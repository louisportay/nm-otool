# nm-otool

Ce projet a pour but de commencer a decouvrir les arcanes de la programmation bas-niveau.
Decomposition de binaires au programme

Format Mach-O 32 et 64 bits a gerer
Format Fat Binaries (Intel + PPC) 32 et 64 bits
Format Archive


the following symbols are implemented

U Undefined
A Absolute
T Text
D Data
B Bss
C Common

S Other
I Indirect

##Doc

https://lowlevelbits.org/parsing-mach-o-files/
Mach-O File Format Reference
/usr/include/{ar,nlist,loader,fat}.h
man {nm,otool}
man 5 {ar,Mach-O}

##Authorized Functions

open(2)
close(2)
mmap(2)
munmap(2)
write(2)
fstat(2)
malloc(3)
free(3)
