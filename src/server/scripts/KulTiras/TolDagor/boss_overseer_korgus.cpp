/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "tol_dagor.h"

enum Spells {
    SPELL_ARBLAST = 256199,
    SPELL_ARI = 256198,
    SPELL_CROSSIGNITION = 256083,
    SPELL_CROSSIGNITION_VISUAL = 256057,
    //for the player
    SPELL_DEADEYE = 256038,
    //Cast
    SPELL_DEADEYE_CAST = 256039,
    //Damage
    SPELL_DEADEYE_BULLET = 256044,
    SPELL_EXPLOSIVE_BURST = 256105,
    SPELL_EXPLOSIVE_BURST_DAMAGE = 256128,
    SPELL_MASSIVE_BLAST = 263345,
};

enum Events : uint32
{
    EVENT_MUNITION = 1,
    EVENT_CROSSIGNITION = 2,
    EVENT_DEADEYE = 3,
    EVENT_EXPLOSIVE_BURST = 4,
    EVENT_MASSIVE_BLAST = 5
};

struct boss_overseer_korgus : public BossAI
{
    boss_overseer_korgus(Creature* creature) : BossAI(creature, DATA_OVERSEER_KORGUS) { }

    void EnterCombat(Unit* who) override
    {
        //todo change chance to ari or airblast and script the auras
        events.ScheduleEvent(EVENT_MUNITION, 5100);
        events.ScheduleEvent(EVENT_EXPLOSIVE_BURST, 11500);
        events.ScheduleEvent(EVENT_CROSSIGNITION, 16000);
        events.ScheduleEvent(EVENT_MASSIVE_BLAST, 17000);
        events.ScheduleEvent(EVENT_DEADEYE, 23300);
        BossAI::EnterCombat(who);
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
            case EVENT_MUNITION:
                random = urand(0, 1);
                if (random == 0)
                {
                    DoCast(SPELL_ARBLAST);
                }
                else
                {
                    DoCast(SPELL_ARI);
                }
                events.ScheduleEvent(EVENT_MUNITION, 44800);
                break;
            case EVENT_CROSSIGNITION:
                DoCastVictim(SPELL_CROSSIGNITION);
                // todo fix offset cast and make it depend on korgus orientation
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 6.065254f);
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 5.018055f);
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 3.970858f);
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 2.923661f);
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 0.8292661f);
                me->CastSpellWithOrientation(me, SPELL_CROSSIGNITION_VISUAL, true, 1.876463f);
                events.ScheduleEvent(EVENT_CROSSIGNITION, 44800);
                break;
            case EVENT_DEADEYE:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                {
                    me->CastSpell(target, SPELL_DEADEYE);
                    me->CastSpell(target, SPELL_DEADEYE_CAST);
                }
                events.ScheduleEvent(EVENT_DEADEYE, 23000);
                break;
            case EVENT_MASSIVE_BLAST:
                //blizzlike the cannon would rotate slowly instead of instant locking to the object
                if (Unit* cannon = me->FindNearestCreature(NPC_HEAVY_CANNON, 50.0f))
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    {
                        cannon->SetFacingToObject(target);
                        cannon->CastSpell(target, SPELL_MASSIVE_BLAST);
                    }
                events.ScheduleEvent(EVENT_MASSIVE_BLAST, 22000);
                break;
            case EVENT_EXPLOSIVE_BURST:
                //todo should target multiple players
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                {
                    me->CastSpell(target, SPELL_EXPLOSIVE_BURST);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_BURST, 44800);
                    break;
                }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    int random = 0;
};

// 256038 - Deadeye
class bfa_spell_generic_deadeye : public AuraScript
{
    PrepareAuraScript(bfa_spell_generic_deadeye);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        if (!target)
            return;

        caster->CastSpell(target, SPELL_DEADEYE_BULLET, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_generic_deadeye::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 256105 - Explosive Burst
class bfa_spell_explosive_burst : public AuraScript
{
    PrepareAuraScript(bfa_spell_explosive_burst);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        if (!target)
            return;

        caster->CastSpell(target, SPELL_EXPLOSIVE_BURST_DAMAGE, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_explosive_burst::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_overseer_korgus()
{
    RegisterCreatureAI(boss_overseer_korgus);
    RegisterAuraScript(bfa_spell_generic_deadeye);
    RegisterAuraScript(bfa_spell_explosive_burst);
}
