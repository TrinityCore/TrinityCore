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
SDName: boss_malacrass
SD%Complete: 100
SDComment: interessante
SDCategory: zul'aman
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO1              "Fallirete, idioti! Molti ci hanno provato prima di voi, le tigri stanno ancora rosicchiando i loro scheletri..."
#define SAY_AGGRO2				"Non siate timidi. A migliaia sono venuti prima di voi..."
#define SAY_DEATH               "No.. non e' la morte... Avevo previsto tutto.. tornero' piu' forte.."
#define SAY_TRANSFORM           "ed ora qualcosa di mio, risultato di anni di esperimenti... NON SFUGGIRETE AL DEMONE CHE C'E' IN ME!"
#define SAY_SLAY                "E' tutto inutile, $N. Presto gli altri ti raggiungeranno."
#define EMOTE_DEATH				" esplode in un'ultima risata, sputando sangue tutt'intorno..."

// spell da usare  quando diventa un demone:

#define SPELL_SILENCE	            23207	// silence x 10 sec. , single target
#define SPELL_SHADOWBOLT	        47248	// 3k-4k shadow dmg, single target
#define SPELL_SW_PAIN		        37275	// 15k over 18 sec, single target (dispellabile, e poi nello shard fa meno danno.)
#define SPELL_MIND_BLAST            41374	// 3,5k to 4k di danno, single target.
#define SPELL_CURSE_DOOM			43439	// 7k dopo 30 sec

// spell k usa normalmente nel combat

#define SPELL_DRAIN_LIFE		    46155	// 6000 drained OVER 3 sec.

// spell che copia dalla classe che seleziona a caso (non seleziona mai 1 classe + di 1 volta)

#define SPELL_MAGE1		            31250       // frost nova, congela tutti (root) x 10 sec +2k dmg.
#define SPELL_MAGE2                 43428       // frostbolt, 3k, -50% speed x 4 sec
#define SPELL_DRUID1                20701       // rejuvenation, 2k ogni 3 sec x 12 sec (cura)
#define SPELL_DRUID2                43420       // thorns, x 40 secondi ogni attacco k riceve fa 200 di danno all'attacker
#define SPELL_PALADIN1              38385       // consecration, 750 dmg ogni sec x 20 sec ad area itnrono a se. self cast.
#define SPELL_PALADIN2              41367       // x 15 sec immune a tutto, diminuisce l'attack speed del 25% (nel senso k � + lento ad attaccare)
#define SPELL_WARLOCK1              43440       // rain of fire, 2,8k ogni 2 sec x 10 sec, single target ma ad area.
#define SPELL_WARLOCK2              25195       // curse of tongues: diminuisce (rallenta) casting speed del 75% x 15 sec
#define SPELL_HUNTER1               35945       // 1k dmg + 240 ogni 3 sec x 12 sec (hunter sfigati, nn ci sn tante spell...)
#define SPELL_HUNTER2               43444       // explosive trap, fa 1 po' di danno fire a caso nn so bn cm funziona, nn troppo cmq. self.
#define SPELL_ROGUE1                43461       // wound poison: riduce healing ricevuto dal target del 10%, e fa 500 dmg.
#define SPELL_ROGUE2				43433		// blind, confused x 10 sec, dmg rimuove l'effetto.
#define SPELL_SHAMAN1				43435		// chain lightning: 3k dmg a 5 targets. single target x castare.
#define SPELL_SHAMAN2				46181		// lesser healing wave, cura 4k. self.
#define SPELL_PRIEST1				43432		// psychic scream, fear x 8 sec a 8 yard. self.
#define SPELL_PRIEST2				41375		// sw:death, fa 2k di danno a 1 target ma anche a se stesso. single target.
#define SPELL_WARRIOR1				43443		// spell reflect: riflette la prissima spell ricevuta al nemuci (funzia)
#define SPELL_WARRIOR2				43441		// mortal strike: 150% weapon dmg, e riduce healing nel target del 50%

#define SAY_MAGE        "$N, e cosi' tu sei uno di quei superbi maghi elementali? I futili risultati che hai ottenuto in tutto questo tempo sono NIENTE in confronto a quello che so fare io! "
#define SAY_WARRIOR     "$N ! Vediamo chi sa usare meglio quell'arma!"
#define SAY_DRUID       "E cosi' tu usi gli antichi poteri druidici, $N... non e' poi una brutta idea!"
#define SAY_PRIEST      "$N! Voi chierici fate finta di esser bianchi ma vi dilettate, con scarso successo, in magia nera... ipocriti!"
#define SAY_PALADIN     "$N, quello stupido trucchetto dello scudo magico lo so fare anche io..."
#define SAY_SHAMAN      "$N, e' meglio che ti mostri io come maneggiare quelle magie!"
#define SAY_WARLOCK     "Dunque anche tu sei uno stregone, $N? Lascia che ti mostri come si gioca con la magia nera!"
#define SAY_HUNTER      "$N! Tu e il tuo stupido mostriciattolo! Chiunque saprebbe maneggiare un arco meglio di te!"
#define SAY_ROGUE       "$N, ti fai chiamare assassino? Oggi sarai tu la vittima!"

