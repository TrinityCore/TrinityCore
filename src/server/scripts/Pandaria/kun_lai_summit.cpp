/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "kun_lai_summit.h"

#define GOSSIP_CHOICE_1 "I challenge you."

// Nessos the Oracle - 50789
class mob_nessos_the_oracle : public CreatureScript
{
    public:
        mob_nessos_the_oracle() : CreatureScript("mob_nessos_the_oracle") {}

        struct mob_nessos_the_oracleAI : public ScriptedAI
        {
            mob_nessos_the_oracleAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_VICIOUS_REND,      7000);
                events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17000);
                events.ScheduleEvent(EVENT_VANISH, 12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VICIOUS_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_VICIOUS_REND, false);
                            events.ScheduleEvent(EVENT_VICIOUS_REND,      7000);
                            break;
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17000);
                            break;
                        case EVENT_VANISH:
                            me->CastSpell(me, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 20000);
                            events.ScheduleEvent(EVENT_SMOKED_BLADE, urand(0, 8000));
                            break;
                        case EVENT_SMOKED_BLADE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SMOKED_BLADE, false);

                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_nessos_the_oracleAI(creature);
        }
};

// Ski'thik - 50733
class mob_ski_thik : public CreatureScript
{
    public:
        mob_ski_thik() : CreatureScript("mob_ski_thik") {}

        struct mob_ski_thikAI : public ScriptedAI
        {
            mob_ski_thikAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BLADE_FURY,       8000);
                events.ScheduleEvent(EVENT_TORNADO,         40000);
                events.ScheduleEvent(EVENT_WINDSONG,        32000);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);


                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY,      8000);
                            break;
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 40000);
                            break;
                        case EVENT_WINDSONG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 32000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ski_thikAI(creature);
        }
};

// Havak - 50354
class mob_havak : public CreatureScript
{
    public:
        mob_havak() : CreatureScript("mob_havak") {}

        struct mob_havakAI : public ScriptedAI
        {
            mob_havakAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATING_ARC,   50000);
                events.ScheduleEvent(EVENT_SUMMON_QUILEN,     15000);
                events.ScheduleEvent(EVENT_TITANIC_STRENGH,   32000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEVASTATING_ARC:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEVASTATING_ARC, false);
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC,      50000);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 80000);
                            break;
                        case EVENT_TITANIC_STRENGH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_TITANIC_STRENGH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGH, 40000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_havakAI(creature);
        }
};

// Mogujia Soul-Caller - 59797
class mob_mogujia_soul_caller : public CreatureScript
{
    public:
        mob_mogujia_soul_caller() : CreatureScript("mob_mogujia_soul_caller") {}

        struct mob_mogujia_soul_callerAI : public ScriptedAI
        {
            mob_mogujia_soul_callerAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DRAIN_LIFE,      20000);
                events.ScheduleEvent(EVENT_SHADOW_BOLT,     15000);
                events.ScheduleEvent(EVENT_SHADOW_CRASH,    32000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DRAIN_LIFE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DRAIN_LIFE, false);
                            events.ScheduleEvent(EVENT_DRAIN_LIFE,      20000);
                            break;
                        case EVENT_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SHADOW_BOLT, false);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 15000);
                            break;
                        case EVENT_SHADOW_CRASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHADOW_CRASH, false);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, 32000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mogujia_soul_callerAI(creature);
        }
};

// Quilen Stonemaw - 64014
class mob_quilen_stonemaw : public CreatureScript
{
    public:
        mob_quilen_stonemaw() : CreatureScript("mob_quilen_stonemaw") {}

        struct mob_quilen_stonemawAI : public ScriptedAI
        {
            mob_quilen_stonemawAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM,      5000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNSTABLE_SERUM:
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM,      5000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_quilen_stonemawAI(creature);
        }
};

// Zai the Outcast - 50769
class mob_zai_the_outcast : public CreatureScript
{
    public:
        mob_zai_the_outcast() : CreatureScript("mob_zai_the_outcast") {}

        struct mob_zai_the_outcastAI : public ScriptedAI
        {
            mob_zai_the_outcastAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RAIN_DANCE,       8000);
                events.ScheduleEvent(EVENT_TORRENT,         40000);
                events.ScheduleEvent(EVENT_WATER_BOLT,      32000);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAIN_DANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_RAIN_DANCE, false);
                            events.ScheduleEvent(EVENT_RAIN_DANCE,      8000);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 40000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 32000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_zai_the_outcastAI(creature);
        }
};

// Zhi the Harmonious - 64537
class mob_zhi_the_harmonious : public CreatureScript
{
    public:
        mob_zhi_the_harmonious() : CreatureScript("mob_zhi_the_harmonious") {}

        struct mob_zhi_the_harmoniousAI : public ScriptedAI
        {
            mob_zhi_the_harmoniousAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override {}

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ZHI_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_ZHI_TALK_2:
                        Talk(1);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_zhi_the_harmoniousAI(creature);
        }
};

