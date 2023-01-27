/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "well_of_eternity.h"
#include "ScriptedGossip.h"
#include "GridNotifiers.h"

#define MAX_DOOMGUARDS 15

enum ScriptedTextNozdormu
{
    SAY_NOZDORMU_EVENT_1        = 0,
    SAY_NOZDORMU_INTRO_1        = 1,
    SAY_NOZDORMU_INTRO_2        = 2,
    SAY_NOZDORMU_INTRO_3        = 3,
    SAY_NOZDORMU_INTRO_4        = 4,

    SAY_ILLIDAN_HIDE            = 0,
    SAY_ILLIDAN_1_AGGRO         = 1,
    SAY_ILLIDAN_1_NEAR          = 2,
    SAY_ILLIDAN_1_OUTRO_1       = 3,
    SAY_ILLIDAN_1_OUTRO_2       = 4,
    SAY_ILLIDAN_1_SPELL         = 5,
    SAY_ILLIDAN_1_MOVE          = 13,
    SAY_ILLIDAN_1_INTRO         = 24,

    SAY_ILLIDAN_2_INTRO_1       = 4,
    SAY_ILLIDAN_2_INTRO_2       = 5,
    SAY_ILLIDAN_2_INTRO_3       = 6,
    SAY_ILLIDAN_2_DEMONS        = 8,
    SAY_ILLIDAN_2_ELEMENTAL_1   = 9,
    SAY_ILLIDAN_2_ELEMENTAL_2   = 10,
    SAY_ILLIDAN_2_ELEMENTAL_3   = 11,
    SAY_ILLIDAN_2_ELEMENTAL_4   = 12,
    SAY_ILLIDAN_2_VAROTHEN      = 14,
    SAY_ILLIDAN_2_SWORD         = 15,
    SAY_ILLIDAN_2_BUFF_1        = 16,
    SAY_ILLIDAN_2_BUFF_2        = 17,
    SAY_ILLIDAN_2_BUFF_3        = 18,
    SAY_ILLIDAN_2_SPELL         = 19,

    SAY_MALFURION_INTRO_1       = 4,
    SAY_MALFURION_INTRO_2       = 5,

    SAY_TYRANDE_INTRO_1         = 3,
    SAY_TYRANDE_INTRO_2         = 4,
    SAY_TYRANDE_ELEMENTAL       = 5,
    SAY_TYRANDE_DEMONS          = 7,
    SAY_TYRANDE_ELUNE           = 8,
    SAY_TYRANDE_CONTINUE        = 9,
    SAY_TYRANDE_ARROWS          = 10,
    SAY_TYRANDE_NO_1            = 11,
    SAY_TYRANDE_NO_2            = 12,
    SAY_TYRANDE_MALFURION       = 13,
    SAY_TYRANDE_MANY_DEMONS     = 14,
};

enum Spells
{
    // Legion Demon
    SPELL_STRIKE_FEAR           = 103913,
    SPELL_CRUSHING_LEAP         = 108474,
    SPELL_CRUSHING_LEAP_DMG     = 108479,
    SPELL_CRUSHING_LEAP_VISUAL  = 108481,

    // Illidan 1
    SPELL_RETURN_TO_THE_SHADOWS = 105635,
    SPELL_SHADOW_CLOAK          = 103004,
    SPELL_SHADOW_WALK_AURA      = 102994,
    SPELL_SHADOW_WALK_DUMMY     = 103020,

    // Eternal Champion
    SPELL_QUEENS_BLADE          = 102260,
    SPELL_SHIMMERING_STRIKE     = 102257,

    // Eye of Legion
    SPELL_FEL_FLAMES            = 102356,

    // Enchanted Highmistress
    SPELL_FIREBALL              = 102265,
    SPELL_FIREBOMB              = 102263,
    SPELL_FROSTBOLT             = 102266,
    SPELL_BLIZZARD              = 102267,

    // Royal Handmaiden
    SPELL_SWEET_LULLABY         = 120245,

    // Illidan 2
    SPELL_WATERS_OF_ETERNITY    = 103952,
    SPELL_TAUNT                 = 104461,
    SPELL_DEMON_RUSH            = 104205,
    SPELL_DARKLANCE             = 104394,
    SPELL_AURA_OF_IMMOLATION    = 104379,
    SPELL_GIFT_OF_SARGERAS      = 104998,
    SPELL_GIFT_OF_SARGERAS_AOE  = 105009,

    // Tyrande
    SPELL_BLESSING_OF_ELUNE     = 103917,
    SPELL_HAND_OF_ELUNE         = 105072,
    SPELL_WRATH_OF_ELUNE_1      = 105073, // 30k damage
    SPELL_WRATH_OF_ELUNE_2      = 105075, // 300k damage
    SPELL_LUNAR_SHOT_1          = 104214, // 30k damage, single
    SPELL_LUNAR_SHOT_2          = 104313, // 300k damage, single
    SPELL_LUNAR_SHOT_3          = 104688, // 300k damage, aoe

    // Abyssal Doombringer
    SPELL_ABYSSAL_FLAMES        = 103992,

    // Doomguard Debilitator
    SPELL_DEBILITATING_FLAY         = 104678,
};

enum Events
{
    // Nozdormu
    EVENT_NOZDORMU_TALK_1   = 1,
    EVENT_NOZDORMU_TALK_2   = 2,
    EVENT_NOZDORMU_TALK_3   = 3,
    EVENT_NOZDORMU_TALK_4   = 4,

