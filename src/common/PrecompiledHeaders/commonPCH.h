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

#include "BoundingIntervalHierarchy.h"
#include "Common.h"
#include "Config.h"
#include "Define.h"
#include "Errors.h"
#include "GitRevision.h"
#include "Log.h"
#include "LogMessage.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "Util.h"
#include "VMapDefinitions.h"
#include "WorldModel.h"
#include <G3D/Ray.h>
#include <G3D/Vector4.h>
#include <algorithm>
#include <cstring>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
