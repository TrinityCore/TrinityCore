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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "Map.h"
#include "necrotic_wake.h"
#include "npc_Bastion"
#include "objects_Bastion"

enum Spells
{
	//Surgeon Stitchflesh
	
	//Stitchflesh's Creation
    SPELL_MEAT_HOOK  = 320208,322548,322681,
    SPELL_AWAKEN_CREATION = 320358,
    SPELL_Festering Rot = 348170,
    SPELL_Lethargy = 326868,
    SPELL_Meerahs_Jukebox  = 288865,
    SPELL_Mutilate         = 320376,
    SPELL_Shattered Psyche = 344663,
};

enum Creatures
{
	NPC_Stitchfleshs_Creation;
	NPC_Surgeon_Stitchflesh;
	NPC_
}

//162691
struct boss_boss_surgeon_stitchflesh : public BossAI
{
    boss_surgeon_stitchflesh(Creature* creature) : BossAI(creature, DATA_SURGEON_STITCHFLESH) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(0);
        if (auto* encounterDoor = me->FindNearestGameObject(GO_SURGEON_STITCHFLESH_EXIT, 100.0f))
            encounterDoor->SetGoState(GO_STATE_READY);
        events.ScheduleEvent(SPELL_CRUNCH, 3s);
        events.ScheduleEvent(SPELL_HEAVING_RETCH, 5s);
        events.ScheduleEvent(SPELL_FETID_GAS_CREATE_AT, 10s);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override 
    { 
        switch (spellInfo->Id)
        {
        case SPELL_HEAVING_RETCH:
            me->AddAura(SPELL_HEAVING_RETCH, target);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_CRUNCH:
            DoCastVictim(SPELL_CRUNCH, false);
            events.Repeat(15s);
            break;
        case SPELL_HEAVING_RETCH:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_HEAVING_RETCH), false;
                AddTimedDelayedOperation(2600, [this, target]() -> void
                {
                    for (uint8 i = 0; i < 3; i++)
                    {
                        me->CastSpell(target, SPELL_HEAVING_RETCH_MISSILE, true);
                    }
                });
            }
            events.Repeat(20s);
            break;
        case SPELL_FETID_GAS_CREATE_AT:
            me->CastSpell(nullptr, SPELL_FETID_GAS_CREATE_AT, false);
            events.Repeat(18s);
            break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(1);
        me->RemoveAllAreaTriggers();
        if (auto* encounterDoor = me->FindNearestGameObject(GO_SURGEON_STITCHFLESH_EXIT, 100.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);
    }
};

//23443
struct at_boss_surgeon_stitchfleshAI : public AreaTriggerAI
{
    at_fetid_gas(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_FETID_GAS_AURA))
            at->GetCaster()->AddAura(SPELL_FETID_GAS_AURA, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (target->HasAura(SPELL_FETID_GAS_AURA))
            target->RemoveAura(SPELL_FETID_GAS_AURA);
    }
};

//164702
struct npc_boss_surgeon_stitchflesh : public ScriptedAI
{
    npc_carrion_worm_nw(Creature* creature) : ScriptedAI(c) { }
    
    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(SPELL_BLOOD_GORGE, 3s);
    }

    void ExecuteEvent(uint32 eventId)// override
    {
        if (Aura const* gorge = me->GetAura(SPELL_BLOOD_GORGE_BUFF))
            if (gorge->GetStackAmount() == 3)
            {
                me->RemoveAurasDueToSpell(SPELL_BLOOD_GORGE_BUFF);
                me->CastSpell(nullptr, SPELL_CARRION_ERUPTION, false);
            }

        switch (eventId)
        {
        case SPELL_BLOOD_GORGE:
            DoCastVictim(SPELL_BLOOD_GORGE, false);
            me->AddAura(SPELL_BLOOD_GORGE_BUFF, me);
            _events.Repeat(10s);
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {
        if (IsMythic())
            me->CastSpell(nullptr, SPELL_FETID_GAS_CREATE_AT, true);
    }

private:
    EventMap _events;
};

void boss_surgeon_stitchflesh()
{
    RegisterCreatureAI(boss_surgeon_stitchflesh);
    RegisterAreaTriggerAI(at_boss_surgeon_stitchfleshAI);
    RegisterCreatureAI(npc_boss_surgeon_stitchfleshAI);
}
