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

#define SPELL_EXPLOSION		41524	// circa 6000 danno(arcane) area 20 yard. da fare spesso. 3,7 sec cast
// le 4 seguenti spell le casto cn timer unico cambiandole cn 1 switch rand
#define SPELL_MISSILES		39414	// 3k esatti di danno(arcane), target random
#define SPELL_BOLT		38823	// da 2500 a 3500 di danno(arcane), target random
#define SPELL_STARFIRE		30130	// 4500 a 5500 di danno(arcane), lo faccio tipo ogni minuto, al tanker, 4 sec cast
#define SPELL_SHADOWBOLT	20690	// 3600 a 4400 di danno(shadow), 1 sec cast

#define SPELL_MANGLE		25653	// 1600 a 2400 subito + 500 ogni 3 sec x 15 sec di danno(normale), al tanker
#define SPELL_SUPERARC		40425	// 7K to 8k, 50 yard. 5 sec cast
#define SPELL_FROSTNOVA		5403	// fa tipo 100 di danno, e stunna tutti i player in 10yard per 10 secondi

#define SAY_FROSTNOVA	"il freddo entra nel profondo delle vostre anime... non resisterete!"
#define SAY_BEFORENOVA	"non siate frettolosi... non vi salver�"
#define SAY_DIECIPERC	"NON RIUSCIRETE A VINCERMI, SONO SUPERIORE A VOI MORTALI!"
#define SAY_KILL	"non potete nulla contro di me"
#define SAY_DEATH	"... accadra' anche a voi"
#define SAY_TECNICA	"NON HO SCELTA... E' UN RISCHIO DA CORRERE!"

struct MANGOS_DLL_DECL boss_netherspiteAI : public ScriptedAI
{
    boss_netherspiteAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 explosion_timer;
    uint32 spell_timer; // timer unico xk si alternano
    uint32 mangle_timer;
    uint32 bite_timer;
    

    Unit* target;

	int cambia;
    

    void Reset()
    {
        // alcuni timer iniziali sono + brevi
        explosion_timer = 1000;
        spell_timer = 10000;
        mangle_timer = 36000;
        bite_timer = 81000;

		cambia = 0;


        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BLEED, true); // non vedo xk un drago non corporeo dovrebbe poter sanguinare...
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
    }


    void KilledUnit(Unit* Victim)
    {
        m_creature->MonsterYell(SAY_KILL,LANG_UNIVERSAL,NULL);
    }

	void Aggro(Unit *who) {}

    void JustDied(Unit* Killer)
    {
        m_creature->MonsterYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() )
            return;

        if (explosion_timer < diff)
        {
            DoCast(m_creature,SPELL_EXPLOSION);
            explosion_timer = 7000;
        }
        else explosion_timer -= diff;

        if (mangle_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MANGLE);
            mangle_timer = 13000;
        }
        else mangle_timer -= diff;

        if(spell_timer < diff)
        {
            target = m_creature->SelectRandomUnfriendlyTarget();

        switch(rand()%4)
        {
        case 0:
            DoCast(target,SPELL_MISSILES);
            break;
        case 1:
            DoCast(target,SPELL_BOLT);
            break;
        case 2:
            DoCast(target,SPELL_STARFIRE);
            break;
        case 3:
            DoCast(target,SPELL_SHADOWBOLT);
            break;
        }
    
            spell_timer = 5000;
        }
        else spell_timer -= diff;

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 60 && cambia == 0)
        {    
            m_creature->MonsterYell(SAY_BEFORENOVA,LANG_UNIVERSAL,NULL);
			cambia = 1;
        }

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 55 && cambia == 1)
        {   
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
            m_creature->MonsterYell(SAY_FROSTNOVA,LANG_UNIVERSAL,NULL);
            DoCast(m_creature,SPELL_FROSTNOVA);
			cambia = 2;
        }

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 10 && cambia == 2)
        {    
            m_creature->MonsterYell(SAY_DIECIPERC,LANG_UNIVERSAL,NULL);
			cambia = 3;
        }

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 5 && cambia == 3)
        {   
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
            m_creature->MonsterYell(SAY_TECNICA,LANG_UNIVERSAL,NULL);
            DoCast(m_creature,SPELL_SUPERARC);
			cambia = 4; // evita k cominci a spammar sta spell
        }

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_netherspite_azsc(Creature *_Creature)
{
    return new boss_netherspiteAI (_Creature);
}

void AddSC_boss_netherspite_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_netherspite_azsc";
    newscript->GetAI = GetAI_boss_netherspite_azsc;
    newscript->RegisterSelf();
}


// update creature_template set scriptname=boss_netherspite where entry=15689;

// extern void AddSC_boss_netherspite();

// AddSC_boss_netherspite();

