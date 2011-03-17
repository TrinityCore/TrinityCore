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
SDName: Argent Challenge Encounter.
SD%Complete: 90 %
SDComment: AI from bosses need more improvements. Need AI for lightwell
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum eSpells
{
    //Eadric
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_SMITE                 = 66536,
    SPELL_SMITE_H               = 67674,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_HOLY_FIRE_H           = 67676,
    SPELL_RENEW                 = 66537,
    SPELL_RENEW_H               = 67675,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677, 

    //Monk
    SPELL_DIVINE_SHIELD         = 67251, 
    SPELL_FINAL_MEDITATION      = 67255,
    SPELL_FLURRY_OF_BLOWS       = 67233, 
    SPELL_PUMMEL                = 67235,

    //Priestess
    SPELL_HOLY_SMITE_H          = 67289,
    SPELL_MIND_CONTROLL         = 67229, //not supported yet
    SPELL_DOT_PAIN_H            = 34942,
    SPELL_HOLY_SMITE            = 36176,
    SPELL_DOT_PAIN              = 34941,
    SPELL_FOUNTAIN_OF_LIGHT     = 67194, //partially not work

    //Lightwielder
    SPELL_BLAZING_LIGHT_H       = 67290,
    SPELL_BLAZING_LIGHT         = 67247,
    SPELL_UNBALANCING_STRIKE    = 67237,
    SPELL_CLEAVE                = 15284
};

enum Misc
{
    ACHIEV_FACEROLLER           = 3803,
    ACHIEV_CONF                 = 3802
};

enum eEnums
{
    SAY_MEM_DIE                             = -1999968,
    SAY_DEATH_P                             = -1999967,
    SAY_INTRO_P2                            = -1999966,
    SAY_INTRO_P1                            = -1999965,
    SAY_INTRO_E                             = -1999964,
    SAY_HAMMER_E                            = -1999963,
    SAY_DEATH_E                             = -1999962,
    SAY_START_E                             = -1999961,
    SAY_KILL1_P                             = -1999960,
    SAY_KILL2_P                             = -1999959,
    SAY_KILL1_E                             = -1999958,
    SAY_KILL2_E                             = -1999957,
    SAY_START_10                            = -1999956,
    SAY_START_9                             = -1999955,
    SAY_START_8                             = -1999941,
    SAY_START_P                             = -1999955,
    SAY_START_7                             = -1999954,
    SAY_START_6                             = -1999951
};

class boss_eadric : public CreatureScript
{
public:
    boss_eadric() : CreatureScript("boss_eadric") { }
    struct boss_eadricAI : public ScriptedAI
    {
        boss_eadricAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            pCreature->SetReactState(REACT_PASSIVE);
            pCreature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint32 uiVenganceTimer;
        uint32 uiRadianceTimer;
        uint32 uiHammerJusticeTimer;
        uint32 uiResetTimer;

        bool bDone;

        void Reset()
        {
            uiVenganceTimer = 10000;
            uiRadianceTimer = 16000;
            uiHammerJusticeTimer = 25000;
            uiResetTimer = 5000;

            bDone = false;
        }

        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                bDone = true;
                DoScriptText(SAY_DEATH_E, me);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                    pInstance->HandleGameObject(pGO->GetGUID(),true);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                    pInstance->HandleGameObject(pGO->GetGUID(),true);
            }
        }

        void EnterCombat(Unit* pWho)
        {
            DoScriptText(SAY_START_E, me);           
        }

        void KilledUnit(Unit* pVictim)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL1_E : SAY_KILL2_E, me);
            if (pInstance)
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_E,IN_PROGRESS);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0,746.87f,665.87f,411.75f);
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                me->DisappearAndDie();
                bDone = false;
                if (IsHeroic())
                    pInstance->DoCompleteAchievement(ACHIEV_FACEROLLER);
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            if (uiHammerJusticeTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);

                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (pTarget && pTarget->isAlive())
                    {
                        DoCast(pTarget, SPELL_HAMMER_JUSTICE);
                        DoCast(pTarget, SPELL_HAMMER_RIGHTEOUS);
                    }
                }
                uiHammerJusticeTimer = 25000;
            } else uiHammerJusticeTimer -= uiDiff;

            if (uiVenganceTimer <= uiDiff)
            {
                DoCast(me,SPELL_VENGEANCE);

                uiVenganceTimer = 10000;
            } else uiVenganceTimer -= uiDiff;

            if (uiRadianceTimer <= uiDiff)
            {
                DoCastAOE(SPELL_RADIANCE);

                uiRadianceTimer = 16000;
            } else uiRadianceTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_eadricAI(pCreature);
    }
};

