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

//Spells
#define SPELL_CURSE_OF_TWISTED_FLESH                58845
#define SPELL_EXPLODE_GHOUL_N                       52480
#define SPELL_EXPLODE_GHOUL_H                       58825
#define SPELL_SHADOW_BOLT_N                         57725
#define SPELL_SHADOW_BOLT_H                         58828
#define SPELL_STEAL_FLESH                           52708
#define SPELL_SUMMON_GHOULS                         52451

//Yell
#define SAY_AGGRO                                -1595032
#define SAY_SPAWN                                -1595033
#define SAY_SLAY_1                               -1595034
#define SAY_SLAY_2                               -1595035
#define SAY_SLAY_3                               -1595036
#define SAY_DEATH                                -1595037
#define SAY_EXPLODE_GHOUL_1                      -1595038
#define SAY_EXPLODE_GHOUL_2                      -1595039
#define SAY_STEAL_FLESH_1                        -1595040
#define SAY_STEAL_FLESH_2                        -1595041
#define SAY_STEAL_FLESH_3                        -1595042
#define SAY_SUMMON_GHOULS_1                      -1595043
#define SAY_SUMMON_GHOULS_2                      -1595044

struct TRINITY_DLL_DECL boss_salrammAI : public ScriptedAI
{
    boss_salrammAI(Creature *c) : ScriptedAI(c) {}

    uint32 Curse_flesh_Timer,
           Explode_ghoul_Timer,
           Shadow_bolt_Timer,
           Steal_flesh_Timer,
           Summon_ghouls_Timer;

    void Reset()
    {
         Curse_flesh_Timer =   30000;  //30s DBM
         Explode_ghoul_Timer = 25000 + rand()%3000; //approx 6 sec after summon ghouls
         Shadow_bolt_Timer =   8000  + rand()%4000; // approx 10s
         Steal_flesh_Timer =   12345;
         Summon_ghouls_Timer = 19000 + rand()%5000; //on a video approx 24s after aggro
    }

    void EnterCombat(Unit* who)
        {DoScriptText(SAY_AGGRO, m_creature);}

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        Unit* random_target = SelectUnit(SELECT_TARGET_RANDOM, 0);

        //Curse of twisted flesh timer
        if (Curse_flesh_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSE_OF_TWISTED_FLESH);
            Curse_flesh_Timer = 37000;
        }else Curse_flesh_Timer -= diff;

        //Shadow bolt timer
        if (Shadow_bolt_Timer < diff)
        {
            if(random_target)
                DoCast(random_target,SPELL_SHADOW_BOLT_N);
            Shadow_bolt_Timer = 8000 + rand()%4000;
        }else Shadow_bolt_Timer -= diff;

        //Steal Flesh timer
        if (Steal_flesh_Timer < diff)
        {
            switch(rand()%3)
            {
                case 0:
                    DoScriptText(SAY_STEAL_FLESH_1, m_creature);
                    break;
                case 1:
                    DoScriptText(SAY_STEAL_FLESH_2, m_creature);
                    break;
                case 2:
                    DoScriptText(SAY_STEAL_FLESH_3, m_creature);
                    break;
            }
            if(random_target)
                DoCast(random_target,SPELL_STEAL_FLESH);
            Steal_flesh_Timer = 10000;
        }else Steal_flesh_Timer -= diff;

        //Summon ghouls timer
        if (Summon_ghouls_Timer < diff)
        {
            switch(rand()%2)
            {
                case 0:
                    DoScriptText(SAY_SUMMON_GHOULS_1, m_creature);
                    break;
                case 1:
                    DoScriptText(SAY_SUMMON_GHOULS_2, m_creature);
                    break;
            }
            if(random_target)
                DoCast(random_target,SPELL_SUMMON_GHOULS);
            Summon_ghouls_Timer = 10000;
        }else Summon_ghouls_Timer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {DoScriptText(SAY_DEATH, m_creature);}

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_salramm(Creature *_Creature)
{
    return new boss_salrammAI (_Creature);
}

void AddSC_boss_salramm()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_salramm";
    newscript->GetAI = &GetAI_boss_salramm;
    newscript->RegisterSelf();
}
