/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "trial_of_the_champion.h"

enum Yells
{
    SAY_AGGRO               = 3,
    SAY_PHASE_2             = 4,
    SAY_PHASE_3             = 5,
    SAY_KILL                = 6,
    SAY_DEATH               = 7
};

enum Events
{
    // The Black Knight
    EVENT_ICY_TOUCH         = 1,
    EVENT_PLAGUE_STRIKE,
    EVENT_DEATH_RESPITE,
    EVENT_OBLITERATE,
    EVENT_DESECRATION,
    EVENT_GHOUL_EXPLODE,
    EVENT_DEATH_BITE,
    EVENT_MARKED_DEATH,
    EVENT_RESURRECT,
    // Ghouls
    EVENT_CLAW,
    EVENT_LEAP
};

enum Spells
{
    // Phase 1
    SPELL_PLAGUE_STRIKE     = 67724,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_OBLITERATE        = 67725,
    SPELL_RAISE_ARELAS      = 67705,
    SPELL_RAISE_JAEREN      = 67715,

    // Phase 2
    SPELL_ARMY_DEAD         = 67761,
    SPELL_DESECRATION       = 67778,
    SPELL_GHOUL_EXPLODE     = 67751,

    // Phase 3
    SPELL_DEATH_BITE        = 67808,
    SPELL_MARKED_DEATH      = 67882,

    // Ghouls
    SPELL_CLAW              = 67774,
    SPELL_LEAP              = 67749,

    SPELL_DEATH_RESPITE_DND = 66798, // casted on announcer
    SPELL_FEIGN_DEATH       = 66804,
    SPELL_BLACK_KNIGHT_DIE  = 67691,
    SPELL_BLACK_KNIGHT_RES  = 67693,
    SPELL_FROST_FEVER       = 67719,
    SPELL_BLOOD_PLAGUE      = 67722,
    SPELL_EXPLODE           = 67729,
    SPELL_DESECRATION_DND   = 67782,
    SPELL_DESECRATION_ARM   = 67803,
    SPELL_FROST_FEVER_H     = 67878,
    SPELL_BLOOD_PLAGUE_H    = 67885,
    SPELL_EXPLODE_H         = 67886,
    SPELL_KILL_CREDIT       = 68663
};

enum Models
{
    MODEL_SKELETON          = 29846,
    MODEL_GHOST             = 21300
};

enum Equipment
{
    EQUIP_SWORD             = 40343
};

enum Phases
{
    PHASE_UNDEAD            = 1,
    PHASE_SKELETON          = 2,
    PHASE_GHOST             = 3
};

class npc_risen_ghoul : public CreatureScript
{
public:
    npc_risen_ghoul() : CreatureScript("npc_risen_ghoul") { }

    struct npc_risen_ghoulAI : public ScriptedAI
    {
        npc_risen_ghoulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            doExplode = false;
        }

        InstanceScript* instance;

        EventMap events;

        bool doExplode;

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_EXPLODE || spell->Id == SPELL_EXPLODE_H)
            {
                if (!target->ToPlayer())
                    return;

                if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                    // If corpse explosion hits any player during encounter
                    // we cannot give achievement id 3804
                    knight->AI()->SetData(1, 0);
            }
        }

        void DoExplode()
        {
            // We trigger the ghoul explode spell casted on us by Black Knight
            // to get immunity to crowd control forms and we get correct growth aura
            // the spell script of Ghoul Explode functions normally from here on
            if (me->HasAura(SPELL_GHOUL_EXPLODE))
                return;
            DoCast(me, SPELL_GHOUL_EXPLODE, true);
            // wtf?
            if (me->GetEntry() == NPC_RISEN_ARELAS || me->GetEntry() == NPC_RISEN_JAEREN)
                Talk(urand(0, 2));
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (HealthBelowPct(31) && !doExplode)
            {
                // Ghouls cast explode when they reach 30% health or if Black Knight dies
                // or if Black Knight forces them to explode
                doExplode = true;
                DoExplode();
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_CLAW, 3000);
            events.ScheduleEvent(EVENT_LEAP, 2000);
            DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(1000);
        }

        void KilledUnit(Unit* who) override
        {
            if (who == me)
                return;
            if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
            {
                if (!knight->HasAura(SPELL_BLACK_KNIGHT_DIE))
                    knight->AI()->KilledUnit(who);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLAW:
                        DoCastVictim(SPELL_CLAW);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50.0f, true))
                        {
                            ResetThreatList();
                            AddThreat(target, 10.0f);
                            me->AI()->AttackStart(target);
                        }
                        events.ScheduleEvent(EVENT_CLAW, urand(12000, 15000));
                        break;
                    case EVENT_LEAP:
                        if (me->GetEntry() == NPC_RISEN_ARELAS || me->GetEntry() == NPC_RISEN_JAEREN)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
                                DoCast(target, SPELL_LEAP);
                            events.ScheduleEvent(EVENT_LEAP, urand(8000, 10000));
                        }
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<npc_risen_ghoulAI>(creature);
    }
};

