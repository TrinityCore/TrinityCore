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

#ifndef PacketsCommon_h__
#define PacketsCommon_h__

#include "Common.h"
#include "Realm/Realm.h"
#include <typeinfo>

namespace Battlenet
{
    struct PrintableComponent
    {
        virtual ~PrintableComponent() { }

        virtual std::string ToString() const = 0;
    };

    namespace Format
    {
        template<typename T>
        struct is_printable : std::is_base_of<PrintableComponent, typename std::remove_pointer<T>::type>::type
        {
        };

        template<typename T>
        typename std::enable_if<!std::is_pointer<T>::value, T>::type const& Dereference(T const& t) { return t; };

        template<typename T>
        typename std::enable_if<std::is_pointer<T>::value, typename std::remove_pointer<T>::type>::type const& Dereference(T const& t) { return *t; };

        template<typename T>
        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, T const& u, std::false_type)
        {
            if (fieldName[0])
                stream << fieldName << ": ";
            return stream << u << std::endl;
        }

        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, PrintableComponent const& u, std::true_type);
        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, uint8 const& u, std::false_type);

        template<typename T>
        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, std::vector<T> const& u, std::false_type)
        {
            stream << fieldName << ":" << std::endl;
            for (T const& t : u)
                FieldToString(stream, "", Dereference(t), is_printable<T>());
            return stream;
        }

        template<typename T>
        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, Optional<T> const& u)
        {
            if (u)
                FieldToString(stream, fieldName, Dereference(*u), is_printable<T>());
            return stream;
        }

        template<typename T>
        std::ostream& FieldToString(std::ostream& stream, char const* fieldName, T const& u)
        {
            return FieldToString(stream, fieldName, Dereference(u), is_printable<T>());
        }
    }

#define APPEND_FIELD(stream, field) Format::FieldToString(stream, #field, field)

    namespace Version
    {
        struct Record : public PrintableComponent
        {
            std::string ProgramId;
            std::string Component;
            uint32 Version;

            std::string ToString() const override;
        };
    }

    namespace Cache
    {
        struct Handle : public PrintableComponent
        {
            std::string Type;
            std::string Region;
            uint8 ModuleId[32] = { };

            std::string ToString() const override;
        };
    }

    namespace Account
    {
        struct FullName : public PrintableComponent
        {
            std::string GivenName;
            std::string Surname;

            std::string ToString() const override;
        };
    }

    namespace GameAccount
    {
        struct Handle : public PrintableComponent
        {
            uint8 Region = 0;
            std::string ProgramId;
            uint32 Id = 0;

            std::string ToString() const override;
        };
    }

    // For use in packets
    struct PrintableRealmHandle : public RealmHandle, public PrintableComponent
    {
        PrintableRealmHandle() : RealmHandle() { }
        PrintableRealmHandle(uint8 region, uint8 battlegroup, uint32 index)
            : RealmHandle(region, battlegroup, index) { }

        PrintableRealmHandle& operator=(RealmHandle const& r)
        {
            RealmHandle::operator=(r);
            return *this;
        }

        std::string ToString() const override;
    };

    namespace Toon
    {
        struct FullName : public PrintableComponent
        {
            uint8 Region = 0;
            std::string ProgramId;
            uint32 Realm = 0;
            std::string Name;

            std::string ToString() const override;
        };

        struct Handle : public PrintableComponent
        {
            uint8 Region = 0;
            std::string ProgramId;
            uint32 Realm = 0;
            uint64 Id = 0;

            std::string ToString() const override;
        };
    }

    namespace Profile
    {
        struct RecordAddress : public PrintableComponent
        {
            uint32 Label = 0;
            uint64 Id = 0;

            std::string ToString() const override;
        };
    }
}

#endif // PacketsCommon_h__
