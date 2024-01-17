/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ScriptedGossip.h"
#include "PassiveAI.h"
#include "ObjectAccessor.h"

/*######
## Quest 37446: Lazy Peons
## npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = 0
};

enum LazyPeon
{
    QUEST_LAZY_PEONS    = 37446,
    GO_LUMBERPILE       = 175784,
    SPELL_BUFF_SLEEP    = 17743,
    SPELL_AWAKEN_PEON   = 19938
};

class npc_lazy_peon : public CreatureScript
{
public:
    npc_lazy_peon() : CreatureScript("npc_lazy_peon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lazy_peonAI(creature);
    }

    struct npc_lazy_peonAI : public ScriptedAI
    {
        npc_lazy_peonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            RebuffTimer = 0;
            work = false;
        }

        uint32 RebuffTimer;
        bool work;

        void Reset() override
        {
            Initialize();
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(WorldObject* caster, SpellInfo const* spell) override
        {
            if (spell->Id != SPELL_AWAKEN_PEON)
                return;

            Player* player = caster->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                Talk(SAY_SPELL_HIT, caster);
                me->RemoveAllAuras();
                if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
                    me->GetMotionMaster()->MovePoint(1, Lumberpile->GetPositionX()-1, Lumberpile->GetPositionY(), Lumberpile->GetPositionZ());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (work == true)
                me->HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);
            if (RebuffTimer <= diff)
            {
                DoCast(me, SPELL_BUFF_SLEEP);
                RebuffTimer = 300000; //Rebuff agian in 5 minutes
            }
            else
                RebuffTimer -= diff;
            if (!UpdateVictim())
                return;
        }
    };
};

enum VoodooSpells
{
    SPELL_BREW      = 16712, // Special Brew
    SPELL_GHOSTLY   = 16713, // Ghostly
    SPELL_HEX1      = 16707, // Hex
    SPELL_HEX2      = 16708, // Hex
    SPELL_HEX3      = 16709, // Hex
    SPELL_GROW      = 16711, // Grow
    SPELL_LAUNCH    = 16716, // Launch (Whee!)
};

// 17009 - Voodoo
class spell_voodoo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BREW, SPELL_GHOSTLY, SPELL_HEX1, SPELL_HEX2, SPELL_HEX3, SPELL_GROW, SPELL_LAUNCH });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint32 spellid = RAND(SPELL_BREW, SPELL_GHOSTLY, RAND(SPELL_HEX1, SPELL_HEX2, SPELL_HEX3), SPELL_GROW, SPELL_LAUNCH);
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, spellid, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_voodoo::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum Mithaka
{
    DATA_SHIP_DOCKED    = 1,
    GOSSIP_MENU_MITHAKA = 23225,
    GOSSIP_TEXT_MITHAKA = 35969
};

struct npc_mithaka : ScriptedAI
{
    npc_mithaka(Creature* creature) : ScriptedAI(creature), _shipInPort(false) { }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        if (data == DATA_SHIP_DOCKED)
            _shipInPort = true;
        else
            _shipInPort = false;
    }

    bool OnGossipHello(Player* player) override
    {
        InitGossipMenuFor(player, GOSSIP_MENU_MITHAKA);
        if (!_shipInPort)
            AddGossipItemFor(player, GOSSIP_MENU_MITHAKA, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        SendGossipMenuFor(player, GOSSIP_TEXT_MITHAKA, me->GetGUID());
        return true;
    }
private:
    bool _shipInPort;
};

// Echo Isles
// 91404 - Summon Zuni (Lvl 1)
class spell_durotar_summon_zuni : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate({ -1173.4531f, -5266.401f, 0.85905945f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_durotar_summon_zuni::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

enum TikiTargetData
{
    SPELL_ARCANE_MISSILES_TRAINER = 83470,
    SPELL_TIKI_TARGET_VISUAL_1    = 71064,
    SPELL_TIKI_TARGET_VISUAL_2    = 71065,
    SPELL_TIKI_TARGET_VISUAL_3    = 71066,
    SPELL_TIKI_TARGET_DEATH       = 71240
};

uint32 const TiKiTargetMask[3] = { SPELL_TIKI_TARGET_VISUAL_1, SPELL_TIKI_TARGET_VISUAL_2, SPELL_TIKI_TARGET_VISUAL_3 };

struct npc_durotar_tiki_target : public ScriptedAI
{
    npc_durotar_tiki_target(Creature* creature) : ScriptedAI(creature), _credited(false) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetTemplateRooted(true);
        DoCastSelf(TiKiTargetMask[urand(0, 2)]);
        DoCastSelf(SPELL_ARCANE_MISSILES_TRAINER);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetHealth() <= damage)
        {
            damage = 0;
            me->SetHealth(1);

            if (!_credited)
            {
                _credited = true;

                DoCastSelf(SPELL_TIKI_TARGET_DEATH);

                if (Player* player = attacker->ToPlayer())
                    player->KilledMonsterCredit(me->GetEntry());

                me->DespawnOrUnsummon(2s, 13s);
            }
        }
    }

private:
    bool _credited;
};

enum DarkspearJailorData
{
    ACTION_EVENT_COMPLETE         = 1,
    ACTION_MOVE_TO_PRISONER       = 1,

    EVENT_PLAYER_ACCEPT_CHALLENGE = 1,
    EVENT_WALK_BACK_TO_HOME       = 2,

    GOSSIP_JAILOR_EVENT_NOT_READY = 10973,
    GOSSIP_JAILOR_EVENT_READY     = 10974,

    GOSSIP_EVENT_IN_PROGRESS_ID   = 10973,
    TEXT_GOSSIP_EVENT_IN_PROGRESS = 15252,

    NPC_DARKSPEAR_JAILOR          = 39062,
    NPC_CAPTIVE_SPITESCALE_SCOUT  = 38142,

    PATH_CAGE_ONE                 = 30915500,
    PATH_HOME_ONE                 = 30915501,
    PATH_CAGE_TWO                 = 30908200,
    PATH_HOME_TWO                 = 30908201,

    SAY_GET_IN_THE_PIT            = 0,

    SPELL_ACTIVATE_DNT            = 227105,
};

// 39062 - Darkspear Jailor
struct npc_darkspear_jailor : public ScriptedAI
{
    npc_darkspear_jailor(Creature* creature) : ScriptedAI(creature), _eventInProgress(false), _pathCage(0), _pathHome(0) { }

    void JustAppeared() override
    {
        me->SetGossipMenuId(GOSSIP_JAILOR_EVENT_READY);

        if (me->HasStringId("darkspear_jailor_one"))
        {
            _pathCage = PATH_CAGE_ONE;
            _pathHome = PATH_HOME_ONE;
        }
        else if (me->HasStringId("darkspear_jailor_two"))
        {
            _pathCage = PATH_CAGE_TWO;
            _pathHome = PATH_HOME_TWO;
        }
    }

    void DoAction(int32 param) override
    {
        if (param == ACTION_EVENT_COMPLETE)
        {
            _eventInProgress = false;
            me->SetGossipMenuId(GOSSIP_JAILOR_EVENT_READY);
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathCage)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
            me->CastSpell(me, SPELL_ACTIVATE_DNT);
            _events.ScheduleEvent(EVENT_WALK_BACK_TO_HOME, 1s);
        }
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        CloseGossipMenuFor(player);
        player->KilledMonsterCredit(NPC_DARKSPEAR_JAILOR);
        Talk(SAY_GET_IN_THE_PIT, player);
        _eventInProgress = true;
        me->SetGossipMenuId(GOSSIP_JAILOR_EVENT_NOT_READY);
        _events.ScheduleEvent(EVENT_PLAYER_ACCEPT_CHALLENGE, 2s);
        return true;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PLAYER_ACCEPT_CHALLENGE:
                    me->GetMotionMaster()->MovePath(_pathCage, false);
                    break;
                case EVENT_WALK_BACK_TO_HOME:
                    if (Creature* scout = me->FindNearestCreature(NPC_CAPTIVE_SPITESCALE_SCOUT, 5.0f, true))
                        scout->AI()->DoAction(ACTION_MOVE_TO_PRISONER);
                    me->GetMotionMaster()->MovePath(_pathHome, false);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }
private:
    EventMap _events;
    bool _eventInProgress;
    uint32 _pathCage;
    uint32 _pathHome;
};

enum CaptiveSpitescaleScoutData
{
    EVENT_UPDATE_JAILOR_GOSSIP      = 1,
    EVENT_TALK_TO_PLAYER            = 2,
    EVENT_DESPAWN_OUT_OF_COMBAT     = 3,
    EVENT_CAST_FROSTSHOCK           = 4,

    POINT_PRISONER_POSITION         = 0,

    SAY_SEND_YOU_TO_YOUR_DEATH      = 0,

    SPELL_FROST_SHOCK               = 15089
};

Position const PrisonerPositionOne = { -1142.49f, -5415.59f, 10.597655f };
Position const PrisonerPositionTwo = { -1149.03f, -5526.18f, 8.1045685f };

// 38142 - Captive Spitescale Scout
struct npc_captive_spitescale_scout : public ScriptedAI
{
    npc_captive_spitescale_scout(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_UPDATE_JAILOR_GOSSIP, 2s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SetImmuneToPC(true);
        me->DespawnOrUnsummon(10s, 7s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon(0s, 2s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.CancelEvent(EVENT_DESPAWN_OUT_OF_COMBAT);
        _events.ScheduleEvent(EVENT_CAST_FROSTSHOCK, 2s, 4s);
    }

    void DoAction(int32 param) override
    {
        if (param == ACTION_MOVE_TO_PRISONER)
        {
            me->SetWalk(true);

            if (me->HasStringId("captive_spitescale_scout_one"))
                me->GetMotionMaster()->MovePoint(POINT_PRISONER_POSITION, PrisonerPositionOne);
            else if (me->HasStringId("captive_spitescale_scout_two"))
                me->GetMotionMaster()->MovePoint(POINT_PRISONER_POSITION, PrisonerPositionTwo);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_PRISONER_POSITION)
        {
            _events.ScheduleEvent(EVENT_TALK_TO_PLAYER, 1s);
            _events.ScheduleEvent(EVENT_DESPAWN_OUT_OF_COMBAT, 100s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_UPDATE_JAILOR_GOSSIP:
                    if (Creature* jailer = me->FindNearestCreature(NPC_DARKSPEAR_JAILOR, 25.0f, true))
                        jailer->AI()->DoAction(ACTION_EVENT_COMPLETE);
                    break;
                case EVENT_TALK_TO_PLAYER:
                    Talk(SAY_SEND_YOU_TO_YOUR_DEATH);
                    me->SetImmuneToPC(false);
                    break;
                case EVENT_DESPAWN_OUT_OF_COMBAT:
                    me->DespawnOrUnsummon(0s, 2s);
                    break;
                case EVENT_CAST_FROSTSHOCK:
                    DoCastVictim(SPELL_FROST_SHOCK);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
    ObjectGuid _jailorGUID;
};

enum ProvingPitData
{
    EVENT_MOVE_TO_PIT               = 1,
    EVENT_MOVE_HOME                 = 2,

    GOSSIP_MENU_ARCANE_MOMENTUN     = 20690,

    GOSSIP_OPTION_TRAIN_MOMENTUM    = 0,
    GOSSIP_OPTION_UNTRAIN_MOMENTUM  = 1,

    NPC_TRAINER_NORTET              = 38037, // Warrior Trainer
    NPC_TRAINER_TUNARI              = 38245, // Priest Trainer
    NPC_TRAINER_SERATHA             = 38246, // Mage Trainer
    NPC_TRAINER_LEGATI              = 38244, // Rogue Trainer
    NPC_TRAINER_NEKALI              = 38242, // Shaman Trainer
    NPC_TRAINER_ERTEZZA             = 38247, // Hunter Trainer
    NPC_TRAINER_ZENTABRA            = 38243, // Druid Trainer
    NPC_TRAINER_VOLDREKA            = 42618, // Warlock Trainer
    NPC_TRAINER_ZABRAX              = 63310, // Monk Trainer

    QUEST_PROVING_PIT_WARRIOR       = 24642,
    QUEST_PROVING_PIT_PRIEST        = 24786,
    QUEST_PROVING_PIT_MAGE          = 24754,
    QUEST_PROVING_PIT_ROGUE         = 24774,
    QUEST_PROVING_PIT_SHAMAN        = 24762,
    QUEST_PROVING_PIT_HUNTER        = 24780,
    QUEST_PROVING_PIT_DRUID         = 24768,
    QUEST_PROVING_PIT_WARLOCK       = 26276,
    QUEST_PROVING_PIT_MONK          = 31161,

    SPELL_LEARN_ARCANE_MOMENTUM     = 232062,
    SPELL_UNLEARN_ARCANE_MOMENTUM   = 232063,

    SAY_NOT_BAD                     = 0,
    SAY_WELL_DONE                   = 1,

    POINT_INITIAL_HOME              = 1,
};

// Path point to proving pit fo trainers
Position const EchoIslandTrainersPitPoints[9] =
{
    { -1158.99f, -5421.14f, 13.218976f, 0.2094395f },   // Nortet Pit
    { -1137.0f, -5528.23f, 11.979752f, 3.1764990f },    // Tunari Pit
    { -1145.95f, -5543.13f, 12.48863f, 1.7278759f },    // Seratha Pit
    { -1146.67f, -5430.05f, 13.596256f, 1.4835298f },   // Legati Pit
    { -1152.22f, -5407.6f, 13.263395f, 4.904375f },     // Nekali Pit
    { -1136.46f, -5525.13f, 11.99673f, 3.3161256f },    // Ertezza Pit
    { -1158.81f, -5533.08f, 11.939185f, 0.3141593f },   // Zentabra Pit
    { -1149.92f, -5407.46f, 13.235063f, 4.956735f },    // Voldreka Pit
    { -1151.54f, -5429.86f, 13.29182f, 1.256637f }      // Zabrax Pit
};

template<uint8 PitPos, uint32 QuestID>
struct npc_echo_isles_class_trainer : public ScriptedAI
{
    npc_echo_isles_class_trainer(Creature* creature) : ScriptedAI(creature), _canMoveToPit(true) { }

    void JustAppeared() override
    {
        _initialHomePosition = me->GetPosition();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_INITIAL_HOME)
            _canMoveToPit = true;
    }

    void OnQuestAccept(Player* /*player*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QuestID)
        {
            if (_canMoveToPit)
            {
                _events.ScheduleEvent(EVENT_MOVE_TO_PIT, 2s);
                _canMoveToPit = false;
            }
        }
    }

    void OnQuestReward(Player* /*player*/, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QuestID)
            _events.RescheduleEvent(EVENT_MOVE_HOME, 60s);
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        // Use by Mage
        if (menuId == GOSSIP_MENU_ARCANE_MOMENTUN)
        {
            CloseGossipMenuFor(player);

            switch (gossipListId)
            {
                case GOSSIP_OPTION_TRAIN_MOMENTUM:
                    player->CastSpell(player, SPELL_LEARN_ARCANE_MOMENTUM);
                    break;
                case GOSSIP_OPTION_UNTRAIN_MOMENTUM:
                    player->CastSpell(player, SPELL_UNLEARN_ARCANE_MOMENTUM);
                    break;
                default:
                    break;
            }
            return true;
        }
        return false;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_PIT:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(0, EchoIslandTrainersPitPoints[PitPos], true, EchoIslandTrainersPitPoints[PitPos].GetOrientation());
                    _events.ScheduleEvent(EVENT_MOVE_HOME, 300s);
                    break;
                case EVENT_MOVE_HOME:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_INITIAL_HOME, _initialHomePosition, true, _initialHomePosition.GetOrientation());
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
    bool _canMoveToPit;
    Position _initialHomePosition;
};

