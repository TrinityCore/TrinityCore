/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Chat.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptHelpers.h"
#include "SpellInfo.h"

#include "Followship_bots.h"
#include "Followship_bots_ai_base.h"
#include "Followship_bots_mgr.h"

#include "Followship_bots_auras_handler.h"
#include "Followship_bots_config.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_chatter_handler.h"
#include "Followship_bots_combat_handler.h"

#include "Followship_bots_db.h"

#include "GenAI_chatter_prompts.h"
#include "Followship_bots_death_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_gossip_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_incombat_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_outofcombat_handler.h"
#include "Followship_bots_pet_handler.h"
#include "Followship_bots_powers_handler.h"
#include "Followship_bots_recovery_handler.h"
#include "Followship_bots_regen_handler.h"
#include "Followship_bots_spells_handler.h"
#include "Followship_bots_stats_handler.h"
#include "Followship_bots_party_handler.h"
#include "Followship_bots_teleport_handler.h"
#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_warsong_gulch.h"



class npc_followship_bots : public CreatureScript
{
public:
    npc_followship_bots() : CreatureScript("npc_followship_bots") { }

    struct npc_followship_botsAI : public FSB_BaseAI
    {
        npc_followship_botsAI(Creature* creature) : FSB_BaseAI(creature), _summons(creature)
        {
            // Runs once when creature is spawned
            static bool tablesInitialized = false;
            if (!tablesInitialized)
            {
                FSBSpells::InitBotSpellTables();
                tablesInitialized = true;
            }

            FSBSpells::InitSpellRuntime(me, botRuntimeSpells);
        }        

        bool updateFollowInfo = false;

        void InitializeAI() override // Runs once after creature is spawned and AI not loaded
        {
            ScriptedAI::InitializeAI(); // always call base first            
        }

        void OnDespawn() override
        {
            if (me && me->GetMap() && me->GetMap()->IsBattlegroundOrArena())
            {
                if (me->GetMap()->IsBattleground())
                    FSBBattleground::RespawnBotOnDespawn(me);
                ScriptHelpers::EraseBotScore(me->GetGUID());
                ScriptHelpers::EraseBotRace(me->GetGUID());
            }
        }

        void Reset() override // Runs at creature respawn, evade or when triggered
        {
            if (FollowshipBotsConfig::configFSBEnabled)
            {
                events.Reset();

                FSBMgr::Get()->SetInitialBotState(me);

                TC_LOG_DEBUG("scripts.fsb.general", "FSB: Reset() triggered for bot: {}", me->GetName());

                // Schedule Generic Events
                FSBEvents::ScheduleBotEvent(me, FSB_EVENT_GENERIC_MAINTENANCE, 1s);

                // Periodic events happen as long as the bot exists in the world
                events.ScheduleEvent(FSB_EVENT_PERIODIC_MAINTENANCE, 1s);
                // Hire events happen when bot is hired (on duty)
                events.ScheduleEvent(FSB_EVENT_HIRED_MAINTENANCE, 1s);
                // Combat events happen when bot is in combat
                events.ScheduleEvent(FSB_EVENT_COMBAT_MAINTENANCE, 1s);

                if (FollowshipBotsConfig::configFSBUseCustomRegen)
                {
                    botRegenMods = FSBRegenMods(); // zero

                    // Disable npc flags if any in DB
                    me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
                    me->SetRegenerateHealth(false); // no health regen

                    //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Reset() Using Custom Regen for bot: {}", me->GetName());
                }
                else
                {
                    me->SetUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
                    me->SetRegenerateHealth(true);  // restore normal regen
                }

            }

            else
            {
                // Completely disable gossip
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            }            
        }

        // Runs once when creature is summoned by another unit
        // This only works if creature is spawned by summon (NOT DB spawn)
        void IsSummonedBy(WorldObject* /*summoner*/) override
        {
            TC_LOG_DEBUG("scripts.fsb.general", "FSB: IsSummonedBy() triggered for bot: {}", me->GetName());
        }

        void JustAppeared() override // Runs once when creature appeared in world, works for DB spawns
        {
            TC_LOG_DEBUG("scripts.fsb.general", "FSB: JustAppeared() triggered for bot: {}", me->GetName());
            FSBChatMgr::Get()->RegisterActiveBot(me);
            FSBChatMgr::Get()->JoinBotChannels(me);
        }

