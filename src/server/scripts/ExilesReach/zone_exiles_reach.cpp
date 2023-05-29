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

#include "Map.h"
#include "Object.h"
#include "Player.h"
#include "CellImpl.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "ScriptMgr.h"
#include "Transport.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ScriptSystem.h"
#include "MotionMaster.h"
#include "Conversation.h"
#include "ObjectAccessor.h"
#include "CreatureAIImpl.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include <Containers.h>

class ExilesReach
{
public:
    static Creature* FindCreature(WorldObject const* obj, std::string_view stringId)
    {
        return obj->FindNearestCreatureWithOptions(100.0f, FindCreatureOptions().SetIgnorePhases(true).SetStringId(stringId));
    }
};

 // ********************************************
 // * Scripting in this section occurs on ship *
 // ********************************************

enum QuestScripts
{
    CONVERSATION_WARMING_UP          = 12798,

    NPC_WARLORD_BREKA_GRIMAXE2       = 166824,
    NPC_WARLORD_BREKA_GRIMAXE3       = 166827,
    NPC_CAPTAIN_GARRICK              = 156280,

    QUEST_WARMING_UP_ALLIANCE        = 56775,
    QUEST_WARMING_UP_HORDE           = 59926,
    QUEST_STAND_YOUR_GROUND_ALLIANCE = 58209,
    QUEST_STAND_YOUR_GROUND_HORDE    = 59927,
    QUEST_BRACE_FOR_IMPACT_ALLIANCE  = 58208,
    QUEST_BRACE_FOR_IMPACT_HORDE     = 59928,

    SPELL_SUMMON_COLE                = 303064,
    SPELL_SUMMON_THROG               = 325107,
    SPELL_COMBAT_TRAINING_COMPLETE   = 303120
};

// This quest script is used for alliance and horde quest "Warming Up"

class BaseQuestWarmingUp : public QuestScript
{
public:
    BaseQuestWarmingUp(const char* name) : QuestScript(name) { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus)
    {
        if(newStatus == QUEST_STATUS_COMPLETE)
            Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
    }
};

class q56775_warming_up : public BaseQuestWarmingUp
{
public:
    q56775_warming_up() : BaseQuestWarmingUp("q56775_warming_up") { }

