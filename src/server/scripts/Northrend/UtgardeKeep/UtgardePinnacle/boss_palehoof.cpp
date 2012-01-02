/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
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
    SAY_AGGRO                                = -1575000,
    SAY_SLAY_1                               = -1575001,
    SAY_SLAY_2                               = -1575002,
    SAY_DEATH                                = -1575003
};

enum Creatures
{
    MOB_STASIS_CONTROLLER                       = 26688
};

struct Locations
{
    float x, y, z;
};

struct Locations moveLocs[]=
{
    {261.6f, -449.3f, 109.5f},
    {263.3f, -454.0f, 109.5f},
    {291.5f, -450.4f, 109.5f},
    {291.5f, -454.0f, 109.5f},
    {310.0f, -453.4f, 109.5f},
    {238.6f, -460.7f, 109.5f}
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

class boss_palehoof : public CreatureScript
{
public:
    boss_palehoof() : CreatureScript("boss_palehoof") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_palehoofAI (creature);
    }

    struct boss_palehoofAI : public ScriptedAI
    {
        boss_palehoofAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiArcingSmashTimer;
        uint32 uiImpaleTimer;
        uint32 uiWhiteringRoarTimer;
        uint32 uiWaitingTimer;
        Phase currentPhase;
        uint8 AddCount;
        bool DoneAdds[4];

        InstanceScript* instance;

        void Reset()
        {
            uiArcingSmashTimer = 15000;
            uiImpaleTimer = 12000;
            uiWhiteringRoarTimer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            for (uint32 i = 0; i < 4; i++)
                DoneAdds[i] = false;
            AddCount = 0;

            currentPhase = PHASE_NONE;

            if (instance)
            {
                instance->SetData(DATA_GORTOK_PALEHOOF_EVENT, NOT_STARTED);

                Creature* temp = Unit::GetCreature((*me), instance->GetData64(DATA_MOB_FRENZIED_WORGEN));
                if (temp && !temp->isAlive())
                    temp->Respawn();

                temp = Unit::GetCreature((*me), instance->GetData64(DATA_MOB_FEROCIOUS_RHINO));
                if (temp && !temp->isAlive())
                    temp->Respawn();

                temp = Unit::GetCreature((*me), instance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR));
                if (temp && !temp->isAlive())
                    temp->Respawn();

                temp = Unit::GetCreature((*me), instance->GetData64(DATA_MOB_RAVENOUS_FURBOLG));
                if (temp && !temp->isAlive())
                    temp->Respawn();

                GameObject* go = instance->instance->GetGameObject(instance->GetData64(DATA_GORTOK_PALEHOOF_SPHERE));
                if (go)
                {
                    go->SetGoState(GO_STATE_READY);
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
        }

        void AttackStart(Unit* who)
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

        void UpdateAI(const uint32 diff)
        {
            if (currentPhase != PHASE_GORTOK_PALEHOOF)
                return;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            Creature* temp = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_ORB) : 0);
            if (temp && temp->isAlive())
                temp->DisappearAndDie();

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

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            if (instance)
                instance->SetData(DATA_GORTOK_PALEHOOF_EVENT, DONE);
            Creature* temp = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_ORB) : 0);
            if (temp && temp->isAlive())
                temp->DisappearAndDie();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void NextPhase()
        {
            if (currentPhase == PHASE_NONE)
            {
                instance->SetData(DATA_GORTOK_PALEHOOF_EVENT, IN_PROGRESS);
                me->SummonCreature(MOB_STASIS_CONTROLLER, moveLocs[5].x, moveLocs[5].y, moveLocs[5].z, 0, TEMPSUMMON_CORPSE_DESPAWN);
            }
            Phase move = PHASE_NONE;
            if (AddCount >= DUNGEON_MODE(2, 4))
                move = PHASE_GORTOK_PALEHOOF;
            else
            {
                //select random not yet defeated add
                uint8 next = urand(0, 3);
                for (uint8 i = 0; i < 16; i++)
                {
                    if (!DoneAdds[i % 4])
                    {
                        if (next == 0)
                        {
                            move = (Phase)(i % 4);
                            break;
                        }
                        else if (next > 0)
                            --next;
                    }
                }
                ++AddCount;
                DoneAdds[move] = true;
                move = (Phase)(move % 4);
            }
            //send orb to summon spot
            Creature* pOrb = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_ORB) : 0);
            if (pOrb && pOrb->isAlive())
            {
                if (currentPhase == PHASE_NONE)
                    pOrb->CastSpell(me, SPELL_ORB_VISUAL, true);
                pOrb->GetMotionMaster()->MovePoint(move, moveLocs[move].x, moveLocs[move].y, moveLocs[move].z);
            }
            currentPhase = move;
        }

        void JustReachedHome()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

