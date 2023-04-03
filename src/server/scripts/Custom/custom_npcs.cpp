/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
* Copyright 2021 DekkCore
* * Copyright (C) 2021 BfaCore Reforged / / 来源:https://github.com/Titans-Project/BfaCore-Reforged/blob/main/src/server/scripts/Custom/custom_npcs.cpp

*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "DatabaseEnv.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
//#include "BattlePetSystem.h"
#include "Creature.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "Language.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
//#include "PetBattle.h"
#include "BattlePetDataStore.h"
#include "World.h"
#include "CollectionMgr.h"
#include "WorldSession.h"
#include "Chat.h"
#include <PetBattle.h>
#include <BattlePetSystem.h>

class npc_rate_xp_modifier : public CreatureScript
{
    public:
        npc_rate_xp_modifier() : CreatureScript("npc_rate_xp_modifier") { }

//#define MAX_RATE uint32(10)
#define MAX_RATE uint32(3)  //定义最大倍率

        bool OnGossipHello(Player* player, Creature* creature) //override   //原先为override
        {
            for (uint32 i = 1; i <= MAX_RATE; ++i)
            {
                if (i == player->GetPersonnalXpRate())
                    continue;

                if (i == sWorld->getRate(RATE_XP_KILL))
                    continue;

                std::ostringstream gossipText;
                gossipText << "Rate x" << i;
                AddGossipItemFor(player,GossipOptionNpc::None, gossipText.str(), GOSSIP_SENDER_MAIN, i);
            }

            if (player->GetPersonnalXpRate())
            {
                std::ostringstream gossipText;
                gossipText << "Default Rate - x" << sWorld->getRate(RATE_XP_KILL);
                AddGossipItemFor(player, GossipOptionNpc::None, gossipText.str(), GOSSIP_SENDER_MAIN, 0);
            }

            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            return ItemContext::NONE, true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction) //override    //原先为override
        {
            CloseGossipMenuFor(player);
            player->SetPersonnalXpRate(float(std::min(MAX_RATE, uiAction)));
            return ItemContext::NONE, true;
        }
};

#define GOSSIP_A_WRINKIE_IN_TIME "Yes, Anachronos. I am ready to witness your vision of the future."
#define ACTION_A_WRINKIE_IN_TIME 1001
#define GOSSIP_ON_A_WING_AND_A_PRAYER "Take the Timeless Eye."
#define ACTION_ON_A_WING_AND_A_PRAYER 1002

enum Says
{
    SAY_1 = 0,
    SAY_2 = 1,
    SAY_3 = 2,
    SAY_4 = 3,
    SAY_5 = 4,
    SAY_6 = 5,
    SAY_7 = 6,
    SAY_8 = 7
};

enum Spells
{
    SPELL_HALEGOSA_TRANSFORM = 98948,
    SPELL_HALLEGOSA_SUMMON_DISC_1 = 98939, // alliance
    SPELL_HALLEGOSA_SUMMON_DISC_2 = 99094, // horde
    SPELL_PLAYER_CAST_DISC_SUMMON_1 = 98944, // alliance
    SPELL_PLAYER_CAST_DISC_SUMMON_2 = 99096, // horde
    SPELL_DISC_SUMMON_AURA = 98946,
    SPELL_RIDE_VEHICLE = 43671,
    SPELL_SUMMON_TARECGOSA_DISC = 98634,
    SPELL_SUMMON_DRAGON_DISC_1 = 98943, // alliance
    SPELL_SUMMON_DRAGON_DISC_2 = 99098, // horde
    SPELL_ESSENCE_OF_TARECGOSA = 98439,
    SPELL_PULSE_OF_TARECGOSA = 99025
};

enum Events
{
    EVENT_HALLEGOSA_MOVE_1 = 1,
    EVENT_HALLEGOSA_MOVE_2 = 2,
    EVENT_HALLEGOSA_DISC_1 = 3,
    EVENT_HALLEGOSA_TRANS = 4,
    EVENT_HALLEGOSA_END = 5,
    EVENT_TALK_1 = 6,
    EVENT_TALK_2 = 7,
    EVENT_TALK_3 = 8,
    EVENT_TALK_4 = 9,
    EVENT_TALK_5 = 10,
    EVENT_ESSENCE_1 = 11,
    EVENT_ESSENCE_2 = 12,
    EVENT_TALK_6 = 13,
    EVENT_TALK_7 = 14,
    EVENT_TALK_8 = 15,
    EVENT_START_FINAL = 16,
    EVENT_END_FINAL = 17,
    EVENT_START_EVENT = 18
};

enum Creatures
{
    NPC_HALLEGOSA_1 = 53371,
    NPC_HALLEGOSA_2 = 53466,
    NPC_KALECGOS = 53392,
    NPC_TARECGOSA = 53396,
    NPC_STALKER = 53422,
    NPC_STALKER2 = 53398,
    NPC_BLUE_DRAGON = 53394,
    NPC_BLUE_DRAKE = 53408
};

enum Points
{
    POINT_HALLEGOSA_1 = 1,
    POINT_HALLEGOSA_2 = 2
};

Position const Pos1[10] =
{
    { -8642.198242f, 780.237244f, 97.042953f, 0.0f },
    { -8635.111328f, 787.129761f, 97.045670f, 0.0f },
    { -8637.245117f, 798.395203f, 96.929199f, 0.0f },
    { -8667.672852f, 743.323975f, 148.60f, 3.82f },
    { -8706.003906f, 712.394714f, 159.57f, 0.64f },
    { -8726.765625f, 738.313660f, 148.60f, 6.14f },
    { -8698.031250f, 757.344666f, 148.60f, 4.92f },
    { -8655.565430f, 717.462524f, 149.95f, 2.86f },
    { -8681.251953f, 698.383423f, 154.26f, 1.72f },
    { -8686.417969f, 728.565369f, 152.66f, 3.73f }
};

Position const Pos2[13] =
{
    { 1646.289795f, -4354.969238f, 26.337263f, 0.0f },
    { 1632.526611f, -4362.582031f, 26.775732f, 0.0f },
    { 1627.358765f, -4365.393555f, 24.574675f, 0.0f },
    { 1622.515015f, -4375.128906f, 24.620348f, 0.0f },
    { 1611.619873f, -4373.713867f,  24.628357f, 0.0f },
    { 1604.297729f, -4377.556152f,  20.968573f, 0.0f },
    { 1582.353271f, -4370.833496f,  20.658976f, 0.0f },
    { 1615.443115f, -4357.785156f,  125.10f,    0.18f },
    { 1656.803711f, -4350.011719f,  136.80f,    3.63f },
    { 1631.014893f, -4339.889160f,  133.39f,    5.08f },
    { 1649.036011f, -4379.650391f,  123.84f,    2.12f },
    { 1627.399048f, -4381.077637f,  125.10f,    1.06f },
    { 1634.151245f, -4358.372559f,  124.68f,    0.55f }
};

