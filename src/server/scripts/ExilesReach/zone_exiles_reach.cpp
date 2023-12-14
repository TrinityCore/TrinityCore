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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "CreatureAIImpl.h"
#include "Map.h"
#include "Object.h"
#include "Player.h"
#include "CellImpl.h"
#include "Containers.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptSystem.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Loot.h"
#include <SpellHistory.h>

template<class privateAI, class publicAI>
CreatureAI* GetPrivatePublicPairAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new privateAI(creature);
    return new publicAI(creature);
}

#define RegisterPrivatePublicCreatureAIPair(scriptName, privateAI, publicAI) new FactoryCreatureScript<CreatureAI, &GetPrivatePublicPairAISelector<privateAI, publicAI>>(scriptName);

static Creature* FindCreatureIgnorePhase(WorldObject const* obj, std::string_view stringId, float range = 100.0f)
{
    return obj->FindNearestCreatureWithOptions(range, { .StringId = stringId, .IgnorePhases = true });
}

 // ********************************************
 // * Scripting in this section occurs on ship *
 // ********************************************

enum AttentionExilesReachData
{
    SPELL_DEBUG_LOOK_RIGHT = 290903
};

// 290901 - Attention!
class spell_attention_exiles_reach_tutorial : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEBUG_LOOK_RIGHT });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DEBUG_LOOK_RIGHT, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_attention_exiles_reach_tutorial::OnRemove, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
    }
};

enum WarmingUpData
{
    CONVERSATION_WARMING_UP_ACCEPT          = 12818,
    CONVERSATION_WARMING_UP_COMPLETE        = 12798,
};

class BaseQuestWarmingUp : public QuestScript
{
public:
    BaseQuestWarmingUp(const char* name) : QuestScript(name) { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus)
    {
        if (newStatus == QUEST_STATUS_INCOMPLETE)
            Conversation::CreateConversation(CONVERSATION_WARMING_UP_ACCEPT, player, *player, player->GetGUID(), nullptr);
        else if (newStatus == QUEST_STATUS_COMPLETE)
            Conversation::CreateConversation(CONVERSATION_WARMING_UP_COMPLETE, player, *player, player->GetGUID(), nullptr);
    }
};

class q56775_warming_up : public BaseQuestWarmingUp
{
public:
    q56775_warming_up() : BaseQuestWarmingUp("q56775_warming_up") { }

    static constexpr float CLONE_ORIENTATION = 5.124503135681152343f;
    static constexpr float CLONE_Z_OFFSET = 0.308f;

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus oldStatus, QuestStatus newStatus) override
    {
        BaseQuestWarmingUp::OnQuestStatusChange(player, quest, oldStatus, newStatus);

        if (newStatus == QUEST_STATUS_REWARDED)
        {
            Creature* garrickLowerDeck = FindCreatureIgnorePhase(player, "q56775_garrick_lower_deck", 5.0f);
            Creature* garrickUpperDeck = FindCreatureIgnorePhase(player, "q56775_garrick_upper_deck", 75.0f);
            if (!garrickLowerDeck || !garrickUpperDeck)
                return;

            Position pos(garrickLowerDeck->GetPositionX(), garrickLowerDeck->GetPositionY(), garrickLowerDeck->GetPositionZ() - CLONE_Z_OFFSET, CLONE_ORIENTATION);
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
            Creature* grimaxeLowerDeck = FindCreatureIgnorePhase(player, "q59926_grimaxe_lower_deck", 5.0f);
            Creature* grimaxeUpperDeck = FindCreatureIgnorePhase(player, "q59926_grimaxe_upper_deck", 75.0f);
            if (!grimaxeLowerDeck || !grimaxeUpperDeck)
                return;

            grimaxeUpperDeck->SummonPersonalClone(*grimaxeLowerDeck, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

enum WarmingUpCaptainData
{
    NPC_WARLORD_BREKA_GRIMAXE2      = 166824,
    NPC_WARLORD_BREKA_GRIMAXE3      = 166827,
    NPC_CAPTAIN_GARRICK             = 156280,

    PATH_GARRICK_TO_COLE            = 10501450,
    PATH_GARRICK_TO_UPPER_DECK      = 10501451,
    PATH_GRIMAXE_TO_THROG           = 10501900,
    PATH_GRIMAXE_TO_UPPER_DECK      = 10501901,

    EVENT_SHIP_CAPTAIN1_SCRIPT1     = 1,
    EVENT_SHIP_CAPTAIN1_SCRIPT2,
    EVENT_SHIP_CAPTAIN1_SCRIPT3,

    SAY_SPAR                        = 0,
};

// 156280 - Captain Garrick
// 166824 - Warlord Breka Grimaxe
struct npc_ship_captain_warming_up_private : public ScriptedAI
{
    npc_ship_captain_warming_up_private(Creature* creature) : ScriptedAI(creature), _pathToSparringPartner(0), _pathToUpperDeck(0) { }

    void InitializeAI() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_CAPTAIN_GARRICK)
        {
            _pathToSparringPartner = PATH_GARRICK_TO_COLE;
            _pathToUpperDeck = PATH_GARRICK_TO_UPPER_DECK;
        }
        else if (me->GetEntry() == NPC_WARLORD_BREKA_GRIMAXE2)
        {
            _pathToSparringPartner = PATH_GRIMAXE_TO_THROG;
            _pathToUpperDeck = PATH_GRIMAXE_TO_UPPER_DECK;
        }

        _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT1, 1s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathToSparringPartner)
            _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT2, 0s);
        else if (pathId == _pathToUpperDeck)
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
                    me->GetMotionMaster()->MovePath(_pathToSparringPartner, false);
                    break;
                case EVENT_SHIP_CAPTAIN1_SCRIPT2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    _events.ScheduleEvent(EVENT_SHIP_CAPTAIN1_SCRIPT3, 3s);
                    break;
                case EVENT_SHIP_CAPTAIN1_SCRIPT3:
                    me->GetMotionMaster()->MovePath(_pathToUpperDeck, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    uint32 _pathToSparringPartner;
    uint32 _pathToUpperDeck;
};

enum StandYourGroundData
{
    ACTOR_ID_ALLIANCE                   = 68598,
    ACTOR_ID_HORDE                      = 75920,

    CONVERSATION_PREFIGHT               = 14422,
    CONVERSATION_AGGRO                  = 14423,
    CONVERSATION_JUMP                   = 14424,

    EQUIPMENT_SWORD                     = 108493,
    EQUIPMENT_AXE                       = 175161,

    EVENT_MOVE_TO_A_POSITION            = 1,
    EVENT_PREFIGHT_CONVERSATION,
    EVENT_JUMP_BEHIND,
    EVENT_WALK_BACK,

    PATH_ALLIANCE_SPARING_PARTNER       = 10501460,
    PATH_HORDE_SPARING_PARTNER          = 10501870,

    POSITION_SPARPOINT_ADVERTISMENT     = 1,
    POSITION_SPARPOINT_READY            = 2,

    TALK_SPARING_COMPLETE               = 0,

    NPC_ALLIANCE_SPARING_PARTNER        = 157051,
    NPC_HORDE_SPARING_PARTNER           = 166814,
    NPC_SPAR_POINT_ADVERTISMENT         = 174971,
    NPC_KILL_CREDIT                     = 155607,

    SPELL_COMBAT_TRAINING_COMPLETE      = 303120,
    SPELL_JUMP_LEFT                     = 312757,
    SPELL_JUMP_BEHIND                   = 312755,
    SPELL_COMBAT_TRAINING               = 323071,
    SPELL_UPDATE_PHASE_SHIFT            = 82238,
};

// 58209 - Stand Your Ground
// 59927 - Stand Your Ground
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

// 303065 - Summon Cole - Combat Training (DNT)
// 325108 - Summon Throg - Combat Training (DNT)
class spell_summon_sparring_partner : public SpellScript
{
    void SelectTarget(WorldObject*& target)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        Creature* partner = FindCreatureIgnorePhase(caster, caster->GetTeam() == ALLIANCE ? "q58209_cole" : "q59927_throg", 10.0f);
        if (!partner)
            return;

        target = partner;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_summon_sparring_partner::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY_OR_DB);
    }
};

// 157051 - Alliance Sparring Partner
// 166814 - Horde Sparring Partner
struct npc_sparring_partner_exiles_reach : public ScriptedAI
{
    npc_sparring_partner_exiles_reach(Creature* creature) : ScriptedAI(creature), _jumped(false), _actorIndex(0), _actorId(0), _path(0) { }

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
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
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
                me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_READY, me->GetFirstCollisionPosition(2.0f, rand_norm() * static_cast<float>(2 * M_PI)));
                break;
            case POSITION_SPARPOINT_READY:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->SetFacingToObject(player);
                me->SetImmuneToPC(false);
                me->SetUninteractible(false);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId != _path)
            return;

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            me->DespawnOrUnsummon();
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
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
            me->SetImmuneToPC(true);
            me->SetUninteractible(true);
            _events.CancelEvent(EVENT_JUMP_BEHIND);

            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            {
                me->SetFacingToObject(player);
                Talk(TALK_SPARING_COMPLETE, player);
                player->CastSpell(player, SPELL_COMBAT_TRAINING);
                player->KilledMonsterCredit(NPC_KILL_CREDIT);
            }
        }

        if (me->HealthBelowPctDamaged(65, damage) && !_jumped)
        {
            _jumped = true;
            DoCastVictim(SPELL_JUMP_LEFT, true);
            StartPrivateConversation(CONVERSATION_JUMP);
            _events.ScheduleEvent(EVENT_JUMP_BEHIND, 2s);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        StartPrivateConversation(CONVERSATION_AGGRO);
    }

    void DamageDealt(Unit* target, uint32& damage, DamageEffectType /*damageType*/) override
    {
        if (target->GetHealthPct() < 95)
            damage = 0;
    }

    void StartPrivateConversation(uint32 conversationId)
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            Conversation* conversation = Conversation::CreateConversation(conversationId, player, *player, player->GetGUID(), nullptr, false);
            conversation->AddActor(_actorId, _actorIndex, me->GetGUID());
            conversation->Start();
        }
    }

    Creature* GetRandomSparPoint()
    {
        std::list<Creature*> sparPoints;
        GetCreatureListWithEntryInGrid(sparPoints, me, NPC_SPAR_POINT_ADVERTISMENT, 25.0f);
        Trinity::Containers::RandomResize(sparPoints, 1);

        if (sparPoints.empty()) // should never happen
            return nullptr;

        return sparPoints.front();
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
                    if (Creature* sparPoint = GetRandomSparPoint())
                        me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_ADVERTISMENT, sparPoint->GetPosition());

                    _events.ScheduleEvent(EVENT_PREFIGHT_CONVERSATION, 1s);
                    break;
                }
                case EVENT_PREFIGHT_CONVERSATION:
                    StartPrivateConversation(CONVERSATION_PREFIGHT);
                    break;
                case EVENT_JUMP_BEHIND:
                    DoCastVictim(SPELL_JUMP_BEHIND, true);
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
    bool _jumped;
    uint8 _actorIndex;
    uint32 _actorId;
    uint32 _path;
    ObjectGuid _playerGUID;
};

enum FirstMateStandYourGroundData
{
    QUEST_STAND_YOUR_GROUND_ALLIANCE    = 58209,
    QUEST_STAND_YOUR_GROUND_HORDE       = 59927,

    SPELL_SUMMON_COLE                   = 303064,
    SPELL_SUMMON_THROG                  = 325107,
};

// 160664 - Private Cole
// 166583 - Grunt Throg
struct npc_first_mate_stand_your_ground : public ScriptedAI
{
    npc_first_mate_stand_your_ground(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STAND_YOUR_GROUND_ALLIANCE)
        {
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->CastSpell(player, SPELL_SUMMON_COLE);
        }
        else if (quest->GetQuestId() == QUEST_STAND_YOUR_GROUND_HORDE)
        {
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->CastSpell(player, SPELL_SUMMON_THROG);
        }
    }
};

struct ActorData
{
    std::string_view StringId;
    Position ActorPosition;
};

static std::vector<ActorData> const ActorDataMap[2] =
{
    // TEAM_ALLIANCE
    {
        { "q58208_garrick",  { 35.5643f, -1.19837f, 12.1479f, 3.3272014f }    },
        { "q58208_richter",  { -1.84858f, -8.38776f, 5.10018f, 1.5184366f }   },
        { "q58208_keela",    { -15.3642f, 6.5793f, 5.5026f, 3.1415925f }      },
        { "q58208_bjorn",    { 12.8406f, -8.49553f, 4.98031f, 4.8520155f }    },
        { "q58208_austin",   { -4.48607f, 9.89729f, 5.07851f, 1.5184366f }    },
        { "q58208_cole",     { -13.3396f, 0.702157f, 5.57996f, 0.087266445f } },
    },
    // TEAM_HORDE
    {
        { "q59928_grimaxe",  { 25.5237f, 0.283005f, 26.5455f, 3.3526998f }   },
        { "q59928_throg",    { -10.8399f, 11.9039f, 8.88028f, 6.2308254f }   },
        { "q59928_mithdran", { -24.4763f, -4.48273f, 9.13471f, 0.62831855f } },
        { "q59928_lana",     { -5.1971f, -15.0268f, 8.992f, 4.712389f }      },
        { "q59928_bo",       { -22.1559f, 5.58041f, 9.09176f, 6.143559f }    },
        { "q59928_jinhake",  { -31.9464f, 7.5772f, 10.6408f, 6.0737457f }    },
    }
};

