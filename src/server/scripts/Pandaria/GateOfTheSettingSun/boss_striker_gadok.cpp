/*
 * Copyright 2021 ShadowCore
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
#include "gate_setting_sun.h"

struct StrafPointStruct
{
    uint8 pointIdBeginOutside;
    Position beginOutside;

    uint8 pointIdBegin;
    Position begin;

    uint8 pointIdEnd;
    Position end;

    uint8 pointIdOutside;
    Position outside;
};

enum eMovements
{
    POINT_NORTH_START       = 1,
    POINT_SOUTH_START       = 2,
    POINT_WEST_START        = 3,
    POINT_EAST_START        = 4,

    POINT_NORTH_END         = 5,
    POINT_SOUTH_END         = 6,
    POINT_WEST_END          = 7,
    POINT_EAST_END          = 8,

    POINT_NORTH_OUTSIDE     = 9,
    POINT_SOUTH_OUTSIDE     = 10,
    POINT_WEST_OUTSIDE      = 11,
    POINT_EAST_OUTSIDE      = 12,

    POINT_KRIKTHIK_CIRCLE   = 13,

    MOV_NORTH_SOUTH         = 0,
    MOV_SOUTH_NORTH         = 1,
    MOV_WEST_EAST           = 2,
    MOV_EAST_WEST           = 3
};

StrafPointStruct StrafPoints[4] =
{
    { POINT_NORTH_OUTSIDE, {1258.0f, 2304.644f, 438.0f, 0.0f}, POINT_NORTH_START, {1238.007f, 2304.644f, 435.0f, 0.0f}, POINT_NORTH_END, {1153.398f, 2304.578f, 435.0f, 0.0f}, POINT_SOUTH_OUTSIDE, {1133.4f, 2304.578f, 438.0f, 0.0f} }, // North -> South
    { POINT_SOUTH_OUTSIDE, {1133.4f, 2304.578f, 438.0f, 0.0f}, POINT_SOUTH_START, {1153.398f, 2304.578f, 435.0f, 0.0f}, POINT_SOUTH_END, {1238.007f, 2304.644f, 435.0f, 0.0f}, POINT_NORTH_OUTSIDE, {1258.0f, 2304.644f, 438.0f, 0.0f} }, // South -> North
    { POINT_WEST_OUTSIDE,  {1195.3f, 2366.941f, 438.0f, 0.0f}, POINT_WEST_START,  {1195.299f, 2348.941f, 435.0f, 0.0f}, POINT_WEST_END,  {1195.392f, 2263.441f, 435.0f, 0.0f}, POINT_EAST_OUTSIDE,  {1195.4f, 2243.441f, 438.0f, 0.0f} }, // West  -> East
    { POINT_EAST_OUTSIDE,  {1195.4f, 2243.441f, 438.0f, 0.0f}, POINT_EAST_START,  {1195.392f, 2263.441f, 435.0f, 0.0f}, POINT_EAST_END,  {1195.299f, 2348.941f, 435.0f, 0.0f}, POINT_WEST_OUTSIDE,  {1195.3f, 2366.941f, 438.0f, 0.0f} }  // East  -> West
};

Position CenterPos = {1195.0f, 2304.0f, 438.0f, 0.0f};

enum eSpells
{
    SPELL_PREY_TIME         = 106933,
    SPELL_IMPALING_STRIKE   = 107047,

    SPELL_STRAFING_RUN      = 107342,
    SPELL_STRAFIND_RUN_DMG  = 116298,

    SPELL_RIDE_VEHICLE      = 46598,

    // Disruptor
    SPELL_BOMB              = 115110
};

enum eEvents
{
    EVENT_PREY_TIME         = 1,
    EVENT_IMPALING_STRIKE   = 2,

    EVENT_DISRUPTOR_BOMBARD = 3
};

enum ePhases
{
    PHASE_MAIN          = 1,
    PHASE_NORTH_SOUTH   = 2,
    PHASE_WEST_EAST     = 3
};

enum eStrafing
{
    STRAF_NONE    = 0,
    STRAF_70      = 1,
    STRAF_30      = 2
};

#define MAX_DISRUPTOR   5
#define MAX_STRIKER     10
#define RADIUS_CIRCLE   100.0f

class boss_striker_gadok : public CreatureScript
{
    public:
        boss_striker_gadok() : CreatureScript("boss_striker_gadok") {}

        struct boss_striker_gadokAI : public BossAI
        {
            boss_striker_gadokAI(Creature* creature) : BossAI(creature, DATA_GADOK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            bool isStrafing;

            uint32 strafingTimer;

            uint8 strafingEventCount;
            uint8 strafingEventProgress;
            uint8 move;

            void Reset() override
            {
                _Reset();
                isStrafing = false;

                strafingTimer = 0;

                strafingEventCount = 0;
                strafingEventProgress = 0;
                move = 0;
                me->GetMotionMaster()->Clear();

                summons.DespawnAll();
                DoSpawnKrikThik();

                if (instance)
                    instance->SetData(DATA_GADOK, PHASE_MAIN);

                events.ScheduleEvent(EVENT_PREY_TIME, 10000, PHASE_MAIN);
                events.ScheduleEvent(EVENT_IMPALING_STRIKE, 19000, PHASE_MAIN);
            }

            void DoSpawnKrikThik()
            {
                for (uint8 i = 0; i < MAX_DISRUPTOR; ++i)
                    SummonKrikThik(NPC_KRIKTHIK_DISRUPTOR);

                for (uint8 i = 0; i < MAX_STRIKER; ++i)
                    SummonKrikThik(NPC_KRIKTHIK_STRIKER);
            }

            TempSummon* SummonKrikThik(uint32 creatureId)
            {
                float angle = frand(0, 2 * (float)M_PI);
                float x = CenterPos.GetPositionX() + (RADIUS_CIRCLE * std::cos(angle));
                float y = CenterPos.GetPositionY() + (RADIUS_CIRCLE * std::sin(angle));

                return me->SummonCreature(creatureId, x, y, CenterPos.GetPositionZ());
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
            }

            void JustReachedHome() override
            {
                if (instance)
                    instance->SetBossState(DATA_GADOK, FAIL);

                summons.DespawnAll();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_NORTH_START:   case POINT_SOUTH_START:   case POINT_WEST_START:   case POINT_EAST_START:
                    case POINT_NORTH_END:     case POINT_SOUTH_END:     case POINT_WEST_END:     case POINT_EAST_END:
                    case POINT_NORTH_OUTSIDE: case POINT_SOUTH_OUTSIDE: case POINT_WEST_OUTSIDE: case POINT_EAST_OUTSIDE:
                        DoStrafingEvent();
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                float nextHealthPct = ((float(me->GetHealth()) - damage)  / float(me->GetMaxHealth())) * 100;

                if (!isStrafing)
                {
                    if ((strafingEventCount < STRAF_70 && nextHealthPct <= 70.0f) ||
                        (strafingEventCount < STRAF_30 && nextHealthPct <= 30.0f))
                    {
                        DoStrafingEvent();
                        ++strafingEventCount;
                    }
                }
                // Must not die during Strafing
                else if (damage >= me->GetHealth())
                    damage = 0;
            }

            uint8 SelectNextStartPoint()
            {
                // In videos, Gadok follow the opposite direction of clockwise, to confirm
                switch (move)
                {
                    case MOV_NORTH_SOUTH:   return MOV_WEST_EAST;
                    case MOV_SOUTH_NORTH:   return MOV_EAST_WEST;
                    case MOV_WEST_EAST:     return MOV_NORTH_SOUTH;
                    case MOV_EAST_WEST:     return MOV_SOUTH_NORTH;
                    default:                break;
                }

                return MOV_NORTH_SOUTH;
            }

            void DoStrafingEvent()
            {
                switch (strafingEventProgress)
                {
                    case 0: // Begin, Gadok is 70% or 30% health, he go to the first POINT_START
                        isStrafing = true;
                        me->SetReactState(REACT_PASSIVE);
                        events.CancelEventGroup(PHASE_MAIN);

                        move = urand(MOV_NORTH_SOUTH, MOV_EAST_WEST);

                        if (instance)
                            instance->SetData(DATA_GADOK, move <= MOV_SOUTH_NORTH ? PHASE_NORTH_SOUTH: PHASE_WEST_EAST);

                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdBegin, StrafPoints[move].begin.GetPositionX(), StrafPoints[move].begin.GetPositionY(), StrafPoints[move].begin.GetPositionZ());

                        for (uint8 i = 0; i < 2; ++i)
                            if (Creature* striker = SummonKrikThik(NPC_KRIKTHIK_STRIKER))
                                if (striker->AI())
                                    striker->AI()->DoAction(0);

                        me->SetWalk(false);
                        ++strafingEventProgress;
                        strafingTimer = 0;
                        break;
                    case 1: // We are a POINT_START, wait 2 sec then continue
                        ++strafingEventProgress;
                        strafingTimer = 2000;
                        break;
                    case 2: // 2 sec passed, move to POINT_END with the spell
                        me->SetSpeed(MOVE_FLIGHT, 2.0f);
                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdEnd, StrafPoints[move].end.GetPositionX(), StrafPoints[move].end.GetPositionY(), StrafPoints[move].end.GetPositionZ());
                        me->CastSpell(me, SPELL_STRAFING_RUN, true);

                        ++strafingEventProgress;
                        break;
                    case 3: // We are a POINT_END, wait 500 ms to let movement finish then continue
                        ++strafingEventProgress;
                        strafingTimer = 50;
                        break;
                    case 4: // First strafing finished, we are at a POINT_END and go to POINT_OUTSIDE
                        if (instance)
                            instance->SetData(DATA_GADOK, PHASE_MAIN);

                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdOutside, StrafPoints[move].outside.GetPositionX(), StrafPoints[move].outside.GetPositionY(), StrafPoints[move].outside.GetPositionZ());
                        ++strafingEventProgress;
                        break;
                    case 5: // We are a POINT_OUTSIDE, wait 500 ms to let movement finish then continue
                        ++strafingEventProgress;
                        strafingTimer = 50;
                        break;
                    case 6: // We are POINT_OUTSIDE, go to the next POINT_OUTSIDE_START
                        move = SelectNextStartPoint();

                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdBeginOutside, StrafPoints[move].beginOutside.GetPositionX(), StrafPoints[move].beginOutside.GetPositionY(), StrafPoints[move].beginOutside.GetPositionZ());
                        ++strafingEventProgress;
                        break;
                    case 7: // We are POINT_OUTSIDE_START, wait 500 ms to let movement finish then continue
                        ++strafingEventProgress;
                        strafingTimer = 50;
                        break;
                    case 8: // We are at POINT_OUTSIDE_START, go to POINT_START

                        if (instance)
                            instance->SetData(DATA_GADOK, move <= MOV_SOUTH_NORTH ? PHASE_NORTH_SOUTH: PHASE_WEST_EAST);

                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdBegin, StrafPoints[move].begin.GetPositionX(), StrafPoints[move].begin.GetPositionY(), StrafPoints[move].begin.GetPositionZ());

                        ++strafingEventProgress;
                        break;
                    case 9: // Just arrived to second POINT_START, wait 2 sec
                        ++strafingEventProgress;
                        strafingTimer = 50;
                        break;
                    case 10: // 2 sec passed, move to POINT_END with the spell
                        me->SetSpeed(MOVE_FLIGHT, 2.0f);
                        me->GetMotionMaster()->MovePoint(StrafPoints[move].pointIdEnd, StrafPoints[move].end.GetPositionX(), StrafPoints[move].end.GetPositionY(), StrafPoints[move].end.GetPositionZ());
                        me->CastSpell(me, SPELL_STRAFING_RUN, true);

                        ++strafingEventProgress;
                        break;
                    case 11: // We are a POINT_END, wait 500 ms to let movement finish then continue
                        ++strafingEventProgress;
                        strafingTimer = 50;
                        break;
                    case 12: // POINT_END, End Strafing Event, go back to fight
                        if (me->GetVictim())
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                        else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            me->AI()->AttackStart(target);

                        if (instance)
                            instance->SetData(DATA_GADOK, PHASE_MAIN);

                        move = 0;
                        me->SetReactState(REACT_AGGRESSIVE);
                        strafingTimer = 0;
                        strafingEventProgress = 0;
                        isStrafing = false;
                        me->SetSpeed(MOVE_FLIGHT, 1.134f);
                        me->SetWalk(true);

                        events.ScheduleEvent(EVENT_PREY_TIME, 5000, PHASE_MAIN);
                        events.ScheduleEvent(EVENT_IMPALING_STRIKE, 9000, PHASE_MAIN);
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);

                switch (summoned->GetEntry())
                {
                    case NPC_KRIKTHIK_STRIKER:
                    case NPC_KRIKTHIK_DISRUPTOR:
                        summoned->SetSpeed(MOVE_FLIGHT, 2);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (strafingTimer)
                {
                    if (strafingTimer <= diff)
                    {
                        strafingTimer = 0;
                        DoStrafingEvent();
                    }
                    else strafingTimer -= diff;
                }

                switch (events.ExecuteEvent())
                {
                    case EVENT_PREY_TIME:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            me->CastSpell(target, SPELL_PREY_TIME, false);

                        events.ScheduleEvent(EVENT_PREY_TIME, 10000, PHASE_MAIN);
                        break;
                    case EVENT_IMPALING_STRIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            me->CastSpell(target, SPELL_IMPALING_STRIKE, false);

                        events.ScheduleEvent(EVENT_IMPALING_STRIKE, 19000, PHASE_MAIN);
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                if (instance)
                {
                    instance->SetBossState(DATA_GADOK, DONE);
                    instance->SaveToDB();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_striker_gadokAI(creature);
        }
};

// Base struct for circle movements
struct npc_krikthik : public ScriptedAI
{
    npc_krikthik(Creature* creature) : ScriptedAI(creature) {}

    uint32 nextMovementTimer;
    float actualAngle;
    float myPositionZ;
    bool direction;

    void Reset() override
    {
        nextMovementTimer = 0;
        actualAngle = me->GetAngle(CenterPos.GetPositionX(), CenterPos.GetPositionY());
        direction = urand(0, 1);

        if (direction)
            myPositionZ = 435.0f;
        else
            myPositionZ = 440.0f;

        // Enable Movements
        MovementInform(POINT_MOTION_TYPE, POINT_KRIKTHIK_CIRCLE);

        me->setActive(true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_KRIKTHIK_CIRCLE)
            nextMovementTimer = 50;
    }

    void SelectNextWaypoint(float& x, float& y)
    {
        if (direction)
            actualAngle -= (float)M_PI / 8.0f;
        else
            actualAngle += (float)M_PI / 8.0f;

        x = CenterPos.GetPositionX() + (me->GetObjectSize() + RADIUS_CIRCLE) * std::cos(actualAngle);
        y = CenterPos.GetPositionY() + (me->GetObjectSize() + RADIUS_CIRCLE) * std::sin(actualAngle);
    }

    void UpdateAI(uint32 diff) override
    {
        if (nextMovementTimer)
        {
            if (nextMovementTimer <= diff)
            {
                nextMovementTimer = 0;

                float x = 0.0f;
                float y = 0.0f;
                SelectNextWaypoint(x, y);

                me->GetMotionMaster()->MovePoint(POINT_KRIKTHIK_CIRCLE, x, y, myPositionZ);
            }
            else nextMovementTimer -= diff;
        }
    }
};

class npc_krikthik_striker : public CreatureScript
{
public:
    npc_krikthik_striker() : CreatureScript("npc_krikthik_striker") { }

    struct npc_krikthik_strikerAI : public npc_krikthik
    {
        npc_krikthik_strikerAI(Creature* creature) : npc_krikthik(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        bool isAttackerStriker;

        void Reset() override
        {
            npc_krikthik::Reset();
            isAttackerStriker = false;
        }

        void DoAction(int32 const /*action*/) override
        {
            isAttackerStriker = true;

            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));

            Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
            Map::PlayerList::const_iterator it = PlayerList.begin();
            // Randomize it, everything is done in the "for"
            for (uint8 i = 0; i < urand(0, PlayerList.getSize() - 1); ++i, ++it);

            if (Player* player = it->GetSource())
                AttackStart(player);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!isAttackerStriker)
                npc_krikthik::UpdateAI(diff);
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_krikthik_strikerAI (creature);
    }
};

