/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "nyalotha.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

const Position middle_pos = { -1487.0f, -580.0f, -518.4f, 4.71f };

enum Texts
{
    SAY_MINDQUAKE,    
    SAY_AGGRO = 2,
    SAY_SHRED_PSYCHE,
    SAY_ILLUSIONARY_PROJECTIONS,
};

enum Spells
{
    SPELL_SHADOW_SHOCK = 307977,
    SPELL_SHADOW_SHOCK_DEBUFF = 308059,
    SPELL_SHRED_PSYCHE_DUMMY = 307937,
    SPELL_SHRED_PSYCHE_AURA = 308065,
    SPELL_SHRED_PSYCHE_SUMMON = 309680,
    SPELL_ILLUSIONARY_PROJECTION_DUMMY = 307445,
    SPELL_ILLUSIONARY_PROJECTION_DISAPPEAR = 307725,
    SPELL_PROPHET_ILLUSION = 307713, //Apply Aura : Invisibility Detection(7)
    SPELL_CLOUDED_MIND = 307784,
    SPELL_TWISTED_MIND = 307785,
    SPELL_DARK_RITUAL = 309657,
    SPELL_MINDQUAKE = 307864,
    SPELL_RAGE_OF_THE_CORRUPTOR = 317669,
    //ADD
    NPC_SHREDDED_PSYCHE = 158781,
    SPELL_PSYCHIC_OUTBURST = 309687,
    SPELL_PSYCHIC_REVERBERATIONS = 312721,
    //Heroic    
    SPELL_INTANGIBLE_ILLUSION = 313208,
    SPELL_SURGING_IMAGES_CREATE_AT = 313210,
    SPELL_SURGING_IMAGES_AT_DAMAGE = 313215,
};

enum Events
{
    EVENT_SHADOW_SHOCK = 1,
    EVENT_SHRED_PSYCHE,
    EVENT_PSYCHIC_OUTBURST,
    EVENT_PSYCHIC_REVERBERATIONS,
    EVENT_MIND,
    EVENT_PROJECTIONS,
    EVENT_ABSOLUTIONS,
    EVENT_BERSERK,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO,
};

//157620
struct boss_prophet_skitra : public BossAI
{
    boss_prophet_skitra(Creature* creature) : BossAI(creature, DATA_SKITRA) { }

private:
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();        
        me->ClearUnitState(UNIT_STATE_ROOT);
        me->RemoveAura(SPELL_PROPHET_ILLUSION);
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_DEMONIC);
    }

    void EnterCombat(Unit* u) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        this->phase = 1;
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 3s);
        events.ScheduleEvent(EVENT_SHRED_PSYCHE, 15s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_ABSOLUTIONS, 30s);
        events.ScheduleEvent(EVENT_BERSERK, 8min);
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(81) && this->phase != 2 )
        {
            this->phase = 2;
            me->InterruptNonMeleeSpells(true, 0, true);
            Talk(SAY_ILLUSIONARY_PROJECTIONS);            
            me->SetReactState(REACT_PASSIVE);
            DoCast(SPELL_ILLUSIONARY_PROJECTION_DISAPPEAR);            
            me->GetScheduler().Schedule(5s, [this] (TaskContext context)
            {
                std::list<Player*> p_li;
                me->GetPlayerListInGrid(p_li, 150.0f);
                for (auto & players : p_li)
                me->AddAura(SPELL_DARK_RITUAL, players);

                if (this->phase == 2)
                    context.Repeat(5s);
            });
        }
        if (me->HealthBelowPct(75) && this->phase != 2)
        {
            this->phase = 1;
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->ClearUnitState(UNIT_STATE_CASTING);
            events.ScheduleEvent(EVENT_SHADOW_SHOCK, 3s);
            events.ScheduleEvent(EVENT_SHRED_PSYCHE, 15s);
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ILLUSIONARY_PROJECTION_DISAPPEAR)
        {
            me->StopMoving();
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetDisplayId(me->GetNativeDisplayId());
            events.Reset();
            events.ScheduleEvent(EVENT_MIND, 100ms);
            events.ScheduleEvent(EVENT_PROJECTIONS, 200ms);
            me->RemoveAllAttackers();
            me->NearTeleportTo(me->GetRandomPoint(middle_pos, 60.0f));
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        me->DespawnCreaturesInArea(NPC_SHREDDED_PSYCHE, 125.0f);
        me->DespawnCreaturesInArea(NPC_IMAGE_OF_ABSOLUTION, 125.0f);
        me->DespawnCreaturesInArea(NPC_PROPGET_SKITRA_PROJECTION, 125.0f);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOUDED_MIND);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWISTED_MIND);
        me->ClearUnitState(UNIT_STATE_ROOT);
        _DespawnAtEvade();
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_SHREDDED_PSYCHE, 125.0f);
        me->DespawnCreaturesInArea(NPC_IMAGE_OF_ABSOLUTION, 125.0f);
        me->DespawnCreaturesInArea(NPC_PROPGET_SKITRA_PROJECTION, 125.0f);
        instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 12);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SHADOW_SHOCK:
        {
             DoCastVictim(SPELL_SHADOW_SHOCK, false);
             events.Repeat(2s);
             break;
        }
        case EVENT_SHRED_PSYCHE:
        {
            Talk(SAY_SHRED_PSYCHE);
             UnitList tarlist;
             SelectTargetList(tarlist, 1, SELECT_TARGET_RANDOM, 500.0f);
             for (Unit* tar : tarlist)
             {
                 DoCast(SPELL_SHRED_PSYCHE_DUMMY);
                 DoCast(tar, SPELL_SHRED_PSYCHE_AURA);
                 tar->GetScheduler().Schedule(5s, [tar] (TaskContext context)
                 {
                    tar->CastSpell(nullptr, SPELL_SHRED_PSYCHE_SUMMON, true);
                 });      
             }
             events.Repeat(30s);  
        }
        break;

        case EVENT_MIND:
        {
            if (Is25ManRaid())
            {
                UnitList tarlist;
                SelectTargetList(tarlist, 13, SELECT_TARGET_RANDOM, 500.0f);
                for (Unit* tar : tarlist)
                {
                    DoCast(tar, SPELL_CLOUDED_MIND, true);
                }
                UnitList tarlist2;
                SelectTargetList(tarlist2, 12, SELECT_TARGET_RANDOM, 500.0f);
                for (Unit* tar : tarlist2)
                {
                    DoCast(tar, SPELL_TWISTED_MIND, true);
                }
            }
            else
            {
                UnitList tarlist;
                SelectTargetList(tarlist, 5, SELECT_TARGET_RANDOM, 500.0f);
                for (Unit* tar : tarlist)
                {
                    DoCast(tar, SPELL_CLOUDED_MIND, true);
                }
                UnitList tarlist2;
                SelectTargetList(tarlist2, 5, SELECT_TARGET_RANDOM, 500.0f);
                for (Unit* tar : tarlist2)
                {
                    DoCast(tar, SPELL_TWISTED_MIND, true);
                }
            }  
            break;
        }
        case EVENT_PROJECTIONS:
        {
            Talk(SAY_ILLUSIONARY_PROJECTIONS);
            for (uint8 i = 0; i < 5; ++i)
            {
                auto* projections = DoSummon(NPC_PROPGET_SKITRA_PROJECTION, me->GetRandomPoint(middle_pos, 60.0f), TEMPSUMMON_MANUAL_DESPAWN);               
            }
            me->AddUnitState(UNIT_STATE_CASTING);
        }
        case EVENT_BERSERK:
        {
            me->AddAura(SPELL_RAGE_OF_THE_CORRUPTOR);
            break;
        }
        case EVENT_ABSOLUTIONS:
        {
            std::list<Creature*> controllerList;
            me->GetCreatureListWithEntryInGrid(controllerList, 500526, 250.0f);
            for (auto& absolutions : controllerList)
            {
                me->SummonCreature(NPC_IMAGE_OF_ABSOLUTION, absolutions->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            }
            events.Repeat(45s);
            break;
        }
        }
    }
};

