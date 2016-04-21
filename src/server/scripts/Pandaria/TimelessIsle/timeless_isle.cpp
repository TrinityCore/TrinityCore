/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Object.h"
#include "Player.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "timeless_isle.h"

class npc_cinderfall : public CreatureScript
{
public:
    npc_cinderfall() : CreatureScript("npc_cinderfall") { }

    struct npc_cinderfallAI : public ScriptedAI
    {
        npc_cinderfallAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 MoltenInfernoTimer;
        uint8 MoltenInfernoChoice;

        void Reset() override
        {
        	MoltenInfernoTimer = 2000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        	me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
        }

		void EnterCombat(Unit* target) override
        {
        	InCombat = true;

        	me->SetFacingToObject(target);
        }

		void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (MoltenInfernoTimer <= diff)
        	{
        		MoltenInfernoChoice = urand(1, 4);

        		switch (MoltenInfernoChoice)
        		{
        			case 1:
        				DoCastAOE(SPELL_MOLTEN_INFERNO_1, false);
        				break;

        			case 2:
        				DoCastAOE(SPELL_MOLTEN_INFERNO_2, false);
        				break;

        			case 3:
        				DoCastAOE(SPELL_MOLTEN_INFERNO_3, false);
        				break;

        			case 4:
        				DoCastAOE(SPELL_MOLTEN_INFERNO_4, false);
        				break;
        			default:
        				break;
        		}

        		MoltenInfernoTimer = urand(3000, 5000);
        	}

        	else
        		MoltenInfernoTimer -= diff;
        }

    private:
    	bool InCombat;
    };

	CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cinderfallAI(creature);
    }
};

class npc_huolon : public CreatureScript
{
public:
    npc_huolon() : CreatureScript("npc_huolon") { }

    struct npc_huolonAI : public ScriptedAI
    {
        npc_huolonAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 LightningBreathTimer;
        uint32 StormBlossomTimer;

		void Reset() override
        {
        	LightningBreathTimer = 6000;
        	StormBlossomTimer = 8000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

		void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

		void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (LightningBreathTimer <= diff)
        	{
        		DoCastAOE(SPELL_LIGHTNING_BREATH, false);

        		LightningBreathTimer = urand(9000, 12000);
        	}

        	else
        		LightningBreathTimer -= diff;

        	if (StormBlossomTimer <= diff)
        	{
        		if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
        		{
        			/* DoCast(target, SPELL_STORM_BLOSSOM); */

        			StormBlossomTimer = 15000;
        		}
        	}

        	else
        		StormBlossomTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_huolonAI(creature);
    }
};

class npc_imperial_python : public CreatureScript
{
public:
    npc_imperial_python() : CreatureScript("npc_imperial_python") { }

    struct npc_imperial_pythonAI : public ScriptedAI
    {
        npc_imperial_pythonAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 HugeFangTimer;

        void Reset() override
        {
        	HugeFangTimer = 2000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        	me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (HugeFangTimer <= diff)
        	{
        		DoCastVictim(SPELL_HUGE_FANG, false);

        		HugeFangTimer = 5000;
        	}

        	else
        		HugeFangTimer -= diff;
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_imperial_pythonAI(creature);
    }
};

class npc_emerald_gander : public CreatureScript
{
public:
    npc_emerald_gander() : CreatureScript("npc_emerald_gander") { }

    struct npc_emerald_ganderAI : public ScriptedAI
    {
        npc_emerald_ganderAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 GustofWindTimer;
        uint32 HealingSongTimer;

        void Reset() override
        {
        	GustofWindTimer = urand(6000, 9000);
        	HealingSongTimer = 15000;

            InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;

        	DoCast(me, SPELL_WINDFEATHER);
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (GustofWindTimer <= diff)
        	{
        		DoCastAOE(SPELL_GUST_OF_WIND, false);

        		GustofWindTimer = urand(12000, 16000);
        	}

        	else
        		GustofWindTimer -= diff;

        	if (HealingSongTimer <= diff) // Fuck it.
        	{
        		if (me->GetHealthPct() >= 81)
        			return;

        		if (me->GetHealthPct() <= 80)
        		{
        			DoCast(me, SPELL_HEALING_SONG);

        			HealingSongTimer = urand(15000, 22000);
        		}
        	}

        	else
        		HealingSongTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_emerald_ganderAI(creature);
    }
};

class npc_golganarr : public CreatureScript
{
public:
    npc_golganarr() : CreatureScript("npc_golganarr") { }