    const float CloneOrientation = 5.124503135681152343f;
    const float CloneSpawnZOffSet = 0.308f;

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus oldStatus, QuestStatus newStatus) override
    {
        BaseQuestWarmingUp::OnQuestStatusChange(player, quest, oldStatus, newStatus);

        if (newStatus == QUEST_STATUS_REWARDED)
        {
            Creature* garrickLowerDeck = ExilesReach::FindCreature(player, "q56775_garrick_lower_deck");
            Creature* garrickUpperDeck = ExilesReach::FindCreature(player, "q56775_garrick_upper_deck");
            if (!garrickLowerDeck || !garrickUpperDeck)
                return;

            Position pos(garrickLowerDeck->GetPositionX(), garrickLowerDeck->GetPositionY(), garrickLowerDeck->GetPositionZ() - CloneSpawnZOffSet, CloneOrientation);
            garrickUpperDeck->SummonPersonalClone(pos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

class q59926_warming_up : public BaseQuestWarmingUp
{
public:
    q59926_warming_up() : BaseQuestWarmingUp("q59926_warming_up") { }

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus oldStatus, QuestStatus newStatus) override
    {
        BaseQuestWarmingUp::OnQuestStatusChange(player, quest, oldStatus, newStatus);

        if (newStatus == QUEST_STATUS_REWARDED)
        {
            Creature* grimaxeLowerDeck = ExilesReach::FindCreature(player, "q59926_grimaxe_lower_deck");
            Creature* grimaxeUpperDeck = ExilesReach::FindCreature(player, "q59926_grimaxe_upper_deck");
            if (!grimaxeLowerDeck || !grimaxeUpperDeck)
                return;

            grimaxeUpperDeck->SummonPersonalClone(*grimaxeLowerDeck, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

// This quest script is used for alliance and horde quest "Stand Your Ground"

class quest_stand_your_ground : public QuestScript
{
public:
    quest_stand_your_ground() : QuestScript("quest_stand_your_ground") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        // Remove aura if player drops quest
        if (newStatus == QUEST_STATUS_NONE)
            player->CastSpell(player, SPELL_COMBAT_TRAINING_COMPLETE);
    }
};

// This quest script is used for alliance and horde quest "Brace For Impact"

struct ActorData
{
    std::string_view StringId;
    Position ActorPosition;
};

static std::unordered_map<TeamId, std::vector<ActorData>> const actorData =
{
    { TEAM_ALLIANCE,
        {
            { "q58208_garrick",  { 35.5643f, -1.19837f, 12.1479f, 3.3272014f }    },
            { "q58208_richter",  { -1.84858f, -8.38776f, 5.10018f, 1.5184366f }   },
            { "q58208_keela",    { -15.3642f, 6.5793f, 5.5026f, 3.1415925f }      },
            { "q58208_bjorn",    { 12.8406f, -8.49553f, 4.98031f, 4.8520155f }    },
            { "q58208_austin",   { -4.48607f, 9.89729f, 5.07851f, 1.5184366f }    },
            { "q58208_cole",     { -13.3396f, 0.702157f, 5.57996f, 0.087266445f } },
        }
    },
    { TEAM_HORDE,
        {
            { "q59928_grimaxe",  { 25.5237f, 0.283005f, 26.5455f, 3.3526998f }   },
            { "q59928_throg",    { -10.8399f, 11.9039f, 8.88028f, 6.2308254f }   },
            { "q59928_mithdran", { -24.4763f, -4.48273f, 9.13471f, 0.62831855f } },
            { "q59928_lana",     { -5.1971f, -15.0268f, 8.992f, 4.712389f }      },
            { "q59928_bo",       { -22.1559f, 5.58041f, 9.09176f, 6.143559f }    },
            { "q59928_jinhake",  { -31.9464f, 7.5772f, 10.6408f, 6.0737457f }    },
        }
    }
};

static std::unordered_map<Races, std::string_view> const actorPetData =
{
    { RACE_HUMAN,             "q58208_wolf"         },
    { RACE_DWARF,             "q58208_bear"         },
    { RACE_NIGHTELF,          "q58208_tiger"        },
    { RACE_GNOME,             "q58208_bunny"        },
    { RACE_DRAENEI,           "q58208_moth"         },
    { RACE_WORGEN,            "q58208_dog"          },
    { RACE_PANDAREN_ALLIANCE, "q58208_turtle"       },
    { RACE_ORC,               "q59928_wolf"         },
    { RACE_UNDEAD_PLAYER,     "q59928_bat"          },
    { RACE_TAUREN,            "q59928_plainstrider" },
    { RACE_TROLL,             "q59928_raptor"       },
    { RACE_GOBLIN,            "q59928_scorpion"     },
    { RACE_BLOODELF,          "q59928_dragonhawk"   },
    { RACE_PANDAREN_HORDE,    "q59928_turtle"       }
};

class quest_brace_for_impact : public QuestScript
{
public:
    quest_brace_for_impact() : QuestScript("quest_brace_for_impact") { }

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus != QUEST_STATUS_COMPLETE)
            return;

        if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_ALLIANCE)
        {
            if (auto const* actors = Trinity::Containers::MapGetValuePtr(actorData, TeamId(TEAM_ALLIANCE)))
            for (ActorData const actor : *actors)
                SpawnActor(player, ExilesReach::FindCreature(player, actor.StringId), actor.ActorPosition);

            // Spawn pet
            SpawnPet(player, { -1.4492f, 8.06887f,  5.10348f, 2.6005409f });
        }
        else if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_HORDE)
        {
            if (auto const* actors = Trinity::Containers::MapGetValuePtr(actorData, TeamId(TEAM_HORDE)))
                for (ActorData const actor : *actors)
                SpawnActor(player, ExilesReach::FindCreature(player, actor.StringId), actor.ActorPosition);

            // Spawn pet
            SpawnPet(player, { -22.8374f, -3.08287f, 9.12613f, 3.857178f });
        }
    }

    void SpawnPet(Player* player, Position const& position)
    {
        if (player->GetClass() != CLASS_HUNTER)
            return;

        if (std::string_view const* stringId = Trinity::Containers::MapGetValuePtr(actorPetData, Races(player->GetRace())))
        {
            Creature* pet = ExilesReach::FindCreature(player, *stringId);
            if (!pet)
                return;

            SpawnActor(player, pet, position);
        }
    }

    void SpawnActor(Player* player, Creature* creature, Position const& position)
    {
        TransportBase const* transport = player->GetDirectTransport();

        if (!transport || !creature)
            return;

        float x, y, z, o;
        position.GetPosition(x, y, z, o);
        transport->CalculatePassengerPosition(x, y, z, &o);
        creature->SummonPersonalClone({ x, y, z, o }, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
    }
};

// This script is used to script sparring partners for quest "Stand Your Ground" Alliance and Horde
// by entries: 157051,166814

enum SparingPartner
{
    ACTOR_ID_ALLIANCE               = 68598,
    ACTOR_ID_HORDE                  = 75920,

    CONVERSATION_PREFIGHT           = 14422,
    CONVERSATION_AGGRO              = 14423,
    CONVERSATION_JUMP               = 14424,

    EQUIPMENT_SWORD                 = 108493,
    EQUIPMENT_AXE                   = 175161,

    EVENT_MOVE_TO_A_POSITION        = 1,
    EVENT_PREFIGHT_CONVERSATION,
    EVENT_WALK_BACK,

    NPC_ALLIANCE_SPARING_PARTNER    = 157051,
    NPC_HORDE_SPARING_PARTNER       = 166814,
    NPC_SPAR_POINT_ADVERTISMENT     = 174971,
    NPC_KILL_CREDIT                 = 155607,

    PATH_ALLIANCE_SPARING_PARTNER   = 10501460,
    PATH_HORDE_SPARING_PARTNER      = 10501870,

    POSITION_SPARPOINT_ADVERTISMENT = 1,
    POSITION_SPARPOINT_READY        = 2,

    SPELL_JUMP_BEHIND               = 312757,
    SPELL_COMBAT_TRAINING           = 323071,
    SPELL_UPDATE_PHASE_SHIFT        = 82238,

    TALK_SPARING_COMPLETE           = 0
};

struct npc_sparring_partner : public ScriptedAI
{
    npc_sparring_partner(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_ALLIANCE_SPARING_PARTNER)
        {
            SetEquipmentSlots(false, EQUIPMENT_SWORD, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            _path = PATH_ALLIANCE_SPARING_PARTNER;
            _actorId = ACTOR_ID_ALLIANCE;
            _actorIndex = 0;
        }
        else if (me->GetEntry() == NPC_HORDE_SPARING_PARTNER)
        {
            SetEquipmentSlots(false, EQUIPMENT_AXE, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            _path = PATH_HORDE_SPARING_PARTNER;
            _actorId = ACTOR_ID_HORDE;
            _actorIndex = 1;
        }

        _events.ScheduleEvent(EVENT_MOVE_TO_A_POSITION, 1s);
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Unit* summoner = summonerWO->ToUnit();

        if (!summoner || !summoner->IsPlayer())
            return;

        _playerGUID = summoner->GetGUID();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!me->IsAlive())
            return;

        me->CombatStop(true);
        EngagementOver();
        me->ResetPlayerDamageReq();
        _events.ScheduleEvent(EVENT_WALK_BACK, 1s);
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case POSITION_SPARPOINT_ADVERTISMENT:
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_READY, me->GetFirstCollisionPosition(2.0f, (float)rand_norm() * static_cast<float>(2 * M_PI)));
                break;
            case POSITION_SPARPOINT_READY:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->SetFacingToObject(player);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->KilledMonsterCredit(NPC_KILL_CREDIT); // MINOR HACK should be done when fight ends but phase change is tied to quest conditions.
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT); // Here is where phase should change.
            player->CastSpell(player, SPELL_COMBAT_TRAINING_COMPLETE);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetHealth() <= damage)
        {
            damage = 0;
            me->SetHealth(1);
            DoStopAttack();
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);

            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            {
                me->SetFacingToObject(player);
                Talk(TALK_SPARING_COMPLETE, player);
                player->CastSpell(player, SPELL_COMBAT_TRAINING);
            }
        }

        if (me->HealthBelowPctDamaged(65, damage) && !_jumped)
        {
            _jumped = true;
            DoCastVictim(SPELL_JUMP_BEHIND, true);
            ConversationWithPlayer(CONVERSATION_JUMP);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ConversationWithPlayer(CONVERSATION_AGGRO);
    }

    void DamageDealt(Unit* target, uint32& damage, DamageEffectType /*damageType*/) override
    {
        if (target->GetHealthPct() < 91)
            damage = 0;
    }

    void ConversationWithPlayer(uint32 conversationId)
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            Conversation* conversation = Conversation::CreateConversation(conversationId, player, *player, player->GetGUID(), nullptr, false);
            conversation->AddActor(_actorId, _actorIndex, me->GetGUID());
            conversation->Start();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_A_POSITION:
                {
                    std::list<Creature*> sparpoints;
                    GetCreatureListWithEntryInGrid(sparpoints, me, NPC_SPAR_POINT_ADVERTISMENT, 25.0f);
                    Trinity::Containers::RandomResize(sparpoints, 1);

                    for (Creature* creature : sparpoints)
                        me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_ADVERTISMENT, creature->GetPosition());

                    me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    _events.ScheduleEvent(EVENT_PREFIGHT_CONVERSATION, 1s);
                }
                break;
                case EVENT_PREFIGHT_CONVERSATION:
                    ConversationWithPlayer(CONVERSATION_PREFIGHT);
                    break;
                case EVENT_WALK_BACK:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePath(_path, false);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    bool _jumped = false;
    uint8 _actorIndex = 0;
    uint32 _actorId = 0;
    uint32 _path = 0;
    ObjectGuid _playerGUID;
};