static std::unordered_map<Races, std::string_view> const ActorPetData =
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

enum BraceForImpactData
{
    QUEST_BRACE_FOR_IMPACT_ALLIANCE = 58208,
    QUEST_BRACE_FOR_IMPACT_HORDE    = 59928,
};

// 58208 - Brace For Impact
// 59928 - Brace For Impact
class quest_brace_for_impact : public QuestScript
{
public:
    quest_brace_for_impact() : QuestScript("quest_brace_for_impact") { }

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus != QUEST_STATUS_COMPLETE)
            return;

        TeamId team = TEAM_NEUTRAL;
        Position petSpawnPos;

        if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_ALLIANCE)
        {
            team = TEAM_ALLIANCE;
            petSpawnPos = { -1.4492f, 8.06887f,  5.10348f, 2.6005409f };
        }
        else if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_HORDE)
        {
            team = TEAM_HORDE;
            petSpawnPos = { -22.8374f, -3.08287f, 9.12613f, 3.857178f };
        }

        if (team == TEAM_NEUTRAL)
            return;

        SpawnActors(player, team, petSpawnPos);
        player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
    }

    void SpawnActors(Player* player, TeamId team, Position petSpawnPos)
    {
        for (ActorData const& actor : ActorDataMap[team])
            SpawnActor(player, FindCreatureIgnorePhase(player, actor.StringId, 50.0f), actor.ActorPosition);

        SpawnPet(player, petSpawnPos);
    }

    void SpawnPet(Player* player, Position const& position)
    {
        if (player->GetClass() != CLASS_HUNTER)
            return;

        if (std::string_view const* stringId = Trinity::Containers::MapGetValuePtr(ActorPetData, Races(player->GetRace())))
        {
            Creature* pet = FindCreatureIgnorePhase(player, *stringId, 25.0f);
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

enum BraceForImpactCaptainData
{
    PATH_GARRICK_FROM_UPPER_DECK    = 10505890,
    PATH_GARRICK_TO_LOWER_DECK      = 10505891,
    PATH_GRIMAXE_FROM_UPPER_DECK    = 10501910,
    PATH_GRIMAXE_TO_LOWER_DECK      = 10501911,

    EVENT_SHIP_CAPTAIN2_SCRIPT1     = 1,
    EVENT_SHIP_CAPTAIN2_SCRIPT2,

    SAY_GET_TO_POSITIONS            = 1,
};

// 156280 - Captain Garrick
// 166827 - Warlord Breka Grimaxe
struct npc_ship_captain_brace_for_impact_private : public ScriptedAI
{
    npc_ship_captain_brace_for_impact_private(Creature* creature) : ScriptedAI(creature), _pathPreTalk(0), _pathPostTalk(0), _waitTime(0s){ }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_CAPTAIN_GARRICK)
        {
            _pathPreTalk = PATH_GARRICK_FROM_UPPER_DECK;
            _pathPostTalk = PATH_GARRICK_TO_LOWER_DECK;
            _waitTime = 0s;
        }
        else if (me->GetEntry() == NPC_WARLORD_BREKA_GRIMAXE3)
        {
            _pathPreTalk = PATH_GRIMAXE_FROM_UPPER_DECK;
            _pathPostTalk = PATH_GRIMAXE_TO_LOWER_DECK;
            _waitTime = 1s;
        }

        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->GetMotionMaster()->MovePath(_pathPreTalk, false);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathPreTalk)
            _events.ScheduleEvent(EVENT_SHIP_CAPTAIN2_SCRIPT1, _waitTime);
        else if (pathId == _pathPostTalk)
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
                    _events.ScheduleEvent(EVENT_SHIP_CAPTAIN2_SCRIPT2, 3s);
                    break;
                case EVENT_SHIP_CAPTAIN2_SCRIPT2:
                    me->GetMotionMaster()->MovePath(_pathPostTalk, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    uint32 _pathPreTalk;
    uint32 _pathPostTalk;
    Seconds _waitTime;
};

enum BraceForImpactFirstMateData
{
    NPC_PRIVATE_COLE                = 160664,
    NPC_GRUNT_THROG                 = 166583,

    PATH_COLE_BRACE_FOR_IMPACT      = 10501461,
    PATH_THROG_BRACE_FOR_IMPACT     = 10501871,

    EVENT_FIRST_MATE_1              = 1,
    EVENT_FIRST_MATE_2,

    SAY_STORM = 0,
};

// 160664 - Private Cole
// 166583 - Grunt Throg
struct npc_first_mate_brace_for_impact_private : public ScriptedAI
{
    npc_first_mate_brace_for_impact_private(Creature* creature) : ScriptedAI(creature), _path(0) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_PRIVATE_COLE)
            _path = PATH_COLE_BRACE_FOR_IMPACT;
        else if (me->GetEntry() == NPC_GRUNT_THROG)
            _path = PATH_THROG_BRACE_FOR_IMPACT;

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
    uint32 _path;
};

enum BraceForImpactCrewData
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
    PATH_JIN_HAKE_BRACE_FOR_IMPACT  = 10502000,
};

// 157042 - Quartermaster Richter
// 157043 - Kee-La
// 157044 - Bjorn Stouthands
// 157046 - Austin Huxworth
// 166585 - Bo
// 166590 - Mithdran Dawntracker
// 166794 - Lana Jordan
// 166799 - Provisoner Jin'hake
struct npc_crew_ship_private : public ScriptedAI
{
    npc_crew_ship_private(Creature* creature) : ScriptedAI(creature), _path(0) { }

    uint32 GetPathID()
    {
        switch (me->GetEntry())
        {
            case NPC_QUARTERMASTER_RICHTER: return PATH_RICHTER_BRACE_FOR_IMPACT;
            case NPC_KEE_LA:                return PATH_KEE_LA_BRACE_FOR_IMPACT;
            case NPC_BJORN_STOUTHANDS:      return PATH_BJORN_BRACE_FOR_IMPACT;
            case NPC_AUSTIN_HUXWORTH:       return PATH_AUSTIN_BRACE_FOR_IMPACT;
            case NPC_BO:                    return PATH_BO_BRACE_FOR_IMPACT;
            case NPC_MITHDRAN_DAWNTRACKER:  return PATH_MITHDRAN_BRACE_FOR_IMPACT;
            case NPC_LANA_JORDAN:           return PATH_LANA_BRACE_FOR_IMPACT;
            case NPC_PROVISONER_JIN_HAKE:   return PATH_JIN_HAKE_BRACE_FOR_IMPACT;
            default:                        return 0;
        }
    }

    void JustAppeared() override
    {
        _path = GetPathID();
        _scheduler.Schedule(Seconds(7), [this](TaskContext)
        {
            me->GetMotionMaster()->MovePath(_path, false);
        });
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
    uint32 _path;
};

enum BraceForImpactPetData
{
    EVENT_PET_SHIP_RUN_TO_POSITION = 1,

    MAP_ALLIANCE_SHIP              = 2261,
    MAP_HORDE_SHIP                 = 2369,

    PATH_PET_ALLIANCE_SHIP         = 10501510,
    PATH_PET_HORDE_SHIP            = 10502020
};

// 167337 - Mechanical Bunny
// 167342 - Moth
// 167343 - Dragonhawk
// 167344 - Scorpion
// 167345 - Wolf
// 167346 - Wolf
// 167347 - Tiger
// 167348 - Turtle
// 167349 - Plainstrider
// 167350 - Raptor
// 167351 - Bat
// 167352 - Dog
// 167375 - Bear
struct npc_pet_ship_private : public ScriptedAI
{
    npc_pet_ship_private(Creature* creature) : ScriptedAI(creature), _path(0) { }

    void JustAppeared() override
    {
        if (!me->GetTransport())
            return;

        int32 transportMap = me->GetTransport()->GetMapIdForSpawning();
        if (transportMap == MAP_ALLIANCE_SHIP)
            _path = PATH_PET_ALLIANCE_SHIP;
        else if (transportMap == MAP_HORDE_SHIP)
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
    uint32 _path;
};

enum ExilesReachShipCrashData
{
    MOVIE_ALLIANCE_SHIP_CRASH       = 895,
    MOVIE_HORDE_SHIP_CRASH          = 931,

    SPELL_ALLIANCE_SHIP_CRASH       = 305446,
    SPELL_HORDE_SHIP_CRASH          = 325133,
    SPELL_BEGIN_TUTORIAL            = 295600,
};

class player_exiles_reach_ship_crash : public PlayerScript
{
public:
    player_exiles_reach_ship_crash() : PlayerScript("player_exiles_reach_ship_crash") { }

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

class scene_alliance_and_horde_ship : public SceneScript
{
public:
    scene_alliance_and_horde_ship() : SceneScript("scene_alliance_and_horde_ship") { }

    void StartConvo(Player* player)
    {
        // This script is used to send conversation to Captian Garrick and Warlord Grimaxe on movement after entering ship
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        StartConvo(player);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        StartConvo(player);
    }
};

// ***************************************************************
// * Scripting in this section occurs after teleporting to beach *
// ***************************************************************

enum KnockedDownExilesReachData
{
    SPELL_KNOCKED_DOWN_STUN2 = 344889
};

// 305445 - Knocked Down!
class spell_knocked_down_exiles_reach_beach : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_KNOCKED_DOWN_STUN2 });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_KNOCKED_DOWN_STUN2, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_knocked_down_exiles_reach_beach::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

enum ExilesReachShipCrashBeachData
{
    SPELL_KNOCKED_DOWN              = 305445,
    SPELL_CRASHED_LANDED_ALLIANCE   = 305464,
    SPELL_CRASHED_LANDED_HORDE      = 325136
};

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

enum SpellCrashLandedData
{
    NPC_CAPTAIN_GARRICK_BEACH       = 156626,
    NPC_WARLORD_BREKA_GRIMAXE_BEACH = 166782
};

// 305464 - Crash Landed
// 325136 - Crash Landed
template<uint32 StaticCaptainNPCId>
class spell_crash_landed_generic : public SpellScript
{
    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        if (Creature* creature = player->FindNearestCreature(StaticCaptainNPCId, 50.0f))
            creature->SummonPersonalClone(creature->GetPosition(), TempSummonType(TEMPSUMMON_MANUAL_DESPAWN), 0s, 0, 0, player);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_crash_landed_generic::HandleEffect, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
    }
};

enum ExilesReachCaptainsBeachData
{
    CONVERSATION_QUEST_MURLOC_MANIA_ALLIANCE               = 12043,
    CONVERSATION_QUEST_MURLOC_MANIA_HORDE                  = 14432,

    EVENT_EMERGENCY_FIRST_AID_SCRIPT_SHEATH                = 1,
    EVENT_EMERGENCY_FIRST_AID_SCRIPT_BANDAGE,
    EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_SECOND_SURVIVOR,
    EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_HOME_BEACH,

    POINT_SECOND_SURVIVOR                                  = 0,
    POINT_BEACH_HOME                                       = 1,

    QUEST_MURLOC_MANIA_ALLIANCE                            = 55122,
    QUEST_EMERGENCY_FIRST_AID_ALLIANCE                     = 54951,
    QUEST_MURLOC_MANIA_HORDE                               = 59929,
    QUEST_EMERGENCY_FIRST_AID_HORDE                        = 59930,

    SPELL_BANDAGING                                        = 305584,

    TALK_ARRIVED_AT_BEACH                                  = 0
};

// 156626 - Captain Garrick
// 166782 - Warlord Breka Grimaxe
struct npc_captain_warlord_beach_arrive_private : public ScriptedAI
{
    npc_captain_warlord_beach_arrive_private(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Player* summoner = summonerWO->ToPlayer();
        if (!summoner)
            return;

        me->SetFacingToObject(summoner);
        Talk(TALK_ARRIVED_AT_BEACH, summoner);
        me->DespawnOrUnsummon(5s);
    }
};

