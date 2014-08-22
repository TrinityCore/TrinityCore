/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_HARDMODE_ON                             = 1,
    SAY_MKII_ACTIVATE                           = 2,
    SAY_MKII_SLAY                               = 3,
    SAY_MKII_DEATH                              = 4,
    SAY_VX001_ACTIVATE                          = 5,
    SAY_VX001_SLAY                              = 6,
    SAY_VX001_DEATH                             = 7,
    SAY_AERIAL_ACTIVATE                         = 8,
    SAY_AERIAL_SLAY                             = 9,
    SAY_AERIAL_DEATH                            = 10,
    SAY_V07TRON_ACTIVATE                        = 11,
    SAY_V07TRON_SLAY                            = 12,
    SAY_V07TRON_DEATH                           = 13,
    SAY_BERSERK                                 = 14
};

enum ComputerYells
{
    SAY_SELF_DESTRUCT_INITIATED                 = 0,
    SAY_SELF_DESTRUCT_TERMINATED                = 1,
    SAY_SELF_DESTRUCT_10                        = 2,
    SAY_SELF_DESTRUCT_9                         = 3,
    SAY_SELF_DESTRUCT_8                         = 4,
    SAY_SELF_DESTRUCT_7                         = 5,
    SAY_SELF_DESTRUCT_6                         = 6,
    SAY_SELF_DESTRUCT_5                         = 7,
    SAY_SELF_DESTRUCT_4                         = 8,
    SAY_SELF_DESTRUCT_3                         = 9,
    SAY_SELF_DESTRUCT_2                         = 10,
    SAY_SELF_DESTRUCT_1                         = 11,
    SAY_SELF_DESTRUCT_FINALIZED                 = 12
};

enum Spells
{
    // Mimiron
    SPELL_WELD                                  = 63339, // Idle aura.
    SPELL_SEAT_1                                = 52391, // Cast on all vehicles, Cycled on MKII
    SPELL_SEAT_2                                = 63313, // Cast on MKII and VX-001, Cycled on MKII
    SPELL_SEAT_3                                = 63314, // Cast on MKII, Cycled on MKII
    SPELL_SEAT_5                                = 63316, // Cast on MKII and VX-001, Cycled on MKII
    SPELL_SEAT_6                                = 63344, // Cast on MKII
    SPELL_SEAT_7                                = 63345, // Cast on MKII
    SPELL_JETPACK                               = 63341,
    SPELL_DESPAWN_ASSAULT_BOTS                  = 64463, // only despawns assault bots... no equivalent spell for the other adds...
    SPELL_TELEPORT_VISUAL                       = 41232,
    SPELL_SLEEP_VISUAL_1                        = 64393,
    SPELL_SLEEP_VISUAL_2                        = 64394,

    // Leviathan MK II
    SPELL_FLAME_SUPPRESSANT_MK                  = 64570,
    SPELL_NAPALM_SHELL                          = 63666,
    SPELL_FORCE_CAST_NAPALM_SHELL               = 64539,
    SPELL_PLASMA_BLAST                          = 62997,
    SPELL_SCRIPT_EFFECT_PLASMA_BLAST            = 64542,
    SPELL_SHOCK_BLAST                           = 63631,
    SPELL_SHOCK_BLAST_AURA                      = 63632, // Deprecated? It is never cast.

    // VX-001
    SPELL_FLAME_SUPPRESSANT_VX                  = 65192,
    SPELL_SPINNING_UP                           = 63414,
    SPELL_HEAT_WAVE_AURA                        = 63679,
    SPELL_HAND_PULSE_LEFT                       = 64348,
    SPELL_HAND_PULSE_RIGHT                      = 64352,
    SPELL_MOUNT_MKII                            = 64387,
    SPELL_TORSO_DISABLED                        = 64120,

    // Aerial Command Unit
    SPELL_PLASMA_BALL_P1                        = 63689,
    SPELL_PLASMA_BALL_P2                        = 65647,
    SPELL_MOUNT_VX_001                          = 64388,

