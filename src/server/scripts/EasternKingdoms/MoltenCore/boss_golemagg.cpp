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
SDName: Boss_Golemagg
SD%Complete: 90
SDComment: Timers need to be confirmed, Golemagg's Trust need to be checked
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"
#include "molten_core.h"

enum eEnums
{
    SPELL_MAGMASPLASH       = 13879,
    SPELL_PYROBLAST         = 20228,
    SPELL_EARTHQUAKE        = 19798,
    SPELL_ENRAGE            = 19953,
    SPELL_GOLEMAGG_TRUST    = 20553,

    // Core Rager
    EMOTE_LOWHP             = -1409002,
    SPELL_MANGLE            = 19820
};

class boss_golemagg : public CreatureScript
{
public:
    boss_golemagg() : CreatureScript("boss_golemagg") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_golemaggAI (pCreature);
    }

    struct boss_golemaggAI : public ScriptedAI
    {
        boss_golemaggAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 m_uiPyroblastTimer;
        uint32 m_uiEarthquakeTimer;
        uint32 m_uiBuffTimer;
        bool m_bEnraged;

        void Reset()
        {
            m_uiPyroblastTimer = 7*IN_MILLISECONDS;              // These timers are probably wrong
            m_uiEarthquakeTimer = 3*IN_MILLISECONDS;
            m_uiBuffTimer = 2500;
            m_bEnraged = false;

            DoCast(me, SPELL_MAGMASPLASH, true);
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(DATA_GOLEMAGG, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            //Pyroblast
            if (m_uiPyroblastTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_PYROBLAST);

                m_uiPyroblastTimer = 7*IN_MILLISECONDS;
            }
            else
                m_uiPyroblastTimer -= uiDiff;

            // Enrage
            if (!m_bEnraged && HealthBelowPct(10))
            {
                DoCast(me, SPELL_ENRAGE);
                m_bEnraged = true;
            }

            // Earthquake
            if (m_bEnraged)
            {
                if (m_uiEarthquakeTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_EARTHQUAKE);
                    m_uiEarthquakeTimer = 3*IN_MILLISECONDS;
                }
                else
                    m_uiEarthquakeTimer -= uiDiff;
            }

            /*
            // Golemagg's Trust
            if (m_uiBuffTimer <= uidiff)
            {
                DoCast(me, SPELL_GOLEMAGG_TRUST);
                m_uiBuffTimer = 2.5*IN_MILLISECONDS;
            }
            else
                m_uiBuffTimer -= uiDiff;
            */

            DoMeleeAttackIfReady();
        }
    };

};

class mob_core_rager : public CreatureScript
{
public:
    mob_core_rager() : CreatureScript("mob_core_rager") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_core_ragerAI (pCreature);
    }

    struct mob_core_ragerAI : public ScriptedAI
    {
        mob_core_ragerAI(Creature *c) : ScriptedAI(c)
        {
            m_pInstance = c->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 m_uiMangleTimer;

        void Reset()
        {
            m_uiMangleTimer = 7*IN_MILLISECONDS;                 // These times are probably wrong
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage)
        {
            if (HealthBelowPct(50))
            {
                if (m_pInstance)
                {
                    if (Creature* pGolemagg = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_GOLEMAGG)))
                    {
                        if (pGolemagg->isAlive())
                        {
                            DoScriptText(EMOTE_LOWHP, me);
                            me->SetFullHealth();
                        }
                        else
                            uiDamage = me->GetHealth();
                    }
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Mangle
            if (m_uiMangleTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_MANGLE);
                m_uiMangleTimer = 10*IN_MILLISECONDS;
            }
            else
                m_uiMangleTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};



void AddSC_boss_golemagg()
{
    new boss_golemagg();
    new mob_core_rager();
}
