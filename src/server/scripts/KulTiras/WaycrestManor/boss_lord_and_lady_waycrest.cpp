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
#include "GameObject.h"

enum Spells
{
	WRACKING_CHORD_CHANNEL = 268278,
	WRACKING_CHORD_DAMAGE = 268271,
	DISCORDANT_CADENZA_CHANNEL = 268306,
	DISCORDANT_CADENZA_DAMAGE = 268308,
	VITALITY_TRANSFER_DUMMY = 261446,
	WASTING_STRIKE = 261438,
	VIRULENT_PATHOGEN_AURA = 261440,
	VIRULENT_PATHOGEN_EXP = 261441,
	PUTRID_VITALITY = 261447,
	CONTAGIOUS_REMNANTS_MISSILE = 268385,
};

enum Events
{
	EVENT_WRACKING_CHORD = 1,
	EVENT_DISCORDANT_CADENZA,
	EVENT_WASTING_STRIKE,
	EVENT_VIRULENT_PATHOGEN,
	EVENT_CONTAGIOUS_REMNANTS,
};

enum Texts
{
	SAY_INTRO = 0,
	SAY_AGGRO = 6,
	SAY_CADENZA_WARNING = 1,
	SAY_VITALITY_TRANSFER = 2,
	SAY_VIRULENT_PATHOGEN = 1,
	SAY_DEATH_LADY = 4,
};

enum Misc
{
	ENCOUNTER_ID = 2116,
};

//131527 lord, lady 131545
struct boss_lord_and_lady_waycrest : public BossAI
{
	boss_lord_and_lady_waycrest(Creature* creature) : BossAI(creature, DATA_LORD_AND_LADY_WAYCREST) { }	

private:
	uint16 transfer;

