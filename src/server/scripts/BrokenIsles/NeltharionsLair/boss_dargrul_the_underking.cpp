/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"
#include "GridNotifiers.h"



struct boss_dargrul : public BossAI
{
    boss_dargrul(Creature* creature) : BossAI(creature, DATA_DARGRUL) { }

    enum eTexts
    {
        TALK_AGGRO                           = 0,
        TALK_SPIKES                          = 1,
        TALK_DEATH                           = 2,
    };

    enum eEvents
    {
        EVENT_MANAREGEN_TICK                 = 1,
        EVENT_MAGMA_SCULPTOR                 = 2,
        EVENT_LANDSLIDE                      = 3,
        EVENT_MOLTEN_CRASH                   = 4,
        EVENT_CRYSTALL_SPIKES                = 5,
        EVENT_MAGMA_WAVE                     = 6,
        EVENT_RESET_MANA                     = 7,
    };

    enum eSpells
    {
        SPELL_MAGMA_SCULPTOR                 = 200637,
        SPELL_LANDSLIDE                      = 200700,
        SPELL_MOLTEN_CRASH                   = 200732,
        SPELL_CRYSTALL_SPIKES                = 200551,
        SPELL_MAGMA_WAVE                     = 200404,
    };

    struct boss_dargrul_AI : public BossAI
    {
        boss_dargrul_AI(Creature* creature) : BossAI(creature, DATA_DARGRUL)
        {
            me->SetReactState(REACT_DEFENSIVE);
        }

        EventMap events;
        InstanceScript* instance;
        bool manaRegenerated = false;

        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
            me->SetPower(POWER_MANA, 0);
        }

        void Reset() override
        {
            _Reset();
            events.Reset();
            me->SetPower(POWER_MANA, 0);

            if (instance)
                instance->SetData(DATA_DARGRUL, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(TALK_AGGRO);
            me->SetInCombatWithZone();
            me->SetPower(POWER_MANA, 0);

            events.ScheduleEvent(EVENT_MANAREGEN_TICK, 1s);
            events.ScheduleEvent(EVENT_MAGMA_SCULPTOR, 7s);
            events.ScheduleEvent(EVENT_LANDSLIDE, 12s);
            events.ScheduleEvent(EVENT_CRYSTALL_SPIKES, 20s);

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetData(DATA_DARGRUL, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*unit*/) override
        {
            Talk(TALK_DEATH);
            instance->SetData(DATA_DARGRUL, DONE);
        }

        void EnterEvadeMode(EvadeReason) override
        {
            BossAI::EnterEvadeMode();
            if (instance)
            {
                instance->SetData(DATA_DARGRUL, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_MANAREGEN_TICK:
                    if (!manaRegenerated && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
                    {
                        if (instance)
                        {
                            float manaRegenMod = 4;
                            me->SetPower(POWER_MANA, me->GetPower(POWER_MANA)+(me->GetMaxPower(POWER_MANA)*manaRegenMod/100));

                            if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                            {
                                manaRegenerated = true;
                                events.ScheduleEvent(EVENT_MAGMA_WAVE, 3s);
                            }
                            else
                                events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2s);
                        }
                    }
                    break;
                case EVENT_MAGMA_SCULPTOR:
                    me->CastSpell((Unit*)nullptr, SPELL_MAGMA_SCULPTOR, false);
                    events.ScheduleEvent(EVENT_MAGMA_SCULPTOR, 60s);
                    break;
                case EVENT_LANDSLIDE:
                    me->CastSpell((Unit*)nullptr, SPELL_LANDSLIDE, false);
                    events.ScheduleEvent(EVENT_LANDSLIDE, 27s);
                    events.ScheduleEvent(EVENT_MOLTEN_CRASH, 1s + 500ms);
                    break;
                case EVENT_MOLTEN_CRASH:
                    if (me->GetVictim())
                        me->CastSpell(me->GetVictim(), SPELL_MOLTEN_CRASH, false);
                    break;
                case EVENT_CRYSTALL_SPIKES:
                    Talk(TALK_SPIKES);
                    me->CastSpell((Unit*)nullptr, SPELL_CRYSTALL_SPIKES, false);
                    events.ScheduleEvent(EVENT_CRYSTALL_SPIKES, 20s);
                    break;
                case EVENT_MAGMA_WAVE:
                    me->CastSpell(me, SPELL_MAGMA_WAVE, false);
                    events.ScheduleEvent(EVENT_RESET_MANA, 7s);
                    break;
                case EVENT_RESET_MANA:
                    me->SetPower(POWER_MANA, 0);
                    manaRegenerated = false;
                    events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2s);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 200700
class spell_dargrul_landslide : public SpellScriptLoader
{
public:
    spell_dargrul_landslide() : SpellScriptLoader("spell_dargrul_landslide") { }

    class spell_dargrul_landslide_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dargrul_landslide_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell((Unit*)nullptr, 200722, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_dargrul_landslide_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dargrul_landslide_SpellScript();
    }
};

// 200551
class spell_dargrul_crystal_spikes : public SpellScriptLoader
{
public:
    spell_dargrul_crystal_spikes() : SpellScriptLoader("spell_dargrul_crystal_spikes") { }

    class spell_dargrul_crystal_spikes_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dargrul_crystal_spikes_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell((Unit*)nullptr, 200338, false);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_dargrul_crystal_spikes_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dargrul_crystal_spikes_SpellScript();
    }
};

//101593
class mob_crystall_stalker : public CreatureScript
{
public:
    mob_crystall_stalker() : CreatureScript("mob_crystall_stalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_crystall_stalker_AI(creature);
    }

    struct mob_crystall_stalker_AI : public ScriptedAI
    {

        mob_crystall_stalker_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(35);
        }
    };
};

// 101476
class mob_molten_charskin : public CreatureScript
{
public:
    mob_molten_charskin() : CreatureScript("mob_molten_charskin") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_molten_charskin_AI(creature);
    }

    struct mob_molten_charskin_AI : public ScriptedAI
    {
        InstanceScript* instance;

        mob_molten_charskin_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(209920, me);
            instance = me->GetInstanceScript();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->ToCreature() && who->ToCreature()->GetEntry() == NPC_CRYSTALL_SPIKE && me->IsWithinDistInMap(who, 1.0f) && !me->HasAura(200672))
            {
                me->AddAura(200672, me);
                who->ToCreature()->DespawnOrUnsummon();
            }
        }

        uint32 magmaTimer = 2000;
        void UpdateAI(uint32 diff) override
        {
            if (instance)
            {
                if (magmaTimer <= diff && me->GetVictim())
                {
                    if (me->isMoving())
                        me->CastSpell(me->GetVictim(), 209930, false);
                    magmaTimer = 2000;
                }
                else
                    magmaTimer -= diff;
            }
        }
    };
};

