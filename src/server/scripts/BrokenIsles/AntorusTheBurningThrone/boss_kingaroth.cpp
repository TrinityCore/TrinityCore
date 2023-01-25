#include "AreaTriggerAI.h"
#include "antorus.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_RUINER = 1,
    SAY_REVERBERATING_STRIKE = 2,
    SAY_WARN_PHASE_2 = 3,
    SAY_PHASE_2 = 4,
    SAY_PHASE_2_PREPARE_TRAP = 5,
    SAY_PHASE_2_END = 6,
    SAY_DEATH = 7,
    SAY_WARN_EMPOWERED_RUINER = 8,
    SAY_WARN_EMPOWERED_REVERBERATING = 9,
    SAY_WARN_EMPOWERED_DIABOLIC_BOMB = 10,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249807,
    SPELL_ENERGIZE_PERIODIC = 248303,
    SPELL_FORGING_STRIKE = 254919,
    SPELL_FORGING_STRIKE_LFR = 257978,
    SPELL_REVERBERATING_STRIKE = 254926,
    SPELL_REVERBERATING_STRIKE_LFR = 257997,
    SPELL_DIABOLIC_BOMB = 248214,
    SPELL_RUINER_FILTER = 246793,
    SPELL_RUINER_SUMMON = 246798,
    SPELL_RUINER_CHANNEL = 246833,
    SPELL_SHATTERING_STRIKE_1 = 248375,
    SPELL_SHATTERING_STRIKE_2 = 254900,
    SPELL_DAILY_ESSENCE_KINGAROTH = 305313,

    //Phase 2
    SPELL_APOCALYPSE_PROTOCOL = 246516,
    SPELL_REAVER_SPAWN = 246511,
    SPELL_INITIALIZING = 246504,
    SPELL_FEEDBACK_OVERLOAD = 258643,
    SPELL_APOCALYPSE_BLAST_FILTER = 246599,
    SPELL_APOCALYPSE_BLAST_MISSILE = 246629,

    //Mythic
    SPELL_WEAPONS_UPGRADE = 249920,
    SPELL_EMPOWERED_REVERBERATING = 254795,
    SPELL_EMPOWERED_DIABOLIC_BOMB = 254796,
    SPELL_EMPOWERED_RUINER = 254797,
    SPELL_OVERCHARGE = 249740,
    SPELL_RUINATION_SUMMON = 249425,
    SPELL_RUINATION_AT = 249429,
    SPELL_RUINATION_IN_AT = 249430,
    SPELL_RUINATION_MISSILE = 249453,
    SPELL_RUINATION_DMG = 249455,
    SPELL_RUINATION_BLAST = 249458,
    SPELL_REVER_DECIMATION_FILTER = 249680,
    SPELL_REVER_DECIMATION_MISSILE = 249686,
    SPELL_DEMOLISHED = 249535,

    // NPC_DETONATION_CHARGE
    SPELL_FIRE_MINE_VISUAL = 244313,
    SPELL_FLAME_REVERBERATION = 244328,

    // NPC_INCINERATOR_STALKER
    SPELL_PURGING_PROTOCOL = 248048,
    SPELL_PURGING_PROTOCOL_2 = 258020,

    // NPC_GAROTHI_ANNIHILATOR
    SPELL_ANNIHILATION = 246657,
    SPELL_ANNIHILATION_SUMMON = 246659,
    SPELL_ANNIHILATION_MISSILE = 246661,
    SPELL_ANNIHILATION_DMG = 246664,
    SPELL_ANNIHILATION_BLAST = 246666,
    SPELL_ANNIHILATION_AT = 246667,
    SPELL_ANNIHILATION_IN_AT = 246670,

    // NPC_GAROTHI_DECIMATOR
    SPELL_DECIMATION_FILTER = 246686,
    SPELL_DECIMATION_MARK = 246687,
    SPELL_DECIMATION_MISSILE = 246689,

    // NPC_GAROTHI_DEMOLISHER
    SPELL_DEMOLISH_FILTER = 246692,
    SPELL_DEMOLISH_MARK = 246698,
    SPELL_DEMOLISH_DMG = 246706,
};

