/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuras.h"
#include "vault_of_archavon.h"

//Emalon spells
enum Spells
{
    SPELL_OVERCHARGE            = 64218,    // Cast every 45 sec on a random Tempest Minion
    SPELL_BERSERK               = 26662,

    SPELL_SHOCK                 = 64363,
    SPELL_OVERCHARGED           = 64217,
    SPELL_OVERCHARGED_BLAST     = 64219,    // Cast when Overcharged reaches 10 stacks. Mob dies after that
};

// cannot let SpellDifficulty handle it, no entries for these
#define SPELL_CHAIN_LIGHTNING           RAID_MODE(64213, 64215)
#define SPELL_LIGHTNING_NOVA            RAID_MODE(64216, 65279)

enum BossEmotes
{
    EMOTE_OVERCHARGE        = 0,
    EMOTE_MINION_RESPAWN    = 1,
    EMOTE_BERSERK           = 2
};

enum Events
{
    EVENT_CHAIN_LIGHTNING   = 1,
    EVENT_LIGHTNING_NOVA    = 2,
    EVENT_OVERCHARGE        = 3,
    EVENT_BERSERK           = 4,
    EVENT_SHOCK             = 5,
};

//Creatures
#define NPC_TEMPEST_MINION          33998

#define MAX_TEMPEST_MINIONS         4

struct Position TempestMinions[MAX_TEMPEST_MINIONS] =
{
    {-203.980103f, -281.287720f, 91.650223f, 1.598807f},
    {-233.489410f, -281.139282f, 91.652412f, 1.598807f},
    {-233.267578f, -297.104645f, 91.681915f, 1.598807f},
    {-203.842529f, -297.097015f, 91.745163f, 1.598807f}
};

/*######
##  Emalon the Storm Watcher
######*/
class boss_emalon : public CreatureScript
{
    public:
        boss_emalon() : CreatureScript("boss_emalon") { }

        struct boss_emalonAI : public BossAI
        {
            boss_emalonAI(Creature* creature) : BossAI(creature, DATA_EMALON)
            {
            }

            void Reset()
            {
                _Reset();

                for (uint8 i = 0; i < MAX_TEMPEST_MINIONS; ++i)
                    me->SummonCreature(NPC_TEMPEST_MINION, TempestMinions[i], TEMPSUMMON_CORPSE_DESPAWN, 0);
            }

            void JustSummoned(Creature* summoned)
            {
                BossAI::JustSummoned(summoned);

                // AttackStart has NULL-check for victim
                if (summoned->AI())
                    summoned->AI()->AttackStart(me->GetVictim());
            }

            void EnterCombat(Unit* who)
            {
                if (!summons.empty())
                {
                    for (std::list<uint64>::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
                    {
                        Creature* minion = Unit::GetCreature(*me, *itr);
                        if (minion && minion->IsAlive() && !minion->GetVictim() && minion->AI())
                            minion->AI()->AttackStart(who);
                    }
                }

                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 5000);
                events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 40000);
                events.ScheduleEvent(EVENT_BERSERK, 360000);
                events.ScheduleEvent(EVENT_OVERCHARGE, 45000);

                _EnterCombat();
            }

            void UpdateAI(uint32 diff)
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
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 25000);
                            break;
                        case EVENT_LIGHTNING_NOVA:
                            DoCastAOE(SPELL_LIGHTNING_NOVA);
                            events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 40000);
                            break;
                        case EVENT_OVERCHARGE:
                            if (!summons.empty())
                            {
                                Creature* minion = Unit::GetCreature(*me, Trinity::Containers::SelectRandomContainerElement(summons));
                                if (minion && minion->IsAlive())
                                {
                                    minion->CastSpell(me, SPELL_OVERCHARGED, true);
                                    minion->SetFullHealth();
                                    Talk(EMOTE_OVERCHARGE);
                                    events.ScheduleEvent(EVENT_OVERCHARGE, 45000);
                                }
                            }
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_emalonAI(creature);
        }
};

/*######
##  Tempest Minion
######*/
class npc_tempest_minion : public CreatureScript
{
    public:
        npc_tempest_minion() : CreatureScript("npc_tempest_minion") { }

        struct npc_tempest_minionAI : public ScriptedAI
        {
            npc_tempest_minionAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
                OverchargedTimer = 0;
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* emalon = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_EMALON) : 0))
                {
                    if (emalon->IsAlive())
                    {
                        emalon->SummonCreature(NPC_TEMPEST_MINION, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        Talk(EMOTE_MINION_RESPAWN);
                    }
                }
            }

            void EnterCombat(Unit* who)
            {
                DoZoneInCombat();
                events.ScheduleEvent(EVENT_SHOCK, 20000);

                if (Creature* pEmalon = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_EMALON) : 0))
                {
                    if (!pEmalon->GetVictim() && pEmalon->AI())
                        pEmalon->AI()->AttackStart(who);
                }
            }

            void UpdateAI(uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (Aura const* overchargedAura = me->GetAura(SPELL_OVERCHARGED))
                {
                    if (overchargedAura->GetStackAmount() < 10)
                    {
                        if (OverchargedTimer <= diff)
                        {
                            DoCast(me, SPELL_OVERCHARGED);
                            OverchargedTimer = 2000;
                        }
                        else
                            OverchargedTimer -= diff;
                    }
                    else
                    {
                        if (overchargedAura->GetStackAmount() == 10)
                        {
                            DoCast(me, SPELL_OVERCHARGED_BLAST);
                            me->DespawnOrUnsummon();
                            Talk(EMOTE_MINION_RESPAWN);
                        }
                    }
                }

                if (events.ExecuteEvent() == EVENT_SHOCK)
                {
                    DoCastVictim(SPELL_SHOCK);
                    events.ScheduleEvent(EVENT_SHOCK, 20000);
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            EventMap events;
            uint32 OverchargedTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tempest_minionAI(creature);
        }
};

void AddSC_boss_emalon()
{
    new boss_emalon();
    new npc_tempest_minion();
}
