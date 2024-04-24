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
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "CreatureAI.h"
#include "Map.h"
#include "sunken_temple.h"

enum TimedEvents
{
    EVENT_SPAWN_HAKKARI_BLOODKEEPER  = 1,
    EVENT_SPAWN_NIGHTMARE_SUPPRESSOR = 2,
    EVENT_SPAWN_HAKKARI_MINION       = 3,
};

static constexpr DoorData doorData[] =
{
    { GO_AVATAR_OF_HAKKAR_DOOR, BOSS_AVATAR_OF_HAKKAR,   DOOR_TYPE_ROOM },
    { GO_FORCEFIELD,            BOSS_EVENT_ELITE_TROLLS, DOOR_TYPE_PASSAGE },
    { 0,                        0,                       DOOR_TYPE_ROOM }  // END
};

static constexpr ObjectData gameObjects[] =
{
    { GO_ATALAI_STATUE1,  GO_ATALAI_STATUE1 },
    { GO_ATALAI_STATUE2,  GO_ATALAI_STATUE2 },
    { GO_ATALAI_STATUE3,  GO_ATALAI_STATUE3 },
    { GO_ATALAI_STATUE4,  GO_ATALAI_STATUE4 },
    { GO_ATALAI_STATUE5,  GO_ATALAI_STATUE5 },
    { GO_ATALAI_STATUE6,  GO_ATALAI_STATUE6 },
    { GO_ETERNAL_FLAME_1, GO_ETERNAL_FLAME_1 },
    { GO_ETERNAL_FLAME_2, GO_ETERNAL_FLAME_2 },
    { GO_ETERNAL_FLAME_3, GO_ETERNAL_FLAME_3 },
    { GO_ETERNAL_FLAME_4, GO_ETERNAL_FLAME_4 },
    { 0,                  0 } // END
};

