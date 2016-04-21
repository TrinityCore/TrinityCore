/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum Talks
{
    TALK_AGGRO,
    TALK_DEATH,
    TALK_INTRO,
    TALK_SLAY,
    TALK_SPECIAL1,
    TALK_SPECIAL2,
    TALK_SPECIAL3,
};

enum Spells
{
    SPELL_PLANT_EXPLOSIVE               = 107187,

    SPELL_SABOTAGE                      = 107268,
    SPELL_SABOTAGE_EXPLOSION            = 113645,
    
    SPELL_PLAYER_EXPLOSION              = 113654,

    SPELL_MUNITION_STABLE               = 109987,
    SPELL_MUNITION_EXPLOSION            = 107153,
    SPELL_MUNITION_EXPLOSION_VISUAL     = 107216,
    SPELL_MUNITION_EXPLOSION_DAMAGE     = 107215,
};

enum Events
{
    EVENT_EXPLOSIVES        = 1,
    EVENT_SABOTAGE          = 2
};

enum WorldInFlames
{
    WIF_NONE    = 0,
    WIF_70      = 1,
    WIF_30      = 2
};

class boss_saboteur_kiptilak : public CreatureScript
{
    public:
        boss_saboteur_kiptilak() : CreatureScript("boss_saboteur_kiptilak") {}

        struct boss_saboteur_kiptilakAI : public BossAI
        {
            boss_saboteur_kiptilakAI(Creature* creature) : BossAI(creature, DATA_KIPTILAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint8 WorldInFlamesEvents;

            void Reset()
            {
                _Reset();
                
                events.ScheduleEvent(EVENT_EXPLOSIVES, urand(7500,  10000));
                events.ScheduleEvent(EVENT_SABOTAGE,   urand(22500, 30000));

                WorldInFlamesEvents = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(TALK_INTRO);
            }

            void KilledUnit(Unit* u)
            {
                if (!urand(0, 1))
                    Talk(TALK_SLAY);
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_KIPTILAK, FAIL);
                summons.DespawnAll();
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                switch (attacker->GetEntry())
                {
                    case NPC_EXPLOSION_BUNNY_N_M:
                    case NPC_EXPLOSION_BUNNY_S_M:
                    case NPC_EXPLOSION_BUNNY_E_M:
                    case NPC_EXPLOSION_BUNNY_W_M:
                    case NPC_EXPLOSION_BUNNY_N_P:
                    case NPC_EXPLOSION_BUNNY_S_P:
                    case NPC_EXPLOSION_BUNNY_E_P:
                    case NPC_EXPLOSION_BUNNY_W_P:
                        damage = 0;
                        return;
                }

                float nextHealthPct = ((float(me->GetHealth()) - damage)  / float(me->GetMaxHealth())) * 100;

                if (WorldInFlamesEvents < WIF_70 && nextHealthPct <= 70.0f)
                {
                    DoWorldInFlamesEvent();
                    ++WorldInFlamesEvents;
                }
                else if (WorldInFlamesEvents < WIF_30 && nextHealthPct <= 30.0f)
                {
                    DoWorldInFlamesEvent();
                    ++WorldInFlamesEvents;
                }
            }

            void DoWorldInFlamesEvent()
            {
                Talk(TALK_SPECIAL3);
                std::list<Creature*> munitionList;
                GetCreatureListWithEntryInGrid(munitionList, me, NPC_STABLE_MUNITION, 100.0f);

                for (auto itr: munitionList)
                {
                    itr->RemoveAurasDueToSpell(SPELL_MUNITION_STABLE);
                    itr->CastSpell(itr, SPELL_MUNITION_EXPLOSION, true);
                    itr->DespawnOrUnsummon(2000);
                }
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_STABLE_MUNITION)
                    summoned->AddAura(SPELL_MUNITION_STABLE, summoned);

                summons.Summon(summoned);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_EXPLOSIVES:
                        if (!urand(0, 2))
                            Talk(TALK_SPECIAL2);

                        for (uint8 i = 0; i < urand(1, 3); ++i)
                            me->CastSpell(frand(702, 740), frand(2292, 2320), 388.5f, SPELL_PLANT_EXPLOSIVE, true);