    // Proximity Mines
    SPELL_PROXIMITY_MINES                       = 63027, // Cast by Leviathan MK II
    SPELL_PROXIMITY_MINE_EXPLOSION              = 66351,
    SPELL_PROXIMITY_MINE_TRIGGER                = 65346,
    SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER       = 65345,
    SPELL_PERIODIC_PROXIMITY_AURA               = 65345,
    SPELL_SUMMON_PROXIMITY_MINE                 = 65347,

    // Rapid Burst
    SPELL_RAPID_BURST_LEFT                      = 63387,
    SPELL_RAPID_BURST_RIGHT                     = 64019,
    SPELL_RAPID_BURST                           = 63382, // Cast by VX-001
    SPELL_RAPID_BURST_TARGET_ME                 = 64841, // Cast by Burst Target
    SPELL_SUMMON_BURST_TARGET                   = 64840, // Cast by VX-001

    // Rocket Strike
    SPELL_SUMMON_ROCKET_STRIKE                  = 63036,
    SPELL_SCRIPT_EFFECT_ROCKET_STRIKE           = 63681, // Cast by Rocket (Mimiron Visual)
    SPELL_ROCKET_STRIKE                         = 64064, // Added in creature_template_addon
    SPELL_ROCKET_STRIKE_LEFT                    = 64402, // Cast by VX-001
    SPELL_ROCKET_STRIKE_BOTH                    = 65034, // Cast by VX-001

    // Flames
    SPELL_FLAMES_PERIODIC_TRIGGER               = 64561, // Added in creature_template_addon
    SPELL_SUMMON_FLAMES_SPREAD_TRIGGER          = 64562,
    SPELL_SUMMON_FLAMES_INITIAL                 = 64563,
    SPELL_SUMMON_FLAMES_SPREAD                  = 64564,
    SPELL_FLAMES                                = 64566,
    SPELL_SCRIPT_EFFECT_SUMMON_FLAMES_INITIAL   = 64567,

    // Frost Bomb
    SPELL_SCRIPT_EFFECT_FROST_BOMB              = 64623, // Cast by VX-001
    SPELL_FROST_BOMB_LINKED                     = 64624, // Added in creature_template_addon
    SPELL_FROST_BOMB_DUMMY                      = 64625,
    SPELL_SUMMON_FROST_BOMB                     = 64627, // Cast by VX-001
    SPELL_FROST_BOMB_EXPLOSION                  = 64626,
    SPELL_CLEAR_FIRES                           = 65354,

    // Bots
    SPELL_SUMMON_FIRE_BOT                       = 64622,
    SPELL_SUMMON_FIRE_BOT_DUMMY                 = 64621,
    SPELL_SUMMON_FIRE_BOT_TRIGGER               = 64620, // Cast by Areal Command Unit
    SPELL_DEAFENING_SIREN                       = 64616, // Added in creature_template_addon
    SPELL_FIRE_SEARCH_AURA                      = 64617, // Added in creature_template_addon
    SPELL_FIRE_SEARCH                           = 64618,
    SPELL_WATER_SPRAY                           = 64619,

    SPELL_SUMMON_JUNK_BOT                       = 63819,
    SPELL_SUMMON_JUNK_BOT_TRIGGER               = 63820, // Cast by Areal Command Unit
    SPELL_SUMMON_JUNK_BOT_DUMMY                 = 64398,

    SPELL_SUMMON_ASSAULT_BOT_TRIGGER            = 64425, // Cast by Areal Command Unit
    SPELL_SUMMON_ASSAULT_BOT_DUMMY              = 64426,
    SPELL_SUMMON_ASSAULT_BOT                    = 64427,
    SPELL_MAGNETIC_FIELD                        = 64668,

    SPELL_SUMMON_BOMB_BOT                       = 63811, // Cast by Areal Command Unit
    SPELL_BOMB_BOT_AURA                         = 63767, // Added in creature_template_addon