    struct npc_golganarrAI : public ScriptedAI
    {
        npc_golganarrAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 BoulderTimer;
        uint32 StompTimer;
        uint32 StompFrenzyTimer;
        uint32 FrenzyTimer;

        void Reset() override
        {
        	BoulderTimer = urand(8000, 11000);
        	StompTimer = 14500;
        	FrenzyTimer = 30000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_FRENZY)
            	StompFrenzyTimer = 500;
        }

        void JustRespawned() override
        {
            ScriptedAI::JustRespawned();
            
//            me->YellToZone(SAY_SPAWN, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (BoulderTimer <= diff)
        	{
        		if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
        		{
        			if (!me->HasAura(SPELL_FRENZY))
	        			DoCast(target, SPELL_BOULDER);

	        		else
	        			DoCast(target, SPELL_BOULDER_FRENZY);
        		}

	        	BoulderTimer = urand(15000, 25000);
        	}

        	else
        		BoulderTimer -= diff;

        	if (StompTimer <= diff)
        	{
        		DoCastAOE(SPELL_STOMP, false);

        		StompTimer = urand(6000, 11000);
        	}

        	else
        		StompTimer -= diff;

        	if (StompFrenzyTimer <= diff)
        	{
        		if (me->HasAura(SPELL_FRENZY))
        			DoCastAOE(SPELL_STOMP_FRENZY, false);

        		else if (!me->HasAura(SPELL_FRENZY))
        			return;

        		StompFrenzyTimer = urand(2000, 2200);
        	}

        	else
        		StompFrenzyTimer -= diff;

        	if (FrenzyTimer <= diff)
        	{
        		DoCast(me, SPELL_FRENZY);

        		FrenzyTimer = urand(40000, 60000);
        	}

        	else
        		FrenzyTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_golganarrAI(creature);
    }
};

class npc_watcher_osu : public CreatureScript
{
public:
    npc_watcher_osu() : CreatureScript("npc_watcher_osu") { }

    struct npc_watcher_osuAI : public ScriptedAI
    {
        npc_watcher_osuAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 FallingFlamesTimer;
        uint32 PyroblastTimer;

        void Reset() override
        {
        	FallingFlamesTimer = urand(9000, 15000);
        	PyroblastTimer = 7500;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (FallingFlamesTimer <= diff)
        	{
        		DoCastAOE(SPELL_FALLING_FLAMES, false);

        		FallingFlamesTimer = urand(15000, 22000);
        	}

        	else
        		FallingFlamesTimer -= diff;

        	if (PyroblastTimer <= diff)
        	{
        		DoCastVictim(SPELL_PYROBLAST, false);

        		PyroblastTimer = urand(9000, 16000);
        	}

        	else
        		PyroblastTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_watcher_osuAI(creature);
    }
};

class npc_tsavoka : public CreatureScript
{
public:
    npc_tsavoka() : CreatureScript("npc_tsavoka") { }

    struct npc_tsavokaAI : public ScriptedAI
    {
        npc_tsavokaAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 GreaterSwipeTimer;
        uint32 DefensiveLeapTimer;
        uint32 StunTimer;

