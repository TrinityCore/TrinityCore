/*
 * Copyright (C) 2008-2013 DREAM WOW <http://www.dream-wow.com/>
 * Code by Troxx Rodrigo Alviña
 * 2013-2015
 *
 * Fase 1: lanza spell machacar, pisoton y cristal resonador = 100%
 * Fase 2: lanza pisoton y sangre negra = 100%
 * En hero al 90% de salud invoca a korchom = 100%
 * Al 20% de salud castea Furioso para el = 100%
 
 * Script de Text en Sql sql_boss_dragonsoul.sql
 * Reparacion de Cristal Resonador en Sql sql_boss_dragonsoul.sql
 * Script de ScriptName en slq_boss_dragonsoul.sql
 */
  
#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "dragonsoul.h"

// ENUMERACION DE TEXTOS A DECIR "SQL"
enum Texts
{
	SAY_AGGRO				= -180001,	// USADO	
	SAY_KILL				= -180002,	// USADO
	SAY_DEATH				= -180003,	// USADO
	SAY_SUMMON1				= -180004,	// USADO
	SAY_SUMMON2				= -180005,	// USADO
	SAY_HOME				= -180006,	// USADO
	SAY_MORCHOK_CAST_SANGRE	= -180007,	// USADO
	SAY_KILL2				= -180008,	
	SAY_CAST_RABIA			= -180009,	// USADO
	SAY_HOME2				= -180010,
};

// ENUMERACION SPELL A OCUPAR
enum SPELLIDS
{
	// SPELL FASE 1
	SPELL_MACHACAR			= 103687,		// MACHACAR ARMADURA
	SPELL_PISOTON			= 97282,		// PISOTON
	SPELL_SUMMON_CRISTAL	= 103640,  		// SUMON CRISTAL
	
	// SPELL FASE 2 + HERO
	SPELL_SUMMON			= 109017,		// INVOCAR A PRIMO KROCHOM
	
	// SPELL FASE 3 
	SPELL_BBOTE_VISUAL		= 103851,		// VISUAL SANGRE NEGRA
	SPELL_BBOTE_DOT			= 103875,		// DAÑO SANGRE NEGRA
	SPELL_VENGEANCE			= 103176,		// VENGANZA DE LA TIERRA
	SPELL_VORTEX			= 103821,		// VOTICE TERRANEO
	
	// SPELL 20% DE VIDA
	SPELL_FURIOSO			= 103846,		// FURIOSO AL 20% DE SALUD
	
	// SPELL VARIOS
	SPELL_CLEAR_DEBUFFS     = 34098,		// despejar prejuicios para eliminar buffs
	
	// SPELL CRISTAL RESONADOR
	SPELL_CRISTAL_AURA		= 103494, // AURA AL INICIAR
	SPELL_CRISTAL_DECIR		= 103536, // AURA DE DECIR DAÑO
	SPELL_CRISTAL_EXPLOSION = 83703,  // SPELL DE EXPLOSION
};

enum Events
{
	
// para npc cristal resonador
    EVENT_AURACRISTAL 		= 10,
	EVENT_DECIRCRISTAL		= 11,
	EVENT_EXPLOSION			= 12,
                                                        
};

// posiciones de aparicion
Position const MorchokSpawnPos = {-1986.09f, -2407.83f, 69.533f, 3.09272f};
Position const KohcromSpawnPos = {-2015.687012f, -2385.382324f, 70.755798f, 3.09272f};
 
class boss_morchok : public CreatureScript
{
	public:
		boss_morchok() : CreatureScript("boss_morchok") { }

		struct boss_morchokAI : public BossAI
		{
			boss_morchokAI(Creature* creature) : BossAI(creature, BOSS_MORCHOK)
			{
				InstanceScript* instance;
				instance = creature->GetInstanceScript();
			}
			
			// enumeracion de bases a ocupar
			uint32 BaseHealth;
			uint32 Raid10N;
			uint32 Raid10H;
			uint32 Raid25N;
			uint32 Raid25H;
			uint32 MorchokHealth;
			uint32 KohcromGUID;
			uint32 Phase;
			uint32 Pisoton_Timer;
			uint32 SummonCristal_Timer;
			uint32 Machacar_Timer;
			uint32 Sangre_Timer;

			// al resetear quedara asi: 	
			void Reset() OVERRIDE
			{
				_Reset();
				BaseHealth = 1000000;
				Raid10N = BaseHealth * 36;
				Raid10H = BaseHealth * 21.473;
				Raid25N = BaseHealth * 102;
				Raid25H = BaseHealth * 90.202;
				MorchokHealth = RAID_MODE(Raid10N, Raid25N, Raid10H, Raid25H);
				me->SetMaxHealth(MorchokHealth);
				me->SetFullHealth();
				me->SetHomePosition(MorchokSpawnPos);
                me->GetMotionMaster()->MoveTargetedHome();
				
				Phase = 1;
			}
			
