/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Sholazar_Basin
SD%Complete: 100
SDComment: Quest support: 12570, 12573, 12621.
SDCategory: Sholazar_Basin
EndScriptData */

/* ContentData
npc_injured_rainspeaker_oracle
npc_vekjik
avatar_of_freya
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"

/*######
## npc_injured_rainspeaker_oracle
######*/

#define GOSSIP_ITEM1 "I am ready to travel to your village now."
#define GOSSIP_ITEM2 "<Reach down and pull the injured Rainspeaker Oracle to it's feet.>"

enum eRainspeaker
{
    SAY_START_IRO                       = -1571000,
    SAY_QUEST_ACCEPT_IRO                = -1571001,
    SAY_END_IRO                         = -1571002,

    QUEST_FORTUNATE_MISUNDERSTANDINGS = 12570,
    QUEST_JUST_FOLLOWING_ORDERS       = 12540,
    ENTRY_RAVENOUS_MANGAL_CROCOLISK   = 28325,
    FACTION_ESCORTEE_A = 774,
    FACTION_ESCORTEE_H = 775
};

#define FACTION_FRENZYHEART                     1104
#define FACTION_ORCLES                          1105

class npc_injured_rainspeaker_oracle : public CreatureScript
{
public:
    npc_injured_rainspeaker_oracle() : CreatureScript("npc_injured_rainspeaker_oracle") { }

    struct npc_injured_rainspeaker_oracleAI : public npc_escortAI
    {
        npc_injured_rainspeaker_oracleAI(Creature* c) : npc_escortAI(c)
        {
            c_guid = c->GetGUID();
        }

        uint64 c_guid;

        void Reset()
        {
            me->RestoreFaction();
            // if we will have other way to assign this to only one npc remove this part
            if (GUID_LOPART(me->GetGUID()) != 101030)
            {
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(i)
            {
            case 1: SetRun(); break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_JUMPING);
                me->SetSpeed(MOVE_SWIM, 0.85f, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_LEVITATING);
                break;
            case 19:
                me->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
                break;
            case 28:
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_FORTUNATE_MISUNDERSTANDINGS, me);
              //  me->RestoreFaction();
                DoScriptText(SAY_END_IRO, me);
                SetRun(false);
                break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (Player* pPlayer = GetPlayerForEscort())
            {
              if (pPlayer->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) != QUEST_STATUS_COMPLETE)
                pPlayer->FailQuest(QUEST_FORTUNATE_MISUNDERSTANDINGS);
            }
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if (pPlayer->GetQuestStatus(QUEST_JUST_FOLLOWING_ORDERS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
            CAST_AI(npc_escortAI, (pCreature->AI()))->SetMaxPlayerDistance(35.0f);
            pCreature->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
            DoScriptText(SAY_START_IRO, pCreature);

            switch (pPlayer->GetTeam())
            {
                case ALLIANCE:
                    pCreature->setFaction(FACTION_ESCORTEE_A);
                    break;
                case HORDE:
                    pCreature->setFaction(FACTION_ESCORTEE_H);
                    break;
            }
        }else if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
        {
            pCreature->SummonCreature(ENTRY_RAVENOUS_MANGAL_CROCOLISK,*pCreature,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
        }
        return true;
    }

    bool OnQuestAccept(Player* /*pPlayer*/, Creature* pCreature, Quest const* /*_Quest*/)
    {
        DoScriptText(SAY_QUEST_ACCEPT_IRO, pCreature);
        return false;
    }

    bool OnQuestReward(Player *player, Creature *_Creature, Quest const *_Quest, uint32 /*item*/)
    {
        switch(_Quest->GetQuestId())
        {
        case QUEST_JUST_FOLLOWING_ORDERS:
            player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_ORCLES),3000);
            //player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_FRENZYHEART),-600);
            break;
        }
        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_injured_rainspeaker_oracleAI(creature);
    }
};

/*######
## npc_vekjik
######*/

#define GOSSIP_VEKJIK_ITEM1 "Shaman Vekjik, I have spoken with the big-tongues and they desire peace. I have brought this offering on their behalf."
#define GOSSIP_VEKJIK_ITEM2 "No no... I had no intentions of betraying your people. I was only defending myself. it was all a misunderstanding."

enum eVekjik
{
    GOSSIP_TEXTID_VEKJIK1       = 13137,
    GOSSIP_TEXTID_VEKJIK2       = 13138,

    SAY_TEXTID_VEKJIK1          = -1000208,

    SPELL_FREANZYHEARTS_FURY    = 51469,

    QUEST_MAKING_PEACE          = 12573
};

class npc_vekjik : public CreatureScript
{
public:
    npc_vekjik() : CreatureScript("npc_vekjik") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_MAKING_PEACE) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK1, pCreature->GetGUID());
            return true;
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK2, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_TEXTID_VEKJIK1, pCreature, pPlayer);
                pPlayer->AreaExploredOrEventHappens(QUEST_MAKING_PEACE);
                pCreature->CastSpell(pPlayer, SPELL_FREANZYHEARTS_FURY, false);
                break;
        }

        return true;
    }
};

/*######
## avatar_of_freya
######*/

#define GOSSIP_ITEM_AOF1 "I want to stop the Scourge as much as you do. How can I help?"
#define GOSSIP_ITEM_AOF2 "You can trust me. I am no friend of the Lich King."
#define GOSSIP_ITEM_AOF3 "I will not fail."

enum eFreya
{
    QUEST_FREYA_PACT         = 12621,

    SPELL_FREYA_CONVERSATION = 52045,

    GOSSIP_TEXTID_AVATAR1    = 13303,
    GOSSIP_TEXTID_AVATAR2    = 13304,
    GOSSIP_TEXTID_AVATAR3    = 13305
};