// 24639 - The Basics: Hitting Things (Warrior)
// 24783 - The Basics: Hitting Things (Priest)
// 24751 - The Basics: Hitting Things (Mage)
// 24771 - The Basics: Hitting Things (Rogue)
// 24759 - The Basics: Hitting Things (Shaman)
// 24777 - The Basics: Hitting Things (Hunter)
// 24765 - The Basics: Hitting Things (Druid)
// 26273 - The Basics: Hitting Things (Warlock)
// 31158 - The Basics: Hitting Things (Monk)
template<uint32 TrainerEntry>
class quest_the_basics_hitting_things : public QuestScript
{
public:
    quest_the_basics_hitting_things(char const* scriptName) : QuestScript(scriptName) { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_COMPLETE)
        {
            if (Creature* creature = player->FindNearestCreature(TrainerEntry, 50.0f, true))
                creature->AI()->Talk(SAY_NOT_BAD, player);
        }
    }
};

// 24642 - Proving Pit (Warrior)
// 24786 - Proving Pit (Priest)
// 24754 - Proving Pit (Mage)
// 24774 - Proving Pit (Rogue)
// 24762 - Proving Pit (Shaman)
// 24780 - Proving Pit (Hunter)
// 24768 - Proving Pit (Druid)
// 26276 - Proving Pit (Warlock)
// 31161 - Proving Pit (Monk)
template<uint32 TrainerId>
class quest_proving_pit : public QuestScript
{
public:
    quest_proving_pit(char const* scriptName) : QuestScript(scriptName) { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_COMPLETE)
        {
            if (Creature* creature = player->FindNearestCreature(TrainerId, 50.0f, true))
                creature->AI()->Talk(SAY_WELL_DONE, player);
        }
    }
};

