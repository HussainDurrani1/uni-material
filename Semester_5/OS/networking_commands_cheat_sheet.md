# 🌐 Ultimate Networking Commands & Troubleshooting Cheat Sheet

This cheat sheet covers essential networking commands, mental models, and troubleshooting workflows for developers and system administrators, mapping out Windows and Linux equivalents.

## 1. 🧠 Networking Mental Model

When debugging a network problem, think in this order:

```
1. Do I have an IP address?
        ↓
2. Can I reach my gateway?
        ↓
3. Can I reach an external IP?
        ↓
4. Does DNS work?
        ↓
5. Is the destination port reachable?
        ↓
6. Is the application actually listening/responding?

```

### Conceptual Structure

```
Your PC
  ├── IP address
  ├── Default Gateway
  ├── DNS Server
  └── Internet
        └── Server
              └── Port 443
                    └── HTTPS application

```

## 2. 🪟 ipconfig — Windows IP Configuration

### Basic Commands

* **`ipconfig`**: Shows basic network information (IPv4 address, subnet mask, default gateway).

* **`ipconfig /all`** *(⭐ Very important)*: Shows detailed information about network adapters, including MAC addresses, DHCP status, lease times, and DNS servers.

#### Key Fields Explained

| Field | Meaning | 
 | ----- | ----- | 
| **Physical Address** | The hardware MAC address of your network interface. | 
| **IPv4 Address** | Your device's address on the local network. | 
| **Subnet Mask** | Defines the range of your local network. | 
| **Default Gateway** | The router IP used to reach outside your local network. | 
| **DHCP Server** | The server/router that assigned your IP address. | 
| **DNS Servers** | Servers responsible for resolving domain names to IPs. | 

### IP Management & DNS Cache

* **`ipconfig /release`**: Releases your current DHCP-assigned IP address. Useful when troubleshooting network assignment problems.

* **`ipconfig /renew`**: Requests a brand new DHCP configuration from the network router. *(Often run sequentially: `ipconfig /release` followed by `ipconfig /renew`)*.

* **`ipconfig /displaydns`**: Shows locally cached DNS records on your machine.

* **`ipconfig /flushdns`** *(⭐ Useful when DNS behaves strangely)*: Clears the local DNS resolver cache.

## 3. 🐧 Linux Equivalent of ipconfig

Modern Linux systems use the `ip` utility instead of legacy tools.

* **`ip addr`** (or short version **`ip a`**): Displays all network interfaces and their assigned IP addresses.

* **`ip link`** (or **`ip l`**): Shows network physical/virtual links and interface statuses.

* **`ip addr show enp3s0`**: Shows details for a single specific interface (interface names vary like `eth0`, `enp3s0`, `wlan0`, `wlp2s0`).

## 4. 🛣️ Routing

Routing dictates how packets are directed through networks.

* **Windows:** `route print` (or `route print -4` / `route print -6`)

* **Linux:** `ip route`

### Reading Route Output

An entry like `default via 192.168.1.1 dev wlp2s0` means:

> *"For any destination address I do not have a specific local route for, forward the packets through the gateway at `192.168.1.1` using interface `wlp2s0`."*

## 5. 🔌 netstat (Windows)

`netstat` displays active network connections, routing tables, and interface statistics.

* **`netstat -n`** *(⭐ Important)*: Displays addresses and port numbers **numerically** rather than resolving hostnames or service names (e.g., shows `142.250.x.x:443` instead of `google.com:https`), making output much faster and clearer.

* **`netstat -a`**: Shows all active connections and listening ports.

* **`netstat -an`**: Combines all connections with numeric formatting.

* **`netstat -o`**: Shows the Process ID (PID) associated with each connection.

* **`netstat -ano`** *(⭐ One of the most useful commands)*: Combines all connections, numeric addresses, and Process IDs.

### Finding What's Using a Specific Port (e.g., Port 3000)

```
netstat -ano | findstr :3000

```

*If you see a line ending with a PID (e.g., `12345`), map it to a program using:*

```
tasklist | findstr 12345

```

* **`netstat -b`**: Attempts to show the exact executable responsible for the connection (requires Administrator privileges).

* **`netstat -p tcp` / `-p udp`**: Filters connections by specific transport protocols.

* **`netstat -s`**: Displays granular protocol statistics (TCP, UDP, IP, ICMP).

* **`netstat -r`**: Displays the IP routing table (similar to `route print`).

## 6. 🐧 Linux ss — Modern Alternative to netstat

On modern Linux environments, `ss` is faster and preferred over `netstat`.

* **`ss`**: Basic active connections.

* **`ss -a`**: All sockets/connections.

* **`ss -n`**: Numeric output (no service name resolution).

* **`ss -t`**: TCP connections only.

* **`ss -ltn`**: Listens (`-l`), TCP (`-t`), numeric (`-n`).

* **`sudo ss -ltnp`**: Shows listening sockets along with process/socket details (`-p`).

* **`ss -tn state established`**: Filters for established TCP connections only.

* **Finding a port on Linux:** `sudo ss -ltnp | grep :3000`

## 7. 🔥 netstat vs ss Quick Reference

| Purpose | Windows Command | Linux Command | 
 | ----- | ----- | ----- | 
