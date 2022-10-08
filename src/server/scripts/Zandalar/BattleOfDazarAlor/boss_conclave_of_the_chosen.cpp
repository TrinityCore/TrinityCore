#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "battle_of_dazaralor.h"
// ||

enum Texts
{
    //Paku
    SAY_PAKU_AGGRO = 0,
    SAY_PAKU_GIFT_OF_WIND,
    SAY_PAKU_DEATH,
    //Gonk
    SAY_GONK_RAPTORM_FORM = 0,
    SAY_GONK_CRAWLING_HEX,
    SAY_GONG_DEATH,
    //Kimbul
    SAY_KIMBUL_LACERATING_CLAWS = 0,
    SAY_KIMBUL_DEATH,
    //Akunda
    SAY_AKUNDA_THUNDERING_STORM = 0,
    SAY_AKUNDA_DEATH,
    //BWONSAMDI
    SAY_BWONSAMDIS_WRATH = 0
};

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_LOAS_WRATH = 282736,
    SPELL_LOAS_PACT = 282079,
    SPELL_HASTENING_WIND = 285945,
    SPELL_GIFT_OF_WIND = 282098,
    SPELL_PAKUS_WRATH = 282107,
    SPELL_WILD_MAUL = 285893,
    SPELL_CRAWLING_HEX = 282135,
    SPELL_GONKS_WRATH = 282155,
    SPELL_LACERATING_CLAWS = 282444,
    SPELL_BLEEDING_WOUNDS = 282592,
    SPELL_KIMBULS_WRATH_JUMP = 283508,
    SPELL_THUNDERING_STORM = 282411,
    SPELL_MIND_WIPE_SPAWN_EFFECT = 286708,
    SPELL_MIND_WIPE_PACIFY_SILENCE = 285879,
    SPELL_AKUNDAS_WRATH = 286811,
    SPELL_AKUNDAS_WRAT_EXP = 286821,
    SPELL_STATIC_ORB_CREATE_AT = 286833,
    //Heroic
    SPELL_CRY_OF_THE_FALLEN = 286060,
    SPELL_PACK_HUNTER = 286007,
    SPELL_KRAGWAS_WRATH_MAIN = 282636,
    //Mythic
    SPELL_BWONSAMDIS_WRATH = 284663,
};

enum Events
{
    EVENT_HASTENING_WIND = 1,
    EVENT_GIFT_OF_THE_WIND,
    EVENT_PAKUS_WRATH,

    EVENT_RAPTOR_FORM,
    EVENT_CRAWLING_HEX,
    EVENT_GONKS_WRATH,

    EVENT_LACERATING_CLAWS,
    EVENT_KIMBULS_WRATH,

    EVENT_THUNDERING_STORM,
    EVENT_MIND_WIPE,
    EVENT_AKUNDAS_WRATH,
    //Heroic
    EVENT_CRY_OF_THE_FALLEN,
    EVENT_KRAGWA,
    //Mythic
    EVENT_BWONSAMDIS_WRATH,
};

const Position middle_of_the_room = { -1095.421f, 804.986f, 203.865f, 1.53f };
const Position pakku_pos = { -1078.854f, 766.060f, 204.249f, 1.91f };

//144767,144747,144963,144941
struct boss_conclave_of_the_chosen : public BossAI
{
    boss_conclave_of_the_chosen(Creature* creature) : BossAI(creature, DATA_CONCLAVE) { }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_GONK:
            BossAI::Reset();
            me->SetPowerType(POWER_ENERGY);
            me->SetPower(POWER_ENERGY, 0);
            me->SetObjectScale(me->GetNativeDisplayScale());
            break;

        case NPC_PAKU:
            BossAI::Reset();
            break;

        case NPC_KIMBUL:
            BossAI::Reset();
            break;

