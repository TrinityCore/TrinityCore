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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "uldir.h"

enum Spells
{
    SPELL_ANNIHILATION_DEBUFF = 272336,
    SPELL_EXISTENSE_FRAGMENT_CREATE_AT = 272480,
    SPELL_EXISTENCE_FRAGMENT_MISSILE = 272467,
    SPELL_ESSENCE_SHEAR = 273282,
    SPELL_OBLIVION_SPHERE_SUMMON = 272394, //npc 138492
    SPELL_OBLIVION_SPHERE_CHARM = 272407, //range 5y
    SPELL_OBLIVION_SPHERE_MIND_CONTROL = 284944,
    SPELL_CRASHING_OBLIVION_EXPLOSION = 276863,
    SPELL_OBLITERATION_BLAST_CREATE_AT = 273552,
    SPELL_OBLITERATION_BLAST_DAMAGE = 273554,
    SPELL_IMMINENT_RUIN_AURA = 272536,
    SPELL_IMMINENT_RUIN_DECREASE_SPEED = 272541,
    SPELL_IMMINENT_RUIN_EXPLOSION = 272543,
    //Phase 2
    SPELL_OBLIVION_VEIL_AURA = 274230,
    SPELL_XALZAIX_MAIN = 273810,
    SPELL_XALZAIX_CREATE_AT_VISUAL = 273831,
    SPELL_XALZAIX_DAMAGE = 273811,
    SPELL_OBLITERATION_BEAM_SUMMON_TARGET = 272110, //npc 138315
    SPELL_OBLITERATION_BEAM_CREATE_AT = 279887,
    SPELL_OBLITERATION_BEAM_AT_DAMAGE = 274113,
    //Heroic Phase 2
    SPELL_ESSENCE_SHATTER = 279013,
    //Adds
    SPELL_VISION_OF_MADNESS_SUMMON = 273951,
    SPELL_MINDFLAY = 274019,
    SPELL_VISION_OF_MADNESS_MISSILE = 273950,
    SPELL_VISION_OF_MADNESS_AURA = 274004,
    SPELL_CRITICAL_MASS_AURA = 276900,
    SPELL_VOID_VOLLEY = 273945,
    //Mythic
    //Once Xalzaix has landed, it will become active and players must damage it down to 50% health, at which point it will retreat and regain health back to 100%.
    SPELL_LIVING_WEAPON_LANDING_MARK = 276912,
    SPELL_LIVING_WEAPON_DAMAGE = 276922,    
    SPELL_VOID_ECHOES = 279157, // every 10s
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_AGGRO_WHISPER,
    SAY_OBLITERATION_BLAST,
    SAY_OBLITERATION_BLAST_WHISPER,
    SAY_OBLIVION_SPHERE,
    SAY_OBLIVION_SPHERE_WHISPER,
    SAY_XALZAIX_AWAKENING,
    SAY_XALZAIX_AWAKENING_WHISPER,
    SAY_OBLITERATION_BEAM,
    SAY_OBLITERATION_BEAM_WHISPER,
    SAY_KILL,
    SAY_DEATH,
    SAY_DEATH_WHISPER
};

enum Events
{
    EVENT_ESSENCE_SHEAR = 1,
    EVENT_IMMINENT_RUIN,
    EVENT_OBLIVION_SPHERE,
    EVENT_OBLITERATION_BLAST,
    //Phase 2
    EVENT_VISION_OF_MADNESS,
    EVENT_OBLITERATION_BEAM,
    EVENT_NRAQI,
    EVENT_XALZAIX,
    EVENT_PHASE_ONE
};

const Position middle_pos = { 255.149f, -255.744f, 542.909f, 3.65f };
const Position nraqi_pos_one = { 228.434f, -238.122f, 542.908f, 5.736f };
const Position nraqi_pos_two = { 246.924f, -286.016f, 542.908f, 1.136f };

