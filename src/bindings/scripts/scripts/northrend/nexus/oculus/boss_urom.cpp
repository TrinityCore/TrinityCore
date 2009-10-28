/* Script Data Start
SDName: Boss urom
SDAuthor: LordVanMartin
SD%Complete:  1%
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "oculus.h"

enum Spells
{
    SPELL_ARCANE_SHIELD                      = 53813, //Dummy --> Channeled, shields the caster from damage.
    SPELL_EMPOWERED_ARCANE_EXPLOSION         = 51110,
    SPELL_EMPOWERED_ARCANE_EXPLOSION_2       = 59377,
    SPELL_FROSTBOMB                          = 51103, //Urom throws a bomb, hitting its target with the highest aggro which inflict directly 650 frost damage and drops a frost zone on the ground. This zone deals 650 frost damage per second and reduce the movement speed by 35%. Lasts 1 minute.
    SPELL_SUMMON_MENAGERIE                   = 50476, //Summons an assortment of creatures and teleports the caster to safety.
    SPELL_SUMMON_MENAGERIE_2                 = 50495,
    SPELL_SUMMON_MENAGERIE_3                 = 50496,
    SPELL_TELEPORT                           = 51112, //Teleports to the center of Oculus
    SPELL_TIME_BOMB                          = 51121, //Deals arcane damage to a random player, and after 6 seconds, deals zone damage to nearby equal to the health missing of the target afflicted by the debuff.
    SPELL_TIME_BOMB_2                        = 59376
};
//not in db
enum Yells
{
    SAY_AGGRO                             = -1578012,
    SAY_KILL_1                            = -1578013,
    SAY_KILL_2                            = -1578014,
    SAY_KILL_3                            = -1578015,
    SAY_DEATH                             = -1578016,
    SAY_EXPLOSION_1                       = -1578017,
    SAY_EXPLOSION_2                       = -1578018,
    SAY_SUMMON_1                          = -1578019,
    SAY_SUMMON_2                          = -1578020,
    SAY_SUMMON_3                          = -1578021
};

struct TRINITY_DLL_DECL boss_uromAI : public ScriptedAI
{
    boss_uromAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_UROM_EVENT, NOT_STARTED);
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_UROM_EVENT, IN_PROGRESS);
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
            pInstance->SetData(DATA_UROM_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), m_creature);
    }
};

CreatureAI* GetAI_boss_urom(Creature* pCreature)
{
    return new boss_uromAI (pCreature);
}

void AddSC_boss_urom()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_urom";
    newscript->GetAI = &GetAI_boss_urom;
    newscript->RegisterSelf();
}
