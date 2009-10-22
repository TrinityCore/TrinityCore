/* Script Data Start
SDName: Boss epoch
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CURSE_OF_EXERTION                   = 52772,
    SPELL_TIME_WARP                           = 52766, //Time slows down, reducing attack, casting and movement speed by 70% for 6 sec.
    SPELL_TIME_STOP                           = 58848, //Stops time in a 50 yard sphere for 2 sec.
    SPELL_WOUNDING_STRIKE                     = 52771, //Used only on the tank
    H_SPELL_WOUNDING_STRIKE                   = 58830
};

//not in db
enum Yells
{
    SAY_INTRO                                = -1595000, //"Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own."
    SAY_AGGRO                                = -1595001, //"We'll see about that, young prince."
    SAY_TIME_WARP_1                          = -1595002, //"Tick tock, tick tock..."
    SAY_TIME_WARP_2                          = -1595003, //"Not quick enough!"
    SAY_TIME_WARP_3                          = -1595004, //"Let's get this over with. "
    SAY_SLAY_1                               = -1595005, //"There is no future for you."
    SAY_SLAY_2                               = -1595006, //"This is the hour of our greatest triumph!"
    SAY_SLAY_3                               = -1595007, //"You were destined to fail. "
    SAY_DEATH                                = -1595008 //"*gurgles*"
};

struct TRINITY_DLL_DECL boss_epochAI : public ScriptedAI
{
    boss_epochAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_EPOCH_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_EPOCH_EVENT, IN_PROGRESS);
    }

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
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
            pInstance->SetData(DATA_EPOCH_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_epoch(Creature* pCreature)
{
    return new boss_epochAI (pCreature);
}

void AddSC_boss_epoch()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_epoch";
    newscript->GetAI = &GetAI_boss_epoch;
    newscript->RegisterSelf();
}
