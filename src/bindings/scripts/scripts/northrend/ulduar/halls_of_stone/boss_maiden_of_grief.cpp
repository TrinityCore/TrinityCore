/* Script Data Start
SDName: Boss maiden_of_grief
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_maiden_of_grief' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spell
#define SPELL_PARTING_SORROW                                59723
#define SPELL_STORM_OF_GRIEF_N                              50752
#define SPELL_STORM_OF_GRIEF_H                              59772
#define SPELL_SHOCK_OF_SORROW_N                             50760
#define SPELL_SHOCK_OF_SORROW_H                             59726
#define SPELL_PILLAR_OF_WOE_N                               50761
#define SPELL_PILLAR_OF_WOE_H                               59727

//not in db
//Yell
#define SAY_AGGRO                                        -1603000
#define SAY_SLAY_1                                       -1603001
#define SAY_SLAY_2                                       -1603002
#define SAY_SLAY_3                                       -1603003
#define SAY_SLAY_4                                       -1603004
#define SAY_DEATH                                        -1603005
#define SAY_STUN                                         -1603006

struct TRINITY_DLL_DECL boss_maiden_of_griefAI : public ScriptedAI
{
    boss_maiden_of_griefAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = m_creature->GetInstanceData();
        IsHeroic = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool IsHeroic;

    uint32 PartingSorrowTimer;
    uint32 StormOfGriefTimer;
    uint32 ShockOfSorrowTimer;
    uint32 PillarOfWoeTimer;

    void Reset() 
    {
        PartingSorrowTimer = 25000 + rand()%5000;
        StormOfGriefTimer = 10000;
        ShockOfSorrowTimer = 20000+rand()%5000;
        PillarOfWoeTimer = 5000 + rand()%10000;

        //Missing support for instance data (and door?)
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        //Missing support for instance data (and door?)
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if(IsHeroic)
        {
            if (PartingSorrowTimer < diff)
            {
                Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if(target)
                    DoCast(target,SPELL_PARTING_SORROW);

                PartingSorrowTimer = 30000 + rand()%10000;
            }else PartingSorrowTimer -= diff;
        }

        if (StormOfGriefTimer < diff)
        {
            DoCast(m_creature->getVictim(),IsHeroic ? SPELL_STORM_OF_GRIEF_H : SPELL_STORM_OF_GRIEF_N, true);
            StormOfGriefTimer = 15000 + rand()%5000;
        }else StormOfGriefTimer -= diff;

        if (ShockOfSorrowTimer < diff)
        {
            DoResetThreat();
            DoScriptText(SAY_STUN, m_creature);
            DoCast(m_creature,IsHeroic ? SPELL_SHOCK_OF_SORROW_H : SPELL_SHOCK_OF_SORROW_N);
            ShockOfSorrowTimer = 20000 + rand()%10000;
        }else ShockOfSorrowTimer -= diff;

        if (PillarOfWoeTimer < diff)
        {
            Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 1);

            if(target)
                DoCast(target,IsHeroic ? SPELL_PILLAR_OF_WOE_H : SPELL_PILLAR_OF_WOE_N);
            else
                DoCast(m_creature->getVictim(),IsHeroic ? SPELL_PILLAR_OF_WOE_H : SPELL_PILLAR_OF_WOE_N);

            PillarOfWoeTimer = 5000 + rand()%20000;
        }else PillarOfWoeTimer -= diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        //Missing support for instance data (and door?)
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        switch(rand()%4)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
            case 3: DoScriptText(SAY_SLAY_4, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_maiden_of_grief(Creature* pCreature)
{
    return new boss_maiden_of_griefAI (pCreature);
}

void AddSC_boss_maiden_of_grief()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_maiden_of_grief";
    newscript->GetAI = &GetAI_boss_maiden_of_grief;
    newscript->RegisterSelf();
}
