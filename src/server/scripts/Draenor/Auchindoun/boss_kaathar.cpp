#include "ScriptMgr.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "Log.h"
#include "auchindoun.h"


enum eKaatharSpells
{
    SpellHallowedGround = 154526,
    SpellHallowedGroundsTriggerMissile = 155646,
    SpellConsecratedLight = 153006,
    SpellConsecratedLightDamage = 156746,
    SpellHolyShieldThrow = 153002,
    SpellHolyShieldLos = 153028,
    SpellHolyShieldLosSpells = 153452,
    SpellHolyShieldAreatrigger = 153478,
    SpellHolyShieldOffHandDisarm = 174205,
    SpellHolyShieldTwoHandDisarm = 174206,
    SpellHolyShieldKnockBack = 153481,
    SpellHolyShieldDamageFromKnockBack = 153480,
    SpellHolyShieldAreaTrigger = 153478,
    SpellSanctifiedStrikeDummy = 152954,
    SpellSanctifiedGroundTickDamage = 161457,
    SpellSanctifiedGroundAura = 153430,
    SpellSanctifiedGroundDamageTick = 161457,
    SpellSanctifiedStrikeAreaTrigger = 165064,
    SpellSanctifiedStrikeAreaTrigger2 = 163559,
    SpellSancitfiedStrikeAreaTrigger3 = 165055,
    SpellSanctifiedStrikeAreaTrigger4 = 165065,
    SpellFate = 157465
};

enum eKaatharEvents
{
    EventHallowedGround = 1,
    EventHolyShield,
    EventConsecratedLight,
    EventSanctifiedStrike,
    EventHolyShieldReturn,
    EventFate,
    EventCheckPlayer,
    EventDecreaseSize
};

enum eKaatharActions
{
    ActionActivateBoss = 1,
    ActionFateHallowedGround,
    ActionDespawnCreatures
};

enum eKaatharTalks
{
    VigilantKaatherIntro = 0,   ///< None Live p_Who Assault The Holy Auchenai. (46436)
    VigilantKaatherAgro = 1,   ///< I Will Strike You Down. (46434)
    VigilantKaatherSpell1 = 20,   ///< Bathe In The Glory Of The Light! (46438)
    VigilantKaatherSpell2 = 21,   ///< The Light Guide My Hand! (46439)
    VigilantKaatherKill = 22,   ///< Light Guide You. (46434)
    VigilantKaatherDeath = 3    ///< Auchindoun...Is...Doomed...(46435)
};

enum eKaatharCreatures
{
    TriggerHallowedGround = 537324,
    TriggerHolyShield = 76071,
    TriggerFissureSummoner = 543536
};

Position const g_KaatharNewHomePosition = { 1911.47f, 3152.13f, 30.972f, 1.166194f };

enum Events
{
    // PostKaathar
    EVENT_POST_KAATHAR_1 = 2000,
    EVENT_POST_KAATHAR_2,
    EVENT_POST_KAATHAR_3,
    EVENT_NYAMI_ESCAPE_1,
    EVENT_NYAMI_ESCAPE_2,
    EVENT_NYAMI_ESCAPE_3,
    EVENT_NYAMI_ESCAPE_4,
    EVENT_NYAMI_ESCAPE_5,
    EVENT_NYAMI_ESCAPE_6,
    EVENT_NYAMI_ESCAPE_7,
    EVENT_NYAMI_ESCAPE_8,
    EVENT_NYAMI_ESCAPE_9,
    EVENT_KAATHAR_DESPAWN_CREATURES,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

/// Nyami Mob - 77810
struct auchindoun_kaathar_mob_nyami : public ScriptedAI
{
    auchindoun_kaathar_mob_nyami(Creature* p_Creature) : ScriptedAI(p_Creature){ }

    void Reset()
    {
        me->SetFaction(FriendlyFaction);
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->CastSpell(me, eAuchindounSpells::SpellLevitateNyami);
        me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));
    }
};
    
/// Vigilant Kaathar - 75839
struct boss_kaathar : public BossAI
{
    boss_kaathar(Creature* creature) : BossAI(creature, DATA_KAATHAR) { Initialize(); }

    void Initialize()
    {
        m_False = true;
    }

    uint32 m_Counting;
    bool m_IntroDone;
    bool m_Intro;
    bool m_False;

    void Reset() override
    {
        _Reset();
        events.Reset();
        // ClearDelayedOperations();
        me->SetCurrentEquipmentId(1); // Equipment Id  
        me->RemoveAllAreaTriggers();

        std::list<AreaTrigger*> l_listAreaTriggers;
        // me->GetAreatriggerListInRange(l_listAreaTriggers, 300.0f);
        if (!l_listAreaTriggers.empty())
        {
            for (AreaTrigger* l_Itr : l_listAreaTriggers)
            {
                if (!l_Itr)
                    continue;

                if (l_Itr->GetSpellId() != eKaatharSpells::SpellHolyShieldAreatrigger)
                    continue;

                l_Itr->Remove(/*1 * TimeConstants::IN_MILLISECONDS*/);
            }
        }

        ActivateDoors();

        if (m_False)
        {
            m_Counting = 0;
            m_Intro = false;
            m_False = false;
            m_IntroDone = false;
            me->SetFaction(FriendlyFaction);
            me->CastSpell(me, eAuchindounSpells::SpellGuard);
            me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
        }

        if (instance)
            instance->DoRemoveAurasDueToSpellOnPlayers(eKaatharSpells::SpellSanctifiedGroundAura);
    }

