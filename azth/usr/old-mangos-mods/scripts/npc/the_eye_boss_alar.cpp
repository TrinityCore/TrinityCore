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

#define SPELL_FLAME_EXPLOSION	45746	// 1,5k di danno (phisical) + riduce movement speed del 25% x 15 sec - SELF
#define SPELL_FIRE_RAIN			31341	// 1250 fire dmg ogni sec x 5 sec, single target
#define SPELL_FIRE_WEAKNESS		19366	// riduce la fire res di tutti in 45 yard di 200 x 15 min - SELF
#define SPELL_AMPLIFY_FIRE		41078	// aumenta il danno da fuoco ricevuto dal target di 1000 x 2 min
#define SPELL_FLAME_BUFFET		22433	// 1k di danno e aumenta danno fire ricevuto di 1k x 20 sec, single target
#define SPELL_FLAME_BREATH		43215	// 2,2k fire dmg in 15 yard davanti - nn self
#define SPELL_FLAME_BOMB		42630	// da 6k a 8k di danno fire a 4 yard radius - SELF
#define SPELL_MAGIC_SHIELD		19645	// buff k rende immune alle school magiche x 10 sec
#define SPELL_FIREBALL			41484	// 6,5k fire dmg + 600 over 3 sec
#define SPELL_MELTARMOR			35410	// riduce armor del 80%
#define SPELL_REBIRTH			35369	// 5k + knockback 400, il tt a 15 yard

#define EMOTE_AGGRO		" brucia con ancora piu' furia"
#define EMOTE_KILL1		" sembra ricaricarsi dell'energia vitale appena dispersa..."
#define EMOTE_KILL2		" assorbe l'energia dispersa, aumentando la sua temperatura ulteriormente"
#define EMOTE_DEATH		" si spegne, consumandosi in un'ultima vampata"

struct MANGOS_DLL_DECL boss_alarAI : public ScriptedAI
{
    boss_alarAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 aoefire_timer;
    uint32 singlefire_timer;
    uint32 weakness_timer;
	uint32 shield_timer;
	uint32 meltarmor_timer;
	uint32 rebirth_timer;
    
	bool kill;

	Unit* target;
	Unit* target2;
	Unit* target3;

	uint32 maxlife;
	uint32 hcurrentlife;


    void Reset()
    {
        aoefire_timer = 20000;
        singlefire_timer = 15000;
        weakness_timer  = 11000;
		shield_timer = 61000;
		meltarmor_timer = 64000;
		rebirth_timer = 201000;

		kill = false;

		m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
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
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DAZE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
    }

    void Aggro(Unit *who)
    {
        maxlife = m_creature->GetMaxHealth();
		m_creature->MonsterTextEmote(EMOTE_AGGRO,NULL);
    }


    void KilledUnit(Unit* Victim)
    {
            switch(rand()%2)
            {
             case 0:
                 m_creature->MonsterTextEmote(EMOTE_KILL1,NULL);
                 break;
             case 1:
				 m_creature->MonsterTextEmote(EMOTE_KILL2,NULL);
                 break;
            }
    }

    void JustDied(Unit* Killer)
    {
        m_creature->MonsterTextEmote(EMOTE_DEATH,NULL);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() )
            return;

        if (aoefire_timer < diff)
        {
			switch(rand()%3)
			{
			case 1:
				DoCast(m_creature->getVictim(),SPELL_FLAME_EXPLOSION);
			case 2:
				DoCast(m_creature->getVictim(),SPELL_FLAME_BREATH);
			case 0:
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_FIRE_RAIN);
			}
            aoefire_timer = 18000;
        }
        else aoefire_timer -= diff;

        if (singlefire_timer < diff)
        {
			target2 = m_creature->SelectRandomUnfriendlyTarget();
			switch(rand()%3)
			{
			case 1:
				DoCast(target2,SPELL_AMPLIFY_FIRE);
			case 2:
				DoCast(target2,SPELL_FLAME_BUFFET);
			case 0:
				DoCast(target2,SPELL_FIREBALL);
			}
            singlefire_timer = 7000;
        }
        else singlefire_timer -= diff;

        if(shield_timer < diff)
        {
            DoCast(m_creature,SPELL_MAGIC_SHIELD);
			shield_timer = 70000;
        }
        else shield_timer -= diff;

		if(rebirth_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_REBIRTH);
			rebirth_timer = 300000;
        }
        else rebirth_timer -= diff;

		if(meltarmor_timer < diff)
		{
			DoCast(m_creature->getVictim(),SPELL_MELTARMOR);
			meltarmor_timer = 160000;
		}
		else meltarmor_timer -= diff;

		if(weakness_timer < diff)
        {
            DoCast(m_creature,SPELL_FIRE_WEAKNESS);
			weakness_timer = 65000;
        }
        else weakness_timer -= diff;

		hcurrentlife = m_creature->GetHealth()*100;

		if(hcurrentlife / maxlife < 10 && !kill) // ultimo tentativo di disintegrare sto raid...
        {
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
			DoCast(m_creature,SPELL_FLAME_BOMB);
			kill = true;
        }

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_alar_azsc(Creature *_Creature)
{
    return new boss_alarAI (_Creature);
}

void AddSC_boss_alar_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_alar_azsc";
    newscript->GetAI = GetAI_boss_alar_azsc;
    newscript->RegisterSelf();
}
