#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_SAP_PUDDLE_SUMMON = 123112,
    SPELL_CARRYING_CAUSTIC_TAR = 123032,
    SPELL_MANTID_BARREL_ACTIVE = 123215,
    SPELL_MANTID_BARREL_INACTIVE = 123218,
    SPELL_GRAB_BARREL = 120405,
    SPELL_LOOT_SPARKLES = 92406,
    SPELL_SAP_PUDDLE_SLOW = 120270,
    SPELL_CARRYING_EXPLOSIVES = 121986,
    SPELL_BOMBARD_PERIODIC = 120559,
    SPELL_THOUSAND_BLADES = 120759,
    SPELL_DASHING_STRIKE = 120789,
    SPELL_AURA_CAUSTIC_TAR = 120778,
    SPELL_FRANTIC_FITHER = 120757,
    SPELL_RISING_SPEED = 120758,
    SPELL_BLUE_ARROW = 87864,

    BFA_SPELL_SLEEP = 9454,
};

enum Events
{
    EVENT_YANG_DO_IRONCLAW_INTRO_EVENT  = 1,
    EVENT_YANG_DO_IRONCLAW_BOSS_ORDER_CHECK,
    EVENT_PICK_UP_BARREL,
    EVENT_MOVE_TO_BARREL_DROP_SPOT,
    EVENT_MOVE_BACK_TO_BARREL_PICKUP_SPOT,
    EVENT_VOJAK_SAY_INTRO_LINE_ONE,
    EVENT_VOJAK_SAY_INTRO_LINE_TWO,
    EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER,
    EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER,
    EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER_AND_WARRIOR,
    EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER_AND_WARRIOR,
    EVENT_VOJAK_SUMMON_AIR_SUPPORT,
    EVENT_CHECK_FOR_SAP_PUDDLE,
    EVENT_CHECK_FOR_ALIVE_PLAYERS,
    EVENT_AMBERWING_RETREAT,
    EVENT_AMBERWING_START_MOVING,
    EVENT_VOJAK_MOVE_TO_PLATFORM,
    EVENT_CAST_DASHING_STRIKE,
    EVENT_CAST_THOUSAND_BLADES,

};

enum Points
{
    POINT_YANG_IRONCLAW_INTRO = 1,
    POINT_LO_LI_CHU_BARREL_PICKUP_SPOT,
    POINT_LO_LI_CHU_PLANT_BOMB_POS,
    POINT_SIKTHIK_MOVE_TO_HALFWAY,
    POINT_MOVE_TO_PLATFORM_TOP,
    POINT_AMBERWING_WAYPOINT,
    POINT_AMBERWING_RETREAT,
};

enum Actions
{
    ACTION_CHU_START_PLANTING_BARRELS = 1,
    ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT_INITIAL,
    ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT,
    ACTION_VOJAK_START_ENCOUNTER,
    ACTION_ENCOUNTER_RESET,
};

enum Misc
{
    NPC_LI_CHU = 61812,
    NPC_LO_CHU = 62794,
    NPC_SIKTHIK_SWARMER = 63106,
    NPC_SIKTHIK_DEMOLISHER = 61670,
    NPC_SIKTHIK_AMBERWING = 61699,
    NPC_YANG_IRONCLAW = 61620,
    NPC_SAP_PUDDLE = 61579,
    NPC_SIKTHIK_WARRIOR = 61701,
    NPC_MANTID_TAR_KEG = 61817,
};

Position LiChuBarrelPlacePosition[3] =
{
    { 1547.93f, 5289.14f, 184.73f, 0.0f },
    { 1533.28f, 5311.80f, 184.64f, 0.0f },
    { 1551.89f, 5313.00f, 184.64f, 0.0f },
};

Position LoChuBarrelPlacePosition[3] =
{
    { 1488.72f, 5299.47f, 184.64f, 0.0f },
    { 1515.69f, 5309.72f, 184.64f, 0.0f },
    { 1490.19f, 5308.79f, 184.64f, 0.0f },
};

