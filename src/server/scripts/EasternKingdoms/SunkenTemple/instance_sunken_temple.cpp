/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Sunken_Temple
SD%Complete: 100
SDComment:Place Holder
SDCategory: Sunken Temple
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "sunken_temple.h"

enum Gameobject
{
    GO_ATALAI_STATUE1           = 148830,
    GO_ATALAI_STATUE2           = 148831,
    GO_ATALAI_STATUE3           = 148832,
    GO_ATALAI_STATUE4           = 148833,
    GO_ATALAI_STATUE5           = 148834,
    GO_ATALAI_STATUE6           = 148835,
    GO_ATALAI_IDOL              = 148836,
    GO_ATALAI_LIGHT1            = 148883,
    GO_ATALAI_LIGHT2            = 148937

};

enum CreatureIds
{
    NPC_MALFURION_STORMRAGE     = 15362
};

class instance_sunken_temple : public InstanceMapScript
{
public:
    instance_sunken_temple() : InstanceMapScript("instance_sunken_temple", 109) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_sunken_temple_InstanceMapScript(map);
    }

    struct instance_sunken_temple_InstanceMapScript : public InstanceScript
    {
        instance_sunken_temple_InstanceMapScript(Map* map) : InstanceScript(map)
        {
        }

        uint64 GOAtalaiStatue1;
        uint64 GOAtalaiStatue2;
        uint64 GOAtalaiStatue3;
        uint64 GOAtalaiStatue4;
        uint64 GOAtalaiStatue5;
        uint64 GOAtalaiStatue6;
        uint64 GOAtalaiIdol;

        uint32 State;

        bool s1;
        bool s2;
        bool s3;
        bool s4;
        bool s5;
        bool s6;

        void Initialize()
        {
            GOAtalaiStatue1 = 0;
            GOAtalaiStatue2 = 0;
            GOAtalaiStatue3 = 0;
            GOAtalaiStatue4 = 0;
            GOAtalaiStatue5 = 0;
            GOAtalaiStatue6 = 0;
            GOAtalaiIdol = 0;

            State = 0;

            s1 = false;
            s2 = false;
            s3 = false;
            s4 = false;
            s5 = false;
            s6 = false;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_ATALAI_STATUE1: GOAtalaiStatue1 = go->GetGUID();   break;
                case GO_ATALAI_STATUE2: GOAtalaiStatue2 = go->GetGUID();   break;
                case GO_ATALAI_STATUE3: GOAtalaiStatue3 = go->GetGUID();   break;
                case GO_ATALAI_STATUE4: GOAtalaiStatue4 = go->GetGUID();   break;
                case GO_ATALAI_STATUE5: GOAtalaiStatue5 = go->GetGUID();   break;
                case GO_ATALAI_STATUE6: GOAtalaiStatue6 = go->GetGUID();   break;
                case GO_ATALAI_IDOL:    GOAtalaiIdol = go->GetGUID();      break;
            }
        }

         virtual void Update(uint32 /*diff*/) // correct order goes form 1-6
         {
             switch (State)
             {
             case GO_ATALAI_STATUE1:
                if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue1 = instance->GetGameObject(GOAtalaiStatue1))
                        UseStatue(pAtalaiStatue1);
                    s1 = true;
                    State = 0;
                };
                break;
             case GO_ATALAI_STATUE2:
                if (s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue2 = instance->GetGameObject(GOAtalaiStatue2))
                        UseStatue(pAtalaiStatue2);
                    s2 = true;
                    State = 0;
                };
                break;
             case GO_ATALAI_STATUE3:
                if (s1 && s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue3 = instance->GetGameObject(GOAtalaiStatue3))
                        UseStatue(pAtalaiStatue3);
                    s3 = true;
                    State = 0;
                };
                break;
             case GO_ATALAI_STATUE4:
                if (s1 && s2 && s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue4 = instance->GetGameObject(GOAtalaiStatue4))
                        UseStatue(pAtalaiStatue4);
                    s4 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE5:
                if (s1 && s2 && s3 && s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue5 = instance->GetGameObject(GOAtalaiStatue5))
                        UseStatue(pAtalaiStatue5);
                    s5 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE6:
                if (s1 && s2 && s3 && s4 && s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue6 = instance->GetGameObject(GOAtalaiStatue6))
                        UseStatue(pAtalaiStatue6);
                    s6 = true;
                    State = 0;
                }
                break;
             }
         };

        void UseStatue(GameObject* go)
        {
            go->SummonGameObject(GO_ATALAI_LIGHT1, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, 0, 0, 0, 0, 0);
            go->SetUInt32Value(GAMEOBJECT_FLAGS, 4);
        }

         /*
         void UseLastStatue(GameObject* go)
         {
             AtalaiStatue1->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue1->GetPositionX(), AtalaiStatue1->GetPositionY(), AtalaiStatue1->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             AtalaiStatue2->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue2->GetPositionX(), AtalaiStatue2->GetPositionY(), AtalaiStatue2->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             AtalaiStatue3->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue3->GetPositionX(), AtalaiStatue3->GetPositionY(), AtalaiStatue3->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             AtalaiStatue4->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue4->GetPositionX(), AtalaiStatue4->GetPositionY(), AtalaiStatue4->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             AtalaiStatue5->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue5->GetPositionX(), AtalaiStatue5->GetPositionY(), AtalaiStatue5->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             AtalaiStatue6->SummonGameObject(GO_ATALAI_LIGHT2, AtalaiStatue6->GetPositionX(), AtalaiStatue6->GetPositionY(), AtalaiStatue6->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
             go->SummonGameObject(148838, -488.997, 96.61, -189.019, -1.52, 0, 0, 0, 0, 100000);
         }
         */

         void SetData(uint32 type, uint32 data) OVERRIDE
         {
            if (type == EVENT_STATE)
                State = data;
         }

         uint32 GetData(uint32 type) const OVERRIDE
         {
            if (type == EVENT_STATE)
                return State;
            return 0;
         }
    };

};

void AddSC_instance_sunken_temple()
{
    new instance_sunken_temple();
}
