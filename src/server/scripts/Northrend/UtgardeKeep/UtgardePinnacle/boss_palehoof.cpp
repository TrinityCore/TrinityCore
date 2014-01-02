/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss palehoof
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include <algorithm>
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "utgarde_pinnacle.h"

enum Spells
{
    SPELL_ARCING_SMASH                          = 48260,
    SPELL_IMPALE                                = 48261,
    H_SPELL_IMPALE                              = 59268,
    SPELL_WITHERING_ROAR                        = 48256,
    H_SPELL_WITHERING_ROAR                      = 59267,
    SPELL_FREEZE                                = 16245
};

//Orb spells
enum OrbSpells
{
    SPELL_ORB_VISUAL                            = 48044,
    SPELL_ORB_CHANNEL                           = 48048
};

//not in db
enum Yells
{
    SAY_AGGRO                                = 0,
    SAY_SLAY                                 = 1
  //SAY_DEATH                                = 2 Missing in database
};

enum Creatures
{
    NPC_STASIS_CONTROLLER                       = 26688
};

Position const moveLocs[] =
{
    { 261.6f, -449.3f, 109.5f, 0.0f },
    { 263.3f, -454.0f, 109.5f, 0.0f },
    { 291.5f, -450.4f, 109.5f, 0.0f },
    { 291.5f, -454.0f, 109.5f, 0.0f },
    { 310.0f, -453.4f, 109.5f, 0.0f },
    { 238.6f, -460.7f, 109.5f, 0.0f }
};

enum Phase
{
    PHASE_FRENZIED_WORGEN,
    PHASE_RAVENOUS_FURLBORG,
    PHASE_MASSIVE_JORMUNGAR,
    PHASE_FEROCIOUS_RHINO,
    PHASE_GORTOK_PALEHOOF,
    PHASE_NONE
};

enum Misc
{
    ACTION_NEXT_PHASE,
};

class boss_palehoof : public CreatureScript
{
public:
    boss_palehoof() : CreatureScript("boss_palehoof") { }

    struct boss_palehoofAI : public BossAI
    {
        boss_palehoofAI(Creature* creature) : BossAI(creature, DATA_GORTOK_PALEHOOF)
        {
        }

        uint32 uiArcingSmashTimer;
        uint32 uiImpaleTimer;
        uint32 uiWhiteringRoarTimer;
        uint32 uiWaitingTimer;
        Phase currentPhase;
        uint8 AddCount;
        Phase Sequence[4];

        void Reset() OVERRIDE
        {
            _Reset();

            /// There is a good reason to store them like this, we are going to shuffle the order.
            for (uint32 i = PHASE_FRENZIED_WORGEN; i < PHASE_GORTOK_PALEHOOF; ++i)
                Sequence[i] = Phase(i);

            /// This ensures a random order and only executes each phase once.
            std::random_shuffle(Sequence, Sequence + PHASE_GORTOK_PALEHOOF);

            uiArcingSmashTimer = 15000;
            uiImpaleTimer = 12000;
            uiWhiteringRoarTimer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            AddCount = 0;

            currentPhase = PHASE_NONE;

            for (uint8 i = DATA_FRENZIED_WORGEN; i <= DATA_FEROCIOUS_RHINO; ++i)
                if (Creature* temp = ObjectAccessor::GetCreature(*me, instance->GetData64(i)))
                    if (!temp->IsAlive())
                        temp->Respawn();

            if (GameObject* go = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_GORTOK_PALEHOOF_SPHERE)))
            {
                go->SetGoState(GO_STATE_READY);
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (currentPhase != PHASE_GORTOK_PALEHOOF)
                return;

            if (!UpdateVictim())
                return;

            if (uiArcingSmashTimer <= diff)
            {
                DoCast(me, SPELL_ARCING_SMASH);
                uiArcingSmashTimer = urand(13000, 17000);
            } else uiArcingSmashTimer -= diff;

            if (uiImpaleTimer <= diff)
            {
              if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                  DoCast(target, SPELL_IMPALE);
              uiImpaleTimer = urand(8000, 12000);
            } else uiImpaleTimer -= diff;

            if (uiWhiteringRoarTimer <= diff)
            {
                DoCast(me, SPELL_WITHERING_ROAR);
                uiWhiteringRoarTimer = urand(8000, 12000);
            } else uiWhiteringRoarTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
            //Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DoAction(int32 actionId) OVERRIDE
        {
            if (actionId != ACTION_NEXT_PHASE)
                return;

            if (currentPhase == PHASE_NONE)
            {
                instance->SetBossState(DATA_GORTOK_PALEHOOF, IN_PROGRESS);

                if (Creature* orb = me->SummonCreature(NPC_STASIS_CONTROLLER, moveLocs[5], TEMPSUMMON_CORPSE_DESPAWN))
                    orb->CastSpell(me, SPELL_ORB_VISUAL, true);
            }

            Phase move = PHASE_NONE;
            if (AddCount >= DUNGEON_MODE(2, 4))
                move = PHASE_GORTOK_PALEHOOF;
            else
                move = Sequence[AddCount++];

            // send orb to summon spot
            if (Creature* orb = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_ORB)))
                if (orb->IsAlive())
                    orb->GetMotionMaster()->MovePoint(move, moveLocs[move]);