enum VoljinVisionData
{
    EVENT_VOLJIN_VISION_SCRIPT_1       = 1,
    EVENT_VOLJIN_VISION_SCRIPT_2       = 2,
    EVENT_VOLJIN_VISION_SCRIPT_3       = 3,
    EVENT_VOLJIN_VISION_SCRIPT_4       = 4,
    EVENT_VOLJIN_VISION_SCRIPT_5       = 5,
    EVENT_VOLJIN_VISION_SCRIPT_6       = 6,
    EVENT_VOLJIN_VISION_SCRIPT_7       = 7,
    EVENT_VOLJIN_VISION_SCRIPT_8       = 8,
    EVENT_VOLJIN_VISION_SCRIPT_9       = 9,
    EVENT_VOLJIN_VISION_SCRIPT_10      = 10,
    EVENT_VOLJIN_VISION_SCRIPT_11      = 11,
    EVENT_VOLJIN_VISION_SCRIPT_12      = 12,
    EVENT_VOLJIN_VISION_SCRIPT_13      = 13,
    EVENT_VOLJIN_VISION_SCRIPT_14      = 14,
    EVENT_VOLJIN_VISION_SCRIPT_15      = 15,
    EVENT_VOLJIN_VISION_SCRIPT_16      = 16,
    EVENT_VOLJIN_VISION_SCRIPT_17      = 17,
    EVENT_VOLJIN_VISION_SCRIPT_18      = 18,
    EVENT_VOLJIN_VISION_SCRIPT_19      = 19,
    EVENT_VOLJIN_VISION_SCRIPT_20      = 20,
    EVENT_VOLJIN_VISION_SCRIPT_21      = 21,
    EVENT_VOLJIN_VISION_SCRIPT_22      = 22,

