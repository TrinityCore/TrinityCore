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
SDName: Orgrimmar
SD%Complete: 100
SDComment: Quest support: 2460, 6566
SDCategory: Orgrimmar
EndScriptData */

/* ContentData
npc_shenthul
npc_thrall_warchief
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*######
## npc_shenthul
######*/

enum Shenthul
{
    QUEST_SHATTERED_SALUTE  = 2460
};

class npc_shenthul : public CreatureScript
{
public:
    npc_shenthul() : CreatureScript("npc_shenthul") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_SHATTERED_SALUTE)
        {
            ENSURE_AI(npc_shenthul::npc_shenthulAI, creature->AI())->CanTalk = true;
            ENSURE_AI(npc_shenthul::npc_shenthulAI, creature->AI())->PlayerGUID = player->GetGUID();
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shenthulAI(creature);
    }

    struct npc_shenthulAI : public ScriptedAI
    {
        npc_shenthulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            CanTalk = false;
            CanEmote = false;
            SaluteTimer = 6000;
            ResetTimer = 0;
            PlayerGUID.Clear();
        }

        bool CanTalk;
        bool CanEmote;
        uint32 SaluteTimer;
        uint32 ResetTimer;
        ObjectGuid PlayerGUID;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (CanEmote)
            {
                if (ResetTimer <= diff)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    {
                        if (player->GetTypeId() == TYPEID_PLAYER && player->GetQuestStatus(QUEST_SHATTERED_SALUTE) == QUEST_STATUS_INCOMPLETE)
                            player->FailQuest(QUEST_SHATTERED_SALUTE);
                    }
                    Reset();
                } else ResetTimer -= diff;
            }

            if (CanTalk && !CanEmote)
            {
                if (SaluteTimer <= diff)
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    CanEmote = true;
                    ResetTimer = 60000;
                } else SaluteTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            if (emote == TEXT_EMOTE_SALUTE && player->GetQuestStatus(QUEST_SHATTERED_SALUTE) == QUEST_STATUS_INCOMPLETE)
            {
                if (CanEmote)
                {
                    player->AreaExploredOrEventHappens(QUEST_SHATTERED_SALUTE);
                    Reset();
                }
            }
        }
    };

};

/*######
## npc_thrall_warchief
######*/

enum ThrallWarchief
{
    GOSSIP_MENU_OPTION_ID_ALL   = 0,

    OPTION_PLEASE_SHARE_YOUR    = 3664,
    OPTION_WHAT_DISCOVERIES     = 3665,
    OPTION_USURPER              = 3666,
    OPTION_WITH_ALL_DUE_RESPECT = 3667,
    OPTION_I_I_DID_NOT_THINK_OF = 3668,
    OPTION_I_LIVE_ONLY_TO_SERVE = 3669,
    OPTION_OF_COURSE_WARCHIEF   = 3670,

    GOSSIP_MEMBERS_OF_THE_HORDE = 4477,
    GOSSIP_THE_SHATTERED_HAND   = 5733,
    GOSSIP_IT_WOULD_APPEAR_AS   = 5734,
    GOSSIP_THE_BROOD_MOTHER     = 5735,
    GOSSIP_SO_MUCH_TO_LEARN     = 5736,
    GOSSIP_I_DO_NOT_FAULT_YOU   = 5737,
    GOSSIP_NOW_PAY_ATTENTION    = 5738,

    QUEST_WHAT_THE_WIND_CARRIES = 6566,

    SPELL_CHAIN_LIGHTNING       = 16033,
    SPELL_SHOCK                 = 16034
};

/// @todo verify abilities/timers
class npc_thrall_warchief : public CreatureScript
{
public:
    npc_thrall_warchief() : CreatureScript("npc_thrall_warchief") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM_DB(OPTION_WHAT_DISCOVERIES, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_THE_SHATTERED_HAND, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM_DB(OPTION_USURPER, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(GOSSIP_IT_WOULD_APPEAR_AS, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM_DB(OPTION_WITH_ALL_DUE_RESPECT, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(GOSSIP_THE_BROOD_MOTHER, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM_DB(OPTION_I_I_DID_NOT_THINK_OF, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(GOSSIP_SO_MUCH_TO_LEARN, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM_DB(OPTION_I_LIVE_ONLY_TO_SERVE, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->SEND_GOSSIP_MENU(GOSSIP_I_DO_NOT_FAULT_YOU, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM_DB(OPTION_OF_COURSE_WARCHIEF, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                player->SEND_GOSSIP_MENU(GOSSIP_NOW_PAY_ATTENTION, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(QUEST_WHAT_THE_WIND_CARRIES);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_WHAT_THE_WIND_CARRIES) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM_DB(OPTION_PLEASE_SHARE_YOUR, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(GOSSIP_MEMBERS_OF_THE_HORDE, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_warchiefAI(creature);
    }

    struct npc_thrall_warchiefAI : public ScriptedAI
    {
        npc_thrall_warchiefAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ChainLightningTimer = 2000;
            ShockTimer = 8000;
        }

        uint32 ChainLightningTimer;
        uint32 ShockTimer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (ChainLightningTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainLightningTimer = 9000;
            } else ChainLightningTimer -= diff;

            if (ShockTimer <= diff)
            {
                DoCastVictim(SPELL_SHOCK);
                ShockTimer = 15000;
            } else ShockTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_orgrimmar()
{
    new npc_shenthul();
    new npc_thrall_warchief();
}
