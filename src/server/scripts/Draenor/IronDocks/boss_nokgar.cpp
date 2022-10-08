#include "iron_docks.hpp"

enum eTalks
{
    /// Nok'gar
    SayAggro        = 0,    ///< Start the funeral pyres! (46057)
    SaySlay         = 1,    ///< Hahahaha my blade's thirst for war! (46061) / Revolt.. in the slaughter! (46060)
    SayDeath        = 2,    ///< You.. will burn.. with me. (46058)
    SayIntro        = 3,    ///< Warsong arrows sing from the skies, they'll be the last thing you hear as I crush your skull. (46059)
    SaySpell03      = 6,    ///< Terror overwhelms you.. Death is near! (46064)
    SaySpell04      = 7,    ///< A death worthy of a warrior. (46065)
    /// After Death
    TalkZoggosh01   = 8,    ///< Sir, they've breached the gates! Nok'gar is.. dead!! We should pick anchor and prepare to sail to Talador. Right now! (44047)
    TalkKoramar01   = 23,   ///< Calm yourself.. Zoggosh. We'll do no such thing, if these weaklings are so eager to die then we should obliged! (43899)
    TalkKoramar0222 = 24    ///< Zoggosh.. do not question my authority. This isn't just any Groon, this is Skuloc son of Grool.. the blood of a champion course through his veins.. I'm not concerned with these whelps. (43900)  
};

enum eSpells
{
    SpellRideVehicle                = 47020,
    SpellBarbedArrow                = 164370,
    SpellRecklessProvocation        = 164426,
    SpellIntimidated                = 164504,
    /// MISC
    SpellFeignDeath = 103750,
    SpellCosmeticFeignDeath = 166925
};

enum eMovementInformed
{
    MovementInformDreadfangShreddingStrikes = 1,
    MovementInformDreadfangFranticMauling
};

enum eActions
{
    ActionDismountHeroic    = 1,
    ActionBarbedArrow       = 2,
    ActionStop
};

enum eCreatures
{
    CreatureShreddingSwipes = 81832,
    CreatureWolf            = 81297
};

Position const g_ArchersPos[5] =
{
    { 6882.93f, -694.61f, 55.554f, 3.14270f },
    { 6883.21f, -705.07f, 55.922f, 3.13948f },
    { 6883.21f, -688.00f, 56.686f, 3.16305f },
    { 6884.02f, -676.18f, 56.483f, 3.34997f },
    { 6884.07f, -662.27f, 56.541f, 3.09864f }
};

class basicevent_nokgar_death : public BasicEvent
{
    public:
        explicit basicevent_nokgar_death(Unit* p_Unit, int p_Value) : m_Obj(p_Unit), m_Modifier(p_Value) { }

