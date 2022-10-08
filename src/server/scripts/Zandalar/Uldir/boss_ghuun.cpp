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

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_EXPLOSIVE_CORRUPTION_TARGET_SELECTOR = 272504,
    SPELL_EXPLOSIVE_CORRUPTION = 272505,
    SPELL_UNDULATING_MASS = 263321,
    SPELL_UNDULATING_MASS_AT = 263320,
    SPELL_UNDULATING_MASS_AT2 = 271953,
    SPELL_UNCLEAN_CONTAGION = 267657,
    SPELL_UNCLEAN_CONTAGION_AURA = 267659,
    SPELL_CORRUPTING_BITE = 270443,
    SPELL_CORRUPTING_BITE_DMG = 270454,
    SPELL_GROWING_CORRUPTION = 270447,
    SPELL_VIRULENT_CORRUPTION_AT = 272513,
    SPELL_VIRULENT_CORRUPTION = 273486,
    SPELL_VIRULENT_CORRUPTION_AT_HALF = 273540,
    SPELL_VIRULENT_CORRUPTION_AT2 = 277081,
    SPELL_BLIGHTED_GROUND = 270287,
    SPELL_BLIGHTED_GROUND_AT = 270286,
    SPELL_WAVE_OF_CORRUPTION_TARGET_SELECTOR = 270373,
    SPELL_WAVE_OF_CORRUPTION_DMG_N = 273477,
    SPELL_WAVE_OF_CORRUPTION_DMG_H = 270385,
    SPELL_WAVE_OF_CORRUPTION_KNOCK_BACK = 275703,
    SPELL_WAVE_OF_CORRUPTION = 270386,
    SPELL_GAZE_OF_GHUNN = 275160,
    SPELL_POWER_MATRIX_COLLECT = 269455,
    SPELL_POWER_MATRIX = 263372,
    SPELL_POWER_MATRIX_ROOT = 263426,
    SPELL_POWER_MATRIX_DECREASE_SPEED = 263420,
    SPELL_POWER_MATRIX_ENERGIZE = 263433,
    SPELL_POWER_MATRIX_COSMETICS = 263443,
    SPELL_TORMENT = 267427,
    SPELL_REORIGINATION_BLAST_CAST = 267761,
    SPELL_REORIGINATION_BLAST_DAMAGE_MAIN = 263503,
    SPELL_REORIGINATION_BLAST_STUN = 263504,    
    SPELL_REORIGINATION_BLAST_ENERGIZE = 269439,
    //SPELL_REORIGINATION_BLAST_DAMAGE = 281444, // not used
    SPELL_COLLAPSE = 276893,
    SPELL_COLLAPSE_PERIODIC = 276839,
    SPELL_IMPERFECT_PHYSIOLOGY = 263436,
    SPELL_IMPERFECT_PHYSIOLOGY_SELECTOR = 273214,
    SPELL_DARK_YOUNG_COSMETIC = 263381,    
    //Adds
    SPELL_MASSIVE_SMASH = 267412,
    EVENT_MASSIVE_SMASH = 1,
    EVENT_DARK_BARGAIN,
    SPELL_DARK_BARGAIN = 273405,
    SPELL_MIND_NUMBED_CHATTER = 263307,
    SPELL_UNSTOPABBLE_CORRUPTION = 275204,
    SPELL_DARK_PURPOSE = 267816,
    SPELL_BLOOD_HOST = 267813,
    SPELL_BLOOD_HOST_MISSILE = 268099,
    //Heroic
    SPELL_DECAYING_ERUPTION = 267462,
    SPELL_BURROW_TELEPORT = 267579,
    //Mythic
    SPELL_MATRIX_SURGE = 274534,
    SPELL_BURSTING_BOIL_SUMMON = 277071,
    SPELL_BURSTING_BOIL_AURA = 277007,
    SPELL_BURSTING_BOIL_AURA_DAMAGE = 277092,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_AGGRO_WHISPER,
    SAY_DARK_YOUNG,
    SAY_THOUSAND_MAWS,
    SAY_THOUSAND_MAWS_WHISPER,
    SAY_EMERGE = 6,
    SAY_EMERGE_WHISPER,
    SAY_BLOOD_FEAST_WHISPER,
    SAY_COLLAPSE,
    SAY_COLLAPSE_WHISPER,
    SAY_GAZE_OF_GHUUN,
    SAY_GAZE_OF_GHUUN_WHISPER,
    SAY_KILL,
    SAY_KILL_WHISPER,
    SAY_DEATH,
    SAY_DEATH_WHISPER
};

