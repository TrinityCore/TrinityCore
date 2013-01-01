/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "Appender.h"

class AppenderFile: public Appender
{
    public:
        AppenderFile(uint8 _id, std::string const& _name, LogLevel level, const char* filename, const char* logDir, const char* mode, AppenderFlags flags);
        ~AppenderFile();
        FILE* OpenFile(std::string const& _name, std::string const& _mode, bool _backup);

    private:
        void _write(LogMessage& message);
        FILE* logfile;
        std::string filename;
        std::string logDir;
        std::string mode;
        bool dynamicName;
        bool backup;
};

#endif
