/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include <limits>

/*
7[17:27]	@DorianGrey: 2945, 2946 (But I'm on your side)          | 10088,10418,10419 - 10089,10420,10421 
7[17:27]	@DorianGrey: 2947, 2948 (Can't do that while stunned)   | 10090,10422,10423 - 10091,10424,10425
7[17:27]	@DorianGrey: 2941, 2944 (I choose you)                  | 10084 - 10087
*/

enum AssemblySpells
{
    // Any boss
    SPELL_SUPERCHARGE                  = 61920,
    SPELL_BERSERK                      = 47008, // Hard enrage, don't know the correct ID.
    SPELL_CREDIT_MARKER                = 65195, // spell_dbc
    SPELL_IRON_BOOT_FLASK              = 58501,

    // Steelbreaker
    SPELL_HIGH_VOLTAGE                 = 61890,
    SPELL_FUSION_PUNCH                 = 61903,
    SPELL_STATIC_DISRUPTION_10         = 61911,
    SPELL_STATIC_DISRUPTION_CHECKED_10 = 61912, // Checked = spell works as target-check-trigger
    SPELL_STATIC_DISRUPTION_25         = 63494,
    SPELL_STATIC_DISRUPTION_CHECKED_25 = 63495,
    SPELL_OVERWHELMING_POWER_10        = 61888,
    SPELL_OVERWHELMING_POWER_25        = 64637,
    SPELL_MELTDOWN                     = 61889, // Triggered by overwhelming power
    SPELL_ELECTRICAL_CHARGE            = 61900,
    SPELL_ELECTRICAL_CHARGE_TRIGGER    = 61901,
    SPELL_ELECTRICAL_CHARGE_TRIGGERED  = 61902,

    // Runemaster Molgeim
    SPELL_SHIELD_OF_RUNES              = 62274,
    SPELL_SHIELD_OF_RUNES_10_BUFF      = 62277,
    SPELL_SHIELD_OF_RUNES_25_BUFF      = 63967,
    SPELL_SUMMON_RUNE_OF_POWER         = 63513,
    SPELL_RUNE_OF_POWER                = 61974,
    SPELL_RUNE_OF_DEATH                = 62269,
    SPELL_RUNE_OF_SUMMONING            = 62273, // This is the spell that summons the rune
    SPELL_RUNE_OF_SUMMONING_VIS        = 62019, // Visual
    SPELL_RUNE_OF_SUMMONING_SUMMON     = 62020, // Spell that summons
    SPELL_LIGHTNING_ELEMENTAL_PASSIVE  = 62052, // Basic spell
    SPELL_LIGHTNING_BLAST              = 62054, // Triggered by SPELL_LIGHTNING_BLAST

    // Stormcaller Brundir
    SPELL_CHAIN_LIGHTNING_10           = 61879,
    SPELL_CHAIN_LIGHTNING_25           = 63479,
    SPELL_OVERLOAD_10                  = 61869,
    SPELL_OVERLOAD_25                  = 63481,
    SPELL_LIGHTNING_WHIRL_10           = 61915,
    SPELL_LIGHTNING_WHIRL_25           = 63483,
    SPELL_LIGHTNING_WHIRL_DMG_10       = 61916,   // Periodic damage by spell above
    SPELL_LIGHTNING_WHIRL_DMG_25       = 63482,
    SPELL_LIGHTNING_TENDRILS_10        = 61887,
    SPELL_LIGHTNING_TENDRILS_25        = 63486,
    SPELL_LIGHTNING_TENDRILS_VISUAL    = 61883,
    SPELL_STORMSHIELD                  = 64187
};

// Steelbreaker
#define SPELL_STATIC_DISRUPTION RAID_MODE(SPELL_STATIC_DISRUPTION_10, SPELL_STATIC_DISRUPTION_25)
#define SPELL_OVERWHELMING_POWER RAID_MODE(SPELL_OVERWHELMING_POWER_10, SPELL_OVERWHELMING_POWER_25)

// Molgeim
#define SPELL_SHIELD_OF_RUNES_BUFF RAID_MODE(SPELL_SHIELD_OF_RUNES_10_BUFF, SPELL_SHIELD_OF_RUNES_25_BUFF)

// Brundir
#define SPELL_CHAIN_LIGHTNING RAID_MODE(SPELL_CHAIN_LIGHTNING_10, SPELL_CHAIN_LIGHTNING_25)
#define SPELL_OVERLOAD RAID_MODE(SPELL_OVERLOAD_10, SPELL_OVERLOAD_25)
#define SPELL_LIGHTNING_WHIRL RAID_MODE(SPELL_LIGHTNING_WHIRL_10, SPELL_LIGHTNING_WHIRL_25)
#define SPELL_LIGHTNING_WHIRL_DMG RAID_MODE(SPELL_LIGHTNING_WHIRL_DMG_10, SPELL_LIGHTNING_WHIRL_DMG_25)
#define SPELL_LIGHTNING_TENDRILS RAID_MODE(SPELL_LIGHTNING_TENDRILS_10, SPELL_LIGHTNING_TENDRILS_25)

