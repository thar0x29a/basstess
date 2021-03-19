# basstess
fork of nears's bass assembler v15

More to write later.

## Current State
Right now we have an absolute minmum of 150 8086 (not Nec32) opcodes in our arch file. It is obvious that an CISC architecture like the 8086 needs a proper assembler in its back. Just having an lookup table will not be enought for long. 

But on the other hand it is not very likely that much more than 200 opcodes would ever been used by the users anyway.

**Included:**
 - almost all mov commands
 - interrupt clearing
 - increments 
 - short jumps
 - in and out
 - rep stosw and repnz stosw
 - xor, and for the accu
 

Everything else is still missed. Yes I know. Not even 'add' is included.

## Building
Requires make and coreutils (msys/cygwin on windows)
```
git clone https://github.com/thar0x29a/basstess.git && cd bass/bass && make
```

## How to help?!
You are missing some commands? You want to help? Sure! Here is a step by step guide how to add an opcode:

 - download nasm
 - make a text file that is absolute clean except for the command that you miss. If you have any constant values involved just use 0xFF or 0x00 for better understanding later. 
 - make a binary with nasm by just run it with `nasm sample.asm`. Then use hexdump (\*nix command line command, also downloadable for windows)
 - The the binary there? Good. Thats what to insert into the wsc.cpu.arch file. 
 
Its pretty easy to just translate one command. But its even easier to loose interest by doing so.

Your help on this tiresome work is welcome!
 