Position SikthikAmberwingWaypoint[6]
{
    { 1648.000f, 5398.483f, 158.9442f },
    { 1630.078f, 5402.018f, 163.3863f },
    { 1574.807f, 5394.819f, 173.6126f },
    { 1548.351f, 5376.471f, 192.1736f },
    { 1529.559f, 5346.958f, 196.6980f },
    { 1527.813f, 5316.797f, 196.6980f },
};

class SummonSikthikAdsEvent : public BasicEvent
{
    public:
        SummonSikthikAdsEvent(Creature& owner, uint32 entry) : BasicEvent(), _owner(owner), _entry(entry) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
        {
            _owner.SummonCreature(_entry, _owner.GetPositionX(), _owner.GetPositionY(), _owner.GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
            return true;
        }

    private:
        Creature& _owner;
        uint32 _entry;
};

class boss_commander_vojak : public CreatureScript
{
    public:
        boss_commander_vojak() : CreatureScript("boss_commander_vojak") { }

        struct boss_commander_vojakAI : public BossAI
        {
            boss_commander_vojakAI(Creature* creature) : BossAI(creature, 0) { }

            void Reset()
            {
                _Reset();
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAurasDueToSpell(SPELL_FRANTIC_FITHER);

                if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                    ironclaw->AI()->DoAction(ACTION_ENCOUNTER_RESET);
            }

            void EnterCombat(Unit* who)
            {
                _EnterCombat();

                //Talk(0, who);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                //events.ScheduleEvent(EVENT_, urand(1000, 5000));
            }

            void JustDied(Unit* killer)
            {
                _JustDied();

                Talk(11, killer);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                    ironclaw->AI()->DoAction(ACTION_ENCOUNTER_RESET);
            }

            void KilledUnit(Unit* victim)
            {
                events.RescheduleEvent(EVENT_CHECK_FOR_ALIVE_PLAYERS, 1);
                //if (victim->GetTypeId() == TYPEID_PLAYER)
                //    Talk(3, victim);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_VOJAK_START_ENCOUNTER:
                        DoZoneInCombat();
                        events.ScheduleEvent(EVENT_VOJAK_SAY_INTRO_LINE_ONE, 3500);
                        events.ScheduleEvent(EVENT_CHECK_FOR_ALIVE_PLAYERS, 1000);
                        break;
                }
            }

            void JustReachedHome()
            {
                summons.DespawnAll();

            }

            void JustSummoned(Creature* summoned)
            {
                summons.Summon(summoned);
            }

            void UpdateAI(uint32 diff)
            {
                //FREAKZ_CheckBossOrder(me, diff);

                if (!CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_CHECK_FOR_ALIVE_PLAYERS:
                        if (!CountAlivePlayers())
                        {
                            Reset();
                            me->GetMotionMaster()->MoveTargetedHome();
                            break;
                        }

                        events.ScheduleEvent(EVENT_CHECK_FOR_ALIVE_PLAYERS, 500);
                        break;
                    case EVENT_VOJAK_SAY_INTRO_LINE_ONE:
                        Talk(0);
                        events.ScheduleEvent(EVENT_VOJAK_SAY_INTRO_LINE_TWO, 6500);
                        break;
                    case EVENT_VOJAK_SAY_INTRO_LINE_TWO:
                        Talk(1);
                        events.ScheduleEvent(EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER, 6500);
                        break;
                    case EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER:
                        DoDelayedSummonSikthikSwarmers();
                        events.ScheduleEvent(EVENT_VOJAK_SUMMON_AIR_SUPPORT, 37000);
                        break;
                    case EVENT_VOJAK_SUMMON_AIR_SUPPORT:
                        Talk(2);

                        me->SummonCreature(NPC_SIKTHIK_AMBERWING, SikthikAmberwingWaypoint[0].GetPositionX(), SikthikAmberwingWaypoint[0].GetPositionY(), SikthikAmberwingWaypoint[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 4000);

                        if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                            ironclaw->AI()->Talk(9);

                        events.ScheduleEvent(EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER, 37000);
                        break;
                    case EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER:
                        DoDelayedSummonSikthikDemolishers();
                        events.ScheduleEvent(EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER_AND_WARRIOR, 45000);
                        break;
                    case EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER_AND_WARRIOR:
                        Talk(5);

                        // 500 - 1000 - 1500
                        for (int i = 0; i < 3; ++i)
                            me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_SWARMER), me->m_Events.CalculateTime((i + 1) * 500));

                        me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_WARRIOR), me->m_Events.CalculateTime(3500));