	void Reset() override
	{		
		BossAI::Reset();
		me->SetReactState(REACT_AGGRESSIVE);
		me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
		me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:
			break;

		case NPC_LADY_WAYCREST:
			 me->AddUnitState(UNIT_STATE_ROOT);
			break;
		}
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case VITALITY_TRANSFER_DUMMY:
			if (Creature* lord = me->FindNearestCreature(NPC_LORD_WAYCREST, 250.0f, true))
				lord->SetFullHealth();
			break;
		}
	}

	void DamageTaken(Unit* target, uint32& damage) override
	{
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:			
			if (me->HealthBelowPctDamaged(31, damage))
			{	
				this->transfer++;
				if (me->HealthBelowPctDamaged(31, damage) && this->transfer < 4)
				{
					if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 250.0f, true))
					{						
						lady->AI()->Talk(SAY_VITALITY_TRANSFER);
						lady->AI()->DoCast(VITALITY_TRANSFER_DUMMY);		
						float ladyPct = (float)(this->transfer * 30) / 100;
						uint64 ladyHealth = (lady->GetMaxHealth() - (lady->GetMaxHealth() * ladyPct));
						lady->SetHealth(ladyHealth);				
						me->AddAura(PUTRID_VITALITY, me);
					}
				}
				if (this->transfer == 3)
				{
					if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 100.0f))
					{
						lady->NearTeleportTo(-550.0f, -249.0f, 185.0f, 3.19f);
						lady->ClearUnitState(UNIT_STATE_ROOT);
					}
				}
			}
		}
	}

	void MoveInLineOfSight(Unit* u) override
	{
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:
			//Intro
			//if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == DONE && instance->GetBossState(DATA_RAAL_THE_GLUTTONOUS) == DONE && instance->GetBossState(DATA_SOULBOUND_GOLIATH) == DONE)
			//{
				if (u->GetDistance(me) <= 50.0f && u->IsPlayer() && me->HasUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC))
				{
					me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
					if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 100.0f, true))
					{
						lady->AI()->Talk(SAY_INTRO);
					}
				}
				//Engage
				if (u->GetDistance(me) <= 35.0f && u->IsPlayer() && me->HasUnitFlag(UNIT_FLAG_IMMUNE_TO_PC))
				{
					me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
					_EnterCombat();
					me->GetMotionMaster()->MoveJump(-549.0f, -264.0f, 185.0f, 3.03f, 15.0f, 15.0f);
					if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 100.0f, true))
					{
						lady->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
						lady->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
						lady->AI()->Talk(SAY_AGGRO);
						lady->AI()->DoZoneInCombat(nullptr, 100.0f);
						instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, lady);
					}
				}
			//}
			break;
		}
	}

	void EnterCombat(Unit* u) override
	{
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:
			 events.ScheduleEvent(EVENT_WASTING_STRIKE, 3s);
			 events.ScheduleEvent(EVENT_VIRULENT_PATHOGEN, 17s);
			 this->transfer = 0;
			 break;

		case NPC_LADY_WAYCREST:
			 events.ScheduleEvent(EVENT_WRACKING_CHORD, 3s);
			 events.ScheduleEvent(EVENT_DISCORDANT_CADENZA, 15s);			 
			 break;
		}
	}

	void CallCadenza()
	{
		std::list<Player*> p_list;
		me->GetPlayerListInGrid(p_list, 100.0f);
		for (auto& players : p_list)
			DoCast(players, DISCORDANT_CADENZA_DAMAGE);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_WRACKING_CHORD:
		{
			DoCast(WRACKING_CHORD_CHANNEL);
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				DoCast(target, WRACKING_CHORD_DAMAGE);	
			events.Repeat(3s);
			break;
		}
		case EVENT_DISCORDANT_CADENZA:
		{
			if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 100.0f, true))
			{
				lady->AI()->Talk(SAY_CADENZA_WARNING);
				DoCast(DISCORDANT_CADENZA_CHANNEL);
				CallCadenza();
				events.Repeat(15s);	
			}
			break;
		}
		case EVENT_WASTING_STRIKE:
		{
			if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 5.0f, true)){
				DoCast(target, WASTING_STRIKE);
			events.Repeat(15s);
			break;
		}
		case EVENT_VIRULENT_PATHOGEN:
		{
			if (Creature* lord = me->FindNearestCreature(NPC_LORD_WAYCREST, 100.0f, true))
				lord->AI()->Talk(SAY_VIRULENT_PATHOGEN);

			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true)){
				me->AddAura(VIRULENT_PATHOGEN_AURA, target);
			events.Repeat(20s);
			break;
		}
		}
		}
		}
	}

	void EnterEvadeMode(EvadeReason /*reason*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:
			_JustReachedHome();
			me->NearTeleportTo(me->GetHomePosition());
			break;

		case NPC_LADY_WAYCREST:
			_JustReachedHome();
			me->NearTeleportTo(me->GetHomePosition());
			break;
		}
	}

	void JustDied(Unit* victim) override
	{
		switch (me->GetEntry())
		{
		case NPC_LORD_WAYCREST:
			 _JustDied();
			 if (Creature* lady = me->FindNearestCreature(NPC_LADY_WAYCREST, 100.0f, false))
			 {
				instance->SendBossKillCredit(ENCOUNTER_ID);
				if (auto* sfx = me->FindNearestGameObject(DOODAD_SFX_LORD_AND_LADY_WAYCREST, 100.0f))
					sfx->RemoveFromWorld();
			 }
			break;

		case NPC_LADY_WAYCREST:
			Talk(SAY_DEATH_LADY);
			_JustDied();
			if (Creature* lord = me->FindNearestCreature(NPC_LORD_WAYCREST, 100.0f, false))
				if (auto* sfx = me->FindNearestGameObject(DOODAD_SFX_LORD_AND_LADY_WAYCREST, 100.0f))
					sfx->RemoveFromWorld();
			break;
		}
	}
};

//261440
class bfa_spell_virulent_pathogen_aura : public AuraScript
{
	PrepareAuraScript(bfa_spell_virulent_pathogen_aura);

	void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (Unit* caster = GetCaster())
		{
			if (GetTarget())
			{
				caster->CastSpell(GetTarget(), VIRULENT_PATHOGEN_EXP, true);
				caster->CastSpell(GetTarget(), CONTAGIOUS_REMNANTS_MISSILE, true);
			}
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(bfa_spell_virulent_pathogen_aura::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

void AddSC_boss_lord_and_lady_waycrest()
{
	RegisterCreatureAI(boss_lord_and_lady_waycrest);
	RegisterAuraScript(bfa_spell_virulent_pathogen_aura);
}
