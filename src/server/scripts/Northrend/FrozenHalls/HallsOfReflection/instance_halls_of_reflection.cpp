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

#include "ScriptMgr.h"
#include "Containers.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "halls_of_reflection.h"
#include "InstanceScript.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "WorldStatePackets.h"

Position const JainaSpawnPos           = { 5236.659f, 1929.894f, 707.7781f, 0.8726646f }; // Jaina Spawn Position
Position const SylvanasSpawnPos        = { 5236.667f, 1929.906f, 707.7781f, 0.8377581f }; // Sylvanas Spawn Position (sniffed)
Position const JainaSpawnPos2          = { 5549.011f, 2257.041f, 733.0120f, 1.153993f  }; // Jaina Spawn Position 2
Position const SylvanasSpawnPos2       = { 5549.29f,  2257.353f, 733.0943f, 0.8901179f }; // Sylvanas Spawn Position 2 (sniffed)
Position const KorelnOrLoralenSpawnPos = { 5232.68f,  1931.46f,  707.7781f, 0.8377581f };

Position const TheLichKingEscapePosition[] =
{
    { 5557.017f, 2266.103f, 733.0943f, 3.892084f }, // 0 - Spawn (Horde)
    { 5552.733f, 2262.718f, 733.0110f, 4.009696f }  // 1 - Spawn (Alliance)
};

Position const SpawnPos[] =
{
    { 5309.577f, 2042.668f, 707.7781f, 4.694936f },
    { 5295.885f, 2040.342f, 707.7781f, 5.078908f },
    { 5340.836f, 1992.458f, 707.7781f, 2.757620f },
    { 5325.072f, 1977.597f, 707.7781f, 2.076942f },
    { 5277.365f, 1993.229f, 707.7781f, 0.401426f },
    { 5275.479f, 2001.135f, 707.7781f, 0.174533f },
    { 5302.448f, 2042.222f, 707.7781f, 4.904375f },
    { 5343.293f, 1999.384f, 707.7781f, 2.914700f },
    { 5295.635f, 1973.757f, 707.7781f, 1.186824f },
    { 5311.031f, 1972.229f, 707.7781f, 1.640610f },
    { 5275.076f, 2008.724f, 707.7781f, 6.213372f },
    { 5316.701f, 2041.550f, 707.7781f, 4.502949f },
    { 5344.150f, 2007.168f, 707.7781f, 3.159046f },
    { 5319.158f, 1973.998f, 707.7781f, 1.919862f },
    { 5302.247f, 1972.415f, 707.7781f, 1.378810f },
    { 5277.739f, 2016.882f, 707.7781f, 5.969026f },
    { 5322.964f, 2040.288f, 707.7781f, 4.345870f },
    { 5343.467f, 2015.951f, 707.7781f, 3.490659f },
    { 5313.820f, 1978.146f, 707.7781f, 1.745329f },
    { 5279.649f, 2004.656f, 707.7781f, 0.069814f },
    { 5306.057f, 2037.002f, 707.7781f, 4.817109f },
    { 5337.865f, 2003.403f, 707.7781f, 2.984513f },
    { 5299.434f, 1979.009f, 707.7781f, 1.239184f },
    { 5312.752f, 2037.122f, 707.7781f, 4.590216f },
    { 5335.724f, 1996.859f, 707.7781f, 2.740167f },
    { 5280.632f, 2012.156f, 707.7781f, 6.056293f },
    { 5320.369f, 1980.125f, 707.7781f, 2.007129f },
    { 5306.572f, 1977.474f, 707.7781f, 1.500983f },
    { 5336.599f, 2017.278f, 707.7781f, 3.473205f },
    { 5282.897f, 2019.597f, 707.7781f, 5.881760f },
    { 5318.704f, 2036.108f, 707.7781f, 4.223697f },
    { 5280.513f, 1997.842f, 707.7781f, 0.296706f },
    { 5337.833f, 2010.057f, 707.7781f, 3.228859f },
    { 5299.250f, 2035.998f, 707.7781f, 5.026548f }
};

Position const UtherQuelDalarPos = { 5302.001f, 1988.698f, 707.7781f, 3.700098f };

class instance_halls_of_reflection : public InstanceMapScript
{
    public:
        instance_halls_of_reflection() : InstanceMapScript(HoRScriptName, 668) { }

        struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_reflection_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

                _teamInInstance           = 0;
                _waveCount                = 0;
                _introState               = NOT_STARTED;
                _frostswornGeneralState   = NOT_STARTED;
                _quelDelarState           = NOT_STARTED;

