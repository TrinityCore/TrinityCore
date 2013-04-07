/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"
#include "Vehicle.h"
#include "Player.h"

/* ScriptData
SDName: boss_kologarn
SD%Complete: 90
SDComment: @todo Achievements
SDCategory: Ulduar
EndScriptData */

// Maybe I will spent those manually...
enum Achiev
{
    ACHIEVEMENT_RUBBLE_AND_ROLL_10   = 2959,
    ACHIEVEMENT_RUBBLE_AND_ROLL_25   = 2960,
    ACHIEVEMENT_DISARMED_10          = 2953,
    ACHIEVEMENT_DISARMED_25          = 2954,
    ACHIEVEMENT_WITH_OPEN_ARMS_10    = 2951,
    ACHIEVEMENT_WITH_OPEN_ARMS_25    = 2952
};

enum KologarnSpells
{
    SPELL_ARM_DEAD_DAMAGE_10            = 63629,
    SPELL_ARM_DEAD_DAMAGE_25            = 63979,
    SPELL_TWO_ARM_SMASH_10              = 63356,
    SPELL_TWO_ARM_SMASH_25              = 64003,
    SPELL_ONE_ARM_SMASH_10              = 63573,
    SPELL_ONE_ARM_SMASH_25              = 64006,
    SPELL_ARM_SWEEP_10                  = 63766,
    SPELL_ARM_SWEEP_25                  = 63983,
    SPELL_STONE_SHOUT_10                = 63716,
    SPELL_STONE_SHOUT_25                = 64005,
    SPELL_PETRIFY_BREATH_10             = 62030,
    SPELL_PETRIFY_BREATH_25             = 63980,
    SPELL_STONE_GRIP_10                 = 62166,
    SPELL_STONE_GRIP_25                 = 63981,
    SPELL_STONE_GRIP_DOT_10             = 64290,
    SPELL_STONE_GRIP_DOT_25             = 64292,
    SPELL_STONE_GRIP_CANCEL             = 65594,
    SPELL_SUMMON_RUBBLE                 = 63633,
    SPELL_FALLING_RUBBLE                = 63821,
    SPELL_ARM_ENTER_VEHICLE             = 65343,
    SPELL_ARM_ENTER_VISUAL              = 64753,
    SPELL_FOCUSED_EYEBEAM_PERIODIC_10   = 63347,
    SPELL_FOCUSED_EYEBEAM_PERIODIC_25   = 63977,
    SPELL_SUMMON_FOCUSED_EYEBEAM        = 63342,
    SPELL_FOCUSED_EYEBEAM_VISUAL        = 63369,
    SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT   = 63676,
    SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT  = 63702,
       // Passive
    SPELL_KOLOGARN_REDUCE_PARRY         = 64651,
    SPELL_KOLOGARN_PACIFY               = 63726,
    SPELL_KOLOGARN_UNK_0                = 65219,   // Not found in DBC

    SPELL_BERSERK                       = 47008    // guess
};

#define SPELL_ARM_DEAD_DAMAGE           RAID_MODE(SPELL_ARM_DEAD_DAMAGE_10, SPELL_ARM_DEAD_DAMAGE_25)
#define SPELL_TWO_ARM_SMASH             RAID_MODE(SPELL_TWO_ARM_SMASH_10, SPELL_TWO_ARM_SMASH_25)
#define SPELL_ONE_ARM_SMASH             RAID_MODE(SPELL_ONE_ARM_SMASH_10, SPELL_ONE_ARM_SMASH_25)
#define SPELL_ARM_SWEEP                 RAID_MODE(SPELL_ARM_SWEEP_10, SPELL_ARM_SWEEP_25)
#define SPELL_STONE_SHOUT               RAID_MODE(SPELL_STONE_SHOUT_10, SPELL_STONE_SHOUT_25)
#define SPELL_PETRIFY_BREATH            RAID_MODE(SPELL_PETRIFY_BREATH_10, SPELL_PETRIFY_BREATH_25)
#define SPELL_STONE_GRIP                RAID_MODE(SPELL_STONE_GRIP_10, SPELL_STONE_GRIP_25)
#define SPELL_FOCUSED_EYEBEAM_PERIODIC  RAID_MODE(SPELL_FOCUSED_EYEBEAM_PERIODIC_10, SPELL_FOCUSED_EYEBEAM_PERIODIC_25)
#define SPELL_STONE_GRIP_DOT            RAID_MODE(SPELL_STONE_GRIP_DOT_10, SPELL_STONE_GRIP_DOT_25)

