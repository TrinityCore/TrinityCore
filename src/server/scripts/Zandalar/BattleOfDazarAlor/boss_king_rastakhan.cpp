#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PhasingHandler.h"
#include "battle_of_dazaralor.h"

enum Spells
{
    SPELL_BIND_SOULS = 284276,
    SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA = 284831, //289915
    SPELL_SCORCHING_DETONATION_EXPLOSION = 284846,
    SPELL_PLAGUE_TOADS_CAST = 284933,
    SPELL_PLAGUE_OF_FIRE_CAST = 285346,
    SPELL_PLAGUE_OF_FIRE_AURA = 285349,
    SPELL_PLAGUE_OF_FIRE_MISSILE = 285347,
    SPELL_ZOMBIE_DUST_TOTEM_SUMMON = 285003, //npc 146731
    SPELL_ZOMBIE_DUST_MIND_CONTROL = 284995,
    SPELL_DEATHS_PRESENCE = 284376,
    SPELL_DREAD_REAPING_CREATE_AT = 287116,
    SPELL_DREAD_REAPING_AT_DAMAGE = 287147,
    SPELL_DREAD_REAPING_PORTAL_VISUAL = 287109,
    SPELL_INEVITABLE_END_PULL_CREATE_AT = 287333,
    SPELL_INEVITABLE_END_INSTAKILL = 288576,
    SPELL_UNLIVING_PASSIVE = 284377,    
    SPELL_AURA_OF_DEATH_MAIN = 289924,
    SPELL_AURA_OF_DEATH = 285190,
    SPELL_CARESS_OF_DEATH = 285213,
    SPELL_DEATHS_DOOR_DEBUFF = 288449,
    SPELL_DEATH_RIFT_CREATE_AT = 288048, // 148351, at custom 40019
    SPELL_BWONSAMDIS_BOON = 284446,
    SPELL_BWONSAMDIS_BOON_BUFF = 289169, // script on apply, ever 15s addstack
    SPELL_WITHERING_BURST_DAMAGE = 288053,
    SPELL_UNDYING_RELENTLESSNESS = 289162,    
    SPELL_ALL_ENCOMPASSING_DEATH = 289890,
    SPELL_SPIRIT_EXPULSION = 284521,
    SPELL_DEATHLY_WITHERING = 285195,
    SPELL_SEAL_OF_BWONSAMDI_MISSILE = 286669,
    SPELL_SEAL_OF_BWONSAMDI_CREATE_AT = 286664,
    SPELL_SEAL_OF_BWONSAMDI_DAMAGE = 286671, //script on hit
    SPELL_BWONSAMDIS_WRATH = 286672, 
    SPELL_PLAGUE_OF_TOAD_JUMP = 284917,
    SPELL_PLAGUE_OF_TOAD_CREATE_AT = 284918,
    SPELL_PLAGUE_OF_TOAD_PERSONAL_AT = 285041,
    SPELL_TOAD_TOXIN = 285044,
    //Heroic
    SPELL_GRIEVOUS_AXE = 290955,
    SPELL_GREATER_SERPENT_TOTEM_SUMMON = 285172, //146766
    SPELL_SERPENTS_BREATH = 285178,
    SPELL_POISON_TOAD_SLIME_AT_DAMAGE = 285010, // used for toads
    //Mythic
    SPELL_FOCUSED_DEMISE = 286779,
};

enum ACtions
{
    ACTION_PHASE_TWO = 1,
    ACTION_PHASE_THREE,
    ACTION_PHASE_FOUR
};

enum MiniBosses
{
    SPELL_CRUSHING_LEAP_JUMP = 284719,
    SPELL_CRUSHING_LEAP_DAMAGE = 284730,
    SPELL_METEOR_LEAP = 284686,
    SPELL_METEOR_LEAP_DAMAGE = 284688,
    SPELL_CRUSHED = 289858,
    SEAL_OF_PURIFICATION_CREATE_AT = 286537,
    SPELL_SEAL_OF_PURIFICATION_DAMAGE = 290448,
};

bool IsInLivingRealm;
bool IsINDeathRealm;

