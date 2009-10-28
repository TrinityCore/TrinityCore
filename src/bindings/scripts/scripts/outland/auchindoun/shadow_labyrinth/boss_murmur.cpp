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
SDName: Boss_Murmur
SD%Complete: 90
SDComment: Timers may be incorrect
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "shadow_labyrinth.h"

#define EMOTE_SONIC_BOOM            -1555036

#define SPELL_SONIC_BOOM_CAST       (HeroicMode?38796:33923)
#define SPELL_SONIC_BOOM_EFFECT     (HeroicMode?38795:33666)
#define SPELL_RESONANCE             33657
#define SPELL_MURMURS_TOUCH         (HeroicMode?38794:33711)
#define SPELL_MAGNETIC_PULL         33689
#define SPELL_SONIC_SHOCK           38797
#define SPELL_THUNDERING_STORM      39365

struct TRINITY_DLL_DECL boss_murmurAI : public ScriptedAI
{
    boss_murmurAI(Creature *c) : ScriptedAI(c)
    {
        SetCombatMovement(false);
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    uint32 SonicBoom_Timer;
    uint32 MurmursTouch_Timer;
    uint32 Resonance_Timer;
    uint32 MagneticPull_Timer;
    uint32 SonicShock_Timer;
    uint32 ThunderingStorm_Timer;
    bool HeroicMode;
    bool SonicBoom;

    void Reset()
    {
        SonicBoom_Timer = 30000;
        MurmursTouch_Timer = 8000 + rand()%12000;
        Resonance_Timer = 5000;
        MagneticPull_Timer = 15000 + rand()%15000;
        ThunderingStorm_Timer = 15000;
        SonicShock_Timer = 10000;
        SonicBoom = false;

        //database should have `RegenHealth`=0 to prevent regen
        uint32 hp = (m_creature->GetMaxHealth()*40)/100;
        if (hp) m_creature->SetHealth(hp);
        m_creature->ResetPlayerDamageReq();
    }

    void SonicBoomEffect()
    {
        std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
        for (std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
        {
           Unit *pTarget = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
           if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
           {
               //Not do anything without aura, spell can be resisted!
               if (pTarget->HasAura(SPELL_SONIC_BOOM_CAST) && m_creature->IsWithinDistInMap(pTarget, 34.0f))
               {
                   //This will be wrong calculation. Also, comments suggest it must deal damage
                   pTarget->SetHealth(uint32(pTarget->GetMaxHealth() - pTarget->GetMaxHealth() * 0.8));
               }
           }
        }
    }

    void EnterCombat(Unit *who) { }

    // Sonic Boom instant damage (needs core fix instead of this)
    void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
    {
        if (pTarget && pTarget->isAlive() && spell && spell->Id == SPELL_SONIC_BOOM_EFFECT)
            m_creature->DealDamage(pTarget,(pTarget->GetHealth()*90)/100,NULL,SPELL_DIRECT_DAMAGE,SPELL_SCHOOL_MASK_NATURE,spell);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target or casting
        if (!UpdateVictim() || m_creature->IsNonMeleeSpellCasted(false))
            return;

        // Sonic Boom
        if (SonicBoom)
        {
            DoCast(m_creature, SPELL_SONIC_BOOM_EFFECT, true);
            SonicBoomEffect();

            SonicBoom = false;
            Resonance_Timer = 1500;
        }
        if (SonicBoom_Timer <= diff)
        {
            DoScriptText(EMOTE_SONIC_BOOM, m_creature);
            DoCast(m_creature, SPELL_SONIC_BOOM_CAST);
            SonicBoom_Timer = 30000;
            SonicBoom = true;
            return;
        } else SonicBoom_Timer -= diff;

        // Murmur's Touch
        if (MurmursTouch_Timer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,80,true))
                DoCast(pTarget, SPELL_MURMURS_TOUCH);
            MurmursTouch_Timer = 25000 + rand()%10000;
        } else MurmursTouch_Timer -= diff;

        // Resonance
        if (!SonicBoom && !(m_creature->IsWithinMeleeRange(m_creature->getVictim())))
        {
            if (Resonance_Timer <= diff)
            {
                DoCast(m_creature, SPELL_RESONANCE);
                Resonance_Timer = 5000;
            } else Resonance_Timer -= diff;
        }

        // Magnetic Pull
        if (MagneticPull_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                if (pTarget->GetTypeId() == TYPEID_PLAYER && pTarget->isAlive())
                {
                    DoCast(pTarget, SPELL_MAGNETIC_PULL);
                    MagneticPull_Timer = 15000+rand()%15000;
                    return;
                }
            MagneticPull_Timer = 500;
        } else MagneticPull_Timer -= diff;

        if (HeroicMode)
        {
            // Thundering Storm
            if (ThunderingStorm_Timer <= diff)
            {
                std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
                for (std::list<HostilReference*>::iterator i = m_threatlist.begin(); i != m_threatlist.end(); ++i)
                    if (Unit *pTarget = Unit::GetUnit((*m_creature),(*i)->getUnitGuid()))
                        if (pTarget->isAlive() && !m_creature->IsWithinDist(pTarget, 35, false))
                            DoCast(pTarget, SPELL_THUNDERING_STORM, true);
                ThunderingStorm_Timer = 15000;
            } else ThunderingStorm_Timer -= diff;

            // Sonic Shock
            if (SonicShock_Timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,20,false))
                    if (pTarget->isAlive())
                        DoCast(pTarget, SPELL_SONIC_SHOCK);
                SonicShock_Timer = 10000+rand()%10000;
            } else SonicShock_Timer -= diff;
        }

        // Select nearest most aggro target if top aggro too far
        if (!m_creature->isAttackReady())
            return;
        if (!m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
            for (std::list<HostilReference*>::iterator i = m_threatlist.begin(); i != m_threatlist.end(); ++i)
                if (Unit *pTarget = Unit::GetUnit((*m_creature),(*i)->getUnitGuid()))
                    if (pTarget->isAlive() && m_creature->IsWithinMeleeRange(pTarget))
                    {
                        m_creature->TauntApply(pTarget);
                        break;
                    }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_murmur(Creature* pCreature)
{
    return new boss_murmurAI (pCreature);
}

void AddSC_boss_murmur()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_murmur";
    newscript->GetAI = &GetAI_boss_murmur;
    newscript->RegisterSelf();
}

