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
# generic defines
###*/

#define GOSSIP_SENDER_LEARN         50
#define GOSSIP_SENDER_UNLEARN       51
#define GOSSIP_SENDER_CHECK         52

/*###
# gossip item and box texts
###*/

enum Gossips
{
    GOSSIP_SPELLFIRE        = 8531, // Gidge Spellweaver
    GOSSIP_MOONCLOTH        = 8530, // Nasmara Moonsong
    GOSSIP_SHADOWEAVE       = 8532, // Andrion Darkspinner
    GOSSIP_DRAGON1          = 3067, // Peter Galen
    GOSSIP_DRAGON2          = 3068, // Thorkaf Dragoneye
    GOSSIP_ELEMENTAL1       = 3070, // Sarah Tanner
    GOSSIP_ELEMENTAL2       = 3069, // Brumn Winterhoof
    GOSSIP_TRIBAL1          = 3072, // Caryssia Moonhunter
    GOSSIP_TRIBAL2          = 3071, // Se'Jib
    GOSSIP_SMITHOMNI1       = 3182, // Myolor Sunderfury
    GOSSIP_SMITHOMNI2       = 3187, // Krathok Moltenfist
    GOSSIP_WEAPON1          = 3201, // Ironus Coldsteel
    GOSSIP_WEAPON2          = 3202, // Borgosh Corebender
    GOSSIP_ARMOR1           = 597,  // Grumnus Steelshaper
    GOSSIP_ARMOR2           = 3203, // Okothos Ironrager
    GOSSIP_HAMMER           = 6090, // Lilith the Lithe
    GOSSIP_AXE              = 6089, // Kilram
    GOSSIP_SWORD            = 6091, // Seril Scourgebane
    GOSSIP_TRANSMUTE        = 8542, // Zarevhi
    GOSSIP_ELIXIR           = 8540, // Lorokeem
    GOSSIP_POTION           = 7571, // Lauranna Thar'well
    GOSSIP_ZAP              = 6092, // Zap Farflinger
    GOSSIP_JHORDY           = 6094, // Jhordy Lapforge
    GOSSIP_KABLAM           = 8308, // Kablamm Farflinger
    GOSSIP_SMILES           = 8306, // Smiles O'Byron
    GOSSIP_LEARN            = 1,
    GOSSIP_UNLEARN          = 2
};

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
    S_UNLEARN_SHADOWEAVE    = 41559,

    S_TRANSMUTE             = 28672,
    S_ELIXIR                = 28677,
    S_POTION                = 28675,

    S_LEARN_TRANSMUTE       = 28674,
    S_LEARN_ELIXIR          = 28678,
    S_LEARN_POTION          = 28676,

    S_UNLEARN_TRANSMUTE     = 41565,
    S_UNLEARN_ELIXIR        = 41564,
    S_UNLEARN_POTION        = 41563,
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

    /* Alchemy */
    N_TRAINER_TRANSMUTE     = 22427, // Zarevhi
    N_TRAINER_ELIXIR        = 19052, // Lorokeem
    N_TRAINER_POTION        = 17909, // Lauranna Thar'well

};