        bool OnGossipHello(Player* player) override // Runs once when opening creature gossip
        {
            return FSBGossip::HandleDefaultGossipHello(me, player, botHired, _playerGuid);
        }

        bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override // Runs once when gossip item selected
        {
            return FSBGossip::HandleGossipSelect(me, player->GetGUID(), menuId, gossipListId);
        }

        void JustEngagedWith(Unit* who) override // Runs every time creature gets in combat
        {
            if(!botHired)
                FSBChat::StartBotRandomChat(me, FSBChat::ChatChannelType::CombatDefense, who);

            TC_LOG_DEBUG("scripts.fsb.general", "FSB: JustEngagedWith() triggered for bot: {}", me->GetName());
        }

        void JustEnteredCombat(Unit* who) override
        {
            FSBCombat::BotSyncShapeshift(me, true);

            for (ObjectGuid const& guid : _summons)
                if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
                    if (summon->IsAlive())
                        summon->EngageWithTarget(who);
        }

        void JustExitedCombat() override
        {
            botOutOfCombatTimer = getMSTime();

            FSBCombat::BotSyncShapeshift(me, false);

            botGenericData.manaPotionUsed = false;
            botGenericData.healthPotionUsed = false;

            if (!botHired)
            {
                if (me->GetMap()->IsBattleground())
                {
                    if (me->HasUnitState(UNIT_STATE_CHASE))
                        me->GetMotionMaster()->Clear();

                    if (FSB_BattlegroundData* bgData = GetBattlegroundData())
                    {
                        // setDeathState calls CombatStop before JustDied, so we must not clear the tap list when the bot is dying.
                        if (me->IsAlive())
                            bgData->damageTappers.clear();
                        // recentPlayerTargets is also needed by OnPlayerKilledByCreature, which runs after death triggers CombatStop.
                    }
                }
            }
        }        

        void HealReceived(Unit* /*done_by*/, uint32& /*addhealth*/) override
        {
        }

        int32 GetBotSpellPower() const override
        {
            TC_LOG_DEBUG("scripts.fsb.general", "FSB: GetBotSpellPower() triggered for bot: {}", me->GetName());

            return FSBStats::BotGetSpellPower(me);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            damage = uint32(damage * FSBStats::ApplyBotDamageDoneReduction(me));
            FSBPowers::GenerateRageFromDamageDone(me, damage);

            if (me->GetMap()->IsBattlegroundOrArena())
            {
                ScriptHelpers::RecordBotDamageDone(me->GetGUID(), damage);

                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    if (FSB_BattlegroundData* bgData = GetBattlegroundData())
                        bgData->recentPlayerTargets.insert(victim->GetGUID());
            }
        }

        // Runs every time creature takes damage
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            damage = uint32(damage * FSBStats::ApplyBotDamageTakenReduction(me));
            FSBPowers::GenerateRageFromDamageTaken(me, damage);

            FSBBattleground::HandleBotDamageTaken(me, attacker, damage);
        }

        void HealDone(Unit* /*done_to*/, uint32& addhealth) override
        {
            if (me->GetMap()->IsBattlegroundOrArena())
                ScriptHelpers::RecordBotHealingDone(me->GetGUID(), addhealth);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override // Runs every time creature evades
        {

        }

        void KilledUnit(Unit* victim) override // Runs every time the creature kills an unit
        {
            if (!victim)
                return;

            if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                FSBGenAIPrompts::DispatchBotTargetKilled(me, victim->GetGUID());

            if (me->GetMap()->IsBattlegroundOrArena())
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    FSBBattleground::HandleBotKilledPlayer(me, victim->GetGUID());

                ScriptHelpers::RecordBotKillingBlow(me->GetGUID());
            }
        }

        void OnSpellCast(SpellInfo const* spell) override // Runs every time the creature casts a spell
        {
            uint32 spellId = spell->Id;

            FSBSpells::HandleOnSpellCast(me, botClass, spellId);
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (!spellInfo)
                return;

            FSBDeath::HandleSpellResurrection(me, spellInfo->Id);
        }