    // Legion Demon
    EVENT_STRIKE_FEAR       = 5,
    EVENT_CRUSHING_LEAP     = 6,

    // Illidan 1
    EVENT_ILLIDAN_MOVE_1_3  = 7,
    EVENT_ILLIDAN_MOVE_1_4  = 8,
    EVENT_ILLIDAN_MOVE_1_5  = 9,
    EVENT_ILLIDAN_MOVE_1_6  = 10,
    EVENT_ILLIDAN_START_1_1 = 11,
    EVENT_ILLIDAN_START_1_2 = 12,
    EVENT_ILLIDAN_START_1_3 = 13,
    EVENT_ILLIDAN_OUTRO_1_1 = 14,
    EVENT_ILLIDAN_OUTRO_1_2 = 15,

    // Eternal Champion
    EVENT_QUEENS_BLADE      = 16,
    EVENT_SHIMMERING_STRIKE = 17,

    // Eye of Legion
    EVENT_FEL_FLAMES        = 18,

    // Enchanted Highmistress
    EVENT_FIREBALL          = 20,
    EVENT_FIREBOMB          = 21,
    EVENT_FROSTBOLT         = 22,
    EVENT_BLIZZARD          = 23,

    // Royal Handmaiden
    EVENT_SWEET_LULLABY     = 24,

    // Illidan 2
    EVENT_MALFURION_INTRO_1         = 25,
    EVENT_MALFURION_INTRO_2         = 26,
    EVENT_ILLIDAN_INTRO_2_2         = 27,
    EVENT_TYRANDE_INTRO_1           = 28,
    EVENT_ILLIDAN_INTRO_2_3         = 29,
    EVENT_TYRANDE_INTRO_2           = 30,
    EVENT_ILLIDAN_MOVE_2_1          = 31,
    EVENT_ILLIDAN_MOVE_2_2          = 32,
    EVENT_ILLIDAN_MOVE_2_3          = 33,
    EVENT_ILLIDAN_MOVE_2_4          = 34,
    EVENT_ILLIDAN_MOVE_2_5          = 35,
    EVENT_ILLIDAN_MOVE_2_6          = 36,
    EVENT_ILLIDAN_NEAR_ELEMENTAL_1  = 37,
    EVENT_ILLIDAN_NEAR_ELEMENTAL_2  = 38,
    EVENT_TYRANDE_NEAR_ELEMENTAL_1  = 39,
    EVENT_ILLIDAN_NEAR_ELEMENTAL_3  = 40,
    EVENT_ILLIDAN_NEAR_ELEMENTAL_4  = 41,
    EVENT_ILLIDAN_NEAR_ELEMENTAL_5  = 42,
    EVENT_ILLIDAN_MOVE_2_7          = 43,
    EVENT_ILLIDAN_MOVE_2_8          = 44,
    EVENT_ILLIDAN_MOVE_2_9          = 45,
    EVENT_TYRANDE_MOVE_1            = 46,
    EVENT_TYRANDE_MOVE_2            = 47,
    EVENT_TYRANDE_SHOT              = 48,
    EVENT_HAND_OF_ELUNE             = 49,

    // Abyssal Doombringer
    EVENT_ABYSSAL_FLAMES            = 49,
};

enum Adds
{
    NPC_NOZDORMU                    = 55624,
    NPC_LEGION_DEMON                = 55503,

    // legion demon 54500
    // guardian demon 54927
    // stalker after illidan's shadowcloak (visual) 55154 with 102951 aura
    // portal stalkers 54513 with auras 102456 101856
    // portal stalker 55965
    // stalker near illidan and portals 56389 (green mark)  with aura 105924
    // stalker 54506 after peroth'arn has aura 102456 (portal status: active) while demons are coming

    NPC_ETERNAL_CHAMPION            = 54612,
    NPC_EYE_OF_LEGION               = 54747,
    NPC_ENCHANTED_HIGHMISTRESS_1    = 56579,
    NPC_ENCHANTED_HIGHMISTRESS_2    = 54589,
    NPC_ROYAL_HANDMAIDEN            = 54645,

    // isera 55393
    // alextraza 55394
    // bronze dragon 55391
    // shadowbat 57458
    // nozdormu 56102
    // soridormi 55395
    // red dragon 55366
    // green dragon 55390
    // the dragon soul 55078 aura 102845
    // portal to twisting nether 56087 aura 102918
    // shadowbat + highguard elite 55463 + 55426
};

enum Points
{
    POINT_ILLIDAN_1_1   = 1,
    POINT_ILLIDAN_1_2   = 2,
    POINT_ILLIDAN_1_3   = 3,
    POINT_ILLIDAN_1_4   = 4,
    POINT_ILLIDAN_1_5   = 5,
    POINT_ILLIDAN_1_6   = 6,
    POINT_ILLIDAN_2_1   = 7,
    POINT_ILLIDAN_2_2   = 8,
    POINT_ILLIDAN_2_3   = 9,
    POINT_ILLIDAN_2_4   = 10,
    POINT_ILLIDAN_2_5   = 11,
    POINT_ILLIDAN_2_6   = 12,
    POINT_ILLIDAN_2_7   = 13,
    POINT_ILLIDAN_2_8   = 14,
    POINT_ILLIDAN_2_9   = 15,
    POINT_ILLIDAN_2_10  = 16,
    POINT_TYRANDE_1     = 17,
    POINT_TYRANDE_2     = 18,
    POINT_TYRANDE_3     = 19,
};

