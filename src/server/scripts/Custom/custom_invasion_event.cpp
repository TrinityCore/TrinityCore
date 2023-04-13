//#include "OutdoorPvP.h"
//#include "OutdoorPvPMgr.h"
//#include "ScenarioMgr.h"
//#include "PetBattle.h"
//
//// 107249 small vignette
//
//// Vignettes
////1272	Ïîðòàë
////1273	Áîëüøîé ïîðòàë
////1274	Ñòðîåíèå Ëåãèîíà
//// 1287	Ëàãåðü Ëåãèîíà ??
//std::vector<uint32> lowNps
//{
//    104476,
//    104465,
//    104281,
//    104286,
//    92113, // fly
//    104426,
//    104474,
//    104282,
//    104467,
//    104489,
//    104450,
//    104423,
//    104421,
//    104418,
//    105569, // + crystal 96985
//    104425,
//    104285,
//};
//
//std::vector<uint32> middleNps
//{
//    104432,
//    104875,
//    104283,
//
//    105900,
//    105901,
//    105999,
//    108126,
//};
//
//std::vector<uint32> highNps
//{
//    105954,
//    94357,
//    94226,
//    107198,
//};
//
//std::vector<uint32> bosses
//{
//    107115
//};
//
//std::vector<uint32> go
//{
//    243448, // small    114259  sum 227391    dest  227788
//    241610, // middle+  109761  sum 207688    destr 218496
//};
//
//std::vector<std::pair<uint32, Position>> g_startedNPCs
//{
//    { 104842 , {-825.50f, 4254.05f, 857.38f, 1.50f} },
//    { 104842 , {-1011.34f, 4513.21f, 857.38f, 5.09f} },
//    { 104842 , {-643.05f, 4465.06f, 857.38f, 3.03f} },
//    { 950116, {-857.10f, 4572.40f, 733.82f, 4.67f}},
//};
//
//std::vector<Position> g_firstStepSummonsPosition
//{
//    { -849.74f, 4272.29f, 745.133f },
//    //{ -846.346f, 4265.58f, 746.272f },
//    { -814.334f, 4278.38f, 746.279f },
//    //{ -828.288f, 4289.49f, 746.27f },
//     { -835.27f, 4315.17f, 744.881f },
//     //{ -846.723f, 4394.19f, 737.653f },
//     { -873.506f, 4404.24f, 738.107f },
//     { -873.081f, 4426.89f, 738.414f },
//     { -894.844f, 4419.58f, 736.951f },
//     { -916.328f, 4454.45f, 735.047f },
//     { -940.503f, 4454.21f, 733.758f },
//     { -957.607f, 4467.61f, 734.165f },
//     { -949.275f, 4491.32f, 733.46f },
//     { -924.102f, 4478.49f, 733.913f },
//     { -907.797f, 4489.6f, 732.046f },
//     { -884.778f, 4500.34f, 730.341f },
//     { -877.921f, 4526.43f, 729.44f },
//     //{ -860.651f, 4543.89f, 728.33f },
//     { -835.612f, 4553.13f, 728.555f },
//     { -822.956f, 4538.94f, 728.621f },
//     { -808.217f, 4527.09f, 729.395f },
//     { -811.229f, 4507.81f, 730.909f },
//     { -785.395f, 4510.84f, 730.759f },
//     { -772.516f, 4486.8f, 732.507f },
//     { -759.142f, 4487.11f, 732.429f },
//     { -727.474f, 4460.4f, 732.989f },
//     { -745.427f, 4464.49f, 733.374f },
//     { -771.232f, 4465.53f, 734.295f },
//     { -778.047f, 4446.28f, 737.233f },
//     { -799.904f, 4444.21f, 737.773f },
//     { -799.229f, 4426.23f, 738.401f },
//     { -819.639f, 4412.17f, 737.714f },
//     { -820.099f, 4394.09f, 738.758f },
//};
//
//std::vector<std::pair<uint32, Position>> g_thirdNPCs
//{
//    { 109761,{ -951.678f, 4489.05f, 733.683f, 2.70005f } },
//    { 109761,{ -835.45f, 4277.18f, 747.933f, 4.15096f } },
//    { 114259,{ -681.061f, 4491.7f, 728.876f, 0.561419f } },
//    { 114259,{ -757.937f, 4511.77f, 730.109f, 0.76405f } },
//    { 114259,{ -827.407f, 4569.37f, 728.67f, 1.02323f } },
//    { 114259,{ -922.617f, 4371.83f, 740.297f, 4.02345f } },
//
//    { 114259,{ -886.996f, 4540.06f, 729.29f, 2.50677f } },
//    { 114259,{ -734.566f, 4455.58f, 733.476f, 5.57451f } },
//    { 114259,{ -946.806f, 4441.15f, 734.163f, 4.021f } },
//    { 114259,{ -795.448f, 4424.73f, 738.448f, 5.70568f } },
//};
//
//std::vector<Position> m_smallShipsPath // 737
//{
//    {-853.55f, 4556.45f, 752.34f, 0.0f},
//    {-772.70f, 4491.85f, 748.83f, 0.0f},
//    {-839.11f, 4391.07f, 760.86f, 0.0f},
//    {-927.33f, 4463.47f, 758.90f, 0.0f}
//};
//
//enum Spells
//{
//    SPELL_SUMMON_NPC = 216240,
//    SPELL_LEGION_SKY = 232407,
//    SPELL_KNOCK_BACK = 212437,
//    SPELL_ARRILERRY = 207541, // 252512
//
//    SPELL_GO_KNOCK_BACK = 223801,
//};
//
//class OutdoorPVPdalaran_invasion : public OutdoorPvP
//{
//public:
//    OutdoorPVPdalaran_invasion()
//    {
//        m_TypeId = OUTDOOR_PVP_DALARAN_EVENT;
//    }
//
//    ~OutdoorPVPdalaran_invasion()
//    {
//        delete m_scenario;
//    }
//
//    bool SetupOutdoorPvP() override
//    {
//        RegisterZone(7502);
//        return true;
//    }
//
//    void HandlePlayerEnterZone(ObjectGuid guid, uint32 zone) override
//    {
//        OutdoorPvP::HandlePlayerEnterZone(guid, zone);
//
//        Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
//        if (!player)
//            return;
//
//        if (m_scenario)
//        {
//            m_scenario->SendStepUpdate(player, true);
//            player->AddDelayedEvent(500, [player]() -> void
//                {
//                    player->GetPhaseMgr().SetCustomPhase(120);
//                });
//
//            player->CastSpell(player, SPELL_LEGION_SKY, true);
//        }
//    }
//
//    void HandlePlayerLeaveZone(ObjectGuid guid, uint32 zone) override
//    {
//        Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
//
//        if (player) // not leave really, it's only in GO
//            if (player->GetMapId() == 1220 && player->GetDistance2d(-846.85f, 4469.60f) <= 200.0f && player->GetPositionZ() >= 650.0f)
//                // if (!m_map->IsOutdoors(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()))
//                return;
//
//        OutdoorPvP::HandlePlayerLeaveZone(guid, zone);
//
//        if (!player)
//            return;
//
//        RemoveScenarioForPlayer(player);
//    }
//
//    void HandleKill(Unit* killer, Unit* killed) override
//    {
//        if (!killed->IsCreature() || !m_scenario)
//            return;
//
//        if (std::find(m_creatures.begin(), m_creatures.end(), killed->GetGUID()) == m_creatures.end())
//            return;
//
//        if (!killer->IsPlayer()) // Find Player
//            killer = GetFirstPlayer();
//
//        if (killer)
//            DoUpdateCriterias(killer->ToPlayer(), killed);
//
//        m_creatures.remove(killed->GetGUID());
//
//        if (killed->GetCustomData())
//        {
//            switch (m_scenario->GetCurrentStep())
//            {
//            case 0:
//                DieActionDefault(killed->GetCustomData() - 1);
//                break;
//            case 2:
//                if (killed->GetEntry() == 109761 || killed->GetEntry() == 114259)
//                {
//                    DoThirdStepSummons();
//                    m_thirdStepGOs.erase(killed->GetCustomData() - 1);
//                    return; // don't need Despawn call
//                }
//                else
//                    DieActionDefault(killed->GetCustomData() - 1);
//                break;
//            }
//        }
//
//        killed->ToCreature()->DespawnOrUnsummon(1000);
//    }
//
//    void SetData(uint32 zone, uint32 step) override
//    {
//        switch (step)
//        {
//        case 0:
//            SummonNPCsByVector(g_startedNPCs);
//
//            m_currentVector = g_firstStepSummonsPosition;
//            m_processor.AddDelayedEvent(29000, [this]() -> void
//                {
//                    SummonShips();
//                    SummonNPCsByVectorWithRandom(true);
//                });
//            break;
//        case 1:
//            Trinity::Containers::RandomResizeList(m_currentVector, m_currentVector.size() / 4);
//            m_eventTimer = 23000;
//            m_needEvent = true;
//            if (auto creature = m_map->SummonCreature(middleNps[urand(0, middleNps.size() - 1)], m_currentVector[urand(0, m_currentVector.size())]))
//                JustSummonedActions(creature);
//            break;
//        case 2:
//            DoThirdStepSummons();
//            m_eventTimer = 13000;
//            m_needEvent = true;
//            break;
//        case 3:
//            m_needEvent = false;
//            if (auto creature = m_map->SummonCreature(bosses[urand(0, bosses.size() - 1)], m_currentVector[urand(0, m_currentVector.size())]))
//                JustSummonedActions(creature);
//            break;
//        case 100:
//            m_processor.KillAllFunctions();
//            m_needEvent = false;
//            m_endTimer = 5000;
//            ApplyOnEveryPlayerInZone([](Player* player) -> void
//                {
//                    if (player->HasItemCount(136924))
//                        return;
//
//                    auto pet = sDB2Manager.GetSpeciesBySpell(210699);
//                    for (const auto& pair : *player->GetBattlePets())
//                        if (pair.second->Species == pet->ID)
//                            return;
//
//                    player->AddItem(136924, 1);
//                });
//            break;
//        }
//    }
//
//    void HandleGameEventStart(uint32 eventId) override
//    {
//        if (eventId != 192)
//            return;
//
//        m_endTimer = 30 * MINUTE * IN_MILLISECONDS + 100;
//        m_scenario = new Scenario(m_map, 1);
//        m_scenario->SetOutdoorPvP(this, 7502);
//
//        ApplyOnEveryPlayerInZone([this](Player* player) -> void
//            {
//                HandlePlayerEnterZone(player->GetGUID(), 7502);
//            });
//
//        SetData(0, 0);
//        m_secondStepState = 0;
//        m_artilleryTimer = 40000;
//    }
//
//    void SetGuidData(uint32 type, ObjectGuid guid) override
//    {
//        if (type == 0)
//        {
//            if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
//                JustSummonedActions(cre);
//            else
//                m_creatures.push_back(guid);
//        }
//        else if (type == 1)
//            m_objects.push_back(guid);
//    }
//
//    bool Update(uint32 diff) override
//    {
//        m_processor.Update(diff);
//
//        if (!m_scenario)
//            return true;
//
//        DoArtillery(diff);
//        DoEndTimer(diff);
//        DoEventTimer(diff);
//
//        return true;
//    }
//
//private:
//    void RemoveScenarioForPlayer(Player* player)
//    {
//        if (m_scenario)
//            m_scenario->SendFinishPacket(player);
//
//        if (player->GetPhaseMask() == 120)
//            player->AddDelayedEvent(500, [player]() -> void
//                {
//                    player->GetPhaseMgr().SetCustomPhase(1);
//                });
//
//        player->RemoveAurasDueToSpell(SPELL_LEGION_SKY);
//    }
//
//    void SummonNPCsByVector(std::vector<std::pair<uint32, Position>>& npcs)
//    {
//        uint8 i = 0;
//        for (auto& pair : npcs)
//            if (auto creature = m_map->SummonCreature(pair.first, pair.second))
//            {
//                creature->SetPhaseMask(120, true);
//                m_creatures_first.push_back(creature->GetGUID());
//                creature->setActive(true);
//                creature->SetRespawnTime(1);
//
//                if (pair.first == 950116) // khadgar
//                    DoKhadgarEvents(creature);
//            }
//    }
//
//    void SummonShips()
//    {
//        for (uint8 i = 0; i < 11; ++i)
//        {
//            uint8 j = urand(0, m_smallShipsPath.size() - 1);
//            if (auto ship = m_map->SummonCreature(950120, m_smallShipsPath[j]))
//            {
//                ship->SetPhaseMask(120, true);
//                ship->setActive(true);
//                m_creatures_first.push_back(ship->GetGUID());
//                ship->AI()->DoAction(j);
//            }
//        }
//    }
//
//    void SummonNPCsByVectorWithRandom(bool addData = false)
//    {
//        for (uint16 i = 0; i < m_currentVector.size(); ++i)
//        {
//            if ((!addData || m_scenario->GetCurrentStep() >= 1) && urand(0, 1) == 1)
//                continue;
//
//            m_map->LoadGrid(m_currentVector[i]);
//            for (uint16 j = ((urand(1, 100) > 70) ? 0 : 1); j < 2; ++j)
//            {
//                m_processor.AddDelayedEvent(100 + i * 400, [this, i, addData]() -> void
//                    {
//                        Position pos = m_currentVector[i];
//                        pos.m_positionX += frand(-5.0f, 5.0f);
//                        pos.m_positionY += frand(-5.0f, 5.0f);
//
//                        if (auto creature = m_map->SummonCreature(GenerateEntry(), pos))
//                        {
//                            if (addData)
//                                creature->SetCustomData(i + 1);
//                            JustSummonedActions(creature);
//                        }
//                    });
//            }
//        }
//    }
//
//    uint32 GenerateEntry() const
//    {
//        uint32 rand = urand(1, 100);
//        if (rand < 96 || m_scenario->GetCurrentStep() <= 1)
//            return lowNps[urand(0, lowNps.size() - 1)];
//        else if (rand < 99 || m_scenario->GetCurrentStep() <= 1)
//            return middleNps[urand(0, middleNps.size() - 1)];
//        else
//            return highNps[urand(0, highNps.size() - 1)];
//    }
//
//    void DieActionDefault(uint8 data)
//    {
//        for (uint8 i = ((urand(0, 10) > 8) ? 0 : 1); i < 2; ++i)
//        {
//            m_processor.AddDelayedEvent(urand(5000, 10000), [data, this, i]() -> void
//                {
//                    Position pos = g_firstStepSummonsPosition[data];
//                    pos.m_positionX += frand(-3.0f, 3.0f);
//                    pos.m_positionY += frand(-3.0f, 3.0f);
//
//                    m_map->LoadGrid(pos);
//
//                    if (auto creature = m_map->SummonCreature(GenerateEntry(), pos))
//                    {
//                        if (i == 1)
//                            creature->SetCustomData(data + 1);
//                        JustSummonedActions(creature);
//                    }
//                });
//        }
//    }
//
//    void JustSummonedActions(Creature* creature)
//    {
//        creature->SetPvP(false);
//        creature->SetPhaseMask(120, true);
//        m_creatures.push_back(creature->GetGUID());
//
//        if (!m_scenario)
//            return;
//
//        creature->setActive(true);
//        creature->SetReactState(REACT_AGGRESSIVE);
//        creature->CastSpell(creature, SPELL_SUMMON_NPC, true);
//
//        if (m_scenario->GetCurrentStep() != 0)
//            return;
//
//        creature->GetMotionMaster()->MoveIdle();
//        creature->AddDelayedEvent(2900, [creature]() -> void
//            {
//                creature->GetMotionMaster()->MovePath(145541501, false);
//            });
//    }
//
//    void DoKhadgarEvents(Creature* khadgar)
//    {
//        std::list<Creature*> tempCreatures{};
//
//        m_map->LoadGrid(-861.04f, 4546.27f);
//
//        for (uint8 i = 0; i < 23; ++i)
//        {
//            if (Creature* creature = m_map->SummonCreature(950117, { -861.04f + frand(-9.0f, 9.0f), 4546.27f + frand(-9.0f, 9.0f), 728.19f, 1.43f }))
//            {
//                creature->SetPhaseMask(120, true);
//                m_creatures_first.push_back(creature->GetGUID());
//                creature->setActive(true);
//                tempCreatures.push_back(creature);
//            }
//        }
//        std::list<Creature*> tempCreatures_1 = tempCreatures;
//        Trinity::Containers::RandomResizeList(tempCreatures_1, 4);
//
//        khadgar->AddDelayedEvent(2000, [khadgar]() -> void
//            {
//                khadgar->AI()->ZoneTalk(1);
//            });
//
//        uint8 i = 0;
//        for (auto creature : tempCreatures_1)
//        {
//            creature->AddDelayedEvent(12100 + 100 * i, [creature, i]() -> void
//                {
//                    creature->AI()->ZoneTalk(i);
//                });
//
//            ++i;
//        }
//
//        khadgar->AddDelayedEvent(16500, [khadgar]() -> void
//            {
//                khadgar->AI()->ZoneTalk(2);
//            });
//
//        for (auto creature : tempCreatures)
//        {
//            creature->AddDelayedEvent(19100, [creature]() -> void
//                {
//                    creature->GetMotionMaster()->MovePath(145541501, false, frand(-5.0f, 5.0f), frand(-5.0f, 5.0f));
//                });
//        }
//
//        khadgar->AddDelayedEvent(27000, [khadgar, this]() -> void
//            {
//                if (auto go = m_map->SummonGameObject(276297, -848.25f, 4653.28f, 732.946f, 0.0f, 0, 0, 0, 0, RESPAWN_ONE_DAY))
//                {
//                    go->SetPhaseMask(120, true);
//                    m_objects.push_back(go->GetGUID());
//                }
//                khadgar->AI()->ZoneTalk(3);
//            });
//
//        khadgar->AddDelayedEvent(29000, [khadgar, this]() -> void
//            {
//                if (Creature* arhim = m_map->SummonCreature(950119, g_firstStepSummonsPosition[0]))
//                {
//                    arhim->setActive(true);
//                    arhim->AI()->ZoneTalk(0);
//                    arhim->DespawnOrUnsummon(5000);
//                }
//            });
//
//        khadgar->AddDelayedEvent(40000, [khadgar, this]() -> void
//            {
//                khadgar->AI()->ZoneTalk(4);
//            });
//
//    }
//
//    void DoArtillery(uint32 diff)
//    {
//        if (m_artilleryTimer <= diff)
//        {
//            m_artilleryTimer = urand(10000, 20000);
//            if (Creature* artillery = m_map->GetCreature(m_creatures_first[urand(0, 2)]))
//            {
//                uint32 timer = 100;
//                for (uint8 team = TEAM_ALLIANCE; team < MAX_TEAMS; ++team)
//                    for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
//                        if (Player* player = ObjectAccessor::GetObjectInMap(*itr, m_map, (Player*)nullptr))
//                            if (urand(1, 2) == 1)
//                            {
//                                artillery->CastSpellDelay(player, SPELL_ARRILERRY, false, timer);
//                                timer += 100;
//                            }
//
//                for (const auto& pos : g_firstStepSummonsPosition)
//                    if (urand(1, 2) == 1)
//                    {
//                        artillery->CastSpellDelay(pos, SPELL_ARRILERRY, false, timer);
//                        timer += 100;
//                    }
//            }
//        }
//        else
//            m_artilleryTimer -= diff;
//    }
//
//    void DoEndTimer(uint32 diff)
//    {
//        if (m_endTimer <= diff)
//        {
//            m_processor.KillAllFunctions();
//            sGameEventMgr->StopEvent(192, true); // stop, if don't stop
//
//            ApplyOnEveryPlayerInZone([this](Player* player) -> void
//                {
//                    RemoveScenarioForPlayer(player);
//                });
//
//            for (auto& guid : m_creatures)
//                if (auto creature = m_map->GetCreature(guid))
//                    creature->DespawnOrUnsummon();
//
//            for (auto& guid : m_creatures_first)
//                if (auto creature = m_map->GetCreature(guid))
//                    creature->DespawnOrUnsummon();
//
//            for (auto& guid : m_objects)
//                if (auto go = m_map->GetGameObject(guid))
//                {
//                    go->SetRespawnTime(0);
//                    go->Delete();
//                }
//
//            m_creatures.clear();
//            m_creatures_first.clear();
//            m_objects.clear();
//            m_secondStepState = 0;
//
//            delete m_scenario;
//            m_scenario = nullptr;
//        }
//        else
//            m_endTimer -= diff;
//    }
//
//    void DoEventTimer(uint32 diff)
//    {
//        if (!m_needEvent)
//            return;
//
//        if (m_eventTimer <= diff)
//        {
//            SummonNPCsByVectorWithRandom(m_creatures.empty());
//            m_eventTimer = urand(120, 240) * 1000;
//        }
//        else
//            m_eventTimer -= diff;
//    }
//
//    void DoUpdateCriterias(Player* player, Unit* killed)
//    {
//        switch (m_scenario->GetCurrentStep())
//        {
//        case 0:
//            m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46005, 1, 0, nullptr, player);
//            break;
//        case 1:
//        {
//            bool needSummon = false;
//            if (std::find(middleNps.begin(), middleNps.end(), killed->GetEntry()) != middleNps.end())
//            {
//                m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51810, 1, 0, nullptr, player);
//                needSummon = true;
//            }
//            else if (std::find(highNps.begin(), highNps.end(), killed->GetEntry()) != highNps.end())
//            {
//                m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51823, 1, 0, nullptr, player);
//                needSummon = true;
//            }
//
//            if (needSummon)
//            {
//                uint32 entry = 0;
//                switch (++m_secondStepState)
//                {
//                case 1:
//                    entry = middleNps[urand(0, middleNps.size() - 1)];
//                    break;
//                case 2:
//                    entry = highNps[urand(0, highNps.size() - 1)];
//                    break;
//                }
//                if (entry)
//                    if (auto creature = m_map->SummonCreature(entry, m_currentVector[urand(0, m_currentVector.size())]))
//                        JustSummonedActions(creature);
//            }
//            break;
//        }
//        case 2:
//            if (killed->GetEntry() == 109761 || killed->GetEntry() == 114259)
//            {
//                for (uint8 i = urand(0, 2); i < 4; ++i)
//                    m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50991, 1, 0, nullptr, player);
//                m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46005, 1, 0, nullptr, player);
//            }
//            else
//                m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50990, 1, 0, nullptr, player);
//            break;
//        case 3:
//            if (std::find(bosses.begin(), bosses.end(), killed->GetEntry()) != bosses.end())
//                m_scenario->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52035, 1, 0, nullptr, player);
//            break;
//        }
//    }
//
//    void DoThirdStepSummons()
//    {
//        if (m_thirdStepGOs.size() >= 3)
//            return;
//
//        std::list<uint8> canPositions{ 0, 1, 2, 3, 4, 5 };
//        for (auto id : m_thirdStepGOs)
//            canPositions.remove(id);
//
//        if (canPositions.empty())
//            return;
//
//        Trinity::Containers::RandomResizeList(canPositions, 3 - m_thirdStepGOs.size() + (m_thirdStepGOs.empty() ? 0 : 1));
//        for (auto id : canPositions)
//        {
//            if (auto trigger = m_map->SummonCreature(g_thirdNPCs[id].first, g_thirdNPCs[id].second))
//            {
//                trigger->SetCustomData(id + 1);
//                trigger->setActive(true);
//                trigger->SetPhaseMask(120, true);
//                m_creatures.push_back(trigger->GetGUID());
//                m_thirdStepGOs.insert(id);
//            }
//        }
//    }
//
//    Scenario* m_scenario{};
//    uint32 m_endTimer{};
//    std::vector<ObjectGuid> m_creatures_first{};
//    std::list<ObjectGuid> m_creatures{};
//    std::list<ObjectGuid> m_objects{};
//    std::vector<Position> m_currentVector{};
//    std::set<uint8> m_thirdStepGOs{};
//
//    FunctionProcessor m_processor{};
//
//    bool m_needEvent = false;
//    uint32 m_eventTimer{};
//    uint8 m_secondStepState = 0;
//    uint32 m_artilleryTimer = 0;
//};
//
//class OutdoorPvP_dalaran_invasion : public OutdoorPvPScript
//{
//public:
//    OutdoorPvP_dalaran_invasion() : OutdoorPvPScript("outdoorpvp_dalaran_invasion") {}
//
//    OutdoorPvP* GetOutdoorPvP() const override
//    {
//        return new OutdoorPVPdalaran_invasion();
//    }
//};
//
//// 109761, 114259
//struct npc_invasion_event_gobs_triggers : public ScriptedAI
//{
//    npc_invasion_event_gobs_triggers(Creature* creature) : ScriptedAI(creature) {}
//
//    uint32 spellSum{}, spellDesp{}, goEntry{};
//    ObjectGuid go{};
//
//    void InitializeAI() override
//    {
//        me->setActive(true);
//
//        switch (me->GetEntry())
//        {
//        case 109761:
//            spellSum = 207688;
//            spellDesp = 218496;
//            goEntry = 241610;
//            break;
//        case 114259: // small
//            spellSum = 227295;
//            spellDesp = 227775;
//            goEntry = 243448;
//            break;
//        }
//
//        me->AddDelayedEvent(1000, [this]() -> void
//            {
//                me->CastSpell(me, spellSum);
//                me->AddDelayedEvent(9000, [this]
//                    {
//                        auto outdoor = me->GetOutdoorPvP();
//                        if (!outdoor)
//                            return;
//
//                        if (auto gob = me->SummonGameObject(goEntry, me->GetPosition(), me->GetOrientation(), 0, 0, 0, 0, 30 * 60))
//                        {
//                            gob->setActive(true);
//                            gob->SetPhaseMask(120, true);
//                            outdoor->SetGuidData(1, gob->GetGUID());
//                            go = gob->GetGUID();
//                        }
//
//                        if (auto crystal = me->SummonCreature(98371, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 3.0f, 0, TEMPSUMMON_TIMED_DESPAWN, 30 * 60 * 1000))
//                        {
//                            outdoor->SetGuidData(0, crystal->GetGUID());
//                            crystal->SetReactState(REACT_PASSIVE);
//                            crystal->SetCustomData(me->GetCustomData());
//                        }
//
//                        float diff = isSmall() ? 0 : 4;
//                        for (uint8 i = 0; i < (isSmall() ? 1 : 3); ++i)
//                            if (auto creature = me->SummonCreature(lowNps[urand(0, lowNps.size() - 1)], me->GetPositionX() + frand(-diff, diff), me->GetPositionY() + frand(-diff, diff), me->GetPositionZ() + 3.0f))
//                                outdoor->SetGuidData(0, creature->GetGUID());
//                    });
//            });
//    }
//
//    void SummonedCreatureDies(Creature* creature, Unit* killer) override
//    {
//        if (creature->GetEntry() == 98371)
//        {
//            creature->DespawnOrUnsummon(1);
//            if (auto gob = me->GetMap()->GetGameObject(go))
//            {
//                gob->SetRespawnTime(0);
//                gob->Delete();
//            }
//
//            if (auto outdoor = me->GetOutdoorPvP())
//                outdoor->HandleKill(killer, me);
//
//            me->CastSpell(me, spellDesp);
//            me->DespawnOrUnsummon(10000);
//        }
//        else if (auto outdoor = me->GetOutdoorPvP())
//            outdoor->HandleKill(killer, creature);
//
//    }
//
//    bool isSmall() const
//    {
//        return me->GetEntry() == 114259;
//    }
//};
//
//// 950120
//struct npc_invasion_event_fly_ships : public ScriptedAI
//{
//    npc_invasion_event_fly_ships(Creature* creature) : ScriptedAI(creature) {}
//
//    std::vector<Position> m_path{};
//    uint32 timer{};
//
//    void DoAction(int32 const act) override
//    {
//        me->SetReactState(REACT_PASSIVE);
//        auto itr = m_smallShipsPath.begin();
//        std::advance(itr, act);
//        m_path.insert(m_path.end(), itr, m_smallShipsPath.end());
//        m_path.insert(m_path.end(), m_smallShipsPath.begin(), itr);
//
//        if (urand(1, 2) == 1)
//            std::reverse(m_path.begin(), m_path.end());
//
//        for (auto& pos : m_path)
//        {
//            pos.m_positionX += frand(-5.0f, 5.0f);
//            pos.m_positionY += frand(-5.0f, 5.0f);
//            pos.m_positionZ -= frand(0.0f, 10.0f);
//        }
//
//        me->GetMotionMaster()->MovePoint(1, m_path[0]);
//        timer = 5000;
//    }
//
//    void MovementInform(uint32 type, uint32 point) override
//    {
//        if (type != POINT_MOTION_TYPE)
//            return;
//
//        me->AddDelayedEvent(500, [this, point]()
//            {
//                me->GetMotionMaster()->MovePoint((point % 4) + 1, m_path[point % 4]);
//            });
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (timer <= diff)
//        {
//            me->CastSpell(me->GetPositionX() + frand(-8.0f, 8.0f), me->GetPositionY() + frand(-8.0f, 8.0f), me->GetWaterOrGroundLevel(me->GetPosition()), 249933);
//            timer = urand(1000, 1500);
//        }
//        else
//            timer -= diff;
//    }
//
//};
//
//
//
//void Addsc_dalaran_invasion()
//{
//    new OutdoorPvP_dalaran_invasion();
//    RegisterCreatureAI(npc_invasion_event_gobs_triggers);
//    RegisterCreatureAI(npc_invasion_event_fly_ships);
//}
