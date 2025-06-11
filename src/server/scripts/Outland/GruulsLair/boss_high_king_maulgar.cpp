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
 * The door should open after Maulgar's death, not after all NPCs are dead
 */

#include "ScriptMgr.h"
#include "gruuls_lair.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

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
    SPELL_ARCING_SMASH          = 39144,
    SPELL_MIGHTY_BLOW           = 33230,
    SPELL_WHIRLWIND             = 33238,
    SPELL_BERSERKER_CHARGE      = 26561,
    SPELL_ROAR                  = 16508,
    SPELL_FLURRY                = 33232,

    // Olm the Summoner
    SPELL_DARK_DECAY            = 33129,
    SPELL_DEATH_COIL            = 33130,
    SPELL_SUMMON_WILD_FELHUNTER = 33131,

    // Kiggler the Craed
    SPELL_GREATER_POLYMORPH     = 33173,
    SPELL_LIGHTNING_BOLT        = 36152,
    SPELL_ARCANE_SHOCK          = 33175,
    SPELL_ARCANE_EXPLOSION      = 33237,

    // Blindeye the Seer
    SPELL_GREATER_PW_SHIELD     = 33147,
    SPELL_HEAL                  = 33144,
    SPELL_PRAYER_OH             = 33152,

    // Krosh Firehand
    SPELL_GREATER_FIREBALL      = 33051,
    SPELL_SPELLSHIELD           = 33054,
    SPELL_BLAST_WAVE            = 33061
};

enum MaulgarMisc
{
    ACTION_ADD_DEATH            = 1
};

// 18831 - High King Maulgar
struct boss_high_king_maulgar : public BossAI
{
    boss_high_king_maulgar(Creature* creature) : BossAI(creature, DATA_MAULGAR), _enraged(false) { }

    void Reset() override
    {
        _Reset();
        _enraged = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        scheduler.Schedule(10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_ARCING_SMASH);
            task.Repeat(10s);
        });

        scheduler.Schedule(30s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_WHIRLWIND);
            task.Repeat(55s);
        });

        scheduler.Schedule(40s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MIGHTY_BLOW);
            task.Repeat(30s, 40s);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_enraged && me->HealthBelowPctDamaged(50, damage))
        {
            scheduler.Schedule(0s, [this](TaskContext /*task*/)
            {
                _enraged = true;
                Talk(SAY_ENRAGE);
                DoCastSelf(SPELL_FLURRY);
                SetEquipmentSlots(false, EQUIP_UNEQUIP);
            });

            scheduler.Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_ROAR);
                task.Repeat(40s, 50s);
            });

            scheduler.Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BERSERKER_CHARGE);
                task.Repeat(20s);
            });
        }
    }

    void DoAction(int32 actionId) override
    {
        if (!me->IsAlive())
            return;

        if (actionId == ACTION_ADD_DEATH)
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

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    bool _enraged;
};

// 18834 - Olm the Summoner
struct boss_olm_the_summoner : public ScriptedAI
{
    boss_olm_the_summoner(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_DARK_DECAY);
            task.Repeat(20s);
        });

        _scheduler.Schedule(0s, 10s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_SUMMON_WILD_FELHUNTER);
            task.Repeat(50s, 60s);
        });

        _scheduler.Schedule(20s, [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_DEATH_COIL);
            task.Repeat(20s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* maulgar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MAULGAR)))
            maulgar->AI()->DoAction(ACTION_ADD_DEATH);

        _instance->SetBossState(DATA_MAULGAR, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 18835 - Kiggler the Crazed
struct boss_kiggler_the_crazed : public ScriptedAI
{
    boss_kiggler_the_crazed(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 40.0f);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_GREATER_POLYMORPH);
            task.Repeat(15s, 20s);
        });

        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_LIGHTNING_BOLT);
            task.Repeat(2s);
        });

        _scheduler.Schedule(20s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_ARCANE_SHOCK);
            task.Repeat(20s);
        });

        _scheduler.Schedule(30s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_ARCANE_EXPLOSION);
            task.Repeat(30s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* maulgar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MAULGAR)))
            maulgar->AI()->DoAction(ACTION_ADD_DEATH);

        _instance->SetBossState(DATA_MAULGAR, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 18836 - Blindeye the Seer
struct boss_blindeye_the_seer : public ScriptedAI
{
    boss_blindeye_the_seer(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_GREATER_PW_SHIELD);
            task.Repeat(40s);
        });

        _scheduler.Schedule(25s, 40s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_HEAL);
            task.Repeat(25s, 40s);
        });

        _scheduler.Schedule(45s, 55s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_PRAYER_OH);
            task.Repeat(35s, 50s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* maulgar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MAULGAR)))
            maulgar->AI()->DoAction(ACTION_ADD_DEATH);

        _instance->SetBossState(DATA_MAULGAR, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 18832 - Krosh Firehand
struct boss_krosh_firehand : public ScriptedAI
{
    boss_krosh_firehand(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(0s, 5s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_GREATER_FIREBALL);
            task.Repeat(2s, 5s);
        });

        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_SPELLSHIELD);
            task.Repeat(30s);
        });

        _scheduler.Schedule(10s, 20s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_BLAST_WAVE);
            task.Repeat(5s, 15s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* maulgar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MAULGAR)))
            maulgar->AI()->DoAction(ACTION_ADD_DEATH);

        _instance->SetBossState(DATA_MAULGAR, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

void AddSC_boss_high_king_maulgar()
{
    RegisterGruulsLairCreatureAI(boss_high_king_maulgar);
    RegisterGruulsLairCreatureAI(boss_kiggler_the_crazed);
    RegisterGruulsLairCreatureAI(boss_blindeye_the_seer);
    RegisterGruulsLairCreatureAI(boss_olm_the_summoner);
    RegisterGruulsLairCreatureAI(boss_krosh_firehand);
}