enum NPCs
{
    NPC_RUBBLE_STALKER    = 33809,
    NPC_ARM_SWEEP_STALKER = 33661
};

enum Events
{
    EVENT_INSTALL_ACCESSORIES = 1,
    EVENT_MELEE_CHECK,
    EVENT_SMASH,
    EVENT_SWEEP,
    EVENT_STONE_SHOUT,
    EVENT_STONE_GRIP,
    EVENT_FOCUSED_EYEBEAM,
    EVENT_RESPAWN_LEFT_ARM,
    EVENT_RESPAWN_RIGHT_ARM,
    EVENT_ENRAGE
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_LEFT_ARM_GONE                           = 2,
    SAY_RIGHT_ARM_GONE                          = 3,
    SAY_SHOCKWAVE                               = 4,
    SAY_GRAB_PLAYER                             = 5,
    SAY_DEATH                                   = 6,
    SAY_BERSERK                                 = 7,
    WHISPER_EYEBEAM                             = 8,
    EMOTE_LEFT                                  = 9,
    EMOTE_RIGHT                                 = 10,
    EMOTE_STONE                                 = 11
};

enum
{
    ACHIEV_DISARMED_START_EVENT                 = 21687,

    DATA_RUBBLE_AND_ROLL                        = 1,
    DATA_DISARMED                               = 2,
    DATA_WITH_OPEN_ARMS                         = 3
};

class boss_kologarn : public CreatureScript
{
    public:
        boss_kologarn() : CreatureScript("boss_kologarn") {}

        struct boss_kologarnAI : public BossAI
        {
            boss_kologarnAI(Creature* creature) : BossAI(creature, BOSS_KOLOGARN), vehicle(creature->GetVehicleKit()),
                haveLeftArm(false), haveRightArm(false)
            {
                ASSERT(vehicle);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                DoCast(SPELL_KOLOGARN_REDUCE_PARRY);
                SetCombatMovement(false);
                Reset();
            }            

            void Reset()
            {
                _Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
                me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                armDied = false;
                rubbleCount = 0;
                eyebeamTarget = 0;
                me->SetReactState(REACT_DEFENSIVE);

                Creature* leftHand = me->FindNearestCreature(NPC_LEFT_ARM, 20.f);
                if (leftHand)
                    leftHand->AI()->Reset();

                Creature* rightHand = me->FindNearestCreature(NPC_RIGHT_ARM, 20.f);
                if (rightHand)
                    rightHand->AI()->Reset();

                if (instance)
                    instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
                me->SetStandState(UNIT_STAND_STATE_STAND);

                events.ScheduleEvent(EVENT_MELEE_CHECK, 6*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SMASH, 5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SWEEP, 19*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_STONE_GRIP, 25*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, 21*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_ENRAGE, 10*MINUTE*IN_MILLISECONDS);

                for (uint8 i = 0; i < 2; ++i)   // 2 -> 2 arms
                    if (Unit* arm = vehicle->GetPassenger(i))
                        if (!arm->isInCombat()) // avoid cyclical activation: His arms are calling Kologarn if they get in combat and he is not.
                            arm->ToCreature()->SetInCombatWithZone();

                me->SetReactState(REACT_AGGRESSIVE);
                _EnterCombat();
            }            

