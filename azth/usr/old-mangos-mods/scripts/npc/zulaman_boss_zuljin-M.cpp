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


ScriptData
SDName: boss_zuljin
SD%Complete: 100
SDComment: need test!
EndScriptData */

#include "precompiled.h"
#include "../../../../game/ZZ_ScriptsPersonali.h"

// spell x trasformarsi

#define FORM_BEAR				42594
#define FORM_EAGLE				42606
#define FORM_LYNX				42607
#define FORM_DRAGONHAWK			42608

// spell da troll

#define SPELL_THROW				37074	        // 250% weapon dmg
#define SPELL_WHIRLWIND         17207			// si mette a girare su se stesso e fa weapon dmg

// spell da bear

#define SPELL_KNOCKBACK			11027			// knockback enorme. gli fcc uccidere (90% muore, se nn ha culo di beccare il muro) il tanker.
#define SPELL_OVERPOWER			43456			// 125% dmg, istant attack.
#define SPELL_CHARGE			35570			// 1 bel charge, treath wipe e taunt immune.

// spell da eagle

#define SPELL_WIND_SHOCK		39261			// fa un dmg basso, ma rallenta speed (cast, ranged, melee) del 50% x 10 sec
#define SPELL_CLAW				17470			// colpisce il target, 1k dmg e la vita tolta cura il caster. (drain insomma)

	// spell del tornado evocato in eagle form
	#define SPELL_HARSH_WINDS		25161			// 2k dmg, silence x 1 sec, -85% speed x 1 sec
	#define SPELL_WIND_BLAST		43620			// knockback da poco. nn lo uso spesso

// spell da lynx

#define SPELL_LYNX_RUSH			43153			// 2k dmg + 7500 over 10 sec. 80 yard range, single target
#define	SPELL_CLEAVE			31043			// weapon dmg + 500, 3 target. istant.

// spell da dragonhawk

#define SPELL_FLAME_WHIRL       43213			// gira su se stesso veloce, sputa fuoco, mette 1 debuff +50% fire dmg ricevuto, e fa 1k fire dmg.
#define SPELL_FLAME_BREATH		43215			// flame breath tipico. target.
#define SPELL_FLAME_COLUMN		43218			// vengon gi� fiamme dall'alto e fan dmg a qll vicini (self)
#define SPELL_FIRE_SHIELD		38933			// 500 dmg ogni 3 sec x 10 min a quelli intorno a s�, self.
#define SPELL_FIREBALL			41484			// 6,8k dmg circa, + 600 over 3 sec. 40 yard range, single target


#define SAY_AGGRO				"Nobody badduh dan me! $N, PREPARE TO DIE!"
#define SOUND_AGGRO				12091
#define SAY_BEAR				"Got me some new tricks...like me bruddah bear! Muhah!"
#define SOUND_BEAR				12092
#define SAY_EAGLE				"Dere be no hidin' from da eagle!"
#define SOUND_EAGLE				12093
#define SAY_DRAGONHAWK          "Ya don' have to look to da sky to see da dragonhawk!"
#define SOUND_DRAGONHAWK		12095
#define SAY_LYNX	            "Let me introduce to you my new bruddahs: fang and claw!"
#define SOUND_LYNX				12094
#define SAY_SLAY1               "Da Amani de chuka!"
#define SOUND_SLAY1				12098
#define SAY_SLAY2               "Lot more gonna fall like $N!"
#define SOUND_SLAY2				12099
#define SAY_DEATH               "Mebbe me fall...but da Amani empire...never gonna die..."
#define SOUND_DEATH				12100

//#define SAY_SIGHT				"Everybody always wanna take from us. Now we gonna start takin' back. Anybody who get in our way...gonna drown in their own blood! De Amani empire be back now...seekin' vengeance. And we gonna start...with you!"

struct MANGOS_DLL_DECL boss_zuljinAI : public ScriptedAI
{
    boss_zuljinAI (Creature *c) : ScriptedAI(c) 
    {
        Reset();
    }

    uint32 throw_Timer;
    uint32 whirlwind_Timer;

    uint32 overpower_Timer;
    uint32 charge_Timer;

	uint32 windshock_Timer;
	uint32 claw_Timer;

	uint32 rush_Timer;
	uint32 cleave_Timer;
	uint32 changeaggro_Timer;

