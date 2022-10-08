/*
 * Trinity Core and update by MoPCore Forums
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
 *
 * Dungeon: Siege of Niuzao Temple.
 * Boss:    Vizier Jin'bak.
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "InstanceScript.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Spell.h"
#include "Map.h"
#include "MapManager.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

#include "siege_of_niuzao_temple.h"

enum Yells
{
    SAY_INTRO               = 0, // I hope they make it this far. Then my strength and skill will be clear to all.
    SAY_AGGRO               = 1, // Ah-hah! The lot of you will soon wish you hadn't come this way...
    SAY_DETONATE            = 2, // Allow me to show you the power of amber alchemy...
    SAY_KILL                = 3, // 0 - Your curve bones will decorate the weapons of our warriors! ; 1 - Did you think you stood a chance?
    SAY_DEATH               = 4  // But... I was... who will...!?
};

#define ANN_GLOBULES "Sap Globules begin to sprout from the tree!"
#define ANN_DETONATE "Vizier Jin'bak begins to cast |cFFFF0000|Hspell:120001|h[Detonate]|h|r!"

enum Spells
{
    // Boss
    SPELL_SAP_PUDDLE_SUMMON = 123112, // The Sap Puddle grows over time. Touching the Sap Puddle causes it to shrink in size.
    SPELL_SUMMON_GLOBULE    = 119990, // Sap Globules will try to congeal with the Sap Puddle, increasing its size. 15s A, every 45 seconds.

    SPELL_DETONATE_COSMETIC = 120095, // Boss cosmetic (before event starts).
    SPELL_DETONATE          = 120001, // The Resin Harvester attempts to detonate the Sap Puddle, inflicting damage based on the size of the Sap Puddle. 30s A, every 45 seconds.
    SPELL_DETONATE_DMG      = 120002, // Damage calculated according to puddle size.

    // Sap Puddle
    SPELL_SAP_PUDDLE_AURA   = 119939, // The Sap Puddle grows, inflicting 4000 Shadow damage over 1 sec to enemies who touch it.
    SPELL_SAP_PUDDLE_RES    = 120591, // Touching the Sap Puddle causes the Residue to attach. Puddle PD aura, 120593 dmg. 8 secs.
    SPELL_SAP_RESIDUE_SE    = 120070, // Every 1 sec. Trig by aura. Shrink / Increase size check.
    SPELL_SAP_RESIDUE_AURA  = 119941, // Every 1 sec. Trig by aura. Applies player debuff. Sap Residue inflicts 4000 Shadow damage each 1 sec. over 10 sec. The effect stacks.

    SPELL_GROW              = 120865, // + 10% Size.

    // Sap Globule
    SPELL_GLOBULE_VISUAL    = 120071
};

enum Events
{
    // Boss
    EVENT_SUMMON_GLOBULES   = 1,
    EVENT_DETONATE,

    // Sap Globule
    EVENT_MOVE_PUDDLE
};

// Sap Puddle position.
Position const middlePos        = { 1529.52f, 5163.24f, 160.57f };

// Vizier Jin'bak 61567.
class boss_vizier_jinbak : public CreatureScript
{
    public:
        boss_vizier_jinbak() : CreatureScript("boss_vizier_jinbak") { }

        struct boss_vizier_jinbakAI : public BossAI
        {
            boss_vizier_jinbakAI(Creature* creature) : BossAI(creature, DATA_VIZIER_JINBAK_EVENT), summons(me)
            {
                instance = creature->GetInstanceScript();
                introDone = false;
                evaded = false;
            }

            InstanceScript* instance;
            SummonList summons;
            EventMap events;
            bool introDone, evaded;

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                if (instance)
                    instance->SetData(DATA_VIZIER_JINBAK_EVENT, NOT_STARTED);

                _Reset();

                if (!evaded)
                    if (Creature* puddle = me->SummonCreature(NPC_SAP_PUDDLE, middlePos, TEMPSUMMON_CORPSE_DESPAWN, 1000))
                        DoCast(puddle, SPELL_DETONATE_COSMETIC);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!introDone && me->IsWithinDistInMap(who, 40) && who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_INTRO);
                    introDone = true;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_SUMMON_GLOBULES, 15000);
                events.ScheduleEvent(EVENT_DETONATE, 30000);

                if (instance)
                {
                    instance->SetData(DATA_VIZIER_JINBAK_EVENT, IN_PROGRESS);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                }

                _EnterCombat();
            }

            void DamageTaken(Unit* who, uint32& damage)
            {
                if (Spell* spell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                    if (spell->m_spellInfo->Id == SPELL_DETONATE_COSMETIC)
                        me->InterruptNonMeleeSpells(true);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void EnterEvadeMode()
            {
                evaded = true;
                me->AddUnitState(UNIT_STATE_EVADE);

                me->RemoveAllAuras();
                Reset();
                me->DeleteThreatList();
                me->CombatStop(true);
                me->GetMotionMaster()->MoveTargetedHome();

                if (instance)
                {
                    instance->SetData(DATA_VIZIER_JINBAK_EVENT, FAIL);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                }

                _EnterEvadeMode();
            }

            void JustReachedHome()
            {
                me->ClearUnitState(UNIT_STATE_EVADE);

                if (evaded)
                    if (Creature* puddle = me->SummonCreature(NPC_SAP_PUDDLE, middlePos, TEMPSUMMON_CORPSE_DESPAWN, 1000))
                        DoCast(puddle, SPELL_DETONATE_COSMETIC);

                _JustReachedHome();
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
                summons.DespawnAll();

                if (instance)
                {
                    instance->SetData(DATA_VIZIER_JINBAK_EVENT, DONE);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                }

                _JustDied();
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                summon->setActive(true);

		        if (me->isInCombat())
                    summon->SetInCombatWithZone();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_GLOBULES:
                            me->MonsterTextEmote(ANN_GLOBULES, NULL, true);
                            DoCast(me, SPELL_SUMMON_GLOBULE);
                            events.ScheduleEvent(EVENT_SUMMON_GLOBULES, 45000);
                            break;

                        case EVENT_DETONATE:
                            me->MonsterTextEmote(ANN_DETONATE, NULL, true);
                            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f, true))
                                DoCast(puddle, SPELL_DETONATE);
                            events.ScheduleEvent(EVENT_DETONATE, 45000);
                            break;

                        default: break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_vizier_jinbakAI(creature);
        }
};

// Sap Puddle 61613.
class npc_sap_puddle : public CreatureScript
{
    public:
        npc_sap_puddle() : CreatureScript("npc_sap_puddle") { }

        struct npc_sap_puddleAI : public ScriptedAI
        {
            npc_sap_puddleAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void IsSummonedBy(Unit* summoner)
            {
                Reset();
                me->AddAura(SPELL_SAP_PUDDLE_AURA, me);
				me->AddAura(SPELL_SAP_PUDDLE_RES, me);
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
            }

            void UpdateAI(uint32 const diff)
            {
                // Keep damage aura on.
                if (!me->HasAura(SPELL_SAP_PUDDLE_RES))
				    me->AddAura(SPELL_SAP_PUDDLE_RES, me);

                // No melee.			
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sap_puddleAI(creature);
        }
};

// Sap Globule 61623.
class npc_sap_globule : public CreatureScript
{
    public:
        npc_sap_globule() : CreatureScript("npc_sap_globule") { }

        struct npc_sap_globuleAI : public ScriptedAI
        {
            npc_sap_globuleAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            bool congealed;

            void IsSummonedBy(Unit* summoner)
            {
                Reset();

                me->SetSpeed(MOVE_WALK, 0.75f);
                me->SetSpeed(MOVE_RUN, 0.75f);

                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_GLOBULE_VISUAL, me);

                events.ScheduleEvent(EVENT_MOVE_PUDDLE, 1000);
            }

            void Reset()
            {
                events.Reset();
                congealed = false;
            }

            void UpdateAI(uint32 const diff)
            {
                // If the globule reaches the puddle, despawn it and increase the puddle size.
                if (me->GetDistance(middlePos) <= 2.0f && !congealed)
                {
                    congealed = true;

                    if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 3.0f))
                        puddle->AddAura(SPELL_GROW, puddle);
                    me->DespawnOrUnsummon(100);
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_PUDDLE:
                            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f))
                                me->GetMotionMaster()->MovePoint(1, puddle->GetPositionX(), puddle->GetPositionY(), puddle->GetPositionZ()); 
                            break;

                        default: break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sap_globuleAI(creature);
        }
};

// Sap Residue aura 119941.
class spell_jinbak_sap_residue_aura : public SpellScriptLoader
{
    public:
        spell_jinbak_sap_residue_aura() : SpellScriptLoader("spell_jinbak_sap_residue_aura") { }
        
        class spell_jinbak_sap_residue_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinbak_sap_residue_aura_SpellScript);

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                if (Unit* caster = GetCaster())
                {
                    targets.clear();

                    float dist = 4.0f * caster->GetObjectScale();

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, caster, dist);

                    if (!playerList.empty())
                        for (std::list<Player*>::iterator player = playerList.begin(); player != playerList.end(); player++)
                            targets.push_back(*player);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jinbak_sap_residue_aura_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_jinbak_sap_residue_aura_SpellScript();
        }
};

// Sap Residue script effect 120070.
class spell_jinbak_sap_residue_se : public SpellScriptLoader
{
    public:
        spell_jinbak_sap_residue_se() : SpellScriptLoader("spell_jinbak_sap_residue_se") { }

        class spell_jinbak_sap_residue_se_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinbak_sap_residue_se_SpellScript);

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                if (Unit* caster = GetCaster())
                {
                    targets.clear();

                    float dist = 4.0f * caster->GetObjectScale();

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, caster, dist);

                    if (!playerList.empty())
                        for (std::list<Player*>::iterator player = playerList.begin(); player != playerList.end(); player++)
                            targets.push_back(*player);
                }
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!caster || !target)
                    return;

                // Shrink for each player in the puddle.
                if (AuraPtr grow = caster->GetAura(SPELL_GROW))
                {
                    if (grow->GetStackAmount() > 1)
                        grow->SetStackAmount(grow->GetStackAmount() - 1);
                    else
                        caster->RemoveAurasDueToSpell(SPELL_GROW);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jinbak_sap_residue_se_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_jinbak_sap_residue_se_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_jinbak_sap_residue_se_SpellScript();
        }
};

// Detonate 120001.
class spell_jinbak_detonate : public SpellScriptLoader
{
    public:
        spell_jinbak_detonate() : SpellScriptLoader("spell_jinbak_detonate") { }

        class spell_jinbak_detonate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jinbak_detonate_AuraScript)

            void OnPeriodic(constAuraEffectPtr /*aurEff*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetTarget();

                if (!caster || !target)
                    return;

                target->CastSpell(target, SPELL_DETONATE_DMG, true);
                target->RemoveAurasDueToSpell(SPELL_GROW);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_jinbak_detonate_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_jinbak_detonate_AuraScript();
        }
};

// Detonate damage 120002.
class spell_jinbak_detonate_damage : public SpellScriptLoader
{
    public:
        spell_jinbak_detonate_damage() : SpellScriptLoader("spell_jinbak_detonate_damage") { }

        class spell_jinbak_detonate_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinbak_detonate_damage_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!caster || !target)
                    return;

                // Damage seems to be 75 k * scale.
                SetHitDamage(75000 * caster->GetObjectScale());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_jinbak_detonate_damage_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_jinbak_detonate_damage_SpellScript();
        }
};

void AddSC_boss_vizier_jinbak()
{
    new boss_vizier_jinbak();
    new npc_sap_puddle();
    new npc_sap_globule();
    new spell_jinbak_sap_residue_aura();
    new spell_jinbak_sap_residue_se();
    new spell_jinbak_detonate();
    new spell_jinbak_detonate_damage();
}