enum AssemblyEvents
{
    // General
    EVENT_ENRAGE                                        = 1,

    // Steelbreaker
    EVENT_FUSION_PUNCH                                  = 2,
    EVENT_STATIC_DISRUPTION                             = 3,
    EVENT_OVERWHELMING_POWER                            = 4,

    // Molgeim
    EVENT_RUNE_OF_POWER                                 = 5,
    EVENT_SHIELD_OF_RUNES                               = 6,
    EVENT_RUNE_OF_DEATH                                 = 7,
    EVENT_RUNE_OF_SUMMONING                             = 8,
    EVENT_LIGHTNING_BLAST                               = 9,

    // Brundir
    EVENT_CHAIN_LIGHTNING                               = 10,
    EVENT_OVERLOAD                                      = 11,
    EVENT_LIGHTNING_WHIRL                               = 12,
    EVENT_LIGHTNING_TENDRILS_START                      = 13,
    EVENT_STORMSHIELD                                   = 14,
    EVENT_THREAT_WIPE                                   = 15,
    EVENT_LIGHTNING_TENDRILS_FLIGHT_NEW_TARGET          = 16,
    EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET       = 17,
    EVENT_LIGHTNING_TENDRILS_ENDFLIGHT                  = 18,
    EVENT_LIGHTNING_TENDRILS_GROUND                     = 19,
    EVENT_LIGHTNING_TENDRILS_LAND                       = 20,
    EVENT_MOVE_POSITION                                 = 21
};

enum AssemblyActions
{
    ACTION_ADD_CHARGE           = 3,
    ACTION_UPDATEPHASE          = 4
};

enum SteelBreakerYells
{
    SAY_STEELBREAKER_AGGRO      = 0,
    SAY_STEELBREAKER_SLAY       = 1,
    SAY_STEELBREAKER_POWER      = 2,
    SAY_STEELBREAKER_DEATH      = 3,
    SAY_STEELBREAKER_BERSERK    = 4
};

enum MolgeimYells
{
    SAY_MOLGEIM_AGGRO           = 0,
    SAY_MOLGEIM_SLAY            = 1,
    SAY_MOLGEIM_RUNE_DEATH      = 2,
    SAY_MOLGEIM_SUMMON          = 3,
    SAY_MOLGEIM_DEATH           = 4,
    SAY_MOLGEIM_BERSERK         = 5
};

enum BrundirYells
{
    SAY_BRUNDIR_AGGRO           = 0,
    SAY_BRUNDIR_SLAY            = 1,
    SAY_BRUNDIR_SPECIAL         = 2,
    SAY_BRUNDIR_FLIGHT          = 3,
    SAY_BRUNDIR_DEATH           = 4,
    SAY_BRUNDIR_BERSERK         = 5,
    EMOTE_OVERLOAD              = 6
};

enum AssemblyNPCs
{
    NPC_WORLD_TRIGGER = 22515
};

enum MovePoints
{
    POINT_FLY   = 1,
    POINT_LAND  = 2,
    POINT_CHASE = 3
};

enum Phases
{
    PHASE_IDLE      = 0,
    PHASE_0_DEAD    = 1,
    PHASE_1_DEAD    = 2,
    PHASE_2_DEAD    = 3
};

enum Data
{
    DATA_I_CHOOSE_YOU_PHASE_CHECK = 1,
    DATA_CANT_DO_THAT_WHILE_STUNNED
};

#define FLOOR_Z         427.28f

Position const FinalPos =
{
    1586.920166f, 119.848984f, 435.0f, 0
};

void PostEncounterStuff(InstanceScript* inst)
{
    if (!inst)
        return;

    // Note: Sometimes, the players remain infight, even with the whole Assembly of Iron finished.
    // Seems that this occurs due to temporarily spawned triggers which despawn during fight or afterwards.
    // While a SEND_MSG_ATTACKSTART is sent once they spawn (e.g., for Rune of Power), its ATTACKSTOP never occurs in the server-logs.
    // Thus, I will force a combat-stop here.
    const Map::PlayerList& players = inst->instance->GetPlayers();
    for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
    {
        if (Player* p = it->getSource())
            p->CombatStop(true);
    }

    inst->SetBossState(BOSS_ASSEMBLY_OF_IRON, DONE);
    inst->SetBossState(BOSS_STEELBREAKER, DONE);
    inst->SetBossState(BOSS_MOLGEIM, DONE);
    inst->SetBossState(BOSS_BRUNDIR, DONE);

    // Open door to Kologarn
    inst->HandleGameObject(inst->GetData64(GO_KOLOGARN_DOOR), true);
}

bool IsEncounterComplete(InstanceScript* instance, Creature* me)
{
    if (!instance || !me)
        return false;

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
        if (boss->isAlive())
            return false;

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_BRUNDIR)))
        if (boss->isAlive())
            return false;

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MOLGEIM)))
        if (boss->isAlive())
            return false;

    return true;
}

