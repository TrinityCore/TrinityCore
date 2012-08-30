/*
* Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2012 Rising Gods <http://www.rising-gods.de/>
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

#include "event.h"
#include "ScriptPCH.h"
#include "Group.h"

enum eMatrons
{
    //Start quests
    QUEST_BACK_TO_THE_ORPHANAGE_WOLVAR          = 13960,
    QUEST_BACK_TO_THE_ORPHANAGE_ORACLE          = 13959,
    QUEST_BACK_TO_THE_ORPHANAGE_A               = 10966,
    QUEST_BACK_TO_THE_ORPHANAGE_H               = 10967,
    QUEST_CHILDRENS_WEEK_SW                     = 1468,
    QUEST_CHILDRENS_WEEK_OG                     = 172,

    //End quests
    QUEST_CHILDRENS_WEEK_A                      = 10943,
    QUEST_CHILDRENS_WEEK_H                      = 10942,   
    QUEST_LITTLE_ORPHAN_KEKEK_OF_THE_WOLVAR     = 13927,
    QUEST_LITTLE_ORPHAN_ROO_OF_THE_ORACLES      = 13926,
    QUEST_A_WARDEN_OF_THE_ALLIANCE              = 171,
    QUEST_A_WARDEN_OF_THE_HORDE                 = 5502,

    //Quest giver gossips
    GOSSIP_TEXT_WOLVAR                          = 2002011,
    GOSSIP_TEXT_ORACLE                          = 2002010,   

    //Items
    ITEM_WOLVAR_ORPHAN_WHISTLE                  = 46396,
    ITEM_ORACLE_ORPHAN_WHISTLE                  = 46397,
    ITEM_BLOOD_ELF_ORPHAN_WHISTLE               = 31880,
    ITEM_DRAENEI_ORPHAN_WHISTLE                 = 31881,
    ITEM_HUMAN_ORPHAN_WHISTLE                   = 18598,
    ITEM_ORCISH_ORPHAN_WHISTLE                  = 18597,

    //Item create spells
    SPELL_CREATE_WOLVAR_ORPHAN_WHISTLE          = 65360,
    SPELL_CREATE_ORACLE_ORPHAN_WHISTLE          = 65359,
    SPELL_CREATE_BLOOD_ELF_ORPHAN_WHISTLE       = 39512,
    SPELL_CREATE_DRAENEI_ORPHAN_WHISTLE         = 39513,
    SPELL_CREATE_HUMAN_ORPHAN_WHISTLE           = 23124,
    SPELL_CREATE_ORCISH_ORPHAN_WHISTLE          = 23125,
};

//Gossip menu options
#define GOSSIP_SELECT_WOLVAR        "Gebt mir eine neue Pfeife des Wolvarwaisenkindes, bitte."
#define GOSSIP_SELECT_ORACLE        "Gebt mir eine neue Pfeife des Orakelwaisenkindes, bitte."
#define GOSSIP_SELECT_BLOOD_ELF     "Gebt mir eine neue Pfeife des Blutelfenwaisenkindes, bitte."
#define GOSSIP_SELECT_DRAENEI       "Gebt mir eine neue Pfeife des Draeneiwaisenkindes, bitte."
#define GOSSIP_SELECT_HUMAN         "Gebt mir eine neue Pfeife des Menschenwaisenkindes, bitte."
#define GOSSIP_SELECT_ORC           "Gebt mir eine neue Pfeife des Orcwaisenkindes, bitte."

#define GOSSIP_SELECT_WOLVAR_START  "Ich hätte gerne ein Waisenkind der Wolvar."
#define GOSSIP_SELECT_ORACLE_START  "Ich hätte gerne ein Waisenkind der Orakel."
#define GOSSIP_SELECT_ANSWER        "Ja, ich bin mir der Verantwortung bewusst."

/*######
## npc_orphan_matron_aria
######*/
class npc_orphan_matron_aria : public CreatureScript
{
    public:
        npc_orphan_matron_aria() : CreatureScript("npc_orphan_matron_aria") {}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            if (!player || !creature)
                return false;

            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    creature->CastSpell(player, SPELL_CREATE_WOLVAR_ORPHAN_WHISTLE, false);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    creature->CastSpell(player, SPELL_CREATE_ORACLE_ORPHAN_WHISTLE, false);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    player->PlayerTalkClass->ClearMenus();
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_ANSWER,GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXT_WOLVAR, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    player->PlayerTalkClass->ClearMenus();
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_ANSWER,GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 41);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXT_ORACLE, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 31:
                    creature->CastSpell(player, SPELL_CREATE_WOLVAR_ORPHAN_WHISTLE, false);
                    player->KilledMonsterCredit(34365, 0);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 41:
                    creature->CastSpell(player, SPELL_CREATE_ORACLE_ORPHAN_WHISTLE, false);
                    player->KilledMonsterCredit(34365, 0);
                    player->CLOSE_GOSSIP_MENU();
                    break;
            }

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!player || !creature)
                return false;

            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (IsHolidayActive(HOLIDAY_CHILDRENS_WEEK))
            {
                if (player->GetQuestStatus(QUEST_LITTLE_ORPHAN_KEKEK_OF_THE_WOLVAR) != QUEST_STATUS_NONE
                    && player->GetQuestStatus(QUEST_LITTLE_ORPHAN_KEKEK_OF_THE_WOLVAR) != QUEST_STATUS_INCOMPLETE
                    && !player->HasItemCount(ITEM_WOLVAR_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_WOLVAR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

                if (player->GetQuestStatus(QUEST_LITTLE_ORPHAN_ROO_OF_THE_ORACLES) != QUEST_STATUS_NONE
                    && player->GetQuestStatus(QUEST_LITTLE_ORPHAN_ROO_OF_THE_ORACLES) != QUEST_STATUS_INCOMPLETE
                    && !player->HasItemCount(ITEM_ORACLE_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_ORACLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

                if (player->GetQuestStatus(QUEST_LITTLE_ORPHAN_KEKEK_OF_THE_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_WOLVAR_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

                if (player->GetQuestStatus(QUEST_LITTLE_ORPHAN_ROO_OF_THE_ORACLES) == QUEST_STATUS_INCOMPLETE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_ORACLE_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            }

            player->SEND_GOSSIP_MENU(14534, creature->GetGUID());

            return true;
        }

        bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/)
        {
            if (!player)
                return false;

            std::list<Creature*> MinionList;

            switch (quest->GetQuestId())
            {
                case QUEST_BACK_TO_THE_ORPHANAGE_WOLVAR:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);
                    break;
                case QUEST_BACK_TO_THE_ORPHANAGE_ORACLE:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_ORACLE);
                    break;
            }

            if (!MinionList.empty())
                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            return true;
        }

};


/*######
## npc_orphan_matron_mercy
######*/
class npc_orphan_matron_mercy : public CreatureScript
{
    public:
        npc_orphan_matron_mercy() : CreatureScript("npc_orphan_matron_mercy") {}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            if (!player || !creature)
                return false;

            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    creature->CastSpell(player, SPELL_CREATE_DRAENEI_ORPHAN_WHISTLE, false);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    creature->CastSpell(player, SPELL_CREATE_BLOOD_ELF_ORPHAN_WHISTLE, false);
                    break;
            }

            player->CLOSE_GOSSIP_MENU();

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!player || !creature)
                return false;

            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (IsHolidayActive(HOLIDAY_CHILDRENS_WEEK))
            {
                if (player->GetQuestStatus(QUEST_CHILDRENS_WEEK_A) != QUEST_STATUS_NONE 
                    && !player->HasItemCount(ITEM_DRAENEI_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_DRAENEI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

                if (player->GetQuestStatus(QUEST_CHILDRENS_WEEK_H) != QUEST_STATUS_NONE 
                    && !player->HasItemCount(ITEM_BLOOD_ELF_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_BLOOD_ELF, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }

            player->SEND_GOSSIP_MENU(10744, creature->GetGUID());

            return true;
        }

        bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/)
        {
            if (!player)
                return false;

            std::list<Creature*> MinionList;

            switch (quest->GetQuestId())
            {
                case QUEST_BACK_TO_THE_ORPHANAGE_A:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_DRAENEI);
                    break;
                case QUEST_BACK_TO_THE_ORPHANAGE_H:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_BLOOD_ELF);
                    break;
            }

            if (!MinionList.empty())
                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            return true;
        }

};

