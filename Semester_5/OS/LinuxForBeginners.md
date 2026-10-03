# Linux Tutorial for Beginners

> Learn Linux step by step — from setup to commands, permissions, automation, and basic web hosting.

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Bash](https://img.shields.io/badge/Bash-121011?style=for-the-badge&logo=gnubash&logoColor=white)
![WSL](https://img.shields.io/badge/WSL-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![VirtualBox](https://img.shields.io/badge/VirtualBox-183A61?style=for-the-badge&logo=virtualbox&logoColor=white)
![Nginx](https://img.shields.io/badge/Nginx-009639?style=for-the-badge&logo=nginx&logoColor=white)
![Markdown](https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white)
![Beginner Friendly](https://img.shields.io/badge/Beginner%20Friendly-2ea44f?style=for-the-badge)

## Overview

This repository is a practical Linux learning guide for beginners. It follows a clear sequence: understand Linux, set up a learning environment, learn daily commands, manage users and permissions, automate with cron, and deploy with Nginx.

## Who this is for

- Students starting Linux for development or DevOps
- Windows/macOS users who want a Linux practice setup
- Beginners preparing for cloud, backend, or sysadmin learning

## Recommended Learning Path

Follow this exact sequence:

1. [What is Linux?](#what-is-linux)
2. [History of Linux](#history-of-linux)
3. [Getting an online Linux Server](#getting-an-online-linux-server)
4. [Installing Linux through VirtualBox on Windows](#installing-linux-through-virtualbox-on-windows)
5. [Installing Linux on Windows using WSL](#installing-linux-on-windows-using-wsl)
6. [Installing Linux through VirtualBox on Mac](#installing-linux-through-virtualbox-on-mac)
7. [Basic Linux Commands](#basic-linux-commands)
8. [Creating Users](#creating-users)
9. [Package Management](#package-management)
10. [Groups & Permissions](#groups--permissions)
11. [Processes & Services](#processes--services)
12. [Environment Variables, PATH and Bashrc](#environment-variables-path-and-bashrc)
13. [Archives and Compression](#archives-and-compression)
14. [Cronjobs](#cronjobs)
15. [Understanding Linux Filesystem](#understanding-linux-filesystem)
16. [Understanding Nginx](#understanding-nginx)
17. [Using FileZilla to Transfer Files](#using-filezilla-to-transfer-files)
18. [Conclusion](#conclusion)

---

## What is Linux?

**Linux is a free and open-source operating system kernel** that manages a computer's hardware and allows software to interact with it.

The kernel is the core component of an operating system. It manages essential resources such as the CPU, memory, storage, and running processes.

### How Linux Works

```text
User → Applications / Shell → Linux Kernel → Hardware
```

| Component | Purpose |
|-----------|---------|
| Hardware | Physical components such as CPU, RAM, and storage. |
| Kernel | Manages hardware resources and communication with software. |
| Shell | Allows users to interact with the operating system through commands. |
| Applications | Programs that perform tasks for users. |

### What Does the Linux Kernel Manage?

| Resource | Responsibility |
|----------|----------------|
| CPU | Schedules processes and allocates processing time. |
| Memory | Manages RAM allocation between programs. |
| Storage | Supports filesystem operations and access to storage devices. |
| Processes | Creates, schedules, and terminates running programs. |
| Permissions | Enforces access controls for users and processes. |

### Linux Kernel vs. Linux Distribution

Technically, **Linux refers to the kernel**, not the complete operating system.

A **Linux distribution (distro)** combines the Linux kernel with system utilities, a package manager, and other software to provide a usable operating system.

Popular Linux distributions include Ubuntu, Debian, Fedora, Arch Linux, and Kali Linux.

> **Example:** Ubuntu is a complete operating system built around the Linux kernel.

### Check Your Linux System

Run these commands in your Linux terminal:

```bash
uname -s              # Display the kernel name
uname -r              # Display the kernel release
uname -a              # Display detailed system information
cat /etc/os-release   # Identify your Linux distribution
```

### Why Learn Linux?

Linux is widely used in servers, cloud computing, cybersecurity, DevOps, software development, and Android devices. Learning Linux helps you understand how modern computing infrastructure works and how to manage systems through the command line.

---

## History of Linux

Linux was inspired by **Unix**, combined with tools from the **GNU Project**, and developed into one of the most widely used foundations for operating systems today.

### Linux Evolution

```text
Unix (1969) → GNU (1983) → Linux Kernel (1991) → Linux Distributions → Android & Cloud Computing
```

| Year | Milestone | Significance |
|------|-----------|--------------|
| **1969** | Unix developed at Bell Labs by Ken Thompson and Dennis Ritchie. | Introduced multi-user, multitasking, and hierarchical filesystem concepts. |
| **1983** | Richard Stallman announced the GNU Project. | Developed free software tools such as GCC, Bash, and core utilities. |
| **1991** | Linus Torvalds created the Linux kernel at the University of Helsinki. | Started Linux as a personal project that grew through community contributions. |
| **1993–1994** | Debian and Red Hat emerged. | Helped make Linux accessible through packaged operating systems called distributions. |
| **2004** | Ubuntu was released. | Introduced a Debian-based Linux distribution focused on usability. |
| **2005** | Google acquired Android Inc. | Helped bring the Linux kernel into mainstream mobile computing. |

### How GNU and Linux Work Together

The Linux kernel manages hardware and system resources, while GNU provides many essential tools needed to operate the system.

```text
Linux Kernel + GNU Tools + System Software
                  ↓
        Linux Distribution
                  ↓
       Ubuntu, Debian, Fedora
```

> **Note:** Linux is Unix-like, not Unix itself. It follows many Unix design principles but was independently developed.

### Why Linux Became Popular

- **Open Source:** Users can study, modify, and distribute the Linux kernel under its license.
- **Cost-Effective:** Most Linux distributions are available without operating system license fees.
- **Customizable:** Developers can modify and configure systems according to their needs.
- **Widely Adopted:** Linux powers servers, cloud infrastructure, supercomputers, Android devices, and embedded systems.

**Today, Linux is a fundamental technology for software development, cloud computing, DevOps, cybersecurity, and system administration.**

---


## Getting an Online Linux Server

### What is a VPS?

A **VPS (Virtual Private Server)** is a virtual machine hosted in the cloud that you can access remotely through the internet.

It allows you to practice Linux, deploy websites, run applications, and automate tasks without installing Linux on your personal computer.

### Step 1: Choose a VPS Provider

For this tutorial, we will use [Hostinger](https://www.hostinger.com/) as an example.

1. Visit Hostinger and select a suitable VPS hosting plan.
2. Choose **Ubuntu LTS (Long Term Support)** as your operating system.
3. Complete the purchase and configure your VPS.
4. Set a strong root password and store it securely.
5. Wait for the VPS installation to complete.

> **Note:** You can use any VPS provider that supports Linux. A small VPS is sufficient for practicing basic Linux commands.

### Step 2: Connect to Your VPS Using SSH

**SSH (Secure Shell)** allows you to securely access and manage a remote Linux server through your terminal.

Open PowerShell, Windows Terminal, or your macOS/Linux terminal and run:

```bash
ssh root@203.0.113.10
```

Replace \`203.0.113.10\` with your VPS's actual public IP address.

Other SSH connection methods:

```bash
# Connect using a specific port
ssh -p 22 root@203.0.113.10

# Connect using an SSH private key
ssh -i ~/.ssh/id_rsa root@203.0.113.10
```

On your first connection, SSH may ask you to verify the server's identity. Confirm that its fingerprint matches the one provided by your hosting provider before accepting it.

Enter your root password when prompted. Your password will not appear on the screen while typing.

> **Security Tip:** SSH key authentication is recommended for long-term server access. After initial setup, use a regular user with sudo privileges instead of working as root for everyday tasks.

### Step 3: Verify Your Linux Server

Once connected, run the following commands:

```bash
hostname             # Display the server's hostname
uname -a             # Display kernel and system information
cat /etc/os-release  # Identify your Linux distribution
whoami               # Display the currently logged-in user
```

If the commands return your server information, you have successfully connected to your Linux VPS.

> **Remember:** Commands executed through SSH run on your remote Linux server, not your personal computer. Your VPS continues running even after you close your terminal.

### Troubleshooting

If you cannot connect to your VPS, open your hosting provider's dashboard and verify the server status, IP address, SSH port, and login credentials.

Most VPS providers also offer a browser-based terminal for accessing your server when SSH is unavailable.

---

## Installing Linux Through VirtualBox on Windows

### What is Virtualization?

**Virtualization** allows you to run another operating system inside your existing computer without replacing Windows.

Using VirtualBox, you can create a **Virtual Machine (VM)** to run Ubuntu Linux independently.

- **Host OS:** Your original operating system (Windows).
- **Guest OS:** The operating system running inside VirtualBox (Ubuntu Linux).

### Step 1: Install VirtualBox

1. Visit the official [VirtualBox Downloads](https://www.virtualbox.org/wiki/Downloads) page.
2. Download VirtualBox for **Windows hosts**.
3. Run the installer and follow the installation instructions.
4. Complete the installation and launch VirtualBox.

### Step 2: Download Ubuntu

1. Visit the official [Ubuntu Desktop Download](https://ubuntu.com/download/desktop) page.
2. Select an Ubuntu **LTS (Long Term Support)** release.
3. Download the AMD64 (Intel/AMD 64-bit) ISO file.

> **Note:** The ISO file contains the Ubuntu operating system required to install Linux inside your virtual machine.

### Step 3: Create a Virtual Machine

1. Open VirtualBox and click **New**.
2. Enter a name for your VM, such as \`Ubuntu\`.
3. Select the downloaded Ubuntu ISO file.
4. Set your username and password.
5. Allocate the following resources according to your computer's available hardware:

| Resource | Recommended Allocation |
|----------|------------------------|
| RAM | 4 GB (or 50% of your Memory) |
| CPU | 2 Cores (or 50% of your CPU) |
| Storage | 35 GB minimum; allocate more if available |
| Operating System | Ubuntu LTS (64-bit) |

6. Complete the VM configuration and click **Finish**.
7. Start your virtual machine and complete the Ubuntu installation.

> **Important:** Do not allocate all your computer's RAM or CPU cores to the VM. Windows needs enough resources to continue running smoothly.

### Step 4: Open the Linux Terminal

Once Ubuntu starts, log in with your username and password.

Open the terminal using:

```text
Ctrl + Alt + T
```

Alternatively, search for **Terminal** in Ubuntu's Activities menu.

### Step 5: Verify Your Linux Installation

Run these commands inside the Ubuntu terminal:

```bash
uname -a             # Display kernel and system information
cat /etc/os-release  # Identify your Linux distribution
ls                   # List files and directories
ls -l                # Display detailed file information
ls -la               # Include hidden files and directories
```

> **Remember:** Windows Terminal runs commands on your Windows host, while the Ubuntu terminal runs commands inside your Linux virtual machine. Use the Ubuntu terminal throughout this handbook.

---

## Installing Linux on Windows Using WSL

### What is WSL?

**WSL (Windows Subsystem for Linux)** allows you to run Linux directly inside Windows without installing a separate operating system or creating a virtual machine using VirtualBox.

WSL is ideal for beginners who want to practice Linux commands, Bash scripting, and development through the terminal.

### Step 1: Install WSL

1. Open **Windows PowerShell as Administrator**.
2. Run the following command:

```powershell
wsl --install
```

This installs WSL along with the default Linux distribution, typically Ubuntu.

To view available Linux distributions:

```powershell
wsl --list --online
```

To install Ubuntu explicitly:

```powershell
wsl --install -d Ubuntu
```

> **Note:** You do not need to run both installation commands. Use \`wsl --install -d Ubuntu\` when you specifically want Ubuntu. Restart Windows if prompted.

### Step 2: Configure Ubuntu

1. Open **Ubuntu** from the Windows Start menu.
2. Wait for the initial installation to complete.
3. Create your Linux username and password.
4. Once configured, the Ubuntu terminal will be ready to use.

> **Important:** Your Linux username and password are separate from your Windows login credentials.

### Step 3: Verify Your Linux Installation

Run these commands inside the Ubuntu terminal:

```bash
uname -a             # Display kernel and system information
cat /etc/os-release  # Identify your Linux distribution
ls -la               # List files, including hidden files
```

### Useful WSL Commands

Run these commands in Windows PowerShell:

| Command | Purpose |
|---------|---------|
| `wsl --list --online` | List available Linux distributions. |
| `wsl --list --verbose` | Display installed distributions and their WSL versions. |
| `wsl -d Ubuntu` | Launch Ubuntu. |
| `wsl --shutdown` | Shut down all running WSL distributions. |

### Access Windows Files from Linux

Windows drives are accessible inside WSL through the `mnt` directory.

For example, to access your Windows C drive:

```bash
cd /mnt/c
ls
```

> **Remember:** WSL runs Linux locally on your Windows computer. It is not a cloud VPS or a publicly accessible Linux server by default.

---

## Installing Linux Through VirtualBox on Mac

### What is VirtualBox on Mac?

**VirtualBox** allows you to run Ubuntu Linux inside macOS as a virtual machine without replacing your existing operating system.

- **Host OS:** macOS (your original operating system).
- **Guest OS:** Ubuntu Linux (running inside VirtualBox).

### Step 1: Install VirtualBox

1. Visit the official [VirtualBox Downloads](https://www.virtualbox.org/wiki/Downloads) page.
2. Download VirtualBox for your supported macOS system.
3. Follow the installation instructions and launch VirtualBox.

### Step 2: Download Ubuntu

Visit the official [Ubuntu Downloads](https://ubuntu.com/download/desktop) page and download an Ubuntu LTS ISO compatible with your Mac's processor.

| Mac Processor | Ubuntu Architecture |
|---------------|---------------------|
| Intel Mac | AMD64 (x86-64) |
| Apple Silicon (M1/M2/M3/M4, etc.) | ARM64 (aarch64) |

> **Important:** Ensure that your VirtualBox version supports your Mac's processor and the selected Ubuntu guest architecture.

### Step 3: Create an Ubuntu Virtual Machine

1. Open VirtualBox and click **New**.
2. Name your virtual machine, such as `Ubuntu`.
3. Select the downloaded Ubuntu ISO file.
4. Configure your username and password.
5. Allocate RAM, CPU cores, and storage according to your Mac's available resources.
6. Click **Finish** and start the virtual machine.
7. Complete the Ubuntu installation and log in.

> **Note:** Leave sufficient RAM and CPU resources for macOS to run smoothly.

### Step 4: Open the Ubuntu Terminal

Once Ubuntu starts, open the terminal using:

```text
Ctrl + Alt + T
```

Alternatively, open **Activities → Terminal** inside Ubuntu.

### Step 5: Verify Your Linux Installation

Run these commands inside the Ubuntu terminal:

```bash
uname -m             # Display CPU architecture
uname -a             # Display kernel and system information
cat /etc/os-release  # Identify your Linux distribution
ls -la               # List files, including hidden files
```

The `uname -m` command typically returns:

- `x86_64` for Intel/AMD 64-bit Linux.
- `aarch64` for ARM64 Linux.

> **Remember:** The macOS Terminal runs commands on your Mac, while the Ubuntu terminal runs commands inside your Linux virtual machine. Use the Ubuntu terminal throughout this handbook.

---

## Basic Linux Commands

Linux commands allow you to navigate directories, create and manage files, edit content, and interact with your operating system through the terminal.

### 1. Navigation Commands

#### `pwd` — Print Working Directory

Displays the full path of your current directory.

**Syntax:**
```bash
pwd
```

**Example Output:**
```text
/home/zeeshan
```

#### `cd` — Change Directory

Allows you to navigate between directories in the Linux filesystem.

| Command | Purpose | Example |
|---------|---------|---------|
| `cd <directory>` | Move into a specific directory. | `cd Documents` |
| `cd ..` or `cd ../` | Move one directory up. | `cd ..` |
| `cd ../..` | Move two directories up. | `cd ../..` |
| `cd ../<directory>` | Move into another directory inside the parent directory. | `cd ../Downloads` |
| `cd ~` | Navigate to your home directory. | `cd ~` |
| `cd /` | Navigate to the filesystem root. | `cd /` |
| `cd .` | Stay in the current directory. | `cd .` |
| `cd` | Return to your home directory. | `cd` |

**Understanding Directory Shortcuts**

```text
/       → Filesystem root
~       → Current user's home directory
.       → Current directory
..      → Parent directory
../..   → Two directories up
```

For example, suppose your current directory is:

```text
/home/zeeshan/projects
```

Running:

```bash
cd ..
```

Takes you to:

```text
/home/zeeshan
```

Running it again takes you to:

```text
/home
```

> [!NOTE]
> `/` represents the filesystem root, while `~` represents the current user's home directory. They are not the same location.

#### `ls` — List Files and Directories

Displays the files and directories available inside a directory.

**Syntax:**
```bash
ls
```

**Useful Examples:**

| Command | Purpose |
|---------|---------|
| `ls` | List files and directories in the current directory. |
| `ls -l` | Display detailed file information. |
| `ls -la` | Include hidden files and directories. |
| `ls .` | List the contents of the current directory. |
| `ls ~` | List the contents of your home directory. |

> **Tip:** Press `Tab` while typing a file or directory name to autocomplete it when possible.

---

### 2. Creating and Managing Files

#### `mkdir` — Make Directory

Creates a new directory in the Linux filesystem.

**Syntax:**
```bash
mkdir <directory-name>
```

**Example:**
```bash
mkdir projects
```

To create multiple nested directories:

```bash
mkdir -p folder1/folder2/folder3
```

The `-p` option creates missing parent directories automatically.

#### `touch` — Create an Empty File

Creates a new empty file if it does not already exist.

**Syntax:**
```bash
touch <filename>
```

**Example:**
```bash
touch notes.txt
```

> **Note:** If the file already exists, `touch` updates its timestamps without deleting its contents.

#### `cp` — Copy Files

Copies a file from one location to another.

**Syntax:**
```bash
cp <source> <destination>
```

**Example:**
```bash
cp notes.txt backup.txt
```

This creates a copy of `notes.txt` named `backup.txt`.

> [!IMPORTANT]
> Copying to an existing destination file may overwrite its contents.

---

### 3. Editing Files with Vim

#### `vim` — Text Editor

Vim is a terminal-based text editor used to create and modify files directly inside Linux.

**Syntax:**
```bash
vim <filename>
```

**Example:**
```bash
vim notes.txt
```

**If Vim is not installed:**

```bash
sudo apt update
sudo apt install vim
```

After installation, open your file again:

```bash
vim notes.txt
```

**How to Edit a File Using Vim**

1. Press `i` to enter Insert Mode.
2. Type or modify your content.
3. Press `Esc` to return to Normal Mode.
4. Type `:wq` and press `Enter` to save and exit.

| Vim Command | Purpose |
|-------------|---------|
| `i` | Enter Insert Mode. |
| `Esc` | Return to Normal Mode. |
| `:w` | Save the file. |
| `:q` | Exit if there are no unsaved changes. |
| `:wq` | Save and exit. |
| `:q!` | Exit without saving changes. |

---

### 4. Reading Files with `cat`

#### `cat` — Concatenate

The `cat` command is commonly used to display the contents of a file directly in the terminal.

**Syntax:**
```bash
cat <filename>
```

**Example:**
```bash
cat hello.txt
```

**Example Output:**
```text
Hello Linux!
Welcome to my first Linux file.
```

**Useful cat Commands**

| Command | Purpose |
|---------|---------|
| `cat file.txt` | Display the contents of a file. |
| `cat file1.txt file2.txt` | Display multiple files consecutively. |
| `cat -n file.txt` | Display file contents with line numbers. |
| `cat > file.txt` | Create or overwrite a file using terminal input. |
| `cat >> file.txt` | Append content to the end of a file. |

**Example: Display File Content with Line Numbers**

```bash
cat -n hello.txt
```

**Output:**
```text
     1  Hello Linux!
     2  Welcome to my first Linux file.
```

**Example: Create a File Using cat**

```bash
cat > hello.txt
```

Enter your content:

```text
Hello Linux!
This is my first file.
```

Press `Ctrl + D` to finish writing and return to the terminal.

**Example: Append Content to an Existing File**

```bash
cat >> hello.txt
```

Type additional content and press `Ctrl + D` when finished.

> [!WARNING]
> `cat > file.txt` overwrites existing content, while `cat >> file.txt` appends content without removing what is already there.

---

### 5. Reading Large Files with `less`

#### `less` — Interactive File Viewer

The `less` command allows you to read, scroll through, and search large files without printing everything into the terminal at once.

**Syntax:**
```bash
less <filename>
```

**Example:**
```bash
less hello.txt
```

**Navigation Inside less**

| Key | Purpose |
|-----|---------|
| ↑ / ↓ | Move one line up or down. |
| `Space` | Move one page down. |
| `b` | Move one page up. |
| `Enter` | Move one line down. |
| `g` | Go to the beginning of the file. |
| `G` | Go to the end of the file. |
| `/word` | Search for a specific word. |
| `n` | Jump to the next search result. |
| `q` | Quit and return to the terminal. |

**Example: Searching Inside a File**

Open a file:

```bash
less hello.txt
```

Type `/Linux` and press `Enter` to search for the word `Linux`.

Press `n` to navigate to the next matching result.

**cat vs. less**

| Command | Best Used For |
|---------|---------------|
| `cat` | Quickly displaying small files. |
| `less` | Reading and searching large files interactively. |

---

### 6. Terminal Utility Commands

#### `clear` — Clear Terminal Screen

Clears the visible terminal screen.

**Syntax & Example:**
```bash
clear
```

#### `history` — Command History

Displays previously executed commands in your terminal session's available history.

**Syntax & Example:**
```bash
history
```

> **Tip:** Use the ↑ and ↓ arrow keys to navigate through previous commands instead of typing long commands repeatedly.

---


## Creating Users

Linux is a **multi-user operating system**, meaning multiple users can have separate accounts, home directories, files, and permissions.

### 1. Check the Current User

The `whoami` command displays the username of the currently logged-in user.

**Syntax & Example:**

```bash
whoami
```

**Example Output:**

```text
zeeshan
```

To view additional information about your account:

```bash
id
```

This displays your **User ID (UID)**, **Group ID (GID)**, and group memberships.

### 2. Create a New User

The `adduser` command creates a new user account in Ubuntu.

**Syntax:**

```bash
sudo adduser <username>
```

**Example:**

```bash
sudo adduser john
```

Linux will ask you to set a password and optionally provide additional user information.

A home directory is also created:

```text
/home/john
```

> **Note:** `sudo` allows an authorized user to execute commands with elevated privileges, usually as root.

### 3. Switch Between Users

The `su` command allows you to switch to another user account.

**Syntax:**

```bash
su - <username>
```

**Example:**

```bash
su - john
```

The `-` starts a login shell, loading John's environment and taking you to his home directory.

Verify the current user and directory:

```bash
whoami
pwd
```

**Expected Output:**

```text
john
/home/john
```

To return to your previous shell:

```bash
exit
```

### 4. View User Information

Use `id` to display information about a specific user.

**Syntax:**

```bash
id <username>
```

**Example:**

```bash
id john
```

**Example Output:**

```text
uid=1001(john) gid=1001(john) groups=1001(john)
```

| Field | Meaning |
|-------|---------|
| UID | User ID that uniquely identifies the user. |
| GID | Primary Group ID associated with the user. |
| groups | Groups the user belongs to. |

### 5. Give a User Sudo Access

By default, a newly created standard user does not necessarily have administrative privileges.

On Ubuntu, you can add an authorized user to the `sudo` group to grant administrative access.

**Syntax:**

```bash
sudo usermod -aG sudo <username>
```

**Example:**

```bash
sudo usermod -aG sudo john
```

John can then execute administrative commands using `sudo`, for example:

```bash
sudo apt update
```

> [!IMPORTANT]
> Adding a user to the `sudo` group grants significant administrative privileges. The user may need to log out and log back in before the new group membership takes effect.

#### Understanding `usermod -aG`

The command:

```bash
sudo usermod -aG sudo john
```

Can be broken down as follows:

| Component | Purpose |
|-----------|---------|
| `sudo` | Execute with elevated privileges. |
| `usermod` | Modify an existing user account. |
| `-a` | Append to existing supplementary groups. |
| `-G` | Specify supplementary groups. |
| `sudo` | Group to which the user will be added. |
| `john` | Username to modify. |

**Why is `-aG` important?**

Suppose John belongs to these groups:

```text
john developers docker
```

Using:

```bash
sudo usermod -G sudo john
```

Can replace his existing supplementary group memberships with `sudo`.

Instead, use:

```bash
sudo usermod -aG sudo john
```

This adds John to the `sudo` group while preserving his existing supplementary groups.

### 6. Change a User's Password

The `passwd` command allows an administrator to set or change another user's password.

**Syntax:**

```bash
sudo passwd <username>
```

**Example:**

```bash
sudo passwd john
```

Enter and confirm the new password when prompted.

### 7. Check User Groups

The `groups` command displays the groups associated with a user.

**Syntax:**

```bash
groups <username>
```

**Example:**

```bash
groups john
```

**Example Output:**

```text
john : john sudo
```

This indicates that John belongs to the `john` and `sudo` groups.

### 8. Delete a User

The `userdel` command removes an existing user account.

**Syntax:**

```bash
sudo userdel <username>
```

**Example:**

```bash
sudo userdel john
```

To remove the user along with their home directory and mail spool:

```bash
sudo userdel -r john
```

> [!CAUTION]
> The `-r` option deletes the user's home directory and its contents. Back up important data before using this command. Files owned by the user outside their home directory may remain on the system.

---

## Package Management

**Package Management** is the process of installing, updating, removing, and managing software on a Linux system.

Ubuntu and Debian use **APT (Advanced Package Tool)** to manage software packages through configured repositories.

### 1. Update Package Information

The `apt update` command refreshes the list of available packages and their versions from configured software repositories.

**Syntax & Example:**

```bash
sudo apt update
```

> **Note:** `apt update` only refreshes package information. It does not upgrade your installed software.

### 2. Upgrade Installed Packages

The `apt upgrade` command downloads and installs available updates for packages already installed on your system.

**Syntax & Example:**

```bash
sudo apt upgrade
```

**Recommended Workflow:**

```bash
sudo apt update
sudo apt upgrade
```

You can also combine both commands:

```bash
sudo apt update && sudo apt upgrade
```

The `&&` operator executes the second command only if the first command succeeds.

**Understanding update vs. upgrade:**

| Command | Purpose |
|---------|---------|
| `sudo apt update` | Check for available package updates. |
| `sudo apt upgrade` | Download and install available updates. |

> [!IMPORTANT]
> Package upgrades can introduce compatibility issues. Back up important data before major upgrades, especially on production servers.

### 3. Upgrade vs. Full Upgrade

APT provides two methods for upgrading installed packages.

| Command | Purpose |
|---------|---------|
| `sudo apt upgrade` | Upgrades packages without removing installed packages. |
| `sudo apt full-upgrade` | Allows larger dependency changes, including removing packages when necessary. |

**Examples:**

```bash
sudo apt upgrade
sudo apt full-upgrade
```

> [!WARNING]
> Review the proposed changes before confirming `full-upgrade`, as it may remove existing packages.

### 4. Search for a Package

The `apt search` command searches available software repositories for packages matching a keyword.

**Syntax:**

```bash
apt search <package-name>
```

**Example:**

```bash
apt search nginx
```

### 5. View Package Information

The `apt show` command displays details about a package, including its version, description, dependencies, and download size.

**Syntax:**

```bash
apt show <package-name>
```

**Example:**

```bash
apt show nginx
```

### 6. Install Packages

The `apt install` command downloads and installs software from configured repositories.

**Syntax:**

```bash
sudo apt install <package-name>
```

**Example:**

```bash
sudo apt install nginx
```

You can also install multiple packages using a single command:

```bash
sudo apt install git curl wget
```

This installs Git, cURL, and Wget together.

### 7. Remove or Purge Packages

APT provides two common methods for uninstalling software.

| Command | Purpose |
|---------|---------|
| `sudo apt remove nginx` | Remove Nginx while generally preserving its configuration files. |
| `sudo apt purge nginx` | Remove Nginx and its package-managed configuration files. |

**Examples:**

```bash
sudo apt remove nginx
sudo apt purge nginx
```

> **Remember:** `remove` uninstalls the software, while `purge` also removes its package-managed configuration files.

### 8. View Installed Packages

The `apt list --installed` command displays packages currently installed on your system.

**Syntax & Example:**

```bash
apt list --installed
```

To search for a specific package in the installed list:

```bash
apt list --installed | grep nginx
```

The `|` operator, called a **pipe**, sends the output of one command to another. Here, `grep` filters the list for packages containing `nginx`.

### 9. Check Package Versions

The `apt policy` command displays installed and available package versions along with their repository information.

**Syntax:**

```bash
apt policy <package-name>
```

**Example:**

```bash
apt policy nginx
```

This is useful when troubleshooting package versions and update availability.

### 10. Clean Unused Packages

APT provides commands to remove unnecessary dependencies and downloaded package files.

| Command | Purpose |
|---------|---------|
| `sudo apt autoremove` | Remove automatically installed dependencies that are no longer needed. |
| `sudo apt clean` | Clear downloaded package files from the local APT cache. |

**Examples:**

```bash
sudo apt autoremove
sudo apt clean
```

> **Note:** Review the package list before confirming `autoremove` to avoid removing anything you still need.

### 11. Understanding Software Repositories

A **repository** is a configured source from which APT retrieves software packages and updates.

When you run:

```bash
sudo apt install nginx
```

APT follows this general process:

```text
Software Repository
        ↓
APT Package Information
        ↓
Download Package
        ↓
Install Package
```

Ubuntu stores repository configuration in locations such as:

```text
/etc/apt/sources.list
/etc/apt/sources.list.d/
```

### 12. APT vs. APT-GET

Ubuntu and Debian provide both `apt` and `apt-get` for package management.

| Tool | Purpose |
|------|---------|
| `apt` | User-friendly command-line interface for everyday package management. |
| `apt-get` | Established package-management interface commonly used in scripts and automation. |

Both remain supported. This handbook uses `apt` for beginner-friendly examples.

---

## Groups & Permissions

Linux uses **users, groups, ownership, and permissions** to control who can access files and directories.

For example:

```text
/home/harry/private.txt
/home/project/app.py
/etc/nginx/nginx.conf
```

Linux needs to decide who can **read, modify, or execute** each resource.

---

### 1. Users

Every person or process in Linux operates as a user.

Check the current user:

```bash
whoami
```

**Example Output:**

```text
harry
```

View a user's UID, GID, and groups:

```bash
id harry
```

**Example Output:**

```text
uid=1000(harry) gid=1000(harry) groups=1000(harry),27(sudo)
```

- **UID** → User ID
- **GID** → Primary Group ID
- **groups** → Groups the user belongs to

---

### 2. Groups

Groups allow multiple users to share the same permissions.

```text
developers
├── Alice
├── Bob
└── Charlie
```

Check a user's groups:

```bash
groups harry
id harry
```

Create a group:

```bash
sudo groupadd developers
```

Add a user to the group:

```bash
sudo usermod -aG developers harry
```

Here:

- `-a` → Append the user without removing existing group memberships.
- `-G` → Specify supplementary groups.

> [!NOTE]
> After changing group membership, the user may need to log out and log back in before the change appears in the current session.

---

### 3. Understanding File Permissions

View file permissions:

```bash
ls -l
```

Example:

```text
-rwxr-xr-- 1 harry developers 1234 Aug 24 app.sh
```

The permission section:

```text
-rwxr-xr--
││  │  │
││  │  └── Others
││  └───── Group
│└──────── Owner
└───────── File type
```

Linux permissions are divided into three categories:

| Category | Meaning |
|----------|---------|
| Owner | User who owns the file |
| Group | Group associated with the file |
| Others | Everyone else |

### Permission Types

| Permission | Symbol | Meaning |
|------------|--------|---------|
| Read | `r` | Read file contents |
| Write | `w` | Modify the file |
| Execute | `x` | Execute the file |

Example:

```text
rwx | r-x | r--
Owner | Group | Others
```

This means:

- **Owner:** read, write, execute
- **Group:** read and execute
- **Others:** read only

---

### 4. File Types

The first character in `ls -l` output identifies the file type.

```text
-  → Regular file
d  → Directory
l  → Symbolic link
```

Example:

```text
-rwxr-xr--
```

The `-` means it is a regular file.

---

### 5. Directory Permissions

For directories:

| Permission | Meaning |
|------------|---------|
| `r` | List directory contents |
| `w` | Create, delete, or rename entries |
| `x` | Enter or traverse the directory |

Create a test directory:

```bash
mkdir test
```

View its permissions:

```bash
ls -ld test
```

---

### 6. Changing Permissions with `chmod`

Check a file's permissions:

```bash
ls -l script.sh
```

You might see:

```text
-rw-r--r-- script.sh
```

Make it executable:

```bash
chmod +x script.sh
```

Then run it:

```bash
./script.sh
```

### Symbolic Permission Changes

```bash
chmod u+x script.sh
chmod g+w file.txt
chmod o-r file.txt
chmod g=rx file.txt
```

| Symbol | Meaning |
|--------|---------|
| `u` | User / owner |
| `g` | Group |
| `o` | Others |
| `a` | All users |
| `+` | Add permission |
| `-` | Remove permission |
| `=` | Set exact permissions |

Examples:

```text
u+x   → Add execute permission to owner
g+w   → Add write permission to group
o-r   → Remove read permission from others
g=rx  → Set group permissions to read + execute only
```

---

### 7. Numeric Permissions

Linux permissions can also be represented using numbers.

```text
r = 4
w = 2
x = 1
```

Common combinations:

| Permission | Value |
|------------|------:|
| `rwx` | 7 |
| `rw-` | 6 |
| `r-x` | 5 |
| `r--` | 4 |
| `-wx` | 3 |
| `-w-` | 2 |
| `--x` | 1 |
| `---` | 0 |

The three digits represent:

```text
Owner | Group | Others
```

Generic syntax:

```bash
chmod 755 file
```

#### `755`

```bash
chmod 755 script.sh
```

```text
7 = rwx → Owner: read + write + execute
5 = r-x → Group: read + execute
5 = r-x → Others: read + execute
```

#### `644`

```bash
chmod 644 file.txt
```

```text
6 | 4 | 4
rw- | r-- | r--
```

- Owner → read + write
- Group → read
- Others → read

#### `700`

```bash
chmod 700 private.txt
```

```text
rwx | --- | ---
```

Only the owner has access.

### Why `777` Can Be Dangerous

```bash
chmod 777 file
```

Means:

```text
rwx | rwx | rwx
```

Everyone can read, modify, and execute the file.

> [!WARNING]
> Do not solve permission problems by blindly using `chmod 777`. Give users only the permissions they actually need.

---

### 8. Changing Ownership

Suppose:

```text
-rw-r--r-- 1 harry developers app.py
```

Change the owner to Alice:

```bash
sudo chown alice app.py
```

Change both owner and group:

```bash
sudo chown alice:developers app.py
```

Generic syntax:

```bash
chown OWNER:GROUP FILE
```

Change only the group:

```bash
sudo chgrp developers app.py
```

```text
chown → Change ownership
chgrp → Change group
chmod → Change permissions
```

---

### 9. Recursive Ownership Changes

Suppose your project contains:

```text
project/
├── app.py
├── config.txt
└── logs/
    └── app.log
```

Change ownership of only the `project` directory:

```bash
sudo chown lovish:developers project
```

Change ownership recursively for the directory and everything inside it:

```bash
sudo chown -R lovish:developers project
```

> [!CAUTION]
> `-R` means recursive. Verify the path carefully because it can change ownership of a large number of files.

---

### 10. Reading an `ls -l` Entry

Example:

```text
drwxr-x--- 3 harry harry 4096 Aug 23 10:21 harry
```

| Part | Meaning |
|------|---------|
| `d` | Directory |
| `rwxr-x---` | Permissions |
| `3` | Hard-link count |
| First `harry` | Owner |
| Second `harry` | Group |
| `4096` | Directory size reported by `ls` |
| `Aug 23 10:21` | Last modification time |
| Final `harry` | Directory name |

To view the total disk usage of the directory:

```bash
du -sh harry
```

---

### 11. How Linux Chooses Permissions

Suppose:

```text
-rwxr----- 1 harry developers app.py
```

Permissions are:

```text
Owner  → rwx
Group  → r--
Others → ---
```

Linux checks permissions in this order:

```text
Is the user the owner?
        ↓
      YES → Use OWNER permissions
        ↓ NO
Is the user in the file's group?
        ↓
      YES → Use GROUP permissions
        ↓ NO
Use OTHERS permissions
```

Linux does not combine these permission sets.

---

### 12. Worked Example

Create two users:

```bash
sudo adduser alice
sudo adduser bob
```

Create a developers group:

```bash
sudo groupadd developers
```

Add both users:

```bash
sudo usermod -aG developers alice
sudo usermod -aG developers bob
```

Create a project file:

```bash
sudo touch /opt/project.txt
```

Set Alice as the owner and `developers` as the group:

```bash
sudo chown alice:developers /opt/project.txt
```

Check ownership and permissions:

```bash
ls -l /opt/project.txt
```

Set permissions:

```bash
sudo chmod 640 /opt/project.txt
```

`640` means:

```text
6 → Owner:  read + write
4 → Group:  read
0 → Others: no permissions
```

Therefore:

```text
Owner  → Alice
Group  → developers
Others → Everyone else
```

---

## Processes & Services

Linux uses **processes** to run programs and **services** to manage long-running background applications.

```text
Program  → Code stored on disk
Process  → A running instance of a program
Service  → A background application managed by systemd
```

For example, running:

```bash
python app.py
```

starts a Python process. Even a short command such as:

```bash
ls
```

runs as a process and exits when its work is complete.

---

### 1. Process IDs (PID)

Every running process has a unique **PID (Process ID)**.

Use `ps` to view processes associated with your current terminal:

```bash
ps
```

**Example Output:**

```text
PID    TTY      TIME     CMD
1234   pts/0    00:00:00 bash
5678   pts/0    00:00:00 ps
```

Here, `5678` is the PID of the `ps` command itself.

### 2. View All Processes

For a more detailed process list:

```bash
ps aux
```

Important columns include:

| Column | Meaning |
|--------|---------|
| `USER` | Process owner |
| `PID` | Process ID |
| `%CPU` | CPU usage |
| `%MEM` | Memory usage |
| `STAT` | Process state |
| `START` | Start time |
| `TIME` | CPU time used |
| `COMMAND` | Program or command |

### 3. Find a Specific Process

Search the process list for Nginx:

```bash
ps aux | grep nginx
```

The `|` symbol is a **pipe**. It sends the output of `ps aux` to `grep`, which searches for `nginx`.

A cleaner option is:

```bash
pgrep nginx
```

This returns matching PIDs.

To display both the PID and command:

```bash
pgrep -a nginx
```

---

### 4. Monitor Processes in Real Time

`ps` gives you a snapshot. `top` continuously updates process information:

```bash
top
```

Use it to identify processes consuming high CPU or memory.

A more interactive alternative is:

```bash
htop
```

If `htop` is not installed:

```bash
sudo apt install htop
```

```text
ps    → Process snapshot
top   → Live monitoring
htop  → Interactive live monitoring
```

---

### 5. Stop Processes

To request that a process shuts down gracefully:

```bash
kill 1234
```

or generally:

```bash
kill PID
```

By default, `kill` sends **SIGTERM**, allowing the process to clean up before exiting.

To force a process to stop immediately:

```bash
kill -9 1234
```

or:

```bash
kill -9 PID
```

`-9` sends **SIGKILL**, which the process cannot ignore.

```text
kill PID      → Graceful termination request
kill -9 PID   → Force immediate termination
```

> [!WARNING]
> Try normal `kill` first. Use `kill -9` only when the process does not terminate normally.

To terminate processes by name:

```bash
pkill nginx
```

> [!CAUTION]
> `pkill` can terminate multiple processes matching the given name. Make sure you are targeting the correct application.

---

## Services

A **service** is software that normally runs in the background and provides functionality to the system or other applications.

Examples:

```text
nginx → Web server
ssh   → Remote access
mysql → Database
cron  → Scheduled tasks
```

Many Linux systems use **systemd** to manage services.

```text
systemd
   ↓
systemctl
   ↓
Services such as nginx
```

---

### 6. Check Service Status

Check whether Nginx is running:

```bash
systemctl status nginx
```

Common states include:

```text
active (running) → Service is running
inactive (dead)  → Service is stopped
failed           → Service failed to start or stopped unexpectedly
```

---

### 7. Start, Stop, Restart & Reload Services

Start Nginx:

```bash
sudo systemctl start nginx
```

Stop Nginx:

```bash
sudo systemctl stop nginx
```

Restart Nginx:

```bash
sudo systemctl restart nginx
```

Reload its configuration without fully stopping the service:

```bash
sudo systemctl reload nginx
```

```text
restart → Stop + start the service
reload  → Reload configuration while keeping the service running
```

> **Note:** Not every service supports `reload`.

---

### 8. Enable or Disable Services at Boot

Enable Nginx to start automatically during system boot:

```bash
sudo systemctl enable nginx
```

Disable automatic startup:

```bash
sudo systemctl disable nginx
```

```text
start   → Start service now
stop    → Stop service now
enable  → Start automatically at boot
disable → Do not start automatically at boot
```

Disabling a service does not necessarily stop a service that is already running.

To enable and start it immediately:

```bash
sudo systemctl enable --now nginx
```

To disable automatic startup and stop it immediately:

```bash
sudo systemctl disable --now nginx
```

The `--now` option applies the boot configuration change and immediately starts or stops the service.

---

### 9. List & Check Services

List currently loaded service units:

```bash
systemctl list-units --type=service
```

List available service definitions and their enablement state:

```bash
systemctl list-unit-files --type=service
```

Check whether Nginx is currently active:

```bash
systemctl is-active nginx
```

Check whether it is enabled at boot:

```bash
systemctl is-enabled nginx
```

---

### 10. View Service Logs

Linux systems using systemd provide `journalctl` for viewing service logs.

View Nginx logs:

```bash
journalctl -u nginx
```

Show the latest 50 log entries:

```bash
journalctl -u nginx -n 50
```

Follow new log entries in real time:

```bash
journalctl -u nginx -f
```

Here:

```text
-u     → Select a systemd unit
-n 50  → Show the latest 50 entries
-f     → Follow new log entries
```

The `-f` behavior is similar to:

```bash
tail -f <file>
```

---

### 11. Troubleshooting a Service

If your Nginx website is not working, use this sequence:

**1. Check service status**

```bash
sudo systemctl status nginx
```

**2. Start it if it is stopped**

```bash
sudo systemctl start nginx
```

**3. Check recent logs if it failed**

```bash
sudo journalctl -u nginx -n 50
```

**4. Check whether Nginx processes exist**

```bash
ps aux | grep nginx
```

**5. Check system resource usage**

```bash
top
```

---

### Process vs. Service

A **process** is a specific running instance of a program identified by a PID.

A **service** is an application managed by the system's service manager and may contain multiple processes.

```text
nginx.service
│
├── nginx process PID 1234
├── nginx process PID 1235
└── nginx process PID 1236
```

```text
Process    → Running program identified by PID
Service    → Managed background application
systemctl  → Controls systemd services
journalctl → Reads system and service logs
```

---

## Environment Variables, PATH and `.bashrc`

Environment variables store configuration values used by the shell and programs. `PATH` tells Linux where to search for commands, while `.bashrc` stores Bash settings that should persist across shell sessions.

---

### 1. Environment Variables

An **environment variable** is a named value stored in the shell environment.

Check common variables:

```bash
echo $HOME
echo $USER
echo $SHELL
```

Example:

```text
HOME=/home/harry
USER=harry
SHELL=/bin/bash
```

View environment variables:

```bash
printenv
env
```

The `$` symbol means: **get the value stored in this variable**.

For example:

```bash
echo $HOME
```

prints the value of `HOME`, while:

```bash
echo HOME
```

simply prints:

```text
HOME
```

---

### 2. Create Variables

Create a shell variable:

```bash
name="Harry"
```

Display its value:

```bash
echo $name
```

> [!IMPORTANT]
> Do not place spaces around `=`.

Correct:

```bash
name="Harry"
```

Incorrect:

```bash
name = "Harry"
```

The incorrect version is interpreted differently by the shell and produces an error.

---

### 3. Shell Variables vs Environment Variables

A normal variable exists only in the current shell:

```bash
name="Harry"
```

To make it available to programs launched from that shell, use `export`:

```bash
export name="Harry"
export APP_ENV="production"
```

You can also write:

```bash
export APP_ENV=production
```

Environment variables are commonly used for application configuration, such as:

```text
DATABASE_URL
API_KEY
PORT
APP_ENV
DEBUG
```

> [!WARNING]
> Environment variables are not automatically secure. Sensitive values may be exposed through logs, debugging, process inspection, or incorrect configuration.

---

### 4. Understanding `PATH`

`PATH` contains the directories Linux searches when you enter a command.

Check it with:

```bash
echo $PATH
```

Example:

```text
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```

The directories are separated by `:`.

```text
PATH
├── /usr/local/sbin
├── /usr/local/bin
├── /usr/sbin
├── /usr/bin
├── /sbin
└── /bin
```

When you run commands such as:

```bash
ls
cat
sudo
```

the shell searches directories in `PATH` to find them.

---

### 5. Find Where a Command Comes From

Find the executable used by a command:

```bash
which ls
```

Example output:

```text
/usr/bin/ls
```

A better shell-aware method is:

```bash
command -v ls
```

You can also use:

```bash
type ls
```

`type` can tell you whether something is an alias, function, shell builtin, or external command.

For example:

```bash
type cd
```

may return:

```text
cd is a shell builtin
```

---

### 6. Why `./` is Sometimes Required

Suppose you have a script named `hello.sh`.

Make it executable:

```bash
chmod +x hello.sh
```

Running:

```bash
hello.sh
```

may produce:

```text
command not found
```

But this works:

```bash
./hello.sh
```

`./` means:

> Run `hello.sh` from the current directory.

The current directory (`.`) is normally not included in `PATH`, partly for security reasons.

---

### 7. Add a Directory to `PATH`

Suppose your scripts are stored in:

```text
/home/harry/scripts
```

Add that directory to the existing `PATH`:

```bash
export PATH="$PATH:/home/harry/scripts"
```

Check the updated value:

```bash
echo $PATH
```

Now commands stored in that directory can be executed without typing their full path.

For example:

```bash
command -v backup
```

> [!WARNING]
> Do not replace your entire `PATH` like this:

```bash
export PATH="/home/harry/scripts"
```

Doing so removes the existing directories from `PATH`, which can make commands such as `ls`, `cat`, and `sudo` unavailable by their normal names.

---

### 8. Temporary vs Permanent Variables

A command such as:

```bash
export APP_ENV=production
```

normally lasts only for the current shell session.

To make Bash settings persistent, add them to:

```text
~/.bashrc
```

For example:

```bash
export APP_ENV=production
export PATH="$PATH:$HOME/scripts"
```

Reload `.bashrc` without opening a new terminal:

```bash
source ~/.bashrc
```

The shorthand form is:

```bash
. ~/.bashrc
```

Here, `.` acts as the `source` command.

---

### 9. Worked Example

Check your current `PATH`:

```bash
echo $PATH
```

Create a scripts directory:

```bash
mkdir -p ~/scripts
```

Create a file named:

```text
~/scripts/hello
```

Add:

```bash
#!/bin/bash
echo "Hello from my script!"
```

Make it executable:

```bash
chmod +x ~/scripts/hello
```

Running the full path works:

```bash
~/scripts/hello
```

But this may not work yet:

```bash
hello
```

Add the scripts directory to `PATH`:

```bash
export PATH="$PATH:$HOME/scripts"
```

Now run:

```bash
hello
```

Verify where Linux finds it:

```bash
command -v hello
```

Example output:

```text
/home/harry/scripts/hello
```

---

## Archives and Compression

**Archiving** and **compression** are related but different:

- **Archiving** combines multiple files and directories into one file.
- **Compression** reduces the size of data.
- `tar` mainly creates archives.
- `gzip` compresses files.
- `zip` generally archives and compresses at the same time.

Example:

```text
project/
├── app.py
├── config.py
├── index.html
├── styles.css
└── images/
    ├── logo.png
    └── banner.jpg

project/ → project.tar → gzip → project.tar.gz
```

---

### 1. Working with `tar`

`tar` stands for **Tape Archive** and is commonly used to combine files and directories into a single archive.

**General Syntax:**

```bash
tar [options] archive-name files
```

### Create a TAR Archive

```bash
tar -cf project.tar project/
```

```text
-c → Create archive
-f → Specify archive file
```

Check the archive size:

```bash
ls -lh project.tar
```

List the contents without extracting:

```bash
tar -tf project.tar
```

```text
-t → List archive contents
-f → Specify archive file
```

Extract the archive:

```bash
tar -xf project.tar
```

Extract while displaying filenames:

```bash
tar -xvf project.tar
```

Create an archive in verbose mode:

```bash
tar -cvf project.tar project/
```

### Common `tar` Options

| Option | Purpose |
|--------|---------|
| `c` | Create archive |
| `x` | Extract archive |
| `t` | List archive contents |
| `v` | Verbose — display files being processed |
| `f` | Specify archive file |
| `z` | Use gzip compression |

---

### 2. Compression with `gzip`

Compress a TAR archive:

```bash
gzip project.tar
```

This normally creates:

```text
project.tar.gz
```

and replaces the original `project.tar`.

Decompress it:

```bash
gunzip project.tar.gz
```

This restores:

```text
project.tar
```

```text
gzip   → Compress
gunzip → Decompress
```

---

### 3. Creating `.tar.gz` Archives

Instead of creating a `.tar` file and compressing it separately, `tar` can do both operations together.

Create a gzip-compressed TAR archive:

```bash
tar -czf project.tar.gz project/
```

```text
c → Create
z → Compress using gzip
f → Specify archive file
```

Extract it:

```bash
tar -xzf project.tar.gz
```

```text
x → Extract
z → Decompress gzip
f → Specify archive file
```

A `.tar.gz` file means:

```text
.tar → TAR archive
.gz  → gzip compression

.tar.gz → A TAR archive compressed with gzip
```

You may also encounter:

```text
.tar.bz2
.tar.xz
```

These use different compression methods but follow the same general archive-and-compress idea.

---

### 4. Working with ZIP Files

Unlike plain `tar`, ZIP generally combines **archiving and compression** in one format.

Create a ZIP archive from a directory:

```bash
zip -r project.zip project/
```

The `-r` option means **recursive**, allowing directories and their contents to be included.

Extract a ZIP archive:

```bash
unzip project.zip
```

Extract into a specific directory:

```bash
unzip project.zip -d extracted/
```

List archive contents without extracting:

```bash
unzip -l project.zip
```

```text
-r → Recursively include directories
-d → Choose extraction destination
-l → List archive contents
```

---

### 5. TAR vs GZIP vs ZIP

| Tool / Format | Archive Files? | Compress Data? |
|---------------|----------------|----------------|
| `tar` | Yes | No, by itself |
| `gzip` | No | Yes |
| `tar.gz` | Yes | Yes |
| `zip` | Yes | Yes |

```text
tar    → Combine files into one archive
gzip   → Compress data
tar.gz → TAR archive + gzip compression
zip    → Archive + compression
```

---

### 6. Worked Example

Create a project directory:

```bash
mkdir project
```

Create some files:

```bash
touch project/app.py project/config.py project/index.html
```

Create a TAR archive:

```bash
tar -cf project.tar project/
```

List its contents:

```bash
tar -tf project.tar
```

Compress it:

```bash
gzip project.tar
```

Decompress it:

```bash
gunzip project.tar.gz
```

Extract the TAR archive:

```bash
tar -xf project.tar
```

Create a compressed TAR archive directly:

```bash
tar -czf project.tar.gz project/
```

Extract it:

```bash
tar -xzf project.tar.gz
```

Create a ZIP archive:

```bash
zip -r project.zip project/
```

Extract it:

```bash
unzip project.zip
```

---

## Cronjobs

**Cron jobs** automatically run commands or scripts at scheduled times.

Examples include:

- Creating backups every night
- Running scripts every hour
- Cleaning files every Sunday
- Generating reports automatically

A scheduled task is called a **cron job**, and the background service that runs these tasks is called **cron**.

---

### 1. Check the Cron Service

Check whether cron is running:

```bash
systemctl status cron
```

You should see:

```text
Active: active (running)
```

If cron is not running:

```bash
sudo systemctl start cron
```

Enable it to start automatically when the system boots:

```bash
sudo systemctl enable cron
```

---

### 2. Understanding `crontab`

A **crontab** is a file containing scheduled tasks for a user.

List your current cron jobs:

```bash
crontab -l
```

Edit your cron jobs:

```bash
crontab -e
```

Example:

```cron
*/5 * * * * echo "Hello" >> /home/harry/cron.log
```

This appends `Hello` to `cron.log` every 5 minutes.

---

### 3. Cron Schedule Format

A cron job contains five scheduling fields followed by a command:

```text
* * * * * command
│ │ │ │ │
│ │ │ │ └── Day of week   (0-7)
│ │ │ └──── Month         (1-12)
│ │ └────── Day of month  (1-31)
│ └──────── Hour          (0-23)
└────────── Minute        (0-59)
```

`*` means **every possible value**.

For example:

```cron
* * * * * command
```

runs the command every minute.

---

### 4. Common Cron Schedules

Run every 5 minutes:

```cron
*/5 * * * * /home/harry/backup.sh
```

Run at the beginning of every hour:

```cron
0 * * * * /home/harry/backup.sh
```

Run every day at 2:30 AM:

```cron
30 2 * * * /home/harry/backup.sh
```

Run every Sunday at 3:00 AM:

```cron
0 3 * * 0 /home/harry/backup.sh
```

Run at midnight on the first day of every month:

```cron
0 0 1 * * /home/harry/report.sh
```

Run at 9:00 AM on Monday, Wednesday, and Friday:

```cron
0 9 * * 1,3,5 /home/harry/report.sh
```

Run at 9:00 AM from Monday to Friday:

```cron
0 9 * * 1-5 /home/harry/report.sh
```

Useful cron patterns:

```text
*       → Every value
*/5     → Every 5
1,5,10  → Specific values
1-5     → Range
```

Days of the week:

```text
0 or 7 → Sunday
1      → Monday
2      → Tuesday
3      → Wednesday
4      → Thursday
5      → Friday
6      → Saturday
```

---

### 5. Run Scripts with Cron

Instead of placing a large command directly inside crontab, create a script.

Create the script:

```bash
nano /home/harry/backup.sh
```

Example script:

```bash
#!/bin/bash
tar -czf /home/harry/backup.tar.gz /home/harry/project
```

Make it executable:

```bash
chmod +x /home/harry/backup.sh
```

Schedule it to run every day at 2:00 AM:

```cron
0 2 * * * /home/harry/backup.sh
```

> [!NOTE]
> Cron has a more limited environment than your normal terminal. Prefer absolute paths when running scripts and commands.

Find the full path of a command using:

```bash
which tar
```

or:

```bash
command -v tar
```

---

### 6. Save Cron Output to a Log

Cron output does not normally appear in your terminal.

Redirect output to a log file:

```cron
* * * * * /home/harry/test.sh >> /home/harry/cron.log 2>&1
```

Here:

```text
>>    → Append normal output to the file
2>&1  → Send error output to the same file
```

View the log:

```bash
cat /home/harry/cron.log
```

or:

```bash
tail /home/harry/cron.log
```

---

### 7. User and Root Cron Jobs

Cron jobs belong to individual users.

Your user's crontab:

```bash
crontab -e
```

List your jobs:

```bash
crontab -l
```

Root has a separate crontab:

```bash
sudo crontab -e
```

> [!WARNING]
> Root cron jobs run with administrative privileges. Incorrect commands can make significant system changes.

---

### 8. Remove Cron Jobs

Edit the crontab and manually remove a job:

```bash
crontab -e
```

To remove the entire current user's crontab:

```bash
crontab -r
```

> [!CAUTION]
> `crontab -r` removes all cron jobs for the current user. Use it carefully.

---

### 9. Troubleshoot Cron Jobs

If a job does not run, first check your scheduled tasks:

```bash
crontab -l
```

Check the log file:

```bash
tail /home/harry/cron.log
```

Check whether cron is running:

```bash
systemctl status cron
```

Cron uses the server's configured timezone, so make sure the schedule matches the system timezone.

A simple test job is:

```cron
*/5 * * * * echo "Cron works!" >> /home/harry/cron.log
```

After a few minutes, check:

```bash
cat /home/harry/cron.log
```

If `Cron works!` appears repeatedly, cron is running correctly.

> **Practice Resource:** [crontab.guru](https://crontab.guru/) is a useful website for learning and practicing cron job schedules.

---

## Understanding Linux Filesystem

Linux organizes files in a single **directory tree** starting from `/`, unlike Windows, which commonly uses separate drive letters such as `C:\` and `D:\`.

```text
/
├── bin
├── boot
├── dev
├── etc
├── home
├── lib
├── media
├── mnt
├── opt
├── proc
├── root
├── run
├── sbin
├── srv
├── sys
├── tmp
├── usr
└── var
```

You do not need to memorize every directory. Start with the most important ones.

---

### 1. `/` — Filesystem Root

`/` is the top-level directory of the entire Linux filesystem. Everything exists somewhere underneath it.

Move to the root directory:

```bash
cd /
```

List its contents:

```bash
ls /
```

> [!NOTE]
> `/` and `/root` are different:
>
> ```text
> /      → Root of the entire filesystem
> /root  → Home directory of the root user
> ```

---

### 2. `/home` — Users' Files

Normal users usually store their personal files inside `/home`.

```text
/home
├── harry
├── alice
└── bob
```

If your username is `harry`, your home directory is usually:

```text
/home/harry
```

You can return to your home directory using:

```bash
cd ~
```

or simply:

```bash
cd
```

When logged in as `harry`:

```text
~ = /home/harry
```

---

### 3. `/etc` — System Configuration

`/etc` stores system-wide configuration files.

Common examples:

```text
/etc/ssh/
/etc/apt/
/etc/systemd/
/etc/passwd
/etc/hosts
```

View hostname and IP mappings:

```bash
cat /etc/hosts
```

View user account information:

```bash
cat /etc/passwd
```

```text
/etc → System configuration
```

---

### 4. `/var` — Variable Data

`/var` stores data that changes frequently while Linux is running.

Common locations include:

```text
/var/log
/var/cache
/var/lib
```

View available log files:

```bash
ls /var/log
```

Common log files may include:

```text
/var/log/syslog
/var/log/auth.log
```

When troubleshooting a server, `/var/log` is often one of the first places to check.

```text
/var → Frequently changing data, logs, and caches
```

---

### 5. `/usr` — Programs and Shared Resources

`/usr` contains a large amount of installed software, commands, libraries, and shared resources.

Common directories include:

```text
/usr/bin
/usr/sbin
/usr/lib
/usr/share
```

List commands stored in `/usr/bin`:

```bash
ls /usr/bin
```

Find where Python 3 is installed:

```bash
which python3
```

You may see:

```text
/usr/bin/python3
```

Other commands may also exist here:

```text
/usr/bin/grep
/usr/bin/curl
```

```text
/usr → Installed user-space programs and resources
```

---

### 6. `/bin` — Essential Commands

`/bin` traditionally contains essential commands such as:

```text
ls
cp
mv
cat
rm
```

Check what `/bin` points to:

```bash
ls -ld /bin
```

On many modern Linux systems, `/bin` is a symbolic link to:

```text
/usr/bin
```

```text
/bin → Essential command location, commonly merged with /usr/bin
```

---

### 7. `/tmp` — Temporary Files

`/tmp` is used by programs for temporary storage.

Move into it:

```bash
cd /tmp
```

Create a temporary file:

```bash
touch test.txt
```

> [!WARNING]
> Do not store important files in `/tmp`. Its contents may be removed during reboot or automatic cleanup.

```text
/tmp → Temporary files
```

---

### 8. Other Important Directories

| Directory | Purpose |
|-----------|---------|
| `/boot` | Files required to boot Linux |
| `/dev` | Devices represented as files |
| `/proc` | Information about processes and the kernel |
| `/sys` | Kernel and device information |
| `/run` | Runtime data created since boot |
| `/mnt` | Temporary or manual mount points |
| `/media` | Common location for removable media |
| `/opt` | Optional or third-party software |
| `/sbin` | Traditionally system administration commands |
| `/root` | Home directory of the root user |

---

### 9. Walk Through the Filesystem

Start from the root:

```bash
cd /
```

List its contents:

```bash
ls
```

Explore important directories such as:

```text
/home
/etc
/var
/usr
/tmp
```

Check your current location at any time:

```bash
pwd
```

---

### Seven Directories to Remember

```text
/      → Everything starts here
/home  → Users' personal files
/etc   → System configuration
/var   → Changing data and logs
/usr   → Programs and shared resources
/bin   → Essential commands
/tmp   → Temporary files
```

---

## Understanding Nginx

**Nginx** is a web server that listens for HTTP/HTTPS requests, usually on ports **80** and **443**, and returns web pages or other responses.

On a Linux VPS:

```text
Browser → Port 80/443 → Nginx → Website Files
```

You can check the Nginx service with:

```bash
systemctl status nginx
```

---

### 1. Install and Start Nginx

Update the package list:

```bash
sudo apt update
```

Install Nginx:

```bash
sudo apt install nginx
```

Enable Nginx at boot and start it immediately:

```bash
sudo systemctl enable --now nginx
```

Check its status:

```bash
systemctl status nginx
```

Check whether it is active:

```bash
systemctl is-active nginx
```

View running Nginx processes:

```bash
ps aux | grep nginx
```

Several Nginx processes running under one service are normal.

---

### 2. Test the Default Website

From the Linux server, test Nginx using:

```bash
curl http://127.0.0.1
```

or:

```bash
curl http://localhost
```

These commands display the HTML returned by Nginx.

To view only HTTP headers:

```bash
curl -I http://127.0.0.1
```

A successful response may include:

```text
HTTP/1.1 200 OK
Server: nginx
```

From your own computer, open:

```text
http://YOUR_SERVER_IP
```

in a web browser.

---

### 3. Troubleshoot Nginx

Check whether something is listening on port 80:

```bash
sudo ss -tlnp | grep ':80'
```

Test the Nginx configuration:

```bash
sudo nginx -t
```

View the latest Nginx service logs:

```bash
sudo journalctl -u nginx -n 50
```

```text
ss          → Check listening ports
nginx -t    → Test Nginx configuration
journalctl  → View service logs
```

---

### 4. Important Nginx Locations

Common Nginx paths on Ubuntu:

```text
/etc/nginx/nginx.conf         → Main Nginx configuration
/etc/nginx/sites-available/   → Available site configurations
/etc/nginx/sites-enabled/     → Enabled site configurations
/var/www/html/                → Default website files
```

List available sites:

```bash
ls /etc/nginx/sites-available
```

List enabled sites:

```bash
ls /etc/nginx/sites-enabled
```

View enabled-site links in detail:

```bash
ls -l /etc/nginx/sites-enabled
```

Enabled sites are commonly symbolic links to configuration files stored in `sites-available`.

---

### 5. Serve Your Own Web Page

Check the default web directory:

```bash
ls -l /var/www/html
```

Edit the default HTML page:

```bash
sudo nano /var/www/html/index.html
```

Add simple HTML such as:

```html
<!DOCTYPE html>
<html>
<head><title>Hello</title></head>
<body><h1>Hello from Nginx</h1></body>
</html>
```

Save the file and test it:

```bash
curl http://127.0.0.1
```

For normal static HTML changes, Nginx does not need to be restarted because it reads the file when a request arrives.

---

### 6. Reload Nginx Configuration

When you change Nginx configuration files, test them first:

```bash
sudo nginx -t
```

Then reload Nginx:

```bash
sudo systemctl reload nginx
```

If a full restart is required:

```bash
sudo systemctl restart nginx
```

```text
reload  → Reload configuration without fully stopping Nginx
restart → Stop and start Nginx again
```

> [!NOTE]
> For configuration changes, prefer `reload` when possible. Editing static HTML inside `/var/www/html` normally requires only refreshing the browser.

> [!WARNING]
> Do not use `chmod 777` on the web root just to solve permission problems. Fix the correct ownership or group permissions instead. On Ubuntu, Nginx commonly runs as `www-data`.

---

### 7. Basic Nginx Server Block

A simple Nginx server block defines which port to listen on and which files to serve.

```nginx
server {
    listen 80;
    server_name _;
    root /var/www/html;
    index index.html;
}
```

```text
listen 80           → Listen for HTTP traffic
server_name _       → Match the server name
root /var/www/html  → Website files location
index index.html    → Default page
```

The default Ubuntu Nginx configuration already provides this basic setup.

---

### 8. Enable Additional Sites

For additional websites, the typical flow is:

```text
sites-available
      ↓
Create/Edit Site Configuration
      ↓
Link into sites-enabled
      ↓
Test with nginx -t
      ↓
Reload Nginx
```

Disabling a site usually means removing its symbolic link from `sites-enabled` while keeping the original configuration in `sites-available`.

---

### 9. If the Website Does Not Load

Follow this troubleshooting sequence:

**1. Check whether Nginx is running**

```bash
systemctl status nginx
```

**2. Test the configuration**

```bash
sudo nginx -t
```

**3. Test the website locally from the server**

```bash
curl http://127.0.0.1
```

If local `curl` works but the website does not open from your computer, check the firewall or VPS provider's security settings.

Check UFW status:

```bash
sudo ufw status
```

Allow HTTP traffic:

```bash
sudo ufw allow 80/tcp
```

Allow HTTPS traffic:

```bash
sudo ufw allow 443/tcp
```

> [!NOTE]
> These UFW commands apply only if your server uses UFW. Some VPS providers manage firewall rules through their hosting dashboard instead.

---

## Using FileZilla to Transfer Files

**FileZilla** provides a graphical way to transfer files between your computer and a Linux VPS.

```text
SSH       → Command-line access
FileZilla → Visual file transfer
```

For a VPS, use **SFTP (SSH File Transfer Protocol)** over **port 22**, the same connection used by:

```bash
ssh
```

```text
Laptop → SFTP (Port 22) → Linux VPS
```

---

### 1. Connect with FileZilla

1. Install the **FileZilla Client** from [filezilla-project.org](https://filezilla-project.org/).
2. Open **File → Site Manager** or use **Quickconnect**.
3. Enter your server connection details.
4. Choose **SFTP**, not FTP.
5. Connect and accept the server host key on the first connection.

| Field | Typical Value |
|-------|---------------|
| Protocol | SFTP |
| Host | `203.0.113.10` (your server IP) |
| Port | `22` |
| User | `root`, `ubuntu`, or your SSH user |
| Password / Key | Same credentials used for SSH |

After connecting:

```text
Local side  → Files on your laptop
Remote side → Files on your VPS
```

Drag a file to the remote side to **upload** it, or drag it back to **download** it.

> [!WARNING]
> Use **SFTP on port 22** instead of old unencrypted FTP on port 21.

---

### 2. Common Remote Locations

Useful server directories include:

```text
/home/harry
/var/www/html
/etc/nginx
```

For example, files uploaded to:

```text
/var/www/html
```

can be served by Nginx.

You can also edit files directly on the server using:

```bash
nano
```

---

### 3. File Permissions After Upload

Uploaded files still follow Linux ownership and permission rules.

Use:

```bash
chown
```

to change ownership, and:

```bash
chmod
```

to change permissions.

Avoid blindly using:

```bash
chmod 777 <file>
```

A file owned by `root` with restrictive permissions such as `600` may not be readable by Nginx's usual `www-data` user.

---

## Transfer Files from the Terminal

FileZilla is optional. You can also use `scp`, `sftp`, or `rsync`.

### 4. Upload a File

Using SCP:

```bash
scp page.html ubuntu@203.0.113.10:/var/www/html/
```

Using SFTP:

```bash
sftp ubuntu@203.0.113.10
```

Using rsync:

```bash
rsync -av page.html ubuntu@203.0.113.10:/var/www/html/
```

```text
scp   → One-shot file copy
sftp  → Interactive file-transfer session
rsync → Efficient repeated synchronization
```

---

### 5. SFTP Interactive Commands

After connecting with:

```bash
sftp ubuntu@203.0.113.10
```

you can use:

```bash
put index.html
get index.html
ls
cd
bye
```

| Command | Purpose |
|---------|---------|
| `put index.html` | Upload a file |
| `get index.html` | Download a file |
| `ls` | List remote files |
| `cd` | Change remote directory |
| `bye` | Exit the SFTP session |

---

### 6. Download a File

Using SCP:

```bash
scp ubuntu@203.0.113.10:/var/www/html/index.html .
```

Using SFTP:

```bash
sftp ubuntu@203.0.113.10
```

Then:

```bash
get index.html
```

Using rsync:

```bash
rsync -av ubuntu@203.0.113.10:/var/www/html/index.html .
```

Here, `.` means the current local directory.

---

### 7. Copy a Whole Directory

Using SCP:

```bash
scp -r site/ ubuntu@203.0.113.10:/var/www/html/
```

Using rsync:

```bash
rsync -av site/ ubuntu@203.0.113.10:/var/www/html/
```

```text
-r → Copy recursively
-a → Preserve attributes such as permissions and timestamps
-v → Verbose output
```

> [!NOTE]
> With `rsync`, trailing slashes matter. `site/` copies the directory's contents, while `site` can result in the directory itself being placed inside the destination.

---

### 8. Transfer Files Using an SSH Key

Use an SSH private key with SCP:

```bash
scp -i ~/.ssh/id_rsa page.html ubuntu@203.0.113.10:/var/www/html/
```

With SFTP:

```bash
sftp -i ~/.ssh/id_rsa ubuntu@203.0.113.10
```

With rsync:

```bash
rsync -av -e "ssh -i ~/.ssh/id_rsa" page.html ubuntu@203.0.113.10:/var/www/html/
```

---

### What to Use When

| Tool | Best For |
|------|----------|
| **FileZilla** | Visual browsing and occasional uploads |
| **SCP** | Quickly copying one file or a small directory |
| **SFTP** | Interactive file transfer through SSH |
| **rsync** | Repeatedly synchronizing project folders |

All of these transfer files to the same Linux server. Nginx does not care whether `index.html` arrived through FileZilla, `scp`, `rsync`, or `nano`; it serves whatever is inside the configured web root.

---

## Conclusion

You started by understanding the difference between a **kernel, operating system, and Linux distribution**, and finished with a Linux system you can manage through a VPS, VirtualBox, or WSL.

The environment may change, but the core Linux commands remain the same.

```text
ls        → List files and directories
systemctl → Manage services
Cron      → Run scheduled tasks
Nginx     → Serve web content
```

---

### What You Can Do Now

You can now:

- Understand the difference between the Linux kernel and a Linux distribution.
- Connect to a remote Linux server using:

```bash
ssh
```

- Navigate files and directories using:

```bash
ls
```

- Create users, manage groups, and understand permissions such as:

```text
-rwxr-xr--
```

- Install and manage software using APT:

```bash
apt
```

Understand the difference between:

```bash
apt update
apt upgrade
```

```text
update  → Refresh available package information
upgrade → Install available package updates
```

- Manage Linux services using:

```bash
systemctl
```

- Monitor running processes and system resources using:

```bash
top
```

- Configure and understand the `PATH` environment variable.

- Archive and compress files using:

```bash
tar
gzip
zip
```

- Schedule automated tasks with cron.
- Understand important Linux directories such as:

```text
/
/home
/etc
/var
/usr
```

- Deploy an `index.html` file inside:

```text
/var/www/html
```

- Transfer files using FileZilla or:

```bash
scp
```

---

### Good Linux Habits

Test your Nginx configuration before reloading it:

```bash
nginx -t
```

Try graceful process termination first:

```bash
kill <PID>
```

Use force termination only when necessary:

```bash
kill -9 <PID>
```

Use appropriate permissions such as:

```bash
chmod 644 <file>
chmod 755 <file-or-directory>
```

Avoid blindly using:

```bash
chmod 777 <file-or-directory>
```

When adding a user to a supplementary group, prefer:

```bash
usermod -aG <group> <username>
```

instead of:

```bash
usermod -G <group> <username>
```

because `-aG` appends the group without replacing existing supplementary group memberships.

---

### When Something Breaks

Follow a simple troubleshooting path:

```text
Service Status
      ↓
Logs
      ↓
Process List
      ↓
top
```

Linux may seem large at first, but the basic structure remains consistent:

```text
Filesystem starts at /
Shell searches PATH
Kernel manages system resources
Commands let you control the machine
```

You now have the foundation to use Linux intentionally, troubleshoot problems, manage services, automate tasks, and work with Linux servers.

## Author

Click the box below to visit the author's GitHub profile and explore more projects, open-source work, and contributions.

<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="220px">
        <a href="https://github.com/zeeshan020dev">
          <img src="https://github.com/zeeshan020dev.png?size=100" width="100px;" alt="Muhammad Zeeshan Islam"/>
          <br />
          <sub><b>Muhammad&nbsp;Zeeshan&nbsp;Islam</b></sub>
        </a>
        <br />
        <a href="https://github.com/zeeshan020dev" title="GitHub Profile">💻</a>
        <a href="https://github.com/zeeshan020dev" title="Documentation">📖</a>
      </td>
    </tr>
  </tbody>
</table>
