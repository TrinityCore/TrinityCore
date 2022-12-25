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

#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "ScriptedEscortAI.h"

#include "Creature.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "ScriptedGossip.h"
#include "Pet.h"
#include "PetAI.h"
#include "Log.h"

enum ZuldazarQuests
{
    QUEST_WELCOME_ZULDAZAR      = 46957,
    QUEST_RASTAKHAN             = 46930,
    QUEST_SPEAKER_OF_THE_HORDE  = 46931,
    OBJECTIVE_SUMMON_THE_HORDE  = 291969,
    QUEST_NEED_EACH_OTHER       = 52131,
    QUEST_SEND_THE_FLEET_HORDE = 56044,
    QUEST_RIDE_OF_THE_ZANDALARI = 54140,
};

enum ZuldazarSpells
{
    SPELL_TALANJI_EXPOSITION_CONVERSATION_1 = 261541,
    SPELL_TALANJI_EXPOSITION_CONVERSATION_2 = 261549,
    SPELL_TALANJI_EXPOSITION_KILL_CREDIT    = 265711,

    SPELL_RASTAKHAN_GREETINGS_SCENE         = 244534,

    SPELL_PREVIEW_TO_ZANDALAR               = 273387,
};

enum ZuldazarNpcs
{
    NPC_ZOLANI                      = 135441,
    NPC_FOLLOW_ZOLANI_KILL_CREDIT   = 120169,
};

void AddSC_zone_zuldazar()
{
    
}
