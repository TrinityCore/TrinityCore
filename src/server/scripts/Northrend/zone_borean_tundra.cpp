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

#include "ScriptMgr.h"
#include "Containers.h"
#include "CreatureAIImpl.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

 /*######
 ## Quest 11590: Abduction
 ######*/

// NPC 25316: Beryl Sorcerer
enum BerylSorcerer
{
    EVENT_FROSTBOLT                                = 1,
    EVENT_ARCANE_CHAINS,

    NPC_LIBRARIAN_DONATHAN                         = 25262,
    NPC_CAPTURED_BERLY_SORCERER                    = 25474,

    SPELL_FROSTBOLT                                = 9672,
    SPELL_ARCANE_CHAINS                            = 45611,
    SPELL_ARCANE_CHAINS_CHARACTER_FORCE_CAST       = 45625,
    SPELL_ARCANE_CHAINS_SUMMON_CHAINED_MAGE_HUNTER = 45626,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF             = 45631,
    SPELL_ARCANE_CHAINS_CHANNEL_II                 = 45735
};

struct npc_beryl_sorcerer : public ScriptedAI
{
    npc_beryl_sorcerer(Creature* creature) : ScriptedAI(creature), _chainsCast(false) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (me->IsValidAttackTarget(who))
            AttackStart(who);

        _events.ScheduleEvent(EVENT_FROSTBOLT, 3s, 4s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (_chainsCast)
            return;

        if (spellInfo->Id == SPELL_ARCANE_CHAINS && caster->IsPlayer())
        {
            _playerGUID = caster->GetGUID();
            _chainsCast = true;
            _events.ScheduleEvent(EVENT_ARCANE_CHAINS, 4s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FROSTBOLT:
                    DoCastVictim(SPELL_FROSTBOLT);
                    _events.ScheduleEvent(EVENT_FROSTBOLT, 3s, 4s);
                    break;
                case EVENT_ARCANE_CHAINS:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        me->CastSpell(player, SPELL_ARCANE_CHAINS_CHARACTER_FORCE_CAST);
                        player->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER);
                    }
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    bool _chainsCast;
    ObjectGuid _playerGUID;
};

// NPC 25474: Captured Beryl Sorcerer
struct npc_captured_beryl_sorcerer : public FollowerAI
{
    npc_captured_beryl_sorcerer(Creature* creature) : FollowerAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->SetImmuneToAll(true);
        if (TempSummon const* tempSummon = me->ToTempSummon())
        {
            if (Player* summoner = Object::ToPlayer(tempSummon->GetSummoner()))
            {
                summoner->CastSpell(summoner, SPELL_ARCANE_CHAINS_CHANNEL_II);
                StartFollow(summoner);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        FollowerAI::MoveInLineOfSight(who);

        if (who->GetEntry() == NPC_LIBRARIAN_DONATHAN && me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
        {
            SetFollowComplete();
            me->DespawnOrUnsummon();
        }
    }
};

// Spell 45625: - Arcane Chains: Character Force Cast
class spell_arcane_chains_character_force_cast : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_ARCANE_CHAINS_SUMMON_CHAINED_MAGE_HUNTER); // Player cast back 45626 on npc
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arcane_chains_character_force_cast::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11865: Unfit for Death
######*/

// Gameobjects 187982,187995,187996,187997,187998,187999,188000,188001,188002,188003,188004,188005,188006,188007,188008: Caribou Trap
enum CaribouTrap
{
    EVENT_FUR_SPAWN        = 1,
    EVENT_SPAWN_TRAPPER,
    EVENT_TRAPPER_MOVE,
    EVENT_TRAPPER_TEXT,
    EVENT_TRAPPER_LOOT,
    EVENT_FUR_DESPAWN,
    EVENT_TRAPPER_DIE,
    EVENT_DESPAWN_ALL,

    GO_HIGH_QUALITY_FUR    = 187983,

    NPC_NESINGWARY_TRAPPER = 25835,

    SAY_NESINGWARY_1       = 0,

    SPELL_PLACE_FAKE_FUR   = 46085,
    SPELL_TRAPPED          = 46104,
};

struct go_caribou_trap : public GameObjectAI
{
    go_caribou_trap(GameObject* go) : GameObjectAI(go), _placedFur(false) { }

