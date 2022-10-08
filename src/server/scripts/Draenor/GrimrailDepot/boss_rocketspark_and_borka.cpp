#include "grimrail_depot.h"
#include "GameObject.h"

enum eRocketsparkAndBorkaTalks
{
    TalkBorkaAggro = 1,     ///< I got this boss [45775]
    TalkBorkaDeath,         ///< Awwww!! sweet time.. now.. [45776]
    TalkBorkaSpell01,       ///< Don't get in my way! [45782]
    TalkBorkaSpell02,       ///< I'm unstoppable! [45783]
    TalkBorkaIntro01,       ///< Where you want this box? [45778]
    TalkBorkaIntro02,       ///< Why I gotta move all the boxes..?[45779]
    TalkBorkaKill01,        ///< Haha it's too much fun [45780]
    TalkBorkaKill02,        ///< [45781]

    TalkRocketsparkDeath,   ///< This was not the plan [43731]
    TalkRocketsparkEvent03, ///< Oh you big oof! stop breaking my things! [43732]
    TalkRocketsparkEvent04, ///< That was my entire collection of heartstone cards [43733]
    TalkRocketsparkEvent05, ///< Argh.. that was my last --- do you know how hard those are to get? [43734]
    TalkRocketsparkEvent06, ///< Hey dummy.. how would you like it if I'll break all your things![43735]
    TalkRocketsparkEvent07, ///< Time to go to plan B! [43736]
    TalkRocketsparkEvent08, ///< All systems online! Fire! [43737]
    TalkRocketsparkIntro,   ///< Overthere why do you keep asking? you're always move the boxes from here to there [43738]
    TalkRocketsparkKill01,  ///< Hah, got one! [43740]
    TalkRocketsparkKill02,  ///< Stop asking and get back to work [43741]
    TalkRocketsparkSpell01, ///< Acquiring targets! [43741]
    TalkRocketsparkSpell02, ///< Correcting for A speed volecity! [43741]
    TalkRocketsparkSpell03, ///< Adjusting for drang coefficient![43741]
};

enum eRocksparkAndBorkaActions
{
    ActionBorkaUnmanagedAggression = 1,
    ActionRocketSparkNewPlan,
    ActionBorkaActivateMadDash,
    ActionRocketSparkShootMissilesVX18,
    ActionMadDashContact
};

enum eRocksparkAndBorkaMovementInformed
{
    MovementInformedRocketsparkHigherGroundsStartx2101aMissileBarrage = 1,
    MovementInformBetterPosition,
    MovementHigherPlatform,
    MovementMadDashContact,
};

enum eRocksparkAndBorkaCreatures
{
    CreatureX21Triggers = 877894,
    CreatureTriggerLineOfSight = 432425,
    CreatureBottomTrigger = 80518
};

/*
Position const g_PositionRandomRocketSparkMovements[4] =
{
{ 1718.639f, 1572.846f, 7.7136f, 3.616752f },
{ 1687.059f, 1572.249f, 7.7136f, 0.032194f },
{ 1719.248f, 1553.528f, 7.7136f, 2.866693f },
{ 1692.416f, 1583.240f, 7.7136f, 5.500137f },
};

Position const g_PostionRocketSparkHigherPlatform[2] = /// X21-01A Missile Barrage
{
{ 1708.924f, 1647.510f, 17.315f, 1.610062f },
{ 1726.215f, 1580.797f, 14.062f, 4.130380f },
};
*/

Position const g_PositionNewRocketSparkHomePoint = { 1683.582f, 1558.110f, 7.7140f };
Position const g_PositionNewBorkaSparkHomePoint = { 1683.414f, 1546.511f, 7.714f };

#define g_FloorPositionZ 7.713f

/// 1st Starting Event
class EventRocketsparkAndBorkaConversation : public BasicEvent
{
public:

    explicit EventRocketsparkAndBorkaConversation(Unit* p_Unit, int p_Value, InstanceScript* p_Instance) : m_Obj(p_Unit), m_Modifier(p_Value), m_InstanceScript(p_Instance), BasicEvent()
    {
    }

