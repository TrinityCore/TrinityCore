/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
SDName: boss_murozond
SD%Complete:
SDComment:
EndScriptData */

#include "end_time.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellHistory.h"

enum Spells
{
    SPELL_TEMPORAL_BLAST                = 102381,
    SPELL_INFINITE_BREATH               = 102569,
    SPELL_DISTORTION_BOMB               = 101983,
    SPELL_HOURGLASS_BAR                 = 102668,
    SPELL_REWIND_TIME                   = 101591,
    SPELL_TAIL_SWEEP                    = 108589,
    SPELL_FADING                        = 107550,
    SPELL_BUFF_BLESSING_OF_BRONZE       = 102364,
};

enum Events
{
    EVENT_TEMPORAL_BLAST                = 1,
    EVENT_INFINITE_BREATH,
    EVENT_DISTORTION_BOMB,
    EVENT_TAIL_SWEEP,
};

enum MovementPoints
{
    POINT_MUROZOND_FLY_IN   = 1,
    POINT_MUROZOND_LAND     = 2,
};

enum Misc
{
    NPC_MUROZOND_ENTRY                  = 54432,
    NPC_PLAYER_CLONE_ENTRY              = 46956,
};

Position const MurozondFlyPos       = {4156.6801f, -430.114f, 139.9719f, 2.981764f};
Position const MurozondLandPos      = {4156.6801f, -430.114f, 119.9719f, 2.981764f};

class MurozondLandEvent : public BasicEvent
{
    public:
        MurozondLandEvent(Creature& owner, Position const& dest) : _owner(owner), _dest(dest) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/) override
        {
            _owner.GetMotionMaster()->MoveLand(POINT_MUROZOND_LAND, _dest);
            return true;
        }

    private:
        Creature& _owner;
        Position const& _dest;
};

class MurozondStartAttack : public BasicEvent
{
    public:
        MurozondStartAttack(Creature& owner) : _owner(owner) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/) override
        {
            _owner.SetReactState(REACT_AGGRESSIVE);
            return true;
        }

    private:
        Creature& _owner;
};

class boss_murozond : public CreatureScript
{
    public:
        boss_murozond() : CreatureScript("boss_murozond") { }

        struct boss_murozondAI : public BossAI
        {
            boss_murozondAI(Creature* creature) : BossAI(creature, DATA_MUROZOND), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;

            GameObject* Rewardchest;

            void Reset() override
            {
                instance->SetData(DATA_MUROZOND_STARTED, false);
                if (!instance->GetData(DATA_MUROZOND_TRASH))
                {
                    me->GetMotionMaster()->Clear();
                    me->SetHomePosition(MurozondLandPos);
                    me->GetMotionMaster()->MoveTargetedHome();
                }

                DoAction(ACTION_MUROZOND_REMOVE_HOURGLASS_BAR);

                _Reset();
                events.Reset();

                Summons.DespawnAll();
            }

            void InitializeAI() override
            {
                instance->SetData(DATA_MUROZOND_STARTED, false);
                if (!instance->GetData(DATA_MUROZOND_TRASH))
                {
                    me->GetMotionMaster()->Clear();
                    DoAction(ACTION_MUROZOND_START);
                }

                Rewardchest = GetClosestGameObjectWithEntry(me, 209547, 500.0f);
                if (Rewardchest != nullptr)
                    PhasingHandler::AddPhase(Rewardchest, 50);
            }

