/* Copyright ?2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Brutallus
SD%Complete: 90
SDComment: Burn gets casted on himself and intro is missing.
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"

// Yells and Sounds used by boss.
#define YELL_AGGRO			"Ahh! More lambs to the slaughter!"
#define SOUND_AGGRO 		12463

#define YELL_BERSERK 		"So much for a real challenge... Die!"
#define SOUND_BERSERK 		12470

#define YELL_KILL1 			"Perish, insect!"
#define SOUND_KILL1 		12464

#define YELL_KILL2			"You are meat!"
#define SOUND_KILL2 		12465
	
#define YELL_KILL3 			"Too easy!"
#define SOUND_KILL3 		12466

#define YELL_CHARGE 		"I will crush you!"
#define SOUND_CHARGE 		12460

#define YELL_DEATH 			"Gah! Well done... Now... this gets... interesting..."
#define SOUND_DEATH 		12471

#define YELL_LOVE1 			"Bring the fight to me!"
#define SOUND_LOVE1 		12467

#define YELL_LOVE2 			"Another day, another glorious battle!"
#define SOUND_LOVE2 		12468

#define YELL_LOVE3 			"I live for this!"
#define SOUND_LOVE3 		12469

// Boss spells.
#define SPELL_METEOR_SLASH 		45150
#define SPELL_BURN 				46394
#define SPELL_STOMP 			45185
#define SPELL_BERSERK 			26662
#define SPELL_DUAL_WIELD                42459

struct TRINITY_DLL_DECL boss_brutallusAI : public ScriptedAI
{
    boss_brutallusAI(Creature *c) : ScriptedAI(c) { Reset(); }

    uint32 SlashTimer;
    uint32 BurnTimer;
    uint32 StompTimer;
    uint32 BerserkTimer;

    void Reset()
    {
        SlashTimer = 11000;
        StompTimer = 30000;
        BurnTimer = 60000;
        BerserkTimer = 360000;
        m_creature->CastSpell(m_creature, SPELL_DUAL_WIELD, true);
    }

    void Aggro(Unit *who)
    {
        DoYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(YELL_KILL1,LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_KILL1);
                break;
            case 1:
                DoYell(YELL_KILL2,LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_KILL2);
                break;
            case 2:
                DoYell(YELL_KILL3,LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_KILL3);
                break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoYell(YELL_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if(SlashTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_METEOR_SLASH);
            SlashTimer = 11000;
        }else SlashTimer -= diff;

        if(StompTimer < diff)
        {
			switch(rand()%3)
			{
				case 0:
					DoYell(YELL_LOVE1,LANG_UNIVERSAL, NULL);
					DoPlaySoundToSet(m_creature, SOUND_LOVE1);
					break;
				case 1:
					DoYell(YELL_LOVE2,LANG_UNIVERSAL, NULL);
					DoPlaySoundToSet(m_creature, SOUND_LOVE2);
					break;
				case 2:
					DoYell(YELL_LOVE3,LANG_UNIVERSAL, NULL);
					DoPlaySoundToSet(m_creature, SOUND_LOVE3);
					break;
			}
            
			Unit *Target = m_creature->getVictim();
            DoCast(Target,SPELL_STOMP);
            if(Target->HasAura(45151,0)) Target->RemoveAura(45151,0);
            StompTimer = 30000;
        }else StompTimer -= diff;

        if(BurnTimer < diff)
        {
            if(Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                target->CastSpell(target,SPELL_BURN,true);
			BurnTimer = 60000;
        }
        else BurnTimer -= diff;

        DoMeleeAttackIfReady();

        if(BerserkTimer < diff)
        {
            DoYell(YELL_BERSERK,LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_BERSERK);
            DoCast(m_creature,SPELL_BERSERK);
            BerserkTimer = 20000;
        }
        else BerserkTimer -= diff;
    }

};

CreatureAI* GetAI_boss_brutallus(Creature *_Creature)
{
    return new boss_brutallusAI (_Creature);
}

void AddSC_boss_brutallus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_brutallus";
    newscript->GetAI = GetAI_boss_brutallus;
    m_scripts[nrscripts++] = newscript;
}
