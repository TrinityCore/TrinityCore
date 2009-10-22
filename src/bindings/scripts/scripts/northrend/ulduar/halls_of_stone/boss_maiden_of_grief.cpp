/* Script Data Start
SDName: Boss maiden_of_grief
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_maiden_of_grief' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_PARTING_SORROW                                = 59723,
    SPELL_STORM_OF_GRIEF_N                              = 50752,
    SPELL_STORM_OF_GRIEF_H                              = 59772,
    SPELL_SHOCK_OF_SORROW_N                             = 50760,
    SPELL_SHOCK_OF_SORROW_H                             = 59726,
    SPELL_PILLAR_OF_WOE_N                               = 50761,
    SPELL_PILLAR_OF_WOE_H                               = 59727
};

enum Yells
{
    SAY_AGGRO                                        = -1603000,
    SAY_SLAY_1                                       = -1603001,
    SAY_SLAY_2                                       = -1603002,
    SAY_SLAY_3                                       = -1603003,
    SAY_SLAY_4                                       = -1603004,
    SAY_DEATH                                        = -1603005,
    SAY_STUN                                         = -1603006
};

enum Achievements
{
    ACHIEVEMENT_GOOD_GRIEF                           = 1866
};

struct TRINITY_DLL_DECL boss_maiden_of_griefAI : public ScriptedAI
{
    boss_maiden_of_griefAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = m_creature->GetInstanceData();
        IsHeroic = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool IsHeroic;

    uint32 PartingSorrowTimer;
    uint32 StormOfGriefTimer;
    uint32 ShockOfSorrowTimer;
    uint32 PillarOfWoeTimer;
    uint32 AchievTimer;

    void Reset()
    {
        PartingSorrowTimer = 25000 + rand()%5000;
        StormOfGriefTimer = 10000;
        ShockOfSorrowTimer = 20000+rand()%5000;
        PillarOfWoeTimer = 5000 + rand()%10000;
        AchievTimer = 0;

        if (pInstance)
            pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Achievement counter
        if (pInstance)
            if (pInstance->GetData(DATA_MAIDEN_OF_GRIEF_EVENT) == IN_PROGRESS)
                AchievTimer += diff;

        if(IsHeroic)
        {
            if (PartingSorrowTimer < diff)
            {
                Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if(target)
                    DoCast(target,SPELL_PARTING_SORROW);

                PartingSorrowTimer = 30000 + rand()%10000;
            }else PartingSorrowTimer -= diff;
        }

        if (StormOfGriefTimer < diff)
        {
            DoCast(m_creature->getVictim(),IsHeroic ? SPELL_STORM_OF_GRIEF_H : SPELL_STORM_OF_GRIEF_N, true);
            StormOfGriefTimer = 15000 + rand()%5000;
        }else StormOfGriefTimer -= diff;

        if (ShockOfSorrowTimer < diff)
        {
            DoResetThreat();
            DoScriptText(SAY_STUN, m_creature);
            DoCast(m_creature,IsHeroic ? SPELL_SHOCK_OF_SORROW_H : SPELL_SHOCK_OF_SORROW_N);
            ShockOfSorrowTimer = 20000 + rand()%10000;
        }else ShockOfSorrowTimer -= diff;

        if (PillarOfWoeTimer < diff)
        {
            Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 1);

            if(target)
                DoCast(target,IsHeroic ? SPELL_PILLAR_OF_WOE_H : SPELL_PILLAR_OF_WOE_N);
            else
                DoCast(m_creature->getVictim(),IsHeroic ? SPELL_PILLAR_OF_WOE_H : SPELL_PILLAR_OF_WOE_N);

            PillarOfWoeTimer = 5000 + rand()%20000;
        }else PillarOfWoeTimer -= diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, DONE);

        AchievementEntry const *AchievGoodGrief = GetAchievementStore()->LookupEntry(ACHIEVEMENT_GOOD_GRIEF);
        Map* pMap = m_creature->GetMap();

        if (HeroicMode && AchievTimer < 60000 && pMap && pMap->IsDungeon() && AchievGoodGrief)
        {
            Map::PlayerList const &players = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievGoodGrief);
        }
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3,SAY_SLAY_4), m_creature);
    }
};

CreatureAI* GetAI_boss_maiden_of_grief(Creature* pCreature)
{
    return new boss_maiden_of_griefAI (pCreature);
}

void AddSC_boss_maiden_of_grief()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_maiden_of_grief";
    newscript->GetAI = &GetAI_boss_maiden_of_grief;
    newscript->RegisterSelf();
}