        void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
        {
            TC_LOG_DEBUG("scripts.fsb.general", "FSB: SpellHitTarget() triggered for bot: {} with target {} and Spell {}", me->GetName(), target->GetName(), spellInfo->Id);

            Player* player = target->ToPlayer();

            if (spellInfo->Id == 461537 && player && !player->IsAlive() && player->GetGUID() == me->GetOwnerGUID())
                player->ResurrectPlayer(0.35f, false);
        }

        void OnAuraApplied(AuraApplication const* aurApp) override
        {
            if (!aurApp)
                return;

            FSBAuras::BotOnAuraApplied(me, aurApp, true, botRegenMods, botHasSoulstone, botStats);
        }

        void OnAuraRemoved(AuraApplication const* aurApp) override
        {
            if (!aurApp)
                return;

            FSBAuras::BotOnAuraApplied(me, aurApp, false, botRegenMods, botHasSoulstone, botStats);
        }

        void JustSummoned(Creature* summon) override // Runs every time the creature summons another creature
        {
            if (summon)
            {
                summon->ApplyLevelScaling(3325, 0);
                summon->SetLevel(me->GetLevel());

                if (botClass == FSB_Class::Warlock)
                {
                    FSBWarlock::AdjustSummonHealth(me, summon);
                    botHasDemon = true;
                    TC_LOG_DEBUG("scripts.fsb.general", "FSB: JustSummoned Triggered for Warlock bot {} with summon {}", me->GetName(), summon->GetName());
                }

                _summons.Summon(summon);
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override // Runs everytime the creature's summon dies - pet or minion
        {
            if (summon && botClass == FSB_Class::Warlock)
            {
                botHasDemon = false;
                TC_LOG_DEBUG("scripts.fsb.general", "FSB: SummonedCreatureDies Triggered for Warlock bot {} with summon {}", me->GetName(), summon->GetName());
            }

            if(summon)
                _summons.Despawn(summon);
        }

        void JustDied(Unit* killer) override // Runs once when creature dies
        {
            botCorpsePos = me->GetPosition();
            FSBChatMgr::Get()->UnregisterActiveBot(me);
            FSBChatMgr::Get()->LeaveBotChannels(me);
            FSBDeath::HandlerJustDied(me, killer);

            FSBBattleground::HandleBotDeathScores(me, killer);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == EFFECT_MOTION_TYPE)
            {
                FSBMovement::HandleBattlegroundMovement(me, type, id);
                return;
            }

            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
            case FSBMovement::MOVEMENT_POINT_CORPSE:
            {
                FSBDeath::BotSetStateAfterCorpseRevive(me);
                break;
            }

            case FSBMovement::MOVEMENT_POINT_NEAR_FIRE:
            {
                FSBEvents::ScheduleBotEvent(me, FSB_EVENT_RANDOM_ACTION_SIT_BY_FIRE, 1s, 3s);
                break;
            }

            default:
            {
                if (FSBMovement::IsWsgMovementPoint(id))
                    FSBMovement::HandleBattlegroundMovement(me, type, id);
                break;
            }
            }
        }

        uint32 GetData(uint32 /*type*/) const override // Runs once to check what data exists on the creature
        {
            return 0;
        }