// Anduin Wrynn - 64540
class mob_andruin_wrynn : public CreatureScript
{
    public:
        mob_andruin_wrynn() : CreatureScript("mob_andruin_wrynn") {}

        struct mob_andruin_wrynnAI : public ScriptedAI
        {
            mob_andruin_wrynnAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override {}

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ANDRUIN_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_ANDRUIN_TALK_2:
                        Talk(1);
                        break;
                    case ACTION_ANDRUIN_TALK_3:
                        Talk(2);
                        break;
                    case ACTION_ANDRUIN_TALK_4:
                        Talk(3);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_andruin_wrynnAI(creature);
        }
};

// Taran Zhu - 64536
class mob_taran_zhu_white_tiger : public CreatureScript
{
    public:
        mob_taran_zhu_white_tiger() : CreatureScript("mob_taran_zhu_white_tiger") {}

        struct mob_taran_zhu_white_tigerAI : public ScriptedAI
        {
            mob_taran_zhu_white_tigerAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override {}

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_TARAN_ZHU_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_TARAN_ZHU_TALK_2:
                        Talk(1);
                        break;
                    case ACTION_TARAN_ZHU_TALK_3:
                        Talk(2);
                        break;
                    case ACTION_TARAN_ZHU_TALK_4:
                        Talk(3);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_taran_zhu_white_tigerAI(creature);
        }
};

// Xuen - 64528
class npc_xuen : public CreatureScript
{
    public:
        npc_xuen() : CreatureScript("npc_xuen") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (!creature->AI())
                return false;