    // Miscellaneous
    SPELL_SELF_DESTRUCTION_AURA                 = 64610,
    SPELL_SELF_DESTRUCTION_VISUAL               = 64613,
    SPELL_NOT_SO_FRIENDLY_FIRE                  = 65040,
    SPELL_ELEVATOR_KNOCKBACK                    = 65096, // Cast by worldtrigger.
    SPELL_VEHICLE_DAMAGED                       = 63415,
    SPELL_EMERGENCY_MODE                        = 64582, // mkii, vx001, aerial, assault, junk
    SPELL_EMERGENCY_MODE_TURRET                 = 65101, // Cast by Leviathan MK II, only hits Leviathan MK II turret
    SPELL_SELF_REPAIR                           = 64383,
    SPELL_MAGNETIC_CORE                         = 64436,
    SPELL_MAGNETIC_CORE_VISUAL                  = 64438,
    SPELL_HALF_HEAL                             = 64188,
    SPELL_CLEAR_ALL_DEBUFFS                     = 34098, // TODO: make use of this spell...
    SPELL_FREEZE_ANIM_STUN                      = 63354, // used to prevent mkii from doing stuff?..
    SPELL_FREEZE_ANIM                           = 16245  // Idle aura. Freezes animation.
};

enum Data
{
    DATA_SETUP_MINE,
    DATA_SETUP_BOMB,
    DATA_SETUP_ROCKET,
    DATA_NOT_SO_FRIENDLY_FIRE,
    DATA_FIREFIGHTER,
    DATA_WATERSPRAY,
    DATA_MOVE_NEW
};

enum Events
{
    // Leviathan MK II
    EVENT_PROXIMITY_MINE = 1,
    EVENT_NAPALM_SHELL,
    EVENT_PLASMA_BLAST,
    EVENT_SHOCK_BLAST,
    EVENT_FLAME_SUPPRESSANT_MK,
    EVENT_MOVE_POINT_2,
    EVENT_MOVE_POINT_3,
    EVENT_MOVE_POINT_5,

    // VX-001
    EVENT_RAPID_BURST,
    EVENT_SPINNING_UP,
    EVENT_ROCKET_STRIKE,
    EVENT_HAND_PULSE,
    EVENT_FROST_BOMB,
    EVENT_FLAME_SUPPRESSANT_VX,
    EVENT_RELOAD,

    // Aerial Command Unit
    EVENT_SUMMON_FIRE_BOTS,
    EVENT_SUMMON_JUNK_BOT,
    EVENT_SUMMON_ASSAULT_BOT,
    EVENT_SUMMON_BOMB_BOT,

    // Mimiron
    EVENT_SUMMON_FLAMES,
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,

    EVENT_VX001_ACTIVATION_1,
    EVENT_VX001_ACTIVATION_2,
    EVENT_VX001_ACTIVATION_3,
    EVENT_VX001_ACTIVATION_4,
    EVENT_VX001_ACTIVATION_5,
    EVENT_VX001_ACTIVATION_6,
    EVENT_VX001_ACTIVATION_7,
    EVENT_VX001_ACTIVATION_8,
    EVENT_VX001_ACTIVATION_9,

    EVENT_AERIAL_ACTIVATION_1,
    EVENT_AERIAL_ACTIVATION_2,
    EVENT_AERIAL_ACTIVATION_3,
    EVENT_AERIAL_ACTIVATION_4,
    EVENT_AERIAL_ACTIVATION_5,
    EVENT_AERIAL_ACTIVATION_6,

    EVENT_VOL7RON_ACTIVATION_1,
    EVENT_VOL7RON_ACTIVATION_2,
    EVENT_VOL7RON_ACTIVATION_3,
    EVENT_VOL7RON_ACTIVATION_4,
    EVENT_VOL7RON_ACTIVATION_5,
    EVENT_VOL7RON_ACTIVATION_6,
    EVENT_VOL7RON_ACTIVATION_7,

    EVENT_OUTTRO_1,
    EVENT_OUTTRO_2,
    EVENT_OUTTRO_3,

    // Computer
    EVENT_SELF_DESTRUCT_10,
    EVENT_SELF_DESTRUCT_9,
    EVENT_SELF_DESTRUCT_8,
    EVENT_SELF_DESTRUCT_7,
    EVENT_SELF_DESTRUCT_6,
    EVENT_SELF_DESTRUCT_5,
    EVENT_SELF_DESTRUCT_4,
    EVENT_SELF_DESTRUCT_3,
    EVENT_SELF_DESTRUCT_2,
    EVENT_SELF_DESTRUCT_1,
    EVENT_SELF_DESTRUCT_FINALIZED,