            void JustDied(Unit* /*victim*/)
            {
                Talk(SAY_DEATH);
                DoCast(me, SPELL_KOLOGARN_PACIFY);  // TODO: Check if this works, since... yeah, we're dead.
                me->GetMotionMaster()->MoveTargetedHome();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetCorpseDelay(604800); // Prevent corpse from despawning - it's the bridge to inner Ulduar.

                for (uint8 i = 0; i < 2; ++i)
                    if (Unit* arm = vehicle->GetPassenger(i))
                        arm->ExitVehicle();

                summons.DespawnAll();

                while (Creature* rubbleStalker = me->FindNearestCreature(NPC_RUBBLE_STALKER, 100.0f, true))
                    rubbleStalker->DisappearAndDie();

                _JustDied();
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
            {
                bool isEncounterInProgress = (instance->GetBossState(BOSS_KOLOGARN) == IN_PROGRESS);
                if (who->GetEntry() == NPC_LEFT_ARM)
                {
                    haveLeftArm = apply;
                    if (!apply && isEncounterInProgress)
                    {
                        who->ToCreature()->DespawnOrUnsummon();
                        Talk(SAY_LEFT_ARM_GONE);
                        events.ScheduleEvent(EVENT_RESPAWN_LEFT_ARM, 40*IN_MILLISECONDS);
                    }
                }
                else if (who->GetEntry() == NPC_RIGHT_ARM)
                {
                    haveRightArm = apply;
                    if (!apply && isEncounterInProgress)
                    {
                        who->ToCreature()->DespawnOrUnsummon();
                        Talk(SAY_RIGHT_ARM_GONE);
                        events.ScheduleEvent(EVENT_RESPAWN_RIGHT_ARM, 40*IN_MILLISECONDS);
                    }
                }

                if (!isEncounterInProgress)
                    return;

                if (!apply)
                {
                    armDied = true;
                    who->CastSpell(me, SPELL_ARM_DEAD_DAMAGE, true);
                    me->LowerPlayerDamageReq(RAID_MODE<uint32>(543855, 2300925));   // Reduce requirements for players to get the loot - since the spell does a lot of damage

                    if (Creature* rubbleStalker = who->FindNearestCreature(NPC_RUBBLE_STALKER, 70.0f))
                    {
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_FALLING_RUBBLE, true);
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_SUMMON_RUBBLE, true);
                    }

                    if (!haveRightArm && !haveLeftArm)
                        events.ScheduleEvent(EVENT_STONE_SHOUT, 5*IN_MILLISECONDS);

                    if (instance)
                        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);   // !apply = passenger got lost
                }
                else
                {
                    if (instance)
                        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);