            void JustReachedHome() override
            {
                DoAction(ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                DoAction(ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB);
                me->setActive(false);
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetHomePosition(MurozondLandPos);
                me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);

                instance->SetData(DATA_MUROZOND_STARTED, true);

                events.ScheduleEvent(EVENT_INFINITE_BREATH, 22000);
                events.ScheduleEvent(EVENT_TEMPORAL_BLAST, 12000);
                events.ScheduleEvent(EVENT_DISTORTION_BOMB, 5000);
                events.ScheduleEvent(EVENT_TAIL_SWEEP, 10000);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoZoneInCombat();

                if (Map* map = me->GetMap())
                {
                    std::list<Player*> PlayerList;
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            Position pos = player->GetPosition();
                            Creature* clone = player->SummonCreature(46956, pos);
                            player->CastSpell(clone, 45204, true);
                            player->CastSpell(clone, 41054, true);
                            player->CastSpell(clone, 45205, true);
                            clone->AddAura(37800, clone);
                            player->AddAura(SPELL_HOURGLASS_BAR, player);
                            player->CastSpell(player, SPELL_BUFF_BLESSING_OF_BRONZE, true);
                            player->SetMaxPower(POWER_ALTERNATE_POWER, 50);
                            player->SetPower(POWER_ALTERNATE_POWER, 50);
                            Summons.Summon(clone);
                        }
                    }
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Summons.DespawnAll();

                me->AddAura(SPELL_FADING, me);
                DoAction(ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB);
                DoAction(ACTION_MUROZOND_REMOVE_HOURGLASS_BAR);

            if (me->GetMap()->IsHeroic())
            {// this will give the achievement to players in heroic difficulty
                Map::PlayerList const& PlayerList = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        player->CompletedAchievement(6117);
                    }
                }
            }

                if (Rewardchest)
                    PhasingHandler::ResetPhaseShift(Rewardchest);
            }

            void JustSummoned(Creature* summon) override
            {
                Summons.Summon(summon);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                case ACTION_MUROZOND_START:
                {
                    if (me->isDead())
                        return;

                    me->setActive(true);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetSpeed(MOVE_FLIGHT, 1.0f);
                    me->SetSpeed(MOVE_RUN, 1.0f);
                    me->SetSpeed(MOVE_WALK, 1.0f);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);
                    float moveTime = me->GetExactDist(&MurozondFlyPos) / (me->GetSpeed(MOVE_FLIGHT) * 0.001f);
                    me->m_Events.AddEvent(new MurozondLandEvent(*me, MurozondLandPos), me->m_Events.CalculateTime(uint64(moveTime) + 250));
                    me->m_Events.AddEvent(new MurozondStartAttack(*me), me->m_Events.CalculateTime(uint64(moveTime) + 5250));
                    me->GetMotionMaster()->MovePoint(POINT_MUROZOND_FLY_IN, MurozondFlyPos);
                    break;
                }
                case ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB:
                    me->RemoveAllDynObjects();
                    break;
                case ACTION_MUROZOND_REMOVE_HOURGLASS_BAR:
                    if (Map* map = me->GetMap())
                    {
                        std::list<Player*> PlayerList;
                        Map::PlayerList const& Players = map->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                            player->RemoveAura(SPELL_HOURGLASS_BAR);
                        }
                    }
                default:
                    break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_TEMPORAL_BLAST:
                        DoCast(me, SPELL_TEMPORAL_BLAST);
                        events.ScheduleEvent(EVENT_TEMPORAL_BLAST, 12000);
                        break;
                    case EVENT_INFINITE_BREATH:
                        DoCastAOE(SPELL_INFINITE_BREATH);
                        events.ScheduleEvent(EVENT_INFINITE_BREATH, 22000);
                        break;
                    case EVENT_DISTORTION_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            Position targetPos = target->GetPosition();
                            float bombTimer = me->GetExactDist(&targetPos) / 4.0f;
                            DoCast(target, SPELL_DISTORTION_BOMB, true);
                            events.ScheduleEvent(EVENT_DISTORTION_BOMB, uint32(bombTimer * 1000));
                        }
                        break;
                    case EVENT_TAIL_SWEEP:
                        DoCastAOE(SPELL_TAIL_SWEEP);
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, 10000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_murozondAI(creature);
        }
};

class npc_murozond_trash : public CreatureScript
{
    public:
        npc_murozond_trash() : CreatureScript("npc_murozond_trash") { }

