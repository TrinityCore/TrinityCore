/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Silithus
SD%Complete: 100
SDComment: Quest support: 7785, 8304.
SDCategory: Silithus
EndScriptData */

/* ContentData
npc_highlord_demitrian
npcs_rutgar_and_frankal
go_wind_stone
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Group.h"

/*###
## npc_highlord_demitrian
###*/

#define GOSSIP_DEMITRIAN1 "What do you know of it?"
#define GOSSIP_DEMITRIAN2 "I am listening, Demitrian."
#define GOSSIP_DEMITRIAN3 "Continue, please."
#define GOSSIP_DEMITRIAN4 "A battle?"
#define GOSSIP_DEMITRIAN5 "<Nod>"
#define GOSSIP_DEMITRIAN6 "Caught unaware? How?"
#define GOSSIP_DEMITRIAN7 "So what did Ragnaros do next?"

class npc_highlord_demitrian : public CreatureScript
{
public:
    npc_highlord_demitrian() : CreatureScript("npc_highlord_demitrian") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(6842, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(6843, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(6844, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(6867, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            player->SEND_GOSSIP_MENU(6868, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            player->SEND_GOSSIP_MENU(6869, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            player->SEND_GOSSIP_MENU(6870, creature->GetGUID());

            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 19016, 1);
            if (msg == EQUIP_ERR_OK)
                player->StoreNewItem(dest, 19016, true);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(7785) == QUEST_STATUS_NONE &&
            (player->HasItemCount(18563, 1, false) || player->HasItemCount(18564, 1, false)))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(6812, creature->GetGUID());
            return true;
    }

};

/*###
## npcs_rutgar_and_frankal
###*/

//gossip item text best guess
#define GOSSIP_ITEM1 "I seek information about Natalia"

#define GOSSIP_ITEM2 "That sounds dangerous!"
#define GOSSIP_ITEM3 "What did you do?"
#define GOSSIP_ITEM4 "Who?"
#define GOSSIP_ITEM5 "Women do that. What did she demand?"
#define GOSSIP_ITEM6 "What do you mean?"
#define GOSSIP_ITEM7 "What happened next?"

#define GOSSIP_ITEM11 "Yes, please continue"
#define GOSSIP_ITEM12 "What language?"
#define GOSSIP_ITEM13 "The Priestess attacked you?!"
#define GOSSIP_ITEM14 "I should ask the monkey about this"
#define GOSSIP_ITEM15 "Then what..."

enum RutgarAndFrankal //trigger creatures to kill
{
    TRIGGER_FRANKAL     = 15221,
    TRIGGER_RUTGAR      = 15222
};

class npcs_rutgar_and_frankal : public CreatureScript
{
public:
    npcs_rutgar_and_frankal() : CreatureScript("npcs_rutgar_and_frankal") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(7755, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(7756, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(7757, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                player->SEND_GOSSIP_MENU(7758, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                player->SEND_GOSSIP_MENU(7759, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                player->SEND_GOSSIP_MENU(7760, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 6:
                player->SEND_GOSSIP_MENU(7761, creature->GetGUID());
                                                                //'kill' our trigger to update quest status
                player->KilledMonsterCredit(TRIGGER_RUTGAR, 0);
                break;

            case GOSSIP_ACTION_INFO_DEF + 9:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                player->SEND_GOSSIP_MENU(7762, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 10:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM12, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                player->SEND_GOSSIP_MENU(7763, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 11:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM13, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                player->SEND_GOSSIP_MENU(7764, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 12:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM14, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                player->SEND_GOSSIP_MENU(7765, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 13:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM15, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
                player->SEND_GOSSIP_MENU(7766, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 14:
                player->SEND_GOSSIP_MENU(7767, creature->GetGUID());
                                                                //'kill' our trigger to update quest status
                player->KilledMonsterCredit(TRIGGER_FRANKAL, 0);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(8304) == QUEST_STATUS_INCOMPLETE &&
            creature->GetEntry() == 15170 &&
            !player->GetReqKillOrCastCurrentCount(8304, TRIGGER_RUTGAR))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        if (player->GetQuestStatus(8304) == QUEST_STATUS_INCOMPLETE &&
            creature->GetEntry() == 15171 &&
            player->GetReqKillOrCastCurrentCount(8304, TRIGGER_RUTGAR))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);

        player->SEND_GOSSIP_MENU(7754, creature->GetGUID());

        return true;
    }

};

/*###
## go_wind_stone
###*/

enum WSSpells
{
    SPELL_PUNISHMENT = 24803,
    SPELL_SPAWN_IN = 25035,

    AURA_TWILIGHT_SET = 24746,
    AURA_MEDALLION = 24748,
    AURA_RING = 24782,

    SPELL_TEMPLAR_RANDOM = 24745,
    SPELL_TEMPLAR_FIRE = 24747,
    SPELL_TEMPLAR_AIR = 24757,
    SPELL_TEMPLAR_EARTH = 24759,
    SPELL_TEMPLAR_WATER = 24761,

    SPELL_DUKE_RANDOM = 24762,
    SPELL_DUKE_FIRE = 24766,
    SPELL_DUKE_AIR = 24769,
    SPELL_DUKE_EARTH = 24771,
    SPELL_DUKE_WATER = 24773,

    SPELL_ROYAL_RANDOM = 24785,
    SPELL_ROYAL_FIRE = 24787,
    SPELL_ROYAL_AIR = 24791,
    SPELL_ROYAL_EARTH = 24792,
    SPELL_ROYAL_WATER = 24793
};

enum WSGossip
{
    GOSSIPID_LESSER_WS = 6540,
    GOSSIPID_WS = 6542,
    GOSSIPID_GREATER_WS = 6543
};

enum WSCreatures
{
    NPC_TEMPLAR_FIRE = 15209,
    NPC_TEMPLAR_WATER = 15211,
    NPC_TEMPLAR_AIR = 15212,
    NPC_TEMPLAR_EARTH = 15307,

    NPC_DUKE_FIRE = 15206,
    NPC_DUKE_WATER = 15207,
    NPC_DUKE_EARTH = 15208,
    NPC_DUKE_AIR = 15220,

    NPC_ROYAL_FIRE = 15203,
    NPC_ROYAL_AIR = 15204,
    NPC_ROYAL_EARTH = 15205,
    NPC_ROYAL_WATER = 15305
};

enum WSItems
{
    ITEM_TEMPLAR_FIRE = 20416,
    ITEM_TEMPLAR_EARTH =  20419,
    ITEM_TEMPLAR_WATER = 20420,
    ITEM_TEMPLAR_AIR = 20418,

    ITEM_DUKE_FIRE = 20432,
    ITEM_DUKE_EARTH =  20435,
    ITEM_DUKE_WATER = 20436,
    ITEM_DUKE_AIR = 20433,

    ITEM_ROYAL_FIRE = 20447,
    ITEM_ROYAL_EARTH =  20449,
    ITEM_ROYAL_WATER = 20450,
    ITEM_ROYAL_AIR = 20448,
};

enum WS
{
    TEMPLAR = 0,
    DUKE = 1,
    ROYAL = 2,

    FIRE = 0x1,
    WATER = 0x2,
    EARTH = 0x4,
    AIR = 0x8
};

enum WSTexts
{
    SAY_TEMPLAR_AGGRO = 0,
    SAY_DUKE_AGGRO = 0,
    YELL_ROYAL_AGGRO = 0
};

#define GOSSIP_TEMPLAR_RANDOM "I am no cultist, you monster! Come to me and face your destruction!"
#define GOSSIP_TEMPLAR_FIRE "Crimson Templar! I hold your signet! Heed my call!"
#define GOSSIP_TEMPLAR_EARTH "Earthen Templar! I hold your signet! Heed my call!"
#define GOSSIP_TEMPLAR_AIR "Hoary Templar! I hold your signet! Heed my call!"
#define GOSSIP_TEMPLAR_WATER "Azure Templar! I hold your signet! Heed my call!"

#define GOSSIP_DUKE_RANDOM "You will listen to this, vile duke! I am not your Twilight's Hammer lapdog! I am here to challenge you! Come! Come, and meet your death..."
#define GOSSIP_DUKE_FIRE "Duke of Cynders! I hold your signet! Heed my call!"
#define GOSSIP_DUKE_EARTH "The Duke of Shards! I hold your signet! Heed my call!"
#define GOSSIP_DUKE_AIR "The Duke of Zephyrs! I hold your signet! Heed my call!"
#define GOSSIP_DUKE_WATER "The Duke of Fathoms! I hold your signet! Heed my call!"

#define GOSSIP_ROYAL_RANDOM "The day of the judgement has come, fiend! I challenge you to battle!"
#define GOSSIP_ROYAL_FIRE "Prince Skaldrenox! I hold your signet! Heed my call!"
#define GOSSIP_ROYAL_EARTH "Baron Kazum! I hold your signet! Heed my call!"
#define GOSSIP_ROYAL_AIR "High Marshal Whirlaxis! I hold your signet! Heed my call!"
#define GOSSIP_ROYAL_WATER "Lord Skwol! I hold your signet! Heed my call!"

class go_wind_stone : public GameObjectScript
{
    public:
        go_wind_stone() : GameObjectScript("go_wind_stone") { }

    private:
        uint8 GetPlayerRank(Player* player) // For random summoning
        {
            bool setAura = player->HasAura(AURA_TWILIGHT_SET);
            bool medallionAura = player->HasAura(AURA_MEDALLION);
            bool ringAura = player->HasAura(AURA_RING);

            if (setAura && medallionAura && ringAura)
                return 3;
            else if (setAura && medallionAura)
                return 2;
            else if (setAura)
                return 1;
            else
                return 0;
        }

        uint8 GetItems(Player* player, WS type)
        {
            uint8 result = 0x0;

            switch (type)
            {
                case TEMPLAR:
                {
                    if (player->HasItemCount(ITEM_TEMPLAR_FIRE))
                        result |= FIRE;
                    if (player->HasItemCount(ITEM_TEMPLAR_WATER))
                        result |= WATER;
                    if (player->HasItemCount(ITEM_TEMPLAR_EARTH))
                        result |= EARTH;
                    if (player->HasItemCount(ITEM_TEMPLAR_AIR))
                        result |= AIR;
                    break;
                }
                case DUKE:
                {
                    if (player->HasItemCount(ITEM_DUKE_FIRE))
                        result |= FIRE;
                    if (player->HasItemCount(ITEM_DUKE_WATER))
                        result |= WATER;
                    if (player->HasItemCount(ITEM_DUKE_EARTH))
                        result |= EARTH;
                    if (player->HasItemCount(ITEM_DUKE_AIR))
                        result |= AIR;
                    break;
                }
                case ROYAL:
                {
                    if (player->HasItemCount(ITEM_ROYAL_FIRE))
                        result |= FIRE;
                    if (player->HasItemCount(ITEM_ROYAL_WATER))
                        result |= WATER;
                    if (player->HasItemCount(ITEM_ROYAL_EARTH))
                        result |= EARTH;
                    if (player->HasItemCount(ITEM_ROYAL_AIR))
                        result |= AIR;
                    break;
                }
                default:
                    break;
            }
            return result;
        }

        void SummonNPC(GameObject* go, Player* player, uint32 npc, uint32 spell)
        {
            go->CastSpell(player, spell);
            TempSummon* summons = go->SummonCreature(npc, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), player->GetOrientation() - M_PI, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10 * 60 * 1000);
            summons->CastSpell(summons, SPELL_SPAWN_IN, false);
            switch (summons->GetEntry())
            {
                case NPC_TEMPLAR_FIRE:
                case NPC_TEMPLAR_WATER:
                case NPC_TEMPLAR_AIR:
                case NPC_TEMPLAR_EARTH:
                    summons->AI()->Talk(SAY_TEMPLAR_AGGRO);
                    break;

                case NPC_DUKE_FIRE:
                case NPC_DUKE_WATER:
                case NPC_DUKE_EARTH:
                case NPC_DUKE_AIR:
                    summons->AI()->Talk(SAY_DUKE_AGGRO);
                    break;
                case NPC_ROYAL_FIRE:
                case NPC_ROYAL_AIR:
                case NPC_ROYAL_EARTH:
                case NPC_ROYAL_WATER:
                    summons->AI()->Talk(YELL_ROYAL_AGGRO);
                    break;
            }
            summons->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            summons->SendMeleeAttackStart(player);
            summons->CombatStart(player);
        }

    public:
        bool OnGossipHello(Player* player, GameObject* go)
        {
            uint8 rank = GetPlayerRank(player);

            uint32 gossipId = go->GetGOInfo()->GetGossipMenuId();
            switch (gossipId)
            {
                case GOSSIPID_LESSER_WS:
                {
                    if (rank >= 1) // 1 or 2 or 3
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEMPLAR_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else
                    {
                        go->CastSpell(player, SPELL_PUNISHMENT);
                        break;
                    }

                    uint8 item = GetItems(player, TEMPLAR);
                    if (item & FIRE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEMPLAR_FIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    if (item & WATER)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEMPLAR_WATER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                    if (item & EARTH)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEMPLAR_EARTH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    if (item & AIR)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEMPLAR_AIR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                    break;
                }
                case GOSSIPID_WS:
                {
                    if (rank >= 2) // 2 or 3
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUKE_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                    else
                    {
                        go->CastSpell(player, SPELL_PUNISHMENT);
                        break;
                    }

                    uint8 item = GetItems(player, DUKE);
                    if (item & FIRE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUKE_FIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                    if (item & WATER)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUKE_WATER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                    if (item & EARTH)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUKE_EARTH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                    if (item & AIR)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUKE_AIR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                    break;
                }
                case GOSSIPID_GREATER_WS:
                {
                    if (rank == 3) // 3
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ROYAL_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                    else
                    {
                        go->CastSpell(player, SPELL_PUNISHMENT);
                        break;
                    }

                    uint8 item = GetItems(player, ROYAL);
                    if (item & FIRE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ROYAL_FIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                    if (item & WATER)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ROYAL_WATER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                    if (item & EARTH)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ROYAL_EARTH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
                    if (item & AIR)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ROYAL_AIR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
                    break;
                }
                default:
                    break;
            }

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(gossipId, go), go->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            player->PlayerTalkClass->SendCloseGossip();

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    SummonNPC(go, player, RAND(NPC_TEMPLAR_WATER, NPC_TEMPLAR_FIRE, NPC_TEMPLAR_EARTH, NPC_TEMPLAR_AIR), SPELL_TEMPLAR_RANDOM);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    SummonNPC(go, player, NPC_TEMPLAR_FIRE, SPELL_TEMPLAR_FIRE);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    SummonNPC(go, player, NPC_TEMPLAR_WATER, SPELL_TEMPLAR_WATER);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    SummonNPC(go, player, NPC_TEMPLAR_EARTH, SPELL_TEMPLAR_EARTH);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    SummonNPC(go, player, NPC_TEMPLAR_AIR, SPELL_TEMPLAR_AIR);
                    break;

                case GOSSIP_ACTION_INFO_DEF + 6:
                    SummonNPC(go, player, RAND(NPC_DUKE_FIRE, NPC_DUKE_WATER, NPC_DUKE_EARTH, NPC_DUKE_AIR), SPELL_DUKE_RANDOM);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 7:
                    SummonNPC(go, player, NPC_DUKE_FIRE, SPELL_DUKE_FIRE);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 8:
                    SummonNPC(go, player, NPC_DUKE_WATER, SPELL_DUKE_WATER);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 9:
                    SummonNPC(go, player, NPC_DUKE_EARTH, SPELL_DUKE_EARTH);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 10:
                    SummonNPC(go, player, NPC_DUKE_AIR, SPELL_DUKE_AIR);
                    break;

                case GOSSIP_ACTION_INFO_DEF + 11:
                    SummonNPC(go, player, RAND(NPC_ROYAL_FIRE, NPC_ROYAL_AIR, NPC_ROYAL_EARTH, NPC_ROYAL_WATER), SPELL_ROYAL_RANDOM);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 12:
                    SummonNPC(go, player, NPC_ROYAL_FIRE, SPELL_ROYAL_FIRE);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 13:
                    SummonNPC(go, player, NPC_ROYAL_WATER, SPELL_ROYAL_WATER);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 14:
                    SummonNPC(go, player, NPC_ROYAL_EARTH, SPELL_ROYAL_EARTH);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 15:
                    SummonNPC(go, player, NPC_ROYAL_AIR, SPELL_ROYAL_AIR);
                    break;

                default:
                    break;
            }
            return true;
        }
};

void AddSC_silithus()
{
    new npc_highlord_demitrian();
    new npcs_rutgar_and_frankal();
    new go_wind_stone();
}
