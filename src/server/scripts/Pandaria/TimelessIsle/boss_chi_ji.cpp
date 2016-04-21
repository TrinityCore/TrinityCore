#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "Player.h"
#include "Unit.h"
#include "UnitAI.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "timeless_isle.h"

enum Spells
{
	SPELL_FIRESTORM					= 144461,
	SPELL_INSPIRING_SONG			= 144468,
	SPELL_BEACON_OF_HOPE			= 144473,
	SPELL_BLAZING_SONG				= 144471,
	SPELL_CRANE_RUSH				= 144470,
	SPELL_FIRESTORM_VISUAL			= 144463,
	SPELL_BLAZING_NOVA				= 144494,
};

enum Events
{
	EVENT_FIRESTORM					= 0,
	EVENT_INSPIRING_SONG			= 1,
	EVENT_BEACON_OF_HOPE			= 2,
	EVENT_CRANE_RUSH				= 3,
	EVENT_DEFEATED_1				= 4,
	EVENT_DEFEATED_2				= 5,
	EVENT_DEFEATED_3				= 6,
};

enum Actions
{
	ACTION_DEFEATED					= 0,
};

enum Says
{
	SAY_AGGRO						= 0,
	SAY_BEACON_OF_HOPE				= 1,
	SAY_CRANE_RUSH					= 2,
	SAY_KILL						= 3,
	SAY_DEFEATED_1					= 4,
};

enum Phases
{
	PHASE_INTRO						= 0,
	PHASE_COMBAT					= 1,
	PHASE_DEFEATED					= 2
};

class BlazingSongEvent : public BasicEvent
{
    public:
        BlazingSongEvent(Creature* ChiJi): _owner(ChiJi){}

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _owner->AI()->DoCastAOE(SPELL_BLAZING_SONG, false);

            return true;
        }

    private:
        Creature* _owner;
};

class boss_chi_ji_ti : public CreatureScript
{
    public:
        boss_chi_ji_ti() : CreatureScript("boss_chi_ji_ti") { }

        struct boss_chi_ji_tiAI : public BossAI
        {
            boss_chi_ji_tiAI(Creature* creature) : BossAI(creature, DATA_CHI_JI) {	}

            void CancelAllCombatEventsAndReset()
            {
            	me->InterruptNonMeleeSpells(true);

            	events.SetPhase(PHASE_DEFEATED);

            	events.CancelEvent(EVENT_FIRESTORM);
                events.CancelEvent(EVENT_INSPIRING_SONG);
                events.CancelEvent(EVENT_BEACON_OF_HOPE);
                events.CancelEvent(EVENT_CRANE_RUSH);

                me->m_Events.KillAllEvents(true);
            }

            void Reset() override
            {
                _Reset();
                me->setFaction(35);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                events.SetPhase(PHASE_INTRO);
            }

            void EnterCombat(Unit* /*target*/) override
            {
                me->setActive(true);
                Talk(SAY_AGGRO);

                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_FIRESTORM, 10000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_INSPIRING_SONG, 20000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BEACON_OF_HOPE, urand(29000, 31000), 0, PHASE_COMBAT);
            }

            void EnterEvadeMode()
            {
                BossAI::EnterEvadeMode();

                if (Defeated == true)
                {
                	CancelAllCombatEventsAndReset();

                	me->AI()->DoAction(ACTION_DEFEATED);
                	summons.DespawnAll();
                }

                else if (Defeated == false)
                	me->Respawn(true);
            }

			void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER && !me->IsInEvadeMode() && events.IsInPhase(PHASE_COMBAT))
                    Talk(SAY_KILL);

                if (!me->GetVictim() && !me->IsInEvadeMode())
                {
                	Defeated = false;
                	EnterEvadeMode();
                }
            }

			void DoAction(int32 action) override
            {
                switch (action)
                {
                	case ACTION_DEFEATED:
                		events.ScheduleEvent(EVENT_DEFEATED_1, 1000, 0, PHASE_DEFEATED);
                		events.ScheduleEvent(EVENT_DEFEATED_2, 11000, 0, PHASE_DEFEATED);
                		events.ScheduleEvent(EVENT_DEFEATED_3, 17000, 0, PHASE_DEFEATED);
                		break;
                	default:
                		break;
                }
            }

			void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (events.IsInPhase(PHASE_COMBAT) && !HealthAbovePct(66))
                {
                	events.ScheduleEvent(EVENT_CRANE_RUSH, 1000, 0, PHASE_COMBAT);
                	return;
                }

                if (events.IsInPhase(PHASE_COMBAT) && !HealthAbovePct(33))
                {
                	events.ScheduleEvent(EVENT_CRANE_RUSH, 1000, 0, PHASE_COMBAT);
                	return;
                }

                if (events.IsInPhase(PHASE_COMBAT) && !HealthAbovePct(3))
                {
                    damage = 0;
                	Defeated = true;

                	EnterEvadeMode();
                	return;
                }
            }

			void UpdateAI(uint32 diff) override
            {
                if (events.IsInPhase(PHASE_COMBAT))
                {
                    if (!UpdateVictim())
                        return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (events.IsInPhase(PHASE_INTRO))
                	return;
				// #todo
                /*while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    	case EVENT_FIRESTORM:
                    		DoCastAOE(SPELL_FIRESTORM, false);
                    		events.ScheduleEvent(EVENT_FIRESTORM, urand(15000, 30000), 0, PHASE_COMBAT); 
                    		break;

                    	case EVENT_INSPIRING_SONG:
                    		DoCast(me, SPELL_INSPIRING_SONG);
                    		events.ScheduleEvent(EVENT_INSPIRING_SONG, 30000, 0, PHASE_COMBAT);
                    		break;

                    	case EVENT_BEACON_OF_HOPE:
                    		if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    		{
                    			Talk(SAY_BEACON_OF_HOPE);
                    			DoCast(target, SPELL_BEACON_OF_HOPE);
                    			me->m_Events.AddEvent(new BlazingSongEvent(me), me->m_Events.CalculateTime(3000));
                    		}

                    		events.ScheduleEvent(EVENT_BEACON_OF_HOPE, urand(78000, 80000), 0, PHASE_COMBAT);
                    		break;

                    	case EVENT_CRANE_RUSH:
                    		Talk(SAY_CRANE_RUSH);
                    		DoCastAOE(SPELL_CRANE_RUSH, false);
                    		break;

                    	case EVENT_DEFEATED_1:
                    		Talk(SAY_DEFEATED_1);
                    		break;

                    	case EVENT_DEFEATED_2:
                    		me->Respawn();
                    		me->setActive(false);
                    		me->setFaction(35);
                    		me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    		break;

                    	case EVENT_DEFEATED_3:
                    		if (Creature* Shaohao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 500.0f))
                    			Shaohao->AI()->Talk(SAY_DEFEATED_CHI_JI);
                    		break;
                    	default:
                    		break;
                    }
                }

                DoMeleeAttackIfReady();*/
            }

        private:
        	bool Defeated;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_chi_ji_tiAI(creature);
        }
};

void AddSC_worldboss_chiji()
{
    new boss_chi_ji_ti();
}
