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
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "uldir.h"

enum Spells
{
    SPELL_OMEGA_VECTOR_CLOSEST_TARGET_SELECTOR = 277764,
    SPELL_OMEGA_VECTOR_TARGET_SELECTOR = 276439,
    SPELL_OMEGA_VECTOR_JUMP = 265140,
    SPELL_OMEGA_VECTOR_DAMAGE = 265143,
    SPELL_ENERGY_FILL = 265249,
    SPELL_LINGERING_INFECTION = 281080,
    SPELL_LINGERING_INFECTION_AURA = 265127,
    SPELL_EVOLVING_AFFLICTION = 265178,
    SPELL_CONTAGION = 267242,
    SPELL_GESTATE_TARGET_SELECTOR = 265208,
    SPELL_GESTATE = 265209,
    SPELL_GESTATE_SUMMON = 265215,
    SPELL_GESTATE_DAMAGE = 266077,
    SPELL_LIQUEFY = 265217,
    SPELL_LIQUEFY_CANCEL_COSMETIC = 265291,
    SPELL_BLOOD_GEYSER_TARGET_SELECTOR = 265928,
    SPELL_BLOOD_GEYSER_CREATE_AT = 277438,
    SPELL_BLOOD_GEYSER_DAMAGE = 265370,
    SPELL_BLOOD_GEYSER_CAST = 265281,
    SPELL_PLAGUE_BOMB_CAST = 266459,
    SPELL_PLAGUE_BOMB = 266926,
    SPELL_PLAGUE_BOMB_SUMMON_AMALGAM = 266953,
    SPELL_PLAGUE_BOMB_MISSILE_SUMMON = 277542,
    SPELL_PLAGUE_BOMB_AT = 267648,
    SPELL_BURSTING_LESIONS = 274990,
    SPELL_SPAWN_PARASITE = 275053,
    SPELL_TERMINAL_ERUPTION = 274989,
    SPELL_IMMUNOSUPPRESSION = 265206,
    SPELL_PATHOGEN_BOMB_VISUAL = 269676,
    SPELL_CAUSTIC_BITE = 275170,
    SPELL_PARASITIC_DISCHARGE = 276276,
    SPELL_LIQUEFY_CHANGE_MODEL = 277765,
};

enum Texts
{
    SAY_AGGRO,
    SAY_OMEGA_VECTOR,
    SAY_GESTATE,
    SAY_LIQUEFY,
    SAY_DEATH,
};

enum Events
{
    EVENT_GESTATE = 1,
    EVENT_CONTAGION,
    EVENT_EVOLVING_AFFLICTION,
    EVENT_LIQUEFY,
    EVENT_BLOOD_GEYSER,
    EVENT_PLAGUE_BOMB,
    EVENT_CHANGE_PHASE,
    EVENT_IMMUNOSUPPRESSION,
};

const int OmegaVectorAuras[4] =
{
    267160,267161, 267162, 267163
};

const Position VectisLiquefyPos[4] =
{
{ 710.08f, -239.776f, 694.698f, 3.85f },
{ 705.77f, -271.224f, 694.698f, 2.73f },
{ 619.86f, -226.085f, 694.698f, 5.43f },
{ 621.06f, -283.571f, 694.698f, 0.73f },
};

const Position PlagueBombPos[12] =
{
{ 640.71f, -264.544f, 694.698f, 3.85f },
{ 629.74f, -264.857f, 694.698f, 2.73f },
{ 618.33f, -264.711f, 694.698f, 5.43f },
{ 678.93f, -264.877f, 694.698f, 0.73f },
{ 688.71f, -264.808f, 694.698f, 3.85f },
{ 698.46f, -264.965f, 694.698f, 2.73f },
{ 698.86f, -256.172f, 694.698f, 5.43f },
{ 689.23f, -256.232f, 694.698f, 0.73f },
{ 679.75f, -256.292f, 694.698f, 3.85f },
{ 668.16f, -256.365f, 694.698f, 2.73f },
{ 629.98f, -247.196f, 694.698f, 5.43f },
{ 618.10f, -247.182f, 694.698f, 0.73f },
};

enum Misc
{
    ACHIEVEMENT_VECTIS_MYTHIC = 12529,
};

