# NDG Linux Essentials --- Modules 8--18 Command Cheat Sheet

This is a command-focused study sheet for NDG Linux Essentials v2.0
Modules/Chapters 8--18.

## Module 8 --- Managing Files and Directories

### cp --- copy

``` bash
cp source.txt destination.txt
cp file.txt Documents/
cp file1.txt file2.txt Documents/
cp -r source_dir destination_dir
cp -i file.txt backup.txt
cp -n file.txt backup.txt
cp -v file.txt Documents/
```

`-i` prompt before overwrite; `-n` do not overwrite; `-r` recursive;
`-v` verbose.

### mv --- move / rename

``` bash
mv file.txt Documents/
mv oldname.txt newname.txt
mv old_directory new_directory
mv -i file.txt Documents/
mv -v file.txt Documents/
```

### rm --- remove

``` bash
rm file.txt
rm file1.txt file2.txt
rm -i file.txt
rm -r directory/
rm -f file.txt
rm -rf directory/
```

`-i` prompts; `-r` recursive; `-f` force. Be very careful with `rm -rf`.

### touch

``` bash
touch file.txt
touch file1.txt file2.txt
```

Creates files if absent; updates timestamps if they already exist.

### Globs

``` bash
ls *.txt
cp *.txt Documents/
ls file?.txt
ls file[123].txt
ls file[1-5].txt
rm *.tmp
```

`*` = zero or more characters; `?` = one character; `[abc]` = one
character from the set; `[0-9]` = one digit.

------------------------------------------------------------------------

## Module 9 --- Archiving and Compression

### tar

``` bash
tar -cf archive.tar file1 file2
tar -cf backup.tar Documents/
tar -tf archive.tar
tar -xf archive.tar
tar -xf archive.tar -C /tmp/
tar -cvf archive.tar Documents/
tar -czf backup.tar.gz Documents/
tar -xzf backup.tar.gz
tar -cjf backup.tar.bz2 Documents/
tar -xjf backup.tar.bz2
tar -cJf backup.tar.xz Documents/
tar -xJf backup.tar.xz
```

Flags: `c` create, `x` extract, `t` list, `f` archive filename, `v`
verbose, `z` gzip, `j` bzip2, `J` xz.

### gzip

``` bash
gzip file.txt
gzip -d file.txt.gz
gunzip file.txt.gz
gzip -l file.txt.gz
gzip -t file.txt.gz
```

### bzip2

``` bash
bzip2 file.txt
bzip2 -d file.txt.bz2
bunzip2 file.txt.bz2
```

### xz

``` bash
xz file.txt
xz -d file.txt.xz
unxz file.txt.xz
```

### zip / unzip

``` bash
zip archive.zip file1 file2
zip -r archive.zip Documents/
unzip -l archive.zip
unzip archive.zip
unzip archive.zip -d Documents/
```

------------------------------------------------------------------------

## Module 10 --- Working With Text

### cat

``` bash
cat file.txt
cat file1.txt file2.txt
cat file1.txt file2.txt > combined.txt
cat file.txt >> combined.txt
cat -n file.txt
```

### less / more

``` bash
less file.txt
more file.txt
```

In `less`: `Space` next page, `b` previous page, `/word` search, `n`
next match, `q` quit.

### head / tail

``` bash
head file.txt
head -5 file.txt
head -n 5 file.txt
tail file.txt
tail -n 5 file.txt
tail -f logfile.txt
```

### sort

``` bash
sort file.txt
sort -r file.txt
sort -n numbers.txt
sort -u file.txt
```

### wc

``` bash
wc file.txt
wc -l file.txt
wc -w file.txt
wc -c file.txt
```

`-l` lines, `-w` words, `-c` bytes.

### nl

``` bash
nl file.txt
```

### cut

``` bash
cut -c 1-5 file.txt
cut -d ':' -f 1 /etc/passwd
cut -d ',' -f 1 users.csv
cut -d ',' -f 1,3 users.csv
```

`-d` delimiter; `-f` field; `-c` characters.

### grep

