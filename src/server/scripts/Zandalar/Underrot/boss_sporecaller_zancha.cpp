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
#include "CellImpl.h"
#include "Containers.h"
#include "Conversation.h"
#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "underrot.h"

enum SporecallerZanchaSpells
{
    // Intro
    SPELL_BOSS_3_INTRO                 = 280683,
    SPELL_INFUSION                     = 272104,

    SPELL_FESTERING_HARVEST            = 259888,
    SPELL_FESTERING_HARVEST_DAMAGE     = 259732,
    SPELL_BOUNDLESS_ROT                = 259830,
    SPELL_SHOCKWAVE                    = 272457,
    SPELL_UPHEAVAL_SELECTOR            = 259717,
    SPELL_UPHEAVAL_AURA                = 259718,
    SPELL_UPHEAVAL_SCRIPT_EFFECT       = 272511,
    SPELL_UPHEAVAL_MISSILE             = 274213,
    SPELL_UPHEAVAL_DAMAGE              = 259720,
    SPELL_DECAYING_SPORES              = 259714,
    SPELL_SPORE_POD_BEAM               = 259968,
    SPELL_VOLATILE_PODS                = 273271,
    SPELL_VOLATILE_PODS_VISUAL         = 273285,
    SPELL_VOLATILE_PODS_AREATRIGGER    = 273300,

    // Musashitake
    SPELL_ACHIEVEMENT_VISUAL           = 272773,
    SPELL_TELEPORT_BEHIND_YOU_SELECTOR = 272786,
    SPELL_TELEPORT                     = 272787,
    SPELL_THOUSAND_FOLD_BLADE          = 272864
};

enum SporecallerZanchaEvents
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_SHOCKWAVE,
    EVENT_UPHEAVAL,
    EVENT_VOLATILE_PODS,
    EVENT_BOUNDLESS_ROT,

    // Musashitake
    EVENT_TELEPORT
};

enum SporecallerZanchaTexts
{
    SAY_AGGRO             = 0,
    SAY_UPHEAVAL          = 1,
    SAY_FESTERING_HARVEST = 2,
    SAY_WIPE              = 3,
    SAY_KILL              = 4,
    SAY_DEATH             = 5,

    // Musashitake
    SAY_PERSONAL          = 0
};

enum SporecallerZanchaSummonGroups
{
    SUMMON_GROUP_ZANCHA_INTRO  = 0,
    SUMMON_GROUP_MUSASHITAKE   = 1,
    SUMMON_GROUP_VOLATILE_PODS = 2
};

enum SporecallerZanchaActions
{
    ACTION_INTRO = 1
};

enum SporecallerZanchaCreatures
{
    NPC_SPORE_POD   = 131597
};

enum MusashitakeMisc
{
    CONVERSATION_START = 8358
};

