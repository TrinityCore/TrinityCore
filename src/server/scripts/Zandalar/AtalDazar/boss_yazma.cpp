/*
 * Copyright 2023 AzgathCore
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

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "ScriptMgr.h"
#include "atal_dazar.h"

enum Spells {
    //Soulrend
    SPELL_SOULREND_TARGET_SELECTOR = 249921,
    SPELL_SOULREND = 249923,
    SPELL_SOULREND_EXPLODE = 256577,
    SPELL_SOULREND_DAMAGE_HEROIC = 259191,
    SPELL_SOULREND_DAMAGE = 259145, //The heroic vertion have this damage too, so i don't know why this spell but just in case
    SPELL_SOULREND_PYROSHADOW_ON = 259186,
    //Basic Spells
    SPELL_WRACKING_PAIN = 250096,
    SPELL_SKEWER = 249919,
    //Echoes of Shadra
    //SPELL_TARGET_SELECTOR = 257066, //HITS ALL UNITS IN RANGE
    SPELL_ECHOES_OF_SHADOW = 250050,
    SPELL_ECHOES_OF_SHADOW_EMPOWERED = 258612,
    SPELL_ECHOES_OF_SHADOW_EMPOWERED2 = 256036,
    SPELL_ECHOES_OF_SHADOW_SPAWN = 257291,
    SPELL_ECHOES_OF_SHADOW_SPAWN_SMALL = 263092, // ?
    //SPELL_ECHOES_OF_SHAODW_AREATRIGGER = 263096, // the spiders on the stairs
    SPELL_ECHOES_OF_SHADOW_AREATRIGGER = 250022, //Bigger
};

enum Npcs {
    NPC_SOULREND = 125828,
};

enum Events {
    EVENT_SKEWER = 1,
    EVENT_WRACKING_PAIN,
    EVENT_ECHOES_OF_SHADOW,
    EVENT_SHADOWY_REMAINS,
    EVENT_SOULREND,
    EVENT_ECHOES_OF_SHADOW_SPAWN,
    EVENT_SHADOW_EMPOWERED = 1,
    EVENT_SHADOW_EMPOWERED_STOP = 2,
};

void AddSC_boss_yazma()
{
    
}
