/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef APPENDERFILE_H
#define APPENDERFILE_H

#include <atomic>
#include "Appender.h"

class AppenderFile: public Appender
{
    public:
        AppenderFile(uint8 id, std::string const& name, LogLevel level, const char* filename, const char* logDir, const char* mode, AppenderFlags flags, uint64 maxSize);
        ~AppenderFile();
        FILE* OpenFile(std::string const& name, std::string const& mode, bool backup);

    private:
        void CloseFile();
        void _write(LogMessage const* message) override;
        FILE* logfile;
        std::string _fileName;
        std::string _logDir;
        bool _dynamicName;
        bool _backup;
        uint64 _maxFileSize;
        std::atomic<uint64> _fileSize;
};

#endif