// 156626 - Captain Garrick
// 166782 - Warlord Breka Grimaxe
// for Emergency first aid quest 54951
struct npc_captain_warlord_first_aid_private : public ScriptedAI
{
    npc_captain_warlord_first_aid_private(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Player* summoner = summonerWO->ToPlayer();
        if (!summoner)
            return;

        _events.ScheduleEvent(EVENT_EMERGENCY_FIRST_AID_SCRIPT_SHEATH, 2s);
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case POINT_SECOND_SURVIVOR:
                if (Creature* mate = ObjectAccessor::GetCreature(*me, _quartermasterGUID))
                    me->CastSpell(mate, SPELL_BANDAGING);
                _events.ScheduleEvent(EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_HOME_BEACH, 6s);
                break;
            case POINT_BEACH_HOME:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EMERGENCY_FIRST_AID_SCRIPT_SHEATH:
                    me->SetSheath(SHEATH_STATE_UNARMED);
                    _events.ScheduleEvent(EVENT_EMERGENCY_FIRST_AID_SCRIPT_BANDAGE, 1s);
                    break;
                case EVENT_EMERGENCY_FIRST_AID_SCRIPT_BANDAGE:
                    if (Creature* mate = ObjectAccessor::GetCreature(*me, _firstMateGUID))
                        me->CastSpell(mate, SPELL_BANDAGING);
                    _events.ScheduleEvent(EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_SECOND_SURVIVOR, 5s);
                    break;
                case EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_SECOND_SURVIVOR:
                    me->GetMotionMaster()->MovePoint(POINT_SECOND_SURVIVOR, -414.15277f, -2605.2014f, 0.91079247f, false);
                    break;
                case EVENT_EMERGENCY_FIRST_AID_SCRIPT_MOVE_HOME_BEACH:
                    me->GetMotionMaster()->MovePoint(POINT_BEACH_HOME, -435.15277f, -2610.9915f, 0.649292f, false);
                    break;
                default:
                    break;
            }
        }
    }

public:
    void SetFirstMateGUID(ObjectGuid coleGUID)
    {
        _firstMateGUID = coleGUID;
    }

    void SetQuartermasterGUID(ObjectGuid richterGUID)
    {
        _quartermasterGUID = richterGUID;
    }

private:
    EventMap _events;
    ObjectGuid _firstMateGUID;
    ObjectGuid _quartermasterGUID;
};

// 156626 - Captain Garrick
struct npc_captain_garrick_beach : public ScriptedAI
{
    npc_captain_garrick_beach(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_MURLOC_MANIA_ALLIANCE:
                Conversation::CreateConversation(CONVERSATION_QUEST_MURLOC_MANIA_ALLIANCE, player, *player, player->GetGUID(), nullptr);
                break;
            case QUEST_EMERGENCY_FIRST_AID_ALLIANCE:
            {
                Creature* cole = FindCreatureIgnorePhase(player, "private_cole_beach", 50.0f);
                Creature* richter = FindCreatureIgnorePhase(player, "quartermaster_richter_beach", 50.0f);
                if (!cole || !richter)
                    return;

                Creature* colePersonal = cole->SummonPersonalClone(cole->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                Creature* richterPersonal = richter->SummonPersonalClone(richter->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                Creature* mePersonal = me->SummonPersonalClone(me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                if (!colePersonal || !richterPersonal || !mePersonal)
                    return;

                if (npc_captain_warlord_first_aid_private* personalAI = CAST_AI(npc_captain_warlord_first_aid_private, mePersonal->GetAI()))
                {
                    personalAI->SetFirstMateGUID(colePersonal->GetGUID());
                    personalAI->SetQuartermasterGUID(richterPersonal->GetGUID());
                }
                break;
            }
            default:
                break;
        }
    }
};

// 166782 - Warlord Breka Grimaxe
struct npc_warlord_grimaxe_beach : public ScriptedAI
{
    npc_warlord_grimaxe_beach(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_MURLOC_MANIA_HORDE:
                Conversation::CreateConversation(CONVERSATION_QUEST_MURLOC_MANIA_HORDE, player, *player, player->GetGUID(), nullptr);
                break;
            case QUEST_EMERGENCY_FIRST_AID_HORDE:
            {
                Creature* throg = FindCreatureIgnorePhase(player, "grunt_throg_beach", 50.0f);
                Creature* jinhake = FindCreatureIgnorePhase(player, "jin_hake_beach", 50.0f);
                if (!throg || !jinhake)
                    return;

                Creature* throgPersonal = throg->SummonPersonalClone(throg->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                Creature* jinhakePersonal = jinhake->SummonPersonalClone(jinhake->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                Creature* mePersonal = me->SummonPersonalClone(me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                if (!throgPersonal || !jinhakePersonal || !mePersonal)
                    return;

                if (npc_captain_warlord_first_aid_private* personalAI = CAST_AI(npc_captain_warlord_first_aid_private, mePersonal->AI()))
                {
                    personalAI->SetFirstMateGUID(throgPersonal->GetGUID());
                    personalAI->SetQuartermasterGUID(jinhakePersonal->GetGUID());
                }
                break;
            }
            default:
                break;
        }
    }
};

CreatureAI* CaptainGarrickBeachAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if (privateObjectOwner->GetQuestStatus(QUEST_MURLOC_MANIA_ALLIANCE) == QUEST_STATUS_NONE)
                return new npc_captain_warlord_beach_arrive_private(creature);
            else
                return new npc_captain_warlord_first_aid_private(creature);
        }
    }
    return new npc_captain_garrick_beach(creature);
};

CreatureAI* WarlordGrimaxeBeachAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if (privateObjectOwner->GetQuestStatus(QUEST_MURLOC_MANIA_HORDE) == QUEST_STATUS_NONE)
                return new npc_captain_warlord_beach_arrive_private(creature);
            else
                return new npc_captain_warlord_first_aid_private(creature);
        }
    }
    return new npc_warlord_grimaxe_beach(creature);
};

enum HealedByLeaderBeachData
{
    EVENT_SALUTE       = 1,
    EVENT_LEAVE_BEACH,

    NPC_COLE_BEACH     = 149917,
    NPC_RICHTER_BEACH  = 156622,
    NPC_THROG_BEACH    = 166784,
    NPC_JINHAKE_BEACH  = 166800,

    PATH_LONG_BEACH    = 10520070,
    PATH_SHORT_BEACH   = 10520080
};

// 149917 - Private Cole
// 156622 - Quartermaster Richter
// 166784 - Grunt Throg
// 166800 - Provisioner Jin'hake
// for Emergency first aid quest
template<uint32 PathId, uint32 WaitTime>
struct npc_survivors_healed_by_leader_beach_private : public ScriptedAI
{
    npc_survivors_healed_by_leader_beach_private(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetStandState(UNIT_STAND_STATE_SLEEP);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_BANDAGING)
            return;

        _casterGUID = caster->GetGUID();
        me->SetStandState(UNIT_STAND_STATE_STAND);
        _events.ScheduleEvent(EVENT_SALUTE, 2s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SALUTE:
                    if (Creature* caster = ObjectAccessor::GetCreature(*me, _casterGUID))
                        me->SetFacingToObject(caster);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    _events.ScheduleEvent(EVENT_LEAVE_BEACH, 2s);
                    break;
                case EVENT_LEAVE_BEACH:
                    me->GetMotionMaster()->MovePath(PathId, false);
                    me->DespawnOrUnsummon(Milliseconds(WaitTime));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    ObjectGuid _casterGUID;
};

CreatureAI* HealedByLeaderAllianceAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_survivors_healed_by_leader_beach_private<PATH_LONG_BEACH, 16 * IN_MILLISECONDS>(creature);
    return new NullCreatureAI(creature);
};

CreatureAI* HealedByLeaderHordeAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_survivors_healed_by_leader_beach_private<PATH_SHORT_BEACH, 9 * IN_MILLISECONDS>(creature);
    return new NullCreatureAI(creature);
};

enum ExilesReachAllianceSurvivorsBeachData
{
    CONVERSATION_STOUTHANDS_BEACH         = 11685,
    CONVERSATION_HUXWORTH_BEACH           = 12128,
    CONVERSATION_KEE_LA_BEACH             = 12127,

    NPC_BJORN_STOUTHANDS_LAYING           = 156609,
    NPC_AUSTIN_HUXWORTH_LAYING            = 156610,
    NPC_KEE_LA_LAYING                     = 156612,
    NPC_KEE_LA_STANDING                   = 151088,
    NPC_BJORN_STOUTHANDS_STANDING         = 151089,
    NPC_AUSTIN_HUXWORTH_STANDING          = 154170,

    PATH_KEE_LA_STANDING                  = ((1052012 * 10) + 1) << 3,
    PATH_BJORN_STOUTHANDS_STANDING        = ((1052013 * 10) + 1) << 3,
    PATH_AUSTIN_HUXWORTH_STANDING         = ((1052014 * 10) + 1) << 3,

    SPELL_BANDAGING_QUEST                 = 297415
};

// 156609 - Bjorn Stouthands
// 156610 - Austin Huxworth
// 156612 - Kee-La
template<uint32 ConversationId>
struct npc_alliance_survivors_beach_laying : public ScriptedAI
{
    npc_alliance_survivors_beach_laying(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_BANDAGING_QUEST)
            return;

        if (Player* player = caster->ToPlayer())
        {
            player->KilledMonsterCredit(me->GetEntry());
            Conversation::CreateConversation(ConversationId, player, *player, player->GetGUID(), nullptr);
            player->UpdateVisibilityForPlayer(); // Needed to make survivor stand instantly
        }
    }
};

enum ExilesReachHordeSurvivorsBeachData
{
    EVENT_SURVIVORS_HORDE_STAND_AND_TALK        = 1,
    EVENT_SURVIVORS_HORDE_MOVE_TO_GRIMAXE,

    EVENT_SURVIVORS_SALUTE                      = 1,
    EVENT_SURVIVORS_LEAVE_BEACH,

    NPC_BO_LAYING_LAYING                        = 166786,
    NPC_MITHDRAN_LAYING                         = 166791,
    NPC_LANA_JORDAN_LAYING                      = 166796,
    NPC_BO_STANDING                             = 166787,
    NPC_MITHDRAN_STANDING                       = 166792,
    NPC_LANA_JORDAN_STANDING                    = 166797,

    QUEST_FINDING_THE_LOST_EXPEDITION_HORDE     = 59931,
    QUEST_FINDING_THE_LOST_EXPEDITION_ALLIANCE  = 54952,

    PATH_BO_TO_GRIMAXE                          = 10520210,
    PATH_MITHDRAN_TO_GRIMAXE                    = 10520220,
    PATH_LANA_JORDAN_TO_GRIMAXE                 = 10520230,

    PATH_BO_LEAVE_BEACH                         = ((1052021 * 10) + 1) << 3,
    PATH_MITHDRAN_LEAVE_BEACH                   = ((1052022 * 10) + 1) << 3,
    PATH_LANA_JORDAN_LEAVE_BEACH                = ((1052023 * 10) + 1) << 3,

    TALK_HORDE_BEACH_THANK_PLAYER               = 0
};

// 166786 - Bo
struct npc_bo_beach_laying : public ScriptedAI
{
    npc_bo_beach_laying(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_BANDAGING_QUEST)
            return;

        static const Position BoCloneSpawnPosition = { -448.731f, -2606.03f, 0.602435f, 6.17441f };

