/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "ScriptedPch.h"

#define SPELL_ARCHAEDAS_AWAKEN        10347
#define SPELL_AWAKEN_VAULT_WALKER     10258

#define ARCHAEDAS_TEMPLE_DOOR           141869
#define ALTAR_OF_ARCHAEDAS              133234

#define ALTAR_OF_THE_KEEPER_TEMPLE_DOOR 124367
#define ALTAR_OF_THE_KEEPER_TEMPLE      130511

#define ANCIENT_VAULT_DOOR              124369

struct TRINITY_DLL_DECL instance_uldaman : public ScriptedInstance
{
    instance_uldaman(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    void Initialize()
    {
        archaedasGUID = 0;
        altarOfTheKeeperTempleDoor = 0;
        archaedasTempleDoor = 0;
        ancientVaultDoor = 0;
        whoWokeArchaedasGUID = 0;
    }

    uint64 archaedasGUID;
    uint64 altarOfTheKeeperTempleDoor;
    uint64 archaedasTempleDoor;
    uint64 ancientVaultDoor;
    uint64 whoWokeArchaedasGUID;

    std::vector<uint64> stoneKeeper;
    std::vector<uint64> altarOfTheKeeperCount;
    std::vector<uint64> vaultWalker;
    std::vector<uint64> earthenGuardian;
    std::vector<uint64> archaedasWallMinions;    // minions lined up around the wall

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch (pGo->GetEntry())
        {
            case ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:         // lock the door
                altarOfTheKeeperTempleDoor = pGo->GetGUID();
            break;

            case ARCHAEDAS_TEMPLE_DOOR:
                archaedasTempleDoor = pGo->GetGUID();
            break;

            case ANCIENT_VAULT_DOOR:
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
                ancientVaultDoor = pGo->GetGUID();
            break;
        }
    }

    void SetFrozenState(Creature* pCreature)
    {
        pCreature->setFaction(35);
        pCreature->RemoveAllAuras();
        //creature->RemoveFlag (UNIT_FIELD_FLAGS,UNIT_FLAG_ANIMATION_FROZEN);
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
    }

    void OpenDoor(uint64 guid)
    {
        GameObject* pGo = instance->GetGameObject(guid);
        if (!pGo)
            return;

        pGo->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
        pGo->SetGoState(GO_STATE_ACTIVE);
    }