void RespawnEncounter(InstanceScript* instance, Creature* me)
{
    if (!instance || !me)
        return;

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
        if (!boss->isAlive())
        {
            boss->Respawn();
            boss->GetMotionMaster()->MoveTargetedHome();
        }

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_BRUNDIR)))
        if (!boss->isAlive())
        {
            boss->Respawn();
            boss->GetMotionMaster()->MoveTargetedHome();
        }

    if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MOLGEIM)))
        if (!boss->isAlive())
        {
            boss->Respawn();
            boss->GetMotionMaster()->MoveTargetedHome();
        }
}

void ResetEncounter(InstanceScript* instance, Creature* me)
{
    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(BOSS_STEELBREAKER + i);
        if (!guid)
            continue;

        if (Creature* boss = ObjectAccessor::GetCreature(*me, guid))
        {
            if (!boss->isAlive())
            {
                boss->Respawn();
                boss->GetMotionMaster()->MoveTargetedHome();
            }
        }
    }

    instance->HandleGameObject(instance->GetData64(GO_KOLOGARN_DOOR), false);
}

void StartEncounter(InstanceScript* instance, Creature* caller)
{
    if (instance && instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) == IN_PROGRESS)
        return; // Prevent recursive calls

    instance->SetBossState(BOSS_ASSEMBLY_OF_IRON, IN_PROGRESS);

    if (Creature* boss = ObjectAccessor::GetCreature(*caller, instance->GetData64(BOSS_STEELBREAKER)))
        if (boss->isAlive() && caller->GetGUID()!=boss->GetGUID()) // Avoid redundant calls
            boss->SetInCombatWithZone();

    if (Creature* boss = ObjectAccessor::GetCreature(*caller, instance->GetData64(BOSS_BRUNDIR)))
        if (boss->isAlive() && caller->GetGUID()!=boss->GetGUID()) // Avoid redundant calls
            boss->SetInCombatWithZone();

    if (Creature* boss = ObjectAccessor::GetCreature(*caller, instance->GetData64(BOSS_MOLGEIM)))
        if (boss->isAlive() && caller->GetGUID()!=boss->GetGUID()) // Avoid redundant calls
            boss->SetInCombatWithZone();
}

class boss_steelbreaker : public CreatureScript
{
    public:
        boss_steelbreaker() : CreatureScript("boss_steelbreaker") {}

        struct boss_steelbreakerAI : public BossAI
        {
            boss_steelbreakerAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) {}

            void Reset()
            {
                _Reset();
                _phase = PHASE_0_DEAD;
                _superChargedCnt = 0;
                me->RemoveAllAuras();
                me->RemoveLootMode(LOOT_MODE_DEFAULT);
                ResetEncounter(instance, me);
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->setActive(true);
                StartEncounter(instance, me);
                DoZoneInCombat();
                DoCast(me, SPELL_HIGH_VOLTAGE);
                events.ScheduleEvent(EVENT_ENRAGE, 15*MINUTE*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FUSION_PUNCH, 15*IN_MILLISECONDS);
                Talk(SAY_STEELBREAKER_AGGRO);
                DoAction(ACTION_UPDATEPHASE);
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_I_CHOOSE_YOU_PHASE_CHECK)
                    return (_phase >= PHASE_2_DEAD) ? 1 : 0;

