/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum eScriptTexts
{
    // Festergut
    SAY_FESTERGUT_GASEOUS_BLIGHT = -1631080,
    SAY_FESTERGUT_DEATH          = -1631090,
    SAY_ROTFACE_OOZE_FLOOD1      = -1631091,
    SAY_ROTFACE_OOZE_FLOOD2      = -1631092,
    SAY_ROTFACE_DEATH            = -1631093,
};

enum eSpells
{
    // Festergut
    SPELL_RELEASE_GAS_VISUAL    = 69125,
    SPELL_GASEOUS_BLIGHT_LARGE  = 69157,
    SPELL_GASEOUS_BLIGHT_MEDIUM = 69162,
    SPELL_GASEOUS_BLIGHT_SMALL  = 69164,
    SPELL_MALLABLE_GOO_H        = 70852,

    // Rotface
    SPELL_VILE_GAS_H            = 69240,
};

enum eEvents
{
    // Festergut
    EVENT_FESTERGUT_DIES        = 1,
    EVENT_FESTERGUT_GOO         = 2,

    // Rotface
    EVENT_ROTFACE_DIES          = 3,
    EVENT_ROTFACE_VILE_GAS      = 4,
    EVENT_ROTFACE_OOZE_FLOOD    = 5,
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
    POINT_FESTERGUT = 366260,
    POINT_ROTFACE   = 366270,
};

static const Position festergutWatchPos = {4324.820f, 3166.03f, 389.3831f, 3.316126f}; //emote 432 (release gas)
static const Position rotfaceWatchPos =   {4390.371f, 3164.50f, 389.3890f, 5.497787f}; //emote 432 (release gas)

static const uint32 oozeFloodSpells[4] = {69782, 69796, 69798, 69801};

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
                    case ACTION_ROTFACE_COMBAT:
                    {
                        _SetPhase(PHASE_ROTFACE);
                        me->SetSpeed(MOVE_RUN, fBaseSpeed*2.0f, true);
                        me->GetMotionMaster()->MovePoint(POINT_ROTFACE, rotfaceWatchPos);
                        me->SetReactState(REACT_PASSIVE);
                        oozeFloodStage = 0;
                        if (IsHeroic())
                        {
                            DoZoneInCombat(me);
                            events.ScheduleEvent(EVENT_ROTFACE_VILE_GAS, urand(15000, 20000), 0, PHASE_ROTFACE);
                        }
                        // init random sequence of floods
                        if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(DATA_ROTFACE)))
                        {
                            std::list<Creature*> list;
                            GetCreatureListWithEntryInGrid(list, rotface, NPC_PUDDLE_STALKER, 36.0f);
                            if (list.size() > 4)
                            {
                                list.sort(Trinity::ObjectDistanceOrderPred(rotface));
                                do
                                {
                                    list.pop_back();
                                } while (list.size() > 4);
                            }

                            uint8 i = 0;
                            while (!list.empty())
                            {
                                std::list<Creature*>::iterator itr = list.begin();
                                std::advance(itr, urand(0, list.size()-1));
                                oozeFloodDummy[i++] = (*itr)->GetGUID();
                                list.erase(itr);
                            }
                        }
                        break;
                    }
                    case ACTION_ROTFACE_OOZE:
                        DoScriptText(RAND(SAY_ROTFACE_OOZE_FLOOD1, SAY_ROTFACE_OOZE_FLOOD2), me);
                        if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(DATA_ROTFACE)))
                            if (Creature* dummy = Unit::GetCreature(*me, oozeFloodDummy[oozeFloodStage]))
                                dummy->CastSpell(dummy, oozeFloodSpells[oozeFloodStage], true, NULL, NULL, me->GetGUID()); // cast from self for LoS (with prof's GUID for logs)
                        if (++oozeFloodStage == 4)
                            oozeFloodStage = 0;
                        break;
                    case ACTION_ROTFACE_DEATH:
                        events.ScheduleEvent(EVENT_ROTFACE_DIES, 4500, 0, PHASE_ROTFACE);
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                if (phase == PHASE_COMBAT)
                    instance->SetBossState(DATA_PROFESSOR_PUTRICIDE, FAIL);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                switch (id)
                {
                    case POINT_FESTERGUT:
                        me->SetSpeed(MOVE_RUN, fBaseSpeed, true);
                        DoAction(ACTION_FESTERGUT_GAS);
                        if (Creature* festergut = Unit::GetCreature(*me, instance->GetData64(DATA_FESTERGUT)))
                            festergut->CastSpell(festergut, SPELL_GASEOUS_BLIGHT_LARGE, false, NULL, NULL, festergut->GetGUID());
                        break;
                    case POINT_ROTFACE:
                        me->SetSpeed(MOVE_RUN, fBaseSpeed, true);
                        DoAction(ACTION_ROTFACE_OOZE);
                        events.ScheduleEvent(EVENT_ROTFACE_OOZE_FLOOD, 25000, 0, PHASE_ROTFACE);
                        break;
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
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_MALLABLE_GOO_H, true); // triggered, to skip LoS check
                            events.ScheduleEvent(EVENT_FESTERGUT_GOO, urand(15000, 20000), 0, PHASE_FESTERGUT);
                            break;
                        case EVENT_ROTFACE_DIES:
                            DoScriptText(SAY_ROTFACE_DEATH, me);
                            EnterEvadeMode();
                            break;
                        case EVENT_ROTFACE_VILE_GAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_VILE_GAS_H, true); // triggered, to skip LoS check
                            events.ScheduleEvent(EVENT_ROTFACE_VILE_GAS, urand(15000, 20000), 0, PHASE_ROTFACE);
                            break;
                        case EVENT_ROTFACE_OOZE_FLOOD:
                            DoAction(ACTION_ROTFACE_OOZE);
                            events.ScheduleEvent(EVENT_ROTFACE_OOZE_FLOOD, 25000, 0, PHASE_ROTFACE);
                        default:
                            break;
                    }
                }
            }

        private:
            void _SetPhase(ePhases newPhase)
            {
                phase = newPhase;
                events.SetPhase(newPhase);
            }

            ePhases phase;          // external of EventMap because event phase gets reset on evade
            const float fBaseSpeed;
            uint64 oozeFloodDummy[4];
            uint8 oozeFloodStage;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_professor_putricideAI(pCreature);
        }
};

// Stinky and Precious spell, it's here because its used for both (Festergut and Rotface "pets")
class spell_stinky_precious_decimate : public SpellScriptLoader
{
    public:
        spell_stinky_precious_decimate() : SpellScriptLoader("spell_stinky_precious_decimate") { }

        class spell_stinky_precious_decimate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stinky_precious_decimate_SpellScript)
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
