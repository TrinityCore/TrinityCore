/* Script Data Start
SDName: Boss palehoof
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_palehoof' where entry = '';
*** SQL END ***/
#include "precompiled.h"
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
    {261.6,-449.3,109.5},
    {263.3,-454.0,109.5},
    {291.5,-450.4,109.5},
    {291.5,-454.0,109.5},
    {310.0,-453.4,109.5},
    {238.6,-460.7,109.5}
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

struct TRINITY_DLL_DECL boss_palehoofAI : public ScriptedAI
{
    boss_palehoofAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiArcingSmashTimer;
    uint32 uiImpaleTimer;
    uint32 uiWhiteringRoarTimer;
    uint32 uiWaitingTimer;
    Phase currentPhase;
    uint8 AddCount;
    bool DoneAdds[4];

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiArcingSmashTimer = 15000;
        uiImpaleTimer = 12000;
        uiWhiteringRoarTimer = 10000;

        m_creature->GetMotionMaster()->MoveTargetedHome();
 
        for(uint32 i=0;i<4;i++)
            DoneAdds[i]=false;
        AddCount=0;
 
        currentPhase=PHASE_NONE;

        if (pInstance)
        {
            pInstance->SetData(DATA_GORTOK_PALEHOOF_EVENT, NOT_STARTED);

            Creature* pTemp;
            if ((pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_FRENZIED_WORGEN))) && !pTemp->isAlive())
                pTemp->Respawn();
            if ((pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_FEROCIOUS_RHINO))) && !pTemp->isAlive())
                pTemp->Respawn();
            if ((pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR))) && !pTemp->isAlive())
                pTemp->Respawn();
            if ((pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_RAVENOUS_FURBOLG))) && !pTemp->isAlive())
                pTemp->Respawn();

            if (GameObject* pGo = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_GORTOK_PALEHOOF_SPHERE)))
            {
                pGo->SetGoState(GO_STATE_READY);
                pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
            }
        }
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    
    void AttackStart(Unit* who)
    {
        if (!who)
            return;
 
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;
 
        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);
            DoStartMovement(who);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(currentPhase!=PHASE_GORTOK_PALEHOOF)
            return;
        //Return since we have no target
        if (!UpdateVictim())
            return;
        
        Creature* pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_ORB));
        if (pTemp && pTemp->isAlive())
            pTemp->DisappearAndDie();
        
        if (uiArcingSmashTimer < diff)
        {
            DoCast(m_creature,SPELL_ARCING_SMASH);
            uiArcingSmashTimer = urand(13000,17000);
        } else uiArcingSmashTimer -= diff;
        
        if (uiImpaleTimer < diff)
        {
          if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
              DoCast(pTarget, HEROIC(SPELL_IMPALE,H_SPELL_IMPALE));
          uiImpaleTimer = urand(8000,12000);
        } else uiImpaleTimer -= diff;
        
        if (uiWhiteringRoarTimer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_WITHERING_ROAR,H_SPELL_WITHERING_ROAR));
            uiWhiteringRoarTimer = urand(8000,12000);
        } else uiWhiteringRoarTimer -= diff;
        
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (pInstance)
            pInstance->SetData(DATA_GORTOK_PALEHOOF_EVENT, DONE);
        Creature* pTemp = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_MOB_ORB));
        if (pTemp && pTemp->isAlive())
            pTemp->DisappearAndDie();
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void NextPhase()
    {
        if(currentPhase==PHASE_NONE)
        {
            pInstance->SetData(DATA_GORTOK_PALEHOOF_EVENT, IN_PROGRESS);
            m_creature->SummonCreature(MOB_STASIS_CONTROLLER,moveLocs[5].x,moveLocs[5].y,moveLocs[5].z,0,TEMPSUMMON_CORPSE_DESPAWN);
        }
        Phase move = PHASE_NONE;
        if(AddCount>=(HeroicMode?4:2))
        {
            move=PHASE_GORTOK_PALEHOOF;
        }
        else
        {
            //select random not yet defeated add
            uint8 next = rand()%4;
            for(int i=0;i<16;i++)
            {
                if(!DoneAdds[i%4]&&next==0){
                    move=(Phase)(i%4);
                    break;
                }else if(!DoneAdds[i%4]&&next>0)
                    next--;
            }
            AddCount++;
            DoneAdds[move]=true;
            move=(Phase)(move%4);
        }
        //send orb to summon spot
        Creature *pOrb = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_ORB) : 0);
        if (pOrb && pOrb->isAlive()){
            if(currentPhase==PHASE_NONE)
                pOrb->CastSpell(m_creature,SPELL_ORB_VISUAL,true);
            pOrb->GetMotionMaster()->MovePoint(move,moveLocs[move].x,moveLocs[move].y,moveLocs[move].z);
        }
        currentPhase=move;
    }
    
    void JustReachedHome()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        DoCast(m_creature, SPELL_FREEZE);
    }
};