            currentPhase = move;
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_IMMUNE_TO_PC);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetUtgardePinnacleAI<boss_palehoofAI>(creature);
    }
};

//ravenous furbolg's spells
enum RavenousSpells
{
    SPELL_CHAIN_LIGHTING                        = 48140,
    H_SPELL_CHAIN_LIGHTING                      = 59273,
    SPELL_CRAZED                                = 48139,
    SPELL_TERRIFYING_ROAR                       = 48144
};

class npc_ravenous_furbolg : public CreatureScript
{
public:
    npc_ravenous_furbolg() : CreatureScript("npc_ravenous_furbolg") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_ravenous_furbolgAI>(creature);
    }

    struct npc_ravenous_furbolgAI : public ScriptedAI
    {
        npc_ravenous_furbolgAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiChainLightingTimer;
        uint32 uiCrazedTimer;
        uint32 uiTerrifyingRoarTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiChainLightingTimer = 5000;
            uiCrazedTimer = 10000;
            uiTerrifyingRoarTimer = 15000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance->GetBossState(DATA_GORTOK_PALEHOOF) == IN_PROGRESS)
            {
                Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF));
                if (palehoof && palehoof->IsAlive())
                    palehoof->AI()->Reset();
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiChainLightingTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTING);
                uiChainLightingTimer = 5000 + rand() % 5000;
            } else uiChainLightingTimer -=  diff;

            if (uiCrazedTimer <= diff)
            {
                DoCast(me, SPELL_CRAZED);
                uiCrazedTimer = 8000 + rand() % 4000;
            } else uiCrazedTimer -=  diff;

            if (uiTerrifyingRoarTimer <= diff)
            {
                DoCast(me, SPELL_TERRIFYING_ROAR);
                uiTerrifyingRoarTimer = 10000 + rand() % 10000;
            } else uiTerrifyingRoarTimer -=  diff;

            DoMeleeAttackIfReady();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF)))
                palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

//frenzied worgen's spells
enum FrenziedSpells
{
    SPELL_MORTAL_WOUND                          = 48137,
    H_SPELL_MORTAL_WOUND                        = 59265,
    SPELL_ENRAGE_1                              = 48138,
    SPELL_ENRAGE_2                              = 48142
};

class npc_frenzied_worgen : public CreatureScript
{
public:
    npc_frenzied_worgen() : CreatureScript("npc_frenzied_worgen") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_frenzied_worgenAI>(creature);
    }

    struct npc_frenzied_worgenAI : public ScriptedAI
    {
        npc_frenzied_worgenAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiMortalWoundTimer;
        uint32 uiEnrage1Timer;
        uint32 uiEnrage2Timer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiMortalWoundTimer = 5000;
            uiEnrage1Timer = 15000;
            uiEnrage2Timer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance->GetBossState(DATA_GORTOK_PALEHOOF) == IN_PROGRESS)
            {
                Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF));
                if (palehoof && palehoof->IsAlive())
                    palehoof->AI()->Reset();
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiMortalWoundTimer <= diff)
            {
                DoCastVictim(SPELL_MORTAL_WOUND);
                uiMortalWoundTimer = 3000 + rand() % 4000;
            } else uiMortalWoundTimer -= diff;

            if (uiEnrage1Timer <= diff)
            {
                DoCast(me, SPELL_ENRAGE_1);
                uiEnrage1Timer = 15000;
            } else uiEnrage1Timer -= diff;

            if (uiEnrage2Timer <= diff)
            {
                DoCast(me, SPELL_ENRAGE_2);
                uiEnrage2Timer = 10000;
            } else uiEnrage2Timer -= diff;

            DoMeleeAttackIfReady();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
            instance->SetBossState(DATA_GORTOK_PALEHOOF, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF)))
                palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