                return 0;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_ADD_CHARGE:
                        DoCast(me, SPELL_ELECTRICAL_CHARGE, true);
                        break;
                    case ACTION_UPDATEPHASE:
                        _phase++;
                        events.SetPhase(_phase);
                        if (_phase >= PHASE_2_DEAD)
                        {
                            me->ResetLootMode();
                            DoCast(me, SPELL_ELECTRICAL_CHARGE, true);
                            uint32 nextSchedule = 0;
                            if (events.GetNextEventTime(EVENT_STATIC_DISRUPTION) > 0)   // Note: Function returns 0 if the event isn't scheduled yet.
                                nextSchedule = urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS);
                            else 
                                nextSchedule = urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                            events.RescheduleEvent(EVENT_OVERWHELMING_POWER, nextSchedule);
                        }
                        else if (_phase >= PHASE_1_DEAD)
                            events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 30*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*who*/)
            {
                Talk(SAY_STEELBREAKER_DEATH);
                if (IsEncounterComplete(instance, me))
                {
                    me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                    _JustDied();
                    PostEncounterStuff(instance);
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
                }
                else
                {
                    events.Reset();
                    summons.DespawnAll();
                    me->SetLootRecipient(NULL);
                    DoCastAOE(SPELL_SUPERCHARGE);
                }            
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_STEELBREAKER_SLAY);

                if (_phase == PHASE_2_DEAD)
                    DoCast(me, SPELL_ELECTRICAL_CHARGE);
            }

            void SpellHit(Unit* /*from*/, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_SUPERCHARGE:
                        me->SetHealth(me->GetMaxHealth());                     
                        events.RescheduleEvent(EVENT_FUSION_PUNCH, 15*IN_MILLISECONDS);
                        _superChargedCnt++;
                        DoAction(ACTION_UPDATEPHASE);
                        // Crazy hack, but since - whyever - stacking does not work automatically when the casts are fired from different NPCs...
                        // Note that it also does not work if the same NPC tries to cast the spell twice (as used in last commit)
                        if (Aura* charge = me->GetAura(SPELL_SUPERCHARGE))                           
                            charge->SetStackAmount(std::min<uint8>(2, _superChargedCnt));
                        break;
                    case SPELL_ELECTRICAL_CHARGE_TRIGGERED:
                        if (!me->isInCombat())
                            me->RemoveAurasDueToSpell(SPELL_ELECTRICAL_CHARGE_TRIGGERED);
                        break;
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_MELTDOWN && target && target->ToCreature())
                    target->CastSpell(me, SPELL_ELECTRICAL_CHARGE_TRIGGER, true);
            }

            // try to prefer ranged targets, targets that already have the aura should be avoided; tanks are allowed
            Unit* GetDisruptionTarget()
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    std::list<Player*> playerList;
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    {
                        if (Player* player = itr->getSource())
                        {
                            if (player->isDead() || player->HasAura(SPELL_STATIC_DISRUPTION) || player->isGameMaster())
                                continue;

                            float Distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (Distance < 15.0f || Distance > 100.0f)
                                continue;

                            playerList.push_back(player);
                        }
                    }

                    if (playerList.empty())
                    {
                        Unit* sel = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, -SPELL_STATIC_DISRUPTION);
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

            void UpdateAI(uint32 const diff)
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
                        case EVENT_ENRAGE:
                            Talk(SAY_STEELBREAKER_BERSERK);
                            DoCast(SPELL_BERSERK);
                            return;
                        case EVENT_FUSION_PUNCH:
                            if (me->IsWithinMeleeRange(me->getVictim()))
                                DoCastVictim(SPELL_FUSION_PUNCH);
                            events.ScheduleEvent(EVENT_FUSION_PUNCH, urand(13*IN_MILLISECONDS, 22*IN_MILLISECONDS));
                            return;
                        case EVENT_STATIC_DISRUPTION:
                            if (Unit* target = GetDisruptionTarget())
                                DoCast(target, SPELL_STATIC_DISRUPTION);
                            events.ScheduleEvent(EVENT_STATIC_DISRUPTION, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_OVERWHELMING_POWER:
                            if (me->getVictim() && !me->getVictim()->HasAura(SPELL_OVERWHELMING_POWER))
                            {
                                Talk(SAY_STEELBREAKER_POWER);
                                DoCastVictim(SPELL_OVERWHELMING_POWER);
                                events.ScheduleEvent(EVENT_OVERWHELMING_POWER, RAID_MODE(60*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            }
                            else
                                events.ScheduleEvent(EVENT_OVERWHELMING_POWER, 2*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                uint32 _phase;
                uint8 _superChargedCnt;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_steelbreakerAI>(creature);
        }
};

class spell_steelbreaker_static_disruption : public SpellScriptLoader
{
    public:
        spell_steelbreaker_static_disruption() : SpellScriptLoader("spell_steelbreaker_static_disruption") {}

        class spell_steelbreaker_static_disruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_steelbreaker_static_disruption_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_STATIC_DISRUPTION_CHECKED_10))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_STATIC_DISRUPTION_CHECKED_25))
                    return false;
                return true;
            }

            void HandleTriggerMissile(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                if (caster && target)
                {
                    uint32 id = uint32(caster->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? SPELL_STATIC_DISRUPTION_CHECKED_10 : SPELL_STATIC_DISRUPTION_CHECKED_25);
                    caster->CastSpell(target, id, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_steelbreaker_static_disruption_SpellScript::HandleTriggerMissile, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_steelbreaker_static_disruption_SpellScript();
        }
};

class spell_steelbreaker_electrical_charge : public SpellScriptLoader
{
    public:
        spell_steelbreaker_electrical_charge() : SpellScriptLoader("spell_steelbreaker_electrical_charge") {}

        class spell_steelbreaker_electrical_charge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_steelbreaker_electrical_charge_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                Unit* caster = GetCaster();
                if (target && target->ToPlayer() && caster && GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    target->CastSpell(caster, GetSpellInfo()->Effects[EFFECT_0].CalcValue(), true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_steelbreaker_electrical_charge_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_steelbreaker_electrical_charge_AuraScript();
        }
};

class boss_runemaster_molgeim : public CreatureScript
{
    public:
        boss_runemaster_molgeim() : CreatureScript("boss_runemaster_molgeim") {}

        struct boss_runemaster_molgeimAI : public BossAI
        {
            boss_runemaster_molgeimAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) {}

            void Reset()
            {
                _Reset();
                _phase = PHASE_IDLE;
                _superChargedCnt = 0;
                me->RemoveAllAuras();
                me->RemoveLootMode(LOOT_MODE_DEFAULT);
                ResetEncounter(instance, me);
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->setActive(true);
                StartEncounter(instance, me);
                DoZoneInCombat();
                events.ScheduleEvent(EVENT_ENRAGE, 15*MINUTE*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_RUNE_OF_POWER, 20*IN_MILLISECONDS);
                Talk(SAY_MOLGEIM_AGGRO);
                DoAction(ACTION_UPDATEPHASE);
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_I_CHOOSE_YOU_PHASE_CHECK)
                    return (_phase >= PHASE_2_DEAD) ? 1 : 0;
                return 0;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_UPDATEPHASE:
                        _phase++;
                        events.SetPhase(_phase);
                        if (_phase >= PHASE_2_DEAD)
                        {
                            me->ResetLootMode();
                            events.RescheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                        }
                        else if (_phase >= PHASE_1_DEAD)
                            events.RescheduleEvent(EVENT_RUNE_OF_DEATH, 30*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*who*/)
            {
                Talk(SAY_MOLGEIM_DEATH);
                if (IsEncounterComplete(instance, me))
                {
                    _JustDied();
                    PostEncounterStuff(instance);
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
                }
                else
                {
                    events.Reset();
                    summons.DespawnAll();
                    me->SetLootRecipient(NULL);
                    DoCastAOE(SPELL_SUPERCHARGE);
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_MOLGEIM_SLAY);
            }

            void SpellHit(Unit* /*from*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_SUPERCHARGE)
                {
                    me->SetHealth(me->GetMaxHealth());
                    events.RescheduleEvent(EVENT_SHIELD_OF_RUNES, 27*IN_MILLISECONDS);
                    events.RescheduleEvent(EVENT_RUNE_OF_POWER, 25*IN_MILLISECONDS);
                    _superChargedCnt++;
                    DoAction(ACTION_UPDATEPHASE);
                    // TODO: hack while stacking auras cast by different npcs doesnt work
                    if (Aura* charge = me->GetAura(SPELL_SUPERCHARGE))
                        charge->SetStackAmount(std::min<uint8>(2, _superChargedCnt));
                }
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_ENRAGE:
                            Talk(SAY_MOLGEIM_BERSERK);
                            DoCast(SPELL_BERSERK);
                            break;
                        case EVENT_RUNE_OF_POWER:
                            if (Unit* target = DoSelectLowestHpFriendly(60)) // Removed dead-check, function does not return dead allies
                                DoCast(target, SPELL_SUMMON_RUNE_OF_POWER);
                            else
                                DoCast(me, SPELL_SUMMON_RUNE_OF_POWER);
                            events.ScheduleEvent(EVENT_RUNE_OF_POWER, 60*IN_MILLISECONDS);
                            break;
                        case EVENT_SHIELD_OF_RUNES:
                            DoCast(me, SPELL_SHIELD_OF_RUNES);
                            events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, urand(27*IN_MILLISECONDS, 34*IN_MILLISECONDS));
                            break;
                        case EVENT_RUNE_OF_DEATH:
                            Talk(SAY_MOLGEIM_RUNE_DEATH);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_RUNE_OF_DEATH);
                            events.ScheduleEvent(EVENT_RUNE_OF_DEATH, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            break;
                        case EVENT_RUNE_OF_SUMMONING:
                            Talk(SAY_MOLGEIM_SUMMON);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_RUNE_OF_SUMMONING);
                            events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(35*IN_MILLISECONDS, 45*IN_MILLISECONDS));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                uint32 _phase;
                uint8 _superChargedCnt;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_runemaster_molgeimAI>(creature);
        }
};

class mob_rune_of_power : public CreatureScript
{
    public:
        mob_rune_of_power() : CreatureScript("mob_rune_of_power") {}

        struct mob_rune_of_powerAI : public Scripted_NoMovementAI
        {
            mob_rune_of_powerAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetInCombatWithZone();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(16); // Same faction as bosses
                DoCast(SPELL_RUNE_OF_POWER);

                me->DespawnOrUnsummon(60*IN_MILLISECONDS);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_rune_of_powerAI(creature);
        }
};

class mob_lightning_elemental : public CreatureScript
{
    public:
        mob_lightning_elemental() : CreatureScript("mob_lightning_elemental") {}

        struct mob_lightning_elementalAI : public ScriptedAI
        {
            mob_lightning_elementalAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                me->SetInCombatWithZone();
            }

            void EnterCombat(Unit* /* target */)
            {
                DoCast(me, SPELL_LIGHTNING_ELEMENTAL_PASSIVE);      // TODO: Check if both this spell and the other one below are required
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    me->AddThreat(target, std::numeric_limits<float>::max());
                    AttackStart(target);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()) && !_castDone)
                {
                    me->CastSpell(me, SPELL_LIGHTNING_BLAST, true);
                    me->DespawnOrUnsummon(0.5*IN_MILLISECONDS);
                    _castDone = true;
                }

                if (_instance && _instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }

        private:
            InstanceScript* _instance;
            bool _castDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lightning_elementalAI(creature);
        }
};

