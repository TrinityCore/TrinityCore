/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "naxxramas.h"
 
 const DoorData doorData[] =
{
    {181126,    BOSS_ANUBREKHAN,  DOOR_TYPE_ROOM,     BOUNDARY_S},
    {181195,    BOSS_ANUBREKHAN,  DOOR_TYPE_PASSAGE,           0},
    {194022,    BOSS_FAERLINA,    DOOR_TYPE_PASSAGE,           0},
    {181209,    BOSS_FAERLINA,    DOOR_TYPE_PASSAGE,           0},
    {181209,    BOSS_MAEXXNA,     DOOR_TYPE_ROOM,    BOUNDARY_SW},
    {181200,    BOSS_NOTH,        DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181201,    BOSS_NOTH,        DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181202,    BOSS_NOTH,        DOOR_TYPE_PASSAGE,           0},
    {181202,    BOSS_HEIGAN,      DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181203,    BOSS_HEIGAN,      DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181241,    BOSS_HEIGAN,      DOOR_TYPE_PASSAGE,           0},
    {181241,    BOSS_LOATHEB,     DOOR_TYPE_ROOM,     BOUNDARY_W},
    {181123,    BOSS_PATCHWERK,   DOOR_TYPE_PASSAGE,           0},
    {181123,    BOSS_GROBBULUS,   DOOR_TYPE_ROOM,              0},
    {181120,    BOSS_GLUTH,       DOOR_TYPE_PASSAGE, BOUNDARY_NW},
    {181121,    BOSS_GLUTH,       DOOR_TYPE_PASSAGE,           0},
    {181121,    BOSS_THADDIUS,    DOOR_TYPE_ROOM,              0},
    {181124,    BOSS_RAZUVIOUS,   DOOR_TYPE_PASSAGE,           0},
    {181124,    BOSS_GOTHIK,      DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181125,    BOSS_GOTHIK,      DOOR_TYPE_PASSAGE,  BOUNDARY_S},
    {181119,    BOSS_GOTHIK,      DOOR_TYPE_PASSAGE,           0},
    {181119,    BOSS_HORSEMEN,    DOOR_TYPE_ROOM,    BOUNDARY_NE},
    {181225,    BOSS_SAPPHIRON,   DOOR_TYPE_PASSAGE,  BOUNDARY_W},
    {181228,    BOSS_KELTHUZAD,   DOOR_TYPE_ROOM,     BOUNDARY_S},
    {0,         0,                DOOR_TYPE_ROOM,              0}, // EOF
};

const MinionData minionData[] =
{
    //{16573,     BOSS_ANUBREKHAN},     there is no spawn point in db, so we do not add them here
    {16506,     BOSS_FAERLINA},
    {16803,     BOSS_RAZUVIOUS},
    {16063,     BOSS_HORSEMEN},
    {16064,     BOSS_HORSEMEN},
    {16065,     BOSS_HORSEMEN},
    {30549,     BOSS_HORSEMEN},
    {0,         0, }
};