    GOSSIP_MENU_GARROSH_VISION         = 11112,
    GOSSIP_MENU_THRALL_VISION          = 11127,
    GOSSIP_MENU_VISION_IN_PROGRESS     = 11126,

    QUEST_MORE_THAN_EXPECTED_WARRIOR   = 24643,
    QUEST_MORE_THAN_EXPECTED_MAGE      = 24755,
    QUEST_MORE_THAN_EXPECTED_SHAMAN    = 24763,
    QUEST_MORE_THAN_EXPECTED_ROGUE     = 24775,
    QUEST_MORE_THAN_EXPECTED_HUNTER    = 24781,
    QUEST_MORE_THAN_EXPECTED_PRIEST    = 24787,
    QUEST_MORE_THAN_EXPECTED_DRUID     = 24769,
    QUEST_MORE_THAN_EXPECTED_WARLOCK   = 26277,
    QUEST_MORE_THAN_EXPECTED_MONK      = 31163,
    QUEST_AN_ANCIENT_ENEMY             = 24814,

    SAY_GORROSH_VISION_SCRIPT_TEXT_0   = 0,
    SAY_GORROSH_VISION_SCRIPT_TEXT_1   = 1,
    SAY_GORROSH_VISION_SCRIPT_TEXT_2   = 2,
    SAY_GORROSH_VISION_SCRIPT_TEXT_3   = 3,
    SAY_GORROSH_VISION_SCRIPT_TEXT_4   = 4,