        struct npc_murozond_trashAI : public ScriptedAI
        {
            npc_murozond_trashAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void InitializeAI() override
            {
                // Increase add count
                if (!me->isDead())
                {
                    if (me->GetEntry() == NPC_INFINITE_WARDEN || me->GetEntry() == NPC_INFINITE_SUPPRESSOR)
                    {
                        if (WorldObject* hourglass = GetClosestGameObjectWithEntry(me, 209249, 300.0f))
                        {
                            if (me->IsWithinDist(hourglass, 32.0f))
                                _instance->SetData(DATA_MUROZOND_TRASH, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
                        }
                        Reset();
                    }
                }
            }

            private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetEndTimelAI<npc_murozond_trashAI>(creature);
        }
};

class go_hourglass_of_time : public GameObjectScript
{
public:
    go_hourglass_of_time() : GameObjectScript("go_hourglass_of_time") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGO) override
    {
        InstanceScript* _instance = pGO->GetInstanceScript();

        if (pPlayer->GetPower(POWER_ALTERNATE_POWER) < 1 || _instance->GetData(DATA_MUROZOND_TRASH) || !pPlayer->IsInCombat() || !_instance->GetData(DATA_MUROZOND_STARTED))
            return true;
        else
        {
            if (Creature* murozond = pGO->FindNearestCreature(NPC_MUROZOND_ENTRY, 200.0f))
                murozond->AI()->DoAction(ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB);
            if (Map* map = pPlayer->GetMap())
            {
                std::list<Player*> PlayerList;
                Map::PlayerList const& Players = map->GetPlayers();
                for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        if (player->isDead())
                            player->ResurrectPlayer(100.0f, false);

                        player->CastSpell(player, SPELL_BUFF_BLESSING_OF_BRONZE, true);

                        int32 charges = player->GetPower(POWER_ALTERNATE_POWER);
                        charges -= 10;

                        if (player->HasAura(SPELL_HOURGLASS_BAR))
                        {
                            player->RemoveAura(SPELL_HOURGLASS_BAR);
                            player->AddAura(SPELL_HOURGLASS_BAR, player);
                        }

                        player->SetMaxPower(POWER_ALTERNATE_POWER, 50);
                        player->SetPower(POWER_ALTERNATE_POWER, charges);

                        std::list<Creature*> playerClones;
                        player->GetCreatureListWithEntryInGrid(playerClones, NPC_PLAYER_CLONE_ENTRY, 200.0f);

                        Creature* myClone;
                        for (std::list<Creature*>::iterator iter = playerClones.begin(); iter != playerClones.end(); ++iter)
                        {
                            if (!(*iter) || (*iter)->isDead())
                                continue;

                            if (Aura* aur = (*iter)->GetAura(45204))
                            {
                                if (aur->GetCasterGUID() == player->GetGUID())
                                    myClone = (*iter);
                                else
                                    continue;
                            }
                        }

                        if (myClone)
                        {
                            float cloneDist = player->GetDistance2d(myClone);
                            player->AddAura(SPELL_REWIND_TIME, player);
                            player->GetMotionMaster()->MoveCharge(myClone->GetPositionX(), myClone->GetPositionY(), myClone->GetPositionZ(), cloneDist / 3.0f);
                            player->GetSpellHistory()->ResetAllCooldowns();
                            player->RemoveAura(57723);      // Heroism
                            player->RemoveAura(57724);      // Bloodlust
                            player->RemoveAura(80354);      // Time Warp
                            player->RemoveAura(102381);     // Temporal Blast
                            player->ToPlayer()->SetFullHealth();
                            player->ToPlayer()->SetFullPower(player->GetPowerType());
                        }
                    }
                }
            }
        }
        return true;
    }
};

void AddSC_boss_murozond()
{
    new boss_murozond();
    new npc_murozond_trash();
    new go_hourglass_of_time();
}