class npc_avatar_of_freya : public CreatureScript
{
public:
    npc_avatar_of_freya() : CreatureScript("npc_avatar_of_freya") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_FREYA_PACT) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR1, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CastSpell(pPlayer, SPELL_FREYA_CONVERSATION, true);
            pPlayer->CompleteQuest(QUEST_FREYA_PACT);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

/*######
## npc_bushwhacker
######*/

class npc_bushwhacker : public CreatureScript
{
public:
    npc_bushwhacker() : CreatureScript("npc_bushwhacker") { }

    struct npc_bushwhackerAI : public ScriptedAI
    {
        npc_bushwhackerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        void InitializeAI()
        {
            if (me->isDead())
                return;

            if (me->isSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (summoner)
                        me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());

            Reset();
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_bushwhackerAI(creature);
    }
};

/*######
## npc_engineer_helice
######*/

enum eEnums
{
    SPELL_EXPLODE_CRYSTAL       = 62487,
    SPELL_FLAMES                = 64561,

    SAY_WP_7                    = -1800047,
    SAY_WP_6                    = -1800048,
    SAY_WP_5                    = -1800049,
    SAY_WP_4                    = -1800050,
    SAY_WP_3                    = -1800051,
    SAY_WP_2                    = -1800052,
    SAY_WP_1                    = -1800053,

    QUEST_DISASTER              = 12688
};

class npc_engineer_helice : public CreatureScript
{
public:
    npc_engineer_helice() : CreatureScript("npc_engineer_helice") { }

    struct npc_engineer_heliceAI : public npc_escortAI
    {
        npc_engineer_heliceAI(Creature* pCreature) : npc_escortAI(pCreature) { }

        uint32 m_uiChatTimer;

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();
            switch (i)
            {
                case 0:
                    DoScriptText(SAY_WP_2, me);
                    break;
                case 1:
                    DoScriptText(SAY_WP_3, me);
                    me->CastSpell(5918.33f, 5372.91f, -98.770f, SPELL_EXPLODE_CRYSTAL, true);
                    me->SummonGameObject(184743, 5918.33f, 5372.91f, -98.770f, 0, 0, 0, 0, 0, TEMPSUMMON_MANUAL_DESPAWN);     //approx 3 to 4 seconds
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                    break;
                case 2:
                    DoScriptText(SAY_WP_4, me);
                    break;
                case 7:
                    DoScriptText(SAY_WP_5, me);
                    break;
                case 8:
                    me->CastSpell(5887.37f, 5379.39f, -91.289f, SPELL_EXPLODE_CRYSTAL, true);
                    me->SummonGameObject(184743, 5887.37f, 5379.39f, -91.289f, 0, 0, 0, 0, 0, TEMPSUMMON_MANUAL_DESPAWN);      //approx 3 to 4 seconds
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                    break;
                case 9:
                    DoScriptText(SAY_WP_6, me);
                    break;
                case 13:
                    if (pPlayer)
                    {
                        pPlayer->GroupEventHappens(QUEST_DISASTER, me);
                        DoScriptText(SAY_WP_7, me);
                    }
                    break;
            }
        }

        void Reset()
        {
            m_uiChatTimer = 4000;
        }
        void JustDied(Unit* /*pKiller*/)
        {
            Player* pPlayer = GetPlayerForEscort();
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (pPlayer)
                    pPlayer->FailQuest(QUEST_DISASTER);
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (m_uiChatTimer <= uiDiff)
                {
                    m_uiChatTimer = 12000;
                }
                else
                    m_uiChatTimer -= uiDiff;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_engineer_heliceAI(creature);
    }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_DISASTER)
        {
            if (npc_engineer_heliceAI* pEscortAI = CAST_AI(npc_engineer_helice::npc_engineer_heliceAI, pCreature->AI()))
            {
                pCreature->GetMotionMaster()->MoveJumpTo(0, 0.4f, 0.4f);
                pCreature->setFaction(113);

                pEscortAI->Start(false, false, pPlayer->GetGUID());
                DoScriptText(SAY_WP_1, pCreature);
            }
        }
        return true;
    }
};

/*######
 ## npc_high_oracle_soo_say
 ######*/

enum o_npc_high_oracle_soo_say
{

    ITEM_JALOOTS_FAVORITE_CRYSTAL = 38623,
    ITEM_LAFOOS_BUG_BAG = 38622,
    ITEM_MOODLES_STRESS_BALL = 38624,

    QUEST_APPEASING_THE_GREAT_RAIN_STONE = 12704, //Alle
    QUEST_GODS_LIKE_SHINEY_THINGS = 12572, //Lafoo
    QUEST_MAKE_THE_BAD_SNAKE_GO_AWAY = 12571, //Lafoo
    //QUEST_FORTUNATE_MISUNDERSTANDINGS = 12570,
    //QUEST_MAKING_PEACE = 12573, //Lafoo
    QUEST_BACK_SO_SOON = 12574, //Jaloo
    QUEST_FORCED_HAND = 12576, //Jaloo
    QUEST_THE_LOST_MISTWHISPER_TRESURE = 12575, //Jaloo
    QUEST_THE_ANGRY_GORLOC = 12578, //Moodle
    QUEST_A_HEROS_BURDEN = 12581, //Moodle
};

#define GOSSIP_LAFOO_ITEM       "I need to find Lafoo, do you have his bug bag?"
#define GOSSIP_JALOOT_ITEM      "I need to find Jaloot, do you have his favorite crystal?"
#define GOSSIP_MOODLE_ITEM      "I need to find Moodle, do you have his stressball?"

//This function is called when the player opens the gossip menubool