// 15192
class npc_anachronos : public CreatureScript
{
public:
    npc_anachronos() : CreatureScript("npc_anachronos") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(29134) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_A_WRINKIE_IN_TIME, GOSSIP_SENDER_MAIN, ACTION_A_WRINKIE_IN_TIME);
        else if (player->GetQuestStatus(29193) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_ON_A_WING_AND_A_PRAYER, GOSSIP_SENDER_MAIN, ACTION_ON_A_WING_AND_A_PRAYER);
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return ItemContext::NONE, true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == ACTION_A_WRINKIE_IN_TIME)
            player->KilledMonsterCredit(52605);
        else if (action == ACTION_ON_A_WING_AND_A_PRAYER)
        {
            uint32 curItemCount = player->GetItemCount(69238, false);
            if (curItemCount >= 1)
                return false;

            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 49661, 1);
            if (msg == EQUIP_ERR_OK)
            {
                Item* item = player->StoreNewItem(dest, 69238, true);
                player->SendNewItem(item, 1, true, false);
            }
            else
                return false;
        }
        return ItemContext::NONE, true;
    }
};

// 53371 & 53466
class npc_hallegosa : public CreatureScript
{
public:
    npc_hallegosa() : CreatureScript("npc_hallegosa") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hallegosaAI(creature);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/)
    {
        player->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(player);

        creature->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        creature->SetWalk(true);
        creature->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_1, ((creature->GetMapId() == 1) ? Pos2[0] : Pos1[0]));
        return ItemContext::NONE, true;
    }

    struct npc_hallegosaAI : ScriptedAI
    {
        npc_hallegosaAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;
        uint8 curPoint=0;//原先没有定义初值

        void OnQuestAccept(Player* /*player*/, Quest const* /*quest*/) 
        {
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
        }

        void Reset() override
        {
            curPoint = 0;
            me->SetWalk(false);
            me->SetDisableGravity(false);
            me->SetCanFly(false);
            me->RemoveAllAuras();
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
        }

        void MovementInform(uint32 type, uint32 data)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (data)
                {
                case POINT_HALLEGOSA_1:
                {
                    curPoint++;
                    uint8 max_point = ((me->GetMapId() == 1) ? 7 : 3);

                    if (curPoint == max_point)
                        events.ScheduleEvent(EVENT_HALLEGOSA_DISC_1, Milliseconds(500), 0, 0);
                    else
                        events.ScheduleEvent(EVENT_HALLEGOSA_MOVE_1, Milliseconds(500),0,0);
                    break;
                }
                case POINT_HALLEGOSA_2:
                    events.ScheduleEvent(EVENT_HALLEGOSA_END, Milliseconds(5000), 0, 0);
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_HALLEGOSA_MOVE_1:
                    me->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_1, ((me->GetMapId() == 1) ? Pos2[curPoint] : Pos1[curPoint]));
                    break;
                case EVENT_HALLEGOSA_DISC_1:
                    if (me->GetMapId() == 1)
                        sGameEventMgr->StopEvent(88, true);
                    else if (me->GetMapId() == 0)
                        sGameEventMgr->StopEvent(89, true);
                    DoCast(me, SPELL_HALLEGOSA_SUMMON_DISC_1);
                    events.ScheduleEvent(EVENT_HALLEGOSA_TRANS, Milliseconds(5000), 0, 0);
                    break;
                case EVENT_HALLEGOSA_TRANS:
                    DoCast(me, SPELL_HALEGOSA_TRANSFORM);
                    events.ScheduleEvent(EVENT_HALLEGOSA_MOVE_2, Milliseconds(3000), 0, 0);
                    break;
                case EVENT_HALLEGOSA_MOVE_2:
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_CAN_FLY);
                    me->GetMotionMaster()->MovePoint(POINT_HALLEGOSA_2, ((me->GetMapId() == 1) ? Pos2[curPoint] : Pos1[curPoint]));
                    break;
                case EVENT_HALLEGOSA_END:
                    me->SummonCreature(53392, ((me->GetMapId() == 1) ? Pos2[8] : Pos1[4]), TEMPSUMMON_TIMED_DESPAWN, 95000, 0, ObjectGuid::Empty);

                    //TempSummon* npc = player->SummonCreature(8000000, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, minutesforassist * 60000, ObjectGuid::Empty);//ObjectGuid privateObjectOwner /* = ObjectGuid::Empty */
                    //TempSummon* npc = me->SummonCreature(53392, ((me->GetMapId() == 1) ? Pos2[8] : Pos1[4]), TEMPSUMMON_TIMED_DESPAWN, 95000, 0, ObjectGuid::Empty);

                    //TempSummon* npc= 是我后加的
                    break;
                //default:
                    break;
                }
            }
        }
    };
};

