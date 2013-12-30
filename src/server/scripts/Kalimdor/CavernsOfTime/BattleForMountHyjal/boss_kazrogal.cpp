/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "hyjal.h"
#include "hyjal_trash.h"

enum Spells
{
    SPELL_CLEAVE        = 31436,
    SPELL_WARSTOMP      = 31480,
    SPELL_MARK          = 31447,
    SPELL_MARK_DAMAGE   = 31463
};

enum Texts
{
    SAY_ONSLAY          = 0,
    SAY_MARK            = 1,
    SAY_ONAGGRO         = 2,
};

enum Sounds
{
    SOUND_ONDEATH       = 11018,
};

class boss_kazrogal : public CreatureScript
{
public:
    boss_kazrogal() : CreatureScript("boss_kazrogal") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_kazrogalAI>(creature);
    }

    struct boss_kazrogalAI : public hyjal_trashAI
    {
        boss_kazrogalAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
        }

        uint32 CleaveTimer;
        uint32 WarStompTimer;
        uint32 MarkTimer;
        uint32 MarkTimerBase;
        bool go;

        void Reset() OVERRIDE
        {
            damageTaken = 0;
            CleaveTimer = 5000;
            WarStompTimer = 15000;
            MarkTimer = 45000;
            MarkTimerBase = 45000;

            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, IN_PROGRESS);
            Talk(SAY_ONAGGRO);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_ONSLAY);
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            if (waypointId == 7 && instance)
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                if (target && target->IsAlive())
                    me->AddThreat(target, 0.0f);
            }
        }

        void JustDied(Unit* killer) OVERRIDE
        {
            hyjal_trashAI::JustDied(killer);
            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, DONE);
            DoPlaySoundToSet(me, SOUND_ONDEATH);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (IsEvent)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(diff);
                if (!go)
                {
                    go = true;
                    AddWaypoint(0, 5492.91f,    -2404.61f,    1462.63f);
                    AddWaypoint(1, 5531.76f,    -2460.87f,    1469.55f);
                    AddWaypoint(2, 5554.58f,    -2514.66f,    1476.12f);
                    AddWaypoint(3, 5554.16f,    -2567.23f,    1479.90f);
                    AddWaypoint(4, 5540.67f,    -2625.99f,    1480.89f);
                    AddWaypoint(5, 5508.16f,    -2659.2f,    1480.15f);
                    AddWaypoint(6, 5489.62f,    -2704.05f,    1482.18f);
                    AddWaypoint(7, 5457.04f,    -2726.26f,    1485.10f);
                    Start(false, true);
                    SetDespawnAtEnd(false);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (CleaveTimer <= diff)
            {
                DoCast(me, SPELL_CLEAVE);
                CleaveTimer = 6000+rand()%15000;
            } else CleaveTimer -= diff;

            if (WarStompTimer <= diff)
            {
                DoCast(me, SPELL_WARSTOMP);
                WarStompTimer = 60000;
            } else WarStompTimer -= diff;

            if (MarkTimer <= diff)
            {
                DoCastAOE(SPELL_MARK);

                MarkTimerBase -= 5000;
                if (MarkTimerBase < 5500)
                    MarkTimerBase = 5500;
                MarkTimer = MarkTimerBase;
                Talk(SAY_MARK);
            } else MarkTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class MarkTargetFilter
{
    public:
        bool operator()(WorldObject* target) const
        {
            if (Unit* unit = target->ToUnit())
                return unit->getPowerType() != POWER_MANA;
            return false;
        }
};

class spell_mark_of_kazrogal : public SpellScriptLoader
{
    public:
        spell_mark_of_kazrogal() : SpellScriptLoader("spell_mark_of_kazrogal") { }

        class spell_mark_of_kazrogal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mark_of_kazrogal_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(MarkTargetFilter());
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mark_of_kazrogal_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        class spell_mark_of_kazrogal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_kazrogal_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_DAMAGE))
                    return false;
                return true;
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();

                if (target->GetPower(POWER_MANA) == 0)
                {
                    target->CastSpell(target, SPELL_MARK_DAMAGE, true, NULL, aurEff);
                    // Remove aura
                    SetDuration(0);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_kazrogal_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mark_of_kazrogal_SpellScript();
        }

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_mark_of_kazrogal_AuraScript();
        }
};

void AddSC_boss_kazrogal()
{
    new boss_kazrogal();
    new spell_mark_of_kazrogal();
}