// 131383 - Sporecaller Zancha
struct boss_sporecaller_zancha : public BossAI
{
    boss_sporecaller_zancha(Creature* creature) : BossAI(creature, DATA_SPORECALLER_ZANCHA), _shockwaveCount(1), _upheavalCount(1), _volatilePodsCount(1) { }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_MUSASHITAKE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DEATH);
    }

    void Reset() override
    {
        _Reset();

        _shockwaveCount = 1;
        _upheavalCount = 1;
        _volatilePodsCount = 1;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();

        Talk(SAY_WIPE);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_BOUNDLESS_ROT);
        DoCastSelf(SPELL_FESTERING_HARVEST);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);

        if (IsHeroicOrHigher() || IsMythicPlus())
        {
            events.ScheduleEvent(EVENT_SHOCKWAVE, 10600ms);
            events.ScheduleEvent(EVENT_UPHEAVAL, 16600ms);
            events.ScheduleEvent(EVENT_VOLATILE_PODS, 21600ms);
        }
        else
        {
            events.ScheduleEvent(EVENT_SHOCKWAVE, 10500ms);
            events.ScheduleEvent(EVENT_UPHEAVAL, 16s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_INTRO)
            return;

        for (ObjectGuid summonGUID : summons)
        {
            if (Creature* defiler = ObjectAccessor::GetCreature(*me, summonGUID))
            {
                defiler->KillSelf();
                defiler->DespawnOrUnsummon(20s);
            }
        }
        me->SummonCreatureGroup(SUMMON_GROUP_MUSASHITAKE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_CHECK_ENERGY:
            {
                if (me->GetPower(POWER_ENERGY) >= 100)
                {
                    Talk(SAY_FESTERING_HARVEST);
                    DoCastSelf(SPELL_FESTERING_HARVEST_DAMAGE);
                    events.ScheduleEvent(EVENT_BOUNDLESS_ROT, 9s);
                    events.RescheduleEvent(EVENT_CHECK_ENERGY, 10s);
                }
                events.Repeat(500ms);
                break;
            }
            case EVENT_SHOCKWAVE:
            {
                DoCastSelf(SPELL_SHOCKWAVE);
                _shockwaveCount++;
                if (IsHeroicOrHigher() || IsMythicPlus())
                {
                    if (_shockwaveCount == 2)
                        events.Repeat(14600ms);
                    else if (_shockwaveCount == 3)
                        events.Repeat(45100ms);
                    else if (_shockwaveCount % 2 == 0)
                        events.Repeat(20700ms);
                    else
                        events.Repeat(30400ms);
                }
                else
                {
                    if (_shockwaveCount == 2)
                        events.Repeat(14600ms);
                    else if (_shockwaveCount == 4)
                        events.Repeat(30400ms);
                    else if (_shockwaveCount % 2 == 0)
                        events.Repeat(40100ms);
                    else
                        events.Repeat(15800ms);
                }
                break;
            }
            case EVENT_UPHEAVAL:
            {
                DoCastSelf(SPELL_UPHEAVAL_SELECTOR);
                _upheavalCount++;
                if (IsHeroicOrHigher() || IsMythicPlus())
                {
                    if (_upheavalCount == 3)
                        events.Repeat(24300ms);
                    else if (_upheavalCount % 2 == 0)
                        events.Repeat(20700ms);
                    else
                        events.Repeat(30400ms);
                }
                else
                {
                    if (_upheavalCount == 3)
                        events.Repeat(30400ms);
                    else if (_upheavalCount % 3 == 0)
                        events.Repeat(24300ms);
                    else
                        events.Repeat(15800ms);
                }
                break;
            }
            case EVENT_VOLATILE_PODS:
            {
                DoCastSelf(SPELL_VOLATILE_PODS);
                _volatilePodsCount++;
                if (_volatilePodsCount == 4)
                    events.Repeat(27900ms);
                else
                    events.Repeat(25500ms);
                break;
            }
            case EVENT_BOUNDLESS_ROT:
            {
                DoCastSelf(SPELL_BOUNDLESS_ROT);
                break;
            }
            default:
                break;
        }
    }

private:
    uint32 _shockwaveCount;
    uint32 _upheavalCount;
    uint32 _volatilePodsCount;
};

// 138740 - Musashitake
struct npc_sporecaller_zancha_musashitake : public ScriptedAI
{
    npc_sporecaller_zancha_musashitake(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if ((spellInfo->Id == SPELL_SHOCKWAVE || spellInfo->Id == SPELL_UPHEAVAL_DAMAGE) && me->HasReactState(REACT_PASSIVE))
        {
            if (IsHeroicOrHigher() || IsMythicPlus())
            {
                me->RemoveAurasDueToSpell(SPELL_ACHIEVEMENT_VISUAL);
                Conversation::CreateConversation(CONVERSATION_START, me, me->GetPosition(), ObjectGuid::Empty);
                me->SetUninteractible(false);
                me->RemoveUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);
                me->SetReactState(REACT_AGGRESSIVE);
                _events.ScheduleEvent(EVENT_TELEPORT, 3s);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_TELEPORT:
            {
                Talk(SAY_PERSONAL);
                DoCastSelf(SPELL_TELEPORT_BEHIND_YOU_SELECTOR);
                _events.Repeat(20s);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// 259717 - Upheaval
class spell_sporecaller_zancha_upheaval_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UPHEAVAL_AURA });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
        {
            creatureCaster->CastSpell(GetHitUnit(), SPELL_UPHEAVAL_AURA, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
            creatureCaster->AI()->Talk(SAY_UPHEAVAL, GetHitUnit());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_upheaval_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 259718 - Upheaval
class spell_sporecaller_zancha_upheaval_marker : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UPHEAVAL_SCRIPT_EFFECT });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_UPHEAVAL_SCRIPT_EFFECT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sporecaller_zancha_upheaval_marker::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 272511 - Upheaval
class spell_sporecaller_zancha_upheaval_script_effect : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UPHEAVAL_MISSILE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_UPHEAVAL_MISSILE, TRIGGERED_IGNORE_CAST_TIME);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_upheaval_script_effect::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 259888 - Festering Harvest
class spell_sporecaller_zancha_festering_harvest : public AuraScript
{
    static constexpr std::array<uint8, 5> SporecallerEnergizeCycle = { 2, 2, 2, 2, 3 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        uint8 cycleIdx = aurEff->GetTickNumber() % SporecallerEnergizeCycle.size();
        GetTarget()->ModifyPower(POWER_ENERGY, SporecallerEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sporecaller_zancha_festering_harvest::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 259732 - Festering Harvest
class spell_sporecaller_zancha_festering_harvest_pods_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPORE_POD_BEAM });
    }

