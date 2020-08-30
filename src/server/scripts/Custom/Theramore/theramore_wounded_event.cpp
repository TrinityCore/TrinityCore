#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "theramore.h"

#define AMARA_PATH_SIZE 24
#define AMARA_REVERSE_PATH_SIZE 6
#define JAINA_OUTRO_PATH_SIZE 19

enum Wounded
{
    // Events
	EVENT_START_TELEPORT	= 1,
    EVENT_START_AMARA       = 2,
    
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
	EVENT_TELEPORT_29,
	EVENT_TELEPORT_30
};

const Position AmaraPath[AMARA_PATH_SIZE]
{
    { -3658.76f, -4520.87f, 9.71f, 2.55f },
    { -3661.97f, -4519.87f, 9.85f, 3.14f },
    { -3664.97f, -4519.89f, 9.99f, 3.14f },
    { -3667.66f, -4519.76f, 10.02f, 2.99f },
    { -3669.91f, -4519.01f, 9.99f, 2.45f },
    { -3671.18f, -4517.12f, 10.01f, 1.91f },
    { -3671.49f, -4514.76f, 10.08f, 1.50f },
    { -3671.18f, -4512.43f, 10.14f, 1.50f },
    { -3671.00f, -4509.44f, 10.20f, 1.48f },
    { -3670.68f, -4506.46f, 10.26f, 1.42f },
    { -3670.24f, -4503.49f, 10.33f, 1.42f },
    { -3669.99f, -4500.50f, 10.43f, 1.57f },
    { -3670.19f, -4498.67f, 10.48f, 1.79f },
    { -3671.51f, -4495.55f, 10.57f, 2.10f },
    { -3672.28f, -4494.26f, 10.61f, 2.11f },
    { -3673.88f, -4491.72f, 10.74f, 2.15f },
    { -3675.52f, -4489.22f, 10.83f, 2.12f },
    { -3677.06f, -4486.64f, 10.94f, 2.07f },
    { -3678.38f, -4483.95f, 11.07f, 1.99f },
    { -3679.55f, -4481.19f, 11.22f, 1.93f },
    { -3680.46f, -4478.33f, 11.37f, 1.81f },
    { -3680.63f, -4476.05f, 11.45f, 1.49f },
    { -3679.94f, -4472.33f, 11.50f, 1.20f },
    { -3678.00f, -4468.27f, 11.47f, 1.09f }
};

const Position AmaraReversePath[AMARA_REVERSE_PATH_SIZE]
{
    { -3682.65f, -4478.18f, 11.52f, 5.30f },
    { -3680.38f, -4481.71f, 11.26f, 5.28f },
    { -3675.82f, -4488.77f, 10.85f, 5.28f },
    { -3671.61f, -4496.03f, 10.56f, 5.15f },
    { -3668.61f, -4505.48f, 10.26f, 4.91f },
    { -3668.04f, -4508.23f, 10.16f, 4.91f }
};

