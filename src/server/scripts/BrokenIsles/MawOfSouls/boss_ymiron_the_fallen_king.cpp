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
#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SharedDefines.h"
#include "TemporarySummon.h"
#include "maw_of_souls.h"

enum YmironFallenKingSpells
{
    // Intro
    SPELL_SOUL_SIPHON               = 243029,
    SPELL_SOUL_SIPHON_CHANNEL       = 194665,
    SPELL_KNEELING                  = 197227,
    SPELL_SUICIDE                   = 117624,

    SPELL_POWER                     = 167922,
    SPELL_DARK_SLASH                = 193211,
    SPELL_SCREAMS_OF_THE_DEAD       = 193364,
    SPELL_WINDS_OF_NORTHREND        = 193977,
    SPELL_BANE_AURA                 = 193460,
    SPELL_BANE_MISSILE              = 193463,
    SPELL_BANE_AT_NHC_HEROIC        = 193465,
    SPELL_BANE_DAMAGE               = 193513, // only on triggering unit of Bane
    SPELL_BANE_NOVA                 = 200194, // AoE on party when Bane orb is triggered
    SPELL_ARISE_FALLEN_ENABLER      = 193510,
    SPELL_ARISE_FALLEN_SELECTOR     = 193566,
    SPELL_ARISE_FALLEN_SUMMON       = 193594,
    SPELL_DESPAWN_AREA_TRIGGERS     = 115905,

    SPELL_VIGOR                     = 203816, // stacking every 6s
};

enum YmironFallenKingSpellVisuals
{
    SPELL_VISUAL_SOUL_SIPHON        = 52528,
    SPELL_VISUAL_BANE_PRECAST       = 50121,
    SPELL_VISUAL_ARISE_FALLEN       = 50259,

    SPELL_VISUAL_KIT_ARISE_FALLEN   = 59548,
};

enum YmironFallenKingEvents
{
    EVENT_DARK_SLASH_CHECKER = 1,
    EVENT_SCREAMS_OF_THE_DEAD,
    EVENT_WINDS_OF_NORTHREND,
    EVENT_BANE,
    EVENT_ARISE_FALLEN
};

enum YmironFallenKingTexts
{
    SAY_INTRO1              = 0, // Your souls will drift for eternity in the tides of the underworld!
    SAY_INTRO2              = 1, // Another drop in the sea of souls!
    SAY_AGGRO               = 2, // Mortals... I fell to your wretched kind once before. It WILL NOT happen again!
    SAY_SCREAMS_OF_THE_DEAD = 3, // COWER BEFORE ME!
    SAY_WINDS_OF_NORTHREND  = 4, // Know the bitter chill of death as I have!
    SAY_BANE                = 5, // The shadows of the underworld bend to me!
    SAY_ARISE_FALLEN        = 6, // The shadows of Helheim cut deeper than steel!
    SAY_DEATH               = 7, // Not... again... HARBARON! CAST THEIR SOULS INTO THE TIDES!
};

enum YmironFallenKingActions
{
    ACTION_ACTIVATE = 1,
};

enum YmironFallenKingPaths
{
    PATH_INTRO_TOWARDS_SLAVES   = 9675600,
    PATH_INTRO_AWAY_FROM_SLAVES = 9675601
};

constexpr Position YmironIntroJumpPos = { 7401.39f, 7281.7f, 44.0207f };
constexpr Position YmironRespawnPos = { 7398.374f, 7277.1206f, 43.792637f, 5.724679946899414062f };

// 96756 - Ymiron, the Fallen King
struct boss_ymiron_the_fallen_king : public BossAI
{
    boss_ymiron_the_fallen_king(Creature* creature) : BossAI(creature, DATA_YMIRON), _firstScreamDone(false) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

        DoCastSelf(SPELL_KNEELING);

