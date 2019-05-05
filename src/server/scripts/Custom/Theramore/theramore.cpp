#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "theramore.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Weather.h"
#include "GridNotifiersImpl.h"
#include <iostream>

constexpr int TERVOSH_PATH_SIZE     = 8;
constexpr int KINNDY_PATH_SIZE      = 6;
constexpr int ADEN_PATH_SIZE        = 7;
constexpr int JAINA_PATH_SIZE       = 14;
constexpr int JAINA_PATH_1_SIZE     = 43;

Position TervoshPath[TERVOSH_PATH_SIZE]
{
    { -3747.68f, -4442.04f, 30.55f, 2.19f },
    { -3743.27f, -4439.73f, 30.55f, 5.04f },
    { -3742.35f, -4450.20f, 32.38f, 4.53f },
    { -3744.46f, -4453.00f, 33.65f, 4.02f },
    { -3747.94f, -4455.76f, 35.21f, 3.64f },
    { -3751.50f, -4456.92f, 36.55f, 3.45f },
    { -3755.51f, -4456.95f, 37.98f, 3.05f },
    { -3759.44f, -4455.61f, 37.99f, 2.33f }
};

Position KinndyPath[KINNDY_PATH_SIZE]
{
    { -3746.47f, -4441.14f, 30.55f, 2.67f },
    { -3747.43f, -4435.41f, 30.55f, 2.24f },
    { -3754.94f, -4432.40f, 32.24f, 3.12f },
    { -3759.19f, -4433.18f, 33.75f, 3.79f },
    { -3762.79f, -4435.95f, 35.21f, 3.79f },
    { -3764.64f, -4438.99f, 35.21f, 0.67f }
};

Position const AdenPath[ADEN_PATH_SIZE]
{
    { -3717.79f, -4522.24f, 25.82f, 5.16f },
    { -3714.91f, -4528.24f, 25.82f, 5.16f },
    { -3713.09f, -4532.02f, 25.82f, 5.16f },
    { -3711.22f, -4535.91f, 25.82f, 5.16f },
    { -3710.03f, -4538.38f, 25.82f, 5.16f },
    { -3712.85f, -4539.80f, 25.82f, 3.60f },
    { -3716.85f, -4541.81f, 25.82f, 3.60f }
};

Position const JainaPostBattlePath[JAINA_PATH_SIZE]
{
    { -3669.20f, -4380.69f,  9.51f, 3.89f },
    { -3672.86f, -4393.39f, 10.60f, 4.71f },
    { -3672.87f, -4398.85f, 10.64f, 4.71f },
    { -3672.87f, -4403.85f, 10.68f, 4.71f },
    { -3672.87f, -4407.60f, 10.64f, 4.71f },
    { -3671.40f, -4411.18f, 10.61f, 0.79f },
    { -3668.17f, -4412.39f, 10.73f, 6.16f },
    { -3662.70f, -4413.18f, 10.67f, 6.17f },
    { -3657.73f, -4413.71f, 10.48f, 6.17f },
    { -3652.12f, -4413.99f, 10.25f, 6.18f },
    { -3647.20f, -4414.85f, 10.06f, 5.99f },
    { -3642.43f, -4416.33f,  9.88f, 5.96f },
    { -3637.79f, -4418.19f,  9.71f, 5.79f },
    { -3633.32f, -4420.42f,  9.69f, 5.82f }
};

Position const JainaWoundedPath[JAINA_PATH_1_SIZE]
{
    { -3637.05f, -4416.78f,  9.67f, 0.21f },
    { -3640.47f, -4416.59f,  9.80f, 6.04f },
    { -3642.88f, -4415.93f,  9.89f, 6.02f },
    { -3645.31f, -4415.34f, 10.00f, 6.07f },
    { -3649.00f, -4414.67f, 10.13f, 6.10f },
    { -3652.70f, -4414.02f, 10.27f, 6.10f },
    { -3655.16f, -4413.59f, 10.38f, 6.10f },
    { -3658.86f, -4413.01f, 10.52f, 6.16f },
    { -3661.35f, -4412.73f, 10.61f, 6.18f },
    { -3665.09f, -4412.54f, 10.75f, 6.28f },
    { -3667.37f, -4412.95f, 10.82f, 0.32f },
    { -3669.74f, -4414.60f, 10.86f, 0.84f },
    { -3671.13f, -4417.32f, 11.03f, 1.24f },
    { -3671.80f, -4420.67f, 11.11f, 1.43f },
    { -3672.18f, -4424.40f, 11.18f, 1.52f },
    { -3672.29f, -4426.90f, 11.22f, 1.52f },
    { -3672.46f, -4430.64f, 11.28f, 1.52f },
    { -3672.57f, -4433.14f, 11.35f, 1.52f },
    { -3672.74f, -4436.89f, 11.35f, 1.52f },
    { -3672.85f, -4439.38f, 11.36f, 1.52f },
    { -3673.02f, -4443.13f, 11.38f, 1.52f },
    { -3673.18f, -4446.88f, 11.39f, 1.52f },
    { -3673.35f, -4450.62f, 11.40f, 1.52f },
    { -3673.52f, -4454.37f, 11.42f, 1.52f },
    { -3673.83f, -4458.10f, 11.36f, 1.43f },
    { -3674.56f, -4461.78f, 11.35f, 1.32f },
    { -3675.83f, -4465.16f, 11.41f, 1.05f },
    { -3677.86f, -4468.11f, 11.46f, 0.94f },
    { -3680.00f, -4471.19f, 11.54f, 1.01f },
    { -3681.56f, -4474.36f, 11.56f, 1.25f },
    { -3681.85f, -4477.52f, 11.48f, 1.66f },
    { -3680.67f, -4480.93f, 11.30f, 2.04f },
    { -3678.74f, -4484.14f, 11.08f, 2.14f },
    { -3676.05f, -4488.35f, 10.87f, 2.13f },
    { -3673.41f, -4492.59f, 10.69f, 2.11f },
    { -3671.56f, -4495.86f, 10.56f, 2.02f },
    { -3670.55f, -4500.86f, 10.40f, 1.69f },
    { -3670.10f, -4504.58f, 10.30f, 1.69f },
    { -3669.46f, -4509.53f, 10.15f, 1.81f },
    { -3668.26f, -4511.59f, 10.09f, 2.44f },
    { -3665.60f, -4512.60f, 10.03f, 2.97f },
    { -3663.23f, -4512.82f, 9.977f, 3.07f },
    { -3655.96f, -4513.32f, 9.463f, 3.07f }
};

