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
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
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
#include "CombatAI.h"

 /*######
 ## Quest 11590: Abduction
 ######*/

// NPC 25316: Beryl Sorcerer
enum BerylSorcerer
{
    EVENT_FROSTBOLT                                   = 1,
    EVENT_ARCANE_CHAINS                               = 2,
    EVENT_DESPAWN                                     = 3,
    NPC_LIBRARIAN_DONATHAN                            = 25262,
    NPC_CAPTURED_BERLY_SORCERER                       = 25474,
    SPELL_FROSTBOLT                                   = 9672,
    SPELL_ARCANE_CHAINS                               = 45611,
    SPELL_ARCANE_CHAINS_CHARACTER_FORCE_CAST          = 45625,
    SPELL_ARCANE_CHAINS_SUMMON_CHAINED_MAGE_HUNTER    = 45626,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF                = 45631,
    SPELL_ARCANE_CHAINS_CHANNEL_II                    = 45735
};

struct npc_beryl_sorcerer : public CreatureAI
{
    npc_beryl_sorcerer(Creature* creature) : CreatureAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _playerGUID.Clear();
        _chainsCast = false;
    }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        Initialize();
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

        if (spellInfo->Id == SPELL_ARCANE_CHAINS)
            if (Player* player = caster->ToPlayer())
            {
                _playerGUID = player->GetGUID();
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
                        me->CastSpell(player, SPELL_ARCANE_CHAINS_CHARACTER_FORCE_CAST);
                    _events.ScheduleEvent(EVENT_DESPAWN, 1s);
                    break;
                case EVENT_DESPAWN:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        player->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
    private:
        EventMap _events;
        ObjectGuid _playerGUID;
        bool _chainsCast;
};

// NPC 25474: Captured Beryl Sorcerer
struct npc_captured_beryl_sorcerer : public FollowerAI
{
    npc_captured_beryl_sorcerer(Creature* creature) : FollowerAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        if (Player* summoner = me->ToTempSummon()->GetSummonerUnit()->ToPlayer())
        {
            summoner->CastSpell(summoner, SPELL_ARCANE_CHAINS_CHANNEL_II);
            StartFollow(summoner);
        }
    }

    void Reset() override {}

    void MoveInLineOfSight(Unit* who) override
    {
        FollowerAI::MoveInLineOfSight(who);

        if (who->GetEntry() == NPC_LIBRARIAN_DONATHAN && me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
        {
            SetFollowComplete();
            me->DisappearAndDie();
        }
    }
};

