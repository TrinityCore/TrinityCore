/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "DBCStores.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Spell.h"
#include "ScriptCalls.h"
#include "Totem.h"
#include "TemporarySummon.h"
#include "SpellAuras.h"

void WorldSession::HandleUseItemOpcode(WorldPacket& recvPacket)
{
    // TODO: add targets.read() check
    CHECK_PACKET_SIZE(recvPacket,1+1+1+4+8+4+1);

    Player* pUser = _player;

    // ignore for remote control state
    if(pUser->m_mover != pUser)
        return;

    uint8 bagIndex, slot;
    uint8 unk_flags;                                        // flags (if 0x02 - some additional data are received)
    uint8 cast_count;                                       // next cast if exists (single or not)
    uint64 item_guid;
    uint32 glyphIndex;                                      // something to do with glyphs?
    uint32 spellid;                                         // casted spell id

    recvPacket >> bagIndex >> slot >> cast_count >> spellid >> item_guid >> glyphIndex >> unk_flags;

    Item *pItem = pUser->GetUseableItemByPos(bagIndex, slot);
    if(!pItem)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL );
        return;
    }

    if(pItem->GetGUID() != item_guid)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL );
        return;
    }

    sLog.outDetail("WORLD: CMSG_USE_ITEM packet, bagIndex: %u, slot: %u, cast_count: %u, spellid: %u, Item: %u, glyphIndex: %u, unk_flags: %u, data length = %i", bagIndex, slot, cast_count, spellid, pItem->GetEntry(), glyphIndex, unk_flags, (uint32)recvPacket.size());

    ItemPrototype const *proto = pItem->GetProto();
    if(!proto)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pItem, NULL );
        return;
    }

    // some item classes can be used only in equipped state
    if(proto->InventoryType != INVTYPE_NON_EQUIP && !pItem->IsEquipped())
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pItem, NULL );
        return;
    }

    uint8 msg = pUser->CanUseItem(pItem);
    if( msg != EQUIP_ERR_OK )
    {
        pUser->SendEquipError( msg, pItem, NULL );
        return;
    }

    // only allow conjured consumable, bandage, poisons (all should have the 2^21 item flag set in DB)
    if( proto->Class == ITEM_CLASS_CONSUMABLE &&
        !(proto->Flags & ITEM_FLAGS_USEABLE_IN_ARENA) &&
        pUser->InArena())
    {
        pUser->SendEquipError(EQUIP_ERR_NOT_DURING_ARENA_MATCH,pItem,NULL);
        return;
    }

    if (pUser->isInCombat())
    {
        for(int i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        {
            if (SpellEntry const *spellInfo = sSpellStore.LookupEntry(proto->Spells[i].SpellId))
            {
                if (IsNonCombatSpell(spellInfo))
                {
                    pUser->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT,pItem,NULL);
                    return;
                }
            }
        }
    }

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if( pItem->GetProto()->Bonding == BIND_WHEN_USE || pItem->GetProto()->Bonding == BIND_WHEN_PICKED_UP || pItem->GetProto()->Bonding == BIND_QUEST_ITEM )
    {
        if (!pItem->IsSoulBound())
        {
            pItem->SetState(ITEM_CHANGED, pUser);
            pItem->SetBinding( true );
        }
    }

    SpellCastTargets targets;
    if(!targets.read(&recvPacket, pUser))
        return;

    //Note: If script stop casting it must send appropriate data to client to prevent stuck item in gray state.
    if(!Script->ItemUse(pUser,pItem,targets))
    {
        // no script or script not process request by self
        pUser->CastItemUseSpell(pItem,targets,cast_count,glyphIndex);
    }
}

#define OPEN_CHEST 11437
#define OPEN_SAFE 11535
#define OPEN_CAGE 11792
#define OPEN_BOOTY_CHEST 5107
#define OPEN_STRONGBOX 8517