			// al entrar en evadir 
			void EnterEvadeMode() OVERRIDE
            {
																				// resetear eventos
				Talk(SAY_HOME);													// decir al volver a home
                summons.DespawnAll();											// despawn all creatures sumon
                me->GetMotionMaster()->MoveTargetedHome();						// volver a hogar (base)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me, 1);	
                _EnterEvadeMode();
				
				Phase = 1;
            }
			
			// al matar jugadores
			void KilledUnit(Unit* who) OVERRIDE
			{
				if (who->GetTypeId() == TYPEID_PLAYER)							// al matar jugadores decir
					Talk(SAY_KILL);
			}
			
		    // al morir:
			void JustDied(Unit* /*killer*/) OVERRIDE
			{
				_JustDied();
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_MORCHOK, DONE); // data de realizado 
				Talk(SAY_DEATH);
			}

			// al entrar en combate:
			void EnterCombat(Unit* /*who*/) OVERRIDE
			{
				_EnterCombat();
				Talk(SAY_AGGRO); 												// decir en agro
				events.Reset();													// resetear eventos
				
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);		
                instance->SetBossState(DATA_MORCHOK, IN_PROGRESS);

                // Beta
                instance->SetData(DATA_MORCHOK_HEALTH, me->GetHealth());
			}
			
			 void UpdateAI(const uint32 uiDiff)
             {
                 if(!UpdateVictim())
                    return;
				
				if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) == 90) && (Phase == 1))
				{
					Phase = 2; 
				}
				
				if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) < 80) && (Phase == 1))
				{
					Phase = 3;
				}
				
				if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) < 60) && (Phase == 2))
				{
					Phase = 4;
				}
                if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) < 40) && (Phase == 3))
				{
					Phase = 5;
				}    
				if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) == 20) && (Phase == 3))
				{
					Phase = 6;
				}
				if(((me->GetMaxHealth()*100 / me->GetMaxHealth()) < 20) && (Phase == 3))
				{
					Phase = 7;
				}
				
				//FASE 1 DEL 100% DE VIDA AL 80% 
				if (Phase == 1)
				{
					// pisoton spell AOE
					if(Pisoton_Timer <= uiDiff)
                        {
							DoCastAOE(SPELL_PISOTON);
							Pisoton_Timer = 10000;
                        }
                        else
                                Pisoton_Timer -= uiDiff;
								
					// cristal resonador spell random
					if(SummonCristal_Timer <= uiDiff)
						{
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
							DoCast(target, SPELL_SUMMON_CRISTAL);
							Talk(SAY_SUMMON2);
							SummonCristal_Timer = 20000;
						}
						else
								SummonCristal_Timer -= uiDiff;
					
					// spell machacar a tank (victim)
					if(Machacar_Timer <= uiDiff)
						{
							DoCastVictim(SPELL_MACHACAR);
							Machacar_Timer = 15500;
						}
					else 
							Machacar_Timer -= uiDiff;
				}
				
				// FASE 2 AL 90% DE VIDA Y HEROICO SUMONEAR A KROCHOM
				if(Phase == 2 && IsHeroic())
					{	
					 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
						DoCast(target, SPELL_SUMMON);
						Talk(SAY_SUMMON1);
					}
					
				// FASE 3 DE 80% DE VIDA A 60%
				if(Phase == 3)
					{
					// sangre negra de tierra
					if(Sangre_Timer <= uiDiff)
						{
							DoCast(me, SPELL_VENGEANCE);
							DoCast(me, SPELL_BBOTE_VISUAL);
							Talk(SAY_MORCHOK_CAST_SANGRE);
							Sangre_Timer = 20000;
						}
					else 
							Sangre_Timer -= uiDiff;
							
					// pisoton spell AOE
					if(Pisoton_Timer <= uiDiff)
                        {
							DoCastAOE(SPELL_PISOTON);
							Pisoton_Timer = 10000;
                        }
                        else
                                Pisoton_Timer -= uiDiff;
					}
				
				// FASE 4 DE 60% VIDA A 40%
				if (Phase == 4)
				{
					// pisoton spell AOE
					if(Pisoton_Timer <= uiDiff)
                        {
							DoCastAOE(SPELL_PISOTON);
							Pisoton_Timer = 10000;
                        }
                        else
                                Pisoton_Timer -= uiDiff;
								
					// cristal resonador spell random
					if(SummonCristal_Timer <= uiDiff)
						{
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
							DoCast(target, SPELL_SUMMON_CRISTAL);
							Talk(SAY_SUMMON2);
							SummonCristal_Timer = 20000;
						}
						else
								SummonCristal_Timer -= uiDiff;
					
					// spell machacar a tank (victim)
					if(Machacar_Timer <= uiDiff)
						{
							DoCastVictim(SPELL_MACHACAR);
							Machacar_Timer = 15500;
						}
					else 
							Machacar_Timer -= uiDiff;
				}
				
				// FASE 5 40% DE VIDA A 20%
				if(Phase == 5)
					{
					// sangre negra de tierra
					if(Sangre_Timer <= uiDiff)
						{
							DoCast(me, SPELL_VENGEANCE);
							DoCast(me, SPELL_BBOTE_VISUAL);
							Talk(SAY_MORCHOK_CAST_SANGRE);
							Sangre_Timer = 20000;
						}
					else 
							Sangre_Timer -= uiDiff;
							
					// pisoton spell AOE
					if(Pisoton_Timer <= uiDiff)
                        {
							DoCastAOE(SPELL_PISOTON);
							Pisoton_Timer = 10000;
                        }
                        else
                                Pisoton_Timer -= uiDiff;
					}	
				
				// FASE 6 20% DE VIDA
				if(Phase == 6 )
					{	
					 	DoCast(me, SPELL_FURIOSO);
						Talk(SAY_CAST_RABIA);
					}
				
				// FASE FINAL DEL 20% DE VIDA A 0%
				if (Phase == 7)
				{
					// pisoton spell AOE
					if(Pisoton_Timer <= uiDiff)
                        {
							DoCastAOE(SPELL_PISOTON);
							Pisoton_Timer = 10000;
                        }
                        else
                                Pisoton_Timer -= uiDiff;
								
					// cristal resonador spell random
					if(SummonCristal_Timer <= uiDiff)
						{
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
							DoCast(target, SPELL_SUMMON_CRISTAL);
							Talk(SAY_SUMMON2);
							SummonCristal_Timer = 20000;
						}
						else
								SummonCristal_Timer -= uiDiff;
					
					// spell machacar a tank (victim)
					if(Machacar_Timer <= uiDiff)
						{
							DoCastVictim(SPELL_MACHACAR);
							Machacar_Timer = 15500;
						}
					else 
							Machacar_Timer -= uiDiff;
				}
					
                 DoMeleeAttackIfReady();
             }
			
			
			
		};

		// siempre
		CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
        	return GetDragonSoulAI<boss_morchokAI>(creature);
        }
};

