#include "antorus.h"
#include "GameObject.h"

#define MIN_X -4356.93f
#define MAX_X -3638.09f
#define MIN_Y -11006.65f
#define MAX_Y -10354.48f

DoorData const doorData[] =
{
    {GO_STONE,                     DATA_WORLDBREAKER,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_INVISIBLE_WALL,            DATA_WORLDBREAKER,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_ARCANE_BARRIER,            DATA_IMONAR,            DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_COMMAND_DOOR,              DATA_ANTORAN,           DOOR_TYPE_ROOM,         BOUNDARY_SE},
    {GO_KINGAROTH_DOOR,            DATA_KINGAROTH,         DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_HASABEL_DOOR,              DATA_HASABEL,           DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_EONAR_DOOR,                DATA_EONAR,             DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_VARIMATHRAS_DOOR_1,        DATA_VARIMATHRAS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_VARIMATHRAS_DOOR_2,        DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_COVEN_DOOR_1,              DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_COVEN_DOOR_2,              DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_COVEN_DOOR_1,              DATA_COVEN,             DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_COVEN_DOOR_2,              DATA_COVEN,             DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_AGGRAMAR_DOOR,             DATA_AGGRAMAR,          DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_AGGRAMAR_BRIDGE,           DATA_AGGRAMAR,          DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {0,                            0,                      DOOR_TYPE_ROOM,         BOUNDARY_NONE} // END
};

ObjectData const creatureData[] =
{
    {NPC_WORLDBREAKER,              NPC_WORLDBREAKER},
    {NPC_HASABEL,                   NPC_HASABEL},
    {NPC_IMONAR,                    NPC_IMONAR},
    {NPC_AZARA,                     NPC_AZARA},
    {NPC_KINGAROTH,                 NPC_KINGAROTH},
    {NPC_SHATUG,                    NPC_SHATUG},
    {NPC_FHARG,                     NPC_FHARG},
    {NPC_MOLTEN_TOUCH,              NPC_MOLTEN_TOUCH},
    {NPC_ADMIRAL_SVIRAX,            NPC_ADMIRAL_SVIRAX},
    {NPC_VARIMATHRAS,               NPC_VARIMATHRAS},
    {NPC_EONAR_EVENT,               NPC_EONAR_EVENT},
    {0,                             0} // END
};

ObjectData const gobjectData[] =
{
    {GO_ELEVATOR,                   GO_ELEVATOR},
    {GO_PORTAL_TO_ELUNARIES,        GO_PORTAL_TO_ELUNARIES},
    {GO_ARCANE_BARRIER_VISUAL,      GO_ARCANE_BARRIER_VISUAL},
    {GO_KINGAROTH_TRAP_LEFT_1,      GO_KINGAROTH_TRAP_LEFT_1},
    {GO_KINGAROTH_TRAP_LEFT_2,      GO_KINGAROTH_TRAP_LEFT_2},
    {GO_KINGAROTH_TRAP_RIGHT_1,     GO_KINGAROTH_TRAP_RIGHT_1},
    {GO_KINGAROTH_TRAP_RIGHT_2,     GO_KINGAROTH_TRAP_RIGHT_2},
    {GO_KINGAROTH_TRAP_BACK_1,      GO_KINGAROTH_TRAP_BACK_1},
    {GO_KINGAROTH_TRAP_BACK_2,      GO_KINGAROTH_TRAP_BACK_2},
    {GO_EONAR_PARAXIS_SHIP,         GO_EONAR_PARAXIS_SHIP},
    {GO_EONAR_PARAXIS_DOOR_1,       GO_EONAR_PARAXIS_DOOR_1},
    {GO_EONAR_PARAXIS_DOOR_2,       GO_EONAR_PARAXIS_DOOR_2},
    {GO_EONAR_PARAXIS_DOOR_3,       GO_EONAR_PARAXIS_DOOR_3},
    {GO_EONAR_CACHE,                GO_EONAR_CACHE},
    {0,                             0 } // END
};


Position const dreadWingsPos[2]
{
    { -3290.76f,	9519.75f,	22.1289f },
    { -3301.51f,	9595.35f,	36.3317f }
};

class instance_antorus : public InstanceMapScript
{
public:
    instance_antorus() : InstanceMapScript("instance_antorus", 1712) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_antorus_InstanceMapScript(map);
    }

    struct instance_antorus_InstanceMapScript : InstanceScript
    {
        explicit instance_antorus_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        uint32 timerIntroEvent{}, timerIntroEvent2{}, timerConstEvent{};
        uint32 checkSurgeLifeTimer{};
        uint32 playerFallCheckTimer{};
        WorldLocation loc_res_pla;
        std::list<ObjectGuid> introGuids{};
        std::list<ObjectGuid> cosmeticTormentList;
        std::vector<ObjectGuid> wireframesGuids{};
        std::vector<ObjectGuid> introFirstBossGuids{};
        std::vector<ObjectGuid> secondBossOutro{};
        std::unordered_set<ObjectGuid> mobsForBridge{};
        std::vector<ObjectGuid> mobsFromBridge{};
        std::unordered_set<ObjectGuid> mobsForElevator{};
        std::vector<ObjectGuid> mobsToSeondPath{};
        std::vector<ObjectGuid> mobsAfterKingaroth{};

        std::list<ObjectGuid> firstEventCounter{};
        std::list<ObjectGuid> secondEventCounter{};

        void Initialize() override
        {
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gobjectData);

            timerIntroEvent = urand(4000, 7000);
            timerIntroEvent2 = urand(3000, 6000);
            timerConstEvent = urand(3000, 7000);
            checkSurgeLifeTimer = 1000;
            playerFallCheckTimer = 1000;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_DREADWING:
                //creature->SetReactState(REACT_ATTACK_OFF);
                introGuids.push_back(creature->GetGUID());
                break;
            case NPC_LIGHTFORGED_WIREFRAME:
                if (creature->GetPositionZ() >= -10)
                {
                    wireframesGuids.push_back(creature->GetGUID());
                    creature->CastSpell(creature, SPELL_LIGHT_SHIELD);
                }
                break;
            case NPC_LIGHT_CENTURION:
            case NPC_LIGHT_COMANDIR:
            case NPC_LIGHT_PRIEST:
                if (creature->GetPositionY() >= 1610.0f)
                {
                   // creature->SetReactState(REACT_ATTACK_OFF);
                    //creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);

                    if (creature->GetDistance(-3285.94f, 10254.57f, -127.32f) <= 10)
                    {
                        if (creature->GetEntry() == NPC_LIGHT_CENTURION)
                            creature->CastSpell(creature, 64165);
                    }
                    else
                        creature->SetVisible(false);
                }
                break;
            case NPC_RUN_NPC_1:
            case NPC_RUN_NPC_2:
                //creature->SetReactState(REACT_ATTACK_OFF);
                creature->CastSpell(creature, 211762);
                break;
            case NPC_FEL_PORTAL_1:
            case NPC_FEL_PORTAL_2:
                //creature->SetReactState(REACT_ATTACK_OFF);
                creature->SetRegenerateHealth(false);
                break;
            case NPC_IMPLOSIONS:
                mobsAfterKingaroth.push_back(creature->GetGUID());
                break;
            case NPC_WIND_STALKER:
                //creature->SetReactState(REACT_ATTACK_OFF);
                creature->CastSpell(creature, 246198);
                creature->GetMotionMaster()->MoveRandom(7.0f);
                break;
            case NPC_COSMETIC_TORMENT:
                cosmeticTormentList.push_back(creature->GetGUID());
                break;
            default:
                break;
            }

            if (!creature->IsAlive())
                return;

            if (creature->GetFaction() == 35 || creature->GetFaction() == 2921 || creature->GetFaction() == 2916)
            {
                if (creature->GetDistance2d(-3296.24f, 9763.55f) <= 50 && GetBossState(DATA_WORLDBREAKER) != DONE) // frist
                {
                    introFirstBossGuids.push_back(creature->GetGUID());
                    creature->SetVisible(false);
                    //creature->SetReactState(REACT_ATTACK_OFF);
                }
                if (creature->GetDistance2d(-3293.42f, 10340.64f) <= 25.0f && GetBossState(DATA_FELHOUNDS) != DONE) // second boss
                {
                    secondBossOutro.push_back(creature->GetGUID());
                    creature->SetVisible(false);
                    //creature->SetReactState(REACT_ATTACK_OFF);
                }
                if (creature->GetDistance2d(-3186.41f, 10345.27f) <= 25.0f && GetBossState(DATA_ANTORAN) != DONE && GetBossState(DATA_FELHOUNDS) != DONE) // bridge TP
                {
                    mobsFromBridge.push_back(creature->GetGUID());
                    creature->SetVisible(false);
                    //creature->SetReactState(REACT_ATTACK_OFF);
                }
                if (creature->GetPositionZ() <= -133.0f && GetBossState(DATA_EONAR) != DONE)
                {
                    mobsToSeondPath.push_back(creature->GetGUID());
                    creature->SetVisible(false);
                    //creature->SetReactState(REACT_ATTACK_OFF);
                }
                if (creature->GetDistance(-10575.48f, 8211.12f, 1871.40f) <= 10.0f && GetBossState(DATA_KINGAROTH) != DONE)
                {
                    mobsAfterKingaroth.push_back(creature->GetGUID());
                    creature->SetVisible(false);
                    //creature->SetReactState(REACT_ATTACK_OFF);
                }
            }
            else if (creature->GetFaction() == 16)
            {
                if (creature->GetDistance2d(-3216.10f, 10302.62f) <= 15)
                    mobsForBridge.insert(creature->GetGUID());
                else if (creature->GetDistance(-2891.67f, 10768.20f, -90.77f) <= 10)
                    mobsForElevator.insert(creature->GetGUID());
            }
        }

        void OnCreatureRemove(Creature* creature) override
        {
            InstanceScript::OnCreatureRemove(creature);

            switch (creature->GetEntry())
            {
            case NPC_DREADWING:
                firstEventCounter.remove(creature->GetGUID());
                break;
            case NPC_RUN_NPC_1:
            case NPC_RUN_NPC_2:
                secondEventCounter.remove(creature->GetGUID());
                break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            if (mobsForBridge.find(unit->GetGUID()) != mobsForBridge.end())
            {
                mobsForBridge.erase(unit->GetGUID());
                if (mobsForBridge.empty())
                {
                    for (const auto& guid : mobsFromBridge)
                        if (Creature* cre = instance->GetCreature(guid))
                        {
                            cre->SetVisible(true);
                            cre->CastSpell(cre, SPELL_SPAWN);
                        }
                }
            }
            else if (mobsForElevator.find(unit->GetGUID()) != mobsForElevator.end())
            {
                mobsForElevator.erase(unit->GetGUID());
            }
            switch (unit->GetEntry())
            {
            case NPC_ANNIHILATOR_OF_KINGAROTH:
                for (const auto& guid : introFirstBossGuids)
                    if (Creature* cre = instance->GetCreature(guid))
                    {
                        cre->SetVisible(true);
                        cre->CastSpell(cre, SPELL_SPAWN);

                        if (cre->GetEntry() == NPC_EXARH_TURALION)
                        {
                            AddDelayedCombat(3000, [cre]() -> void
                            {
                                //cre->CreateConversation(5515);
                                AddDelayedEvent(3000, [cre]() -> void
                                {
                                    cre->GetMotionMaster()->MovePoint(0, -3299.39f, 9733.63f, -63.24f);
                                    AddDelayedEvent(2000, [cre]() -> void
                                    {
                                        cre->GetMotionMaster()->MoveTargetedHome();
                                        cre->SetVisible(false);
                                    });
                                });
                            });
                            continue;
                        }

                        if (cre->GetEntry() == NPC_LIGHTFORGED_WIREFRAME_1 || cre->GetEntry() == NPC_TELEPORT_OF_LIGHTFORGED_1)
                            continue;


                        cre->GetMotionMaster()->MovePoint(0, -3294.85f + frand(-5, 5), 9799.49f + frand(-5, 5), -63.49f);
                        AddDelayedCombat(7000, [cre]() -> void
                        {
                            cre->CastStop();
                            cre->Kill(cre,cre);
                            cre->DespawnOrUnsummon(500);
                        });
                    }
                break;
            case NPC_PRIESTESS_OF_DELIRIUM:
                if (unit->ToCreature()->GetHomePosition().GetPositionY() <= 2900.00f)
                {
                    unit->CastSpell(unit, 254650);
                }
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_ELEVATOR:
                break;
            case GO_PORTAL_TO_ELUNARIES:
                break;
            case GO_ARCANE_BARRIER_VISUAL:
                break;
            case GO_EONAR_PARAXIS_SHIP:
            case GO_EONAR_PARAXIS_DOOR_1:
            case GO_EONAR_PARAXIS_DOOR_2:
            case GO_EONAR_PARAXIS_DOOR_3:
                break;
            default:
                break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            InstanceScript::OnGameObjectRemove(go);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (!mobsToSeondPath.empty())
            {
                bool isDone = true;
                for (uint8 i = DATA_WORLDBREAKER; i <= DATA_EONAR; ++i)
                    if (GetBossState(i) != DONE)
                        isDone = false;

                if (isDone)
                {
                    for (auto& guid : mobsToSeondPath)
                        if (Creature* cre = instance->GetCreature(guid))
                            cre->SetVisible(true);

                    mobsToSeondPath.clear();
                }
            }

            switch (state)
            {
            case DONE:
            {
                switch (type)
                {
                case DATA_WORLDBREAKER:
                    for (const auto& guid : introFirstBossGuids)
                        if (Creature* cre = instance->GetCreature(guid))
                            if (cre->GetEntry() == NPC_LIGHTFORGED_WIREFRAME_1 || cre->GetEntry() == NPC_EXARH_TURALION || cre->GetEntry() == NPC_TELEPORT_OF_LIGHTFORGED_1)
                            {
                                cre->SetVisible(true);
                                cre->CastSpell(cre, SPELL_SPAWN);
                            }
                    break;
                case DATA_FELHOUNDS:
                    for (const auto& guid : secondBossOutro)
                        if (auto cre = instance->GetCreature(guid))
                        {
                            cre->SetVisible(true);
                            Position pos{};
                            cre->GetMotionMaster()->MovePoint(1, -3218.40f + frand(-10, 10), 10374.50f + frand(-10, 10), -155.47f);
                            if (cre->GetEntry() == NPC_LIGHTFORGED_WIREFRAME)
                                AddDelayedEvent(14000, [cre]() -> void
                            {
                                cre->CastSpell(cre, SPELL_LIGHT_SHIELD);
                                cre->CastSpell(cre, 252787);
                            });
                        }
                    break;
                case DATA_ANTORAN:
                    if (auto go = instance->GetGameObject(GetGuidData(GO_PORTAL_TO_ELUNARIES)))
                        go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                    break;
                case DATA_EONAR:
                {
                    DoOnPlayers([this](Player* player)
                    {
                        instance->ToInstanceMap()->PermBindAllPlayers();
                    });
                    if (auto chest = instance->GetGameObject(GetGuidData(GO_EONAR_CACHE)))
                        chest->SetRespawnTime(86400);
                    break;
                }
                case DATA_KINGAROTH:
                    for (auto& guid : mobsAfterKingaroth)
                        if (auto cre = instance->GetCreature(guid))
                        {
                            cre->SetVisible(true);
                            cre->CastSpell(cre, SPELL_SPAWN);

                            if (cre->GetEntry() == NPC_IMPLOSIONS)
                                if (cre->GetPositionZ() >= 1876.0f)
                                {
                                    cre->CastSpell(cre, 251052, true);
                                    cre->DespawnOrUnsummon(urandms(8, 20));
                                }
                        }
                    break;
                }
                break;
            }
            }
            return true;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            return InstanceScript::GetGuidData(type);
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_COSMETIC_TORMENT)
            {
                for (auto guid : cosmeticTormentList)
                {
                    if (auto cosmetic = instance->GetCreature(guid))
                    {
                        if (data == 5)
                            cosmetic->RemoveAllAuras();
                        else
                            cosmetic->CastSpell(cosmetic, SPELL_TORMENT_FLAME_VISUAL + data, true);
                    }
                }
            }
        }



        void Load(const char* data) override
        {

            char dataHead1, dataHead2, dataHead3, dataHead4;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2 >> dataHead3 >> dataHead4;

            if (dataHead1 == 'A' && dataHead2 == 'T' && dataHead3 == 'B' && dataHead4 == 'T')
            {
                for (uint32 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            }

        }

        void Update(uint32 diff) override
        {
            if (timerIntroEvent <= diff)
            {
                uint8 rand = urand(1, 2);
                if (firstEventCounter.size() <= 5)
                {
                    for (uint8 i = 0; i < rand; ++i)
                        if (Creature* dreadwing = instance->SummonCreature(NPC_DREADWING, dreadWingsPos[urand(0, 1)], nullptr, urand(9000, 11000)))
                        {
                            firstEventCounter.push_back(dreadwing->GetGUID());
                            if (urand(1, 2) == 1)
                                dreadwing->GetMotionMaster()->MoveCirclePath(-3322.34f + frand(-10, 10), 9544.79f + frand(-10, 10), 24.30f + frand(-10, 5), frand(50, 60), urand(0, 1), 12);
                            else
                                dreadwing->GetMotionMaster()->MoveRandom(40.0f);
                        }
                }
                timerIntroEvent = urand(4000, 6000);
            }
            else
                timerIntroEvent -= diff;


            if (timerIntroEvent2 <= diff)
            {
                introGuids.remove_if([this](const ObjectGuid& guid) {
                    Creature* cre = instance->GetCreature(guid);
                    return !cre || !cre->IsAlive();
                });

                if (!wireframesGuids.empty())
                    if (Creature* protect = instance->GetCreature(wireframesGuids[urand(0, wireframesGuids.size())]))
                    {
                        Creature* cre = nullptr;
                        for (const auto& guid : introGuids)
                            if (Creature* cur = instance->GetCreature(guid))
                                if (!cre || protect->GetDistance(cur) <= protect->GetDistance(cre))
                                    cre = cur;
                        if (cre)
                            protect->CastSpell(cre, SPELL_INTRO_FIELD_OF_FIRE);

                    }

                timerIntroEvent2 = urand(5000, 7000);
            }
            else
                timerIntroEvent2 -= diff;

            if (timerConstEvent <= diff)
            {
                if (secondEventCounter.size() <= 20)
                {
                    if (TempSummon* cre = instance->SummonCreature((urand(1, 2) == 1 ? NPC_RUN_NPC_1 : NPC_RUN_NPC_2), { -2934.23f + frand(-9, 9), 10312.14f + frand(-9,9), -165.48f }, nullptr, 35000))
                    {
                        secondEventCounter.push_back(cre->GetGUID());
                        cre->GetMotionMaster()->MovePoint(0, -3164.60f + frand(-9, 9), 10452.94f + frand(-9, 9), -194.78f);
                        AddDelayedEvent(35000, [cre]() -> void {cre->Kill(cre,cre); });
                    }
                }
                timerConstEvent = urand(3000, 4000);
            }
            else
                timerConstEvent -= diff;

            if (checkSurgeLifeTimer <= diff)
            {
                checkSurgeLifeTimer = 1500;

                DoOnPlayers([](Player* player)
                {
                    if ((player->GetAreaId() == 8681 || player->GetAreaId() == 9333) && player->IsAlive())
                    {
                        if (player->GetPositionX() > MIN_X && player->GetPositionX() < MAX_X && player->GetPositionY() > MIN_Y && player->GetPositionY() < MAX_Y)
                        {
                            if (!player->HasAura(SPELL_SURGE_OF_LIFE_OVERRIDE) && !player->HasAura(SPELL_SURGE_OF_LIFE_OVERRIDE_2))
                                player->CastSpell(player, SPELL_SURGE_OF_LIFE_OVERRIDE, true);
                        }
                        else
                            player->RemoveAurasDueToSpell(SPELL_SURGE_OF_LIFE_OVERRIDE);
                    }
                });
            }
            else
                checkSurgeLifeTimer -= diff;

            if (playerFallCheckTimer <= diff)
            {
                playerFallCheckTimer = 1000;

                DoOnPlayers([](Player* player)
                {
                    if (player->IsFalling())
                    {
                        if (player->GetDistance(-10574.53f, 8629.80f, 1871.52f) < 300.0f && player->GetPositionZ() < 1820.0f)
                        {
                            if (player->IsAlive())
                                player->Kill(player,player);

                            player->NearTeleportTo(-10574.89f, 8771.44f, 1871.46f, player->GetOrientation());
                        }
                        else if (player->GetDistance(-10574.7f, 8098.39f, 1873.72f) < 250.0f && player->GetPositionZ() < 1835.0f)
                        {
                            if (player->IsAlive())
                                player->Kill(player,player);

                            player->NearTeleportTo(-10575.16f, 8199.96f, 1871.29f, player->GetOrientation());
                        }
                    }
                });
            }
            else
                playerFallCheckTimer -= diff;
        }
    };
};

void AddSC_instance_antorus()
{
    new instance_antorus();
}
