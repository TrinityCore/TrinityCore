/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "obsidian_sanctum.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Enums
{
    //Sartharion Yell
    SAY_SARTHARION_AGGRO                        = 0,
    SAY_SARTHARION_BERSERK                      = 1,
    SAY_SARTHARION_BREATH                       = 2,
    SAY_SARTHARION_CALL_SHADRON                 = 3,
    SAY_SARTHARION_CALL_TENEBRON                = 4,
    SAY_SARTHARION_CALL_VESPERON                = 5,
    SAY_SARTHARION_DEATH                        = 6,
    SAY_SARTHARION_SPECIAL                      = 7,
    SAY_SARTHARION_SLAY                         = 8,
    WHISPER_LAVA_CHURN                          = 9,

    //Sartharion Spells
    SPELL_BERSERK                               = 61632,    // Increases the caster's attack speed by 150% and all damage it deals by 500% for 5 min.
    SPELL_CLEAVE                                = 56909,    // Inflicts 35% weapon damage to an enemy and its nearest allies, affecting up to 10 targets.
    SPELL_FLAME_BREATH                          = 56908,    // Inflicts 8750 to 11250 Fire damage to enemies in a cone in front of the caster.
    SPELL_TAIL_LASH                             = 56910,    // A sweeping tail strike hits all enemies behind the caster, inflicting 3063 to 3937 damage and stunning them for 2 sec.
    SPELL_WILL_OF_SARTHARION                    = 61254,    // Sartharion's presence bolsters the resolve of the Twilight Drakes, increasing their total health by 25%. This effect also increases Sartharion's health by 25%.
    SPELL_LAVA_STRIKE                           = 57571,    // (Real spell cast should be 57578) 57571 then trigger visual missile, then summon Lava Blaze on impact(spell 57572)
    SPELL_TWILIGHT_REVENGE                      = 60639,
    NPC_FIRE_CYCLONE                            = 30648,

    SPELL_PYROBUFFET                            = 56916,    // currently used for hard enrage after 15 minutes
    SPELL_PYROBUFFET_RANGE                      = 58907,    // possibly used when player get too far away from dummy creatures (2x Creature entry 30494)

    //Vesperon
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_VESPERON                     = 31219,    // Acolyte of Vesperon
    SPELL_POWER_OF_VESPERON                     = 61251,    // Vesperon's presence decreases the maximum health of all enemies by 25%.

    //Shadron
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_SHADRON                      = 31218,    // Acolyte of Shadron
    SPELL_POWER_OF_SHADRON                      = 58105,    // Shadron's presence increases Fire damage taken by all enemies by 100%.

    //Tenebron
    //in the portal spawns 6 eggs, if not killed in time (approx. 20s)  they will hatch,  whelps can cast 60708
    SPELL_POWER_OF_TENEBRON                     = 61248,    // Tenebron's presence increases Shadow damage taken by all enemies by 100%.

    NPC_FLAME_TSUNAMI                           = 30616,    // for the flame waves

    //using these custom points for dragons start and end
    POINT_ID_INIT                               = 100,
    POINT_ID_LAND                               = 200
};

enum Misc
{
    DATA_CAN_LOOT           = 0
};

Position const FlameRight1Spawn     = { 3200.00f, 573.211f, 57.1551f, 0.0f };
Position const FlameRight1Direction = { 3289.28f, 573.211f, 57.1551f, 0.0f };
Position const FlameRight2Spawn     = { 3200.00f, 532.211f, 57.1551f, 0.0f };
Position const FlameRight2Direction = { 3289.28f, 532.211f, 57.1551f, 0.0f };
Position const FlameRight3Spawn     = { 3200.00f, 491.211f, 57.1551f, 0.0f };
Position const FlameRight3Direction = { 3289.28f, 491.211f, 57.1551f, 0.0f };
Position const FlameLeft1Spawn      = { 3289.28f, 511.711f, 57.1551f, 0.0f };
Position const FlameLeft1Direction  = { 3200.00f, 511.711f, 57.1551f, 0.0f };
Position const FlameLeft2Spawn      = { 3289.28f, 552.711f, 57.1551f, 0.0f };
Position const FlameLeft2Direction  = { 3200.00f, 552.711f, 57.1551f, 0.0f };

