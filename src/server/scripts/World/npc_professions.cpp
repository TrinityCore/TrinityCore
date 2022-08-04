/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SD%Complete: 100
SDComment: Provides learn/unlearn/relearn-options for professions.
SDCategory: NPCs/GOBs
EndScriptData */

#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "Item.h"
#include "Log.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "WorldSession.h"

/*
A few notes for future developement:
- It's possible blacksmithing still require some tweaks and adjustments due to the way we _have_ to use reputation.
*/

/*###
# to be removed from here (->npc_text). This is data for database projects.
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

#define GOSSIP_UNLEARN_DRAGON       "I wish to unlearn Dragonscale Leatherworking"
#define GOSSIP_UNLEARN_ELEMENTAL    "I wish to unlearn Elemental Leatherworking"
#define GOSSIP_UNLEARN_TRIBAL       "I wish to unlearn Tribal Leatherworking"

#define BOX_UNLEARN_LEATHER_SPEC    "Do you really want to unlearn your leatherworking specialty and lose all associated recipes? \n Cost: "

#define GOSSIP_LEARN_SPELLFIRE      "Please teach me how to become a Spellcloth tailor"
#define GOSSIP_UNLEARN_SPELLFIRE    "I wish to unlearn Spellfire Tailoring"
#define GOSSIP_LEARN_MOONCLOTH      "Please teach me how to become a Mooncloth tailor"
#define GOSSIP_UNLEARN_MOONCLOTH    "I wish to unlearn Mooncloth Tailoring"
#define GOSSIP_LEARN_SHADOWEAVE     "Please teach me how to become a Shadoweave tailor"
#define GOSSIP_UNLEARN_SHADOWEAVE   "I wish to unlearn Shadoweave Tailoring"

#define BOX_UNLEARN_TAILOR_SPEC     "Do you really want to unlearn your tailoring specialty and lose all associated recipes? \n Cost: "

/*###
# spells defines
###*/
enum ProfessionSpells
{
    S_WEAPON                = 9787,
    S_ARMOR                 = 9788,
    S_HAMMER                = 17040,
    S_AXE                   = 17041,
    S_SWORD                 = 17039,

    S_LEARN_WEAPON          = 9789,
    S_LEARN_ARMOR           = 9790,
    S_LEARN_HAMMER          = 39099,
    S_LEARN_AXE             = 39098,
    S_LEARN_SWORD           = 39097,

    S_UNLEARN_WEAPON        = 36436,
    S_UNLEARN_ARMOR         = 36435,
    S_UNLEARN_HAMMER        = 36441,
    S_UNLEARN_AXE           = 36439,
    S_UNLEARN_SWORD         = 36438,

    S_REP_ARMOR             = 17451,
    S_REP_WEAPON            = 17452,

    REP_ARMOR               = 46,
    REP_WEAPON              = 289,
    REP_HAMMER              = 569,
    REP_AXE                 = 570,
    REP_SWORD               = 571,

    S_DRAGON                = 10656,
    S_ELEMENTAL             = 10658,
    S_TRIBAL                = 10660,

    S_LEARN_DRAGON          = 10657,
    S_LEARN_ELEMENTAL       = 10659,
    S_LEARN_TRIBAL          = 10661,

    S_UNLEARN_DRAGON        = 36434,
    S_UNLEARN_ELEMENTAL     = 36328,
    S_UNLEARN_TRIBAL        = 36433,

    S_GOBLIN                = 20222,
    S_GNOMISH               = 20219,

    S_LEARN_GOBLIN          = 20221,
    S_LEARN_GNOMISH         = 20220,

    S_UNLEARN_GOBLIN        = 68334,
    S_UNLEARN_GNOMISH       = 68333,

    S_SPELLFIRE             = 26797,
    S_MOONCLOTH             = 26798,
    S_SHADOWEAVE            = 26801,

    S_LEARN_SPELLFIRE       = 26796,
    S_LEARN_MOONCLOTH       = 26799,
    S_LEARN_SHADOWEAVE      = 26800,

    S_UNLEARN_SPELLFIRE     = 41299,
    S_UNLEARN_MOONCLOTH     = 41558,
    S_UNLEARN_SHADOWEAVE    = 41559
};

