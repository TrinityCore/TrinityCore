/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "trial_of_the_crusader.h"
#include "SpellScript.h"

enum Yells
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    EMOTE_LEGION_FLAME      = 2,
    EMOTE_NETHER_PORTAL     = 3,
    SAY_MISTRESS_OF_PAIN    = 4,
    EMOTE_INCINERATE        = 5,
    SAY_INCINERATE          = 6,
    EMOTE_INFERNAL_ERUPTION = 7,
    SAY_INFERNAL_ERUPTION   = 8,
    SAY_KILL_PLAYER         = 9,
    SAY_DEATH               = 10,
    SAY_BERSERK             = 11
};

enum Summons
{
    NPC_LEGION_FLAME     = 34784,
    NPC_INFERNAL_VOLCANO = 34813,
    NPC_FEL_INFERNAL     = 34815, // immune to all CC on Heroic (stuns, banish, interrupt, etc)
    NPC_NETHER_PORTAL    = 34825,
    NPC_MISTRESS_OF_PAIN = 34826
};

enum BossSpells
{
    SPELL_LEGION_FLAME                = 66197, // player should run away from raid because he triggers Legion Flame
    SPELL_LEGION_FLAME_EFFECT         = 66201, // used by trigger npc
    SPELL_NETHER_POWER                = 66228, // +20% of spell damage per stack, stackable up to 5/10 times, must be dispelled/stealed
    SPELL_FEL_LIGHTING                = 66528, // jumps to nearby targets
    SPELL_FEL_FIREBALL                = 66532, // does heavy damage to the tank, interruptable
    SPELL_INCINERATE_FLESH            = 66237, // target must be healed or will trigger Burning Inferno
    SPELL_BURNING_INFERNO             = 66242, // triggered by Incinerate Flesh
    SPELL_INFERNAL_ERUPTION           = 66258, // summons Infernal Volcano
    SPELL_INFERNAL_ERUPTION_EFFECT    = 66252, // summons Felflame Infernal (3 at Normal and inifinity at Heroic)
    SPELL_NETHER_PORTAL               = 66269, // summons Nether Portal
    SPELL_NETHER_PORTAL_EFFECT        = 66263, // summons Mistress of Pain (1 at Normal and infinity at Heroic)

    SPELL_BERSERK                     = 64238, // unused

    // Mistress of Pain spells
    SPELL_SHIVAN_SLASH                  = 67098,
    SPELL_SPINNING_STRIKE               = 66283,
    SPELL_MISTRESS_KISS                 = 66336,
    SPELL_FEL_INFERNO                   = 67047,
    SPELL_FEL_STREAK                    = 66494,
    SPELL_LORD_HITTIN                   = 66326,   // special effect preventing more specific spells be cast on the same player within 10 seconds
    SPELL_MISTRESS_KISS_DEBUFF          = 66334,
    SPELL_MISTRESS_KISS_DAMAGE_SILENCE  = 66359
};

enum Events
{
    // Lord Jaraxxus
    EVENT_FEL_FIREBALL              = 1,
    EVENT_FEL_LIGHTNING             = 2,
    EVENT_INCINERATE_FLESH          = 3,
    EVENT_NETHER_POWER              = 4,
    EVENT_LEGION_FLAME              = 5,
    EVENT_SUMMONO_NETHER_PORTAL     = 6,
    EVENT_SUMMON_INFERNAL_ERUPTION  = 7,

    // Mistress of Pain
    EVENT_SHIVAN_SLASH              = 8,
    EVENT_SPINNING_STRIKE           = 9,
    EVENT_MISTRESS_KISS             = 10
};

class boss_jaraxxus : public CreatureScript
{
    public:
        boss_jaraxxus() : CreatureScript("boss_jaraxxus") { }

        struct boss_jaraxxusAI : public BossAI
        {
            boss_jaraxxusAI(Creature* creature) : BossAI(creature, BOSS_JARAXXUS)
            {
            }

