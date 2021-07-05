# basstess (Version 2)
fork of nears's bass assembler v15

Under construction.

## Current State for Wonderswan Color Developers
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
 
Everything else is still missed. Yes I know.

## Building
Requires make and core-utils (msys/cygwin on windows)
```
git clone https://github.com/thar0x29a/basstess.git && cd bass/bass && make
```

## Changes compared to the original Bass
### Arch Files
#### Relative Offsets
The arch def supports the \<term><size> by now. It will calculate an relative offset in 8086 fashion. For Example `\a3` indicates that you want an relative offset from `a` and that your current instruction has 3 bytes. I could had it implemented without the second parameter, but since that gives you an extra to fix some edge cases I decided to just let it in. 

#### Overloading
From now on its possible to overload terms. The feature works, but with limitations since the way how bass works do not include any real lookup strategy. 
```
mov ax, cx     ;$89 $c8
mov ax, *16	   ;$b8 ~a
```
.. will work. Bass will notice that the first version does not match the pattern and will jump forward to the next one. However. If you switch the order, it will not work, since cx could be the 'parameter'. Bass will not choose. It will just try and continue.

### Macro
#### Full nested Namespaces
In the original bass you allready could nest namespaces as much as you want. But the access Level was always limited to `local` (current scope), `global` (global scope), and `parent` (one scope ahead). Not just in definition, but also in access.

This meant that you where not able to use terms outside of the root or the leaves from the outside. This had been removed. You should be able to use every term by its full path from everywhere. 

## How to help?!
You are missing some commands? You want to help? Sure! Here is a step by step guide how to add an opcode:

 - download nasm
 - make a text file that is absolute clean except for the command that you miss. If you have any constant values involved just use 0xFF or 0x00 for better understanding later. 
 - make a binary with nasm by just run it with `nasm sample.asm`. Then use hexdump (\*nix command line command, also downloadable for windows)
 - The the binary there? Good. Thats what to insert into the wsc.cpu.arch file. 
 
Its pretty easy to just translate one command. But its even easier to loose interest by doing so.

Your help on this tiresome work is welcome!

## Next steps
Todo
