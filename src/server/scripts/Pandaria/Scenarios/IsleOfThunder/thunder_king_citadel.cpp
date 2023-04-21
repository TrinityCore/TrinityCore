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

#include "thunder_king_citadel.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "LFGMgr.h"

enum Spells
{
    SPELL_LIGHTNING_ATTRACTOR = 137114,
    SPELL_LIGHTNING_SURGE = 139804,
    SPELL_STONE_SMASH = 139777,
    SPELL_LIMITED_TIME = 140000, // 5m
    SPELL_COMPLETE_SCENARIO_SCREEN_EFF = 140005,
    SPELL_SENTRY_BEAM = 139810,
    SPELL_SENTRY = 139808, // Areatrigger
    SPELL_SUMM_SENTRY_BEAM_BUNNY = 139807,
    SPELL_RUNE_TRAP = 139798,
    SPELL_SPOTTED = 138954,
    SPELL_SPEED = 132959,
    SPELL_RING_OF_FROST = 15063,
    SPELL_ARCANE_BOLT = 13748,
    SPELL_ARCANE_EXPLOSION = 51820,
    SPELL_THROVES_OF_THE_THUNDER_KING = 137275,
    SPELL_BATTLE_SHOUT = 32064,
    SPELL_MORTAL_STRIKE = 13737,
    SPELL_IMPALING_PULL = 82742,
    SPELL_MIGHTY_STOMP = 136855,
    SPELL_MIGHTY_CRASH = 136844,
    SPELL_ETERNAL_SLUMBER = 140011,
    SPELL_CRUSH_ARMOR = 127157,
    SPELL_LEAPING_RUSH = 131942,
};

enum Events
{
    EVENT_RING_OF_FROST,
    EVENT_ARCANE_BOLT,
    EVENT_ARCANE_EXPLOSION,
    EVENT_BATTLE_SHOUT,
    EVENT_MORTAL_STRIKE,
    EVENT_MIGHTY_STOMP,
    EVENT_MIGHTY_CRASH,
    EVENT_ETERNAL_SLUMBER,
    EVENT_CRUSH_ARMOR,
    EVENT_LEAPING_RUSH,
};

// Lightning Pillar Master 70409
struct npc_lightning_pillar_master : public ScriptedAI
{
    npc_lightning_pillar_master(Creature* creature) : ScriptedAI(creature) { }

    float x, y;
    TaskScheduler scheduler;

    void InitializeAI() override
    {
        scheduler
            .Schedule(Milliseconds(urand(500, 5000)), [this](TaskContext context)
                {
                    DoCast(me, SPELL_LIGHTNING_SURGE);
                    context.Repeat(Milliseconds(urand(6000, 10000)));
                });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }
};

void AddSC_thunder_king_citadel()
{
    
}