#include "iron_docks.hpp"
#include "GameObject.h"

class instance_iron_docks : public InstanceMapScript
{
    public:
        instance_iron_docks() : InstanceMapScript("instance_iron_docks", 1195) { }

        struct instance_iron_docks_InstanceMapScript : public InstanceScript
        {
            instance_iron_docks_InstanceMapScript(InstanceMap* p_Map) : InstanceScript(p_Map)  { }

            ObjectGuid m_MakoggGuid;
            ObjectGuid m_DuguruGuid;
            ObjectGuid m_NoxxGuid;
            ObjectGuid m_NokgarGuid;
            ObjectGuid m_WolfGuid;
            ObjectGuid m_OshirGuid;
            ObjectGuid m_SkullocGuid;
            ObjectGuid m_ZoggoshGuid;
            ObjectGuid m_KoramarGuid;
            ObjectGuid m_DarunaGuid;
            ObjectGuid m_GwarnokGuid;
            ObjectGuid m_OlugarGuid;
            ObjectGuid m_TurretGuid;
            /// Iron stars
            bool m_SecondEvent;
            bool m_ThirdEvent;
            /// Scenario handling
            uint32 m_CreatureKilled;
            /// Encounter Gates
            ObjectGuid m_EncounterGateOshirGuid;

            void Initialize() override
            {
                SetBossNumber(4);

                /// Bosses
                m_MakoggGuid = ObjectGuid::Empty;
                m_DuguruGuid = ObjectGuid::Empty;
                m_NoxxGuid = ObjectGuid::Empty;
                m_NokgarGuid = ObjectGuid::Empty;
                m_WolfGuid = ObjectGuid::Empty;
                m_OshirGuid = ObjectGuid::Empty;
                m_SkullocGuid = ObjectGuid::Empty;
                /// Mini bosses
                m_DarunaGuid = ObjectGuid::Empty;
                m_GwarnokGuid = ObjectGuid::Empty;
                m_OlugarGuid = ObjectGuid::Empty;
                // Triggers
                // Gobs
                // Creatures
                m_TurretGuid = ObjectGuid::Empty;
                m_ZoggoshGuid = ObjectGuid::Empty;
                m_KoramarGuid = ObjectGuid::Empty;
                m_SecondEvent = false;
                m_ThirdEvent = false;
                m_CreatureKilled = 0;
                /// Encounter Gates
                m_EncounterGateOshirGuid = ObjectGuid::Empty;
            }