        me->SetPower(me->GetPowerType(), 80);
    }

    void InitializeAI() override
    {
        if (instance->GetBossState(DATA_YMIRON) != NOT_STARTED)
            me->Relocate(YmironRespawnPos);
    }

    void Reset() override
    {
        BossAI::Reset();
        _firstScreamDone = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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

        me->InterruptNonMeleeSpells(true);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        Talk(SAY_AGGRO);

        DoCastAOE(SPELL_POWER);

        scheduler.CancelAll();

        // should turn to highest threat target after standing up
        if (me->HasAura(SPELL_KNEELING))
        {
            me->RemoveAurasDueToSpell(SPELL_KNEELING);
            me->SetReactState(REACT_PASSIVE);

            scheduler.Schedule(1600ms, [this](TaskContext /*task*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
            });
        }

        events.ScheduleEvent(EVENT_DARK_SLASH_CHECKER, 500ms);
        events.ScheduleEvent(EVENT_SCREAMS_OF_THE_DEAD, 5900ms);
        events.ScheduleEvent(EVENT_WINDS_OF_NORTHREND, 15100ms);
        events.ScheduleEvent(EVENT_BANE, 22100ms);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DARK_SLASH_CHECKER:
                {
                    if (me->GetPower(me->GetPowerType()) >= 100)
                    {
                        DoCastVictim(SPELL_DARK_SLASH);
                        me->SetPower(me->GetPowerType(), 0);
                    }
                    events.Repeat(500ms);
                    break;
                }
                case EVENT_SCREAMS_OF_THE_DEAD:
                {
                    if (_firstScreamDone)
                        Talk(SAY_SCREAMS_OF_THE_DEAD);
                    else
                        _firstScreamDone = true;

                    DoCastAOE(SPELL_SCREAMS_OF_THE_DEAD);
                    events.Repeat(31s);
                    break;
                }
                case EVENT_WINDS_OF_NORTHREND:
                    Talk(SAY_WINDS_OF_NORTHREND);
                    DoCastAOE(SPELL_WINDS_OF_NORTHREND);
                    events.Repeat(29s);
                    break;
                case EVENT_BANE:
                {
                    Talk(SAY_BANE);
                    DoCastAOE(SPELL_BANE_AURA);
                    if (IsHeroicOrHigher())
                        events.ScheduleEvent(EVENT_ARISE_FALLEN, 19100ms);
                    events.Repeat(59s);
                    break;
                }
                case EVENT_ARISE_FALLEN:
                    Talk(SAY_ARISE_FALLEN);
                    DoCastAOE(SPELL_ARISE_FALLEN_ENABLER);
                    DoCastAOE(SPELL_ARISE_FALLEN_SELECTOR);
                    break;
                default:
                    break;
            }
        }
    }

    void DoAction(int32 param) override
    {
        if (param != ACTION_ACTIVATE)
            return;

        me->RemoveAurasDueToSpell(SPELL_KNEELING);
        scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            me->GetMotionMaster()->MoveJumpWithGravity(YmironIntroJumpPos, 24.0f, 25.31545448303222656, EVENT_JUMP);
        });
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId != EVENT_JUMP)
            return;

        scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            me->GetMotionMaster()->MovePath(PATH_INTRO_TOWARDS_SLAVES, false);
        });
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_SOUL_SIPHON_CHANNEL)
            return;

        scheduler.Schedule(2s, [this](TaskContext task)
        {
            Talk(SAY_INTRO2);

            task.Schedule(5s, [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MovePath(PATH_INTRO_AWAY_FROM_SLAVES, false);
            });
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (me->IsInCombat())
            return;

        if (pathId == PATH_INTRO_TOWARDS_SLAVES)
        {
            scheduler.Schedule(2s, [this](TaskContext /*task*/)
            {
                DoCastAOE(SPELL_SOUL_SIPHON_CHANNEL);
                Talk(SAY_INTRO1);
            });
        }
        else if (pathId == PATH_INTRO_AWAY_FROM_SLAVES)
        {
            DoCastSelf(SPELL_KNEELING);
        }
    }

private:
    bool _firstScreamDone;
};

// Maw of Souls - Ymiron Activation Trigger
struct at_ymiron_the_fallen_king_activation : AreaTriggerAI
{
    at_ymiron_the_fallen_king_activation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        if (player->IsGameMaster())
            return;

        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Creature* ymiron = instance->GetCreature(DATA_YMIRON);
        if (!ymiron)
            return;