                        for (int i = 0; i < 3; ++i)
                            me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_SWARMER), me->m_Events.CalculateTime(((i + 1) * 500)) + 4000);

                        if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                        {
                            ironclaw->AI()->Talk(12);
                            ironclaw->AI()->Talk(13);
                        }

                        events.ScheduleEvent(EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER_AND_WARRIOR, 45000);
                        break;
                    case EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER_AND_WARRIOR:
                        for (int i = 0; i < 3; ++i)
                            me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_DEMOLISHER), me->m_Events.CalculateTime((i + 1) * 500));

                        me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_WARRIOR), me->m_Events.CalculateTime(3500));

                        for (int i = 0; i < 3; ++i)
                            me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_DEMOLISHER), me->m_Events.CalculateTime(((i + 1) * 500)) + 4000);

                        if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                            ironclaw->AI()->Talk(14);

                        events.ScheduleEvent(EVENT_VOJAK_MOVE_TO_PLATFORM, 55000);
                        break;
                    case EVENT_VOJAK_MOVE_TO_PLATFORM:
                        Talk(8);
                        Talk(9);
                        me->SetReactState(REACT_PASSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_PLATFORM_TOP, 1513.30f, 5297.26f, 184.64f);
                        events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 1500);
                        break;
                    case EVENT_CHECK_FOR_SAP_PUDDLE:
                        if (me->FindNearestCreature(NPC_SAP_PUDDLE, 5.0f))
                        {
                            me->AddAura(SPELL_SAP_PUDDLE_SLOW, me);
                            me->RemoveAurasDueToSpell(SPELL_RISING_SPEED);
                        }
                        else
                            me->RemoveAurasDueToSpell(SPELL_SAP_PUDDLE_SLOW);

                        events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 250);
                        break;
                    case EVENT_CAST_DASHING_STRIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_DASHING_STRIKE);

                        events.ScheduleEvent(EVENT_CAST_DASHING_STRIKE, urand(13000, 20000));
                        events.ScheduleEvent(EVENT_CAST_THOUSAND_BLADES, 5000);
                        break;
                    case EVENT_CAST_THOUSAND_BLADES:
                        if (me->HasAura(SPELL_AURA_CAUSTIC_TAR))
                            Talk(10);

                        DoCast(me, SPELL_THOUSAND_BLADES);
                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_MOVE_TO_PLATFORM_TOP)
                {
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->AddAura(SPELL_FRANTIC_FITHER, me);
                    me->SetReactState(REACT_AGGRESSIVE);
                    AttackStart(me->SelectNearestPlayer(100.0f));
                }
            }

            void DoDelayedSummonSikthikSwarmers()
            {
                for (int i = 0; i < 3; ++i)
                    me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_SWARMER), me->m_Events.CalculateTime((i + 1) * 500));

                for (int i = 0; i < 3; ++i)
                    me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_SWARMER), me->m_Events.CalculateTime(((i + 1) * 500)) + 4000);
            }

            void DoDelayedSummonSikthikDemolishers()
            {
                Talk(3);

                for (int i = 0; i < 3; ++i)
                    me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_DEMOLISHER), me->m_Events.CalculateTime((i + 1) * 500));

                for (int i = 0; i < 3; ++i)
                    me->m_Events.AddEvent(new SummonSikthikAdsEvent(*me, NPC_SIKTHIK_DEMOLISHER), me->m_Events.CalculateTime(((i + 1) * 500)) + 4000);

                if (Creature* ironclaw = me->FindNearestCreature(NPC_YANG_IRONCLAW, 150.0f))
                {
                    ironclaw->AI()->Talk(10);
                    ironclaw->AI()->Talk(11);
                }
            }

            bool CheckInRoom()
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 300.0f)
                {
                    EnterEvadeMode();
                    return false;
                }

                return true;
            }

            uint32 CountAlivePlayers()
            {
                Map::PlayerList const &players = me->GetMap()->GetPlayers();
                uint32 count = 0;

                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive() && !player->IsGameMaster())
                                count++;

                return count;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_commander_vojakAI(creature);
        }
};

