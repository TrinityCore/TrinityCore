/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Item_Scripts
SD%Complete: 100
SDComment: Items for a range of different items. See content below (in script)
SDCategory: Items
EndScriptData */

/* ContentData
item_draenei_fishing_net(i23654)    Hacklike implements chance to spawn item or creature
item_nether_wraith_beacon(i31742)   Summons creatures for quest Becoming a Spellfire Tailor (q10832)
item_flying_machine(i34060,i34061)  Engineering crafted flying machines
item_gor_dreks_ointment(i30175)     Protecting Our Own(q10488)
item_only_for_flight                Items which should only useable while flying
EndContentData */

#include "ScriptedPch.h"
#include "Spell.h"

/*#####
# item_only_for_flight
#####*/

enum eOnlyForFlight
{
    SPELL_ARCANE_CHARGES    = 45072
};

bool ItemUse_item_only_for_flight(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    uint32 itemId = pItem->GetEntry();
    bool disabled = false;

    //for special scripts
    switch(itemId)
    {
       case 24538:
            if (pPlayer->GetAreaId() != 3628)
                disabled = true;
                break;
       case 34489:
            if (pPlayer->GetZoneId() != 4080)
                disabled = true;
                break;
       case 34475:
            if (const SpellEntry* pSpellInfo = GetSpellStore()->LookupEntry(SPELL_ARCANE_CHARGES))
                Spell::SendCastResult(pPlayer, pSpellInfo, 1, SPELL_FAILED_NOT_ON_GROUND);
                break;
    }

    // allow use in flight only
    if (pPlayer->isInFlight() && !disabled)
        return false;

    // error
    pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,pItem,NULL);
    return true;
}

/*#####
# item_draenei_fishing_net
#####*/

//This is just a hack and should be removed from here.
//Creature/Item are in fact created before spell are sucessfully casted, without any checks at all to ensure proper/expected behavior.
bool ItemUse_item_draenei_fishing_net(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    //if (targets.getGOTarget() && targets.getGOTarget()->GetTypeId() == TYPEID_GAMEOBJECT &&
    //targets.getGOTarget()->GetGOInfo()->type == GAMEOBJECT_TYPE_SPELL_FOCUS && targets.getGOTarget()->GetEntry() == 181616)
    //{
    if (pPlayer->GetQuestStatus(9452) == QUEST_STATUS_INCOMPLETE)
    {
        if (urand(0,99) < 35)
        {
            Creature *Murloc = pPlayer->SummonCreature(17102, pPlayer->GetPositionX(), pPlayer->GetPositionY()+20, pPlayer->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
            if (Murloc)
                Murloc->AI()->AttackStart(pPlayer);
        }
        else
        {
            ItemPosCountVec dest;
            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 23614, 1);
            if (msg == EQUIP_ERR_OK)
            {
                if (Item* item = pPlayer->StoreNewItem(dest,23614,true))
                    pPlayer->SendNewItem(item,1,false,true);
            } else
                pPlayer->SendEquipError(msg,NULL,NULL);
        }
    }
    //}
    return false;
}

/*#####
# item_nether_wraith_beacon
#####*/

bool ItemUse_item_nether_wraith_beacon(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    if (pPlayer->GetQuestStatus(10832) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *Nether;
        Nether = pPlayer->SummonCreature(22408, pPlayer->GetPositionX(), pPlayer->GetPositionY()+20, pPlayer->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
        Nether = pPlayer->SummonCreature(22408, pPlayer->GetPositionX(), pPlayer->GetPositionY()-20, pPlayer->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
        if (Nether)
            Nether->AI()->AttackStart(pPlayer);
    }
    return false;
}

/*#####
# item_flying_machine
#####*/

bool ItemUse_item_flying_machine(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    uint32 itemId = pItem->GetEntry();
    if (itemId == 34060)
        if (pPlayer->GetBaseSkillValue(SKILL_RIDING) >= 225)
            return false;

    if (itemId == 34061)
        if (pPlayer->GetBaseSkillValue(SKILL_RIDING) == 300)
            return false;

    debug_log("TSCR: Player attempt to use item %u, but did not meet riding requirement",itemId);
    pPlayer->SendEquipError(EQUIP_ERR_ERR_CANT_EQUIP_SKILL,pItem,NULL);
    return true;
}

/*#####
# item_gor_dreks_ointment
#####*/

bool ItemUse_item_gor_dreks_ointment(Player *pPlayer, Item *pItem, SpellCastTargets const& targets)
{
    if (targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId() == TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 20748 && !targets.getUnitTarget()->HasAura(32578))
        return false;

    pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,pItem,NULL);
    return true;
}

/*#####
# item_incendiary_explosives
#####*/

bool ItemUse_item_incendiary_explosives(Player *pPlayer, Item *pItem, SpellCastTargets const &targets)
{
    if (pPlayer->FindNearestCreature(26248,15) || pPlayer->FindNearestCreature(26249,15))
        return false;
    else
    {
        pPlayer->SendEquipError(EQUIP_ERR_OUT_OF_RANGE,pItem,NULL);
        return true;
    }
}

/*#####
# item_mysterious_egg
#####*/

bool ItemExpire_item_mysterious_egg(Player *pPlayer, ItemPrototype const *pItemProto)
{
    ItemPosCountVec dest;
    uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 39883, 1); // Cracked Egg
    if (msg == EQUIP_ERR_OK)
        pPlayer->StoreNewItem(dest, 39883, true, Item::GenerateItemRandomPropertyId(39883));

    return true;
}

