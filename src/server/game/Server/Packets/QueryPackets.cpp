/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "QueryPackets.h"
#include "Player.h"
#include "World.h"

void WorldPackets::Query::QueryPlayerName::Read()
{
    _worldPacket >> Player;
}

bool WorldPackets::Query::PlayerGuidLookupData::Initialize(ObjectGuid const& guid, Player const* player /*= nullptr*/)
{
    CharacterNameData const* nameData = sWorld->GetCharacterNameData(guid);
    if (!nameData)
        return false;

    if (player)
    {
        ASSERT(player->GetGUID() == guid);
        Name = player->GetName();
        Race = player->getRace();
        Sex = player->getGender();
        Class = player->getClass();
        Level = player->getLevel();

        if (DeclinedName const* names = player->GetDeclinedNames())
            DeclinedNames = names;
    }
    else
    {
        Name = nameData->m_name;
        Race = nameData->m_race;
        Sex = nameData->m_gender;
        Class = nameData->m_class;
        Level = nameData->m_level;
    }

    VirtualRealmAddress = 0;

    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupData const& lookupData)
{
    data << lookupData.Name;
    data << uint8(lookupData.VirtualRealmAddress);
    data << uint8(lookupData.Race);
    data << uint8(lookupData.Sex);
    data << uint8(lookupData.Class);

    if (lookupData.DeclinedNames)
    {
        data << uint8(1);                           // Name is declined
        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << lookupData.DeclinedNames->name[i];
    }
    else
        data << uint8(0);                           // Name is not declined

    return data;
}

WorldPacket const* WorldPackets::Query::QueryPlayerNameResponse::Write()
{
    _worldPacket << Player.WriteAsPacked();
    _worldPacket << uint8(Result);

    if (Result == RESPONSE_SUCCESS)
        _worldPacket << Data;

    return &_worldPacket;
}

void WorldPackets::Query::QueryPetName::Read()
{
    _worldPacket >> Number;
    _worldPacket >> Pet;
}