    void Reset() override
    {
        me->SetGoState(GO_STATE_READY);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (_placedFur)
            return;

        Player* playerCaster = caster->ToPlayer();
        if (!playerCaster)
            return;

        if (spellInfo->Id == SPELL_PLACE_FAKE_FUR)
        {
            _playerGUID = caster->GetGUID();
            _placedFur = true;
            _events.ScheduleEvent(EVENT_FUR_SPAWN, 1s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_placedFur)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FUR_SPAWN:
                    if (GameObject* fur = me->SummonGameObject(GO_HIGH_QUALITY_FUR, me->GetPosition(), QuaternionData(0.0f, 0.0f, 0.77162457f, 0.63607824f), 20s))
                        _goFurGUID = fur->GetGUID();
                    _events.ScheduleEvent(EVENT_SPAWN_TRAPPER, 1s);
                    break;
                case EVENT_SPAWN_TRAPPER:
                    if (TempSummon* trapper = me->SummonCreature(NPC_NESINGWARY_TRAPPER, me->GetFirstCollisionPosition(21.0f, 0), TEMPSUMMON_DEAD_DESPAWN, 6s))
                    {
                        trapper->SetFacingToObject(me);
                        _trapperGUID = trapper->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_TRAPPER_MOVE, 1s);
                    break;
                case EVENT_TRAPPER_MOVE:
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                        trapper->GetMotionMaster()->MovePoint(0, trapper->GetFirstCollisionPosition(20.0f, 0));
                    _events.ScheduleEvent(EVENT_TRAPPER_TEXT, 5s);
                    break;
                case EVENT_TRAPPER_TEXT:
                {
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                    {
                        if (trapper->IsAIEnabled())
                            trapper->AI()->Talk(SAY_NESINGWARY_1);
                    }
                    _events.ScheduleEvent(EVENT_TRAPPER_LOOT, 2s);
                    break;
                }
                case EVENT_TRAPPER_LOOT:
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                        trapper->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                    _events.ScheduleEvent(EVENT_FUR_DESPAWN, 1s);
                    break;
                case EVENT_FUR_DESPAWN:
                    if (GameObject* fur = ObjectAccessor::GetGameObject(*me, _goFurGUID))
                        fur->Delete();
                    _events.ScheduleEvent(EVENT_TRAPPER_DIE, 1s);
                    break;
                case EVENT_TRAPPER_DIE:
                    me->SetGoState(GO_STATE_ACTIVE);
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->KilledMonsterCredit(trapper->GetEntry(), trapper->GetGUID());
                        trapper->CastSpell(trapper, SPELL_TRAPPED);
                    }
                    _events.ScheduleEvent(EVENT_DESPAWN_ALL, 1s);
                    break;
                case EVENT_DESPAWN_ALL:
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                        trapper->DespawnOrUnsummon();
                    me->DespawnOrUnsummon(0s, 50s);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    bool _placedFur;
    ObjectGuid _goFurGUID;
    ObjectGuid _playerGUID;
    ObjectGuid _trapperGUID;
};

/*######
## Quest 11876: Help Those That Cannot Help Themselves
######*/

// Gameobjects 188022,188024,188025,188026,188027,188028,188029,188030,188031,188032,188033,188034,188035,188036,188037,188038,188039,188040,188041,188042,188043,188044: Mammoth Trap
enum MammothTrap
{
    EVENT_FIND_MAMMOTH     = 1,
    EVENT_FACE_PLAYER,
    EVENT_QUEST_CREDIT,
    EVENT_MAMMOTH_TEXT,
    EVENT_MAMMOTH_MOVE,
    EVENT_MAMMOTH_DESPAWN,
    EVENT_TRAP_RESET,
    EVENT_MAMMOTH_RESPAWN,

    NPC_TRAPPED_MAMMOTH    = 25850,

    SAY_MAMMOTH            = 0,

    SPELL_SMASH_TRAP       = 46201
};

struct go_mammoth_trap : public GameObjectAI
{
    go_mammoth_trap(GameObject* go) : GameObjectAI(go), _trapSmashed(true) { }

    void Reset() override
    {
        me->SetGoState(GO_STATE_ACTIVE);
        _events.ScheduleEvent(EVENT_FIND_MAMMOTH, 1s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Player* playerCaster = caster->ToPlayer();
        if (!playerCaster)
            return;

        if (me->GetGoState() == GO_STATE_READY)
            return;

        if (spellInfo->Id == SPELL_SMASH_TRAP)
        {
            _playerGUID = caster->GetGUID();
            _trapSmashed = true;
            me->SetGoState(GO_STATE_READY);
            _events.ScheduleEvent(EVENT_FACE_PLAYER, 1s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_trapSmashed)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FIND_MAMMOTH:
                    if (Creature* mammoth = me->FindNearestCreature(NPC_TRAPPED_MAMMOTH, 1.0f, true))
                    {
                        _mammothGUID = mammoth->GetGUID();
                        _trapSmashed = false;
                    }
                    break;
                case EVENT_FACE_PLAYER:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        {
                            mammoth->SetStandState(UNIT_STAND_STATE_STAND);
                            mammoth->SetFacingToObject(player);
                        }
                    _events.ScheduleEvent(EVENT_QUEST_CREDIT, 1s);
                    break;
                case EVENT_QUEST_CREDIT:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        player->KilledMonsterCredit(NPC_TRAPPED_MAMMOTH);
                    _events.ScheduleEvent(EVENT_MAMMOTH_TEXT, 1s);
                    break;
                case EVENT_MAMMOTH_TEXT:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        if (mammoth->IsAIEnabled())
                            mammoth->AI()->Talk(SAY_MAMMOTH);
                    _events.ScheduleEvent(EVENT_MAMMOTH_MOVE, 2s);
                    break;
                case EVENT_MAMMOTH_MOVE:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        mammoth->GetMotionMaster()->MovePoint(0, mammoth->GetFirstCollisionPosition(50.0f, me->GetOrientation()));
                    _events.ScheduleEvent(EVENT_MAMMOTH_DESPAWN, 9s);
                    break;
                case EVENT_MAMMOTH_DESPAWN:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        mammoth->DespawnOrUnsummon(0s, 120s);
                    _events.ScheduleEvent(EVENT_MAMMOTH_RESPAWN, 5s);
                    break;
                case EVENT_MAMMOTH_RESPAWN:
                    if (me->FindNearestCreature(NPC_TRAPPED_MAMMOTH, 1.0f, true))
                        Reset();
                    else
                        _events.ScheduleEvent(EVENT_MAMMOTH_RESPAWN, 5s);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    bool _trapSmashed;
    ObjectGuid _playerGUID;
    ObjectGuid _mammothGUID;
};

enum red_dragonblood
{
    SPELL_DRAKE_HATCHLING_SUBDUED = 46691,
    SPELL_SUBDUED = 46675
};

// 46620 - Red Dragonblood
class spell_red_dragonblood : public AuraScript
{
    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE || !GetCaster())
            return;

        Creature* owner = GetOwner()->ToCreature();
        owner->RemoveAllAurasExceptType(SPELL_AURA_DUMMY);
        owner->CombatStop(true);
        owner->GetMotionMaster()->Clear();
        owner->GetMotionMaster()->MoveFollow(GetCaster(), 4.0f, 0.0f);
        owner->CastSpell(owner, SPELL_SUBDUED, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_DRAKE_HATCHLING_SUBDUED, true);
        owner->SetFaction(FACTION_FRIENDLY);
        owner->SetImmuneToAll(true);
        owner->DespawnOrUnsummon(3min);
    }

    void Register()
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_red_dragonblood::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/*######
## Valiance Keep Cannoneer script to activate cannons
######*/

enum Valiancekeepcannons
{
    GO_VALIANCE_KEEP_CANNON_1                     = 187560,
    GO_VALIANCE_KEEP_CANNON_2                     = 188692
};

struct npc_valiance_keep_cannoneer : public ScriptedAI
{
    npc_valiance_keep_cannoneer(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        uiTimer = urand(13000, 18000);
    }

    uint32 uiTimer;

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (uiTimer <= diff)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
            GameObject* pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_1, 10);
            if (!pCannon)
                pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_2, 10);
            if (pCannon)
                pCannon->Use(me);
            uiTimer = urand(13000, 18000);
        }
        else uiTimer -= diff;