// 53392
struct npc_kalecgos_for_teracgosa : ScriptedAI
{
    npc_kalecgos_for_teracgosa(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void IsSummonedBy(Unit* /*owner*/)
    {
        events.ScheduleEvent(EVENT_TALK_1, Milliseconds(5000));
    }

    void UpdateAI(uint32 diff)
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_TALK_1:
                Talk(SAY_1);
                events.ScheduleEvent(EVENT_TALK_2, Milliseconds(6000)); 
                break;
            case EVENT_TALK_2:
                Talk(SAY_2);
                if (me->GetMapId() == 1)
                {
                    for (uint8 i = 10; i < 12; ++i)
                        me->SummonCreature(NPC_BLUE_DRAGON, Pos2[i], TEMPSUMMON_TIMED_DESPAWN, 84000,0, ObjectGuid::Empty);
                }
                else
                {
                    for (uint8 i = 6; i < 9; ++i)
                        me->SummonCreature(NPC_BLUE_DRAGON, Pos1[i], TEMPSUMMON_TIMED_DESPAWN, 84000, 0, ObjectGuid::Empty);
                }
                events.ScheduleEvent(EVENT_TALK_3, Milliseconds(7000));
                break;
            case EVENT_TALK_3:
                Talk(SAY_3);
                events.ScheduleEvent(EVENT_TALK_4, Milliseconds(6000));
                break;
            case EVENT_TALK_4:
                Talk(SAY_4);
                me->SummonCreature(NPC_TARECGOSA, ((me->GetMapId() == 1) ? Pos2[9] : Pos1[5]), TEMPSUMMON_TIMED_DESPAWN, 71000,0, ObjectGuid::Empty);
                events.ScheduleEvent(EVENT_TALK_5, Milliseconds(7000));
                break;
            case EVENT_TALK_5:
                Talk(SAY_5);
                me->SummonCreature(NPC_STALKER2, ((me->GetMapId() == 1) ? Pos2[12] : Pos1[9]), TEMPSUMMON_TIMED_DESPAWN, 64000, 0, ObjectGuid::Empty);
                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
                {
                    stalker->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
                    stalker->SetDisplayId(38326);
                }
                events.ScheduleEvent(EVENT_ESSENCE_1, Milliseconds(9000));
                break;
            case EVENT_ESSENCE_1:
                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
                    stalker->CastSpell(stalker, SPELL_ESSENCE_OF_TARECGOSA);
                events.ScheduleEvent(EVENT_ESSENCE_2, Milliseconds(15000));
                break;
            case EVENT_ESSENCE_2:
                if (Creature* tarecgosa = me->FindNearestCreature(NPC_TARECGOSA, 100.0f))
                    tarecgosa->DespawnOrUnsummon();
                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
                    stalker->CastSpell(stalker, SPELL_PULSE_OF_TARECGOSA);
                events.ScheduleEvent(EVENT_TALK_6, Milliseconds(6000));
                break;
            case EVENT_TALK_6:
                Talk(SAY_6);
                events.ScheduleEvent(EVENT_TALK_7, Milliseconds(13000));
                break;
            case EVENT_TALK_7:
                Talk(SAY_7);
                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER, 100.0f))
                    stalker->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_QUESTGIVER));
                events.ScheduleEvent(EVENT_TALK_8, Milliseconds(7000));
                break;
            case EVENT_TALK_8:
                Talk(SAY_8);
                if (Creature* hallegosa = me->FindNearestCreature(((me->GetMapId() == 1) ? NPC_HALLEGOSA_1 : NPC_HALLEGOSA_2), 100.0f))
                {
                    hallegosa->NearTeleportTo(hallegosa->GetHomePosition().GetPositionX(), hallegosa->GetHomePosition().GetPositionY(), hallegosa->GetHomePosition().GetPositionZ(), hallegosa->GetHomePosition().GetOrientation());
                    hallegosa->DespawnOrUnsummon();
                }
                if (me->GetMapId() == 1)
                    WorldDatabase.PExecute("UPDATE game_event SET start_time=NOW() WHERE eventEntry = 88");
                else if (me->GetMapId() == 0)
                    WorldDatabase.PExecute("UPDATE game_event SET start_time=NOW() WHERE eventEntry = 89");
                events.ScheduleEvent(EVENT_START_EVENT, Milliseconds(4000));
                break;
            case EVENT_START_EVENT:
                if (me->GetMapId() == 1)
                    sGameEventMgr->StartEvent(88, true);
                else if (me->GetMapId() == 0)
                    sGameEventMgr->StartEvent(89, true);
                break;
            }

        }
    }
};

class item_level_boost : public ItemScript
{
public:
    item_level_boost() : ItemScript("item_level_boost") { }

    enum
    {
        item_id = 789001, //Item Entry
        max_lvl = 110, //Server Max Level
        lvlup = 110, //Sets level
    };

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        }
        else if (player->GetLevel() == max_lvl)

        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789001)); //Item is not usable if character is server maxlevel
            return false;
        }
        // Bags
        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            if (Item* bag = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            player->EquipNewItem(slot, 142075, ItemContext::NONE, true);

        player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
        player->InitTalentForLevel();
        player->ModifyMoney(200000000);
        player->LearnSpell(71810, true); // Montura vermis
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, 131736, ItemContext::NONE, true); // Cuello
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, 139248, ItemContext::NONE, true); // Capa
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 139237, ItemContext::NONE, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 139236, ItemContext::NONE, true); // Anillo
        player->LearnSpell(33388, true); // Equitacion
        player->LearnSpell(33391, true);
        player->LearnSpell(34090, true);
        player->LearnSpell(34091, true);
        player->LearnSpell(90265, true);
        player->LearnSpell(54197, true);
        player->LearnSpell(90267, true);
        player->LearnSpell(115913, true);
        player->LearnSpell(110406, true);
        player->LearnSpell(104381, true);

        //   add end - level quests
        bool IsPandarenNeutral = player->GetRace() == RACE_PANDAREN_NEUTRAL;
        std::vector<uint32> questsToAdd;
        if (player->GetTeam() == HORDE || IsPandarenNeutral)
        {
            // quests for Pandaria map
            questsToAdd.push_back(29611);   // The Art of War
            questsToAdd.push_back(31853);   // All Aboard!
            questsToAdd.push_back(29690);   // Into the Mists
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                questsToAdd.push_back(13189);
        }
        if (player->GetTeam() == ALLIANCE || IsPandarenNeutral)
        {
            // quests for Pandaria map
            questsToAdd.push_back(29547);   // The King's Command
            questsToAdd.push_back(29548);   // The Mission
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                questsToAdd.push_back(13188);
        }
        // pandarens
        if (IsPandarenNeutral)
        {
            // add "A New Fate" quest
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(31450))
            {
                player->AddQuest(quest, NULL);
                player->CompleteQuest(quest->GetQuestId());
            }
            // send faction selection screen
