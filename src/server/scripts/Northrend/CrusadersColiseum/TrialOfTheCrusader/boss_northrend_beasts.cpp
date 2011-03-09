/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: northrend_beasts
SD%Complete: 90%
SDComment: based on /dev/rsa
SDCategory:
EndScriptData */

// Known bugs:
// Gormok - Not implemented as a vehicle
//        - Snobold Firebomb
//        - Snobolled (creature at back)
// Snakes - miss the 1-hitkill from emerging
//        - visual changes between mobile and stationary models seems not to work sometimes

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    //Gormok
    SAY_SNOBOLLED        = -1649000,
    //Acidmaw & Dreadscale
    SAY_SUBMERGE         = -1649010,
    SAY_EMERGE           = -1649011,
    SAY_BERSERK          = -1649012,
    //Icehowl
    SAY_TRAMPLE_STARE    = -1649020,
    SAY_TRAMPLE_FAIL     = -1649021,
    SAY_TRAMPLE_START    = -1649022,
};

enum Equipment
{
    EQUIP_MAIN           = 50760,
    EQUIP_OFFHAND        = 48040,
    EQUIP_RANGED         = 47267,
    EQUIP_DONE           = EQUIP_NO_CHANGE,
};

enum Model
{
    MODEL_ACIDMAW_STATIONARY     = 29815,
    MODEL_ACIDMAW_MOBILE         = 29816,
    MODEL_DREADSCALE_STATIONARY  = 26935,
    MODEL_DREADSCALE_MOBILE      = 24564,
};

enum Summons
{
    NPC_SNOBOLD_VASSAL   = 34800,
    NPC_SLIME_POOL       = 35176,
};

enum BossSpells
{
    //Gormok
    SPELL_IMPALE            = 66331,
    SPELL_STAGGERING_STOMP  = 67648,
    SPELL_RISING_ANGER      = 66636,
    //Snobold
    SPELL_SNOBOLLED         = 66406,
    SPELL_BATTER            = 66408,
    SPELL_FIRE_BOMB         = 66313,
    SPELL_FIRE_BOMB_1       = 66317,
    SPELL_FIRE_BOMB_DOT     = 66318,
    SPELL_HEAD_CRACK        = 66407,

    //Acidmaw & Dreadscale
    SPELL_ACID_SPIT         = 66880,
    SPELL_PARALYTIC_SPRAY   = 66901,
    SPELL_ACID_SPEW         = 66819,
    SPELL_PARALYTIC_BITE    = 66824,
    SPELL_SWEEP_0           = 66794,
    SUMMON_SLIME_POOL       = 66883,
    SPELL_FIRE_SPIT         = 66796,
    SPELL_MOLTEN_SPEW       = 66821,
    SPELL_BURNING_BITE      = 66879,
    SPELL_BURNING_SPRAY     = 66902,
    SPELL_SWEEP_1           = 67646,
    SPELL_EMERGE_0          = 66947,
    SPELL_SUBMERGE_0        = 53421,
    SPELL_ENRAGE            = 68335,
    SPELL_SLIME_POOL_EFFECT = 66882, //In 60s it diameter grows from 10y to 40y (r=r+0.25 per second)

    //Icehowl
    SPELL_FEROCIOUS_BUTT    = 66770,
    SPELL_MASSIVE_CRASH     = 66683,
    SPELL_WHIRL             = 67345,
    SPELL_ARCTIC_BREATH     = 66689,
    SPELL_TRAMPLE           = 66734,
    SPELL_FROTHING_RAGE     = 66759,
    SPELL_STAGGERED_DAZE    = 66758,
};

