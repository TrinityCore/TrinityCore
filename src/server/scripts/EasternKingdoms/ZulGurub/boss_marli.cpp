/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "zulgurub.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Object.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Says
{
    SAY_AGGRO                 = 0,
    SAY_TRANSFORM             = 1,
    SAY_SPIDER_SPAWN          = 2,
    SAY_DEATH                 = 3
};

enum Spells
{
    SPELL_CHARGE              = 22911,
    SPELL_ASPECT_OF_MARLI     = 24686, // A stun spell
    SPELL_ENVOLWINGWEB        = 24110,
    SPELL_POISON_VOLLEY       = 24099,
    SPELL_SPIDER_FORM         = 24084,
    SPELL_HATCH_EGGS          = 24083,
    SPELL_HATCH_SPIDER_EGG    = 24082,
    // The Spider Spell
    SPELL_LEVELUP             = 24312  // Not right Spell.
};

enum Events
{
    EVENT_SPAWN_START_SPIDERS = 1, // Phase 1
    EVENT_POISON_VOLLEY       = 2, // Phase All
    EVENT_HATCH_SPIDER_EGG    = 3, // Phase All
    EVENT_CHARGE_PLAYER       = 4, // Phase 3
    EVENT_ASPECT_OF_MARLI     = 5, // Phase 2
    EVENT_TRANSFORM           = 6, // Phase 2
    EVENT_TRANSFORM_BACK      = 7  // Phase 3
};

enum Phases
{
    PHASE_ONE                 = 1,
    PHASE_TWO                 = 2,
    PHASE_THREE               = 3
};

enum Misc
{
    NPC_SPIDER                = 15041,
    GOB_SPIDER_EGG            = 179985,
};

// AWFUL HACK WARNING
// To whoever reads this: Zul'Gurub needs your love
// Need to do this calculation to increase/decrease Mar'li's damage by 35% (probably some aura missing)
// This is only to compile the scripts after the aura calculation revamp
float const DamageIncrease = 35.0f;
float const DamageDecrease = 100.f / (1.f + DamageIncrease / 100.f) - 100.f;

class boss_marli : public CreatureScript
{
    public: boss_marli() : CreatureScript("boss_marli") { }

        struct boss_marliAI : public BossAI
        {
            boss_marliAI(Creature* creature) : BossAI(creature, DATA_MARLI) { }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_THREE))
                    me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageDecrease); // hack

                std::list<GameObject*> eggs;
                me->GetGameObjectListWithEntryInGrid(eggs, GOB_SPIDER_EGG);
                for (GameObject* egg : eggs)
                {
                    egg->Respawn();
                    egg->UpdateObjectVisibility(true);
                }

                summons.DespawnAll();
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_SPAWN_START_SPIDERS, 1s, 0, PHASE_ONE);
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* creature) override
            {
                creature->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true));
                summons.Summon(creature);
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
                        case EVENT_SPAWN_START_SPIDERS:
                            Talk(SAY_SPIDER_SPAWN);
                            DoCastAOE(SPELL_HATCH_EGGS);
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 12s, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45s, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, 15s);
                            events.ScheduleEvent(EVENT_HATCH_SPIDER_EGG, 30s);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45s, 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            break;
                        case EVENT_POISON_VOLLEY:
                            DoCastVictim(SPELL_POISON_VOLLEY, true);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, 10s, 20s);
                            break;
                        case EVENT_ASPECT_OF_MARLI:
                            DoCastVictim(SPELL_ASPECT_OF_MARLI, true);
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 13s, 18s, 0, PHASE_TWO);
                            break;
                        case EVENT_HATCH_SPIDER_EGG:
                            me->CastSpell(me, SPELL_HATCH_SPIDER_EGG);
                            events.ScheduleEvent(EVENT_HATCH_SPIDER_EGG, 12s, 17s);
                            break;
                        case EVENT_TRANSFORM:
                        {
                            Talk(SAY_TRANSFORM);
                            DoCast(me, SPELL_SPIDER_FORM); // SPELL_AURA_TRANSFORM
                            /*
                            CreatureTemplate const* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageIncrease); // hack
                            DoCastVictim(SPELL_ENVOLWINGWEB);
                            if (GetThreat(me->GetVictim()))
                                ModifyThreatByPercent(me->GetVictim(), -100);
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, 1500ms, 0, PHASE_THREE);
                            events.ScheduleEvent(EVENT_TRANSFORM_BACK, 25s, 0, PHASE_THREE);
                            events.CancelEvent(EVENT_HATCH_SPIDER_EGG);
                            events.SetPhase(PHASE_THREE);
                            break;
                        }
                        case EVENT_CHARGE_PLAYER:
                        {
                            Unit* target = nullptr;
                            int i = 0;
                            while (i++ < 3) // max 3 tries to get a random target with power_mana
                            {
                                target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);  // not aggro leader
                                if (target && target->GetPowerType() == POWER_MANA)
                                    break;
                            }
                            if (target)
                            {
                                DoCast(target, SPELL_CHARGE);
                                AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, 8s, 0, PHASE_THREE);
                            break;
                        }
                        case EVENT_TRANSFORM_BACK:
                        {
                            me->RemoveAura(SPELL_SPIDER_FORM);
                            /*
                            CreatureTemplate const* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 1)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 1)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageDecrease); // hack
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 12s, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45s, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, 15s);
                            events.ScheduleEvent(EVENT_HATCH_SPIDER_EGG, 12s, 17s);
                            events.ScheduleEvent(EVENT_TRANSFORM, urand(35000, 60000), 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            break;
                        }
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_marliAI>(creature);
        }
};

class gob_spider_egg : public GameObjectScript
{
   public: gob_spider_egg() : GameObjectScript("gob_spider_egg") { }

        struct gob_spider_eggAI : public GameObjectAI
        {
            gob_spider_eggAI(GameObject* gob) : GameObjectAI(gob), _instance(gob->GetInstanceScript()) { }

            void JustSummoned(Creature* creature) override
            {
                if (Creature * marli = _instance->GetCreature(DATA_MARLI))
                    marli->AI()->JustSummoned(creature);

                me->SetRespawnCompatibilityMode(true);
            }
        private:
            InstanceScript* const _instance;
        };

        GameObjectAI* GetAI(GameObject* gob) const override
        {
            return GetZulGurubAI<gob_spider_eggAI>(gob);
        }
};

// Spawn of Marli
class npc_spawn_of_marli : public CreatureScript
{
    public: npc_spawn_of_marli() : CreatureScript("npc_spawn_of_marli") { }

        struct npc_spawn_of_marliAI : public ScriptedAI
        {
            npc_spawn_of_marliAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _levelUpTimer = 3000;
            }

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_levelUpTimer <= diff)
                {
                    DoCast(me, SPELL_LEVELUP);
                    _levelUpTimer = 3000;
                }
                else
                    _levelUpTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _levelUpTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_spawn_of_marliAI>(creature);
        }
};

class spell_hatch_spiders : public SpellScript
{
       PrepareSpellScript(spell_hatch_spiders);

       void HandleObjectAreaTargetSelect(std::list<WorldObject*>& targets)
       {
           targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
           targets.resize(GetSpellInfo()->MaxAffectedTargets);
       }

       void Register() override
       {
           OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hatch_spiders::HandleObjectAreaTargetSelect, EFFECT_0, TARGET_GAMEOBJECT_DEST_AREA);
       }

};

void AddSC_boss_marli()
{
    new boss_marli();
    new npc_spawn_of_marli();
    new gob_spider_egg();
    RegisterSpellScript(spell_hatch_spiders);
}
