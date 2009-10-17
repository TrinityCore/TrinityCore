/* Script Data Start
SDName: Boss trollgore
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */
/*** SQL START ***
update creature_template set scriptname = 'boss_trollgore' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_drak_tharon_keep.h"
enum Spells
{
    SPELL_INFECTED_WOUND                          = 49637,
    SPELL_CRUSH                                   = 49639,
    SPELL_CORPSE_EXPLODE                          = 49555,
    SPELL_CONSUME                                 = 49380,
//Spell Heroic
    H_SPELL_CORPSE_EXPLODE                        = 59807,
    H_SPELL_CONSUME                               = 59803
};
//not in db
enum Yells
{
    SAY_AGGRO                                  = -1600006,
    SAY_KILL                                   = -1600007,
    SAY_CONSUME                                = -1600008,
    SAY_EXPLODE                                = -1600009,
    SAY_DEATH                                  = -1600010
};
struct TRINITY_DLL_DECL boss_trollgoreAI : public ScriptedAI
{
    boss_trollgoreAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    ScriptedInstance* pInstance;
    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_TROLLGORE_EVENT, NOT_STARTED);
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if (pInstance)
            pInstance->SetData(DATA_TROLLGORE_EVENT, IN_PROGRESS);
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
            pInstance->SetData(DATA_TROLLGORE_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};
CreatureAI* GetAI_boss_trollgore(Creature* pCreature)
{
    return new boss_trollgoreAI (pCreature);
}
void AddSC_boss_trollgore()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_trollgore";
    newscript->GetAI = &GetAI_boss_trollgore;
    newscript->RegisterSelf();
}
