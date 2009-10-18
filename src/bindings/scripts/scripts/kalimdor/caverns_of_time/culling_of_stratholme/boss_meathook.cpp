/* Script Data Start
SDName: Boss meathook
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_meathook' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_culling_of_stratholme.h"

enum Spells
{
    SPELL_CONSTRICTING_CHAINS                    = 52696, //Encases the targets in chains, dealing 1800 Physical damage every 1 sec. and stunning the target for 5 sec.
    H_SPELL_CONSTRICTING_CHAINS                  = 58823,
    SPELL_DISEASE_EXPULSION                      = 52666, //Meathook belches out a cloud of disease, dealing 1710 to 1890 Nature damage and interrupting the spell casting of nearby enemy targets for 4 sec.
    H_SPELL_DISEASE_EXPULSION                    = 58824,
    SPELL_FRENZY                                 = 58841 //Increases the caster's Physical damage by 10% for 30 sec.
};
//not in db
enum Yells
{
    SAY_AGGRO                                 = -1595026,
    SAY_SLAY_1                                = -1595027,
    SAY_SLAY_2                                = -1595028,
    SAY_SLAY_3                                = -1595029,
    SAY_SPAWN                                 = -1595030,
    SAY_DEATH                                 = -1595031
};

struct TRINITY_DLL_DECL boss_meathookAI : public ScriptedAI
{
    boss_meathookAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiChainTimer;
    uint32 uiDiseaseTimer;
    uint32 uiFrenzyTimer;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        uiChainTimer = urand(12000,17000);   //seen on video 13, 17, 15, 12, 16
        uiDiseaseTimer = urand(2000,3000);   //approx 3s
        uiFrenzyTimer = urand(20000,30000);  //made it up
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, IN_PROGRESS);
    }

    void AttackStart(Unit* who) {}

    void MoveInLineOfSight(Unit* who, const uint32 diff) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiDiseaseTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_DISEASE_EXPULSION,H_SPELL_DISEASE_EXPULSION));
            uiDiseaseTimer = urand(1500,4000);
        }else uiDiseaseTimer -= diff;

        if (uiFrenzyTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FRENZY);
            uiFrenzyTimer = urand(20000,30000);
        }else uiFrenzyTimer -= diff;

        if (uiChainTimer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 1), HEROIC(SPELL_CONSTRICTING_CHAINS,H_SPELL_CONSTRICTING_CHAINS)); //anyone but the tank
            uiChainTimer = urand(2000,3000);
        }else uiChainTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_meathook(Creature* pCreature)
{
    return new boss_meathookAI (pCreature);
}

void AddSC_boss_meathook()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_meathook";
    newscript->GetAI = &GetAI_boss_meathook;
    newscript->RegisterSelf();
}