            if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_H) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_A) == QUEST_STATUS_INCOMPLETE)
            {
                if (!creature->AI()->GetData(XUEN_PHASE_1))
                {
                    creature->AI()->DoAction(ACTION_CONVERSATION);
                    player->KilledMonsterCredit(KILLED_CREDIT_FIRST_PHASE);
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->AI()->SetData(XUEN_PHASE_1, DONE);
                }

                if (creature->AI()->GetData(XUEN_PHASE_2))
                {
                    creature->AI()->DoAction(ACTION_SECOND_CONVERSATION);
                    player->KilledMonsterCredit(KILLED_CREDIT_SECOND_PHASE);
                    creature->AI()->SetData(XUEN_PHASE_2, DONE);
                }

                if (creature->AI()->GetData(XUEN_PHASE_3))
                {
                    player->KilledMonsterCredit(KILLED_CREDIT_THIRD_PHASE);
                    creature->AI()->DoAction(ACTION_THIRD_CONVERSATION);
                    creature->AI()->SetData(XUEN_PHASE_3, DONE);
                }
            }

            return true;
        }

        struct npc_xuenAI : public ScriptedAI
        {
            npc_xuenAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;
            ObjectGuid playerGUID;
            uint32 phaseDone[XUEN_PHASE_MAX];

            void Reset() override
            {
                events.Reset();
                playerGUID = ObjectGuid::Empty;
                for (int i = 0; i < XUEN_PHASE_MAX; i++)
                    phaseDone[i] = NOT_STARTED;
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/ /*= 0*/) override
            {
                playerGUID = guid;
            }

            uint32 GetData(uint32 index) const override
            {
                if (index >= XUEN_PHASE_MAX)
                    return 0;

                return phaseDone[index];
            }

            void SetData(uint32 index, uint32 value) override
            {
                if (index >= XUEN_PHASE_MAX)
                    return;

                phaseDone[index] = value;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CONVERSATION:
                        events.ScheduleEvent(EVENT_XUEN_TALK_1, 2000);
                        events.ScheduleEvent(EVENT_TARAN_ZHU_TALK_1, 7000);
                        events.ScheduleEvent(EVENT_ANDRUIN_TALK_1, 13000);
                        events.ScheduleEvent(EVENT_TARAN_ZHU_TALK_2, 20000);
                        events.ScheduleEvent(EVENT_XUEN_TALK_2, 30000);
                        events.ScheduleEvent(EVENT_PLAYER_TELEPORT, 31000);
                        events.ScheduleEvent(EVENT_SPAWN_SPIRIT_OF_VIOLENCE, 34000);
                        events.ScheduleEvent(EVENT_TARAN_ZHU_TALK_3, 45000);
                        events.ScheduleEvent(EVENT_ANDRUIN_TALK_2, 51000);
                        events.ScheduleEvent(EVENT_SPAWN_SPIRIT_OF_VIOLENCE, 54000);
                        events.ScheduleEvent(EVENT_ZHI_TALK_1, 63000);
                        break;
                    case ACTION_SECOND_CONVERSATION:
                        events.ScheduleEvent(EVENT_XUEN_TALK_3, 2000);
                        events.ScheduleEvent(EVENT_PLAYER_TELEPORT, 6000);
                        events.ScheduleEvent(EVENT_SPAWN_SPIRIT_OF_ANGER, 9000);
                        events.ScheduleEvent(EVENT_ANDRUIN_TALK_3, 15000);
                        events.ScheduleEvent(EVENT_TARAN_ZHU_TALK_4, 28000);
                        events.ScheduleEvent(EVENT_SPAWN_SPIRIT_OF_VIOLENCE, 30000);
                        events.ScheduleEvent(EVENT_ZHI_TALK_2, 36000);
                        break;
                    case ACTION_THIRD_CONVERSATION:
                        events.ScheduleEvent(EVENT_XUEN_TALK_4, 2000);
                        events.ScheduleEvent(EVENT_PLAYER_TELEPORT, 6000);
                        events.ScheduleEvent(EVENT_SPAWN_SPIRIT_OF_HATRED, 8000);
                        events.ScheduleEvent(EVENT_ANDRUIN_TALK_4, 20000);
                        break;
                    case ACTION_XUEN_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_XUEN_TALK_2:
                        Talk(1);
                        break;
                    case ACTION_XUEN_TALK_3:
                        Talk(2);
                        break;
                    case ACTION_XUEN_TALK_4:
                        Talk(3);
                        break;
                    case ACTION_FINAL_KILL_CREDIT:
                        events.ScheduleEvent(EVENT_FINAL_KILL_CREDIT, 1000);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                {

                    if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_H) != QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_A) != QUEST_STATUS_INCOMPLETE)
                        return;

                    std::list<Creature*> TaranZhuList;
                    me->GetCreatureListWithEntryInGrid(TaranZhuList, NPC_TARAN_ZHU, 15.0f);

                    std::list<Creature*> andruinWrynnList;
                    me->GetCreatureListWithEntryInGrid(andruinWrynnList, NPC_ANDRUIN_WRYNN, 15.0f);

                    std::list<Creature*> zhiList;
                    me->GetCreatureListWithEntryInGrid(zhiList, NPC_ZHI_THE_HARMONIOUS, 15.0f);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_XUEN_TALK_1:
                                DoAction(ACTION_XUEN_TALK_1);
                                break;
                            case EVENT_TARAN_ZHU_TALK_1:
                                if (!TaranZhuList.empty())
                                    for (auto TaranZhu: TaranZhuList)
                                        TaranZhu->AI()->DoAction(ACTION_TARAN_ZHU_TALK_1);
                                break;
                            case EVENT_ANDRUIN_TALK_1:
                                if (!andruinWrynnList.empty())
                                    for (auto andruinWrynn: andruinWrynnList)
                                        andruinWrynn->AI()->DoAction(ACTION_ANDRUIN_TALK_1);
                                break;
                            case EVENT_TARAN_ZHU_TALK_2:
                                if (!TaranZhuList.empty())
                                    for (auto TaranZhu: TaranZhuList)
                                        TaranZhu->AI()->DoAction(ACTION_TARAN_ZHU_TALK_2);
                                break;
                            case EVENT_XUEN_TALK_2:
                                DoAction(ACTION_XUEN_TALK_2);
                                break;
                            case EVENT_PLAYER_TELEPORT:
                                player->TeleportTo(870, 3770.889f, 538.036f, 639.046f, 0.0f);
                                break;
                            case EVENT_SPAWN_SPIRIT_OF_VIOLENCE:
                                me->SummonCreature(MOB_SPIRIT_OF_VIOLENCE, 3778.698f, 539.101f, 639.007f);
                                break;
                            case EVENT_TARAN_ZHU_TALK_3:
                                if (!TaranZhuList.empty())
                                    for (auto TaranZhu: TaranZhuList)
                                        TaranZhu->AI()->DoAction(ACTION_TARAN_ZHU_TALK_3);
                                break;
                            case EVENT_ANDRUIN_TALK_2:
                                if (!andruinWrynnList.empty())
                                    for (auto andruinWrynn: andruinWrynnList)
                                        andruinWrynn->AI()->DoAction(ACTION_ANDRUIN_TALK_2);
                                break;
                            case EVENT_ZHI_TALK_1:
                                if (!zhiList.empty())
                                    for (auto zhi: zhiList)
                                        zhi->AI()->DoAction(ACTION_ZHI_TALK_1);
                                break;
                            case EVENT_XUEN_TALK_3:
                                DoAction(ACTION_XUEN_TALK_3);
                                break;
                            case EVENT_SPAWN_SPIRIT_OF_ANGER:
                                me->SummonCreature(MOB_SPIRIT_OF_ANGER, 3778.698f, 539.101f, 639.007f);
                                break;
                            case EVENT_ANDRUIN_TALK_3:
                                if (!andruinWrynnList.empty())
                                    for (auto andruinWrynn: andruinWrynnList)
                                        andruinWrynn->AI()->DoAction(ACTION_ANDRUIN_TALK_3);
                                break;
                            case EVENT_TARAN_ZHU_TALK_4:
                                if (!TaranZhuList.empty())
                                    for (auto TaranZhu: TaranZhuList)
                                        TaranZhu->AI()->DoAction(ACTION_TARAN_ZHU_TALK_4);
                                break;
                            case EVENT_ZHI_TALK_2:
                                if (!zhiList.empty())
                                    for (auto zhi: zhiList)
                                        zhi->AI()->DoAction(ACTION_ZHI_TALK_2);
                                break;
                            case EVENT_XUEN_TALK_4:
                                DoAction(ACTION_XUEN_TALK_4);
                                break;
                            case EVENT_SPAWN_SPIRIT_OF_HATRED:
                                if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_H) == QUEST_STATUS_INCOMPLETE)
                                    me->SummonCreature(MOB_SPIRIT_OF_HATRED_1, 3778.698f, 539.101f, 639.007f);

                                if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_A) == QUEST_STATUS_INCOMPLETE)
                                    me->SummonCreature(MOB_SPIRIT_OF_HATRED_2, 3778.698f, 539.101f, 639.007f);
                                break;
                            case EVENT_ANDRUIN_TALK_4:
                                if (!andruinWrynnList.empty())
                                    for (auto andruinWrynn: andruinWrynnList)
                                        andruinWrynn->AI()->DoAction(ACTION_ANDRUIN_TALK_4);
                                break;
                            case EVENT_FINAL_KILL_CREDIT:
                                if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_H) == QUEST_STATUS_INCOMPLETE)
                                    player->KilledMonsterCredit(KILLED_CREDIT_FOURTH_PHASE_H);

                                if (player->GetQuestStatus(QUEST_A_CELESTIAL_EXPERIENCE_A) == QUEST_STATUS_INCOMPLETE)
                                    player->KilledMonsterCredit(KILLED_CREDIT_FOURTH_PHASE_A);

                                Reset();
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_xuenAI(creature);
        }
};

