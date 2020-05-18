/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "blackrock_spire.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"

 //uint32 const DragonspireRunes[7] = { GO_HALL_RUNE_1, GO_HALL_RUNE_2, GO_HALL_RUNE_3, GO_HALL_RUNE_4, GO_HALL_RUNE_5, GO_HALL_RUNE_6, GO_HALL_RUNE_7 };

uint32 const DragonspireMobs[3] = { NPC_BLACKHAND_DREADWEAVER, NPC_BLACKHAND_SUMMONER, NPC_BLACKHAND_VETERAN };

DoorData const doorData[] =
{
    { GO_DOORS,                 DATA_PYROGAURD_EMBERSEER,   DOOR_TYPE_ROOM },
    { GO_EMBERSEER_OUT,         DATA_PYROGAURD_EMBERSEER,   DOOR_TYPE_PASSAGE },
    { GO_DRAKKISATH_DOOR_1,     DATA_GENERAL_DRAKKISATH,    DOOR_TYPE_PASSAGE },
    { GO_DRAKKISATH_DOOR_2,     DATA_GENERAL_DRAKKISATH,    DOOR_TYPE_PASSAGE },
    { 0,                        0,                          DOOR_TYPE_ROOM }
};

enum EventIds :uint32
{
    EVENT_DARGONSPIRE_ROOM_STORE = 1,
    EVENT_DARGONSPIRE_ROOM_CHECK = 2,
    EVENT_UROK_DOOMHOWL_SPAWNS_1 = 3,
    EVENT_UROK_DOOMHOWL_SPAWNS_2 = 4,
    EVENT_UROK_DOOMHOWL_SPAWNS_3 = 5,
    EVENT_UROK_DOOMHOWL_SPAWNS_4 = 6,
    EVENT_UROK_DOOMHOWL_SPAWNS_5 = 7,
    EVENT_UROK_DOOMHOWL_SPAWN_IN = 8,
    // EJ blackrock scripts
    EVENT_STADIUM_RESET,
    EVENT_STADIUM_READY,
    EVENT_UPPER_DOOR_OPEN_STEP_1,
    EVENT_UPPER_DOOR_OPEN_STEP_2,
    EVENT_UPPER_DOOR_OPEN_STEP_3,
    EVENT_UPPER_DOOR_OPEN_STEP_4,
    EVENT_STADIUM_QUIT_LINE,
    EVENT_STADIUM_QUIT_MOVE,
    EVENT_STADIUM_CLOSE_DOOR,
    EVENT_STADIUM_OPEN_DOOR,
    EVENT_TOBOSS_OPEN_DOOR,
    EVENT_STADIUM_FAIL_LINE,
    EVENT_STADIUM_FAIL_MOVE,
};

class instance_blackrock_spire : public InstanceMapScript
{
public:
    instance_blackrock_spire() : InstanceMapScript(BRSScriptName, 229) { }