enum Actions
{
    ACTION_PEROTHARN_DEAD       = 1,
    ACTION_DOOMGUARD_DIED       = 2,
    ACTION_DOOMBRINGER_DIED     = 3,
    ACTION_TYRANDE_MOVE_1       = 4,
    ACTION_TYRANDE_MOVE_2       = 5,
    ACTION_MANNOROTH_AGGRO      = 6,
    ACTION_MANNOROTH_RESET      = 7,
    ACTION_DEBILITATING_OFF     = 8,
    ACTION_MANNOROTH_SARGERAS   = 9,
    ACTION_MANNOROTH_INFERNO    = 10,
    ACTION_MANNOROTH_END        = 11,
};

/*
{3294.199951f, -4981.970215f, 181.160004f, 0.8f} // illidan near 1 portal
{3444.979980f, -4886.339844f, 181.160004f, 4.0f} // illidan near 2 portal
{3471.120117f, -4839.830078f, 194.214996f, 2.0f} // illidan near 3 portal

*/

const Position illidan1Pos[6] =
{
    {3191.901123f, -4890.239258f, 194.357269f, 0.0f},
    {3217.059814f, -4902.321777f, 194.179321f, 0.0f},
    {3242.290527f, -4901.905273f, 180.980728f, 0.0f},
    {3286.567139f, -4898.600098f, 181.077377f, 0.0f},
    {3327.890137f, -4892.302246f, 181.077682f, 0.0f},
    {3362.441162f, -4934.355957f, 181.077682f, 0.0f},
};

const Position illidan2Pos[10] =
{
    {3159.834961f, -5572.989746f, 18.292067f, 0.0f},
    {3168.384766f, -5581.995605f, 18.055605f, 0.0f},
    {3177.702148f, -5598.211426f, 17.121992f, 0.0f},
    {3184.541748f, -5616.823242f, 17.969137f, 0.0f},
    {3192.839844f, -5638.349121f, 18.085392f, 0.0f},
    {3205.317871f, -5666.366211f, 18.083393f, 0.0f},  // near elemental
    {3219.282227f, -5683.890137f, 18.111153f, 0.0f},  // attack elemental
    {3259.732178f, -5703.202637f, 17.23f,     6.15f}, // after elemental
    {3281.667236f, -5706.658203f, 16.42f,     6.09f}, // near varo'then
    {3339.285889f, -5730.857910f, 15.23f,     5.64f}  // near mannoroth
};

const Position tyrandePos ={3310.190674f, -5691.714355f, 14.78f, 1.78f};

class npc_well_of_eternity_nozdormu : public CreatureScript
{
public:
    npc_well_of_eternity_nozdormu() : CreatureScript("npc_well_of_eternity_nozdormu") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_nozdormuAI(pCreature);
    }

    struct npc_well_of_eternity_nozdormuAI : public ScriptedAI
    {
        npc_well_of_eternity_nozdormuAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
            bTalk = false;
            pInstance = me->GetInstanceScript();
            npc_id = ((me->GetPositionX() > 3200.0f) ? 1 : 0);
        }

        void Reset() override
        {
            events.Reset();
            if (npc_id == 1)
                if (pInstance && pInstance->GetData(DATA_EVENT_NOZDORMU) == DONE)
                    me->DespawnOrUnsummon(500);

        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (npc_id != 1 || bTalk || !pInstance)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!who->ToPlayer()->IsInWorld() || who->ToPlayer()->IsBeingTeleported())
                return;

            if (me->GetDistance(who) > 5.0f)
                return;

            bTalk = true;

            events.ScheduleEvent(EVENT_NOZDORMU_TALK_1, 5000);

            pInstance->SetData(DATA_EVENT_NOZDORMU, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!bTalk)
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_NOZDORMU_TALK_1:
                    Talk(SAY_NOZDORMU_INTRO_1);
                    events.ScheduleEvent(EVENT_NOZDORMU_TALK_2, 12000);
                    break;
                case EVENT_NOZDORMU_TALK_2:
                    Talk(SAY_NOZDORMU_INTRO_2);
                    events.ScheduleEvent(EVENT_NOZDORMU_TALK_3, 7000);
                    break;
                case EVENT_NOZDORMU_TALK_3:
                    Talk(SAY_NOZDORMU_INTRO_3);
                    events.ScheduleEvent(EVENT_NOZDORMU_TALK_4, 14000);
                    break;
                case EVENT_NOZDORMU_TALK_4:
                    Talk(SAY_NOZDORMU_INTRO_4);
                    if (pInstance)
                        pInstance->SetData(DATA_EVENT_NOZDORMU, DONE);
                    me->DespawnOrUnsummon(500);
                    break;
                }
            }
        }

    private:
        bool bTalk;
        uint8 npc_id;
        EventMap events;
        InstanceScript* pInstance;
    };
};

