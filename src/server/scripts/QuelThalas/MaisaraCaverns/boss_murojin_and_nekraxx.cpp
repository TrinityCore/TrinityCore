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
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Position.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "maisara_caverns.h"

namespace Scripts::QuelThalas::MaisaraCaverns::MurojinAndNekraxx
{
    namespace Spells
    {
        // Muro'jin
        static constexpr uint32 FreezingTrapSelector        = 1260728;
        static constexpr uint32 FreezingTrapDummy           = 1260731;
        static constexpr uint32 FreezingTrapMissile         = 1260736;
        static constexpr uint32 FreezingTrapStun            = 1243741;
        static constexpr uint32 BarrageSelector             = 1260642;
        static constexpr uint32 BarrageAura                 = 1260643;
        static constexpr uint32 BarrageMissiles             = 1260701;
        static constexpr uint32 OpenWound                   = 1266488;
        static constexpr uint32 Harpoon                     = 1266483;
        static constexpr uint32 FlankingSpear               = 1266480;
        static constexpr uint32 FlankingSpearKnockback      = 1267200;
        static constexpr uint32 RevivePet                   = 1249789;
        static constexpr uint32 RevivePetHeal               = 1249793;
        static constexpr uint32 IcySlick                    = 1243751;
        static constexpr uint32 IcySlickDamage              = 1243752;

        // Nekraxx
        static constexpr uint32 DNT                         = 1260494;
        static constexpr uint32 BestialWrath                = 1249947;
        static constexpr uint32 FetidQuillstormSelector     = 1249474;
        static constexpr uint32 FetidQuillstormCharge       = 1249475;
        static constexpr uint32 FetidQuillstormArea         = 1243900;
        static constexpr uint32 FetidQuillstormVisual       = 1256157;
        static constexpr uint32 FetidQuillstormDamage       = 1256247;
        static constexpr uint32 InfectedPinions             = 1246666;
        static constexpr uint32 CarrionSwoopSelector        = 1249477;
        static constexpr uint32 CarrionSwoopAura            = 1249478;
        static constexpr uint32 CarrionSwoopAT              = 1249481;
        static constexpr uint32 CarrionSwoopRemoveAT        = 1249781;
        static constexpr uint32 CarrionSwoopCharge          = 1249479; // TARGET_UNK_151
        static constexpr uint32 CarrionSwoopDamage          = 1249638;
        static constexpr uint32 CarrionSwoopKnockback       = 1249669;
        static constexpr uint32 CarrionSwoopStun            = 1256387;
        static constexpr uint32 CoordinatedAssault          = 1249769;
        static constexpr uint32 CoordinatedAssaultKnockback = 1249986;
    }

    namespace Texts
    {
        // Muro'jin
        static constexpr uint8 Aggro                = 0;
        static constexpr uint8 FlankingSpear        = 1;
        static constexpr uint8 InfectedPinions      = 2;
        static constexpr uint8 FreezingTrap         = 3;
        static constexpr uint8 FetidQuillstorm      = 4;
        static constexpr uint8 Barrage              = 5;
        static constexpr uint8 BarrageWarning       = 6;
        static constexpr uint8 CarriornSwoop        = 7;
        static constexpr uint8 CoordinatedAssault   = 8;
        static constexpr uint8 Slay                 = 9;
        static constexpr uint8 NekraxxDied          = 10;
        static constexpr uint8 Died                 = 11;

        // Nekraxx
        static constexpr uint8 CarriornSwoopWarning = 0;
    }

    namespace Events
    {
        // Muro'jin
        static constexpr uint8 FreezingTrap    = 1;
        static constexpr uint8 Barrage         = 2;
        static constexpr uint8 FlankingSpear   = 3;

        // Nekraxx
        static constexpr uint8 FetidQuillstorm = 4;
        static constexpr uint8 InfectedPinions = 5;
        static constexpr uint8 CarrionSwoop    = 6;
    }

    namespace Actions
    {
        static constexpr uint8 MurojinStartIntro = 2;
    }

    namespace Misc
    {
        static constexpr uint32 FetidQuillstormVisualSpell = 169326;
        static constexpr uint32 FlyingPath                 = 24757200;
        static constexpr uint32 IntroPath                  = 24757201;
        static constexpr uint32 MurojinCombatPath          = 24757000;
        static constexpr uint8 PointLand                   = 0;
        static constexpr uint8 NekraxxPointCombat          = 1;
        static constexpr uint8 WaypointId                  = 1;
        static constexpr uint8 AnimTierLanding             = 7;
        static constexpr uint32 ConvoStart                 = 31838;
    }

