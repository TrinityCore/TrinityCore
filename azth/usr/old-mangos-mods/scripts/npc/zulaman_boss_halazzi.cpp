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
SDName: boss_halazzi
SD%Complete: 100
SDComment: 
EndScriptData */

#include "precompiled.h"

#define SPELL_FRENZY			43139	// x 6 sec aumenta attack speed del 100% (nel senso k si velocizza. pu� essere dispellato da lock e hunter.)
#define SPELL_EVASION			15087	// +50% dodge x 15 sec
#define SPELL_DISARM			30013	// disarma x 8 secondi
#define SPELL_REND				36965	// 2250 dmg ogni 3 sec x 15 sec
#define SPELL_CLEAVE			31345	// weapon dmg + 1,4k 5 yard range

#define SPELL_SHAPESHIFT		42607	// diventa 1 lince

#define SPELL_LYNX_RUSH			43153	// 2,2k + 7,5k over 10 sec
#define SPELL_SHRED_ARMOR		31042	// riduce armor di 5k x 8 sec
#define SPELL_FERAL_SWIPE		43357	// 3,5k-4k di danno al target, e -35% velocit� x 8 sec
#define SPELL_RAVENOUS_CLAW		17470	// draina 1k di vita dal target. (5 yard)

#define SAY_AGGRO	"Ingninokkiatevi a zanna e artigli!"
#define SAY_SUMMON1	"Addoszo! Ingozzatevi zi carne, bestie!"
#define SAY_SUMMON2	"Mangiate sporki nemizi!"
#define SAY_KILL1	"Lasciate il mondo in pezi!"
#define SAY_KILL2	"Io vi uccide!"
#define SAY_KILL3	"Cacciatore vinze!"
#define SAY_DEATH1	"Chaga... choka'jin"
#define SAY_DEATH2	"Amani.. vive ancora"

#define LYNX_SPAWN1	24530	// lince, lvl 70 elite, 27k vita
#define LYNX_SPAWN2	24064	// lince cucciola, lvl 70 nn elite, 29k di vita, fa 1 spell k riduce x 3 sec stamina del 15%, e fa anke il suo moderato danno ai cloth!

struct MANGOS_DLL_DECL boss_halazziAI : public ScriptedAI
{
    boss_halazziAI(Creature *c) : ScriptedAI(c) {Reset();}

	uint32 summon_timer;

	uint32 frenzy_timer, evasion_timer, disarm_timer, rend_timer, cleave_timer;

	uint32 lynxrush_timer, shredarmor_timer, feralswipe_timer, ravenousclaw_timer, aggrowipe_timer;

	int phase;

	bool shapeshifted;

	Unit* target;
	Unit* target2;
	Creature* spawn1;
	Creature* spawn2;

    void Reset()
    {
		phase = 1;

		summon_timer = 45000;

		frenzy_timer = 30000;
		evasion_timer = 65000;
		disarm_timer = 41000;
		rend_timer = 26000;
		cleave_timer = 13000;

		lynxrush_timer = 35000;
		shredarmor_timer = 20000;
		feralswipe_timer = 25000;
		ravenousclaw_timer = 9000;
		aggrowipe_timer = 30000;

		shapeshifted = false;

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
		m_creature->MonsterYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
		m_creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
    }

	void JustDied(Unit *killer)
    {
        switch(rand()%2)
		{
		case 0:
			m_creature->MonsterYell(SAY_DEATH1,LANG_UNIVERSAL,NULL);
			break;
		case 1:
			m_creature->MonsterYell(SAY_DEATH2,LANG_UNIVERSAL,NULL);
			break;
		}
    }

	void KilledUnit(Unit* Victim)
    {
        switch(rand()%3)
		{
		case 0:
			m_creature->MonsterYell(SAY_KILL1,LANG_UNIVERSAL,NULL);
			break;
		case 1:
			m_creature->MonsterYell(SAY_KILL2,LANG_UNIVERSAL,NULL);
			break;
		case 2:
			m_creature->MonsterYell(SAY_KILL3,LANG_UNIVERSAL,NULL);
			break;
		}
    }

    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;


