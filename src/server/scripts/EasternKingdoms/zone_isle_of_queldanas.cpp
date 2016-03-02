/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Isle_of_Queldanas
SD%Complete: 100
SDComment: Quest support: 11541,24535,24563
SDCategory: Isle Of Quel'Danas
EndScriptData */

/* ContentData
npc_greengill_slave
npc_thalorien_dawnseeker
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "SpellInfo.h"

/*######
## npc_greengill_slave
######*/

enum GreengillSlave
{
    NPC_DARKSPINE_MYRIDON       = 25060,
    QUEST_GREENGILL_COAST       = 11541,
    SPELL_ENRAGE                = 45111,
    SPELL_ORB_MURLOC_CONTROL    = 45109,
    SPELL_GREENGILL_SLAVE_FREED = 45110
};

class npc_greengill_slave : public CreatureScript
{
public:
    npc_greengill_slave() : CreatureScript("npc_greengill_slave") { }

    struct npc_greengill_slaveAI : public ScriptedAI
    {
        npc_greengill_slaveAI(Creature* creature) : ScriptedAI(creature) { }

        void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
        {
            Player* player = caster->ToPlayer();

            if (!player)
                return;

            if (spellInfo->Id == SPELL_ORB_MURLOC_CONTROL && !me->HasAura(SPELL_ENRAGE))
            {
                if (player->GetQuestStatus(QUEST_GREENGILL_COAST) == QUEST_STATUS_INCOMPLETE)
                    DoCast(player, SPELL_GREENGILL_SLAVE_FREED, true);

                DoCast(me, SPELL_ENRAGE);

                if (Creature* Myrmidon = me->FindNearestCreature(NPC_DARKSPINE_MYRIDON, 70))
                {
                    me->AddThreat(Myrmidon, 100000.0f);
                    AttackStart(Myrmidon);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_greengill_slaveAI(creature);
    }
};

/*######
## npc_thalorien_dawnseeker
######*/

enum ThalorienDawnseekerSays
{
    SAY_THALORIEN_1 = 0,
    SAY_THALORIEN_2 = 1,
    SAY_THALORIEN_3 = 2,
    SAY_THALORIEN_4 = 3,
    SAY_THALORIEN_5 = 4,
    SAY_THALORIEN_6 = 5,
    SAY_THALORIEN_7 = 6,
    SAY_THALORIEN_8 = 7,
    SAY_THALORIEN_9 = 8,
    SAY_THALORIEN_10 = 9
};

enum MorlenSays
{
    SAY_MORLEN_1 = 0,
    SAY_MORLEN_2 = 1,
    SAY_MORLEN_3 = 2,
    SAY_MORLEN_4 = 3,
    SAY_MORLEN_5 = 4
};

enum ThalorienDawnseekerCreatures
{
    NPC_THALORIEN_DAWNSEEKER    = 37205,
    NPC_MORLEN_GOLDGRIP         = 37542,
    NPC_QUEST_CREDIT            = 37601,
    NPC_SUNWELL_DEFENDER        = 37211,
    NPC_SCOURGE_ZOMBIE          = 37538,
    NPC_GHOUL_INVADER           = 37539,
    NPC_CRYPT_RAIDER            = 37541
};

enum ThalorienDawnseekerActions
{
    ACTION_START_QUEST = 1
};

enum ThalorienDawnseekerEvents
{
    EVENT_STEP_1    = 1,
    EVENT_STEP_2    = 2,
    EVENT_STEP_3    = 3,
    EVENT_STEP_4    = 4,
    EVENT_STEP_5    = 5,
    EVENT_STEP_6    = 6,
    EVENT_STEP_7    = 7,
    EVENT_STEP_8    = 8,
    EVENT_STEP_9    = 9,
    EVENT_STEP_10   = 10,
    EVENT_STEP_11   = 11,
    EVENT_STEP_12   = 12,
    EVENT_STEP_13   = 13,
    EVENT_STEP_14   = 14,
    EVENT_STEP_15   = 15,
    EVENT_STEP_16   = 16,
    EVENT_STEP_17   = 17,
    EVENT_STEP_18   = 18,
    EVENT_STEP_19   = 19
};

enum ThalorienDawnseekerMisc
{
    OPTION_ID_REMAINS       = 0,
    DISPLAY_MOUNT           = 25678,
    QUEST_THALORIEN_A       = 24535,
    QUEST_THALORIEN_H       = 24563,
    GOSSIP_MENU_ID_REMAINS  = 37552,
    SPELL_BLOOD_PRESENCE    = 50689
};

Position const ZombieLoc[5] =
{
    { 11768.7f, -7065.83f, 24.0971f, 0.125877f },
    { 11769.5f, -7063.83f, 24.1399f, 6.06035f },
    { 11769.8f, -7061.41f, 24.2536f, 6.06035f },
    { 11769.4f, -7057.86f, 24.4624f, 0.00335493f },
    { 11769.4f, -7054.56f, 24.6869f, 0.00335493f }
};

Position const GuardLoc[4] =
{
    { 11807.0f, -7070.37f, 25.372f, 3.218f },
    { 11805.7f, -7073.64f, 25.5694f, 3.218f },
    { 11805.6f, -7077.0f, 25.9643f, 3.218f },
    { 11806.0f, -7079.71f, 26.2067f, 3.218f }
};

class npc_thalorien_dawnseeker : public CreatureScript
{
    public:
        npc_thalorien_dawnseeker() : CreatureScript("npc_thalorien_dawnseeker") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            player->PrepareGossipMenu(creature, 0);

            if ((player->GetQuestStatus(QUEST_THALORIEN_A) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(QUEST_THALORIEN_H) == QUEST_STATUS_INCOMPLETE))
                player->ADD_GOSSIP_ITEM_DB(GOSSIP_MENU_ID_REMAINS, OPTION_ID_REMAINS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SendPreparedGossip(creature);
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CLOSE_GOSSIP_MENU();
                creature->AI()->SetGUID(player->GetGUID());
                creature->SetPhaseMask(2, true);
                player->SetPhaseMask(2, true); // Better handling if we find the correct Phasing-Spell
                creature->AI()->DoAction(ACTION_START_QUEST);
                break;
            default:
                return false;
            }
            return true;
        }

        struct npc_thalorien_dawnseekerAI : public ScriptedAI
        {
            npc_thalorien_dawnseekerAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayer))
                    player->SetPhaseMask(1, true);
                if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                    Morlen->DisappearAndDie();
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->SetPhaseMask(1, true);
                events.Reset();
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                case EVENT_STEP_1:
                    if (Creature* Thalorien = me->SummonCreature(NPC_THALORIEN_DAWNSEEKER, 11797.0f, -7074.06f, 26.379f, 0.242908f, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        Thalorien->SetPhaseMask(2, true);
                        uiThalorien = Thalorien->GetGUID();
                    }

                    for (int i = 0; i < 4; ++i)
                        if (Creature* Guard = me->SummonCreature(NPC_SUNWELL_DEFENDER, GuardLoc[i], TEMPSUMMON_TIMED_DESPAWN, 30000))
                            Guard->SetPhaseMask(2, true);

                    if (Creature* Morlen = me->SummonCreature(NPC_MORLEN_GOLDGRIP, 11776.8f, -7050.72f, 25.2394f, 5.13752f, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        Morlen->Mount(DISPLAY_MOUNT);
                        Morlen->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        Morlen->SetPhaseMask(2, true);
                        Morlen->SetReactState(REACT_PASSIVE);
                        uiMorlen = Morlen->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_STEP_2, 0.1 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_2:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_1);
                    events.ScheduleEvent(EVENT_STEP_3, 5 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_3:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_2);
                    events.ScheduleEvent(EVENT_STEP_4, 5 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_4:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_3);
                    events.ScheduleEvent(EVENT_STEP_5, 10 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_5:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_4);
                    events.ScheduleEvent(EVENT_STEP_6, 6 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_6:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->GetMotionMaster()->MovePoint(0, 11787.3f, -7064.11f, 25.8395f);
                    events.ScheduleEvent(EVENT_STEP_7, 6 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_7:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_5);
                    events.ScheduleEvent(EVENT_STEP_8, 9 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_8:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_6);
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->CastSpell(Morlen, SPELL_BLOOD_PRESENCE, true);
                    events.ScheduleEvent(EVENT_STEP_9, 9 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_9:
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->AI()->Talk(SAY_MORLEN_1);
                    events.ScheduleEvent(EVENT_STEP_10, 9 * IN_MILLISECONDS);
                    break;
                    // Intro 
                case EVENT_STEP_10:
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->AI()->Talk(SAY_MORLEN_2);
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->SetHomePosition(Thalorien->GetPositionX(), Thalorien->GetPositionY(), Thalorien->GetPositionZ(), Thalorien->GetOrientation());
                    SummonWave(NPC_SCOURGE_ZOMBIE);
                    events.ScheduleEvent(EVENT_STEP_11, 30 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_11:
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->AI()->Talk(SAY_MORLEN_3);
                    SummonWave(NPC_GHOUL_INVADER);
                    events.ScheduleEvent(EVENT_STEP_12, 30 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_12:
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->AI()->Talk(SAY_MORLEN_4);
                    SummonWave(NPC_CRYPT_RAIDER);
                    events.ScheduleEvent(EVENT_STEP_13, 30 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_13:
                    if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        Morlen->AI()->Talk(SAY_MORLEN_5);
                    events.ScheduleEvent(EVENT_STEP_14, 1 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_14:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                    {
                        if (Creature* Morlen = ObjectAccessor::GetCreature(*me, uiMorlen))
                        {
                            Morlen->SetReactState(REACT_AGGRESSIVE);
                            Morlen->AddThreat(Thalorien, 100);
                            Morlen->AI()->AttackStart(Thalorien);
                            Morlen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                    }
                    break;
                    // Outro
                case EVENT_STEP_15:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_7);
                    events.ScheduleEvent(EVENT_STEP_16, 5 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_16:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_8);
                    events.ScheduleEvent(EVENT_STEP_17, 5 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_17:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_9);
                    events.ScheduleEvent(EVENT_STEP_18, 6 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_18:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->AI()->Talk(SAY_THALORIEN_10);
                    events.ScheduleEvent(EVENT_STEP_19, 12 * IN_MILLISECONDS);
                    break;
                case EVENT_STEP_19:
                    if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                        Thalorien->DisappearAndDie();
                    if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayer))
                        player->KilledMonsterCredit(NPC_QUEST_CREDIT, player->GetGUID());
                    Reset();
                    break;
                default:
                    break;
                }

                DoMeleeAttackIfReady();
            }

            void SummonWave(uint32 entry)
            {
                if (Creature* Thalorien = ObjectAccessor::GetCreature(*me, uiThalorien))
                {
                    for (int i = 0; i < 5; ++i)
                        if (Creature* Zombie = me->SummonCreature(entry, ZombieLoc[i], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
                        {
                            Zombie->SetPhaseMask(2, true);
                            Zombie->AddThreat(Thalorien, 100.0f);
                            Zombie->AI()->AttackStart(Thalorien);
                        }
                }
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                if (summon->GetEntry() == NPC_THALORIEN_DAWNSEEKER)
                {
                    Reset();
                    return;
                }

                if (summon->GetEntry() == NPC_MORLEN_GOLDGRIP)
                    events.ScheduleEvent(EVENT_STEP_15, 3 * IN_MILLISECONDS);
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/) override
            {
                uiPlayer = guid;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                case ACTION_START_QUEST:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    events.ScheduleEvent(EVENT_STEP_1, 0);
                    break;
                }
            }
        private:
            EventMap events;
            ObjectGuid uiThalorien;
            ObjectGuid uiPlayer;
            ObjectGuid uiMorlen;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thalorien_dawnseekerAI(creature);
        }
};

void AddSC_isle_of_queldanas()
{
    new npc_greengill_slave();
    new npc_thalorien_dawnseeker();
}
