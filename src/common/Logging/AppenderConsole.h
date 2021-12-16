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

#ifndef APPENDERCONSOLE_H
#define APPENDERCONSOLE_H

#include "Appender.h"

// EnumUtils: DESCRIBE THIS
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
    WHITE,
    NUM_COLOR_TYPES // SKIP
};

class TC_COMMON_API AppenderConsole : public Appender
{
    public:
        static constexpr AppenderType type = APPENDER_CONSOLE;

        AppenderConsole(uint8 _id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<std::string_view> const& args);
        void InitColors(std::string const& name, std::string_view init_str);
        AppenderType getType() const override { return type; }

    private:
        void SetColor(bool stdout_stream, ColorTypes color);
        void ResetColor(bool stdout_stream);
        void Print(std::string const& str, bool error);
        void _write(LogMessage const* message) override;
        bool _colored;
        ColorTypes _colors[NUM_ENABLED_LOG_LEVELS];
};

#endif