class boss_black_knight : public CreatureScript
{
public:
    boss_black_knight() : CreatureScript("boss_black_knight") { }

    struct boss_black_knightAI : public BossAI
    {
        boss_black_knightAI(Creature* creature) : BossAI(creature, DATA_BLACK_KNIGHT)
        {
            Initialize();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            uiPhase = PHASE_UNDEAD;
            achievementCredit = true;
        }

        uint8 uiPhase;
        bool achievementCredit;

        void Reset() override
        {
            me->SetDisplayId(me->GetNativeDisplayId());
            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            _Reset();
            Initialize();
        }

        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override
        {
            BossAI::EnterEvadeMode(why);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        // Events are not resetted in this function
        void LoadEvents()
        {
            if (uiPhase == PHASE_GHOST)
            {
                // Phase 3
                events.ScheduleEvent(EVENT_DEATH_BITE, 5000);
                events.ScheduleEvent(EVENT_MARKED_DEATH, 20000);
            }
            else
            {
                // Phase 1 and 2
                events.ScheduleEvent(EVENT_ICY_TOUCH, 6000);
                if (uiPhase == PHASE_UNDEAD)
                {
                    // Phase 1 only
                    events.ScheduleEvent(EVENT_DEATH_RESPITE, 8000);

                    // Raising announcer as a ghoul
                    if (Creature* announcer = instance->GetCreature(DATA_ANNOUNCER))
                    {
                        if (announcer->GetEntry() == NPC_JAEREN)
                            announcer->CastSpell(me->GetVictim(), SPELL_RAISE_JAEREN, false);
                        else
                            announcer->CastSpell(me->GetVictim(), SPELL_RAISE_ARELAS, false);
                    }
                }
                else
                {
                    // Phase 2 only
                    events.ScheduleEvent(EVENT_DESECRATION, 5000);
                    events.ScheduleEvent(EVENT_GHOUL_EXPLODE, 8000);

                    // Army of the Dead
                    // disabling movement temporarily so the spell wont get interrupted
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    DoCast(SPELL_ARMY_DEAD);
                }
            }
        }

        void SetData(uint32 type, uint32 /*data*/) override
        {
            if (type == 1)
                achievementCredit = false;
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_BLACK_KNIGHT_RES)
            {
                // TODO: According to sniffs, The Black Knight should update
                // creature template to another entry, not just change his display id
                // But the other templates are missing correct damage modifiers
                me->SetFullHealth();
                me->SetStandState(UNIT_STAND_STATE_STAND);
                if (uiPhase == PHASE_UNDEAD)
                {
                    me->SetDisplayId(MODEL_SKELETON);
                    Talk(SAY_PHASE_2);
                }
                else if (uiPhase == PHASE_SKELETON)
                {
                    me->SetDisplayId(MODEL_GHOST);
                    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                    Talk(SAY_PHASE_3);
                }
                ++uiPhase;
                LoadEvents();
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 0)
            {
                if (Creature* announcer = instance->GetCreature(DATA_ANNOUNCER))
                    announcer->AI()->SetData(DATA_BLACK_KNIGHT_PRECAST, 0);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_DESECRATION_STALKER)
            {
                summon->CastSpell(summon, SPELL_DESECRATION_DND, true);
                summon->CastSpell(summon, SPELL_DESECRATION_ARM, true);
                return;
            }
            summons.Summon(summon);
            summon->AI()->AttackStart(me->GetVictim());
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void DamageTaken(Unit* /*done_by*/, uint32& damage) override
        {
            if (damage >= me->GetHealth() && uiPhase < PHASE_GHOST)
            {
                damage = 0;
                events.Reset();
                me->RemoveAllAuras();
                me->SetHealth(0);
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                DoCast(me, SPELL_BLACK_KNIGHT_DIE);
                for (SummonList::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
                {
                    Creature* ghoul = ObjectAccessor::GetCreature(*me, *itr);
                    if (ghoul && ghoul->IsAlive() && !ghoul->HasAura(SPELL_GHOUL_EXPLODE))
                        ENSURE_AI(npc_risen_ghoul::npc_risen_ghoulAI, ghoul->AI())->DoExplode();
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_KILL_CREDIT, 0, me);
            _JustDied();
        }

        void JustEngagedWith(Unit* who) override
        {
            LoadEvents();
            Talk(SAY_AGGRO, who);
            _JustEngagedWith();
        }

        void KilledUnit(Unit* who) override
        {
            Talk(SAY_KILL, who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ICY_TOUCH:
                        DoCastVictim(SPELL_ICY_TOUCH);
                        events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 1000);
                        break;
                    case EVENT_PLAGUE_STRIKE:
                        DoCastVictim(SPELL_PLAGUE_STRIKE);
                        events.ScheduleEvent(EVENT_OBLITERATE, 5000);
                        break;
                    case EVENT_OBLITERATE:
                        DoCastVictim(SPELL_OBLITERATE);
                        events.ScheduleEvent(EVENT_ICY_TOUCH, urand(5000, 8000));
                        break;
                    case EVENT_DEATH_RESPITE:
                        // TODO: fixing this later
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50.0f, true))
                            DoCast(target, SPELL_DEATH_RESPITE);
                        events.ScheduleEvent(EVENT_DEATH_RESPITE, urand(15000, 16000));
                        break;
                    case EVENT_DESECRATION:
                        DoCastVictim(SPELL_DESECRATION);
                        events.ScheduleEvent(EVENT_DESECRATION, urand(15000, 16000));
                        break;
                    case EVENT_GHOUL_EXPLODE:
                        DoCastAOE(SPELL_GHOUL_EXPLODE);
                        events.ScheduleEvent(EVENT_GHOUL_EXPLODE, urand(15000, 16000));
                        break;
                    case EVENT_DEATH_BITE:
                        DoCastAOE(SPELL_DEATH_BITE);
                        events.ScheduleEvent(EVENT_DEATH_BITE, 3000);
                        break;
                    case EVENT_MARKED_DEATH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                            DoCast(target, SPELL_MARKED_DEATH);
                        events.ScheduleEvent(EVENT_MARKED_DEATH, urand(13000, 15000));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_black_knightAI>(creature);
    }
};

class npc_black_knight_skeletal_gryphon : public CreatureScript
{
public:
    npc_black_knight_skeletal_gryphon() : CreatureScript("npc_black_knight_skeletal_gryphon") { }

