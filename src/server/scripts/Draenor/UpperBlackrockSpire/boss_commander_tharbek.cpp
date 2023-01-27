#include "upper_blackrock_spire.h"

#define MIN_X 111.0f
#define MAX_X 194.0f
#define MIN_Y -454.0f   
#define MAX_Y -385.0f
#define MIN_Z 100.0f
#define MAX_Z 120.0f

enum Says
{
    SAY_DEATH           = 0,
};

enum Spells
{
    //Tharbek
    SPELL_DIALOG_1              = 174129,
    SPELL_DIALOG_2              = 174138,
    SPELL_DIALOG_3              = 174142,
    SPELL_IRON_RAGE             = 161985,
    SPELL_IRON_REAVER           = 161987,
    SPELL_IMBUED_IRON_AXE       = 162085,
    SPELL_IMBUED_IRON_AXE_AURA  = 162092,
    SPELL_IRON_AXE              = 161765,
    //Skyreaver
    SPELL_RIDE_VEHICLE          = 43671,
    SPELL_NOXIOUS_SPIT          = 161811,
    SPELL_INCINERATING_BREATH   = 161883,

    //Christmas
    SPELL_CHRISTMAS_CAP         = 176922
};

enum eEvents
{
    EVENT_SUMMON             = 1,
    EVENT_SUMMON_2,
    EVENT_SUMMON_3,
    EVENT_SUMMON_4,
    EVENT_SUMMONS_ATTACK     = 5,
    EVENT_IRON_REAVER        = 6,
    EVENT_IMBUED_AXE         = 7,
    EVENT_IRON_AXE           = 8,
    //Skyreaver
    EVENT_NOXIOUS_SPIT       = 1,
    EVENT_BREATH             = 2,
    //Other
    EVENT_RANDOM_POS         = 1,
};

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,
};

struct boss_commander_tharbek : public BossAI
{
    boss_commander_tharbek(Creature* creature) : BossAI(creature, DATA_THARBEK) {}

    uint32 checkTimer;
    uint8 summonCount;
    uint8 waveCount;
    bool find;
    bool rage;