// This script used to script Captain Garrick and Warlord Breka Grimaxe after quest "Warming Up" rewarded Alliance and Horde
// by entries: 156280,166824

enum ShipCaptains
{
    EVENT_SHIP_CAPTAIN1_SCRIPT1     = 1,
    EVENT_SHIP_CAPTAIN1_SCRIPT2,
    EVENT_SHIP_CAPTAIN1_SCRIPT3,

    PATH_GARRICK_TO_COLE            = 10501450,
    PATH_GARRICK_TO_UPPER_DECK      = 10501451,
    PATH_GRIMAXE_TO_THROG           = 10501900,
    PATH_GRIMAXE_TO_UPPER_DECK      = 10501901,

    SAY_SPAR                        = 0
};

struct npc_ship_captain_warming_up_private : public ScriptedAI
{
    npc_ship_captain_warming_up_private(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_CAPTAIN_GARRICK)
        {
            _path_to_sparing_partner = PATH_GARRICK_TO_COLE;
            _path_to_upper_deck = PATH_GARRICK_TO_UPPER_DECK;
        }
        else if (me->GetEntry() == NPC_WARLORD_BREKA_GRIMAXE2)
        {
            _path_to_sparing_partner = PATH_GRIMAXE_TO_THROG;
            _path_to_upper_deck = PATH_GRIMAXE_TO_UPPER_DECK;
        }

