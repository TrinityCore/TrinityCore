/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "vortex_pinnacle.h"

enum Spells
{
    // Altairus
    SPELL_CALL_THE_WIND         = 88276,
    SPELL_CHILLING_BREATH       = 88322,
    SPELL_LIGHTNING_BLAST       = 88357,

    // Invisible Stalker
    SPELL_SAFE_AREA             = 88350,
    SPELL_CALL_THE_WIND_CHANNEL = 88772,

    // Air Current
    SPELL_CALL_THE_WIND_AURA    = 88244,
    SPELL_UPWIND_OF_ALTAIRUS    = 88282,
    SPELL_DOWNWIND_OF_ALTAIRUS  = 88286
};

enum Texts
{
    SAY_ANNOUNCE_CALL_THE_WIND      = 0,
    SAY_ANNOUNCE_LIGHTNING_BLAST    = 1
};

enum Events
{
    EVENT_CALL_THE_WIND = 1,
    EVENT_CHILLING_BREATH,
    EVENT_LIGHTNING_BLAST
};

enum Points
{
    POINT_TWISTER_MAX = 24
};

enum Data
{
    DATA_INVISIBLE_STALKER  = 0,
    DATA_AIR_CURRENT        = 1
};

Position const InvisibleStalkerPos = { -1216.12f, 64.026f, 734.2573f };
Position const platform = { -1213.83f, 62.99f, 735.2f, 0.0f };

Position const TwisterSpawnPoints[POINT_TWISTER_MAX] =
{
    { -1226.936f, 58.03993f, 734.2574f },
    { -1250.604f, 78.47916f, 729.8842f },
    { -1255.609f, 63.03125f, 729.05f   },
    { -1235.368f, 85.2691f,  732.747f  },
    { -1245.059f, 61.33333f, 732.6014f },
    { -1237.84f,  72.69965f, 734.2705f },
    { -1190.684f, 69.16666f, 734.2564f },
    { -1194.172f, 54.2066f,  734.2574f },
    { -1215.405f, 65.88541f, 734.2574f },
    { -1236.722f, 48.6632f,  734.2571f },
    { -1193.104f, 82.77431f, 737.7465f },
    { -1210.278f, 80.68056f, 734.2574f },
    { -1202.799f, 68.46702f, 734.2574f },
    { -1224.179f, 76.04688f, 734.2574f },
    { -1244.069f, 92.11979f, 729.0458f },
    { -1211.163f, 53.77778f, 734.2574f },
    { -1198.332f, 106.1181f, 740.7894f },
    { -1203.602f, 93.05209f, 738.5089f },
    { -1242.745f, 37.7257f,  734.257f  },
    { -1219.642f, 93.82291f, 737.8855f },
    { -1223.229f, 40.89063f, 734.2574f },
    { -1211.016f, 105.4375f, 740.8424f },
    { -1189.568f, 95.77604f, 740.8668f },
    { -1204.863f, 40.49826f, 734.2564f }
};

struct boss_altairus : public BossAI
{
    boss_altairus(Creature* creature) : BossAI(creature, DATA_ALTAIRUS)
    {
        me->SetHover(true);
        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_CALL_THE_WIND, 6s);