        if (Player* player = caster->ToPlayer())
        {
            player->KilledMonsterCredit(me->GetEntry());

            if (Creature* survivor = FindCreatureIgnorePhase(player, "bo_beach", 50.0f))
                survivor->SummonPersonalClone(BoCloneSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

// 166791 - Mithdran Dawntracker
struct npc_mithran_dawntracker_beach_laying : public ScriptedAI
{
    npc_mithran_dawntracker_beach_laying(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_BANDAGING_QUEST)
            return;

        static Position const MithranCloneSpawnPosition = { -428.576f, -2593.93f, 0.152832f, 4.849576f };

        if (Player* player = caster->ToPlayer())
        {
            player->KilledMonsterCredit(me->GetEntry());

            if (Creature* survivor = FindCreatureIgnorePhase(player, "mithran_beach", 50.0f))
                survivor->SummonPersonalClone(MithranCloneSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

// 166796 - Lana Jordan
struct npc_lana_jordan_beach_laying : public ScriptedAI
{
    npc_lana_jordan_beach_laying(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_BANDAGING_QUEST)
            return;

        static Position const LanaCloneSpawnPosition = { -420.656f, -2600.28f, 0.556646f, 4.046853f };

        if (Player* player = caster->ToPlayer())
        {
            player->KilledMonsterCredit(me->GetEntry());

            if (Creature* survivor = FindCreatureIgnorePhase(player, "lana_jordan_beach", 50.0f))
                survivor->SummonPersonalClone(LanaCloneSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

enum ExilesReachMurlocsData
{
    ITEM_STITCHED_CLOTH_SHOES           = 174791,
    ITEM_STITCHED_LEATHER_BOOTS         = 174792,
    ITEM_LINKED_MAIL_BOOTS              = 174793,
    ITEM_DENTED_PLATE_BOOTS             = 174794,

    QUEST_MURLOC_HIDEAWAY_BOOTS_DROPPED = 58883
};

// 150228 - Murloc Spearhunter
// 150229 - Murloc Watershaper
struct npc_murloc_spearhunter_watershaper : public ScriptedAI
{
    npc_murloc_spearhunter_watershaper(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        for (auto const& [playerGuid, loot] : me->m_personalLoot)
        {
            for (LootItem const& lootItem : loot->items)
            {
                if (lootItem.itemid == ITEM_STITCHED_CLOTH_SHOES || lootItem.itemid == ITEM_STITCHED_LEATHER_BOOTS || lootItem.itemid == ITEM_LINKED_MAIL_BOOTS || lootItem.itemid == ITEM_DENTED_PLATE_BOOTS)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                        player->SetRewardedQuest(QUEST_MURLOC_HIDEAWAY_BOOTS_DROPPED);
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// 150228 - Murloc Spearhunter
// 150229 - Murloc Watershaper
struct npc_murloc_spearhunter_watershaper_higher_ground : public npc_murloc_spearhunter_watershaper
{
    npc_murloc_spearhunter_watershaper_higher_ground(Creature* creature) : npc_murloc_spearhunter_watershaper(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        me->GetMotionMaster()->MoveJump(who->GetPosition(), 16.0f, 6.2f);
    }
};

// 166787 - Bo
// 166792 - Mithdran Dawntracker
// 166797 - Lana Jordan
template<uint32 PathId>
struct npc_horde_survivors_beach_q59930_private : public ScriptedAI
{
    npc_horde_survivors_beach_q59930_private(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetStandState(UNIT_STAND_STATE_SLEEP);
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_SURVIVORS_HORDE_STAND_AND_TALK, 1s);
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
            switch (eventId)
            {
                case EVENT_SURVIVORS_HORDE_STAND_AND_TALK:
                    Talk(TALK_HORDE_BEACH_THANK_PLAYER);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    _events.ScheduleEvent(EVENT_SURVIVORS_HORDE_MOVE_TO_GRIMAXE, 6s);
                    break;
                case EVENT_SURVIVORS_HORDE_MOVE_TO_GRIMAXE:
                    me->GetMotionMaster()->MovePath(PathId, false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

// 151088 - Kee La
// 151089 - Bjorn Stouthands
// 154170 - Austin Huxworth
// 166787 - Bo
// 166792 - Mithdran Dawntracker
// 166797 - Lana Jordan
template<uint32 PathId, uint32 WaitTime>
struct npc_survivors_beach_leave_private : public ScriptedAI
{
    npc_survivors_beach_leave_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_SURVIVORS_SALUTE, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SURVIVORS_SALUTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    _events.ScheduleEvent(EVENT_SURVIVORS_LEAVE_BEACH, 2s);
                    break;
                case EVENT_SURVIVORS_LEAVE_BEACH:
                    me->GetMotionMaster()->MovePath(PathId, false);
                    me->DespawnOrUnsummon(Milliseconds(WaitTime));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

CreatureAI* BoBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if ((privateObjectOwner->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_HORDE) == QUEST_STATUS_NONE))
                return new npc_horde_survivors_beach_q59930_private<PATH_BO_TO_GRIMAXE>(creature);
            else
                return new npc_survivors_beach_leave_private<PATH_BO_LEAVE_BEACH, 5 * IN_MILLISECONDS>(creature);
        }
    }

    return new NullCreatureAI(creature);
};

CreatureAI* MithdranBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if ((privateObjectOwner->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_HORDE) == QUEST_STATUS_NONE))
                return new npc_horde_survivors_beach_q59930_private<PATH_MITHDRAN_TO_GRIMAXE>(creature);
            else
                return new npc_survivors_beach_leave_private<PATH_MITHDRAN_LEAVE_BEACH, 4 * IN_MILLISECONDS>(creature);
        }
    }

    return new NullCreatureAI(creature);
};

CreatureAI* LanaJordanBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
    {
        if (Player* privateObjectOwner = ObjectAccessor::GetPlayer(*creature, creature->GetPrivateObjectOwner()))
        {
            if ((privateObjectOwner->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_HORDE) == QUEST_STATUS_NONE))
                return new npc_horde_survivors_beach_q59930_private<PATH_LANA_JORDAN_TO_GRIMAXE>(creature);
            else
                return new npc_survivors_beach_leave_private<PATH_LANA_JORDAN_LEAVE_BEACH, 5 * IN_MILLISECONDS>(creature);
        }
    }

    return new NullCreatureAI(creature);
};

CreatureAI* KeeLaBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_survivors_beach_leave_private<PATH_KEE_LA_STANDING, 7 * IN_MILLISECONDS>(creature);
    return new NullCreatureAI(creature);
};

CreatureAI* BjornBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_survivors_beach_leave_private<PATH_BJORN_STOUTHANDS_STANDING, 4 * IN_MILLISECONDS>(creature);
    return new NullCreatureAI(creature);
};

CreatureAI* AustinBeachStandingAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_survivors_beach_leave_private<PATH_AUSTIN_HUXWORTH_STANDING, 5 * IN_MILLISECONDS>(creature);
    return new NullCreatureAI(creature);
};

enum LostExpeditionFollowerData
{
    ACTOR_ID_ALLIANCE_SURVIVOR                  = 69830,
    ACTOR_ID_HORDE_SURVIVOR                     = 76283,

    AREA_ABANDONED_CAMP                         = 10452,

    CONVERSATION_LINE_ESCORT_ALLIANCE_SURVIVOR  = 12044,
    CONVERSATION_LINE_ESCORT_HORDE_SURVIVOR     = 14437,
    CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP      = 12058,

    EVENT_INITIAL_SPAWN_CHECK                   = 1,
    EVENT_FOLLOW_PLAYER,

    SPELL_GARRICK_PING                          = 313664,
    SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN       = 297295,
    SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN       = 325075,

    POINT_CAMP_POSITION                         = 0,
};

Position const GarrickAbandonedCampPosition = { -249.059006f, -2492.520020f, 18.0742f };
Position const GrimaxeAbandonedCampPosition = { -249.20117f, -2492.6191f, 17.964903f };

// 165359 - Captain Garrick
// This script is used by Captian Garrick Follower for Finding the Lost Expedition quest
struct npc_garrick_summoned_beach : public ScriptedAI
{
    npc_garrick_summoned_beach(Creature* creature) : ScriptedAI(creature), _reachedCamp(false) {}

    void IsSummonedBy(WorldObject* summoner) override
    {
        Player* player = summoner->ToPlayer();
        if (!player)
            return;

        _playerGUID = player->GetGUID();

        _events.ScheduleEvent(EVENT_INITIAL_SPAWN_CHECK, 1s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_GARRICK_PING)
            return;

        if (_reachedCamp)
            return;

        _reachedCamp = true;

        if (Player* player = caster->ToPlayer())
        {
            Conversation* conversation = Conversation::CreateConversation(CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP, player, *player, _playerGUID, nullptr, false);
            conversation->AddActor(ACTOR_ID_ALLIANCE_SURVIVOR, 1, me->GetGUID());
            conversation->Start();

            me->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);
            me->GetMotionMaster()->MovePoint(POINT_CAMP_POSITION, GarrickAbandonedCampPosition, false);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE || uiId != POINT_CAMP_POSITION)
            return;

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->RemoveAura(SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INITIAL_SPAWN_CHECK:
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID);
                    if (!player)
                        break;

                    Creature* survivor = FindCreatureIgnorePhase(player, "spawn_check");

                    if (!survivor)
                    {
                        if (player->GetAreaId() != AREA_ABANDONED_CAMP)
                            player->RemoveAura(SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN);
                        else
                            _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 0s);
                    }
                    else
                    {
                        Conversation* conversation = Conversation::CreateConversation(CONVERSATION_LINE_ESCORT_ALLIANCE_SURVIVOR, player, *player, _playerGUID, nullptr, false);
                        conversation->AddActor(ACTOR_ID_ALLIANCE_SURVIVOR, 1, me->GetGUID());
                        conversation->Start();

                        _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 2s);
                    }
                    break;
                }
                case EVENT_FOLLOW_PLAYER:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        me->GetMotionMaster()->MoveFollow(player, 0.0f, float(M_PI / 4.0f));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    ObjectGuid _playerGUID;
    bool _reachedCamp;
};

// 166805 - Warlord Breka Grimaxe
// This script is used by Warlord Grimaxe Follower for Finding the Lost Expedition quest
struct npc_grimaxe_summoned_beach : public ScriptedAI
{
    npc_grimaxe_summoned_beach(Creature* creature) : ScriptedAI(creature), _reachedCamp(false) {}

    void IsSummonedBy(WorldObject* summoner) override
    {
        Player* player = summoner->ToPlayer();
        if (!player)
            return;

        _playerGUID = player->GetGUID();
        _reachedCamp = false;

        _events.ScheduleEvent(EVENT_INITIAL_SPAWN_CHECK, 1s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_GARRICK_PING)
            return;

        if (_reachedCamp)
            return;

        if (Player* player = caster->ToPlayer())
        {
            Conversation* conversation = Conversation::CreateConversation(CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP, player, *player, _playerGUID, nullptr, false);
            conversation->AddActor(ACTOR_ID_HORDE_SURVIVOR, 3, me->GetGUID());
            conversation->Start();

            me->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);
            me->GetMotionMaster()->MovePoint(POINT_CAMP_POSITION, GrimaxeAbandonedCampPosition, false);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE || uiId != POINT_CAMP_POSITION)
            return;

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->RemoveAura(SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INITIAL_SPAWN_CHECK:
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID);
                    if (!player)
                        break;

                    Creature* survivor = FindCreatureIgnorePhase(player, "spawn_check");

                    if (!survivor)
                    {
                        if (player->GetAreaId() != AREA_ABANDONED_CAMP)
                            player->RemoveAura(SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN);
                        else
                            _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 0s);
                    }
                    else
                    {
                        Conversation* conversation = Conversation::CreateConversation(CONVERSATION_LINE_ESCORT_HORDE_SURVIVOR, player, *player, _playerGUID, nullptr, false);
                        conversation->AddActor(ACTOR_ID_HORDE_SURVIVOR, 2, me->GetGUID());
                        conversation->Start();

                        _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 2s);
                    }
                    break;
                }
                case EVENT_FOLLOW_PLAYER:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        me->GetMotionMaster()->MoveFollow(player, 0.0f, float(M_PI / 4.0f));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    ObjectGuid _playerGUID;
    bool _reachedCamp;
};

// 54952 - Finding the Lost Expedition
// 59931 - Finding the Lost Expedition
class quest_finding_the_lost_expedition : public QuestScript
{
public:
    quest_finding_the_lost_expedition(char const* script) : QuestScript(script) { }

    void HandleQuestStatusChange(Player* player, QuestStatus newStatus, uint32 summonSpellId, std::string_view survivor1StringId, std::string_view survivor2StringId, std::string_view survivor3StringId)
    {
        switch (newStatus)
        {
            case QUEST_STATUS_INCOMPLETE:
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
                player->CastSpell(player, summonSpellId);

                if (Creature* survivor1 = FindCreatureIgnorePhase(player, survivor1StringId, 25.0f))
                {
                    Creature* survivor1Personal = survivor1->SummonPersonalClone(survivor1->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                    survivor1Personal->SetScriptStringId("spawn_check");
                }
                if (Creature* survivor2 = FindCreatureIgnorePhase(player, survivor2StringId, 25.0f))
                    survivor2->SummonPersonalClone(survivor2->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
                if (Creature* survivor3 = FindCreatureIgnorePhase(player, survivor3StringId, 25.0f))
                    survivor3->SummonPersonalClone(survivor3->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);

                break;
            case QUEST_STATUS_NONE:
                player->RemoveAura(summonSpellId);
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
                break;
            default:
                break;
        }
    }
};

// 54952 - Finding the Lost Expedition
class quest_finding_the_lost_expedition_alliance : public quest_finding_the_lost_expedition
{
public:
    quest_finding_the_lost_expedition_alliance() : quest_finding_the_lost_expedition("quest_finding_the_lost_expedition_alliance") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus,
            SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN,
            "kee_la_beach",
            "bjorn_stouthands_beach",
            "austin_huxworth_beach");
    }
};

// 59931 - Finding the Lost Expedition
class quest_finding_the_lost_expedition_horde : public quest_finding_the_lost_expedition
{
public:
    quest_finding_the_lost_expedition_horde() : quest_finding_the_lost_expedition("quest_finding_the_lost_expedition_horde") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus,
            SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN,
            "bo_beach",
            "mithran_beach",
            "lana_jordan_beach");
    }
};

// 305596 - Summon Admiral Garrick Guardian
// 325076 - Summon Warlord Grimaxe
class spell_summon_survivor_beach : public SpellScript
{
    void SelectTarget(WorldObject*& target)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        Creature* survivor = FindCreatureIgnorePhase(caster, caster->GetTeam() == ALLIANCE ? "q54952_garrick" : "q59931_grimaxe", 5.0f);
        if (!survivor)
            return;