    // Misc
    EVENT_MAGNETIC_FIELD,
    EVENT_SPREAD_FLAMES,
    EVENT_FROST_BOMB_EXPLOSION,
    EVENT_FROST_BOMB_CLEAR_FIRES,
    EVENT_PROXIMITY_MINE_ARM,
    EVENT_PROXIMITY_MINE_DETONATION,
    EVENT_SEARCH_FLAMES,
    EVENT_WATER_SPRAY
};

enum Actions
{
    DO_START_MKII,
    DO_HARDMODE_MKII,

    DO_ACTIVATE_VX001,
    DO_START_VX001,
    DO_HARDMODE_VX001,

    DO_ACTIVATE_AERIAL,
    DO_START_AERIAL,
    DO_HARDMODE_AERIAL,
    DO_DISABLE_AERIAL,
    DO_ENABLE_AERIAL,

    DO_ACTIVATE_V0L7R0N_1,
    DO_ACTIVATE_V0L7R0N_2,
    DO_ASSEMBLED_COMBAT, // All 3 parts use this action, its done on purpose.

    DO_ACTIVATE_HARD_MODE,
    DO_ACTIVATE_COMPUTER,
    DO_DEACTIVATE_COMPUTER,
    DO_ACTIVATE_SELF_DESTRUCT,

    DO_ENCOUNTER_DONE
};

enum Phases
{
    // Leviathan MK II
    PHASE_LEVIATHAN_SOLO = 1,
    PHASE_LEVIATHAN_ASSEMBLED,

    // VX-001
    PHASE_VX001_SOLO,
    PHASE_VX001_ASSEMBLED,

    // Aerial Command Unit
    PHASE_AERIAL_SOLO,
    PHASE_AERIAL_ASSEMBLED
};

uint32 const RepairSpells[4] =
{
    SPELL_SEAT_1,
    SPELL_SEAT_2,
    SPELL_SEAT_3,
    SPELL_SEAT_5
};

// 63801 Bomb Bot
class spell_mimiron_bomb_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_bomb_bot() : SpellScriptLoader("spell_mimiron_bomb_bot") { }

        class spell_mimiron_bomb_bot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_bomb_bot_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer()) 
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkii = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(DATA_LEVIATHAN_MK_II)))
                            mkii->AI()->SetData(DATA_SETUP_BOMB, 0);
            }

            void HandleDespawn(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                {
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                    target->DespawnOrUnsummon(1000);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_bomb_bot_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_bomb_bot_SpellScript::HandleDespawn, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_bomb_bot_SpellScript();
        }
};

// 65192 - Flame Suppressant, 65224 - Clear Fires, 65354 - Clear Fires, 64619 - Water Spray
class spell_mimiron_clear_fires : public SpellScriptLoader
{
    public:
        spell_mimiron_clear_fires() : SpellScriptLoader("spell_mimiron_clear_fires") { }

        class spell_mimiron_clear_fires_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_clear_fires_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (GetHitCreature())
                    GetHitCreature()->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_clear_fires_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_clear_fires_SpellScript();
        }
};

// 64463 - Despawn Assault Bots
class spell_mimiron_despawn_assault_bots : public SpellScriptLoader
{
    public:
        spell_mimiron_despawn_assault_bots() : SpellScriptLoader("spell_mimiron_despawn_assault_bots") { }

        class spell_mimiron_despawn_assault_bots_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_despawn_assault_bots_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitCreature())
                    GetHitCreature()->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_despawn_assault_bots_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_despawn_assault_bots_SpellScript();
        }
};

// 64618 - Fire Search
class spell_mimiron_fire_search : public SpellScriptLoader
{
    public:
        spell_mimiron_fire_search() : SpellScriptLoader("spell_mimiron_fire_search") { }
    