//134442
struct boss_vectis : public BossAI
{
    boss_vectis(Creature* creature) : BossAI(creature, DATA_VECTIS) { }

private:
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();
        this->phase = 0;
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->RemoveAura(SPELL_LIQUEFY_CHANGE_MODEL);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);        
    }

    void CleanEncounter(InstanceScript* instance, Creature* vectis)
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LINGERING_INFECTION_AURA);
        for (int i = 0; i < 4; i++)
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(OmegaVectorAuras[i]);
        }
        std::list<Creature*> npcList;
        vectis->GetCreatureListWithEntryInGrid(npcList, NPC_PLAGUE_AMALGAM, 300.0f);
        vectis->GetCreatureListWithEntryInGrid(npcList, NPC_ENGORGED_PARASITE, 300.0f);
        for (auto vectisMinions : npcList)
        {
            vectisMinions->DespawnOrUnsummon();
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        CleanEncounter(instance, me);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        this->phase = 1;
        events.ScheduleEvent(EVENT_GESTATE, 9s);
        events.ScheduleEvent(EVENT_EVOLVING_AFFLICTION, 3s);
        events.ScheduleEvent(EVENT_CONTAGION, 20s);
        events.ScheduleEvent(EVENT_LIQUEFY, 90s);
        DoCast(SPELL_OMEGA_VECTOR_TARGET_SELECTOR);
        DoCast(SPELL_ENERGY_FILL);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_PLAGUE_AMALGAM)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                summon->getThreatManager().resetAllAggro();
                summon->getThreatManager().addThreat(target, 1000000.0f);
                summon->GetMotionMaster()->MoveChase(target);
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        CleanEncounter(instance, me);
        if (IsMythic())
            instance->DoCompleteAchievement(ACHIEVEMENT_VECTIS_MYTHIC);
        AddTimedDelayedOperation(6000, [this]() -> void
        {
            instance->DoPlayScenePackageIdOnPlayers(SCENE_STAIRS);
        });
        CleanEncounter(instance, me);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (this->phase == 1)
        {
            switch (eventId)
            {
            case EVENT_CONTAGION:
            {
                DoCast(SPELL_CONTAGION);
                events.Repeat(22500);
                break;
            }
            case EVENT_EVOLVING_AFFLICTION:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                    me->CastSpell(target, SPELL_EVOLVING_AFFLICTION, true);
                events.Repeat(9500);
                break;
            }
            case EVENT_GESTATE:
            {
                Talk(SAY_GESTATE);
                DoCast(SPELL_GESTATE_TARGET_SELECTOR);
                events.Repeat(25s);
                break;
            }
            case EVENT_LIQUEFY:
            {                
                me->SetPower(POWER_ENERGY, 0);
                Talk(SAY_LIQUEFY);
                DoCast(SPELL_LIQUEFY);
                this->phase = 2;                    
                events.ScheduleEvent(EVENT_BLOOD_GEYSER, 5s);
                events.ScheduleEvent(EVENT_PLAGUE_BOMB, 10s);
                events.ScheduleEvent(EVENT_CHANGE_PHASE, 35s);
                break;
            }
            }
        }
        if (this->phase == 2)
        {
            switch (eventId)
            {
            case EVENT_BLOOD_GEYSER:
            {
                DoCast(SPELL_BLOOD_GEYSER_CAST);
                break;
            }
            case EVENT_PLAGUE_BOMB:
            {
                DoCast(SPELL_PLAGUE_BOMB_CAST);
                events.ScheduleEvent(EVENT_PLAGUE_BOMB, 10s);
                break;
            }
            case EVENT_CHANGE_PHASE:
            {
                this->phase = 1;                
                DoCast(SPELL_LIQUEFY_CANCEL_COSMETIC);
                me->RemoveAurasDueToSpell(SPELL_LIQUEFY);
                me->ClearUnitState(UNIT_STATE_ROOT);
                events.ScheduleEvent(EVENT_GESTATE, 9s);
                events.ScheduleEvent(EVENT_EVOLVING_AFFLICTION, 3s);
                events.ScheduleEvent(EVENT_CONTAGION, 20s);
                events.ScheduleEvent(EVENT_LIQUEFY, 90s);
                break;                
            }
            }
        }
    }
};

