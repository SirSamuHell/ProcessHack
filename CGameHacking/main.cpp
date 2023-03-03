#include "tools.hpp"
#include <iostream>
#include <Windows.h>

int main()
{
    auto pid = ProcessHack::Get()->GetProcessIdFromName(L"hl2.exe");
    auto names = ProcessHack::Get()->GetModuleFilenameFromProcessID(pid);
    auto clientdll = ProcessHack::Get()->GetModuleAddressFromProcess(L"client.dll", pid);
    auto hProcess = ProcessHack::Get()->GetProcessHandleFromProcessID(pid);
    
    std::cout << ProcessHack::Get()->ReadProcessMemoryFromProcessID<int>(hProcess, (void*)(clientdll+0x4F5D24)) << std::endl;
    ProcessHack::Get()->WriteProcessMemoryFromProcessID<int>(hProcess, (void*)(clientdll + 0x4F5D24), 5);

    for (auto name : names)
        std::wcout << name << std::endl;

    


    return 0;
}