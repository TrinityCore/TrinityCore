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
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "sunken_temple.h"

enum TimedEvents
{
    EVENT_SPAWN_HAKKARI_BLOODKEEPER = 1,
    EVENT_SPAWN_NIGHTMARE_SUPPRESSOR = 2,
    EVENT_SPAWN_HAKKARI_MINION = 3,
};

static Position const HakkariBloodkeeperSpawnsPos[8] =
{
    { -483.465f, 272.550f, -90.640f, 0.0f },      //{ -483.20f, 272.56f, -90.64f, 0.0f },
    { -449.465f, 272.550f, -90.580f, 0.0f },      //{ -450.24f, 276.49f, -90.58f, 0.0f },
    { -479.400f, 285.461f, -90.600f, 0.0f },      //{ -480.78f, 282.72f, -90.60f, 0.0f },
    { -479.400f, 260.461f, -90.480f, 0.0f },      //{ -478.98f, 262.06f, -90.48f, 0.0f },
    { -467.067f, 290.461f, -90.600f, 0.0f },      //{ -469.55f, 290.58f, -90.60f, 0.0f },
    { -467.067f, 255.461f, -90.570f, 0.0f },      //{ -464.42f, 257.45f, -90.57f, 0.0f },
    { -455.400f, 285.461f, -90.580f, 0.0f },      //{ -458.24f, 287.90f, -90.58f, 0.0f },
    { -455.400f, 260.461f, -90.500f, 0.0f }       //{ -453.59f, 264.41f, -90.50f, 0.0f }
};