    uint32 const MurojinAndNekraxx[2] =
    {
        DATA_MUROJIN,
        DATA_NEKRAXX
    };

    Position const NekraxxLandingPosition = {-914.7274f, 162.20312f, 99.76655f};
    Position const NekraxxCombatPosition = {-919.3368f, 165.42708f, 99.7619f};
    Position const MurojinCombatPosition = {-913.1424f, 156.8368f, 99.76655f};

    namespace
    {
        void DespawnMurojinAndNekraxx(InstanceScript* instance, EvadeReason why)
        {
            if (instance->GetBossState(DATA_MUROJIN_AND_NEKRAXX) == FAIL)
                return;

            instance->SetBossState(DATA_MUROJIN_AND_NEKRAXX, FAIL);

            for (uint32 bossesData : MurojinAndNekraxx)
            {
                if (Creature* murojinAndNekraxx = instance->GetCreature(bossesData))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, murojinAndNekraxx);
                    murojinAndNekraxx->AI()->EnterEvadeMode(why);
                }
            }
        }

        void MurojinAndNekraxxEncounterDone(InstanceScript* instance)
        {
            if (instance->GetBossState(DATA_MUROJIN_AND_NEKRAXX) == DONE)
                return;

            for (uint32 bossesData : MurojinAndNekraxx)
            {
                if (Creature* murojinAndNekraxx = instance->GetCreature(bossesData))
                {
                    if (murojinAndNekraxx->IsAlive())
                        return;
                }
            }

            instance->SetBossState(DATA_MUROJIN_AND_NEKRAXX, DONE);
        }
    }

struct MurojinAndNekraxxSharedAI : public BossAI
{
    MurojinAndNekraxxSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_MUROJIN_AND_NEKRAXX));
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnMurojinAndNekraxx(instance, why);

        events.Reset();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        for (uint32 bossesData : MurojinAndNekraxx)
        {
            if (Creature* murojinAndNekraxx = instance->GetCreature(bossesData))
            {
                if (!murojinAndNekraxx->IsAlive() || murojinAndNekraxx->IsInCombat())
                    continue;

                murojinAndNekraxx->AI()->DoZoneInCombat();
            }
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        MurojinAndNekraxxEncounterDone(instance);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 247570 - Muro'jin
struct boss_murojin : public MurojinAndNekraxxSharedAI
{
    boss_murojin(Creature* creature) : MurojinAndNekraxxSharedAI(creature, DATA_MUROJIN) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE) == DONE)
        {
            me->SetDisableGravity(false);
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->SetImmuneToPC(false);
            me->SetEmoteState(EMOTE_STATE_READY2HL);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(Texts::Slay);
    }

    void JustEngagedWith(Unit* who) override
    {
        MurojinAndNekraxxSharedAI::JustEngagedWith(who);
        Talk(Texts::Aggro);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        switch (spellInfo->Id)
        {
            case Spells::BarrageSelector:
            {
                Talk(Texts::BarrageWarning, target);
                Talk(Texts::Barrage);
                break;
            }
            case Spells::FlankingSpear:
            {
                Talk(Texts::FlankingSpear);
                break;
            }
            default:
                break;
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case Spells::FreezingTrapDummy:
            {
                Talk(Texts::FreezingTrap);
                break;
            }
            case Spells::CoordinatedAssault:
            {
                Talk(Texts::CoordinatedAssault);
                break;
            }
            default:
                break;
        }
    }

    void JustDied(Unit* killer) override
    {
        MurojinAndNekraxxSharedAI::JustDied(killer);

        if (Creature* nekraxx = instance->GetCreature(DATA_NEKRAXX))
            nekraxx->AI()->DoCastSelf(Spells::BestialWrath);
    }

    void DoAction(int32 action) override
    {
        if (action != Actions::MurojinStartIntro)
            return;

        scheduler.Schedule(800ms, [this](TaskContext /*context*/)
        {
            me->SetDisableGravity(false);
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->GetMotionMaster()->MovePath(Misc::MurojinCombatPath, false);
        });
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId != Misc::MurojinCombatPath)
            return;

        if (waypointId == Misc::WaypointId)
        {
            me->SetImmuneToPC(false);
            me->SetEmoteState(EMOTE_STATE_READY2HL);
            me->SetOrientation(me->GetOrientation());
            me->SetHomePosition(me->GetPosition());
        }
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(Events::FlankingSpear, 5s);
        events.ScheduleEvent(Events::FreezingTrap, 20s);
        events.ScheduleEvent(Events::Barrage, 36s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case Events::FreezingTrap:
            {
                DoCastSelf(Spells::FreezingTrapSelector);
                events.Repeat(62s);
                break;
            }
            case Events::Barrage:
            {
                DoCastSelf(Spells::BarrageSelector);
                events.Repeat(45s);
                break;
            }
            case Events::FlankingSpear:
            {
                DoCastSelf(Spells::Harpoon);
                events.Repeat(45s);
                break;
            }
            default:
                break;
        }
    }
};

