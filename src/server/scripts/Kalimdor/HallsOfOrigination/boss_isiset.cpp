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

#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_SUPERNOVA                         = 74136,
    SPELL_SUPERNOVA_EFFECT                  = 74137,

    // Startfall / Astral Rain ability
    SPELL_ASTRAL_RAIN_CONTROLLER            = 74381,
    SPELL_ASTRAL_RAIN_1                     = 74134,
    SPELL_ASTRAL_RAIN_2                     = 74365,
    SPELL_ASTRAL_RAIN_3                     = 74371,

    // Adds / Celestial Call ability
    SPELL_ASTRAL_FAMILIAR_CONTROLLER        = 74383,
    SPELL_CELESTIAL_CALL_1                  = 74362,
    SPELL_CELESTIAL_CALL_2                  = 74355,
    SPELL_CELESTIAL_CALL_3                  = 74364,

    // Mana shield / Veil of Sky ability
    SPELL_MANA_SHIELD_CONTROLLER            = 74382,
    SPELL_VEIL_OF_SKY_1                     = 74133,
    SPELL_VEIL_OF_SKY_2                     = 74372,
    SPELL_VEIL_OF_SKY_3                     = 74373,
    SPELL_VEIL_OF_SKY_DAMAGE                = 79370,

    // Mirror Images (at 66% and 33%)
    SPELL_MIRROR_IMAGE_STARRY_SKY_SPAWNER   = 69941,
    SPELL_MIRROR_IMAGE_STARRY_SKY_N         = 69936,
    SPELL_MIRROR_IMAGE_STARRY_SKY_E         = 69939,
    SPELL_MIRROR_IMAGE_STARRY_SKY_W         = 69940,
    SPELL_ASTRAL_SHIFT                      = 74312,
    SPELL_ASTRAL_SHIFT_EXPLOSION            = 74333,
    SPELL_MIRROR_IMAGE_SPAWNER              = 74264,
    SPELL_MIRROR_IMAGE_N                    = 74263,
    SPELL_MIRROR_IMAGE_E                    = 74262,
    SPELL_MIRROR_IMAGE_W                    = 74261,
    SPELL_ADDS_STATE_VISUAL                 = 74289,
    SPELL_STARFALL_STATE_VISUAL             = 74265,
    SPELL_MANA_SHIELD_STATE_VISUAL          = 74266,
    SPELL_IMAGE_EXPLOSION                   = 74301,

    // Celestial Familiar npc
    SPELL_ORB_VISUAL                        = 74356, 
    SPELL_ARCANE_BARRAGE                    = 74374,

    // Starry Sky npc
    SPELL_STARRY_SKY_VISUAL                 = 74149,

    // Astral Shift Explosion Visual npc
    SPELL_ASTRAL_SHIFT_EXPLOSION_VISUAL     = 74331,

    // Spatial Flux & Energy Flux (heroic only)
    SPELL_CALL_OF_SKY                       = 90750  // Summons Spatial Flux (npc script in halls_of_oriignation.cpp)
};

enum NPCs
{
    NPC_CELESTIAL_FAMILIAR                  = 39795,
    NPC_ASTRAL_RAIN                         = 39720, // N
    NPC_CELESTIAL_CALL                      = 39721, // E
    NPC_VEIL_OF_SKY                         = 39722, // W
    NPC_ISISET_SPATIAL_FLUX                 = 48707  // heroic only
};

enum Texts
{
    SAY_AGGRO                               = 0,
    SAY_SUPERNOVA                           = 1,
    SAY_SUPERNOVA_WARNING                   = 2,
    SAY_PLAYER_KILL                         = 3,
    SAY_DEATH                               = 4
};

enum Events
{
    EVENT_SUPERNOVA = 1,
    EVENT_ASTRAL_RAIN,
    EVENT_ASTRAL_FAMILIAR,
    EVENT_VEIL_OF_SKY,
    EVENT_IMAGES_ATTACK,
    EVENT_DESPAWN_IMAGES,

    EVENT_ORB_ADD_VISUAL,
    EVENT_ORB_SET_AGGRESSIVE,
    EVENT_ORB_ARCANE_BARRAGE,

