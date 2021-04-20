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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "antorus_the_burning_throne.h"

enum Texts
{
    // Garothi Worldbreaker
    SAY_AGGRO                       = 0,
    SAY_DISENGAGE                   = 1,
    SAY_ANNOUNCE_APOCALYPSE_DRIVE   = 2,
    SAY_APOCALYPSE_DRIVE            = 3,
    SAY_ANNOUNCE_ERADICATION        = 4,
    SAY_FINISH_APOCALYPSE_DRIVE     = 5,
    SAY_DECIMATION                  = 6,
    SAY_ANNIHILATION                = 7,
    SAY_ANNOUNCE_FEL_BOMBARDMENT    = 8,
    SAY_SLAY                        = 9,
    SAY_DEATH                       = 10,

    // Decimator
    SAY_ANNOUNCE_DECIMATION         = 0
};

enum Spells
{
    // Garothi Worldbreaker
    SPELL_MELEE                                 = 248229,
    SPELL_APOCALYPSE_DRIVE                      = 244152,
    SPELL_APOCALYPSE_DRIVE_PERIODIC_DAMAGE      = 253300,
    SPELL_APOCALYPSE_DRIVE_FINAL_DAMAGE         = 240277,
    SPELL_ERADICATION                           = 244969,
    SPELL_EMPOWERED                             = 245237,
    SPELL_RESTORE_HEALTH                        = 246012,
    SPELL_ANNIHILATOR_CANNON_EJECT              = 245527,
    SPELL_DECIMATOR_CANNON_EJECT                = 245515,
    SPELL_FEL_BOMBARDMENT_SELECTOR              = 244150,
    SPELL_FEL_BOMBARDMENT_WARNING               = 246220,
    SPELL_FEL_BOMBARDMENT_DUMMY                 = 245219,
    SPELL_FEL_BOMBARDMENT_PERIODIC              = 244536,
    SPELL_CANNON_CHOOSER                        = 245124,
    SPELL_SEARING_BARRAGE_ANNIHILATOR           = 246368,
    SPELL_SEARING_BARRAGE_DECIMATOR             = 244395,
    SPELL_SEARING_BARRAGE_DUMMY_ANNIHILATOR     = 244398,
    SPELL_SEARING_BARRAGE_DUMMY_DECIMATOR       = 246369,
    SPELL_SEARING_BARRAGE_SELECTOR              = 246360,
    SPELL_SEARING_BARRAGE_DAMAGE_ANNIHILATOR    = 244400,
    SPELL_SEARING_BARRAGE_DAMAGE_DECIMATOR      = 246373,
    SPELL_CARNAGE                               = 244106,

    // Decimator
    SPELL_DECIMATION_SELECTOR                   = 244399,
    SPELL_DECIMATION_WARNING                    = 244410,
    SPELL_DECIMATION_CAST_VISUAL                = 245338,
    SPELL_DECIMATION_MISSILE                    = 244448,

    // Annihilator
    SPELL_ANNIHILATION_SUMMON                   = 244790,
    SPELL_ANNIHILATION_SELECTOR                 = 247572,
    SPELL_ANNIHILATION_DUMMY                    = 244294,
    SPELL_ANNIHILATION_DAMAGE_UNSPLITTED        = 244762,

    // Annihilation
    SPELL_ANNIHILATION_AREA_TRIGGER             = 244795,
    SPELL_ANNIHILATION_WARNING                  = 244799,

    // Garothi Worldbreaker (Surging Fel)
    SPELL_SURGING_FEL_AREA_TRIGGER              = 246655,
    SPELL_SURGING_FEL_DAMAGE                    = 246663

};

enum Events
{
    // Garothi Worldbreaker
    EVENT_REENGAGE_PLAYERS = 1,
    EVENT_FEL_BOMBARDMENT,
    EVENT_SEARING_BARRAGE,
    EVENT_CANNON_CHOOSER,
    EVENT_SURGING_FEL
};

enum Data
{
    DATA_LAST_FIRED_CANNON = 0
};