//145616
struct boss_king_rastakhan : public BossAI
{
    boss_king_rastakhan(Creature* creature) : BossAI(creature, DATA_KING_RASTAKHAN) { }

private:    
    Creature* GetBwonsamdi() { return me->FindNearestCreature(NPC_BWONSAMDI_ENCOUNTER, 150.0f, true); }
    uint8 phase;
    bool at10;

    void Reset() override
    {
        BossAI::Reset();
        //me->AddUnitState(UNIT_STAND_STATE_SIT_HIGH_CHAIR);
        if (Creature* bwonsamdi = me->FindNearestCreature(100.0f, true))
            bwonsamdi->ClearUnitState(UNIT_STAND_STATE_SIT_HIGH_CHAIR);
        me->SetReactState(REACT_DEFENSIVE);
        me->SetVisible(true);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);        
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
        me->SetReactState(REACT_PASSIVE);
        this->phase = 0;
        if (IsHeroic() || IsMythic())
            me->SummonCreature(NPC_HEADHUNTER_GALWANA, -1232.223f, 807.1162f, 351.649f, 0.051f, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (me->HealthBelowPct(60) && this->phase == 2)
        {
            this->phase = 3;
            DoAction(ACTION_PHASE_THREE);
        }
        if (me->HealthBelowPct(10) && !at10)
        {
            at10 = true;
            Talk(7);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer() && roll_chance_f(15))
            Talk(8);
    }
    
    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_REAPING_PORTAL:
            summon->CastSpell(nullptr, SPELL_DREAD_REAPING_CREATE_AT, true);
            summon->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            break;

        case NPC_PHANTOM_OF_RAGE:
        case NPC_PHANTOM_OF_RETRIBUTION:
        case NPC_HEADHUNTER_GALWANA:
            summon->AddAura(SPELL_UNDYING_RELENTLESSNESS);
            break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_PHASE_TWO:
            if (this->phase == 1)
            {
                me->Say("PHASE TWO", LANG_UNIVERSAL);
                events.Reset();
                this->phase = 2;
                Talk(4);
                me->SummonCreature(NPC_BWONSAMDI_ENCOUNTER, -1254.939f, 805.260f, 359.227f, 6.222f, TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA, 7s);
                events.ScheduleEvent(SPELL_PLAGUE_TOADS_CAST, 10s);
                events.ScheduleEvent(SPELL_ZOMBIE_DUST_TOTEM_SUMMON, 15s);
                events.ScheduleEvent(SPELL_PLAGUE_OF_FIRE_CAST, 20s);
            }
            break;

