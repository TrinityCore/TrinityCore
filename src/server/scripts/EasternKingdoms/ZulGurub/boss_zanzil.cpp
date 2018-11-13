/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Spell.h"
#include "DynamicObject.h"
#include "zulgurub.h"

enum Yells
{
    // Zanzil
    SAY_AGGRO                           = 0,
    SAY_ANNOUNCE_ZANZIL_ZOMBIES         = 1,
    SAY_ZANZILI_ZOMBIES                 = 2,
    SAY_ANNOUNCE_ZANZILS_GRAVEYARD_GAS  = 3,
    SAY_ZANZILS_GRAVEYARD_GAS           = 4,
    SAY_ANNOUNCE_ZANZILI_BERSEKER       = 5,
    SAY_ZANZILI_BERSEKER                = 6,
    SAY_SLAY                            = 7,
    SAY_DEATH                           = 8,

    // Zanzili Berserker
    SAY_WHISPER_PURSUIT_PLAYER          = 0,
    SAY_ANNOUNCE_PURSUIT_PLAYER         = 1
};

enum Spells
{
    // Zanzil
    SPELL_ZANZILI_FIRE                          = 96914,
    SPELL_ZANZILI_FIRE_TRIGGERED                = 96916,
    SPELL_TERRIBLE_TONIC                        = 96348,
    SPELL_ZANZILS_RESURRECTION_ELIXIR_BLUE      = 96316,
    SPELL_ZANZILS_RESURRECTION_ELIXIR_TRIGGERED = 96317,
    SPELL_ZANZILS_RESURRECTION_ELIXIR_RED       = 96319,
    SPELL_ZANZILS_GRAVEYARD_GAS                 = 96338,

    // Zanzili Berserker
    SPELL_PURSUIT                               = 96342,
    SPELL_THUNDERCLAP                           = 96340,
    SPELL_KNOCK_AWAY                            = 96341,

    // Zanzil's Toxic Gas
    SPELL_TOXIC_GAS_SOUND                       = 96500,
    SPELL_GREEN_GAS                             = 97180
};

#define SPELL_VOODOO_BOLT                   RAID_MODE<uint32>(96346, 96347)
#define SPELL_ZANZILS_GRAVEYARD_GAS_DAMAGE  RAID_MODE<uint32>(96335, 96434)

enum Events
{
    // Zanzil
    EVENT_ZANZILI_FIRE = 1,
    EVENT_TERRIBLE_TONIC,
    EVENT_VOODOO_BOLT,
    EVENT_ZANZILS_SECRET_TECHNIQUE,
    EVENT_RESPAWN_ZOMBIE_GROUP,
    EVENT_RESPAWN_BERSERKER,
    EVENT_ZANZILS_GRAVEYARD_GAS_DAMAGE,
    EVENT_END_GRAVEYARD_GAS,

    // Zanzili Berserker
    EVENT_PURSUIT,
    EVENT_THUNDERCLAP,
    EVENT_KNOCK_AWAY
};

enum Actions
{
    // Zanzil
    ACTION_CAST_ZANZILI_FLAME = 1
};

enum SecretTechniques
{
    TECHNIQUE_NONE = 0,
    TECHNIQUE_BLUE_RESURRECTION_ELIXIR,
    TECHNIQUE_RED_RESURRECTION_ELIXIR,
    TECHNIQUE_GRAVEYARD_GAS
};

enum AIAnimKitId
{
    AI_ANIM_KIT_ID_NONE = 0
};

Position const ZanziliBerserkerPositions[] =
{
    { -11541.43f, -1298.149f, 85.2326f,  2.338741f },
    { -11544.98f, -1240.557f, 81.50435f, 3.926991f },
    { -11603.58f, -1233.599f, 81.3652f,  5.201081f }
};

Position const ZanziliZombieSpellDestinations[] =
{
    { -11540.43f, -1258.781f, 78.80729f },
    { -11588.05f, -1255.446f, 77.53773f },
    { -11588.19f, -1332.054f, 79.14419f },
    { -11615.35f, -1315.958f, 78.37769f }
};