//134546
struct boss_mythrax : public BossAI
{
    boss_mythrax(Creature* creature) : BossAI(creature, DATA_MYTHRAX) { }

private:
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();
        /*if (instance->GetBossState(DATA_ZUL) != DONE)
            me->SetVisible(false);*/
        me->SetReactState(REACT_DEFENSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {        
        _EnterCombat();
        Talk(SAY_AGGRO);
        Talk(SAY_AGGRO_WHISPER);
        this->phase = 1;
        events.ScheduleEvent(EVENT_ESSENCE_SHEAR, 3s);
        events.ScheduleEvent(EVENT_IMMINENT_RUIN, 5s);
        events.ScheduleEvent(EVENT_OBLIVION_SPHERE, 9s);
        //events.ScheduleEvent(EVENT_OBLITERATION_BLAST, 11s);
        if (IsMythic())
            events.ScheduleEvent(EVENT_XALZAIX, 8s);
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(67) && this->phase != 2)
        {
            this->phase = 2;
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(1, middle_pos, true);
            if (IsHeroic() || IsMythic())
                if (Creature* xalzaix = me->FindNearestCreature(NPC_XALZAIX, 100.0f, true))
                    xalzaix->DespawnOrUnsummon();
        }
        if (me->HealthBelowPct(34) && this->phase != 2)
        {
            this->phase = 2;
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(1, middle_pos, true);
            if (IsHeroic() || IsMythic())
                if (Creature* xalzaix = me->FindNearestCreature(NPC_XALZAIX, 100.0f, true))
                    xalzaix->DespawnOrUnsummon();
        }
        if (me->HealthBelowPct(21) && this->phase == 1 && IsHeroic() || IsMythic())
        {
            std::list<Player*> pl_li;
            me->GetPlayerListInGrid(pl_li, 100.0f);
            for (auto& targets : pl_li)
            {
                me->CastSpell(targets, SPELL_ESSENCE_SHATTER, true);
            }
        }
    }

    void CleanEncounter(InstanceScript* instance, Creature* mythrax)
    {
        me->DespawnCreaturesInArea(NPC_OBLIVION_SPHERE, 125.0f);
        me->DespawnCreaturesInArea(NPC_VISION_OF_MADNESS, 125.0f);
        me->DespawnCreaturesInArea(NPC_NRAQI_DESTROYER, 125.0f);
        me->DespawnCreaturesInArea(NPC_XALZAIX, 125.0f);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        CleanEncounter(instance, me);
        me->RemoveAllAreaTriggers();
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == 1)
        {            
            events.Reset();
            this->phase = 2;
            Talk(SAY_XALZAIX_AWAKENING);
            Talk(SAY_XALZAIX_AWAKENING_WHISPER);
            me->CastSpell(nullptr, SPELL_XALZAIX_MAIN, false);
            AddTimedDelayedOperation(8000, [this]() -> void
            {
                me->AddAura(SPELL_OBLIVION_VEIL_AURA);
                me->CastSpell(nullptr, SPELL_XALZAIX_CREATE_AT_VISUAL);
                me->CastSpell(me->GetVictim(), SPELL_XALZAIX_DAMAGE, true);
                events.ScheduleEvent(EVENT_VISION_OF_MADNESS, 5s);
                events.ScheduleEvent(EVENT_NRAQI, 15s);
                events.ScheduleEvent(EVENT_OBLITERATION_BEAM, 18s);
                events.ScheduleEvent(EVENT_PHASE_ONE, 60s);
            });
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            if (roll_chance_f(15))
                Talk(SAY_KILL);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() != NPC_OBLIVION_SPHERE)
            summon->AI()->DoZoneInCombat(nullptr);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_ESSENCE_SHEAR:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                DoCast(SPELL_ESSENCE_SHEAR);
            }
            events.Repeat(14s);
            break;
        }
        case EVENT_IMMINENT_RUIN:
        {             
            UnitList u_li;
            SelectTargetList(u_li, 4, SELECT_TARGET_RANDOM, 150.0f, true);
            for (Unit* targets : u_li)
            {
                me->CastSpell(targets, SPELL_IMMINENT_RUIN_AURA, true);
                me->CastSpell(targets, SPELL_IMMINENT_RUIN_DECREASE_SPEED, true);
            }
            events.Repeat(20s);
            break;
        }
        case EVENT_OBLITERATION_BLAST:
        {            
            Talk(SAY_OBLITERATION_BLAST);
            Talk(SAY_OBLITERATION_BLAST_WHISPER);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(nullptr, SPELL_OBLITERATION_BLAST_CREATE_AT, true);
            }
            events.Repeat(25s);
            break;
        }
        case EVENT_OBLIVION_SPHERE:
        {
            Talk(SAY_OBLIVION_SPHERE);
            Talk(SAY_OBLIVION_SPHERE_WHISPER);
            UnitList u_li;
            SelectTargetList(u_li, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : u_li)
            {
                me->CastSpell(targets->GetRandomNearPosition(10.0f), SPELL_OBLIVION_SPHERE_SUMMON, true);
            }
            events.Repeat(30s);
            break;
        }
        case EVENT_VISION_OF_MADNESS:
        {
            UnitList u_li;
            SelectTargetList(u_li, 5, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : u_li)
            {
                me->CastSpell(targets->GetPosition(), SPELL_VISION_OF_MADNESS_SUMMON, true);
            }
            break;
        }
        case EVENT_NRAQI:
        {
            me->SummonCreature(NPC_NRAQI_DESTROYER, nraqi_pos_one, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_NRAQI_DESTROYER, nraqi_pos_two, TEMPSUMMON_MANUAL_DESPAWN);
            break;
        }
        case EVENT_PHASE_ONE:
        {
            events.Reset();
            me->RemoveAura(SPELL_OBLIVION_VEIL_AURA);
            me->SetReactState(REACT_AGGRESSIVE);
            me->GetMotionMaster()->Clear();
            me->AI()->AttackStart(me->GetVictim());
            events.ScheduleEvent(EVENT_ESSENCE_SHEAR, 3s);
            events.ScheduleEvent(EVENT_IMMINENT_RUIN, 5s);
            events.ScheduleEvent(EVENT_OBLIVION_SPHERE, 9s);
            //events.ScheduleEvent(EVENT_OBLITERATION_BLAST, 11s);
            break;
        }
        case EVENT_OBLITERATION_BEAM:
        {
            Talk(SAY_OBLITERATION_BEAM);
            Talk(SAY_OBLITERATION_BEAM_WHISPER);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_OBLITERATION_BEAM_CREATE_AT, true);
            }
            events.Repeat(20s);
            break;
        }
        case EVENT_XALZAIX:
        {  
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target->GetPosition(), SPELL_LIVING_WEAPON_LANDING_MARK, true);
                AddTimedDelayedOperation(3000, [this, target]() -> void
                {
                    me->SummonCreature(NPC_XALZAIX, target->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                });
            }
            break;
        }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        Talk(SAY_DEATH_WHISPER);
        CleanEncounter(instance, me);
        if (auto* mythraxDoor = me->FindNearestGameObject(GO_MYTHRAX_DOOR, 100.0f))
            mythraxDoor->SetGoState(GO_STATE_ACTIVE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OBLIVION_SPHERE_CHARM);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_SHATTER);
    }
};

