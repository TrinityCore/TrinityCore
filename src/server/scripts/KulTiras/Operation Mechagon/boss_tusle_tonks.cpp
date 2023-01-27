#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "operation_mechagon.h"

enum Texts
{

};

enum Spells
{
    SPELL_BUZZ_SAW_CREATE_AT_VISUAL = 282898,
    SPELL_BUZZ_SAW_DAMAGE_KNOCK = 282945,

    SPELL_PLATINUM_PLATING = 282801,
    SPELL_WHIRLING_EDGE = 285020,
    SPELL_LAY_MINE_MISSILE = 285344,
    SPELL_LAY_MINE_CREATE_AREATRIGGER = 285351,
    SPELL_MAXIMUM_THRUST_DAMAGE = 283422,
    SPELL_AURA_VENT_JETS = 285388,
};

enum Events
{
    EVENT_BUZZ_SAW = 1,
    EVENT_WHIRLING_EDGE,
    EVENT_LAY_MINE,
    EVENT_MAXIMUM_THRUST,
    EVENT_VENT_JETS
};

const Position buzz_saws_charge_pos = { 454.811f, 224.149f, 72.0f, 1.5f };
const Position buzz_saws_spawn_pos = { 461.845f, 260.902f, 72.406f, 4.5f };

//TODO
//Spawn positions for buzz saws, improve their event

//pummeler 144244, gnomercy 145185
struct boss_tusle_tonks : public BossAI
{
    boss_tusle_tonks(Creature* creature) : BossAI(creature, DATA_TUSSLE_TONKS) { }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_PLATINUM_PUMMELER:
            BossAI::Reset();
            me->AddAura(SPELL_PLATINUM_PLATING);
            if (Aura* plating = me->GetAura(SPELL_PLATINUM_PLATING))            
                plating->SetStackAmount(3);
            me->DespawnCreaturesInArea(NPC_BUZZ_SAW, 125.0f);
            break;

        case NPC_GNOMERCY:
            BossAI::Reset();
            me->SetReactState(REACT_PASSIVE);
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_PLATINUM_PUMMELER:
            _EnterCombat();            
            events.ScheduleEvent(EVENT_WHIRLING_EDGE, 5s);
            events.ScheduleEvent(EVENT_LAY_MINE, 10s);
            events.ScheduleEvent(EVENT_BUZZ_SAW, 15s);
            if (Creature* gnomercy = me->FindNearestCreature(NPC_GNOMERCY, 100.0f, true))
                if (!gnomercy->IsInCombat())
                    gnomercy->AI()->DoZoneInCombat();
            break;

        case NPC_GNOMERCY:
            _EnterCombat();
            events.ScheduleEvent(EVENT_MAXIMUM_THRUST, 1s);
            events.ScheduleEvent(EVENT_VENT_JETS, 6s);
            if (Creature* pummeler = me->FindNearestCreature(NPC_PLATINUM_PUMMELER, 100.0f, true))
                if (!pummeler->IsInCombat())
                    pummeler->AI()->DoZoneInCombat();
            break;
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_BUZZ_SAW:
        {
            for (uint8 i = 0; i < 13; i++)
            {
                me->SummonCreature(NPC_BUZZ_SAW, buzz_saws_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
            }
            std::list<Creature*> buzz_saw_list;
            buzz_saw_list.clear();
            me->GetCreatureListWithEntryInGrid(buzz_saw_list, NPC_BUZZ_SAW, 300.0f);
            for (auto& buzz_saws : buzz_saw_list)
            {
                if (Creature* stalker = me->FindNearestCreature(NPC_STALKER_ROBODROME_ARENA, 100.0f, true))
                {
                    buzz_saws->SetFacingToObject(stalker);
                    me->GetScheduler().Schedule(1s, [buzz_saws, stalker] (TaskContext context)
                    {                        
                        buzz_saws->GetMotionMaster()->MoveCharge(stalker->GetPositionX(), stalker->GetPositionY(), stalker->GetPositionZ(), 80.0f, 1, true);
                    });
                    me->GetScheduler().Schedule(3s, [buzz_saws, stalker] (TaskContext context)
                    {
                        buzz_saws->GetMotionMaster()->MoveRandom(30.0f);
                    });
                    me->GetScheduler().Schedule(6s, [buzz_saws, stalker] (TaskContext context)
                    {
                        buzz_saws->DespawnOrUnsummon();
                    });
                }
        }   }
        events.Repeat(35s);
        break;

        case EVENT_WHIRLING_EDGE:
            DoCast(SPELL_WHIRLING_EDGE);
            events.Repeat(20s);
            break;

        case EVENT_LAY_MINE:
            DoCastRandom(SPELL_LAY_MINE_MISSILE, 100.0f, true);
            events.Repeat(30s);
            break;

        case EVENT_MAXIMUM_THRUST:
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->GetScheduler().Schedule(1s, [this, target] (TaskContext context)
                {
                    me->GetMotionMaster()->MoveCharge(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 100.0f, 1, true);
                });
            }
            events.Repeat(20s);
            break;

        case EVENT_VENT_JETS:
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
            {
                me->AddAura(SPELL_AURA_VENT_JETS);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(target, 100.0f, PET_FOLLOW_ANGLE);
            }
            events.Repeat(30s);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        switch (me->GetEntry())
        {
        case NPC_PLATINUM_PUMMELER:
            me->NearTeleportTo(me->GetHomePosition());
            me->ForcedDespawn(0, 15s);
            me->DespawnCreaturesInArea(NPC_BUZZ_SAW, 125.0f);
            if (Creature* gnomercy = me->FindNearestCreature(NPC_GNOMERCY, 100.0f, false))
            {
                gnomercy->NearTeleportTo(me->GetHomePosition());
                gnomercy->ForcedDespawn(0, 15s);
            }
            break;

        case NPC_GNOMERCY:
            me->NearTeleportTo(me->GetHomePosition());
            me->ForcedDespawn(0, 15s);
            me->DespawnCreaturesInArea(NPC_BUZZ_SAW, 125.0f);
            if (Creature* pummeler = me->FindNearestCreature(NPC_PLATINUM_PUMMELER, 100.0f, false))
            {
                pummeler->NearTeleportTo(me->GetHomePosition());
                pummeler->ForcedDespawn(0, 15s);
            }
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_PLATINUM_PUMMELER:
            _JustDied();
            instance->DoModifyPlayerCurrencies(1553, 35);
            break;

        case NPC_GNOMERCY:
            _JustDied();
            break;
        }        
    }
};

//145312
struct npc_buzz_saw : public ScriptedAI
{
    npc_buzz_saw(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(nullptr, SPELL_BUZZ_SAW_CREATE_AT_VISUAL);
    }
};

void AddSC_boss_tussie_tonks()
{
    RegisterCreatureAI(boss_tusle_tonks);
    RegisterCreatureAI(npc_buzz_saw);
};