enum eEvents
{
    EVENT_FORGING_STRIKE = 1,
    EVENT_REVERBERATING_STRIKE = 2,
    EVENT_DIABOLIC_BOMB = 3,
    EVENT_RUINER = 4,
    EVENT_CHECK_NEAREST_PLAYER = 5,
    EVENT_PHASE_2 = 6,
};

Position const summonPos[11] =
{
    {-10574.7f, 8028.3f, 1873.67f, 1.57f}, // NPC_INCINERATOR_STALKER
    {-10632.0f, 8140.1f, 1873.67f, 5.67f},
    {-10517.4f, 8140.1f, 1873.67f, 3.75f},

    {-10574.8f, 8023.36f, 1873.18f, 0.0f}, // NPC_INFERNAL_TOWER_1
    {-10637.3f, 8142.35f, 1873.18f, 4.12f},
    {-10512.4f, 8144.02f, 1873.18f, 2.16f},

    // Garothi
    {-10635.07f, 8142.42f, 1873.17f, 5.65f}, // Left Side
    {-10514.54f, 8142.44f, 1873.17f, 3.76f}, // Right Side
    {-10574.77f, 8024.12f, 1873.14f, 1.57f}, // Back Side

    {-10612.7f, 8025.21f, 1915.17f, 0.0f}, // NPC_APOCALYPSE_BLAST_STALKER
    {-10535.1f, 8025.50f, 1916.21f, 0.0f}
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};
//122578
struct boss_kingaroth : BossAI
{
    explicit boss_kingaroth(Creature* creature) : BossAI(creature, DATA_KINGAROTH)
    {
        SetCombatMovement(false);
        //me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_STAND_STATE_STAND);
        //me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_TALENTS, 0);
        //me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, 0);
        //me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, 2);
    }

    bool phaseConstruction = false;
    uint8 phaseCount = 0;
    uint8 garothiDiedCount = 0;
    uint32 garothiLastEntry = 0;

    void Reset() override
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveAllAuras();
        me->SetPower(POWER_ENERGY, 75);
        phaseConstruction = false;
        phaseCount = 0;
        garothiDiedCount = 0;
        garothiLastEntry = 0;