// 247572 - Nekraxx
struct boss_nekraxx : public MurojinAndNekraxxSharedAI
{
    boss_nekraxx(Creature* creature) : MurojinAndNekraxxSharedAI(creature, DATA_NEKRAXX) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE) != DONE)
            me->GetMotionMaster()->MovePath(Misc::FlyingPath, true);
        else
            me->RemoveAurasDueToSpell(Spells::DNT);
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_NEKRAXX_INTRO)
            return;

        Creature* murojin = instance->GetCreature(DATA_MUROJIN);
        if (!murojin)
            return;

        Conversation::CreateConversation(Misc::ConvoStart, murojin, murojin->GetPosition(), ObjectGuid::Empty);

        instance->SetData(DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE, IN_PROGRESS);
        me->GetMotionMaster()->Clear();
        me->StopMoving();
        me->GetMotionMaster()->MovePath(Misc::IntroPath, false);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case Spells::InfectedPinions:
            {
                if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
                    murojin->AI()->Talk(Texts::InfectedPinions);
                break;
            }
            case Spells::FetidQuillstormArea:
            {
                if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
                    murojin->AI()->Talk(Texts::FetidQuillstorm);
                break;
            }
            default:
                break;
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        if (spellInfo->Id == Spells::CarrionSwoopSelector)
        {
            Talk(Texts::CarriornSwoopWarning, target);

            if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
                murojin->AI()->Talk(Texts::CarriornSwoop);
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId != Misc::IntroPath)
            return;

        if (waypointId == Misc::WaypointId)
        {
            me->GetMotionMaster()->MoveLand(Misc::PointLand, NekraxxLandingPosition, Misc::AnimTierLanding);

            scheduler.Schedule(800ms, [this](TaskContext context)
            {
                me->SetAnimTier(AnimTier::Ground, true);
                me->RemoveAurasDueToSpell(Spells::DNT);

                context.Schedule(2s, [this](TaskContext context)
                {
                    me->GetMotionMaster()->MovePoint(Misc::NekraxxPointCombat, NekraxxCombatPosition);

                    context.Schedule(800ms, [this](TaskContext context)
                    {
                        me->SetFacingTo(0.4854921f);
                        me->SetOrientation(me->GetOrientation());
                        me->SetHomePosition(me->GetPosition());

                        context.Schedule(400ms, [this](TaskContext /*context*/)
                        {
                            me->SetDisableGravity(false);
                            me->SetImmuneToPC(false);
                            instance->SetData(DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE, DONE);
                        });
                    });
                });
            });

            if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
                murojin->AI()->DoAction(Actions::MurojinStartIntro);
        }
    }

    void JustDied(Unit* killer) override
    {
        MurojinAndNekraxxSharedAI::JustDied(killer);

        if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
        {
            murojin->AI()->Talk(Texts::NekraxxDied);
            murojin->AI()->DoCast(me, Spells::RevivePet);
        }
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(Events::InfectedPinions, 12s);
        events.ScheduleEvent(Events::FetidQuillstorm, 28s);
        events.ScheduleEvent(Events::CarrionSwoop, 40s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case Events::FetidQuillstorm:
            {
                DoCastSelf(Spells::FetidQuillstormSelector);
                events.Repeat(45s);
                break;
            }
            case Events::InfectedPinions:
            {
                DoCastSelf(Spells::InfectedPinions);
                events.Repeat(46s);
                break;
            }
            case Events::CarrionSwoop:
            {
                DoCastSelf(Spells::CarrionSwoopSelector);
                events.Repeat(45s);
                break;
            }
            default:
                break;
        }
    }
};

