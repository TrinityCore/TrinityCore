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
SDName: Uldaman
SD%Complete: 100
SDComment: Quest support: 2240, 2278 + 1 trash mob.
SDCategory: Uldaman
EndScriptData */

/* ContentData
mob_jadespine_basilisk
npc_lore_keeper_of_norgannon
go_keystone_chamber
at_map_chamber
EndContentData */

#include "ScriptPCH.h"
#include "uldaman.h"

/*######
## mob_jadespine_basilisk
######*/

enum eSpells
{
    SPELL_CRYSTALLINE_SLUMBER   = 3636,
};

class mob_jadespine_basilisk : public CreatureScript
{
    public:

        mob_jadespine_basilisk()
            : CreatureScript("mob_jadespine_basilisk")
        {
        }

        struct mob_jadespine_basiliskAI : public ScriptedAI
        {
            mob_jadespine_basiliskAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 uiCslumberTimer;

            void Reset()
            {
                uiCslumberTimer = 2000;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //uiCslumberTimer
                if (uiCslumberTimer <= uiDiff)
                {
                    //Cast
                    DoCastVictim(SPELL_CRYSTALLINE_SLUMBER, true);

                    //Stop attacking target thast asleep and pick new target
                    uiCslumberTimer = 28000;

                    Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0);

                    if (!target || target == me->getVictim())
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                    if (target)
                        me->TauntApply(target);

                } else uiCslumberTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_jadespine_basiliskAI(creature);
        }
};

/*######
## go_keystone_chamber
######*/

class go_keystone_chamber : public GameObjectScript
{
public:
    go_keystone_chamber() : GameObjectScript("go_keystone_chamber") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (InstanceScript* instance = go->GetInstanceScript())
            instance->SetData(DATA_IRONAYA_SEAL, IN_PROGRESS); //door animation and save state.

        return false;
    }
};

/*######
## at_map_chamber
######*/

#define QUEST_HIDDEN_CHAMBER    2240

class AreaTrigger_at_map_chamber : public AreaTriggerScript
{
    public:

        AreaTrigger_at_map_chamber()
            : AreaTriggerScript("at_map_chamber")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (player->GetQuestStatus(QUEST_HIDDEN_CHAMBER) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(QUEST_HIDDEN_CHAMBER);

            return true;
        }
};

/*######
## npc_lore_keeper_of_norgannon
######*/

#define GOSSIP_HELLO_KEEPER     "Who are the Earthen?"
#define GOSSIP_SELECT_KEEPER1   "What is a \"subterranean being matrix\"?"
#define GOSSIP_SELECT_KEEPER2   "What are the anomalies you speak of?"
#define GOSSIP_SELECT_KEEPER3   "What is a resilient foundation of construction?"
#define GOSSIP_SELECT_KEEPER4   "So... the Earthen were made out of stone?"
#define GOSSIP_SELECT_KEEPER5   "Anything else I should know about the Earthen?"
#define GOSSIP_SELECT_KEEPER6   "I think I understand the Creators' design intent for the Earthen now. What are the Earthen's anomalies that you spoke of earlier?"
#define GOSSIP_SELECT_KEEPER7   "What high-stress environments would cause the Earthen to destabilize?"
#define GOSSIP_SELECT_KEEPER8   "What happens when the Earthen destabilize?"
#define GOSSIP_SELECT_KEEPER9   "Troggs?! Are the troggs you mention the same as the ones in the world today?"
#define GOSSIP_SELECT_KEEPER10  "You mentioned two results when the Earthen destabilize. What is the second?"
#define GOSSIP_SELECT_KEEPER11  "Dwarves!!! Now you're telling me that dwarves originally came from the Earthen?!"
#define GOSSIP_SELECT_KEEPER12  "These dwarves are the same ones today, yes? Do the dwarves maintain any other links to the Earthen?"
#define GOSSIP_SELECT_KEEPER13  "Who are the Creators?"
#define GOSSIP_SELECT_KEEPER14  "This is a lot to think about."
#define GOSSIP_SELECT_KEEPER15  "I will access the discs now."

class npc_lore_keeper_of_norgannon : public CreatureScript
{
    public:

        npc_lore_keeper_of_norgannon()
            : CreatureScript("npc_lore_keeper_of_norgannon")
        {
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (player->GetQuestStatus(2278) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_KEEPER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

            player->SEND_GOSSIP_MENU(1079, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    player->SEND_GOSSIP_MENU(1080, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                    player->SEND_GOSSIP_MENU(1081, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+3:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    player->SEND_GOSSIP_MENU(1082, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+4:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                    player->SEND_GOSSIP_MENU(1083, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+5:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                    player->SEND_GOSSIP_MENU(1084, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+6:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                    player->SEND_GOSSIP_MENU(1085, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+7:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
                    player->SEND_GOSSIP_MENU(1086, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+8:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
                    player->SEND_GOSSIP_MENU(1087, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+9:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
                    player->SEND_GOSSIP_MENU(1088, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+10:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER10, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
                    player->SEND_GOSSIP_MENU(1089, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+11:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+12);
                    player->SEND_GOSSIP_MENU(1090, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+12:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER12, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
                    player->SEND_GOSSIP_MENU(1091, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+13:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER13, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+14);
                    player->SEND_GOSSIP_MENU(1092, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+14:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER14, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+15);
                    player->SEND_GOSSIP_MENU(1093, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+15:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_KEEPER15, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+16);
                    player->SEND_GOSSIP_MENU(1094, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+16:
                    player->CLOSE_GOSSIP_MENU();
                    player->AreaExploredOrEventHappens(2278);
                    break;
            }
            return true;
        }
};

void AddSC_uldaman()
{
    new mob_jadespine_basilisk();
    new go_keystone_chamber();
    new AreaTrigger_at_map_chamber();
    new npc_lore_keeper_of_norgannon();
}