class npc_high_oracle_soo_say : public CreatureScript
{
public:
    npc_high_oracle_soo_say() : CreatureScript("npc_high_oracle_soo_say") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        ItemPosCountVec dest;
        uint32 ToStoreItem;

        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                ToStoreItem = ITEM_LAFOOS_BUG_BAG;
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                ToStoreItem = ITEM_JALOOTS_FAVORITE_CRYSTAL;
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                ToStoreItem = ITEM_MOODLES_STRESS_BALL;
                break;
        }

        if (ToStoreItem > 0)
        {
            uint8 canStoreNewItem = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ToStoreItem, 1);
            if (canStoreNewItem == EQUIP_ERR_OK) {
                Item *newItem = NULL;
                newItem = pPlayer->StoreNewItem(dest, ToStoreItem, 1, true);
                pPlayer->SendNewItem(newItem, 1, true, false);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
        }
        return true;
    }


    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_APPEASING_THE_GREAT_RAIN_STONE) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_LAFOO_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, false);
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_JALOOT_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2, "", 0, false);
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_MOODLE_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3, "", 0, false);

            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature),pCreature->GetGUID());
            return true;
        }

        if (pPlayer->GetQuestStatus(QUEST_MAKE_THE_BAD_SNAKE_GO_AWAY) == QUEST_STATUS_INCOMPLETE
            || (pPlayer->GetQuestStatus(QUEST_GODS_LIKE_SHINEY_THINGS) == QUEST_STATUS_INCOMPLETE
            || pPlayer->GetQuestStatus(QUEST_GODS_LIKE_SHINEY_THINGS) == QUEST_STATUS_NONE)
            || pPlayer->GetQuestStatus(QUEST_MAKING_PEACE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_LAFOO_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, false);
   
        if (pPlayer->GetQuestStatus(QUEST_BACK_SO_SOON) == QUEST_STATUS_INCOMPLETE
            || pPlayer->GetQuestStatus(QUEST_FORCED_HAND) == QUEST_STATUS_INCOMPLETE
            || pPlayer->GetQuestStatus(QUEST_THE_LOST_MISTWHISPER_TRESURE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_JALOOT_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2, "", 0, false);

        if (pPlayer->GetQuestStatus(QUEST_THE_ANGRY_GORLOC) == QUEST_STATUS_INCOMPLETE
            || (pPlayer->GetQuestStatus(QUEST_THE_ANGRY_GORLOC) == QUEST_STATUS_COMPLETE
            && pPlayer->GetQuestStatus(QUEST_A_HEROS_BURDEN) == QUEST_STATUS_NONE))
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_MOODLE_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3, "", 0, false);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature),pCreature->GetGUID());
        return true;
    }

};

/*####
 # npc_generic_oracle_treasure_trigger
 ####*/

enum trigger_stuff
{
    SPELL_GLINTING_BUG_SPARKLE = 51444,
    NPC_ORACLE_MOODLE_ID = 28122,
    NPC_ORACLE_JALOOT_ID = 28121,
    NPC_ORACLE_LAFOO_ID = 28120,
    TRIGGER_SIGHT_DIST = 15,
    DATA_CHANGEFORCEAURAREMOVE = 666,
    DATA_CHANGEFORCEDESPAWN = 667
};

class npc_generic_oracle_treasure_trigger : public CreatureScript
{
public:
    npc_generic_oracle_treasure_trigger() : CreatureScript("npc_generic_oracle_treasure_trigger") { }

    struct npc_generic_oracle_treasure_triggerAI: public ScriptedAI
    {
        npc_generic_oracle_treasure_triggerAI(Creature *c) : ScriptedAI(c)
        {
            initial_cast = true;
            AuraTimer = 3000;
            bForceAuraRemove = false;
            bForceDespawn = false;
        }

        bool AuraRemoved;
        bool initial_cast;
        bool bForceAuraRemove;
        bool bForceDespawn;
        uint32 AuraTimer;

        void Reset() 
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(17519); //Fix for future db changes, should be always invisible for Player
            AuraRemoved = false;
            bForceAuraRemove = false;
            bForceDespawn = false;
        }

        void ChangeForceAuraRemove(bool condition)
        {
            bForceAuraRemove = condition;
        }

        void ChangeForceDespawn(bool despawn)
        {
            bForceDespawn = despawn;
        }

        void SetData(uint32 data, uint32 value)
        {
            if(data == DATA_CHANGEFORCEAURAREMOVE)
                ChangeForceAuraRemove(value == 1);

            if(data == DATA_CHANGEFORCEDESPAWN)
                ChangeForceDespawn(value == 1);
        }

        Player* GetNearPlayer()
        {
            float radius = TRIGGER_SIGHT_DIST + 10;

            if(me->FindNearestPlayer(radius) && (me->FindNearestPlayer(radius)->GetQuestStatus(QUEST_APPEASING_THE_GREAT_RAIN_STONE) == QUEST_STATUS_INCOMPLETE || me->FindNearestPlayer(radius)->GetQuestStatus(QUEST_GODS_LIKE_SHINEY_THINGS) == QUEST_STATUS_INCOMPLETE))
                return me->FindNearestPlayer(radius);
            return NULL;
        }

        void UpdateAI(const uint32 diff) 
        {
            if (initial_cast)
            {
                me->CastSpell(me, SPELL_GLINTING_BUG_SPARKLE, false);
                initial_cast = false;
            }

            if (bForceDespawn)
                me->DespawnOrUnsummon(0);

            if (!bForceAuraRemove)
            {
                if (AuraTimer <= diff)
                {
                    if (GetNearPlayer()) 
                    {
                        if (!AuraRemoved) 
                        {
                            if (!me->FindNearestCreature(NPC_ORACLE_MOODLE_ID, TRIGGER_SIGHT_DIST) && !me->FindNearestCreature(NPC_ORACLE_JALOOT_ID, TRIGGER_SIGHT_DIST) && !me->FindNearestCreature(NPC_ORACLE_LAFOO_ID, TRIGGER_SIGHT_DIST)) {
                                me->RemoveAllAuras();
                                AuraRemoved = true;
                            }
                        }

                        if (AuraRemoved)
                        {
                            if (me->FindNearestCreature(NPC_ORACLE_MOODLE_ID, TRIGGER_SIGHT_DIST + 8) || me->FindNearestCreature(NPC_ORACLE_JALOOT_ID, TRIGGER_SIGHT_DIST + 8) || me->FindNearestCreature(NPC_ORACLE_LAFOO_ID, TRIGGER_SIGHT_DIST + 8)) {
                                DoCast(me, SPELL_GLINTING_BUG_SPARKLE);
                                Reset();
                            }
                        }
                    } else 
                    {
                        me->RemoveAllAuras();
                        AuraRemoved = true;
                    }
                    AuraTimer = 3000;
                } else
                    AuraTimer -= diff;
            } else
            {
                me->RemoveAllAuras();
                AuraRemoved = true;
            }
        }
    };

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new npc_generic_oracle_treasure_triggerAI(_Creature);
    }
};

