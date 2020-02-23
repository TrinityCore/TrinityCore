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

 /*
 This placeholder for the instance is needed for dungeon finding to be able
 to give credit after the boss defined in lastEncounterDungeon is killed.
 Without it, the party doing random dungeon won't get satchel of spoils and
 gets instead the deserter debuff.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "GameObject.h"

 // Bosses (East)
 // 0 - Pusillin
 // 1 - Lethtendris
 // 2 - Hydrospawn
 // 3 - Zevrim Thornhoof
 // 4 - Alzzin the Wildshaper

 // West
 // 5 - Tendris Warpwood
 // 6 - Magister Kalendris
 // 7 - Tsu'zee
 // 8 - Illyanna Ravenoak
 // 9 - Immol'thar
 // 10 - Prince Tortheldrin

 // North
 // 11 - Guard Mol'dar
 // 12 - Stomper Kreeg
 // 13 - Guard Fengus
 // 14 - Guard Slip'kik
 // 15 - Captain Kromcrush
 // 16 - King Gordok

uint8 const EncounterCount = 17;

#ifndef GOSSIP_MENU_IRONBARK_THE_REDEEMED
#define GOSSIP_MENU_IRONBARK_THE_REDEEMED 5602
#endif

// EJ scripts
enum DIRE_MAUL_NPC
{
    NPC_ZEVRIM_THORNHOOF = 11490,
    NPC_OLD_IRONBARK = 11491,
    NPC_IRONBARK_THE_REDEEMED = 14241,
};

enum DIRE_MAUL_GAMEOBJECT
{
    GAMEOBJECT_CONSERVATORY_DOOR = 176907,
};

enum DIRE_MAUL_BOSS
{
    BOSS_ZEVRIM_THORNHOOF = 0,
};

enum DIRE_MAUL_WAYPOINT
{
    WAYPOINT_IRONBARK_THE_REDEEMED = 569430,
};

enum DIRE_MAUL_LINE_OLD_IRONBARK
{
    LINE_OLD_IRONBARK_0 = 0,
};

enum DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED
{
    LINE_IRONBARK_THE_REDEEMED_0 = 0,
    LINE_IRONBARK_THE_REDEEMED_1 = 1,
    LINE_IRONBARK_THE_REDEEMED_2 = 2,
};

enum DIRE_MAUL_DATA
{
    DATA_OLD_IRONBARK_REDEEM = 0,
    DATA_CONSERVATORY_DOOR_SPAWN_ID = 1,
};

enum DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED
{
    EVENT_TALK_0 = 1,
    EVENT_MOVE_WAY = 2,
    EVENT_OPEN_DOOR_EMOTE = 3,
    EVENT_DOOR_OPEN = 4,
    EVENT_TALK_1 = 5,
    EVENT_FAKE_DEATH = 6,
    EVENT_TALK_2 = 7,
    EVENT_DESPAWN = 8,
};

class instance_dire_maul : public InstanceMapScript
{
public:
    instance_dire_maul() : InstanceMapScript("instance_dire_maul", 429) { }

    struct instance_dire_maul_InstanceMapScript : public InstanceScript
    {
        instance_dire_maul_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(EncounterCount);
            SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::NOT_STARTED);
        }

        ObjectGuid OGBossZevrimThornhoof;
        ObjectGuid OGOldIronbark;
        uint32 siConservatoryDoor;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case DIRE_MAUL_NPC::NPC_OLD_IRONBARK:
            {
                OGOldIronbark = creature->GetGUID();
                creature->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                break;
            }
            case DIRE_MAUL_NPC::NPC_ZEVRIM_THORNHOOF:
            {
                OGBossZevrimThornhoof = creature->GetGUID();
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_CONSERVATORY_DOOR:
            {
                siConservatoryDoor = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DIRE_MAUL_DATA::DATA_OLD_IRONBARK_REDEEM)
            {
                if (Creature* checkC = instance->GetCreature(OGOldIronbark))
                {
                    checkC->AI()->Talk(DIRE_MAUL_LINE_OLD_IRONBARK::LINE_OLD_IRONBARK_0);
                    checkC->UpdateEntry(DIRE_MAUL_NPC::NPC_IRONBARK_THE_REDEEMED);
                    checkC->SetFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DIRE_MAUL_DATA::DATA_CONSERVATORY_DOOR_SPAWN_ID)
            {
                return siConservatoryDoor;
            }
            return 0;
        }

        virtual void Update(uint32 diff) override
        {
            if (GetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF) == EncounterState::NOT_STARTED)
            {
                if (Creature* checkBoss = instance->GetCreature(OGBossZevrimThornhoof))
                {
                    if (checkBoss->IsInCombat())
                    {
                        SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::IN_PROGRESS);
                    }
                }
            }
            else if (GetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF) == EncounterState::IN_PROGRESS)
            {
                if (Creature* checkBoss = instance->GetCreature(OGBossZevrimThornhoof))
                {
                    if (!checkBoss->IsAlive())
                    {
                        SetData(DIRE_MAUL_DATA::DATA_OLD_IRONBARK_REDEEM, 0);
                        SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::DONE);
                    }
                    else if (!checkBoss->IsInCombat())
                    {
                        SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::NOT_STARTED);
                    }
                }
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dire_maul_InstanceMapScript(map);
    }
};

class npc_ironbark_the_redeemed : public CreatureScript
{
public:
    npc_ironbark_the_redeemed() : CreatureScript("npc_ironbark_the_redeemed") { }

    struct npc_ironbark_the_redeemedAI : public ScriptedAI
    {
        npc_ironbark_the_redeemedAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }

        void Reset() override
        {
            events.Reset();
        }

        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == GOSSIP_MENU_IRONBARK_THE_REDEEMED && gossipListId == 0)
            {
                me->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_0, 2000);
                events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_MOVE_WAY, 4000);
                return true;
            }
            return false;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 4:
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE, 2000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE, 5000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DOOR_OPEN, 7000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_1, 10000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_FAKE_DEATH, 15000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_2, 25000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DESPAWN, 35000);
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            if (events.Empty())
            {
                return;
            }
            switch (events.ExecuteEvent())
            {
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_0:
            {
                me->AI()->Talk(DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED::LINE_IRONBARK_THE_REDEEMED_0);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_MOVE_WAY:
            {
                me->StopMoving();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePath(DIRE_MAUL_WAYPOINT::WAYPOINT_IRONBARK_THE_REDEEMED, false);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE:
            {
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_ATTACK_UNARMED);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DOOR_OPEN:
            {
                if (Map* myMap = me->GetMap())
                {
                    if (InstanceScript* is = me->GetInstanceScript())
                    {
                        if (GameObject* goDoor = myMap->GetGameObjectBySpawnId(is->GetData(DIRE_MAUL_DATA::DATA_CONSERVATORY_DOOR_SPAWN_ID)))
                        {
                            goDoor->SetGoState(GOState::GO_STATE_ACTIVE);
                        }
                    }
                }
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_1:
            {
                me->AI()->Talk(DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED::LINE_IRONBARK_THE_REDEEMED_1);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_FAKE_DEATH:
            {
                me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_DEAD);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_2:
            {
                me->AI()->Talk(DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED::LINE_IRONBARK_THE_REDEEMED_2);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DESPAWN:
            {
                me->DespawnOrUnsummon(100, 24h * 7);
                break;
            }
            default:
            {
                break;
            }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ironbark_the_redeemedAI(creature);
    }
};

void AddSC_instance_dire_maul()
{
    new instance_dire_maul();
    new npc_ironbark_the_redeemed();
}