        case ACTION_PHASE_THREE:
            me->Say("PHASE THREE", LANG_UNIVERSAL);
            events.Reset();
            this->phase = 3;
            Talk(5);
            if (Creature* bwonsamdi = GetBwonsamdi())
            {
                bwonsamdi->RemoveAura(SPELL_UNLIVING_PASSIVE);
                bwonsamdi->CastSpell(me, SPELL_BWONSAMDIS_BOON, false);                
                me->GetScheduler().Schedule(5300ms, [this](TaskContext context)
                {
                    me->AddAura(SPELL_BWONSAMDIS_BOON_BUFF);
                    me->AddAura(SPELL_ALL_ENCOMPASSING_DEATH);
                    me->SetDisplayId(me->GetNativeDisplayId());
                });
                bwonsamdi->GetScheduler().Schedule(6000ms, [bwonsamdi](TaskContext context)
                {
                    bwonsamdi->AI()->Talk(1);
                });
            }
            events.ScheduleEvent(SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA, 7s);
            events.ScheduleEvent(SPELL_PLAGUE_TOADS_CAST, 10s);
            events.ScheduleEvent(SPELL_ZOMBIE_DUST_TOTEM_SUMMON, 15s);
            events.ScheduleEvent(SPELL_PLAGUE_OF_FIRE_CAST, 20s);
            me->SummonCreature(NPC_PHANTOM_OF_RAGE, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_PHANTOM_OF_RETRIBUTION, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case ACTION_PHASE_FOUR:
            if (this->phase == 3)
            {
                me->Say("PHASE FOUR", LANG_UNIVERSAL);
                events.Reset();
                this->phase = 4;
                Talk(6);
                if (Creature* bwonsamdi = GetBwonsamdi())
                {
                    bwonsamdi->GetScheduler().Schedule(6000ms, [bwonsamdi](TaskContext context)
                    {
                        bwonsamdi->AI()->Talk(3);
                    });
                }
                events.ScheduleEvent(SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA, 7s);
                events.ScheduleEvent(SPELL_PLAGUE_TOADS_CAST, 10s);
                events.ScheduleEvent(SPELL_PLAGUE_OF_FIRE_CAST, 20s);
                events.ScheduleEvent(SPELL_DEATHS_DOOR_DEBUFF, 30s);
                events.ScheduleEvent(SPELL_INEVITABLE_END_PULL_CREATE_AT, 40s);
                events.ScheduleEvent(SPELL_DREAD_REAPING_CREATE_AT, 50s);
            }
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
        {
            Talk(0);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetInCombatWithZone();
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        this->phase = 1;
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(SPELL_GREATER_SERPENT_TOTEM_SUMMON, 5s);
        events.ScheduleEvent(SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA, 7s);
        events.ScheduleEvent(SPELL_PLAGUE_TOADS_CAST, 10s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_PLAGUE_OF_FIRE_CAST:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : tarlist)
            {
                me->CastSpell(targets, SPELL_PLAGUE_OF_FIRE_AURA, true);
            }
            break;
        }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA:
            Talk(1);
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.f, true))      
            {
                me->CastSpell(target, SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA, false);
                target->GetScheduler().Schedule(5100ms, [this, target](TaskContext context)
                {
                    if (target)
                        return;

                    me->CastSpell(target, SPELL_SCORCHING_DETONATION_EXPLOSION, true);
                });
            }
            events.Repeat(20s);
            break;

        case SPELL_GREATER_SERPENT_TOTEM_SUMMON:
            me->CastSpell(nullptr, SPELL_GREATER_SERPENT_TOTEM_SUMMON, false);
            events.Repeat(18s);
            break;

        case SPELL_PLAGUE_TOADS_CAST:
            Talk(2);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
            {
                me->SetFacingToObject(target, true);
                me->CastSpell(target->GetPosition(), SPELL_PLAGUE_TOADS_CAST, false);
            }
            events.Repeat(25s);
            break;

        case SPELL_PLAGUE_OF_FIRE_CAST:
            Talk(3);
            me->CastSpell(nullptr, SPELL_PLAGUE_OF_FIRE_CAST, false);
            events.Repeat(30s);
            break;

        case SPELL_ZOMBIE_DUST_TOTEM_SUMMON:
            me->CastSpell(nullptr, SPELL_ZOMBIE_DUST_TOTEM_SUMMON, true);
            events.Repeat(40s);
            break;

        case SPELL_DEATHS_DOOR_DEBUFF:
            DoCastRandom(SPELL_DEATHS_DOOR_DEBUFF, 100.0f, true);
            events.Repeat(50s);
            break;

        case SPELL_INEVITABLE_END_PULL_CREATE_AT:
        {
            me->CastSpell(nullptr, SPELL_INEVITABLE_END_PULL_CREATE_AT, false);
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (auto& targets : playerList)
            {
                /*targets->AddUnitState(UNIT_STATE_LOST_CONTROL);
                targets->SetWalk(true);
                targets->GetMotionMaster()->MovePoint(0, me->GetPosition(), true);*/
            }
            events.Repeat(60s);
            break;
        }

        case SPELL_DREAD_REAPING_CREATE_AT:
            events.Repeat(70s);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade(15s);
        if (auto* siegebreakerRoka = me->FindNearestCreature(NPC_SIEGEBREAKER_ROKA, 100.0f, false))
            siegebreakerRoka->ForcedDespawn(0, 15s);
        if (auto* prelateZalan = me->FindNearestCreature(NPC_PRELATE_ZALAN, 100.0f, false))
            prelateZalan->ForcedDespawn(0, 15s);
        if (auto* headhunterGalwana = me->FindNearestCreature(NPC_HEADHUNTER_GALWANA, 100.0f, false))
            headhunterGalwana->ForcedDespawn(0, 15s);
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
        Talk(9);
        if (IsMythic())
            instance->DoCompleteAchievement(13311);
        me->GetScheduler().Schedule(10s, [this](TaskContext /*context*/)
        {
            instance->DoStartMovie(MOVIE_RASTAKHAN_DEATH);
        });
        if (auto* door = me->FindNearestGameObject(GO_RASTAKHAN_DOOR_EXIT_TO_PORT_OF_ZANDALAR, 200.0f))
            door->SetGoState(GO_STATE_ACTIVE);
        //Rastakhan and Talanji for raid quest
        if (auto* rastakhan = me->FindNearestCreature(147012, 100.0f))
            PhasingHandler::RemovePhase(rastakhan, 200, true);
        if (auto* talanji = me->FindNearestCreature(147383, 200.0f))
            PhasingHandler::RemovePhase(talanji, 200, true);
    };
};