const float HeiganPos[2] = {2796, -3707};
Position const KelthuzadPos  = {3749.6799f, -5114.0600f, 142.1150f, 2.932150f};
Position const HorsemenPos  = {2521.4895f, -2953.4926f, 245.5520f, 2.357414f};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if (y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if (x > -1.0f)
        return 3;

    float slope = y/x;
    for (uint32 i = 0; i < 3; ++i)
        if (slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

class instance_naxxramas : public InstanceMapScript
{
public:
    instance_naxxramas() : InstanceMapScript("instance_naxxramas", 533) { }

    struct instance_naxxramas_InstanceMapScript : public InstanceScript
    {
        instance_naxxramas_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadMinionData(minionData);
            gothikGateGUID            = 0;
            horsemenChestGUID         = 0;
            sapphironGUID             = 0;
            faerlinaGUID              = 0;
            thaneGUID                 = 0;
            ladyGUID                  = 0;
            baronGUID                 = 0;
            sirGUID                   = 0;
            thaddiusGUID              = 0;
            heiganGUID                = 0;
            feugenGUID                = 0;
            stalaggGUID               = 0;
            kelthuzadGUID             = 0;
            kelthuzadTriggerGUID      = 0;

            Step                      = 0;
            Step2                     = 0;
            playerDied                = 0;
            gothikDoorState           = GO_STATE_ACTIVE;

            memset(portalsGUID, 0, sizeof(portalsGUID));
        }

        void OnUnitDeath(Unit* unit)
        {
            if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
            {
                playerDied = 1;
                SaveToDB();
            }
        }
		
        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_SAPPHIRON:
                    sapphironGUID = creature->GetGUID();
                    break;
                case NPC_FAERLINA:
                    faerlinaGUID = creature->GetGUID();
                    break;
                case NPC_THANE:
                    thaneGUID = creature->GetGUID();
                    break;
                case NPC_LADY:
                    ladyGUID = creature->GetGUID();
                    break;
                case NPC_BARON:
                    baronGUID = creature->GetGUID();
                    break;
                case NPC_SIR:
                    sirGUID = creature->GetGUID();
                    break;
                case NPC_THADDIUS:
                    thaddiusGUID = creature->GetGUID();
                    break;
                case NPC_HEIGAN:
                    heiganGUID = creature->GetGUID();
                    break;
                case NPC_FEUGEN:
                    feugenGUID = creature->GetGUID();
                    break;
                case NPC_STALAGG:
                    stalaggGUID = creature->GetGUID();
                    break;
                case NPC_KELTHUZAD:
                    kelthuzadGUID = creature->GetGUID();
                    break;
                case NPC_LICH_KING:
                    lichkingGUID = creature->GetGUID();
                    break;
                default:
                    break;
            }
            AddMinion(creature, true);
        }
		
        void OnCreatureRemove(Creature* creature)
        {
            AddMinion(creature, false);
        }
		
        void OnGameObjectCreate(GameObject* go)
        {
            if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
                heiganEruptionGUID[section].insert(go->GetGUID());

                return;
            }
			
            switch (go->GetEntry())
            {
                case 181126:
                case 181195:
                case 194022:
                case 181209:
                case 181200:
                case 181201:
                case 181202:
                case 181203:
                case 181241:
                case 181123:
                case 181120:
                case 181121:
                case 181124:
                case 181125:
                case 181119:
                case 181225:
                case 181228:
                    AddDoor(go, true);
                    break;
                case GO_GOTHIK_GATE:
                    gothikGateGUID = go->GetGUID();
                    go->SetGoState(gothikDoorState);
                    break;
                case GO_HORSEMEN_CHEST:
                    horsemenChestGUID = go->GetGUID();
                    break;
                case GO_HORSEMEN_CHEST_HERO:
                    horsemenChestGUID = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL01:
                    portalsGUID[0] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL02:
                    portalsGUID[1] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL03:
                    portalsGUID[2] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL04:
                    portalsGUID[3] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_TRIGGER:
                    kelthuzadTriggerGUID = go->GetGUID();
                    break;
               case GO_ARAC_PORTAL:
                    AracPortalGUID = go->GetGUID();
                    break;
               case GO_PLAG_PORTAL:
                    PlagPortalGUID = go->GetGUID();
                    break;
                case GO_MILI_PORTAL:
                    MiliPortalGUID = go->GetGUID();
                    break;
                case GO_CONS_PORTAL:
                    ConsPortalGUID = go->GetGUID();
                    break;
                default:
                    break;
            }
        }
		
        void OnGameObjectRemove(GameObject* go)
        {
            if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());

                heiganEruptionGUID[section].erase(go->GetGUID());
                return;
            }

            switch (go->GetEntry())
            {
                case 181126:
                case 181195:
                case 194022:
                case 181209:
                case 181200:
                case 181201:
                case 181202:
                case 181203:
                case 181241:
                case 181123:
                case 181120:
                case 181121:
                case 181124:
                case 181125:
                case 181119:
                case 181225:
                case 181228:
                    AddDoor(go, false);
                    break;
                case GO_BIRTH:
                    if (sapphironGUID)
                    {
                        if (Creature* pSapphiron = instance->GetCreature(sapphironGUID))
                            pSapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH);
                        return;
                    }
                    break;
                default:
                    break;
            }
        }
		
        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_ABOMINATION_KILLED:
                    return AbominationCount;
                default:
                    break;
            }

            return 0;
        }
		
        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case BOSS_FAERLINA:
                    return faerlinaGUID;
                case DATA_THANE:
                    return thaneGUID;
                case DATA_LADY:
                    return ladyGUID;
                case DATA_BARON:
                    return baronGUID;
                case DATA_SIR:
                    return sirGUID;
                case BOSS_THADDIUS:
                    return thaddiusGUID;
                case BOSS_HEIGAN:
                    return heiganGUID;
                case DATA_FEUGEN:
                    return feugenGUID;
                case DATA_STALAGG:
                    return stalaggGUID;
                case BOSS_KELTHUZAD:
                    return kelthuzadGUID;
                case DATA_LICHKING:
                    return lichkingGUID;
                case DATA_KELTHUZAD_PORTAL01:
                    return portalsGUID[0];
                case DATA_KELTHUZAD_PORTAL02:
                    return portalsGUID[1];
                case DATA_KELTHUZAD_PORTAL03:
                    return portalsGUID[2];
                case DATA_KELTHUZAD_PORTAL04:
                    return portalsGUID[3];
                case DATA_KELTHUZAD_TRIGGER:
                    return kelthuzadTriggerGUID;
            }
            return 0;
        }
		
        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;
				
            switch (type)
            {
                case BOSS_FAERLINA:
                    break;
                case BOSS_GOTHIK:
                    if (state == DONE)
                    {
                        Step2=1;
                        StepTimer2 = 100;
                        GothicEvent();
                    }
                    break;
                case BOSS_THADDIUS:
                    if (state == DONE)
                    {
                        if (GameObject* gameObject = instance->GetGameObject(ConsPortalGUID))
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        Taunt();
                    }
                    break;
                case BOSS_HEIGAN:
                    break;
                case BOSS_RAZUVIOUS:
                    break;
                case BOSS_GROBBULUS:
                    break;
                case BOSS_GLUTH:
                    break;
                case BOSS_HORSEMEN:
                    if (state == DONE)
                    {
                        if (GameObject* pHorsemenChest = instance->GetGameObject(horsemenChestGUID))
                            pHorsemenChest->SetRespawnTime(pHorsemenChest->GetRespawnDelay());
                        if (GameObject* gameObject = instance->GetGameObject(MiliPortalGUID))
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        Taunt();
                    }
                    break;
                case BOSS_ANUBREKHAN:
                    break;
                case BOSS_MAEXXNA:
                    if (state == DONE)
                    {
                        if (GameObject* gameObject = instance->GetGameObject(AracPortalGUID))
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        Taunt();
                    }
                    break;
                case BOSS_NOTH:
                    break;
                case BOSS_LOATHEB:
                    if (state == DONE)
                    {
                        if (GameObject* gameObject = instance->GetGameObject(PlagPortalGUID))
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        Taunt();
                    }
                    break;
                case BOSS_PATCHWERK:
                    break;
                case BOSS_SAPPHIRON:
                    if (state == DONE)
                    {
                        Step=1;
                        StepTimer = 100;
                        SapphironEvent();
                    }
                    break;
                case BOSS_KELTHUZAD:
                    break;
                default:
                    break;
            }
			
            return true;
        }
		
        void SetData(uint32 type, uint32 value)
        {
            switch (type)
            {
                case DATA_HEIGAN_ERUPT:
                    HeiganErupt(value);
                    break;
                case DATA_GOTHIK_GATE:
                    if (GameObject* gothikGate = instance->GetGameObject(gothikGateGUID))
                        gothikGate->SetGoState(GOState(value));
                    gothikDoorState = GOState(value);
                    break;
                case DATA_HORSEMEN0:
                case DATA_HORSEMEN1:
                case DATA_HORSEMEN2:
                case DATA_HORSEMEN3:
                    if (value == NOT_STARTED)
                    {
                        minHorsemenDiedTime = 0;
                        maxHorsemenDiedTime = 0;
                    }
                    else if (value == DONE)
                    {
                        time_t now = time(NULL);

                        if (minHorsemenDiedTime == 0)
                            minHorsemenDiedTime = now;

                        maxHorsemenDiedTime = now;
                    }
                    break;
                case DATA_ABOMINATION_KILLED:
                    AbominationCount = value;
                    break;
                default:
                    break;
            }
        }
		
        void HeiganErupt(uint32 section)
        {
            for (uint32 i = 0; i < 4; ++i)
            {
                if (i == section)
                    continue;

                for (std::set<uint64>::const_iterator itr = heiganEruptionGUID[i].begin(); itr != heiganEruptionGUID[i].end(); ++itr)
                {
                    if (GameObject* pHeiganEruption = instance->GetGameObject(*itr))
                    {
                        pHeiganEruption->SendCustomAnim(pHeiganEruption->GetGoAnimProgress());
                        pHeiganEruption->CastSpell(NULL, SPELL_ERUPTION);
                    }
                }
            }
        }

        void Taunt()
        {
            if ((GetBossState(BOSS_HORSEMEN) == DONE) ||
                (GetBossState(BOSS_LOATHEB) == DONE) ||
                (GetBossState(BOSS_MAEXXNA) == DONE) ||
                (GetBossState(BOSS_THADDIUS) == DONE))
            {
                instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                if (Creature* Kelthuzad = instance->GetCreature(kelthuzadGUID))
                    Kelthuzad->AI()->Talk(SAY_KELTHUZAD_TAUNT);
            }
        }

        void SapphironEvent()
        {
            if(!Step)
               return;

            if (GetBossState(BOSS_KELTHUZAD) == DONE)
               return;
			   
            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
            Creature* KelThuzad = instance->GetCreature(kelthuzadGUID);
            Creature* LichKing = instance->GetCreature(lichkingGUID);
			
            switch(Step)
            {
			       case 1:
                       JumpNextStep(10000);
                       break;
                   case 2:
                       KelThuzad->AI()->Talk(SAY_SAPP_DIALOG1);
                       JumpNextStep(6000);
                       break;
                   case 3:
                       LichKing->AI()->Talk(SAY_SAPP_DIALOG2_LICH);
                       JumpNextStep(16000);
                       break;
                   case 4:
                       KelThuzad->AI()->Talk(SAY_SAPP_DIALOG3);
                       JumpNextStep(9000);
                       break;
                   case 5:
                       LichKing->AI()->Talk(SAY_SAPP_DIALOG4_LICH);
                       JumpNextStep(9000);
                       break;
                   case 6:
                       KelThuzad->AI()->Talk(SAY_SAPP_DIALOG5);
                       JumpNextStep(3000);
                       break;
            }
        }
		
        void GothicEvent()
        {
            if(!Step2)
               return;

            if (GetBossState(BOSS_HORSEMEN) == DONE)
               return;
			   
            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
            Creature* Thane = instance->GetCreature(thaneGUID);
            Creature* Sir = instance->GetCreature(sirGUID);
            Creature* Lady = instance->GetCreature(ladyGUID);
            Creature* Baron = instance->GetCreature(baronGUID);
			
            switch(Step2)
            {
			       case 1:
                       Jump(10000);
                       break;
                   case 2:
                       Sir->AI()->Talk(SAY_HORSEMEN_1);
                       Jump(6000);
                       break;
                   case 3:
                       Lady->AI()->Talk(SAY_HORSEMEN_2);
                       Jump(6000);
                       break;
                   case 4:
                       Baron->AI()->Talk(SAY_HORSEMEN_3);
                       Jump(6000);
                       break;
                   case 5:
                       Lady->AI()->Talk(SAY_HORSEMEN_4);
                       Jump(5000);
                       break;
                   case 6:
                       Sir->AI()->Talk(SAY_HORSEMEN_5);
                       Jump(4000);
                       break;
                   case 7:
                       Thane->AI()->Talk(SAY_HORSEMEN_6);
                       Jump(5000);
                       break;
                   case 8:
                       Baron->AI()->Talk(SAY_HORSEMEN_7);
                       Jump(8000);
                       break;
            }
        }
		
        void JumpNextStep(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }
		
        void Jump(uint32 Time2)
        {
            StepTimer2 = Time2;
            Step2++;
        }
		
        void Update (uint32 diff)
        {
            if(!instance)
               return;
					
            if(StepTimer < diff)
                SapphironEvent();
            else StepTimer -= diff;
			
            if(StepTimer2 < diff)
                GothicEvent();
            else StepTimer2 -= diff;
            return;
        }		
		
        bool AreAllEncoutersDone()
        {
            uint32 numBossAlive = 0;
            for (uint32 i = 0; i < EncounterCount; ++i)
                if (GetBossState(i) != DONE)
                    numBossAlive++;

            if (numBossAlive > 1)
                return false;
            return true;
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/)
        {
            switch (criteria_id)
            {
                case 7600:  // Criteria for achievement 2176: And They Would All Go Down Together 15sec of each other 10-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                case 7601:  // Criteria for achievement 2177: And They Would All Go Down Together 15sec of each other 25-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_25MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                // Difficulty checks are done on DB.
                // Criteria for achievement 2186: The Immortal (25-man)
                case 13233: // The Four Horsemen
                case 13234: // Maexxna
                case 13235: // Thaddius
                case 13236: // Loatheb
                case 7616:  // Kel'Thuzad
                // Criteria for achievement 2187: The Undying (10-man)
                case 13237: // The Four Horsemen
                case 13238: // Maexxna
                case 13239: // Loatheb
                case 13240: // Thaddius
                case 7617:  // Kel'Thuzad
                    if (AreAllEncoutersDone() && !playerDied)
                        return true;
                    return false;
            }
            return false;
        }
		
        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;
			
            std::ostringstream saveStream;
            saveStream << "N X " << GetBossSaveData() << gothikDoorState << ' ' << playerDied;
			
            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char * str)
        {
            if (!str)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }
			
            OUT_LOAD_INST_DATA(str);
			
            char dataHead1, dataHead2;
			
            std::istringstream loadStream(str);
            loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'N' && dataHead2 == 'X')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }


                    uint32 temp = 0;
                    uint32 temp2 = 0;
                    loadStream >> temp;
                    gothikDoorState = GOState(temp);

                    loadStream >> temp2;
                    playerDied = temp2;
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
			
    protected:
        std::set<uint64> heiganEruptionGUID[4];
        uint64 gothikGateGUID;
        uint64 horsemenChestGUID;
        uint64 sapphironGUID;
        uint64 faerlinaGUID;
        uint64 thaneGUID;
        uint64 ladyGUID;
        uint64 baronGUID;
        uint64 sirGUID;

        uint64 thaddiusGUID;
        uint64 heiganGUID;
        uint64 feugenGUID;
        uint64 stalaggGUID;

        uint64 kelthuzadGUID;
        uint64 lichkingGUID;
        uint64 kelthuzadTriggerGUID;
        uint64 portalsGUID[4];

        uint64 AracPortalGUID;
        uint64 PlagPortalGUID;
        uint64 MiliPortalGUID;
        uint64 ConsPortalGUID;
		
        uint32 AbominationCount;

        uint32 StepTimer;
        uint32 Step;
        uint32 StepTimer2;
        uint32 Step2;
		
        GOState gothikDoorState;

        time_t minHorsemenDiedTime;
        time_t maxHorsemenDiedTime;

        uint32 playerDied;
    };
	
    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_naxxramas_InstanceMapScript(map);
    }

};