enum AnimKits
{
    ANIM_KIT_ID_CANNON_DESTROYED = 13264
};

constexpr uint8 MIN_TARGETS_SIZE = 2;
constexpr uint8 MAX_TARGETS_SIZE = 6;

enum Misc
{
    SUMMON_GROUP_ID_SURGING_FEL         = 0,
    ENCOUNTER_ID_GAROTHI_WORLDBREAKER   = 2076
};

namespace TargetHandler
{
    class VictimCheck
    {
        public:
            VictimCheck(Unit* caster, bool keepTank) : _caster(caster), _keepTank(keepTank) { }

            bool operator()(WorldObject* object)
            {
                Unit* unit = object->ToUnit();
                if (!unit)
                    return true;

                if (_caster->GetVictim() && _caster->GetVictim() != unit)
                    return _keepTank;

                return false;
            }
        private:
            Unit* _caster;
            bool _keepTank; // true = remove all nontank targets | false = remove current tank
    };

    void PreferNonTankTargetsAndResizeTargets(std::list<WorldObject*>& targets, Unit* caster)
    {
        if (targets.empty())
            return;

        std::list<WorldObject*> targetsCopy = targets;
        uint8 size = targetsCopy.size();
        // Selecting our prefered target size based on total targets (min 10 player: 2, max 30 player: 6)
        uint8 preferedSize = std::min<uint8>(std::max<uint8>(std::ceil(size / 5), MIN_TARGETS_SIZE), MAX_TARGETS_SIZE);

        // Now we get rid of the tank as these abilities prefer non-tanks above tanks as long as there are alternatives
        targetsCopy.remove_if(TargetHandler::VictimCheck(caster, false));

        // We have less available nontank targets than we want, include tanks
        if (targetsCopy.size() < preferedSize)
            Trinity::Containers::RandomResize(targets, preferedSize);
        else
        {
            // Our target list has enough alternative targets, resize
            Trinity::Containers::RandomResize(targetsCopy, preferedSize);
            targets = targetsCopy;
        }
    }
}

static constexpr uint32 const MaxApocalypseDriveCount = 2;
Position const AnnihilationCenterReferencePos = { -3296.72f, 9767.78f, -60.0f };

struct boss_garothi_worldbreaker : public BossAI
{
    boss_garothi_worldbreaker(Creature* creature) : BossAI(creature, DATA_GAROTHI_WORLDBREAKER)
    {
        Initialize();
        me->SetReactState(REACT_PASSIVE);
    }