/*#####
# item_disgusting_jar
#####*/

bool ItemExpire_item_disgusting_jar(Player *pPlayer, ItemPrototype const *pItemProto)
{
    ItemPosCountVec dest;
    uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 44718, 1); // Ripe Disgusting Jar
    if (msg == EQUIP_ERR_OK)
        pPlayer->StoreNewItem(dest, 44718, true, Item::GenerateItemRandomPropertyId(44718));

    return true;
}

/*#####
# item_harvesters_gift
#####*/
#define GHOULS 28845
bool ItemUse_item_harvesters_gift(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    std::list<Creature*> MinionList;
    pPlayer->GetAllMinionsByEntry(MinionList,GHOULS);

    if (pPlayer->GetQuestStatus(12698) == QUEST_STATUS_INCOMPLETE)
    {
        if (!MinionList.empty())
        {
            if (MinionList.size() < 5)
                return false;
            else
            {
                //This should be sent to the player as red text.
                pPlayer->Say("You have created enough ghouls. Return to Gothik the Harvester at Death's Breach.",LANG_UNIVERSAL);
                return true;
            }
        }
        else
            return false;
    }
    return true;
}

/*#####
# item_pile_fake_furs
#####*/

enum ePileFakeFur
{
    GO_CARIBOU_TRAP_1                                      = 187982,
    GO_CARIBOU_TRAP_2                                      = 187995,
    GO_CARIBOU_TRAP_3                                      = 187996,
    GO_CARIBOU_TRAP_4                                      = 187997,
    GO_CARIBOU_TRAP_5                                      = 187998,
    GO_CARIBOU_TRAP_6                                      = 187999,
    GO_CARIBOU_TRAP_7                                      = 188000,
    GO_CARIBOU_TRAP_8                                      = 188001,
    GO_CARIBOU_TRAP_9                                      = 188002,
    GO_CARIBOU_TRAP_10                                     = 188003,
    GO_CARIBOU_TRAP_11                                     = 188004,
    GO_CARIBOU_TRAP_12                                     = 188005,
    GO_CARIBOU_TRAP_13                                     = 188006,
    GO_CARIBOU_TRAP_14                                     = 188007,
    GO_CARIBOU_TRAP_15                                     = 188008,
    GO_HIGH_QUALITY_FUR                                    = 187983,
    NPC_NESINGWARY_TRAPPER                                 = 25835
};
bool ItemUse_item_pile_fake_furs(Player *pPlayer, Item *pItem, SpellCastTargets const &targets)
{
    GameObject *pGo;
    if ((pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_1, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_2, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_3, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_4, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_5, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_6, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_7, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_8, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_9, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_10, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_11, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_12, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_13, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_14, 5.0f)) ||
        (pGo = pPlayer->FindNearestGameObject(GO_CARIBOU_TRAP_15, 5.0f)))
    {
        if (pGo->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, true) || pGo->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, false) || pGo->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 2.0f))
            return true;
        float x, y, z;
        pGo->GetClosePoint(x, y, z, pGo->GetObjectSize() / 3, 7.0f);
        pGo->SummonGameObject(GO_HIGH_QUALITY_FUR, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), 0, 0, 0, 0, 0, 1000);
        if (TempSummon* summon = pPlayer->SummonCreature(NPC_NESINGWARY_TRAPPER, x, y, z, pGo->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 1000))
        {
            summon->SetVisibility(VISIBILITY_OFF);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }
    }
    return false;
}

/*#####
# item_petrov_cluster_bombs
#####*/

enum ePetrovClusterBombs
{
    SPELL_PETROV_BOMB           = 42406,
    AREA_ID_SHATTERED_STRAITS   = 4064,
    ZONE_ID_HOWLING             = 495
};