class npc_commander_vojak_mantid_tar_keg : public CreatureScript
{
    public:
        npc_commander_vojak_mantid_tar_keg() : CreatureScript("npc_commander_vojak_mantid_tar_keg") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->CastSpell(player, SPELL_CARRYING_CAUSTIC_TAR, false);
            //player->AddTemporarySpell(123039);
            creature->DespawnOrUnsummon();
            return true;
        }

        struct npc_commander_vojak_mantid_tar_kegAI : public ScriptedAI
        {
            npc_commander_vojak_mantid_tar_kegAI(Creature* creature) : ScriptedAI(creature) { }

            void OnSpellClick(Unit* clicker, bool& result)
            {
                me->DespawnOrUnsummon();
            }

            void JustRespawned()
            {
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAurasDueToSpell(SPELL_LOOT_SPARKLES);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                damage = 0;
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_mantid_tar_kegAI(creature);
        }
};

class npc_commander_vojak_yang_ironclaw : public CreatureScript
{
    public:
        npc_commander_vojak_yang_ironclaw() : CreatureScript("npc_commander_vojak_yang_ironclaw") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            
            creature->GetMotionMaster()->MovePoint(POINT_YANG_IRONCLAW_INTRO, 1524.109f, 5313.25f, 185.22f, false);

            creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            creature->RemoveAura(SPELL_BLUE_ARROW);
            return true;
        }

        struct npc_commander_vojak_yang_ironclawAI : public ScriptedAI
        {
            npc_commander_vojak_yang_ironclawAI(Creature* creature) : ScriptedAI(creature) { }

            uint8 talkProgress;

            void Reset()
            {
                talkProgress = 0;
                //events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_BOSS_ORDER_CHECK, 5000);
            }

            void JustRespawned()
            {
                talkProgress = 0;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ENCOUNTER_RESET:
                    {
                        events.Reset();
                        me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
                        me->AddAura(SPELL_BLUE_ARROW, me);
                        me->RemoveAllAuras();
                        EnterEvadeMode();
                        talkProgress = 0;

                        if (Creature* loChu = me->FindNearestCreature(NPC_LO_CHU, 100.0f))
                            loChu->AI()->DoAction(ACTION_ENCOUNTER_RESET);

                        if (Creature* liChu = me->FindNearestCreature(NPC_LI_CHU, 100.0f))
                            liChu->AI()->DoAction(ACTION_ENCOUNTER_RESET);

                        std::list<Creature*> barrels;
                        GetCreatureListWithEntryInGrid(barrels, me, NPC_MANTID_TAR_KEG, 200.0f);

                        for (std::list<Creature*>::iterator itr = barrels.begin(); itr != barrels.end(); ++itr)
                            if ((*itr)->HasAura(SPELL_LOOT_SPARKLES))
                                (*itr)->DespawnOrUnsummon();

                        break;
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_YANG_IRONCLAW_INTRO)
                    events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_INTRO_EVENT, 500);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                damage = 0;
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_YANG_DO_IRONCLAW_BOSS_ORDER_CHECK:
                        if (Creature * vojak = me->FindNearestCreature(61634, 500.0f, true))
                            if (vojak->HasAura(BFA_SPELL_SLEEP))
                            {
                                if (!me->HasAura(BFA_SPELL_SLEEP))
                                    me->AddAura(BFA_SPELL_SLEEP, me);
                            }
                            else
                                me->RemoveAura(BFA_SPELL_SLEEP);
                        events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_BOSS_ORDER_CHECK, 5000);
                        break;
                    case EVENT_YANG_DO_IRONCLAW_INTRO_EVENT:
                        Talk(talkProgress++);

                        switch (talkProgress)
                        {
                            case 8: //! Second to last point of intro!
                                if (Creature* loChu = me->FindNearestCreature(NPC_LO_CHU, 100.0f))
                                    loChu->AI()->DoAction(ACTION_CHU_START_PLANTING_BARRELS);

                                if (Creature* liChu = me->FindNearestCreature(NPC_LI_CHU, 100.0f))
                                    liChu->AI()->DoAction(ACTION_CHU_START_PLANTING_BARRELS);

                                break;
                            case 7: //! Make Vojak speak, then continue
                                if (Creature* vojak = me->FindNearestCreature(61634, 300.0f))
                                {
                                    vojak->AI()->DoAction(ACTION_VOJAK_START_ENCOUNTER);
                                    events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_INTRO_EVENT, 19000);
                                }

                                break;
                            case 5: //! Tell the Chu's to start placing barrels
                                if (Creature* loChu = me->FindNearestCreature(NPC_LO_CHU, 100.0f))
                                    loChu->AI()->DoAction(ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT_INITIAL);

                                if (Creature* liChu = me->FindNearestCreature(NPC_LI_CHU, 100.0f))
                                    liChu->AI()->DoAction(ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT_INITIAL);

                                events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_INTRO_EVENT, 6500);
                                break;
                            case 3:
                                me->SetFacingTo(4.79f);
                                // no break
                            default:
                                events.ScheduleEvent(EVENT_YANG_DO_IRONCLAW_INTRO_EVENT, 6500);
                                break;
                        }

                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_yang_ironclawAI(creature);
        }
};

