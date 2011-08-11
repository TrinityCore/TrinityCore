/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_BALTHARUS_INTRO = 0,    // Your power wanes, ancient one.... Soon you will join your friends.
    SAY_AGGRO,                  // Ah, the entertainment has arrived.
    SAY_KILL,                   // Baltharus leaves no survivors! - This world has enough heroes.
    SAY_CLONE,                  // Twice the pain and half the fun.
    SAY_DEATH                   // I... didn't see that coming....
};

enum Spells
{
    SPELL_BARRIER_CHANNEL       = 76221,
    SPELL_ENERVATING_BRAND      = 74502,
    SPELL_SIPHONED_MIGHT        = 74507,
    SPELL_CLEAVE                = 40504,
    SPELL_BLADE_TEMPEST         = 75125,
    SPELL_CLONE                 = 74511,
    SPELL_REPELLING_WAVE        = 74509,
    SPELL_CLEAR_DEBUFFS         = 34098,
    SPELL_SPAWN_EFFECT          = 64195,

    SPELL_ENRAGE                = 26662,
    SPELL_FEURIGE_EINAESCHERUNG = 74562,
    SPELL_GROSSBRAND            = 74456
};

enum Events
{
    EVENT_BLADE_TEMPEST = 1,
    EVENT_CLEAVE,
    EVENT_ENERVATING_BRAND,
    EVENT_INTRO_TALK,
    EVENT_OOC_CHANNEL,
    EVENT_ENRAGE,
    EVENT_FEURIGE_EINAESCHERUNG,
    EVENT_GROSSBRAND,
    EVENT_TIMER
};

enum Actions
{
    ACTION_CLONE = 1
};

enum Phases
{
    PHASE_ALL = 0,
    PHASE_INTRO,
    PHASE_COMBAT,
    PHASE_INTRO_MASK = 1 << PHASE_INTRO
};

enum Diverse
{
    BALTHARUS_CLONE_OUTDOOR = 60006
};

class boss_baltharus_the_warborn_outdoor : public CreatureScript
{
    public:
        boss_baltharus_the_warborn_outdoor() : CreatureScript("boss_baltharus_the_warborn_outdoor") { }

        struct boss_baltharus_the_warborn_outdoorAI : public WorldBossAI
        {
            boss_baltharus_the_warborn_outdoorAI(Creature * creature) : WorldBossAI(creature)
            {
                me->SetHomePosition(4458.606f,-168.933f,86.58399f,0.0f); // Dies entspricht nicht dem Spawnpunkt (DB), deshalb hier setzen!

                _introDone = false;
                _random = false;
            }

            void Reset()
            {
                _Reset();
                _cloneCount = 2;
            }

            void DoAction(int32 const action)
            {
                switch(action)
                {
                    case ACTION_INTRO_BALTHARUS:
                        if (_introDone)
                            return;
                        _introDone = true;
                        me->setActive(true);
                        events.ScheduleEvent(EVENT_INTRO_TALK, 7 * IN_MILLISECONDS, 0, PHASE_INTRO);
                        break;
                    case ACTION_CLONE:
                        if (_cloneCount > 0)
                        {
                            Talk(SAY_CLONE);

                            DoCast(me, SPELL_CLEAR_DEBUFFS, true);
                            //DoCast(me, SPELL_CLONE);
                            Position pos;
                            me->GetPosition(&pos);
                            me->SummonCreature(BALTHARUS_CLONE_OUTDOOR, pos, TEMPSUMMON_CORPSE_DESPAWN);
                            DoCast(me, SPELL_REPELLING_WAVE, true);
                            --_cloneCount;
                        }
                        break;
                    default:
                        break;
                }
            }

