#include "ScriptMgr.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "auchindoun.h"


enum eNyamiSpells
{
    SpellShadowWordPain = 154477,
    SpellSoulVesselDummy = 155327,
    SpellSoulBubbleVisual = 177549,
    SpellSoulBubbleBuff = 177550,
    SpellSoulVesselDmg = 154187,
    SpellSoulVesselAreatrigger = 153888,
    SpellTornSpritsDummy = 153994,
    SpellTornSpritsDummyTwo = 153991,
    SpellTournSpiritsJump = 153992,
    SpellArbitrerHammer = 154218,
    SpellRadiantFuryVisualStar = 157787,
    SpellRadiantFuryDummy = 154261,
    SpellRadiantFullyVisual = 154264,
    SpellRadiantDamage = 154301,
    SpellRadiantFuryJump = 154262,
    SpellCrusaderStrike = 176931,
    SpellArcaneBolt = 154235,
    SpellVoidChanneling = 160677,
    SpellStrangulateState = 78037,
    SpellSpiritVisual = 145945,
};

enum eNyamiEvents
{
    EventShadowWordPain = 1,
    EventMindSpikeNyami,
    EventSoulVessel,
    EventTornSpirit,
    EventTornSpiritNyamiEffect,
    EventTornSpiritsDummy,
    EventArbitrerHammer,
    EventRadiantFury,
    EventRadiantFurySummonTrigger,
    EventRadiantFuryStop,
    EventArcaneBolt,
    EventCrusaderStrike,
    EventArcaneBombNyami,
    EventOnDeath1,
    EventOnDeath2,
    EventOnDeath3,
};

enum eNyamiTalks
{
    NyamiSpell1 = 1,   ///< Your Oath Is Unfinished! (43647)
    NyamiSpell3 = 2,   ///< The Spirits Are Mine To Command! (43649)
    NyamiSpell2 = 3,   ///< Return To This World! (43648)
    NyamiSpell4 = 4,   ///< I Will Drown This World In Shadows!(43650)
    NyamiAggro = 5,   ///< I Will Coil Your Souls Into Darkness!(43636)
    NyamiSlay = 6,   ///< Shadows Envelop You! (43646)
    NyamiDeath = 7,   ///< Too Late...My Master...Comes...(43637) 
    Auchenaiwarden1 = 32,  ///< Champions! Nyami'S Agents - They Went This Way.
    Auchenaiwarden2 = 33,  ///< No...Oh...No...
    Auchenaiwarden3 = 34,  ///< The Barrier Protecting Auchindoun Is Asunder.
    Auchenaiwarden4 = 35,  ///< A Foul Force Has Penetrated These Sacerd Chambers.
    Auchenaiwarden5 = 36   ///< Scount Ahead While We Establish A Foothold.
};

enum eNyamiActions
{
    ActionSummonSpirits = 1,
    ActionBreakLoose,
    ActionReleaseAnimationPreSoulVessel
};

enum eNyamiCreatures
{
    CreatureSpitefulArbitrer = 76284,
    CreatureTwistedMagus = 76296,
    CreatureMaleficDefender = 76283,
    CreatureRadiantFury = 432626,
    CreatureSoulVesselHackBubbleEffect = 342652
};

enum eNyamiMovementInformed
{
    MovementInformedRadiantFury = 1,
    MovementWardenMoveOuttaGate
};

/// Nyami - 76177
struct boss_nyami : public BossAI
{
    boss_nyami(Creature* creature) : BossAI(creature, DATA_NYAMI) { Initialize(); }

    void Initialize()
    {
        m_First = false;
    }

    uint32 m_DiffVisual;
    uint32 m_DiffChannel;
    bool m_CanChain;
    bool m_First;

