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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "ScriptMgr.h"
#include "halls_of_valor.h"

enum hyrjaSpells
{
    SPELL_MYSTIC_EMPOWEREMENT_THUNDER_VISUAL    = 192008,
    SPELL_MYSTIC_EMPOWEREMENT_THUNDER           = 192132,
    SPELL_MYSTIC_EMPOWEREMENT_HOLY_VISUAL       = 191924,
    SPELL_MYSTIC_EMPOWEREMENT_HOLY              = 192133,
};

enum hyrjaEvents
{
    EVENT_MYSTIC_EMPOWEREMENT,
    EVENT_CHOOSE_SPECIAL,
};

enum olmyrSpells
{
    SPELL_SANCTIFY                  = 192307,
    SPELL_SANCTIFY_DAMAGE           = 192206,
    SPELL_SANCTIFY_AREATRIGGER      = 192163,
    SPELL_SEARING_LIGHT             = 192288,
    SPELL_OLMYR_SPAWN_COSMETIC      = 191899,
    SPELL_SHIELD_OF_LIGHT           = 192018,
    SPELL_EXPEL_LIGHT               = 192048,
    SPELL_EXPEL_LIGHT_EXPLODE       = 192067,
    SPELL_EYE_OF_THE_STORM          = 200901,
    SPELL_EYE_OF_THE_STORM_2        = 200902,
    SPELL_EYE_OF_THE_STORM_ACTIVE   = 200906,
    SPELL_EYE_OF_THE_STORM_DMG      = 200682,
    SPELL_SOLSTEN_SPAWN_COSMETIC    = 192147,
    SPELL_ARCING_BOLT               = 191976,
    SPELL_EYE_OF_THE_STORM_ABSORB   = 203963,
};

enum olmyrEvents
{
    EVENT_SANCTIFY,
    EVENT_SEARING_LIGHT,
    EVENT_SHIELD_OF_LIGHT,
    EVENT_EYE_OF_THE_STORM,
    EVENT_ARCING_BOLT,
    EVENT_STORM,
};

enum hyrjaSays
{
    SAY_COMBAT      = 0,
    SAY_KILLED      = 1,
    SAY_SANCTIFY    = 2,
    SAY_STORM       = 3,
    SAY_DIED        = 4,
};

struct boss_hyrja : public BossAI
{
    boss_hyrja(Creature* creature) : BossAI(creature, DATA_HYRJA)
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->SetCanFly(false);

        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    std::list<Creature*> creatureList;
    bool inCombat = false;
    uint8 count;