            void MoveInLineOfSight(Unit * who)
            {
                if (!who || me->getVictim())
                    return;

                Unit * pTarget = who;

                if (!_introDone && pTarget->GetDistance(me) <= 100)
                {
                    DoAction(ACTION_INTRO_BALTHARUS);
                    return;
                }
                // Keine NPCs angreifen, die nicht zu einem Spieler gehören!
                if (pTarget->GetTypeId() == TYPEID_UNIT && !pTarget->GetOwner())
                    return;
                // Nur Spieler angreifen, die keine GMs sind!
                if (pTarget->GetTypeId() == TYPEID_PLAYER)
                    if (pTarget->ToPlayer()->GetSession()->GetSecurity() > SEC_VETERAN)
                        return;

                if (me->canStartAttack(pTarget, true))
                    AttackStart(pTarget);
            }

            void EnterCombat(Unit * /*who*/)
            {
                _EnterCombat();

                DoZoneInCombat(me, true);

                Talk(SAY_AGGRO);

                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_CLEAVE, 11 * IN_MILLISECONDS, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_ENERVATING_BRAND, 13 * IN_MILLISECONDS, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BLADE_TEMPEST, 15 * IN_MILLISECONDS, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_ENRAGE, MINUTEN_10);
                events.ScheduleEvent(EVENT_FEURIGE_EINAESCHERUNG, SEKUNDEN_10);
                events.ScheduleEvent(EVENT_GROSSBRAND, SEKUNDEN_30);
            }

            void JustDied(Unit * /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit * victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER && urand(0,2) == 1)
                    Talk(SAY_KILL);
            }

            void JustSummoned(Creature * summon)
            {
                summons.Summon(summon);
                summon->CastSpell(summon, SPELL_SPAWN_EFFECT, true);
                summon->SetHealth(me->GetHealth());

                if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f))
                    summon->AI()->AttackStart(target);
            }

            void DamageTaken(Unit * /*attacker*/, uint32 & damage)
            {
                switch(_cloneCount)
                {
                    case 2: if (me->HealthBelowPctDamaged(66, damage)) DoAction(ACTION_CLONE); break;
                    case 1: if (me->HealthBelowPctDamaged(33, damage)) DoAction(ACTION_CLONE); break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!_random && me->GetPositionX() >= 4458.0f && me->GetPositionY() <= -168.0f && me->GetPositionZ() >= 86.0f)
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->Initialize();
                    me->GetMotionMaster()->MoveRandom(80.0f);

                    _random = true;
                }

                if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING) && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_TALK:
                            Talk(SAY_BALTHARUS_INTRO);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.RescheduleEvent(EVENT_CLEAVE, SEKUNDEN_20, 0, PHASE_COMBAT);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCast(me, SPELL_BLADE_TEMPEST);
                            events.RescheduleEvent(EVENT_BLADE_TEMPEST, SEKUNDEN_20, 0, PHASE_COMBAT);
                            break;
                        case EVENT_ENERVATING_BRAND:
                            for (uint8 i=0; i<20; ++i)
                                if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                                    DoCast(target, SPELL_ENERVATING_BRAND);
                                events.RescheduleEvent(EVENT_ENERVATING_BRAND, 22 * IN_MILLISECONDS, 0, PHASE_COMBAT);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(SPELL_ENRAGE);
                            break;
                        case EVENT_FEURIGE_EINAESCHERUNG:
                            if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                                DoCast(target, SPELL_FEURIGE_EINAESCHERUNG);
                            events.RescheduleEvent(EVENT_FEURIGE_EINAESCHERUNG, urand(SEKUNDEN_20, SEKUNDEN_30), 0, PHASE_COMBAT);
                            break;
                        case EVENT_GROSSBRAND:
                            for (uint8 i=0; i<4; ++i)
                                if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                                    DoCast(target, SPELL_GROSSBRAND);
                            events.RescheduleEvent(EVENT_GROSSBRAND, urand(SEKUNDEN_30, 45 * IN_MILLISECONDS), 0, PHASE_COMBAT);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            private:
                uint8 _cloneCount;
                bool _introDone;
                bool _random;
        };

        CreatureAI * GetAI(Creature * creature) const
        {
            return new boss_baltharus_the_warborn_outdoorAI(creature);
        }
};

