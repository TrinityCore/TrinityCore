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
#include "precompiled.h"
#include "Spell.h"
/*#####
# item_only_for_flight
#####*/
enum eOnlyForFlight
{
    SPELL_ARCANE_CHARGES    = 45072
};
bool ItemUse_item_only_for_flight(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    uint32 itemId = _Item->GetEntry();
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
    pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}
/*#####
# item_draenei_fishing_net
#####*/
//This is just a hack and should be removed from here.
//Creature/Item are in fact created before spell are sucessfully casted, without any checks at all to ensure proper/expected behavior.
bool ItemUse_item_draenei_fishing_net(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    //if (targets.getGOTarget() && targets.getGOTarget()->GetTypeId() == TYPEID_GAMEOBJECT &&
    //targets.getGOTarget()->GetGOInfo()->type == GAMEOBJECT_TYPE_SPELL_FOCUS && targets.getGOTarget()->GetEntry() == 181616)
    //{
    if (pPlayer->GetQuestStatus(9452) == QUEST_STATUS_INCOMPLETE)
    {
        if (rand()%100 < 35)
        {
            Creature *Murloc = pPlayer->SummonCreature(17102,pPlayer->GetPositionX() ,pPlayer->GetPositionY()+20, pPlayer->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
            if (Murloc)
                Murloc->AI()->AttackStart(pPlayer);
        }
        else
        {
            ItemPosCountVec dest;
            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 23614, 1);
            if (msg == EQUIP_ERR_OK)
            {
                Item* item = pPlayer->StoreNewItem(dest,23614,true);
                if (item)
                    pPlayer->SendNewItem(item,1,false,true);
            }else
            pPlayer->SendEquipError(msg,NULL,NULL);
        }
    }
    //}
    return false;
}
/*#####
# item_nether_wraith_beacon
#####*/
bool ItemUse_item_nether_wraith_beacon(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    if (pPlayer->GetQuestStatus(10832) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *Nether;
        Nether = pPlayer->SummonCreature(22408,pPlayer->GetPositionX() ,pPlayer->GetPositionY()+20, pPlayer->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,180000);
        Nether = pPlayer->SummonCreature(22408,pPlayer->GetPositionX() ,pPlayer->GetPositionY()-20, pPlayer->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,180000);
        if (Nether)
            (Nether->AI())->AttackStart(pPlayer);
    }
    return false;
}
/*#####
# item_flying_machine
#####*/
bool ItemUse_item_flying_machine(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    uint32 itemId = _Item->GetEntry();
    if (itemId == 34060)
        if (pPlayer->GetBaseSkillValue(SKILL_RIDING) >= 225)
            return false;
    if (itemId == 34061)
        if (pPlayer->GetBaseSkillValue(SKILL_RIDING) == 300)
            return false;
    debug_log("TSCR: Player attempt to use item %u, but did not meet riding requirement",itemId);
    pPlayer->SendEquipError(EQUIP_ERR_ERR_CANT_EQUIP_SKILL,_Item,NULL);
    return true;
}
/*#####
# item_gor_dreks_ointment
#####*/
bool ItemUse_item_gor_dreks_ointment(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    if (targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 20748 && !targets.getUnitTarget()->HasAura(32578))
        return false;
    pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}
/*#####
# item_incendiary_explosives
#####*/
bool ItemUse_item_incendiary_explosives(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    if (pPlayer->FindNearestCreature(26248,15) || pPlayer->FindNearestCreature(26249,15))
    {
        return false;
    }
    else
    {
        pPlayer->SendEquipError(EQUIP_ERR_OUT_OF_RANGE,_Item,NULL);
        return true;
    }
}
/*#####
# item_mysterious_egg
#####*/
bool ItemExpire_item_mysterious_egg(Player* pPlayer, ItemPrototype const * _ItemProto)
{
    ItemPosCountVec dest;
    uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 39883, 1); // Cracked Egg
    if (msg == EQUIP_ERR_OK)
    {
        pPlayer->StoreNewItem(dest, 39883, true, Item::GenerateItemRandomPropertyId(39883));
    }
    return true;
}
/*#####
# item_disgusting_jar
#####*/
bool ItemExpire_item_disgusting_jar(Player* pPlayer, ItemPrototype const * _ItemProto)
{
    ItemPosCountVec dest;
    uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 44718, 1); // Ripe Disgusting Jar
    if (msg == EQUIP_ERR_OK)
    {
        pPlayer->StoreNewItem(dest, 44718, true, Item::GenerateItemRandomPropertyId(44718));
    }
    return true;
}
/*#####
# item_harvesters_gift
#####*/
#define GHOULS 28845
bool ItemUse_item_harvesters_gift(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    std::list<Creature*> MinionList;
    pPlayer->GetAllMinionsByEntry(MinionList,GHOULS);
    if (pPlayer->GetQuestStatus(12698) == QUEST_STATUS_INCOMPLETE)
    {
        if (!MinionList.empty())
        {
            if (MinionList.size() < 5)
            {
                return false;
            }
            else
            {
                //This should be sent to the player as red text.
                pPlayer->Say("You have created enough ghouls. Return to Gothik the Harvester at Death's Breach.",LANG_UNIVERSAL);
                return true;
            }
        }
        else return false;
    }
    else
    {
        return true;
    }
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
}

