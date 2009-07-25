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
item_area_52_special(i28132)        Prevents abuse of this item
item_attuned_crystal_cores(i34368)  Prevent abuse(quest 11524 & 11525)
item_blackwhelp_net(i31129)         Quest Whelps of the Wyrmcult (q10747). Prevents abuse
item_dart_gun                       Prevent quest provided item instakill anything but the expected
item_draenei_fishing_net(i23654)    Hacklike implements chance to spawn item or creature
item_disciplinary_rod               Prevents abuse
item_nether_wraith_beacon(i31742)   Summons creatures for quest Becoming a Spellfire Tailor (q10832)
item_flying_machine(i34060,i34061)  Engineering crafted flying machines
item_gor_dreks_ointment(i30175)     Protecting Our Own(q10488)
item_muiseks_vessel                 Cast on creature, they must be dead(q 3123,3124,3125,3126,3127)
item_only_for_flight                Items which should only useable while flying
item_protovoltaic_magneto_collector Prevents abuse
item_razorthorn_flayer_gland        Quest Discovering Your Roots (q11520) and Rediscovering Your Roots (q11521). Prevents abuse
item_tame_beast_rods(many)          Prevent cast on any other creature than the intended (for all tame beast quests)
item_soul_cannon(i32825)            Prevents abuse of this item
item_sparrowhawk_net(i32321)        Quest To Catch A Sparrowhawk (q10987). Prevents abuse
item_voodoo_charm                   Provide proper error message and target(q2561)
item_vorenthals_presence(i30259)    Prevents abuse of this item
item_yehkinyas_bramble(i10699)      Allow cast spell on vale screecher only and remove corpse if cast sucessful (q3520)
item_zezzak_shard(i31463)           Quest The eyes of Grillok (q10813). Prevents abuse
item_inoculating_crystal            Quest Inoculating. Prevent abuse
EndContentData */

#include "precompiled.h"
#include "SpellMgr.h"
#include "Spell.h"
#include "WorldPacket.h"

/*#####
# item_area_52_special
#####*/

bool ItemUse_item_area_52_special(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if ( player->GetAreaId() == 3803 )
    {
        return false;
    }
    else
    {
        player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE,_Item,NULL);
        return true;
    }
}

/*#####
# item_only_for_flight
#####*/

bool ItemUse_item_only_for_flight(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    uint32 itemId = _Item->GetEntry();
    bool disabled = false;

    //for special scripts
    switch(itemId)
    {
       case 24538:
            if(player->GetAreaId() != 3628)
                disabled = true;
                break;
       case 34489:
            if(player->GetZoneId() != 4080)
                disabled = true;
                break;
    }

    // allow use in flight only
    if( player->isInFlight() && !disabled)
        return false;

    // error
    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}

/*#####
# item_attuned_crystal_cores
#####*/

bool ItemUse_item_attuned_crystal_cores(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 24972 && targets.getUnitTarget()->isDead() &&
        (player->GetQuestStatus(11524) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(11525) == QUEST_STATUS_INCOMPLETE) )
    {
        CAST_CRE(targets.getUnitTarget())->RemoveCorpse();
        return false;
    }

    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}

/*#####
# item_blackwhelp_net
#####*/

bool ItemUse_item_blackwhelp_net(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 21387 )
        return false;

    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_dart_gun
#####*/

enum
{
    NPC_HAMMER_SCOUT    = 32201
};

bool ItemUse_item_dart_gun(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
    if (pTargets.getUnitTarget() && pTargets.getUnitTarget()->GetTypeId() == TYPEID_UNIT &&
        pTargets.getUnitTarget()->GetEntry() == NPC_HAMMER_SCOUT)
        return false;

    pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, pItem, NULL);
    return true;
}

/*#####
# item_draenei_fishing_net
#####*/