        if (!UpdateVictim())
            return;
    }
};

/*######
## npc_hidden_cultist
######*/

enum HiddenCultist
{
    SPELL_SHROUD_OF_THE_DEATH_CULTIST           = 46077, //not working
    SPELL_RIGHTEOUS_VISION                      = 46078, //player aura

    QUEST_THE_HUNT_IS_ON                        = 11794,

    GOSSIP_TEXT_SALTY_JOHN_THORPE               = 12529,
    GOSSIP_TEXT_GUARD_MITCHELSS                 = 12530,
    GOSSIP_TEXT_TOM_HEGGER                      = 12528,

    NPC_TOM_HEGGER                              = 25827,
    NPC_SALTY_JOHN_THORPE                       = 25248,
    NPC_GUARD_MITCHELLS                         = 25828,

    SAY_HIDDEN_CULTIST_1                        = 0,
    SAY_HIDDEN_CULTIST_2                        = 1,
    SAY_HIDDEN_CULTIST_3                        = 2,
    SAY_HIDDEN_CULTIST_4                        = 3,

    GOSSIP_ITEM_TOM_HEGGER_MENUID               = 9217, //What do you know about the Cult of the Damned?
    GOSSIP_ITEM_GUARD_MITCHELLS_MENUID          = 9219, //How long have you worked for the Cult of the Damned?
    GOSSIP_ITEM_SALTY_JOHN_THORPE_MENUID        = 9218, //I have a reason to believe you're involved in the cultist activity
    GOSSIP_ITEM_HIDDEN_CULTIST_OPTIONID         = 0
};

struct npc_hidden_cultist : public ScriptedAI
{
    npc_hidden_cultist(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        uiEmoteState = creature->GetEmoteState();
        uiNpcFlags = creature->GetNpcFlags();
    }

    void Initialize()
    {
        uiEventTimer = 0;
        uiEventPhase = 0;

        uiPlayerGUID.Clear();
    }

    Emote uiEmoteState;
    NPCFlags uiNpcFlags;

    uint32 uiEventTimer;
    uint8 uiEventPhase;

    ObjectGuid uiPlayerGUID;

    void Reset() override
    {
        if (uiEmoteState)
            me->SetEmoteState(uiEmoteState);

        if (uiNpcFlags)
            me->ReplaceAllNpcFlags(uiNpcFlags);

        Initialize();

        DoCast(SPELL_SHROUD_OF_THE_DEATH_CULTIST);

        me->RestoreFaction();
    }

    void DoAction(int32 /*iParam*/) override
    {
        me->StopMoving();
        me->ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
            me->SetFacingToObject(player);
        uiEventTimer = 3000;
        uiEventPhase = 1;
    }

    void AttackPlayer()
    {
        me->SetFaction(FACTION_MONSTER);
        if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
            AttackStart(player);
    }

    void UpdateAI(uint32 uiDiff) override
    {
        if (uiEventTimer && uiEventTimer <= uiDiff)
        {
            switch (uiEventPhase)
            {
                case 1:
                    switch (me->GetEntry())
                    {
                        case NPC_SALTY_JOHN_THORPE:
                            Talk(SAY_HIDDEN_CULTIST_1);
                            uiEventTimer = 5000;
                            uiEventPhase = 2;
                            break;
                        case NPC_GUARD_MITCHELLS:
                            Talk(SAY_HIDDEN_CULTIST_2);
                            uiEventTimer = 5000;
                            uiEventPhase = 2;
                            break;
                        case NPC_TOM_HEGGER:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                                Talk(SAY_HIDDEN_CULTIST_3, player);
                            uiEventTimer = 5000;
                            uiEventPhase = 2;
                            break;
                    }
                    break;
                case 2:
                    switch (me->GetEntry())
                    {
                        case NPC_SALTY_JOHN_THORPE:
                            Talk(SAY_HIDDEN_CULTIST_4);
                            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                                me->SetFacingToObject(player);
                            uiEventTimer = 3000;
                            uiEventPhase = 3;
                            break;
                        case NPC_GUARD_MITCHELLS:
                        case NPC_TOM_HEGGER:
                            AttackPlayer();
                            uiEventPhase = 0;
                            break;
                    }
                    break;
                case 3:
                    if (me->GetEntry() == NPC_SALTY_JOHN_THORPE)
                    {
                        AttackPlayer();
                        uiEventPhase = 0;
                    }
                    break;
            }
        }else uiEventTimer -= uiDiff;

        if (!UpdateVictim())
            return;
    }