                events.Reset();
            }

            void OnPlayerEnter(Player* player) override
            {
                if (!_teamInInstance)
                    _teamInInstance = player->GetTeam();

                if (GetBossState(DATA_MARWYN) == DONE)
                {
                    SpawnGunship();

                    if (!JainaOrSylvanasEscapeGUID && GetBossState(DATA_THE_LICH_KING_ESCAPE) != DONE)
                        SpawnEscapeEvent();
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_JAINA_INTRO:
                    case NPC_SYLVANAS_INTRO:
                        JainaOrSylvanasIntroGUID = creature->GetGUID();
                        break;
                    case NPC_KORELN:
                    case NPC_LORALEN:
                        if (GetBossState(DATA_MARWYN) != DONE)
                            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        KorelnOrLoralenGUID = creature->GetGUID();
                        break;
                    case NPC_THE_LICH_KING_INTRO:
                        TheLichkingIntroGUID = creature->GetGUID();
                        break;
                    case NPC_FALRIC:
                        FalricGUID = creature->GetGUID();
                        break;
                    case NPC_MARWYN:
                        MarwynGUID = creature->GetGUID();
                        break;
                    case NPC_FROSTMOUNRE_ALTAR_BUNNY:
                        FrostmourneAltarBunnyGUID = creature->GetGUID();
                        break;
                    case NPC_FROSTSWORN_GENERAL:
                        FrostswornGeneralGUID = creature->GetGUID();
                        if (GetBossState(DATA_MARWYN) != DONE)
                            PhasingHandler::AddPhase(creature, 170, true);
                        else
                            PhasingHandler::RemovePhase(creature, 170, true);
                        break;
                    case NPC_JAINA_ESCAPE:
                    case NPC_SYLVANAS_ESCAPE:
                        JainaOrSylvanasEscapeGUID = creature->GetGUID();
                        break;
                    case NPC_THE_LICH_KING_ESCAPE:
                        TheLichKingEscapeGUID = creature->GetGUID();
                        break;
                    case NPC_JUSTIN_BARTLETT:
                    case NPC_KORM_BLACKSCAR:
                        CaptainGUID = creature->GetGUID();
                        break;
                    case NPC_WORLD_TRIGGER:
                        if (!creature->GetTransport())
                            break;
                        // no break
                    case NPC_GUNSHIP_CANNON_HORDE:
                        GunshipCannonGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_ICE_WALL_TARGET:
                        IcewallTargetGUID = creature->GetGUID();
                        break;
                    case NPC_UTHER:
                        UtherGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_WAVE_MERCENARY:
                    case NPC_WAVE_FOOTMAN:
                    case NPC_WAVE_RIFLEMAN:
                    case NPC_WAVE_PRIEST:
                    case NPC_WAVE_MAGE:
                    {
                        uint32 internalWaveId = creature->AI()->GetData(0);
                        waveGuidList[internalWaveId].erase(creature->GetGUID());
                        break;
                    }
                    case NPC_ICE_WALL_TARGET:
                        IcewallTargetGUID.Clear();
                        break;
                    case NPC_WORLD_TRIGGER:
                    case NPC_GUNSHIP_CANNON_HORDE:
                        GunshipCannonGUIDs.erase(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            uint32 GetGameObjectEntry(ObjectGuid::LowType /*guidLow*/, uint32 entry) override
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _teamInInstance = player->GetTeam();
                }

                switch (entry)
                {
                    case GO_THE_CAPTAIN_CHEST_ALLIANCE_NORMAL:
                    case GO_THE_CAPTAIN_CHEST_ALLIANCE_HEROIC:
                    case GO_THE_SKYBREAKER_STAIRS:
                        if (_teamInInstance == HORDE)
                            return 0;
                        break;
                    case GO_THE_CAPTAIN_CHEST_HORDE_NORMAL:
                    case GO_THE_CAPTAIN_CHEST_HORDE_HEROIC:
                    case GO_ORGRIMS_HAMMER_STAIRS:
                        if (_teamInInstance == ALLIANCE)
                            return 0;
                        break;
                    default:
                        break;
                }

                return entry;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_FROSTMOURNE:
                        FrostmourneGUID = go->GetGUID();
                        if (GetData(DATA_INTRO_EVENT) == DONE)
                            go->SetLootState(GO_JUST_DEACTIVATED);
                        break;
                    case GO_ENTRANCE_DOOR:
                        EntranceDoorGUID = go->GetGUID();
                        break;
                    case GO_IMPENETRABLE_DOOR:
                        ImpenetrableDoorGUID = go->GetGUID();
                        HandleGameObject(ObjectGuid::Empty, GetBossState(DATA_MARWYN) == DONE, go);
                        break;
                    case GO_SHADOW_THRONE_DOOR:
                        ShadowThroneDoorGUID = go->GetGUID();
                        HandleGameObject(ObjectGuid::Empty, GetData(DATA_FROSTSWORN_GENERAL) == DONE, go);
                        break;
                    case GO_CAVE_IN:
                        CaveInGUID = go->GetGUID();
                        break;
                    case GO_THE_SKYBREAKER:
                    case GO_ORGRIMS_HAMMER:
                        GunshipGUID = go->GetGUID();
                        break;
                    case GO_THE_SKYBREAKER_STAIRS:
                    case GO_ORGRIMS_HAMMER_STAIRS:
                        if (GetBossState(DATA_THE_LICH_KING_ESCAPE) == DONE)
                            go->SetRespawnTime(DAY);
                        GunshipStairGUIDs.insert(go->GetGUID());
                        break;
                    case GO_THE_CAPTAIN_CHEST_ALLIANCE_NORMAL:
                    case GO_THE_CAPTAIN_CHEST_HORDE_NORMAL:
                    case GO_THE_CAPTAIN_CHEST_ALLIANCE_HEROIC:
                    case GO_THE_CAPTAIN_CHEST_HORDE_HEROIC:
                        CaptainsChestGUID = go->GetGUID();
                        break;
                    case GO_ICE_WALL:
                        HandleGameObject(ObjectGuid::Empty, false, go);
                        IcewallGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_THE_SKYBREAKER_STAIRS:
                    case GO_ORGRIMS_HAMMER_STAIRS:
                        GunshipStairGUIDs.erase(go->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_HOR_WAVES_ENABLED), int32(_introState == DONE && GetBossState(DATA_MARWYN) != DONE));
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_HOR_WAVE_COUNT), int32(_waveCount));
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_FALRIC:
                        if (state == DONE)
                        {
                            ++_waveCount;
                            events.ScheduleEvent(EVENT_NEXT_WAVE, 60000);
                        }
                        break;
                    case DATA_MARWYN:
                        if (state == DONE)
                        {
                            if (Creature* bunny = instance->GetCreature(FrostmourneAltarBunnyGUID))
                                bunny->CastSpell(bunny, SPELL_START_HALLS_OF_REFLECTION_QUEST_AE, true);

                            if (Creature* korelnOrLoralen = instance->GetCreature(KorelnOrLoralenGUID))
                                korelnOrLoralen->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                            HandleGameObject(EntranceDoorGUID, true);
                            HandleGameObject(ImpenetrableDoorGUID, true);
                            DoUpdateWorldState(WORLD_STATE_HOR_WAVES_ENABLED, 0);
                            if (Creature* general = instance->GetCreature(FrostswornGeneralGUID))
                                PhasingHandler::RemovePhase(general, 170, true);

                            SpawnGunship();
                            SpawnEscapeEvent();
                        }
                        break;
                    case DATA_THE_LICH_KING_ESCAPE:
                        switch (state)
                        {
                            case NOT_STARTED:
                                break;
                            case IN_PROGRESS:
                                if (Creature* jainaOrSylvanas = instance->GetCreature(JainaOrSylvanasEscapeGUID))
                                    jainaOrSylvanas->AI()->DoAction(ACTION_START_PREFIGHT);
                                break;
                            case DONE:
                                if (GameObject* chest = instance->GetGameObject(CaptainsChestGUID))
                                    chest->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);

                                DoUseDoorOrButton(CaveInGUID, 15);

                                if (Creature* lichking = instance->GetCreature(TheLichKingEscapeGUID))
                                {
                                    lichking->CastSpell((Unit*)NULL, SPELL_ACHIEV_CHECK, true);
                                    lichking->DespawnOrUnsummon(1);
                                }
                                break;
                            case FAIL:
                                DoStopCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);

                                if (Creature* jainaOrSylvanas = instance->GetCreature(JainaOrSylvanasEscapeGUID))
                                    jainaOrSylvanas->DespawnOrUnsummon(10000);

                                if (Creature* icewallTarget = instance->GetCreature(IcewallTargetGUID))
                                    icewallTarget->DespawnOrUnsummon();

                                if (GameObject* icewall = instance->GetGameObject(IcewallGUID))
                                    icewall->Delete();

                                events.ScheduleEvent(EVENT_SPAWN_ESCAPE_EVENT, 30000);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SpawnGunship()
            {
                // don't spawn gunship twice
                if (!GunshipGUID.IsEmpty())
                    return;

                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _teamInInstance = player->GetTeam();
                }

                if (Transport* gunship = sTransportMgr->CreateTransport(_teamInInstance == HORDE ? GO_ORGRIMS_HAMMER : GO_THE_SKYBREAKER, UI64LIT(0), instance))
                    gunship->EnableMovement(GetBossState(DATA_THE_LICH_KING_ESCAPE) == DONE);
            }

            void SpawnEscapeEvent()
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _teamInInstance = player->GetTeam();
                }

                if (_teamInInstance == ALLIANCE)
                {
                    instance->SummonCreature(NPC_JAINA_ESCAPE, JainaSpawnPos2);
                    instance->SummonCreature(NPC_THE_LICH_KING_ESCAPE, TheLichKingEscapePosition[1]);
                }
                else
                {
                    instance->SummonCreature(NPC_SYLVANAS_ESCAPE, SylvanasSpawnPos2);
                    instance->SummonCreature(NPC_THE_LICH_KING_ESCAPE, TheLichKingEscapePosition[0]);
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_INTRO_EVENT:
                        if (data == IN_PROGRESS)
                        {
                            if (_introState == NOT_STARTED)
                            {
                                if (_teamInInstance == ALLIANCE)
                                {
                                    instance->SummonCreature(NPC_JAINA_INTRO, JainaSpawnPos);
                                    instance->SummonCreature(NPC_KORELN, KorelnOrLoralenSpawnPos);
                                }
                                else
                                {
                                    instance->SummonCreature(NPC_SYLVANAS_INTRO, SylvanasSpawnPos);
                                    instance->SummonCreature(NPC_LORALEN, KorelnOrLoralenSpawnPos);
                                }
                            }
                        }
                        _introState = data;
                        break;
                    case DATA_WAVE_COUNT:
                        if (_waveCount && data == NOT_STARTED)
                            ProcessEvent(NULL, EVENT_DO_WIPE);
                        break;
                    case DATA_FROSTSWORN_GENERAL:
                        if (data == DONE)
                            HandleGameObject(ShadowThroneDoorGUID, true);
                        _frostswornGeneralState = data;
                        break;
                    case DATA_QUEL_DELAR_EVENT:
                        if (data == IN_PROGRESS)
                        {
                            if (_quelDelarState == NOT_STARTED)
                            {
                                if (Creature* bunny = instance->GetCreature(FrostmourneAltarBunnyGUID))
                                    bunny->CastSpell((Unit*)NULL, SPELL_ESSENCE_OF_CAPTURED);
                                events.ScheduleEvent(EVENT_QUEL_DELAR_SUMMON_UTHER, 2000);
                            }
                        }
                        _quelDelarState = data;
                        break;
                    default:
                        break;
                }

                SaveToDB();
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                switch (type)
                {
                    case DATA_QUEL_DELAR_INVOKER:
                        QuelDelarInvokerGUID = data;
                        break;
                    default:
                        break;
                }
            }

            // wave scheduling, checked when wave npcs die
            void OnUnitDeath(Unit* unit) override
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
                    {
                        uint32 waveId = creature->AI()->GetData(0);
                        for (ObjectGuid guid : waveGuidList[waveId])
                        {
                            if (Creature* npc = instance->GetCreature(guid))
                                if (npc->IsAlive())
                                    return;
                        }

                        ++_waveCount;
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 3000);
                        break;
                    }
                }
            }

            void Update(uint32 diff) override
            {
                if (!instance->HavePlayers())
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_NEXT_WAVE:
                        ProcessEvent(NULL, EVENT_ADD_WAVE);
                        break;
                    case EVENT_SPAWN_ESCAPE_EVENT:
                        SpawnEscapeEvent();
                        break;
                    case EVENT_QUEL_DELAR_SUMMON_UTHER:
                        instance->SummonCreature(NPC_UTHER, UtherQuelDalarPos);
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    // spawning all wave npcs at once
                    case EVENT_SPAWN_WAVES:
                        _waveCount = 1;
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVES_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                        {
                            std::list<uint32> possibilityList, tempList;
                            uint32 posIndex = 0;

                            possibilityList.push_back(NPC_WAVE_MERCENARY);
                            possibilityList.push_back(NPC_WAVE_FOOTMAN);
                            possibilityList.push_back(NPC_WAVE_RIFLEMAN);
                            possibilityList.push_back(NPC_WAVE_PRIEST);
                            possibilityList.push_back(NPC_WAVE_MAGE);

                            // iterate each wave
                            for (uint8 i = 0; i < 8; ++i)
                            {
                                tempList = possibilityList;

                                ObjectGuid bossGuid = i <= 3 ? FalricGUID : MarwynGUID;

                                if (!i)
                                    Trinity::Containers::RandomResize(tempList, 3);
                                else if (i < 6 && i != 3)
                                    Trinity::Containers::RandomResize(tempList, 4);

                                for (uint32 entry : tempList)
                                {
                                    if (Creature* boss = instance->GetCreature(bossGuid))
                                    {
                                        if (Creature* temp = boss->SummonCreature(entry, SpawnPos[posIndex], TEMPSUMMON_DEAD_DESPAWN))
                                        {
                                            temp->AI()->SetData(0, i);
                                            waveGuidList[i].insert(temp->GetGUID());
                                        }
                                    }

                                    ++posIndex;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 5000);
                        break;
                    case EVENT_ADD_WAVE:
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVES_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                        HandleGameObject(EntranceDoorGUID, false);

                        if (_waveCount % 5)
                        {
                            uint32 internalWaveId = _waveCount - ((_waveCount < 5) ? 1 : 2);
                            for (ObjectGuid guid : waveGuidList[internalWaveId])
                            {
                                if (Creature* temp = instance->GetCreature(guid))
                                {
                                    temp->CastSpell(temp, SPELL_SPIRIT_ACTIVATE, false);
                                    temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                                    temp->AI()->DoZoneInCombat(temp, 100.00f);
                                }
                            }
                        }
                        else
                        {
                            uint32 bossIndex = (_waveCount / 5) - 1;
                            if (GetBossState(DATA_FALRIC + bossIndex) != DONE)
                            {
                                if (Creature* boss = instance->GetCreature(bossIndex ? MarwynGUID : FalricGUID))
                                    boss->AI()->DoAction(ACTION_ENTER_COMBAT);
                            }
                            else if (_waveCount != 10)
                            {
                                ++_waveCount;
                                events.ScheduleEvent(EVENT_NEXT_WAVE, 5000);
                            }
                        }
                        break;
                    case EVENT_DO_WIPE:
                        _waveCount = 0;
                        events.Reset();
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVES_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, _waveCount);
                        HandleGameObject(EntranceDoorGUID, true);

                        if (Creature* falric = instance->GetCreature(FalricGUID))
                            falric->SetVisible(false);
                        if (Creature* marwyn = instance->GetCreature(MarwynGUID))
                            marwyn->SetVisible(false);
                        // despawn wave npcs
                        for (uint8 i = 0; i < 8; ++i)
                        {
                            for (ObjectGuid guid : waveGuidList[i])
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(1);
                            waveGuidList[i].clear();
                        }
                        break;
                    // Gunship Outro
                    case EVENT_GUNSHIP_ARRIVAL:
                        if (GetBossState(DATA_THE_LICH_KING_ESCAPE) == DONE)
                            break;

                        if (Transport* gunship = instance->GetTransport(GunshipGUID))
                            gunship->EnableMovement(false);

                        if (Creature* jainaOrSylvanas = instance->GetCreature(JainaOrSylvanasEscapeGUID))
                            jainaOrSylvanas->AI()->DoAction(ACTION_GUNSHIP_ARRIVAL);

                        if (Creature* captain = instance->GetCreature(CaptainGUID))
                            captain->AI()->Talk(SAY_CAPTAIN_FIRE);

                        for (ObjectGuid guid : GunshipCannonGUIDs)
                        {
                            uint32 entry = guid.GetEntry();
                            if ((entry == NPC_WORLD_TRIGGER && _teamInInstance == ALLIANCE) || (entry == NPC_GUNSHIP_CANNON_HORDE && _teamInInstance == HORDE))
                                if (Creature* cannon = instance->GetCreature(guid))
                                    cannon->CastSpell(cannon, SPELL_GUNSHIP_CANNON_FIRE, true);
                        }
                        break;
                    case EVENT_GUNSHIP_ARRIVAL_2:
                        if (Transport* gunship = instance->GetTransport(GunshipGUID))
                            gunship->EnableMovement(false);

                        for (ObjectGuid guid : GunshipStairGUIDs)
                            if (GameObject* stairs = instance->GetGameObject(guid))
                                stairs->SetRespawnTime(DAY);

                        if (Creature* jainaOrSylvanas = instance->GetCreature(JainaOrSylvanasEscapeGUID))
                            jainaOrSylvanas->AI()->DoAction(ACTION_GUNSHIP_ARRIVAL_2);

                        if (Creature* captain = instance->GetCreature(CaptainGUID))
                            captain->AI()->Talk(SAY_CAPTAIN_FINAL);

                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_WAVE_COUNT:
                        return _waveCount;
                    case DATA_TEAM_IN_INSTANCE:
                        return _teamInInstance;
                    case DATA_INTRO_EVENT:
                        return _introState;
                    case DATA_FROSTSWORN_GENERAL:
                        return _frostswornGeneralState;
                    case DATA_QUEL_DELAR_EVENT:
                        return _quelDelarState;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_FALRIC:
                        return FalricGUID;
                    case DATA_MARWYN:
                        return MarwynGUID;
                    case DATA_FROSTSWORN_GENERAL:
                        return FrostswornGeneralGUID;
                    case DATA_IMPENETRABLE_DOOR:
                        return ImpenetrableDoorGUID;
                    case DATA_FROSTMOURNE:
                        return FrostmourneGUID;
                    case DATA_ESCAPE_LEADER:
                        return JainaOrSylvanasEscapeGUID;
                    case DATA_KORELN_LORALEN:
                        return KorelnOrLoralenGUID;
                    case DATA_THE_LICH_KING_ESCAPE:
                        return TheLichKingEscapeGUID;
                    case DATA_GUNSHIP:
                        return GunshipGUID;
                    case DATA_ICEWALL:
                        return IcewallGUID;
                    case DATA_ICEWALL_TARGET:
                        return IcewallTargetGUID;
                    case DATA_FROSTMOURNE_ALTAR_BUNNY:
                        return FrostmourneAltarBunnyGUID;
                    case DATA_UTHER_QUEL_DELAR:
                        return UtherGUID;
                    case DATA_QUEL_DELAR_INVOKER:
                        return QuelDelarInvokerGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _introState << ' ' << _frostswornGeneralState << ' ' << _quelDelarState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                uint32 temp = 0;
                data >> temp;
                if (temp == DONE)
                    SetData(DATA_INTRO_EVENT, DONE);
                else
                    SetData(DATA_INTRO_EVENT, NOT_STARTED);

                data >> temp;
                if (temp == DONE)
                    SetData(DATA_FROSTSWORN_GENERAL, DONE);
                else
                    SetData(DATA_FROSTSWORN_GENERAL, NOT_STARTED);

                data >> temp;
                if (temp == DONE)
                    SetData(DATA_QUEL_DELAR_EVENT, DONE);
                else
                    SetData(DATA_QUEL_DELAR_EVENT, NOT_STARTED);
            }

        private:
            ObjectGuid JainaOrSylvanasIntroGUID; // unused
            ObjectGuid KorelnOrLoralenGUID;
            ObjectGuid TheLichkingIntroGUID; // unused
            ObjectGuid FalricGUID;
            ObjectGuid MarwynGUID;
            ObjectGuid FrostmourneAltarBunnyGUID;
            ObjectGuid FrostswornGeneralGUID;
            ObjectGuid JainaOrSylvanasEscapeGUID;
            ObjectGuid TheLichKingEscapeGUID;

            ObjectGuid FrostmourneGUID;
            ObjectGuid EntranceDoorGUID;
            ObjectGuid ImpenetrableDoorGUID;
            ObjectGuid ShadowThroneDoorGUID;
            ObjectGuid CaveInGUID;

            uint32 _teamInInstance;
            uint32 _waveCount;
            uint32 _introState;
            uint32 _frostswornGeneralState;
            uint32 _quelDelarState;

            EventMap events;
            GuidSet waveGuidList[8];

            ObjectGuid GunshipGUID;
            ObjectGuid CaptainsChestGUID;
            ObjectGuid CaptainGUID;
            ObjectGuid IcewallGUID;
            ObjectGuid IcewallTargetGUID;
            ObjectGuid QuelDelarInvokerGUID;
            ObjectGuid UtherGUID;

            GuidSet GunshipCannonGUIDs;
            GuidSet GunshipStairGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_reflection_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_reflection()
{
    new instance_halls_of_reflection();
}