class npc_commander_vojak_lo_and_lo_chu : public CreatureScript
{
    public:
        npc_commander_vojak_lo_and_lo_chu() : CreatureScript("npc_commander_vojak_lo_and_lo_chu") { }

        struct npc_commander_vojak_lo_and_lo_chuAI : public ScriptedAI
        {
            npc_commander_vojak_lo_and_lo_chuAI(Creature* creature) : ScriptedAI(creature) { }

            bool isLoChu;

            void Reset()
            {
                isLoChu = me->GetEntry() == NPC_LO_CHU;

                me->SetWalk(false);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                damage = 0;
            }

            void JustRespawned()
            {
                me->SetWalk(false);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_LO_LI_CHU_BARREL_PICKUP_SPOT:
                        me->SetFacingTo(4.79f);
                        events.ScheduleEvent(EVENT_PICK_UP_BARREL, 4000);

                        me->SetWalk(false);
                        break;
                    case POINT_LO_LI_CHU_PLANT_BOMB_POS:
                        if (Vehicle* veh = me->GetVehicleKit())
                        {
                            if (Unit* passenger = veh->GetPassenger(0))
                            {
                                if (passenger->GetTypeId() == TYPEID_UNIT)
                                {
                                    passenger->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                    passenger->AddAura(SPELL_LOOT_SPARKLES, passenger);
                                    passenger->ToCreature()->DespawnOrUnsummon(300000);
                                    veh->RemoveAllPassengers();

                                    float ori = 1.642f;
                                    me->SetFacingTo(ori);
                                    float dist = 2.0f;
                                    float x = me->GetPositionX() + (dist * cos(ori));
                                    float y = me->GetPositionY() + (dist * sin(ori));
                                    Position pos = { x, y, 184.64f };
                                    me->MovePositionToFirstCollision(pos, 5.0f, me->GetAngle(&pos));
                                    passenger->GetMotionMaster()->MoveJump(pos, 20.0f, 10.0f);
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_MOVE_BACK_TO_BARREL_PICKUP_SPOT, 1500);
                        break;
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_CHU_START_PLANTING_BARRELS:
                        events.ScheduleEvent(EVENT_PICK_UP_BARREL, 500);
                        break;
                    case ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT_INITIAL:
                        me->GetMotionMaster()->MovePoint(0, isLoChu ? LoChuBarrelPlacePosition[0] : LiChuBarrelPlacePosition[0], false);
                        break;
                    case ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT:
                        me->GetMotionMaster()->MovePoint(POINT_LO_LI_CHU_BARREL_PICKUP_SPOT, isLoChu ? LoChuBarrelPlacePosition[0] : LiChuBarrelPlacePosition[0], false);
                        break;
                    case ACTION_ENCOUNTER_RESET:
                        events.Reset();
                        me->RemoveAllAuras();
                        EnterEvadeMode();
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_PICK_UP_BARREL:
                        me->SetWalk(false);
                        //me->AddAura(SPELL_CARRYING_CAUSTIC_TAR, me);
                        me->CastSpell(me, SPELL_GRAB_BARREL, false);
                        events.ScheduleEvent(EVENT_MOVE_TO_BARREL_DROP_SPOT, 500);
                        break;
                    case EVENT_MOVE_TO_BARREL_DROP_SPOT:
                    {
                        Position pos = isLoChu ? LoChuBarrelPlacePosition[urand(1, 2)] : LiChuBarrelPlacePosition[urand(1, 2)];
                        me->MovePosition(pos, 5.0f * (float)rand_norm(), (float)rand_norm() * static_cast<float>(2 * M_PI));
                        //me->MovePositionToFirstCollision(pos, 5.0f, me->GetAngle(&pos));
                        me->GetMotionMaster()->MovePoint(POINT_LO_LI_CHU_PLANT_BOMB_POS, pos, false);
                        break;
                    }
                    case EVENT_MOVE_BACK_TO_BARREL_PICKUP_SPOT:
                        me->GetMotionMaster()->MovePoint(POINT_LO_LI_CHU_BARREL_PICKUP_SPOT, isLoChu ? LoChuBarrelPlacePosition[0] : LiChuBarrelPlacePosition[0], false);
                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_lo_and_lo_chuAI(creature);
        }
};

class npc_commander_vojak_sikthik_swarmer : public CreatureScript
{
    public:
        npc_commander_vojak_sikthik_swarmer() : CreatureScript("npc_commander_vojak_sikthik_swarmer") { }

        struct npc_commander_vojak_sikthik_swarmerAI : public ScriptedAI
        {
            npc_commander_vojak_sikthik_swarmerAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void JustRespawned()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(POINT_SIKTHIK_MOVE_TO_HALFWAY, 1549.96f, 5329.94f, 161.23f);
                events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 1500);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_SIKTHIK_MOVE_TO_HALFWAY)
                {
                    me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_PLATFORM_TOP, 1513.30f, 5297.26f, 184.64f);
                    me->SetReactState(REACT_PASSIVE);
                }
                else if (pointId == POINT_MOVE_TO_PLATFORM_TOP)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    AttackStart(me->SelectNearestPlayer(100.0f));
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_CHECK_FOR_SAP_PUDDLE:
                        if (me->FindNearestCreature(NPC_SAP_PUDDLE, 5.0f))
                            me->AddAura(SPELL_SAP_PUDDLE_SLOW, me);
                        else
                            me->RemoveAurasDueToSpell(SPELL_SAP_PUDDLE_SLOW);

