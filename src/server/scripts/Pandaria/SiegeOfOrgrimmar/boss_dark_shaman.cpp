///*
//* Copyright (C) 2015-2016 JadeCore <https://github.com/cooler-SAI/JadeCore548-patched>
//* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
///*
//	Earthbreaker Haromm - Spells
//	
//	Earthbreaker Haromm's basic ability is Froststorm Strike Froststorm Strike. 
//	This deals high Frost damage to Haromm's tank, and affects them with a stacking debuff 
//	that causes them to take 25% increased damage from Froststorm Strike for 30 seconds. 
//	This debuff stacks. This ability requires a tank switch.
//	
//	When reaching 85% health, Haromm gains Toxic Mist Toxic Mist. 
//	This is an undispellable 30-second DoT, cast on random raid members, that deals Nature damage 
//	every 3 seconds. With each tick, the player also gains a stack of a debuff that increases their 
//	Nature damage taken by 10%. This debuff wears off at the same time as the DoT. 
//	The damage of Toxic Mist goes through all immunities.
//	
//	When reaching 65% health, Haromm gains Foul Stream Foul Stream. 
//	This ability targets an area on the ground, in the shape of a long, wide line. 
//	The area is marked with a green effect, and a few seconds later, any players standing 
//	there take high Nature damage. Haromm casts Foul Stream roughly every 30 seconds.
//	
//	When reaching 50% health, Haromm gains Ashen Wall Ashen Wall. 
//	This summons a wall of stationary Ash Elementals that attack players who are in 
//	their melee range for very high amounts of damage. The Elementals cannot be 
//	tanked or killed, and they last for a very long time (possibly indefinitely). 
//	The ability is cast roughly every 30 seconds.
//*/
//
///*
//	Wavebinder Kardris - Spells
//	
//	Wavebinder Kardris' basic ability is Froststorm Bolt Froststorm Bolt. 
//	This is an uninterruptible nuke that Kardris regularly casts on his tank. 
//	It deals a very high amount of Frost damage.
//	
//	When reaching 85% health, Kardris gains Toxic Storm Toxic Storm. 
//	This ability summons a cloud that moves slowly around the arena, 
//	dealing damage to any players who are under it. Moreover, the cloud regularly 
//	creates Toxic Tornadoes, which also move around the arena, dealing damage to any 
//	players they touch, and knocking them up slightly. The ability is cast roughly every 30 seconds, 
//	and each cloud lasts for about 90 seconds, meaning that it eventually leads to spacial constraints.
//	
//	When reaching 65% health, Kardris gains Foul Geyser Foul Geyser. 
//	Kardris channels Foul Geyser for 8 seconds, dealing damage to any players 
//	around him and summoning many adds called Foul Slimes. The Foul Slime adds 
//	can be tanked, and they have an aura that constantly deals Nature damage to 
//	any players within 3 yards of them. Foul Geyser is cast roughly every 30 seconds.
//	
//	When reaching 50% health, Kardris gains Falling Ash Falling Ash. 
//	This ability targets a large area on the ground, marking it with a 
//	red effect. About 15 seconds later, a fiery projectile will land in this area, 
//	dealing lethal damage to anyone inside it, as well as a moderate amount of raid-wide Fire damage. 
//	The ability is cast roughly every 30 seconds.
//*/
//
///*
//	10 NM mode == 100%
//	10 HC mode == 100%
//
//	25 NM mode - not tested
//	25 HC mode - not tested
//*/
//
//#include "siege_of_orgrimmar.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//
//enum Spells
//{
//	// Mini Enrage spell
//	SPELL_BLOODLUST				= 144302, // Both bosses casts this on themselves when they reach 25% health
//
//	// Earthbreaker Haromm spells
//	SPELL_FROSTSTORM_STRIKE		= 144215, // Boss starts casting this spell from start of the fight
//
//	SPELL_TOXIC_MIST			= 144089, // Boss starts casting this spell when he reaches 85% health
//	SPELL_TOXICITY				= 144107,
//
//	SPELL_FOUL_STREAM			= 144090, // Boss starts casting this spell when he reaches 65% health
//
//	SPELL_ASHEN_WALL			= 144070, // Boss starts casting this spell when he reaches 50% health
//
//	// Wavebinder Kardris spells
//	SPELL_FROSTSTORM_BOLT		= 144214, // Boss starts casting this spell from start of the fight
//
//	SPELL_TOXIC_STORM			= 144005, // Boss starts casting this spell when he reaches 85% health
//	SPELL_TOXIC_STORM_DAMAGE	= 144017,
//	SPELL_TOXIC_TORNADO			= 144019, // Triggers Toxic Tornado spell
//	SPELL_TOXIC_TORNADO_DAMAGE	= 144030,
//	SPELL_TOXIC_TORNADO_VISUAL	= 144029, // Visual for Toxic Tornado
//	SPELL_TOXIC_STORM_VISUAL	= 144006, // Visual for Toxic Storm
//
//	SPELL_FOUL_GEYSER			= 143990, // Boss starts casting this spell when he reaches 65% health
//	SPELL_FOULNESS				= 144064,
//	SPELL_FOULNESS_DAMAGE		= 144066,
//
//	SPELL_FALLING_ASH			= 143973, // Boss starts casting this spell when he reaches 50% health
//	SPELL_FALLING_ASH_VISUAL	= 143986, // Visual falling
//	SPELL_FALLING_ASH_EXPLOSION	= 143987, // Damage
//
//	// Heroic mode spells
//	SPELL_IRON_TOMB				= 144334,
//	SPELL_IRON_PRISON			= 144330,
//	SPELL_IRON_PRISON_DAMAGE	= 144331,
//
//	// Darkfang and Bloodclaw spells
//	SPELL_SWIPE					= 144303,
//	SPELL_REND					= 144304,
//
//	// Totems
//	SPELL_POISONMIST_TOTEM		= 144288,
//	SPELL_FOULSTREAM_TOTEM		= 144289,
//	SPELL_ASHFLARE_TOTEM		= 144290,
//	SPELL_RUSTED_IRON_TOTEM		= 144291,
//
//	// Spirit Link
//	SPELL_SPIRIT_LINK_HAROMM	= 144227,
//	SPELL_SPIRIT_LINK_KARDRIS	= 144226,
//};
//
//enum TalksHaromm
//{
//	// Earthbreaker Haromm
//	TALK_INTRO_HAROMM_ONE		= 0, // Storm! - First (39022)
//	TALK_INTRO_HAROMM_TWO		= 1, // And fire! - Third (39023)
//	TALK_INTRO_HAROMM_THREE		= 2, // Bend to our will! - Fourth - No Sound
//	TALK_INTRO_HAROMM_FOUR		= 3, // The True Horde takes what it wants! (39020)
//	TALK_SPELL_HAROMM_ONE		= 4, // Anguished water, stagnant and poisonous! (39025)
//	TALK_DEATH_HAROMM			= 5, // The elements... What have we done... (39021)
//	TALK_KILL_HAROMM			= 6, // Your skull will endore my necklace! (39024)
//};
//
//enum TalksKardris
//{
//	// Wavebinder Kardris
//	TALK_INTRO_KARDRIS_ONE		= 0, // Earth! - Second (39016)
//	TALK_INTRO_KARDRIS_TWO		= 1, // Bend to our will! - Fourth - No Sound
//	TALK_INTRO_KARDRIS_THREE	= 2, // We do not ask elements for aid! (39014)
//	TALK_SPELL_KARDRIS_ONE		= 3, // Tortured wind, stale and toxic! (39018)
//	TALK_SPELL_KARDRIS_TWO		= 4, // Long dead fire, black and smouldering! (39019)
//	TALK_DEATH_KARDRIS			= 5, // I can hear them... No longer... (39015)
//	TALK_KILL_KARDRIS			= 6, // Ha Ha Ha, my wolfs will feast on your blood! (39017)
//};
//
//enum Events
//{
//	// Earthbreaker Haromm
//	EVENT_FROSTSTORM_STRIKE		= 1,
//	EVENT_TOXIC_MIST			= 2,
//	EVENT_FOUL_STREAM			= 3,
//	EVENT_ASHEN_WALL			= 4,
//
//	// Wavebinder Kardris
//	EVENT_FROSTSTORM_BOLT		= 5,
//	EVENT_TOXIC_STORM			= 6,
//	EVENT_FOUL_GEYSER			= 7,
//	EVENT_FALLING_ASH			= 8,
//
//	// Mini Enrage
//	EVENT_BLOODLUST				= 9,
//
//	// Heroic only
//	EVENT_IRON_TOMB				= 10,
//	EVENT_IRON_PRISON			= 11,
//
//	// Darkfand And Bloodclaw events
//	EVENT_SWIPE					= 12,
//	EVENT_REND					= 13,
//
//	// Toxic Storm
//	EVENT_TOXIC_STORM_VISUAL	= 14,
//	EVENT_TOXIC_STORM_DAMAGE	= 15,
//
//	// Toxic Tornado
//	EVENT_TOXIC_TORNADO_VISUAL	= 16,
//	EVENT_TOXIC_TORNADO_DAMAGE	= 17,
//
//	// Falling Ash
//	EVENT_FALLING_ASH_DAMAGE	= 18,
//	EVENT_FALLING_CHECK			= 19,
//
//	EVENT_MOVE_RANDOM			= 20,
//
//	// Foul Slime
//	EVENT_FOULNESS				= 21,
//
//	// Talk events
//	EVENT_TALK_HAROMM_ONE		= 22,
//	EVENT_TALK_HAROMM_TWO		= 23,
//	EVENT_TALK_HAROMM_THREE		= 24,
//	EVENT_TALK_HAROMM_FOUR		= 25,
//	EVENT_TALK_KARDRIS_ONE		= 26,
//	EVENT_TALK_KARDRIS_TWO		= 27,
//	EVENT_TALK_KARDRIS_THREE	= 28,
//};
//
//enum Creatures
//{
//	CREATURE_TOXIC_STORM		= 71801,
//	CREATURE_TOXIC_TORNADO		= 71817,
//	CREATURE_FALLING_ASH		= 71789,
//	CREATURE_ASH_ELEMENTAL		= 71827,
//	CREATURE_FOUL_SLIME			= 71825,
//	CREATURE_FOULSTREAM_TOTEM	= 71916,
//	CREATURE_ASHFLARE_TOTEM		= 71917,
//	CREATURE_POISONMIST_TOTEM	= 71915,
//	CREATURE_RUSTED_IRON_TOTEM	= 71918,
//
//	CREATURE_DARKFANG			= 71921,
//	CREATURE_BLOODCLAW			= 71923,
//};
//
//enum Phases
//{
//	PHASE_ONE	= 1,
//	PHASE_TWO	= 2,
//	PHASE_THREE	= 3,
//	PHASE_FOUR	= 4,
//	PHASE_FIVE	= 5,
//};
//
//enum Gameobjects
//{
//	GOBJECT_IRON_TOMB	= 220864,
//};
//
//#define FLOOR_Z 21.0f
//
///*
//void FallingAshPosition()
//{
//	InstanceScript* instance;
//
//	if (Creature* kardris = instance->instance->GetCreature(instance->GetData64(DATA_WAVEBINDER_KARDRIS))
//
//}*/
//
//static void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//{
//	std::list<Creature*> creatures;
//	GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//	if (creatures.empty())
//		return;
//
//	for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//		(*iter)->DespawnOrUnsummon();
//}
//
//// 71859 - Earthbreaker Haromm
//class boss_earthbreaker_haromm : public CreatureScript
//{
//	public:
//		boss_earthbreaker_haromm() : CreatureScript("boss_earthbreaker_haromm") { }
//
//		struct boss_earthbreaker_harommAI : public BossAI
//		{
//			boss_earthbreaker_harommAI(Creature* creature) : BossAI(creature, DATA_EARTHBREAKER_HAROMM)
//			{
//				m_Instance = creature->GetInstanceScript();
//				me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				_Reset();
//				events.Reset();
//				summons.DespawnAll();
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//
//				switch (me->GetMap()->GetDifficulty())
//				{
//					case MAN10_DIFFICULTY:
//						me->SetMaxHealth(435000000);
//						break;
//					case MAN10_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(654000000);
//						break;
//					case MAN25_DIFFICULTY:
//						me->SetMaxHealth(1000000000);
//						break;
//					case MAN25_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(1900000000);
//						break;
//				}
//
//				me->SetReactState(ReactStates::REACT_AGGRESSIVE);
//
//				me->setFaction(16);
//				DoCast(me, SPELL_SPIRIT_LINK_HAROMM);
//			}
//
//			void DamageTaken(Unit* attacker, uint32& damage)
//			{
//				
//			}
//
//			void JustReachedHome()
//			{
//				_JustReachedHome();
//
//				if (m_Instance)
//				{
//					m_Instance->SetBossState(DATA_EARTHBREAKER_HAROMM, FAIL);
//				}
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//
//				int32 gobjects[1] =
//				{
//					GOBJECT_IRON_TOMB
//				};
//
//				if (Creature* Darkfang = me->FindNearestCreature(CREATURE_DARKFANG, 500.0f, true))
//					if (Creature* Bloodclaw = me->FindNearestCreature(CREATURE_BLOODCLAW, 500.0f, true))
//					{
//						Darkfang->AI()->Reset();
//						Darkfang->Respawn();
//						Darkfang->GetMotionMaster()->MovePoint(0, Darkfang->GetHomePosition().GetPositionX(), Darkfang->GetHomePosition().GetPositionY(), Darkfang->GetHomePosition().GetPositionZ());
//
//						Bloodclaw->AI()->Reset();
//						Bloodclaw->Respawn();
//						Bloodclaw->GetMotionMaster()->MovePoint(0, Bloodclaw->GetHomePosition().GetPositionX(), Bloodclaw->GetHomePosition().GetPositionY(), Bloodclaw->GetHomePosition().GetPositionZ());
//					}
//			}
//
//			void KilledUnit(Unit* who)
//			{
//				if (who->GetTypeId() == TYPEID_PLAYER)
//					Talk(TALK_KILL_HAROMM);
//			}
//
//			void EnterCombat(Unit* who)
//			{
//				_EnterCombat();
//				m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//				events.SetPhase(PHASE_ONE);
//				Talk(TALK_INTRO_HAROMM_ONE);
//				events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_ONE);
//				events.ScheduleEvent(EVENT_TALK_HAROMM_TWO, 4000, 0, PHASE_ONE);
//
//				if (me->GetMap()->IsHeroic())
//				{ 
//					DoCast(SPELL_RUSTED_IRON_TOTEM);
//					events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_ONE);
//				}
//			}
//
//			void JustDied(Unit* killer)
//			{
//				_JustDied();
//
//				Talk(TALK_DEATH_HAROMM);
//				if (m_Instance)
//				{
//					m_Instance->SetBossState(DATA_EARTHBREAKER_HAROMM, DONE);
//				}
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				if (!UpdateVictim())
//					return;
//
//				if (me->HasUnitState(UNIT_STATE_CASTING))
//					return;
//
//				events.Update(diff);
//
//				if (HealthBelowPct(85) && events.IsInPhase(PHASE_ONE))
//				{
//					events.Reset();
//					DoCast(SPELL_POISONMIST_TOTEM);
//					events.SetPhase(PHASE_TWO);
//					events.RescheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_TWO);
//					events.ScheduleEvent(EVENT_TOXIC_MIST, 1000, 0, PHASE_TWO);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_TOMB, 0, 30000, PHASE_TWO);
//				}
//
//				if (HealthBelowPct(65) && events.IsInPhase(PHASE_TWO))
//				{
//					events.Reset();
//					DoCast(SPELL_FOULSTREAM_TOTEM);
//					events.SetPhase(PHASE_THREE);
//					events.RescheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_THREE);
//					events.RescheduleEvent(EVENT_TOXIC_MIST, 30000, 0, PHASE_THREE);
//					events.ScheduleEvent(EVENT_FOUL_STREAM, 1000, 0, PHASE_THREE);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_TOMB, 0, 30000, PHASE_THREE);
//				}
//
//				if (HealthBelowPct(50) && events.IsInPhase(PHASE_THREE))
//				{
//					events.Reset();
//					DoCast(SPELL_ASHFLARE_TOTEM);
//					events.SetPhase(PHASE_FOUR);
//					events.RescheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_FOUR);
//					events.RescheduleEvent(EVENT_TOXIC_MIST, 25000, 0, PHASE_FOUR);
//					events.RescheduleEvent(EVENT_FOUL_STREAM, 30000, 0, PHASE_FOUR);
//					events.ScheduleEvent(EVENT_ASHEN_WALL, 1000, 0, PHASE_FOUR);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_TOMB, 0, 30000, PHASE_FOUR);
//				}
//
//				if (HealthBelowPct(25) && events.IsInPhase(PHASE_FOUR))
//				{
//					events.SetPhase(PHASE_FIVE);
//					events.RescheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_FIVE);
//					events.RescheduleEvent(EVENT_TOXIC_MIST, 20000, 0, PHASE_FIVE);
//					events.RescheduleEvent(EVENT_FOUL_STREAM, 25000, 0, PHASE_FIVE);
//					events.RescheduleEvent(EVENT_ASHEN_WALL, 30000, 0, PHASE_FIVE);
//					events.ScheduleEvent(EVENT_BLOODLUST, 1000, 0, PHASE_FIVE);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_TOMB, 0, 35000, PHASE_FIVE);
//				}
//
//				switch (events.ExecuteEvent())
//				{
//					case EVENT_TALK_HAROMM_TWO:
//					{
//						Talk(TALK_INTRO_HAROMM_TWO);
//						events.ScheduleEvent(EVENT_TALK_HAROMM_THREE, 7000, 0, PHASE_ONE);
//						break;
//					}
//
//					case EVENT_TALK_HAROMM_THREE:
//					{
//						Talk(TALK_INTRO_HAROMM_THREE);
//						events.ScheduleEvent(EVENT_TALK_HAROMM_FOUR, 16000, 0, PHASE_ONE);
//						break;
//					}
//
//					case EVENT_TALK_HAROMM_FOUR:
//					{
//						Talk(TALK_INTRO_HAROMM_FOUR);
//						break;
//					}
//
//					case EVENT_FROSTSTORM_STRIKE:
//					{
//						DoCastVictim(SPELL_FROSTSTORM_STRIKE, true);
//						if (events.IsInPhase(PHASE_ONE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_ONE);
//						else if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, 7000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_TOXIC_MIST:
//					{
//						if (Unit* target_one = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							DoCast(target_one, SPELL_TOXIC_MIST);
//						}
//						if (Unit* target_two = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							DoCast(target_two, SPELL_TOXIC_MIST);
//						}
//
//						if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_TOXIC_MIST, 30000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_TOXIC_MIST, 30000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_TOXIC_MIST, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_TOXIC_MIST, 30000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_FOUL_STREAM:
//					{
//						if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							me->CastSpell(target, SPELL_FOUL_STREAM);
//						}
//
//						if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_FOUL_STREAM, 30000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_FOUL_STREAM, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_FOUL_STREAM, 30000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_ASHEN_WALL:
//					{
//						float posX = me->GetPositionX();
//						float posY = me->GetPositionY();
//						float posZ = me->GetPositionZ();
//						float O = me->GetOrientation();
//						Position position[11] =
//						{
//							{ posX + 12.5f, posY + 12.5f, posZ, O },
//							{ posX + 10.0f, posY + 10.0f, posZ, O },
//							{ posX + 7.5f, posY + 7.5f, posZ, O },
//							{ posX + 5.0f, posY + 5.0f, posZ, O },
//							{ posX + 2.5f, posY + 2.5f, posZ, O },
//							{ posX, posY, posZ, O },
//							{ posX - 2.5f, posY - 2.5f, posZ, O },
//							{ posX - 5.0f, posY - 5.0f, posZ, O },
//							{ posX - 7.5f, posY - 7.5f, posZ, O },
//							{ posX - 10.0f, posY - 10.0f, posZ, O },
//							{ posX - 12.5f, posY - 12.5f, posZ, O },
//						};
//
//						for (int i = 0; i < 11; i++)
//						{
//							me->SummonCreature(71827, position[i], TEMPSUMMON_MANUAL_DESPAWN);
//						}
//						
//						if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_ASHEN_WALL, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_ASHEN_WALL, 30000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_BLOODLUST:
//					{
//						DoCast(me, SPELL_BLOODLUST);
//						break;
//					}
//
//					case EVENT_IRON_TOMB:
//					{
//						if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							me->CastSpell(target, SPELL_IRON_TOMB);
//						}
//
//						if (events.IsInPhase(PHASE_ONE))
//							events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_ONE);
//						else if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_IRON_TOMB, 30000, 0, PHASE_FIVE);
//						break;
//					}
//					default:
//						break;
//				}
//
//				DoMeleeAttackIfReady();
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new boss_earthbreaker_harommAI(creature);
//		}
//};
//
//// 71858 - Wavebinder Kardris
//class boss_wavebinder_kardris : public CreatureScript
//{
//	public:
//		boss_wavebinder_kardris() : CreatureScript("boss_wavebinder_kardris") { }
//
//		struct boss_wavebinder_kardrisAI : public BossAI
//		{
//			boss_wavebinder_kardrisAI(Creature* creature) : BossAI(creature, DATA_WAVEBINDER_KARDRIS)
//			{
//				m_Instance = creature->GetInstanceScript();
//				me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//				me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				_Reset();
//				events.Reset();
//				summons.DespawnAll();
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//
//				switch (me->GetMap()->GetDifficulty())
//				{
//					case MAN10_DIFFICULTY:
//						me->SetMaxHealth(435000000);
//						break;
//					case MAN10_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(654000000);
//						break;
//					case MAN25_DIFFICULTY:
//						me->SetMaxHealth(1000000000);
//						break;
//					case MAN25_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(1900000000);
//						break;
//				}
//
//				me->SetReactState(ReactStates::REACT_AGGRESSIVE);
//
//				me->setFaction(16);
//				DoCast(me, SPELL_SPIRIT_LINK_KARDRIS);
//			}
//
//			void DamageTaken(Unit* attacker, uint32& damage)
//			{
//				
//			}
//
//			void JustReachedHome()
//			{
//				_JustReachedHome();
//
//				if (m_Instance)
//				{
//					m_Instance->SetBossState(DATA_WAVEBINDER_KARDRIS, FAIL);
//				}
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//
//				if (Creature* Darkfang = me->FindNearestCreature(CREATURE_DARKFANG, 500.0f, true))
//					if (Creature* Bloodclaw = me->FindNearestCreature(CREATURE_BLOODCLAW, 500.0f, true))
//					{
//						Darkfang->AI()->Reset();
//						Darkfang->Respawn();
//						Darkfang->GetMotionMaster()->MovePoint(0, Darkfang->GetHomePosition().GetPositionX(), Darkfang->GetHomePosition().GetPositionY(), Darkfang->GetHomePosition().GetPositionZ());
//
//						Bloodclaw->AI()->Reset();
//						Bloodclaw->Respawn();
//						Bloodclaw->GetMotionMaster()->MovePoint(0, Bloodclaw->GetHomePosition().GetPositionX(), Bloodclaw->GetHomePosition().GetPositionY(), Bloodclaw->GetHomePosition().GetPositionZ());
//					}
//			}
//
//			void KilledUnit(Unit* who)
//			{
//				if (who->GetTypeId() == TYPEID_PLAYER)
//					Talk(TALK_KILL_KARDRIS);
//			}
//
//			void EnterCombat(Unit* /*who*/)
//			{
//				_EnterCombat();
//				m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//				events.SetPhase(PHASE_ONE);
//				events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_ONE);
//				events.ScheduleEvent(EVENT_TALK_KARDRIS_ONE, 2000, 0, PHASE_ONE);
//				
//				if (me->GetMap()->IsHeroic())
//					events.ScheduleEvent(EVENT_IRON_PRISON, 30000, 0, PHASE_ONE);
//			}
//
//			void JustDied(Unit* killer)
//			{
//				_JustDied();
//
//				Talk(TALK_DEATH_KARDRIS);
//				if (m_Instance)
//				{
//					m_Instance->SetBossState(DATA_WAVEBINDER_KARDRIS, DONE);
//				}
//
//				int32 Creatures[9] =
//				{
//					CREATURE_TOXIC_STORM,
//					CREATURE_TOXIC_TORNADO,
//					CREATURE_FALLING_ASH,
//					CREATURE_ASH_ELEMENTAL,
//					CREATURE_FOUL_SLIME,
//					CREATURE_FOULSTREAM_TOTEM,
//					CREATURE_ASHFLARE_TOTEM,
//					CREATURE_POISONMIST_TOTEM,
//					CREATURE_RUSTED_IRON_TOTEM,
//				};
//
//				for (int i = 0; i <= 8; i++)
//					DespawnCreaturesInArea(Creatures[i], me);
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				if (!UpdateVictim())
//					return;
//
//				if (me->HasUnitState(UNIT_STATE_CASTING))
//					return;
//
//				events.Update(diff);
//
//				if (HealthBelowPct(85) && events.IsInPhase(PHASE_ONE))
//				{
//					events.Reset();
//					DoCast(SPELL_POISONMIST_TOTEM);
//					events.SetPhase(PHASE_TWO);
//					events.RescheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_TWO);
//					events.ScheduleEvent(EVENT_TOXIC_STORM, 1000, 0, PHASE_TWO);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_PRISON, 30000, 0, PHASE_TWO);
//				}
//
//				if (HealthBelowPct(65) && events.IsInPhase(PHASE_TWO))
//				{
//					events.Reset();
//					DoCast(SPELL_FOULSTREAM_TOTEM);
//					events.SetPhase(PHASE_THREE);
//					events.RescheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_THREE);
//					events.RescheduleEvent(EVENT_TOXIC_STORM, 25000, 0, PHASE_THREE);
//					events.ScheduleEvent(EVENT_FOUL_GEYSER, 1000, 0, PHASE_THREE);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_PRISON, 30000, 0, PHASE_TWO);
//				}
//
//				if (HealthBelowPct(50) && events.IsInPhase(PHASE_THREE))
//				{
//					events.Reset();
//					DoCast(SPELL_ASHFLARE_TOTEM);
//					events.SetPhase(PHASE_FOUR);
//					events.RescheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_FOUR);
//					events.RescheduleEvent(EVENT_TOXIC_STORM, 20000, 0, PHASE_FOUR);
//					events.RescheduleEvent(EVENT_FOUL_GEYSER, 25000, 0, PHASE_FOUR);
//					// events.ScheduleEvent(EVENT_FALLING_ASH, 1000, 0, PHASE_FOUR);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_PRISON, 30000, 0, PHASE_ONE);
//				}
//
//				if (HealthBelowPct(25) && events.IsInPhase(PHASE_FOUR))
//				{
//					events.SetPhase(PHASE_FIVE);
//					events.RescheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_FIVE);
//					events.RescheduleEvent(EVENT_TOXIC_STORM, 20000, 0, PHASE_FIVE);
//					events.RescheduleEvent(EVENT_FOUL_GEYSER, 25000, 0, PHASE_FIVE);
//					// events.RescheduleEvent(EVENT_FALLING_ASH, 35000, 0, PHASE_FIVE);
//					events.ScheduleEvent(EVENT_BLOODLUST, 1000, 0, PHASE_FIVE);
//
//					if (me->GetMap()->IsHeroic())
//						events.ScheduleEvent(EVENT_IRON_PRISON, 30000, 0, PHASE_ONE);
//				}
//
//				switch (events.ExecuteEvent())
//				{
//					case EVENT_TALK_KARDRIS_ONE:
//					{
//						Talk(TALK_INTRO_KARDRIS_ONE);
//						events.ScheduleEvent(EVENT_TALK_KARDRIS_TWO, 7000, 0, PHASE_ONE);
//						break;
//					}
//					case EVENT_TALK_KARDRIS_TWO:
//					{
//						Talk(TALK_INTRO_KARDRIS_TWO);
//						events.ScheduleEvent(EVENT_TALK_KARDRIS_THREE, 12000, 0, PHASE_ONE);
//						break;
//					}
//
//					case EVENT_TALK_KARDRIS_THREE:
//					{
//						Talk(TALK_INTRO_KARDRIS_THREE);
//						break;
//					}
//
//					case EVENT_FROSTSTORM_BOLT:
//					{
//						DoCastVictim(SPELL_FROSTSTORM_BOLT);
//
//						if (events.IsInPhase(PHASE_ONE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_ONE);
//						else if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, 7000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_TOXIC_STORM:
//					{
//						if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							me->CastSpell(target, SPELL_TOXIC_STORM);
//						}
//
//						if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_TOXIC_STORM, 30000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_TOXIC_STORM, 30000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_TOXIC_STORM, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_TOXIC_STORM, 30000, 0, PHASE_FIVE);
//						break;
//					}
//
//					case EVENT_FOUL_GEYSER:
//					{
//						DoCastVictim(SPELL_FOUL_GEYSER);
//
//						if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_FOUL_GEYSER, 30000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_FOUL_GEYSER, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_FOUL_GEYSER, 30000, 0, PHASE_FIVE);
//						break;
//					}
//					/*
//					case EVENT_FALLING_ASH:
//					{
//						DoCast(SPELL_FALLING_ASH);
//
//						if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_FALLING_ASH, 30000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_FALLING_ASH, 30000, 0, PHASE_FIVE);
//						break;
//					}
//					*/
//					case EVENT_BLOODLUST:
//					{
//						DoCast(me, SPELL_BLOODLUST);
//						break;
//					}
//
//					case EVENT_IRON_PRISON:
//					{
//						if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 40.0f, true))
//						{
//							me->CastSpell(target, SPELL_IRON_PRISON);
//						}
//						
//						if (events.IsInPhase(PHASE_ONE))
//							events.ScheduleEvent(EVENT_IRON_PRISON, 7000, 0, PHASE_ONE);
//						else if (events.IsInPhase(PHASE_TWO))
//							events.ScheduleEvent(EVENT_IRON_PRISON, 7000, 0, PHASE_TWO);
//						else if (events.IsInPhase(PHASE_THREE))
//							events.ScheduleEvent(EVENT_IRON_PRISON, 7000, 0, PHASE_THREE);
//						else if (events.IsInPhase(PHASE_FOUR))
//							events.ScheduleEvent(EVENT_IRON_PRISON, 7000, 0, PHASE_FOUR);
//						else if (events.IsInPhase(PHASE_FIVE))
//							events.ScheduleEvent(EVENT_IRON_PRISON, 7000, 0, PHASE_FIVE);
//
//						break;
//					}
//					default:
//						break;
//				}
//
//				DoMeleeAttackIfReady();
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new boss_wavebinder_kardrisAI(creature);
//		}
//};
//
//// 71801 - Toxic Storm
//class npc_toxic_storm : public CreatureScript
//{
//	public:
//		npc_toxic_storm() : CreatureScript("npc_toxic_storm") { }
//
//		struct npc_toxic_stormAI : public ScriptedAI
//		{
//			npc_toxic_stormAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//				me->SetVisible(true);
//				me->setFaction(16);
//				me->SetInCombatWithZone();
//				me->SetSpeed(MOVE_RUN, 0.05f, true);
//				me->ForcedDespawn(60000000);
//				events.Reset();
//				me->CastSpell(me, SPELL_TOXIC_STORM_VISUAL);
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_toxic_stormAI(creature);
//		}
//};
//
//// 71817 - Toxic Tornado
//class npc_toxic_tornado : public CreatureScript
//{
//	public:
//		npc_toxic_tornado() : CreatureScript("npc_toxic_tornado") { }
//
//		struct npc_toxic_tornadoAI : public ScriptedAI
//		{
//			npc_toxic_tornadoAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//				me->SetVisible(true);
//				me->setFaction(16);
//				me->SetInCombatWithZone();
//				me->SetSpeed(MOVE_RUN, 0.05f, true);
//				me->ForcedDespawn(60000000);
//				events.Reset();
//				me->CastSpell(me, SPELL_TOXIC_TORNADO_VISUAL);
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_toxic_tornadoAI(creature);
//		}
//};
///*
//// 71789 - Falling Ash
//class npc_falling_ash : public CreatureScript
//{
//	public:
//		npc_falling_ash() : CreatureScript("npc_falling_ash") { }
//
//		struct npc_falling_ashAI : public ScriptedAI
//		{
//			npc_falling_ashAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				if (Creature* kardris = me->FindNearestCreature(BOSS_WAVEBINDER_KARDRIS, 500.0f, true))
//				{
//					if (me->GetPositionZ() > kardris->GetPositionZ())
//					{
//						float posX = kardris->GetPositionX();
//						float posY = kardris->GetPositionY();
//						float O = kardris->GetOrientation();
//						float posZ = kardris->GetPositionZ();
//						
//						Position pos = { urand(posX-15, posX+15), urand(posY-15, posY+15), posZ, O };
//						me->GetMotionMaster()->MoveLand(1, pos);
//					}
//				}
//
//				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//				me->SetVisible(true);
//				me->SetSpeed(MOVE_FLIGHT, 0.5f, true);
//				DoCast(me, SPELL_FALLING_ASH_VISUAL);
//				events.ScheduleEvent(EVENT_FALLING_ASH_DAMAGE, 10000);
//				events.ScheduleEvent(EVENT_FALLING_CHECK, 1000);
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				switch (events.ExecuteEvent())
//				{
//					events.Update(diff);
//
//					case EVENT_FALLING_ASH_DAMAGE:
//					{
//						if (Creature* kardris = me->FindNearestCreature(BOSS_WAVEBINDER_KARDRIS, 500.0f, true))
//						{
//							if (me->GetPositionZ() <= kardris->GetPositionZ())
//							{
//								DoCast(me, SPELL_FALLING_ASH_EXPLOSION);
//								me->DespawnOrUnsummon(1);
//							}
//						}
//						
//						break;
//					}
//
//					case EVENT_FALLING_CHECK:
//					{
//						if (Creature* kardris = me->FindNearestCreature(BOSS_WAVEBINDER_KARDRIS, 500.0f, true))
//						{
//							if (me->GetPositionZ() > kardris->GetPositionZ())
//							{
//								float posX = kardris->GetPositionX();
//								float posY = kardris->GetPositionY();
//								float O = kardris->GetOrientation();
//								float posZ = kardris->GetPositionZ();
//
//								Position pos = { urand(posX - 15, posX + 15), urand(posY - 15, posY + 15), posZ, O };
//								me->GetMotionMaster()->MoveLand(1, pos);
//							}
//						}
//
//						events.ScheduleEvent(EVENT_FALLING_CHECK, 1000);
//						break;
//					}
//
//					default:
//						break;
//				}
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_falling_ashAI(creature);
//		}
//};
//*/
//// 71827 - Ash Elemental
//class npc_ash_elemental : public CreatureScript
//{
//	public:
//		npc_ash_elemental() : CreatureScript("npc_ash_elemental") { }
//
//		struct npc_ash_elementalAI : public ScriptedAI
//		{
//			npc_ash_elementalAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				me->SetReactState(ReactStates::REACT_AGGRESSIVE);
//				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
//				me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
//				me->SetInCombatWithZone();
//				me->setFaction(16);
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				events.Update(diff);
//				DoMeleeAttackIfReady();
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_ash_elementalAI(creature);
//		}
//};
//
//// 71825 - Foul Slime
//class npc_foul_slime : public CreatureScript
//{
//	public:
//		npc_foul_slime() : CreatureScript("npc_foul_slime") { }
//
//		struct npc_foul_slimeAI : public ScriptedAI
//		{
//			npc_foul_slimeAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				switch (me->GetMap()->GetDifficulty())
//				{
//					case MAN10_DIFFICULTY:
//						me->SetMaxHealth(400000);
//						break;
//					case MAN10_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(400000);
//						break;
//					case MAN25_DIFFICULTY:
//						me->SetMaxHealth(1200000);
//						break;
//					case MAN25_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(1200000);
//						break;
//				}
//
//				me->SetReactState(ReactStates::REACT_AGGRESSIVE);
//				me->setFaction(16);
//
//				DoCast(me, SPELL_FOULNESS);
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				events.Update(diff);
//				DoMeleeAttackIfReady();
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_foul_slimeAI(creature);
//		}
//};
//
//// 71921 - Darkfang and 71923 - Bloodclaw
//class npc_darkfang_and_bloodclaw : public CreatureScript
//{
//	public:
//		npc_darkfang_and_bloodclaw() : CreatureScript("npc_darkfang_and_bloodclaw") { }
//
//		struct npc_darkfang_and_bloodclawAI : public ScriptedAI
//		{
//			npc_darkfang_and_bloodclawAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				switch (me->GetMap()->GetDifficulty())
//				{
//					case MAN10_DIFFICULTY:
//						me->SetMaxHealth(12700000);
//						break;
//					case MAN10_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(63000000);
//						break;
//					case MAN25_DIFFICULTY:
//						me->SetMaxHealth(122000000);
//						break;
//					case MAN25_HEROIC_DIFFICULTY:
//						me->SetMaxHealth(189000000);
//						break;
//				}
//				me->setFaction(16);
//				me->SetReactState(ReactStates::REACT_AGGRESSIVE);
//				events.Reset();
//				events.ScheduleEvent(EVENT_SWIPE, urand(5000, 10000));
//				events.ScheduleEvent(EVENT_REND, urand(5000, 10000));
//			}
//
//			void UpdateAI(const uint32 diff)
//			{
//				if (!UpdateVictim())
//					return;
//
//				if (me->HasUnitState(UNIT_STATE_CASTING))
//					return;
//
//				events.Update(diff);
//
//				switch (events.ExecuteEvent())
//				{
//					case EVENT_SWIPE:
//					{
//						DoCastVictim(SPELL_SWIPE);
//						events.ScheduleEvent(EVENT_SWIPE, urand(5000, 10000));
//						break;
//					}
//
//					case EVENT_REND:
//					{
//						DoCastVictim(SPELL_REND);
//						events.ScheduleEvent(EVENT_REND, urand(5000, 10000));
//						break;
//					}
//				}
//
//				DoMeleeAttackIfReady();
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_darkfang_and_bloodclawAI(creature);
//		}
//};
//
//// 71916 - Foulstream Totem, 71917 - Ashflare Totem, 71915 - Poisonmist Totem and 71918 - Rusted Iron Totem
//class npc_totems : public CreatureScript
//{
//	public:
//		npc_totems() : CreatureScript("npc_totems") { }
//
//		struct npc_totemsAI : public ScriptedAI
//		{
//			npc_totemsAI(Creature* creature) : ScriptedAI(creature)
//			{
//				m_Instance = creature->GetInstanceScript();
//			}
//
//			InstanceScript* m_Instance;
//
//			void Reset() override
//			{
//				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
//				me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
//			}
//		};
//
//		CreatureAI* GetAI(Creature* creature) const override
//		{
//			return new npc_totemsAI(creature);
//		}
//};
//
//// 144089 - Toxic Mist
//class spell_toxic_mist : public SpellScriptLoader
//{
//	public:
//		spell_toxic_mist() : SpellScriptLoader("spell_toxic_mist") { }
//
//		class spell_toxic_mist_SpellScript : public SpellScript
//		{
//			PrepareSpellScript(spell_toxic_mist_SpellScript);
//
//			void HandleOnHit()
//			{
//				if (Unit* target = GetHitUnit())
//					if (target->GetTypeId() == TYPEID_PLAYER)
//						SetHitDamage(80000);
//			}
//
//			void Register()
//			{
//				OnHit += SpellHitFn(spell_toxic_mist_SpellScript::HandleOnHit);
//			}
//		};
//
//		SpellScript* GetSpellScript() const
//		{
//			return new spell_toxic_mist_SpellScript();
//		}
//};
//
//// 144331 - Iron Prison
//class spell_iron_prison : public SpellScriptLoader
//{
//	public:
//		spell_iron_prison() : SpellScriptLoader("spell_iron_prison") { }
//
//		class spell_iron_prison_SpellScript : public SpellScript
//		{
//			PrepareSpellScript(spell_iron_prison_SpellScript);
//
//			void HandleOnHit()
//			{
//
//				if (Unit* target = GetHitUnit())
//				{
//					uint32 damage = target->GetHealth();
//
//					if (target->GetTypeId() == TYPEID_PLAYER)
//						SetHitDamage(damage);
//				}
//			}
//
//			void Register()
//			{
//				OnHit += SpellHitFn(spell_iron_prison_SpellScript::HandleOnHit);
//			}
//		};
//
//		SpellScript* GetSpellScript() const
//		{
//			return new spell_iron_prison_SpellScript();
//		}
//};
//
//// 144334 - Iron Tomb
//class spell_iron_tomb : public SpellScriptLoader
//{
//	public:
//		spell_iron_tomb() : SpellScriptLoader("spell_iron_tomb") { }
//
//		class spell_iron_tomb_SpellScript : public SpellScript
//		{
//			PrepareSpellScript(spell_iron_tomb_SpellScript);
//
//			void HandleOnCast()
//			{
//				if (Unit* caster = GetCaster())
//					if (Unit* target = GetHitUnit())
//					{
//						float posX = target->GetPositionX();
//						float posY = target->GetPositionY();
//						float posZ = target->GetPositionZ();
//						float angl = target->GetOrientation();
//
//						caster->SummonGameObject(GOBJECT_IRON_TOMB, posX, posY, posZ, angl, 0, 0, 0, 0, TEMPSUMMON_MANUAL_DESPAWN);
//					}
//			}
//
//			void Register()
//			{
//				OnCast += SpellCastFn(spell_iron_tomb_SpellScript::HandleOnCast);
//			}
//
//			SpellScript* GetSpellScript() const
//			{
//				return new spell_iron_tomb_SpellScript();
//			}
//		};
//};
//
//void AddSC_boss_dark_shaman()
//{
//	// Boss
//	new boss_earthbreaker_haromm();
//	new boss_wavebinder_kardris();
//
//	// Creatures
//	new npc_toxic_storm();
//	new npc_toxic_tornado();
//	// new npc_falling_ash();
//	new npc_ash_elemental();
//	new npc_foul_slime();
//	new npc_darkfang_and_bloodclaw();
//	new npc_totems();
//
//	// Spells
//	new spell_toxic_mist();
//	new spell_iron_prison();
//	new spell_iron_tomb();
//}