        bool Execute(uint64 /*p_CurrTime*/, uint32 /*p_Diff*/)
        {
            if (InstanceScript* l_Instance = m_Obj->GetInstanceScript())
            {
                if (Creature* l_Zoggosh = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eIronDocksDatas::DataZuggosh)))
                {
                    if (Creature* l_Koramar = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eIronDocksDatas::DataKoramar)))
                    {
                        if (Creature* l_Skulloc = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eIronDocksDatas::DataSkulloc)))
                        {                  
                            if (l_Zoggosh->IsAIEnabled && l_Koramar->IsAIEnabled)
                            {
                                switch (m_Modifier)
                                {
                                    case 0:
                                        l_Zoggosh->AI()->Talk(eTalks::TalkZoggosh01);
                                        l_Zoggosh->m_Events.AddEvent(new basicevent_nokgar_death(l_Zoggosh, 1), l_Zoggosh->m_Events.CalculateTime(8 * TimeConstants::IN_MILLISECONDS));
                                        break;
                                    case 1:
                                        l_Koramar->AI()->Talk(eTalks::TalkKoramar01);
                                        l_Koramar->m_Events.AddEvent(new basicevent_nokgar_death(l_Koramar, 2), l_Koramar->m_Events.CalculateTime(12 * TimeConstants::IN_MILLISECONDS));
                                        break;
                                    case 2:
                                        l_Koramar->AI()->Talk(eTalks::TalkKoramar0222);
                                        break;
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
        Unit* m_Obj;
        int m_Modifier;
};

/// Fleshrender Nok'gar - 81305
class boss_nokgar : public CreatureScript
{
public:
    boss_nokgar() : CreatureScript("boss_nokgar") { }

    struct boss_nokgarAI : public BossAI
    {
        boss_nokgarAI(Creature* p_Creature) : BossAI(p_Creature, eIronDocksDatas::DataNokgar)
        {
            m_Intro = false;
            m_Instance = me->GetInstanceScript();
        }

        enum eNokgarSpells
        {          
            SpellWarsongFlag = 168531,
            SpellBarbedArrow = 164370,
            SpellRecklessProvocation = 164426,
            SpellIntimidated = 164504
        };

        enum eNokgarEvents
        {
            EventFireArrows = 1,
            EventBarbedArrows,
            EventRecklessProvocation,
            EventDismount,
            EventLaunchArchers,
            EventStopArchers,
            EventBarbedArrowArchers
        };

        int8 m_Phase;
        bool m_Intro;
        bool m_DismountHeroic;
        bool m_Dismounted;
        InstanceScript* m_Instance;

        void Reset() override
        {
            _Reset();
            events.Reset();
            m_Phase = 0;
            m_DismountHeroic = false;
            m_Dismounted = false;
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            me->CastSpell(me, eNokgarSpells::SpellWarsongFlag, true);
        }

        void LaunchArchers()
        {
            std::list<Creature*> l_Flameslingers;
            me->GetCreatureListWithEntryInGrid(l_Flameslingers, eIronDocksCreatures::CreatureGromkarFlameslinger, 200.0f);
            if (l_Flameslingers.empty())
                return;

            for (auto l_Itr : l_Flameslingers)
            {
                if (l_Itr->IsAIEnabled)
                    l_Itr->GetAI()->DoAction(eIronDocksActions::ActionFireArrows);
            }
        }

        void StopArchers()
        {
            std::list<Creature*> l_Flameslingers;
            me->GetCreatureListWithEntryInGrid(l_Flameslingers, eIronDocksCreatures::CreatureGromkarFlameslinger, 200.0f);
            if (l_Flameslingers.empty())
                return;

            for (auto l_Itr : l_Flameslingers)
            {
                if (l_Itr->IsAIEnabled)
                l_Itr->GetAI()->Reset();
            }
        }

        void MoveInLineOfSight(Unit* p_Who) override
        {
            if (p_Who && p_Who->IsInWorld() && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER && !m_Intro && me->IsWithinDistInMap(p_Who, 10.0f))
            {
                m_Intro = true;
                Talk(eTalks::SayIntro);
                if (Creature* l_Wolf = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataMountWolf)))
                    me->CastSpell(l_Wolf, eSpells::SpellRideVehicle, true);
            }
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (p_Damage && p_Damage > 0)
            {
                if (me->HealthBelowPct(50) && !m_DismountHeroic)
                {
                    m_DismountHeroic = true;
                    events.ScheduleEvent(eNokgarEvents::EventDismount, 1 * TimeConstants::IN_MILLISECONDS);
                }

                if (me->HasAura(eNokgarSpells::SpellRecklessProvocation))
                    me->AddAura(eNokgarSpells::SpellIntimidated, p_Attacker);
            }
        }

        void EnterCombat(Unit* p_Who) override
        {
            _EnterCombat();
            StopArchers();
            events.ScheduleEvent(eNokgarEvents::EventLaunchArchers, 10 * TimeConstants::IN_MILLISECONDS);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            if (!IsHeroic())
                events.ScheduleEvent(eNokgarEvents::EventDismount, 29 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
                Talk(eTalks::SaySlay);
        }

        void JustDied(Unit* /*p_Killer*/) override
        {
            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
                if (Creature* l_Wolf = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataMountWolf)))
                    l_Wolf->DespawnOrUnsummon(2 * TimeConstants::IN_MILLISECONDS);           
            }

            _JustDied();
            StopArchers();
            Talk(eTalks::SayDeath);
            me->m_Events.AddEvent(new basicevent_nokgar_death(me, 0), me->m_Events.CalculateTime(2 * TimeConstants::IN_MILLISECONDS));
        }

        void JustReachedHome() override
        {
            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* l_Wolf = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataMountWolf)))
                {
                    l_Wolf->AI()->Reset();
                    l_Wolf->Respawn(true);
                    l_Wolf->SetHealth(l_Wolf->GetMaxHealth());
                }
            }
   
            StopArchers();
            _JustReachedHome();
            me->DespawnOrUnsummon();
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
                case eActions::ActionDismountHeroic:
                {
                    events.ScheduleEvent(eNokgarEvents::EventDismount, 1 * TimeConstants::IN_MILLISECONDS);
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

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (m_Dismounted)
            {
                if (Unit* l_Victim = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                {
                    if (!me->IsWithinMeleeRange(l_Victim))
                        me->GetMotionMaster()->MoveChase(l_Victim);
                }
            }

            switch (events.ExecuteEvent())
            {
                case eNokgarEvents::EventLaunchArchers:
                    LaunchArchers();
                    events.ScheduleEvent(eNokgarEvents::EventStopArchers, 15 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eNokgarEvents::EventStopArchers:
                {
                    std::list<Creature*> l_Flameslingers;
                    me->GetCreatureListWithEntryInGrid(l_Flameslingers, eIronDocksCreatures::CreatureGromkarFlameslinger, 200.0f);
                    if (l_Flameslingers.empty())
                        return;

                    for (auto l_Itr : l_Flameslingers)
                    {
                        if (l_Itr->IsAIEnabled)
                            l_Itr->GetAI()->DoAction(eActions::ActionStop);
                    }

                    events.ScheduleEvent(eNokgarEvents::EventLaunchArchers, 20 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eNokgarEvents::EventDismount:
                {
                    if (m_Instance != nullptr)
                    {
                        if (Creature* l_Wolf = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataMountWolf)))
                        {
                            if (l_Wolf->GetVehicleKit())
                                l_Wolf->GetVehicleKit()->RemoveAllPassengers();

                            me->RemoveAura(eSpells::SpellRideVehicle);
                        }
                    }

                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                    {
                        me->Attack(l_Target, true);
                        me->GetMotionMaster()->MoveChase(l_Target);

                        m_Dismounted = true;
                        events.SetPhase(1);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        events.ScheduleEvent(eNokgarEvents::EventRecklessProvocation, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                }
                case eNokgarEvents::EventRecklessProvocation:
                {
                    Talk(eTalks::SaySpell03);
                    //me->MonsterTextEmote("Fleshrender Nok'gar casts |cffff0000[Reckless Provocation]|cfffaeb00!", me->GetGUID());
                    me->CastSpell(me, eNokgarSpells::SpellRecklessProvocation);
                    events.CancelEvent(eNokgarEvents::EventRecklessProvocation);
                    events.ScheduleEvent(eNokgarEvents::EventRecklessProvocation, 20 * TimeConstants::IN_MILLISECONDS);
                }
                default:
                    break;
                }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_nokgarAI(p_Creature);
    }
};

/// Dreadfang <Fleshrender Nok'gar's Mount> - 81297
class iron_docks_nokgar_mob_dreadfang : public CreatureScript
{
    public:
        iron_docks_nokgar_mob_dreadfang() : CreatureScript("iron_docks_nokgar_mob_dreadfang") { }

        struct iron_docks_nokgar_mob_dreadfangAI : public ScriptedAI
        {
            iron_docks_nokgar_mob_dreadfangAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_Vehicle(p_Creature->GetVehicleKit())
            {
                m_First = false;
                m_Instance = me->GetInstanceScript();
            }

            enum eDreadfangSpells
            {
                SpellBloodlettingHowl          = 164835,
                SpellSavageMauling             = 154039,
                SpellShreddingSwipesDot        = 164734,
                SpellShreddingSwipesJump       = 164735,
                SpellShreddingSwipesDummy      = 164730,
                SpellShreddingSwipesAuraRemove = 164733      
            };

            enum eDreadfangEvents
            {
                EventBloodlettingHowl = 1,
                EventSavageMauling,
                EventShreddingSwipes,
                EventShreddingSwipes2,
                EventInstallAccessories
            };

            Vehicle* m_Vehicle;
            InstanceScript* m_Instance;
            uint32 m_ShreddingStrikeTimer;
            EventMap m_Events;
            uint32 m_ShreddingAttackDiff;
            uint32 m_BloodlettingHowlDiff;
            uint32 m_SavageMaullingDiff;
            bool m_First;
            bool m_Dismounted;
            bool m_ShreddingStrikes;
            bool m_Dead;

            void Reset() override
            {             
                events.Reset();
                m_Dead = false;
                m_Dismounted = false;
                m_ShreddingStrikes = false;      
                m_ShreddingAttackDiff = 0;
                m_BloodlettingHowlDiff = 0;
                m_SavageMaullingDiff = 0;
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                m_ShreddingStrikeTimer = 1 * TimeConstants::IN_MILLISECONDS;
                me->RemoveUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                me->RemoveDynamicFlag(UnitDynFlags::UNIT_DYNFLAG_DEAD);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN | UNIT_FLAG2_FEIGN_DEATH));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                std::list<Creature*> l_ListFlameSlingers;
                me->GetCreatureListWithEntryInGrid(l_ListFlameSlingers, eIronDocksCreatures::CreatureGromkarFlameslinger, 200.0f);
                if (!l_ListFlameSlingers.empty())
                {
                    for (Creature* l_Itr : l_ListFlameSlingers)
                    {
                        if (l_Itr->IsAIEnabled)
                            l_Itr->GetAI()->Reset();
                    }
                }
                //DespawnCreaturesInArea(eIronDocksCreatures::CreatureFleshrenderNokgar, me);
             
                if (Creature* l_Nokgar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataNokgar)))
                {
                    if (l_Nokgar->IsAIEnabled)
                        l_Nokgar->GetAI()->Reset();
                    //if (!l_Nokgar->HasAura(eSpells::SpellRideVehicle))
                        l_Nokgar->CastSpell(me, eSpells::SpellRideVehicle, true);
                }       

                events.ScheduleEvent(eDreadfangEvents::EventInstallAccessories, 3 * TimeConstants::IN_MILLISECONDS);
            }

            void JustReachedHome() override
            {

            }

            void EnterCombat(Unit* p_Who) override
            {
                if (Creature* l_Nokgar = me->FindNearestCreature(eIronDocksCreatures::CreatureFleshrenderNokgar, 100.0f, true))
                {
                    if (!l_Nokgar->HasAura(eSpells::SpellRideVehicle))
                        l_Nokgar->CastSpell(me, eSpells::SpellRideVehicle, true);
                    l_Nokgar->Attack(p_Who, true);
                }
  
                m_ShreddingAttackDiff = 50 * TimeConstants::IN_MILLISECONDS;
                m_BloodlettingHowlDiff = urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS);
                m_SavageMaullingDiff = 20 * TimeConstants::IN_MILLISECONDS;            
            }

            void KilledUnit(Unit* p_Killed) override
            {
                if (p_Killed && p_Killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::SaySlay);
            }

            void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
            {
                /*
                if (p_Damage && p_Damage > 0)
                {
                    if (!m_Dead)
                    {
                        if (me->GetHealthPct() <= 12)
                        {
                            m_Dead = true;
                            events.Reset();
                            me->RemoveAllAuras();
                            me->SetFullHealth();
                            me->AttackStop();
                            me->CastSpell(me, eSpells::SpellFeignDeath);
                            me->CastSpell(me, eSpells::SpellCosmeticFeignDeath);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH | UNIT_FLAG2_DISABLE_TURN);
                            me->SetFlag(EObjectFields::OBJECT_DYNAMIC_FLAGS, UnitDynFlags::UNIT_DYNFLAG_DEAD);
                            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                            me->GetVehicleKit()->RemoveAllPassengers();

                            if (m_Instance != nullptr)
                            {
                                if (Creature* l_Nokgar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataNokgar)))
                                {
                                    if (l_Nokgar->IsAIEnabled)
                                        l_Nokgar->AI()->Talk(eTalks::SaySpell04);
                                }
                            }
                        }
                    }
                    */
                    if (!m_Dismounted)
                    {
                        if (me->GetHealthPct() <= 50) ///< Heroic
                        {
                            if (Creature* l_Nokgar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eIronDocksDatas::DataNokgar)))
                            {
                                if (l_Nokgar->IsAIEnabled)
                                {
                                    m_Dismounted = true;
                                    l_Nokgar->AI()->DoAction(eActions::ActionDismountHeroic);
                                }
                            }
                        }
                    }
            }

            void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
            {
                if (p_Id == eMovementInformed::MovementInformDreadfangShreddingStrikes)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                    {
                        me->Attack(l_Target, true);
                    }

                    m_ShreddingStrikes = false;
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    me->RemoveAura(eDreadfangSpells::SpellShreddingSwipesAuraRemove); // Visual
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                }

                if (p_Id == eMovementInformed::MovementInformDreadfangFranticMauling)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                    {
                        me->Attack(l_Target, true);
                    }
                }
            }

            void UpdateAI(uint32 const p_Diff) override
            {
                events.Update(p_Diff);

                if (events.ExecuteEvent() == eDreadfangEvents::EventInstallAccessories)
                {
                    if (m_Vehicle->GetPassenger(0) == nullptr)
                    m_Vehicle->InstallAllAccessories(false);
                }

                if (!UpdateVictim() || m_Dead)
                    return;

                if (m_ShreddingStrikes)
                {
                    if (m_ShreddingStrikeTimer <= p_Diff)
                    {
                        std::list<Player*> l_PlayerList;
                        l_PlayerList = me->SelectNearestPlayers(2.0f);

                        if (!l_PlayerList.empty())
                        {
                            for (Player* l_Itr : l_PlayerList)
                            {
                                if (me->isInFront(l_Itr, float(M_PI)))
                                    l_Itr->AddAura(eDreadfangSpells::SpellShreddingSwipesDot, l_Itr);
                            }
                        }

                        m_ShreddingStrikeTimer = 1 * TimeConstants::IN_MILLISECONDS;
                    }
                    else
                        m_ShreddingStrikeTimer -= p_Diff;
                }
  
               // if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_ShreddingStrikes)
                  //  return;

                if (m_SavageMaullingDiff <= p_Diff)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
                    {
                        me->Attack(l_Target, true);
                        me->GetMotionMaster()->MoveChase(l_Target);

                        me->CastSpell(l_Target, eDreadfangSpells::SpellSavageMauling);
                        me->GetMotionMaster()->MoveJump(*l_Target, 8.0, 4.0f, eMovementInformed::MovementInformDreadfangFranticMauling);
                    }

                    m_SavageMaullingDiff = urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS);
                }
                else
                    m_SavageMaullingDiff -= p_Diff;


                if (m_BloodlettingHowlDiff <= p_Diff)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
                        me->CastSpell(me, eDreadfangSpells::SpellBloodlettingHowl);

                    m_BloodlettingHowlDiff = 25 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_BloodlettingHowlDiff -= p_Diff;


                if (m_ShreddingAttackDiff <= p_Diff)
                {
                    m_ShreddingStrikes = true;
                    m_ShreddingStrikeTimer = 1 * TimeConstants::IN_MILLISECONDS;
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->AddAura(eDreadfangSpells::SpellShreddingSwipesAuraRemove, me);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_FARTHEST, 0, 50.0f, true))
                        me->GetMotionMaster()->MovePoint(eMovementInformed::MovementInformDreadfangShreddingStrikes, l_Target->GetPositionX(), l_Target->GetPositionY(), l_Target->GetPositionZ());

                    m_ShreddingAttackDiff = 50 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_ShreddingAttackDiff -= p_Diff;


                /*
                switch (events.ExecuteEvent())
                {
                    case eDreadfangEvents::EventSavageMauling:
                        {
                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
                            {
                                me->Attack(l_Target, true);

                                me->CastSpell(l_Target, eDreadfangSpells::SpellSavageMauling);
                                me->GetMotionMaster()->MoveJump(*l_Target, 8.0, 4.0f, eMovementInformed::MovementInformDreadfangFranticMauling);                                                                
                            }

                            events.ScheduleEvent(eDreadfangEvents::EventSavageMauling, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
                            break;
                        }
                    case eDreadfangEvents::EventBloodlettingHowl:
                        {
                            me->CastSpell(me, eDreadfangSpells::SpellBloodlettingHowl);
                            events.ScheduleEvent(eDreadfangEvents::EventBloodlettingHowl, 25 * TimeConstants::IN_MILLISECONDS);
                            break;
                        }
                    case eDreadfangEvents::EventShreddingSwipes:
                        {
                            m_ShreddingStrikes = true;
                            m_ShreddingStrikeTimer = 1 * TimeConstants::IN_MILLISECONDS;
                            me->SetReactState(ReactStates::REACT_PASSIVE);
                            me->AddAura(eDreadfangSpells::SpellShreddingSwipesAuraRemove, me);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);    
                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_FARTHEST, 0, 50.0f, true))
                                me->GetMotionMaster()->MovePoint(eMovementInformed::MovementInformDreadfangShreddingStrikes, l_Target->GetPositionX(), l_Target->GetPositionY(), l_Target->GetPositionZ());
                            events.ScheduleEvent(eDreadfangEvents::EventShreddingSwipes, 50 * TimeConstants::IN_MILLISECONDS);            
                            break;
                        }
                        default:
                            break;
                }
                */

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new iron_docks_nokgar_mob_dreadfangAI(p_Creature);
        }
};