                        events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 250);
                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_sikthik_swarmerAI(creature);
        }
};

class npc_commander_vojak_sikthik_demolisher : public CreatureScript
{
    public:
        npc_commander_vojak_sikthik_demolisher() : CreatureScript("npc_commander_vojak_sikthik_demolisher") { }

        struct npc_commander_vojak_sikthik_demolisherAI : public ScriptedAI
        {
            npc_commander_vojak_sikthik_demolisherAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_CARRYING_EXPLOSIVES, false);
            }

            void JustRespawned()
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_CARRYING_EXPLOSIVES, false);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_CARRYING_EXPLOSIVES, false);
                me->GetMotionMaster()->MovePoint(POINT_SIKTHIK_MOVE_TO_HALFWAY, 1549.96f, 5329.94f, 161.23f);
                events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 1500);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_SIKTHIK_MOVE_TO_HALFWAY)
                {
                    me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_PLATFORM_TOP, 1513.30f, 5297.26f, 184.64f);
                    me->SetReactState(REACT_PASSIVE);
                }
                else if (pointId == POINT_MOVE_TO_PLATFORM_TOP)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    AttackStart(me->SelectNearestPlayer(100.0f));
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_CHECK_FOR_SAP_PUDDLE:
                        if (me->FindNearestCreature(NPC_SAP_PUDDLE, 5.0f))
                            me->AddAura(SPELL_SAP_PUDDLE_SLOW, me);
                        else
                            me->RemoveAurasDueToSpell(SPELL_SAP_PUDDLE_SLOW);

                        events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 250);
                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_sikthik_demolisherAI(creature);
        }
};

