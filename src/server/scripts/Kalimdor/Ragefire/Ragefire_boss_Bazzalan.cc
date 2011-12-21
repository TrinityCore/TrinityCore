#include "ScriptPCH.h"
#include "Neltharion_Ragefire_Chasm.h"


#define    SPELL_SinisterStrike				14873


class boss_Bazzalan : public CreatureScript
{
    public:
        boss_Bazzalan() : CreatureScript("boss_Bazzalan") { }

		 CreatureAI *GetAI(Creature* pCreature) const
        {
            return new boss_BazzalanAI(pCreature);
        }

        struct boss_BazzalanAI : public ScriptedAI
        {
            boss_BazzalanAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
				m_pInstance = pCreature->GetInstanceScript();
				Reset();
            }
			 InstanceScript* m_pInstance;

			 uint32 uiSinisterStrikeTimer;


            void Reset()
            {
				 uiSinisterStrikeTimer							= 5*IN_MILLISECONDS;
				 if (m_pInstance)
					m_pInstance->SetData(DATA_Bazzalan, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (m_pInstance)
					  m_pInstance->SetData(DATA_Bazzalan, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
               if (m_pInstance)
					 m_pInstance->SetData(DATA_Bazzalan, DONE);
            }

            void KilledUnit(Unit * who)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

			if (uiSinisterStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_SinisterStrike);
                uiSinisterStrikeTimer =  5*IN_MILLISECONDS;
            } else
				uiSinisterStrikeTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

       
};
void AddSC_boss_Bazzalan()
{
    new boss_Bazzalan();
}