/*######
## npc_orphan_matron_nightingale
######*/
class npc_orphan_matron_nightingale : public CreatureScript
{
    public:
        npc_orphan_matron_nightingale() : CreatureScript("npc_orphan_matron_nightingale") {}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            if (!player || !creature)
                return false;

            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    creature->CastSpell(player, SPELL_CREATE_HUMAN_ORPHAN_WHISTLE, false);
                    break;
            }

            player->CLOSE_GOSSIP_MENU();

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!player || !creature)
                return false;

            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (IsHolidayActive(HOLIDAY_CHILDRENS_WEEK))
            {
                if (player->GetQuestStatus(QUEST_CHILDRENS_WEEK_SW) != QUEST_STATUS_NONE 
                    && !player->HasItemCount(ITEM_HUMAN_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_HUMAN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            player->SEND_GOSSIP_MENU(7011, creature->GetGUID());

            return true;
        }

        bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/)
        {
            if (!player)
                return false;

            std::list<Creature*> MinionList;

            switch (quest->GetQuestId())
            {
                case QUEST_A_WARDEN_OF_THE_ALLIANCE:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_HUMAN);
                    break;
            }

            if (!MinionList.empty())
                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            return true;
        }

};

/*######
## npc_orphan_matron_battlewail
######*/
class npc_orphan_matron_battlewail : public CreatureScript
{
    public:
        npc_orphan_matron_battlewail() : CreatureScript("npc_orphan_matron_battlewail") {}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            if (!player || !creature)
                return false;

            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    creature->CastSpell(player, SPELL_CREATE_ORCISH_ORPHAN_WHISTLE, false);
                    break;
            }

            player->CLOSE_GOSSIP_MENU();

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!player || !creature)
                return false;

            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (IsHolidayActive(HOLIDAY_CHILDRENS_WEEK))
            {
                if(player->GetQuestStatus(QUEST_CHILDRENS_WEEK_OG) != QUEST_STATUS_NONE 
                    && !player->HasItemCount(ITEM_ORCISH_ORPHAN_WHISTLE, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_ORC, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            player->SEND_GOSSIP_MENU(7010, creature->GetGUID());

            return true;
        }

        bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/)
        {
            if (!player)
                return false;

            std::list<Creature*> MinionList;

            switch (quest->GetQuestId())
            {
                case QUEST_A_WARDEN_OF_THE_HORDE:
                    player->GetAllMinionsByEntry(MinionList, ORPHAN_ORCISH);
                    break;
            }

            if (!MinionList.empty())
                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            return true;
        }

};