    void OnPrecast() override
    {
        std::list<Creature*> sporePods;
        Trinity::AllCreaturesOfEntryInRange checker(GetCaster(), NPC_SPORE_POD, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(GetCaster(), sporePods, checker);
        Cell::VisitAllObjects(GetCaster(), searcher, 200.0f);

        if (sporePods.empty())
            return;

        for (Creature* spore : sporePods)
        {
            spore->CastSpell(spore, SPELL_SPORE_POD_BEAM, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override { }
};

// 259845 - Boundless Rot
class spell_sporecaller_zancha_boundless_rot : public SpellScript
{
    static constexpr Position CenterPosition = { 1032.9444f, 1058.2899f, 33.330894f };

    static void SetDest(SpellScript const&, SpellDestination& dest)
    {
        dest.Relocate(CenterPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_sporecaller_zancha_boundless_rot::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 273271 - Volatile Pods
class spell_sporecaller_zancha_volatile_pods : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            creatureCaster->SummonCreatureGroup(SUMMON_GROUP_VOLATILE_PODS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_volatile_pods::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 273285 - Volatile Pods
class spell_sporecaller_zancha_volatile_pods_explosion : public SpellScript
{
    static constexpr uint8 MAX_VOLATILE_PODS = 6;

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();

        for (uint8 i = 0; i < MAX_VOLATILE_PODS; ++i)
        {
            float angle = target->GetOrientation() + float(M_PI) / 6.0f + i * float(M_PI) / 3.0f;
            Position dest(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), angle);
            target->CastSpell(dest, SPELL_VOLATILE_PODS_AREATRIGGER, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_volatile_pods_explosion::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 272786 - Teleport Behind You
class spell_sporecaller_zancha_musashitake_teleport_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_TELEPORT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_musashitake_teleport_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 272787 - Teleport
class spell_sporecaller_zancha_musashitake_teleport : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_THOUSAND_FOLD_BLADE });
    }

    void HandleTeleport(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_THOUSAND_FOLD_BLADE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sporecaller_zancha_musashitake_teleport::HandleTeleport, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

// 259727 - Boundless Rot
// ID - 12266
struct at_sporecaller_zancha_boundless_rot : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        player->CastSpell(player, SPELL_DECAYING_SPORES, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        if (Creature* creatureCaster = caster->ToCreature())
            creatureCaster->DespawnOrUnsummon();
    }
};

// 273300 - Volatile Pods
// ID - 13726
struct at_sporecaller_zancha_volatile_pod : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        Position destPos = at->GetPosition();
        at->MovePositionToFirstCollision(destPos, 200.0f, 0.0f);

        PathGenerator path(at);
        path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), true);

        at->InitSplines(path.GetPath());
    }

    void OnDestinationReached() override
    {
        at->Remove();
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_DECAYING_SPORES, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// Id 100 - Areatrigger
struct at_sporecaller_zancha_intro : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* zancha = instance->GetCreature(DATA_SPORECALLER_ZANCHA))
        {
            if (zancha->IsAlive())
                zancha->SummonCreatureGroup(SUMMON_GROUP_ZANCHA_INTRO);
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Creature* zancha = instance->GetCreature(DATA_SPORECALLER_ZANCHA);
        if (!zancha || !zancha->IsAlive())
            return;

        zancha->AI()->DoAction(ACTION_INTRO);
        zancha->CastSpell(unit, SPELL_BOSS_3_INTRO);

        at->Remove();
    }
};

void AddSC_boss_sporecaller_zancha()
{
    RegisterUnderrotCreatureAI(boss_sporecaller_zancha);
    RegisterUnderrotCreatureAI(npc_sporecaller_zancha_musashitake);

    RegisterSpellScript(spell_sporecaller_zancha_upheaval_selector);
    RegisterSpellScript(spell_sporecaller_zancha_upheaval_marker);
    RegisterSpellScript(spell_sporecaller_zancha_upheaval_script_effect);
    RegisterSpellScript(spell_sporecaller_zancha_festering_harvest);
    RegisterSpellScript(spell_sporecaller_zancha_festering_harvest_pods_selector);
    RegisterSpellScript(spell_sporecaller_zancha_boundless_rot);
    RegisterSpellScript(spell_sporecaller_zancha_volatile_pods);
    RegisterSpellScript(spell_sporecaller_zancha_volatile_pods_explosion);

    // Musashitake
    RegisterSpellScript(spell_sporecaller_zancha_musashitake_teleport_selector);
    RegisterSpellScript(spell_sporecaller_zancha_musashitake_teleport);

    RegisterAreaTriggerAI(at_sporecaller_zancha_boundless_rot);
    RegisterAreaTriggerAI(at_sporecaller_zancha_volatile_pod);
    RegisterAreaTriggerAI(at_sporecaller_zancha_intro);
}