    SAY_VOLJIN_VISION_SCRIPT_TEXT_0    = 0,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_1    = 1,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_2    = 2,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_3    = 3,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_4    = 4,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_5    = 5,
    SAY_VOLJIN_VISION_SCRIPT_TEXT_6    = 6,

    SAY_THRALL_VISION_SCRIPT_TEXT_0    = 0,
    SAY_THRALL_VISION_SCRIPT_TEXT_1    = 1,
    SAY_THRALL_VISION_SCRIPT_TEXT_2    = 2,
    SAY_THRALL_VISION_SCRIPT_TEXT_3    = 3,
    SAY_THRALL_VISION_SCRIPT_TEXT_4    = 4,
    SAY_THRALL_VISION_SCRIPT_TEXT_5    = 5,
    SAY_THRALL_VISION_SCRIPT_TEXT_6    = 6,
    SAY_THRALL_VISION_SCRIPT_TEXT_7    = 7,

    SAY_VOLJIN_SCRIPT_TEXT_0           = 0,
    SAY_VOLJIN_SCRIPT_TEXT_1           = 1,
    SAY_VOLJIN_SCRIPT_TEXT_2           = 2,
    SAY_VOLJIN_SCRIPT_TEXT_3           = 3,
    SAY_VOLJIN_SCRIPT_TEXT_4           = 4,
    SAY_VOLJIN_SCRIPT_TEXT_5           = 5,
    SAY_VOLJIN_SCRIPT_TEXT_6           = 6,
    SAY_VOLJIN_SCRIPT_TEXT_7           = 7,
    SAY_VOLJIN_SCRIPT_TEXT_8           = 8,
    SAY_VOLJIN_SCRIPT_TEXT_9           = 9,
    SAY_VOLJIN_SCRIPT_TEXT_10          = 10,
    SAY_VOLJIN_SCRIPT_TEXT_11          = 11,
    SAY_VOLJIN_SCRIPT_TEXT_12          = 12,
    SAY_VOLJIN_SCRIPT_TEXT_13          = 13,
    SAY_VOLJIN_SCRIPT_TEXT_14          = 14,