const Position JainaOutroPath[JAINA_OUTRO_PATH_SIZE]
{
    { -3665.92f, -4515.97f, 10.09f, 1.85f },
    { -3680.00f, -4473.11f, 11.49f, 1.27f },
    { -3680.50f, -4475.70f, 11.45f, 1.49f },
    { -3680.43f, -4478.10f, 11.37f, 1.66f },
    { -3679.93f, -4480.50f, 11.26f, 1.82f },
    { -3678.53f, -4484.02f, 11.07f, 2.00f },
    { -3677.87f, -4485.37f, 11.00f, 2.04f },
    { -3676.34f, -4487.95f, 10.89f, 2.16f },
    { -3674.57f, -4490.37f, 10.77f, 2.21f },
    { -3672.76f, -4492.76f, 10.68f, 2.21f },
    { -3671.06f, -4495.23f, 10.57f, 2.09f },
    { -3670.15f, -4497.28f, 10.51f, 1.89f },
    { -3669.90f, -4500.00f, 10.49f, 1.46f },
    { -3670.35f, -4502.97f, 10.34f, 1.40f },
    { -3670.78f, -4505.93f, 10.28f, 1.44f },
    { -3670.66f, -4509.95f, 10.17f, 1.79f },
    { -3670.04f, -4511.52f, 10.11f, 2.12f },
    { -3668.00f, -4513.85f, 10.06f, 2.37f },
    { -3665.84f, -4515.93f, 10.09f, 2.37f }
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
            switch (id)
            {
                case EVENT_START_TELEPORT:
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

                    if (Creature * kinndy = GetClosestCreatureWithEntry(me, NPC_KINNDY_SPARKSHINE, 40.f))
                        kinndy->GetMotionMaster()->MovePoint(0, -3656.46f, -4516.56f, 9.46f, true, 0.42f);

                    if (Creature* helaina = GetClosestCreatureWithEntry(me, NPC_DOCTOR_HELAINA, 40.f))
                    {
                        helaina->SetWalk(true);
                        helaina->GetMotionMaster()->MovePoint(0, -3651.05f, -4503.82f, 9.46f, true, 5.67f);
                    }

                    events.ScheduleEvent(EVENT_TELEPORT_1, 1s);
                    break;
                }

                case EVENT_START_AMARA:
                    jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 20.f);
                    rhonin = GetClosestCreatureWithEntry(me, NPC_RHONIN, 40.f);
                    amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 2000.f);
                    jaina->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    events.ScheduleEvent(EVENT_TELEPORT_21, 1s);
                    break;
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
                    // Event - Retour de Kalecgos
                    #pragma region KALECGOS

                    case EVENT_TELEPORT_1:
                    {
                        if (Creature * soldier = jaina->FindNearestCreature(NPC_WOUNDED_THERAMORE_GUARD, 15.f))
                        {
                            currentSoldier = soldier;
                            jaina->GetMotionMaster()->MoveCloserAndStop(0, soldier, 1.5f);
                            events.ScheduleEvent(EVENT_TELEPORT_2, Milliseconds((uint64)jaina->GetMotionMaster()->GetTime() + 500));
                        }
                        else
                            events.ScheduleEvent(EVENT_TELEPORT_5, 1s);

                        break;
                    }

                    case EVENT_TELEPORT_2:
                        jaina->CastSpell(jaina, SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_3, 1300ms);
                        break;

                    case EVENT_TELEPORT_3:
                        currentSoldier->CastSpell(currentSoldier, SPELL_TELEPORT);
                        events.ScheduleEvent(EVENT_TELEPORT_4, 1500ms);
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
                        if (Creature* p = DoSummon(NPC_INVISIBLE_STALKER, { -3679.66f, -4481.86f, 11.20f, 5.30f }, 0s, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            portal = p;
                            p->SetObjectScale(1.5f);
                            p->AddAura(SPELL_PORTAL, p);
                            kalecgos = DoSummon(NPC_KALECGOS, { -3679.84f, -4481.61f, 16.64f, 5.27f }, 0s, TEMPSUMMON_MANUAL_DESPAWN);
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
                        amara->GetMotionMaster()->MoveSmoothPath(0, AmaraPath, AMARA_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_TELEPORT_16, 2s);
                        break;

                    case EVENT_TELEPORT_16:
                        jaina->SetFacingToObject(kalecgos);
                        events.ScheduleEvent(EVENT_TELEPORT_17, 2s);
                        break;

                    case EVENT_TELEPORT_17:
                        jaina->AI()->Talk(SAY_TELEPORT_11);
                        events.ScheduleEvent(EVENT_TELEPORT_18, 2s);
                        break;

                    case EVENT_TELEPORT_18:
                        kalecgos->AI()->Talk(SAY_TELEPORT_12);
                        events.ScheduleEvent(EVENT_TELEPORT_19, 10s);
                        break;

                    case EVENT_TELEPORT_19:
                        amara->SetVisible(false);
                        jaina->SetFacingTo(2.05f);
                        kalecgos->GetMotionMaster()->MovePoint(0, -3676.04f, -4487.67f, 10.88f, true, 2.15f);
                        events.ScheduleEvent(EVENT_TELEPORT_20, 5s);
                        break;

                    case EVENT_TELEPORT_20:
                        kalecgos->GetMotionMaster()->MoveJump(-3679.84f, -4481.61f, 16.64f, 5.27f, 10.4f, 6.5f);
                        portal->DespawnOrUnsummon(4s);
                        kalecgos->DespawnOrUnsummon(1s);
                        jaina->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;

                    #pragma endregion

                    // Event - Retour de Rhonin
                    #pragma region RHONIN

                    case EVENT_TELEPORT_21:
                        amara->SetVisible(true);
                        amara->GetMotionMaster()->Clear();
                        amara->GetMotionMaster()->MoveIdle();
                        amara->NearTeleportTo(AmaraReversePath[0]);
                        amara->GetMotionMaster()->MoveSmoothPath(0, AmaraReversePath, AMARA_REVERSE_PATH_SIZE, false);
                        events.ScheduleEvent(EVENT_TELEPORT_22, 6s);
                        break;

                    case EVENT_TELEPORT_22:
                        amara->SetFacingToObject(jaina);
                        jaina->SetFacingToObject(amara);
                        events.ScheduleEvent(EVENT_TELEPORT_23, 1s);
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
                        jaina->GetMotionMaster()->MoveSmoothPath(0, JainaOutroPath, JAINA_OUTRO_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_TELEPORT_28, 16s);
                        break;

                    case EVENT_TELEPORT_28:
                        jaina->SetVisible(false);
                        rhonin->SetVisible(true);
                        rhonin->NearTeleportTo(-3741.20f, -4452.27f, 64.99f, 5.71f);
                        events.ScheduleEvent(EVENT_TELEPORT_29, 2s);
                        break;

                    case EVENT_TELEPORT_29:
                        jaina->NearTeleportTo(-3747.51f, -4448.29f, 64.92f, 3.34f);
                        events.ScheduleEvent(EVENT_TELEPORT_30, 1s);
                        break;

                    case EVENT_TELEPORT_30:
                        if (GameObject * portal = me->SummonGameObject(201797, -3749.90f, -4448.93f, 64.90f, 3.34f, QuaternionData(), 0s))
                        {
                            portal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            rhonin->CastSpell(rhonin, 54219);
                            jaina->SetVisible(true);
                            jaina->CastSpell(jaina, 23017);
                            jaina->AI()->SetData(EVENT_SET_END, 1U);
                        }
                        break;

                    #pragma endregion

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
