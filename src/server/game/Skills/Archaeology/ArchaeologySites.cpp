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

#include "Archaeology.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameObjectData.h"
#include "Language.h"
#include "Map.h"
#include "Player.h"
#include "Random.h"

// use squared distances so we don't have to use the squareroot
enum DigSiteDist
{
    DIST_FAR            = 10000,    // 100 yards
    DIST_MED            = 900,      // 30  yards
    DIST_CLOSE          = 100,      // 10  yards
};

enum SurveyBot
{
    FAR_SURVEYBOT       = 206590,
    MED_SURVEYBOT       = 206589,
    CLOSE_SURVEYBOT     = 204272,
};

void Archaeology::LoadSitesFromDB()
{
    QueryResult result = CharacterDatabase.PQuery("SELECT site, type, finds FROM character_archaeology_sites WHERE guid=%u", _player->GetGUID());

    if (!result)
        return;

    uint32 count = 0;
    do {
        Field *fields = result->Fetch();
        uint32 site = fields[0].GetUInt8();
        uint16 type = fields[1].GetUInt16();
        uint8 finds = fields[2].GetUInt8();
        SetSite(site, type, finds);
        count++;
    } while (result->NextRow());
}

void Archaeology::VerifySites()
{
    uint16 skillValue = _player->GetSkillValue(SKILL_ARCHAEOLOGY);

    if (skillValue >= SKILL_OUTLAND)
        _continentState[CONT_OUTLAND] = STATE_USE;
    else
        _continentState[CONT_OUTLAND] = STATE_NULL;

    if (skillValue >= SKILL_NORTHREND)
        _continentState[CONT_NORTHREND] = STATE_USE;
    else
        _continentState[CONT_NORTHREND] = STATE_NULL;

    if (skillValue >= SKILL_CATA)
    {
        _continentState[CONT_EASTERN] = STATE_EXT;
        _continentState[CONT_KALIMDOR] = STATE_EXT;
    }
    else
    {
        _continentState[CONT_EASTERN] = STATE_USE;
        _continentState[CONT_KALIMDOR] = STATE_USE;
    }

    RegenerateAllSites();
}

void Archaeology::UseSite()
{
    float dist;
    uint32 position = GetNearestSite(dist);

    if (0 == position)
        return;

    position--;

    if (dist > DIST_CLOSE)
    {
        uint32 surveyGoID;
        float angle = std::atan2(_site[position].Y - _player->GetPositionY(), _site[position].X - _player->GetPositionX());
        static float const pi = float(M_PI);

        if (dist < DIST_MED)
        {
            surveyGoID = CLOSE_SURVEYBOT;     // within the med radius -> green light
            angle += frand(-pi / 12.f, pi / 12.f);
        }
        else if (dist < DIST_FAR)
        {
            surveyGoID = MED_SURVEYBOT;       // within the far radius -> yellow light
            angle += frand(-pi / 6.f, pi / 6.f);
        }
        else
        {
            surveyGoID = FAR_SURVEYBOT;       // outside far radius -> red light
            angle += frand(-pi / 3.f, pi / 3.f);
        }

        float o      = _player->GetOrientation();
        float x      = _player->GetPositionX() + cos(o) * 2.0f;
        float y      = _player->GetPositionY() + sin(o) * 2.0f;
        float z      = _player->GetPositionZ();
        float ground = _player->GetMap()->GetWaterOrGroundLevel(_player->GetPhaseShift(), x, y, z, &ground, _player->IsInWater());

        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(angle, 0.f, 0.f);
        if (std::abs(z - ground) < 1.5f)
        {
            _player->SummonGameObject(surveyGoID, Position(x, y, ground, angle), rot, 4);
            return;
        }
        else
        {
            _player->GetSession()->SendNotification(LANG_YOU_CANT_USE_THAT_HERE);
            return;
        }
    }

    // Spawn the correct Find Object Here
    uint32 goId  = sArchaeologyMgr->GetSiteType(_site[position].Entry);
    float o      = _player->GetOrientation();
    float x      = _player->GetPositionX() + cos(o) * 2.0f;
    float y      = _player->GetPositionY() + sin(o) * 2.0f;
    float z      = _player->GetPositionZ();
    float ground = _player->GetMap()->GetWaterOrGroundLevel(_player->GetPhaseShift(), x, y, z, &ground, _player->IsInWater());

    // Spawn object
    _player->SummonGameObject(goId, Position(x, y, ground, o), QuaternionData(), 60);
    (_site[position].State)++;

    if (_site[position].State >= DIGS_PER_SITE)
        RegeneratePosition(position, GetContinent());
    else
    {
        CharacterDatabase.PExecute("UPDATE character_archaeology_sites SET finds = %u WHERE site= %u AND guid= %u", _site[position].State, position, _player->GetGUID());
        sArchaeologyMgr->SetSiteCoords(_site[position]);
    }
}