//This is just a hack and should be removed from here.
//Creature/Item are in fact created before spell are sucessfully casted, without any checks at all to ensure proper/expected behavior.
bool ItemUse_item_draenei_fishing_net(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    //if( targets.getGOTarget() && targets.getGOTarget()->GetTypeId() == TYPEID_GAMEOBJECT &&
    //targets.getGOTarget()->GetGOInfo()->type == GAMEOBJECT_TYPE_SPELL_FOCUS && targets.getGOTarget()->GetEntry() == 181616 )
    //{
    if( player->GetQuestStatus(9452) == QUEST_STATUS_INCOMPLETE )
    {
        if( rand()%100 < 35 )
        {
            Creature *Murloc = player->SummonCreature(17102,player->GetPositionX() ,player->GetPositionY()+20, player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
            if( Murloc )
                Murloc->AI()->AttackStart(player);
        }
        else
        {
            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 23614, 1);
            if( msg == EQUIP_ERR_OK )
            {
                Item* item = player->StoreNewItem(dest,23614,true);
                if( item )
                    player->SendNewItem(item,1,false,true);
            }else
            player->SendEquipError(msg,NULL,NULL);
        }
    }
    //}
    return false;
}

/*#####
# item_disciplinary_rod
#####*/

bool ItemUse_item_disciplinary_rod(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        (targets.getUnitTarget()->GetEntry() == 15941 || targets.getUnitTarget()->GetEntry() == 15945) )
        return false;

    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}

/*#####
# item_nether_wraith_beacon
#####*/

bool ItemUse_item_nether_wraith_beacon(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if (player->GetQuestStatus(10832) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *Nether;
        Nether = player->SummonCreature(22408,player->GetPositionX() ,player->GetPositionY()+20, player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,180000);
        Nether = player->SummonCreature(22408,player->GetPositionX() ,player->GetPositionY()-20, player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,180000);
        if (Nether)
            (Nether->AI())->AttackStart(player);
    }
    return false;
}

/*#####
# item_flying_machine
#####*/

bool ItemUse_item_flying_machine(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    uint32 itemId = _Item->GetEntry();
    if( itemId == 34060 )
        if( player->GetBaseSkillValue(SKILL_RIDING) >= 225 )
            return false;

    if( itemId == 34061 )
        if( player->GetBaseSkillValue(SKILL_RIDING) == 300 )
            return false;

    debug_log("TSCR: Player attempt to use item %u, but did not meet riding requirement",itemId);
    player->SendEquipError(EQUIP_ERR_ERR_CANT_EQUIP_SKILL,_Item,NULL);
    return true;
}

/*#####
# item_gor_dreks_ointment
#####*/

bool ItemUse_item_gor_dreks_ointment(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 20748 && !targets.getUnitTarget()->HasAura(32578) )
        return false;

    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}

/*#####
# item_muiseks_vessel
#####*/

bool ItemUse_item_muiseks_vessel(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    Unit* uTarget = targets.getUnitTarget();
    uint32 itemSpell = _Item->GetProto()->Spells[0].SpellId;
    uint32 cEntry = 0;
    uint32 cEntry2 = 0;
    uint32 cEntry3 = 0;
    uint32 cEntry4 = 0;

    if(itemSpell)
    {
        switch(itemSpell)
        {
            case 11885:                                     //Wandering Forest Walker
                cEntry =  7584;
                break;
            case 11886:                                     //Owlbeasts
                cEntry =  2927;
                cEntry2 = 2928;
                cEntry3 = 2929;
                cEntry4 = 7808;
                break;
            case 11887:                                     //Freyfeather Hippogryphs
                cEntry =  5300;
                cEntry2 = 5304;
                cEntry3 = 5305;
                cEntry4 = 5306;
                break;
            case 11888:                                     //Sprite Dragon Sprite Darters
                cEntry =  5276;
                cEntry2 = 5278;
                break;
            case 11889:                                     //Zapped Land Walker Land Walker Zapped Cliff Giant Cliff Giant
                cEntry =  5357;
                cEntry2 = 5358;
                cEntry3 = 14640;
                cEntry4 = 14604;
                break;
        }
        if( uTarget && uTarget->GetTypeId()==TYPEID_UNIT && uTarget->isDead() &&
            (uTarget->GetEntry()==cEntry || uTarget->GetEntry()==cEntry2 || uTarget->GetEntry()==cEntry3 || uTarget->GetEntry()==cEntry4) )
        {
            CAST_CRE(uTarget)->RemoveCorpse();
            return false;
        }
    }

    WorldPacket data(SMSG_CAST_FAILED, (4+2));              // prepare packet error message
    data << uint32(_Item->GetEntry());                      // itemId
    data << uint8(SPELL_FAILED_BAD_TARGETS);                // reason
    player->GetSession()->SendPacket(&data);                // send message: Invalid target

    player->SendEquipError(EQUIP_ERR_NONE,_Item,NULL);      // break spell
    return true;
}

