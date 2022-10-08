#include "instance_skyreach.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"

enum MaxEncounter
{
    Number = 4,
};

static const DoorData k_DoorData[] =
{
    { DOOR_RANJIT_ENTRANCE,             Data::Ranjit,           DOOR_TYPE_ROOM,      },
    { DOOR_RANJIT_EXIT,                 Data::Ranjit,           DOOR_TYPE_PASSAGE,   },
    { DOOR_ARAKNATH_ENTRANCE_1,         Data::Araknath,         DOOR_TYPE_ROOM,      },
    { DOOR_ARAKNATH_ENTRANCE_2,         Data::Araknath,         DOOR_TYPE_ROOM,      },
    { DOOR_ARAKNATH_EXIT_1,             Data::Araknath,         DOOR_TYPE_PASSAGE,   },
    { DOOR_ARAKNATH_EXIT_2,             Data::Araknath,         DOOR_TYPE_PASSAGE,   },
    { DOOR_RUKHRAN_ENTRANCE,            Data::Rukhran,          DOOR_TYPE_ROOM,      },
    { DOOR_RUKHRAN_EXIT,                Data::Rukhran,          DOOR_TYPE_PASSAGE,   },
    { DOOR_HIGH_SAVE_VIRYX_ENTRANCE,    Data::HighSageViryx,    DOOR_TYPE_ROOM,      },
    { 0,                                0,                      DOOR_TYPE_ROOM,      }  // EOF
};

class instance_skyreach : public InstanceMapScript
{
public:
    instance_skyreach() : InstanceMapScript("instance_skyreach", 1209) { }

    struct instance_skyreachInstanceMapScript : public InstanceScript
    {
        // Araknath part.
        ObjectGuid m_AraknathGuid;
        ObjectGuid m_SkyreachArcanologistGuid;
        std::list<ObjectGuid> m_SolarConstructorsGuid;
        ObjectGuid m_SelectedSolarConstructorGuid;
        ObjectGuid m_InteriorFocusGuid;
        ObjectGuid m_SolarConstructorEnergizerGuid;

        // Rukhran part.
        ObjectGuid m_RukhranGuid;
        ObjectGuid m_SkyreachRavenWhispererGuid;
        std::set<ObjectGuid> m_PileOfAshesGuid;
        std::set<ObjectGuid> m_SolarFlaresGuid;
        ObjectGuid m_CacheOfArakoanTreasuresGuid;

        // Wind maze zone.
        std::map<ObjectGuid, uint32> m_PlayerGuidToBlockId;
        std::vector<ObjectGuid> m_WindMazeBlockGuids;

        // High Sage Viryx.
        std::vector<ObjectGuid> m_MagnifyingGlassFocusGuids;
        ObjectGuid m_ReshadOutroGuid;

        // Achievements.
        std::map<ObjectGuid, uint32> m_ReadyForRaidingIVAchievements;
        bool m_HasFailedMonomaniaAchievement;

        instance_skyreachInstanceMapScript(InstanceMap* map) : InstanceScript(map),
            m_AraknathGuid(ObjectGuid::Empty),
            m_SkyreachArcanologistGuid(ObjectGuid::Empty),
            m_SolarConstructorsGuid(),
            m_SelectedSolarConstructorGuid(ObjectGuid::Empty),
            m_InteriorFocusGuid(ObjectGuid::Empty),
            m_SolarConstructorEnergizerGuid(ObjectGuid::Empty),
            m_RukhranGuid(ObjectGuid::Empty),
            m_SkyreachRavenWhispererGuid(ObjectGuid::Empty),
            m_PileOfAshesGuid(),
            m_SolarFlaresGuid(),
            m_CacheOfArakoanTreasuresGuid(ObjectGuid::Empty),
            m_PlayerGuidToBlockId(),
            m_WindMazeBlockGuids(),
            m_MagnifyingGlassFocusGuids(),
            m_ReshadOutroGuid(ObjectGuid::Empty),
            m_HasFailedMonomaniaAchievement(false)
        {
            SetBossNumber(MaxEncounter::Number);
            LoadDoorData(k_DoorData);
            //LoadScenariosInfos(k_ScenarioData, p_Map->IsChallengeMode() ? ScenarioDatas::ChallengeScenarioId : ScenarioDatas::ScenarioId);

            //for (uint32 i = Blocks::FirstStair; i <= Blocks::SecondStair; i++)
            //    m_WindMazeBlockGuids.push_back(MAKE_NEW_GUID(sObjectMgr->GenerateLowGuid(HIGHGUID_AREATRIGGER), 6452, HIGHGUID_AREATRIGGER));

            // instance->SetObjectVisibility(1000.0f);
        }