    uint32 flame_whirl_Timer;
	uint32 flamewhirl_Timer;	// ne ho due ma � xk devo fargli castare ogni 30 secondi 9 volte la spell, ovviamente nn posso usare un ciclo for, uso 1 timer piccolo
	uint32 times_Timer;
    uint32 flamebreath_Timer;
	uint32 flamecolumn_Timer;
	uint32 fireball_Timer;

	uint32 special_Timer;

	Creature* Twist1;
	Creature* Twist2;

	ObjectGuid Twist1Guid,Twist2Guid;

	bool twist1summoned, twist2summoned, special, doflame;

	int phase;
	int whirl_count;

	Unit* target;

	uint32 hcurrentlife;	// siccome ne ho parekki di if che usano la vita, preferisco assegnarla una volta sola su update ai, o sbagliorum? ( h = hundred = 100)
	uint32 maxlife;

    void Reset()
    {
        throw_Timer = 15000;
        whirlwind_Timer = 10000;	// rimane 10 secondi. questa form non � particolarmente difficile, serve a rilassare il raid x pwnarlo in seguito.

        overpower_Timer = 6000;	// rimane 6
        charge_Timer = 40000;	// rimane 40 sec

        windshock_Timer = 8000;	// rimane 8
        claw_Timer = 3000;	// rimane 3 sec. qst fase durer� di + proprio xk si cura

		rush_Timer = 6500;
		cleave_Timer = 5000;
		changeaggro_Timer = 17000;

		flame_whirl_Timer = 30000;
		flamewhirl_Timer = 2000;
		flamebreath_Timer = 10000;
		flamecolumn_Timer = 1000;	// dopo diventa 30 sec xk dura 25 sec
		fireball_Timer = 9000;

		special_Timer = 3500;

		special = false;
		doflame = false;

		whirl_count = 0;

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

		phase = 0;
		if(twist1summoned)
		{
			Twist1 = NULL;
			Twist1 = ((Creature*)ObjectAccessor::GetUnit((*m_creature), Twist1Guid));
			if(Twist1 && Twist1->isAlive())
			{
				Twist1->SetVisibility(VISIBILITY_OFF);
				Twist1->DealDamage(Twist1, Twist1->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
				Twist1 = NULL;
				twist1summoned = false;
			}
		}
		if(twist2summoned)
		{
			Twist2 = NULL;
			Twist2 = ((Creature*)ObjectAccessor::GetUnit((*m_creature), Twist2Guid));
			if(Twist2 && Twist2->isAlive())
			{
				Twist2->SetVisibility(VISIBILITY_OFF);
				Twist2->DealDamage(Twist2, Twist2->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
				Twist2 = NULL;
				twist2summoned = false;
			}
		}
    }

    void KilledUnit(Unit *victim)
    {
		switch(rand()%2)
            {
                case 0:
                m_creature->MonsterYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
				DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;

                case 1:
                m_creature->MonsterYell(SAY_SLAY2, LANG_UNIVERSAL, victim);
				DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
            }
    }

    void JustDied(Unit *victim)
    {
        m_creature->MonsterYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
		DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
		maxlife = m_creature->GetMaxHealth();
        m_creature->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, who);
		DoPlaySoundToSet(m_creature, SOUND_AGGRO);
		m_creature->SetInCombatWithZone();
    }

    void UpdateAI(const uint32 diff)
    {
        // lol
		
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

		if(phase == 0)
		{
			if(throw_Timer < diff)
			{   
				target = m_creature->SelectRandomUnfriendlyTarget();
				if(target)
					DoCast(target,SPELL_THROW);
				throw_Timer = 10000;
			}else throw_Timer -= diff;

			if(whirlwind_Timer < diff)
			{   
				DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
				whirlwind_Timer = 10000;
			}else whirlwind_Timer -= diff;
		}
		else if(phase == 1)
		{
			if(special)
			{
				if(special_Timer < diff)
				{
					special = false;
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_KNOCKBACK);
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoResetThreat();
					if(target)
						m_creature->AddThreat(target, 90000.0f);
					special_Timer = 3500;
				}
				else special_Timer -= diff;
			}
			else
			{
				if(overpower_Timer < diff)
				{   
					DoCast(m_creature->getVictim(),SPELL_OVERPOWER);
					overpower_Timer = 6000;
				}else overpower_Timer -= diff;

				if(charge_Timer < diff)
				{   
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoResetThreat();
					if(target)
						m_creature->AddThreat(target, 90000.0f);
					DoCast(target,SPELL_CHARGE);
					charge_Timer = 40000;
				}else charge_Timer -= diff;
			}
		}
		else if(phase == 2)
		{
			if(windshock_Timer < diff)
			{   
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_WIND_SHOCK);
				windshock_Timer = 8000;
			}else windshock_Timer -= diff;

			if(claw_Timer < diff)
			{   
				DoCast(m_creature->getVictim(),SPELL_CLAW);
				claw_Timer = 3000;
			}else claw_Timer -= diff;
		}
		else if(phase == 3)
		{
			if(rush_Timer < diff)
			{   
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_LYNX_RUSH);
				rush_Timer = 5500;
			}else rush_Timer -= diff;

