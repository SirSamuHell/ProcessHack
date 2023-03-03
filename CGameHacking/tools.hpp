#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

#include <string>
#include <vector>



#include <Windows.h>

class ProcessHack
{
private:
	ProcessHack() = default;
	~ProcessHack();
	ProcessHack(const ProcessHack&) = delete;  

	std::vector<void*> m_handles;

public:
	static ProcessHack* Get();

public:
	void Release();

	int GetProcessIdFromName(const std::wstring processName);
	void* GetProcessHandleFromProcessID(const int processID);
	uint32_t GetModuleAddressFromProcess(const std::wstring targetModule, const int processID);
	std::vector<std::wstring> GetModuleFilenameFromProcessID(const int processID);

	template<typename T>
	T ReadProcessMemoryFromProcessID(void* hProcess, void* targetAddress);

	template<typename T>
	void WriteProcessMemoryFromProcessID(void* hProcess, void* targetAddress, T writeData);
};
 

template<typename T>
T ProcessHack::ReadProcessMemoryFromProcessID(void* hProcess, void* targetAddress)
{
	T data{};

	ReadProcessMemory(hProcess, targetAddress, &data, sizeof(T), nullptr);

	return data;
}

template<typename T>
void ProcessHack::WriteProcessMemoryFromProcessID(void* hProcess, void* targetAddress, T writeData)
{
	WriteProcessMemory(hProcess, targetAddress, &writeData, sizeof(T), nullptr);
}
 

#endif 