        case NPC_AKUNDA:
            BossAI::Reset();
            break;
        }
    }

    void ResetEncounter()
    {
        me->DespawnCreaturesInArea(NPC_RAVENOUS_STALKER, 125.0f);
        std::list<Creature*> encounterNPCs;
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_PAKU, 100.0f);
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_GONK, 100.0f);
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_KIMBUL, 100.0f);
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_AKUNDA, 100.0f);
        for (auto& minions : encounterNPCs)
        {
            minions->AI()->JustReachedHome();
            minions->NearTeleportTo(minions->GetHomePosition());
            minions->ForcedDespawn(100, 15s);
        }

        if (auto* conclaveExit = me->FindNearestGameObject(GO_ENCLAVE_DOOR_ENTRANCE, 125.0f))
            conclaveExit->SetGoState(GO_STATE_ACTIVE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GONK:
            ResetEncounter();
            break;

        case NPC_PAKU:
            ResetEncounter();
            break;

        case NPC_KIMBUL:
            ResetEncounter();
            break;

        case NPC_AKUNDA:
            ResetEncounter();
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GONK:
            _EnterCombat();
            DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_RAPTOR_FORM, 15s);            
            if (auto* paku = me->FindNearestCreature(NPC_PAKU, 125.0f, true))
                if (!paku->IsInCombat())
                    paku->AI()->DoZoneInCombat();

            if (auto* conclaveExit = me->FindNearestGameObject(GO_ENCLAVE_DOOR_ENTRANCE, 125.0f))
                conclaveExit->SetGoState(GO_STATE_READY);
            break;

        case NPC_PAKU:
            Talk(SAY_PAKU_AGGRO);
            _EnterCombat();

            if (auto* gonk = me->FindNearestCreature(NPC_GONK, 125.0f, true))
                if (!gonk->IsInCombat())
                    gonk->AI()->DoZoneInCombat();

            if (auto* conclaveExit = me->FindNearestGameObject(GO_ENCLAVE_DOOR_ENTRANCE, 125.0f))
                conclaveExit->SetGoState(GO_STATE_READY);

            events.ScheduleEvent(EVENT_HASTENING_WIND, 15ms);
            events.ScheduleEvent(EVENT_GIFT_OF_THE_WIND, 18s);
            events.ScheduleEvent(EVENT_PAKUS_WRATH, 20s);
            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_KRAGWA, 35s);
            if (IsMythic())
                events.ScheduleEvent(EVENT_BWONSAMDIS_WRATH, 50s);
            break;

        case NPC_KIMBUL:
            _EnterCombat();
            events.ScheduleEvent(EVENT_LACERATING_CLAWS, 15s);
            events.ScheduleEvent(EVENT_KIMBULS_WRATH, 20s);
            break;

        case NPC_AKUNDA:
            _EnterCombat();
            events.ScheduleEvent(EVENT_THUNDERING_STORM, 15s);
            events.ScheduleEvent(EVENT_MIND_WIPE, 20s);
            events.ScheduleEvent(EVENT_AKUNDAS_WRATH, 25s);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetEntry() == NPC_GONK && me->GetPowerPct(POWER_ENERGY) == 100)
        {
            me->ModifyPower(POWER_ENERGY, -75);
            events.ScheduleEvent(EVENT_GONKS_WRATH, 100ms);
        }

        switch (eventId)
        {
        case EVENT_HASTENING_WIND:
            me->AddAura(SPELL_HASTENING_WIND);
            events.Repeat(2s);
            break;

        case EVENT_GIFT_OF_THE_WIND:
            Talk(SAY_PAKU_GIFT_OF_WIND);
            instance->DoAddAuraOnPlayers(SPELL_GIFT_OF_WIND);
            events.Repeat(15s, 18s);
            break;

        case EVENT_PAKUS_WRATH:
            me->SummonCreature(NPC_PAKU_MINION, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(30s);
            break;

        case EVENT_RAPTOR_FORM:
            Talk(SAY_GONK_RAPTORM_FORM);
            me->SetDisplayId(80358);
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_WILD_MAUL, false);
                me->SetDisplayId(me->GetNativeDisplayId());
                me->SetObjectScale(me->GetNativeDisplayScale());
            }
            events.Repeat(15s, 18s);
            break;

        case EVENT_CRAWLING_HEX:
        {
            Talk(SAY_GONK_CRAWLING_HEX);
            UnitList tar_li;
            SelectTargetList(tar_li, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* target : tar_li)
            {
                me->CastSpell(target, SPELL_CRAWLING_HEX, true);
                target->SetDisplayId(48056);
                target->GetScheduler().Schedule(6s, [this, target](TaskContext context)
                {
                    target->DeMorph();
                });
            }
            events.Repeat(50s);
        }
        break;

        case EVENT_GONKS_WRATH:
            me->SummonCreature(NPC_GONK_MINION, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(60s);
            break;

        case EVENT_LACERATING_CLAWS:
            Talk(SAY_KIMBUL_LACERATING_CLAWS);
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_LACERATING_CLAWS, true);
            }
            events.Repeat(20s);
            break;

        case EVENT_KIMBULS_WRATH:
            me->SummonCreature(NPC_KIMBUL_MINION, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(60s);
            break;


        case EVENT_THUNDERING_STORM:
            Talk(SAY_AKUNDA_THUNDERING_STORM);
            me->CastSpell(nullptr, SPELL_THUNDERING_STORM, false);
            events.Repeat(20s);
            break;

        case EVENT_MIND_WIPE:
        {
            UnitList tar_li;
            SelectTargetList(tar_li, 2, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* target : tar_li)
            {
                me->CastSpell(target, SPELL_MIND_WIPE_SPAWN_EFFECT, true);
                me->CastSpell(target, SPELL_MIND_WIPE_PACIFY_SILENCE, true);
            }
            events.Repeat(50s);
        }
        break;

        case EVENT_AKUNDAS_WRATH:
            me->SummonCreature(NPC_AKUNDA_MINION, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(60s);
            break;

        case EVENT_CRY_OF_THE_FALLEN:
        {
            instance->DoAddAuraOnPlayers(SPELL_CRY_OF_THE_FALLEN);
        }
        break;

        case EVENT_KRAGWA:
            me->SummonCreature(NPC_KRAGWA, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(70s);
            break;

        case EVENT_BWONSAMDIS_WRATH:
            me->SummonCreature(NPC_BWONSAMDI_CONCLAVE, middle_of_the_room, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(50s);
            break;
        }
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        switch (me->GetEntry())
        {
        case NPC_GONK:
            if (unit->GetEntry() == NPC_PAKU)
            {
                if (me->GetDistance(unit) <= 7.0f)
                {
                    if (!me->HasAura(SPELL_LOAS_PACT))
                        me->AddAura(SPELL_LOAS_PACT);

                    if (!unit->HasAura(SPELL_LOAS_PACT))
                        unit->AddAura(SPELL_LOAS_PACT);
                }
                if (me->GetDistance(unit) > 7.0f)
                {
                    if (me->HasAura(SPELL_LOAS_PACT))
                        me->RemoveAura(SPELL_LOAS_PACT);

                    if (unit->HasAura(SPELL_LOAS_PACT))
                        unit->RemoveAura(SPELL_LOAS_PACT);
                }
            }
            break;

        case NPC_PAKU:
            if (unit->GetEntry() == NPC_GONK)
            {
                if (me->GetDistance(unit) <= 7.0f)
                {
                    me->AddAura(SPELL_LOAS_PACT);
                    unit->AddAura(SPELL_LOAS_PACT);
                }
                if (me->GetDistance(unit) > 7.0f)
                {
                    if (me->HasAura(SPELL_LOAS_PACT))
                        me->RemoveAura(SPELL_LOAS_PACT);

                    if (unit->HasAura(SPELL_LOAS_PACT))
                        unit->RemoveAura(SPELL_LOAS_PACT);
                }
            }
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GONK:
            _JustDied();
            Talk(SAY_GONG_DEATH);
            if (Creature* paku = me->FindNearestCreature(NPC_PAKU, 125.0f, true))
                paku->CastSpell(nullptr, SPELL_LOAS_WRATH, true);

            //Gonk + Paku are dead now, so Kimbul is joing the fight
            if (Creature* paku = me->FindNearestCreature(NPC_PAKU, 125.0f, false && me->isDead()))
            {
                if (Creature* kimbul = me->FindNearestCreature(NPC_KIMBUL, 125.0f, true))  
                {
                    kimbul->RemoveAllAuras();
                    kimbul->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    kimbul->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    kimbul->AI()->DoZoneInCombat();
                }
            }
            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_CRY_OF_THE_FALLEN, 100ms);
            break;

        case NPC_PAKU:
            _JustDied();
            Talk(SAY_PAKU_DEATH);
            if (Creature* gonk = me->FindNearestCreature(NPC_GONK, 125.0f, true))
                gonk->CastSpell(nullptr, SPELL_LOAS_WRATH, true);

            //Gonk + Paku are dead now, so Kimbul is joing the fight
            if (Creature* gonk = me->FindNearestCreature(NPC_GONK, 125.0f, false && me->isDead()))
            {
                if (Creature* kimbul = me->FindNearestCreature(NPC_KIMBUL, 125.0f, true))
                {
                    kimbul->RemoveAllAuras();
                    kimbul->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    kimbul->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    kimbul->AI()->DoZoneInCombat();
                }
            }

            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_CRY_OF_THE_FALLEN, 100ms);
            break;

        case NPC_KIMBUL:
            _JustDied();
            Talk(SAY_KIMBUL_DEATH);
            //Kimbul is dead, so Akunda is joining the fight
            if (Creature* akunda = me->FindNearestCreature(NPC_AKUNDA, 125.0f, true))
            {
                akunda->RemoveAllAuras();
                akunda->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                akunda->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                akunda->AI()->DoZoneInCombat();
            }

            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_CRY_OF_THE_FALLEN, 100ms);
            break;

        case NPC_AKUNDA:
            _JustDied();
            Talk(SAY_AKUNDA_DEATH);
            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_CRY_OF_THE_FALLEN, 100ms);
            if (auto* conclaveExit = me->FindNearestGameObject(GO_CONCLAVE_DOOR_EXIT, 125.0f))
                conclaveExit->SetGoState(GO_STATE_ACTIVE);

            if (auto* conclaveEntrance = me->FindNearestGameObject(GO_ENCLAVE_DOOR_ENTRANCE, 125.0f))
                conclaveEntrance->SetGoState(GO_STATE_ACTIVE);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LOAS_WRATH);            
            instance->SendBossKillCredit(2268);
            if (IsMythic())
                instance->DoCompleteAchievement(13300);
            break;
        }
    }
};