class npc_baltharus_the_warborn_clone_outdoor : public CreatureScript
{
    public:
        npc_baltharus_the_warborn_clone_outdoor() : CreatureScript("npc_baltharus_the_warborn_clone_outdoor") { }

        struct npc_baltharus_the_warborn_clone_outdoorAI : public ScriptedAI
        {
            npc_baltharus_the_warborn_clone_outdoorAI(Creature * creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoZoneInCombat(me, true);

                _events.ScheduleEvent(EVENT_CLEAVE, 11 * IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_BLADE_TEMPEST, 15 * IN_MILLISECONDS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.RescheduleEvent(EVENT_CLEAVE, SEKUNDEN_20);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCast(me, SPELL_BLADE_TEMPEST);
                            _events.RescheduleEvent(EVENT_BLADE_TEMPEST, SEKUNDEN_20);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            private:
                EventMap _events;
        };

        CreatureAI * GetAI(Creature * creature) const
        {
            return new npc_baltharus_the_warborn_clone_outdoorAI(creature);
        }
};

class boss_baltharus_the_warborn : public CreatureScript
{
    public:
        boss_baltharus_the_warborn() : CreatureScript("boss_baltharus_the_warborn") { }

        struct boss_baltharus_the_warbornAI : public BossAI
        {
            boss_baltharus_the_warbornAI(Creature* creature) : BossAI(creature, DATA_BALTHARUS_THE_WARBORN)
            {
                _introDone = false;
            }

            void Reset()
            {
                _Reset();
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_OOC_CHANNEL, 0, 0, PHASE_INTRO);
                _cloneCount = RAID_MODE<uint8>(1, 2, 2, 2);
                instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetMaxHealth());
            }

            void DoAction(int32 const action)
            {
                switch(action)
                {
                    case ACTION_INTRO_BALTHARUS:
                        if (_introDone)
                            return;
                        _introDone = true;
                        me->setActive(true);
                        events.ScheduleEvent(EVENT_INTRO_TALK, 7000, 0, PHASE_INTRO);
                        break;
                    case ACTION_CLONE:
                    {
                        DoCast(me, SPELL_CLEAR_DEBUFFS);
                        DoCast(me, SPELL_CLONE);
                        DoCast(me, SPELL_REPELLING_WAVE);
                        Talk(SAY_CLONE);
                        --_cloneCount;
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->InterruptNonMeleeSpells(false);
                _EnterCombat();
                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_CLEAVE, 11000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_ENERVATING_BRAND, 13000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BLADE_TEMPEST, 15000, 0, PHASE_COMBAT);
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (Creature* xerestrasza = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_XERESTRASZA)))
                    xerestrasza->AI()->DoAction(ACTION_BALTHARUS_DEATH);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                summon->SetHealth(me->GetHealth());
                summon->CastSpell(summon, SPELL_SPAWN_EFFECT, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                {
                    if (me->HealthBelowPctDamaged(50, damage) && _cloneCount == 1)
                        DoAction(ACTION_CLONE);
                }
                else
                {
                    if (me->HealthBelowPctDamaged(66, damage) && _cloneCount == 2)
                        DoAction(ACTION_CLONE);
                    else if (me->HealthBelowPctDamaged(33, damage) && _cloneCount == 1)
                        DoAction(ACTION_CLONE);
                }

                if (me->GetHealth() - damage > 0)
                    instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetHealth() - damage);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                if (!(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    me->SetHealth(instance->GetData(DATA_BALTHARUS_SHARED_HEALTH));

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING) && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_TALK:
                            Talk(SAY_BALTHARUS_INTRO);
                            break;
                        case EVENT_OOC_CHANNEL:
                            if (Creature* channelTarget = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_CRYSTAL_CHANNEL_TARGET)))
                                DoCast(channelTarget, SPELL_BARRIER_CHANNEL);
                            events.ScheduleEvent(EVENT_OOC_CHANNEL, 7000, 0, PHASE_INTRO);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, 24000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCast(me, SPELL_BLADE_TEMPEST);
                            events.ScheduleEvent(EVENT_BLADE_TEMPEST, 24000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_ENERVATING_BRAND:
                            for (uint8 i = 0; i < RAID_MODE<uint8>(4, 8, 8, 10); i++)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                    DoCast(target, SPELL_ENERVATING_BRAND);
                            events.ScheduleEvent(EVENT_ENERVATING_BRAND, 26000, 0, PHASE_COMBAT);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _cloneCount;
            bool _introDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_baltharus_the_warbornAI>(creature);
        }
};

