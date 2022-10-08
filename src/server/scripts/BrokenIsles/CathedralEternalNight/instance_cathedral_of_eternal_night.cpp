/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "cathedral_of_eternal_night.h"
#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"

DoorData const doorData[] =
{
    {GO_AGRONOX_DOOR,       DATA_AGRONOX,         DOOR_TYPE_PASSAGE},
    {GO_THRASHBITE_DOOR,       DATA_THRASHBITE,         DOOR_TYPE_PASSAGE},
    {GO_THRASHBITE_DOOR_ENTER,       DATA_THRASHBITE,         DOOR_TYPE_ROOM},
    {GO_LAST_DOORS,       DATA_DOMATRAX,         DOOR_TYPE_ROOM},
    {GO_LAST_DOORS,       DATA_MEPHISTROTH,         DOOR_TYPE_ROOM},
};

class instance_cathedral_of_eternal_night : public InstanceMapScript
{
public:
    instance_cathedral_of_eternal_night() : InstanceMapScript("instance_cathedral_of_eternal_night", 1677) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_cathedral_of_eternal_night_InstanceMapScript(map);
    }

    struct instance_cathedral_of_eternal_night_InstanceMapScript : public InstanceScript
    {
        instance_cathedral_of_eternal_night_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }
        
        bool IntroTrashBiteDone = false;
        
        ObjectGuid ThrashbiteGuid{};
        ObjectGuid GazzeraxGuid{};
        ObjectGuid DomaTraxGuid{};
        ObjectGuid EgidaDomatraxStarterGuid{};
        ObjectGuid MephistrothGuid{};
        ObjectGuid EgidaMephistrothBuffGuid{};
        
        
        ObjectGuid EgidaGobFinal{};
        
        std::map<uint32, ObjectGuid> thrashbiteBookCases;
        std::vector<ObjectGuid> outroSecondBossAdds{};
        std::vector<ObjectGuid> introMephistrothAdds{};
        std::vector<ObjectGuid> eventMephistrothIllidan{};
        
        WorldLocation loc_res_pla;

        void Initialize() override
        {
            LoadDoorData(doorData);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case BOSS_THRASHBITE:    
                    if (!IntroTrashBiteDone)
                    {
                        creature->SetVisible(false);
                        creature->SetReactState(REACT_PASSIVE);
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
                    }
                    ThrashbiteGuid = creature->GetGUID();
                    break;
                case BOSS_DOMATRAX:
                    creature->SetVisible(false);
                    DomaTraxGuid = creature->GetGUID();
                    break;  
                case BOSS_MEPHISTROTH:
                    if (GetBossState(DATA_DOMATRAX) != DONE)
                    {
                        creature->SetVisible(false);
                        creature->SetReactState(REACT_PASSIVE);
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
                    }
                    MephistrothGuid = creature->GetGUID();
                    break;
                case NPC_GAZERAX:
                    if (creature->isDead())
                        IntroTrashBiteDone = true;
                    GazzeraxGuid = creature->GetGUID();
                    break;
                case 120371:
                case 118719:
                case 118717:
                    if (creature->GetPositionX() >= -487.09f && creature->GetPositionX() <= -467.62f &&
                        creature->GetPositionZ() >= 434.00f && creature->GetPositionZ() <= 443.39f)
                        outroSecondBossAdds.push_back(creature->GetGUID());
                        break;
                case NPC_EGIDA_GIVE_BUFF:
                    if (GetBossState(DATA_DOMATRAX) != DONE)
                        creature->SetVisible(false);
                    
                    EgidaMephistrothBuffGuid = creature->GetGUID();
                    break;
                case NPC_EGIDA_START:
                    if (GetBossState(DATA_DOMATRAX) == DONE)
                        creature->SetVisible(false);
                    EgidaDomatraxStarterGuid = creature->GetGUID();
                    break;
                case NPC_BATS_INTRO:
                case NPC_BATS_FLY:
                    if (GetBossState(DATA_DOMATRAX) != DONE || (creature->GetEntry() == NPC_BATS_FLY && instance->GetDifficultyID() == DIFFICULTY_HEROIC))
                    {
                        creature->SetVisible(false);
                        creature->SetReactState(REACT_PASSIVE);
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
                        introMephistrothAdds.push_back(creature->GetGUID());
                    }
                    else if (creature->GetEntry() == NPC_BATS_INTRO)
                        creature->GetMotionMaster()->MovePath(creature->GetWaypointPath(), false);
                    break;
                case NPC_ILLIDAN_VISUAL_OUT:
                    creature->SetVisible(false);
                    eventMephistrothIllidan.push_back(creature->GetGUID());
                    break;
                    
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_THRASHBITE_BOOKCASE_1:
                case GO_THRASHBITE_BOOKCASE_2:
                case GO_THRASHBITE_BOOKCASE_3:
                case GO_THRASHBITE_BOOKCASE_4:
                    thrashbiteBookCases[go->GetEntry()] = go->GetGUID();
                    break;
                case GO_EGIDA_FINAL:
                    EgidaGobFinal = go->GetGUID();
                    go->SetGoState(GetBossState(DATA_MEPHISTROTH) != DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                    break;
                case GO_AGRONOX_DOOR:
                case GO_THRASHBITE_DOOR:
                    AddDoor(go, true);
                    break;
                default:
                    break;
            }
        }
        
        void OnUnitDeath(Unit* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_GAZERAX:
                    IntroTrashBiteDone = true;
                    if (Creature* thrashbite = instance->GetCreature(ThrashbiteGuid))
                    {
                       // thrashbite->AddDelayedEvent(6000, [thrashbite]()-> void
                       // {
                            thrashbite->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            thrashbite->SetReactState(REACT_DEFENSIVE);
                        
                            thrashbite->SetVisible(true);
                           // thrashbite->CreateConversation(5043);
                       // });
                    }
                    break;
                case NPC_BATS_INTRO:
                {
                    uint8 deads_npc = 1;
                    for (auto guid : introMephistrothAdds)
                        if (Creature* creature = instance->GetCreature(guid))
                            if (creature->GetEntry() == NPC_BATS_INTRO)
                                if (creature->isDead())
                                    deads_npc++;
                                
                    if (deads_npc >= 4)
                    {
                        if (Creature* illidan = instance->SummonCreature(NPC_ILLIDAN_INTRO, { -600.66f, 2527.25f, 532.47f, 0.02f }))
                        {
                            illidan->GetMotionMaster()->MovePath(387354, false);
                           // illidan->AddDelayedEvent(10000, [illidan] () -> void
                         //   {
                                illidan->AI()->Talk(0);
                            //    illidan->AddDelayedEvent(3000, [illidan] () -> void
                             //   {
                                    illidan->CastSpell(illidan, 239485);
                                    illidan->DespawnOrUnsummon(2100);
                           //     });
                         //   });
                        }
                        if (Creature* mephistroth = instance->GetCreature(MephistrothGuid))
                        {
                          //  mephistroth->AddDelayedEvent(15000, [mephistroth] () -> void
                          //  {
                             //   mephistroth->RemoveNpcFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                                mephistroth->SetReactState(REACT_DEFENSIVE);
                                mephistroth->SetVisible(true);
                                mephistroth->CastSpell(mephistroth, 241817);
                             //   mephistroth->AddDelayedEvent(1000, [mephistroth] () -> void
                              //  {
                                    mephistroth->AI()->Talk(0);
                              //  });
                           // };
                        }
                    }
                    break;
                }
            }
        }

         bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;
            
            switch(type)
            {
                case DATA_THRASHBITE:
                    if (state != DONE)
                    {
                        for (std::map<uint32, ObjectGuid>::iterator itr = thrashbiteBookCases.begin(); itr != thrashbiteBookCases.end(); ++itr)
                            if (GameObject* cage = instance->GetGameObject(itr->second))
                                cage->SetGoState(GO_STATE_READY);
                    }
                    else
                    {
                        bool justSay = false;
                        uint8 i = 0;
                        for (auto guid : outroSecondBossAdds)
                            if (Creature* add = instance->GetCreature(guid))
                            {
                                if (add->GetEntry() == 118719 && !justSay)
                                {
                               //     add->AddDelayedEvent(4000, [add]() -> void
                                  //  {
                                        add->AI()->Talk(0);
                                 //   });
                                    
                                    justSay = true;
                                }
                                add->SetReactState(REACT_PASSIVE);
                               // add->AddDelayedEvent(6000 + 100*(i++), [add]() -> void
                               // {
                                    add->GetMotionMaster()->MovePath(387382, false);
                                    add->DespawnOrUnsummon(16000);
                             //   });
                            }
                    }
                    break;
                case DATA_DOMATRAX:
                    switch(state)
                    {
                        case NOT_STARTED:
                        {
                            if (Creature* egida = instance->GetCreature(EgidaDomatraxStarterGuid))
                            {
                                egida->SetVisible(true);
                                egida->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                                egida->CastSpell(egida, 144373);
                            }
                            break;
                        }
                        case DONE:
                        {
                            for (auto guid : introMephistrothAdds)
                                if (Creature* creature = instance->GetCreature(guid))
                                {
                                    if (creature->GetEntry() == NPC_BATS_FLY && instance->GetDifficultyID() == DIFFICULTY_HEROIC) //only myth
                                        continue;
                                    
                                    creature->SetVisible(true);
                                    if (creature->GetEntry() == NPC_BATS_INTRO)
                                    {
                                        creature->SetReactState(REACT_DEFENSIVE);
                                        creature->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                    }
                                    
                                  //  creature->AddDelayedEvent(2000, [creature]()-> void
                                 //   {
                                        if (creature->GetEntry() != NPC_BATS_FLY)
                                            creature->GetMotionMaster()->MovePath(creature->GetWaypointPath(), false);
                                   // });
                                }
                                
                            if (Creature* egida = instance->GetCreature(EgidaMephistrothBuffGuid))
                                egida->SetVisible(true);
                            
                            break;
                        }
                    }
                    break;
                case DATA_MEPHISTROTH:
                    if (GameObject* egida = instance->GetGameObject(EgidaGobFinal))
                        egida->SetGoState(state != DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                    
                    SetData(NPC_ILLIDAN_VISUAL_OUT, state != IN_PROGRESS ? 0 : 1);
                    
                    if (state == DONE)
                    {
                        if (Creature* illidan = instance->SummonCreature(NPC_ILLIDAN_INTRO, { -547.93f, 2532.18f, 533.94f, 5.01f }))
                            illidan->CastSpell(illidan, 239484);
                        
                        if (Creature* maiev = instance->SummonCreature(NPC_MAIEV_INTRO, { -579.73f, 2526.37f, 533.98f, 0.00f }))
                            maiev->GetMotionMaster()->MovePoint(0, -553.83f, 2518.90f, 533.94f);
                        
                        if (Creature* egvin = instance->SummonCreature(NPC_EGVIN_FINAL, { -546.11f, 2523.09f, 534.40f, 2.96f }))
                        {
                            egvin->CastSpell(egvin, 241351);
                          //  egvin->CreateConversation(4966);
                        }
                        
                        instance->SummonCreature(NPC_EGIDA_FINAL, { -541.89f, 2526.10f, 533.94f, 3.15f });
                    }
                    break;                    
            }
                            
            return true;
        }

      /*  void SetData(uint32 data, uint32 value) override
        {
            //switch (type)
          //  {
             //   case NPC_ILLIDAN_VISUAL_OUT:
                 //   if (!data)
                  // {
                        for (auto guid : eventMephistrothIllidan)
                            if (Creature* illidan = instance->GetCreature(guid))
                                illidan->SetVisible(false);
                    }
                 //   else
                   // {
                       // if (eventMephistrothIllidan.size() > 0)
                     //   {
                            uint8 select = urand(0, eventMephistrothIllidan.size() -1 );
                        //    if (Creature* illidan = instance->GetCreature(eventMephistrothIllidan[select]))
                          //      illidan->SetVisible(true);
                        }
                //    }
              //  default:
                 //   break;
         //   }
      //  }
        
      //  WorldLocation* GetClosestGraveYard(float x, float y, float z) override
     //   {
         //   loc_res_pla.Relocate(x, y, z);
        //    loc_res_pla.SetMapId(1677);

            uint32 graveyardId = 5891;

            if (GetBossState(DATA_DOMATRAX) == DONE || GetBossState(DATA_MEPHISTROTH) == DONE)
                graveyardId = 5953;
            else if (GetBossState(DATA_THRASHBITE) == DONE)
                graveyardId = 5952;
            else if (GetBossState(DATA_AGRONOX) == DONE)
                graveyardId = 5951;

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }
            
            return &loc_res_pla;
        }
        */
        ObjectGuid GetGuidData(uint32 type) const
        {
            switch (type)
            {
                case NPC_GAZERAX:   
                    return GazzeraxGuid;
                case BOSS_DOMATRAX:
                    return DomaTraxGuid;
                case NPC_EGIDA_START:
                    return EgidaDomatraxStarterGuid;
                case BOSS_MEPHISTROTH:
                    return MephistrothGuid;
            }
            return ObjectGuid::Empty;
        }
        
        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

         void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        } 
    };
};

void AddSC_instance_cathedral_of_eternal_night()
{
    new instance_cathedral_of_eternal_night();
}