WorldPacket const* WorldPackets::Query::QueryPetNameResponse::Write()
{
    _worldPacket << uint32(Number);
    _worldPacket << Name;
    _worldPacket << uint32(Timestamp);

    if (DeclinedNames)
    {
        _worldPacket << uint8(1);
        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket << DeclinedNames->name[i];
    }
    else
        _worldPacket << uint8(0);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::QueryTimeResponse::Write()
{
    _worldPacket << uint32(CurrentTime);
    _worldPacket << uint32(TimeOutRequest);

    return &_worldPacket;
}

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << uint32(Stats ? CreatureID : CreatureID | 0x80000000);  // creature entry

    if (Stats)
    {
        _worldPacket << Stats->Name;
        _worldPacket << uint8(0) << uint8(0) << uint8(0);                   // name2, name3, name4, always empty
        _worldPacket << Stats->NameAlt;
        _worldPacket << Stats->CursorName;                                  // "Directions" for guard, string for Icons 2.3.0
        _worldPacket << uint32(Stats->Flags);                               // flags
        _worldPacket << uint32(Stats->CreatureType);                        // CreatureType.dbc
        _worldPacket << uint32(Stats->CreatureFamily);                      // CreatureFamily.dbc
        _worldPacket << uint32(Stats->Classification);                      // Creature Rank (elite, boss, etc)
        _worldPacket.append(Stats->ProxyCreatureID, MAX_KILL_CREDIT);       // new in 3.1, kill credit
        _worldPacket.append(Stats->CreatureDisplayID, MAX_CREATURE_MODELS); // Modelid
        _worldPacket << float(Stats->HpMulti);                              // dmg/hp modifier
        _worldPacket << float(Stats->EnergyMulti);                          // dmg/mana modifier
        _worldPacket << uint8(Stats->Leader);
        _worldPacket.append(Stats->QuestItems, MAX_CREATURE_QUEST_ITEMS);   // itemId[6], quest drop
        _worldPacket << uint32(Stats->CreatureMovementInfoID);              // CreatureMovementInfo.dbc
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryGameObject::Read()
{
    _worldPacket >> GameObjectID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryGameObjectResponse::Write()
{
    _worldPacket << uint32(Stats ? GameObjectID : GameObjectID | 0x80000000);

    if (Stats)
    {
        _worldPacket << uint32(Stats->Type);
        _worldPacket << uint32(Stats->DisplayID);
        _worldPacket << Stats->Name;
        _worldPacket << uint8(0) << uint8(0) << uint8(0);                   // name2, name3, name4
        _worldPacket << Stats->IconName;                                    // 2.0.3, string. Icon name to use instead of default icon for go's (ex: "Attack" makes sword)
        _worldPacket << Stats->CastBarCaption;                              // 2.0.3, string. Text will appear in Cast Bar when using GO (ex: "Collecting")
        _worldPacket << Stats->UnkString;                                   // 2.0.3, string
        _worldPacket.append(Stats->Data, MAX_GAMEOBJECT_DATA);
        _worldPacket << float(Stats->Size);                                 // go size
        _worldPacket.append(Stats->QuestItems, MAX_GAMEOBJECT_QUEST_ITEMS); // itemId[6], quest drop
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::QueryCorpseLocationResponse::Write()
{
    _worldPacket << uint8(Location ? 1 : 0);

    if (Location)
    {
        _worldPacket << int32(Location->MapID);
        _worldPacket << Location->Position;
        _worldPacket << int32(Location->ActualMapID);
        _worldPacket << uint32(0);                                      // unknown
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::QueryCorpseMapPositionResponse::Write()
{
    _worldPacket << float(0)
                 << float(0)
                 << float(0)
                 << float(0);

    return &_worldPacket;
}

void WorldPackets::Query::QueryNPCText::Read()
{
    _worldPacket >> TextID;
    _worldPacket >> Guid;
}

std::string const WorldPackets::Query::QueryNPCTextResponse::DefaultGossip  = "Greetings $N";

WorldPacket const* WorldPackets::Query::QueryNPCTextResponse::Write()
{
    _worldPacket << uint32(TextID);

    for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
    {
        if (Allow)
        {
            _worldPacket << float(Probabilities[i]);
            if (Texts[0][i].empty())
                _worldPacket << Texts[1][i];
            else
                _worldPacket << Texts[0][i];

            if (Texts[1][i].empty())
                _worldPacket << Texts[0][i];
            else
                _worldPacket << Texts[1][i];

            _worldPacket << uint32(Languages[i]);
            for (uint8 j = 0; j < MAX_GOSSIP_TEXT_EMOTES; ++j)
            {
                _worldPacket << uint32(Emotes[i][j]._Delay);
                _worldPacket << uint32(Emotes[i][j]._Emote);
            }
        }
        else
        {
            _worldPacket << float(0);
            _worldPacket << DefaultGossip;
            _worldPacket << DefaultGossip;
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
            _worldPacket << uint32(0);
        }
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryPageText::Read()
{
    _worldPacket >> PageID;
    _worldPacket >> Guid;
}

std::string const WorldPackets::Query::QueryPageTextResponse::MissingText = "Item page missing.";

WorldPacket const* WorldPackets::Query::QueryPageTextResponse::Write()
{
    _worldPacket << uint32(Page.ID);
    
    if (Allow)
    {
        _worldPacket << Page.Text;
        _worldPacket << uint32(Page.NextPageID);
    }
    else
    {
        _worldPacket << MissingText;
        _worldPacket << uint32(0);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QuestPOIQuery::Read()
{
    _worldPacket >> MissingQuestCount; // quest count, max=25

    if (MissingQuestCount <= MAX_QUEST_LOG_SIZE)
    {
        for (uint8 i = 0; i < MissingQuestCount; ++i)
            _worldPacket >> MissingQuestPOIs[i];
    }

    _worldPacket.rfinish();
}

WorldPacket const* WorldPackets::Query::QuestPOIQueryResponse::Write()
{
    _worldPacket << uint32(QuestPOIDataStats.size());

    for (QuestPOIData const& questPOIData : QuestPOIDataStats)
    {
        _worldPacket << uint32(questPOIData.QuestID); // quest ID
        _worldPacket << uint32(questPOIData.QuestPOIBlobDataStats.size()); // POI count

        for (QuestPOIBlobData const& questPOIBlobData : questPOIData.QuestPOIBlobDataStats)
        {
            _worldPacket << uint32(questPOIBlobData.BlobIndex);                     // POI index
            _worldPacket << int32(questPOIBlobData.ObjectiveIndex);                 // objective index
            _worldPacket << uint32(questPOIBlobData.MapID);                         // mapid
            _worldPacket << uint32(questPOIBlobData.WorldMapAreaID);                // areaid
            _worldPacket << uint32(questPOIBlobData.Floor);                         // floorid
            _worldPacket << uint32(questPOIBlobData.Unk3);                          // unknown
            _worldPacket << uint32(questPOIBlobData.Unk4);                          // unknown
            _worldPacket << uint32(questPOIBlobData.QuestPOIBlobPointStats.size()); // POI points count

            for (QuestPOIBlobPoint const& questPOIBlobPoint : questPOIBlobData.QuestPOIBlobPointStats)
            {
                _worldPacket << int32(questPOIBlobPoint.X); // POI point x
                _worldPacket << int32(questPOIBlobPoint.Y); // POI point y
            }
        }
    }

    return &_worldPacket;
}