    bool OnGossipHello(Player* player) override
    {
        uint32 uiGossipText = 0;
        uint32 charGossipItem = 0;

        switch (me->GetEntry())
        {
            case NPC_TOM_HEGGER:
                uiGossipText = GOSSIP_TEXT_TOM_HEGGER;
                charGossipItem = GOSSIP_ITEM_TOM_HEGGER_MENUID;
                break;
            case NPC_SALTY_JOHN_THORPE:
                uiGossipText = GOSSIP_TEXT_SALTY_JOHN_THORPE;
                charGossipItem = GOSSIP_ITEM_SALTY_JOHN_THORPE_MENUID;
                break;
            case NPC_GUARD_MITCHELLS:
                uiGossipText = GOSSIP_TEXT_GUARD_MITCHELSS;
                charGossipItem = GOSSIP_ITEM_GUARD_MITCHELLS_MENUID;
                break;
            default:
                return false;
        }

        InitGossipMenuFor(player, charGossipItem);
        if (player->HasAura(SPELL_RIGHTEOUS_VISION) && player->GetQuestStatus(QUEST_THE_HUNT_IS_ON) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, charGossipItem, GOSSIP_ITEM_HIDDEN_CULTIST_OPTIONID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (me->IsVendor())
            AddGossipItemFor(player, GossipOptionNpc::Vendor, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        SendGossipMenuFor(player, uiGossipText, me->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        ClearGossipMenuFor(player);

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            CloseGossipMenuFor(player);
            uiPlayerGUID = player->GetGUID();
            DoAction(1);
        }

        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(me->GetGUID());

        return true;
    }
};

/*######
## Quest 12019: Last Rites
######*/

// NPC 26170: Thassarian
enum Thassarian
{
    EVENT_THASSARIAN_SCRIPT_1  = 1,
    EVENT_THASSARIAN_SCRIPT_2,
    EVENT_THASSARIAN_SCRIPT_3,
    EVENT_THASSARIAN_SCRIPT_4,
    EVENT_THASSARIAN_SCRIPT_5,
    EVENT_THASSARIAN_SCRIPT_6,
    EVENT_THASSARIAN_SCRIPT_7,
    EVENT_THASSARIAN_SCRIPT_8,
    EVENT_THASSARIAN_SCRIPT_9,
    EVENT_THASSARIAN_SCRIPT_10,
    EVENT_THASSARIAN_SCRIPT_11,
    EVENT_THASSARIAN_SCRIPT_12,
    EVENT_THASSARIAN_SCRIPT_13,
    EVENT_THASSARIAN_SCRIPT_14,
    EVENT_THASSARIAN_SCRIPT_15,
    EVENT_THASSARIAN_SCRIPT_16,
    EVENT_THASSARIAN_SCRIPT_17,
    EVENT_THASSARIAN_SCRIPT_18,
    EVENT_THASSARIAN_SCRIPT_19,
    EVENT_THASSARIAN_SCRIPT_20,
    EVENT_THASSARIAN_SCRIPT_21,
    EVENT_THASSARIAN_SCRIPT_22,
    EVENT_THASSARIAN_SCRIPT_23,
    EVENT_THASSARIAN_SCRIPT_24,
    EVENT_THASSARIAN_SCRIPT_25,
    EVENT_THASSARIAN_SCRIPT_26,
    EVENT_THASSARIAN_SCRIPT_27,
    EVENT_THASSARIAN_SCRIPT_28,
    EVENT_THASSARIAN_SCRIPT_29,

    FACTION_VALANAR_COMBAT      = 1988,

    NPC_IMAGE_LICH_KING         = 26203,
    NPC_COUNSELOR_TALBOT        = 25301,
    NPC_PRINCE_VALANAR          = 28189,
    NPC_GENERAL_ARLOS           = 25250,
    NPC_LERYSSA                 = 25251,

    SPELL_TRANSFORM_VALANAR     = 46753,
    SPELL_STUN                  = 46957,

    SAY_THASSARIAN_1            = 0,
    SAY_THASSARIAN_2            = 1,
    SAY_THASSARIAN_3            = 2,
    SAY_THASSARIAN_4            = 3,
    SAY_THASSARIAN_5            = 4,
    SAY_THASSARIAN_6            = 5,
    SAY_THASSARIAN_7            = 6,
    SAY_TALBOT_1                = 0,
    SAY_TALBOT_2                = 1,
    SAY_TALBOT_3                = 2,
    SAY_TALBOT_4                = 3,
    SAY_LICH_1                  = 0,
    SAY_LICH_2                  = 1,
    SAY_LICH_3                  = 2,
    SAY_ARLOS_1                 = 0,
    SAY_ARLOS_2                 = 1,
    SAY_LERYSSA_1               = 0,
    SAY_LERYSSA_2               = 1,
    SAY_LERYSSA_3               = 2,
    SAY_LERYSSA_4               = 3,

    PATH_THASSARIAN             = 8104240,
    PATH_ARTHAS                 = 8104248,
    PATH_TALBOT                 = 8104256,
    PATH_ARLOS                  = 8104264,
    PATH_LERYSSA                = 8104272
};

struct npc_thassarian : public ScriptedAI
{
    npc_thassarian(Creature* creature) : ScriptedAI(creature), _questEventStarted(false), _preFightComplete(false), ArlosInPosition(false), LeryssaInPosition(false), TalbotJustDied(false) { }

    void JustAppeared() override
    {
        me->RestoreFaction();
        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_THASSARIAN)
        {
            me->SetWalk(false);
            me->SetEmoteState(EMOTE_STATE_READY1H);
            _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_1, 2s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_questEventStarted)
            return;

        if (ArlosInPosition && LeryssaInPosition)
        {
            ArlosInPosition = false;
            LeryssaInPosition = false;
            _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_8, 1s);
        }

        if (TalbotJustDied && _preFightComplete)
        {
            TalbotJustDied = false;
            _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_18, 0s);
        }

        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THASSARIAN_SCRIPT_1:
                    // Summon Arthas and Talbot
                    if (Creature* arthas = me->SummonCreature(NPC_IMAGE_LICH_KING, 3729.4614f, 3520.386f, 473.4048f, 1.361f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _arthasGUID = arthas->GetGUID();
                        arthas->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        arthas->SetReactState(REACT_PASSIVE);
                        arthas->SetWalk(true);
                    }
                    if (Creature* talbot = me->SummonCreature(NPC_COUNSELOR_TALBOT, 3748.7627f, 3614.0374f, 473.4048f, 4.5553f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _talbotGUID = talbot->GetGUID();
                        talbot->SetWalk(true);
                        TalbotJustDied = false;
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_2, 1s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_2:
                    // Arthas load path
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                        arthas->GetMotionMaster()->MovePath(PATH_ARTHAS, false);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_3, 1s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_3:
                    // Talbot load path
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                        talbot->GetMotionMaster()->MovePath(PATH_TALBOT, false);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_4, 22s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_4:
                    // Talbot transform and knell
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                    {
                        talbot->UpdateEntry(NPC_PRINCE_VALANAR);
                        talbot->SetFullHealth();
                        talbot->SetFaction(FACTION_UNDEAD_SCOURGE);
                        talbot->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        talbot->SetReactState(REACT_PASSIVE);
                        talbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_5, 7s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_5:
                    // Talbot say text 1
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                        if (talbot->IsAIEnabled())
                            talbot->AI()->Talk(SAY_TALBOT_1);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_6, 9s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_6:
                    // Summon General Arlos and Leryssa
                    if (Creature* arlos = me->SummonCreature(NPC_GENERAL_ARLOS, 3746.2825f, 3616.3699f, 473.4048f, 4.5029f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _arlosGUID = arlos->GetGUID();
                        arlos->SetWalk(true);
                        arlos->SetReactState(REACT_PASSIVE);
                        arlos->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                        arlos->GetMotionMaster()->MovePath(PATH_ARLOS, false);
                    }
                    if (Creature* leryssa = me->SummonCreature(NPC_LERYSSA, 3751.0986f, 3614.9219f, 473.4048f, 4.5029f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _leryssaGUID = leryssa->GetGUID();
                        leryssa->SetWalk(true);
                        leryssa->SetReactState(REACT_PASSIVE);
                        leryssa->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        leryssa->GetMotionMaster()->MovePath(PATH_LERYSSA, false);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_7, 7s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_7:
                    // Talbot say text 2
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                        if (talbot->IsAIEnabled())
                            talbot->AI()->Talk(SAY_TALBOT_2);
                    break;
                case EVENT_THASSARIAN_SCRIPT_8:
                    // Thassarian say text 1 and move to location
                    Talk(SAY_THASSARIAN_1);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, 3722.527f, 3567.2583f, 477.44086f);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_9, 9s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_9:
                    // Thassarian say text 2
                    Talk(SAY_THASSARIAN_2);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_10, 6s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_10:
                    // Arthas turn to Thassarian and Talbot stand
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                        arthas->SetFacingToObject(me);
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                        talbot->SetStandState(UNIT_STAND_STATE_STAND);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_11, 4s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_11:
                    // Arthas say text 2
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                        if (arthas->IsAIEnabled())
                            arthas->AI()->Talk(SAY_LICH_2);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_12, 18s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_12:
                    // Thassarian say text 3
                    Talk(SAY_THASSARIAN_3);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_13, 10s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_13:
                    // Talbot say text 3
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                        if (talbot->IsAIEnabled())
                            talbot->AI()->Talk(SAY_TALBOT_3);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_14, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_14:
                    // Arthas turn to Talbot say text 3
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                    {
                        if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                            arthas->SetFacingToObject(talbot);
                        if (arthas->IsAIEnabled())
                            arthas->AI()->Talk(SAY_LICH_3);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_15, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_15:
                    // Arthas turn to me and emote
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                    {
                        arthas->SetFacingToObject(me);
                        arthas->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_16, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_16:
                    // Arthas despawn
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                        arthas->RemoveFromWorld();
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_17, 3s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_17:
                    // Talbot say text 4 and attack
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                    {
                        if (talbot->IsAIEnabled())
                            talbot->AI()->Talk(SAY_TALBOT_4);
                        talbot->SetFaction(FACTION_VALANAR_COMBAT);
                        talbot->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        talbot->SetReactState(REACT_AGGRESSIVE);
                        talbot->Attack(me, false);
                        _preFightComplete = true;
                    }
                    break;
                case EVENT_THASSARIAN_SCRIPT_18:
                    // Arlos say text 1
                    me->SetEmoteState(EMOTE_STATE_READY1H);
                    if (Creature* arlos = ObjectAccessor::GetCreature(*me, _arlosGUID))
                    {
                        if (arlos->IsAIEnabled())
                            arlos->AI()->Talk(SAY_ARLOS_1);
                        arlos->SetEmoteState(EMOTE_STATE_NONE);
                        arlos->SetStandState(UNIT_STAND_STATE_KNEEL);
                        arlos->RemoveAura(SPELL_STUN);
                    }
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
                        leryssa->SetEmoteState(EMOTE_STATE_NONE);
                        leryssa->RemoveAura(SPELL_STUN);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_19, 3s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_19:
                    // Leryssa set facing to me
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    me->SetNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                    if (Creature* leryssa = me->FindNearestCreature(NPC_LERYSSA, 50.0f, true))
                    {
                        _leryssaGUID = leryssa->GetGUID();
                        leryssa->SetFacingToObject(me);
                        me->SetFacingToObject(leryssa);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_20, 3s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_20:
                    // Arlos say text 2 and die. Leryssa say text 1
                    if (Creature* arlos = me->FindNearestCreature(NPC_GENERAL_ARLOS, 50.0f, true))
                    {
                        _arlosGUID = arlos->GetGUID();
                        if (arlos->IsAIEnabled())
                            arlos->AI()->Talk(SAY_ARLOS_2);
                        arlos->SetStandState(UNIT_STAND_STATE_DEAD);
                    }
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
                        if (leryssa->IsAIEnabled())
                            leryssa->AI()->Talk(SAY_LERYSSA_1);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_21, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_21:
                    // Thassarian say text 4
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    Talk(SAY_THASSARIAN_4);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_22, 3s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_22:
                    // Leryssa run to Thassarian
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
                        leryssa->SetWalk(false);
                        leryssa->MonsterMoveWithSpeed(3726.751f, 3568.1633f, 477.44086f, leryssa->GetSpeed(MOVE_RUN), true, true);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_23, 2s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_23:
                    // Leryssa say text 2
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
                        if (leryssa->IsAIEnabled())
                            leryssa->AI()->Talk(SAY_LERYSSA_2);
                        leryssa->SetStandState(UNIT_STAND_STATE_SIT);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_24, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_24:
                    // Thassarian say text 5
                    Talk(SAY_THASSARIAN_5);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_25, 10s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_25:
                    // Leryssa say text 3
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                        if (leryssa->IsAIEnabled())
                            leryssa->AI()->Talk(SAY_LERYSSA_3);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_26, 12s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_26:
                    // Thassarian say text 6
                    Talk(SAY_THASSARIAN_6);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_27, 11s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_27:
                    // Leryssa say text 4
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                        if (leryssa->IsAIEnabled())
                            leryssa->AI()->Talk(SAY_LERYSSA_4);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_28, 12s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_28:
                    // Thassarian say text 7
                    Talk(SAY_THASSARIAN_7);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_29, 35s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_29:
                    Cleanup();
                    me->DespawnOrUnsummon(0s, 30s);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

    void JustDied(Unit* /*killer*/) override
    {
        Cleanup();
    }

    void Cleanup()
    {
        if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
            talbot->DespawnOrUnsummon();

        if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
            leryssa->DespawnOrUnsummon();

        if (Creature* arlos = ObjectAccessor::GetCreature(*me, _arlosGUID))
            arlos->DespawnOrUnsummon();

        if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
            arthas->DespawnOrUnsummon();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == 0)
        {
            _playerGUID = player->GetGUID();
            CloseGossipMenuFor(player);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            _questEventStarted = true;
            me->GetMotionMaster()->MovePath(PATH_THASSARIAN, false);
        }
        return false;
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
    ObjectGuid _arthasGUID;
    ObjectGuid _talbotGUID;
    ObjectGuid _leryssaGUID;
    ObjectGuid _arlosGUID;
    bool _questEventStarted;
    bool _preFightComplete;
public:
    bool ArlosInPosition;
    bool LeryssaInPosition;
    bool TalbotJustDied;
};

// NPC 25250: General Arlos
struct npc_general_arlos : public ScriptedAI
{
    npc_general_arlos(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_ARLOS)
        {
            me->AddUnitState(UNIT_STATE_STUNNED);
            DoCastSelf(SPELL_STUN);
            if (TempSummon* tempSummon = me->ToTempSummon())
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian, summoner->GetAI())->ArlosInPosition = true;
        }
    }
};

// NPC 25251: Leryssa
struct npc_leryssa : public ScriptedAI
{
    npc_leryssa(Creature* creature) : ScriptedAI(creature) {}

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_LERYSSA)
        {
            me->SetFacingTo(4.537856f);
            me->AddUnitState(UNIT_STATE_STUNNED);
            DoCastSelf(SPELL_STUN);
            if (TempSummon* tempSummon = me->ToTempSummon())
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian, summoner->GetAI())->LeryssaInPosition = true;
        }
    }
};

// NPC 25301: Counselor Talbot
enum CounselorTalbot
{
    AREA_LAST_RITES     = 4128,

    EVENT_DEFLECTION    = 1,
    EVENT_SOUL_BLAST,
    EVENT_VAMPIRIC_BOLT,

    SPELL_DEFLECTION    = 51009,
    SPELL_SOUL_BLAST    = 50992,
    SPELL_VAMPIRIC_BOLT = 51016
};

struct npc_counselor_talbot : public ScriptedAI
{
    npc_counselor_talbot(Creature* creature) : ScriptedAI(creature) {}

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_DEFLECTION, 10s, 20s);
        _events.ScheduleEvent(EVENT_SOUL_BLAST, 4s, 6s);
        _events.ScheduleEvent(EVENT_VAMPIRIC_BOLT, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->GetAreaId() == AREA_LAST_RITES)
        {
            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEFLECTION:
                        DoCastSelf(SPELL_DEFLECTION);
                        _events.ScheduleEvent(EVENT_DEFLECTION, 10s, 20s);
                        break;
                    case EVENT_SOUL_BLAST:
                        DoCastVictim(SPELL_SOUL_BLAST);
                        _events.ScheduleEvent(EVENT_SOUL_BLAST, 4s, 6s);
                        break;
                    case EVENT_VAMPIRIC_BOLT:
                        DoCastVictim(SPELL_VAMPIRIC_BOLT);
                        _events.ScheduleEvent(EVENT_VAMPIRIC_BOLT, 3s, 4s);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (TempSummon* tempSummon = me->ToTempSummon())
            if (Unit* summoner = tempSummon->GetSummonerUnit())
                ENSURE_AI(npc_thassarian, summoner->GetAI())->TalbotJustDied = true;
    }

private:
    EventMap _events;
};

enum WindsoulTotemAura
{
    SPELL_WINDSOUL_CREDT = 46378
};

// 46374 - Windsoul Totem Aura
class spell_windsoul_totem_aura : public AuraScript
{
    void OnRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        if (GetTarget()->isDead())
            if (Unit* caster = GetCaster())
                caster->CastSpell(nullptr, SPELL_WINDSOUL_CREDT);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_windsoul_totem_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum BloodsporeRuination
{
    NPC_BLOODMAGE_LAURITH   = 25381,
    SAY_BLOODMAGE_LAURITH   = 0,
    EVENT_TALK              = 1,
    EVENT_RESET_ORIENTATION
};

// 45997 - Bloodspore Ruination
class spell_q11719_bloodspore_ruination_45997 : public SpellScript
{
    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* laurith = caster->FindNearestCreature(NPC_BLOODMAGE_LAURITH, 100.0f))
                laurith->AI()->SetGUID(caster->GetGUID());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11719_bloodspore_ruination_45997::HandleEffect, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
    }
};

struct npc_bloodmage_laurith : public ScriptedAI
{
    npc_bloodmage_laurith(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _playerGUID.Clear();
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_playerGUID.IsEmpty())
            return;

        _playerGUID = guid;

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            me->SetFacingToObject(player);

        _events.ScheduleEvent(EVENT_TALK, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (UpdateVictim())
            return;

        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(SAY_BLOODMAGE_LAURITH, player);
                    _playerGUID.Clear();
                    _events.ScheduleEvent(EVENT_RESET_ORIENTATION, 5s);
                    break;
                case EVENT_RESET_ORIENTATION:
                    me->SetFacingTo(me->GetHomePosition().GetOrientation());
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
};

enum ShorteningBlaster
{
    SPELL_SHORTENING_BLASTER_BIGGER1    = 45674,
    SPELL_SHORTENING_BLASTER_SHRUNK1    = 45675,
    SPELL_SHORTENING_BLASTER_YELLOW1    = 45678,
    SPELL_SHORTENING_BLASTER_GHOST1     = 45682,
    SPELL_SHORTENING_BLASTER_POLYMORPH1 = 45684,

    SPELL_SHORTENING_BLASTER_BIGGER2    = 45673,
    SPELL_SHORTENING_BLASTER_SHRUNK2    = 45672,
    SPELL_SHORTENING_BLASTER_YELLOW2    = 45677,
    SPELL_SHORTENING_BLASTER_GHOST2     = 45682,
    SPELL_SHORTENING_BLASTER_POLYMORPH2 = 45683
};

// 45668 - Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
class spell_q11653_shortening_blaster : public SpellScript
{
    void HandleScript(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        uint32 spellId = RAND(SPELL_SHORTENING_BLASTER_BIGGER1, SPELL_SHORTENING_BLASTER_SHRUNK1, SPELL_SHORTENING_BLASTER_YELLOW1,
            SPELL_SHORTENING_BLASTER_GHOST1, SPELL_SHORTENING_BLASTER_POLYMORPH1);
        uint32 spellId2 = RAND(SPELL_SHORTENING_BLASTER_BIGGER2, SPELL_SHORTENING_BLASTER_SHRUNK2, SPELL_SHORTENING_BLASTER_YELLOW2,
            SPELL_SHORTENING_BLASTER_GHOST2, SPELL_SHORTENING_BLASTER_POLYMORPH2);

        caster->CastSpell(caster, spellId, true);
        target->CastSpell(target, spellId2, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11653_shortening_blaster::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11611: Taken by the Scourge
######*/

enum TakenByTheScourge
{
    SPELL_FREED_WARSONG_MAGE        = 45526,
    SPELL_FREED_WARSONG_SHAMAN      = 45527,
    SPELL_FREED_WARSONG_WARRIOR     = 45514,
    SPELL_FREED_WARSONG_PEON        = 45532,
    SPELL_FREED_SOLDIER_DEBUFF      = 45523
};

std::array<uint32, 3> const CocoonSummonSpells =
{
    SPELL_FREED_WARSONG_MAGE, SPELL_FREED_WARSONG_SHAMAN, SPELL_FREED_WARSONG_WARRIOR
};

// 45516 - Nerub'ar Web Random Unit (Not On Quest, Script Effect)
class spell_borean_tundra_nerubar_web_random_unit_not_on_quest : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_borean_tundra_nerubar_web_random_unit_not_on_quest::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45515 - Nerub'ar Web Random Unit (Not On Quest, Dummy)
class spell_borean_tundra_nerubar_web_random_unit_not_on_quest_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells) && ValidateSpellInfo({ SPELL_FREED_SOLDIER_DEBUFF });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        // Do nothing if has 3 soldiers
        Aura* aura = caster->GetAura(SPELL_FREED_SOLDIER_DEBUFF);
        if (!aura || aura->GetStackAmount() < 3)
            caster->CastSpell(caster, Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_borean_tundra_nerubar_web_random_unit_not_on_quest_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 45535 - Nerub'ar Web Random Unit (On Quest, Dummy)
class spell_borean_tundra_nerubar_web_random_unit_on_quest_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells) && ValidateSpellInfo({ SPELL_FREED_SOLDIER_DEBUFF, SPELL_FREED_WARSONG_PEON });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        // Always summon peon if has 3 soldiers
        Aura* aura = caster->GetAura(SPELL_FREED_SOLDIER_DEBUFF);
        if ((!aura || aura->GetStackAmount() < 3) && roll_chance_i(75))
            caster->CastSpell(caster, Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
        else
            caster->CastSpell(nullptr, SPELL_FREED_WARSONG_PEON, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_borean_tundra_nerubar_web_random_unit_on_quest_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 45522 - Dispel Freed Soldier Debuff
class spell_borean_tundra_dispel_freed_soldier_debuff : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetHitUnit()->GetAura(uint32(GetEffectValue())))
            aura->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_borean_tundra_dispel_freed_soldier_debuff::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11690: Bring 'Em Back Alive
######*/

enum BringEmBackAlive
{
    SPELL_KODO_DELIVERED   = 48203,

    TEXT_DELIVERED_1       = 24881,
    TEXT_DELIVERED_2       = 24882,
    TEXT_DELIVERED_3       = 26284,
    TEXT_DELIVERED_4       = 26285,
    TEXT_DELIVERED_5       = 26286
};

// 45877 - Deliver Kodo
class spell_borean_tundra_deliver_kodo : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_KODO_DELIVERED });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_KODO_DELIVERED, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_borean_tundra_deliver_kodo::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 48204 - Kodo Delivered
class spell_borean_tundra_kodo_delivered : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return sBroadcastTextStore.HasRecord(TEXT_DELIVERED_1) &&
            sBroadcastTextStore.HasRecord(TEXT_DELIVERED_2) &&
            sBroadcastTextStore.HasRecord(TEXT_DELIVERED_3) &&
            sBroadcastTextStore.HasRecord(TEXT_DELIVERED_4) &&
            sBroadcastTextStore.HasRecord(TEXT_DELIVERED_5);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->Unit::Say(RAND(TEXT_DELIVERED_1, TEXT_DELIVERED_2, TEXT_DELIVERED_3, TEXT_DELIVERED_4, TEXT_DELIVERED_5), caster);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_borean_tundra_kodo_delivered::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11648: The Art of Persuasion
######*/

enum TheArtOfPersuasion
{
    WHISPER_TORTURE_1                      = 0,
    WHISPER_TORTURE_2                      = 1,
    WHISPER_TORTURE_3                      = 2,
    WHISPER_TORTURE_4                      = 3,
    WHISPER_TORTURE_5                      = 4,
    WHISPER_TORTURE_RANDOM_1               = 5,
    WHISPER_TORTURE_RANDOM_2               = 6,
    WHISPER_TORTURE_RANDOM_3               = 7,

    WHISPER_TORTURE_PROTO_1                = 8,
    WHISPER_TORTURE_PROTO_2                = 9,
    WHISPER_TORTURE_PROTO_3                = 10,
    WHISPER_TORTURE_PROTO_4                = 11,
    WHISPER_TORTURE_PROTO_5                = 12,
    WHISPER_TORTURE_PROTO_6                = 13,
    WHISPER_TORTURE_PROTO_7                = 14,
    WHISPER_TORTURE_PROTO_8                = 15,
    WHISPER_TORTURE_PROTO_9                = 16,
    WHISPER_TORTURE_PROTO_10               = 17,

    SPELL_NEURAL_NEEDLE_IMPACT             = 45702,
    SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT   = 48254
};

// 45634 - Neural Needle
class spell_borean_tundra_neural_needle : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NEURAL_NEEDLE_IMPACT });
    }