        target = survivor;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_summon_survivor_beach::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY_OR_DB);
    }
};

// ******************************************************************
// * Scripting in this section occurs after reaching Abandoned Camp *
// ******************************************************************

enum CaptainGarrickAbandonedCampData
{
    CONVERSATION_QUEST_COOKING_MEAT_ACCEPT_ALLIANCE     = 11696,
    CONVERSATION_QUEST_COOKING_MEAT_COMPLETE_ALLIANCE   = 12863,

    QUEST_COOKING_MEAT_ALLIANCE                         = 55174
};

enum WarlordGrimaxeAbandonedCampData
{
    CONVERSATION_QUEST_COOKING_MEAT_ACCEPT_HORDE        = 14439,
    CONVERSATION_QUEST_COOKING_MEAT_COMPLETE_HORDE      = 14611,

    QUEST_COOKING_MEAT_HORDE                            = 59932
};

template<uint32 QuestId, uint32 ConversationId>
struct npc_captain_abandoned_camp_exiles_reach : public ScriptedAI
{
    npc_captain_abandoned_camp_exiles_reach(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() != QuestId)
            return;

        Conversation::CreateConversation(ConversationId, player, *player, player->GetGUID());
    }
};

enum CookingMeatQuestData
{
    ANIMATION_KIT_INJURED = 14432
};

Position const InjuredNpcPositionAbandonedCamp = { -245.40973f, -2492.0886f, 18.404648f, 2.4754f };

// 55174 - Cooking Meat
// 59932 - Cooking Meat
class quest_cooking_meat : public QuestScript
{
public:
    quest_cooking_meat(char const* script) : QuestScript(script) { }

    void HandleQuestStatusChange(Player* player, QuestStatus newStatus, uint32 completeConversationId, std::string_view injuredStringId)
    {
        switch (newStatus)
        {
            case QUEST_STATUS_COMPLETE:
            {
                Conversation::CreateConversation(completeConversationId, player, *player, player->GetGUID());
                break;
            }
            case QUEST_STATUS_REWARDED:
            {
                Creature* injured = FindCreatureIgnorePhase(player, injuredStringId);
                if (!injured)
                    break;

                Creature* injuredTemp = injured->SummonPersonalClone(InjuredNpcPositionAbandonedCamp, TEMPSUMMON_TIMED_DESPAWN, 2s, 0, 0, player);
                injuredTemp->SetAIAnimKitId(ANIMATION_KIT_INJURED);
                break;
            }
            default:
                break;
        }
    }
};

// 55174 - Cooking Meat
class quest_cooking_meat_alliance : public quest_cooking_meat
{
public:
    quest_cooking_meat_alliance() : quest_cooking_meat("quest_cooking_meat_alliance") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus,
            CONVERSATION_QUEST_COOKING_MEAT_COMPLETE_ALLIANCE,
            "alaria_standing_abandoned_camp");
    }
};

// 59932 - Cooking Meat
class quest_cooking_meat_horde : public quest_cooking_meat
{
public:
    quest_cooking_meat_horde() : quest_cooking_meat("quest_cooking_meat_horde") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus,
            CONVERSATION_QUEST_COOKING_MEAT_COMPLETE_HORDE,
            "wonza_standing_abandoned_camp");
    }
};

struct areatrigger_find_the_lost_expedition : AreaTriggerAI
{
    areatrigger_find_the_lost_expedition(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        if (player->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_ALLIANCE) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_HORDE) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, SPELL_GARRICK_PING);
    }
};

struct areatrigger_find_the_lost_expedition_follower : AreaTriggerAI
{
    areatrigger_find_the_lost_expedition_follower(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        if (player->GetTeam() == ALLIANCE)
        {
            if (player->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_ALLIANCE) != QUEST_STATUS_INCOMPLETE)
                return;

            if (player->HasAura(SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN))
                return;

            player->CastSpell(player, SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN);
        }
        else
        {
            if (player->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION_HORDE) != QUEST_STATUS_INCOMPLETE)
                return;

            if (player->HasAura(SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN))
                return;

            player->CastSpell(player, SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN);
        }
    }
};

// Enhanced Combat Tacktics Quest

enum EnhancedCombatTactics
{
    SPELL_SUMMON_CAPTAIN_GARRICK_COMBAT = 320211,
    SPELL_SUMMON_WARLORD_GRIMAXE_COMBAT = 325180
};

class quest_enhanced_combat_tactics : public QuestScript
{
public:
    quest_enhanced_combat_tactics() : QuestScript("quest_enhanced_combat_tactics") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        switch (newStatus)
        {
        case QUEST_STATUS_INCOMPLETE:
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->CastSpell(player, player->GetTeam() == ALLIANCE ? SPELL_SUMMON_CAPTAIN_GARRICK_COMBAT : SPELL_SUMMON_WARLORD_GRIMAXE_COMBAT);
            break;
        case QUEST_STATUS_NONE:
            player->RemoveAura(player->GetTeam() == ALLIANCE ? SPELL_SUMMON_CAPTAIN_GARRICK_COMBAT : SPELL_SUMMON_WARLORD_GRIMAXE_COMBAT);
            player->UpdateObjectVisibility();
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            break;
        default:
            break;
        }
    }
};

// Used for spells 320175 and 325181

class spell_summon_combat_trainer : public SpellScript
{
    PrepareSpellScript(spell_summon_combat_trainer);

    void SelectTarget(WorldObject*& target)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;
        Creature* partner = FindCreatureIgnorePhase(caster, caster->GetTeam() == ALLIANCE ? "garrick_camp" : "grimaxe_camp", 10.0f);
        if (!partner)
            return;

        target = partner;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_summon_combat_trainer::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY_OR_DB);
    }
};

enum EnhancedCombatTrainer
{
    ACTOR_ID_ALLIANCE_ENHANCED_TRAINING               = 74771,
    ACTOR_ID_HORDE_ENHANCED_TRAINING                  = 76285,

    CARGE_CATAGORY_ID_CHARGE_SPELL                    = 1386,

    CONVERSATION_PREFIGHT_WALK_ENHANCED               = 13710,
    CONVERSATION_USE_SPELLS_AT_RANGE                  = 13630,
    CONVERSATION_READY_COMBAT                         = 14440,
    // Warrior
    CONVERSATION_READY_COMBAT_WARRIOR                 = 14441,
    CONVERSATION_CHARGE_ZERO_RES_ENHANCED             = 14444,
    CONVERSATION_SLAM_ENHANCED                        = 14447,
    CONVERSATION_CHARGE_ONE_RES_ENHANCED              = 14448,
    CONVERSATION_CHARGE_FINAL_ENHANCED                = 14449,
    CONVERSATION_CHARGE_KICKBACK                      = 13611,
    // Paladin
    CONVERSATION_HOLY_POWER_ONE_PALADIN               = 14452,
    CONVERSATION_CRUSADER_STRIKE_ONE_PALADIN          = 14453,
    CONVERSATION_CRUSADER_STRIKE_TWO_PALADIN          = 14454,
    CONVERSATION_SHIELD_SLAM_ONE_PALADIN              = 14455,
    CONVERSATION_HOLY_POWER_TWO_PALADIN               = 14456,
    CONVERSATION_SHIELD_SLAM_TWO_PALADIN              = 14457,
    CONVERSATION_CRUSADER_STRIKE_THREE_PALADIN        = 14458,
    CONVERSATION_HOLY_POWER_THREE_PALADIN             = 14459,
    // Rogue
    CONVERSATION_SINISTER_STRIKE_ONE_ROGUE            = 14486,
    CONVERSATION_REGULAR_ATTACKS_ROGUE                = 14487,
    CONVERSATION_THREE_COMBO_POINTS_ROGUE             = 14488,
    CONVERSATION_THREE_COMBO_EVISCERATE_ROGUE         = 14489,
    CONVERSATION_SINISTER_STRIKE_TWO_ROGUE            = 14490,
    CONVERSATION_FOUR_COMBO_POINTS_ROGUE              = 14491,
    CONVERSATION_FOUR_COMBO_EVISCERATE_ROGUE          = 14492,
    CONVERSATION_SINISTER_STRIKE_THREE_ROGUE          = 14493,
    CONVERSATION_FIVE_COMBO_POINTS_ROGUE              = 14494,
    CONVERSATION_FAILED_EVISCERATE_ROGUE              = 14495,
    // Priest
    CONVERSATION_SHADOW_WORD_PAIN_QUEST_CREDIT_PRIEST = 13892,
    CONVERSATION_SMITE_PRE_COMBAT_PRIEST              = 14460,
    CONVERSATION_SHADOW_WORD_PAIN_PRE_COMBAT_PRIEST   = 14461,
    CONVERSATION_SHADOW_WORD_PAIN_TOO_SOON_PRIEST     = 14462,
    CONVERSATION_SHADOW_WORD_PAIN_FADING_PRIEST       = 14463,
    // Shaman
    CONVERSATION_LIGHTNINGBOLT_FIRST_SHAMAN           = 13631,
    CONVERSATION_PRIMAL_STRIKE_FIRST_SHAMAN           = 13632,
    CONVERSATION_PRIMAL_STRIKE_QUEST_CREDIT_SHAMAN    = 13633,
    CONVERSATION_LIGHTNINGBOLT_RANGE_SHAMAN           = 14475,
    // Mage
    CONVERSATION_FROSTBOLT_MAGE                       = 13634,
    CONVERSATION_FIRE_BLAST_QUEST_CREDIT_MAGE         = 13635,
    CONVERSATION_FROSTBOLT_CLOSE_MAGE                 = 14476,
    CONVERSATION_FIRE_BLAST_MAGE_NO_CREDIT            = 14477,
    // Warlock
    CONVERSATION_CORRUPTION_QUEST_CREDIT_WARLOCK      = 13895,
    CONVERSATION_SHADOW_BOLT_PRE_COMBAT_WARLOCK       = 14465,
    CONVERSATION_CORRUPTION_CAST_PRE_COMBAT_WARLOCK   = 14466,
    CONVERSATION_CORRUPTION_CAST_TOO_SOON_WARLOCK     = 14467,
    CONVERSATION_CORRUPTION_IS_FADING_WARLOCK         = 14468,
    //Druid
    CONVERSATION_MOONFIRE_QUEST_CREDIT_DRUID          = 13893,
    CONVERSATION_WRATH_PRE_COMBAT_DRUID               = 14471,
    CONVERSATION_MOONFIRE_CAST_PRE_COMBAT_DRUID       = 14472,
    CONVERSATION_MOONFIRE_CAST_TOO_SOON_DRUID         = 14473,
    CONVERSATION_MOONFIRE_WEARING_OFF_DRUID           = 14474,
    // All classes
    EVENT_COMBAT_TRAINING_WALK_AND_TALK               = 1,
    EVENT_COMBAT_TRAINING_FACE_PLAYER                 = 2,
    EVENT_COMBAT_RUN_BACK                             = 3,
    EVENT_COMBAT_TRAINING_END                         = 4,
    EVENT_COMBAT_CHECK_PLAYER                         = 5,
    // Rogue Class
    EVENT_COMBAT_TRAINING_SINISTER_CHECK_ROGUE        = 6,
    // Priest, Warloc, Druid Class
    EVENT_COMBAT_TRAINING_SPELL_FADING                = 7,
    // Shaman Class
    EVENT_COMBAT_TRAINING_RESET_SHAMAN                = 8,
    EVENT_COMBAT_TRAINING_AGGRO_CHECK_SHAMAN          = 9,
    // Mage Class
    EVENT_COMBAT_TRAINING_RESET_MAGE                  = 10,
    EVENT_COMBAT_TRAINING_AGGRO_CHECK_MAGE            = 11,

    NPC_ALLIANCE_SPARING_PARTNER_ENHANCED             = 164577,
    NPC_ALLIANCE_SPARING_PARTNER_ENHANCED2            = 164775,
    NPC_HORDE_SPARING_PARTNER_ENHANCED                = 166916,
    NPC_INVISBUNNY_CAMP                               = 167761,

    PATH_COMBAT_TRAINER_HOME                          = 10512100,

    POSITION_WALK_POINT_ENHANCED_TRAINING             = 1,
    POSITION_RUN_POINT_ENHANCED_TRAINING              = 2,
    POSITION_TRAINING_POINT_ENHANCED_TRAINING         = 3,

    QUEST_ENHANCED_COMBAT_TACTICS_ALLIANCE            = 59254,
    QUEST_ENHANCED_COMBAT_TACTICS_ALLIANCE_MONK       = 59339,
    QUEST_ENHANCED_COMBAT_TACTICS_HORDE               = 59933,
    QUEST_ENHANCED_COMBAT_TACTICS_HORDE_MONK          = 59934,

