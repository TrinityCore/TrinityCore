/* Script Data Start
SDName: Boss mal_ganis
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_mal_ganis' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CARRION_SWARM                           = 52720, //A cresting wave of chaotic magic splashes over enemies in front of the caster, dealing 3230 to 3570 Shadow damage and 380 to 420 Shadow damage every 3 sec. for 15 sec.
    H_SPELL_CARRION_SWARM                         = 58852,
    SPELL_MIND_BLAST                              = 52722, //Inflicts 4163 to 4837 Shadow damage to an enemy.
    H_SPELL_MIND_BLAST                            = 58850,
    SPELL_SLEEP                                   = 52721, //Puts an enemy to sleep for up to 10 sec. Any damage caused will awaken the target.
    SPELL_VAMPIRIC_TOUCH                          = 52723 //Heals the caster for half the damage dealt by a melee attack.
};

//not in db
enum Yells
{
    SAY_INTRO_1                                  = -1595009,
    SAY_INTRO_2                                  = -1595010,
    SAY_OUTRO                                    = -1595011,
    SAY_AGGRO                                    = -1595012,
    SAY_KILL_1                                   = -1595013,
    SAY_KILL_2                                   = -1595014,
    SAY_KILL_3                                   = -1595015,
    SAY_SLAY_1                                   = -1595016,
    SAY_SLAY_2                                   = -1595017,
    SAY_SLAY_3                                   = -1595018,
    SAY_SLAY_4                                   = -1595019,
    SAY_SLEEP_1                                  = -1595020,
    SAY_SLEEP_2                                  = -1595021,
    SAY_30HEALTH                                 = -1595022,
    SAY_15HEALTH                                 = -1595023,
    SAY_ESCAPE_SPEECH_1                          = -1595024,
    SAY_ESCAPE_SPEECH_2                          = -1595025
};

struct TRINITY_DLL_DECL boss_mal_ganisAI : public ScriptedAI
{
    boss_mal_ganisAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    bool yelled,
         yelled2,
         yelled3;
         
    ScriptedInstance* pInstance;

    void Reset()
    {
         yelled = false;
         yelled2 = false;
         yelled3 = false;
         
         if (pInstance)
             pInstance->SetData(DATA_MAL_GANIS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
             pInstance->SetData(DATA_MAL_GANIS_EVENT, IN_PROGRESS);
    }

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!yelled)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 30)
            {
                DoScriptText(SAY_30HEALTH, m_creature);
                yelled = true;
            }
        }

        if (!yelled2)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 15)
            {
                DoScriptText(SAY_15HEALTH, m_creature);
                yelled2 = true;
            }
        }

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 1)
        {
            //Handle Escape Event
        }

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        if (pInstance)
             pInstance->SetData(DATA_MAL_GANIS_EVENT, NOT_STARTED);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3,SAY_SLAY_4), m_creature);
    }
};

CreatureAI* GetAI_boss_mal_ganis(Creature* pCreature)
{
    return new boss_mal_ganisAI (pCreature);
}

void AddSC_boss_mal_ganis()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_mal_ganis";
    newscript->GetAI = &GetAI_boss_mal_ganis;
    newscript->RegisterSelf();
}