    void ActivateStoneKeepers()
    {
        for (std::vector<uint64>::iterator i = stoneKeeper.begin(); i != stoneKeeper.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (!pTarget || !pTarget->isAlive() || pTarget->getFaction()==14)
                continue;
            pTarget->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE);
            pTarget->setFaction(14);
            pTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            return;        // only want the first one we find
        }
        // if we get this far than all four are dead so open the door
        SetData (NULL, 0);
    }

    void ActivateWallMinions()
    {
        Creature *archaedas = instance->GetCreature(archaedasGUID);
        if (!archaedas)
            return;

        for (std::vector<uint64>::iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (!pTarget || !pTarget->isAlive() || pTarget->getFaction()==14)
                continue;
            archaedas->CastSpell(pTarget, SPELL_AWAKEN_VAULT_WALKER, true);
            pTarget->CastSpell(pTarget, SPELL_ARCHAEDAS_AWAKEN,true);
            return;        // only want the first one we find
        }
    }

    // used when Archaedas dies.  All active minions must be despawned.
    void DeActivateMinions()
    {
        // first despawn any aggroed wall minions
        for (std::vector<uint64>::iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (!pTarget || pTarget->isDead() || pTarget->getFaction()!=14)
                continue;
            pTarget->setDeathState(JUST_DIED);
            pTarget->RemoveCorpse();
        }

        // Vault Walkers
        for (std::vector<uint64>::iterator i = vaultWalker.begin(); i != vaultWalker.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (!pTarget || pTarget->isDead() || pTarget->getFaction()!=14)
                continue;
            pTarget->setDeathState(JUST_DIED);
            pTarget->RemoveCorpse();
        }

        // Earthen Guardians
        for (std::vector<uint64>::iterator i = earthenGuardian.begin(); i != earthenGuardian.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (!pTarget || pTarget->isDead() || pTarget->getFaction()!=14)
                continue;
            pTarget->setDeathState(JUST_DIED);
            pTarget->RemoveCorpse();
        }
    }

    void ActivateArchaedas(uint64 target)
    {
        Creature *archaedas = instance->GetCreature(archaedasGUID);
        if (!archaedas)
            return;

        if (Unit *victim = Unit::GetUnit(*archaedas, target))
        {
            archaedas->CastSpell(archaedas, SPELL_ARCHAEDAS_AWAKEN,false);
            whoWokeArchaedasGUID = target;
        }
    }

    void RespawnMinions()
    {
        // first respawn any aggroed wall minions
        for (std::vector<uint64>::iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (pTarget && pTarget->isDead())
            {
                pTarget->Respawn();
                pTarget->GetMotionMaster()->MoveTargetedHome();
                SetFrozenState(pTarget);
            }
        }

        // Vault Walkers
        for (std::vector<uint64>::iterator i = vaultWalker.begin(); i != vaultWalker.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (pTarget && pTarget->isDead())
            {
                pTarget->Respawn();
                pTarget->GetMotionMaster()->MoveTargetedHome();
                SetFrozenState(pTarget);
            }
        }

        // Earthen Guardians
        for (std::vector<uint64>::iterator i = earthenGuardian.begin(); i != earthenGuardian.end(); ++i)
        {
            Creature *pTarget = instance->GetCreature(*i);
            if (pTarget && pTarget->isDead())
            {
                pTarget->Respawn();
                pTarget->GetMotionMaster()->MoveTargetedHome();
                SetFrozenState(pTarget);
            }
        }
    }

    void SetData (uint32 type, uint32 data)
    {
        //error_log ("SetData: data = %d", data);
        if (data==0) OpenDoor (altarOfTheKeeperTempleDoor);
        if (data==0) OpenDoor (archaedasTempleDoor);
        if (data==3) OpenDoor (ancientVaultDoor);
        if (data==1) ActivateStoneKeepers();
        if (data==2) ActivateWallMinions();
        if (data==4) DeActivateMinions();
        if (data==5) RespawnMinions();
    }

    void SetData64 (uint32 type, uint64 data)
    {
        // Archaedas
        if (type==0)
        {
            ActivateArchaedas (data);
        }
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch (pCreature->GetEntry()) {
            case 4857:    // Stone Keeper
                SetFrozenState (pCreature);
                stoneKeeper.push_back(pCreature->GetGUID());
                break;

            case 7309:    // Earthen Custodian
                archaedasWallMinions.push_back(pCreature->GetGUID());
                break;

            case 7077:    // Earthen Hallshaper
                archaedasWallMinions.push_back(pCreature->GetGUID());
                break;

            case 7076:    // Earthen Guardian
                earthenGuardian.push_back(pCreature->GetGUID());
                break;

            case 10120:    // Vault Walker
                vaultWalker.push_back(pCreature->GetGUID());
                break;

            case 2748:    // Archaedas
                archaedasGUID = pCreature->GetGUID();
                break;

        } // end switch
    } // end OnCreatureCreate

    uint64 GetData64 (uint32 identifier)
    {
        if (identifier == 0) return whoWokeArchaedasGUID;
        if (identifier == 1) return vaultWalker[0];    // VaultWalker1
        if (identifier == 2) return vaultWalker[1];    // VaultWalker2
        if (identifier == 3) return vaultWalker[2];    // VaultWalker3
        if (identifier == 4) return vaultWalker[3];    // VaultWalker4

        if (identifier == 5) return earthenGuardian[0];
        if (identifier == 6) return earthenGuardian[1];
        if (identifier == 7) return earthenGuardian[2];
        if (identifier == 8) return earthenGuardian[3];
        if (identifier == 9) return earthenGuardian[4];
        if (identifier == 10) return earthenGuardian[5];

        return 0;
    } // end GetData64
};

InstanceData* GetInstanceData_instance_uldaman(Map* pMap)
{
    return new instance_uldaman(pMap);
}

void AddSC_instance_uldaman()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_uldaman";
    newscript->GetInstanceData = &GetInstanceData_instance_uldaman;
    newscript->RegisterSelf();
}

