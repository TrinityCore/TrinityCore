/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Instance_Deadmines
SD%Complete: 100
SDComment:
SDCategory: Deadmines
EndScriptData */

#include "ScriptedPch.h"
#include "deadmines.h"

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

struct instance_deadmines : public ScriptedInstance
{
    instance_deadmines(Map* pMap) : ScriptedInstance(pMap) { Initialize(); };

    GameObject* IronCladDoor;
    GameObject* DefiasCannon;
    GameObject* DoorLever;
    Creature* DefiasPirate1;
    Creature* DefiasPirate2;
    Creature* DefiasCompanion;
    uint32 State;
    uint32 CannonBlast_Timer;
    uint32 PiratesDelay_Timer;
    uint64 uiSmiteChestGUID;

    void Initialize()
    {
        IronCladDoor = NULL;
        DefiasCannon = NULL;
        DoorLever =    NULL;
        State = CANNON_NOT_USED;
        uiSmiteChestGUID = 0;
    }

    virtual void Update(uint32 diff)
    {
        if (!IronCladDoor || !DefiasCannon || !DoorLever)
            return;

        switch (State)
        {
            case CANNON_GUNPOWDER_USED:
                CannonBlast_Timer = DATA_CANNON_BLAST_TIMER;
                // it's a hack - Mr. Smite should do that but his too far away
                IronCladDoor->SetName("Mr. Smite");
                IronCladDoor->MonsterYell(SAY_MR_SMITE_ALARM1, LANG_UNIVERSAL, 0);
                DoPlaySound(IronCladDoor, SOUND_MR_SMITE_ALARM1);
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
                    IronCladDoor->MonsterYell(SAY_MR_SMITE_ALARM2, LANG_UNIVERSAL, 0);
                    DoPlaySound(IronCladDoor, SOUND_MR_SMITE_ALARM2);
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
        DefiasPirate1 = IronCladDoor->SummonCreature(657,IronCladDoor->GetPositionX() - 2,IronCladDoor->GetPositionY()-7,IronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
        DefiasPirate2 = IronCladDoor->SummonCreature(657,IronCladDoor->GetPositionX() + 3,IronCladDoor->GetPositionY()-6,IronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
        DefiasCompanion = IronCladDoor->SummonCreature(3450,IronCladDoor->GetPositionX() + 2,IronCladDoor->GetPositionY()-6,IronCladDoor->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
    }

    void MoveCreaturesInside()
    {
        if (!DefiasPirate1 || !DefiasPirate2 || !DefiasCompanion)
            return;

        MoveCreatureInside(DefiasPirate1);
        MoveCreatureInside(DefiasPirate2);
        MoveCreatureInside(DefiasCompanion);
    }

    void MoveCreatureInside(Creature* pCreature)
    {
        pCreature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pCreature->GetMotionMaster()->MovePoint(0, -102.7,-655.9, pCreature->GetPositionZ());
    }

    void ShootCannon()
    {
        DefiasCannon->SetGoState(GO_STATE_ACTIVE);
        DoPlaySound(DefiasCannon, SOUND_CANNONFIRE);
    }

    void BlastOutDoor()
    {
        IronCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
        DoPlaySound(IronCladDoor, SOUND_DESTROYDOOR);
    }

    void LeverStucked()
    {
        DoorLever->SetUInt32Value(GAMEOBJECT_FLAGS, 4);
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_IRONCLAD_DOOR:
                IronCladDoor = pGo;
                break;
            case GO_DEFIAS_CANNON:
                DefiasCannon = pGo;
                break;
            case GO_DOOR_LEVER:
                DoorLever = pGo;
                break;
            case GO_MR_SMITE_CHEST:
                uiSmiteChestGUID = pGo->GetGUID();
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        if (type == EVENT_STATE)
        {
            if (DefiasCannon && IronCladDoor)
                State=data;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch (type)
        {
            case EVENT_STATE:
                return State;
        }

        return 0;
    }

    uint64 GetData64(uint32 data)
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
        WorldPacket data(4);
        data.SetOpcode(SMSG_PLAY_SOUND);
        data << uint32(sound);
        unit->SendMessageToSet(&data,false);
    }

    void DoPlaySoundCreature(Unit* unit, uint32 sound)
    {
        WorldPacket data(4);
        data.SetOpcode(SMSG_PLAY_SOUND);
        data << uint32(sound);
        unit->SendMessageToSet(&data,false);
    }
};

InstanceData* GetInstanceData_instance_deadmines(Map* pMap)
{
    return new instance_deadmines(pMap);
}

void AddSC_instance_deadmines()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_deadmines";
    newscript->GetInstanceData = &GetInstanceData_instance_deadmines;
    newscript->RegisterSelf();
}
