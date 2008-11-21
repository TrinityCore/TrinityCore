/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_the_lurker_below
SD%Complete: 10
SDComment:
SDCategory: The Lurker Below
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"
#include "../../../creature/simple_ai.h"
#include "Spell.h"

#define SPELL_SPOUT			37433
#define SPELL_SPOUT_2		42835
#define SPELL_KNOCKBACK		19813
#define SPELL_GEYSER		37478
#define SPELL_WHIRL			37660
#define SPELL_WATERBOLT		37138
#define SPELL_SUBMERGE		37550
#define SPELL_EMERGE		20568

#define EMOTE_SPOUT	"takes a deep breath."

#define MOB_COILFANG_GUARDIAN 21873
#define MOB_COILFANG_AMBUSHER 21865

//Ambusher spells
#define SPELL_SPREAD_SHOT	37790
#define SPELL_SHOOT			37770

//Guardian spells
#define SPELL_ARCINGSMASH	38761 // Wrong SpellId. Can't find the right one.
#define SPELL_HAMSTRING		26211

struct TRINITY_DLL_DECL boss_the_lurker_belowAI : public ScriptedAI
{
    boss_the_lurker_belowAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
		
	}

    void MoveInLineOfSight(Unit *who)
    {

    }

	void Aggro(Unit *who)
    {
		
    }

	void UpdateAI(const uint32 diff)
    {
		
	}
};

CreatureAI* GetAI_mob_coilfang_guardian(Creature *_Creature)
{
    SimpleAI* ai = new SimpleAI (_Creature);

    ai->Spell[0].Enabled = true;
    ai->Spell[0].Spell_Id = SPELL_ARCINGSMASH;
    ai->Spell[0].Cooldown = 15000;
    ai->Spell[0].First_Cast = 5000;
    ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->Spell[1].Enabled = true;
    ai->Spell[1].Spell_Id = SPELL_HAMSTRING;
    ai->Spell[1].Cooldown = 10000;
    ai->Spell[1].First_Cast = 2000;
    ai->Spell[1].Cast_Target_Type = CAST_HOSTILE_TARGET;

	return ai;
}

struct TRINITY_DLL_DECL mob_coilfang_ambusherAI : public Scripted_NoMovementAI
{
    mob_coilfang_ambusherAI(Creature *c) : Scripted_NoMovementAI(c) 
	{
		Reset();
		SpellEntry *TempSpell = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_SHOOT);
        if(TempSpell)
			TempSpell->Effect[0] = 2;//change spell effect from weapon % dmg to simple phisical dmg
	}

	uint32 MultiShotTimer;
	uint32 ShootBowTimer;
    
    void Reset()
    {
		MultiShotTimer = 10000;
		ShootBowTimer = 4000;

	}

	void Aggro(Unit *who)
    {
		
    }

    void MoveInLineOfSight(Unit *who)
	{
		if (!who || m_creature->getVictim()) return;

		if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
			AttackStart(who);
        }
	}

	void UpdateAI(const uint32 diff)
    {
		if(MultiShotTimer < diff)
		{
			if(m_creature->getVictim())			
				DoCast(m_creature->getVictim(), SPELL_SPREAD_SHOT, true);

			MultiShotTimer = 10000;
			ShootBowTimer += 1500;//add global cooldown
		}else MultiShotTimer -= diff;

		if(ShootBowTimer < diff)
		{
			Unit* target = NULL;
			target = SelectUnit(SELECT_TARGET_RANDOM, 0);	
			int bp0 = 1100;
			if(target)
				m_creature->CastCustomSpell(target,SPELL_SHOOT,&bp0,NULL,NULL,true);
			ShootBowTimer = 4000;
			MultiShotTimer += 1500;//add global cooldown
		}else ShootBowTimer -= diff;
	}
};

CreatureAI* GetAI_mob_coilfang_ambusher(Creature *_Creature)
{
    return new mob_coilfang_ambusherAI (_Creature);
}

CreatureAI* GetAI_boss_the_lurker_below(Creature *_Creature)
{
    return new boss_the_lurker_belowAI (_Creature);
}

void AddSC_boss_the_lurker_below()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_the_lurker_below";
    newscript->GetAI = GetAI_boss_the_lurker_below;
    newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="mob_coilfang_guardian";
    newscript->GetAI = GetAI_mob_coilfang_guardian;
    newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="mob_coilfang_ambusher";
    newscript->GetAI = GetAI_mob_coilfang_ambusher;
    newscript->RegisterSelf();
}