class mob_rune_of_summoning : public CreatureScript
{
    public:
        mob_rune_of_summoning() : CreatureScript("mob_rune_of_summoning") {}

        struct mob_rune_of_summoningAI : public ScriptedAI
        {
            mob_rune_of_summoningAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddAura(SPELL_RUNE_OF_SUMMONING_VIS, me);
                _summonCount = 0;
                _summonTimer = 2*IN_MILLISECONDS;
                _instance = creature->GetInstanceScript();
            }

            void JustSummoned(Creature* summon)
            {
                if (Creature* Molgeim = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(DATA_MOLGEIM) : 0))
                    Molgeim->AI()->JustSummoned(summon);    // Move ownership, take care that the spawned summon does not know about this
            }

            void UpdateAI(uint32 const diff)
            {
                if (_summonTimer <= diff)
                    SummonLightningElemental();
                else
                    _summonTimer -= diff;
            }

            void SummonLightningElemental()
            {
                me->CastSpell(me, SPELL_RUNE_OF_SUMMONING_SUMMON, false);   // Spell summons 32958
                if (++_summonCount == 10)                        // TODO: Find out if this amount is right
                    me->DespawnOrUnsummon();
                else
                    _summonTimer = 2*IN_MILLISECONDS;                         // TODO: Find out of timer is right
            }

            private:
                InstanceScript* _instance;
                uint32 _summonCount;
                uint32 _summonTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_rune_of_summoningAI(creature);
        }
};