// Spirit of Violence - 64656
class mob_spirit_of_violence : public CreatureScript
{
    public:
        mob_spirit_of_violence() : CreatureScript("mob_spirit_of_violence") {}

        struct mob_spirit_of_violenceAI : public ScriptedAI
        {
            mob_spirit_of_violenceAI(Creature* creature) : ScriptedAI(creature)
            {
                xuenGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid xuenGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UNTAMED_FURY, 3000);
                events.ScheduleEvent(EVENT_HATED_BLAST, 12000);
                events.ScheduleEvent(EVENT_SHA_CORRUPTION, 23000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* xuen = me->GetMap()->GetCreature(xuenGUID);
                if (!xuen || !xuen->GetAI())
                    return;

                xuen->AI()->SetData(XUEN_PHASE_2, DONE);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                xuenGUID = summoner->GetGUID();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNTAMED_FURY:
                            me->CastSpell(me, SPELL_UNTAMED_FURY, false);
                            events.ScheduleEvent(EVENT_UNTAMED_FURY,      20000);
                            break;
                        case EVENT_HATED_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HATED_BLAST, false);
                            events.ScheduleEvent(EVENT_HATED_BLAST, 20000);
                            break;
                        case EVENT_SHA_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHA_CORRUPTION, false);
                            events.ScheduleEvent(EVENT_SHA_CORRUPTION, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_spirit_of_violenceAI(creature);
        }
};

// Spirit of Anger - 64684
class mob_spirit_of_anger : public CreatureScript
{
    public:
        mob_spirit_of_anger() : CreatureScript("mob_spirit_of_anger") {}

        struct mob_spirit_of_angerAI : public ScriptedAI
        {
            mob_spirit_of_angerAI(Creature* creature) : ScriptedAI(creature)
            {
                xuenGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid xuenGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATION, 3000);
                events.ScheduleEvent(EVENT_HATED_BLAST, 12000);
                events.ScheduleEvent(EVENT_SHA_CORRUPTION, 23000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* xuen = me->GetMap()->GetCreature(xuenGUID);
                if (!xuen || !xuen->GetAI())
                    return;

                xuen->AI()->SetData(XUEN_PHASE_3, DONE);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if(me->HealthBelowPctDamaged(20, damage))
                {
                    me->SummonCreature(MOB_SPIRIT_OF_VIOLENCE, 3778.698f, 539.101f, 639.007f);
                }
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                xuenGUID = summoner->GetGUID();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEVASTATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEVASTATION, false);
                            events.ScheduleEvent(EVENT_DEVASTATION,      20000);
                            break;
                        case EVENT_HATED_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HATED_BLAST, false);
                            events.ScheduleEvent(EVENT_HATED_BLAST, 20000);
                            break;
                        case EVENT_SHA_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHA_CORRUPTION, false);
                            events.ScheduleEvent(EVENT_SHA_CORRUPTION, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_spirit_of_angerAI(creature);
        }
};