                    events.CancelEvent(EVENT_STONE_SHOUT);
                    who->ToCreature()->SetInCombatWithZone();
                }
            }

            // try to get ranged target, not too far away
            Player* GetEyeBeamTarget()
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    std::list<Player*> playerList;
                    Map::PlayerList const& players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* player = itr->getSource())
                        {
                            if (player->isDead() || player->HasAura(SPELL_STONE_GRIP_DOT) || player->isGameMaster())
                                continue;

                            if (me->getVictim())
                                if (me->getVictim()->GetGUID() == player->GetGUID())
                                    continue;

                            float Distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (Distance < 20.0f || Distance > 60.0f)
                                continue;

                            playerList.push_back(player);
                        }
                    }

                    if (playerList.empty()) // This should only happen if our current victim is the only alive one
                    {
                        Unit* sel = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true, -SPELL_STONE_GRIP_DOT);
                        if (sel)
                        {
                            if (Player* p = sel->ToPlayer())
                                playerList.push_back(p);
                            else
                                return 0;
                        }
                        else
                            return 0;    
                    }

                    return Trinity::Containers::SelectRandomContainerElement(playerList);
                }
                else
                    return 0;
            }

            // Just for the overall managing stuff...
            void SummonedCreatureDespawn(Creature* summon)
            {
                if (summon->GetEntry() == NPC_RUBBLE)
                    --rubbleCount;
                summons.Despawn(summon);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /* killer */)
            {
                if (summon->GetEntry() == NPC_RUBBLE)
                    --rubbleCount;
                summons.Despawn(summon);
            }

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_FOCUSED_EYEBEAM:
                        summons.Summon(summon);
                        summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT, true);
                        break;
                    case NPC_FOCUSED_EYEBEAM_RIGHT:
                        summons.Summon(summon);
                        summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT, true);
                        break;
                    case NPC_RUBBLE:
                        summons.Summon(summon);
                        summon->SetInCombatWithZone();
                        ++rubbleCount;
                        return;
                    default:
                        return;
                }

                summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_PERIODIC, true);
                summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_VISUAL, true);
                summon->SetReactState(REACT_PASSIVE);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                // One of the above spells is a channeled spell, we need to clear this unit state for MoveChase to work
                summon->ClearUnitState(UNIT_STATE_CASTING);

                // Victim gets 67351
                if (eyebeamTarget)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*summon, eyebeamTarget))
                    {
                        summon->Attack(target, false);
                        summon->GetMotionMaster()->MoveChase(target);
                    }
                }
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_RUBBLE_AND_ROLL:
                        return (rubbleCount >= 25) ? 1 : 0;
                    case DATA_DISARMED:
                        return (!haveRightArm && !haveLeftArm) ? 1 : 0;
                    case DATA_WITH_OPEN_ARMS:
                        return armDied ? 0 : 1;
                    default:
                        break;
                }

                return 0;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MELEE_CHECK:
                            if (!me->IsWithinMeleeRange(me->getVictim()))
                                DoCast(SPELL_PETRIFY_BREATH);
                            events.ScheduleEvent(EVENT_MELEE_CHECK, 1*IN_MILLISECONDS);
                            return;
                        case EVENT_SWEEP:           // Cast for left arm
                            if (haveLeftArm)
                            {
                                if (Creature* target = me->FindNearestCreature(NPC_ARM_SWEEP_STALKER, 500.0f, true))
                                {
                                    DoCast(target, SPELL_ARM_SWEEP, true);
                                    Talk(SAY_SHOCKWAVE);
                                }  
                            }
                            events.ScheduleEvent(EVENT_SWEEP, 25*IN_MILLISECONDS);
                            return;
                        case EVENT_STONE_GRIP:      // Cast for right arm
                            if (haveRightArm)
                            {
                                DoCast(SPELL_STONE_GRIP);
                                Talk(EMOTE_STONE);
                                Talk(SAY_GRAB_PLAYER);
                            }
                            events.ScheduleEvent(EVENT_STONE_GRIP, 25*IN_MILLISECONDS);
                            return;
                        case EVENT_SMASH:
                            if (haveLeftArm && haveRightArm)
                                DoCastVictim(SPELL_TWO_ARM_SMASH);
                            else if (haveLeftArm || haveRightArm)
                                DoCastVictim(SPELL_ONE_ARM_SMASH);
                            events.ScheduleEvent(EVENT_SMASH, 15 * IN_MILLISECONDS);
                            return;
                        case EVENT_STONE_SHOUT:
                            DoCast(SPELL_STONE_SHOUT);
                            events.ScheduleEvent(EVENT_STONE_SHOUT, 2*IN_MILLISECONDS);
                            return;
                        case EVENT_ENRAGE:
                            DoCast(SPELL_BERSERK);
                            Talk(SAY_BERSERK);
                            return;
                        case EVENT_RESPAWN_LEFT_ARM:
                            RespawnArm(NPC_LEFT_ARM);
                            Talk(EMOTE_LEFT);
                            events.CancelEvent(EVENT_RESPAWN_LEFT_ARM);
                            return;
                        case EVENT_RESPAWN_RIGHT_ARM:
                            RespawnArm(NPC_RIGHT_ARM);
                            Talk(EMOTE_RIGHT);
                            events.CancelEvent(EVENT_RESPAWN_RIGHT_ARM);
                            return;
                        case EVENT_FOCUSED_EYEBEAM:
                            if (Player* eyebeamTargetUnit = GetEyeBeamTarget())
                            {
                                eyebeamTarget = eyebeamTargetUnit->GetGUID();
                                Talk(WHISPER_EYEBEAM, eyebeamTarget);

                                eyebeamTargetUnit->CastSpell(eyebeamTargetUnit, 63343, true, NULL, NULL, me->GetGUID());
                                eyebeamTargetUnit->CastSpell(eyebeamTargetUnit, 63701, true, NULL, NULL, me->GetGUID());
                            }
                            events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void RespawnArm(uint32 entry)
            {
                if (Creature* arm = me->SummonCreature(entry, *me))
                {
                    // If that does not work properly, install the arm manually
                    arm->AddUnitTypeMask(UNIT_MASK_ACCESSORY);
                    int32 seatId = (entry == NPC_LEFT_ARM) ? 0 : 1;
                    arm->CastCustomSpell(SPELL_ARM_ENTER_VEHICLE, SPELLVALUE_BASE_POINT0, seatId+1, me, true);
                    arm->CastSpell(arm, SPELL_ARM_ENTER_VISUAL, true);
                    /*
                    int8 seat = eventId == EVENT_RESPAWN_LEFT_ARM ? 0 : 1;
                    uint32 entry = eventId == EVENT_RESPAWN_LEFT_ARM ? NPC_LEFT_ARM : NPC_RIGHT_ARM;
                    vehicle->InstallAccessory(entry, seat, true, TEMPSUMMON_MANUAL_DESPAWN, 0);
                    */
                }
            }

            private:
                Vehicle* vehicle;
                bool haveLeftArm, haveRightArm;
                bool armDied;
                uint64 eyebeamTarget;
                uint8 rubbleCount;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_kologarnAI>(creature);
        }
};

