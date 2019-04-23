/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Trinity <http://www.projecttrinity.org/>
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
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "throne_of_the_tides.h"
#include "GameObject.h"

#define ENCOUNTERS 5

class instance_throne_of_the_tides : public InstanceMapScript
{
public:
    instance_throne_of_the_tides() : InstanceMapScript("instance_throne_of_the_tides", 643) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_throne_of_the_tides_InstanceMapScript(map);
    }

    struct instance_throne_of_the_tides_InstanceMapScript: public InstanceScript
    {
        instance_throne_of_the_tides_InstanceMapScript(InstanceMap* map): InstanceScript(map) { }

        uint32 uiEncounter[ENCOUNTERS];

        ObjectGuid uiLadyNazjar;
        ObjectGuid uiCommanderUlthok;
        ObjectGuid uiErunakStonespeaker;
        ObjectGuid uiMindbenderGhrusha;
        ObjectGuid uiNeptulon;
        ObjectGuid uiOzumat;

        ObjectGuid uiTeleporter;

        ObjectGuid doorOzumat;
        ObjectGuid doorErunak;
        ObjectGuid doorNazjar;
        ObjectGuid doorUlthok;

        uint8 uiUlthokDoorCounter;
        uint8 uiMindbenderDoorCounter;

        std::list<ObjectGuid> firstTunnelTrash;
        std::list<ObjectGuid> secondTunnelTrash;
        std::list<ObjectGuid> tunnelObjects;

        bool firstTunnel;

        void Initialize() override
        {
            uiUlthokDoorCounter = 0;
            uiMindbenderDoorCounter = 0;

            firstTunnel = false;

            for (uint8 i=0; i < ENCOUNTERS; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const override 
        {
            for (uint8 i=0; i < ENCOUNTERS; ++i)
            {
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case BOSS_LADY_NAZJAR:
                    uiLadyNazjar = creature->GetGUID();
                    break;
                case BOSS_COMMANDER_ULTHOK:
                    uiCommanderUlthok = creature->GetGUID();
                    if (GetData(DATA_LADY_NAZJAR_EVENT) == DONE)
                    {
                        creature->SetVisible(true);
                        creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        creature->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                case BOSS_ERUNAK_STONESPEAKER:
                    uiErunakStonespeaker = creature->GetGUID();
                    break;
                case BOSS_MINDBENDER_GHURSHA:
                    uiMindbenderGhrusha = creature->GetGUID();
                    break;
                case BOSS_OZUMAT:
                    uiOzumat = creature->GetGUID();
                    break;
                case BOSS_NEPTULON:
                    uiNeptulon = creature->GetGUID();
                    break;
                case NPC_TELEPORTER:
                    uiTeleporter = creature->GetGUID();
                    if (GetData(DATA_COMMANDER_ULTHOK_EVENT) == DONE)
                    {
                        creature->SetVisible(true);
                    }
                    break;
                case NPC_NAZJAR_INVADER:
                case NPC_NAZJAR_SPIRITMENDER:
                    firstTunnelTrash.push_back(creature->GetGUID());
                    break;
                case NPC_NAZJAR_INVADER2:
                case NPC_NAZJAR_SPIRITMENDER2:
                    secondTunnelTrash.push_back(creature->GetGUID());
                    break;
                case NPC_TAINTED_SENTRY:
                    ++uiUlthokDoorCounter;
                    break;
                case NPC_GILGOBLIN_AQUAMAGE:
                case NPC_GILGOBLIN_HUNTER:
                case NPC_FACELESS_WATCHER:
                    ++uiMindbenderDoorCounter;
                    break;
                case NPC_CAPTAIN_TAYLOR:
                case NPC_LEGIONNAIRE_NAZGRIM:
                {
                    Map::PlayerList const &players = instance->GetPlayers();
                    uint32 TeamInInstance = 0;

                    if (!players.isEmpty())
                    {
                        if (Player* player = players.begin()->GetSource())
                            TeamInInstance = player->GetTeam();
                    }
                    if ((creature->GetEntry() == NPC_LEGIONNAIRE_NAZGRIM && TeamInInstance == ALLIANCE) || (creature->GetEntry() == NPC_CAPTAIN_TAYLOR && TeamInInstance == HORDE))
                    {
                        creature->SetVisible(false);
                        creature->SetReactState(REACT_PASSIVE);
                    }
                    break;
                }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch(go->GetEntry())
            {
                case GO_OZUMAT_DOOR: doorOzumat = go->GetGUID();        break;
                case GO_LADY_NAZJAR_DOOR: doorNazjar = go->GetGUID();   break;
                case GO_ERUNAK_STONESPEAKER_DOOR: doorErunak = go->GetGUID(); break;
                case GO_COMMANDER_ULTHOK_DOOR: doorUlthok = go->GetGUID(); break;
                case GO_OZUMAT_TENTACLE_1:
                case GO_OZUMAT_TENTACLE_2:
                case GO_INVISIBLE_DOOR:
                {
                    tunnelObjects.push_back(go->GetGUID());
                    go->setActive(true);
                    break;
                }
            }
        }

        void OnCreatureDeath(Creature* creature) /*override*/
        {
            switch(creature->GetEntry())
            {
                case NPC_TAINTED_SENTRY:
                    if(GetData(DATA_LADY_NAZJAR_EVENT) == DONE)
                        if(--uiUlthokDoorCounter == 0)
                            HandleGameObject(GetGuidData(GO_OZUMAT_DOOR), true);
                    break;
                case NPC_GILGOBLIN_AQUAMAGE:
                case NPC_GILGOBLIN_HUNTER:
                case NPC_FACELESS_WATCHER:
                    if(GetData(DATA_LADY_NAZJAR_EVENT) == DONE)
                        if(--uiMindbenderDoorCounter == 0)
                            HandleGameObject(GetGuidData(GO_ERUNAK_STONESPEAKER_DOOR), true);
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_LADY_NAZJAR:
                    return uiLadyNazjar;
                case DATA_COMMANDER_ULTHOK:
                    return uiCommanderUlthok;
                case DATA_ERUNAK_STONESPEAKER:
                    return uiErunakStonespeaker;
                case DATA_MINDBENDER_GHURSHA:
                    return uiMindbenderGhrusha;
                case DATA_OZUMAT:
                    return uiOzumat;
                case DATA_NEPTULON:
                    return uiNeptulon;
                case GO_LADY_NAZJAR_DOOR:
                    return doorNazjar;
                case GO_ERUNAK_STONESPEAKER_DOOR:
                    return doorErunak;
                case GO_OZUMAT_DOOR:
                    return doorOzumat;
                case GO_COMMANDER_ULTHOK_DOOR:
                    return doorUlthok;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_LADY_NAZJAR_EVENT:
                    uiEncounter[0] = data;
                    break;
                case DATA_COMMANDER_ULTHOK_EVENT:
                    uiEncounter[1] = data;
                    break;
                case DATA_ERUNAK_STONESPEAKER_EVENT:
                    uiEncounter[2] = data;
                    break;
                case DATA_MINDBENDER_GHURSHA_EVENT:
                    uiEncounter[3] = data;
                    break;
                case DATA_OZUMAT_EVENT:
                    uiEncounter[4] = data;
                    if (data == DONE)
                        if (Creature* neptulon =  instance->GetCreature(uiNeptulon))
                        {
                            if (GameObject* Chest = neptulon->SummonGameObject(instance->IsHeroic() ? GO_OZUMAT_CHEST_HEROIC : GO_OZUMAT_CHEST_NORMAL, -145.697f, 985.088f, 230.406f, 6.137f, QuaternionData(), 90000000))
                                Chest->SetRespawnTime(Chest->GetRespawnDelay());
                        }
                    break;
                case DATA_FIRST_TUNNEL:
                    firstTunnel = true;
                    break;
            }

           if (data == DONE)
               SaveToDB();
        }

        uint32 GetData(uint32 type) const override 
        {
            switch (type)
            {
                case DATA_LADY_NAZJAR_EVENT:
                    return uiEncounter[0];
                case DATA_COMMANDER_ULTHOK_EVENT:
                    return uiEncounter[1];
                case DATA_ERUNAK_STONESPEAKER_EVENT:
                    return uiEncounter[2];
                case DATA_MINDBENDER_GHURSHA_EVENT:
                    return uiEncounter[3];
                case DATA_OZUMAT_EVENT:
                    return uiEncounter[4];
                case DATA_FIRST_TUNNEL:
                    return firstTunnel;
            }
            return 0;
        }
    };
};

// Shorten definition
typedef instance_throne_of_the_tides::instance_throne_of_the_tides_InstanceMapScript MapAI;

class GoHelloThroneDefenseSystem : public GameObjectScript
{
    public:

        GoHelloThroneDefenseSystem()
            : GameObjectScript("go_throne_of_tides_defence_system")
        {
        }

        bool OnGossipHello(Player* player, GameObject* /*go*/) override
        {
            Map::PlayerList const &PlList = player->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return false;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    if (player->IsGameMaster())
                        continue;

                    if (player->IsAlive())
                        player->SendCinematicStart(INSTANCE_CINEMATIC);
                }
            }

            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return false;

            if (instance->GetData(DATA_LADY_NAZJAR_EVENT) == DONE)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_LADY_NAZJAR_DOOR), true);
                if(Creature * commander = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_COMMANDER_ULTHOK)))
                {
                    commander->SetVisible(true);
                    commander->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    commander->SetReactState(REACT_AGGRESSIVE);
                }

                if (MapAI * pInstanceAI = CAST_AI(MapAI, instance))
                {
                    for(std::list<ObjectGuid>::iterator itr = pInstanceAI->tunnelObjects.begin(); itr != pInstanceAI->tunnelObjects.end(); ++itr)
                    {
                        //instance->HandleGameObject(*itr), true);
                        if(GameObject * gob = instance->instance->GetGameObject((*itr)))
                            gob->Delete();
                    }
                }
            }
            return true;
        }
};

