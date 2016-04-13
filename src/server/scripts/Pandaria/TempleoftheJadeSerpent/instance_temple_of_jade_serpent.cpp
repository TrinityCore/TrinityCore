#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "temple_of_jade_serpent.h"

#define MAX_ENCOUNTER 4

DoorData const doorData[] =
{
    { GAMEOBJECT_DOOR_WISE_MARI,             DATA_WISE_MARI_EVENT,            DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GAMEOBJECT_DOOR_LOREWALKER_STONSTEP,   DATA_LOREWALKER_STONESTEP_EVENT, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { 0,                                     0,                               DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

Position const roomCenter = {1046.941f, -2560.606f, 174.9552f, 4.33f };
#define WISE_MARI_WATER_TIMER 250


class instance_temple_of_jade_serpent : public InstanceMapScript
{
public:
    instance_temple_of_jade_serpent() : InstanceMapScript("instance_temple_of_jade_serpent", 960) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_temple_of_jade_serpent_InstanceMapScript(map);
    }

    struct instance_temple_of_jade_serpent_InstanceMapScript : public InstanceScript
    {
        instance_temple_of_jade_serpent_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            // instance
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doorData);

            // Wise Mari script
            doorWiseMari = 0;
            doorWiseMariEntrance = 0;
            waterDamageTimer = WISE_MARI_WATER_TIMER;
            wiseMariGUID = 0;

            //LoreWalkter Stonestep script.
            lorewalkterStonestepGUID = 0;
            doorLorewalkerStonestep =  0;
            zaoSunSeekerGUID = 0;
            scrollGUID = 0;
            perilGUID = 0;
            strifeGUID = 0;

            //Liu Flameheart script.
            liuGUID = 0;
            doorLiu = 0;
            doorLiu2 = 0;

            //Sha of doubt script.
            shaOfDoubtGUID = 0;
            doorShaOfDoubt = 0;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GAMEOBJECT_DOOR_WISE_MARI:
                    doorWiseMari = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_WISE_MARI_ENTRANCE:
                    doorWiseMariEntrance = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_LOREWALKER_STONSTEP:
                    doorLorewalkerStonestep = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART:
                    doorLiu = go->GetGUID();
                    if(GetBossState(DATA_WISE_MARI_EVENT) == DONE && GetBossState(DATA_LOREWALKER_STONESTEP_EVENT) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART_2:
                    doorLiu2 = go->GetGUID();
                    if(GetBossState(DATA_WISE_MARI_EVENT) == DONE && GetBossState(DATA_LOREWALKER_STONESTEP_EVENT) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GAMEOBJECT_DOOR_SHA_OF_DOUBT:
                    doorShaOfDoubt = go->GetGUID();
                    if(GetBossState(DATA_LIU_FLAMEHEART_EVENT) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                //Wise Mari
                case CREATURE_WISE_MARI:
                    wiseMariGUID = creature->GetGUID();
                    break;

                // LoreWalker Stonestep
                case CREATURE_LOREWALKTER_STONESTEP:
                    lorewalkterStonestepGUID = creature->GetGUID();
                    break;

                case CREATURE_SCROLL:
                    scrollGUID = creature->GetGUID();
                    break;

                case CREATURE_STRIFE:
                    strifeGUID = creature->GetGUID();
                    break;
                case CREATURE_PERIL:
                    perilGUID = creature->GetGUID();
                    break;

                case CREATURE_ZAO_SUNSEEKER:
                    zaoSunSeekerGUID = creature->GetGUID();
                    break;
                //Liu FlameHeart
                case CREATURE_LIU_FLAMEHEART:
                    liuGUID = creature->GetGUID();
                    break;

                //Sha of Doubt
                case CREATURE_SHA_OF_DOUBT:
                    shaOfDoubtGUID = creature->GetGUID();
                    break;
            }
                
        }
        
        void Update(uint32 diff) 
        {
            //WISE MARI
            if (waterDamageTimer <= diff)
            {
                // Handle damage of water in wise mari combat
                // Blizz handle that case with trigger and aura cast every 250 ms, anyway it's work
                Map::PlayerList const& PlayerList = instance->GetPlayers();

                if (!PlayerList.isEmpty())
                {
                    Creature* wiseMari = instance->GetCreature(wiseMariGUID);
                    if (wiseMari && wiseMari->IsAlive() && wiseMari->IsInCombat())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* plr = i->GetSource();
                            if (!plr)
                                continue;

                            // position : center of the wise mari's room
                            Position pos;
                            plr->GetPosition(&pos);

                            if ((plr->GetDistance(roomCenter) < 20.00f && roomCenter.HasInArc(M_PI, &pos))
                                || (!roomCenter.HasInArc(M_PI, &pos) && plr->GetDistance(roomCenter) < 14.00f))
                            {
                                if (plr->GetPositionZ() > 174.05f && plr->GetPositionZ() < 174.23f)
                                    plr->CastSpell(plr, SPELL_CORRUPTED_WATERS, true);
                            }

                            if (plr->GetDistance(roomCenter) < 30.00f && plr->GetPositionZ() > 170.19f && plr->GetPositionZ() < 170.215f)
                                plr->CastSpell(plr, SPELL_CORRUPTED_WATERS, true);
                        }
                    }
                }
                waterDamageTimer = WISE_MARI_WATER_TIMER;
            }
            else
                waterDamageTimer -= diff;
        }

        uint64 GetData64(uint32 identifier) const
        {
            switch (identifier)
            {
                case CREATURE_WISE_MARI:                    return wiseMariGUID;
                case CREATURE_LOREWALKTER_STONESTEP:        return lorewalkterStonestepGUID;
                case CREATURE_STRIFE:                       return strifeGUID;
                case CREATURE_PERIL:                        return perilGUID;
                case CREATURE_SCROLL:                       return scrollGUID;
                case CREATURE_ZAO_SUNSEEKER:                return zaoSunSeekerGUID;
                case CREATURE_LIU_FLAMEHEART:               return liuGUID;
                case CREATURE_SHA_OF_DOUBT:                 return shaOfDoubtGUID;

                case GAMEOBJECT_DOOR_WISE_MARI:             return doorWiseMari;
                case GAMEOBJECT_DOOR_WISE_MARI_ENTRANCE:    return doorWiseMariEntrance;
                case GAMEOBJECT_DOOR_LOREWALKER_STONSTEP:   return doorLorewalkerStonestep;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART:        return doorLiu;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART_2:      return doorLiu2;
                case GAMEOBJECT_DOOR_SHA_OF_DOUBT:          return doorShaOfDoubt;
            }
            return 0;
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_WISE_MARI_EVENT:
                {
                    if (state == IN_PROGRESS)
                    {
                        HandleGameObject(doorWiseMariEntrance, false);
                    }
                    else if (state == DONE)
                    {
                        HandleGameObject(doorWiseMariEntrance, true);
                        if (GetBossState(DATA_LOREWALKER_STONESTEP_EVENT) == DONE)
                        {
                            HandleGameObject(doorWiseMari, true);
                            HandleGameObject(doorLorewalkerStonestep, true);
                        }
                    }
                    else
                    {
                        HandleGameObject(doorWiseMariEntrance, true);
                    }

                    break;
                }
                case DATA_LOREWALKER_STONESTEP_EVENT:
                {
                    if(state == DONE && GetBossState(DATA_WISE_MARI_EVENT) == DONE)
                    {
                        HandleGameObject(doorLorewalkerStonestep, true);
                        HandleGameObject(doorWiseMari, true);
                    }
                    break;
                }
                case DATA_LIU_FLAMEHEART_EVENT:
                {
                    switch(state)
                    {
                        case IN_PROGRESS:
                        {
                            HandleGameObject(doorLiu, false);
                            HandleGameObject(doorLiu2, false);
                            break;
                        }
                        case NOT_STARTED:
                        {
                            if(GetBossState(DATA_WISE_MARI_EVENT) == DONE && GetBossState(DATA_LOREWALKER_STONESTEP_EVENT) == DONE)
                            {
                                HandleGameObject(doorLiu, true);
                                HandleGameObject(doorLiu2, true);
                            }
                            break;
                        }
                        case DONE:
                        {
                            HandleGameObject(doorLiu, true);
                            HandleGameObject(doorLiu2, true);
                            HandleGameObject(doorShaOfDoubt, true);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case DATA_SHA_OF_DOUBT_EVENT:
                {
                    if(state == IN_PROGRESS)
                        HandleGameObject(doorShaOfDoubt, false);
                    else if(state == DONE)
                        HandleGameObject(doorShaOfDoubt, true);
                    else if(state == NOT_STARTED)
                    {
                        if(GetBossState(DATA_LIU_FLAMEHEART_EVENT) == DONE)
                            HandleGameObject(doorShaOfDoubt, true);
                        else
                            HandleGameObject(doorShaOfDoubt, false);
                    }
                        
                    break;
                }
            }


            return true;
        }

        private:
            //Wise Mari
            uint32 waterDamageTimer;
            uint64 doorWiseMari;
            uint64 doorWiseMariEntrance;
            uint64 wiseMariGUID;

            //LoreWalkter Stonestep
            uint64 lorewalkterStonestepGUID;
            uint64 doorLorewalkerStonestep;

            uint64 zaoSunSeekerGUID;
            uint64 scrollGUID;
            uint64 perilGUID;
            uint64 strifeGUID;
            
            //Liu Flameheart
            uint64 liuGUID;
            uint64 doorLiu;
            uint64 doorLiu2;

            //Sha of Doubt
            uint64 shaOfDoubtGUID;
            uint64 doorShaOfDoubt;
    };

};

void AddSC_instance_temple_of_jade_serpent()
{
    new instance_temple_of_jade_serpent();
}