        void Reset() override
        {
        	GreaterSwipeTimer = urand(6000, 8000);
        	DefensiveLeapTimer = urand(11000, 13500);

        	InCombat = false;
        	Leaped = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* target) override
        {
        	InCombat = true;

        	LeapOrNot = urand(1, 2);

        	if (LeapOrNot == 1)
        		DoCast(target, SPELL_POUNCE_LEAP);

        	else if (LeapOrNot == 2)
        		me->Attack(target, true);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
        	if (target->GetTypeId() == TYPEID_PLAYER && target->IsAlive() && spell->Id == SPELL_POUNCE_LEAP)
        		StunTimer = 3000;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (GreaterSwipeTimer <= diff)
        	{
        		DoCastAOE(SPELL_GREATER_SWIPE, false);

        		GreaterSwipeTimer = urand(9000, 14000);
        	}

        	else
        		GreaterSwipeTimer -= diff;

        	if (DefensiveLeapTimer <= diff)
        	{
        		DoCast(me, SPELL_DEFENSIVE_LEAP);

        		LeapDone = 3000;
        		DefensiveLeapTimer = urand(10000, 16000);
        	}

        	else
        		DefensiveLeapTimer -= diff;

        	if (LeapDone <= diff)
        		DoCastVictim(SPELL_POUNCE_LEAP, false);

        	else
        		LeapDone -= diff;

        	if (StunTimer <= diff)
        	{
        		if (me->IsWithinMeleeRange(me->GetVictim()))
        			DoCastVictim(SPELL_POUNCE_STUN, true);
        	}

        	else
        		StunTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
        uint32 LeapDone;

        uint8 LeapOrNot;

        bool Leaped;
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tsavokaAI(creature);
    }
};

class npc_spirit_of_jadefire : public CreatureScript
{
public:
    npc_spirit_of_jadefire() : CreatureScript("npc_spirit_of_jadefire") { }

    struct npc_spirit_of_jadefireAI : public ScriptedAI
    {
        npc_spirit_of_jadefireAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 JadefireBoltTimer;
        uint32 JadeflameStrikeTimer;

        void Reset() override
        {
        	JadefireBoltTimer = 3500;
        	JadeflameStrikeTimer = 8000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/)
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (JadefireBoltTimer <= diff)
        	{
        		DoCastVictim(SPELL_JADEFIRE_BOLT, false);

        		JadefireBoltTimer = urand(5000, 6000);
        	}

        	else
        		JadefireBoltTimer -= diff;

        	if (JadeflameStrikeTimer <= diff)
        	{
        		DoCastAOE(SPELL_JADEFLAME_STRIKE, false);

        		JadeflameStrikeTimer = urand(10000, 15000);
        	}

        	else
        		JadeflameStrikeTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spirit_of_jadefireAI(creature);
    }
};

class npc_monstrous_spineclaw : public CreatureScript
{
public:
    npc_monstrous_spineclaw() : CreatureScript("npc_monstrous_spineclaw") { }

    struct npc_monstrous_spineclawAI : public ScriptedAI
    {
        npc_monstrous_spineclawAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 ClawFlurryTimer;

        void Reset() override
        {
        	ClawFlurryTimer = urand(6000, 8000);

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (ClawFlurryTimer <= diff)
        	{
        		DoCastAOE(SPELL_CLAW_FLURRY, false);

        		ClawFlurryTimer = urand(7000, 8000);
        	}

        	else
        		ClawFlurryTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_monstrous_spineclawAI(creature);
    }
};

class npc_great_turtle_furyshell : public CreatureScript
{
public:
    npc_great_turtle_furyshell() : CreatureScript("npc_great_turtle_furyshell") { }

    struct npc_great_turtle_furyshellAI : public ScriptedAI
    {
        npc_great_turtle_furyshellAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
        	GeyserTimer = urand(4000, 6000);
        	ShellSpinTimer = urand(5000, 7000);
        	SnappingBiteTimer = urand(2500, 12500);

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (GeyserTimer <= diff)
        	{
        		DoCastVictim(SPELL_GEYSER, false);

        		GeyserTimer = urand(10000, 14000);
        	}

        	else
        		GeyserTimer -= diff;

        	if (ShellSpinTimer <= diff)
        	{
        		DoCastAOE(SPELL_SHELL_SPIN, false);

        		ShellSpinTimer = urand(11000, 15000);
        	}

        	else
        		ShellSpinTimer -= diff;

        	if (SnappingBiteTimer <= diff)
        	{
        		DoCastVictim(SPELL_SNAPPING_BITE, false);

        		SnappingBiteTimer = urand(10000, 18000);
        	}

