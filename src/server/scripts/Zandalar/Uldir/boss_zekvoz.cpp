/*
 * Copyright 2021 BfaCore
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "uldir.h"

enum ZekvozSpells
{
    //Phase 1
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_EYE_BEAM_TRANSFORM = 264738, //well, this is used for bunny controller, just visual
    SPELL_TITAN_SPARK_TARGETS_SELECTOR = 266470,
    SPELL_TITAN_SPARK = 267019,
    SPELL_TITAN_SPARK_SELECTOR = 265061,
    SPELL_TITAN_SPARK_DAMAGE = 264954,
    SPELL_TITAN_SPARK_COSMETIC = 264950,
    SPELL_MIGHT_OF_THE_VOID = 267312,
    SPELL_VOID_LASH_DMG = 265264,
    SPELL_VOID_LASH_TARGET_SELECTOR = 265231,
    SPELL_VOID_LASH_TARGET_SELECTOR_VISION_RANGE = 265268,
    SPELL_VOID_LASH_TARGET_SELECTOR_CONE = 267963,
    SPELL_SHATTER = 265237,
    SPELL_SHATTER_DUMMY = 265248,
    SPELL_EYE_BEAM = 264382,
    SPELL_EYE_BEAM_TARGET_SELECTOR = 264383,
    SPELL_SPAWN_SILITHID_WARRIOR = 266913,
    SPELL_DESPAWN_SILITHID_WARRIOR = 267249,
    SPELL_SKITTERING_SWARM = 275772,
    SPELL_JAGGED_MANDIBLE = 264209,
    SPELL_JAGGED_MANDIBLE_DMG = 261976,
    SPELL_SURGING_DARKNESS_DMG_INT = 265451,
    SPELL_SURGING_DARKNESS_DMG_MID = 265452,
    SPELL_SURGING_DARKNESS_DMG_EXT = 265454,
    SPELL_SURGING_DARKNESS_DMG_EXT_N = 275084,
    SPELL_SURGING_DARKNESS_CIRCLE_INT = 265558,
    SPELL_SURGING_DARKNESS_CIRCLE_MID = 265559,
    SPELL_SURGING_DARKNESS_CIRCLE_EXT_N = 275925,
    SPELL_SURGING_DARKNESS_CIRCLE_INT_N = 271030,//same size
    SPELL_SURGING_DARKNESS_CIRCLE_MID_N = 271032,
    SPELL_SURGING_DARKNESS_CIRCLE_EXT_H = 271035,
    SPELL_SURGING_DARKNESS_ENERGIZE = 267629,
    SPELL_SURGING_DARKNESS_ENERGY_BAR = 267625,
    SPELL_SURGING_DARKNESS_DMG = 267350,
    //Phase 2
    SPELL_ROILING_DECEIT_TARGET_SELECTOR = 265437,
    SPELL_ROILING_DECEIT = 265358,
    SPELL_ROILING_DECEIT_AT = 265361,
    SPELL_ROILING_DECEIT_AURA = 265360,
    SPELL_ROILING_DECEIT_SUMMON = 265369,
    SPELL_ROILING_DECEIT_SUMMON_GUARD = 265363,
    SPELL_ROILING_DECEIT_DUMMY = 265402,
    SPELL_ROILING_DECEIT_TRANSFORM_SELECTOR = 265434,
    SPELL_ROILING_DECEIT_TRANSFORM = 265435,
    SPELL_ROILING_DECEIT_AURA_DAMAGE = 281473,
    SPELL_ENERGY_FILL = 265249,
    SPELL_JAGGED_MANDIBLE_AURA = 264210,
    SPELL_JAGGED_MANDIBLE_PROC_TRIGGER = 264209,
    SPELL_SHADOW_NOVA_DAMAGE = 265374,
    SPELL_VOID_BOLT = 267180,
    SPELL_SHADOWBIND_VISUAL = 270954,
    SPELL_VOID_WALL = 270589,
    //Phase 3
    SPELL_OVERLOAD = 61878,
    SPELL_OF_CORRUPTION_CREATE_AT = 265672,
    SPELL_ORB_OF_CORRUPTION_IMPACT_VISUAL = 269113,
    SPELL_ORB_OF_CORRUPTION_DUMMY = 267334,
    SPELL_ORB_OF_CORRUPTION = 267239,
    SPELL_ORB_OF_CORRUPTION_TARGET_SELECTOR = 267234,
    SPELL_CORRUPTORS_PATH_MAIN = 265662,
    SPELL_CORRUPTORS_PATH_SCREEN_EFFECT = 272023,
    SPELL_WILL_OF_THE_CORRUPTOR = 265646,
    SPELL_WILL_OF_THE_CORRUPTOR_BEAM = 270717,
    SPELL_PSIONIC_BLAST = 270620,
};

enum ZekvozEvents
{
    EVENT_TITAN_SPARK = 1,
    EVENT_MIGHT_OF_THE_VOID,
    EVENT_SURGING_DARKNESS,
    EVENT_EYE_BEAM,
    EVENT_SUMMON_SILITHID_WARRIOR,
    EVENT_ROILING_DECEIT,    
    EVENT_SURGING_DARKNESS_INT,
    EVENT_SURGING_DARKNESS_MID,
    EVENT_SURGING_DARKNESS_EXT,
    EVENT_SURGING_DARKNES_DMG_INT,
    EVENT_SURGING_DARKNES_DMG_MID,
    EVENT_SURGING_DARKNES_DMG_EXT,
    EVENT_NERUBIANS,
    EVENT_ORB_OF_CORRUPTION,
    EVENT_VOID_BOLT,
    EVENT_WILL_OF_THE_CORRUPTOR,
    EVENT_VOID_WAIL,
    EVENT_CORRUPTORS_PACT,
    EVENT_PSIONIC_BLAST,
};

enum ZekvozTexts
{
    SAY_AGGRO = 0,
    SAY_AGGRO_WHISPER = 7,
    SAY_SURGING_DARKNESS = 1,
    SAY_SURGING_DARKNESS_WHISPER = 2,
    SAY_WIPE_WHISPER = 3,
    SAY_DEATH = 4,
    SAY_DEATH_WHISPER = 8,
    SAY_WIPE = 5,
    SAY_KILL = 6,
};

enum Misc
{
    ACHIEVEMENT_MYTHIC_ZEKVOZ = 12529,
};

//134445
struct boss_zekvoz : public BossAI
{
    boss_zekvoz(Creature* creature) : BossAI(creature, DATA_ZEKVOZ) { }

private:
    uint8 phase;
    bool sixtyfivePercent;
    bool thirtyPercent;
    uint8 titansparkcounter;

    void Reset() override
    {
        BossAI::Reset();
        this->phase = 0;
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);        
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);        
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_WIPE);
        Talk(SAY_WIPE_WHISPER);
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        CleanEncounter(instance, me);
        me->RemoveAllAreaTriggers();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        Talk(SAY_AGGRO_WHISPER);
        sixtyfivePercent = false;
        thirtyPercent = false;
        this->phase = 1;       
        me->AddAura(SPELL_SURGING_DARKNESS_ENERGY_BAR);
        me->AddAura(SPELL_SURGING_DARKNESS_ENERGIZE);
        events.ScheduleEvent(EVENT_MIGHT_OF_THE_VOID, 6s);
        events.ScheduleEvent(EVENT_TITAN_SPARK, 9s);
        events.ScheduleEvent(EVENT_SURGING_DARKNESS, 25s);
        events.ScheduleEvent(EVENT_EYE_BEAM, 51s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_SUMMON_SILITHID_WARRIOR, 62s);
        DoCast(SPELL_PERIODIC_ENERGY_GAIN);
        me->SetPower(POWER_ENERGY, 75);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            if (roll_chance_f(15))
                Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(65) && !sixtyfivePercent)
        {
            sixtyfivePercent = true;
            events.Reset();
            this->phase = 2;
            events.CancelEvent(EVENT_EYE_BEAM);
            events.CancelEvent(EVENT_SUMMON_SILITHID_WARRIOR);
            events.ScheduleEvent(EVENT_ROILING_DECEIT, 1s);
            events.ScheduleEvent(EVENT_MIGHT_OF_THE_VOID, 6s);
            events.ScheduleEvent(EVENT_TITAN_SPARK, 9s);
            events.ScheduleEvent(EVENT_SURGING_DARKNESS, 25s);
        }
        if (me->HealthBelowPct(30) && !thirtyPercent)
        {
            thirtyPercent = true;
            events.Reset();
            this->phase = 3;
            events.CancelEvent(EVENT_NERUBIANS);
            events.ScheduleEvent(EVENT_ORB_OF_CORRUPTION, 1s);
            events.ScheduleEvent(EVENT_PSIONIC_BLAST, 3s);
            events.ScheduleEvent(EVENT_MIGHT_OF_THE_VOID, 6s);
            events.ScheduleEvent(EVENT_TITAN_SPARK, 9s);
            events.ScheduleEvent(EVENT_SURGING_DARKNESS, 25s);
            events.ScheduleEvent(EVENT_EYE_BEAM, 51s);
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        Talk(SAY_DEATH);
        Talk(SAY_DEATH_WHISPER);
        _JustDied();
        if (IsMythic())
            instance->DoCompleteAchievement(ACHIEVEMENT_MYTHIC_ZEKVOZ);
        CleanEncounter(instance, me);
        me->RemoveAllAreaTriggers();
    }

    void CleanEncounter(InstanceScript* instance, Creature* zekvoz)
    {
        me->DespawnCreaturesInArea(NPC_SILITHID_WARRIOR, 125.0f);
        me->DespawnCreaturesInArea(NPC_NERUBIAN_VOIDWEAVER, 125.0f);
        me->DespawnCreaturesInArea(NPC_OMINOUS_CLOUD_STALKER, 125.0f);
        me->DespawnCreaturesInArea(NPC_ORB_OF_CORRUPTION, 125.0f);
        me->DespawnCreaturesInArea(NPC_ORB_OF_CORRUPTION_VISUAL_SOAK, 125.0f);
        me->DespawnCreaturesInArea(NPC_GUARDIAN_OF_YOGG_SARON, 125.0f);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SURGING_DARKNESS:
            {
                Talk(SAY_SURGING_DARKNESS);
                Talk(SAY_SURGING_DARKNESS_WHISPER, me->GetVictim());
                me->ModifyPower(POWER_ENERGY, -100);
                me->SummonCreature(NPC_SURGING_DARKNESS_BUNNY, me->GetPosition());
                events.Repeat(20s);
                break;
            }
            case EVENT_TITAN_SPARK:
            {
                if (Creature* titanBunny = me->FindNearestCreature(NPC_TITAN_SPARK, 150.0f, true))
                {
                    this->titansparkcounter = 0;
                    titanBunny->GetScheduler().Schedule(100ms, [this](TaskContext context)
                    {
                        UnitList u_li;
                        SelectTargetList(u_li, 10, SELECT_TARGET_RANDOM, 150.0f, true);
                        for (Unit* targets : u_li)
                        {
                            me->CastSpell(targets, SPELL_TITAN_SPARK_DAMAGE, true);
                            targets->CastSpell(nullptr, SPELL_TITAN_SPARK_COSMETIC, true);
                        }
                        titansparkcounter++;
                        if (this->titansparkcounter < 5)
                            context.Repeat(2s);
                    });
                }
                if (this->phase != 3)
                    events.Repeat(25s);
                else
                    events.Repeat(10s);
                break;
            }
            case EVENT_MIGHT_OF_THE_VOID:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 30.0f, true))
                {
                    DoCast(target, SPELL_MIGHT_OF_THE_VOID, false);
                    me->GetScheduler().Schedule(3500ms, [this, target](TaskContext context)
                    {
                        me->CastSpell(target, SPELL_VOID_LASH_DMG, true);
                        me->CastSpell(target, SPELL_SHATTER, true);
                    });
                }
                events.Repeat(45s);
                break;
            }
        }
        //Phase 1
        if (this->phase = 1)
        {
            switch (eventId)
            {
            case EVENT_EYE_BEAM:
            {
                if (Creature* yoggProjection = me->FindNearestCreature(NPC_PROJECTION_OF_CTHUN, 150.0f, true))
                    yoggProjection->AddAura(SPELL_EYE_BEAM_TRANSFORM);

                DoCast(SPELL_EYE_BEAM_TARGET_SELECTOR);
                events.Repeat(27s);
                break;
            }
            case EVENT_SUMMON_SILITHID_WARRIOR:
            {
                for (int i = 0; i < 7; i++)
                {
                    me->SummonCreature(NPC_SILITHID_WARRIOR, me->GetRandomNearPosition(15.0f));
                }
                events.Repeat(120s);
                break;
            }
        }
        //Phase 2
        if (this->phase = 2)
        {
            switch (eventId)
            {
            case EVENT_ROILING_DECEIT:
            {
                if (Creature* yoggProjection = me->FindNearestCreature(NPC_PROJECTION_OF_YOGG_SARON, 150.0f, true))
                    yoggProjection->AddAura(SPELL_ROILING_DECEIT_TRANSFORM);

                UnitList u_li;
                SelectTargetList(u_li, 3, SELECT_TARGET_RANDOM, 150.0f, true);
                for (Unit* targets : u_li)
                {
                    me->CastSpell(targets, SPELL_ROILING_DECEIT_AURA, true);
                }
                events.Repeat(20s, 25s);
                break;
            }
            case EVENT_NERUBIANS:
            {
                for (int i = 0; i < 3; i++)
                {
                    me->SummonCreature(NPC_NERUBIAN_VOIDWEAVER, me->GetRandomNearPosition(20.0f));
                }
                events.Repeat(30s, 35s);
                break;
            }

            }
        }
        //Phase 3
        if (this->phase = 3)
        {
            switch (eventId)
            {
            case EVENT_ORB_OF_CORRUPTION:
            {
                uint32 OrbOfCorruptionSpawns = urand(1, 4);
                switch (OrbOfCorruptionSpawns)
                {
                case 1:
                    me->SummonCreature(NPC_ORB_OF_CORRUPTION, 237.093f, 157.093f, 737.432f, 1.46f, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case 2:
                    me->SummonCreature(NPC_ORB_OF_CORRUPTION, 267.422f, 170.200f, 725.991f, 2.25f, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case 3:
                    me->SummonCreature(NPC_ORB_OF_CORRUPTION, 265.425f, 186.500f, 735.251f, 4.30f, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case 4:
                    me->SummonCreature(NPC_ORB_OF_CORRUPTION, 231.283f, 187.813f, 733.033f, 0.24f, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                }              
                events.Repeat(35s);
                break;
            }
            case EVENT_PSIONIC_BLAST:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    me->CastSpell(target, SPELL_PSIONIC_BLAST, false);
                events.Repeat(40s);
                break;
            }
            }
        }
    }
    }
};

enum Silithid
{
    EVENT_JAGGED_MANDIBLE = 1,
};

//134503
struct npc_silithid_warrior : public ScriptedAI
{
    npc_silithid_warrior(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddAura(SPELL_JAGGED_MANDIBLE_PROC_TRIGGER);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_JAGGED_MANDIBLE, 2s);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AI()->DoZoneInCombat(nullptr);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_JAGGED_MANDIBLE:
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 10.0f, true))
            {
                me->AddAura(SPELL_JAGGED_MANDIBLE_AURA, target);
            }
            events.Repeat(2s);
            break;
        }
    }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        me->CastSpell(me, SPELL_SKITTERING_SWARM);
    }
};

//135183
struct npc_surging_darkness : public ScriptedAI
{
    npc_surging_darkness(Creature* creature) : ScriptedAI(creature) { }

private:
    uint8 count;

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void InitializeAI() override
    {
        this->count = 0;
        ScriptedAI::InitializeAI();
        events.ScheduleEvent(RAND(EVENT_SURGING_DARKNESS_INT, EVENT_SURGING_DARKNESS_MID, EVENT_SURGING_DARKNESS_EXT), 1s);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitState(UNIT_STATE_ROOT);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SURGING_DARKNESS_INT:
            {
                if (this->count == 3)
                {
                    me->DespawnOrUnsummon();
                    break;
                }
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_EXT_N);
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_INT);
                events.ScheduleEvent(EVENT_SURGING_DARKNES_DMG_INT, 7s);
                events.ScheduleEvent(RAND(EVENT_SURGING_DARKNESS_MID, EVENT_SURGING_DARKNESS_EXT), 8s);
                count++;
                break;
            }
            case EVENT_SURGING_DARKNESS_MID:
            {
                if (this->count == 3)
                {
                    me->DespawnOrUnsummon();
                    break;
                }
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_MID_N);
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_INT);
                events.ScheduleEvent(EVENT_SURGING_DARKNES_DMG_MID, 7s);
                events.ScheduleEvent(RAND(EVENT_SURGING_DARKNESS_INT, EVENT_SURGING_DARKNESS_EXT), 8s);
                count++;
                break;
            }
            case EVENT_SURGING_DARKNESS_EXT:
            {
                if (this->count == 3)
                {
                    me->DespawnOrUnsummon();
                    break;
                }
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_EXT_N);
                DoCast(SPELL_SURGING_DARKNESS_CIRCLE_MID_N);
                events.ScheduleEvent(EVENT_SURGING_DARKNES_DMG_EXT, 7s);
                events.ScheduleEvent(RAND(EVENT_SURGING_DARKNESS_MID, EVENT_SURGING_DARKNESS_INT), 8s);
                count++;
                break;
            }
            case EVENT_SURGING_DARKNES_DMG_EXT:
            {
                DoCast(SPELL_SURGING_DARKNESS_DMG_EXT_N);
                DoCast(SPELL_SURGING_DARKNESS_DMG_MID);
                break;
            }
            case EVENT_SURGING_DARKNES_DMG_INT:
            {
                DoCast(SPELL_SURGING_DARKNESS_DMG_EXT_N);
                DoCast(SPELL_SURGING_DARKNESS_DMG_INT);
                break;
            }
            case EVENT_SURGING_DARKNES_DMG_MID:
            {
                DoCast(SPELL_SURGING_DARKNESS_DMG_INT);
                DoCast(SPELL_SURGING_DARKNESS_DMG_MID);
                break;
            }
            }
        }
    }    
};

//264383
class spell_eye_beam_selector : public SpellScript
{
    PrepareSpellScript(spell_eye_beam_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (Unit* caster = GetCaster())
                if (Unit* bunny = caster->FindNearestCreature(NPC_EYE_BEAM, 300.0f))
                    bunny->CastSpell(target, SPELL_EYE_BEAM);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eye_beam_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eye_beam_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//265231
class spell_void_lash_selector : public SpellScript
{
    PrepareSpellScript(spell_void_lash_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
            if (Unit* caster = GetCaster())
                caster->CastSpell(hitUnit, SPELL_VOID_LASH_DMG);
    }

    void HandleShatter()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_SHATTER_DUMMY);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_void_lash_selector::DoEffectHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_void_lash_selector::HandleShatter);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_void_lash_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_void_second_lash_selector : public SpellScript
{
    PrepareSpellScript(spell_void_second_lash_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
            GetCaster()->CastSpell(hitUnit, SPELL_VOID_LASH_DMG);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_void_second_lash_selector::DoEffectHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_void_second_lash_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//265237
class spell_shatter : public SpellScript
{
    PrepareSpellScript(spell_shatter);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster->GetVictim(), SPELL_SHATTER);
    }

    void HandleVoidLash()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_VOID_LASH_TARGET_SELECTOR_VISION_RANGE);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_shatter::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_shatter::HandleVoidLash);
    }
};

//267312
class spell_might_of_the_void : public SpellScript
{
    PrepareSpellScript(spell_might_of_the_void);

    void HandleDummy()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_VOID_LASH_TARGET_SELECTOR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_might_of_the_void::HandleDummy);
    }
};

//265437
class spell_roiling_deceit_selector : public SpellScript
{
    PrepareSpellScript(spell_roiling_deceit_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                caster->AddAura(SPELL_ROILING_DECEIT_AURA, target);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_roiling_deceit_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_roiling_deceit_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//265360
class spell_roiling_deceit_aura : public AuraScript
{
    PrepareAuraScript(spell_roiling_deceit_aura);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (Unit* target = GetTarget())
        {
            Unit* caster = GetCaster();
            GetCaster()->CastSpell(target, SPELL_ROILING_DECEIT_AURA_DAMAGE, true);
        }
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_ROILING_DECEIT_SUMMON);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_roiling_deceit_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        OnEffectRemove += AuraEffectRemoveFn(spell_roiling_deceit_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//265402
class spell_roiling_deceit_dummy : public SpellScript
{
    PrepareSpellScript(spell_roiling_deceit_dummy);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_ROILING_DECEIT_TARGET_SELECTOR);
    }

    void HandleCosmetics()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_ROILING_DECEIT_TRANSFORM_SELECTOR);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_roiling_deceit_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_roiling_deceit_dummy::HandleCosmetics);
    }
};

//?
struct areatrigger_ominous_cloud : AreaTriggerAI
{
    areatrigger_ominous_cloud(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit->IsPlayer())
        {
            if (Unit* cloudStalker = unit->FindNearestCreature(NPC_OMINOUS_CLOUD_STALKER, 20.0f, true))
            {
                cloudStalker->CastSpell(cloudStalker, SPELL_ROILING_DECEIT_SUMMON_GUARD);
                cloudStalker->KillSelf();
            }
        }
    }
};

//264954
class spell_titan_spark_aura : public AuraScript
{
    PrepareAuraScript(spell_titan_spark_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetTarget())
                caster->CastSpell(target, SPELL_TITAN_SPARK_COSMETIC);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_titan_spark_aura::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//265061
class spell_titan_spark_selector : public SpellScript
{
    PrepareSpellScript(spell_titan_spark_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_TITAN_SPARK_DAMAGE);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer() && obj->ToUnit()->HasAura(SPELL_TITAN_SPARK_DAMAGE); });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_titan_spark_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_titan_spark_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//135824
struct npc_nerubian_voidweaver : public ScriptedAI
{
    npc_nerubian_voidweaver(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();       
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AI()->DoZoneInCombat(nullptr);

        if (IsHeroic() || IsMythic())
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(SPELL_SHADOWBIND_VISUAL);
        }

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void EnterCombat(Unit* /*killer*/) override
    {
        events.ScheduleEvent(EVENT_VOID_BOLT, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_VOID_BOLT:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_VOID_BOLT, false);
            }
            events.Repeat(6s);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

