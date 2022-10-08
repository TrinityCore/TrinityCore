#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "operation_mechagon.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_GUNKER_VISUAL = 300859,
    SPELL_GOOPED_CREATE_AURA_AT = 297821,
    SPELL_GOOPED_INCAPCITATED = 298124,
    SPELL_GOOPED_MAIN = 298259,
    SPELL_TOXIC_FLAMES_TRIGGER = 298228,
    SPELL_SPLATTER_TRIGGER = 297985,
    SPELL_COALESCE = 297835,
    SPELL_SLUDGE_BOLT = 298212,
    SPELL_TOXIC_WAVE = 297834,
    SPELL_SANITIZING_SPRAY = 297901,
    SPELL_SANITIZING_AURA = 298145,
    SPELL_SANITIZING_SPRAY2 = 298216,
};

enum Events
{
    EVENT_COALESCE = 1,
    EVENT_GOOPED,
    EVENT_SLUDGE_BOLT,
    EVENT_SPLATTER,
    EVENT_TOXIC_WAVE,
    EVENT_TOXIC_FLAMES
};

const Position squirt_bot_pos = { 626.622f, -348.212f, 0.423f, 3.54f };
const Position squirt_bot_pos2 = { 595.423f, -325.170f, 1.017f, 4.79f };
const Position squirt_bot_pos3 = { 577.199f, -359.477f, 0.864f, 0.11f };

//150222
struct boss_gunker : public BossAI
{
    boss_gunker(Creature* creature) : BossAI(creature, DATA_GUNKER) { }

    void Reset() override
    {
        BossAI::Reset();
        SetCombatMovement(false);
        me->AddUnitState(UNIT_STATE_ROOT);        
        me->SetPower(POWER_ENERGY, 0);        
        me->SummonCreature(NPC_SQUIRT_BOT, squirt_bot_pos, TEMPSUMMON_MANUAL_DESPAWN);
        me->SummonCreature(NPC_SQUIRT_BOT, squirt_bot_pos2, TEMPSUMMON_MANUAL_DESPAWN);
        me->SummonCreature(NPC_SQUIRT_BOT, squirt_bot_pos3, TEMPSUMMON_MANUAL_DESPAWN);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_GREEN);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && instance->GetBossState(DATA_KING_GOBBAMAK) == DONE)
        {
            if (me->HasAura(SPELL_GUNKER_VISUAL))
                me->RemoveAura(SPELL_GUNKER_VISUAL);

            if (me->HasUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC)))
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }
    }

    void EnterCombat(Unit* who) override
    {
        _EnterCombat();
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);        
        events.ScheduleEvent(EVENT_SLUDGE_BOLT, 1s);
        events.ScheduleEvent(EVENT_SPLATTER, 8s);
        events.ScheduleEvent(EVENT_COALESCE, 20s);
        events.ScheduleEvent(EVENT_GOOPED, 30s);        
        events.ScheduleEvent(EVENT_TOXIC_WAVE, 45s);
        events.ScheduleEvent(EVENT_TOXIC_FLAMES, 50s);
        std::list<Creature*> sb_li;
        sb_li.clear();
        me->GetCreatureListWithEntryInGrid(sb_li, NPC_SQUIRT_BOT, 100.0f);
        for (auto& squirt_bot : sb_li)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, squirt_bot);            
            squirt_bot->GetMotionMaster()->MoveRandom(10.0f);
            squirt_bot->AI()->DoCast(SPELL_SANITIZING_SPRAY);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_COALESCE:
            DoCastSelf(SPELL_COALESCE, false);
            events.Repeat(30s);
            break;

        case EVENT_GOOPED:           
            break;

        case EVENT_SLUDGE_BOLT:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
            {
                if (target->GetDistance2d(me) > 5.0f)
                {
                    me->CastSpell(target, SPELL_SLUDGE_BOLT, false);
                }
            }
            events.Repeat(2s);
            break;

        case EVENT_SPLATTER:
            DoCastSelf(SPELL_SPLATTER_TRIGGER, false);
            events.Repeat(35s);
            break;

        case EVENT_TOXIC_WAVE:
            me->SetPower(POWER_ENERGY, 0);
            DoCastSelf(SPELL_TOXIC_WAVE, false);
            events.Repeat(20s);
            break;

        case EVENT_TOXIC_FLAMES:
            DoCastSelf(SPELL_TOXIC_FLAMES_TRIGGER, true);
            events.Repeat(25s);
            break;
        }
    }

    void JustDied(Unit* killer) override
    {       
        _JustDied();
        me->DespawnCreaturesInArea(NPC_SQUIRT_BOT, 125.0f);
        instance->DoModifyPlayerCurrencies(1553, 35);
    }    
};

enum Squirt
{
    SAY_FOUND_POOL = 0,
    SAY_SYSTEM_RESTORE
};

//154746
struct npc_squirt_bot : public ScriptedAI
{
    npc_squirt_bot(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    //void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
};

void AddSC_boss_gunker()
{   
    RegisterCreatureAI(boss_gunker);
    RegisterCreatureAI(npc_squirt_bot);
}