/* Script Data Start
SDName: Boss Eck the Ferocious
SDAuthor: LordVanMartin
SD%Complete:
SDComment: Only appears in Heroic mode
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "gundrak.h"

enum Spells
{
    SPELL_ECK_BERSERK                       = 55816, //Eck goes berserk, increasing his attack speed by 150% and all damage he deals by 500%.
    SPELL_ECK_BITE                          = 55813, //Eck bites down hard, inflicting 150% of his normal damage to an enemy.
    SPELL_ECK_SPIT                          = 55814, //Eck spits toxic bile at enemies in a cone in front of him, inflicting 2970 Nature damage and draining 220 mana every 1 sec for 3 sec.
    SPELL_ECK_SPRING_1                      = 55815, //Eck leaps at a distant target.  --> Drops aggro and charges a random player. Tank can simply taunt him back.
    SPELL_ECK_SPRING_2                      = 55837  //Eck leaps at a distant target.
};
struct TRINITY_DLL_DECL boss_eckAI : public ScriptedAI
{
    boss_eckAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBerserkTimer;
    uint32 uiBiteTimer;
    uint32 uiSpitTimer;
    uint32 uiSpringTimer;

    bool bBerserk;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiBerserkTimer = 60000 + rand()%30000; //60-90 secs according to wowwiki
        uiBiteTimer = 5000;
        uiSpitTimer = 10000;
        uiSpringTimer = 8000;

        bBerserk = false;

        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ECK_BITE);
            uiBiteTimer = 8000 + rand()%4000;
        } else uiBiteTimer -= diff;

        if (uiSpitTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ECK_SPIT);
            uiSpitTimer = 6000 + rand()%8000;
        } else uiSpitTimer -= diff;

        if (uiSpringTimer < diff)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
            if(pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(pTarget,RAND(SPELL_ECK_SPRING_1,SPELL_ECK_SPRING_2));
                uiSpringTimer = 5000 + rand()%10000;
            }
        } else uiSpringTimer -= diff;

        //Berserk on timer or 20% of health
        if (!bBerserk)
        {
            if (uiBerserkTimer < diff)
            {
                DoCast(m_creature,SPELL_ECK_BERSERK);
                bBerserk = true;
            }
            else
            {
                uiBerserkTimer -= diff;
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 20)
                {
                    DoCast(m_creature,SPELL_ECK_BERSERK);
                    bBerserk = true;
                }
            }
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_eck(Creature* pCreature)
{
    return new boss_eckAI (pCreature);
}

void AddSC_boss_eck()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_eck";
    newscript->GetAI = &GetAI_boss_eck;
    newscript->RegisterSelf();
}
