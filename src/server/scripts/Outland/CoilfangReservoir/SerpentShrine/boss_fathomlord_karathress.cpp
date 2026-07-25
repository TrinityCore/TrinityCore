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
 * Greater Poison Cleansing Totem has no passive spell (nothing found in sniffs). What spell should it use?
 * Seer Olum's event is NYI (should be handled in DB)
 * Damage of fathom pets is too low, core issue (if creature is summoned by spell, damage is quite low)
 * Bestial Wrath cannot be applied on Fathom Lurker and only applies on Fathom Sporebat. The reason is Creature Type Mask = 0x00000001 (BEAST).
   It is unclear if this is an issue or not
 * Sharkkis should be able to summon multiple pets, at this moment he can have only one summoned pet per time
 * Transform spells (handled in SAI for each totem) for totems cannot be casted by totems because of Totem::IsImmunedToSpellEffect (SPELL_AURA_TRANSFORM)
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "serpent_shrine.h"

enum KarathressTexts
{
    SAY_AGGRO                       = 0,
    SAY_GAIN_BLESSING               = 1,
    SAY_GAIN_ABILITY                = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4
};

enum KarathressSpells
{
    // Karathress
    SPELL_CATACLYSMIC_BOLT          = 38441,
    SPELL_SEAR_NOVA                 = 38445,
    SPELL_BERSERK                   = 27680,

    // Sharkkis
    SPELL_LEECHING_THROW            = 29436,
    SPELL_THE_BEAST_WITHIN          = 38373,
    SPELL_MULTI_TOSS                = 38366,
    SPELL_SUMMON_FATHOM_LURKER      = 38433,
    SPELL_SUMMON_FATHOM_SPOREBAT    = 38431,

    // Tidalvess
    SPELL_WINDFURY                  = 38184,
    SPELL_FROST_SHOCK               = 38234,
    SPELL_SPITFIRE_TOTEM            = 38236,
    SPELL_EARTHBIND_TOTEM           = 38304,
    SPELL_POISON_CLEANSING_TOTEM    = 38306,

    // Caribdis
    SPELL_WATER_BOLT_VOLLEY         = 38335,
    SPELL_TIDAL_SURGE               = 38358,
    SPELL_SUMMON_CYCLONE            = 38337,
    SPELL_HEALING_WAVE              = 38330,

    // Cyclone
    SPELL_CYCLONE_WATER_VISUAL      = 38497,
    SPELL_CYCLONE_WATER_VISUAL_2    = 38464,
    SPELL_CYCLONE_KNOCK_BACK        = 38516,
    SPELL_CYCLONE_KNOCK_BACK_2      = 38518,
    SPELL_DREAM_FOG                 = 24780,

    // Misc
    SPELL_POWER_OF_SHARKKIS         = 38455,
    SPELL_POWER_OF_TIDALVESS        = 38452,
    SPELL_POWER_OF_CARIBDIS         = 38451,

    SPELL_BLESSING_OF_THE_TIDES     = 38449,

    SPELL_TIDAL_SURGE_EFFECT        = 38353,
    SPELL_BESTIAL_WRATH             = 38371
};

enum KarathressEvents
{
    // Karathress
    EVENT_CATACLYSMIC_BOLT          = 1,
    EVENT_SEAR_NOVA,
    EVENT_BERSERK,

    // Sharkkis
    EVENT_LEECHING_THROW,
    EVENT_THE_BEAST_WITHIN,
    EVENT_MULTI_TOSS,
    EVENT_SUMMON_FATHOM_PET,

    // Tidalvess
    EVENT_FROST_SHOCK,
    EVENT_SPITFIRE_TOTEM,
    EVENT_EARTHBIND_TOTEM,
    EVENT_POISON_CLEANSING_TOTEM,

    // Caribdis
    EVENT_WATER_BOLT_VOLLEY,
    EVENT_TIDAL_SURGE,
    EVENT_SUMMON_CYCLONE,
    EVENT_HEALING_WAVE
};

enum KarathressMisc
{
    SPAWN_GROUP_CARIBDIS            = 399,
    SPAWN_GROUP_TIDALVESS           = 400,
    SPAWN_GROUP_SHARKKIS            = 401,
    ACTION_GIVE_BLESSING            = 0
};

static constexpr std::array<uint32, 3> FathomGuardSpawnGroupsData =
{
    SPAWN_GROUP_CARIBDIS,
    SPAWN_GROUP_TIDALVESS,
    SPAWN_GROUP_SHARKKIS
};

// 21214 - Fathom-Lord Karathress
struct boss_fathomlord_karathress : public BossAI
{
    boss_fathomlord_karathress(Creature* creature) : BossAI(creature, BOSS_FATHOM_LORD_KARATHRESS),
        _blessingOfTides(false), _performedEmote(false) { }