    void Reset() override
    {
        _Reset();
        events.Reset();
        m_CanChain = false;
        m_DiffVisual = 8 * TimeConstants::IN_MILLISECONDS;
        m_DiffChannel = 2 * TimeConstants::IN_MILLISECONDS;

        if (m_First)
        {
            m_First = false;
            if (Creature* l_Teronogor = instance->GetCreature(eAuchindounDatas::DataBossTeronogor))
                l_Teronogor->SummonCreature(eAuchindounCreatures::CreatureWardenAzzakael, g_PositionWardenSpawnPoint);
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        summons.DespawnAll();
        uint32 l_Entries[3] = { eNyamiCreatures::CreatureTwistedMagus, eNyamiCreatures::CreatureMaleficDefender, eNyamiCreatures::CreatureSpitefulArbitrer };
        for (uint32 l_Entry : l_Entries)
            DespawnCreaturesInArea(l_Entry, me);
    }

    void ScheduleTasks() override
    {
        if (instance)
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

        Talk(eNyamiTalks::NyamiAggro);
        events.ScheduleEvent(eNyamiEvents::EventMindSpikeNyami, urand(8 * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eNyamiEvents::EventShadowWordPain, urand(12 * TimeConstants::IN_MILLISECONDS, 18 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eNyamiEvents::EventSoulVessel, 20 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eNyamiEvents::EventTornSpirit, 35 * TimeConstants::IN_MILLISECONDS);
    }

    void KilledUnit(Unit* p_Who) override
    {
        if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            Talk(eNyamiTalks::NyamiSlay);
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        _JustDied();
        Talk(eNyamiTalks::NyamiDeath);

        if (instance)
        {
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);;
            if (Creature* l_Warden = instance->GetCreature(eAuchindounDatas::DataWarden))
            {
                Position pos;
                pos.Relocate(l_Warden);
                pos.m_positionZ += 34.764f;
                l_Warden->GetMotionMaster()->MoveTakeoff(2, pos);//?????
                l_Warden->RemoveAura(eAuchindounSpells::SpellPrisonAura);
            }
        }
        events.ScheduleEvent(eNyamiEvents::EventOnDeath1, 5 * TimeConstants::IN_MILLISECONDS);
    }

    void HandleNonCombatVisuals(uint32 const p_Diff)
    {
        /// Non Combat
        if (!UpdateVictim())
        {
            if (m_DiffVisual <= p_Diff)
            {
                std::list<Creature*> l_ListCorpsesTriggers;
                me->GetCreatureListWithEntryInGrid(l_ListCorpsesTriggers, eAuchindounCreatures::CreatureCorpsesNyamiFight, 40.0f);
                if (!l_ListCorpsesTriggers.empty())
                {
                    std::list<Creature*>::const_iterator l_Itr = l_ListCorpsesTriggers.begin();
                    std::advance(l_Itr, urand(0, l_ListCorpsesTriggers.size() - 1));

                    if ((*l_Itr))
                    {
                        m_CanChain = true;

                        me->RemoveAura(eNyamiSpells::SpellVoidChanneling);
                        me->CastSpell((*l_Itr), eNyamiSpells::SpellTournSpiritsJump);
                        Position const pos = { (*l_Itr)->GetPositionX(), (*l_Itr)->GetPositionY(), (*l_Itr)->GetPositionZ() };
                        me->GetMotionMaster()->MoveJump(pos, 15.0f, 5.0f);         //???

                                                                                   // G3D::Vector3 l_Source(me->m_positionX, me->m_positionY, me->m_positionZ);
                                                                                   //G3D::Vector3 l_Dest(me->m_positionX, me->m_positionY, me->m_positionZ + 5.0f);
                                                                                   // G3D::Vector3 l_Orientation(0.0f, 0.0f, 0.0f);
                                                                                   //?????
                        me->SendPlaySpellVisual(Position(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.f), 0.0f, eAuchindounSpellVisualKit::SpellVisualKitNyamiSpiralUponTornSpirit, 0, 0, 1.0f, true);
                    }
                }

                m_DiffChannel = 2 * TimeConstants::IN_MILLISECONDS;
                m_DiffVisual = 15 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_DiffVisual -= p_Diff;

            if (m_DiffChannel <= p_Diff && m_CanChain)
            {
                me->CastSpell(me, eNyamiSpells::SpellVoidChanneling);
                m_CanChain = false;
            }
            else
                m_DiffChannel -= p_Diff;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case eNyamiEvents::EventMindSpikeNyami:
            if (Unit * l_Target = me->GetVictim())
                me->CastSpell(l_Target, eAuchindounSpells::SpellMindSpike);
            events.ScheduleEvent(eNyamiEvents::EventMindSpikeNyami, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
            break;
        case eNyamiEvents::EventShadowWordPain:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 200.0f, true))
                me->CastSpell(l_Target, eNyamiSpells::SpellShadowWordPain);
            events.ScheduleEvent(eNyamiEvents::EventShadowWordPain, urand(12 * TimeConstants::IN_MILLISECONDS, 18 * TimeConstants::IN_MILLISECONDS));
            break;
        case eNyamiEvents::EventSoulVessel:
            if (instance)
            {
                me->CastSpell(me, eNyamiSpells::SpellSoulVesselDummy);
                instance->DoRemoveAurasDueToSpellOnPlayers(eNyamiSpells::SpellSoulBubbleBuff);
                //me->MonsterTextEmote("Soulbinder Nyami begins to cast|cffff0000[Soul Vessel]|cfffaeb00!", me->GetGUID(), true);
                if (Creature* l_Bubble = me->SummonCreature(eNyamiCreatures::CreatureSoulVesselHackBubbleEffect, g_PositionBubble, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN))
                    if (l_Bubble->IsAIEnabled)
                        l_Bubble->AI()->DoAction(eNyamiActions::ActionReleaseAnimationPreSoulVessel);
            }
            events.ScheduleEvent(eNyamiEvents::EventSoulVessel, 25 * TimeConstants::IN_MILLISECONDS);
            break;
        case eNyamiEvents::EventTornSpirit:
        {
            std::list<Creature*> l_ListCorpsesTriggers;
            me->GetCreatureListWithEntryInGrid(l_ListCorpsesTriggers, eAuchindounCreatures::CreatureCorpsesNyamiFight, 40.0f);
            if (!l_ListCorpsesTriggers.empty())
            {
                std::list<Creature*>::const_iterator l_Itr = l_ListCorpsesTriggers.begin();
                std::advance(l_Itr, urand(0, l_ListCorpsesTriggers.size() - 1));
                if ((*l_Itr))
                {
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 20.0f);
                    me->CastSpell((*l_Itr), eAuchindounSpells::SpellDispersionVisualNyami);
                    me->GetMotionMaster()->MovePoint(0, (*l_Itr)->GetPositionX(), (*l_Itr)->GetPositionY(), (*l_Itr)->GetPositionZ());
                }
            }
            events.ScheduleEvent(eNyamiEvents::EventTornSpiritsDummy, 3 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNyamiEvents::EventTornSpirit, 35 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eNyamiEvents::EventTornSpiritsDummy:
            me->SetSpeed(UnitMoveType::MOVE_RUN, 1.5f);
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            me->CastSpell(me, eNyamiSpells::SpellTornSpritsDummy);
            break;
        case EventOnDeath1:
        {
            if (Creature* l_Warden = me->GetSummonedCreatureByEntry(CreatureWardenAzzakael))
            {
                l_Warden->SetCanFly(false);
                l_Warden->RemoveAllAuras();
                l_Warden->SetDisableGravity(false);
                l_Warden->AddAura(eAuchindounSpells::SpellKneel, l_Warden);
                events.ScheduleEvent(eNyamiEvents::EventOnDeath2, 6 * TimeConstants::IN_MILLISECONDS);
            }            
            break;
        }
        case EventOnDeath2:
        {
            if (Creature* l_Warden = me->GetSummonedCreatureByEntry(CreatureWardenAzzakael))
            {
                l_Warden->RemoveAllAuras();
                l_Warden->AI()->Talk(eNyamiTalks::Auchenaiwarden1);
                l_Warden->RemoveAura(eAuchindounSpells::SpellKneel);
                l_Warden->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                if (GameObject* l_Door = l_Warden->FindNearestGameObject(eAuchindounObjects::GameobjectDoorBarrier2, 30.0f))
                    l_Door->Delete();

                l_Warden->GetMotionMaster()->MovePoint(60, g_PositionWardenPosition1st);
                events.ScheduleEvent(eNyamiEvents::EventOnDeath3, 10 * TimeConstants::IN_MILLISECONDS);
            }
            break;
        }
        case EventOnDeath3:
        {
            if (instance)
            {
                if (GameObject* l_Window = instance->GetGameObject(eAuchindounDatas::DataAuchindounWindow))
                {
                    l_Window->SetLootState(LootState::GO_READY);
                    l_Window->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS);
                }
                if (Creature* l_Warden = me->GetSummonedCreatureByEntry(CreatureWardenAzzakael))
                {
                    l_Warden->SetReactState(ReactStates::REACT_PASSIVE);
                    l_Warden->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                    l_Warden->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    l_Warden->AddDynamicFlag(UNIT_DYNFLAG_DEAD);
                    l_Warden->AddUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN | UnitFlags2::UNIT_FLAG2_FEIGN_DEATH));
                    l_Warden->SummonCreature(eAuchindounCreatures::CreatureFelborneAbyssal, l_Warden->GetPositionX(), l_Warden->GetPositionY(), l_Warden->GetPositionZ(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);

                    if (l_Warden->IsAIEnabled)
                        l_Warden->AI()->Talk(eNyamiTalks::Auchenaiwarden2);
                }
            }
            break;
        }
        default:
            break;
        }
    }
};

/// Warden - 76572
struct auchindoun_nyami_mob_warden_cosmetic : public ScriptedAI
{
    auchindoun_nyami_mob_warden_cosmetic(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_First = false;
    }