// Spell 45625: - Arcane Chains: Character Force Cast
class spell_arcane_chains_character_force_cast : public SpellScript
{
    PrepareSpellScript(spell_arcane_chains_character_force_cast);

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
## Quest 11611: Taken by the Scourge "Not correct needs work"
######*/

enum TakenByTheScourge
{
    SPELL_FREED_WARSONG_MAGE    = 45526,
    SPELL_FREED_WARSONG_SHAMAN  = 45527,
    SPELL_FREED_WARSONG_WARRIOR = 45514,
    SPELL_FREED_WARSONG_PEON    = 45532,
    SPELL_FREED_SOLDIER_DEBUFF  = 45523
};

std::array<uint32, 3> const CocoonSummonSpells =
{
    SPELL_FREED_WARSONG_MAGE, SPELL_FREED_WARSONG_SHAMAN, SPELL_FREED_WARSONG_WARRIOR
};

// Spell 45516: Nerub'ar Web Random Unit (Not On Quest, Script Effect)
class spell_nerubar_web_random_unit_not_on_quest : public SpellScript
{
    PrepareSpellScript(spell_nerubar_web_random_unit_not_on_quest);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectInfo().CalcValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_nerubar_web_random_unit_not_on_quest::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Spell 45515: Nerub'ar Web Random Unit (Not On Quest, Dummy)
class spell_nerubar_web_random_unit_not_on_quest_dummy : public SpellScript
{
    PrepareSpellScript(spell_nerubar_web_random_unit_not_on_quest_dummy);

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
        OnEffectHit += SpellEffectFn(spell_nerubar_web_random_unit_not_on_quest_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell 45535: Nerub'ar Web Random Unit (On Quest, Dummy)
class spell_nerubar_web_random_unit_on_quest_dummy : public SpellScript
{
    PrepareSpellScript(spell_nerubar_web_random_unit_on_quest_dummy);

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
        OnEffectHit += SpellEffectFn(spell_nerubar_web_random_unit_on_quest_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell 45522: Dispel Freed Soldier Debuff
class spell_dispel_freed_soldier_debuff : public SpellScript
{
    PrepareSpellScript(spell_dispel_freed_soldier_debuff);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetHitUnit()->GetAura(GetEffectInfo().CalcValue()))
            aura->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dispel_freed_soldier_debuff::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11648: The Art of Persuasion
######*/

// NPC 25478: Imprisoned Beryl Sorcerer
enum ImprisionedBerylSorcerer
{
    SPELL_NEURAL_NEEDLE                  = 45634,
    SPELL_PROTOTYPE_NEURAL_NEEDLE        = 48252,
    SPELL_NEURAL_NEEDLE_IMPACT           = 45702,
    SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT = 48254,
    NPC_IMPRISONED_BERYL_SORCERER        = 25478,
    QUEST_THE_ART_OF_PERSUASION          = 11648,
    EVENT_REBUFF                         = 1
};

struct npc_imprisoned_beryl_sorcerer : public ScriptedAI
{
    npc_imprisoned_beryl_sorcerer(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _events.ScheduleEvent(EVENT_REBUFF, 0s);
    }

    void Reset() override
    {
        if (me->GetReactState() != REACT_PASSIVE)
            me->SetReactState(REACT_PASSIVE);

        Initialize();
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Player* playerCaster = caster->ToPlayer();
        if (!playerCaster)
            return;

        if (spellInfo->Id == SPELL_NEURAL_NEEDLE || spellInfo->Id == SPELL_PROTOTYPE_NEURAL_NEEDLE)
            GotStung(playerCaster, spellInfo->Id);
    }

    void GotStung(Player* caster, uint32 spellId)
    {
        DoCastSelf(spellId == SPELL_NEURAL_NEEDLE ? SPELL_NEURAL_NEEDLE_IMPACT : SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT);

        // Event cannot happen if quest is not accepted/completed/rewarded
        if (caster->GetQuestStatus(QUEST_THE_ART_OF_PERSUASION) == QUEST_STATUS_NONE)
            return;

        uint32 step = 0;

        if (spellId == SPELL_NEURAL_NEEDLE)
            step = caster->GetAuraCount(SPELL_NEURAL_NEEDLE); // Text IDs 0-6
        else
            step = caster->GetAuraCount(SPELL_PROTOTYPE_NEURAL_NEEDLE) + 7; // Text IDs 7-18

        if (spellId == SPELL_NEURAL_NEEDLE && step == 4)
            caster->KilledMonsterCredit(NPC_IMPRISONED_BERYL_SORCERER);

        Talk(step, caster);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REBUFF:
                    if (!me->HasAura(SPELL_COSMETIC_ENSLAVE_CHAINS_SELF))
                        DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF);
                    _events.ScheduleEvent(EVENT_REBUFF, 18s);
                    break;
                default:
                    break;
            }
        }

        UpdateVictim();
        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

/*######
## Quest 11653: Hah... You're Not So Big Now!
######*/

// Spell 45668: Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
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

class spell_q11653_shortening_blaster : public SpellScript
{
    PrepareSpellScript(spell_q11653_shortening_blaster);

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
## Quest 11661: Orabus the Helmsman "Not Assigned in DB?"
######*/

// NPC 32576: Orabus the Helmsman
enum OrabusTheHelmsman
{
    NPC_ORABUS            = 32576,
    NPC_KVALDIR_CREWMAN_1 = 32577,
    NPC_KVALDIR_CREWMAN_2 = 32578,
    NPC_KVALDIR_CREWMAN_3 = 32579,
    NPC_KVALDIR_CREWMAN_4 = 32580
};

Position const ExitPosition[5] =
{
    {2807.858f, 7038.571f, 7.075813f, 4.73481f},
    {2801.168f, 7046.468f, 5.362013f, 4.73481f},
    {2803.729f, 7046.516f, 5.362013f, 4.73481f},
    {2801.480f, 7051.379f, 5.362913f, 4.73481f},
    {2803.319f, 7051.411f, 5.362913f, 4.73481f}
};

struct npc_orabus_the_helmsman_ship_exit_pos : public VehicleAI
{
    npc_orabus_the_helmsman_ship_exit_pos(Creature* creature) : VehicleAI(creature) { }

    void ModifyVehiclePassengerExitPos(Unit* passenger, Vehicle* /*vehicle*/, Position& pos)
    {
        if (passenger->GetTypeId() == TYPEID_UNIT)
        {
            switch (passenger->GetEntry())
            {
                case NPC_ORABUS:
                    pos.Relocate(ExitPosition[0]);
                    break;
                case NPC_KVALDIR_CREWMAN_1:
                    pos.Relocate(ExitPosition[1]);
                    break;
                case NPC_KVALDIR_CREWMAN_2:
                    pos.Relocate(ExitPosition[2]);
                    break;
                case NPC_KVALDIR_CREWMAN_3:
                    pos.Relocate(ExitPosition[3]);
                    break;
                case NPC_KVALDIR_CREWMAN_4:
                    pos.Relocate(ExitPosition[4]);
                    break;
            }
        }
    }
};

/*######
## Quest 11719 A Suitable Test Subject
######*/

// Spell 45997 Bloodspore Ruination
enum BloodsporeRuination
{
    NPC_BLOODMAGE_LAURITH = 25381
};

class spell_q11719_bloodspore_ruination_45997 : public SpellScript
{
    PrepareSpellScript(spell_q11719_bloodspore_ruination_45997);

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

/*######
## Quest 11794: The hunt is on
######*/

// NPCs 25827: Tom Hegger, 25248: Salty John Thorpe, 25828: Guard Mitchells
enum HiddenCultist
{
    SPELL_SHROUD_OF_THE_DEATH_CULTIST = 46077,
    SPELL_RIGHTEOUS_VISION            = 46078,
    QUEST_THE_HUNT_IS_ON              = 11794,
    NPC_TOM_HEGGER                    = 25827,
    NPC_SALTY_JOHN_THORPE             = 25248,
    NPC_GUARD_MITCHELLS               = 25828,
    SAY_HIDDEN_CULTIST_1              = 0,
    SAY_HIDDEN_CULTIST_2              = 1,
    SAY_HIDDEN_CULTIST_3              = 2,
    SAY_HIDDEN_CULTIST_4              = 3,
    EVENT_CULTIST_SCRIPT_1            = 1,
    EVENT_CULTIST_SCRIPT_2            = 2,
    EVENT_CULTIST_SCRIPT_3            = 3
};

struct npc_hidden_cultist : public ScriptedAI
{
    npc_hidden_cultist(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        _emoteState = creature->GetUInt32Value(UNIT_NPC_EMOTESTATE);
        _npcFlags = creature->GetUInt32Value(UNIT_NPC_FLAGS);
    }

    void Initialize()
    {
        _playerGUID.Clear();
    }

    void Reset() override
    {
        if (_emoteState)
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, _emoteState);

        if (_npcFlags)
            me->SetUInt32Value(UNIT_NPC_FLAGS, _npcFlags);

        Initialize();
        DoCast(SPELL_SHROUD_OF_THE_DEATH_CULTIST);
        me->RestoreFaction();
    }

    void DoAction(int32 /*iParam*/) override
    {
        me->StopMoving();
        me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            me->SetFacingToObject(player);
        _events.ScheduleEvent(EVENT_CULTIST_SCRIPT_1, 3s, 3s);
    }

    void AttackPlayer()
    {
        me->SetFaction(FACTION_MONSTER);
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            AttackStart(player);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CULTIST_SCRIPT_1:
                {
                    switch (me->GetEntry())
                    {
                        case NPC_SALTY_JOHN_THORPE:
                            Talk(SAY_HIDDEN_CULTIST_1);
                            _events.ScheduleEvent(EVENT_CULTIST_SCRIPT_2, 5s, 5s);
                            break;
                        case NPC_GUARD_MITCHELLS:
                            Talk(SAY_HIDDEN_CULTIST_2);
                            _events.ScheduleEvent(EVENT_CULTIST_SCRIPT_2, 5s, 5s);
                            break;
                        case NPC_TOM_HEGGER:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                                Talk(SAY_HIDDEN_CULTIST_3, player);
                            _events.ScheduleEvent(EVENT_CULTIST_SCRIPT_2, 5s, 5s);
                            break;
                    }
                    break;
                }
                case EVENT_CULTIST_SCRIPT_2:
                {
                    switch (me->GetEntry())
                    {
                        case NPC_SALTY_JOHN_THORPE:
                            Talk(SAY_HIDDEN_CULTIST_4);
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                                me->SetFacingToObject(player);
                            _events.ScheduleEvent(EVENT_CULTIST_SCRIPT_3, 3s, 3s);
                            break;
                        case NPC_GUARD_MITCHELLS:
                        case NPC_TOM_HEGGER:
                            AttackPlayer();
                            break;
                    }
                    break;
                }
                case EVENT_CULTIST_SCRIPT_3:
                {
                    if (me->GetEntry() == NPC_SALTY_JOHN_THORPE)
                        AttackPlayer();
                    break;
                }
                default:
                    break;
            }
        }
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == 0)
        {
            CloseGossipMenuFor(player);
            _playerGUID = player->GetGUID();
            DoAction(1);
        }
        return false;
    }
    private:
        EventMap   _events;
        ObjectGuid _playerGUID;
        uint32     _emoteState;
        uint32     _npcFlags;
};

/*######
## Quest 11865: Unfit for Death
######*/

// Gameobjects 187982,187995,187996,187997,187998,187999,188000,188001,188002,188003,188004,188005,188006,188007,188008: Caribou Trap
enum CaribouTrap
{
    EVENT_FUR_SPAWN        = 1,
    EVENT_SPAWN_TRAPPER    = 2,
    EVENT_TRAPPER_MOVE     = 3,
    EVENT_TRAPPER_TEXT     = 4,
    EVENT_TRAPPER_LOOT     = 5,
    EVENT_FUR_DESPAWN      = 6,
    EVENT_TRAPPER_DIE      = 7,
    EVENT_DESPAWN_ALL      = 8,
    GO_HIGH_QUALITY_FUR    = 187983,
    NPC_NESINGWARY_TRAPPER = 25835,
    SAY_NESINGWARY_1       = 0,
    SPELL_PLACE_FAKE_FUR   = 46085,
    SPELL_TRAPPED          = 46104
};

struct go_caribou_trap : public GameObjectAI
{
    go_caribou_trap(GameObject* go) : GameObjectAI(go)
    {
        InitializeAI();
    }

