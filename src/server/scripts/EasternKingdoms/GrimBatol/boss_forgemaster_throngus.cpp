/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
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
#include "grim_batol.h"

enum Yells
{
    SAY_ENGAGE  = 0,
    SAY_SHIELD  = 1,
    SAY_SWORD   = 2,
    SAY_MACE    = 3,
    SAY_SLAY    = 4,
    SAY_SLAY2   = 5,
    SAY_DEATH   = 6
};

enum Spells
{
    // Misc
    SPELL_MIGHTY_STOMP = 74984, //pietinement puissant
    SPELL_PICK_WEAPON = 75000, // He switches his weapon (DBM Announce)
    SPELL_EBOULEMENT = 74987,
    SPELL_EBOULEMENT_TRIGGER = 74986,

    //Shield
    SPELL_SHIELD_VISUAL = 94588,
    SPELL_FLAME_ARROW = 74946,
    SPELL_PERSONAL_PHALANX_FIX = 75071,
    SPELL_PERSONAL_PHALANX = 74908,
    SPELL_FLAMING_SHIELD = 90819,

    // Sword Phase
    SPELL_DUAL_BLADES_BUFF = 74981,
    SPELL_BURNING_FLAMES = 90759,
    SPELL_DISORIENTING_ROAR = 74976,

    // Mace Phase
    SPELL_ENCUMBERED = 75007,
    SPELL_LAVAL_MARRE = 90743,
    SPELL_IMPALING_SLAM = 75056,

    SPELL_LAVA_PATCH = 90754,
    SPELL_LAVA_PATCH_VISUAL = 90752,
};

enum Events
{
    // General
    EVENT_PICK_WEAPON = 1,
    EVENT_STOMP,
    // Shield Phase
    EVENT_PERSONAL_PHALANX ,
    EVENT_PERSONAL_PHALANX_FIX,
    // Swords Phase
    EVENT_DISORIENTING_ROAR,
    // Mace Phase
    EVENT_IMPALING_SLAM,
    EVENT_ARCHER_SHOOT,
};

enum Weapon
{
    WEAPON_NON       = 0,
    WEAPON_CHOOSING  = 1,
    WEAPON_SHIELD    = 2,
    WEAPON_SWORDS    = 3,
    WEAPON_MACE      = 4,
};

enum Equipment
{
    EQUIPMENT_ID_SWORD    = 65094,  // Not Blizzlike
    EQUIPMENT_ID_MACE    = 65090,  // Not Blizzlike
};

Position const TwilightArcherSummonPos[13] =
{
    {-542.994f, -605.236f, 300.201f, 1.68049f},
    {-543.59f, -605.413f, 283.784f, 1.50377f},
    {-521.237f, -605.435f, 300.76f, 1.63886f},
    {-483.862f, -588.658f, 297.574f, 2.38106f},
    {-482.655f, -588.461f, 280.966f, 2.34571f},
    {-471.266f, -575.324f, 295.906f, 2.30254f},
    {-525.377f, -455.312f, 285.288f, 4.66187f},
    {-544.49f, -454.961f, 295.831f, 4.79539f},
    {-522.164f, -455.31f, 299.791f, 4.77575f},
    {-468.703f, -489.004f, 300.462f, 3.78616f},
    {-470.907f, -484.791f, 282.203f, 3.87255f},
    {-485.052f, -474.621f, 296.525f, 3.92361f},
    {-481.352f, -477.21f, 280.714f, 3.72334f}
};