    EVENT_IMAGE_ASTRAL_RAIN_ABILITY,
    EVENT_IMAGE_ARCANE_BARRAGE_ABILITY,
    EVENT_IMAGE_VEIL_OF_SKY_ABILITY,

    EVENT_STARRY_SKY_ADD_VISUAL,
};

enum Actions
{
    ACTION_IMAGES_SET_AGGRESSIVE,
    ACTION_MIRROR_IMAGE_DIED,
    ACTION_IMAGES_SET_PASSIVE,
    ACTION_IMAGES_DESPAWN
};

class boss_isiset : public CreatureScript
{
public:
    boss_isiset() : CreatureScript("boss_isiset") { }

    struct boss_isisetAI : public BossAI
    {
        boss_isisetAI(Creature* creature) : BossAI(creature, DATA_ISISET) { }

        void Reset() override
        {
            _Reset();

            me->SetReactState(REACT_AGGRESSIVE);
            _transitionPhase = false;
            instance->SetData(DATA_ISISET_PHASE, 1);
            instance->SetData(DATA_ISISET_ASTRAL_RAIN_ALIVE, 1);
            instance->SetData(DATA_ISISET_CELESTIAL_CALL_ALIVE, 1);
            instance->SetData(DATA_ISISET_VEIL_OF_SKY_ALIVE, 1);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);
            if (IsHeroic())
                DoCastSelf(SPELL_CALL_OF_SKY);
            RescheduleEvents();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, 0);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (_transitionPhase)
                return;

            // Second transition
            if (instance->GetData(DATA_ISISET_PHASE) == 2 && me->HealthBelowPctDamaged(33, damage))
                MirrorImage();

            // First transition
            if (instance->GetData(DATA_ISISET_PHASE) == 1 && me->HealthBelowPctDamaged(66, damage))
                MirrorImage();
        }

        void DoAction(int32 action) override
        {
            // We only accept action from the first dying image
            if (_mirrorImageDied || action != ACTION_MIRROR_IMAGE_DIED)
                return;

            _mirrorImageDied = true;
            
            // Handle despawning
            DummyEntryCheckPredicate pred;
            summons.DoAction(ACTION_IMAGES_SET_PASSIVE, pred);
            events.ScheduleEvent(EVENT_DESPAWN_IMAGES, Seconds(2));
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_PLAYER_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            //instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, ?me?, 1); //from sniff, not sure what it does
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me, 0);
            _JustDied();
            Talk(SAY_DEATH);
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
                    case EVENT_ASTRAL_RAIN:
                        DoCastSelf(SPELL_ASTRAL_RAIN_CONTROLLER);
                        events.Repeat(Seconds(15), Seconds(19));
                        break;
                    case EVENT_ASTRAL_FAMILIAR:
                        DoCastSelf(SPELL_ASTRAL_FAMILIAR_CONTROLLER);
                        events.Repeat(Seconds(26), Seconds(30));
                        break;
                    case EVENT_VEIL_OF_SKY:
                        DoCastSelf(SPELL_MANA_SHIELD_CONTROLLER);
                        events.Repeat(Seconds(20), Seconds(25));
                        break;
                    case EVENT_SUPERNOVA:
                        DoCastSelf(SPELL_SUPERNOVA);
                        Talk(SAY_SUPERNOVA);
                        Talk(SAY_SUPERNOVA_WARNING);
                        events.Repeat(Seconds(45), Seconds(50));
                        break;
                    case EVENT_IMAGES_ATTACK:
                    {
                        DummyEntryCheckPredicate pred;
                        summons.DoAction(ACTION_IMAGES_SET_AGGRESSIVE, pred);
                        break;
                    }
                    case EVENT_DESPAWN_IMAGES:
                    {
                        DummyEntryCheckPredicate pred;
                        summons.DoAction(ACTION_IMAGES_DESPAWN, pred);
                        instance->SetData(DATA_ISISET_PHASE, instance->GetData(DATA_ISISET_PHASE) + 1);
                        _transitionPhase = false;
                        me->RemoveAurasDueToSpell(SPELL_ASTRAL_SHIFT);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 1);
                        RescheduleEvents();
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

    private:
        void RescheduleEvents()
        {
            events.Reset();
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE))
                events.ScheduleEvent(EVENT_ASTRAL_RAIN, Seconds(4), Seconds(6));
            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE))
                events.ScheduleEvent(EVENT_ASTRAL_FAMILIAR, Seconds(7));
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE))
                events.ScheduleEvent(EVENT_VEIL_OF_SKY, Seconds(8), Seconds(10));
            events.ScheduleEvent(EVENT_SUPERNOVA, Seconds(12), Seconds(17));
        }

        // Mirror Image transition phase
        void MirrorImage()
        {
            _transitionPhase = true;

            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 0);
            _mirrorImageDied = false;

            DoCastSelf(SPELL_ASTRAL_SHIFT);
            DoCastSelf(SPELL_ASTRAL_SHIFT_EXPLOSION);
            DoCastSelf(SPELL_MIRROR_IMAGE_STARRY_SKY_SPAWNER);
            DoCastSelf(SPELL_MIRROR_IMAGE_SPAWNER);

            events.ScheduleEvent(EVENT_IMAGES_ATTACK, Seconds(2));
        }

        bool _transitionPhase;
        bool _mirrorImageDied;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<boss_isisetAI>(creature);
    }
};