			if(cleave_Timer < diff)
			{   
				DoCast(m_creature->getVictim(),SPELL_CLEAVE);
				cleave_Timer = 3500;
			}else cleave_Timer -= diff;

			if(changeaggro_Timer < diff)
			{  
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoResetThreat();
				if(target)
					m_creature->AddThreat(target, 90000.0f);
				changeaggro_Timer = 18000;
			}else changeaggro_Timer -= diff;
		}
		else if(phase == 4)
		{
			if(special)
			{
				if(special_Timer < diff)
				{
					special = false;
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature,SPELL_FIRE_SHIELD);
					special_Timer = 3500;
				}
				else special_Timer -= diff;
			}
			else if(doflame)
			{
				if(flamewhirl_Timer < diff)
				{ 
					m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
					DoCast(m_creature->getVictim(),SPELL_FLAME_WHIRL);
					flamewhirl_Timer = 1500;
					whirl_count++;
					if(whirl_count == 5)
						doflame = false;

				}else flamewhirl_Timer -= diff;
			}
			else
			{
				if(flamecolumn_Timer < diff)
				{   
					DoCast(m_creature,SPELL_FLAME_COLUMN);
					flamecolumn_Timer = 35000;
				}else flamecolumn_Timer -= diff;

				if(flamebreath_Timer < diff)
				{   
					DoCast(m_creature->getVictim(),SPELL_FLAME_BREATH);
					flamebreath_Timer = 10000;
				}else flamebreath_Timer -= diff;

				if(flame_whirl_Timer < diff)
				{   
					whirl_count = 0;
					doflame = true;
					flame_whirl_Timer = 30000;
				}else flame_whirl_Timer -= diff;

				if(fireball_Timer < diff)
				{   
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_FIREBALL);
					fireball_Timer = 28000;
				}else fireball_Timer -= diff;
			}
		}

		hcurrentlife = m_creature->GetHealth()*100;

        if(phase == 0 && hcurrentlife / maxlife < 80)
        {   
            phase = 1;
			special = true;
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
			m_creature->InterruptNonMeleeSpells(false);
			m_creature->MonsterYell(SAY_BEAR, LANG_UNIVERSAL, NULL);
			DoPlaySoundToSet(m_creature, SOUND_BEAR);
			DoCast(m_creature,FORM_BEAR);
        }

		if(phase == 1 && hcurrentlife / maxlife < 60)
        {   
            phase = 2;
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
			m_creature->InterruptNonMeleeSpells(false);
			m_creature->MonsterYell(SAY_EAGLE, LANG_UNIVERSAL, NULL);
			DoPlaySoundToSet(m_creature, SOUND_EAGLE);
			DoCast(m_creature,FORM_EAGLE);
			target = m_creature->SelectRandomUnfriendlyTarget();
			if(target)
			{
				Twist1 = m_creature->SummonCreature(24136,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_CORPSE_DESPAWN,0);
				if (Twist1 && Twist1->isAlive())
				{
					Twist1->SetVisibility(VISIBILITY_ON);
					Twist1->AI()->AttackStart(target);
					Twist1->setFaction(m_creature->getFaction());
					twist1summoned = true;
					Twist1Guid = Twist1->GetObjectGuid();
				}
			}
			target = m_creature->SelectRandomUnfriendlyTarget();
			if(target)
			{
				Twist2 = m_creature->SummonCreature(24136,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_CORPSE_DESPAWN,0);
				if (Twist2 && Twist2->isAlive())
				{
					Twist2->AI()->AttackStart(target);
					Twist2->SetVisibility(VISIBILITY_ON);
					Twist2->setFaction(m_creature->getFaction());
					twist2summoned = true;
					Twist2Guid = Twist2->GetObjectGuid();
				}
			}
        }

		if(phase == 2 && hcurrentlife / maxlife < 40)
        {   
            phase = 3;
			if(twist1summoned) 
			if (Twist1 && Twist1->isAlive())
			{
				Twist1->SetVisibility(VISIBILITY_OFF);
				Twist1->DealDamage(Twist1, Twist1->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
				Twist1 = NULL;
				twist1summoned = false;
			}
			if(twist2summoned)
			if(Twist2 && Twist2->isAlive())
			{
				Twist2->SetVisibility(VISIBILITY_OFF);
				Twist2->DealDamage(Twist2, Twist2->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
				Twist2 = NULL;
				twist2summoned = false;
			}

			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
			m_creature->InterruptNonMeleeSpells(false);
			m_creature->MonsterYell(SAY_LYNX, LANG_UNIVERSAL, NULL);
			DoPlaySoundToSet(m_creature, SOUND_LYNX);
			DoCast(m_creature,FORM_LYNX);
			
        }

		if(phase == 3 && hcurrentlife / maxlife < 20)
		{
			phase = 4;
			special = true;
			m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
			m_creature->InterruptNonMeleeSpells(false);
			m_creature->MonsterYell(SAY_DRAGONHAWK, LANG_UNIVERSAL, NULL);
			DoPlaySoundToSet(m_creature, SOUND_DRAGONHAWK);
			DoCast(m_creature,FORM_DRAGONHAWK);
			
		}

        DoMeleeAttackIfReady();
    }
};