Continent Archaeology::GetContinent()
{
    switch (_player->GetMapId())
    {
        case 0:
            return CONT_EASTERN;
        case 1:
            return CONT_KALIMDOR;
        case 530:
            return CONT_OUTLAND;
        case 571:
            return CONT_NORTHREND;
    }
    return COUNT_CONT;
}

uint32 Archaeology::GetNearestSite(float &distance)
{
    uint32 cont = GetContinent();

    if (COUNT_CONT == cont)
        return 0;

    uint32 position = cont * CONTINENT_SITES;

    float pX = _player->GetPositionX();
    float pY = _player->GetPositionY();

    float distSq = (pX - _site[position].X) * (pX - _site[position].X) + (pY - _site[position].Y) * (pY - _site[position].Y);

    for (uint32 i = cont * CONTINENT_SITES + 1; i < (cont + 1) * CONTINENT_SITES; ++i)
    {
        float distSq2 = (pX -_site[i].X) * (pX -_site[i].X) + (pY - _site[i].Y) * (pY - _site[i].Y);
        if (distSq2 < distSq)
        {
            position = i;
            distSq = distSq2;
        }
    }
    distance = distSq;

    return position + 1;
}

void Archaeology::SetSite(uint32 position, uint16 entry, uint32 state)
{
    _site[position].Entry = entry;
    _site[position].State = state;
    _player->SetUInt16Value(PLAYER_FIELD_RESEARCH_SITE_1 + (position / 2), position % 2, entry);

    if (entry == 0)
    {
        _site[position].X = 0.f;
        _site[position].Y = 0.f;
    }
    else
        sArchaeologyMgr->SetSiteCoords(_site[position]);
}

void Archaeology::RegeneratePosition(uint32 position, Continent continent)
{
    if (_site[position].Entry && sResearchSiteStore.LookupEntry(_site[position].Entry) && _site[position].State < DIGS_PER_SITE)
        return;

    uint16 entry = sArchaeologyMgr->GetNewSite(continent, _site, _continentState[continent] == STATE_EXT, _player->getLevel());
    SetSite(position, entry);
    CharacterDatabase.PExecute("REPLACE INTO character_archaeology_sites values (%u, %u, %u, %u);", _player->GetGUID(), position, entry, _site[position].State);
}

void Archaeology::RegenerateContinent(Continent continent)
{
    if (_continentState[continent] == STATE_NULL)
    {
        uint32 position = continent * CONTINENT_SITES;

        for (int i = 0; i < CONTINENT_SITES; i++)
            SetSite(position + i, 0);
        return;
    }

    uint32 position = continent * CONTINENT_SITES;

    for (uint32 i = 0; i < CONTINENT_SITES; i++)
        RegeneratePosition(position + i, continent);
}

void Archaeology::RegenerateAllSites()
{
    for (uint32 i = 0; i < COUNT_CONT; i++)
        RegenerateContinent(Continent(i));
}