class go_naxxramas_portal : public GameObjectScript
{
    public:
        go_naxxramas_portal() : GameObjectScript("go_naxxramas_portal") {}

        bool OnGossipHello(Player* player, GameObject* go)
        {
             switch (go->GetEntry())
             {
              	case GO_ARAC_PORTAL:
                    player->TeleportTo(533, 3019.814941f, -3448.389160f, 302.194061f, 5.557699f);
                    break;
                case GO_MILI_PORTAL:
                    player->TeleportTo(533, 2991.749512f, -3420.202637f, 302.186279f, 2.290148f);
                    break;
                case GO_PLAG_PORTAL:
                    player->TeleportTo(533, 2991.559570f, -3448.530273f, 302.177795f, 3.955977f);
                    break;
                case GO_CONS_PORTAL:
                    player->TeleportTo(533, 3019.950928f, -3420.313232f, 302.184509f, 0.785320f);
                    break;
             }
             return true;
         }
 };
 
class mr_bigglesworth_npc : public CreatureScript
{
    public:
        mr_bigglesworth_npc(): CreatureScript("mr_bigglesworth_npc") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mr_bigglesworth_npcAI (creature);
    }

    struct mr_bigglesworth_npcAI : public ScriptedAI
    {
        mr_bigglesworth_npcAI(Creature *c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;
		

			
        void JustDied(Unit* killer)
        {
            if (instance->GetBossState(BOSS_KELTHUZAD) == DONE)
                return;
            me->GetMap()->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());	
            if (Creature* KelThuzad = Unit::GetCreature(*me, instance ? instance->GetData64(BOSS_KELTHUZAD) : 0))
            {
                KelThuzad->AI()->Talk(SAY_CAT_DIED);
            }
        }
    };
};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
    new mr_bigglesworth_npc();
    new go_naxxramas_portal();
}