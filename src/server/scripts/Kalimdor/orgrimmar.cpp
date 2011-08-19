/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

/*######
## npc_shenthul
######*/

enum eShenthul
{
    QUEST_SHATTERED_SALUTE  = 2460
};

class npc_shenthul : public CreatureScript
{
public:
    npc_shenthul() : CreatureScript("npc_shenthul") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_SHATTERED_SALUTE)
        {
            CAST_AI(npc_shenthul::npc_shenthulAI, creature->AI())->CanTalk = true;
            CAST_AI(npc_shenthul::npc_shenthulAI, creature->AI())->PlayerGUID = player->GetGUID();
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shenthulAI (creature);
    }

    struct npc_shenthulAI : public ScriptedAI
    {
        npc_shenthulAI(Creature* c) : ScriptedAI(c) {}

        bool CanTalk;
        bool CanEmote;
        uint32 Salute_Timer;
        uint32 Reset_Timer;
        uint64 PlayerGUID;

        void Reset()
        {
            CanTalk = false;
            CanEmote = false;
            Salute_Timer = 6000;
            Reset_Timer = 0;
            PlayerGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (CanEmote)
            {
                if (Reset_Timer <= diff)
                {
                    if (Player* player = Unit::GetPlayer(*me, PlayerGUID))
                    {
                        if (player->GetTypeId() == TYPEID_PLAYER && player->GetQuestStatus(QUEST_SHATTERED_SALUTE) == QUEST_STATUS_INCOMPLETE)
                            player->FailQuest(QUEST_SHATTERED_SALUTE);
                    }
                    Reset();
                } else Reset_Timer -= diff;
            }

            if (CanTalk && !CanEmote)
            {
                if (Salute_Timer <= diff)
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    CanEmote = true;
                    Reset_Timer = 60000;
                } else Salute_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote)
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

#define QUEST_6566              6566

#define SPELL_CHAIN_LIGHTNING   16033
#define SPELL_SHOCK             16034

#define GOSSIP_HTW "Please share your wisdom with me, Warchief."
#define GOSSIP_STW1 "What discoveries?"
#define GOSSIP_STW2 "Usurper?"
#define GOSSIP_STW3 "With all due respect, Warchief - why not allow them to be destroyed? Does this not strengthen our position?"
#define GOSSIP_STW4 "I... I did not think of it that way, Warchief."
#define GOSSIP_STW5 "I live only to serve, Warchief! My life is empty and meaningless without your guidance."
#define GOSSIP_STW6 "Of course, Warchief!"

//TODO: verify abilities/timers
class npc_thrall_warchief : public CreatureScript
{
public:
    npc_thrall_warchief() : CreatureScript("npc_thrall_warchief") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(5733, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(5734, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(5735, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(5736, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->SEND_GOSSIP_MENU(5737, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STW6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                player->SEND_GOSSIP_MENU(5738, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(QUEST_6566);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_6566) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HTW, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_thrall_warchiefAI (creature);
    }

    struct npc_thrall_warchiefAI : public ScriptedAI
    {
        npc_thrall_warchiefAI(Creature* c) : ScriptedAI(c) {}

        uint32 ChainLightning_Timer;
        uint32 Shock_Timer;

        void Reset()
        {
            ChainLightning_Timer = 2000;
            Shock_Timer = 8000;
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (ChainLightning_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CHAIN_LIGHTNING);
                ChainLightning_Timer = 9000;
            } else ChainLightning_Timer -= diff;

            if (Shock_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHOCK);
                Shock_Timer = 15000;
            } else Shock_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_orgrimmar()
{
    new npc_shenthul();
    new npc_thrall_warchief();
}