#define SOUND_1			12042
#define SOUND_2			12043
#define SOUND_3			12044
#define SOUND_4			12046
#define SOUND_5			12047


struct MANGOS_DLL_DECL boss_malacrassAI : public ScriptedAI
{
    boss_malacrassAI(Creature *c) : ScriptedAI(c) {Reset();}

    
    bool cast, demon, mage, warlock, druid, warrior, priest, paladin, shaman, hunter, rogue;

	Unit* target;
	Unit* classe;

	int Cast;

	uint32 demonspell_timer;
	uint32 swpain_timer;
	uint32 silence_timer;
	uint32 spell2_timer;
	uint32 drain_timer;
	uint32 copia_timer;
	uint32 doom_timer;
	uint32 sound_timer;

    void Reset()
    {
        demonspell_timer = 7000;       // unico timer x mind blast & shadowbolt, switch(rand) x scegliere quale
        swpain_timer = 20000;
        silence_timer = 35000;			// silence x 10 sec, � abb pesante, soprattutto sul healer. nn esageriamo ora!
		doom_timer = 17000;

        spell2_timer = 500000;			// qst � x evitare crash. fidati.

        drain_timer = 9000;			// se nn � in fase di copia spell(copiando), castiamo questa spell ogni 10 sec.

        copia_timer = 30000;			// ogni 30 secondi scegliamo 1 classe a caso(diversa dalla precedente) e castiamo 2 spell di quella classe

		sound_timer = 45000;

		Cast = 0;

        demon = false;
		cast = false;
		mage = warlock = druid = warrior = priest = paladin = shaman = hunter = rogue = false;

		m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,22332);	// displayid originale
		m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X,1.0);

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

    void KilledUnit(Unit* Victim)
    {
        m_creature->MonsterYell(SAY_SLAY,LANG_UNIVERSAL,Victim);
    }

    void JustDied(Unit* Killer)
    {
        m_creature->MonsterYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
		m_creature->MonsterTextEmote(EMOTE_DEATH, NULL);
    }

    void Aggro(Unit *who)
    {
		m_creature->SetInCombatWithZone();
                switch (rand()%2)
                {
                case 0:
                    m_creature->MonsterYell(SAY_AGGRO1,LANG_UNIVERSAL,NULL);
                    break;

                case 1:
                    m_creature->MonsterYell(SAY_AGGRO2,LANG_UNIVERSAL,NULL);
                    break;
                }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() )
            return;

		if(demon)
		{
			if (demonspell_timer < diff)
			{
				target = m_creature->SelectRandomUnfriendlyTarget();

				//Cast
				switch (rand()%2)
                {
                case 0:
                    DoCast(target,SPELL_SHADOWBOLT);
                    break;

                case 1:
                    DoCast(target,SPELL_MIND_BLAST);
                    break;
                }
				//7 seconds till recast
				demonspell_timer = 7000;
			}else demonspell_timer -= diff;


			if (swpain_timer < diff)
			{
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_SW_PAIN);
				swpain_timer = 15000;
			}else swpain_timer -= diff;

			if (silence_timer < diff)
			{
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_SILENCE);
				silence_timer = 30000;
			}else silence_timer -= diff;

			if (doom_timer < diff)
			{
				target = m_creature->SelectRandomUnfriendlyTarget();
				DoCast(target,SPELL_CURSE_DOOM);
				doom_timer = 17000;
			}else doom_timer -= diff;
		}
		else
		{
			if(copia_timer < diff)
			{
				for(int i = 0; i <= 20; i++)	// non � detto che in un gruppo ci siano tutte le classi. io ho 1 variabile x ogni classe usata (nn copio mai una colasse 2 volte. se dopo 20 tentativi non sono riuscito a trovare una classe diversa da quelle finora usate, 99% le abbiamo copiate tutte, 1% abbiam avuto sfiga. in questo caso ci trasformiamo in demone.
				{
					if(cast)	// cast = true vuol dire k abbiamo impostato la condizione x castare un'altra spell della classe copiata tra 4 secondi, quindi nn dobbiamo + andare avanti con qst ciclo
						break;

					classe = m_creature->SelectRandomUnfriendlyTarget();
					if(classe && classe->GetTypeId() == TYPEID_PLAYER)
					{
					switch(classe->getClass())
					{
					case 1:
						if(!warrior)
						{
							warrior = true;
							m_creature->MonsterYell(SAY_WARRIOR,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(m_creature,SPELL_WARRIOR1);
							cast = true;	// vedi linea 204
							Cast = 1;	// serve x sapere quale spell (tra le 9 restanti delle classi) dobbiamo castare tra 4,5 sec
							spell2_timer = 4500;							
						}
						break;	// se warrior era true qualche linea fa (nell'if), cast non sar� true, di conseguenza alla ripetizione del ciclo si cambier� classe(hopefully... sen� se vien fuori di nuovo warrior, si ripete di nuovo.)
					case 2:
						if(!paladin)
						{
							paladin = true;
							m_creature->MonsterYell(SAY_PALADIN,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(m_creature,SPELL_PALADIN2);
							cast = true;
							Cast = 2;
							spell2_timer = 4500;							
						}
						break;
					case 3:
						if(!hunter)
						{
							hunter = true;
							m_creature->MonsterYell(SAY_HUNTER,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(classe,SPELL_HUNTER1);
							cast = true;
							Cast = 3;
							spell2_timer = 4500;							
						}
						break;
					case 4:
						if(!rogue)
						{
							rogue = true;
							m_creature->MonsterYell(SAY_ROGUE,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(classe,SPELL_ROGUE2);
							cast = true;
							Cast = 4;
							spell2_timer = 4500;							
						}
						break;
					case 5:
						if(!priest)
						{
							priest = true;
							m_creature->MonsterYell(SAY_PRIEST,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(classe,SPELL_PRIEST2);
							cast = true;
							Cast = 5;
							spell2_timer = 4500;							
						}
						break;
					case 7:
						if(!shaman)
						{
							shaman = true;
							m_creature->MonsterYell(SAY_SHAMAN,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(classe,SPELL_SHAMAN1);
							cast = true;
							Cast = 7;
							spell2_timer = 4500;							
						}
						break;
					case 8:
						if(!mage)
						{
							mage = true;
							m_creature->MonsterYell(SAY_MAGE,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(m_creature,SPELL_MAGE1);
							cast = true;
							Cast = 8;
							spell2_timer = 4500;							
						}
						break;
					case 9:
						if(!warlock)
						{
							warlock = true;
							m_creature->MonsterYell(SAY_WARLOCK,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(classe,SPELL_WARLOCK1);
							cast = true;
							Cast = 9;
							spell2_timer = 4500;							
						}
						break;
					case 11:
						if(!druid)
						{
							druid = true;
							m_creature->MonsterYell(SAY_DRUID,LANG_UNIVERSAL,classe);
							m_creature->InterruptNonMeleeSpells(false);
							m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
							DoCast(m_creature,SPELL_DRUID1);
							cast = true;
							Cast = 11;
							spell2_timer = 4500;							
						}
						break;
					default:	// x tt le altre classi (bah, magari becca 1 pet e vien fuori roba strana) rifamo il ciclo for
						cast = false;
						break;
					}
					}
				}

				copia_timer = 40000;

				if(!cast)	// 20 cicli for x niente! i player van puniti xk � colpa loro XD
				{
					// trasformiamoci in demone:
					m_creature->MonsterYell(SAY_TRANSFORM,LANG_UNIVERSAL,NULL);
					demon = true;
					m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,19882);	// displayid di 1 demone
					m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X,2.0);	// ingrandiamolo x fare + scena
				}

			}else copia_timer -= diff;

			if(cast && spell2_timer < diff)
			{
				m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
				switch(Cast)
				{
				case 1:
					DoCast(m_creature->getVictim(),SPELL_WARRIOR2);
					cast = false;
					break;
				case 2:
					DoCast(m_creature,SPELL_PALADIN1);
					cast = false;
					break;
				case 3:
					DoCast(m_creature,SPELL_HUNTER2);
					cast = false;
					break;
				case 4:
					DoCast(m_creature->getVictim(),SPELL_ROGUE1);
					cast = false;
					break;
				case 5:
					DoCast(m_creature,SPELL_PRIEST1);
					cast = false;
					break;
				case 7:
					DoCast(m_creature,SPELL_SHAMAN2);
					cast = false;
					break;
				case 8:
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_MAGE2);
					cast = false;
					break;
				case 9:
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_WARLOCK2);
					cast = false;
					break;
				case 11:
					DoCast(m_creature,SPELL_DRUID2);
					cast = false;
					break;
				}
				spell2_timer = 500000;	// x sicurezza, siccome tra 2 linee diminuiamo il timer in qualunque caso, meglio star sicuri che un uint rimanga positivo :D
			}else spell2_timer -= diff;

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

			if(!cast)
			{
				if(drain_timer < diff)
				{
					target = m_creature->SelectRandomUnfriendlyTarget();
					DoCast(target,SPELL_DRAIN_LIFE);
					drain_timer = 10000;
				}else drain_timer -= diff;
			}
			
		}

        DoMeleeAttackIfReady();
    }

};
CreatureAI* GetAI_boss_malacrass_azsc(Creature *_Creature)
{
    return new boss_malacrassAI (_Creature);
}


void AddSC_boss_malacrass_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_malacrass_azsc";
    newscript->GetAI = GetAI_boss_malacrass_azsc;
    newscript->RegisterSelf();
}
