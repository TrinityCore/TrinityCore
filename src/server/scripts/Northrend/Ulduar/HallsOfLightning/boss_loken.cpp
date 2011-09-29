/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss Loken
SD%Complete: 60%
SDComment: Missing intro. Remove hack of Pulsing Shockwave when core supports. Aura is not working (59414)
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptPCH.h"
#include "halls_of_lightning.h"

enum eEnums
{
    ACHIEV_TIMELY_DEATH_START_EVENT               = 20384,

    SAY_AGGRO                                     = -1602018,
    SAY_INTRO_1                                   = -1602019,
    SAY_INTRO_2                                   = -1602020,
    SAY_SLAY_1                                    = -1602021,
    SAY_SLAY_2                                    = -1602022,
    SAY_SLAY_3                                    = -1602023,
    SAY_DEATH                                     = -1602024,
    SAY_NOVA_1                                    = -1602025,
    SAY_NOVA_2                                    = -1602026,
    SAY_NOVA_3                                    = -1602027,
    SAY_75HEALTH                                  = -1602028,
    SAY_50HEALTH                                  = -1602029,
    SAY_25HEALTH                                  = -1602030,
    EMOTE_NOVA                                    = -1602031,

    SPELL_ARC_LIGHTNING                           = 52921,
    SPELL_LIGHTNING_NOVA_N                        = 52960,
    SPELL_LIGHTNING_NOVA_H                        = 59835,

    SPELL_PULSING_SHOCKWAVE_N                     = 52961,
    SPELL_PULSING_SHOCKWAVE_H                     = 59836,
    SPELL_PULSING_SHOCKWAVE_AURA                  = 59414
};

/*######
## Boss Loken
######*/

class boss_loken : public CreatureScript
{
public:
    boss_loken() : CreatureScript("boss_loken") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lokenAI(creature);
    }

    struct boss_lokenAI : public ScriptedAI
    {
        boss_lokenAI(Creature* creature) : ScriptedAI(creature)
        {
            m_pInstance = creature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        bool m_bIsAura;

        uint32 m_uiArcLightning_Timer;
        uint32 m_uiLightningNova_Timer;
        uint32 m_uiPulsingShockwave_Timer;
        uint32 m_uiResumePulsingShockwave_Timer;

        uint32 m_uiHealthAmountModifier;

        void Reset()
        {
            m_bIsAura = false;

            m_uiArcLightning_Timer = 15000;
            m_uiLightningNova_Timer = 20000;
            m_uiPulsingShockwave_Timer = 2000;
            m_uiResumePulsingShockwave_Timer = 15000;

            m_uiHealthAmountModifier = 1;

            if (m_pInstance)
            {
                m_pInstance->SetData(TYPE_LOKEN, NOT_STARTED);
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMELY_DEATH_START_EVENT);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (m_pInstance)
            {
                m_pInstance->SetData(TYPE_LOKEN, IN_PROGRESS);
                m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMELY_DEATH_START_EVENT);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (m_pInstance)
                m_pInstance->SetData(TYPE_LOKEN, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (m_bIsAura)
            {
                // workaround for PULSING_SHOCKWAVE
                if (m_uiPulsingShockwave_Timer <= uiDiff)
                {
                    Map* pMap = me->GetMap();
                    if (pMap->IsDungeon())
                    {
                        Map::PlayerList const &PlayerList = pMap->GetPlayers();

                        if (PlayerList.isEmpty())
                            return;

                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->getSource() && i->getSource()->isAlive() && i->getSource()->isTargetableForAttack())
                            {
                                int32 dmg;
                                float m_fDist = me->GetExactDist(i->getSource()->GetPositionX(), i->getSource()->GetPositionY(), i->getSource()->GetPositionZ());

                                dmg = DUNGEON_MODE(100, 150); // need to correct damage
                                if (m_fDist > 1.0f) // Further from 1 yard
                                    dmg = int32(dmg*m_fDist);

                                me->CastCustomSpell(i->getSource(), DUNGEON_MODE(52942, 59837), &dmg, 0, 0, false);
                            }
                    }
                    m_uiPulsingShockwave_Timer = 2000;
                } else m_uiPulsingShockwave_Timer -= uiDiff;
            }
            else
            {
                if (m_uiResumePulsingShockwave_Timer <= uiDiff)
                {
                    //breaks at movement, can we assume when it's time, this spell is casted and also must stop movement?
                    DoCast(me, SPELL_PULSING_SHOCKWAVE_AURA, true);

                    DoCast(me, SPELL_PULSING_SHOCKWAVE_N); // need core support
                    m_bIsAura = true;
                    m_uiResumePulsingShockwave_Timer = 0;
                }
                else
                    m_uiResumePulsingShockwave_Timer -= uiDiff;
            }

            if (m_uiArcLightning_Timer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARC_LIGHTNING);

                m_uiArcLightning_Timer = 15000 + rand()%1000;
            }
            else
                m_uiArcLightning_Timer -= uiDiff;

            if (m_uiLightningNova_Timer <= uiDiff)
            {
                DoScriptText(RAND(SAY_NOVA_1, SAY_NOVA_2, SAY_NOVA_3), me);
                DoScriptText(EMOTE_NOVA, me);
                DoCast(me, SPELL_LIGHTNING_NOVA_N);

                m_bIsAura = false;
                m_uiResumePulsingShockwave_Timer = DUNGEON_MODE(5000, 4000); // Pause Pulsing Shockwave aura
                m_uiLightningNova_Timer = 20000 + rand()%1000;
            }
            else
                m_uiLightningNova_Timer -= uiDiff;

            // Health check
            if (HealthBelowPct(100 - 25 * m_uiHealthAmountModifier))
            {
                switch (m_uiHealthAmountModifier)
                {
                    case 1: DoScriptText(SAY_75HEALTH, me); break;
                    case 2: DoScriptText(SAY_50HEALTH, me); break;
                    case 3: DoScriptText(SAY_25HEALTH, me); break;
                }

                ++m_uiHealthAmountModifier;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_loken()
{
    new boss_loken();
}
