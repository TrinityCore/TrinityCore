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

/* ScriptData
SDName: Instance_Deadmines
SD%Complete: 100
SDComment:
SDCategory: Deadmines
EndScriptData */

#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "deadmines.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"

enum Sounds
{
    SOUND_CANNONFIRE                                     = 1400,
    SOUND_DESTROYDOOR                                    = 3079
};

enum Misc
{
    DATA_CANNON_BLAST_TIMER                                = 3000,
    DATA_PIRATES_DELAY_TIMER                               = 1000,
    DATA_SMITE_ALARM_DELAY_TIMER                           = 5000
};

DoorData const doorData[] =
{
    { GO_FACTORY_DOOR,      BOSS_RHAHKZOR,   DOOR_TYPE_PASSAGE },
    { GO_MAST_ROOM_DOOR,    BOSS_SNEED,      DOOR_TYPE_PASSAGE },
    { GO_FOUNDRY_DOOR,      BOSS_GILNID,     DOOR_TYPE_PASSAGE },
    { 0,                    0,               DOOR_TYPE_ROOM    } // END
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
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                State = CANNON_NOT_USED;
                CannonBlast_Timer = 0;
                PiratesDelay_Timer = 0;
                SmiteAlarmDelay_Timer = 0;
            }

            ObjectGuid IronCladDoorGUID;
            ObjectGuid DefiasCannonGUID;
            ObjectGuid DoorLeverGUID;
            ObjectGuid DefiasPirate1GUID;
            ObjectGuid DefiasPirate2GUID;
            ObjectGuid MrSmiteGUID;

            uint32 State;
            uint32 CannonBlast_Timer;
            uint32 PiratesDelay_Timer;
            uint32 SmiteAlarmDelay_Timer;
            ObjectGuid uiSmiteChestGUID;

            virtual void Update(uint32 diff) override
            {
                if (!IronCladDoorGUID || !DefiasCannonGUID || !DoorLeverGUID)
                    return;

                GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID);
                if (!pIronCladDoor)
                    return;

                switch (State)
                {
                    case CANNON_GUNPOWDER_USED:
                        CannonBlast_Timer = DATA_CANNON_BLAST_TIMER;
                        State = CANNON_BLAST_INITIATED;
                        break;
                    case CANNON_BLAST_INITIATED:
                        PiratesDelay_Timer = DATA_PIRATES_DELAY_TIMER;
                        SmiteAlarmDelay_Timer = DATA_SMITE_ALARM_DELAY_TIMER;
                        if (CannonBlast_Timer <= diff)
                        {
                            SummonCreatures();
                            ShootCannon();
                            BlastOutDoor();
                            LeverStucked();
                            instance->LoadGrid(-22.8f, -797.24f); // Loads Mr. Smite's grid.
                            if (Creature* smite = instance->GetCreature(MrSmiteGUID)) // goes off when door blows up
                                smite->AI()->Talk(SAY_ALARM1);
                            State = PIRATES_ATTACK;
                        } else CannonBlast_Timer -= diff;
                        break;
                    case PIRATES_ATTACK:
                        if (PiratesDelay_Timer <= diff)
                        {
                            MoveCreaturesInside();
                            State = SMITE_ALARMED;
                        } else PiratesDelay_Timer -= diff;
                        break;
                    case SMITE_ALARMED:
                        if (SmiteAlarmDelay_Timer <= diff)
                        {
                            if (Creature* smite = instance->GetCreature(MrSmiteGUID))
                                smite->AI()->Talk(SAY_ALARM2);
                            State = EVENT_DONE;
                        } else SmiteAlarmDelay_Timer -= diff;
                        break;
                }
            }

            void SummonCreatures()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                {
                    Creature* DefiasPirate1 = pIronCladDoor->SummonCreature(657, pIronCladDoor->GetPositionX() - 2, pIronCladDoor->GetPositionY()-7, pIronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s);
                    Creature* DefiasPirate2 = pIronCladDoor->SummonCreature(657, pIronCladDoor->GetPositionX() + 3, pIronCladDoor->GetPositionY()-6, pIronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s);

                    DefiasPirate1GUID = DefiasPirate1->GetGUID();
                    DefiasPirate2GUID = DefiasPirate2->GetGUID();
                }
            }

            void MoveCreaturesInside()
            {
                if (!DefiasPirate1GUID || !DefiasPirate2GUID)
                    return;

                Creature* pDefiasPirate1 = instance->GetCreature(DefiasPirate1GUID);
                Creature* pDefiasPirate2 = instance->GetCreature(DefiasPirate2GUID);
                if (!pDefiasPirate1 || !pDefiasPirate2)
                    return;

                MoveCreatureInside(pDefiasPirate1);
                MoveCreatureInside(pDefiasPirate2);
            }

            void MoveCreatureInside(Creature* creature)
            {
                creature->SetWalk(false);
                creature->GetMotionMaster()->MovePoint(0, -102.7f, -655.9f, creature->GetPositionZ());
            }

            void ShootCannon()
            {
                if (GameObject* pDefiasCannon = instance->GetGameObject(DefiasCannonGUID))
                {
                    pDefiasCannon->SetGoState(GO_STATE_ACTIVE);
                    pDefiasCannon->PlayDirectSound(SOUND_CANNONFIRE);
                }
            }

            void BlastOutDoor()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                {
                    pIronCladDoor->SetGoState(GO_STATE_DESTROYED);
                    pIronCladDoor->PlayDirectSound(SOUND_DESTROYDOOR);
                }
            }

            void LeverStucked()
            {
                if (GameObject* pDoorLever = instance->GetGameObject(DoorLeverGUID))
                    pDoorLever->SetFlag(GO_FLAG_INTERACT_COND);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_MR_SMITE:
                        MrSmiteGUID = creature->GetGUID();
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
                    case GO_IRONCLAD_DOOR:
                        IronCladDoorGUID = go->GetGUID();
                        break;
                    case GO_DEFIAS_CANNON:
                        DefiasCannonGUID = go->GetGUID();
                        break;
                    case GO_DOOR_LEVER:
                        DoorLeverGUID = go->GetGUID();
                        break;
                    case GO_MR_SMITE_CHEST:
                        uiSmiteChestGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (Creature* creature = unit->ToCreature())
                {
                    switch (creature->GetEntry())
                    {
                        case NPC_RHAHKZOR:
                            SetBossState(BOSS_RHAHKZOR, DONE);
                            break;
                        case NPC_SNEED:
                            SetBossState(BOSS_SNEED, DONE);
                            break;
                        case NPC_GILNID:
                            SetBossState(BOSS_GILNID, DONE);
                            break;
                        case NPC_MR_SMITE:
                            SetBossState(BOSS_MR_SMITE, DONE);
                            break;
                        case NPC_GREENSKIN:
                            SetBossState(BOSS_GREENSKIN, DONE);
                            break;
                        case NPC_COOKIE:
                            SetBossState(BOSS_COOKIE, DONE);
                            break;
                        default:
                            break;
                    }
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case EVENT_STATE:
                        if (DefiasCannonGUID && IronCladDoorGUID)
                            State = data;
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case EVENT_STATE:
                        return State;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_SMITE_CHEST:
                        return uiSmiteChestGUID;
                }

                return ObjectGuid::Empty;
            }
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