    struct instance_blackrock_spireMapScript : public InstanceScript
    {
        instance_blackrock_spireMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            stadiumCombatStatus = StadiumCombatStatus::SCS_FREE;            
            upperDoorCheckDelay = 1000;
            rendDead = false;
            gythDead = false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_HIGHLORD_OMOKK:
                HighlordOmokk = creature->GetGUID();
                break;
            case NPC_SHADOW_HUNTER_VOSHGAJIN:
                ShadowHunterVoshgajin = creature->GetGUID();
                break;
            case NPC_WARMASTER_VOONE:
                WarMasterVoone = creature->GetGUID();
                break;
            case NPC_MOTHER_SMOLDERWEB:
                MotherSmolderweb = creature->GetGUID();
                break;
            case NPC_UROK_DOOMHOWL:
            {                
                UrokDoomhowl = creature->GetGUID();                
                break;
            }
            case BRSCreaturesIds::NPC_Urok_Enforcer:
            {
                std::list<Player*> players;
                Trinity::AnyPlayerInObjectRangeCheck checker(creature, VISIBILITY_DISTANCE_SMALL);
                Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(creature, players, checker);
                Cell::VisitWorldObjects(creature, searcher, VISIBILITY_DISTANCE_SMALL);
                bool allDead = true;
                for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* eachP = *itr;
                    if (creature->CanSeeOrDetect(eachP))
                    {
                        if (creature->GetDistance(eachP) < creature->GetAttackDistance(eachP))
                        {
                            creature->EngageWithTarget(eachP);
                            break;
                        }
                    }
                }
                break;
            }
            case BRSCreaturesIds::NPC_Urok_Ogre_Magus:
            {
                std::list<Player*> players;
                Trinity::AnyPlayerInObjectRangeCheck checker(creature, VISIBILITY_DISTANCE_SMALL);
                Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(creature, players, checker);
                Cell::VisitWorldObjects(creature, searcher, VISIBILITY_DISTANCE_SMALL);
                bool allDead = true;
                for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* eachP = *itr;
                    if (creature->CanSeeOrDetect(eachP))
                    {
                        if (creature->GetDistance(eachP) < creature->GetAttackDistance(eachP))
                        {
                            creature->EngageWithTarget(eachP);
                            break;
                        }
                    }
                }
                break;
            }
            case NPC_QUARTERMASTER_ZIGRIS:
                QuartermasterZigris = creature->GetGUID();
                break;
            case NPC_GIZRUL_THE_SLAVENER:
                GizrultheSlavener = creature->GetGUID();
                break;
            case NPC_HALYCON:
                Halycon = creature->GetGUID();
                break;
            case NPC_OVERLORD_WYRMTHALAK:
                OverlordWyrmthalak = creature->GetGUID();
                break;
            case NPC_PYROGAURD_EMBERSEER:
                PyroguardEmberseer = creature->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    creature->DespawnOrUnsummon(0, 24h * 7);
                break;
            case NPC_WARCHIEF_REND_BLACKHAND:
                WarchiefRendBlackhand = creature->GetGUID();
                if (GetBossState(DATA_GYTH) == DONE)
                    creature->DespawnOrUnsummon(0, 24h * 7);
                break;
            case NPC_GYTH:
                Gyth = creature->GetGUID();
                break;
            case NPC_THE_BEAST:
                TheBeast = creature->GetGUID();
                break;
            case NPC_GENERAL_DRAKKISATH:
                GeneralDrakkisath = creature->GetGUID();
                break;
            case NPC_LORD_VICTOR_NEFARIUS:
                LordVictorNefarius = creature->GetGUID();
                if (GetBossState(DATA_GYTH) == DONE)
                    creature->DespawnOrUnsummon(0, 24h * 7);
                break;
            case NPC_SCARSHIELD_INFILTRATOR:
                ScarshieldInfiltrator = creature->GetGUID();
                break;
            case NPC_FINKLE_EINHORN:
                creature->AI()->Talk(SAY_FINKLE_GANG);
                break;
                case NPC_BLACKHAND_INCARCERATOR:
                    _incarceratorList.push_back(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_WHELP_SPAWNER:
                go->CastSpell(nullptr, SPELL_SUMMON_ROOKERY_WHELP);
                break;
            case GO_EMBERSEER_IN:
                go_emberseerin = go->GetGUID();
                if (GetBossState(DATA_DRAGONSPIRE_ROOM) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_DOORS:
                go_doors = go->GetGUID();
                if (GetBossState(DATA_DRAGONSPIRE_ROOM) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_EMBERSEER_OUT:
                go_emberseerout = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_HALL_RUNE_1:
                go_roomrunes[0] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_1) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_2:
                go_roomrunes[1] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_2) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_3:
                go_roomrunes[2] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_3) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_4:
                go_roomrunes[3] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_4) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_5:
                go_roomrunes[4] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_5) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_6:
                go_roomrunes[5] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_6) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_HALL_RUNE_7:
                go_roomrunes[6] = go->GetGUID();
                if (GetBossState(DATA_HALL_RUNE_7) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_1:
                go_emberseerrunes[0] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_2:
                go_emberseerrunes[1] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                {
                    HandleGameObject(ObjectGuid::Empty, false, go);
                }
                break;
            case GO_EMBERSEER_RUNE_3:
                go_emberseerrunes[2] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_4:
                go_emberseerrunes[3] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_5:
                go_emberseerrunes[4] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_6:
                go_emberseerrunes[5] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_EMBERSEER_RUNE_7:
                go_emberseerrunes[6] = go->GetGUID();
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                    HandleGameObject(ObjectGuid::Empty, false, go);
                break;
            case GO_PORTCULLIS_ACTIVE:
                go_portcullis_active = go->GetGUID();
                //if (GetBossState(DATA_GYTH) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_PORTCULLIS_TOBOSSROOMS:
                go_portcullis_tobossrooms = go->GetGUID();
                if (GetBossState(DATA_GYTH) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_01:
            {
                OGGODoodadDarkIronBrazier01 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_02:
            {
                OGGODoodadDarkIronBrazier02 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_03:
            {
                OGGODoodadDarkIronBrazier03 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_04:
            {
                OGGODoodadDarkIronBrazier04 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_05:
            {
                OGGODoodadDarkIronBrazier05 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DOODAD_DARKIRON_BRAZIER_06:
            {
                OGGODoodadDarkIronBrazier06 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case BRSGameObjectsIds::GO_DRAGONSPINE_DOOR:
            {
                OGGODragonspineDoor = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
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
            case DATA_HIGHLORD_OMOKK:
            case DATA_SHADOW_HUNTER_VOSHGAJIN:
            case DATA_WARMASTER_VOONE:
            case DATA_MOTHER_SMOLDERWEB:
            case DATA_UROK_DOOMHOWL:
            case DATA_QUARTERMASTER_ZIGRIS:
            case DATA_GIZRUL_THE_SLAVENER:
            case DATA_HALYCON:
            case DATA_OVERLORD_WYRMTHALAK:
            case DATA_PYROGAURD_EMBERSEER:
            case DATA_WARCHIEF_REND_BLACKHAND:
            case DATA_GYTH:
            case DATA_THE_BEAST:
            case DATA_GENERAL_DRAKKISATH:
            case DATA_DRAGONSPIRE_ROOM:
                break;
            default:
                break;
            }

            return true;
        }

        void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
        {
            switch (eventId)
            {
            case EVENT_PYROGUARD_EMBERSEER:
                if (GetBossState(DATA_PYROGAURD_EMBERSEER) == NOT_STARTED)
                {
                    if (Creature* Emberseer = instance->GetCreature(PyroguardEmberseer))
                        Emberseer->AI()->SetData(1, 1);
                }
                break;
            case EVENT_UROK_DOOMHOWL:
                if (GetBossState(NPC_UROK_DOOMHOWL) == NOT_STARTED)
                {

                }
                break;
            default:
                break;
            }
        }

        uint32 GetData(uint32 DataId) const override
        {
            switch (DataId)
            {
            case BRSAdditionalData::STADIUM_COMBAT:
            {
                return stadiumCombatStatus;
            }
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case AREATRIGGER:
            {
                if (data == AREATRIGGER_DRAGONSPIRE_HALL)
                {
                    if (GetBossState(DATA_DRAGONSPIRE_ROOM) != DONE)
                    {
                        Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_STORE, 1s);
                    }
                }
                break;
            }
            case DATA_BLACKHAND_INCARCERATOR:
            {
                for (GuidList::const_iterator itr = _incarceratorList.begin(); itr != _incarceratorList.end(); ++itr)
                    if (Creature* creature = instance->GetCreature(*itr))
                        creature->Respawn();
                break;
            }
            case BRSAdditionalData::STADIUM_COMBAT:
            {
                stadiumCombatStatus = data;
                if (stadiumCombatStatus == StadiumCombatStatus::SCS_GOING)
                {
                    Events.ScheduleEvent(EventIds::EVENT_STADIUM_CLOSE_DOOR, 5000);
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_HIGHLORD_OMOKK:
                return HighlordOmokk;
            case DATA_SHADOW_HUNTER_VOSHGAJIN:
                return ShadowHunterVoshgajin;
            case DATA_WARMASTER_VOONE:
                return WarMasterVoone;
            case DATA_MOTHER_SMOLDERWEB:
                return MotherSmolderweb;
            case DATA_UROK_DOOMHOWL:
                return UrokDoomhowl;
            case DATA_QUARTERMASTER_ZIGRIS:
                return QuartermasterZigris;
            case DATA_GIZRUL_THE_SLAVENER:
                return GizrultheSlavener;
            case DATA_HALYCON:
                return Halycon;
            case DATA_OVERLORD_WYRMTHALAK:
                return OverlordWyrmthalak;
            case DATA_PYROGAURD_EMBERSEER:
                return PyroguardEmberseer;
            case DATA_WARCHIEF_REND_BLACKHAND:
                return WarchiefRendBlackhand;
            case DATA_GYTH:
                return Gyth;
            case DATA_THE_BEAST:
                return TheBeast;
            case DATA_GENERAL_DRAKKISATH:
                return GeneralDrakkisath;
            case DATA_SCARSHIELD_INFILTRATOR:
                return ScarshieldInfiltrator;
            case GO_EMBERSEER_IN:
                return go_emberseerin;
            case GO_DOORS:
                return go_doors;
            case GO_EMBERSEER_OUT:
                return go_emberseerout;
            case GO_HALL_RUNE_1:
                return go_roomrunes[0];
            case GO_HALL_RUNE_2:
                return go_roomrunes[1];
            case GO_HALL_RUNE_3:
                return go_roomrunes[2];
            case GO_HALL_RUNE_4:
                return go_roomrunes[3];
            case GO_HALL_RUNE_5:
                return go_roomrunes[4];
            case GO_HALL_RUNE_6:
                return go_roomrunes[5];
            case GO_HALL_RUNE_7:
                return go_roomrunes[6];
            case GO_EMBERSEER_RUNE_1:
                return go_emberseerrunes[0];
            case GO_EMBERSEER_RUNE_2:
                return go_emberseerrunes[1];
            case GO_EMBERSEER_RUNE_3:
                return go_emberseerrunes[2];
            case GO_EMBERSEER_RUNE_4:
                return go_emberseerrunes[3];
            case GO_EMBERSEER_RUNE_5:
                return go_emberseerrunes[4];
            case GO_EMBERSEER_RUNE_6:
                return go_emberseerrunes[5];
            case GO_EMBERSEER_RUNE_7:
                return go_emberseerrunes[6];
            case GO_PORTCULLIS_ACTIVE:
                return go_portcullis_active;
            case GO_PORTCULLIS_TOBOSSROOMS:
                return go_portcullis_tobossrooms;
            default:
                break;
            }
            return ObjectGuid::Empty;
        }

        void OnUnitDeath(Unit* unit) override
        {
            //! HACK, needed because of buggy CreatureAI after charm
            if (unit->GetEntry() == BRSCreaturesIds::NPC_WARCHIEF_REND_BLACKHAND)
            {
                rendDead = true;
            }
            if (unit->GetEntry() == BRSCreaturesIds::NPC_GYTH)
            {
                gythDead = true;
            }
            if (stadiumCombatStatus == StadiumCombatStatus::SCS_GOING)
            {
                if (rendDead && gythDead)
                {
                    stadiumCombatStatus = StadiumCombatStatus::SCS_VICTORY;
                }
            }            
        }

        void Update(uint32 diff) override
        {
            if (GameObject* checkDD = instance->GetGameObject(OGGODragonspineDoor))
            {
                if (checkDD->GetGoState() != GOState::GO_STATE_ACTIVE)
                {
                    upperDoorCheckDelay -= diff;
                    if (upperDoorCheckDelay < 0)
                    {
                        upperDoorCheckDelay = 1000;
                        Position checkP;
                        checkP.m_positionX = 99.0;
                        checkP.m_positionY = -319.0f;
                        checkP.m_positionZ = 65.5f;
                        bool openDoor = false;
                        for (MapReference const& ref : instance->GetPlayers())
                        {
                            if (Player* player = ref.GetSource())
                            {
                                if (player->HasItemCount(BRSAdditionalData::ITEM_SEAL_OF_ASCENSION, 1))
                                {
                                    if (player->GetDistance(checkP) < 2.0f)
                                    {
                                        openDoor = true;
                                        break;
                                    }
                                    if (player->GetDistance(checkDD) < 5.0f)
                                    {
                                        openDoor = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (openDoor)
                        {
                            upperDoorCheckDelay = 50000;
                            Events.ScheduleEvent(EventIds::EVENT_UPPER_DOOR_OPEN_STEP_1, 100);
                            Events.ScheduleEvent(EventIds::EVENT_UPPER_DOOR_OPEN_STEP_2, 1000);
                            Events.ScheduleEvent(EventIds::EVENT_UPPER_DOOR_OPEN_STEP_3, 2000);
                            Events.ScheduleEvent(EventIds::EVENT_UPPER_DOOR_OPEN_STEP_4, 3000);
                        }
                    }
                }
            }

            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DARGONSPIRE_ROOM_STORE:
                    Dragonspireroomstore();
                    Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_CHECK, 3s);
                    break;
                case EVENT_DARGONSPIRE_ROOM_CHECK:
                    Dragonspireroomcheck();
                    if ((GetBossState(DATA_DRAGONSPIRE_ROOM) != DONE))
                        Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_CHECK, 3s);
                    break;
                case EventIds::EVENT_STADIUM_RESET:
                {
                    rendDead = false;
                    gythDead = false;
                    if (GameObject* addsGate = instance->GetGameObjectBySpawnId(BRSSPawnID::BRSSPawnID_GO_STADIUM_ADDS_GATE))
                    {
                        addsGate->SetGoState(GOState::GO_STATE_READY);
                    }
                    if (Creature* victor = instance->GetCreature(LordVictorNefarius))
                    {
                        victor->AI()->Reset();
                        victor->DespawnOrUnsummon(500, 2s);
                    }
                    if (Creature* rend = instance->GetCreature(WarchiefRendBlackhand))
                    {
                        rend->AI()->Reset();
                        if (TempSummon* summon = rend->ToTempSummon())
                        {
                            summon->UnSummon(100);
                            RespawnInfo* riRend = instance->GetRespawnInfo(SpawnObjectType::SPAWN_TYPE_CREATURE, BRSSPawnID::BRSSPawnID_CREATURE_WARCHIEF_REND_BLACKHAND);
                            riRend->respawnTime = 2000;
                            instance->Respawn(riRend);
                        }
                        else
                        {
                            rend->DespawnOrUnsummon(500, 2s);
                        }
                    }
                    else
                    {
                        RespawnInfo* riRend = instance->GetRespawnInfo(SpawnObjectType::SPAWN_TYPE_CREATURE, BRSSPawnID::BRSSPawnID_CREATURE_WARCHIEF_REND_BLACKHAND);
                        riRend->respawnTime = 2000;
                        instance->Respawn(riRend);
                    }
                    if (Creature* gyth = instance->GetCreature(Gyth))
                    {
                        gyth->AI()->Reset();
                        gyth->DespawnOrUnsummon();
                    }
                    Events.ScheduleEvent(EventIds::EVENT_STADIUM_READY, 5000);
                    break;
                }
                case EventIds::EVENT_STADIUM_READY:
                {
                    stadiumCombatStatus = StadiumCombatStatus::SCS_FREE;
                    break;
                }
                case EventIds::EVENT_STADIUM_CLOSE_DOOR:
                {
                    if (GameObject* stadiumDoor = instance->GetGameObject(go_portcullis_active))
                    {
                        stadiumDoor->SetGoState(GOState::GO_STATE_READY);
                    }
                    break;
                }
                case EventIds::EVENT_STADIUM_OPEN_DOOR:
                {
                    if (GameObject* stadiumDoor = instance->GetGameObject(go_portcullis_active))
                    {
                        stadiumDoor->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case EventIds::EVENT_TOBOSS_OPEN_DOOR:
                {
                    if (GameObject* tobossDoor = instance->GetGameObject(go_portcullis_tobossrooms))
                    {
                        tobossDoor->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case EventIds::EVENT_STADIUM_FAIL_LINE:
                {
                    if (Creature* victor = instance->GetCreature(LordVictorNefarius))
                    {
                        victor->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        victor->AI()->Talk(SAY_NEFARIUS_11);
                    }
                    break;
                }
                case EventIds::EVENT_STADIUM_QUIT_LINE:
                {
                    if (Creature* victor = instance->GetCreature(LordVictorNefarius))
                    {
                        victor->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                        victor->AI()->Talk(SAY_NEFARIUS_10);
                    }
                    break;
                }
                case EventIds::EVENT_STADIUM_QUIT_MOVE:
                {
                    if (Creature* victor = instance->GetCreature(LordVictorNefarius))
                    {
                        victor->SetWalk(true);
                        victor->GetMotionMaster()->MovePoint(0, 165.74f, -466.46f, 116.80f);
                        victor->DespawnOrUnsummon(10000, 24h * 7);
                    }
                    break;
                }
                case EventIds::EVENT_UPPER_DOOR_OPEN_STEP_1:
                {
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier01))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier02))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case EventIds::EVENT_UPPER_DOOR_OPEN_STEP_2:
                {
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier03))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier04))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case EventIds::EVENT_UPPER_DOOR_OPEN_STEP_3:
                {
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier05))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    if (GameObject* checkGO = instance->GetGameObject(OGGODoodadDarkIronBrazier06))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case EventIds::EVENT_UPPER_DOOR_OPEN_STEP_4:
                {
                    if (GameObject* checkGO = instance->GetGameObject(OGGODragonspineDoor))
                    {
                        checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                default:
                    break;
                }
            }

            switch (stadiumCombatStatus)
            {
            case StadiumCombatStatus::SCS_FREE:
            {
                break;
            }
            case StadiumCombatStatus::SCS_GOING:
            {
                if (Creature* victor = instance->GetCreature(LordVictorNefarius))
                {
                    std::list<Player*> players;
                    Trinity::AnyPlayerInObjectRangeCheck checker(victor, 200.0f);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(victor, players, checker);
                    Cell::VisitWorldObjects(victor, searcher, 200.0f);
                    bool allDead = true;
                    for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* eachPlayer = *itr)
                        {
                            if (eachPlayer->IsAlive())
                            {
                                allDead = false;
                                break;
                            }
                        }
                    }
                    if (allDead)
                    {
                        stadiumCombatStatus = StadiumCombatStatus::SCS_FAILED;
                    }
                }
                break;
            }
            case StadiumCombatStatus::SCS_FAILED:
            {                
                Events.ScheduleEvent(EventIds::EVENT_STADIUM_FAIL_LINE, 3000);
                Events.ScheduleEvent(EVENT_STADIUM_RESET, 10000);
                Events.ScheduleEvent(EventIds::EVENT_STADIUM_OPEN_DOOR, 15000);
                stadiumCombatStatus = StadiumCombatStatus::SCS_RESET;
                break;
            }
            case StadiumCombatStatus::SCS_VICTORY:
            {
                SetBossState(DATA_WARCHIEF_REND_BLACKHAND, EncounterState::DONE);
                SetBossState(DATA_GYTH, EncounterState::DONE);                
                Events.ScheduleEvent(EventIds::EVENT_STADIUM_QUIT_LINE, 3000);
                Events.ScheduleEvent(EventIds::EVENT_STADIUM_QUIT_MOVE, 10000);
                Events.ScheduleEvent(EventIds::EVENT_STADIUM_OPEN_DOOR, 15000);
                Events.ScheduleEvent(EventIds::EVENT_TOBOSS_OPEN_DOOR, 17000);
                stadiumCombatStatus = StadiumCombatStatus::SCS_DONE;
                break;
            }
            case StadiumCombatStatus::SCS_RESET:
            {
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void Dragonspireroomstore()
        {
            uint8 creatureCount;

            for (uint8 i = 0; i < 7; ++i)
            {
                creatureCount = 0;

                if (GameObject* rune = instance->GetGameObject(go_roomrunes[i]))
                {
                    for (uint8 j = 0; j < 3; ++j)
                    {
                        std::list<Creature*> creatureList;
                        GetCreatureListWithEntryInGrid(creatureList, rune, DragonspireMobs[j], 15.0f);
                        for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                        {
                            if (Creature* creature = *itr)
                            {
                                runecreaturelist[i][creatureCount] = creature->GetGUID();
                                ++creatureCount;
                            }
                        }
                    }
                }
            }
        }

        void Dragonspireroomcheck()
        {
            Creature* mob = nullptr;
            GameObject* rune = nullptr;

            for (uint8 i = 0; i < 7; ++i)
            {
                bool _mobAlive = false;
                rune = instance->GetGameObject(go_roomrunes[i]);
                if (!rune)
                    continue;

                if (rune->GetGoState() == GO_STATE_ACTIVE)
                {
                    for (uint8 ii = 0; ii < 5; ++ii)
                    {
                        mob = instance->GetCreature(runecreaturelist[i][ii]);
                        if (mob && mob->IsAlive())
                            _mobAlive = true;
                    }
                }

                if (!_mobAlive && rune->GetGoState() == GO_STATE_ACTIVE)
                {
                    HandleGameObject(ObjectGuid::Empty, false, rune);

                    switch (rune->GetEntry())
                    {
                    case GO_HALL_RUNE_1:
                        SetBossState(DATA_HALL_RUNE_1, DONE);
                        break;
                    case GO_HALL_RUNE_2:
                        SetBossState(DATA_HALL_RUNE_2, DONE);
                        break;
                    case GO_HALL_RUNE_3:
                        SetBossState(DATA_HALL_RUNE_3, DONE);
                        break;
                    case GO_HALL_RUNE_4:
                        SetBossState(DATA_HALL_RUNE_4, DONE);
                        break;
                    case GO_HALL_RUNE_5:
                        SetBossState(DATA_HALL_RUNE_5, DONE);
                        break;
                    case GO_HALL_RUNE_6:
                        SetBossState(DATA_HALL_RUNE_6, DONE);
                        break;
                    case GO_HALL_RUNE_7:
                        SetBossState(DATA_HALL_RUNE_7, DONE);
                        break;
                    default:
                        break;
                    }
                }
            }

            if (GetBossState(DATA_HALL_RUNE_1) == DONE && GetBossState(DATA_HALL_RUNE_2) == DONE && GetBossState(DATA_HALL_RUNE_3) == DONE &&
                GetBossState(DATA_HALL_RUNE_4) == DONE && GetBossState(DATA_HALL_RUNE_5) == DONE && GetBossState(DATA_HALL_RUNE_6) == DONE &&
                GetBossState(DATA_HALL_RUNE_7) == DONE)
            {
                SetBossState(DATA_DRAGONSPIRE_ROOM, DONE);
                if (GameObject* door1 = instance->GetGameObject(go_emberseerin))
                    HandleGameObject(ObjectGuid::Empty, true, door1);
                if (GameObject* door2 = instance->GetGameObject(go_doors))
                    HandleGameObject(ObjectGuid::Empty, true, door2);
            }
        }

    protected:
        EventMap Events;
        ObjectGuid HighlordOmokk;
        ObjectGuid ShadowHunterVoshgajin;
        ObjectGuid WarMasterVoone;
        ObjectGuid MotherSmolderweb;
        ObjectGuid UrokDoomhowl;
        ObjectGuid QuartermasterZigris;
        ObjectGuid GizrultheSlavener;
        ObjectGuid Halycon;
        ObjectGuid OverlordWyrmthalak;
        ObjectGuid PyroguardEmberseer;
        ObjectGuid WarchiefRendBlackhand;
        ObjectGuid Gyth;
        ObjectGuid LordVictorNefarius;
        ObjectGuid TheBeast;
        ObjectGuid GeneralDrakkisath;
        ObjectGuid ScarshieldInfiltrator;
        ObjectGuid go_emberseerin;
        ObjectGuid go_doors;
        ObjectGuid go_emberseerout;
        ObjectGuid go_blackrockaltar;
        ObjectGuid go_roomrunes[7];
        ObjectGuid go_emberseerrunes[7];
        ObjectGuid runecreaturelist[7][5];
        ObjectGuid go_portcullis_active;
        ObjectGuid go_portcullis_tobossrooms;
            GuidList _incarceratorList;
        ObjectGuid OGGODoodadDarkIronBrazier01;
        ObjectGuid OGGODoodadDarkIronBrazier02;
        ObjectGuid OGGODoodadDarkIronBrazier03;
        ObjectGuid OGGODoodadDarkIronBrazier04;
        ObjectGuid OGGODoodadDarkIronBrazier05;
        ObjectGuid OGGODoodadDarkIronBrazier06;

        ObjectGuid OGGODragonspineDoor;

    private:
        uint32 stadiumCombatStatus;
        int upperDoorCheckDelay;
        bool rendDead;
        bool gythDead;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_blackrock_spireMapScript(map);
    }
};

/*#####
# at_dragonspire_hall
#####*/

class at_dragonspire_hall : public AreaTriggerScript
{
public:
    at_dragonspire_hall() : AreaTriggerScript("at_dragonspire_hall") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player && player->IsAlive())
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                instance->SetData(AREATRIGGER, AREATRIGGER_DRAGONSPIRE_HALL);
                return true;
            }
        }

        return false;
    }
};

/*#####
# at_blackrock_stadium
#####*/

class at_blackrock_stadium : public AreaTriggerScript
{
public:
    at_blackrock_stadium() : AreaTriggerScript("at_blackrock_stadium") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player && player->IsAlive())
        {
            if (InstanceScript* is = player->GetInstanceScript())
            {
                if (Creature* rend = player->FindNearestCreature(NPC_WARCHIEF_REND_BLACKHAND, 50.0f))
                {
                    if (is->GetData(BRSAdditionalData::STADIUM_COMBAT) == StadiumCombatStatus::SCS_FREE)
                    {
                        is->SetData(BRSAdditionalData::STADIUM_COMBAT, StadiumCombatStatus::SCS_GOING);
                        rend->AI()->SetData(AREATRIGGER, AREATRIGGER_BLACKROCK_STADIUM);
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class at_nearby_scarshield_infiltrator : public AreaTriggerScript
{
public:
    at_nearby_scarshield_infiltrator() : AreaTriggerScript("at_nearby_scarshield_infiltrator") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (Creature* infiltrator = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_SCARSHIELD_INFILTRATOR)))
                {
                    if (player->GetLevel() >= 57)
                        infiltrator->AI()->SetData(1, 1);
                    else if (infiltrator->GetEntry() == NPC_SCARSHIELD_INFILTRATOR)
                        infiltrator->AI()->Talk(0, player);

                    return true;
                }
            }
        }

        return false;
    }
};

void AddSC_instance_blackrock_spire()
{
    new instance_blackrock_spire();
    new at_dragonspire_hall();
    new at_blackrock_stadium();
    new at_nearby_scarshield_infiltrator();
}