    void Reset() override
    {
        _Reset();
        count = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        me->GetMotionMaster()->MoveJump(3148.366f, 325.743f, 655.16f, 0.80f, 15.0f, 15.0f);

        events.ScheduleEvent(EVENT_MYSTIC_EMPOWEREMENT, 5 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_CHOOSE_SPECIAL, 10 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_SHIELD_OF_LIGHT, 16 * IN_MILLISECONDS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (GameObject* go = instance->GetGameObject(GOB_DOOR_ODYN_PASSAGE))
        {
            go->SetLootState(GO_READY);
            go->UseDoorOrButton(3000000, false);
            go->setActive(true);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_CAN_JOIN_COMBAT)
            CanJoinCombat();
    }

    void CanJoinCombat()
    {
        if (inCombat)
            return;

        uint8 count1 = 0;

        if (instance->GetCreature(NPC_OLMYR_GHOST))
            count1++;
        else if (Creature* olmyr = instance->GetCreature(NPC_OLMYR_THE_ENLIGHTENED))
        {
            if (Creature* olmyrghost = me->SummonCreature(NPC_OLMYR_GHOST, olmyr->GetPositionX(), olmyr->GetPositionY(), olmyr->GetPositionZ(), olmyr->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                olmyrghost->CastSpell(olmyrghost, SPELL_OLMYR_SPAWN_COSMETIC, true);

            count1++;
        }

        if (instance->GetCreature(NPC_SOLSTEN_GHOST))
            count1++;
        else if (Creature* solsten = instance->GetCreature(NPC_SOLSTEN))
        {
            if (Creature* solstenghost = me->SummonCreature(NPC_SOLSTEN_GHOST, solsten->GetPositionX(), solsten->GetPositionY(), solsten->GetPositionZ(), solsten->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                solstenghost->CastSpell(solstenghost, SPELL_SOLSTEN_SPAWN_COSMETIC, true);

            count1++;
        }

        if (count1 >= 2)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            inCombat = true;
            EnterCombat(me);
        }
    }

    void ChooseSpecial()
    {
        uint32 spellId = 0;

        switch (urand(1, 4))
        {
            case 1:
                Talk(SAY_STORM);
                me->CastSpell(me, SPELL_EYE_OF_THE_STORM_2, true);
                events.ScheduleEvent(EVENT_STORM, 1 * IN_MILLISECONDS);
                count = 0;
                spellId = SPELL_EYE_OF_THE_STORM;
                break;
            case 2:
                spellId = SPELL_ARCING_BOLT;
                break;
            case 3:
                Talk(SAY_SANCTIFY);
                spellId = SPELL_SANCTIFY;
                break;
            case 4:
                spellId = SPELL_EXPEL_LIGHT;
                break;
        }

        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true, 0))
            me->CastSpell(target, spellId, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHOOSE_SPECIAL:
                    ChooseSpecial();

                    if (me->HasAura(SPELL_MYSTIC_EMPOWEREMENT_HOLY) || me->HasAura(SPELL_MYSTIC_EMPOWEREMENT_THUNDER))
                        events.ScheduleEvent(EVENT_MYSTIC_EMPOWEREMENT, 4 * IN_MILLISECONDS);
                    else
                        events.ScheduleEvent(EVENT_MYSTIC_EMPOWEREMENT, 30 * IN_MILLISECONDS);

                    events.ScheduleEvent(EVENT_CHOOSE_SPECIAL, 20 * IN_MILLISECONDS);
                    break;

                case EVENT_SHIELD_OF_LIGHT:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_SHIELD_OF_LIGHT, true);

                    events.ScheduleEvent(EVENT_SHIELD_OF_LIGHT, 16 * IN_MILLISECONDS);
                    break;

                case EVENT_STORM:
                    me->CastSpell(me, SPELL_EYE_OF_THE_STORM_DMG, true);

                    ++count;

                    if (count <= 8)
                        events.ScheduleEvent(EVENT_STORM, 1 * IN_MILLISECONDS);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_olmyr_the_enlightened : public BossAI
{
    npc_olmyr_the_enlightened(Creature* creature) : BossAI(creature, DATA_OLMYR)
    {
        me->SetDisableGravity(false);
        me->SetCanFly(false);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_SANCTIFY, 3 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_SEARING_LIGHT, 8 * IN_MILLISECONDS);
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();

        if (Creature* creature = me->SummonCreature(NPC_OLMYR_GHOST, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN))
            creature->CastSpell(creature, SPELL_OLMYR_SPAWN_COSMETIC, true);

        if (Creature* hyrja = instance->GetCreature(BOSS_HYRJA))
        {
            hyrja->AI()->DoAction(ACTION_CAN_JOIN_COMBAT);
            hyrja->SetTarget(killer->GetGUID());
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SANCTIFY:
                    me->CastSpell(me, SPELL_SANCTIFY, true);
                    events.ScheduleEvent(EVENT_SANCTIFY, 12 * IN_MILLISECONDS);
                    break;
                case EVENT_SEARING_LIGHT:
                    me->CastSpell(me, SPELL_SEARING_LIGHT, true);
                    events.ScheduleEvent(EVENT_SEARING_LIGHT, 21 * IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_olmyr_ghost : public ScriptedAI
{
    npc_olmyr_ghost(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisableGravity(false);
        me->SetCanFly(false);
    }

    enum Events
    {
        EVENT_MYSTIC_EMPOWERMENT,
    };

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_MYSTIC_EMPOWERMENT, 1 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MYSTIC_EMPOWERMENT:
                if (Creature* hyrja = instance->GetCreature(BOSS_HYRJA))
                {
                    if (hyrja && me->GetDistance2d(hyrja->GetPositionX(), hyrja->GetPositionY()) < 5.0f)
                        me->CastSpell(hyrja, SPELL_MYSTIC_EMPOWEREMENT_HOLY, true);
                    else if (hyrja && me->GetDistance2d(hyrja->GetPositionX(), hyrja->GetPositionY()) < 20.0f)
                    {
                        me->CastSpell(hyrja, SPELL_MYSTIC_EMPOWEREMENT_HOLY_VISUAL, true);

                        /*if (hyrja->HasAura(SPELL_MYSTIC_EMPOWEREMENT_HOLY))
                        hyrja->RemoveAurasDueToSpell(SPELL_MYSTIC_EMPOWEREMENT_HOLY);*/
                    }
                    /*else if (hyrja->HasAura(SPELL_MYSTIC_EMPOWEREMENT_HOLY_VISUAL))
                    hyrja->RemoveAurasDueToSpell(SPELL_MYSTIC_EMPOWEREMENT_HOLY_VISUAL);*/
                }

                events.ScheduleEvent(EVENT_MYSTIC_EMPOWERMENT, 5 * IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }
    }
};

struct npc_solsten : public BossAI
{
    npc_solsten(Creature* creature) : BossAI(creature, DATA_SOLSTEN)
    {
        me->SetDisableGravity(false);
        me->SetCanFly(false);
    }

    uint8 count;

    void Reset() override
    {
        _Reset();

        count = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_EYE_OF_THE_STORM, 5 * IN_MILLISECONDS);
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();

        if (Creature* creature = me->SummonCreature(NPC_SOLSTEN_GHOST, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN))
            creature->CastSpell(creature, SPELL_SOLSTEN_SPAWN_COSMETIC, true);

        if (Creature* hyrja = instance->GetCreature(BOSS_HYRJA))
        {
            hyrja->AI()->DoAction(ACTION_CAN_JOIN_COMBAT);
            hyrja->SetTarget(killer->GetGUID());
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STORM:
                    me->CastSpell(me, SPELL_EYE_OF_THE_STORM_DMG, true);

                    ++count;

                    if (count <= 8)
                        events.ScheduleEvent(EVENT_STORM, 1 * IN_MILLISECONDS);
                    break;

                case EVENT_EYE_OF_THE_STORM:
                    if (Unit* target = me->GetVictim())
                    {
                        me->CastSpell(target, SPELL_EYE_OF_THE_STORM, true);
                        me->CastSpell(me, SPELL_EYE_OF_THE_STORM_2, true);
                        events.ScheduleEvent(EVENT_STORM, 1 * IN_MILLISECONDS);
                    }

                    events.ScheduleEvent(EVENT_EYE_OF_THE_STORM, 30 * IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_solsten_ghost : public ScriptedAI
{
    npc_solsten_ghost(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisableGravity(false);
        me->SetCanFly(false);
    }

    enum Events
    {
        EVENT_MYSTIC_EMPOWERMENT,
    };

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_MYSTIC_EMPOWERMENT, 1 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MYSTIC_EMPOWERMENT:
                if (Creature* hyrja = instance->GetCreature(BOSS_HYRJA))
                {
                    if (hyrja && me->GetDistance2d(hyrja->GetPositionX(), hyrja->GetPositionY()) < 5.0f)
                        me->CastSpell(hyrja, SPELL_MYSTIC_EMPOWEREMENT_THUNDER, true);

                    else if (hyrja && me->GetDistance2d(hyrja->GetPositionX(), hyrja->GetPositionY()) < 20.0f)
                    {
                        me->CastSpell(hyrja, SPELL_MYSTIC_EMPOWEREMENT_THUNDER_VISUAL, true);

                        /*if (hyrja->HasAura(SPELL_MYSTIC_EMPOWEREMENT_THUNDER))
                        hyrja->RemoveAurasDueToSpell(SPELL_MYSTIC_EMPOWEREMENT_THUNDER);*/
                    }
                    /*else if (hyrja->HasAura(SPELL_MYSTIC_EMPOWEREMENT_THUNDER_VISUAL))
                    hyrja->RemoveAurasDueToSpell(SPELL_MYSTIC_EMPOWEREMENT_THUNDER_VISUAL);*/
                }

                events.ScheduleEvent(EVENT_MYSTIC_EMPOWERMENT, 5 * IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }
    }
};

// 10675
struct at_center_eye_of_the_storm : AreaTriggerAI
{
    at_center_eye_of_the_storm(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->HasAura(SPELL_EYE_OF_THE_STORM_ABSORB))
            target->CastSpell(target, SPELL_EYE_OF_THE_STORM_ABSORB, true);
    }

    void OnUnitExit(Unit* target) override
    {
        target->RemoveAurasDueToSpell(SPELL_EYE_OF_THE_STORM_ABSORB);
    }
};

// 10374
struct at_eye_of_the_storm : AreaTriggerAI
{
    at_eye_of_the_storm(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->HasAura(SPELL_EYE_OF_THE_STORM_ACTIVE))
            target->CastSpell(target, SPELL_EYE_OF_THE_STORM_ACTIVE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        target->RemoveAurasDueToSpell(SPELL_EYE_OF_THE_STORM_ACTIVE);
    }
};

struct at_sanctify : AreaTriggerAI
{
    at_sanctify(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(2000);
    }

    void OnUnitEnter(Unit* target) override
    {
        target->CastSpell(target, SPELL_SANCTIFY_DAMAGE, true);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
            for (ObjectGuid guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*at, guid))
                    if (caster->IsValidAttackTarget(unit))
                        caster->CastSpell(unit, SPELL_SANCTIFY_DAMAGE, true);
    }
};

// 192048 - Expel Light
class spell_expel_light : public AuraScript
{
    PrepareAuraScript(spell_expel_light);

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_EXPEL_LIGHT_EXPLODE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_expel_light::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 192307
class spell_sanctify : public AuraScript
{
    PrepareAuraScript(spell_sanctify);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Position pos = GetTarget()->GetRandomPoint(GetTarget()->GetPosition(), 30.0f);
        GetTarget()->CastSpell(pos, SPELL_SANCTIFY_AREATRIGGER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sanctify::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_hyrja()
{
    RegisterCreatureAI(boss_hyrja);
    RegisterCreatureAI(npc_olmyr_the_enlightened);
    RegisterCreatureAI(npc_solsten);
    RegisterAreaTriggerAI(at_center_eye_of_the_storm);
    RegisterAreaTriggerAI(at_eye_of_the_storm);
    RegisterAreaTriggerAI(at_sanctify);
    RegisterAuraScript(spell_expel_light);
    RegisterAuraScript(spell_sanctify);
    RegisterCreatureAI(npc_olmyr_ghost);
    RegisterCreatureAI(npc_solsten_ghost);
}