    void Initialize()
    {
        SetCombatMovement(false);

        switch (GetDifficulty())
        {
            case DIFFICULTY_MYTHIC_RAID:
            case DIFFICULTY_HEROIC_RAID:
                _apocalypseDriveHealthLimit[0] = 65;
                _apocalypseDriveHealthLimit[1] = 35;
                break;
            case DIFFICULTY_NORMAL_RAID:
            case DIFFICULTY_LFR_NEW:
                _apocalypseDriveHealthLimit[0] = 60;
                _apocalypseDriveHealthLimit[1] = 20;
                break;
            default:
                break;
        }

        // Todo: move this section out of the ctor and remove the .clear call when dynamic spawns have been merged.
        _apocalypseDriveCount = 0;
        _searingBarrageSpellId = 0;
        _lastCanonEntry = NPC_DECIMATOR;
        _castEradication = false;
        _surgingFelDummyGuids.clear();
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->SummonCreatureGroup(SUMMON_GROUP_ID_SURGING_FEL);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_MELEE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_FEL_BOMBARDMENT, 9s);
        events.ScheduleEvent(EVENT_CANNON_CHOOSER, 8s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_DISENGAGE);
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        events.Reset();
        CleanupEncounter();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        CleanupEncounter();
        instance->SendBossKillCredit(ENCOUNTER_ID_GAROTHI_WORLDBREAKER);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_APOCALYPSE_DRIVE_FINAL_DAMAGE:
                if (_apocalypseDriveCount < MaxApocalypseDriveCount)
                    events.Reset();
                events.ScheduleEvent(EVENT_REENGAGE_PLAYERS, 3s + 500ms);
                HideCannons();
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(_apocalypseDriveHealthLimit[_apocalypseDriveCount], damage))
        {
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->InterruptNonMeleeSpells(true);
            me->SetFacingTo(me->GetHomePosition().GetOrientation());
            events.Reset();

            if (GetDifficulty() == DIFFICULTY_MYTHIC_RAID || GetDifficulty() == DIFFICULTY_HEROIC_RAID)
                events.ScheduleEvent(EVENT_SURGING_FEL, 8s);

            DoCastSelf(SPELL_APOCALYPSE_DRIVE);
            DoCastSelf(SPELL_APOCALYPSE_DRIVE_FINAL_DAMAGE);
            Talk(SAY_ANNOUNCE_APOCALYPSE_DRIVE);
            Talk(SAY_APOCALYPSE_DRIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            if (Creature* decimator = instance->GetCreature(DATA_DECIMATOR))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, decimator, 2);
                decimator->AddUnitFlag(UNIT_FLAG_IN_COMBAT);
                decimator->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            }

            if (Creature* annihilator = instance->GetCreature(DATA_ANNIHILATOR))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, annihilator, 2);
                annihilator->AddUnitFlag(UNIT_FLAG_IN_COMBAT);
                annihilator->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            }
            ++_apocalypseDriveCount;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_ANNIHILATION:
                summon->CastSpell(summon, SPELL_ANNIHILATION_WARNING);
                summon->CastSpell(summon, SPELL_ANNIHILATION_AREA_TRIGGER);
                break;
            case NPC_ANNIHILATOR:
            case NPC_DECIMATOR:
                summon->SetReactState(REACT_PASSIVE);
                break;
            case NPC_GAROTHI_WORLDBREAKER:
                _surgingFelDummyGuids.insert(summon->GetGUID());
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_DECIMATOR:
            case NPC_ANNIHILATOR:
                me->InterruptNonMeleeSpells(true);
                me->RemoveAurasDueToSpell(SPELL_APOCALYPSE_DRIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

                if (summon->GetEntry() == NPC_ANNIHILATOR)
                    _searingBarrageSpellId = SPELL_SEARING_BARRAGE_ANNIHILATOR;
                else
                    _searingBarrageSpellId = SPELL_SEARING_BARRAGE_DECIMATOR;

                if (_apocalypseDriveCount < MaxApocalypseDriveCount)
                    events.Reset();

                events.ScheduleEvent(EVENT_SEARING_BARRAGE, 3s + 500ms);
                events.ScheduleEvent(EVENT_REENGAGE_PLAYERS, 3s + 500ms);
                _castEradication = true;

                if (summon->GetEntry() == NPC_DECIMATOR)
                    DoCastSelf(SPELL_DECIMATOR_CANNON_EJECT);
                else
                    DoCastSelf(SPELL_ANNIHILATOR_CANNON_EJECT);

                me->PlayOneShotAnimKitId(ANIM_KIT_ID_CANNON_DESTROYED);
                HideCannons();
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_LAST_FIRED_CANNON)
            return _lastCanonEntry;

        return 0;
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_LAST_FIRED_CANNON)
            _lastCanonEntry = value;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !me->HasAura(SPELL_APOCALYPSE_DRIVE))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REENGAGE_PLAYERS:
                    DoCastSelf(SPELL_EMPOWERED);
                    DoCastSelf(SPELL_RESTORE_HEALTH);
                    if (_castEradication)
                    {
                        DoCastSelf(SPELL_ERADICATION);
                        Talk(SAY_ANNOUNCE_ERADICATION);
                        Talk(SAY_FINISH_APOCALYPSE_DRIVE);
                        _castEradication = false;
                    }
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_FEL_BOMBARDMENT, 20s);
                    events.ScheduleEvent(EVENT_CANNON_CHOOSER, 18s);
                    break;
                case EVENT_FEL_BOMBARDMENT:
                    DoCastAOE(SPELL_FEL_BOMBARDMENT_SELECTOR);
                    events.Repeat(20s);
                    break;
                case EVENT_SEARING_BARRAGE:
                    DoCastSelf(_searingBarrageSpellId);
                    break;
                case EVENT_CANNON_CHOOSER:
                    DoCastSelf(SPELL_CANNON_CHOOSER);
                    events.Repeat(16s);
                    break;
                case EVENT_SURGING_FEL:
                {
                    GuidSet guids = _surgingFelDummyGuids;
                    guids.erase(_lastSurgingFelDummyGuid);
                    _lastSurgingFelDummyGuid = Trinity::Containers::SelectRandomContainerElement(guids);
                    if (Creature* dummy = ObjectAccessor::GetCreature(*me, _lastSurgingFelDummyGuid))
                        dummy->CastSpell(dummy, SPELL_SURGING_FEL_AREA_TRIGGER);

                    events.Repeat(8s);
                    break;
                }
                default:
                    break;
            }
        }

        if (me->GetVictim() && me->GetVictim()->IsWithinMeleeRange(me))
            DoMeleeAttackIfReady();
        else
            DoSpellAttackIfReady(SPELL_CARNAGE);
    }
 private:
     uint8 _apocalypseDriveHealthLimit[MaxApocalypseDriveCount];
     uint8 _apocalypseDriveCount;
     uint32 _searingBarrageSpellId;
     uint32 _lastCanonEntry;
     bool _castEradication;
     ObjectGuid _lastSurgingFelDummyGuid;
     GuidSet _surgingFelDummyGuids;

     void CleanupEncounter()
     {
         if (Creature* decimator = instance->GetCreature(DATA_DECIMATOR))
             instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, decimator);

         if (Creature* annihilator = instance->GetCreature(DATA_ANNIHILATOR))
             instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, annihilator);

         instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DECIMATION_WARNING);
         instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEL_BOMBARDMENT_WARNING);
         instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEL_BOMBARDMENT_PERIODIC);
         summons.DespawnAll();
     }

     void HideCannons()
     {
         if (Creature* decimator = instance->GetCreature(DATA_DECIMATOR))
         {
             instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, decimator);
             decimator->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31));
         }

         if (Creature* annihilator = instance->GetCreature(DATA_ANNIHILATOR))
         {
             instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, annihilator);
             annihilator->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31));
         }
     }
};

