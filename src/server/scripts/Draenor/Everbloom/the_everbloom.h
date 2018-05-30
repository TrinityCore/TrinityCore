/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#ifndef DEF_THE_EVERBLOOM_H
#define DEF_THE_EVERBLOOM_H

#define CoSScriptName "instance_everbloom"

uint32 const EncounterCount = 5;

enum DataTypes
{
    DATA_WITHERBARK       = 1,
    DATA_ANCIENT_PROTECTORS,
    DATA_XERITAC,
    DATA_ARCHMAGE_SOL,
    DATA_YALNU,
    DATA_LIFE_WARDEN_GOLA,
    DATA_EARTHSHAPER_TELU,
    DATA_DULHU,
};

enum eEverbloomNpcs
{
    NPC_WITHERBARK          = 81522,
    NPC_LIFE_WARDEN_GOLA    = 83892,
    NPC_EARTHSHAPER_TELU    = 83893,
    NPC_DULHU               = 83894,
    NPC_XERITAC             = 84550,
    NPC_ARCHMAGE_SOL        = 82682,
    NPC_YALNU               = 83846,
    NPC_SLG_GENERIC_MOP     = 68553
};

enum eEverbloomAchievements
{
    AchievementTheEverbloomNormal = 9044,
    AchivementTheEverbloomHeroic  = 9053,
    AchivementWeedWhacker         = 9223,
    AchivementWaterManagement     = 9017
};

enum eEverbloomGameobjects
{
    ObjectSWPortal = 234025
};

#endif