//146322,146320,146326
struct npc_king_rastakhan_minion : public ScriptedAI
{
    npc_king_rastakhan_minion(Creature* c) : ScriptedAI(c) { }

private:
    Creature* GetRastakhan() { return me->FindNearestCreature(NPC_KING_RASTAKHAN, 150.0f, true); }
    Creature* GetMe() { return me->FindNearestCreature(NPC_SIEGEBREAKER_ROKA, 150.0f, false), me->FindNearestCreature(NPC_PRELATE_ZALAN, 150.0f, false); }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_SIEGEBREAKER_ROKA:
            ScriptedAI::Reset();
            me->SetReactState(REACT_DEFENSIVE);            
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 100);
            break;

        case NPC_PRELATE_ZALAN:
            ScriptedAI::Reset();
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 100);
            break;

        case NPC_HEADHUNTER_GALWANA:
            ScriptedAI::Reset();
            me->SetReactState(REACT_DEFENSIVE);
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 100);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_METEOR_LEAP_DAMAGE:
            target->AddAura(SPELL_CRUSHED);
            break;

        case SPELL_CRUSHING_LEAP_DAMAGE:
            target->AddAura(SPELL_CRUSHED);
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_SIEGEBREAKER_ROKA:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (Creature* zalan = me->FindNearestCreature(NPC_PRELATE_ZALAN, 100.0f, true))
                if (!zalan->IsInCombat())
                    zalan->SetInCombatWithZone();
            if (Creature* rastakhan = GetRastakhan())
            {
                rastakhan->AI()->Talk(0);
                rastakhan->AddAura(SPELL_BIND_SOULS);
                rastakhan->SetWalk(true);
                rastakhan->GetMotionMaster()->MovePoint(1, -1232.270f, 805.715f, 351.649f, 0.000f);
            }
            events.ScheduleEvent(SPELL_METEOR_LEAP, 5s);
            break;

        case NPC_PRELATE_ZALAN:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(SEAL_OF_PURIFICATION_CREATE_AT, 5s);
            break;

        case NPC_HEADHUNTER_GALWANA:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(SPELL_GRIEVOUS_AXE, 5s);
            break;
        }
    }


    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_METEOR_LEAP:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.f, true))
                me->CastSpell(target, SPELL_CRUSHING_LEAP_JUMP, true);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_METEOR_LEAP:
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.f, true))
                me->CastSpell(target, SPELL_METEOR_LEAP, false);
            events.Repeat(25s);
            break;
        case SEAL_OF_PURIFICATION_CREATE_AT:
            me->CastSpell(nullptr, SEAL_OF_PURIFICATION_CREATE_AT, true);
            events.Repeat(30s);
            break;

        case SPELL_GRIEVOUS_AXE:
            DoCastRandom(SPELL_GRIEVOUS_AXE, 50.0f, false);
            events.Repeat(15s, 20s);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_SIEGEBREAKER_ROKA:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;

        case NPC_PRELATE_ZALAN:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;

        case NPC_HEADHUNTER_GALWANA:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {        
        switch (me->GetEntry())
        {
        case NPC_SIEGEBREAKER_ROKA:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;

        case NPC_PRELATE_ZALAN:
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;
        }
        if (Creature* Get = GetMe())
            if (Creature* rastakhan = GetRastakhan())
                rastakhan->AI()->DoAction(ACTION_PHASE_TWO);
    }
};