//ravenous furbolg's spells
enum RavenousSpells
{
    SPELL_CHAIN_LIGHTING                        = 48140,
    H_SPELL_CHAIN_LIGHTING                      = 59273,
    SPELL_CRAZED                                = 48139,
    SPELL_TERRIFYING_ROAR                       = 48144
};

class mob_ravenous_furbolg : public CreatureScript
{
public:
    mob_ravenous_furbolg() : CreatureScript("mob_ravenous_furbolg") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ravenous_furbolgAI (creature);
    }

    struct mob_ravenous_furbolgAI : public ScriptedAI
    {
        mob_ravenous_furbolgAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiChainLightingTimer;
        uint32 uiCrazedTimer;
        uint32 uiTerrifyingRoarTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiChainLightingTimer = 5000;
            uiCrazedTimer = 10000;
            uiTerrifyingRoarTimer = 15000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
                if (instance->GetData(DATA_GORTOK_PALEHOOF_EVENT) == IN_PROGRESS)
                {
                    Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                    if (pPalehoof && pPalehoof->isAlive())
                        CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->Reset();
                }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiChainLightingTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CHAIN_LIGHTING);
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

        void AttackStart(Unit* who)
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

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof)
                    CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->NextPhase();
            }
        }

        void JustReachedHome()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
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

class mob_frenzied_worgen : public CreatureScript
{
public:
    mob_frenzied_worgen() : CreatureScript("mob_frenzied_worgen") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_frenzied_worgenAI (creature);
    }

    struct mob_frenzied_worgenAI : public ScriptedAI
    {
        mob_frenzied_worgenAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiMortalWoundTimer;
        uint32 uiEnrage1Timer;
        uint32 uiEnrage2Timer;

        InstanceScript* instance;

        void Reset()
        {
            uiMortalWoundTimer = 5000;
            uiEnrage1Timer = 15000;
            uiEnrage2Timer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
                if (instance->GetData(DATA_GORTOK_PALEHOOF_EVENT) == IN_PROGRESS)
                {
                    Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                    if (pPalehoof && pPalehoof->isAlive())
                        CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->Reset();
                }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiMortalWoundTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
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

        void AttackStart(Unit* who)
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
            if (instance)
                instance->SetData(DATA_GORTOK_PALEHOOF_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* pPalehoof = Unit::GetCreature((*me), instance->GetData64(DATA_GORTOK_PALEHOOF));
                if (pPalehoof)
                    CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->NextPhase();
            }
        }

        void JustReachedHome()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
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

class mob_ferocious_rhino : public CreatureScript
{
public:
    mob_ferocious_rhino() : CreatureScript("mob_ferocious_rhino") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ferocious_rhinoAI (creature);
    }

    struct mob_ferocious_rhinoAI : public ScriptedAI
    {
        mob_ferocious_rhinoAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiStompTimer;
        uint32 uiGoreTimer;
        uint32 uiGrievousWoundTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiStompTimer = 10000;
            uiGoreTimer = 15000;
            uiGrievousWoundTimer = 20000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
                if (instance->GetData(DATA_GORTOK_PALEHOOF_EVENT) == IN_PROGRESS)
                {
                    Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                    if (pPalehoof && pPalehoof->isAlive())
                        CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->Reset();
                }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiStompTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_STOMP);
                uiStompTimer = 8000 + rand() % 4000;
            } else uiStompTimer -= diff;

            if (uiGoreTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_GORE);
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

        void AttackStart(Unit* who)
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

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof)
                    CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->NextPhase();
            }
        }

        void JustReachedHome()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
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

class mob_massive_jormungar : public CreatureScript
{
public:
    mob_massive_jormungar() : CreatureScript("mob_massive_jormungar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_massive_jormungarAI (creature);
    }