class npc_jaina_theramore : public CreatureScript
{
    public:
    npc_jaina_theramore() : CreatureScript("npc_jaina_theramore") {}

    struct npc_jaina_theramoreAI : public ScriptedAI
    {
        npc_jaina_theramoreAI(Creature* creature) : ScriptedAI(creature)
        {
            sayInCombatTimer = 0;
            fireballTimer = 0;
            blizzardTimer = 0;
            playerShaker = false;
            firesCount = 0;
            npcCount = 0;
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LOOKING_FOR_THE_ARTEFACT:
                    SetData(EVENT_START_CONVO, 0);
                    break;

                case QUEST_EVACUATION:
                    SetData(EVENT_START_EVACUATION, 0);
                    break;

                case QUEST_PREPARE_FOR_WAR:
                    SetData(EVENT_START_BATTLE, 0);
                    break;
            }
        }

        void QuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LOOKING_FOR_THE_ARTEFACT:
                    SetData(EVENT_END_CONVO, 0);
                    break;

                case QUEST_PREPARE_FOR_WAR:
                    SetData(EVENT_START_POST_BATTLE, 0);
                    break;
            }
        }

        void SetData(uint32 id, uint32 value) override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetSheath(SHEATH_STATE_UNARMED);

            if (!players.empty())
                players.clear();

            Map::PlayerList const& allPlayers = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = allPlayers.begin(); itr != allPlayers.end(); ++itr)
            {
                if (Player * player = itr->GetSource()->ToPlayer())
                    players.push_back(player);
            }

            switch (id)
            {
                case EVENT_START_CONVO:
                    kalecgos = me->FindNearestCreature(NPC_KALECGOS, 15.f);
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    kinndy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    me->PlayDirectSound(28096);
                    events.SetPhase(PHASE_CONVO);
                    events.ScheduleEvent(EVENT_CONVO_1, 2s, 0, PHASE_CONVO);

                    break;

                case EVENT_END_CONVO:
                    events.ScheduleEvent(EVENT_CONVO_25, 2s, 0, PHASE_CONVO);
                    break;

                case EVENT_START_POST_BATTLE:
                {
                    for (Player* player : players)
                        player->SetPhaseMask(3, true);

                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 2000.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 2000.f);
                    kalecgos = me->FindNearestCreature(NPC_KALECGOS, 2000.f);
                    aden = me->FindNearestCreature(NPC_LIEUTENANT_ADEN, 2000.f);

                    me->SetPhaseMask(3, true);
                    tervosh->SetPhaseMask(3, true);
                    kinndy->SetPhaseMask(3, true);
                    kalecgos->SetPhaseMask(3, true);
                    aden->SetPhaseMask(3, true);
                    kinndy->NearTeleportTo(-3637.63f, -4408.91f, 9.79f, 4.84f);
                    kinndy->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_CRY);

                    std::vector<GameObject*> fires;
                    GetGameObjectListWithEntryInGrid(fires, me, GOB_FIRE_THERAMORE, 5000.f);
                    for (GameObject* fire : fires)
                        fire->Delete();

                    events.SetPhase(PHASE_POST_BATTLE);
                    events.ScheduleEvent(EVENT_POST_BATTLE_1, 2s, 0, PHASE_POST_BATTLE);
                    break;
                }

                case EVENT_START_EVACUATION:
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    kalecgos = me->FindNearestCreature(NPC_KALECGOS, 2000.f);
                    aden = me->FindNearestCreature(NPC_LIEUTENANT_ADEN, 2000.f);
                    events.ScheduleEvent(EVENT_EVACUATION_1, value ? value : 60000, 0, PHASE_CONVO);
                    break;

                case EVENT_START_WARN:
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    kinndy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    events.SetPhase(PHASE_WARN);
                    events.ScheduleEvent(EVENT_WARN_1, 2s, 0, PHASE_WARN);
                    break;

                case EVENT_START_BATTLE:
                {
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    aden = me->FindNearestCreature(NPC_LIEUTENANT_ADEN, 2000.f);

                    kinndy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                    // First get all creatures.
                    Trinity::AllFriendlyCreaturesInGrid creature_check(me);
                    Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(me, civils, creature_check);
                    Cell::VisitGridObjects(me, creature_searcher, 2000.f);

                    me->SetWalk(false);
                    tervosh->SetWalk(false);
                    kinndy->SetWalk(false);

                    events.SetPhase(PHASE_PRE_BATTLE);
                    events.ScheduleEvent(EVENT_SHAKER, 2s, 0, PHASE_PRE_BATTLE);
                    events.ScheduleEvent(EVENT_PRE_BATTLE_1, 2s, 0, PHASE_PRE_BATTLE);
                    break;
                }
            }
        }

        void Reset() override
        {
            me->RemoveAllAuras();

            sayInCombatTimer = 8000;
            fireballTimer = 1;
            blizzardTimer = urand(3500, 5000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Event - Convo
                    #pragma region EVENT_CONVO

                    // Début de la réunion
                    case EVENT_CONVO_1:
                        Talk(SAY_CONVO_1);
                        events.ScheduleEvent(EVENT_CONVO_2, 11s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_2:
                        kinndy->AI()->Talk(SAY_CONVO_2);
                        events.ScheduleEvent(EVENT_CONVO_3, 10s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_3:
                        Talk(SAY_CONVO_3);
                        events.ScheduleEvent(EVENT_CONVO_4, 12s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_4:
                        kinndy->AI()->Talk(SAY_CONVO_4);
                        events.ScheduleEvent(EVENT_CONVO_5, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_5:
                        Talk(SAY_CONVO_5);
                        events.ScheduleEvent(EVENT_CONVO_6, 8s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_6:
                        tervosh->AI()->Talk(SAY_CONVO_6);
                        events.ScheduleEvent(EVENT_CONVO_7, 8s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_7:
                        kalecgos->AI()->Talk(SAY_CONVO_7);
                        events.ScheduleEvent(EVENT_CONVO_8, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_8:
                        kalecgos->AI()->Talk(SAY_CONVO_8);
                        events.ScheduleEvent(EVENT_CONVO_9, 9s, 0, PHASE_CONVO);
                        events.ScheduleEvent(EVENT_CONVO_10, 10s, 0, PHASE_CONVO);
                        events.ScheduleEvent(EVENT_CONVO_11, 14s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_9:
                        kinndy->AI()->Talk(SAY_CONVO_9_BIS);
                        break;

                    case EVENT_CONVO_10:
                        tervosh->AI()->Talk(SAY_CONVO_9);
                        break;

                    case EVENT_CONVO_11:
                        Talk(SAY_CONVO_10);
                        events.ScheduleEvent(EVENT_CONVO_12, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_12:
                        kalecgos->AI()->Talk(SAY_CONVO_11);
                        events.ScheduleEvent(EVENT_CONVO_13, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_13:
                        Talk(SAY_CONVO_12);
                        events.ScheduleEvent(EVENT_CONVO_14, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_14:
                        kinndy->AI()->Talk(SAY_CONVO_13);
                        events.ScheduleEvent(EVENT_CONVO_15, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_15:
                        kalecgos->AI()->Talk(SAY_CONVO_14);
                        events.ScheduleEvent(EVENT_CONVO_16, 7s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_16:
                        Talk(SAY_CONVO_15);
                        events.ScheduleEvent(EVENT_CONVO_17, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_17:
                        kalecgos->AI()->Talk(SAY_CONVO_16);
                        events.ScheduleEvent(EVENT_CONVO_18, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_18:
                        kalecgos->AI()->Talk(SAY_CONVO_17);
                        kalecgos->SetWalk(true);
                        events.ScheduleEvent(EVENT_CONVO_19, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_19:
                        kalecgos->GetMotionMaster()->MovePoint(1, -3746.48f, -4437.71f, 30.55f, false);
                        events.ScheduleEvent(EVENT_CONVO_20, 2s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_20:
                        kalecgos->GetMotionMaster()->MovePoint(2, -3717.99f, -4411.30f, 24.37f, false);
                        events.ScheduleEvent(EVENT_CONVO_21, 18s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_21:
                        kalecgos->SetVisible(false);
                        kalecgos = me->SummonCreature(NPC_KALECGOS_DRAGON, kalecgos->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                        kalecgos->SetWalk(false);
                        kalecgos->SetDisableGravity(true);
                        kalecgos->SetFacingTo(5.99f);
                        events.ScheduleEvent(EVENT_CONVO_22, 2s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_22:
                        kalecgos->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        kalecgos->UpdatePosition({ kalecgos->GetPositionX(), kalecgos->GetPositionY(), kalecgos->GetPositionZ() + 30.0f, me->GetOrientation() });
                        events.ScheduleEvent(EVENT_CONVO_23, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_23:
                        kalecgos->GetMotionMaster()->MovePoint(4, -3546.51f, -4352.54f, 74.02f, false);
                        tervosh->GetMotionMaster()->MoveSmoothPath(0, TervoshPath, TERVOSH_PATH_SIZE, true);
                        kinndy->GetMotionMaster()->MoveSmoothPath(0, KinndyPath, KINNDY_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_CONVO_24, 16s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_24:
                    {
                        for (Player* player : players)
                            player->AreaExploredOrEventHappens(QUEST_LOOKING_FOR_THE_ARTEFACT);

                        kinndy->SetFacingTo(0.62f);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        kalecgos->DespawnOrUnsummon();
                        tervosh->SetVisible(false);
                        break;
                    }

                    // Fin de la réunion
                    case EVENT_CONVO_25:
                    {
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, -3759.73f, -4446.66f, 30.55f, true, 0.38f);
                        events.ScheduleEvent(EVENT_CONVO_26, 15s, 0, PHASE_CONVO);
                        break;
                    }

                    case EVENT_CONVO_26:
                        SetData(EVENT_START_WARN, 0);
                        break;

                        #pragma endregion

                    // Event - Warn
                    #pragma region EVENT_WARN

                    case EVENT_WARN_1:
                    {
                        if (npcCount >= 4)
                        {
                            events.ScheduleEvent(EVENT_WARN_2, 3s, 0, PHASE_WARN);
                            break;
                        }

                        uint32 entry = (uint32)WarnLocation[npcCount][0];
                        if (Creature * c = me->SummonCreature(entry, WarnLocation[npcCount][1], WarnLocation[npcCount][2], WarnLocation[npcCount][3], WarnLocation[npcCount][4], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            switch (entry)
                            {
                                case NPC_PAINED:
                                    c->SetSheath(SHEATH_STATE_UNARMED);
                                    pained = c;
                                    break;

                                case NPC_MYSTERIOUS_TAUREN:
                                    perith = c;
                                    break;

                                case NPC_ZEALOUS_THERAMORE_GUARD:
                                    zealous = c;
                                    break;

                                case NPC_THERAMORE_GUARD:
                                    guard = c;
                                    break;
                            }

                            c->SetWalk(true);
                            c->GetMotionMaster()->MovePoint(0, WarnDestination[npcCount], false, WarnDestination[npcCount].GetOrientation());

                            npcCount++;

                            events.ScheduleEvent(EVENT_WARN_1, 1s, 0, PHASE_WARN);
                        }

                        break;
                    }

                    case EVENT_WARN_2:
                        pained->AI()->Talk(SAY_WARN_1);
                        pained->SetFacingTo(3.64f);
                        events.ScheduleEvent(EVENT_WARN_3, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_3:
                        Talk(SAY_WARN_2);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->GetMotionMaster()->MovePoint(0, -3750.87f, -4439.72f, 30.55f, true, 0.58f);
                        events.ScheduleEvent(EVENT_WARN_4, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_4:
                        pained->AI()->Talk(SAY_WARN_3);
                        events.ScheduleEvent(EVENT_WARN_5, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_5:
                        pained->AI()->Talk(SAY_WARN_4);
                        events.ScheduleEvent(EVENT_WARN_6, 7s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_6:
                        Talk(SAY_WARN_5);
                        events.ScheduleEvent(EVENT_WARN_7, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_7:
                        pained->AI()->Talk(SAY_WARN_6);
                        events.ScheduleEvent(EVENT_WARN_8, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_8:
                        pained->GetMotionMaster()->MoveCloserAndStop(0, me, 1.0f);
                        events.ScheduleEvent(EVENT_WARN_9, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_9:
                        pained->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_10, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_10:
                        pained->AI()->Talk(SAY_WARN_7);
                        pained->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_WARN_11, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_11:
                        pained->SetTarget(ObjectGuid::Empty);
                        pained->GetMotionMaster()->MovePoint(0, -3746.31f, -4433.00f, 30.55f, false, 4.23f);
                        events.ScheduleEvent(EVENT_WARN_12, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_12:
                        Talk(SAY_WARN_8);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_13, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_13:
                        Talk(SAY_WARN_9);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->SetFacingToObject(perith);
                        events.ScheduleEvent(EVENT_WARN_14, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_14:
                        pained->AI()->Talk(SAY_WARN_10);
                        perith->GetMotionMaster()->MovePoint(0, -3747.11f, -4438.24f, 30.55f, false, 3.94f);
                        events.ScheduleEvent(EVENT_WARN_15, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_15:
                        Talk(SAY_WARN_11);
                        events.ScheduleEvent(EVENT_WARN_16, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_16:
                        me->SetFacingToObject(zealous);
                        perith->SetFacingToObject(me);
                        zealous->AI()->Talk(0);
                        zealous->GetMotionMaster()->MovePoint(0, -3743.01f, -4433.78f, 30.55f, false, 3.93f);
                        events.ScheduleEvent(EVENT_WARN_17, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_17:
                        Talk(SAY_WARN_13);
                        events.ScheduleEvent(EVENT_WARN_18, 7s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_18:
                        zealous->GetMotionMaster()->MovePoint(0, -3731.17f, -4420.68f, 30.44f, false);
                        guard->GetMotionMaster()->MovePoint(0, -3729.32f, -4422.18f, 30.44f, false);
                        me->SetFacingToObject(perith);
                        perith->UpdateEntry(NPC_PERITH_STORMHOOF);
                        perith->AI()->Talk(SAY_WARN_14);
                        events.ScheduleEvent(EVENT_WARN_19, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_19:
                        Talk(SAY_WARN_15);
                        zealous->DespawnOrUnsummon();
                        guard->DespawnOrUnsummon();
                        events.ScheduleEvent(EVENT_WARN_20, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_20:
                        perith->AI()->Talk(SAY_WARN_16);
                        events.ScheduleEvent(EVENT_WARN_21, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_21:
                        perith->AI()->Talk(SAY_WARN_17);
                        events.ScheduleEvent(EVENT_WARN_22, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_22:
                        perith->AI()->Talk(SAY_WARN_18);
                        events.ScheduleEvent(EVENT_WARN_23, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_23:
                        Talk(SAY_WARN_19);
                        events.ScheduleEvent(EVENT_WARN_24, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_24:
                        perith->AI()->Talk(SAY_WARN_20);
                        events.ScheduleEvent(EVENT_WARN_25, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_25:
                        Talk(SAY_WARN_21);
                        events.ScheduleEvent(EVENT_WARN_26, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_26:
                        perith->AI()->Talk(SAY_WARN_22);
                        events.ScheduleEvent(EVENT_WARN_27, 12s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_27:
                        perith->AI()->Talk(SAY_WARN_23);
                        events.ScheduleEvent(EVENT_WARN_28, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_28:
                        Talk(SAY_WARN_24);
                        events.ScheduleEvent(EVENT_WARN_29, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_29:
                        perith->AI()->Talk(SAY_WARN_25);
                        events.ScheduleEvent(EVENT_WARN_30, 11s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_30:
                        Talk(SAY_WARN_26);
                        me->SetWalk(true);
                        events.ScheduleEvent(EVENT_WARN_31, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_31:
                        me->GetMotionMaster()->MovePoint(0, -3756.04f, -4437.71f, 30.55f, false, 2.08f);
                        events.ScheduleEvent(EVENT_WARN_32, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_32:
                        Talk(SAY_WARN_27);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_33, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_33:
                        Talk(SAY_WARN_28);
                        me->GetMotionMaster()->MovePoint(0, -3750.87f, -4439.72f, 30.55f, false, 0.97f);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_WARN_34, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_34:
                        me->SetFacingToObject(perith);
                        perith->AI()->Talk(SAY_WARN_29);
                        events.ScheduleEvent(EVENT_WARN_35, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_35:
                        perith->AI()->Talk(SAY_WARN_30);
                        events.ScheduleEvent(EVENT_WARN_36, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_36:
                        Talk(SAY_WARN_31);
                        events.ScheduleEvent(EVENT_WARN_37, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_37:
                        perith->AI()->Talk(SAY_WARN_32);
                        events.ScheduleEvent(EVENT_WARN_38, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_38:
                        Talk(SAY_WARN_33);
                        events.ScheduleEvent(EVENT_WARN_39, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_39:
                        perith->AI()->Talk(SAY_WARN_34);
                        events.ScheduleEvent(EVENT_WARN_40, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_40:
                        perith->GetMotionMaster()->MovePoint(0, -3731.33f, -4422.18f, 30.47f);
                        events.ScheduleEvent(EVENT_WARN_41, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_41:
                        perith->DespawnOrUnsummon();
                        me->SetFacingToObject(pained);
                        Talk(SAY_WARN_35);
                        events.ScheduleEvent(EVENT_WARN_42, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_42:
                        pained->GetMotionMaster()->MoveCloserAndStop(0, me, 4.0f);
                        pained->AI()->Talk(SAY_WARN_36);
                        events.ScheduleEvent(EVENT_WARN_43, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_43:
                        Talk(SAY_WARN_37);
                        events.ScheduleEvent(EVENT_WARN_44, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_44:
                        pained->GetMotionMaster()->MoveSmoothPath(0, TervoshPath, TERVOSH_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_WARN_45, 16s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_45:

                        // Reverse path points
                        reverse(TervoshPath, TERVOSH_PATH_SIZE);
                        reverse(KinndyPath, KINNDY_PATH_SIZE);

                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFacingTo(6.26f);
                        tervosh->SetVisible(true);
                        tervosh->GetMotionMaster()->MoveSmoothPath(0, TervoshPath, TERVOSH_PATH_SIZE, true);
                        kinndy->GetMotionMaster()->MoveSmoothPath(0, KinndyPath, KINNDY_PATH_SIZE, true);
                        kinndy->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        events.ScheduleEvent(EVENT_WARN_46, 16s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_46:
                        me->SetFacingTo(0.60f);
                        tervosh->SetFacingTo(1.05f);
                        kinndy->SetFacingTo(1.05f);
                        break;

                    #pragma endregion

                    // Event - Evacuation
                    case EVENT_EVACUATION_1:
                        kalecgos = GetClosestCreatureWithEntry(me, NPC_KALECGOS, 100.f);
                        kalecgos->SetVisible(true);
                        kalecgos->NearTeleportTo(-3724.90f, -4547.24f, 25.82f, 0.51f);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->NearTeleportTo(-3725.09f, -4545.75f, 25.82f, 0.53f);
                        kinndy->NearTeleportTo(-3726.27f, -4543.99f, 25.82f, 0.47f);
                        tervosh->NearTeleportTo(-3723.67f, -4548.69f, 25.82f, 0.94f);
                        break;

                    // Event - Pre Battle
                    #pragma region EVENT_PRE_BATTLE

                    case EVENT_SHAKER:
                    {
                        if (!playerShaker)
                        {
                            for (Player* player : players)
                                player->CastSpell(player, 42910);

                            aden->AI()->Talk(SAY_EVENT_SHAKER);

                            std::list<GameObject*> theramoreGates;
                            GetGameObjectListWithEntryInGrid(theramoreGates, me, GOB_THERAMORE_GATE, 2000.f);
                            for (GameObject* gate : theramoreGates)
                                gate->UseDoorOrButton();

                            playerShaker = true;
                        }

                        uint32 sound = RAND(14340, 14341, 14338);
                        me->PlayDirectSound(sound);
                        events.ScheduleEvent(EVENT_SHAKER, urand(500, 1000), 0, PHASE_CONVO);
                        break;
                    }

                    case EVENT_PRE_BATTLE_1:
                    {
                        for (int i = 0; i < 35; ++i)
                        {
                            me->SummonGameObject(GOB_FIRE_THERAMORE, FireLocation[i][0], FireLocation[i][1], FireLocation[i][2], FireLocation[i][3], QuaternionData(), 0);
                            if (Creature * fx = me->SummonCreature(NPC_INVISIBLE_STALKER, FireLocation[i][0], FireLocation[i][1], FireLocation[i][2], 0.f, TEMPSUMMON_TIMED_DESPAWN, 5000))
                                fx->CastSpell(fx, 70444);
                        }

                        for (Creature* civil : civils)
                        {
                            switch (civil->GetEntry())
                            {
                                case 4901:
                                case 4902:
                                case 6732:
                                case 100025:
                                case 100027:
                                case 100028:
                                    civil->SetVisible(false);
                                    break;

                                case 100012:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                                    if (civil->GetSpawnId() == 1022705 || civil->GetSpawnId() == 1022704)
                                    {
                                        civil->SetVisible(false);
                                        civil->StopMoving();
                                        civil->GetMotionMaster()->MoveIdle();
                                    }
                                    break;

                                case 34776:
                                    if (civil->GetSpawnId() == 1022775)
                                    {
                                        civil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        civil->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                                        civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                                        civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM);
                                    }
                                    break;

                                case 4941:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    break;

                                case 4899:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3698.03f, -4353.46f, 11.45f, true, 1.78f);
                                    break;

                                case 4900:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3699.53f, -4356.35f, 11.41f, true, 1.78f);
                                    break;

                                case 4898:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3700.21f, -4351.08f, 11.41f, true, 1.86f);
                                    break;

                                case 4897:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3824.76f, -4443.74f, 12.66f, true, 3.24f);
                                    break;

                                case 11052:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3826.36f, -4441.66f, 12.25f, true, 3.51f);
                                    break;

                                case 4885:
                                case 4888:
                                case 5405:
                                case 10047:
                                case 12375:
                                case 12376:
                                case 24005:
                                case 24006:
                                case 24007:
                                    civil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    civil->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                                    civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                                    civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM);
                                    break;

                                case 4886:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                                    if (Creature * c = civil->FindNearestCreature(4888, 18.f))
                                    {
                                        civil->GetMotionMaster()->MoveFollow(c, 1.0f, 0.f);
                                        civil->SetTarget(c->GetGUID());
                                    }
                                    break;
                            }
                        }

                        me->PlayDirectSound(15003);
                        me->GetMap()->SetZoneWeather(ZONE_THERAMORE_ISLE, WEATHER_STATE_FOG, 1.0f);
                        aden->Dismount();
                        aden->NearTeleportTo(-3717.79f, -4522.24f, 25.82f, 5.16f);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_2, 1s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_2:
                        Talk(SAY_PRE_BATTLE_1);
                        aden->GetMotionMaster()->MoveSmoothPath(0, AdenPath, ADEN_PATH_SIZE, false);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_3, 3s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_3:
                        events.CancelEvent(EVENT_SHAKER);
                        aden->AI()->Talk(SAY_PRE_BATTLE_2);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_4, 4s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_4:
                        Talk(SAY_PRE_BATTLE_3);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_5, 3s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_5:
                    {
                        aden->SetWalk(true);
                        aden->GetMotionMaster()->MovePoint(0, -3721.23f, -4549.68f, 25.82f, true, 1.32f);
                        if (GameObject * portal = me->SummonGameObject(201797, PortalPosition, QuaternionData(), 13))
                        {
                            me->SetFacingToObject(portal);
                            portal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        events.ScheduleEvent(EVENT_PRE_BATTLE_6, 800, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_6:
                    {
                        if (npcCount >= 6)
                        {
                            events.ScheduleEvent(EVENT_PRE_BATTLE_7, 1s, 0, PHASE_PRE_BATTLE);
                            break;
                        }

                        uint32 entry = (uint32)ArchmagesLocation[npcCount][0];
                        if (Creature * c = me->SummonCreature(entry, PortalPosition, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            switch (entry)
                            {
                                case NPC_RHONIN:
                                    rhonin = c;
                                    c->AI()->Talk(SAY_PRE_BATTLE_4);
                                    me->SetFacingToObject(c);
                                    kinndy->SetFacingToObject(c);
                                    tervosh->SetFacingToObject(c);
                                    break;

                                case NPC_THALEN_SONGWEAVER:
                                    thalen = c;
                                    break;

                                case NPC_VEREESA_WINDRUNNER:
                                    vereesa = c;
                                    break;

                                default:
                                    break;
                            }

                            archmagesGUID[npcCount] = c->GetGUID();
                            c->SetWalk(true);
                            c->GetMotionMaster()->MovePoint(0, ArchmagesLocation[npcCount][1], ArchmagesLocation[npcCount][2], ArchmagesLocation[npcCount][3], true, ArchmagesLocation[npcCount][4]);
                            c->SetSheath(SHEATH_STATE_UNARMED);
                            c->CastSpell(c, SPELL_TELEPORT);
                            c->SetTarget(me->GetGUID());
                        }

                        npcCount++;
                        events.RescheduleEvent(EVENT_PRE_BATTLE_6, 800ms, 1180ms, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_7:
                        Talk(SAY_PRE_BATTLE_5);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_8, 11s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_8:
                        Talk(SAY_PRE_BATTLE_6);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_9, 9s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_9:
                        thalen->AI()->Talk(SAY_PRE_BATTLE_7);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_10, 7s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_10:
                        Talk(SAY_PRE_BATTLE_8);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_11, 3s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_11:
                        Talk(SAY_PRE_BATTLE_9);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_12, 7s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_12:
                        rhonin->AI()->Talk(SAY_PRE_BATTLE_10);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_13, 2s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_13:
                        Talk(SAY_PRE_BATTLE_11);
                        me->SetFacingToObject(tervosh);
                        tervosh->SetFacingToObject(me);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_14, 5s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_14:
                        vereesa->AI()->Talk(SAY_PRE_BATTLE_12);
                        me->SetFacingToObject(vereesa);
                        tervosh->SetFacingToObject(vereesa);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_15, 5s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_15:
                        Talk(SAY_PRE_BATTLE_13);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_16, 8s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_16:
                        vereesa->CastSpell(vereesa, SPELL_VANISH);
                        if (Player * player = me->SelectNearestPlayer(50.f))
                        {
                            Talk(SAY_PRE_BATTLE_14);
                            me->SetFacingToObject(player);
                        }
                        events.ScheduleEvent(EVENT_PRE_BATTLE_17, 2s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_17:
                        vereesa->SetFaction(35);
                        vereesa->SetVisible(false);
                        DoCast(SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_18, 1300, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_18:
                    {
                        DoCastSelf(SPELL_TELEPORT);

                        kinndy->CastSpell(kinndy, SPELL_TELEPORT);
                        tervosh->CastSpell(tervosh, SPELL_TELEPORT);
                        aden->CastSpell(aden, SPELL_TELEPORT);
                        kalecgos->CastSpell(kalecgos, SPELL_TELEPORT);

                        for (uint32 i = 0; i < 6; ++i)
                        {
                            if (Creature * c = ObjectAccessor::GetCreature(*me, archmagesGUID[i]))
                                c->CastSpell(c, SPELL_TELEPORT);
                        }

                        for (Player* player : players)
                            player->CastSpell(player, SPELL_TELEPORT);

                        events.ScheduleEvent(EVENT_PRE_BATTLE_19, 1500, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_19:
                    {
                        me->SetSheath(SHEATH_STATE_MELEE);

                        // @TODO : Summon dragon kalec with path flight
                        kalecgos->SetVisible(false);
                        kalecgos = me->SummonCreature(NPC_KALECGOS_DRAGON, -3753.57f, -4444.59f, 73.83f, 5.49f);
                        kalecgos->GetMotionMaster()->MoveCirclePath(-3753.57f, -4444.59f, 73.83f, 88.05f, true, 16);

                        Relocate(aden, -3669.01f, -4381.60f, 9.56f, 0.69f);
                        Relocate(me, -3658.39f, -4372.87f, 9.35f, 0.69f);
                        Relocate(kinndy, -3666.15f, -4519.95f, 10.03f, 2.44f);
                        Relocate(tervosh, -3808.72f, -4541.01f, 10.68f, 3.09f);

                        for (int i = 0; i < 6; ++i)
                        {
                            if (Creature * c = ObjectAccessor::GetCreature(*me, archmagesGUID[i]))
                            {
                                c->SetTarget(ObjectGuid::Empty);
                                c->SetSheath(SHEATH_STATE_MELEE);
                                Relocate(c, ArchmagesRelocate[i][0], ArchmagesRelocate[i][1], ArchmagesRelocate[i][2], ArchmagesRelocate[i][3]);

                                uint32 entry = c->GetEntry();
                                switch (entry)
                                {
                                    case NPC_AMARA_LEESON:
                                    case NPC_THALEN_SONGWEAVER:
                                        c->CastSpell(c, 39550);
                                        break;

                                    default:
                                        break;
                                }
                            }
                        }

                        if (Creature * c = me->SummonCreature(NPC_INVISIBLE_STALKER, -3646.48f, -4362.23f, 9.57f, 0.70f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            c->AddAura(70573, c);
                            c->SetObjectScale(3.0f);
                        }

                        for (Player* player : players)
                        {
                            float angle = float(rand_norm() * 2 * M_PI);
                            float dist = frand(1, 4);
                            player->NearTeleportTo(-3661.96f + cos(angle) * dist, -4374.06f + sin(angle) * dist, 9.35f, 0.72f);
                        }

                        events.ScheduleEvent(EVENT_PRE_BATTLE_20, 4s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_20:
                        me->GetGameObjectListWithEntryInGrid(fires, GOB_FIRE_THERAMORE, 18.f);
                        firesCount = fires.size();
                        events.ScheduleEvent(EVENT_PRE_BATTLE_21, 1s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_21:
                    {
                        me->SetFacingTo(0.70f);

                        if (fires.empty() || firesCount <= 0)
                        {
                            events.SetPhase(PHASE_BATTLE);
                            if (Creature * waves = me->SummonCreature(NPC_WAVES_INVOKER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN))
                                waves->AI()->SetData(1, 1);
                            break;
                        }

                        if (GameObject * fire = fires.at(firesCount - 1))
                        {
                            if (Creature * c = me->SummonCreature(NPC_INVISIBLE_STALKER, *fire, TEMPSUMMON_DEAD_DESPAWN))
                            {
                                c->SetFaction(14);
                                c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                c->SetReactState(REACT_PASSIVE);
                                c->CastSpell(c, 62849);
                                me->SetFacingToObject(c);
                                DoCast(c, 54261);
                                fire->Delete();
                                firesCount--;
                                events.ScheduleEvent(EVENT_PRE_BATTLE_21, 2s, 0, PHASE_PRE_BATTLE);
                            }
                        }

                        break;
                    }

                    #pragma endregion

                    // Event - Post Battle
                    case EVENT_POST_BATTLE_1:
                        me->SetWalk(true);
                        aden->Dismount();
                        me->GetMotionMaster()->MovePoint(0, -3666.88f, -4379.16f, 9.36f, true, 3.89f);
                        events.ScheduleEvent(EVENT_POST_BATTLE_2, 6s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_2:
                        Talk(SAY_POST_BATTLE_1);
                        me->SetFacingToObject(aden);
                        events.ScheduleEvent(EVENT_POST_BATTLE_3, 4s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_3:
                        aden->AI()->Talk(SAY_POST_BATTLE_2);
                        events.ScheduleEvent(EVENT_POST_BATTLE_4, 6s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_4:
                        Talk(SAY_POST_BATTLE_3);
                        events.ScheduleEvent(EVENT_POST_BATTLE_5, 2s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_5:
                        aden->SetWalk(true);
                        aden->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaPostBattlePath, JAINA_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_POST_BATTLE_6, 23s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_6:
                        if (Creature * amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 2000.f))
                            amara->NearTeleportTo(-3651.13f, -4520.06f, 9.46f, 1.58f);
                        me->GetMotionMaster()->MovePoint(0, -3634.95f, -4412.57f, 9.81f, true, 2.17f);
                        aden->GetMotionMaster()->Clear();
                        aden->GetMotionMaster()->MovePoint(0, -3615.46f, -4437.43f, 13.68f, true, 1.57f);
                        events.ScheduleEvent(EVENT_POST_BATTLE_7, 3s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_7:
                        kinndy->AI()->Talk(SAY_POST_BATTLE_4);
                        events.ScheduleEvent(EVENT_POST_BATTLE_8, 5s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_8:
                        Talk(SAY_POST_BATTLE_5);
                        events.ScheduleEvent(EVENT_POST_BATTLE_9, 9s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_9:
                        kinndy->AI()->Talk(SAY_POST_BATTLE_6);
                        kinndy->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        kinndy->SetFacingToObject(me);
                        events.ScheduleEvent(EVENT_POST_BATTLE_10, 4s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_10:
                        Talk(SAY_POST_BATTLE_7);
                        events.ScheduleEvent(EVENT_POST_BATTLE_11, 4s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_11:
                        kinndy->AI()->Talk(SAY_POST_BATTLE_8);
                        events.ScheduleEvent(EVENT_POST_BATTLE_12, 3s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_12:
                        Talk(SAY_POST_BATTLE_9);
                        events.ScheduleEvent(EVENT_POST_BATTLE_13, 16s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_13:
                        Talk(SAY_POST_BATTLE_10);
                        events.ScheduleEvent(EVENT_POST_BATTLE_14, 7s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_14:
                        kinndy->AI()->Talk(SAY_POST_BATTLE_11);
                        events.ScheduleEvent(EVENT_POST_BATTLE_15, 6s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_15:
                        Talk(SAY_POST_BATTLE_12);
                        events.ScheduleEvent(EVENT_POST_BATTLE_16, 6s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_16:
                        Talk(SAY_POST_BATTLE_13);
                        events.ScheduleEvent(EVENT_POST_BATTLE_17, 15s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_17:
                        kinndy->AI()->Talk(SAY_POST_BATTLE_14);
                        events.ScheduleEvent(EVENT_POST_BATTLE_18, 3s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_18:
                        Talk(SAY_POST_BATTLE_15);
                        events.ScheduleEvent(EVENT_POST_BATTLE_19, 3s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_19:
                        Talk(SAY_POST_BATTLE_3);
                        kinndy->SetWalk(false);
                        kinndy->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                        me->SetWalk(false);
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaWoundedPath, JAINA_PATH_1_SIZE, false);
                        events.ScheduleEvent(EVENT_POST_BATTLE_20, 23s, 0, PHASE_POST_BATTLE);
                        break;

                    case EVENT_POST_BATTLE_20:
                        kinndy->GetMotionMaster()->Clear();
                        kinndy->GetMotionMaster()->MoveIdle();
                        kinndy->SetWalk(true);
                        me->SetWalk(true);
                        if (Creature * wounded = DoSummon(NPC_WOUNDED_DUMMY, me->GetPosition()))
                            wounded->AI()->SetData(1, 1);
                        break;

                    default:
                        break;
                }
            }

            // Combat
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // Blizzard
            if (blizzardTimer <= diff)
            {
                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_BLIZZARD);
                blizzardTimer = urand(6000, 15000);
            }
            else blizzardTimer -= diff;

            // Boule de Feu
            if (fireballTimer <= diff)
            {
                DoCastVictim(SPELL_FIREBALL);
                fireballTimer = urand(3600, 5000);
            }
            else fireballTimer -= diff;

            // Parle en combat
            if (sayInCombatTimer <= diff)
            {
                me->PlayDistanceSound(28140);
                sayInCombatTimer = urand(24000, 65000);
            }
            else sayInCombatTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:
        Creature* kalecgos;
        Creature* tervosh;
        Creature* kinndy;
        Creature* aden;
        Creature* thalen;
        Creature* rhonin;
        Creature* vereesa;
        Creature* pained;
        Creature* perith;
        Creature* zealous;
        Creature* guard;
        ObjectGuid archmagesGUID[6];
        EventMap events;
        std::vector<GameObject*> fires;
        std::vector<Player*> players;
        std::list<Creature*> civils;
        bool playerShaker;
        uint8 firesCount;
        uint8 npcCount;

        uint32 sayInCombatTimer, fireballTimer, blizzardTimer;

        void Relocate(Creature * c, float x, float y, float z, float orientation)
        {
            const Position pos{ x, y, z, orientation };
            c->NearTeleportTo(pos);
            c->SetHomePosition(pos);
            c->Respawn();
        }

        void reverse(Position array[], int size)
        {
            std::stack<Position> stack;
            for (int i = 0; i < size; ++i)
                stack.push(array[i]);

            int index = 0;
            while (!stack.empty())
            {
                array[index++] = stack.top();
                stack.pop();
            }
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_jaina_theramoreAI(creature);
    }
};

void AddSC_theramore()
{
    new npc_jaina_theramore();
}