// sangre negra de la tierra spell de morchok
class BlackBloodOfEarthFilter
{
	public:
		explicit BlackBloodOfEarthFilter(Unit* caster) : _caster(caster) { }

		bool operator()(WorldObject* unit) const
		{
			return !unit->IsWithinLOSInMap(_caster);
		}
	private:
		Unit* _caster;
};

// sangre negra de la tierra spell morchok

class spell_morchok_bboe : public SpellScriptLoader
{
    public:
        spell_morchok_bboe() : SpellScriptLoader("spell_morchok_bboe") { }

        class spell_morchok_bboe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_morchok_bboe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BlackBloodOfEarthFilter(GetCaster()));
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_bboe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_morchok_bboe_SpellScript();
        }
};

// NPC CRISTAL RESONADOR 55346
class npc_cristal_resonador: public CreatureScript
{
public:
 npc_cristal_resonador() : CreatureScript("npc_cristal_resonador") { }

 struct npc_cristal_resonadorAI : public ScriptedAI
    {
        npc_cristal_resonadorAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

                void EnterCombat(Unit * /*who*/)
                {
                        EnterPhaseGround();
                }

                void EnterPhaseGround()
                {
                        events.ScheduleEvent(EVENT_AURACRISTAL, 1000);
						events.ScheduleEvent(EVENT_DECIRCRISTAL, 7000);
						events.ScheduleEvent(EVENT_EXPLOSION, 11000);
                }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                        events.Update(diff);

                                while (uint32 eventId = events.ExecuteEvent())
                                {
                                        switch(eventId)
                                        {
                                                case EVENT_AURACRISTAL:
                                                        DoCast(me,SPELL_CRISTAL_AURA);
                                                        events.ScheduleEvent(EVENT_AURACRISTAL, 1000);
                                                        return;
												case EVENT_DECIRCRISTAL:
														DoCast(me, SPELL_CRISTAL_DECIR);
														events.ScheduleEvent(EVENT_DECIRCRISTAL, 7000);
														return;
												case EVENT_EXPLOSION:
														DoCastAOE(SPELL_CRISTAL_EXPLOSION);
														me->DespawnOrUnsummon(1000);
														events.ScheduleEvent(EVENT_EXPLOSION, 11000);
														return;
														
                                        }
										
                                }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_cristal_resonadorAI (creature);
    }
};


void AddSC_boss_morchok()
{
	new boss_morchok();
	new spell_morchok_bboe();
	new npc_cristal_resonador();
}