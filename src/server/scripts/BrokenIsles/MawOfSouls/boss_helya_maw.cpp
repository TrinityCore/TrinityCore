#include "maw_of_souls.h"
#include "GameObject.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_TAINT_SEA = 2,
    SAY_97 = 3,
    SAY_94 = 4,
    SAY_90 = 5,
    SAY_87 = 6,
    SAY_PHASE2 = 7,
    SAY_WARN_WING_BUFFET = 8,
    SAY_DEATH = 9,
    SAY_SUBMERGED_2 = 10
};

enum Spells
{
    //Intro
    SPELL_SOULLESS_SCREAM = 194603,

    SPELL_INTERFERE_TARGETTING = 197710,
    SPELL_TAINT_OF_THE_SEA = 197517,
    SPELL_TORRENT = 197805,
    SPELL_TAINTED_ESSENCE = 202470,
    //Phase 2
    SPELL_SUBMERGED = 196947, //32:34
    SPELL_TRANSFORM = 197734, //32:44 - Self hit
                        //SMSG_MOVE_UPDATE_TELEPORT 32:44 - 2933.5 Y: 961.792 Z: 510.38 O: 4.712389
                        SPELL_SMASH = 197689, //Force cast all players
                        SPELL_WING_BUFFET = 198520,
                        SPELL_TORRENT_2 = 198495,
                        SPELL_CORRUPTED_BELLOW = 227233,

                        //Tentacle
                        SPELL_GRASPING_STUN_LEFT = 198180,
                        SPELL_GRASPING_STUN_RIGHT = 196450,
                        SPELL_PIERCING_TENTACLE = 197112,
                        SPELL_SWIRLING_POOL_AT = 195167,
                        SPELL_SWIRLING_POOL_DMG = 195309,
                        SPELL_SWIRLING_POOL_JUMP = 194839,

                        //Swirling Pool
                        SPELL_TURBULENT_WATERS = 197753,

                        //Heroic
                        SPELL_BRACKWATER_BARRAGE = 202088,
                        SPELL_BRACKWATER_BARRAGE_DMG = 202098,

                        //Trash
                        SPELL_GIVE_NO = 196885,
                        SPELL_DEBILITATING = 195293,
                        SPELL_BIND = 195279,
};

enum eEvents
{
    EVENT_INTRO = 1,
    EVENT_TAINT_SEA = 2,
    EVENT_TORRENT = 3,
    EVENT_SUM_DESTRUCTOR_TENTACLE = 4,
    EVENT_SUM_PIERCING_TENTACLE = 5,
    EVENT_P1_SUBMERGED_START = 6,
    EVENT_P1_SUBMERGED_END = 7,
    EVENT_WING_BUFFET = 8,
    EVENT_ACTION_SWIRLING_POOL = 9,
    EVENT_BRACKWATER_BARRAGE = 10,
    EVENT_TORRENT_2 = 11, //Second phase
    EVENT_CORRUPTED_BELLOW = 12,
    EVENT_P2_SUBMERGED_START = 13,
    EVENT_P2_SUBMERGED_END = 14,

    //Trash
    EVENT_SUMMON_1 = 1,
    EVENT_SUMMON_2 = 2,
    EVENT_GIVE_NO = 3,
    EVENT_DEBILITATING = 4,
    EVENT_BIND = 5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
};

enum eVisualKits
{
    VISUAL_KIT_1 = 60920, //30:14 - visual spawn
    VISUAL_KIT_2 = 62877, //30:22 - start intro
    VISUAL_KIT_3 = 60222, //30:28
    VISUAL_KIT_4 = 63777, //Brackwater barrage?

    //Brackwater missle
    VISUAL_BW_MIS_RIGHT = 52865,
    VISUAL_BW_MIS_LEFT = 52868,
    //Heroic
    VISUAL_H_BRACKWATER_LEFT = 52869,
    VISUAL_H_BRACKWATER_RIGHT = 52870,
    //Mythic
    VISUAL_M_BRACKWATER_LEFT = 65462,
    VISUAL_M_BRACKWATER_RIGHT = 65463,
};

enum eMisk
{
    DATA_POOL_ACTIVE = 0,
    DATA_POOL_IDX
};

std::vector<std::pair<uint32, Position>> graspingPos =
{
    //Left
    {NPC_GRASPING_TENTACLE_3, {2917.30f, 950.65f, 512.26f, 5.73f}},
    {NPC_GRASPING_TENTACLE_2, {2921.71f, 959.25f, 513.21f, 5.85f}},
    {NPC_GRASPING_TENTACLE_3, {2925.54f, 965.84f, 512.26f, 5.65f}},

    //Right
    {NPC_GRASPING_TENTACLE_1, {2941.37f, 966.34f, 513.79f, 4.08f}},
    {NPC_GRASPING_TENTACLE_4, {2945.93f, 958.59f, 513.23f, 3.58f}},
    {NPC_GRASPING_TENTACLE_1, {2948.58f, 952.28f, 513.47f, 3.41f}}
};