        std::list<GameObject*> objectList;
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_BACK_2, 200.0f);
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_BACK_1, 200.0f);
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_RIGHT_2, 200.0f);
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_RIGHT_1, 200.0f);
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_LEFT_1, 200.0f);
        me->GetGameObjectListWithEntryInGrid(objectList, GO_KINGAROTH_TRAP_LEFT_2, 200.0f);
        if (!objectList.empty())
        {
            for (auto object : objectList)
                object->SetGoState(GO_STATE_ACTIVE);
        }

        for (uint8 i = 0; i < 3; ++i)
        {
            me->SummonCreature(NPC_INCINERATOR_STALKER, summonPos[i]);
            me->SummonCreature(NPC_INFERNAL_TOWER_1, summonPos[i + 3]);
        }
        me->SummonCreature(NPC_APOCALYPSE_BLAST_STALKER, summonPos[9]);
        me->SummonCreature(NPC_APOCALYPSE_BLAST_STALKER, summonPos[10]);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_ENERGIZE_PERIODIC, true);
        DefaultEvents(true);

        //DoActionSummon(NPC_INCINERATOR_STALKER, ACTION_1); //Cast AT
    }

    void DefaultEvents(bool JustEngagedWith = false)
    {
        if (JustEngagedWith)
        {
            events.RescheduleEvent(EVENT_FORGING_STRIKE, 6000);
            events.RescheduleEvent(EVENT_REVERBERATING_STRIKE, 14000);
            events.RescheduleEvent(EVENT_DIABOLIC_BOMB, 14000);
            events.RescheduleEvent(EVENT_RUINER, 26000);
        }
        else
        {
            events.RescheduleEvent(EVENT_FORGING_STRIKE, 1000);
            events.RescheduleEvent(EVENT_REVERBERATING_STRIKE, 2000);
            events.RescheduleEvent(EVENT_DIABOLIC_BOMB, 20000);
            events.RescheduleEvent(EVENT_RUINER, 22000);
        }
        events.RescheduleEvent(EVENT_CHECK_NEAREST_PLAYER, 3000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        me->StopMoving();
        me->SetDisableGravity(true);

        AddDelayedEvent(3000, [this]() -> void
        {
            me->CastSpell(me, SPELL_OUTRO_CONV, true);
        });
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_RUINER)
            me->CastSpell(summon, SPELL_RUINER_CHANNEL);
    }

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_1 && !phaseConstruction)
        {
            phaseConstruction = true;
            events.Reset();
            events.RescheduleEvent(EVENT_PHASE_2, 500);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_RUINER_FILTER:
        {
            Position pos;
            me->GetNearPosition(35.0f, me->GetRelativeAngle(target));
            me->CastSpell(pos, SPELL_RUINER_SUMMON, true);
            break;
        }
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_REVERBERATING_STRIKE:
        {
            //DoActionSummon(NPC_DETONATION_CHARGE, ACTION_1);
            if (me->HasAura(SPELL_EMPOWERED_REVERBERATING))
                me->CastSpell(me, SPELL_REVER_DECIMATION_FILTER, true);
            break;
        }
        case SPELL_SHATTERING_STRIKE_1:
            me->CastSpell(me, SPELL_SHATTERING_STRIKE_2, true);
            break;
        case SPELL_APOCALYPSE_PROTOCOL:
            GarothiInstall();
            break;
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (!me->IsInCombat() || apply)
            return;

        if (spellId == SPELL_APOCALYPSE_PROTOCOL)
        {
            Talk(SAY_PHASE_2_END);
            //DoActionSummon(NPC_INCINERATOR_STALKER, ACTION_1); //Cast AT
            //DoActionSummon(NPC_INFERNAL_TOWER_1, ACTION_2); //Move Down
            me->SetReactState(REACT_AGGRESSIVE);
            DefaultEvents();
            phaseConstruction = false;
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_REVER_DECIMATION_FILTER:
            me->CastSpell(target, SPELL_REVER_DECIMATION_MISSILE, true);
            break;
        case SPELL_RUINER_CHANNEL:
            me->SetReactState(REACT_AGGRESSIVE);
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
    {
        switch (summon->GetEntry())
        {
        case NPC_GAROTHI_ANNIHILATOR:
        case NPC_GAROTHI_DECIMATOR:
        case NPC_GAROTHI_DEMOLISHER:
        {
            me->CastSpell(me, SPELL_FEEDBACK_OVERLOAD, true);

            if (IsMythicRaid())
            {
                if (++garothiDiedCount == 3)
                {
                    garothiDiedCount = 0;

                    if (garothiLastEntry == summon->GetEntry())
                        me->CastSpell(me, SPELL_OVERCHARGE, true);
                    else
                    {
                        garothiLastEntry = summon->GetEntry();
                        me->CastSpell(me, SPELL_WEAPONS_UPGRADE, true);

                        if (summon->GetEntry() == NPC_GAROTHI_ANNIHILATOR && !me->HasAura(SPELL_EMPOWERED_RUINER))
                        {
                            me->CastSpell(me, SPELL_EMPOWERED_RUINER, true);
                            Talk(SAY_WARN_EMPOWERED_RUINER);
                        }
                        if (summon->GetEntry() == NPC_GAROTHI_DECIMATOR && !me->HasAura(SPELL_EMPOWERED_REVERBERATING))
                        {
                            me->CastSpell(me, SPELL_EMPOWERED_REVERBERATING, true);
                            Talk(SAY_WARN_EMPOWERED_REVERBERATING);
                        }
                        if (summon->GetEntry() == NPC_GAROTHI_DEMOLISHER && !me->HasAura(SPELL_EMPOWERED_DIABOLIC_BOMB))
                        {
                            me->CastSpell(me, SPELL_EMPOWERED_DIABOLIC_BOMB, true);
                            Talk(SAY_WARN_EMPOWERED_DIABOLIC_BOMB);
                        }
                    }
                }
            }
            break;
        }
        }
    }

    void GarothiInstall()
    {
        if (IsHeroicPlusRaid())
        {
            switch (phaseCount)
            {
            case 0:
                me->SummonCreature(NPC_GAROTHI_DECIMATOR, summonPos[6]);
                me->SummonCreature(NPC_GAROTHI_DEMOLISHER, summonPos[7]);
                me->SummonCreature(NPC_GAROTHI_ANNIHILATOR, summonPos[8]);
                break;
            case 1:
                me->SummonCreature(NPC_GAROTHI_ANNIHILATOR, summonPos[6]);
                me->SummonCreature(NPC_GAROTHI_DEMOLISHER, summonPos[7]);
                me->SummonCreature(NPC_GAROTHI_ANNIHILATOR, summonPos[8]);
                break;
            case 2:
                me->SummonCreature(NPC_GAROTHI_DECIMATOR, summonPos[6]);
                me->SummonCreature(NPC_GAROTHI_DECIMATOR, summonPos[7]);
                me->SummonCreature(NPC_GAROTHI_ANNIHILATOR, summonPos[8]);
                break;
            }
        }
        else
        {
            switch (phaseCount)
            {
            case 0:
                me->SummonCreature(NPC_GAROTHI_DECIMATOR, summonPos[6]);
                me->SummonCreature(NPC_GAROTHI_DEMOLISHER, summonPos[7]);
                break;
            case 1:
                me->SummonCreature(NPC_GAROTHI_ANNIHILATOR, summonPos[7]);
                me->SummonCreature(NPC_GAROTHI_DEMOLISHER, summonPos[8]);
                break;
            case 2:
                me->SummonCreature(NPC_GAROTHI_DEMOLISHER, summonPos[8]);
                me->SummonCreature(NPC_GAROTHI_DECIMATOR, summonPos[6]);
                break;
            }
        }

        if (++phaseCount == 3)
            phaseCount = 0;
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
            case EVENT_FORGING_STRIKE:
                me->CastSpell(me->GetVictim(), IsLFR() ? SPELL_FORGING_STRIKE_LFR : SPELL_FORGING_STRIKE);
                events.RescheduleEvent(EVENT_FORGING_STRIKE, 14000);
                break;
            case EVENT_REVERBERATING_STRIKE:
                Talk(SAY_REVERBERATING_STRIKE);
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return me->IsWithinMeleeRange(t); }))
                    DoCast(target, IsLFR() ? SPELL_REVERBERATING_STRIKE_LFR : SPELL_REVERBERATING_STRIKE);
                else
                    me->CastSpell(target, IsLFR() ? SPELL_REVERBERATING_STRIKE_LFR : SPELL_REVERBERATING_STRIKE);
                events.RescheduleEvent(EVENT_REVERBERATING_STRIKE, 30000);
                break;
            case EVENT_DIABOLIC_BOMB:
                DoCast(SPELL_DIABOLIC_BOMB);
                events.RescheduleEvent(EVENT_DIABOLIC_BOMB, 20000);
                break;
            case EVENT_RUINER:
            {
                if (me->HasAura(SPELL_EMPOWERED_RUINER))
                {
                    Position pos;
                    float angle = frand(0.0f, 6.28f);
                    for (uint8 i = 0; i < 5; ++i)
                    {
                        me->GetNearPosition(40.0f, angle);
                        angle += frand(1.0f, 1.25f);
                        me->CastSpell(pos, SPELL_RUINATION_SUMMON, true);
                        me->CastSpell(pos, SPELL_RUINATION_MISSILE, true);
                    }
                }
                Talk(SAY_RUINER);
                me->AttackStop();
                me->CastSpell(me, SPELL_RUINER_FILTER);
                events.RescheduleEvent(EVENT_RUINER, 30000);
                events.RescheduleEvent(EVENT_CHECK_NEAREST_PLAYER, 12000);
                break;
            }
            case EVENT_CHECK_NEAREST_PLAYER:
            {
                events.RescheduleEvent(EVENT_CHECK_NEAREST_PLAYER, 1500);

                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    if (auto target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 60.0f, true, false))
                    {
                        if (me->IsWithinMeleeRange(target))
                        {
                            ModifyThreatByPercent(me->GetVictim(), -100);
                            AddThreat(target, 10000.0f);
                            AttackStart(target);
                            return;
                        }
                        else if (me->GetExactDist2d(target) >= 50.0f)
                        {
                            EnterEvadeMode();
                            return;
                        }
                        DoCast(SPELL_SHATTERING_STRIKE_1);
                    }
                    else
                        EnterEvadeMode();
                }
                break;
            }
            case EVENT_PHASE_2:
            {
                Talk(SAY_WARN_PHASE_2);
                Talk(SAY_PHASE_2);
                me->AttackStop();
                me->CastSpell(me, SPELL_APOCALYPSE_PROTOCOL);
                //DoActionSummon(NPC_INCINERATOR_STALKER, ACTION_2); //Despawn AT
                //DoActionSummon(NPC_INFERNAL_TOWER_1, ACTION_1); //Move UP
                AddDelayedCombat(35000, [this]() -> void
                {
                    Talk(SAY_PHASE_2_PREPARE_TRAP);
                });
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//122585
struct npc_kingaroth_detonation_charge : public ScriptedAI
{
    explicit npc_kingaroth_detonation_charge(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_FIRE_MINE_VISUAL, true);
    }

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_1)
            DoCast(me, SPELL_FLAME_REVERBERATION, true);
    }

    void UpdateAI(uint32 diff) override {}
};