Position const GreenGasStalkerPos = { -11572.96f, -1272.288f, 77.63614f };

class DelayedAttackStartEvent : public BasicEvent
{
    public:
        DelayedAttackStartEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->SetReactState(REACT_AGGRESSIVE);
            return true;
        }
    private:
        Creature* _owner;
};

struct boss_zanzil : public BossAI
{
    boss_zanzil(Creature* creature) : BossAI(creature, DATA_ZANZIL)
    {
        Initialize();
    }

    void Initialize()
    {
        _zanziliFireCount = 0;
        _zombieGroupToRespawn = 0;
        _berserkerToRespawn = 0;
        _lastSecretTechnique = TECHNIQUE_NONE;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->MakeInterruptable(false);

        for (uint8 i = 0; i < 5; i++)
            me->SummonCreatureGroup(i);

        for (uint8 i = 0; i < 3; i++)
            DoSummon(NPC_ZANZILI_BERSERKER, ZanziliBerserkerPositions[i], 4000);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_ZANZILI_FIRE, 13s, 14s);
        events.ScheduleEvent(EVENT_TERRIBLE_TONIC, 10s, 11s);
        events.ScheduleEvent(EVENT_VOODOO_BOLT, 1ms);
        events.ScheduleEvent(EVENT_ZANZILS_SECRET_TECHNIQUE, 15s, 16s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ZANZILS_GRAVEYARD_GAS_DAMAGE);

