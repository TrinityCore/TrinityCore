/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_the_lurker_below
SD%Complete: 90
SDComment: yeho gay
EndScriptData */

#include "precompiled.h"

#define SPELL_WATERBALL           37138	        // 8k to 11k dmg. lo faccio ogni 25%. si, probabilmente uccide, ma portarsi dietro un druido serve no?
#define SPELL_WATERVOLLEY         38335			// 2,7k to 3,2k di aoe a 45 yard. (x me: target)
#define SPELL_WATERBUBBLE		  31250			// frostnova a tt
#define SPELL_FROST_AURA		  28531			// 600 dmg ogni sec x 5 sec in 100 yard a tutti (x me: self)
#define SPELL_FROST_BREATH		  21099			// circa 1k dmg, stunx 5 sec in cono di fronte caster
#define SPELL_FROST_MIST	      29292			// rallenta del 75% in 8 yard range x 10 sec., tanto x far qualcosa k nn siano i soliti k di dmg
#define SPELL_FROST_SHOCK         43524			// 2,5k di dmg, random target. lo alterno con switch a freeze
#define SPELL_FROST_VOLLEY	      29923			// 2k di dmg ad area + slow in 20 yard (x me: self)
#define SPELL_WHIRLWIND           26038			// si mette a girare su se stesso k � 1 figata e fa 1k di dmg al secondo a tt qll intorno
#define SPELL_FREEZE			  18763			// stunna x 15 sec e fa circa 150 di danno ogni 3 secondi


struct MANGOS_DLL_DECL boss_the_lurker_belowAI : public ScriptedAI
{
    boss_the_lurker_belowAI (Creature *c) : ScriptedAI(c) 
    {
        Reset();
    }

    uint32 watervolley_Timer;
    uint32 frostaura_Timer;
    uint32 frostbreath_Timer;
    uint32 frostmist_Timer;
    uint32 frostshock_freeze_Timer;
    uint32 frostvolley_Timer;

	int cambia;

	Unit* target;

	uint32 hcurrentlife;	// siccome ne ho parekki di if che usano la vita, preferisco assegnarla una volta sola su update ai, o sbagliorum? ( h = hundred = 100)
	uint32 maxlife;

    void Reset()
    {
        watervolley_Timer = 15000;	// timer diminuisce dopo
        frostaura_Timer = 30000;	// ||
        frostbreath_Timer = 21000;	// ||
        frostmist_Timer = 19000;	// ||
        frostshock_freeze_Timer = 10000;	// ||
        frostvolley_Timer = 45000;	// ||

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
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);

		maxlife = m_creature->GetMaxHealth();

		cambia = 0;
    }

    void KilledUnit(Unit *victim)
    {

    }

    void JustDied(Unit *victim)
    {

    }

    void Aggro(Unit *who)
    {        

    }
    
    void UpdateAI(const uint32 diff)
    {
        // lol     
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if(frostshock_freeze_Timer < diff)
        {   
            target = m_creature->SelectRandomUnfriendlyTarget();
            switch(rand()%3)
            {
                case 0:
                DoCast(target,SPELL_FROST_SHOCK);
                break;

                case 1:
                DoCast(target,SPELL_FREEZE);
                break;
            }
            frostshock_freeze_Timer = 15000;
        }else frostshock_freeze_Timer -= diff;

		if(watervolley_Timer < diff)
        {   
            DoCast(m_creature->getVictim(),SPELL_WATERVOLLEY);
            watervolley_Timer = 7000;
        }else watervolley_Timer -= diff;

		if(frostaura_Timer < diff)
        {   
            DoCast(m_creature,SPELL_FROST_AURA);
            frostaura_Timer = 10000;
        }else frostaura_Timer -= diff;

		if(frostvolley_Timer < diff)
        {   
            DoCast(m_creature,SPELL_FROST_VOLLEY);
            frostvolley_Timer = 8000;
        }else frostvolley_Timer -= diff;

		hcurrentlife = m_creature->GetHealth()*100;

        if(hcurrentlife / maxlife < 80) // al 80% inizia il divertimento. ahahah!
        {
            switch(cambia)  // aumento var cambia ogni volta k la vita diminuisce e quindi faccio 1 cast, � come memorizzare il livello di vita corrente.
			{
				//efficiente e professionale, by edoz.
				case 0:
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
					cambia++;
                break;
				case 1:
				if(hcurrentlife / maxlife < 72)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					
					DoCast(m_creature->getVictim(), SPELL_WATERBUBBLE);
					cambia++;
				}
                break;
				case 2:
				if(hcurrentlife / maxlife < 65)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_WATERBALL);
					cambia++;
				}
                break;
				case 3:
				if(hcurrentlife / maxlife < 60)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
					cambia++;
				}
                break;
				case 4:
				if(hcurrentlife / maxlife < 55)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					
					DoCast(m_creature->getVictim(), SPELL_WATERBUBBLE);
					cambia++;
				}
                break;
				case 5:
				if(hcurrentlife / maxlife < 45)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_WATERBALL);
					cambia++;
				}
                break;
				case 6:
				if(hcurrentlife / maxlife < 35)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
					cambia++;
				}
                break;
				case 7:
				if(hcurrentlife / maxlife < 30)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(), SPELL_WATERBUBBLE);
					cambia++;
				}
                break;
				case 8:
				if(hcurrentlife / maxlife < 20)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}

					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_WATERBALL);
					cambia++;
				}
                break;
				case 9:
				if(hcurrentlife / maxlife < 15)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
					cambia++;
				}
                break;
				case 10:
				if(hcurrentlife / maxlife < 10)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					
					DoCast(m_creature->getVictim(), SPELL_WATERBUBBLE);
					cambia++;
				}
                break;
				case 11:
				if(hcurrentlife / maxlife < 5)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					switch(rand()%2)
					{
					case 0:
						break;
					case 1:
						break;
					}
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_WATERBALL);
					cambia++;
				}
                break;
				case 12:
				if(hcurrentlife / maxlife < 2)
				{
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
					cambia++;
				}
                break;
			}
        }

        DoMeleeAttackIfReady();
    }
}; 
CreatureAI* GetAI_boss_the_lurker_below(Creature *_Creature)
{
    return new boss_the_lurker_belowAI (_Creature);
}

void AddSC_boss_the_lurker_below_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_the_lurker_below_azsc";
    newscript->GetAI = GetAI_boss_the_lurker_below;
    newscript->RegisterSelf();
}