//ferocious rhino's spells
enum FerociousSpells
{
    SPELL_GORE                                  = 48130,
    H_SPELL_GORE                                = 59264,
    SPELL_GRIEVOUS_WOUND                        = 48105,
    H_SPELL_GRIEVOUS_WOUND                      = 59263,
    SPELL_STOMP                                 = 48131
};

class npc_ferocious_rhino : public CreatureScript
{
public:
    npc_ferocious_rhino() : CreatureScript("npc_ferocious_rhino") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_ferocious_rhinoAI>(creature);
    }

    struct npc_ferocious_rhinoAI : public ScriptedAI
    {
        npc_ferocious_rhinoAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiStompTimer;
        uint32 uiGoreTimer;
        uint32 uiGrievousWoundTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiStompTimer = 10000;
            uiGoreTimer = 15000;
            uiGrievousWoundTimer = 20000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance->GetBossState(DATA_GORTOK_PALEHOOF) == IN_PROGRESS)
            {
                Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF));
                if (palehoof && palehoof->IsAlive())
                    palehoof->AI()->Reset();
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiStompTimer <= diff)
            {
                DoCastVictim(SPELL_STOMP);
                uiStompTimer = 8000 + rand() % 4000;
            } else uiStompTimer -= diff;

            if (uiGoreTimer <= diff)
            {
                DoCastVictim(SPELL_GORE);
                uiGoreTimer = 13000 + rand() % 4000;
            } else uiGoreTimer -= diff;

            if (uiGrievousWoundTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_GRIEVOUS_WOUND);
                uiGrievousWoundTimer = 18000 + rand() % 4000;
            } else uiGrievousWoundTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF)))
                palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

//massive jormungar's spells
enum MassiveSpells
{
    SPELL_ACID_SPIT                             = 48132,
    SPELL_ACID_SPLATTER                         = 48136,
    H_SPELL_ACID_SPLATTER                       = 59272,
    SPELL_POISON_BREATH                         = 48133,
    H_SPELL_POISON_BREATH                       = 59271
};

enum MassiveAdds
{
  CREATURE_JORMUNGAR_WORM                     = 27228
};

class npc_massive_jormungar : public CreatureScript
{
public:
    npc_massive_jormungar() : CreatureScript("npc_massive_jormungar") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_massive_jormungarAI>(creature);
    }

    struct npc_massive_jormungarAI : public ScriptedAI
    {
        npc_massive_jormungarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiAcidSpitTimer;
        uint32 uiAcidSplatterTimer;
        uint32 uiPoisonBreathTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiAcidSpitTimer = 3000;
            uiAcidSplatterTimer = 12000;
            uiPoisonBreathTimer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance->GetBossState(DATA_GORTOK_PALEHOOF) == IN_PROGRESS)
            {
                Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF));
                if (palehoof && palehoof->IsAlive())
                    palehoof->AI()->Reset();
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiAcidSpitTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ACID_SPIT);
                uiAcidSpitTimer = 2000 + rand() % 2000;
            } else uiAcidSpitTimer -= diff;

            if (uiAcidSplatterTimer <= diff)
            {
                DoCast(me, SPELL_POISON_BREATH);
                uiAcidSplatterTimer = 10000 + rand() % 4000;
            } else uiAcidSplatterTimer -= diff;

            if (uiPoisonBreathTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_POISON_BREATH);
                uiPoisonBreathTimer = 8000 + rand() % 4000;
            } else uiPoisonBreathTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* palehoof = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_GORTOK_PALEHOOF)))
                palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