class boss_gormok : public CreatureScript
{
public:
    boss_gormok() : CreatureScript("boss_gormok") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_gormokAI(pCreature);
    }

    struct boss_gormokAI : public ScriptedAI
    {
        boss_gormokAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 m_uiImpaleTimer;
        uint32 m_uiStaggeringStompTimer;
        SummonList Summons;
        uint32 m_uiSummonTimer;
        uint32 m_uiSummonCount;

        void Reset()
        {
            m_uiImpaleTimer = urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            m_uiStaggeringStompTimer = 15*IN_MILLISECONDS;
            m_uiSummonTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);;

            if (getDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL ||
                getDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                m_uiSummonCount = 5;
            else
                m_uiSummonCount = 4;

            Summons.DespawnAll();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_DONE);
        }

        void JustReachedHome()
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
            me->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            me->SetInCombatWithZone();
            m_pInstance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_IN_PROGRESS);
        }

        void JustSummoned(Creature* summon)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
            {
                if (summon->GetEntry() == NPC_SNOBOLD_VASSAL)
                {
                    summon->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 10.0f, 20.0f);
                    DoCast(me, SPELL_RISING_ANGER);
                    --m_uiSummonCount;
                }
                summon->AI()->AttackStart(target);
            }
            Summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (summon->GetEntry() == NPC_SNOBOLD_VASSAL)
                if (summon->isAlive())
                    ++m_uiSummonCount;
            Summons.Despawn(summon);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (m_uiImpaleTimer <= uiDiff)
            {
                DoCastVictim(SPELL_IMPALE);
                m_uiImpaleTimer = urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            } else m_uiImpaleTimer -= uiDiff;

            if (m_uiStaggeringStompTimer <= uiDiff)
            {
                DoCastVictim(SPELL_STAGGERING_STOMP);
                m_uiStaggeringStompTimer = urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            } else m_uiStaggeringStompTimer -= uiDiff;

            if (m_uiSummonTimer <= uiDiff)
            {
                if (m_uiSummonCount > 0)
                {
                    me->SummonCreature(NPC_SNOBOLD_VASSAL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN);
                    DoScriptText(SAY_SNOBOLLED, me);
                }
                m_uiSummonTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            } else m_uiSummonTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};


class mob_snobold_vassal : public CreatureScript
{
public:
    mob_snobold_vassal() : CreatureScript("mob_snobold_vassal") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_snobold_vassalAI(pCreature);
    }

    struct mob_snobold_vassalAI : public ScriptedAI
    {
        mob_snobold_vassalAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            if (m_pInstance)
                m_pInstance->SetData(DATA_SNOBOLD_COUNT, INCREASE);
        }

        InstanceScript* m_pInstance;
        uint32 m_uiFireBombTimer;
        uint32 m_uiBatterTimer;
        uint32 m_uiHeadCrackTimer;
        uint64 m_uiBossGUID;
        uint64 m_uiTargetGUID;
        bool   m_bTargetDied;

        void Reset()
        {
            m_uiFireBombTimer = 15000;
            m_uiBatterTimer = 5000;
            m_uiHeadCrackTimer = 25000;

            m_uiTargetGUID = 0;
            m_bTargetDied = false;
            if (m_pInstance)
                m_uiBossGUID = m_pInstance->GetData64(NPC_GORMOK);
            //Workaround for Snobold
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }

        void EnterCombat(Unit *pWho)
        {
            m_uiTargetGUID = pWho->GetGUID();
            me->TauntApply(pWho);
            DoCast(pWho, SPELL_SNOBOLLED);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (pDoneBy->GetGUID()==m_uiTargetGUID)
                uiDamage = 0;
        }

        void MovementInform(uint32 uiType, uint32 uiId)
        {
            if (uiType != POINT_MOTION_TYPE) return;

            switch (uiId)
            {
                case 0: // JUMP!? Fuck! THAT'S BEEZARR! Would someone PLEASE make MotionMaster->Move* work better?
                    if (m_bTargetDied)
                        me->DespawnOrUnsummon();
                    break;
            }
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (Unit *pTarget = Unit::GetPlayer(*me, m_uiTargetGUID))
                if (pTarget->isAlive())
                    pTarget->RemoveAurasDueToSpell(SPELL_SNOBOLLED);
            if (m_pInstance)
                m_pInstance->SetData(DATA_SNOBOLD_COUNT, DECREASE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_bTargetDied || !UpdateVictim())
                return;

            if (Unit* pTarget = Unit::GetPlayer(*me, m_uiTargetGUID))
            {
                if (!pTarget->isAlive())
                {
                    if (m_pInstance)
                    {
                        Unit* gormok = ObjectAccessor::GetCreature(*me, m_pInstance->GetData64(NPC_GORMOK));
                        if (gormok && gormok->isAlive())
                        {
                            SetCombatMovement(false);
                            m_bTargetDied = true;
                            me->GetMotionMaster()->MoveJump(gormok->GetPositionX(), gormok->GetPositionY(), gormok->GetPositionZ(), 15.0f, 15.0f);
                        }
                        else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            m_uiTargetGUID = target->GetGUID();
                            me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 15.0f, 15.0f);
                        }
                    }
                }
            }

            if (m_uiFireBombTimer < uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FIRE_BOMB);
                m_uiFireBombTimer = 20000;
            }
            else m_uiFireBombTimer -= uiDiff;

            if (m_uiBatterTimer < uiDiff)
            {
                if (Unit *pTarget = Unit::GetPlayer(*me, m_uiTargetGUID))
                    DoCast(pTarget, SPELL_BATTER);
                m_uiBatterTimer = 10000;
            }
            else m_uiBatterTimer -= uiDiff;

            if (m_uiHeadCrackTimer < uiDiff)
            {
                if (Unit *pTarget = Unit::GetPlayer(*me, m_uiTargetGUID))
                    DoCast(pTarget, SPELL_HEAD_CRACK);
                m_uiHeadCrackTimer = 35000;
            }
            else m_uiHeadCrackTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};