    void ActivateDoors()
    {
        if (instance)
        {
            if (GameObject* l_HolyBarrier = instance->GetGameObject(eAuchindounDatas::DataHolyBarrier))
            {
                l_HolyBarrier->SetLootState(LootState::GO_READY);
                l_HolyBarrier->UseDoorOrButton();
            }
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        summons.DespawnAll();
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        _JustDied();
        
        /// From here Teronogor spawns
        //??????
        if (instance)
        {
            instance->DoPlayScenePackageIdOnPlayers(SpellAuchindounSceneTeronogorSpawn);
            instance->DoRemoveAurasDueToSpellOnPlayers(eKaatharSpells::SpellSanctifiedGroundAura);
        }
        
        DespawnAllAucheniDraeneis();

        /// Remove the auchenai shield npc
        if (Creature* l_Nearest = me->FindNearestCreature(eAuchindounCreatures::CreatureAuchenaiShield, 300.0f))
            l_Nearest->DespawnOrUnsummon();

        Talk(eKaatharTalks::VigilantKaatherDeath);
        events.ScheduleEvent(Events::EVENT_POST_KAATHAR_1, 2 * TimeConstants::IN_MILLISECONDS);

        me->SummonCreature(NPC_NYAMI, Position(1649.33f, 2964.08f, 35.3197f, 2.65524f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eAuchindounActions::ActionCountPre1StBossKill:
        {
            m_Counting = m_Counting + 1;
            if (m_Counting >= 12)
            {
                me->RemoveAura(eAuchindounSpells::SpellGuard);
                m_IntroDone = true;
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_1, 5 * TimeConstants::IN_MILLISECONDS);
            }
            break;
        case eKaatharActions::ActionDespawnCreatures:
            DespawnAllAucheniDraeneis();
            break;
        }
        default:
            break;
        }
    }

    /// Responsible for the phase change after Kaathar fight - despawning
    void DespawnAllAucheniDraeneis()
    {
        if (instance)
        {
            if (Creature* l_AssinatingGuard = instance->GetCreature(eAuchindounDatas::DataAssinatingGuard))
                if (Creature* l_AssinatedGuard = instance->GetCreature(eAuchindounDatas::DataAssinatedGuard))
                {
                    l_AssinatingGuard->GetMotionMaster()->MovePoint(0, *l_AssinatedGuard);
                    l_AssinatingGuard->Attack(l_AssinatedGuard, true);
                    l_AssinatedGuard->Kill(l_AssinatedGuard);
                }
        }

        uint32 l_Entries[13] = { 77693, 76595, eAuchindounCreatures::CreatureAuchenaiDefenderUnique, eAuchindounCreatures::CreatureAucheniMagus2, eAuchindounCreatures::CreatureAucheniHoplite,
            eAuchindounCreatures::CreatureAucheniZealot, eAuchindounCreatures::CreatureAucheniWarden, eAuchindounCreatures::CreatureAucheniRitualist, eAuchindounCreatures::CreatureAucheniMagus,
            eAuchindounCreatures::CreatureAucheniSoulPriest, eAuchindounCreatures::CreatureAucheniArbiter, eAuchindounCreatures::CreatureAucheniCleric, eAuchindounCreatures::CreatureAucheniDefender };

        for (uint8 l_I = 0; l_I < 13; l_I++)
            DespawnCreaturesInArea(l_Entries[l_I], me);
    }

    void ScheduleTasks() override
    {
        ActivateDoors();

        ///< Heroics
        if (me->GetMap() && me->GetMap()->IsHeroic())
            events.ScheduleEvent(eKaatharEvents::EventFate, 25 * TimeConstants::IN_MILLISECONDS);

        events.ScheduleEvent(eKaatharEvents::EventHallowedGround, urand(12 * TimeConstants::IN_MILLISECONDS, 17 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eKaatharEvents::EventSanctifiedStrike, 8 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eKaatharEvents::EventHolyShield, 30 * TimeConstants::IN_MILLISECONDS);

        if (instance)
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
        Talk(eKaatharTalks::VigilantKaatherAgro);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case Events::EVENT_POST_KAATHAR_1:
        {
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
            {
                l_Tuulani->AI()->Talk(eAuchindounTalks::TUULANITALK14);
                l_Tuulani->RemoveAura(eAuchindounSpells::SpellTuulaniCapturedVoidPrison);
            }            

            for (int8 l_I = 0; l_I < 4; l_I++)
            {
                if (Creature* l_Defender = me->SummonCreature(eAuchindounCreatures::CreatureAucheniDefender, g_PositionFourMagesThatSpawnAfterKaatharIsKaaput[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                {
                    //l_Defender->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 505);
                    l_Defender->GetMotionMaster()->MovePoint(0, g_PositionFourMagesThatSpawnAfterKaatharIsKaaput[l_I]);
                }
            }

            //if (Creature* l_Nyami = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eAuchindounDatas::DataBossNyami)))
            //	l_Nyami->SetPhaseMask(1, true);

            if (Creature* l_Magus = me->SummonCreature(eAuchindounCreatures::CreatureAucheniMagus, g_PositionMageSpawning, TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
            {
                l_Magus->GetMotionMaster()->MovePoint(0, g_PositionMageMoveTo);
            }
            events.ScheduleEvent(Events::EVENT_POST_KAATHAR_2, 7 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_POST_KAATHAR_3, 55 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case Events::EVENT_POST_KAATHAR_2:
        {
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
            {
                l_Tuulani->AI()->Talk(eAuchindounTalks::TUULANITALK15);

                /// Holy Wall, Object In MIddle
                l_Tuulani->SummonGameObject(eAuchindounObjects::GameobjectHolyWall, g_PositionWallInMiddleFromNyami.GetPositionX(), g_PositionWallInMiddleFromNyami.GetPositionY(), g_PositionWallInMiddleFromNyami.GetPositionZ(), g_PositionWallInMiddleFromNyami.GetOrientation(), QuaternionData(0, 0, 0, 0), 0);
                /// Holy Wall, Object Behind
                l_Tuulani->SummonGameObject(eAuchindounObjects::GameobjectHolyWall, g_PositionWallInBackFromNyami.GetPositionX(), g_PositionWallInBackFromNyami.GetPositionY(), g_PositionWallInBackFromNyami.GetPositionZ(), g_PositionWallInBackFromNyami.GetOrientation(), QuaternionData(0, 0, 0, 0), 0);

                /// Three prisonners
                for (int8 l_I = 0; l_I < 3; l_I++)
                {
                    if (Creature* l_Prisoners = l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureAucheniSoulPriest, g_PositionThreePrisoners[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        l_Prisoners->SetCanFly(true);
                        l_Prisoners->SetDisableGravity(true);
                        l_Prisoners->SetReactState(ReactStates::REACT_PASSIVE);
                        l_Prisoners->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                        l_Prisoners->CastSpell(l_Prisoners, eAuchindounSpells::SpellPrisonAura, true);
                        l_Prisoners->CastSpell(l_Prisoners, eAuchindounSpells::SpellStrangulate, true);
                       // l_Prisoners->UNIT_NPC_EMOTESTATEUnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        l_Prisoners->AddUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
                        l_Prisoners->AddDynamicFlag(UnitDynFlags::UNIT_DYNFLAG_DEAD);
                    }
                }

                /// Twelve prisoners (cosmetic)
                for (int8 l_I = 0; l_I < 11; l_I++)
                {
                    if (Creature* l_Prisoners = l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureAucheniDefender, g_PositionCorpsesNearNyomi[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        l_Prisoners->SetReactState(ReactStates::REACT_PASSIVE);
                        l_Prisoners->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                        l_Prisoners->AddDynamicFlag(UnitDynFlags::UNIT_DYNFLAG_DEAD);
                        l_Prisoners->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        l_Prisoners->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN | UnitFlags2::UNIT_FLAG2_FEIGN_DEATH));
                    }
                }

                /// Defenders
                for (int8 l_I = 0; l_I < 4; l_I++)
                {
                    if (Creature* l_Defenders = l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureAucheniWarden, g_PositionDefenderBehindMiddleWallOfNyami[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        l_Defenders->SetReactState(ReactStates::REACT_PASSIVE);
                        l_Defenders->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                        if (Creature* l_Stalker = l_Defenders->FindNearestCreature(eAuchindounCreatures::CreatureLightWallTargets, 8.0f))
                            l_Defenders->CastSpell(l_Stalker, eAuchindounSpells::SpellHolyBeam);
                    }
                }

                /// Cosmetic Wardens
                for (int8 l_I = 0; l_I < 2; l_I++)
                {
                    if (Creature* l_Defenders = l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureAucheniWarden, g_PositionDefenderBehindBackWallOfNyami[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        l_Defenders->SetReactState(ReactStates::REACT_PASSIVE);
                        l_Defenders->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                        if (Creature* l_Stalker = l_Defenders->FindNearestCreature(eAuchindounCreatures::CreatureLightWallTargets, 15.0f))
                            l_Defenders->CastSpell(l_Stalker, eAuchindounSpells::SpellHolyBeam);
                    }
                }

                l_Tuulani->SummonCreature(NPC_NYAMI, g_PositionNyamiSpawn, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);

                // Corpses		                          
                for (int8 l_I = 0; l_I < 2; l_I++)                              /// Holy Wall, Object In MIddle
                    l_Tuulani->SummonGameObject(eAuchindounObjects::GameobjectHolyWall, g_PositionWallInMiddleFromNyami.GetPositionX(), g_PositionWallInMiddleFromNyami.GetPositionY(), g_PositionWallInMiddleFromNyami.GetPositionZ(), g_PositionWallInMiddleFromNyami.GetOrientation(), QuaternionData(0, 0, 0, 0), 0);

                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiDefender, g_PositionMagusAndDefenderHostile[1], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Hostile near Two corpses          		
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiMagus, g_PositionMagusAndDefenderHostile[0], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Two defender		
                for (int8 l_I = 0; l_I < 2; l_I++)
                    l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiDefender, g_PositionSargereiDefenders[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Magus p_Who control footmans                                  		
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiMagus, g_PositionMagusp_WhoControlFootmans, TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Twelve prisoners (cosmetic)		
                for (int8 l_I = 0; l_I < 11; l_I++)
                {
                    if (Creature* l_Prisoner = l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureAucheniDefender, g_PositionCorpsesNearNyomi[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        l_Prisoner->SetReactState(ReactStates::REACT_PASSIVE);
                        l_Prisoner->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                        l_Prisoner->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN | UnitFlags2::UNIT_FLAG2_FEIGN_DEATH));
                    }
                }

                // Pack of arbitrer and magus and defender.		                                 /// Defenders
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSpitefulArbitrerTrash, g_PositionThreeHostileArbitrerMagusSoulPriest[0], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiMagus, g_PositionThreeHostileArbitrerMagusSoulPriest[1], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargeriSoulPriest, g_PositionThreeHostileArbitrerMagusSoulPriest[2], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Warden		
                l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargeriWarden, g_PositionWardenAndGuards, TempSummonType::TEMPSUMMON_DEAD_DESPAWN);

                // Defenders		
                // Twelve prisoners (cosmetic)		
                for (int8 l_I = 0; l_I < 2; l_I++)
                {
                    l_Tuulani->SummonCreature(eAuchindounCreatures::CreatureSargereiDefender, g_PositionGuardsAndWardens[l_I], TempSummonType::TEMPSUMMON_DEAD_DESPAWN);
                }

                /*
                uint32 l_EntriesOfSargereiDraeneis[8] = { eAuchindounCreatures::CreatureSargeriMagus, eAuchindounCreatures::CreatureAucheniArbiter,
                eAuchindounCreatures::CreatureSargeriSoulPriest, eAuchindounCreatures::CreatureSargeriWarden,
                eAuchindounCreatures::CreatureAuchenaiAssainated, eAuchindounCreatures::CreatureSargereiAssasinating, eAuchindounCreatures::CreatureWardenAzzakael, eAuchindounBosses::BossNyami };

                std::list<Creature*> l_ListSargereiDraeneis;
                for (uint8 l_I = 0; l_I < 8; l_I)
                {
                l_Tuulani->GetCreatureListWithEntryInGrid(l_ListSargereiDraeneis, l_EntriesOfSargereiDraeneis[l_I], 1000.0f);
                }

                if (!l_ListSargereiDraeneis.empty())
                {
                for (Creature* l_Itr : l_ListSargereiDraeneis)
                {
                l_Itr->SetPhaseMask(1, true);
                l_Itr->SetFaction(HostileFaction);
                l_Itr->SetReactState(ReactStates::REACT_AGGRESSIVE);
                l_Itr->RemoveFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
                }
                }

                */
            }
                       
            /// Magus
            if (Creature* l_Magus = me->GetSummonedCreatureByEntry(eAuchindounCreatures::CreatureAucheniMagus))
            {
                l_Magus->CastSpell(l_Magus, eAuchindounSpells::SpellArcaneChanneling);
                l_Magus->SummonGameObject(eAuchindounObjects::GameobjectTaladorPortal, g_PositionTuulaniGobjectPortalSpawn.GetPositionX(), g_PositionTuulaniGobjectPortalSpawn.GetPositionY(), g_PositionTuulaniGobjectPortalSpawn.GetPositionZ(), g_PositionTuulaniGobjectPortalSpawn.GetOrientation(), QuaternionData(0, 0, 0, 0), 0);
            }             
            break;
        }
        case Events::EVENT_POST_KAATHAR_3:
        {
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
            {
                /// Phases Teronogor and all the other creatures back to phase 1
                uint32 l_CreaturesTeronogorPhaseIn[7] = { eAuchindounCreatures::CreatureZipteq, eAuchindounCreatures::CreatureZashoo, eAuchindounCreatures::CreatureShaadum,
                    eAuchindounCreatures::CreatureGromtashTheDestructor, eAuchindounCreatures::CreatureGulkosh, eAuchindounCreatures::CreatureDurem, NPC_TERONOGOR };

                std::list<Creature*> l_CreaturesTeronogorPhaseInList;

                for (uint8 l_I = 0; l_I < 7; l_I++)
                {
                    l_Tuulani->GetCreatureListWithEntryInGrid(l_CreaturesTeronogorPhaseInList, l_CreaturesTeronogorPhaseIn[l_I], 700.0f);
                }

                if (!l_CreaturesTeronogorPhaseInList.empty())
                {
                    for (Creature* l_Itr : l_CreaturesTeronogorPhaseInList)
                    {
                        if (!l_Itr)
                            continue;
                        //  l_Itr->SetPhaseMask(1, true);
                    }
                }
            }           
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_1:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
            {
                //????! ????,??????
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK6);
                l_Nyami->CastSpell(l_Nyami, eAuchindounSpells::SpellNyamiExplodeCrystal);
                if (GameObject* l_Crystal = me->FindNearestGameObject(GameObjectAuchindounCrystal, 1000.0f))
                    l_Crystal->Delete();

                //if (Unit* l_Caster = l_Nyami->FindNearestCreature(eAuchindounCreatures::CreatureLeftCrystalTrigger, 1000.0f))
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_2, 3 * TimeConstants::IN_MILLISECONDS);
            }           
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_2:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
            {
                //???! ???..????????,???????????!
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK7);

                /// Cosmetic crystal projectiles flies toward the middle
                if (Creature* l_Teronoger = instance->GetCreature(eAuchindounDatas::DataBossTeronogor)){}

                if (Unit* l_Caster = l_Nyami->FindNearestCreature(eAuchindounCreatures::CreatureLeftCrystalTrigger, 1000.0f))
                {
                    for (uint8 l_I = 0; l_I < 20; l_I++)
                    {
                        // G3D::Vector3 l_Source(1911.741f, 3183.639f, 56.50413f);
                        //  G3D::Vector3 l_Dest(1911.731f, 3183.639f, 56.50413f);
                        //  G3D::Vector3 l_Orientation(0.0f, 0.0f, 0.0f);
                        l_Caster->SendPlaySpellVisual(Position(1911.741f, 3183.639f, 56.50413f, 0.0f), 0.f, eAuchindounSpellVisualKit::SpellVisualKitBlackOrbFallingDownInSpiral, 0, 0, 8.0f, true);
                    }                 
                }
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_3, 6 * TimeConstants::IN_MILLISECONDS);
            }
           
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_3:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
            {
                //????
                /// Cosmetic crystal projectiles flies toward the middle
                if (Creature* l_Teronoger = instance->GetCreature(eAuchindounDatas::DataBossTeronogor)){ }

                if (Unit* l_Caster = l_Nyami->FindNearestCreature(eAuchindounCreatures::CreatureLeftCrystalTrigger, 1000.0f, true))
                {
                    for (uint8 l_I = 0; l_I < 20; l_I++)
                    {
                        //  G3D::Vector3 l_Source(l_Caster->GetPositionX(), l_Caster->GetPositionY(), l_Caster->GetPositionZ());
                        //  G3D::Vector3 l_Dest(l_Teronoger->m_positionX, l_Teronoger->m_positionY, 59.996f);
                        //  G3D::Vector3 l_Orientation(0.0f, 0.0f, 0.0f);

                        l_Caster->SendPlaySpellVisual(Position(l_Caster->GetPositionX(), l_Caster->GetPositionY(), l_Caster->GetPositionZ(), 0.f), 0.0f, eAuchindounSpellVisualKit::SpellVisualKitBlackOrbFallingDownInSpiral, 0, 0, 8.0f, true);
                    }
                }
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_4, 4 * TimeConstants::IN_MILLISECONDS);              
            }  
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_4:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
            {
                //??! ???????!
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK8);
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_5, 5 * TimeConstants::IN_MILLISECONDS);
            }

            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_5:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
                l_Nyami->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformNyamiEscape06, g_PositionNyamiEscapeMovement[1]);
            events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_6, 5 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_6:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
            {
                me->SetFaction(HostileFaction);
                l_Nyami->SetSpeed(UnitMoveType::MOVE_RUN, 10.0f);
                l_Nyami->RemoveAura(eAuchindounSpells::SpellTuulaniCapturedVoidPrison);
                l_Nyami->AddAura(eAuchindounSpells::SpellDispersionVisualNyami, l_Nyami);
                l_Nyami->CastSpell(l_Nyami, eAuchindounSpells::SpellCrystalEarthquake);
                l_Nyami->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformNyamiEscape07, 1765.926f, 3178.208f, 57.904f, true);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                me->GetMotionMaster()->MoveJump(g_PositionKaatharCombatJump.GetPositionX(), g_PositionKaatharCombatJump.GetPositionY(), g_PositionKaatharCombatJump.GetPositionZ(), 10.0f, 10.0f, 10.0f, 0);
                events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_7, 4 * TimeConstants::IN_MILLISECONDS);
            }           
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_7:
        {
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 1000.0f))
                l_Nyami->DespawnOrUnsummon(5 * TimeConstants::IN_MILLISECONDS);
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
                l_Tuulani->AI()->Talk(eAuchindounTalks::TUULANITALK10);
            events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_8, 5 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_8:
        {
            //????..??!
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
                l_Tuulani->AI()->Talk(eAuchindounTalks::TUULANITALK11);
            events.ScheduleEvent(Events::EVENT_NYAMI_ESCAPE_9, 5 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case Events::EVENT_NYAMI_ESCAPE_9:
        {
            //???????????,????????!
            if (Creature* l_Tuulani = me->FindNearestCreature(CreatureSoulBinderTuulani, 1000.0f))
            {
                l_Tuulani->AI()->Talk(eAuchindounTalks::TUULANITALK9);
                l_Tuulani->AddAura(eAuchindounSpells::SpellTuulaniCapturedVoidPrison, l_Tuulani);
            }          
            break;
        }
        case eKaatharEvents::EventFate:
        {
            me->CastSpell(me, eKaatharSpells::SpellFate);
            //  me->MonsterTextEmote("|cffff0000[Fate]|cfffaeb00!", me->GetGUID(), true);
            events.ScheduleEvent(eKaatharEvents::EventFate, 37 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eKaatharEvents::EventHallowedGround:
        {
            Position l_Position;
            me->GetRandomNearPosition(20.0f);
            me->SummonCreature(eKaatharCreatures::TriggerHallowedGround, l_Position, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 30 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eKaatharEvents::EventHallowedGround, 8 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eKaatharEvents::EventHolyShield:
        {
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
            {
                float l_X = l_Target->m_positionX + 10 /** cos(l_Target->m_orientation)*/;
                float l_Y = l_Target->m_positionY + 10/* * sin(l_Target->m_orientation)*/;

                Talk(eKaatharTalks::VigilantKaatherSpell2);
                me->CastSpell(l_Target, eKaatharSpells::SpellHolyShieldThrow);
                if (me->HasAura(eKaatharSpells::SpellHolyShieldOffHandDisarm))
                    me->AddAura(eKaatharSpells::SpellHolyShieldTwoHandDisarm, me);
                else
                    me->AddAura(eKaatharSpells::SpellHolyShieldOffHandDisarm, me);

                std::string l_Str;
                l_Str += "Vigilant kaathar hurls his |cffff0000[Holy Shield]|cfffaeb00! at ";
                l_Str += l_Target->GetName();
                //  me->MonsterTextEmote(l_Str.c_str(), me->GetGUID(), true);                
                events.ScheduleEvent(eKaatharEvents::EventConsecratedLight, 4 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eKaatharEvents::EventHolyShieldReturn, 14 * TimeConstants::IN_MILLISECONDS);
            }
            events.ScheduleEvent(eKaatharEvents::EventHolyShield, 47 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eKaatharEvents::EventHolyShieldReturn:
        {
            if (Creature* l_Shield = me->FindNearestCreature(eKaatharCreatures::TriggerHolyShield, 50.0f, true))
            {
                me->SetCurrentEquipmentId(1); /// Equipment Id
                l_Shield->DespawnOrUnsummon(3 * TimeConstants::IN_MILLISECONDS);
                l_Shield->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 20.0f, 10.0f, 10.0f);
                DespawnCreaturesInArea(eKaatharCreatures::TriggerHolyShield, me);

                if (me->HasAura(eKaatharSpells::SpellHolyShieldOffHandDisarm))
                    me->RemoveAura(eKaatharSpells::SpellHolyShieldOffHandDisarm);
                else if (me->HasAura(eKaatharSpells::SpellHolyShieldTwoHandDisarm))
                    me->RemoveAura(eKaatharSpells::SpellHolyShieldTwoHandDisarm);

                /// Despawn previous Holy Shields.
                std::list<AreaTrigger*> l_ListAreaTriggers;
                // me->GetAreaTriggerList(l_ListAreaTriggers, eKaatharSpells::SpellHolyShieldAreaTrigger);
                if (!l_ListAreaTriggers.empty())
                {
                    for (AreaTrigger* l_Itr : l_ListAreaTriggers)
                        l_Itr->Remove(/*4 * TimeConstants::IN_MILLISECONDS*/);
                }
            }
            break;
        }
        case eKaatharEvents::EventConsecratedLight:
        {
            Talk(eKaatharTalks::VigilantKaatherSpell1);
            DoCast(eKaatharSpells::SpellConsecratedLight);
            // me->MonsterTextEmote("Vigilant Kaathar readies |cffff0000[Consecrated Light]|cfffaeb00!. Hide!", me->GetGUID(), true);
            break;
        }
        case eKaatharEvents::EventSanctifiedStrike:
        {
            DoCastVictim(eKaatharSpells::SpellSanctifiedStrikeDummy);

            for (uint8 l_I = 0; l_I <= 10; l_I++)
            {
                float l_PosX = me->GetPositionX() + (l_I + 1)/* * cos(me->m_orientation)*/;;
                float l_PosY = me->GetPositionY() + l_I /** sin(me->m_orientation)*/;

                l_PosX += frand(0.5f, 1.8f);
                l_PosY += frand(0.7f, 1.9f);

                me->SummonCreature(eKaatharCreatures::TriggerFissureSummoner, l_PosX, l_PosY, me->GetPositionZ(), me->GetOrientation(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 15 * TimeConstants::IN_MILLISECONDS);
            }
            events.ScheduleEvent(eKaatharEvents::EventSanctifiedStrike, 8 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who && who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !m_Intro && m_IntroDone)
        {
            m_Intro = true;
            Talk(eKaatharTalks::VigilantKaatherIntro);
            me->SetHomePosition(g_KaatharNewHomePosition);
        }
    }
};

/// Hallowed Ground - 537324

struct auchindoun_kaathar_mob_hallowed_ground : public ScriptedAI
{
    auchindoun_kaathar_mob_hallowed_ground(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_First = false;
    }

    uint32 m_VisualDiff;
    EventMap events;
    bool m_HasExploded;
    bool m_First;

    void Reset()
    {
        events.Reset();
        m_HasExploded = false;
        me->SetFaction(HostileFaction);
        m_VisualDiff = 1 * TimeConstants::IN_MILLISECONDS;
        events.ScheduleEvent(eKaatharEvents::EventCheckPlayer, 4 * TimeConstants::IN_MILLISECONDS); // Takes 4 seconds to charge

        if (!m_First)
        {
            me->SetObjectScale(1.0f);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
            me->SetReactState(ReactStates::REACT_PASSIVE);
        }
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eKaatharActions::ActionFateHallowedGround:
            DoCast(me, eKaatharSpells::SpellHallowedGround);
            me->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }
    }

    void UpdateAI(uint32 p_Diff)
    {
        events.Update(p_Diff);

        // Visual
        if (m_VisualDiff <= p_Diff)
        {
            me->CastSpell(me, eKaatharSpells::SpellHallowedGroundsTriggerMissile);
            m_VisualDiff = 1 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_VisualDiff -= p_Diff;

        switch (events.ExecuteEvent())
        {
        case eKaatharEvents::EventCheckPlayer:
            if (m_HasExploded)
                return;

            if (Player* l_Player = me->SelectNearestPlayer(4.0f))  //modify
            {
                if (l_Player->IsWithinDistInMap(me, 4.0f))
                {
                    m_HasExploded = true;

                    DoCast(me, eKaatharSpells::SpellHallowedGround);
                    me->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
                }
            }

            events.ScheduleEvent(eKaatharEvents::EventCheckPlayer, 1 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }
    }
};

/// Fissure Spawner Trigger - 543536
struct auchindoun_kaathar_mob_spawn_fissures : public ScriptedAI
{
    auchindoun_kaathar_mob_spawn_fissures(Creature* p_Creature) : ScriptedAI(p_Creature) { }

    void Reset()
    {
        me->SetFaction(HostileFaction);
        me->SetDisplayId(InvisibleDisplay);
        me->CastSpell(me, eKaatharSpells::SpellSanctifiedStrikeAreaTrigger4);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC));
    }
};

/// Post Fight Summoner to Center - 324235
struct auchindoun_kaathar_mob_teleport_players : public ScriptedAI
{
    auchindoun_kaathar_mob_teleport_players(Creature* p_Creature) : ScriptedAI(p_Creature) {}

    void Reset()
    {
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC));
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (instance)
            if (Creature* l_Kaathar = instance->GetCreature(eAuchindounDatas::DataBossKathaar))
                if (l_Kaathar->isDead())
                    if (Player * l_Player = me->SelectNearestPlayer(10.0f))
                        l_Player->TeleportTo(1182, 1904.29f, 3185.111f, 30.799f, 3.34086f);
    }
};

/// Holy Shield - 76071
struct auchindoun_kaathar_mob_holy_shield : public ScriptedAI
{
    auchindoun_kaathar_mob_holy_shield(Creature* p_Creature) : ScriptedAI(p_Creature) { }

    void Reset()
    {
        me->SetFaction(HostileFaction);
        me->SetDisplayId(InvisibleDisplay);
        me->CastSpell(me, eKaatharSpells::SpellHolyShieldLos);
        me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
        me->AddUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
        me->AddDynamicFlag(UnitDynFlags::UNIT_DYNFLAG_DEAD);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
        /// Knockback
        std::list<Player*> l_ListPlayers;
        me->GetPlayerListInGrid(l_ListPlayers, 5.0f);
        if (!l_ListPlayers.empty())
        {
            for (Player* l_itr : l_ListPlayers)
            {
                if (!l_itr)
                    continue;

                l_itr->CastSpell(l_itr, eKaatharSpells::SpellHolyShieldKnockBack);
                me->CastSpell(l_itr, eKaatharSpells::SpellHolyShieldDamageFromKnockBack);
            }
        }
    }
};

/// Consecrated Light - 153006
class auchindoun_kaathar_spell_consecrated_light : public SpellScriptLoader
{
public:

    auchindoun_kaathar_spell_consecrated_light() : SpellScriptLoader("auchindoun_kaathar_spell_consecrated_light") { }

    class auchindoun_kaathar_spell_consecrated_light_SpellScript : public AuraScript
    {
        PrepareAuraScript(auchindoun_kaathar_spell_consecrated_light_SpellScript);

        void HandlePeriodic(AuraEffect const* /*p_AurEff*/)
        {
            if (GetCaster())
            {
                if (InstanceScript* m_Instance = GetCaster()->GetInstanceScript())
                {
                    std::list<Player*> l_ListPlayers;
                    GetCaster()->GetPlayerListInGrid(l_ListPlayers, 200.0f);
                    if (!l_ListPlayers.empty())
                    {
                        for (Player* l_Itr : l_ListPlayers)
                        {
                            if (!l_Itr)
                                continue;

                            l_Itr->CastSpell(l_Itr, eKaatharSpells::SpellConsecratedLightDamage, true);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_kaathar_spell_consecrated_light_SpellScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new auchindoun_kaathar_spell_consecrated_light_SpellScript();
    }
};

/// Consecrated Light - 156746
class auchindoun_kaathar_spell_conscreated_damage : public SpellScriptLoader
{
public:

    auchindoun_kaathar_spell_conscreated_damage() : SpellScriptLoader("auchindoun_kaathar_spell_conscreated_damage") { }

    class auchindoun_kaathar_spell_conscreated_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(auchindoun_kaathar_spell_conscreated_damage_SpellScript);

        void RecalculateDamage(SpellEffIndex /*p_EffIndex*/)
        {
            if (!GetCaster() && !GetHitUnit())
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (!GetHitDamage())
                    return;

                if (Creature* l_Kaathar = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
                    if (Creature* l_Shield = GetCaster()->FindNearestCreature(eKaatharCreatures::TriggerHolyShield, 200.0f))
                        if (l_Shield->IsInBetween(GetHitUnit(), l_Kaathar))
                            SetHitDamage(0);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(auchindoun_kaathar_spell_conscreated_damage_SpellScript::RecalculateDamage, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new auchindoun_kaathar_spell_conscreated_damage_SpellScript();
    }
};

/// Sanctified Ground Periodic Dummy - 153430
class auchindoun_kaathar_spell_sanctified_ground : public SpellScriptLoader
{
public:

    auchindoun_kaathar_spell_sanctified_ground() : SpellScriptLoader("auchindoun_kaathar_spell_sanctified_ground") { }

    class auchindoun_kaathar_spell_sanctified_ground_AuraScript : public AuraScript
    {
        PrepareAuraScript(auchindoun_kaathar_spell_sanctified_ground_AuraScript);

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            PreventDefaultAction();

            if (GetCaster() && GetTarget())
            {
                GetTarget()->CastSpell(GetTarget(), eKaatharSpells::SpellSanctifiedGroundTickDamage);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_kaathar_spell_sanctified_ground_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new auchindoun_kaathar_spell_sanctified_ground_AuraScript();
    }
};

/// Fate - 157465
class auchindoun_kaathar_spell_fate : public SpellScriptLoader
{
public:

    auchindoun_kaathar_spell_fate() : SpellScriptLoader("auchindoun_kaathar_spell_fate") { }

    class auchindoun_kaathar_spell_fate_SpellScript : public SpellScript
    {
        PrepareSpellScript(auchindoun_kaathar_spell_fate_SpellScript);

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {
                std::list<Creature*> l_HallowedGroundCreatures;
                GetCaster()->GetCreatureListWithEntryInGrid(l_HallowedGroundCreatures, eKaatharCreatures::TriggerHallowedGround, 150.0f);
                if (!l_HallowedGroundCreatures.empty())
                {
                    for (Creature* l_Itr : l_HallowedGroundCreatures)
                    {
                        if (l_Itr->IsAIEnabled)
                            l_Itr->GetAI()->DoAction(eKaatharActions::ActionFateHallowedGround);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(auchindoun_kaathar_spell_fate_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new auchindoun_kaathar_spell_fate_SpellScript();
    }
};

/// Sanctified Strike Fissure - 

class auchindoun_kaathar_at_fissure : public AreaTriggerEntityScript
{
public:

    auchindoun_kaathar_at_fissure() : AreaTriggerEntityScript("auchindoun_kaathar_at_fissure")
    {
    }

    uint32 m_Diff = 2 * TimeConstants::IN_MILLISECONDS;
    std::list<uint64> m_Targets;

    void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
    {
        if (m_Diff <= p_Time)
        {
            std::list<Player*> l_PlayerList;
            p_AreaTrigger->GetPlayerListInGrid(l_PlayerList, 1.0f);
            // p_AreaTrigger->VisitNearbyObject(2.0f, searcher);

            if (!l_PlayerList.empty())
            {
                for (std::list<Player*>::const_iterator l_Itr = l_PlayerList.begin(); l_Itr != l_PlayerList.end(); ++l_Itr)
                {
                    if (!(*l_Itr))
                        continue;

                    if (!(*l_Itr)->HasAura(eKaatharSpells::SpellSanctifiedGroundAura))
                        (*l_Itr)->CastSpell((*l_Itr), eKaatharSpells::SpellSanctifiedGroundAura);
                }
            }

            m_Diff = 2 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_Diff -= p_Time;
    }
    /*
    auchindoun_kaathar_at_fissure* GetAI()
    {
    return nullptr;
    }*/
};

/// Hallowed Ground  - 

class auchindoun_kaathar_at_hallowed_ground : public AreaTriggerEntityScript
{
public:

    auchindoun_kaathar_at_hallowed_ground() : AreaTriggerEntityScript("auchindoun_kaathar_at_hallowed_ground")
    {
    }

    float m_Size;
    uint32 m_Diff = 2 * TimeConstants::IN_MILLISECONDS;
    uint32 m_Explosion = 15 * TimeConstants::IN_MILLISECONDS;
    std::list<ObjectGuid> m_Targets;

    void OnCreate(AreaTrigger* p_AreaTrigger)
    {
        m_Size = 3.0f;
        p_AreaTrigger->SetObjectScale(m_Size);
    }

    void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
    {
        if (m_Diff <= p_Time)
        {
            m_Size -= float(0.3f);
            p_AreaTrigger->SetObjectScale(m_Size);

            std::list<Player*> l_PlayerList;
            p_AreaTrigger->GetPlayerListInGrid(l_PlayerList, 2.0f);
            // p_AreaTrigger->VisitNearbyObject(2.0f, searcher);

            if (!l_PlayerList.empty())
            {
                for (std::list<Player*>::const_iterator l_Itr = l_PlayerList.begin(); l_Itr != l_PlayerList.end(); ++l_Itr)
                {
                    if (!(*l_Itr))
                        continue;

                    if (!(*l_Itr)->HasAura(eKaatharSpells::SpellSanctifiedGroundAura))
                    {
                        (*l_Itr)->CastSpell((*l_Itr), eKaatharSpells::SpellSanctifiedGroundAura);
                        m_Targets.push_back((*l_Itr)->GetGUID());
                    }
                }
            }

            m_Diff = 2 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_Diff -= p_Time;
    }

    void OnRemove(AreaTrigger* p_AreaTrigger, uint32 p_Time)
    {
        if (!m_Targets.empty())
        {
            for (ObjectGuid l_Guid : m_Targets)
            {
                // if (!l_Guid)
                //   continue;

                Unit* l_Target = ObjectAccessor::GetUnit(*p_AreaTrigger, l_Guid);
                if (l_Target && l_Target->HasAura(eKaatharSpells::SpellSanctifiedGroundAura))
                    l_Target->RemoveAura(eKaatharSpells::SpellSanctifiedGroundAura);
            }
        }
    }
    /*
    auchindoun_kaathar_at_hallowed_ground* GetAI()
    {
    return nullptr;
    }*/
};

void AddSC_boss_kaathar()
{
    RegisterCreatureAI(boss_kaathar);
    RegisterCreatureAI(auchindoun_kaathar_mob_spawn_fissures);                        ///< 543536//unuse
    RegisterCreatureAI(auchindoun_kaathar_mob_hallowed_ground);                       ///< 537324//unuse
    RegisterCreatureAI(auchindoun_kaathar_mob_holy_shield);                           ///< 76071
    RegisterCreatureAI(auchindoun_kaathar_mob_nyami);                   ///< 77810
    RegisterCreatureAI(auchindoun_kaathar_mob_teleport_players);                      ///< 3242352//unuse
    new auchindoun_kaathar_spell_consecrated_light();                   ///< 153006
    new auchindoun_kaathar_spell_fate();                                ///< 157465
    new auchindoun_kaathar_spell_sanctified_ground();                   ///< 153430
    new auchindoun_kaathar_spell_conscreated_damage();                  ///< 156746
    new auchindoun_kaathar_at_fissure();                                ///< 165065
}