        	else
        		SnappingBiteTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
        uint32 GeyserTimer;
        uint32 ShellSpinTimer;
        uint32 SnappingBiteTimer;

    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_great_turtle_furyshellAI(creature);
    }
};

class npc_ironfur_steelhorn : public CreatureScript
{
public:
    npc_ironfur_steelhorn() : CreatureScript("npc_ironfur_steelhorn") { }

    struct npc_ironfur_steelhornAI : public ScriptedAI
    {
        npc_ironfur_steelhornAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 HeadbuttTimer;
        uint32 IronFurTimer;
        uint32 OxChargeTimer;
        uint32 OxChargeStunTimer;

        void Reset() override
        {
        	HeadbuttTimer = 6000;
        	IronFurTimer = urand(8000, 10000);
        	OxChargeTimer = urand(7500, 12500);

        	InCombat = false;
        	Charged = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (HeadbuttTimer <= diff)
        	{
        		DoCastAOE(SPELL_HEADBUTT);

        		HeadbuttTimer = urand(8000, 12000);
        	}

        	else
        		HeadbuttTimer -= diff;

        	if (IronFurTimer <= diff)
        	{
        		DoCast(me, SPELL_IRON_FUR);

        		IronFurTimer = urand(17000, 22000);
        	}

        	else
        		IronFurTimer -= diff;

        	if (OxChargeTimer <= diff)
        	{
        		DoCastVictim(SPELL_OX_CHARGE_CAST, false);

        		OxChargeTimer = urand(12000, 16500);
        		OxChargeStunTimer = 3000;
        	}

        	else
        		OxChargeTimer -= diff;

        	if (OxChargeStunTimer <= diff)
        	{
        		if (!Charged)
        			Charged = true;

        		if (me->IsWithinMeleeRange(me->GetVictim()))
        			DoCastVictim(SPELL_OX_CHARGE);
        	}

        	else
        		OxChargeStunTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    	bool Charged;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ironfur_steelhornAI(creature);
    }
};
/*
class npc_flintlord_gairan : public CreatureScript
{
public:
    npc_flintlord_gairan() : CreatureScript("npc_flintlord_gairan") { }

    struct npc_flintlord_gairanAI : public ScriptedAI
    {
        npc_flintlord_gairanAI(Creature* creature) : ScriptedAI(creature) {	}

        void Reset() override
        {
        	for (uint32 i = 0; i <= EternalKilnAlive; ++i)
            {
                if (EternalKilnAlive == 0)
                    return;

                else
                {
                    if (Creature* Kilns = Unit::GetCreature(*me, EternalKilnGUID[i]))
                    {
                        if (Kilns->GetOwnerGUID() == me->GetGUID())
                        {
                        	EternalKilnGUID[i] = 0;
                            Kilns->DespawnOrUnsummon();
                        }

                        else
                            return;
                    }
                }
            }

        	BlazingBlowTimer = urand(5000, 7000);
        	ConjureEternalKilnTimer = urand(10000, 12000);
        	FieryChargeTimer = 5000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* target) override
        {
        	InCombat = true;
        }

        void JustDied(Unit* killer) override
        {
            for (uint32 i = 0; i <= EternalKilnAlive; ++i)
            {
                if (EternalKilnAlive == 0)
                    return;

                else
                {
                    if (Creature* Kilns = Unit::GetCreature(*me, EternalKilnGUID[i]))
                    {
                        if (Kilns->GetOwnerGUID() == me->GetGUID()) // make sure we're using the owner's guid and not some other lol xD
                        {
                        	EternalKilnGUID[i] = 0;
                            Kilns->DespawnOrUnsummon(); // Gets all kilns alive, and despawns them :P
                        }

                        else
                            return;
                    }
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == 73528)
            {
                EternalKilnGUID = summon->GetGUID();
                EternalKilnAlive = EternalKilnAlive + 1;
            }
        }

        void SummonedCreatureDies(Creature* summoned, Unit* who) override
        {
            if (summoned->GetEntry() == 73528)
            {
                EternalKilnGUID = 0;
                EternalKilnAlive = EternalKilnAlive - 1;
            }
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (BlazingBlowTimer <= diff)
        	{
        		DoCastAOE(SPELL_BLAZING_BLOW, false);

        		BlazingBlowTimer = urand(4000, 6500);
        	}

        	else
        		BlazingBlowTimer -= diff;

        	if (ConjureEternalKilnTimer <= diff)
        	{
        		DoCast(me, SPELL_CONJURE_ETERNAL_KILN);

        		ConjureEternalKilnTimer = urand(20000, 35000);
        	}

        	else
        		ConjureEternalKilnTimer -= diff;

        	if (FieryChargeTimer <= diff)
        	{
        		if (!me->GetVictim()) // make sure we have a tank/victim
        			return;

        		if (me->GetDistance(me->GetVictim()) < 20.0f)
        			return;

        		if (me->GetDistance(me->GetVictim()) > 60.0f)
        			return;

        		else if (me->GetDistance(me->GetVictim()) >= 20.0f)
        			DoCastVictim(SPELL_FIERY_CHARGE, false);

        		FieryChargeTimer = urand(3000, 6000);
        	}

        	DoMeleeAttackIfReady();
        }

    private:
        uint64 EternalKilnGUID;

        uint32 EternalKilnAlive;
        uint32 BlazingBlowTimer;
        uint32 ConjureEternalKilnTimer;
        uint32 FieryChargeTimer; // It can be casted from 1 to infinite seconds. Once you go out of melee range, he immediately casts it :P

    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
    	return new npc_flintlord_gairanAI(creature);
    }
};

class npc_archiereus_of_flame : public CreatureScript
{
public:
    npc_archiereus_of_flame() : CreatureScript("npc_archiereus_of_flame") { }

    struct npc_archiereus_of_flameAI : public ScriptedAI
    {
        npc_archiereus_of_flameAI(Creature* creature) : ScriptedAI(creature) { }

        // I don't understand this at all. Why would there be 2 NPC IDs for this guy, same spells, same hp... same drop? Wtf?

        uint32 CauterizeTimer;
        uint32 ConjureFlarecoreGolemTimer;
        uint32 FireStormTimer;

        void Reset() override
        {
        	for (uint32 i = 0; i <= FlareCoreGolemAlive; ++i)
            {
                if (FlareCoreGolemAlive == 0)
                    return;

                else
                {
                    if (Creature* Golems = Unit::GetCreature(*me, FlareCoreGolemGUID[i]))
                    {
                        if (Golems->GetOwnerGUID() == me->GetGUID())
                        {
                        	FlareCoreGolemGUID[i] = 0;
                            Golems->DespawnOrUnsummon();
                        }

                        else
                            return;
                    }
                }
            }

            for (uint32 i = 0; i <= EternalKilnAlive; ++i)
            {
                if (EternalKilnAlive == 0)
                    return;

                else
                {
                    if (Creature* Kilns = Unit::GetCreature(*me, EternalKilnGUID[i]))
                    {
                        if (Kilns->GetOwnerGUID() == me->GetGUID())
                        {
                        	EternalKilnGUID[i] = 0;
                            Kilns->DespawnOrUnsummon();
                        }

                        else
                            return;
                    }
                }
            }

            BlazingBlowTimer = urand(5000, 7500);
            CauterizeTimer = urand(15000, 30000);
            ConjureEternalKilnTimer = 20000;
            ConjureFlarecoreGolemTimer = urand(12000, 32000);
            FireStormTimer = urand(11000, 15100);

            InCombat = false;

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* target) override
        {
            Talk(SAY_ARCHIEREUS_AGGRO);

            InCombat = true;
        }

        void JustDied(Unit* killer) override
        {
            for (uint32 i = 0; i <= FlareCoreGolemAlive; ++i)
            {
                if (FlareCoreGolemAlive == 0)
                    return; // If it's 0, why would it remove 0? XD

                else
                {
                    if (Creature* Golems = Unit::GetCreature(*me, FlareCoreGolemGUID[i]))
                    {
                        if (Golems->GetOwnerGUID() == me->GetGUID())
                        {
                        	FlareCoreGolemGUID[i] = 0;
                            Golems->DespawnOrUnsummon();
                        }

                        else
                            return;
                    }
                }
            }

            for (uint32 i = 0; i <= EternalKilnAlive; ++i)
            {
                if (EternalKilnAlive == 0)
                    return;

                else
                {
                    if (Creature* Kilns = Unit::GetCreature(*me, EternalKilnGUID[i]))
                    {
                        if (Kilns->GetOwnerGUID() == me->GetGUID())
                        {
                        	EternalKilnGUID[i] = 0;
                            Kilns->DespawnOrUnsummon();
                        }

                        else
                            return;
                    }
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case 73527:
                    FlareCoreGolemGUID = summon->GetGUID();
                    FlareCoreGolemAlive = FlareCoreGolemAlive + 1;
                    break;

                case 73528:
                    EternalKilnGUID = summon->GetGUID();
                    EternalKilnAlive = EternalKilnAlive + 1;
                    break;
                default:
                    break;
            }
        }

        void SummonedCreatureDies(Creature* summoned, Unit* who) override
        {
            switch (summoned->GetEntry())
            {
                case 73527:
                    FlareCoreGolemGUID = 0;
                    FlareCoreGolemAlive = FlareCoreGolemAlive - 1;
                    break;

                case 73528:
                    EternalKilnGUID = 0;
                    EternalKilnAlive = EternalKilnAlive - 1;
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

            if (!InCombat)
                return;

            if (me->isDead())
                return;

            if (BlazingBlowTimer <= diff)
            {
                DoCastAOE(SPELL_BLAZING_BLOW, false);

                BlazingBlowTimer = urand(5500, 7500);
            }

            else
                BlazingBlowTimer -= diff;

            if (CauterizeTimer <= diff)
            {
                DoCast(me, SPELL_CAUTERIZE);

                CauterizeTimer = urand(20000, 30000);
            }

            else
                CauterizeTimer -= diff;

            if (ConjureEternalKilnTimer <= diff)
            {
                DoCast(me, SPELL_CONJURE_ETERNAL_KILN);

                ConjureEternalKilnTimer = urand(18000, 32000);
            }

            else
                ConjureEternalKilnTimer -= diff;

            if (ConjureFlarecoreGolemTimer <= diff)
            {
                DoCast(me, SPELL_CONJURE_FLARECORE_GOLEM);

                ConjureFlarecoreGolemTimer = 30000;
            }

            else
                ConjureFlarecoreGolemTimer -= diff;

            if (FireStormTimer <= diff)
            {
                DoCastAOE(SPELL_FIRE_STORM, false);

                FireStormTimer = urand(12000, 27000);
            }

            else
                FireStormTimer -= diff;

            DoMeleeAttackIfReady();
        }
    
    private:
        uint64 EternalKilnGUID;
        uint64 FlareCoreGolemGUID;

        uint32 EternalKilnAlive;
        uint32 FlareCoreGolemAlive;
        uint32 BlazingBlowTimer;
        uint32 ConjureEternalKilnTimer;

        bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archiereus_of_flameAI(creature);
    }
};
*/
class npc_champion_of_the_black_flame : public CreatureScript
{
public:
    npc_champion_of_the_black_flame() : CreatureScript("npc_champion_of_the_black_flame") { }