//124230
struct npc_kingaroth_ruiner : public ScriptedAI
{
    explicit npc_kingaroth_ruiner(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetSpeed(MOVE_RUN, 0.8f);
    }

    void Reset() override {}

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RUINER_CHANNEL)
        {
            Position pos;
            Position path[6];
            float angle = caster->GetRelativeAngle(me);
            float direction = urand(0, 1) ? 0.3f : -0.3f;

            for (uint8 i = 0; i < 6; ++i)
            {
                caster->GetNearPosition(35.0f, angle);
                path[i] = Position(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                angle += direction;
            }

            me->GetMotionMaster()->MoveSmoothPath(1, path, 6, false);
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//124879
struct npc_kingaroth_incinerator_stalker : public ScriptedAI
{
    explicit npc_kingaroth_incinerator_stalker(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override {}

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_1)
        {
            DoCast(me, SPELL_PURGING_PROTOCOL, true);

            AddDelayedEvent(1000, [this]() -> void
            {
                CheckPlayers();
            });
        }

        if (actionID == ACTION_2)
        {
            me->RemoveAurasDueToSpell(SPELL_PURGING_PROTOCOL);
            me->RemoveAllAreaObjects();

            if (me->GetDistance(-10632.0f, 8140.10f, 1873.67f) < 5.0f)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_LEFT_1), true);
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_LEFT_2), true);
            }

            if (me->GetDistance(-10517.4f, 8140.1f, 1873.67f) < 5.0f)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_RIGHT_1), true);
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_RIGHT_2), true);
            }

            if (me->GetDistance(-10574.7f, 8028.2f, 1873.67f) < 5.0f)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_BACK_1), true);
                instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_BACK_2), true);
            }
        }
    }

    void CheckPlayers()
    {
        if (me->GetDistance(-10632.0f, 8140.10f, 1873.67f) < 5.0f)
        {
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_LEFT_1), false);
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_LEFT_2), false);
        }

        if (me->GetDistance(-10517.4f, 8140.1f, 1873.67f) < 5.0f)
        {
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_RIGHT_1), false);
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_RIGHT_2), false);
        }

        if (me->GetDistance(-10574.7f, 8028.2f, 1873.67f) < 5.0f)
        {
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_BACK_1), false);
            instance->HandleGameObject(instance->GetGuidData(GO_KINGAROTH_TRAP_BACK_2), false);
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//122634
struct npc_kingaroth_infernal_tower : public ScriptedAI
{
    explicit npc_kingaroth_infernal_tower(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override {}

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_1)
            me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20.0f);

        if (actionID == ACTION_2)
            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
    }

    void UpdateAI(uint32 diff) override {}
};