class npc_commander_vojak_sikthik_warrior : public CreatureScript
{
    public:
        npc_commander_vojak_sikthik_warrior() : CreatureScript("npc_commander_vojak_sikthik_warrior") { }

        struct npc_commander_vojak_sikthik_warriorAI : public ScriptedAI
        {
            npc_commander_vojak_sikthik_warriorAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void JustRespawned()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(POINT_SIKTHIK_MOVE_TO_HALFWAY, 1549.96f, 5329.94f, 161.23f);
                events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 1500);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_SIKTHIK_MOVE_TO_HALFWAY)
                {
                    me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_PLATFORM_TOP, 1513.30f, 5297.26f, 184.64f);
                    me->SetReactState(REACT_PASSIVE);
                }
                else if (pointId == POINT_MOVE_TO_PLATFORM_TOP)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    AttackStart(me->SelectNearestPlayer(100.0f));
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_CHECK_FOR_SAP_PUDDLE:
                        if (me->FindNearestCreature(NPC_SAP_PUDDLE, 5.0f))
                            me->AddAura(SPELL_SAP_PUDDLE_SLOW, me);
                        else
                            me->RemoveAurasDueToSpell(SPELL_SAP_PUDDLE_SLOW);

                        events.ScheduleEvent(EVENT_CHECK_FOR_SAP_PUDDLE, 250);
                        break;
                }

                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_sikthik_warriorAI(creature);
        }
};

class npc_commander_vojak_sikthik_amberwing : public CreatureScript
{
    public:
        npc_commander_vojak_sikthik_amberwing() : CreatureScript("npc_commander_vojak_sikthik_amberwing") { }

        struct npc_commander_vojak_sikthik_amberwingAI : public ScriptedAI
        {
            npc_commander_vojak_sikthik_amberwingAI(Creature* creature) : ScriptedAI(creature) { }

            uint8 waypointProgress;

            void Reset()
            {
                StartMoving();
            }

            void JustRespawned()
            {
                StartMoving();
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                StartMoving();
            }

            void StartMoving()
            {
                me->AddAura(SPELL_BOMBARD_PERIODIC, me);
                me->SetWalk(false);
                me->SetCanFly(true);
                me->SetSpeed(MOVE_RUN, 2.0f);
                me->SetSpeed(MOVE_FLIGHT, 2.0f);

                me->SetReactState(REACT_PASSIVE);
                waypointProgress = 5;
                me->GetMotionMaster()->MovePoint(POINT_AMBERWING_WAYPOINT, SikthikAmberwingWaypoint[waypointProgress].GetPositionX(), SikthikAmberwingWaypoint[waypointProgress].GetPositionY(), SikthikAmberwingWaypoint[waypointProgress].GetPositionZ(), false);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (pointId == POINT_AMBERWING_WAYPOINT)
                {
                    Talk(0);
                    me->SetFacingTo(4.79f);
                    //me->CastSpell(me, SPELL_BOMBARD_PERIODIC, false);
                    events.ScheduleEvent(EVENT_AMBERWING_RETREAT, 25000);
                    me->SetCanFly(true);
                }
                else if (pointId == POINT_AMBERWING_RETREAT)
                    events.ScheduleEvent(EVENT_AMBERWING_START_MOVING, 27500);

                //{
                //    if (waypointProgress == 6)
                //        events.ScheduleEvent(EVENT_AMBERWING_RETREAT, 15000);
                //    else
                //        me->GetMotionMaster()->MovePoint(POINT_AMBERWING_WAYPOINT, SikthikAmberwingWaypoint[waypointProgress].GetPositionX(), SikthikAmberwingWaypoint[waypointProgress].GetPositionY(), SikthikAmberwingWaypoint[waypointProgress].GetPositionZ(), false);
                //
                //    waypointProgress++;
                //}
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_AMBERWING_RETREAT:
                        Talk(1);
                        waypointProgress = 0;
                        me->GetMotionMaster()->MovePoint(POINT_AMBERWING_RETREAT, SikthikAmberwingWaypoint[0].GetPositionX(), SikthikAmberwingWaypoint[0].GetPositionY(), SikthikAmberwingWaypoint[0].GetPositionZ(), false);
                        //me->DespawnOrUnsummon(5000);
                        //me->RemoveAurasDueToSpell(SPELL_BOMBARD_PERIODIC);
                        break;
                    case EVENT_AMBERWING_START_MOVING:
                        StartMoving();
                        break;
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_sikthik_amberwingAI(creature);
        }
};

class npc_commander_vojak_sap_puddle : public CreatureScript
{
    public:
        npc_commander_vojak_sap_puddle() : CreatureScript("npc_commander_vojak_sap_puddle") { }