class npc_well_of_eternity_legion_demon : public CreatureScript
{
public:
    npc_well_of_eternity_legion_demon() : CreatureScript("npc_well_of_eternity_legion_demon") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_legion_demonAI(pCreature);
    }

    struct npc_well_of_eternity_legion_demonAI : public ScriptedAI
    {
        npc_well_of_eternity_legion_demonAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            pInstance = me->GetInstanceScript();
            npc_id = ((me->GetPositionX() <= 3200.0f) ? 1 : 0);
        }

        void Reset() override
        {
            events.Reset();
            if (npc_id == 1)
                if (pInstance && pInstance->GetData(DATA_EVENT_DEMON) == DONE)
                    me->DespawnOrUnsummon(500);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_STRIKE_FEAR, urand(5000, 7000));
            //DoCast(who, SPELL_CRUSHING_LEAP);
        }

        void SpellHit(Unit* who, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_ARCHIVED_DEMON_1)
                DoCast(who, SPELL_ARCHIVED_DEMON_2, true);
        }

        void MovementInform(uint32 /*type*/, uint32 data) override
        {
            if (data == EVENT_JUMP)
            {
                DoCastAOE(SPELL_CRUSHING_LEAP_DMG, true);
                DoCastAOE(SPELL_CRUSHING_LEAP_VISUAL, true);
            }
        }

        void JustDied(Unit* /*who*/) override
        {
            if (npc_id)
                if (pInstance)
                    pInstance->SetData(DATA_EVENT_DEMON, DONE);

            // Quest
            if (!pInstance)
                return;

            Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* pPlayer = i->GetSource())
                        if (me->GetDistance(pPlayer) <= 50.0f && pPlayer->GetQuestStatus(QUEST_DOCUMENTING_THE_TIMEWAYS) == QUEST_STATUS_INCOMPLETE)
                            pPlayer->CastSpell(me, SPELL_ARCHIVED_DEMON_1, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STRIKE_FEAR:
                    DoCastAOE(SPELL_STRIKE_FEAR);
                    events.ScheduleEvent(EVENT_STRIKE_FEAR, urand(10000, 15000));
                    break;
                case EVENT_CRUSHING_LEAP:
                    //if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    //    DoCastVictim(SPELL_CRUSHING_LEAP);
                    events.ScheduleEvent(EVENT_STRIKE_FEAR, urand(15000, 20000));
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint8 npc_id;
        EventMap events;
        InstanceScript* pInstance;
    };
};

class npc_well_of_eternity_illidan_1 : public CreatureScript
{
public:
    npc_well_of_eternity_illidan_1() : CreatureScript("npc_well_of_eternity_illidan_1") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_illidan_1AI(pCreature);
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*sender*/, uint32 /*action*/) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        pCreature->AI()->Talk(SAY_ILLIDAN_1_MOVE);
        pCreature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        pCreature->SetSpeed(MOVE_RUN, 1.0f);
        pCreature->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_2, illidan1Pos[1]);

        if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            pInstance->SetData(DATA_EVENT_ILLIDAN_1, IN_PROGRESS);
        return true;
    }

    struct npc_well_of_eternity_illidan_1AI : public ScriptedAI
    {
        npc_well_of_eternity_illidan_1AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
            bTalk = false;
            curPoint = 0;
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            pInstance = me->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
            if (pInstance)
                if (pInstance->GetData(DATA_EVENT_ILLIDAN_1) == DONE)
                    me->DespawnOrUnsummon(500);
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (who->GetGUID() == me->GetGUID())
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (bTalk || !pInstance)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 40.0f)
                return;

            bTalk = true;

            Talk(SAY_ILLIDAN_1_INTRO);

            me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_1, illidan1Pos[0]);
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (data)
                {
                case POINT_ILLIDAN_1_1:
                    curPoint = 1;
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    break;
                case POINT_ILLIDAN_1_2:
                    curPoint = 2;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_1_3, 100);
                    break;
                case POINT_ILLIDAN_1_3:
                    curPoint = 3;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_1_4, 100);
                    break;
                case POINT_ILLIDAN_1_4:
                    curPoint = 4;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_1_5, 100);
                    break;
                case POINT_ILLIDAN_1_5:
                    curPoint = 5;
                    curPoint = 6;
                    if (pInstance)
                        if (Creature* pPerotharn = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_PEROTHARN)))
                            pPerotharn->AI()->Talk(9); // SAY_INTRO
                    events.ScheduleEvent(EVENT_ILLIDAN_START_1_1, 10000);
                    break;
                case POINT_ILLIDAN_1_6:
                    me->DespawnOrUnsummon(500);
                    break;
                default:
                    break;
                }
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_PEROTHARN_DEAD)
                events.ScheduleEvent(EVENT_ILLIDAN_OUTRO_1_1, 6000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!bTalk)
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ILLIDAN_MOVE_1_3:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_3, illidan1Pos[2]);
                    break;
                case EVENT_ILLIDAN_MOVE_1_4:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_4, illidan1Pos[3]);
                    break;
                case EVENT_ILLIDAN_MOVE_1_5:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_5, illidan1Pos[4]);
                    break;
                case EVENT_ILLIDAN_MOVE_1_6:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_1_6, illidan1Pos[5]);
                    break;
                case EVENT_ILLIDAN_START_1_1:
                    Talk(SAY_ILLIDAN_1_NEAR);
                    events.ScheduleEvent(EVENT_ILLIDAN_START_1_2, 8000);
                    break;
                case EVENT_ILLIDAN_START_1_2:
                    if (pInstance)
                    {
                        if (Creature* pPerotharn = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_PEROTHARN)))
                            pPerotharn->AI()->DoAction(1); // ACTION_START
                    }
                    break;
                case EVENT_ILLIDAN_OUTRO_1_1:
                    Talk(SAY_ILLIDAN_1_OUTRO_1);
                    events.ScheduleEvent(EVENT_ILLIDAN_OUTRO_1_2, 5000);
                    break;
                case EVENT_ILLIDAN_OUTRO_1_2:
                    Talk(SAY_ILLIDAN_1_OUTRO_2);
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_1_6, 2000);
                    break;
                default:
                    break;
                }
            }
        }

    private:
        bool bTalk;
        EventMap events;
        InstanceScript* pInstance;
        uint8 curPoint;
    };
};