        ymiron->AI()->DoAction(ACTION_ACTIVATE);

        at->Remove();
    }
};

class YmironSoulSiphonVisual : public BasicEvent
{
public:
    explicit YmironSoulSiphonVisual(ObjectGuid ymironGUID, Unit* runecarver, float travelSpeed) : _ymironGUID(ymironGUID), _runecarver(runecarver), _travelSpeed(travelSpeed) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        if (_runecarver->isDead())
            return true;

        Unit* ymiron = ObjectAccessor::GetCreature(*_runecarver, _ymironGUID);
        if (!ymiron)
            return true;

        _runecarver->SendPlaySpellVisual(ymiron->GetPosition(), SPELL_VISUAL_SOUL_SIPHON, 0, 0, _travelSpeed, false, 0.0f);

        _runecarver->m_Events.AddEventAtOffset(this, 400ms);
        return false;
    }

private:
    ObjectGuid _ymironGUID;
    Unit* _runecarver;
    float _travelSpeed;
};

// 243029 - Soul Siphon
class spell_ymiron_the_fallen_king_soul_siphon : public AuraScript
{
    void OnAfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        float travelSpeed = 15 + 0.180f * caster->GetDistance(GetTarget());
        GetTarget()->m_Events.AddEventAtOffset(new YmironSoulSiphonVisual(caster->GetGUID(), GetTarget(), travelSpeed), 1s);
    }

    void TriggerSuicide()
    {
        Creature* targetCreature = GetTarget()->ToCreature();
        if (!targetCreature)
            return;

        targetCreature->CastSpell(nullptr, SPELL_SUICIDE, true);
        targetCreature->DespawnOrUnsummon(20s);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!roll_chance_f(10))
            return;

        TriggerSuicide();
    }

    void OnAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        TriggerSuicide();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_ymiron_the_fallen_king_soul_siphon::OnAfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_the_fallen_king_soul_siphon::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ymiron_the_fallen_king_soul_siphon::OnAfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 167922 - Power
class spell_ymiron_the_fallen_king_power_periodic : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff)
    {
        int32 newPower = GetTarget()->GetPower(POWER_ENERGY) + (((aurEff->GetTickNumber() + 1) % 3 == 0) ? 6 : 7);
        GetTarget()->SetPower(POWER_ENERGY, newPower);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_the_fallen_king_power_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class YmironBanePrecastVisual : public BasicEvent
{
public:
    explicit YmironBanePrecastVisual(Unit* caster, int8 remainingVisualsToSpawn) : _caster(caster), _remainingVisualsToSpawn(remainingVisualsToSpawn) { }

    static constexpr int8 BANE_VISUAL_NUM = 11;
    static constexpr float BANE_VISUAL_TIME_OFFSET = 0.204545438289642f;
    static constexpr float BANE_VISUAL_TIME_BASE = 0.75f;

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        float dist = frand(10.0f, 35.0f);
        float angle = frand(0.0f, 2.0f * float(M_PI));
        Position dest(_caster->GetPositionX() + dist * std::cos(angle), _caster->GetPositionY() + dist * std::sin(angle), _caster->GetPositionZ());
        float travelSpeed = BANE_VISUAL_TIME_BASE + (BANE_VISUAL_TIME_OFFSET * _remainingVisualsToSpawn);

        _caster->SendPlaySpellVisual(dest, SPELL_VISUAL_BANE_PRECAST, 0, 0, travelSpeed, true);

        _remainingVisualsToSpawn--;

        if (_remainingVisualsToSpawn > 0)
        {
            _caster->m_Events.AddEventAtOffset(this, 200ms);
            return false;
        }
        return true;
    }

private:
    Unit* _caster;
    int8 _remainingVisualsToSpawn;
};

// 193460 - Bane
class spell_ymiron_the_fallen_king_bane_periodic : public SpellScript
{
    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEventAtOffset(new YmironBanePrecastVisual(GetCaster(), YmironBanePrecastVisual::BANE_VISUAL_NUM), 0s);
    }

    void Register() override { }
};

