/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
 * Comment: Complete - BUT THE TRIGGER NEEDS DATA WHETHER THE PRISON OF TALDARAM IS OFFLINE !
 */

#include "ScriptPCH.h"
#include "ahnkahet.h"

enum Yells
{
    TEXT_AGGRO                                    = -1619000,
    TEXT_SACRIFICE_1_1                            = -1619001,
    TEXT_SACRIFICE_1_2                            = -1619002,
    TEXT_SACRIFICE_2_1                            = -1619003,
    TEXT_SACRIFICE_2_2                            = -1619004,
    TEXT_SLAY_1                                   = -1619005,
    TEXT_SLAY_2                                   = -1619006,
    TEXT_SLAY_3                                   = -1619007,
    TEXT_DEATH                                    = -1619008,
    TEXT_PREACHING_1                              = -1619009,
    TEXT_PREACHING_2                              = -1619010,
    TEXT_PREACHING_3                              = -1619011,
    TEXT_PREACHING_4                              = -1619012,
    TEXT_PREACHING_5                              = -1619013
};

enum Spells
{
    SPELL_SPHERE_VISUAL                           = 56075,
    SPELL_GIFT_OF_THE_HERALD                      = 56219,
    SPELL_CYCLONE_STRIKE                          = 56855, // Self
    SPELL_CYCLONE_STRIKE_H                        = 60030,
    SPELL_LIGHTNING_BOLT                          = 56891, // 40Y
    SPELL_LIGHTNING_BOLT_H                        = 60032, // 40Y
    SPELL_THUNDERSHOCK                            = 56926, // 30Y
    SPELL_THUNDERSHOCK_H                          = 60029  // 30Y
};

enum Creatures
{
    NPC_JEDOGA_CONTROLLER                         = 30181
};

const Position JedogaPosition[2] =
{
    {372.330994f, -705.278015f, -0.624178f,  5.427970f},
    {372.330994f, -705.278015f, -16.179716f, 5.427970f}
};

class boss_jedoga_shadowseeker : public CreatureScript
{
public:
    boss_jedoga_shadowseeker() : CreatureScript("boss_jedoga_shadowseeker") { }

    struct boss_jedoga_shadowseekerAI : public ScriptedAI
    {
        boss_jedoga_shadowseekerAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            bFirstTime = true;
            bPreDone = false;
        }

        InstanceScript* pInstance;

        uint32 uiOpFerTimer;
        uint32 uiCycloneTimer;
        uint32 uiBoltTimer;
        uint32 uiThunderTimer;

        bool bPreDone;
        bool bOpFerok;
        bool bOnGround;
        bool bOpFerokFail;
        bool bCanDown;

        bool bFirstTime;