    SPELL_DRINK_HEALING_POTION                        = 320229,
    SPELL_KNOCKBACK                                   = 320735,
    SPELL_CHARGE_KNOCKBACK_DRUID                      = 320767,
    SPELL_CHARGE                                      = 100,
    SPELL_SLAM                                        = 1464,
    SPELL_CHARGE_KNOCKBACK_WARRIOR                    = 320583,
    SPELL_SHIELD_OF_THE_RIGHTEOUS                     = 53600,
    SPELL_CRUSADER_STRIKE                             = 35395,
    SPELL_SINISTER_STRIKE                             = 1752,
    SPELL_EVISCERATE                                  = 196819,
    SPELL_SMITE                                       = 585,
    SPELL_SHADOW_WORD_PAIN                            = 589,
    SPELL_CHARGE_KNOCKBACK                            = 320605,
    SPELL_PRIMAL_STRIKE                               = 73899,
    SPELL_LIGHTNING_BOLT                              = 188196,
    SPELL_FIRE_BLAST                                  = 319836,
    SPELL_FROSTBOLT                                   = 116,
    SPELL_CORRUPTION                                  = 172,
    SPELL_SHADOWBOLT                                  = 686,
    SPELL_MOONFIRE                                    = 164812,
    SPELL_WRATH                                       = 5176,
    SPELL_TIGER_PALM                                  = 100780,
    SPELL_BLACKOUT_KICK                               = 100784,
    SPELL_RANGED_ROOT_DNT                             = 320608,
    SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR              = 320741,
    SPELL_AGGRO_RADIUS_CHECK_DNT_PRIEST               = 320649,
    SPELL_AGGRO_RADIUS_CHECK_DNT_SHAMAN               = 320705,
    SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE         = 320741,
    SPELL_AGGRO_RADIUS_CHECK_DNT_WARLOCK              = 320606,
    SPELL_AGGRO_RADIUS_CHECK_DNT_DRUID                = 320766
};

struct npc_sparring_partner_combat_training : public ScriptedAI
{
    npc_sparring_partner_combat_training(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_WALK_AND_TALK, 2s);
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Unit* summoner = summonerWO->ToUnit();

        if (!summoner || !summoner->IsPlayer())
            return;

        Player* player = summoner->ToPlayer();

        _playerGUID = player->GetGUID();

        _playerClass = player->GetClass();

        if (player->GetTeam() == ALLIANCE)
        {
            _hordeGUID = ObjectGuid::Empty;
            _summonSpellAura = SPELL_SUMMON_CAPTAIN_GARRICK_COMBAT;

            if (_playerClass == CLASS_MONK)
                _questID = QUEST_ENHANCED_COMBAT_TACTICS_ALLIANCE_MONK;
            else
                _questID = QUEST_ENHANCED_COMBAT_TACTICS_ALLIANCE;
        }
        else
        {
            _hordeGUID = me->GetGUID();
            _summonSpellAura = SPELL_SUMMON_WARLORD_GRIMAXE_COMBAT;

            if (_playerClass == CLASS_MONK)
                _questID = QUEST_ENHANCED_COMBAT_TACTICS_HORDE_MONK;
            else
                _questID = QUEST_ENHANCED_COMBAT_TACTICS_HORDE;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if ((_playerClass == CLASS_ROGUE) && !_questCredits)
            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SINISTER_CHECK_ROGUE, 8s, 20s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!me->IsAlive())
            return;

        me->CombatStop(true);
        EngagementOver();
        me->ResetPlayerDamageReq();
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case POSITION_WALK_POINT_ENHANCED_TRAINING:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(POSITION_RUN_POINT_ENHANCED_TRAINING, -231.5225f, -2480.5276f, 19.019197f);
            break;
            case POSITION_RUN_POINT_ENHANCED_TRAINING:
            {
                std::list<Creature*> sparpoints;
                GetCreatureListWithEntryInGrid(sparpoints, me, NPC_INVISBUNNY_CAMP, 100.0f);
                Trinity::Containers::RandomResize(sparpoints, 1);

                for (Creature* creature : sparpoints)
                    me->GetMotionMaster()->MovePoint(POSITION_TRAINING_POINT_ENHANCED_TRAINING, creature->GetPosition());
            }
            break;
            case POSITION_TRAINING_POINT_ENHANCED_TRAINING:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->SetFacingToObject(player);

                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                _events.ScheduleEvent(EVENT_COMBAT_CHECK_PLAYER, 1s);