    bool m_First;

    void Reset()
    {
        if (!m_First)
        {
            m_First = true;
            me->AddAura(eAuchindounSpells::SpellPrisonAura, me);
        }

        me->SetCanFly(true);
        me->SetDisableGravity(true);
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->CastSpell(me, eNyamiSpells::SpellStrangulateState);
        me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_FLYING);
        me->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
    }
};

/// Bubble Creature - 342652
struct auchindoun_nyami_mob_bubble : public ScriptedAI
{
    auchindoun_nyami_mob_bubble(Creature* p_Creature) : ScriptedAI(p_Creature) {}

    enum eBubbleSpells
    {
        SpellSoulBubbleVisual = 177549,
        SpellSoulBubbleBuff = 177550
    };

    EventMap events;
    uint32 m_SpellDiff;
    bool m_Visual;

    void Reset()
    {
        events.Reset();
        m_Visual = false;
        me->SetDisplayId(InvisibleDisplay);
        m_SpellDiff = 1 * TimeConstants::IN_MILLISECONDS;
        me->CastSpell(me, eBubbleSpells::SpellSoulBubbleVisual);
        me->CastSpell(me, eBubbleSpells::SpellSoulBubbleBuff);
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (m_Visual)
        {
            if (m_SpellDiff <= p_Diff)
            {
                std::list<Player*> l_PlayerList;
                me->GetPlayerListInGrid(l_PlayerList, 20.0f);
                //me->VisitNearbyObject(12.0f, searcher);
                if (!l_PlayerList.empty())
                {
                    for (std::list<Player*>::const_iterator l_Itr = l_PlayerList.begin(); l_Itr != l_PlayerList.end(); ++l_Itr)
                    {
                        if (!(*l_Itr))
                            continue;

                        if ((*l_Itr)->IsWithinDistInMap(me, 4.0f))
                        {
                            if (!(*l_Itr)->HasAura(eBubbleSpells::SpellSoulBubbleBuff))
                                me->AddAura(eBubbleSpells::SpellSoulBubbleBuff, (*l_Itr));
                        }
                        else
                        {
                            if ((*l_Itr)->HasAura(eBubbleSpells::SpellSoulBubbleBuff))
                                (*l_Itr)->RemoveAura(eBubbleSpells::SpellSoulBubbleBuff);
                        }
                    }
                }

                //G3D::Vector3 l_Source(me->m_positionX, me->m_positionY, me->m_positionZ);
                //G3D::Vector3 l_Dest(1652.273f, 3008.761f, 36.79123f);
                //G3D::Vector3 l_Orientation(0.0f, 0.0f, 0.0f);

                me->SendPlaySpellVisual(Position(1652.273f, 3008.761f, 36.79123f, 0.f), 0.f, eAuchindounSpellVisualKit::SpellVisualKitNyamiSoulVesselCircle, 0, 0, 1.0f, true);

                m_SpellDiff = 1 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_SpellDiff -= p_Diff;
        }
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eNyamiActions::ActionReleaseAnimationPreSoulVessel:
        {
            //??????
            me->Unit::SendCancelOrphanSpellVisual(eAuchindounSpellVisualKit::SpellVisualKitNyamiSoulVesselCircle);
            me->Unit::SendCancelOrphanSpellVisual(eAuchindounSpellVisualKit::SpellVisualKitNyamiSoulVesselSpiralCircle);

            if (m_Visual)
                m_Visual = false;
            else
                m_Visual = true;
            break;
        }
        default:
            break;
        }
    }

};