    bool Execute(uint64 /*p_CurrTime*/, uint32 /*p_Diff*/)
    {
        if (m_Obj)
        {
            if (InstanceScript* l_Instance = m_Obj->GetInstanceScript())
            {
                if (Creature* l_RocketSpark = m_InstanceScript->instance->GetCreature(m_InstanceScript->GetGuidData(GrimrailDepotData::DataRocketspark)))
                {
                    if (Creature* l_Borka = m_InstanceScript->instance->GetCreature(m_InstanceScript->GetGuidData(GrimrailDepotData::DataBorka)))
                    {
                        if (l_RocketSpark->IsAIEnabled && l_Borka->IsAIEnabled)
                        {
                            switch (m_Modifier)
                            {
                            case 0:
                            {
                                l_Borka->AI()->Talk(eRocketsparkAndBorkaTalks::TalkBorkaIntro01);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 1, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 1:
                            {
                                l_Borka->AI()->Talk(eRocketsparkAndBorkaTalks::TalkBorkaIntro02);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 2, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 2:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent03);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 3, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 3:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent04);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 4, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 4:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent05);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 5, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 5:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent06);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 6, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 6:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent07);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 7, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 7:
                            {
                                l_RocketSpark->AI()->Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkEvent08);
                                l_RocketSpark->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(l_RocketSpark, 8, m_InstanceScript), l_RocketSpark->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));
                                break;
                            }
                            case 8:
                            {
                                l_RocketSpark->GetMotionMaster()->MovePoint(100, g_PositionNewRocketSparkHomePoint);
                                l_Borka->GetMotionMaster()->MovePoint(100, g_PositionNewBorkaSparkHomePoint);

                                l_RocketSpark->SetHomePosition(g_PositionNewRocketSparkHomePoint);
                                l_Borka->SetHomePosition(g_PositionNewBorkaSparkHomePoint);
                                break;
                            }
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

private:
    InstanceScript* m_InstanceScript;
    Unit* m_Obj;
    int m_Modifier;
    int m_Event;
};

static void StartRocketSparkAndBorka(InstanceScript* p_Instance, Creature* p_Me, ObjectGuid p_TargetGuid)
{
    if (p_Instance == nullptr)
        return;

    p_Instance->SetBossState(GrimrailDepotData::DataRocketspark, EncounterState::IN_PROGRESS);

    if (Creature* l_Borka = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataBorka)))
        l_Borka->SetInCombatWithZone();
    if (Creature* l_Rocketspark = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataRocketspark)))
        l_Rocketspark->SetInCombatWithZone();
}

static void WipingConditionRocketSparkAndBorka(InstanceScript* p_Instance, Creature* p_Me)
{
    if (p_Instance == nullptr)
        return;

    if (Creature* l_Borka = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataBorka)))
    {
        if (Creature* l_Rocketspark = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataRocketspark)))
        {
            p_Instance->SetBossState(GrimrailDepotData::DataRocketspark, EncounterState::FAIL);
            l_Borka->Respawn();
            l_Borka->GetMotionMaster()->MovePoint(0, l_Borka->GetHomePosition().GetPositionX(), l_Borka->GetHomePosition().GetPositionY(), l_Borka->GetHomePosition().GetPositionZ());
            l_Rocketspark->Respawn();
            l_Rocketspark->GetMotionMaster()->MovePoint(0, l_Rocketspark->GetHomePosition().GetPositionX(), l_Rocketspark->GetHomePosition().GetPositionY(), l_Rocketspark->GetHomePosition().GetPositionZ());
        }
    }
}

static void WiningConditionRocketsparkAndBurka(InstanceScript* p_Instance, Creature* p_Me, Unit* l_Killer)
{
    if (p_Instance == nullptr)
        return;

    if (Creature* l_Borka = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataBorka)))
    {
        if (Creature* l_Rocketspark = p_Instance->instance->GetCreature(p_Instance->GetGuidData(GrimrailDepotData::DataRocketspark)))
        {
            if (l_Borka->isDead() || l_Rocketspark->isDead())
            {
                p_Instance->SetBossState(GrimrailDepotData::DataRocketspark, EncounterState::DONE);
                l_Rocketspark->AddLootRecipient(l_Killer);
            }
        }
    }
}