/*######
## npc_cw_the_biggest_tree_trigger
######*/
enum eBiggestTreeEver 
{
    TEXT_THE_BIGGEST_TREE_EVER_1                = -1998874,

    QUEST_THE_BIGGEST_TREE_EVER                 = 13929,
};

class npc_cw_the_biggest_tree_trigger : public CreatureScript
{
    public:
        npc_cw_the_biggest_tree_trigger() : CreatureScript("npc_cw_the_biggest_tree_trigger") {}

        struct npc_cw_the_biggest_tree_triggerAI : public ScriptedAI
        {
            npc_cw_the_biggest_tree_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            uint8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BIGGEST_TREE_EVER) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_ORACLE);

                            if (!MinionList.empty())                        
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        break;
                                    }
                        }
            }

            void Reset()
            {
                timer = 1000;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            timer = 2000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            DoScriptText(TEXT_THE_BIGGEST_TREE_EVER_1, orphan);
                            timer = 5000;
                            break;
                        case 3:
                            player->GroupEventHappensWithOrphan(QUEST_THE_BIGGEST_TREE_EVER, me, ORPHAN_ORACLE);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else 
                    timer-=diff;
            }

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_the_biggest_tree_triggerAI(creature);
        }
};

/*######
## npc_winterfin_playmate
######*/
enum eWinterfinPlaymate
{
    TEXT_PLAYMATE_ORACLE_1                             = -1998862,
    TEXT_PLAYMATE_ORACLE_2                             = -1998863,
    TEXT_PLAYMATE_ORACLE_3                             = -1998864,
    TEXT_PLAYMATE_ORACLE_4                             = -1998865,
    TEXT_PLAYMATE_ORACLE_5                             = -1998866,

    QUEST_PLAYMATE_ORACLE                              = 13950,
};

class npc_winterfin_playmate : public CreatureScript
{
    public:
        npc_winterfin_playmate() : CreatureScript("npc_winterfin_playmate") {}

        struct npc_winterfin_playmateAI : public ScriptedAI
        {
            npc_winterfin_playmateAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {            
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_PLAYMATE_ORACLE)==QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList,ORPHAN_ORACLE);
                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        break;
                                    }
                            }
                        }
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch(phase)
                    {
                        case 1:                            
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5,me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            DoScriptText(TEXT_PLAYMATE_ORACLE_1, orphan);
                            timer = 3000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            DoScriptText(TEXT_PLAYMATE_ORACLE_2, me);
                            me->HandleEmoteCommand(EMOTE_STATE_DANCE);
                            timer = 3000;
                            break;
                        case 3:
                            DoScriptText(TEXT_PLAYMATE_ORACLE_3, orphan);
                            timer = 3000;
                            break;
                        case 4:
                            DoScriptText(TEXT_PLAYMATE_ORACLE_4, me);
                            timer = 5000;
                            break;
                        case 5:
                            DoScriptText(TEXT_PLAYMATE_ORACLE_5, orphan);
                            me->HandleEmoteCommand(EMOTE_STATE_NONE);
                            player->GroupEventHappensWithOrphan(QUEST_PLAYMATE_ORACLE, me, ORPHAN_ORACLE);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_winterfin_playmateAI(creature);
        }
};

/*######
## npc_snowfall_glade_playmate
######*/
enum eSnowfallGladePlaymate
{
    TEXT_PLAYMATE_WOLVAR_1                             = -1998891,
    TEXT_PLAYMATE_WOLVAR_2                             = -1998892,
    TEXT_PLAYMATE_WOLVAR_3                             = -1998893,
    TEXT_PLAYMATE_WOLVAR_4                             = -1998894,
    TEXT_PLAYMATE_WOLVAR_5                             = -1998895,

    QUEST_PLAYMATE_WOLVAR                              = 13951,
};

class npc_snowfall_glade_playmate : public CreatureScript
{
    public:
        npc_snowfall_glade_playmate() : CreatureScript("npc_snowfall_glade_playmate") {}