        events.ScheduleEvent(EVENT_CHILLING_BREATH, 15000);
        events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 1000);

        if (Creature* stalker = DoSummon(NPC_INVISIBLE_STALKER, InvisibleStalkerPos))
        {
            stalker->CastSpell(stalker, SPELL_SAFE_AREA);
            _invisibleStalkerGUID = stalker->GetGUID();
        }

        if (IsHeroic())
        {
            for (int8 i = 0; i < POINT_TWISTER_MAX; i++)
            {
                if (Creature* twister = me->SummonCreature(NPC_TWISTER, TwisterSpawnPoints[i]))
                {
                    twister->SetHover(true);
                    twister->GetMotionMaster()->MoveRandom(10.0f);
                }
            }
        }

    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void SetGUID(ObjectGuid const& guid, int32 data) override
    {
        if (data == DATA_AIR_CURRENT)
        {
            // Cleaning up last air current stalker
            if (Creature* oldAirCurrent = ObjectAccessor::GetCreature(*me, _airCurrentGUID))
                oldAirCurrent->RemoveAllAuras();

            // Setting new air current guid
            _airCurrentGUID = guid;

            // Turn the invisible stalker towards the new stalker
            if (Creature* stalker = ObjectAccessor::GetCreature(*me, _invisibleStalkerGUID))
            {
                stalker->m_Events.AddEventAtOffset([stalker, guid]()
                {
                    if (Creature* airCurrent = ObjectAccessor::GetCreature(*stalker, guid))
                    {
                        stalker->SetFacingToObject(airCurrent);
                        stalker->m_Events.AddEventAtOffset([stalker]()
                        {
                            stalker->CastSpell(stalker, SPELL_CALL_THE_WIND_CHANNEL);
                        }, 1s + 200ms);
                    }
                }, 400ms);
            }
        }
    }

    ObjectGuid GetGUID(int32 data) const override
    {
        if (data == DATA_AIR_CURRENT)
            return _airCurrentGUID;

        return ObjectGuid::Empty;
    }

    void UpdateAI(uint32 diff) override
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
                case EVENT_CALL_THE_WIND:
                    DoCastAOE(SPELL_CALL_THE_WIND);
                    Talk(SAY_ANNOUNCE_CALL_THE_WIND);
                    events.Repeat(20s, 24s);
                    break;
                case EVENT_CHILLING_BREATH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHILLING_BREATH);
                    events.ScheduleEvent(EVENT_CHILLING_BREATH, 13000);
                    break;
                case EVENT_LIGHTNING_BLAST:
                    events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 5000);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    ObjectGuid _invisibleStalkerGUID;
    ObjectGuid _airCurrentGUID;
};

// 88276 - Call The Wind
class spell_altairus_call_the_wind : public SpellScript
{
    PrepareSpellScript(spell_altairus_call_the_wind);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CALL_THE_WIND_AURA });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_CALL_THE_WIND_AURA));
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_CALL_THE_WIND_AURA);

        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->SetGUID(target->GetGUID(), DATA_AIR_CURRENT);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_altairus_call_the_wind::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_altairus_call_the_wind::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 88282 - Upwind of Altairus
class spell_altairus_upwind_of_altairus : public SpellScript
{
    PrepareSpellScript(spell_altairus_upwind_of_altairus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DOWNWIND_OF_ALTAIRUS,
                SPELL_UPWIND_OF_ALTAIRUS
            });
    }

    void HandleUpwind(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();

        if (std::abs(caster->GetOrientation() - target->GetOrientation()) > (float(M_PI) / 2))
            target->RemoveAurasDueToSpell(SPELL_DOWNWIND_OF_ALTAIRUS);
        else
        {
            PreventHitDefaultEffect(EFFECT_0);
            PreventHitDefaultEffect(EFFECT_1);
            target->RemoveAurasDueToSpell(SPELL_UPWIND_OF_ALTAIRUS);
            target->CastSpell(target, SPELL_DOWNWIND_OF_ALTAIRUS, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_altairus_upwind_of_altairus::HandleUpwind, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 88772 - Call the Wind
class spell_altairus_call_the_wind_channel : public SpellScript
{
    PrepareSpellScript(spell_altairus_call_the_wind_channel);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* altairus = instance->GetCreature(DATA_ALTAIRUS))
                if (Creature* trigger = ObjectAccessor::GetCreature(*GetCaster(), altairus->AI()->GetGUID(DATA_AIR_CURRENT)))
                    target = trigger;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_altairus_call_the_wind_channel::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// 88322 - Chilling Breath
class spell_altairus_chilling_breath : public SpellScript
{
    PrepareSpellScript(spell_altairus_chilling_breath);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_altairus_chilling_breath::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};
class spell_altairus_safe_area : public AuraScript
{
    PrepareAuraScript(spell_altairus_safe_area);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LIGHTNING_BLAST });
    }

    void HandleLightningBlast(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* altairus = instance->GetCreature(DATA_ALTAIRUS))
        {
            if (altairus->isDead())
                return;

            altairus->AI()->Talk(SAY_ANNOUNCE_LIGHTNING_BLAST, target);
            altairus->CastSpell(target, SPELL_LIGHTNING_BLAST, true);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_altairus_safe_area::HandleLightningBlast, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_altairus()
{
    RegisterVortexPinnacleCreatureAI(boss_altairus);
    RegisterSpellScript(spell_altairus_call_the_wind);
    RegisterSpellScript(spell_altairus_upwind_of_altairus);
    RegisterSpellScript(spell_altairus_call_the_wind_channel);
    RegisterSpellScript(spell_altairus_chilling_breath);
    RegisterAuraScript(spell_altairus_safe_area);
}