//125462
struct npc_kingaroth_apocalypse_blast_stalker : public ScriptedAI
{
    explicit npc_kingaroth_apocalypse_blast_stalker(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override {}

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_1)
            if (me->GetDistance(summonPos[9]) < 5.0f)
                me->CastSpell(me, SPELL_APOCALYPSE_BLAST_FILTER, true);

        if (actionID == ACTION_2)
            if (me->GetDistance(summonPos[10]) < 5.0f)
                me->CastSpell(me, SPELL_APOCALYPSE_BLAST_FILTER, true);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_APOCALYPSE_BLAST_FILTER)
            me->CastSpell(target, SPELL_APOCALYPSE_BLAST_MISSILE, true);
    }

    void UpdateAI(uint32 diff) override {}
};

//123906, 123921, 123929
struct npc_kingaroth_garothi : public ScriptedAI
{
    explicit npc_kingaroth_garothi(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    EventMap events;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 150.0f);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->SetPower(POWER_ENERGY, 0);
        me->CastSpell(me, SPELL_REAVER_SPAWN, true);
        me->CastSpell(me, SPELL_INITIALIZING, true);

        switch (me->GetEntry())
        {
        case NPC_GAROTHI_ANNIHILATOR:
            events.RescheduleEvent(EVENT_1, 45000);
            break;
        case NPC_GAROTHI_DECIMATOR:
            events.RescheduleEvent(EVENT_2, 45000);
            break;
        case NPC_GAROTHI_DEMOLISHER:
            events.RescheduleEvent(EVENT_3, 46000);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply)
            return;

