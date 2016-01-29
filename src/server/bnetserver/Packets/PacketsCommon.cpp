/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "PacketsCommon.h"
#include "Util.h"

std::string Battlenet::Version::Record::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Version::Record" << std::endl;
    APPEND_FIELD(stream, ProgramId);
    APPEND_FIELD(stream, Component);
    APPEND_FIELD(stream, Version);
    return stream.str();
}

std::string Battlenet::Cache::Handle::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::Handle" << std::endl;
    APPEND_FIELD(stream, Type);
    APPEND_FIELD(stream, Region);
    stream << "ModuleId: " << ByteArrayToHexStr(ModuleId, 32) << std::endl;
    return stream.str();
}

std::string Battlenet::Account::FullName::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Account::FullName" << std::endl;
    APPEND_FIELD(stream, GivenName);
    APPEND_FIELD(stream, Surname);
    return stream.str();
}

std::string Battlenet::GameAccount::Handle::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::GameAccount::Handle" << std::endl;
    APPEND_FIELD(stream, Region);
    APPEND_FIELD(stream, ProgramId);
    APPEND_FIELD(stream, Id);
    return stream.str();
}

std::string Battlenet::PrintableRealmHandle::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::RealmHandle" << std::endl;
    APPEND_FIELD(stream, Region);
    APPEND_FIELD(stream, Site);
    APPEND_FIELD(stream, Realm);
    return stream.str();
}

std::string Battlenet::Toon::FullName::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Toon::FullName" << std::endl;
    APPEND_FIELD(stream, Region);
    APPEND_FIELD(stream, ProgramId);
    APPEND_FIELD(stream, Realm);
    APPEND_FIELD(stream, Name);
    return stream.str();
}

std::string Battlenet::Toon::Handle::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Toon::Handle" << std::endl;
    APPEND_FIELD(stream, Region);
    APPEND_FIELD(stream, ProgramId);
    APPEND_FIELD(stream, Realm);
    APPEND_FIELD(stream, Id);
    return stream.str();
}

std::string Battlenet::Profile::RecordAddress::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Profile::RecordAddress" << std::endl;
    APPEND_FIELD(stream, Label);
    APPEND_FIELD(stream, Id);
    return stream.str();
}

std::ostream& Battlenet::Format::FieldToString(std::ostream& stream, char const* fieldName, PrintableComponent const& u, std::true_type)
{
    if (fieldName[0])
        stream << fieldName << ": ";
    return stream << u.ToString();
}

std::ostream& Battlenet::Format::FieldToString(std::ostream& stream, char const* fieldName, uint8 const& u, std::false_type)
{
    return FieldToString(stream, fieldName, uint32(u), std::false_type());
}