//20000, 286537
struct at_seal_of_purification : public AreaTriggerAI
{
    at_seal_of_purification(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position movePos = caster->GetPosition();
        at->MovePosition(movePos, 30.0f, 0.0f);
        at->SetDestination(movePos, 10000);
        at->SetDuration(10000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(SPELL_SEAL_OF_PURIFICATION_DAMAGE))
            at->GetCaster()->AddAura(SPELL_SEAL_OF_PURIFICATION_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(SPELL_SEAL_OF_PURIFICATION_DAMAGE))
            unit->RemoveAura(SPELL_SEAL_OF_PURIFICATION_DAMAGE);
    }
};

//20024, 287116
struct at_dread_reaping : public AreaTriggerAI
{
    at_dread_reaping(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position moveRandom = at->GetRandomNearPosition(30.0f);
        at->MovePosition(moveRandom, 30.0f, 0.0f);
        at->SetDestination(moveRandom, 10000);
    }

    void OnDestinationReached() override
    { 
        Position moveRandom = at->GetRandomNearPosition(30.0f);
        at->MovePosition(moveRandom, 30.0f, 0.0f);
        at->SetDestination(moveRandom, 10000);
    }

    void OnCreate() override
    {
        at->SetDuration(300000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(SPELL_DREAD_REAPING_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_DREAD_REAPING_AT_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(SPELL_DREAD_REAPING_AT_DAMAGE))
            unit->RemoveAura(SPELL_DREAD_REAPING_AT_DAMAGE);
    }
};

//20025, 287333
struct at_inevitable_end_pull : public AreaTriggerAI
{
    at_inevitable_end_pull(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            unit->ClearUnitState(UNIT_STATE_LOST_CONTROL);
            unit->CastSpell(unit, SPELL_INEVITABLE_END_INSTAKILL);
        }
    }
};