        for (ObjectGuid guid : _toxicGasGUIDs)
            if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                stalker->RemoveAllAuras();

        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ZANZILS_GRAVEYARD_GAS_DAMAGE);

        for (ObjectGuid guid : _toxicGasGUIDs)
            if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                stalker->RemoveAllAuras();

        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_ZANZILI_ZOMBIE:
            case NPC_ZANZILI_BERSERKER:
                summon->SetReactState(REACT_PASSIVE);
                break;
            case NPC_ZANZILS_TOXIC_GAS:
                _toxicGasGUIDs.push_back(summon->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_ZANZILI_FIRE:
                _zanzilPosition = me->GetPosition();
                break;
            default:
                break;
        }

        if (spell->Id == SPELL_VOODOO_BOLT)
            me->MakeInterruptable(false);
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_VOODOO_BOLT)
            me->MakeInterruptable(false);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CAST_ZANZILI_FLAME:
            {
                _zanziliFireCount++;
                float angle = _zanzilPosition.GetOrientation();
                float x = _zanzilPosition.GetPositionX() + cos(angle) * (2.0f * _zanziliFireCount);
                float y = _zanzilPosition.GetPositionY() + sin(angle) * (2.0f * _zanziliFireCount);
                float z = _zanzilPosition.GetPositionZ();

                if (_zanzilPosition.GetExactDist2d(x, y) <= 30.0f)
                    me->CastSpell(x, y, z, SPELL_ZANZILI_FIRE_TRIGGERED, true);
                else
                    me->RemoveAurasDueToSpell(SPELL_ZANZILI_FIRE);
                break;
            }
            default:
                break;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _reservedTargetGUIDs.push_back(guid);
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
                case EVENT_ZANZILI_FIRE:
                    _zanziliFireCount = 0;
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true, 0))
                        DoCast(target, SPELL_ZANZILI_FIRE);
                    events.Repeat(13s, 14s);
                    break;
                case EVENT_TERRIBLE_TONIC:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        DoCast(target, SPELL_TERRIBLE_TONIC);
                    events.Repeat(10s, 11s);
                    break;
                case EVENT_VOODOO_BOLT:
                    me->MakeInterruptable(true);
                    DoCastVictim(SPELL_VOODOO_BOLT);
                    events.Repeat(4s, 5s);
                    break;
                case EVENT_ZANZILS_SECRET_TECHNIQUE:
                {
                    me->InterruptNonMeleeSpells(true);
                    me->StopMoving();
                    events.RescheduleEvent(EVENT_ZANZILI_FIRE, 10s);
                    events.RescheduleEvent(EVENT_TERRIBLE_TONIC, 12s);
                    events.RescheduleEvent(EVENT_VOODOO_BOLT, 12s + 100ms);

                    SecretTechniques technique = RAND(TECHNIQUE_BLUE_RESURRECTION_ELIXIR, TECHNIQUE_GRAVEYARD_GAS);
                    // Make sure that we wont get the same technique twice
                    if (technique == _lastSecretTechnique)
                        technique = SecretTechniques(technique + 1);
                    if (technique > TECHNIQUE_GRAVEYARD_GAS)
                        technique = RAND(TECHNIQUE_BLUE_RESURRECTION_ELIXIR, TECHNIQUE_RED_RESURRECTION_ELIXIR);

                    switch (technique)
                    {
                        case TECHNIQUE_BLUE_RESURRECTION_ELIXIR:
                        {
                            Position nearestPos = ZanziliBerserkerPositions[0];
                            for (uint8 i = 1; i < 3; i++)
                            {
                                if (ZanziliBerserkerPositions[i].GetExactDist2d(me) < nearestPos.GetExactDist2d(me))
                                {
                                    nearestPos = ZanziliBerserkerPositions[i];
                                    _berserkerToRespawn = i;
                                }
                            }

                            Talk(SAY_ANNOUNCE_ZANZILI_BERSEKER);
                            Talk(SAY_ZANZILI_BERSEKER);
                            me->CastSpell(nearestPos.GetPositionX(), nearestPos.GetPositionY(), nearestPos.GetPositionZ(), SPELL_ZANZILS_RESURRECTION_ELIXIR_BLUE);
                            events.ScheduleEvent(EVENT_RESPAWN_BERSERKER, 13s);
                            break;
                        }
                        case TECHNIQUE_RED_RESURRECTION_ELIXIR:
                        {
                            _reservedTargetGUIDs.clear();
                            Position nearestPos = ZanziliZombieSpellDestinations[0];
                            for (uint8 i = 1; i < 4; i++)
                            {
                                if (ZanziliZombieSpellDestinations[i].GetExactDist2d(me) < nearestPos.GetExactDist2d(me))
                                {
                                    nearestPos = ZanziliZombieSpellDestinations[i];
                                    _zombieGroupToRespawn = i;
                                }
                            }

                            Talk(SAY_ANNOUNCE_ZANZIL_ZOMBIES);
                            Talk(SAY_ZANZILI_ZOMBIES);
                            me->CastSpell(nearestPos.GetPositionX(), nearestPos.GetPositionY(), nearestPos.GetPositionZ(), SPELL_ZANZILS_RESURRECTION_ELIXIR_RED);
                            events.ScheduleEvent(EVENT_RESPAWN_ZOMBIE_GROUP, 13s);
                            break;
                        }
                        case TECHNIQUE_GRAVEYARD_GAS:
                            _reservedTargetGUIDs.clear();
                            Talk(SAY_ANNOUNCE_ZANZILS_GRAVEYARD_GAS);
                            Talk(SAY_ZANZILS_GRAVEYARD_GAS);
                            DoCastSelf(SPELL_ZANZILS_GRAVEYARD_GAS);
                            events.ScheduleEvent(EVENT_END_GRAVEYARD_GAS, 21s);
                            events.ScheduleEvent(EVENT_ZANZILS_GRAVEYARD_GAS_DAMAGE, 9s + 500ms);
                            break;
                        default:
                            break;
                    }
                    _lastSecretTechnique = technique;
                    events.Repeat(30s);
                    break;
                }
                case EVENT_RESPAWN_ZOMBIE_GROUP:
                    me->SummonCreatureGroup(_zombieGroupToRespawn);
                    break;
                case EVENT_RESPAWN_BERSERKER:
                    DoSummon(NPC_ZANZILI_BERSERKER, ZanziliBerserkerPositions[_berserkerToRespawn], 4000);
                    break;
                case EVENT_END_GRAVEYARD_GAS:
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ZANZILS_GRAVEYARD_GAS_DAMAGE);
                    for (ObjectGuid guid : _toxicGasGUIDs)
                        if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                            stalker->RemoveAllAuras();
                    break;
                case EVENT_ZANZILS_GRAVEYARD_GAS_DAMAGE:
                    instance->DoCastSpellOnPlayers(SPELL_ZANZILS_GRAVEYARD_GAS_DAMAGE);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

    GuidVector const GetAlreadyTargetedObjectGuids()
    {
            return _reservedTargetGUIDs;
    }