std::vector<Position> swirlingPos =
{
    {2933.33f, 960.27f, 510.39f, 1.57f},
    {2926.73f, 952.15f, 510.39f, 1.57f},
    {2939.91f, 952.15f, 510.39f, 1.57f},
    {2933.40f, 941.15f, 510.39f, 1.57f},
    {2922.20f, 937.07f, 510.39f, 1.57f},
    {2943.52f, 935.80f, 510.39f, 1.57f},
    {2927.44f, 928.84f, 510.39f, 1.57f},
    {2939.53f, 928.46f, 510.39f, 1.57f},
    {2918.25f, 921.30f, 510.39f, 1.57f},
    {2933.18f, 920.70f, 510.39f, 1.57f},
    {2948.52f, 921.45f, 510.39f, 1.57f}
};

//Skyal
Position const addsPos[18] =
{
    {2942.57f, 886.99f, 537.76f, 4.48f},
    {2924.55f, 887.20f, 537.65f, 5.26f},

    {2906.68f, 752.27f, 538.55f, 4.72f}, //97097
    {2959.93f, 751.26f, 538.52f, 4.63f}, //97097
    {2916.09f, 807.88f, 535.81f, 4.66f}, //97097
    {2950.01f, 804.85f, 535.65f, 4.66f}, //97097
    {2923.85f, 771.78f, 538.59f, 4.53f}, //98919
    {2957.19f, 775.12f, 538.66f, 5.03f}, //98919
    {2923.93f, 838.52f, 536.17f, 4.66f}, //98919
    {2942.26f, 838.82f, 536.16f, 4.64f}, //98919
    {2917.46f, 772.97f, 538.55f, 4.40f}, //99033
    {2950.14f,  773.0f, 538.52f, 4.93f}, //99033
    {2921.54f, 807.65f, 535.82f, 4.67f}, //99033
    {2945.05f, 805.94f, 535.84f, 4.53f}, //99033
    {2911.42f,  775.0f, 538.55f, 4.43f}, //97365
    {2944.38f, 771.65f, 538.54f, 4.94f}, //97365
    {2919.12f, 839.14f, 536.17f, 4.74f}, //97200
    {2946.58f, 838.83f, 536.17f, 4.74f}  //97200
};

uint32 swirlingGO[11]
{
    GO_SWIRLING_POOL_1,
    GO_SWIRLING_POOL_2,
    GO_SWIRLING_POOL_3,
    GO_SWIRLING_POOL_4,
    GO_SWIRLING_POOL_5,
    GO_SWIRLING_POOL_6,
    GO_SWIRLING_POOL_7,
    GO_SWIRLING_POOL_8,
    GO_SWIRLING_POOL_9,
    GO_SWIRLING_POOL_10,
    GO_SWIRLING_POOL_11
};

std::vector<Position> brackwaterLeftPos =
{
    {2939.40f, 962.60f, 512.62f},
    {2942.39f, 959.01f, 512.62f},
    {2936.74f, 958.69f, 512.44f},
    {2940.28f, 954.87f, 512.62f},
    {2945.83f, 955.33f, 512.62f},
    {2935.46f, 953.10f, 512.62f},
    {2938.70f, 950.05f, 512.44f},
    {2944.88f, 950.54f, 512.62f},
    {2935.38f, 946.62f, 512.62f},
    {2949.86f, 946.64f, 512.62f},
    {2941.57f, 945.62f, 512.62f},
    {2939.18f, 942.02f, 512.62f},
    {2947.10f, 941.91f, 512.62f},
    {2936.93f, 938.13f, 512.62f},
    {2943.34f, 937.14f, 512.62f},
    {2950.44f, 936.89f, 512.62f},
    {2936.81f, 931.11f, 512.62f},
    {2947.02f, 931.25f, 512.62f},
    {2941.39f, 929.56f, 512.44f},
    {2936.53f, 924.82f, 512.62f},
    {2943.62f, 924.13f, 512.62f},
    {2950.87f, 923.85f, 512.62f},
    {2939.42f, 917.48f, 512.62f},
    {2946.80f, 916.83f, 512.62f}
};

std::vector<Position> brackwaterRightPos =
{
    {2925.56f, 963.48f, 512.62f},
    {2929.07f, 960.50f, 512.62f},
    {2923.64f, 958.06f, 512.62f},
    {2919.76f, 956.44f, 512.96f},
    {2928.60f, 955.48f, 512.62f},
    {2922.82f, 953.38f, 512.62f},
    {2930.63f, 950.74f, 512.62f},
    {2918.42f, 950.52f, 512.62f},
    {2925.68f, 949.56f, 512.44f},
    {2920.87f, 946.22f, 512.62f},
    {2929.98f, 945.46f, 512.62f},
    {2925.92f, 944.20f, 512.62f},
    {2917.76f, 944.13f, 512.62f},
    {2929.15f, 940.10f, 512.62f},
    {2921.97f, 939.96f, 512.62f},
    {2925.20f, 937.02f, 512.44f},
    {2916.68f, 937.24f, 512.62f},
    {2921.16f, 934.19f, 512.62f},
    {2927.87f, 932.90f, 512.62f},
    {2916.64f, 931.38f, 512.62f},
    {2923.48f, 929.93f, 512.44f},
    {2927.61f, 925.69f, 512.62f},
    {2918.18f, 925.71f, 512.62f},
    {2922.55f, 922.01f, 512.62f},
    {2913.16f, 922.54f, 512.62f},
    {2931.84f, 921.01f, 512.34f},
    {2917.70f, 919.10f, 512.54f},
    {2927.18f, 918.08f, 512.62f}
};