    void JustAppeared() override
    {
        for (uint32 group : FathomGuardSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CATACLYSMIC_BOLT, 5s, 10s);
        events.ScheduleEvent(EVENT_SEAR_NOVA, 40s, 50s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_POWER_OF_SHARKKIS:
            case SPELL_POWER_OF_TIDALVESS:
            case SPELL_POWER_OF_CARIBDIS:
                Talk(SAY_GAIN_ABILITY);
                break;
            case SPELL_BLESSING_OF_THE_TIDES:
                if (!_performedEmote)
                {
                    Talk(SAY_GAIN_BLESSING);
                    _performedEmote = true;
                }
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_blessingOfTides && me->HealthBelowPctDamaged(75, damage))
        {
            _blessingOfTides = true;

            for (uint32 data : { DATA_CARIBDIS, DATA_TIDALVESS, DATA_SHARKKIS })
                if (Creature* guard = instance->GetCreature(data))
                    if (guard->IsAlive())
                        guard->AI()->DoAction(ACTION_GIVE_BLESSING);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 group : FathomGuardSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);

        summons.DespawnAll();
        _DespawnAtEvade();
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
                case EVENT_CATACLYSMIC_BOLT:
                    if (me->GetThreatManager().GetThreatListPlayerCount() > 1)
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 80.0f, true))
                            DoCast(target, SPELL_CATACLYSMIC_BOLT);
                    events.Repeat(6s, 12s);
                    break;
                case EVENT_SEAR_NOVA:
                    DoCastSelf(SPELL_SEAR_NOVA);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
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
    bool _blessingOfTides;
    bool _performedEmote;
};

struct FathomGuardBaseAI : public ScriptedAI
{
    FathomGuardBaseAI(Creature* creature) : ScriptedAI(creature), Instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        Events.Reset();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_GIVE_BLESSING)
            DoCastSelf(SPELL_BLESSING_OF_THE_TIDES, true);
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* karathress = Instance->GetCreature(BOSS_FATHOM_LORD_KARATHRESS))
            karathress->AI()->JustSummoned(summon);
    }

    virtual void ExecuteEvent(uint32 const eventId) = 0;

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            ExecuteEvent(eventId);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

protected:
    InstanceScript* Instance;
    EventMap Events;
};

// 21966 - Fathom-Guard Sharkkis
struct boss_fathomguard_sharkkis : public FathomGuardBaseAI
{
    using FathomGuardBaseAI::FathomGuardBaseAI;

    void JustEngagedWith(Unit* /*who*/) override
    {
        Events.ScheduleEvent(EVENT_LEECHING_THROW, 5s, 10s);
        Events.ScheduleEvent(EVENT_THE_BEAST_WITHIN, 30s, 40s);
        Events.ScheduleEvent(EVENT_MULTI_TOSS, 20s, 30s);
        Events.ScheduleEvent(EVENT_SUMMON_FATHOM_PET, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_POWER_OF_SHARKKIS);
    }

    void ExecuteEvent(uint32 eventId)
    {
        switch (eventId)
        {
            case EVENT_LEECHING_THROW:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_LEECHING_THROW);
                Events.Repeat(5s, 10s);
                break;
            case EVENT_THE_BEAST_WITHIN:
                DoCastSelf(SPELL_THE_BEAST_WITHIN);
                Events.Repeat(30s, 40s);
                break;
            case EVENT_MULTI_TOSS:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_MULTI_TOSS);
                Events.Repeat(20s, 30s);
                break;
            case EVENT_SUMMON_FATHOM_PET:
                DoCastSelf(RAND(SPELL_SUMMON_FATHOM_LURKER, SPELL_SUMMON_FATHOM_SPOREBAT));
                Events.Repeat(30s);
                break;
            default:
                break;
        }
    }
};

// 21965 - Fathom-Guard Tidalvess
struct boss_fathomguard_tidalvess : public FathomGuardBaseAI
{
    using FathomGuardBaseAI::FathomGuardBaseAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_WINDFURY);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Events.ScheduleEvent(EVENT_FROST_SHOCK, 10s, 15s);
        Events.ScheduleEvent(EVENT_SPITFIRE_TOTEM, 10s, 15s);
        Events.ScheduleEvent(EVENT_EARTHBIND_TOTEM, 15s, 25s);
        Events.ScheduleEvent(EVENT_POISON_CLEANSING_TOTEM, 20s, 30s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_POWER_OF_TIDALVESS);
    }

    void ExecuteEvent(uint32 eventId)
    {
        switch (eventId)
        {
            case EVENT_FROST_SHOCK:
                DoCastVictim(SPELL_FROST_SHOCK);
                Events.Repeat(10s, 15s);
                break;
            case EVENT_SPITFIRE_TOTEM:
                DoCastSelf(SPELL_SPITFIRE_TOTEM);
                Events.Repeat(40s, 60s);
                break;
            case EVENT_EARTHBIND_TOTEM:
                DoCastSelf(SPELL_EARTHBIND_TOTEM);
                Events.Repeat(40s, 60s);
                break;
            case EVENT_POISON_CLEANSING_TOTEM:
                DoCastSelf(SPELL_POISON_CLEANSING_TOTEM);
                Events.Repeat(30s, 50s);
                break;
            default:
                break;
        }
    }
};