        class spell_mimiron_fire_search_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_fire_search_SpellScript);
            
            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WATER_SPRAY))
                    return false; 
                return true;
            }

            bool Load() override
            {
                _noTarget = false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                _noTarget = targets.empty();
                if (_noTarget)
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleAftercast()
            {
                if (_noTarget)
                    GetCaster()->GetMotionMaster()->MoveRandom(15.0f);
            }
 
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (UnitAI* ai = caster->GetAI())
                {
                    if (caster->GetDistance2d(GetHitUnit()) <= 15.0f && ai->GetData(DATA_WATERSPRAY))
                    {
                        caster->CastSpell(GetHitUnit(), SPELL_WATER_SPRAY, true);
                        ai->SetData(DATA_WATERSPRAY, 0);
                        ai->SetData(DATA_MOVE_NEW, 1);
                    }
                    else if (caster->GetAI()->GetData(DATA_MOVE_NEW))
                    {
                        caster->GetMotionMaster()->MoveChase(GetHitUnit());
                        ai->SetData(DATA_MOVE_NEW, 0);
                    }
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_mimiron_fire_search_SpellScript::HandleAftercast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_fire_search_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_fire_search_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:
            bool _noTarget;
        };
    
        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_fire_search_SpellScript();
        }
};

// 64436 - Magnetic Core
class spell_mimiron_magnetic_core : public SpellScriptLoader
{
    public:
        spell_mimiron_magnetic_core() : SpellScriptLoader("spell_mimiron_magnetic_core") { }

        class spell_mimiron_magnetic_core_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_magnetic_core_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* obj) { return obj->ToUnit() && (obj->ToUnit()->GetVehicleBase() || obj->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE)); });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_magnetic_core_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_magnetic_core_SpellScript();
        }

        class spell_mimiron_magnetic_core_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_magnetic_core_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_CORE_VISUAL))
                    return false; 
                return true;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->GetAI()->DoAction(DO_DISABLE_AERIAL);
                    target->CastSpell(target, SPELL_MAGNETIC_CORE_VISUAL, true);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->GetAI()->DoAction(DO_ENABLE_AERIAL);
                    target->RemoveAurasDueToSpell(SPELL_MAGNETIC_CORE_VISUAL);
                }
            }

            void OnRemoveSelf(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (TempSummon* summ = GetTarget()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_mimiron_magnetic_core_AuraScript::OnApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mimiron_magnetic_core_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mimiron_magnetic_core_AuraScript::OnRemoveSelf, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_magnetic_core_AuraScript();
        }
};

// 63667 - Napalm Shell
class spell_mimiron_napalm_shell : public SpellScriptLoader
{
    public:
        spell_mimiron_napalm_shell() : SpellScriptLoader("spell_mimiron_napalm_shell") { }

        class spell_mimiron_napalm_shell_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_napalm_shell_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NAPALM_SHELL))
                    return false; 
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (!targets.empty())
                    target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_NAPALM_SHELL);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_napalm_shell_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_napalm_shell_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_napalm_shell_SpellScript();
        }
};

// 63274 - P3Wx2 Laser Barrage -- HACK! Core will currently not set UNIT_FIELD_CHANNEL_OBJECT automatially if the spell targets more than a single target.
class spell_mimiron_p3wx2_laser_barrage : public SpellScriptLoader
{
    public:
        spell_mimiron_p3wx2_laser_barrage() : SpellScriptLoader("spell_mimiron_p3wx2_laser_barrage") { }

        class spell_mimiron_p3wx2_laser_barrage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_p3wx2_laser_barrage_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, GetHitUnit()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_p3wx2_laser_barrage_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_p3wx2_laser_barrage_SpellScript();
        }
};

// 64542 - Plasma Blast
class spell_mimiron_plasma_blast : public SpellScriptLoader
{
    public:
        spell_mimiron_plasma_blast() : SpellScriptLoader("spell_mimiron_plasma_blast") { }

        class spell_mimiron_plasma_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_plasma_blast_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PLASMA_BLAST))
                    return false; 
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetVehicleKit() != nullptr;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster()->GetVehicleKit()->GetPassenger(3))
                    caster->CastSpell(GetHitUnit(), SPELL_PLASMA_BLAST);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_plasma_blast_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_plasma_blast_SpellScript();
        }
};