// 1266483 - Harpoon
class spell_murojin_and_nekraxx_harpoon : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FlankingSpear });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster->GetThreatManager().GetCurrentVictim(), Spells::FlankingSpear, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_harpoon::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1260728 - Freezing Trap
class spell_murojin_and_nekraxx_freezing_trap_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FreezingTrapDummy });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::FreezingTrapDummy, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_freezing_trap_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1260731 - Freezing Trap
class spell_murojin_and_nekraxx_freezing_trap_missile : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FreezingTrapMissile });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(*GetHitDest(), Spells::FreezingTrapMissile, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_murojin_and_nekraxx_freezing_trap_missile::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1243741 - Freezing Trap
class spell_murojin_and_nekraxx_freezing_trap_stun : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::IcySlick });
    }

    void HandleDamage(AuraEffect const* /*aurEff*/ , AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetMap()->IsMythic() || target->GetMap()->IsMythicPlus())
        {
            if (GetCaster())
                target->CastSpell(target->GetPosition(), Spells::IcySlick, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_murojin_and_nekraxx_freezing_trap_stun::HandleDamage, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1260642 - Barrage
class spell_murojin_and_nekraxx_barrage_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::BarrageAura });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::BarrageAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_barrage_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1260643 - Barrage
class spell_murojin_and_nekraxx_barrage_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::BarrageMissiles });
    }

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();

        if (Unit* caster = GetCaster())
            caster->CastSpell(target->GetPosition(), Spells::BarrageMissiles, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_murojin_and_nekraxx_barrage_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 1266485 - Flanking Spear
class spell_murojin_and_nekraxx_flanking_spear : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ Spells::OpenWound, Spells::FlankingSpearKnockback });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::OpenWound, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(*GetHitDest(), Spells::FlankingSpearKnockback, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_flanking_spear::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHit += SpellEffectFn(spell_murojin_and_nekraxx_flanking_spear::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 1249789 - Revive Pet
class spell_murojin_and_nekraxx_revive_pet : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::RevivePetHeal });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, Spells::RevivePetHeal, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_revive_pet::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1249474 - Fetid Quillstorm
class spell_murojin_and_nekraxx_fetid_quillstorm_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FetidQuillstormCharge });
    }

    void HandleCharge(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::FetidQuillstormCharge, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_fetid_quillstorm_selector::HandleCharge, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1249475 - Fetid Quillstorm
class spell_murojin_and_nekraxx_fetid_quillstorm_charge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FetidQuillstormArea });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(*GetHitDest(), Spells::FetidQuillstormArea, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_murojin_and_nekraxx_fetid_quillstorm_charge::HandleHit, EFFECT_0, SPELL_EFFECT_JUMP_CHARGE);
    }
};

// 1243900 - Fetid Quillstorm
class spell_murojin_and_nekraxx_fetid_quillstorm : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ Spells::FetidQuillstormVisual });
    }

    void HandleCast()
    {
        for (uint8 i = 0; i < 65; ++i)
        {
            float randomAngle = frand(0.0f, 2.0f * float(M_PI));
            float randomDist = frand(5.0f, 60.0f);

            Unit* caster = GetCaster();
            Position pos = caster->GetPosition();
            caster->MovePosition(pos, randomDist, randomAngle);
            caster->CastSpell(pos, Spells::FetidQuillstormVisual, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_murojin_and_nekraxx_fetid_quillstorm::HandleCast);
    }
};

class FetidQuillstormDamageEvent : public BasicEvent
{
public:
    explicit FetidQuillstormDamageEvent(Unit* caster, Position dest, Spell* triggeringSpell) : _caster(caster), _dest(dest), _triggeringSpell(triggeringSpell) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _caster->CastSpell(_dest, Spells::FetidQuillstormDamage, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = _triggeringSpell
        });
        return true;
    }

private:
    Unit* _caster;
    Position _dest;
    Spell* _triggeringSpell;
};

// 1256157 - Fetid Quillstorm
class spell_murojin_and_nekraxx_fetid_quillstorm_visual : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ Spells::FetidQuillstormDamage });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Position const* pos = GetHitDest();

        caster->SendPlaySpellVisual(*pos, Misc::FetidQuillstormVisualSpell, 0, 0, 1.5f, true);
        caster->m_Events.AddEventAtOffset(new FetidQuillstormDamageEvent(caster, *pos, GetSpell()), 500ms);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_murojin_and_nekraxx_fetid_quillstorm_visual::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1249477 - Carrion Swoop
