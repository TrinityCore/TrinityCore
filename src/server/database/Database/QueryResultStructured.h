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

#ifndef TRINITYCORE_QUERY_RESULT_STRUCTURED_H
#define TRINITYCORE_QUERY_RESULT_STRUCTURED_H

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/stringize.hpp>

#define DEFINE_FIELD_ACCESSOR_CACHE_FIELD_INDEX_INIT(r, data, i, field) BOOST_PP_COMMA_IF(i) field(result.GetFieldMetadata(BOOST_PP_STRINGIZE(field)).Index)

#define DEFINE_FIELD_ACCESSOR_CACHE_FIELD(r, data, field) Field const& field() const\
    {\
        return Fields[indexes.field];\
    }

#define DEFINE_FIELD_ACCESSOR_CACHE(namespace_name, struct_name, result_type, fields_list) \
    struct namespace_name struct_name \
    { \
        struct Indexes\
        {\
            Indexes(result_type const& result) :\
            BOOST_PP_SEQ_FOR_EACH_I(DEFINE_FIELD_ACCESSOR_CACHE_FIELD_INDEX_INIT, ~, fields_list) { }\
            std::size_t BOOST_PP_SEQ_ENUM(fields_list);\
        };\
        BOOST_PP_SEQ_FOR_EACH(DEFINE_FIELD_ACCESSOR_CACHE_FIELD, ~, fields_list) \
        struct_name(result_type const& result) : Fields(result.Fetch()), indexes(indexes_impl(result)) { }\
        Field* Fields; \
        static Indexes const& indexes_impl(result_type const& result) { static Indexes const instance(result); return instance; }\
        Indexes const& indexes;\
    }

#define DEFINE_FIELD_ACCESSOR_CACHE_ANONYMOUS(result_type, fields_list) DEFINE_FIELD_ACCESSOR_CACHE(BOOST_PP_EMPTY(), BOOST_PP_CAT(FieldAccessors, __LINE__), result_type, fields_list)

#endif // TRINITYCORE_QUERY_RESULT_STRUCTURED_H