/// Grom'kar Flameslinger - 81279
class iron_docks_nokgar_mob_flameslinger : public CreatureScript
{
    public:
        iron_docks_nokgar_mob_flameslinger() : CreatureScript("iron_docks_nokgar_mob_flameslinger") { }

        struct iron_docks_nokgar_mob_flameslingerAI : public ScriptedAI
        {
            iron_docks_nokgar_mob_flameslingerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = me->GetInstanceScript();
            }

            enum eFlameslingerSpells
            {
                SpellWarsongFlag         = 168531,
                SpellBarbedArrow         = 164370,
                SpellRecklessProvocation = 164426,
                SpellIntimidated         = 164504,
                SpellBurningArrow        = 164234,
                SpellBarbedArrowAura     = 164370,
                SpellBarbedArrowMissile  = 166914
            };

            enum eFlameslingerEvents
            {
                EventBurningArrow = 1,
                EventBurningArrowCheck,
                EventBarbedArrows,
                EventRecklessProvocation,
                EventDismount
            };

            InstanceScript* m_Instance;

            void Reset() override
            {          
                events.Reset();                 
                me->SetHover(true);
                me->SetCanFly(true);
                me->RemoveAllAuras();
                me->SetDisableGravity(true);
                me->SetFaction(HostileFaction);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }

            void DoAction(int32 const p_Action) override
            {
                switch (p_Action)
                {
                    case eActions::ActionStop:
                        events.Reset();
                        me->CombatStop();
                        break;
                    case eIronDocksActions::ActionFireArrows:
                        me->SetInCombatWithZone();
                        events.ScheduleEvent(eFlameslingerEvents::EventBurningArrow, 5 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eIronDocksActions::ActionBurningArrowSingle:
                        if (Player* l_Target = me->SelectNearestPlayer(200.0f))
                            me->CastSpell(l_Target, eFlameslingerSpells::SpellBurningArrow, true);
                        break;
                    case eIronDocksActions::ActionBarbedArrowSingle:
                        if (Player* l_Target = me->SelectNearestPlayer(200.0f))
                            me->CastSpell(l_Target, eFlameslingerSpells::SpellBarbedArrow, true);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const p_Diff) override
            {
                events.Update(p_Diff);

                switch (events.ExecuteEvent())
                {
                case eFlameslingerEvents::EventBurningArrow:
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        me->CastSpell(l_Target, eFlameslingerSpells::SpellBurningArrow, true);

                    events.ScheduleEvent(eFlameslingerEvents::EventBurningArrow, 2 * TimeConstants::IN_MILLISECONDS);

                    if (roll_chance_i(50))
                    events.ScheduleEvent(eFlameslingerEvents::EventBarbedArrows, 5 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eFlameslingerEvents::EventBarbedArrows:
                {
                    if(Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        me->CastSpell(l_Target, eFlameslingerSpells::SpellBarbedArrowMissile, true);
                    break;
                }
                default:
                    break;
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new iron_docks_nokgar_mob_flameslingerAI(p_Creature);
        }
};

/// Intimidated - 164504
class iron_docks_nokgar_spell_intimidated : public SpellScriptLoader
{
    public:

        iron_docks_nokgar_spell_intimidated() : SpellScriptLoader("iron_docks_nokgar_spell_intimidated") { }

        class iron_docks_nokgar_spell_intimidated_SpellScript : public SpellScript
        {
            PrepareSpellScript(iron_docks_nokgar_spell_intimidated_SpellScript);

            SpellCastResult CheckTarget()
            {
                if (GetCaster()->GetEntry() == eIronDocksCreatures::CreatureFleshrenderNokgar)
                    return SpellCastResult::SPELL_FAILED_DONT_REPORT;
                else
                    return SpellCastResult::SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(iron_docks_nokgar_spell_intimidated_SpellScript::CheckTarget);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new iron_docks_nokgar_spell_intimidated_SpellScript();
        }
};

void AddSC_boss_nokgar()
{
    /// Creatures
    new boss_nokgar(); /// 81305
    new iron_docks_nokgar_mob_flameslinger(); /// 81279
    new iron_docks_nokgar_mob_dreadfang(); /// 81297
    /// Spells 
    new iron_docks_nokgar_spell_intimidated(); /// 164504
}
