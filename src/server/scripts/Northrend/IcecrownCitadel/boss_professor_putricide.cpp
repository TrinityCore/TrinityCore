/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum eScriptTexts
{
    // Festergut
    SAY_FESTERGUT_GASEOUS_BLIGHT = -1631080,
    SAY_FESTERGUT_DEATH          = -1631090,
};

enum eSpells
{
    // Festergut
    SPELL_RELEASE_GAS_VISUAL    = 69125,
    SPELL_GASEOUS_BLIGHT_LARGE  = 69157,
    SPELL_GASEOUS_BLIGHT_MEDIUM = 69162,
    SPELL_GASEOUS_BLIGHT_SMALL  = 69164,
    SPELL_MALLABLE_GOO_H        = 70852,
};

enum eEvents
{
    // Festergut
    EVENT_FESTERGUT_DIES    = 1,
    EVENT_FESTERGUT_GOO     = 2,
};

enum ePhases
{
    PHASE_FESTERGUT     = 1,
    PHASE_ROTFACE       = 2,
    PHASE_COMBAT        = 3,

    PHASE_MASK_NOT_SELF = (1 << PHASE_FESTERGUT) | (1 << PHASE_ROTFACE)
};

enum ePoints
{
    POINT_FESTERGUT = -366260,
};

static const Position festergutWatchPos = {4324.82f, 3166.03f, 389.3831f, 3.316126f}; //emote 432 (release gas)

class boss_professor_putricide : public CreatureScript
{
    public:
        boss_professor_putricide() : CreatureScript("boss_professor_putricide") { }

        struct boss_professor_putricideAI : public BossAI
        {
            boss_professor_putricideAI(Creature* pCreature) : BossAI(pCreature, DATA_PROFESSOR_PUTRICIDE),
                fBaseSpeed(pCreature->GetSpeedRate(MOVE_RUN))
            {
                ASSERT(instance);
                phase = ePhases(0);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
                _SetPhase(PHASE_COMBAT);
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                    me->GetMotionMaster()->MovementExpired();
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_FESTERGUT_COMBAT:
                        _SetPhase(PHASE_FESTERGUT);
                        me->SetSpeed(MOVE_RUN, fBaseSpeed*2.0f, true);
                        me->GetMotionMaster()->MovePoint(POINT_FESTERGUT, festergutWatchPos);
                        me->SetReactState(REACT_PASSIVE);
                        if (IsHeroic())
                        {
                            DoZoneInCombat(me);
                            events.ScheduleEvent(EVENT_FESTERGUT_GOO, urand(15000, 20000), 0, PHASE_FESTERGUT);
                        }
                        break;
                    case ACTION_FESTERGUT_GAS:
                        DoScriptText(SAY_FESTERGUT_GASEOUS_BLIGHT, me);
                        if (Creature* festergut = Unit::GetCreature(*me, instance->GetData64(DATA_FESTERGUT)))
                            festergut->CastSpell(festergut, SPELL_RELEASE_GAS_VISUAL, false, NULL, NULL, me->GetGUID()); // cast from festergut for LoS (with prof's GUID for logs)
                        break;
                    case ACTION_FESTERGUT_DEATH:
                        events.ScheduleEvent(EVENT_FESTERGUT_DIES, 4000, 0, PHASE_FESTERGUT);
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                if (phase == PHASE_COMBAT)
                    instance->SetBossState(DATA_PROFESSOR_PUTRICIDE, FAIL);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == POINT_FESTERGUT)
                {
                    me->SetSpeed(MOVE_RUN, fBaseSpeed, true);
                    DoAction(ACTION_FESTERGUT_GAS);
                    if (Creature* festergut = Unit::GetCreature(*me, instance->GetData64(DATA_FESTERGUT)))
                        festergut->CastSpell(festergut, SPELL_GASEOUS_BLIGHT_LARGE, false, NULL, NULL, festergut->GetGUID());
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if ((!UpdateVictim() && !(events.GetPhaseMask() & PHASE_MASK_NOT_SELF)) || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->hasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FESTERGUT_DIES:
                            DoScriptText(SAY_FESTERGUT_DEATH, me);
                            EnterEvadeMode();
                            break;
                        case EVENT_FESTERGUT_GOO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_MALLABLE_GOO_H, true); // triggered, to skip LoS check
                            events.ScheduleEvent(EVENT_FESTERGUT_GOO, urand(15000, 20000), 0, PHASE_FESTERGUT);
                            break;
                        default:
                            break;
                    }
                }
            }

            void _SetPhase(ePhases newPhase)
            {
                phase = newPhase;
                events.SetPhase(newPhase);
            }

        private:
            ePhases phase;  // external of EventMap because event phase gets reset on evade
            const float fBaseSpeed;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_professor_putricideAI(pCreature);
        }
};

// Stinky and Precious spell, it's here because its used for both (Festergut and Rotface "pet")
class spell_stinky_precious_decimate : public SpellScriptLoader
{
    public:
        spell_stinky_precious_decimate() : SpellScriptLoader("spell_stinky_precious_decimate") { }

        class spell_stinky_precious_decimate_SpellScript : public SpellScript
        {
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->GetHealthPct() > float(GetEffectValue()))
                {
                    uint32 newHealth = GetHitUnit()->GetMaxHealth() * uint32(GetEffectValue()) / 100;
                    if (GetHitUnit()->GetMaxHealth() >= newHealth)
                        GetHitUnit()->SetHealth(newHealth);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_stinky_precious_decimate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_stinky_precious_decimate_SpellScript();
        }
};

void AddSC_boss_professor_putricide()
{
    new boss_professor_putricide();
    new spell_stinky_precious_decimate();
}