    void HandleWhisper()
    {
        Player* caster = GetCaster()->ToPlayer();
        Creature* target = GetHitCreature();
        if (!caster || !target)
            return;

        target->CastSpell(target, SPELL_NEURAL_NEEDLE_IMPACT);

        if (Aura* aura = caster->GetAura(GetSpellInfo()->Id))
        {
            switch (aura->GetStackAmount())
            {
                case 1:
                    target->AI()->Talk(WHISPER_TORTURE_1, caster);
                    break;
                case 2:
                    target->AI()->Talk(WHISPER_TORTURE_2, caster);
                    break;
                case 3:
                    target->AI()->Talk(WHISPER_TORTURE_3, caster);
                    break;
                case 4:
                    target->AI()->Talk(WHISPER_TORTURE_4, caster);
                    break;
                case 5:
                    target->AI()->Talk(WHISPER_TORTURE_5, caster);
                    caster->KilledMonsterCredit(target->GetEntry());
                    break;
                case 6:
                    target->AI()->Talk(RAND(WHISPER_TORTURE_RANDOM_1, WHISPER_TORTURE_RANDOM_2, WHISPER_TORTURE_RANDOM_3), caster);
                    break;
                default:
                    return;
            }
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_borean_tundra_neural_needle::HandleWhisper);
    }
};

// 48252 - Prototype Neural Needle
class spell_borean_tundra_prototype_neural_needle : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT });
    }

    void HandleWhisper()
    {
        Player* caster = GetCaster()->ToPlayer();
        Creature* target = GetHitCreature();
        if (!caster || !target)
            return;

        target->CastSpell(target, SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT);

        uint32 text = 0;
        if (Aura* aura = caster->GetAura(GetSpellInfo()->Id))
        {
            switch (aura->GetStackAmount())
            {
                case 1: text = WHISPER_TORTURE_PROTO_1; break;
                case 2: text = WHISPER_TORTURE_PROTO_2; break;
                case 3: text = WHISPER_TORTURE_PROTO_3; break;
                case 4: text = WHISPER_TORTURE_PROTO_4; break;
                case 5: text = WHISPER_TORTURE_PROTO_5; break;
                case 6: text = WHISPER_TORTURE_PROTO_6; break;
                case 7: text = WHISPER_TORTURE_PROTO_7; break;
                case 8: text = WHISPER_TORTURE_PROTO_8; break;
                case 9: text = WHISPER_TORTURE_PROTO_9; break;
                case 10: text = WHISPER_TORTURE_PROTO_10; break;
                default: return;
            }
        }

        if (text)
            target->AI()->Talk(text, caster);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_borean_tundra_prototype_neural_needle::HandleWhisper);
    }
};

