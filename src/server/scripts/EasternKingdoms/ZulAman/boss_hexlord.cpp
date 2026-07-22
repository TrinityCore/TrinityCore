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
 * SAY_BERSERK is NYI, is it used?
 * Combat timers requires to be revisited, mainly player class abilities, half of timers are guessed
 * Move spell script of spell 43421 to this file
 * Currently we generate random companions after every wipe, doubt it is correct
 */

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "zulaman.h"

enum MalacrassTexts
{
    SAY_AGGRO                     = 0,
    SAY_BERSERK                   = 1,
    SAY_SLAY                      = 2,
    SAY_CHARM                     = 3,
    SAY_DRAIN_POWER               = 4,
    SAY_SPIRIT_BOLTS              = 5,
    SAY_PET_DIES                  = 6,
    SAY_DEATH                     = 7
};

enum MalacrassSpells
{
    // Malacrass
    SPELL_SPIRIT_BOLTS            = 43383,
    SPELL_SIPHON_SOUL             = 43498,
    SPELL_DRAIN_POWER             = 44131,

    // Warrior
    SPELL_WR_MORTAL_STRIKE        = 43441,
    SPELL_WR_HEROIC_LEAP          = 97521,
    SPELL_WR_SPELL_REFLECTION     = 43443,

    // Paladin
    SPELL_PA_CONSECRATION         = 43429,
    SPELL_PA_AVENGING_WRATH       = 43430,
    SPELL_PA_HOLY_LIGHT           = 43451,

    // Hunter
    SPELL_HU_EXPLOSIVE_TRAP       = 43444,
    SPELL_HU_FREEZING_TRAP        = 43447,
    SPELL_HU_SNAKE_TRAP           = 43449,

    // Rogue
    SPELL_RO_SMOKE_BOMB           = 97643,
    SPELL_RO_WOUND_POISON         = 43461,
    SPELL_RO_SLICE_AND_DICE       = 43547,

    // Priest
    SPELL_PR_FLASH_HEAL           = 43431,
    SPELL_PR_PSYCHIC_SCREAM       = 43432,
    SPELL_PR_LEAP_OF_FAITH        = 97640,
    SPELL_PR_SHADOW_WORD_PAIN     = 97642,

    // Death Knight
    SPELL_DK_PLAGUE_STRIKE        = 61600,
    SPELL_DK_DEATH_AND_DECAY      = 61603,
    SPELL_DK_BLOOD_WORMS          = 97628,

    // Shaman
    SPELL_SH_CHAIN_LIGHTNING      = 43435,
    SPELL_SH_FIRE_NOVA_TOTEM      = 43436,
    SPELL_SH_HEALING_WAVE         = 43548,

    // Mage
    SPELL_MG_FROST_NOVA           = 43426,
    SPELL_MG_ICE_LANCE            = 43427,
    SPELL_MG_FROSTBOLT            = 43428,

    // Warlock
    SPELL_WL_CURSE_OF_DOOM        = 43439,
    SPELL_WL_RAIN_OF_FIRE         = 43440,
    SPELL_WL_UNSTABLE_AFFLICTION  = 43522,

    // Monk
    SPELL_MK_RISING_SUN_KICK      = 127734,
    SPELL_MK_HEX_SPHERE           = 127737,
    SPELL_MK_RENEWING_MIST        = 127735,

    // Druid
    SPELL_DR_TYPHOON              = 97636,
    SPELL_DR_LIFEBLOOM            = 43421,
    SPELL_DR_MOONFIRE             = 43545,

    // Alyson Antille
    SPELL_ARCANE_TORRENT          = 33390,
    SPELL_FLASH_HEAL              = 43575,
    SPELL_DISPEL_MAGIC            = 43577,

    // Thurg
    SPELL_CLEAVE                  = 15496,
    SPELL_BLOODLUST               = 43578,

    // Slither
    SPELL_VENOM_SPIT              = 43579,
    SPELL_DEADLY_POISON           = 43580,

    // Lord Raadan
    SPELL_FLAME_BREATH            = 43582,
    SPELL_THUNDERCLAP             = 43583,

    // Gazakroth
    SPELL_FIREBOLT                = 43584,

    // Fenstalker
    SPELL_VOLATILE_INFECTION      = 43586,

    // Darkheart
    SPELL_PSYCHIC_WAIL            = 43590,

    // Koragg
    SPELL_MIGHTY_BLOW             = 43592,
    SPELL_COLD_STARE              = 43593,