private:
    Position _zanzilPosition;
    uint8 _zanziliFireCount;
    uint8 _zombieGroupToRespawn;
    uint8 _berserkerToRespawn;
    SecretTechniques _lastSecretTechnique;
    GuidVector _reservedTargetGUIDs;
    GuidVector _toxicGasGUIDs;
};

struct npc_zanzil_zanzili_berserker : public ScriptedAI
{
    npc_zanzil_zanzili_berserker(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _elixirHits = 0;
    }

    void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ZANZILS_RESURRECTION_ELIXIR_TRIGGERED)
        {
            _elixirHits++;
            if (_elixirHits == 5)
            {
                me->SetAIAnimKitId(0);
                me->GetMotionMaster()->MoveFall();
                me->SetDisableGravity(false);
                me->SendSetPlayHoverAnim(false);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_PURSUIT, 2s);
            }
        }
    }

    void SpellHitTarget(Unit* victim, const SpellInfo* spellInfo)
    {
        if (!victim)
            return;

        if (spellInfo->Id == SPELL_PURSUIT)
        {
            me->getThreatManager().resetAllAggro();
            me->AddThreat(victim, spellInfo->Effects[EFFECT_1].BasePoints);
            Talk(SAY_WHISPER_PURSUIT_PLAYER, victim);
            Talk(SAY_ANNOUNCE_PURSUIT_PLAYER, victim);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PURSUIT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true, 0))
                        DoCast(target, SPELL_PURSUIT);

                    _events.ScheduleEvent(EVENT_THUNDERCLAP, 7s);
                    _events.ScheduleEvent(EVENT_KNOCK_AWAY, 6s);
                    _events.Repeat(14s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastAOE(SPELL_THUNDERCLAP);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    uint8 _elixirHits;
};