        struct npc_snowfall_glade_playmateAI : public ScriptedAI
        {
            npc_snowfall_glade_playmateAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {            
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_PLAYMATE_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);
                            if(!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if(orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        break;
                                    }
                            }
                        }
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {   
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5,me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            DoScriptText(TEXT_PLAYMATE_WOLVAR_1,orphan);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            DoScriptText(TEXT_PLAYMATE_WOLVAR_2, me);
                            me->CastSpell(orphan, 21343, true);
                            timer = 5000;
                            break;
                        case 3:
                            DoScriptText(TEXT_PLAYMATE_WOLVAR_3, me);
                            timer = 5000;
                            break;
                        case 4:
                            DoScriptText(TEXT_PLAYMATE_WOLVAR_4, orphan);
                            orphan->CastSpell(me, 21343, true);
                            timer = 5000;
                            break;
                        case 5:
                            DoScriptText(TEXT_PLAYMATE_WOLVAR_5, orphan);
                            player->GroupEventHappensWithOrphan(QUEST_PLAYMATE_WOLVAR, me, ORPHAN_WOLVAR);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_snowfall_glade_playmateAI(pCreature);
        }
};

/*######
## npc_high_oracle_soo_roo
######*/
enum eSooRoo
{
    TEXT_SOO_ROO_1                              = -1998867,
    TEXT_SOO_ROO_2                              = -1998868,
    TEXT_SOO_ROO_3                              = -1998869,
    
    QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE               = 13933,
};

class npc_high_oracle_soo_roo : public CreatureScript
{
    public:
        npc_high_oracle_soo_roo() : CreatureScript("npc_high_oracle_soo_roo") {}

        struct npc_high_oracle_soo_rooAI : public ScriptedAI
        {
            npc_high_oracle_soo_rooAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_ORACLE);
                            if(!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if(orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        break;
                                    }
                            }
                        }
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            DoScriptText(TEXT_SOO_ROO_1, orphan);
                            timer = 3000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            DoScriptText(TEXT_SOO_ROO_2, me);
                            timer = 6000;
                            break;
                        case 3:
                            DoScriptText(TEXT_SOO_ROO_3, orphan);
                            player->GroupEventHappensWithOrphan(QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE, me, ORPHAN_ORACLE);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_high_oracle_soo_rooAI(creature);
        }
};

/*######
## npc_elder_kekek
######*/
enum eKekek
{
    TEXT_ELDER_KEKEK_1                              = -1998896,
    TEXT_ELDER_KEKEK_2                              = -1998897,
    TEXT_ELDER_KEKEK_3                              = -1998898,
    
    QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR            = 13934,
};

class npc_elder_kekek : public CreatureScript
{
    public:
        npc_elder_kekek() : CreatureScript("npc_elder_kekek") {}

        struct npc_elder_kekekAI : public ScriptedAI
        {
            npc_elder_kekekAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (!phase)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);

                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        break;
                                    }
                            }
                    }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);

                    if (!player || !orphan)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            DoScriptText(TEXT_ELDER_KEKEK_1, orphan);
                            timer = 3000;
                            break;
                        case 2:
                            DoScriptText(TEXT_ELDER_KEKEK_2, me);
                            timer = 6000;
                            break;
                        case 3:
                            DoScriptText(TEXT_ELDER_KEKEK_3, orphan);
                            player->GroupEventHappensWithOrphan(QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR, me, ORPHAN_WOLVAR);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_elder_kekekAI(creature);
        }
};

/*######
## npc_cw_area_trigger
######*/
enum eCWAreaTriggers
{
    CW_TRIGGER_UNDERCITY                        = 1010593,
    CW_TRIGGER_SPOOKY_LIGHTHOUSE                = 1010592,
    CW_TRIGGER_DOWN_AT_THE_DOCKS                = 1010591,
    CW_TRIGGER_GATEWAY_TO_THE_FRONTIER          = 1010590,
    CW_TRIGGER_BOUGH_OF_THE_ETERNALS            = 1010589,
    CW_TRIGGER_STONEWROUGHT_DAM                 = 1010588,
    CW_TRIGGER_CAVERNS_OF_TIME                  = 22872,
    CW_TRIGGER_EXODAR_01_TRIGGER                = 22851,
    CW_TRIGGER_EXODAR_02_TRIGGER                = 22905,
    CW_TRIGGER_AERIS_LANDING                    = 22838,
    CW_TRIGGER_AUCHINDOUN                       = 22831,    
    CW_TRIGGER_SPOREGGAR                        = 22829,
    CW_TRIGGER_THRONE_OF_ELEMENTS               = 22839,
    CW_TRIGGER_SILVERMOON_01                    = 22866,
    CW_TRIGGER_DARK_PORTAL                      = 22833,

    QUEST_SPOOKY_LIGHTHOUSE                     = 1687,
    QUEST_DOWN_AT_THE_DOCKS                     = 910,
    QUEST_GATEWAY_TO_THE_FRONTIER               = 911,
    QUEST_BOUGH_OF_ETERNALS                     = 1479,
    QUEST_STONEWROUGHT_DAM                      = 1558,
    QUEST_AUCHINDOUN_AND_THE_RING_OF_OBSERVANCE = 10950,
    QUEST_TIME_TO_VISIT_THE_CAVERNS_H           = 10963,
    QUEST_TIME_TO_VISIT_THE_CAVERNS_A           = 10962,
    QUEST_THE_SEAT_OF_THE_NARUU                 = 10956,
    QUEST_CALL_ON_THE_FARSEER                   = 10968,
    QUEST_JHEEL_IS_AT_AERIS_LANDING             = 10954,
    QUEST_HCHUU_AND_THE_MUSHROOM_PEOPLE         = 10945,
    QUEST_VISIT_THE_THRONE_OF_ELEMENTS          = 10953,
    QUEST_LORDAERON_THRONE_ROOM                 = 1800,    
    QUEST_DARK_PORTAL_H                         = 10951,
    QUEST_DARK_PORTAL_A                         = 10952,
    QUEST_NOW_WHEN_I_GROW_UP                    = 11975,
};