//            player->ShowNeutralPlayerFactionSelectUI();//tmp
        }

        if (player->getClass() == CLASS_DEATH_KNIGHT)
        {
            player->LearnSpell(53428, true); // Spell runas de forjas
            player->LearnSpell(48778, true); // Bayo
            player->LearnSpell(50977, true); // porton
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, ItemContext::NONE, true);//Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, ItemContext::NONE, true); // abalorio1
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, ItemContext::NONE, true); // Trinket - Abalario Dps Fuerza
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124386, ItemContext::NONE, true); //  espada de una mano 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124385, ItemContext::NONE, true);  // espada de una mano
            player->AddItem(124388, 1); // arma tanque y dps

        }
        if (player->getClass() == CLASS_MAGE)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, ItemContext::NONE, true); // Trinket - Abalario Dps intelecto
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, ItemContext::NONE, true); // disciplina // sagrado // sombra

        }
        if (player->getClass() == CLASS_DRUID)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad
            player->AddItem(139326, 1);// Trinket - Abalario Dps intelecto
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, ItemContext::NONE, true); // heler
            player->AddItem(124378, 1); // feral

        }
        if (player->getClass() == CLASS_HUNTER)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139214, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139222, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139212, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 141694, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139221, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139215, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139218, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139219, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124361, ItemContext::NONE, true); // punteria // bestias 
            player->AddItem(124368, 1); //supervivencia

        }
        if (player->getClass() == CLASS_MONK)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124368, ItemContext::NONE, true); //  dps 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124368, ItemContext::NONE, true);  // dps
            player->AddItem(124378, 1); // tanke
            player->AddItem(124382, 1); // heler
        }
        if (player->getClass() == CLASS_PALADIN)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, ItemContext::NONE, true);//Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, ItemContext::NONE, true); // Trinket - Abalario Dps Fuerza
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124374, ItemContext::NONE, true); //  tanke 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, ItemContext::NONE, true);  // escudo
            player->AddItem(124388, 1); // dps
            player->AddItem(124376, 1); // heler

        }
        if (player->getClass() == CLASS_PRIEST)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, ItemContext::NONE, true); // Trinket - Abalario Dps intelecto
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, ItemContext::NONE, true); // disciplina // sagrado // sombra 

        }
        if (player->getClass() == CLASS_ROGUE)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124367, ItemContext::NONE, true); //  asesinato //sutileza 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124367, ItemContext::NONE, true);  //  asesinato //sutileza 
            player->AddItem(124387, 1); // foragido
            player->AddItem(124387, 1); // foragido

        }
        if (player->getClass() == CLASS_SHAMAN)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139214, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139222, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139212, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 141694, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139221, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139215, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139218, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139219, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad
            player->AddItem(139326, 1); // Trinket - Abalario Dps intelecto
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124372, ItemContext::NONE, true); //  elemental // heler
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, ItemContext::NONE, true);  //  elemental // heler 
            player->AddItem(124359, 1); // mejora
            player->AddItem(124359, 1); // mejora

        }
        if (player->getClass() == CLASS_WARLOCK)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, ItemContext::NONE, true); // Trinket - Abalario Dps intelecto
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, ItemContext::NONE, true); // las 3 ramas

        }
        if (player->getClass() == CLASS_WARRIOR)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, ItemContext::NONE, true); // Trinket - Abalario Dps Fuerza
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124374, ItemContext::NONE, true); //  tanke 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, ItemContext::NONE, true);  // escudo
            player->AddItem(124388, 1); // dps
            player->AddItem(124388, 1); // dps

        }
        if (player->getClass() == CLASS_DEMON_HUNTER)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, ItemContext::NONE, true); //Head - Cabeza
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, ItemContext::NONE, true); //Wrists - Muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, ItemContext::NONE, true); //Wrais - Cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, ItemContext::NONE, true); // Hands - Manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, ItemContext::NONE, true); // Pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, ItemContext::NONE, true); // Legs - Pantalones
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, ItemContext::NONE, true); // Shoulder - Hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, ItemContext::NONE, true); // feet - pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, ItemContext::NONE, true);
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, ItemContext::NONE, true); // Trinket - Abalario Dps Agilidad

        }
        if (player->GetRace() == RACE_GOBLIN || RACE_ORC || RACE_UNDEAD_PLAYER || RACE_TAUREN || RACE_TROLL || RACE_BLOODELF || RACE_NIGHTBORNE || RACE_HIGHMOUNTAIN_TAUREN || RACE_ZANDALARI_TROLL || RACE_VULPERA || RACE_MAGHAR_ORC)
        {
            player->TeleportTo(1, 1569.97f, -4397.41f, 16.0472f, 0.503f);
        }

        else
            if (player->GetRace() == RACE_DRAENEI || RACE_DWARF || RACE_HUMAN || RACE_NIGHTELF || RACE_GNOME || RACE_WORGEN || RACE_VOID_ELF || RACE_LIGHTFORGED_DRAENEI || RACE_DARK_IRON_DWARF || RACE_MECHAGNOME || RACE_KUL_TIRAN)
            {
                player->TeleportTo(0, -8833.68f, 621.302f, 93.8017f, 0.733f);
            }
            else

                if (player->GetRace() == RACE_PANDAREN_NEUTRAL || RACE_PANDAREN_ALLIANCE || RACE_PANDAREN_HORDE)
                {
                    player->TeleportTo(860, 1466.09f, 3465.98f, 181.86f, 2.733f);
                }

        player->SaveToDB();
        player->SetLevel(lvlup);
        player->InitTalentForLevel();
        player->DestroyItemCount(item_id, 1, true);

        return true;

    }
};

class item_level_boost120 : public ItemScript
{
public:
    item_level_boost120() : ItemScript("item_level_boost120") { }

