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

static std::array<uint32, 3> DragonspireMobs =
{
    NPC_BLACKHAND_DREADWEAVER,
    NPC_BLACKHAND_SUMMONER,
    NPC_BLACKHAND_VETERAN
};

DoorData const doorData[] =
{
    { GO_DOORS,                 DATA_PYROGAURD_EMBERSEER,   DOOR_TYPE_ROOM },
    { GO_EMBERSEER_OUT,         DATA_PYROGAURD_EMBERSEER,   DOOR_TYPE_PASSAGE },
    { GO_DRAKKISATH_DOOR_1,     DATA_GENERAL_DRAKKISATH,    DOOR_TYPE_PASSAGE },
    { GO_DRAKKISATH_DOOR_2,     DATA_GENERAL_DRAKKISATH,    DOOR_TYPE_PASSAGE },
    { 0,                        0,                          DOOR_TYPE_ROOM }
};

enum EventIds
{
    EVENT_DARGONSPIRE_ROOM_STORE           = 1,
    EVENT_DARGONSPIRE_ROOM_CHECK           = 2,
    EVENT_UROK_DOOMHOWL_SPAWNS_1           = 3,
    EVENT_UROK_DOOMHOWL_SPAWNS_2           = 4,
    EVENT_UROK_DOOMHOWL_SPAWNS_3           = 5,
    EVENT_UROK_DOOMHOWL_SPAWNS_4           = 6,
    EVENT_UROK_DOOMHOWL_SPAWNS_5           = 7,
    EVENT_UROK_DOOMHOWL_SPAWN_IN           = 8
};