    struct npc_black_knight_skeletal_gryphonAI : public EscortAI
    {
        npc_black_knight_skeletal_gryphonAI(Creature* creature) : EscortAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            SetDespawnAtEnd(true);

            uiWaypointPath = 0;
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 uiWaypointPath;

        void SetData(uint32 uiType, uint32 /*uiData*/) override
        {
            if (uiType == 1)
            {
                // Black Knight is flying towards arena
                AddWaypoint(0, 766.99f, 657.16f, 457.43f);
                AddWaypoint(1, 747.28f, 659.71f, 440.49f);
                AddWaypoint(2, 730.03f, 639.59f, 428.16f);
                AddWaypoint(3, 721.13f, 621.49f, 423.16f);
                AddWaypoint(4, 731.72f, 599.81f, 421.99f);
                AddWaypoint(5, 753.71f, 591.09f, 420.63f);
                AddWaypoint(6, 776.53f, 597.52f, 418.05f);
                AddWaypoint(7, 787.38f, 617.07f, 417.49f);
                AddWaypoint(8, 777.06f, 636.98f, 416.57f);
                AddWaypoint(9, 760.6f, 642.12f, 414.71f);
                AddWaypoint(10, 752.58f, 632.35f, 411.63f);
                // The vehicle starts flying away
                AddWaypoint(11, 748.89f, 633.61f, 415.24f);
                AddWaypoint(12, 740.42f, 636.31f, 418.32f);
                AddWaypoint(13, 727.49f, 637.4f, 422.24f);
                AddWaypoint(14, 716.59f, 617.99f, 422.24f);
                AddWaypoint(15, 727.18f, 599.29f, 422.24f);
                AddWaypoint(16, 746.63f, 587.77f, 422.24f);
                AddWaypoint(17, 765.6f, 599.52f, 422.24f);
                AddWaypoint(18, 777.01f, 618.79f, 422.24f);
                AddWaypoint(19, 761.84f, 642.18f, 422.24f);
                AddWaypoint(20, 746.09f, 670.33f, 429.68f);
                AddWaypoint(21, 748.02f, 728.22f, 466.68f);
                AddWaypoint(22, 779.44f, 797.49f, 477.79f);
                AddWaypoint(23, 859.14f, 807.98f, 477.79f);
                Start(false, true);
            }
            else if (uiType == 2)
            {
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                SetEscortPaused(false);
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (waypointId == 10)
            {
                // Reached to arena
                SetEscortPaused(true);
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                if (Creature* announcer = instance->GetCreature(DATA_ANNOUNCER))
                {
                    me->SetFacingToObject(announcer);
                    announcer->AI()->SetData(DATA_BLACK_KNIGHT_PREPARE, 0);
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            EscortAI::UpdateAI(uiDiff);

            UpdateVictim();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<npc_black_knight_skeletal_gryphonAI>(creature);
    }
};

class spell_black_knight_deaths_push : public SpellScriptLoader
{
public:
    spell_black_knight_deaths_push() : SpellScriptLoader("spell_black_knight_deaths_push") { }

    class spell_black_knight_deaths_push_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_black_knight_deaths_push_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DEATH_RESPITE_DND) ||
                !sSpellMgr->GetSpellInfo(SPELL_FEIGN_DEATH))
                return false;
            return true;
        }

