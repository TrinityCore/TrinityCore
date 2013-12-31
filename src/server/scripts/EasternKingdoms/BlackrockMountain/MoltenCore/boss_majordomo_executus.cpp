/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Majordomo_Executus
SD%Complete: 30
SDComment: Correct spawning and Event NYI
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "molten_core.h"
#include "Player.h"

enum Texts
{
    SAY_AGGRO           = 0,
    SAY_SPAWN           = 1,
    SAY_SLAY            = 2,
    SAY_SPECIAL         = 3,
    SAY_DEFEAT          = 4,

    SAY_SUMMON_MAJ      = 5,
    SAY_ARRIVAL2_MAJ    = 6
};

enum Spells
{
    SPELL_MAGIC_REFLECTION  = 20619,
    SPELL_DAMAGE_REFLECTION = 21075,
    SPELL_BLAST_WAVE        = 20229,
    SPELL_AEGIS_OF_RAGNAROS = 20620,
    SPELL_TELEPORT          = 20618,
    SPELL_SUMMON_RAGNAROS   = 19774,
};

#define GOSSIP_HELLO 4995
#define GOSSIP_SELECT "Tell me more."

enum Events
{
    EVENT_MAGIC_REFLECTION  = 1,
    EVENT_DAMAGE_REFLECTION = 2,
    EVENT_BLAST_WAVE        = 3,
    EVENT_TELEPORT          = 4,

    EVENT_OUTRO_1           = 5,
    EVENT_OUTRO_2           = 6,
    EVENT_OUTRO_3           = 7,
};

class boss_majordomo : public CreatureScript
{
    public:
        boss_majordomo() : CreatureScript("boss_majordomo") { }

        struct boss_majordomoAI : public BossAI
        {
            boss_majordomoAI(Creature* creature) : BossAI(creature, BOSS_MAJORDOMO_EXECUTUS)
            {
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                if (urand(0, 99) < 25)
                    Talk(SAY_SLAY);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                BossAI::EnterCombat(who);
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_MAGIC_REFLECTION, 30000);
                events.ScheduleEvent(EVENT_DAMAGE_REFLECTION, 15000);
                events.ScheduleEvent(EVENT_BLAST_WAVE, 10000);
                events.ScheduleEvent(EVENT_TELEPORT, 20000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (instance && instance->GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(diff);

                    if (!me->FindNearestCreature(NPC_FLAMEWAKER_HEALER, 100.0f) && !me->FindNearestCreature(NPC_FLAMEWAKER_ELITE, 100.0f))
                    {
                        instance->UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, me->GetEntry(), me);
                        me->setFaction(35);
                        me->AI()->EnterEvadeMode();
                        Talk(SAY_DEFEAT);
                        _JustDied();
                        events.ScheduleEvent(EVENT_OUTRO_1, 32000);
                        return;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (HealthBelowPct(50))
                        DoCast(me, SPELL_AEGIS_OF_RAGNAROS, true);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_MAGIC_REFLECTION:
                                DoCast(me, SPELL_MAGIC_REFLECTION);
                                events.ScheduleEvent(EVENT_MAGIC_REFLECTION, 30000);
                                break;
                            case EVENT_DAMAGE_REFLECTION:
                                DoCast(me, SPELL_DAMAGE_REFLECTION);
                                events.ScheduleEvent(EVENT_DAMAGE_REFLECTION, 30000);
                                break;
                            case EVENT_BLAST_WAVE:
                                DoCastVictim(SPELL_BLAST_WAVE);
                                events.ScheduleEvent(EVENT_BLAST_WAVE, 10000);
                                break;
                            case EVENT_TELEPORT:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                    DoCast(target, SPELL_TELEPORT);
                                events.ScheduleEvent(EVENT_TELEPORT, 20000);
                                break;
                            default:
                                break;
                        }
                    }

                    DoMeleeAttackIfReady();
                }
                else
                {
                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_OUTRO_1:
                                me->NearTeleportTo(RagnarosTelePos.GetPositionX(), RagnarosTelePos.GetPositionY(), RagnarosTelePos.GetPositionZ(), RagnarosTelePos.GetOrientation());
                                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                break;
                            case EVENT_OUTRO_2:
                                instance->instance->SummonCreature(NPC_RAGNAROS, RagnarosSummonPos);
                                break;
                            case EVENT_OUTRO_3:
                                Talk(SAY_ARRIVAL2_MAJ);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            void DoAction(int32 action) OVERRIDE
            {
                if (action == ACTION_START_RAGNAROS)
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_SUMMON_MAJ);
                    events.ScheduleEvent(EVENT_OUTRO_2, 8000);
                    events.ScheduleEvent(EVENT_OUTRO_3, 24000);
                }
                else if (action == ACTION_START_RAGNAROS_ALT)
                {
                    me->setFaction(35);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                }
            }
        };

        bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_HELLO, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) OVERRIDE
        {
            player->CLOSE_GOSSIP_MENU();
            creature->AI()->DoAction(ACTION_START_RAGNAROS);
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_majordomoAI>(creature);
        }
};

void AddSC_boss_majordomo()
{
    new boss_majordomo();
}