        if(phase == 1)
		{
			if (frenzy_timer < diff)
            { 
                DoCast(m_creature, SPELL_FRENZY);
                frenzy_timer = 30000;
            }else frenzy_timer -= diff;

			if (evasion_timer < diff)
            { 
                DoCast(m_creature, SPELL_EVASION);
                evasion_timer = 65000;
            }else evasion_timer -= diff;

			if (disarm_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_DISARM);
                disarm_timer = 41000;
            }else disarm_timer -= diff;

			if (rend_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_REND);
                rend_timer = 41000;
            }else rend_timer -= diff;

			if (cleave_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                cleave_timer = 41000;
            }else cleave_timer -= diff;

			// summon
			if (summon_timer < diff)
			{

				switch(rand()%2)
				{
				case 0:
					m_creature->MonsterYell(SAY_SUMMON1,LANG_UNIVERSAL,NULL);
					break;
				case 1:
					m_creature->MonsterYell(SAY_SUMMON2,LANG_UNIVERSAL,NULL);
					break;
				}

				target = m_creature->SelectRandomUnfriendlyTarget();
				if(target)
				{
					spawn1 = NULL;
					spawn1 = m_creature->SummonCreature(LYNX_SPAWN1,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,360000);
					if (spawn1)
					{
						spawn1->AI()->AttackStart(target);
						spawn1->AddThreat(target,10000.0f);
						spawn1->setFaction(m_creature->getFaction());
					}

				}

				target = m_creature->SelectRandomUnfriendlyTarget();
				if(target)
				{
					spawn2 = NULL;
					spawn2 = m_creature->SummonCreature(LYNX_SPAWN2,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,360000);
					if (spawn2)
					{
						spawn2->AI()->AttackStart(target);
						spawn2->AddThreat(target,10000.0f);
						spawn2->setFaction(m_creature->getFaction());
					}

				}

				summon_timer = 40000;
			}else summon_timer -= diff;

			if ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 50)
				phase = 2;
		}
		else
		{
			if(!shapeshifted)
			{
				// mi assicuro completamente k sta spell venga castata, quindi interrompo TUTTE le altre.
				m_creature->InterruptNonMeleeSpells(false);
				m_creature->InterruptNonMeleeSpells(true);
				m_creature->InterruptSpell(CURRENT_GENERIC_SPELL,false);
			    m_creature->InterruptSpell(CURRENT_GENERIC_SPELL,true);
				DoCast(m_creature, SPELL_SHAPESHIFT);
				shapeshifted = true;
				phase = 2;
			}

			if (aggrowipe_timer < diff)
            { 
				target = m_creature->SelectRandomUnfriendlyTarget();
                DoResetThreat();
				if(target)
					m_creature->AddThreat(target, 90000.0f);
                aggrowipe_timer = 30000;
            }else aggrowipe_timer -= diff;

			if (shredarmor_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_SHRED_ARMOR);
                shredarmor_timer = 10000;
            }else shredarmor_timer -= diff;

			if (feralswipe_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_FERAL_SWIPE);
                feralswipe_timer = 15000;
            }else feralswipe_timer -= diff;

			if (ravenousclaw_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_RAVENOUS_CLAW);
                ravenousclaw_timer = 7000;
            }else ravenousclaw_timer -= diff;

			if (lynxrush_timer < diff)
            { 
                DoCast(m_creature->getVictim(), SPELL_LYNX_RUSH);
                lynxrush_timer = 20000;
            }else lynxrush_timer -= diff;

		}			
        
        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_halazzi_azsc(Creature *_Creature)
{
    return new boss_halazziAI (_Creature);
}


void AddSC_boss_halazzi_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_halazzi_azsc";
    newscript->GetAI = GetAI_boss_halazzi_azsc;
    newscript->RegisterSelf();
}