        _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT1, 1s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _path_to_sparing_partner)
            _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT2, 1s);
        else if (pathId == _path_to_upper_deck)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHIP_CAPTAIN1_SCRIPT1:
                    Talk(SAY_SPAR);
                    me->GetMotionMaster()->MovePath(_path_to_sparing_partner, false);
                    break;
                case EVENT_SHIP_CAPTAIN1_SCRIPT2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT3, 3s);
                    break;
                case EVENT_SHIP_CAPTAIN1_SCRIPT3:
                    me->GetMotionMaster()->MovePath(_path_to_upper_deck, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    uint32 _path_to_sparing_partner = 0;
    uint32 _path_to_upper_deck = 0;
};

// This script used to script Captain Garrick and Warlord Breka Grimaxe for quest "Brace for Impact" Alliance and Horde
// by entries: 156280,166827

enum CaptainGarrickBraceForImpactShip
{
    EVENT_SHIP_CAPTAIN2_SCRIPT1     = 1,
    EVENT_SHIP_CAPTAIN2_SCRIPT2,

    PATH_GARRICK_FROM_UPPER_DECK    = 10505890,
    PATH_GARRICK_TO_LOWER_DECK      = 10505891,
    PATH_GRIMAXE_FROM_UPPER_DECK    = 10501910,
    PATH_GRIMAXE_TO_LOWER_DECK      = 10501911,

    SAY_GET_TO_POSITIONS            = 1
};