/// Malefic Defender - 76283
struct auchindoun_nyami_mob_malefic_defender : public ScriptedAI
{
    auchindoun_nyami_mob_malefic_defender(Creature* p_Creature) : ScriptedAI(p_Creature) {}

    enum eMaleficDefenderSpells
    {
        SpellCrusaderStirke = 176931
    };

    enum eMaleficDefenderEvents
    {
        EventCrusaderStirke = 1
    };

    EventMap events;

    void Reset()
    {
        events.Reset();
        me->AddAura(eNyamiSpells::SpellSpiritVisual, me);
    }

    void EnterCombat(Unit* p_Attacker) override
    {
        events.ScheduleEvent(eMaleficDefenderEvents::EventCrusaderStirke, 5 * TimeConstants::IN_MILLISECONDS);
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eMaleficDefenderEvents::EventCrusaderStirke:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eMaleficDefenderSpells::SpellCrusaderStirke);
            events.ScheduleEvent(eMaleficDefenderEvents::EventCrusaderStirke, urand(7 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Spiteful Arbitrer - 76284
struct auchindoun_nyami_mob_spiteful_arbitrer : public ScriptedAI
{
    auchindoun_nyami_mob_spiteful_arbitrer(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eArbitrerSpells
    {
        SpellRadiantFuryAreatrigger = 157787
    };

    InstanceScript* m_Instance;
    uint32 m_RadiantDiff;
    bool m_Radiant;
    EventMap events;

    void Reset()
    {
        events.Reset();
        m_Radiant = false;
        me->AddAura(eNyamiSpells::SpellSpiritVisual, me);
        m_RadiantDiff = 1 * TimeConstants::IN_MILLISECONDS;
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eNyamiEvents::EventRadiantFury, 8 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eNyamiEvents::EventArbitrerHammer, 14 * TimeConstants::IN_MILLISECONDS);
    }

    void MovementInform(uint32 /*p_Type*/, uint32 p_Id)
    {
        switch (p_Id)
        {
        case eNyamiMovementInformed::MovementInformedRadiantFury:
            m_Radiant = false;
            break;
        default:
            break;
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (m_Radiant)
        {
            if (m_RadiantDiff <= p_Diff)
            {
                me->CastSpell(me, eArbitrerSpells::SpellRadiantFuryAreatrigger, true);

                m_RadiantDiff = 200;
            }
            else
                m_RadiantDiff -= p_Diff;
        }

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eNyamiEvents::EventArbitrerHammer:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eNyamiSpells::SpellArbitrerHammer);
            events.ScheduleEvent(eNyamiEvents::EventArbitrerHammer, 14 * TimeConstants::IN_MILLISECONDS);
            break;
        case eNyamiEvents::EventRadiantFury:
        {
            m_Radiant = true;
            m_RadiantDiff = 200;

            float l_X = me->GetPositionX() + 30 /** cos(me->m_orientation)*/;
            float l_Y = me->GetPositionY() + 30/* * sin(me->m_orientation)*/;
            me->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ(), 20.0f, 7.0f, 10.0f);

            events.ScheduleEvent(eNyamiEvents::EventRadiantFuryStop, 6 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eNyamiEvents::EventRadiantFuryStop:
        {
            m_Radiant = false;
            events.CancelEvent(eNyamiEvents::EventRadiantFurySummonTrigger);
            events.ScheduleEvent(eNyamiEvents::EventRadiantFury, urand(15 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};


/// Twisted Magus - 76296
struct auchindoun_nyami_mob_twisted_magus : public ScriptedAI
{
    auchindoun_nyami_mob_twisted_magus(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eTwistedMagusSpells
    {
        SpellArcaneBolt = 153235,
        SpellArcaneBombDummy = 157652,
    };

    enum eTwistedMagusEvents
    {
        EventArcaneBolt = 1,
        EventArcaneBomb
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        me->AddAura(eNyamiSpells::SpellSpiritVisual, me);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eTwistedMagusEvents::EventArcaneBolt, 4 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eTwistedMagusEvents::EventArcaneBomb, 12 * TimeConstants::IN_MILLISECONDS);
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eTwistedMagusEvents::EventArcaneBolt:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eTwistedMagusSpells::SpellArcaneBolt);
            events.ScheduleEvent(eTwistedMagusEvents::EventArcaneBolt, 15 * TimeConstants::IN_MILLISECONDS);
            break;
        case eTwistedMagusEvents::EventArcaneBomb:
            me->CastSpell(me, eTwistedMagusSpells::SpellArcaneBombDummy);
            events.ScheduleEvent(eTwistedMagusEvents::EventArcaneBomb, 25 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }
    }
};


/// Torn Spirits - 153994
class auchindoun_nyami_spell_torn_spirits : public SpellScript
{
    PrepareSpellScript(auchindoun_nyami_spell_torn_spirits);

    void HandleDummy(SpellEffIndex effIndex)
    {
        uint32 l_Entries[3] = { eNyamiCreatures::CreatureMaleficDefender, eNyamiCreatures::CreatureTwistedMagus, eNyamiCreatures::CreatureSpitefulArbitrer };

        if (Unit* l_Caster = GetCaster())
        {
            if (Creature* l_Trigger = GetCaster()->FindNearestCreature(eAuchindounCreatures::CreatureCorpsesNyamiFight, 100.0f, true))
            {
                Position l_Pos;
                l_Trigger->GetRandomNearPosition(4.0f);

                for (uint32 l_Entry : l_Entries)
                    l_Caster->SummonCreature(l_Entry, l_Pos, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            }
        }
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(auchindoun_nyami_spell_torn_spirits::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
    }
};


/// Soul Vessel - 154187
class auchindoun_nyami_spell_soul_vessel : public SpellScript
{
    PrepareSpellScript(auchindoun_nyami_spell_soul_vessel);

    void RecalculateDamage(SpellEffIndex p_EffIndex)
    {
        if (GetHitUnit() && GetHitUnit()->HasAura(eNyamiSpells::SpellSoulBubbleBuff))
            SetHitDamage(0);
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(auchindoun_nyami_spell_soul_vessel::RecalculateDamage, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};
    
// Soul Vessel - 155327
class auchindoun_nyami_spell_soul_vessel_dummy : public AuraScript
{
    PrepareAuraScript(auchindoun_nyami_spell_soul_vessel_dummy);

    void HandlePeriodic(AuraEffect const* p_AurEff)
    {
        if (Unit* l_Caster = GetCaster())
        {
            std::list<Player*> l_ListPlayers;
            l_Caster->GetPlayerListInGrid(l_ListPlayers, 200.0f);
            if (!l_ListPlayers.empty())
            {
                for (Player* l_Itr : l_ListPlayers)
                {
                    if (l_Itr && l_Itr->IsInWorld())
                        l_Itr->CastSpell(l_Itr, eNyamiSpells::SpellSoulVesselDmg);
                }
            }

            /// Cosmetic
            if (Creature* l_Bubble = l_Caster->FindNearestCreature(eNyamiCreatures::CreatureSoulVesselHackBubbleEffect, 150.0f))
            {
                //G3D::Vector3 l_Source(l_Bubble->m_positionX, l_Bubble->m_positionY, l_Bubble->m_positionZ);
                //G3D::Vector3 l_Dest(1759.477f, 2947.181f, 36.79123f);
                //G3D::Vector3 l_Orientation(0.0f, 0.0f, 3.717551f);
                //?????
                l_Caster->SendPlaySpellVisual(Position(1759.477f, 2947.181f, 36.79123f, 3.717551f), 0.f, eAuchindounSpellVisualKit::SpellVisualKitNyamiSoulVesselSpiralCircle, 0, 0, 1.0f, true);
            }
        }
    }

    void OnRemove(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
    {
        if (Unit* l_Caster = GetCaster())
        {
            /// Cosmetic
            if (Creature* l_Bubble = l_Caster->FindNearestCreature(eNyamiCreatures::CreatureSoulVesselHackBubbleEffect, 150.0f))
            {
                if (l_Bubble->IsAIEnabled)
                    l_Bubble->AI()->DoAction(eNyamiActions::ActionReleaseAnimationPreSoulVessel);
            }
        }
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_nyami_spell_soul_vessel_dummy::HandlePeriodic, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(auchindoun_nyami_spell_soul_vessel_dummy::OnRemove, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
    }
};
    

/// Radiant Star AreaTrigger - 157787

class auchindoun_nyami_at_radiant_star : public AreaTriggerEntityScript
{
public:

    auchindoun_nyami_at_radiant_star() : AreaTriggerEntityScript("auchindoun_nyami_at_radiant_star") {}

    uint32 m_Diff = 1 * TimeConstants::IN_MILLISECONDS;
    std::list<uint64> m_Targets;

    void OnCreate(AreaTrigger* p_AreaTrigger)
    {
        Position l_Position;
        //p_AreaTrigger->GetPosition(&l_Position);

        l_Position.m_positionX = p_AreaTrigger->m_positionX + 15/* * cos(p_AreaTrigger->m_orientation)*/;
        l_Position.m_positionY = p_AreaTrigger->m_positionY + 15/* * sin(p_AreaTrigger->m_orientation)*/;

        p_AreaTrigger->MovePosition(l_Position, 2.0f, p_AreaTrigger->GetOrientation());
    }

    void OnUpdate(AreaTrigger* p_AreaTrigger, Unit* SPLL, uint32 p_Time)
    {
        if (m_Diff <= p_Time)
        {
            std::list<Player*> l_ListPlayers;
            p_AreaTrigger->GetPlayerListInGrid(l_ListPlayers, 1.2f);
            //  p_AreaTrigger->VisitNearbyObject(3.0f, searcher);

            if (!l_ListPlayers.empty())
            {
                for (std::list<Player*>::const_iterator l_Itr = l_ListPlayers.begin(); l_Itr != l_ListPlayers.end(); ++l_Itr)
                {
                    if (!(*l_Itr))
                        continue;
                    //???
                    SPLL->CastSpell((*l_Itr), eNyamiSpells::SpellRadiantDamage);
                    p_AreaTrigger->Remove();
                }
            }
        }
        else
            m_Diff -= p_Time;
    }
    /*
    auchindoun_nyami_at_radiant_star* GetAI()const
    {
    return nullptr;
    }*/
};



void AddSC_boss_nyami()
{
    RegisterCreatureAI(boss_nyami);
    RegisterCreatureAI(auchindoun_nyami_mob_warden_cosmetic);
    RegisterCreatureAI(auchindoun_nyami_mob_bubble); ///delete
    RegisterCreatureAI(auchindoun_nyami_mob_malefic_defender);
    RegisterCreatureAI(auchindoun_nyami_mob_spiteful_arbitrer);
    RegisterCreatureAI(auchindoun_nyami_mob_twisted_magus);
    RegisterSpellScript(auchindoun_nyami_spell_torn_spirits);
    RegisterSpellScript(auchindoun_nyami_spell_soul_vessel);
    RegisterAuraScript(auchindoun_nyami_spell_soul_vessel_dummy);
    new auchindoun_nyami_at_radiant_star();             ///< 157787//???
}