    struct npc_champion_of_the_black_flameAI : public ScriptedAI
    {
        npc_champion_of_the_black_flameAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 BlazingCleaveTimer;
        uint32 BurningFuryTimer;

        void Reset() override
        {
            BlazingCleaveTimer = urand(8000, 11000);
            BurningFuryTimer = urand(14000, 17000);
            FieryChargeTimer = 4000;

            InCombat = false;

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
            InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

            if (!InCombat)
                return;

            if (me->isDead())
                return;

            if (BlazingCleaveTimer <= diff)
            {
                DoCastAOE(SPELL_BLAZING_CLEAVE, false);

                BlazingCleaveTimer = urand(14000, 22000);
            }

            else
                BlazingCleaveTimer -= diff;

            if (BurningFuryTimer <= diff)
            {
                DoCast(me, SPELL_BURNING_FURY);

                BurningFuryTimer = urand(16000, 24000);
            }

            else
                BurningFuryTimer -= diff;

            if (FieryChargeTimer <= diff)
            {
                if (!me->GetVictim())
                    return;

                if (me->GetDistance(me->GetVictim()) < 20.0f)
                    return;

                if (me->GetDistance(me->GetVictim()) > 60.0f)
                    return;

                else if (me->GetDistance(me->GetVictim()) >= 20.0f)
                    DoCastVictim(SPELL_FIERY_CHARGE, false);

                FieryChargeTimer = urand(3000, 6000);
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 FieryChargeTimer;

        bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_champion_of_the_black_flameAI(creature);
    }
};

class npc_chelon : public CreatureScript
{
public:
    npc_chelon() : CreatureScript("npc_chelon") { }