/*###
# specialization trainers
###*/
enum SpecializationTrainers
{
    /* Blacksmithing */
    N_TRAINER_SMITHOMNI1    = 11145, // Myolor Sunderfury
    N_TRAINER_SMITHOMNI2    = 11176, // Krathok Moltenfist
    N_TRAINER_WEAPON1       = 11146, // Ironus Coldsteel
    N_TRAINER_WEAPON2       = 11178, // Borgosh Corebender
    N_TRAINER_ARMOR1        =  5164, // Grumnus Steelshaper
    N_TRAINER_ARMOR2        = 11177, // Okothos Ironrager
    N_TRAINER_HAMMER        = 11191, // Lilith the Lithe
    N_TRAINER_AXE           = 11192, // Kilram
    N_TRAINER_SWORD         = 11193, // Seril Scourgebane

    /* Leatherworking */
    N_TRAINER_DRAGON1       =  7866, // Peter Galen
    N_TRAINER_DRAGON2       =  7867, // Thorkaf Dragoneye
    N_TRAINER_ELEMENTAL1    =  7868, // Sarah Tanner
    N_TRAINER_ELEMENTAL2    =  7869, // Brumn Winterhoof
    N_TRAINER_TRIBAL1       =  7870, // Caryssia Moonhunter
    N_TRAINER_TRIBAL2       =  7871, // Se'Jib

    /* Tailoring */
    N_TRAINER_SPELLFIRE     = 22213, // Gidge Spellweaver
    N_TRAINER_MOONCLOTH     = 22208, // Nasmara Moonsong
    N_TRAINER_SHADOWEAVE    = 22212, // Andrion Darkspinner
};

/*###
# formulas to calculate unlearning cost
###*/

int32 DoLearnCost(Player* /*player*/)                      //tailor
{
    return 200000;
}

int32 DoHighUnlearnCost(Player* /*player*/)                //tailor
{
    return 1500000;
}

int32 DoMedUnlearnCost(Player* player)                     //blacksmith, leatherwork
{
    uint8 level = player->GetLevel();
    if (level < 51)
        return 250000;
    else if (level < 66)
        return 500000;
    else
        return 1000000;
}

int32 DoLowUnlearnCost(Player* player)                     //blacksmith
{
    uint8 level = player->GetLevel();
    if (level < 66)
        return 50000;
    else
        return 100000;
}

void ProcessCastaction(Player* player, Creature* creature, uint32 spellId, uint32 triggeredSpellId, int32 cost)
{
    if (!(spellId && player->HasSpell(spellId)) && player->HasEnoughMoney(cost))
    {
        player->CastSpell(player, triggeredSpellId, true);
        player->ModifyMoney(-cost);
    }
    else
        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
    CloseGossipMenuFor(player);
}

/*###
# unlearning related profession spells
###*/