bool ItemUse_item_petrov_cluster_bombs(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
    if (pPlayer->GetZoneId() != ZONE_ID_HOWLING)
        return false;

    if (!pPlayer->GetTransport() || pPlayer->GetAreaId() != AREA_ID_SHATTERED_STRAITS)
    {
        pPlayer->SendEquipError(EQUIP_ERR_NONE, pItem, NULL);

        if (const SpellEntry* pSpellInfo = GetSpellStore()->LookupEntry(SPELL_PETROV_BOMB))
            Spell::SendCastResult(pPlayer, pSpellInfo, 1, SPELL_FAILED_NOT_HERE);

        return true;
    }

    return false;
}

/*######
# item_dehta_trap_smasher
# For quest 11876, Help Those That Cannot Help Themselves
######*/
enum eHelpThemselves
{
    QUEST_CANNOT_HELP_THEMSELVES                  =  11876,
    NPC_TRAPPED_MAMMOTH_CALF                      =  25850,
    GO_MAMMOTH_TRAP_1                             = 188022,
    GO_MAMMOTH_TRAP_2                             = 188024,
    GO_MAMMOTH_TRAP_3                             = 188025,
    GO_MAMMOTH_TRAP_4                             = 188026,
    GO_MAMMOTH_TRAP_5                             = 188027,
    GO_MAMMOTH_TRAP_6                             = 188028,
    GO_MAMMOTH_TRAP_7                             = 188029,
    GO_MAMMOTH_TRAP_8                             = 188030,
    GO_MAMMOTH_TRAP_9                             = 188031,
    GO_MAMMOTH_TRAP_10                            = 188032,
    GO_MAMMOTH_TRAP_11                            = 188033,
    GO_MAMMOTH_TRAP_12                            = 188034,
    GO_MAMMOTH_TRAP_13                            = 188035,
    GO_MAMMOTH_TRAP_14                            = 188036,
    GO_MAMMOTH_TRAP_15                            = 188037,
    GO_MAMMOTH_TRAP_16                            = 188038,
    GO_MAMMOTH_TRAP_17                            = 188039,
    GO_MAMMOTH_TRAP_18                            = 188040,
    GO_MAMMOTH_TRAP_19                            = 188041,
    GO_MAMMOTH_TRAP_20                            = 188042,
    GO_MAMMOTH_TRAP_21                            = 188043,
    GO_MAMMOTH_TRAP_22                            = 188044,
};

bool ItemUse_item_dehta_trap_smasher(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
    Creature* pMammoth;
    GameObject* pTrap;
    
    if (pPlayer->GetQuestStatus(QUEST_CANNOT_HELP_THEMSELVES) == QUEST_STATUS_INCOMPLETE &&
        (pMammoth = pPlayer->FindNearestCreature(NPC_TRAPPED_MAMMOTH_CALF,5.0f)) &&
        ((pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_1,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_2,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_3,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_4,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_5,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_6,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_7,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_8,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_9,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_10,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_11,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_12,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_13,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_14,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_15,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_16,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_17,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_18,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_19,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_20,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_21,5.0f)) ||
        (pTrap = pPlayer->FindNearestGameObject(GO_MAMMOTH_TRAP_22,5.0f))))
    {
        pMammoth->AI()->DoAction(1);
        pTrap->SetGoState(GO_STATE_READY);
        pPlayer->KilledMonsterCredit(NPC_TRAPPED_MAMMOTH_CALF,0);
    }

    return false;
}

void AddSC_item_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "item_only_for_flight";
    newscript->pItemUse = &ItemUse_item_only_for_flight;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_draenei_fishing_net";
    newscript->pItemUse = &ItemUse_item_draenei_fishing_net;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_nether_wraith_beacon";
    newscript->pItemUse = &ItemUse_item_nether_wraith_beacon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_flying_machine";
    newscript->pItemUse = &ItemUse_item_flying_machine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_gor_dreks_ointment";
    newscript->pItemUse = &ItemUse_item_gor_dreks_ointment;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_incendiary_explosives";
    newscript->pItemUse = &ItemUse_item_incendiary_explosives;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_mysterious_egg";
    newscript->pItemExpire = &ItemExpire_item_mysterious_egg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_disgusting_jar";
    newscript->pItemExpire = &ItemExpire_item_disgusting_jar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_harvesters_gift";
    newscript->pItemUse = &ItemUse_item_harvesters_gift;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_pile_fake_furs";
    newscript->pItemUse = &ItemUse_item_pile_fake_furs;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_petrov_cluster_bombs";
    newscript->pItemUse = &ItemUse_item_petrov_cluster_bombs;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_dehta_trap_smasher";
    newscript->pItemUse = &ItemUse_item_dehta_trap_smasher;
    newscript->RegisterSelf();
}