class npc_well_of_eternity_eternal_champion : public CreatureScript
{
public:
    npc_well_of_eternity_eternal_champion() : CreatureScript("npc_well_of_eternity_eternal_champion") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_eternal_championAI(pCreature);
    }

    struct npc_well_of_eternity_eternal_championAI : public ScriptedAI
    {
        npc_well_of_eternity_eternal_championAI(Creature* pCreature) : ScriptedAI(pCreature)
        { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_QUEENS_BLADE, urand(2000, 6000));
            events.ScheduleEvent(EVENT_SHIMMERING_STRIKE, urand(9000, 12000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_QUEENS_BLADE:
                    DoCastVictim(SPELL_QUEENS_BLADE);
                    events.ScheduleEvent(EVENT_QUEENS_BLADE, urand(6000, 8000));
                    break;
                case EVENT_SHIMMERING_STRIKE:
                    DoCastAOE(SPELL_SHIMMERING_STRIKE);
                    events.ScheduleEvent(EVENT_SHIMMERING_STRIKE, urand(12000, 15000));
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class npc_well_of_eternity_eye_of_legion : public CreatureScript
{
public:
    npc_well_of_eternity_eye_of_legion() : CreatureScript("npc_well_of_eternity_eye_of_legion") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_eye_of_legionAI(pCreature);
    }

    struct npc_well_of_eternity_eye_of_legionAI : public ScriptedAI
    {
        npc_well_of_eternity_eye_of_legionAI(Creature* pCreature) : ScriptedAI(pCreature)
        { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_FEL_FLAMES, urand(2000, 10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FEL_FLAMES:
                    DoCastVictim(SPELL_FEL_FLAMES);
                    events.ScheduleEvent(EVENT_FEL_FLAMES, urand(10000, 15000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class npc_well_of_eternity_enchanted_highmistress : public CreatureScript
{
public:
    npc_well_of_eternity_enchanted_highmistress() : CreatureScript("npc_well_of_eternity_enchanted_highmistress") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_enchanted_highmistressAI(pCreature);
    }

    struct npc_well_of_eternity_enchanted_highmistressAI : public ScriptedAI
    {
        npc_well_of_eternity_enchanted_highmistressAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (me->GetEntry() == NPC_ENCHANTED_HIGHMISTRESS_1)
            {
                events.ScheduleEvent(EVENT_FIREBALL, 1);
                events.ScheduleEvent(EVENT_FIREBOMB, urand(7000, 12000));
            } else if (me->GetEntry() == NPC_ENCHANTED_HIGHMISTRESS_2)
            {
                events.ScheduleEvent(EVENT_FROSTBOLT, 1);
                events.ScheduleEvent(EVENT_BLIZZARD, urand(7000, 12000));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 2000);
                    break;
                case EVENT_FIREBOMB:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_FIREBOMB);
                    events.ScheduleEvent(EVENT_FIREBOMB, urand(10000, 15000));
                    break;
                case EVENT_FROSTBOLT:
                    DoCastVictim(SPELL_FROSTBOLT);
                    events.ScheduleEvent(EVENT_FROSTBOLT, 2000);
                    break;
                case EVENT_BLIZZARD:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_BLIZZARD);
                    events.ScheduleEvent(EVENT_BLIZZARD, urand(20000, 25000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class npc_well_of_eternity_royal_handmaiden : public CreatureScript
{
public:
    npc_well_of_eternity_royal_handmaiden() : CreatureScript("npc_well_of_eternity_royal_handmaiden") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_royal_handmaidenAI(pCreature);
    }

    struct npc_well_of_eternity_royal_handmaidenAI : public ScriptedAI
    {
        npc_well_of_eternity_royal_handmaidenAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = me->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SWEET_LULLABY, urand(7000, 12000));
        }

        void SpellHit(Unit* who, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_ARCHIVED_HANDMAIDEN_1)
                DoCast(who, SPELL_ARCHIVED_HANDMAIDEN_2, true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!pInstance)
                return;

            Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* pPlayer = i->GetSource())
                        if (me->GetDistance2d(pPlayer) <= 50.0f &&
                            pPlayer->GetQuestStatus(QUEST_DOCUMENTING_THE_TIMEWAYS) == QUEST_STATUS_INCOMPLETE)
                            pPlayer->CastSpell(me, SPELL_ARCHIVED_HANDMAIDEN_1, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SWEET_LULLABY:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_SWEET_LULLABY);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        InstanceScript* pInstance;
    };
};

class TrashRespawnWorker
{
public:
    void operator()(Creature* creature) const
    {
        switch (creature->GetEntry())
        {
        case NPC_ABYSSAL:
        case NPC_VAROTHEN:
        case NPC_DOOMGUARD:
            if (!creature->IsAlive())
                creature->Respawn(true);
            break;
        }
    }
};

static void TrashEvaded(Creature* creature)
{
    TrashRespawnWorker check;
    Trinity::CreatureWorker<TrashRespawnWorker> worker(creature, check);
    Cell::VisitGridObjects(creature, worker, SIZE_OF_GRIDS);
}

class npc_well_of_eternity_doomguard_annihilator : public CreatureScript
{
public:
    npc_well_of_eternity_doomguard_annihilator() : CreatureScript("npc_well_of_eternity_doomguard_annihilator") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_doomguard_annihilatorAI(pCreature);
    }

    struct npc_well_of_eternity_doomguard_annihilatorAI : public ScriptedAI
    {
        npc_well_of_eternity_doomguard_annihilatorAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void Reset() override
        { }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;

            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, me->GetEntry(), 500.0f);
            if (!creatures.empty())
                for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                    if (!(*itr)->IsInCombat())
                        (*itr)->AI()->AttackStart(who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* pInstance = me->GetInstanceScript())
                if (Creature* pIllidan = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_EVENT_ILLIDAN_2)))
                    pIllidan->AI()->DoAction(ACTION_DOOMGUARD_DIED);
        }
    };
};

