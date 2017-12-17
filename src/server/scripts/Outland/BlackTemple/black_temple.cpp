/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "black_temple.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    // Wrathbone Flayer
    SPELL_CLEAVE                = 15496,
    SPELL_IGNORED               = 39544,
    SPELL_SUMMON_CHANNEL        = 40094,

    // Angered Soul Fragment
    SPELL_GREATER_INVISIBILITY  = 41253,
    SPELL_ANGER                 = 41986,

    // Illidari Nightlord
    SPELL_SHADOW_INFERNO_DAMAGE = 39646
};

enum Creatures
{
    NPC_BLOOD_MAGE               = 22945,
    NPC_DEATHSHAPER              = 22882
};

enum Events
{
    // Wrathbone Flayer
    EVENT_GET_CHANNELERS = 1,
    EVENT_SET_CHANNELERS,
    EVENT_CLEAVE,
    EVENT_IGNORED
};

enum Misc
{
    GROUP_OUT_OF_COMBAT = 1
};

struct npc_wrathbone_flayer : public ScriptedAI
{
    npc_wrathbone_flayer(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        _enteredCombat = false;
    }

    void Reset() override
    {
        _events.ScheduleEvent(EVENT_GET_CHANNELERS, 3000);
        Initialize();
        _bloodmageList.clear();
        _deathshaperList.clear();
    }

    void JustDied(Unit* /*killer*/) override { }

    void EnterCombat(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CLEAVE, 5000);
        _events.ScheduleEvent(EVENT_IGNORED, 7000);
        _enteredCombat = true;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_enteredCombat)
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GET_CHANNELERS:
                    {
                        std::list<Creature*> BloodMageList;
                        me->GetCreatureListWithEntryInGrid(BloodMageList, NPC_BLOOD_MAGE, 15.0f);

                        if (!BloodMageList.empty())
                            for (std::list<Creature*>::const_iterator itr = BloodMageList.begin(); itr != BloodMageList.end(); ++itr)
                            {
                                _bloodmageList.push_back((*itr)->GetGUID());
                                if ((*itr)->isDead())
                                    (*itr)->Respawn();
                            }

                        std::list<Creature*> DeathShaperList;
                        me->GetCreatureListWithEntryInGrid(DeathShaperList, NPC_DEATHSHAPER, 15.0f);

                        if (!DeathShaperList.empty())
                            for (std::list<Creature*>::const_iterator itr = DeathShaperList.begin(); itr != DeathShaperList.end(); ++itr)
                            {
                                _deathshaperList.push_back((*itr)->GetGUID());
                                if ((*itr)->isDead())
                                    (*itr)->Respawn();
                            }

                        _events.ScheduleEvent(EVENT_SET_CHANNELERS, 3000);

                        break;
                    }
                    case EVENT_SET_CHANNELERS:
                    {
                        for (ObjectGuid guid : _bloodmageList)
                            if (Creature* bloodmage = ObjectAccessor::GetCreature(*me, guid))
                                bloodmage->CastSpell(nullptr, SPELL_SUMMON_CHANNEL);

                        for (ObjectGuid guid : _deathshaperList)
                            if (Creature* deathshaper = ObjectAccessor::GetCreature(*me, guid))
                                deathshaper->CastSpell(nullptr, SPELL_SUMMON_CHANNEL);

                        _events.ScheduleEvent(EVENT_SET_CHANNELERS, 12000);

                        break;
                    }
                    default:
                        break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.ScheduleEvent(EVENT_CLEAVE, urand(1000, 2000));
                    break;
                case EVENT_IGNORED:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_IGNORED);
                    _events.ScheduleEvent(EVENT_IGNORED, 10000);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    GuidList _bloodmageList;
    GuidList _deathshaperList;
    bool _enteredCombat;
};

struct npc_angered_soul_fragment : public ScriptedAI
{
    npc_angered_soul_fragment(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();

        _scheduler.Schedule(Seconds(1), GROUP_OUT_OF_COMBAT, [this](TaskContext invi)
        {
            DoCastSelf(SPELL_GREATER_INVISIBILITY);

            /* Workaround - On Retail creature appear and "vanish" again periodically, but i cant find packets
            with UPDATE_AURA on sniffs about it */
            _scheduler.Schedule(Seconds(5), Seconds(10), GROUP_OUT_OF_COMBAT, [this](TaskContext /*context*/)
            {
                me->RemoveAurasDueToSpell(SPELL_GREATER_INVISIBILITY);
            });

            invi.Repeat(Seconds(15), Seconds(25));
        });
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->RemoveAurasDueToSpell(SPELL_GREATER_INVISIBILITY);

        _scheduler.CancelGroup(GROUP_OUT_OF_COMBAT);
        _scheduler.Schedule(Seconds(1), [this](TaskContext anger)
        {
            Unit* target = me->GetVictim();
            if (target && me->IsWithinMeleeRange(target))
                DoCastSelf(SPELL_ANGER);
            else
                anger.Repeat(Seconds(1));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 41986 - Anger
class spell_soul_fragment_anger : public SpellScript
{
    PrepareSpellScript(spell_soul_fragment_anger);

    void HandleKill()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            caster->DespawnOrUnsummon(Milliseconds(200));
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_soul_fragment_anger::HandleKill);
    }
};

// 39645 - Shadow Inferno
class spell_illidari_nightlord_shadow_inferno : public AuraScript
{
    PrepareAuraScript(spell_illidari_nightlord_shadow_inferno);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_INFERNO_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* aurEffect)
    {
        PreventDefaultAction();
        int32 bp = aurEffect->GetTickNumber() * aurEffect->GetAmount();
        GetUnitOwner()->CastCustomSpell(SPELL_SHADOW_INFERNO_DAMAGE, SPELLVALUE_BASE_POINT0, bp, GetUnitOwner(), true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_illidari_nightlord_shadow_inferno::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_black_temple()
{
    RegisterBlackTempleCreatureAI(npc_wrathbone_flayer);
    RegisterBlackTempleCreatureAI(npc_angered_soul_fragment);
    RegisterSpellScript(spell_soul_fragment_anger);
    RegisterAuraScript(spell_illidari_nightlord_shadow_inferno);
}