class npc_baltharus_the_warborn_clone : public CreatureScript
{
    public:
        npc_baltharus_the_warborn_clone() : CreatureScript("npc_baltharus_the_warborn_clone") { }

        struct npc_baltharus_the_warborn_cloneAI : public ScriptedAI
        {
            npc_baltharus_the_warborn_cloneAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = (InstanceScript*)creature->GetInstanceScript();
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 10000));
                _events.ScheduleEvent(EVENT_BLADE_TEMPEST, urand(18000, 25000));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                // Setting DATA_BALTHARUS_SHARED_HEALTH to 0 when killed would bug the boss.
                if (_instance && me->GetHealth() - damage > 0)
                    _instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetHealth() - damage);
            }

            void JustDied(Unit* killer)
            {
                // This is here because DamageTaken wont trigger if the damage is deadly.
                if (_instance)
                    if (Creature* baltharus = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_BALTHARUS_THE_WARBORN)))
                        killer->Kill(baltharus);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_instance)
                    me->SetHealth(_instance->GetData(DATA_BALTHARUS_SHARED_HEALTH));

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.ScheduleEvent(EVENT_CLEAVE, 24000);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCastVictim(SPELL_BLADE_TEMPEST);
                            _events.ScheduleEvent(EVENT_BLADE_TEMPEST, 24000);
                           break;
                        default:
                            break;
                    }
               }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_baltharus_the_warborn_cloneAI>(creature);
        }
};

class spell_baltharus_enervating_brand : public SpellScriptLoader
{
    public:
        spell_baltharus_enervating_brand() : SpellScriptLoader("spell_baltharus_enervating_brand") { }

        class spell_baltharus_enervating_brand_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baltharus_enervating_brand_AuraScript);

            void HandleTriggerSpell(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                Unit* target = GetTarget();
                uint32 triggerSpellId = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                target->CastSpell(target, triggerSpellId, true);

                if (Unit* caster = GetCaster())
                    if (target->GetDistance(caster) <= 12.0f)
                        target->CastSpell(caster, SPELL_SIPHONED_MIGHT, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_baltharus_enervating_brand_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_baltharus_enervating_brand_AuraScript();
        }
};

class EnervatingBrandSelector
{
    public:
        explicit EnervatingBrandSelector(Unit* caster) : _caster(caster) {}

        bool operator()(Unit* unit)
        {
            if (_caster->GetDistance(unit) > 12.0f)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            return false;
        }

    private:
        Unit* _caster;
};

class spell_baltharus_enervating_brand_trigger : public SpellScriptLoader
{
    public:
        spell_baltharus_enervating_brand_trigger() : SpellScriptLoader("spell_baltharus_enervating_brand_trigger") { }

        class spell_baltharus_enervating_brand_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baltharus_enervating_brand_trigger_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(EnervatingBrandSelector(GetCaster()));
                unitList.push_back(GetCaster());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_baltharus_enervating_brand_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_baltharus_enervating_brand_trigger_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_baltharus_enervating_brand_trigger_SpellScript();
        }
};

void AddSC_boss_baltharus_the_warborn()
{
    new boss_baltharus_the_warborn();
    new boss_baltharus_the_warborn_outdoor();
    new npc_baltharus_the_warborn_clone();
    new npc_baltharus_the_warborn_clone_outdoor();
    new spell_baltharus_enervating_brand();
    new spell_baltharus_enervating_brand_trigger();
}