class npc_well_of_eternity_illidan_2 : public CreatureScript
{
public:
    npc_well_of_eternity_illidan_2() : CreatureScript("npc_well_of_eternity_illidan_2") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_illidan_2AI(pCreature);
    }

    struct npc_well_of_eternity_illidan_2AI : public ScriptedAI
    {
        npc_well_of_eternity_illidan_2AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
            bTalk = false;
            bMove = false;
            curPoint = 0;
            doomguards = 0;
            pInstance = me->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        { }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (who->GetGUID() == me->GetGUID())
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (bTalk || !pInstance)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            if (pInstance->GetBossState(DATA_MANNOROTH) == DONE)
                return;

            if (pInstance)
                TrashEvaded(me);

            bTalk = true;

            Talk(SAY_ILLIDAN_2_INTRO_1);

            events.ScheduleEvent(EVENT_MALFURION_INTRO_1, 7000);
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (data)
                {
                case POINT_ILLIDAN_2_1:
                    curPoint = 1;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_2, 100);
                    break;
                case POINT_ILLIDAN_2_2:
                    curPoint = 2;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_3, 100);
                    break;
                case POINT_ILLIDAN_2_3:
                    curPoint = 3;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_4, 100);
                    break;
                case POINT_ILLIDAN_2_4:
                    curPoint = 4;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_5, 100);
                    break;
                case POINT_ILLIDAN_2_5:
                    curPoint = 5;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_6, 100);
                    break;
                case POINT_ILLIDAN_2_6:
                    events.ScheduleEvent(EVENT_ILLIDAN_NEAR_ELEMENTAL_1, 3000);
                    break;
                case POINT_ILLIDAN_2_8:
                    curPoint = 8;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_9, 100);
                    break;
                case POINT_ILLIDAN_2_9:
                    if (pInstance)
                    {
                        if (Creature* pVarothen = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_VAROTHEN)))
                            pVarothen->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        if (Creature* pMannoroth = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_MANNOROTH)))
                            pMannoroth->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    }
                    Talk(SAY_ILLIDAN_2_VAROTHEN);
                    break;
                default:
                    break;
                }
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_DOOMGUARD_DIED)
            {
                doomguards++;

                if (doomguards >= MAX_DOOMGUARDS && !bMove)
                {
                    bMove = true;
                    curPoint = 0;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_1, 5000);
                }
            } else if (action == ACTION_DOOMBRINGER_DIED)
            {
                curPoint = 7;
                me->RemoveAura(SPELL_WATERS_OF_ETERNITY);
                events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_8, 5000);
            } else if (action == ACTION_MANNOROTH_AGGRO)
            {
                curPoint = 9;
                me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_10, illidan2Pos[curPoint]);
                if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                    pTyrande->AI()->DoAction(ACTION_MANNOROTH_AGGRO);
            } else if (action == ACTION_MANNOROTH_RESET)
            {
                me->RemoveAllAuras();
                me->InterruptNonMeleeSpells(false);
                events.Reset();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!bTalk && !bMove)
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MALFURION_INTRO_1:
                    if (Creature* pMalfurion = me->FindNearestCreature(NPC_MALFURION, 100.0f))
                        pMalfurion->AI()->Talk(SAY_MALFURION_INTRO_1);
                    events.ScheduleEvent(EVENT_MALFURION_INTRO_2, 7000);
                    break;
                case EVENT_MALFURION_INTRO_2:
                    if (Creature* pMalfurion = me->FindNearestCreature(NPC_MALFURION, 100.0f))
                        pMalfurion->AI()->Talk(SAY_MALFURION_INTRO_2);
                    events.ScheduleEvent(EVENT_ILLIDAN_INTRO_2_2, 7000);
                    break;
                case EVENT_ILLIDAN_INTRO_2_2:
                    Talk(SAY_ILLIDAN_2_INTRO_2);
                    events.ScheduleEvent(EVENT_TYRANDE_INTRO_1, 7000);
                    break;
                case EVENT_TYRANDE_INTRO_1:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                        pTyrande->AI()->Talk(SAY_TYRANDE_INTRO_1);
                    events.ScheduleEvent(EVENT_ILLIDAN_INTRO_2_3, 9000);
                    break;
                case EVENT_ILLIDAN_INTRO_2_3:
                    Talk(SAY_ILLIDAN_2_INTRO_3);
                    events.ScheduleEvent(EVENT_TYRANDE_INTRO_2, 5000);
                    break;
                case EVENT_TYRANDE_INTRO_2:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                    {
                        pTyrande->AI()->Talk(SAY_TYRANDE_INTRO_2);
                        pTyrande->CastSpell(pTyrande, SPELL_BLESSING_OF_ELUNE);
                    }
                    break;
                case EVENT_ILLIDAN_MOVE_2_1:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                        pTyrande->RemoveAura(SPELL_BLESSING_OF_ELUNE);
                    Talk(SAY_ILLIDAN_2_DEMONS);
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_1, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_2:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                        pTyrande->AI()->DoAction(ACTION_TYRANDE_MOVE_1);
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_2, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_3:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_3, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_4:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_4, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_5:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_5, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_6:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_6, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_NEAR_ELEMENTAL_1:
                    Talk(SAY_ILLIDAN_2_ELEMENTAL_1);
                    events.ScheduleEvent(EVENT_ILLIDAN_NEAR_ELEMENTAL_2, 5000);
                    break;
                case EVENT_ILLIDAN_NEAR_ELEMENTAL_2:
                    Talk(SAY_ILLIDAN_2_ELEMENTAL_2);
                    events.ScheduleEvent(EVENT_TYRANDE_NEAR_ELEMENTAL_1, 5000);
                    break;
                case EVENT_TYRANDE_NEAR_ELEMENTAL_1:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                        pTyrande->AI()->Talk(SAY_TYRANDE_ELEMENTAL);
                    events.ScheduleEvent(EVENT_ILLIDAN_NEAR_ELEMENTAL_3, 7000);
                    break;
                case EVENT_ILLIDAN_NEAR_ELEMENTAL_3:
                    Talk(SAY_ILLIDAN_2_ELEMENTAL_3);
                    events.ScheduleEvent(EVENT_ILLIDAN_NEAR_ELEMENTAL_4, 5000);
                    break;
                case EVENT_ILLIDAN_NEAR_ELEMENTAL_4:
                    DoCast(me, SPELL_WATERS_OF_ETERNITY);
                    events.ScheduleEvent(EVENT_ILLIDAN_NEAR_ELEMENTAL_5, 5000);
                    break;
                case EVENT_ILLIDAN_NEAR_ELEMENTAL_5:
                    Talk(SAY_ILLIDAN_2_ELEMENTAL_4);
                    curPoint = 6;
                    events.ScheduleEvent(EVENT_ILLIDAN_MOVE_2_7, 14000);
                    break;
                case EVENT_ILLIDAN_MOVE_2_7:
                    if (Creature* pAbyssal = me->FindNearestCreature(NPC_ABYSSAL, 100.0f))
                        pAbyssal->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_7, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_8:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                        pTyrande->AI()->DoAction(ACTION_TYRANDE_MOVE_2);
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_8, illidan2Pos[curPoint]);
                    break;
                case EVENT_ILLIDAN_MOVE_2_9:
                    me->GetMotionMaster()->MovePoint(POINT_ILLIDAN_2_9, illidan2Pos[curPoint]);
                    break;
                default:
                    break;
                }
            }
        }

    private:
        bool bTalk;
        bool bMove;
        EventMap events;
        InstanceScript* pInstance;
        uint8 curPoint;
        uint8 doomguards;
    };
};