//135016
struct npc_plague_amalgam : public ScriptedAI
{
    npc_plague_amalgam(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_IMMUNOSUPPRESSION, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_IMMUNOSUPPRESSION:
        {
            me->CastSpell(me, SPELL_IMMUNOSUPPRESSION);
            events.ScheduleEvent(EVENT_IMMUNOSUPPRESSION, 10s);
            break;
        }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

//265208
class spell_gestate_selector : public SpellScript
{
    PrepareSpellScript(spell_gestate_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_GESTATE);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gestate_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gestate_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//265212
class spell_gestate : public AuraScript
{
    PrepareAuraScript(spell_gestate);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {        
        if (Unit* target = GetTarget())
        {
            Unit* caster = GetCaster();
            GetCaster()->CastSpell(target, SPELL_GESTATE_DAMAGE, true);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, SPELL_GESTATE_SUMMON);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gestate::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_gestate::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//276439
class spell_omega_vector_target_selector : public SpellScript
{
    PrepareSpellScript(spell_omega_vector_target_selector);
    int hosts = 0;
    int count = 0;
    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (this->count <= 4)
        {
            if (Unit* target = GetHitUnit())
            {
                target->CastSpell(target, OmegaVectorAuras[count]);
                count++;
            }
        }
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
        hosts = 0;
        count = 0;
        if (Unit* caster = GetCaster())
        {
            hosts = 1;
            hosts = 4 ? caster->GetInstanceScript()->instance->IsMythic() && hosts > 3 : 3 ? hosts > 2 : hosts;
        }
        Trinity::Containers::RandomResize(targets, hosts);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_omega_vector_target_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omega_vector_target_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//267160,267161,267162,267163
class spell_omega_vector : public AuraScript
{
    PrepareAuraScript(spell_omega_vector);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, SPELL_OMEGA_VECTOR_DAMAGE, true);
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetEffect(EFFECT_0)->GetTickNumber() >= uint32(GetEffect(EFFECT_0)->GetTotalTicks()))
        {
            if (Unit* target = GetTarget())
            {
                Player* nextPlayer = target->SelectNearestPlayer(500.0f);
                if (nextPlayer)
                    target->CastSpell(nextPlayer, GetSpellInfo()->Id);
                if (Unit* vectis = target->FindNearestCreature(NPC_VECTIS, 500.0f))
                {
                    vectis->Talk(SAY_OMEGA_VECTOR, ChatMsg::CHAT_MSG_RAID_BOSS_WHISPER, 0, nextPlayer);
                    vectis->AddAura(SPELL_LINGERING_INFECTION_AURA, target);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_omega_vector::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_omega_vector::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//266459
class spell_plague_bomb_cast : public SpellScript
{
    PrepareSpellScript(spell_plague_bomb_cast);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            int length = GetEffectInfo(effIndex)->BasePoints;
            for (int i = 0; i < length; i++)
            {
                Position pos = caster->GetRandomPoint(PlagueBombPos[i], 20);
                caster->CastSpell(pos, SPELL_PLAGUE_BOMB_MISSILE_SUMMON);
            }
            std::list<Creature*> creatureList;
            caster->GetCreatureListWithEntryInGrid(creatureList, NPC_PATHOGEN_BOMB, 50.0f);
            for (auto creatures : creatureList)
            {
                caster->CastSpell(creatures, SPELL_PLAGUE_BOMB);
                creatures->CastSpell(creatures, SPELL_PLAGUE_BOMB_AT);
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_plague_bomb_cast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//266948
class spell_plague_bomb : public SpellScript
{
    PrepareSpellScript(spell_plague_bomb);

    bool hitplayers = false;
    Unit* bunny;

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
        {
            if (hitUnit->IsPlayer())
                hitplayers = true;
            else
                if (hitUnit->GetEntry() == NPC_PATHOGEN_BOMB)
                    bunny = hitUnit;
        }
    }

    void HandleSummon()
    {
        if (!hitplayers)
            if (Creature* caster = GetCaster()->ToCreature())
            {
                if (bunny)
                    bunny->CastSpell(bunny, SPELL_PLAGUE_BOMB_SUMMON_AMALGAM);
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_plague_bomb::DoEffectHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_plague_bomb::HandleSummon);
    }
};

//17917
struct areatrigger_plague_bomb : AreaTriggerAI
{
    areatrigger_plague_bomb(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit && unit->IsPlayer())
            if (Unit* dummy = unit->FindNearestCreature(NPC_PATHOGEN_BOMB, 10.0f))
                dummy->RemoveAura(SPELL_PATHOGEN_BOMB_VISUAL);
    }
};

//265370
class spell_blood_geyser_damage : public SpellScript
{
    PrepareSpellScript(spell_blood_geyser_damage);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
        {
            if (Creature* vectis = hitUnit->FindNearestCreature(NPC_VECTIS, 500.0f))
                vectis->CastSpell(hitUnit, SPELL_LINGERING_INFECTION);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blood_geyser_damage::DoEffectHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

//265281
class spell_blood_geyser_aura : public AuraScript
{
    PrepareAuraScript(spell_blood_geyser_aura);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        int count = GetEffect(EFFECT_0)->GetAmount();
        for (int i = 0; i < count; i++)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_BLOOD_GEYSER_TARGET_SELECTOR);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_blood_geyser_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//265928
class spell_blood_geyser_cast : public SpellScript
{
    PrepareSpellScript(spell_blood_geyser_cast);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_BLOOD_GEYSER_CREATE_AT);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_blood_geyser_cast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//19185
void MoveForward(float distance, AreaTrigger* at)
{
    Position movePos;
    float ori = float(M_PI_2) + float(M_PI) + frand(0.f, float(M_PI));
    float x = at->GetPositionX() + distance * cos(ori);
    float y = at->GetPositionY() + distance * sin(ori);
    float z = at->GetPositionZ();
    at->GetNearPoint2D(x, y, distance, ori);
    movePos = { x, y, z, ori };
    at->SetDestination(movePos, 3500);    
}

//19185
struct areatrigger_blood_geyser : AreaTriggerAI
{
    areatrigger_blood_geyser(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
            if (Creature* vectis = unit->FindNearestCreature(NPC_VECTIS, 500.0f))
                vectis->CastSpell(unit, SPELL_BLOOD_GEYSER_DAMAGE);
    }

    void OnCreate()
    {
        MoveForward(100.0f, this->at);
    }
};

//265217
class spell_liquefy : public SpellScript
{
    PrepareSpellScript(spell_liquefy);

    void HandleMove()
    {
        if (Unit* caster = GetCaster())
        {
            int liquefypos = urand(0, 4);
            caster->GetMotionMaster()->MovePoint(1, VectisLiquefyPos[liquefypos]);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_liquefy::HandleMove);
    }
};

//?
struct areatrigger_liquefy : AreaTriggerAI
{
    areatrigger_liquefy(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
        {
            if (Creature* vectis = unit->FindNearestCreature(NPC_VECTIS, 100.0f))
                vectis->CastSpell(unit, SPELL_LINGERING_INFECTION);
        }
    }
};

//267242
class spell_contagion : public SpellScript
{
    PrepareSpellScript(spell_contagion);

    void HandleOnHit()
    {
        if (Unit* target = GetHitUnit())
        {
            if (target->GetInstanceScript()->instance->IsMythic())
            {
                if (Aura* lingeringInfection = target->GetAura(SPELL_LINGERING_INFECTION_AURA))
                {
                    switch (lingeringInfection->GetStackAmount())
                    {
                    case 6:
                        target->CastSpell(target, SPELL_BURSTING_LESIONS);
                        break;

                    case 12:
                        target->CastSpell(target, SPELL_SPAWN_PARASITE);
                        break;

                    case 25:
                        target->CastSpell(target, SPELL_TERMINAL_ERUPTION);
                        break;
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_contagion::HandleOnHit);
    }
};

//274990
class aura_burning_lesions : public AuraScript
{
    PrepareAuraScript(aura_burning_lesions);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            std::list<Player*> playersList;
            for (auto player : caster->SelectNearestPlayers(5.0f, true))
            {
                if (Creature* vectis = player->FindNearestCreature(NPC_VECTIS, 500.0f))
                    vectis->CastSpell(player, SPELL_LINGERING_INFECTION);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_burning_lesions::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//265178
class aura_evolving_affliction : public AuraScript
{
    PrepareAuraScript(aura_evolving_affliction);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
        {
            if (Aura* evolv_affli = target->GetAura(265178))
            {
                switch (evolv_affli->GetStackAmount())
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                }
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_evolving_affliction::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

enum
{
    EVENT_CAUSTIC_BITE = 1,
    EVENT_PARASITIC_DISCHARGE
};

//140478
struct npc_engorged_parasite : public ScriptedAI
{
    npc_engorged_parasite(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        events.ScheduleEvent(EVENT_CAUSTIC_BITE, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CAUSTIC_BITE:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_CAUSTIC_BITE, true);
            }
            events.Repeat(13s, 15s);
            break;

        case EVENT_PARASITIC_DISCHARGE:
            me->CastSpell(nullptr, SPELL_PARASITIC_DISCHARGE, false);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        events.ScheduleEvent(EVENT_PARASITIC_DISCHARGE, 100ms);
    }
};

//135687
struct npc_pathogen_bomb : public ScriptedAI
{
    npc_pathogen_bomb(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        SetCombatMovement(false);
    }
};

void AddSC_boss_vectis()
{
    RegisterCreatureAI(boss_vectis);
    RegisterCreatureAI(npc_plague_amalgam);
    RegisterAreaTriggerAI(areatrigger_liquefy);
    RegisterAreaTriggerAI(areatrigger_plague_bomb);
    RegisterAreaTriggerAI(areatrigger_blood_geyser);
    RegisterAuraScript(spell_gestate);
    RegisterAuraScript(spell_omega_vector);
    RegisterAuraScript(spell_blood_geyser_aura);
    RegisterSpellScript(spell_gestate_selector);
    RegisterSpellScript(spell_omega_vector_target_selector);
    RegisterSpellScript(spell_plague_bomb);
    RegisterSpellScript(spell_plague_bomb_cast);
    RegisterSpellScript(spell_liquefy);
    RegisterSpellScript(spell_blood_geyser_damage);
    RegisterSpellScript(spell_blood_geyser_cast);
    RegisterSpellScript(spell_contagion);
    RegisterAuraScript(aura_burning_lesions);
    RegisterAuraScript(aura_evolving_affliction);
    RegisterCreatureAI(npc_engorged_parasite);
    RegisterCreatureAI(npc_pathogen_bomb);
}