    void InitializeAI() override
    {
        _placeFir = false;
        _goFurGUID.Clear();
        _playerGUID.Clear();
        _trapperGUID.Clear();
        me->SetGoState(GO_STATE_READY);
    }

    void Reset() override
    {
        InitializeAI();
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Player* playerCaster = caster->ToPlayer();
        if (!playerCaster)
            return;

        if (spellInfo->Id == SPELL_PLACE_FAKE_FUR)
        {
            _playerGUID = caster->GetGUID();
            _placeFir = true;
            _events.ScheduleEvent(EVENT_FUR_SPAWN, 1s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_placeFir)
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
                    if (TempSummon* trapper = me->SummonCreature(NPC_NESINGWARY_TRAPPER, me->GetPositionX() + (std::cos(me->GetOrientation()) * 21), me->GetPositionY() + (std::sin(me->GetOrientation()) * 21), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 6s))
                    {
                        trapper->SetVisible(false);
                        trapper->SetFacingToObject(me);
                        _trapperGUID = trapper->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_TRAPPER_MOVE, 1s);
                    break;
                case EVENT_TRAPPER_MOVE:
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                    {
                        trapper->GetMotionMaster()->MovePoint(0, trapper->GetPositionX() + (std::cos(trapper->GetOrientation()) * 20), trapper->GetPositionY() + (std::sin(trapper->GetOrientation()) * 20), me->GetPositionZ());
                        trapper->SetVisible(true);
                    }
                    _events.ScheduleEvent(EVENT_TRAPPER_TEXT, 5s);
                    break;
                case EVENT_TRAPPER_TEXT:
                    if (Creature* trapper = ObjectAccessor::GetCreature(*me, _trapperGUID))
                        trapper->AI()->Talk(SAY_NESINGWARY_1);
                    _events.ScheduleEvent(EVENT_TRAPPER_LOOT, 2s);
                    break;
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
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->CastSpell(trapper, SPELL_TRAPPED); // Had to use player cast as go cast is not working. Has no adverse effect to script.
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
    bool _placeFir;
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
    EVENT_FIND_MAMMOTH    = 1,
    EVENT_FACE_PLAYER     = 2,
    EVENT_QUEST_CREDIT    = 3,
    EVENT_MAMMOTH_TEXT    = 4,
    EVENT_MAMMOTH_MOVE    = 5,
    EVENT_MAMMOTH_DESPAWN = 6,
    EVENT_TRAP_RESET      = 7,
    EVENT_MAMMOTH_RESPAWN = 8,
    NPC_TRAPPED_MAMMOTH   = 25850,
    SAY_MAMMOTH           = 0,
    SPELL_SMASH_TRAP      = 46201
};

struct go_mammoth_trap : public GameObjectAI
{
    go_mammoth_trap(GameObject* go) : GameObjectAI(go)
    {
        InitializeAI();
    }

    void InitializeAI() override
    {
        _trapSmashed = true;
        _mammothGUID.Clear();
        _playerGUID.Clear();
        me->SetGoState(GO_STATE_ACTIVE);
        _events.ScheduleEvent(EVENT_FIND_MAMMOTH, 1s);
    }

    void Reset() override
    {
        InitializeAI();
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
                            mammoth->SetFacingToObject(player);
                    _events.ScheduleEvent(EVENT_QUEST_CREDIT, 1s);
                    break;
                case EVENT_QUEST_CREDIT:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                    {
                        mammoth->SetStandState(UNIT_STAND_STATE_STAND);
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->KilledMonsterCredit(mammoth->GetEntry());
                    }
                    _events.ScheduleEvent(EVENT_MAMMOTH_TEXT, 1s);
                    break;
                case EVENT_MAMMOTH_TEXT:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        mammoth->AI()->Talk(SAY_MAMMOTH);
                    _events.ScheduleEvent(EVENT_MAMMOTH_MOVE, 2s);
                    break;
                case EVENT_MAMMOTH_MOVE:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        mammoth->GetMotionMaster()->MovePoint(0, mammoth->GetPositionX() + (std::cos(mammoth->GetOrientation()) * 50), mammoth->GetPositionY() + (std::sin(mammoth->GetOrientation()) * 50), mammoth->GetPositionZ());
                    _events.ScheduleEvent(EVENT_MAMMOTH_DESPAWN, 9s);
                    break;
                case EVENT_MAMMOTH_DESPAWN:
                    if (Creature* mammoth = ObjectAccessor::GetCreature(*me, _mammothGUID))
                        mammoth->DespawnOrUnsummon(0s, 120s);
                    _events.ScheduleEvent(EVENT_MAMMOTH_RESPAWN, 120s);
                    break;
                case EVENT_MAMMOTH_RESPAWN:
                {
                    Creature* mammoth = me->FindNearestCreature(NPC_TRAPPED_MAMMOTH, 1.0f, true);
                    if (mammoth)
                        Reset();
                    else
                        _events.ScheduleEvent(EVENT_MAMMOTH_RESPAWN, 2s);
                }
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    ObjectGuid _playerGUID;
    ObjectGuid _mammothGUID;
    bool _trapSmashed;
};

/*######
## Quest 11919: Drake Hunt "Needs rework"
######*/

// Spell 46620: Red Dragonblood
enum red_dragonblood
{
    SPELL_DRAKE_HATCHLING_SUBDUED = 46691,
    SPELL_SUBDUED                 = 46675
};

class spell_red_dragonblood : public AuraScript
{
    PrepareAuraScript(spell_red_dragonblood);

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
## Quest 12019: Last Rites
######*/

// NPC 26170: Thassarian
enum Thassarian
{
    EVENT_THASSARIAN_SCRIPT_1  = 1,
    EVENT_THASSARIAN_SCRIPT_2  = 2,
    EVENT_THASSARIAN_SCRIPT_3  = 3,
    EVENT_THASSARIAN_SCRIPT_4  = 4,
    EVENT_THASSARIAN_SCRIPT_5  = 5,
    EVENT_THASSARIAN_SCRIPT_6  = 6,
    EVENT_THASSARIAN_SCRIPT_7  = 7,
    EVENT_THASSARIAN_SCRIPT_8  = 8,
    EVENT_THASSARIAN_SCRIPT_9  = 9,
    EVENT_THASSARIAN_SCRIPT_10 = 10,
    EVENT_THASSARIAN_SCRIPT_11 = 11,
    EVENT_THASSARIAN_SCRIPT_12 = 12,
    EVENT_THASSARIAN_SCRIPT_13 = 13,
    EVENT_THASSARIAN_SCRIPT_14 = 14,
    EVENT_THASSARIAN_SCRIPT_15 = 15,
    EVENT_THASSARIAN_SCRIPT_16 = 16,
    EVENT_THASSARIAN_SCRIPT_17 = 17,
    EVENT_THASSARIAN_SCRIPT_18 = 18,
    EVENT_THASSARIAN_SCRIPT_19 = 19,
    EVENT_THASSARIAN_SCRIPT_20 = 20,
    EVENT_THASSARIAN_SCRIPT_21 = 21,
    EVENT_THASSARIAN_SCRIPT_22 = 22,
    EVENT_THASSARIAN_SCRIPT_23 = 23,
    EVENT_THASSARIAN_SCRIPT_24 = 24,
    EVENT_THASSARIAN_SCRIPT_25 = 25,
    EVENT_THASSARIAN_SCRIPT_26 = 26,
    EVENT_THASSARIAN_SCRIPT_27 = 27,
    EVENT_THASSARIAN_SCRIPT_28 = 28,
    EVENT_THASSARIAN_SCRIPT_29 = 29,
    FACTION_VALANAR_COMBAT     = 1988,
    NPC_IMAGE_LICH_KING        = 26203,
    NPC_COUNSELOR_TALBOT       = 25301,
    NPC_PRINCE_VALANAR         = 28189,
    NPC_GENERAL_ARLOS          = 25250,
    NPC_LERYSSA                = 25251,
    SPELL_TRANSFORM_VALANAR    = 46753,
    SPELL_STUN                 = 46957,
    SAY_THASSARIAN_1           = 0,
    SAY_THASSARIAN_2           = 1,
    SAY_THASSARIAN_3           = 2,
    SAY_THASSARIAN_4           = 3,
    SAY_THASSARIAN_5           = 4,
    SAY_THASSARIAN_6           = 5,
    SAY_THASSARIAN_7           = 6,
    SAY_TALBOT_1               = 0,
    SAY_TALBOT_2               = 1,
    SAY_TALBOT_3               = 2,
    SAY_TALBOT_4               = 3,
    SAY_LICH_1                 = 0,
    SAY_LICH_2                 = 1,
    SAY_LICH_3                 = 2,
    SAY_ARLOS_1                = 0,
    SAY_ARLOS_2                = 1,
    SAY_LERYSSA_1              = 0,
    SAY_LERYSSA_2              = 1,
    SAY_LERYSSA_3              = 2,
    SAY_LERYSSA_4              = 3,
    PATH_THASSARIAN            = 1013030,
    PATH_ARTHAS                = 1013031,
    PATH_TALBOT                = 1013032,
    PATH_ARLOS                 = 1013033,
    PATH_LERYSSA               = 1013034
};

struct npc_thassarian : public CreatureAI
{
    npc_thassarian(Creature* creature) : CreatureAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _arthasGUID.Clear();
        _talbotGUID.Clear();
        _leryssaGUID.Clear();
        _arlosGUID.Clear();

        _arlosInPosition   = false;
        _leryssaInPosition = false;
        _preFightComplete  = false;
        _talbotJustDied    = false;
    }

    void Reset() override
    {
        me->RestoreFaction();
        me->RemoveStandFlags(UNIT_STAND_STATE_SIT);
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        Initialize();
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        switch (waypointId)
        {
            case 3:
                me->SetWalk(false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_1, 2s);
                break;
            }
    }

    void UpdateAI(uint32 diff) override
    {
        if (_arlosInPosition && _leryssaInPosition)
        {
            _arlosInPosition = false;
            _leryssaInPosition = false;
            _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_8, 1s);
        }

        if (_talbotJustDied && _preFightComplete)
        {
            _talbotJustDied = false;
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
                        arthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        arthas->SetReactState(REACT_PASSIVE);
                        arthas->SetWalk(true);
                    }
                    if (Creature* talbot = me->SummonCreature(NPC_COUNSELOR_TALBOT, 3748.7627f, 3614.0374f, 473.4048f, 4.5553f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _talbotGUID = talbot->GetGUID();
                        talbot->SetWalk(true);
                        _talbotJustDied = false;
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
                        talbot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        talbot->SetReactState(REACT_PASSIVE);
                        talbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_5, 7s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_5:
                    // Talbot say text 1
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
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
                        arlos->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        arlos->GetMotionMaster()->MovePath(PATH_ARLOS, false);
                    }
                    if (Creature* leryssa = me->SummonCreature(NPC_LERYSSA, 3751.0986f, 3614.9219f, 473.4048f, 4.5029f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2min))
                    {
                        _leryssaGUID = leryssa->GetGUID();
                        leryssa->SetWalk(true);
                        leryssa->SetReactState(REACT_PASSIVE);
                        leryssa->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        leryssa->GetMotionMaster()->MovePath(PATH_LERYSSA, false);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_7, 7s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_7:
                    // Talbot say text 2
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
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
                        talbot->AI()->Talk(SAY_TALBOT_3);
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_14, 5s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_14:
                    // Arthas turn to Talbot say text 3
                    if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                    {
                        if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                            arthas->SetFacingToObject(talbot);
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
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
                    {
                        talbot->AI()->Talk(SAY_TALBOT_4);
                        talbot->SetFaction(FACTION_VALANAR_COMBAT);
                        talbot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        talbot->SetReactState(REACT_AGGRESSIVE);
                        talbot->Attack(me, false);
                        _preFightComplete = true;
                    }
                    break;
                case EVENT_THASSARIAN_SCRIPT_18:
                    // Arlos say text 1
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    if (Creature* arlos = ObjectAccessor::GetCreature(*me, _arlosGUID))
                    {
                        arlos->AI()->Talk(SAY_ARLOS_1);
                        arlos->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                        arlos->SetStandState(UNIT_STAND_STATE_KNEEL);
                        arlos->RemoveAura(SPELL_STUN);
                    }
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
                        leryssa->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                        leryssa->RemoveAura(SPELL_STUN);
                    }
                    _events.ScheduleEvent(EVENT_THASSARIAN_SCRIPT_19, 3s);
                    break;
                case EVENT_THASSARIAN_SCRIPT_19:
                    // Leryssa set facing to me
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
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
                        arlos->AI()->Talk(SAY_ARLOS_2);
                        arlos->SetStandState(UNIT_STAND_STATE_DEAD);
                    }
                    if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
                    {
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

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Cleanup();
    }

    void Cleanup()
    {
        if (Creature* talbot = ObjectAccessor::GetCreature(*me, _talbotGUID))
            talbot->RemoveFromWorld();

        if (Creature* leryssa = ObjectAccessor::GetCreature(*me, _leryssaGUID))
            leryssa->RemoveFromWorld();

        if (Creature* arlos = ObjectAccessor::GetCreature(*me, _arlosGUID))
            arlos->RemoveFromWorld();

        if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
            arthas->RemoveFromWorld();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == 0)
        {
            _playerGUID = player->GetGUID();
            CloseGossipMenuFor(player);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
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
        bool _preFightComplete;
    public:
        bool _arlosInPosition;
        bool _leryssaInPosition;
        bool _talbotJustDied;
};

// NPC 25250: General Arlos
struct npc_general_arlos : public ScriptedAI
{
    npc_general_arlos(Creature* creature) : ScriptedAI(creature) { }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        if (waypointId == 3)
        {
            me->AddUnitState(UNIT_STATE_STUNNED);
            DoCastSelf(SPELL_STUN);
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian, summoner->ToCreature()->AI())->_arlosInPosition = true;
        }
    }
};

// NPC 25251: Leryssa
struct npc_leryssa : public ScriptedAI
{
    npc_leryssa(Creature* creature) : ScriptedAI(creature) {}

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        if (waypointId == 3)
        {
            me->SetOrientation(4.537856f);
            me->AddUnitState(UNIT_STATE_STUNNED);
            DoCastSelf(SPELL_STUN);
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian, summoner->GetAI())->_leryssaInPosition = true;
        }
    }
};

// NPC 25301: Counselor Talbot
enum CounselorTalbot
{
    AREA_LAST_RITES     = 4128,
    SPELL_DEFLECTION    = 51009,
    SPELL_SOUL_BLAST    = 50992,
    SPELL_VAMPIRIC_BOLT = 51016,
    EVENT_DEFLECTION    = 1,
    EVENT_SOUL_BLAST    = 2,
    EVENT_VAMPIRIC_BOLT = 3
};

struct npc_counselor_talbot : public ScriptedAI
{
    npc_counselor_talbot(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override {}

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
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->IsSummon())
            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                ENSURE_AI(npc_thassarian, summoner->GetAI())->_talbotJustDied = true;
    }
    private:
        EventMap _events;
};

/*######
## Spell 46374 Windsoul Totem Aura "To test No idea what quest this is for"
######*/

enum WindsoulTotemAura
{
    SPELL_WINDSOUL_CREDIT = 46378
};

class spell_windsoul_totem_aura : public AuraScript
{
    PrepareAuraScript(spell_windsoul_totem_aura);