bool EquippedOk(Player* player, uint32 spellId)
{
    SpellInfo const* spell = sSpellMgr->GetSpellInfo(spellId);
    if (!spell)
        return false;

    for (SpellEffectInfo const& spellEffectInfo : spell->GetEffects())
    {
        uint32 reqSpell = spellEffectInfo.TriggerSpell;
        if (!reqSpell)
            continue;

        Item* item = nullptr;
        for (uint8 j = EQUIPMENT_SLOT_START; j < EQUIPMENT_SLOT_END; ++j)
        {
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, j);
            if (item && item->GetTemplate()->RequiredSpell == reqSpell)
            {
                //player has item equipped that require specialty. Not allow to unlearn, player has to unequip first
                TC_LOG_DEBUG("scripts", "player attempt to unlearn spell %u, but item %u is equipped.", reqSpell, item->GetEntry());
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
        case S_UNLEARN_WEAPON:                              // S_UNLEARN_WEAPON
            player->RemoveSpell(36125);                     // Light Earthforged Blade
            player->RemoveSpell(36128);                     // Light Emberforged Hammer
            player->RemoveSpell(36126);                     // Light Skyforged Axe
            break;
        case S_UNLEARN_ARMOR:                               // S_UNLEARN_ARMOR
            player->RemoveSpell(36122);                     // Earthforged Leggings
            player->RemoveSpell(36129);                     // Heavy Earthforged Breastplate
            player->RemoveSpell(36130);                     // Stormforged Hauberk
            player->RemoveSpell(34533);                     // Breastplate of Kings
            player->RemoveSpell(34529);                     // Nether Chain Shirt
            player->RemoveSpell(34534);                     // Bulwark of Kings
            player->RemoveSpell(36257);                     // Bulwark of the Ancient Kings
            player->RemoveSpell(36256);                     // Embrace of the Twisting Nether
            player->RemoveSpell(34530);                     // Twisting Nether Chain Shirt
            player->RemoveSpell(36124);                     // Windforged Leggings
            break;
        case S_UNLEARN_HAMMER:                              // S_UNLEARN_HAMMER
            player->RemoveSpell(36262);                     // Dragonstrike
            player->RemoveSpell(34546);                     // Dragonmaw
            player->RemoveSpell(34545);                     // Drakefist Hammer
            player->RemoveSpell(36136);                     // Lavaforged Warhammer
            player->RemoveSpell(34547);                     // Thunder
            player->RemoveSpell(34567);                     // Deep Thunder
            player->RemoveSpell(36263);                     // Stormherald
            player->RemoveSpell(36137);                     // Great Earthforged Hammer
            break;
        case S_UNLEARN_AXE:                                 // S_UNLEARN_AXE
            player->RemoveSpell(36260);                     // Wicked Edge of the Planes
            player->RemoveSpell(34562);                     // Black Planar Edge
            player->RemoveSpell(34541);                     // The Planar Edge
            player->RemoveSpell(36134);                     // Stormforged Axe
            player->RemoveSpell(36135);                     // Skyforged Great Axe
            player->RemoveSpell(36261);                     // Bloodmoon
            player->RemoveSpell(34543);                     // Lunar Crescent
            player->RemoveSpell(34544);                     // Mooncleaver
            break;
        case S_UNLEARN_SWORD:                               // S_UNLEARN_SWORD
            player->RemoveSpell(36258);                     // Blazefury
            player->RemoveSpell(34537);                     // Blazeguard
            player->RemoveSpell(34535);                     // Fireguard
            player->RemoveSpell(36131);                     // Windforged Rapier
            player->RemoveSpell(36133);                     // Stoneforged Claymore
            player->RemoveSpell(34538);                     // Lionheart Blade
            player->RemoveSpell(34540);                     // Lionheart Champion
            player->RemoveSpell(36259);                     // Lionheart Executioner
            break;
        case S_UNLEARN_DRAGON:                              // S_UNLEARN_DRAGON
            player->RemoveSpell(36076);                     // Dragonstrike Leggings
            player->RemoveSpell(36079);                     // Golden Dragonstrike Breastplate
            player->RemoveSpell(35576);                     // Ebon Netherscale Belt
            player->RemoveSpell(35577);                     // Ebon Netherscale Bracers
            player->RemoveSpell(35575);                     // Ebon Netherscale Breastplate
            player->RemoveSpell(35582);                     // Netherstrike Belt
            player->RemoveSpell(35584);                     // Netherstrike Bracers
            player->RemoveSpell(35580);                     // Netherstrike Breastplate
            break;
        case S_UNLEARN_ELEMENTAL:                           // S_UNLEARN_ELEMENTAL
            player->RemoveSpell(36074);                     // Blackstorm Leggings
            player->RemoveSpell(36077);                     // Primalstorm Breastplate
            player->RemoveSpell(35590);                     // Primalstrike Belt
            player->RemoveSpell(35591);                     // Primalstrike Bracers
            player->RemoveSpell(35589);                     // Primalstrike Vest
            break;
        case S_UNLEARN_TRIBAL:                              // S_UNLEARN_TRIBAL
            player->RemoveSpell(35585);                     // Windhawk Hauberk
            player->RemoveSpell(35587);                     // Windhawk Belt
            player->RemoveSpell(35588);                     // Windhawk Bracers
            player->RemoveSpell(36075);                     // Wildfeather Leggings
            player->RemoveSpell(36078);                     // Living Crystal Breastplate
            break;
        case S_UNLEARN_GOBLIN:                              // S_UNLEARN_GOBLIN
            player->RemoveSpell(30565);                     // Foreman's Enchanted Helmet
            player->RemoveSpell(30566);                     // Foreman's Reinforced Helmet
            player->RemoveSpell(30563);                     // Goblin Rocket Launcher
            player->RemoveSpell(56514);                     // Global Thermal Sapper Charge
            player->RemoveSpell(36954);                     // Dimensional Ripper - Area 52
            player->RemoveSpell(23486);                     // Dimensional Ripper - Everlook
            player->RemoveSpell(23078);                     // Goblin Jumper Cables XL
            player->RemoveSpell(72952);                     // Shatter Rounds
            break;
        case S_UNLEARN_GNOMISH:                             // S_UNLEARN_GNOMISH
            player->RemoveSpell(30575);                     // Gnomish Battle Goggles
            player->RemoveSpell(30574);                     // Gnomish Power Goggles
            player->RemoveSpell(56473);                     // Gnomish X-Ray Specs
            player->RemoveSpell(30569);                     // Gnomish Poultryizer
            player->RemoveSpell(30563);                     // Ultrasafe Transporter - Toshley's Station
            player->RemoveSpell(23489);                     // Ultrasafe Transporter - Gadgetzan
            player->RemoveSpell(23129);                     // World Enlarger
            player->RemoveSpell(23096);                     // Gnomish Alarm-o-Bot
            player->RemoveSpell(72953);                     // Iceblade Arrow
            break;
        case S_UNLEARN_SPELLFIRE:                           // S_UNLEARN_SPELLFIRE
            player->RemoveSpell(26752);                     // Spellfire Belt
            player->RemoveSpell(26753);                     // Spellfire Gloves
            player->RemoveSpell(26754);                     // Spellfire Robe
            break;
        case S_UNLEARN_MOONCLOTH:                           // S_UNLEARN_MOONCLOTH
            player->RemoveSpell(26760);                     // Primal Mooncloth Belt
            player->RemoveSpell(26761);                     // Primal Mooncloth Shoulders
            player->RemoveSpell(26762);                     // Primal Mooncloth Robe
            break;
        case S_UNLEARN_SHADOWEAVE:                          // S_UNLEARN_SHADOWEAVE
            player->RemoveSpell(26756);                     // Frozen Shadoweave Shoulders
            player->RemoveSpell(26757);                     // Frozen Shadoweave Boots
            player->RemoveSpell(26758);                     // Frozen Shadoweave Robe
            break;
    }
}

void ProcessUnlearnAction(Player* player, Creature* creature, uint32 spellId, uint32 alternativeSpellId, int32 cost)
{
    if (EquippedOk(player, spellId))
    {
        if (player->HasEnoughMoney(cost))
        {
            player->CastSpell(player, spellId, true);
            ProfessionUnlearnSpells(player, spellId);
            player->ModifyMoney(-cost);
            if (alternativeSpellId)
                creature->CastSpell(player, alternativeSpellId, true);
        }
        else
            player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
    }
    else
        player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, nullptr, nullptr);
    CloseGossipMenuFor(player);
}

