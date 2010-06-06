/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptedPch.h"
#include "naxxramas.h"

enum Horsemen
{
    HORSEMEN_THANE,
    HORSEMEN_LADY,
    HORSEMEN_BARON,
    HORSEMEN_SIR,
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
    {2542.3, -2984.1, 241.49, 5.362},
    {2547.6, -2999.4, 241.34, 5.049},
    {2542.9, -3015.0, 241.35, 4.654},
    // Lady waypoints
    {2498.3, -2961.8, 241.28, 3.267},
    {2487.7, -2959.2, 241.28, 2.890},
    {2469.4, -2947.6, 241.28, 2.576},
    // Baron waypoints
    {2553.8, -2968.4, 241.33, 5.757},
    {2564.3, -2972.5, 241.33, 5.890},
    {2583.9, -2971.67, 241.35, 0.008},
    // Sir waypoints
    {2534.5, -2921.7, 241.53, 1.363},
    {2523.5, -2902.8, 241.28, 2.095},
    {2517.8, -2896.6, 241.28, 2.315},
};

const uint32 MOB_HORSEMEN[]     =   {16064, 16065, 30549, 16063};
const uint32 SPELL_MARK[]       =   {28832, 28833, 28834, 28835};
#define SPELL_PRIMARY(i)            RAID_MODE(SPELL_PRIMARY_N[i],SPELL_PRIMARY_H[i])
const uint32 SPELL_PRIMARY_N[]  =   {28884, 28863, 28882, 28883};
const uint32 SPELL_PRIMARY_H[]  =   {57467, 57463, 57369, 57466};
#define SPELL_SECONDARY(i)          RAID_MODE(SPELL_SECONDARY_N[i],SPELL_SECONDARY_H[i])
const uint32 SPELL_SECONDARY_N[]=   {0, 57374, 0, 57376};
const uint32 SPELL_SECONDARY_H[]=   {0, 57464, 0, 57465};
const uint32 SPELL_PUNISH[]     =   {0, 57381, 0, 57377};
#define SPELL_BERSERK               26662

// used by 16063,16064,16065,30549, but signed for 16063
const int32 SAY_AGGRO[]     =   {-1533051, -1533044, -1533065, -1533058};
const int32 SAY_TAUNT[3][4] ={  {-1533052, -1533045, -1533071, -1533059},
                                {-1533053, -1533046, -1533072, -1533060},
                                {-1533054, -1533047, -1533073, -1533061},};
const int32 SAY_SPECIAL[]   =   {-1533055, -1533048, -1533070, -1533062};
const int32 SAY_SLAY[]      =   {-1533056, -1533049, -1533068, -1533063};
const int32 SAY_DEATH[]     =   {-1533057, -1533050, -1533074, -1533064};

#define SAY_BARON_AGGRO     RAND(-1533065,-1533066,-1533067)
#define SAY_BARON_SLAY      RAND(-1533068,-1533069)