// 66351 - Explosion
class spell_mimiron_proximity_explosion : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_explosion() : SpellScriptLoader("spell_mimiron_proximity_explosion") { }

        class spell_mimiron_proximity_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_explosion_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {                
                if (GetHitPlayer())
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkII = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(DATA_LEVIATHAN_MK_II)))
                            mkII->AI()->SetData(DATA_SETUP_MINE, 0);
            }

            void HandleAura(SpellEffIndex /*effIndex*/)
            {                
                GetCaster()->RemoveAurasDueToSpell(SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_explosion_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_explosion_SpellScript::HandleAura, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_explosion_SpellScript();
        }
};

// 63027 - Proximity Mines
class spell_mimiron_proximity_mines : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_mines() : SpellScriptLoader("spell_mimiron_proximity_mines") { }

        class spell_mimiron_proximity_mines_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_mines_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_PROXIMITY_MINE))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                for (uint8 i = 0; i < 10; ++i)
                    GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_PROXIMITY_MINE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_mines_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_mines_SpellScript();
        }
};

// 65346 - Proximity Mine
class spell_mimiron_proximity_trigger : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_trigger() : SpellScriptLoader("spell_mimiron_proximity_trigger") { }

        class spell_mimiron_proximity_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PROXIMITY_MINE_EXPLOSION))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetWorldObject());

                if (targets.empty())
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell((Unit*)NULL, SPELL_PROXIMITY_MINE_EXPLOSION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_proximity_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHit += SpellEffectFn(spell_mimiron_proximity_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_trigger_SpellScript();
        }
};

// 63382 - Rapid Burst
class spell_mimiron_rapid_burst : public SpellScriptLoader
{
    public:
        spell_mimiron_rapid_burst() : SpellScriptLoader("spell_mimiron_rapid_burst") { }

        class spell_mimiron_rapid_burst_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_rapid_burst_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_RAPID_BURST_LEFT) || !sSpellMgr->GetSpellInfo(SPELL_RAPID_BURST_RIGHT))
                    return false;
                return true;
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (TempSummon* summ = GetTarget()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (GetCaster())
                    GetCaster()->CastSpell(GetTarget(), aurEff->GetTickNumber() % 2 == 0 ? SPELL_RAPID_BURST_RIGHT : SPELL_RAPID_BURST_LEFT, true, NULL, aurEff);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_mimiron_rapid_burst_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_rapid_burst_AuraScript::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_rapid_burst_AuraScript();
        }
};

// 64402 - Rocket Strike, 65034 - Rocket Strike
class spell_mimiron_rocket_strike : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike() : SpellScriptLoader("spell_mimiron_rocket_strike") { }

        class spell_mimiron_rocket_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SCRIPT_EFFECT_ROCKET_STRIKE))
                    return false; 
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (m_scriptSpellId == SPELL_ROCKET_STRIKE_LEFT && GetCaster()->IsVehicle())
                    if (WorldObject* target = GetCaster()->GetVehicleKit()->GetPassenger(6))
                    {
                        targets.clear();
                        targets.push_back(target);
                    }
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell((Unit*)NULL, SPELL_SCRIPT_EFFECT_ROCKET_STRIKE, true, NULL, NULL, GetCaster()->GetGUID());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_rocket_strike_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_SpellScript();
        }
};

// 63041 - Rocket Strike
class spell_mimiron_rocket_strike_damage : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike_damage() : SpellScriptLoader("spell_mimiron_rocket_strike_damage") { }

        class spell_mimiron_rocket_strike_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_damage_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NOT_SO_FRIENDLY_FIRE))
                    return false; 
                return true;
            }

            void HandleAfterCast()
            {
                if (TempSummon* summ = GetCaster()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer()) 
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkii = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(DATA_LEVIATHAN_MK_II)))
                            mkii->AI()->SetData(DATA_SETUP_ROCKET, 0);
            }

            void HandleFriendlyFire(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell((Unit*)NULL, SPELL_NOT_SO_FRIENDLY_FIRE, true);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleAfterCast);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleFriendlyFire, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_damage_SpellScript();
        }
};