class PlayersNearCrystallSpikeSelector
{
public:
    PlayersNearCrystallSpikeSelector() { }

    bool operator()(WorldObject* object) const
    {
        if (object->GetTypeId() == TYPEID_PLAYER)
        {
            if (Player* plr = object->ToPlayer())
                if (Creature* spike = plr->FindNearestCreature(NPC_CRYSTALL_SPIKE, 5.0f, true))
                    if (Creature* dargrul = plr->FindNearestCreature(NPC_DARGRUL, 300.0f, true))
                        if (dargrul->GetDistance2d(spike) + 1.5f < (dargrul->GetDistance2d(plr)) &&
                            dargrul->GetDistance2d(plr) < (dargrul->GetDistance2d(spike) + 7.0f))
                            return true;
            return false;
        }

        return false;
    }
};

// 200404
class spell_dargrul_magma_wave : public SpellScriptLoader
{
public:
    spell_dargrul_magma_wave() : SpellScriptLoader("spell_dargrul_magma_wave") { }

    class spell_dargrul_magma_wave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dargrul_magma_wave_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(PlayersNearCrystallSpikeSelector());
        }

        void DespawnSpikes()
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Creature*> list = caster->FindNearestCreatures(NPC_CRYSTALL_SPIKE, 250.0f);
                for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); ++itr)
                    if (Creature* spike = (*itr))
                        spike->ForcedDespawn();
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dargrul_magma_wave_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            AfterCast += SpellCastFn(spell_dargrul_magma_wave_SpellScript::DespawnSpikes);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dargrul_magma_wave_SpellScript();
    }
};

void AddSC_boss_dargrul_the_underking()
{
    RegisterCreatureAI(boss_dargrul);
    new spell_dargrul_landslide();
    new spell_dargrul_crystal_spikes();
    new mob_molten_charskin();
    new spell_dargrul_magma_wave();
    new mob_crystall_stalker();
}
