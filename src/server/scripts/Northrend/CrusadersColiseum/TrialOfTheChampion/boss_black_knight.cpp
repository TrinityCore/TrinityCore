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
SDName: Boss Black Knight
SD%Complete: 95%
SDComment: not sure about timers.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "trial_of_the_champion.h"
#define SAY_RESET  -1999927


enum eEnums
{
    //Yell
    SAY_DEATH_3                             = -1999935,
    SAY_AGGRO                               = -1999929,
    SAY_AGGRO_2                             = -1999930,
    SAY_SLAY                                = -1999932,
    SAY_DEATH_1                             = -1999933,
    SAY_DEATH                               = -1999934,
    SAY_START5                              = -1999936,
    SAY_START6                              = -1999937,
    SAY_START7                              = -1999928,
    SAY_START8                              = -1999929,
    SAY_START9                              = -1999952,
    SAY_START10                             = -1999932,
    SAY_START11                             = -1999953,
};
enum eSpells
{
    //phase 1
    SPELL_PLAGUE_STRIKE     = 67884,
    SPELL_PLAGUE_STRIKE_2   = 67724,
    SPELL_ICY_TOUCH_H       = 67881,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_DEATH_RESPITE_2   = 68306,
    SPELL_DEATH_RESPITE_3   = 66798,
    SPELL_OBLITERATE_H      = 67883,
    SPELL_OBLITERATE        = 67725,

    //phase 2 - During this phase, the Black Knight will use the same abilities as in phase 1, except for Death's Respite
    SPELL_ARMY_DEAD         = 67761,
    SPELL_DESECRATION       = 67778,
    SPELL_DESECRATION_2     = 67778,
    SPELL_GHOUL_EXPLODE     = 67751,

    //phase 3
    SPELL_DEATH_BITE_H      = 67875,
    SPELL_DEATH_BITE        = 67808,
    SPELL_MARKED_DEATH      = 67882,
    SPELL_MARKED_DEATH_2    = 67823,

    SPELL_BLACK_KNIGHT_RES  = 67693,

    SPELL_LEAP                          = 67749,
    SPELL_LEAP_H                        = 67880
};

enum eModels
{
     MODEL_SKELETON = 29846,
     MODEL_GHOST    = 21300
};

enum ePhases
{
    PHASE_UNDEAD    = 1,
    PHASE_SKELETON  = 2,
    PHASE_GHOST     = 3
};
/*
enum eState
{
    START =0,
    IDLE  =1,
    ENABLE  =2
};
*/

enum Misc
{
    ACHIEV_WORSE                                  = 3804
};

class boss_black_knight : public CreatureScript
{
    public:
        boss_black_knight(): CreatureScript("boss_black_knight") {}

    struct boss_black_knightAI : public BossAI
    {
        boss_black_knightAI(Creature* pCreature) : BossAI(pCreature,BOSS_BLACK_KNIGHT)
        {
            pInstance = pCreature->GetInstanceScript();
            bStartCombat = false;
        }

        InstanceScript* pInstance;
        std::list<uint64> SummonList;

        bool bEventInProgress;
        bool bEvent;
        bool bSummonArmy;
        bool bDeathArmyDone;
        bool bReset;
        bool bStartCombat;

        uint8 uiPhase;
        //uint8 uiState;

        uint32 uiPlagueStrikeTimer;
        uint32 uiPlagueStrike1Timer;
        uint32 uiIcyTouchTimer;
        uint32 uiIcyTouch1Timer;
        uint32 uiDeathRespiteTimer;
        uint32 uiObliterateTimer;
        uint32 uiObliterate1Timer;
        uint32 uiDesecration;
        uint32 uiDesecration1;
        uint32 uiResurrectTimer;
        uint32 uiDeathArmyCheckTimer;
        uint32 uiGhoulExplodeTimer;
        uint32 uiDeathBiteTimer;
        uint32 uiMarkedDeathTimer;  