        void OnCreatureCreate(Creature* p_Creature)
        {
            switch (p_Creature->GetEntry())
            {
            case BossEntries::RANJIT:
                break;
            case BossEntries::ARAKNATH:
                m_AraknathGuid = p_Creature->GetGUID();
                break;
            case BossEntries::RUKHRAN:
                m_RukhranGuid = p_Creature->GetGUID();
                if (GetBossState(Data::Rukhran) == EncounterState::SPECIAL)
                    SetData(Data::SkyreachRavenWhispererIsDead, 0);
                break;
            case MobEntries::SKYREACH_ARCANALOGIST:
                m_SkyreachArcanologistGuid = p_Creature->GetGUID();
                break;
            case MobEntries::SkyreachDefenseConstruct:
                p_Creature->RemoveUnitFlag(UnitFlags(UNIT_FLAG_UNK_6));
                break;
            case MobEntries::SKYREACH_SOLAR_CONSTRUCTOR:
                m_SolarConstructorsGuid.emplace_front(p_Creature->GetGUID());
               // p_Creature->DisableEvadeMode();
                p_Creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_SERVER_CONTROLLED | UNIT_FLAG_IMMUNE_TO_PC));
                if (GetBossState(Data::Araknath) == EncounterState::NOT_STARTED || GetBossState(Data::Araknath) == EncounterState::TO_BE_DECIDED)
                {
                    p_Creature->CastSpell(p_Creature, uint32(RandomSpells::ENERGIZE_VISUAL_1));
                    p_Creature->RemoveAura(RandomSpells::SUBMERGED);
                }
                else
                {
                    p_Creature->AddAura(RandomSpells::SUBMERGED, p_Creature);
                    p_Creature->SetReactState(ReactStates::REACT_PASSIVE);
                    p_Creature->getThreatManager().clearReferences();
                    p_Creature->getThreatManager().resetAllAggro();
                }
                break;
            case MobEntries::SKYREACH_RAVEN_WHISPERER:
                m_SkyreachRavenWhispererGuid = p_Creature->GetGUID();
                break;
            case MobEntries::YoungKaliri:
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
                //p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
                p_Creature->SetFaction(16);
                //p_Creature->DisableEvadeMode();
                p_Creature->AddUnitFlag(UnitFlags(UNIT_FLAG_SERVER_CONTROLLED | UNIT_FLAG_NON_ATTACKABLE));
                break;
            case MobEntries::Arakkoa:
            case MobEntries::Kaliri:
            case MobEntries::Kaliri2:
                // Setting fly.
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
               // p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
                break;
            case MobEntries::PILE_OF_ASHES:
                p_Creature->AddUnitState(UNIT_STATE_UNATTACKABLE);
                p_Creature->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                p_Creature->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC));
                m_PileOfAshesGuid.insert(p_Creature->GetGUID());
                break;
            case MobEntries::SOLAR_FLARE:
                m_SolarFlaresGuid.insert(p_Creature->GetGUID());
                break;
            case MobEntries::GrandDefenseConstruct:
            case MobEntries::RadiantSupernova:
            case MobEntries::AirFamiliar:
                p_Creature->SetFaction(16);
                break;
            case MobEntries::ArakkoaPincerBirdsController:
                p_Creature->AddAura(16245, p_Creature); // Freeze anim spell.
                p_Creature->SetFaction(16);
                p_Creature->SetReactState(REACT_PASSIVE);
                p_Creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_SERVER_CONTROLLED | UNIT_FLAG_IMMUNE_TO_PC));
                break;
            case MobEntries::SolarZealot:
                p_Creature->SetFaction(16);
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
               // p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
              //  p_Creature->DisableEvadeMode();
                break;
            case MobEntries::DreadRavenHatchling:
                p_Creature->SetFaction(16);
                break;
            case MobEntries::SunConstructEnergizer:
                m_SolarConstructorEnergizerGuid = p_Creature->GetGUID();
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
              //  p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
                break;
            case MobEntries::InteriorFocus:
                m_InteriorFocusGuid = p_Creature->GetGUID();
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
              //  p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
                break;
            case MobEntries::AraokkoaMagnifyingConstructA:
                m_MagnifyingGlassFocusGuids.push_back(p_Creature->GetGUID());
                p_Creature->SetFaction(16);
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
              //  p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                p_Creature->SetReactState(REACT_PASSIVE);
               // p_Creature->DisableEvadeMode();
                break;
            case MobEntries::ArakkoaMagnifyingGlassFocus:
                p_Creature->SetDisplayId(17519);
                p_Creature->SetReactState(REACT_PASSIVE);
                p_Creature->SetCanFly(false);
               // p_Creature->DisableEvadeMode();
                p_Creature->SetDisableGravity(false);
                break;
            case MobEntries::ReshadOutro:
                m_ReshadOutroGuid = p_Creature->GetGUID();
                p_Creature->SetDisableGravity(true);
                p_Creature->SetCanFly(true);
               // p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);

                if (InstanceScript::GetBossState(Data::HighSageViryx) == EncounterState::DONE)
                {
                    p_Creature->SetVisible(true);
                    p_Creature->GetMotionMaster()->MovePoint(0, 1128.81f, 1814.251f, 262.171f);
                }
                else
                    p_Creature->SetVisible(false);
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* p_Gameobject)
        {
            switch (p_Gameobject->GetEntry())
            {
            case GameObjectEntries::DOOR_RANJIT_ENTRANCE:
            case GameObjectEntries::DOOR_RANJIT_EXIT:
            case GameObjectEntries::DOOR_ARAKNATH_ENTRANCE_1:
            case GameObjectEntries::DOOR_ARAKNATH_ENTRANCE_2:
            case GameObjectEntries::DOOR_ARAKNATH_EXIT_1:
            case GameObjectEntries::DOOR_ARAKNATH_EXIT_2:
            case GameObjectEntries::DOOR_RUKHRAN_ENTRANCE:
            case GameObjectEntries::DOOR_RUKHRAN_EXIT:
            case GameObjectEntries::DOOR_HIGH_SAVE_VIRYX_ENTRANCE:
                AddDoor(p_Gameobject, true);
                break;
            default:
                break;
            }
        }

        void OnCreatureKilled(Creature* p_Creature, Player* /*p_Player*/)
        {
           // if (!instance->IsChallengeMode() || !IsChallengeModeStarted() || m_CreatureKilled >= ScenarioDatas::MaxEnnemiesToKill)
              //  return;

            if (p_Creature == nullptr)
                return;

            if (!p_Creature->isElite() || p_Creature->IsDungeonBoss())
                return;

           // ++m_CreatureKilled;
            //SendScenarioProgressUpdate(CriteriaProgressData(ScenarioDatas::EnnemiesCriteriaId, m_CreatureKilled, m_InstanceGuid, uint32(time(nullptr)), m_BeginningTime, 0));

          //  if (m_CreatureKilled >= ScenarioDatas::MaxEnnemiesToKill)
           //     m_ConditionCompleted = true;
        }

        bool SetBossState(uint32 p_ID, EncounterState p_State)
        {
            if (!InstanceScript::SetBossState(p_ID, p_State))
                return false;

            switch (p_ID)
            {
            case Data::Ranjit:
            {
                // Achievement handling.
                if (p_State == EncounterState::DONE && instance->IsHeroic())
                {
                    DoCompleteAchievement(uint32(Achievements::ReadyForRaidingIV));
                }

                break;
            }
            case Data::Araknath:
            {
                switch (p_State)
                {
                case EncounterState::FAIL:
                {
                    if (Creature* l_SkyreachArcanologist = instance->GetCreature(m_SkyreachArcanologistGuid))
                        l_SkyreachArcanologist->Respawn();
                    break;
                }
                case EncounterState::DONE:
                {
                    if (instance->IsHeroic())
                        DoCompleteAchievement(uint32(Achievements::MagnifyEnhance));

                    for (ObjectGuid l_Guid : m_SolarConstructorsGuid)
                    {
                        if (Creature* l_Constructor = instance->GetCreature(l_Guid))
                        {
                            l_Constructor->CombatStop();
                            l_Constructor->SetReactState(ReactStates::REACT_PASSIVE);
                            l_Constructor->getThreatManager().clearReferences();
                            l_Constructor->getThreatManager().resetAllAggro();
                        }
                    }

                    break;
                }
                default:
                    break;
                }

                break;
            }
            case Data::Rukhran:
            {
                switch (p_State)
                {
                case EncounterState::FAIL:
                {
                    if (Creature* l_Rukhran = instance->GetCreature(m_RukhranGuid))
                    {
                        l_Rukhran->GetMotionMaster()->Clear(true);
                        SetBossState(Data::Rukhran, EncounterState::SPECIAL);
                        l_Rukhran->GetMotionMaster()->MovePoint(12, 918.92f, 1913.46f, 215.87f);
                    }
                    break;
                }
                default:
                    break;
                }

                break;
            }
            case Data::HighSageViryx:
            {
                switch (p_State)
                {
                case EncounterState::DONE:
                {
                    if (Creature* l_Reshad = instance->GetCreature(m_ReshadOutroGuid))
                    {
                        l_Reshad->SetVisible(true);
                        l_Reshad->GetMotionMaster()->MovePoint(0, 1128.81f, 1814.251f, 262.171f);
                    }

                    if (instance->IsHeroic())
                        DoCompleteAchievement(uint32(Achievements::HeroicSkyreach));
                    else
                        DoCompleteAchievement(uint32(Achievements::Skyreach));

                    if (instance->IsHeroic() && !m_HasFailedMonomaniaAchievement)
                        DoCompleteAchievement(uint32(Achievements::Monomania));

                    DoKilledMonsterCredit(ScenarioDatas::ScenarioDatas::DailyChallengeQuestID, ScenarioDatas::ScenarioDatas::DailyChallengeKillCredit);
                    break;
                }
                default:
                    break;
                }

                break;
            }
            default:
                break;
            }

            return true;
        }

        void SetData(uint32 p_Type, uint32 p_Data)
        {
            switch (p_Type)
            {
            case Data::SkyreachRavenWhispererIsDead:
                if (Creature* l_Rukhran = instance->GetCreature(m_RukhranGuid))
                {
                    if (GetBossState(Data::Rukhran) == EncounterState::NOT_STARTED)
                    {
                        l_Rukhran->RemoveAura(157259);
                        l_Rukhran->GetMotionMaster()->Clear(true);
                        l_Rukhran->GetMotionMaster()->MovePoint(12, 918.92f, 1913.46f, 215.87f);
                       // l_Rukhran->DisableEvadeMode();
                        SetBossState(Data::Rukhran, EncounterState::SPECIAL);
                    }
                    else
                        l_Rukhran->SetOrientation(5.4f);
                }
                break;
            case Data::SkyreachArcanologistIsDead:
                if (Creature* l_Araknath = instance->GetCreature(m_AraknathGuid))
                {
                    SetBossState(Data::Araknath, EncounterState::SPECIAL);
                    l_Araknath->RemoveAura(RandomSpells::SUBMERGED);
                    l_Araknath->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    l_Araknath->SetReactState(REACT_AGGRESSIVE);
                }

                for (ObjectGuid l_Guid : m_SolarConstructorsGuid)
                {
                    if (Creature* l_Constructor = instance->GetCreature(l_Guid))
                    {
                        l_Constructor->CastStop();
                        l_Constructor->AddAura(RandomSpells::SUBMERGED, l_Constructor);
                    }
                }

                if (Creature* l_InteriorFocus = instance->GetCreature(m_InteriorFocusGuid))
                    l_InteriorFocus->CastStop();
                if (Creature* l_SolarConstructorEnergizer = instance->GetCreature(m_SolarConstructorEnergizerGuid))
                    l_SolarConstructorEnergizer->CastStop();
                break;
            case Data::SkyreachArcanologistReset:
                if (GetBossState(Data::Araknath) == EncounterState::DONE)
                    break;

                if (Creature* l_Araknath = instance->GetCreature(m_AraknathGuid))
                {
                    l_Araknath->getThreatManager().resetAllAggro();

                    if (l_Araknath->GetAI())
                        l_Araknath->GetAI()->Reset();
                }

                for (ObjectGuid l_Guid : m_SolarConstructorsGuid)
                {
                    if (Creature* l_Constructor = instance->GetCreature(l_Guid))
                    {
                        l_Constructor->CastSpell(l_Constructor, uint32(RandomSpells::ENERGIZE_VISUAL_1));
                        l_Constructor->RemoveAura(RandomSpells::SUBMERGED);
                    }
                }

                if (Creature* l_InteriorFocus = instance->GetCreature(m_InteriorFocusGuid))
                    l_InteriorFocus->CastSpell(l_InteriorFocus, uint32(RandomSpells::ENERGIZE_VISUAL_3));

                if (Creature* l_SolarConstructorEnergizer = instance->GetCreature(m_SolarConstructorEnergizerGuid))
                    l_SolarConstructorEnergizer->CastSpell(l_SolarConstructorEnergizer, uint32(RandomSpells::ENERGIZE_VISUAL_3));
                break;
            case Data::AraknathSolarConstructorActivation:
                if (p_Data)
                {
                    if (m_SolarConstructorsGuid.empty())
                        break;

                    auto l_RandUnit = m_SolarConstructorsGuid.begin();
                    std::advance(l_RandUnit, urand(0, m_SolarConstructorsGuid.size() - 1));
                    m_SelectedSolarConstructorGuid = *l_RandUnit;

                    if (Creature* l_Constructor = instance->GetCreature(m_SelectedSolarConstructorGuid))
                    {
                        l_Constructor->RemoveAura(RandomSpells::SUBMERGED);
                        l_Constructor->CastSpell(l_Constructor, uint32(RandomSpells::ENERGIZE_HEAL));
                    }

                    // Visual part.
                    if (Creature* l_InteriorFocus = instance->GetCreature(m_InteriorFocusGuid))
                        l_InteriorFocus->CastSpell(l_InteriorFocus, uint32(RandomSpells::ENERGIZE_VISUAL_3));

                    if (Creature* l_SolarConstructorEnergizer = instance->GetCreature(m_SolarConstructorEnergizerGuid))
                        l_SolarConstructorEnergizer->CastSpell(l_SolarConstructorEnergizer, uint32(RandomSpells::ENERGIZE_VISUAL_2));
                }
                else
                {
                    if (Creature* l_Constructor = instance->GetCreature(m_SelectedSolarConstructorGuid))
                    {
                        l_Constructor->AddAura(RandomSpells::SUBMERGED, l_Constructor);
                        l_Constructor->CastStop();
                    }

                    // Visual part.
                    if (Creature* l_InteriorFocus = instance->GetCreature(m_InteriorFocusGuid))
                        l_InteriorFocus->CastStop();

                    if (Creature* l_SolarConstructorEnergizer = instance->GetCreature(m_SolarConstructorEnergizerGuid))
                        l_SolarConstructorEnergizer->CastStop();

                    m_SelectedSolarConstructorGuid = ObjectGuid::Empty;
                }
            case Data::StartingLensFlare:
            {
                if (m_MagnifyingGlassFocusGuids.empty())
                    break;

                auto l_Itr = m_MagnifyingGlassFocusGuids.begin();
                std::advance(l_Itr, m_MagnifyingGlassFocusGuids.size() - 1);

                if (Creature* l_Creature = instance->GetCreature(*l_Itr))
                    l_Creature->CastSpell(l_Creature, uint32(RandomSpells::LensFlare), true);

            } break;
            case Data::MonomaniaAchievementFail:
                m_HasFailedMonomaniaAchievement = true;
                break;
            default:
                break;
            }
        }

        void SetGuidData(uint32 p_Type, ObjectGuid p_Data) override
        {
            enum class Spells : uint32
            {
                SOLAR_FLARE = 160964,
                DORMANT = 160641,
                SUMMON_SOLAR_FLARE = 153810,
            };

            switch (p_Type)
            {
            case Data::SolarFlareDying:
                if (m_SolarFlaresGuid.find(p_Data) == m_SolarFlaresGuid.end())
                    break;
                m_SolarFlaresGuid.erase(p_Data);

                if (Unit* l_SolarFlareDying = instance->GetCreature(p_Data))
                {
                    uint32 l_SolarFlaresFormed = 0;
                    std::list<Creature*> l_Piles;
                    l_SolarFlareDying->GetCreatureListWithEntryInGrid(l_Piles, MobEntries::PILE_OF_ASHES, 5.0f);

                    for (Creature* l_Pile : l_Piles)
                    {
                        if (m_PileOfAshesGuid.find(l_Pile->GetGUID()) == m_PileOfAshesGuid.end())
                            continue;
                        m_PileOfAshesGuid.erase(l_Pile->GetGUID());

                        Position l_Pos;
                        l_Pos = l_Pile->GetPosition();
                        if (l_Pile->ToCreature())
                        {
                            l_Pile->CastSpell(l_Pos.m_positionX, l_Pos.m_positionY, l_Pos.m_positionZ, uint32(Spells::SUMMON_SOLAR_FLARE), true);
                            if (TempSummon* l_Summon = l_Pile->SummonCreature(MobEntries::SOLAR_FLARE, l_Pos))
                                m_SolarFlaresGuid.insert(l_Summon->GetGUID());
                            l_Pile->ToCreature()->DespawnOrUnsummon(500);
                            ++l_SolarFlaresFormed;
                        }
                    }

                    if (l_SolarFlaresFormed >= 3)
                        DoCompleteAchievement(uint32(Achievements::ISawSolis));

                    // We summon a new pile of ashes.
                    l_SolarFlareDying->CastSpell(l_SolarFlareDying, uint32(Spells::DORMANT), true);

                    Position l_Pos;
                    l_Pos = l_SolarFlareDying->GetPosition();
                    TempSummon* l_Sum = l_SolarFlareDying->SummonCreature(MobEntries::PILE_OF_ASHES, l_Pos);
                    l_Sum->SetFaction(16);
                    l_Sum->SetReactState(REACT_PASSIVE);
                    l_Sum->CastSpell(l_Sum, uint32(Spells::DORMANT), true);
                    l_SolarFlareDying->Kill(l_SolarFlareDying);

                    if (l_SolarFlareDying->ToCreature())
                        l_SolarFlareDying->ToCreature()->DespawnOrUnsummon(500);
                }
                break;
            case Data::PlayerIsHittedByRanjitSpells:
                if (!instance->IsHeroic())
                    break;
                ++m_ReadyForRaidingIVAchievements[p_Data];
                break;
            }
        }

        void OnPlayerEnter(Player* p_Player)
        {
            if (!p_Player->IsInWorld())
                return;

            InstanceScript::OnPlayerEnter(p_Player);

            m_ReadyForRaidingIVAchievements[p_Player->GetGUID()] = 0;
            m_PlayerGuidToBlockId[p_Player->GetGUID()] = 0;
        }

        void Update(uint32 p_Diff)
        {
            UpdateOperations(p_Diff);
            /*
            // We check here if a player is in the WindMaze zone.
            DoOnPlayers([this](Player* player)
            {
                // Is he in WindMaze zone ?
                if (IsPointInBlock(Blocks::ConvexHull, *player))
                {
                    bool l_IsInBlock = false;
                    uint32 i = Blocks::FirstStair;
                    for (; i <= Blocks::SecondStair; i++)
                    {
                        if (IsPointInBlock(i, *player))
                        {
                            l_IsInBlock = true;
                            break;
                        }
                    }

                    // If the player is in one of the blocks and if it doesn't have the Wind aura, add it.
                    if (l_IsInBlock)
                    {
                        float l_Magnitude = 1;
                        Position l_ForceDir = CalculateForceVectorFromBlockId(i, l_Magnitude);
                        if (!player->HasAura(RandomSpells::Wind))
                        {
                            player->AddAura(RandomSpells::Wind, player);
                            // Apply force.
                            player->ApplyMovementForce(m_WindMazeBlockGuids[i], l_Magnitude, l_ForceDir);
                        }
                        else if (i != m_PlayerGuidToBlockId[player->GetGUID()])
                        {
                            // Remove old force.
                            // Add new force.
                            if (player->HasMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]))
                                player->RemoveMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]);
                            player->ApplyMovementForce(m_WindMazeBlockGuids[i], l_Magnitude, l_ForceDir);
                        }

                        m_PlayerGuidToBlockId[player->GetGUID()] = i;
                    }
                    // Otherwise remove it if it has the Wind aura.
                    else if (player->HasAura(RandomSpells::Wind))
                    {
                        if (player->HasMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]))
                            player->RemoveMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]);
                        player->RemoveAura(RandomSpells::Wind);
                    }
                }
                // If player is out of the WindMaze zone and has the aura, remove it.
                else if (player->HasAura(RandomSpells::Wind))
                {
                    if (player->HasMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]))
                        player->RemoveMovementForce(m_WindMazeBlockGuids[m_PlayerGuidToBlockId[player->GetGUID()]]);
                    player->RemoveAura(RandomSpells::Wind);
                }
            });



            
            // Beam light intersection handler.
            if (m_SelectedSolarConstructorGuid != ObjectGuid::Empty)
            {
                if (instance)
                {
                    Map::PlayerList const &PlayerList = instance->GetPlayers();
                    if (PlayerList.isEmpty())
                        return;

                    Unit* l_Araknath = instance->GetCreature(m_AraknathGuid);
                    Unit* l_SelectedSolarConstructor = instance->GetCreature(m_SelectedSolarConstructorGuid);

                    if (!l_Araknath || !l_SelectedSolarConstructor)
                        return;

                    Player* l_ClosestPlayerInBeam = nullptr;
                    float l_ClosestDistance = std::numeric_limits<float>::max();

                    DoOnPlayers([this, l_Araknath, l_SelectedSolarConstructor, &l_ClosestDistance, &l_ClosestPlayerInBeam](Player* player)
                    {
                        if (DistanceFromLine(*l_Araknath, *l_SelectedSolarConstructor, *player) < 0.5f // If is in beam.
                            && dotProductXY(*l_Araknath - *l_SelectedSolarConstructor, *l_Araknath - *player) > 0 // If player is between solar constructor and araknath.
                            && l_ClosestDistance > l_SelectedSolarConstructor->GetDistance(player))
                        {
                            l_ClosestDistance = l_SelectedSolarConstructor->GetDistance(player);
                            l_ClosestPlayerInBeam = player;
                        }
                    });

                    Spell* l_CurrentSpell = l_SelectedSolarConstructor->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
                    if (l_ClosestPlayerInBeam
                        && l_CurrentSpell
                        && l_CurrentSpell->GetUnitTarget()
                        && l_CurrentSpell->GetUnitTarget()->ToPlayer() != l_ClosestPlayerInBeam)
                        l_SelectedSolarConstructor->CastSpell(l_ClosestPlayerInBeam, uint32(RandomSpells::ENERGIZE_DMG), false, nullptr, nullptr, m_AraknathGuid);
                    else if (!l_ClosestPlayerInBeam
                        && l_CurrentSpell
                        && l_CurrentSpell->GetUnitTarget()
                        && l_CurrentSpell->GetUnitTarget()->ToPlayer())
                        l_SelectedSolarConstructor->CastSpell(l_SelectedSolarConstructor, uint32(RandomSpells::ENERGIZE_HEAL));
                }
            }
            */
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* p_Map) const override
    {
        return new instance_skyreachInstanceMapScript(p_Map);
    }
};

void AddSC_instance_skyreach()
{
    new instance_skyreach();
}
