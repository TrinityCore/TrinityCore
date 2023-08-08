/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AnticheatData.h"

AnticheatData::AnticheatData()
{
    lastOpcode = 0;
    totalReports = 0;
    for (uint8 i = 0; i < MAX_REPORT_TYPES; i++)
    {
        typeReports[i] = 0;
        tempReports[i] = 0;
        tempReportsTimer[i] = 0;
    }
    average = 0;
    creationTime = 0;
    hasDailyReport = false;
}

AnticheatData::~AnticheatData()
{
}

void AnticheatData::SetDailyReportState(bool b)
{
    hasDailyReport = b;
}

bool AnticheatData::GetDailyReportState()
{
    return hasDailyReport;
}

void AnticheatData::SetLastOpcode(uint32 opcode)
{
    lastOpcode = opcode;
}

void AnticheatData::SetPosition(float x, float y, float z, float o)
{
    lastMovementInfo.pos = { x, y, z, o };
}

uint32 AnticheatData::GetLastOpcode() const
{
    return lastOpcode;
}

const MovementInfo& AnticheatData::GetLastMovementInfo() const
{
    return lastMovementInfo;
}

void AnticheatData::SetLastMovementInfo(MovementInfo& moveInfo)
{
    lastMovementInfo = moveInfo;
}

uint32 AnticheatData::GetTotalReports() const
{
    return totalReports;
}

void AnticheatData::SetTotalReports(uint32 _totalReports)
{
    totalReports = _totalReports;
}

void AnticheatData::SetTypeReports(uint32 type, uint32 amount)
{
    typeReports[type] = amount;
}

uint32 AnticheatData::GetTypeReports(uint32 type) const
{
    return typeReports[type];
}

float AnticheatData::GetAverage() const
{
    return average;
}

void AnticheatData::SetAverage(float _average)
{
    average = _average;
}

uint32 AnticheatData::GetCreationTime() const
{
    return creationTime;
}

void AnticheatData::SetCreationTime(uint32 _creationTime)
{
    creationTime = _creationTime;
}

void AnticheatData::SetTempReports(uint32 amount, uint8 type)
{
    tempReports[type] = amount;
}

uint32 AnticheatData::GetTempReports(uint8 type)
{
    return tempReports[type];
}

void AnticheatData::SetTempReportsTimer(uint32 time, uint8 type)
{
    tempReportsTimer[type] = time;
}

uint32 AnticheatData::GetTempReportsTimer(uint8 type)
{
    return tempReportsTimer[type];
}