class npc_cw_area_trigger : public CreatureScript
{
    public:
        npc_cw_area_trigger() : CreatureScript("npc_cw_area_trigger") {}

        struct npc_cw_area_triggerAI : public ScriptedAI
        {
            npc_cw_area_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || me->GetDistance2d(who) > 20.0f)
                    return;

                if (Player* player = who->ToPlayer())
                {
                    switch (me->GetEntry())
                    {
                        case CW_TRIGGER_STONEWROUGHT_DAM: 
                            if (player->GetQuestStatus(QUEST_STONEWROUGHT_DAM) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_STONEWROUGHT_DAM);
                            break;
                        case CW_TRIGGER_CAVERNS_OF_TIME: 
                            if (player->GetTeam() == ALLIANCE && player->GetQuestStatus(QUEST_TIME_TO_VISIT_THE_CAVERNS_A) == QUEST_STATUS_INCOMPLETE && player->HasAura(SPELL_ORPHAN_OUT))
                                player->KilledMonsterCredit(ORPHAN_DRAENEI,0);
                            else if (player->GetTeam() == HORDE && player->GetQuestStatus(QUEST_TIME_TO_VISIT_THE_CAVERNS_H) == QUEST_STATUS_INCOMPLETE && player->HasAura(SPELL_ORPHAN_OUT)) 
                                player->KilledMonsterCredit(ORPHAN_BLOOD_ELF,0);
                            break;
                        case CW_TRIGGER_EXODAR_01_TRIGGER: 
                            if (player->GetQuestStatus(QUEST_THE_SEAT_OF_THE_NARUU) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_THE_SEAT_OF_THE_NARUU); 
                            break;
                        case CW_TRIGGER_EXODAR_02_TRIGGER: 
                            if (player->GetQuestStatus(QUEST_CALL_ON_THE_FARSEER) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_CALL_ON_THE_FARSEER); 
                            break;
                        case CW_TRIGGER_AERIS_LANDING: 
                            if (player->GetQuestStatus(QUEST_JHEEL_IS_AT_AERIS_LANDING) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_JHEEL_IS_AT_AERIS_LANDING); 
                            break;
                        case CW_TRIGGER_AUCHINDOUN: 
                            if (player->GetQuestStatus(QUEST_AUCHINDOUN_AND_THE_RING_OF_OBSERVANCE) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_AUCHINDOUN_AND_THE_RING_OF_OBSERVANCE); 
                            break;
                        case CW_TRIGGER_SPOREGGAR: 
                            if (player->GetQuestStatus(QUEST_HCHUU_AND_THE_MUSHROOM_PEOPLE) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_HCHUU_AND_THE_MUSHROOM_PEOPLE); 
                            break;
                        case CW_TRIGGER_THRONE_OF_ELEMENTS: 
                            if (player->GetQuestStatus(QUEST_VISIT_THE_THRONE_OF_ELEMENTS) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_VISIT_THE_THRONE_OF_ELEMENTS); 
                            break;
                        case CW_TRIGGER_UNDERCITY: 
                            if (player->GetQuestStatus(QUEST_LORDAERON_THRONE_ROOM) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_LORDAERON_THRONE_ROOM); 
                            break;
                        case CW_TRIGGER_DARK_PORTAL: 
                            if (player->GetTeam() == ALLIANCE && player->GetQuestStatus(QUEST_DARK_PORTAL_A) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_DARK_PORTAL_A);
                            else if (player->GetTeam() == HORDE && player->GetQuestStatus(QUEST_DARK_PORTAL_H) == QUEST_STATUS_INCOMPLETE) 
                                player->AreaExploredWithOrphan(QUEST_DARK_PORTAL_H); 
                            break;
                        case CW_TRIGGER_BOUGH_OF_THE_ETERNALS: 
                            if (player->GetQuestStatus(QUEST_BOUGH_OF_ETERNALS) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_BOUGH_OF_ETERNALS); 
                            break;
                        case CW_TRIGGER_GATEWAY_TO_THE_FRONTIER: 
                            if (player->GetQuestStatus(QUEST_GATEWAY_TO_THE_FRONTIER) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_GATEWAY_TO_THE_FRONTIER); 
                            break;
                        case CW_TRIGGER_DOWN_AT_THE_DOCKS: 
                            if (player->GetQuestStatus(QUEST_DOWN_AT_THE_DOCKS) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_DOWN_AT_THE_DOCKS); 
                            break;
                        case CW_TRIGGER_SPOOKY_LIGHTHOUSE: 
                            if (player->GetQuestStatus(QUEST_SPOOKY_LIGHTHOUSE) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredWithOrphan(QUEST_SPOOKY_LIGHTHOUSE); 
                            break;
                        case CW_TRIGGER_SILVERMOON_01:
                            if (player->GetQuestStatus(QUEST_NOW_WHEN_I_GROW_UP) == QUEST_STATUS_INCOMPLETE)
                            {
                                player->AreaExploredWithOrphan(QUEST_NOW_WHEN_I_GROW_UP); 
                                if (player->GetQuestStatus(QUEST_NOW_WHEN_I_GROW_UP) == QUEST_STATUS_COMPLETE)
                                    if (Creature* samuro = me->FindNearestCreature(25151, 20.0f))
                                    {
                                        switch(urand(1,5))
                                        {
                                            case 1: samuro->HandleEmoteCommand(EMOTE_ONESHOT_WAVE); break;
                                            case 2: samuro->HandleEmoteCommand(EMOTE_ONESHOT_ROAR); break;
                                            case 3: samuro->HandleEmoteCommand(EMOTE_ONESHOT_FLEX); break;
                                            case 4: samuro->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE); break;
                                            case 5: samuro->HandleEmoteCommand(EMOTE_ONESHOT_DANCE); break;
                                        }
                                    }
                            }
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_area_triggerAI(creature);
        }
};

/*######
## npc_cw_alexstrasza_trigger
######*/
enum eAlexstraszaTheLifeBinder
{
    NPC_ALEXSTRASZA_THE_LIFE_BINDER                     = 26917,

