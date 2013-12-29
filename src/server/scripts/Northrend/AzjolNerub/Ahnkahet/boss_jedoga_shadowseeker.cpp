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

/*
 * Comment: Complete - BUT THE TRIGGER NEEDS DATA WHETHER THE PRISON OF TALDARAM IS OFFLINE !
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ahnkahet.h"


enum Yells
{
    TEXT_AGGRO          = 0,
    TEXT_SACRIFICE_1    = 1,
    TEXT_SACRIFICE_2    = 2,
    TEXT_SLAY           = 3,
    TEXT_DEATH          = 4,
    TEXT_PREACHING      = 5
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

const Position JedogaPosition[2] =
{
    {372.330994f, -705.278015f, -0.624178f,  5.427970f},
    {372.330994f, -705.278015f, -16.179716f, 5.427970f}
};

enum Misc
{
    ACTION_INITIAND_KILLED                      = 1,
    DATA_VOLUNTEER_WORK                         = 2
};

class boss_jedoga_shadowseeker : public CreatureScript
{
public:
    boss_jedoga_shadowseeker() : CreatureScript("boss_jedoga_shadowseeker") { }

    struct boss_jedoga_shadowseekerAI : public ScriptedAI
    {
        boss_jedoga_shadowseekerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            bFirstTime = true;
            bPreDone = false;
        }

        InstanceScript* instance;

        uint32 uiOpFerTimer;
        uint32 uiCycloneTimer;
        uint32 uiBoltTimer;
        uint32 uiThunderTimer;

        bool bPreDone;
        bool bOpFerok;
        bool bOnGround;
        bool bOpFerokFail;
        bool bCanDown;
        bool volunteerWork;
        bool bFirstTime;

        void Reset() OVERRIDE
        {
            uiOpFerTimer = urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS);

            uiCycloneTimer = 3*IN_MILLISECONDS;
            uiBoltTimer = 7*IN_MILLISECONDS;
            uiThunderTimer = 12*IN_MILLISECONDS;

            bOpFerok = false;
            bOpFerokFail = false;
            bOnGround = false;
            bCanDown = false;
            volunteerWork = true;

            if (instance)
            {
                if (!bFirstTime)
                    instance->SetBossState(DATA_JEDOGA_SHADOWSEEKER, FAIL);

                instance->SetData64(DATA_PL_JEDOGA_TARGET, 0);
                instance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);
                instance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
            }
            MoveUp();

            bFirstTime = false;
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            if (!instance || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            Talk(TEXT_AGGRO);
            me->SetInCombatWithZone();
            instance->SetBossState(DATA_JEDOGA_SHADOWSEEKER, IN_PROGRESS);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            ScriptedAI::AttackStart(who);
        }

        void KilledUnit(Unit* Victim) OVERRIDE
        {
            if (!Victim || Victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(TEXT_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(TEXT_DEATH);
            if (instance)
                instance->SetBossState(DATA_JEDOGA_SHADOWSEEKER, DONE);
        }

        void DoAction(int32 action) OVERRIDE
        {
            if (action == ACTION_INITIAND_KILLED)
                volunteerWork = false;
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            if (type == DATA_VOLUNTEER_WORK)
                return volunteerWork ? 1 : 0;

            return 0;
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE
        {
            if (!instance || !who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_JEDOGA_CONTROLLER))
                return;

            if (!bPreDone && who->GetTypeId() == TYPEID_PLAYER && me->GetDistance(who) < 100.0f)
            {
                Talk(TEXT_PREACHING);
                bPreDone = true;
            }

            if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) != IN_PROGRESS || !bOnGround)
                return;

            if (!me->GetVictim() && me->CanCreatureAttack(who))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                {
                    if (!me->GetVictim())
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
            if (!instance)
                return;

            bOpFerokFail = false;

            instance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 0);
            me->GetMotionMaster()->MovePoint(1, JedogaPosition[1]);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

            me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);

            bOnGround = true;

            if (UpdateVictim())
            {
                AttackStart(me->GetVictim());
                me->GetMotionMaster()->MoveChase(me->GetVictim());
            }
            else
            {
                if (Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_PL_JEDOGA_TARGET)))
                {
                    AttackStart(target);
                    instance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
                    if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) != IN_PROGRESS)
                        EnterCombat(target);
                }
                else if (!me->IsInCombat())
                    EnterEvadeMode();
            }
        }

        void MoveUp()
        {
            if (!instance)
                return;

            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

            me->AttackStop();
            me->RemoveAllAuras();
            me->LoadCreaturesAddon();
            me->GetMotionMaster()->MovePoint(0, JedogaPosition[0]);

            instance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 1);
            if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) == IN_PROGRESS)
                OpferRufen();

            bOnGround = false;
            uiOpFerTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
        }

        void OpferRufen()
        {
            if (!instance)
                return;

            uint64 opfer = instance->GetData64(DATA_ADD_JEDOGA_INITIAND);

            if (opfer)
            {
                Talk(TEXT_SACRIFICE_1);
                instance->SetData64(DATA_ADD_JEDOGA_OPFER, opfer);
            } else
                bCanDown = true;
        }

        void Opfern()
        {
            Talk(TEXT_SACRIFICE_2);

            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_GIFT_OF_THE_HERALD, false);

            bOpFerok = false;
            bCanDown = true;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!instance)
                return;

            if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) != IN_PROGRESS && instance->GetData(DATA_ALL_INITIAND_DEAD))
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
                    uiCycloneTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else uiCycloneTimer -= diff;

                if (uiBoltTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->CastSpell(target, DUNGEON_MODE(SPELL_LIGHTNING_BOLT, SPELL_LIGHTNING_BOLT_H), false);

                    uiBoltTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else uiBoltTimer -= diff;

                if (uiThunderTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->CastSpell(target, DUNGEON_MODE(SPELL_THUNDERSHOCK, SPELL_THUNDERSHOCK_H), false);

                    uiThunderTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else uiThunderTimer -= diff;

                if (uiOpFerTimer <= diff)
                    MoveUp();
                else
                    uiOpFerTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_jedoga_shadowseekerAI>(creature);
    }
};

class npc_jedoga_initiand : public CreatureScript
{
public:
    npc_jedoga_initiand() : CreatureScript("npc_jedoga_initiand") { }

    struct npc_jedoga_initiandAI : public ScriptedAI
    {
        npc_jedoga_initiandAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 bCheckTimer;

        bool bWalking;

        void Reset() OVERRIDE
        {
            if (!instance)
                return;

            bWalking = false;
            bCheckTimer = 2*IN_MILLISECONDS;

            if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) != IN_PROGRESS)
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

        void JustDied(Unit* killer) OVERRIDE
        {
            if (!killer || !instance)
                return;

            if (bWalking)
            {
                if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_JEDOGA_SHADOWSEEKER)))
                {
                    if (!CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerok)
                        CAST_AI(boss_jedoga_shadowseeker::boss_jedoga_shadowseekerAI, boss->AI())->bOpFerokFail = true;

                    if (killer->GetTypeId() == TYPEID_PLAYER)
                        boss->AI()->DoAction(ACTION_INITIAND_KILLED);
                }

                instance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);

                bWalking = false;
            }
            if (killer->GetTypeId() == TYPEID_PLAYER)
                instance->SetData64(DATA_PL_JEDOGA_TARGET, killer->GetGUID());
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
        }

        void AttackStart(Unit* victim) OVERRIDE
        {
            if ((instance && instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) == IN_PROGRESS) || !victim)
                return;

            ScriptedAI::AttackStart(victim);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if ((instance && instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) == IN_PROGRESS) || !who)
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE || !instance)
                return;

            switch (uiPointId)
            {
                case 1:
                    {
                        Creature* boss = me->GetMap()->GetCreature(instance->GetData64(DATA_JEDOGA_SHADOWSEEKER));
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

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (instance && bCheckTimer <= diff)
            {
                if (me->GetGUID() == instance->GetData64(DATA_ADD_JEDOGA_OPFER) && !bWalking)
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
                    if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) != IN_PROGRESS && me->HasAura(SPELL_SPHERE_VISUAL))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                        me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                    }
                    if (instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) == IN_PROGRESS && !me->HasAura(SPELL_SPHERE_VISUAL))
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_jedoga_initiandAI>(creature);
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

    struct npc_jedogas_aufseher_triggerAI : public ScriptedAI
    {
        npc_jedogas_aufseher_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance    = creature->GetInstanceScript();
            bRemoved    = false;
            bRemoved2   = false;
            bCast     = false;
            bCast2    = false;

            SetCombatMovement(false);
        }

        InstanceScript* instance;

        bool bRemoved;
        bool bRemoved2;
        bool bCast;
        bool bCast2;

        void Reset() OVERRIDE { }
        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void AttackStart(Unit* /*victim*/) OVERRIDE { }
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (!instance)
                return;

            if (!bRemoved && me->GetPositionX() > 440.0f)
            {
                if (instance->GetBossState(DATA_PRINCE_TALDARAM) == DONE)
                {
                    me->InterruptNonMeleeSpells(true);
                    bRemoved = true;
                    return;
                }
                if (!bCast)
                {
                    DoCast(me, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_1, false);
                    bCast = true;
                }
            }
            if (!bRemoved2 && me->GetPositionX() < 440.0f)
            {
                if (!bCast2 && instance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
                {
                    DoCast(me, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_2, false);
                    bCast2 = true;
                }
                if (bCast2 && !instance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
                {
                    me->InterruptNonMeleeSpells(true);
                    bCast2 = false;
                }
                if (!bRemoved2 && instance->GetBossState(DATA_JEDOGA_SHADOWSEEKER) == DONE)
                {
                    me->InterruptNonMeleeSpells(true);
                    bRemoved2 = true;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_jedogas_aufseher_triggerAI>(creature);
    }
};

class achievement_volunteer_work : public AchievementCriteriaScript
{
    public:
        achievement_volunteer_work() : AchievementCriteriaScript("achievement_volunteer_work")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* Jedoga = target->ToCreature())
                if (Jedoga->AI()->GetData(DATA_VOLUNTEER_WORK))
                    return true;

            return false;
        }
};

void AddSC_boss_jedoga_shadowseeker()
{
    new boss_jedoga_shadowseeker();
    new npc_jedoga_initiand();
    new npc_jedogas_aufseher_trigger();
    new achievement_volunteer_work();
}
