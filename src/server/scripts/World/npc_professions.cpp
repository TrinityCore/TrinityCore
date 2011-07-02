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
SDName: Npc_Professions
SD%Complete: 80
SDComment: Provides learn/unlearn/relearn-options for professions. Not supported: Unlearn engineering, re-learn engineering, re-learn leatherworking.
SDCategory: NPCs
EndScriptData */

#include "ScriptPCH.h"

/*
A few notes for future developement:
- A full implementation of gossip for GO's is required. They must have the same scripting capabilities as creatures. Basically,
there is no difference here (except that default text is chosen with `gameobject_template`.`data3` (for GO type2, different dataN for a few others)
- It's possible blacksmithing still require some tweaks and adjustments due to the way we _have_ to use reputation.
*/

/*###
# to be removed from here (->ncp_text). This is data for database projects.
###*/
#define TALK_MUST_UNLEARN_WEAPON    "You must forget your weapon type specialty before I can help you. Go to Everlook in Winterspring and seek help there."

#define TALK_HAMMER_LEARN           "Ah, a seasoned veteran you once were. I know you are capable, you merely need to ask and I shall teach you the way of the hammersmith."
#define TALK_AXE_LEARN              "Ah, a seasoned veteran you once were. I know you are capable, you merely need to ask and I shall teach you the way of the axesmith."
#define TALK_SWORD_LEARN            "Ah, a seasoned veteran you once were. I know you are capable, you merely need to ask and I shall teach you the way of the swordsmith."

#define TALK_HAMMER_UNLEARN         "Forgetting your Hammersmithing skill is not something to do lightly. If you choose to abandon it you will forget all recipes that require Hammersmithing to create!"
#define TALK_AXE_UNLEARN            "Forgetting your Axesmithing skill is not something to do lightly. If you choose to abandon it you will forget all recipes that require Axesmithing to create!"
#define TALK_SWORD_UNLEARN          "Forgetting your Swordsmithing skill is not something to do lightly. If you choose to abandon it you will forget all recipes that require Swordsmithing to create!"

/*###
# generic defines
###*/

#define GOSSIP_SENDER_LEARN         50
#define GOSSIP_SENDER_UNLEARN       51
#define GOSSIP_SENDER_CHECK         52

/*###
# gossip item and box texts
###*/

#define GOSSIP_LEARN_POTION         "Please teach me how to become a Master of Potions, Lauranna"
#define GOSSIP_UNLEARN_POTION       "I wish to unlearn Potion Mastery"
#define GOSSIP_LEARN_TRANSMUTE      "Please teach me how to become a Master of Transmutations, Zarevhi"
#define GOSSIP_UNLEARN_TRANSMUTE    "I wish to unlearn Transmutation Mastery"
#define GOSSIP_LEARN_ELIXIR         "Please teach me how to become a Master of Elixirs, Lorokeem"
#define GOSSIP_UNLEARN_ELIXIR       "I wish to unlearn Elixir Mastery"

#define BOX_UNLEARN_ALCHEMY_SPEC    "Do you really want to unlearn your alchemy specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_WEAPON_LEARN         "Please teach me how to become a Weaponsmith"
#define GOSSIP_WEAPON_UNLEARN       "I wish to unlearn the art of Weaponsmithing"
#define GOSSIP_ARMOR_LEARN          "Please teach me how to become a Armorsmith"
#define GOSSIP_ARMOR_UNLEARN        "I wish to unlearn the art of Armorsmithing"

#define GOSSIP_UNLEARN_SMITH_SPEC   "I wish to unlearn my blacksmith specialty"
#define BOX_UNLEARN_ARMORORWEAPON   "Do you really want to unlearn your blacksmith specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_LEARN_HAMMER         "Please teach me how to become a Hammersmith, Lilith"
#define GOSSIP_UNLEARN_HAMMER       "I wish to unlearn Hammersmithing"
#define GOSSIP_LEARN_AXE            "Please teach me how to become a Axesmith, Kilram"
#define GOSSIP_UNLEARN_AXE          "I wish to unlearn Axesmithing"
#define GOSSIP_LEARN_SWORD          "Please teach me how to become a Swordsmith, Seril"
#define GOSSIP_UNLEARN_SWORD        "I wish to unlearn Swordsmithing"

#define BOX_UNLEARN_WEAPON_SPEC     "Do you really want to unlearn your weaponsmith specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_LEARN_DRAGON         "I am absolutely certain that i want to learn dragonscale leatherworking"
#define GOSSIP_UNLEARN_DRAGON       "I wish to unlearn Dragonscale Leatherworking"
#define GOSSIP_LEARN_ELEMENTAL      "I am absolutely certain that i want to learn elemental leatherworking"
#define GOSSIP_UNLEARN_ELEMENTAL    "I wish to unlearn Elemental Leatherworking"
#define GOSSIP_LEARN_TRIBAL         "I am absolutely certain that i want to learn tribal leatherworking"
#define GOSSIP_UNLEARN_TRIBAL       "I wish to unlearn Tribal Leatherworking"

