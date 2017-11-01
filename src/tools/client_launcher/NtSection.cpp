/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "NtSection.hpp"
#include <winternl.h>

// wdm.h
typedef enum _SECTION_INHERIT {
    ViewShare = 1,
    ViewUnmap = 2
} SECTION_INHERIT;

NTSYSAPI NTSTATUS NTAPI NtCreateSection(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PLARGE_INTEGER MaximumSize, ULONG SectionPageProtection, ULONG AllocationAttributes, HANDLE FileHandle);
NTSYSAPI NTSTATUS NTAPI NtMapViewOfSection(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID *BaseAddress, ULONG_PTR ZeroBits, SIZE_T CommitSize, PLARGE_INTEGER SectionOffset, PSIZE_T ViewSize, SECTION_INHERIT InheritDisposition, ULONG AllocationType, ULONG Win32Protect);
NTSYSAPI NTSTATUS NTAPI NtUnmapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress);
NTSYSAPI NTSTATUS NTAPI NtSuspendProcess(HANDLE ProcessHandle);
NTSYSAPI NTSTATUS NTAPI NtResumeProcess(HANDLE ProcessHandle);

struct NtdllFunctions
{
    decltype(&::NtQueryInformationProcess) NtQueryInformationProcess;
    decltype(&::NtCreateSection) NtCreateSection;
    decltype(&::NtMapViewOfSection) NtMapViewOfSection;
    decltype(&::NtUnmapViewOfSection) NtUnmapViewOfSection;
    decltype(&::NtSuspendProcess) NtSuspendProcess;
    decltype(&::NtResumeProcess) NtResumeProcess;
    decltype(&::NtClose) NtClose;
};

template<typename T>
void AssignHelper(T& func, FARPROC proc) { func = (T)proc; }

std::unique_ptr<NtdllFunctions> GetNtFunctions()
{
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");

    std::unique_ptr<NtdllFunctions> functions = std::make_unique<NtdllFunctions>();
    AssignHelper(functions->NtQueryInformationProcess, GetProcAddress(ntdll, "NtQueryInformationProcess"));
    AssignHelper(functions->NtCreateSection, GetProcAddress(ntdll, "NtCreateSection"));
    AssignHelper(functions->NtMapViewOfSection, GetProcAddress(ntdll, "NtMapViewOfSection"));
    AssignHelper(functions->NtUnmapViewOfSection, GetProcAddress(ntdll, "NtUnmapViewOfSection"));
    AssignHelper(functions->NtSuspendProcess, GetProcAddress(ntdll, "NtSuspendProcess"));
    AssignHelper(functions->NtResumeProcess, GetProcAddress(ntdll, "NtResumeProcess"));
    AssignHelper(functions->NtClose, GetProcAddress(ntdll, "NtClose"));
    return functions;
}

NtSection::NtSection(HANDLE process, HANDLE section, std::vector<BYTE>&& data)
    : _ntdll(GetNtFunctions()), _processHandle(process), _sectionHandle(section), _data(std::move(data))
{
}

NtSection::~NtSection()
{
    _ntdll->NtClose(_sectionHandle);
}

std::unique_ptr<NtSection> NtSection::CopyCodeSection(HANDLE process)
{
    ULONG dummy;
    std::unique_ptr<NtdllFunctions> ntdll = GetNtFunctions();

    PROCESS_BASIC_INFORMATION pbi;
    if (!NT_SUCCESS(ntdll->NtQueryInformationProcess(process, ProcessBasicInformation, &pbi, sizeof(pbi), &dummy)))
        return nullptr;

    void* imageBase;
    if (!ReadProcessMemory(process, &pbi.PebBaseAddress->Reserved3[1], &imageBase, sizeof(imageBase), nullptr))
        return nullptr;

    MEMORY_BASIC_INFORMATION mbi;
    if (!VirtualQueryEx(process, imageBase, &mbi, sizeof(mbi)))
        return nullptr;

    std::vector<BYTE> code(mbi.RegionSize);
    if (!ReadProcessMemory(process, mbi.BaseAddress, code.data(), mbi.RegionSize, nullptr))
        return nullptr;

    ntdll->NtSuspendProcess(process);
    std::shared_ptr<void> threads(nullptr, [&ntdll, process](void*)
    {
        ntdll->NtResumeProcess(process);
    });

    HANDLE sectionHandle = nullptr;
    LARGE_INTEGER maximumSize = {};
    maximumSize.QuadPart = mbi.RegionSize;
    if (!NT_SUCCESS(ntdll->NtCreateSection(&sectionHandle, SECTION_ALL_ACCESS, nullptr, &maximumSize, PAGE_EXECUTE_READWRITE, SEC_COMMIT, nullptr)))
        return nullptr;

    if (!NT_SUCCESS(ntdll->NtUnmapViewOfSection(process, mbi.BaseAddress)))
        return nullptr;

    std::unique_ptr<NtSection> section(new NtSection(process, sectionHandle, std::move(code)));
    section->CreateView(PAGE_EXECUTE_READ, mbi.BaseAddress);
    PVOID writableView = section->CreateView(PAGE_READWRITE);

    if (!WriteProcessMemory(process, writableView, section->_data.data(), mbi.RegionSize, nullptr))
        return nullptr;

    section->DestroyView(writableView);

    return section;
}

LPVOID NtSection::CreateView(DWORD protect, PVOID viewBase /*= nullptr*/)
{
    LARGE_INTEGER sectionOffset = {};
    SIZE_T viewSize = 0;
    if (!NT_SUCCESS(_ntdll->NtMapViewOfSection(_sectionHandle, _processHandle, &viewBase, 0, _data.size(), &sectionOffset, &viewSize, ViewUnmap, 0, protect)))
        return nullptr;

    return viewBase;
}

void NtSection::DestroyView(PVOID viewBase)
{
    _ntdll->NtUnmapViewOfSection(_processHandle, viewBase);
}