Position const smashPos[5] =
{
    {2947.05f, 914.22f, 513.0f},
    {2950.39f, 914.91f, 512.26f},
    {2933.61f, 914.46f, 512.38f},
    {2923.04f, 914.18f, 512.26f},
    {2915.98f, 914.39f, 512.26f}
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
};

//96759
struct boss_helya : public BossAI
{
    boss_helya(Creature* creature) : BossAI(creature, DATA_HELYA)
    {
        me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
        SetCombatMovement(false);
    }

    std::list<ObjectGuid> playerGUIDList;
    std::set<uint8> graspingRand;
    std::vector<ObjectGuid> poolGUID;
    std::list<uint8> poolRandList;
    std::map<ObjectGuid, uint8> poolSaveMap; //Guid, idx
    bool introSpawn = false;
    bool introEvent = false;
    bool eventDelay = false;
    bool submerged = false;
    bool encounterComplete = false;
    uint8 tentacleDiedCound = 0;
    uint8 healthSwitch = 0;
    uint8 healthSay = 0;
    uint8 BWrand = 0;
    uint32 piercingTentacleTimer = 0;

    void Reset() override
    {
        _Reset();
        submerged = false;
        encounterComplete = false;
        tentacleDiedCound = 0;
        healthSwitch = 0;
        healthSay = healthSwitch + 3;
        piercingTentacleTimer = 8000;
        UpdateShipState(STATE_REBUILDING);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
        me->SetReactState(REACT_AGGRESSIVE);

        std::list<Creature*> poolList;
        GetCreatureListWithEntryInGrid(poolList, me, NPC_SWIRLING_POOL_TRIG, 200.0f);
        for (auto const& pool : poolList)
            pool->DespawnOrUnsummon();

        ChangePoolState(GO_STATE_READY);

        graspingRand = { 0, 1, 2, 3, 4, 5 };
        poolRandList = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Trinity::Containers::RandomResize(poolRandList, 3);
        poolSaveMap.clear();
        poolGUID.clear();

        uint8 idx = 0;
        for (auto pos : swirlingPos)
            if (auto pool = me->SummonCreature(NPC_SWIRLING_POOL_VEH, pos))
            {
                poolGUID.push_back(pool->GetGUID());
                pool->AI()->SetData(DATA_POOL_IDX, idx++);
            }

        if (introEvent)
        {
            SummonGrasping(true);
            SummonDestructor(true);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _JustEngagedWith();
        events.RescheduleEvent(EVENT_TAINT_SEA, 0);
        events.RescheduleEvent(EVENT_SUM_DESTRUCTOR_TENTACLE, 26000);
        events.RescheduleEvent(EVENT_SUM_PIERCING_TENTACLE, piercingTentacleTimer);

        if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
            events.RescheduleEvent(EVENT_BRACKWATER_BARRAGE, 15000);
        else
            events.RescheduleEvent(EVENT_TORRENT, 3000);

        std::list<Creature*> tentacleList;
        GetCreatureListWithEntryInGrid(tentacleList, me, 99801, 200.0f); //DESTRUCTOR_TENTACLE
        GetCreatureListWithEntryInGrid(tentacleList, me, 98363, 200.0f); //NPC_GRASPING_TENTACLE_1
        GetCreatureListWithEntryInGrid(tentacleList, me, 100362, 200.0f); //NPC_GRASPING_TENTACLE_2
        for (auto tentacle : tentacleList)
            if (!tentacle->IsInCombat())
                tentacle->AI()->DoZoneInCombat(tentacle, 150.0f);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade(15);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer() || who->ToPlayer()->IsGameMaster())
            return;

        if (me->GetDistance(who) < 140.0f && !introSpawn)
        {
            introSpawn = true;
            eventDelay = true;
            me->SendPlaySpellVisualKit(0, VISUAL_KIT_1, 100);
            me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
            {
                eventDelay = false;
            });
            return;
        }