struct boss_four_horsemenAI : public BossAI
{
    boss_four_horsemenAI(Creature *c) : BossAI(c, BOSS_HORSEMEN)
    {
        id = Horsemen(0);
        for (uint8 i = 0; i < 4; ++i)
            if (me->GetEntry() == MOB_HORSEMEN[i])
                id = Horsemen(i);
        caster = (id == HORSEMEN_LADY || id == HORSEMEN_SIR);
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

    void Reset()
    {
        if (!encounterActionReset)
            DoEncounterAction(NULL, false, true, false);

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

    bool DoEncounterAction(Unit *who, bool attack, bool reset, bool checkAllDead)
    {
        if (!instance)
            return false;

        Creature *Thane = CAST_CRE(Unit::GetUnit(*me, instance->GetData64(DATA_THANE)));
        Creature *Lady = CAST_CRE(Unit::GetUnit(*me, instance->GetData64(DATA_LADY)));
        Creature *Baron = CAST_CRE(Unit::GetUnit(*me, instance->GetData64(DATA_BARON)));
        Creature *Sir = CAST_CRE(Unit::GetUnit(*me, instance->GetData64(DATA_SIR)));

        if (Thane && Lady && Baron && Sir)
        {
            if (attack && who)
            {
                CAST_AI(boss_four_horsemenAI, Thane->AI())->encounterActionAttack = true;
                CAST_AI(boss_four_horsemenAI, Lady->AI())->encounterActionAttack = true;
                CAST_AI(boss_four_horsemenAI, Baron->AI())->encounterActionAttack = true;
                CAST_AI(boss_four_horsemenAI, Sir->AI())->encounterActionAttack = true;

                CAST_AI(boss_four_horsemenAI, Thane->AI())->AttackStart(who);
                CAST_AI(boss_four_horsemenAI, Lady->AI())->AttackStart(who);
                CAST_AI(boss_four_horsemenAI, Baron->AI())->AttackStart(who);
                CAST_AI(boss_four_horsemenAI, Sir->AI())->AttackStart(who);
            }

            if (reset)
            {
                if (instance->GetBossState(BOSS_HORSEMEN) != NOT_STARTED)
                {
                    if (!Thane->isAlive())
                        Thane->Respawn();

                    if (!Lady->isAlive())
                        Lady->Respawn();

                    if (!Baron->isAlive())
                        Baron->Respawn();

                    if (!Sir->isAlive())
                        Sir->Respawn();

                    CAST_AI(boss_four_horsemenAI, Thane->AI())->encounterActionReset = true;
                    CAST_AI(boss_four_horsemenAI, Lady->AI())->encounterActionReset = true;
                    CAST_AI(boss_four_horsemenAI, Baron->AI())->encounterActionReset = true;
                    CAST_AI(boss_four_horsemenAI, Sir->AI())->encounterActionReset = true;

                    CAST_AI(boss_four_horsemenAI, Thane->AI())->EnterEvadeMode();
                    CAST_AI(boss_four_horsemenAI, Lady->AI())->EnterEvadeMode();
                    CAST_AI(boss_four_horsemenAI, Baron->AI())->EnterEvadeMode();
                    CAST_AI(boss_four_horsemenAI, Sir->AI())->EnterEvadeMode();
                }
            }

            if (checkAllDead)
                return !Thane->isAlive() && !Lady->isAlive() && !Baron->isAlive() && !Sir->isAlive();
        }
        return false;
    }

    void BeginFourHorsemenMovement()
    {
        movementStarted = true;
        me->SetReactState(REACT_PASSIVE);
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN), true);

        switch(id)
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

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 2 || id == 5 || id == 8 || id == 11)
        {
            movementCompleted = true;
            me->SetReactState(REACT_AGGRESSIVE);

            Unit *eventStarter = Unit::GetUnit(*me, uiEventStarterGUID);

            if (eventStarter && me->canAttack(eventStarter))
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
    void SelectNearestTarget(Unit *who)
    {
        if (me->getVictim() && me->GetDistanceOrder(who, me->getVictim()) && me->canAttack(who))
        {
            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);
            me->AddThreat(who, 1000000.0f);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        BossAI::MoveInLineOfSight(who);
        if (caster)
            SelectNearestTarget(who);
    }

    void AttackStart(Unit *who)
    {
        if (!movementCompleted && !movementStarted)
        {
            uiEventStarterGUID = who->GetGUID();
            BeginFourHorsemenMovement();

            if (!encounterActionAttack)
                DoEncounterAction(who, true, false, false);
        }
        else if (movementCompleted && movementStarted)
        {
            if (caster)
                me->Attack(who, false);
            else
                BossAI::AttackStart(who);
        }
    }

    void KilledUnit(Unit* /*victim*/)
    {
        if (!(rand()%5))
        {
            if (id == HORSEMEN_BARON)
                DoScriptText(SAY_BARON_SLAY, me);
            else
                DoScriptText(SAY_SLAY[id], me);
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        events.Reset();
        summons.DespawnAll();

        if (instance)
            instance->SetData(DATA_HORSEMEN0 + id, DONE);

        if (instance && DoEncounterAction(NULL, false, false, true))
        {
            instance->SetBossState(BOSS_HORSEMEN, DONE);
            instance->SaveToDB();

            // Achievements related to the 4-horsemen are given through spell 59450 which does not exist.
            // There is thus no way it can be given by casting the spell on the players.
            instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 59450);
        }

        DoScriptText(SAY_DEATH[id], me);
    }

    void EnterCombat(Unit * /*who*/)
    {
        _EnterCombat();

        if (id == HORSEMEN_BARON)
            DoScriptText(SAY_BARON_AGGRO, me);
        else
            DoScriptText(SAY_AGGRO[id], me);

        events.ScheduleEvent(EVENT_MARK, 15000);
        events.ScheduleEvent(EVENT_CAST, 20000+rand()%5000);
        events.ScheduleEvent(EVENT_BERSERK, 15*100*1000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (nextWP && movementStarted && !movementCompleted && !nextMovementStarted)
        {
            nextMovementStarted = true;
            me->GetMotionMaster()->MovePoint(nextWP, WaypointPositions[nextWP]);
        }

        if (!UpdateVictim() || !CheckInRoom() || !movementCompleted)
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_MARK:
                    if (!(rand()%5))
                        DoScriptText(SAY_SPECIAL[id], me);
                    DoCastAOE(SPELL_MARK[id]);
                    events.ScheduleEvent(EVENT_MARK, 15000);
                    break;
                case EVENT_CAST:
                    if (!(rand()%5))
                        DoScriptText(SAY_TAUNT[rand()%3][id], me);

                    if (caster)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f))
                            DoCast(pTarget, SPELL_PRIMARY(id));
                    }
                    else
                        DoCast(me->getVictim(), SPELL_PRIMARY(id));

                    events.ScheduleEvent(EVENT_CAST, 15000);
                    break;
                case EVENT_BERSERK:
                    DoScriptText(SAY_SPECIAL[id], me);
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
        else if ((!DoSpellAttackIfReady(SPELL_SECONDARY(id)) || !me->IsWithinLOSInMap(me->getVictim())) && movementCompleted && !doDelayPunish)
            doDelayPunish = true;
    }
};

CreatureAI* GetAI_four_horsemen(Creature* pCreature)
{
    return new boss_four_horsemenAI (pCreature);
}

void AddSC_boss_four_horsemen()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_four_horsemen";
    newscript->GetAI = &GetAI_four_horsemen;
    newscript->RegisterSelf();
}
