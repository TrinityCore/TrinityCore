/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "naxxramas.h"

enum Horsemen
{
    HORSEMEN_THANE,
    HORSEMEN_LADY,
    HORSEMEN_BARON,
    HORSEMEN_SIR,
};

enum Spells
{
    SPELL_MARK_DAMAGE   = 28836
};

enum Events
{
    EVENT_NONE,
    EVENT_MARK,
    EVENT_CAST,
    EVENT_BERSERK,
};

const Position WaypointPositions[12] =
{
    // Thane waypoints
    {2542.3f, -2984.1f, 241.49f, 5.362f},
    {2547.6f, -2999.4f, 241.34f, 5.049f},
    {2542.9f, -3015.0f, 241.35f, 4.654f},
    // Lady waypoints
    {2498.3f, -2961.8f, 241.28f, 3.267f},
    {2487.7f, -2959.2f, 241.28f, 2.890f},
    {2469.4f, -2947.6f, 241.28f, 2.576f},
    // Baron waypoints
    {2553.8f, -2968.4f, 241.33f, 5.757f},
    {2564.3f, -2972.5f, 241.33f, 5.890f},
    {2583.9f, -2971.67f, 241.35f, 0.008f},
    // Sir waypoints
    {2534.5f, -2921.7f, 241.53f, 1.363f},
    {2523.5f, -2902.8f, 241.28f, 2.095f},
    {2517.8f, -2896.6f, 241.28f, 2.315f},
};

const uint32 NPC_HORSEMEN[]     =   {16064, 16065, 30549, 16063};
const uint32 SPELL_MARK[]       =   {28832, 28833, 28834, 28835};
#define SPELL_PRIMARY(i)            RAID_MODE(SPELL_PRIMARY_N[i], SPELL_PRIMARY_H[i])
const uint32 SPELL_PRIMARY_N[]  =   {28884, 28863, 28882, 28883};
const uint32 SPELL_PRIMARY_H[]  =   {57467, 57463, 57369, 57466};
#define SPELL_SECONDARY(i)          RAID_MODE(SPELL_SECONDARY_N[i], SPELL_SECONDARY_H[i])
const uint32 SPELL_SECONDARY_N[]=   {0, 57374, 0, 57376};
const uint32 SPELL_SECONDARY_H[]=   {0, 57464, 0, 57465};
const uint32 SPELL_PUNISH[]     =   {0, 57381, 0, 57377};
#define SPELL_BERSERK               26662

enum FourHorsemen
{
    SAY_AGGRO       = 0,
    SAY_TAUNT       = 1,
    SAY_SPECIAL     = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4
};