// 39795 - Celestial Familiar
class npc_celestial_familiar : public CreatureScript
{
public:
    npc_celestial_familiar() : CreatureScript("npc_celestial_familiar") { }

    struct npc_celestial_familiarAI : public ScriptedAI
    {
        npc_celestial_familiarAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetInCombatWithZone();
            events.Reset();
            events.ScheduleEvent(EVENT_ORB_ADD_VISUAL, Seconds(1));
            events.ScheduleEvent(EVENT_ORB_SET_AGGRESSIVE, Seconds(2));
            events.ScheduleEvent(EVENT_ORB_ARCANE_BARRAGE, Seconds(4), Seconds(6));
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
                    case EVENT_ORB_ADD_VISUAL:
                        DoCastSelf(SPELL_ORB_VISUAL);
                        break;
                    case EVENT_ORB_SET_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_ORB_ARCANE_BARRAGE:
                        DoCastSelf(SPELL_ARCANE_BARRAGE);
                        events.Repeat(Seconds(6), Seconds(7));
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_celestial_familiarAI>(creature);
    }
};

// 39720 - Astral Rain
// 39721 - Celestial Call
// 39722 - Veil of Sky
class npc_isiset_mirror_image : public CreatureScript
{
public:
    npc_isiset_mirror_image() : CreatureScript("npc_isiset_mirror_image") { }

    struct npc_isiset_mirror_imageAI : public ScriptedAI
    {
        npc_isiset_mirror_imageAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void Reset() override
        {            
            me->SetReactState(REACT_PASSIVE);
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

            switch (me->GetEntry()) {
                case NPC_ASTRAL_RAIN:
                    _events.ScheduleEvent(EVENT_IMAGE_ASTRAL_RAIN_ABILITY, Seconds(3), Seconds(5));
                    DoCastSelf(SPELL_STARFALL_STATE_VISUAL);
                    break;
                case NPC_CELESTIAL_CALL:
                    _events.ScheduleEvent(EVENT_IMAGE_ARCANE_BARRAGE_ABILITY, Seconds(6));
                    DoCastSelf(SPELL_ADDS_STATE_VISUAL);
                    break;
                case NPC_VEIL_OF_SKY:
                    _events.ScheduleEvent(EVENT_IMAGE_VEIL_OF_SKY_ABILITY, Seconds(8), Seconds(9));
                    //DoCastSelf(SPELL_MANA_SHIELD_STATE_VISUAL); // Disabled in sniffs/on retail, too shiny. 
                    break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            // Because only one image explodes, others become passive
            if (me->GetReactState() != REACT_AGGRESSIVE || me->GetHealth() > damage)
                return;

            me->SetReactState(REACT_PASSIVE);
            damage = me->GetHealth() - 1;
            DoCastSelf(SPELL_IMAGE_EXPLOSION);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_IMAGES_SET_AGGRESSIVE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetInCombatWithZone();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        AttackStart(target);
                    break;
                case ACTION_IMAGES_SET_PASSIVE:
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    break;
                case ACTION_IMAGES_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_IMAGE_ASTRAL_RAIN_ABILITY:
                        DoCastSelf(SPELL_ASTRAL_RAIN_CONTROLLER);
                        _events.Repeat(Seconds(16), Seconds(19));
                        break;
                    case EVENT_IMAGE_ARCANE_BARRAGE_ABILITY:
                        DoCastSelf(SPELL_ARCANE_BARRAGE);
                        _events.Repeat(Seconds(8), Seconds(10));
                        break;
                    case EVENT_IMAGE_VEIL_OF_SKY_ABILITY:
                        DoCastSelf(SPELL_VEIL_OF_SKY_1); // Veil of Sky npc does not cast controller spell!
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_isiset_mirror_imageAI>(creature);
    }
};

// 74381 - Astral Rain Controller Spell 
class spell_isiset_astral_rain_controller : public SpellScriptLoader
{
public:
    spell_isiset_astral_rain_controller() : SpellScriptLoader("spell_isiset_astral_rain_controller") { }