    // Scripts
    SPELL_UNSTABLE_AFFL_DISPEL    = 43523,
    SPELL_SIPHON_SOUL_EFFECT      = 43501,
    SPELL_MARK_OF_BLOOD_HEAL      = 61607,
    SPELL_BLOOD_WORMS_HEAL        = 97630,
    SPELL_HEX_SPHERE_DAMAGE       = 127741
};

enum MalacrassEvents
{
    EVENT_SPIRIT_BOLTS            = 1,
    EVENT_SIPHON_SOUL,
    EVENT_DRAIN_POWER,
    EVENT_CANCEL_CLASS_ABILITIES,

    // Warrior
    EVENT_WR_MORTAL_STRIKE,
    EVENT_WR_HEROIC_LEAP,
    EVENT_WR_SPELL_REFLECTION,

    // Paladin
    EVENT_PA_CONSECRATION,
    EVENT_PA_AVENGING_WRATH,
    EVENT_PA_HOLY_LIGHT,

    // Hunter
    EVENT_HU_EXPLOSIVE_TRAP,
    EVENT_HU_FREEZING_TRAP,
    EVENT_HU_SNAKE_TRAP,

    // Rogue
    EVENT_RO_SMOKE_BOMB,
    EVENT_RO_WOUND_POISON,
    EVENT_RO_SLICE_AND_DICE,

    // Priest
    EVENT_PR_FLASH_HEAL,
    EVENT_PR_PSYCHIC_SCREAM,
    EVENT_PR_LEAP_OF_FAITH,
    EVENT_PR_SHADOW_WORD_PAIN,

    // Death Knight
    EVENT_DK_PLAGUE_STRIKE,
    EVENT_DK_DEATH_AND_DECAY,
    EVENT_DK_BLOOD_WORMS,

    // Shaman
    EVENT_SH_CHAIN_LIGHTNING,
    EVENT_SH_FIRE_NOVA_TOTEM,
    EVENT_SH_HEALING_WAVE,

    // Mage
    EVENT_MG_FROST_NOVA,
    EVENT_MG_ICE_LANCE,
    EVENT_MG_FROSTBOLT,

    // Warlock
    EVENT_WL_CURSE_OF_DOOM,
    EVENT_WL_RAIN_OF_FIRE,
    EVENT_WL_UNSTABLE_AFFLICTION,

    // Monk
    EVENT_MK_RISING_SUN_KICK,
    EVENT_MK_HEX_SPHERE,
    EVENT_MK_RENEWING_MIST,

    // Druid
    EVENT_DR_TYPHOON,
    EVENT_DR_LIFEBLOOM,
    EVENT_DR_MOONFIRE
};

enum MalacrassEventGroups
{
    EVENT_GROUP_PLAYER_ABILITY    = 1
};

enum MalacrassMisc
{
    ACTION_COMPANION_DEATH        = 0,
    DATA_PLAYER_CLASS             = 0
};

static constexpr std::array<std::array<uint32, 2>, 2> MalacrassSpawnGroups =
{{
    {{ 368, 370 }},
    {{ 372, 374 }}
}};

// 24239 - Hex Lord Malacrass
struct boss_hexlord_malacrass : public BossAI
{
    boss_hexlord_malacrass(Creature* creature) : BossAI(creature, BOSS_HEXLORD), _canUseDrainPower(false) { }

