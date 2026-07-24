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

/*
 * Combat timers requires to be revisited
 * Clearly seen one peon died from Shadow Fissure, doesn't work because health regenerates,
   it should regenerate in case of other spells, no sniffs with Wild Shadow Fissure
 * Dark Spin gets interrupted after first tick
 * Death Coil is a buff instead of a debuff
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum NethekurseTexts
{
    SAY_TAUNT_SHADOW_SEAR      = 0,
    SAY_TAUNT_DEATH_COIL       = 1,
    SAY_TAUNT_SHADOW_FISSURE   = 2,

    SAY_AGGRO_ALL_ALIVE        = 3,
    SAY_AGGRO_SOME_ALIVE       = 4,
    SAY_AGGRO_ALL_DEAD         = 5,

    SAY_PEON_ENGAGED           = 6,
    SAY_PEON_DEFEATED          = 7,

    SAY_SLAY                   = 8,
    SAY_DEATH                  = 9,

    // Fel Orc Convert
    SAY_PEON_AGGRO             = 0,
    SAY_PEON_SHADOW_SEAR       = 1,
    SAY_PEON_DEATH_COIL        = 2,
    SAY_PEON_SHADOW_FISSURE    = 3
};

enum NethekurseSpells
{
    // Combat
    SPELL_SHADOW_FISSURE       = 30496,
    SPELL_DEATH_COIL           = 30500,
    SPELL_SHADOW_CLEAVE        = 30495,
    SPELL_SHADOW_SLAM          = 35953,
    SPELL_DARK_SPIN            = 30502,

    // Intro
    SPELL_PEON_SHADOW_SEAR     = 30735,
    SPELL_PEON_DEATH_COIL      = 30741,
    SPELL_PEON_TARGET_FISSURES = 30745,

    // Fel Orc Convert
    SPELL_HEMORRHAGE           = 30478,

    // Lesser Shadow Fissure
    SPELL_CONSUMPTION          = 30497,
    SPELL_CONSUMPTION_H        = 35952,

    // Wild Shadow Fissure
    SPELL_CONSUMPTION_WILD     = 32250,

    // Scripts
    SPELL_SHADOW_FISSURE_2     = 30744
};

enum NethekurseEvents
{
    EVENT_TAUNT_PEONS          = 1,
    EVENT_INTERNAL_COOLDOWN,
    EVENT_CLEAR_EMOTE_STATE,

    EVENT_SHADOW_FISSURE,
    EVENT_DEATH_COIL,
    EVENT_SHADOW_CLEAVE,
    EVENT_SHADOW_SLAM,
    EVENT_DARK_SPIN
};

enum NethekurseActions
{
    ACTION_START_INTRO         = 0,
    ACTION_PEON_ENGAGED        = 1,
    ACTION_PEON_KILLED         = 2
};

enum NethekurseMisc
{
    SOUND_ID_ROAR              = 9110,
    MAX_KILLED_PEONS           = 4
};

// 16807 - Grand Warlock Nethekurse
struct boss_grand_warlock_nethekurse : public BossAI
{
    boss_grand_warlock_nethekurse(Creature* creature) : BossAI(creature, DATA_NETHEKURSE),
        _peonKilledCount(0), _isEventOnCooldown(false), _isDarkSpinStarted(false) { }

    void Reset() override
    {
        _Reset();

        _isEventOnCooldown = false;
        _isDarkSpinStarted = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.Reset();

        events.ScheduleEvent(EVENT_SHADOW_FISSURE, 8s);
        events.ScheduleEvent(EVENT_DEATH_COIL, 10s, 15s);

        if (!IsHeroic())
            events.ScheduleEvent(EVENT_SHADOW_CLEAVE, 15s, 20s);
        else
            events.ScheduleEvent(EVENT_SHADOW_SLAM, 15s, 20s);

        switch (_peonKilledCount)
        {
            case 0:
                Talk(SAY_AGGRO_ALL_ALIVE);
                break;
            case 1:
            case 2:
            case 3:
                Talk(SAY_AGGRO_SOME_ALIVE);
                break;
            case 4:
                Talk(SAY_AGGRO_ALL_DEAD);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (!me->IsAlive())
            return;

        switch (action)
        {
            case ACTION_START_INTRO:
                if (!me->IsInCombat() && _peonKilledCount != MAX_KILLED_PEONS)
                    events.ScheduleEvent(EVENT_TAUNT_PEONS, 0s);
                break;
            case ACTION_PEON_ENGAGED:
                if (!me->IsInCombat() && !_isEventOnCooldown)
                {
                    Talk(SAY_PEON_ENGAGED);
                    me->PauseMovement(5000);
                    me->SetFacingTo(4.537856101989746093f);
                    _isEventOnCooldown = true;

                    events.ScheduleEvent(EVENT_INTERNAL_COOLDOWN, 5s);
                }
                break;
            case ACTION_PEON_KILLED:
            {
                ++_peonKilledCount;

                if (!me->IsInCombat() && _peonKilledCount == MAX_KILLED_PEONS)
                    DoZoneInCombat();

                if (!me->IsInCombat() && !_isEventOnCooldown && _peonKilledCount != MAX_KILLED_PEONS)
                {
                    Talk(SAY_PEON_DEFEATED);
                    me->PauseMovement(5000);
                    me->SetFacingTo(4.572762489318847656f);
                    me->SetEmoteState(EMOTE_STATE_APPLAUD);
                    _isEventOnCooldown = true;

                    events.ScheduleEvent(EVENT_INTERNAL_COOLDOWN, 5s);
                    events.ScheduleEvent(EVENT_CLEAR_EMOTE_STATE, 5s);
                }
                break;
            }
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isDarkSpinStarted && me->HealthBelowPctDamaged(25, damage))
        {
            _isDarkSpinStarted = true;
            events.ScheduleEvent(EVENT_DARK_SPIN, 0s);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateOutOfCombatEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // ... intro event starts every time player enters area trigger
                case EVENT_TAUNT_PEONS:
                {
                    switch (urand(0, 2))
                    {
                        case 0:
                            // This one targets two (?) peons
                            Talk(SAY_TAUNT_SHADOW_SEAR);
                            DoCastSelf(SPELL_PEON_SHADOW_SEAR, { SPELLVALUE_MAX_TARGETS, 2 });
                            break;
                        case 1:
                            // This one targets all four peons
                            Talk(SAY_TAUNT_DEATH_COIL);
                            DoCastSelf(SPELL_PEON_DEATH_COIL);
                            break;
                        case 2:
                            // This one targets one peon
                            Talk(SAY_TAUNT_SHADOW_FISSURE);
                            DoCastSelf(SPELL_PEON_TARGET_FISSURES);
                            break;
                        default:
                            break;
                    }

                    // ... cancel copies of event every time it is scheduled, then schedule new to repeat it, only one should be active
                    events.CancelEvent(EVENT_TAUNT_PEONS);
                    if (_peonKilledCount != MAX_KILLED_PEONS)
                        events.ScheduleEvent(EVENT_TAUNT_PEONS, 25s, 35s);
                    break;
                }
                case EVENT_INTERNAL_COOLDOWN:
                    _isEventOnCooldown = false;
                    break;
                case EVENT_CLEAR_EMOTE_STATE:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateOutOfCombatEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_FISSURE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, true))
                        DoCast(target, SPELL_SHADOW_FISSURE);
                    events.Repeat(8s);
                    break;
                case EVENT_DEATH_COIL:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        DoCast(target, SPELL_DEATH_COIL);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_SHADOW_CLEAVE:
                    DoCastVictim(SPELL_SHADOW_CLEAVE);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_SHADOW_SLAM:
                    DoCastVictim(SPELL_SHADOW_SLAM);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_DARK_SPIN:
                    DoCastSelf(SPELL_DARK_SPIN);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint32 _peonKilledCount;
    bool _isEventOnCooldown;
    bool _isDarkSpinStarted;
};

// 17083 - Fel Orc Convert
struct npc_fel_orc_convert : public ScriptedAI
{
    npc_fel_orc_convert(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (roll_chance_i(15))
            Talk(SAY_PEON_AGGRO);

        _scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_HEMORRHAGE);
            task.Repeat(5s, 10s);
        });

        if (!me->HasStringId("FelOrcConvertNethekurseEvent"))
            return;

        if (Creature* nethekurse = _instance->GetCreature(DATA_NETHEKURSE))
            nethekurse->AI()->DoAction(ACTION_PEON_ENGAGED);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // Not sure if these are grouped correctly, based on few sniffs
        // By the way, language is correct, verified, not a typo
        // Text 14143 seems to be unused, not added here
        switch (spellInfo->Id)
        {
            case SPELL_PEON_SHADOW_SEAR:
                if (roll_chance_i(30))
                    Talk(SAY_PEON_SHADOW_SEAR);
                break;
            case SPELL_PEON_DEATH_COIL:
                if (roll_chance_i(30))
                {
                    Talk(SAY_PEON_DEATH_COIL);
                    DoPlaySoundToSet(me, SOUND_ID_ROAR);
                }
                break;
            case SPELL_PEON_TARGET_FISSURES:
                if (roll_chance_i(30))
                    Talk(SAY_PEON_SHADOW_FISSURE);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!me->HasStringId("FelOrcConvertNethekurseEvent"))
            return;

        if (Creature* nethekurse = _instance->GetCreature(DATA_NETHEKURSE))
            nethekurse->AI()->DoAction(ACTION_PEON_KILLED);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17471 - Lesser Shadow Fissure
struct npc_lesser_shadow_fissure : public ScriptedAI
{
    npc_lesser_shadow_fissure(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(IsHeroic() ? SPELL_CONSUMPTION_H : SPELL_CONSUMPTION);
    }
};

// 18370 - Wild Shadow Fissure
struct npc_wild_shadow_fissure : public ScriptedAI
{
    npc_wild_shadow_fissure(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CONSUMPTION_WILD);
    }
};

// 182539 - Grand Warlock Chamber Door
struct go_grand_warlock_chamber_door : public GameObjectAI
{
    go_grand_warlock_chamber_door(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        if (Creature* nethekurse = _instance->GetCreature(DATA_NETHEKURSE))
            nethekurse->AI()->DoAction(ACTION_START_INTRO);

        return true;
    }

private:
    InstanceScript* _instance;
};

// 30745 - Target Fissures
class spell_grand_warlock_nethekurse_target_fissures : public SpellScript
{
    PrepareSpellScript(spell_grand_warlock_nethekurse_target_fissures);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_FISSURE_2 });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHADOW_FISSURE_2);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_grand_warlock_nethekurse_target_fissures::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_grand_warlock_nethekurse_target_fissures::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 4347
class at_shattered_halls_the_sewer : public AreaTriggerScript
{
public:
    at_shattered_halls_the_sewer() : AreaTriggerScript("at_shattered_halls_the_sewer") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* nethekurse = instance->GetCreature(DATA_NETHEKURSE))
                nethekurse->AI()->DoAction(ACTION_START_INTRO);

        return true;
    }
};

void AddSC_boss_grand_warlock_nethekurse()
{
    RegisterShatteredHallsCreatureAI(boss_grand_warlock_nethekurse);
    RegisterShatteredHallsCreatureAI(npc_fel_orc_convert);
    RegisterShatteredHallsCreatureAI(npc_lesser_shadow_fissure);
    RegisterShatteredHallsCreatureAI(npc_wild_shadow_fissure);
    RegisterShatteredHallsGameObjectAI(go_grand_warlock_chamber_door);
    RegisterSpellScript(spell_grand_warlock_nethekurse_target_fissures);
    new at_shattered_halls_the_sewer();
}