#define BOX_UNLEARN_LEATHER_SPEC    "Do you really want to unlearn your leatherworking specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_LEARN_SPELLFIRE      "Please teach me how to become a Spellcloth tailor"
#define GOSSIP_UNLEARN_SPELLFIRE    "I wish to unlearn Spellfire Tailoring"
#define GOSSIP_LEARN_MOONCLOTH      "Please teach me how to become a Mooncloth tailor"
#define GOSSIP_UNLEARN_MOONCLOTH    "I wish to unlearn Mooncloth Tailoring"
#define GOSSIP_LEARN_SHADOWEAVE     "Please teach me how to become a Shadoweave tailor"
#define GOSSIP_UNLEARN_SHADOWEAVE   "I wish to unlearn Shadoweave Tailoring"

#define BOX_UNLEARN_TAILOR_SPEC     "Do you really want to unlearn your tailoring specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_LEARN_GOBLIN         "I am absolutely certain that i want to learn Goblin engineering"
#define GOSSIP_LEARN_GNOMISH        "I am absolutely certain that i want to learn Gnomish engineering"

/*###
# spells defines
###*/

#define S_WEAPON                9787
#define S_ARMOR                 9788
#define S_HAMMER                17040
#define S_AXE                   17041
#define S_SWORD                 17039

#define S_LEARN_WEAPON          9789
#define S_LEARN_ARMOR           9790
#define S_LEARN_HAMMER          39099
#define S_LEARN_AXE             39098
#define S_LEARN_SWORD           39097

#define S_UNLEARN_WEAPON        36436
#define S_UNLEARN_ARMOR         36435
#define S_UNLEARN_HAMMER        36441
#define S_UNLEARN_AXE           36439
#define S_UNLEARN_SWORD         36438

#define S_REP_ARMOR             17451
#define S_REP_WEAPON            17452

#define REP_ARMOR               46
#define REP_WEAPON              289
#define REP_HAMMER              569
#define REP_AXE                 570
#define REP_SWORD               571

#define S_DRAGON                10656
#define S_ELEMENTAL             10658
#define S_TRIBAL                10660

#define S_LEARN_DRAGON          10657
#define S_LEARN_ELEMENTAL       10659
#define S_LEARN_TRIBAL          10661

#define S_UNLEARN_DRAGON        36434
#define S_UNLEARN_ELEMENTAL     36328
#define S_UNLEARN_TRIBAL        36433

#define S_GOBLIN                20222
#define S_GNOMISH               20219

#define S_LEARN_GOBLIN          20221
#define S_LEARN_GNOMISH         20220

#define S_SPELLFIRE             26797
#define S_MOONCLOTH             26798
#define S_SHADOWEAVE            26801

#define S_LEARN_SPELLFIRE       26796
#define S_LEARN_MOONCLOTH       26799
#define S_LEARN_SHADOWEAVE      26800

#define S_UNLEARN_SPELLFIRE     41299
#define S_UNLEARN_MOONCLOTH     41558
#define S_UNLEARN_SHADOWEAVE    41559

#define S_TRANSMUTE             28672
#define S_ELIXIR                28677
#define S_POTION                28675

#define S_LEARN_TRANSMUTE       28674
#define S_LEARN_ELIXIR          28678
#define S_LEARN_POTION          28676

#define S_UNLEARN_TRANSMUTE     41565
#define S_UNLEARN_ELIXIR        41564
#define S_UNLEARN_POTION        41563

/*###
# formulas to calculate unlearning cost
###*/

int32 DoLearnCost(Player* /*player*/)                      //tailor, alchemy
{
    return 200000;
}

int32 DoHighUnlearnCost(Player* /*player*/)                //tailor, alchemy
{
    return 1500000;
}

int32 DoMedUnlearnCost(Player* player)                     //blacksmith, leatherwork
{
    uint8 level = player->getLevel();
    if (level < 51)
        return 250000;
    else if (level < 66)
        return 500000;
    else
        return 1000000;
}

int32 DoLowUnlearnCost(Player* player)                     //blacksmith
{
    uint8 level = player->getLevel();
    if (level < 66)
        return 50000;
    else
        return 100000;
}

/*###
# unlearning related profession spells
###*/