static Position const HakkariBloodkeeperSpawnsPos[8] =
{
    { -483.465f, 272.550f, -90.640f, 0.0f },
    { -449.465f, 272.550f, -90.580f, 0.0f },
    { -479.400f, 285.461f, -90.600f, 0.0f },
    { -479.400f, 260.461f, -90.480f, 0.0f },
    { -467.067f, 290.461f, -90.600f, 0.0f },
    { -467.067f, 255.461f, -90.570f, 0.0f },
    { -455.400f, 285.461f, -90.580f, 0.0f },
    { -455.400f, 260.461f, -90.500f, 0.0f }
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
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doorData);
            LoadObjectData(nullptr, gameObjects);
            State = 0;

            s1 = false;
            s2 = false;
            s3 = false;
            s4 = false;
            s5 = false;
            s6 = false;
            EliteTrollsKilled = 0;
            LockEvent = false;
            CountFlames = 0;
        }

        void Reset()
        {
            Events.Reset();
        }

        ObjectGuid JammalAnTheProphetGUID;
        ObjectGuid ShadeOfEranikusGUID;
        ObjectGuid ShadeOfHakkarGUID;
        ObjectGuid AvatarOfHakkarGUID;
        ObjectGuid NightmareSuppressorGUID;
        GuidVector EternalFlameGUIDs;
        uint32 EliteTrollsKilled;
        uint32 AvatarOfHakkarEventState;
        uint8 CountFlames;
        EventMap Events;
        bool LockEvent;

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
            case NPC_ATALALARION:           SetBossState(BOSS_ATALALARION, DONE); break;
            case NPC_ZOLO:
            case NPC_GASHER:
            case NPC_LORO:
            case NPC_HUKKU:
            case NPC_ZUL_LOR:
            case NPC_MIJAN:                 SetData(BOSS_EVENT_ELITE_TROLLS, EliteTrollsKilled + 1); break;
            case NPC_NIGHTMARE_SUPPRESSOR:
                if (unit->ToCreature()->m_isTempWorldObject)
                {
                    NightmareSuppressorGUID.Clear();
                    if (!Events.Empty())
                        Events.ScheduleEvent(EVENT_SPAWN_NIGHTMARE_SUPPRESSOR, 15s, 45);
                }
                break;
            default:
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
            case NPC_JAMMALAN_THE_PROPHET:
                JammalAnTheProphetGUID = creature->GetGUID();
                if (GetBossState(BOSS_EVENT_ELITE_TROLLS) != DONE)
                {
                    creature->SetImmuneToPC(true);
                    creature->CastSpell(creature, SPELL_GREEN_CHANNELING);
                }
                break;
            case NPC_SHADE_OF_ERANIKUS:
                ShadeOfEranikusGUID = creature->GetGUID();
                if (GetBossState(BOSS_JAMMALAN_THE_PROPHET) != DONE)
                    creature->SetImmuneToAll(true);
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

            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SPAWN_HAKKARI_BLOODKEEPER:
                    if (Creature* hakkariBloodkeeper = instance->SummonCreature(NPC_HAKKARI_BLOODKEEPER, HakkariBloodkeeperSpawnsPos[urand(0, 7)]))
                        if (Unit* target = hakkariBloodkeeper->SelectNearestTarget(200.0f))
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
            for (uint32 i = GO_ETERNAL_FLAME_1; i <= GO_ETERNAL_FLAME_4; ++i)
                if (GameObject* eternalFlame = GetGameObject(i))
                    eternalFlame->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            if (ShadeOfHakkarGUID)
            { 
                Creature* shade = instance->GetCreature(ShadeOfHakkarGUID);
                for (uint8 i = 0; i < 8; ++i)
                {
                    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(0.f, 0.f, 0.f);
                    if (GameObject* circle = shade->SummonGameObject(GO_EVIL_GOD_SUMMONING_CIRCLE, HakkariBloodkeeperSpawnsPos[i], rot, 0s, GOSummonType(GO_SUMMON_TIMED_OR_CORPSE_DESPAWN)))
                    {
                        circle->SetGoState(GO_STATE_READY);
                        circle->SetFlag(GO_FLAG_NOT_SELECTABLE);
                    }
                }
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case BOSS_AVATAR_OF_HAKKAR:
            {
                AvatarOfHakkarEventState = state;
                if (AvatarOfHakkarEventState == IN_PROGRESS)
                {
                    if (!LockEvent)
                    {
                        Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_BLOODKEEPER, 15s);
                        Events.ScheduleEvent(EVENT_SPAWN_HAKKARI_MINION, 3s, 10s);
                        Events.ScheduleEvent(EVENT_SPAWN_NIGHTMARE_SUPPRESSOR, 10s);
                        EnableFlameCircle();
                        LockEvent = true;
                    }
                }
                if (AvatarOfHakkarEventState == FAIL)
                {
                    LockEvent = false;
                    if (Creature* avatar = instance->GetCreature(AvatarOfHakkarGUID))
                    {
                        avatar->DespawnOrUnsummon();
                        AvatarOfHakkarGUID.Clear();
                    }
                    ShadeOfHakkarGUID.Clear();
                    for (uint32 i = GO_ETERNAL_FLAME_1; i <= GO_ETERNAL_FLAME_4; ++i)
                        if (GameObject* eternalFlame = GetGameObject(i))
                        {
                            eternalFlame->SetFlag(GO_FLAG_NOT_SELECTABLE);
                            eternalFlame->SetGoState(GO_STATE_READY);
                        }
                    Events.Reset();
                    SetBossState(BOSS_AVATAR_OF_HAKKAR, NOT_STARTED);
                }
            }
            break;
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
            case DATA_ETERNAL_FLAME:
                CountFlames = data;
                if (Creature* shade = instance->GetCreature(ShadeOfHakkarGUID)) {
                    switch (CountFlames)
                    {
                    case 1: shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE1); break;
                    case 2: shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE2); break;
                    case 3: shade->AI()->Talk(SAY_ETHERNAL_FLAME_SHADE3); break;
                    case 4:
                        shade->DespawnOrUnsummon();
                        if (Creature* avatar = instance->SummonCreature(NPC_AVATAR_OF_HAKKAR, AvatarHakkarSpawnPos))
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
            case BOSS_EVENT_ELITE_TROLLS:
                EliteTrollsKilled = data;
                if (EliteTrollsKilled == 6)
                {
                    if (Creature* jammal = instance->GetCreature(JammalAnTheProphetGUID))
                        jammal->SetImmuneToPC(false);
                    SetBossState(BOSS_EVENT_ELITE_TROLLS, DONE);
                }
                SaveToDB();
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
            case BOSS_AVATAR_OF_HAKKAR:
                return AvatarOfHakkarEventState;
            case BOSS_EVENT_ELITE_TROLLS:
                return EliteTrollsKilled;
            case DATA_ETERNAL_FLAME:
                return CountFlames;
            default:
                break;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case BOSS_AVATAR_OF_HAKKAR:
                return AvatarOfHakkarGUID;
                break;
            case DATA_SHADE_OF_HAKKAR:
                return ShadeOfHakkarGUID;
                break;
            default:
                break;
            }
            return ObjectGuid::Empty;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> EliteTrollsKilled;
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << EliteTrollsKilled;
        }
    };
};

void AddSC_instance_sunken_temple()
{
    new instance_sunken_temple();
}
