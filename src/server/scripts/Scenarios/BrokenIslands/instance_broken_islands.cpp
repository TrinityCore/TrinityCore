/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "broken_islands.h"
#include "MapManager.h"
#include "Transport.h"
#include "InstanceScript.h"
#include "QuestData.h"
#include "MoveSplineInit.h"
#include "PlayerDefines.h"

class instance_broken_islands : public InstanceMapScript
{
public:
    instance_broken_islands() : InstanceMapScript("instance_broken_islands", 1460) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_broken_islands_InstanceMapScript(map);
    }

    struct instance_broken_islands_InstanceMapScript : public InstanceScript
    {
        instance_broken_islands_InstanceMapScript(Map* map) : InstanceScript(map)
        { 
        }

        void Initialize() override
        {
          //  instance->LoadGrid(461.8785f, 2032.679f);
        }

        std::map<uint32, ObjectGuid> objects;
        std::map<uint8, GuidList> final_waves;
        uint32 wave_counter = 0;
        uint8 wave_current = 0;
        uint32 count_ = 0;
        uint32 count_h = 0;
        uint32 team = 0;
        WorldLocation loc_res_pla;  // for respawn
        bool firstEnter = false;


        void OnPlayerEnter(Player* player) override
        {
            if (!team)
                team = player->GetTeam();

            if (!firstEnter)
            {
                firstEnter = true;
                player->AddDelayedEvent(5000, [player]() -> void
                {
                    if (player->GetMapId() != 1460)
                        return;

                    player->CreateConversation(player->GetTeam() == ALLIANCE ? 923 : 3598);
                    player->AddDelayedEvent(15000, [player]() -> void
                    {
                        if (player->GetMapId() != 1460)
                            return;

                        player->CreateConversation(player->GetTeam() == ALLIANCE ? 924 : 3599);
                        player->AddDelayedEvent(13100, [player]() -> void
                        {
                            if (player->GetMapId() != 1460)
                                return;

                            player->CreateConversation(player->GetTeam() == ALLIANCE ? 925 : 3600);
                        });
                    });
                });
            }

            player->KilledMonsterCredit(108920);
            player->KilledMonsterCredit(113118);

            player->ApplyModFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP, true);
            player->ApplyModFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER, false);
            player->UpdatePvP(true, true);

            for (TransportHashSet::iterator i = player->GetMap()->m_Transports.begin(); i != player->GetMap()->m_Transports.end(); ++i)
            {
                if (Transport* transport = *i)
                {
                    if ((player->GetTeam() == ALLIANCE ? TRANSPORT_ALLIANCE : TRANSPORT_HORDE) == transport->GetEntry())
                    {
                        instance->LoadGrid(521.7239f, 1862.63f);
                        instance->LoadGrid(461.8785f, 2032.679f);
                        instance->LoadGrid(472.92f, 2037.86f);
                        instance->LoadGrid(591.77f, 1898.48f);

                        transport->AddPassenger(player);

                        Movement::MoveSplineInit init(*player);

                        if (player->GetTeam() == ALLIANCE)
                        {
                            //X: 2.39286 Y: 1.694546 Z: 5.205733 O: 3.155922
                            init.MoveTo(2.39286f, 1.694546f, 5.205733f, false, true);
                            init.SetFacing(3.155922f);
                        }else
                        {
                            //X: -7.351539 Y : -3.37038 Z : 10.99244 O : 0.4190969
                            init.MoveTo(-7.351539f, -3.37038f, 10.99244f, false, true);
                            init.SetFacing(0.4190969f);
                        }

                        init.Launch();
                    }

                    transport->AddDelayedEvent(5000, [transport]() -> void
                    {
                        transport->EnableMovement(true);
                    });
                }
            }
        }
        
        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1460);

            uint32 graveyardId = 0;
            if (team)
            {
                switch(getScenarionStep())
                {
                    case 0:
                    case 1:
                    case 2:
                        graveyardId = (team == ALLIANCE ? 5021 : 5682 );
                        break;
                    case 3:
                    case 4:
                        graveyardId = (team == ALLIANCE ? 5024 : 5683);
                        break;
                    case 5:
                        graveyardId = (team == ALLIANCE ? 5025 : 5684);
                        break;
                    case 6:
                    case 7:
                        graveyardId = (team == ALLIANCE ? 5026 : 5685);
                        break;
                    case 8:
                        graveyardId = (team == ALLIANCE ? 5027 : 5686);
                        break;
                    default:
                        break;
                }
                
                if (graveyardId)
                {
                    if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
                    {
                        loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                        loc_res_pla.SetMapId(gy->MapID);
                    }
                }
            }
            return &loc_res_pla;
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                //Demons slain
                case 90686:
                case 109591:
                case 109592:
                case 109604:
                    updateCriteriaForPlayers(44095); // Alliance
                    updateCriteriaForPlayers(54116); // Horde
                    break;
                //Fel Lords slain
                case 91588:
                case 109586:
                case 109587:
                    updateCriteriaForPlayers(52643); // Alliance
                    break;
                case 113036:
                case 113037:
                case 113038:
                    updateCriteriaForPlayers(54117); // Horde
                    break;
                //Spires of Woe destroyed // vechicle id 109494
                case 91704:     // alliance
                case 110618:    // horde
                {
                    uint32 c = 0;
                    if (auto owner = unit->GetAnyOwner())
                        if (auto veh = owner->ToCreature()->GetVehicleKit())
                            for (uint32 i = 0; i < 3; ++i)
                                if (!veh->GetPassenger(i))
                                    ++c;

                    if (c >= 3)
                    {
                        //step2
                        updateCriteriaForPlayers(44077); // Alliance
                        updateCriteriaForPlayers(54114); // Horde
                        //step6
                        updateCriteriaForPlayers(44384); // Alliance

                        
                        if (GameObject* go = unit->FindNearestGameObject(240194, 20.0f))
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetPhaseMask(2, true);
                        }

                        if (auto cr = unit->GetAnyOwner()->ToCreature())
                            cr->DespawnOrUnsummon();
                    }

                    break;
                }
                //step 3
                case 90705:
                    updateCriteriaForPlayers(45131); // Alliance
                    break;
                case 93719:
                    updateCriteriaForPlayers(54109); // Horde
                    break;
                //step 5
                case 101667:
                    updateCriteriaForPlayers(45288); // Alliance
                    updateCriteriaForPlayers(54141); // Horde
                    break;
                //step6
                case 102698://1
                case 102701://2
                case 110614://1
                case 102704://1
                case 102705://1
                case 113059://1
                case 100621://1
                case 110616://7
                case 102703://1
                case 91967://5
                case 94190://4
                case 110617://6
                case 113053:
                case 113058:
                case 113054:
                case 113055:
                case 97510:
                case 113056:
                case 113057:
                    updateCriteriaForPlayers(53064);    //10 Alliance & Horde
                    break;
                case 110615://9
                case 102696://4
                case 102706://5
                case 94189://5
                case 90525://14
                    updateCriteriaForPlayers(53063);    //5 Alliance & Horde
                    break;
                case 100959://19
                case 91970://27
                case 90506://20
                case 102702://15
                case 94191://27
                    updateCriteriaForPlayers(44384);    //1 Alliance & Horde
                    break;