class npc_well_of_eternity_tyrande : public CreatureScript
{
public:
    npc_well_of_eternity_tyrande() : CreatureScript("npc_well_of_eternity_tyrande") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_tyrandeAI(pCreature);
    }

    struct npc_well_of_eternity_tyrandeAI : public ScriptedAI
    {
        npc_well_of_eternity_tyrandeAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
            curPoint = 0;
            pInstance = me->GetInstanceScript();
            bDebilitating = false;
            uiDebilitatingCount = 0;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_DEBILITATING_FLAY)
                if (!bDebilitating)
                {
                    bDebilitating = true;
                    events.CancelEvent(EVENT_TYRANDE_SHOT);
                    me->InterruptNonMeleeSpells(false);
                    Talk(SAY_TYRANDE_ELUNE);
                    DoCast(me, SPELL_BLESSING_OF_ELUNE);
                }
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
            case ACTION_TYRANDE_MOVE_1:
                curPoint = 0;
                events.ScheduleEvent(EVENT_TYRANDE_MOVE_1, 100);
                break;
            case ACTION_TYRANDE_MOVE_2:
                curPoint = 5;
                events.ScheduleEvent(EVENT_TYRANDE_MOVE_2, 100);
                break;
            case ACTION_MANNOROTH_AGGRO:
                me->GetMotionMaster()->MovePoint(POINT_TYRANDE_3, tyrandePos);
                break;
            case ACTION_MANNOROTH_RESET:
                me->RemoveAllAuras();
                me->InterruptNonMeleeSpells(false);
                events.Reset();
                bDebilitating = false;
                uiDebilitatingCount = 0;
                break;
            case ACTION_DEBILITATING_OFF:
                if (bDebilitating)
                {
                    uiDebilitatingCount++;
                    if (uiDebilitatingCount >= 2)
                    {
                        bDebilitating = false;
                        uiDebilitatingCount = 0;
                        me->RemoveAura(SPELL_BLESSING_OF_ELUNE);
                        Talk(SAY_TYRANDE_CONTINUE);
                        events.ScheduleEvent(EVENT_TYRANDE_SHOT, 1000);
                        if (pInstance)
                            if (Creature* pMannoroth = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_MANNOROTH)))
                                pMannoroth->AI()->DoAction(2); // ACTION_DEBILITATING_OFF
                    }
                }
                break;
            case ACTION_MANNOROTH_SARGERAS:
                events.CancelEvent(EVENT_TYRANDE_SHOT);
                events.ScheduleEvent(EVENT_HAND_OF_ELUNE, 1000);
                break;
            case ACTION_MANNOROTH_INFERNO:
                events.CancelEvent(EVENT_TYRANDE_SHOT);
                events.CancelEvent(EVENT_HAND_OF_ELUNE);
                me->RemoveAura(SPELL_HAND_OF_ELUNE);
                DoCastAOE(SPELL_WRATH_OF_ELUNE_2, true);
                break;
            case ACTION_MANNOROTH_END:
                me->RemoveAllAuras();
                me->InterruptNonMeleeSpells(false);
                events.Reset();
                bDebilitating = false;
                uiDebilitatingCount = 0;
                break;
            default:
                break;
            }
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                if (data == POINT_TYRANDE_1)
                {
                    if (curPoint < 4)
                    {
                        curPoint++;
                        events.ScheduleEvent(EVENT_TYRANDE_MOVE_1, 100);
                    }
                } else if (data == POINT_TYRANDE_2)
                {
                    if (curPoint < 7)
                    {
                        curPoint++;
                        events.ScheduleEvent(EVENT_TYRANDE_MOVE_2, 100);
                    }
                } else if (data == POINT_TYRANDE_3)
                {
                    Talk(SAY_TYRANDE_DEMONS);
                    events.ScheduleEvent(EVENT_TYRANDE_SHOT, 3000);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TYRANDE_MOVE_1:
                    me->GetMotionMaster()->MovePoint(POINT_TYRANDE_1, illidan2Pos[curPoint]);
                    break;
                case EVENT_TYRANDE_MOVE_2:
                    me->GetMotionMaster()->MovePoint(POINT_TYRANDE_2, illidan2Pos[curPoint]);
                    break;
                case EVENT_TYRANDE_SHOT:
                    DoCastAOE(SPELL_LUNAR_SHOT_3);
                    events.ScheduleEvent(EVENT_TYRANDE_SHOT, 3000);
                    break;
                case EVENT_HAND_OF_ELUNE:
                    if (!me->HasAura(SPELL_DEBILITATING_FLAY))
                        DoCast(me, SPELL_HAND_OF_ELUNE);
                    else
                        events.ScheduleEvent(EVENT_HAND_OF_ELUNE, 1000);
                    break;
                default:
                    break;
                }
            }
        }

    private:
        EventMap events;
        uint8 curPoint;
        InstanceScript* pInstance;
        bool bDebilitating;
        uint8 uiDebilitatingCount;
    };
};