//145405
struct npc_paku_conclave : public ScriptedAI
{
    npc_paku_conclave(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
        {
            me->GetMotionMaster()->Clear(true);
            me->CastSpell(nullptr, SPELL_PAKUS_WRATH, false);
            me->DespawnOrUnsummon(9s);
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->CanFly();
        me->SetFlying(true);
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            me->GetMotionMaster()->MovePoint(1, me->GetRandomPoint(me->GetPosition(), 30.0f), true);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//148849
struct npc_gonk_conclave : public ScriptedAI
{
    npc_gonk_conclave(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->CastSpell(nullptr, SPELL_GONKS_WRATH, false);
        for (uint8 i = 0; i < 5; i++)
        {
            me->SummonCreature(NPC_RAVENOUS_STALKER, me->GetRandomPoint(me->GetPosition(), + 30.0f));
        }
        me->DespawnOrUnsummon(3s);
    }
};

//145835
struct npc_kimbul_conclave : public ScriptedAI
{
    npc_kimbul_conclave(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->GetScheduler().Schedule(1s, [this] (TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->AddAura(SPELL_BLEEDING_WOUNDS, target);
            }

        }).Schedule(2s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->AddAura(SPELL_BLEEDING_WOUNDS, target);
            }

        }).Schedule(3s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->AddAura(SPELL_BLEEDING_WOUNDS, target);
            }
        }).Schedule(4s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->AddAura(SPELL_BLEEDING_WOUNDS, target);
                me->DespawnOrUnsummon(2s);
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//145397
struct npc_akunda_conclave : public ScriptedAI
{
    npc_akunda_conclave(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);       
        UnitList tar_li;
        SelectTargetList(tar_li, 3, SELECT_TARGET_RANDOM, 100.0f, true);
        for (Unit* targets : tar_li)
        {
            me->CastSpell(targets, SPELL_AKUNDAS_WRATH, true);
            targets->GetScheduler().Schedule(7s, [this, targets](TaskContext context)
            {
                me->CastSpell(targets, SPELL_AKUNDAS_WRAT_EXP, true);
                for (int8 i = 0; i < 6; i++)
                {
                    me->CastSpell(targets, SPELL_STATIC_ORB_CREATE_AT, true);
                }
                me->DespawnOrUnsummon(3s);
            });
        }
    }
};

