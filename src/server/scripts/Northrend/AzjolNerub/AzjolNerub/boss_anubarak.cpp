/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

class boss_anub_arak : public CreatureScript
{
public:
    boss_anub_arak() : CreatureScript("boss_anub_arak") { }

    struct boss_anub_arakAI : public BossAI
    {
        boss_anub_arakAI(Creature* creature) : BossAI(creature, DATA_ANUBARAK), _nextSubmerge(0), _petCount(0), _assassinCount(0), _guardianCount(0), _venomancerCount(0) { }

        void Reset() override
        {
            BossAI::Reset();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            instance->DoStopCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_GOTTA_GO_START_EVENT);
            _nextSubmerge = 75;
            _petCount = 0;
        }

        bool CanAIAttack(Unit const* /*who*/) const override { return true; } // do not check boundary here

        void EnterCombat(Unit* who) override
        {
            BossAI::EnterCombat(who);

            if (GameObject* door = instance->GetGameObject(DATA_ANUBARAK_WALL))
                door->SetGoState(GO_STATE_ACTIVE); // open door for now
            if (GameObject* door2 = instance->GetGameObject(DATA_ANUBARAK_WALL_2))
                door2->SetGoState(GO_STATE_ACTIVE);

            Talk(SAY_AGGRO);
            instance->DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_GOTTA_GO_START_EVENT);

            events.SetPhase(PHASE_EMERGE);
            events.ScheduleEvent(EVENT_CLOSE_DOOR, Seconds(5));
            events.ScheduleEvent(EVENT_POUND, randtime(Seconds(2), Seconds(4)), 0, PHASE_EMERGE);
            events.ScheduleEvent(EVENT_LEECHING_SWARM, randtime(Seconds(5), Seconds(7)), 0, PHASE_EMERGE);
            events.ScheduleEvent(EVENT_CARRION_BEETLES, randtime(Seconds(14), Seconds(17)), 0, PHASE_EMERGE);

            // set up world triggers
            std::list<TempSummon*> summoned;
            me->SummonCreatureGroup(SUMMON_GROUP_WORLD_TRIGGER_GUARDIAN, &summoned);
            if (summoned.empty()) // something went wrong
            {
                EnterEvadeMode(EVADE_REASON_OTHER);
                return;
            }
            _guardianTrigger = (*summoned.begin())->GetGUID();

            if (Creature* trigger = DoSummon(NPC_WORLD_TRIGGER, me->GetPosition(), 0u, TEMPSUMMON_MANUAL_DESPAWN))
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
                        events.Repeat(randtime(Seconds(26), Seconds(32)));
                        break;
                    case EVENT_LEECHING_SWARM:
                        Talk(SAY_LOCUST);
                        DoCastAOE(SPELL_LEECHING_SWARM);
                        events.Repeat(randtime(Seconds(25), Seconds(28)));
                        break;
                    case EVENT_CARRION_BEETLES:
                        DoCastAOE(SPELL_CARRION_BEETLES);
                        events.Repeat(randtime(Seconds(24), Seconds(27)));
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
                            std::list<Creature*>::iterator it = triggers.begin();
                            std::advance(it, urand(0, triggers.size()-1));
                            (*it)->CastSpell(*it, SPELL_SUMMON_DARTER, true);
                            events.Repeat(Seconds(11));
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
                                events.Repeat(Seconds(20));
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
                                events.Repeat(Seconds(20));
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
                                events.Repeat(Seconds(20));
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