class npc_kologarn_arm : public CreatureScript
{
    public:
        npc_kologarn_arm() : CreatureScript("npc_kologarn_arm") {}

        struct npc_kologarn_armAI : public ScriptedAI
        {
            npc_kologarn_armAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* who)
            {
                me->SetReactState(REACT_AGGRESSIVE);

                Creature* kologarn = me->GetVehicleCreatureBase();
                if (kologarn && !kologarn->isInCombat())
                    kologarn->AI()->AttackStart(who);
            }

            void JustDied(Unit* /*victim*/)
            {
                me->DespawnOrUnsummon();
            }

            void DamageTaken(Unit* /*pDone*/, uint32 &damage)
            {
                // handle passenger throwing here, its too late when the arm is dead
                if (damage >= me->GetHealth())
                {
                    if (me->GetEntry() == NPC_RIGHT_ARM)
                    {
                        if (me->GetVehicleKit())
                        {
                            if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                            {
                                passenger->ExitVehicle();
                                passenger->GetMotionMaster()->MoveJump(1771.25f + irand(-3, 3), -13.3f + irand(-3, 3), 448.8f, 30.0f, 10.0f);
                            }
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kologarn_armAI(creature);
        }
};

class spell_ulduar_rubble_summon : public SpellScriptLoader
{
    public:
        spell_ulduar_rubble_summon() : SpellScriptLoader("spell_ulduar_rubble_summon") {}

        class spell_ulduar_rubble_summonSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_rubble_summonSpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                uint64 originalCaster = caster->GetInstanceScript() ? caster->GetInstanceScript()->GetData64(BOSS_KOLOGARN) : 0;
                uint32 spellId = GetEffectValue();
                for (uint8 i = 0; i < 5; ++i)
                    caster->CastSpell(caster, spellId, true, 0, 0, originalCaster);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_rubble_summonSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ulduar_rubble_summonSpellScript();
        }
};

// predicate function to select non main tank target
class StoneGripTargetSelector : public std::unary_function<WorldObject*, bool>
{
    public:
        StoneGripTargetSelector(Creature* me, WorldObject const* victim) : _me(me), _victim(victim) {}

        bool operator() (WorldObject* target)
        {
            if (target == _victim && _me->getThreatManager().getThreatList().size() > 1)
                return true;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return true;

            return false;
        }

        Creature* _me;
        WorldObject const* _victim;
};

class spell_ulduar_stone_grip_cast_target : public SpellScriptLoader
{
    public:
        spell_ulduar_stone_grip_cast_target() : SpellScriptLoader("spell_ulduar_stone_grip_cast_target") {}

        class spell_ulduar_stone_grip_cast_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_stone_grip_cast_target_SpellScript);

            bool Load()
            {
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return false;
                return true;
            }

            void FilterTargetsInitial(std::list<WorldObject*>& targets)
            {
                // Remove "main tank" and non-player targets
                targets.remove_if (StoneGripTargetSelector(GetCaster()->ToCreature(), GetCaster()->getVictim()));
                // Maximum affected targets per difficulty mode
                uint32 maxTargets = GetSpellInfo()->Id == 63981 ? 3 : 1; // 63981 -> 25 man raid

                // Return a random amount of targets based on maxTargets
                while (maxTargets < targets.size())
                {
                    std::list<WorldObject*>::iterator itr = targets.begin();
                    advance(itr, urand(0, targets.size()-1));
                    targets.erase(itr);
                }

                // For subsequent effects
                m_unitList = targets;
            }

            void FillTargetsSubsequential(std::list<WorldObject*>& targets)
            {
                targets = m_unitList;
            }

            void HandleForceCast(SpellEffIndex i)
            {
                Player* player = GetHitPlayer();

                if (!player)
                    return;

                // Don't send m_originalCasterGUID param here or underlying AuraEffect::HandleAuraControlVehicle will fail on caster == target
                player->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[i].TriggerSpell, true);
                PreventHitEffect(i);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_stone_grip_cast_target_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FillTargetsSubsequential, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FillTargetsSubsequential, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            // Shared between effects
            std::list<WorldObject*> m_unitList;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ulduar_stone_grip_cast_target_SpellScript();
        }
};

