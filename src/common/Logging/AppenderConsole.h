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

#ifndef APPENDERCONSOLE_H
#define APPENDERCONSOLE_H

#include <string>
#include "Appender.h"

enum ColorTypes
{
    BLACK,
    RED,
    GREEN,
    BROWN,
    BLUE,
    MAGENTA,
    CYAN,
    GREY,
    YELLOW,
    LRED,
    LGREEN,
    LBLUE,
    LMAGENTA,
    LCYAN,
    WHITE
};

const uint8 MaxColors = uint8(WHITE) + 1;

class TC_COMMON_API AppenderConsole : public Appender
{
    public:
        typedef std::integral_constant<AppenderType, APPENDER_CONSOLE>::type TypeIndex;

        AppenderConsole(uint8 _id, std::string const& name, LogLevel level, AppenderFlags flags, ExtraAppenderArgs extraArgs);
        void InitColors(const std::string& init_str);
        AppenderType getType() const override { return TypeIndex::value; }

    private:
        void SetColor(bool stdout_stream, ColorTypes color);
        void ResetColor(bool stdout_stream);
        void _write(LogMessage const* message) override;
        bool _colored;
        ColorTypes _colors[MaxLogLevels];
};

#endif