    void JustAppeared() override
    {
        DoSpawnCompanions();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SPIRIT_BOLTS, 30s);
        events.ScheduleEvent(EVENT_SIPHON_SOUL, 40s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_canUseDrainPower && me->HealthBelowPctDamaged(80, damage))
        {
            _canUseDrainPower = true;
            _specialEvents.ScheduleEvent(EVENT_DRAIN_POWER, 0s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_COMPANION_DEATH)
            Talk(SAY_PET_DIES);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_PLAYER_CLASS)
        {
            if (data > CLASS_NONE && data <= CLASS_DRUID)
            {
                switch (data)
                {
                    case CLASS_WARRIOR:
                        _specialEvents.ScheduleEvent(EVENT_WR_MORTAL_STRIKE, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_WR_HEROIC_LEAP, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_WR_SPELL_REFLECTION, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_PALADIN:
                        _specialEvents.ScheduleEvent(EVENT_PA_CONSECRATION, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_PA_AVENGING_WRATH, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_PA_HOLY_LIGHT, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_HUNTER:
                        _specialEvents.ScheduleEvent(EVENT_HU_EXPLOSIVE_TRAP, 5s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_HU_FREEZING_TRAP, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_HU_SNAKE_TRAP, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_ROGUE:
                        _specialEvents.ScheduleEvent(EVENT_RO_SMOKE_BOMB, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_RO_WOUND_POISON, 0s, 5s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_RO_SLICE_AND_DICE, 0s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_PRIEST:
                        _specialEvents.ScheduleEvent(EVENT_PR_FLASH_HEAL, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_PR_PSYCHIC_SCREAM, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_PR_LEAP_OF_FAITH, 5s, 25s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_PR_SHADOW_WORD_PAIN, 3s, 4s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        _specialEvents.ScheduleEvent(EVENT_DK_PLAGUE_STRIKE, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_DK_DEATH_AND_DECAY, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_DK_BLOOD_WORMS, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_SHAMAN:
                        _specialEvents.ScheduleEvent(EVENT_SH_CHAIN_LIGHTNING, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_SH_FIRE_NOVA_TOTEM, 10s, 20s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_SH_HEALING_WAVE, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_MAGE:
                        _specialEvents.ScheduleEvent(EVENT_MG_FROST_NOVA, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_MG_ICE_LANCE, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_MG_FROSTBOLT, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_WARLOCK:
                        _specialEvents.ScheduleEvent(EVENT_WL_CURSE_OF_DOOM, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_WL_RAIN_OF_FIRE, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_WL_UNSTABLE_AFFLICTION, 5s, 10s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_MONK:
                        _specialEvents.ScheduleEvent(EVENT_MK_RISING_SUN_KICK, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_MK_HEX_SPHERE, 8s, 14s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_MK_RENEWING_MIST, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    case CLASS_DRUID:
                        _specialEvents.ScheduleEvent(EVENT_DR_TYPHOON, 0s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_DR_LIFEBLOOM, 10s, 15s, EVENT_GROUP_PLAYER_ABILITY);
                        _specialEvents.ScheduleEvent(EVENT_DR_MOONFIRE, 3s, 4s, EVENT_GROUP_PLAYER_ABILITY);
                        break;
                    default:
                        break;
                }

                _specialEvents.ScheduleEvent(EVENT_CANCEL_CLASS_ABILITIES, 30s);
            }
        }
    }

    void DoSpawnCompanions()
    {
        for (std::array<uint32, 2> const& spawnGroupsForSlot : MalacrassSpawnGroups)
            me->GetMap()->SpawnGroupSpawn(Trinity::Containers::SelectRandomContainerElement(spawnGroupsForSlot), true);
    }

    void DoDespawnCompanions()
    {
        for (std::array<uint32, 2> const& spawnGroupsForSlot : MalacrassSpawnGroups)
            for (uint32 spawnGroupId : spawnGroupsForSlot)
                me->GetMap()->SpawnGroupDespawn(spawnGroupId);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SPIRIT_BOLTS:
                Talk(SAY_SPIRIT_BOLTS);
                break;
            case SPELL_SIPHON_SOUL:
                Talk(SAY_CHARM);
                break;
            case SPELL_DRAIN_POWER:
                Talk(SAY_DRAIN_POWER);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();

        DoDespawnCompanions();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        DoDespawnCompanions();
    }

    void UpdateSpecialEvents(uint32 diff)
    {
        _specialEvents.Update(diff);

        if (me->FindCurrentSpellBySpellId(SPELL_SPIRIT_BOLTS) ||
            me->FindCurrentSpellBySpellId(SPELL_PA_HOLY_LIGHT) ||
            me->FindCurrentSpellBySpellId(SPELL_PR_FLASH_HEAL) ||
            me->FindCurrentSpellBySpellId(SPELL_SH_CHAIN_LIGHTNING) ||
            me->FindCurrentSpellBySpellId(SPELL_SH_HEALING_WAVE) ||
            me->FindCurrentSpellBySpellId(SPELL_MG_FROSTBOLT) ||
            me->FindCurrentSpellBySpellId(SPELL_MK_RENEWING_MIST))
            return;

        while (uint32 eventId = _specialEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DRAIN_POWER:
                    DoCastSelf(SPELL_DRAIN_POWER);
                    _specialEvents.Repeat(30s);
                    break;

                case EVENT_WR_MORTAL_STRIKE:
                    DoCastVictim(SPELL_WR_MORTAL_STRIKE);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_WR_HEROIC_LEAP:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_WR_HEROIC_LEAP);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_WR_SPELL_REFLECTION:
                    DoCastSelf(SPELL_WR_SPELL_REFLECTION);
                    _specialEvents.Repeat(10s);
                    break;

                case EVENT_PA_CONSECRATION:
                    DoCastSelf(SPELL_PA_CONSECRATION);
                    _specialEvents.Repeat(20s, 25s);
                    break;
                case EVENT_PA_AVENGING_WRATH:
                    DoCastSelf(SPELL_PA_AVENGING_WRATH);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_PA_HOLY_LIGHT:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_PA_HOLY_LIGHT);
                    _specialEvents.Repeat(10s, 15s);
                    break;

                case EVENT_HU_EXPLOSIVE_TRAP:
                    DoCastSelf(SPELL_HU_EXPLOSIVE_TRAP);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_HU_FREEZING_TRAP:
                    DoCastSelf(SPELL_HU_FREEZING_TRAP);
                    _specialEvents.Repeat(10s, 20s);
                    break;
                case EVENT_HU_SNAKE_TRAP:
                    DoCastSelf(SPELL_HU_SNAKE_TRAP);
                    _specialEvents.Repeat(10s, 20s);
                    break;

                case EVENT_RO_SMOKE_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 10.0f))
                        DoCast(target, SPELL_RO_SMOKE_BOMB);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_RO_WOUND_POISON:
                    DoCastVictim(SPELL_RO_WOUND_POISON);
                    _specialEvents.Repeat(0s, 5s);
                    break;
                case EVENT_RO_SLICE_AND_DICE:
                    DoCastSelf(SPELL_RO_SLICE_AND_DICE);
                    _specialEvents.Repeat(40s);
                    break;

                case EVENT_PR_FLASH_HEAL:
                    DoCastSelf(SPELL_PR_FLASH_HEAL);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_PR_PSYCHIC_SCREAM:
                    DoCastSelf(SPELL_PR_PSYCHIC_SCREAM);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_PR_LEAP_OF_FAITH:
                    DoCastSelf(SPELL_PR_LEAP_OF_FAITH);
                    break;
                case EVENT_PR_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_PR_SHADOW_WORD_PAIN);
                    _specialEvents.Repeat(10s, 15s);
                    break;

                case EVENT_DK_PLAGUE_STRIKE:
                    DoCastVictim(SPELL_DK_PLAGUE_STRIKE);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_DK_DEATH_AND_DECAY:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_DK_DEATH_AND_DECAY);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_DK_BLOOD_WORMS:
                    DoCastSelf(SPELL_DK_BLOOD_WORMS);
                    _specialEvents.Repeat(10s, 15s);
                    break;

                case EVENT_SH_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_SH_CHAIN_LIGHTNING);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_SH_FIRE_NOVA_TOTEM:
                    DoCastSelf(SPELL_SH_FIRE_NOVA_TOTEM);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_SH_HEALING_WAVE:
                    DoCastSelf(SPELL_SH_HEALING_WAVE);
                    _specialEvents.Repeat(10s, 15s);
                    break;

                case EVENT_MG_FROST_NOVA:
                    DoCastSelf(SPELL_MG_FROST_NOVA);
                    _specialEvents.Repeat(15s, 20s);
                    break;
                case EVENT_MG_ICE_LANCE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_MG_ICE_LANCE);
                    _specialEvents.Repeat(5s, 10s);
                    break;
                case EVENT_MG_FROSTBOLT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_MG_FROSTBOLT);
                    _specialEvents.Repeat(5s, 10s);
                    break;

                case EVENT_WL_CURSE_OF_DOOM:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_WL_CURSE_OF_DOOM))
                        DoCast(target, SPELL_WL_CURSE_OF_DOOM);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_WL_RAIN_OF_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f))
                        DoCast(target, SPELL_WL_RAIN_OF_FIRE);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_WL_UNSTABLE_AFFLICTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_WL_UNSTABLE_AFFLICTION))
                        DoCast(target, SPELL_WL_UNSTABLE_AFFLICTION);
                    _specialEvents.Repeat(5s, 10s);
                    break;

                case EVENT_MK_RISING_SUN_KICK:
                    DoCastVictim(SPELL_MK_RISING_SUN_KICK);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_MK_HEX_SPHERE:
                    DoCastSelf(SPELL_MK_HEX_SPHERE);
                    _specialEvents.Repeat(8s, 14s);
                    break;
                case EVENT_MK_RENEWING_MIST:
                    DoCastSelf(SPELL_MK_RENEWING_MIST);
                    _specialEvents.Repeat(10s);
                    break;

                case EVENT_DR_TYPHOON:
                    DoCastVictim(SPELL_DR_TYPHOON);
                    _specialEvents.Repeat(40s);
                    break;
                case EVENT_DR_LIFEBLOOM:
                    DoCastSelf(SPELL_DR_LIFEBLOOM);
                    _specialEvents.Repeat(10s, 15s);
                    break;
                case EVENT_DR_MOONFIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_DR_MOONFIRE);
                    _specialEvents.Repeat(3s, 4s);
                    break;

                case EVENT_CANCEL_CLASS_ABILITIES:
                    _specialEvents.CancelEventGroup(EVENT_GROUP_PLAYER_ABILITY);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        UpdateSpecialEvents(diff);

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SPIRIT_BOLTS:
                    DoCastSelf(SPELL_SPIRIT_BOLTS);
                    events.Repeat(40s);
                    break;
                case EVENT_SIPHON_SOUL:
                    DoCastSelf(SPELL_SIPHON_SOUL);
                    events.Repeat(60s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _canUseDrainPower;
    EventMap _specialEvents;
};

