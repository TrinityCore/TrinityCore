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
#include "Vehicle.h"

enum eSpels
{
    // Helix
    SPELL_OAFQUARD                  = 90546,
    SPELL_HELIX_RIDE                = 88337,
    SPELL_THROW_BOMB                = 88264,

    // Oaf spell
    SPELL_OAF_GRAB_TARGETING        = 88289,
    SPELL_RIDE_OAF                  = 88278, // 88277,
    SPELL_RIDE_VEHICLE_HARDCODED    = 46598,
    OAF_CHARGE                      = 88288,
    SPELL_OAF_SMASH                 = 88300,
    SPELL_OAF_SMASH_H               = 91568,

    // BOMB
    SPELL_STICKY_BOMB_EXPLODE       = 95500, //88329, // 95500 -> 88321, 88974
    SPELL_STICKY_BOMB_EXPLODE_H     = 91566,
    SPELL_ARMING_VISUAL_YELLOW      = 88315,
    SPELL_ARMING_VISUAL_ORANGE      = 88316,
    SPELL_ARMING_VISUAL_RED         = 88317,
    SPELL_BOMB_ARMED_STATE          = 88319,
    SPELL_CHEST_BOMB                = 88352, // Unused
};


const Position OafPos[2] =
{
    {-289.809f, -527.215f, 49.8021f, 0},
    {-289.587f, -489.575f, 49.9126f, 0},
};

const Position CrewSpawn[] =
{
    {-281.68f, -504.10f, 60.51f, 4.75f},
    {-284.71f, -504.13f, 60.42f, 4.72f},
    {-288.65f, -503.74f, 60.38f, 4.64f},
    {-293.88f, -503.90f, 60.07f, 4.77f},
};

enum HelOaf_Events
{
    // Helix Events
    EVENT_CHEST_BOMB         = 1,
    EVENT_THROW_BOMB         = 2,
    EVENT_NO_OAF             = 3,
    EVENT_ACHIEVEVEMENT_BUFF = 4,

    // Oaf Events
    EVENT_OAFQUARD           = 5,
    EVENT_MOVE_TO_POINT      = 6,
    EVENT_MOUNT_PLAYER       = 7,
    EVEMT_CHARGE             = 8,
    EVENT_FINISH             = 9,
};

#define CHEST_BOMB "Helix attaches a bomb to $N's chest."

class boss_helix_gearbreaker : public CreatureScript
{
public:
    boss_helix_gearbreaker() : CreatureScript("boss_helix_gearbreaker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_helix_gearbreakerAI(creature);
    }

    struct boss_helix_gearbreakerAI : public BossAI
    {
        boss_helix_gearbreakerAI(Creature* pCreature) : BossAI(pCreature, DATA_HELIX), summons(me)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList summons;

        uint32 Phase;
        uint32 uiTimer;
        uint32 numberKillMineRat;
        Creature* oaf;

        void Reset() override
        {
            _Reset();
            Phase = 1;
            uiTimer = 2000;
            numberKillMineRat = 0;

            if (!me)
                return;

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            summons.DespawnAll();
            OafSupport();
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            if (!me)
                return;

            _EnterCombat();
            Talk(5);
            me->SetInCombatWithZone();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_THROW_BOMB, 3000);

            if (IsHeroic())
            {
                SummonCrew();
                events.ScheduleEvent(EVENT_ACHIEVEVEMENT_BUFF, 0);
            }
        }

        void OafSupport()
        {
            oaf = me->GetVehicleCreatureBase();
            if (!oaf)
            {
                oaf = me->FindNearestCreature(NPC_OAF, 30.0f);
                if (oaf && oaf->IsAlive())
                {
                    me->CastSpell(oaf, SPELL_RIDE_VEHICLE_HARDCODED);
                } else
                {
                    oaf = me->SummonCreature(NPC_OAF, me->GetHomePosition());

                    if (oaf && oaf->IsAlive())
                    {
                        me->CastSpell(oaf, SPELL_RIDE_VEHICLE_HARDCODED);
                    }
                }
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void SummonCrew()
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                me->SummonCreature(NPC_HELIX_CREW, CrewSpawn[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!me)
                return;

            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(0);
            summons.DespawnAll();
        }

        void JustReachedHome() override
        {
            if (!me)
                return;

            _JustReachedHome();
            Talk(1);
            instance->SetBossState(DATA_HELIX, FAIL);
        }

        void OafDead()
        {
            events.ScheduleEvent(EVENT_NO_OAF, 100);
            events.ScheduleEvent(EVENT_THROW_BOMB, 3000);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CHEST_BOMB, 5000);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (!me)
                return;

            DoMeleeAttackIfReady();

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_THROW_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                            me->CastSpell(target, SPELL_THROW_BOMB, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
                        events.ScheduleEvent(EVENT_THROW_BOMB, 3000);
                        break;
                    case EVENT_CHEST_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                        {
                            me->TextEmote(CHEST_BOMB, target, true);
                            me->AddAura(SPELL_CHEST_BOMB, target);
                        }
                        events.ScheduleEvent(EVENT_CHEST_BOMB, 11000);
                        break;
                    case EVENT_NO_OAF:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAura(SPELL_OAFQUARD);
                        Talk(2);
                        events.RescheduleEvent(EVENT_THROW_BOMB, 3000);
                        break;
                    case EVENT_ACHIEVEVEMENT_BUFF:
                        std::list<Player*> players;
                        me->GetPlayerListInGrid(players, 150.0f);

                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            me->CastSpell(( *itr ), SPELL_HELIX_RIDE, true);

                        events.ScheduleEvent(EVENT_ACHIEVEVEMENT_BUFF, 60000);
                        break;
                }
            }
        }
    };
};