// Spirit of Hatred - 64742/64744
class mob_spirit_of_hatred : public CreatureScript
{
    public:
        mob_spirit_of_hatred() : CreatureScript("mob_spirit_of_hatred") {}

        struct mob_spirit_of_hatredAI : public ScriptedAI
        {
            mob_spirit_of_hatredAI(Creature* creature) : ScriptedAI(creature)
            {
                xuenGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid xuenGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UNTAMED_FURY, 3000);
                events.ScheduleEvent(EVENT_HATED_BLAST, 12000);
                events.ScheduleEvent(EVENT_SHA_CORRUPTION, 23000);
                events.ScheduleEvent(EVENT_WHIRLWIND_OF_ANGER, 32000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* xuen = me->GetMap()->GetCreature(xuenGUID);
                if (!xuen || !xuen->GetAI())
                    return;

                xuen->AI()->SetData(XUEN_PHASE_4, DONE);
                xuen->AI()->DoAction(ACTION_FINAL_KILL_CREDIT);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                xuenGUID = summoner->GetGUID();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEVASTATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEVASTATION, false);
                            events.ScheduleEvent(EVENT_DEVASTATION, 20000);
                            break;
                        case EVENT_HATED_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HATED_BLAST, false);
                            events.ScheduleEvent(EVENT_HATED_BLAST, 20000);
                            break;
                        case EVENT_SHA_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHA_CORRUPTION, false);
                            events.ScheduleEvent(EVENT_SHA_CORRUPTION, 20000);
                            break;
                        case EVENT_WHIRLWIND_OF_ANGER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_WHIRLWIND_OF_ANGER, false);
                            events.ScheduleEvent(EVENT_WHIRLWIND_OF_ANGER, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_spirit_of_hatredAI(creature);
        }
};

// Xuen - 60968
class npc_questgiver_xuen : public CreatureScript
{
    public:
        npc_questgiver_xuen() : CreatureScript("npc_questgiver_xuen") {}

        bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case 30880:
                    player->SummonCreature(60994, 3455.440f, 396.495f, 587.990f, 3.534870f);
                    break;
                case 30879:
                    player->SummonCreature(60996, 3455.440f, 396.495f, 587.990f, 3.534870f);
                    break;
                case 30882:
                    player->SummonCreature(60978, 3727.387f, 354.103f, 596.644f, 2.873523f);
                    break;
                case 30881:
                    player->SummonCreature(60980, 3727.387f, 354.103f, 596.644f, 2.873523f);
                    player->SummonCreature(60979, 3732.874f, 356.998f, 596.645f, 3.010161f);
                    break;
                case 30883:
                    player->SummonCreature(60997, 3678.923f, 668.206f, 636.749f, 4.385365f);
                    break;
                case 30885:
                    player->SummonCreature(61013, 3678.923f, 668.206f, 636.749f, 4.385365f);
                    break;
                case 30902:
                    player->SummonCreature(61012, 3795.768f, 533.490f, 639.007f, 2.990473f);
                    break;
                case 30907:
                    player->SummonCreature(61006, 3795.768f, 533.490f, 639.007f, 2.990473f);
                    player->SummonCreature(61004, 3794.767f, 524.924f, 639.007f, 2.990473f);
                    player->SummonCreature(61007, 3796.669f, 542.368f, 639.007f, 2.990473f);
                    break;
                default:
                    break;
            }

            return true;
        }
};

// Lun-Chi - 60994
class mob_lun_chi : public CreatureScript
{
    public:
        mob_lun_chi() : CreatureScript("mob_lun_chi") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30880) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_lun_chiAI : public ScriptedAI
        {
            mob_lun_chiAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_TORPEDO, 3000);
                events.ScheduleEvent(EVENT_KNOCKDOWN, 12000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 23000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30880) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60994);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30880) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHI_TORPEDO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CHI_TORPEDO, false);
                            events.ScheduleEvent(EVENT_CHI_TORPEDO, 28000);
                            break;
                        case EVENT_KNOCKDOWN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_KNOCKDOWN, false);
                            events.ScheduleEvent(EVENT_KNOCKDOWN, 28000);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 28000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_lun_chiAI(creature);
        }
};

// Brewmaster Chani - 60996
class mob_brewmaster_chani : public CreatureScript
{
    public:
        mob_brewmaster_chani() : CreatureScript("mob_brewmaster_chani") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30879) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_brewmaster_chaniAI : public ScriptedAI
        {
            mob_brewmaster_chaniAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BITTER_BREW, 3000);
                events.ScheduleEvent(EVENT_THE_STEAMER, 12000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30879) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60996);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30879) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BITTER_BREW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BITTER_BREW, false);
                            events.ScheduleEvent(EVENT_BITTER_BREW, 18000);
                            break;
                        case EVENT_THE_STEAMER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_THE_STEAMER, false);
                            events.ScheduleEvent(EVENT_THE_STEAMER, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_brewmaster_chaniAI(creature);
        }
};

