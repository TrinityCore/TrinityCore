/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "waycrest_manor.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum Spells
{
	CLAIM_THE_IRIS = 260852,
	IRONBARK_SHIELD = 261265, //briar
	RUNIC_MARK = 261266, //malady
	//BRIAR
	BRAMBLE_BOLT = 260701,
	JAGGED_NEATTLES = 260741,
	AURA_OF_THORNS = 268122,
	//MALADY
	RUINOUS_BOLT = 260700,
	UNSTABLE_RUNIC_MARK = 260703,
	UNSTABLE_RUNIC_MARK_EXP = 260702,
	AURA_OF_DREAD = 268088,
	AURA_OF_DREAD_DEBUFF = 268086,
	//SOLENA
	SOUL_BOLT = 260699,
	SOUL_MANIPULATION = 260907,
	SOUL_CHANNELED = 260926,
	SOUL_MANIPULATION_AURA = 260900,
	SOUL_MANIPULATION_REDUCE_DAMAGE = 260923,
	AURA_OF_APATHY = 268077,
	AURA_OF_APATHY_DEBUFF = 268080,
	//FOCUSING IRIS
	FOCUSING_IRIS = 260805,
	DIRE_RITUAL = 260773,
};

enum Events
{
	EVENT_BRAMBLE_BOLT = 1,
	EVENT_JAGGED_NEATTLES,
	EVENT_RUINOUS_BOLT,
	EVENT_UNSTABLE_RUNIC_MARK,
	EVENT_SOUL_BOLT,
	EVENT_SOUL_MANIPULATION,
	EVENT_DIRE_RITUAL,
	EVENT_FOCUSING_IRIS,
	EVENT_RESET_IRIS,
	EVENT_AURA_OF_APATHY,
	EVENT_AURA_OF_THORNS,
	EVENT_AURA_OF_DREAD,
};

enum Texts
{
	SAY_SOLENA_AGGRO = 7,
	SAY_PASSING_IRIS_SOLENA = 1,
	SAY_PASSING_IRIS_BRIAR = 0,
	SAY_PASSING_IRIS_MALADY = 1,
	SAY_MALADY_ABILITY = 2,
	SAY_BRIAR_ABILITY = 2,
	SAY_SOLENA_SOUL_MANIP = 0,
	SAY_DEATH_SOLENA = 6,
	SAY_DEATH_BRIAR = 5,
	SAY_DEATH_MALADY = 5,
	SAY_WARNING_DIRE_RITUAL = 3,
	SAY_DIRE_RITUAL_SOLENA = 4,
	SAY_THORN_AURA_BRIAR = 1,
	SAY_DREAD_AURA_MALADY = 0,
	SAY_KILL_MALADY = 3,
	SAY_KILL_SOLENA = 5,
	SAY_KILL_BRIAR = 3,
	//OUTRO//
	//Inquisitor Yorrick says : I can rest more easily knowing these foul creatures no longer prowl the night.
	//Inquisitor Yorrick says : Continue your hunt for Lady Waycrest.I will ensure these rooms are clear.
};

struct boss_heartsbane_triad : public BossAI
{
	boss_heartsbane_triad(Creature* creature) : BossAI(creature, DATA_HEARTSBANE_TRIAD) { }

	uint8 iris_count;

	void Reset() override
	{
		BossAI::Reset();	
		iris_count = 0;
		me->SetPowerType(POWER_COMBO_POINTS);
		me->SetPower(POWER_COMBO_POINTS, 0);
	}

