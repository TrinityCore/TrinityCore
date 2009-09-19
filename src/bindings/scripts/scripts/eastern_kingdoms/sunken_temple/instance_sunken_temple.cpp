/* Copyright (C) 2006 - 2009 kb_z
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
SDName: Instance_Sunken_Temple
SD%Complete: 100
SDComment:Place Holder
SDCategory: Sunken Temple
EndScriptData */

#include "precompiled.h"
#include "def_sunken_temple.h"

#define GO_ATALAI_STATUE1 148830
#define GO_ATALAI_STATUE2 148831
#define GO_ATALAI_STATUE3 148832
#define GO_ATALAI_STATUE4 148833
#define GO_ATALAI_STATUE5 148834
#define GO_ATALAI_STATUE6 148835
#define GO_ATALAI_IDOL 148836

#define GO_ATALAI_LIGHT1 148883
#define GO_ATALAI_LIGHT2 148937

#define NPC_MALFURION_STORMRAGE 15362

struct TRINITY_DLL_DECL instance_sunken_temple : public ScriptedInstance
{
    instance_sunken_temple(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    GameObject* AtalaiStatue1;
    GameObject* AtalaiStatue2;
    GameObject* AtalaiStatue3;
    GameObject* AtalaiStatue4;
    GameObject* AtalaiStatue5;
    GameObject* AtalaiStatue6;
    GameObject* AtalaiIdol;

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
        AtalaiStatue1 = NULL;
        AtalaiStatue2 = NULL;
        AtalaiStatue3 = NULL;
        AtalaiStatue4 = NULL;
        AtalaiStatue5 = NULL;
        AtalaiStatue6 = NULL;
        AtalaiIdol = NULL;
        s1 = false;
        s2 = false;
        s3 = false;
        s4 = false;
        s5 = false;
        s6 = false;
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
     {
         switch(pGo->GetEntry())
         {
         case GO_ATALAI_STATUE1:
             AtalaiStatue1 = pGo;
             GOAtalaiStatue1 = pGo->GetGUID();
             break;
         case GO_ATALAI_STATUE2:
             AtalaiStatue2 = pGo;
             GOAtalaiStatue2 = pGo->GetGUID();
             break;
         case GO_ATALAI_STATUE3:
             AtalaiStatue3 = pGo;
             GOAtalaiStatue3 = pGo->GetGUID();
             break;
         case GO_ATALAI_STATUE4:
             AtalaiStatue4 = pGo;
             GOAtalaiStatue4 = pGo->GetGUID();
             break;
         case GO_ATALAI_STATUE5:
             AtalaiStatue5 = pGo;
             GOAtalaiStatue5 = pGo->GetGUID();
             break;
         case GO_ATALAI_STATUE6:
             AtalaiStatue6 = pGo;
             GOAtalaiStatue6 = pGo->GetGUID();
             break;
         case GO_ATALAI_IDOL:
             AtalaiIdol = pGo;
             GOAtalaiIdol = pGo->GetGUID();
             break;
         }
     };


     virtual void Update(uint32 diff) // correct order goes form 1-6
     {
         switch(State)
         {
         case GO_ATALAI_STATUE1:
            if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6)
            {
                UseStatue(AtalaiStatue1);
                s1 = true;
                State = 0;
            };
            break;
         case GO_ATALAI_STATUE2:
            if(s1 && !s2 && !s3 && !s4 && !s5 && !s6)
            {
                UseStatue(AtalaiStatue2);
                s2 = true;
                State = 0;
            };
            break;
         case GO_ATALAI_STATUE3:
            if(s1 && s2 && !s3 && !s4 && !s5 && !s6)
            {
                UseStatue(AtalaiStatue3);
                s3 = true;
                State = 0;
            };
            break;
         case GO_ATALAI_STATUE4:
            if(s1 && s2 && s3 && !s4 && !s5 && !s6)
            {
                UseStatue(AtalaiStatue4);
                s4 = true;
                State = 0;
            }
            break;
         case GO_ATALAI_STATUE5:
            if(s1 && s2 && s3 && s4 && !s5 && !s6)
            {
                UseStatue(AtalaiStatue5);
                s5 = true;
                State = 0;
            }
            break;
         case GO_ATALAI_STATUE6:
            if(s1 && s2 && s3 && s4 && s5 && !s6)
            {
                UseLastStatue(AtalaiStatue6);
                s6 = true;
                State = 0;
            }
            break;
         }
     };

     void UseStatue(GameObject* pGo)
     {
         pGo->SummonGameObject(GO_ATALAI_LIGHT1,pGo->GetPositionX(),pGo->GetPositionY(),pGo->GetPositionZ(),0,0,0,0,0,0);
         pGo->SetUInt32Value(GAMEOBJECT_FLAGS, 4);
     }
     void UseLastStatue(GameObject* pGo)
     {
         AtalaiStatue1->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue1->GetPositionX(),AtalaiStatue1->GetPositionY(),AtalaiStatue1->GetPositionZ(),0,0,0,0,0,100000);
         AtalaiStatue2->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue2->GetPositionX(),AtalaiStatue2->GetPositionY(),AtalaiStatue2->GetPositionZ(),0,0,0,0,0,100000);
         AtalaiStatue3->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue3->GetPositionX(),AtalaiStatue3->GetPositionY(),AtalaiStatue3->GetPositionZ(),0,0,0,0,0,100000);
         AtalaiStatue4->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue4->GetPositionX(),AtalaiStatue4->GetPositionY(),AtalaiStatue4->GetPositionZ(),0,0,0,0,0,100000);
         AtalaiStatue5->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue5->GetPositionX(),AtalaiStatue5->GetPositionY(),AtalaiStatue5->GetPositionZ(),0,0,0,0,0,100000);
         AtalaiStatue6->SummonGameObject(GO_ATALAI_LIGHT2,AtalaiStatue6->GetPositionX(),AtalaiStatue6->GetPositionY(),AtalaiStatue6->GetPositionZ(),0,0,0,0,0,100000);
         pGo->SummonGameObject(148838,-488.997,96.61,-189.019,-1.52,0,0,0,0,100000);
     }

     void SetData(uint32 type, uint32 data)
     {
        if (type == EVENT_STATE)
            State = data;
     }

     uint32 GetData(uint32 type)
     {
        if (type == EVENT_STATE)
            return State;
        return 0;
     }
};

InstanceData* GetInstanceData_instance_sunken_temple(Map* pMap)
{
    return new instance_sunken_temple(pMap);
}

void AddSC_instance_sunken_temple()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_sunken_temple";
    newscript->GetInstanceData = &GetInstanceData_instance_sunken_temple;
    newscript->RegisterSelf();
}
