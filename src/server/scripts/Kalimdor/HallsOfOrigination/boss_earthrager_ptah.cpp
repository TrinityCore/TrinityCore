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

#include "halls_of_origination.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "Unit.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "PassiveAI.h"
#include "GridNotifiers.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Weather.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"

enum Texts
{
    SAY_DEATH       = 0,
    SAY_AGGRO       = 1,
    SAY_PLAYER_KILL = 2,
    SAY_SPECIAL     = 3
};

enum Events
{
    // Earthrager Ptah
    EVENT_RAGING_SMASH = 1,
    EVENT_FLAME_BOLT,
    EVENT_EARTH_SPIKE,
    EVENT_PTAH_EXPLODE,
    EVENT_TUMULTUOUS_SAND_STORM,
    EVENT_QUICKSAND,

    // Beetle Stalker
    EVENT_SUMMON_JEWELED_SCARAB,

    // Tumultuous Earthstorm
    EVENT_START_MOVEMENT
};

enum Spells
{
    // Fight
    SPELL_RAGING_SMASH              = 83650,
    SPELL_FLAME_BOLT                = 77370,
    SPELL_EARTH_SPIKE_WARN          = 94974,

    // Disperse
    SPELL_SANDSTORM                 = 75491,
    SPELL_TUMULTUOUS_EARTHSTORM     = 75517, // Server-side spell
    SPELL_PTAH_EXPLOSION            = 75519,
    SPELL_SUMMON_QUICKSAND          = 75550,  // Server-side spell + hidden client-side flag!

    // Tumultuous Earthstorm
    SPELL_CONSUME                   = 89633
};

enum Phases
{
    PHASE_FIGHT                     = 1,
    PHASE_EARTHSTORM                = 2
};

enum Sounds
{
    SOUND_PTAH_EARTHQUAKE           = 18908
};

struct boss_earthrager_ptah : public BossAI
{
    boss_earthrager_ptah(Creature* creature) : BossAI(creature, DATA_EARTHRAGER_PTAH), _hasDispersed(false), _summonCount(0), _summonsDeadCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_FIGHT);
        events.ScheduleEvent(EVENT_RAGING_SMASH, 7s, 0, PHASE_FIGHT); // Seconds(12)
        events.ScheduleEvent(EVENT_FLAME_BOLT, 8s, 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_EARTH_SPIKE, 15s, 0, PHASE_FIGHT); // Seconds(21)
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_PLAYER_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_FOG, 0.0f);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // About to die? One-hit cases...
        if (int64(me->GetHealth()) - int64(damage) <= 0)
            return;

        // Earthquake phase happens at 50% health remaining.
        if (me->HealthBelowPctDamaged(50, damage) && !_hasDispersed)
            EnterDispersePhase();
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_PTAH_ADD_DIED)
            return;

        _summonsDeadCount++;
        if (_summonsDeadCount == _summonCount)
            ExitDispersePhase();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_DUSTBONE_HORROR:
            case NPC_JEWELED_SCARAB:
                summon->SetReactState(REACT_PASSIVE);
                if (summon->IsAIEnabled)
                    summon->AI()->DoZoneInCombat();
                _addGUIDs.push_back(summon->GetGUID());
                _summonCount++;
                break;
            case NPC_TUMULTOUS_EARTHSTORM:
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->CastSpell(summon, SPELL_CONSUME);
                    summon->GetMotionMaster()->MoveRandom(30.f);
                }, 3s + 600ms);
                break;
            default:
                break;
        }
        summons.Summon(summon);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RAGING_SMASH:
                    DoCastVictim(SPELL_RAGING_SMASH);
                    events.Repeat(19s);
                    break;
                case EVENT_FLAME_BOLT:
                    DoCast(me, SPELL_FLAME_BOLT);
                    events.Repeat(21s);
                    break;
                case EVENT_EARTH_SPIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_EARTH_SPIKE_WARN);
                    events.Repeat(15s);
                    break;
                case EVENT_PTAH_EXPLODE:
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 0);
                    Talk(SAY_SPECIAL);
                    DoCast(me, SPELL_PTAH_EXPLOSION);

                    for (ObjectGuid guid : _addGUIDs)
                    {
                        if (Creature* add = ObjectAccessor::GetCreature(*me, guid))
                        {
                            add->SetReactState(REACT_AGGRESSIVE);
                            if (add->IsAIEnabled)
                                add->AI()->DoZoneInCombat();
                        }
                    }

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_TUMULTUOUS_SAND_STORM, 2s + 500ms, 0, PHASE_EARTHSTORM);
                    break;
                case EVENT_QUICKSAND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_SUMMON_QUICKSAND, true);
                    events.Repeat(21s); //Seconds(10)
                    break;
                case EVENT_TUMULTUOUS_SAND_STORM:
                    DoCastSelf(SPELL_TUMULTUOUS_EARTHSTORM, true);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void EnterDispersePhase()
    {
        _hasDispersed = true;

        me->SetReactState(REACT_PASSIVE);
        me->CastStop();
        me->AttackStop();
        me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_LIGHT_SANDSTORM, 1.0f);
        DoCast(me, SPELL_SANDSTORM);
        instance->SetData(DATA_SUMMON_SANDSTORM_ADDS, IN_PROGRESS);

        events.SetPhase(PHASE_EARTHSTORM);
        events.ScheduleEvent(EVENT_PTAH_EXPLODE, 6s, 0, PHASE_EARTHSTORM);
        events.ScheduleEvent(EVENT_QUICKSAND, 10s, 0, PHASE_EARTHSTORM);
    }

    void ExitDispersePhase()
    {
        me->RemoveAurasDueToSpell(SPELL_PTAH_EXPLOSION);
        me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_FOG, 0.0f);
        me->SetReactState(REACT_AGGRESSIVE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 2);
        events.SetPhase(PHASE_FIGHT);
        events.ScheduleEvent(EVENT_RAGING_SMASH, 7s, 0, PHASE_FIGHT); // Seconds(12)
        events.ScheduleEvent(EVENT_FLAME_BOLT, 8s, 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_EARTH_SPIKE, 15s, 0, PHASE_FIGHT); // Seconds(21)
    }

    bool _hasDispersed;
    uint8 _summonCount;
    uint8 _summonsDeadCount;
    GuidVector _addGUIDs;
};