/// Railmaster Rocketspark - 77803 [boss]
class boss_rocketspark : public CreatureScript
{
public:

    boss_rocketspark() : CreatureScript("boss_rocketspark") { }

    struct boss_rocketsparkAI : public BossAI
    {
        boss_rocketsparkAI(Creature* p_Creature) : BossAI(p_Creature, GrimrailDepotData::DataRocketspark)
        {
            m_First = false;
            m_Instance = me->GetInstanceScript();
        }

        enum eRocketsparkSpells
        {
            SpellAcquiringTargetsDummy = 162489,
            SpellAcquiringTargetsAura = 162507,
            SpellBetterPositionDummy = 162571,
            SpellBetterPositionJump = 162171,
            SpellLockingOn = 166561,
            SpellLockingOnAura = 166559,
            SpellMissileSmoke = 162752,
            SpellNewPlanDummy = 163927,
            SpellNewPlanAura = 161091,
            SpellNewPlanDamage = 163929,
            SpellX2101aMissileBarrage = 162407,
            SpellX2101aMissileBarrageDamage = 162422,
            SpellVx18BTargetEliminatorDummy = 162500,
            SpellVx18BTargetEliminatorTriggerMissile = 162509,
            SpellVx18BTargetEliminatorDamage = 162513,
            SpellMadDashAura = 169225,
            SpellRecovering = 163947
        };

        enum eRocketsparkEvents
        {
            EventBetterPosition = 1,
            EventNewPlan,
            EventVx18BTargetEliminator,
            EventX2101a,
            Eventx2101aCancelation,
            Eventx2101aRenew,
            EventRandomMovement
        };

        InstanceScript* m_Instance;
        bool m_NewPlan;
        bool m_x210IsActivated;
        bool m_Firstx18;
        bool m_First;
        uint8 m_MovementPosition;
        uint8 m_MovementHigherGround;
        std::list<Creature*>::const_iterator l_It;

        void Reset() override
        {
            events.Reset();
            m_NewPlan = false;
            m_x210IsActivated = false;
            m_Firstx18 = false;
            m_MovementPosition = 0;
            m_MovementHigherGround = 0;
            if (!m_First)
            {
                if (m_Instance != nullptr)
                {
                    m_First = true;
                    me->m_Events.AddEvent(new EventRocketsparkAndBorkaConversation(me, 8, m_Instance), me->m_Events.CalculateTime(4 * TimeConstants::IN_MILLISECONDS));
                }
            }
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            HandleEncounterStartDoor();
            if (m_Instance != nullptr)
                WipingConditionRocketSparkAndBorka(m_Instance, me);
        }