struct MalacrassCompanionBaseAI : public ScriptedAI
{
    MalacrassCompanionBaseAI(Creature* creature) : ScriptedAI(creature), Instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);

        Scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });

        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        Scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* malacrass = Instance->GetCreature(BOSS_HEXLORD))
            malacrass->AI()->DoAction(ACTION_COMPANION_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Scheduler.Update(diff);
    }

protected:
    InstanceScript* Instance;
    TaskScheduler Scheduler;
};

// 24240 - Alyson Antille
struct boss_alyson_antille : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(10s, 20s, [this](TaskContext& task)
            {
                DoCastSelf(SPELL_ARCANE_TORRENT);
                task.Repeat(10s, 20s);
            })
            .Schedule(0s, 5s, [this](TaskContext& task)
            {
                if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                    DoCast(target, SPELL_FLASH_HEAL);
                task.Repeat(5s, 10s);
            })
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                Unit* target = nullptr;

                if (urand(0, 1))
                    target = DoSelectLowestHpFriendly(40.0f, 0);
                else
                    target = SelectTarget(SelectTargetMethod::Random, 0);
                if (target)
                    DoCast(target, SPELL_DISPEL_MAGIC);
                task.Repeat(10s, 15s);
            });
    }
};

// 24241 - Thurg
struct boss_thurg : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                DoCastVictim(SPELL_CLEAVE);
                task.Repeat(10s, 15s);
            })
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                std::list<Creature*> creatureList = DoFindFriendlyMissingBuff(50.0f, SPELL_BLOODLUST);
                if (!creatureList.empty())
                {
                    if (Unit* target = *(creatureList.begin()))
                        DoCast(target, SPELL_BLOODLUST);
                }
                task.Repeat(10s, 15s);
            });
    }
};