    SPELL_RITES_OF_VISION              = 73169,
    SPELL_VOLJINS_VISION_SMOKE         = 73158,
    SPELL_GENERIC_QUEST_INVISIBILITY_1 = 49414,
    SPELL_GENERIC_QUEST_INVISIBILITY_2 = 49415,
    SPELL_GENERIC_QUEST_INVISIBILITY_8 = 78718,
};

// 38966 - Vol'jin (specific script for guid 309032)
struct npc_voljin_garrosh_vision : public ScriptedAI
{
    npc_voljin_garrosh_vision(Creature* creature) : ScriptedAI(creature), _scriptRunning(false) { }

    void JustAppeared() override
    {
        me->SetGossipMenuId(GOSSIP_MENU_GARROSH_VISION);

        Creature* garrosh = me->FindNearestCreatureWithOptions(10.0f, { .StringId = "vision_of_garrosh", .IgnorePhases = true });
        Creature* voljin = me->FindNearestCreatureWithOptions(10.0f, { .StringId = "vision_of_voljin", .IgnorePhases = true });
        Creature* bunny = me->FindNearestCreatureWithOptions(10.0f, { .StringId = "vision_brazier_bunny_garrosh", .IgnorePhases = true });
        GameObject* brazier = me->FindNearestGameObjectWithOptions(10.0f, { .StringId = "vision_brazier_garrosh_voljin", .IgnorePhases = true });

        if (!garrosh || !voljin || !bunny || !brazier)
            return;

        _garroshGUID = garrosh->GetGUID();
        _voljinGUID = voljin->GetGUID();
        _bunnyGUID = bunny->GetGUID();
        _brazierGUID = brazier->GetGUID();
    }

    void OnQuestReward(Player* /*player*/, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        if (_scriptRunning)
            return;

        switch (quest->GetQuestId())
        {
            case QUEST_MORE_THAN_EXPECTED_WARRIOR:
            case QUEST_MORE_THAN_EXPECTED_MAGE:
            case QUEST_MORE_THAN_EXPECTED_SHAMAN:
            case QUEST_MORE_THAN_EXPECTED_ROGUE:
            case QUEST_MORE_THAN_EXPECTED_HUNTER:
            case QUEST_MORE_THAN_EXPECTED_PRIEST:
            case QUEST_MORE_THAN_EXPECTED_DRUID:
            case QUEST_MORE_THAN_EXPECTED_WARLOCK:
            case QUEST_MORE_THAN_EXPECTED_MONK:
                _scriptRunning = true;
                _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_1, 0s);
                break;
            default:
                break;
        }
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        CloseGossipMenuFor(player);
        _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_1, 0s);
        _scriptRunning = true;
        return false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_scriptRunning)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VOLJIN_VISION_SCRIPT_1:
                {
                    me->SetGossipMenuId(GOSSIP_MENU_VISION_IN_PROGRESS);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_2, 0s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_2:
                {
                    me->SetFacingTo(3.97935f);
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_0);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_3, 3s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_3:
                {
                    DoCastSelf(SPELL_RITES_OF_VISION);
                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, _bunnyGUID))
                        bunny->AI()->DoCastSelf(SPELL_VOLJINS_VISION_SMOKE);
                    if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, _brazierGUID))
                        brazier->SetGoState(GO_STATE_ACTIVE);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_4, 4s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_4:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_1);
                        garrosh->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                    }

                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_5, 1s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_5:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        garrosh->AI()->Talk(SAY_GORROSH_VISION_SCRIPT_TEXT_0);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_6, 7s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_6:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                    {
                        voljin->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_1);
                        voljin->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                    }
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_7, 4s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_7:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_0);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_8, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_8:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_1);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_9, 6s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_9:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        garrosh->AI()->Talk(SAY_GORROSH_VISION_SCRIPT_TEXT_1);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_10, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_10:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_2);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_11, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_11:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        garrosh->AI()->Talk(SAY_GORROSH_VISION_SCRIPT_TEXT_2);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_12, 16s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_12:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_3);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_13, 16s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_13:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_4);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_14, 15s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_14:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_5);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_15, 17s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_15:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        garrosh->AI()->Talk(SAY_GORROSH_VISION_SCRIPT_TEXT_3);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_16, 3s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_16:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        garrosh->AI()->Talk(SAY_GORROSH_VISION_SCRIPT_TEXT_4);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_17, 3s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_17:
                {
                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                        voljin->AI()->Talk(SAY_VOLJIN_VISION_SCRIPT_TEXT_6);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_18, 9s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_18:
                {
                    me->RemoveAura(SPELL_RITES_OF_VISION);
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                        garrosh->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_1);
                    }

                    if (Creature* voljin = ObjectAccessor::GetCreature(*me, _voljinGUID))
                    {
                        voljin->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                        voljin->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_1);
                    }
                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, _bunnyGUID))
                        bunny->RemoveAura(SPELL_VOLJINS_VISION_SMOKE);
                    if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, _brazierGUID))
                        brazier->SetGoState(GO_STATE_READY);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_19, 2s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_19:
                {
                    me->SetFacingTo(0.837758f);
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_1);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_20, 9s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_20:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_2);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_21, 16s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_21:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_3);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_22, 8s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_22:
                {
                    me->SetGossipMenuId(GOSSIP_MENU_GARROSH_VISION);
                    _scriptRunning = false;
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _scriptRunning;
    ObjectGuid _garroshGUID;
    ObjectGuid _voljinGUID;
    ObjectGuid _bunnyGUID;
    ObjectGuid _brazierGUID;
};

