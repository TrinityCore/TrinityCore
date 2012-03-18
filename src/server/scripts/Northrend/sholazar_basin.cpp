/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "Vehicle.h"

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
        npc_injured_rainspeaker_oracleAI(Creature* creature) : npc_escortAI(creature) { c_guid = creature->GetGUID(); }

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
            Player* player = GetPlayerForEscort();

            if (!player)
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
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);
                me->SetSpeed(MOVE_SWIM, 0.85f, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_DISABLE_GRAVITY);
                break;
            case 19:
                me->SetUnitMovementFlags(MOVEMENTFLAG_FALLING);
                break;
            case 28:
                player->GroupEventHappens(QUEST_FORTUNATE_MISUNDERSTANDINGS, me);
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

            if (Player* player = GetPlayerForEscort())
              if (player->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) != QUEST_STATUS_COMPLETE)
                player->FailQuest(QUEST_FORTUNATE_MISUNDERSTANDINGS);
            }
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (player->GetQuestStatus(QUEST_JUST_FOLLOWING_ORDERS) == QUEST_STATUS_INCOMPLETE
            && !creature->FindNearestCreature(ENTRY_RAVENOUS_MANGAL_CROCOLISK, 10.0f))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
            CAST_AI(npc_escortAI, (creature->AI()))->SetMaxPlayerDistance(35.0f);
            creature->SetUnitMovementFlags(MOVEMENTFLAG_FALLING);
            DoScriptText(SAY_START_IRO, creature);

            switch (player->GetTeam())
            {
            case ALLIANCE:
                creature->setFaction(FACTION_ESCORTEE_A);
                break;
            case HORDE:
                creature->setFaction(FACTION_ESCORTEE_H);
                break;
            }
        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            player->SummonCreature(ENTRY_RAVENOUS_MANGAL_CROCOLISK, *creature, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* /*_Quest*/)
    {
        DoScriptText(SAY_QUEST_ACCEPT_IRO, creature);
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

    CreatureAI* GetAI(Creature* creature) const
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

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_MAKING_PEACE) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK1, creature->GetGUID());
            return true;
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_TEXTID_VEKJIK1, creature, player);
                player->AreaExploredOrEventHappens(QUEST_MAKING_PEACE);
                creature->CastSpell(player, SPELL_FREANZYHEARTS_FURY, false);
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

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_FREYA_PACT) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR2, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR3, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->CastSpell(player, SPELL_FREYA_CONVERSATION, true);
            player->CompleteQuest(QUEST_FREYA_PACT);
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
        npc_bushwhackerAI(Creature* creature) : ScriptedAI(creature)
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

    CreatureAI* GetAI(Creature* creature) const
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
        npc_engineer_heliceAI(Creature* creature) : npc_escortAI(creature) { }

        uint32 m_uiChatTimer;

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();
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
                    if (player)
                    {
                        player->GroupEventHappens(QUEST_DISASTER, me);
                        DoScriptText(SAY_WP_7, me);
                    }
                    break;
            }
        }

        void Reset()
        {
            m_uiChatTimer = 4000;
        }
        void JustDied(Unit* /*killer*/)
        {
            Player* player = GetPlayerForEscort();
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (player)
                    player->FailQuest(QUEST_DISASTER);
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_engineer_heliceAI(creature);
    }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_DISASTER)
        {
            if (npc_engineer_heliceAI* pEscortAI = CAST_AI(npc_engineer_helice::npc_engineer_heliceAI, creature->AI()))
            {
                creature->GetMotionMaster()->MoveJumpTo(0, 0.4f, 0.4f);
                creature->setFaction(113);

                pEscortAI->Start(false, false, player->GetGUID());
                DoScriptText(SAY_WP_1, creature);
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
    TRIGGER_ID = 28088, // bad id, just not used
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

            void SpellHit(Unit* /*pCaster*/, const SpellInfo* pSpell)
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
                        //Spell for GO fehlt noch
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
        npc_jungle_punch_targetAI(Creature* creature) : ScriptedAI(creature) {}

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

        void SpellHit(Unit* caster, const SpellInfo* proto)
        {
            if (!proto || proto->Id != SPELL_OFFER)
                return;

            if (!caster->ToPlayer())
                return;

            QuestStatusMap::const_iterator itr = caster->ToPlayer()->getQuestStatusMap().find(QUEST_ENTRY);
            if (itr->second.Status != QUEST_STATUS_INCOMPLETE)
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

                if (itr->second.CreatureOrGOCount[i] != 0)
                    continue;

                caster->ToPlayer()->KilledMonsterCredit(me->GetEntry(), 0);
                caster->ToPlayer()->Say(SAY_OFFER, LANG_UNIVERSAL);
                sayStep = 0;
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jungle_punch_targetAI(creature);
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

    CreatureAI* GetAI(Creature* creature) const
    {
        DoScriptText(SAY_DWARF_OUCH, creature);
        return NULL;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_12634) != QUEST_STATUS_INCOMPLETE)
            return false;

        if (player->GetItemCount(ITEM_ORANGE) < 1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_ORANGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (player->GetItemCount(ITEM_BANANAS) < 2)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_BANANAS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        if (player->GetItemCount(ITEM_PAPAYA) < 1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION_PAPAYA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        player->PlayerTalkClass->SendGossipMenu(GOSSIP_MENU_DWARF, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        uint32 spellId = 0;
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1: spellId = SPELL_ADD_ORANGE;     break;
            case GOSSIP_ACTION_INFO_DEF + 2: spellId = SPELL_ADD_BANANAS;    break;
            case GOSSIP_ACTION_INFO_DEF + 3: spellId = SPELL_ADD_PAPAYA;     break;
        }
        if (spellId)
            player->CastSpell(player, spellId, true);
        DoScriptText(SAY_DWARF_HELP, creature);
        creature->DespawnOrUnsummon();
        return true;
    }
};

/*######
## npc_tipsy_mcmanus
######*/

enum TipsyMcManus
{
    DATA_EVENT                 = 1,
    DATA_OBJECT_ENTRY          = 2,
    QUEST_STILL_AT_IT          = 12644,
    GOSSIP_TIPSY_MCMANUS_TEXT  = 13288,
    GO_JUNGLE_PUNCH            = 190643
};

static uint32 const goEntry[5] =
{
    190635,
    190636,
    190637,
    190638,
    190639
};

static char const* Instructions[6] =
{
    "Use la valvula de presion!",
    "Calienta a las brasas!",
    "Tirar una naranja todavia en eso, date prisa!",
    "Mezcla de unos cuantos platanos!",
    "Rapido, una Papaya!",
    "No, eso estuvo mal! Tenemos que comenzar de nevo."
};

#define GOSSIP_ITEM_TIPSY  "Estoy listo, vamos a comenzar."

class npc_tipsy_mcmanus : public CreatureScript
{
    public:
        npc_tipsy_mcmanus() : CreatureScript("npc_tipsy_mcmanus") { }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                player->CLOSE_GOSSIP_MENU();
                creature->AI()->SetData(DATA_EVENT, 1);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (player->GetQuestStatus(QUEST_STILL_AT_IT) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TIPSY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->SEND_GOSSIP_MENU(GOSSIP_TIPSY_MCMANUS_TEXT, creature->GetGUID());
            return true;
        }

        struct npc_tipsy_mcmanusAI : public ScriptedAI
        {
            npc_tipsy_mcmanusAI(Creature* c) : ScriptedAI(c) {}

            void Reset()
            {
                _event = false;
                _choice = true;
                _rnd = 0;
                _count = 0;
                _reactTimer = 10000;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void SetData(uint32 id, uint32 data)
            {
                switch (id)
                {
                    case DATA_EVENT:
                        _event = data ? true : false;
                        break;
                    case DATA_OBJECT_ENTRY:
                        if (!_choice && data == goEntry[_rnd]) // used correct object
                        {
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                            _choice = true;
                            _reactTimer = urand(5000, 7000);
                        }
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (UpdateVictim())
                {
                    DoMeleeAttackIfReady();
                    return;
                }

                if (_event) // active
                {
                    if(_reactTimer <= diff)
                    {
                        if (_choice) // used correct object
                        {
                            ++_count;

                            if (_count > 10) // spawn quest reward and reset
                            {
                                float x, y, z;
                                me->GetPosition(x, y, z);
                                me->SummonGameObject(GO_JUNGLE_PUNCH, x + 1.2f, y + 0.8f, z - 0.23f, 0, 0, 0, 0, 0, 60);
                                Reset();
                                return;
                            }

                            _rnd = urand(0, 4);
                            me->MonsterSay(Instructions[_rnd], LANG_UNIVERSAL, 0); // give new instructions
                            me->HandleEmoteCommand(RAND(EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_POINT));
                            _choice = false; // reset choice
                        }
                        else // failed -> reset and try again
                        {
                            me->MonsterSay(Instructions[5], LANG_UNIVERSAL, 0);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            Reset();
                            return;
                        }

                        _reactTimer = 10000;
                    }
                    else
                        _reactTimer -= diff;
                }
            }

        private:
            bool _event;
            bool _choice;
            uint8 _count;
            uint8 _rnd;
            uint32 _reactTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tipsy_mcmanusAI(creature);
        }
};

/*######
## go_brew_event
######*/

enum BrewEvent
{
    NPC_TIPSY_MCMANUS = 28566
};

class go_brew_event : public GameObjectScript
{
    public:
        go_brew_event() : GameObjectScript("go_brew_event") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            if (Creature* Tipsy = go->FindNearestCreature(NPC_TIPSY_MCMANUS, 30.0f, true))
                Tipsy->AI()->SetData(DATA_OBJECT_ENTRY, go->GetEntry());

            return false;
        }
};

/*######
## npc_stormwatcher
######*/

enum eSpells
{
    SPELL_CALL_LIGHTNING                = 32018,
    SPELL_THROW_VENTURE_CO_EXPLOSIVES   = 53145,
    SPELL_SUMMON_STORMWATCHERS_HEAD     = 53162
};

class npc_stormwatcher : public CreatureScript
{
    public:
        npc_stormwatcher() : CreatureScript("npc_stormwatcher"){ }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_stormwatcherAI(pCreature);
        }

        struct npc_stormwatcherAI : public ScriptedAI
        {
            npc_stormwatcherAI(Creature* pCreature) : ScriptedAI (pCreature){ }

            uint32 uiCallLightning_Timer;

            void Reset()
            {
                uiCallLightning_Timer = urand (3000,5000);
            }

            void SpellHit (Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_THROW_VENTURE_CO_EXPLOSIVES)
                {
                    DoCast(me, SPELL_SUMMON_STORMWATCHERS_HEAD, true);
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (uiCallLightning_Timer <= diff)
                {
                    DoCastVictim(SPELL_CALL_LIGHTNING);
                    uiCallLightning_Timer = urand (3000,5000);
                }
                else uiCallLightning_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
};

/*######
## Quest: Rejek: First Blood
######*/

enum enums
{
    ENTRY_SAPPHIRE_HIVE_WASP    = 28086,
    ENTRY_HARDKNUCKLE_CHARGER   = 28096,
    ENTRY_MISTWHISPER_ORACLE    = 28110,
    ENTRY_MISTWHISPER_WARRIOR   = 28109,
    // Kill Credit Entries from quest_template
    NPC_CREDIT_1                = 28040,
    NPC_CREDIT_2                = 36189,
    NPC_CREDIT_3                = 29043,

    SPELL_BLOOD_REJEKS_SWORD    = 52992,
    SPELL_WASP_STINGER_RAGE     = 34392,
    SPELL_CHARGER_CHARGE        = 49758,
    SPELL_ORACLE_LIGHTNING_CLOUD= 54921,
    SPELL_WARRIOR_FLIP_ATTACK   = 50533
};

class npc_rejek_first_blood : public CreatureScript
{
    public:
        npc_rejek_first_blood() : CreatureScript("npc_rejek_first_blood"){ }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_rejek_first_bloodAI(pCreature);
        }

        struct npc_rejek_first_bloodAI : public ScriptedAI
        {
            npc_rejek_first_bloodAI(Creature* pCreature) : ScriptedAI (pCreature){ }

            uint32 uiFlipAttack_Timer;
            uint32 uiCharge_Timer;
            
            bool Frenzied;

            void Reset()
            {
                uiFlipAttack_Timer = urand (2000,6000);
                uiCharge_Timer = 0;
            }

            void EnterCombat (Unit* /*who*/)
            {
                Frenzied = false;

                if(me->GetEntry() == ENTRY_MISTWHISPER_ORACLE)
                    DoCast(me, SPELL_ORACLE_LIGHTNING_CLOUD, true);
            }

            void SpellHit (Unit* caster, SpellInfo const* spell)
            {
                if(spell->Id == SPELL_BLOOD_REJEKS_SWORD)
                {
                    if(caster && caster->ToPlayer())
                    {
                        switch(me->GetEntry())
                        {
                            case ENTRY_SAPPHIRE_HIVE_WASP:
                                caster->ToPlayer()->KilledMonsterCredit(NPC_CREDIT_1,0);
                                break;
                            case ENTRY_HARDKNUCKLE_CHARGER:
                                caster->ToPlayer()->KilledMonsterCredit(NPC_CREDIT_2,0);
                                break;
                            case ENTRY_MISTWHISPER_ORACLE:
                            case ENTRY_MISTWHISPER_WARRIOR:
                                caster->ToPlayer()->KilledMonsterCredit(NPC_CREDIT_3,0);
                                break;
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if(!UpdateVictim())
                    return;

                if(me->GetEntry() == ENTRY_SAPPHIRE_HIVE_WASP)
                {
                    if(!Frenzied && HealthBelowPct(30))
                    {
                        DoCast(me, SPELL_WASP_STINGER_RAGE, true);
                        Frenzied = true;
                    }
                }

                if(me->GetEntry() == ENTRY_HARDKNUCKLE_CHARGER)
                {
                    if(uiCharge_Timer <= diff)
                    {
                        DoCastVictim(SPELL_CHARGER_CHARGE);
                        uiCharge_Timer = 5000;
                    }
                    else uiCharge_Timer -= diff;
                }

                if(me->GetEntry() == ENTRY_MISTWHISPER_WARRIOR)
                {
                    if(uiFlipAttack_Timer <= diff)
                    {
                        DoCastVictim(SPELL_WARRIOR_FLIP_ATTACK);
                        uiFlipAttack_Timer = urand (4000,7000);
                    }
                    else uiFlipAttack_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        };
};

/*######
## vehicle_haiphoon
######*/

enum eHaiphoon
{
    SPELL_DEVOUR_WIND       = 52862,
    SPELL_DEVOUR_WATER      = 52864,

    NPC_HAIPHOON_WATER      = 28999,
    NPC_HAIPHOON_AIR        = 28985
};

class vehicle_haiphoon : public CreatureScript
{
public:
    vehicle_haiphoon() : CreatureScript("vehicle_haiphoon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  vehicle_haiphoonAI(pCreature);
    }

    struct vehicle_haiphoonAI : public VehicleAI
    {
        vehicle_haiphoonAI(Creature* pCreature) : VehicleAI(pCreature) { }

        void SpellHitTarget(Unit* target,SpellInfo const* spell)
        {
            if(target == me)
                return;       
        
            if(spell->Id == SPELL_DEVOUR_WIND)
            {
                if(Player* player = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    player->KilledMonsterCredit(29009, 0);
                    me->UpdateEntry(NPC_HAIPHOON_AIR);                    
                    player->VehicleSpellInitialize();
                    me->setFaction(player->getFaction());
                }
            }

            if(spell->Id == SPELL_DEVOUR_WATER)
            {
                if(Player* player = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    player->KilledMonsterCredit(29008, 0);                    
                    me->UpdateEntry(NPC_HAIPHOON_WATER);
                    player->VehicleSpellInitialize();
                    me->setFaction(player->getFaction());
                }
            }
        }
    };
};

const Position CaptiveCrocWaypoints[32] =
{
    {5296.98f, 4449.35f, -97.6785f, 0.0f},
    {5268.84f, 4431.05f, -95.9974f, 0.0f},
    {5253.46f, 4394.40f, -95.0352f, 0.0f},
    {5263.19f, 4365.86f, -98.5669f, 0.0f},
    {5284.49f, 4366.25f, -101.402f, 0.0f},
    {5297.54f, 4358.85f, -105.052f, 0.0f},
    {5354.68f, 4361.32f, -128.512f, 0.0f},
    {5378.45f, 4313.85f, -147.025f, 0.0f},
    {5418.90f, 4345.02f, -146.904f, 0.0f},
    {5448.35f, 4407.74f, -146.738f, 0.0f},
    {5511.23f, 4457.99f, -146.229f, 0.0f},
    {5507.92f, 4540.06f, -145.055f, 0.0f},
    {5496.91f, 4565.59f, -141.307f, 0.0f},
    {5489.50f, 4608.78f, -138.538f, 0.0f},
    {5506.16f, 4640.55f, -134.925f, 0.0f},
    {5577.96f, 4664.14f, -134.699f, 0.0f},
    {5615.76f, 4702.42f, -136.552f, 0.0f},
    {5631.72f, 4729.98f, -134.209f, 0.0f},
    {5648.63f, 4749.76f, -140.618f, 0.0f},
    {5667.33f, 4777.87f, -141.298f, 0.0f},
    {5697.99f, 4814.09f, -139.960f, 0.0f},
    {5707.43f, 4829.78f, -135.915f, 0.0f},
    {5796.30f, 4840.33f, -133.721f, 0.0f},
    {5818.77f, 4842.79f, -140.250f, 0.0f},
    {5851.73f, 4834.99f, -134.428f, 0.0f},
    {5886.75f, 4832.68f, -129.530f, 0.0f},
    {5925.07f, 4836.92f, -113.021f, 0.0f},
    {5948.74f, 4843.23f, -103.147f, 0.0f},
    {5984.39f, 4858.27f, -98.9468f, 0.0f},
    {6055.89f, 4888.39f, -94.4171f, 0.0f},
    {6129.51f, 4929.48f, -95.6752f, 0.0f},
    {6153.20f, 4942.70f, -90.4089f, 0.0f}
};
#define GOSSIP_ITEM_B "Travel to Refuge Susurraneblina"

class npc_captive_croco_gossip : public CreatureScript
{
public:
    npc_captive_croco_gossip() : CreatureScript("npc_captive_croco_gossip") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {

        if (player->GetQuestStatus(12536) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_B, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->CLOSE_GOSSIP_MENU();

        if (!player->HasUnitState(UNIT_STATE_ONVEHICLE))
        {
            if (Creature* pTemp = player->SummonCreature(28308, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0))
            {
                pTemp->SetCreatorGUID(player->GetGUID());
                player->EnterVehicle(pTemp, 0);
            }
            if (Unit* base = player->GetVehicleBase())
                if (base->isCharmed())
                    base->RemoveCharmedBy(base->GetCharmer());
        }
        return true;
    }
};

class npc_captive_croco_vehicle : public CreatureScript
{
public:
    npc_captive_croco_vehicle() : CreatureScript("npc_captive_croco_vehicle") { }

    struct npc_captive_croco_vehicleAI : public ScriptedAI
    {
        npc_captive_croco_vehicleAI(Creature* creature) : ScriptedAI(creature) { }

        uint8 count;
        uint64 uiPlayer;
        bool occupied;
        bool wp_reached;
        bool movementStarted;

        void Reset()
        {
            me->SetSpeed(MOVE_SWIM, 2.0f, true);
            count = 0;
            occupied = false;
            wp_reached = false;
            movementStarted = false;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != count)
                return;

            if (id < 31)
            {
                Unit* player = me->GetVehicleKit()->GetPassenger(0);
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                {
                    ++count;
                    wp_reached = true;
                }
                else
                    me->DisappearAndDie();
            }
            else // reached questgiver, give credit
            {
                Unit* player = me->GetVehicleKit()->GetPassenger(0);
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                {
                    player->ToPlayer()->CompleteQuest(12536);
                    player->ExitVehicle();
                }
                me->DisappearAndDie();
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!me->isCharmed() && !movementStarted)
            {
                movementStarted = true;
                wp_reached = true;
            }

            if (wp_reached)
            {
                wp_reached = false;
                me->GetMotionMaster()->MovePoint(count, CaptiveCrocWaypoints[count]);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_captive_croco_vehicleAI(creature);
    }
};

#define GOSSIP_ITEM_ZEPIK "Some need extra way to talk to Zepik."

class npc_harkek_gossip : public CreatureScript
{
public:
    npc_harkek_gossip() : CreatureScript("npc_harkek_gossip") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {

        if ((player->GetQuestStatus(12536) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(12536) == QUEST_STATUS_REWARDED) && !player->HasItemCount(38512, 1))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ZEPIK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player, 52545, false);
        return true;
    }
};

enum stillEvents
{
    EVENT_BANANA_CLICK,
    EVENT_ORANGE_CLICK,
    EVENT_PAPAYA_CLICK,
    EVENT_VALVE_CLICK,
    EVENT_BRAZIER_CLICK
};

class go_still_tools : public GameObjectScript
{
public:
    go_still_tools(): GameObjectScript("go_still_tools") {}

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Creature *pTipsy = go->FindNearestCreature(28566, 15.0f))
            {
                switch(go->GetEntry())
                {
                    case 190639: // Barrel of Papayas
                        pTipsy->AI()->DoAction(EVENT_PAPAYA_CLICK);
                        break;
                    case 190638: // Barrel of Bananas
                        pTipsy->AI()->DoAction(EVENT_BANANA_CLICK);
                        break;
                    case 190637: //Barrel of Oranges
                        pTipsy->AI()->DoAction(EVENT_ORANGE_CLICK);
                        break;
                    case 190636: // Brazier
                        pTipsy->AI()->DoAction(EVENT_BRAZIER_CLICK);
                        break;
                    case 190635: // Preassure Valve
                        pTipsy->AI()->DoAction(EVENT_VALVE_CLICK);
                        break;
                }
            }
            return true;
        }
};

/*######
## Quest The Lifewarden's Wrath
######*/

enum MiscLifewarden
{
    NPC_PRESENCE = 28563, // Freya's Presence
    NPC_SABOTEUR = 28538, // Cultist Saboteur
    NPC_SERVANT = 28320, // Servant of Freya

    WHISPER_ACTIVATE = 0,

    SPELL_FREYA_DUMMY = 51318,
    SPELL_LIFEFORCE = 51395,
    SPELL_FREYA_DUMMY_TRIGGER = 51335,
    SPELL_LASHER_EMERGE = 48195,
    SPELL_WILD_GROWTH = 52948,
};

class spell_q12620_the_lifewarden_wrath : public SpellScriptLoader
{
public:
    spell_q12620_the_lifewarden_wrath() : SpellScriptLoader("spell_q12620_the_lifewarden_wrath") { }

    class spell_q12620_the_lifewarden_wrath_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q12620_the_lifewarden_wrath_SpellScript);

        void HandleSendEvent(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            if (Unit* caster = GetCaster())
            {
                if (Creature* presence = caster->FindNearestCreature(NPC_PRESENCE, 50.0f))
                {
                    presence->AI()->Talk(WHISPER_ACTIVATE, caster->GetGUID());
                    presence->CastSpell(presence, SPELL_FREYA_DUMMY, true); // will target plants
                    // Freya Dummy could be scripted with the following code

                    // Revive plants
                    std::list<Creature*> servants;
                    GetCaster()->GetCreatureListWithEntryInGrid(servants, NPC_SERVANT, 200.0f);
                    for (std::list<Creature*>::iterator itr = servants.begin(); itr != servants.end(); ++itr)
                    {
                        // Couldn't find a spell that does this
                        if ((*itr)->isDead())
                            (*itr)->Respawn(true);

                        (*itr)->CastSpell(*itr, SPELL_FREYA_DUMMY_TRIGGER, true);
                        (*itr)->CastSpell(*itr, SPELL_LASHER_EMERGE, false);
                        (*itr)->CastSpell(*itr, SPELL_WILD_GROWTH, false);

                        if (Unit* target = (*itr)->SelectNearestTarget(150.0f))
                            (*itr)->AI()->AttackStart(target);
                    }

                    // Kill nearby enemies
                    std::list<Creature*> saboteurs;
                    caster->GetCreatureListWithEntryInGrid(saboteurs, NPC_SABOTEUR, 200.0f);
                    for (std::list<Creature*>::iterator itr = saboteurs.begin(); itr != saboteurs.end(); ++itr)
                        if ((*itr)->isAlive())
                            // Lifeforce has a cast duration, it should be cast at all saboteurs one by one
                            presence->CastSpell((*itr), SPELL_LIFEFORCE, false);
                }
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_q12620_the_lifewarden_wrath_SpellScript::HandleSendEvent, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12620_the_lifewarden_wrath_SpellScript();
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
    new npc_stormwatcher();
    new npc_rejek_first_blood();
    new vehicle_haiphoon();	
    new npc_captive_croco_gossip();
    new npc_captive_croco_vehicle();
    new npc_harkek_gossip();	
    new spell_q12620_the_lifewarden_wrath();
}