void WorldSession::HandleOpenItemOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,1+1);

    sLog.outDetail("WORLD: CMSG_OPEN_ITEM packet, data length = %i",(uint32)recvPacket.size());

    Player* pUser = _player;

    // ignore for remote control state
    if(pUser->m_mover != pUser)
        return;

    uint8 bagIndex, slot;

    recvPacket >> bagIndex >> slot;

    sLog.outDetail("bagIndex: %u, slot: %u",bagIndex,slot);

    Item *pItem = pUser->GetItemByPos(bagIndex, slot);
    if(!pItem)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL );
        return;
    }

    ItemPrototype const *proto = pItem->GetProto();
    if(!proto)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pItem, NULL );
        return;
    }

    // locked item
    uint32 lockId = proto->LockID;
    if(lockId)
    {
        LockEntry const *lockInfo = sLockStore.LookupEntry(lockId);

        if (!lockInfo)
        {
            pUser->SendEquipError(EQUIP_ERR_ITEM_LOCKED, pItem, NULL );
            sLog.outError( "WORLD::OpenItem: item [guid = %u] has an unknown lockId: %u!", pItem->GetGUIDLow() , lockId);
            return;
        }

        // required picklocking
        if(lockInfo->Skill[1] || lockInfo->Skill[0])
        {
            pUser->SendEquipError(EQUIP_ERR_ITEM_LOCKED, pItem, NULL );
            return;
        }
    }

    if(pItem->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAGS_WRAPPED))// wrapped?
    {
        QueryResult *result = CharacterDatabase.PQuery("SELECT entry, flags FROM character_gifts WHERE item_guid = '%u'", pItem->GetGUIDLow());
        if (result)
        {
            Field *fields = result->Fetch();
            uint32 entry = fields[0].GetUInt32();
            uint32 flags = fields[1].GetUInt32();

            pItem->SetUInt64Value(ITEM_FIELD_GIFTCREATOR, 0);
            pItem->SetEntry(entry);
            pItem->SetUInt32Value(ITEM_FIELD_FLAGS, flags);
            pItem->SetState(ITEM_CHANGED, pUser);
            delete result;
        }
        else
        {
            sLog.outError("Wrapped item %u don't have record in character_gifts table and will deleted", pItem->GetGUIDLow());
            pUser->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
            return;
        }
        CharacterDatabase.PExecute("DELETE FROM character_gifts WHERE item_guid = '%u'", pItem->GetGUIDLow());
    }
    else
        pUser->SendLoot(pItem->GetGUID(),LOOT_CORPSE);
}

void WorldSession::HandleGameObjectUseOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;

    recv_data >> guid;

    sLog.outDebug( "WORLD: Recvd CMSG_GAMEOBJ_USE Message [guid=%u]", GUID_LOPART(guid));

    // ignore for remote control state
    if(_player->m_mover != _player)
        return;

    GameObject *obj = GetPlayer()->GetMap()->GetGameObject(guid);

    if(!obj)
        return;

    if (Script->GOHello(_player, obj))
        return;

    obj->Use(_player);
}

void WorldSession::HandleGameobjectReportUse(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,8);

    uint64 guid;
    recvPacket >> guid;

    sLog.outDebug( "WORLD: Recvd CMSG_GAMEOBJ_REPORT_USE Message [in game guid: %u]", GUID_LOPART(guid));

    // ignore for remote control state
    if(_player->m_mover != _player)
        return;

    GameObject* go = GetPlayer()->GetMap()->GetGameObject(guid);
    if(!go)
        return;

    if(!go->IsWithinDistInMap(_player,INTERACTION_DISTANCE))
        return;

    _player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT, go->GetEntry());
}

void WorldSession::HandleCastSpellOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,1+4+1);

    uint32 spellId;
    uint8  cast_count, unk_flags;
    recvPacket >> cast_count;
    recvPacket >> spellId;
    recvPacket >> unk_flags;                                // flags (if 0x02 - some additional data are received)

    // ignore for remote control state (for player case)
    Unit* mover = _player->m_mover;
    if(mover != _player && mover->GetTypeId()==TYPEID_PLAYER)
        return;

    sLog.outDebug("WORLD: got cast spell packet, spellId - %u, cast_count: %u, unk_flags %u, data length = %i",
        spellId, cast_count, unk_flags, (uint32)recvPacket.size());

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );

    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown spell id %u", spellId);
        return;
    }

    if(mover->GetTypeId()==TYPEID_PLAYER)
    {
        // not have spell in spellbook or spell passive and not casted by client
        if (!((Player*)mover)->HasActiveSpell (spellId) || IsPassiveSpell(spellId) )
        {
            //cheater? kick? ban?
            return;
        }
    }
    else
    {
        // not have spell in spellbook or spell passive and not casted by client
        if (!((Creature*)mover)->HasSpell(spellId) || IsPassiveSpell(spellId) )
        {
            //cheater? kick? ban?
            return;
        }
    }

    // can't use our own spells when we're in possession of another unit,
    if(_player->isPossessing())
        return;

    // client provided targets
    SpellCastTargets targets;
    if(!targets.read(&recvPacket,mover))
        return;

    // auto-selection buff level base at target level (in spellInfo)
    if(targets.getUnitTarget())
    {
        SpellEntry const *actualSpellInfo = spellmgr.SelectAuraRankForPlayerLevel(spellInfo,targets.getUnitTarget()->getLevel());

        // if rank not found then function return NULL but in explicit cast case original spell can be casted and later failed with appropriate error message
        if(actualSpellInfo)
            spellInfo = actualSpellInfo;
    }

    Spell *spell = new Spell(mover, spellInfo, false);
    spell->m_cast_count = cast_count;                       // set count of casts
    spell->prepare(&targets);
}