//159150
struct npc_orb_of_corruption : public ScriptedAI
{
    npc_orb_of_corruption(Creature* creature) : ScriptedAI(creature) 
    { 
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);        
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC));
    }

private:
    TaskScheduler scheduler;
    float x;
    float y;
    float z;
    bool despawn;

    void Reset() override
    {
        me->AI()->DoZoneInCombat(nullptr);
        despawn = false;
        me->SummonCreature(NPC_ORB_OF_CORRUPTION_VISUAL_SOAK, me->GetPosition());     
        me->CanFly();
        me->SetFlying(true);
        me->SetHover(true);
        me->SetWalk(true);
        me->SetHoverHeight(10.0f);
        me->GetMotionMaster()->Clear();
        me->GetPosition(x, y, z);
        z = me->GetMap()->GetHeight(me->GetPhaseShift(), x, y, z, true, 100.0f);
        me->SetSpeedRate(MOVE_RUN, 1.0f);
        me->SetSpeedRate(MOVE_WALK, 1.0f);
        me->SetFall(true);
        me->GetMotionMaster()->MovePoint(1, x, y, z, false);
        me->GetScheduler().Schedule(17s, [this](TaskContext context)
        {            
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 25.0f, true))
            {
                if (Creature* zekvoz = me->FindNearestCreature(NPC_ZEKVOZ, 150.0f, true))
                {
                    zekvoz->CastSpell(target, SPELL_CORRUPTORS_PATH_MAIN, true);
                    zekvoz->AddAura(SPELL_CORRUPTORS_PATH_SCREEN_EFFECT, target);
                    despawn = true;
                    if (despawn)
                        me->DespawnOrUnsummon(5s);
                }
            }
            else
            {
                me->CastSpell(nullptr, SPELL_ORB_OF_CORRUPTION, true);
                AddTimedDelayedOperation(1000, [this]() -> void {               
                //TODO: damage
                });
                if (!despawn)
                    context.Repeat(5s);
            }
        });
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_ORB_OF_CORRUPTION_VISUAL_SOAK:
            me->CastSpell(summon->GetPosition(), SPELL_ORB_OF_CORRUPTION_IMPACT_VISUAL, true);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }
};