// 193460 - Bane
class spell_ymiron_the_fallen_king_bane_periodic_AuraScript : public AuraScript
{
    static constexpr float BANE_MISSILE_DIST_OFFSET = 2.272f;
    static constexpr float BANE_MISSILE_DIST_BASE = 10.0f;
    static constexpr float BANE_MISSILE_ANGLE_OFFSET = 0.75f;

    static constexpr int8 BANE_MAX_TOTAL_TICKS = 4 + 4 + 14;

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& /*isPeriodic*/, int32& amplitude)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetMap()->IsMythic() || caster->GetMap()->IsMythicPlus())
            amplitude = 1 * IN_MILLISECONDS;

        // defaults to 2000 for Normal and Heroic via. db2 data
    }

    void SpawnBaneOrb(int8 tickNumber)
    {
        float dist = _distances[tickNumber - 1];
        float angle = _angles[tickNumber - 1];
        Position dest = { GetTarget()->GetPositionX() + dist * std::cos(angle), GetTarget()->GetPositionY() + dist * std::sin(angle), GetTarget()->GetPositionZ(), angle};
        GetTarget()->CastSpell(dest, SPELL_BANE_MISSILE, true);
    }

    void OnAfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        for (int8 i = 0; i < BANE_MAX_TOTAL_TICKS; i++)
        {
            float angle = Position::NormalizeOrientation(GetCaster()->GetOrientation() + (i * BANE_MISSILE_ANGLE_OFFSET));
            _angles[2 * i + 0] = angle;
            _angles[2 * i + 1] = angle;

            float dist = BANE_MISSILE_DIST_BASE + (i * BANE_MISSILE_DIST_OFFSET);
            _distances[2 * i + 0] = dist;
            _distances[2 * i + 1] = dist;
        }
        Trinity::Containers::RandomShuffle(_angles);
        Trinity::Containers::RandomShuffle(_distances);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 1 || (aurEff->GetTickNumber() == 2 && (GetTarget()->GetMap()->IsMythic() || GetTarget()->GetMap()->IsMythicPlus())))
        {
            for (int8 i = 0; i < 4; i++)
                SpawnBaneOrb(aurEff->GetTickNumber() + i);
        }
        else
            SpawnBaneOrb(aurEff->GetTickNumber() + 8);
    }

    void OnAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_ARISE_FALLEN_ENABLER, true);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_ymiron_the_fallen_king_bane_periodic_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectApply += AuraEffectApplyFn(spell_ymiron_the_fallen_king_bane_periodic_AuraScript::OnAfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_the_fallen_king_bane_periodic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ymiron_the_fallen_king_bane_periodic_AuraScript::OnAfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    std::array<float, BANE_MAX_TOTAL_TICKS * 2> _angles;
    std::array<float, BANE_MAX_TOTAL_TICKS * 2> _distances;
};

struct at_ymiron_the_fallen_king_bane : AreaTriggerAI
{
    at_ymiron_the_fallen_king_bane(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    static constexpr float TIME_TO_TARGET_DIST_MULTIPLIER = 966.6466466434464f;

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        float radius = at->GetExactDist(caster);
        float timeToTarget = radius * TIME_TO_TARGET_DIST_MULTIPLIER;
        float angle = at->GetOrientation();

        AreaTriggerOrbitInfo orbitInfo;
        orbitInfo.CounterClockwise = false;
        orbitInfo.CanLoop = true;
        orbitInfo.ElapsedTimeForMovement = 0;
        orbitInfo.StartDelay = 0;
        orbitInfo.Radius = radius;
        orbitInfo.BlendFromRadius = radius;
        orbitInfo.InitialAngle = angle;
        orbitInfo.PathTarget = caster->GetGUID();
        at->InitOrbit(orbitInfo, timeToTarget);
    }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(player, SPELL_BANE_DAMAGE, true);
        caster->CastSpell(nullptr, SPELL_BANE_NOVA, true);

        at->Remove();
    }
};

class YmironAriseFallenVisual : public BasicEvent
{
public:
    explicit YmironAriseFallenVisual(Unit* caster, Position dest) : _caster(caster), _dest(dest) { }