static Position const NightmareSuppressorSpawnsPos[4] =
{
    { -428.367f, 263.694f, -90.882f, 2.86277f },
    { -428.367f, 288.694f, -90.882f, 3.51888f },
    { -506.193f, 263.694f, -90.882f, 0.22388f },
    { -506.193f, 288.694f, -90.882f, 5.89048f }
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
            SetBossNumber(EncounterCount);

            State = 0;

            s1 = false;
            s2 = false;
            s3 = false;
            s4 = false;
            s5 = false;
            s6 = false;

            lockEvent = false;
            CountFlames = 0;
        }

        void Reset()
        {
            Events.Reset();
        }

        ObjectGuid GOAtalaiStatue1;
        ObjectGuid GOAtalaiStatue2;
        ObjectGuid GOAtalaiStatue3;
        ObjectGuid GOAtalaiStatue4;
        ObjectGuid GOAtalaiStatue5;
        ObjectGuid GOAtalaiStatue6;

        ObjectGuid ShadeOfHakkarGUID;
        ObjectGuid AvatarOfHakkarGUID;
        ObjectGuid NightmareSuppressorGUID;
        GuidVector EternalFlameGUIDs;
        GuidVector SummoningCircleGUIDs;
        uint32 AvatarOfHakkarEventState;
        uint8 CountFlames;
        EventMap Events;
        bool lockEvent;

        uint32 State;

        bool s1;
        bool s2;
        bool s3;
        bool s4;
        bool s5;
        bool s6;

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_ATALAI_STATUE1: GOAtalaiStatue1 = go->GetGUID();   break;
            case GO_ATALAI_STATUE2: GOAtalaiStatue2 = go->GetGUID();   break;
            case GO_ATALAI_STATUE3: GOAtalaiStatue3 = go->GetGUID();   break;
            case GO_ATALAI_STATUE4: GOAtalaiStatue4 = go->GetGUID();   break;
            case GO_ATALAI_STATUE5: GOAtalaiStatue5 = go->GetGUID();   break;
            case GO_ATALAI_STATUE6: GOAtalaiStatue6 = go->GetGUID();   break;
            case GO_ETERNAL_FLAME_1:
            case GO_ETERNAL_FLAME_2:
            case GO_ETERNAL_FLAME_3:
            case GO_ETERNAL_FLAME_4:
                EternalFlameGUIDs.push_back(go->GetGUID());
                break;
            case GO_EVIL_GOD_SUMMONING_CIRCLE:
                SummoningCircleGUIDs.push_back(go->GetGUID());
                break;
            }
        }
        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_SHADE_OF_HAKKAR:
                ShadeOfHakkarGUID = creature->GetGUID();
                break;
            case NPC_AVATAR_OF_HAKKAR:
                AvatarOfHakkarGUID = creature->GetGUID();
                break;
            case NPC_NIGHTMARE_SUPPRESSOR:
                if (creature->m_isTempWorldObject)
                    NightmareSuppressorGUID = creature->GetGUID();
                break;
            default:
                break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
            case NPC_NIGHTMARE_SUPPRESSOR:
                if (unit->ToCreature()->m_isTempWorldObject)
                {
                    NightmareSuppressorGUID.Clear();
                    if (!Events.Empty())
                        Events.ScheduleEvent(EVENT_SPAWN_NIGHTMARE_SUPPRESSOR, 50s, 60s);
                }
                break;
            default:
                break;
            }
        }

        virtual void Update(uint32 diff) override // correct order goes form 1-6
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
                    {
                        UseStatue(pAtalaiStatue6);
                        UseLastStatue(pAtalaiStatue6);
                    }
                    s6 = true;
                    State = 0;
                }
                break;
            }

            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SPAWN_HAKKARI_BLOODKEEPER:
                    if (Creature* hakkariBloodkeeper = instance->SummonCreature(NPC_HAKKARI_BLOODKEEPER, HakkariBloodkeeperSpawnsPos[urand(0, 7)]))
                        if (Unit* target = hakkariBloodkeeper->SelectNearestTarget(200))
                            hakkariBloodkeeper->AI()->AttackStart(target);
                    Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_BLOODKEEPER, 45s, 55s);
                    break;
                case EVENT_SPAWN_NIGHTMARE_SUPPRESSOR:
                    if (NightmareSuppressorGUID.IsEmpty())
                        if (Creature* nightmareSuppressor = instance->SummonCreature(NPC_NIGHTMARE_SUPPRESSOR, NightmareSuppressorSpawnsPos[urand(0, 3)]))
                        {
                            nightmareSuppressor->m_isTempWorldObject = true;
                            nightmareSuppressor->AI()->DoAction(ACTION_CAST_SUPPRESSOR_NIGHTMARE);
                        }
                    break;
                case EVENT_SPAWN_HAKKARI_MINION:
                    for (uint8 i = urand(0, 4); i < 7; ++i)
                        if (Creature* hakkariMinion = instance->SummonCreature(NPC_HAKKARI_MINION, HakkariBloodkeeperSpawnsPos[i]))
                            hakkariMinion->AI()->DoZoneInCombat();
                    Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_MINION, 25s, 32s);
                    break;
                default:
                    break;
                }
            }
        };

        void UseStatue(GameObject* go)
        {
            go->SummonGameObject(GO_ATALAI_LIGHT1, *go, QuaternionData(), 0s);
            go->SetFlag(GO_FLAG_INTERACT_COND);
        }

        void UseLastStatue(GameObject* go)
        {
            for (uint8 i = 0; i < nStatues; ++i)
                go->SummonGameObject(GO_ATALAI_LIGHT2, statuePositions[i], QuaternionData(), 0s);

            go->SummonCreature(NPC_ATALALARION, atalalarianPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min);
        }

        void EnableFlameCircle()
        {
            for (uint8 i = 0; i < 4; ++i)
                if (GameObject* eternalFlame = instance->GetGameObject(EternalFlameGUIDs[i]))
                    eternalFlame->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

            Creature* avatar = instance->GetCreature(ShadeOfHakkarGUID);
            for (uint8 i = 0; i < 8; ++i)
            {
                QuaternionData rot = QuaternionData::fromEulerAnglesZYX(0.f, 0.f, 0.f);
                if (GameObject* circle = avatar->SummonGameObject(GO_EVIL_GOD_SUMMONING_CIRCLE, HakkariBloodkeeperSpawnsPos[i], rot, 0s, GOSummonType(GO_SUMMON_TIMED_OR_CORPSE_DESPAWN)))
                {
                    circle->SetGoState(GO_STATE_READY);
                    circle->SetFlag(GO_FLAG_NOT_SELECTABLE);
                }
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;
            switch (type)
            {
            case DATA_AVATAR_OF_HAKKAR:
            {
                AvatarOfHakkarEventState = state;
                if (AvatarOfHakkarEventState == IN_PROGRESS)
                {
                    if (!lockEvent)
                    {
                        Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_BLOODKEEPER, 15s);
                        Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_MINION, 3s, 10s);
                        Events.ScheduleEvent(EVENT_SPAWN_NIGHTMARE_SUPPRESSOR, 10s);
                        EnableFlameCircle();
                        lockEvent = true;
                    }
                }
                if (AvatarOfHakkarEventState == FAIL)
                {
                    lockEvent = false;
                    if (Creature* avatar = instance->GetCreature(AvatarOfHakkarGUID))
                    {
                        avatar->DespawnOrUnsummon();
                        AvatarOfHakkarGUID.Clear();
                    }
                    if (Creature* shade = instance->GetCreature(ShadeOfHakkarGUID))
                    {
                        shade->DespawnOrUnsummon();
                        ShadeOfHakkarGUID.Clear();
                    }
                    for (uint8 i = 0; i < 4; ++i)
                        if (GameObject* eternalFlame = instance->GetGameObject(EternalFlameGUIDs[i]))
                        {
                            eternalFlame->SetFlag(GO_FLAG_NOT_SELECTABLE);
                            eternalFlame->SetGoState(GO_STATE_READY);
                        }
                    Events.Reset();
                    SetBossState(DATA_AVATAR_OF_HAKKAR, NOT_STARTED);
                }
            }
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
            case DATA_ETERNAL_FLAME:
                CountFlames = data;
                if (Creature* shade = instance->GetCreature(ShadeOfHakkarGUID)) {
                    switch (CountFlames)
                    {
                    case 1:
                        shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE1);
                        break;
                    case 2:
                        shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE2);
                        break;
                    case 3:
                        shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE3);
                        break;
                    case 4:
                        shade->DespawnOrUnsummon();
                        if (Creature* avatar = instance->GetCreature(AvatarOfHakkarGUID))
                        {
                            avatar->AI()->DoAction(ACTION_FIGHT_STATE_AVATAR);
                            avatar->AI()->DoZoneInCombat();
                        }
                        Events.Reset();
                        break;
                    default:
                        break;
                    }
                }
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
                break;
            case DATA_AVATAR_OF_HAKKAR:
                return AvatarOfHakkarEventState;
                break;
            case DATA_ETERNAL_FLAME:
                return CountFlames;
                break;
            default:
                break;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_AVATAR_OF_HAKKAR:
                return AvatarOfHakkarGUID;
                break;
            default:
                break;
            }
            return ObjectGuid::Empty;
        }

        /*void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> AvatarOfHakkarEventState;
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << AvatarOfHakkarEventState;
        }*/
    };
};

void AddSC_instance_sunken_temple()
{
    new instance_sunken_temple();
}