class spell_ulduar_cancel_stone_grip : public SpellScriptLoader
{
    public:
        spell_ulduar_cancel_stone_grip() : SpellScriptLoader("spell_ulduar_cancel_stone_grip") {}

        class spell_ulduar_cancel_stone_gripSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_cancel_stone_gripSpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                if (!target || !target->GetVehicle() || target->GetTypeId() != TYPEID_PLAYER)
                    return;

                switch (target->GetMap()->GetDifficulty())
                {
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                        target->RemoveAura(GetSpellInfo()->Effects[EFFECT_0].CalcValue());
                        break;
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                        target->RemoveAura(GetSpellInfo()->Effects[EFFECT_1].CalcValue());
                        break;
                    default:
                        break;
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_cancel_stone_gripSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ulduar_cancel_stone_gripSpellScript();
        }
};

class spell_ulduar_squeezed_lifeless : public SpellScriptLoader
{
    public:
        spell_ulduar_squeezed_lifeless() : SpellScriptLoader("spell_ulduar_squeezed_lifeless") {}

        class spell_ulduar_squeezed_lifeless_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_squeezed_lifeless_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitPlayer() || !GetHitPlayer()->GetVehicle())
                    return;

                Position pos;
                pos.m_positionX = 1756.25f + irand(-3, 3);
                pos.m_positionY = -8.3f + irand(-3, 3);
                pos.m_positionZ = 448.8f;
                pos.SetOrientation(M_PI);
                GetHitPlayer()->DestroyForNearbyPlayers();
                GetHitPlayer()->ExitVehicle(&pos);
                GetHitPlayer()->UpdateObjectVisibility(false);
            }

            void MoveCorpse()
            {
                GetHitUnit()->ExitVehicle();
                GetHitUnit()->GetMotionMaster()->MoveJump(1756.25f + irand(-3, 3), -8.3f + irand(-3, 3), 448.8f, 10.0f, 10.0f);
                //! Proper exit position does not work currently,
                //! See documentation in void Unit::ExitVehicle(Position const* exitPosition)
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_squeezed_lifeless_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
                AfterHit += SpellHitFn(spell_ulduar_squeezed_lifeless_SpellScript::MoveCorpse);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ulduar_squeezed_lifeless_SpellScript();
        }
};

class spell_ulduar_stone_grip_absorb : public SpellScriptLoader
{
    private:
        enum
        {
            NPC_RUBBLE_STALKER_25 = 33942
        };

    public:
        spell_ulduar_stone_grip_absorb() : SpellScriptLoader("spell_ulduar_stone_grip_absorb") {}

        class spell_ulduar_stone_grip_absorb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ulduar_stone_grip_absorb_AuraScript);

            //! This will be called when Right Arm (vehicle) has sustained a specific amount of damage depending on instance mode
            //! What we do here is remove all harmful aura's related and teleport to safe spot.
            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
                    return;

                if (!GetOwner()->ToCreature())
                    return;

                uint32 rubbleStalkerEntry = (GetOwner()->GetMap()->GetDifficulty() == DUNGEON_DIFFICULTY_NORMAL ? NPC_RUBBLE_STALKER : NPC_RUBBLE_STALKER_25);  // An exception that we need the difficulty-entry for.
                Creature* rubbleStalker = GetOwner()->FindNearestCreature(rubbleStalkerEntry, 200.0f, true);
                // TODO: Check if that works, if it doesn't, we need a manual exit from vehicle
                if (rubbleStalker)
                    rubbleStalker->CastSpell(rubbleStalker, SPELL_STONE_GRIP_CANCEL, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_absorb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ulduar_stone_grip_absorb_AuraScript();
        }
};