                switch (_playerClass)
                {
                    case CLASS_WARRIOR:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT_WARRIOR);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_PALADIN:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        _rightiousCheck = true;
                        _senondaryCheck = true;
                        break;
                    case CLASS_ROGUE:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        _comboPointCheck = true;
                        _senondaryCheck = true;
                        break;
                    case CLASS_PRIEST:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_PRIEST);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_SHAMAN:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_SHAMAN);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_MAGE:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_WARLOCK:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_WARLOCK);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_DRUID:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_DRUID);
                        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
                        _senondaryCheck = true;
                        break;
                    case CLASS_MONK:
                        ConversationWithPlayer(CONVERSATION_READY_COMBAT);
                        break;
                    default:
                        break;
                }
                break;
            }
            default:
                break;
            }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = me->GetHealth() - 1;

        if (me->HealthBelowPctDamaged(20, damage))
            me->CastSpell(me, SPELL_DRINK_HEALING_POTION);
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
            conversation->AddActor(ACTOR_ID_ALLIANCE_ENHANCED_TRAINING, 0, _allianceGUID);
            conversation->AddActor(ACTOR_ID_HORDE_ENHANCED_TRAINING, 1, _hordeGUID);
            conversation->Start();
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        // Used to check if reached home
        if (pathId == PATH_COMBAT_TRAINER_HOME)
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            {
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
                player->RemoveAura(_summonSpellAura);
            }
        }
    }

    void ResetWarrior(Player* player)
    {
        _counter = 0;
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        player->GetSpellHistory()->ResetCharges(CARGE_CATAGORY_ID_CHARGE_SPELL);
        me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);
        me->CastSpell(me, SPELL_RANGED_ROOT_DNT);
        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_FACE_PLAYER, 1s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Player* player = caster->ToPlayer();
        if (!player)
            return;

        switch (_playerClass)
        {
            case CLASS_WARRIOR:
            {
                if ((spellInfo->Id == SPELL_CHARGE))
                {
                    me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                    me->RemoveAura(SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);

                    ++_questCredits;
                    player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                    switch (_questCredits)
                    {
                        case 1:
                            ConversationWithPlayer(CONVERSATION_CHARGE_ZERO_RES_ENHANCED);
                            break;
                        case 2:
                            ConversationWithPlayer(CONVERSATION_CHARGE_ONE_RES_ENHANCED);
                            break;
                        case 3:
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                            break;
                        default:
                            break;
                    }
                }

                if ((spellInfo->Id == SPELL_SLAM))
                {
                    ++_counter;

                    if ((_counter == 3 && _questCredits))
                        ResetWarrior(player);

                    if (!_senondaryCheck)
                        return;

                    _senondaryCheck = false;
                    ConversationWithPlayer(CONVERSATION_SLAM_ENHANCED);
                }
                break;
            }
            case CLASS_PALADIN:
            {
                if (spellInfo->Id == SPELL_SHIELD_OF_THE_RIGHTEOUS)
                {
                    ++_questCredits;
                    player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                    switch (_questCredits)
                    {
                        case 1:
                            ConversationWithPlayer(CONVERSATION_SHIELD_SLAM_ONE_PALADIN);
                            _senondaryCheck = true;
                            break;
                        case 2:
                            ConversationWithPlayer(CONVERSATION_SHIELD_SLAM_TWO_PALADIN);
                            _senondaryCheck = true;
                            break;
                        case 3:
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                            _events.CancelEvent(EVENT_COMBAT_CHECK_PLAYER);
                            break;
                        default:
                            break;
                    }
                }

                if (spellInfo->Id == SPELL_CRUSADER_STRIKE)
                {
                    if (_senondaryCheck)
                    {
                        switch (_questCredits)
                        {
                            case 0:
                                ConversationWithPlayer(CONVERSATION_CRUSADER_STRIKE_ONE_PALADIN);
                                break;
                            case 1:
                                ConversationWithPlayer(CONVERSATION_CRUSADER_STRIKE_TWO_PALADIN);
                                break;
                            case 2:
                                ConversationWithPlayer(CONVERSATION_CRUSADER_STRIKE_THREE_PALADIN);
                                break;
                            default:
                                break;
                        }
                        _senondaryCheck = false;
                        _rightiousCheck = true;
                    }
                }
                break;
            }
            case CLASS_ROGUE:
            {
                if (spellInfo->Id == SPELL_EVISCERATE)
                {
                    _comboPointCheck = true;
                    if (_counter >= (_questCredits + 3))
                    {
                        ++_questCredits;
                        player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                        switch (_questCredits)
                        {
                            case 1:
                                ConversationWithPlayer(CONVERSATION_THREE_COMBO_EVISCERATE_ROGUE);
                                _senondaryCheck = true;
                                break;
                            case 2:
                                ConversationWithPlayer(CONVERSATION_FOUR_COMBO_EVISCERATE_ROGUE);
                                _senondaryCheck = true;
                                break;
                            case 3:
                                _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                                _events.CancelEvent(EVENT_COMBAT_CHECK_PLAYER);
                                break;
                            default:
                                break;
                        }
                    }
                    else
                    {
                        ConversationWithPlayer(CONVERSATION_FAILED_EVISCERATE_ROGUE);
                    }
                }

                if (spellInfo->Id == SPELL_SINISTER_STRIKE)
                {
                    if (!_questCredits)
                        _events.RescheduleEvent(EVENT_COMBAT_TRAINING_SINISTER_CHECK_ROGUE, 8s, 20s);

                    if (_senondaryCheck)
                    {
                        switch (_questCredits)
                        {
                            case 0:
                                ConversationWithPlayer(CONVERSATION_SINISTER_STRIKE_ONE_ROGUE);
                                break;
                            case 1:
                                ConversationWithPlayer(CONVERSATION_SINISTER_STRIKE_TWO_ROGUE);
                                break;
                            case 2:
                                ConversationWithPlayer(CONVERSATION_SINISTER_STRIKE_THREE_ROGUE);
                                break;
                            default:
                                break;
                        }
                        _senondaryCheck = false;
                    }
                }
                break;
            }
            case CLASS_PRIEST:
            {
                if (spellInfo->Id == SPELL_SHADOW_WORD_PAIN)
                {
                    _events.CancelEvent(EVENT_COMBAT_TRAINING_SPELL_FADING);

                    if (!_mainSpellCheck)
                    {
                        if (_senondaryCheck)
                        {
                            ConversationWithPlayer(CONVERSATION_SHADOW_WORD_PAIN_PRE_COMBAT_PRIEST);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                            me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                            _senondaryCheck = false;
                        }
                        else
                            ConversationWithPlayer(CONVERSATION_SHADOW_WORD_PAIN_TOO_SOON_PRIEST);

                        _convoID = CONVERSATION_SHADOW_WORD_PAIN_FADING_PRIEST;
                        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 13s);
                    }
                    else
                    {
                        ++_questCredits;
                        _mainSpellCheck = false;
                        player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                        if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                        {
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                        }
                        else
                        {
                            ConversationWithPlayer(CONVERSATION_SHADOW_WORD_PAIN_QUEST_CREDIT_PRIEST);
                            _convoID = CONVERSATION_SHADOW_WORD_PAIN_FADING_PRIEST;
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 13s);
                        }
                    }
                }

                if (spellInfo->Id == SPELL_SMITE)
                {
                    if (_senondaryCheck)
                        ConversationWithPlayer(CONVERSATION_SMITE_PRE_COMBAT_PRIEST);
                }
                break;
            }
            case CLASS_SHAMAN:
            {
                if (spellInfo->Id == SPELL_PRIMAL_STRIKE)
                {
                    if (!player->IsWithinDist(me, 2.0f))
                        return;

                    ++_counter;

                    if (_counter < 3)
                    {
                        if (_counter == 1)
                            ConversationWithPlayer(CONVERSATION_PRIMAL_STRIKE_FIRST_SHAMAN);
                        return;
                    }

                    _counter = 0;
                    ++_questCredits;
                    player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                    if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                    {
                        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                    }
                    else
                    {
                        ConversationWithPlayer(CONVERSATION_PRIMAL_STRIKE_QUEST_CREDIT_SHAMAN);
                        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_RESET_SHAMAN, 3s);
                    }
                }

                if (spellInfo->Id == SPELL_LIGHTNING_BOLT)
                {
                    me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                    me->RemoveAura(SPELL_AGGRO_RADIUS_CHECK_DNT_SHAMAN);
                    if (_senondaryCheck)
                    {
                        ConversationWithPlayer(CONVERSATION_LIGHTNINGBOLT_FIRST_SHAMAN);
                        _senondaryCheck = false;
                    }
                    else
                    {
                        if (player->IsWithinDist(me, 2.0f))
                            ConversationWithPlayer(CONVERSATION_LIGHTNINGBOLT_RANGE_SHAMAN);
                    }
                }
                break;
            }
            case CLASS_MAGE:
            {
                if (spellInfo->Id == SPELL_FIRE_BLAST)
                {
                    ++_questCredits;

                    if (player->IsWithinDist(me, 2.0f))
                    {
                        player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                        if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                        {
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                        }
                        else
                        {
                            ConversationWithPlayer(CONVERSATION_FIRE_BLAST_QUEST_CREDIT_MAGE);
                            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_RESET_MAGE, 4s);
                        }
                    }
                    else
                    {
                        ConversationWithPlayer(CONVERSATION_FIRE_BLAST_MAGE_NO_CREDIT);
                    }
                }

                if (spellInfo->Id == SPELL_FROSTBOLT)
                {
                    me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                    me->RemoveAura(SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);
                    if (_senondaryCheck)
                    {
                        ConversationWithPlayer(CONVERSATION_FROSTBOLT_MAGE);
                        _senondaryCheck = false;
                    }
                    else
                    {
                        if (player->IsWithinDist(me, 2.0f))
                            ConversationWithPlayer(CONVERSATION_FROSTBOLT_CLOSE_MAGE);
                    }
                }
                break;
            }
            case CLASS_WARLOCK:
            {
                if (spellInfo->Id == SPELL_CORRUPTION)
                {
                    _events.CancelEvent(EVENT_COMBAT_TRAINING_SPELL_FADING);

                    if (!_mainSpellCheck)
                    {
                        if (_senondaryCheck)
                        {
                            ConversationWithPlayer(CONVERSATION_CORRUPTION_CAST_PRE_COMBAT_WARLOCK);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                            me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                            _senondaryCheck = false;
                        }
                        else
                            ConversationWithPlayer(CONVERSATION_CORRUPTION_CAST_TOO_SOON_WARLOCK);

                        _convoID = CONVERSATION_CORRUPTION_IS_FADING_WARLOCK;
                        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 11s);
                    }
                    else
                    {
                        ++_questCredits;
                        _mainSpellCheck = false;
                        player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                        if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                        {
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                        }
                        else
                        {
                            ConversationWithPlayer(CONVERSATION_CORRUPTION_QUEST_CREDIT_WARLOCK);
                            _convoID = CONVERSATION_CORRUPTION_IS_FADING_WARLOCK;
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 11s);
                        }
                    }
                }

                if (spellInfo->Id == SPELL_SHADOWBOLT)
                {
                    if (_senondaryCheck)
                        ConversationWithPlayer(CONVERSATION_SHADOW_BOLT_PRE_COMBAT_WARLOCK);
                }
                break;
            }
            case CLASS_DRUID:
            {
                if (spellInfo->Id == SPELL_MOONFIRE)
                {
                    _events.CancelEvent(EVENT_COMBAT_TRAINING_SPELL_FADING);

                    if (!_mainSpellCheck)
                    {
                        if (_senondaryCheck)
                        {
                            ConversationWithPlayer(CONVERSATION_MOONFIRE_CAST_PRE_COMBAT_DRUID);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                            me->RemoveAura(SPELL_RANGED_ROOT_DNT);
                            _senondaryCheck = false;
                        }
                        else
                            ConversationWithPlayer(CONVERSATION_MOONFIRE_CAST_TOO_SOON_DRUID);

                        _convoID = CONVERSATION_MOONFIRE_WEARING_OFF_DRUID;
                        _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 14s);
                    }
                    else
                    {
                        ++_questCredits;
                        _mainSpellCheck = false;
                        player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);

                        if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                        {
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                        }
                        else
                        {
                            ConversationWithPlayer(CONVERSATION_MOONFIRE_QUEST_CREDIT_DRUID);
                            _convoID = CONVERSATION_MOONFIRE_WEARING_OFF_DRUID;
                            _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SPELL_FADING, 14s);
                        }
                    }
                }

                if (spellInfo->Id == SPELL_WRATH)
                {
                    if (_senondaryCheck)
                        ConversationWithPlayer(CONVERSATION_WRATH_PRE_COMBAT_DRUID);
                }
                break;
            }
            case CLASS_MONK:
            {
                if (spellInfo->Id == SPELL_TIGER_PALM)
                    player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED);
                if (spellInfo->Id == SPELL_BLACKOUT_KICK)
                    player->KilledMonsterCredit(NPC_ALLIANCE_SPARING_PARTNER_ENHANCED2);

                if (player->GetQuestStatus(_questID) == QUEST_STATUS_COMPLETE)
                {
                    _events.ScheduleEvent(EVENT_COMBAT_TRAINING_END, 1s);
                }
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_COMBAT_TRAINING_WALK_AND_TALK:
                // Used by all classes
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POSITION_WALK_POINT_ENHANCED_TRAINING, -250.60243f, -2485.2517f, 17.787413f);
                ConversationWithPlayer(CONVERSATION_PREFIGHT_WALK_ENHANCED);
                break;
            case EVENT_COMBAT_TRAINING_FACE_PLAYER:
            {
                // Used by all classes
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->SetFacingToObject(player);

                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                break;
            }
            case EVENT_COMBAT_TRAINING_END:
                // Used by all classes
                me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                me->RemoveAllAuras();
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->SetFacingToObject(player);
                    ConversationWithPlayer(CONVERSATION_CHARGE_FINAL_ENHANCED);
                    _events.ScheduleEvent(EVENT_COMBAT_RUN_BACK, 4s);
                }
                break;
            case EVENT_COMBAT_RUN_BACK:
                // Used by all classes
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePath(PATH_COMBAT_TRAINER_HOME, false);
                break;
            case EVENT_COMBAT_CHECK_PLAYER:
            {
                // Used by paladin
                if (_rightiousCheck)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (player->GetPower(POWER_HOLY_POWER) >= 3)
                        {
                            switch (_questCredits)
                            {
                            case 0:
                                ConversationWithPlayer(CONVERSATION_HOLY_POWER_ONE_PALADIN);
                                break;
                            case 1:
                                ConversationWithPlayer(CONVERSATION_HOLY_POWER_TWO_PALADIN);
                                break;
                            case 2:
                                ConversationWithPlayer(CONVERSATION_HOLY_POWER_THREE_PALADIN);
                                break;
                            default:
                                break;
                            }
                            _rightiousCheck = false;
                        }
                    }
                }

                // Used by rogue
                if (_comboPointCheck)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        _counter = player->GetPower(POWER_COMBO_POINTS);

                    if (_counter >= (_questCredits + 3))
                    {
                        switch (_questCredits)
                        {
                            case 0:
                                ConversationWithPlayer(CONVERSATION_THREE_COMBO_POINTS_ROGUE);
                                break;
                            case 1:
                                ConversationWithPlayer(CONVERSATION_FOUR_COMBO_POINTS_ROGUE);
                                break;
                            case 2:
                                ConversationWithPlayer(CONVERSATION_FIVE_COMBO_POINTS_ROGUE);
                                break;
                            default:
                                break;
                        }
                        _comboPointCheck = false;
                    }
                }
                _events.ScheduleEvent(EVENT_COMBAT_CHECK_PLAYER, 500ms);
                break;
            }
            case EVENT_COMBAT_TRAINING_SINISTER_CHECK_ROGUE:
                ConversationWithPlayer(CONVERSATION_REGULAR_ATTACKS_ROGUE);
                _events.ScheduleEvent(EVENT_COMBAT_TRAINING_SINISTER_CHECK_ROGUE, 8s, 20s);
                break;
            case EVENT_COMBAT_TRAINING_SPELL_FADING:
                ConversationWithPlayer(_convoID);
                _mainSpellCheck = true;
                break;
            case EVENT_COMBAT_TRAINING_RESET_SHAMAN:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->CastSpell(player, SPELL_KNOCKBACK);
                    _events.ScheduleEvent(EVENT_COMBAT_TRAINING_AGGRO_CHECK_SHAMAN, 2s);
                }
                break;
            case EVENT_COMBAT_TRAINING_AGGRO_CHECK_SHAMAN:
                me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_SHAMAN);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                _senondaryCheck = true;
                break;
            case EVENT_COMBAT_TRAINING_RESET_MAGE:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->CastSpell(player, SPELL_KNOCKBACK);
                    _events.ScheduleEvent(EVENT_COMBAT_TRAINING_AGGRO_CHECK_MAGE, 2s);
                }
                break;
            case EVENT_COMBAT_TRAINING_AGGRO_CHECK_MAGE:
                me->CastSpell(me, SPELL_AGGRO_RADIUS_CHECK_DNT_WARRIOR_MAGE);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                _senondaryCheck = true;
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
    int8 _counter = 0;
    int8 _questCredits = 0;
    uint32 _questID;
    uint32 _convoID;
    uint32 _summonSpellAura;
    uint32 _playerClass;
    EventMap _events;
    ObjectGuid _allianceGUID;
    ObjectGuid _hordeGUID;
    ObjectGuid _playerGUID;
    bool _mainSpellCheck = false;
    bool _senondaryCheck = false;
    // Used by Paladin class
    bool _rightiousCheck = false;
    // used by rogue class
    bool _comboPointCheck = false;
};

struct areatrigger_aggro_radius_check : AreaTriggerAI
{
    areatrigger_aggro_radius_check(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Creature* caster = at->GetCaster()->ToCreature();

        if (!caster)
        {
            at->RemoveFromWorld();
            return;
        }

        caster->SetFacingToObject(player);

        switch (player->GetClass())
        {
            case CLASS_WARRIOR:
                caster->CastSpell(player, SPELL_CHARGE_KNOCKBACK_WARRIOR);
                break;
            case CLASS_PRIEST:
            case CLASS_SHAMAN:
            case CLASS_MAGE:
            case CLASS_WARLOCK:
                caster->CastSpell(player, SPELL_CHARGE_KNOCKBACK);
                break;
            case CLASS_DRUID:
                caster->CastSpell(player, SPELL_CHARGE_KNOCKBACK_DRUID);
                break;
            default:
                break;
        }
    }
};

// Spell 320605
class spell_knockback_charge_enhanced_training : public SpellScript
{
    void HandleLaunch(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Player* player = GetHitUnit()->ToPlayer();
        if (!player)
            return;

        Conversation* conversation = Conversation::CreateConversation(GetSpellInfo()->GetEffect(effIndex).MiscValue, player, *player, player->GetGUID(), nullptr, false);
        conversation->AddActor(ACTOR_ID_ALLIANCE_ENHANCED_TRAINING, 0, player->GetTeam() == ALLIANCE ? caster->GetGUID() : ObjectGuid::Empty);
        conversation->AddActor(ACTOR_ID_HORDE_ENHANCED_TRAINING, 1, player->GetTeam() == ALLIANCE ? ObjectGuid::Empty : caster->GetGUID());
        conversation->Start();
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_knockback_charge_enhanced_training::HandleLaunch, EFFECT_1, SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION);
        OnEffectHitTarget += SpellEffectFn(spell_knockback_charge_enhanced_training::HandleEffect, EFFECT_1, SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION);
    }
};

enum Northbound
{
    CONVERSATION_QUEST_NORTHBOUND_ACCEPT_ALLIANCE    = 12066,
    CONVERSATION_QUEST_NORTHBOUND_ACCEPT_HORDE       = 14499,

    ACTOR_ID_0_NORTHBOUND_ACCEPT_ALLIANCE            = 71310,
    ACTOR_ID_1_NORTHBOUND_ACCEPT_ALLIANCE            = 71297,
    ACTOR_ID_0_NORTHBOUND_ACCEPT_HORDE               = 79890,
    ACTOR_ID_1_NORTHBOUND_ACCEPT_HORDE               = 79888,
    ACTOR_ID_0_NORTHBOUND_AREATRIGGER_ALLIANCE       = 71317,
    ACTOR_ID_1_NORTHBOUND_AREATRIGGER_HORDE          = 76319,

    QUEST_NORTHBOND_ALLIANCE                         = 55173,
    QUEST_NORTHBOND_HORDE                            = 59935,

    SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN_NORTHBOUND = 305660,
    SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN_NORTHBOUND = 344382,
    SPELL_LINGER_NORTHBOUND_ALLIANCE                 = 305665,
    SPELL_LINGER_NORTHBOUND_HORDE                    = 344385,
};

Position const GarrickQuillboarBriarpatchPosition = { -142.62154f, -2641.0364f, 48.775497f };
Position const GrimaxeQuillboarBriarpatchPosition = { -142.56076f, -2640.9915f, 48.755478f };

// 165360 - Alliance Survivor
// This script is used by Captian Garrick Follower for Northbound quest
struct npc_leader_northbound : public ScriptedAI
{
    npc_leader_northbound(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID);

        player->UpdateVisibilityForPlayer();

        if (!player)
            return;

