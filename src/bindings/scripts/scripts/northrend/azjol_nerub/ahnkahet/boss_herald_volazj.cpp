/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: boss_herald_volazj
SDAuthor: Tartalo
SD%Complete: 20
SDComment: Coded all but Insanity
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_INSANITY                         = 57496, //Dummy
    INSANITY_VISUAL                        = 57561,
    SPELL_MIND_FLAY                        = 57941,
    H_SPELL_MIND_FLAY                      = 59974,
    SPELL_SHADOW_BOLT_VOLLEY               = 57942,
    H_SPELL_SHADOW_BOLT_VOLLEY             = 59975,
    SPELL_SHIVER                           = 57949,
    H_SPELL_SHIVER                         = 59978
};

//not in db
enum Yells
{
    SAY_AGGRO                               = -1619030,
    SAY_SLAY_1                              = -1619031,
    SAY_SLAY_2                              = -1619032,
    SAY_SLAY_3                              = -1619033,
    SAY_DEATH_1                             = -1619034,
    SAY_DEATH_2                             = -1619035,
    SAY_PHASE                               = -1619036
};

enum Achievements
{
    ACHIEVEMENT_QUICK_DEMISE                = 1862
};

struct TRINITY_DLL_DECL boss_volazjAI : public ScriptedAI
{
    boss_volazjAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    uint32 uiMindFlayTimer;
    uint32 uiShadowBoltVolleyTimer;
    uint32 uiShiverTimer;
    uint32 uiEncounterTimer;

    void Reset()
    {
        uiEncounterTimer = 0;
        uiMindFlayTimer = 8000;
        uiShadowBoltVolleyTimer = 5000;
        uiShiverTimer = 15000;

        if (pInstance)
            pInstance->SetData(DATA_HERALD_VOLAZJ, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_HERALD_VOLAZJ, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiMindFlayTimer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_MIND_FLAY, H_SPELL_MIND_FLAY));
            uiMindFlayTimer = 20000;
        } else uiMindFlayTimer -= diff;

        if (uiShadowBoltVolleyTimer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_SHADOW_BOLT_VOLLEY, H_SPELL_SHADOW_BOLT_VOLLEY));
            uiShadowBoltVolleyTimer = 5000;
        } else uiShadowBoltVolleyTimer -= diff;

        if (uiShiverTimer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, DUNGEON_MODE(SPELL_SHIVER, H_SPELL_SHIVER));
            uiShiverTimer = 15000;
        } else uiShiverTimer -= diff;

        uiEncounterTimer += diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH_1, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_HERALD_VOLAZJ, DONE);

        AchievementEntry const *AchievQuickDemise = GetAchievementStore()->LookupEntry(ACHIEVEMENT_QUICK_DEMISE);
        Map* pMap = m_creature->GetMap();

        if (IsHeroic() && uiEncounterTimer < 120000 && pMap && pMap->IsDungeon() && AchievQuickDemise)
        {
            Map::PlayerList const &players = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievQuickDemise);
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_volazj(Creature* pCreature)
{
    return new boss_volazjAI (pCreature);
}

void AddSC_boss_volazj()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_volazj";
    newscript->GetAI = &GetAI_boss_volazj;
    newscript->RegisterSelf();
}