/*####
 # npc_generic_oracle_treasure_seeker
 ####*/

static const char * Generic_sayings[] = { "That weird. Someone took our bugs. You have maybe?", "You have pie? Someone gave us pie year ago. Really yummy.", "One day maybe you can be Soo-dryskin. You like?", "You got funny looking eyeballs.", "Never meet Great Ones. Nope, just met their shrines.", "Chase the hatchlings! Chase the hatchlings! So fast!", "Mistcaller really good at controlling weather with shrine. They know just which crystals to use! Really good!", "You like that? Bet not! Bet not cause you dead! Hahah!", "We know you have dragon thing! We not scared! We going to get you and dragon thing!", "Teach you to steal our treasures! Our treasures are... ours, okay?", "Want us to help with something? What we help with? We good at helping.", "Hello! You're pretty strong and nice and stuff. I like you. Lets stay friends, okay?", "Misty. Very misty. Seem sort of misty to you? Maybe not so much." };

static const char * Special_sayings[] = { "Home good, but not stay long! More adventures!", "Good home. Had it long time, still stay good.", "There some reason why we're still here? I'd love to hear it", "Planning to sit on your butt some more, or are we going to go do something that's actually useful?", "Yeah, let's go now.", "No come back this time!", "Crunchy bugs so delicious. Want?", "Ever trip over own feet? We have. Kind of hurt. No do it, not fun. Nope.", "What the heck are shiny rabbits doing here anyway?" };

static const char * Seeker_sayings[] = { "Ooh! Shinies!", "Maybe more shiny bugs! We like bugs!", "Treasure for me! Treasure for shrine!", "Dig, dig, dig...", "Shiny things! Shiny things! Not as shiny as my crystal, but still shiny!", "More treasures! Treasures of all kinds! Yay treasures!", "Can never have too many shiny crystals! Nope!", "We are fast digger! Really fast! See... all done! That was fast, huh?", "Yay... more dirt.", "Here I am, digging up some useless bauble on the will of someone I just met...does that seem right to you?", "I'm done here" };

enum oracle_specific 
{
    TRIGGER_ID = 19656,
    TRIGGER_SEARCH_DIST = 10,
    FACTION_ID = 35,
    NPC_HIGH_ORACLE_SOO_SAY = 28027,
    HOME_DIST = 50,
    MOB_GLINTING_BUG = 28372,
    AREA_MOSSWALKER_VILLAGE = 4297,
    ENTRY_MOODLE = 28122,
};

enum seeking_spells
{
    DIG_UP_GLINTING_BUG = 51443,
    DIG_UP_SPARKLING_HARE = 51441,

    DIG_UP_DISGRUNTLED_BUG_COVER = 52928,

    DIG_UP_GLINTING_ARMOR = 51398,
    DIG_UP_GLOWING_GEM = 51400,
    DIG_UP_POLISHED_PLATTER = 51401,
    DIG_UP_SHINING_CRYSTAL = 51397,
    DIG_UP_SPARKLING_TREASURE = 51402
};

class npc_generic_oracle_treasure_seeker : public CreatureScript
{
public:
    npc_generic_oracle_treasure_seeker() : CreatureScript("npc_generic_oracle_treasure_seeker") { }

    struct npc_generic_oracle_treasure_seekerAI: public FollowerAI
    {
        npc_generic_oracle_treasure_seekerAI(Creature* pCreature) : FollowerAI(pCreature) {}

            uint32 CheckTimer;
            uint32 SearchTimer;
            uint32 GeneralSayTimer;
            uint32 TreasureSpell;
            uint8 SearchCount;
            bool AlreadyMoved;
            bool SearchAnim;
            bool SayHome;
            bool isAway;
            uint32 AreaCheckTimer;

            void Reset()
            {
                if (HasFollowState(STATE_FOLLOW_PAUSED | STATE_FOLLOW_INPROGRESS))
                    SetFollowPaused(false);
                if (me->GetOwner() && Unit::GetPlayer(*me,me->GetOwner()->GetGUID()))
                    StartFollow(Unit::GetPlayer(*me,me->GetOwner()->GetGUID()), FACTION_ID, 0);
                me->SetReactState(REACT_DEFENSIVE);
                me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                AlreadyMoved = false;
                CheckTimer = 2000;
                SearchTimer = 0;
                SearchCount = 1;
                SearchAnim = false;
                SayHome = false;
                GeneralSayTimer = 60000;
                isAway = false;
                AreaCheckTimer = 5000;
            }

            void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
            {
                switch(pSpell->Id)
                {
                case DIG_UP_GLINTING_BUG:
                case DIG_UP_SPARKLING_HARE:
                case DIG_UP_GLINTING_ARMOR:
                case DIG_UP_GLOWING_GEM: 
                case DIG_UP_POLISHED_PLATTER:
                case DIG_UP_SHINING_CRYSTAL: 
                case DIG_UP_SPARKLING_TREASURE:
                    break;
                default:
                    if (HasFollowState(STATE_FOLLOW_INPROGRESS) && rand() % 10 == 1)
                        me->MonsterSay(Special_sayings[7], LANG_UNIVERSAL, 0);
                break;
                }

            }

