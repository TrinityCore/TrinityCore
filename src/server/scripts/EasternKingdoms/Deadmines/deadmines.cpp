/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "deadmines.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

enum eSpels
{
    SPELL_CANNONBALL        = 89697, // 91066 (HC) supported by Spell Difficulty
    SPELL_THROW             = 91038,
    SPELL_THROW_H           = 91039,
    SPELL_EXPLODE           = 89769,
    SPELL_EYE_GOUGE         = 90913,
    SPELL_EYE_GOUGE_H       = 90918,
    SPELL_EYE_PECK          = 90920,
    SPELL_EYE_PECK_H        = 90921,
};

Position const SourcePosition[8] =
{
    {-30.2622f, -793.069f, 19.237f},
    {-72.1059f, -786.894f, 39.5538f},
    {-58.6424f, -787.132f, 39.3505f},
    {-82.3142f, -775.5f,   26.8933f},
    {-46.901f,  -783.155f, 18.4898f},
    {-89.2569f, -782.528f, 17.2564f},
    {-122.925f, -388.813f, 59.0769f},
    {-40.0035f, -793.302f, 39.4754f},
};

Position const TargetPosition[8] =
{
    {0.512153f, -768.229f, 9.80134f},
    {-72.559f,  -731.221f, 8.5869f},
    {-49.3264f, -730.056f, 9.32048f},
    {-100.849f, -703.773f, 9.29407f},
    {-30.6337f, -727.731f, 8.52102f},
    {-88.4253f, -724.722f, 8.67503f},
    {-91.9409f, -375.307f, 57.9774f},
    {-12.0556f, -740.252f, 9.10946f},
};

/**
 * TODO: this npc is also used in Ship and require 48522
 */
class npc_defias_cannon : public CreatureScript
{
public:
    npc_defias_cannon() : CreatureScript("npc_defias_cannon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_cannonAI(creature);
    }

    struct npc_defias_cannonAI : public ScriptedAI
    {
        npc_defias_cannonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 Phase;
        uint32 CannonBlast_Timer;
        ObjectGuid TargetGUID;

        void Reset() override
        {
            Phase = 0;
            CannonBlast_Timer = DATA_CANNON_BLAST_TIMER;
            if (!me)
                return;

            if (!ObjectAccessor::GetPlayer(*me, TargetGUID))
                GetCreature();
        }

        bool GetSupporter()
        {
            Creature* supporter = me->FindNearestCreature(NPC_OGRE_HENCHMAN, 7.0f, true);
            if (supporter)
                return true;

            supporter = me->FindNearestCreature(NPC_DEFIAS_PIRATE, 5.0f, true);
            if (supporter)
                return true;

            return false;
        }

        void EnterCombat(Unit* /*who*/) override { }

        void GetCreature()
        {
            if (!me)
                return;

            for (uint8 i = 0; i <= 7; i++)
            {
                if (me->IsInDist(&SourcePosition[i], 1.0f))
                {
                    TargetGUID = me->SummonCreature(NPC_SCORCH_MARK_BUNNY_JMF, TargetPosition[i])->GetGUID();
                    break;
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me)
                return;

            if (Phase == 0)
            {
                if (CannonBlast_Timer <= uiDiff)
                {
                    if (!GetSupporter())
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Phase++;
                    } else if (Creature* target = ObjectAccessor::GetCreature(*me, TargetGUID))
                    {
                        me->CastSpell(target, SPELL_CANNONBALL);
                    }
                    CannonBlast_Timer = urand(3000, 5000);
                } else
                    CannonBlast_Timer -= uiDiff;
            }
        }
    };
};