//each dragons special points. First where fly to before connect to connon, second where land point is.
Position const TenebronPositions[] =
{
    { 3212.854f, 575.597f, 109.856f, 0.0f }, // init
    { 3246.425f, 565.367f, 61.249f,  0.0f }  // end
};

Position const ShadronPositions[] =
{
    { 3293.238f, 472.223f, 106.968f, 0.0f },
    { 3271.669f, 526.907f, 61.931f,  0.0f }
};

Position const VesperonPositions[] =
{
    { 3193.310f, 472.861f, 102.697f, 0.0f },
    { 3227.268f, 533.238f, 59.995f,  0.0f }
};

enum SartharionEvents
{
    EVENT_HARD_ENRAGE      = 1,
    EVENT_FLAME_TSUNAMI    = 2,
    EVENT_FLAME_BREATH     = 3,
    EVENT_TAIL_SWEEP       = 4,
    EVENT_CLEAVE_ATTACK    = 5,
    EVENT_LAVA_STRIKE      = 6,
    EVENT_CALL_TENEBRON    = 7,
    EVENT_CALL_SHADRON     = 8,
    EVENT_CALL_VESPERON    = 9
};

/*######
## Boss Sartharion
######*/

class boss_sartharion : public CreatureScript
{
public:
    boss_sartharion() : CreatureScript("boss_sartharion") { }

    struct boss_sartharionAI : public BossAI
    {
        boss_sartharionAI(Creature* creature) : BossAI(creature, DATA_SARTHARION)
        {
            Initialize();
        }

        void Initialize()
        {
            _isBerserk = false;
            _isSoftEnraged = false;
            _isHardEnraged = false;
            drakeCount = 0;
        }

        void Reset() override
        {
            Initialize();

            if (me->HasAura(SPELL_TWILIGHT_REVENGE))
                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_REVENGE);

            me->SetHomePosition(3246.57f, 551.263f, 58.6164f, 4.66003f);