    struct npc_chelonAI : public ScriptedAI
    {
        npc_chelonAI(Creature* creature) : ScriptedAI(creature) { }

        // Chelon and Great Turtle Furyshell have the SAME exact script...

        void Reset() override
        {
            GeyserTimer = urand(4000, 6000);
            ShellSpinTimer = urand(5000, 7000);
            SnappingBiteTimer = urand(2500, 12500);

            InCombat = false;

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
            InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

            if (!InCombat)
                return;

            if (me->isDead())
                return;

            if (GeyserTimer <= diff)
            {
                DoCastVictim(SPELL_GEYSER, false);

                GeyserTimer = urand(10000, 14000);
            }

            else
                GeyserTimer -= diff;

            if (ShellSpinTimer <= diff)
            {
                DoCastAOE(SPELL_SHELL_SPIN, false);

                ShellSpinTimer = urand(11000, 15000);
            }

            else
                ShellSpinTimer -= diff;

            if (SnappingBiteTimer <= diff)
            {
                DoCastVictim(SPELL_SNAPPING_BITE, false);

                SnappingBiteTimer = urand(10000, 18000);
            }

            else
                SnappingBiteTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 GeyserTimer;
        uint32 ShellSpinTimer;
        uint32 SnappingBiteTimer;

        bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chelonAI(creature);
    }
};

class npc_cranegnasher : public CreatureScript
{
public:
    npc_cranegnasher() : CreatureScript("npc_cranegnasher") { }