            void UpdateFollowerAI(const uint32 diff)
            {
                if(me->GetEntry() == ENTRY_MOODLE)
                {
                    if(AreaCheckTimer <= diff)
                    {
                        if(me->GetAreaId() == AREA_MOSSWALKER_VILLAGE)
                            if(me->GetOwner() && me->GetOwner()->ToPlayer())
                                if(me->GetOwner()->ToPlayer()->GetQuestStatus(QUEST_THE_ANGRY_GORLOC) == QUEST_STATUS_INCOMPLETE)
                                    me->GetOwner()->ToPlayer()->CompleteQuest(QUEST_THE_ANGRY_GORLOC);
                        AreaCheckTimer = 5000;
                    }else AreaCheckTimer -= diff;
                }

                if (CheckTimer <= diff)
                {
                    if (me->GetOwner() && Unit::GetPlayer(*me,me->GetOwner()->GetGUID()))
                        isAway = Unit::GetPlayer(*me,me->GetOwner()->GetGUID())->isAFK();

                    if (!isAway)
                    {
                        if (!SayHome && me->FindNearestCreature(NPC_HIGH_ORACLE_SOO_SAY, HOME_DIST))
                        {
                            me->MonsterSay(Special_sayings[urand(0, 1)], LANG_UNIVERSAL, 0);
                            SayHome = true;
                        }
                        if (SayHome && !me->FindNearestCreature(NPC_HIGH_ORACLE_SOO_SAY, HOME_DIST))
                            SayHome = false;

                        if (me->GetOwner() && Unit::GetPlayer(*me,me->GetOwner()->GetGUID()) && Unit::GetPlayer(*me,me->GetOwner()->GetGUID())->GetQuestStatus(QUEST_APPEASING_THE_GREAT_RAIN_STONE) == QUEST_STATUS_INCOMPLETE
                                || Unit::GetPlayer(*me,me->GetOwner()->GetGUID())->GetQuestStatus(QUEST_GODS_LIKE_SHINEY_THINGS) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (Creature *OracleTrigger = me->FindNearestCreature(TRIGGER_ID, TRIGGER_SEARCH_DIST)) 
                            {
                                OracleTrigger->AI()->SetData(DATA_CHANGEFORCEAURAREMOVE,1);
                                SetFollowPaused(true);
                                if (HasFollowState(STATE_FOLLOW_PAUSED))
                                {
                                    if (!AlreadyMoved) {
                                        me->GetMotionMaster()->MovePoint(0, OracleTrigger->GetPositionX(), OracleTrigger->GetPositionY(), OracleTrigger->GetPositionZ());
                                        AlreadyMoved = true;
                                    }
                                    if (me->IsWithinDistInMap(OracleTrigger, 1))
                                        SearchAnim = true;
                                }
                                CheckTimer = 2000;
                            }
                        }
                    } else
                    {
                        me->MonsterSay(Special_sayings[urand(2, 4)], LANG_UNIVERSAL, 0);
                        CheckTimer = 120000;
                    }
                } else
                    CheckTimer -= diff;

                if (GeneralSayTimer <= diff)
                {
                    if (!SearchAnim && !isAway)
                        me->MonsterSay(Generic_sayings[urand(0, 12)], LANG_UNIVERSAL, 0);

                    GeneralSayTimer = 30000 + urand(300000, 600000);
                } else
                    GeneralSayTimer -= diff;

                if (SearchAnim)
                {
                    if (SearchTimer <= diff)
                    {
                        if (SearchCount < 4)
                            DoCast(me, DIG_UP_DISGRUNTLED_BUG_COVER);

                        if (SearchCount == 2)
                        {
                            TreasureSpell = RAND(DIG_UP_GLINTING_ARMOR, DIG_UP_SPARKLING_HARE, DIG_UP_GLOWING_GEM, DIG_UP_POLISHED_PLATTER, DIG_UP_SPARKLING_TREASURE, DIG_UP_GLINTING_BUG);
                            if (TreasureSpell == DIG_UP_GLINTING_BUG)
                                me->MonsterSay(Special_sayings[6], LANG_UNIVERSAL, 0);
                            else
                                if (TreasureSpell == DIG_UP_SPARKLING_HARE)
                                    me->MonsterSay(Special_sayings[8], LANG_UNIVERSAL, 0);
                                else
                                    me->MonsterSay(Seeker_sayings[urand(0, 10)], LANG_UNIVERSAL, 0);
                        }

                        if (SearchCount == 4)
                            DoCast(me, TreasureSpell);

                        if (SearchCount > 4)
                        {
                            if (Creature *OracleTrigger = me->FindNearestCreature(TRIGGER_ID, TRIGGER_SEARCH_DIST-8))
                                OracleTrigger->AI()->SetData(DATA_CHANGEFORCEDESPAWN,1);
                            Reset();
                        }

                        SearchTimer = 1000;
                        SearchCount++;
                    } else
                        SearchTimer -= diff;
                }
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_generic_oracle_treasure_seekerAI(pCreature);
    }
};

/*######
## oracle_frenzyheart_switch
######*/

#define D_QUEST_FRENZYHEART_CHAMPION            12582
#define D_QUEST_HAND_OF_THE_ORACLES             12689

class oracle_frenzyheart_switch : public CreatureScript
{
public:
    oracle_frenzyheart_switch() : CreatureScript("oracle_frenzyheart_switch") { }

    bool OnQuestReward(Player *player, Creature *_Creature, Quest const *_Quest, uint32 /*item*/)
    {
        switch(_Quest->GetQuestId())
        {
        case D_QUEST_FRENZYHEART_CHAMPION:
            player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_FRENZYHEART),9000);
            //player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_ORCLES),-4200);
            break;
        case D_QUEST_HAND_OF_THE_ORACLES:
            player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_ORCLES),9000);
            //player->GetReputationMgr().SetReputation(sFactionStore.LookupEntry(FACTION_FRENZYHEART),-4200);
            break;
        }
        return true;
    }
};

