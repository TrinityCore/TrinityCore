/*
* Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptedPch.h"
#include "gundrak.h"

//Spells
enum Spells
{
    SPELL_ENRAGE                                  = 55285,
    H_SPELL_ENRAGE                                = 59828,
    SPELL_IMPALING_CHARGE                         = 54956,
    H_SPELL_IMPALING_CHARGE                       = 59827,
    SPELL_STOMP                                   = 55292,
    H_SPELL_STOMP                                 = 59826,
    SPELL_PUNCTURE                                = 55276,
    H_SPELL_PUNCTURE                              = 59826,
    SPELL_STAMPEDE                                = 55218,
    SPELL_WHIRLING_SLASH                          = 55249,
    H_SPELL_WHIRLING_SLASH                        = 55825,
    SPELL_ECK_RESIDUE                             = 55817
};

//Yells
enum Yells
{
    SAY_AGGRO                                     = -1604000,
    SAY_SLAY_1                                    = -1604001,
    SAY_SLAY_2                                    = -1604002,
    SAY_SLAY_3                                    = -1604003,
    SAY_DEATH                                     = -1604004,
    SAY_SUMMON_RHINO_1                            = -1604005,
    SAY_SUMMON_RHINO_2                            = -1604006,
    SAY_SUMMON_RHINO_3                            = -1604007,
    SAY_TRANSFORM_1                               = -1604008,  //Phase change
    SAY_TRANSFORM_2                               = -1604009
};

enum Achievements
{
    ACHIEV_WHAT_THE_ECK                           = 1864,
    ACHIEV_SHARE_THE_LOVE                         = 2152
};


enum CombatPhase
{
    TROLL,
    RHINO
};

struct boss_gal_darahAI : public ScriptedAI
{
    boss_gal_darahAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiStampedeTimer;
    uint32 uiWhirlingSlashTimer;
    uint32 uiPunctureTimer;
    uint32 uiEnrageTimer;
    uint32 uiImpalingChargeTimer;
    uint32 uiStompTimer;
    std::set<uint64> lImpaledPlayers;

    CombatPhase Phase;

    uint8 uiPhaseCounter;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiStampedeTimer = 10*IN_MILISECONDS;
        uiWhirlingSlashTimer = 20*IN_MILISECONDS;
        uiPunctureTimer = 10*IN_MILISECONDS;
        uiEnrageTimer = 15*IN_MILISECONDS;
        uiImpalingChargeTimer = 20*IN_MILISECONDS;
        uiStompTimer = 25*IN_MILISECONDS;
        uiPhaseCounter = 0;

        lImpaledPlayers.clear();

        Phase = TROLL;

        if (pInstance)
            pInstance->SetData(DATA_GAL_DARAH_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_GAL_DARAH_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        switch (Phase)
        {
            case TROLL:
                if (uiPhaseCounter == 2)
                {
                    //FIX: implement transformation
                    Phase = RHINO;
                    uiPhaseCounter = 0;
                    DoScriptText(SAY_TRANSFORM_1,m_creature);
                }
                else
                {
                    if (uiStampedeTimer <= diff)
                    {
                        DoCast(m_creature, SPELL_STAMPEDE);
                        DoScriptText(RAND(SAY_SUMMON_RHINO_1,SAY_SUMMON_RHINO_2,SAY_SUMMON_RHINO_3),m_creature);
                        uiStampedeTimer = 15*IN_MILISECONDS;
                    } else uiStampedeTimer -= diff;

                    if (uiWhirlingSlashTimer <= diff)
                    {
                        DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_WHIRLING_SLASH, H_SPELL_WHIRLING_SLASH));
                        uiWhirlingSlashTimer = 20*IN_MILISECONDS;
                        ++uiPhaseCounter;
                    } else uiWhirlingSlashTimer -= diff;
                }
            break;
            case RHINO:
                if (uiPhaseCounter == 2)
                {
                    //FIX: implement transformation
                    Phase = TROLL;
                    uiPhaseCounter = 0;
                    DoScriptText(SAY_TRANSFORM_2,m_creature);
                }
                else
                {
                    if (uiPunctureTimer <= diff)
                    {
                        DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_PUNCTURE, H_SPELL_PUNCTURE));
                        uiPunctureTimer = 8*IN_MILISECONDS;
                    } else uiPunctureTimer -= diff;

                    if (uiEnrageTimer <= diff)
                    {
                        DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_ENRAGE, H_SPELL_ENRAGE));
                        uiEnrageTimer = 20*IN_MILISECONDS;
                    } else uiEnrageTimer -= diff;

                    if (uiStompTimer <= diff)
                    {
                        DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_STOMP, H_SPELL_STOMP));
                        uiStompTimer = 20*IN_MILISECONDS;
                    } else uiStompTimer -= diff;

                    if (uiImpalingChargeTimer <= diff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                        {
                            DoCast(pTarget, DUNGEON_MODE(SPELL_IMPALING_CHARGE, H_SPELL_IMPALING_CHARGE));
                            lImpaledPlayers.insert(pTarget->GetGUID());
                        }
                        uiImpalingChargeTimer = 30*IN_MILISECONDS;
                        ++uiPhaseCounter;
                    } else uiImpalingChargeTimer -= diff;
                }
            break;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            if (IsHeroic())
            {
                if (lImpaledPlayers.size() == 5)
                    pInstance->DoCompleteAchievement(ACHIEV_SHARE_THE_LOVE);

                AchievementEntry const *achievWhatTheEck = GetAchievementStore()->LookupEntry(ACHIEV_WHAT_THE_ECK);
                if (achievWhatTheEck)
                {
                    Map::PlayerList const &players = pInstance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (itr->getSource()->HasAura(SPELL_ECK_RESIDUE))
                            itr->getSource()->CompletedAchievement(achievWhatTheEck);
                }
            }
            
            pInstance->SetData(DATA_GAL_DARAH_EVENT, DONE);
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_gal_darah(Creature* pCreature)
{
    return new boss_gal_darahAI (pCreature);
}

void AddSC_boss_gal_darah()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_gal_darah";
    newscript->GetAI = &GetAI_boss_gal_darah;
    newscript->RegisterSelf();
}