``` bash
grep "error" logfile.txt
grep -i "error" logfile.txt
grep -n "error" logfile.txt
grep -v "error" logfile.txt
grep -r "TODO" project/
grep -c "error" logfile.txt
grep -w "root" file.txt
grep -E 'start|end' file.txt
```

`-i` ignore case; `-n` line numbers; `-v` invert; `-r` recursive; `-c`
count; `-w` whole word; `-E` extended regex.

### Basic regular expressions

``` bash
grep '^start' file.txt
grep 'end$' file.txt
grep 'c.t' file.txt
grep -E 'start|end' file.txt
```

`^` beginning; `$` end; `.` one character; `|` OR with extended regex.

### Pipes

``` bash
cat file.txt | grep error
grep error logfile.txt | sort
grep error logfile.txt | wc -l
cut -d ':' -f 1 /etc/passwd | sort
```

### Redirection

``` bash
echo "Hello" > file.txt
echo "Hello" >> file.txt
ls /root 2> error.log
command > output.log 2>&1
```

`>` overwrite; `>>` append; `2>` stderr; `2>&1` send stderr where stdout
is going.

------------------------------------------------------------------------

## Module 11 --- Basic Scripting

### Create and execute

``` bash
nano script.sh
chmod +x script.sh
./script.sh
bash script.sh
```

### Shebang

``` bash
#!/bin/bash
```

### Variables / echo

``` bash
name="Hussain"
echo "$name"
```

Do not put spaces around `=`.

### Input

``` bash
read name
read -p "Enter your name: " name
```

### Command substitution

``` bash
current_dir=$(pwd)
echo "$current_dir"
```

### Exit status

``` bash
echo $?
```

Usually `0` means success; non-zero means failure.

### Tests

``` bash
test -f file.txt
[ -f file.txt ]
[ -d directory ]
[ -r file.txt ]
[ -w file.txt ]
[ -x file.txt ]
[ "$name" = "Hussain" ]
[ "$age" -gt 18 ]
```

Numeric operators: `-eq`, `-ne`, `-gt`, `-ge`, `-lt`, `-le`.

### if

``` bash
if [ "$age" -ge 18 ]; then
    echo "Adult"
else
    echo "Minor"
fi
```

### for

``` bash
for file in *.txt
do
    echo "$file"
done
```

### while

``` bash
count=1
while [ "$count" -le 5 ]
do
    echo "$count"
    count=$((count + 1))
done
```

### Arithmetic

``` bash
x=$((5 + 3))
count=$((count + 1))
```

### case

``` bash
case "$choice" in
    1)
        echo "Start"
        ;;
    2)
        echo "Stop"
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
```

------------------------------------------------------------------------

## Module 12 --- Understanding Computer Hardware

### System/kernel

``` bash
uname
uname -a
uname -r
uname -m
arch
```

### CPU

``` bash
lscpu
cat /proc/cpuinfo
grep "model name" /proc/cpuinfo
```

### USB / PCI

``` bash
lsusb
lspci
lspci -v
```

### Storage devices

``` bash
lsblk
lsblk -f
```

### Memory

``` bash
free
free -h
```

------------------------------------------------------------------------

## Module 13 --- Where Data is Stored

### Disk usage

``` bash
df
df -h
df -T
du directory/
du -h directory/
du -sh directory/
du -h --max-depth=1
```

### find

``` bash
find . -name "file.txt"
find . -name "*.txt"
find . -type f
find . -type d
find . -type f -executable
find . -size +100M
find . -name "*.tmp" -delete
```

Be careful with `-delete`.

### mount

``` bash
mount
mount /dev/sdb1 /mnt
umount /mnt
```

### Important directories

``` text
/       root filesystem
/home   user homes
/root   root user's home
/etc    configuration
/var    changing data/logs
/tmp    temporary files
/usr    userland programs/data
/bin    essential commands
/sbin   system administration commands
/dev    device files
/proc   process/kernel information
```

### /proc

``` bash
ls /proc
cat /proc/cpuinfo
cat /proc/meminfo
cat /proc/cmdline
```

------------------------------------------------------------------------

## Module 14 --- Network Configuration

### hostname

``` bash
hostname
sudo hostname newname
```

### ip

