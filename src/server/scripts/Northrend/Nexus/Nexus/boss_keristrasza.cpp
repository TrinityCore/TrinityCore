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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "nexus.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Spells
{
    //Spells
    SPELL_FROZEN_PRISON                           = 47854,
    SPELL_TAIL_SWEEP                              = 50155,
    SPELL_CRYSTAL_CHAINS                          = 50997,
    SPELL_ENRAGE                                  = 8599,
    SPELL_CRYSTALFIRE_BREATH                      = 48096,
    SPELL_CRYSTALLIZE                             = 48179,
    SPELL_INTENSE_COLD                            = 48094,
    SPELL_INTENSE_COLD_TRIGGERED                  = 48095
};

enum Events
{
    EVENT_CRYSTAL_FIRE_BREATH                     = 1,
    EVENT_CRYSTAL_CHAINS_CRYSTALLIZE,
    EVENT_TAIL_SWEEP
};

enum Yells
{
    // Yell
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_ENRAGE                                    = 2,
    SAY_DEATH                                     = 3,
    SAY_CRYSTAL_NOVA                              = 4,
    SAY_FRENZY                                    = 5
};

enum Misc
{
    DATA_INTENSE_COLD                             = 1,
    DATA_CONTAINMENT_SPHERES                      = 3
};

class boss_keristrasza : public CreatureScript
{
    public:
        boss_keristrasza() : CreatureScript("boss_keristrasza") { }

        struct boss_keristraszaAI : public BossAI
        {
            boss_keristraszaAI(Creature* creature) : BossAI(creature, DATA_KERISTRASZA)
            {
                Initialize();
            }

            void Initialize()
            {
                _enrage = false;
                _intenseCold = true;
            }

            void Reset() override
            {
                Initialize();
                _intenseColdList.clear();

                me->RemoveUnitFlag(UNIT_FLAG_STUNNED);

                RemovePrison(CheckContainmentSpheres());
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                DoCastAOE(SPELL_INTENSE_COLD);
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_CRYSTAL_FIRE_BREATH, 14s);
                events.ScheduleEvent(EVENT_CRYSTAL_CHAINS_CRYSTALLIZE, DUNGEON_MODE(30s, 11s));
                events.ScheduleEvent(EVENT_TAIL_SWEEP, 5s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            bool CheckContainmentSpheres(bool removePrison = false)
            {
                for (uint32 i = ANOMALUS_CONTAINMENT_SPHERE; i < (ANOMALUS_CONTAINMENT_SPHERE + DATA_CONTAINMENT_SPHERES); ++i)
                {
                    GameObject* containmentSpheres = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(i));
                    if (!containmentSpheres || containmentSpheres->GetGoState() != GO_STATE_ACTIVE)
                        return false;
                }
                if (removePrison)
                    RemovePrison(true);
                return true;
            }

            void RemovePrison(bool remove)
            {
                if (remove)
                {
                    me->SetImmuneToPC(false);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    if (me->HasAura(SPELL_FROZEN_PRISON))
                        me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
                }
                else
                {
                    me->SetImmuneToPC(true);
                    me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(me, SPELL_FROZEN_PRISON, false);
                }
            }

            void SetGUID(ObjectGuid const& guid, int32 id) override
            {
                if (id == DATA_INTENSE_COLD)
                    _intenseColdList.push_back(guid);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (!_enrage && me->HealthBelowPctDamaged(25, damage))
                {
                    Talk(SAY_ENRAGE);
                    Talk(SAY_FRENZY);
                    DoCast(me, SPELL_ENRAGE);
                    _enrage = true;
                }
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
                        case EVENT_CRYSTAL_FIRE_BREATH:
                            DoCastVictim(SPELL_CRYSTALFIRE_BREATH);
                            events.ScheduleEvent(EVENT_CRYSTAL_FIRE_BREATH, 14s);
                            break;
                        case EVENT_CRYSTAL_CHAINS_CRYSTALLIZE:
                            DoCast(me, SPELL_TAIL_SWEEP);
                            events.ScheduleEvent(EVENT_CRYSTAL_CHAINS_CRYSTALLIZE, 5s);
                            break;
                        case EVENT_TAIL_SWEEP:
                            Talk(SAY_CRYSTAL_NOVA);
                            if (IsHeroic())
                                DoCast(me, SPELL_CRYSTALLIZE);
                            else if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_CRYSTAL_CHAINS);
                            events.ScheduleEvent(EVENT_TAIL_SWEEP, DUNGEON_MODE(30s, 11s));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _intenseCold;
            bool _enrage;

        public:
            GuidList _intenseColdList;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNexusAI<boss_keristraszaAI>(creature);
        }
};

class containment_sphere : public GameObjectScript
{
public:
    containment_sphere() : GameObjectScript("containment_sphere") { }

    struct containment_sphereAI : public GameObjectAI
    {
        containment_sphereAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool OnGossipHello(Player* /*player*/) override
        {
            Creature* keristrasza = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KERISTRASZA));
            if (keristrasza && keristrasza->IsAlive())
            {
                // maybe these are hacks :(
                me->AddFlag(GO_FLAG_NOT_SELECTABLE);
                me->SetGoState(GO_STATE_ACTIVE);

                ENSURE_AI(boss_keristrasza::boss_keristraszaAI, keristrasza->AI())->CheckContainmentSpheres(true);
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetNexusAI<containment_sphereAI>(go);
    }
};

class spell_intense_cold : public SpellScriptLoader
{
    public:
        spell_intense_cold() : SpellScriptLoader("spell_intense_cold") { }

        class spell_intense_cold_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_intense_cold_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (GetStackAmount() < 2)
                    return;
                Unit* caster = GetCaster();
                /// @todo the caster should be boss but not the player
                if (!caster || !caster->GetAI())
                    return;
                caster->GetAI()->SetGUID(GetTarget()->GetGUID(), DATA_INTENSE_COLD);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_intense_cold_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_intense_cold_AuraScript();
        }
};

class achievement_intense_cold : public AchievementCriteriaScript
{
    public:
        achievement_intense_cold() : AchievementCriteriaScript("achievement_intense_cold")
        {
        }

        bool OnCheck(Player* player, Unit* target) override
        {
            if (!target)
                return false;

            GuidList const& _intenseColdList = ENSURE_AI(boss_keristrasza::boss_keristraszaAI, target->GetAI())->_intenseColdList;
            if (!_intenseColdList.empty())
                for (GuidList::const_iterator itr = _intenseColdList.begin(); itr != _intenseColdList.end(); ++itr)
                    if (player->GetGUID() == *itr)
                        return false;

            return true;
        }
};

void AddSC_boss_keristrasza()
{
    new boss_keristrasza();
    new containment_sphere();
    new achievement_intense_cold();
    new spell_intense_cold();
}