        void SetGUID(ObjectGuid guid, int32 type) override
        {
            switch (type)
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
                    events.ScheduleEvent(EVENT_IMPALE, Seconds(4));
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
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        DoCastSelf(SPELL_EMERGE);
                        events.SetPhase(PHASE_EMERGE);
                        events.ScheduleEvent(EVENT_POUND, randtime(Seconds(13), Seconds(18)), 0, PHASE_EMERGE);
                        events.ScheduleEvent(EVENT_LEECHING_SWARM, randtime(Seconds(3), Seconds(7)), 0, PHASE_EMERGE);
                        events.ScheduleEvent(EVENT_CARRION_BEETLES, randtime(Seconds(10), Seconds(15)), 0, PHASE_EMERGE);
                    }
                    break;
                case ACTION_PET_EVADE:
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
            }
        }

        void DamageTaken(Unit* /*source*/, uint32& damage) override
        {
            if (me->HasAura(SPELL_SUBMERGE))
                damage = 0;
            else
                if (_nextSubmerge && me->HealthBelowPctDamaged(_nextSubmerge, damage))
                {
                    events.CancelEvent(EVENT_SUBMERGE);
                    events.ScheduleEvent(EVENT_SUBMERGE, 0, 0, PHASE_EMERGE);
                    _nextSubmerge = _nextSubmerge-25;
                }
        }

        void SpellHit(Unit* /*whose*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SUBMERGE)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
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
                        events.ScheduleEvent(EVENT_DARTER, Seconds(0), 0, PHASE_SUBMERGE);
                        break;
                }
                _petCount = _guardianCount + _venomancerCount;
                if (_assassinCount)
                    events.ScheduleEvent(EVENT_ASSASSIN, Seconds(0), 0, PHASE_SUBMERGE);
                if (_guardianCount)
                    events.ScheduleEvent(EVENT_GUARDIAN, Seconds(4), 0, PHASE_SUBMERGE);
                if (_venomancerCount)
                    events.ScheduleEvent(EVENT_VENOMANCER, Seconds(20), 0, PHASE_SUBMERGE);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAzjolNerubAI<boss_anub_arakAI>(creature);
    }
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

class npc_anubarak_anub_ar_darter : public CreatureScript
{
    public:
        npc_anubarak_anub_ar_darter() : CreatureScript("npc_anubarak_anub_ar_darter") { }

        struct npc_anubarak_anub_ar_darterAI : public npc_anubarak_pet_template
        {
            npc_anubarak_anub_ar_darterAI(Creature* creature) : npc_anubarak_pet_template(creature, false) { }

            void InitializeAI() override
            {
                npc_anubarak_pet_template::InitializeAI();
                DoCastAOE(SPELL_DART);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anubarak_anub_ar_darterAI>(creature);
        }
};

class npc_anubarak_anub_ar_assassin : public CreatureScript
{
    public:
        npc_anubarak_anub_ar_assassin() : CreatureScript("npc_anubarak_anub_ar_assassin") { }

        struct npc_anubarak_anub_ar_assassinAI : public npc_anubarak_pet_template
        {
            npc_anubarak_anub_ar_assassinAI(Creature* creature) : npc_anubarak_pet_template(creature, false), _backstabTimer(6 * IN_MILLISECONDS) { }

            bool IsInBounds(Position const& jumpTo, CreatureBoundary const* boundary)
            {
                if (!boundary)
                    return true;
                for (AreaBoundary const* it : *boundary)
                    if (!it->IsWithinBoundary(&jumpTo))
                        return false;
                return true;
            }
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
                    while (!IsInBounds(jumpTo, boundary));
                    me->GetMotionMaster()->MoveJump(jumpTo, 40.0f, 40.0f);
                    DoCastSelf(SPELL_ASSASSIN_VISUAL, true);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (diff >= _backstabTimer)
                {
                    if (me->GetVictim() && me->GetVictim()->isInBack(me))
                        DoCastVictim(SPELL_BACKSTAB);
                    _backstabTimer = 6 * IN_MILLISECONDS;
                }
                else
                    _backstabTimer -= diff;

                DoMeleeAttackIfReady();
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
                uint32 _backstabTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anubarak_anub_ar_assassinAI>(creature);
        }
};

class npc_anubarak_anub_ar_guardian : public CreatureScript
{
    public:
    npc_anubarak_anub_ar_guardian() : CreatureScript("npc_anubarak_anub_ar_guardian") { }

    struct npc_anubarak_anub_ar_guardianAI : public npc_anubarak_pet_template
    {
        npc_anubarak_anub_ar_guardianAI(Creature* creature) : npc_anubarak_pet_template(creature, true), _sunderTimer(6 * IN_MILLISECONDS) { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (diff >= _sunderTimer)
            {
                DoCastVictim(SPELL_SUNDER_ARMOR);
                _sunderTimer = 12 * IN_MILLISECONDS;
            }
            else
                _sunderTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:
            uint32 _sunderTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAzjolNerubAI<npc_anubarak_anub_ar_guardianAI>(creature);
    }
};

class npc_anubarak_anub_ar_venomancer : public CreatureScript
{
    public:
    npc_anubarak_anub_ar_venomancer() : CreatureScript("npc_anubarak_anub_ar_venomancer") { }

    struct npc_anubarak_anub_ar_venomancerAI : public npc_anubarak_pet_template
    {
        npc_anubarak_anub_ar_venomancerAI(Creature* creature) : npc_anubarak_pet_template(creature, true), _boltTimer(5 * IN_MILLISECONDS) { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (diff >= _boltTimer)
            {
                DoCastVictim(SPELL_POISON_BOLT);
                _boltTimer = urandms(2, 3);
            }
            else
                _boltTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:
            uint32 _boltTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAzjolNerubAI<npc_anubarak_anub_ar_venomancerAI>(creature);
    }
};

class npc_anubarak_impale_target : public CreatureScript
{
    public:
        npc_anubarak_impale_target() : CreatureScript("npc_anubarak_impale_target") { }

        struct npc_anubarak_impale_targetAI : public NullCreatureAI
        {
            npc_anubarak_impale_targetAI(Creature* creature) : NullCreatureAI(creature) { }

            void InitializeAI() override
            {
                if (Creature* anubarak = me->GetInstanceScript()->GetCreature(DATA_ANUBARAK))
                {
                    DoCastSelf(SPELL_IMPALE_VISUAL);
                    me->DespawnOrUnsummon(Seconds(6));
                    anubarak->AI()->SetGUID(me->GetGUID(), GUID_TYPE_IMPALE);
                }
                else
                    me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anubarak_impale_targetAI>(creature);
        }
};

class spell_anubarak_pound : public SpellScriptLoader
{
    public:
        spell_anubarak_pound() : SpellScriptLoader("spell_anubarak_pound") { }

        class spell_anubarak_pound_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anubarak_pound_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_POUND_DAMAGE });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_POUND_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_anubarak_pound_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_anubarak_pound_SpellScript();
        }
};

class spell_anubarak_carrion_beetles : public SpellScriptLoader
{
    public:
        spell_anubarak_carrion_beetles() : SpellScriptLoader("spell_anubarak_carrion_beetles") { }

        class spell_anubarak_carrion_beetles_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_anubarak_carrion_beetles_AuraScript);

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
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_anubarak_carrion_beetles_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_anubarak_carrion_beetles_AuraScript();
        }
};

void AddSC_boss_anub_arak()
{
    new boss_anub_arak();

    new npc_anubarak_anub_ar_darter();
    new npc_anubarak_anub_ar_assassin();
    new npc_anubarak_anub_ar_guardian();
    new npc_anubarak_anub_ar_venomancer();
    new npc_anubarak_impale_target();

    new spell_anubarak_pound();
    new spell_anubarak_carrion_beetles();
}