CreatureAI* GetAI_boss_palehoof(Creature* pCreature)
{
    return new boss_palehoofAI (pCreature);
}

//ravenous furbolg's spells
enum RavenousSpells
{
    SPELL_CHAIN_LIGHTING                        = 48140,
    H_SPELL_CHAIN_LIGHTING                      = 59273,
    SPELL_CRAZED                                = 48139,
    SPELL_TERRIFYING_ROAR                       = 48144
};

struct TRINITY_DLL_DECL mob_ravenous_furbolgAI : public ScriptedAI
{
    mob_ravenous_furbolgAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiChainLightingTimer;
    uint32 uiCrazedTimer;
    uint32 uiTerrifyingRoarTimer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiChainLightingTimer = 5000;
        uiCrazedTimer = 10000;
        uiTerrifyingRoarTimer = 15000;

        m_creature->GetMotionMaster()->MoveTargetedHome();
 
        if (pInstance)
            if(pInstance->GetData(DATA_GORTOK_PALEHOOF_EVENT)==IN_PROGRESS)
            {
                Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof && pPalehoof->isAlive())
                    CAST_AI(boss_palehoofAI, pPalehoof->AI())->Reset();
            }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiChainLightingTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_CHAIN_LIGHTING, H_SPELL_CHAIN_LIGHTING));
            uiChainLightingTimer = 5000 + rand()%5000;
        } else uiChainLightingTimer -=  diff;

        if (uiCrazedTimer < diff)
        {
            DoCast(m_creature, SPELL_CRAZED);
            uiCrazedTimer = 8000 + rand()%4000;
        } else uiCrazedTimer -=  diff;

        if (uiTerrifyingRoarTimer < diff)
        {
            DoCast(m_creature, SPELL_TERRIFYING_ROAR);
            uiTerrifyingRoarTimer = 10000 + rand()%10000;
        } else uiTerrifyingRoarTimer -=  diff;

        DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);
            DoStartMovement(who);
        }
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
            if (pPalehoof)
                CAST_AI(boss_palehoofAI, pPalehoof->AI())->NextPhase();
        }
    }
    
    void JustReachedHome()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        DoCast(m_creature, SPELL_FREEZE);
    }
};

CreatureAI* GetAI_mob_ravenous_furbolg(Creature* pCreature)
{
    return new mob_ravenous_furbolgAI (pCreature);
}

//frenzied worgen's spells
enum FrenziedSpells
{
    SPELL_MORTAL_WOUND                          = 48137,
    H_SPELL_MORTAL_WOUND                        = 59265,
    SPELL_ENRAGE_1                              = 48138,
    SPELL_ENRAGE_2                              = 48142
};

struct TRINITY_DLL_DECL mob_frenzied_worgenAI : public ScriptedAI
{
    mob_frenzied_worgenAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiMortalWoundTimer;
    uint32 uiEnrage1Timer;
    uint32 uiEnrage2Timer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uint32 uiMortalWoundTimer = 5000;
        uint32 uiEnrage1Timer = 15000;
        uint32 uiEnrage2Timer = 10000;

        m_creature->GetMotionMaster()->MoveTargetedHome();
 