void WorldSession::HandleCancelCastOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,5);

    // increments with every CANCEL packet, don't use for now
    uint8 counter;
    uint32 spellId;
    recvPacket >> counter;
    recvPacket >> spellId;

    if(_player->IsNonMeleeSpellCasted(false))
        _player->InterruptNonMeleeSpells(false,spellId,false);
}

void WorldSession::HandleCancelAuraOpcode( WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,4);

    uint32 spellId;
    recvPacket >> spellId;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
        return;

    // not allow remove non positive spells and spells with attr SPELL_ATTR_CANT_CANCEL
    if(!IsPositiveSpell(spellId) || (spellInfo->Attributes & SPELL_ATTR_CANT_CANCEL))
        return;

    // channeled spell case (it currently casted then)
    if (IsChanneledSpell(spellInfo))
    {
        if (_player->m_currentSpells[CURRENT_CHANNELED_SPELL] &&
            _player->m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->Id==spellId)
            _player->InterruptSpell(CURRENT_CHANNELED_SPELL);
        return;
    }

    // non channeled case
    // maybe should only remove one buff when there are multiple?
    _player->RemoveAurasDueToSpell(spellId, 0, AURA_REMOVE_BY_CANCEL);
}

void WorldSession::HandlePetCancelAuraOpcode( WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 8+4);

    uint64 guid;
    uint32 spellId;

    recvPacket >> guid;
    recvPacket >> spellId;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );
    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown PET spell id %u", spellId);
        return;
    }

    Creature* pet=ObjectAccessor::GetCreatureOrPetOrVehicle(*_player,guid);

    if(!pet)
    {
        sLog.outError( "Pet %u not exist.", uint32(GUID_LOPART(guid)) );
        return;
    }

    if(pet != GetPlayer()->GetGuardianPet() && pet != GetPlayer()->GetCharm())
    {
        sLog.outError( "HandlePetCancelAura.Pet %u isn't pet of player %s", uint32(GUID_LOPART(guid)),GetPlayer()->GetName() );
        return;
    }

    if(!pet->isAlive())
    {
        pet->SendPetActionFeedback(FEEDBACK_PET_DEAD);
        return;
    }

    pet->RemoveAurasDueToSpell(spellId);

    pet->AddCreatureSpellCooldown(spellId);
}

void WorldSession::HandleCancelGrowthAuraOpcode( WorldPacket& /*recvPacket*/)
{
    // nothing do
}

void WorldSession::HandleCancelAutoRepeatSpellOpcode( WorldPacket& /*recvPacket*/)
{
    // may be better send SMSG_CANCEL_AUTO_REPEAT?
    // cancel and prepare for deleting
    _player->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
}

/// \todo Complete HandleCancelChanneling function
void WorldSession::HandleCancelChanneling( WorldPacket & /*recv_data */)
{
    /*
        CHECK_PACKET_SIZE(recv_data, 4);

        uint32 spellid;
        recv_data >> spellid;
    */
}

void WorldSession::HandleTotemDestroyed( WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    // ignore for remote control state
    if(_player->m_mover != _player)
        return;

    uint8 slotId;

    recvPacket >> slotId;

    ++slotId;
    if (slotId >= MAX_TOTEM_SLOT)
        return;

    if(!_player->m_SummonSlot[slotId])
        return;

    Creature* totem = GetPlayer()->GetMap()->GetCreature(_player->m_SummonSlot[slotId]);
    // Don't unsummon sentry totem
    if(totem && totem->isTotem() && totem->GetEntry() != SENTRY_TOTEM_ENTRY)
        ((Totem*)totem)->UnSummon();
}

void WorldSession::HandleSelfResOpcode( WorldPacket & /*recv_data*/ )
{
    sLog.outDebug("WORLD: CMSG_SELF_RES");                  // empty opcode

    if(_player->GetUInt32Value(PLAYER_SELF_RES_SPELL))
    {
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(_player->GetUInt32Value(PLAYER_SELF_RES_SPELL));
        if(spellInfo)
            _player->CastSpell(_player,spellInfo,false,0);

        _player->SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);
    }
}

void WorldSession::HandleSpellClick( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;
    recv_data >> guid;

    Creature *unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if(!unit)
        return;

    SpellClickInfoMap const& map = objmgr.mSpellClickInfoMap;
    for(SpellClickInfoMap::const_iterator itr = map.lower_bound(unit->GetEntry()); itr != map.upper_bound(unit->GetEntry()); ++itr)
    {
        if(itr->second.questId == 0 || _player->GetQuestStatus(itr->second.questId) == itr->second.questStatus)
        {
            Unit *caster = (itr->second.castFlags & 0x1) ? (Unit*)_player : (Unit*)unit;
            Unit *target = (itr->second.castFlags & 0x2) ? (Unit*)_player : (Unit*)unit;

            caster->CastSpell(target, itr->second.spellId, true);
        }
    }

    if(unit->isVehicle())
        _player->EnterVehicle((Vehicle*)unit);
}