struct npc_ptah_beetle_stalker : public ScriptedAI
{
    npc_ptah_beetle_stalker(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BEETLE_BURROW)
            _events.ScheduleEvent(EVENT_SUMMON_JEWELED_SCARAB, Seconds(5), Seconds(6));
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_JEWELED_SCARAB:
                    if (me->HasAura(SPELL_BEETLE_BURROW))
                    {
                        DoCastAOE(SPELL_SUMMON_JEWELED_SCARAB);
                        me->RemoveAurasDueToSpell(SPELL_BEETLE_BURROW);
                    }
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

class spell_earthrager_ptah_flame_bolt : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 size = GetCaster()->GetMap()->IsHeroic() ? 3 : 2;

        if (targets.size() > size)
            Trinity::Containers::RandomResize(targets, size);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_earthrager_ptah_flame_bolt::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_earthrager_ptah_sandstorm : public SpellScript
{
    void PlaySoundID(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitUnit()->ToPlayer())
            GetCaster()->PlayDirectSound(SOUND_PTAH_EARTHQUAKE, player);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_earthrager_ptah_sandstorm::PlaySoundID, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_earthrager_ptah_explosion : public AuraScript
{
    void SetFlags(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetFlag(UNIT_FIELD_FLAGS, uint32(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_29 | UNIT_FLAG_IMMUNE));
        target->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
    }

    void RemoveFlags(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveFlag(UNIT_FIELD_FLAGS, uint32(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_29 | UNIT_FLAG_IMMUNE));
        target->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_earthrager_ptah_explosion::SetFlags, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_earthrager_ptah_explosion::RemoveFlags, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_earthrager_ptah_consume : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject* target)->bool
        {
            Unit* unit = target->ToUnit();
            return (!unit || unit->GetVehicle() || !unit->movespline->Finalized());
        });
    }

    void FilterKnockbackTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject* target)->bool
        {
            Unit* unit = target->ToUnit();
            return (!unit || !unit->GetVehicleCreatureBase() || unit->GetVehicleCreatureBase() != caster);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_earthrager_ptah_consume::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class achievement_straw_broke_camels_back : public AchievementCriteriaScript
{
    public:
        achievement_straw_broke_camels_back() : AchievementCriteriaScript("achievement_straw_broke_camels_back") { }

        bool OnCheck(Player* player, Unit* /*target*/) override
        {
            if (Unit* vehicle = player->GetVehicleBase())
                return vehicle->GetEntry() == NPC_HOO_CAMEL;

            return false;
        }
};

void AddSC_boss_earthrager_ptah()
{
    RegisterHallsOfOriginationCreatureAI(boss_earthrager_ptah);
    RegisterHallsOfOriginationCreatureAI(npc_ptah_beetle_stalker);
    RegisterSpellScript(spell_earthrager_ptah_flame_bolt);
    RegisterSpellScript(spell_earthrager_ptah_sandstorm);
    RegisterSpellScript(spell_earthrager_ptah_explosion);
    RegisterSpellScript(spell_earthrager_ptah_consume);
    new achievement_straw_broke_camels_back();
}