    struct mob_massive_jormungarAI : public ScriptedAI
    {
        mob_massive_jormungarAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiAcidSpitTimer;
        uint32 uiAcidSplatterTimer;
        uint32 uiPoisonBreathTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiAcidSpitTimer = 3000;
            uiAcidSplatterTimer = 12000;
            uiPoisonBreathTimer = 10000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
                if (instance->GetData(DATA_GORTOK_PALEHOOF_EVENT) == IN_PROGRESS)
                {
                    Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                    if (pPalehoof && pPalehoof->isAlive())
                        CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->Reset();
                }
        }

        void UpdateAI(const uint32 diff)
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

        void AttackStart(Unit* who)
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

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* pPalehoof = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof)
                    CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->NextPhase();
            }
        }

        void JustReachedHome()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoCast(me, SPELL_FREEZE);
        }
    };

};

class mob_palehoof_orb : public CreatureScript
{
public:
    mob_palehoof_orb() : CreatureScript("mob_palehoof_orb") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_palehoof_orbAI (creature);
    }

    struct mob_palehoof_orbAI : public ScriptedAI
    {
        mob_palehoof_orbAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 SummonTimer;
        Phase currentPhase;

        void Reset()
        {
            currentPhase = PHASE_NONE;
            SummonTimer = 5000;
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->RemoveAurasDueToSpell(SPELL_ORB_VISUAL);
            me->SetSpeed(MOVE_FLIGHT, 0.5f);
        }

        void UpdateAI(const uint32 diff)
        {
            if (currentPhase == PHASE_NONE)
                return;

            if (SummonTimer <= diff)
            {
                if (currentPhase<5&&currentPhase >= 0)
                {
                   Creature* pNext = NULL;
                   switch (currentPhase)
                   {
                        case PHASE_FRENZIED_WORGEN: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_FRENZIED_WORGEN) : 0); break;
                        case PHASE_RAVENOUS_FURLBORG: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_RAVENOUS_FURBOLG) : 0); break;
                        case PHASE_MASSIVE_JORMUNGAR: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR) : 0); break;
                        case PHASE_FEROCIOUS_RHINO: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_FEROCIOUS_RHINO) : 0); break;
                        case PHASE_GORTOK_PALEHOOF: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0); break;
                        default: break;
                   }

                   if (pNext)
                   {
                        pNext->RemoveAurasDueToSpell(SPELL_FREEZE);
                        pNext->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        pNext->SetStandState(UNIT_STAND_STATE_STAND);
                        pNext->SetInCombatWithZone();
                        pNext->Attack(pNext->SelectNearestTarget(100), true);

                   }
                   currentPhase = PHASE_NONE;
                }
            } else SummonTimer -= diff;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            if (id > 4)
                return;
            Creature* pNext = NULL;
            switch (id)
            {
                case PHASE_FRENZIED_WORGEN: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_FRENZIED_WORGEN) : 0); break;
                case PHASE_RAVENOUS_FURLBORG: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_RAVENOUS_FURBOLG) : 0); break;
                case PHASE_MASSIVE_JORMUNGAR: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR) : 0); break;
                case PHASE_FEROCIOUS_RHINO: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_MOB_FEROCIOUS_RHINO) : 0); break;
                case PHASE_GORTOK_PALEHOOF: pNext = Unit::GetCreature((*me), instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0); break;
                default: break;
            }
            if (pNext)
                DoCast(pNext, SPELL_ORB_CHANNEL, false);
            currentPhase = (Phase)id;
            SummonTimer = 5000;
        }
    };

};

class go_palehoof_sphere : public GameObjectScript
{
public:
    go_palehoof_sphere() : GameObjectScript("go_palehoof_sphere") { }

    bool OnGossipHello(Player* /*player*/, GameObject* pGO)
    {
        InstanceScript* instance = pGO->GetInstanceScript();

        Creature* pPalehoof = Unit::GetCreature(*pGO, instance ? instance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
        if (pPalehoof && pPalehoof->isAlive())
        {
            pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            pGO->SetGoState(GO_STATE_ACTIVE);

            CAST_AI(boss_palehoof::boss_palehoofAI, pPalehoof->AI())->NextPhase();
        }
        return true;
    }

};

void AddSC_boss_palehoof()
{
    new boss_palehoof();
    new mob_ravenous_furbolg();
    new mob_frenzied_worgen();
    new mob_ferocious_rhino();
    new mob_massive_jormungar();
    new mob_palehoof_orb();
    new go_palehoof_sphere();
}
