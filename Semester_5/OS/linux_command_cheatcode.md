# 🐧 Linux Command Cheat Code

> **A practical Linux/Ubuntu terminal reference**
>
> Covers the commands from **OS Lab 2 --- Overview of Ubuntu Directories
> and Linux Basic Shell Commands**, plus the most useful everyday Linux
> commands for development, system administration, files, permissions,
> processes, networking, packages, Git workflows, and troubleshooting.
>
> **Rule:** You do not need to memorize everything. Learn the command
> name, understand the common flags, and use `man <command>` when you
> need details.

------------------------------------------------------------------------

## 📌 Quick Navigation

-   [0. Terminal & Command Anatomy](#0--terminal--command-anatomy)
-   [1. Linux Directory Structure](#1--linux-directory-structure)
-   [2. Help & Documentation](#2--help--documentation)
-   [3. Navigation](#3--navigation)
-   [4. Listing Files](#4--listing-files)
-   [5. Creating Files & Directories](#5--creating-files--directories)
-   [6. Reading Files](#6--reading-files)
-   [7. Searching](#7--searching)
-   [8. Copying, Moving & Renaming](#8--copying-moving--renaming)
-   [9. Deleting](#9--deleting)
-   [10. Redirection](#10--redirection)
-   [11. Pipes](#11--pipes)
-   [12. Wildcards & Pattern Matching](#12--wildcards--pattern-matching)
-   [13. Text Processing](#13--text-processing)
-   [14. File Information](#14--file-information)
-   [15. Permissions](#15--permissions)
-   [16. Users & sudo](#16--users--sudo)
-   [17. Processes & Jobs](#17--processes--jobs)
-   [18. System Information](#18--system-information)
-   [19. Disk & Storage](#19--disk--storage)
-   [20. Archives & Compression](#20--archives--compression)
-   [21. Networking](#21--networking)
-   [22. Package Management](#22--package-management)
-   [23. Environment Variables](#23--environment-variables)
-   [24. Shell History & Productivity](#24--shell-history--productivity)
-   [25. SSH & Remote Work](#25--ssh--remote-work)
-   [26. Development Essentials](#26--development-essentials)
-   [27. Dangerous Commands ⚠️](#27--dangerous-commands-)
-   [28. Lab 2 Quick Revision](#28--lab-2-quick-revision)
-   [29. Command Patterns to
    Memorize](#29--command-patterns-to-memorize)

------------------------------------------------------------------------

# 0. 🧠 Terminal & Command Anatomy

A Linux command usually looks like:

``` bash
command [options] [arguments]
```

Example:

``` bash
ls -lah ~/Documents
```

Breakdown:

-   `ls` → command
-   `-l`, `-a`, `-h` → options/flags
-   `~/Documents` → argument/path

### Common syntax

``` bash
command
command file.txt
command -option file.txt
command -a -b file.txt
command -ab file.txt
command --long-option file.txt
```

### Important symbols

  Symbol   Meaning
  -------- -------------------------------------------------
  `/`      Root directory
  `~`      Current user's home directory
  `.`      Current directory
  `..`     Parent directory
  `*`      Zero or more characters
  `?`      Exactly one character
  `>`      Redirect output; overwrite
  `>>`     Redirect output; append
  `<`      Redirect input
  `|`      Pipe output into another command
  `&&`     Run next command only if previous succeeds
  `;`      Run commands sequentially regardless of success
  `\`      Escape a special character
  `$VAR`   Expand an environment variable

------------------------------------------------------------------------

# 1. 📁 Linux Directory Structure

Linux uses one directory tree beginning at `/`.

  -----------------------------------------------------------------------
  Directory                           Purpose
  ----------------------------------- -----------------------------------
  `/`                                 Root of the entire filesystem

  `/bin`                              Essential user command binaries; on
                                      many modern distributions this may
                                      be a symlink into `/usr`

  `/sbin`                             System/administrative binaries;
                                      often integrated into `/usr` on
                                      modern systems

  `/etc`                              System configuration files

  `/dev`                              Device files

  `/proc`                             Virtual filesystem exposing
                                      process/kernel information

  `/sys`                              Kernel/device information

  `/run`                              Runtime state since boot

  `/var`                              Variable data such as logs, caches,
                                      databases, spools

  `/tmp`                              Temporary files

  `/usr`                              Installed userland programs,
                                      libraries and shared data

  `/home`                             Users' home directories

  `/root`                             Home directory of the root user ---
                                      **not the same as `/`**

  `/boot`                             Bootloader and kernel-related files

  `/lib`                              Essential libraries; often
                                      integrated into `/usr/lib`

  `/opt`                              Optional/add-on software

  `/mnt`                              Conventional temporary mount point

  `/media`                            Removable media mount points

  `/srv`                              Data served by system services
  -----------------------------------------------------------------------

### Inspect the filesystem

``` bash
ls /
ls /etc
ls /home
ls /var/log
```

Useful:

``` bash
tree /
tree -L 2 /
```

> `tree` may need to be installed first.

------------------------------------------------------------------------

# 2. 🆘 Help & Documentation

## `man` --- Manual pages

The lab's primary help command:

``` bash
man ls
```

Other examples:

``` bash
man cp
man mv
man grep
man chmod
```

Inside `man`:

  Key       Action
  --------- --------------------
  `Space`   Next page
  `b`       Previous page
  `/word`   Search
  `n`       Next search result
  `q`       Quit

### Search manual pages by keyword

``` bash
man -k keyword
```

Equivalent on many systems:

``` bash
apropos keyword
```

Example:

``` bash
man -k archive
```

## `--help`

Fast option reference:

``` bash
ls --help
cp --help
grep --help
```

## `info`

Some GNU utilities have detailed Info documentation:

``` bash
info coreutils
info ls
```

## Find the executable

``` bash
which ls
```

Better for shell-aware lookup:

``` bash
type ls
type cd
```

Find all matching commands:

``` bash
type -a python
```

## Command documentation pattern

When unsure:

``` bash
man <command>
<command> --help
```

**80/20 rule:** Start with `--help`; use `man` when you need exact
behavior.

------------------------------------------------------------------------

# 3. 🧭 Navigation

## `pwd` --- Print Working Directory

Shows where you are:

``` bash
pwd
```

Example:

``` text
/home/hussain
```

## `cd` --- Change Directory

``` bash
cd Documents
cd /home/hussain/Documents
cd ~/Documents
```

### Go home

``` bash
cd
```

or:

``` bash
cd ~
```

### Current directory

``` bash
cd .
```

This changes nothing.

### Parent directory

``` bash
cd ..
```

### Two levels up

``` bash
cd ../..
```

### Previous directory

``` bash
cd -
```

This is extremely useful when jumping between two locations.

### Paths

Absolute:

``` bash
cd /home/hussain/projects
```

Relative:

``` bash
cd projects
```

------------------------------------------------------------------------

# 4. 📋 Listing Files

## `ls`

Basic:

``` bash
ls
```

Long listing:

``` bash
ls -l
```

Hidden files:

``` bash
ls -a
```

Long + hidden:

``` bash
ls -la
```

Human-readable sizes:

``` bash
ls -lh
```

Most useful everyday version:

``` bash
ls -lah
```

Reverse order:

``` bash
ls -lr
```

Sort by modification time:

``` bash
ls -lt
```

Newest first:

``` bash
ls -lt
```

Oldest first:

``` bash
ls -ltr
```

Directories themselves:

``` bash
ls -ld Documents
```

Recursive listing:

``` bash
ls -R
```

Specific path:

``` bash
ls -lah ~/Downloads
```

### What `ls -l` shows

Example:

``` text
-rwxr-xr-- 1 hussain users 2450 Sep 29 11:52 script.sh
```

Roughly:

``` text
-rwxr-xr--
│└──┬──┘
│   └── permissions
└── file type
```

The permission groups are:

``` text
owner | group | others
rwx   | r-x   | r--
```

------------------------------------------------------------------------

# 5. ✍️ Creating Files & Directories

## `touch`

Create an empty file:

``` bash
touch file.txt
```

Create multiple:

``` bash
touch file1.txt file2.txt file3.txt
```

Update timestamps if the file already exists:

``` bash
touch file.txt
```

## `mkdir`

Create directory:

``` bash
mkdir projects
```

Multiple directories:

``` bash
mkdir frontend backend database
```

Create nested directories:

``` bash
mkdir -p projects/backend/src
```

> `-p` creates missing parent directories and avoids errors when they
> already exist.

Example:

``` bash
mkdir -p ~/projects/boxspire/backend/src
```

## `cat > file`

Create/write from terminal:

``` bash
cat > notes.txt
```

Type content, then press:

``` text
Ctrl+D
```

to signal end-of-input.

### Safer one-line creation

``` bash
printf '%s\n' "Hello Linux" > hello.txt
```

------------------------------------------------------------------------

# 6. 👀 Reading Files

## `cat`

Display entire file:

``` bash
cat file.txt
```

Multiple files:

``` bash
cat file1.txt file2.txt
```

Number lines:

``` bash
cat -n file.txt
```

Show non-printing characters:

``` bash
cat -A file.txt
```

Concatenate files:

``` bash
cat file1.txt file2.txt > combined.txt
```

## `less`

Best for large files:

``` bash
less file.txt
```

Multiple files:

``` bash
less file1.txt file2.txt
```

Inside `less`:

  Key       Action
  --------- --------------------
  `Space`   Forward one screen
  `b`       Back one screen
  `↑ / ↓`   Move
  `/word`   Search
  `n`       Next match
  `N`       Previous match
  `g`       Beginning
  `G`       End
  `q`       Quit

### Read beginning/end without opening an interactive viewer

``` bash
head file.txt
tail file.txt
```

Specific number:

``` bash
head -n 20 file.txt
tail -n 20 file.txt
```

Follow a changing log:

``` bash
tail -f /var/log/syslog
```

Follow and show more lines:

``` bash
tail -n 100 -f app.log
```

------------------------------------------------------------------------

# 7. 🔎 Searching

## Search inside a file with `less`

``` bash
less os.txt
```

Inside `less`:

``` text
/science
```

Then:

``` text
n
```

for next occurrence.

------------------------------------------------------------------------

## `grep`

Search for text:

``` bash
grep science os.txt
```

Case-insensitive:

``` bash
grep -i science os.txt
```

Search a phrase:

``` bash
grep -i 'spinning top' os.txt
```

Show line numbers:

``` bash
grep -n science os.txt
```

Count matching lines:

``` bash
grep -c science os.txt
```

Show lines that **do not** match:

``` bash
grep -v science os.txt
```

Combine options:

``` bash
grep -ivc science os.txt
```

Search recursively:

``` bash
grep -r "TODO" .
```

Case-insensitive recursive search:

``` bash
grep -rin "todo" .
```

Show filenames only:

``` bash
grep -rl "TODO" .
```

Search multiple patterns:

``` bash
grep -E 'error|warning' app.log
```

Useful fixed-string search:

``` bash
grep -F "hello.world" file.txt
```

### Very useful developer pattern

``` bash
grep -Rni "mongodb" .
```

Meaning:

-   `-R` → recursively search
-   `-n` → show line numbers
-   `-i` → ignore case

------------------------------------------------------------------------

## `find`

Find files by name:

``` bash
find . -name "notes.txt"
```

Case-insensitive:

``` bash
find . -iname "notes.txt"
```

Find all `.js` files:

``` bash
find . -name "*.js"
```

Find directories:

``` bash
find . -type d
```

Find regular files:

``` bash
find . -type f
```

Find files modified recently:

``` bash
find . -type f -mtime -1
```

Find large files:

``` bash
find . -type f -size +100M
```

Execute a command on matches:

``` bash
find . -type f -name "*.log" -exec rm {} \;
```

> ⚠️ Be careful with `-exec rm`. Test the `find` command first without
> `rm`.

------------------------------------------------------------------------

## `locate`

Fast filename search:

``` bash
locate notes.txt
```

The database may need updating:

``` bash
sudo updatedb
```

`locate` is fast but can be less current than `find`.

------------------------------------------------------------------------

# 8. 📦 Copying, Moving & Renaming

## `cp` --- Copy

Copy file:

``` bash
cp file1.txt file2.txt
```

Copy to directory:

``` bash
cp file.txt ~/Documents/
```

Copy multiple files:

``` bash
cp file1.txt file2.txt ~/Documents/
```

Copy directory recursively:

``` bash
cp -r project backup/
```

Preserve metadata:

``` bash
cp -a project backup/
```

Interactive overwrite confirmation:

``` bash
cp -i file.txt destination/
```

Verbose:

``` bash
cp -v file.txt destination/
```

------------------------------------------------------------------------

## `mv` --- Move / Rename

Move:

``` bash
mv file.txt ~/Documents/
```

Rename:

``` bash
mv oldname.txt newname.txt
```

Move multiple files:

``` bash
mv *.txt ~/Documents/
```

Interactive:

``` bash
mv -i file.txt destination/
```

Verbose:

``` bash
mv -v file.txt destination/
```

> **Important:** Linux has no separate `rename-file` command for normal
> use. `mv` performs both moving and renaming.

------------------------------------------------------------------------

# 9. 🗑️ Deleting

## `rm`

Delete file:

``` bash
rm file.txt
```

Interactive:

``` bash
rm -i file.txt
```

Verbose:

``` bash
rm -v file.txt
```

Delete multiple:

``` bash
rm file1.txt file2.txt
```

Delete matching files:

``` bash
rm *.tmp
```

Delete directory recursively:

``` bash
rm -r project/
```

Force deletion:

``` bash
rm -f file.txt
```

Recursive + force:

``` bash
rm -rf project/
```

> 🚨 **EXTREMELY DANGEROUS:** `rm -rf` does not normally provide a
> recycle bin. Always inspect the path before executing it.

## `rmdir`

Remove an **empty** directory:

``` bash
rmdir empty_dir
```

Remove empty nested directories:

``` bash
rmdir -p parent/child
```

------------------------------------------------------------------------

# 10. ↔️ Redirection

Linux commands commonly use:

-   **stdin** → standard input
-   **stdout** → standard output
-   **stderr** → standard error

## `>` --- overwrite

``` bash
ls > files.txt
```

This replaces the contents of `files.txt`.

## `>>` --- append

``` bash
ls >> files.txt
```

Adds output to the end.

Example:

``` bash
echo "Hello" > notes.txt
echo "World" >> notes.txt
```

## `<` --- input from file

``` bash
sort < names.txt
```

## Redirect stderr

``` bash
command 2> errors.txt
```

## Redirect stdout and stderr separately

``` bash
command > output.txt 2> errors.txt
```

## Redirect both to the same file

``` bash
command > all.txt 2>&1
```

Common Bash shorthand:

``` bash
command &> all.txt
```

## Discard output

``` bash
command > /dev/null
```

Discard errors:

``` bash
command 2> /dev/null
```

Discard everything:

``` bash
command > /dev/null 2>&1
```

------------------------------------------------------------------------

# 11. 🔗 Pipes

The pipe `|` sends stdout of one command to stdin of another.

``` bash
who | sort
```

Count logged-in users:

``` bash
who | wc -l
```

List files and search:

``` bash
ls -lah | grep ".js"
```

Processes containing Python:

``` bash
ps aux | grep python
```

Disk usage sorted:

``` bash
du -sh * | sort -h
```

View long output one page at a time:

``` bash
ls -lah /usr/bin | less
```

### Mental model

``` text
command A → output → | → input → command B
```

Example:

``` bash
cat app.log | grep ERROR
```

Often this can be simplified to:

``` bash
grep ERROR app.log
```

**Good Linux style:** avoid unnecessary `cat` when the next command
already accepts a filename.

------------------------------------------------------------------------

# 12. 🃏 Wildcards & Pattern Matching

## `*`

Matches zero or more characters.

``` bash
ls *.txt
```

Files ending in `.txt`.

``` bash
ls list*
```

Names beginning with `list`.

``` bash
ls *list
```

Names ending with `list`.

``` bash
rm *.tmp
```

Delete all `.tmp` files in the current directory.

------------------------------------------------------------------------

## `?`

Matches exactly one character.

``` bash
ls ?ouse
```

Can match:

``` text
house
mouse
```

but not:

``` text
grouse
```

------------------------------------------------------------------------

## Character ranges

``` bash
ls file[0-9].txt
```

Matches:

``` text
file1.txt
file2.txt
...
file9.txt
```

Letters:

``` bash
ls file[a-z].txt
```

Specific alternatives:

``` bash
ls file[ab].txt
```

------------------------------------------------------------------------

# 13. 🔤 Text Processing

## `wc`

Word count:

``` bash
wc -w file.txt
```

Line count:

``` bash
wc -l file.txt
```

Character count:

``` bash
wc -m file.txt
```

Byte count:

``` bash
wc -c file.txt
```

Everything:

``` bash
wc file.txt
```

Common:

``` bash
wc -l file.txt
```

------------------------------------------------------------------------

## `sort`

Sort lines:

``` bash
sort names.txt
```

Reverse:

``` bash
sort -r names.txt
```

Numeric:

``` bash
sort -n numbers.txt
```

Human-readable numeric sizes:

``` bash
sort -h
```

Unique sorted lines:

``` bash
sort -u names.txt
```

Sort by a field:

``` bash
sort -k2 file.txt
```

------------------------------------------------------------------------

## `uniq`

Remove adjacent duplicate lines:

``` bash
uniq file.txt
```

Usually combine with `sort`:

``` bash
sort file.txt | uniq
```

Count occurrences:

``` bash
sort file.txt | uniq -c
```

------------------------------------------------------------------------

## `cut`

Extract columns:

``` bash
cut -d',' -f1 data.csv
```

-   `-d','` → delimiter is comma
-   `-f1` → first field

Characters:

``` bash
cut -c1-10 file.txt
```

------------------------------------------------------------------------

## `tr`

Translate characters:

``` bash
echo "hello" | tr 'a-z' 'A-Z'
```

Output:

``` text
HELLO
```

Delete characters:

``` bash
echo "hello123" | tr -d '0-9'
```

------------------------------------------------------------------------

## `sed`

Stream editor.

Replace first occurrence per line:

``` bash
sed 's/old/new/' file.txt
```

Replace all occurrences per line:

``` bash
sed 's/old/new/g' file.txt
```

Do not modify the original file.

Write result:

``` bash
sed 's/old/new/g' input.txt > output.txt
```

> `sed` becomes extremely powerful, but the substitution form
> `s/old/new/g` is the 80/20 part to learn first.

------------------------------------------------------------------------

## `awk`

Useful for column-based text processing:

``` bash
awk '{print $1}' file.txt
```

Print second column:

``` bash
awk '{print $2}' file.txt
```

CSV-like data:

``` bash
awk -F',' '{print $1}' data.csv
```

Simple calculation:

``` bash
awk '{sum += $1} END {print sum}' numbers.txt
```

------------------------------------------------------------------------

# 14. 📊 File Information

## `file`

Identify file type:

``` bash
file image.png
file script.sh
```

## `stat`

Detailed metadata:

``` bash
stat file.txt
```

Access/modification timestamps:

``` bash
stat file.txt
```

## `du`

Disk usage:

``` bash
du file.txt
```

Human-readable:

``` bash
du -h file.txt
```

Directory total:

``` bash
du -sh project/
```

Current directory contents:

``` bash
du -sh *
```

## `df`

Filesystem free space:

``` bash
df
```

Human-readable:

``` bash
df -h
```

Inode usage:

``` bash
df -i
```

------------------------------------------------------------------------

# 15. 🔐 Permissions

Linux permissions normally have three classes:

``` text
owner | group | others
```

And three basic permissions:

``` text
r = read
w = write
x = execute
```

## View permissions

``` bash
ls -l
```

Example:

``` text
-rwxr-xr--
```

Breakdown:

``` text
-   rwx   r-x   r--
│    │     │     │
│  owner  group others
│
file
```

For directories:

``` text
d
```

means directory.

------------------------------------------------------------------------

## Numeric permissions

Values:

  Permission     Value
  ------------ -------
  `r`                4
  `w`                2
  `x`                1

Therefore:

``` text
rwx = 7
rw- = 6
r-x = 5
r-- = 4
-wx = 3
-w- = 2
--x = 1
--- = 0
```

Example:

``` bash
chmod 755 script.sh
```

Means:

``` text
owner  = rwx = 7
group  = r-x = 5
others = r-x = 5
```

Another common example:

``` bash
chmod 644 file.txt
```

Means:

``` text
owner  = rw-
group  = r--
others = r--
```

------------------------------------------------------------------------

## `chmod`

Symbolic mode:

``` bash
chmod u+x script.sh
```

Give owner execute permission.

``` bash
chmod g+w file.txt
```

Give group write permission.

``` bash
chmod o-r file.txt
```

Remove read permission from others.

``` bash
chmod go-rwx file.txt
```

Remove read/write/execute from group and others.

``` bash
chmod a+rw file.txt
```

Give everyone read/write.

Numeric mode:

``` bash
chmod 755 script.sh
chmod 644 file.txt
chmod 700 private.sh
```

Recursive:

``` bash
chmod -R 755 directory/
```

> ⚠️ Avoid blindly using recursive permission changes. Files and
> directories often need different permissions.

------------------------------------------------------------------------

## `chown`

Change owner:

``` bash
sudo chown user file.txt
```

Change owner and group:

``` bash
sudo chown user:group file.txt
```

Recursive:

``` bash
sudo chown -R user:group project/
```

## `chgrp`

Change group:

``` bash
sudo chgrp developers file.txt
```

------------------------------------------------------------------------

# 16. 👤 Users & `sudo`

## Current user

``` bash
whoami
```

## Logged-in users

``` bash
who
```

More detailed:

``` bash
w
```

## User ID and groups

``` bash
id
```

Specific user:

``` bash
id username
```

## `sudo`

Run a command with elevated privileges:

``` bash
sudo command
```

Examples:

``` bash
sudo apt update
sudo systemctl restart nginx
sudo chown user:group file.txt
```

Open a root shell:

``` bash
sudo -i
```

> ⚠️ Prefer `sudo <specific-command>` over staying in a root shell
> unnecessarily.

------------------------------------------------------------------------

# 17. ⚙️ Processes & Jobs

## `ps`

Show processes:

``` bash
ps
```

All processes for your terminal/user:

``` bash
ps -f
```

Common system-wide view:

``` bash
ps aux
```

Search:

``` bash
ps aux | grep python
```

## `top`

Live process monitor:

``` bash
top
```

## `htop`

Friendlier interactive process monitor:

``` bash
htop
```

May need installation.

## `pgrep`

Find process IDs by name:

``` bash
pgrep firefox
```

## `kill`

Terminate by PID:

``` bash
kill 1234
```

Force termination:

``` bash
kill -9 1234
```

> Prefer normal `kill` first. `-9` (`SIGKILL`) should be a last resort
> because the process cannot clean up.

## `pkill`

Kill by process name:

``` bash
pkill firefox
```

## Background process

Run in background:

``` bash
command &
```

Example:

``` bash
gedit &
```

## `jobs`

Show shell jobs:

``` bash
jobs
```

## `fg`

Bring job to foreground:

``` bash
fg
```

Specific job:

``` bash
fg %1
```

## `bg`

Continue a stopped job in background:

``` bash
bg %1
```

### Keyboard shortcuts

  Shortcut   Action
  ---------- ----------------------------------------
  `Ctrl+C`   Interrupt/terminate foreground command
  `Ctrl+Z`   Suspend foreground process
  `Ctrl+D`   End input / EOF
  `Ctrl+L`   Clear terminal display
  `Ctrl+R`   Search command history

------------------------------------------------------------------------

# 18. 🖥️ System Information

## Kernel/system

``` bash
uname
uname -a
uname -r
```

## Distribution information

``` bash
cat /etc/os-release
```

## Hostname

``` bash
hostname
```

Set hostname temporarily/on supported systems:

``` bash
sudo hostnamectl set-hostname new-name
```

## Uptime

``` bash
uptime
```

## Date/time

``` bash
date
```

## Calendar

``` bash
cal
```

## CPU

``` bash
lscpu
```

## Memory

``` bash
free
free -h
```

## PCI devices

``` bash
lspci
```

## USB devices

``` bash
lsusb
```

------------------------------------------------------------------------

# 19. 💾 Disk & Storage

## Disk usage

``` bash
df -h
```

## Directory size

``` bash
du -sh ~/Downloads
```

Largest items:

``` bash
du -sh * | sort -h
```

## Block devices

``` bash
lsblk
```

Filesystem information:

``` bash
lsblk -f
```

## Mount information

``` bash
mount
```

Show mounted filesystems:

``` bash
findmnt
```

## Mount a filesystem

General form:

``` bash
sudo mount /dev/sdX1 /mnt
```

Unmount:

``` bash
sudo umount /mnt
```

> ⚠️ Always verify the device with `lsblk` before mounting or modifying
> disks.

------------------------------------------------------------------------

# 20. 🗜️ Archives & Compression

## `tar`

Create archive:

``` bash
tar -cf archive.tar folder/
```

Create gzip-compressed archive:

``` bash
tar -czf archive.tar.gz folder/
```

Extract:

``` bash
tar -xf archive.tar
```

Extract `.tar.gz`:

``` bash
tar -xzf archive.tar.gz
```

List contents:

``` bash
tar -tf archive.tar
```

Extract to a directory:

``` bash
tar -xzf archive.tar.gz -C destination/
```

### `tar` mnemonic

``` text
c = create
x = extract
t = list
f = file
z = gzip
j = bzip2
J = xz
```

------------------------------------------------------------------------

## `gzip`

Compress:

``` bash
gzip file.txt
```

Decompress:

``` bash
gunzip file.txt.gz
```

## `zip`

Create:

``` bash
zip archive.zip file.txt
```

Directory:

``` bash
zip -r archive.zip folder/
```

Extract:

``` bash
unzip archive.zip
```

List:

``` bash
unzip -l archive.zip
```

------------------------------------------------------------------------

# 21. 🌐 Networking

## `ip`

Show interfaces:

``` bash
ip addr
```

Short:

``` bash
ip a
```

Show routes:

``` bash
ip route
```

Show link status:

``` bash
ip link
```

## `ping`

Test reachability:

``` bash
ping google.com
```

Limit count:

``` bash
ping -c 4 google.com
```

## DNS

Query DNS:

``` bash
dig example.com
```

Specific record:

``` bash
dig A example.com
dig MX example.com
```

Alternative:

``` bash
nslookup example.com
```

## `curl`

Fetch a URL:

``` bash
curl https://example.com
```

Headers:

``` bash
curl -I https://example.com
```

Follow redirects:

``` bash
curl -L https://example.com
```

Download:

``` bash
curl -O https://example.com/file.zip
```

POST JSON:

``` bash
curl -X POST \
  -H "Content-Type: application/json" \
  -d '{"name":"Hussain"}' \
  https://example.com/api
```

## `wget`

Download:

``` bash
wget https://example.com/file.zip
```

Continue a download:

``` bash
wget -c https://example.com/file.zip
```

## Open ports/connections

Modern:

``` bash
ss -tulpn
```

TCP listening ports:

``` bash
ss -ltn
```

## Route tracing

``` bash
traceroute example.com
```

May need installation.

------------------------------------------------------------------------

# 22. 📦 Package Management

Ubuntu/Debian commonly use **APT**.

## Refresh package index

``` bash
sudo apt update
```

## Upgrade installed packages

``` bash
sudo apt upgrade
```

## Update + upgrade

``` bash
sudo apt update && sudo apt upgrade
```

## Install

``` bash
sudo apt install package-name
```

Example:

``` bash
sudo apt install git
```

Multiple:

``` bash
sudo apt install git curl wget
```

## Remove

``` bash
sudo apt remove package-name
```

Remove package + configuration:

``` bash
sudo apt purge package-name
```

Remove unnecessary dependencies:

``` bash
sudo apt autoremove
```

## Search

``` bash
apt search package-name
```

## Package information

``` bash
apt show package-name
```

## List installed packages

``` bash
apt list --installed
```

### Ubuntu `.deb` packages

Install a local `.deb`:

``` bash
sudo apt install ./package.deb
```

------------------------------------------------------------------------

# 23. 🌱 Environment Variables

Show a variable:

``` bash
echo $PATH
```

Show all exported environment variables:

``` bash
printenv
```

Set for current shell:

``` bash
export NAME="Hussain"
```

Read it:

``` bash
echo "$NAME"
```

Remove:

``` bash
unset NAME
```

### Add to PATH temporarily

``` bash
export PATH="$HOME/bin:$PATH"
```

### Shell configuration

Bash commonly:

``` bash
~/.bashrc
```

Zsh commonly:

``` bash
~/.zshrc
```

After editing:

``` bash
source ~/.bashrc
```

or:

``` bash
source ~/.zshrc
```

------------------------------------------------------------------------

# 24. 🕘 Shell History & Productivity

## `history`

Show history:

``` bash
history
```

Search:

``` bash
history | grep docker
```

Run a history entry:

``` bash
!123
```

Run previous command:

``` bash
!!
```

Run previous command with sudo:

``` bash
sudo !!
```

> Use this carefully; it repeats the previous command exactly.

## `clear`

Clear terminal:

``` bash
clear
```

Keyboard alternative:

``` text
Ctrl+L
```

## `echo`

Print text:

``` bash
echo "Hello"
```

Print variable:

``` bash
echo "$PATH"
```

## `printf`

More predictable formatted output:

``` bash
printf '%s\n' "Hello"
```

## Command chaining

Run second only if first succeeds:

``` bash
mkdir project && cd project
```

Run regardless of previous result:

``` bash
command1 ; command2
```

Fallback if first fails:

``` bash
command1 || command2
```

------------------------------------------------------------------------

# 25. 🔑 SSH & Remote Work

## Connect to a server

``` bash
ssh username@server-ip
```

Example:

``` bash
ssh hussain@192.168.1.10
```

Specific port:

``` bash
ssh -p 2222 username@server
```

## Copy local → remote

``` bash
scp file.txt username@server:/path/
```

Directory:

``` bash
scp -r project/ username@server:/path/
```

## Copy remote → local

``` bash
scp username@server:/path/file.txt .
```

## `rsync`

Efficient directory synchronization:

``` bash
rsync -av project/ backup/
```

Remote:

``` bash
rsync -av project/ username@server:/path/project/
```

Common flags:

``` text
-a = archive
-v = verbose
-z = compress during transfer
```

------------------------------------------------------------------------

# 26. 👨‍💻 Development Essentials

## `git`

Check repository:

``` bash
git status
```

Initialize:

``` bash
git init
```

Clone:

``` bash
git clone <repository-url>
```

Add:

``` bash
git add .
```

Commit:

``` bash
git commit -m "message"
```

Pull:

``` bash
git pull
```

Push:

``` bash
git push
```

View history:

``` bash
git log
```

Compact history:

``` bash
git log --oneline
```

Branches:

``` bash
git branch
git switch -c feature-name
git switch main
```

------------------------------------------------------------------------

## `which`, `whereis`, `type`

Where executable comes from:

``` bash
which node
```

More information:

``` bash
whereis node
```

Shell command resolution:

``` bash
type node
type cd
```

`type` is especially useful because some commands, such as `cd`, are
shell builtins rather than standalone executables.

------------------------------------------------------------------------

## Processes for development

Find Node processes:

``` bash
ps aux | grep node
```

Find a process:

``` bash
pgrep -af node
```

Find what is using a port:

``` bash
sudo ss -ltnp
```

------------------------------------------------------------------------

# 27. ⚠️ Dangerous Commands

These are powerful. **Do not copy-paste blindly.**

## Recursive force delete

``` bash
rm -rf directory/
```

The path matters enormously.

Never casually run:

``` bash
rm -rf /
```

Modern systems may block some dangerous forms, but you should never
depend on that.

## Disk-writing commands

Commands involving:

``` bash
dd
mkfs
fdisk
parted
mount
umount
```

can destroy or alter filesystems.

Always verify the target device first:

``` bash
lsblk
```

## Recursive permission changes

``` bash
chmod -R ...
chown -R ...
```

Can break applications or system permissions if used on the wrong
directory.

## Root shell

``` bash
sudo -i
```

Everything you run afterward can have administrator privileges.

**Golden rule:** Before executing a destructive command, ask:

``` text
1. What exact path/device am I targeting?
2. What will this command change?
3. Can I undo it?
4. Did I verify the target?
```

------------------------------------------------------------------------

# 28. 🎓 Lab 2 Quick Revision

The lab focuses on Ubuntu directories and basic terminal/file commands,
including help, listing, creating/viewing, combining, paging, deleting,
moving, copying, searching, appending, directory manipulation,
redirection, pipes, wildcards, history, and `sudo`.
fileciteturn0file0L15-L44

## Commands directly covered in the lab

### Help

``` bash
man ls
```

### Listing

``` bash
ls
ls -R
ls -a
ls -l
ls -lg
```

### Create/read files

``` bash
gedit OS.txt
cat > os.txt
touch os.txt
cat os.txt
```

### Combine files

``` bash
cat OS.txt os.txt > combined.txt
```

### Page-wise view

``` bash
less OS.txt
```

### Delete

``` bash
rm os.txt
```

### Move

``` bash
mv file1 destination/
```

### Rename

``` bash
mv oldname newname
```

### Copy

``` bash
cp file1 file2
cp file.txt destination/
cp -r directory/ destination/
```

### Search with `less`

``` bash
less os.txt
/science
n
```

### Search with `grep`

``` bash
grep science os.txt
grep Science os.txt
grep -i science os.txt
grep -i 'spinning top' os.txt
grep -v science os.txt
grep -n science os.txt
grep -c science os.txt
grep -ivc science os.txt
```

### Word/line count

``` bash
wc -w os.txt
wc -l os.txt
```

### Append

``` bash
cat >> list1
```

Press:

``` text
Ctrl+D
```

### Redirection

``` bash
sort < biglist
sort < biglist > slist
```

### Long listing / permissions

``` bash
ls -l
ls -lg
```

### Change permissions

``` bash
chmod go-rwx os.txt
chmod a+rw os.txt
```

### Directories

``` bash
mkdir OS
mkdir /tmp/MUSIC
cd OS
cd .
cd ..
cd
cd ~
ls ~/OS
pwd
rmdir OS
```

### Terminal

``` bash
clear
```

### Users

``` bash
who
```

### Pipes

``` bash
who | sort
who | wc -l
```

### Wildcards

``` bash
ls list*
ls *list
ls ?list
```

### History

``` bash
history
```

------------------------------------------------------------------------

# 29. 🧩 Command Patterns to Memorize

Instead of memorizing hundreds of commands, memorize these **patterns**.

## Navigation

``` bash
pwd
ls
cd <directory>
cd ..
cd ~
cd -
```

## Files

``` bash
touch file
cat file
less file
cp source destination
mv source destination
rm file
```

## Directories

``` bash
mkdir directory
mkdir -p a/b/c
cp -r source destination
rm -r directory
```

## Search

``` bash
grep "text" file
grep -Rni "text" .
find . -name "*.js"
```

## Permissions

``` bash
ls -l
chmod 755 file
chmod u+x file
chown user:group file
```

## Input/output

``` bash
command > file
command >> file
command < file
command 2> errors.txt
command | another-command
```

## Processes

``` bash
ps aux
top
pgrep name
kill PID
```

## Storage

``` bash
df -h
du -sh directory
lsblk
```

## Networking

``` bash
ip a
ip route
ping host
ss -ltnp
curl URL
```

## Packages

``` bash
sudo apt update
sudo apt install package
sudo apt remove package
sudo apt upgrade
```

------------------------------------------------------------------------

# 🧠 The 30 Commands Worth Learning First

If you're still a beginner, learn these before trying to memorize
everything:

``` text
1.  pwd
2.  ls
3.  cd
4.  mkdir
5.  touch
6.  cat
7.  less
8.  head
9.  tail
10. cp
11. mv
12. rm
13. grep
14. find
15. wc
16. sort
17. chmod
18. chown
19. sudo
20. ps
21. kill
22. df
23. du
24. clear
25. history
26. man
27. echo
28. curl
29. ssh
30. apt
```

------------------------------------------------------------------------

# 🚀 A Practical Linux Learning Order

### Level 1 --- Survive the terminal

``` bash
pwd
ls
cd
mkdir
touch
cat
less
cp
mv
rm
```

### Level 2 --- Control files

``` bash
find
grep
wc
sort
head
tail
```

### Level 3 --- Understand Linux

``` bash
ls -l
chmod
chown
sudo
ps
kill
df
du
```

### Level 4 --- Think like a Linux user

``` bash
|
>
>>
<
&&
||
*
?
```

### Level 5 --- Become productive

``` bash
ssh
scp
rsync
curl
tar
git
apt
```

------------------------------------------------------------------------

# 🔥 10 Extremely Useful Real-World Combinations

## 1. Find large files

``` bash
find . -type f -size +100M
```

## 2. Find TODOs in a project

``` bash
grep -Rni "TODO" .
```

## 3. Find JavaScript files

``` bash
find . -type f -name "*.js"
```

## 4. Watch a log

``` bash
tail -f app.log
```

## 5. Find a process

``` bash
ps aux | grep node
```

## 6. Check disk space

``` bash
df -h
```

## 7. Find which folders are huge

``` bash
du -sh * | sort -h
```

## 8. See listening ports

``` bash
ss -ltnp
```

## 9. Search command history

``` bash
history | grep docker
```

## 10. Run only if previous command succeeds

``` bash
mkdir project && cd project
```

------------------------------------------------------------------------

# 📝 Mini Cheat Sheet

``` bash
# WHERE AM I?
pwd

# WHAT'S HERE?
ls
ls -lah

# MOVE AROUND
cd folder
cd ..
cd ~
cd -

# CREATE
touch file.txt
mkdir folder
mkdir -p a/b/c

# READ
cat file.txt
less file.txt
head file.txt
tail file.txt

# COPY / MOVE / RENAME
cp file.txt copy.txt
cp -r folder backup/
mv old.txt new.txt
mv file.txt folder/

# DELETE
rm file.txt
rm -r folder/

# SEARCH
grep "word" file.txt
grep -Rni "word" .
find . -name "*.js"

# COUNT / SORT
wc -l file.txt
sort file.txt

# PERMISSIONS
ls -l
chmod 755 script.sh
chmod u+x script.sh

# SYSTEM
ps aux
top
free -h
df -h
du -sh *

# NETWORK
ip a
ping example.com
curl https://example.com
ss -ltnp

# PACKAGE
sudo apt update
sudo apt install <package>
sudo apt upgrade

# HELP
man <command>
<command> --help

# HISTORY
history
```

------------------------------------------------------------------------

# 🎯 Final Rule

**Do not try to memorize this document.**

Use it like a reference:

``` text
I know what I want to do
        ↓
Find the command category
        ↓
Use the common command
        ↓
Check --help / man if needed
        ↓
Run it
        ↓
Understand the result
```

The real Linux skill is not remembering every flag.

It is being able to **compose small commands together**:

``` bash
find . -type f -name "*.log" | grep -v node_modules
```

``` bash
du -sh * | sort -h
```

``` bash
ps aux | grep python
```

``` bash
history | grep ssh
```

``` bash
grep -Rni "TODO" . | less
```

Once you understand **commands + options + paths + redirection + pipes +
wildcards**, the Linux terminal becomes much easier to reason about.
