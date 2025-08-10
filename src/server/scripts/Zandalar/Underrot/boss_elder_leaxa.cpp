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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "underrot.h"

enum LeaxaSpells
{
    SPELL_TAINT_OF_GHUUN                = 260685,
    SPELL_BLOOD_BOLT                    = 260879,
    SPELL_SANGUINE_FEAST                = 264747,
    SPELL_CREEPING_ROT_SELECTOR         = 260889,
    SPELL_CREEPING_ROT_SUMMON           = 260894,
    SPELL_CREEPING_ROT_SPAWN_VISUAL     = 260891,
    SPELL_CREEPING_ROT_AURA             = 261496,
    SPELL_CREEPING_ROT_PERIODIC_DMG     = 261498,
    SPELL_BLOOD_MIRROR_SELECTOR         = 264603,
    SPELL_BLOOD_MIRROR_MISSILE          = 264609
};

enum LeaxaEvents
{
    EVENT_BLOOD_BOLT        = 1,
    EVENT_CREEPING_ROT,
    EVENT_SANGUINE_FEAST,
    EVENT_BLOOD_MIRROR
};

enum LeaxaTexts
{
    SAY_AGGRO                   = 0,
    SAY_SANGUINE_FEAST          = 1,
    SAY_ROT_AND_WITHER          = 2,
    SAY_BLOOD_MIRROR            = 3,
    SAY_ANNOUNCE_BLOOD_MIRROR   = 4,
    SAY_DEATH                   = 5
};

enum LeaxaAnimKits
{
    ANIMKIT_BLOOD_EFFIGY_DEATH = 9798
};

// 131318 - Elder Leaxa
struct boss_elder_leaxa : public BossAI
{
    boss_elder_leaxa(Creature* creature) : BossAI(creature, DATA_ELDER_LEAXA) { }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        Talk(SAY_AGGRO);
        me->SetAIAnimKitId(0);
        events.ScheduleEvent(EVENT_BLOOD_BOLT, 1s);
        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_SANGUINE_FEAST, 8s);
        events.ScheduleEvent(EVENT_CREEPING_ROT, 12s);
        events.ScheduleEvent(EVENT_BLOOD_MIRROR, 17s);
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
            case EVENT_BLOOD_BOLT:
                DoCastVictim(SPELL_BLOOD_BOLT);
                events.ScheduleEvent(EVENT_BLOOD_BOLT, 6s);
                break;
            case EVENT_SANGUINE_FEAST:
                Talk(SAY_SANGUINE_FEAST);
                DoCastAOE(SPELL_SANGUINE_FEAST);
                events.ScheduleEvent(EVENT_SANGUINE_FEAST, 30s);
                break;
            case EVENT_CREEPING_ROT:
                Talk(SAY_ROT_AND_WITHER);
                DoCastAOE(SPELL_CREEPING_ROT_SELECTOR);
                events.ScheduleEvent(EVENT_CREEPING_ROT, 16s);
                break;
            case EVENT_BLOOD_MIRROR:
                Talk(SAY_BLOOD_MIRROR);
                Talk(SAY_ANNOUNCE_BLOOD_MIRROR);
                DoCastSelf(SPELL_BLOOD_MIRROR_SELECTOR);
                events.ScheduleEvent(EVENT_BLOOD_MIRROR, 47s);
                break;
            default:
                break;
        }
    }
};

// 134701 - Blood Effigy
struct npc_blood_effigy : public ScriptedAI
{
    npc_blood_effigy(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BLOOD_BOLT, 1s);
        _events.ScheduleEvent(EVENT_SANGUINE_FEAST, 8s);
        _events.ScheduleEvent(EVENT_CREEPING_ROT, 12s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SetAIAnimKitId(ANIMKIT_BLOOD_EFFIGY_DEATH);
        me->DespawnOrUnsummon(3s);
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
            case EVENT_BLOOD_BOLT:
                DoCastVictim(SPELL_BLOOD_BOLT);
                _events.ScheduleEvent(EVENT_BLOOD_BOLT, 2s);
                break;
            case EVENT_SANGUINE_FEAST:
                DoCastAOE(SPELL_SANGUINE_FEAST);
                _events.ScheduleEvent(EVENT_SANGUINE_FEAST, 30s);
                break;
            case EVENT_CREEPING_ROT:
                DoCastAOE(SPELL_CREEPING_ROT_SELECTOR);
                _events.ScheduleEvent(EVENT_CREEPING_ROT, 16s);
                break;
            default:
                break;
        }
    }
