/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This SourceCode is NOT free a software. Please hold everything Private
 * and read our Terms
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_ENRAGE         = 50420,
    SPELL_GROUND_RUPTURE = 119999,
    SPELL_SEISMIC_SLAM   = 120024
};

enum Events
{
    EVENT_RUPTURE,
    EVENT_SLAM
};

enum Creatures
{
    NPC_XORENTH = 61716
};

Position XorenthPos = {-327.424f, 220.4f, -20.381f, 3.56417f};

Position XorenthCenterPos = {-347.99f, 210.165f, -21.785f, 3.52412f};

class boss_gordoth : public CreatureScript
{
    public:
        boss_gordoth() : CreatureScript("boss_gordoth") { }

        struct boss_gordothAI : public ScriptedAI
        {
            boss_gordothAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                rage = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_RUPTURE, 5000);
                events.ScheduleEvent(EVENT_SLAM, 10000);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if(!rage && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(30))
                {
                    rage = true;
                    DoCast(me, SPELL_ENRAGE);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                me->SummonCreature(NPC_XORENTH, XorenthPos);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                switch (summon->GetEntry())
                {
                    case NPC_XORENTH:
                        summon->GetMotionMaster()->MovePoint(0, XorenthCenterPos);
                        return;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if(!UpdateVictim())
                    return;

                events.Update(diff);

                if(me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_SLAM:
                            DoCastVictim(SPELL_SEISMIC_SLAM);
                            events.ScheduleEvent(EVENT_SLAM, 15*IN_MILLISECONDS);
                            break;
                        case EVENT_RUPTURE:
			    DoCastRandom(SPELL_GROUND_RUPTURE, 30);
                            events.ScheduleEvent(EVENT_RUPTURE, 12*IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            bool rage;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gordothAI(creature);
        }
};

void AddSC_boss_gordoth()
{
    new boss_gordoth();
}