// 24242 - Slither
struct boss_slither : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DEADLY_POISON);
    }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, 5s, [this](TaskContext& task)
            {
                DoCastVictim(SPELL_VENOM_SPIT);
                task.Repeat(5s, 10s);
            });
    }
};

// 24243 - Lord Raadan
struct boss_lord_raadan : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                DoCastSelf(SPELL_FLAME_BREATH);
                task.Repeat(10s, 15s);
            })
            .Schedule(0s, 5s, [this](TaskContext& task)
            {
                DoCastSelf(SPELL_THUNDERCLAP);
                task.Repeat(10s, 15s);
            });
    }
};

// 24244 - Gazakroth
struct boss_gazakroth : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext& task)
            {
                DoCastVictim(SPELL_FIREBOLT);
                task.Repeat(1200ms);
            });
    }
};

// 24245 - Fenstalker
struct boss_fenstalker : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true, true, -SPELL_VOLATILE_INFECTION))
                    DoCast(target, SPELL_VOLATILE_INFECTION);
                task.Repeat(15s, 20s);
            });
    }
};

// 24246 - Darkheart
struct boss_darkheart : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                DoCastSelf(SPELL_PSYCHIC_WAIL);
                task.Repeat(15s, 20s);
            });
    }
};

// 24247 - Koragg
struct boss_koragg : public MalacrassCompanionBaseAI
{
    using MalacrassCompanionBaseAI::MalacrassCompanionBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                DoCastVictim(SPELL_MIGHTY_BLOW);
                task.Repeat(10s, 15s);
            })
            .Schedule(10s, 15s, [this](TaskContext& task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                    DoCast(target, SPELL_COLD_STARE);
                task.Repeat(15s, 20s);
            });
    }
};