            DrakeRespawn();
            instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);
        }

        void JustReachedHome() override
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_SARTHARION_AGGRO);
            _EnterCombat();
            DoZoneInCombat();

            FetchDragons();

            events.ScheduleEvent(EVENT_LAVA_STRIKE, 5000);
            events.ScheduleEvent(EVENT_CLEAVE_ATTACK, 7000);
            events.ScheduleEvent(EVENT_FLAME_BREATH, 20000);
            events.ScheduleEvent(EVENT_TAIL_SWEEP, 20000);
            events.ScheduleEvent(EVENT_FLAME_TSUNAMI, 30000);
            events.ScheduleEvent(EVENT_CALL_TENEBRON, 30000);
            events.ScheduleEvent(EVENT_CALL_SHADRON, 75000);
            events.ScheduleEvent(EVENT_CALL_VESPERON, 120000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_SARTHARION_DEATH);
            _JustDied();

            if (Creature* tenebron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TENEBRON)))
                if (tenebron->IsAlive())
                    tenebron->DisappearAndDie();

            if (Creature* shadron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
                if (shadron->IsAlive())
                    shadron->DisappearAndDie();

            if (Creature* vesperon = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VESPERON)))
                if (vesperon->IsAlive())
                    vesperon->DisappearAndDie();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SARTHARION_SLAY);
        }

        // me->ResetLootMode() is called from Reset()
        // AddDrakeLootMode() should only ever be called from FetchDragons(), which is called from Aggro()
        void AddDrakeLootMode()
        {
            if (me->HasLootMode(LOOT_MODE_HARD_MODE_2))      // Has two Drake loot modes
                me->AddLootMode(LOOT_MODE_HARD_MODE_3);      // Add 3rd Drake loot mode
            else if (me->HasLootMode(LOOT_MODE_HARD_MODE_1)) // Has one Drake loot mode
                me->AddLootMode(LOOT_MODE_HARD_MODE_2);      // Add 2nd Drake loot mode
            else                                             // Has no Drake loot modes
                me->AddLootMode(LOOT_MODE_HARD_MODE_1);      // Add 1st Drake loot mode
        }

        void DrakeRespawn() // Drakes respawning system
        {
            if (Creature* tenebron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TENEBRON)))
            {
                tenebron->SetHomePosition(3239.07f, 657.235f, 86.8775f, 4.74729f);
                if (tenebron->IsAlive())
                {
                    tenebron->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    tenebron->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if (instance->GetBossState(DATA_TENEBRON) != DONE)
                    {
                        tenebron->Respawn();
                        tenebron->GetMotionMaster()->MoveTargetedHome();
                        tenebron->AI()->SetData(DATA_CAN_LOOT, 0);
                    }
                }
            }

            if (Creature* shadron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
            {
                shadron->SetHomePosition(3363.06f, 525.28f, 98.362f, 4.76475f);
                if (shadron->IsAlive())
                {
                    shadron->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    shadron->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if (instance->GetBossState(DATA_SHADRON) != DONE)
                    {
                        shadron->Respawn();
                        shadron->GetMotionMaster()->MoveTargetedHome();
                        shadron->AI()->SetData(DATA_CAN_LOOT, 0);
                    }
                }
            }

            if (Creature* vesperon = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VESPERON)))
            {
                vesperon->SetHomePosition(3145.68f, 520.71f, 89.7f, 4.64258f);
                if (vesperon->IsAlive())
                {
                    vesperon->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    vesperon->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if (instance->GetBossState(DATA_VESPERON) != DONE)
                    {
                        vesperon->Respawn();
                        vesperon->GetMotionMaster()->MoveTargetedHome();
                        vesperon->AI()->SetData(DATA_CAN_LOOT, 0);
                    }
                }
            }
        }

        void FetchDragons()
        {
            me->ResetLootMode();
            drakeCount = 0;

            //if at least one of the dragons are alive and are being called
            bool _canUseWill = false;

            if (Creature* fetchTene = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TENEBRON)))
            {
                if (fetchTene->IsAlive() && !fetchTene->GetVictim())
                {
                    _canUseWill = true;
                    if (!fetchTene->IsInCombat())
                    {
                        DoCast(me, SPELL_POWER_OF_TENEBRON);
                        AddDrakeLootMode();
                        ++drakeCount;
                    }
                    fetchTene->GetMotionMaster()->MovePoint(POINT_ID_INIT, TenebronPositions[0]);

                    fetchTene->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            if (Creature* fetchShad = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
            {
                if (fetchShad->IsAlive() && !fetchShad->GetVictim())
                {
                    _canUseWill = true;
                    if (!fetchShad->IsInCombat())
                    {
                        DoCast(me, SPELL_POWER_OF_SHADRON);
                        AddDrakeLootMode();
                        ++drakeCount;
                    }
                    fetchShad->GetMotionMaster()->MovePoint(POINT_ID_INIT, ShadronPositions[0]);

                    fetchShad->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            if (Creature* fetchVesp = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VESPERON)))
            {
                if (fetchVesp && fetchVesp->IsAlive() && !fetchVesp->GetVictim())
                {
                    _canUseWill = true;
                    if (!fetchVesp->IsInCombat())
                    {
                        DoCast(me, SPELL_POWER_OF_VESPERON);
                        AddDrakeLootMode();
                        ++drakeCount;
                    }
                    fetchVesp->GetMotionMaster()->MovePoint(POINT_ID_INIT, VesperonPositions[0]);

                    fetchVesp->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            if (_canUseWill)
                DoCast(me, SPELL_WILL_OF_SARTHARION);
        }

        void CallDragon(uint32 dataId)
        {
            if (Creature* temp = ObjectAccessor::GetCreature(*me, instance->GetGuidData(dataId)))
            {
                if (temp->IsAlive() && !temp->GetVictim())
                {
                    temp->SetWalk(false);

                    temp->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

                    uint8 textId = 0;

                    switch (temp->GetEntry())
                    {
                        case NPC_TENEBRON:
                            textId = SAY_SARTHARION_CALL_TENEBRON;
                            temp->AddAura(SPELL_POWER_OF_TENEBRON, temp);
                            temp->GetMotionMaster()->MovePoint(POINT_ID_LAND, TenebronPositions[1]);
                            break;
                        case NPC_SHADRON:
                            textId = SAY_SARTHARION_CALL_SHADRON;
                            temp->AddAura(SPELL_POWER_OF_SHADRON, temp);
                            temp->GetMotionMaster()->MovePoint(POINT_ID_LAND, ShadronPositions[1]);
                            break;
                        case NPC_VESPERON:
                            textId = SAY_SARTHARION_CALL_VESPERON;
                            temp->AddAura(SPELL_POWER_OF_VESPERON, temp);
                            temp->GetMotionMaster()->MovePoint(POINT_ID_LAND, VesperonPositions[1]);
                            break;
                    }

                    Talk(textId);
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TWILIGHT_ACHIEVEMENTS)
                return drakeCount;

            return 0;
        }

        // Selects a random Fire Cyclone and makes it cast Lava Strike.
        // FIXME: Frequency of the casts reduced to compensate 100% chance of spawning a Lava Blaze add
        void CastLavaStrikeOnTarget(Unit* target)
        {
            std::list<Creature*> fireCyclonesList;
            Trinity::AllCreaturesOfEntryInRange checker(me, NPC_FIRE_CYCLONE, 200.0f);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, fireCyclonesList, checker);
            Cell::VisitAllObjects(me, searcher, 200.0f);

            if (fireCyclonesList.empty())
                return;

            Trinity::Containers::SelectRandomContainerElement(fireCyclonesList)->CastSpell(target, SPELL_LAVA_STRIKE, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HARD_ENRAGE:
                        if (!_isHardEnraged)
                        {
                            DoCast(me, SPELL_PYROBUFFET, true);
                            _isHardEnraged = true;
                        }
                        break;
                    case EVENT_FLAME_TSUNAMI:
                        Talk(WHISPER_LAVA_CHURN);
                        switch (urand(0, 1))
                        {
                            case 0:
                            {
                                if (Creature* right1 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight1Spawn, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    right1->GetMotionMaster()->MovePoint(0, FlameRight1Direction);
                                if (Creature* right2 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight2Spawn, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    right2->GetMotionMaster()->MovePoint(0, FlameRight2Direction);
                                if (Creature* right3 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight3Spawn, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    right3->GetMotionMaster()->MovePoint(0, FlameRight3Direction);
                                break;
                            }
                            case 1:
                            {
                                if (Creature* left1 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameLeft1Spawn, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    left1->GetMotionMaster()->MovePoint(0, FlameLeft1Direction);
                                if (Creature* left2 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameLeft2Spawn, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    left2->GetMotionMaster()->MovePoint(0, FlameLeft2Direction);
                                break;
                            }
                        }
                        events.ScheduleEvent(EVENT_FLAME_TSUNAMI, 30000);
                        break;
                    case EVENT_FLAME_BREATH:
                        Talk(SAY_SARTHARION_BREATH);
                        DoCastVictim(SPELL_FLAME_BREATH);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, urand(25000, 35000));
                        break;
                    case EVENT_TAIL_SWEEP:
                        DoCastVictim(SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(15000, 20000));
                        break;
                    case EVENT_CLEAVE_ATTACK:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE_ATTACK, urand(7000, 10000));
                        break;
                    case EVENT_LAVA_STRIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            CastLavaStrikeOnTarget(target);
                            if (urand(0, 5) == 0)
                                Talk(SAY_SARTHARION_SPECIAL);
                        }
                        events.ScheduleEvent(EVENT_LAVA_STRIKE, (_isSoftEnraged ? urand(1400, 2000) : urand(5000, 20000)));
                        break;
                    case EVENT_CALL_TENEBRON:
                        CallDragon(DATA_TENEBRON);
                        break;
                    case EVENT_CALL_SHADRON:
                        CallDragon(DATA_SHADRON);
                        break;
                    case EVENT_CALL_VESPERON:
                        CallDragon(DATA_VESPERON);
                        break;
                    default:
                        break;
                }
            }

            //  At 35% spell will target dragons, if they are still alive.
            if (!_isBerserk && !HealthAbovePct(35))
            {
                if (instance->GetBossState(DATA_TENEBRON) != DONE || instance->GetBossState(DATA_SHADRON) != DONE || instance->GetBossState(DATA_VESPERON) != DONE)
                {
                    Talk(SAY_SARTHARION_BERSERK);
                    DoCast(me, SPELL_BERSERK);
                    _isBerserk = true;
                }
            }

            // Soft Enrage used while determining Lava Strike cooldown.
            if (!_isSoftEnraged && HealthBelowPct(10))
            {
                _isSoftEnraged = true;
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool _isBerserk;
        bool _isSoftEnraged;
        bool _isHardEnraged;
        uint8 drakeCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetObsidianSanctumAI<boss_sartharionAI>(creature);
    }
};

void AddSC_boss_sartharion()
{
    new boss_sartharion();
}
