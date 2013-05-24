/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "Player.h"
#include "halls_of_reflection.h"

const Position JainaSpawnPos                = {5236.659f, 1929.894f, 707.7781f, 0.8726646f}; // Jaina Spawn Position
const Position SylvanasSpawnPos             = {5236.667f, 1929.906f, 707.7781f, 0.8377581f}; // Sylvanas Spawn Position
const Position GeneralSpawnPos              = {5415.538f, 2117.842f, 707.7781f, 3.944444f}; // Frostsworn General

static Position SpawnPos[] =
{
    {5309.577f, 2042.668f, 707.7781f, 4.694936f},
    {5295.885f, 2040.342f, 707.7781f, 5.078908f},
    {5340.836f, 1992.458f, 707.7781f, 2.757620f},
    {5325.072f, 1977.597f, 707.7781f, 2.076942f},
    {5277.365f, 1993.229f, 707.7781f, 0.401426f},
    {5275.479f, 2001.135f, 707.7781f, 0.174533f},
    {5302.448f, 2042.222f, 707.7781f, 4.904375f},
    {5343.293f, 1999.384f, 707.7781f, 2.914700f},
    {5295.635f, 1973.757f, 707.7781f, 1.186824f},
    {5311.031f, 1972.229f, 707.7781f, 1.640610f},
    {5275.076f, 2008.724f, 707.7781f, 6.213372f},
    {5316.701f, 2041.550f, 707.7781f, 4.502949f},
    {5344.150f, 2007.168f, 707.7781f, 3.159046f},
    {5319.158f, 1973.998f, 707.7781f, 1.919862f},
    {5302.247f, 1972.415f, 707.7781f, 1.378810f},
    {5277.739f, 2016.882f, 707.7781f, 5.969026f},
    {5322.964f, 2040.288f, 707.7781f, 4.345870f},
    {5343.467f, 2015.951f, 707.7781f, 3.490659f},
    {5313.820f, 1978.146f, 707.7781f, 1.745329f},
    {5279.649f, 2004.656f, 707.7781f, 0.069814f},
    {5306.057f, 2037.002f, 707.7781f, 4.817109f},
    {5337.865f, 2003.403f, 707.7781f, 2.984513f},
    {5299.434f, 1979.009f, 707.7781f, 1.239184f},
    {5312.752f, 2037.122f, 707.7781f, 4.590216f},
    {5335.724f, 1996.859f, 707.7781f, 2.740167f},
    {5280.632f, 2012.156f, 707.7781f, 6.056293f},
    {5320.369f, 1980.125f, 707.7781f, 2.007129f},
    {5306.572f, 1977.474f, 707.7781f, 1.500983f},
    {5336.599f, 2017.278f, 707.7781f, 3.473205f},
    {5282.897f, 2019.597f, 707.7781f, 5.881760f},
    {5318.704f, 2036.108f, 707.7781f, 4.223697f},
    {5280.513f, 1997.842f, 707.7781f, 0.296706f},
    {5337.833f, 2010.057f, 707.7781f, 3.228859f},
    {5299.250f, 2035.998f, 707.7781f, 5.026548f},
};

class instance_halls_of_reflection : public InstanceMapScript
{
public:
    instance_halls_of_reflection() : InstanceMapScript("instance_halls_of_reflection", 668) { }

    struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_reflection_InstanceMapScript(Map* map) : InstanceScript(map) {}

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);
            events.Reset();
            _falricGUID = 0;
            _marwynGUID = 0;
            _jainaOrSylvanasPart1GUID = 0;
            _frostwornGeneralGUID = 0;
            _frostmourneGUID = 0;
            _entranceDoorGUID = 0;
            _frostwornDoorGUID = 0;
            _arthasDoorGUID = 0;
            _teamInInstance = 0;
            _waveCount = 0;
            _introEvent = NOT_STARTED;
            _frostwornGeneral = NOT_STARTED;

            for (uint8 i = 0; i < 8; i++)
            {
                waveGuidList[i].clear();
            }
        }

        void OnPlayerEnter(Player* player)
        {
            if (!_teamInInstance)
                _teamInInstance = player->GetTeam();
        }

        void OnCreatureCreate(Creature* creature)
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* player = players.begin()->getSource())
                    _teamInInstance = player->GetTeam();

            switch (creature->GetEntry())
            {
                case NPC_JAINA_PART1:
                case NPC_SYLVANAS_PART1:
                    _jainaOrSylvanasPart1GUID = creature->GetGUID();
                    break;
                case NPC_FALRIC:
                    _falricGUID = creature->GetGUID();
                    break;
                case NPC_MARWYN:
                    _marwynGUID = creature->GetGUID();
                    break;
                case NPC_FROSTWORN_GENERAL:
                    _frostwornGeneralGUID = creature->GetGUID();
                    if (GetBossState(DATA_MARWYN_EVENT) == DONE)
                        if (Creature* general = instance->GetCreature(_frostwornGeneralGUID))
                            general->SetPhaseMask(1, true);
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_FROSTMOURNE:
                    _frostmourneGUID = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, false, go);
                    if (GetData(DATA_INTRO_EVENT) == DONE)
                        go->SetPhaseMask(2, true);
                    break;
                case GO_ENTRANCE_DOOR:
                    _entranceDoorGUID = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, go);
                    break;
                case GO_FROSTWORN_DOOR:
                    _frostwornDoorGUID = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    if (GetBossState(DATA_MARWYN_EVENT) == DONE)
                        HandleGameObject(0, true, go);
                    else
                        HandleGameObject(0, false, go);
                    break;
                case GO_ARTHAS_DOOR:
                    _arthasDoorGUID = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    if (GetBossState(DATA_FROSWORN_EVENT) == DONE)
                        HandleGameObject(0, true, go);
                    else
                        HandleGameObject(0, false, go);
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_FALRIC_EVENT:
                    if (state == DONE)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 60000);
                    break;
                case DATA_MARWYN_EVENT:
                    if (state == DONE)
                    {
                        HandleGameObject(_entranceDoorGUID, true);
                        HandleGameObject(_frostwornDoorGUID, true);
                        if (Creature* general = instance->GetCreature(_frostwornGeneralGUID))
                            general->SetPhaseMask(1, true);
                    }
                    break;
                case DATA_LICHKING_EVENT:
                    break;
                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (_waveCount && data == NOT_STARTED)
                ProcessEvent(0, EVENT_DO_WIPE);

            switch (type)
            {
                case DATA_INTRO_EVENT:
                    if (data == IN_PROGRESS)
                    {
                        if (!_introEvent)
                        {
                            if (_teamInInstance == ALLIANCE)
                                instance->SummonCreature(NPC_JAINA_PART1, JainaSpawnPos);
                            else
                                instance->SummonCreature(NPC_SYLVANAS_PART1, SylvanasSpawnPos);
                        }
                    }
                    _introEvent = data;
                    break;
                case DATA_WAVE_COUNT:
                    if (data == SPECIAL)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    break;
                case DATA_FROSWORN_EVENT:
                    if (data == DONE)
                    {
                        HandleGameObject(_arthasDoorGUID, true);
                        // spawn Jaina part 2
                        // spawn LK part 2
                    }
                    _frostwornGeneral = data;
                    break;
            }

            SaveToDB();
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
                case DATA_WAVE_COUNT:
                    return _waveCount;
                case DATA_TEAM_IN_INSTANCE:
                    return _teamInInstance;
                case DATA_INTRO_EVENT:
                    return _introEvent;
                case DATA_FROSWORN_EVENT:
                    return _frostwornGeneral;
                default:
                    break;
            }

            return 0;
        }

        uint64 GetData64(uint32 type) const
        {
            switch (type)
            {
                case DATA_FALRIC_EVENT:
                    return _falricGUID;
                case DATA_MARWYN_EVENT:
                    return _marwynGUID;
                case DATA_FROSWORN_EVENT:
                    return _frostwornGeneralGUID;
                case DATA_FROSTWORN_DOOR:
                    return _frostwornDoorGUID;
                case DATA_FROSTMOURNE:
                    return _frostmourneGUID;
                default:
                    break;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H R " << GetBossSaveData() << _introEvent << ' ' << _frostwornGeneral;

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'H' && dataHead2 == 'R')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;

                    SetBossState(i, EncounterState(tmpState));
                }

                uint32 temp = 0;
                loadStream >> temp;
                if (temp == DONE)
                    SetData(DATA_INTRO_EVENT, DONE);
                else
                    SetData(DATA_INTRO_EVENT, NOT_STARTED);

                loadStream >> temp;
                if (temp == DONE)
                    SetData(DATA_FROSWORN_EVENT, DONE);
                else
                    SetData(DATA_FROSWORN_EVENT, NOT_STARTED);
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        // wave scheduling,checked when wave npcs die
        void OnUnitDeath(Unit* unit)
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            switch (creature->GetEntry())
            {
                case NPC_WAVE_MERCENARY:
                case NPC_WAVE_FOOTMAN:
                case NPC_WAVE_RIFLEMAN:
                case NPC_WAVE_PRIEST:
                case NPC_WAVE_MAGE:
                    uint32 deadNpcs = 0;
                    if (_waveCount < 5)
                    {
                        for (std::set<uint64>::const_iterator itr = waveGuidList[_waveCount-1].begin(); itr != waveGuidList[_waveCount-1].end(); ++itr)
                            if ((instance->GetCreature(*itr)->isDying()) || (instance->GetCreature(*itr)->isDead()))
                                deadNpcs++;

                        // because the current npc returns isAlive when OnUnitDeath happens
                        // we check if the number of dead npcs is equal to the list-1
                        if (deadNpcs == waveGuidList[_waveCount-1].size() - 1)
                            events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    }
                    else
                    {
                        for (std::set<uint64>::const_iterator itr = waveGuidList[_waveCount-2].begin(); itr != waveGuidList[_waveCount-2].end(); ++itr)
                            if ((instance->GetCreature(*itr)->isDying()) || (instance->GetCreature(*itr)->isDead()))
                                deadNpcs++;

                        // because the current npc returns isAlive when OnUnitDeath happens
                        // we check if the number of dead npcs is equal to the list-1
                        if (deadNpcs == waveGuidList[_waveCount-2].size() - 1)
                            events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    }
                    break;
            }
        }

        void Update(uint32 diff)
        {
            if (!instance->HavePlayers())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_NEXT_WAVE:
                    _waveCount++;
                    ProcessEvent(0, EVENT_ADD_WAVE);
                    break;
            }
        }

        void ProcessEvent(WorldObject* /*go*/, uint32 eventId)
        {
            switch (eventId)
            {
                // spawning all wave npcs at once
                case EVENT_SPAWN_WAVES:
                    DoUpdateWorldState(WORLD_STATE_HOR, 1);
                    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                    {
                        std::vector<uint32> possibilityList,tempList;
                        uint32 posIndex = 0;

                        possibilityList.push_back(NPC_WAVE_MERCENARY);
                        possibilityList.push_back(NPC_WAVE_FOOTMAN);
                        possibilityList.push_back(NPC_WAVE_RIFLEMAN);
                        possibilityList.push_back(NPC_WAVE_PRIEST);
                        possibilityList.push_back(NPC_WAVE_MAGE);

                        // iterate each wave
                        for (uint8 i = 0; i < 8; i++)
                        {
                            tempList = possibilityList;

                            uint64 guid = i <= 3 ? _falricGUID : _marwynGUID;

                            if (i == 0)
                            {
                                tempList.erase(tempList.begin() + urand(0, tempList.size() - 1));
                                tempList.erase(tempList.begin() + urand(0, tempList.size() - 1));
                            }
                            else if (i == 1 || i == 2 || i == 4 || i == 5)
                                tempList.erase(tempList.begin() + urand(0, tempList.size() - 1));

                            for (uint8 itr = 0; itr < tempList.size(); ++itr)
                            {
                                if (Creature* falric = instance->GetCreature(guid))
                                    if (Creature* temp = falric->SummonCreature(tempList[itr], SpawnPos[posIndex], TEMPSUMMON_DEAD_DESPAWN))
                                        waveGuidList[i].insert(temp->GetGUID());
                                posIndex++;
                            }

                            tempList.clear();
                        }
                    }
                    SetData(DATA_WAVE_COUNT, SPECIAL);
                    break;
                case EVENT_ADD_WAVE:
                    DoUpdateWorldState(WORLD_STATE_HOR, 1);
                    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                    HandleGameObject(_entranceDoorGUID, false);

                    switch (_waveCount)
                    {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            for (std::set<uint64>::const_iterator itr = waveGuidList[_waveCount-1].begin(); itr != waveGuidList[_waveCount-1].end(); ++itr)
                            {
                                if (Creature* temp = instance->GetCreature(*itr))
                                {
                                    temp->CastSpell(temp, SPELL_SPIRIT_ACTIVATE, true);
                                    temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_NOT_SELECTABLE);
                                    temp->AI()->DoZoneInCombat();
                                }
                            }
                            break;
                        case 5:
                            if (GetBossState(DATA_FALRIC_EVENT) == DONE)
                                events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                            else
                                if (Creature* falric = instance->GetCreature(_falricGUID))
                                    if (falric->AI())
                                        falric->AI()->DoAction(ACTION_ENTER_COMBAT);
                            break;
                        case 6:
                        case 7:
                        case 8:
                        case 9:
                            for (std::set<uint64>::const_iterator itr = waveGuidList[_waveCount-2].begin(); itr != waveGuidList[_waveCount-2].end(); ++itr)
                            {
                                if (Creature* temp = instance->GetCreature(*itr))
                                {
                                    temp->CastSpell(temp, SPELL_SPIRIT_ACTIVATE, true);
                                    temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_NOT_SELECTABLE);
                                    temp->AI()->DoZoneInCombat();
                                }
                            }
                            break;
                        case 10:
                            if (GetBossState(DATA_MARWYN_EVENT) != DONE) // wave should not have been started if DONE. Check anyway to avoid bug exploit!
                                if (Creature* marwyn = instance->GetCreature(_marwynGUID))
                                    if (marwyn->AI())
                                        marwyn->AI()->DoAction(ACTION_ENTER_COMBAT);
                            break;
                    }
                    break;
                case EVENT_DO_WIPE:
                    //SetData(DATA_WAVE_COUNT, NOT_STARTED);
                    _waveCount = 0;
                    events.Reset();
                    DoUpdateWorldState(WORLD_STATE_HOR, 1);
                    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                    HandleGameObject(_entranceDoorGUID, true);

                    if (Creature* falric = instance->GetCreature(_falricGUID))
                        falric->SetVisible(false);
                    if (Creature* marwyn = instance->GetCreature(_marwynGUID))
                        marwyn->SetVisible(false);

                    //despawn wave npcs
                    for (uint8 i = 0; i < 8; i++)
                    {
                        for (std::set<uint64>::const_iterator itr = waveGuidList[i].begin(); itr != waveGuidList[i].end(); ++itr)
                            instance->GetCreature(*itr)->DespawnOrUnsummon();
                    }
                    break;
            }
        }

    private:
        uint64 _falricGUID;
        uint64 _marwynGUID;
        uint64 _jainaOrSylvanasPart1GUID;
        uint64 _frostwornGeneralGUID;

        uint64 _frostmourneGUID;
        uint64 _entranceDoorGUID;
        uint64 _frostwornDoorGUID;
        uint64 _arthasDoorGUID;
        uint64 _escapeDoorGUID;

        uint32 _teamInInstance;
        uint32 _waveCount;
        uint32 _introEvent;
        uint32 _frostwornGeneral;

        EventMap events;

        std::set<uint64> waveGuidList[8];
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_halls_of_reflection_InstanceMapScript(map);
    }
};

void AddSC_instance_halls_of_reflection()
{
    new instance_halls_of_reflection();
}