// 52827 - Blood Worm
struct npc_malacrass_blood_worm : public NullCreatureAI
{
    using NullCreatureAI::NullCreatureAI;

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* hexlord = me->GetInstanceScript()->GetCreature(BOSS_HEXLORD))
            me->GetMotionMaster()->MoveFollow(hexlord, 0.0f, me->GetRelativeAngle(hexlord));
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != FOLLOW_MOTION_TYPE)
            return;

        me->GetMotionMaster()->Clear();
        DoCast(SPELL_BLOOD_WORMS_HEAL);
        me->DespawnOrUnsummon(2s);
    }
};

// 127737 - Hex Sphere
// CreatePropertiesId - 407
struct at_malacrass_hex_sphere : public AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!caster->IsValidAttackTarget(unit, sSpellMgr->GetSpellInfo(SPELL_HEX_SPHERE_DAMAGE, caster->GetMap()->GetDifficultyID())))
            return;

        caster->CastSpell(unit, SPELL_HEX_SPHERE_DAMAGE);
        at->Remove();
    }
};

// 43498 - Siphon Soul
class spell_malacrass_siphon_soul : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SIPHON_SOUL_EFFECT });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // This is wrong, full list of targets is sent to client
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (Creature* caster = GetCaster()->ToCreature())
        {
            caster->CastSpell(target, SPELL_SIPHON_SOUL_EFFECT);
            caster->GetAI()->SetData(DATA_PLAYER_CLASS, target->GetClass());
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malacrass_siphon_soul::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_malacrass_siphon_soul::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 43522 - Unstable Affliction
class spell_malacrass_unstable_affliction : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_AFFL_DISPEL });
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(dispelInfo->GetDispeller(), SPELL_UNSTABLE_AFFL_DISPEL, GetEffect(EFFECT_0));
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_malacrass_unstable_affliction::HandleDispel);
    }
};

// 43550 - Mind Control
class spell_malacrass_mind_control : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // Target count - verified. Removing victim - guessed
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malacrass_mind_control::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 61606 - Mark of Blood
class spell_malacrass_mark_of_blood : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_BLOOD_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_MARK_OF_BLOOD_HEAL, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_malacrass_mark_of_blood::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 97628 - Blood Worms
class spell_malacrass_blood_worms_selector : public SpellScript
{
    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = *Trinity::Containers::SelectRandomWeightedContainerElement(targets, [caster = GetCaster()](WorldObject const* target)
        {
            return std::max(caster->GetExactDist(target) - caster->GetCombatReach(), CONTACT_DISTANCE);
        });
        targets.assign(1, target);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malacrass_blood_worms_selector::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 97640 - Leap of Faith
class spell_malacrass_leap_of_faith_selector : public SpellScript
{
    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.size() < 2)
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), false));
        targets.resize(1);
    }

    void TriggerSpell(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), GetEffectValueAsInt());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malacrass_leap_of_faith_selector::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_malacrass_leap_of_faith_selector::TriggerSpell, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_hex_lord_malacrass()
{
    RegisterZulAmanCreatureAI(boss_hexlord_malacrass);
    RegisterZulAmanCreatureAI(boss_alyson_antille);
    RegisterZulAmanCreatureAI(boss_thurg);
    RegisterZulAmanCreatureAI(boss_slither);
    RegisterZulAmanCreatureAI(boss_lord_raadan);
    RegisterZulAmanCreatureAI(boss_gazakroth);
    RegisterZulAmanCreatureAI(boss_fenstalker);
    RegisterZulAmanCreatureAI(boss_darkheart);
    RegisterZulAmanCreatureAI(boss_koragg);
    RegisterZulAmanCreatureAI(npc_malacrass_blood_worm);
    RegisterAreaTriggerAI(at_malacrass_hex_sphere);
    RegisterSpellScript(spell_malacrass_siphon_soul);
    RegisterSpellScript(spell_malacrass_unstable_affliction);
    RegisterSpellScript(spell_malacrass_mind_control);
    RegisterSpellScript(spell_malacrass_mark_of_blood);
    RegisterSpellScript(spell_malacrass_blood_worms_selector);
    RegisterSpellScript(spell_malacrass_leap_of_faith_selector);
}