private:
    EventMap _events;
};

// 132398 - Blood Wave Stalker
struct npc_blood_wave_stalker : public ScriptedAI
{
    npc_blood_wave_stalker(Creature* creature) : ScriptedAI(creature) { }

    static constexpr float WALK_DISTANCE = 58.0f;

    void JustAppeared() override
    {
        DoCast(SPELL_CREEPING_ROT_AURA);

        float angle = me->GetOrientation();
        float destX = me->GetPositionX() + WALK_DISTANCE * std::cos(angle);
        float destY = me->GetPositionY() + WALK_DISTANCE * std::sin(angle);
        float destZ = me->GetPositionZ();
        Position walkDest(destX, destY, destZ);

        me->GetMotionMaster()->MovePoint(0, walkDest);
    }
};

// 264747 - Sanguine Feast
class spell_sanguine_feast_selector : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(GetHitUnit(), uint32(GetEffectInfo().CalcValue(caster)));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sanguine_feast_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260889 - Creeping Rot
class spell_creeping_rot_selector : public SpellScript
{
    static constexpr float SPAWN_DISTANCE = 5.0f;

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        // make sure spell is cast towards target and caster looks towards target
        caster->SetInFront(target);
        caster->SetFacingToObject(target);

        caster->CastSpell(target, SPELL_CREEPING_ROT_SUMMON);

        float angle = caster->GetOrientation();
        float destX = caster->GetPositionX() + SPAWN_DISTANCE * std::cos(angle);
        float destY = caster->GetPositionY() + SPAWN_DISTANCE * std::sin(angle);
        float destZ = caster->GetPositionZ();
        Position spawnVisualDest(destX, destY, destZ);
        caster->CastSpell(spawnVisualDest, SPELL_CREEPING_ROT_SPAWN_VISUAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_creeping_rot_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 261496 - Creeping Rot (Aura)
class spell_creeping_rot_aura : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Creature* creature = GetTarget()->ToCreature();
        if (!creature)
            return;

        creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_creeping_rot_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

static Position const MirrorSpawnPositions[] =
{
    { 879.79865f, 1222.6233f, 56.47815f  },
    { 856.184f,   1232.5435f, 56.52007f  },
    { 859.34204f, 1238.0243f, 56.520065f },
    { 857.8333f,  1220.6545f, 56.468567f },
    { 876.17365f, 1240.2848f, 56.409615f },
    { 864.25867f, 1240.5903f, 56.520065f },
    { 863.1042f,  1218.0591f, 56.468765f }
};

// 264603 - Blood Mirror
class spell_blood_mirror_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_MIRROR_MISSILE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Position spawnPos = Trinity::Containers::SelectRandomContainerElement(MirrorSpawnPositions);
        GetCaster()->CastSpell(spawnPos, SPELL_BLOOD_MIRROR_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blood_mirror_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260879 - Blood Bolt
// 264757 - Sanguine Feast
// 261498 - Creeping Rot
class spell_taint_of_ghuun : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TAINT_OF_GHUUN });
    }

    void HandleHit()
    {
        InstanceScript* instance = GetHitUnit()->GetInstanceScript();
        if (!instance)
            return;

        Creature* leaxa = instance->GetCreature(DATA_ELDER_LEAXA);
        if (!leaxa)
            return;

        leaxa->CastSpell(GetHitUnit(), SPELL_TAINT_OF_GHUUN, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_taint_of_ghuun::HandleHit);
    }
};

void AddSC_boss_elder_leaxa()
{
    // Creature
    RegisterUnderrotCreatureAI(boss_elder_leaxa);
    RegisterUnderrotCreatureAI(npc_blood_wave_stalker);
    RegisterUnderrotCreatureAI(npc_blood_effigy);

    // Spells
    RegisterSpellScript(spell_sanguine_feast_selector);
    RegisterSpellScript(spell_creeping_rot_selector);
    RegisterSpellScript(spell_creeping_rot_aura);
    RegisterSpellScript(spell_blood_mirror_selector);
    RegisterSpellScript(spell_taint_of_ghuun);
}