struct at_garothi_annihilation : AreaTriggerAI
{
    at_garothi_annihilation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        Initialize();
    }

    void Initialize()
    {
        _playerCount = 0;
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        _playerCount++;

        if (Unit* annihilation = at->GetCaster())
            annihilation->RemoveAurasDueToSpell(SPELL_ANNIHILATION_WARNING);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        _playerCount--;

        if (!_playerCount && !at->IsRemoved())
            if (Unit* annihilation = at->GetCaster())
                annihilation->CastSpell(annihilation, SPELL_ANNIHILATION_WARNING);
    }

private:
    uint8 _playerCount;
};

class spell_garothi_apocalypse_drive : public AuraScript
{
    PrepareAuraScript(spell_garothi_apocalypse_drive);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_APOCALYPSE_DRIVE_PERIODIC_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_APOCALYPSE_DRIVE_PERIODIC_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_garothi_apocalypse_drive::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_garothi_fel_bombardment_selector : public SpellScript
{
    PrepareSpellScript(spell_garothi_fel_bombardment_selector);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FEL_BOMBARDMENT_WARNING,
                SPELL_FEL_BOMBARDMENT_DUMMY
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (Unit* caster = GetCaster())
            targets.remove_if(TargetHandler::VictimCheck(caster, true));
    }

    void HandleWarningEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster() ? GetCaster()->ToCreature() : nullptr;
        if (!caster || !caster->IsAIEnabled)
            return;