/*#####
# item_inoculating_crystal
#####*/

bool ItemUse_item_inoculating_crystal(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 16518 )
        return false;

    WorldPacket data(SMSG_CAST_FAILED, (4+2));              // prepare packet error message
    data << uint32(_Item->GetEntry());                      // itemId
    data << uint8(SPELL_FAILED_BAD_TARGETS);                // reason
    player->GetSession()->SendPacket(&data);                // send message: Invalid target

    player->SendEquipError(EQUIP_ERR_NONE,_Item,NULL);      // break spell
    return true;
}

/*#####
# item_razorthorn_flayer_gland
#####*/

bool ItemUse_item_razorthorn_flayer_gland(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 24922 )
        return false;

    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_tame_beast_rods
#####*/

bool ItemUse_item_tame_beast_rods(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    uint32 itemSpell = _Item->GetProto()->Spells[0].SpellId;
    uint32 cEntry = 0;

    if(itemSpell)
    {
        switch(itemSpell)
        {
            case 19548: cEntry =  1196; break;              //Ice Claw Bear
            case 19674: cEntry =  1126; break;              //Large Crag Boar
            case 19687: cEntry =  1201; break;              //Snow Leopard
            case 19688: cEntry =  2956; break;              //Adult Plainstrider
            case 19689: cEntry =  2959; break;              //Prairie Stalker
            case 19692: cEntry =  2970; break;              //Swoop
            case 19693: cEntry =  1998; break;              //Webwood Lurker
            case 19694: cEntry =  3099; break;              //Dire Mottled Boar
            case 19696: cEntry =  3107; break;              //Surf Crawler
            case 19697: cEntry =  3126; break;              //Armored Scorpid
            case 19699: cEntry =  2043; break;              //Nightsaber Stalker
            case 19700: cEntry =  1996; break;              //Strigid Screecher
            case 30646: cEntry = 17217; break;              //Barbed Crawler
            case 30653: cEntry = 17374; break;              //Greater Timberstrider
            case 30654: cEntry = 17203; break;              //Nightstalker
            case 30099: cEntry = 15650; break;              //Crazed Dragonhawk
            case 30102: cEntry = 15652; break;              //Elder Springpaw
            case 30105: cEntry = 16353; break;              //Mistbat
        }
        if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
            targets.getUnitTarget()->GetEntry() == cEntry )
            return false;
    }

    WorldPacket data(SMSG_CAST_FAILED, (4+2));              // prepare packet error message
    data << uint32(_Item->GetEntry());                      // itemId
    data << uint8(SPELL_FAILED_BAD_TARGETS);                // reason
    player->GetSession()->SendPacket(&data);                // send message: Invalid target

    player->SendEquipError(EQUIP_ERR_NONE,_Item,NULL);      // break spell
    return true;
}

/*#####
# item_protovoltaic_magneto_collector
#####*/

bool ItemUse_item_protovoltaic_magneto_collector(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 21729 )
        return false;

    player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,_Item,NULL);
    return true;
}

/*#####
# item_soul_cannon
#####*/

bool ItemUse_item_soul_cannon(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    // allow use
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 22357 )
        return false;

    // error
    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_sparrowhawk_net
#####*/

bool ItemUse_item_sparrowhawk_net(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 22979 )
        return false;

    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_voodoo_charm
#####*/

bool ItemUse_item_voodoo_charm(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT && targets.getUnitTarget()->isDead() &&
        targets.getUnitTarget()->GetEntry()==7318 )
        return false;

    WorldPacket data(SMSG_CAST_FAILED, (4+2));              // prepare packet error message
    data << uint32(_Item->GetEntry());                      // itemId
    data << uint8(SPELL_FAILED_BAD_TARGETS);                // reason
    player->GetSession()->SendPacket(&data);                // send message: Invalid target

    player->SendEquipError(EQUIP_ERR_NONE,_Item,NULL);      // break spell
    return true;
}

/*#####
# item_vorenthals_presence
#####*/