    void Reset() override
    {
        events.Reset();
        _Reset();
        summons.DespawnAll();
        DespawnAllSummons();

        checkTimer = 1000;
        summonCount = 0;
        waveCount = 0;
        rage = false;

        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        me->SummonCreature(NPC_WARLORD_ZAELA, tharbekAdds[12]);
        
        if (me->HasAura(SPELL_CHRISTMAS_CAP))
            me->RemoveAura(SPELL_CHRISTMAS_CAP);
        
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.RescheduleEvent(EVENT_SUMMON, 2000);
        DoCast(SPELL_DIALOG_1);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        DespawnAllSummons();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade(15);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, NPC_WARLORD_ZAELA, 100.0f);
        me->GetCreatureListWithEntryInGrid(list, NPC_IRON_AXE_STALKER, 100.0f);
        if (!list.empty())
            for (auto& cre : list)
                cre->DespawnOrUnsummon();
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_WARLORD_ZAELA)
        {
            summon->SetReactState(REACT_PASSIVE);
            summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            summon->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            return;
        }

        summons.Summon(summon);
        summon->SetReactState(REACT_PASSIVE);

        if (waveCount > 2)
            return;

        summonCount++;
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        if (waveCount > 2)
            return;

        summonCount--;

        if (summonCount == 0)
        {
            waveCount++;
            events.RescheduleEvent(EVENT_SUMMON + waveCount, 2000);
        }
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            events.RescheduleEvent(EVENT_IRON_REAVER, 10000);
            events.RescheduleEvent(EVENT_IRON_AXE, 24000);
            break;
        case ACTION_2:
            me->SetReactState(REACT_AGGRESSIVE);
            events.RescheduleEvent(EVENT_IMBUED_AXE, 18000);
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
    {
        if (me->HealthBelowPct(70) && !rage)
        {
            rage = true;
            DoCast(me, SPELL_IRON_RAGE, true);
        }
    }

    void CheckPlrInBattleZone()
    {
        find = false;
        const Map::PlayerList &PlayerList = me->GetMap()->GetPlayers();
        if (!PlayerList.isEmpty())
        {
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if (Player* plr = i->GetSource())
                {
                    if (!plr->IsAlive() || plr->IsGameMaster())
                        break;

                    if (plr->GetPositionX() > MIN_X && plr->GetPositionX() < MAX_X && plr->GetPositionY() > MIN_Y && plr->GetPositionY() < MAX_Y && plr->GetPositionZ() > MIN_Z && plr->GetPositionZ() < MAX_Z)
                        find = true;
                }
            }
        }

        if (find && !me->IsInCombat())
        {
            DoZoneInCombat();
        }
        else if (!find && me->IsInCombat())
        {
            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            checkTimer = 1000;
            CheckPlrInBattleZone();
        }
        else
            checkTimer -= diff;

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SUMMON:
                for (uint8 i = 0; i < 2; i++)
                {
                    me->SummonCreature(NPC_BLACK_IRON_LEADBELCHER, tharbekAdds[i]);
                    me->SummonCreature(NPC_RAGEMAW_WORG, tharbekAdds[i + 2]);
                }

                for (uint8 i = 4; i < 12; i++)
                    me->SummonCreature(NPC_VILEMAW_HATCHLING, tharbekAdds[i]);

                events.RescheduleEvent(EVENT_SUMMONS_ATTACK, 1000);
                break;
            case EVENT_SUMMON_2:
                DoCast(SPELL_DIALOG_2);

                for (uint8 i = 0; i < 2; i++)
                {
                    me->SummonCreature(NPC_BLACK_IRON_BERSERKER, tharbekAdds[i]);
                    me->SummonCreature(NPC_BLACK_IRON_DREADWEAVER, tharbekAdds[i + 2]);
                }

                for (uint8 i = 4; i < 12; i++)
                    me->SummonCreature(NPC_VILEMAW_HATCHLING, tharbekAdds[i]);

                events.RescheduleEvent(EVENT_SUMMONS_ATTACK, 1000);
                break;
            case EVENT_SUMMON_3:
                DoCast(SPELL_DIALOG_3);
                me->SummonCreature(NPC_BLACK_IRON_ENGINEER, tharbekAdds[0]);

                for (uint8 i = 1; i < 3; i++)
                    me->SummonCreature(NPC_BLACK_IRON_SUMMONER, tharbekAdds[i]);

                for (uint8 i = 3; i < 12; i++)
                    me->SummonCreature(NPC_VILEMAW_HATCHLING, tharbekAdds[i]);

                events.RescheduleEvent(EVENT_SUMMONS_ATTACK, 1000);
                break;
            case EVENT_SUMMON_4:
                me->SummonCreature(NPC_IRONBARB_SKYREAVER, tharbekAdds[0]);
                instance->SetData(DATA_THARBEK_OPENGATE, IN_PROGRESS);
                break;
            case EVENT_SUMMONS_ATTACK:
                instance->SetData(DATA_THARBEK_OPENGATE, IN_PROGRESS);
                summons.DoZoneInCombat();
                break;
            case EVENT_IRON_REAVER:
                DoCast(SPELL_IRON_REAVER);
                events.RescheduleEvent(EVENT_IRON_REAVER, 20000);
                break;
            case EVENT_IMBUED_AXE:
                DoCast(SPELL_IMBUED_IRON_AXE);
                events.RescheduleEvent(EVENT_IMBUED_AXE, 30000);
                break;
            case EVENT_IRON_AXE:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0, true))
                    DoCast(target, SPELL_IRON_AXE, false);

                events.RescheduleEvent(EVENT_IRON_AXE, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//80098
struct npc_ironbarb_skyreaver : public ScriptedAI
{
    npc_ironbarb_skyreaver(Creature* creature) : ScriptedAI(creature)
    {
        exitPassenger = false;
        me->SetSpeed(MOVE_FLIGHT, 2.0f);
    }

    EventMap events;
    uint8 healthPct;
    bool exitPassenger;

    void Reset() override
    {
        events.Reset();

        if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
            healthPct = 50;
        else
            healthPct = 30;
    }

    void EnterCombat(Unit* /*who*/) override {}

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
    {
        if (me->HealthBelowPct(healthPct) && !exitPassenger)
        {
            exitPassenger = true;

            if (auto tharbek = me->GetOwner())
            {
                tharbek->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                tharbek->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                tharbek->GetAI()->DoAction(ACTION_1);
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != WAYPOINT_MOTION_TYPE)
            return;

        switch (id)
        {
        case 1:
            if (auto tharbek = me->GetOwner())
                tharbek->CastSpell(me, SPELL_RIDE_VEHICLE, true);
            break;
        case 6:
            me->SetReactState(REACT_AGGRESSIVE);

            if (auto tharbek = me->GetOwner())
                tharbek->GetAI()->DoAction(ACTION_2);

            events.RescheduleEvent(EVENT_NOXIOUS_SPIT, 2000);
            events.RescheduleEvent(EVENT_BREATH, 8000);
            break;
        }
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (!me->IsInCombat())
            DoZoneInCombat();

        me->GetMotionMaster()->MovePath(me->GetEntry(), false);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_NOXIOUS_SPIT:
                DoCast(SPELL_NOXIOUS_SPIT);
                events.RescheduleEvent(EVENT_NOXIOUS_SPIT, 14000);
                break;
            case EVENT_BREATH:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                {
                    me->AttackStop();
                    DoCast(target, SPELL_INCINERATING_BREATH, false);
                    me->SetFacingToObject(target);
                }
                events.RescheduleEvent(EVENT_BREATH, 12000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//80307
struct npc_imbued_iron_axe_stalker : public ScriptedAI
{
    npc_imbued_iron_axe_stalker(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;

    void Reset() override
    {
        DoCast(me, SPELL_IMBUED_IRON_AXE_AURA, true);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        events.RescheduleEvent(EVENT_RANDOM_POS, 1000);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            events.RescheduleEvent(EVENT_RANDOM_POS, 1000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_RANDOM_POS:
                float x = frand(MIN_X, MAX_X);
                float y = frand(MIN_Y, MAX_Y);
                me->GetMotionMaster()->MovePoint(1, x, y, me->GetPositionZ());
                break;
            }
        }
    }
};

void AddSC_boss_commander_tharbek()
{
    RegisterCreatureAI(boss_commander_tharbek);
    RegisterCreatureAI(npc_ironbarb_skyreaver);
    RegisterCreatureAI(npc_imbued_iron_axe_stalker);
}