//148962
struct npc_ravenous_stalker : public ScriptedAI
{
    npc_ravenous_stalker(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void IsSummonedBy(Unit* summoner)
    {
        me->AI()->DoZoneInCombat(nullptr);        
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->GetEntry() == NPC_GONK || unit->GetEntry() == NPC_PAKU || unit->GetEntry() == NPC_KIMBUL || unit->GetEntry() == NPC_AKUNDA && me->GetDistance2d(unit) <= 5.0f)
        {
            if (!me->HasAura(SPELL_PACK_HUNTER))
                me->AddAura(SPELL_PACK_HUNTER);

            if (!unit->HasAura(SPELL_PACK_HUNTER))
                unit->AddAura(SPELL_PACK_HUNTER);
        }
        if (unit->GetEntry() == NPC_GONK || unit->GetEntry() == NPC_PAKU || unit->GetEntry() == NPC_KIMBUL || unit->GetEntry() == NPC_AKUNDA && me->GetDistance2d(unit) > 5.0f)
        {
            if (me->HasAura(SPELL_PACK_HUNTER))
                me->RemoveAura(SPELL_PACK_HUNTER);

            if (unit->HasAura(SPELL_PACK_HUNTER))
                unit->RemoveAura(SPELL_PACK_HUNTER);
        }
    }
};