//134726
struct npc_projection_of_cthun : public ScriptedAI
{
    npc_projection_of_cthun(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }
};

//135129
struct npc_projection_of_yogg_saron : public ScriptedAI
{
    npc_projection_of_yogg_saron(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }
};

//135079
struct npc_ominous_cloud_stalker : public ScriptedAI
{
    npc_ominous_cloud_stalker(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        Timer = 0;
    }

    void Reset() override
    {
        Initialize();
        summon_guard = false;
        me->CastSpell(nullptr, 24777, true);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) <= 3.0f && !summon_guard)
        {
            summon_guard = true;
            if (summon_guard)
            {
                me->CastSpell(me, SPELL_ROILING_DECEIT_SUMMON_GUARD);
                me->DespawnOrUnsummon(3s);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (!Timer)
        {        
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                Timer = urand(15000, 30000);
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveChase(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
            }
            else
            {
                Timer = 2500;
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveRandom(25.0f);
            }
            me->SetWalk(true);
            me->SetSpeedRate(MOVE_WALK, 0.75f);
        }
        else
        Timer -= diff;
    }

private:
    uint32 Timer;
    bool summon_guard;
};

//265662
class aura_corruptors_path : public AuraScript
{
    PrepareAuraScript(aura_corruptors_path);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Creature* zekvoz = caster->FindNearestCreature(NPC_ZEKVOZ, 150.0f, true))
            {
                caster->CastSpell(GetTarget(), SPELL_VOID_WALL, true);
                caster->CastSpell(GetTarget(), SPELL_WILL_OF_THE_CORRUPTOR, true);
                caster->CastSpell(GetTarget(), SPELL_WILL_OF_THE_CORRUPTOR_BEAM, true);
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_corruptors_path::OnRemove, EFFECT_10, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//281473
class spell_roiling_deceit_damage : public SpellScript
{
    PrepareSpellScript(spell_roiling_deceit_damage);

    void HandleOnHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (GetHitUnit()->GetMap()->IsMythic())
        {
            float damageMythic = 44009;
            SetHitDamage(damageMythic);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_roiling_deceit_damage::HandleOnHit);
    }
};