// Kang Bramblestaff - 60978
class mob_kang_bramblestaff : public CreatureScript
{
    public:
        mob_kang_bramblestaff() : CreatureScript("mob_kang_bramblestaff") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30882) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_kang_bramblestaffAI : public ScriptedAI
        {
            mob_kang_bramblestaffAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, 3000);
                events.ScheduleEvent(EVENT_KNOCKDOWN, 12000);
                events.ScheduleEvent(EVENT_WHIRLWIND, 20000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30882) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60978);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30882) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_FROM_ABOVE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEATH_FROM_ABOVE, false);
                            events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, 25000);
                            break;
                        case EVENT_KNOCKDOWN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_KNOCKDOWN, false);
                            events.ScheduleEvent(EVENT_KNOCKDOWN, 25000);
                            break;
                        case EVENT_WHIRLWIND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_WHIRLWIND, false);
                            events.ScheduleEvent(EVENT_WHIRLWIND, 25000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kang_bramblestaffAI(creature);
        }
};

// Clever Ashyo - 60980
class mob_clever_ashyo : public CreatureScript
{
    public:
        mob_clever_ashyo() : CreatureScript("mob_clever_ashyo") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30881) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* kenKen = GetClosestCreatureWithEntry(creature, 60979, 20.0f, true))
                    {
                        creature->SetFaction(14);
                        kenKen->SetFaction(14);

                        if (creature->GetAI())
                        {
                            creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                            creature->AI()->Reset();
                            creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                        }

                        if (kenKen->GetAI())
                        {
                            kenKen->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                            kenKen->AI()->Reset();
                            kenKen->AI()->DoAction(ACTION_REMOVE_FLAG);
                        }
                    }
                }
            }
            return true;
        }

        struct mob_clever_ashyoAI : public ScriptedAI
        {
            mob_clever_ashyoAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

//                events.ScheduleEvent(EVENT_HEALING_SPHERE, 3000);
                events.ScheduleEvent(EVENT_WATER_SPOUT, 12000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30881) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60980);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void EnterCombat(Unit* victim) override
            {
                if (Creature* kenKen = GetClosestCreatureWithEntry(me, 60979, 20.0f, true))
                {
                    if (kenKen->GetAI())
                    {
                        kenKen->AI()->AttackStart(victim);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30881) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEALING_SPHERE:
                            me->CastSpell(me, SPELL_HEALING_SPHERE, false);
                            events.ScheduleEvent(EVENT_HEALING_SPHERE, 18000);
                            break;
                        case EVENT_WATER_SPOUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_WATER_SPOUT, false);
                            events.ScheduleEvent(EVENT_WATER_SPOUT, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_clever_ashyoAI(creature);
        }
};

// Ken-Ken - 60979
class mob_ken_ken : public CreatureScript
{
    public:
        mob_ken_ken() : CreatureScript("mob_ken_ken") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30881) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* ashyo = GetClosestCreatureWithEntry(creature, 60980, 20.0f, true))
                    {
                        creature->SetFaction(14);
                        ashyo->SetFaction(14);

                        if (creature->GetAI())
                        {
                            creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                            creature->AI()->Reset();
                            creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                        }

                        if (ashyo->GetAI())
                        {
                            ashyo->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                            ashyo->AI()->Reset();
                            ashyo->AI()->DoAction(ACTION_REMOVE_FLAG);
                        }
                    }
                }
            }
            return true;
        }

        struct mob_ken_kenAI : public ScriptedAI
        {
            mob_ken_kenAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_ENRAGE, 3000);
                events.ScheduleEvent(EVENT_KEN_KEN_RAMPAGE, 12000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30881) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60979);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void EnterCombat(Unit* victim) override
            {
                if (Creature* ashyo = GetClosestCreatureWithEntry(me, 60980, 20.0f, true))
                {
                    if (ashyo->GetAI())
                    {
                        ashyo->AI()->AttackStart(victim);
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30881) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            me->CastSpell(me, SPELL_ENRAGE, false);
                            events.ScheduleEvent(EVENT_ENRAGE, 18000);
                            break;
                        case EVENT_KEN_KEN_RAMPAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_KEN_KEN_RAMPAGE, false);
                            events.ScheduleEvent(EVENT_KEN_KEN_RAMPAGE, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ken_kenAI(creature);
        }
};

