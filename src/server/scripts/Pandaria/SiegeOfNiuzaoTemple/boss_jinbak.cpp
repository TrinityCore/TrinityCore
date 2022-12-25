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
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_SAP_PUDDLE_GROW = 120865,
    SPELL_SAP_PUDDLE_VISUAL = 119939,
    SPELL_COSMETIC_SHIELD_AURA = 131628,
    SPELL_DETONATE_DAMAGE = 120002,
    SPELL_DETONATE_VISUAL_OOC = 120095,
    SPELL_DETONATE = 120001,
    SPELL_DELAYED_SUMMON_SAPPLING = 119990,
    SPELL_SUMMON_SAPPLING_VISUAL_PRE_EFFECT = 120071,
};

enum Events
{
    EVENT_SAP_PUDDLE_CAST_GROW = 1,
    EVENT_VINZIER_JINBAK_CAST_DETONATE,
    EVENT_VINZIER_JINBAK_SUMMON_SAP_GLOBULES,
};

enum Actions
{
    ACTION_SAP_PUDDLE_START_GROWING = 1,
    ACTION_SAP_PUDDLE_STOP_GROWING,
    ACTION_SAP_PUDDLE_EXPLODE,
    ACTION_SAP_PUDDLE_DOUBLE_IN_SIZE,
};

enum Misc
{
    NPC_SAP_PUDDLE = 61613,
};

enum Points
{
    POINT_SAP_GLOBULE_MOVE_TO_CENTER = 1,
};

void AddSC_boss_jinbak()
{
    
}
