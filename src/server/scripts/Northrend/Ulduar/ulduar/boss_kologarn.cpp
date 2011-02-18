/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Kologarn
SDAuthor: PrinceCreed
SD%Complete: 100%
SD%Comments: Kologarn's vehicleid is wrong.
EndScriptData */

#include "ScriptPCH.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Spells
{
    // Kologarn
    SPELL_ARM_DEAD_DAMAGE                       = 63629,
    SPELL_TWO_ARM_SMASH                         = 63356,
    SPELL_ONE_ARM_SMASH                         = 63573,
    SPELL_ARM_SWEEP                             = 63766,
    SPELL_STONE_SHOUT                           = 63716,
    SPELL_PETRIFY_BREATH                        = 62030,
    SPELL_SHOCKWAVE                             = 63783,
    SPELL_SHOCKWAVE_VISUAL                      = 63788,
    
    SPELL_STONE_GRIP                            = 64290,
    SPELL_STONE_GRIP_STUN                       = 62056,
    SPELL_FOCUSED_EYEBEAM                       = 63347,
    SPELL_EYEBEAM_VISUAL_1                      = 63676,
    SPELL_EYEBEAM_VISUAL_2                      = 63702,
    SPELL_EYEBEAM_IMMUNITY                      = 64722,
    SPELL_ARM_RESPAWN                           = 64753
};

enum Events
{
    EVENT_NONE,
    EVENT_SMASH,
    EVENT_GRIP,
    EVENT_SWEEP,
    EVENT_SHOCKWAVE,
    EVENT_EYEBEAM,
    EVENT_STONESHOT,
    EVENT_RIGHT,
    EVENT_LEFT
};

enum Actions
{
    ACTION_RESPAWN_RIGHT,
    ACTION_RESPAWN_LEFT,
    ACTION_GRIP
};

enum Npcs
{
    NPC_EYEBEAM_1                               = 33632,
    NPC_EYEBEAM_2                               = 33802,
    NPC_RUBBLE                                  = 33768,
    NPC_LEFT_ARM                                = 32933,
    NPC_RIGHT_ARM                               = 32934
};

enum Yells
{
    SAY_AGGRO                                   = -1603230,
    SAY_SLAY_1                                  = -1603231,
    SAY_SLAY_2                                  = -1603232,
    SAY_LEFT_ARM_GONE                           = -1603233,
    SAY_RIGHT_ARM_GONE                          = -1603234,
    SAY_SHOCKWAVE                               = -1603235,
    SAY_GRAB_PLAYER                             = -1603236,
    SAY_DEATH                                   = -1603237,
    SAY_BERSERK                                 = -1603238
};

#define EMOTE_LEFT                              "The Left Arm has regrown!"
#define EMOTE_RIGHT                             "The Right Arm has regrown!"
#define EMOTE_STONE                             "Kologarn casts Stone Grip!"

// Achievements
#define ACHIEVEMENT_LOOKS_COULD_KILL            RAID_MODE(2955, 2956) // TODO
#define ACHIEVEMENT_RUBBLE_AND_ROLL             RAID_MODE(2959, 2960)
#define ACHIEVEMENT_WITH_OPEN_ARMS              RAID_MODE(2951, 2952)
#define ACHIEV_DISARMED_START_EVENT             21687

uint32 GripTargetGUID[3];

const Position RubbleLeft   = {1781.814f, -45.07f, 448.808f, 2.260f};
const Position RubbleRight  = {1781.814f, -3.716f, 448.808f, 4.211f};

enum KologarnChests
{
    CACHE_OF_LIVING_STONE_10                    = 195046,
    CACHE_OF_LIVING_STONE_25                    = 195047
};

class boss_kologarn : public CreatureScript
{
public:
    boss_kologarn() : CreatureScript("boss_kologarn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kologarnAI (pCreature);
    }

    struct boss_kologarnAI : public BossAI
    {
        boss_kologarnAI(Creature *pCreature) : BossAI(pCreature, BOSS_KOLOGARN), vehicle(pCreature->GetVehicleKit()),
            left(false), right(false)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            SetCombatMovement(false);
            emerged = false;
        }

        Vehicle *vehicle;

        bool left, right;
        bool Gripped;
        bool emerged;
        uint32 RubbleCount;