        if (spellId == SPELL_INITIALIZING)
        {
            Position pos;
            me->GetNearPosition(40.0f, 0.0f);
            me->GetMotionMaster()->MovePoint(1, pos);
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_DEMOLISH_MARK:
            target->CastSpell(target, SPELL_DEMOLISH_DMG, true);
            break;
        case SPELL_DECIMATION_MARK:
            me->CastSpell(target, SPELL_DECIMATION_MISSILE, true);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_DECIMATION_FILTER:
            if (target->GetGUID() != me->GetGUID())
                me->CastSpell(target, SPELL_DECIMATION_MARK, true);
            break;
        case SPELL_DEMOLISH_FILTER:
            if (target->GetGUID() != me->GetGUID())
                me->CastSpell(target, SPELL_DEMOLISH_MARK, true);
            break;
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_ANNIHILATION)
        {
            uint8 maxPoint = 2;

            if (IsNormalRaid())
                maxPoint = 3;
            else if (IsHeroicRaid())
                maxPoint = 4;
            else if (IsMythicRaid())
                maxPoint = 5;

            std::list<Position> randPos;
            //me->GenerateCollisionNonDuplicatePoints(randPos, maxPoint, 5.0f, 30.0f, 5.0f);

            if (auto owner = me->GetOwner())
            {
                for (auto pos : randPos)
                {
                    me->CastSpell(pos, SPELL_ANNIHILATION_SUMMON, true);
                    me->CastSpell(pos, SPELL_ANNIHILATION_MISSILE, true);
                }
            }
        }
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
                DoCast(SPELL_ANNIHILATION);
                events.RescheduleEvent(EVENT_1, 14000);
                break;
            case EVENT_2:
                DoCast(SPELL_DECIMATION_FILTER);
                events.RescheduleEvent(EVENT_2, 16000);
                break;
            case EVENT_3:
                DoCast(SPELL_DEMOLISH_FILTER);
                events.RescheduleEvent(EVENT_3, 16000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//124160, 125646
struct npc_kingaroth_annihilation_trigger : public ScriptedAI
{
    explicit npc_kingaroth_annihilation_trigger(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        if (me->GetEntry() == NPC_ANNIHILATION_TRIGGER)
        {
            DoCast(me, SPELL_ANNIHILATION_AT, true);
        }
        else if (me->GetEntry() == NPC_EMPOWERED_RUINER_STALKER)
        {
            DoCast(me, SPELL_RUINATION_AT, true);
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//246754
class spell_kingaroth_diabolic_bomb : public SpellScript
{
    PrepareSpellScript(spell_kingaroth_diabolic_bomb);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster())
            return;

        WorldLocation loc;
        GetCaster()->GetNearPosition(frand(23.0f, 45.0f), frand(0.0f, 6.28f));
        SetExplTargetDest(loc);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_kingaroth_diabolic_bomb::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

//246779
class spell_kingaroth_diabolic_bomb_dmg : public SpellScript
{
    PrepareSpellScript(spell_kingaroth_diabolic_bomb_dmg);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();
        if (!caster || !target || !GetHitDest())
            return;

        float distance = GetHitDest()->GetExactDist2d(target) * 2.0f;
        uint8 pct = 25;
        if (distance <= 18.0f)
            pct = 100.0f - (distance * 4.0f);

        SetHitDamage(CalculatePct(GetHitDamage(), pct));

        if (auto instance = caster->GetInstanceScript())
        {
            if (auto kingaroth = instance->instance->GetCreature(instance->GetGuidData(NPC_KINGAROTH)))
                if (kingaroth->HasAura(SPELL_EMPOWERED_DIABOLIC_BOMB))
                    target->CastSpell(target, SPELL_DEMOLISHED, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kingaroth_diabolic_bomb_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//248303
class spell_kingaroth_energize_periodic : public AuraScript
{
    PrepareAuraScript(spell_kingaroth_energize_periodic);

    bool firstTick = true;
    int8 tickCount = 0;
    uint8 powerCount = 0;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster || !caster->IsInCombat())
            return;

        if (tickCount-- == 0)
        {
            if (firstTick)
            {
                firstTick = false;
                tickCount = 5;
            }
            else
                tickCount = 6;
            return;
        }

        powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
            caster->SetPower(POWER_ENERGY, ++powerCount);
        else
            caster->GetAI()->DoAction(true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kingaroth_energize_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//246516
class spell_kingaroth_apocalypse_protocol : public AuraScript
{
    PrepareAuraScript(spell_kingaroth_apocalypse_protocol);

    void OnTick(AuraEffect const* aurEff)
    {
        if (auto caster = GetCaster())
            caster->GetAI()->DoAction(ACTION_2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kingaroth_apocalypse_protocol::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//246504
class spell_kingaroth_initializing : public AuraScript
{
    PrepareAuraScript(spell_kingaroth_initializing);

    void OnTick(AuraEffect const* aurEff)
    {
        aurEff->GetBase()->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kingaroth_initializing::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//Custom: 15701 (Entry: 10875 / 11149)
struct at_kingaroth_annihilation : AreaTriggerAI
{
    at_kingaroth_annihilation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void ActionOnUpdate(GuidList& affectedPlayers)
    {
        auto owner = at->GetCaster();
        if (!owner)
            return;

        if (affectedPlayers.empty())
        {
            if (at->GetEntry() == 10875) //Annihilation
            {
                if (!owner->HasAura(SPELL_ANNIHILATION_IN_AT))
                    owner->CastSpell(owner, SPELL_ANNIHILATION_IN_AT, true);
            }
            else if (at->GetEntry() == 11149) //Ruination
            {
                if (!owner->HasAura(SPELL_RUINATION_IN_AT))
                    owner->CastSpell(owner, SPELL_RUINATION_IN_AT, true);
            }
        }
        else
        {
            if (at->GetEntry() == 10875) //Annihilation
            {
                if (owner->HasAura(SPELL_ANNIHILATION_IN_AT))
                    owner->RemoveAurasDueToSpell(SPELL_ANNIHILATION_IN_AT);
            }
            else if (at->GetEntry() == 11149) //Ruination
            {
                if (owner->HasAura(SPELL_RUINATION_IN_AT))
                    owner->RemoveAurasDueToSpell(SPELL_RUINATION_IN_AT);
            }
        }
    }
};

void AddSC_boss_kingaroth()
{
    RegisterCreatureAI(boss_kingaroth);
    RegisterCreatureAI(npc_kingaroth_detonation_charge);
    RegisterCreatureAI(npc_kingaroth_ruiner);
    RegisterCreatureAI(npc_kingaroth_incinerator_stalker);
    RegisterCreatureAI(npc_kingaroth_infernal_tower);
    RegisterCreatureAI(npc_kingaroth_apocalypse_blast_stalker);
    RegisterCreatureAI(npc_kingaroth_garothi);
    RegisterCreatureAI(npc_kingaroth_annihilation_trigger);
    RegisterSpellScript(spell_kingaroth_diabolic_bomb);
    RegisterSpellScript(spell_kingaroth_diabolic_bomb_dmg);
    RegisterAuraScript(spell_kingaroth_energize_periodic);
    RegisterAuraScript(spell_kingaroth_apocalypse_protocol);
    RegisterAuraScript(spell_kingaroth_initializing);
    RegisterAreaTriggerAI(at_kingaroth_annihilation);
}
