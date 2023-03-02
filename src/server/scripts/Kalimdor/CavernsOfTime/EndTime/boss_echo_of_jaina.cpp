/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_echo_of_jaina
SD%Complete:
SDComment:
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "end_time.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_PYROBLAST             = 101809,
    SPELL_BLINK                 = 101812,
    SPELL_SUMMON_FROST_BLADES   = 101339,
    SPELL_FROST_BLADES          = 101338,
    SPELL_SUMMON_FLARECORE      = 101927,
    SPELL_FLARECORE             = 101588,
    SPELL_FLARE_UP              = 101589,
    SPELL_UNSTABLE_FLARE        = 101980,
    SPELL_FLARE                 = 101587,
    SPELL_FROSTBOLT_VOLLEY      = 101810

};

enum Events
{
    EVENT_PYROBLAST = 1,
    EVENT_FLARECORE,
    EVENT_BLINK,
    EVENT_FROST_BLADES,
    EVENT_FROSTBOLT_VOLLEY
};

enum Misc
{
    NPC_FROST_BLADE             = 54494,
    NPC_FLARECORE               = 54446
};

const float TelePoint[4][4]=
{
    {3052.10f, 489.98f, 21.7684f, 1.8236f},
    {3017.94f, 491.92f, 26.5740f, 0.4384f},
    {2989.04f, 506.10f, 26.4568f, 5.8042f},
    {3017.94f, 491.92f, 26.5740f, 0.4384f},
};

class boss_echo_of_jaina : public CreatureScript
{
    public:
        boss_echo_of_jaina() : CreatureScript("boss_echo_of_jaina") { }

        struct boss_echo_of_jainaAI : public BossAI
        {
            boss_echo_of_jainaAI(Creature* creature) : BossAI(creature, DATA_JAINA), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;

            Position points[3];
            int i;
            int count;
            int volley;

            void Reset() override
            {
                _Reset();
                events.Reset();

                Summons.DespawnAll();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                DoZoneInCombat();
                i = 0;
                me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                events.ScheduleEvent(EVENT_PYROBLAST, 1000);
                events.ScheduleEvent(EVENT_BLINK, 3500); // 20 seconds
                events.ScheduleEvent(EVENT_FLARECORE, 5000); // 30 seconds
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SetData(DATA_BOSS_COUNT, 1);
            }

            void JustSummoned(Creature* summon) override
            {
                Summons.Summon(summon);

                if(summon->GetEntry() == NPC_FLARECORE)
                {
                    summon->SetReactState(REACT_PASSIVE);
                    summon->CastSpell(summon, SPELL_FLARECORE, false);
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PYROBLAST:
                            me->CastSpell(me->GetVictim(), SPELL_PYROBLAST, false);
                            events.CancelEvent(EVENT_FROSTBOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_PYROBLAST, 500);
                            break;
                        case EVENT_BLINK:
                            me->CastSpell(me, SPELL_BLINK, false);
                            i = i < 4 ? i : 0;
                            me->NearTeleportTo(TelePoint[i][0], TelePoint[i][1], TelePoint[i][2], TelePoint[i][3]);
                            i++;
                            events.CancelEvent(EVENT_PYROBLAST);
                            events.ScheduleEvent(EVENT_FROST_BLADES, 1);
                            break;
                        case EVENT_FROST_BLADES:
                        {
                            count =0;
                            for(int i = 0; i < 3; i++)
                            {
                                if(Creature* summon = me->SummonCreature(NPC_FROST_BLADE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 5000))
                                {
                                    summon->SetReactState(REACT_PASSIVE);
                                    summon->CastSpell(summon, SPELL_FROST_BLADES, false);
                                    float dir =(me->GetOrientation() - (0.52f) + count * (0.52f));
                                    if (dir >6.28f)
                                        dir-=6.28f;
                                    count++;
                                    summon->GetMotionMaster()->MovePoint(0,
                                                                         me->GetPositionX()+ 120  * cos(dir),
                                                                         me->GetPositionY()+ 120  * sin(dir),
                                                                         me->GetPositionZ());
                                }
                            }
                            volley = 0;
                            events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 500);
                            break;
                        }
                        case EVENT_FROSTBOLT_VOLLEY:
                            if(volley < 3)
                            {
                                me->CastSpell(me, SPELL_FROSTBOLT_VOLLEY, false);

                                volley++;
                                events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 1);
                            }
                            else
                            {
                                events.CancelEvent(EVENT_FROSTBOLT_VOLLEY);
                                events.ScheduleEvent(EVENT_PYROBLAST, 1);
                                events.ScheduleEvent(EVENT_BLINK, 2500);
                            }
                            break;
                        case EVENT_FLARECORE:
                            if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                me->CastSpell(target, SPELL_SUMMON_FLARECORE, false);
                            events.ScheduleEvent(EVENT_FLARECORE, 5000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_echo_of_jainaAI(creature);
        }
};

//101588
class spell_flarecore : public SpellScriptLoader
{
    public:
        spell_flarecore() : SpellScriptLoader("spell_flarecore") { }

        class spell_flarecore_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_flarecore_SpellScript);

            void HandleOnHit(SpellEffIndex /*effIndex*/)
            {
                if(Unit* caster = GetCaster())
                {
                    if(caster->GetEntry() == NPC_FLARECORE)
                    {
                        caster->CastSpell(caster, SPELL_FLARE_UP, false);
                        caster->CastSpell(caster, SPELL_UNSTABLE_FLARE, false);
                        caster->RemoveAura(SPELL_FLARECORE);
                    }
                }

            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_flarecore_SpellScript::HandleOnHit, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_flarecore_SpellScript();
        }
};

class spell_flarecore_periodic : public SpellScriptLoader
{
    public:
        spell_flarecore_periodic() : SpellScriptLoader("spell_flarecore_periodic") { }

    private:
        class spell_flarecore_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_flarecore_periodic_AuraScript);

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if(Unit* owner = GetUnitOwner())
                    if(!owner->HasAura(SPELL_FLARE_UP))
                        owner->CastSpell(owner, SPELL_FLARE, false);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_flarecore_periodic_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_flarecore_periodic_AuraScript();
        }
};

void AddSC_boss_echo_of_jaina()
{
    new boss_echo_of_jaina();
    new spell_flarecore();
    new spell_flarecore_periodic();
}