struct npc_ship_captain_brace_for_impact_private : public ScriptedAI
{
    npc_ship_captain_brace_for_impact_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_CAPTAIN_GARRICK)
        {
            _path_pre_talk = PATH_GARRICK_FROM_UPPER_DECK;
            _path_post_talk = PATH_GARRICK_TO_LOWER_DECK;
        }
        else if (me->GetEntry() == NPC_WARLORD_BREKA_GRIMAXE3)
        {
            _path_pre_talk = PATH_GRIMAXE_FROM_UPPER_DECK;
            _path_post_talk = PATH_GRIMAXE_TO_LOWER_DECK;
        }

        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->GetMotionMaster()->MovePath(_path_pre_talk, false);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _path_pre_talk)
            _events.ScheduleEvent(EVENT_SHIP_CAPTAIN2_SCRIPT1, 1s);
        else if (pathId == _path_post_talk)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHIP_CAPTAIN2_SCRIPT1:
                    Talk(SAY_GET_TO_POSITIONS);
                    _events.ScheduleEvent(EVENT_SHIP_CAPTAIN2_SCRIPT2, 2s);
                    break;
                case EVENT_SHIP_CAPTAIN2_SCRIPT2:
                    me->GetMotionMaster()->MovePath(_path_post_talk, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    uint32 _path_pre_talk = 0;
    uint32 _path_post_talk = 0;
};

CreatureAI* CaptainGarrickShipAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if ((privateObjectOwner->GetTeam() == ALLIANCE && privateObjectOwner->GetQuestStatus(QUEST_BRACE_FOR_IMPACT_ALLIANCE) == QUEST_STATUS_NONE))
                return new npc_ship_captain_warming_up_private(creature);
            else
                return new npc_ship_captain_brace_for_impact_private(creature);
        }
    }

    return new NullCreatureAI(creature);
};

CreatureAI* GrimaxeLowerShipAISelector(Creature* creature) { return creature->IsPrivateObject() ? new npc_ship_captain_warming_up_private(creature) : nullptr; };

CreatureAI* GrimaxeUpperShipAISelector(Creature* creature) { return creature->IsPrivateObject() ? new npc_ship_captain_brace_for_impact_private(creature) : nullptr; };

// This script is used to script Private Cole and Grunt Throg for quest "Stand Your Ground" Alliance and Horde
// by entries: 160664,166583

struct npc_first_mate_stand_your_ground : public ScriptedAI
{
    npc_first_mate_stand_your_ground(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);

        switch (quest->GetQuestId())
        {
            case QUEST_STAND_YOUR_GROUND_ALLIANCE:
                player->CastSpell(player, SPELL_SUMMON_COLE);
                break;
            case QUEST_STAND_YOUR_GROUND_HORDE:
                player->CastSpell(player, SPELL_SUMMON_THROG);
                break;
            default:
                break;
        }
    }
};

// This script is used to script Private Cole and Grunt Throg for quest "Brace For Impact" Alliance and Horde
// by private entries: 160664,166583

enum FirstMate
{
    EVENT_FIRST_MATE_1          = 1,
    EVENT_FIRST_MATE_2,

    NPC_PRIVATE_COLE            = 160664,
    NPC_GRUNT_THROG             = 166583,

    PATH_COLE_BRACE_FOR_IMPACT  = 10501461,
    PATH_THROG_BRACE_FOR_IMPACT = 10501871,

    SAY_STORM                   = 0
};