class spell_ulduar_stone_grip : public SpellScriptLoader
{
    private:
        enum
        {
            SPELL_SQUEEZED_LIFELESS = 64708
        };

    public:
        spell_ulduar_stone_grip() : SpellScriptLoader("spell_ulduar_stone_grip") {}

        class spell_ulduar_stone_grip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ulduar_stone_grip_AuraScript);

            void OnRemoveStun(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Player* owner = GetOwner()->ToPlayer())
                {
                    owner->RemoveAurasDueToSpell(aurEff->GetAmount());
                    owner->RemoveAurasDueToSpell(SPELL_SQUEEZED_LIFELESS);
                }
            }

            void OnEnterVehicle(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Player* caster = GetCaster() ? GetCaster()->ToPlayer() : 0;
                if (caster)
                    caster->ClearUnitState(UNIT_STATE_ONVEHICLE);
                // TODO: Check if this works, but due to the code below, GetCaster() should return the player. 
                // It appears that this function will be called after entering the "vehicle" arm. 
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_ulduar_stone_grip_AuraScript::OnEnterVehicle, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_AuraScript::OnRemoveStun, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ulduar_stone_grip_AuraScript();
        }
};

class spell_kologarn_stone_shout : public SpellScriptLoader
{
    public:
        spell_kologarn_stone_shout() : SpellScriptLoader("spell_kologarn_stone_shout") {}

        class spell_kologarn_stone_shout_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_kologarn_stone_shout_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if (PlayerOrPetCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_stone_shout_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_kologarn_stone_shout_SpellScript();
        }
};

class spell_kologarn_summon_focused_eyebeam : public SpellScriptLoader
{
    public:
        spell_kologarn_summon_focused_eyebeam() : SpellScriptLoader("spell_kologarn_summon_focused_eyebeam") {}

        class spell_kologarn_summon_focused_eyebeam_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_kologarn_summon_focused_eyebeam_SpellScript);

            void HandleForceCast(SpellEffIndex eff)
            {
                PreventHitDefaultEffect(eff);
                GetCaster()->CastSpell(GetCaster(), GetSpellInfo()->Effects[eff].TriggerSpell, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_kologarn_summon_focused_eyebeam_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
                OnEffectHitTarget += SpellEffectFn(spell_kologarn_summon_focused_eyebeam_SpellScript::HandleForceCast, EFFECT_1, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_kologarn_summon_focused_eyebeam_SpellScript();
        }
};

class achievement_rubble_and_roll : public AchievementCriteriaScript
{
    public:
        achievement_rubble_and_roll(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_RUBBLE_AND_ROLL);

            return false;
        }
};

class achievement_disarmed : public AchievementCriteriaScript
{
    public:
        achievement_disarmed(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_DISARMED);

            return false;
        }
};

class achievement_with_open_arms : public AchievementCriteriaScript
{
    public:
        achievement_with_open_arms(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_WITH_OPEN_ARMS);

            return false;
        }
};

void AddSC_boss_kologarn()
{
    new boss_kologarn();
    new npc_kologarn_arm();
    new spell_ulduar_rubble_summon();
    new spell_ulduar_squeezed_lifeless();
    new spell_ulduar_cancel_stone_grip();
    new spell_ulduar_stone_grip_cast_target();
    new spell_ulduar_stone_grip_absorb();
    new spell_ulduar_stone_grip();
    new spell_kologarn_stone_shout();
    new spell_kologarn_summon_focused_eyebeam();

    new achievement_rubble_and_roll("achievement_rubble_and_roll");
    new achievement_rubble_and_roll("achievement_rubble_and_roll_25");
    new achievement_disarmed("achievement_disarmed");
    new achievement_disarmed("achievement_disarmed_25");
    new achievement_with_open_arms("achievement_with_open_arms");
    new achievement_with_open_arms("achievement_with_open_arms_25");
}

#undef SPELL_ARM_DEAD_DAMAGE
#undef SPELL_TWO_ARM_SMASH
#undef SPELL_ONE_ARM_SMASH
#undef SPELL_ARM_SWEEP
#undef SPELL_STONE_SHOUT
#undef SPELL_PETRIFY_BREATH
#undef SPELL_STONE_GRIP
#undef SPELL_FOCUSED_EYEBEAM_PERIODIC
#undef SPELL_STONE_GRIP_DOT