    enum
    {
        item_id = 789002, //Item Entry
        max_lvl = 120, //Server Max Level
        lvlup = 120, //Sets level
    };

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        }

        // Bags
        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            if (Item* bag = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            player->EquipNewItem(slot, 142075, ItemContext::NONE, true);

        player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
        player->InitTalentForLevel();
        player->ModifyMoney(200000000);
        player->LearnSpell(88331, true); // Montura Riendas del draco de piedra volcnico
        player->LearnSpell(33388, true); // Equitacion
        player->LearnSpell(33391, true);
        player->LearnSpell(34090, true);
        player->LearnSpell(34091, true);
        player->LearnSpell(90265, true);
        player->LearnSpell(54197, true);
        player->LearnSpell(90267, true);
        player->LearnSpell(115913, true);
        player->LearnSpell(110406, true);
        player->LearnSpell(104381, true);

        //   add end - level quests
        bool IsPandarenNeutral = player->GetRace() == RACE_PANDAREN_NEUTRAL;
        std::vector<uint32> questsToAdd;
        if (player->GetTeam() == HORDE || IsPandarenNeutral)
        {
            // quests for Pandaria map
            questsToAdd.push_back(29611);   // The Art of War
            questsToAdd.push_back(31853);   // All Aboard!
            questsToAdd.push_back(29690);   // Into the Mists
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                questsToAdd.push_back(13189);
        }
        if (player->GetTeam() == ALLIANCE || IsPandarenNeutral)
        {
            // quests for Pandaria map
            questsToAdd.push_back(29547);   // The King's Command
            questsToAdd.push_back(29548);   // The Mission
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                questsToAdd.push_back(13188);
        }
        // pandarens
        if (IsPandarenNeutral)
        {
            // add "A New Fate" quest
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(31450))
            {
                player->AddQuest(quest, NULL);
                player->CompleteQuest(quest->GetQuestId());
            }
            // send faction selection screen
            //player->ShowNeutralPlayerFactionSelectUI();//tmp
        }

        if (player->getClass() == CLASS_PALADIN)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 155866, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 158359, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159442, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159437, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159408, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159451, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159415, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 155861, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio healer
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159615, ItemContext::NONE, true); //abalorio healer 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159641, ItemContext::NONE, true); //maza healer
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 159663, ItemContext::NONE, true); //escudo healer
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159287, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159462, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 158314, ItemContext::NONE, true); //dedo
            player->AddItem(159632, 1);  // maza tanke
            player->AddItem(159666, 1);  // escudo tanke
            player->AddItem(159618, 1);  // abalorio tanke
            player->AddItem(159626, 1);  // abalorio tanke 1
            player->AddItem(159638, 1);  // arma 2 manos dps
            player->AddItem(159625, 1);  // abalorio dps
            player->AddItem(159616, 1);  // abalorio dps 1
        }
        if (player->getClass() == CLASS_PRIEST)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159244, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159263, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159239, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159247, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159257, ItemContext::NONE, true); //pecho 
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159285, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159238, ItemContext::NONE, true); //hombros 
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159259, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio healer 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159630, ItemContext::NONE, true); //abalorio healer 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159641, ItemContext::NONE, true); //maza healer 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 158322, ItemContext::NONE, true); //tomo healer 
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 158375, ItemContext::NONE, true);// capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158314, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 158318, ItemContext::NONE, true); //dedo 
            player->AddItem(159631, 1);  // abalorio healer
            player->AddItem(159636, 1);  // baston dps 
            player->AddItem(159615, 1); // abalorio dps
        }
        if (player->getClass() == CLASS_ROGUE)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159334, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159324, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159309, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159968, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159303, ItemContext::NONE, true); //pecho 
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159338, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159331, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 155862, ItemContext::NONE, true); //pies 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 155881, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159623, ItemContext::NONE, true); //abalorio dps 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159131, ItemContext::NONE, true); //arma una mano
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 159131, ItemContext::NONE, true); //second adage
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 155884, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159461, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 158314, ItemContext::NONE, true); //dedo
            player->AddItem(159661, 1);  // maza una mano dps
            player->AddItem(159661, 1);  // maza una mano dps 1

        }
        if (player->getClass() == CLASS_SHAMAN)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159358, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159372, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159402, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 158317, ItemContext::NONE, true);// manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159362, ItemContext::NONE, true); //pecho 
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 155868, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159376, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 158308, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio healer 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159630, ItemContext::NONE, true); //abalorio healer 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 158369, ItemContext::NONE, true); //maza healer
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 159664, ItemContext::NONE, true); //escudo healer
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 158375, ItemContext::NONE, true); //capa 
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159461, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 158362, ItemContext::NONE, true); //dedo 
            player->AddItem(159652, 1);  // maza dps 
            player->AddItem(158713, 1);  // escudo dps
            player->AddItem(160269, 1);  // arma 1 mano dps
            player->AddItem(160269, 1);  // arma 1 mano dps 1
            player->AddItem(155881, 1);  // abalorio dps
            player->AddItem(159623, 1);  // abalorio dps 1 
        }
        if (player->getClass() == CLASS_WARLOCK)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159279, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159282, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 158346, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159237, ItemContext::NONE, true); //manos 
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159233, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159285, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159273, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 158303, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159615, ItemContext::NONE, true); //abalorio 	dps 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159636, ItemContext::NONE, true); //baston dps
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159294, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159462, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159463, ItemContext::NONE, true); //dedo  
            player->AddItem(158321, 1); // varita dps
            player->AddItem(158322, 1); // tomo dps
            player->AddItem(159630, 1); // abalorio dps 

        }
        if (player->getClass() == CLASS_WARRIOR)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 155866, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159229, ItemContext::NONE, true); //muecas 
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 160215, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159445, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159448, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159456, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159455, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159428, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159625, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159616, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159972, ItemContext::NONE, true); //arma 1 mano 
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 159638, ItemContext::NONE, true); //arma 1 mano
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159294, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158314, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159461, ItemContext::NONE, true); //dedo
            player->AddItem(159632, 1);  // maza tanke
            player->AddItem(159666, 1);  // escudo tanke
            player->AddItem(159618, 1);  // abalorio tanke
            player->AddItem(159626, 1);  // abalorio tanke 1
            player->AddItem(159644, 1);  // arma 2 manos dps

        }
        if (player->getClass() == CLASS_DEMON_HUNTER)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159364, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 160214, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 158306, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159321, ItemContext::NONE, true); //manos 
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159298, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159313, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159323, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159320, ItemContext::NONE, true); //pies 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 155881, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 158374, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 160110, ItemContext::NONE, true); //guja dps
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 160110, ItemContext::NONE, true); //guja dps
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159292, ItemContext::NONE, true); //capa 
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158362, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159297, ItemContext::NONE, true); //dedo
            player->AddItem(158714, 1);  // guja tanke
            player->AddItem(158714, 1);  // guja tanke
            player->AddItem(159618, 1);  // abalorio tanke
            player->AddItem(159626, 1);  // abalorio tanke 1
        }
        if (player->getClass() == CLASS_MONK)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 155888, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 160214, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159309, ItemContext::NONE, true); //cintura 
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 155889, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 155860, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159322, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159323, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159295, ItemContext::NONE, true); //pies 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 155881, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159623, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159661, ItemContext::NONE, true); //maza dps
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 159661, ItemContext::NONE, true); //maza dps
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159292, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158318, ItemContext::NONE, true); //dedos
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159314, ItemContext::NONE, true); //dedos
            player->AddItem(159656, 1);  // arma 2 manos tanke
            player->AddItem(159617, 1);  // abalorio tanke
            player->AddItem(159626, 1);  // abalorio tanke 1
            player->AddItem(159636, 1);  // baston manos healer
            player->AddItem(159630, 1);  // abalorio healer
            player->AddItem(159620, 1);  // abalorio healer 1
        }
        if (player->getClass() == CLASS_HUNTER)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159381, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159380, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159386, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159366, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159362, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159384, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159385, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 158308, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159623, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 155881, ItemContext::NONE, true); //abalorio dps 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159643, ItemContext::NONE, true); //arco
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159294, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158314, ItemContext::NONE, true); //dedo 
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159461, ItemContext::NONE, true); //dedo 
            player->AddItem(158370, 1);  // arma 2 manos dps

        }
        if (player->getClass() == CLASS_DRUID)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159310, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 160214, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159309, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159968, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159314, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 155869, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159299, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159295, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio heal
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159615, ItemContext::NONE, true); //abalorio heal 
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159636, ItemContext::NONE, true); //baston heal
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159294, ItemContext::NONE, true); //capa 
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 158366, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159462, ItemContext::NONE, true); //dedo
            player->AddItem(159642, 1);  // arma 2 manos tanke 
            player->AddItem(159626, 1);  // abalorio tanke
            player->AddItem(159618, 1);  // abalorio tanke 1
            player->AddItem(155881, 1);  // abalorio dps
            player->AddItem(159623, 1);  // abalorio dps 1
        }
        if (player->getClass() == CLASS_MAGE)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159252, ItemContext::NONE, true); //casco
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 159256, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159266, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159237, ItemContext::NONE, true); //manos 
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159233, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159242, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159238, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 158303, ItemContext::NONE, true); //pies 
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159620, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159615, ItemContext::NONE, true); //abalorio dps
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 158321, ItemContext::NONE, true); //varita dps
            player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 158322, ItemContext::NONE, true); //tomo dps
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159294, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159458, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159463, ItemContext::NONE, true); //dedo
        }
        if (player->getClass() == CLASS_DEATH_KNIGHT)
        {
            player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 159430, ItemContext::NONE, true); //casco 
            player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 160212, ItemContext::NONE, true); //muecas
            player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 159418, ItemContext::NONE, true); //cintura
            player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 159445, ItemContext::NONE, true); //manos
            player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 159448, ItemContext::NONE, true); //pecho
            player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 159456, ItemContext::NONE, true); //piernas
            player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 159455, ItemContext::NONE, true); //hombros
            player->EquipNewItem(EQUIPMENT_SLOT_FEET, 159420, ItemContext::NONE, true); //pies
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 159626, ItemContext::NONE, true); //abalorio tank                           
            player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 159618, ItemContext::NONE, true); //abalorio tank
            player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 159368, ItemContext::NONE, true); //arma 2 manos tank
            player->EquipNewItem(EQUIPMENT_SLOT_BACK, 159287, ItemContext::NONE, true); //capa
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 159459, ItemContext::NONE, true); //dedo
            player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 159462, ItemContext::NONE, true); //dedo
            player->AddItem(158373, 1);  // arma 1 mano dps
            player->AddItem(158373, 1);  // arma 1 mano dps
            player->AddItem(159625, 1);  // abalorio dps
            player->AddItem(159616, 1);  // abalorio dps 1
        }
        player->SaveToDB();
        player->SetLevel(lvlup);
        player->InitTalentForLevel();
        player->DestroyItemCount(item_id, 1, true);
        return true;

    }
};

