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
SDName: Instance_Sunken_Temple
SD%Complete: 100
SDComment:Place Holder
SDCategory: Sunken Temple
EndScriptData */

#include "ScriptMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "sunken_temple.h"

static constexpr ObjectData gameObjects[] =
{
    { GO_ATALAI_STATUE1, GO_ATALAI_STATUE1 },
    { GO_ATALAI_STATUE2, GO_ATALAI_STATUE2 },
    { GO_ATALAI_STATUE3, GO_ATALAI_STATUE3 },
    { GO_ATALAI_STATUE4, GO_ATALAI_STATUE4 },
    { GO_ATALAI_STATUE5, GO_ATALAI_STATUE5 },
    { GO_ATALAI_STATUE6, GO_ATALAI_STATUE6 }
};

static constexpr DungeonEncounterData Encounters[]
{
    { BOSS_AVATAR_OF_HAKKAR, { { 492 } } },
    { BOSS_JAMMALAN_THE_PROPHET, { { 488 } } },
    { BOSS_DREAMSCYTHE, { { 486 } } },
    { BOSS_WEAVER, { { 487 } } },
    { BOSS_MORPHAZ, { { 490 } } },
    { BOSS_HAZZAS, { { 491 } } },
    { BOSS_SHADE_OF_ERANIKUS, { { 493 } } },
};

static Position const atalalarianPos = { -466.5134f, 95.19822f, -189.6463f, 0.03490658f };
static uint8 const nStatues = 6;
static Position const statuePositions[nStatues]
{
    { -515.553f,  95.25821f, -173.707f,  0.0f },
    { -419.8487f, 94.48368f, -173.707f,  0.0f },
    { -491.4003f, 135.9698f, -173.707f,  0.0f },
    { -491.4909f, 53.48179f, -173.707f,  0.0f },
    { -443.8549f, 136.1007f, -173.707f,  0.0f },
    { -443.4171f, 53.83124f, -173.707f,  0.0f }
};

class instance_sunken_temple : public InstanceMapScript
{
public:
    instance_sunken_temple() : InstanceMapScript(STScriptName, 109) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sunken_temple_InstanceMapScript(map);
    }

    struct instance_sunken_temple_InstanceMapScript : public InstanceScript
    {
        instance_sunken_temple_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            LoadObjectData({}, gameObjects);
            LoadDungeonEncounterData(Encounters);
            State = 0;

            s1 = false;
            s2 = false;
            s3 = false;
            s4 = false;
            s5 = false;
            s6 = false;
        }

        ObjectGuid ShadeOfEranikusGUID;

        uint32 State;

        bool s1;
        bool s2;
        bool s3;
        bool s4;
        bool s5;
        bool s6;

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_AVATAR_OF_HAKKAR:      SetBossState(BOSS_AVATAR_OF_HAKKAR, DONE); break;
                case NPC_JAMMALAN_THE_PROPHET:  SetBossState(BOSS_JAMMALAN_THE_PROPHET, DONE); break;
                case NPC_DREAMSCYTHE:           SetBossState(BOSS_DREAMSCYTHE, DONE); break;
                case NPC_WEAVER:                SetBossState(BOSS_WEAVER, DONE); break;
                case NPC_MORPHAZ:               SetBossState(BOSS_MORPHAZ, DONE); break;
                case NPC_HAZZAS:                SetBossState(BOSS_HAZZAS, DONE); break;
                case NPC_SHADE_OF_ERANIKUS:     SetBossState(BOSS_SHADE_OF_ERANIKUS, DONE); break;
                default:                        break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_SHADE_OF_ERANIKUS:
                    ShadeOfEranikusGUID = creature->GetGUID();
                    if (GetBossState(BOSS_JAMMALAN_THE_PROPHET) != DONE)
                        creature->SetImmuneToAll(true);
                    break;
                default:
                    break;
            }
        }

         virtual void Update(uint32 /*diff*/) override // correct order goes form 1-6
         {
             switch (State)
             {
             case GO_ATALAI_STATUE1:
                if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue1 = GetGameObject(GO_ATALAI_STATUE1))
                        UseStatue(pAtalaiStatue1);
                    s1 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE2:
                if (s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue2 = GetGameObject(GO_ATALAI_STATUE2))
                        UseStatue(pAtalaiStatue2);
                    s2 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE3:
                if (s1 && s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue3 = GetGameObject(GO_ATALAI_STATUE3))
                        UseStatue(pAtalaiStatue3);
                    s3 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE4:
                if (s1 && s2 && s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue4 = GetGameObject(GO_ATALAI_STATUE4))
                        UseStatue(pAtalaiStatue4);
                    s4 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE5:
                if (s1 && s2 && s3 && s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue5 = GetGameObject(GO_ATALAI_STATUE5))
                        UseStatue(pAtalaiStatue5);
                    s5 = true;
                    State = 0;
                }
                break;
             case GO_ATALAI_STATUE6:
                if (s1 && s2 && s3 && s4 && s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue6 = GetGameObject(GO_ATALAI_STATUE6))
                    {
                        UseStatue(pAtalaiStatue6);
                        UseLastStatue(pAtalaiStatue6);
                    }
                    s6 = true;
                    State = 0;
                }
                break;
             }
         }

        void UseStatue(GameObject* go)
        {
            go->SummonGameObject(GO_ATALAI_LIGHT1, *go, QuaternionData::fromEulerAnglesZYX(go->GetOrientation(), 0.0f, 0.0f), 0s);
            go->SetFlag(GO_FLAG_INTERACT_COND);
        }

        void UseLastStatue(GameObject* go)
        {
            for (uint8 i = 0; i < nStatues; ++i)
                go->SummonGameObject(GO_ATALAI_LIGHT2, statuePositions[i], QuaternionData(), 0s);

            go->SummonCreature(NPC_ATALALARION, atalalarianPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case BOSS_JAMMALAN_THE_PROPHET:
                    if (state == DONE)
                        if (Creature* creature = instance->GetCreature(ShadeOfEranikusGUID))
                            creature->SetImmuneToAll(false);
                    break;
                default:
                    break;
            }
            return true;
        }

         void SetData(uint32 type, uint32 data) override
         {
            switch (type)
            {
                case EVENT_STATE:
                    State = data;
                    break;
                default:
                    break;
            }
         }

         uint32 GetData(uint32 type) const override
         {
            switch (type)
            {
                case EVENT_STATE:
                    return State;
                default:
                    break;
            }
            return 0;
         }
    };
};

void AddSC_instance_sunken_temple()
{
    new instance_sunken_temple();
}