    TEXT_THE_DRAGON_QUEEN_ORACLE_1                      = -1998875,
    TEXT_THE_DRAGON_QUEEN_ORACLE_2                      = -1998876,
    TEXT_THE_DRAGON_QUEEN_ORACLE_3                      = -1998877,
    TEXT_THE_DRAGON_QUEEN_ORACLE_4                      = -1998878,
    TEXT_THE_DRAGON_QUEEN_ORACLE_5                      = -1998879,

    TEXT_THE_DRAGON_QUEEN_WOLVAR_1                      = -1998885,
    TEXT_THE_DRAGON_QUEEN_WOLVAR_2                      = -1998886,
    TEXT_THE_DRAGON_QUEEN_WOLVAR_3                      = -1998887,
    TEXT_THE_DRAGON_QUEEN_WOLVAR_4                      = -1998888,
    TEXT_THE_DRAGON_QUEEN_WOLVAR_5                      = -1998889,

    QUEST_THE_DRAGON_QUEEN_ORACLE                       = 13954,
    QUEST_THE_DRAGON_QUEEN_WOLVAR                       = 13955,
};

class npc_cw_alexstrasza_trigger : public CreatureScript
{
    public:
        npc_cw_alexstrasza_trigger() : CreatureScript("npc_cw_alexstrasza_trigger") {}

        struct npc_cw_alexstrasza_triggerAI : public ScriptedAI
        {
            npc_cw_alexstrasza_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            int8 phase;
            uint32 timer;
            uint64 playerGUID;
            uint64 orphanGUID;
            uint64 alexstraszaGUID;
        
            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
                alexstraszaGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if (Player* player = who->ToPlayer())
                    {                 
                        if (player->GetQuestStatus(QUEST_THE_DRAGON_QUEEN_ORACLE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_ORACLE);

                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        if (Creature* alexstrasza = me->FindNearestCreature(NPC_ALEXSTRASZA_THE_LIFE_BINDER, 10.0f))
                                            alexstraszaGUID = alexstrasza->GetGUID();
                                        break;
                                    }
                            }
                        } 
                        else if (player->GetQuestStatus(QUEST_THE_DRAGON_QUEEN_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);

                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 7;
                                        if (Creature* alexstrasza = me->FindNearestCreature(NPC_ALEXSTRASZA_THE_LIFE_BINDER, 10.0f))
                                            alexstraszaGUID = alexstrasza->GetGUID();
                                        break;
                                    }
                            }
                        }
                    }
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);
                    Creature* alexstrasza = Creature::GetCreature(*me, alexstraszaGUID);

                    if (!orphan || !alexstrasza || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, alexstrasza->GetPositionX() + cos(alexstrasza->GetOrientation()) * 5, alexstrasza->GetPositionY() + sin(alexstrasza->GetOrientation()) * 5, alexstrasza->GetPositionZ());
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_ORACLE_1, orphan);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(alexstrasza);
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_ORACLE_2, orphan);
                            timer = 5000;
                            break;
                        case 3:
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_ORACLE_3, orphan);
                            timer = 5000;
                            break;
                        case 4:
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_ORACLE_4, alexstrasza);
                            alexstrasza->SetStandState(UNIT_STAND_STATE_KNEEL);
                            alexstrasza->SetFacingToObject(orphan);
                            timer = 5000;
                            break;
                        case 5:
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_ORACLE_5, orphan);
                            timer = 5000;
                            break;
                        case 6:
                            alexstrasza->SetStandState(UNIT_STAND_STATE_STAND);
                            alexstrasza->SetOrientation(alexstrasza->GetHomePosition().GetOrientation());
                            player->GroupEventHappensWithOrphan(QUEST_THE_DRAGON_QUEEN_ORACLE, alexstrasza, ORPHAN_ORACLE);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                        case 7:
                            orphan->GetMotionMaster()->MovePoint(0, alexstrasza->GetPositionX() + cos(alexstrasza->GetOrientation()) * 5, alexstrasza->GetPositionY() + sin(alexstrasza->GetOrientation()) * 5, alexstrasza->GetPositionZ());
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_WOLVAR_1, orphan);
                            timer = 5000;
                            break;
                        case 8:
                            if(Creature* krasus = me->FindNearestCreature(27990, 10.0f))
                            {
                                orphan->SetFacingToObject(krasus);
                                DoScriptText(TEXT_THE_DRAGON_QUEEN_WOLVAR_2, krasus);
                            }
                            timer = 5000;
                            break;
                        case 9:
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_WOLVAR_3, orphan);
                            timer = 5000;
                            break;
                        case 10:
                            orphan->SetFacingToObject(alexstrasza);
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_WOLVAR_4, alexstrasza);
                            timer = 5000;
                            break;
                        case 11:
                            DoScriptText(TEXT_THE_DRAGON_QUEEN_WOLVAR_5, orphan);
                            timer = 5000;
                            break;
                        case 12:
                            player->GroupEventHappensWithOrphan(QUEST_THE_DRAGON_QUEEN_WOLVAR, alexstrasza, ORPHAN_WOLVAR);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_alexstrasza_triggerAI(creature);
        }
};