class boss_four_horsemen : public CreatureScript
{
public:
    boss_four_horsemen() : CreatureScript("boss_four_horsemen") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_four_horsemenAI(creature);
    }

    struct boss_four_horsemenAI : public BossAI
    {
        boss_four_horsemenAI(Creature* creature) : BossAI(creature, BOSS_HORSEMEN)
        {
            id = Horsemen(0);
            for (uint8 i = 0; i < 4; ++i)
                if (me->GetEntry() == NPC_HORSEMEN[i])
                    id = Horsemen(i);
            caster = (id == HORSEMEN_LADY || id == HORSEMEN_SIR);
            encounterActionReset = false;
        }

        Horsemen id;
        uint64 uiEventStarterGUID;
        uint8 nextWP;
        uint32 punishTimer;
        bool caster;
        bool nextMovementStarted;
        bool movementCompleted;
        bool movementStarted;
        bool encounterActionAttack;
        bool encounterActionReset;
        bool doDelayPunish;

        void Reset() OVERRIDE
        {
            if (!encounterActionReset)
                DoEncounteraction(NULL, false, true, false);

            if (instance)
                instance->SetData(DATA_HORSEMEN0 + id, NOT_STARTED);

            me->SetReactState(REACT_AGGRESSIVE);
            uiEventStarterGUID = 0;
            nextWP = 0;
            punishTimer = 2000;
            nextMovementStarted = false;
            movementCompleted = false;
            movementStarted = false;
            encounterActionAttack = false;
            encounterActionReset = false;
            doDelayPunish = false;
            _Reset();
        }

        bool DoEncounteraction(Unit* who, bool attack, bool reset, bool checkAllDead)
        {
            if (!instance)
                return false;

            Creature* Thane = Unit::GetCreature(*me, instance->GetData64(DATA_THANE));
            Creature* Lady = Unit::GetCreature(*me, instance->GetData64(DATA_LADY));
            Creature* Baron = Unit::GetCreature(*me, instance->GetData64(DATA_BARON));
            Creature* Sir = Unit::GetCreature(*me, instance->GetData64(DATA_SIR));

            if (Thane && Lady && Baron && Sir)
            {
                if (attack && who)
                {
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Thane->AI())->encounterActionAttack = true;
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Lady->AI())->encounterActionAttack = true;
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Baron->AI())->encounterActionAttack = true;
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Sir->AI())->encounterActionAttack = true;

                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Thane->AI())->AttackStart(who);
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Lady->AI())->AttackStart(who);
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Baron->AI())->AttackStart(who);
                    CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Sir->AI())->AttackStart(who);
                }

                if (reset)
                {
                    if (instance->GetBossState(BOSS_HORSEMEN) != NOT_STARTED)
                    {
                        if (!Thane->IsAlive())
                            Thane->Respawn();

                        if (!Lady->IsAlive())
                            Lady->Respawn();

                        if (!Baron->IsAlive())
                            Baron->Respawn();

                        if (!Sir->IsAlive())
                            Sir->Respawn();

                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Thane->AI())->encounterActionReset = true;
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Lady->AI())->encounterActionReset = true;
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Baron->AI())->encounterActionReset = true;
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Sir->AI())->encounterActionReset = true;

                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Thane->AI())->EnterEvadeMode();
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Lady->AI())->EnterEvadeMode();
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Baron->AI())->EnterEvadeMode();
                        CAST_AI(boss_four_horsemen::boss_four_horsemenAI, Sir->AI())->EnterEvadeMode();
                    }
                }

                if (checkAllDead)
                    return !Thane->IsAlive() && !Lady->IsAlive() && !Baron->IsAlive() && !Sir->IsAlive();
            }
            return false;
        }

        void BeginFourHorsemenMovement()
        {
            movementStarted = true;
            me->SetReactState(REACT_PASSIVE);
            me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN), true);

            switch (id)
            {
                case HORSEMEN_THANE:
                    me->GetMotionMaster()->MovePoint(0, WaypointPositions[0]);
                    break;
                case HORSEMEN_LADY:
                    me->GetMotionMaster()->MovePoint(3, WaypointPositions[3]);
                    break;
                case HORSEMEN_BARON:
                    me->GetMotionMaster()->MovePoint(6, WaypointPositions[6]);
                    break;
                case HORSEMEN_SIR:
                    me->GetMotionMaster()->MovePoint(9, WaypointPositions[9]);
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 2 || id == 5 || id == 8 || id == 11)
            {
                movementCompleted = true;
                me->SetReactState(REACT_AGGRESSIVE);

                Unit* eventStarter = Unit::GetUnit(*me, uiEventStarterGUID);

                if (eventStarter && me->IsValidAttackTarget(eventStarter))
                    AttackStart(eventStarter);
                else if (!UpdateVictim())
                {
                    EnterEvadeMode();
                    return;
                }

                if (caster)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                }

                return;
            }

            nextMovementStarted = false;
            nextWP = id + 1;
        }

        // switch to "who" if nearer than current target.
        void SelectNearestTarget(Unit* who)
        {
            if (me->GetVictim() && me->GetDistanceOrder(who, me->GetVictim()) && me->IsValidAttackTarget(who))
            {
                me->getThreatManager().modifyThreatPercent(me->GetVictim(), -100);
                me->AddThreat(who, 1000000.0f);
            }
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            BossAI::MoveInLineOfSight(who);
            if (caster)
                SelectNearestTarget(who);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!movementCompleted && !movementStarted)
            {
                uiEventStarterGUID = who->GetGUID();
                BeginFourHorsemenMovement();

                if (!encounterActionAttack)
                    DoEncounteraction(who, true, false, false);
            }
            else if (movementCompleted && movementStarted)
            {
                if (caster)
                    me->Attack(who, false);
                else
                    BossAI::AttackStart(who);
            }
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            if (!(rand()%5))
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            events.Reset();
            summons.DespawnAll();

            if (instance)
                instance->SetData(DATA_HORSEMEN0 + id, DONE);

            if (instance && DoEncounteraction(NULL, false, false, true))
            {
                instance->SetBossState(BOSS_HORSEMEN, DONE);
                instance->SaveToDB();

                // Achievements related to the 4-horsemen are given through spell 59450 which does not exist.
                // There is thus no way it can be given by casting the spell on the players.
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 59450);
            }

            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_MARK, 15000);
            events.ScheduleEvent(EVENT_CAST, 20000+rand()%5000);
            events.ScheduleEvent(EVENT_BERSERK, 15*100*1000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (nextWP && movementStarted && !movementCompleted && !nextMovementStarted)
            {
                nextMovementStarted = true;
                me->GetMotionMaster()->MovePoint(nextWP, WaypointPositions[nextWP]);
            }

            if (!UpdateVictim() || !CheckInRoom() || !movementCompleted)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MARK:
                        if (!(rand()%5))
                            Talk(SAY_SPECIAL);
                        DoCastAOE(SPELL_MARK[id]);
                        events.ScheduleEvent(EVENT_MARK, 15000);
                        break;
                    case EVENT_CAST:
                        if (!(rand()%5))
                            Talk(SAY_TAUNT);

                        if (caster)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f))
                                DoCast(target, SPELL_PRIMARY(id));
                        }
                        else
                            DoCastVictim(SPELL_PRIMARY(id));

                        events.ScheduleEvent(EVENT_CAST, 15000);
                        break;
                    case EVENT_BERSERK:
                        Talk(SAY_SPECIAL);
                        DoCast(me, EVENT_BERSERK);
                        break;
                }
            }

            if (punishTimer <= diff)
            {
                if (doDelayPunish)
                {
                    DoCastAOE(SPELL_PUNISH[id], true);
                    doDelayPunish = false;
                }
                punishTimer = 2000;
            } else punishTimer -= diff;

            if (!caster)
                DoMeleeAttackIfReady();
            else if ((!DoSpellAttackIfReady(SPELL_SECONDARY(id)) || !me->IsWithinLOSInMap(me->GetVictim())) && movementCompleted && !doDelayPunish)
                doDelayPunish = true;
        }
    };

};

class spell_four_horsemen_mark : public SpellScriptLoader
{
    public:
        spell_four_horsemen_mark() : SpellScriptLoader("spell_four_horsemen_mark") { }

        class spell_four_horsemen_mark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_four_horsemen_mark_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 damage;
                    switch (GetStackAmount())
                    {
                        case 1:
                            damage = 0;
                            break;
                        case 2:
                            damage = 500;
                            break;
                        case 3:
                            damage = 1000;
                            break;
                        case 4:
                            damage = 1500;
                            break;
                        case 5:
                            damage = 4000;
                            break;
                        case 6:
                            damage = 12000;
                            break;
                        default:
                            damage = 20000 + 1000 * (GetStackAmount() - 7);
                            break;
                    }
                    if (damage)
                        caster->CastCustomSpell(SPELL_MARK_DAMAGE, SPELLVALUE_BASE_POINT0, damage, GetTarget());
                }
            }

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_four_horsemen_mark_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_four_horsemen_mark_AuraScript();
        }
};

void AddSC_boss_four_horsemen()
{
    new boss_four_horsemen();
    new spell_four_horsemen_mark();
}
