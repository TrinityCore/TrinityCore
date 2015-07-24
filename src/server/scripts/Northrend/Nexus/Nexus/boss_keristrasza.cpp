/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "nexus.h"

enum Spells
{
    //Spells
    SPELL_FROZEN_PRISON                           = 47854,
    SPELL_TAIL_SWEEP                              = 50155,
    SPELL_CRYSTAL_CHAINS                          = 50997,
    SPELL_ENRAGE                                  = 8599,
    SPELL_CRYSTALFIRE_BREATH                      = 48096,
    SPELL_CRYSTALIZE                              = 48179,
    SPELL_INTENSE_COLD                            = 48094,
    SPELL_INTENSE_COLD_TRIGGERED                  = 48095
};

enum Events
{
    EVENT_CRYSTAL_FIRE_BREATH                     = 1,
    EVENT_CRYSTAL_CHAINS_CRYSTALIZE,
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

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

                RemovePrison(CheckContainmentSpheres());
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                DoCastAOE(SPELL_INTENSE_COLD);
                _EnterCombat();

                events.ScheduleEvent(EVENT_CRYSTAL_FIRE_BREATH, 14000);
                events.ScheduleEvent(EVENT_CRYSTAL_CHAINS_CRYSTALIZE, DUNGEON_MODE(30000, 11000));
                events.ScheduleEvent(EVENT_TAIL_SWEEP, 5000);
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

            bool CheckContainmentSpheres(bool remove_prison = false)
            {
                ContainmentSphereGUIDs[0] = instance->GetGuidData(ANOMALUS_CONTAINMET_SPHERE);
                ContainmentSphereGUIDs[1] = instance->GetGuidData(ORMOROKS_CONTAINMET_SPHERE);
                ContainmentSphereGUIDs[2] = instance->GetGuidData(TELESTRAS_CONTAINMET_SPHERE);

                GameObject* ContainmentSpheres[DATA_CONTAINMENT_SPHERES];

                for (uint8 i = 0; i < DATA_CONTAINMENT_SPHERES; ++i)
                {
                    ContainmentSpheres[i] = ObjectAccessor::GetGameObject(*me, ContainmentSphereGUIDs[i]);
                    if (!ContainmentSpheres[i])
                        return false;
                    if (ContainmentSpheres[i]->GetGoState() != GO_STATE_ACTIVE)
                        return false;
                }
                if (remove_prison)
                    RemovePrison(true);
                return true;
            }

            void RemovePrison(bool remove)
            {
                if (remove)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (me->HasAura(SPELL_FROZEN_PRISON))
                        me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
                }
                else
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(me, SPELL_FROZEN_PRISON, false);
                }
            }

            void SetGUID(ObjectGuid guid, int32 id/* = 0 */) override
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
                            events.ScheduleEvent(EVENT_CRYSTAL_FIRE_BREATH, 14000);
                            break;
                        case EVENT_CRYSTAL_CHAINS_CRYSTALIZE:
                            DoCast(me, SPELL_TAIL_SWEEP);
                            events.ScheduleEvent(EVENT_CRYSTAL_CHAINS_CRYSTALIZE, 5000);
                            break;
                        case EVENT_TAIL_SWEEP:
                            Talk(SAY_CRYSTAL_NOVA);
                            if (IsHeroic())
                                DoCast(me, SPELL_CRYSTALIZE);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_CRYSTAL_CHAINS);
                            events.ScheduleEvent(EVENT_TAIL_SWEEP, DUNGEON_MODE(30000, 11000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _intenseCold;
            bool _enrage;
            ObjectGuid ContainmentSphereGUIDs[DATA_CONTAINMENT_SPHERES];
        public:
            GuidList _intenseColdList;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_keristraszaAI>(creature);
        }
};

class containment_sphere : public GameObjectScript
{
public:
    containment_sphere() : GameObjectScript("containment_sphere") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) override
    {
        InstanceScript* instance = go->GetInstanceScript();

        Creature* pKeristrasza = ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_KERISTRASZA));
        if (pKeristrasza && pKeristrasza->IsAlive())
        {
            // maybe these are hacks :(
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            go->SetGoState(GO_STATE_ACTIVE);

            ENSURE_AI(boss_keristrasza::boss_keristraszaAI, pKeristrasza->AI())->CheckContainmentSpheres(true);
        }
        return true;
    }

};

class spell_intense_cold : public SpellScriptLoader
{
    public:
        spell_intense_cold() : SpellScriptLoader("spell_intense_cold") { }

        class spell_intense_cold_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_intense_cold_AuraScript);

            void HandlePeriodicTick(AuraEffect const* aurEff)
            {
                if (aurEff->GetBase()->GetStackAmount() < 2)
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

            GuidList _intenseColdList = ENSURE_AI(boss_keristrasza::boss_keristraszaAI, target->ToCreature()->AI())->_intenseColdList;
            if (!_intenseColdList.empty())
                for (GuidList::iterator itr = _intenseColdList.begin(); itr != _intenseColdList.end(); ++itr)
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