/*######
## npc_frenzyheart_zepik
######*/

#define QUEST_A_ROUGH_RIDE                      12536
#define AREA_MISTWHISPER_REFUGE                 4306

class npc_frenzyheart_zepik : public CreatureScript
{
public:
    npc_frenzyheart_zepik() : CreatureScript("npc_frenzyheart_zepik") { }

    struct npc_frenzyheart_zepikAI: public ScriptedAI
    {
        npc_frenzyheart_zepikAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 check_Timer;

        void Reset()
        {
            check_Timer = 5000;
            if(me->GetOwner() && me->GetOwner()->ToPlayer())
                me->GetMotionMaster()->MoveFollow(me->GetOwner()->ToPlayer(), PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }

        void Aggro(){}

        void UpdateAI(const uint32 diff)
        {
            if(check_Timer <= diff)
            {
                if(me->GetAreaId() == AREA_MISTWHISPER_REFUGE)
                    if(me->GetOwner() && me->GetOwner()->ToPlayer())
                    {
                        if(me->GetOwner()->ToPlayer()->GetQuestStatus(QUEST_A_ROUGH_RIDE) == QUEST_STATUS_INCOMPLETE)
                            me->GetOwner()->ToPlayer()->CompleteQuest(QUEST_A_ROUGH_RIDE);
                    }
                check_Timer = 5000;
            }else check_Timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_frenzyheart_zepikAI(pCreature);
    }
};

/*######
## npc_mosswalker_victim
######*/

#define SPELL_MOSSWALKER_QUEST_CREDIT               52157
#define QUEST_THE_MOSSWALKER_SAVIOR                 12580

static const char * dead_sayings[5] =
{
    "Please take... my shinies. All done...",
    "We not do anything... to them... I no understand.",
    "Use my shinies... make weather good again... make undead things go away.",
    "We gave shinies to shrine... we not greedy... why this happen?",
    "I do something bad? I sorry..."
};
static const char * survive_sayings[4] =
{
    "We saved. You nice, dryskin.",
    "Maybe you make weather better too?",
    "You save us! Yay for you!",
    "Thank you! You good!"
};

#define GOSSIP_EVENT            "<Check for pulse.>"

class npc_mosswalker_victim : public CreatureScript
{
public:
    npc_mosswalker_victim() : CreatureScript("npc_mosswalker_victim") { }

    struct npc_mosswalker_victimAI: public ScriptedAI
    {
        npc_mosswalker_victimAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        bool PulseChecked;
        bool hasSurvived;
        bool doReset;
        uint32 action_Timer;

        void Reset()
        {
            PulseChecked = false;
            action_Timer = 5000;
            doReset = false;
        }

        void CheckPulse(Player *pPlayer)
        {
            PulseChecked = true;
            hasSurvived = (urand(0,1) == 0);
            uint32 checkrand;
            if(hasSurvived)
            {
                checkrand = urand(0,3);
                me->CastSpell(pPlayer,SPELL_MOSSWALKER_QUEST_CREDIT,true);
                me->MonsterSay(survive_sayings[checkrand],LANG_UNIVERSAL, NULL);
                action_Timer = 15000;
            }
            else
            {
                checkrand = urand(0,4);
                me->MonsterSay(dead_sayings[checkrand],LANG_UNIVERSAL, NULL);
                action_Timer = 2000;
            }
        }

        void Aggro() {}
        void MoveInLineOfSight(Unit *who) {}
        void AttackStart(Unit *who) {}
        void UpdateAI(const uint32 diff)
        {
            if(PulseChecked)
            {
                if(action_Timer <= diff)
                {
                    if(hasSurvived)
                    {
                        me->DealDamage(me,me->GetHealth());
                        me->RemoveCorpse();
                    }else
                    {
                        //Spell f�r GO fehlt noch
                        me->DealDamage(me,me->GetHealth());
                    }
                    action_Timer = 9999999;
                }else action_Timer -= diff;
            }
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action )
    {
        switch(action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            CAST_AI(npc_mosswalker_victim::npc_mosswalker_victimAI,pCreature->AI())->CheckPulse(pPlayer);
            break;
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if(pPlayer->GetQuestStatus(QUEST_THE_MOSSWALKER_SAVIOR) == QUEST_STATUS_INCOMPLETE && !CAST_AI(npc_mosswalker_victim::npc_mosswalker_victimAI,pCreature->AI())->PulseChecked)
           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_mosswalker_victimAI(pCreature);
    }

};

/*######
## npc_artruis_the_heartless
######*/

#define SPELL_ARTRUIS_FROST_NOVA            11831
#define SPELL_ARTRUIS_FROST_BOLT            15530
#define SPELL_ARTRUIS_ICY_VEINS             54792
#define SPELL_ARTRUIS_ICE_LANCE             54261

#define ENTRY_ARTRUIS_URN                   190777

class npc_artruis_the_heartless : public CreatureScript
{
public:
    npc_artruis_the_heartless() : CreatureScript("npc_artruis_the_heartless") { }

    struct npc_artruis_the_heartlessAI: public ScriptedAI
    {
        npc_artruis_the_heartlessAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 shoot_Timer;
        uint32 nova_Timer;
        uint32 veins_Timer;

        void Reset()
        {
            shoot_Timer = 2000;
            nova_Timer = urand(20000,40000);
            veins_Timer = urand(20000,40000);
        }

        bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
        {
            if(me->IsNonMeleeSpellCasted(false)) return false;

            DoCast(victim,spellId,triggered);
            return true;
        }

        void Aggro() 
        {

        }