class npc_well_of_eternity_malfurion : public CreatureScript
{
public:
    npc_well_of_eternity_malfurion() : CreatureScript("npc_well_of_eternity_malfurion") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_malfurionAI(pCreature);
    }

    struct npc_well_of_eternity_malfurionAI : public ScriptedAI
    {
        npc_well_of_eternity_malfurionAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
            pInstance = me->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        { }

    private:
        EventMap events;
        InstanceScript* pInstance;
    };
};

class npc_well_of_eternity_abyssal_doombringer : public CreatureScript
{
public:

    npc_well_of_eternity_abyssal_doombringer() : CreatureScript("npc_well_of_eternity_abyssal_doombringer") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_abyssal_doombringerAI(pCreature);
    }

    struct npc_well_of_eternity_abyssal_doombringerAI : public ScriptedAI
    {
        npc_well_of_eternity_abyssal_doombringerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ABYSSAL_FLAMES, 5000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* pInstance = me->GetInstanceScript())
                if (Creature* pIllidan = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_EVENT_ILLIDAN_2)))
                    pIllidan->AI()->DoAction(ACTION_DOOMBRINGER_DIED);

            me->DespawnOrUnsummon(3000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_ABYSSAL_FLAMES)
                {
                    DoCastAOE(SPELL_ABYSSAL_FLAMES);
                    events.ScheduleEvent(EVENT_ABYSSAL_FLAMES, 3000);
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };
};

class npc_well_of_eternity_dragon_soul : public CreatureScript
{
public:
    npc_well_of_eternity_dragon_soul() : CreatureScript("npc_well_of_eternity_dragon_soul") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_dragon_soulAI(pCreature);
    }

    struct npc_well_of_eternity_dragon_soulAI : public ScriptedAI
    {
        npc_well_of_eternity_dragon_soulAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
        }
    };
};

class npc_well_of_eternity_portal_to_twisting_nether : public CreatureScript
{
public:
    npc_well_of_eternity_portal_to_twisting_nether() : CreatureScript("npc_well_of_eternity_portal_to_twisting_nether") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_well_of_eternity_portal_to_twisting_netherAI(pCreature);
    }

    struct npc_well_of_eternity_portal_to_twisting_netherAI : public ScriptedAI
    {
        npc_well_of_eternity_portal_to_twisting_netherAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->setActive(true);
        }
    };
};

void AddSC_well_of_eternity()
{
    new npc_well_of_eternity_nozdormu();
    new npc_well_of_eternity_legion_demon();
    new npc_well_of_eternity_illidan_1();
    new npc_well_of_eternity_eternal_champion();
    new npc_well_of_eternity_eye_of_legion();
    new npc_well_of_eternity_enchanted_highmistress();
    new npc_well_of_eternity_royal_handmaiden();
    new npc_well_of_eternity_doomguard_annihilator();
    new npc_well_of_eternity_illidan_2();
    new npc_well_of_eternity_tyrande();
    new npc_well_of_eternity_malfurion();
    new npc_well_of_eternity_abyssal_doombringer();
    new npc_well_of_eternity_dragon_soul();
    new npc_well_of_eternity_portal_to_twisting_nether();
}