        if (me->GetDistance(who) < 130.0f && !introEvent && !eventDelay)
        {
            introEvent = true;
            Talk(SAY_INTRO); //You ALL will regret trespassing in my realm.
            me->SendPlaySpellVisualKit(0, VISUAL_KIT_2, 100);
            events.RescheduleEvent(EVENT_INTRO, 5000);
        }
    }

    void SummonGrasping(bool restart = false)
    {
        if (tentacleDiedCound >= 6 || graspingRand.empty())
            return;

        if (restart)
        {
            uint8 lRand = urand(0, 2);
            uint8 rRand = urand(3, 5);
            graspingRand.erase(lRand);
            graspingRand.erase(rRand);
            me->SummonCreature(graspingPos[lRand].first, graspingPos[lRand].second);
            me->SummonCreature(graspingPos[rRand].first, graspingPos[rRand].second);
        }
        else
        {
            auto idx = Trinity::Containers::SelectRandomContainerElement(graspingRand);
            graspingRand.erase(idx);
            me->SummonCreature(graspingPos[idx].first, graspingPos[idx].second);
        }
    }

    void SummonDestructor(bool restart = false)
    {
        if (tentacleDiedCound >= 6 || poolRandList.empty())
            return;

        if (restart)
        {
            if (auto destructor = me->SummonCreature(NPC_DESTRUCTOR_TENTACLE, swirlingPos[0]))
                poolSaveMap[destructor->GetGUID()] = 0;
        }
        else
        {
            uint8 idx = Trinity::Containers::SelectRandomContainerElement(poolRandList);
            poolRandList.remove(idx);

            if (auto destructor = me->SummonCreature(NPC_DESTRUCTOR_TENTACLE, swirlingPos[idx]))
                poolSaveMap[destructor->GetGUID()] = idx;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_DESTRUCTOR_TENTACLE:
        case NPC_GRASPING_TENTACLE_1:
        case NPC_GRASPING_TENTACLE_2:
        case NPC_GRASPING_TENTACLE_3:
        case NPC_GRASPING_TENTACLE_4:
        {
            if (++tentacleDiedCound == 6)
            {
                for (uint32 entry : {NPC_DESTRUCTOR_TENTACLE, NPC_GRASPING_TENTACLE_1, NPC_GRASPING_TENTACLE_2, NPC_GRASPING_TENTACLE_3, NPC_GRASPING_TENTACLE_4})
                    summons.DespawnEntry(entry);
                events.Reset();
                events.RescheduleEvent(EVENT_P1_SUBMERGED_START, 1000);
                Talk(SAY_87);
            }
            else if (tentacleDiedCound < 6)
            {
                if (summon->GetEntry() == NPC_DESTRUCTOR_TENTACLE)
                {
                    uint8 idx = poolSaveMap[summon->GetGUID()];
                    poolRandList.push_back(idx);
                    poolSaveMap.erase(summon->GetGUID());
                }
                else
                {
                    me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
                    {
                        SummonGrasping();
                    });
                }
            }
            break;
        }
        default:
            return;
        }

        if (healthSwitch < 2)
        {
            me->SetHealth(me->GetHealth() - me->CountPctFromMaxHealth(3));
            ++healthSwitch;
            healthSay = healthSwitch + 3;
            Talk(healthSay);
        }
        else
        {
            me->SetHealth(me->GetHealth() - me->CountPctFromMaxHealth(4));
            healthSwitch = 0;
            healthSay = healthSwitch + 3;
            Talk(healthSay);
        }
    }

    void UpdateShipState(uint8 state)
    {
        if (auto pGo = instance->instance->GetGameObject(instance->GetGuidData(DATA_SHIP)))
        {
            if (state == STATE_DESTROY)
            {
                pGo->SetDisplayId(31853);
                pGo->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED, nullptr, true);
            }
            else if (state == STATE_REBUILDING)
            {
                pGo->SetDisplayId(31852);
                pGo->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, nullptr, true);
            }
        }
    }

    bool CheckAura()
    {
        auto const& players = me->GetMap()->GetPlayers();
        uint32 size = 0;
        if (!players.isEmpty())
        {
            size = players.getSize();
            if (size < 5)
                return false;

            for (auto const& itr : players)
            {
                if (auto player = itr.GetSource())
                {
                    if (!player->HasAura(213413))
                        return false;
                }
            }
        }
        return true;
    }

    bool GetObjectData(ObjectGuid const& guid)
    {
        bool find = false;

        for (auto targetGuid : playerGUIDList)
            if (targetGuid == guid)
                find = true;

        if (!find)
            playerGUIDList.push_back(guid);

        return find;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(71) && !encounterComplete)
        {
            encounterComplete = true;
            me->AttackStop();
            Talk(SAY_DEATH);
            _JustDied();
            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 1824);

            // for quest need "kill"
            instance->DoOnPlayers([this](Player* player)
            {
                player->KilledMonsterCredit(me->GetEntry());

                if (CheckAura())
                {
                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE)
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 213415);
                }
            });
            me->DespawnOrUnsummon(100);
        }
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_BRACKWATER_BARRAGE)
        {
            std::vector<Position> brackwaterPos = !BWrand ? brackwaterLeftPos : brackwaterRightPos;
            uint8 count = 0;

            for (auto const& pos : brackwaterPos)
            {
                ++count;
                if (me)
                {
                    for(uint8 i = 0; i < count; ++i)
                        me->CastSpell(pos, SPELL_BRACKWATER_BARRAGE_DMG, true);
                }

            }
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_SMASH)
            target->GetMotionMaster()->MoveJump(smashPos[urand(0, 4)], 30.0f, 10.0f);
    }

    void ChangePoolState(GOState state)
    {
        for (uint8 i = 0; i < 11; ++i)
            if (auto go = me->FindNearestGameObject(swirlingGO[i], 200.0f))
            {
                go->SetGoState(state);
            }
    }

    void OpenNewPool(bool closeOldPull = false)
    {
        std::list<ObjectGuid> tempGuid;

        for (auto guid : poolGUID)
        {
            if (auto pool = Creature::GetCreature(*me, guid))
            {
                if (pool->AI()->GetData(DATA_POOL_IDX) < 4)
                {
                    if (closeOldPull)
                    {
                        if (auto pool = Creature::GetCreature(*me, guid))
                            pool->AI()->DoAction(ACTION_3);
                    }
                    continue;
                }

                if (pool->AI()->GetData(DATA_POOL_ACTIVE))
                    continue;

                tempGuid.push_back(guid);
            }
        }

        if (tempGuid.empty())
            return;

        Trinity::Containers::RandomResize(tempGuid, 1);

        for (auto guid : tempGuid)
            if (auto pool = Creature::GetCreature(*me, guid))
                pool->AI()->DoAction(ACTION_1);
    }

    void CheckActivePool()
    {
        poolRandList.clear();

        for (auto guid : poolGUID)
        {
            if (auto pool = Creature::GetCreature(*me, guid))
            {
                if (!pool->AI()->GetData(DATA_POOL_ACTIVE))
                    continue;

                uint8 index = pool->AI()->GetData(DATA_POOL_IDX);
                if (pool->AI()->GetData(DATA_POOL_IDX) > 3)
                    poolRandList.push_back(index);
            }
        };
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !submerged)
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_INTRO:
                me->SendPlaySpellVisualKit(0, VISUAL_KIT_3, 100);
                DoCast(me, SPELL_SOULLESS_SCREAM, true);
                DoCast(me, SPELL_INTERFERE_TARGETTING, true);
                SummonGrasping(true);
                SummonDestructor(true);
                break;
            case EVENT_TAINT_SEA:
                DoCast(SPELL_TAINT_OF_THE_SEA);
                events.RescheduleEvent(EVENT_TAINT_SEA, 12000);
                Talk(SAY_TAINT_SEA);
                break;
            case EVENT_TORRENT:
                DoCast(SPELL_TORRENT);
                events.RescheduleEvent(EVENT_TORRENT, 5000);
                break;
            case EVENT_TORRENT_2: //Second Phase
                DoCast(SPELL_TORRENT_2);
                events.RescheduleEvent(EVENT_TORRENT_2, 8000);
                break;
            case EVENT_SUM_DESTRUCTOR_TENTACLE:
                SummonDestructor();
                events.RescheduleEvent(EVENT_SUM_DESTRUCTOR_TENTACLE, 26000);
                break;
            case EVENT_SUM_PIERCING_TENTACLE:
            {
                if (!poolRandList.empty())
                {
                    uint8 idx = 0;
                    if (piercingTentacleTimer > 2000)
                        idx = Trinity::Containers::SelectRandomContainerElement(poolRandList);
                    else
                    {
                        idx = poolRandList.front();
                        poolRandList.pop_front();
                        poolRandList.push_back(idx);
                    }
                    if (auto pool = Creature::GetCreature(*me, poolGUID[idx]))
                        pool->AI()->DoAction(ACTION_1);
                }
                events.RescheduleEvent(EVENT_SUM_PIERCING_TENTACLE, piercingTentacleTimer);
                break;
            }
            case EVENT_P1_SUBMERGED_START:
                submerged = true;
                me->InterruptNonMeleeSpells(false);
                me->CastSpell(me, SPELL_SUBMERGED, true);
                Talk(SAY_PHASE2);
                events.RescheduleEvent(EVENT_SUM_PIERCING_TENTACLE, piercingTentacleTimer = 2000);
                events.RescheduleEvent(EVENT_P1_SUBMERGED_END, 15000);
                break;
            case EVENT_P1_SUBMERGED_END:
                submerged = false;
                OpenNewPool(true);
                DoTeleportTo(2933.5f, 961.79f, 512.38f, 4.71f);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                DoCast(me, SPELL_TRANSFORM, true);
                DoCast(me, SPELL_SMASH, true);
                UpdateShipState(STATE_DESTROY);
                events.CancelEvent(EVENT_SUM_PIERCING_TENTACLE);
                events.RescheduleEvent(EVENT_ACTION_SWIRLING_POOL, 1000);
                events.RescheduleEvent(EVENT_WING_BUFFET, 10000);
                events.RescheduleEvent(EVENT_TORRENT_2, 16000);
                events.RescheduleEvent(EVENT_CORRUPTED_BELLOW, 15000);
                events.RescheduleEvent(EVENT_P2_SUBMERGED_START, 70000);
                break;
            case EVENT_P2_SUBMERGED_START: //In Phase 2
                submerged = true;
                me->InterruptNonMeleeSpells(false);
                me->CastSpell(me, SPELL_SUBMERGED, true);
                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
                OpenNewPool();
                CheckActivePool();
                Trinity::Containers::SelectRandomContainerElement(poolRandList);
                Talk(SAY_SUBMERGED_2);
                events.Reset();
                events.RescheduleEvent(EVENT_P2_SUBMERGED_END, 15000);
                events.RescheduleEvent(EVENT_SUM_PIERCING_TENTACLE, piercingTentacleTimer);
                break;
            case EVENT_P2_SUBMERGED_END: //In Phase 2
                submerged = false;
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                events.CancelEvent(EVENT_SUM_PIERCING_TENTACLE);
                events.RescheduleEvent(EVENT_ACTION_SWIRLING_POOL, 1000);
                events.RescheduleEvent(EVENT_WING_BUFFET, 10000);
                events.RescheduleEvent(EVENT_TORRENT_2, 14000);
                events.RescheduleEvent(EVENT_CORRUPTED_BELLOW, 16000);
                events.RescheduleEvent(EVENT_P2_SUBMERGED_START, 70000);
                break;
            case EVENT_WING_BUFFET:
                if (auto target = me->GetVictim())
                {
                    if (!me->IsWithinMeleeRange(target))
                    {
                        Talk(SAY_WARN_WING_BUFFET);
                        me->CastSpell(me, SPELL_WING_BUFFET);
                    }
                }
                events.RescheduleEvent(EVENT_WING_BUFFET, 2000);
                break;
            case EVENT_ACTION_SWIRLING_POOL:
            {
                std::list<Creature*> poolList;
                GetCreatureListWithEntryInGrid(poolList, me, NPC_SWIRLING_POOL_TRIG, 150.0f);
                for (auto pool : poolList)
                {
                    if (!pool->HasAura(SPELL_TURBULENT_WATERS) && pool->AI()->GetData(DATA_POOL_ACTIVE) && pool->AI()->GetData(DATA_POOL_IDX) > 4)
                        pool->CastSpell(pool, SPELL_TURBULENT_WATERS, true);
                }
                break;
            }
            case EVENT_BRACKWATER_BARRAGE:
            {
                playerGUIDList.clear();
                Position pos = { 2934.49f, 1055.94f, 510.51f, 0.0f };
                BWrand = urand(0, 1);
                uint32 visualBrackwater = 0;
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC)
                    visualBrackwater = VISUAL_H_BRACKWATER_LEFT + BWrand;
                else if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE)
                    visualBrackwater = VISUAL_M_BRACKWATER_LEFT + BWrand;
                DoCast(SPELL_BRACKWATER_BARRAGE);
                events.RescheduleEvent(EVENT_BRACKWATER_BARRAGE, 22000);
                break;
            }
            case EVENT_CORRUPTED_BELLOW:
            {
                me->AttackStop();
                float facing[3] = { 4.26f, 4.71f, 5.16f };
                me->SetFacingTo(facing[urand(0, 2)]);
                me->CastSpell(me, SPELL_CORRUPTED_BELLOW);
                events.RescheduleEvent(EVENT_CORRUPTED_BELLOW, 21000);
                me->GetScheduler().Schedule(8s, [this](TaskContext /*context*/)
                {
                    me->SetFacingTo(4.71f);
                    me->SetReactState(REACT_AGGRESSIVE);
                });
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//98363, 99801, 100354, 100360, 100362, 100188
struct npc_helya_tentacle : public ScriptedAI
{
    npc_helya_tentacle(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetDisableGravity(true);
        me->SetCollision(true);
        me->SetReactState(REACT_DEFENSIVE);
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;

    void IsSummonedBy(Unit* summoner) override
    {
        switch (me->GetEntry())
        {
        case 100360: //On NPC_GRASPING_TENTACLE_3
        case 100362: //On NPC_GRASPING_TENTACLE_2
            events.RescheduleEvent(EVENT_1, 1000);
            break;
        case 98363:  //On NPC_GRASPING_TENTACLE_1
        case 100354: //On NPC_GRASPING_TENTACLE_4
            events.RescheduleEvent(EVENT_2, 1000);
            break;
        case NPC_PIERCING_TENTACLE:
            events.RescheduleEvent(EVENT_3, 1000);
            return;
        default:
            break;
        }
        if (instance->GetBossState(DATA_HELYA) == IN_PROGRESS)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 100.0f);
        }
    }

    void Reset() override {}

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (instance && instance->GetBossState(DATA_HELYA) != IN_PROGRESS)
            if (auto helya = instance->instance->GetCreature(instance->GetGuidData(DATA_HELYA)))
                helya->SetInCombatWithZone();

        switch (me->GetEntry())
        {
        case 99801: //DESTRUCTOR_TENTACLE
            Talk(0);
            events.RescheduleEvent(EVENT_5, 2000);
            events.RescheduleEvent(EVENT_6, 2000);
            break;
        default:
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (auto summoner = me->GetOwner())
            summoner->Kill(summoner,summoner);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(me, SPELL_GRASPING_STUN_LEFT, true);
                break;
            case EVENT_2:
                DoCast(me, SPELL_GRASPING_STUN_RIGHT, true);
                break;
            case EVENT_3:
                me->CastSpell(me, SPELL_PIERCING_TENTACLE, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
                events.RescheduleEvent(EVENT_4, 4000);
                break;
            case EVENT_4:
                me->SetDisplayId(11686);
                break;
            case EVENT_5:
            {
                Unit* target = me->GetVictim();
                if (target && me->IsWithinMeleeRange(target))
                    me->CastSpell(target, 185539, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
                else
                {
                    events.RescheduleEvent(EVENT_5, 3000);
                    break;
                }
                events.RescheduleEvent(EVENT_5, 12000);
                break;
            }
            case EVENT_6:
            {
                Unit* target = me->GetVictim();
                if (!target || !me->IsWithinMeleeRange(target))
                {
                    if (me->GetReactState() != REACT_PASSIVE)
                        me->AttackStop();
                    me->CastSpell(me, 196534, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE | TRIGGERED_IGNORE_CASTER_AURASTATE));
                }
                else
                    me->SetReactState(REACT_AGGRESSIVE);
                events.RescheduleEvent(EVENT_6, 2000);
                break;
            }
            }
        }
        if (me->GetEntry() == 99801)
            DoMeleeAttackIfReady();
    }
};