class boss_forgemaster_throngus: public CreatureScript
{
public:
    boss_forgemaster_throngus() : CreatureScript("boss_forgemaster_throngus") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_forgemaster_throngusAI (pCreature);
    }

    struct boss_forgemaster_throngusAI : public ScriptedAI
    {
        boss_forgemaster_throngusAI(Creature *c) : ScriptedAI(c), instance(c->GetInstanceScript()) {}

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(0);
            phases[0] = 0;
            phases[1] = 0;
            phases[2] = 0;
            events.ScheduleEvent(EVENT_PICK_WEAPON, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
                  Talk(1);
                  DespawnCreatures(NPC_FIRE_PATCH);
                  DespawnCreatures(NPC_TWILIGHT_ARCHER);
                  instance->SetData(DATA_FORGEMASTER_THRONGUS, DONE);
                  DespawnCreatures(40228);
        }

        void Reset() override
        {
                  events.Reset();
                  currentWaepon = WEAPON_NON;
                  DespawnCreatures(NPC_FIRE_PATCH);
                  DespawnCreatures(NPC_TWILIGHT_ARCHER);
                  SetEquipmentSlots(false, 0, 0,0);
                  instance->SetData(DATA_FORGEMASTER_THRONGUS, NOT_STARTED);
                  DespawnCreatures(40228);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || (me->HasUnitState(UNIT_STATE_CASTING) && currentWaepon != WEAPON_SHIELD))
                return;

            if (currentWaepon == WEAPON_CHOOSING)
            {
                IntializeWeapon();
                events.ScheduleEvent(EVENT_PICK_WEAPON, 30000);
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_PICK_WEAPON:
                    {
                        ResetWeapon();
                        DoCast(SPELL_PICK_WEAPON);
                        currentWaepon = WEAPON_CHOOSING;
                        return;
                    }
                    case EVENT_STOMP:
                    {
                        DoCast(SPELL_MIGHTY_STOMP);
                        events.ScheduleEvent(EVENT_STOMP, 15000);
                        break;
                    }
                   case EVENT_PERSONAL_PHALANX:
                    {
                        if (Creature *c = me->FindNearestCreature(40255, 100))
                            c->DespawnOrUnsummon();
                        events.ScheduleEvent(EVENT_PERSONAL_PHALANX_FIX, 1000);
                        events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 9000);
                        break;
                    }
                       case EVENT_PERSONAL_PHALANX_FIX:
                    {
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                        {
                            DoCast(me, SPELL_PERSONAL_PHALANX, true);
                            tempTarget->CastSpell(tempTarget, 74926, true);
                            me->CastSpell(me, SPELL_PERSONAL_PHALANX_FIX, true);
                        }
                        break;
                    }
                   case EVENT_IMPALING_SLAM:
                    {
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(tempTarget, SPELL_IMPALING_SLAM);
                        events.ScheduleEvent(EVENT_IMPALING_SLAM, 15000);
                        break;
                    }
                   case EVENT_DISORIENTING_ROAR:
                    {
                        DoCastAOE(SPELL_DISORIENTING_ROAR);
                        events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon) override
        {
            summon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
            switch (summon->GetEntry())
            {
                case NPC_FIRE_PATCH:
                    summon->CastSpell(summon, SPELL_LAVA_PATCH_VISUAL, true);
                    break;
                case NPC_CAVE_IN_STALKER:
                    summon->CastSpell(summon, SPELL_EBOULEMENT, true);
                    break;
                default :
                    break;
            }
        }

    private:
        void IntializeWeapon()
        {
            currentWaepon = GetNextPhase();

            switch (currentWaepon)
            {
                case WEAPON_SHIELD:
                    DoCast(me, SPELL_SHIELD_VISUAL, true);
                    DespawnCreatures(NPC_TWILIGHT_ARCHER);
                    for(uint32 i = 0; i <= 12; i++)
                        me->SummonCreature(NPC_TWILIGHT_ARCHER, TwilightArcherSummonPos[i], TEMPSUMMON_MANUAL_DESPAWN);
//                    DoCast(me, SPELL_FLAME_ARROW, true);
                    if (me->GetMap()->IsHeroic())
                        DoCast(me, SPELL_FLAMING_SHIELD, true);
                    events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 100);
                    break;
                case WEAPON_SWORDS:
                    DoCast(me, SPELL_DUAL_BLADES_BUFF, true);
                    if (IsHeroic())
                        DoCast(me, SPELL_BURNING_FLAMES, true);
                    SetEquipmentSlots(false, EQUIPMENT_ID_SWORD, EQUIPMENT_ID_SWORD, 0);
                    events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);
                    events.ScheduleEvent(EVENT_STOMP, urand(5000, 9000));
                    break;
                case WEAPON_MACE:
                    DoCast(me, SPELL_ENCUMBERED, true);
                    SetEquipmentSlots(false, EQUIPMENT_ID_MACE, 0,0);
                    events.ScheduleEvent(EVENT_IMPALING_SLAM, 7000);
                    events.ScheduleEvent(EVENT_STOMP, 9000);
                    break;
            }
        }

        void ResetWeapon()
        {
            events.Reset();
            if (Creature *c = me->FindNearestCreature(40255, 100))
                c->DespawnOrUnsummon();
            DespawnCreatures(NPC_TWILIGHT_ARCHER);
            me->RemoveAura(SPELL_FLAME_ARROW);
            me->RemoveAura(SPELL_FLAMING_SHIELD);
            me->RemoveAura(SPELL_PERSONAL_PHALANX);
            me->RemoveAura(SPELL_PERSONAL_PHALANX_FIX);
            me->RemoveAura(SPELL_DUAL_BLADES_BUFF);
            me->RemoveAura(SPELL_LAVA_PATCH);
            me->RemoveAura(SPELL_ENCUMBERED);
        }

        uint8 GetNextPhase()
        {
            uint8 base[3] = {WEAPON_SHIELD, WEAPON_SWORDS, WEAPON_MACE};
            if (phases[0] == 0 && phases[1] == 0 && phases[2] == 0)
            {
                for(uint8 i = 0; i <= 2; i++)
                {
                    while (phases[i] == 0)
                    {
                        uint8 r = urand(0,2);
                        phases[i] = base[r];
                        base[r] = 0;
                    }
                }
                uint8 v = phases[0];
                phases[0] = 0;
                return v;
            }
            else
            {
                for (uint8 i = 0; i <= 2; i++)
                {
                    if (phases[i] != 0)
                    {
                        uint8 v = phases[i];
                        phases[i] = 0;
                        return v;
                    }
                }
            }
            return urand(WEAPON_SHIELD,WEAPON_MACE);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        EventMap events;
        uint32 currentWaepon;
        uint8 phases [3];
        InstanceScript *instance;
    };
};