class Battle_for_Azeroth_Pathfinder : public ItemScript
{
public:
    Battle_for_Azeroth_Pathfinder() : ItemScript("Battle_for_Azeroth_Pathfinder") { }

    enum
    {
        item_id = 789003, //Item Entry
    };

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        }

        player->LearnSpell(278833, true); // Abrecaminos de Battle for Azeroth
//        player->SendCustomMessage(sObjectMgr->GetTrinityStringForDBCLocale(789004));//tmp
        player->SaveToDB();
        player->DestroyItemCount(item_id, 1, true);
        return true;

    }
};

class Broken_Isles_Pathfinder : public ItemScript
{
public:
    Broken_Isles_Pathfinder() : ItemScript("Broken_Isles_Pathfinder") { }

    enum
    {
        item_id = 789004, //Item Entry
    };

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        }

        player->LearnSpell(233368, true); // Abrecaminos de las Islas Abruptas
        //player->SendCustomMessage(sObjectMgr->GetTrinityStringForDBCLocale(789003));//tmp
        player->SaveToDB();
        player->DestroyItemCount(item_id, 1, true);
        return true;
    }

};



class token_honor : public ItemScript
{
public:
    token_honor() : ItemScript("token_honor") { }

    enum
    {
        item_id = 789005, //Item Entry
    };

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        }

        player->RewardHonor(NULL, 0, 45000, false);
//        player->SendCustomMessage(sObjectMgr->GetTrinityStringForDBCLocale(789005));//tmp
        player->SaveToDB();
        player->DestroyItemCount(item_id, 1, true);
        return true;

    }
};

/*
class arwent_gift_mount : public PlayerScript
{
private:
    bool isEnabled = false;
    uint32 flySpell = 90265;
    uint32 mountSpell = 307932;
public:
    arwent_gift_mount() : PlayerScript("arwent_gift_mount") {}
    void OnLogin(Player* player, bool) {
        if (isEnabled) {
            if (!player->HasSpell(flySpell)) {
                player->LearnSpell(flySpell, false);
            }
            if (!player->HasSpell(mountSpell)) {
                player->LearnSpell(mountSpell, false);
            }
        }
    }
};
*/

/*
class heirloom_mount_tempfix : public PlayerScript {
private:
    const uint32 heirloomSpell = 179244;
    const int16 heirloomRequiredSize = 35;
    const uint32 heirloomAchievement = 9909;
public:
    heirloom_mount_tempfix() : PlayerScript("heirloom_mount_tempfix") {}
    void OnUpdate(Player* player, uint32) {
        if (!player->HasSpell(heirloomSpell)) {
            const CollectionMgr* sCollectionMgr = player->GetSession()->GetCollectionMgr();
            if (sCollectionMgr->GetAccountHeirlooms().size() == heirloomRequiredSize) {
                player->CompletedAchievement(heirloomAchievement);
                player->LearnSpell(heirloomSpell, false);
            }
        }
    }
};
*/

#define ACTION_RANDOM_MORPH 1003
#define ACTION_DEMORPH 1004