/*######
## npc_cw_etymidian_trigger
######*/
enum eTheEtymidian
{
    NPC_ETYMIDIAN                               = 28092,

    TEXT_MEETING_A_GREAT_ONE_1                  = -1998870,
    TEXT_MEETING_A_GREAT_ONE_2                  = -1998871,
    TEXT_MEETING_A_GREAT_ONE_3                  = -1998872,
    TEXT_MEETING_A_GREAT_ONE_4                  = -1998873,

    QUEST_MEETING_A_GREAT_ONE                   = 13956,
};

class npc_cw_etymidian_trigger : public CreatureScript
{
    public:
        npc_cw_etymidian_trigger() : CreatureScript("npc_cw_etymidian_trigger") {}
        struct npc_cw_etymidian_triggerAI : public ScriptedAI
        {
            npc_cw_etymidian_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint32 GOtimer;
            uint64 playerGUID;
            uint64 orphanGUID;
            uint64 etymidianGUID;    

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
                etymidianGUID = 0;
                if (GameObject* gift = me->FindNearestGameObject(411510, 5.0f))
                {
                    gift->SetPhaseMask(2, true);
                    GOtimer = 0;
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (!phase)
                    if (Player* player = who->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_MEETING_A_GREAT_ONE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_ORACLE);
                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        if (Creature* etymidian = me->FindNearestCreature(NPC_ETYMIDIAN, 10.0f))
                                            etymidianGUID = etymidian->GetGUID();
                                        break;
                                    }
                            }
                        }
                    }
            }

            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);
                    Creature* etymidian = Creature::GetCreature(*me, etymidianGUID);

                    if (!orphan || !player || !etymidian)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, etymidian->GetPositionX() + cos(etymidian->GetOrientation()) * 5, etymidian->GetPositionY() + sin(etymidian->GetOrientation()) * 5, etymidian->GetPositionZ());
                            DoScriptText(TEXT_MEETING_A_GREAT_ONE_1, orphan);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(etymidian);
                            DoScriptText(TEXT_MEETING_A_GREAT_ONE_2, orphan);
                            timer = 5000;
                            break;
                        case 3:
                            DoScriptText(TEXT_MEETING_A_GREAT_ONE_3, orphan);
                            timer = 5000;
                            break;
                        case 4:
                            DoScriptText(TEXT_MEETING_A_GREAT_ONE_4, orphan);
                            if (GameObject* gift = me->FindNearestGameObject(411510, 5.0f))
                            {
                                gift->SetPhaseMask(1, true);
                                GOtimer = 10000;
                            }
                            timer = 5000;
                            break;
                        case 5:
                            orphan->GetMotionMaster()->MoveFollow(player,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);
                            player->GroupEventHappensWithOrphan(QUEST_MEETING_A_GREAT_ONE,me,ORPHAN_ORACLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_etymidian_triggerAI(creature);
        }
};

/*######
## npc_cw_nesingwary_trigger
######*/
enum eNesingwaryTrigger
{
    NPC_NESINGWARY                               = 27986,

    TEXT_THE_MIGHTY_HEMET_NESINGWARY_1          = -1998880,
    TEXT_THE_MIGHTY_HEMET_NESINGWARY_2          = -1998881,
    TEXT_THE_MIGHTY_HEMET_NESINGWARY_3          = -1998882,
    TEXT_THE_MIGHTY_HEMET_NESINGWARY_4          = -1998883,
    TEXT_THE_MIGHTY_HEMET_NESINGWARY_5          = -1998884,