class npc_mining_monkey : public CreatureScript
{
public:
    npc_mining_monkey() : CreatureScript("npc_mining_monkey") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mining_monkeyAI(creature);
    }

    struct npc_mining_monkeyAI : public ScriptedAI
    {
        npc_mining_monkeyAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 Phase;
        uint32 uiTimer;

        void Reset() override
        {
            Phase = 1;
            uiTimer = 2000;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!me)
                return;

            if (Phase == 1)
            {
                if (me->GetHealth()-damage <= me->GetMaxHealth()*0.15)
                {
                    Phase++;
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!me)
                return;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me || !me->AI() || !UpdateVictim())
                return;

            switch (Phase)
            {
                case 1:
                    if (Unit* victim = me->GetVictim())
                    {
                        if (me->IsInRange(victim, 0, 35.0f, true))
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                            if (uiTimer <= uiDiff)
                            {
                                me->CastSpell(victim, IsHeroic() ? SPELL_THROW_H : SPELL_THROW);
                                uiTimer = 2000;
                            } else
                                uiTimer -= uiDiff;
                        } else
                        {
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                        }
                    }
                    break;
                case 2:
                    Talk(0);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Phase++;
                    break;
                default:
                    me->DoFleeToGetAssistance();
                    break;
            }
        }
    };
};

/**
 * explode door and say mobs after Door to attack tank...
 */
class go_defias_cannon : public GameObjectScript
{
public:
    go_defias_cannon() : GameObjectScript("go_defias_cannon") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (!go || !player)
            return false;

        if (GameObject* ironCladDoor = go->FindNearestGameObject(GO_IRONCLAD_DOOR, 30.0f))
        {
            go->SetGoState(GO_STATE_ACTIVE);
            go->PlayDistanceSound(SOUND_CANNONFIRE, player);
            ironCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
            ironCladDoor->PlayDistanceSound(SOUND_DESTROYDOOR, player);

            MoveCreatureInside(go, NPC_DEFIAS_SHADOWGUARD);
            MoveCreatureInside(go, NPC_DEFIAS_ENFORCER);
            MoveCreatureInside(go, NPC_DEFIAS_BLOODWIZARD);
            if (Creature* bunny = go->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ()))
            {
                bunny->AI()->Talk(0);
            }
        }
        return true;
    }

    void MoveCreatureInside(GameObject* go, uint32 entry)
    {
        if (!go || entry <= 0)
            return;

        if (Creature* defias = go->FindNearestCreature(entry, 20.0f))
        {
            defias->SetWalk(false);
            defias->GetMotionMaster()->MovePoint(0, -102.7f, -655.9f, defias->GetPositionZ());
        }
    }
};