``` bash
ip addr
ip a
ip link
ip route
ip neigh
```

### Legacy ifconfig

``` bash
ifconfig
ifconfig eth0
```

Modern Linux generally prefers `ip`.

### ping

``` bash
ping google.com
ping -c 4 google.com
ping 192.168.1.1
```

### netstat

``` bash
netstat
netstat -n
netstat -a
netstat -an
netstat -r
netstat -l
netstat -t
netstat -u
```

### ss

``` bash
ss
ss -ltn
ss -ltnu
sudo ss -ltnp
```

### DNS

``` bash
nslookup example.com
dig example.com
dig +short example.com
```

### Route / traceroute

``` bash
route -n
ip route
traceroute google.com
```

------------------------------------------------------------------------

## Module 15 --- System and User Security

### Identity

``` bash
id
id bob
whoami
```

### Logged-in users

``` bash
who
w
last
```

### Switch users

``` bash
su bob
su -
su - bob
```

### sudo

``` bash
sudo command
sudo ls /root
sudo -i
sudo -u bob command
```

### passwords

``` bash
passwd
sudo passwd bob
```

### Locate commands

``` bash
which ls
whereis ls
```

------------------------------------------------------------------------

## Module 16 --- Creating Users and Groups

Most account-management commands require `root`/`sudo`.

### useradd

``` bash
sudo useradd bob
sudo useradd -m bob
sudo useradd -u 1500 bob
sudo useradd -g developers bob
sudo useradd -G developers,docker bob
sudo useradd -m -s /bin/bash bob
```

`-m` home directory; `-u` UID; `-g` primary group; `-G` supplementary
groups; `-s` login shell.

### usermod

``` bash
sudo usermod -g developers bob
sudo usermod -aG docker bob
sudo usermod -s /bin/bash bob
sudo usermod -u 1500 bob
sudo usermod -L bob
sudo usermod -U bob
```

Important: use `-aG` when adding supplementary groups so existing
supplementary groups are preserved.

### userdel

``` bash
sudo userdel bob
sudo userdel -r bob
```

### groupadd

``` bash
sudo groupadd developers
sudo groupadd -g 2000 developers
```

### groupmod

``` bash
sudo groupmod -n programmers developers
sudo groupmod -g 3000 programmers
```

### groupdel

``` bash
sudo groupdel developers
```

### groups

``` bash
groups
groups bob
```

### getent

``` bash
getent passwd
getent passwd bob
getent group
getent group developers
```

------------------------------------------------------------------------

## Module 17 --- Ownership and Permissions

### Inspect permissions

``` bash
ls -l
ls -la
```

Permission characters:

``` text
r = read
w = write
x = execute
- = absent
```

For files:

``` text
r → read contents
w → modify contents
x → execute
```

For directories:

``` text
r → list entries
w → create/delete/rename entries
x → traverse/access
```

### chmod --- symbolic

``` bash
chmod u+x file.sh
chmod u-x file.sh
chmod g+w file.txt
chmod o-w file.txt
chmod o=rx file
chmod u=rwx,g=rx,o=r file
```

### chmod --- octal

``` bash
chmod 755 script.sh
chmod 644 file.txt
chmod 700 private.sh
chmod 600 secret.txt
chmod 777 shared
chmod -R 755 directory/
```

Permission values:

``` text
r = 4
w = 2
x = 1

7 = rwx
6 = rw-
5 = r-x
4 = r--
3 = -wx
2 = -w-
1 = --x
0 = ---
```

### chown

``` bash
sudo chown bob file.txt
sudo chown bob:developers file.txt
sudo chown -R bob:developers project/
```

### chgrp

``` bash
sudo chgrp developers file.txt
sudo chgrp -R developers project/
```

### umask

``` bash
umask
umask -S
umask 022
```

------------------------------------------------------------------------

## Module 18 --- Special Directories and Files

### setuid

Run a program with the file owner's privileges:

``` bash
chmod u+s program
chmod 4755 program
chmod u-s program
```

Special numeric value: `4000`.

### setgid

For files:

``` bash
chmod g+s program
chmod 2755 program
chmod g-s program
```