//272536
class aura_imminent_ruin : public AuraScript
{
    PrepareAuraScript(aura_imminent_ruin);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();
            caster->CastSpell(target->GetPosition(), SPELL_IMMINENT_RUIN_EXPLOSION, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_imminent_ruin::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//138492
struct npc_oblivion_sphere : public ScriptedAI
{
    npc_oblivion_sphere(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) <= 5.0f && !unit->HasAura(SPELL_OBLIVION_SPHERE_CHARM))
        {
            me->AddAura(SPELL_OBLIVION_SPHERE_CHARM, unit);
            //me->CastSpell(unit, SPELL_OBLIVION_SPHERE_MIND_CONTROL, true);
        }
        if (unit->IsPlayer() && me->GetDistance2d(unit) > 5.0f && unit->HasAura(SPELL_OBLIVION_SPHERE_CHARM))
        {
            me->CastSpell(unit, SPELL_CRASHING_OBLIVION_EXPLOSION, true);
            unit->RemoveAura(SPELL_OBLIVION_SPHERE_CHARM);
        }
    }
};


enum Xalzaix
{
    EVENT_VOID_ECHOES = 1,
};

//138324
struct npc_xalzaix : public ScriptedAI
{
    npc_xalzaix(Creature* creature) : ScriptedAI(creature) {
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

private:
    bool retreat;

    void Reset() override
    {
        ScriptedAI::Reset();
        retreat = false;
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetEntry() == NPC_MYTHRAX)
            me->CastSpell(nullptr, SPELL_LIVING_WEAPON_DAMAGE, true);
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(51) && !retreat)
        {
            retreat = true;
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            
            me->SetVisible(false);
            me->RemoveAllAuras();
            me->ClearInCombat();
            me->SetHealth(me->GetMaxHealth());
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_VOID_ECHOES, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (Creature* mythrax = me->FindNearestCreature(NPC_MYTHRAX, 150.0f, true))
        {
            if (!mythrax->IsInCombat())
                me->DespawnOrUnsummon();
        }
        switch (eventId)
        {
        case EVENT_VOID_ECHOES:
            me->CastSpell(nullptr, SPELL_VOID_ECHOES, false);
            events.Repeat(10s);
            break;
        }
    }
};

void AddSC_boss_mythrax()
{
    RegisterCreatureAI(boss_mythrax);
    RegisterAuraScript(aura_imminent_ruin);
    RegisterCreatureAI(npc_oblivion_sphere);
    RegisterCreatureAI(npc_xalzaix);
}