        void HandleScript(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // The spell applies a dummy aura with short duration
            // when the dummy aura is removed, announcer 'dies'
            GetTarget()->RemoveAura(SPELL_DEATH_RESPITE_DND);
            GetTarget()->CastSpell(GetTarget(), SPELL_FEIGN_DEATH, true);
            GetTarget()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_black_knight_deaths_push_AuraScript::HandleScript, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_black_knight_deaths_push_AuraScript();
    }
};

class spell_black_knight_obliterate : public SpellScriptLoader
{
public:
    spell_black_knight_obliterate() : SpellScriptLoader("spell_black_knight_obliterate") { }

    class spell_black_knight_obliterate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_black_knight_obliterate_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_BLOOD_PLAGUE) ||
                !sSpellMgr->GetSpellInfo(SPELL_FROST_FEVER) ||
                !sSpellMgr->GetSpellInfo(SPELL_BLOOD_PLAGUE_H) ||
                !sSpellMgr->GetSpellInfo(SPELL_FROST_FEVER_H))
                return false;
            return true;
        }

        void CalculateDamage()
        {
            if (!GetHitUnit())
                return;
            uint32 bloodPlague = GetCaster()->GetMap()->IsHeroic() ? SPELL_BLOOD_PLAGUE_H : SPELL_BLOOD_PLAGUE;
            uint32 frostFever = GetCaster()->GetMap()->IsHeroic() ? SPELL_FROST_FEVER_H : SPELL_FROST_FEVER;

            int32 damage = GetHitDamage();
            int32 bonus = 0;
            if (GetHitUnit()->HasAura(frostFever))
            {
                bonus += int32(damage * 0.3f);
                GetHitUnit()->RemoveAurasDueToSpell(frostFever);
            }
            if (GetHitUnit()->HasAura(bloodPlague))
            {
                bonus += int32(damage * 0.3f);
                GetHitUnit()->RemoveAurasDueToSpell(bloodPlague);
            }
            SetHitDamage(damage + bonus);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_black_knight_obliterate_SpellScript::CalculateDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_black_knight_obliterate_SpellScript();
    }
};

class spell_black_knight_army_of_the_dead : public SpellScriptLoader
{
public:
    spell_black_knight_army_of_the_dead() : SpellScriptLoader("spell_black_knight_army_of_the_dead") { }

    class spell_black_knight_army_of_the_dead_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_black_knight_army_of_the_dead_AuraScript);

        void RemoveFlag(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // that is wrong, movement disabled by spell (channel)
            // On aura remove we must remove disable movement flag
            if (Unit* caster = GetCaster())
                caster->SetControlled(false, UNIT_STATE_ROOT);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_black_knight_army_of_the_dead_AuraScript::RemoveFlag, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_black_knight_army_of_the_dead_AuraScript();
    }
};

class spell_black_knight_ghoul_explode : public SpellScriptLoader
{
public:
    spell_black_knight_ghoul_explode() : SpellScriptLoader("spell_black_knight_ghoul_explode") { }

    class spell_black_knight_ghoul_explode_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_black_knight_ghoul_explode_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_EXPLODE))
                return false;
            return true;
        }

        void CastExplode(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // On Ghoul Explode aura apply, start casting Explode
            GetTarget()->CastSpell(GetTarget(), SPELL_EXPLODE);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_black_knight_ghoul_explode_AuraScript::CastExplode, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_black_knight_ghoul_explode_AuraScript();
    }
};

// Achievement id 3804 - I've Had Worse
class achievement_ive_had_worse : public AchievementCriteriaScript
{
public:
    achievement_ive_had_worse() : AchievementCriteriaScript("achievement_ive_had_worse") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (target->GetEntry() != NPC_BLACK_KNIGHT)
            return false;
        if (!ENSURE_AI(boss_black_knight::boss_black_knightAI, target->GetAI())->achievementCredit)
            return false;
        return true;
    }
};

void AddSC_boss_black_knight()
{
    new boss_black_knight();
    new npc_risen_ghoul();
    new npc_black_knight_skeletal_gryphon();
    new spell_black_knight_deaths_push();
    new spell_black_knight_obliterate();
    new spell_black_knight_army_of_the_dead();
    new spell_black_knight_ghoul_explode();
    new achievement_ive_had_worse();
}