//285349
class aura_plague_of_fire : public AuraScript
{
    PrepareAuraScript(aura_plague_of_fire);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        std::list<Player*> playerList;
        GetTarget()->GetPlayerListInGrid(playerList, 7.5f);
        if (playerList.size() > 1)
        {
            for (auto& targets : playerList)
            {
                if (!targets->IsGameMaster())
                    GetTarget()->CastSpell(targets, SPELL_PLAGUE_OF_FIRE_MISSILE, true);
            }
        }
        else
            GetTarget()->RemoveAurasDueToSpell(SPELL_PLAGUE_OF_FIRE_AURA);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_plague_of_fire::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//145644
struct boss_bwonsamdi : public ScriptedAI
{
    boss_bwonsamdi(Creature* c) : ScriptedAI(c) { }

private:
    Creature* GetRastakhan() { return me->FindNearestCreature(NPC_KING_RASTAKHAN, 150.0f, true); }
    bool IsInPhaseFour;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_DEFENSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
        me->AddAura(SPELL_UNLIVING_PASSIVE);
        me->AddAura(SPELL_AURA_OF_DEATH_MAIN);
        me->SetHover(true);
        IsInPhaseFour = false;
    }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!me->IsInCombat())
            return;
        
        if (target->IsPlayer() && target->GetDistance2d(me) <= 30.0f && !target->HasAura(SPELL_AURA_OF_DEATH))
        {
            me->AddAura(SPELL_AURA_OF_DEATH, target);
            target->GetScheduler().Schedule(100ms, [this, target](TaskContext context)
            {
                if (!target)
                    return;

                me->AddAura(SPELL_DEATHLY_WITHERING, target);
                if (target->HasAura(SPELL_AURA_OF_DEATH))
                    context.Repeat(3s);
            });
        }

        if (target->IsPlayer() && target->GetDistance2d(me) >= 30.0f && target->HasAura(SPELL_AURA_OF_DEATH))
        {
            target->RemoveAura(SPELL_AURA_OF_DEATH);
            target->RemoveAura(SPELL_DEATHLY_WITHERING);
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(nullptr, SPELL_DEATHS_PRESENCE, true);
        instance->DoAddAuraOnPlayers(SPELL_DEATHS_PRESENCE);
        if (summoner->GetEntry() == NPC_KING_RASTAKHAN)
            AddTimedDelayedOperation(5500, [this]() -> void
            {
                Talk(0);
            });
        AddTimedDelayedOperation(12000, [this]() -> void
        {
            me->NearTeleportTo(-1232.270f, 805.715f, 351.649f, 0.000f);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
            me->SetInCombatWithZone();
        });
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (me->HasAura(SPELL_UNLIVING_PASSIVE))
        {
            damage = 0;
            me->SetHealth(me->GetMaxHealth());
        }
        if (me->HealthBelowPct(50) && !IsInPhaseFour)
        {
            IsInPhaseFour = true;
            events.Reset();
            if (Creature* rastakhan = GetRastakhan())
                rastakhan->AI()->DoAction(ACTION_PHASE_FOUR);
            events.ScheduleEvent(SPELL_CARESS_OF_DEATH, 7s);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(SPELL_AURA_OF_DEATH_MAIN, 100s);
        events.ScheduleEvent(SPELL_CARESS_OF_DEATH, 7s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_AURA_OF_DEATH_MAIN:
            me->AddAura(SPELL_AURA_OF_DEATH_MAIN);
            break;
        case SPELL_CARESS_OF_DEATH:
            if (roll_chance_f(15))
                Talk(2);
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                me->CastSpell(target, SPELL_CARESS_OF_DEATH, false);
            events.Repeat(20s);
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

//288449
class aura_deaths_door : public AuraScript
{
    PrepareAuraScript(aura_deaths_door);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
            GetTarget()->SummonCreature(NPC_DEATH_RIFT, GetTarget()->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_deaths_door::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);        
    }
};

enum
{
    SPELL_NECROTIC_SMASH = 286742,
    SPELL_GRAVE_BOLT = 285572,
};

//146492,146491,146493
struct npc_phantom_generic : public ScriptedAI
{
    npc_phantom_generic(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_PHANTOM_OF_RAGE:
            events.ScheduleEvent(SPELL_NECROTIC_SMASH, 5s);
            break;

        case NPC_PHANTOM_OF_RETRIBUTION:
            events.ScheduleEvent(SPELL_GRAVE_BOLT, 5s);
            break;

        case NPC_PHANTOM_OF_SLAUGHTER:
            events.ScheduleEvent(SPELL_FOCUSED_DEMISE, 5s);
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SEAL_OF_BWONSAMDI:
            summon->CastSpell(me->GetPosition(), SPELL_SEAL_OF_BWONSAMDI_MISSILE, true);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_NECROTIC_SMASH:
            DoCastVictim(SPELL_NECROTIC_SMASH, false);
            events.Repeat(15s, 20s);
            break;
        case SPELL_GRAVE_BOLT:
            DoCastRandom(SPELL_GRAVE_BOLT, 80.0f, false);
            events.Repeat(15s, 20s);
            break;
        case SPELL_SEAL_OF_BWONSAMDI_MISSILE:
            me->SummonCreature(NPC_SEAL_OF_BWONSAMDI, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case SPELL_FOCUSED_DEMISE:
            DoCastRandom(SPELL_FOCUSED_DEMISE, 50.0f, false);
            events.Repeat(15s, 20s);
            break;
        }
    }
};

//146731,146766
struct npc_king_rastakhan_static_generic : public ScriptedAI
{
    npc_king_rastakhan_static_generic(Creature* c) : ScriptedAI(c) 
    { 
        SetCombatMovement(false);
    }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_ZOMBIE_DUST_TOTEM:
            ScriptedAI::Reset();
            break;

        case NPC_GREATER_SERPENT_TOTEM:
            ScriptedAI::Reset();
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_ZOMBIE_DUST_TOTEM:
            events.ScheduleEvent(SPELL_ZOMBIE_DUST_MIND_CONTROL, 5s);
            break;

        case NPC_GREATER_SERPENT_TOTEM:
            events.ScheduleEvent(SPELL_SERPENTS_BREATH, 5s);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_ZOMBIE_DUST_MIND_CONTROL:
            DoCastRandom(SPELL_ZOMBIE_DUST_MIND_CONTROL, 100.0f, false);
            events.Repeat(20s, 25s);
            break;

        case SPELL_SERPENTS_BREATH:
            DoCastRandom(SPELL_SERPENTS_BREATH, 30.0f, false);
            events.Repeat(20s, 25s);
            break;
        }
    }
};

