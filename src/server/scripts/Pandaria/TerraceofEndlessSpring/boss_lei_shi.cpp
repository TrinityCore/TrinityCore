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
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "terrace_of_endless_spring.h"
#include "GridNotifiers.h"
#include "Group.h"

static const Position aLeiWps[] =
{
    { -1017.7f, -2864.0f, 30.4f, 4.71f },
    { -1017.8f, -2771.9f, 38.6f, 4.71f },
};

enum eLeiShiSpells
{
    SPELL_AFRAID = 123181,
    SPELL_SPRAY = 123121,
    SPELL_HIDE = 123244,
    SPELL_HIDE_SUMMON = 123213,
    SPELL_HIDE_STACKS = 123233,
    SPELL_GET_AWAY = 123461,
    SPELL_GET_AWAY_TELEPORT = 123441,
    SPELL_PROTECT = 123250,
    SPELL_PROTECT_RESPAWN = 123493,
    SPELL_PROTECT_VISUAL = 123505,
    SPELL_CLOUDED_REFLECTION = 123620,
    SPELL_CLOUDED_IMPACT = 123625,

    // This is for Heroic Mode
    SPELL_SCARY_FOG_CIRCLE = 123797,
    SPELL_SCARY_FOG_DOT = 123705,
    SPELL_SCARY_FOG_STACKS = 123712,

    SPELL_LEI_SHI_TRANSFORM = 127535,
    SPELL_LEI_SHI_ACHIEVEMENT_MARKER = 123903,
};

enum eLeiShiEvents
{
    // Lei Shi
    EVENT_SPECIAL = 1,
    EVENT_SPRAY = 2,
    EVENT_GET_AWAY = 3,
    EVENT_GET_AWAY_CAST = 4,
    EVENT_PROTECT = 5,
    EVENT_HIDE = 6,

    // Lei Shi (hidden)
    EVENT_HIDDEN_SPRAY = 7,
    EVENT_BERSERK = 8,

    // OOC
    EVENT_WP_1 = 9,
    EVENT_WP_2 = 10,
    EVENT_WP_3 = 11,

    EVENT_HIDE_NEW,
    EVENT_HIDE_REVEAL,
    EVENT_PROTECT_FINAL,
};

enum eLeiShiActions
{
    ACTION_ANIMATED_PROTECTOR_DIED,
    ACTION_ACTIVATE_ANIMATED_PROTECTORS,
    ACTION_TERMINATE_GET_AWAY_PHASE,
    ACTION_TERMINATE_HIDE_PHASE,
};

enum eLeiShiSays
{
    TALK_AGGRO = 1,
    TALK_HIDE,
    TALK_GET_AWAY,
    TALK_SLAY,
    TALK_INTRO,
    TALK_DEFEATED,
    TALK_OUTRO_1,
    TALK_OUTRO_2
};

enum eReflectionSays
{
    EMOTE_RIPPLE,
    EMOTE_RIPPLE_2,
    EMOTE_APPEAR
};

Position leiShiPos = { -1017.93f, -2911.3f, 19.902f, 4.74f };

Position hidePositions[4] =
{
    { -990.678f,  -2890.043f, 19.172f, 3.781f },
    { -994.835f,  -2933.835f, 19.172f, 2.377f },
    { -1041.316f, -2932.84f,  19.172f, 0.733f },
    { -1045.101f, -2890.742f, 19.172f, 5.646f }
};

#define HEROIC_DIST_TO_VORTEX 21.0f
#define DIST_TO_SCARY_FOG_DOT 4.5f

void AddSC_boss_lei_shi()
{
    
}