class spell_effect_fix : public SpellScriptLoader
{
public:
    spell_effect_fix() : SpellScriptLoader("spell_effect_fix") { }

    class spell_effect_fix_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_effect_fix_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit *caster = GetCaster())
                caster->AddUnitState(UNIT_STATE_CANNOT_TURN);
        }

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit *caster = GetCaster())
                caster->ClearUnitState(UNIT_STATE_CANNOT_TURN);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_effect_fix_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            AfterEffectRemove += AuraEffectRemoveFn(spell_effect_fix_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_effect_fix_AuraScript();
    }
};


class spell_throngus_arrow_barage : public SpellScriptLoader
{
    class DistCheck
    {
    public:
        DistCheck(Unit *caster)
        {
            _caster = caster;
        }

        bool operator() (WorldObject* obj)
        {
            if (_caster && obj)
                if (_caster->GetDistance2d(obj) >= 60)
                    return true;
            return false;
        }
    private:
        Unit *_caster;
    };


public:
    spell_throngus_arrow_barage() : SpellScriptLoader("spell_throngus_arrow_barage")
    {
    }

    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        bool Load() override
        {
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(DistCheck(GetCaster()));
            if (unitList.empty())
                return;
            std::list<WorldObject*>::const_iterator itr = unitList.begin();
            advance(itr, rand() % unitList.size());
            if (WorldObject * tar = *itr)
            {
                unitList.clear();
                unitList.push_back(tar);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(script_impl::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new script_impl();
    }
};

class spell_disoriented_roar : public SpellScriptLoader
{
public:
    spell_disoriented_roar() : SpellScriptLoader("spell_disoriented_roar") { }

    class spell_disoriented_roar_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_disoriented_roar_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_disoriented_roar_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_SPEED_SLOW_ALL);
        }

    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_disoriented_roar_AuraScript();
    }
};

void AddSC_boss_forgemaster_throngus()
{
    new boss_forgemaster_throngus();
    new spell_effect_fix();
    new spell_throngus_arrow_barage();
    new spell_disoriented_roar();
}