        void HandleEncounterStartDoor()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_EncounterStartDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataSpikedGateBoss1)))
                {
                    /// Activate
                    l_EncounterStartDoor->SetLootState(LootState::GO_READY);
                    l_EncounterStartDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void HandleEncounterFinishDoor()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_EncounterFinishDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataIronWroughtGate)))
                {
                    /// Activate
                    l_EncounterFinishDoor->SetLootState(LootState::GO_READY);
                    l_EncounterFinishDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void EnterCombat(Unit* p_Who) override
        {
            if (m_Instance != nullptr)
            {
                StartRocketSparkAndBorka(m_Instance, me, p_Who->GetGUID());
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
            }

            _EnterCombat();
            HandleEncounterStartDoor();
            events.ScheduleEvent(eRocketsparkEvents::EventRandomMovement, 3 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eRocketsparkEvents::EventX2101a, 30 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkKill01);
                else
                    Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkKill02);
            }
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
        {
            switch (p_Id)
            {
            case eRocksparkAndBorkaMovementInformed::MovementInformBetterPosition:
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                break;
            case eRocksparkAndBorkaMovementInformed::MovementHigherPlatform:
                m_x210IsActivated = true;
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->CastSpell(me, eRocketsparkSpells::SpellLockingOnAura);
                me->CastSpell(me, eRocketsparkSpells::SpellX2101aMissileBarrage);
                me->CastSpell(me, eRocketsparkSpells::SpellBetterPositionJump, true);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                break;
            default:
                break;
            }
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eRocksparkAndBorkaActions::ActionRocketSparkShootMissilesVX18:
                for (uint8 l_I = 0; l_I < 6; l_I++)
                {
                    Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkSpell01);

                    Position l_Position;
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        l_Position = l_Target->GetRandomNearPosition(20.0f);

                    me->CastSpell(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), eRocketsparkSpells::SpellVx18BTargetEliminatorTriggerMissile, true);
                }
                break;
            case eRocksparkAndBorkaActions::ActionRocketSparkNewPlan:
                if (!m_NewPlan)
                {
                    events.Reset();
                    me->RemoveAllAuras();               
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkSpell03);
                    me->RemoveAura(eRocketsparkSpells::SpellX2101aMissileBarrage);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));

                    m_NewPlan = true;
                    Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkSpell03);
                    me->CastSpell(me, eRocketsparkSpells::SpellNewPlanAura);

                    if (Creature* l_Nearest = me->FindNearestCreature(eRocksparkAndBorkaCreatures::CreatureBottomTrigger, 10.0f))
                        me->GetMotionMaster()->MoveJump(*l_Nearest, 10.0f, 10.0f);

                    events.ScheduleEvent(eRocketsparkEvents::EventNewPlan, 5 * TimeConstants::IN_MILLISECONDS);

                }
                break;
            case eRocksparkAndBorkaActions::ActionMadDashContact:
                events.Reset();
                me->RemoveAllAuras();
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->CastSpell(me, eRocketsparkSpells::SpellRecovering);
                me->RemoveAura(eRocketsparkSpells::SpellX2101aMissileBarrage);

                m_x210IsActivated = false;

                if (Creature* l_Nearest = me->FindNearestCreature(eRocksparkAndBorkaCreatures::CreatureBottomTrigger, 10.0f))
                    me->GetMotionMaster()->MoveJump(*l_Nearest, 10.0f, 10.0f);

                events.ScheduleEvent(eRocketsparkEvents::EventX2101a, 30 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eRocketsparkEvents::EventRandomMovement, 5 * TimeConstants::IN_MILLISECONDS);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* p_Killer) override
        {
            _JustDied();
            HandleEncounterFinishDoor();
            Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkDeath);

            if (m_Instance != nullptr)
            {
                m_Instance->DoSendScenarioEvent(40132);
                WiningConditionRocketsparkAndBurka(m_Instance, me, p_Killer);
                if (Creature* l_Borka = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataBorka)))
                {
                    if (l_Borka->IsAlive())
                    {
                        if (l_Borka->IsAIEnabled)
                            l_Borka->GetAI()->DoAction(eRocksparkAndBorkaActions::ActionBorkaUnmanagedAggression);
                    }
                }
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            ///< In order to stop the x210 session, players must bring borka with mad dash towards x210 location.
            if (m_x210IsActivated)
            {
                if (events.ExecuteEvent() == eRocketsparkEvents::Eventx2101aRenew)
                {
                    me->CastSpell(me, eRocketsparkSpells::SpellX2101aMissileBarrage);
                    events.ScheduleEvent(eRocketsparkEvents::Eventx2101aRenew, 10 * TimeConstants::IN_MILLISECONDS);
                }
            }

            ///< While x210 is activated all other abilities are disabled. (auto attack included).
            if (m_x210IsActivated)
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eRocketsparkEvents::EventX2101a:
            {
                Talk(eRocketsparkAndBorkaTalks::TalkRocketsparkSpell02);

                events.Reset();
                std::list<Creature*> l_ListCreatureStar;
                me->GetCreatureListWithEntryInGrid(l_ListCreatureStar, GrimrailDepotCreatures::CreatureJumpToLocation, 100.0f);
                if (!l_ListCreatureStar.empty())
                {
                    l_It = l_ListCreatureStar.begin();
                    std::advance(l_It, urand(0, l_ListCreatureStar.size() - 1));

                    me->CastSpell((*l_It), eRocketsparkSpells::SpellBetterPositionJump, true);
                    me->GetMotionMaster()->MoveJump(*(*l_It), 20.0f, 20.0f, eRocksparkAndBorkaMovementInformed::MovementHigherPlatform);
                }
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                events.ScheduleEvent(eRocketsparkEvents::EventX2101a, 40 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eRocketsparkEvents::Eventx2101aRenew, 10 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eRocketsparkEvents::Eventx2101aCancelation, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case eRocketsparkEvents::Eventx2101aCancelation:
                events.Reset();
                me->RemoveAllAuras();
                m_x210IsActivated = false;
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                break;
            case eRocketsparkEvents::EventVx18BTargetEliminator:
                me->CastSpell(me, eRocketsparkSpells::SpellVx18BTargetEliminatorDummy);
                break;
            case eRocketsparkEvents::EventRandomMovement:
            {
                if (m_NewPlan)
                {
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    std::list<Creature*> l_ListCreatureStar;
                    me->GetCreatureListWithEntryInGrid(l_ListCreatureStar, GrimrailDepotCreatures::CreatureBetterPosition, 100.0f);
                    if (!l_ListCreatureStar.empty())
                    {
                        if (Creature* l_Nearest = me->FindNearestCreature(GrimrailDepotCreatures::CreatureBetterPosition, 2.0f))
                        {
                            if (std::find(std::begin(l_ListCreatureStar), std::end(l_ListCreatureStar), l_Nearest) != std::end(l_ListCreatureStar))
                                l_ListCreatureStar.remove(l_Nearest);
                        }

                        l_It = l_ListCreatureStar.begin();
                        std::advance(l_It, urand(0, l_ListCreatureStar.size() - 1));

                        me->CastSpell((*l_It), eRocketsparkSpells::SpellBetterPositionJump, true);
                        me->GetMotionMaster()->MoveJump(*(*l_It), 20.0f, 20.0f, eRocksparkAndBorkaMovementInformed::MovementInformBetterPosition);
                    }
                }
                else if (!m_Firstx18)
                {
                    m_Firstx18 = true;
                    DoAction(eRocksparkAndBorkaActions::ActionRocketSparkShootMissilesVX18);
                }
                else
                {
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    std::list<Creature*> l_ListCreatureStar;
                    me->GetCreatureListWithEntryInGrid(l_ListCreatureStar, GrimrailDepotCreatures::CreatureBetterPosition, 100.0f);
                    if (!l_ListCreatureStar.empty())
                    {
                        if (Creature* l_Nearest = me->FindNearestCreature(GrimrailDepotCreatures::CreatureBetterPosition, 2.0f))
                        {
                            if (std::find(std::begin(l_ListCreatureStar), std::end(l_ListCreatureStar), l_Nearest) != std::end(l_ListCreatureStar))
                                l_ListCreatureStar.remove(l_Nearest);
                        }

                        l_It = l_ListCreatureStar.begin();
                        std::advance(l_It, urand(0, l_ListCreatureStar.size() - 1));

                        me->CastSpell((*l_It), eRocketsparkSpells::SpellBetterPositionJump, true);
                        me->GetMotionMaster()->MoveJump(*(*l_It), 20.0f, 20.0f, eRocksparkAndBorkaMovementInformed::MovementInformBetterPosition);
                    }
                }

                events.ScheduleEvent(eRocketsparkEvents::EventRandomMovement, 12 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eRocketsparkEvents::EventVx18BTargetEliminator, 2 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_rocketsparkAI(p_Creature);
    }
};

/// Borka The Brute - 86226 
class grimrail_depot_rocketspark_mob_borka : public CreatureScript
{
public:

    grimrail_depot_rocketspark_mob_borka() : CreatureScript("grimrail_depot_rocketspark_mob_borka") { }

    struct grimrail_depot_rocketspark_mob_borkaAI : public BossAI
    {
        grimrail_depot_rocketspark_mob_borkaAI(Creature* p_Creature) : BossAI(p_Creature, GrimrailDepotData::DataBorka)
        {
            m_Instance = me->GetInstanceScript();
        }

        enum eBorkaSpells
        {
            SpellMadDashDummy = 161088,
            SpellMadDashDamage = 161089,
            SpellMadDashHit = 162160,
            SpellMadDashCharge = 161102,
            SpellMadDashAura = 169225,
            SpellSlam = 161087,
            SpellUnmanagedAggression = 161092
        };

        enum eBorkaEvents
        {
            EventMadDash = 1,
            EventMadDashActionDelayed,
            EventSlam,
            EventUnmanagedAggression,
            EventRemoveDisableTurn
        };

        InstanceScript* m_Instance;
        ObjectGuid m_MadDashTargetGUID;
        uint32 m_MadDashTargetFinderDiff;
        bool m_Hit;

        void Reset() override
        {
            events.Reset();
            m_Hit = false;
            m_MadDashTargetGUID = ObjectGuid::Empty;
            m_MadDashTargetFinderDiff = 1 * TimeConstants::IN_MILLISECONDS;
        }

        void JustReachedHome() override
        {
            if (m_Instance != nullptr)
                WipingConditionRocketSparkAndBorka(m_Instance, me);
        }

        void EnterCombat(Unit* p_Who) override
        {
            if (m_Instance != nullptr)
                StartRocketSparkAndBorka(m_Instance, me, p_Who->GetGUID());

            Talk(eRocketsparkAndBorkaTalks::TalkBorkaAggro);
            events.ScheduleEvent(eBorkaEvents::EventSlam, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBorkaEvents::EventMadDash, 20 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                switch (urand(0, 1))
                {
                case 0:
                    Talk(eRocketsparkAndBorkaTalks::TalkBorkaKill01);
                    break;
                case 1:
                    Talk(eRocketsparkAndBorkaTalks::TalkBorkaKill02);
                    break;
                default:
                    break;
                }
            }
        }

        void JustDied(Unit* p_Killer) override
        {
            /// New Plan! - Incase Borka dies first.
            if (m_Instance != nullptr)
            {
                if (Creature* l_RocketSpark = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataRocketspark)))
                {
                    if (l_RocketSpark->IsAIEnabled)
                        l_RocketSpark->GetAI()->DoAction(eRocksparkAndBorkaActions::ActionRocketSparkNewPlan);
                }
            }

            if (m_Instance != nullptr)
                WiningConditionRocketsparkAndBurka(m_Instance, me, p_Killer);
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eRocksparkAndBorkaActions::ActionBorkaUnmanagedAggression:
                me->CastSpell(me, eBorkaSpells::SpellUnmanagedAggression);
                break;
            default:
                break;
            }
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
        {
            switch (p_Id)
            {
            case eRocksparkAndBorkaMovementInformed::MovementMadDashContact:
            {
                float l_X = me->GetPositionX() + 50 * cos(me->GetOrientation());
                float l_Y = me->GetPositionY() + 50 * sin(me->GetOrientation());

                me->GetMotionMaster()->MoveCharge(l_X, l_Y, me->GetPositionZ());
                break;
            }
            default:
                break;
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            /// Mad Rush
            if (m_Instance != nullptr)
            {
                /// Responsible for stopping Borka and rescheduling mad dash
                if (m_MadDashTargetGUID!= ObjectGuid::Empty)
                {
                    if (m_Hit)
                    {
                        /// Responsible for running players over.
                        if (m_MadDashTargetFinderDiff <= p_Diff)
                        {
                            std::list<Player*> l_ListPlayer;
                            me->GetPlayerListInGrid(l_ListPlayer, 1.5f);
                            if (!l_ListPlayer.empty())
                            {
                                for (Player* l_Itr : l_ListPlayer)
                                {
                                    if (!l_Itr)
                                        continue;

                                    l_Itr->CastSpell(l_Itr, eBorkaSpells::SpellMadDashDamage);
                                }
                            }

                            m_MadDashTargetFinderDiff = 1 * TimeConstants::IN_MILLISECONDS;
                        }
                        else
                            m_MadDashTargetFinderDiff -= p_Diff;

                        if (Creature* l_RocketSpark = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataRocketspark)))
                        {
                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_MadDashTargetGUID))
                            {
                                if (me->IsWithinDistInMap(l_Target, 2.0f))
                                {
                                    m_Hit = false;
                                    m_MadDashTargetGUID = ObjectGuid::Empty;
                                    me->StopMoving();
                                    me->CastSpell(me, eBorkaSpells::SpellMadDashHit);
                                    if (Unit* l_Victim = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                                        me->Attack(l_Victim, true);

                                    events.Reset();
                                    events.ScheduleEvent(eBorkaEvents::EventSlam, 8 * TimeConstants::IN_MILLISECONDS);
                                    events.ScheduleEvent(eBorkaEvents::EventMadDash, 20 * TimeConstants::IN_MILLISECONDS);

                                    if (l_Target->IsWithinDistInMap(l_RocketSpark, 10.0f)) /// If it's Rocketspark line of sight.
                                    {
                                        if (l_RocketSpark->IsAIEnabled)
                                            l_RocketSpark->GetAI()->DoAction(eRocksparkAndBorkaActions::ActionMadDashContact);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eBorkaEvents::EventRemoveDisableTurn:
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                break;
            case eBorkaEvents::EventMadDash: /// 01
            {
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->AttackStop();
                    me->SendClearTarget();
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                    /// Responsible for choosing a target which is between player and boss
                    std::list<Creature*> l_ListCreatures;
                    me->GetCreatureListWithEntryInGrid(l_ListCreatures, eRocksparkAndBorkaCreatures::CreatureTriggerLineOfSight, 200.0f);
                    if (!l_ListCreatures.empty())
                    {
                        for (Creature* l_Itr : l_ListCreatures)
                        {
                            if (m_MadDashTargetGUID != ObjectGuid::Empty)
                                continue;

                            if (!l_Itr)
                                continue;

                            if (!l_Target->IsInBetween(l_Itr, me))
                                continue;

                            m_MadDashTargetGUID = l_Itr->GetGUID();
                        }
                    }

                    if (m_MadDashTargetGUID != ObjectGuid::Empty)
                    {
                        if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, m_MadDashTargetGUID))
                            me->CastSpell(l_Creature, eBorkaSpells::SpellMadDashAura);
                    }
                }

                events.ScheduleEvent(eBorkaEvents::EventMadDashActionDelayed, 3 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eBorkaEvents::EventMadDash, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case eBorkaEvents::EventMadDashActionDelayed:
            {
                if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, m_MadDashTargetGUID))
                    me->GetMotionMaster()->MoveCharge(l_Creature, eBorkaSpells::SpellMadDashCharge, eRocksparkAndBorkaMovementInformed::MovementMadDashContact);

                m_Hit = true;
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                events.ScheduleEvent(eBorkaEvents::EventRemoveDisableTurn, 4 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case eBorkaEvents::EventSlam:
                me->CastSpell(me, eBorkaSpells::SpellSlam);
                events.ScheduleEvent(eBorkaEvents::EventSlam, 8 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_rocketspark_mob_borkaAI(p_Creature);
    }
};

/// VX18-B Target Eliminator - 162500 
class grimrail_depot_rocketspark_spell_vx18_target_eliminator : public SpellScriptLoader
{
public:

    grimrail_depot_rocketspark_spell_vx18_target_eliminator() : SpellScriptLoader("grimrail_depot_rocketspark_spell_vx18_target_eliminator") { }

    class grimrail_depot_rocketspark_spell_vx18_target_eliminator_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_rocketspark_spell_vx18_target_eliminator_SpellScript);

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (GetCaster())
            {
                if (GetCaster()->IsAIEnabled)
                    GetCaster()->GetAI()->DoAction(eRocksparkAndBorkaActions::ActionRocketSparkShootMissilesVX18);
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(grimrail_depot_rocketspark_spell_vx18_target_eliminator_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_rocketspark_spell_vx18_target_eliminator_SpellScript();
    }
};

/// X21-01A Missile Barrage - 162407 
class grimrail_depot_rocketspark_spell_x21_01a_missile_barrage : public SpellScriptLoader
{
public:

    grimrail_depot_rocketspark_spell_x21_01a_missile_barrage() : SpellScriptLoader("grimrail_depot_rocketspark_spell_x21_01a_missile_barrage") { }

    class grimrail_depot_rocketspark_spell_x21_01a_missile_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_rocketspark_spell_x21_01a_missile_barrage_AuraScript);

        enum eSpells
        {
            SpellX2101AMissileBarrage = 162422,
        };

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            PreventDefaultAction();

            if (GetCaster())
            {
                std::list<Player*> l_ListPlayers;
                GetCaster()->GetPlayerListInGrid(l_ListPlayers, 100.0f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        if (!l_Itr)
                            continue;

                        GetCaster()->CastSpell(l_Itr, eSpells::SpellX2101AMissileBarrage, true);

                        /// Cosmetic
                        Position l_Position;
                        l_Position = l_Itr->GetRandomNearPosition(10.0f);

                        if (Creature* l_Trigger = GetCaster()->SummonCreature(eRocksparkAndBorkaCreatures::CreatureX21Triggers, l_Position, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 3 * TimeConstants::IN_MILLISECONDS))
                            GetCaster()->CastSpell(l_Trigger, eSpells::SpellX2101AMissileBarrage, true);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(grimrail_depot_rocketspark_spell_x21_01a_missile_barrage_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_rocketspark_spell_x21_01a_missile_barrage_AuraScript();
    }
};

/// New Plan - 161091  
class grimrail_depot_rocketspark_spell_new_plan : public SpellScriptLoader
{
    public:

    grimrail_depot_rocketspark_spell_new_plan() : SpellScriptLoader("grimrail_depot_rocketspark_spell_new_plan") { }

    class grimrail_depot_rocketspark_spell_new_plan_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_rocketspark_spell_new_plan_AuraScript);

        enum eSpells
        {
            SpellNewPlanMissile = 163929,
            SpellNewPlanMissile01 = 163930
        };

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            PreventDefaultAction();

            if (GetCaster())
            {
                std::list<Player*> l_ListPlayers;
                GetCaster()->GetPlayerListInGrid(l_ListPlayers, 100.0f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        if (!l_Itr)
                            continue;

                        GetCaster()->CastSpell(l_Itr, eSpells::SpellNewPlanMissile, true);

                        /// Cosmetic
                        Position l_Position;
                        l_Position = l_Itr->GetRandomNearPosition(10.0f);

                        if (Creature* l_Trigger = GetCaster()->SummonCreature(eRocksparkAndBorkaCreatures::CreatureX21Triggers, l_Position, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 3 * TimeConstants::IN_MILLISECONDS))
                            GetCaster()->CastSpell(l_Trigger, eSpells::SpellNewPlanMissile, true);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(grimrail_depot_rocketspark_spell_new_plan_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_rocketspark_spell_new_plan_AuraScript();
    }
};

void AddSC_boss_rocketspark_and_borka()
{
    new boss_rocketspark();                                            ///< 77803
    new grimrail_depot_rocketspark_mob_borka();                        ///< 86226
    new grimrail_depot_rocketspark_spell_x21_01a_missile_barrage();    ///< 162407
    new grimrail_depot_rocketspark_spell_vx18_target_eliminator();     ///< 162500
    new grimrail_depot_rocketspark_spell_new_plan();                   ///< 161091
};
