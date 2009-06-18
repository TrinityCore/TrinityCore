/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA02111-1307USA
 */

/* ScriptData
SDName: Boss_Lady_Vashj
SD%Complete: 60
SDComment: Code cleanup needed. This script needs further adjustments.
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"
#include "../../../creature/simple_ai.h"
#include "Item.h"
#include "Spell.h"

enum
{
    SAY_INTRO                   = -1548042,
    SAY_AGGRO1                  = -1548043,
    SAY_AGGRO2                  = -1548044,
    SAY_AGGRO3                  = -1548045,
    SAY_AGGRO4                  = -1548046,
    SAY_PHASE1                  = -1548047,
    SAY_PHASE2                  = -1548048,
    SAY_PHASE3                  = -1548049,
    SAY_BOWSHOT1                = -1548050,
    SAY_BOWSHOT2                = -1548051,
    SAY_SLAY1                   = -1548052,
    SAY_SLAY2                   = -1548053,
    SAY_SLAY3                   = -1548054,
    SAY_DEATH                   = -1548055,

    POINT_MOVE_CENTER           = 0,

    PHASE_1                     = 1,
    PHASE_2                     = 2,
    PHASE_3                     = 3,

    MAX_SHIELD_GEN              = 4,

    SPELL_MULTI_SHOT            = 38310,
    SPELL_SHOCK_BLAST           = 38509,
    SPELL_ENTANGLE              = 38316,
    SPELL_STATIC_CHARGE_TRIGGER = 38280,
    SPELL_FORKED_LIGHTNING      = 38145,
    SPELL_SHOOT                 = 38295,

    SPELL_TOXIC_SPORES          = 38575,
    SPELL_MAGIC_BARRIER         = 38112,
    SPELL_SURGE                 = 38044,

    //tainted elemental
    SPELL_POISON_BOLT           = 38253,
    SPELL_SUMMON_TAINTED        = 38139,

    NPC_ENCHANTED_ELEMENTAL     = 21958,
    NPC_TAINTED_ELEMENTAL       = 22009,
    NPC_COILFANG_STRIDER        = 22056,
    NPC_COILFANG_ELITE          = 22055,
    NPC_TOXIC_SPOREBAT          = 22140,

    NPC_SHIELD_GENERATOR        = 19870
};

const float afMiddlePos[3]   = {30.134f, -923.65f, 42.9f};

const float afSporebatPos[4] = {30.977156f, -925.297761f, 77.176567f, 5.223932f};

const float afElementPos[8][4] =
{
    {8.3f  , -835.3f , 21.9f, 5.0f},
    {53.4f , -835.3f , 21.9f, 4.5f},
    {96.0f , -861.9f , 21.8f, 4.0f},
    {96.0f , -986.4f , 21.4f, 2.5f},
    {54.4f , -1010.6f, 22.0f, 1.8f},
    {9.8f  , -1012.0f, 21.7f, 1.4f},
    {-35.0f, -987.6f , 21.5f, 0.8f},
    {-58.9f, -901.6f , 21.5f, 6.0f}
};

const float afCoilfangElitePos[3][4] =
{
    {28.84f    , -923.28f    , 42.9f     , 6.0f     },
    {31.183281f, -953.502625f, 41.523602f, 1.640957f},
    {58.895180f, -923.124268f, 41.545307f, 3.152848f}
};

const float afCoilfangStriderPos[3][4] =
{
    {66.427f, -948.778f, 41.262245f, 2.584f},
    {7.513f , -959.538f, 41.300422f, 1.0346f},
    {-12.843f, -907.798f, 41.239620f, 6.087f}
};

const float afShieldGeneratorChannelPos[4][4] =
{
    {49.626f, -902.181f, 41.54f, 3.956f},
    {10.988f, -901.616f, 41.54f, 5.437f},
    {10.385f, -944.036f, 41.54f, 0.779f},
    {49.312f, -943.398f, 41.54f, 2.401f}
};

//Lady Vashj AI
struct TRINITY_DLL_DECL boss_lady_vashjAI : public ScriptedAI
{
    boss_lady_vashjAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());

        memset(&m_auiShieldGeneratorChannel, 0, sizeof(m_auiShieldGeneratorChannel));
    }

    ScriptedInstance *m_pInstance;                          // the instance

    uint64 m_auiShieldGeneratorChannel[MAX_SHIELD_GEN];

    // timers
    uint32 m_uiShockBlast_Timer;
    uint32 m_uiEntangle_Timer;
    uint32 m_uiStaticCharge_Timer;
    uint32 m_uiForkedLightning_Timer;
    uint32 m_uiCheck_Timer;
    uint32 m_uiEnchantedElemental_Timer;
    uint32 m_uiTaintedElemental_Timer;
    uint32 m_uiCoilfangElite_Timer;
    uint32 m_uiCoilfangStrider_Timer;
    uint32 m_uiSummonSporebat_Timer;
    uint32 m_uiSummonSporebat_StaticTimer;
    uint8  m_uiEnchantedElemental_Pos;
    uint8  m_uiPhase;

    bool m_bEntangle;

    void Reset()
    {
        SetCombatMovement(true);

        m_uiShockBlast_Timer           = 1+rand()%60000;
        m_uiEntangle_Timer             = 30000;
        m_uiStaticCharge_Timer         = 10000+rand()%15000;
        m_uiCheck_Timer                = 1000;

        m_uiForkedLightning_Timer      = 43000+rand()%6000;
        m_uiEnchantedElemental_Timer   = 10000;
        m_uiTaintedElemental_Timer     = 50000;
        m_uiCoilfangElite_Timer        = 45000;
        m_uiCoilfangStrider_Timer      = 60000;

        m_uiSummonSporebat_Timer       = 10000;
        m_uiSummonSporebat_StaticTimer = 30000;
        m_uiEnchantedElemental_Pos     = 0;
        m_uiPhase                      = PHASE_1;

        m_bEntangle = false;

        RemoveAllShieldGenerators();

        if (m_pInstance)
            m_pInstance->SetData(DATA_LADYVASHJEVENT, NOT_STARTED);
    }

    void RemoveAllShieldGenerators()
    {
        for(uint8 i = 0; i < MAX_SHIELD_GEN; i++)
        {
            if (Unit* pTemp = Unit::GetUnit(*m_creature,m_auiShieldGeneratorChannel[i]))
            {
                if (pTemp->isAlive())
                    pTemp->setDeathState(JUST_DIED);

                m_auiShieldGeneratorChannel[i] = 0;
            }
        }
    }

    void Aggro(Unit* pWho)
    {
        switch(rand()%4)
        {
            case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
            case 3: DoScriptText(SAY_AGGRO4, m_creature); break;
        }

        if (m_pInstance)
            m_pInstance->SetData(DATA_LADYVASHJEVENT, IN_PROGRESS);
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == POINT_MOVE_CENTER)
        {
            m_creature->RemoveAllAuras();

            for(uint8 i = 0; i < MAX_SHIELD_GEN; i++)
            {
                if (Creature* pCreature = m_creature->SummonCreature(NPC_SHIELD_GENERATOR, afShieldGeneratorChannelPos[i][0],  afShieldGeneratorChannelPos[i][1],  afShieldGeneratorChannelPos[i][2],  afShieldGeneratorChannelPos[i][3], TEMPSUMMON_CORPSE_DESPAWN, 0))
                    m_auiShieldGeneratorChannel[i] = pCreature->GetGUID();
            }
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        uint32 uiEntry = pSummoned->GetEntry();

        if (uiEntry == NPC_COILFANG_STRIDER || uiEntry == NPC_COILFANG_ELITE || uiEntry == NPC_TOXIC_SPOREBAT)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }

        if (uiEntry == NPC_SHIELD_GENERATOR)
        {
            //we should really expect database to have this set already
            if (!pSummoned->HasFlag(UNIT_FIELD_FLAGS, (UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE)))
            {
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            pSummoned->CastSpell(m_creature,SPELL_MAGIC_BARRIER,true);
        }
    }

    //called when any summoned (by m_creature) despawns
    void SummonedCreatureDespawn(Creature* pDespawned)
    {
        if (pDespawned->GetEntry() == NPC_TAINTED_ELEMENTAL)
        {
            if (m_uiTaintedElemental_Timer > 50000)
                m_uiTaintedElemental_Timer = 50000;
        }
    }

    void KilledUnit(Unit* pVictim)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
            case 2: DoScriptText(SAY_SLAY3, m_creature); break;
        }
    }

    void JustDied(Unit* pVictim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(DATA_LADYVASHJEVENT, DONE);
    }

    void CastShootOrMultishot()
    {
        //Shoot: Used in m_uiPhases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits her target for 4097-5543 Physical damage.
        //Multishot: Used in m_uiPhases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits 1 person and 4 people around him for 6475-7525 physical damage.
        DoCast(m_creature->getVictim(), urand(0,1) ? SPELL_SHOOT : SPELL_MULTI_SHOT);

        if (rand()%3)
            DoScriptText(urand(0,1) ? SAY_BOWSHOT1 : SAY_BOWSHOT2, m_creature);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (m_uiPhase == PHASE_1 || m_uiPhase == PHASE_3)
        {
            //m_uiShockBlast_Timer
            if (m_uiShockBlast_Timer < uiDiff)
            {
                //Randomly used in m_uiPhases 1 and 3 on Vashj's target, it's a Shock spell doing 8325-9675 nature damage and stunning the target for 5 seconds, during which she will not attack her target but switch to the next person on the aggro list.
                DoCast(m_creature->getVictim(), SPELL_SHOCK_BLAST);

                m_uiShockBlast_Timer = 1000+rand()%14000;   //random cooldown
            }else m_uiShockBlast_Timer -= uiDiff;

            //m_uiStaticCharge_Timer
            if (m_uiStaticCharge_Timer < uiDiff)
            {
                //Used on random people (only 1 person at any given time) in m_uiPhases 1 and 3, it's a debuff doing 2775 to 3225 Nature damage to the target and everybody in about 5 yards around it, every 1 seconds for 30 seconds. It can be removed by Cloak of Shadows, Iceblock, Divine Shield, etc, but not by Cleanse or Dispel Magic.
                Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

                //cast Static Charge every 2 seconds for 20 seconds
                if (pTarget && !pTarget->HasAura(SPELL_STATIC_CHARGE_TRIGGER))
                    DoCast(pTarget, SPELL_STATIC_CHARGE_TRIGGER);

                m_uiStaticCharge_Timer = 10000+rand()%20000;
            }else m_uiStaticCharge_Timer -= uiDiff;

            //m_uiEntangle_Timer
            if (m_uiEntangle_Timer < uiDiff)
            {
                if (!m_bEntangle)
                {
                    //Used in m_uiPhases 1 and 3, it casts Entangling Roots on everybody in a 15 yard radius of Vashj, immobilzing them for 10 seconds and dealing 500 damage every 2 seconds. It's not a magic effect so it cannot be dispelled, but is removed by various buffs such as Cloak of Shadows or Blessing of Freedom.
                    DoCast(m_creature->getVictim(), SPELL_ENTANGLE);
                    m_bEntangle = true;
                    m_uiEntangle_Timer = 10000;
                }
                else
                {
                    CastShootOrMultishot();
                    m_bEntangle = false;
                    m_uiEntangle_Timer = 20000+rand()%5000;
                }
            }else m_uiEntangle_Timer -= uiDiff;

            //m_uiPhase 1
            if (m_uiPhase == PHASE_1)
            {
                //m_uiPhase 2 begins when Vashj hits 70%. She will run to the middle of her platform and surround herself in a shield making her invulerable.
                if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 70)
                {
                    DoScriptText(SAY_PHASE2, m_creature);

                    if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
                    {
                        //set false, so MoveChase is not triggered in AttackStart
                        SetCombatMovement(false);

                        m_creature->GetMotionMaster()->MovementExpired();
                        m_creature->GetMotionMaster()->MovePoint(POINT_MOVE_CENTER, afMiddlePos[0], afMiddlePos[1], afMiddlePos[2]);
                    }

                    m_uiPhase = PHASE_2;
                    return;
                }
            }
            //m_uiPhase PHASE_3
            else
            {
                //m_uiSummonSporebat_Timer
                if (m_uiSummonSporebat_Timer < uiDiff)
                {
                    m_creature->SummonCreature(NPC_TOXIC_SPOREBAT,
                        afSporebatPos[0], afSporebatPos[1], afSporebatPos[2], afSporebatPos[3],
                        TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);

                    //summon sporebats faster and faster
                    if (m_uiSummonSporebat_StaticTimer > 1000)
                        m_uiSummonSporebat_StaticTimer -= 1000;

                    m_uiSummonSporebat_Timer = m_uiSummonSporebat_StaticTimer;
                }else m_uiSummonSporebat_Timer -= uiDiff;
            }

            //Melee attack
            DoMeleeAttackIfReady();

            //m_uiCheck_Timer - used to check if somebody is in melee range
            if (m_uiCheck_Timer < uiDiff)
            {
                bool bInMeleeRange = false;
                std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
                for(std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    Unit* pTarget = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());

                    //if in melee range
                    if (pTarget && pTarget->IsWithinDistInMap(m_creature, ATTACK_DISTANCE))
                    {
                        bInMeleeRange = true;
                        break;
                    }
                }

                //if nobody is in melee range
                if (!bInMeleeRange)
                    CastShootOrMultishot();

                m_uiCheck_Timer = 1500;
            }else m_uiCheck_Timer -= uiDiff;
        }
        //m_uiPhase PHASE_2
        else
        {
            //m_uiForkedLightning_Timer
            if (m_uiForkedLightning_Timer < uiDiff)
            {
                //Used constantly in m_uiPhase 2, it shoots out completely randomly targeted bolts of lightning which hit everybody in a roughtly 60 degree cone in front of Vashj for 2313-2687 nature damage.
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if (!pTarget)
                    pTarget = m_creature->getVictim();

                DoCast(pTarget, SPELL_FORKED_LIGHTNING);

                m_uiForkedLightning_Timer = 3000+rand()%6000;
            }else m_uiForkedLightning_Timer -= uiDiff;

            //NPC_ENCHANTED_ELEMENTAL
            if (m_uiEnchantedElemental_Timer < uiDiff)
            {
                if (Creature* pElemental = m_creature->SummonCreature(NPC_ENCHANTED_ELEMENTAL, afElementPos[m_uiEnchantedElemental_Pos][0], afElementPos[m_uiEnchantedElemental_Pos][1], afElementPos[m_uiEnchantedElemental_Pos][2], afElementPos[m_uiEnchantedElemental_Pos][3], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
                    pElemental->GetMotionMaster()->MoveFollow(m_creature, 0.0f, 0.0f);

                if (m_uiEnchantedElemental_Pos == 7)
                    m_uiEnchantedElemental_Pos = 0;
                else
                    ++m_uiEnchantedElemental_Pos;

                m_uiEnchantedElemental_Timer = 10000+rand()%5000;
            }else m_uiEnchantedElemental_Timer -= uiDiff;

            //NPC_TAINTED_ELEMENTAL
            if (m_uiTaintedElemental_Timer < uiDiff)
            {
                uint32 uiPos = urand(0,7);

                m_creature->SummonCreature(NPC_TAINTED_ELEMENTAL,
                    afElementPos[uiPos][0], afElementPos[uiPos][1], afElementPos[uiPos][2], afElementPos[uiPos][3],
                    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 15000);

                m_uiTaintedElemental_Timer = 120000;
            }else m_uiTaintedElemental_Timer -= uiDiff;

            //NPC_COILFANG_ELITE
            if (m_uiCoilfangElite_Timer < uiDiff)
            {
                uint32 uiPos = urand(0,2);

                m_creature->SummonCreature(NPC_COILFANG_ELITE,
                    afCoilfangElitePos[uiPos][0], afCoilfangElitePos[uiPos][1], afCoilfangElitePos[uiPos][2], afCoilfangElitePos[uiPos][3],
                    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 45000);

                //wowwiki says 50 seconds, bosskillers says 45
                m_uiCoilfangElite_Timer = 45000+rand()%5000;
            }else m_uiCoilfangElite_Timer -= uiDiff;

            //NPC_COILFANG_STRIDER
            if (m_uiCoilfangStrider_Timer < uiDiff)
            {
                uint32 uiPos = urand(0,2);

                m_creature->SummonCreature(NPC_COILFANG_STRIDER,
                    afCoilfangStriderPos[uiPos][0], afCoilfangStriderPos[uiPos][1], afCoilfangStriderPos[uiPos][2], afCoilfangStriderPos[uiPos][3],
                    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);

                //wowwiki says 60 seconds, bosskillers says 60-70
                m_uiCoilfangStrider_Timer = 60000+rand()%10000;
            }else m_uiCoilfangStrider_Timer -= uiDiff;

            //m_uiCheck_Timer
            if (m_uiCheck_Timer < uiDiff)
            {
                //Start m_uiPhase 3
                if (m_pInstance && m_pInstance->GetData(DATA_CANSTARTPHASE3))
                {
                    DoScriptText(SAY_PHASE3, m_creature);

                    //set life 50%, not correct. Must remove 5% for each generator switched off
                    m_creature->SetHealth(m_creature->GetMaxHealth()/2);

                    //m_creature->RemoveAurasDueToSpell(SPELL_MAGIC_BARRIER);

                    SetCombatMovement(true);

                    //return to chase top aggro
                    if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());

                    m_uiPhase = PHASE_3;
                }
                m_uiCheck_Timer = 1000;
            }else m_uiCheck_Timer -= uiDiff;
        }
    }
};

//Enchanted Elemental
//If one of them reaches Vashj he will increase her damage done by 5%.
struct TRINITY_DLL_DECL mob_enchanted_elementalAI : public ScriptedAI
{
    mob_enchanted_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        SetCombatMovement(false);
    }

    ScriptedInstance *m_pInstance;                          // the instance

    void Reset() { }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (m_pInstance)
        {
            if (Unit* pVashj = Unit::GetUnit((*m_creature), m_pInstance->GetData64(DATA_LADYVASHJ)))
            {
                if (pVashj->IsWithinDistInMap(m_creature, ATTACK_DISTANCE))
                {
                    //increase lady vashj damage
                    if (pVashj->isAlive() && pVashj->isInCombat())
                        m_creature->CastSpell(pVashj, SPELL_SURGE, false, 0, 0, pVashj->GetGUID());
                    else
                        m_creature->setDeathState(JUST_DIED);
                }
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) { }
};

//Tainted Elemental
//This mob has 7,900 life, doesn't move, and shoots Poison Bolts at one person anywhere in the area, doing 3,000 nature damage and placing a posion doing 2,000 damage every 2 seconds. He will switch targets often, or sometimes just hang on a single player, but there is nothing you can do about it except heal the damage and kill the Tainted Elemental
struct TRINITY_DLL_DECL mob_tainted_elementalAI : public ScriptedAI
{
    mob_tainted_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        SetCombatMovement(false);
    }

    ScriptedInstance* m_pInstance;                          // the instance

    // timers
    uint32 m_uiPoisonBolt_Timer;

    void Reset()
    {
        m_uiPoisonBolt_Timer = 5000+rand()%5000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        //m_uiPoisonBolt_Timer
        if (m_uiPoisonBolt_Timer < uiDiff)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if (pTarget && pTarget->IsWithinDistInMap(m_creature, 30.0f))
                DoCast(pTarget, SPELL_POISON_BOLT);

            m_uiPoisonBolt_Timer = 5000+rand()%5000;
        }else m_uiPoisonBolt_Timer -= uiDiff;
    }
};

//Toxic Sporebat
//Toxic Spores: Used in m_uiPhase 3 by the Spore Bats, it creates a contaminated green patch of ground, dealing about 2775-3225 nature damage every second to anyone who stands in it.
struct TRINITY_DLL_DECL mob_toxic_sporebatAI : public ScriptedAI
{
    mob_toxic_sporebatAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiToxicSpore_Timer;
    uint32 m_uiCheck_Timer;

    void Reset()
    {
        m_creature->setFaction(14);
        m_uiToxicSpore_Timer = 5000;
        m_uiCheck_Timer = 1000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //m_uiToxicSpore_Timer
        if (m_uiToxicSpore_Timer < uiDiff)
        {
            //The Spores will hit you anywhere in the instance: underwater, at the elevator, at the entrance, wherever.
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, SPELL_TOXIC_SPORES);

            m_uiToxicSpore_Timer = 20000+rand()%5000;
        }else m_uiToxicSpore_Timer -= uiDiff;

        //m_uiCheck_Timer
        if (m_uiCheck_Timer < uiDiff)
        {
            if (m_pInstance)
            {
                //check if vashj is death
                Unit* pVashj = Unit::GetUnit((*m_creature), m_pInstance->GetData64(DATA_LADYVASHJ));
                if (!pVashj || !pVashj->isAlive())
                {
                    //remove
                    m_creature->setDeathState(DEAD);
                    m_creature->RemoveCorpse();
                    m_creature->setFaction(35);
                }
            }

            m_uiCheck_Timer = 1000;
        }else m_uiCheck_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

//Coilfang Elite
//It's an elite Naga mob with 170,000 HP. It does about 5000 damage on plate, and has a nasty cleave hitting for about 7500 damage
CreatureAI* GetAI_mob_coilfang_elite(Creature* pCreature)
{
    SimpleAI* pAI = new SimpleAI (pCreature);

    pAI->Spell[0].Enabled = true;
    pAI->Spell[0].Spell_Id = 31345;                          //Cleave
    pAI->Spell[0].Cooldown = 15000;
    pAI->Spell[0].CooldownRandomAddition = 5000;
    pAI->Spell[0].First_Cast = 5000;
    pAI->Spell[0].Cast_Target_Type = CAST_HOSTILE_RANDOM;

    pAI->EnterEvadeMode();

    return pAI;
}

//Coilfang Strifer
//It hits plate for about 8000 damage, has a Mind Blast spell doing about 3000 shadow damage, and a Psychic Scream Aura, which fears everybody in a 8 yard range of it every 2-3 seconds , for 5 seconds and increasing their movement speed by 150% during the fear.
CreatureAI* GetAI_mob_coilfang_strider(Creature* pCreature)
{
    SimpleAI* pAI = new SimpleAI (pCreature);

    pAI->Spell[0].Enabled = true;
    pAI->Spell[0].Spell_Id = 41374;                          //Mind Blast
    pAI->Spell[0].Cooldown = 30000;
    pAI->Spell[0].CooldownRandomAddition = 10000;
    pAI->Spell[0].First_Cast = 8000;
    pAI->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    //Scream aura not implemented

    pAI->EnterEvadeMode();

    return pAI;
}

//can probably be removed
struct TRINITY_DLL_DECL mob_shield_generator_channelAI : public ScriptedAI
{
    mob_shield_generator_channelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
    }

    ScriptedInstance *m_pInstance;                          // the instance

    void Reset() { }

    void MoveInLineOfSight(Unit* pWho) { }
};

//this is wrong, alternative script needed
bool ItemUse_item_tainted_core(Player* pPlayer, Item* pItem, SpellCastTargets const& sctTargets)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)pPlayer->GetInstanceData());

    if(!pInstance)
    {
        pPlayer->GetSession()->SendNotification("ERROR: Instance script not initialized. Notify your administrator.");
        error_log("ERROR: Lady Vashj Tainted Core: Instance Script Not Initialized");
        return true;
    }

    Creature* pVashj = (Creature*)(Unit::GetUnit((*pPlayer), pInstance->GetData64(DATA_LADYVASHJ)));
    if(pVashj && ((boss_lady_vashjAI*)pVashj->AI())->m_uiPhase == 2)
    {
        if(sctTargets.getGOTarget() && sctTargets.getGOTarget()->GetTypeId()==TYPEID_GAMEOBJECT)
        {
            uint32 uiIdentifier;
            uint8 uiChannelIdentifier;
            switch(sctTargets.getGOTarget()->GetEntry())
            {
                case 185052:
                    uiIdentifier = DATA_SHIELDGENERATOR1;
                    uiChannelIdentifier = 0;
                    break;
                case 185053:
                    uiIdentifier = DATA_SHIELDGENERATOR2;
                    uiChannelIdentifier = 1;
                    break;
                case 185051:
                    uiIdentifier = DATA_SHIELDGENERATOR3;
                    uiChannelIdentifier = 2;
                    break;
                case 185054:
                    uiIdentifier = DATA_SHIELDGENERATOR4;
                    uiChannelIdentifier = 3;
                    break;
                default:
                    return true;
                    break;
            }

            if(pInstance->GetData(uiIdentifier))
            {
                pPlayer->GetSession()->SendNotification("Already deactivated");
                return true;
            }

            //get and remove channel
            if(Unit* pChannel = Unit::GetUnit((*pVashj), ((boss_lady_vashjAI*)pVashj->AI())->m_auiShieldGeneratorChannel[uiChannelIdentifier]))
                pChannel->setDeathState(JUST_DIED);         //calls Unsummon()

            pInstance->SetData(uiIdentifier, 1);

            //remove this item
            pPlayer->DestroyItemCount(31088, 1, true);
        }
    }
    return true;
}

CreatureAI* GetAI_boss_lady_vashj(Creature* pCreature)
{
    return new boss_lady_vashjAI(pCreature);
}

CreatureAI* GetAI_mob_enchanted_elemental(Creature* pCreature)
{
    return new mob_enchanted_elementalAI(pCreature);
}

CreatureAI* GetAI_mob_tainted_elemental(Creature* pCreature)
{
    return new mob_tainted_elementalAI(pCreature);
}

CreatureAI* GetAI_mob_toxic_sporebat(Creature* pCreature)
{
    return new mob_toxic_sporebatAI(pCreature);
}

CreatureAI* GetAI_mob_shield_generator_channel(Creature* pCreature)
{
    return new mob_shield_generator_channelAI(pCreature);
}

void AddSC_boss_lady_vashj()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_lady_vashj";
    newscript->GetAI = &GetAI_boss_lady_vashj;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_enchanted_elemental";
    newscript->GetAI = &GetAI_mob_enchanted_elemental;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_tainted_elemental";
    newscript->GetAI = &GetAI_mob_tainted_elemental;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_toxic_sporebat";
    newscript->GetAI = &GetAI_mob_toxic_sporebat;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_coilfang_elite";
    newscript->GetAI = &GetAI_mob_coilfang_elite;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_coilfang_strider";
    newscript->GetAI = &GetAI_mob_coilfang_strider;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_shield_generator_channel";
    newscript->GetAI = &GetAI_mob_shield_generator_channel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "item_tainted_core";
    newscript->pItemUse = &ItemUse_item_tainted_core;
    newscript->RegisterSelf();
}