        Unit* target = GetHitUnit();
        caster->AI()->Talk(SAY_ANNOUNCE_FEL_BOMBARDMENT, target);
        caster->CastSpell(target, SPELL_FEL_BOMBARDMENT_WARNING, true);
        caster->CastSpell(target, SPELL_FEL_BOMBARDMENT_DUMMY, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garothi_fel_bombardment_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_garothi_fel_bombardment_selector::HandleWarningEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_fel_bombardment_warning : public AuraScript
{
    PrepareAuraScript(spell_garothi_fel_bombardment_warning);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEL_BOMBARDMENT_PERIODIC });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (Unit* caster = GetCaster())
                caster->CastSpell(GetTarget(), SPELL_FEL_BOMBARDMENT_PERIODIC, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_garothi_fel_bombardment_warning::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_garothi_fel_bombardment_periodic : public AuraScript
{
    PrepareAuraScript(spell_garothi_fel_bombardment_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0)->BasePoints) });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), uint32(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints), true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_garothi_fel_bombardment_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_garothi_searing_barrage_dummy : public SpellScript
{
    PrepareSpellScript(spell_garothi_searing_barrage_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEARING_BARRAGE_SELECTOR });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SEARING_BARRAGE_SELECTOR, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, GetSpellInfo()->Id));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_searing_barrage_dummy::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_searing_barrage_selector : public SpellScript
{
    PrepareSpellScript(spell_garothi_searing_barrage_selector);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SEARING_BARRAGE_DAMAGE_ANNIHILATOR,
                SPELL_SEARING_BARRAGE_DAMAGE_DECIMATOR,
                SPELL_SEARING_BARRAGE_DUMMY_ANNIHILATOR,
                SPELL_SEARING_BARRAGE_DUMMY_DECIMATOR
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        TargetHandler::PreferNonTankTargetsAndResizeTargets(targets, GetCaster());
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = GetEffectValue() == SPELL_SEARING_BARRAGE_DUMMY_ANNIHILATOR ? SPELL_SEARING_BARRAGE_DAMAGE_ANNIHILATOR : SPELL_SEARING_BARRAGE_DAMAGE_DECIMATOR;
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garothi_searing_barrage_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_garothi_searing_barrage_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_decimation_selector : public SpellScript
{
    PrepareSpellScript(spell_garothi_decimation_selector);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DECIMATION_WARNING });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        TargetHandler::PreferNonTankTargetsAndResizeTargets(targets, GetCaster());
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetHitUnit(), SPELL_DECIMATION_WARNING, true);
            if (Creature* decimator = caster->ToCreature())
                if (decimator->IsAIEnabled)
                    decimator->AI()->Talk(SAY_ANNOUNCE_DECIMATION, GetHitUnit());
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garothi_decimation_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_garothi_decimation_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_decimation_warning : public AuraScript
{
    PrepareAuraScript(spell_garothi_decimation_warning);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DECIMATION_MISSILE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(GetTarget(), SPELL_DECIMATION_MISSILE, true);
                if (!caster->HasUnitState(UNIT_STATE_CASTING))
                    caster->CastSpell(caster, SPELL_DECIMATION_CAST_VISUAL);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_garothi_decimation_warning::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_garothi_carnage : public AuraScript
{
    PrepareAuraScript(spell_garothi_carnage);

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo`*/)
    {
        // Usually we could just handle this via spell_proc but since we want
        // to silence the console message because it's not a spell trigger proc, we need a script here.
        PreventDefaultAction();
        Remove();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_garothi_carnage::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_garothi_annihilation_selector : public SpellScript
{
    PrepareSpellScript(spell_garothi_annihilation_selector);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0)->BasePoints) });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), uint32(GetSpellInfo()->GetEffect(effIndex)->BasePoints), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_annihilation_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_annihilation_triggered : public SpellScript
{
    PrepareSpellScript(spell_garothi_annihilation_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANNIHILATION_DAMAGE_UNSPLITTED });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(SPELL_ANNIHILATION_WARNING))
            target->CastSpell(target, SPELL_ANNIHILATION_DAMAGE_UNSPLITTED, true);

        target->RemoveAllAuras();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_annihilation_triggered::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_garothi_eradication : public SpellScript
{
    PrepareSpellScript(spell_garothi_eradication);

    void ChangeDamage()
    {
        if (Unit* caster = GetCaster())
        {
            uint32 damageReduction = CalculatePct(GetHitDamage(), GetHitUnit()->GetDistance(caster));
            SetHitDamage(GetHitDamage() - damageReduction);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_garothi_eradication::ChangeDamage);
    }
};

class spell_garothi_surging_fel : public AuraScript
{
    PrepareAuraScript(spell_garothi_surging_fel);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGING_FEL_DAMAGE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetTarget()->CastSpell(GetTarget(), SPELL_SURGING_FEL_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_garothi_surging_fel::AfterRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_garothi_cannon_chooser : public SpellScript
{
    PrepareSpellScript(spell_garothi_cannon_chooser);

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetHitCreature();
        if (!caster || !caster->IsAIEnabled)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* decimator = instance->GetCreature(DATA_DECIMATOR);
        Creature* annihilator = instance->GetCreature(DATA_ANNIHILATOR);
        uint32 lastCannonEntry = caster->AI()->GetData(DATA_LAST_FIRED_CANNON);

        if ((lastCannonEntry == NPC_ANNIHILATOR && decimator) || (decimator && !annihilator))
        {
            decimator->CastSpell(decimator, SPELL_DECIMATION_SELECTOR, true);
            caster->AI()->Talk(SAY_DECIMATION, decimator);
            lastCannonEntry = NPC_DECIMATOR;
        }
        else if ((lastCannonEntry == NPC_DECIMATOR && annihilator) || (annihilator && !decimator))
        {
            uint8 count = caster->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? MAX_TARGETS_SIZE :
                std::max<uint8>(MIN_TARGETS_SIZE, std::ceil(float(caster->GetMap()->GetPlayersCountExceptGMs()) / 5));

            for (uint8 i = 0; i < count; i++)
            {
                float x = AnnihilationCenterReferencePos.GetPositionX() + cos(frand(0.0f, float(M_PI * 2))) * frand(15.0f, 30.0f);
                float y = AnnihilationCenterReferencePos.GetPositionY() + sin(frand(0.0f, float(M_PI * 2))) * frand(15.0f, 30.0f);
                float z = caster->GetMap()->GetHeight(caster->GetPhaseShift(), x, y, AnnihilationCenterReferencePos.GetPositionZ());
                annihilator->CastSpell({ x, y, z }, SPELL_ANNIHILATION_SUMMON, true);
            }

            annihilator->CastSpell(annihilator, SPELL_ANNIHILATION_DUMMY);
            annihilator->CastSpell(annihilator, SPELL_ANNIHILATION_SELECTOR);
            caster->AI()->Talk(SAY_ANNIHILATION);
            lastCannonEntry = NPC_ANNIHILATOR;
        }

        caster->AI()->SetData(DATA_LAST_FIRED_CANNON, lastCannonEntry);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_cannon_chooser::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_garothi_worldbreaker()
{
    RegisterAntorusTheBurningThroneCreatureAI(boss_garothi_worldbreaker);
    RegisterAreaTriggerAI(at_garothi_annihilation);
    RegisterAuraScript(spell_garothi_apocalypse_drive);
    RegisterSpellScript(spell_garothi_fel_bombardment_selector);
    RegisterAuraScript(spell_garothi_fel_bombardment_warning);
    RegisterAuraScript(spell_garothi_fel_bombardment_periodic);
    RegisterSpellScript(spell_garothi_searing_barrage_dummy);
    RegisterSpellScript(spell_garothi_searing_barrage_selector);
    RegisterSpellScript(spell_garothi_decimation_selector);
    RegisterAuraScript(spell_garothi_decimation_warning);
    RegisterAuraScript(spell_garothi_carnage);
    RegisterSpellScript(spell_garothi_annihilation_selector);
    RegisterSpellScript(spell_garothi_annihilation_triggered);
    RegisterSpellScript(spell_garothi_eradication);
    RegisterAuraScript(spell_garothi_surging_fel);
    RegisterSpellScript(spell_garothi_cannon_chooser);
}
