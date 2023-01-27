#include "upper_blackrock_spire.h"
#include "VehicleDefines.h"

#define MIN_X -0.5f
#define MAX_X 42.92f
#define MIN_Y -139.73f   
#define MAX_Y -101.40f

enum Says
{
    SAY_INTRO           = 0,
    SAY_AGGRO           = 1,
    SAY_DEATH           = 6
};

enum Spells
{
    SPELL_BURNING_BRIDGE        = 166685,
    SPELL_BURNING_BRIDGE_AT     = 166721,
    SPELL_DESTRUCTIVE_SMITE     = 155673,
    SPELL_BLACK_IRON_CYCLONE    = 155720,
    SPELL_REBOUNDING_BLADE      = 155705,
    SPELL_RIDE_VEHICLE          = 46598,

    SPELL_BURNING_BREATH        = 166040
};

enum eEvents
{
    EVENT_DESTRUCTIVE_SMITE     = 1,
    EVENT_BLACK_IRON_CYCLONE    = 2,
    EVENT_REBOUNDING_BLADE      = 3,
    EVENT_DRAKE_ATTACK          = 4,

    EVENT_DRAKE_BURNING_BREATH  = 1,
    EVENT_DRAKE_MOVE_BACK       = 2
};

enum eActions
{
    ACTION_DRAKE_INTRO      = 1,

    ACTION_REMOVE_VEHICLE   = 1
};

Position const fireBridgePos[11] = 
{
    {24.26f, -141.72f, 97.55f},
    {23.47f, -147.01f, 97.50f},
    {22.55f, -154.03f, 97.51f},
    {20.71f, -159.56f, 97.81f},
    {18.25f, -164.55f, 98.32f},
    {15.71f, -169.47f, 98.78f},
    {13.29f, -174.33f, 99.15f},
    {11.23f, -179.76f, 99.72f},
    {10.00f, -184.17f, 100.2f},
    {8.860f, -189.42f, 100.8f},
    {7.769f, -194.11f, 101.4f}
};

Position const drakePos[6] = 
{
    {11.44f, -110.48f,  97.75f, 4.78f}, // Intro drake spawn
    {33.64f, -109.21f,  97.75f, 4.78f},
    {68.62f,    0.98f, 129.01f},        // Drake despawn pos
    {19.71f, -186.19f,  29.51f},        // Matron spawn
    {4.49f,  -123.23f,  97.46f},        // Zaela run to matron point
    {21.88f, -112.88f, 122.49f}         // Centr platform pos
};

enum ePhase
{
    PHASE_BATTLE    = 1,
    PHASE_FLY       = 2
};

struct boss_warlord_zaela : public BossAI
{
    boss_warlord_zaela(Creature* creature) : BossAI(creature, DATA_ZAELA)
    {
        intro = false;
    }

    ObjectGuid matronGUID;
    uint16 checkTimer;
    bool phaseFly;
    bool drakeAttack;
    bool intro;

