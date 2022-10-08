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
#include "ScriptedCreature.h"
#include "gate_setting_sun.h"

enum eSpells
{
    // Commander Rimok
    SPELL_VISCOUS_FLUID_SUMMON      = 107078,
    SPELL_VISCOUS_FLUID_DMG_UP      = 107091,
    SPELL_VISCOUS_FLUID_DMG_DOWN    = 107122,
    SPELL_FRENZIED_ASSAULT          = 107120,

    // Add Generator
    SPELL_PERIODIC_SPAWN_SWARMER    = 115052,
    SPELL_PERIODIC_SPAWN_SABOTEUR   = 116621,

    // Saboteur
    SPELL_BOMBARD                   = 120559
};

enum eEvents
{
    EVENT_FRENZIED_ASSAULT  = 1,
    EVENT_VISCOUS_FLUID     = 2
};

class boss_commander_rimok : public CreatureScript
{
    public:
        boss_commander_rimok() : CreatureScript("boss_commander_rimok") {}

        struct boss_commander_rimokAI : public BossAI
        {
            boss_commander_rimokAI(Creature* creature) : BossAI(creature, DATA_RIMOK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset() override
            {
                _Reset();

                events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, urand(5000, 10000));
                events.ScheduleEvent(EVENT_VISCOUS_FLUID,    urand(10000, 15000));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
            }

            void JustReachedHome() override
            {
                instance->SetBossState(DATA_RIMOK, FAIL);
                summons.DespawnAll();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override {}

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch(events.ExecuteEvent())
                {
                    case EVENT_FRENZIED_ASSAULT:
                        if (me->GetVictim())
                            me->CastSpell(me->GetVictim(), SPELL_FRENZIED_ASSAULT, false);

                        events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, urand(10000, 15000));
                        break;
                    case EVENT_VISCOUS_FLUID:
                        me->CastSpell(me, 107077, true);
                        events.ScheduleEvent(EVENT_VISCOUS_FLUID, urand(5000, 10000));
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_commander_rimokAI(creature);
        }
};

class npc_krikthik_swarmer : public CreatureScript
{
    public:
        npc_krikthik_swarmer() : CreatureScript("npc_krikthik_swarmer") {}

        struct npc_krikthik_swarmerAI : public ScriptedAI
        {
            npc_krikthik_swarmerAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 attackTimer;

            void Reset() override
            {
                attackTimer = 2000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (attackTimer)
                {
                    if (attackTimer <= diff)
                    {
                        DoZoneInCombat();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            AttackStart(target);

                        attackTimer = 0;
                    }
                    else attackTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_krikthik_swarmerAI(creature);
        }
};

class npc_krikthik_saboteur : public CreatureScript
{
    public:
        npc_krikthik_saboteur() : CreatureScript("npc_krikthik_saboteur") {}

        struct npc_krikthik_saboteurAI : public ScriptedAI
        {
            npc_krikthik_saboteurAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 attackTimer;
            uint32 checkTimer;

            void Reset() override
            {
                attackTimer = 2000;
                checkTimer = urand(17500, 22500);
            }

            void UpdateAI(uint32 diff) override
            {
                if (attackTimer)
                {
                    if (attackTimer <= diff)
                    {
                        DoZoneInCombat();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            AttackStart(target);

                        attackTimer = 0;
                    }
                    else attackTimer -= diff;
                }

                if (checkTimer <= diff)
                {
                    me->CastSpell(me, SPELL_BOMBARD, false);
                    checkTimer = urand(7500, 12500);
                }
                else checkTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_krikthik_saboteurAI(creature);
        }
};

class npc_add_generator : public CreatureScript
{
    public:
        npc_add_generator() : CreatureScript("npc_add_generator") {}

        struct npc_add_generatorAI : public ScriptedAI
        {
            npc_add_generatorAI(Creature* creature) : ScriptedAI(creature), summons(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            SummonList summons;

            void Reset() override
            {
                me->RemoveAurasDueToSpell(SPELL_PERIODIC_SPAWN_SWARMER);
                me->RemoveAurasDueToSpell(SPELL_PERIODIC_SPAWN_SABOTEUR);
                summons.DespawnAll();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case NOT_STARTED:
                    case FAIL:
                        summons.DespawnAll();
                        // no break
                    case DONE:
                        me->RemoveAurasDueToSpell(SPELL_PERIODIC_SPAWN_SWARMER);
                        me->RemoveAurasDueToSpell(SPELL_PERIODIC_SPAWN_SABOTEUR);
                        break;
                    case SPECIAL: // Only one must spawn saboteurs
                        me->CastSpell(me, SPELL_PERIODIC_SPAWN_SABOTEUR, true);
                        break;
                    case IN_PROGRESS:
                        me->CastSpell(me, SPELL_PERIODIC_SPAWN_SWARMER, true);
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);

                float x = me->GetPositionX();
                float y = me->GetPositionY() - 10;
                float z = me->GetMap()->GetHeight(me->GetPhaseShift(), x, y, 400.0f);
                summoned->GetMotionMaster()->MoveJump(x, y, z, 0.0f, 10, 20);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_add_generatorAI(creature);
        }
};

class npc_viscous_fluid : public CreatureScript
{
    public:
        npc_viscous_fluid() : CreatureScript("npc_viscous_fluid") {}

        struct npc_viscous_fluidAI : public ScriptedAI
        {
            npc_viscous_fluidAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 checkTimer;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                checkTimer = 1000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (checkTimer <= diff)
                {
                    if (Player* player = me->SelectNearestPlayer())
                    {
                        if (me->GetDistance(player) < 5.0f)
                        {
                            if (Creature* rimok = pInstance->instance->GetCreature(pInstance->GetGuidData(NPC_RIMOK)))
                            {
                                me->AddAura(SPELL_VISCOUS_FLUID_DMG_UP, rimok);
                                me->AddAura(SPELL_VISCOUS_FLUID_DMG_DOWN, player);
                            }
                        }
                    }

                    checkTimer = 1000;
                }
                else checkTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_viscous_fluidAI(creature);
        }
};

class spell_rimok_saboteur_bombard: public SpellScriptLoader
{
    public:
        spell_rimok_saboteur_bombard() :  SpellScriptLoader("spell_rimok_saboteur_bombard") { }

        class spell_rimok_saboteur_bombard_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rimok_saboteur_bombard_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();

                if (Unit* caster = GetCaster())
                {
                    if (InstanceScript* pInstance = caster->GetInstanceScript())
                    {
                        Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();

                        if (PlayerList.isEmpty())
                            return;

                        Map::PlayerList::const_iterator it = PlayerList.begin();
                        for (uint8 i = 0; i < urand(0, PlayerList.getSize() - 1); ++i, ++it);

                        if (it == PlayerList.end())
                            return;

                        if (Player* player = it->GetSource())
                            caster->CastSpell(player, GetSpellInfo()->GetEffect(0)->TriggerSpell, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rimok_saboteur_bombard_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rimok_saboteur_bombard_AuraScript();
        }
};

void AddSC_boss_commander_rimok()
{
    new boss_commander_rimok();
    new npc_krikthik_swarmer();
    new npc_krikthik_saboteur();
    new npc_add_generator();
    new npc_viscous_fluid();
    new spell_rimok_saboteur_bombard();
}