// The Wrestler - 60997
class mob_the_wrestler : public CreatureScript
{
    public:
        mob_the_wrestler() : CreatureScript("mob_the_wrestler") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30883) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_the_wrestlerAI : public ScriptedAI
        {
            mob_the_wrestlerAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GRAPPLE_OPPONENT, 3000);
                events.ScheduleEvent(EVENT_SLING_SWEAT, 12000);
                events.ScheduleEvent(EVENT_VULNERABLE, 43000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30883) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60997);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30883) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRAPPLE_OPPONENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GRAPPLE_OPPONENT, false);
                            events.ScheduleEvent(EVENT_GRAPPLE_OPPONENT, 25000);
                            break;
                        case EVENT_SLING_SWEAT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SLING_SWEAT, false);
                            events.ScheduleEvent(EVENT_SLING_SWEAT, 25000);
                            break;
                        case EVENT_VULNERABLE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_VULNERABLE, false);
                            events.ScheduleEvent(EVENT_VULNERABLE, 50000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_the_wrestlerAI(creature);
        }
};

// Master Boom Boom - 61013
class mob_master_boom_boom : public CreatureScript
{
    public:
        mob_master_boom_boom() : CreatureScript("mob_master_boom_boom") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30885) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_master_boom_boomAI : public ScriptedAI
        {
            mob_master_boom_boomAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_HEAVY_DYNAMITE, 3000);
                events.ScheduleEvent(EVENT_TOSS_A_BOOM_BOOM, 12000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30885) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(61013);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30885) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEAVY_DYNAMITE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HEAVY_DYNAMITE, false);
                            events.ScheduleEvent(EVENT_HEAVY_DYNAMITE, 18000);
                            break;
                        case EVENT_TOSS_A_BOOM_BOOM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TOSS_A_BOOM_BOOM, false);
                            events.ScheduleEvent(EVENT_TOSS_A_BOOM_BOOM, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_master_boom_boomAI(creature);
        }
};

// Master Windfur - 61012
class mob_master_windfur : public CreatureScript
{
    public:
        mob_master_windfur() : CreatureScript("mob_master_windfur") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30902) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_master_windfurAI : public ScriptedAI
        {
            mob_master_windfurAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_WIND_SWORD, 3000);
                // events.ScheduleEvent(EVENT_WINDFUR_PUNCH, 12000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30902) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(61012);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30902) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WIND_SWORD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WIND_SWORD, false);
                            events.ScheduleEvent(EVENT_WIND_SWORD, 18000);
                            break;
                        case EVENT_WINDFUR_PUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WINDFUR_PUNCH, false);
                            events.ScheduleEvent(EVENT_WINDFUR_PUNCH, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_master_windfurAI(creature);
        }
};

// Tankiss - 61006
class mob_tankiss : public CreatureScript
{
    public:
        mob_tankiss() : CreatureScript("mob_tankiss") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* healiss = GetClosestCreatureWithEntry(creature, 61004, 20.0f, true))
                    {
                        if (Creature* hackiss = GetClosestCreatureWithEntry(creature, 61007, 20.0f, true))
                        {
                            creature->SetFaction(14);
                            healiss->SetFaction(14);
                            hackiss->SetFaction(14);

                            if (creature->GetAI())
                            {
                                creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                creature->AI()->Reset();
                                creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (healiss->GetAI())
                            {
                                healiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                healiss->AI()->Reset();
                                healiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (hackiss->GetAI())
                            {
                                hackiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                hackiss->AI()->Reset();
                                hackiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }
                        }
                    }
                }
            }
            return true;
        }

        struct mob_tankissAI : public ScriptedAI
        {
            mob_tankissAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_FLAY, 3000);
                events.ScheduleEvent(EVENT_FULL_CONTACT_INTERVENE, 12000);
                events.ScheduleEvent(EVENT_GROUND_PUMMEL, 18000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(61006);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void EnterCombat(Unit* victim) override
            {
                if (Creature* healiss = GetClosestCreatureWithEntry(me, 61004, 20.0f, true))
                {
                    healiss->AI()->AttackStart(victim);
                }
                if (Creature* hackiss = GetClosestCreatureWithEntry(me, 61007, 20.0f, true))
                {
                    hackiss->AI()->AttackStart(victim);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30907) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLAY:
                            me->CastSpell(me, SPELL_FLAY, false);
                            events.ScheduleEvent(EVENT_FLAY, 25000);
                            break;
                        case EVENT_FULL_CONTACT_INTERVENE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FULL_CONTACT_INTERVENE, false);
                            events.ScheduleEvent(EVENT_FULL_CONTACT_INTERVENE, 25000);
                            break;
                        case EVENT_GROUND_PUMMEL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_GROUND_PUMMEL, false);
                            events.ScheduleEvent(EVENT_GROUND_PUMMEL, 25000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_tankissAI(creature);
        }
};

