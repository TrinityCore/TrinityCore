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
SDName: boss_thrall
SD%Complete: 100
SDComment: 
EndScriptData */

#include "precompiled.h"

#define SPELL_LIGHTNINGBOLT_VOLLEY	38839	// volley di lightning bolt: 2,8k a tt il raid (40yard range)
#define SPELL_CHAIN_LIGHTNING		40536	// chain lighting da 7k, up to 5 targets.
#define SPELL_FIRE_SHOCK			43303	// circa 3,5k iniziali, 2,5k ogni 3 sec x 12 sec
#define SPELL_EARTH_SHOCK			43305	// 4,5k + interrompe cast
#define SPELL_FROST_SHOCK			38234	// 6k + -70% speed x 8 sec
#define SPELL_EARTHQUAKE			37764	// earthquake da 4k, bello xk trema tt lo skermo

#define SAY_AGGRO1	"Tempesta, terra e fuoco, rispondete al mio richiamo!"
#define SAY_AGGRO2	"Lok'tar fratelli! Lok'tar!"
#define SAY_SUMMON1	"Gli spiriti vegliano su di me!"
#define SAY_SUMMON2	"Invoco l'antico potere! Spiriti, a me!"
#define SAY_SUMMON3	"Non c'e' vittoria contro il potere degli spiriti!"
#define SAY_KILL1	"Per Doomhammer!"
#define SAY_KILL2	"Hellscream vive ancora!"
#define SAY_KILL3	"Questa e' l'orda, questa e' la sua furia!"
#define SAY_DEATH1	"Per l'Orda...per i suoi figli..."
#define SAY_DEATH2	"Potete sconfiggere me, ma non sconfiggerete mai l'Orda!"
#define SAY_DEATH3	"L'Orda riuscira' dove io ho fallito..."

#define WOLF_SPAWN1	20748	// "thunderlord dire wolf" - lvl 66 - 5k di vita
#define WOLF_SPAWN2	20058	// "bloodmaul dire wolf" - lvl 63 - 6k di vita

#define SOUND_AGGRO		5880
#define SOUND_1			10454
#define SOUND_2         10449
#define SOUND_3         10450
#define SOUND_4         10452
#define SOUND_5         10453

struct MANGOS_DLL_DECL boss_thrallAI : public ScriptedAI
{
    boss_thrallAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 spell_timer;
	uint32 summon_timer;
	uint32 sound_timer;
	int spell;

	Unit* target;
	Unit* target2;
	Creature* spawn;

    void Reset()
    {
		spell_timer = 5000;
		summon_timer = 43000;
		sound_timer = 45000;

		spell = 0;

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

        //m_creature->RemoveAllAuras();
        //m_creature->DeleteThreatList();
        //m_creature->CombatStop();
        //DoGoHome();
    }

    void Aggro(Unit *who)
    {
            	switch(rand()%2)
					{
					case 0:
						m_creature->MonsterYell(SAY_AGGRO1,LANG_UNIVERSAL,NULL);
						m_creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
						break;
					case 1:
						m_creature->MonsterYell(SAY_AGGRO2,LANG_UNIVERSAL,NULL);
						m_creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
						break;
					}
    }

	void JustDied(Unit *killer)
    {
        switch(rand()%3)
		{
		case 0:
			m_creature->MonsterYell(SAY_DEATH1,LANG_UNIVERSAL,NULL);
			break;
		case 1:
			m_creature->MonsterYell(SAY_DEATH2,LANG_UNIVERSAL,NULL);
			break;
		case 2:
			m_creature->MonsterYell(SAY_DEATH3,LANG_UNIVERSAL,NULL);
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

		if (sound_timer < diff)
        {
			switch(rand()%5)
            {
             case 0:
                 DoPlaySoundToSet(m_creature, SOUND_1);
                 break;
             case 1:
				 DoPlaySoundToSet(m_creature, SOUND_2);
                 break;
			 case 2:
				 DoPlaySoundToSet(m_creature, SOUND_3);
				 break;
			 case 3:
				 DoPlaySoundToSet(m_creature, SOUND_4);
				 break;
			 case 4:
				 DoPlaySoundToSet(m_creature, SOUND_5);
				 break;
            }
            sound_timer = 30000;
        }
		else sound_timer -= diff;

        //spell timer generale, 1 spell ogni 5 secondi, a rotazione tra quelle definite
        if (spell_timer < diff)
        {
			target2 = m_creature->SelectRandomUnfriendlyTarget();
            switch(spell)
			{
			case 0:
				DoCast(m_creature, SPELL_LIGHTNINGBOLT_VOLLEY);
			case 1:
				DoCast(target, SPELL_EARTH_SHOCK);
			case 2:
				DoCast(m_creature, SPELL_EARTHQUAKE);
			case 3:
				DoCast(target2, SPELL_CHAIN_LIGHTNING);
			case 4:
				DoCast(target2, SPELL_FROST_SHOCK);
			case 5:
				DoCast(target2, SPELL_FIRE_SHOCK);
			}
			spell++;

			if(spell > 5)
				spell = 0;

            spell_timer = 5000;
        }else spell_timer -= diff;

        // summon.
        if (summon_timer < diff)
        {

			switch(rand()%3)
			{
			case 0:
				m_creature->MonsterYell(SAY_SUMMON1,LANG_UNIVERSAL,NULL);
				break;
			case 1:
				m_creature->MonsterYell(SAY_SUMMON2,LANG_UNIVERSAL,NULL);
				break;
			case 2:
				m_creature->MonsterYell(SAY_SUMMON3,LANG_UNIVERSAL,NULL);
				break;
			}

            for(int i = 0; i <= 3; i++)
			{
				target = m_creature->SelectRandomUnfriendlyTarget();
				if(target)
				{
				switch(rand()%2)
				{
				case 0:
					spawn = NULL;
					spawn = m_creature->SummonCreature(WOLF_SPAWN1,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,360000);
					if (spawn && spawn->isAlive())
					{
						spawn->AI()->AttackStart(target);
                        spawn->AddThreat(target,1000.0f);
						spawn->setFaction(m_creature->getFaction());
					}
				case 1:
					spawn = NULL;
					spawn = m_creature->SummonCreature(WOLF_SPAWN2,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,360000);
					if (spawn && spawn->isAlive())
					{
						spawn->AI()->AttackStart(target);
                        spawn->AddThreat(target,1000.0f);
						spawn->setFaction(m_creature->getFaction());
					}
				}
				}

			}

            summon_timer = 160000;
        }else summon_timer -= diff;
        
        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_thrall_azsc(Creature *_Creature)
{
    return new boss_thrallAI (_Creature);
}


void AddSC_boss_thrall_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_thrall_azsc";
    newscript->GetAI = GetAI_boss_thrall_azsc;
    newscript->RegisterSelf();
}