For directories, setgid causes newly created files/subdirectories to
inherit the directory's group. Special numeric value: `2000`.

### sticky bit

Common on shared directories:

``` bash
chmod +t shared/
chmod 1777 shared/
chmod -t shared/
```

Special numeric value: `1000`.

Classic example:

``` bash
ls -ld /tmp
```

A final `t` in permissions indicates the sticky bit.

### Special-bit memory

``` text
4000 → setuid
2000 → setgid
1000 → sticky bit
```

------------------------------------------------------------------------

# ⭐ High-Value Command Table

  Command            Purpose
  ------------------ -------------------------------
  `cp`               Copy
  `mv`               Move/rename
  `rm`               Remove
  `touch`            Create/update timestamp
  `tar`              Archive/extract/list
  `gzip`             gzip compression
  `bzip2`            bzip2 compression
  `xz`               xz compression
  `zip` / `unzip`    ZIP archives
  `cat`              Display/concatenate text
  `less`             Scroll text
  `head` / `tail`    First/last lines
  `sort`             Sort lines
  `wc`               Count lines/words/bytes
  `cut`              Extract fields/characters
  `grep`             Search text
  `nl`               Number lines
  `echo`             Print
  `read`             Read input
  `test`             Test conditions
  `uname`            System/kernel info
  `lscpu`            CPU info
  `lsusb`            USB devices
  `lspci`            PCI devices
  `lsblk`            Block devices
  `df`               Filesystem usage
  `du`               Directory usage
  `find`             Find files
  `mount`            Mount filesystem
  `ip`               Network configuration
  `ping`             Connectivity
  `netstat` / `ss`   Network sockets
  `hostname`         Hostname
  `id`               UID/GID/groups
  `whoami`           Current user
  `who` / `w`        Logged-in users
  `last`             Login history
  `su`               Switch user
  `sudo`             Elevated command
  `passwd`           Change password
  `useradd`          Create user
  `usermod`          Modify user
  `userdel`          Delete user
  `groupadd`         Create group
  `groupmod`         Modify group
  `groupdel`         Delete group
  `groups`           Group membership
  `getent`           Query account/group databases
  `chmod`            Permissions
  `chown`            Owner
  `chgrp`            Group owner
  `umask`            Default permission mask

------------------------------------------------------------------------

# ⚡ 80/20 Revision

``` bash
# Files
cp
mv
rm
touch

# Globs
*
?
[]

# Archives
tar
gzip
bzip2
xz
zip
unzip

# Text
cat
less
head
tail
sort
wc
cut
grep
nl

# Scripting
echo
read
test
$?
$()
if
for
while
case

# Hardware
uname
lscpu
lsusb
lspci
lsblk
free

# Storage
df
du
find
mount

# Networking
ip
ifconfig
ping
netstat
ss
hostname
route
nslookup
traceroute

# Security
id
whoami
who
last
su
sudo
passwd

# Users/groups
useradd
usermod
userdel
groupadd
groupmod
groupdel
groups
getent

# Permissions
ls -l
chmod
chown
chgrp
umask

# Special permissions
setuid
setgid
sticky bit
```

## Permission Numbers

``` text
r = 4
w = 2
x = 1

755 = rwxr-xr-x
644 = rw-r--r--
700 = rwx------
600 = rw-------

4000 = setuid
2000 = setgid
1000 = sticky bit
```

## Useful pipelines

``` bash
grep error logfile.txt | sort
grep error logfile.txt | wc -l
cut -d ':' -f 1 /etc/passwd | sort
cut -d ':' -f 1 /etc/passwd | sort | wc -l
```

## Useful administration checks

``` bash
id bob
getent passwd bob
getent group developers
ls -l file.txt
df -h
du -sh directory/
ip addr
ip route
ss -ltnp
```

------------------------------------------------------------------------

## Course scope reference

NDG Linux Essentials v2.0 places Modules/Chapters 8--18 in this
sequence: file management; archiving/compression; text processing;
scripting; hardware; storage; networking; system/user security;
users/groups; ownership/permissions; and special directories/files.

The NDG course is aligned with the LPI Linux Essentials certification
and is offered as a free course while offered by NDG.
