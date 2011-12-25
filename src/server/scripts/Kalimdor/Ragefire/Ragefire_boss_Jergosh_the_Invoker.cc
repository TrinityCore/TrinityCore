#include "ScriptPCH.h"
#include "Neltharion_Ragefire_Chasm.h"


#define    SPELL_Immolate				20800
#define    SPELL_CurseofWeakness		18267


class boss_Jergosh_the_Invoker : public CreatureScript
{
    public:
        boss_Jergosh_the_Invoker() : CreatureScript("boss_Jergosh_the_Invoker") { }

		 CreatureAI *GetAI(Creature* pCreature) const
        {
            return new boss_Jergosh_the_InvokerAI(pCreature);
        }

        struct boss_Jergosh_the_InvokerAI : public ScriptedAI
        {
            boss_Jergosh_the_InvokerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
				m_pInstance = pCreature->GetInstanceScript();
				Reset();
            }
			 InstanceScript* m_pInstance;

			 uint32 uiImmolateTimer;
			 uint32 uiCurseofWeaknessTimer;

            void Reset()
            {
				 uiImmolateTimer							= 1*IN_MILLISECONDS;
				 uiCurseofWeaknessTimer                     = 5*IN_MILLISECONDS;
				 if (m_pInstance)
					m_pInstance->SetData(DATA_Jergosh_the_Invoker, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (m_pInstance)
					  m_pInstance->SetData(DATA_Jergosh_the_Invoker, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
               if (m_pInstance)
					 m_pInstance->SetData(DATA_Jergosh_the_Invoker, DONE);
            }

            void KilledUnit(Unit * who)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

			if (uiImmolateTimer <= diff)
            {
                DoCastVictim(SPELL_Immolate);
                uiImmolateTimer =  20*IN_MILLISECONDS;
            } else
				uiImmolateTimer -= diff;

			if (uiCurseofWeaknessTimer <= diff)
            {
                DoCastVictim(SPELL_CurseofWeakness);
                uiCurseofWeaknessTimer =  35*IN_MILLISECONDS;
            } else 
				uiCurseofWeaknessTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

       
};
void AddSC_boss_Jergosh_the_Invoker()
{
    new boss_Jergosh_the_Invoker();
}
