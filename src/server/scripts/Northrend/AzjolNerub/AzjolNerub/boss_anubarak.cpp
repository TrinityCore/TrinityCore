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

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "azjol_nerub.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_EMERGE                = 53500,
    SPELL_SUBMERGE              = 53421,
    SPELL_IMPALE_AURA           = 53456,
    SPELL_IMPALE_VISUAL         = 53455,
    SPELL_IMPALE_DAMAGE         = 53454,
    SPELL_LEECHING_SWARM        = 53467,
    SPELL_POUND                 = 59433,
    SPELL_POUND_DAMAGE          = 59432,
    SPELL_CARRION_BEETLES       = 53520,
    SPELL_CARRION_BEETLE        = 53521,

    SPELL_SUMMON_DARTER         = 53599,
    SPELL_SUMMON_ASSASSIN       = 53609,
    SPELL_SUMMON_GUARDIAN       = 53614,
    SPELL_SUMMON_VENOMANCER     = 53615,

    SPELL_DART                  = 59349,
    SPELL_BACKSTAB              = 52540,
    SPELL_ASSASSIN_VISUAL       = 53611,
    SPELL_SUNDER_ARMOR          = 53618,
    SPELL_POISON_BOLT           = 53617
};

enum Creatures
{
    NPC_WORLD_TRIGGER           = 22515,
};

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SLAY        = 1,
    SAY_DEATH       = 2,
    SAY_LOCUST      = 3,
    SAY_SUBMERGE    = 4,
    SAY_INTRO       = 5
};

enum Events
{
    EVENT_POUND = 1,
    EVENT_IMPALE,
    EVENT_LEECHING_SWARM,
    EVENT_CARRION_BEETLES,
    EVENT_SUBMERGE, // use event for this so we don't submerge mid-cast
    EVENT_DARTER,
    EVENT_ASSASSIN,
    EVENT_GUARDIAN,
    EVENT_VENOMANCER,
    EVENT_CLOSE_DOOR
};

enum Actions
{
    ACTION_PET_DIED = 1,
    ACTION_PET_EVADE
};

enum Misc
{
    ACHIEV_GOTTA_GO_START_EVENT = 20381,
};

enum Phases
{
    PHASE_EMERGE = 1,
    PHASE_SUBMERGE
};

enum GUIDTypes
{
    GUID_TYPE_PET = 0,
    GUID_TYPE_IMPALE
};

enum SummonGroups
{
    SUMMON_GROUP_WORLD_TRIGGER_GUARDIAN = 1
};

struct boss_anub_arak : public BossAI
{
    boss_anub_arak(Creature* creature) : BossAI(creature, DATA_ANUBARAK), _nextSubmerge(0), _petCount(0), _assassinCount(0), _guardianCount(0), _venomancerCount(0) { }