| **All Connections** | `netstat -a` | `ss -a` | 
| **Numeric Only** | `netstat -n` | `ss -n` | 
| **All + Numeric** | `netstat -an` | `ss -an` | 
| **Listening TCP** | `netstat -an` | `ss -ltn` | 
| **Process / PID** | `netstat -ano` | `ss -ltnp` | 
| **Routing Table** | `netstat -r` | `ip route` | 

## 8. 📡 ping

Tests whether a remote host can be reached using ICMP echo requests.

* **Windows:** `ping -n 4 google.com` (sends 4 packets)

* **Linux:** `ping -c 4 google.com` (sends 4 packets)

* **Test Local Router:** `ping 192.168.1.1`

* **Test External IP (No DNS):** `ping 8.8.8.8`

> ⚠️ **Important Diagnostic Distinction:** If `ping 8.8.8.8` works but `ping google.com` fails, your internet connection is fine, but **DNS is broken**. Note also that servers can block ICMP ping while still serving traffic over HTTPS.

## 9. 🌎 DNS — nslookup & dig

### nslookup (Cross-Platform)

Resolves domain names to IP addresses or queries custom DNS servers:

* **Basic lookup:** `nslookup google.com`

* **Query a specific public DNS server:** `nslookup google.com 8.8.8.8` (or `1.1.1.1`)

### dig (Linux Power Tool)

* **Basic query:** `dig google.com` (Short version: `dig +short google.com`)

* **Specific record types:** `dig A google.com`, `dig AAAA google.com`, `dig MX google.com`, `dig NS google.com`

* **Use a specific DNS server:** `dig @1.1.1.1 google.com`

## 10. 🛣️ tracert / traceroute

Tracks the path (hops) packets take across the network topology to reach a destination.

* **Windows:** `tracert google.com`

* **Linux:** `traceroute google.com`

> 💡 *Note on asterisks (`*`): Seeing asterisks in a trace does not automatically mean a broken connection; many routers block traceroute ICMP probes for security or performance reasons.*

## 11. 📇 ARP (Address Resolution Protocol)

Maps local IP addresses to physical MAC addresses.

* **Windows:** `arp -a`

* **Linux:** `ip neigh`

## 12. 🔌 Testing Specific Ports (Backend Development)

* **Windows PowerShell:** `Test-NetConnection google.com -Port 443` (or alias `tnc localhost -Port 3000`)

* **Linux / Netcat:** `nc -vz google.com 443` (or `nc -vz localhost 3000`)

## 13. 🌀 curl — HTTP & API Testing

* **GET Request:** `curl https://example.com`

* **Headers Only:** `curl -I https://example.com` (Checks status, content type, redirects, cache headers)

* **Verbose Mode** *(⭐ Great for debugging TLS/HTTP handshake issues)*: `curl -v https://example.com`

* **Follow Redirects:** `curl -L https://example.com`

* **Save Output:** `curl -o page.html https://example.com`

### Testing Local Backend APIs

* **Simple GET:** `curl http://localhost:3000/api/users`

* **POST with JSON Body:**

  ```
  curl -X POST http://localhost:3000/api/users \
    -H "Content-Type: application/json" \
    -d '{"name":"Hussain"}'
  
  ```

## 14. 🧠 IP vs Port & Special Binding Addresses

* **IP Address:** Identifies the **physical/virtual machine** (like a building address).

* **Port:** Identifies the **specific application/service** running on that machine (like an apartment or office number inside the building).

### Common Development Ports

| Port | Common Service / Application | 
 | ----- | ----- | 
| **22** | SSH | 
| **53** | DNS | 
| **80 / 443** | HTTP / HTTPS | 
| **3000** | Node.js / React development servers | 
| **5000** | Python / Flask / General dev servers | 
| **5173** | Vite development server | 
| **5432** | PostgreSQL database | 
| **6379** | Redis database | 
| **27017** | MongoDB database | 

### localhost vs 0.0.0.0

* **`127.0.0.1` / `localhost`:** Loops back to your own machine internally. Accessible only from the local host.

* **`0.0.0.0`:** Binds the application to **all available network interfaces**. Essential when running services inside Docker containers, WSL, VMs, or exposing servers to your local area network (LAN).

## 15. 🔄 Understanding TCP States in netstat / ss

* **`LISTENING`**: The application is actively waiting for incoming client connections on a port.

* **`ESTABLISHED`**: An active data communication session is open between two computers.

* **`TIME_WAIT`**: The connection has closed, but the operating system temporarily holds state information to ensure delayed packets are handled safely.

* **`CLOSE_WAIT`**: The remote peer has closed its end of the socket, but your local application hasn't finished closing its side yet.

## 16. 🚀 80/20 Rule: Most Important Commands to Memorize

### Windows Essentials

```
ipconfig /all
ping google.com
netstat -ano
netstat -ano | findstr :3000
nslookup google.com
route print
Test-NetConnection localhost -Port 3000
curl http://localhost:3000

```

### Linux Essentials

```
ip addr
ip route
ss -ltnp
sudo ss -ltnp | grep :3000
ping -c 4 google.com
dig google.com
ip neigh
curl http://localhost:3000

```