    struct npc_cranegnasherAI : public ScriptedAI
    {
        npc_cranegnasherAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 BiteMorselTimer;
        uint32 ClawTimer;
        uint32 PounceTimer;
        uint32 RakeTimer;

        void Reset() override
        {
            DoCast(me, SPELL_STEALTH);
            DoCast(me, SPELL_HUNGRY);

            BiteMorselTimer = urand(6000, 10000);
            ClawTimer = urand(7000, 11500);
            PounceTimer = urand(3000, 7000);
            RakeTimer = urand(4000, 9000);

            InCombat = false;

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
            InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

            if (!InCombat)
                return;

            if (me->isDead())
                return;

            if (BiteMorselTimer <= diff)
            {
                DoCastVictim(SPELL_BITE_MORSEL);

                BiteMorselTimer = 12000;
            }

            if (ClawTimer <= diff)
            {
                DoCastVictim(SPELL_CLAW);

                ClawTimer = urand(8000, 15000);
            }

            if (PounceTimer <= diff)
            {
                if (me->GetDistance(me->GetVictim()) < 10.0f)
                    return;

                if (me->GetDistance(me->GetVictim()) > 40.0f)
                    return;

                else if (me->GetDistance(me->GetVictim()) >= 10.0f)
                    DoCastVictim(SPELL_POUNCE);

                PounceTimer = urand(2000, 3500);
            }

            if (RakeTimer <= diff)
            {
                DoCastVictim(SPELL_RAKE);

                RakeTimer = urand(7000, 14000);
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cranegnasherAI(creature);
    }
};

class npc_jakur_of_ordon : public CreatureScript
{
public:
    npc_jakur_of_ordon() : CreatureScript("npc_jakur_of_ordon") { }

    struct npc_jakur_of_ordonAI : public ScriptedAI
    {
        npc_jakur_of_ordonAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 CrackingBlowTimer;
        uint32 DefensiveShieldTimer;
        uint32 OathofGuardianshipTimer;

