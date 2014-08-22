/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "InstanceScript.h"
#include "deadmines.h"
#include "TemporarySummon.h"
#include "WorldPacket.h"
#include "Opcodes.h"

enum Sounds
{
    SOUND_CANNONFIRE                                     = 1400,
    SOUND_DESTROYDOOR                                    = 3079,
    SOUND_MR_SMITE_ALARM1                                = 5775,
    SOUND_MR_SMITE_ALARM2                                = 5777
};

#define SAY_MR_SMITE_ALARM1 "You there, check out that noise!"
#define SAY_MR_SMITE_ALARM2 "We're under attack! A vast, ye swabs! Repel the invaders!"

enum Misc
{
    DATA_CANNON_BLAST_TIMER                                = 3000,
    DATA_PIRATES_DELAY_TIMER                               = 1000
};

class instance_deadmines : public InstanceMapScript
{
    public:
        instance_deadmines()
            : InstanceMapScript("instance_deadmines", 36)
        {
        }

        struct instance_deadmines_InstanceMapScript : public InstanceScript
        {
            instance_deadmines_InstanceMapScript(Map* map) : InstanceScript(map) { }

            uint64 FactoryDoorGUID;
            uint64 IronCladDoorGUID;
            uint64 DefiasCannonGUID;
            uint64 DoorLeverGUID;
            uint64 DefiasPirate1GUID;
            uint64 DefiasPirate2GUID;
            uint64 DefiasCompanionGUID;

            uint32 State;
            uint32 CannonBlast_Timer;
            uint32 PiratesDelay_Timer;
            uint64 uiSmiteChestGUID;

            void Initialize() override
            {
                FactoryDoorGUID = 0;
                IronCladDoorGUID = 0;
                DefiasCannonGUID = 0;
                DoorLeverGUID = 0;
                DefiasPirate1GUID = 0;
                DefiasPirate2GUID = 0;
                DefiasCompanionGUID = 0;

                State = CANNON_NOT_USED;
                uiSmiteChestGUID = 0;
            }

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
                        // it's a hack - Mr. Smite should do that but his too far away
                        pIronCladDoor->SetName("Mr. Smite");
                        pIronCladDoor->MonsterYell(SAY_MR_SMITE_ALARM1, LANG_UNIVERSAL, NULL);
                        DoPlaySound(pIronCladDoor, SOUND_MR_SMITE_ALARM1);
                        State = CANNON_BLAST_INITIATED;
                        break;
                    case CANNON_BLAST_INITIATED:
                        PiratesDelay_Timer = DATA_PIRATES_DELAY_TIMER;
                        if (CannonBlast_Timer <= diff)
                        {
                            SummonCreatures();
                            ShootCannon();
                            BlastOutDoor();
                            LeverStucked();
                            pIronCladDoor->MonsterYell(SAY_MR_SMITE_ALARM2, LANG_UNIVERSAL, NULL);
                            DoPlaySound(pIronCladDoor, SOUND_MR_SMITE_ALARM2);
                            State = PIRATES_ATTACK;
                        } else CannonBlast_Timer -= diff;
                        break;
                    case PIRATES_ATTACK:
                        if (PiratesDelay_Timer <= diff)
                        {
                            MoveCreaturesInside();
                            State = EVENT_DONE;
                        } else PiratesDelay_Timer -= diff;
                        break;
                }
            }

            void SummonCreatures()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                {
                    Creature* DefiasPirate1 = pIronCladDoor->SummonCreature(657, pIronCladDoor->GetPositionX() - 2, pIronCladDoor->GetPositionY()-7, pIronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    Creature* DefiasPirate2 = pIronCladDoor->SummonCreature(657, pIronCladDoor->GetPositionX() + 3, pIronCladDoor->GetPositionY()-6, pIronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    Creature* DefiasCompanion = pIronCladDoor->SummonCreature(3450, pIronCladDoor->GetPositionX() + 2, pIronCladDoor->GetPositionY()-6, pIronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                    DefiasPirate1GUID = DefiasPirate1->GetGUID();
                    DefiasPirate2GUID = DefiasPirate2->GetGUID();
                    DefiasCompanionGUID = DefiasCompanion->GetGUID();
                }
            }

            void MoveCreaturesInside()
            {
                if (!DefiasPirate1GUID || !DefiasPirate2GUID || !DefiasCompanionGUID)
                    return;

                Creature* pDefiasPirate1 = instance->GetCreature(DefiasPirate1GUID);
                Creature* pDefiasPirate2 = instance->GetCreature(DefiasPirate2GUID);
                Creature* pDefiasCompanion = instance->GetCreature(DefiasCompanionGUID);
                if (!pDefiasPirate1 || !pDefiasPirate2 || !pDefiasCompanion)
                    return;

                MoveCreatureInside(pDefiasPirate1);
                MoveCreatureInside(pDefiasPirate2);
                MoveCreatureInside(pDefiasCompanion);
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
                    DoPlaySound(pDefiasCannon, SOUND_CANNONFIRE);
                }
            }

            void BlastOutDoor()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                {
                    pIronCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    DoPlaySound(pIronCladDoor, SOUND_DESTROYDOOR);
                }
            }

            void LeverStucked()
            {
                if (GameObject* pDoorLever = instance->GetGameObject(DoorLeverGUID))
                    pDoorLever->SetUInt32Value(GAMEOBJECT_FLAGS, 4);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_FACTORY_DOOR:   FactoryDoorGUID = go->GetGUID(); break;
                    case GO_IRONCLAD_DOOR:  IronCladDoorGUID = go->GetGUID();  break;
                    case GO_DEFIAS_CANNON:  DefiasCannonGUID = go->GetGUID();  break;
                    case GO_DOOR_LEVER:     DoorLeverGUID = go->GetGUID();     break;
                    case GO_MR_SMITE_CHEST: uiSmiteChestGUID = go->GetGUID();  break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                case EVENT_STATE:
                    if (DefiasCannonGUID && IronCladDoorGUID)
                        State=data;
                    break;
                case EVENT_RHAHKZOR:
                    if (data == DONE)
                        if (GameObject* go = instance->GetGameObject(FactoryDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
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

            uint64 GetData64(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_SMITE_CHEST:
                        return uiSmiteChestGUID;
                }

                return 0;
            }

            void DoPlaySound(GameObject* unit, uint32 sound)
            {
                WorldPacket data(SMSG_PLAY_SOUND, 4);
                data << uint32(sound);
                unit->SendMessageToSet(&data, false);
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