        if (pInstance)
            if(pInstance->GetData(DATA_GORTOK_PALEHOOF_EVENT)==IN_PROGRESS)
            {
                Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof && pPalehoof->isAlive())
                    CAST_AI(boss_palehoofAI, pPalehoof->AI())->Reset();
            }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiMortalWoundTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_MORTAL_WOUND, H_SPELL_MORTAL_WOUND));
            uiMortalWoundTimer = 3000 + rand()%4000;
        } else uiMortalWoundTimer -= diff;

        if (uiEnrage1Timer < diff)
        {
            DoCast(m_creature, SPELL_ENRAGE_1);
            uiEnrage1Timer = 15000;
        } else uiEnrage1Timer -= diff;

        if (uiEnrage2Timer < diff)
        {
            DoCast(m_creature, SPELL_ENRAGE_2);
            uiEnrage2Timer = 10000;
        } else uiEnrage2Timer -= diff;

        DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);
            DoStartMovement(who);
        }
        if (pInstance)
            pInstance->SetData(DATA_GORTOK_PALEHOOF_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
            if (pPalehoof)
                CAST_AI(boss_palehoofAI, pPalehoof->AI())->NextPhase();
        }
    }
    
    void JustReachedHome()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        DoCast(m_creature, SPELL_FREEZE);
    }
};

CreatureAI* GetAI_mob_frenzied_worgen(Creature* pCreature)
{
    return new mob_frenzied_worgenAI (pCreature);
}

//ferocious rhino's spells
enum FerociousSpells
{
    SPELL_GORE                                  = 48130,
    H_SPELL_GORE                                = 59264,
    SPELL_GRIEVOUS_WOUND                        = 48105,
    H_SPELL_GRIEVOUS_WOUND                      = 59263,
    SPELL_STOMP                                 = 48131
};

struct TRINITY_DLL_DECL mob_ferocious_rhinoAI : public ScriptedAI
{
    mob_ferocious_rhinoAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiStompTimer;
    uint32 uiGoreTimer;
    uint32 uiGrievousWoundTimer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiStompTimer = 10000;
        uiGoreTimer = 15000;
        uiGrievousWoundTimer = 20000;

        m_creature->GetMotionMaster()->MoveTargetedHome();
 
        if (pInstance)
            if(pInstance->GetData(DATA_GORTOK_PALEHOOF_EVENT)==IN_PROGRESS)
            {
                Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof && pPalehoof->isAlive())
                    CAST_AI(boss_palehoofAI, pPalehoof->AI())->Reset();
            }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiStompTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_STOMP);
            uiStompTimer = 8000 + rand()%4000;
        } else uiStompTimer -= diff;

        if (uiGoreTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_GORE, H_SPELL_GORE));
            uiGoreTimer = 13000 + rand()%4000;
        } else uiGoreTimer -= diff;

        if (uiGrievousWoundTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, HEROIC(SPELL_GRIEVOUS_WOUND, H_SPELL_GRIEVOUS_WOUND));
            uiGrievousWoundTimer = 18000 + rand()%4000;
        } else uiGrievousWoundTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);
            DoStartMovement(who);
        }
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
            if (pPalehoof)
                CAST_AI(boss_palehoofAI, pPalehoof->AI())->NextPhase();
        }
    }
    
    void JustReachedHome()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        DoCast(m_creature, SPELL_FREEZE);
    }
};

CreatureAI* GetAI_mob_ferocious_rhino(Creature* pCreature)
{
    return new mob_ferocious_rhinoAI (pCreature);
}

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

struct TRINITY_DLL_DECL mob_massive_jormungarAI : public ScriptedAI
{
    mob_massive_jormungarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiAcidSpitTimer;
    uint32 uiAcidSplatterTimer;
    uint32 uiPoisonBreathTimer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiAcidSpitTimer = 3000;
        uiAcidSplatterTimer = 12000;
        uiPoisonBreathTimer = 10000;

        m_creature->GetMotionMaster()->MoveTargetedHome();
 
        if (pInstance)
            if(pInstance->GetData(DATA_GORTOK_PALEHOOF_EVENT) == IN_PROGRESS)
            {
                Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
                if (pPalehoof && pPalehoof->isAlive())
                    CAST_AI(boss_palehoofAI, pPalehoof->AI())->Reset();
            }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiAcidSpitTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_ACID_SPIT);
            uiAcidSpitTimer = 2000 + rand()%2000;
        } else uiAcidSpitTimer -= diff;

        if (uiAcidSplatterTimer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_POISON_BREATH, H_SPELL_POISON_BREATH));
            uiAcidSplatterTimer = 10000 + rand()%4000;
        } else uiAcidSplatterTimer -= diff;

        if (uiPoisonBreathTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, HEROIC(SPELL_POISON_BREATH, H_SPELL_POISON_BREATH));
            uiPoisonBreathTimer = 8000 + rand()%4000;
        } else uiPoisonBreathTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);
            DoStartMovement(who);
        }
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            Creature *pPalehoof = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
            if (pPalehoof)
                CAST_AI(boss_palehoofAI,pPalehoof->AI())->NextPhase();
        }
    }
    
    void JustReachedHome()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        DoCast(m_creature, SPELL_FREEZE);
    }
};