//146695,146698,146700
struct npc_plague_toad : public ScriptedAI
{
    npc_plague_toad(Creature* c) : ScriptedAI(c)
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

private:
    uint8 jumpCount;

    void Reset() override
    {
        me->CastSpell(nullptr, SPELL_PLAGUE_OF_TOAD_PERSONAL_AT, true);
        me->GetScheduler().Schedule(1500ms, [this](TaskContext context)
        {
            Position AreatriggerPos = me->GetPositionX() + 10.0f;  
            jumpCount++;
            me->CastSpell(AreatriggerPos, SPELL_PLAGUE_OF_TOAD_JUMP, true);
            if (IsHeroic() || IsMythic())
                me->CastSpell(AreatriggerPos, SPELL_PLAGUE_OF_TOAD_CREATE_AT, true);
            if (this->jumpCount = !3)
                context.Repeat(2s);
        });
    }
};

//40022, 285041, personal
struct at_plague_of_toads_personal : public AreaTriggerAI
{
    at_plague_of_toads_personal(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        return;

        if (unit->IsPlayer() && !unit->HasAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        return;

        if (unit->IsPlayer() && unit->HasAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE))
            unit->RemoveAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE);
    }
};

//40021, 284918, pool, at_plague_of_toads_pool
struct at_plague_of_toads_pool : public AreaTriggerAI
{
    at_plague_of_toads_pool(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE))
            unit->RemoveAura(SPELL_POISON_TOAD_SLIME_AT_DAMAGE);
    }
};

//289169
class aura_bwonsamdis_toon : public AuraScript
{
    PrepareAuraScript(aura_bwonsamdis_toon);

    void OnApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetTarget())
            {
                target->GetScheduler().Schedule(100ms, [target](TaskContext context)
                {
                    if (!target)
                        return;

                    target->AddAura(SPELL_BWONSAMDIS_BOON_BUFF);

                    context.Repeat(3s);
                });
            }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_bwonsamdis_toon::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

//40019, 288048, 148351
struct at_death_rift : public AreaTriggerAI
{
    at_death_rift(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (unit->HasAura(SPELL_DEATHLY_WITHERING))
        {
            unit->RemoveAurasDueToSpell(SPELL_DEATHLY_WITHERING);
            at->GetCaster()->CastSpell(unit->GetPosition(), SPELL_WITHERING_BURST_DAMAGE, true);
        }
    }
};

void AddSC_boss_king_rastakhan()
{
    RegisterCreatureAI(boss_king_rastakhan);
    RegisterCreatureAI(npc_king_rastakhan_minion);
    RegisterAreaTriggerAI(at_seal_of_purification);
    RegisterAreaTriggerAI(at_dread_reaping);
    RegisterAreaTriggerAI(at_inevitable_end_pull);
    RegisterAuraScript(aura_plague_of_fire);
    RegisterCreatureAI(boss_bwonsamdi);
    RegisterAuraScript(aura_deaths_door);
    RegisterCreatureAI(npc_phantom_generic);
    RegisterCreatureAI(npc_king_rastakhan_static_generic);
    RegisterCreatureAI(npc_plague_toad);
    RegisterAreaTriggerAI(at_plague_of_toads_personal);
    RegisterAreaTriggerAI(at_plague_of_toads_pool);
    RegisterAuraScript(aura_bwonsamdis_toon);
    RegisterAreaTriggerAI(at_death_rift);
}