class npc_deadmines_bird : public CreatureScript
{
public:
    npc_deadmines_bird() : CreatureScript("npc_deadmines_bird") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_deadmines_birdAI(creature);
    }

    struct npc_deadmines_birdAI : public ScriptedAI
    {
        npc_deadmines_birdAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 uiTimerEyePeck;
        uint32 uiTimerEyeGouge;

        void Reset() override
        {
            uiTimerEyePeck  = urand(4000, 4900);
            uiTimerEyeGouge = urand(7000, 9000);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me)
                return;

            if (!UpdateVictim())
                return;

            if (uiTimerEyeGouge <= uiDiff)
            {
                if (Unit* victim = me->GetVictim())
                {
                    me->CastSpell(victim, IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                }
                uiTimerEyeGouge = urand(9000, 12000);
                return;
            } else
                uiTimerEyeGouge -= uiDiff;

            if (uiTimerEyePeck <= uiDiff)
            {
                if (Unit* victim = me->GetVictim())
                {
                    me->CastSpell(victim, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                }
                uiTimerEyePeck = urand(16000, 19000);
                return;
            } else
                uiTimerEyePeck -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_goblin_engineer : public CreatureScript
{
public:
    npc_goblin_engineer() : CreatureScript("npc_goblin_engineer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_goblin_engineerAI(creature);
    }

    struct npc_goblin_engineerAI : public ScriptedAI
    {
        npc_goblin_engineerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        void Reset() override
        {
            if (!me)
                return;

            if (me->FindNearestGameObject(GO_HEAVY_DOOR, 20.0f))
                me->AddAura(78087, me);
            else
                me->AddAura(57626, me);
        }

        void UpdateAI(uint32 /*uiDiff*/) override { }
    };
};

class go_heavy_door : public GameObjectScript
{
public:
    go_heavy_door() : GameObjectScript("go_heavy_door") { }

    void MoveNearCreature(GameObject* me, uint32 entry, uint32 ragne)
    {
        if (!me)
            return;

        std::list<Creature*> creature_list;
        me->GetCreatureListWithEntryInGrid(creature_list, entry, ragne);

        creature_list.sort(Trinity::ObjectDistanceOrderPred(me));
        for (std::list<Creature*>::iterator itr = creature_list.begin(); itr != creature_list.end(); ++itr)
        {
            if (( *itr ) && ( *itr )->IsAlive() && ( *itr )->GetTypeId() == TYPEID_UNIT && ( *itr )->HasAura(78087))
            {
                ( *itr )->GetMotionMaster()->MoveCharge( me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 5.0f);
                ( *itr )->DespawnOrUnsummon(3000);
                ( *itr )->AI()->Talk(0);
            }
        }
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (!go || !player)
            return false;

        MoveNearCreature(go, 48439, 50.0f);
        MoveNearCreature(go, 48280, 50.0f);

        return true;
    }
};

#define GOSSIP_BOSS_1 "Press the button labeled 'Wood and Lumber.'"
#define GOSSIP_BOSS_2 "Press the button labeled 'Metal and Scraps.'"
#define GOSSIP_BOSS_3 "Press the button labeled 'Ship Parts.'"

class go_deadmines_tp : public GameObjectScript
{
public:
    go_deadmines_tp() : GameObjectScript("go_deadmines_tp") { }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 action) override
    {
        if (player->HasAura(SPELL_NIGHTMARE_ELIXIR))
            return false;

        player->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(player);
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->TeleportTo(player->GetMapId(), -305.32f, -491.29f, 49.23f, 3.14f);
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->TeleportTo(player->GetMapId(), -201.09f, -606.04f, 19.30f, 3.14f);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->TeleportTo(player->GetMapId(), -129.91f, -788.89f, 17.34f, 3.14f);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->HasAura(SPELL_NIGHTMARE_ELIXIR))
            return false;

        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return false;

        if (instance->GetBossState(DATA_HELIX) == DONE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_BOSS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        }
        if (instance->GetBossState(DATA_FOEREAPER) == DONE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_BOSS_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }
        if (instance->GetBossState(DATA_RIPSNARL) == DONE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_BOSS_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        }
        SendGossipMenuFor(player, player->GetGossipTextId(go), go->GetGUID());
        return true;
    }
};


class npc_mining_powder : public CreatureScript
{
public:
    npc_mining_powder() : CreatureScript("npc_mining_powder") { }

    struct npc_mining_powderAI : public ScriptedAI
    {
        npc_mining_powderAI(Creature* creature) : ScriptedAI(creature), damaged(false) { }

        bool damaged;

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (damaged)
                return;
            damaged = true;
            me->CastSpell(me, SPELL_EXPLODE);
            me->DespawnOrUnsummon(100);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mining_powderAI(creature);
    }
};

static const Position entryPosition = { -97.6376f, -690.562f, 24.3914f };
static const Position leavePosition = { -19.5636f, -377.193f, 60.8038f };

Position const visionWaypoints[] =
{
    { -96.52084f, -701.3229f, 26.23725f },
    { -72.3125f,  -732.9184f, 34.70948f },
    { -40.28125f, -763.783f,  43.5428f  },
    { -2.125f,    -818.7014f, 57.0428f  },
    { -27.65799f, -850.7101f, 57.0428f  },
    { -63.17188f, -829.3177f, 47.68164f },
};

enum VisionData
{
    EVENT_START_MOVEMENT        = 1,
    EVENT_DMGROUP_START_COMBAT  = 2,
    EVENT_REWARD_PASSENGER_PLR  = 3,
    EVENT_EXIT_VISION           = 4,

    NPC_VISION_OF_THE_PAST      = 42693,

    ACTION_START_FIGHT          = 1,
    ACTION_VANCLEEF_DEAD        = 2,

    SAY_VISION_INTRO            = 0,

    SPELL_QUEST_CREDIT          = 79620,
};

struct npc_vision_of_the_past : public ScriptedAI
{
    npc_vision_of_the_past(Creature* creature) : ScriptedAI(creature) { }

    void MovementInform(uint32 /*type*/, uint32 pointId) override
    {
        if (pointId == 0)
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetData(EVENT_VISION_OF_THE_PAST, IN_PROGRESS);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_VANCLEEF_DEAD)
            _events.ScheduleEvent(EVENT_REWARD_PASSENGER_PLR, 3000);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            who->SetCanFly(true);
            who->SetDisableGravity(true);

            me->SetCanFly(true);
            me->NearTeleportTo(entryPosition, false);

            Talk(SAY_VISION_INTRO, who);

            _events.ScheduleEvent(EVENT_START_MOVEMENT, 3000);
        }
        else
        {
            who->SetCanFly(false);
            who->SetDisableGravity(false);
            who->NearTeleportTo(leavePosition, false);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_START_MOVEMENT:
                    me->GetMotionMaster()->MoveSmoothPath(0, visionWaypoints, 6, false, true);
                    break;
                case EVENT_REWARD_PASSENGER_PLR:
                    _events.ScheduleEvent(EVENT_EXIT_VISION, 1000);
                    if (Unit* passenger = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                    {
                        me->NearTeleportTo(leavePosition, false);
                        passenger->CastSpell(passenger, SPELL_QUEST_CREDIT, true);
                    }
                    break;
                case EVENT_EXIT_VISION:
                    me->GetCharmerOrOwnerPlayerOrPlayerItself()->ExitVehicle();
                    me->DespawnOrUnsummon(1000);
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum VanCleefData
{
    SAY_VANCLEEF_INTRO              = 0,
    SAY_VANCLEEF_COMBAT_1           = 1,
    SAY_VANCLEEF_COMBAT_2           = 3,
    SAY_VANCLEEF_COMBAT_3           = 4,

    ACTION_VANESSA_RUNS_TO_EDWIN    = 1,
    ACTION_COMBAT_END               = 2,

    EVENT_LET_VANESSA_RUN           = 1,
};

struct npc_dm_edwin_vancleef : public ScriptedAI
{
    npc_dm_edwin_vancleef(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _phase = 0;
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage) override
    {
        if (_phase == 0 && me->HealthBelowPctDamaged(75, damage))
        {
            _phase = 1;
            Talk(SAY_VANCLEEF_COMBAT_1);
            return;
        }

        if (_phase == 1 && me->HealthBelowPctDamaged(50, damage))
        {
            _phase = 2;
            Talk(SAY_VANCLEEF_COMBAT_2);
            return;
        }

        if (_phase == 2 && me->HealthBelowPctDamaged(25, damage))
        {
            _phase = 3;
            Talk(SAY_VANCLEEF_COMBAT_3);
            return;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_FIGHT:
                _events.ScheduleEvent(EVENT_DMGROUP_START_COMBAT, 8000);
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (GetAllianceWarrior())
            GetAllianceWarrior()->AI()->DoAction(ACTION_COMBAT_END);

        if (GetVanessa())
            GetVanessa()->AI()->DoAction(ACTION_VANESSA_RUNS_TO_EDWIN);
    }

    Creature* GetAllianceWarrior()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_ALLIANCE_WARRIOR));
        return nullptr;
    }

    Creature* GetVanessa()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_VANESSA_VANCLEEF));
        return nullptr;
    }

    void AttackAllianceWarrior()
    {
        if (Creature* warrior = GetAllianceWarrior())
        {
            Talk(SAY_VANCLEEF_INTRO);
            me->SetReactState(REACT_AGGRESSIVE);
            AttackStart(warrior);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_DMGROUP_START_COMBAT:
                    AttackAllianceWarrior();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    uint8 _phase;
};

enum DMAllianceWarriorData
{
    SAY_WARRIOR_INTRO           = 0,
    SAY_WARRIOR_COMBAT_START    = 1,
    SAY_VICTORY                 = 2,
    SAY_BACK_TO_SENTINEL_HILL   = 3,

    EVENT_SAY_COMBAT_START      = 10,
    EVENT_SAY_OUTRO             = 20,
};

struct npc_dm_alliance_warrior : public ScriptedAI
{
    npc_dm_alliance_warrior(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_FIGHT:
                Talk(SAY_WARRIOR_INTRO);
                _events.ScheduleEvent(EVENT_SAY_COMBAT_START, 4000);
                break;
            case ACTION_COMBAT_END:
                Talk(SAY_VICTORY);
                _events.ScheduleEvent(EVENT_SAY_OUTRO, 3000);
                break;
        }
    }

    Creature* GetEdwinVanCleef()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_EDWIN_VANCLEEF));
        return nullptr;
    }

    void AttackEdwinVanCleef()
    {
        if (Creature* edwin = GetEdwinVanCleef())
        {
            me->SetReactState(REACT_AGGRESSIVE);
            AttackStart(edwin);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_DMGROUP_START_COMBAT:
                    AttackEdwinVanCleef();
                    break;
                case EVENT_SAY_COMBAT_START:
                    _events.ScheduleEvent(EVENT_DMGROUP_START_COMBAT, 5000);
                    Talk(SAY_WARRIOR_COMBAT_START);
                    break;
                case EVENT_SAY_OUTRO:
                    Talk(SAY_BACK_TO_SENTINEL_HILL);
                    // despawn creatures
                    me->DespawnCreaturesInArea(NPC_ALLIANCE_HUNTER);
                    me->DespawnCreaturesInArea(NPC_ALLIANCE_ROGUE);
                    me->DespawnCreaturesInArea(NPC_ALLIANCE_MAGE);
                    me->DespawnCreaturesInArea(NPC_ALLIANCE_PRIEST);
                    me->DespawnCreaturesInArea(NPC_ALLIANCE_HUNTER);
                    me->DespawnCreaturesInArea(42698); // Defias Blackguard
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_dm_alliance_rogue : public ScriptedAI
{
    npc_dm_alliance_rogue(Creature* creature) : ScriptedAI(creature){ }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_FIGHT:
                _events.ScheduleEvent(EVENT_DMGROUP_START_COMBAT, 10000);
                break;
        }
    }

    Creature* GetEdwinVanCleef()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_EDWIN_VANCLEEF));
        return nullptr;
    }

    void AttackEdwinVanCleef()
    {
        if (Creature* edwin = GetEdwinVanCleef())
        {
            me->SetReactState(REACT_AGGRESSIVE);
            AttackStart(edwin);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_DMGROUP_START_COMBAT:
                    AttackEdwinVanCleef();
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

enum AllianceMageData
{
    SPELL_DM_FIREBALL       = 11921,
    SPELL_DM_FROSTBOLT      = 12675,

    EVENT_CAST_MAGE_SPELL   = 10,
};

struct npc_dm_alliance_mage : public ScriptedAI
{
    npc_dm_alliance_mage(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _inCombat = false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_FIGHT:
                _events.ScheduleEvent(EVENT_DMGROUP_START_COMBAT, 10000);
                break;
        }
    }

    Creature* GetEdwinVanCleef()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_EDWIN_VANCLEEF));
        return nullptr;
    }

    void AttackEdwinVanCleef()
    {
        if (!_inCombat)
            return;

        if (Creature* target = GetEdwinVanCleef())
        {
            if (target->isDead())
            {
                _inCombat = false;
                return;
            }

            me->SetTarget(target->GetGUID());
            DoCast(target, urand(0, 1) ? SPELL_DM_FIREBALL : SPELL_DM_FROSTBOLT);
            _events.ScheduleEvent(EVENT_CAST_MAGE_SPELL, 1000);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_DMGROUP_START_COMBAT:
                    _inCombat = true;
                    _events.ScheduleEvent(EVENT_CAST_MAGE_SPELL, 1000);
                    break;
                case EVENT_CAST_MAGE_SPELL:
                    AttackEdwinVanCleef();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _inCombat;
};

struct npc_dm_alliance_priest : public ScriptedAI
{
    npc_dm_alliance_priest(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    Creature* GetAllianceWarrior()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_ALLIANCE_WARRIOR));
        return nullptr;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        /*while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                default:
                    break;
            }
        }*/
    }