// 38966 - Vol'jin (specific script for guid 3000469)
struct npc_voljin_thrall_vision : public ScriptedAI
{
    npc_voljin_thrall_vision(Creature* creature) : ScriptedAI(creature), _scriptRunning(false) { }

    void JustAppeared() override
    {
        me->SetGossipMenuId(GOSSIP_MENU_THRALL_VISION);

        Creature* thrall = me->FindNearestCreatureWithOptions(10.0f, { .StringId = "vision_of_thrall", .IgnorePhases = true });
        Creature* bunny = me->FindNearestCreatureWithOptions(10.0f, { .StringId = "vision_brazier_bunny_thrall", .IgnorePhases = true });
        GameObject* brazier = me->FindNearestGameObjectWithOptions(10.0f, { .StringId = "vision_brazier_thrall", .IgnorePhases = true });

        if (!thrall || !bunny || !brazier)
            return;

        _thrallGUID = thrall->GetGUID();
        _bunnyGUID = bunny->GetGUID();
        _brazierGUID = brazier->GetGUID();
    }

    void OnQuestReward(Player* /*player*/, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        if (_scriptRunning)
            return;

        if (quest->GetQuestId() == QUEST_AN_ANCIENT_ENEMY)
        {
            _scriptRunning = true;
            _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_1, 0s);
        }
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_1, 0s);
        CloseGossipMenuFor(player);
        _scriptRunning = true;
        return false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_scriptRunning)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VOLJIN_VISION_SCRIPT_1:
                {
                    me->SetGossipMenuId(GOSSIP_MENU_VISION_IN_PROGRESS);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_2, 0s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_2:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_4);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_3, 9s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_3:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_5);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_4, 8s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_4:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_6);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_5, 7s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_5:
                {
                    DoCastSelf(SPELL_RITES_OF_VISION);
                    me->SetFacingTo(3.97935f);
                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, _bunnyGUID))
                        bunny->AI()->DoCastSelf(SPELL_VOLJINS_VISION_SMOKE);
                    if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, _brazierGUID))
                        brazier->SetGoState(GO_STATE_ACTIVE);
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                    {
                        thrall->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_2);
                        thrall->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                    }
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_6, 5s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_6:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_0);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_7, 4s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_7:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_7);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_8, 6s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_8:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_1);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_9, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_9:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_8);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_10, 18s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_10:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_2);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_11, 6s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_11:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_3);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_12, 12s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_12:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_4);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_13, 18s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_13:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_5);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_14, 17s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_14:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_6);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_15, 9s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_15:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_9);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_16, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_16:
                {
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                        thrall->AI()->Talk(SAY_THRALL_VISION_SCRIPT_TEXT_7);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_17, 6s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_17:
                {
                    me->RemoveAura(SPELL_RITES_OF_VISION);
                    me->SetFacingTo(0.837758f);
                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, _thrallGUID))
                    {
                        thrall->AI()->DoCastSelf(SPELL_GENERIC_QUEST_INVISIBILITY_8);
                        thrall->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_2);
                    }
                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, _bunnyGUID))
                        bunny->RemoveAura(SPELL_VOLJINS_VISION_SMOKE);
                    if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, _brazierGUID))
                        brazier->SetGoState(GO_STATE_READY);
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_10);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_18, 8s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_18:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_11);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_19, 9s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_19:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_12);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_20, 17s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_20:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_13);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_21, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_21:
                {
                    Talk(SAY_VOLJIN_SCRIPT_TEXT_14);
                    _events.ScheduleEvent(EVENT_VOLJIN_VISION_SCRIPT_22, 11s);
                    break;
                }
                case EVENT_VOLJIN_VISION_SCRIPT_22:
                {
                    me->SetGossipMenuId(GOSSIP_MENU_THRALL_VISION);
                    _scriptRunning = false;
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _scriptRunning;
    ObjectGuid _thrallGUID;
    ObjectGuid _bunnyGUID;
    ObjectGuid _brazierGUID;
};