struct npc_first_mate_brace_for_impact_private : public ScriptedAI
{
    npc_first_mate_brace_for_impact_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_PRIVATE_COLE)
        {
            _path = PATH_COLE_BRACE_FOR_IMPACT;
        }
        else if (me->GetEntry() == NPC_GRUNT_THROG)
        {
            _path = PATH_THROG_BRACE_FOR_IMPACT;
        }

        _events.ScheduleEvent(EVENT_FIRST_MATE_1, 3s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (_path && pathId == _path)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FIRST_MATE_1:
                    Talk(SAY_STORM);
                    _events.ScheduleEvent(EVENT_FIRST_MATE_2, 4s);
                    break;
                case EVENT_FIRST_MATE_2:
                    me->GetMotionMaster()->MovePath(_path, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    uint32 _path = 0;
};

CreatureAI* ColeShipAISelector(Creature* creature)
{
    return creature->IsPrivateObject() ? new npc_first_mate_brace_for_impact_private(creature) : (CreatureAI*)new npc_first_mate_stand_your_ground(creature);
};

CreatureAI* ThrogShipAISelector(Creature* creature)
{
    return creature->IsPrivateObject() ? new npc_first_mate_brace_for_impact_private(creature) : (CreatureAI*)new npc_first_mate_stand_your_ground(creature);
};

// This script is used to script crew for quest "Brace For Impact" Alliance and Horde
// by private entries: 157042,157043,157044,157046,166585,166590,166794,166799

enum CrewShipBraceForImpact
{
    NPC_QUARTERMASTER_RICHTER       = 157042,
    NPC_KEE_LA                      = 157043,
    NPC_BJORN_STOUTHANDS            = 157044,
    NPC_AUSTIN_HUXWORTH             = 157046,

    NPC_BO                          = 166585,
    NPC_MITHDRAN_DAWNTRACKER        = 166590,
    NPC_LANA_JORDAN                 = 166794,
    NPC_PROVISONER_JIN_HAKE         = 166799,

    PATH_RICHTER_BRACE_FOR_IMPACT   = 10501770,
    PATH_KEE_LA_BRACE_FOR_IMPACT    = 10501800,
    PATH_BJORN_BRACE_FOR_IMPACT     = 10501790,
    PATH_AUSTIN_BRACE_FOR_IMPACT    = 10501780,

    PATH_BO_BRACE_FOR_IMPACT        = 10502010,
    PATH_MITHDRAN_BRACE_FOR_IMPACT  = 10501990,
    PATH_LANA_BRACE_FOR_IMPACT      = 10501980,
    PATH_JIN_HAKE_BRACE_FOR_IMPACT  = 10502000
};

struct npc_crew_ship_private : public ScriptedAI
{
    npc_crew_ship_private(Creature* creature) : ScriptedAI(creature) { }

    std::unordered_map<uint32, uint32> const PathData =
    {
        { NPC_QUARTERMASTER_RICHTER, PATH_RICHTER_BRACE_FOR_IMPACT  },
        { NPC_KEE_LA,                PATH_KEE_LA_BRACE_FOR_IMPACT   },
        { NPC_BJORN_STOUTHANDS,      PATH_BJORN_BRACE_FOR_IMPACT    },
        { NPC_AUSTIN_HUXWORTH,       PATH_AUSTIN_BRACE_FOR_IMPACT   },
        { NPC_BO,                    PATH_BO_BRACE_FOR_IMPACT       },
        { NPC_MITHDRAN_DAWNTRACKER,  PATH_MITHDRAN_BRACE_FOR_IMPACT },
        { NPC_LANA_JORDAN,           PATH_LANA_BRACE_FOR_IMPACT     },
        { NPC_PROVISONER_JIN_HAKE,   PATH_JIN_HAKE_BRACE_FOR_IMPACT }
    };

    void JustAppeared() override
    {
        if (uint32 const* path = Trinity::Containers::MapGetValuePtr(PathData, me->GetEntry()))
        {
            _path = *path;
            _scheduler.Schedule(Seconds(7), [this](TaskContext)
            {
                me->GetMotionMaster()->MovePath(_path, false);
            });
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (_path && pathId == _path)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
    uint32 _path = 0;
};

CreatureAI* ShipCrewAISelector(Creature* creature)
{
    return creature->IsPrivateObject() ? new npc_crew_ship_private(creature) : nullptr;
};

// This script is used to script pets for quest "Brace For Impact" Alliance and Horde
// by private entries: 167337,167342,167343,167344,167345,167346,167347,167348,167349,167350,167351,167352,167375

enum PetShipBraceForImpact
{
    EVENT_PET_SHIP_RUN_TO_POSITION = 1,

    MAP_ALLIANCE_SHIP              = 2261,
    MAP_HORDE_SHIP                 = 2369,

    PATH_PET_ALLIANCE_SHIP         = 10501510,
    PATH_PET_HORDE_SHIP            = 10502020
};

struct npc_pet_ship_private : public ScriptedAI
{
    npc_pet_ship_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (!me->GetTransport())
            return;

        if (me->GetTransport()->GetMapIdForSpawning() == MAP_ALLIANCE_SHIP)
            _path = PATH_PET_ALLIANCE_SHIP;
        else if (me->GetTransport()->GetMapIdForSpawning() == MAP_HORDE_SHIP)
            _path = PATH_PET_HORDE_SHIP;

        if (_path)
            _events.ScheduleEvent(EVENT_PET_SHIP_RUN_TO_POSITION, 8s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            if (eventId == EVENT_PET_SHIP_RUN_TO_POSITION)
                me->GetMotionMaster()->MovePath(_path, false);
        }
    }
private:
    EventMap _events;
    uint32 _path = 0;
};

CreatureAI* ShipPetAISelector(Creature* creature)
{
    return creature->IsPrivateObject() ? new npc_pet_ship_private(creature) : nullptr;
};

enum PlayerScriptHordeShipCrash
{
    MOVIE_ALLIANCE_SHIP_CRASH = 895,
    MOVIE_HORDE_SHIP_CRASH    = 931,

    SPELL_ALLIANCE_SHIP_CRASH = 305446,
    SPELL_HORDE_SHIP_CRASH    = 325133
};

class player_ship_crash : public PlayerScript
{
public:
    player_ship_crash() : PlayerScript("player_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        switch (movieId)
        {
            case MOVIE_ALLIANCE_SHIP_CRASH:
                player->CastSpell(player, SPELL_ALLIANCE_SHIP_CRASH, true);
                break;
            case MOVIE_HORDE_SHIP_CRASH:
                player->CastSpell(player, SPELL_HORDE_SHIP_CRASH, true);
                break;
            default:
                break;
        }
    }
};

enum AllianceHordeShipSceneSpells
{
    SPELL_BEGIN_TUTORIAL          = 295600,
    SPELL_KNOCKED_DOWN            = 305445,
    SPELL_CRASHED_LANDED_ALLIANCE = 305464,
    SPELL_CRASHED_LANDED_HORDE    = 325136
};

// This script is used to send conversation to Captian Garrick and Warlord Grimaxe on movement after entering ship

class scene_alliance_and_horde_ship : public SceneScript
{
public:
    scene_alliance_and_horde_ship() : SceneScript("scene_alliance_and_horde_ship") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }
};

// Player needs to be removed from transport before teleport or will not be teleported to correct location

class spell_exiles_reach_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_exiles_reach_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_exiles_reach_ship_crash_teleport::RelocateTransportOffset, EFFECT_3, SPELL_EFFECT_TELEPORT_UNITS);
        OnEffectHitTarget += SpellEffectFn(spell_exiles_reach_ship_crash_teleport::RelocateTransportOffset, EFFECT_4, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

class spell_summon_sparing_partner : public SpellScript
{
    PrepareSpellScript(spell_summon_sparing_partner);

    void SelectTarget(WorldObject*& target)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        Creature* partner = ExilesReach::FindCreature(caster, caster->GetTeam() == ALLIANCE ? "q58209_cole" : "q59927_throg");
        if (!partner)
            return;

        target = partner;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_summon_sparing_partner::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY_OR_DB);
    }
};