bool EquippedOk(Player* player, uint32 spellId)
{
    SpellEntry const* spell = GetSpellStore()->LookupEntry(spellId);

    if (!spell)
        return false;

    for (uint8 i = 0; i < 3; ++i)
    {
        uint32 reqSpell = spell->EffectTriggerSpell[i];
        if (!reqSpell)
            continue;

        Item* pItem;
        for (uint8 j = EQUIPMENT_SLOT_START; j < EQUIPMENT_SLOT_END; ++j)
        {
            pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, j);
            if (pItem)
                if (pItem->GetTemplate()->RequiredSpell == reqSpell)
            {
                //player has item equipped that require specialty. Not allow to unlearn, player has to unequip first
                sLog->outDebug(LOG_FILTER_TSCR, "TSCR: player attempt to unlearn spell %u, but item %u is equipped.", reqSpell, pItem->GetTemplate()->ItemId);
                return false;
            }
        }
    }
    return true;
}

void ProfessionUnlearnSpells(Player* player, uint32 type)
{
    switch (type)
    {
        case 36436:                                         // S_UNLEARN_WEAPON
            player->removeSpell(36125);                     // Light Earthforged Blade
            player->removeSpell(36128);                     // Light Emberforged Hammer
            player->removeSpell(36126);                     // Light Skyforged Axe
            break;
        case 36435:                                         // S_UNLEARN_ARMOR
            player->removeSpell(36122);                     // Earthforged Leggings
            player->removeSpell(36129);                     // Heavy Earthforged Breastplate
            player->removeSpell(36130);                     // Stormforged Hauberk
            player->removeSpell(34533);                     // Breastplate of Kings
            player->removeSpell(34529);                     // Nether Chain Shirt
            player->removeSpell(34534);                     // Bulwark of Kings
            player->removeSpell(36257);                     // Bulwark of the Ancient Kings
            player->removeSpell(36256);                     // Embrace of the Twisting Nether
            player->removeSpell(34530);                     // Twisting Nether Chain Shirt
            player->removeSpell(36124);                     // Windforged Leggings
            break;
        case 36441:                                         // S_UNLEARN_HAMMER
            player->removeSpell(36262);                     // Dragonstrike
            player->removeSpell(34546);                     // Dragonmaw
            player->removeSpell(34545);                     // Drakefist Hammer
            player->removeSpell(36136);                     // Lavaforged Warhammer
            player->removeSpell(34547);                     // Thunder
            player->removeSpell(34567);                     // Deep Thunder
            player->removeSpell(36263);                     // Stormherald
            player->removeSpell(36137);                     // Great Earthforged Hammer
            break;
        case 36439:                                         // S_UNLEARN_AXE
            player->removeSpell(36260);                     // Wicked Edge of the Planes
            player->removeSpell(34562);                     // Black Planar Edge
            player->removeSpell(34541);                     // The Planar Edge
            player->removeSpell(36134);                     // Stormforged Axe
            player->removeSpell(36135);                     // Skyforged Great Axe
            player->removeSpell(36261);                     // Bloodmoon
            player->removeSpell(34543);                     // Lunar Crescent
            player->removeSpell(34544);                     // Mooncleaver
            break;
        case 36438:                                         // S_UNLEARN_SWORD
            player->removeSpell(36258);                     // Blazefury
            player->removeSpell(34537);                     // Blazeguard
            player->removeSpell(34535);                     // Fireguard
            player->removeSpell(36131);                     // Windforged Rapier
            player->removeSpell(36133);                     // Stoneforged Claymore
            player->removeSpell(34538);                     // Lionheart Blade
            player->removeSpell(34540);                     // Lionheart Champion
            player->removeSpell(36259);                     // Lionheart Executioner
            break;
        case 36434:                                         // S_UNLEARN_DRAGON
            player->removeSpell(36076);                     // Dragonstrike Leggings
            player->removeSpell(36079);                     // Golden Dragonstrike Breastplate
            player->removeSpell(35576);                     // Ebon Netherscale Belt
            player->removeSpell(35577);                     // Ebon Netherscale Bracers
            player->removeSpell(35575);                     // Ebon Netherscale Breastplate
            player->removeSpell(35582);                     // Netherstrike Belt
            player->removeSpell(35584);                     // Netherstrike Bracers
            player->removeSpell(35580);                     // Netherstrike Breastplate
            break;
        case 36328:                                         // S_UNLEARN_ELEMENTAL
            player->removeSpell(36074);                     // Blackstorm Leggings
            player->removeSpell(36077);                     // Primalstorm Breastplate
            player->removeSpell(35590);                     // Primalstrike Belt
            player->removeSpell(35591);                     // Primalstrike Bracers
            player->removeSpell(35589);                     // Primalstrike Vest
            break;
        case 36433:                                         // S_UNLEARN_TRIBAL
            player->removeSpell(35585);                     // Windhawk Hauberk
            player->removeSpell(35587);                     // Windhawk Belt
            player->removeSpell(35588);                     // Windhawk Bracers
            player->removeSpell(36075);                     // Wildfeather Leggings
            player->removeSpell(36078);                     // Living Crystal Breastplate
            break;
        case 41299:                                         // S_UNLEARN_SPELLFIRE
            player->removeSpell(26752);                     // Spellfire Belt
            player->removeSpell(26753);                     // Spellfire Gloves
            player->removeSpell(26754);                     // Spellfire Robe
            break;
        case 41558:                                         // S_UNLEARN_MOONCLOTH
            player->removeSpell(26760);                     // Primal Mooncloth Belt
            player->removeSpell(26761);                     // Primal Mooncloth Shoulders
            player->removeSpell(26762);                     // Primal Mooncloth Robe
            break;
        case 41559:                                         // S_UNLEARN_SHADOWEAVE
            player->removeSpell(26756);                     // Frozen Shadoweave Shoulders
            player->removeSpell(26757);                     // Frozen Shadoweave Boots
            player->removeSpell(26758);                     // Frozen Shadoweave Robe
            break;
    }
}

