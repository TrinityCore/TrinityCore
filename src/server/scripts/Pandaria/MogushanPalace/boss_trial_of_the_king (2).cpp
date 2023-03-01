///*
// *   Dungeon : Mogu'shan palace 87-89
// *   Trial of the king
// *   Jade servers
// */
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "mogu_shan_palace.h"
//
//#define SPELL_GUARDIAN_GRUNT 85667
//
//enum Effect
//{
//    EFFECT_0,
//    EFFECT_1,
//    EFFECT_2,
//    EFFECT_3,
//};
//
//
//enum eBosses
//{
//    BOSS_MING_THE_CUNNING,
//    BOSS_KUAI_THE_BRUTE,
//    BOSS_HAIYAN_THE_UNSTOPPABLE,
//};
//
//static const Position pXinWaypoints[] =
//{
//    { -4365.8f, -2613.6f, 22.3f, 0.0f },
//    { -4365.6f, -2647.3f, 22.3f, 0.0f },
//    { -4399.3f, -2647.0f, 22.3f, 0.0f }
//};
//
//static const Position pTrialHomePositions[] =
//{
//    { -4257.5f, -2613.5f, 17.5f, 6.25f },
//    { -4215.9f, -2583.2f, 17.5f, 4.70f },
//    { -4215.8f, -2644.2f, 17.5f, 1.57f }
//};
//
//static const Position apSaurokWaypoints[] =
//{
//    { -4235.7f, -2672.3f,  17.50f, 0.0f },
//    { -4226.6f, -2686.2f,  13.70f, 0.0f },
//    { -4211.7f, -2688.2f,  10.90f, 0.0f },
//    { -4199.6f, -2681.4f,  7.700f, 0.0f },
//    { -4194.6f, -2666.6f,  3.600f, 0.0f },
//    { -4193.5f, -2643.3f, -3.600f, 0.0f },
//    { -4196.6f, -2626.6f, -7.800f, 0.0f },
//    { -4191.7f, -2596.7f, -9.400f, 0.0f },
//    { -4194.9f, -2574.7f, -9.700f, 0.0f },
//    { -4192.1f, -2552.4f, -20.80f, 0.0f },
//    { -4196.7f, -2529.2f, -28.40f, 0.0f },
//    { -4218.5f, -2518.3f, -28.39f, 0.0f },
//    { -4264.0f, -2519.9f, -39.00f, 0.0f },
//    { -4356.5f, -2519.2f, -28.20f, 0.0f }
//};
//
//static const Position apCaveBatPositions[6]
//{
//    { -4268.7f, -2664.5f, -22.2f, 0.0f },
//    { -4293.1f, -2669.8f, -36.1f, 0.0f },
//    { -4262.9f, -2654.9f, -1.06f, 0.0f },
//    { -4283.3f, -2461.4f, -14.3f, 0.0f },
//    { -4289.3f, -2466.3f, -20.0f, 0.0f },
//    { -4282.4f, -2470.2f, -22.0f, 0.0f }
//};
//
//// Since the bosses have different action numbers we track them in this constructor
//struct BossAction
//{
//    uint32 m_uiBoss;
//    const int32 m_uiAction;
//};
//
//static const BossAction aBosses[3] =
//{
//    { CREATURE_HAIYAN_THE_UNSTOPPABLE, 2},
//    { CREATURE_MING_THE_CUNNING, 2},
//    { CREATURE_KUAI_THE_BRUTE, 5}
//};
//
//static const Position pXinJumpPoint{ -4296.391f, -2613.577f, 22.325f, 0.0f };
//
//const uint32 auiStanceSpells[5] =
//{
//    SPELL_REPLACE_STAND_APPLAUD,
//    SPELL_REPLACE_STAND_CHEER,
//    SPELL_REPLACE_STAND_LAUGH,
//    SPELL_REPLACE_STAND_RUDE,
//    SPELL_REPLACE_STAND_SHOUT
//};
//
//
//const uint32 auiRetireSpells[3] =
//{
//    SPELL_REPLACE_STAND_CRY,
//    SPELL_REPLACE_STAND_READY1H,
//    SPELL_REPLACE_STAND_NO
//};
//
//const uint32 auiGruntScaleSpells[3] =
//{
//    SPELL_SCALE_95_100,
//    SPELL_SCALE_105_110,
//    SPELL_SCALE_115_120
//};
//
//class mob_xian_the_weaponmaster_trigger : public CreatureScript
//{
//public:
//    mob_xian_the_weaponmaster_trigger() : CreatureScript("mob_xian_the_weaponmaster_trigger") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_xian_the_weaponmaster_trigger_AI(creature);
//    }
//
//    enum eEvents
//    {
//        EVENT_INITIATE_SPEECH = 1,
//        EVENT_TALK_0          = 2,
//        EVENT_TALK_1          = 3,
//        EVENT_JUMP            = 4,
//        EVENT_INITIATE_FIGHT  = 5,
//        EVENT_START_COMBAT    = 6,
//        EVENT_MOVECHECK       = 7,
//        EVENT_SET_ORIENTATION = 8,
//        EVENT_IDLE_TALK       = 9,
//    };
//
//    enum eSpells
//    {
//        SPELL_MOGU_JUMP                 = 120444,
//    };
//
//    enum eTalks
//    {
//        TALK_INTRO_01,
//        TALK_INTRO_02,
//    };
//
//    struct mob_xian_the_weaponmaster_trigger_AI : public ScriptedAI
//    {
//        mob_xian_the_weaponmaster_trigger_AI(Creature* creature) : ScriptedAI(creature)
//        {
//            m_uiLastBoss = 0;
//            m_bEventGo = false;
//            m_mEvents.ScheduleEvent(EVENT_IDLE_TALK, urand(5000,25000));
//        }
//
//        EventMap m_mEvents;
//        bool m_bEventGo;
//
//        uint32 m_uiWaypointCount;
//        // Which boss talked last (used to prevent bosses talking twice in a row)
//        uint32 m_uiLastBoss;
//
//        void Reset()
//        {
//            m_bEventGo = false;
//            me->GetMotionMaster()->MoveTargetedHome();
//            SetCanSeeEvenInPassiveMode(true);
//
//            if (me->GetInstanceScript() && me->GetInstanceScript()->GetData(TYPE_TRIAL_CHEST) == DONE)
//            {
//                m_bEventGo = true;
//                me->SetVisible(false);
//            }
//        }
//
//        void MoveInLineOfSight(Unit* who)
//        {
//            // Launch the speech when a player steps close to Xin the Weaponmaster
//            if (!m_bEventGo && who->GetTypeId() == TYPEID_PLAYER && (who->GetDistance2d(me) < 35.0f))
//            {
//                m_bEventGo = true;
//                m_mEvents.ScheduleEvent(EVENT_INITIATE_SPEECH, 3000);
//                m_mEvents.CancelEvent(EVENT_IDLE_TALK);
//            }
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            switch (uiPointId)
//            {
//                case 0:
//                case 1:
//                    m_mEvents.ScheduleEvent(EVENT_MOVECHECK, 200);
//                    ++m_uiWaypointCount;
//                    break;
//                case 2:
//                    m_mEvents.Reset();
//                    me->SetVisible(false);
//                    break;
//            }
//        }
//
//        void HandleIdleTalk()
//        {
//            // as we will need the actual rand value for later, we initialize it here
//            uint32 m_uiRand = urand(0, 2);
//            // Which boss will talk next
//            uint32 m_uiNewBoss = aBosses[m_uiRand].m_uiBoss;;
//
//            while (m_uiNewBoss == m_uiLastBoss)
//            {
//                m_uiRand = urand(0, 2);
//                m_uiNewBoss = aBosses[m_uiRand].m_uiBoss;
//            }
//
//            m_uiLastBoss = m_uiNewBoss;
//
//            if (Creature* pBoss = GetClosestCreatureWithEntry(me, m_uiNewBoss, 99.f))
//            {
//                if (pBoss->AI())
//                    pBoss->AI()->DoAction(aBosses[m_uiRand].m_uiAction);
//            }
//
//            m_mEvents.ScheduleEvent(EVENT_IDLE_TALK, urand(15000,25000));
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            m_mEvents.Update(diff);
//
//            while (uint32 eventId = m_mEvents.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_INITIATE_SPEECH:
//                        me->GetMotionMaster()->Clear(false);
//                        me->GetMotionMaster()->MoveIdle();
//                        m_mEvents.ScheduleEvent(EVENT_TALK_0, 400);
//                        break;
//                    case EVENT_TALK_0:
//                        Talk(TALK_INTRO_01);
//                        // Sniff data says 11 seconds
//                        m_mEvents.ScheduleEvent(EVENT_TALK_1, 11000);
//                        break;
//                    case EVENT_TALK_1:
//                        Talk(TALK_INTRO_02);
//                        m_mEvents.ScheduleEvent(EVENT_JUMP, 5000);
//                        break;
//                    case EVENT_JUMP:
//                        DoCast(SPELL_MOGU_JUMP);
//                        m_mEvents.ScheduleEvent(EVENT_INITIATE_FIGHT, 8000);
//                        m_mEvents.ScheduleEvent(EVENT_SET_ORIENTATION, 2800);
//                        break;
//                    case EVENT_INITIATE_FIGHT:
//                        // here is when we should start running away
//                        me->SetWalk(false);
//                        m_mEvents.ScheduleEvent(EVENT_START_COMBAT, 1400);
//                        m_mEvents.ScheduleEvent(EVENT_MOVECHECK, 200);
//                        m_uiWaypointCount = 0;
//                        break;
//                    case EVENT_START_COMBAT:
//                        if (me->GetInstanceScript())
//                            me->GetInstanceScript()->SetData(TYPE_SHUFFLE_ORDER, 0);
//                        break;
//                    case EVENT_MOVECHECK:
//                        me->GetMotionMaster()->MovePoint(m_uiWaypointCount, pXinWaypoints[m_uiWaypointCount]);
//                        break;
//                    case EVENT_SET_ORIENTATION:
//                        me->SetFacingTo(6.25f);
//                        break;
//                    case EVENT_IDLE_TALK:
//                        HandleIdleTalk();
//                        break;
//                }
//            }
//        }
//    };
//};
//
//class boss_ming_the_cunning : public CreatureScript
//{
//public:
//    boss_ming_the_cunning() : CreatureScript("boss_ming_the_cunning") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_ming_the_cunning_AI(creature);
//    }
//
//    enum eEvents
//    {
//        EVENT_LIGHTNING_BOLT = 1,
//        EVENT_WHIRLING_DERVISH = 2,
//        EVENT_MAGNETIC_FIELD   = 3,
//        EVENT_BOSS_RETIRE = 4,
//    };
//
//    enum eSpells
//    {
//        SPELL_LIGHTNING_BOLT            = 123654,
//        SPELL_WHIRLING_DERVISH          = 119981,
//        SPELL_MAGNETIC_FIELD_AURA       = 120100,
//    };
//
//    enum eActions
//    {
//        ACTION_INTRO,
//        ACTION_TALK_1,
//        ACTION_TALK_IDLE
//    };
//
//    enum eTalks
//    {
//        TALK_INTRO,
//        TALK_DEFEATED,
//        TALK_KILLING,
//        TALK_POSTCOMBAT,
//        TALK_IDLE_1,
//        TALK_WHIRLING_DERVISH,
//        TALK_MAGNETIC_FIELD
//    };
//
//    struct boss_ming_the_cunning_AI : public BossAI
//    {
//        boss_ming_the_cunning_AI(Creature* creature) : BossAI(creature, BOSS_MING_THE_CUNNING)
//        {
//            me->SetHomePosition(pTrialHomePositions[TYPE_MING]);
//        }
//
//        bool m_bIsMovingHome;
//
//        void InitializeAI() final
//        {
//            Reset();
//            SetImmuneToPullPushEffects(true);
//        }
//
//        void EnterEvadeMode()
//        {
//            _EnterEvadeMode();
//
//            if (instance)
//                instance->SetData(TYPE_WIPE_FIRST_BOSS, 0);
//
//            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
//
//            events.Reset();
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            if (uiPointId == 0)
//                DoZoneInCombat();
//
//            if (uiPointId == 1)
//                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//        }
//
//        void EnterCombat(Unit* /*unit*/)
//        {
//            if (instance->GetData(TYPE_SHUFFLE_ORDER) == DONE)
//                return;
//
//            me->CastSpell(me, SPELL_GUARDIAN_GRUNT, false);
//            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 3000);
//            events.ScheduleEvent(EVENT_WHIRLING_DERVISH, 10000);
//            events.ScheduleEvent(EVENT_MAGNETIC_FIELD, 30000);
//
//            m_bIsMovingHome = false;
//        }
//
//        void KilledUnit(Unit* /*u*/)
//        {
//            Talk(TALK_KILLING);
//        }
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_INTRO:
//                    Talk(TALK_INTRO);
//                    break;
//                case ACTION_TALK_1:
//                    Talk(TALK_POSTCOMBAT);
//                    break;
//                case ACTION_TALK_IDLE:
//                    Talk(TALK_IDLE_1);
//                    break;
//            }
//        }
//
//        void HandleRetire()
//        {
//            me->RemoveAllAuras();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetHomePosition(pTrialHomePositions[TYPE_MING]);
//            me->GetMotionMaster()->MoveTargetedHome();
//            me->AttackStop();
//            me->CastStop();
//            events.Reset();
//            events.ScheduleEvent(EVENT_BOSS_RETIRE, 11000);
//            if (instance)
//                instance->SetData(TYPE_MING_RETIRED, 0);
//
//            m_bIsMovingHome = true;
//        }
//
//        void DamageTaken(Unit* /*killer*/, uint32 &damage)
//        {
//            //We need to retire Ming and let the next boss enter combat.
//            if ((me->GetHealthPct() < 10.f || damage > me->GetHealth()) && !m_bIsMovingHome)
//            {
//                Talk(TALK_DEFEATED);
//                damage = 0;
//
//                HandleRetire();
//            }
//
//            if (m_bIsMovingHome)
//                damage = 0;
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            events.Update(diff);
//
//            if (!UpdateVictim())
//                return;
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_LIGHTNING_BOLT:
//                        me->CastSpell(me->getVictim(), SPELL_LIGHTNING_BOLT, false);
//                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, urand(5000,9000));
//                        break;
//                    case EVENT_WHIRLING_DERVISH:
//                        Talk(TALK_WHIRLING_DERVISH);
//                        DoCast(SPELL_WHIRLING_DERVISH);
//                        events.ScheduleEvent(EVENT_WHIRLING_DERVISH, urand(13000,19000));
//                        break;
//                    case EVENT_MAGNETIC_FIELD:
//                        Talk(TALK_MAGNETIC_FIELD);
//                        DoCast(SPELL_MAGNETIC_FIELD_AURA);
//                        events.ScheduleEvent(EVENT_MAGNETIC_FIELD, 30000);
//                        break;
//                    case EVENT_BOSS_RETIRE:
//                        if (instance)
//                            instance->SetData(TYPE_SHUFFLE_ORDER, 0);
//                        break;
//                }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class mob_whirling_dervish : public CreatureScript
//{
//public:
//    mob_whirling_dervish() : CreatureScript("mob_whirling_dervish") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_whirling_dervish_AI(creature);
//    }
//
//    enum eSpells
//    {
//        SPELL_WHIRLING_DERVISH_AURA        = 119982,
//        SPELL_WHIRLING_DERVISH_3           = 119994,
//        SPELL_THROW                        = 120087,
//        SPELL_THROW_2                      = 120035,
//    };
//
//    enum eEvents
//    {
//        EVENT_INITIALIZE_MYSELF = 1,
//        EVENT_MOVE              = 2,
//    };
//
//    struct mob_whirling_dervish_AI : public ScriptedAI
//    {
//        mob_whirling_dervish_AI(Creature* creature) : ScriptedAI(creature)
//        {
//            events.ScheduleEvent(EVENT_INITIALIZE_MYSELF, 300);
//            events.ScheduleEvent(EVENT_MOVE, 3000);
//            m_bClockWise = urand(0, 1);
//            me->GetPosition(x, y, z);
//
//            // Radius of our circle should be 20 yards give or take
//            m_uiArcRadius = 20.f;
//            m_uiArcOffset = 0;
//        }
//
//        uint32 m_uiArcOffset;
//        float m_uiArcRadius;
//        bool m_bClockWise;
//
//        float x, y, z;
//
//        void HandleCircularMovement()
//        {
//            float newX, newY, newZ;
//
//            newX = x + m_uiArcRadius*cos(m_uiArcOffset*M_PI / 12);
//            newY = m_bClockWise ? y + m_uiArcRadius*sin(m_uiArcOffset*M_PI / 12) : y - m_uiArcRadius*sin(m_uiArcOffset*M_PI / 12);
//            newZ = me->GetMap()->GetHeight(newX, newY, z);
//
//            me->GetMotionMaster()->MovementExpired();
//            me->GetMotionMaster()->MovePoint(0, newX, newY, newZ);
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            if (uiPointId == 0)
//            {
//                // make sure we offset next point in circle
//                ++m_uiArcOffset;
//                // next update tick
//                events.ScheduleEvent(EVENT_MOVE, 100);
//            }
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            events.Update(diff);
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_INITIALIZE_MYSELF:
//                        if (!me->HasAura(SPELL_WHIRLING_DERVISH_AURA))
//                            DoCast(SPELL_WHIRLING_DERVISH_AURA);
//                        events.ScheduleEvent(EVENT_INITIALIZE_MYSELF, 2500);
//                        break;
//                    case EVENT_MOVE:
//                        HandleCircularMovement();
//                        break;
//                }
//            }
//        }
//    };
//};
//
//class mob_adepts : public CreatureScript
//{
//public:
//    mob_adepts() : CreatureScript("mob_adepts") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_adepts_AI(creature);
//    }
//
//    enum eEvents
//    {
//        EVENT_CHECK_MOVE = 1,
//    };
//
//    enum eActions
//    {
//        ACTION_ENCOURAGE,
//        ACTION_RETIRE,
//        ACTION_ATTACK,
//    };
//
//    enum eStatus
//    {
//        STATUS_ATTACK_PLAYER,
//        STATUS_ATTACK_GRUNTS,
//    };
//
//    enum eTalks
//    {
//        TALK_00,
//    };
//
//    struct mob_adepts_AI : public ScriptedAI
//    {
//        mob_adepts_AI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetWalk(false);
//            status = STATUS_ATTACK_PLAYER;
//            m_uiKickCooldownTimer = 0;
//            me->SetReactState(REACT_AGGRESSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            DoCast(auiGruntScaleSpells[urand(0, 2)]);
//            events.ScheduleEvent(EVENT_CHECK_MOVE, 2500);
//        }
//        uint8 status;
//        uint32 m_uiKickCooldownTimer;
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_ENCOURAGE:
//                {
//                    float x, y;
//                    GetPositionWithDistInOrientation(me, 5.0f, me->GetOrientation(), x, y);
//                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));
//
//                    DoCast(auiStanceSpells[urand(0, 4)]);
//                    break;
//                }
//                case ACTION_RETIRE:
//                {
//                    float x, y;
//                    GetPositionWithDistInOrientation(me, -5.0f, me->GetOrientation(), x, y);
//                    me->GetMotionMaster()->MovePoint(1, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));
//
//                    me->RemoveAurasByType(SPELL_AURA_ANIM_REPLACEMENT_SET);
//                    DoCast(auiRetireSpells[urand(0, 2)]);
//
//                    me->CombatStop();
//                    break;
//                }
//                case ACTION_ATTACK:
//                {
//                    me->CombatStop();
//                    status = STATUS_ATTACK_GRUNTS;
//
//                    float x, y;
//                    GetPositionWithDistInOrientation(me, 30.0f, me->GetOrientation(), x, y);
//                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));
//
//                    me->RemoveAurasByType(SPELL_AURA_ANIM_REPLACEMENT_SET);
//
//                    events.CancelEvent(EVENT_CHECK_MOVE);
//                    break;
//                }
//            }
//        }
//
//        void MovementInform(uint32 /*motionType*/, uint32 pointId)
//        {
//            if (pointId == 1)
//                me->SetFacingTo(me->GetOrientation() - M_PI);
//        }
//
//        void DamageTaken(Unit* /*pWho*/, uint32& uiDamage)
//        {
//            uiDamage = 0;
//        }
//
//        void MoveInLineOfSight(Unit* pWho)
//        {
//            if (pWho->GetTypeId() == TYPEID_PLAYER && pWho->GetAreaId() == 6471
//                    && status != STATUS_ATTACK_GRUNTS
//                    && me->GetDistance2d(pWho) < 2.0f
//                    && pWho->isInFront(me)
//                    && pWho->GetPositionZ() <= (me->GetPositionZ() + 3.f))
//            {
//                if (me->IsMoving() || m_uiKickCooldownTimer)
//                    return;
//
//                m_uiKickCooldownTimer = 1 * IN_MILLISECONDS;
//
//                DoCast(pWho, SPELL_GRUNT_KNOCK_2, true);
//                pWho->CastSpell(pWho, SPELL_GRUNT_KNOCK, true);
//
//                if (urand(0, 2))
//                    Talk(TALK_00, pWho->GetGUID());
//            }
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (m_uiKickCooldownTimer > diff)
//                m_uiKickCooldownTimer -= diff;
//            else
//                m_uiKickCooldownTimer = 0;
//
//            events.Update(diff);
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_CHECK_MOVE:
//                        me->CombatStop();
//                        if (me->GetDistance(me->GetHomePosition()) > 7.f)
//                            me->GetMotionMaster()->MoveTargetedHome();
//                        events.ScheduleEvent(EVENT_CHECK_MOVE, 2500);
//                        break;
//                }
//            }
//        }
//    };
//};
//
//class boss_kuai_the_brute : public CreatureScript
//{
//public:
//    boss_kuai_the_brute() : CreatureScript("boss_kuai_the_brute") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_kuai_the_brute_AI(creature);
//    }
//
//    enum eEvents
//    {
//        EVENT_SHOCKWAVE = 1,
//        EVENT_BOSS_RETIRE = 2,
//    };
//
//    enum eCreatures
//    {
//        CREATURE_MU_SHIBA = 61453,
//    };
//
//    enum eSpells
//    {
//        SPELL_SHOCKWAVE                 = 119922,
//        SPELL_PICK_SHOCKWAVE_TARGET     = 120499,
//    };
//
//    enum eActions
//    {
//        ACTION_ATTACK,
//        ACTION_ATTACK_STOP,
//        ACTION_INTRO,
//        ACTION_TALK_1,
//        ACTION_TALK_2,
//        ACTION_TALK_IDLE
//    };
//
//    enum eTalks
//    {
//        TALK_INTRO,
//        TALK_DEFEATED,
//        TALK_KILLING,
//        TALK_POSTCOMBAT_1,
//        TALK_POSTCOMBAT_2,
//        TALK_IDLE_1,
//        TALK_SHOCKWAVE
//    };
//
//    struct boss_kuai_the_brute_AI : public BossAI
//    {
//        boss_kuai_the_brute_AI(Creature* creature) : BossAI(creature, BOSS_KUAI_THE_BRUTE)
//        {
//            TempSummon* sum = me->SummonCreature(CREATURE_MU_SHIBA, me->GetPositionX() + 3 * cos(M_PI / 4), me->GetPositionY() + 3 * sin(M_PI / 4), me->GetPositionZ(), me->GetOrientation());
//            if (sum)
//            {
//                pet_guid = sum->GetGUID();
//                sum->setFaction(me->getFaction());
//            }
//
//            me->SetHomePosition(pTrialHomePositions[TYPE_KUAI]);
//        }
//        uint64 pet_guid;
//        bool m_bIsMovingHome;
//
//        void InitializeAI() final
//        {
//            Reset();
//            SetImmuneToPullPushEffects(true);
//        }
//
//        void EnterEvadeMode()
//        {
//            _EnterEvadeMode();
//
//            if (instance)
//                instance->SetData(TYPE_WIPE_FIRST_BOSS, 0);
//
//            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
//
//            events.Reset();
//        }
//
//        void KilledUnit(Unit* /*u*/)
//        {
//            Talk(TALK_KILLING);
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            if (uiPointId == 0)
//                DoZoneInCombat();
//
//            if (uiPointId == 1)
//                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//        }
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_INTRO:
//                    Talk(TALK_INTRO);
//                    break;
//                case ACTION_TALK_1:
//                    Talk(TALK_POSTCOMBAT_1);
//                    break;
//                case ACTION_TALK_2:
//                    Talk(TALK_POSTCOMBAT_2);
//                    break;
//                case ACTION_TALK_IDLE:
//                    Talk(TALK_IDLE_1);
//                    break;
//            }
//        }
//
//        void EnterCombat(Unit* /*unit*/)
//        {
//            if (instance->GetData(TYPE_SHUFFLE_ORDER) == DONE)
//                return;
//
//            events.ScheduleEvent(EVENT_SHOCKWAVE, 3000);
//
//            if (Creature* mu_shiba = me->GetMap()->GetCreature(pet_guid))
//                mu_shiba->AI()->DoAction(ACTION_ATTACK);
//
//            m_bIsMovingHome = false;
//        }
//
//        void HandleRetire()
//        {
//            me->RemoveAllAuras();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetHomePosition(pTrialHomePositions[TYPE_KUAI]);
//            me->CastStop();
//            me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
//            me->GetMotionMaster()->MoveTargetedHome();
//            me->AttackStop();
//            events.Reset();
//            events.ScheduleEvent(EVENT_BOSS_RETIRE, 11000);
//            if (instance)
//                instance->SetData(TYPE_KUAI_RETIRED, 0);
//
//            m_bIsMovingHome = true;
//
//            Creature* mu_shiba = me->GetMap()->GetCreature(pet_guid);
//            if (mu_shiba && mu_shiba->IsAlive())
//            {
//                mu_shiba->CastStop();
//                mu_shiba->GetMotionMaster()->MoveTargetedHome();
//                if (mu_shiba->GetAI())
//                    mu_shiba->GetAI()->DoAction(ACTION_ATTACK_STOP);
//            }
//        }
//
//        void DamageTaken(Unit* /*killer*/, uint32 &damage)
//        {
//            //We need to retire Kuai and let the next boss enter combat.
//            if ((me->GetHealthPct() < 10.f || damage > me->GetHealth()) && !m_bIsMovingHome)
//            {
//                Talk(TALK_DEFEATED);
//                damage = 0;
//
//                HandleRetire();
//            }
//
//            if (m_bIsMovingHome)
//                damage = 0;
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_SHOCKWAVE:
//                        Talk(TALK_SHOCKWAVE);
//                        DoCast(SPELL_PICK_SHOCKWAVE_TARGET);
//                        events.ScheduleEvent(EVENT_SHOCKWAVE, 15000);
//                        break;
//                    case EVENT_BOSS_RETIRE:
//                        if (instance)
//                            instance->SetData(TYPE_SHUFFLE_ORDER, 0);
//                        break;
//                }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class mob_mu_shiba : public CreatureScript
//{
//public:
//    mob_mu_shiba() : CreatureScript("mob_mu_shiba") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_mu_shiba_AI(creature);
//    }
//
//    enum eSpells
//    {
//        SPELL_RAVAGE        = 119948,
//    };
//
//    enum eActions
//    {
//        ACTION_ATTACK,
//        ACTION_ATTACK_STOP,
//    };
//
//    struct mob_mu_shiba_AI : public ScriptedAI
//    {
//        mob_mu_shiba_AI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//        }
//        EventMap events;
//
//        void InitializeAI() final
//        {
//            Reset();
//            SetImmuneToPullPushEffects(true);
//        }
//
//        void Reset()
//        {
//            DoAction(ACTION_ATTACK_STOP);
//        }
//
//        void EnterCombat(Unit* /*unit*/)
//        {
//            events.ScheduleEvent(1, 7000);
//        }
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_ATTACK:
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//                    DoZoneInCombat();
//
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
//                        AttackStart(target);
//                    break;
//                case ACTION_ATTACK_STOP:
//                    events.Reset();
//                    me->AttackStop();
//                    me->SetReactState(REACT_PASSIVE);
//                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//                    break;
//            }
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case 1:
//                        me->CastSpell(me->getVictim(), SPELL_RAVAGE, false);
//                        me->Attack(SelectTarget(SELECT_TARGET_RANDOM), false);
//                        events.ScheduleEvent(1, 25000);
//                        break;
//                }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class boss_haiyan_the_unstoppable : public CreatureScript
//{
//public:
//    boss_haiyan_the_unstoppable() : CreatureScript("boss_haiyan_the_unstoppable") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_haiyan_the_unstoppable_AI(creature);
//    }
//
//    enum eEvents
//    {
//        EVENT_TRAUMATIC_BLOW = 1,
//        EVENT_CONFLAGRATE = 2,
//        EVENT_METEOR   = 3,
//        EVENT_BOSS_RETIRE = 4,
//    };
//
//    enum eSpells
//    {
//        SPELL_TRAUMATIC_BLOW            = 123655,
//    };
//
//    enum eTalks
//    {
//        TALK_INTRO,
//        TALK_DEFEATED,
//        TALK_KILLING,
//        TALK_POSTCOMBAT,
//        TALK_IDLE_1,
//        TALK_CONFLAGRATE,
//        TALK_METEOR
//    };
//
//    enum eActions
//    {
//        ACTION_INTRO,
//        ACTION_TALK_1,
//        ACTION_TALK_IDLE
//    };
//
//    struct boss_haiyan_the_unstoppable_AI : public BossAI
//    {
//        boss_haiyan_the_unstoppable_AI(Creature* creature) : BossAI(creature, BOSS_HAIYAN_THE_UNSTOPPABLE)
//        {
//            me->SetHomePosition(pTrialHomePositions[TYPE_KUAI]);
//        }
//
//        bool m_bIsMovingHome;
//
//        void InitializeAI() final
//        {
//            Reset();
//            SetImmuneToPullPushEffects(true);
//        }
//
//        void EnterCombat(Unit* /*unit*/)
//        {
//            if (instance->GetData(TYPE_SHUFFLE_ORDER) == DONE)
//                return;
//
//            m_bIsMovingHome = false;
//            events.ScheduleEvent(EVENT_TRAUMATIC_BLOW, 3000);
//            events.ScheduleEvent(EVENT_CONFLAGRATE, 10000);
//            events.ScheduleEvent(EVENT_METEOR, 30000);
//        }
//
//        void EnterEvadeMode()
//        {
//            _EnterEvadeMode();
//
//            if (instance)
//                instance->SetData(TYPE_WIPE_FIRST_BOSS, 0);
//
//            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
//
//            events.Reset();
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            if (uiPointId == 0)
//                DoZoneInCombat();
//
//            if (uiPointId == 1)
//                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//        }
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_INTRO:
//                    Talk(TALK_INTRO);
//                    break;
//                case ACTION_TALK_1:
//                    Talk(TALK_POSTCOMBAT);
//                    break;
//                case ACTION_TALK_IDLE:
//                    Talk(TALK_IDLE_1);
//                    break;
//            }
//        }
//
//        void KilledUnit(Unit* /*u*/)
//        {
//            Talk(TALK_KILLING);
//        }
//
//        void HandleRetire()
//        {
//            me->RemoveAllAuras();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            me->CastStop();
//            me->SetHomePosition(pTrialHomePositions[TYPE_HAIYAN]);
//            me->GetMotionMaster()->MoveTargetedHome();
//            me->AttackStop();
//            events.Reset();
//            events.ScheduleEvent(EVENT_BOSS_RETIRE, 11000);
//            if (instance)
//                instance->SetData(TYPE_HAIYAN_RETIRED, 0);
//
//            m_bIsMovingHome = true;
//        }
//
//        void DamageTaken(Unit* /*killer*/, uint32 &damage)
//        {
//            //We need to retire Haiyan and let the next boss enter combat.
//            if ((me->GetHealthPct() < 10.f || damage > me->GetHealth()) && !m_bIsMovingHome)
//            {
//                Talk(TALK_DEFEATED);
//                damage = 0;
//
//                HandleRetire();
//            }
//
//            if (m_bIsMovingHome)
//                damage = 0;
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_TRAUMATIC_BLOW:
//                        me->CastSpell(me->getVictim(), SPELL_TRAUMATIC_BLOW, false);
//                        events.ScheduleEvent(EVENT_TRAUMATIC_BLOW, urand(5000,9000));
//                        break;
//                    case EVENT_CONFLAGRATE:
//                        Talk(TALK_CONFLAGRATE);
//                        DoCast(SPELL_CONFLAGRATE);
//                        events.ScheduleEvent(EVENT_CONFLAGRATE, urand(9000, 14000));
//                        break;
//                    case EVENT_METEOR:
//                        Talk(TALK_METEOR);
//                        DoCast(SPELL_METEOR_TARGETING);
//                        events.ScheduleEvent(EVENT_METEOR, urand(23000, 30000));
//                        break;
//                    case EVENT_BOSS_RETIRE:
//                        if (instance)
//                            instance->SetData(TYPE_SHUFFLE_ORDER, 0);
//                        break;
//                }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class npc_glintrok_scout : public CreatureScript
//{
//public:
//    npc_glintrok_scout() : CreatureScript("npc_glintrok_scout") { }
//
//    CreatureAI* GetAI(Creature* pCreature) const
//    {
//        return new npc_glintrok_scoutAI(pCreature);
//    }
//
//    enum eSpells : uint32
//    {
//        SPELL_TAKE_LOOT     = 125265,
//        SPELL_CAVEBAT_VISUAL= 119319
//    };
//
//    enum eTalks
//    {
//        EMOTE_1
//    };
//
//    enum eActions
//    {
//        ACTION_INITIALIZE,
//    };
//
//    enum eEvents
//    {
//        EVENT_LOOT_CHEST    = 1,
//        EVENT_START_MOVING  = 2,
//        EVENT_MOVECHECK     = 3,
//        EVENT_TALK_1        = 4,
//        EVENT_TALK_2        = 5,
//        EVENT_TALK_3        = 6,
//        EVENT_TALK_4        = 7,
//        EVENT_START_BATTLE  = 8,
//        EVENT_SUMMON_BAT    = 9
//    };
//
//    struct npc_glintrok_scoutAI : public ScriptedAI
//    {
//        npc_glintrok_scoutAI(Creature* pCreature) : ScriptedAI(pCreature) { }
//
//        uint32 m_uiWayPointCount;
//
//        void DoAction(const int32 iAction)
//        {
//            switch (iAction)
//            {
//                case ACTION_INITIALIZE:
//                    me->SetReactState(REACT_PASSIVE);
//                    me->SetPhaseMask(1, true);
//                    me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
//                    events.ScheduleEvent(EVENT_LOOT_CHEST, 5000);
//                    events.ScheduleEvent(EVENT_TALK_1, 10000);
//
//                    if (auto const script = me->GetInstanceScript())
//                        script->SetData(TYPE_TRIAL_CHEST, DONE);
//                    break;
//            }
//        }
//
//        bool HandleBatSummons(int n)
//        {
//            if (n < 0)
//                return false;
//
//            if (Creature* pBat = me->SummonCreature(CREATURE_CAVE_BAT, apCaveBatPositions[n], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
//            {
//                pBat->SetCanFly(true);
//                pBat->CastSpell(pBat, SPELL_CAVEBAT_VISUAL, true);
//                pBat->GetMotionMaster()->MovePoint(0, n > 2 ? apCaveBatPositions[urand(0, 2)] : apCaveBatPositions[urand(3, 5)]);
//            }
//
//            return HandleBatSummons(n - 1);
//        }
//
//        Creature* GetAffectedBoss(uint32 uiType)
//        {
//            Creature* pCreature = NULL;
//
//            if (me->GetInstanceScript())
//                pCreature = ObjectAccessor::GetCreature(*me, (me->GetInstanceScript()->GetData64(uiType)));
//
//            return pCreature;
//        }
//
//        void ClearCombat()
//        {
//            Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
//
//            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
//            {
//                if (Player* pPlayer = itr->getSource())
//                    pPlayer->CombatStop();
//            }
//        }
//
//        void MovementInform(uint32 uiType, uint32 uiPointId)
//        {
//            if (uiType != POINT_MOTION_TYPE)
//                return;
//
//            if (uiPointId >= 13)
//            {
//                me->SetVisible(false);
//                events.CancelEvent(EVENT_MOVECHECK);
//            }
//            else
//            {
//                events.ScheduleEvent(EVENT_MOVECHECK, 100);
//                ++m_uiWayPointCount;
//            }
//        }
//
//        void UpdateAI(const uint32 uiDiff)
//        {
//            events.Update(uiDiff);
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_LOOT_CHEST:
//                        me->HandleEmoteCommand(EMOTE_STATE_NONE);
//                        DoCast(SPELL_TAKE_LOOT);
//                        events.ScheduleEvent(EVENT_START_MOVING, 500);
//
//                        ClearCombat();
//                        break;
//                    case EVENT_START_MOVING:
//                        Talk(EMOTE_1);
//                        me->SetWalk(false);
//                        events.ScheduleEvent(EVENT_MOVECHECK, 200);
//                        events.ScheduleEvent(EVENT_SUMMON_BAT, 4000);
//                        m_uiWayPointCount = 0;
//                        break;
//                    case EVENT_MOVECHECK:
//                        me->GetMotionMaster()->Clear(false);
//                        me->GetMotionMaster()->MovePoint(m_uiWayPointCount, apSaurokWaypoints[m_uiWayPointCount]);
//                        break;
//                    case EVENT_TALK_1:
//                        if (Creature* pKuai = GetAffectedBoss(TYPE_KUAI))
//                        {
//                            if (pKuai->AI())
//                                pKuai->AI()->DoAction(3);
//
//                            events.ScheduleEvent(EVENT_TALK_2, 10000);
//
//                            pKuai->CombatStop();
//                        }
//                        break;
//                    case EVENT_TALK_2:
//                        if (Creature* pMing = GetAffectedBoss(TYPE_MING))
//                        {
//                            if (pMing->AI())
//                                pMing->AI()->DoAction(1);
//
//                            events.ScheduleEvent(EVENT_TALK_3, 14000);
//
//                            pMing->CombatStop();
//                        }
//                        break;
//                    case EVENT_TALK_3:
//                        if (Creature* pHaiyan = GetAffectedBoss(TYPE_HAIYAN))
//                        {
//                            if (pHaiyan->AI())
//                                pHaiyan->AI()->DoAction(1);
//
//                            events.ScheduleEvent(EVENT_TALK_4, 13000);
//
//                            pHaiyan->CombatStop();
//                        }
//                        break;
//                    case EVENT_TALK_4:
//                        if (Creature* pKuai = GetAffectedBoss(TYPE_KUAI))
//                        {
//                            if (pKuai->AI())
//                                pKuai->AI()->DoAction(4);
//
//                            events.ScheduleEvent(EVENT_START_BATTLE, 4800);
//                        }
//                        break;
//                    case EVENT_START_BATTLE:
//                        if (auto const script = me->GetInstanceScript())
//                            script->SetData(TYPE_TRIAL_ENDED, 0);
//                        break;
//                    case EVENT_SUMMON_BAT:
//                        HandleBatSummons(5);
//                        events.ScheduleEvent(EVENT_SUMMON_BAT, urand(9000, 14000));
//                        break;
//                }
//            }
//        }
//
//    };
//};
//
//class npc_glintrok_scout_2 : public CreatureScript
//{
//public:
//    npc_glintrok_scout_2() : CreatureScript("npc_glintrok_scout_2") { }
//
//    CreatureAI* GetAI(Creature* pCreature) const
//    {
//        return new npc_glintrok_scout_2AI(pCreature);
//    }
//
//    enum eTalks
//    {
//        TALK_EMOTE
//    };
//
//    struct npc_glintrok_scout_2AI : public ScriptedAI
//    {
//        npc_glintrok_scout_2AI(Creature* pCreature) : ScriptedAI(pCreature)
//        {
//            m_bHasCalledMobs = false;
//        }
//
//        bool m_bHasCalledMobs;
//
//        void MoveInLineOfSight(Unit* pWho)
//        {
//            if (m_bHasCalledMobs)
//                return;
//
//            if (pWho && pWho->GetTypeId() == TYPEID_PLAYER && pWho->GetDistance(me) < 15.0f)
//            {
//                m_bHasCalledMobs = true;
//                DoCast(SPELL_GLINTROK_SCOUT_CALL);
//                Talk(TALK_EMOTE);
//            }
//        }
//
//        void UpdateAI(const uint32 /*uiDiff*/)
//        {
//            if (!UpdateVictim())
//                return;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class spell_xin_mogu_jump_targeting : public SpellScriptLoader
//{
//public:
//    spell_xin_mogu_jump_targeting() : SpellScriptLoader("spell_xin_mogu_jump_targeting") { }
//
//    class xin_mogu_jump_targeting_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(xin_mogu_jump_targeting_SpellScript);
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_MOGU_JUMP))
//                return false;
//            return true;
//        }
//
//        void HandlePosition()
//        {
//            if (GetCaster() && GetCaster()->GetDistance(pXinJumpPoint) < 99.f)
//                GetCaster()->GetMotionMaster()->MoveJump(-4296.391f, -2613.577f, 22.325f, 30.f, 22.f);
//
//            FinishCast(SPELL_CAST_OK);
//        }
//
//        void Register()
//        {
//            BeforeCast += SpellCastFn(xin_mogu_jump_targeting_SpellScript::HandlePosition);
//        }
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new xin_mogu_jump_targeting_SpellScript;
//    }
//};
//
//// struct SpellForTicks
//// {
////     uint32 m_uiTicks;
////     uint32 m_uiSpell;
//// };
//
//class PlayerCheck
//{
//public:
//    bool operator()(WorldObject* target) const
//    {
//        return !target->ToPlayer();
//    }
//};
//
//// static const SpellForTicks MagneticField[3] =
//// {
////     { 3, SPELL_MAGNETIC_FIELD_10 },
////     { 5, SPELL_MAGNETIC_FIELD_20 },
////     { 8, SPELL_MAGNETIC_FIELD_40 }
//// };
//
//class spell_magnetic_field : public SpellScriptLoader
//{
//public:
//    spell_magnetic_field() : SpellScriptLoader("spell_magnetic_field") { }
//
//    class spell_magnetic_field_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_magnetic_field_SpellScript)
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_FIELD_AURA))
//                return false;
//            return true;
//        }
//
//        void SelectTargets(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(PlayerCheck());
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magnetic_field_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        }
//
//    };
//
//    class spell_magnetic_field_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_magnetic_field_AuraScript);
//
//        uint32 m_uiAuraTicks;
//        uint32 m_uiAuraTimer;
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_FIELD_AURA))
//                return false;
//            return true;
//        }
//
//        bool Load()
//        {
//            m_uiAuraTicks = 0;
//            m_uiAuraTimer = 500;
//            return true;
//        }
//
//        void OnPeriodic(constAuraEffectPtr aurEff)
//        {
//            ++m_uiAuraTicks;
//        }
//
//        void AuraUpdate(const uint32 diff)
//        {
//            if (m_uiAuraTimer <= diff)
//            {
//                m_uiAuraTimer = 500;
//
//                uint32 uiUsedSpell = 0;
//
//                if (m_uiAuraTicks < 4)
//                    uiUsedSpell = SPELL_MAGNETIC_FIELD_10;
//                else if (m_uiAuraTicks < 6)
//                    uiUsedSpell = SPELL_MAGNETIC_FIELD_20;
//                else
//                    uiUsedSpell = SPELL_MAGNETIC_FIELD_40;
//
//                if (Unit* pCaster = GetCaster())
//                    pCaster->CastSpell(pCaster, uiUsedSpell, true);
//            }
//            else
//                m_uiAuraTimer -= diff;
//        }
//
//        void Register()
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_magnetic_field_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
//            OnAuraUpdate += AuraUpdateFn(spell_magnetic_field_AuraScript::AuraUpdate);
//        }
//
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_magnetic_field_AuraScript();
//    }
//};
//
//// Bosses should never be sucked in
//class TargetCheck
//{
//public:
//    bool operator()(WorldObject* target) const
//    {
//        return target && target->ToCreature() && target->ToCreature()->getFaction() == 14;
//    }
//};
//
//class spell_magnetic_pull : public SpellScriptLoader
//{
//public:
//    spell_magnetic_pull() : SpellScriptLoader("spell_magnetic_pull") { }
//
//    class spell_magnetic_pull_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_magnetic_pull_SpellScript);
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_FIELD_10) || !sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_FIELD_20) || !sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_FIELD_40))
//                return false;
//            return true;
//        }
//
//        void SelectTargets(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(TargetCheck());
//        }
//
//        void HandleDummy(SpellEffIndex /*effIndex*/)
//        {
//            if (Unit* pUnit = GetHitUnit())
//            {
//                if (Unit* pCaster = GetCaster())
//                {
//                    if (pUnit->GetDistance(pCaster) > 8.f)
//                        pUnit->CastSpell(pCaster, SPELL_MAGNETIC_PULL, true);
//                }
//            }
//        }
//
//        void Register()
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_magnetic_pull_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magnetic_pull_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_magnetic_pull_SpellScript();
//    }
//};
//
//class spell_whirling_dervish : public SpellScriptLoader
//{
//public:
//    spell_whirling_dervish() : SpellScriptLoader("spell_whirling_dervish") { }
//
//    class spell_whirling_dervish_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_whirling_dervish_AuraScript);
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_WHIRLING_DERVISH_AURA))
//                return false;
//            return true;
//        }
//
//        void HandleAuraRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* pCaster = GetCaster())
//            {
//                //safety
//                if (!pCaster->ToCreature())
//                    return;
//
//                pCaster->AddObjectToRemoveList();
//            }
//        }
//
//        void Register()
//        {
//            AfterEffectRemove += AuraEffectRemoveFn(spell_whirling_dervish_AuraScript::HandleAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_whirling_dervish_AuraScript();
//    }
//};
//
//class AuraCheck
//{
//public:
//    AuraCheck(uint32 aura) : _aura(aura) { }
//
//    bool operator()(WorldObject* target) const
//    {
//        return target->ToUnit() && target->ToUnit()->HasAura(_aura);
//    }
//private:
//    uint32 _aura;
//};
//
//class spell_whirling_dervish_knock : public SpellScriptLoader
//{
//public:
//    spell_whirling_dervish_knock() : SpellScriptLoader("spell_whirling_dervish_knock") { }
//
//    class spell_whirling_dervish_knock_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_whirling_dervish_knock_SpellScript)
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_WHIRLING_DERVISH_TARGETS))
//                return false;
//            return true;
//        }
//
//        void SelectTargets(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(AuraCheck(SPELL_WHIRLING_DERVISH_AURA));
//        }
//
//        void HandleAfterHit()
//        {
//            if (GetCaster() && GetHitUnit())
//            {
//                // no real reason to create another spellscript solely for this purpose
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_THROW, false);
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_THROW_2, false);
//            }
//        }
//
//        void Register()
//        {
//            AfterHit += SpellHitFn(spell_whirling_dervish_knock_SpellScript::HandleAfterHit);
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_whirling_dervish_knock_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_whirling_dervish_knock_SpellScript();
//    }
//
//};
//
//class spell_shockwave_kuai : public SpellScriptLoader
//{
//public:
//    spell_shockwave_kuai() : SpellScriptLoader("spell_shockwave_kuai") { }
//
//    class spell_shockwave_kuai_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_shockwave_kuai_AuraScript);
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_SHOCKWAVE))
//                return false;
//            return true;
//        }
//
//        void HandleOnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetCaster() && GetCaster()->HasUnitState(UNIT_STATE_CANNOT_TURN))
//                GetCaster()->ClearUnitState(UNIT_STATE_CANNOT_TURN);
//        }
//
//        void Register()
//        {
//            AfterEffectRemove += AuraEffectRemoveFn(spell_shockwave_kuai_AuraScript::HandleOnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_shockwave_kuai_AuraScript();
//    }
//};
//
//class spell_shockwave_targeting : public SpellScriptLoader
//{
//public:
//    spell_shockwave_targeting() : SpellScriptLoader("spell_shockwave_targeting") { }
//
//    class spell_shockwave_kuai_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_shockwave_kuai_SpellScript)
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_PICK_SHOCKWAVE_TARGET))
//                return false;
//            return true;
//        }
//
//        void SelectTarget(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(PlayerCheck());
//            targets.resize(1);
//        }
//
//        void HandleSpellcast()
//        {
//            if (GetHitUnit() && GetCaster())
//            {
//                GetCaster()->AddUnitState(UNIT_STATE_CANNOT_TURN);
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHOCKWAVE, false);
//            }
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shockwave_kuai_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//            AfterHit += SpellHitFn(spell_shockwave_kuai_SpellScript::HandleSpellcast);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_shockwave_kuai_SpellScript();
//    }
//};
//
//class spell_haiyan_conflagrate_targeting : public SpellScriptLoader
//{
//public:
//    spell_haiyan_conflagrate_targeting() : SpellScriptLoader("spell_haiyan_conflagrate_targeting") { }
//
//    class spell_haiyan_conflagrate_targeting_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_haiyan_conflagrate_targeting_SpellScript);
//
//        bool Validate(SpellInfo const* /* spell */)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_CONFLAGRATE))
//                return false;
//            return true;
//        }
//
//        void SelectTarget(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(PlayerCheck());
//            targets.resize(1);
//        }
//
//        void HandleSpellcast()
//        {
//            if (GetHitUnit() && GetCaster())
//            {
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_CONFLAGRATE_AURA, false);
//            }
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_haiyan_conflagrate_targeting_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//            AfterHit += SpellHitFn(spell_haiyan_conflagrate_targeting_SpellScript::HandleSpellcast);
//        }
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_haiyan_conflagrate_targeting_SpellScript();
//    }
//
//};
//
//class spell_haiyan_conflagrate_aura : public SpellScriptLoader
//{
//public:
//    spell_haiyan_conflagrate_aura() : SpellScriptLoader("spell_haiyan_conflagrate_aura") { }
//
//    class spell_haiyan_conflagrate_aura_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_haiyan_conflagrate_aura_SpellScript);
//
//        bool Validate(SpellInfo const* /*spell*/)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_CONFLAGRATE_SPREAD))
//                return false;
//            return true;
//        }
//
//        void SelectTargets(std::list<WorldObject*>&targets)
//        {
//            targets.remove_if(AuraCheck(SPELL_CONFLAGRATE_AURA));
//            targets.remove_if(TargetCheck());
//            // cant deal with loads of adepts/grunts dying from this spell
//            targets.remove_if(PlayerCheck());
//        }
//
//        void HandleSpellcast()
//        {
//            if (GetHitUnit() && GetCaster())
//            {
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_CONFLAGRATE_AURA, true);
//            }
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_haiyan_conflagrate_aura_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//            AfterHit += SpellHitFn(spell_haiyan_conflagrate_aura_SpellScript::HandleSpellcast);
//        }
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_haiyan_conflagrate_aura_SpellScript();
//    }
//};
//
//class spell_haiyan_meteor_targeting : public SpellScriptLoader
//{
//public:
//    spell_haiyan_meteor_targeting() : SpellScriptLoader("spell_haiyan_meteor_targeting") { }
//
//    class spell_haiyan_meteor_targeting_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_haiyan_meteor_targeting_SpellScript);
//
//        bool Validate(SpellInfo const* /* spell */)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_METEOR_TARGETING))
//                return false;
//            return true;
//        }
//
//        void SelectTarget(std::list<WorldObject*>& targets)
//        {
//            targets.remove_if(PlayerCheck());
//            targets.resize(1);
//        }
//
//        void HandleSpellcast()
//        {
//            if (GetHitUnit() && GetCaster())
//            {
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_METEOR, false);
//            }
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_haiyan_meteor_targeting_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//            AfterHit += SpellHitFn(spell_haiyan_meteor_targeting_SpellScript::HandleSpellcast);
//        }
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_haiyan_meteor_targeting_SpellScript();
//    }
//};
//
//struct NotPlayerCheck final
//{
//    bool operator ()(WorldObject const *target) const
//    {
//        return target && target->GetTypeId() != TYPEID_PLAYER;
//    }
//};
//
//class spell_haiyan_meteor final : public SpellScriptLoader
//{
//    class script_impl final : public SpellScript
//    {
//        PrepareSpellScript(script_impl)
//
//        uint32 m_targets;
//
//        bool Load() final
//        {
//            m_targets = 0;
//            return true;
//        }
//
//        void SelectTargets(std::list<WorldObject*> &targets)
//        {
//            targets.remove_if(NotPlayerCheck());
//            m_targets = targets.size();
//        }
//
//        void OnBeforeHit()
//        {
//            if (m_targets != 0)
//                SetHitDamage(float(GetHitDamage()) / m_targets);
//        }
//
//        void Register() final
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(script_impl::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//            OnHit += SpellHitFn(script_impl::OnBeforeHit);
//        }
//    };
//
//public:
//    spell_haiyan_meteor()
//        : SpellScriptLoader("spell_haiyan_meteor")
//    { }
//
//    SpellScript * GetSpellScript() const final
//    {
//        return new script_impl;
//    }
//};
//
//class CorrectUnitCheck
//{
//public:
//    CorrectUnitCheck(Unit const *pCaster)
//        : casterGuid(pCaster->GetGUID())
//    { }
//
//    bool operator ()(WorldObject const *target) const
//    {
//        return target && ((target->ToCreature() && target->ToCreature()->getFaction() != 16) || target->ToPlayer() || target->GetGUID() == casterGuid);
//    }
//
//private:
//    uint64 casterGuid;
//};
//
//class spell_saurok_help_call : public SpellScriptLoader
//{
//public:
//    spell_saurok_help_call() : SpellScriptLoader("spell_saurok_help_call") { }
//
//    class spell_saurok_help_call_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_saurok_help_call_SpellScript);
//
//        bool Validate(SpellInfo const* /* spell */)
//        {
//            if (!sSpellMgr->GetSpellInfo(SPELL_GLINTROK_SCOUT_CALL))
//                return false;
//            return true;
//        }
//
//        void SelectTarget(std::list<WorldObject*>& targets)
//        {
//            if (GetCaster())
//            {
//                targets.remove_if(CorrectUnitCheck(GetCaster()));
//                targets.sort(MoPCore::ObjectDistanceOrderPred(GetCaster()));
//                targets.resize(3);
//            }
//        }
//
//        void HandleSpellcast()
//        {
//            if (GetHitUnit())
//            {
//                float x, y;
//                GetPositionWithDistInOrientation(GetHitUnit(), 30.0f, GetHitUnit()->GetOrientation(), x, y);
//                GetHitUnit()->GetMotionMaster()->MovePoint(0, x, y, GetHitUnit()->GetMap()->GetHeight(x, y, GetHitUnit()->GetPositionZ()));
//
//                if (GetHitUnit()->ToCreature() && GetHitUnit()->ToCreature()->GetEntry() == CREATURE_GLINTROK_IRONHIDE)
//                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_IRON_PROTECTOR, false);
//
//                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_REPLACE_STAND_READY1H, true);
//            }
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_saurok_help_call_SpellScript::SelectTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
//            AfterHit += SpellHitFn(spell_saurok_help_call_SpellScript::HandleSpellcast);
//        }
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_saurok_help_call_SpellScript();
//    }
//};
//
//void AddSC_boss_trial_of_the_king()
//{
//    new mob_xian_the_weaponmaster_trigger();
//    new boss_ming_the_cunning();
//    new mob_whirling_dervish();
//    new mob_adepts();
//    new boss_kuai_the_brute();
//    new mob_mu_shiba();
//    new boss_haiyan_the_unstoppable();
//    new npc_glintrok_scout();
//    new npc_glintrok_scout_2();
//    new spell_xin_mogu_jump_targeting();
//    new spell_magnetic_field();
//    new spell_magnetic_pull();
//    new spell_whirling_dervish();
//    new spell_whirling_dervish_knock();
//    new spell_shockwave_kuai();
//    new spell_shockwave_targeting();
//    new spell_haiyan_conflagrate_targeting();
//    new spell_haiyan_conflagrate_aura();
//    new spell_haiyan_meteor_targeting();
//    new spell_haiyan_meteor();
//    new spell_saurok_help_call();
//}