class boss_stormcaller_brundir : public CreatureScript
{
    public:
        boss_stormcaller_brundir() : CreatureScript("boss_stormcaller_brundir") {}

        struct boss_stormcaller_brundirAI : public BossAI
        {
            boss_stormcaller_brundirAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) {}

            void Reset()
            {
                _Reset();
                _phase = PHASE_IDLE;
                _superChargedCnt = 0;
                _tendrilTarget = 0;
                _forceLand = false;
                _couldNotDoThat = true;
                me->RemoveAllAuras();
                me->RemoveLootMode(LOOT_MODE_DEFAULT);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                me->SendMovementFlagUpdate();
                me->SetSpeed(MOVE_RUN, 1.42857f);

                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);  // Should be interruptible unless overridden by spell (Overload)
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);       // Reset immunity, Brundir can be stunned by default
                ResetEncounter(instance, me);
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->setActive(true);
                StartEncounter(instance, me);
                DoZoneInCombat();
                events.ScheduleEvent(EVENT_ENRAGE, 15*MINUTE*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 4*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_OVERLOAD, urand(40*IN_MILLISECONDS, 80*IN_MILLISECONDS));
                Talk(SAY_BRUNDIR_AGGRO);
                DoAction(ACTION_UPDATEPHASE);
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_I_CHOOSE_YOU_PHASE_CHECK:
                        return (_phase >= PHASE_2_DEAD) ? 1 : 0;
                    case DATA_CANT_DO_THAT_WHILE_STUNNED:
                        return _couldNotDoThat ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                    if (_couldNotDoThat)
                        switch (spell->Id)
                        {
                            case SPELL_CHAIN_LIGHTNING_10:
                            case SPELL_CHAIN_LIGHTNING_25:
                            case SPELL_LIGHTNING_WHIRL_DMG_10:
                            case SPELL_LIGHTNING_WHIRL_DMG_25:
                                _couldNotDoThat = false;
                                break;
                            default:
                                break;
                        }
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_UPDATEPHASE:
                        // Change internal phase. Note that the events should _only_ be scheduled if they are not.
                        _phase++;
                        events.SetPhase(_phase);
                        if (_phase >= PHASE_2_DEAD)
                        {
                            me->ResetLootMode();
                            events.ScheduleEvent(EVENT_THREAT_WIPE, 10*IN_MILLISECONDS);
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                            DoCast(me, SPELL_STORMSHIELD);
                            events.RescheduleEvent(EVENT_LIGHTNING_TENDRILS_START, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                        }
                        else if (_phase >= PHASE_1_DEAD)
                            events.RescheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*who*/)
            {
                Talk(SAY_BRUNDIR_DEATH);
                if (IsEncounterComplete(instance, me))
                {
                    _JustDied();
                    PostEncounterStuff(instance);
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
                }
                else
                {
                    events.Reset();
                    summons.DespawnAll();
                    me->SetLootRecipient(NULL);
                    DoCastAOE(SPELL_SUPERCHARGE);
                }

                // Prevent to have Brundir somewhere in the air when he die in Air phase
                if (me->GetPositionZ() > FLOOR_Z)
                    me->GetMotionMaster()->MoveFall();
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_BRUNDIR_SLAY);
            }

            void SpellHit(Unit* /*from*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_SUPERCHARGE)
                {
                    me->SetHealth(me->GetMaxHealth());
                    _superChargedCnt++;
                    DoAction(ACTION_UPDATEPHASE);
                    // Crazy hack, but since - whyever - stacking does not work automatically when the casts are fired from different NPCs...
                    // Note that it also does not work if the same NPC tries to cast the spell twice (as used in last commit)
                    if (Aura* charge = me->GetAura(SPELL_SUPERCHARGE))
                        charge->SetStackAmount(std::min<uint8>(2, _superChargedCnt));
                }
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_ENRAGE:
                            Talk(SAY_BRUNDIR_BERSERK);
                            DoCast(SPELL_BERSERK);
                            return;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS));
                            return;
                        case EVENT_OVERLOAD:
                            Talk(EMOTE_OVERLOAD);
                            Talk(SAY_BRUNDIR_SPECIAL);
                            DoCast(SPELL_OVERLOAD);
                            events.ScheduleEvent(EVENT_OVERLOAD, urand(40*IN_MILLISECONDS, 80*IN_MILLISECONDS));
                            return;
                        case EVENT_LIGHTNING_WHIRL:
                            DoCast(SPELL_LIGHTNING_WHIRL);
                            events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_THREAT_WIPE:
                            DoResetThreat();
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->AddThreat(target, std::numeric_limits<float>::max());
                                me->GetMotionMaster()->MovePoint(POINT_CHASE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            }
                            events.ScheduleEvent(EVENT_THREAT_WIPE, 10*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_START:
                            me->SetSpeed(MOVE_RUN, 0.7f);
                            Talk(SAY_BRUNDIR_FLIGHT);
                            DoCast(SPELL_LIGHTNING_TENDRILS);
                            DoCast(SPELL_LIGHTNING_TENDRILS_VISUAL);
                            me->AttackStop();

                            me->SetReactState(REACT_PASSIVE);
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                            me->SendMovementFlagUpdate();

                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(POINT_FLY, me->GetPositionX(), me->GetPositionY(), FinalPos.GetPositionZ());
                            events.DelayEvents(37*IN_MILLISECONDS);  // Flight phase is 35 seconds, +2 as buffer
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_NEW_TARGET, 2.5*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_ENDFLIGHT, 32.5*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_MOVE_POSITION, 1*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_FLIGHT_NEW_TARGET:
                            events.CancelEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET);
                            _tendrilTarget = 0;
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->GetMotionMaster()->MovePoint(POINT_FLY, target->GetPositionX(), target->GetPositionY(), FinalPos.GetPositionZ());
                                _tendrilTarget = target->GetGUID();
                            }
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_NEW_TARGET, 6*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET, 0.25*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _tendrilTarget))
                            {
                                me->StopMoving();
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MoveIdle();
                                me->GetMotionMaster()->MovePoint(POINT_FLY, player->GetPositionX(), player->GetPositionY(), FinalPos.GetPositionZ());
                            }
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET, 0.25*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_ENDFLIGHT:
                            events.CancelEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_NEW_TARGET);
                            events.CancelEvent(EVENT_LIGHTNING_TENDRILS_FLIGHT_UPDATE_TARGET);
                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(POINT_FLY, FinalPos.GetPositionX(), FinalPos.GetPositionY(), FinalPos.GetPositionZ());
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_LAND, 4*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_LAND:
                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(POINT_LAND, me->GetPositionX(), me->GetPositionY(), FLOOR_Z);
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_GROUND, 2.5*IN_MILLISECONDS);
                            return;
                        case EVENT_LIGHTNING_TENDRILS_GROUND:
                            me->SetSpeed(MOVE_RUN, 1.42857f);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                            me->SendMovementFlagUpdate();
                            me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS);
                            me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS_VISUAL);
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                            me->SendMovementFlagUpdate();
                            DoStartMovement(me->getVictim());
                            me->getThreatManager().resetAllAggro();
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_START, urand(40*IN_MILLISECONDS, 80*IN_MILLISECONDS));
                            events.CancelEvent(EVENT_MOVE_POSITION);
                            return;
                        case EVENT_MOVE_POSITION:
                            if (me->IsWithinMeleeRange(me->getVictim()))
                            {
                                float x = frand(-25.0f, 25.0f);
                                float y = frand(-25.0f, 25.0f);
                                me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + x, me->GetPositionY() + y, FLOOR_Z);
                                // Prevention to go outside the room or into the walls
                                if (Creature* trigger = me->FindNearestCreature(NPC_WORLD_TRIGGER, 100.0f, true))
                                    if (me->GetDistance(trigger) >= 50.0f)
                                        me->GetMotionMaster()->MovePoint(0, trigger->GetPositionX(), trigger->GetPositionY(), FLOOR_Z);
                            }
                            events.ScheduleEvent(EVENT_MOVE_POSITION, urand(7.5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }

                //if (me->GetPositionZ()>FLOOR_Z && !me->HasAura(SPELL_LIGHTNING_TENDRILS_VISUAL)) // in that case, we should not be above the floor
                //    me->GetMotionMaster()->MoveFall();

                if (!me->HasAura(SPELL_LIGHTNING_TENDRILS))
                    DoMeleeAttackIfReady();
            }

            private:
                uint32 _phase;
                uint8 _superChargedCnt;
                uint64 _tendrilTarget;
                bool _forceLand;
                bool _couldNotDoThat;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_stormcaller_brundirAI>(creature);
        }
};

class spell_shield_of_runes : public SpellScriptLoader
{
    public:
        spell_shield_of_runes() : SpellScriptLoader("spell_shield_of_runes") {}

        class spell_shield_of_runes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shield_of_runes_AuraScript);

            void OnAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                uint32 damage = dmgInfo.GetDamage();

                if (absorbAmount > damage)
                    return;

                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, caster->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? SPELL_SHIELD_OF_RUNES_10_BUFF : SPELL_SHIELD_OF_RUNES_25_BUFF, true);
            }

            void Register()
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_shield_of_runes_AuraScript::OnAbsorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_shield_of_runes_AuraScript();
        }
};

class spell_assembly_meltdown : public SpellScriptLoader
{
    public:
        spell_assembly_meltdown() : SpellScriptLoader("spell_assembly_meltdown") {}

        class spell_assembly_meltdown_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_assembly_meltdown_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(BOSS_STEELBREAKER)))
                        Steelbreaker->AI()->DoAction(ACTION_ADD_CHARGE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_assembly_meltdown_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_assembly_meltdown_SpellScript();
        }
};

// Supercharge
const uint32 AssemblyMembers[] = 
{
    32867, // NPC_STEELBREAKER,
    32927, // NPC_RUNEMASTER_MOLGEIM,
    32857  // NPC_STORMCALLER_BRUNDIR,
};

struct IsNoAssemblyMember 
{
    bool operator()(const WorldObject* target) const
    {
        if (const Creature* creature = target->ToCreature())
        {
            /* What happens here:
            State before:
                *searchStart = AssemblyMembers[0]
                *searchEnd = AssembyMemebers[3] // Never reached
            State after "find" (worst case):
                *searchStart = AssemblyMembers[3]
                *searchEnd = AssembyMemebers[3] // Never reached
            Follows the ".end() always refers to the first invalid argument" idiom
            */
            if ( std::find(AssemblyMembers, AssemblyMembers + (sizeof(AssemblyMembers) / sizeof(uint32)), creature->GetOriginalEntry()) != (AssemblyMembers + (sizeof(AssemblyMembers) / sizeof(uint32))) )
                return false;
            else
                return true;
        }
        else
            return true;
    }
};

