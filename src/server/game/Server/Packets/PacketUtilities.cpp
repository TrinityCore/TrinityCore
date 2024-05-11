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

#include "PacketUtilities.h"
#include "Hyperlinks.h"
#include "StringFormat.h"
#include <utf8.h>

WorldPackets::InvalidStringValueException::InvalidStringValueException(std::string const& value) : ByteBufferInvalidValueException("string", value.c_str())
{
}

WorldPackets::InvalidUtf8ValueException::InvalidUtf8ValueException(std::string const& value) : InvalidStringValueException(value)
{
}

WorldPackets::InvalidHyperlinkException::InvalidHyperlinkException(std::string const& value) : InvalidStringValueException(value)
{
}

WorldPackets::IllegalHyperlinkException::IllegalHyperlinkException(std::string const& value) : InvalidStringValueException(value)
{
}

bool WorldPackets::Strings::Utf8::Validate(std::string const& value)
{
    if (!utf8::is_valid(value.begin(), value.end()))
        throw InvalidUtf8ValueException(value);
    return true;
}

bool WorldPackets::Strings::Hyperlinks::Validate(std::string const& value)
{
    if (!Trinity::Hyperlinks::CheckAllLinks(value))
        throw InvalidHyperlinkException(value);
    return true;
}

bool WorldPackets::Strings::NoHyperlinks::Validate(std::string const& value)
{
    if (value.find('|') != std::string::npos)
        throw IllegalHyperlinkException(value);
    return true;
}

WorldPackets::PacketArrayMaxCapacityException::PacketArrayMaxCapacityException(std::size_t requestedSize, std::size_t sizeLimit)
    : ByteBufferException(Trinity::StringFormat("Attempted to read more array elements from packet {} than allowed {}", requestedSize, sizeLimit))
{
}
