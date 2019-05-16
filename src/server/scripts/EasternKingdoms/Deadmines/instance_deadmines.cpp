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
#include "CreatureAI.h"
#include "deadmines.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "VehicleDefines.h"
#include "WorldPacket.h"

enum EventIds
{
    EVENT_SUMMON_CAPTAIN_COOKIE = 1,
    EVENT_SUMMON_NOTE_FROM_VANESSA,
    EVENT_CAST_NIGHTMARE_AURA_1,
    EVENT_CAST_NIGHTMARE_AURA_2,
    EVENT_CAST_NIGHTMARE_AURA_3,
    EVENT_CAST_NIGHTMARE_AURA_4,
    EVENT_ANNOUNCE_NIGHTMARE_ELIXIR_TAKES_HOLD,
    EVENT_SETUP_GLUBTOKS_NIGHTMARE,
    EVENT_SUMMON_ICICLES,
    EVENT_SUMMON_GLUBTOK,
    EVENT_ANNOUNCE_NIGHTMARE_SHIFTS,
    EVENT_DESPAWN_NIGHTMARE_FIRE,
    EVENT_SETUP_HELIX_NIGHTMARE,
    EVENT_DESPAWN_NIGHTMARE_SPIDERS,
    EVENT_SETUP_MECHANICAL_NIGHTMARE,
    EVENT_SUMMON_FOE_REAPER,
    EVENT_DESPAWN_LIGHTNING_PLATTERS,
    EVENT_SETUP_RIPSNARL_NIGHTMARE,
    EVENT_NIGHTMARE_SHIFTS_2,
    EVENT_OPEN_IRON_CLAD_DOOR,
    EVENT_SUMMON_ERIK_HARRINGTON,
    EVENT_SUMMON_JAMES_HARRINGTON,
    EVENT_ANNOUNCE_SAVE_EMME_HARRINGTON,
    EVENT_ANNOUNCE_SAVE_ERIK_HARRINGTON,
    EVENT_ANNOUNCE_SAVE_CALISSA_HARRINGTON,
    EVENT_ANNOUNCE_ELIXIR_WEARS_OFF,
    EVENT_SUMMON_VANESSA_VANCLEEF_BOSS,
    EVENT_CHECK_DEAD_PLAYERS
};

enum TextIds
{
    // Id's 0 - 1 used by Foe Reaper 5000
    // Id 2 used by Defias Cannon
    SAY_ANNOUNCE_SHADOWY_FIGURE                 = 3,
    SAY_ANNOUNCE_NIGHTMARE_ELIXIR_TAKES_HOLD    = 4,
    SAY_ANNOUNCE_NIGHTMARE_SHIFTS               = 5,
    SAY_ANNOUNCE_SAVE_EMME_HARRINGTON           = 6,
    SAY_ANNOUNCE_SAVE_ERIK_HARRINGTON           = 7,
    SAY_ANNOUNCE_SAVE_CALISSA_HARRINGTON        = 8,
    SAY_ANNOUNCE_NIGHTMARE_ELIXIR_WEARS_OFF     = 9,
};

ObjectData const creatureData[] =
{
    { BOSS_GLUBTOK,                     DATA_GLUBTOK                        },
    { BOSS_HELIX_GEARBREAKER,           DATA_HELIX_GEARBREAKER              },
    { BOSS_FOE_REAPER_5000,             DATA_FOE_REAPER_5000                },
    { BOSS_ADMIRAL_RIPSNARL,            DATA_ADMIRAL_RIPSNARL               },
    { BOSS_CAPTAIN_COOKIE,              DATA_CAPTAIN_COOKIE                 },
    { BOSS_VANESSA_VAN_CLEEF,           DATA_VANESSA_VAN_CLEEF              },
    { NPC_LUMBERING_OAF,                DATA_LUMBERING_OAF                  },
    { NPC_FOE_REAPER_TARGETING_BUNNY,   DATA_FOE_REAPER_BUNNY               },
    { NPC_PROTOTYPE_REAPER,             DATA_PROTOTYPE_REAPER               },
    { NPC_VANESSAS_TRAP_BUNNY,          DATA_VANESSAS_TRAP_BUNNY            },
    { NPC_VANESSA_ANCHOR_BUNNY_JMF,     DATA_VANESSA_ANCHOR_BUNNY           },
    { NPC_VANESSA_VANCLEEF_NIGHTMARE,   DATA_VANESSA_VAN_CLEEF_NIGHTMARE    },
    { NPC_EMME_HARRINGTON,              DATA_EMME_HARRINGTON                },
    { NPC_ERIK_HARRINGTON,              DATA_ERIK_HARRINGTON                },
    { NPC_CALISSA_HARRINGTON,           DATA_CALISSA_HARRINGTON             },
    { 0,                                0                                   } // END
};

ObjectData const gameobjectData[] =
{
    { GO_IRON_CLAD_DOOR,                DATA_IRON_CLAD_DOOR     },
    { GO_FOUNDRY_DOOR,                  DATA_FOUNDRY_DOOR       },
    { 0,                                0                       } // END
};