// 63681 - Rocket Strike
class spell_mimiron_rocket_strike_target_select : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike_target_select() : SpellScriptLoader("spell_mimiron_rocket_strike_target_select") { }

        class spell_mimiron_rocket_strike_target_select_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_target_select_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ROCKET_STRIKE))
                    return false; 
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (!targets.empty())
                    target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ROCKET_STRIKE, true, NULL, NULL, instance->GetData64(DATA_VX_001));
                GetCaster()->SetDisplayId(11686);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_rocket_strike_target_select_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_target_select_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_target_select_SpellScript();
        }
};

// 64383 - Self Repair
class spell_mimiron_self_repair : public SpellScriptLoader
{
    public:
        spell_mimiron_self_repair() : SpellScriptLoader("spell_mimiron_self_repair") { }

        class spell_mimiron_self_repair_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_self_repair_SpellScript);

            void HandleScript()
            {
                if (GetCaster()->GetAI())
                    GetCaster()->GetAI()->DoAction(DO_ASSEMBLED_COMBAT);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_mimiron_self_repair_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_self_repair_SpellScript();
        }
};

// 63414 - Spinning Up -- HACK! Core will currently not set UNIT_FIELD_CHANNEL_OBJECT automatially if the spell targets more than a single target.
// eff0 will hit both caster and target due to hack in spellmgr.cpp, it is necessary because caster will interrupt itself if aura is not active on caster.
class spell_mimiron_spinning_up : public SpellScriptLoader
{
    public:
        spell_mimiron_spinning_up() : SpellScriptLoader("spell_mimiron_spinning_up") { }

        class spell_mimiron_spinning_up_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_spinning_up_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit() != GetCaster())
                    GetCaster()->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, GetHitUnit()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_spinning_up_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_spinning_up_SpellScript();
        }
};

// 64426 - Summon Scrap Bot
class spell_mimiron_summon_assault_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_assault_bot() : SpellScriptLoader("spell_mimiron_summon_assault_bot") { }

        class spell_mimiron_summon_assault_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_assault_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ASSAULT_BOT))
                    return false; 
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_ASSAULT_BOT, false, NULL, aurEff, instance->GetData64(DATA_AERIAL_COMMAND_UNIT));
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_assault_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_assault_bot_AuraScript();
        }
};

// 64425 - Summon Scrap Bot Trigger
class spell_mimiron_summon_assault_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_assault_bot_target() : SpellScriptLoader("spell_mimiron_summon_assault_bot_target") { }

        class spell_mimiron_summon_assault_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_assault_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ASSAULT_BOT_DUMMY))
                    return false; 
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_ASSAULT_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_assault_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_assault_bot_target_SpellScript();
        }
};

// 64621 - Summon Fire Bot
class spell_mimiron_summon_fire_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_fire_bot() : SpellScriptLoader("spell_mimiron_summon_fire_bot") { }

        class spell_mimiron_summon_fire_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_fire_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_FIRE_BOT))
                    return false;

                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_FIRE_BOT, false, NULL, aurEff, instance->GetData64(DATA_AERIAL_COMMAND_UNIT));
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_fire_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_fire_bot_AuraScript();
        }
};

// 64620 - Summon Fire Bot Trigger
class spell_mimiron_summon_fire_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_fire_bot_target() : SpellScriptLoader("spell_mimiron_summon_fire_bot_target") { }

        class spell_mimiron_summon_fire_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_fire_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_FIRE_BOT_DUMMY))
                    return false; 
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_FIRE_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_fire_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_fire_bot_target_SpellScript();
        }
};