class npc_palehoof_orb : public CreatureScript
{
public:
    npc_palehoof_orb() : CreatureScript("npc_palehoof_orb") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_palehoof_orbAI>(creature);
    }

    struct npc_palehoof_orbAI : public ScriptedAI
    {
        npc_palehoof_orbAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 SummonTimer;
        Phase currentPhase;

        void Reset() OVERRIDE
        {
            currentPhase = PHASE_NONE;
            SummonTimer = 5000;
            //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->RemoveAurasDueToSpell(SPELL_ORB_VISUAL);
            me->SetSpeed(MOVE_FLIGHT, 0.5f);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (currentPhase == PHASE_NONE)
                return;

            if (SummonTimer <= diff)
            {
                uint8 nextBossId = 0;
                switch (currentPhase)
                {
                    case PHASE_FRENZIED_WORGEN:
                        nextBossId = DATA_FRENZIED_WORGEN;
                        break;
                    case PHASE_RAVENOUS_FURLBORG:
                        nextBossId = DATA_RAVENOUS_FURBOLG;
                        break;
                    case PHASE_MASSIVE_JORMUNGAR:
                        nextBossId = DATA_MASSIVE_JORMUNGAR;
                        break;
                    case PHASE_FEROCIOUS_RHINO:
                        nextBossId = DATA_FEROCIOUS_RHINO;
                        break;
                    case PHASE_GORTOK_PALEHOOF:
                        nextBossId = DATA_GORTOK_PALEHOOF;
                        break;
                    default:
                        return;
                }

                if (Creature* nextBoss = ObjectAccessor::GetCreature(*me, instance->GetData64(nextBossId)))
                {
                    nextBoss->RemoveAurasDueToSpell(SPELL_FREEZE);
                    nextBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                    nextBoss->SetStandState(UNIT_STAND_STATE_STAND);
                    nextBoss->SetInCombatWithZone();
                    nextBoss->Attack(nextBoss->SelectNearestTarget(100), true);
                }
                currentPhase = PHASE_NONE;

                if (nextBossId == DATA_GORTOK_PALEHOOF)
                    me->DespawnOrUnsummon();
            }
            else
                SummonTimer -= diff;
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type != POINT_MOTION_TYPE)
                return;

            uint8 nextBossId = 0;
            switch (id)
            {
                case PHASE_FRENZIED_WORGEN:
                    nextBossId = DATA_FRENZIED_WORGEN;
                    break;
                case PHASE_RAVENOUS_FURLBORG:
                    nextBossId = DATA_RAVENOUS_FURBOLG;
                    break;
                case PHASE_MASSIVE_JORMUNGAR:
                    nextBossId = DATA_MASSIVE_JORMUNGAR;
                    break;
                case PHASE_FEROCIOUS_RHINO:
                    nextBossId = DATA_FEROCIOUS_RHINO;
                    break;
                case PHASE_GORTOK_PALEHOOF:
                    nextBossId = DATA_GORTOK_PALEHOOF;
                    break;
                default:
                    return;
            }

            if (Creature* nextBoss = ObjectAccessor::GetCreature(*me, instance->GetData64(nextBossId)))
                DoCast(nextBoss, SPELL_ORB_CHANNEL, false);

            currentPhase = Phase(id);
            SummonTimer = 5000;
        }
    };

};

class go_palehoof_sphere : public GameObjectScript
{
    public:
        go_palehoof_sphere() : GameObjectScript("go_palehoof_sphere") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
        {
            InstanceScript* instance = go->GetInstanceScript();
            if (!instance)
                return false;

            Creature* palehoof = ObjectAccessor::GetCreature(*go, instance->GetData64(DATA_GORTOK_PALEHOOF));
            if (palehoof && palehoof->IsAlive())
            {
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                go->SetGoState(GO_STATE_ACTIVE);

                palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
            }
            return true;
        }

};

void AddSC_boss_palehoof()
{
    new boss_palehoof();
    new npc_ravenous_furbolg();
    new npc_frenzied_worgen();
    new npc_ferocious_rhino();
    new npc_massive_jormungar();
    new npc_palehoof_orb();
    new go_palehoof_sphere();
}