class at_tott_first_tunnel : public AreaTriggerScript
{
    public:
        at_tott_first_tunnel() : AreaTriggerScript("at_tott_first_tunnel") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();

            if (!instance->GetData(DATA_FIRST_TUNNEL))
            {
                if (MapAI * pInstanceAI = CAST_AI(MapAI, instance))
                {
                    Position pos;
                    pos.Relocate(-388.789f, 808.853f, 248.018f, 3.230f);
                    for (std::list<ObjectGuid>::iterator itr = pInstanceAI->firstTunnelTrash.begin(); itr != pInstanceAI->firstTunnelTrash.end(); ++itr)
                    {
                        float x,y,z;
                        if (Creature* c = ObjectAccessor::GetCreature(*player, (*itr)))
                        {
                            c->GetRandomPoint(pos, 8.0f, x,y,z);
                            c->GetMotionMaster()->MoveJump(x, y, z, pos.GetOrientation(), 20.0f, 20.0f);
                            c->SetHomePosition(x,y,z, pos.GetOrientation());
                        }
                    }
                }

                instance->SetData(DATA_FIRST_TUNNEL, 1);
            }
            return true;
        }
};

static Position MoveLoc[3]=
{
    {-133.32f, 802.56f, 796.81f, 3.164f},
    {-101.49f, 802.29f, 796.19f, 3.164f},
    {-71.26f, 802.43f, 797.79f, 3.164f},
};

