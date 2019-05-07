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
    
    SAY_TELEPORT_1          = 50,
    SAY_TELEPORT_2          = 51,
    SAY_TELEPORT_3          = 6,
    SAY_TELEPORT_4          = 52,
    SAY_TELEPORT_5          = 7,
    SAY_TELEPORT_6          = 53,
    SAY_TELEPORT_7          = 8,
    SAY_TELEPORT_8          = 54,
    SAY_TELEPORT_9          = 55,
    SAY_TELEPORT_10         = 0,
    SAY_TELEPORT_11         = 56,
    SAY_TELEPORT_12         = 9,
    SAY_TELEPORT_13         = 1,
    SAY_TELEPORT_14         = 57,
    SAY_TELEPORT_15         = 58,
    SAY_TELEPORT_16         = 59,

	EVENT_TELEPORT_1        = 1,
	EVENT_TELEPORT_2,
	EVENT_TELEPORT_3,
	EVENT_TELEPORT_4,
	EVENT_TELEPORT_5,
	EVENT_TELEPORT_6,
	EVENT_TELEPORT_7,
	EVENT_TELEPORT_8,
	EVENT_TELEPORT_9,
	EVENT_TELEPORT_10,
	EVENT_TELEPORT_11,
	EVENT_TELEPORT_12,
	EVENT_TELEPORT_13,
	EVENT_TELEPORT_14,
	EVENT_TELEPORT_15,
	EVENT_TELEPORT_16,
	EVENT_TELEPORT_17,
	EVENT_TELEPORT_18,
	EVENT_TELEPORT_19,
	EVENT_TELEPORT_20,
	EVENT_TELEPORT_21,
	EVENT_TELEPORT_22,
	EVENT_TELEPORT_23,
	EVENT_TELEPORT_24,
	EVENT_TELEPORT_25,
	EVENT_TELEPORT_26,
	EVENT_TELEPORT_27,
	EVENT_TELEPORT_28,
	EVENT_TELEPORT_29
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
                rhonin = GetClosestCreatureWithEntry(me, NPC_RHONIN, 40.f);
                amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 2000.f);

                jaina->AI()->Talk(SAY_TELEPORT_1);
                jaina->SetWalk(true);
                jaina->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                jaina->SetSheath(SHEATH_STATE_UNARMED);
                amara->SetSheath(SHEATH_STATE_UNARMED);
                rhonin->SetVisible(false);

                events.ScheduleEvent(EVENT_TELEPORT_1, 1s);
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
                            events.ScheduleEvent(EVENT_TELEPORT_2, time + 500);
                        }
                        else
                            events.ScheduleEvent(EVENT_TELEPORT_5, 1s);

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
                        jaina->AI()->Talk(SAY_TELEPORT_2);
                        jaina->GetMotionMaster()->MovePoint(0, -3665.92f, -4515.97f, 10.09f, true, 1.90f);
                        events.ScheduleEvent(EVENT_TELEPORT_6, 7s);
                        break;

                    case EVENT_TELEPORT_6:
                        if (Creature* p = DoSummon(NPC_INVISIBLE_STALKER, { -3679.66f, -4481.86f, 11.20f, 5.30f }, 0, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            portal = p;
                            p->SetObjectScale(1.5f);
                            p->AddAura(SPELL_PORTAL, p);
                            kalecgos = DoSummon(NPC_KALECGOS, { -3679.84f, -4481.61f, 16.64f, 5.27f }, 0, TEMPSUMMON_MANUAL_DESPAWN);
                            kalecgos->GetMotionMaster()->MoveJump(-3676.04f, -4487.67f, 10.88f, 5.27f, 10.4f, 6.5f);
                            events.ScheduleEvent(EVENT_TELEPORT_7, 3s);
                            events.ScheduleEvent(EVENT_TELEPORT_8, 3s);
                        }
                        break;

                    case EVENT_TELEPORT_7:
                        kalecgos->AI()->Talk(SAY_TELEPORT_3);
                        kalecgos->GetMotionMaster()->MovePoint(0, -3667.18f, -4511.07f, 10.09f, true, 4.98f);
                        break;

                    case EVENT_TELEPORT_8:
                        jaina->AI()->Talk(SAY_TELEPORT_4);
                        jaina->SetFacingToObject(kalecgos);
                        events.ScheduleEvent(EVENT_TELEPORT_9, 3s);
                        break;

                    case EVENT_TELEPORT_9:
                        kalecgos->AI()->Talk(SAY_TELEPORT_5);
                        events.ScheduleEvent(EVENT_TELEPORT_10, 4s);
                        break;

                    case EVENT_TELEPORT_10:
                        jaina->AI()->Talk(SAY_TELEPORT_6);
                        events.ScheduleEvent(EVENT_TELEPORT_11, 7s);
                        break;

                    case EVENT_TELEPORT_11:
                        kalecgos->AI()->Talk(SAY_TELEPORT_7);
                        events.ScheduleEvent(EVENT_TELEPORT_12, 3s);
                        break;

                    case EVENT_TELEPORT_12:
                        jaina->AI()->Talk(SAY_TELEPORT_8);
                        events.ScheduleEvent(EVENT_TELEPORT_13, 7s);
                        break;

                    case EVENT_TELEPORT_13:
                        jaina->AI()->Talk(SAY_TELEPORT_9);
                        jaina->SetFacingToObject(amara);
                        events.ScheduleEvent(EVENT_TELEPORT_14, 5s);
                        break;

                    case EVENT_TELEPORT_14:
                        amara->AI()->Talk(SAY_TELEPORT_10);
                        events.ScheduleEvent(EVENT_TELEPORT_15, 3s);
                        break;

                    case EVENT_TELEPORT_15:
                        amara->CastSpell(amara, SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_16, 1300);
                        break;

                    case EVENT_TELEPORT_16:
                        amara->CastSpell(amara, SPELL_TELEPORT);
                        jaina->SetFacingToObject(kalecgos);
                        events.ScheduleEvent(EVENT_TELEPORT_17, 1500);
                        break;

                    case EVENT_TELEPORT_17:
                        amara->SetVisible(false);
                        jaina->AI()->Talk(SAY_TELEPORT_11);
                        events.ScheduleEvent(EVENT_TELEPORT_18, 2s);
                        break;

                    case EVENT_TELEPORT_18:
                        kalecgos->AI()->Talk(SAY_TELEPORT_12);
                        events.ScheduleEvent(EVENT_TELEPORT_19, 8s);
                        break;

                    case EVENT_TELEPORT_19:
                        jaina->SetFacingTo(2.05f);
                        kalecgos->GetMotionMaster()->MovePoint(0, -3676.04f, -4487.67f, 10.88f, true, 2.15f);
                        events.ScheduleEvent(EVENT_TELEPORT_20, 5s);
                        break;

                    case EVENT_TELEPORT_20:
                        kalecgos->GetMotionMaster()->MoveJump(-3679.84f, -4481.61f, 16.64f, 5.27f, 10.4f, 6.5f);
                        portal->DespawnOrUnsummon(4s);
                        kalecgos->DespawnOrUnsummon(1s);
                        events.ScheduleEvent(EVENT_TELEPORT_21, 5s);
                        break;

                    case EVENT_TELEPORT_21:
                        amara->SetVisible(true);
                        amara->SetFacingToObject(jaina);
                        jaina->SetFacingToObject(amara);
                        events.ScheduleEvent(EVENT_TELEPORT_22, 1s);
                        break;

                    case EVENT_TELEPORT_22:
                        amara->CastSpell(amara, SPELL_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_23, 2s);
                        break;

                    case EVENT_TELEPORT_23:
                        amara->AI()->Talk(SAY_TELEPORT_13);
                        events.ScheduleEvent(EVENT_TELEPORT_24, 8s);
                        break;

                    case EVENT_TELEPORT_24:
                        jaina->AI()->Talk(SAY_TELEPORT_14);
                        events.ScheduleEvent(EVENT_TELEPORT_25, 6s);
                        break;

                    case EVENT_TELEPORT_25:
                        jaina->AI()->Talk(SAY_TELEPORT_15);
                        events.ScheduleEvent(EVENT_TELEPORT_26, 2s);
                        break;

                    case EVENT_TELEPORT_26:
                        jaina->AI()->Talk(SAY_TELEPORT_16);
                        events.ScheduleEvent(EVENT_TELEPORT_27, 2s);
                        break;

                    case EVENT_TELEPORT_27:
                        jaina->GetMotionMaster()->MovePoint(0, -3671.56f, -4495.92f, 10.56f);
                        events.ScheduleEvent(EVENT_TELEPORT_28, 8s);
                        break;

                    case EVENT_TELEPORT_28:
                        rhonin->SetVisible(true);
                        rhonin->NearTeleportTo(-3741.20f, -4452.27f, 64.99f, 5.71f);
                        jaina->NearTeleportTo(-3747.51f, -4448.29f, 64.92f, 3.34f);
                        events.ScheduleEvent(EVENT_TELEPORT_29, 5s);
                        break;

                        // 52894 - zone anti magie
                    case EVENT_TELEPORT_29:
                        if (GameObject * portal = me->SummonGameObject(201797, -3749.90f, -4448.93f, 64.90f, 3.34f, QuaternionData(), 0))
                        {
                            portal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            rhonin->CastSpell(rhonin, 54219);
                            jaina->CastSpell(jaina, 23017);
                            jaina->AI()->SetData(EVENT_SET_END, 1U);
                        }
                        break;

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
        Creature* portal;
        Creature* currentSoldier;
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