class spell_supercharge : public SpellScriptLoader
{
    public:
        spell_supercharge() : SpellScriptLoader("spell_supercharge") {}

        class spell_supercharge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_supercharge_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(IsNoAssemblyMember());
            }

            void Register()
            {              
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_supercharge_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_supercharge_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_supercharge_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_supercharge_SpellScript();
        }
};

class achievement_i_choose_you : public AchievementCriteriaScript
{
    public:
        achievement_i_choose_you(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* boss = target->ToCreature())
                if (boss->AI()->GetData(DATA_I_CHOOSE_YOU_PHASE_CHECK))
                    return true;

            return false;
        }
};

class achievement_but_i_am_on_your_side : public AchievementCriteriaScript
{
    public:
        achievement_but_i_am_on_your_side(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Creature* boss = target->ToCreature())
                if (boss->AI()->GetData(DATA_I_CHOOSE_YOU_PHASE_CHECK) && player->HasAura(SPELL_IRON_BOOT_FLASK))
                    return true;

            return false;
        }
};

class achievement_cant_do_that_while_stunned : public AchievementCriteriaScript
{
    public:
        achievement_cant_do_that_while_stunned(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* boss = target->ToCreature())
                if (boss->AI()->GetData(DATA_I_CHOOSE_YOU_PHASE_CHECK))
                    if (InstanceScript* instance = boss->GetInstanceScript())
                        if (Creature* brundir = ObjectAccessor::GetCreature(*boss, instance->GetData64(DATA_BRUNDIR)))
                            if (brundir->AI()->GetData(DATA_CANT_DO_THAT_WHILE_STUNNED))
                                return true;