        void Reset()
        {
            _Reset();
            RemoveSummons();
            me->SetDisplayId(me->GetNativeDisplayId());
            me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
            
            Map* pMap = me->GetMap();
            if (pMap && pMap->IsDungeon() && !bStartCombat)
            {
                bReset = true;
                Map::PlayerList const &players = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if(itr->getSource() && itr->getSource()->isAlive() && !itr->getSource()->isGameMaster())
                        bReset = false;
                }
            }
            else
                bReset = true;

                   
            ResetEncounter();
           
            //me->SummonCreature(28859,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_CORPSE_DESPAWN);
            //uiState=IDLE;
            bEventInProgress = false;
            bEvent = false;
            bSummonArmy = false;
            bDeathArmyDone = false;        
                   
            uiPhase = PHASE_UNDEAD;

            uiIcyTouchTimer = urand(5000,9000);
            uiIcyTouch1Timer = urand(15000,15000);
            uiPlagueStrikeTimer = urand(10000,13000);
            uiPlagueStrike1Timer = urand(14000,14000);
            uiDeathRespiteTimer = urand(17000,17000);
            uiObliterateTimer = urand(17000,19000);
            uiObliterate1Timer = urand(15000,15000);
            uiDesecration = urand(15000,16000);
            uiDesecration1 = urand(22000,22000);
            uiDeathArmyCheckTimer = 7000;
            uiResurrectTimer = 4000;
            uiGhoulExplodeTimer = 8000;
            uiDeathBiteTimer = urand (2000,4000);
            uiMarkedDeathTimer = urand (5000,7000);
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for(std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                    if (pTemp)
                        pTemp->DisappearAndDie();
            }
            SummonList.clear();
        }


        void JustSummoned(Creature* pSummon)
        {
            SummonList.push_back(pSummon->GetGUID());
            pSummon->AI()->AttackStart(me->getVictim());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;  

            if (bEventInProgress)
                if (uiResurrectTimer <= uiDiff)
                {
                    me->SetFullHealth();
                    me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    me->AttackStop();                              
                            DoScriptText(RAND(SAY_DEATH_1,SAY_DEATH), me);
                    DoCast(me,SPELL_BLACK_KNIGHT_RES,true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    uiPhase++;
                    uiResurrectTimer = 3000;
                    bEventInProgress = false;
                    me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                } else uiResurrectTimer -= uiDiff;

            switch(uiPhase)
            {
                case PHASE_UNDEAD:
                {
                    if (uiPlagueStrikeTimer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_PLAGUE_STRIKE,SPELL_PLAGUE_STRIKE_2));
                        uiPlagueStrikeTimer = urand(12000,15000);
                    } else uiPlagueStrikeTimer -= uiDiff;

                    if (uiObliterateTimer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_OBLITERATE,SPELL_OBLITERATE_H));
                        uiObliterateTimer = urand(17000,19000);
                    } else uiObliterateTimer -= uiDiff;