    QUEST_THE_MIGHTY_HEMET_NESINGWARY           = 13957,
};
class npc_cw_nesingwary_trigger : public CreatureScript
{
    public:
        npc_cw_nesingwary_trigger() : CreatureScript("npc_cw_nesingwary_trigger") {}

        struct npc_cw_nesingwary_triggerAI : public ScriptedAI
        {
            npc_cw_nesingwary_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;
            uint64 nesingwaryGUID;        

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
                nesingwaryGUID = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 10.0f)
                    return;

                if (phase == 0)
                    if(Player* player = who->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_THE_MIGHTY_HEMET_NESINGWARY)==QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();

                            std::list<Creature*> MinionList;
                            player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);
                            if (!MinionList.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                                    if (orphanGUID = (*itr)->GetGUID())
                                    {
                                        phase = 1;
                                        if (Creature* nesingwary = me->FindNearestCreature(NPC_NESINGWARY,10.0f))
                                            nesingwaryGUID = nesingwary->GetGUID();
                                        break;
                                    }
                            }
                        }
                    }
            }
            void UpdateAI(const uint32 diff)
            {
                if (phase == 0)
                    return;

                if (timer <= diff)
                {
                    Player* player = Player::GetPlayer(*me, playerGUID);
                    Creature* orphan = Creature::GetCreature(*me, orphanGUID);
                    Creature* nesingwary = Creature::GetCreature(*me, nesingwaryGUID);

                    if(!orphan || !nesingwary || !player)
                    {
                        Reset();
                        return;
                    }

                    switch(phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, nesingwary->GetPositionX() + cos(nesingwary->GetOrientation()) * 5,nesingwary->GetPositionY() + sin(nesingwary->GetOrientation()) * 5, nesingwary->GetPositionZ());
                            DoScriptText(TEXT_THE_MIGHTY_HEMET_NESINGWARY_1, orphan);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(nesingwary);
                            DoScriptText(TEXT_THE_MIGHTY_HEMET_NESINGWARY_2, orphan);
                            timer = 5000;
                            break;
                        case 3:
                            DoScriptText(TEXT_THE_MIGHTY_HEMET_NESINGWARY_3, nesingwary);
                            timer = 5000;
                            break;
                        case 4:
                            DoScriptText(TEXT_THE_MIGHTY_HEMET_NESINGWARY_4, orphan);
                            timer = 5000;
                            break;
                        case 5:
                            DoScriptText(TEXT_THE_MIGHTY_HEMET_NESINGWARY_5, orphan);
                            timer = 5000;
                            break;
                        case 6:
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            player->GroupEventHappensWithOrphan(QUEST_THE_MIGHTY_HEMET_NESINGWARY, nesingwary, ORPHAN_WOLVAR);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer-=diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_nesingwary_triggerAI(creature);
        }
};


/*######
## npc_cw_grizzlemaw_trigger
######*/
enum eGrizzleMawTrigger
{
    TEXT_HOME_OF_THE_BEAR_MEN                   = -1998890,

    QUEST_HOME_OF_THE_BEAR_MEN                  = 13930,
};

class npc_cw_grizzlemaw_trigger : public CreatureScript
{
    public:
        npc_cw_grizzlemaw_trigger() : CreatureScript("npc_cw_grizzlemaw_trigger") {}

        struct npc_cw_grizzlemaw_triggerAI : public ScriptedAI
        {
            npc_cw_grizzlemaw_triggerAI(Creature* creature) : ScriptedAI (creature) {}

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetDistance2d(me) > 20.0f)
                    return;

                if (Player* player = who->ToPlayer())
                {                 
                    if (player->GetQuestStatus(QUEST_HOME_OF_THE_BEAR_MEN) == QUEST_STATUS_INCOMPLETE)
                    {
                        std::list<Creature*> MinionList;
                        player->GetAllMinionsByEntry(MinionList, ORPHAN_WOLVAR);
                        if (!MinionList.empty())
                        {                        
                            for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                            {
                                if (Creature* orphan = (*itr))
                                {
                                    player->AreaExploredWithOrphan(QUEST_HOME_OF_THE_BEAR_MEN, ORPHAN_WOLVAR);
                                    DoScriptText(TEXT_HOME_OF_THE_BEAR_MEN, orphan);
                                    return;
                                }
                            }                        
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_grizzlemaw_triggerAI(creature);
        }
};

void AddSC_event_childrens_week()
{
    new npc_orphan_matron_mercy();
    new npc_orphan_matron_nightingale();
    new npc_orphan_matron_battlewail();
    new npc_orphan_matron_aria();

    new npc_winterfin_playmate();
    new npc_elder_kekek();
    new npc_high_oracle_soo_roo();
    new npc_snowfall_glade_playmate();

    new npc_cw_the_biggest_tree_trigger();
    new npc_cw_area_trigger();
    new npc_cw_alexstrasza_trigger();
    new npc_cw_etymidian_trigger();
    new npc_cw_nesingwary_trigger();
    new npc_cw_grizzlemaw_trigger();
    
}