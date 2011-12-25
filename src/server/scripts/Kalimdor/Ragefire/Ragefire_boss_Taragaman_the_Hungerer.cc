#include "ScriptPCH.h"
#include "Neltharion_Ragefire_Chasm.h"


#define    SPELL_Uppercut		18072 // repousse les ennemis
#define    SPELL_Fire_Nova		11970 // Fait une nova de feu autour de lui


class boss_Taragaman_the_Hungerer : public CreatureScript
{
    public:
        boss_Taragaman_the_Hungerer() : CreatureScript("boss_Taragaman_the_Hungerer") { }

		CreatureAI *GetAI(Creature* pCreature) const
        {
            return new boss_Taragaman_the_HungererAI(pCreature);
        }

        struct boss_Taragaman_the_HungererAI : public ScriptedAI
        {
            boss_Taragaman_the_HungererAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
				m_pInstance = pCreature->GetInstanceScript();
				Reset();
            }
			 InstanceScript* m_pInstance;

			 uint32 uiUppercutTimer;
			 uint32 uiFireNovaTimer;

           /* void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(AScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }*/

            void Reset()
            {
                /*events.Reset();
                events.ScheduleEvent(EVENT_Uppercut, urand(5000, 10000));
                events.ScheduleEvent(EVENT_Fire_Nova, 10000);*/

				 uiUppercutTimer                     = urand(5*IN_MILLISECONDS,15*IN_MILLISECONDS);
				 uiFireNovaTimer                     = 10*IN_MILLISECONDS;
				 if (m_pInstance)
					m_pInstance->SetData(DATA_Taragaman_the_Hungerer, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (m_pInstance)
					  m_pInstance->SetData(DATA_Taragaman_the_Hungerer, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
               if (m_pInstance)
					 m_pInstance->SetData(DATA_Taragaman_the_Hungerer, DONE);
            }

            void KilledUnit(Unit * who)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

              /*  events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
				     return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_Uppercut:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_Uppercut);
                            events.ScheduleEvent(EVENT_Uppercut, urand(5000, 15000));
                            break;
                        case EVENT_Fire_Nova:
								DoCastAOE(SPELL_Fire_Nova);
								events.ScheduleEvent(EVENT_Fire_Nova, 10000));
                            break;
                        default:
                            break;
                    }
               }*/

			if (uiUppercutTimer <= diff)
            {
                DoCastVictim(SPELL_Uppercut);
                uiUppercutTimer =  urand(5*IN_MILLISECONDS,15*IN_MILLISECONDS);
            } else
				uiUppercutTimer -= diff;

			if (uiFireNovaTimer <= diff)
            {
                DoCastAOE(SPELL_Fire_Nova);
                uiFireNovaTimer =  10*IN_MILLISECONDS;
            } else 
				uiFireNovaTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

       
};
void AddSC_boss_Taragaman_the_Hungerer()
{
    new boss_Taragaman_the_Hungerer();
}
