/* Script Data Start
SDName: Boss moorabi
SDAuthor: Manuel
SD%Complete: 100%
SDComment: Maybe needs better timers.
SDCategory: Gundrak
Script Data End */

#include "ScriptedPch.h"
#include "gundrak.h"

enum eSpells
{
    SPELL_DETERMINED_STAB       =   55104,
    SPELL_GROUND_TREMOR         =   55142,
    SPELL_NUMBING_SHOUT         =   55106,

    SPELL_DETERMINED_GORE       =   55102,
    SPELL_DETERMINED_GORE_1     =   59444,
    SPELL_QUAKE                 =   55101,
    SPELL_NUMBING_ROAR          =   55100,

    SPELL_MOJO_FRENZY           =   55163,
    SPELL_TRANSFORMATION        =   55098, //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
};

enum eArchivements
{
    ACHIEVEMENT_LESS_RABI       =   2040
};

enum eSays
{
    SAY_AGGRO                   =   -1604010,
    //SAY_SLAY_1                =   -1604011, // not in db
    SAY_SLAY_2                  =   -1604012,
    SAY_SLAY_3                  =   -1604013,
    SAY_DEATH                   =   -1604014,
    SAY_TRANSFORM               =   -1604015,
    SAY_QUAKE                   =   -1604016,
    EMOTE_TRANSFORM             =   -1604017
};

struct TRINITY_DLL_DECL boss_moorabiAI : public ScriptedAI
{
    boss_moorabiAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool bPhase;

    uint32 uiNumblingShoutTimer;
    uint32 uiGroundTremorTimer;
    uint32 uiDeterminedStabTimer;
    uint32 uiTransformationTImer;

    void Reset()
    {
        uiGroundTremorTimer = 18000;
        uiNumblingShoutTimer =  10000;
        uiDeterminedStabTimer = 20000;
        uiTransformationTImer = 12000;
        bPhase = false;

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCast(m_creature, SPELL_MOJO_FRENZY, true);

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
         if (!UpdateVictim())
             return;

        if(!bPhase && m_creature->HasAura(SPELL_TRANSFORMATION))
        {
            bPhase = true;
            m_creature->RemoveAura(SPELL_MOJO_FRENZY);
        }

        if (uiGroundTremorTimer <= uiDiff)
        {
            DoScriptText(SAY_QUAKE, m_creature);
            if (bPhase)
                DoCast(m_creature->getVictim(), SPELL_QUAKE, true);
            else
                DoCast(m_creature->getVictim(), SPELL_GROUND_TREMOR, true);
            uiGroundTremorTimer = 10000;
        } else uiGroundTremorTimer -= uiDiff;

        if (uiNumblingShoutTimer <= uiDiff)
        {
            if (bPhase)
                DoCast(m_creature->getVictim(), SPELL_NUMBING_ROAR, true);
            else
                DoCast(m_creature->getVictim(), SPELL_NUMBING_SHOUT, true);
            uiNumblingShoutTimer = 10000;
        } else uiNumblingShoutTimer -=uiDiff;

        if (uiDeterminedStabTimer <= uiDiff)
        {
            if (bPhase)
                DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_DETERMINED_GORE, SPELL_DETERMINED_GORE_1));
            else
                DoCast(m_creature->getVictim(), SPELL_DETERMINED_STAB, true);
            uiDeterminedStabTimer = 8000;
        } else uiDeterminedStabTimer -=uiDiff;

        if (!bPhase && uiTransformationTImer <= uiDiff)
        {
            DoScriptText(EMOTE_TRANSFORM, m_creature);
            DoScriptText(SAY_TRANSFORM, m_creature);
            DoCast(m_creature, SPELL_TRANSFORMATION, false);
            uiTransformationTImer = 10000;
        } else uiTransformationTImer -= uiDiff;

        DoMeleeAttackIfReady();
     }

     void JustDied(Unit* pKiller)
     {
        DoScriptText(SAY_DEATH, m_creature);

        if (IsHeroic() && !bPhase)
        {
            AchievementEntry const *AchievLessRabi = GetAchievementStore()->LookupEntry(ACHIEVEMENT_LESS_RABI);
            if (AchievLessRabi)
            {
                Map* pMap = m_creature->GetMap();
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

    void KilledUnit(Unit* pVictim)
    {
        if (pVictim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_moorabi(Creature *pCreature)
{
    return new boss_moorabiAI(pCreature);
}

void AddSC_boss_moorabi()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_moorabi";
    newscript->GetAI = &GetAI_boss_moorabi;
    newscript->RegisterSelf();
}