        void MoveInLineOfSight(Unit* who)
        {
            // Birth animation
            if (!emerged && me->IsWithinDistInMap(who, 40.0f) && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->isGameMaster())
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                emerged = true;
            }
        }

        void AttackStart(Unit *who)
        {
            me->Attack(who, true);
        }

        void JustDied(Unit* /*victim*/)
        {                
            DoScriptText(SAY_DEATH, me);
            _JustDied();

            if (instance)
            {
                // Rubble and Roll
                if (RubbleCount > 4)
                    instance->DoCompleteAchievement(ACHIEVEMENT_RUBBLE_AND_ROLL);
                // With Open Arms
                if (RubbleCount == 0)
                    instance->DoCompleteAchievement(ACHIEVEMENT_WITH_OPEN_ARMS);

                // Remove Stone Grip from players
                Map::PlayerList const &players = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
 
                    if (!pPlayer)
                        continue;
 
                    if (pPlayer->HasAura(SPELL_STONE_GRIP_STUN))
                    {
                        pPlayer->RemoveAurasDueToSpell(RAID_MODE(64290, 64292));
                        pPlayer->RemoveAurasDueToSpell(SPELL_STONE_GRIP_STUN);
                        pPlayer->GetMotionMaster()->MoveJump(1767.80f, -18.38f, 448.808f, 10, 10);
                    }
                }
            }

            // Hack to disable corpse fall
            me->GetMotionMaster()->MoveTargetedHome();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(35);
            // Chest spawn
            me->SummonGameObject(RAID_MODE(CACHE_OF_LIVING_STONE_10, CACHE_OF_LIVING_STONE_25),1836.52f,-36.11f,448.81f,0.56f,0,0,1,1,604800);
        }

        void KilledUnit(Unit* /*who*/)
        {
            if (!(rand()%5))
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if (who->GetTypeId() == TYPEID_UNIT)
            {
                if (who->GetEntry() == NPC_LEFT_ARM)
                    left = apply;
                else if (who->GetEntry() == NPC_RIGHT_ARM)
                    right = apply;
                who->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            _EnterCombat();
        
            RubbleCount = 0;
            Gripped = false;
            for (int32 n = 0; n < RAID_MODE(1, 3); ++n)
                GripTargetGUID[n] = NULL;
            
            for (int32 n = 0; n < 2; ++n)
            {
                if (vehicle->GetPassenger(n))
                    vehicle->GetPassenger(n)->ToCreature()->AI()->DoZoneInCombat();
            }
            events.ScheduleEvent(EVENT_SMASH, 5000);
            events.ScheduleEvent(EVENT_SWEEP, 10000);
            events.ScheduleEvent(EVENT_EYEBEAM, 10000);
            events.ScheduleEvent(EVENT_SHOCKWAVE, 12000);
            events.ScheduleEvent(EVENT_GRIP, 40000);
        }

        void Reset()
        {
            _Reset();
            
            if (instance)
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
        
            if (Unit* LeftArm = me->SummonCreature(NPC_LEFT_ARM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                LeftArm->EnterVehicle(vehicle, 0);
            if (Unit* RightArm = me->SummonCreature(NPC_RIGHT_ARM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                RightArm->EnterVehicle(vehicle, 1);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            
            if (events.GetTimer() > 15000 && !me->IsWithinMeleeRange(me->getVictim()))
                DoCastAOE(SPELL_PETRIFY_BREATH, true);
        
            if (!left && !right)
                DoCast(me, SPELL_STONE_SHOUT, true);

            switch(events.GetEvent())
            {
                case EVENT_NONE: break;
                case EVENT_SMASH:
                    if (left && right)
                    {
                        if (me->IsWithinMeleeRange(me->getVictim()))
                            DoCastVictim(SPELL_TWO_ARM_SMASH, true);
                    }
                    else if (left || right)
                    {
                        if (me->IsWithinMeleeRange(me->getVictim()))
                            DoCastVictim(SPELL_ONE_ARM_SMASH, true);
                    }
                    events.RescheduleEvent(EVENT_SMASH, 15000);
                    break;
                case EVENT_SWEEP:
                    if (left)
                        DoCastAOE(SPELL_ARM_SWEEP, true);
                    events.RescheduleEvent(EVENT_SWEEP, 15000);
                    break;
                case EVENT_GRIP:
                    if (right && instance)
                    {
                        if (Unit* RightArm = vehicle->GetPassenger(1))
                        {
                            me->MonsterTextEmote(EMOTE_STONE, 0, true);
                            DoScriptText(SAY_GRAB_PLAYER, me);
                            // Grip up to 3 players
                            for (int32 n = 0; n < RAID_MODE(1, 3); ++n)
                            {
                                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 40, true))
                                    GripTargetGUID[n] = pTarget->GetGUID();
                            }
                            RightArm->ToCreature()->AI()->DoAction(ACTION_GRIP);
                        }
                    }
                    events.RescheduleEvent(EVENT_GRIP, 40000);
                    break;
                case EVENT_SHOCKWAVE:
                    if (left)
                    {
                        DoScriptText(SAY_SHOCKWAVE, me);
                        DoCastAOE(SPELL_SHOCKWAVE, true);
                        DoCastAOE(SPELL_SHOCKWAVE_VISUAL, true);
                    }
                    events.RescheduleEvent(EVENT_SHOCKWAVE, urand(15000, 25000));
                    break;
                case EVENT_EYEBEAM:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 50, true))
                    {
                        if (Creature* EyeBeam = me->SummonCreature(NPC_EYEBEAM_1,pTarget->GetPositionX(),pTarget->GetPositionY()+3,pTarget->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,10000))
                        {
                            EyeBeam->CastSpell(me, SPELL_EYEBEAM_VISUAL_1, true);
                            EyeBeam->AI()->AttackStart(pTarget);
                        }
                        if (Creature* EyeBeam = me->SummonCreature(NPC_EYEBEAM_2,pTarget->GetPositionX(),pTarget->GetPositionY()-3,pTarget->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,10000))
                        {
                            EyeBeam->CastSpell(me, SPELL_EYEBEAM_VISUAL_2, true);
                            EyeBeam->AI()->AttackStart(pTarget);
                        }
                    }
                    events.RescheduleEvent(EVENT_EYEBEAM, 20000);
                    break;
                case EVENT_LEFT:
                    if (Unit* LeftArm = me->SummonCreature(NPC_LEFT_ARM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                    {
                        LeftArm->EnterVehicle(vehicle, 0);
                        DoCast(me, SPELL_ARM_RESPAWN, true);
                        me->MonsterTextEmote(EMOTE_LEFT, 0, true);
                        if (instance)
                            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
                    }
                    events.CancelEvent(EVENT_LEFT);
                    break;                
                case EVENT_RIGHT:
                    if (Unit* RightArm = me->SummonCreature(NPC_RIGHT_ARM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                    {
                        RightArm->EnterVehicle(vehicle, 1);
                        DoCast(me, SPELL_ARM_RESPAWN, true);
                        me->MonsterTextEmote(EMOTE_RIGHT, 0, true);
                        if (instance)
                            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
                    }
                    events.CancelEvent(EVENT_RIGHT);
                    break;
            }

            DoMeleeAttackIfReady();
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_RESPAWN_LEFT:
                    DoScriptText(SAY_LEFT_ARM_GONE, me);
                    me->DealDamage(me, int32(me->GetMaxHealth() * 15 / 100)); // decreases Kologarn's health by 15%
                    ++RubbleCount;
                    if (instance && right)
                        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
                    events.ScheduleEvent(EVENT_LEFT, 30000);
                    break;
                case ACTION_RESPAWN_RIGHT:
                    DoScriptText(SAY_RIGHT_ARM_GONE, me);
                    me->DealDamage(me, int32(me->GetMaxHealth() * 15 / 100));
                    ++RubbleCount;
                    if (instance && left)
                        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
                    events.ScheduleEvent(EVENT_RIGHT, 30000);
                    break;
            }
        }    
    };

};


class npc_focused_eyebeam : public CreatureScript
{
public:
    npc_focused_eyebeam() : CreatureScript("npc_focused_eyebeam") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_focused_eyebeamAI (pCreature);
    }

    struct npc_focused_eyebeamAI : public ScriptedAI
    {
        npc_focused_eyebeamAI(Creature *c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            DoCast(me, SPELL_EYEBEAM_IMMUNITY);
            DoCast(me, SPELL_FOCUSED_EYEBEAM);
            me->SetDisplayId(11686);
            checkTimer = 1500;
        }

        uint32 checkTimer;

        void UpdateAI(const uint32 diff)
        {
            if (checkTimer <= diff)
            {
                if (me->getVictim() && me->getVictim()->isAlive())
                    me->GetMotionMaster()->MovePoint(0,me->getVictim()->GetPositionX(),me->getVictim()->GetPositionY(),me->getVictim()->GetPositionZ());
            
                checkTimer = 500;
            }
            else checkTimer -= diff;
        }
    };

};


class npc_left_arm : public CreatureScript
{
public:
    npc_left_arm() : CreatureScript("npc_left_arm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_left_armAI (pCreature);
    }

    struct npc_left_armAI : public ScriptedAI
    {
        npc_left_armAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* pInstance;

        void JustDied(Unit* /*victim*/)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(NPC_RUBBLE, RubbleLeft, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
            
            if (pInstance)
                if (Creature* pKologarn = me->GetCreature(*me, pInstance->GetData64(DATA_KOLOGARN)))
                    pKologarn->AI()->DoAction(ACTION_RESPAWN_LEFT);
                    
            // Hack to disable corpse fall
            me->GetMotionMaster()->MoveTargetedHome();
        }
    
        void JustSummoned(Creature *summon)
        {
            summon->AI()->DoZoneInCombat();
        }
    };

};


class npc_right_arm : public CreatureScript
{
public:
    npc_right_arm() : CreatureScript("npc_right_arm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_right_armAI (pCreature);
    }

    struct npc_right_armAI : public ScriptedAI
    {
        npc_right_armAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 64708, true);
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* pInstance;

        bool Gripped;
        int32 ArmDamage;
        uint32 SqueezeTimer;

        void Reset()
        {
            Gripped = false;
            ArmDamage = 0;
            SqueezeTimer = 0;
        }

        void JustDied(Unit* /*victim*/)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(NPC_RUBBLE, RubbleRight, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
            
            if (pInstance)
                if (Creature* pKologarn = me->GetCreature(*me, pInstance->GetData64(DATA_KOLOGARN)))
                    pKologarn->AI()->DoAction(ACTION_RESPAWN_RIGHT);
                    
            // Hack to disable corpse fall
            me->GetMotionMaster()->MoveTargetedHome();
        }
    
        void JustSummoned(Creature *summon)
        {
            summon->AI()->DoZoneInCombat();
        }

        void KilledUnit(Unit* Victim)
        {
            if (Victim)
            {
                Victim->ExitVehicle();
                Victim->GetMotionMaster()->MoveJump(1767.80f, -18.38f, 448.808f, 10, 10);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Gripped)
            {
                if (SqueezeTimer <= diff)
                {
                    for (uint8 n = 0; n < RAID_MODE(1, 3); ++n)
                    {
                        if (me->GetVehicleKit()->GetPassenger(n) && me->GetVehicleKit()->GetPassenger(n)->isAlive())
                            me->Kill(me->GetVehicleKit()->GetPassenger(n), true);
                    }
                    Gripped = false;
                }  
                else SqueezeTimer -= diff;
            }
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_GRIP:
                    for (uint8 n = 0; n < RAID_MODE(1, 3); ++n)
                    {
                        if (Unit* GripTarget = Unit::GetUnit(*me, GripTargetGUID[n]))
                        {
                            if (GripTarget && GripTarget->isAlive())
                            {
                                GripTarget->EnterVehicle(me, n);
                                me->AddAura(SPELL_STONE_GRIP, GripTarget);
                                me->AddAura(SPELL_STONE_GRIP_STUN, GripTarget);
                                GripTargetGUID[n] = NULL;
                            }
                        }
                    }  
                    ArmDamage = 0;
                    SqueezeTimer = 16000;
                    Gripped = true;
                    break;
            }
        }
    
        void DamageTaken(Unit* pKiller, uint32 &damage)
        {
            if (Gripped)
            {
                ArmDamage += damage;
                int32 dmg = RAID_MODE(100000, 480000);
            
                if (ArmDamage >= dmg || damage >= me->GetHealth())
                {
                    for (uint8 n = 0; n < RAID_MODE(1, 3); ++n)
                    {
                        Unit* pGripTarget = me->GetVehicleKit()->GetPassenger(n);
                        if (pGripTarget && pGripTarget->isAlive())
                        {
                            pGripTarget->RemoveAurasDueToSpell(SPELL_STONE_GRIP);
                            pGripTarget->RemoveAurasDueToSpell(SPELL_STONE_GRIP_STUN);
                            pGripTarget->ExitVehicle();
                            pGripTarget->GetMotionMaster()->MoveJump(1767.80f, -18.38f, 448.808f, 10, 10);
                        }
                    }
                    Gripped = false;
                }
            }
        }
    };

};


void AddSC_boss_kologarn()
{
    new boss_kologarn();
    new npc_focused_eyebeam();
    new npc_left_arm();
    new npc_right_arm();
}
