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

#ifndef NtSection_h__
#define NtSection_h__

#include <memory>
#include <vector>
#include <Windows.h>

struct NtdllFunctions;

class NtSection
{
    NtSection(HANDLE process, HANDLE section, std::vector<BYTE>&& data);
public:
    ~NtSection();

    static std::unique_ptr<NtSection> CopyCodeSection(HANDLE process);
    LPVOID CreateView(DWORD protect, PVOID viewBase = nullptr);
    void DestroyView(PVOID viewBase);
    std::vector<BYTE>& GetData() { return _data; }

private:
    std::unique_ptr<NtdllFunctions> _ntdll;
    HANDLE _processHandle;
    HANDLE _sectionHandle;
    std::vector<BYTE> _data;
};

#endif // NtSection_h__
