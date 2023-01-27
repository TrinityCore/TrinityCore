/*
* Copyright 2021 ShadowCore
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
#include "spires_of_ascension.h"

enum Oryphrion
{
    SPELL_CHARGED_STOMP = 324608,
    SPELL_CHARGED_ANIMA = 338729,
    SPELL_PURIFYING_BLAST_DUMMY = 334053,
    SPELL_PURIFYING_BLAST_DAMAGE = 323195,
    SPELL_PURIFYING_BLAST_MISSILE = 323072,
    SPELL_EMPYREAL_ORDNANCE_VISUAL = 323375,
    SPELL_EMPYREAL_ORDNANCE_CAST = 324427,
    SPELL_EMPYREAL_ORDNANCE_MARK = 321936,
    SPELL_EMPYREAL_ORDNANCE_MISSILE = 323313,
    SPELL_EMPYREAL_ORDNANCE_DAMAGE = 323372,
    SPELL_DRAINED = 323878,
    ACTION_RESTART_EVENTS,
    //Mythic
    SPELL_RECHARGE_ANIMA = 324046,
    SPELL_ANIMA_CHARGE_EXP = 323373,
    SPELL_ANIMA_CHARGE_PERIOIDC = 331997,
    //165807
    SPELL_ANIMA_FIELD_APPLY_AT = 323791,
    SPELL_ANIMA_FIELD_DAMAGE = 323792,
};

bool recharged;

//162060
struct boss_oryphrion : public BossAI
{
    boss_oryphrion(Creature* creature) : BossAI(creature, DATA_ORYPHRION) { }

private:
    uint8 ordnanceCounter;    

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(SPELL_CHARGED_STOMP, 5s);
        events.ScheduleEvent(SPELL_PURIFYING_BLAST_DUMMY, 10s);
        events.ScheduleEvent(SPELL_EMPYREAL_ORDNANCE_CAST, 15s);
        this->ordnanceCounter = 0;
        recharged = false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_RESTART_EVENTS:
            events.ScheduleEvent(SPELL_CHARGED_STOMP, 5s);
            events.ScheduleEvent(SPELL_PURIFYING_BLAST_DUMMY, 10s);
            events.ScheduleEvent(SPELL_EMPYREAL_ORDNANCE_CAST, 15s);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override 
    { 
        switch (spellInfo->Id)
        {
        case SPELL_CHARGED_STOMP:
            me->AddAura(SPELL_CHARGED_ANIMA, target);
            break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo)
    {
        switch (spellInfo->Id)
        {
        case SPELL_EMPYREAL_ORDNANCE_CAST:
            ordnanceCounter++;
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* targets : playerList)
            {
                me->AddAura(SPELL_EMPYREAL_ORDNANCE_MARK, targets);
                me->GetScheduler().Schedule(3100ms, [this, targets](TaskContext context)
                {
                    if (!targets)
                        return;

                    me->CastSpell(targets, SPELL_EMPYREAL_ORDNANCE_MISSILE, true);
                });
            }
            if (this->ordnanceCounter == 2)
            {
                this->ordnanceCounter = 0;
                events.Reset();
                me->CastSpell(nullptr, SPELL_DRAINED, true);
                std::list<Creature*> coalescedAnimaList;
                me->GetCreatureListWithEntryInGrid(coalescedAnimaList, NPC_COALESCED_ANIMA, 100.0f);
                for (Creature* animaOrbs : coalescedAnimaList) 
                {
                    animaOrbs->AddAura(SPELL_EMPYREAL_ORDNANCE_VISUAL);
                    animaOrbs->SetWalk(true);
                    animaOrbs->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                }
            }
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_CHARGED_STOMP:
            DoCastAOE(SPELL_CHARGED_STOMP, false);
            events.Repeat(15s, 18s);
            break;
        case SPELL_PURIFYING_BLAST_DUMMY:
            me->CastSpell(nullptr, SPELL_PURIFYING_BLAST_DUMMY, false);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target, true);
                me->GetScheduler().Schedule(2600ms, [this, target](TaskContext context)
                    {
                        if (!target)
                            return;

                        me->CastSpell(target, SPELL_PURIFYING_BLAST_MISSILE, true);
                    });
            }
            events.Repeat(20s, 23s);
            break;

        case SPELL_EMPYREAL_ORDNANCE_CAST:
            me->CastSpell(nullptr, SPELL_EMPYREAL_ORDNANCE_CAST, false);
            events.Repeat(26s, 29s);
            break;
        }
    }
};

//165807
struct npc_coalesced_anima : public ScriptedAI
{
    npc_coalesced_anima(Creature* c) : ScriptedAI(c) { }

private:
    bool soaked;

    void Reset() override
    {        
        me->SetDisplayId(16925, 1.0f);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
        me->AddAura(SPELL_ANIMA_FIELD_APPLY_AT);
    }

    void MoveInLineOfSight(Unit* target) override
    { 
        if (!target->IsPlayer())
            return;

        if (Creature* oryphrion = me->FindNearestCreature(NPC_ORYPHRION, 100.0f, true))
            if (oryphrion->HasAura(SPELL_DRAINED) && me->GetDistance2d(target) <= 5.0f)
                me->GetMotionMaster()->Clear();

        if (Creature* oryphrion = me->FindNearestCreature(NPC_ORYPHRION, 100.0f, true))
            if (oryphrion->HasAura(SPELL_DRAINED) && me->GetDistance2d(oryphrion) <= 5.0f && !recharged)
            { 
                recharged = true;
                oryphrion->RemoveAura(SPELL_DRAINED);
                oryphrion->AddAura(SPELL_RECHARGE_ANIMA);
                oryphrion->AI()->DoAction(ACTION_RESTART_EVENTS);
                me->DespawnOrUnsummon();
                std::list<Creature*> coalescedAnimaList;
                oryphrion->GetCreatureListWithEntryInGrid(coalescedAnimaList, NPC_COALESCED_ANIMA, 100.0f);
                for (Creature* animaOrbs : coalescedAnimaList)
                {                    
                    animaOrbs->GetMotionMaster()->Clear();
                    animaOrbs->RemoveAura(SPELL_EMPYREAL_ORDNANCE_VISUAL);
                }
            }

        if (Creature* oryphrion = me->FindNearestCreature(NPC_ORYPHRION, 100.0f, true))
            if (me->GetDistance2d(oryphrion) <= 5.0f)
                me->DespawnOrUnsummon();
    }
};

//23858
struct at_anima_field : public AreaTriggerAI
{
    at_anima_field(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_ANIMA_FIELD_DAMAGE))
            at->GetCaster()->AddAura(SPELL_ANIMA_FIELD_DAMAGE, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_ANIMA_FIELD_DAMAGE))
            target->RemoveAura(SPELL_ANIMA_FIELD_DAMAGE);
    }
};

void AddSC_boss_oryphrion()
{
    RegisterCreatureAI(boss_oryphrion);
    RegisterCreatureAI(npc_coalesced_anima);
    RegisterAreaTriggerAI(at_anima_field);
}