bool ItemUse_item_vorenthals_presence(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    // allow use
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 20132 )
        return false;

    // error
    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_yehkinyas_bramble
#####*/

bool ItemUse_item_yehkinyas_bramble(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if (player->GetQuestStatus(3520) == QUEST_STATUS_INCOMPLETE)
    {
        Unit * unit_target = targets.getUnitTarget();
        if( unit_target &&
            unit_target->GetTypeId()==TYPEID_UNIT &&
            unit_target->isDead() &&
                                                            // cast only on corpse 5307 or 5308
            (unit_target->GetEntry()==5307 || unit_target->GetEntry()==5308) )
        {
            CAST_CRE(unit_target)->RemoveCorpse();       // remove corpse for cancelling second use
            return false;                                   // all ok
        }
    }
    WorldPacket data(SMSG_CAST_FAILED, (4+2));              // prepare packet error message
    data << uint32(10699);                                  // itemId
    data << uint8(SPELL_FAILED_BAD_TARGETS);                // reason
    player->GetSession()->SendPacket(&data);                // send message: Bad target
    player->SendEquipError(EQUIP_ERR_NONE,_Item,NULL);      // break spell
    return true;
}

/*#####
# item_zezzak_shard
#####*/

bool ItemUse_item_zezzak_shard(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if( targets.getUnitTarget() && targets.getUnitTarget()->GetTypeId()==TYPEID_UNIT &&
        targets.getUnitTarget()->GetEntry() == 19440 )
        return false;

    player->SendEquipError(EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,_Item,NULL);
    return true;
}

/*#####
# item_incendiary_explosives
#####*/

bool ItemUse_item_incendiary_explosives(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    if ( player->FindNearestCreature(26248,15) || player->FindNearestCreature(26249,15) )
    {
        return false;
    }
    else
    {
        player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE,_Item,NULL);
        return true;
    }
}

void AddSC_item_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="item_area_52_special";
    newscript->pItemUse = &ItemUse_item_area_52_special;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_only_for_flight";
    newscript->pItemUse = &ItemUse_item_only_for_flight;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_attuned_crystal_cores";
    newscript->pItemUse = &ItemUse_item_attuned_crystal_cores;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_blackwhelp_net";
    newscript->pItemUse = &ItemUse_item_blackwhelp_net;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_dart_gun";
    newscript->pItemUse = &ItemUse_item_dart_gun;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_disciplinary_rod";
    newscript->pItemUse = &ItemUse_item_disciplinary_rod;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_draenei_fishing_net";
    newscript->pItemUse = &ItemUse_item_draenei_fishing_net;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_nether_wraith_beacon";
    newscript->pItemUse = &ItemUse_item_nether_wraith_beacon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_flying_machine";
    newscript->pItemUse = &ItemUse_item_flying_machine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_gor_dreks_ointment";
    newscript->pItemUse = &ItemUse_item_gor_dreks_ointment;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_muiseks_vessel";
    newscript->pItemUse = &ItemUse_item_muiseks_vessel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_inoculating_crystal";
    newscript->pItemUse = &ItemUse_item_inoculating_crystal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_razorthorn_flayer_gland";
    newscript->pItemUse = &ItemUse_item_razorthorn_flayer_gland;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_tame_beast_rods";
    newscript->pItemUse = &ItemUse_item_tame_beast_rods;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_protovoltaic_magneto_collector";
    newscript->pItemUse = &ItemUse_item_protovoltaic_magneto_collector;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_soul_cannon";
    newscript->pItemUse = &ItemUse_item_soul_cannon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_sparrowhawk_net";
    newscript->pItemUse = &ItemUse_item_sparrowhawk_net;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_voodoo_charm";
    newscript->pItemUse = &ItemUse_item_voodoo_charm;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_vorenthals_presence";
    newscript->pItemUse = &ItemUse_item_vorenthals_presence;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_yehkinyas_bramble";
    newscript->pItemUse = &ItemUse_item_yehkinyas_bramble;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_zezzaks_shard";
    newscript->pItemUse = &ItemUse_item_zezzak_shard;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="item_incendiary_explosives";
    newscript->pItemUse = &ItemUse_item_incendiary_explosives;
    newscript->RegisterSelf();
}

