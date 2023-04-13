//
//#include "PrecompiledHeaders/ScriptPCH.h"
//
//#define GOSSIP_A_WRINKIE_IN_TIME "Yes, Anachronos. I am ready to witness your vision of the future."
//#define ACTION_A_WRINKIE_IN_TIME 1001
//#define GOSSIP_ON_A_WING_AND_A_PRAYER "Take the Timeless Eye."
//#define ACTION_ON_A_WING_AND_A_PRAYER 1002
//
//enum Says
//{
//    SAY_1 = 0,
//    SAY_2 = 1,
//    SAY_3 = 2,
//    SAY_4 = 3,
//    SAY_5 = 4,
//    SAY_6 = 5,
//    SAY_7 = 6,
//    SAY_8 = 7
//};
//
//enum Spells
//{
//    SPELL_HALEGOSA_TRANSFORM = 98948,
//    SPELL_HALLEGOSA_SUMMON_DISC_1 = 98939, // alliance
//    SPELL_HALLEGOSA_SUMMON_DISC_2 = 99094, // horde
//    SPELL_PLAYER_CAST_DISC_SUMMON_1 = 98944, // alliance
//    SPELL_PLAYER_CAST_DISC_SUMMON_2 = 99096, // horde
//    SPELL_DISC_SUMMON_AURA = 98946,
//    SPELL_RIDE_VEHICLE = 43671,
//    SPELL_SUMMON_TARECGOSA_DISC = 98634,
//    SPELL_SUMMON_DRAGON_DISC_1 = 98943, // alliance
//    SPELL_SUMMON_DRAGON_DISC_2 = 99098, // horde
//    SPELL_ESSENCE_OF_TARECGOSA = 98439,
//    SPELL_PULSE_OF_TARECGOSA = 99025
//};
//
//enum Events
//{
//    EVENT_HALLEGOSA_MOVE_1 = 1,
//    EVENT_HALLEGOSA_MOVE_2 = 2,
//    EVENT_HALLEGOSA_DISC_1 = 3,
//    EVENT_HALLEGOSA_TRANS = 4,
//    EVENT_HALLEGOSA_END = 5,
//    EVENT_TALK_1 = 6,
//    EVENT_TALK_2 = 7,
//    EVENT_TALK_3 = 8,
//    EVENT_TALK_4 = 9,
//    EVENT_TALK_5 = 10,
//    EVENT_ESSENCE_1 = 11,
//    EVENT_ESSENCE_2 = 12,
//    EVENT_TALK_6 = 13,
//    EVENT_TALK_7 = 14,
//    EVENT_TALK_8 = 15,
//    EVENT_START_FINAL = 16,
//    EVENT_END_FINAL = 17,
//    EVENT_START_EVENT = 18
//};
//
//enum Creatures
//{
//    NPC_HALLEGOSA_1 = 53371,
//    NPC_HALLEGOSA_2 = 53466,
//    NPC_KALECGOS = 53392,
//    NPC_TARECGOSA = 53396,
//    NPC_STALKER = 53422,
//    NPC_STALKER2 = 53398,
//    NPC_BLUE_DRAGON = 53394,
//    NPC_BLUE_DRAKE = 53408
//};
//
//enum Points
//{
//    POINT_HALLEGOSA_1 = 1,
//    POINT_HALLEGOSA_2 = 2
//};
//
//Position const Pos1[10] =
//{
//    { -8642.198242f, 780.237244f, 97.042953f, 0.0f },
//    { -8635.111328f, 787.129761f, 97.045670f, 0.0f },
//    { -8637.245117f, 798.395203f, 96.929199f, 0.0f },
//    { -8667.672852f, 743.323975f, 148.60f, 3.82f },
//    { -8706.003906f, 712.394714f, 159.57f, 0.64f },
//    { -8726.765625f, 738.313660f, 148.60f, 6.14f },
//    { -8698.031250f, 757.344666f, 148.60f, 4.92f },
//    { -8655.565430f, 717.462524f, 149.95f, 2.86f },
//    { -8681.251953f, 698.383423f, 154.26f, 1.72f },
//    { -8686.417969f, 728.565369f, 152.66f, 3.73f }
//};
//
//Position const Pos2[13] =
//{
//    { 1646.289795f, -4354.969238f, 26.337263f, 0.0f },
//    { 1632.526611f, -4362.582031f, 26.775732f, 0.0f },
//    { 1627.358765f, -4365.393555f, 24.574675f, 0.0f },
//    { 1622.515015f, -4375.128906f, 24.620348f, 0.0f },
//    { 1611.619873f, -4373.713867f,  24.628357f, 0.0f },
//    { 1604.297729f, -4377.556152f,  20.968573f, 0.0f },
//    { 1582.353271f, -4370.833496f,  20.658976f, 0.0f },
//    { 1615.443115f, -4357.785156f,  125.10f,    0.18f },
//    { 1656.803711f, -4350.011719f,  136.80f,    3.63f },
//    { 1631.014893f, -4339.889160f,  133.39f,    5.08f },
//    { 1649.036011f, -4379.650391f,  123.84f,    2.12f },
//    { 1627.399048f, -4381.077637f,  125.10f,    1.06f },
//    { 1634.151245f, -4358.372559f,  124.68f,    0.55f }
//};
//
//// 15192
//class npc_anachronos : public CreatureScript
//{
//public:
//    npc_anachronos() : CreatureScript("npc_anachronos") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (creature->isQuestGiver())
//            player->PrepareQuestMenu(creature->GetGUID());
//
//        if (player->GetQuestStatus(29134) == QUEST_STATUS_INCOMPLETE)
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_A_WRINKIE_IN_TIME, GOSSIP_SENDER_MAIN, ACTION_A_WRINKIE_IN_TIME);
//        else if (player->GetQuestStatus(29193) == QUEST_STATUS_INCOMPLETE)
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ON_A_WING_AND_A_PRAYER, GOSSIP_SENDER_MAIN, ACTION_ON_A_WING_AND_A_PRAYER);
//        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        if (action == ACTION_A_WRINKIE_IN_TIME)
//            player->KilledMonsterCredit(52605);
//        else if (action == ACTION_ON_A_WING_AND_A_PRAYER)
//        {
//            uint32 curItemCount = player->GetItemCount(69238, false);
//            if (curItemCount >= 1)
//                return false;
//
//            ItemPosCountVec dest;
//            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 49661, 1);
//            if (msg == EQUIP_ERR_OK)
//            {
//                Item* item = player->StoreNewItem(dest, 69238, true);
//                player->SendNewItem(item, 1, true, false);
//            }
//            else
//                return false;
//        }
//        return true;
//    }
//};
//
//// 53371 & 53466
//class npc_hallegosa : public CreatureScript
//{
//public:
//    npc_hallegosa() : CreatureScript("npc_hallegosa") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_hallegosaAI(creature);
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        player->CLOSE_GOSSIP_MENU();
//
//        creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
//
//        creature->SetWalk(true);
//        creature->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_1, ((creature->GetMapId() == 1) ? Pos2[0] : Pos1[0]));
//        return true;
//    }
//
//    struct npc_hallegosaAI : ScriptedAI
//    {
//        npc_hallegosaAI(Creature* creature) : ScriptedAI(creature) {}
//
//        EventMap events;
//        uint8 curPoint;
//
//        void OnQuestAccept(Player* player, const Quest quest)
//        {
//            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
//        }
//
//        void Reset() override
//        {
//            curPoint = 0;
//            me->SetWalk(false);
//            me->SetDisableGravity(false);
//            me->SetCanFly(false);
//            me->RemoveAllAuras();
//            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
//        }
//
//        void MovementInform(uint32 type, uint32 data)
//        {
//            if (type == POINT_MOTION_TYPE)
//            {
//                switch (data)
//                {
//                case POINT_HALLEGOSA_1:
//                {
//                    curPoint++;
//                    uint8 max_point = ((me->GetMapId() == 1) ? 7 : 3);
//
//                    if (curPoint == max_point)
//                        events.ScheduleEvent(EVENT_HALLEGOSA_DISC_1, 500);
//                    else
//                        events.ScheduleEvent(EVENT_HALLEGOSA_MOVE_1, 500);
//                    break;
//                }
//                case POINT_HALLEGOSA_2:
//                    events.ScheduleEvent(EVENT_HALLEGOSA_END, 5000);
//                    break;
//                }
//            }
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_HALLEGOSA_MOVE_1:
//                    me->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_1, ((me->GetMapId() == 1) ? Pos2[curPoint] : Pos1[curPoint]));
//                    break;
//                case EVENT_HALLEGOSA_DISC_1:
//                    if (me->GetMapId() == 1)
//                        sGameEventMgr->StopEvent(88, true);
//                    else if (me->GetMapId() == 0)
//                        sGameEventMgr->StopEvent(89, true);
//                    DoCast(me, SPELL_HALLEGOSA_SUMMON_DISC_1);
//                    events.ScheduleEvent(EVENT_HALLEGOSA_TRANS, 5000);
//                    break;
//                case EVENT_HALLEGOSA_TRANS:
//                    DoCast(me, SPELL_HALEGOSA_TRANSFORM);
//                    events.ScheduleEvent(EVENT_HALLEGOSA_MOVE_2, 3000);
//                    break;
//                case EVENT_HALLEGOSA_MOVE_2:
//                    me->SetCanFly(true);
//                    me->SetDisableGravity(true);
//                    me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_CAN_FLY);
//                    me->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_2, ((me->GetMapId() == 1) ? Pos2[curPoint] : Pos1[curPoint]));
//                    break;
//                case EVENT_HALLEGOSA_END:
//                    me->SummonCreature(NPC_KALECGOS, ((me->GetMapId() == 1) ? Pos2[8] : Pos1[4]), TEMPSUMMON_TIMED_DESPAWN, 95000);
//                    break;
//                default:
//                    break;
//                }
//            }
//        }
//    };
//};
//
//// 53392
//struct npc_kalecgos_for_teracgosa : ScriptedAI
//{
//    npc_kalecgos_for_teracgosa(Creature* creature) : ScriptedAI(creature) {}
//
//    EventMap events;
//
//    void IsSummonedBy(Unit* /*owner*/)
//    {
//        events.ScheduleEvent(EVENT_TALK_1, 5000);
//    }
//
//    void UpdateAI(uint32 diff)
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_TALK_1:
//                Talk(SAY_1);
//                events.ScheduleEvent(EVENT_TALK_2, 6000);
//                break;
//            case EVENT_TALK_2:
//                Talk(SAY_2);
//                if (me->GetMapId() == 1)
//                {
//                    for (uint8 i = 10; i < 12; ++i)
//                        me->SummonCreature(NPC_BLUE_DRAGON, Pos2[i], TEMPSUMMON_TIMED_DESPAWN, 84000);
//                }
//                else
//                {
//                    for (uint8 i = 6; i < 9; ++i)
//                        me->SummonCreature(NPC_BLUE_DRAGON, Pos1[i], TEMPSUMMON_TIMED_DESPAWN, 84000);
//                }
//                events.ScheduleEvent(EVENT_TALK_3, 7000);
//                break;
//            case EVENT_TALK_3:
//                Talk(SAY_3);
//                events.ScheduleEvent(EVENT_TALK_4, 6000);
//                break;
//            case EVENT_TALK_4:
//                Talk(SAY_4);
//                me->SummonCreature(NPC_TARECGOSA, ((me->GetMapId() == 1) ? Pos2[9] : Pos1[5]), TEMPSUMMON_TIMED_DESPAWN, 71000);
//                events.ScheduleEvent(EVENT_TALK_5, 7000);
//                break;
//            case EVENT_TALK_5:
//                Talk(SAY_5);
//                me->SummonCreature(NPC_STALKER2, ((me->GetMapId() == 1) ? Pos2[12] : Pos1[9]), TEMPSUMMON_TIMED_DESPAWN, 64000);
//                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
//                {
//                    stalker->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
//                    stalker->SetDisplayId(38326);
//                }
//                events.ScheduleEvent(EVENT_ESSENCE_1, 9000);
//                break;
//            case EVENT_ESSENCE_1:
//                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
//                    stalker->CastSpell(stalker, SPELL_ESSENCE_OF_TARECGOSA);
//                events.ScheduleEvent(EVENT_ESSENCE_2, 15000);
//                break;
//            case EVENT_ESSENCE_2:
//                if (Creature* tarecgosa = me->FindNearestCreature(NPC_TARECGOSA, 100.0f))
//                    tarecgosa->DespawnOrUnsummon();
//                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
//                    stalker->CastSpell(stalker, SPELL_PULSE_OF_TARECGOSA);
//                events.ScheduleEvent(EVENT_TALK_6, 6000);
//                break;
//            case EVENT_TALK_6:
//                Talk(SAY_6);
//                events.ScheduleEvent(EVENT_TALK_7, 13000);
//                break;
//            case EVENT_TALK_7:
//                Talk(SAY_7);
//                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
//                    stalker->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
//                events.ScheduleEvent(EVENT_TALK_8, 7000);
//                break;
//            case EVENT_TALK_8:
//                Talk(SAY_8);
//                if (Creature* hallegosa = me->FindNearestCreature(((me->GetMapId() == 1) ? NPC_HALLEGOSA_1 : NPC_HALLEGOSA_2), 100.0f))
//                {
//                    hallegosa->NearTeleportTo(hallegosa->GetHomePosition().GetPositionX(), hallegosa->GetHomePosition().GetPositionY(), hallegosa->GetHomePosition().GetPositionZ(), hallegosa->GetHomePosition().GetOrientation());
//                    hallegosa->DespawnOrUnsummon();
//                }
//                if (me->GetMapId() == 1)
//                    WorldDatabase.PExecute("UPDATE game_event SET start_time=NOW() WHERE eventEntry = 88");
//                else if (me->GetMapId() == 0)
//                    WorldDatabase.PExecute("UPDATE game_event SET start_time=NOW() WHERE eventEntry = 89");
//                events.ScheduleEvent(EVENT_START_EVENT, 4000);
//                break;
//            case EVENT_START_EVENT:
//                if (me->GetMapId() == 1)
//                    sGameEventMgr->StartEvent(88, true);
//                else if (me->GetMapId() == 0)
//                    sGameEventMgr->StartEvent(89, true);
//                break;
//            }
//        }
//    }
//};
//
//void AddSC_event_tarecgosa()
//{
//    new npc_anachronos();
//    new npc_hallegosa();
//    RegisterCreatureAI(npc_kalecgos_for_teracgosa);
//}
