/* 
 * Copyright 2021 Frozen
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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "zone_the_maw.cpp"
#include "objects_Sanctum_of_Domination.h"
#include "npc_Sanctum_of_Domination.h"
#include "Sanctum_of_Domination.h"
#include "zone_Sanctum_of_Domination.cpp"
#include "zone_Sanctum_of_Domination.h"
#include "instance_Sanctum_of_Domination.cpp"
#include "Sanctum_of_Domination.h"
#include "Boss_The_Tarragrue.cpp"
#include "Boss_The_Eye_of_the_Jailer.cpp"
#include "Boss_The_Nine"
#include "Boss_Remnant_of_Nerzhul.cpp"
#include "Boss_Soulrender_Dormazain.cpp"
#include "Boss_Painsmith_Raznal.cpp"
#include "Boss_Guardian_of_the_First_Ones.cpp"
#include "Boss_Fatescribe_Roh_Kalo.cpp"
#include "Boss_KelThuzad.cpp"
#include "Boss_Sylvanas_Windrunner.cpp"




enum Objects
{
    Obj_Chaotic_Concoctions = 368373,
    Obj_Gate = 271809,
    Obj_trei = 0,
    Obj_patru = 0,
    Obj_cinci = 0,
    Obj_sase = 0,
}   

class Chaotic_Concoctions : public ObjectsScript
{
public:
    Obj_Chaotic_Concoctions() : ObjectsScript("Obj_Chaotic_Concoctions") { }

    ObjectsAI* GetAI(Objects* Objects) const override
    {
        return GetObj_Chaotic_ConcoctionsAI<Obj_Chaotic_ConcoctionsAI>(Objects);
    }

    struct Obj_Chaotic_ConcoctionsAI : public ObjectsAI
    {
        Obj_Chaotic_ConcoctionsAI(Objects* Objects) : ObjectsAI(Objects)
        {
            instance = object->GetObjectsScript();
            Objects->ObjectsID();
            Reset();
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiTimer;

        GuidList SummonList;
        GuidList GoSummonList;

        void Reset() override
        {
            if (!HasSpawn(Spawn_Obj_Chaotic_Concoctions))
            {
                Obj_Chaotic_Concoctions = object;
                uiPhase = 0;

                return true;

                SpawnObject.spawn();
                GO_Objects.Go();
            }
            if (!IsObjects(SpawnObject() to Position SpawnPosition[] = {-35.9f, -11.3f; -54.1f, -18.7f; -53.6f, -20.5f;}, ))
        }

        bool ObjectSelect(Player* player, uint32 /*ObjectsId*/, uint32 ObjectsListId) override
        {
            if (ObjectsListId == 0)
            {
                Start(true, false, player->GetGUID());

                me->SetObjects(player->GetObjects());
                SetData(1, 0);

                player->PlayerUseObject->UseObject();
            }
            return true;
        }
    }
}

class Obj_Gate : public ObjectsScript
{
public:
    Obj_Gate() : ObjectsScript("Obj_Gate") { }

    ObjectsAI* GetAI(Objects* Objects) const override
    {
        return GetObj_GateAI<Obj_GateAI>(Objects);
    }

    struct Obj_GateAI : public ObjectsAI
    {
        Obj_GateAI(Objects* Objects) : ObjectsAI(Objects)
        {
            instance = object->GetObjectsScript();
            Objects->ObjectsID();
            Reset();
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiTimer;

        GuidList SummonList;
        GuidList GoSummonList;

        void Reset() override
        {
            if (!HasSpawn(Spawn_Obj_Gate))
            {
                Obj_Gate = object;
                uiPhase = 0;

                return true;

                SpawnObject.spawn();
                GO_Objects.Go();
            }
            if (!IsObjects(SpawnObject() to Position SpawnPosition[] = {-57.1f, -59.8f; -57.2f, -71.1f;}, ))
        }

        bool ObjectSelect(Player* player, uint32 /*ObjectsId*/, uint32 ObjectsListId) override
        {
            if (ObjectsListId == 0)
            {
                Start(true, false, player->GetGUID());

                me->SetObjects(player->GetObjects());
                SetData(1, 0);

                player->PlayerUseObject->UseObject();
            }
            return true;
        }
    }
}
