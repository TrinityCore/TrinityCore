#include "ScriptPCH.h"
#include "Neltharion_Ragefire_Chasm.h"


#define    SPELL_Cleave		40505 


class boss_Oggleflint : public CreatureScript
{
    public:
        boss_Oggleflint() : CreatureScript("boss_Oggleflint") { }

		 CreatureAI *GetAI(Creature* pCreature) const
        {
            return new boss_OggleflintAI(pCreature);
        }

        struct boss_OggleflintAI : public ScriptedAI
        {
            boss_OggleflintAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
				m_pInstance = pCreature->GetInstanceScript();
				Reset();
            }
			 InstanceScript* m_pInstance;

			 uint32 uiCleaveTimer;


            void Reset()
            {
				 uiCleaveTimer                     = 5*IN_MILLISECONDS;

				 if (m_pInstance)
					m_pInstance->SetData(DATA_Oggleflint, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (m_pInstance)
					  m_pInstance->SetData(DATA_Oggleflint, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
               if (m_pInstance)
					 m_pInstance->SetData(DATA_Oggleflint, DONE);
            }

            void KilledUnit(Unit * who)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;


			if (uiCleaveTimer <= diff)
            {
                DoCastVictim(SPELL_Cleave);
                uiCleaveTimer =  10*IN_MILLISECONDS;
            } else
				uiCleaveTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

       
};
void AddSC_boss_Oggleflint()
{
    new boss_Oggleflint();
}
