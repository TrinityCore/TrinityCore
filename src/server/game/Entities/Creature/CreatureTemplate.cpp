/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "CreatureTemplate.h"
#include "Common.h"
#include "ObjectMgr.h"
#include "QueryPackets.h"
#include "Random.h"

uint32 CreatureTemplate::GetRandomValidModelId() const
{
	uint8 c = 0;
	uint32 modelIDs[4];

	if (Modelid1) modelIDs[c++] = Modelid1;
	if (Modelid2) modelIDs[c++] = Modelid2;
	if (Modelid3) modelIDs[c++] = Modelid3;
	if (Modelid4) modelIDs[c++] = Modelid4;

	return ((c>0) ? modelIDs[urand(0, c - 1)] : 0);
}

uint32 CreatureTemplate::GetFirstValidModelId() const
{
	if (Modelid1) return Modelid1;
	if (Modelid2) return Modelid2;
	if (Modelid3) return Modelid3;
	if (Modelid4) return Modelid4;
	return 0;
}

uint32 CreatureTemplate::GetFirstInvisibleModel() const
{
	CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid1);
	if (modelInfo && modelInfo->is_trigger)
		return Modelid1;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid2);
	if (modelInfo && modelInfo->is_trigger)
		return Modelid2;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid3);
	if (modelInfo && modelInfo->is_trigger)
		return Modelid3;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid4);
	if (modelInfo && modelInfo->is_trigger)
		return Modelid4;

	return 11686;
}

uint32 CreatureTemplate::GetFirstVisibleModel() const
{
	CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid1);
	if (modelInfo && !modelInfo->is_trigger)
		return Modelid1;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid2);
	if (modelInfo && !modelInfo->is_trigger)
		return Modelid2;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid3);
	if (modelInfo && !modelInfo->is_trigger)
		return Modelid3;

	modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid4);
	if (modelInfo && !modelInfo->is_trigger)
		return Modelid4;

	return 17519;
}

void CreatureTemplate::InitializeQueryData()
{
    for (uint8 lc = LOCALE_enUS; lc < TOTAL_LOCALES; ++lc)
    {
        _response[lc] = new WorldPackets::Query::QueryCreatureResponse();
        BuildQueryData(static_cast<LocaleConstant>(lc));
        _response[lc]->Write();
    }
}

void CreatureTemplate::InitializeQueryData(LocaleConstant lc)
{
	_response[lc] = new WorldPackets::Query::QueryCreatureResponse();
	BuildQueryData(lc);
	_response[lc]->Write();
}

WorldPacket* CreatureTemplate::GetQueryDataRef(LocaleConstant lc)
{
	if (!_response[lc])
	{
		GetQueryData(lc);
	}
	return (WorldPacket*)_response[lc]->GetRawPacket();
}

WorldPacket CreatureTemplate::GetQueryData(LocaleConstant lc)
{
	if (!_response[lc])
	{
		_response[lc] = new WorldPackets::Query::QueryCreatureResponse();
		BuildQueryData(lc);
	}
	const WorldPacket* wp = _response[lc]->Write();
	return *wp;
}

void CreatureTemplate::BuildQueryData(LocaleConstant lc) const
{
    if (lc == LOCALE_enUS)
    {
        _response[lc]->Stats.Name = Name;
        _response[lc]->Stats.NameAlt = Title;
    }
    else if (CreatureLocale const* cl = sObjectMgr->GetCreatureLocale(Entry))
    {
        ObjectMgr::GetLocaleString(cl->Name, lc, _response[lc]->Stats.Name);
        ObjectMgr::GetLocaleString(cl->Title, lc, _response[lc]->Stats.NameAlt);
    }

	_response[lc]->CreatureID = Entry;
	_response[lc]->Allow = true;

	_response[lc]->Stats.CursorName = IconName;
	_response[lc]->Stats.Flags = type_flags;
	_response[lc]->Stats.CreatureType = type;
	_response[lc]->Stats.CreatureFamily = family;
	_response[lc]->Stats.Classification = rank;
	memcpy(_response[lc]->Stats.ProxyCreatureID, KillCredit, sizeof(uint32) * MAX_KILL_CREDIT);
	_response[lc]->Stats.CreatureDisplayID[0] = Modelid1;
	_response[lc]->Stats.CreatureDisplayID[1] = Modelid2;
	_response[lc]->Stats.CreatureDisplayID[2] = Modelid3;
	_response[lc]->Stats.CreatureDisplayID[3] = Modelid4;
	_response[lc]->Stats.HpMulti = ModHealth;
	_response[lc]->Stats.EnergyMulti = ModMana;
	_response[lc]->Stats.Leader = RacialLeader;

	for (uint32 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
		_response[lc]->Stats.QuestItems[i] = 0;

	if (std::vector<uint32> const* items = sObjectMgr->GetCreatureQuestItemList(Entry))
		for (uint32 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
			if (i < items->size())
				_response[lc]->Stats.QuestItems[i] = (*items)[i];

	_response[lc]->Stats.CreatureMovementInfoID = movementId;
}