class npc_krikthik_disruptor : public CreatureScript
{
public:
    npc_krikthik_disruptor() : CreatureScript("npc_krikthik_disruptor") { }

    struct npc_krikthik_disruptorAI : public npc_krikthik
    {
        npc_krikthik_disruptorAI(Creature* creature) : npc_krikthik(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset() override
        {
            npc_krikthik::Reset();

            events.ScheduleEvent(EVENT_DISRUPTOR_BOMBARD, urand(5000, 20000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!pInstance)
                return;

            npc_krikthik::UpdateAI(diff);

            if (pInstance->GetBossState(DATA_GADOK) != IN_PROGRESS)
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_DISRUPTOR_BOMBARD:
                {
                    if (!pInstance)
                        break;

                    Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();

                    if (PlayerList.isEmpty())
                        return;

                    Map::PlayerList::const_iterator it = PlayerList.begin();
                    for (uint8 i = 0; i < urand(0, PlayerList.getSize() - 1); ++i, ++it);

                    if (it == PlayerList.end())
                        return;

                    if (Player* player = it->GetSource())
                        me->CastSpell(player, SPELL_BOMB, true); //Triggered to avoid pillars line of sight

                    events.ScheduleEvent(EVENT_DISRUPTOR_BOMBARD, urand(5000, 20000));

                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_krikthik_disruptorAI (creature);
    }
};

class npc_flak_cannon : public CreatureScript
{
public:
    npc_flak_cannon() : CreatureScript("npc_flak_cannon") { }

    struct npc_flak_cannonAI : public ScriptedAI
    {
        npc_flak_cannonAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset() override {}

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (!pInstance)
                return;

            if (pInstance->GetBossState(DATA_GADOK) != DONE)
                return;

            if (spell->Id == 116554) // Fire Flak Cannon
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    if (Creature* bombarder = pInstance->instance->GetCreature(pInstance->GetGuidData(DATA_RANDOM_BOMBARDER)))
                    {
                        me->CastSpell(bombarder, 116553, true);
                        bombarder->GetMotionMaster()->MoveFall();
                        bombarder->DespawnOrUnsummon(2000);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_flak_cannonAI (creature);
    }
};

class spell_gadok_strafing: public SpellScriptLoader
{
    public:
        spell_gadok_strafing() :  SpellScriptLoader("spell_gadok_strafing") { }

        class spell_gadok_strafing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gadok_strafing_SpellScript);

            void HandleBeforeCast()
            {
                if (Unit* caster = GetCaster())
                {
                    if (InstanceScript* instance = caster->GetInstanceScript())
                    {
                        uint8 actualStrafPhase = instance->GetData(DATA_GADOK);

                        if (actualStrafPhase == PHASE_MAIN)
                            return;

                        uint32 stalkerEntry = actualStrafPhase == PHASE_NORTH_SOUTH ? NPC_STALKER_NORTH_SOUTH: NPC_STALKER_WEST_EAST;

                        std::list<Creature*> stalkerList;
                        GetCreatureListWithEntryInGrid(stalkerList, caster, stalkerEntry, 10.0f);

                        for (auto itr: stalkerList)
                            if (!itr->HasAura(SPELL_STRAFIND_RUN_DMG))
                                itr->CastSpell(itr, SPELL_STRAFIND_RUN_DMG, true);
                    }
                }
            }

            void Register() override
            {
                BeforeCast += SpellCastFn(spell_gadok_strafing_SpellScript::HandleBeforeCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gadok_strafing_SpellScript();
        }
};

class spell_prey_time: public SpellScriptLoader
{
    public:
        spell_prey_time() :  SpellScriptLoader("spell_prey_time") { }

        class spell_prey_time_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_prey_time_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster() && GetTarget())
                    GetTarget()->CastSpell(GetCaster(), SPELL_RIDE_VEHICLE, true);
            }

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster())
                    GetCaster()->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_prey_time_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_prey_time_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_prey_time_AuraScript();
        }
};

void AddSC_boss_striker_gadok()
{
    new boss_striker_gadok();
    new npc_krikthik_striker();
    new npc_krikthik_disruptor();
    new npc_flak_cannon();
    new spell_gadok_strafing();
    new spell_prey_time();
}