/*###
# start menues alchemy
###*/

bool HasAlchemySpell(Player* player)
{
    if (player->HasSpell(S_TRANSMUTE) || player->HasSpell(S_ELIXIR) || player->HasSpell(S_POTION))
        return true;
    return false;
}

class npc_prof_alchemy : public CreatureScript
{
public:
    npc_prof_alchemy() : CreatureScript("npc_prof_alchemy") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        if (creature->isVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        if (creature->isTrainer())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        uint32 eCreature = creature->GetEntry();

        if (player->HasSkill(SKILL_ALCHEMY) && player->GetBaseSkillValue(SKILL_ALCHEMY) >= 350 && player->getLevel() > 67)
        {
            if (player->GetQuestRewardStatus(10899) || player->GetQuestRewardStatus(10902) || player->GetQuestRewardStatus(10897))
            {
                switch (eCreature)
                {
                    case 22427:                                 //Zarevhi
                        if (!HasAlchemySpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_TRANSMUTE,    GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 1);
                        if (player->HasSpell(S_TRANSMUTE))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_TRANSMUTE,  GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 4);
                        break;
                    case 19052:                                 //Lorokeem
                        if (!HasAlchemySpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_ELIXIR,       GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 2);
                        if (player->HasSpell(S_ELIXIR))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_ELIXIR,     GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 5);
                        break;
                    case 17909:                                 //Lauranna Thar'well
                        if (!HasAlchemySpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_POTION,       GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 3);
                        if (player->HasSpell(S_POTION))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_POTION,     GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 6);
                        break;
                }
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    void SendActionMenu(Player* player, Creature* creature, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
            case GOSSIP_ACTION_TRAIN:
                player->GetSession()->SendTrainerList(creature->GetGUID());
                break;
                //Learn Alchemy
            case GOSSIP_ACTION_INFO_DEF + 1:
                if (!player->HasSpell(S_TRANSMUTE) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_TRANSMUTE, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (!player->HasSpell(S_ELIXIR) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_ELIXIR, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                if (!player->HasSpell(S_POTION) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_POTION, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
                //Unlearn Alchemy
            case GOSSIP_ACTION_INFO_DEF + 4:
                if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                {
                    creature->CastSpell(player, S_UNLEARN_TRANSMUTE, true);
                    player->ModifyMoney(-DoHighUnlearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 5:
                if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                {
                    creature->CastSpell(player, S_UNLEARN_ELIXIR, true);
                    player->ModifyMoney(-DoHighUnlearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 6:
                if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                {
                    creature->CastSpell(player, S_UNLEARN_POTION, true);
                    player->ModifyMoney(-DoHighUnlearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
    }

    void SendConfirmLearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 22427:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_TRANSMUTE, GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 19052:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_ELIXIR,    GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 17909:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_POTION,    GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    void SendConfirmUnlearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 22427:                                     //Zarevhi
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_TRANSMUTE, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_ALCHEMY_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 19052:                                     //Lorokeem
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_ELIXIR, GOSSIP_SENDER_CHECK, uiAction,    BOX_UNLEARN_ALCHEMY_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 17909:                                     //Lauranna Thar'well
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_POTION, GOSSIP_SENDER_CHECK, uiAction,    BOX_UNLEARN_ALCHEMY_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:    SendActionMenu(player, creature, uiAction); break;
            case GOSSIP_SENDER_LEARN:   SendConfirmLearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_UNLEARN: SendConfirmUnlearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_CHECK:   SendActionMenu(player, creature, uiAction); break;
        }
        return true;
    }
};

/*###
# start menues blacksmith
###*/

bool HasWeaponSub(Player* player)
{
    if (player->HasSpell(S_HAMMER) || player->HasSpell(S_AXE) || player->HasSpell(S_SWORD))
        return true;
    return false;
}

class npc_prof_blacksmith : public CreatureScript
{
public:
    npc_prof_blacksmith() : CreatureScript("npc_prof_blacksmith") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        if (creature->isVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        if (creature->isTrainer())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        uint32 eCreature = creature->GetEntry();
        //WEAPONSMITH & ARMORSMITH
        if (player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 225)
        {
            switch (eCreature)
            {
                case 11145:                                     //Myolor Sunderfury
                case 11176:                                     //Krathok Moltenfist
                    if (!player->HasSpell(S_ARMOR) && !player->HasSpell(S_WEAPON) && player->GetReputationRank(REP_ARMOR) >= REP_FRIENDLY)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARMOR_LEARN,   GOSSIP_SENDER_MAIN,          GOSSIP_ACTION_INFO_DEF + 1);
                    if (!player->HasSpell(S_WEAPON) && !player->HasSpell(S_ARMOR) && player->GetReputationRank(REP_WEAPON) >= REP_FRIENDLY)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WEAPON_LEARN,  GOSSIP_SENDER_MAIN,          GOSSIP_ACTION_INFO_DEF + 2);
                    break;
                case 11146:                                     //Ironus Coldsteel
                case 11178:                                     //Borgosh Corebender
                    if (player->HasSpell(S_WEAPON))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WEAPON_UNLEARN,    GOSSIP_SENDER_UNLEARN,   GOSSIP_ACTION_INFO_DEF + 3);
                    break;
                case 5164:                                      //Grumnus Steelshaper
                case 11177:                                     //Okothos Ironrager
                    if (player->HasSpell(S_ARMOR))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARMOR_UNLEARN,     GOSSIP_SENDER_UNLEARN,   GOSSIP_ACTION_INFO_DEF + 4);
                    break;
            }
        }
        //WEAPONSMITH SPEC
        if (player->HasSpell(S_WEAPON) && player->getLevel() > 49 && player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 250)
        {
            switch (eCreature)
            {
                case 11191:                                     //Lilith the Lithe
                    if (!HasWeaponSub(player))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_HAMMER,       GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 5);
                    if (player->HasSpell(S_HAMMER))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_HAMMER,     GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 8);
                    break;
                case 11192:                                     //Kilram
                    if (!HasWeaponSub(player))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_AXE,          GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 6);
                    if (player->HasSpell(S_AXE))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_AXE,        GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 9);
                    break;
                case 11193:                                     //Seril Scourgebane
                    if (!HasWeaponSub(player))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SWORD,        GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 7);
                    if (player->HasSpell(S_SWORD))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SWORD,      GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 10);
                    break;
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    void SendActionMenu(Player* player, Creature* creature, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
            case GOSSIP_ACTION_TRAIN:
                player->GetSession()->SendTrainerList(creature->GetGUID());
                break;
                //Learn Armor/Weapon
            case GOSSIP_ACTION_INFO_DEF + 1:
                if (!player->HasSpell(S_ARMOR))
                {
                    player->CastSpell(player, S_LEARN_ARMOR, true);
                    //_Creature->CastSpell(player, S_REP_ARMOR, true);
                }
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (!player->HasSpell(S_WEAPON))
                {
                    player->CastSpell(player, S_LEARN_WEAPON, true);
                    //_Creature->CastSpell(player, S_REP_WEAPON, true);
                }
                player->CLOSE_GOSSIP_MENU();
                break;
                //Unlearn Armor/Weapon
            case GOSSIP_ACTION_INFO_DEF + 3:
                if (HasWeaponSub(player))
                {
                                                                //unknown textID (TALK_MUST_UNLEARN_WEAPON)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                }
                else if (EquippedOk(player, S_UNLEARN_WEAPON))
                {
                    if (player->HasEnoughMoney(DoLowUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_WEAPON, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_WEAPON);
                        player->ModifyMoney(-DoLowUnlearnCost(player));
                        creature->CastSpell(player, S_REP_ARMOR, true);
                        player->CLOSE_GOSSIP_MENU();
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                }
                else
                {
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 4:
                if (EquippedOk(player, S_UNLEARN_ARMOR))
                {
                    if (player->HasEnoughMoney(DoLowUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_ARMOR, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_ARMOR);
                        player->ModifyMoney(-DoLowUnlearnCost(player));
                        creature->CastSpell(player, S_REP_WEAPON, true);
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
                //Learn Hammer/Axe/Sword
            case GOSSIP_ACTION_INFO_DEF + 5:
                player->CastSpell(player, S_LEARN_HAMMER, true);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 6:
                player->CastSpell(player, S_LEARN_AXE, true);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 7:
                player->CastSpell(player, S_LEARN_SWORD, true);
                player->CLOSE_GOSSIP_MENU();
                break;
                //Unlearn Hammer/Axe/Sword
            case GOSSIP_ACTION_INFO_DEF + 8:
                if (EquippedOk(player, S_UNLEARN_HAMMER))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_HAMMER, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_HAMMER);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 9:
                if (EquippedOk(player, S_UNLEARN_AXE))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_AXE, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_AXE);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 10:
                if (EquippedOk(player, S_UNLEARN_SWORD))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_SWORD, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_SWORD);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
    }

    void SendConfirmLearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 11191:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_HAMMER, GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID (TALK_HAMMER_LEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 11192:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_AXE,    GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID (TALK_AXE_LEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 11193:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SWORD,  GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID (TALK_SWORD_LEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    void SendConfirmUnlearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 11146:                                     //Ironus Coldsteel
                case 11178:                                     //Borgosh Corebender
                case 5164:                                      //Grumnus Steelshaper
                case 11177:                                     //Okothos Ironrager
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_SMITH_SPEC, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_ARMORORWEAPON, DoLowUnlearnCost(player), false);
                                                                //unknown textID (TALK_UNLEARN_AXEORWEAPON)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;

                case 11191:
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_HAMMER, GOSSIP_SENDER_CHECK, uiAction,    BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID (TALK_HAMMER_UNLEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 11192:
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_AXE, GOSSIP_SENDER_CHECK, uiAction,       BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID (TALK_AXE_UNLEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 11193:
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_SWORD, GOSSIP_SENDER_CHECK, uiAction,     BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID (TALK_SWORD_UNLEARN)
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:    SendActionMenu(player, creature, uiAction); break;
            case GOSSIP_SENDER_LEARN:   SendConfirmLearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_UNLEARN: SendConfirmUnlearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_CHECK:   SendActionMenu(player, creature, uiAction); break;
        }
        return true;
    }
};

/*###
# engineering trinkets
###*/

enum eEngineeringTrinkets
{
    NPC_ZAP                     = 14742,
    NPC_JHORDY                  = 14743,
    NPC_KABLAM                  = 21493,
    NPC_SMILES                  = 21494,

    SPELL_LEARN_TO_EVERLOOK     = 23490,
    SPELL_LEARN_TO_GADGET       = 23491,
    SPELL_LEARN_TO_AREA52       = 36956,
    SPELL_LEARN_TO_TOSHLEY      = 36957,

    SPELL_TO_EVERLOOK           = 23486,
    SPELL_TO_GADGET             = 23489,
    SPELL_TO_AREA52             = 36954,
    SPELL_TO_TOSHLEY            = 36955,
};

#define GOSSIP_ITEM_ZAP         "[PH] Unknown"
#define GOSSIP_ITEM_JHORDY      "I must build a beacon for this marvelous device!"
#define GOSSIP_ITEM_KABLAM      "[PH] Unknown"
#define GOSSIP_ITEM_SMILES      "[PH] Unknown"

class npc_engineering_tele_trinket : public CreatureScript
{
public:
    npc_engineering_tele_trinket() : CreatureScript("npc_engineering_tele_trinket") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        uint32 NpcTextId = 0;
        std::string GossipItem;
        bool CanLearn = false;

        if (player->HasSkill(SKILL_ENGINERING))
        {
            switch(creature->GetEntry())
            {
                case NPC_ZAP:
                    NpcTextId = 7249;
                    if (player->GetBaseSkillValue(SKILL_ENGINERING) >= 260 && player->HasSpell(S_GOBLIN))
                    {
                        if (!player->HasSpell(SPELL_TO_EVERLOOK))
                        {
                            CanLearn = true;
                            GossipItem = GOSSIP_ITEM_ZAP;
                        }
                        else if (player->HasSpell(SPELL_TO_EVERLOOK))
                            NpcTextId = 0;
                    }
                    break;
                case NPC_JHORDY:
                    NpcTextId = 7251;
                    if (player->GetBaseSkillValue(SKILL_ENGINERING) >= 260 && player->HasSpell(S_GNOMISH))
                    {
                        if (!player->HasSpell(SPELL_TO_GADGET))
                        {
                            CanLearn = true;
                            GossipItem = GOSSIP_ITEM_JHORDY;
                        }
                        else if (player->HasSpell(SPELL_TO_GADGET))
                            NpcTextId = 7252;
                    }
                    break;
                case NPC_KABLAM:
                    NpcTextId = 10365;
                    if (player->GetBaseSkillValue(SKILL_ENGINERING) >= 350 && player->HasSpell(S_GOBLIN))
                    {
                        if (!player->HasSpell(SPELL_TO_AREA52))
                        {
                            CanLearn = true;
                            GossipItem = GOSSIP_ITEM_KABLAM;
                        }
                        else if (player->HasSpell(SPELL_TO_AREA52))
                            NpcTextId = 0;
                    }
                    break;
                case NPC_SMILES:
                    NpcTextId = 10363;
                    if (player->GetBaseSkillValue(SKILL_ENGINERING) >= 350 && player->HasSpell(S_GNOMISH))
                    {
                        if (!player->HasSpell(SPELL_TO_TOSHLEY))
                        {
                            CanLearn = true;
                            GossipItem = GOSSIP_ITEM_SMILES;
                        }
                        else if (player->HasSpell(SPELL_TO_TOSHLEY))
                            NpcTextId = 0;
                    }
                    break;
            }
        }

        if (CanLearn)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GossipItem, creature->GetEntry(), GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(NpcTextId ? NpcTextId : player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
            player->CLOSE_GOSSIP_MENU();

        if (uiSender != creature->GetEntry())
            return true;

        switch(uiSender)
        {
            case NPC_ZAP:
                player->CastSpell(player, SPELL_LEARN_TO_EVERLOOK, false);
                break;
            case NPC_JHORDY:
                player->CastSpell(player, SPELL_LEARN_TO_GADGET, false);
                break;
            case NPC_KABLAM:
                player->CastSpell(player, SPELL_LEARN_TO_AREA52, false);
                break;
            case NPC_SMILES:
                player->CastSpell(player, SPELL_LEARN_TO_TOSHLEY, false);
                break;
        }

        return true;
    }
};

/*###
# start menues leatherworking
###*/

class npc_prof_leather : public CreatureScript
{
public:
    npc_prof_leather() : CreatureScript("npc_prof_leather") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        if (creature->isVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        if (creature->isTrainer())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        uint32 eCreature = creature->GetEntry();

        if (player->HasSkill(SKILL_LEATHERWORKING) && player->GetBaseSkillValue(SKILL_LEATHERWORKING) >= 250 && player->getLevel() > 49)
        {
            switch (eCreature)
            {
                case 7866:                                      //Peter Galen
                case 7867:                                      //Thorkaf Dragoneye
                    if (player->HasSpell(S_DRAGON))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_DRAGON,      GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 1);
                    break;
                case 7868:                                      //Sarah Tanner
                case 7869:                                      //Brumn Winterhoof
                    if (player->HasSpell(S_ELEMENTAL))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_ELEMENTAL,   GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 2);
                    break;
                case 7870:                                      //Caryssia Moonhunter
                case 7871:                                      //Se'Jib
                    if (player->HasSpell(S_TRIBAL))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_TRIBAL,      GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 3);
                    break;
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    void SendActionMenu(Player* player, Creature* creature, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
            case GOSSIP_ACTION_TRAIN:
                player->GetSession()->SendTrainerList(creature->GetGUID());
                break;
                //Unlearn Leather
            case GOSSIP_ACTION_INFO_DEF + 1:
                if (EquippedOk(player, S_UNLEARN_DRAGON))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_DRAGON, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_DRAGON);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (EquippedOk(player, S_UNLEARN_ELEMENTAL))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_ELEMENTAL, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_ELEMENTAL);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                if (EquippedOk(player, S_UNLEARN_TRIBAL))
                {
                    if (player->HasEnoughMoney(DoMedUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_TRIBAL, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_TRIBAL);
                        player->ModifyMoney(-DoMedUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
    }

    void SendConfirmUnlearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 7866:                                      //Peter Galen
                case 7867:                                      //Thorkaf Dragoneye
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_DRAGON, GOSSIP_SENDER_CHECK, uiAction,    BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 7868:                                      //Sarah Tanner
                case 7869:                                      //Brumn Winterhoof
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_ELEMENTAL, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 7870:                                      //Caryssia Moonhunter
                case 7871:                                      //Se'Jib
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_TRIBAL, GOSSIP_SENDER_CHECK, uiAction,    BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:    SendActionMenu(player, creature, uiAction); break;
            case GOSSIP_SENDER_UNLEARN: SendConfirmUnlearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_CHECK:   SendActionMenu(player, creature, uiAction); break;
        }
        return true;
    }
};

/*###
# start menues tailoring
###*/

bool HasTailorSpell(Player* player)
{
    if (player->HasSpell(S_MOONCLOTH) || player->HasSpell(S_SHADOWEAVE) || player->HasSpell(S_SPELLFIRE))
        return true;
    return false;
}

class npc_prof_tailor : public CreatureScript
{
public:
    npc_prof_tailor() : CreatureScript("npc_prof_tailor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        if (creature->isVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        if (creature->isTrainer())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        uint32 eCreature = creature->GetEntry();
                                                                //TAILORING SPEC
        if (player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 350 && player->getLevel() > 59)
        {
            if (player->GetQuestRewardStatus(10831) || player->GetQuestRewardStatus(10832) || player->GetQuestRewardStatus(10833))
            {
                switch (eCreature)
                {
                    case 22213:                                 //Gidge Spellweaver
                        if (!HasTailorSpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SPELLFIRE,    GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 1);
                        if (player->HasSpell(S_SPELLFIRE))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SPELLFIRE,  GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 4);
                        break;
                    case 22208:                                 //Nasmara Moonsong
                        if (!HasTailorSpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_MOONCLOTH,    GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 2);
                        if (player->HasSpell(S_MOONCLOTH))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_MOONCLOTH,  GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 5);
                        break;
                    case 22212:                                 //Andrion Darkspinner
                        if (!HasTailorSpell(player))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SHADOWEAVE,   GOSSIP_SENDER_LEARN,    GOSSIP_ACTION_INFO_DEF + 3);
                        if (player->HasSpell(S_SHADOWEAVE))
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SHADOWEAVE, GOSSIP_SENDER_UNLEARN,  GOSSIP_ACTION_INFO_DEF + 6);
                        break;
                }
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    void SendActionMenu(Player* player, Creature* creature, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
            case GOSSIP_ACTION_TRAIN:
                player->GetSession()->SendTrainerList(creature->GetGUID());
                break;
                //Learn Tailor
            case GOSSIP_ACTION_INFO_DEF + 1:
                if (!player->HasSpell(S_SPELLFIRE) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_SPELLFIRE, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (!player->HasSpell(S_MOONCLOTH) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_MOONCLOTH, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                if (!player->HasSpell(S_SHADOWEAVE) && player->HasEnoughMoney(DoLearnCost(player)))
                {
                    player->CastSpell(player, S_LEARN_SHADOWEAVE, true);
                    player->ModifyMoney(-DoLearnCost(player));
                } else
                    player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                player->CLOSE_GOSSIP_MENU();
                break;
                //Unlearn Tailor
            case GOSSIP_ACTION_INFO_DEF + 4:
                if (EquippedOk(player, S_UNLEARN_SPELLFIRE))
                {
                    if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_SPELLFIRE, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_SPELLFIRE);
                        player->ModifyMoney(-DoHighUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 5:
                if (EquippedOk(player, S_UNLEARN_MOONCLOTH))
                {
                    if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_MOONCLOTH, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_MOONCLOTH);
                        player->ModifyMoney(-DoHighUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF + 6:
                if (EquippedOk(player, S_UNLEARN_SHADOWEAVE))
                {
                    if (player->HasEnoughMoney(DoHighUnlearnCost(player)))
                    {
                        player->CastSpell(player, S_UNLEARN_SHADOWEAVE, true);
                        ProfessionUnlearnSpells(player, S_UNLEARN_SHADOWEAVE);
                        player->ModifyMoney(-DoHighUnlearnCost(player));
                    } else
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                } else
                    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, NULL, NULL);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
    }

    void SendConfirmLearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 22213:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SPELLFIRE, GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 22208:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_MOONCLOTH,    GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 22212:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEARN_SHADOWEAVE,  GOSSIP_SENDER_CHECK, uiAction);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    void SendConfirmUnlearn(Player* player, Creature* creature, uint32 uiAction)
    {
        if (uiAction)
        {
            uint32 eCreature = creature->GetEntry();
            switch(eCreature)
            {
                case 22213:                                     //Gidge Spellweaver
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_SPELLFIRE, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 22208:                                     //Nasmara Moonsong
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_MOONCLOTH, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
                case 22212:                                     //Andrion Darkspinner
                    player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_UNLEARN_SHADOWEAVE, GOSSIP_SENDER_CHECK, uiAction, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                                                                //unknown textID ()
                    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    break;
            }
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:    SendActionMenu(player, creature, uiAction); break;
            case GOSSIP_SENDER_LEARN:   SendConfirmLearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_UNLEARN: SendConfirmUnlearn(player, creature, uiAction); break;
            case GOSSIP_SENDER_CHECK:   SendActionMenu(player, creature, uiAction); break;
        }
        return true;
    }
};

/*###
#
###*/

void AddSC_npc_professions()
{
    new npc_prof_alchemy;
    new npc_prof_blacksmith;
    new npc_engineering_tele_trinket;
    new npc_prof_leather;
    new npc_prof_tailor;
}