        void SetData(uint32 type, uint32 value) override // Runs once to check set data is SET on the creature
        {
            switch (type)
            {
            case FSB_DATA_HIRED:
            {
                botHired = value;
                TC_LOG_DEBUG("scripts.fsb.general", "FSB: SetData FSB_DATA_HIRED for bot {} with hired value {}", me->GetName(), botHired);

                break;
            }

            case FSB_DATA_HIRE_TIME_LEFT:
            {
                hireTimeLeft = value;

                if (hireTimeLeft > 0)
                {
                    FSBEvents::ScheduleBotEvent(me, FSB_EVENT_HIRED_EXPIRED, std::chrono::seconds(hireTimeLeft));
                    TC_LOG_DEBUG("scripts.fsb.general", "FSB: SetData FSB_DATA_HIRE_TIME_LEFT for bot {} with hireTimeLeft value {}", me->GetName(), hireTimeLeft);
                }
                
                FSBMovement::ResumeFollow(me, botFollowDistance, botFollowAngle);
                TC_LOG_DEBUG("scripts.fsb.general", "FSB: SetData FSB_DATA_HIRE_TIME_LEFT for bot {} with permanent hire.", me->GetName());

                break;
            }

            case ScriptHelpers::DATA_BOT_CAPTURED_FLAG:
                if(!botHired)
                    FSBBattleground::WarsongGulch::OnBotCapturedFlag(me);
                break;

            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case FSB_ACTION_WAIT_HEALER_RESSURECT:
                events.ScheduleEvent(FSB_EVENT_HIRED_WAIT_HEALER_RESSURECT, 90s);
                break;

            case FSB_ACTION_SOULSTONE_RESSURECT:
                events.ScheduleEvent(FSB_EVENT_SOULSTONE_RESSURECT, 4s, 6s);
                break;

            case FSB_ACTION_TELEPORT_DUNGEON:
                events.ScheduleEvent(FSB_EVENT_HIRED_TELEPORT_DUNGEON, 5s, 6s);
                break;
            
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!botDungeonData || !botDungeonData->mechanicFlagC)
                FSBCombat::EvaluateAttackNeeded(me);

            FSBCombat::SetOwnerTapToVictim(me);

            events.Update(diff);
            botEvents.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                // =================================================== //
                // ========= PERIODIC MAINTENANCE ==================== //
                // Events that are triggered periodically              //
                // These events can trigger even when bot is NOT hired //
                // =================================================== //

                case FSB_EVENT_PERIODIC_MAINTENANCE:
                {
                    // bot events
                    FSBEvents::ScheduleBotEvent(me, FSB_EVENT_GENERIC_CHECK_HIRED_TIME, 10s);
                    if(!botHired)
                        FSBEvents::ScheduleBotEvent(me, FSB_EVENT_DESPAWN_TEMP_BOT, 1s);

                    uint32 now = getMSTime();

                    // Check if custom regen is enabled and we can schedule every 2s
                    if (FollowshipBotsConfig::configFSBUseCustomRegen && now >= _nextRegenMs && !me->HasAura(SPELL_SPECIAL_GHOST))
                    {
                        if (me->GetHealthPct() < 100 || me->GetPowerPct(me->GetPowerType()) < 100)
                        {
                            FSBRegen::ProcessBotCustomRegenTick(me, botClass, botRegenMods);

                            // ? lock regen for next 2 seconds
                            _nextRegenMs = now + 2000;

                        }
                    }

                    // Check if combat is NOT taking place and schedule OOC actions
                    if (!FSBCombatUtils::IsCombatActive(me))
                    {
                        if (FollowshipBotsConfig::configFSBUseOOCActions && now >= _1secondsCheckMs && !me->HasAura(SPELL_SPECIAL_GHOST))
                        {
                            FSBOOC::BotOOCActions(me);
                            _1secondsCheckMs = now + 1000;
                        }
                    }

                    FSBParty::PeriodicPartyNeededCheck(me);

                    if (me->GetMap()->IsBattleground())
                    {
                        uint32 nowMs = getMSTime();
                        if (nowMs >= _bgRaidUpdateMs)
                        {
                            _bgRaidUpdateMs = nowMs + 10000;
                            FSBParty::PeriodicBattlegroundRaidUpdate(me);
                        }
                    }

                    FSBChatMgr::Get()->UpdateBotChannels(me);

                    events.ScheduleEvent(FSB_EVENT_PERIODIC_MAINTENANCE, 1s);

                    break;
                }

                // =====================================
                // =====================================
                // =================================================== //
                // ========= HIRED MAINTENANCE ======================= //
                // Important polls that are needed when bot is hired   //
                // (on duty)                                           //
                // =================================================== //
                    
                case FSB_EVENT_HIRED_MAINTENANCE:
                {
                    if (botHired)
                    {
                        uint32 now = getMSTime();

                        events.ScheduleEvent(FSB_EVENT_HIRED_CHECK_TELEPORT, 3s, 5s);
                        events.ScheduleEvent(FSB_EVENT_HIRED_CHECK_MOUNT, 3s, 5s);
                        FSBEvents::ScheduleBotEvent(me, FSB_EVENT_HIRED_DESPAWN_TEMP_BOT, 1s);

                        FSBDungeon::CheckDungeonHandlingNeeded(me);

                        if (now >= _5secondsCheckMs)
                        {
                            FSBStats::UpdateBotLevelToPlayer(me);

                            FSBGroup::BuildLogicalBotGroup(me, botLogicalGroup);

                            _5secondsCheckMs = now + 5000;
                        }
                    }

                    events.ScheduleEvent(FSB_EVENT_HIRED_MAINTENANCE, 1s);
                    break;
                }

                    // Check if player is too far (teleport) and bring bot
                case FSB_EVENT_HIRED_CHECK_TELEPORT:
                {
                    if(botMoveState != FSB_MOVE_STATE_STAY || !me->HasAura(SPELL_SPECIAL_GHOST))
                        FSBTeleport::BotTeleport(me, BOT_TOO_FAR);

                    if (FSBPet::BotHasPet(me))
                        FSBTeleport::BotPetTeleport(me);

                    break;
                }

                case FSB_EVENT_HIRED_WAIT_HEALER_RESSURECT:
                    if (me->GetMap()->IsDungeon())
                    {
                        events.ScheduleEvent(FSB_EVENT_HIRED_TELEPORT_DUNGEON, 4s, 6s);
                    } else
                        FSBEvents::ScheduleBotEvent(me, FSB_EVENT_GENERIC_TELEPORT_GRAVEYARD, 4s, 6s);
                    break;

                case FSB_EVENT_HIRED_TELEPORT_DUNGEON:
                    FSBTeleport::BotTeleport(me, BOT_DEATH);
                    events.ScheduleEvent(FSB_EVENT_HIRED_DUNGEON_RESSURECT, 1s);
                    break;

                case FSB_EVENT_HIRED_DUNGEON_RESSURECT:
                    FSBDeath::HandleDeathInDungeon(me, botFollowDistance, botFollowAngle);
                    break;

                    // Check if Bot needs to mount or dismount
                case FSB_EVENT_HIRED_CHECK_MOUNT:
                    FSBMovement::BotSetMountedState(me, botMounted);
                    break;

                // =================================================== //
                // ========= COMBAT MAINTENANCE ====================== //
                // Events that are checked during combat               //
                // =================================================== //
                    
                case FSB_EVENT_COMBAT_MAINTENANCE:
                {
                    if (me->IsAlive() && me->IsInCombat())
                        if (!botDungeonData || !botDungeonData->mechanicFlagD)
                            FSBIC::BotICActions(me, botGlobalCooldown, botCastedCombatBuffs);

                    if (botClass == FSB_Class::Hunter && FSBPet::BotHasPet(me))
                        FSBPet::DoAttackSpell(me);

                    events.ScheduleEvent(FSB_EVENT_COMBAT_MAINTENANCE, 1s);

                    break;
                }

                // =================================================== //
                // ========= TIMED ACTION EVENTS ===================== //
                // Events that are needed for actions                  //
                // =================================================== //   

                case FSB_EVENT_SOULSTONE_RESSURECT:
                    FSBDeath::HandleDeathWithSoulstone(me, botHasSoulstone);
                    break;

                case FSB_EVENT_GRAVEYARD_RESSURECT:
                    FSBDeath::HandleDeathWithGraveyard(me, botCorpsePos);
                    break;

                default:
                    break;
                }
            }

            while (uint32 eventId = botEvents.ExecuteEvent())
            {
                HandleBotEvent(this, eventId);
            }

            PollPendingGenAIResponse();
        }
        
        private:
            EventMap events;
            ObjectGuid _playerGuid;
            SummonList _summons;


            uint32 hireTimeLeft = 0;

            // Bot Stats
            uint32 _nextRegenMs = 0;

            // ----------
            // Combat
            ObjectGuid _lastOwnerVictim;

            uint32 _5secondsCheckMs = 0;
            uint32 _1secondsCheckMs = 0;
            uint32 _bgRaidUpdateMs = 0;
    };

    

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_followship_botsAI(creature);
    }
};


void AddSC_followship_bots()
{
    FollowshipBotsConfig::Load();
    FSBMgr::Get()->LoadBotTemplates();
    FSBMgr::Get()->LoadAllPersistentBots();
    FSBUtilsDB::LoadBotChatterLines(FSBChatter::BotChatterLinesMap);
    FSBSpells::InitBotSpellTables();
    FSBSpellsDB::LoadBotSpellsFromDB();

    new npc_followship_bots();
}
