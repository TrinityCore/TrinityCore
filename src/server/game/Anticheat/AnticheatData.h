/*
 * Copyright (C) 2011-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SC_ACDATA_H
#define SC_ACDATA_H

enum ReportTypes
{
    REPORT_TYPE_SPEED               = 0,
    REPORT_TYPE_FLY                 = 1,
    REPORT_TYPE_WATERWALK           = 2,
    REPORT_TYPE_JUMP                = 3,
    REPORT_TYPE_TELEPORT_PLANE      = 4,
    REPORT_TYPE_CLIMB               = 5,
    MAX_REPORT_TYPES
};

struct AnticheatData
{
    AnticheatData() : lastOpcode(0), totalReports(0), average(0.f), creationTime(0), lastRepTime(0), hasDailyReport(false)
    {
        for (uint8 i = 0; i < MAX_REPORT_TYPES; ++i)
        {
            typeReports[i] = 0;
            tempReports[i] = 0;
            tempReportsTimer[i] = 0;
        }
    }

    inline void SetLastOpcode(uint16 opcode) { lastOpcode = opcode; }
    inline uint16 GetLastOpcode() const { return lastOpcode; }

    inline uint32 GetTotalReports() const { return totalReports; }
    inline void SetTotalReports(uint32 value) { totalReports = value; }

    inline uint32 GetTypeReports(ReportTypes type) const { return type < MAX_REPORT_TYPES ? typeReports[type] : 0; }
    inline void SetTypeReports(ReportTypes type, uint32 amount) { if (type >= MAX_REPORT_TYPES) return; typeReports[type] = amount; }

    inline float GetAverage() const { return average; }
    inline void SetAverage(float value) { average = value; }

    inline uint32 GetCreationTime() const { return creationTime; }
    inline void SetCreationTime(uint32 value) { creationTime = value; }

    inline void SetTempReports(uint32 amount, ReportTypes type) { if (type >= MAX_REPORT_TYPES) return; tempReports[type] = amount; }
    inline uint32 GetTempReports(ReportTypes type) const { return type < MAX_REPORT_TYPES ? tempReports[type] : 0; }

    inline void SetTempReportsTimer(uint32 time, ReportTypes type) { if (type >= MAX_REPORT_TYPES) return; tempReportsTimer[type] = time; }
    inline uint32 GetTempReportsTimer(ReportTypes type) const { return type < MAX_REPORT_TYPES ? tempReportsTimer[type] : 0; }

    inline void SetLastReportTimer(uint32 time) { lastRepTime = time; }
    inline uint32 GetLastReportTimer() const { return lastRepTime; }

    inline void SetDailyReportState(bool b) { hasDailyReport = b; }
    inline bool GetDailyReportState() const { return hasDailyReport; }

private:
    uint16 lastOpcode;
    uint32 totalReports;
    uint32 typeReports[MAX_REPORT_TYPES];
    float average;
    uint32 creationTime;
    uint32 lastRepTime;
    uint32 tempReports[MAX_REPORT_TYPES];
    uint32 tempReportsTimer[MAX_REPORT_TYPES];
    bool hasDailyReport;
};

#endif