    class spell_isiset_astral_rain_controller_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({
                SPELL_ASTRAL_RAIN_1,
                SPELL_ASTRAL_RAIN_2,
                SPELL_ASTRAL_RAIN_3
            });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || !instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE))
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_1, true);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_2, true);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_3, true);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_astral_rain_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_astral_rain_controller_SpellScript();
    }
};

// 74382 - Mana Shield Controller Spell
class spell_isiset_mana_shield_controller : public SpellScriptLoader
{
public:
    spell_isiset_mana_shield_controller() : SpellScriptLoader("spell_isiset_mana_shield_controller") { }

    class spell_isiset_mana_shield_controller_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({
                SPELL_VEIL_OF_SKY_1,
                SPELL_VEIL_OF_SKY_2,
                SPELL_VEIL_OF_SKY_3
            });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || !instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE))
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_1);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_2);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_3);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_mana_shield_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mana_shield_controller_SpellScript();
    }
};

// 74383 - Astral Familiar Controller Spell 
class spell_isiset_astral_familiar_controller : public SpellScriptLoader
{
public:
    spell_isiset_astral_familiar_controller() : SpellScriptLoader("spell_isiset_astral_familiar_controller") { }

    class spell_isiset_astral_familiar_controller_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({
                SPELL_CELESTIAL_CALL_1,
                SPELL_CELESTIAL_CALL_2,
                SPELL_CELESTIAL_CALL_3
            });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || !instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE))
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_1, true);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_2, true);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_3, true);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_astral_familiar_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_astral_familiar_controller_SpellScript();
    }
};

// 74133, 74372, 74373 - Veil of Sky (mana shield)
class spell_isiset_veil_of_sky : public SpellScriptLoader
{
public:
    spell_isiset_veil_of_sky() : SpellScriptLoader("spell_isiset_veil_of_sky") { }

    class spell_isiset_veil_of_sky_AuraScript : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_VEIL_OF_SKY_DAMAGE });
        }

        bool Load() override
        {
            reflectPct = GetSpellInfo()->Effects[EFFECT_1].BasePoints;
            return true;
        }

        void Trigger(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (dmgInfo.GetDamageType() != SPELL_DIRECT_DAMAGE)
                return;

            int32 damage = CalculatePct(absorbAmount, reflectPct);
            GetCaster()->CastSpell(dmgInfo.GetAttacker(), SPELL_VEIL_OF_SKY_DAMAGE, CastSpellExtraArgs(true).AddSpellBP0(damage));
        }

        void Register() override
        {
            AfterEffectManaShield.Register(&spell_isiset_veil_of_sky_AuraScript::Trigger, EFFECT_0);
        }

    private:
        int32 reflectPct;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_isiset_veil_of_sky_AuraScript();
    }
};

// 74137 - Supernova (disorient + triggers 76670) (are pets also affected?)
// 76670 - Supernova (damage)
class spell_isiset_supernova_filter : public SpellScriptLoader
{
public:
    spell_isiset_supernova_filter() : SpellScriptLoader("spell_isiset_supernova_filter") { }