        void Reset() override
        {
        	CrackingBlowTimer = urand(5000, 8000);
        	DefensiveShieldTimer = urand(12000, 15500);
        	OathofGuardianshipTimer = 18000;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (CrackingBlowTimer <= diff)
        	{
        		DoCastAOE(SPELL_CRACKING_BLOW, false);

        		CrackingBlowTimer = urand(8000, 11000);
        	}

        	else
        		CrackingBlowTimer -= diff;

        	if (DefensiveShieldTimer <= diff)
        	{
        		DoCast(me, SPELL_DEFENSIVE_SHIELD);

        		DefensiveShieldTimer = urand(15000, 17000);
        	}

        	else
        		DefensiveShieldTimer -= diff;

        	if (OathofGuardianshipTimer <= diff)
        	{
        		DoCast(me, SPELL_OATH_OF_GUARDIANSHIP);

        		OathofGuardianshipTimer = urand(18000, 20000);
        	}

        	else
        		OathofGuardianshipTimer -= diff;

        	DoMeleeAttackIfReady();
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
    	return new npc_jakur_of_ordonAI(creature);
    }
};

class npc_bufo : public CreatureScript
{
public:
    npc_bufo() : CreatureScript("npc_bufo") { }

    struct npc_bufoAI : public ScriptedAI
    {
        npc_bufoAI(Creature* creature) : ScriptedAI(creature) { }

        // REALLY simple rare... barely even worth a C++ script...

        uint32 GulpFrogToxinTimer;

        void Reset() override
        {
        	DoCast(me, SPELL_TOXIC_SKIN);

        	GulpFrogToxinTimer = 2800;

        	InCombat = false;

        	me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*target*/) override
        {
        	InCombat = true;
        }

        void UpdateAI(uint32 diff) override
        {
        	if (!UpdateVictim())
        		return;

        	if (me->HasUnitState(UNIT_STATE_CASTING))
        		return;

        	if (!InCombat)
        		return;

        	if (me->isDead())
        		return;

        	if (GulpFrogToxinTimer <= diff)
        	{
        		if (me->IsWithinMeleeRange(me->GetVictim()))
        			DoCastVictim(SPELL_GULP_FROG_TOXIN);

        		else
        			return;

        		GulpFrogToxinTimer = urand(2800, 4000);
        	}

        	else
        		GulpFrogToxinTimer -= diff;
        }

    private:
    	bool InCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
    	return new npc_bufoAI(creature);
    }
};

class npc_evermaw : public CreatureScript
{
public:
    npc_evermaw() : CreatureScript("npc_evermaw") { }

    struct npc_evermawAI : public ScriptedAI
    {
        npc_evermawAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 DevourTimer;

        void Reset() override
        {
        	DevourTimer = 500;

        	me->SetReactState(REACT_PASSIVE);
        	me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
        }

        void UpdateAI(uint32 diff) override
        {
        	if (DevourTimer <= diff)
        	{
        		if (Unit* unit = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true)) // I don't know how to define it good. :(
        		{
        			if (me->IsWithinMeleeRange(unit) && unit->isInFront(me)) // make sure that the player is in front of Evermaw, and not behind him...
        				DoCast(unit, SPELL_DEVOUR);

        			else
        				return;
        		}

        		DevourTimer = 1;
        	}

        	else
        		DevourTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
    	return new npc_evermawAI(creature);
    }
};

void AddSC_timeless_isle()
{
	new npc_cinderfall();
	new npc_huolon();
	new npc_imperial_python();
	new npc_emerald_gander();
	new npc_golganarr();
	new npc_watcher_osu();
	new npc_tsavoka();
	new npc_spirit_of_jadefire();
	new npc_monstrous_spineclaw();
	new npc_great_turtle_furyshell();
	new npc_ironfur_steelhorn();
//	new npc_flintlord_gairan();
//    new npc_archiereus_of_flame();
    new npc_champion_of_the_black_flame();
    new npc_chelon();
    new npc_cranegnasher();
    new npc_jakur_of_ordon();
    new npc_bufo();
    new npc_evermaw();
}