class npc_lumbering_oaf : public CreatureScript
{
public:
    npc_lumbering_oaf() : CreatureScript("npc_lumbering_oaf") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lumbering_oafAI(creature);
    }

    struct npc_lumbering_oafAI : public ScriptedAI
    {
        npc_lumbering_oafAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            _vehicle = me->GetVehicleKit();
        }

        Vehicle* _vehicle;
        Creature* bunny;

        void Reset() override
        {
            if (!_vehicle)
                return;

            events.Reset();
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            events.ScheduleEvent(EVENT_OAFQUARD, 5000);
        }

        void JustDied(Unit* /*who*/) override
        {
            if (Creature* Helix = me->FindNearestCreature(NPC_HELIX_GEARBREAKER, 200, true))
                if (boss_helix_gearbreaker::boss_helix_gearbreakerAI* pAI = CAST_AI(boss_helix_gearbreaker::boss_helix_gearbreakerAI, Helix->AI()))
                    pAI->OafDead();
        }

        void SummonBunny()
        {
            Talk(0);
            Talk(1);
            bunny = me->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, OafPos[1].GetPositionX(), OafPos[1].GetPositionY(), OafPos[1].GetPositionZ());
            me->SetInCombatWithZone();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (bunny)
                {
                    me->SetInCombatWithZone();
                    if (Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
                    {
                        passenger->ExitVehicle();
                        me->Attack(passenger, true);
                    }

                    bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 100.0f);
                    if (bunny != nullptr)
                    {
                        me->CastSpell(me, IsHeroic() ? SPELL_OAF_SMASH_H : SPELL_OAF_SMASH);

                        me->SummonCreature(NPC_MINE_RAT, -303.193481f, -486.287140f, 49.185917f, 2.152038f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -300.496674f, -490.433746f, 49.073387f, 5.243889f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -298.689301f, -486.994995f, 48.893055f, 0.950859f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -301.923676f, -486.674591f, 49.081684f, 2.677864f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -296.066345f, -488.150177f, 48.917435f, 2.657793f, TEMPSUMMON_TIMED_DESPAWN, 360000);

                        bunny->Kill(bunny, false);
                        me->SetSpeed(MOVE_RUN, 1.0f);
                    }
                }

                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoStartMovement(target);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (!_vehicle)
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OAFQUARD:
                        SummonBunny();
                        events.ScheduleEvent(EVENT_MOUNT_PLAYER, 500);
                        break;

                    case EVENT_MOUNT_PLAYER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                            target->CastSpell(me, SPELL_RIDE_VEHICLE_HARDCODED);
                        events.ScheduleEvent(EVENT_MOVE_TO_POINT, 500);
                        break;

                    case EVENT_MOVE_TO_POINT:
                        me->SetSpeed(MOVE_RUN, 5.0f);
                        me->GetMotionMaster()->MovePoint(0, -289.809f, -527.215f, 49.8021f);
                        events.ScheduleEvent(EVEMT_CHARGE, 2000);
                        break;

                    case EVEMT_CHARGE:
                        if (me->GetDistance(OafPos[0]) <= 2.0f)
                        {
                            me->GetMotionMaster()->Clear(true);
                            bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 150.0f);
                            if (bunny != nullptr)
                            {
                                me->GetMotionMaster()->MovePoint(1, bunny->GetPositionX(), bunny->GetPositionY(), bunny->GetPositionZ());
                                bunny->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            }
                        }
                        events.ScheduleEvent(EVENT_FINISH, 1500);
                        break;

                    case EVENT_FINISH:
                        events.ScheduleEvent(EVENT_OAFQUARD, 17000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

struct npc_sticky_bomb : public ScriptedAI
{
    npc_sticky_bomb(Creature* pCreature) : ScriptedAI(pCreature) { }

    uint32 Phase;
    uint32 uiTimer;

    void Reset() override
    {
        Phase   = 1;
        uiTimer = 500;

        DoCast(me, SPELL_CHEST_BOMB);
    }

    void UpdateAI(uint32 uiDiff) override
    {
        if (uiTimer < uiDiff)
        {
            switch (Phase++)
            {
                case 1:
                    DoCast(me, SPELL_ARMING_VISUAL_YELLOW);
                    uiTimer = 700;
                    break;
                case 2:
                    DoCast(me, SPELL_ARMING_VISUAL_ORANGE);
                    uiTimer = 600;
                    break;
                case 3:
                    DoCast(me, SPELL_ARMING_VISUAL_RED);
                    uiTimer = 500;
                    break;
                case 4:
                    DoCast(me, SPELL_BOMB_ARMED_STATE);
                    uiTimer = 400;
                    break;
                case 5:
                    DoCast(me, IsHeroic() ? SPELL_STICKY_BOMB_EXPLODE_H : SPELL_STICKY_BOMB_EXPLODE);
                    uiTimer = 300;
                    break;
                case 6:
                    me->DespawnOrUnsummon();
                    break;
            }
        }
        else
            uiTimer -= uiDiff;
    }
};

struct npc_helix_crew : public Scripted_NoMovementAI
{
    npc_helix_crew(Creature* pCreature) : Scripted_NoMovementAI(pCreature) { }

    void Reset() override
    {
        DoCast(me, 18373);

        if (Player* victim = me->SelectNearestPlayer(80.0f))
            me->Attack(victim, false);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->GetScheduler().Schedule(5s, [this](TaskContext context)
        {
            if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                DoCast(player, SPELL_THROW_BOMB);

            context.Repeat();
        });
    }
};

void AddSC_boss_helix_gearbreaker()
{
    new npc_lumbering_oaf();
    new boss_helix_gearbreaker();
    RegisterCreatureAI(npc_sticky_bomb);
    RegisterCreatureAI(npc_helix_crew);
}