        void JustDied(Unit *killer)
        {
            GameObject* object = me->SummonGameObject(ENTRY_ARTRUIS_URN,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,0,0,0,0,600);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if(nova_Timer <= diff)
            {
                if(TryDoCast(me,SPELL_ARTRUIS_FROST_NOVA))
                    nova_Timer = urand(20000,40000);
            }else nova_Timer -= diff;

            if(veins_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_ARTRUIS_ICY_VEINS))
                    veins_Timer = urand(20000,40000);
            }else veins_Timer -= diff;

            if(shoot_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAND(SPELL_ARTRUIS_FROST_BOLT,SPELL_ARTRUIS_ICE_LANCE)))
                    shoot_Timer = 2000;
            }else shoot_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_artruis_the_heartlessAI(pCreature);
    }

};

/*#####
## npc_jungle_punch_target
#####*/

#define SAY_OFFER     "Care to try Grimbooze Thunderbrew's new jungle punch?"
#define SAY_HEMET_1   "Aye, I'll try it."
#define SAY_HEMET_2   "That's exactly what I needed!"
#define SAY_HEMET_3   "It's got my vote! That'll put hair on your chest like nothing else will."
#define SAY_HADRIUS_1 "I'm always up for something of Grimbooze's."
#define SAY_HADRIUS_2 "Well, so far, it tastes like something my wife would drink..."
#define SAY_HADRIUS_3 "Now, there's the kick I've come to expect from Grimbooze's drinks! I like it!"
#define SAY_TAMARA_1  "Sure!"
#define SAY_TAMARA_2  "Oh my..."
#define SAY_TAMARA_3  "Tastes like I'm drinking... engine degreaser!"

enum utils
{
    NPC_HEMET   = 27986,
    NPC_HADRIUS = 28047,
    NPC_TAMARA  = 28568,
    SPELL_OFFER = 51962,
    QUEST_ENTRY = 12645,
};

class npc_jungle_punch_target : public CreatureScript
{
public:
    npc_jungle_punch_target() : CreatureScript("npc_jungle_punch_target") { }

    struct npc_jungle_punch_targetAI : public ScriptedAI
    {
        npc_jungle_punch_targetAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint16 sayTimer;
        uint8 sayStep;

        void Reset()
        {
            sayTimer = 3500;
            sayStep = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!sayStep)
                return;

            if (sayTimer < uiDiff)
            {
                switch (sayStep)
                {
                    case 0:
                    {
                        switch (me->GetEntry())
                        {
                            case NPC_HEMET:   me->MonsterSay(SAY_HEMET_1, LANG_UNIVERSAL, 0);   break;
                            case NPC_HADRIUS: me->MonsterSay(SAY_HADRIUS_1, LANG_UNIVERSAL, 0); break;
                            case NPC_TAMARA:  me->MonsterSay(SAY_TAMARA_1, LANG_UNIVERSAL, 0);  break;
                        }
                        sayTimer = 3000;
                        sayStep++;
                        break;
                    }
                    case 1:
                    {
                        switch (me->GetEntry())
                        {
                            case NPC_HEMET:   me->MonsterSay(SAY_HEMET_2, LANG_UNIVERSAL, 0);   break;
                            case NPC_HADRIUS: me->MonsterSay(SAY_HADRIUS_2, LANG_UNIVERSAL, 0); break;
                            case NPC_TAMARA:  me->MonsterSay(SAY_TAMARA_2, LANG_UNIVERSAL, 0);  break;
                        }
                        sayTimer = 3000;
                        sayStep++;
                        break;
                    }
                    case 2:
                    {
                        switch (me->GetEntry())
                        {
                            case NPC_HEMET:   me->MonsterSay(SAY_HEMET_3, LANG_UNIVERSAL, 0);   break;
                            case NPC_HADRIUS: me->MonsterSay(SAY_HADRIUS_3, LANG_UNIVERSAL, 0); break;
                            case NPC_TAMARA:  me->MonsterSay(SAY_TAMARA_3, LANG_UNIVERSAL, 0);  break;
                        }
                        sayTimer = 3000;
                        sayStep = 0;
                        break;
                    }
                }
            }
            else
                sayTimer -= uiDiff;
        }

        void SpellHit(Unit* caster, const SpellEntry* proto)
        {
            if (!proto || proto->Id != SPELL_OFFER)
                return;

            if (!caster->ToPlayer())
                return;

            QuestStatusMap::const_iterator itr = caster->ToPlayer()->getQuestStatusMap().find(QUEST_ENTRY);
            if (itr->second.m_status != QUEST_STATUS_INCOMPLETE)
                return;

            for (uint8 i=0; i<3; i++)
            {
                switch (i)
                {
                   case 0:
                       if (NPC_HEMET != me->GetEntry())
                           continue;
                       else
                           break;
                   case 1:
                       if (NPC_HADRIUS != me->GetEntry())
                           continue;
                       else
                           break;
                   case 2:
                       if (NPC_TAMARA != me->GetEntry())
                           continue;
                       else
                           break;
                }

                if (itr->second.m_creatureOrGOcount[i] != 0)
                    continue;

                caster->ToPlayer()->KilledMonsterCredit(me->GetEntry(), 0);
                caster->ToPlayer()->Say(SAY_OFFER, LANG_UNIVERSAL);
                sayStep = 0;
                break;
            }
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_jungle_punch_targetAI(pCreature);
    }
};

/*######
## npc_adventurous_dwarf
######*/

#define GOSSIP_OPTION_ORANGE    "Can you spare an orange?"
#define GOSSIP_OPTION_BANANAS   "Have a spare bunch of bananas?"
#define GOSSIP_OPTION_PAPAYA    "I could really use a papaya."

enum eAdventurousDwarf
{
    QUEST_12634         = 12634,

    ITEM_BANANAS        = 38653,
    ITEM_PAPAYA         = 38655,
    ITEM_ORANGE         = 38656,

    SPELL_ADD_ORANGE    = 52073,
    SPELL_ADD_BANANAS   = 52074,
    SPELL_ADD_PAPAYA    = 52076,

