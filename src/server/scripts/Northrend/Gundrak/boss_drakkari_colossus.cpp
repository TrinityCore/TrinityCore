/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Comment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make the boss enter in combat!
 */

#include "ScriptMgr.h"
#include "gundrak.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Texts
{
    // Drakkari Elemental
    EMOTE_MOJO                                    = 0,
    EMOTE_ACTIVATE_ALTAR                          = 1
};

enum Spells
{
    SPELL_EMERGE                                  = 54850,
    SPELL_ELEMENTAL_SPAWN_EFFECT                  = 54888,
    SPELL_MOJO_VOLLEY                             = 54849,
    SPELL_SURGE_VISUAL                            = 54827,
    SPELL_MERGE                                   = 54878,
    SPELL_MIGHTY_BLOW                             = 54719,
    SPELL_SURGE                                   = 54801,
    SPELL_FREEZE_ANIM                             = 16245,
    SPELL_MOJO_PUDDLE                             = 55627,
    SPELL_MOJO_WAVE                               = 55626,
    SPELL_MORTAL_STRIKES_NORMAL                   = 54715,
    SPELL_MORTAL_STRIKES_HEROIC                   = 59454
};

#define SPELL_MORTAL_STRIKES DUNGEON_MODE<uint32>(SPELL_MORTAL_STRIKES_NORMAL, SPELL_MORTAL_STRIKES_HEROIC)

enum ColossusEvents
{
    EVENT_MIGHTY_BLOW   = 1,
};

enum ColossusActions
{
    ACTION_SUMMON_ELEMENTAL     = 1,
    ACTION_FREEZE_COLOSSUS      = 2,
    ACTION_UNFREEZE_COLOSSUS    = 3,
};

enum ColossusPhases
{
    COLOSSUS_PHASE_NORMAL                   = 1,
    COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON   = 2,
    COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON  = 3
};

enum ColossusData
{
    DATA_COLOSSUS_PHASE = 1,
    DATA_INTRO_DONE     = 2
};

enum ElementalActions
{
    ACTION_RETURN_TO_COLOSSUS = 1
};

enum ElementalEvents
{
    EVENT_SURGE = 1
};

struct boss_drakkari_colossus : public BossAI
{
    boss_drakkari_colossus(Creature* creature) : BossAI(creature, DATA_DRAKKARI_COLOSSUS)
    {
        Initialize();
        me->SetReactState(REACT_PASSIVE);
        introDone = false;
    }

    void Initialize()
    {
        phase = COLOSSUS_PHASE_NORMAL;
    }

    void Reset() override
    {
        _Reset();

        if (GetData(DATA_INTRO_DONE))
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetImmuneToPC(false);
            me->RemoveAura(SPELL_FREEZE_ANIM);
        }

        events.ScheduleEvent(EVENT_MIGHTY_BLOW, 10s, 30s);

        Initialize();

        DoCastSelf(SPELL_MORTAL_STRIKES, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        me->RemoveAura(SPELL_FREEZE_ANIM);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SUMMON_ELEMENTAL:
                DoCast(SPELL_EMERGE);
                break;
            case ACTION_FREEZE_COLOSSUS:
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();

                me->SetReactState(REACT_PASSIVE);
                me->SetImmuneToPC(true);
                DoCast(me, SPELL_FREEZE_ANIM);
                break;
            case ACTION_UNFREEZE_COLOSSUS:

                if (me->GetReactState() == REACT_AGGRESSIVE)
                    return;

                me->SetImmuneToPC(false);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAura(SPELL_FREEZE_ANIM);

                DoZoneInCombat();

                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->IsImmuneToPC())
            damage = 0;

        if (phase == COLOSSUS_PHASE_NORMAL ||
            phase == COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON)
        {
            if (HealthBelowPct(phase == COLOSSUS_PHASE_NORMAL ? 50 : 5))
            {
                damage = 0;
                phase = (phase == COLOSSUS_PHASE_NORMAL ? COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON : COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON);
                DoAction(ACTION_FREEZE_COLOSSUS);
                DoAction(ACTION_SUMMON_ELEMENTAL);
            }
        }
    }

    uint32 GetData(uint32 data) const override
    {
       if (data == DATA_COLOSSUS_PHASE)
           return phase;
       else if (data == DATA_INTRO_DONE)
           return introDone;

       return 0;
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_INTRO_DONE)
            introDone = data != 0;
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
                case EVENT_MIGHTY_BLOW:
                    DoCastVictim(SPELL_MIGHTY_BLOW);
                    events.ScheduleEvent(EVENT_MIGHTY_BLOW, 5s, 15s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        DoZoneInCombat(summon);

        if (phase == COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON)
            summon->SetHealth(summon->GetMaxHealth() / 2);
    }