void AddSC_boss_zekvoz()
{
    RegisterCreatureAI(boss_zekvoz);
    RegisterCreatureAI(npc_silithid_warrior);
    RegisterCreatureAI(npc_surging_darkness);
    RegisterSpellScript(spell_eye_beam_selector);
    RegisterSpellScript(spell_void_lash_selector);
    RegisterSpellScript(spell_void_second_lash_selector);
    RegisterSpellScript(spell_shatter);
    RegisterSpellScript(spell_might_of_the_void);
    RegisterSpellScript(spell_roiling_deceit_selector);
    RegisterSpellScript(spell_roiling_deceit_dummy);
    RegisterSpellScript(spell_titan_spark_selector);
    RegisterAuraScript(spell_titan_spark_aura);
    RegisterAuraScript(spell_roiling_deceit_aura);
    RegisterAreaTriggerAI(areatrigger_ominous_cloud);
    RegisterCreatureAI(npc_nerubian_voidweaver);
    RegisterCreatureAI(npc_orb_of_corruption);
    RegisterCreatureAI(npc_projection_of_cthun);
    RegisterCreatureAI(npc_projection_of_yogg_saron);
    RegisterCreatureAI(npc_ominous_cloud_stalker);
    RegisterAuraScript(aura_corruptors_path);
    RegisterSpellScript(spell_roiling_deceit_damage);
}
