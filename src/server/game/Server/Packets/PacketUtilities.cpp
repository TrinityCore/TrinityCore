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

WorldPackets::InvalidStringValueException::InvalidStringValueException(char const* type, std::string_view value)
    : ByteBufferInvalidValueException(type, value), _value(value)
{
}

WorldPackets::InvalidUtf8ValueException::InvalidUtf8ValueException(std::string_view value)
    : InvalidStringValueException("utf8 string", value)
{
}

WorldPackets::InvalidHyperlinkException::InvalidHyperlinkException(std::string_view value, Reason reason)
    : InvalidStringValueException(GetReasonText(reason), value), _reason(reason)
{
}

char const* WorldPackets::InvalidHyperlinkException::GetReasonText(Reason reason)
{
    switch (reason)
    {
        case Malformed: return "malformed hyperlink";
        case NotAllowed: return "not allowed hyperlink";
        default: return "hyperlink";
    }
}

void WorldPackets::Strings::ByteSize::Validate(std::string_view value, std::size_t maxSize)
{
    if (std::size_t size = value.size(); size > maxSize)
        OnInvalidArraySize(size, maxSize);
}

void WorldPackets::Strings::Utf8::Validate(std::string_view value)
{
    if (!utf8::is_valid(value.begin(), value.end()))
        throw InvalidUtf8ValueException(value);
}

void WorldPackets::Strings::Hyperlinks::Validate(std::string_view value)
{
    if (!Trinity::Hyperlinks::CheckAllLinks(value))
        throw InvalidHyperlinkException(value, InvalidHyperlinkException::Malformed);
}

void WorldPackets::Strings::NoHyperlinks::Validate(std::string_view value)
{
    if (value.find('|') != std::string::npos)
        throw InvalidHyperlinkException(value, InvalidHyperlinkException::NotAllowed);
}

void WorldPackets::OnInvalidArraySize(std::size_t requestedSize, std::size_t sizeLimit)
{
    throw PacketArrayMaxCapacityException(requestedSize, sizeLimit);
}

WorldPackets::PacketArrayMaxCapacityException::PacketArrayMaxCapacityException(std::size_t requestedSize, std::size_t sizeLimit)
    : ByteBufferException(Trinity::StringFormat("Attempted to read more array elements from packet {} than allowed {}", requestedSize, sizeLimit))
{
}