class spell_zanzil_zanzili_fire : public AuraScript
{
    PrepareAuraScript(spell_zanzil_zanzili_fire);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Creature* zanzil = GetTarget()->ToCreature())
            if (zanzil->IsAIEnabled)
                zanzil->AI()->DoAction(ACTION_CAST_ZANZILI_FLAME);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_zanzil_zanzili_fire::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_zanzil_zanzils_resurrection_elixir : public AuraScript
{
    PrepareAuraScript(spell_zanzil_zanzils_resurrection_elixir);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ZANZILS_RESURRECTION_ELIXIR_BLUE,
                SPELL_ZANZILS_RESURRECTION_ELIXIR_RED
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        DynamicObject* object = GetTarget()->GetDynObject(SPELL_ZANZILS_RESURRECTION_ELIXIR_BLUE);
        if (!object)
            object = GetTarget()->GetDynObject(SPELL_ZANZILS_RESURRECTION_ELIXIR_RED);

        if (!object)
            return;

        GetTarget()->CastSpell(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_zanzil_zanzils_resurrection_elixir::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class UnusedGuidTargetSelector
{
    public:
        UnusedGuidTargetSelector(GuidVector reservedGuids) : _reservedGuids(reservedGuids) { }

        bool operator() (WorldObject* target)
        {
            for (ObjectGuid guid : _reservedGuids)
                if (guid == target->GetGUID())
                    return true;

            return false;
        }

        GuidVector _reservedGuids;
};

class spell_zanzil_zanzils_resurrection_elixir_red_script : public SpellScript
{
    PrepareSpellScript(spell_zanzil_zanzils_resurrection_elixir_red_script);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        // Create a backup which we are going to use if we have no unique target left anymore
        std::list<WorldObject*> targetsCopy = targets;

        // This is ugly as fuck but there is no other way to get already targeted zombies
        if (Creature* creature = GetCaster()->ToCreature())
            if (creature->IsAIEnabled)
                targets.remove_if(UnusedGuidTargetSelector(CAST_AI(boss_zanzil, creature->AI())->GetAlreadyTargetedObjectGuids()));

        if (targets.empty())
            targets = targetsCopy;

        Trinity::Containers::RandomResize(targets, 5);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
        {
            if (target->GetAIAnimKitId() == AI_ANIM_KIT_ID_NONE)
                return;

            target->SetAIAnimKitId(AI_ANIM_KIT_ID_NONE);
            target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);

            if (target->IsAIEnabled)
            {
                target->AI()->DoZoneInCombat();
                target->m_Events.AddEvent(new DelayedAttackStartEvent(target), target->m_Events.CalculateTime(3500));
            }
        }
    }

    void HandleGuidReservation(SpellEffIndex /*effIndex*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (caster->IsAIEnabled)
                if (Creature* target = GetHitCreature())
                    caster->AI()->SetGUID(target->GetGUID());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_zanzil_zanzils_resurrection_elixir_red_script::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_zanzil_zanzils_resurrection_elixir_red_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectLaunchTarget += SpellEffectFn(spell_zanzil_zanzils_resurrection_elixir_red_script::HandleGuidReservation, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_zanzil_zanzils_graveyard_gas : public SpellScript
{
    PrepareSpellScript(spell_zanzil_zanzils_graveyard_gas);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_TOXIC_GAS_SOUND,
                SPELL_GREEN_GAS
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        // Create a backup which we are going to use if we have no unique target left anymore
        std::list<WorldObject*> targetsCopy = targets;

        // This is ugly as fuck but there is no other way to get already targeted gas stalkers
        if (Creature* creature = GetCaster()->ToCreature())
            if (creature->IsAIEnabled)
                targets.remove_if(UnusedGuidTargetSelector(CAST_AI(boss_zanzil, creature->AI())->GetAlreadyTargetedObjectGuids()));

        if (targets.empty())
            targets = targetsCopy;

        Trinity::Containers::RandomResize(targets, 3);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (target->GetDistance(GreenGasStalkerPos) > 1.0f)
            target->CastSpell(target, SPELL_TOXIC_GAS_SOUND);
        else
            target->CastSpell(target, SPELL_GREEN_GAS);
    }

    void HandleGuidReservation(SpellEffIndex /*effIndex*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (caster->IsAIEnabled)
                if (Creature* target = GetHitCreature())
                    caster->AI()->SetGUID(target->GetGUID());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_zanzil_zanzils_graveyard_gas::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_zanzil_zanzils_graveyard_gas::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectLaunchTarget += SpellEffectFn(spell_zanzil_zanzils_graveyard_gas::HandleGuidReservation, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_zanzil_frostburn_formula : public AuraScript
{
    PrepareAuraScript(spell_zanzil_frostburn_formula);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Unit* target = eventInfo.GetProcTarget())
            if (Creature* creature = target->ToCreature())
                return !creature->IsDungeonBoss();

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_zanzil_frostburn_formula::CheckProc);
    }
};

void AddSC_boss_zanzil()
{
    RegisterZulGurubCreatureAI(boss_zanzil);
    RegisterZulGurubCreatureAI(npc_zanzil_zanzili_berserker);
    RegisterAuraScript(spell_zanzil_zanzili_fire);
    RegisterAuraScript(spell_zanzil_zanzils_resurrection_elixir);
    RegisterSpellScript(spell_zanzil_zanzils_resurrection_elixir_red_script);
    RegisterSpellScript(spell_zanzil_zanzils_graveyard_gas);
    RegisterAuraScript(spell_zanzil_frostburn_formula);
}