enum Events
{
    EVENT_EXPLOSIVE_CORRUPTION = 1,
    EVENT_THOUSAND_MAWS,
    EVENT_POWER_MATRIX,
    EVENT_BLIGHTSPREADER_TENDRIL,
    EVENT_WAVE_OF_CORRUPTION,
    EVENT_MALIGNANT_GROWTH,
    EVENT_GAZE,
    EVENT_TORMENT,
    EVENT_DRAIN_ENERGY,
    EVENT_DECAYING_ERUPTION,
    EVENT_MIND_NUMBED_CHATTER,
    EVENT_CORRUPTING_BITE,
    EVENT_BURSTING_BOIL,
};

enum Actions
{
    ACTION_POWER_MATRIX,
    ACTION_INIT_REORIGINATION_BLAST,
    ACTION_INIT_PHASE_TWO
};

enum Misc
{
    ACHIEVEMENT_MYTHIC_GHUUN = 12533,
    ACHIEVEMENT_HEART_OF_CORRUPTION = 12523,
};

const Position middle_pos = { 503.035f, -255.701f, 459.482f, 6.26f };

//132998
struct boss_ghuun : public BossAI
{
    boss_ghuun(Creature* creature) : BossAI(creature, DATA_GHUUN) { }

private:
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
        me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
        me->RemoveAura(SPELL_CORRUPTING_BITE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_ORANGE);
        me->SetVisible(true);
        SetCombatMovement(false);
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        damage = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        this->phase = 1;
        _EnterCombat();
        events.ScheduleEvent(EVENT_POWER_MATRIX, 4s);
        events.ScheduleEvent(EVENT_EXPLOSIVE_CORRUPTION, 5s);
        events.ScheduleEvent(EVENT_THOUSAND_MAWS, 23s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_BLIGHTSPREADER_TENDRIL, 28s);
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
        if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, reoriginationDrive);
        if (Creature* darkYoung = me->FindNearestCreature(NPC_DARK_YOUNG, 150.0f, true))
        {            
            if (darkYoung->isDead())  
                darkYoung->Respawn();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, darkYoung);
            darkYoung->AI()->DoZoneInCombat(nullptr);
        }
        std::list<Creature*> cyc_li;
        me->GetCreatureListWithEntryInGrid(cyc_li, 100.0f);
        for (auto& cyclopeans : cyc_li)
        {
            if (cyclopeans->isDead())
                cyclopeans->Respawn();
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, cyclopeans);
            cyclopeans->AI()->DoZoneInCombat(nullptr);
        }
        me->SetInCombatWithZone();
    }

    void CleanEncounter(InstanceScript* instance, Creature* ghuun)
    {
        me->DespawnCreaturesInArea(NPC_POWER_MATRIX, 125.0f);
        me->DespawnCreaturesInArea(NPC_DARK_YOUNG, 125.0f);
        me->DespawnCreaturesInArea(NPC_CYCLOPEAN_TERROR, 125.0f);
        if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, reoriginationDrive);
        me->DespawnCreaturesInArea(NPC_BLIGHTSPREADER_TENDRIL, 125.0f);
        me->DespawnCreaturesInArea(NPC_GIBBERING_HORROR, 125.0f);
        me->DespawnCreaturesInArea(NPC_SPAWN_OF_GHUUN, 125.0f);
        me->DespawnCreaturesInArea(NPC_MATRIX_SURGE, 125.0f);
        me->DespawnCreaturesInArea(NPC_BURSTING_BOIL, 125.0f);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)  override
    {
        if (IsMythic())
        {
            switch (summon->GetEntry())
            {
            case NPC_DARK_YOUNG:
            case NPC_BLIGHTSPREADER_TENDRIL:
                for (uint8 i = 0; i < 4; i++)
                {
                    me->CastSpell(nullptr, SPELL_BLOOD_HOST_MISSILE, true);
                }
                break;
            case NPC_CYCLOPEAN_TERROR:
                for (uint8 i = 0; i < 2; i++)
                {
                    me->CastSpell(nullptr, SPELL_BLOOD_HOST_MISSILE, true);
                }
                break;
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_EXPLOSIVE_CORRUPTION:
        {
            if (this->phase != 3)
            {
                UnitList u_li;
                SelectTargetList(u_li, 3, SELECT_TARGET_RANDOM, 150.0f, true);
                for (Unit* targets : u_li)
                {
                    me->CastSpell(targets, SPELL_EXPLOSIVE_CORRUPTION, true);
                }
            }
            else
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    me->CastSpell(target, SPELL_EXPLOSIVE_CORRUPTION, true);
            }
            events.Repeat(26s);
            break;
        }
        case EVENT_POWER_MATRIX:
        {
            bool taked = false;
            for (auto players : me->SelectNearestPlayers(200))
            {
                if (players->HasAura(SPELL_POWER_MATRIX))
                    taked = true;
            }
            if (!taked)
            for (auto idx : me->FindNearestCreatures(NPC_POWER_MATRIX, 500.0f))
            {
                //idx->Talk(0, ChatMsg::CHAT_MSG_RAID_BOSS_EMOTE, 1, idx->FindNearestCreature(NPC_GHUUN, 500.0f));
                idx->CastSpell(idx, SPELL_POWER_MATRIX_COSMETICS);
                idx->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
            events.Repeat(25s);
            break;
        }
        case EVENT_GAZE:
        {
            if (this->phase != 2)
                break;
            Talk(SAY_GAZE_OF_GHUUN);
            Talk(SAY_GAZE_OF_GHUUN_WHISPER);
            DoCast(SPELL_GAZE_OF_GHUNN);
            break;
        }
        case EVENT_BLIGHTSPREADER_TENDRIL:
        {
            me->SummonCreature(NPC_BLIGHTSPREADER_TENDRIL, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(45s);
            break;
        }
        case EVENT_THOUSAND_MAWS:
        {
            if (this->phase != 1)
                break;
            Talk(SAY_THOUSAND_MAWS);
            Talk(SAY_THOUSAND_MAWS_WHISPER);
            uint32 cyclopeansSpawns = urand(0, 2);
            switch (cyclopeansSpawns)
            {
            case 0:
                for (uint8 i = 0; i < 3; i++)
                {
                    me->SummonCreature(NPC_CYCLOPEAN_TERROR, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                me->SummonCreature(NPC_DARK_YOUNG, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case 1:
                for (uint8 i = 0; i < 4; i++)
                {
                    me->SummonCreature(NPC_CYCLOPEAN_TERROR, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                me->SummonCreature(NPC_DARK_YOUNG, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case 2:
                break;
                for (uint8 i = 0; i < 6; i++)
                {
                    me->SummonCreature(NPC_CYCLOPEAN_TERROR, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                me->SummonCreature(NPC_DARK_YOUNG, me->GetRandomPoint(middle_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                events.Repeat(30s);
                break;
            }
        }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_INIT_PHASE_TWO:
        {
            events.Reset();
            Talk(SAY_EMERGE);
            Talk(SAY_EMERGE_WHISPER);
            me->SetReactState(REACT_PASSIVE);
            me->DespawnOrUnsummon();
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (Creature* ghuunNonStatic = me->FindNearestCreature(NPC_GHUUN_NON_STATIC, 150.0f, true))
            {
                ghuunNonStatic->SetFaction(16);
                ghuunNonStatic->SetVisible(true);
                ghuunNonStatic->SetWalk(true);
                ghuunNonStatic->SetInCombatWithZone();
            }
            break;
        }
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        CleanEncounter(instance, me);
    }

    void JustDied(Unit* /*killer*/)
    {        
        _JustDied();
    }
};

//134107
struct npc_power_matrix : ScriptedAI
{
    npc_power_matrix(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        clicker->CastSpell(clicker, SPELL_POWER_MATRIX_COLLECT);
        me->RemoveAura(SPELL_POWER_MATRIX_COSMETICS);       
        if (Creature* reoriginationDerive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
            reoriginationDerive->ModifyPower(POWER_ENERGY, +34);

        if (IsMythic())
            me->SummonCreature(NPC_MATRIX_SURGE, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

//134034
struct npc_amorphous_cyst : public ScriptedAI
{
    npc_amorphous_cyst(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void InitializeAI() override
    {
        me->AddUnitState(UNIT_STATE_ROOT);
        me->CastSpell(nullptr, SPELL_UNDULATING_MASS_AT);
        ScriptedAI::InitializeAI();
    }
};

//138531
struct npc_cyclopean_terror : public ScriptedAI
{
    npc_cyclopean_terror(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        SetCombatMovement(false);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsInCombat())
            me->AI()->DoZoneInCombat(nullptr);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_TORMENT, 5s);
    }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TORMENT:
        {            
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(target, SPELL_TORMENT, false);
            events.Repeat(20s);
            break;
        }
        }
    }
};

//134635
struct npc_dark_young : public ScriptedAI
{
    npc_dark_young(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsInCombat())
            me->AI()->DoZoneInCombat(nullptr);       
    }

    void EnterCombat(Unit* /*who*/) override
    {        
        me->AddAura(SPELL_PERIODIC_ENERGY_GAIN);
        me->CastSpell(nullptr, SPELL_DARK_YOUNG_COSMETIC, true);
        events.ScheduleEvent(EVENT_MASSIVE_SMASH, 5s);
    }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->ModifyPower(POWER_ENERGY, -100);
            me->CastSpell(me->GetVictim(), SPELL_DARK_BARGAIN, false);
        }
        switch (eventId)
        {
        case SPELL_MASSIVE_SMASH:
        {
            me->CastSpell(me->GetVictim(), SPELL_MASSIVE_SMASH, false);
            events.Repeat(20s);
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

//272504
class spell_explosive_corruption_selector : public SpellScript
{
    PrepareSpellScript(spell_explosive_corruption_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_EXPLOSIVE_CORRUPTION, false);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_explosive_corruption_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_explosive_corruption_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//272506
class spell_explosive_corruption : public AuraScript
{
    PrepareAuraScript(spell_explosive_corruption);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(nullptr, SPELL_BLIGHTED_GROUND_AT);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_explosive_corruption::OnRemove, EFFECT_2, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

//270373
class spell_wave_of_corruption_selector : public SpellScript
{
    PrepareSpellScript(spell_wave_of_corruption_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_WAVE_OF_CORRUPTION);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return !obj->IsPlayer(); });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wave_of_corruption_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wave_of_corruption_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//269455
class spell_power_matrix_cast : public SpellScript
{
    PrepareSpellScript(spell_power_matrix_cast);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            caster->AddAura(SPELL_POWER_MATRIX, caster);
            if (!caster->GetInstanceScript()->instance->IsMythic())
                for (auto idx : caster->FindNearestCreatures(NPC_POWER_MATRIX, 500.0f))
                {
                    idx->RemoveAura(SPELL_POWER_MATRIX_COSMETICS);
                    idx->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                }
            else
            {
                Creature* power_matrix = caster->FindNearestCreature(NPC_POWER_MATRIX, 100.0f);
                power_matrix->RemoveAura(SPELL_POWER_MATRIX_COSMETICS);
                power_matrix->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_power_matrix_cast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class unclean_corruption : public PlayerScript
{
public:
    unclean_corruption() : PlayerScript("unclean_corruption") { }

private:
    uint32 checkTimer = 1000;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (player->GetMapId() == 1861 && checkTimer == 1000)
        {
            if (Creature* ghuun = player->FindNearestCreature(NPC_GHUUN, 250.0f, true))    
            {
                if (ghuun->IsInCombat() && player->GetPositionZ() > 465 && player->GetPositionZ() < 475)
                {
                    player->CastSpell(player, SPELL_UNCLEAN_CONTAGION);
                    player->AddAura(SPELL_UNCLEAN_CONTAGION_AURA);
                }
                if (player->GetPositionZ() < 475)
                {
                    player->RemoveAura(SPELL_UNCLEAN_CONTAGION);
                    player->RemoveAura(SPELL_UNCLEAN_CONTAGION_AURA);
                }
            }
        }
    }
};

//17350, 18108
struct areatrigger_undulating_mass : AreaTriggerAI
{
    areatrigger_undulating_mass(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
            unit->CastSpell(unit, SPELL_UNDULATING_MASS);
    }

    void OnUnitExit(Unit* unit)
    {
        if (unit)
            unit->RemoveAura(SPELL_UNDULATING_MASS);
    }

    void OnPeriodicProc()
    {
        float scale = at->GetObjectScale();
    }
};

//17948
struct areatrigger_blighted_corruption : AreaTriggerAI
{
    areatrigger_blighted_corruption(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
            unit->CastSpell(unit, SPELL_BLIGHTED_GROUND);
    }
    void OnUnitExit(Unit* unit)
    {
        if (unit)
            unit->RemoveAura(SPELL_BLIGHTED_GROUND);
    }
};

//?
struct areatrigger_virulent_corruption : AreaTriggerAI
{
    areatrigger_virulent_corruption(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
        {
            unit->CastSpell(unit, SPELL_VIRULENT_CORRUPTION);
            if (unit->GetInstanceScript()->instance->IsHeroic())
                unit->CastSpell(unit, SPELL_EXPLOSIVE_CORRUPTION);
        }
    }
};

//136263
struct npc_reorigination_drive : public ScriptedAI
{
    npc_reorigination_drive(Creature* creature) : ScriptedAI(creature) { }

private: 
    bool reorigination_blast;

    void Reset() override
    {
        ScriptedAI::Reset();
        reorigination_blast = false;
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        SetCombatMovement(false);
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->GetPowerPct(POWER_ENERGY) >= 100 && !reorigination_blast)
        {
            reorigination_blast = true;
            if (Creature* ghuun = me->FindNearestCreature(NPC_GHUUN, 200.0f, true))
                ghuun->AI()->DoAction(ACTION_INIT_PHASE_TWO);
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(nullptr, SPELL_REORIGINATION_BLAST_CAST, false);
            AddTimedDelayedOperation(24000, [this]() -> void
            {        
                std::list<Creature*> blastVictims_li;
                me->GetCreatureListWithEntryInGrid(blastVictims_li, NPC_DARK_YOUNG, 200.0f);
                me->GetCreatureListWithEntryInGrid(blastVictims_li, NPC_CYCLOPEAN_TERROR, 200.0f);
                me->GetCreatureListWithEntryInGrid(blastVictims_li, NPC_GIBBERING_HORROR, 200.0f);
                for (auto& targets : blastVictims_li)
                {
                    switch (targets->GetEntry())
                    {
                    case NPC_DARK_YOUNG:
                    case NPC_CYCLOPEAN_TERROR:
                    case NPC_GIBBERING_HORROR:
                        me->CastSpell(targets, SPELL_REORIGINATION_BLAST_DAMAGE_MAIN, true);
                        me->AddAura(SPELL_REORIGINATION_BLAST_STUN, targets);
                        break;
                    }
                }
                //Not used, it's pulling whole Uldir to the encounter
                //me->CastSpell(nullptr, SPELL_REORIGINATION_BLAST_DAMAGE, false);
                reorigination_blast = false;
            });
        }
    }
};

//134590
struct npc_blightspreader_tendril : public ScriptedAI
{
    npc_blightspreader_tendril(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_DRAIN_ENERGY, 1s);
        events.ScheduleEvent(EVENT_DECAYING_ERUPTION, 5s);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        SetCombatMovement(false);
        if (summoner->IsInCombat())
            me->AI()->DoZoneInCombat(nullptr);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPowerPct(POWER_ENERGY) == 0)
        {
            me->SetPower(POWER_ENERGY, 100);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(target, SPELL_BURROW_TELEPORT, false);
        }
        switch (eventId)
        {
        case EVENT_DRAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, -2);
            events.Repeat(2s);
            break;

        case EVENT_DECAYING_ERUPTION:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
                me->CastSpell(target, SPELL_DECAYING_ERUPTION, false);
            events.Repeat(15s);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

enum GhuunNonStatic
{
    SPELL_CORRUPTING_BITE_DUMMY = 270443,
    SPELL_CORRUPTING_BITE_DAMAGE = 270454,    
    SPELL_WAVE_OF_CORRUPTION_MAIN = 270373,
    SPELL_WAVE_OF_CORRUPTION_MISSILE = 270385,
    SPELL_WAVE_OF_CORRUPTION_KNOCKBACK = 275703,
    SPELL_BLOOD_FEAST_ROOT = 263235,
    SPELL_BLOOD_FEAST_VISUAL_MISSILE = 263295,
    SPELL_PUTRID_BLOOD_PERIODIC_DUMMY = 263227, //263225
    SPELL_CORPULENT_MASS = 275129,
    SPELL_COLLAPSE_MAIN = 276839,
    SPELL_COLLAPSE_TRIGGER_MISSILE = 276759,
    SPELL_COLLAPSE_VISUAL = 278125,
    SPELL_GAZE_OF_GHUUN_MAIN = 275160,
    SPELL_GAZE_OF_GHUUN_FEAR = 267700,
    SPELL_MALIGNANT_GROWTH_MISSILE = 274576,
    SPELL_MALIGNANT_GROWTH_CREATE_AT = 274664,    
    SPELL_BURSTING_BOIL_DAMAGE = 277092,
    SPELL_BURSTING_BOIL_VISUAL = 276994,
    //Add
    SPELL_BLOOD_MIGHT = 263284,
};

//163405 non-static ghuun
struct boss_ghuun_non_static : public BossAI
{
    boss_ghuun_non_static(Creature* creature) : BossAI(creature, DATA_GHUUN_FINAL) 
    { 
        me->SetVisible(false);
        me->SetFaction(35);
    }

private:
    uint8 waveOfCorruption;
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        me->AddAura(SPELL_CORRUPTING_BITE_DUMMY);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_ORANGE);
        me->AddAura(SPELL_PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_EXPLOSIVE_CORRUPTION, 5s);
        events.ScheduleEvent(EVENT_CORRUPTING_BITE, 1500ms);
        events.ScheduleEvent(EVENT_WAVE_OF_CORRUPTION, 20s);
        if (IsMythic())
            events.ScheduleEvent(EVENT_BURSTING_BOIL, 22s, 25s);
        this->waveOfCorruption = 0;
        this->phase = 2;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        me->SetFaction(35);
        _DespawnAtEvade();
        CleanEncounter(instance, me);
        if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, reoriginationDrive);
            reoriginationDrive->SetPower(POWER_ENERGY, 0);
        }
    }

    void CleanEncounter(InstanceScript* instance, Creature* ghuun)
    {
        me->DespawnCreaturesInArea(NPC_POWER_MATRIX, 125.0f);
        me->DespawnCreaturesInArea(NPC_DARK_YOUNG, 125.0f);
        me->DespawnCreaturesInArea(NPC_CYCLOPEAN_TERROR, 125.0f);
        if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, reoriginationDrive);
        me->DespawnCreaturesInArea(NPC_BLIGHTSPREADER_TENDRIL, 125.0f);
        me->DespawnCreaturesInArea(NPC_GIBBERING_HORROR, 125.0f);
        me->DespawnCreaturesInArea(NPC_SPAWN_OF_GHUUN, 125.0f);
        me->DespawnCreaturesInArea(NPC_MATRIX_SURGE, 125.0f);
        me->DespawnCreaturesInArea(NPC_BURSTING_BOIL, 125.0f);
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(21) && this->phase == 2)
        {
            this->phase = 3;
            events.Reset();
            if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
                me->Kill(reoriginationDrive);
            me->AddAura(SPELL_CORPULENT_MASS);
            AddTimedDelayedOperation(19000, [this]() -> void
            {
                me->RemoveAura(SPELL_CORPULENT_MASS);
            });
            me->CastSpell(nullptr, SPELL_COLLAPSE_MAIN, false);
            std::list<Player*> pl_li;
            me->GetPlayerListInGrid(pl_li, 150.0f);
            for (auto& targets: pl_li)
            {
                me->CastSpell(targets->GetPosition(), SPELL_COLLAPSE_TRIGGER_MISSILE, true);
            }
            events.ScheduleEvent(EVENT_EXPLOSIVE_CORRUPTION, 5s);
            events.ScheduleEvent(EVENT_CORRUPTING_BITE, 1500ms);
            events.ScheduleEvent(EVENT_WAVE_OF_CORRUPTION, 20s);
            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_MALIGNANT_GROWTH, 30s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (this->phase == 3 && me->GetPowerPct(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(nullptr, SPELL_GAZE_OF_GHUUN_MAIN, false);
            AddTimedDelayedOperation(2100, [this]() -> void
            {
                std::list<Player*> pl_li;
                me->GetPlayerListInGrid(pl_li, 100.0f);
                for (auto& frontTargets : pl_li)
                {
                    if (frontTargets->isInFront(me, 30.0f))
                        me->AddAura(SPELL_GAZE_OF_GHUUN_FEAR, frontTargets);
                }
            });
        }
        switch (eventId)
        {
        case EVENT_EXPLOSIVE_CORRUPTION:
        {
            DoCast(SPELL_EXPLOSIVE_CORRUPTION_TARGET_SELECTOR);
            events.Repeat(26s);
            break;
        }
        case EVENT_CORRUPTING_BITE:
        {
            DoCastVictim(SPELL_CORRUPTING_BITE_DAMAGE, true);
            me->AddAura(SPELL_GROWING_CORRUPTION);
            events.Repeat(1500ms);
            break;
        }
        case EVENT_WAVE_OF_CORRUPTION:
        {
            DoCast(SPELL_WAVE_OF_CORRUPTION_MAIN);
            waveOfCorruption++;
            if (this->waveOfCorruption >= 2)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->AddAura(SPELL_BLOOD_FEAST_ROOT, target);
                    if (this->phase != 3)
                        this->waveOfCorruption = 0;
                    AddTimedDelayedOperation(8500, [this, target]() -> void
                    {
                        std::list<Player*> pl_li;
                        target->GetPlayerListInGrid(pl_li, 8.5f);
                        for (auto& spreadTargets : pl_li)
                        {
                            target->CastSpell(spreadTargets, SPELL_BLOOD_FEAST_VISUAL_MISSILE, true);
                            me->CastSpell(spreadTargets, SPELL_PUTRID_BLOOD_PERIODIC_DUMMY, true);
                        }
                        me->SummonCreature(NPC_GIBBERING_HORROR, target->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                    });
                }
            }
            events.Repeat(30s);
            break;
        }
        case EVENT_MALIGNANT_GROWTH:
        {
            if (Is25ManRaid())
            {
                UnitList u_li;
                SelectTargetList(u_li, 15, SELECT_TARGET_RANDOM, 150.0f, true);
                for (Unit* targets : u_li)
                {
                    me->CastSpell(targets->GetPosition(), SPELL_MALIGNANT_GROWTH_MISSILE, true);
                }
            }
            else
            {
                UnitList u_li;
                SelectTargetList(u_li, 5, SELECT_TARGET_RANDOM, 150.0f, true);
                for (Unit* targets : u_li)
                {
                    me->CastSpell(targets->GetPosition(), SPELL_MALIGNANT_GROWTH_MISSILE, true);
                }
            }
            events.Repeat(40s);
            break;
        }
        case EVENT_BURSTING_BOIL:
        {
            for (uint8 i = 0; i < 3; i++)
            {
                me->CastSpell(me->GetRandomPoint(middle_pos, 30.0f), SPELL_BURSTING_BOIL_SUMMON, true);
            }
            events.Repeat(44s, 47s);
            break;
        }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendBossKillCredit(2122);
        Talk(SAY_DEATH);
        Talk(SAY_DEATH_WHISPER);
        CleanEncounter(instance, me);
        if (Creature* reoriginationDrive = me->FindNearestCreature(NPC_REORIGINATION_DRIVE, 150.0f, true))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, reoriginationDrive);
        if (IsMythic())
            instance->DoCompleteAchievement(ACHIEVEMENT_MYTHIC_GHUUN);
        instance->DoCompleteAchievement(ACHIEVEMENT_HEART_OF_CORRUPTION);
    }
};

//139910
struct npc_matrix_surge : public ScriptedAI
{
    npc_matrix_surge(Creature* creature) : ScriptedAI(creature) {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetWalk(true);
        me->GetSpeed(MOVE_WALK);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        AddTimedDelayedOperation(1500, [this]() -> void
        {            
            if (Unit* matrixHolder = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
            {
                me->AddAura(SPELL_MATRIX_SURGE);
                if (matrixHolder->HasAura(SPELL_POWER_MATRIX))
                    me->AddThreat(matrixHolder, 1000.0f, SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL);                
            }
            me->DespawnOrUnsummon(30s);
        });
    }
};

//141695
struct npc_bursting_boil : public ScriptedAI
{
    npc_bursting_boil(Creature* creature) : ScriptedAI(creature) {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
    }

    void Reset() override
    {
        ScriptedAI::Reset();       
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(nullptr, SPELL_BURSTING_BOIL_VISUAL);
        AddTimedDelayedOperation(8100, [this]() -> void
        {
            UnitList u_li;
            SelectTargetList(u_li, 2, SELECT_TARGET_RANDOM, 15.0f, true);
            for (Unit* targets : u_li)
            {
                me->CastSpell(targets, SPELL_BURSTING_BOIL_AURA, true);
                me->KillSelf();
            }
        });
    }
};

//134010
struct npc_gibbering_horror : public ScriptedAI
{
    npc_gibbering_horror(Creature* creature) : ScriptedAI(creature) { }

private:
    bool unstopabbleCorruption;

    void Reset() override
    {
        ScriptedAI::Reset();
        unstopabbleCorruption = false;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_MIND_NUMBED_CHATTER, 5s);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsInCombat())
            me->AI()->DoZoneInCombat(nullptr);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_MIND_NUMBED_CHATTER:
            me->CastSpell(nullptr, SPELL_MIND_NUMBED_CHATTER, false);
            events.Repeat(15s);
            break;
        }
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(2) && !me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
        {
            if (!unstopabbleCorruption)
            {
                me->AddAura(SPELL_UNSTOPABBLE_CORRUPTION);
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetHealth(me->GetMaxHealth() / 100 * 80);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            };
        }
    }
};

//141851
struct npc_spawn_of_ghuun : public ScriptedAI
{
    npc_spawn_of_ghuun(Creature* creature) : ScriptedAI(creature) { }

private:
    bool host_Targeted;

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void IsSummonedBy(Unit* summoner) override
    {
        host_Targeted = false;
        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0 , 100.0f, true))
        {
            me->AddAura(SPELL_DARK_PURPOSE);
            me->AddThreat(target, 1000.0f, SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL);
            me->GetMotionMaster()->MoveChase(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) <= 5.0f && !host_Targeted)
        {
            host_Targeted = true;
            if (host_Targeted && !unit->HasAura(SPELL_BLOOD_HOST))
            {
                me->AddAura(SPELL_BLOOD_HOST, unit);
                AddTimedDelayedOperation(20000, [this, unit]() -> void
                {
                    unit->CastSpell(nullptr, SPELL_BLOOD_HOST_MISSILE, true);
                });
                me->DespawnOrUnsummon();
            }
        }
    }
};

void AddSC_boss_ghuun()
{
    RegisterCreatureAI(boss_ghuun);
    RegisterCreatureAI(npc_amorphous_cyst);
    RegisterCreatureAI(npc_cyclopean_terror);
    RegisterCreatureAI(npc_power_matrix);
    RegisterSpellScript(spell_explosive_corruption_selector);
    RegisterSpellScript(spell_wave_of_corruption_selector);
    RegisterSpellScript(spell_power_matrix_cast);
    RegisterAuraScript(spell_explosive_corruption);
    RegisterPlayerScript(unclean_corruption);
    RegisterAreaTriggerAI(areatrigger_undulating_mass);
    RegisterAreaTriggerAI(areatrigger_blighted_corruption);
    RegisterAreaTriggerAI(areatrigger_virulent_corruption);
    RegisterCreatureAI(npc_reorigination_drive);
    RegisterCreatureAI(boss_ghuun_non_static);
    RegisterCreatureAI(npc_blightspreader_tendril);
    RegisterCreatureAI(npc_matrix_surge);
    RegisterCreatureAI(npc_bursting_boil);
    RegisterCreatureAI(npc_gibbering_horror);
    RegisterCreatureAI(npc_spawn_of_ghuun);
}