enum eNazjarTexts
{
    SAY_EVENT_END    = 0,
    SAY_EVENT_START  = 1,
};

class lady_nazjar_gauntlet : public CreatureScript
{
public:
    lady_nazjar_gauntlet() : CreatureScript("lady_nazjar_gauntlet") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new lady_nazjar_gauntletAI (creature);
    }

    struct lady_nazjar_gauntletAI : public ScriptedAI
    {
        lady_nazjar_gauntletAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint8 m_phaseCounter;
        ObjectGuid eventStarter;
        uint32 waveTimer;
        uint32 checkTimer;

        void Reset() override
        {
            m_phaseCounter = 0;
            waveTimer = 15000;
            checkTimer = 5000;
        }

        void ReleasePack()
        {
            Map::PlayerList const &players = instance->instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                // We need to relase pack on first alive person.
                if(!itr->GetSource() || !itr->GetSource()->IsAlive())
                    continue;

                std::list<Creature*> clist;
                GetCreatureListWithEntryInGrid(clist, me, NPC_DEEP_MURLOC_DRUDGE, 30.0f);

                uint8 counter = 0;
                for (std::list<Creature*>::iterator citr = clist.begin(); citr != clist.end(); ++citr)
                {
                    (*citr)->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    (*citr)->GetMotionMaster()->MovePoint(0, -144.25f, 802.33f, 796.51f);
                    // send pack by 5
                    if(++counter == 5)
                        break;
                }
            }
        }

        void ReleaseNPCs()
        {
            if (MapAI * pInstanceAI = CAST_AI(MapAI, instance))
                for (std::list<ObjectGuid>::iterator itr = pInstanceAI->secondTunnelTrash.begin(); itr != pInstanceAI->secondTunnelTrash.end(); ++itr)
                {
                    if (Creature * c = ObjectAccessor::GetCreature(*me, (*itr)))
                    {
                        Position pos;
                        bool positioned = false;
                        for (int i = 0; i < 3; ++i)
                        {
                            if (c->GetDistance(MoveLoc[i]) < 30)
                            {
                                pos.Relocate(MoveLoc[i]);
                                positioned = true;
                            }
                        }

                        // Mob does not belong to Gauntlet Event
                        if (!positioned)
                            continue;

                        float x,y,z;
                        c->GetRandomPoint(pos, 6.0f, x,y,z);
                        c->GetMotionMaster()->MoveJump(x, y, z, pos.GetOrientation(), 20.0f, 20.0f);
                        c->SetHomePosition(x,y,z, pos.GetOrientation());
                    }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!m_phaseCounter)
            {
                if (checkTimer < diff)
                {
                    Map::PlayerList const &players = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        // We need to relase pack on first alive person.
                        if (!itr->GetSource() || itr->GetSource()->IsGameMaster())
                            continue;

                        // Someone moved into the gauntlet
                        if (itr->GetSource()->GetDistance(me) < 115.0f)
                        {
                            Talk(SAY_EVENT_START);
                            ++m_phaseCounter;
                            eventStarter = itr->GetSource()->GetGUID();

                            ReleaseNPCs();
                            break;
                        }
                    }
                    checkTimer = 5000;
                }
                else checkTimer -= diff;

                return;
            }

            if (waveTimer <= diff)
            {
                ReleasePack();
                waveTimer = 15000;
                ++m_phaseCounter;
            }
            else waveTimer -= diff;

            if (m_phaseCounter == 7)
            {
                Talk(SAY_EVENT_END);
                if (instance)
                {
                    instance->HandleGameObject(instance->GetGuidData(GO_LADY_NAZJAR_DOOR), true);
                    instance->HandleGameObject(instance->GetGuidData(GO_COMMANDER_ULTHOK_DOOR), true);
                }
                me->DespawnOrUnsummon();
            }
        }
    };
};

class npc_tot_teleporter : public CreatureScript
{
public:
    npc_tot_teleporter() : CreatureScript("npc_tot_teleporter") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 Sender, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (Sender != GOSSIP_SENDER_MAIN)
            return true;
        if (!player->getAttackers().empty())
            return true;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->TeleportTo(643, -566.13f, 813.483f, 244.924f, 6.18f);
                CloseGossipMenuFor(player);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (instance && instance->GetData(DATA_COMMANDER_ULTHOK_EVENT)==DONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Teleport me to on top", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, 2475, creature->GetGUID());
        return true;
    }
};

void AddSC_instance_throne_of_the_tides()
{
    new instance_throne_of_the_tides();
    new at_tott_first_tunnel();
    new lady_nazjar_gauntlet();
    new GoHelloThroneDefenseSystem();
    new npc_tot_teleporter();
}