    GOSSIP_MENU_DWARF   = 13307,

    SAY_DWARF_OUCH      = -1571042,
    SAY_DWARF_HELP      = -1571043
};

class npc_adventurous_dwarf : public CreatureScript
{
public:
    npc_adventurous_dwarf() : CreatureScript("npc_adventurous_dwarf") { }

    CreatureAI *GetAI(Creature *pCreature) const
    {
        DoScriptText(SAY_DWARF_OUCH, pCreature);
        return NULL;
    }

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_12634) != QUEST_STATUS_INCOMPLETE)
            return false;

        if (pPlayer->GetItemCount(ITEM_ORANGE) < 1)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_ORANGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (pPlayer->GetItemCount(ITEM_BANANAS) < 2)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_BANANAS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        if (pPlayer->GetItemCount(ITEM_PAPAYA) < 1)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_PAPAYA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_MENU_DWARF, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        uint32 spellId = 0;
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1: spellId = SPELL_ADD_ORANGE;     break;
            case GOSSIP_ACTION_INFO_DEF + 2: spellId = SPELL_ADD_BANANAS;    break;
            case GOSSIP_ACTION_INFO_DEF + 3: spellId = SPELL_ADD_PAPAYA;     break;
        }
        if (spellId)
            pPlayer->CastSpell(pPlayer, spellId, true);
        DoScriptText(SAY_DWARF_HELP, pCreature);
        pCreature->DespawnOrUnsummon();
        return true;
    }
};

/*######
## npc_tipsy_mcmanus
######*/

enum eTipsy_mcmanus
{
    QUEST_STILL_AT_IT = 12644,
    GOSSIP_TIPSY_MCMANUS_TEXT = 13288,
    JUNGLE_PUNCH_ENTRY = 190643
};

static const uint32 GOEntry[5] = 
{   
    190635,
    190636,
    190637,
    190638,
    190639
};

static const char * Instructions[6] =
{
    "Benutze das Druckventil!",
    "Heize die Kohlenpfanne an!",
    "Wirf noch eine Orange hinein, schnell!",
    "Misch ein paar Bananen hinzu!",
    "Schnell, eine Papaya!",
    "Nein, das war falsch! Wir muessen noch einmal beginnen."
};

#define GOSSIP_ITEM_TIPSY  "Ich bin bereit, lass uns anfangen."

class npc_tipsy_mcmanus : public CreatureScript
{
public:
    npc_tipsy_mcmanus() : CreatureScript("npc_tipsy_mcmanus") { }

    struct npc_tipsy_mcmanusAI : public ScriptedAI
    {
        npc_tipsy_mcmanusAI(Creature *c) : ScriptedAI(c) {}

        bool Event;
        bool choice;
        uint8 count;
        uint32 rnd;
        uint32 react_Timer;

        void Reset()
        {
            Event = false;
            choice = true;
            rnd = 0;
            count = 0;
            react_Timer = 10*IN_MILLISECONDS;
 
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void GOUsed(uint32 entry) 
        {
            if ((!choice) && (entry == GOEntry[rnd]))   //used correct GO
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);     
                choice = true;

                react_Timer = urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (UpdateVictim())
            {
                DoMeleeAttackIfReady();
                return;
            }
        
            if (Event)  //active
            {

                if(react_Timer <= diff)
                {
                    if (choice)    //used correct GO
                    {
                        ++count;

                        if (count > 10)    //spawn quest reward and reset
                        {
                            float x, y, z;
                            me->GetPosition(x, y, z);         
                            me->SummonGameObject(JUNGLE_PUNCH_ENTRY, x + 1.2f, y + 0.8f, z - 0.23f, 0, 0, 0, 0, 0, 60);
                            Reset();
                            return;
                        }
                           
                        rnd = urand(0, 4);
                    
                        me->MonsterSay(Instructions[rnd], LANG_UNIVERSAL, 0);   //give new instructions
                        me->HandleEmoteCommand(RAND(EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_POINT));
                    
                        choice = false;  //reset choice

                    }else          //failed -> reset and try again
                    {
                        me->MonsterSay(Instructions[5], LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        Reset();
                    }
                    react_Timer = 10*IN_MILLISECONDS;

                }else react_Timer -= diff;
            }
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_tipsy_mcmanus::npc_tipsy_mcmanusAI, pCreature->AI())->Event = true;
            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_STILL_AT_IT) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TIPSY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TIPSY_MCMANUS_TEXT, pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_tipsy_mcmanusAI (pCreature);
    }

};

/*######
## go_brew_event
######*/

enum eBrewEventGO
{
    NPC_TIPSY_MCMANUS    = 28566
};

class go_brew_event : public GameObjectScript
{
public:
    go_brew_event() : GameObjectScript("go_brew_event") { }

    bool OnGossipHello (Player *pPlayer, GameObject *pGO)
    {
        uint32 entry = pGO->GetEntry();

        if (Creature* pTipsy = GetClosestCreatureWithEntry(pPlayer, NPC_TIPSY_MCMANUS, 30.0f))
            CAST_AI(npc_tipsy_mcmanus::npc_tipsy_mcmanusAI, pTipsy->AI())->GOUsed(entry);

        return false;
    }
};

void AddSC_sholazar_basin()
{
    new npc_injured_rainspeaker_oracle();
    new npc_vekjik();
    new npc_avatar_of_freya();
    new npc_bushwhacker();
    new npc_engineer_helice();
    new npc_jungle_punch_target();
    new npc_high_oracle_soo_say();
    new npc_generic_oracle_treasure_trigger();
    new npc_generic_oracle_treasure_seeker();
    new oracle_frenzyheart_switch();
    new npc_frenzyheart_zepik();
    new npc_mosswalker_victim();
    new npc_artruis_the_heartless();
    new npc_adventurous_dwarf();
    new npc_tipsy_mcmanus();
    new go_brew_event();
}