// 64562 - Summon Flames Spread Trigger
class spell_mimiron_summon_flames_spread : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_flames_spread() : SpellScriptLoader("spell_mimiron_summon_flames_spread") { }
 
        class spell_mimiron_summon_flames_spread_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_flames_spread_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                // Flames must chase the closest player
                WorldObject* target = targets.front();

                for (std::list<WorldObject*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    if (GetCaster()->GetDistance2d(*iter) < GetCaster()->GetDistance2d(target))
                        target = *iter;

                targets.clear();
                targets.push_back(target);
            }

            void OnHit(SpellEffIndex /*effIndex*/)
            {                
                GetCaster()->SetInFront(GetHitUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_summon_flames_spread_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_flames_spread_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_flames_spread_SpellScript();
        }

        class spell_mimiron_summon_flames_spread_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_flames_spread_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_FLAMES_SPREAD))
                    return false; 
                return true;
            }

            void HandleTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (caster->HasAura(SPELL_FLAMES_PERIODIC_TRIGGER))
                        caster->CastSpell(GetTarget(), SPELL_SUMMON_FLAMES_SPREAD, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_summon_flames_spread_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_flames_spread_AuraScript();
        }
};

// 64623 - Frost Bomb
class spell_mimiron_summon_frost_bomb_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_frost_bomb_target() : SpellScriptLoader("spell_mimiron_summon_frost_bomb_target") { }

        class spell_mimiron_summon_frost_bomb_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_frost_bomb_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_FROST_BOMB))
                    return false; 
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_FROST_BOMB, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_summon_frost_bomb_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_frost_bomb_target_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_frost_bomb_target_SpellScript();
        }
};

// 64398 - Summon Scrap Bot
class spell_mimiron_summon_junk_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_junk_bot() : SpellScriptLoader("spell_mimiron_summon_junk_bot") { }

        class spell_mimiron_summon_junk_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_junk_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_JUNK_BOT))
                    return false; 
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_JUNK_BOT, false, NULL, aurEff, instance->GetData64(DATA_AERIAL_COMMAND_UNIT));
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_junk_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_junk_bot_AuraScript();
        }
};

// 63820 - Summon Scrap Bot Trigger
class spell_mimiron_summon_junk_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_junk_bot_target() : SpellScriptLoader("spell_mimiron_summon_junk_bot_target") { }

        class spell_mimiron_summon_junk_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_junk_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_JUNK_BOT_DUMMY))
                    return false; 
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_JUNK_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_junk_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_junk_bot_target_SpellScript();
        }
};

// 63339 - Weld
class spell_mimiron_weld : public SpellScriptLoader
{
    public:
        spell_mimiron_weld() : SpellScriptLoader("spell_mimiron_weld") { }

        class spell_mimiron_weld_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_weld_AuraScript);

            void HandleTick(AuraEffect const* aurEff)
            {
                Unit* caster = GetTarget();
                if (Unit* vehicle = caster->GetVehicleBase())
                {
                    if (aurEff->GetTickNumber() % 5 == 0)
                        caster->CastSpell(vehicle, RepairSpells[urand(0, 3)]);
                    caster->SetFacingToObject(vehicle);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_weld_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_weld_AuraScript();
        }
};

void AddSC_boss_mimiron()
{
    new spell_mimiron_bomb_bot();
    new spell_mimiron_clear_fires();
    new spell_mimiron_despawn_assault_bots();
    new spell_mimiron_fire_search();
    new spell_mimiron_magnetic_core();
    new spell_mimiron_napalm_shell();
    new spell_mimiron_p3wx2_laser_barrage();
    new spell_mimiron_plasma_blast();
    new spell_mimiron_proximity_explosion();
    new spell_mimiron_proximity_mines();
    new spell_mimiron_proximity_trigger();
    new spell_mimiron_rapid_burst();
    new spell_mimiron_rocket_strike();
    new spell_mimiron_rocket_strike_damage();
    new spell_mimiron_rocket_strike_target_select();
    new spell_mimiron_self_repair();
    new spell_mimiron_spinning_up();
    new spell_mimiron_summon_assault_bot();
    new spell_mimiron_summon_assault_bot_target();
    new spell_mimiron_summon_fire_bot();
    new spell_mimiron_summon_fire_bot_target();
    new spell_mimiron_summon_flames_spread();
    new spell_mimiron_summon_frost_bomb_target();
    new spell_mimiron_summon_junk_bot();
    new spell_mimiron_summon_junk_bot_target();
    new spell_mimiron_weld();
}
