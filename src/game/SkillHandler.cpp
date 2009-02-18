/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
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

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Opcodes.h"
#include "Log.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "UpdateMask.h"
#include "SpellAuras.h"

void WorldSession::HandleLearnTalentOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+4);

    uint32 talent_id, requested_rank;
    recv_data >> talent_id >> requested_rank;

    uint32 CurTalentPoints =  GetPlayer()->GetFreeTalentPoints();

    if(CurTalentPoints == 0)
        return;

    if (requested_rank > 4)
        return;

    TalentEntry const *talentInfo = sTalentStore.LookupEntry( talent_id );

    if(!talentInfo)
        return;

    TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry( talentInfo->TalentTab );

    if(!talentTabInfo)
        return;

    Player * player = GetPlayer();

    // prevent learn talent for different class (cheating)
    if( (player->getClassMask() & talentTabInfo->ClassMask) == 0 )
        return;

    // prevent skip talent ranks (cheating)
    if(requested_rank > 0 && !player->HasSpell(talentInfo->RankID[requested_rank-1]))
        return;

    // Check if it requires another talent
    if (talentInfo->DependsOn > 0)
    {
        if(TalentEntry const *depTalentInfo = sTalentStore.LookupEntry(talentInfo->DependsOn))
        {
            bool hasEnoughRank = false;
            for (int i = talentInfo->DependsOnRank; i <= 4; i++)
            {
                if (depTalentInfo->RankID[i] != 0)
                    if (player->HasSpell(depTalentInfo->RankID[i]))
                        hasEnoughRank = true;
            }
            if (!hasEnoughRank)
                return;
        }
    }

    // Check if it requires spell
    if( talentInfo->DependsOnSpell && !player->HasSpell(talentInfo->DependsOnSpell) )
        return;

    // Find out how many points we have in this field
    uint32 spentPoints = 0;

    uint32 tTab = talentInfo->TalentTab;
    if (talentInfo->Row > 0)
    {
        unsigned int numRows = sTalentStore.GetNumRows();
        for (unsigned int i = 0; i < numRows; i++)          // Loop through all talents.
        {
            // Someday, someone needs to revamp
            const TalentEntry *tmpTalent = sTalentStore.LookupEntry(i);
            if (tmpTalent)                                  // the way talents are tracked
            {
                if (tmpTalent->TalentTab == tTab)
                {
                    for (int j = 0; j <= 4; j++)
                    {
                        if (tmpTalent->RankID[j] != 0)
                        {
                            if (player->HasSpell(tmpTalent->RankID[j]))
                            {
                                spentPoints += j + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    // not have required min points spent in talent tree
    if(spentPoints < (talentInfo->Row * 5))
        return;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->RankID[requested_rank];
    if( spellid == 0 )
    {
        sLog.outError("Talent.dbc have for talent: %u Rank: %u spell id = 0", talent_id, requested_rank);
        return;
    }

    // already known
    if(GetPlayer( )->HasSpell(spellid))
        return;

    // learn! (other talent ranks will unlearned at learning)
    GetPlayer( )->learnSpell(spellid);
    sLog.outDetail("TalentID: %u Rank: %u Spell: %u\n", talent_id, requested_rank, spellid);

    // update free talent points
    GetPlayer()->SetFreeTalentPoints(CurTalentPoints - 1);
}

void WorldSession::HandleTalentWipeOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    sLog.outDetail("MSG_TALENT_WIPE_CONFIRM");
    uint64 guid;
    recv_data >> guid;

    Creature *unit = ObjectAccessor::GetNPCIfCanInteractWith(*_player, guid,UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleTalentWipeOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    if(!(_player->resetTalents()))
    {
        WorldPacket data( MSG_TALENT_WIPE_CONFIRM, 8+4);    //you have not any talent
        data << uint64(0);
        data << uint32(0);
        SendPacket( &data );
        return;
    }

    unit->CastSpell(_player, 14867, true);                  //spell: "Untalent Visual Effect"
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPacket & recv_data)
{
    CHECK_PACKET_SIZE(recv_data,4);

    uint32 skill_id;
    recv_data >> skill_id;
    GetPlayer()->SetSkill(skill_id, 0, 0);
}

