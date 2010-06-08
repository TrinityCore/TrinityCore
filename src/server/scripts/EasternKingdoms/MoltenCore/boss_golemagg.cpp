/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

struct boss_golemaggAI : public ScriptedAI
{
    boss_golemaggAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiPyroblastTimer;
    uint32 m_uiEarthquakeTimer;
    uint32 m_uiBuffTimer;
    bool m_bEnraged;

    void Reset()
    {
        m_uiPyroblastTimer = 7*IN_MILISECONDS;              // These timers are probably wrong
        m_uiEarthquakeTimer = 3*IN_MILISECONDS;
        m_uiBuffTimer = 2.5*IN_MILISECONDS;
        m_bEnraged = false;

        DoCast(me, SPELL_MAGMASPLASH, true);
    }

    void JustDied(Unit* /*pKiller*/)
    {
        if (m_pInstance)
            m_pInstance->SetData(DATA_GOLEMAGG_DEATH, 0);
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

            m_uiPyroblastTimer = 7*IN_MILISECONDS;
        }
        else
            m_uiPyroblastTimer -= uiDiff;

        // Enrage
        if (!m_bEnraged && me->GetHealth()*100 < me->GetMaxHealth()*10)
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
                m_uiEarthquakeTimer = 3*IN_MILISECONDS;
            }
            else
                m_uiEarthquakeTimer -= uiDiff;
        }

        /*
        // Golemagg's Trust
        if (m_uiBuffTimer <= uidiff)
        {
            DoCast(me, SPELL_GOLEMAGG_TRUST);
            m_uiBuffTimer = 2.5*IN_MILISECONDS;
        }
        else
            m_uiBuffTimer -= uiDiff;
        */

        DoMeleeAttackIfReady();
    }
};

struct mob_core_ragerAI : public ScriptedAI
{
    mob_core_ragerAI(Creature *c) : ScriptedAI(c)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiMangleTimer;

    void Reset()
    {
        m_uiMangleTimer = 7*IN_MILISECONDS;                 // These times are probably wrong
    }

    void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage)
    {
        if (me->GetHealth()*100 < me->GetMaxHealth()*50)
        {
            if (m_pInstance)
            {
                if (Creature* pGolemagg = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_GOLEMAGG)))
                {
                    if (pGolemagg->isAlive())
                    {
                        DoScriptText(EMOTE_LOWHP, me);
                        me->SetHealth(me->GetMaxHealth());
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
            m_uiMangleTimer = 10*IN_MILISECONDS;
        }
        else
            m_uiMangleTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_golemagg(Creature* pCreature)
{
    return new boss_golemaggAI (pCreature);
}

CreatureAI* GetAI_mob_core_rager(Creature* pCreature)
{
    return new mob_core_ragerAI (pCreature);
}

void AddSC_boss_golemagg()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_golemagg";
    newscript->GetAI = &GetAI_boss_golemagg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_core_rager";
    newscript->GetAI = &GetAI_mob_core_rager;
    newscript->RegisterSelf();
}

