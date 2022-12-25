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
#include "CreatureTextMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    SPELL_BANISHMENT = 116272,
    SPELL_SOUL_CUT_SUICIDE = 116278,
    SPELL_SOUL_CUT_DAMAGE = 117337,

    SPELL_TAP_THE_SPIRIT_WORLD = 117002, // Only cosmetic
    SPELL_CHANNEL_SPIRIT_TOTEM = 116833, // Only cosmetic
    SPELL_STRONG_MOJO = 115964, // Only cosmetic
    SPELL_VOODOO_DOLL_VISUAL = 122151,
    SPELL_VOODOO_DOLL_SHARE = 116000,
    SPELL_SUMMON_SPIRIT_TOTEM = 116174,
    SPELL_COSMETIC_SUMMON = 118086, // Only cosmetic - Tiki mask
    SPELL_SOUL_CUTTER_COSMETIC = 120677, // Only cosmetic - Tiki mask too
    SPELL_SUMMON_MINION = 118087,

    // attaques ombreuses
    SPELL_RIGHT_CROSS = 117215,
    SPELL_LEFT_HOOK = 117218,
    SPELL_HAMMER_FIST = 117219,
    SPELL_SWEEPING_KICK = 117222,

    SPELL_FRENESIE = 117752,

    // Shadowy Minion
    SPELL_SHADOW_BOLT = 122118,
    SPELL_SPIRITUAL_GRASP = 118421,

    // Misc
    SPELL_CLONE = 119051,
    SPELL_CLONE_VISUAL = 119053,
    SPELL_LIFE_FRAGILE_THREAD = 116227,
    SPELL_CROSSED_OVER = 116161, // Todo : virer le summon
    SPELL_ANIM_VISUAL = 121475,

    SPELL_FRAIL_SOUL = 117723, // Heroic
    SPELL_SOUL_EXPLOSION = 120639,
    SPELL_ROOT_FOR_EVER = 31366,

    // Death Event
    SPELL_RELEASE_SPIRIT = 118580, // Summon Gara'jal Ghost
    SPELL_SPIRIT_HOVER = 75333,
    SPELL_GHOST_VISUAL = 91218,
    SPELL_SPIRITUAL_PORTAL = 118581, // Summon Spiritual Portal
    SPELL_VISUAL_PORTAL = 118661, // Portal Visual

    // Enrage
    SPELL_FINAL_DESTINATION = 118469,
    SPELL_INSTANTLY_DEATH = 118443,

    SPELL_GARAJAL_BONUS = 132190
};

enum eEvents
{
    EVENT_SECONDARY_ATTACK = 1,
    EVENT_SUMMON_TOTEM = 2,
    EVENT_SUMMON_SHADOWY_MINION = 3,
    EVENT_VOODOO_DOLL = 4,
    EVENT_BANISHMENT = 5,

    // Shadowy Minion
    EVENT_SHADOW_BOLT = 6,
    EVENT_SPIRITUAL_GRASP = 7,
    EVENT_CHECK_PLAYER = 8,
    EVENT_CLONE_TAKEOFF = 9,


    // Gara'Jal Ghost
    EVENT_GROWTH = 10,
    EVENT_TALK_DEATH = 11,
    EVENT_SUMMON_PORTAL = 12,
    EVENT_DISAPPEAR = 13,

    // Enrage
    EVENT_FINAL_DESTINATION = 14,
    EVENT_SOUL_EXPLOSION = 15,
    EVENT_CHECK_POSITION = 16
};

enum GarajalTalk
{
    TALK_AGGRO = 0,
    TALK_SLAY = 1,
    TALK_FRENZY = 2
};

enum GarajalGhostTalk
{
    TALK_DEATH = 0
};

void AddSC_boss_garajal()
{
    
}