/*######
## Quest 11587: Prison Break
######*/

enum PrisonBreak
{
    SPELL_SUMMON_ARCANE_PRISONER_1    = 45446,
    SPELL_SUMMON_ARCANE_PRISONER_2    = 45448
};

// 45449 - Arcane Prisoner Rescue
class spell_borean_tundra_arcane_prisoner_rescue : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ARCANE_PRISONER_1, SPELL_SUMMON_ARCANE_PRISONER_2 });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), RAND(SPELL_SUMMON_ARCANE_PRISONER_1, SPELL_SUMMON_ARCANE_PRISONER_2));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_borean_tundra_arcane_prisoner_rescue::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_borean_tundra()
{
    RegisterCreatureAI(npc_beryl_sorcerer);
    RegisterCreatureAI(npc_captured_beryl_sorcerer);
    RegisterSpellScript(spell_arcane_chains_character_force_cast);
    RegisterGameObjectAI(go_caribou_trap);
    RegisterGameObjectAI(go_mammoth_trap);
    RegisterSpellScript(spell_red_dragonblood);
    RegisterCreatureAI(npc_valiance_keep_cannoneer);
    RegisterCreatureAI(npc_hidden_cultist);
    RegisterCreatureAI(npc_thassarian);
    RegisterCreatureAI(npc_general_arlos);
    RegisterCreatureAI(npc_leryssa);
    RegisterCreatureAI(npc_counselor_talbot);
    RegisterSpellScript(spell_windsoul_totem_aura);
    RegisterSpellScript(spell_q11719_bloodspore_ruination_45997);
    RegisterCreatureAI(npc_bloodmage_laurith);
    RegisterSpellScript(spell_q11653_shortening_blaster);
    RegisterSpellScript(spell_borean_tundra_nerubar_web_random_unit_not_on_quest);
    RegisterSpellScript(spell_borean_tundra_nerubar_web_random_unit_not_on_quest_dummy);
    RegisterSpellScript(spell_borean_tundra_nerubar_web_random_unit_on_quest_dummy);
    RegisterSpellScript(spell_borean_tundra_dispel_freed_soldier_debuff);
    RegisterSpellScript(spell_borean_tundra_deliver_kodo);
    RegisterSpellScript(spell_borean_tundra_kodo_delivered);
    RegisterSpellScript(spell_borean_tundra_neural_needle);
    RegisterSpellScript(spell_borean_tundra_prototype_neural_needle);
    RegisterSpellScript(spell_borean_tundra_arcane_prisoner_rescue);
}