// 21964 - Fathom-Guard Caribdis
struct boss_fathomguard_caribdis : public FathomGuardBaseAI
{
    using FathomGuardBaseAI::FathomGuardBaseAI;

    void JustEngagedWith(Unit* /*who*/) override
    {
        Events.ScheduleEvent(EVENT_WATER_BOLT_VOLLEY, 15s, 25s);
        Events.ScheduleEvent(EVENT_TIDAL_SURGE, 15s, 20s);
        Events.ScheduleEvent(EVENT_SUMMON_CYCLONE, 10s, 25s);
        Events.ScheduleEvent(EVENT_HEALING_WAVE, 15s, 25s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_POWER_OF_CARIBDIS);
    }

    void ExecuteEvent(uint32 eventId)
    {
        switch (eventId)
        {
            case EVENT_WATER_BOLT_VOLLEY:
                DoCastSelf(SPELL_WATER_BOLT_VOLLEY);
                Events.Repeat(10s, 30s);
                break;
            case EVENT_TIDAL_SURGE:
                DoCastSelf(SPELL_TIDAL_SURGE);
                Events.Repeat(15s, 25s);
                break;
            case EVENT_SUMMON_CYCLONE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_SUMMON_CYCLONE);
                Events.Repeat(40s, 50s);
                break;
            case EVENT_HEALING_WAVE:
                if (Unit* target = DoSelectLowestHpFriendly(250.0f))
                    DoCast(target, SPELL_HEALING_WAVE);
                Events.Repeat(15s, 20s);
                break;
            default:
                break;
        }
    }
};

// 22104 - Cyclone (Karathress)
struct npc_fathomlord_karathress_cyclone : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CYCLONE_WATER_VISUAL);
        DoCastSelf(SPELL_CYCLONE_WATER_VISUAL_2);
        DoCastSelf(SPELL_CYCLONE_KNOCK_BACK);
        /// @todo: Seems like on retail this aura does not trigger spell despite this aura is shown in sniffs in aura update packet. Also using this makes
        /// cyclone overpowered and creates behavior we don't see in movies. Same problem occurs in Karazhan's Wizard of Oz. Investigate this
        /// DoCastSelf(SPELL_CYCLONE_KNOCK_BACK_2);
        /// @todo: After first tick makes creature stop movement, the reason is the script linked to this spell
        /// DoCastSelf(SPELL_DREAM_FOG);

        _scheduler.Schedule(10s, [this](TaskContext task)
        {
            DoZoneInCombat();

            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
            {
                ResetThreatList();
                AddThreat(target, 1000000.0f);
                AttackStart(target);
            }
            task.Repeat(10s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 38358 - Tidal Surge
class spell_fathomlord_karathress_tidal_surge : public SpellScript
{
    PrepareSpellScript(spell_fathomlord_karathress_tidal_surge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TIDAL_SURGE_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_TIDAL_SURGE_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fathomlord_karathress_tidal_surge::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 38373 - The Beast Within
class spell_fathomlord_karathress_the_beast_within : public SpellScript
{
    PrepareSpellScript(spell_fathomlord_karathress_the_beast_within);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BESTIAL_WRATH });
    }

    void HandleCast()
    {
        GetCaster()->CastSpell(nullptr, SPELL_BESTIAL_WRATH, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_fathomlord_karathress_the_beast_within::HandleCast);
    }
};

void AddSC_boss_fathomlord_karathress()
{
    RegisterSerpentshrineCavernCreatureAI(boss_fathomlord_karathress);
    RegisterSerpentshrineCavernCreatureAI(boss_fathomguard_sharkkis);
    RegisterSerpentshrineCavernCreatureAI(boss_fathomguard_tidalvess);
    RegisterSerpentshrineCavernCreatureAI(boss_fathomguard_caribdis);
    RegisterSerpentshrineCavernCreatureAI(npc_fathomlord_karathress_cyclone);
    RegisterSpellScript(spell_fathomlord_karathress_tidal_surge);
    RegisterSpellScript(spell_fathomlord_karathress_the_beast_within);
}