//97099
struct npc_helya_tentacle_veh : public ScriptedAI
{
    npc_helya_tentacle_veh(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC); 
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
    }

    ObjectGuid poolGUID;
    bool createAT = false;
    uint8 index = 0;

    void Reset() override {}

    void SetData(uint32 id, uint32 value) override
    {
        if (id == DATA_POOL_IDX)
            index = value;
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_POOL_ACTIVE:
            return createAT;
        case DATA_POOL_IDX:
            return index;
        }
        return 0;
    }

    void ActivateGo(bool anim = false)
    {
        for (uint8 i = 0; i < 11; ++i)
            if (auto go = me->FindNearestGameObject(swirlingGO[i], 1.0f))
            {
                if (anim)
                    go->SetGoState(GO_STATE_ACTIVE);
            }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_3)
        {
            ActivateGo(true);
            me->RemoveAllAuras();
            if (auto pool = Creature::GetCreature(*me, poolGUID))
                pool->DespawnOrUnsummon();
            return;
        }

        if (!createAT)
        {
            createAT = true;
            DoCast(me, SPELL_SWIRLING_POOL_AT, true);
            ActivateGo();
        }

        if (auto owner = me->GetOwner())
        {
            if (action == ACTION_1)
                owner->SummonCreature(NPC_PIERCING_TENTACLE, me->GetPosition(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 6 * IN_MILLISECONDS);

            if (auto pool = owner->SummonCreature(NPC_SWIRLING_POOL_TRIG, me->GetPosition()))
                poolGUID = pool->GetGUID();
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//99803
struct npc_helya_destructor_tentacle_veh : public ScriptedAI
{
    npc_helya_destructor_tentacle_veh(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        if (auto pool = me->FindNearestCreature(NPC_SWIRLING_POOL_VEH, 3.0f))
            pool->AI()->DoAction(ACTION_2);
    }

    void UpdateAI(uint32 diff) override {}
};

//99307
struct npc_skyal : public ScriptedAI
{
    npc_skyal(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        instance->SetBossState(DATA_SKJAL, NOT_STARTED);

        if (instance->GetBossState(DATA_HARBARON) != DONE)
        {
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(false);
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            me->SetVisible(true);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);

            for (uint8 i = 2; i < 18; ++i)
            {
                if (i < 6)
                {
                    if (auto summon = instance->instance->SummonCreature(NPC_HELARJAR_CHAMPION, me->GetPosition()))
                    {
                        summon->SetHomePosition(addsPos[i]);
                        summon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
                else if (i < 10)
                {
                    if (auto summon = instance->instance->SummonCreature(NPC_SEACURSED_SWIFTBLADE, me->GetPosition()))
                    {
                        summon->SetHomePosition(addsPos[i]);
                        summon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
                else if (i < 14)
                {
                    if (auto summon = instance->instance->SummonCreature(NPC_HELARJAR_MISTCALLER, me->GetPosition()))
                    {
                        summon->SetHomePosition(addsPos[i]);
                        summon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
                else if (i < 16)
                {
                    if (auto summon = instance->instance->SummonCreature(NPC_SEACURSED_MISTMENDER, me->GetPosition()))
                    {
                        summon->SetHomePosition(addsPos[i]);
                        summon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
                else if (i < 18)
                {
                    if (auto summon = instance->instance->SummonCreature(NPC_SEACURSED_SOULKEEPER, me->GetPosition()))
                    {
                        summon->SetHomePosition(addsPos[i]);
                        summon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_SUMMON_1, 1000);
        events.RescheduleEvent(EVENT_SUMMON_2, 10000);
        events.RescheduleEvent(EVENT_GIVE_NO, 7000);
        events.RescheduleEvent(EVENT_DEBILITATING, 13000);
        events.RescheduleEvent(EVENT_BIND, 17000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(2);
        instance->SetBossState(DATA_SKJAL, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SUMMON_1:
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (auto sum = me->SummonCreature(98973, addsPos[i], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 4000))
                        sum->AI()->DoZoneInCombat(sum, 90.0f);
                }
                Talk(1);
                events.RescheduleEvent(EVENT_SUMMON_1, 18000);
                break;
            case EVENT_SUMMON_2:
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (auto sum = me->SummonCreature(99447, addsPos[i], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 4000))
                        sum->AI()->DoZoneInCombat(sum, 90.0f);
                }
                Talk(1);
                events.RescheduleEvent(EVENT_SUMMON_2, 18000);
                break;
            case EVENT_GIVE_NO:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    me->CastSpell(target, SPELL_GIVE_NO);
                events.RescheduleEvent(EVENT_GIVE_NO, 13000);
                break;
            case EVENT_DEBILITATING:
                DoCast(SPELL_DEBILITATING);
                events.RescheduleEvent(EVENT_DEBILITATING, 13000);
                break;
            case EVENT_BIND:
                DoCast(SPELL_BIND);
                events.RescheduleEvent(EVENT_BIND, 13000);
                break;
            }

        }
        DoMeleeAttackIfReady();
    }
private:
    EventMap events;
    InstanceScript* instance;
};

//97365
struct npc_mos_seacursed_mistmender : public ScriptedAI
{
    npc_mos_seacursed_mistmender(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, urandms(1, 2));
        events.RescheduleEvent(EVENT_2, 1000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCastVictim(194610);
                events.RescheduleEvent(EVENT_1, urandms(6, 7));
                break;
            case EVENT_2:
            {
                std::list<Creature*> creatureList;
                me->GetCreatureListWithEntryInGrid(creatureList, 97097, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 97200, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 98919, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 99307, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 97365, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 99033, 30.0f);

                if (!creatureList.empty())
                {
                    for (auto creature : creatureList)
                    {
                        if (creature->IsInCombat() && creature->HealthBelowPct(80))
                        {
                            me->CastSpell(creature, 199514);
                            events.RescheduleEvent(EVENT_2, urandms(17, 19));
                            break;
                        }
                        else
                            events.RescheduleEvent(EVENT_2, 1000);
                    }
                }
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//99033
struct npc_mos_helarjar_mistcaller : public ScriptedAI
{
    npc_mos_helarjar_mistcaller(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, urandms(1, 2));
        events.RescheduleEvent(EVENT_2, urandms(5, 6));
        events.RescheduleEvent(EVENT_3, 1000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCastVictim(194610);
                events.RescheduleEvent(EVENT_1, urandms(6, 7));
                break;
            case EVENT_2:
                DoCast(199589);
                events.RescheduleEvent(EVENT_2, urandms(17, 19));
                break;
            case EVENT_3:
            {
                std::list<Creature*> creatureList;
                me->GetCreatureListWithEntryInGrid(creatureList, 97097, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 97200, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 98919, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 99307, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 97365, 30.0f);
                me->GetCreatureListWithEntryInGrid(creatureList, 99033, 30.0f);

                if (!creatureList.empty())
                {
                    for (auto creature : creatureList)
                    {
                        if (creature->IsInCombat() && creature->HealthBelowPct(40))
                        {
                            me->CastSpell(creature, 216197);
                            events.RescheduleEvent(EVENT_3, urandms(24, 25));
                            break;
                        }
                        else
                            events.RescheduleEvent(EVENT_3, 1000);
                    }
                }

                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//195309
class spell_helya_swirling_water : public SpellScript
{
    PrepareSpellScript(spell_helya_swirling_water);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (auto caster = GetCaster()->ToPlayer())
        {
            caster->AddAura(SPELL_SWIRLING_POOL_JUMP, caster);

            caster->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                Unit* caster = GetCaster()->ToPlayer();
                if (!caster)
                    return;

                if (caster && caster->IsAlive() && caster->GetPositionZ() < 512.0f)
                {
                    float x, y, z;
                    caster->GetClosePoint(x, y, z, caster->GetObjectSize(), 5.0f, frand(0.0f, 6.28f));
                    caster->GetMotionMaster()->MoveCharge(x, y, z + 10.0f, 15.0f);
                }
            });
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_helya_swirling_water::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//200208
class spell_brackwater : public AuraScript
{
    PrepareAuraScript(spell_brackwater);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;

        if (auto pTarget = GetTarget()->FindNearestCreature(98919, 40.0f, true))
            pTarget->CastSpell(GetTarget(), 201397, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_brackwater::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//197752
class spell_helya_turbulent_waters : public SpellScript
{
    PrepareSpellScript(spell_helya_turbulent_waters);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_0);

        if (!GetCaster())
            return;

        Position pos;
        GetCaster()->GetRandomNearPosition(30.0f);
        WorldLocation* dest = const_cast<WorldLocation*>(GetExplTargetDest());
        dest->Relocate(pos);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_helya_turbulent_waters::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

//197262
class spell_helya_taint_of_the_sea : public AuraScript
{
    PrepareAuraScript(spell_helya_taint_of_the_sea);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster() || !GetTarget())
            return;

        if (GetCaster()->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL && GetCaster()->IsInCombat())
            GetCaster()->CastSpell(GetTarget(), SPELL_TAINTED_ESSENCE, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_helya_taint_of_the_sea::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};


//trash 199589
class spell_whirpool_of_souls : public AuraScript
{
    PrepareAuraScript(spell_whirpool_of_souls);

    Position pos;

    void OnPereodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        PreventDefaultAction();
        for (uint8 itr = 0; itr < 3; ++itr)
        {
            GetCaster()->GetNearPosition(2.0f, frand(0.0f, 360.0f));
            GetCaster()->CastSpell(pos, 199516, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_whirpool_of_souls::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//trash 199514
class spell_torrent_of_souls : public AuraScript
{
    PrepareAuraScript(spell_torrent_of_souls);

    void OnPereodic(AuraEffect const* aurEff)
    {
        if (!GetCaster() || !GetTarget())
            return;

        for (uint8 itr = 0; itr < 3; ++itr)
            GetCaster()->CastSpell(GetTarget(), 199516, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_torrent_of_souls::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_helya_maw()
{
    RegisterCreatureAI(boss_helya);
    RegisterCreatureAI(npc_helya_tentacle);
    RegisterCreatureAI(npc_helya_tentacle_veh);
    RegisterCreatureAI(npc_helya_destructor_tentacle_veh);
    RegisterCreatureAI(npc_skyal);
    RegisterCreatureAI(npc_mos_seacursed_mistmender);
    RegisterCreatureAI(npc_mos_helarjar_mistcaller);
    RegisterSpellScript(spell_helya_swirling_water);
    RegisterAuraScript(spell_brackwater);
    RegisterSpellScript(spell_helya_turbulent_waters);
    RegisterAuraScript(spell_helya_taint_of_the_sea);
    RegisterAuraScript(spell_whirpool_of_souls);
    RegisterAuraScript(spell_torrent_of_souls);
}