    void Reset() override
    {
        events.Reset();
        _Reset();
        summons.DespawnAll();
        me->RemoveAllAreaObjects();

        checkTimer = 1000;
        phaseFly = false;
        drakeAttack = false;

        if (me->GetPositionX() > MIN_X && me->GetPositionX() < MAX_X && me->GetPositionY() > MIN_Y && me->GetPositionY() < MAX_Y)
            for (uint8 i = 0; i < 2; i++)
                me->SummonCreature(NPC_EMBERSCALE_IRONFLIGHT, drakePos[i]);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (me->GetDistance(who) > 60.0f)
            return;

        if (!intro)
        {
            intro = true;

            Talk(SAY_INTRO);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();

        EntryCheckPredicate pred(NPC_EMBERSCALE_IRONFLIGHT);
        summons.DoAction(ACTION_DRAKE_INTRO, pred);

        for (uint8 i = 0; i < 10; i++)
        {
            float x = fireBridgePos[i].GetPositionX();
            float y = fireBridgePos[i].GetPositionY();
            float z = fireBridgePos[i].GetPositionZ();
            me->CastSpell(x, y, z, SPELL_BURNING_BRIDGE, true);
        }

        BattleEvents();
    }

    void BattleEvents()
    {
        events.SetPhase(PHASE_BATTLE);
        events.RescheduleEvent(EVENT_DESTRUCTIVE_SMITE, 8000, 0, PHASE_BATTLE);
        events.RescheduleEvent(EVENT_BLACK_IRON_CYCLONE, 18000, 0, PHASE_BATTLE);
        events.RescheduleEvent(EVENT_REBOUNDING_BLADE, 22000, 0, PHASE_BATTLE);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        _DespawnAtEvade(15);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();

        summons.DespawnAll();
        me->RemoveAllAreaObjects();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case NPC_EMBERSCALE_MATRON:
            matronGUID = summon->GetGUID();
            break;
        case NPC_EMBERSCALE_IRONFLIGHT:
        {
            if (phaseFly)
            {
                summon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                summon->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                summon->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                uint8 rand;
                if (!drakeAttack)
                {
                    drakeAttack = true;
                    rand = urand(0, 2);
                }
                else
                {
                    rand = urand(3, 5);
                    drakeAttack = false;
                }
                summon->ToCreature()->AI()->DoZoneInCombat();
                summon->GetMotionMaster()->MovePath((NPC_EMBERSCALE_IRONFLIGHT * 100) + rand, false);
            }
            break;
        }
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_BLACK_IRON_CYCLONE)
        {
            DoResetThreat();
            me->AddThreat(target, 10000.0f);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
    {
        if (me->HealthBelowPct(60) && !phaseFly)
        {
            phaseFly = true;
            events.SetPhase(PHASE_FLY);
            me->AttackStop();
            me->RemoveAllAuras();
            me->SummonCreature(NPC_EMBERSCALE_MATRON, drakePos[3]);
            me->GetMotionMaster()->MovePoint(1, drakePos[4]);

            for (uint8 i = 0; i < 3; i++)
                me->SummonCreature(NPC_EMBERSCALE_IRONFLIGHT_2, drakePos[2]);

            events.RescheduleEvent(EVENT_DRAKE_ATTACK, 2000);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            if (auto matron = me->GetCreature(*me, matronGUID))
                DoCast(matron, SPELL_RIDE_VEHICLE, false);
    }

    void CheckPos()
    {
        if (me->GetPositionX() < MIN_X || me->GetPositionX() > MAX_X || me->GetPositionY() < MIN_Y || me->GetPositionY() > MAX_Y)
            EnterEvadeMode(EVADE_REASON_BOUNDARY);
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_REMOVE_VEHICLE)
            BattleEvents();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (!me->HasAura(SPELL_RIDE_VEHICLE))
        {
            if (checkTimer <= diff)
            {
                CheckPos();
                checkTimer = 1000;
            }
            else
                checkTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_DESTRUCTIVE_SMITE:
                if (auto target = me->GetVictim())
                    DoCast(target, SPELL_DESTRUCTIVE_SMITE, false);

                events.RescheduleEvent(EVENT_DESTRUCTIVE_SMITE, 6000, 0, PHASE_BATTLE);
                break;
            case EVENT_BLACK_IRON_CYCLONE:
                DoCast(me, SPELL_BLACK_IRON_CYCLONE, true);
                events.RescheduleEvent(EVENT_BLACK_IRON_CYCLONE, 22000, 0, PHASE_BATTLE);
                break;
            case EVENT_REBOUNDING_BLADE:
                DoCast(SPELL_REBOUNDING_BLADE);
                events.RescheduleEvent(EVENT_REBOUNDING_BLADE, 10000, 0, PHASE_BATTLE);
                break;
            case EVENT_DRAKE_ATTACK:
                me->SummonCreature(NPC_EMBERSCALE_IRONFLIGHT, drakePos[2]);
                events.RescheduleEvent(EVENT_DRAKE_ATTACK, 6000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//82428, 83479
struct npc_emberscale_ironflight : public CreatureAI
{
    npc_emberscale_ironflight(Creature* creature) : CreatureAI(creature)
    {
        me->SetCanFly(true);
        me->SetDisableGravity(true);
        me->SetSpeed(MOVE_FLIGHT, 4.0f);
    }

    EventMap events;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void EnterCombat(Unit* /*who*/) override {}

    void DoAction(int32 const action) override
    {
        if (action == ACTION_DRAKE_INTRO)
        {
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
            me->GetMotionMaster()->MovePoint(1, drakePos[2]);
        }
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (me->GetEntry() == NPC_EMBERSCALE_IRONFLIGHT_2)
        {
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
            me->GetMotionMaster()->MovePoint(1, drakePos[5]);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            if (id == 1)
            {
                if (me->GetEntry() == NPC_EMBERSCALE_IRONFLIGHT_2)
                {
                    Vehicle* veh = me->GetVehicleKit();
                    if (!veh)
                        return;
                    me->ExitVehicle();
                }
                me->DespawnOrUnsummon(1000);
            }
        }

        if (type == WAYPOINT_MOTION_TYPE)
        {
            if (id == 0)
                events.RescheduleEvent(EVENT_DRAKE_BURNING_BREATH, 500);

            if (id == 1)
                me->DespawnOrUnsummon(1000);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_DRAKE_BURNING_BREATH:
                DoCast(SPELL_BURNING_BREATH);
                events.RescheduleEvent(EVENT_DRAKE_MOVE_BACK, 8000);
                break;
            case EVENT_DRAKE_MOVE_BACK:
                me->GetMotionMaster()->MovePoint(1, drakePos[2]);
                break;
            }
        }
    }
};

//82480
struct npc_emberscale_matron : public ScriptedAI
{
    npc_emberscale_matron(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCanFly(true);
        //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
        me->SetSpeed(MOVE_FLIGHT, 4.0f);
    }

    ObjectGuid zaelaGUID;

    void Reset()
    {
        zaelaGUID.Clear();
    }

    void EnterCombat(Unit* /*who*/) {}

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != WAYPOINT_MOTION_TYPE)
            return;

        switch (id)
        {
        case 8:
            me->ExitVehicle();
            me->DespawnOrUnsummon(5000);
            if (auto zaela = me->GetCreature(*me, zaelaGUID))
            {
                zaela->SetReactState(REACT_AGGRESSIVE);
                zaela->AI()->DoAction(ACTION_REMOVE_VEHICLE);
            }
            break;
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        zaelaGUID = summoner->GetGUID();

        me->GetMotionMaster()->MovePath((me->GetEntry() * 100), false);
    }

    void UpdateAI(uint32 /*diff*/) override {}
};

void AddSC_boss_warlord_zaela()
{
    RegisterCreatureAI(boss_warlord_zaela);
    RegisterCreatureAI(npc_emberscale_ironflight);
    RegisterCreatureAI(npc_emberscale_matron);
}