// ***************************************************************
// * Scripting in this section occurs after teleporting to beach *
// ***************************************************************

// Script scene for washed up on beach to cast spells Alliance and Horde

class scene_alliance_and_horde_crash : public SceneScript
{
public:
    scene_alliance_and_horde_crash() : SceneScript("scene_alliance_and_horde_crash") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Begin Knockdown Aura")
            player->CastSpell(player, SPELL_KNOCKED_DOWN, true);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, player->GetTeam() == ALLIANCE ? SPELL_CRASHED_LANDED_ALLIANCE : SPELL_CRASHED_LANDED_HORDE, true);
    }
};

void AddSC_zone_exiles_reach()
{
    // Ship
    RegisterCreatureAI(npc_sparring_partner);
    new FactoryCreatureScript<CreatureAI, &CaptainGarrickShipAISelector>("npc_captain_garrick_ship");
    new FactoryCreatureScript<CreatureAI, &GrimaxeLowerShipAISelector>("npc_warlord_grimaxe_lower_ship");
    new FactoryCreatureScript<CreatureAI, &GrimaxeUpperShipAISelector>("npc_warlord_grimaxe_upper_ship");
    new FactoryCreatureScript<CreatureAI, &ColeShipAISelector>("npc_cole_ship");
    new FactoryCreatureScript<CreatureAI, &ThrogShipAISelector>("npc_throg_ship");
    new FactoryCreatureScript<CreatureAI, &ShipCrewAISelector>("npc_crew_ship");
    new FactoryCreatureScript<CreatureAI, &ShipPetAISelector>("npc_pet_ship");
    new q59926_warming_up();
    new q56775_warming_up();
    new quest_stand_your_ground();
    new quest_brace_for_impact();
    new player_ship_crash();
    new scene_alliance_and_horde_ship();
    RegisterSpellScript(spell_exiles_reach_ship_crash_teleport);
    RegisterSpellScript(spell_summon_sparing_partner);
    // Beach
    new scene_alliance_and_horde_crash();
}
