/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "naxxramas.h"

enum Spells
{
    SPELL_MORTAL_WOUND      = 25646,
    SPELL_ENRAGE            = 28371,
    SPELL_DECIMATE          = 28374,
    SPELL_BERSERK           = 26662,
    SPELL_INFECTED_WOUND    = 29306
};

enum Creatures
{
    NPC_ZOMBIE              = 16360,
    NPC_GLUTH               = 15932
};

Position const PosSummon[3] =
{
    {3267.9f, -3172.1f, 297.42f, 0.94f},
    {3253.2f, -3132.3f, 297.42f, 0},
    {3308.3f, -3185.8f, 297.42f, 1.58f},
};

enum Events
{
    EVENT_WOUND     = 1,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
    EVENT_DEVOUR,
    EVENT_DEVOUR2
};

enum Emotes
{
    EMOTE_NEARBY,
    EMOTE_ENRAGE,
    EMOTE_DECIMATE
};

class boss_gluth : public CreatureScript
{
public:
    boss_gluth() : CreatureScript("boss_gluth") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_gluthAI(creature);
    }

    struct boss_gluthAI : public BossAI
    {
        boss_gluthAI(Creature* creature) : BossAI(creature, BOSS_GLUTH)
        {
            // Do not let Gluth be affected by zombies' debuff
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WOUND, 10000);
            events.ScheduleEvent(EVENT_ENRAGE, 15000);
            events.ScheduleEvent(EVENT_DECIMATE, 105000);
            events.ScheduleEvent(EVENT_BERSERK, 8*60000);
            events.ScheduleEvent(EVENT_SUMMON, 15000);
            events.ScheduleEvent(EVENT_DEVOUR, RAND(5, 8) * 1000);
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            if (summon->GetEntry() == NPC_ZOMBIE)
                summon->AI()->AttackStart(summon->SelectNearestPlayer(200));
            summons.Summon(summon);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictimWithGaze() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WOUND:
                        DoCastVictim(SPELL_MORTAL_WOUND);
                        events.ScheduleEvent(EVENT_WOUND, 10000);
                        break;
                    case EVENT_ENRAGE:
                        Talk(EMOTE_ENRAGE);
                        DoCast(me, SPELL_ENRAGE);
                        events.ScheduleEvent(EVENT_ENRAGE, 15000);
                        break;
                    case EVENT_DECIMATE:
                        Talk(EMOTE_DECIMATE);
                        DoCastAOE(SPELL_DECIMATE);
                        events.ScheduleEvent(EVENT_DECIMATE, 105000);
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK);
                        events.ScheduleEvent(EVENT_BERSERK, 5*60000);
                        break;
                    case EVENT_SUMMON:
                        for (int32 i = 0; i < RAID_MODE(1, 2); ++i)
                            DoSummon(NPC_ZOMBIE, PosSummon[rand() % RAID_MODE(1, 3)]);
                        events.ScheduleEvent(EVENT_SUMMON, 10000);
                        break;
                    case EVENT_DEVOUR:
                        {
                            Creature* zombie = me->FindNearestCreature(NPC_ZOMBIE, 7);
                            if(zombie)
                            {
                                Talk(EMOTE_NEARBY);
                                me->AddUnitState(UNIT_STATE_NOT_MOVE);
                                me->SetTarget(zombie->GetGUID());

                                events.ScheduleEvent(EVENT_DEVOUR2, 500);
                            }
                            events.ScheduleEvent(EVENT_DEVOUR, RAND(5, 8) * 1000);
                        }
                        break;
                    case EVENT_DEVOUR2:
                        {
                            Creature* zombie = sObjectAccessor->GetCreature(*me, me->GetTarget());
                            me->Kill(zombie);
                            Unit* unit = SelectTarget(SELECT_TARGET_TOPAGGRO);
                            me->SetTarget(unit->GetGUID());
                            me->ClearUnitState(UNIT_STATE_NOT_MOVE);
                            me->ModifyHealth(me->CountPctFromMaxHealth(5));
                        }
                        break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
    };

};

class spell_gluth_decimate : public SpellScriptLoader
{
    public:
        spell_gluth_decimate() : SpellScriptLoader("spell_gluth_decimate") { }

        class spell_gluth_decimate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gluth_decimate_SpellScript);

            void Decimate(SpellEffIndex)
            {
                Unit* unit = GetHitUnit();
                if(unit && unit->GetEntry() != NPC_GLUTH && unit->HealthAbovePct(5))
                {
                    int damage = unit->GetHealth() - unit->CountPctFromMaxHealth(5);

                    SpellInfo* info = (SpellInfo*) sSpellMgr->GetSpellInfo(28375);
                    info->AttributesCu |= SPELL_ATTR0_CU_IGNORE_ARMOR;

                    CustomSpellValues values;
                    values.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);

                    SpellCastTargets targets;
                    targets.SetUnitTarget(unit);

                    GetCaster()->CastSpell(targets, info, &values);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_gluth_decimate_SpellScript::Decimate, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_gluth_decimate_SpellScript();
        }
};

void AddSC_boss_gluth()
{
    new boss_gluth();
    new spell_gluth_decimate();
}