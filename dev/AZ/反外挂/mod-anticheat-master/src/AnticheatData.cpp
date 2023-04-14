/*
 *MIT License
 *
 *Copyright (c) 2022 Azerothcore
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
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