struct boss_jormungarAI : public ScriptedAI
{
    boss_jormungarAI(Creature* creature) : ScriptedAI(creature)
    {
        instanceScript = creature->GetInstanceScript();
    }

    void Reset()
    {
        enraged = false;
        biteTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
        spewTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
        slimePoolTimer = 15*IN_MILLISECONDS;
        spitTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
        sprayTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
        sweepTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
    }

    void JustDied(Unit* /*pKiller*/)
    {
        if (instanceScript)
        {
            if (Creature* otherWorm = Unit::GetCreature(*me, instanceScript->GetData64(otherWormEntry)))
            {
                if (!otherWorm->isAlive())
                {
                    instanceScript->SetData(TYPE_NORTHREND_BEASTS, SNAKES_DONE);

                    me->DespawnOrUnsummon();
                    otherWorm->DespawnOrUnsummon();
                }
                else
                    instanceScript->SetData(TYPE_NORTHREND_BEASTS, SNAKES_SPECIAL);
            }
        }
    }

    void JustReachedHome()
    {
        if (instanceScript && instanceScript->GetData(TYPE_NORTHREND_BEASTS) != FAIL)
            instanceScript->SetData(TYPE_NORTHREND_BEASTS, FAIL);

        me->DespawnOrUnsummon();
    }

    void KilledUnit(Unit *pWho)
    {
        if (pWho->GetTypeId() == TYPEID_PLAYER)
        {
            if (instanceScript)
                instanceScript->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
        }
    }

    void EnterCombat(Unit* /*pWho*/)
    {
        me->SetInCombatWithZone();
        if (instanceScript)
            instanceScript->SetData(TYPE_NORTHREND_BEASTS, SNAKES_IN_PROGRESS);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim()) return;

        if (instanceScript && instanceScript->GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL && !enraged)
        {
            DoScriptText(SAY_EMERGE, me);
            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            DoCast(SPELL_ENRAGE);
            enraged = true;
            DoScriptText(SAY_BERSERK, me);
            switch (stage)
            {
                case 0:
                    break;
                case 4:
                    stage = 5;
                    submergeTimer = 5*IN_MILLISECONDS;
                    break;
                default:
                    stage = 7;
            }
        }

