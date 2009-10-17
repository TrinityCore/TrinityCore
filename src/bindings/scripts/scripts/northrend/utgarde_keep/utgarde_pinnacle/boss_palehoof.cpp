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
#include "def_pinnacle.h"

//Spells
#define SPELL_ARCING_SMASH                          48260
#define SPELL_IMPALE                                48261
#define H_SPELL_IMPALE                              59268
#define SPELL_WITHERING_ROAR                        48256
#define H_SPELL_WITHERING_ROAR                      59267

#define SPELL_FREEZE                                16245

//ravenous furbolg's spells
#define SPELL_CHAIN_LIGHTING                        48140
#define H_SPELL_CHAIN_LIGHTING                      59273
#define SPELL_CRAZED                                48139
#define SPELL_TERRIFYING_ROAR                       48144

//frenzied worgen's spells
#define SPELL_MORTAL_WOUND                          48137
#define H_SPELL_MORTAL_WOUND                        59265
#define SPELL_ENRAGE_1                              48138
#define SPELL_ENRAGE_2                              48142

//ferocious rhino's spells
#define SPELL_GORE                                  48130
#define H_SPELL_GORE                                59264
#define SPELL_GRIEVOUS_WOUND                        48105
#define H_SPELL_GRIEVOUS_WOUND                      59263
#define SPELL_STOMP                                 48131

//massive jormungar's spells
#define SPELL_ACID_SPIT                             48132
#define SPELL_ACID_SPLATTER                         48136
#define H_SPELL_ACID_SPLATTER                       59272
#define SPELL_POISON_BREATH                         48133
#define H_SPELL_POISON_BREATH                       59271

#define CREATURE_JORMUNGAR_WORM                     27228

//not in db
//Yell
#define SAY_AGGRO                                -1575000
#define SAY_SLAY_1                               -1575001
#define SAY_SLAY_2                               -1575002
#define SAY_DEATH                                -1575003

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

    uint8 Phase;

    bool bWaiting;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiArcingSmashTimer = 15000;
        uiImpaleTimer = 12000;
        uiWhiteringRoarTimer = 10000;

        Phase = 0;
        bWaiting = false;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_FREEZE);

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

    void UpdateAI(const uint32 diff)
    {
        if (Phase == 6)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiArcingSmashTimer < diff)
            {
                DoCast(m_creature,SPELL_ARCING_SMASH);
                uiArcingSmashTimer = 13000 + rand()%4000;
            } else uiArcingSmashTimer -= diff;

            if (uiImpaleTimer < diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, HEROIC(SPELL_IMPALE, H_SPELL_IMPALE));
                uiImpaleTimer = 8000 + rand()%4000;
            } else uiImpaleTimer -= diff;

            if (uiWhiteringRoarTimer < diff)
            {
                DoCast(m_creature, HEROIC(SPELL_WITHERING_ROAR, H_SPELL_WITHERING_ROAR));
                uiWhiteringRoarTimer = 8000 + rand()%4000;
            } else uiWhiteringRoarTimer -= diff;

            DoMeleeAttackIfReady();
        }
        else if (Phase != 0 && bWaiting)
        {
          if (uiWaitingTimer < diff)
          {
              Creature *pNext;
              switch(Phase)
              {
                  case 1: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FRENZIED_WORGEN) : 0); break;
                  case 2: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_RAVENOUS_FURBOLG) : 0); break;
                  case 3: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_MASSIVE_JORMUNGAR) : 0); break;
                  case 4: pNext = Unit::GetCreature((*m_creature), pInstance ? pInstance->GetData64(DATA_MOB_FEROCIOUS_RHINO) : 0); break;
                  case 5: pNext = m_creature; ++Phase; break;
              }

              if (pNext)
              {
                  pNext->RemoveAurasDueToSpell(SPELL_FREEZE);
                  pNext->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                  pNext->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                  ((Unit*)pNext)->SetStandState(UNIT_STAND_STATE_STAND);
                  pNext->SetInCombatWithZone();
              }

              bWaiting = false;
          } else uiWaitingTimer -= diff;
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (pInstance)
            pInstance->SetData(DATA_GORTOK_PALEHOOF_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void NextPhase()
    {
        ++Phase;
        bWaiting = true;
        uiWaitingTimer = 1000;
    }
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

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_FREEZE);
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

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_FREEZE);
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

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_FREEZE);
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

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_FREEZE);
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
};

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

CreatureAI* GetAI_boss_palehoof(Creature* pCreature)
{
    return new boss_palehoofAI (pCreature);
}

CreatureAI* GetAI_mob_ravenous_furbolg(Creature* pCreature)
{
    return new mob_ravenous_furbolgAI (pCreature);
}

CreatureAI* GetAI_mob_frenzied_worgen(Creature* pCreature)
{
    return new mob_frenzied_worgenAI (pCreature);
}

CreatureAI* GetAI_mob_ferocious_rhino(Creature* pCreature)
{
    return new mob_ferocious_rhinoAI (pCreature);
}

CreatureAI* GetAI_mob_massive_jormungar(Creature* pCreature)
{
    return new mob_massive_jormungarAI (pCreature);
}

void AddSC_boss_palehoof()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_palehoof";
    newscript->GetAI = &GetAI_boss_palehoof;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ravenous_furbolg";
    newscript->GetAI = &GetAI_mob_ravenous_furbolg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_frenzied_worgen";
    newscript->GetAI = &GetAI_mob_frenzied_worgen;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ferocious_rhino";
    newscript->GetAI = &GetAI_mob_ferocious_rhino;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_massive_jormungar";
    newscript->GetAI = &GetAI_mob_massive_jormungar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_palehoof_sphere";
    newscript->pGOHello=&GOHello_palehoof_sphere;
    newscript->RegisterSelf();
}
