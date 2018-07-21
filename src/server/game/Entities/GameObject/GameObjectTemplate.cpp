/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "GameObjectTemplate.h"
#include "GameObjectData.h"
#include "QueryPackets.h"
#include "ObjectMgr.h"

void GameObjectTemplate::InitializeQueryData()
{
    for (uint8 lc = LOCALE_enUS; lc < TOTAL_LOCALES; ++lc)
    {
        _response[lc] = new WorldPackets::Query::QueryGameObjectResponse();
        BuildQueryData(static_cast<LocaleConstant>(lc));
        _response[lc]->Write();
    }
}

void GameObjectTemplate::InitializeQueryData(LocaleConstant lc)
{
    _response[lc] = new WorldPackets::Query::QueryGameObjectResponse();
    BuildQueryData(lc);
    _response[lc]->Write();
}

WorldPacket* GameObjectTemplate::GetQueryDataRef(LocaleConstant lc)
{
    if (!_response[lc])
    {
        GetQueryData(lc);
    }
    return (WorldPacket*)_response[lc]->GetRawPacket();
}

WorldPacket GameObjectTemplate::GetQueryData(LocaleConstant lc)
{
    if (!_response[lc])
    {
        _response[lc] = new WorldPackets::Query::QueryGameObjectResponse();
        BuildQueryData(lc);
    }
    const WorldPacket* wp = _response[lc]->Write();
    return *wp;
}

void GameObjectTemplate::BuildQueryData(LocaleConstant lc) const
{
    if (lc == LOCALE_enUS)
    {
        _response[lc]->Stats.Name = name;
        _response[lc]->Stats.IconName = IconName;
        _response[lc]->Stats.CastBarCaption = castBarCaption;
    }
    if (GameObjectLocale const* gameObjectLocale = sObjectMgr->GetGameObjectLocale(entry))
    {
        ObjectMgr::GetLocaleString(gameObjectLocale->Name, lc, _response[lc]->Stats.Name);
        ObjectMgr::GetLocaleString(gameObjectLocale->CastBarCaption, lc, _response[lc]->Stats.CastBarCaption);
    }

    _response[lc]->GameObjectID = entry;
    _response[lc]->Allow = true;

    _response[lc]->Stats.Type = type;
    _response[lc]->Stats.DisplayID = displayId;
    _response[lc]->Stats.UnkString = unk1;
    memcpy(_response[lc]->Stats.Data, raw.data, sizeof(uint32) * MAX_GAMEOBJECT_DATA);
    _response[lc]->Stats.Size = size;

    for (uint32 i = 0; i < MAX_GAMEOBJECT_QUEST_ITEMS; ++i)
        _response[lc]->Stats.QuestItems[i] = 0;

    if (std::vector<uint32> const* items = sObjectMgr->GetGameObjectQuestItemList(entry))
        for (uint32 i = 0; i < MAX_GAMEOBJECT_QUEST_ITEMS; ++i)
            if (i < items->size())
                _response[lc]->Stats.QuestItems[i] = (*items)[i];
}