    static constexpr int8 BANE_VISUAL_NUM = 11;
    static constexpr float BANE_VISUAL_TIME_OFFSET = 0.204545438289642f;
    static constexpr float BANE_VISUAL_TIME_BASE = 0.75f;

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _caster->CastSpell(_dest, SPELL_ARISE_FALLEN_SUMMON, true);
        return true;
    }

private:
    Unit* _caster;
    Position _dest;
};

// 193566 - Arise, Fallen
class spell_ymiron_the_fallen_king_arise_fallen_selector : public SpellScript
{
    static constexpr float SPAWN_DIST_TO_TARGET = 3.5f;

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(SPELL_ARISE_FALLEN_ENABLER);

        std::vector<AreaTrigger*> atList = GetCaster()->GetAreaTriggers(SPELL_BANE_AT_NHC_HEROIC);
        Trinity::Containers::RandomShuffle(atList);

        for (AreaTrigger* at : atList)
        {
            _baneATGUIDs.push(at->GetGUID());
        }

        _atsPerTarget = atList.size() / GetUnitTargetCountForEffect(EFFECT_0);
        _remainingBaneATs = atList.size() % GetUnitTargetCountForEffect(EFFECT_0);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
        {
            return !target->IsPlayer();
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        uint8 atNum = _atsPerTarget;
        if (_remainingBaneATs > 0)
        {
            atNum++;
            _remainingBaneATs--;
        }

        for (uint8 i = 0; i < atNum; i++)
        {
            AreaTrigger* at = ObjectAccessor::GetAreaTrigger(*GetCaster(), _baneATGUIDs.front());
            _baneATGUIDs.pop();

            if (!at)
                return;

            Position dest = GetHitUnit()->GetFirstCollisionPosition(SPAWN_DIST_TO_TARGET, frand(0, 2.0f * float(M_PI)));

            float travelSpeed = frand(1.50f, 2.50f);
            at->SendPlayOrphanSpellVisual(dest, SPELL_VISUAL_ARISE_FALLEN, travelSpeed, true);

            uint32 travelSpeedInMs = (uint32)(travelSpeed * 1000);
            GetCaster()->m_Events.AddEventAtOffset(new YmironAriseFallenVisual(GetCaster(), dest), Milliseconds(travelSpeedInMs));
            at->Remove();
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ymiron_the_fallen_king_arise_fallen_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHit += SpellEffectFn(spell_ymiron_the_fallen_king_arise_fallen_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_ymiron_the_fallen_king_arise_fallen_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    std::queue<ObjectGuid> _baneATGUIDs;
    uint8 _atsPerTarget = 0;
    uint8 _remainingBaneATs = 0;
};

// 98246 - Risen Warrior
struct npc_ymiron_the_fallen_king_risen_warrior : public ScriptedAI
{
    npc_ymiron_the_fallen_king_risen_warrior(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ARISE_FALLEN, 4, 2000);

        me->SetReactState(REACT_PASSIVE);
        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
        });

        DoZoneInCombat();

        _scheduler.Schedule(6s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_VIGOR, true);
            task.Repeat(6s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        UpdateVictim();
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_ymiron_the_fallen_king()
{
    RegisterMawOfSoulsCreatureAI(boss_ymiron_the_fallen_king);
    RegisterAreaTriggerAI(at_ymiron_the_fallen_king_activation);
    RegisterSpellScript(spell_ymiron_the_fallen_king_soul_siphon);

    RegisterSpellScript(spell_ymiron_the_fallen_king_power_periodic);

    RegisterSpellAndAuraScriptPair(spell_ymiron_the_fallen_king_bane_periodic, spell_ymiron_the_fallen_king_bane_periodic_AuraScript);
    RegisterAreaTriggerAI(at_ymiron_the_fallen_king_bane);

    RegisterSpellScript(spell_ymiron_the_fallen_king_arise_fallen_selector);
    RegisterMawOfSoulsCreatureAI(npc_ymiron_the_fallen_king_risen_warrior);
}
