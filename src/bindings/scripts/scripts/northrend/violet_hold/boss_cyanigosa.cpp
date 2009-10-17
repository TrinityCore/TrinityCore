/* Script Data Start
SDName: Boss cyanigosa
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_violet_hold.h"

enum Spells
{
    SPELL_ARCANE_VACUM                             = 58694,
    SPELL_BLIZZARD                                 = 58693,
    H_SPELL_BLIZZARD                               = 59369,
    SPELL_MANA_DESTRUCTION                         = 59374,
    SPELL_TAIL_SWEEP                               = 58690,
    H_SPELL_TAIL_SWEEP                             = 59283,
    SPELL_UNCONTROLLABLE_ENERGY                    = 58688,
    H_SPELL_UNCONTROLLABLE_ENERGY                  = 59281
};

enum Yells
{
    SAY_AGGRO                                   = -1608000,
    SAY_SLAY_1                                  = -1608001,
    SAY_SLAY_2                                  = -1608002,
    SAY_SLAY_3                                  = -1608003,
    SAY_DEATH                                   = -1608004,
    SAY_SPAWN                                   = -1608005,
    SAY_DISRUPTION                              = -1608006,
    SAY_BREATH_ATTACK                           = -1608007,
    SAY_SPECIAL_ATTACK_1                        = -1608008,
    SAY_SPECIAL_ATTACK_2                        = -1608009
};

struct TRINITY_DLL_DECL boss_cyanigosaAI : public ScriptedAI
{
    boss_cyanigosaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    uint32 uiArcaneVacumTimer;
    uint32 uiBlizzardTimer;
    uint32 uiManaDestructionTimer;
    uint32 uiTailSweepTimer;
    uint32 uiUncontrollableEnergyTimer;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_CYANIGOSA_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_CYANIGOSA_EVENT, IN_PROGRESS);
    }
    
    void MoveInLineOfSight(Unit* who) {}
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;
        
        if (uiArcaneVacumTimer < diff)
        {
            DoCast(m_creature, SPELL_ARCANE_VACUM);
        } else uiArcaneVacumTimer -= diff;
        
        if (uiBlizzardTimer < diff)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (pTarget)
                DoCast(pTarget, HeroicMode ? H_SPELL_BLIZZARD : SPELL_BLIZZARD);
        } else uiBlizzardTimer -= diff;
        
        if (uiTailSweepTimer < diff)
        {
            DoCast(m_creature, HeroicMode ? H_SPELL_TAIL_SWEEP : SPELL_TAIL_SWEEP);
        } else uiTailSweepTimer -= diff;
        
        if (uiUncontrollableEnergyTimer < diff)
        {
            DoCast(m_creature->getVictim(), HeroicMode ? H_SPELL_UNCONTROLLABLE_ENERGY : SPELL_UNCONTROLLABLE_ENERGY);
        } else uiUncontrollableEnergyTimer -= diff;
        
        if (HeroicMode)
            if (uiManaDestructionTimer < diff)
            {
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget)
                    DoCast(pTarget, SPELL_MANA_DESTRUCTION);
            } else uiManaDestructionTimer -= diff;

        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_CYANIGOSA_EVENT, DONE);
    }
    
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_cyanigosa(Creature* pCreature)
{
    return new boss_cyanigosaAI (pCreature);
}

void AddSC_boss_cyanigosa()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_cyanigosa";
    newscript->GetAI = &GetAI_boss_cyanigosa;
    newscript->RegisterSelf();
}
