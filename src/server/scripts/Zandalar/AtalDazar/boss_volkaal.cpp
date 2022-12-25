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

#include "Creature.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "atal_dazar.h"

enum spell
{
    //Totems
    SPELL_REANIMATION_TOTEM_HEAL                = 259531,
    SPELL_BAD_VODOO                             = 250192, //Npc heals if totmes are alive, Each totem is supposed to add 1 stack of this to the boss
    //Toxic Leap
    SPELL_TOXIC_LEAP_DUMMY                      = 250708, //Targes
    SPELL_TOXIC_LEAP                            = 250258, //Jumps to the position of the player (phase 1)
    SPELL_TOXIC_LEAP_LANDING                    = 250259, //Cast after landing

    SPELL_NOXIOUS_STENCH                        = 259572, //Chanelled and adds a debuff to the whole party
    SPELL_NOXIOUS_STENCH_DMG                    = 250368,
    SPELL_LINGERING_NAUSEA                      = 250372, //aura added
    //Rapid Decay
    SPELL_RAPID_DECAY_BOSS_AURA                 = 250241, //Added to the boss after the totems get destroyed
    SPELL_RAPID_DECAY_AREATRIGGER               = 250696, //also creates an areatrigger
    SPELL_RAPID_DECAY_AREATRIGGER_MISSLE        = 250697, //creates an areatrigger random
    SPELL_RAPID_DECAY_AREATRIGGER_MISSLE2       = 250694, // creates an areatrigger at target

    SPELL_CREATE_TOXI_POOL_AREATRIGGER          = 263922, //Creates the areatrigger for the toxic pool

    SPELL_TOXIC_POOLS_AURA                      = 263927  //Gets applied while you're standing in a toxic pool

    // sniffs uses 259114? 250694, 250697,
    // areatrigger used from spell 250696
    // 250696 11243
};

enum Actions
{
    ACTION_TOTEM_DIED = 0,
    ACTION_TOTEM_HEALED,
};

enum NPCs
{
    NPC_REANIMATION_TOTEM = 125977
};

enum Events : uint32
{
    EVENT_REANIMATION_TOTEM_HEAL = 0,
    EVENT_BAD_VODOO,
    EVENT_TOXIC_LEAP,
    EVENT_NOXIOUS_STENCH,
    EVENT_RAPID_DECAY,
    EVENT_TOXIC_POOLS_AURA,
    EVENT_JUMP_DAMAGE,
    EVENT_TOXIC_POOL,
    EVENT_CLOSE_DOOR,
};

enum Talks
{
    TALK_AGGRO = 0,
    TALK_PHASE_TWO,
    TALK_DEATH,
};

enum Areatriggers
{
    AREATRIGGER_TOXIC_POOL = 16029,
};

Position totemSpawns[] =
{
    { -636.18f, 2316.12f, 709.963f },
    { -591.24f, 2292.44f, 709.968f },
    { -636.028f, 2269.22f, 709.974f }
};

void OpenBossGate(InstanceScript* instance)
{
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_005)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_006)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_007)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_008)))
        go->SetGoState(GO_STATE_ACTIVE);
};
void CloseBossGate(InstanceScript* instance)
{
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_005)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_006)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_007)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_008)))
        go->SetGoState(GO_STATE_READY);
};

void AddSC_boss_volkaal()
{
    
}
