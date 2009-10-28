/* Script Data Start
SDName: Boss moorabi
SDAuthor: Manuel
SD%Complete: 100%
SDComment: Maybe needs better timers.
SDCategory: Gundrak
Script Data End */

#include "precompiled.h"
#include "gundrak.h"

//Spells

#define SPELL_DETERMINED_STAB                        55104
#define SPELL_GROUND_TREMOR                          55142
#define SPELL_NUMBING_SHOUT                          55106

#define SPELL_DETERMINED_GORE                        55102
#define SPELL_DETERMINED_GORE_1                      59444
#define SPELL_QUAKE                                  55101
#define SPELL_NUMBING_ROAR                           55100

#define SPELL_MOJO_FRENZY                            55163
#define SPELL_TRANSFORMATION                         55098 //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.

#define ACHIEVEMENT_LESS_RABI                         2040

//Yell
#define SAY_AGGRO                                 -1604010
//#define SAY_SLAY_1                                -1604011 // not in db
#define SAY_SLAY_2                                -1604012
#define SAY_SLAY_3                                -1604013
#define SAY_DEATH                                 -1604014
#define SAY_TRANSFORM                             -1604015
#define SAY_QUAKE                                 -1604016
#define EMOTE_TRANSFORM                           -1604017

struct TRINITY_DLL_DECL boss_moorabiAI : public ScriptedAI
{
    boss_moorabiAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    bool Phase;
    uint32 SPELL_QUAKE_TIMER;
    uint32 SPELL_NUMBING_SHOUT_TIMER;
    uint32 SPELL_GROUND_TREMOR_TIMER;
    uint32 SPELL_DETERMINED_STAB_TIMER;
    uint32 SPELL_TRANSFORMATION_TIMER;

    void Reset()
    {
          SPELL_GROUND_TREMOR_TIMER = 18000;
          SPELL_NUMBING_SHOUT_TIMER =  10000;
          SPELL_DETERMINED_STAB_TIMER = 20000;
          SPELL_TRANSFORMATION_TIMER = 12000;
          Phase = false;

          if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->CastSpell(m_creature,SPELL_MOJO_FRENZY,true);

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
         if (!UpdateVictim())
             return;

        if(Phase == false && m_creature->HasAura(SPELL_TRANSFORMATION))
            Phase = true;

        if(Phase == true)
        {
            m_creature->RemoveAura(SPELL_MOJO_FRENZY);

            if (SPELL_GROUND_TREMOR_TIMER <= diff)
            {
                DoScriptText(SAY_QUAKE, m_creature);
                m_creature->CastSpell(m_creature->getVictim(),SPELL_QUAKE,true);
                SPELL_GROUND_TREMOR_TIMER = 10000;
            } else SPELL_GROUND_TREMOR_TIMER -= diff;

            if (SPELL_NUMBING_SHOUT_TIMER <= diff)
            {
                m_creature->CastSpell(m_creature->getVictim(),SPELL_NUMBING_ROAR,true);
                SPELL_NUMBING_SHOUT_TIMER = 10000;
            } else SPELL_NUMBING_SHOUT_TIMER -=diff;

            if (SPELL_DETERMINED_STAB_TIMER <= diff)
            {
                DoCast(m_creature->getVictim(), HEROIC(SPELL_DETERMINED_GORE, SPELL_DETERMINED_GORE_1));
                SPELL_DETERMINED_STAB_TIMER = 8000;
            } else SPELL_DETERMINED_STAB_TIMER -=diff;
        }
        else
        {
            //CAST TRANSFORMATION
            if (SPELL_TRANSFORMATION_TIMER <= diff)
            {
                DoScriptText(EMOTE_TRANSFORM, m_creature);
                DoScriptText(SAY_TRANSFORM, m_creature);
                m_creature->CastSpell(m_creature,SPELL_TRANSFORMATION,false);
                SPELL_TRANSFORMATION_TIMER = 10000;
            } else SPELL_TRANSFORMATION_TIMER -= diff;

            //CAST GROUND TERMOR || QUAKE
            if (SPELL_GROUND_TREMOR_TIMER <= diff)
            {
                DoScriptText(SAY_QUAKE, m_creature);
                m_creature->CastSpell(m_creature->getVictim(),SPELL_GROUND_TREMOR,true);
                SPELL_GROUND_TREMOR_TIMER = 10000;
            } else SPELL_GROUND_TREMOR_TIMER -= diff;

            //CAST NUMBING SHOUT || DETERMINED_STAB
            if (SPELL_NUMBING_SHOUT_TIMER <= diff)
            {
                m_creature->CastSpell(m_creature->getVictim(),SPELL_NUMBING_SHOUT,true);
                SPELL_NUMBING_SHOUT_TIMER = 10000;
            } else SPELL_NUMBING_SHOUT_TIMER -= diff;

            if (SPELL_DETERMINED_STAB_TIMER <= diff)
            {
                m_creature->CastSpell(m_creature->getVictim(),SPELL_DETERMINED_STAB,true);
                SPELL_DETERMINED_STAB_TIMER = 8000;
            } else SPELL_DETERMINED_STAB_TIMER -= diff;
        }

         DoMeleeAttackIfReady();
     }
     void JustDied(Unit *killer)
     {
         DoScriptText(SAY_DEATH, m_creature);

        if (HeroicMode && Phase == false)
        {
            AchievementEntry const *AchievLessRabi = GetAchievementStore()->LookupEntry(ACHIEVEMENT_LESS_RABI);
            if (AchievLessRabi)
            {
                Map *pMap = m_creature->GetMap();
                if (pMap && pMap->IsDungeon())
                {
                    Map::PlayerList const &players = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievLessRabi);
                }
            }
        }

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI *GetAI_boss_moorabi(Creature *pCreature)
{
    return new boss_moorabiAI(pCreature);
}

void AddSC_boss_moorabi()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_moorabi";
    newscript->GetAI = &GetAI_boss_moorabi;
    newscript->RegisterSelf();
}