            return false;
        }
};

void AddSC_boss_assembly_of_iron()
{
    new boss_steelbreaker();
    new boss_runemaster_molgeim();
    new boss_stormcaller_brundir();
    new mob_lightning_elemental();
    new mob_rune_of_summoning();
    new mob_rune_of_power();

    new spell_steelbreaker_static_disruption();
    new spell_steelbreaker_electrical_charge();
    new spell_shield_of_runes();
    new spell_assembly_meltdown();
    new spell_supercharge();

    new achievement_i_choose_you("achievement_i_choose_you");
    new achievement_i_choose_you("achievement_i_choose_you_25");
    new achievement_but_i_am_on_your_side("achievement_but_i_am_on_your_side");
    new achievement_but_i_am_on_your_side("achievement_but_i_am_on_your_side_25");
    new achievement_cant_do_that_while_stunned("achievement_cant_do_that_while_stunned");
    new achievement_cant_do_that_while_stunned("achievement_cant_do_that_while_stunned_25");
}

// Steelbreaker
#undef SPELL_STATIC_DISRUPTION 
#undef SPELL_OVERWHELMING_POWER 

// Molgeim
#undef SPELL_SHIELD_OF_RUNES_BUFF 

// Brundir
#undef SPELL_CHAIN_LIGHTNING
#undef SPELL_OVERLOAD 
#undef SPELL_LIGHTNING_WHIRL 
#undef SPELL_LIGHTNING_WHIRL_DMG 
#undef SPELL_LIGHTNING_TENDRILS 