    class spell_isiset_supernova_filter_SpellScript : public SpellScript
    {
        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            targets.remove_if([caster](WorldObject* object) { return !object->ToUnit() || !object->ToUnit()->IsCharmedOwnedByPlayerOrPlayer() || !object->isInFront(caster, 2.5f); });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect.Register(&spell_isiset_supernova_filter_SpellScript::FilterTargets, m_scriptSpellId == SPELL_SUPERNOVA_EFFECT ? EFFECT_1 : EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_supernova_filter_SpellScript();
    }
};

// 69941 - Mirror Image
class spell_isiset_mirror_image_starry_sky_spawner : public SpellScriptLoader
{
public:
    spell_isiset_mirror_image_starry_sky_spawner() : SpellScriptLoader("spell_isiset_mirror_image_starry_sky_spawner") { }

    class spell_isiset_mirror_image_starry_sky_spawner_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MIRROR_IMAGE_STARRY_SKY_N, SPELL_MIRROR_IMAGE_STARRY_SKY_E, SPELL_MIRROR_IMAGE_STARRY_SKY_W });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_N, true);
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_E, true);
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_W, true);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_mirror_image_starry_sky_spawner_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mirror_image_starry_sky_spawner_SpellScript();
    }
};

// 74264 - Mirror Image
class spell_isiset_mirror_image_spawner : public SpellScriptLoader
{
public:
    spell_isiset_mirror_image_spawner() : SpellScriptLoader("spell_isiset_mirror_image_spawner") { }

    class spell_isiset_mirror_image_spawner_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MIRROR_IMAGE_N, SPELL_MIRROR_IMAGE_E, SPELL_MIRROR_IMAGE_W });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* const instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_N, true);
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_E, true);
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE))
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_W, true);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_mirror_image_spawner_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mirror_image_spawner_SpellScript();
    }
};

// 74301 - Image Explosion
class spell_isiset_image_explosion : public SpellScriptLoader
{
public:
    spell_isiset_image_explosion() : SpellScriptLoader("spell_isiset_image_explosion") { }

    class spell_isiset_image_explosion_SpellScript : public SpellScript
    {
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* const instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            switch (GetCaster()->GetEntry())
            {
                case NPC_ASTRAL_RAIN:
                    instance->SetData(DATA_ISISET_ASTRAL_RAIN_ALIVE, 0);
                    break;
                case NPC_CELESTIAL_CALL:
                    instance->SetData(DATA_ISISET_CELESTIAL_CALL_ALIVE, 0);
                    break;
                case NPC_VEIL_OF_SKY:
                    instance->SetData(DATA_ISISET_VEIL_OF_SKY_ALIVE, 0);
                    break;
            }

            if (Creature* Isiset = instance->GetCreature(DATA_ISISET))
                Isiset->AI()->DoAction(ACTION_MIRROR_IMAGE_DIED);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_image_explosion_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_image_explosion_SpellScript();
    }
};

// 90755 Call of Sky (heroic only)
class spell_isiset_call_of_sky : public SpellScriptLoader
{
public:
    spell_isiset_call_of_sky() : SpellScriptLoader("spell_isiset_call_of_sky") { }

    class spell_isiset_call_of_sky_SpellScript : public SpellScript
    {
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* Isiset = instance->GetCreature(DATA_ISISET))
                    Isiset->SummonCreature(NPC_ISISET_SPATIAL_FLUX, GetHitDest()->GetPositionX(), GetHitDest()->GetPositionY(), GetHitDest()->GetPositionZ(), 2.775074f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_isiset_call_of_sky_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_call_of_sky_SpellScript();
    }
};

void AddSC_boss_isiset()
{
    new boss_isiset();
    new npc_celestial_familiar();
    new npc_isiset_mirror_image();
    new spell_isiset_astral_rain_controller();
    new spell_isiset_mana_shield_controller();
    new spell_isiset_astral_familiar_controller();
    new spell_isiset_veil_of_sky();
    new spell_isiset_supernova_filter();
    new spell_isiset_mirror_image_starry_sky_spawner();
    new spell_isiset_mirror_image_spawner();
    new spell_isiset_image_explosion();
    new spell_isiset_call_of_sky();
}