class npc_transmorpher_beacon : public CreatureScript 
{
public:
    npc_transmorpher_beacon() : CreatureScript("npc_transmorpher_beacon") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            CloseGossipMenuFor(player);
            player->GetSession()->SendNotification(sObjectMgr->GetTrinityStringForDBCLocale(789000));
            return false;
        } else {
           /* AddGossipItemFor(player, GOSSIP_ICON_TRANSMOGRIFIER, "Random morph", GOSSIP_SENDER_MAIN, ACTION_RANDOM_MORPH);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Demorph", GOSSIP_SENDER_MAIN, ACTION_DEMORPH);*/
            //tmp
            
            AddGossipItemFor(player, GossipOptionNpc::Transmogrify, "Random morph", GOSSIP_SENDER_MAIN, ACTION_RANDOM_MORPH);
            AddGossipItemFor(player, GossipOptionNpc::None, "Demorph", GOSSIP_SENDER_MAIN, ACTION_DEMORPH);

            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            return ItemContext::NONE, true;
        }
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == ACTION_RANDOM_MORPH)
        {        
            int list[] = {
                35739, // Admiral Ripsnarl
                32806, // Vanessa VanCleef
                40293, // Armsmaster Harlan
                41154, // Brother Korloff
                2043,  // High Inquisitor Whitemane
                2042,  // Scarlet Commander Mograine
                43460, // Jandice Barov
                40322, // Darkmaster Gandling
                9472,  // Lord Victor Nefarius
                17715, // Exarch Maladaar
                17153, // Keli'dan the Breaker
                19045, // High Botanist Freywinn
                18929, // Commander Sarannis
                18944, // Vazruden the Herald
                22906, // Kael'thas Sunstrider
                20033, // Pathaleon the Calculator
                19166, // Nethermancer Sepethrea
                18636, // Talon King Ikiss
                20599, // Darkweaver Syth
                16628, // Grand Warlock Nethekurse
                17728, // Mennu the Betrayer
                21254, // Teron Gorefiend
                21418, // Veras Darkshadow
                21417, // High Nethermancer Zerevor
                21416, // Gathios the Shatterer
                21419, // Lady Malande
                16621, // Shade of Aran
                19274, // Prince Malchezaar
                20514, // Leotheras the Blind
                23177, // Lady Sacrolash
                23334, // Grand Warlock Alythess
                18239, // High Astromancer Solarian
                20023, // Kael'thas Sunstrider
                27406, // Prince Taldaram
                26777, // Jedoga Shadowseeker
                26581, // Salramm the Fleshcrafter
                30226, // Bronjahm
                27061, // Gal'darah
                27059, // Moorabi
                27483, // Sjonnir The Ironshaper
                27301, // General Bjarngrim
                30972, // Falric
                30973, // Marwyn
                24066, // Grand Magus Telestra
                25010, // Mage-Lord Urom
                30277, // Scourgelord Tyrannus
                29616, // Eadric the Pure
                29837, // The Black Knight
                29490, // Argent Confessor Paletress
                21953, // Ingvar the Plunderer
                26349, // Dalronn the Controller
                25338, // Prince Keleseth
                27418, // Skadi the Ruthless
                28019, // King Ymiron
                30858, // Prince Valanar
                30857, // Prince Keleseth
                30856, // Prince Taldaram
                31165, // Blood-Queen Lana'thel
                30790, // Deathbringer Saurfang
                30881, // Professor Putricide
                16309, // Heigan the Unclean
                16582, // Instructor Razuvious
                16279, // Gothik the Harvester
                15940, // Grand Widow Faerlina
                16590, // Noth the Plaguebringer
                28324, // Stormcaller Brundir
                28381, // Runemaster Molgeim
                31546, // Corla, Herald of Twilight
                31792, // Drahga Shadowburner
                38995, // Asira Dawnslayer
                38991, // Archbishop Benedictus
                26448, // High Priestess Azil
                22332, // Hex Lord Malacrass
                21630, // Akil'zon
                38118, // Daakara <The Invincible>
                39318, // Hagara the Stormbinder
                39399, // Warmaster Blackhorn
                37953, // Majordomo Staghelm
                46071, // Master Snowdrift
                39489, // Gu Cloudstrike
                41121, // Taran Zhu
                41125, // Wise Mari
                48918, // Rook Stonetoe
                49176, // Earthbreaker Haromm
                48995, // General Nazgrim
                48919, // Sun Tenderheart
                47730, // High Priestess Mar'li
                47229, // Kazra'jin
                47505, // Sul the Sandcrawler
                58912, // Ner'zhul
                53519, // Operator Thogar
                53499, // Beastlord Darmac
                53791, // Blackhand
                65794, // Advisor Vandros
                67346, // Advisor Melandrus
                73162, // Attumen the Huntsman
                67422, // Millificent Manastorm
                69082, // Elisande
                80382  // Skycap'n Kragg
            };

            int randomIdModel = rand() % (sizeof(list) / sizeof(list[0])); // random model
            int value = list[randomIdModel]; // a random model taken from that list

            CloseGossipMenuFor(player);
            player->SetDisplayId(value);
            player->CastSpell(player, 228558, true); // visual effect
        }

        if (action == ACTION_DEMORPH)
        {
            CloseGossipMenuFor(player);
            player->DeMorph();
        }

        return ItemContext::NONE, true;
    }
};

enum
{
    PetBattleTrainerFightActionID = GOSSIP_ACTION_INFO_DEF + 0xABCD
};

class npc_PetBattleTrainer : public CreatureScript
{
public:
    npc_PetBattleTrainer() : CreatureScript("npc_PetBattleTrainer") { }

    struct npc_PetBattleTrainerAI : CreatureAI
    {
        bool isTrainer;
        std::set<uint32> questIDs{};

        npc_PetBattleTrainerAI(Creature* me) : CreatureAI(me)
        {
            isTrainer = false;

            if (sBattlePetDataStore->GetPetBattleTrainerTeam(me->GetEntry()).empty())
                return;

        //    for (auto const& v : sQuestDataStore->GetQuestObjectivesByType(QUEST_OBJECTIVE_PET_TRAINER_DEFEAT))
            //    if (v.ObjectID == me->GetEntry())
             //   {
               //     isTrainer = true;
               //     questIDs.insert(v.QuestID);
              //  }
        }

        void UpdateAI(uint32 /*diff*/) override { }

        bool OnGossipHello(Player* player) override //原先为override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (isTrainer)
            {
                bool check = false;
                for (auto questID : questIDs)
                    if (player->GetQuestStatus(questID) == QUEST_STATUS_INCOMPLETE)
                    {
                        check = true;
                        break;
                    }
                if (check)
                    if (BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(62660))
                        AddGossipItemFor(player, GossipOptionNpc::None, DB2Manager::GetBroadcastTextValue(bct, player->GetSession()->GetSessionDbLocaleIndex()), GOSSIP_SENDER_MAIN, PetBattleTrainerFightActionID);
            }

