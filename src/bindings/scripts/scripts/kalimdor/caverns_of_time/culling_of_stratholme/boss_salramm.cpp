/* Script Data Start
SDName: Boss salramm
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_salramm' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_culling_of_stratholme.h"

enum Spells
{
    SPELL_CURSE_OF_TWISTED_FLESH                = 58845,
    SPELL_EXPLODE_GHOUL                         = 52480,
    H_SPELL_EXPLODE_GHOUL                       = 58825,
    SPELL_SHADOW_BOLT                           = 57725,
    H_SPELL_SHADOW_BOLT                         = 58828,
    SPELL_STEAL_FLESH                           = 52708,
    SPELL_SUMMON_GHOULS                         = 52451
};

//not in db
enum Yells
{
    SAY_AGGRO                                = -1595032,
    SAY_SPAWN                                = -1595033,
    SAY_SLAY_1                               = -1595034,
    SAY_SLAY_2                               = -1595035,
    SAY_SLAY_3                               = -1595036,
    SAY_DEATH                                = -1595037,
    SAY_EXPLODE_GHOUL_1                      = -1595038,
    SAY_EXPLODE_GHOUL_2                      = -1595039,
    SAY_STEAL_FLESH_1                        = -1595040,
    SAY_STEAL_FLESH_2                        = -1595041,
    SAY_STEAL_FLESH_3                        = -1595042,
    SAY_SUMMON_GHOULS_1                      = -1595043,
    SAY_SUMMON_GHOULS_2                      = -1595044
};

struct TRINITY_DLL_DECL boss_salrammAI : public ScriptedAI
{
    boss_salrammAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 Curse_flesh_Timer;
    uint32 Explode_ghoul_Timer;
    uint32 Shadow_bolt_Timer;
    uint32 Steal_flesh_Timer;
    uint32 Summon_ghouls_Timer;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
         Curse_flesh_Timer = 30000;  //30s DBM
         Explode_ghoul_Timer = urand(25000,28000); //approx 6 sec after summon ghouls
         Shadow_bolt_Timer = urand(8000,12000); // approx 10s
         Steal_flesh_Timer = 12345;
         Summon_ghouls_Timer = urand(19000,24000); //on a video approx 24s after aggro
         
         if (pInstance)
             pInstance->SetData(DATA_SALRAMM_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
             pInstance->SetData(DATA_SALRAMM_EVENT, IN_PROGRESS);
    }

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Curse of twisted flesh timer
        if (Curse_flesh_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSE_OF_TWISTED_FLESH);
            Curse_flesh_Timer = 37000;
        }else Curse_flesh_Timer -= diff;

        //Shadow bolt timer
        if (Shadow_bolt_Timer < diff)
        {
            if (Unit* random_target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(random_target, HEROIC(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
            Shadow_bolt_Timer = urand(8000,12000);
        }else Shadow_bolt_Timer -= diff;

        //Steal Flesh timer
        if (Steal_flesh_Timer < diff)
        {
            DoScriptText(RAND(SAY_STEAL_FLESH_1,SAY_STEAL_FLESH_2,SAY_STEAL_FLESH_3), m_creature);
            if (Unit* random_target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(random_target,SPELL_STEAL_FLESH);
            Steal_flesh_Timer = 10000;
        }else Steal_flesh_Timer -= diff;

        //Summon ghouls timer
        if (Summon_ghouls_Timer < diff)
        {
            DoScriptText(RAND(SAY_SUMMON_GHOULS_1,SAY_SUMMON_GHOULS_2), m_creature);
            if (Unit* random_target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(random_target,SPELL_SUMMON_GHOULS);
            Summon_ghouls_Timer = 10000;
        }else Summon_ghouls_Timer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_SALRAMM_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_salramm(Creature* pCreature)
{
    return new boss_salrammAI (pCreature);
}

void AddSC_boss_salramm()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_salramm";
    newscript->GetAI = &GetAI_boss_salramm;
    newscript->RegisterSelf();
}