    void Reset() override
    {
        BossAI::Reset();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOTTA_GO_START_EVENT);
        _nextSubmerge = 75;
        _petCount = 0;
    }

    bool CanAIAttack(Unit const* /*who*/) const override { return true; } // do not check boundary here

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        if (GameObject* door = instance->GetGameObject(DATA_ANUBARAK_WALL))
            door->SetGoState(GO_STATE_ACTIVE); // open door for now
        if (GameObject* door2 = instance->GetGameObject(DATA_ANUBARAK_WALL_2))
            door2->SetGoState(GO_STATE_ACTIVE);

        Talk(SAY_AGGRO);
        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOTTA_GO_START_EVENT);

        events.SetPhase(PHASE_EMERGE);
        events.ScheduleEvent(EVENT_CLOSE_DOOR, 5s);
        events.ScheduleEvent(EVENT_POUND, 2s, 4s, 0, PHASE_EMERGE);
        events.ScheduleEvent(EVENT_LEECHING_SWARM, 5s, 7s, 0, PHASE_EMERGE);
        events.ScheduleEvent(EVENT_CARRION_BEETLES, 14s, 17s, 0, PHASE_EMERGE);

        // set up world triggers
        std::list<TempSummon*> summoned;
        me->SummonCreatureGroup(SUMMON_GROUP_WORLD_TRIGGER_GUARDIAN, &summoned);
        if (summoned.empty()) // something went wrong
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            return;
        }
        _guardianTrigger = (*summoned.begin())->GetGUID();

        if (Creature* trigger = DoSummon(NPC_WORLD_TRIGGER, me->GetPosition(), 0s, TEMPSUMMON_MANUAL_DESPAWN))
            _assassinTrigger = trigger->GetGUID();
        else
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            return;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
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
                case EVENT_CLOSE_DOOR:
                    if (GameObject* door = instance->GetGameObject(DATA_ANUBARAK_WALL))
                        door->SetGoState(GO_STATE_READY);
                    if (GameObject* door2 = instance->GetGameObject(DATA_ANUBARAK_WALL_2))
                        door2->SetGoState(GO_STATE_READY);
                    break;
                case EVENT_POUND:
                    DoCastVictim(SPELL_POUND);
                    events.Repeat(26s, 32s);
                    break;
                case EVENT_LEECHING_SWARM:
                    Talk(SAY_LOCUST);
                    DoCastAOE(SPELL_LEECHING_SWARM);
                    events.Repeat(25s, 28s);
                    break;
                case EVENT_CARRION_BEETLES:
                    DoCastAOE(SPELL_CARRION_BEETLES);
                    events.Repeat(24s, 27s);
                    break;
                case EVENT_IMPALE:
                    if (Creature* impaleTarget = ObjectAccessor::GetCreature(*me, _impaleTarget))
                        DoCast(impaleTarget, SPELL_IMPALE_DAMAGE, true);
                    break;
                case EVENT_SUBMERGE:
                    Talk(SAY_SUBMERGE);
                    DoCastSelf(SPELL_SUBMERGE);
                    break;
                case EVENT_DARTER:
                {
                    std::list<Creature*> triggers;
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_WORLD_TRIGGER);
                    if (!triggers.empty())
                    {
                        Creature* trigger = Trinity::Containers::SelectRandomContainerElement(triggers);
                        trigger->CastSpell(trigger, SPELL_SUMMON_DARTER, true);

                        events.Repeat(11s);
                    }
                    else
                        EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                }
                case EVENT_ASSASSIN:
                    if (Creature* trigger = ObjectAccessor::GetCreature(*me, _assassinTrigger))
                    {
                        trigger->CastSpell(trigger, SPELL_SUMMON_ASSASSIN, true);
                        trigger->CastSpell(trigger, SPELL_SUMMON_ASSASSIN, true);
                        if (_assassinCount > 2)
                        {
                            _assassinCount -= 2;
                            events.Repeat(20s);
                        }
                        else
                            _assassinCount = 0;
                    }
                    else // something went wrong
                        EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                case EVENT_GUARDIAN:
                    if (Creature* trigger = ObjectAccessor::GetCreature(*me, _guardianTrigger))
                    {
                        trigger->CastSpell(trigger, SPELL_SUMMON_GUARDIAN, true);
                        trigger->CastSpell(trigger, SPELL_SUMMON_GUARDIAN, true);
                        if (_guardianCount > 2)
                        {
                            _guardianCount -= 2;
                            events.Repeat(20s);
                        }
                        else
                            _guardianCount = 0;
                    }
                    else
                        EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                case EVENT_VENOMANCER:
                    if (Creature* trigger = ObjectAccessor::GetCreature(*me, _guardianTrigger))
                    {
                        trigger->CastSpell(trigger, SPELL_SUMMON_VENOMANCER, true);
                        trigger->CastSpell(trigger, SPELL_SUMMON_VENOMANCER, true);
                        if (_venomancerCount > 2)
                        {
                            _venomancerCount -= 2;
                            events.Repeat(20s);
                        }
                        else
                            _venomancerCount = 0;
                    }
                    else
                        EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        switch (id)
        {
            case GUID_TYPE_PET:
            {
                if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                    JustSummoned(creature);
                else // something has gone horribly wrong
                    EnterEvadeMode(EVADE_REASON_OTHER);
                break;
            }
            case GUID_TYPE_IMPALE:
                _impaleTarget = guid;
                events.ScheduleEvent(EVENT_IMPALE, 4s);
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PET_DIED:
                if (!_petCount) // underflow check - something has gone horribly wrong
                {
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }
                if (!--_petCount) // last pet died, emerge
                {
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                    me->RemoveAurasDueToSpell(SPELL_IMPALE_AURA);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_EMERGE);
                    events.SetPhase(PHASE_EMERGE);
                    events.ScheduleEvent(EVENT_POUND, 13s, 18s, 0, PHASE_EMERGE);
                    events.ScheduleEvent(EVENT_LEECHING_SWARM, 3s, 7s, 0, PHASE_EMERGE);
                    events.ScheduleEvent(EVENT_CARRION_BEETLES, 10s, 15s, 0, PHASE_EMERGE);
                }
                break;
            case ACTION_PET_EVADE:
                EnterEvadeMode(EVADE_REASON_OTHER);
                break;
        }
    }

    void DamageTaken(Unit* /*source*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HasAura(SPELL_SUBMERGE))
            damage = 0;
        else
            if (_nextSubmerge && me->HealthBelowPctDamaged(_nextSubmerge, damage))
            {
                events.RescheduleEvent(EVENT_SUBMERGE, 0s, 0, PHASE_EMERGE);
                _nextSubmerge = _nextSubmerge-25;
            }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SUBMERGE)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
            me->RemoveAurasDueToSpell(SPELL_LEECHING_SWARM);
            DoCastSelf(SPELL_IMPALE_AURA, true);

            events.SetPhase(PHASE_SUBMERGE);
            switch (_nextSubmerge)
            {
                case 50: // first submerge phase
                    _assassinCount = 4;
                    _guardianCount = 2;
                    _venomancerCount = 0;
                    break;
                case 25: // second submerge phase
                    _assassinCount = 6;
                    _guardianCount = 2;
                    _venomancerCount = 2;
                    break;
                case 0:  // third submerge phase
                    _assassinCount = 6;
                    _guardianCount = 2;
                    _venomancerCount = 2;
                    events.ScheduleEvent(EVENT_DARTER, 0s, 0, PHASE_SUBMERGE);
                    break;
            }
            _petCount = _guardianCount + _venomancerCount;
            if (_assassinCount)
                events.ScheduleEvent(EVENT_ASSASSIN, 0s, 0, PHASE_SUBMERGE);
            if (_guardianCount)
                events.ScheduleEvent(EVENT_GUARDIAN, 4s, 0, PHASE_SUBMERGE);
            if (_venomancerCount)
                events.ScheduleEvent(EVENT_VENOMANCER, 20s, 0, PHASE_SUBMERGE);
        }
    }

    private:
        ObjectGuid _impaleTarget;
        uint32 _nextSubmerge;
        uint32 _petCount;
        ObjectGuid _guardianTrigger;
        ObjectGuid _assassinTrigger;
        uint8 _assassinCount;
        uint8 _guardianCount;
        uint8 _venomancerCount;
};

class npc_anubarak_pet_template : public ScriptedAI
{
    public:
        npc_anubarak_pet_template(Creature* creature, bool isLarge) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _isLarge(isLarge) { }

        void InitializeAI() override
        {
            ScriptedAI::InitializeAI();
            if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
                anubarak->AI()->SetGUID(me->GetGUID(), GUID_TYPE_PET);
            else
                me->DespawnOrUnsummon();
        }

        void JustDied(Unit* killer) override
        {
            ScriptedAI::JustDied(killer);
            if (_isLarge)
                if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
                    anubarak->AI()->DoAction(ACTION_PET_DIED);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
                anubarak->AI()->DoAction(ACTION_PET_EVADE);
            else
                me->DespawnOrUnsummon();
        }

    protected:
        InstanceScript* _instance;
    private:
        bool const _isLarge;
};

struct npc_anubarak_anub_ar_darter : public npc_anubarak_pet_template
{
    npc_anubarak_anub_ar_darter(Creature* creature) : npc_anubarak_pet_template(creature, false) { }

    void InitializeAI() override
    {
        npc_anubarak_pet_template::InitializeAI();
        DoCastAOE(SPELL_DART);
    }
};

struct npc_anubarak_anub_ar_assassin : public npc_anubarak_pet_template
{
    npc_anubarak_anub_ar_assassin(Creature* creature) : npc_anubarak_pet_template(creature, false){ }

    Position GetRandomPositionAround(Creature* anubarak)
    {
        static float DISTANCE_MIN = 10.0f;
        static float DISTANCE_MAX = 30.0f;
        double angle = rand_norm() * 2.0 * M_PI;
        return { anubarak->GetPositionX() + (float)(frand(DISTANCE_MIN, DISTANCE_MAX)*std::sin(angle)), anubarak->GetPositionY() + (float)(frand(DISTANCE_MIN, DISTANCE_MAX)*std::cos(angle)), anubarak->GetPositionZ() };
    }

    void InitializeAI() override
    {
        npc_anubarak_pet_template::InitializeAI();
        CreatureBoundary const* boundary = _instance->GetBossBoundary(DATA_ANUBARAK);
        if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
        {
            Position jumpTo;
            do
                jumpTo = GetRandomPositionAround(anubarak);
            while (!CreatureAI::IsInBounds(*boundary, &jumpTo));
            me->GetMotionMaster()->MoveJump(jumpTo, 40.0f, 40.0f);
            DoCastSelf(SPELL_ASSASSIN_VISUAL, true);
        }
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(6s, [this](TaskContext task)
        {
            if (me->GetVictim() && me->GetVictim()->isInBack(me))
                DoCastVictim(SPELL_BACKSTAB);

            task.Repeat();
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == EVENT_JUMP)
        {
            me->RemoveAurasDueToSpell(SPELL_ASSASSIN_VISUAL);
            DoZoneInCombat();
        }
    }

private:
    TaskScheduler _scheduler;
};

struct npc_anubarak_anub_ar_guardian : public npc_anubarak_pet_template
{
    npc_anubarak_anub_ar_guardian(Creature* creature) : npc_anubarak_pet_template(creature, true) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(6s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_SUNDER_ARMOR);
            task.Repeat(12s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

struct npc_anubarak_anub_ar_venomancer : public npc_anubarak_pet_template
{
    npc_anubarak_anub_ar_venomancer(Creature* creature) : npc_anubarak_pet_template(creature, true) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_POISON_BOLT);
            task.Repeat(2s, 3s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

struct npc_anubarak_impale_target : public NullCreatureAI
{
    npc_anubarak_impale_target(Creature* creature) : NullCreatureAI(creature) { }

    void InitializeAI() override
    {
        if (Creature* anubarak = me->GetInstanceScript()->GetCreature(DATA_ANUBARAK))
        {
            DoCastSelf(SPELL_IMPALE_VISUAL);
            me->DespawnOrUnsummon(6s);
            anubarak->AI()->SetGUID(me->GetGUID(), GUID_TYPE_IMPALE);
        }
        else
            me->DespawnOrUnsummon();
    }
};

// 53472, 59433 - Pound
class spell_anubarak_pound : public AuraScript
{
    PrepareAuraScript(spell_anubarak_pound);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_POUND_DAMAGE });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            GetCaster()->CastSpell(target, SPELL_POUND_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_anubarak_pound::AfterApply, EFFECT_2, SPELL_AURA_FLY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 53520 - Carrion Beetles
class spell_anubarak_carrion_beetles : public AuraScript
{
    PrepareAuraScript(spell_anubarak_carrion_beetles);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_CARRION_BEETLE });
    }

    void HandlePeriodic(AuraEffect const* /*eff*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_CARRION_BEETLE, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_CARRION_BEETLE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anubarak_carrion_beetles::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_anub_arak()
{
    RegisterAzjolNerubCreatureAI(boss_anub_arak);

    RegisterAzjolNerubCreatureAI(npc_anubarak_anub_ar_darter);
    RegisterAzjolNerubCreatureAI(npc_anubarak_anub_ar_assassin);
    RegisterAzjolNerubCreatureAI(npc_anubarak_anub_ar_guardian);
    RegisterAzjolNerubCreatureAI(npc_anubarak_anub_ar_venomancer);
    RegisterAzjolNerubCreatureAI(npc_anubarak_impale_target);

    RegisterSpellScript(spell_anubarak_pound);
    RegisterSpellScript(spell_anubarak_carrion_beetles);
}