            player->TalkedToCreature(me->GetEntry(), me->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) //override    //原先为override
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == PetBattleTrainerFightActionID)
        {
            CloseGossipMenuFor(player);

            static float distance = 10.0f;

         //   float l_X = creature->m_positionX + (std::cos(creature->m_orientation) * distance);
         //   float l_Y = creature->m_positionY + (std::sin(creature->m_orientation) * distance);
         //   float l_Z = player->GetMap()->GetHeight(l_X, l_Y, MAX_HEIGHT);

          //  Position playerPosition = Position(l_X, l_Y, l_Z);
          //  playerPosition.m_orientation = atan2(creature->m_positionY - l_Y, creature->m_positionX - l_X);
          //  playerPosition.m_orientation = (playerPosition.m_orientation >= 0.0f) ? playerPosition.m_orientation : 2 * M_PI + playerPosition.m_orientation;

         //   Position trainerPosition = Position(creature->m_positionX, creature->m_positionY, creature->m_positionZ, creature->m_orientation);

            //Position battleCenterPosition = Position((playerPosition.m_positionX + trainerPosition.m_positionX) / 2, (playerPosition.m_positionY + trainerPosition.m_positionY) / 2, 0.0f, trainerPosition.m_orientation + M_PI);
           // battleCenterPosition.m_positionZ = player->GetMap()->GetHeight(battleCenterPosition.m_positionX, battleCenterPosition.m_positionY, MAX_HEIGHT);

            PetBattleRequest* battleRequest = sPetBattleSystem->CreateRequest(player->GetGUID());
            battleRequest->OpponentGuid = creature->GetGUID();
          //  battleRequest->PetBattleCenterPosition = battleCenterPosition;
        //    battleRequest->TeamPosition[PETBATTLE_TEAM_1] = playerPosition;
        //    battleRequest->TeamPosition[PETBATTLE_TEAM_2] = trainerPosition;
          //  battleRequest->RequestType = PETBATTLE_TYPE_PVE;

            eBattlePetRequests canEnterResult = sPetBattleSystem->CanPlayerEnterInPetBattle(player, battleRequest);
            if (canEnterResult != BATTLE_PET_REQUEST_OK)
            {
                player->GetSession()->SendPetBattleRequestFailed(canEnterResult);
                sPetBattleSystem->RemoveRequest(battleRequest->RequesterGuid);
                return true;
            }

            std::shared_ptr<BattlePetInstance> playerPets[MAX_PET_BATTLE_SLOTS];
            std::shared_ptr<BattlePetInstance> wildBattlePets[MAX_PET_BATTLE_SLOTS];

            for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
            {
                playerPets[i] = nullptr;
                wildBattlePets[i] = nullptr;
            }

            uint32 wildsPetCount = 0;
            for (BattlePetNpcTeamMember& v : sBattlePetDataStore->GetPetBattleTrainerTeam(creature->GetEntry()))
            {
                if (wildsPetCount >= MAX_PET_BATTLE_SLOTS)
                    break;

                auto battlePetInstance = std::make_shared<BattlePetInstance>();

                uint32 l_DisplayID = 0;

            //    if (sBattlePetSpeciesStore.LookupEntry(v.Specie) && sObjectMgr->GetCreatureTemplate(sBattlePetSpeciesStore.LookupEntry(v.Specie)->CreatureID))
             //   {
                  //  l_DisplayID = sObjectMgr->GetCreatureTemplate(sBattlePetSpeciesStore.LookupEntry(v.Specie)->CreatureID)->model[0];

                 //   if (!l_DisplayID)
                  //  {
                       // l_DisplayID = sObjectMgr->GetCreatureTemplate(sBattlePetSpeciesStore.LookupEntry(v.Specie)->CreatureID)->Modelid[1];

                       /* if (!l_DisplayID)
                        {
                            l_DisplayID = sObjectMgr->GetCreatureTemplate(sBattlePetSpeciesStore.LookupEntry(v.Specie)->CreatureID)->Modelid[2];
                            if (!l_DisplayID)
                                l_DisplayID = sObjectMgr->GetCreatureTemplate(sBattlePetSpeciesStore.LookupEntry(v.Specie)->CreatureID)->Modelid[3];
                        }*/
                  //  }
            //    }

                battlePetInstance->JournalID.Clear();
                battlePetInstance->Slot = 0;
                battlePetInstance->NameTimeStamp = 0;
                battlePetInstance->Species = v.Specie;
                battlePetInstance->DisplayModelID = l_DisplayID;
                battlePetInstance->XP = 0;
                battlePetInstance->Flags = 0;
                battlePetInstance->Health = 20000;

                uint8 randQuality = sBattlePetDataStore->GetRandomQuailty();
                battlePetInstance->Quality = v.minquality > randQuality ? v.minquality : randQuality;
                battlePetInstance->Breed = sBattlePetDataStore->GetRandomBreedID(v.BreedIDs);
                battlePetInstance->Level = std::max(urand(v.minlevel, v.maxlevel), static_cast<uint32>(1));

                for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
                    battlePetInstance->Abilities[i] = v.Ability[i];

                wildBattlePets[wildsPetCount] = battlePetInstance;
                wildBattlePets[wildsPetCount]->OriginalCreature.Clear();
                wildsPetCount++;
            }

            size_t playerPetCount = 0;
            std::shared_ptr<BattlePet>* petSlots = player->GetBattlePetCombatTeam();
            for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
            {
                if (!petSlots[i])
                    continue;

                if (playerPetCount >= MAX_PET_BATTLE_SLOTS || playerPetCount >= player->GetUnlockedPetBattleSlot())
                    break;

                playerPets[playerPetCount] = std::make_shared<BattlePetInstance>();
//                playerPets[playerPetCount]->CloneFrom(petSlots[i]);//tmp
                playerPets[playerPetCount]->Slot = playerPetCount;
                playerPets[playerPetCount]->OriginalBattlePet = petSlots[i];

                ++playerPetCount;
            }

            player->GetSession()->SendPetBattleFinalizeLocation(battleRequest);

            PetBattle* petBattle = sPetBattleSystem->CreateBattle();

            petBattle->Teams[PET_BATTLE_TEAM_1]->OwnerGuid = player->GetGUID();
            petBattle->Teams[PET_BATTLE_TEAM_1]->PlayerGuid = player->GetGUID();
            petBattle->Teams[PET_BATTLE_TEAM_2]->OwnerGuid = creature->GetGUID();

            for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
            {
                if (playerPets[i])
                    petBattle->AddPet(PET_BATTLE_TEAM_1, playerPets[i]);

                if (wildBattlePets[i])
                    petBattle->AddPet(PET_BATTLE_TEAM_2, wildBattlePets[i]);
            }

            petBattle->BattleType = battleRequest->RequestType;
          //  petBattle->PveBattleType = PVE_PET_BATTLE_TRAINER;

            player->_petBattleId = petBattle->ID;

            sPetBattleSystem->RemoveRequest(battleRequest->RequesterGuid);

            for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
            {
                if (playerPets[i])
                    playerPets[i] = nullptr;

                if (wildBattlePets[i])
                    wildBattlePets[i] = nullptr;
            }

        //    player->GetMotionMaster()->MovePointWithRot(PETBATTLE_ENTER_MOVE_SPLINE_ID, playerPosition.m_positionX, playerPosition.m_positionY, playerPosition.m_positionZ, playerPosition.m_orientation);
        }
        else
        CloseGossipMenuFor(player);

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_PetBattleTrainerAI(creature);
    }
};

class arwent_gift_mount : public PlayerScript
{
private:
    bool isEnabled = false;
    uint32 flySpell = 90265; /* Matre cavalier */
    uint32 mountSpell = 307932; /* Wyrm ternel ensorcel */

public:
    arwent_gift_mount() : PlayerScript("arwent_gift_mount") {}

    void OnLogin(Player* player, bool /*firstLogin*/) {
        if (isEnabled) {
            if (!player->HasSpell(flySpell))
            {
                player->LearnSpell(flySpell, false);
            }

            if (!player->HasSpell(mountSpell))
            {
                player->LearnSpell(mountSpell, false);
                player->LearnSpell(309452, false);
            }
        }
    }
};


void AddSC_custom_npcs()
{
    new npc_rate_xp_modifier();
    new npc_anachronos();
    new item_level_boost();
    new Broken_Isles_Pathfinder();
    new Battle_for_Azeroth_Pathfinder();
    new item_level_boost120();
    new token_honor();
    new npc_hallegosa();
    RegisterCreatureAI(npc_kalecgos_for_teracgosa);
    new npc_transmorpher_beacon();
    new npc_PetBattleTrainer;
    new arwent_gift_mount();
    //new arwent_gift_mount();
//new heirloom_mount_tempfix();
}