                    if (uiIcyTouchTimer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_ICY_TOUCH,SPELL_ICY_TOUCH_H));
                        uiIcyTouchTimer = urand(5000,7000);
                    } else uiIcyTouchTimer -= uiDiff;
                } break;
                case PHASE_SKELETON:
                {
                    if (!bSummonArmy)
                    {
                        bSummonArmy = true;
                        me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                        me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                        DoCast(me, SPELL_ARMY_DEAD);
                    }

                    if (!bDeathArmyDone)
                    {
                        if (uiDeathArmyCheckTimer <= uiDiff)
                        {
                            me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                            me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                            uiDeathArmyCheckTimer = 0;
                            bDeathArmyDone = true;
                        } else uiDeathArmyCheckTimer -= uiDiff;
                    }

                    if (uiDesecration1 <= uiDiff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (pTarget && pTarget->isAlive())
                                DoCast(pTarget,SPELL_DESECRATION);
                        }
                        uiDesecration1 = urand(15000,16000);
                    } else uiDesecration1 -= uiDiff;

                    if (uiGhoulExplodeTimer <= uiDiff)
                    {
                        DoCast(me, SPELL_GHOUL_EXPLODE);
                        uiGhoulExplodeTimer = 8000;
                    } else uiGhoulExplodeTimer -= uiDiff;

                    if (uiPlagueStrike1Timer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_PLAGUE_STRIKE,SPELL_PLAGUE_STRIKE_2));
                        uiPlagueStrike1Timer = urand(12000,15000);
                    } else uiPlagueStrike1Timer -= uiDiff;

                    if (uiObliterate1Timer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_OBLITERATE,SPELL_OBLITERATE_H));
                        uiObliterate1Timer = urand(17000,19000);
                    } else uiObliterate1Timer -= uiDiff;

                    if (uiIcyTouch1Timer <= uiDiff)
                    {
                        DoCastVictim(DUNGEON_MODE(SPELL_ICY_TOUCH,SPELL_ICY_TOUCH_H));
                        uiIcyTouch1Timer = urand(5000,7000);
                    } else uiIcyTouch1Timer -= uiDiff;

                    if (uiDeathRespiteTimer <= uiDiff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (pTarget && pTarget->isAlive())
                            DoCast(pTarget,SPELL_DEATH_RESPITE);
                        }
                        uiDeathRespiteTimer = urand(15000,16000);
                    } else uiDeathRespiteTimer -= uiDiff;
                } break;
                case PHASE_GHOST:
                {  
                    if (uiDeathBiteTimer <= uiDiff)
                    {
                        DoCast(me,DUNGEON_MODE(SPELL_DEATH_BITE,SPELL_DEATH_BITE_H));
                        uiDeathBiteTimer = urand (2000, 4000);
                    } else uiDeathBiteTimer -= uiDiff;

                    if (uiMarkedDeathTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (pTarget && pTarget->isAlive())
                                DoCast(pTarget,SPELL_MARKED_DEATH);
                        }
                        uiMarkedDeathTimer = urand (5000, 7000);
                    } else uiMarkedDeathTimer -= uiDiff;
                } break;
            }

            if (!me->HasUnitState(UNIT_STAT_ROOT) && !me->HealthBelowPct(1))
                DoMeleeAttackIfReady();
        }

        void EnterCombat(Unit* pWho)
        {
            //uiState=START;
            _EnterCombat();
            bStartCombat = true;
            DoScriptText(SAY_AGGRO_2, me);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                pInstance->HandleGameObject(pGO->GetGUID(),false);
            //me->SetHomePosition(746.843, 695.68, 412.339, 4.70776);
            if (pInstance)
                pInstance->SetData(DATA_AGGRO_DONE, DONE);
            //if (pInstance)
            //    pInstance->SetData(BOSS_BLACK_KNIGHT, IN_PROGRESS);
        }

        void KilledUnit(Unit* pVictim)
        {
            DoScriptText(SAY_SLAY, me);
                   
            if (pInstance)
                pInstance->SetData(BOSS_BLACK_KNIGHT, IN_PROGRESS);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
        {
            if (uiDamage > me->GetHealth() && uiPhase <= PHASE_SKELETON)
            {
                uiDamage = 0;
                me->SetHealth(0);
                me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                RemoveSummons();
                switch(uiPhase)
                {
                    case PHASE_UNDEAD:
                        me->SetDisplayId(MODEL_SKELETON);
                        break;
                    case PHASE_SKELETON:
                        me->SetDisplayId(MODEL_GHOST);
                        break;
                }
                bEventInProgress = true;
            }
        }
                   
        void ResetEncounter()
        {
            if(bReset)
            {      
                if(me)
                {
                    Map *instance = me->GetMap();
                    if(instance && pInstance)
                    {
                        Creature* npc = instance->GetCreature(pInstance->GetData64(DATA_ANNOUNCER));
                        GameObject* door = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1));
                        if (door)
                            pInstance->HandleGameObject(door->GetGUID(),true);
                        if(npc)
                            npc->RemoveFromWorld();       
                        me->SummonCreature(35004, 742.835f, 639.134f, 411.571f, 0, TEMPSUMMON_CORPSE_DESPAWN);
                        me->RemoveFromWorld();
                    }
                }
            }
        }


        void JustDied(Unit* pKiller)
        {
            //uiState=ENABLE;
            DoScriptText(SAY_DEATH_3, me);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                pInstance->HandleGameObject(pGO->GetGUID(),true);
			// Prevent corpse despawning
            if (TempSummon* summ = me->ToTempSummon())
                summ->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);
                   
            if (pInstance)
            {
                pInstance->SetData(BOSS_BLACK_KNIGHT, DONE);
                
                if (IsHeroic())
                    pInstance->DoCompleteAchievement(ACHIEV_WORSE);
            }

            if (Map* instance = me->GetMap())
            {
                Creature* npc = instance->GetCreature(pInstance->GetData64(DATA_ANNOUNCER));
                //fix brutale per il loot °O°

                if (pInstance)
			        pInstance->SetBossState(NPC_BLACK_KNIGHT, DONE);
                // me->SummonGameObject(IsHeroic()? GO_BK_LOOT_H : GO_BK_LOOT, 746.59,618.49, 411.09, 1.42, 0, 0, 0, 0, 90000000);
                if(npc)
                    npc->RemoveFromWorld();
            }
           
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new boss_black_knightAI (pCreature);
    };
};