static constexpr uint8 MAX_ROOM_RUNES = 7;

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
                    UrokDoomhowl = creature->GetGUID();
                    break;
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
                        creature->DespawnOrUnsummon(0s, 7_days);
                    break;
                case NPC_WARCHIEF_REND_BLACKHAND:
                    WarchiefRendBlackhand = creature->GetGUID();
                    if (GetBossState(DATA_GYTH) == DONE)
                        creature->DespawnOrUnsummon(0s, 7_days);
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
                        creature->DespawnOrUnsummon(0s, 7_days);
                    break;
                case NPC_SCARSHIELD_INFILTRATOR:
                    ScarshieldInfiltrator = creature->GetGUID();
                    break;
                case NPC_FINKLE_EINHORN: // @todo: move this either to SAI or CreatureAI
                    if (creature->IsAIEnabled())
                        creature->AI()->Talk(SAY_FINKLE_GANG);
                    break;
                case NPC_BLACKHAND_INCARCERATOR:
                    _incarceratorGUIDs.push_back(creature->GetGUID());
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
                    _roomRuneGUIDs[0] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_1) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_2:
                    _roomRuneGUIDs[1] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_2) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_3:
                    _roomRuneGUIDs[2] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_3) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_4:
                    _roomRuneGUIDs[3] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_4) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_5:
                    _roomRuneGUIDs[4] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_5) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_6:
                    _roomRuneGUIDs[5] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_6) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_HALL_RUNE_7:
                    _roomRuneGUIDs[6] = go->GetGUID();
                    if (GetBossState(DATA_HALL_RUNE_7) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_1:
                    _emberseeingRuneGUIDs[0] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_2:
                    _emberseeingRuneGUIDs[1] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_3:
                    _emberseeingRuneGUIDs[2] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_4:
                    _emberseeingRuneGUIDs[3] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_5:
                    _emberseeingRuneGUIDs[4] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_6:
                    _emberseeingRuneGUIDs[5] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_EMBERSEER_RUNE_7:
                    _emberseeingRuneGUIDs[6] = go->GetGUID();
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_PORTCULLIS_ACTIVE:
                    go_portcullis_active = go->GetGUID();
                    if (GetBossState(DATA_GYTH) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_PORTCULLIS_TOBOSSROOMS:
                    go_portcullis_tobossrooms = go->GetGUID();
                    if (GetBossState(DATA_GYTH) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
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
                        if (Creature* emberseer = instance->GetCreature(PyroguardEmberseer))
                            if (emberseer->IsAIEnabled())
                                emberseer->AI()->SetData(1, 1);
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

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case AREATRIGGER:
                    if (data == AREATRIGGER_DRAGONSPIRE_HALL)
                    {
                        if (GetBossState(DATA_DRAGONSPIRE_ROOM) != DONE)
                            Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_STORE, 1s);
                    }
                    break;
                case DATA_BLACKHAND_INCARCERATOR:
                    for (ObjectGuid const& guid: _incarceratorGUIDs)
                        if (Creature* creature = instance->GetCreature(guid))
                            creature->Respawn();
                    break;
                default:
                    break;
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
                    return _roomRuneGUIDs[0];
                case GO_HALL_RUNE_2:
                    return _roomRuneGUIDs[1];
                case GO_HALL_RUNE_3:
                    return _roomRuneGUIDs[2];
                case GO_HALL_RUNE_4:
                    return _roomRuneGUIDs[3];
                case GO_HALL_RUNE_5:
                    return _roomRuneGUIDs[4];
                case GO_HALL_RUNE_6:
                    return _roomRuneGUIDs[5];
                case GO_HALL_RUNE_7:
                    return _roomRuneGUIDs[6];
                case GO_EMBERSEER_RUNE_1:
                    return _emberseeingRuneGUIDs[0];
                case GO_EMBERSEER_RUNE_2:
                    return _emberseeingRuneGUIDs[1];
                case GO_EMBERSEER_RUNE_3:
                    return _emberseeingRuneGUIDs[2];
                case GO_EMBERSEER_RUNE_4:
                    return _emberseeingRuneGUIDs[3];
                case GO_EMBERSEER_RUNE_5:
                    return _emberseeingRuneGUIDs[4];
                case GO_EMBERSEER_RUNE_6:
                    return _emberseeingRuneGUIDs[5];
                case GO_EMBERSEER_RUNE_7:
                    return _emberseeingRuneGUIDs[6];
                case GO_PORTCULLIS_ACTIVE:
                    return go_portcullis_active;
                case GO_PORTCULLIS_TOBOSSROOMS:
                    return go_portcullis_tobossrooms;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

        void Update(uint32 diff) override
        {
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
                    default:
                         break;
                }
            }
        }

        void Dragonspireroomstore()
        {
            // first we clear the stored creatures of previous attempts
            for (GuidVector& storedRuneCreatures : _runeCreatureGUIDs)
                storedRuneCreatures.clear();

            // next we store all creatures that are near a rune
            for (size_t i = 0; i < _roomRuneGUIDs.size(); ++i)
            {
                if (GameObject* rune = instance->GetGameObject(_roomRuneGUIDs[i]))
                {
                    for (size_t j = 0; j < DragonspireMobs.size(); ++j)
                    {
                        std::list<Creature*> creatureList;
                        GetCreatureListWithEntryInGrid(creatureList, rune, DragonspireMobs[j], 15.0f);
                        _runeCreatureGUIDs[i].reserve(creatureList.size());

                        for (Creature* creature : creatureList)
                            if (creature->IsAlive())
                                _runeCreatureGUIDs[i].push_back(creature->GetGUID());
                    }
                }
            }
        }

        void Dragonspireroomcheck()
        {
            GameObject* rune = nullptr;
            for (size_t i = 0; i < _roomRuneGUIDs.size(); ++i)
            {
                bool hasAliveCreatures = false;
                rune = instance->GetGameObject(_roomRuneGUIDs[i]);
                if (!rune)
                    continue;

                if (rune->GetGoState() == GO_STATE_ACTIVE)
                {
                    for (ObjectGuid const& guid : _runeCreatureGUIDs[i])
                    {
                        if (Creature const* creature = instance->GetCreature(guid))
                        {
                            if (creature->IsAlive())
                            {
                                hasAliveCreatures = true;
                                break;
                            }
                        }
                    }
                }

                if (!hasAliveCreatures && rune->GetGoState() == GO_STATE_ACTIVE)
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
            std::array<ObjectGuid, MAX_ROOM_RUNES> _roomRuneGUIDs;
            std::array<ObjectGuid, MAX_ROOM_RUNES> _emberseeingRuneGUIDs;
            std::array<GuidVector, MAX_ROOM_RUNES> _runeCreatureGUIDs;
            ObjectGuid go_portcullis_active;
            ObjectGuid go_portcullis_tobossrooms;
            GuidVector _incarceratorGUIDs;
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
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return false;

            if (Creature* rend = player->FindNearestCreature(NPC_WARCHIEF_REND_BLACKHAND, 50.0f))
            {
                if (!rend->IsAIEnabled())
                    return false;

                rend->AI()->SetData(AREATRIGGER, AREATRIGGER_BLACKROCK_STADIUM);
                return true;
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
                    if (!infiltrator->IsAIEnabled())
                        return false;

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