// e ora i tornadi che spawna in eagle form e despawna fuori da questa forma. questi tornadi vanno a spasso (metto che cambia target ogni tot, cos� va dal nuovo target) e fanno le loro spell.
struct MANGOS_DLL_DECL twistAI : public ScriptedAI
{
    twistAI (Creature *c) : ScriptedAI(c) 
    {
        Reset();
    }

	uint32 harshwind_Timer;
    uint32 windblast_Timer;

	uint32 move_Timer;

	Unit* target;

	bool didreset, threatupdate;

	void Reset()
    {
		harshwind_Timer = 9000;
		windblast_Timer = 25000;

		move_Timer = 7000; // ogni 7 secondi andiamo da 1 altra parte

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
		m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
		m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);

		DoCast(m_creature,43119);

		m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X,1.2f);

		m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

		didreset = true;

		threatupdate = false;
		
	}

	void KilledUnit(Unit *victim) {}

	void JustDied(Unit *victim) {}

	void Aggro(Unit *who) 
	{

		m_creature->SetInCombatWithZone();
	
	}

	void UpdateAI(const uint32 diff)
    {
		if(m_creature->getLevel() != 70)
			m_creature->SetLevel(70);

		if(didreset != true)
		{
			harshwind_Timer = 9000;
			windblast_Timer = 25000;

			move_Timer = 2000; // ogni 7 secondi andiamo da 1 altra parte

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
			m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
			m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);

			DoCast(m_creature,38464);

			m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X,1.2f);

			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

			didreset = true;
		}

		if(!threatupdate)
		{
			threatupdate = true;
			m_creature->SetInCombatWithZone();
		}

		if(harshwind_Timer < diff)
		{   
			DoCast(m_creature,SPELL_HARSH_WINDS);
			harshwind_Timer = 9000;
		}else harshwind_Timer -= diff;

		if(windblast_Timer < diff)
		{   
			DoCast(m_creature,SPELL_WIND_BLAST);
			windblast_Timer = 25000;
		}else windblast_Timer -= diff;


		if(move_Timer < diff)
		{   			
			target = m_creature->SelectRandomUnfriendlyTarget();
			DoResetThreat();
			if(target)
			{
				m_creature->AddThreat(target, 100.0f);
				// m_creature->GetMotionMaster()->Mutate(new TargetedMovementGenerator<Creature>(*target));
			}
			move_Timer = 7000;
		}else move_Timer -= diff;

	}
};


CreatureAI* GetAI_boss_zuljin_azsc(Creature *_Creature)
{
    return new boss_zuljinAI (_Creature);
}

CreatureAI* GetAI_twist_azsc(Creature *_Creature)
{
    return new twistAI (_Creature);
}

void AddSC_boss_zuljin_azsc()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_zuljin_azsc";
    newscript->GetAI = GetAI_boss_zuljin_azsc;
    newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="twist_azsc";
    newscript->GetAI = GetAI_twist_azsc;
    newscript->RegisterSelf();
}