private:
    EventMap _events;
};

enum AllianceHunterData
{
    EVENT_CAST_HUNTER_SPELL = 10,
    SPELL_DM_ARCANE_SHOT    = 78754
};

struct npc_dm_alliance_hunter : public ScriptedAI
{
    npc_dm_alliance_hunter(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _inCombat = false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_FIGHT:
                _events.ScheduleEvent(EVENT_DMGROUP_START_COMBAT, 10000);
                break;
        }
    }

    Creature* GetEdwinVanCleef()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_EDWIN_VANCLEEF));
        return nullptr;
    }

    void AttackEdwinVanCleef()
    {
        if (!_inCombat)
            return;

        if (Creature* target = GetEdwinVanCleef())
        {
            if (target->isDead())
            {
                _inCombat = false;
                return;
            }

            DoCast(target, SPELL_DM_ARCANE_SHOT);
            _events.ScheduleEvent(EVENT_CAST_HUNTER_SPELL, 1000);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_DMGROUP_START_COMBAT:
                    _inCombat = true;
                    _events.ScheduleEvent(EVENT_CAST_HUNTER_SPELL, 1000);
                    break;
                case EVENT_CAST_MAGE_SPELL:
                    AttackEdwinVanCleef();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _inCombat;
};

enum VenessaVanCleefData
{
    SAY_DADDY           = 0,
    EVENT_SAY_DADDY     = 1,
    EVENT_RUN_TO_DADDY  = 2,
};

struct npc_dm_vanessa_vancleef : public ScriptedAI
{
    npc_dm_vanessa_vancleef(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    Creature* GetEdwinVanCleef()
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            return me->GetMap()->GetCreature(instance->GetGuidData(DATA_EDWIN_VANCLEEF));
        return nullptr;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_VANESSA_RUNS_TO_EDWIN:
                _events.ScheduleEvent(EVENT_RUN_TO_DADDY, 9000);
                _events.ScheduleEvent(EVENT_SAY_DADDY, 15000);
                break;
        }
    }

    void FinishEvent()
    {
        std::list<Creature*> creatures;
        GetCreatureListWithEntryInGrid(creatures, me, NPC_VISION_OF_THE_PAST, 240);
    
        for (auto vision : creatures)
            vision->AI()->DoAction(ACTION_VANCLEEF_DEAD);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 id = _events.ExecuteEvent())
        {
            switch (id)
            {
                case EVENT_SAY_DADDY:
                    Talk(SAY_DADDY);
                    FinishEvent();
                    break;
                case EVENT_RUN_TO_DADDY:
                    me->GetMotionMaster()->MoveCloserAndStop(0, GetEdwinVanCleef(), 0.7f);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

void AddSC_deadmines()
{
    new npc_mining_monkey();
    new npc_defias_cannon();
    new go_defias_cannon();
    new npc_deadmines_bird();
    new go_heavy_door();
    new npc_goblin_engineer();
    new go_deadmines_tp();
    new npc_mining_powder();

    RegisterCreatureAI(npc_vision_of_the_past);
    RegisterCreatureAI(npc_dm_alliance_warrior);
    RegisterCreatureAI(npc_dm_alliance_rogue);
    RegisterCreatureAI(npc_dm_alliance_priest);
    RegisterCreatureAI(npc_dm_alliance_hunter);
    RegisterCreatureAI(npc_dm_alliance_mage);
    RegisterCreatureAI(npc_dm_edwin_vancleef);
    RegisterCreatureAI(npc_dm_vanessa_vancleef);
}