//158781
struct npc_shredded_psyche : public ScriptedAI
{
    npc_shredded_psyche(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetDisplayId(me->GetNativeDisplayId());
        me->AddAura(309681);
        DoCastAOE(SPELL_PSYCHIC_OUTBURST, false);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_PSYCHIC_OUTBURST)
            me->CastSpell(nullptr, SPELL_PSYCHIC_REVERBERATIONS, false);
    }
};

//157620
struct npc_prophet_skitra_projection : public ScriptedAI
{
    npc_prophet_skitra_projection(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        me->AddUnitState(UNIT_STATE_CASTING);
    }

    void JustDied(Unit* u) override
    {
        DoCastAOE(SPELL_MINDQUAKE, false);
    }
};

//160990
struct npc_image_of_absolution : public ScriptedAI
{
    npc_image_of_absolution(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));       
        me->SetReactState(REACT_PASSIVE);
        //me->AddAura(SPELL_INTANGIBLE_ILLUSION);
        me->CastSpell(nullptr, SPELL_SURGING_IMAGES_CREATE_AT, true);
        me->SetFacingTo(3.029f, true);
        me->SetWalk(true);
        if (auto* controller = me->FindNearestCreature(500527, 150.0f, true))
            me->GetMotionMaster()->MoveFollow(controller, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        me->DespawnOrUnsummon(10s);
    }
};

//20001, 313210
struct at_surging_images : public AreaTriggerAI
{
    at_surging_images(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();
        at->MovePosition(pos, 85.0f, 0.0f);

        if (Unit* target = caster->FindNearestCreature(NPC_SKITRA_ABSOLUTION_MOVEMENT_CONTROLLER, 150.0f, true))
            at->SetDestination(target->GetPosition(), 9000);

        at->SetDuration(10000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(SPELL_SURGING_IMAGES_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_SURGING_IMAGES_AT_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(SPELL_SURGING_IMAGES_AT_DAMAGE))
            unit->RemoveAura(SPELL_SURGING_IMAGES_AT_DAMAGE);
    }
};

void AddSC_prophet_skitra()
{
    RegisterCreatureAI(boss_prophet_skitra);
    RegisterCreatureAI(npc_shredded_psyche);
    RegisterCreatureAI(npc_prophet_skitra_projection);
    RegisterCreatureAI(npc_image_of_absolution);
    RegisterAreaTriggerAI(at_surging_images);
};
