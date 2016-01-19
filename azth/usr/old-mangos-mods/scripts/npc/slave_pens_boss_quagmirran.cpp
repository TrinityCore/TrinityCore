/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "precompiled.h"

#define SPELL_AOEPOISON  39340	// 2,5k dmg area + dot da 700
#define SPELL_CLEAVE     40504	//110% weapon dmg, up to 3 targets
#define SPELL_KNOCKBACK	 32055	// weapon dmg + 200 + knockback(10) = qualke metro

#define SAY_AGGRO	"Grhgnggnn..."
#define SAY_DEATH	"Oughgn..."
#define SAY_SLAY	"GNCHGNG"

// nn � fortissimo, ma ricordati k � pur sempre un boss k droppa blu

// quando lo feci, nn sapissi della simple ai, quindi x giustificare uno script apposito mettessi ora dei say simpatici... alla fine � 1 essere senza cervello, rude, bvoso e grosso.
// http://www.wowwiki.com/Quagmirran


struct MANGOS_DLL_DECL boss_quagmirranAI : public ScriptedAI
{
    boss_quagmirranAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 poison_timer;
    uint32 cleave_timer;
	uint32 knockback_timer;

    Unit* target;

    void Reset()
    {
        poison_timer = 18000;
        cleave_timer = 13000;
		knockback_timer = 21000;


		m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
		m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
		m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
    }

	void KilledUnit(Unit *victim)
    {
		m_creature->MonsterYell(SAY_SLAY, LANG_UNIVERSAL, NULL);
	}

	void JustDied(Unit *victim)
    {
        m_creature->MonsterYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
	}

	void Aggro(Unit *who)
    {
       m_creature->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
    }

	void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() )
            return;

        if (cleave_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            cleave_timer = 8000;
        }
        else cleave_timer -= diff;

        if (poison_timer < diff)
        {
            target = m_creature->SelectRandomUnfriendlyTarget();
            DoCast(target,SPELL_AOEPOISON);

            poison_timer = 10000;

        }
        else poison_timer -= diff;

		if (knockback_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCKBACK);
            knockback_timer = 21000;
        }
        else knockback_timer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_quagmirran_azsc(Creature *_Creature)
{
    return new boss_quagmirranAI (_Creature);
}

void AddSC_boss_quagmirran_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_quagmirran_azsc";
    newscript->GetAI = GetAI_boss_quagmirran_azsc;
    newscript->RegisterSelf();
}


// update creature_template set scriptname=boss_quagmirran where entry=17942;

// extern void AddSC_boss_quagmirran();

// AddSC_boss_quagmirran();