        void Reset()
        {
            uiOpFerTimer = urand(15*IN_MILLISECONDS,20*IN_MILLISECONDS);

            uiCycloneTimer = 3*IN_MILLISECONDS;
            uiBoltTimer = 7*IN_MILLISECONDS;
            uiThunderTimer = 12*IN_MILLISECONDS;

            bOpFerok = false;
            bOpFerokFail = false;
            bOnGround = false;
            bCanDown = false;

            if (pInstance)
            {
                if (!bFirstTime)
                    pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, FAIL);

                pInstance->SetData64(DATA_PL_JEDOGA_TARGET, 0);
                pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);
                pInstance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
            }
            MoveUp();

            bFirstTime = false;
        }

        void EnterCombat(Unit* who)
        {
            if (!pInstance || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            DoScriptText(TEXT_AGGRO, me);
            me->SetInCombatWithZone();
            pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, IN_PROGRESS);
        }

        void AttackStart(Unit* who)
        {
            if (!who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            ScriptedAI::AttackStart(who);
        }

        void KilledUnit(Unit* Victim)
        {
            if (!Victim || Victim->GetTypeId() != TYPEID_PLAYER)
                return;

            DoScriptText(RAND(TEXT_SLAY_1, TEXT_SLAY_2, TEXT_SLAY_3), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(TEXT_DEATH, me);
            if (pInstance)
                pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, DONE);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!pInstance || !who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            if (!bPreDone && who->GetTypeId() == TYPEID_PLAYER && me->GetDistance(who) < 100.0f)
            {
                DoScriptText(RAND(TEXT_PREACHING_1, TEXT_PREACHING_2, TEXT_PREACHING_3, TEXT_PREACHING_4, TEXT_PREACHING_5), me);
                bPreDone = true;
            }

            if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS || !bOnGround)
                return;

            if (!me->getVictim() && who->isTargetableForAttack() && me->IsHostileTo(who) && who->isInAccessiblePlaceFor(me))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                {
                    if (!me->getVictim())
                    {
                        who->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                        AttackStart(who);
                    }
                    else if (me->GetMap()->IsDungeon())
                    {
                        who->SetInCombatWith(me);
                        me->AddThreat(who, 0.0f);
                    }
                }
            }
        }

        void MoveDown()
        {
            if (!pInstance)
                return;

            bOpFerokFail = false;

            pInstance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 0);
            me->GetMotionMaster()->MovePoint(1, JedogaPosition[1]);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

            me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);

            bOnGround = true;

            if (UpdateVictim())
            {
                AttackStart(me->getVictim());
                me->GetMotionMaster()->MoveChase(me->getVictim());
            }
            else
            {
                if (Unit* pTarget = Unit::GetUnit(*me, pInstance->GetData64(DATA_PL_JEDOGA_TARGET)))
                {
                    AttackStart(pTarget);
                    pInstance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
                    if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS)
                        EnterCombat(pTarget);
                }
                else if (!me->isInCombat())
                    EnterEvadeMode();
            }
        }

        void MoveUp()
        {
            if (!pInstance)
                return;

            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

            me->AttackStop();
            me->RemoveAllAuras();
            me->LoadCreaturesAddon();
            me->GetMotionMaster()->MovePoint(0, JedogaPosition[0]);

            pInstance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 1);
            if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) OpferRufen();

            bOnGround = false;
            uiOpFerTimer = urand(15*IN_MILLISECONDS,30*IN_MILLISECONDS);
        }

        void OpferRufen()
        {
            if (!pInstance)
                return;

            uint64 opfer = pInstance->GetData64(DATA_ADD_JEDOGA_INITIAND);

            if (opfer)
            {
                DoScriptText(RAND(TEXT_SACRIFICE_1_1, TEXT_SACRIFICE_1_2), me);
                pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, opfer);
            } else
                bCanDown = true;
        }

        void Opfern()
        {
            DoScriptText(RAND(TEXT_SACRIFICE_2_1, TEXT_SACRIFICE_2_2), me);

            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_GIFT_OF_THE_HERALD, false);

            bOpFerok = false;
            bCanDown = true;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!pInstance)
                return;

            if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS && pInstance->GetData(DATA_ALL_INITIAND_DEAD))
                MoveDown();

            if (bOpFerok && !bOnGround && !bCanDown) Opfern();

            if (bOpFerokFail && !bOnGround && !bCanDown)
                bCanDown = true;

            if (bCanDown)
            {
                MoveDown();
                bCanDown = false;
            }

            if (bOnGround)
            {
                if (!UpdateVictim())
                    return;

                if (uiCycloneTimer <= diff)
                {
                    DoCast(me, SPELL_CYCLONE_STRIKE, false);
                    uiCycloneTimer = urand(15*IN_MILLISECONDS,30*IN_MILLISECONDS);
                } else uiCycloneTimer -= diff;

                if (uiBoltTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->CastSpell(pTarget, DUNGEON_MODE(SPELL_LIGHTNING_BOLT, SPELL_LIGHTNING_BOLT_H), false);

                    uiBoltTimer = urand(15*IN_MILLISECONDS,30*IN_MILLISECONDS);
                } else uiBoltTimer -= diff;

                if (uiThunderTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->CastSpell(pTarget, DUNGEON_MODE(SPELL_THUNDERSHOCK, SPELL_THUNDERSHOCK_H), false);

                    uiThunderTimer = urand(15*IN_MILLISECONDS,30*IN_MILLISECONDS);
                } else uiThunderTimer -= diff;

                if (uiOpFerTimer <= diff)
                    MoveUp();
                else
                    uiOpFerTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new boss_jedoga_shadowseekerAI(creature);
    }
};

class mob_jedoga_initiand : public CreatureScript
{
public:
    mob_jedoga_initiand() : CreatureScript("mob_jedoga_initiand") { }

    struct mob_jedoga_initiandAI : public ScriptedAI
    {
        mob_jedoga_initiandAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 bCheckTimer;

        bool bWalking;

