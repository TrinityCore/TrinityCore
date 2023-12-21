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
    ITEM_STITCHED_CLOTH_SHOES = 174791,
    ITEM_STITCHED_LEATHER_BOOTS = 174792,
    ITEM_LINKED_MAIL_BOOTS = 174793,
    ITEM_DENTED_PLATE_BOOTS = 174794,

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
                        me->GetMotionMaster()->MoveFollow(player, 0.0f, 0.0f);
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
                        me->GetMotionMaster()->MoveFollow(player, 0.0f, 0.0f);
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
}