// Healiss - 61004
class mob_healiss : public CreatureScript
{
    public:
        mob_healiss() : CreatureScript("mob_healiss") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* tankiss = GetClosestCreatureWithEntry(creature, 61006, 20.0f, true))
                    {
                        if (Creature* hackiss = GetClosestCreatureWithEntry(creature, 61007, 20.0f, true))
                        {
                            creature->SetFaction(14);
                            tankiss->SetFaction(14);
                            hackiss->SetFaction(14);

                            if (creature->GetAI())
                            {
                                creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                creature->AI()->Reset();
                                creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (tankiss->GetAI())
                            {
                                tankiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                tankiss->AI()->Reset();
                                tankiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (hackiss->GetAI())
                            {
                                hackiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                hackiss->AI()->Reset();
                                hackiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }
                        }
                    }
                }
            }
            return true;
        }

        struct mob_healissAI : public ScriptedAI
        {
            mob_healissAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                // events.ScheduleEvent(EVENT_HEALISS_OIL, 3000);
                // events.ScheduleEvent(EVENT_JUNGE_REMEDY, 12000);
                events.ScheduleEvent(EVENT_MIND_FLAY, 18000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(61004);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void EnterCombat(Unit* victim) override
            {
                if (Creature* tankiss = GetClosestCreatureWithEntry(me, 61006, 20.0f, true))
                {
                    tankiss->AI()->AttackStart(victim);
                }
                if (Creature* hackiss = GetClosestCreatureWithEntry(me, 61007, 20.0f, true))
                {
                    hackiss->AI()->AttackStart(victim);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30907) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEALISS_OIL:
                            me->CastSpell(me, SPELL_HEALISS_OIL, false);
                            events.ScheduleEvent(EVENT_HEALISS_OIL, 25000);
                            break;
                        case EVENT_JUNGE_REMEDY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_JUNGE_REMEDY, false);
                            events.ScheduleEvent(EVENT_JUNGE_REMEDY, 25000);
                            break;
                        case EVENT_MIND_FLAY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_MIND_FLAY, false);
                            events.ScheduleEvent(EVENT_MIND_FLAY, 25000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_healissAI(creature);
        }
};

// Hackiss - 61007
class mob_hackiss : public CreatureScript
{
    public:
        mob_hackiss() : CreatureScript("mob_hackiss") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* healiss = GetClosestCreatureWithEntry(creature, 61004, 20.0f, true))
                    {
                        if (Creature* tankiss = GetClosestCreatureWithEntry(creature, 61006, 20.0f, true))
                        {
                            creature->SetFaction(14);
                            healiss->SetFaction(14);
                            tankiss->SetFaction(14);

                            if (creature->GetAI())
                            {
                                creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                creature->AI()->Reset();
                                creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (healiss->GetAI())
                            {
                                healiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                healiss->AI()->Reset();
                                healiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }

                            if (tankiss->GetAI())
                            {
                                tankiss->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                                tankiss->AI()->Reset();
                                tankiss->AI()->DoAction(ACTION_REMOVE_FLAG);
                            }
                        }
                    }
                }
            }
            return true;
        }

        struct mob_hackissAI : public ScriptedAI
        {
            mob_hackissAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_HEALISS_OIL, 3000);
//                events.ScheduleEvent(EVENT_JUNGE_REMEDY, 12000);
                events.ScheduleEvent(EVENT_MIND_FLAY, 18000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30907) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(61007);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void EnterCombat(Unit* victim) override
            {
                if (Creature* healiss = GetClosestCreatureWithEntry(me, 61004, 20.0f, true))
                {
                    healiss->AI()->AttackStart(victim);
                }
                if (Creature* tankiss = GetClosestCreatureWithEntry(me, 61006, 20.0f, true))
                {
                    tankiss->AI()->AttackStart(victim);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (player->GetQuestStatus(30907) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACID_SPLIT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_ACID_SPLIT, false);
                            events.ScheduleEvent(EVENT_ACID_SPLIT, 25000);
                            break;
                        case EVENT_BACKSTAB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_BACKSTAB, false);
                            events.ScheduleEvent(EVENT_BACKSTAB, 25000);
                            break;
                        case EVENT_VILE_SPITTLE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_VILE_SPITTLE, false);
                            events.ScheduleEvent(EVENT_VILE_SPITTLE, 25000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_hackissAI(creature);
        }
};

void AddSC_kun_lai_summit()
{
    new mob_nessos_the_oracle();
    new mob_ski_thik();
    new mob_havak();
    new mob_mogujia_soul_caller();
    new mob_quilen_stonemaw();
    new mob_zai_the_outcast();
    new mob_zhi_the_harmonious();
    new mob_andruin_wrynn();
    new mob_taran_zhu_white_tiger();
    new npc_xuen();
    new mob_spirit_of_violence();
    new mob_spirit_of_anger();
    new mob_spirit_of_hatred();
    new npc_questgiver_xuen();
    new mob_lun_chi();
    new mob_brewmaster_chani();
    new mob_kang_bramblestaff();
    new mob_clever_ashyo();
    new mob_ken_ken();
    new mob_the_wrestler();
    new mob_master_boom_boom();
    new mob_master_windfur();
    new mob_tankiss();
    new mob_healiss();
    new mob_hackiss();
}
