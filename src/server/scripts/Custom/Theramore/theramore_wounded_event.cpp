#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "theramore.h"

enum Misc
{
    // Events
	EVENT_START_TELEPORT	= 1,
	
	EVENT_TELEPORT_1,
	EVENT_TELEPORT_2,
	EVENT_TELEPORT_3,
	EVENT_TELEPORT_4,
	EVENT_TELEPORT_5,
	EVENT_TELEPORT_6,
	EVENT_TELEPORT_7,
	EVENT_TELEPORT_8,
	EVENT_TELEPORT_9
};

class theramore_wounded_event : public CreatureScript
{
    public:
    theramore_wounded_event() : CreatureScript("theramore_wounded_event") {}

    struct theramore_wounded_eventAI : public ScriptedAI
    {
        theramore_wounded_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            currentSoldier = nullptr;
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            if (id == EVENT_START_TELEPORT)
            {
                jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 20.f);
                kalecgos = GetClosestCreatureWithEntry(me, NPC_KALECGOS, 2000.f);
                amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 2000.f);
                rhonin = GetClosestCreatureWithEntry(me, NPC_RHONIN, 40.f);

                jaina->Say("Je vais TP les wounded pour les mettre en safe zone.", LANG_UNIVERSAL);
                jaina->SetWalk(true);

                initJaina = jaina->GetPosition();

                events.ScheduleEvent(EVENT_TELEPORT_5, 2s);
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
					case EVENT_TELEPORT_1:
                    {
                        if (Creature * solider = jaina->FindNearestCreature(NPC_WOUNDED_THERAMORE_GUARD, 15.f))
                        {
                            float distanceToTravel = jaina->GetExactDist2d(solider->GetPosition()) - 1.5f;
                            float angle = jaina->GetAbsoluteAngle(solider);
                            float destx = jaina->GetPositionX() + distanceToTravel * cosf(angle);
                            float desty = jaina->GetPositionY() + distanceToTravel * sinf(angle);
                            float time = (distanceToTravel / jaina->GetSpeed(MOVE_WALK)) * IN_MILLISECONDS;

                            currentSoldier = solider;
                            jaina->GetMotionMaster()->MovePoint(0, destx, desty, solider->GetPositionZ(), true, angle);
                            events.ScheduleEvent(EVENT_TELEPORT_2, time + 2000);
                        }
                        else
                            events.ScheduleEvent(EVENT_TELEPORT_5, 3s);

                        break;
                    }

                    case EVENT_TELEPORT_2:
                        jaina->CastSpell(jaina, SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_3, 1300);
                        break;

                    case EVENT_TELEPORT_3:
                        currentSoldier->CastSpell(currentSoldier, SPELL_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_4, 1500);
                        break;

                    case EVENT_TELEPORT_4:
                        currentSoldier->SetPhaseMask(32, true);
                        events.ScheduleEvent(EVENT_TELEPORT_1, 2s);
                        break;

                    case EVENT_TELEPORT_5:
                        jaina->GetMotionMaster()->MovePoint(0, initJaina, true, initJaina.GetOrientation());
                        events.ScheduleEvent(EVENT_TELEPORT_6, 2s);
                        break;

                    case EVENT_TELEPORT_6:
                    {
                        if (Creature * portal = DoSummon(NPC_INVISIBLE_STALKER, { -3679.66f, -4481.86f, 11.20f, 5.30f }))
                        {
                            portal->SetObjectScale(1.5f);
                            portal->AddAura(SPELL_PORTAL, portal);
                            portal->DespawnOrUnsummon(10s);

                            kalecgos = DoSummon(NPC_KALECGOS, { -3679.84f, -4481.61f, 16.64f, 5.27f }, 0, TEMPSUMMON_MANUAL_DESPAWN);
                            kalecgos->GetMotionMaster()->MoveJump(-3676.04f, -4487.67f, 10.88f, 5.27f, 10.4f, 6.5f);
                        }
                        break;
                    }

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Creature* jaina;
        Creature* kalecgos;
        Creature* rhonin;
        Creature* amara;
        Creature* currentSoldier;
        Position initJaina;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new theramore_wounded_eventAI(creature);
    }
};

void AddSC_theramore_wounded_event()
{
    new theramore_wounded_event();
}