        struct npc_commander_vojak_sap_puddleAI : public ScriptedAI
        {
            npc_commander_vojak_sap_puddleAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                damage = 0;
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                if (Creature* demolisher = me->FindNearestCreature(NPC_SIKTHIK_DEMOLISHER, 8.0f))
                    me->Kill(demolisher);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_commander_vojak_sap_puddleAI(creature);
        }
};

class spell_commander_vojak_player_throw_barrel : public SpellScriptLoader
{
    public:
        spell_commander_vojak_player_throw_barrel() : SpellScriptLoader("spell_commander_vojak_player_throw_barrel") { }

        class spell_commander_vojak_player_throw_barrel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_commander_vojak_player_throw_barrel_SpellScript);

            void CastAura()
            {
                if (Unit* caster = GetCaster())
                    caster->RemoveAurasDueToSpell(SPELL_CARRYING_CAUSTIC_TAR);
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_commander_vojak_player_throw_barrel_SpellScript::CastAura);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_commander_vojak_player_throw_barrel_SpellScript();
        }
};

class BarrelTargetSelector
{
    public:
        BarrelTargetSelector() { }

        bool operator()(WorldObject* object)
        {
            return !object || object->GetEntry() != 61817;
        }
};

class spell_commander_vojak_grab_barrel : public SpellScriptLoader
{
    public:
        spell_commander_vojak_grab_barrel() : SpellScriptLoader("spell_commander_vojak_grab_barrel") { }

        class spell_commander_vojak_grab_barrel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_commander_vojak_grab_barrel_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BarrelTargetSelector());
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetHitUnit())
                        target->CastSpell(caster, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_commander_vojak_grab_barrel_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_commander_vojak_grab_barrel_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_commander_vojak_grab_barrel_SpellScript();
        }
};

class BombardPlayerTargetSelector
{
    public:
        BombardPlayerTargetSelector() { }

        bool operator()(WorldObject* object)
        {
            return !object || object->GetTypeId() != TYPEID_PLAYER;
        }
};

class spell_commander_vojak_bombard_trigger : public SpellScriptLoader
{
    public:
        spell_commander_vojak_bombard_trigger() : SpellScriptLoader("spell_commander_vojak_bombard_trigger") { }

        class spell_commander_vojak_bombard_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_commander_vojak_bombard_trigger_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BombardPlayerTargetSelector());
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        caster->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, true);
                        caster->SetFacingToObject(target);
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_commander_vojak_bombard_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_commander_vojak_bombard_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_commander_vojak_bombard_trigger_SpellScript();
        }
};

void AddSC_boss_commander_vojak()
{
    new boss_commander_vojak();

    new npc_commander_vojak_mantid_tar_keg();
    new npc_commander_vojak_yang_ironclaw();
    new npc_commander_vojak_lo_and_lo_chu();
    new npc_commander_vojak_sap_puddle();
    new npc_commander_vojak_sikthik_swarmer();
    new npc_commander_vojak_sikthik_warrior();
    new npc_commander_vojak_sikthik_demolisher();
    new npc_commander_vojak_sikthik_amberwing();

    new spell_commander_vojak_player_throw_barrel();
    new spell_commander_vojak_grab_barrel();
    new spell_commander_vojak_bombard_trigger();
}