private:
    uint8 phase;
    bool introDone;
};

struct boss_drakkari_elemental : public ScriptedAI
{
    boss_drakkari_elemental(Creature* creature) : ScriptedAI(creature)
    {
        DoCast(me, SPELL_ELEMENTAL_SPAWN_EFFECT);
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_SURGE, 5s, 15s);

        me->AddAura(SPELL_MOJO_VOLLEY, me);
    }

    void JustDied(Unit* killer) override
    {
        Talk(EMOTE_ACTIVATE_ALTAR);

        if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            Unit::Kill(killer, colossus);
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
                case EVENT_SURGE:
                    DoCast(SPELL_SURGE_VISUAL);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                        DoCast(target, SPELL_SURGE);
                    events.ScheduleEvent(EVENT_SURGE, 5s, 15s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

   void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RETURN_TO_COLOSSUS:
                Talk(EMOTE_MOJO);
                DoCast(SPELL_SURGE_VISUAL);
                if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
                    // what if the elemental is more than 80 yards from drakkari colossus ?
                    DoCast(colossus, SPELL_MERGE, true);
                break;
        }
   }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (HealthBelowPct(50))
        {
            if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            {
                if (colossus->AI()->GetData(DATA_COLOSSUS_PHASE) == COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON)
                {
                    damage = 0;

                    // to prevent spell spaming
                    if (me->HasUnitState(UNIT_STATE_CHARGING))
                        return;

                    // not sure about this, the idea of this code is to prevent bug the elemental
                    // if it is not in a acceptable distance to cast the charge spell.
                    /*if (me->GetDistance(colossus) > 80.0f)
                    {
                        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            return;

                        me->GetMotionMaster()->MovePoint(0, colossus->GetPositionX(), colossus->GetPositionY(), colossus->GetPositionZ());
                        return;
                    }*/
                    DoAction(ACTION_RETURN_TO_COLOSSUS);
                }
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_MERGE)
        {
            if (Creature* colossus = target->ToCreature())
            {
                colossus->AI()->DoAction(ACTION_UNFREEZE_COLOSSUS);
                me->DespawnOrUnsummon();
            }
        }
    }

private:
    EventMap events;
    InstanceScript* instance;
};

struct npc_living_mojo : public ScriptedAI
{
    npc_living_mojo(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MOJO_WAVE);
            task.Repeat(15s);
        })
        .Schedule(7s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MOJO_PUDDLE);
            task.Repeat(18s);
        });
    }

    void MoveMojos(Creature* boss)
    {
        std::list<Creature*> mojosList;
        boss->GetCreatureListWithEntryInGrid(mojosList, me->GetEntry(), 12.0f);
        if (!mojosList.empty())
        {
            for (std::list<Creature*>::const_iterator itr = mojosList.begin(); itr != mojosList.end(); ++itr)
            {
                if (Creature* mojo = *itr)
                    mojo->GetMotionMaster()->MovePoint(1, boss->GetHomePosition().GetPositionX(), boss->GetHomePosition().GetPositionY(), boss->GetHomePosition().GetPositionZ());
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            {
                colossus->AI()->DoAction(ACTION_UNFREEZE_COLOSSUS);
                if (!colossus->AI()->GetData(DATA_INTRO_DONE))
                    colossus->AI()->SetData(DATA_INTRO_DONE, true);
                DoZoneInCombat(colossus);
                me->DespawnOrUnsummon();
            }
        }
    }

    void AttackStart(Unit* attacker) override
    {
        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
            return;

        // we do this checks to see if the creature is one of the creatures that sorround the boss
        if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
        {
            Position homePosition = me->GetHomePosition();

            float distance = homePosition.GetExactDist(&colossus->GetHomePosition());

            if (distance < 12.0f)
            {
                MoveMojos(colossus);
                me->SetReactState(REACT_PASSIVE);
            }
            else
                ScriptedAI::AttackStart(attacker);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    InstanceScript* instance;
    TaskScheduler _scheduler;
};

void AddSC_boss_drakkari_colossus()
{
    RegisterGundrakCreatureAI(boss_drakkari_colossus);
    RegisterGundrakCreatureAI(boss_drakkari_elemental);
    RegisterGundrakCreatureAI(npc_living_mojo);
}
