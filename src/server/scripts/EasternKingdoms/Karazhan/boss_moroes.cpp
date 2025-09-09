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
 * Timers requires update
 * Find a more elegant way to force guests into combat & summon guests
 * Currently linked aggro works only if Moroes is aggroed first (guests can be killed without aggroing Moroes)
 * Moroes does not play sound after casting Vanish (SAY_SPECIAL)
 * Behavior while in Vanish requires rechecks, seems like it is not working properly
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "karazhan.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum MoroesTexts
{
    SAY_AGGRO                       = 0,
    SAY_SPECIAL                     = 1,
    SAY_SLAY                        = 2,
    SAY_DEATH                       = 3,
    EMOTE_FRENZY                    = 4
};

enum MoroesSpells
{
    // Moroes
    SPELL_VANISH                    = 29448,
    SPELL_GARROTE_TRIGGER           = 29433,
    SPELL_BLIND                     = 34694,
    SPELL_GOUGE                     = 29425,
    SPELL_FRENZY                    = 37023,

    SPELL_GARROTE                   = 37066,
    SPELL_GARROTE_REMOVE            = 37870,

    // Baroness Dorothea Millstipe
    SPELL_SHADOWFORM                = 29406,
    SPELL_MANA_BURN                 = 29405,
    SPELL_MIND_FLY                  = 29570,
    SPELL_SHADOW_WORD_PAIN          = 34441,

    // Baron Rafe Dreuger
    SPELL_HAMMER_OF_JUSTICE         = 13005,
    SPELL_SEAL_OF_COMMAND           = 29385,
    SPELL_JUDGEMENT_OF_COMMAND      = 29386,

    // Lady Catriona Von'Indi
    SPELL_DISPEL_MAGIC              = 15090,
    SPELL_POWER_WORD_SHIELD         = 29408,
    SPELL_HOLY_FIRE                 = 29563,
    SPELL_GREATER_HEAL              = 29564,

    // Lady Keira Berrybuck
    SPELL_CLEANSE                   = 29380,
    SPELL_GREATER_BLESS_OF_MIGHT    = 29381,
    SPELL_HOLY_LIGHT                = 29562,
    SPELL_DIVINE_SHIELD             = 41367,

    // Lord Robin Daris
    SPELL_HAMSTRING                 = 9080,
    SPELL_MORTAL_STRIKE             = 29572,
    SPELL_WHIRLWIND                 = 29573,

    // Lord Crispin Ference
    SPELL_DISARM                    = 8379,
    SPELL_HEROIC_STRIKE             = 29567,
    SPELL_SHIELD_BASH               = 11972,
    SPELL_SHIELD_WALL               = 29390
};

enum MoroesEvents
{
    EVENT_VANISH                    = 1,
    EVENT_GARROTE,
    EVENT_BLIND,
    EVENT_GOUGE,
    EVENT_FRENZY
};

Position const Locations[4] =
{
    {-10991.0f, -1884.33f, 81.73f, 0.614315f},
    {-10989.4f, -1885.88f, 81.73f, 0.904913f},
    {-10978.1f, -1887.07f, 81.73f, 2.035550f},
    {-10975.9f, -1885.81f, 81.73f, 2.253890f},
};

constexpr std::array<uint32, 6> Adds =
{
    17007,
    19872,
    19873,
    19874,
    19875,
    19876,
};

// 15687 - Moroes
struct boss_moroes : public BossAI
{
    boss_moroes(Creature* creature) : BossAI(creature, DATA_MOROES), _frenzied(false), AddId()
    {
    }

    void Reset() override
    {
        _Reset();
        _frenzied = false;

        if (me->IsAlive())
            SpawnGuests();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        GuestsAttack();

        events.ScheduleEvent(EVENT_VANISH, 35s);
        events.ScheduleEvent(EVENT_BLIND, 35s);
        events.ScheduleEvent(EVENT_GOUGE, 23s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_frenzied && me->HealthBelowPctDamaged(30, damage))
        {
            _frenzied = true;
            events.ScheduleEvent(EVENT_FRENZY, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_VANISH:
                Talk(SAY_SPECIAL);
                break;
            case SPELL_FRENZY:
                Talk(EMOTE_FRENZY);
                break;
            default:
                break;
        }
    }

    // Do not despawn guests
    void JustSummoned(Creature* /*summon*/) override { }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        DoCastSelf(SPELL_GARROTE_REMOVE);
    }