void AddSC_durotar()
{
    new npc_lazy_peon();
    RegisterSpellScript(spell_voodoo);
    RegisterCreatureAI(npc_mithaka);

    // Echo Isles
    RegisterSpellScript(spell_durotar_summon_zuni);
    RegisterCreatureAI(npc_durotar_tiki_target);
    RegisterCreatureAI(npc_darkspear_jailor);
    RegisterCreatureAI(npc_captive_spitescale_scout);
    new GenericCreatureScript<npc_echo_isles_class_trainer<0, QUEST_PROVING_PIT_WARRIOR>>("npc_nortet");
    new GenericCreatureScript<npc_echo_isles_class_trainer<1, QUEST_PROVING_PIT_PRIEST>>("npc_tunari");
    new GenericCreatureScript<npc_echo_isles_class_trainer<2, QUEST_PROVING_PIT_MAGE>>("npc_seratha");
    new GenericCreatureScript<npc_echo_isles_class_trainer<3, QUEST_PROVING_PIT_ROGUE>>("npc_legati");
    new GenericCreatureScript<npc_echo_isles_class_trainer<4, QUEST_PROVING_PIT_SHAMAN>>("npc_nekali");
    new GenericCreatureScript<npc_echo_isles_class_trainer<5, QUEST_PROVING_PIT_HUNTER>>("npc_ertezza");
    new GenericCreatureScript<npc_echo_isles_class_trainer<6, QUEST_PROVING_PIT_DRUID>>("npc_zentabra");
    new GenericCreatureScript<npc_echo_isles_class_trainer<7, QUEST_PROVING_PIT_WARLOCK>>("npc_voldreka");
    new GenericCreatureScript<npc_echo_isles_class_trainer<8, QUEST_PROVING_PIT_MONK>>("npc_zabrax");
    new quest_the_basics_hitting_things<NPC_TRAINER_NORTET>("quest_the_basics_hitting_things_warrior");
    new quest_the_basics_hitting_things<NPC_TRAINER_TUNARI>("quest_the_basics_hitting_things_priest");
    new quest_the_basics_hitting_things<NPC_TRAINER_SERATHA>("quest_the_basics_hitting_things_mage");
    new quest_the_basics_hitting_things<NPC_TRAINER_LEGATI>("quest_the_basics_hitting_things_rogue");
    new quest_the_basics_hitting_things<NPC_TRAINER_NEKALI>("quest_the_basics_hitting_things_shaman");
    new quest_the_basics_hitting_things<NPC_TRAINER_ERTEZZA>("quest_the_basics_hitting_things_hunter");
    new quest_the_basics_hitting_things<NPC_TRAINER_ZENTABRA>("quest_the_basics_hitting_things_druid");
    new quest_the_basics_hitting_things<NPC_TRAINER_VOLDREKA>("quest_the_basics_hitting_things_warlock");
    new quest_the_basics_hitting_things<NPC_TRAINER_ZABRAX>("quest_the_basics_hitting_things_monk");
    new quest_proving_pit<NPC_TRAINER_NORTET>("quest_proving_pit_warrior");
    new quest_proving_pit<NPC_TRAINER_TUNARI>("quest_proving_pit_priest");
    new quest_proving_pit<NPC_TRAINER_SERATHA>("quest_proving_pit_mage");
    new quest_proving_pit<NPC_TRAINER_LEGATI>("quest_proving_pit_rogue");
    new quest_proving_pit<NPC_TRAINER_NEKALI>("quest_proving_pit_shaman");
    new quest_proving_pit<NPC_TRAINER_ERTEZZA>("quest_proving_pit_hunter");
    new quest_proving_pit<NPC_TRAINER_ZENTABRA>("quest_proving_pit_druid");
    new quest_proving_pit<NPC_TRAINER_VOLDREKA>("quest_proving_pit_warlock");
    new quest_proving_pit<NPC_TRAINER_ZABRAX>("quest_proving_pit_monk");
    RegisterCreatureAI(npc_voljin_garrosh_vision);
    RegisterCreatureAI(npc_voljin_thrall_vision);
}
