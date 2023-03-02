/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_High_Inquisitor_Fairbanks
SD%Complete: 100
SDComment: TODO: if this guy not involved in some special event, remove (and let ACID script)
SDCategory: Scarlet Monastery
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_CURSEOFBLOOD              = 8282,
    SPELL_DISPELMAGIC               = 15090,
    SPELL_FEAR                      = 12096,
    SPELL_HEAL                      = 12039,
    SPELL_POWERWORDSHIELD           = 11647,
    SPELL_SLEEP                     = 8399
};

struct boss_high_inquisitor_fairbanksAI : public ScriptedAI
{
    boss_high_inquisitor_fairbanksAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 CurseOfBlood_Timer;
    uint32 DispelMagic_Timer;
    uint32 Fear_Timer;
    uint32 Heal_Timer;
    uint32 Sleep_Timer;
    uint32 Dispel_Timer;
    bool PowerWordShield;
    bool bAshbringer;

    void Reset() override
    {
        CurseOfBlood_Timer = 10000;
        DispelMagic_Timer = 30000;
        Fear_Timer = 40000;
        Heal_Timer = 30000;
        Sleep_Timer = 30000;
        Dispel_Timer = 20000;
        PowerWordShield = false;
        bAshbringer = false;
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == 28441 && !bAshbringer && pCaster && me->IsWithinLOSInMap(pCaster))
        {
            me->SetSheath(SHEATH_STATE_UNARMED);
            me->CastSpell(me, 28443, true); // transform
            me->SetFacingToObject(pCaster);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            bAshbringer = true;
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //If we are <25% hp cast Heal
        if (m_creature->GetHealthPercent() <= 25.0f && !m_creature->IsNonMeleeSpellCasted(false) && Heal_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_HEAL);
            Heal_Timer = 30000;
        }
        else Heal_Timer -= diff;

        //Fear_Timer
        if (Fear_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                DoCastSpellIfCan(target, SPELL_FEAR);

            Fear_Timer = 40000;
        }
        else Fear_Timer -= diff;

        //Sleep_Timer
        if (Sleep_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
                DoCastSpellIfCan(target, SPELL_SLEEP);

            Sleep_Timer = 30000;
        }
        else Sleep_Timer -= diff;

        //PowerWordShield_Timer
        if (!PowerWordShield && m_creature->GetHealthPercent() <= 25.0f)
        {
            DoCastSpellIfCan(m_creature, SPELL_POWERWORDSHIELD);
            PowerWordShield = true;
        }

        //Dispel_Timer
        if (Dispel_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCastSpellIfCan(target, SPELL_DISPELMAGIC);

            DispelMagic_Timer = 30000;
        }
        else DispelMagic_Timer -= diff;

        //CurseOfBlood_Timer
        if (CurseOfBlood_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFBLOOD);
            CurseOfBlood_Timer = 25000;
        }
        else CurseOfBlood_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_boss_high_inquisitor_fairbanks(Creature* pCreature)
{
    return new boss_high_inquisitor_fairbanksAI(pCreature);
}

void AddSC_boss_high_inquisitor_fairbanks()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_high_inquisitor_fairbanks";
    newscript->GetAI = &GetAI_boss_high_inquisitor_fairbanks;
    newscript->RegisterSelf();
}