DoorData const doorData[] =
{
    { GO_FACTORY_DOOR,      DATA_GLUBTOK,           DOOR_TYPE_PASSAGE   },
    { GO_MAST_ROOM_DOOR,    DATA_HELIX_GEARBREAKER, DOOR_TYPE_PASSAGE   },
    { GO_HEAVY_DOOR,        DATA_HELIX_GEARBREAKER, DOOR_TYPE_ROOM      },
    { GO_FOUNDRY_DOOR,      DATA_FOE_REAPER_5000,   DOOR_TYPE_PASSAGE   },
    { 0,                    0,                      DOOR_TYPE_ROOM      } // END
};

class instance_deadmines : public InstanceMapScript
{
    public:
        instance_deadmines() : InstanceMapScript(DMScriptName, 36) { }

        struct instance_deadmines_InstanceMapScript : public InstanceScript
        {
            instance_deadmines_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(map->IsHeroic() ? EncounterCount : EncounterCount - 1); // Vanessa van Cleef only in heroic mode
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameobjectData);
                _teamInInstance = 0;
                _foeReaper5000Intro = 0;
                _ironCladDoorState = 0;
                _vanessaVanCleefEncounterState = 0;
                _activatedVentCounter = 0;
                _deadEnragedWorgen = 0;
                _firstCookieSpawn = true;
                _cookieSpawnChecked = false;
                _noteSpawnChecked = false;
                _ropesSpawned = false;
            }

            void OnPlayerEnter(Player* player) override
            {
                instance->LoadGrid(-205.75f, -579.09f);
                if (!_teamInInstance)
                    _teamInInstance = player->GetTeam();

                if (!_cookieSpawnChecked)
                {
                    if (GetBossState(DATA_ADMIRAL_RIPSNARL) == DONE && GetBossState(DATA_CAPTAIN_COOKIE) != DONE)
                        events.ScheduleEvent(EVENT_SUMMON_CAPTAIN_COOKIE, Milliseconds(1));

                    _cookieSpawnChecked = true;
                }

                if (!_noteSpawnChecked)
                {
                    if (GetBossState(DATA_CAPTAIN_COOKIE) == DONE && GetBossState(DATA_VANESSA_VAN_CLEEF) != DONE)
                        events.ScheduleEvent(EVENT_SUMMON_NOTE_FROM_VANESSA, Milliseconds(1));
                    _noteSpawnChecked = true;
                }

                if (!_ropesSpawned)
                {
                    for (uint8 i = 0; i < 5; i++)
                        if (Creature* anchor = instance->SummonCreature(NPC_VANESSAS_ROPE_ANCHOR, RopeAnchorPos[i]))
                            _anchorGuidSet.insert(anchor->GetGUID());
                    _ropesSpawned = true;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    // Horde restricted creatures
                    case NPC_SLINKY_SHARPSHIV:
                    case NPC_KAGTHA:
                    case NPC_MISS_MAYHEM:
                    case NPC_SHATTERED_HAND_ASSASSIN:
                    case NPC_MAYHEM_REAPER_PROTOTYPE:
                        if (_teamInInstance != HORDE)
                            creature->SetVisible(false);
                        break;
                    // Alliance restricted creatures
                    case NPC_STORMWIND_INVESTIGATOR:
                    case NPC_CRIME_SCENE_ALARM_O_BOT:
                    case NPC_STORMWIND_DEFENDER:
                    case NPC_LIEUTENANT_HORATIO_LAINE:
                    case NPC_QUARTERMASTER_LEWIS:
                        if (_teamInInstance != ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_FIREWALL_PLATTER_1A:
                    case NPC_FIREWALL_PLATTER_1B:
                    case NPC_FIREWALL_PLATTER_1C:
                    case NPC_FIREWALL_PLATTER_2A:
                    case NPC_FIREWALL_PLATTER_2B:
                    case NPC_FIREWALL_PLATTER_2C:
                        if (Creature* glubtok = GetCreature(DATA_GLUBTOK))
                            glubtok->AI()->JustSummoned(creature);
                        break;
                    case NPC_STICKY_BOMB:
                        if (Creature* helix = GetCreature(DATA_HELIX_GEARBREAKER))
                            helix->AI()->JustSummoned(creature);
                        break;
                    case NPC_LUMBERING_OAF:
                        if (creature->isDead() && GetBossState(DATA_HELIX_GEARBREAKER) != DONE)
                            creature->Respawn();
                        break;
                    case NPC_DEFIAS_REAPER:
                    case NPC_DEFIAS_WATCHER:
                        if (!GetData(DATA_FOE_REAPER_INTRO) && creature->isDead())
                            creature->Respawn();
                        break;
                    case NPC_MOLTEN_SLAG:
                        if (Creature* reaper = GetCreature(DATA_FOE_REAPER_5000))
                            reaper->AI()->JustSummoned(creature);
                        break;
                    case NPC_GENERAL_PURPOSE_BUNNY_L2:
                        _generalPurposeBunnyJMF2GuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_VAPOR:
                        if (Creature* ripsnarl = GetCreature(DATA_ADMIRAL_RIPSNARL))
                            ripsnarl->AI()->JustSummoned(creature);
                        break;
                    case NPC_CORN:
                    case NPC_ROTTEN_CORN:
                    case NPC_MELON:
                    case NPC_ROTTEN_MELON:
                    case NPC_STEAK:
                    case NPC_ROTTEN_STEAK:
                    case NPC_MYSTERY_MEAT:
                    case NPC_ROTTEN_MYSTERY_MEAT:
                    case NPC_LOAF:
                    case NPC_ROTTEN_LOAF:
                    case NPC_BUN:
                    case NPC_ROTTEN_BUN:
                        if (GetBossState(DATA_CAPTAIN_COOKIE) != IN_PROGRESS)
                            creature->DespawnOrUnsummon();
                        else if (Creature* cookie = GetCreature(DATA_CAPTAIN_COOKIE))
                            cookie->AI()->JustSummoned(creature);
                        break;
                    case NPC_VANESSAS_TRAP_BUNNY:
                    case NPC_VANESSA_ANCHOR_BUNNY_JMF:
                    case NPC_VANESSAS_ROPE_ANCHOR:
                        creature->setActive(true);
                        creature->SetFarVisible(true);
                        break;
                    case NPC_STEAM_VALVE:
                        _steamValveGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY:
                    case NPC_GLUBTOK_NIGHTMARE:
                        if (_vanessaVanCleefEncounterState == NIGHTMARE_STAGE_GLUBTOK)
                            _glubtokNightmareGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_HELIX_GEARBREAKER_NIGHTMARE:
                    case NPC_NIGHTMARE_SKITTERLING:
                    case NPC_DARKWEB_DEVOURER:
                    case NPC_CHATTERING_HORROR:
                        _helixNightmareGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_GENERAL_PURPOSE_DUMMY_JMF:
                        if (_vanessaVanCleefEncounterState == NIGHTMARE_STAGE_HELIX)
                            _helixNightmareGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_FOE_REAPER_5000_NIGHTMARE:
                    case NPC_VANESSA_LIGHTNING_PLATTER:
                        _mechanicalNightmareGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_RIPSNARL_NIGHTMARE:
                    case NPC_EMME_HARRINGTON:
                    case NPC_ERIK_HARRINGTON:
                    case NPC_CALISSA_HARRINGTON:
                    case NPC_JAMES_HARRINGTON:
                    case NPC_ENRAGED_WORGEN:
                        _ripsnarlNightareGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_DEFIAS_SHADOWGUARD:
                        creature->setPowerType(POWER_ENERGY);
                        creature->SetMaxPower(POWER_ENERGY, 100);
                        creature->SetPower(POWER_ENERGY, 100);
                        break;
                    case NPC_ROPE:
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        if (Creature* vanessa = GetCreature(DATA_VANESSA_VAN_CLEEF))
                            vanessa->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_IRON_CLAD_DOOR:
                        if (_ironCladDoorState == DONE)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        break;
                    case GO_DEFIAS_CANNON:
                        if (_ironCladDoorState == DONE)
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ADMIRAL_RIPSNARL:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_SUMMON_CAPTAIN_COOKIE, Seconds(10));
                        break;
                    case DATA_CAPTAIN_COOKIE:
                        if (state == FAIL)
                            events.ScheduleEvent(EVENT_SUMMON_CAPTAIN_COOKIE, Seconds(30));
                        else if (state == DONE)
                            if (instance->IsHeroic())
                                instance->SummonCreature(NPC_A_NOTE_FROM_VANESSA, noteFromVanessaSpawnPos);
                        break;
                    case DATA_VANESSA_VAN_CLEEF:
                        if (state == FAIL)
                        {
                            ResetVanessasNightmare();
                            _ropeAnchorPairs.clear();
                        }
                        else if (state == DONE)
                            _ropeAnchorPairs.clear();
                        break;
                    default:
                        break;
                }
                return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() == TYPEID_PLAYER && _vanessaVanCleefEncounterState != NOT_STARTED && _vanessaVanCleefEncounterState != NIGHTMARE_STAGE_DONE)
                    events.ScheduleEvent(EVENT_CHECK_DEAD_PLAYERS, Milliseconds(200));
                else
                {
                    switch (unit->GetEntry())
                    {
                        case NPC_GLUBTOK_NIGHTMARE:
                            unit->ToCreature()->DespawnOrUnsummon(Seconds(4));
                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_HELIX);
                            break;
                        case NPC_HELIX_GEARBREAKER_NIGHTMARE:
                            unit->ToCreature()->DespawnOrUnsummon(Seconds(5) + Milliseconds(500));
                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_FOE_REAPER);
                            break;
                        case NPC_FOE_REAPER_5000_NIGHTMARE:
                            unit->ToCreature()->DespawnOrUnsummon(Seconds(3) + Milliseconds(600));
                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_RIPSNARL);
                            break;
                        case NPC_ENRAGED_WORGEN:
                            _deadEnragedWorgen++;
                            unit->ToCreature()->DespawnOrUnsummon(Seconds(5));
                            if (_deadEnragedWorgen == 3)
                            {
                                if (Creature* emme = GetCreature(DATA_EMME_HARRINGTON))
                                {
                                    emme->CastSpell(emme, SPELL_ADRENALINE, true);
                                    emme->DespawnOrUnsummon();
                                    _deadEnragedWorgen = 0;
                                    events.ScheduleEvent(EVENT_ANNOUNCE_SAVE_ERIK_HARRINGTON, Seconds(4));
                                }
                                else if (Creature* erik = GetCreature(DATA_ERIK_HARRINGTON))
                                {
                                    erik->CastSpell(erik, SPELL_ADRENALINE, true);
                                    erik->DespawnOrUnsummon();
                                    events.ScheduleEvent(EVENT_SUMMON_JAMES_HARRINGTON, Milliseconds(200));
                                }
                            }
                            break;
                        case NPC_JAMES_HARRINGTON:
                            if (Creature* dummy = unit->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                            {
                                dummy->CastSpell(dummy, SPELL_CANCEL_NIGHTMARE_AURA_RIPSNARL, true);
                                dummy->CastSpell(dummy, SPELL_CANCEL_NIGHTMARE_ELIXIR, true);
                            }
                            unit->ToCreature()->DespawnOrUnsummon(Seconds(2) + Milliseconds(300));
                            if (Creature* calissa = GetCreature(DATA_CALISSA_HARRINGTON))
                                calissa->RemoveAllAuras();
                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_DONE);
                            events.ScheduleEvent(EVENT_ANNOUNCE_ELIXIR_WEARS_OFF, Milliseconds(250));
                            break;
                        case NPC_EMME_HARRINGTON:
                        case NPC_ERIK_HARRINGTON:
                        case NPC_CALISSA_HARRINGTON:
                            unit->CastSpell(unit, SPELL_NIGHTMARES_END, true);
                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, FAIL);
                            break;
                        default:
                            break;
                    }
                }
            }

            void ResetVanessasNightmare()
            {
                SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NOT_STARTED);
                events.Reset();
                events.ScheduleEvent(EVENT_SUMMON_NOTE_FROM_VANESSA, Seconds(30));
                _activatedVentCounter = 0;
                _deadEnragedWorgen = 0;

                if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                    trapBunny->DespawnOrUnsummon(0, Seconds(30));

                if (Creature* anchorBunny = GetCreature(DATA_VANESSA_ANCHOR_BUNNY))
                    anchorBunny->DespawnOrUnsummon(0, Seconds(30));

                if (!_steamValveGuidSet.empty())
                    for (auto itr : _steamValveGuidSet)
                        if (Creature* creature = instance->GetCreature(itr))
                            creature->DespawnOrUnsummon();

                if (!_glubtokNightmareGuidSet.empty())
                    for (auto itr : _glubtokNightmareGuidSet)
                        if (Creature* creature = instance->GetCreature(itr))
                            creature->DespawnOrUnsummon();

                if (!_helixNightmareGuidSet.empty())
                    for (auto itr : _helixNightmareGuidSet)
                        if (Creature* creature = instance->GetCreature(itr))
                            creature->DespawnOrUnsummon();

                if (!_mechanicalNightmareGuidSet.empty())
                    for (auto itr : _mechanicalNightmareGuidSet)
                        if (Creature* creature = instance->GetCreature(itr))
                            creature->DespawnOrUnsummon();

                if (!_ripsnarlNightareGuidSet.empty())
                    for (auto itr : _ripsnarlNightareGuidSet)
                        if (Creature* creature = instance->GetCreature(itr))
                            creature->DespawnOrUnsummon();

                if (Creature* vanessa = GetCreature(DATA_VANESSA_VAN_CLEEF_NIGHTMARE))
                    vanessa->DespawnOrUnsummon();

                _steamValveGuidSet.clear();
                _glubtokNightmareGuidSet.clear();
                _helixNightmareGuidSet.clear();
                _mechanicalNightmareGuidSet.clear();
                _ripsnarlNightareGuidSet.clear();

                if (GameObject* foundryDoor = GetGameObject(DATA_FOUNDRY_DOOR))
                    foundryDoor->SetGoState(GO_STATE_ACTIVE);

                if (GameObject* foundryDoor = GetGameObject(DATA_IRON_CLAD_DOOR))
                    foundryDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        _teamInInstance = data;
                        SaveToDB();
                        break;
                    case DATA_FOE_REAPER_INTRO:
                        if (data == DONE)
                        {
                            if (Creature* reaper = GetCreature(DATA_FOE_REAPER_5000))
                            {
                                for (auto itr : _generalPurposeBunnyJMF2GuidSet)
                                {
                                    if (Creature* bunny = instance->GetCreature(itr))
                                        if (bunny->GetDistance2d(reaper->GetHomePosition().GetPositionX(), reaper->GetHomePosition().GetPositionY()) <= 15.0f)
                                            bunny->AI()->DoAction(ACTION_ELECTRICAL_CHARGE);
                                }
                            }
                        }
                        _foeReaper5000Intro = data;
                        SaveToDB();
                        break;
                    case DATA_BROKEN_DOOR:
                        _ironCladDoorState = data;
                        SaveToDB();
                        break;
                    case DATA_RIPSNARL_FOG:
                        if (data == IN_PROGRESS)
                        {
                            if (Creature* ripsnarl = GetCreature(DATA_ADMIRAL_RIPSNARL))
                                for (auto itr : _generalPurposeBunnyJMF2GuidSet)
                                {
                                    if (Creature* bunny = instance->GetCreature(itr))
                                        if (bunny->GetDistance2d(ripsnarl->GetHomePosition().GetPositionX(), ripsnarl->GetHomePosition().GetPositionY()) <= 100.0f)
                                            bunny->CastSpell(bunny, SPELL_FOG, true);
                                }
                        }
                        else if (data == NOT_STARTED)
                        {
                            for (auto itr : _generalPurposeBunnyJMF2GuidSet)
                            {
                                if (Creature* bunny = instance->GetCreature(itr))
                                    bunny->RemoveAllAuras();
                            }
                        }
                        break;
                    case DATA_VANESSA_VAN_CLEEF_ENCOUNTER:
                        _vanessaVanCleefEncounterState = data;
                        switch (_vanessaVanCleefEncounterState)
                        {
                            case IN_PROGRESS:
                                instance->SummonCreature(NPC_VANESSA_VAN_CLEEF_INTRO, vanessaVanCleefSpawnPos);
                                if (GameObject* foundryDoor = GetGameObject(DATA_FOUNDRY_DOOR))
                                    foundryDoor->SetGoState(GO_STATE_READY);

                                if (GameObject* foundryDoor = GetGameObject(DATA_IRON_CLAD_DOOR))
                                    foundryDoor->SetGoState(GO_STATE_READY);

                                break;
                            case FAIL:
                                ResetVanessasNightmare();
                                break;
                            case NIGHTMARE_STATE_PREPARE_TRAP:
                                if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                                    if (Creature* anchorBunny = GetCreature(DATA_VANESSA_ANCHOR_BUNNY))
                                        anchorBunny->CastSpell(trapBunny, SPELL_ROPE_BEAM, true);
                                break;
                            case NIGHTMARE_STAGE_MAGMA_TRAP:
                                if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                                    trapBunny->CastSpell(trapBunny, SPELL_RIDE_MAGMA_VEHICLE, true);
                                break;
                            case NIGHTMARE_STAGE_GLUBTOK:
                                events.ScheduleEvent(EVENT_CAST_NIGHTMARE_AURA_1, Seconds(4));
                                events.ScheduleEvent(EVENT_ANNOUNCE_NIGHTMARE_ELIXIR_TAKES_HOLD, Seconds(4) + Milliseconds(200));
                                break;
                            case NIGHTMARE_STAGE_HELIX:
                                events.CancelEvent(EVENT_SUMMON_ICICLES);
                                events.ScheduleEvent(EVENT_CAST_NIGHTMARE_AURA_2, Seconds(2) + Milliseconds(900));
                                break;
                            case NIGHTMARE_STAGE_FOE_REAPER:
                                events.ScheduleEvent(EVENT_DESPAWN_NIGHTMARE_SPIDERS, Seconds(2));
                                break;
                            case NIGHTMARE_STAGE_RIPSNARL:
                                events.ScheduleEvent(EVENT_CAST_NIGHTMARE_AURA_4, Seconds(2) + Milliseconds(500));
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_ACTIVATED_VENT:
                        _activatedVentCounter++;
                        if (_activatedVentCounter == 4)
                        {
                            for (auto itr : _steamValveGuidSet)
                                if (Creature* valve = instance->GetCreature(itr))
                                    valve->DespawnOrUnsummon(Seconds(10));

                            SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_GLUBTOK);
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                                trapBunny->AI()->DoAction(ACTION_EJECT_PLAYERS);
                        }
                        break;
                    case DATA_SUMMON_ROPES:
                    {
                        uint8 i = 0;
                        if (!_ropeAnchorPairs.empty())
                        {
                            for (auto itr = _ropeAnchorPairs.begin(); itr != _ropeAnchorPairs.end();)
                            {
                                if (!instance->GetCreature(itr->ropeGuid))
                                {
                                    if (Creature* anchor = instance->GetCreature(itr->anchorGuid))
                                    {
                                        if (Creature* rope = instance->SummonCreature(NPC_ROPE, itr->ropePosition))
                                        {
                                            anchor->CastSpell(rope, SPELL_ROPE_BEAM);
                                            _ropeAnchorPairs.push_back({ anchor->GetGUID(), rope->GetGUID(), itr->ropePosition });
                                        }
                                    }
                                    _ropeAnchorPairs.erase(itr);
                                    itr = _ropeAnchorPairs.begin();
                                }
                                else
                                    itr++;
                            }
                        }
                        else
                        {
                            for (auto itr = _anchorGuidSet.begin(); itr != _anchorGuidSet.end(); itr++, i++)
                            {
                                if (Creature* anchor = instance->GetCreature((*itr)))
                                {
                                    if (Creature* rope = instance->SummonCreature(NPC_ROPE, RopePos[i]))
                                    {
                                        anchor->CastSpell(rope, SPELL_ROPE_BEAM);
                                        _ropeAnchorPairs.push_back({ anchor->GetGUID(), rope->GetGUID(), RopePos[i] });
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return _teamInInstance;
                    case DATA_FOE_REAPER_INTRO:
                        return _foeReaper5000Intro;
                    case DATA_BROKEN_DOOR:
                        return _ironCladDoorState;
                    case DATA_VANESSA_VAN_CLEEF_ENCOUNTER:
                        return _vanessaVanCleefEncounterState;
                    default:
                        return 0;
                }
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_CAPTAIN_COOKIE:
                            if (Creature* cookie = instance->SummonCreature(BOSS_CAPTAIN_COOKIE, captainCookieSpawnPos))
                            {
                                if (_firstCookieSpawn)
                                {
                                    if (Creature* bunny = cookie->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 30.0f, true))
                                        bunny->AI()->Talk(SAY_ANNOUNCE_SHADOWY_FIGURE);
                                    _firstCookieSpawn = false;
                                }
                            }
                            break;
                        case EVENT_SUMMON_NOTE_FROM_VANESSA:
                            instance->SummonCreature(NPC_A_NOTE_FROM_VANESSA, noteFromVanessaSpawnPos);
                            break;
                        case EVENT_CAST_NIGHTMARE_AURA_1:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                            {
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                {
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_AURA, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_SLOW, true);
                                }
                            }
                            break;
                        case EVENT_ANNOUNCE_NIGHTMARE_ELIXIR_TAKES_HOLD:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_NIGHTMARE_ELIXIR_TAKES_HOLD);

                            events.ScheduleEvent(EVENT_SETUP_GLUBTOKS_NIGHTMARE, Milliseconds(600));
                            break;
                        case EVENT_SETUP_GLUBTOKS_NIGHTMARE:
                            instance->SummonCreature(NPC_VANESSA_VANCLEEF_NIGHTMARE, vanessaVanCleefNightmareSpawnPos[0]);
                            instance->SummonCreature(NPC_GLUBTOK_NIGHTMARE, GlubtokNightmareIntroSpawnPos);

                            for (uint8 i = 0; i < 32; i++)
                                instance->SummonCreature(NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY, glubtokNightmareFireBunnyPos[i]);

                            events.ScheduleEvent(EVENT_SUMMON_GLUBTOK, Seconds(14) + Milliseconds(400));
                            events.ScheduleEvent(EVENT_SUMMON_ICICLES, Seconds(14));
                            break;
                        case EVENT_SUMMON_ICICLES:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                            {
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                {
                                    std::list<Player*> playerList;
                                    purposeBunny->GetPlayerListInGrid(playerList, 100.0f);
                                    if (!playerList.empty())
                                        if (Player* target = Trinity::Containers::SelectRandomContainerElement(playerList))
                                            purposeBunny->CastSpell(target, SPELL_SUMMON_ICICLE, true);
                                }
                            }
                            events.Repeat(Seconds(3) - Milliseconds(600));
                            break;
                        case EVENT_SUMMON_GLUBTOK:
                            if (Creature* glubtok = instance->SummonCreature(NPC_GLUBTOK_NIGHTMARE, GlubtokNightmareSpawnPos))
                                glubtok->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                            break;
                        case EVENT_CAST_NIGHTMARE_AURA_2:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                            {
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                {
                                    purposeBunny->CastSpell(purposeBunny, SPELL_CANCEL_NIGHTMARE_AURA_GLUBTOK, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_AURA, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_SLOW, true);
                                }
                            }
                            events.ScheduleEvent(EVENT_ANNOUNCE_NIGHTMARE_SHIFTS, Milliseconds(200));
                            events.ScheduleEvent(EVENT_DESPAWN_NIGHTMARE_FIRE, Milliseconds(400));
                            break;
                        case EVENT_ANNOUNCE_NIGHTMARE_SHIFTS:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_NIGHTMARE_SHIFTS);
                            break;
                        case EVENT_DESPAWN_NIGHTMARE_FIRE:
                            for (auto itr : _glubtokNightmareGuidSet)
                            {
                                if (Creature* creature = instance->GetCreature(itr))
                                    if (creature->GetEntry() == NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY)
                                        creature->DespawnOrUnsummon();
                            }

                            events.ScheduleEvent(EVENT_SETUP_HELIX_NIGHTMARE, Seconds(2) + Milliseconds(800));
                            break;
                        case EVENT_SETUP_HELIX_NIGHTMARE:
                            instance->SummonCreature(NPC_VANESSA_VANCLEEF_NIGHTMARE, vanessaVanCleefNightmareSpawnPos[1]);
                            instance->SummonCreature(NPC_HELIX_GEARBREAKER_NIGHTMARE, HelixNightmareSpawnPos);
                            break;
                        case EVENT_DESPAWN_NIGHTMARE_SPIDERS:
                            for (auto itr : _helixNightmareGuidSet)
                            {
                                if (Creature* creature = instance->GetCreature(itr))
                                    if (creature->GetEntry() != NPC_HELIX_GEARBREAKER_NIGHTMARE)
                                        creature->DespawnOrUnsummon();
                            }
                            events.ScheduleEvent(EVENT_ANNOUNCE_NIGHTMARE_SHIFTS, Milliseconds(100));
                            events.ScheduleEvent(EVENT_CAST_NIGHTMARE_AURA_3, Milliseconds(200));
                            break;
                        case EVENT_CAST_NIGHTMARE_AURA_3:
                            if (Creature* trapBunny = GetCreature(DATA_VANESSAS_TRAP_BUNNY))
                            {
                                if (Creature* purposeBunny = trapBunny->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                {
                                    purposeBunny->CastSpell(purposeBunny, SPELL_CANCEL_NIGHTMARE_AURA_HELIX, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_AURA, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_SLOW, true);
                                }
                            }
                            events.ScheduleEvent(EVENT_SETUP_MECHANICAL_NIGHTMARE, Seconds(2) + Milliseconds(400));
                            break;
                        case EVENT_SETUP_MECHANICAL_NIGHTMARE:
                            if (GameObject* door = GetGameObject(DATA_FOUNDRY_DOOR))
                                door->SetGoState(GO_STATE_ACTIVE);
                            instance->SummonCreature(NPC_FOE_REAPER_5000_NIGHTMARE, FoeReaperNightmareIntroSpawnPos);
                            instance->SummonCreature(NPC_VANESSA_VANCLEEF_NIGHTMARE, vanessaVanCleefNightmareSpawnPos[2]);

                            for (uint8 i = 0; i < 6; i++)
                            {
                                if (Creature* platter = instance->SummonCreature(NPC_VANESSA_LIGHTNING_PLATTER, LightningPlatterPos[i]))
                                {
                                    bool clockwise = RAND(0, 1) == 1;
                                    platter->SetSpeed(MOVE_RUN, 0.25f);
                                    platter->GetMotionMaster()->MoveCirclePath(platter->GetPositionX(), platter->GetPositionY(), LightningPlatterCirclePathHeight[i], 0.95f, clockwise, 10);
                                }
                            }
                            events.ScheduleEvent(EVENT_SUMMON_FOE_REAPER, Seconds(9) + Milliseconds(500));
                            break;
                        case EVENT_SUMMON_FOE_REAPER:
                            if (Creature* reaper = instance->SummonCreature(NPC_FOE_REAPER_5000_NIGHTMARE, FoeReaperNightmareSpawnPos))
                            {
                                reaper->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                                reaper->RemoveAurasDueToSpell(SPELL_OFF_LINE);
                            }
                            break;
                        case EVENT_CAST_NIGHTMARE_AURA_4:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                            {
                                if (Creature* purposeBunny = door->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                {
                                    purposeBunny->CastSpell(purposeBunny, SPELL_CANCEL_NIGHTMARE_AURA_MECHANICAL, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_AURA, true);
                                    purposeBunny->CastSpell(purposeBunny, SPELL_NIGHTMARE_SLOW, true);
                                }
                            }
                            events.ScheduleEvent(EVENT_DESPAWN_LIGHTNING_PLATTERS, Milliseconds(50));
                            break;
                        case EVENT_DESPAWN_LIGHTNING_PLATTERS:
                            for (auto itr : _mechanicalNightmareGuidSet)
                            {
                                if (Creature* creature = instance->GetCreature(itr))
                                    if (creature->GetEntry() != NPC_FOE_REAPER_5000_NIGHTMARE)
                                        creature->DespawnOrUnsummon();
                            }
                            events.ScheduleEvent(EVENT_NIGHTMARE_SHIFTS_2, Milliseconds(150));
                            events.ScheduleEvent(EVENT_SETUP_RIPSNARL_NIGHTMARE, Seconds(2) + Milliseconds(600));
                            break;
                        case EVENT_SETUP_RIPSNARL_NIGHTMARE:
                            instance->SummonCreature(NPC_RIPSNARL_NIGHTMARE, RipsnarlNightmareIntroSpawnPos);
                            instance->SummonCreature(NPC_VANESSA_VANCLEEF_NIGHTMARE, vanessaVanCleefNightmareSpawnPos[3]);
                            events.ScheduleEvent(EVENT_OPEN_IRON_CLAD_DOOR, Seconds(14) + Milliseconds(400));
                            break;
                        case EVENT_NIGHTMARE_SHIFTS_2:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                                if (Creature* purposeBunny = door->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_NIGHTMARE_SHIFTS);
                            break;
                        case EVENT_OPEN_IRON_CLAD_DOOR:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                                door->SetGoState(GO_STATE_ACTIVE);

                            instance->SummonCreature(NPC_EMME_HARRINGTON, EmmeHarringtonSpawnPos);
                            for (uint8 i = 0; i < 3; i++)
                                instance->SummonCreature(NPC_ENRAGED_WORGEN, EnragedWorgenEmmeSpawnPos[i]);

                            events.ScheduleEvent(EVENT_ANNOUNCE_SAVE_EMME_HARRINGTON, Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_ANNOUNCE_SAVE_EMME_HARRINGTON:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                                if (Creature* purposeBunny = door->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 20.0f, true))
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_SAVE_EMME_HARRINGTON);
                            break;
                        case EVENT_ANNOUNCE_SAVE_ERIK_HARRINGTON:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                            {
                                if (Creature* purposeBunny = door->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 20.0f, true))
                                {
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_SAVE_ERIK_HARRINGTON);
                                    events.ScheduleEvent(EVENT_SUMMON_ERIK_HARRINGTON, Seconds(1) + Milliseconds(800));
                                }
                            }
                            break;
                        case EVENT_SUMMON_ERIK_HARRINGTON:
                            instance->SummonCreature(NPC_ERIK_HARRINGTON, ErikHarringtonSpawnPos);
                            for (uint8 i = 0; i < 3; i++)
                                instance->SummonCreature(NPC_ENRAGED_WORGEN, EnragedWorgenErikSpawnPos[i]);
                            break;
                        case EVENT_SUMMON_JAMES_HARRINGTON:
                            if (Creature* james = instance->SummonCreature(NPC_JAMES_HARRINGTON, JamesHarringtonSpawnPos))
                            {
                                if (Creature* calissa = instance->SummonCreature(NPC_CALISSA_HARRINGTON, CalissaHarringtonSpawnPos))
                                {
                                    james->SetReactState(REACT_PASSIVE);
                                    calissa->CastSpell(james, VEHICLE_SPELL_RIDE_HARDCODED, true);
                                    calissa->SetInCombatWith(james);
                                }
                            }
                            events.ScheduleEvent(EVENT_ANNOUNCE_SAVE_CALISSA_HARRINGTON, Seconds(3) + Milliseconds(400));
                            break;
                        case EVENT_ANNOUNCE_SAVE_CALISSA_HARRINGTON:
                            if (GameObject* door = GetGameObject(DATA_IRON_CLAD_DOOR))
                                if (Creature* purposeBunny = door->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 20.0f, true))
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_SAVE_CALISSA_HARRINGTON);
                            break;
                        case EVENT_ANNOUNCE_ELIXIR_WEARS_OFF:
                            if (Creature* calissa = GetCreature(DATA_CALISSA_HARRINGTON))
                                if (Creature* purposeBunny = calissa->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 100.0f, true))
                                {
                                    purposeBunny->AI()->Talk(SAY_ANNOUNCE_NIGHTMARE_ELIXIR_WEARS_OFF);
                                    calissa->DespawnOrUnsummon(Seconds(2) + Milliseconds(200));
                                }
                            events.ScheduleEvent(EVENT_SUMMON_VANESSA_VANCLEEF_BOSS, Seconds(2));
                            break;
                        case EVENT_SUMMON_VANESSA_VANCLEEF_BOSS:
                            instance->SummonCreature(BOSS_VANESSA_VAN_CLEEF, bossVanessaVanCleefSpawnPos);
                            break;
                        case EVENT_CHECK_DEAD_PLAYERS:
                        {
                            uint8 instancePlayersCount = instance->GetPlayersCountExceptGMs();
                            uint8 deadPlayersCount = 0;
                            Map::PlayerList const& players = instance->GetPlayers();

                            for (auto const& i : players)
                            {
                                if (Player* player = i.GetSource())
                                {
                                    if (player->IsGameMaster())
                                        continue;

                                    if (player->isDead())
                                        deadPlayersCount++;

                                    if (deadPlayersCount == instancePlayersCount)
                                        ResetVanessasNightmare();
                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _teamInInstance << ' '
                    << _foeReaper5000Intro << ' '
                    << _ironCladDoorState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _teamInInstance;
                data >> _foeReaper5000Intro;
                data >> _ironCladDoorState;
            }

        protected:
            struct RopeAnchorPair
            {
                ObjectGuid anchorGuid;
                ObjectGuid ropeGuid;
                Position ropePosition;
            };

            EventMap events;
            uint8 _activatedVentCounter;
            uint8 _deadEnragedWorgen;
            uint32 _teamInInstance;
            uint32 _foeReaper5000Intro;
            uint32 _ironCladDoorState;
            uint32 _vanessaVanCleefEncounterState;
            GuidSet _generalPurposeBunnyJMF2GuidSet;
            GuidSet _steamValveGuidSet;
            GuidSet _glubtokNightmareGuidSet;
            GuidSet _helixNightmareGuidSet;
            GuidSet _mechanicalNightmareGuidSet;
            GuidSet _ripsnarlNightareGuidSet;
            GuidSet _anchorGuidSet;
            std::vector<RopeAnchorPair> _ropeAnchorPairs;
            bool _firstCookieSpawn;
            bool _cookieSpawnChecked;
            bool _noteSpawnChecked;
            bool _ropesSpawned;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_deadmines_InstanceMapScript(map);
        }
};

void AddSC_instance_deadmines()
{
    new instance_deadmines();
}
