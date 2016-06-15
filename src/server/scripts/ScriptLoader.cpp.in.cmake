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

// This file was created automatically from your script configuration!
// Use CMake to reconfigure this file, never change it on your own!

#cmakedefine TRINITY_IS_DYNAMIC_SCRIPTLOADER

#include "Define.h"
#include <vector>
#include <string>

@TRINITY_SCRIPTS_FORWARD_DECL@
#ifdef TRINITY_IS_DYNAMIC_SCRIPTLOADER
#  include "revision_data.h"
#  define TC_SCRIPT_API TC_API_EXPORT
extern "C" {

/// Exposed in script modules to return the script module revision hash.
TC_SCRIPT_API char const* GetScriptModuleRevisionHash()
{
    return _HASH;
}

/// Exposed in script module to return the name of the script module
/// contained in this shared library.
TC_SCRIPT_API char const* GetScriptModule()
{
    return "@TRINITY_CURRENT_SCRIPT_PROJECT@";
}

#else
#  include "ScriptLoader.h"
#  define TC_SCRIPT_API
#endif

/// Exposed in script modules to register all scripts to the ScriptMgr.
TC_SCRIPT_API void AddScripts()
{
@TRINITY_SCRIPTS_INVOKE@}

/// Exposed in script modules to get the build directive of the module.
TC_SCRIPT_API char const* GetBuildDirective()
{
    return _BUILD_DIRECTIVE;
}

#ifdef TRINITY_IS_DYNAMIC_SCRIPTLOADER
} // extern "C"
#endif