//145075
struct npc_kragwa : public ScriptedAI
{
    npc_kragwa(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->CastSpell(target->GetPosition(), SPELL_KRAGWAS_WRATH_MAIN, true);
            }

        }).Schedule(2s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->CastSpell(target->GetPosition(), SPELL_KRAGWAS_WRATH_MAIN, true);
            }

        }).Schedule(3s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->CastSpell(target->GetPosition(), SPELL_KRAGWAS_WRATH_MAIN, true);
            }
        }).Schedule(4s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_KIMBULS_WRATH_JUMP, true);
                me->CastSpell(target->GetPosition(), SPELL_KRAGWAS_WRATH_MAIN, true);
                me->DespawnOrUnsummon(3s);
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//149485
struct npc_bwonsamdi_conclave : public ScriptedAI
{
    npc_bwonsamdi_conclave(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        Talk(SAY_BWONSAMDIS_WRATH);
        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            me->AddAura(SPELL_BWONSAMDIS_WRATH, target);
        me->DespawnOrUnsummon(5s);
    }
};

//284663 - Bwonsamdis Wrath 
class aura_bwonsamdis_wrath : public AuraScript
{
    PrepareAuraScript(aura_bwonsamdis_wrath);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {  
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL || (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH))
            if (Unit* newTarget = GetTarget()->SelectNearestPlayer(30.0f))
                GetTarget()->AddAura(SPELL_BWONSAMDIS_WRATH, newTarget);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(aura_bwonsamdis_wrath::AfterRemove, EFFECT_4, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_conclave_of_the_chosen()
{
    RegisterCreatureAI(boss_conclave_of_the_chosen);
    RegisterCreatureAI(npc_paku_conclave);
    RegisterCreatureAI(npc_gonk_conclave);
    RegisterCreatureAI(npc_kimbul_conclave);
    RegisterCreatureAI(npc_akunda_conclave);
    RegisterCreatureAI(npc_ravenous_stalker);
    RegisterCreatureAI(npc_kragwa);
    RegisterCreatureAI(npc_bwonsamdi_conclave);
    RegisterAuraScript(aura_bwonsamdis_wrath);
}