/*###
# start menues blacksmith
###*/

class npc_prof_blacksmith : public CreatureScript
{
public:
    npc_prof_blacksmith() : CreatureScript("npc_prof_blacksmith") { }

    struct npc_prof_blacksmithAI : public ScriptedAI
    {
        npc_prof_blacksmithAI(Creature* creature) : ScriptedAI(creature) { }

        inline bool HasWeaponSub(Player* player)
        {
            return (player->HasSpell(S_HAMMER) || player->HasSpell(S_AXE) || player->HasSpell(S_SWORD));
        }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            uint32 creatureId = me->GetEntry();
            //WEAPONSMITH & ARMORSMITH
            if (player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 225)
            {
                switch (creatureId)
                {
                    case N_TRAINER_SMITHOMNI1:
                    case N_TRAINER_SMITHOMNI2:
                        if (!player->HasSpell(S_ARMOR) && !player->HasSpell(S_WEAPON) && player->GetReputationRank(REP_ARMOR) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ARMOR_LEARN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        if (!player->HasSpell(S_WEAPON) && !player->HasSpell(S_ARMOR) && player->GetReputationRank(REP_WEAPON) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_WEAPON_LEARN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_WEAPON1:
                    case N_TRAINER_WEAPON2:
                        if (player->HasSpell(S_WEAPON))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_WEAPON_UNLEARN, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
                    case N_TRAINER_ARMOR1:
                    case N_TRAINER_ARMOR2:
                        if (player->HasSpell(S_ARMOR))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ARMOR_UNLEARN, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 4);
                        break;
                }
            }
            //WEAPONSMITH SPEC
            if (player->HasSpell(S_WEAPON) && player->GetLevel() > 49 && player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 250)
            {
                switch (creatureId)
                {
                    case N_TRAINER_HAMMER:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_HAMMER, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 5);
                        if (player->HasSpell(S_HAMMER))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_HAMMER, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 8);
                        break;
                    case N_TRAINER_AXE:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_AXE, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 6);
                        if (player->HasSpell(S_AXE))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_AXE, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 9);
                        break;
                    case N_TRAINER_SWORD:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SWORD, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 7);
                        if (player->HasSpell(S_SWORD))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SWORD, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 10);
                        break;
                }
            }

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        void SendActionMenu(Player* player, uint32 action)
        {
            switch (action)
            {
                case GOSSIP_ACTION_TRADE:
                    player->GetSession()->SendListInventory(me->GetGUID());
                    break;
                case GOSSIP_ACTION_TRAIN:
                    player->GetSession()->SendTrainerList(me);
                    break;
                    //Learn Armor/Weapon
                case GOSSIP_ACTION_INFO_DEF + 1:
                    if (!player->HasSpell(S_ARMOR))
                    {
                        player->CastSpell(player, S_LEARN_ARMOR, true);
                        //_Creature->CastSpell(player, S_REP_ARMOR, true);
                    }
                    CloseGossipMenuFor(player);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    if (!player->HasSpell(S_WEAPON))
                    {
                        player->CastSpell(player, S_LEARN_WEAPON, true);
                        //_Creature->CastSpell(player, S_REP_WEAPON, true);
                    }
                    CloseGossipMenuFor(player);
                    break;
                    //Unlearn Armor/Weapon
                case GOSSIP_ACTION_INFO_DEF + 3:
                    if (HasWeaponSub(player))
                    {
                        //unknown textID (TALK_MUST_UNLEARN_WEAPON)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                    }
                    else
                        ProcessUnlearnAction(player, me, S_UNLEARN_WEAPON, S_REP_ARMOR, DoLowUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    ProcessUnlearnAction(player, me, S_UNLEARN_ARMOR, S_REP_WEAPON, DoLowUnlearnCost(player));
                    break;
                    //Learn Hammer/Axe/Sword
                case GOSSIP_ACTION_INFO_DEF + 5:
                    player->CastSpell(player, S_LEARN_HAMMER, true);
                    CloseGossipMenuFor(player);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 6:
                    player->CastSpell(player, S_LEARN_AXE, true);
                    CloseGossipMenuFor(player);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 7:
                    player->CastSpell(player, S_LEARN_SWORD, true);
                    CloseGossipMenuFor(player);
                    break;
                    //Unlearn Hammer/Axe/Sword
                case GOSSIP_ACTION_INFO_DEF + 8:
                    ProcessUnlearnAction(player, me, S_UNLEARN_HAMMER, 0, DoMedUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 9:
                    ProcessUnlearnAction(player, me, S_UNLEARN_AXE, 0, DoMedUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 10:
                    ProcessUnlearnAction(player, me, S_UNLEARN_SWORD, 0, DoMedUnlearnCost(player));
                    break;
            }
        }

        void SendConfirmLearn(Player* player, uint32 action)
        {
            if (action)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_HAMMER:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_HAMMER, GOSSIP_SENDER_CHECK, action);
                        //unknown textID (TALK_HAMMER_LEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_AXE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_AXE, GOSSIP_SENDER_CHECK, action);
                        //unknown textID (TALK_AXE_LEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_SWORD:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SWORD, GOSSIP_SENDER_CHECK, action);
                        //unknown textID (TALK_SWORD_LEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                }
            }
        }

        void SendConfirmUnlearn(Player* player, uint32 action)
        {
            if (action)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_WEAPON1:
                    case N_TRAINER_WEAPON2:
                    case N_TRAINER_ARMOR1:
                    case N_TRAINER_ARMOR2:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SMITH_SPEC, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_ARMORORWEAPON, DoLowUnlearnCost(player), false);
                        //unknown textID (TALK_UNLEARN_AXEORWEAPON)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;

                    case N_TRAINER_HAMMER:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_HAMMER, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID (TALK_HAMMER_UNLEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_AXE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_AXE, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID (TALK_AXE_UNLEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_SWORD:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SWORD, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_WEAPON_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID (TALK_SWORD_UNLEARN)
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                }
            }
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (sender)
            {
                case GOSSIP_SENDER_MAIN:
                    SendActionMenu(player, action);
                    break;

                case GOSSIP_SENDER_LEARN:
                    SendConfirmLearn(player, action);
                    break;

                case GOSSIP_SENDER_UNLEARN:
                    SendConfirmUnlearn(player, action);
                    break;

                case GOSSIP_SENDER_CHECK:
                    SendActionMenu(player, action);
                    break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prof_blacksmithAI(creature);
    }
};

/*###
# engineering trinkets
###*/

enum EngineeringTrinkets
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

#define GOSSIP_ITEM_ZAP         "This Dimensional Imploder sounds dangerous! How can I make one?"
#define GOSSIP_ITEM_JHORDY      "I must build a beacon for this marvelous device!"
#define GOSSIP_ITEM_KABLAM      "[PH] Unknown"

class npc_engineering_tele_trinket : public CreatureScript
{
public:
    npc_engineering_tele_trinket() : CreatureScript("npc_engineering_tele_trinket") { }

    struct npc_engineering_tele_trinketAI : public ScriptedAI
    {
        npc_engineering_tele_trinketAI(Creature* creature) : ScriptedAI(creature) { }

        bool CanLearn(Player* player, uint32 textId, uint32 altTextId, uint32 skillValue, uint32 reqSpellId, uint32 spellId, uint32& npcTextId)
        {
            bool res = false;
            npcTextId = textId;
            if (player->GetBaseSkillValue(SKILL_ENGINEERING) >= skillValue && player->HasSpell(reqSpellId))
            {
                if (!player->HasSpell(spellId))
                    res = true;
                else
                    npcTextId = altTextId;
            }
            return res;
        }

        bool OnGossipHello(Player* player) override
        {
            uint32 npcTextId = 0;
            std::string gossipItem;
            bool canLearn = false;

            if (player->HasSkill(SKILL_ENGINEERING))
            {
                switch (me->GetEntry())
                {
                    case NPC_ZAP:
                        canLearn = CanLearn(player, 6092, 0, 260, S_GOBLIN, SPELL_TO_EVERLOOK, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_ITEM_ZAP;
                        break;
                    case NPC_JHORDY:
                        canLearn = CanLearn(player, 7251, 7252, 260, S_GNOMISH, SPELL_TO_GADGET, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_ITEM_JHORDY;
                        break;
                    case NPC_KABLAM:
                        canLearn = CanLearn(player, 10365, 0, 350, S_GOBLIN, SPELL_TO_AREA52, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_ITEM_KABLAM;
                        break;
                    case NPC_SMILES:
                        canLearn = CanLearn(player, 10363, 0, 350, S_GNOMISH, SPELL_TO_TOSHLEY, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_ITEM_KABLAM;
                        break;
                }
            }

            if (canLearn)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, gossipItem, me->GetEntry(), GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, npcTextId ? npcTextId : player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
                CloseGossipMenuFor(player);

            if (sender != me->GetEntry())
                return true;

            switch (sender)
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_engineering_tele_trinketAI(creature);
    }
};

// Object ID - 177226
// Book "Soothsaying for dummies"
enum SoothsayingForDummies
{
    GOSSIP_ID                = 7058,

    // Engineering
    OPTION_UNLEARN_GNOMISH   = 0,
    OPTION_UNLEARN_GOBLIN    = 1,
    OPTION_LEARN_GNOMISH     = 2,
    OPTION_LEARN_GOBLIN      = 3,

    // Leatherworking
    OPTION_LEARN_DRAGONSCALE = 4,
    OPTION_LEARN_ELEMENTAL   = 5,
    OPTION_LEARN_TRIBAL      = 6
};

class go_soothsaying_for_dummies : public GameObjectScript
{
    public:
        go_soothsaying_for_dummies() : GameObjectScript("go_soothsaying_for_dummies") { }

        struct go_soothsaying_for_dummiesAI : public GameObjectAI
        {
            go_soothsaying_for_dummiesAI(GameObject* go) : GameObjectAI(go) { }

            bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                if (menuId != GOSSIP_ID)
                    return false;

                switch (gossipListId)
                {
                    case OPTION_UNLEARN_GNOMISH:
                        ProcessUnlearnAction(player, nullptr, S_UNLEARN_GNOMISH, 0, 0); // cost is handled by gossip code
                        break;
                    case OPTION_UNLEARN_GOBLIN:
                        ProcessUnlearnAction(player, nullptr, S_UNLEARN_GOBLIN, 0, 0);
                        break;
                    case OPTION_LEARN_GNOMISH:
                        player->CastSpell(player, S_LEARN_GNOMISH, true);
                        break;
                    case OPTION_LEARN_GOBLIN:
                        player->CastSpell(player, S_LEARN_GOBLIN, true);
                        break;
                    case OPTION_LEARN_DRAGONSCALE:
                        player->CastSpell(player, S_LEARN_DRAGON, true);
                        break;
                    case OPTION_LEARN_ELEMENTAL:
                        player->CastSpell(player, S_LEARN_ELEMENTAL, true);
                        break;
                    case OPTION_LEARN_TRIBAL:
                        player->CastSpell(player, S_LEARN_TRIBAL, true);
                        break;
                    default:
                        return false;
                }

                CloseGossipMenuFor(player);
                return true; // prevent further processing
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_soothsaying_for_dummiesAI(go);
        }
};

/*###
# start menues leatherworking
###*/

class npc_prof_leather : public CreatureScript
{
public:
    npc_prof_leather() : CreatureScript("npc_prof_leather") { }

    struct npc_prof_leatherAI : public ScriptedAI
    {
        npc_prof_leatherAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            if (player->HasSkill(SKILL_LEATHERWORKING) && player->GetBaseSkillValue(SKILL_LEATHERWORKING) >= 250 && player->GetLevel() > 49)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_DRAGON1:
                    case N_TRAINER_DRAGON2:
                        if (player->HasSpell(S_DRAGON))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_DRAGON, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case N_TRAINER_ELEMENTAL1:
                    case N_TRAINER_ELEMENTAL2:
                        if (player->HasSpell(S_ELEMENTAL))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_ELEMENTAL, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_TRIBAL1:
                    case N_TRAINER_TRIBAL2:
                        if (player->HasSpell(S_TRIBAL))
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_TRIBAL, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
                }
            }

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        void SendActionMenu(Player* player, uint32 action)
        {
            switch (action)
            {
                case GOSSIP_ACTION_TRADE:
                    player->GetSession()->SendListInventory(me->GetGUID());
                    break;
                case GOSSIP_ACTION_TRAIN:
                    player->GetSession()->SendTrainerList(me);
                    break;
                    //Unlearn Leather
                case GOSSIP_ACTION_INFO_DEF + 1:
                    ProcessUnlearnAction(player, me, S_UNLEARN_DRAGON, 0, DoMedUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    ProcessUnlearnAction(player, me, S_UNLEARN_ELEMENTAL, 0, DoMedUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    ProcessUnlearnAction(player, me, S_UNLEARN_TRIBAL, 0, DoMedUnlearnCost(player));
                    break;
            }
        }

        void SendConfirmUnlearn(Player* player, uint32 action)
        {
            if (action)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_DRAGON1:
                    case N_TRAINER_DRAGON2:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_DRAGON, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_ELEMENTAL1:
                    case N_TRAINER_ELEMENTAL2:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_ELEMENTAL, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_TRIBAL1:
                    case N_TRAINER_TRIBAL2:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_TRIBAL, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_LEATHER_SPEC, DoMedUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                }
            }
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (sender)
            {
                case GOSSIP_SENDER_MAIN:
                    SendActionMenu(player, action);
                    break;

                case GOSSIP_SENDER_UNLEARN:
                    SendConfirmUnlearn(player, action);
                    break;

                case GOSSIP_SENDER_CHECK:
                    SendActionMenu(player, action);
                    break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prof_leatherAI(creature);
    }
};

/*###
# start menues tailoring
###*/

class npc_prof_tailor : public CreatureScript
{
public:
    npc_prof_tailor() : CreatureScript("npc_prof_tailor") { }

    struct npc_prof_tailorAI : public ScriptedAI
    {
        npc_prof_tailorAI(Creature* creature) : ScriptedAI(creature) { }

        inline bool HasTailorSpell(Player* player)
        {
            return (player->HasSpell(S_MOONCLOTH) || player->HasSpell(S_SHADOWEAVE) || player->HasSpell(S_SPELLFIRE));
        }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            //TAILORING SPEC
            if (player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 350 && player->GetLevel() > 59)
            {
                if (player->GetQuestRewardStatus(10831) || player->GetQuestRewardStatus(10832) || player->GetQuestRewardStatus(10833))
                {
                    switch (me->GetEntry())
                    {
                        case N_TRAINER_SPELLFIRE:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SPELLFIRE, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 1);
                            if (player->HasSpell(S_SPELLFIRE))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SPELLFIRE, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 4);
                            break;
                        case N_TRAINER_MOONCLOTH:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_MOONCLOTH, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 2);
                            if (player->HasSpell(S_MOONCLOTH))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_MOONCLOTH, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 5);
                            break;
                        case N_TRAINER_SHADOWEAVE:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SHADOWEAVE, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 3);
                            if (player->HasSpell(S_SHADOWEAVE))
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SHADOWEAVE, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 6);
                            break;
                    }
                }
            }

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        void SendActionMenu(Player* player, uint32 action)
        {
            switch (action)
            {
                case GOSSIP_ACTION_TRADE:
                    player->GetSession()->SendListInventory(me->GetGUID());
                    break;
                case GOSSIP_ACTION_TRAIN:
                    player->GetSession()->SendTrainerList(me);
                    break;
                    //Learn Tailor
                case GOSSIP_ACTION_INFO_DEF + 1:
                    ProcessCastaction(player, me, S_SPELLFIRE, S_LEARN_SPELLFIRE, DoLearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    ProcessCastaction(player, me, S_MOONCLOTH, S_LEARN_MOONCLOTH, DoLearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    ProcessCastaction(player, me, S_SHADOWEAVE, S_LEARN_SHADOWEAVE, DoLearnCost(player));
                    break;
                    //Unlearn Tailor
                case GOSSIP_ACTION_INFO_DEF + 4:
                    ProcessUnlearnAction(player, me, S_UNLEARN_SPELLFIRE, 0, DoHighUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    ProcessUnlearnAction(player, me, S_UNLEARN_MOONCLOTH, 0, DoHighUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 6:
                    ProcessUnlearnAction(player, me, S_UNLEARN_SHADOWEAVE, 0, DoHighUnlearnCost(player));
                    break;
            }
        }

        void SendConfirmLearn(Player* player, uint32 action)
        {
            if (action)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_SPELLFIRE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SPELLFIRE, GOSSIP_SENDER_CHECK, action);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_MOONCLOTH:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_MOONCLOTH, GOSSIP_SENDER_CHECK, action);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_SHADOWEAVE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LEARN_SHADOWEAVE, GOSSIP_SENDER_CHECK, action);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                }
            }
        }

        void SendConfirmUnlearn(Player* player, uint32 action)
        {
            if (action)
            {
                switch (me->GetEntry())
                {
                    case N_TRAINER_SPELLFIRE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SPELLFIRE, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_MOONCLOTH:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_MOONCLOTH, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                    case N_TRAINER_SHADOWEAVE:
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_UNLEARN_SHADOWEAVE, GOSSIP_SENDER_CHECK, action, BOX_UNLEARN_TAILOR_SPEC, DoHighUnlearnCost(player), false);
                        //unknown textID ()
                        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                        break;
                }
            }
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (sender)
            {
                case GOSSIP_SENDER_MAIN:
                    SendActionMenu(player, action);
                    break;

                case GOSSIP_SENDER_LEARN:
                    SendConfirmLearn(player, action);
                    break;

                case GOSSIP_SENDER_UNLEARN:
                    SendConfirmUnlearn(player, action);
                    break;

                case GOSSIP_SENDER_CHECK:
                    SendActionMenu(player, action);
                    break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prof_tailorAI(creature);
    }
};

void AddSC_npc_professions()
{
    new npc_prof_blacksmith();
    new npc_engineering_tele_trinket();
    new go_soothsaying_for_dummies();
    new npc_prof_leather();
    new npc_prof_tailor();
}