class spell_murojin_and_nekraxx_carrion_swoop_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ Spells::OpenWound, Spells::FlankingSpearKnockback });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::CarrionSwoopAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_carrion_swoop_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1249478 - Carrion Swoop
class spell_murojin_and_nekraxx_carrion_swoop_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::CarrionSwoopCharge });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), Spells::CarrionSwoopCharge, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_murojin_and_nekraxx_carrion_swoop_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1249669 - Carrion Swoop
class spell_murojin_and_nekraxx_carrion_swoop_knockback : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ Spells::CoordinatedAssault });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Unit* target = GetHitUnit();

        if (!target->GetMap()->IsMythic() || !target->GetMap()->IsMythicPlus())
            return;

        if (Creature* murojin = instance->GetCreature(DATA_MUROJIN))
            murojin->CastSpell(target, Spells::CoordinatedAssault, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_carrion_swoop_knockback::HandleHit, EFFECT_0, SPELL_EFFECT_KNOCK_BACK_DEST);
    }
};

// 1249989 - Coordinated Assault
class spell_murojin_and_nekraxx_coordinated_assault : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ Spells::CoordinatedAssaultKnockback });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::CoordinatedAssaultKnockback, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_murojin_and_nekraxx_coordinated_assault::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 1243731 - Freezing Trap
struct at_murojin_and_nekraxx_freezing_trap : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Creature* nekraxx = instance->GetCreature(DATA_NEKRAXX);
        if (!nekraxx || !nekraxx->HasAura(Spells::CarrionSwoopAT))
            return;

        if (!unit->IsPlayer() && unit != nekraxx)
            return;

        caster->CastSpell(unit, Spells::FreezingTrapStun, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        nekraxx->CastSpell(nekraxx, Spells::CarrionSwoopRemoveAT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        nekraxx->CastSpell(nekraxx, Spells::CarrionSwoopStun, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 1249481 - Carrion Swoop
struct at_murojin_and_nekraxx_carrion_swoop : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit->GetPosition(), Spells::CarrionSwoopKnockback, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        caster->CastSpell(unit, Spells::CarrionSwoopDamage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 1243752 - Icy Slick
struct at_murojin_and_nekraxx_icy_slick : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        // To-Do: this at should apply inertia too (NYI)
        caster->CastSpell(unit, Spells::IcySlickDamage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};
}

void AddSC_boss_murojin_and_nekraxx()
{
    using namespace Scripts::QuelThalas::MaisaraCaverns::MurojinAndNekraxx;

    RegisterMaisaraCavernsCreatureAI(boss_murojin);
    RegisterMaisaraCavernsCreatureAI(boss_nekraxx);

    RegisterSpellScript(spell_murojin_and_nekraxx_harpoon);
    RegisterSpellScript(spell_murojin_and_nekraxx_freezing_trap_selector);
    RegisterSpellScript(spell_murojin_and_nekraxx_freezing_trap_missile);
    RegisterSpellScript(spell_murojin_and_nekraxx_barrage_selector);
    RegisterSpellScript(spell_murojin_and_nekraxx_barrage_periodic);
    RegisterSpellScript(spell_murojin_and_nekraxx_flanking_spear);
    RegisterSpellScript(spell_murojin_and_nekraxx_revive_pet);
    RegisterSpellScript(spell_murojin_and_nekraxx_fetid_quillstorm_selector);
    RegisterSpellScript(spell_murojin_and_nekraxx_fetid_quillstorm_charge);
    RegisterSpellScript(spell_murojin_and_nekraxx_fetid_quillstorm);
    RegisterSpellScript(spell_murojin_and_nekraxx_fetid_quillstorm_visual);
    RegisterSpellScript(spell_murojin_and_nekraxx_carrion_swoop_selector);
    RegisterSpellScript(spell_murojin_and_nekraxx_carrion_swoop_aura);
    RegisterSpellScript(spell_murojin_and_nekraxx_carrion_swoop_knockback);
    RegisterSpellScript(spell_murojin_and_nekraxx_coordinated_assault);

    RegisterAreaTriggerAI(at_murojin_and_nekraxx_freezing_trap);
    RegisterAreaTriggerAI(at_murojin_and_nekraxx_carrion_swoop);
    RegisterAreaTriggerAI(at_murojin_and_nekraxx_icy_slick);
}