            void OnCreatureCreate(Creature* p_Creature) override
            {
                switch (p_Creature->GetEntry())
                {
                case eIronDocksCreatures::CreatureFleshrenderNokgar:
                        m_NokgarGuid = p_Creature->GetGUID();
                        break;
                case eIronDocksCreatures::CreatureOshir:
                        m_OshirGuid = p_Creature->GetGUID();
                        break;
                case eIronDocksCreatures::CreatureSkulloc:
                        m_SkullocGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureNox:
                        m_NoxxGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureMakogg:
                        m_MakoggGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureDuguru:
                        m_DuguruGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureDreadfang:
                        m_WolfGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureZoggosh:
                        m_ZoggoshGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureKoramar:
                        m_KoramarGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureChampionDruna:
                        m_DarunaGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreaturePitwardenGwarnok:
                        m_GwarnokGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureSiegemasterOlugar:
                        m_OlugarGuid = p_Creature->GetGUID();
                        break;
                    case eIronDocksCreatures::CreatureTurret:
                        m_TurretGuid = p_Creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* p_GameObject) override
            {
                switch (p_GameObject->GetEntry())
                {
                    case eIronDocksGameObject::GameObjectChallengeModeDoor:
                        //AddChallengeModeDoor(p_GameObject);
                        break;
                    case eIronDocksGameObject::GameObjectEncounterGateOshir:
                        m_EncounterGateOshirGuid = p_GameObject->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* p_Unit) override
            {
                Creature* l_Creature = p_Unit->ToCreature();
                if (!l_Creature)
                    return;

                switch (l_Creature->GetEntry())
                {
                    case eIronDocksCreatures::CreatureFleshrenderNokgar:
                    {
                        if (Creature* l_Daruna = instance->GetCreature(GetGuidData(eIronDocksDatas::DataDaruna)))
                        {
                            if (Creature* l_Olugar = instance->GetCreature(GetGuidData(eIronDocksDatas::DataOlugar)))
                            {
                                if (Creature* l_Gwarnok = instance->GetCreature(GetGuidData(eIronDocksDatas::DataGwarnok)))
                                {
                                    if (l_Gwarnok->IsAlive() && l_Olugar->IsAlive() && l_Daruna->IsAlive())
                                        DoCompleteAchievement(eIronDocksAchievements::AchievementMilitaristicExpansionist);
                                }
                            }
                        }

                        break;
                    }
                    case eIronDocksCreatures::CreatureSkulloc:
                    {
                        if (l_Creature->GetMap()->IsHeroic())
                            DoCompleteAchievement(eIronDocksAchievements::AchievementHeroicIronDocks);
                        else
                            DoCompleteAchievement(eIronDocksAchievements::AchievementNormalIronDocks);
                        break;
                    }
                    default:
                        break;
                }
            }

            void OnCreatureKilled(Creature* p_Creature, Player* p_Player)
            {
               // if (!instance->IsChallengeMode() || !IsChallengeModeStarted() || m_CreatureKilled >= eIronDocksScenario::IronDocksKillCount)
                //    return;

                if (p_Creature == nullptr)
                    return;

                if (!p_Creature->isElite() || p_Creature->IsDungeonBoss())
                    return;

                ++m_CreatureKilled;
              //  SendScenarioProgressUpdate(CriteriaProgressData(eIronDocksScenario::IronDocksEnnemies, m_CreatureKilled, m_InstanceGuid, time(nullptr), m_BeginningTime, 0));

              //  if (m_CreatureKilled >= eIronDocksScenario::IronDocksKillCount)
                 //   m_ConditionCompleted = true;
            }

            ObjectGuid GetGuidData(uint32 p_Type) const override
            {
                switch (p_Type)
                {
                    /// Bosses
                    case eIronDocksDatas::DataNokgar:
                        return m_NokgarGuid;
                        break;
                    case eIronDocksDatas::DataOshir:
                        return m_OshirGuid;
                        break;
                    case eIronDocksDatas::DataSkulloc:
                        return m_SkullocGuid;
                        break;
                    case eIronDocksDatas::DataGrimrailDuguru:
                        return m_DuguruGuid;
                        break;
                    case eIronDocksDatas::DataGrimrailMakogg:
                        return m_MakoggGuid;
                        break;
                    case eIronDocksDatas::DataGrimrailNoxx:
                        return m_NoxxGuid;
                        break;
                    case eIronDocksDatas::DataMountWolf:
                        return m_WolfGuid;
                        break;
                    case eIronDocksDatas::DataTurret:
                        return m_TurretGuid;
                        break;
                    // Mini Bosses
                    case eIronDocksDatas::DataDaruna:
                        return m_DarunaGuid;
                        break;
                    case eIronDocksDatas::DataGwarnok:
                        return m_GwarnokGuid;
                        break;
                    case eIronDocksDatas::DataOlugar:
                        return m_OlugarGuid;
                        break;
                    /// RP
                    case eIronDocksDatas::DataZuggosh:
                        return m_ZoggoshGuid;
                        break;
                    case eIronDocksDatas::DataKoramar:
                        return m_KoramarGuid;
                        break;
                    /// Encounter Gates
                    case eIronDocksDatas::DataEncounterGateOshir:
                        return m_EncounterGateOshirGuid;
                        break;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case eIronDocksDatas::DataSkulloc:
                    {
                        if (state == EncounterState::DONE)                            
                            DoKilledMonsterCredit(eIronDocksScenario::DailyChallengeQuestID, eIronDocksScenario::DailyChallengeKillCredit);

                        break;
                    }
                    default:
                        break;
                }

                return true;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* p_Map) const override
        {
            return new instance_iron_docks_InstanceMapScript(p_Map);
        }
};

void AddSC_instance_iron_docks()
{
    new instance_iron_docks();
}