        switch (stage)
        {
            case 0: // Mobile
                if (biteTimer <= uiDiff)
                {
                    DoCastVictim(biteSpell);
                    biteTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else biteTimer -= uiDiff;

                if (spewTimer <= uiDiff)
                {
                    DoCastAOE(spewSpell);
                    spewTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else spewTimer -= uiDiff;

                if (slimePoolTimer <= uiDiff)
                {
                    /* Spell summon has only 30s duration */
                    DoCast(me, SUMMON_SLIME_POOL);
                    slimePoolTimer = 30*IN_MILLISECONDS;
                } else slimePoolTimer -= uiDiff;

                if (submergeTimer <= uiDiff && !enraged)
                {
                    stage = 1;
                    submergeTimer = 5*IN_MILLISECONDS;
                } else submergeTimer -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            case 1: // Submerge
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_SUBMERGE_0);
                DoScriptText(SAY_SUBMERGE, me);
                me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX()+urand(0, 80)-40, ToCCommonLoc[1].GetPositionY()+urand(0, 80)-40, ToCCommonLoc[1].GetPositionZ());
                stage = 2;
            case 2: // Wait til emerge
                if (submergeTimer <= uiDiff)
                {
                    stage = 3;
                    submergeTimer = 50*IN_MILLISECONDS;
                } else submergeTimer -= uiDiff;
                break;
            case 3: // Emerge
                me->SetDisplayId(modelStationary);
                DoScriptText(SAY_EMERGE, me);
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
                DoCast(me, SPELL_EMERGE_0);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                SetCombatMovement(false);
                me->GetMotionMaster()->MoveIdle();
                stage = 4;
                break;
            case 4: // Stationary
                if (sprayTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, spraySpell);
                    sprayTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else sprayTimer -= uiDiff;

                if (sweepTimer <= uiDiff)
                {
                    DoCastAOE(SPELL_SWEEP_0);
                    sweepTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                } else sweepTimer -= uiDiff;

                if (submergeTimer <= uiDiff)
                {
                    stage = 5;
                    submergeTimer = 10*IN_MILLISECONDS;
                } else submergeTimer -= uiDiff;

                DoSpellAttackIfReady(spitSpell);
                break;
            case 5: // Submerge
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_SUBMERGE_0);
                DoScriptText(SAY_SUBMERGE, me);
                me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX()+urand(0, 80)-40, ToCCommonLoc[1].GetPositionY()+urand(0, 80)-40, ToCCommonLoc[1].GetPositionZ());
                stage = 6;
            case 6: // Wait til emerge
                if (submergeTimer <= uiDiff)
                {
                    stage = 7;
                    submergeTimer = 45*IN_MILLISECONDS;
                } else submergeTimer -= uiDiff;
                break;
            case 7: // Emerge
                me->SetDisplayId(modelMobile);
                DoScriptText(SAY_EMERGE, me);
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
                DoCast(me, SPELL_EMERGE_0);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                SetCombatMovement(true);
                me->GetMotionMaster()->MoveChase(me->getVictim());
                stage = 0;
                break;
        }
    }

    InstanceScript* instanceScript;

    uint32 otherWormEntry;

    uint32 modelStationary;
    uint32 modelMobile;

    uint32 biteSpell;
    uint32 spewSpell;
    uint32 spitSpell;
    uint32 spraySpell;

    uint32 biteTimer;
    uint32 spewTimer;
    uint32 slimePoolTimer;
    uint32 spitTimer;
    uint32 sprayTimer;
    uint32 sweepTimer;
    uint32 submergeTimer;
    uint8  stage;
    bool   enraged;
};


class boss_acidmaw : public CreatureScript
{
    public:
    boss_acidmaw() : CreatureScript("boss_acidmaw") { }

    struct boss_acidmawAI : public boss_jormungarAI
    {
        boss_acidmawAI(Creature* pCreature) : boss_jormungarAI(pCreature) { }

        void Reset()
        {
            boss_jormungarAI::Reset();
            biteSpell = SPELL_PARALYTIC_BITE;
            spewSpell = SPELL_ACID_SPEW;
            spitSpell = SPELL_ACID_SPIT;
            spraySpell = SPELL_PARALYTIC_SPRAY;
            modelStationary = MODEL_ACIDMAW_STATIONARY;
            modelMobile = MODEL_ACIDMAW_MOBILE;
            otherWormEntry = NPC_DREADSCALE;

            submergeTimer = 500;
            DoCast(me, SPELL_SUBMERGE_0);
            stage = 2;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_acidmawAI(creature);
    }
};


class boss_dreadscale : public CreatureScript
{
public:
    boss_dreadscale() : CreatureScript("boss_dreadscale") { }

    struct boss_dreadscaleAI : public boss_jormungarAI
    {
        boss_dreadscaleAI(Creature* pCreature) : boss_jormungarAI(pCreature) { }

