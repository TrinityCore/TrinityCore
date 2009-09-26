/* Script Data Start
SDName: Boss gal_darah
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_gundrak.h"

//Spells
enum Spells
{
    SPELL_ENRAGE                                  = 55285,
    SPELL_IMPALING_CHARGE                         = 54956,
    SPELL_STOMP                                   = 55292,
    SPELL_PUNCTURE                                = 55276,
    SPELL_STAMPEDE                                = 55218,
    SPELL_WHIRLING_SLASH                          = 55249,
    H_SPELL_WHIRLING_SLASH                        = 55825
};

//Yells
enum Yells
{
    SAY_AGGRO                                  = -1604000,
    SAY_SLAY_1                                 = -1604001,
    SAY_SLAY_2                                 = -1604002,
    SAY_SLAY_3                                 = -1604003,
    SAY_DEATH                                  = -1604004,
    SAY_SUMMON_RHINO_1                         = -1604005,
    SAY_SUMMON_RHINO_2                         = -1604006,
    SAY_SUMMON_RHINO_3                         = -1604007,
    SAY_TRANSFORM_1                            = -1604008,  //Phase change
    SAY_TRANSFORM_2                            = -1604009
};

struct TRINITY_DLL_DECL boss_gal_darahAI : public ScriptedAI
{
    boss_gal_darahAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_GAL_DARAH_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_GAL_DARAH_EVENT, IN_PROGRESS);
    }
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_GAL_DARAH_EVENT, DONE);
    }
    
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_gal_darah(Creature* pCreature)
{
    return new boss_gal_darahAI (pCreature);
}

void AddSC_boss_gal_darah()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_gal_darah";
    newscript->GetAI = &GetAI_boss_gal_darah;
    newscript->RegisterSelf();
}
