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

#ifndef HACKS_boost_program_options_with_filesystem_path_h__
#define HACKS_boost_program_options_with_filesystem_path_h__

#include <boost/filesystem/path.hpp>
#include <boost/program_options/value_semantic.hpp>

namespace boost
{
namespace filesystem
{
    static void validate(boost::any& v, std::vector<std::string> const& values, path* /*target_type_tag*/, int)
    {
        using namespace boost::program_options;

        validators::check_first_occurrence(v);
        std::string const& s = validators::get_single_string(values);
        try
        {
            v = path(s);
        }
        catch (std::exception const&)
        {
            throw validation_error(invalid_option_value(s));
        }
    }
}
}

#endif // HACKS_boost_program_options_with_filesystem_path_h__