            void Reset()
            {
                _Reset();
                events.ScheduleEvent(EVENT_FEL_FIREBALL, 5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FEL_LIGHTNING, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_INCINERATE_FLESH, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_NETHER_POWER, 40*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_LEGION_FLAME, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMONO_NETHER_PORTAL, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_INFERNAL_ERUPTION, 80*IN_MILLISECONDS);
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                if (instance)
                    instance->SetBossState(BOSS_JARAXXUS, FAIL);
                DoCast(me, SPELL_JARAXXUS_CHAINS);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL_PLAYER);
                    if (instance)
                        instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustSummoned(Creature* summoned)
            {
                summons.Summon(summoned);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void UpdateAI(const uint32 diff)
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
                        case EVENT_FEL_FIREBALL:
                            DoCastVictim(SPELL_FEL_FIREBALL);
                            events.ScheduleEvent(EVENT_FEL_FIREBALL, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_FEL_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_LORD_HITTIN))
                                DoCast(target, SPELL_FEL_LIGHTING);
                            events.ScheduleEvent(EVENT_FEL_LIGHTNING, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_INCINERATE_FLESH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_LORD_HITTIN))
                            {
                                Talk(EMOTE_INCINERATE, target->GetGUID());
                                Talk(SAY_INCINERATE);
                                DoCast(target, SPELL_INCINERATE_FLESH);
                            }
                            events.ScheduleEvent(EVENT_INCINERATE_FLESH, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_NETHER_POWER:
                            me->CastCustomSpell(SPELL_NETHER_POWER, SPELLVALUE_AURA_STACK, RAID_MODE<uint32>(5, 10, 5,10), me, true);
                            events.ScheduleEvent(EVENT_NETHER_POWER, 40*IN_MILLISECONDS);
                            return;
                        case EVENT_LEGION_FLAME:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_LORD_HITTIN))
                            {
                                Talk(EMOTE_LEGION_FLAME, target->GetGUID());
                                DoCast(target, SPELL_LEGION_FLAME);
                            }
                            events.ScheduleEvent(EVENT_LEGION_FLAME, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_SUMMONO_NETHER_PORTAL:
                            Talk(EMOTE_NETHER_PORTAL);
                            Talk(SAY_MISTRESS_OF_PAIN);
                            DoCast(SPELL_NETHER_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMONO_NETHER_PORTAL, 2*MINUTE*IN_MILLISECONDS);
                            return;
                        case EVENT_SUMMON_INFERNAL_ERUPTION:
                            Talk(EMOTE_INFERNAL_ERUPTION);
                            Talk(SAY_INFERNAL_ERUPTION);
                            DoCast(SPELL_INFERNAL_ERUPTION);
                            events.ScheduleEvent(EVENT_SUMMON_INFERNAL_ERUPTION, 2*MINUTE*IN_MILLISECONDS);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_jaraxxusAI(creature);
        }
};

class mob_legion_flame : public CreatureScript
{
    public:
        mob_legion_flame() : CreatureScript("mob_legion_flame") { }

        struct mob_legion_flameAI : public Scripted_NoMovementAI
        {
            mob_legion_flameAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetInCombatWithZone();
                DoCast(SPELL_LEGION_FLAME_EFFECT);
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                UpdateVictim();
                if (_instance && _instance->GetBossState(BOSS_JARAXXUS) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }
            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_legion_flameAI(creature);
        }
};

class mob_infernal_volcano : public CreatureScript
{
    public:
        mob_infernal_volcano() : CreatureScript("mob_infernal_volcano") { }

        struct mob_infernal_volcanoAI : public Scripted_NoMovementAI
        {
            mob_infernal_volcanoAI(Creature* creature) : Scripted_NoMovementAI(creature), _summons(me)
            {
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);

                if (!IsHeroic())
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                else
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

                _summons.DespawnAll();
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                DoCast(SPELL_INFERNAL_ERUPTION_EFFECT);
            }

            void JustSummoned(Creature* summoned)
            {
                _summons.Summon(summoned);
                // makes immediate corpse despawn of summoned Felflame Infernals
                summoned->SetCorpseDelay(0);
            }

            void JustDied(Unit* /*killer*/)
            {
                // used to despawn corpse immediately
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 const /*diff*/) {}

            private:
                SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_infernal_volcanoAI(creature);
        }
};

class mob_fel_infernal : public CreatureScript
{
    public:
        mob_fel_infernal() : CreatureScript("mob_fel_infernal") { }

        struct mob_fel_infernalAI : public ScriptedAI
        {
            mob_fel_infernalAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _felStreakTimer = 30*IN_MILLISECONDS;
                me->SetInCombatWithZone();
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_JARAXXUS) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (!UpdateVictim())
                    return;

                if (_felStreakTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_FEL_STREAK);
                    _felStreakTimer = 30*IN_MILLISECONDS;
                }
                else
                    _felStreakTimer -= diff;

                DoMeleeAttackIfReady();
            }
            private:
                uint32 _felStreakTimer;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_fel_infernalAI(creature);
        }
};

class mob_nether_portal : public CreatureScript
{
    public:
        mob_nether_portal() : CreatureScript("mob_nether_portal") { }

