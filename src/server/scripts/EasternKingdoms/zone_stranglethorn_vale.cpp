/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Stranglethorn_Vale
SD%Complete: 100
SDComment: Quest support: 592
SDCategory: Stranglethorn Vale
EndScriptData */

/* ContentData
npc_yenniku
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "SpellInfo.h"
#include "ScriptPCH.h"
#include <cstring>

/*######
## npc_yenniku
######*/

class npc_yenniku : public CreatureScript
{
public:
    npc_yenniku() : CreatureScript("npc_yenniku") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_yennikuAI(creature);
    }

    struct npc_yennikuAI : public ScriptedAI
    {
        npc_yennikuAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            bReset = false;
        }

        void Initialize()
        {
            Reset_Timer = 0;
        }

        uint32 Reset_Timer;
        bool bReset;

        void Reset() override
        {
            Initialize();
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (bReset || spell->Id != 3607)
                return;

            if (Player* player = caster->ToPlayer())
            {
                if (player->GetQuestStatus(592) == QUEST_STATUS_INCOMPLETE) //Yenniku's Release
                {
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STUN);
                    me->CombatStop();                   //stop combat
                    me->DeleteThreatList();             //unsure of this
                    me->setFaction(83);                 //horde generic

                    bReset = true;
                    Reset_Timer = 60000;
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (bReset)
            {
                if (Reset_Timer <= diff)
                {
                    EnterEvadeMode();
                    bReset = false;
                    me->setFaction(28);                     //troll, bloodscalp
                    return;
                }

                Reset_Timer -= diff;

                if (me->IsInCombat() && me->GetVictim())
                {
                    if (Player* player = me->EnsureVictim()->ToPlayer())
                    {
                        if (player->GetTeam() == HORDE)
                        {
                            me->CombatStop();
                            me->DeleteThreatList();
                        }
                    }
                }
             }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
##
######*/


enum LandrosTexts
{
    SAY_WRONG = 1,
    SAY_CORRECT = 2
};

enum LandroMenus
{
    WELCOME                         =   8855,
    PROMOTION_MENU_TEXT             =   8856,
    PROMOTION                       =   9197
};

class landro_longshot : public CreatureScript
{
    public:

        landro_longshot(): CreatureScript("landro_longshot") { }

        int SelectedReward;

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "What promotions do you have?", GOSSIP_SENDER_MAIN, PROMOTION);
            player->SEND_GOSSIP_MENU(WELCOME, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            
            if (action != 0)
            {
                SelectedReward = action;
            }

            QueryResult GetGossipFields = WorldDatabase.PQuery("SELECT option_text, action_menu_id FROM gossip_menu_option WHERE menu_id = %u", action);
            do{
                Field* fields = GetGossipFields->Fetch();

                std::string OptionText      =   fields[0].GetString();
                uint32  ActionMenuID        =   fields[1].GetUInt32();
                if (ActionMenuID != 0)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, OptionText, GOSSIP_SENDER_MAIN, ActionMenuID);
                }
                else
                {
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, OptionText, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);
                }
            } while (GetGossipFields->NextRow());

            player->SEND_GOSSIP_MENU(PROMOTION_MENU_TEXT, creature->GetGUID());
            return true;
        }

        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
        {
            player->PlayerTalkClass->ClearMenus();
            uint32 codeUINT = (uint32)atol(code);
            if (!codeUINT)
                return false;
            QueryResult SearchForCode = WorldDatabase.PQuery("SELECT item FROM promotion_codes WHERE code = %u AND collection = %u AND used = 0", codeUINT, SelectedReward);
            if (!SearchForCode)
            {
                creature->AI()->Talk(SAY_WRONG);
            }
            else
            {
                creature->AI()->Talk(SAY_CORRECT);
                do
                {
                    Field *fields = SearchForCode->Fetch();
                    player->AddItem(fields[0].GetUInt32(), 1);
                    WorldDatabase.PQuery("Update promotion_codes SET USED = 1 WHERE code = %u", codeUINT);
                } while (SearchForCode->NextRow());
            }

            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }

};

void AddSC_stranglethorn_vale()
{
    new npc_yenniku();
    new landro_longshot();
}