        void Reset()
        {
            if (!pInstance)
                return;

            bWalking = false;
            bCheckTimer = 2*IN_MILLISECONDS;

            if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS)
            {
                me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
            }
            else
            {
                DoCast(me, SPELL_SPHERE_VISUAL, false);
                me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        void JustDied(Unit* Killer)
        {
            if (!Killer || !pInstance) return;

            if (bWalking)
            {
                Creature* boss = me->GetMap()->GetCreature(pInstance->GetData64(DATA_JEDOGA_SHADOWSEEKER));
                if (boss && !CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerok) CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerokFail = true;

                if (Killer->GetTypeId() == TYPEID_PLAYER) pInstance->SetData(DATA_INITIAND_KILLED, 1);
                pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);

                bWalking = false;
            }
            if (Killer->GetTypeId() == TYPEID_PLAYER) pInstance->SetData64(DATA_PL_JEDOGA_TARGET, Killer->GetGUID());
        }

        void EnterCombat(Unit* who)
        {
            if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !who) return;
        }

        void AttackStart(Unit* victim)
        {
            if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !victim) return;

            ScriptedAI::AttackStart(victim);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !who) return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE || !pInstance) return;

            switch(uiPointId)
            {
                case 1:
                    {
                        Creature* boss = me->GetMap()->GetCreature(pInstance->GetData64(DATA_JEDOGA_SHADOWSEEKER));
                        if (boss)
                        {
                            CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerok = true;
                            CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerokFail = false;
                            me->Kill(me);
                        }
                    }
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (pInstance && bCheckTimer <= diff)
            {
                if (me->GetGUID() == pInstance->GetData64(DATA_ADD_JEDOGA_OPFER) && !bWalking)
                {
                    me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

                    float distance = me->GetDistance(JedogaPosition[1]);

                    if (distance < 9.0f)
                        me->SetSpeed(MOVE_WALK, 0.5f, true);
                    else if (distance < 15.0f)
                        me->SetSpeed(MOVE_WALK, 0.75f, true);
                    else if (distance < 20.0f)
                        me->SetSpeed(MOVE_WALK, 1.0f, true);

                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MovePoint(1, JedogaPosition[1]);
                    bWalking = true;
                }
                if (!bWalking)
                {
                    if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS && me->HasAura(SPELL_SPHERE_VISUAL))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                    }
                    if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS && !me->HasAura(SPELL_SPHERE_VISUAL))
                    {
                        DoCast(me, SPELL_SPHERE_VISUAL, false);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                bCheckTimer = 2*IN_MILLISECONDS;
            } else bCheckTimer -= diff;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_jedoga_initiandAI(creature);
    }
};

// ------------------------------------------------------------------------------------------------------------
// Jedogas Aufseher - Entry: 30181
// ------------------------------------------------------------------------------------------------------------
enum AufseherSpell
{
  SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_1            = 60342,
  SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_2            = 56312
};

class npc_jedogas_aufseher_trigger : public CreatureScript
{
public:
    npc_jedogas_aufseher_trigger() : CreatureScript("npc_jedogas_aufseher_trigger") { }

    struct npc_jedogas_aufseher_triggerAI : public Scripted_NoMovementAI
    {
        npc_jedogas_aufseher_triggerAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            pInstance = c->GetInstanceScript();
            bRemoved = false;
            bRemoved2 = false;
            bCasted = false;
            bCasted2 = false;
        }

        InstanceScript* pInstance;

        bool bRemoved;
        bool bRemoved2;
        bool bCasted;
        bool bCasted2;

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!pInstance)
                return;

            if (!bRemoved && me->GetPositionX() > 440.0f)
            {
                if (pInstance->GetData(DATA_PRINCE_TALDARAM_EVENT) == DONE)
                {
                    me->InterruptNonMeleeSpells(true);
                    bRemoved = true;
                    return;
                }
                if (!bCasted)
                {
                    DoCast(me, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_1, false);
                    bCasted = true;
                }
            }
            if (!bRemoved2 && me->GetPositionX() < 440.0f)
            {
                if (!bCasted2 && pInstance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
                {
                    DoCast(me, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_2, false);
                    bCasted2 = true;
                }
                if (bCasted2 && !pInstance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
                {
                    me->InterruptNonMeleeSpells(true);
                    bCasted2 = false;
                }
                if (!bRemoved2 && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == DONE)
                {
                    me->InterruptNonMeleeSpells(true);
                    bRemoved2 = true;
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_jedogas_aufseher_triggerAI(creature);
    }
};

void AddSC_boss_jedoga_shadowseeker()
{
    new boss_jedoga_shadowseeker;
    new mob_jedoga_initiand;
    new npc_jedogas_aufseher_trigger;
}
