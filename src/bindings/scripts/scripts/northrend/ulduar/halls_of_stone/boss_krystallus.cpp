/* Script Data Start
SDName: Boss krystallus
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_krystallus' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_BOULDER_TOSS                             = 50843,
    H_SPELL_BOULDER_TOSS                           = 59742,
    SPELL_GROUND_SPIKE                             = 59750,
    SPELL_GROUND_SLAM                              = 50827,
    SPELL_SHATTER                                  = 50810,
    H_SPELL_SHATTER                                = 61546,
    SPELL_STOMP                                    = 48131,
    H_SPELL_STOMP                                  = 59744
};

enum Yells
{
    SAY_AGGRO                                   = -1603007,
    SAY_KILL                                    = -1603008,
    SAY_DEATH                                   = -1603009,
    SAY_SHATTER                                 = -1603010
};

struct TRINITY_DLL_DECL boss_krystallusAI : public ScriptedAI
{
    boss_krystallusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBoulderTossTimer;
    uint32 uiGroundSpikeTimer;
    uint32 uiGroundSlamTimer;
    uint32 uiShatterTimer;
    uint32 uiStompTimer;

    bool bIsSlam;

    ScriptedInstance* pInstance;

    void Reset()
    {
        bIsSlam = false;

        uiBoulderTossTimer = 3000 + rand()%6000;
        uiGroundSpikeTimer = 9000 + rand()%5000;
        uiGroundSlamTimer = 15000 + rand()%3000;
        uiStompTimer = 20000 + rand()%9000;
        uiShatterTimer = 0;

        if (pInstance)
            pInstance->SetData(DATA_KRYSTALLUS_EVENT, NOT_STARTED);
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_KRYSTALLUS_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiBoulderTossTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, HEROIC(SPELL_BOULDER_TOSS, H_SPELL_BOULDER_TOSS));
            uiBoulderTossTimer = 9000 + rand()%6000;
        } else uiBoulderTossTimer -= diff;

        if (uiGroundSpikeTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_GROUND_SPIKE);
            uiGroundSpikeTimer = 12000 + rand()%5000;
        } else uiGroundSpikeTimer -= diff;

        if (uiStompTimer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_STOMP, H_SPELL_STOMP));
            uiStompTimer = 20000 + rand()%9000;
        } else uiStompTimer -= diff;

        if (uiGroundSlamTimer < diff)
        {
            DoCast(m_creature, SPELL_GROUND_SLAM);
            bIsSlam = true;
            uiShatterTimer = 10000;
            uiGroundSlamTimer = 15000 + rand()%3000;
        } else uiGroundSlamTimer -= diff;

        if (bIsSlam)
        {
            if(uiShatterTimer < diff)
            {
                DoCast(m_creature, HEROIC(SPELL_SHATTER, H_SPELL_SHATTER));
                bIsSlam = false;
            } else uiShatterTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_KRYSTALLUS_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_krystallus(Creature* pCreature)
{
    return new boss_krystallusAI (pCreature);
}

void AddSC_boss_krystallus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_krystallus";
    newscript->GetAI = &GetAI_boss_krystallus;
    newscript->RegisterSelf();
}