class npc_risen_ghoul : public CreatureScript
{
    public:
        npc_risen_ghoul(): CreatureScript("npc_risen_ghoul") {}

    struct npc_risen_ghoulAI : public ScriptedAI
    {
        npc_risen_ghoulAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiAttackTimer;
            bool bReset;

        void Reset()
        {
            Map* pMap = me->GetMap();
            if (pMap && pMap->IsDungeon())
            {
                bReset=true;
                Map::PlayerList const &players = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if(itr->getSource())
                        if(itr->getSource()->isAlive())
                            bReset=false;
                }
            }
            Despawn();
            uiAttackTimer = 3500;
        }
           
        void Despawn()
        {
            if(bReset)
                me->RemoveFromWorld();
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiAttackTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    if (pTarget && pTarget->isAlive())
                    DoCast(pTarget, (DUNGEON_MODE(SPELL_LEAP,SPELL_LEAP_H)));
                }
                uiAttackTimer = 3500;
            } else uiAttackTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_risen_ghoulAI(pCreature);
    };
};

class npc_black_knight_skeletal_gryphon : public CreatureScript
{
    public:
        npc_black_knight_skeletal_gryphon(): CreatureScript("npc_black_knight_skeletal_gryphon") {}

    struct npc_black_knight_skeletal_gryphonAI : public npc_escortAI
    {
        npc_black_knight_skeletal_gryphonAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            Start(false,true,0,NULL);
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 1:                        
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);                          
                                break;
                case 2:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                DoScriptText(SAY_START7, me);
                                break;
                case 3:    
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 4:    
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 5:    
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;                          
                case 6:    
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                DoScriptText(SAY_AGGRO, me);
                    break;                          
                case 7:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;      
                case 8:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 9:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 10:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 11:
                                me->SetSpeed(MOVE_FLIGHT , 2.0f);
                                break;
                case 12:
                                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);  
                                me->SetSpeed(MOVE_RUN, 2.0f);                              
                                break;
                case 13:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->SummonCreature(VEHICLE_GR,744.841f,634.505f,411.575f, 2.79f);                              
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_black_knight_skeletal_gryphonAI(pCreature);
    };
};

class npc_gr : public CreatureScript
{
    public:
        npc_gr(): CreatureScript("npc_gr") {}

    struct npc_grAI : public npc_escortAI
    {
        npc_grAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            Start(false,true,0,NULL);
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 1:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case 2:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case 3:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case 4:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case 5:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);                        
                    break;
                case 6:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);                        
                    break;                          
                case 7:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;                          
                case 8:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                case 9:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_grAI(pCreature);
    };
};

void AddSC_boss_black_knight()
{              
    new boss_black_knight();
    new npc_risen_ghoul();
    new npc_black_knight_skeletal_gryphon();
    new npc_gr();
}