//---
                case 105199:
                case 111074:
                case 105200:
                case 105206:
                case 105205:
                case 111175:
                case 111174:
                case 111173:
                case 111167:
                case 111171:
                case 111156:
                case 111157:
                case 111155:
                case 105164:
                case 105165:
                case 105183:
                case 105189:
                case 105175:
                case 105174:
                case 111085:
                case 111088:
                case 111087:
                case 105197:
                case 105196:
                case 105167:
                case 111165:
                case 111149:
                case 105182:
                case 111152:
                case 111153:
                case 105188:
                case 105190:
                case 105192:
                case 111148:
                case 105185:
                case 105186:
                case 105187:
                case 105181:
                case 105179:
                case 105180:
                case 92558:
                case 111154:
                case 105163:
                case 111089:
                case 105166:
                case 91902:
                case 105176:
                case 105171:
                case 111079:
                case 105168:
                case 90688:
                case 105169:
                case 105170:
                    --wave_counter;
                    if (!wave_counter)
                    {
                        if (wave_current == 0)
                        {
                            SetData(SCENARION_STEP_9, ++wave_current);
                            Creature* gualdan = instance->GetCreature(GetGuidData(NPC_GULDAN));
                            if (!gualdan)
                                return;
                            gualdan->CastSpell(gualdan, 225239);
                        }
                        else
                        {
                            //set guialdan to.
                            Creature* gualdan = instance->GetCreature(GetGuidData(NPC_GULDAN));
                            if (!gualdan)
                                return;
                            gualdan->AI()->SetData(SCENARION_STEP_9, 2);
                        }
                    }
                    break;
            }
        }

        void updateCriteriaForPlayers(uint32 objective)
        {
            Map::PlayerList const &PlList = instance->GetPlayers();

            if (PlList.isEmpty())
                return;

            // 950 1
            // 952 2
            if (objective == 44077) // алики
            {
                if (Creature* sayer = instance->GetCreature(GetGuidData(90717)))
                {
                    switch(count_)
                    {
                        case 0:
                            sayer->CastSpell(sayer, 181978);
                            break;
                        case 1:
                            sayer->CastSpell(sayer, 199675);
                            break;
                        default:
                            break;
                    }
                }
                count_++;
            }
            
            if (objective == 54114) // орда
            {
                if (Creature* sayer = instance->GetCreature(GetGuidData(90708)))
                {
                    switch(count_)
                    {
                        case 0:
                            sayer->CastSpell(sayer, 224901);
                            break;
                        case 1:
                            sayer->CastSpell(sayer, 224901);
                            break;
                        case 2:
                            sayer->CastSpell(sayer, 224905);
                            break;
                        default:
                            break;
                    }
                }
                count_++;
            }
            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                {
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, objective);
                    break;
                }
        }
        void massive_cast(uint32 spell)
        {

            Map::PlayerList const &PlList = instance->GetPlayers();

            if (PlList.isEmpty())
                return;
            
            Quest const* quest = NULL; // some hack for atlas
            if (spell == 208513) // alliance
                quest = sQuestDataStore->GetQuestTemplate(39691);
            if (spell == 208516) // horde
                quest = sQuestDataStore->GetQuestTemplate(40976);
                
            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                Player* player = i->getSource();
                if (!player || !player->CanContact())
                    continue;

                player->AddDelayedEvent(100, [player, quest, spell]() -> void
                {
                    if (player)
                    {
                        player->CastSpell(player, spell, true);
                        if (quest && player->getClass() == CLASS_DEMON_HUNTER)
                        {
                            player->AddQuest(quest, NULL);
                            player->CompleteQuest(quest->Id);
                            player->RewardQuest(quest, 0, player);
                        }
                    }
                });
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 55091:
                if (creature->GetDistance2d(1241.09f, 2442.19f) >= 10.0f)
                    break;
                case NPC_STAGE3_HORDE_FEL_COMMANDER:
                case 90708:
                case 90717:
                case NPC_KROSS:
                case NPC_JAINA:
                case NPC_VARIAN: //appear on step3 (4)
                case NPC_GULDAN: //appear on step6 (7)
                case NPC_TIRION: //sppear on step6 (7)
                case NPC_SYLVANA:
                case 90711:
                case 90705:
                    creature->setActive(true);
                    creature->SetWorldObject(true);
                    objects[creature->GetEntry()] = creature->GetGUID();
                    break;
                //FINAL WAVES.
                //ServerToClient: SMSG_UPDATE_OBJECT (0x2802) Length: 1759 ConnIdx: 0 Time: 06/05/2016 08:38:19.304 Number: 260687
                case 105199:
                case 111074:
                case 105200:
                    final_waves[0].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient : SMSG_UPDATE_OBJECT(0x2802) Length : 512 ConnIdx : 0 Time : 06 / 05 / 2016 08 : 38 : 22.887 Number : 260790
                case 105206:
                case 105205:
                    final_waves[1].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient : SMSG_UPDATE_OBJECT(0x2802) Length : 916 ConnIdx : 0 Time : 06 / 05 / 2016 08 : 39 : 01.711 Number : 278391
                case 111175:
                case 111174:
                case 111173:
                case 111167:
                //case 105206:
                case 111171:
                case 111156:
                case 111157:
                case 111155:
                    final_waves[2].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient : SMSG_UPDATE_OBJECT(0x2802) Length : 1627 ConnIdx : 0 Time : 06 / 05 / 2016 08 : 39 : 01.779 Number : 278442
                case 105164:
                case 105165:
                case 105183:
                case 105189:
                case 105175:
                case 105174:
                case 111085:
                case 111088:
                case 111087:
                case 105197:
                case 105196:
                case 105167:
                    final_waves[3].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient: SMSG_UPDATE_OBJECT (0x2802) Length: 1211 ConnIdx: 0 Time: 06/05/2016 08:40:36.575 Number: 303933
                case 111165:
                case 111149:
                case 105182:
                case 111152:
                case 111153:
                case 105188:
                case 105190:
                case 105192:
                case 111148:
                case 105185:
                case 105186:
                case 105187:
                case 105181:
                case NPC_LORD_JAR:
                case 105180:
                case 92558:
                    if (creature->GetEntry() == NPC_LORD_JAR)
                        objects[creature->GetEntry()] = creature->GetGUID();
                    final_waves[4].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient: SMSG_UPDATE_OBJECT (0x2802) Length: 480 ConnIdx: 0 Time: 06/05/2016 08:40:42.548 Number: 304145
                case 111154:
                case 105163:
                case 111089:
                case 105166:
                case NPC_BRUTAL:
                    if (creature->GetEntry() == NPC_BRUTAL)
                        objects[creature->GetEntry()] = creature->GetGUID();
                    final_waves[5].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                //ServerToClient: SMSG_UPDATE_OBJECT (0x2802) Length: 783 ConnIdx: 0 Time: 06/05/2016 08:40:48.582 Number: 304428
                case 105176:
                case 105171:
                case 111079:
                case 105168:
                case NPC_TIHONDR:
                case 105169:
                case 105170:
                    if (creature->GetEntry() == NPC_TIHONDR)
                        objects[creature->GetEntry()] = creature->GetGUID();
                    final_waves[6].push_back(creature->GetGUID());
                    prepareWaveCre(creature);
                    break;
                case 101667: // иначе никак не хочет что-то..........
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                default:
                    break;
            }
        }

        void prepareWaveCre(Creature* creature)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            creature->SetVisible(false);
            creature->SetDisplayId(13069);
            creature->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, 0.005f);
            creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 0.01f);
        }
        void releaseWaveCre(Creature* creature, bool Final)
        {
            ++wave_counter;

            creature->SetVisible(true);
            creature->SetDisplayId(creature->GetNativeDisplayId());
            creature->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, 0.8829392f);
            creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 1.5f);
            creature->CastSpell(creature, 200312, true);
            
            if (!Final)
            {
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                creature->SetReactState(REACT_AGGRESSIVE);
                if(Creature* var = creature->FindNearestCreature(90713, 50.0f, true))
                    creature->AI()->AttackStart(var);
            }
        }

        void releaseWave(uint8 wave, bool release = true)
        {
            for (auto guid : final_waves[wave])
            {
                Creature *c = instance->GetCreature(guid);
                if (!c)
                    continue;
                releaseWaveCre(c, wave >= 2);
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case SCENARION_STEP_9:
                    wave_current = data;
                    releaseWave(data);
                    break;
                case SCENARION_STEP_END:
                    updateCriteriaForPlayers(44826);

                    if (team == ALLIANCE)
                    {
                        massive_cast(208513);
                        //Alliance teleport.
                        massive_cast(208514);
                    }
                    else
                    {
                        massive_cast(208516);
                        massive_cast(208517);
                    }
                    break;
                default:
                    break;
            }
        }
        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_ALLIANCE_SHIP:
                case GO_HORDE_SHIP:
                    go->SetVisible(false);
                    objects[go->GetEntry()] = go->GetGUID();
                    break;
            }
        }



        ObjectGuid GetGuidData(uint32 type) const override
        {
            ObjectGuid guid = ObjectGuid::Empty;
            auto data = objects.find(type);
            if (data != objects.end())
                guid = data->second;

            return guid;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SCENARIO_TEAM: //getteam.
                    return team;
                default:
                    return 0;
            }
        }


        void onScenarionNextStep(uint32 newStep) override
        {
            std::vector<uint32> const vec{ 90708 ,NPC_SYLVANA, 90717, NPC_VARIAN };
            for (auto id : vec)
                if (Creature* cre = instance->GetCreature(GetGuidData(id)))
                    cre->AI()->DoAction(newStep);

            switch (newStep)
            {
                case 2:
                    if (team == HORDE)
                    {
                        if (Creature* fel = instance->GetCreature(GetGuidData(NPC_STAGE3_HORDE_FEL_COMMANDER)))
                            fel->AI()->DoAction(NPC_STAGE3_HORDE_FEL_COMMANDER);
                    }
                    break;
                case 4:
                 //   massive_cast(218626);//scene 1356
                    break;
                
                case 5:
                    if (team == ALLIANCE)
                    {
                        massive_cast(208379);
                        if (Creature* targ = instance->GetCreature(GetGuidData(55091)))
                        {
                            if (GameObject* go = targ->FindNearestGameObject(240211, 100.0f))
                            {
                                go->SetGoState(GO_STATE_ACTIVE);
                                go->SetPhaseMask(2, true);
                            }
                            targ->DespawnOrUnsummon();
                        }
                    }
                    else
                    {
                        massive_cast(224951);
                        if (Creature* checker = instance->GetCreature(GetGuidData(90708)))
                        {
                            if (Creature* targ = checker->FindNearestCreature(55091, 150.0f))
                            {
                                if (GameObject* go = targ->FindNearestGameObject(240211, 140.0f))
                                {
                                    go->SetGoState(GO_STATE_ACTIVE);
                                    go->SetPhaseMask(2, true);
                                }
                                targ->DespawnOrUnsummon();
                            }
                        }
                    }
                    break;
                case 6:
                    if (team == ALLIANCE)
                        massive_cast(181926); // scene 1373
                    else
                        massive_cast(224998); // scene 1437
                    break;
            }
        }
    };
};

void AddSC_instance_broken_islands()
{
    new instance_broken_islands();
}