                        events.ScheduleEvent(EVENT_EXPLOSIVES, urand(7500, 12500));
                        break;
                    case EVENT_SABOTAGE:
                        if (!urand(0, 2))
                            Talk(TALK_SPECIAL1);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            me->CastSpell(target, SPELL_SABOTAGE, true);

                        events.ScheduleEvent(EVENT_SABOTAGE,   urand(22500, 30000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(TALK_DEATH);
            }
        };

        CreatureAI* GetInstanceAI(Creature* creature) const
        {
            return new boss_saboteur_kiptilakAI(creature);
        }
};

class npc_instable_munition : public CreatureScript
{
public:
    npc_instable_munition() : CreatureScript("npc_instable_munition") { }

    struct npc_instable_munitionAI : public ScriptedAI
    {
        npc_instable_munitionAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_instable_munitionAI (creature);
    }
};

class npc_munition_explosion_bunny : public CreatureScript
{
public:
    npc_munition_explosion_bunny() : CreatureScript("npc_munition_explosion_bunny") { }

    struct npc_munition_explosion_bunnyAI : public ScriptedAI
    {
        npc_munition_explosion_bunnyAI(Creature* creature) : ScriptedAI(creature) {}

        float orientation;
        uint32 checkTimer;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            orientation = 0.0f;
            checkTimer = 1000;

            switch (me->GetEntry())
            {
                case NPC_EXPLOSION_BUNNY_N_M:
                case NPC_EXPLOSION_BUNNY_N_P:
                    orientation = 0.0f;
                    break;
                case NPC_EXPLOSION_BUNNY_S_M:
                case NPC_EXPLOSION_BUNNY_S_P:
                    orientation = M_PI;
                    break;
                case NPC_EXPLOSION_BUNNY_E_M:
                case NPC_EXPLOSION_BUNNY_E_P:
                    orientation = 4.71f;
                    break;
                case NPC_EXPLOSION_BUNNY_W_M:
                case NPC_EXPLOSION_BUNNY_W_P:
                    orientation = 1.57f;
                    break;
            }

            float x = 0.0f;
            float y = 0.0f;
            //GetPositionWithDistInOrientation(me, 40.0f, orientation, x, y);
            me->GetMotionMaster()->MovePoint(1, x, y, me->GetPositionZ());

            me->AddAura(SPELL_MUNITION_EXPLOSION_VISUAL, me);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (id == 1)
                me->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/)
        {
            return;
        }
        
        void UpdateAI(uint32 diff)
        {
            if (checkTimer <= diff)
            {
                checkTimer = 500;
                if (Creature* munition = GetClosestCreatureWithEntry(me, NPC_STABLE_MUNITION, 2.0f, true))
                {
                    if (munition->HasAura(SPELL_MUNITION_STABLE))
                    {
                        munition->RemoveAurasDueToSpell(SPELL_MUNITION_STABLE);
                        munition->CastSpell(munition, SPELL_MUNITION_EXPLOSION, true);
                        munition->DespawnOrUnsummon(2000);
                    }
                }

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 2.0f);

                for (auto player : playerList)
                    me->CastSpell(player, SPELL_MUNITION_EXPLOSION_DAMAGE, true);
            }
            else checkTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_munition_explosion_bunnyAI (creature);
    }
};

class spell_kiptilak_sabotage : public SpellScriptLoader
{
    public:
        spell_kiptilak_sabotage() :  SpellScriptLoader("spell_kiptilak_sabotage") { }

        class spell_kiptilak_sabotage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_kiptilak_sabotage_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                target->CastSpell(target, SPELL_PLAYER_EXPLOSION, true);
                target->CastSpell(target, SPELL_SABOTAGE_EXPLOSION, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_kiptilak_sabotage_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_kiptilak_sabotage_AuraScript();
        }
};

void AddSC_boss_saboteur_kiptilak()
{
    new boss_saboteur_kiptilak();
    new npc_instable_munition();
    new npc_munition_explosion_bunny();
    new spell_kiptilak_sabotage();
}