CreatureAI* GetAI_mob_massive_jormungar(Creature* pCreature)
{
    return new mob_massive_jormungarAI (pCreature);
}

struct TRINITY_DLL_DECL mob_palehoof_orbAI : public ScriptedAI
{
    mob_palehoof_orbAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    uint32 SummonTimer;
    Phase currentPhase;

    void Reset()
    {
        currentPhase=PHASE_NONE;
        SummonTimer=5000;
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
        m_creature->RemoveAurasDueToSpell(SPELL_ORB_VISUAL);
        m_creature->SetSpeed(MOVE_FLIGHT , 0.5f);
    }

    void UpdateAI(const uint32 diff)
    {
        if(currentPhase==PHASE_NONE)
            return;

        if(SummonTimer<=diff)
        {
            if(currentPhase<5&&currentPhase>=0)
            {
               Creature *pNext;
               switch(currentPhase)
               {
                    case PHASE_FRENZIED_WORGEN: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FRENZIED_WORGEN) : 0); break;
                    case PHASE_RAVENOUS_FURLBORG: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_RAVENOUS_FURBOLG) : 0); break;
                    case PHASE_MASSIVE_JORMUNGAR: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR) : 0); break;
                    case PHASE_FEROCIOUS_RHINO: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FEROCIOUS_RHINO) : 0); break;
                    case PHASE_GORTOK_PALEHOOF: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0); break;
               }

               if (pNext)
               {
                    pNext->RemoveAurasDueToSpell(SPELL_FREEZE);
                    pNext->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    ((Unit*)pNext)->SetStandState(UNIT_STAND_STATE_STAND);
                    pNext->SetInCombatWithZone();
                    pNext->Attack(pNext->SelectNearestTarget(100),true);
                    
               }
               currentPhase=PHASE_NONE;
            }
        } else SummonTimer-=diff;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;
        if(id<0&&id>4)
            return;
        Creature *pNext;
        switch(id)
        {
            case PHASE_FRENZIED_WORGEN: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FRENZIED_WORGEN) : 0); break;
            case PHASE_RAVENOUS_FURLBORG: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_RAVENOUS_FURBOLG) : 0); break;
            case PHASE_MASSIVE_JORMUNGAR: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR) : 0); break;
            case PHASE_FEROCIOUS_RHINO: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FEROCIOUS_RHINO) : 0); break;
            case PHASE_GORTOK_PALEHOOF: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0); break;
        }
        DoCast(pNext,SPELL_ORB_CHANNEL,false);
        currentPhase=(Phase)id;
        SummonTimer=5000;
    }
};

CreatureAI* GetAI_mob_palehoof_orb(Creature* pCreature)
{
    return new mob_palehoof_orbAI (pCreature);
}

bool GOHello_palehoof_sphere(Player *pPlayer, GameObject *pGO)
{
    ScriptedInstance *pInstance = pGO->GetInstanceData();

    Creature *pPalehoof = Unit::GetCreature(*pGO, pInstance ? pInstance->GetData64(DATA_GORTOK_PALEHOOF) : 0);
    if (pPalehoof && pPalehoof->isAlive())
    {
        // maybe these are hacks :(
        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        pGO->SetGoState(GO_STATE_ACTIVE);

        CAST_AI(boss_palehoofAI, pPalehoof->AI())->NextPhase();
    }
    return true;
}



void AddSC_boss_palehoof()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_palehoof";
    newscript->GetAI = &GetAI_boss_palehoof;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ravenous_furbolg";
    newscript->GetAI = &GetAI_mob_ravenous_furbolg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_frenzied_worgen";
    newscript->GetAI = &GetAI_mob_frenzied_worgen;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ferocious_rhino";
    newscript->GetAI = &GetAI_mob_ferocious_rhino;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_massive_jormungar";
    newscript->GetAI = &GetAI_mob_massive_jormungar;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_palehoof_orb";
    newscript->GetAI = &GetAI_mob_palehoof_orb;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_palehoof_sphere";
    newscript->pGOHello=&GOHello_palehoof_sphere;
    newscript->RegisterSelf();
}