class boss_paletress : public CreatureScript
{
public:
    boss_paletress() : CreatureScript("boss_paletress") { }

    struct boss_paletressAI : public ScriptedAI
    {
        boss_paletressAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();

            MemoryGUID = 0;
            pCreature->SetReactState(REACT_PASSIVE);
            pCreature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            pCreature->RestoreFaction();
        }

        InstanceScript* pInstance;

        Creature* pMemory;
        uint64 MemoryGUID;

        bool bHealth;
        bool bDone;

        uint32 uiHolyFireTimer;
        uint32 uiHolySmiteTimer;
        uint32 uiRenewTimer;
        uint32 uiResetTimer;

        void Reset()
        {
            me->RemoveAllAuras();

            uiHolyFireTimer     = urand(9000,12000);
            uiHolySmiteTimer    = urand(5000,7000);
            uiRenewTimer        = urand(2000,5000);

            uiResetTimer        = 7000;

            bHealth = false;
            bDone = false;

            if (Creature *pMemory = Unit::GetCreature(*me, MemoryGUID))
                if (pMemory->isAlive())
                    pMemory->RemoveFromWorld();
        }

        void SetData(uint32 uiId, uint32 /*uiValue*/)
        {
            if (uiId == 1)
            {
                me->RemoveAura(SPELL_SHIELD);
                DoScriptText(SAY_MEM_DIE, me);
            }
        }
        
        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                bDone = true;
                DoScriptText(SAY_DEATH_P, me);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                    pInstance->HandleGameObject(pGO->GetGUID(),true);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                    pInstance->HandleGameObject(pGO->GetGUID(),true);
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);
                if (IsHeroic())
                    pInstance->DoCompleteAchievement(ACHIEV_CONF);
            }
        } 

        void EnterCombat(Unit* pWho)
        {
            DoScriptText(SAY_START_P, me);           
        }

        void KilledUnit(Unit* pVictim)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL1_P : SAY_KILL2_P, me);
            if (pInstance)
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_P,IN_PROGRESS);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);                
                bDone = false;
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                    pInstance->HandleGameObject(pGO->GetGUID(),true);
                me->DisappearAndDie();
            } else uiResetTimer -= uiDiff; 

            if (!UpdateVictim())
                return;

            if (uiHolyFireTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget,SPELL_HOLY_FIRE);
                }
                 if (me->HasAura(SPELL_SHIELD))
                    uiHolyFireTimer = 13000;
                else
                    uiHolyFireTimer = urand(9000,12000);
            } else uiHolyFireTimer -= uiDiff;

            if (uiHolySmiteTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget,SPELL_SMITE);
                }
                if (me->HasAura(SPELL_SHIELD))
                    uiHolySmiteTimer = 9000;
                else
                    uiHolySmiteTimer = urand(5000,7000);
            } else uiHolySmiteTimer -= uiDiff;

            if (me->HasAura(SPELL_SHIELD))
            {
                if (uiRenewTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(true);
                    uint8 uiTarget = urand(0,1);
                    switch(uiTarget)
                    {
                        case 0:
                            DoCast(me,SPELL_RENEW);
                            break;
                        case 1:
                            if (Creature *pMemory = Unit::GetCreature(*me, MemoryGUID))
                                if (pMemory->isAlive())
                                    DoCast(pMemory, SPELL_RENEW);
                            break;
                    }
                    uiRenewTimer = urand(15000,17000);
                } else uiRenewTimer -= uiDiff;
            }

            if (!bHealth && !HealthAbovePct(25))
            {
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA,false);
                DoCast(me, SPELL_SHIELD);
                DoCastAOE(SPELL_CONFESS,false);
                bHealth = true;

                switch(urand(0, 24))
                {
                    case 0: me->SummonCreature(MEMORY_ALGALON, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 1: me->SummonCreature(MEMORY_CHROMAGGUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 2: me->SummonCreature(MEMORY_CYANIGOSA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 3: me->SummonCreature(MEMORY_DELRISSA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 4: me->SummonCreature(MEMORY_ECK, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 5: me->SummonCreature(MEMORY_ENTROPIUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 6: me->SummonCreature(MEMORY_GRUUL, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 7: me->SummonCreature(MEMORY_HAKKAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 8: me->SummonCreature(MEMORY_HEIGAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 9: me->SummonCreature(MEMORY_HEROD, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 10: me->SummonCreature(MEMORY_HOGGER, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 11: me->SummonCreature(MEMORY_IGNIS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 12: me->SummonCreature(MEMORY_ILLIDAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 13: me->SummonCreature(MEMORY_INGVAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 14: me->SummonCreature(MEMORY_KALITHRESH, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 15: me->SummonCreature(MEMORY_LUCIFRON, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 16: me->SummonCreature(MEMORY_MALCHEZAAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 17: me->SummonCreature(MEMORY_MUTANUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 18: me->SummonCreature(MEMORY_ONYXIA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 19: me->SummonCreature(MEMORY_THUNDERAAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 20: me->SummonCreature(MEMORY_VANCLEEF, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 21: me->SummonCreature(MEMORY_VASHJ, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 22: me->SummonCreature(MEMORY_VEKNILASH, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 23: me->SummonCreature(MEMORY_VEZAX, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                    case 24: me->SummonCreature(MEMORY_ARCHIMONDE, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* pSummon)
        {
            MemoryGUID = pSummon->GetGUID();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_paletressAI(pCreature);
    }
};

class npc_memory : public CreatureScript
{
public:
    npc_memory() : CreatureScript("npc_memory") { }

    struct npc_memoryAI : public ScriptedAI
    {
        npc_memoryAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiOldWoundsTimer;
        uint32 uiShadowPastTimer;
        uint32 uiWakingNightmare;

        void Reset()
        {
            uiOldWoundsTimer = 12000;
            uiShadowPastTimer = 5000;
            uiWakingNightmare = 7000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiOldWoundsTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget, SPELL_OLD_WOUNDS);
                }
                uiOldWoundsTimer = 12000;
            }else uiOldWoundsTimer -= uiDiff;

            if (uiWakingNightmare <= uiDiff)
            {
                DoCast(me, SPELL_WAKING_NIGHTMARE);
                uiWakingNightmare = 7000;
            }else uiWakingNightmare -= uiDiff;

            if (uiShadowPastTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,1))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget,SPELL_SHADOWS_PAST);
                }
                uiShadowPastTimer = 5000;
            }else uiShadowPastTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (me->isSummon())
            {
                if (Unit* pSummoner = CAST_SUM(me)->GetSummoner())
                {
                    if (pSummoner && pSummoner->isAlive())
                        CAST_CRE(pSummoner)->AI()->SetData(1,0);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_memoryAI(pCreature);
    }
};

class npc_argent_soldier : public CreatureScript
{
public:
    npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

    
    struct npc_argent_soldierAI : public npc_escortAI
    {
        npc_argent_soldierAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->SetReactState(REACT_DEFENSIVE);
            SetDespawnAtEnd(false);
            uiWaypoint = 0;
        }

        InstanceScript* pInstance;

        uint8 uiWaypoint;
        uint32 uiCleaveTimer;
        uint32 uiStrikeTimer;
        uint32 uiblazingLightTimer;
        uint32 uiFlurryTimer;
        uint32 uiPummelTimer;
        uint32 uiHolySmiteTimer;
        uint32 uiMindControllTimer;
        uint32 uiPainDotTimer;
        uint32 uiFountainTimer;
        bool Shielded;
        
        void Reset()
        {
            switch(me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    uiCleaveTimer = 10000;
                    uiStrikeTimer = 12000;
                    uiblazingLightTimer = 9000;
                    break;
                case NPC_ARGENT_MONK:
                    uiFlurryTimer = 8000;
                    uiPummelTimer = 10000;
                    Shielded = false;
                    break;
                case NPC_PRIESTESS:
                    uiHolySmiteTimer = 9000;
                    uiPainDotTimer   = 8000;
                    uiFountainTimer  = 10000;
                    break;
            }
        }

        void WaypointReached(uint32 uiPoint)
        {
            if (uiPoint == 0)
            {
                switch(uiWaypoint)
                {
                    case 0:
                        me->SetOrientation(5.81f);
                        break;
                    case 1:
                        me->SetOrientation(4.60f);
                        break;
                    case 2:
                        me->SetOrientation(2.79f);
                        break;
                }

                me->SendMovementFlagUpdate();
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/)
        {
            switch(me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,712.14f,628.42f,411.88f);
                            break;
                        case 1:
                            AddWaypoint(0,742.44f,650.29f,411.79f);
                            break;
                        case 2:
                            AddWaypoint(0,783.33f,615.29f,411.84f);
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,713.12f,632.97f,411.90f);
                            break;
                        case 1:
                            AddWaypoint(0,746.73f,650.24f,411.56f);
                            break;
                        case 2:
                            AddWaypoint(0,781.32f,610.54f,411.82f);
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,715.06f,637.07f,411.91f);
                            break;
                        case 1:
                            AddWaypoint(0,750.72f,650.20f,411.77f);
                            break;
                        case 2:
                            AddWaypoint(0,779.77f,607.03f,411.81f);
                            break;
                    }
                    break;
            }

            Start(false,true,0);
            uiWaypoint = uiType;
        }

        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if (me->GetEntry() == NPC_ARGENT_MONK && IsHeroic() && Shielded==false) 
            {
                if (damage >= me->GetHealth())
                {
                    DoCast(me, SPELL_DIVINE_SHIELD);
                    DoCast(me, SPELL_FINAL_MEDITATION);
                    me->SetHealth(1);
                    damage = 0;
                    Shielded = true;
                }
            }
        } 

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
            
            switch(me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    if (uiCleaveTimer <= uiDiff)
                    {
                         DoCast(me->getVictim(), SPELL_CLEAVE);
                         uiCleaveTimer = 10000;
                    }else 
                         uiCleaveTimer -= uiDiff;

                    if (uiStrikeTimer <= uiDiff && IsHeroic())
                    {
                         DoCast(me->getVictim(), SPELL_UNBALANCING_STRIKE);
                         uiStrikeTimer = 12000;
                    }else 
                         uiStrikeTimer -= uiDiff;

                    if (uiblazingLightTimer <= uiDiff)
                    {
                         if (IsHeroic())
                             DoCast(me, SPELL_BLAZING_LIGHT_H); 
                         else
                             DoCast(me, SPELL_BLAZING_LIGHT); 
                         uiblazingLightTimer = 12000;
                    }else 
                         uiblazingLightTimer -= uiDiff;
                    break;
                case NPC_ARGENT_MONK:
                    if (uiFlurryTimer <= uiDiff)
                    {
                         DoCast(me, SPELL_FLURRY_OF_BLOWS);
                         uiFlurryTimer = 15000;
                    }else 
                         uiFlurryTimer -= uiDiff;
                    
                    if (uiPummelTimer <= uiDiff)
                    {
                         DoCast(me->getVictim(), SPELL_PUMMEL);
                         uiPummelTimer = 15000;
                    }else
                         uiPummelTimer -= uiDiff;

                    break;
                case NPC_PRIESTESS:
                    if (uiHolySmiteTimer <= uiDiff)
                    {
                         if(IsHeroic())
                             DoCast(me->getVictim(), SPELL_HOLY_SMITE_H);
                         else
                             DoCast(me->getVictim(), SPELL_HOLY_SMITE);
                         uiHolySmiteTimer = 9000;
                    }else 
                         uiHolySmiteTimer -= uiDiff;

                    if (uiPainDotTimer <= uiDiff)
                    {
                         if (IsHeroic())
                             DoCast(me->getVictim(), SPELL_DOT_PAIN_H); 
                         else
                             DoCast(me->getVictim(), SPELL_DOT_PAIN); 
                         uiPainDotTimer = 25000;
                    }else 
                         uiPainDotTimer -= uiDiff;

                    if (uiFountainTimer <= uiDiff)
                    {
                         DoCastAOE(SPELL_FOUNTAIN_OF_LIGHT,false); 
                         uiFountainTimer = 60000;
                    }else 
                         uiFountainTimer -= uiDiff;

                    break;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_ARGENT_SOLDIER_DEFEATED,pInstance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_argent_soldierAI(pCreature);
    }
};

enum ReflectiveShield
{
    SPELL_REFLECTIVE_SHIELD_TRIGGERED = 33619,
};

// Reflective Shield 66515
class spell_gen_reflective_shield : public SpellScriptLoader
{
    public:
        spell_gen_reflective_shield() : SpellScriptLoader("spell_gen_reflective_shield") { }

        class spell_gen_reflective_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_reflective_shield_AuraScript);

            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                return sSpellStore.LookupEntry(SPELL_REFLECTIVE_SHIELD_TRIGGERED);
            }

            void Trigger(AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit * target = dmgInfo.GetAttacker();
                if (!target)
                    return;
                Unit * caster = GetCaster();
                if (!caster)
                    return;
                int32 bp = CalculatePctN(absorbAmount, 25);
                target->CastCustomSpell(target, SPELL_REFLECTIVE_SHIELD_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
            }

            void Register()
            {
                 AfterEffectAbsorb += AuraEffectAbsorbFn(spell_gen_reflective_shield_AuraScript::Trigger, EFFECT_0);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_gen_reflective_shield_AuraScript();
        }
};

void AddSC_boss_argent_challenge()
{
    new boss_eadric();
    new boss_paletress();
    new npc_memory();
    new npc_argent_soldier();
    new spell_gen_reflective_shield();
}
