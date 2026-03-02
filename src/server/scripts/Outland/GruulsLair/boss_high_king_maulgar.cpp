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
 * Timers and targets requires to be revisited
 */

#include "ScriptMgr.h"
#include "gruuls_lair.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum MaulgarTexts
{
    SAY_AGGRO                   = 0,
    SAY_ENRAGE                  = 1,
    SAY_OGRE_DEATH              = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4
};

enum MaulgarSpells
{
    // High King Maulgar
    SPELL_MIGHTY_BLOW           = 33230,
    SPELL_WHIRLWIND             = 33238,
    SPELL_ARCING_SMASH          = 39144,

    SPELL_FLURRY                = 33232,
    SPELL_ROAR                  = 16508,
    SPELL_BERSERKER_CHARGE      = 26561,

    // Olm the Summoner
    SPELL_DARK_DECAY            = 33129,
    SPELL_DEATH_COIL            = 33130,
    SPELL_SUMMON_WILD_FELHUNTER = 33131,

    // Kiggler the Crazed
    SPELL_LIGHTNING_BOLT        = 36152,
    SPELL_GREATER_POLYMORPH     = 33173,
    SPELL_ARCANE_SHOCK          = 33175,
    SPELL_ARCANE_EXPLOSION      = 33237,

    // Blindeye the Seer
    SPELL_HEAL                  = 33144,
    SPELL_GREATER_PW_SHIELD     = 33147,
    SPELL_PRAYER_OF_HEALING     = 33152,

    // Krosh Firehand
    SPELL_GREATER_FIREBALL      = 33051,
    SPELL_SPELL_SHIELD          = 33054,
    SPELL_BLAST_WAVE            = 33061
};

enum MaulgarMisc
{
    ACTION_OGRE_DEATH           = 0
};

static constexpr std::array<uint32, 4> OgreData =
{
    DATA_KROSH_FIREHAND,
    DATA_OLM_THE_SUMMONER,
    DATA_KIGGLER_THE_CRAZED,
    DATA_BLINDEYE_THE_SEER
};

// 18831 - High King Maulgar
struct boss_high_king_maulgar : public BossAI
{
    boss_high_king_maulgar(Creature* creature) : BossAI(creature, DATA_MAULGAR), _enraged(false) { }

    void Reset() override
    {
        _Reset();
        _enraged = false;
        SetEquipmentSlots(true);

        for (uint32 data : OgreData)
            me->GetMap()->Respawn(SPAWN_TYPE_CREATURE, instance->GetData64(data));
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        scheduler
            .Schedule(15s, 20s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_MIGHTY_BLOW);
                task.Repeat(15s, 20s);
            })
            .Schedule(55s, 65s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_WHIRLWIND);
                task.Repeat(55s, 60s);
            })
            .Schedule(10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_ARCING_SMASH);
                task.Repeat(10s);
            });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_enraged && me->HealthBelowPctDamaged(50, damage))
        {
            _enraged = true;

            scheduler
                .Schedule(0s, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_FLURRY);
                })
                .Schedule(0s, 5s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_ROAR);
                    task.Repeat(40s, 50s);
                })
                .Schedule(10s, 15s, [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_BERSERKER_CHARGE);
                    task.Repeat(20s);
                });
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FLURRY)
        {
            Talk(SAY_ENRAGE);
            SetEquipmentSlots(false, EQUIP_UNEQUIP);
        }
    }

    void DoAction(int32 action) override
    {
        if (!me->IsAlive())
            return;

        if (action == ACTION_OGRE_DEATH)
            Talk(SAY_OGRE_DEATH);
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

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    bool _enraged;
};

struct OgreBaseAI : public ScriptedAI
{
    OgreBaseAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        ScriptedAI::InitializeAI();
    }

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

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* maulgar = instance->GetCreature(DATA_MAULGAR))
            maulgar->AI()->DoAction(ACTION_OGRE_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

protected:
    InstanceScript* instance;
    TaskScheduler scheduler;
};

// 18834 - Olm the Summoner
struct boss_olm_the_summoner : public OgreBaseAI
{
    boss_olm_the_summoner(Creature* creature) : OgreBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_DARK_DECAY);
                task.Repeat(5s, 10s);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_DEATH_COIL);
                task.Repeat(5s, 15s);
            })
            .Schedule(0s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SUMMON_WILD_FELHUNTER);
                task.Repeat(50s, 60s);
            });
    }
};

// 18835 - Kiggler the Crazed
struct boss_kiggler_the_crazed : public OgreBaseAI
{
    boss_kiggler_the_crazed(Creature* creature) : OgreBaseAI(creature) { }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 40.0f);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        Unit* unitTarget = target->ToUnit();
        if (!unitTarget)
            return;

        if (spellInfo->Id == SPELL_ARCANE_EXPLOSION)
            ModifyThreatByPercent(unitTarget, -100);
    }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_LIGHTNING_BOLT);
                task.Repeat(2s, 3s);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_GREATER_POLYMORPH);
                task.Repeat(10s, 35s);
            })
            .Schedule(5s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_ARCANE_SHOCK);
                task.Repeat(5s, 20s);
            })
            .Schedule(30s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_ARCANE_EXPLOSION);
                task.Repeat(30s);
            });
    }
};

// 18836 - Blindeye the Seer
struct boss_blindeye_the_seer : public OgreBaseAI
{
    boss_blindeye_the_seer(Creature* creature) : OgreBaseAI(creature) { }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GREATER_PW_SHIELD)
            DoCastSelf(SPELL_PRAYER_OF_HEALING);
    }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(7s, [this](TaskContext task)
            {
                if (Unit* target = DoSelectLowestHpFriendly(250.0f))
                    DoCast(target, SPELL_HEAL);
                task.Repeat(7s);
            })
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_GREATER_PW_SHIELD);
                task.Repeat(15s, 25s);
            });
    }
};

// 18832 - Krosh Firehand
struct boss_krosh_firehand : public OgreBaseAI
{
    boss_krosh_firehand(Creature* creature) : OgreBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_GREATER_FIREBALL);
                task.Repeat(2s, 5s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SPELL_SHIELD);
                task.Repeat(30s);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_BLAST_WAVE);
                task.Repeat(5s, 15s);
            });
    }
};

void AddSC_boss_high_king_maulgar()
{
    RegisterGruulsLairCreatureAI(boss_high_king_maulgar);
    RegisterGruulsLairCreatureAI(boss_olm_the_summoner);
    RegisterGruulsLairCreatureAI(boss_kiggler_the_crazed);
    RegisterGruulsLairCreatureAI(boss_blindeye_the_seer);
    RegisterGruulsLairCreatureAI(boss_krosh_firehand);
}