enum ProfessionQuest
{
    Q_MASTER_TRANSMUTE      = 10899,
    Q_MASTER_ELIXIR         = 10902,
    Q_MASTER_POTION         = 10897,
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
                TC_LOG_DEBUG("scripts", "player attempt to unlearn spell {}, but item {} is equipped.", reqSpell, item->GetEntry());
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
        player->SendEquipError(EQUIP_ERR_CLIENT_LOCKED_OUT, nullptr, nullptr);
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
                AddGossipItemFor(player, 0, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, 0, 3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            uint32 creatureId = me->GetEntry();
            //WEAPONSMITH & ARMORSMITH
            if (player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 225)
            {
                uint8 level = player->GetLevel();
                uint32 gossipOption = 0;
                if (level < 66)
                    gossipOption = 1;
                else
                    gossipOption = 2;
                switch (creatureId)
                {
                    case N_TRAINER_SMITHOMNI1:
                        if (!player->HasSpell(S_ARMOR) && !player->HasSpell(S_WEAPON) && player->GetReputationRank(REP_ARMOR) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_SMITHOMNI1, 2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        if (!player->HasSpell(S_WEAPON) && !player->HasSpell(S_ARMOR) && player->GetReputationRank(REP_WEAPON) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_SMITHOMNI1, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_SMITHOMNI2:
                        if (!player->HasSpell(S_ARMOR) && !player->HasSpell(S_WEAPON) && player->GetReputationRank(REP_ARMOR) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_SMITHOMNI2, 2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        if (!player->HasSpell(S_WEAPON) && !player->HasSpell(S_ARMOR) && player->GetReputationRank(REP_WEAPON) >= REP_FRIENDLY)
                            AddGossipItemFor(player, GOSSIP_SMITHOMNI2, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_WEAPON1:
                        if (player->HasSpell(S_WEAPON))
                            AddGossipItemFor(player, GOSSIP_WEAPON1, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
                    case N_TRAINER_WEAPON2:
                        if (player->HasSpell(S_WEAPON))
                            AddGossipItemFor(player, GOSSIP_WEAPON2, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
                    case N_TRAINER_ARMOR1:
                        if (player->HasSpell(S_ARMOR))
                            AddGossipItemFor(player, GOSSIP_ARMOR1, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 4);
                        break;
                    case N_TRAINER_ARMOR2:
                        if (player->HasSpell(S_ARMOR))
                            AddGossipItemFor(player, GOSSIP_ARMOR2, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 4);
                        break;
                }
            }
            //WEAPONSMITH SPEC
            if (player->HasSpell(S_WEAPON) && player->GetLevel() > 49 && player->GetBaseSkillValue(SKILL_BLACKSMITHING) >= 250)
            {
                uint8 level = player->GetLevel();
                uint32 gossipOption = 0;
                if (level < 51)
                    gossipOption = 2;
                else if (level < 66)
                    gossipOption = 3;
                else
                    gossipOption = 4;
                switch (creatureId)
                {
                    case N_TRAINER_HAMMER:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_HAMMER, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 5);
                        if (player->HasSpell(S_HAMMER))
                            AddGossipItemFor(player, GOSSIP_HAMMER, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 8);
                        break;
                    case N_TRAINER_AXE:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_AXE, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 6);
                        if (player->HasSpell(S_AXE))
                            AddGossipItemFor(player, GOSSIP_AXE, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 9);
                        break;
                    case N_TRAINER_SWORD:
                        if (!HasWeaponSub(player))
                            AddGossipItemFor(player, GOSSIP_SWORD, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 7);
                        if (player->HasSpell(S_SWORD))
                            AddGossipItemFor(player, GOSSIP_SWORD, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 10);
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

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            SendActionMenu(player, action);
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
            uint32 gossipItem;
            bool canLearn = false;

            if (player->HasSkill(SKILL_ENGINEERING))
            {
                switch (me->GetEntry())
                {
                    case NPC_ZAP:
                        canLearn = CanLearn(player, 6092, 0, 260, S_GOBLIN, SPELL_TO_EVERLOOK, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_ZAP;
                        break;
                    case NPC_JHORDY:
                        canLearn = CanLearn(player, 7251, 7252, 260, S_GNOMISH, SPELL_TO_GADGET, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_JHORDY;
                        break;
                    case NPC_KABLAM:
                        canLearn = CanLearn(player, 10365, 0, 350, S_GOBLIN, SPELL_TO_AREA52, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_KABLAM;
                        break;
                    case NPC_SMILES:
                        canLearn = CanLearn(player, 10363, 0, 350, S_GNOMISH, SPELL_TO_TOSHLEY, npcTextId);
                        if (canLearn)
                            gossipItem = GOSSIP_SMILES;
                        break;
                }
            }

            if (canLearn)
                AddGossipItemFor(player, gossipItem, 2, me->GetEntry(), GOSSIP_ACTION_INFO_DEF + 1);

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
                AddGossipItemFor(player, 0, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, 0, 3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            if (player->HasSkill(SKILL_LEATHERWORKING) && player->GetBaseSkillValue(SKILL_LEATHERWORKING) >= 250 && player->GetLevel() > 49)
            {
                uint8 level = player->GetLevel();
                uint32 gossipOption = 0;
                if (level < 51)
                    gossipOption = 2;
                else if (level < 66)
                    gossipOption = 3;
                else
                    gossipOption = 4;
                switch (me->GetEntry())
                {
                    case N_TRAINER_DRAGON1:
                        if (player->HasSpell(S_DRAGON))
                            AddGossipItemFor(player, GOSSIP_DRAGON1, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case N_TRAINER_DRAGON2:
                        if (player->HasSpell(S_DRAGON))
                            AddGossipItemFor(player, GOSSIP_DRAGON2, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case N_TRAINER_ELEMENTAL1:
                        if (player->HasSpell(S_ELEMENTAL))
                            AddGossipItemFor(player, GOSSIP_ELEMENTAL1, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_ELEMENTAL2:
                        if (player->HasSpell(S_ELEMENTAL))
                            AddGossipItemFor(player, GOSSIP_ELEMENTAL2, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 2);
                        break;
                    case N_TRAINER_TRIBAL1:
                        if (player->HasSpell(S_TRIBAL))
                            AddGossipItemFor(player, GOSSIP_TRIBAL1, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
                    case N_TRAINER_TRIBAL2:
                        if (player->HasSpell(S_TRIBAL))
                            AddGossipItemFor(player, GOSSIP_TRIBAL2, gossipOption, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 3);
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

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            SendActionMenu(player, action);
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
                AddGossipItemFor(player, 0, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, 0, 3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            //TAILORING SPEC
            if (player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 350 && player->GetLevel() > 59)
            {
                if (player->GetQuestRewardStatus(10831) || player->GetQuestRewardStatus(10832) || player->GetQuestRewardStatus(10833))
                {
                    switch (me->GetEntry())
                    {
                        case N_TRAINER_SPELLFIRE:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_SPELLFIRE, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 1);
                            if (player->HasSpell(S_SPELLFIRE))
                                AddGossipItemFor(player, GOSSIP_SPELLFIRE, GOSSIP_UNLEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 4);
                            break;
                        case N_TRAINER_MOONCLOTH:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_MOONCLOTH, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 2);
                            if (player->HasSpell(S_MOONCLOTH))
                                AddGossipItemFor(player, GOSSIP_MOONCLOTH, GOSSIP_UNLEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 5);
                            break;
                        case N_TRAINER_SHADOWEAVE:
                            if (!HasTailorSpell(player))
                                AddGossipItemFor(player, GOSSIP_SHADOWEAVE, GOSSIP_LEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 3);
                            if (player->HasSpell(S_SHADOWEAVE))
                                AddGossipItemFor(player, GOSSIP_SHADOWEAVE, GOSSIP_UNLEARN, GOSSIP_SENDER_CHECK, GOSSIP_ACTION_INFO_DEF + 6);
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

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            SendActionMenu(player, action);
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prof_tailorAI(creature);
    }
};

/*###
# start menues alchemy
###*/
class npc_prof_alchemy : public CreatureScript
{
public:
    npc_prof_alchemy() : CreatureScript("npc_prof_alchemy") { }

    struct npc_prof_alchemyAI : public ScriptedAI
    {
        npc_prof_alchemyAI(Creature* creature) : ScriptedAI(creature) { }

        inline bool HasAlchemySpell(Player* player)
        {
            return (player->HasSpell(S_TRANSMUTE) || player->HasSpell(S_ELIXIR) || player->HasSpell(S_POTION));
        }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
                AddGossipItemFor(player, 0, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsTrainer())
                AddGossipItemFor(player, 0, 3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

            if (player->HasSkill(SKILL_ALCHEMY) && player->GetBaseSkillValue(SKILL_ALCHEMY) >= 350 && player->GetLevel() > 67)
            {
                if (player->GetQuestRewardStatus(Q_MASTER_TRANSMUTE) || player->GetQuestRewardStatus(Q_MASTER_ELIXIR) || player->GetQuestRewardStatus(Q_MASTER_POTION))
                {
                    switch (me->GetEntry())
                    {
                        case N_TRAINER_TRANSMUTE:
                            if (!HasAlchemySpell(player))
                                AddGossipItemFor(player, GOSSIP_TRANSMUTE, GOSSIP_LEARN, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 1);
                            if (player->HasSpell(S_TRANSMUTE))
                                AddGossipItemFor(player, GOSSIP_TRANSMUTE, GOSSIP_UNLEARN, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 4);
                            break;
                        case N_TRAINER_ELIXIR:
                            if (!HasAlchemySpell(player))
                                AddGossipItemFor(player, GOSSIP_ELIXIR, GOSSIP_LEARN, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 2);
                            if (player->HasSpell(S_ELIXIR))
                                AddGossipItemFor(player, GOSSIP_ELIXIR, GOSSIP_UNLEARN, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 5);
                            break;
                        case N_TRAINER_POTION:
                            if (!HasAlchemySpell(player))
                                AddGossipItemFor(player, GOSSIP_POTION, GOSSIP_LEARN, GOSSIP_SENDER_LEARN, GOSSIP_ACTION_INFO_DEF + 3);
                            if (player->HasSpell(S_POTION))
                                AddGossipItemFor(player, GOSSIP_POTION, GOSSIP_UNLEARN, GOSSIP_SENDER_UNLEARN, GOSSIP_ACTION_INFO_DEF + 6);
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
                //Learn Alchemy
                case GOSSIP_ACTION_INFO_DEF + 1:
                    ProcessCastaction(player, me, S_TRANSMUTE, S_LEARN_TRANSMUTE, DoLearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    ProcessCastaction(player, me, S_ELIXIR, S_LEARN_ELIXIR, DoLearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    ProcessCastaction(player, me, S_POTION, S_LEARN_POTION, DoLearnCost(player));
                    break;
                //Unlearn Alchemy
                case GOSSIP_ACTION_INFO_DEF + 4:
                    ProcessUnlearnAction(player, me, S_UNLEARN_TRANSMUTE, 0, DoHighUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    ProcessUnlearnAction(player, me, S_UNLEARN_ELIXIR, 0, DoHighUnlearnCost(player));
                    break;
                case GOSSIP_ACTION_INFO_DEF + 6:
                    ProcessUnlearnAction(player, me, S_UNLEARN_POTION, 0, DoHighUnlearnCost(player));
                    break;
            }
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            SendActionMenu(player, action);
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prof_alchemyAI(creature);
    }
};

void AddSC_npc_professions()
{
    new npc_prof_blacksmith();
    new npc_engineering_tele_trinket();
    new go_soothsaying_for_dummies();
    new npc_prof_leather();
    new npc_prof_tailor();
    new npc_prof_alchemy();
}