    void OnRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        if (GetTarget()->isDead())
            if (Unit* caster = GetCaster())
                caster->CastSpell(nullptr, SPELL_WINDSOUL_CREDIT);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_windsoul_totem_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/*######
## npc_bloodmage_laurith "To test No idea what this is for"
######*/

enum BloodmageLaurith
{
    SAY_BLOODMAGE_LAURITH   = 0,
    EVENT_TALK              = 1,
    EVENT_RESET_ORIENTATION = 2
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
        {
            DoMeleeAttackIfReady();
            return;
        }

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

/*######
## Valiance Keep Cannoneer script to activate cannons "TESTED NOT WORKING"
######*/

enum Valiancekeepcannons
{
    GO_VALIANCE_KEEP_CANNON_1 = 187560,
    GO_VALIANCE_KEEP_CANNON_2 = 188692,
    EVENT_SHOOT               = 1
};

struct npc_valiance_keep_cannoneer : public ScriptedAI
{
    npc_valiance_keep_cannoneer(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        GameObject* pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_1, 10.0f);
        if (!pCannon)
            pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_2, 10.0f);

        if (pCannon)
        {
            pCannon->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            pCannon->SetGoState(GO_STATE_READY);
            _goCannonGUID = pCannon->GetGUID();
            _events.ScheduleEvent(EVENT_SHOOT, 13s, 18s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (UpdateVictim())
        {
            DoMeleeAttackIfReady();
            return;
        }

        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHOOT:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                    if (GameObject* pCannon = ObjectAccessor::GetGameObject(*me, _goCannonGUID))
                        pCannon->Use(me);
                    _events.ScheduleEvent(EVENT_SHOOT, 13s, 18s);
                    break;
                default:
                    break;
            }
        }
    }
    private:
        EventMap _events;
        ObjectGuid _goCannonGUID;
};

void AddSC_borean_tundra()
{
    RegisterCreatureAI(npc_beryl_sorcerer);
    RegisterCreatureAI(npc_captured_beryl_sorcerer);
    RegisterSpellScript(spell_arcane_chains_character_force_cast);
    RegisterSpellScript(spell_nerubar_web_random_unit_not_on_quest);
    RegisterSpellScript(spell_nerubar_web_random_unit_not_on_quest_dummy);
    RegisterSpellScript(spell_nerubar_web_random_unit_on_quest_dummy);
    RegisterSpellScript(spell_dispel_freed_soldier_debuff);
    RegisterSpellScript(spell_q11653_shortening_blaster);
    RegisterCreatureAI(npc_imprisoned_beryl_sorcerer);
    RegisterCreatureAI(npc_orabus_the_helmsman_ship_exit_pos);
    RegisterSpellScript(spell_q11719_bloodspore_ruination_45997);
    RegisterCreatureAI(npc_hidden_cultist);
    RegisterGameObjectAI(go_caribou_trap);
    RegisterGameObjectAI(go_mammoth_trap);
    RegisterSpellScript(spell_red_dragonblood);
    RegisterCreatureAI(npc_thassarian);
    RegisterCreatureAI(npc_general_arlos);
    RegisterCreatureAI(npc_leryssa);
    RegisterCreatureAI(npc_counselor_talbot);
    RegisterSpellScript(spell_windsoul_totem_aura);
    RegisterCreatureAI(npc_bloodmage_laurith);
    RegisterCreatureAI(npc_valiance_keep_cannoneer);
}