        Creature* survivor = FindCreatureIgnorePhase(player, player->GetTeam() == ALLIANCE ? "alaria_standing_abandoned_camp" : "wonza_standing_abandoned_camp", 5.0f);

        if (!survivor)
            return;

        if (player->GetTeam() == ALLIANCE)
        {
            _convo = CONVERSATION_QUEST_NORTHBOUND_ACCEPT_ALLIANCE;
            _actorIDone = ACTOR_ID_0_NORTHBOUND_ACCEPT_ALLIANCE;
            _actorIDtwo = ACTOR_ID_1_NORTHBOUND_ACCEPT_ALLIANCE;
            _runto = GarrickQuillboarBriarpatchPosition;
            _lingerSpell = SPELL_LINGER_NORTHBOUND_ALLIANCE;
            _guardianSpell = SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN_NORTHBOUND;
        }
        else
        {
            _convo = CONVERSATION_QUEST_NORTHBOUND_ACCEPT_HORDE;
            _actorIDone = ACTOR_ID_0_NORTHBOUND_ACCEPT_HORDE;
            _actorIDtwo = ACTOR_ID_1_NORTHBOUND_ACCEPT_HORDE;
            _runto = GrimaxeQuillboarBriarpatchPosition;
            _lingerSpell = SPELL_LINGER_NORTHBOUND_HORDE;
            _guardianSpell = SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN_NORTHBOUND;
        }

        // Needs work for horde
        Conversation* conversation = Conversation::CreateConversation(_convo, player, *player, player->GetGUID(), nullptr, false);
        conversation->AddActor(0, 0, player->GetGUID());
        conversation->AddActor(_actorIDone, 1, me->GetGUID());
        conversation->AddActor(_actorIDtwo, 2, survivor->GetGUID());
        conversation->Start();
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        Player* player = summoner->ToPlayer();
        if (!player)
            return;

        _playerGUID = player->GetGUID();

        _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 3s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // Needs work for horde
        if (spellInfo->Id == _lingerSpell)
        {
            me->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);
            me->GetMotionMaster()->MovePoint(0, _runto, false);
        }
        return;
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE || uiId != 0)
            return;

        me->SetFacingTo(6.0737457275390625);

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->RemoveAura(_guardianSpell);
            player->UpdateVisibilityForPlayer();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FOLLOW_PLAYER:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        me->GetMotionMaster()->MoveFollow(player, 0.0f, float(M_PI / 4.0f));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    ObjectGuid _playerGUID;
    uint32 _convo;
    uint32 _actorIDone;
    uint32 _actorIDtwo;
    Position _runto;
    uint32 _lingerSpell;
    uint32 _guardianSpell;
};

// 55173 - Northbound
// 59935 - Northbound
class quest_northbound : public QuestScript
{
public:
    quest_northbound(char const* script) : QuestScript(script) { }

    void HandleQuestStatusChange(Player* player, QuestStatus newStatus, uint32 summonSpellId)
    {
        switch (newStatus)
        {
            case QUEST_STATUS_INCOMPLETE:
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
                player->CastSpell(player, summonSpellId);
                break;
            case QUEST_STATUS_NONE:
                player->RemoveAura(summonSpellId);
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
                player->UpdateVisibilityForPlayer();
                break;
            default:
                break;
        }
    }
};

// 55173 - Northbound
class quest_northbound_alliance : public quest_northbound
{
public:
    quest_northbound_alliance() : quest_northbound("quest_northbound_alliance") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus, SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN_NORTHBOUND);
    }
};

// 59935 - Northbound
class quest_northbound_horde : public quest_northbound
{
public:
    quest_northbound_horde() : quest_northbound("quest_northbound_horde") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        HandleQuestStatusChange(player, newStatus, SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN_NORTHBOUND);
    }
};

// Spell 305661 "Summon Admiral Garrick Guardian" Summons Alliance Entry: 165360
// Spell 344383 "Summon Admiral Garrick Guardian" Summons Horde Entry: 175034
class spell_summon_leader_northbound : public SpellScript
{
    void SelectTarget(WorldObject*& target)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        Creature* survivor = FindCreatureIgnorePhase(caster, caster->GetTeam() == ALLIANCE ? "garrick_camp" : "grimaxe_camp", 5.0f);
        if (!survivor)
            return;

        target = survivor;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_summon_leader_northbound::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY_OR_DB);
    }
};

struct areatrigger_northbound : AreaTriggerAI
{
    areatrigger_northbound(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        if (player->GetTeam() == ALLIANCE)
        {
            if (player->GetQuestStatus(QUEST_NORTHBOND_ALLIANCE) != QUEST_STATUS_COMPLETE)
                return;

            if (!player->HasAura(SPELL_SUMMON_ADMIRAL_GARRICK_GUARDIAN_NORTHBOUND))
                return;

            if (player->HasAura(SPELL_LINGER_NORTHBOUND_ALLIANCE))
                return;

            player->CastSpell(player, SPELL_LINGER_NORTHBOUND_ALLIANCE);
        }
        else
        {
            if (player->GetQuestStatus(QUEST_NORTHBOND_HORDE) != QUEST_STATUS_COMPLETE)
                return;

            if (!player->HasAura(SPELL_SUMMON_WARLORD_GRIMAXE_GUARDIAN_NORTHBOUND))
                return;

            if (player->HasAura(SPELL_LINGER_NORTHBOUND_HORDE))
                return;

            player->CastSpell(player, SPELL_LINGER_NORTHBOUND_HORDE);
        }
    }
};

// Spells 305665 & 344385 Handle conversation
class spell_scene_linger_northbound: public SpellScript
{
    void HandleLaunch(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        Player* player = GetHitUnit()->ToPlayer();
        if (!player)
            return;

        Creature* scout = FindCreatureIgnorePhase(player, player->GetTeam() == ALLIANCE ? "huxworth_briarpatch" : "dawntracker_briarpatch", 100.0f);

        if (!scout)
            return;

        scout->SetVisible(true);
        Conversation* conversation = Conversation::CreateConversation(GetSpellInfo()->GetEffect(effIndex).MiscValue, player, *player, player->GetGUID(), nullptr, false);
        conversation->AddActor(ACTOR_ID_0_NORTHBOUND_AREATRIGGER_ALLIANCE, 0, player->GetTeam() == ALLIANCE ? scout->GetGUID() : ObjectGuid::Empty);
        conversation->AddActor(ACTOR_ID_1_NORTHBOUND_AREATRIGGER_HORDE, 1, player->GetTeam() == ALLIANCE ? ObjectGuid::Empty : scout->GetGUID());
        conversation->Start();
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_scene_linger_northbound::HandleLaunch, EFFECT_2, SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION);
        OnEffectHitTarget += SpellEffectFn(spell_scene_linger_northbound::HandleEffect, EFFECT_2, SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION);
    }
};

void AddSC_zone_exiles_reach()
{
    // Ship
    RegisterSpellScript(spell_attention_exiles_reach_tutorial);
    new q59926_warming_up();
    new q56775_warming_up();
    new quest_stand_your_ground();
    RegisterCreatureAI(npc_sparring_partner_exiles_reach);
    RegisterSpellScript(spell_summon_sparring_partner);
    new FactoryCreatureScript<CreatureAI, &CaptainGarrickShipAISelector>("npc_captain_garrick_ship");
    RegisterPrivatePublicCreatureAIPair("npc_warlord_grimaxe_lower_ship", npc_ship_captain_warming_up_private, NullCreatureAI);
    RegisterPrivatePublicCreatureAIPair("npc_warlord_grimaxe_upper_ship", npc_ship_captain_brace_for_impact_private, NullCreatureAI);
    RegisterPrivatePublicCreatureAIPair("npc_cole_ship", npc_first_mate_brace_for_impact_private, npc_first_mate_stand_your_ground);
    RegisterPrivatePublicCreatureAIPair("npc_throg_ship", npc_first_mate_brace_for_impact_private, npc_first_mate_stand_your_ground);
    RegisterPrivatePublicCreatureAIPair("npc_crew_ship", npc_crew_ship_private, NullCreatureAI);
    RegisterPrivatePublicCreatureAIPair("npc_pet_ship", npc_pet_ship_private, NullCreatureAI);
    new quest_brace_for_impact();
    new player_exiles_reach_ship_crash();
    new scene_alliance_and_horde_ship();
    // Beach
    RegisterSpellScript(spell_knocked_down_exiles_reach_beach);
    new scene_alliance_and_horde_crash();
    RegisterSpellScriptWithArgs(spell_crash_landed_generic<NPC_CAPTAIN_GARRICK_BEACH>, "spell_crash_landed_alliance");
    RegisterSpellScriptWithArgs(spell_crash_landed_generic<NPC_WARLORD_BREKA_GRIMAXE_BEACH>, "spell_crash_landed_horde");
    new FactoryCreatureScript<CreatureAI, &CaptainGarrickBeachAISelector>("npc_captain_garrick_beach");
    new FactoryCreatureScript<CreatureAI, &WarlordGrimaxeBeachAISelector>("npc_warlord_grimaxe_beach");
    new FactoryCreatureScript<CreatureAI, &HealedByLeaderAllianceAISelector>("npc_healed_by_leader_alliance_beach");
    new FactoryCreatureScript<CreatureAI, &HealedByLeaderHordeAISelector>("npc_healed_by_leader_horde_beach");
    new GenericCreatureScript<npc_alliance_survivors_beach_laying<CONVERSATION_STOUTHANDS_BEACH>>("npc_bjorn_stouthands_beach_laying");
    new GenericCreatureScript<npc_alliance_survivors_beach_laying<CONVERSATION_HUXWORTH_BEACH>>("npc_austin_huxworth_beach_laying");
    new GenericCreatureScript<npc_alliance_survivors_beach_laying<CONVERSATION_KEE_LA_BEACH>>("npc_kee_la_beach_laying");
    // Note: alliance survivor do not need a script for Emergency First Aid quest
    RegisterCreatureAI(npc_bo_beach_laying);
    RegisterCreatureAI(npc_mithran_dawntracker_beach_laying);
    RegisterCreatureAI(npc_lana_jordan_beach_laying);
    RegisterCreatureAI(npc_murloc_spearhunter_watershaper);
    RegisterCreatureAI(npc_murloc_spearhunter_watershaper_higher_ground);
    new FactoryCreatureScript<CreatureAI, &BoBeachStandingAISelector>("npc_bo_beach_standing");
    new FactoryCreatureScript<CreatureAI, &MithdranBeachStandingAISelector>("npc_mithdran_dawntracker_beach_standing");
    new FactoryCreatureScript<CreatureAI, &LanaJordanBeachStandingAISelector>("npc_lana_jordan_beach_standing");
    new FactoryCreatureScript<CreatureAI, &KeeLaBeachStandingAISelector>("npc_kee_la_beach_standing");
    new FactoryCreatureScript<CreatureAI, &BjornBeachStandingAISelector>("npc_bjorn_stouthands_beach_standing");
    new FactoryCreatureScript<CreatureAI, &AustinBeachStandingAISelector>("npc_austin_huxworth_beach_standing");
    RegisterCreatureAI(npc_garrick_summoned_beach);
    RegisterCreatureAI(npc_grimaxe_summoned_beach);
    new quest_finding_the_lost_expedition_alliance();
    new quest_finding_the_lost_expedition_horde();
    RegisterSpellScript(spell_summon_survivor_beach);
    // Abandoned Camp
    new GenericCreatureScript<npc_captain_abandoned_camp_exiles_reach<QUEST_COOKING_MEAT_ALLIANCE, CONVERSATION_QUEST_COOKING_MEAT_ACCEPT_ALLIANCE>>("npc_captain_garrick_abandoned_camp");
    new GenericCreatureScript<npc_captain_abandoned_camp_exiles_reach<QUEST_COOKING_MEAT_HORDE, CONVERSATION_QUEST_COOKING_MEAT_ACCEPT_HORDE>>("npc_warlord_grimaxe_abandoned_camp");
    new quest_cooking_meat_alliance();
    new quest_cooking_meat_horde();
    RegisterAreaTriggerAI(areatrigger_find_the_lost_expedition);
    RegisterAreaTriggerAI(areatrigger_find_the_lost_expedition_follower);
    // Quest Enhanced Combat Tactics
    new quest_enhanced_combat_tactics();
    RegisterSpellScript(spell_summon_combat_trainer);
    RegisterCreatureAI(npc_sparring_partner_combat_training);
    RegisterAreaTriggerAI(areatrigger_aggro_radius_check);
    RegisterSpellScript(spell_knockback_charge_enhanced_training);
    // Quest Northbound
    RegisterCreatureAI(npc_leader_northbound);
    new quest_northbound_alliance();
    new quest_northbound_horde();
    RegisterSpellScript(spell_summon_leader_northbound);
    RegisterAreaTriggerAI(areatrigger_northbound);
    RegisterSpellScript(spell_scene_linger_northbound);
}