        struct mob_nether_portalAI : public ScriptedAI
        {
            mob_nether_portalAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);

                if (!IsHeroic())
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                else
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

                _summons.DespawnAll();
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                DoCast(SPELL_NETHER_PORTAL_EFFECT);
            }

            void JustSummoned(Creature* summoned)
            {
                _summons.Summon(summoned);
                // makes immediate corpse despawn of summoned Mistress of Pain
                summoned->SetCorpseDelay(0);
            }

            void JustDied(Unit* /*killer*/)
            {
                // used to despawn corpse immediately
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 const /*diff*/) {}

            private:
                SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nether_portalAI(creature);
        }
};

class mob_mistress_of_pain : public CreatureScript
{
    public:
        mob_mistress_of_pain() : CreatureScript("mob_mistress_of_pain") { }

        struct mob_mistress_of_painAI : public ScriptedAI
        {
            mob_mistress_of_painAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                if (_instance)
                    _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, INCREASE);
            }

            void Reset()
            {
                _events.ScheduleEvent(EVENT_SHIVAN_SLASH, 30*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SPINNING_STRIKE, 30*IN_MILLISECONDS);
                if (IsHeroic())
                    _events.ScheduleEvent(EVENT_MISTRESS_KISS, 15*IN_MILLISECONDS);
                me->SetInCombatWithZone();
            }

            void JustDied(Unit* /*killer*/)
            {
                if (_instance)
                    _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, DECREASE);
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_JARAXXUS) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHIVAN_SLASH:
                            DoCastVictim(SPELL_SHIVAN_SLASH);
                            _events.ScheduleEvent(EVENT_SHIVAN_SLASH, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_SPINNING_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SPINNING_STRIKE);
                            _events.ScheduleEvent(EVENT_SPINNING_STRIKE, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_MISTRESS_KISS:
                            DoCast(me, SPELL_MISTRESS_KISS);
                            _events.ScheduleEvent(EVENT_MISTRESS_KISS, 30*IN_MILLISECONDS);
                            return;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
            private:
                InstanceScript* _instance;
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mistress_of_painAI(creature);
        }
};

class spell_mistress_kiss : public SpellScriptLoader
{
    public:
        spell_mistress_kiss() : SpellScriptLoader("spell_mistress_kiss") { }

        class spell_mistress_kiss_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mistress_kiss_AuraScript);

            bool Load()
            {
                if (GetCaster())
                    if (sSpellMgr->GetSpellIdForDifficulty(SPELL_MISTRESS_KISS_DAMAGE_SILENCE, GetCaster()))
                        return true;
                return false;
            }

            void HandleDummyTick(AuraEffect const* /*aurEff*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                if (caster && target)
                {
                    if (target->HasUnitState(UNIT_STATE_CASTING))
                    {
                        caster->CastSpell(target, SPELL_MISTRESS_KISS_DAMAGE_SILENCE, true);
                        target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mistress_kiss_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mistress_kiss_AuraScript();
        }
};

class spell_mistress_kiss_area : public SpellScriptLoader
{
    public:
        spell_mistress_kiss_area() : SpellScriptLoader("spell_mistress_kiss_area") {}

        class spell_mistress_kiss_area_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mistress_kiss_area_SpellScript)

            bool Load()
            {
                if (GetCaster())
                    if (sSpellMgr->GetSpellIdForDifficulty(SPELL_MISTRESS_KISS_DEBUFF, GetCaster()))
                        return true;
                return false;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                if (caster && target)
                    caster->CastSpell(target, SPELL_MISTRESS_KISS_DEBUFF, true);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // get a list of players with mana
                std::list<WorldObject*> _targets;
                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->ToUnit()->getPowerType() == POWER_MANA)
                        _targets.push_back(*itr);

                // pick a random target and kiss him
                if (WorldObject* _target = Trinity::Containers::SelectRandomContainerElement(_targets))
                {
                    // correctly fill "targets" for the visual effect
                    targets.clear();
                    targets.push_back(_target);
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(_target->ToUnit(), SPELL_MISTRESS_KISS_DEBUFF, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mistress_kiss_area_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mistress_kiss_area_SpellScript();
        }
};

void AddSC_boss_jaraxxus()
{
    new boss_jaraxxus();
    new mob_legion_flame();
    new mob_infernal_volcano();
    new mob_fel_infernal();
    new mob_nether_portal();
    new mob_mistress_of_pain();

    new spell_mistress_kiss();
    new spell_mistress_kiss_area();
}