    void SpawnGuests()
    {
        if (IsGuestListEmpty())
        {
            std::array<uint32, 6> AddList = Adds;

            Trinity::Containers::RandomShuffle(AddList);

            for (std::size_t i = 0; i < AddId.size(); ++i)
                AddId[i] = AddList[i];
        }
        else
            DespawnGuests();

        for (std::size_t i = 0; i < AddId.size(); ++i)
            if (Creature* creature = me->SummonCreature(AddId[i], Locations[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s))
                AddGUID[i] = creature->GetGUID();
    }

    bool IsGuestListEmpty()
    {
        return std::ranges::find(AddId, 0u) != AddId.end();
    }

    void DespawnGuests()
    {
        for (ObjectGuid addGuid : AddGUID)
            if (!addGuid.IsEmpty())
                if (Creature* temp = ObjectAccessor::GetCreature(*me, addGuid))
                    temp->DespawnOrUnsummon();
    }

    void GuestsAttack()
    {
        for (ObjectGuid addGuid : AddGUID)
        {
            if (!addGuid.IsEmpty())
            {
                Creature* temp = ObjectAccessor::GetCreature(*me, addGuid);
                if (temp && temp->IsAlive())
                {
                    temp->AI()->AttackStart(me->GetVictim());
                    DoZoneInCombat(temp);
                }
                else
                    EnterEvadeMode();
            }
        }
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
                case EVENT_VANISH:
                    DoCastSelf(SPELL_VANISH);
                    events.ScheduleEvent(EVENT_GARROTE, 3s, 9s);
                    events.Repeat(45s, 50s);
                    break;
                case EVENT_GARROTE:
                    me->RemoveAurasDueToSpell(SPELL_VANISH);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 10.0f, true))
                        // Ignore Stealthed Only attribute
                        DoCast(target, SPELL_GARROTE_TRIGGER, true);
                    break;
                case EVENT_BLIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 10.0f, true))
                        DoCast(target, SPELL_BLIND);
                    events.Repeat(40s);
                    break;
                case EVENT_GOUGE:
                    DoCastVictim(SPELL_GOUGE);
                    events.Repeat(23s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
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
    bool _frenzied;
    std::array<ObjectGuid, 4> AddGUID;
    std::array<uint32, 4> AddId;
};

struct GuestBaseAI : public ScriptedAI
{
    GuestBaseAI(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        scheduler.CancelAll();
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

protected:
    TaskScheduler scheduler;
};

// 19875 - Baroness Dorothea Millstipe (Shadow Priest)
struct boss_baroness_dorothea_millstipe : public GuestBaseAI
{
    boss_baroness_dorothea_millstipe(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(0s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_SHADOWFORM);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                    if (target->GetPowerType() == POWER_MANA)
                        DoCast(target, SPELL_MANA_BURN);
                task.Repeat(10s, 20s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_MIND_FLY);
                task.Repeat(15s, 25s);
            })
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                    DoCast(target, SPELL_SHADOW_WORD_PAIN);
                task.Repeat(20s, 30s);
            });
    }
};

// 19874 - Baron Rafe Dreuger (Retribution Paladin)
struct boss_baron_rafe_dreuger : public GuestBaseAI
{
    boss_baron_rafe_dreuger(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                task.Repeat(20s, 30s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SEAL_OF_COMMAND);
                task.Repeat(20s, 25s);
            })
            .Schedule(5s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                task.Repeat(10s, 20s);
            });
    }
};

// 19872 - Lady Catriona Von'Indi (Holy Priest)
struct boss_lady_catriona_von_indi : public GuestBaseAI
{
    boss_lady_catriona_von_indi(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                    DoCast(target, SPELL_DISPEL_MAGIC);
                task.Repeat(20s, 30s);
            })
            .Schedule(15s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_POWER_WORD_SHIELD);
                task.Repeat(15s, 20s);
            })
            .Schedule(5s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HOLY_FIRE);
                task.Repeat(15s, 25s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                    DoCast(target, SPELL_GREATER_HEAL);
                task.Repeat(15s, 25s);
            });
    }
};

// 17007 - Lady Keira Berrybuck (Holy Paladin)
struct boss_lady_keira_berrybuck : public GuestBaseAI
{
    boss_lady_keira_berrybuck(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_CLEANSE);
                task.Repeat(10s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_GREATER_BLESS_OF_MIGHT);
                task.Repeat(50s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                    DoCast(target, SPELL_HOLY_LIGHT);
                task.Repeat(15s, 20s);
            })
            .Schedule(25s, 35s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_DIVINE_SHIELD);
                task.Repeat(25s, 35s);
            });
    }
};

// 19876 - Lord Robin Daris (Arms Warrior)
struct boss_lord_robin_daris : public GuestBaseAI
{
    boss_lord_robin_daris(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HAMSTRING);
                task.Repeat(10s, 15s);
            })
            .Schedule(15s, 30s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                task.Repeat(15s, 30s);
            })
            .Schedule(20s, 35s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_WHIRLWIND);
                task.Repeat(20s, 35s);
            });
    }
};

// 19873 - Lord Crispin Ference (Protection Warrior)
struct boss_lord_crispin_ference : public GuestBaseAI
{
    boss_lord_crispin_ference(Creature* creature) : GuestBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_DISARM);
                task.Repeat(10s, 20s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HEROIC_STRIKE);
                task.Repeat(15s, 20s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_SHIELD_BASH);
                task.Repeat(15s, 25s);
            })
            .Schedule(30s, 45s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SHIELD_WALL);
                task.Repeat(30s, 45s);
            });
    }
};

// 37870 - Garrote Remove
class spell_moroes_garrote_remove : public AuraScript
{
    PrepareAuraScript(spell_moroes_garrote_remove);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GARROTE });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_GARROTE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_moroes_garrote_remove::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_moroes()
{
    RegisterKarazhanCreatureAI(boss_moroes);
    RegisterKarazhanCreatureAI(boss_baroness_dorothea_millstipe);
    RegisterKarazhanCreatureAI(boss_baron_rafe_dreuger);
    RegisterKarazhanCreatureAI(boss_lady_catriona_von_indi);
    RegisterKarazhanCreatureAI(boss_lady_keira_berrybuck);
    RegisterKarazhanCreatureAI(boss_lord_robin_daris);
    RegisterKarazhanCreatureAI(boss_lord_crispin_ference);
    RegisterSpellScript(spell_moroes_garrote_remove);
}