        void Reset()
        {
            boss_jormungarAI::Reset();
            biteSpell = SPELL_BURNING_BITE;
            spewSpell = SPELL_MOLTEN_SPEW;
            spitSpell = SPELL_FIRE_SPIT;
            spraySpell = SPELL_BURNING_SPRAY;
            modelStationary = MODEL_DREADSCALE_STATIONARY;
            modelMobile = MODEL_DREADSCALE_MOBILE;
            otherWormEntry = NPC_ACIDMAW;

            submergeTimer = 45 * IN_MILLISECONDS;
            stage = 0;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_dreadscaleAI(pCreature);
    }
};


class mob_slime_pool : public CreatureScript
{
public:
    mob_slime_pool() : CreatureScript("mob_slime_pool") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_slime_poolAI(pCreature);
    }

    struct mob_slime_poolAI : public ScriptedAI
    {
        mob_slime_poolAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
        }

        bool casted;
        void Reset()
        {
            casted = false;
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (!casted)
            {
                casted = true;
                DoCast(me, SPELL_SLIME_POOL_EFFECT);
            }
        }
    };

};

class boss_icehowl : public CreatureScript
{
public:
    boss_icehowl() : CreatureScript("boss_icehowl") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_icehowlAI(pCreature);
    }

    struct boss_icehowlAI : public ScriptedAI
    {
        boss_icehowlAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 m_uiFerociousButtTimer;
        uint32 m_uiArticBreathTimer;
        uint32 m_uiWhirlTimer;
        uint32 m_uiMassiveCrashTimer;
        uint32 m_uiTrampleTimer;
        float  m_fTrampleTargetX, m_fTrampleTargetY, m_fTrampleTargetZ;
        uint64 m_uiTrampleTargetGUID;
        bool   m_bMovementStarted;
        bool   m_bMovementFinish;
        bool   m_bTrampleCasted;
        uint8  m_uiStage;
        Unit*  pTarget;

        void Reset()
        {
            m_uiFerociousButtTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            m_uiArticBreathTimer = urand(25*IN_MILLISECONDS, 40*IN_MILLISECONDS);
            m_uiWhirlTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            m_uiMassiveCrashTimer = 30*IN_MILLISECONDS;
            m_uiTrampleTimer = IN_MILLISECONDS;
            m_bMovementStarted = false;
            m_bMovementFinish = false;
            m_bTrampleCasted = false;
            m_uiTrampleTargetGUID = 0;
            m_fTrampleTargetX = 0;
            m_fTrampleTargetY = 0;
            m_fTrampleTargetZ = 0;
            m_uiStage = 0;
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_DONE);
        }

        void MovementInform(uint32 uiType, uint32 uiId)
        {
            if (uiType != POINT_MOTION_TYPE) return;

            switch (uiId)
            {
                case 0: // JUMP!? Fuck! THAT'S BEEZARR! Would someone PLEASE make MotionMaster->Move* work better?
                    if (me->GetDistance2d(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY()) < 6.0f)
                    {
                        // Middle of the room
                        m_uiStage = 1;
                    }
                    else
                    {
                        // Landed from Hop backwards (start trample)
                        if (Unit::GetPlayer(*me, m_uiTrampleTargetGUID))
                        {
                            m_uiStage = 4;
                        } else m_uiStage = 6;
                    }
                    break;
                case 1: // Finish trample
                    m_bMovementFinish = true;
                    break;
            }
        }

        void JustReachedHome()
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
            me->DespawnOrUnsummon();
        }

        void KilledUnit(Unit *pWho)
        {
            if (pWho->GetTypeId() == TYPEID_PLAYER)
            {
                if (m_pInstance)
                    m_pInstance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
            }
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_IN_PROGRESS);
            me->SetInCombatWithZone();
        }

        void SpellHitTarget(Unit* target, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_TRAMPLE && target->GetTypeId() == TYPEID_PLAYER)
            {
                if (!m_bTrampleCasted)
                {
                    DoCast(me, SPELL_FROTHING_RAGE, true);
                    m_bTrampleCasted = true;
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            switch (m_uiStage)
            {
                case 0:
                    if (m_uiFerociousButtTimer <= uiDiff)
                    {
                        DoCastVictim(SPELL_FEROCIOUS_BUTT);
                        m_uiFerociousButtTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                    } else m_uiFerociousButtTimer -= uiDiff;

                    if (m_uiArticBreathTimer <= uiDiff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_ARCTIC_BREATH);
                        m_uiArticBreathTimer = urand(25*IN_MILLISECONDS, 40*IN_MILLISECONDS);
                    } else m_uiArticBreathTimer -= uiDiff;

                    if (m_uiWhirlTimer <= uiDiff)
                    {
                        DoCastAOE(SPELL_WHIRL);
                        m_uiWhirlTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                    } else m_uiWhirlTimer -= uiDiff;

                    if (m_uiMassiveCrashTimer <= uiDiff)
                    {
                        me->GetMotionMaster()->MoveJump(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 10.0f, 20.0f); // 1: Middle of the room
                        m_uiStage = 7; //Invalid (Do nothing more than move)
                        m_uiMassiveCrashTimer = 30*IN_MILLISECONDS;
                    } else m_uiMassiveCrashTimer -= uiDiff;

                    DoMeleeAttackIfReady();
                    break;
                case 1:
                    DoCastAOE(SPELL_MASSIVE_CRASH);
                    m_uiStage = 2;
                    break;
                case 2:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        m_uiTrampleTargetGUID = pTarget->GetGUID();
                        me->SetUInt64Value(UNIT_FIELD_TARGET, m_uiTrampleTargetGUID);
                        DoScriptText(SAY_TRAMPLE_STARE, me, pTarget);
                        m_bTrampleCasted = false;
                        SetCombatMovement(false);
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        m_uiTrampleTimer = 4*IN_MILLISECONDS;
                        m_uiStage = 3;
                    } else m_uiStage = 6;
                    break;
                case 3:
                    if (m_uiTrampleTimer <= uiDiff)
                    {
                        if (Unit* pTarget = Unit::GetPlayer(*me, m_uiTrampleTargetGUID))
                        {
                            m_bTrampleCasted = false;
                            m_bMovementStarted = true;
                            m_fTrampleTargetX = pTarget->GetPositionX();
                            m_fTrampleTargetY = pTarget->GetPositionY();
                            m_fTrampleTargetZ = pTarget->GetPositionZ();
                            me->GetMotionMaster()->MoveJump(2*me->GetPositionX()-m_fTrampleTargetX,
                                2*me->GetPositionY()-m_fTrampleTargetY,
                                me->GetPositionZ(),
                                10.0f, 20.0f); // 2: Hop Backwards
                            m_uiStage = 7; //Invalid (Do nothing more than move)
                        } else m_uiStage = 6;
                    } else m_uiTrampleTimer -= uiDiff;
                    break;
                case 4:
                    DoScriptText(SAY_TRAMPLE_START, me);
                    me->GetMotionMaster()->MoveCharge(m_fTrampleTargetX, m_fTrampleTargetY, m_fTrampleTargetZ+2, 42, 1);
                    me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                    m_uiStage = 5;
                    break;
                case 5:
                    if (m_bMovementFinish)
                    {
                        if (m_uiTrampleTimer <= uiDiff) DoCastAOE(SPELL_TRAMPLE);
                        m_bMovementFinish = false;
                        m_uiStage = 6;
                        return;
                    }
                    if (m_uiTrampleTimer <= uiDiff)
                    {
                        Map::PlayerList const &lPlayers = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                        {
                            if (Unit* pPlayer = itr->getSource())
                                if (pPlayer->isAlive() && pPlayer->IsWithinDistInMap(me, 6.0f))
                                {
                                    DoCastAOE(SPELL_TRAMPLE);
                                    m_uiTrampleTimer = IN_MILLISECONDS;
                                    break;
                                }
                        }
                    } else m_uiTrampleTimer -= uiDiff;
                    break;
                case 6:
                    if (!m_bTrampleCasted)
                    {
                        DoCast(me, SPELL_STAGGERED_DAZE);
                        DoScriptText(SAY_TRAMPLE_FAIL, me);
                    }
                    m_bMovementStarted = false;
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    SetCombatMovement(true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    m_uiStage = 0;
                    break;
            }
        }
    };

};


void AddSC_boss_northrend_beasts()
{
    new boss_gormok();
    new mob_snobold_vassal();
    new boss_acidmaw();
    new boss_dreadscale();
    new mob_slime_pool();
    new boss_icehowl();
}
