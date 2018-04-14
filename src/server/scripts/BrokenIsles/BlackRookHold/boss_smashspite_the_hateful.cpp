/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "black_rook_hold.h"

enum Spells
{
    SPELL_EARTHSHAKING_STOMP    = 198073,

    SPELL_HATEFUL_GAZE          = 198079,
    SPELL_HATEFUL_CHARGE        = 198250,
    SPELL_HATEFUL_CHARGE_DAMAGE = 198080,

    SPELL_BRUTALITY             = 198114,
    SPELL_BRUTAL_HAYMAKER       = 198245,

    // Felbat
    SPELL_FEL_VOMIT_TARGET      = 198446,
    SPELL_FEL_VOMIT             = 198499,

    EVENT_SUMMON_FELBAT         = 1,
};
 
// 98949
struct boss_smashspite_the_hateful : public BossAI
{
    boss_smashspite_the_hateful(Creature* creature) : BossAI(creature, DATA_SMASHSPITE) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_EARTHSHAKING_STOMP, 5s);
        events.ScheduleEvent(SPELL_HATEFUL_GAZE, 30s);
        events.ScheduleEvent(EVENT_SUMMON_FELBAT, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_EARTHSHAKING_STOMP:
            {
                me->CastSpell(nullptr, SPELL_EARTHSHAKING_STOMP, false);
                events.Repeat(15s);
                break;
            }
            case SPELL_HATEFUL_GAZE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.0f, true))
                {
                    me->AddAura(SPELL_HATEFUL_GAZE, target);
                    hatefulGazeTargetGUID = target->GetGUID();
                }

                me->GetMotionMaster()->MoveCharge(0, 0, 0);

                events.ScheduleEvent(SPELL_HATEFUL_CHARGE, 5s);
                events.Repeat(30s);
                break;
            }
            case SPELL_HATEFUL_CHARGE:
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, hatefulGazeTargetGUID))
                    me->CastSpell(target, SPELL_HATEFUL_CHARGE, true);

                hatefulGazeTargetGUID = ObjectGuid::Empty;
                break;
            }
            case EVENT_SUMMON_FELBAT:
            {

                break;
            }
        }
    }

private:
    ObjectGuid hatefulGazeTargetGUID;
};

// 198114 - Brutality
class aura_smashspite_brutality : public AuraScript
{
    PrepareAuraScript(aura_smashspite_brutality);

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->ModifyPower(POWER_ENERGY, 1);

        if (GetTarget()->GetPower(POWER_ENERGY) == 100)
        {
            GetTarget()->CastSpell(GetTarget()->GetVictim(), SPELL_BRUTAL_HAYMAKER, false);
            GetTarget()->SetPower(POWER_ENERGY, 0);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_smashspite_brutality::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 100759
struct npc_brh_felbat : public ScriptedAI
{
    npc_brh_felbat(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->GetScheduler().Schedule(5s, [this](TaskContext context)
        {
            DoZoneInCombat();

            if (Unit* attackableUnit = SelectTarget(SELECT_TARGET_RANDOM))
            {
                ObjectGuid attackableUnitGUID = attackableUnit->GetGUID();
                me->CastSpell(attackableUnit, SPELL_FEL_VOMIT_TARGET, false);

                me->GetScheduler().Schedule(6s, [this, attackableUnitGUID](TaskContext context)
                {
                    if (Unit* attackableUnit = ObjectAccessor::GetUnit(*me, attackableUnitGUID))
                        me->CastSpell(attackableUnit, SPELL_FEL_VOMIT, false);
                });
            }

            context.Repeat(12s);
        });
    }
};

void AddSC_boss_smashspite_the_hateful()
{
    RegisterCreatureAI(boss_smashspite_the_hateful);
    RegisterAuraScript(aura_smashspite_brutality);

    RegisterCreatureAI(npc_brh_felbat);
}