	void PassIris()
	{		
		if (Creature* solena = me->FindNearestCreature(NPC_SISTER_SOLENA, 100.0f, true))
		{
			if (iris_count == 1)
			{								
				if (Creature* iris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f, true))
				{
					solena->AI()->Talk(SAY_PASSING_IRIS_SOLENA);
					solena->AttackStop();
					solena->CastStop();
					solena->CastSpell(iris, CLAIM_THE_IRIS);
					solena->AddAura(FOCUSING_IRIS);
					events.ScheduleEvent(EVENT_SOUL_MANIPULATION, 5s);
					events.ScheduleEvent(EVENT_DIRE_RITUAL, 15s);
					if (IsHeroic() || IsMythic())
					{
						events.ScheduleEvent(EVENT_AURA_OF_APATHY, 2s);
					}
				}
			}			
		}
		if (Creature* briar = me->FindNearestCreature(NPC_SISTER_BRIAR, 100.0f, true))
		{
			if (iris_count == 2)
			{		
				if (Creature* solena = me->FindNearestCreature(NPC_SISTER_SOLENA, 100.0f, true))
				{
					solena->RemoveAura(FOCUSING_IRIS);
					instance->DoRemoveAurasDueToSpellOnPlayers(AURA_OF_APATHY_DEBUFF);
				}				
				if (Creature* iris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f, true))
				{
					if (briar->IsAlive())
					{
						briar->AI()->Talk(SAY_PASSING_IRIS_BRIAR);
						briar->AttackStop();
						briar->CastStop();
						briar->CastSpell(iris, CLAIM_THE_IRIS);
						briar->AddAura(FOCUSING_IRIS);
						briar->RemoveAura(IRONBARK_SHIELD);
						events.ScheduleEvent(EVENT_JAGGED_NEATTLES, 5s);
						events.ScheduleEvent(EVENT_DIRE_RITUAL, 15s);
						if (IsHeroic() || IsMythic())	
							events.ScheduleEvent(EVENT_AURA_OF_THORNS, 2s);
					}
				}
			}
		}
		if (Creature* malady = me->FindNearestCreature(NPC_SISTER_MALADY, 100.0f, true))
		{
			if (iris_count == 3)
			{				
				if (Creature* briar = me->FindNearestCreature(NPC_SISTER_BRIAR, 100.0f, true))
				{
					briar->RemoveAura(FOCUSING_IRIS);
					briar->RemoveAura(AURA_OF_THORNS);
				}					
				if (Creature* iris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f, true))
				{
					if (malady->IsAlive())
					{
						malady->AI()->Talk(SAY_PASSING_IRIS_MALADY);
						malady->AttackStop();
						malady->CastStop();
						malady->CastSpell(iris, CLAIM_THE_IRIS);
						malady->AddAura(FOCUSING_IRIS);
						malady->RemoveAura(RUNIC_MARK);
						events.ScheduleEvent(EVENT_UNSTABLE_RUNIC_MARK, 5s);
						events.ScheduleEvent(EVENT_DIRE_RITUAL, 15s);
						events.ScheduleEvent(EVENT_RESET_IRIS, 18s);
						if (IsHeroic() || IsMythic())
							events.ScheduleEvent(EVENT_AURA_OF_DREAD, 2s);
					}
				}
			}
		}
	}

	void EnterCombat(Unit* u) override
	{
		switch (me->GetEntry())
		{
		case NPC_SISTER_SOLENA:
			 Talk(SAY_SOLENA_AGGRO);
			 _EnterCombat();			 
			 events.ScheduleEvent(EVENT_SOUL_BOLT, 3s);
			 events.ScheduleEvent(EVENT_FOCUSING_IRIS, 5s);
			 break;

		case NPC_SISTER_BRIAR:		
			 _EnterCombat();
			 events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 3s);
			 break;

		case NPC_SISTER_MALADY:
			 _EnterCombat();
			 events.ScheduleEvent(EVENT_RUINOUS_BOLT, 3s);
			 break;

		default:
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_SOUL_BOLT:
		{			
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
				DoCast(target, SOUL_BOLT);
			events.Repeat(10s);
			break;
		}
		case EVENT_BRAMBLE_BOLT:
		{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
				DoCast(target, BRAMBLE_BOLT);
			events.Repeat(3s);
			break;
		}
		case EVENT_RUINOUS_BOLT:
		{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
				DoCast(target, RUINOUS_BOLT);
			events.Repeat(3s);
			break;
		}
		case EVENT_JAGGED_NEATTLES:
		{
			if (Creature* briar = me->FindNearestCreature(NPC_SISTER_BRIAR, 100.0f, true))
			{
				briar->AI()->Talk(SAY_BRIAR_ABILITY);
				briar->AI()->DoCastRandom(JAGGED_NEATTLES, 40.0f);
			}
			break;
		}
		case EVENT_UNSTABLE_RUNIC_MARK:
		{
			if (Creature* malady = me->FindNearestCreature(NPC_SISTER_MALADY, 100.0f, true))
			{
				malady->AI()->Talk(SAY_MALADY_ABILITY);
				std::list<Player*> p_list;
				malady->GetPlayerListInGrid(p_list, 100.0f);
				for (auto & players : p_list)
				malady->CastSpell(players, UNSTABLE_RUNIC_MARK);
			}
			break;
		}
		case EVENT_FOCUSING_IRIS:
		{
			iris_count++;
			PassIris();
			events.Repeat(30s);
			break;
		}
		case EVENT_RESET_IRIS:
		{			
			if (Creature* malady = me->FindNearestCreature(NPC_SISTER_MALADY, 100.0f, true))
			{
				malady->RemoveAura(FOCUSING_IRIS);
				instance->DoRemoveAurasDueToSpellOnPlayers(AURA_OF_DREAD_DEBUFF);
				iris_count = 0;
			}			
			break;
		}
		case EVENT_DIRE_RITUAL:
		{
			if (iris_count == 1)
			{
				if (Creature* solena = me->FindNearestCreature(NPC_SISTER_SOLENA, 100.0f, true))
				{
					if (solena->HasAura(FOCUSING_IRIS))
					{
						solena->AI()->Talk(SAY_WARNING_DIRE_RITUAL);
						solena->AI()->DoCastAOE(DIRE_RITUAL);
						solena->AI()->Talk(SAY_DIRE_RITUAL_SOLENA);
					}
				}
			}

			if (iris_count == 2)
			{
				if (Creature* briar = me->FindNearestCreature(NPC_SISTER_BRIAR, 100.0f, true))
				{
					if (briar->HasAura(FOCUSING_IRIS))
						briar->AI()->DoCastAOE(DIRE_RITUAL);
				}
			}

			if (iris_count == 3)
			{
				if (Creature* malady = me->FindNearestCreature(NPC_SISTER_MALADY, 100.0f, true))
				{
					if (malady->HasAura(FOCUSING_IRIS))
						malady->AI()->DoCastAOE(DIRE_RITUAL);
				}
			}
			break;
		}
		case EVENT_SOUL_MANIPULATION:
		{
			if (Creature* solena = me->FindNearestCreature(NPC_SISTER_SOLENA, 100.0f, true))
			{
				solena->CastSpell(solena, SOUL_MANIPULATION_REDUCE_DAMAGE);
				solena->AI()->Talk(SAY_SOLENA_SOUL_MANIP);
				if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				{
					tar->AddAura(SOUL_MANIPULATION_AURA);
					me->RemoveAura(SOUL_MANIPULATION_REDUCE_DAMAGE);
				}				
				break;
			}
			break;
		}
		case EVENT_AURA_OF_APATHY:
		{
			if (Creature* solena = me->FindNearestCreature(NPC_SISTER_SOLENA, 100.0f, true))
			{
				solena->AddAura(AURA_OF_APATHY);			
				std::list<Player*> p_list;
				solena->GetPlayerListInGrid(p_list, 100.0f);
				for (auto & p : p_list)
				me->AddAura(AURA_OF_APATHY_DEBUFF, p);
			}
			break;
		}
		case EVENT_AURA_OF_THORNS:
		{
			if (Creature* briar = me->FindNearestCreature(NPC_SISTER_BRIAR, 100.0f, true))
			{
				briar->AI()->Talk(SAY_THORN_AURA_BRIAR);
				briar->AddAura(AURA_OF_THORNS);
			}
			break;
		}
		case EVENT_AURA_OF_DREAD:
		{
			if (Creature* malady = me->FindNearestCreature(NPC_SISTER_MALADY, 100.0f, true))
			{
				malady->AddAura(AURA_OF_DREAD);
				malady->AI()->Talk(SAY_DREAD_AURA_MALADY);
				std::list<Player*> p_list;
				malady->GetPlayerListInGrid(p_list, 100.0f);
				for (auto & p : p_list)
				malady->AddAura(AURA_OF_DREAD_DEBUFF, p);
			}
			break;
		}
		}
	}

	void KilledUnit(Unit* u) override
	{
		switch (me->GetEntry())
		{
		case NPC_SISTER_SOLENA:
			 Talk(SAY_KILL_SOLENA);
			 break;

		case NPC_SISTER_BRIAR:
			 Talk(SAY_KILL_BRIAR);
			 break;

		case NPC_SISTER_MALADY:
			 Talk(SAY_KILL_MALADY);		
			 break;
		}
	}

	void JustDied(Unit* u) override
	{
		switch (me->GetEntry())
		{
		case NPC_SISTER_SOLENA:
			Talk(SAY_DEATH_SOLENA);
			_JustDied();	
			instance->DoRemoveAurasDueToSpellOnPlayers(AURA_OF_APATHY_DEBUFF);
			instance->SetBossState(DATA_HEARTSBANE_TRIAD, DONE);
			break;

		case NPC_SISTER_BRIAR:
			Talk(SAY_DEATH_BRIAR);
			_JustDied();
			instance->DoRemoveAurasDueToSpellOnPlayers(JAGGED_NEATTLES);
			break;

		case NPC_SISTER_MALADY:
			Talk(SAY_DEATH_MALADY);
			_JustDied();
			instance->DoRemoveAurasDueToSpellOnPlayers(AURA_OF_DREAD_DEBUFF);
			break;
		}
	}
};

// 260703
class bfa_spell_unstable_runic_mark : public AuraScript
{
	PrepareAuraScript(bfa_spell_unstable_runic_mark);

	void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (GetCaster() && GetTarget())
			GetCaster()->CastSpell(GetTarget(), UNSTABLE_RUNIC_MARK_EXP, true);

	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(bfa_spell_unstable_runic_mark::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

// 268086
class bfa_spell_aura_of_dread : public AuraScript
{
	PrepareAuraScript(bfa_spell_aura_of_dread);

	void HandlePeriodic(AuraEffect const*)
	{
		if (!GetUnitOwner())
			return;

		GetUnitOwner()->CastSpell(GetUnitOwner(), AURA_OF_DREAD_DEBUFF, true);
	}

	void Register() override
	{
		OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_aura_of_dread::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
	}
};

void AddSC_boss_heartsbane_triad()
{
	RegisterCreatureAI(boss_heartsbane_triad);
	RegisterAuraScript(bfa_spell_unstable_runic_mark);
	RegisterAuraScript(bfa_spell_aura_of_dread);
}
