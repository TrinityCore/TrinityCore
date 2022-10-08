#include "siege_of_orgrimmar.hpp"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Spells
{
    SPELL_BERSERK               = 145525, // don't use 'castspell' because it's aoe spell

    SPELL_ZERO_POWER            = 96301,

    SPELL_SHA_BOOLT_AOE         = 143290, // targetting
    SPELL_SHA_BOLT_MISSILE      = 143293,
    SPELL_SHA_BOLT_DMG          = 143295,
    SPELL_SHA_SPLASH            = 143297,
    SPELL_SHA_SPLASH_AURA       = 143298,

    SPELL_SHA_POOL_AURA         = 143462,
    SPELL_SHA_POOL_SCRIPT       = 143461,
    SPELL_SHA_POOL_DMG          = 143460,

    SPELL_CORROSIVE_BLAST       = 143436,

    SPELL_SEEPING_SHA           = 143281,
    SPELL_SEEPING_SHA_DMG       = 143286,

    SPELL_SWIRL                 = 143309,
    SPELL_SWIRL_2               = 143410,
    SPELL_SWIRL_DMG             = 143412, // main swirl from the boss
    SPELL_SWIRL_DMG_2           = 143413, // errupting swirls on the ground
    SPELL_SWIRL_SCRIPT          = 143415,

    SPELL_SHA_CORRUPTION        = 143579,

    SPELL_SPLIT                 = 143020,
    SPELL_SPLIT_MISSILE_1       = 143022, // sha puddle
    SPELL_SPLIT_MISSILE_2       = 143024, // contaminated puddle
    SPELL_SPLIT_SUMMON_1        = 143453,
    SPELL_SPLIT_SUMMON_2        = 143454,

    SPELL_REFORM                = 143469,

    SPELL_SHA_RESIDUE           = 143459,
    SPELL_ERUPTING_SHA          = 143498,

    SPELL_CONGEALING            = 143538,
    SPELL_CONGEALING_AURA       = 143540,
    SPELL_PUTRIFIED_RESUDUE     = 143524,
    SPELL_PURIFIED              = 143523,
    SPELL_ERUPTING_WATER        = 145377,

    SPELL_SWELLING_CORRUPTION           = 143574, // on heroic
    SPELL_SWELLING_CORRUPTION_SCRIPT    = 143578, //
    SPELL_SHA_CORRUPTION_MISSILE        = 143580,
    SPELL_SWELLING_CORRUPTION_SUMMON    = 143581,
    SPELL_SHA_CORRUPTION_DMG            = 143579,

    SPELL_ACHIEVEMENT           = 145889,

};

enum Adds
{
    NPC_SHA_BOLT            = 71544,
    NPC_CONTAMINATED_PUDDLE = 71604,
    NPC_SHA_PUDDLE          = 71603,
    NPC_PURIFIED_PUDDLE     = 71605,
    NPC_SWIRL               = 71548,
    NPC_SHA_POOL            = 71611,
    NPC_CONGEALED_SHA       = 71642,
};

enum Events
{
    EVENT_SHA_BOLT  = 1,
    EVENT_CORROSIVE_BLAST,
    EVENT_SWIRL,
    EVENT_SPLIT,
    EVENT_REFORM,
    EVENT_REFORM_1,
    EVENT_CHECK_MELEE,
    EVENT_BERSERK,
    EVENT_SWELLING_CORRUPTION,
};

enum Timers
{
    TIMER_SWELLING_CORRUPTION_FIRST     = 10 * IN_MILLISECONDS,
    TIMER_SWELLING_CORRUPTION_FIRST_2   = 17 * IN_MILLISECONDS, // after reform
    TIMER_SWELLING_CORRUPTION           = 75 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_PUDDLE_DIED  = 1,
    ACTION_SPLIT,
    ACTION_REFORM,
    ACTION_MOVE_SWIRL,
    ACTION_MOVE_SHA_BOLT,
    ACTION_SHA_POOL_INCREASE,
    ACTION_SHA_POOL_DECREASE,
};

enum eData
{
    DATA_SHA_POOL   = 1,
};

enum Phases
{
    PHASE_IMMERSEUS_BOSS,
    PHASE_IMMERSEUS_ADDS
};

#define MAX_PUDDLE_POINTS 32
#define MAX_PUDDLES_IN_PHASE 25

const Position puddlePos[MAX_PUDDLE_POINTS] =
{
    {1455.601318f, 661.137329f, 246.85f, 0.356930f},
    {1461.414551f, 663.377380f, 246.86f, 0.378310f},
    {1474.600830f, 670.615051f, 246.86f, 0.665416f},
    {1488.301758f, 681.498596f, 246.84f, 0.741774f},
    {1507.742065f, 700.772583f, 246.84f, 1.041098f},
    {1513.817261f, 711.771057f, 246.84f, 1.065533f},
    {1519.040283f, 723.025330f, 246.84f, 1.270173f},
    {1522.439209f, 735.315369f, 246.84f, 1.380130f},
    {1523.098755f, 758.624695f, 246.84f, 1.624478f},
    {1522.009155f, 773.242310f, 246.84f, 1.719162f},
    {1518.275269f, 785.543518f, 246.84f, 2.003216f},
    {1511.928223f, 796.272034f, 246.84f, 2.189532f},
    {1491.666260f, 816.293823f, 246.84f, 2.470533f},
    {1481.050903f, 824.383911f, 246.84f, 2.601870f},
    {1469.224731f, 829.512512f, 246.84f, 2.922577f},
    {1459.451416f, 830.224121f, 246.84f, 2.968393f},
    {1447.282104f, 831.876282f, 246.84f, 3.060024f},
    {1432.209229f, 832.271667f, 246.84f, 3.182199f},
    {1415.996948f, 830.680725f, 246.84f, 3.389895f},
    {1400.198120f, 823.627197f, 246.84f, 3.689223f},
    {1377.474243f, 803.850769f, 246.84f, 4.135154f},
    {1368.328491f, 789.614624f, 246.84f, 4.208457f},
    {1364.697388f, 780.012390f, 246.84f, 4.443637f},
    {1361.294556f, 767.282104f, 246.84f, 4.483343f},
    {1360.805664f, 745.632629f, 246.76f, 4.837642f},
    {1361.920898f, 736.954041f, 246.84f, 4.840696f},
    {1365.434937f, 720.942383f, 246.84f, 5.100311f},
    {1372.835083f, 707.264648f, 246.84f, 5.338545f},
    {1391.068726f, 684.659241f, 246.84f, 5.317163f},
    {1397.286499f, 678.322754f, 246.84f, 5.607323f},
    {1409.754395f, 669.343140f, 246.86f, 5.839451f},
    {1420.205566f, 665.879211f, 246.86f, 6.016602f}
};

#define MAX_SWIRL_POINTS 69

const Position swirlPos[MAX_SWIRL_POINTS] =
{
    {1487.464111f, 820.573914f, 246.843847f, 2.851097f},
    {1483.964111f, 821.693237f, 246.843847f, 2.817499f},
    {1468.896118f, 826.547729f, 246.844167f, 2.909131f},
    {1456.378662f, 828.710266f, 246.844213f, 2.979382f},
    {1439.406494f, 830.934082f, 246.844213f, 3.119882f},
    {1428.211304f, 830.142212f, 246.844213f, 3.263438f},
    {1418.107788f, 828.381470f, 246.844213f, 3.382557f},
    {1402.880737f, 823.863464f, 246.844213f, 3.452806f},
    {1399.085571f, 818.854919f, 246.844213f, 5.294566f},
    {1411.434082f, 808.112427f, 246.844213f, 0.178134f},
    {1422.152222f, 809.762329f, 246.844213f, 6.183375f},
    {1436.858887f, 807.700134f, 246.844213f, 6.088694f},
    {1444.952026f, 805.963623f, 246.844213f, 6.055098f},
    {1456.801147f, 795.857666f, 246.844213f, 4.103389f},
    {1444.532104f, 794.825623f, 246.844213f, 3.352025f},
    {1429.040283f, 790.880737f, 246.844213f, 3.461982f},
    {1410.085205f, 775.187012f, 246.845495f, 4.023979f},
    {1393.301880f, 765.024414f, 246.845495f, 3.208473f},
    {1391.872559f, 772.953552f, 246.845495f, 1.217052f},
    {1386.915649f, 784.558105f, 246.845495f, 2.457110f},
    {1377.011108f, 773.724792f, 246.845495f, 4.243890f},
    {1364.892334f, 769.258484f, 246.845495f, 2.915258f},
    {1365.610352f, 785.148743f, 246.845495f, 1.482780f},
    {1358.791992f, 738.885864f, 246.844656f, 4.736073f},
    {1360.505127f, 726.221008f, 246.844656f, 4.946821f},
    {1368.800781f, 712.329407f, 246.844656f, 5.569902f},
    {1375.536621f, 717.005432f, 246.844656f, 1.611060f},
    {1373.879883f, 730.299927f, 246.844656f, 1.507213f},
    {1381.795410f, 733.744568f, 246.844656f, 5.582122f},
    {1392.619751f, 728.715088f, 246.844656f, 0.435146f},
    {1400.361694f, 737.273865f, 246.844656f, 0.899404f},
    {1418.521362f, 716.076782f, 246.845510f, 5.438570f},
    {1423.970337f, 703.457825f, 246.852407f, 4.885737f},
    {1415.678589f, 699.607605f, 246.851675f, 2.845447f},
    {1407.067871f, 695.299500f, 246.848837f, 4.436752f},
    {1412.809814f, 687.349426f, 246.849600f, 5.649319f},
    {1417.447632f, 678.563110f, 246.852484f, 4.546707f},
    {1403.742798f, 676.551514f, 246.853964f, 3.004273f},
    {1455.166992f, 669.881775f, 246.856405f, 5.796364f},
    {1469.832886f, 668.007324f, 246.852448f, 0.218726f},
    {1481.525024f, 673.573853f, 246.858358f, 0.542484f},
    {1485.030884f, 685.873596f, 246.845449f, 1.868062f},
    {1475.905518f, 689.903992f, 246.845999f, 3.285270f},
    {1461.079590f, 687.039856f, 246.851873f, 3.227237f},
    {1456.446899f, 695.258850f, 246.853765f, 1.281632f},
    {1463.775757f, 702.528687f, 246.852346f, 0.609680f},
    {1466.321899f, 710.755859f, 246.847708f, 2.054377f},
    {1456.144287f, 712.550476f, 246.851980f, 3.062304f},
    {1473.011597f, 730.861023f, 246.845693f, 1.052557f},
    {1477.371216f, 738.282532f, 246.845693f, 0.936493f},
    {1486.354492f, 740.582092f, 246.845693f, 6.141500f},
    {1488.745972f, 732.226196f, 246.845693f, 4.516599f},
    {1489.199829f, 722.414978f, 246.845693f, 5.325995f},
    {1494.694580f, 719.655029f, 246.845693f, 0.362278f},
    {1500.481445f, 725.311035f, 246.845693f, 0.930383f},
    {1507.764038f, 733.761292f, 246.845693f, 0.365333f},
    {1514.580200f, 730.206177f, 246.845693f, 4.822032f},
    {1512.615112f, 717.166931f, 246.845693f, 4.504382f},
    {1524.565308f, 764.396484f, 246.844824f, 1.431730f},
    {1524.019897f, 777.253967f, 246.844824f, 1.813523f},
    {1516.852417f, 789.461365f, 246.844824f, 2.864211f},
    {1511.241699f, 781.535645f, 246.844824f, 4.608231f},
    {1504.731567f, 777.073181f, 246.844824f, 2.320541f},
    {1494.234131f, 781.758850f, 246.844824f, 3.218513f},
    {1487.912109f, 779.528564f, 246.844824f, 3.948496f},
    {1485.296631f, 766.771729f, 246.844824f, 4.492164f},
    {1478.048706f, 765.134338f, 246.844824f, 2.363299f},
    {1461.304810f, 787.290466f, 246.845510f, 2.552668f},
    {1453.450806f, 791.219910f, 246.845510f, 2.833669f}
};

#define MAX_SWIRL_TARGET_POS 16

G3D::Vector3 const swirlTargetPos[MAX_SWIRL_TARGET_POS] =
{
    { 1470.927f, 784.5482f, 246.9319f },
    { 1455.533f, 792.9921f, 247.8354f },
    { 1438.079f, 794.902f,  247.8354f },
    { 1421.223f, 789.9871f, 247.8354f },
    { 1407.53f,  778.9958f, 247.8406f },
    { 1399.086f, 763.6014f, 247.8356f },
    { 1397.177f, 746.1475f, 247.8355f },
    { 1402.091f, 729.2913f, 247.8355f },
    { 1413.083f, 715.5989f, 247.8353f },
    { 1428.477f, 707.1551f, 247.8472f },
    { 1445.931f, 705.2451f, 246.932f  },
    { 1462.787f, 710.16f,   247.84f   },
    { 1476.479f, 721.1512f, 247.5257f },
    { 1484.923f, 736.5457f, 247.8356f },
    { 1486.833f, 753.9997f, 246.9326f },
    { 1481.918f, 770.8559f, 247.8356f },
};

enum DisplayIds
{
    DISPLAY_CORRUPTED   = 49056,
    DISPLAY_PURGED      = 49807
};

Creature* GetImmerseus(Creature* p_Creature)
{
    if (InstanceScript* l_Instance = p_Creature->GetInstanceScript())
        return l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_IMMERSEUS));

    return nullptr;
}

class boss_immerseus : public CreatureScript
{
    public:
        boss_immerseus() : CreatureScript("boss_immerseus") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_immerseusAI(creature);
        }

        struct boss_immerseusAI : public BossAI
        {
            boss_immerseusAI(Creature* creature) : BossAI(creature, DATA_IMMERSEUS)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                if (instance->GetBossState(DATA_IMMERSEUS) == DONE)
                {
                    me->SetDisplayId(DisplayIds::DISPLAY_PURGED);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFaction(35);
                    return;
                }

                _Reset();

                corruptionPct = 100;
                summonedPuddles = 0;
                m_ShaPoolGuid = ObjectGuid::Empty;

                me->SetPowerType(POWER_MANA);
                me->SetMaxPower(POWER_MANA, 100);
                me->SetPower(POWER_MANA, 100);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_REGENERATE_POWER));

                phase = PHASE_IMMERSEUS_BOSS;

                me->AddAura(SPELL_ZERO_POWER, me);

                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void AttackStart(Unit* who) override
            {
                // Prevent pudle movement bugs
                // Because they is set to walk on following if its target (immerseus) walks
                me->SetWalk(false);

                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void EnterCombat(Unit* attacker) override
            {
                events.ScheduleEvent(EVENT_SHA_BOLT, urand(6000, 20000));
                events.ScheduleEvent(EVENT_CORROSIVE_BLAST, 10000);
                events.ScheduleEvent(EVENT_SWIRL, 20000);
                events.ScheduleEvent(EVENT_CHECK_MELEE, 5000);
                events.ScheduleEvent(EVENT_BERSERK, 10000);

                me->AddAura(SPELL_SEEPING_SHA, me);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SWELLING_CORRUPTION, TIMER_SWELLING_CORRUPTION_FIRST);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetBossState(DATA_IMMERSEUS, IN_PROGRESS);
                DoZoneInCombat();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_PUDDLE_DIED)
                {
                    if (corruptionPct > 0)
                        corruptionPct -= 1;
                }
                else if (action == ACTION_SPLIT)
                    Split();
                else if (action == ACTION_REFORM)
                    Reform();
            }

            ObjectGuid GetObjectGuid(uint32 type)
            {
                if (type == DATA_SHA_POOL)
                    return m_ShaPoolGuid;

                return ObjectGuid::Empty;
            }

            void KilledUnit(Unit* who) override
            {
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                BossAI::SummonedCreatureDespawn(summon);

                if (summon->GetEntry() == NPC_SHA_PUDDLE ||
                    summon->GetEntry() == NPC_CONTAMINATED_PUDDLE ||
                    summon->GetEntry() == NPC_PURIFIED_PUDDLE)
                {
                    if (summonedPuddles > 0 && phase == PHASE_IMMERSEUS_ADDS)
                    {
                        summonedPuddles--;

                        if (summonedPuddles == 0)
                        {
                            events.RescheduleEvent(EVENT_REFORM, 3000);

                            /// Remove aura from Sha Pool before despawn for properly animation
                            if (m_ShaPoolGuid != ObjectGuid::Empty)
                                if (Creature* l_ShaPool = instance->instance->GetCreature(m_ShaPoolGuid))
                                    l_ShaPool->RemoveAura(SPELL_SHA_POOL_AURA);
                        }
                    }
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;

                    if (corruptionPct > 0 && phase == PHASE_IMMERSEUS_BOSS)
                    {
                        phase = PHASE_IMMERSEUS_ADDS;

                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->CastStop();

                        me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));

                        summons.DespawnEntry(NPC_SWIRL_TARGET);
                        summons.DespawnEntry(NPC_SWIRL);

                        events.CancelEvent(EVENT_SHA_BOLT);
                        events.CancelEvent(EVENT_CORROSIVE_BLAST);
                        events.CancelEvent(EVENT_SWIRL);
                        events.CancelEvent(EVENT_CHECK_MELEE);
                        events.CancelEvent(EVENT_SWELLING_CORRUPTION);

                        events.ScheduleEvent(EVENT_SPLIT, 100);

                        EntryCheckPredicate pred(NPC_SHA_BOLT);
                        summons.DoAction(ACTION_MOVE_SHA_BOLT, pred);
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_BERSERK:
                            // don't use 'castspell' because it's aoe spell
                            me->AddAura(SPELL_BERSERK, me);
                            break;
                        case EVENT_CHECK_MELEE:
                            if (!me->IsWithinMeleeRange(me->GetVictim()))
                                DoCast(me->GetVictim() ? me->GetVictim() : NULL, SPELL_CORROSIVE_BLAST);
                            events.ScheduleEvent(EVENT_CHECK_MELEE, 5000);
                            break;
                        case EVENT_SHA_BOLT:
                            DoCastAOE(SPELL_SHA_BOOLT_AOE);
                            events.ScheduleEvent(EVENT_SHA_BOLT, urand(7000, 20000));
                            break;
                        case EVENT_CORROSIVE_BLAST:
                            DoCastVictim(SPELL_CORROSIVE_BLAST);
                            events.ScheduleEvent(EVENT_CORROSIVE_BLAST, urand(35000, 40000));
                            break;
                        case EVENT_SWIRL:
                        {
                            uint8 randPos = urand(0, MAX_SWIRL_TARGET_POS - 1);
                            Position l_Pos = Position(swirlTargetPos[randPos][0], swirlTargetPos[randPos][1], swirlTargetPos[randPos][2]);

                            if (Creature* pSwirlTarget = me->SummonCreature(NPC_SWIRL_TARGET, l_Pos, TEMPSUMMON_TIMED_DESPAWN, 15000))
                            {
                                SpawnSwirls();

                                pSwirlTarget->AI()->SetData(0, randPos);

                                DoCast(pSwirlTarget, SPELL_SWIRL);
                            }

                            events.ScheduleEvent(EVENT_SWIRL, 50000);
                            break;
                        }
                        case EVENT_SPLIT:
                            DoCast(me, SPELL_SPLIT);
                            break;
                        case EVENT_REFORM:
                            DoCast(me, SPELL_REFORM);
                            break;
                        case EVENT_REFORM_1:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_SWELLING_CORRUPTION:
                            DoSwellingCorruption();
                            events.ScheduleEvent(EVENT_SWELLING_CORRUPTION, TIMER_SWELLING_CORRUPTION);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoSwellingCorruption()
            {
                int32 stacks = me->GetPower(POWER_MANA) / 2;
                me->CastCustomSpell(SPELL_SWELLING_CORRUPTION, SPELLVALUE_AURA_STACK, stacks, me, true);
            }

            void EnableShaPool(bool value)
            {
                if (value)
                {
                    Position pos = me->GetPosition();
                    pos.m_positionZ += 1.f;

                    if (Creature* pShaPool = me->SummonCreature(NPC_SHA_POOL, pos))
                        m_ShaPoolGuid = pShaPool->GetGUID();
                }
                else
                {
                    summons.DespawnEntry(NPC_SHA_POOL);
                    m_ShaPoolGuid = ObjectGuid::Empty;
                }
            }

        private:

            uint8 phase;
            uint32 corruptionPct;
            uint32 summonedPuddles;
            ObjectGuid m_ShaPoolGuid;

            void Split()
            {
                int32 CorruptionLevel = me->GetPower(POWER_MANA);
                uint8 MaxPuddles = MAX_PUDDLES_IN_PHASE;
                uint8 BlackPuddles = 0;
                uint8 BluePuddles = 0;

                // Calculate Amount of Black & Blue Puddles:
                if (CorruptionLevel >= 80)
                {
                    BlackPuddles = 20;
                    BluePuddles = 5;
                }
                else if (CorruptionLevel < 80 && CorruptionLevel > 25)
                {
                    BlackPuddles = CorruptionLevel / 4;
                    BluePuddles = MAX_PUDDLES_IN_PHASE - BlackPuddles;
                }
                else if (CorruptionLevel <= 25 && CorruptionLevel > 0)
                {
                    BlackPuddles = 5;
                    BluePuddles = 20;
                }
                else if (CorruptionLevel <= 0)
                {
                    CompleteEncounter();
                    return;
                }

                // Generate 25 Random Puddle Spawns:
                std::list<Position> points;
                for (uint8 i = 0; i < MAX_PUDDLE_POINTS; ++i)
                {
                    Position pos = { puddlePos[i].GetPositionX(), puddlePos[i].GetPositionY(), puddlePos[i].GetPositionZ(), 0.0f };
                    points.push_back(pos);
                }

                Trinity::Containers::RandomResize(points, MaxPuddles);

                summonedPuddles = MaxPuddles;

                // Give Every Puddle its spawn Location:
                uint8 b = 1;
                for (auto l_Itr : points)
                {
                    if (b <= BlackPuddles)
                    {
                        me->CastSpell(l_Itr.GetPositionX(), l_Itr.GetPositionY(), l_Itr.GetPositionZ(), SPELL_SPLIT_MISSILE_1, true);
                        ++b;
                    }
                    else
                        me->CastSpell(l_Itr.GetPositionX(), l_Itr.GetPositionY(), l_Itr.GetPositionZ(), SPELL_SPLIT_MISSILE_2, true);
                }

                if (IsHeroic())
                {
                    EnableShaPool(true);
                    me->RemoveAura(SPELL_SEEPING_SHA);
                }

                me->RemoveAura(SPELL_SWELLING_CORRUPTION);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                events.ScheduleEvent(EVENT_REFORM, 60000);
            }

            void Reform()
            {
                me->RemoveAura(SPELL_SPLIT);

                phase = PHASE_IMMERSEUS_BOSS;

                if (corruptionPct <= 0)
                {
                    CompleteEncounter();
                    return;
                }

                summons.DespawnEntry(NPC_SHA_PUDDLE);
                summons.DespawnEntry(NPC_CONTAMINATED_PUDDLE);

                EnableShaPool(false);

                me->SetPower(POWER_MANA, corruptionPct);
                me->SetHealth(me->CountPctFromMaxHealth(corruptionPct));

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                me->AddAura(SPELL_SEEPING_SHA, me);

                events.ScheduleEvent(EVENT_SHA_BOLT, urand(6000, 20000));
                events.ScheduleEvent(EVENT_CORROSIVE_BLAST, 10000);
                events.ScheduleEvent(EVENT_SWIRL, 48500);
                events.ScheduleEvent(EVENT_CHECK_MELEE, 5000);

                /// Set REACT_AGGRESSIVE after 1.5 sec
                events.ScheduleEvent(EVENT_REFORM_1, 1500);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SWELLING_CORRUPTION, TIMER_SWELLING_CORRUPTION_FIRST_2);
            }

            void SpawnSwirls()
            {
                for (uint8 i = 0; i < MAX_SWIRL_POINTS; ++i)
                    me->SummonCreature(NPC_SWIRL, swirlPos[i], TEMPSUMMON_TIMED_DESPAWN, 13000);
            }

            void CompleteEncounter()
            {
                events.Reset();
                summons.DespawnAll();

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Reward();

                instance->SetBossState(DATA_IMMERSEUS, DONE);

                //ProcessCompletedEncounter();

                me->SetDisplayId(DisplayIds::DISPLAY_PURGED);
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAllAuras();
                me->AttackStop();
                me->SetFaction(35);
                me->DeleteThreatList();
                me->CombatStop(true);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                //instance->DoPermBindPlayersForRaid();
            }

            void Reward()
            {
                //instance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ACHIEVEMENT, me);
                //instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT);
                instance->DoModifyPlayerCurrencies(396, 4000);

                switch (GetDifficulty())
                {
                    case DIFFICULTY_10_N:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_TEARS_OF_THE_VALE_10N), DAY);
                        break;
                    case DIFFICULTY_25_N:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_TEARS_OF_THE_VALE_25N), DAY);
                        break;
                    case DIFFICULTY_10_HC:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_TEARS_OF_THE_VALE_10H), DAY);
                        break;
                    case DIFFICULTY_25_HC:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_TEARS_OF_THE_VALE_25H), DAY);
                        break;
                }
            }
        };
};

struct npc_immerseus_puddleAI : public ScriptedAI
{
    npc_immerseus_puddleAI(Creature* creature) : ScriptedAI(creature)
    {
        me->setActive(true);

        me->SetReactState(REACT_PASSIVE);

        m_MovingTimer = 2000;
        m_CheckDestTimer = 1000;
        m_IsDestReached = false;
    }

    void UpdateAI(const uint32 diff) override
    {
        UpdateMoving(diff);

        CheckDestination(diff);
    }

    void JustDied(Unit* who) override
    {
        me->DespawnOrUnsummon(1000);
    }

protected:

    virtual void DoDestinationReached() { }

    bool IsDestinationReached() const { return m_IsDestReached; }

private:

    void UpdateMoving(const uint32 diff)
    {
        if (me->isMoving())
            return;

        if (m_MovingTimer <= diff)
        {
            m_MovingTimer = 1000;

            BeginMoving();
        }
        else
        {
            m_MovingTimer -= diff;
        }
    }

    void BeginMoving()
    {
        if (me->isMoving() || me->HasUnitMovementFlag(MOVEMENTFLAG_ROOT))
            return;

        if (Creature* l_Immerseus = GetImmerseus(me))
            me->GetMotionMaster()->MovePoint(0, l_Immerseus->GetPositionX(), l_Immerseus->GetPositionY(), l_Immerseus->GetPositionZ(), false);
    }

    void CheckDestination(const uint32 diff)
    {
        if (!me->isMoving() || IsDestinationReached())
            return;

        if (m_CheckDestTimer <= diff)
        {
            m_CheckDestTimer = 1000;

            if (Creature* pImmerseus = GetImmerseus(me))
            {
                if (me->GetExactDist(pImmerseus) <= 30.0f)
                {
                    m_IsDestReached = true;

                    me->GetMotionMaster()->MovementExpired(false);
                    me->GetMotionMaster()->Clear(false);

                    IncreaseShaPool();

                    DoDestinationReached();

                    me->DespawnOrUnsummon(100);
                }

                /// stopped for some reason (root, stun)
                if (!me->isMoving())
                    BeginMoving();
            }
        }
        else
        {
            m_CheckDestTimer -= diff;
        }
    }

    void IncreaseShaPool()
    {
        if (!IsHeroic())
            return;

        InstanceScript* pInstance = me->GetInstanceScript();
        if (!pInstance)
            return;

        if (Creature* pImmerseus = GetImmerseus(me))
        {
            if (Creature* pShaPool = pInstance->instance->GetCreature(pImmerseus->AI()->GetGUID(DATA_SHA_POOL)))
            {
                pShaPool->AI()->DoAction(ACTION_SHA_POOL_INCREASE);
            }
        }
    }

private:

    uint32 m_MovingTimer;
    bool m_IsDestReached;
    uint32 m_CheckDestTimer;
};

class npc_immerseus_contaminated_puddle : public CreatureScript
{
    public:
        npc_immerseus_contaminated_puddle() : CreatureScript("npc_immerseus_contaminated_puddle") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_immerseus_contaminated_puddleAI(creature);
        }

        enum ExplosionVisual
        {
            Id = 32365,
        };

        struct npc_immerseus_contaminated_puddleAI : public npc_immerseus_puddleAI
        {
            npc_immerseus_contaminated_puddleAI(Creature* creature) : npc_immerseus_puddleAI(creature) { }

            void Reset() override
            {
                npc_immerseus_puddleAI::Reset();

                me->AddAura(SPELL_CONGEALING, me);

                me->SetHealth(me->CountPctFromMaxHealth(10));

                m_IsHealed = false;
                m_HealCheckTimer = 1000;
            }

            void UpdateAI(const uint32 diff) override
            {
                npc_immerseus_puddleAI::UpdateAI(diff);

                CheckHealed(diff);
            }

            void JustDied(Unit* who) override
            {
                npc_immerseus_puddleAI::JustDied(who);
            }

        protected:

            void DoDestinationReached() override
            {
                if (IsHealed())
                {
                    if (Creature* pImmerseus = GetImmerseus(me))
                        pImmerseus->AI()->DoAction(ACTION_PUDDLE_DIED);

                    //me->SendPlaySpellVisual(ExplosionVisual::Id, me, 100, true);
                }
                else
                    DoCastAOE(SPELL_ERUPTING_WATER, true);
            }

        private:

            bool IsHealed() const { return m_IsHealed; }

            void CheckHealed(const uint32 diff)
            {
                if (IsHealed() || IsDestinationReached())
                    return;

                if (m_HealCheckTimer <= diff)
                {
                    m_HealCheckTimer = 1000;

                    if (!IsHealed() && me->IsFullHealth())
                    {
                        m_IsHealed = true;

                        me->RemoveAura(SPELL_CONGEALING);
                        me->RemoveAura(SPELL_CONGEALING_AURA);

                        me->AddAura(SPELL_PURIFIED, me);

                        DoCastAOE(SPELL_PUTRIFIED_RESUDUE, true);

                        me->UpdateEntry(NPC_PURIFIED_PUDDLE);
                    }
                }
                else
                {
                    m_HealCheckTimer -= diff;
                }
            }

        private:

            bool m_IsHealed;
            uint32 m_HealCheckTimer;
        };
};

class npc_immerseus_sha_puddle : public CreatureScript
{
    public:
        npc_immerseus_sha_puddle() : CreatureScript("npc_immerseus_sha_puddle") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_immerseus_sha_puddleAI(creature);
        }

        struct npc_immerseus_sha_puddleAI : public npc_immerseus_puddleAI
        {
            npc_immerseus_sha_puddleAI(Creature* creature) : npc_immerseus_puddleAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
            }

            void JustDied(Unit* who) override
            {
                DoCastAOE(SPELL_SHA_RESIDUE, true);

                if (Creature* pImmerseus = GetImmerseus(me))
                {
                    pImmerseus->AI()->DoAction(ACTION_PUDDLE_DIED);
                }

                npc_immerseus_puddleAI::JustDied(who);
            }

            void UpdateAI(const uint32 diff) override
            {
                npc_immerseus_puddleAI::UpdateAI(diff);
            }

        protected:

            void DoDestinationReached() override
            {
                DoCastAOE(SPELL_ERUPTING_SHA, true);
            }
        };
};

/// Sha Bolt - 71544
struct npc_immerseus_sha_bolt : public ScriptedAI
{
    npc_immerseus_sha_bolt(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);

        /*if (SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_SHA_SPLASH_AURA))
            Aura::TryRefreshStackOrCreate(l_SpellInfo, ObjectGuid castId, MAX_EFFECT_MASK, me, me);
            */
        m_CheckMovingTimer = 1000;
        m_IsMovingToPool = false;
    }

    void DoAction(const int32 action)
    {
        if (action == ACTION_MOVE_SHA_BOLT)
            MoveToPool();
    }

    void UpdateAI(const uint32 diff) override
    {
        UpdateMovingToPool(diff);
    }

    private:

        void MoveToPool()
        {
            if (m_IsMovingToPool)
                return;

            m_IsMovingToPool = true;

            if (Creature* immerseus = GetImmerseus(me))
                me->GetMotionMaster()->MoveFollow(immerseus, 0.0f, 0.0f);
        }

        void UpdateMovingToPool(const uint32 diff)
        {
            if (!m_IsMovingToPool)
                return;

            if (m_CheckMovingTimer <= diff)
            {

                if (Creature* pImmerseus = GetImmerseus(me))
                {
                    if (me->GetExactDist(pImmerseus) <= 30.0f)
                    {
                        me->GetMotionMaster()->MovementExpired(false);
                        me->GetMotionMaster()->Clear(false);

                        me->DespawnOrUnsummon(100);
                        return;
                    }
                }
            }
            else
                m_CheckMovingTimer -= diff;
        }

    private:
        uint32 m_CheckMovingTimer;
        bool m_IsMovingToPool;
};

class npc_immerseus_swirl_target : public CreatureScript
{
    public:
        npc_immerseus_swirl_target() : CreatureScript("npc_immerseus_swirl_target") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_immerseus_swirl_targetAI(creature);
        }

        struct npc_immerseus_swirl_targetAI : public ScriptedAI
        {
            npc_immerseus_swirl_targetAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(11686);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                pos = 0;

                me->SetDisableGravity(true);
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_MOVE_SWIRL)
                {
                    Movement::MoveSplineInit init(me);

                    if (pos > 0)
                        for (int8 i = pos; i >= 0; --i)
                            init.Path().push_back(swirlTargetPos[i]);

                    for (uint8 i = MAX_SWIRL_TARGET_POS - 1; i > pos; --i)
                        init.Path().push_back(swirlTargetPos[i]);

                    init.SetCyclic();
                    init.SetSmooth();
                    init.SetFly();
                    init.SetVelocity(15.0f);
                    init.Launch();
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                pos = data;
            }

        private:
            uint32 pos;
        };
};

class npc_immerseus_swirl : public CreatureScript
{
    public:
        npc_immerseus_swirl() : CreatureScript("npc_immerseus_swirl") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_immerseus_swirlAI(creature);
        }

        struct npc_immerseus_swirlAI : public ScriptedAI
        {
            npc_immerseus_swirlAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void IsSummonedBy(Unit* /*p_Summoner*/) override
            {
                DoCast(me, SPELL_SWIRL_2);
                me->GetMotionMaster()->MoveRandom(100.f);
            }
        };
};

/// Sha Pool - 71611
struct npc_immerseus_sha_pool : public ScriptedAI
{
    npc_immerseus_sha_pool(Creature* creature) : ScriptedAI(creature) { }

    const float m_MaxScale = 200.f;
    const float m_MinScale = 30.f;
    float m_Scale = 30.0f;

    void DoAction(const int32 p_Action) override
    {
        if (p_Action == ACTION_SHA_POOL_INCREASE)
        {
            if (m_Scale > m_MaxScale)
                return;

            m_Scale = std::min(m_Scale + 5.f, m_MaxScale);
            me->SetObjectScale(m_Scale);
        }
        else
        {
            if (m_Scale <= m_MinScale)
                return;

            m_Scale = std::max(m_Scale - 10.f, m_MinScale);
            me->SetObjectScale(m_Scale);
        }
    }
};

class spell_immerseus_sha_bolt_aoe : public SpellScriptLoader
{
    public:
        spell_immerseus_sha_bolt_aoe() : SpellScriptLoader("spell_immerseus_sha_bolt_aoe") { }

        class spell_immerseus_sha_bolt_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_immerseus_sha_bolt_aoe_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHA_BOLT_MISSILE, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_immerseus_sha_bolt_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_immerseus_sha_bolt_aoe_SpellScript();
        }
};

class spell_immerseus_split : public SpellScriptLoader
{
    public:
        spell_immerseus_split() : SpellScriptLoader("spell_immerseus_split") { }

        class spell_immerseus_split_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_immerseus_split_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_SPLIT);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_immerseus_split_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_immerseus_split_SpellScript();
        }
};

class spell_immerseus_reform : public SpellScriptLoader
{
    public:
        spell_immerseus_reform() : SpellScriptLoader("spell_immerseus_reform") { }

        class spell_immerseus_reform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_immerseus_reform_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_REFORM);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_immerseus_reform_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_immerseus_reform_SpellScript();
        }
};

class spell_immerseus_congealing : public SpellScriptLoader
{
    public:
        spell_immerseus_congealing() : SpellScriptLoader("spell_immerseus_congealing") { }

        class spell_immerseus_congealing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_immerseus_congealing_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                int32 healthPct = int32(GetUnitOwner()->GetHealthPct() / 10.0f);

                if (healthPct > 7)
                {
                    healthPct = 7;
                }
                else if (healthPct < 0)
                {
                    healthPct = 0;
                }


                if (Aura* aur = GetUnitOwner()->GetAura(SPELL_CONGEALING_AURA))
                {
                    uint8 currentStacks = aur->GetStackAmount();
                    if (healthPct != currentStacks)
                    {
                        if (healthPct <= 0)
                        {
                            aur->Remove();
                        }
                        else
                        {
                            aur->SetStackAmount(healthPct);
                        }
                    }
                }
                else if (healthPct > 0)
                {
                    if (Aura* aur = GetUnitOwner()->AddAura(SPELL_CONGEALING_AURA, GetUnitOwner()))
                    {
                        aur->SetStackAmount(healthPct);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_immerseus_congealing_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_immerseus_congealing_AuraScript();
        }
};

/// Swirl - 143309
class spell_immerseus_swirl : public AuraScript
{
    PrepareAuraScript(spell_immerseus_swirl);

    void HandleApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
    {
        if (Unit* l_SwirlTarget = GetTarget())
            if (l_SwirlTarget->IsCreature() && l_SwirlTarget->ToCreature()->AI())
                l_SwirlTarget->ToCreature()->AI()->DoAction(ACTION_MOVE_SWIRL);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_immerseus_swirl::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_immerseus_swirl_aura : public SpellScriptLoader
{
    public:
        spell_immerseus_swirl_aura() : SpellScriptLoader("spell_immerseus_swirl_aura") { }

        class spell_immerseus_swirl_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_immerseus_swirl_aura_AuraScript);

            void CheckFall(AuraEffect const* p_AurEffect)
            {
                // Deal damage only once.
                if (p_AurEffect->GetTickNumber() > 1)
                    PreventDefaultAction();

                // If player has the aura, he cannot be hit by  Swirl damage again.
                // Remove aura after 4 secs.
                if (GetMaxDuration() - GetDuration() >= 4000)
                {
                    Remove();
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_immerseus_swirl_aura_AuraScript::CheckFall, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_immerseus_swirl_aura_AuraScript();
        }
};

class spell_immerseus_corrosive_blast : public SpellScriptLoader
{
    public:
        spell_immerseus_corrosive_blast() : SpellScriptLoader("spell_immerseus_corrosive_blast") { }

        class spell_immerseus_corrosive_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_immerseus_corrosive_blast_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() || !GetCaster()->isInFront(obj, float(M_PI) / 6);
                });

                // It should hit the tank always (maybe only debuff, need to check).
                if (Unit* l_Victim = GetExplTargetUnit())
                {
                    // Prevent duplicating.
                    targets.remove(l_Victim);
                    targets.push_back(l_Victim);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_immerseus_corrosive_blast_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_immerseus_corrosive_blast_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_immerseus_corrosive_blast_SpellScript();
        }
};

class spell_immerseus_erupting_sha : public SpellScriptLoader
{
    public:

        spell_immerseus_erupting_sha() : SpellScriptLoader("spell_immerseus_erupting_sha") { }

        class spell_immerseus_erupting_sha_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_immerseus_erupting_sha_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                float modDamage = 1.f;

                if (GetCaster()->GetEntry() == NPC_CONTAMINATED_PUDDLE ||
                    GetCaster()->GetEntry() == NPC_PURIFIED_PUDDLE)
                {
                    modDamage = (100.0f - GetCaster()->GetHealthPct()) / 100.0f;
                }
                else if (GetCaster()->GetEntry() == NPC_SHA_PUDDLE)
                {
                    modDamage = GetCaster()->GetHealthPct() / 100.0f;
                }

                if (modDamage < 0.1f)
                    modDamage = 0.1f;
                else if (modDamage > 1.f)
                    modDamage = 1.f;

                if (modDamage < 1.f)
                {
                    int32 newDamage = modDamage * GetHitDamage();
                    SetHitDamage(newDamage);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_immerseus_erupting_sha_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_immerseus_erupting_sha_SpellScript();
        }
};

/// Swelling Corruption - 143574
class spell_immerseus_swelling_corruption : public AuraScript
{
    PrepareAuraScript(spell_immerseus_swelling_corruption);

    void OnProc(AuraEffect const* p_AurEff, ProcEventInfo& p_EventInfo)
    {
        PreventDefaultAction();

        if (Unit* l_Caster = GetUnitOwner())
        {
            if (Unit* l_Target = p_EventInfo.GetDamageInfo()->GetAttacker())
            {
                l_Caster->CastSpell(l_Caster, SPELL_SHA_CORRUPTION_MISSILE, true);
                l_Caster->CastSpell(l_Target, SPELL_SHA_CORRUPTION_DMG, true);

                p_AurEff->GetBase()->ModStackAmount(-1);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_immerseus_swelling_corruption::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

/// Sha Pool - 143462
class spell_immerseus_sha_pool : public AuraScript
{
    PrepareAuraScript(spell_immerseus_sha_pool);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void HandlePeriodic(AuraEffect const* /*p_AurEff*/)
    {
        if (Unit* l_Caster = GetCaster())
            l_Caster->ToCreature()->AI()->DoAction(ACTION_SHA_POOL_INCREASE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_immerseus_sha_pool::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

/// Sha Pool - 143460
class spell_immerseus_sha_pool_dmg : public SpellScript
{
    PrepareSpellScript(spell_immerseus_sha_pool_dmg);

    void ScaleRange(std::list<WorldObject*>& p_Targets)
    {
        p_Targets.remove_if([&](WorldObject* p_Target) -> bool { return GetCaster()->GetExactDist2d(p_Target) > (0.6f * GetCaster()->GetObjectScale()); });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_immerseus_sha_pool_dmg::ScaleRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

/// Sha Pool - 143461
class spell_immerseus_sha_pool_script : public SpellScript
{
    PrepareSpellScript(spell_immerseus_sha_pool_script);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void ScaleRange(std::list<WorldObject*>& p_Targets)
    {
        p_Targets.remove_if([&](WorldObject* p_Target) -> bool
        {
            return !p_Target->IsPlayer() || GetCaster()->GetExactDist2d(p_Target) > (0.6f * GetCaster()->GetObjectScale());
        });
    }

    void HandleScript()
    {
        GetCaster()->ToCreature()->AI()->DoAction(ACTION_SHA_POOL_DECREASE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_immerseus_sha_pool_script::ScaleRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnHit += SpellHitFn(spell_immerseus_sha_pool_script::HandleScript);
    }
};

/// Sha Splash - 143298
struct spell_area_immerseus_sha_splash : public AreaTriggerAI
{
    spell_area_immerseus_sha_splash(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_SHA_SPLASH))
            target->CastSpell(target, SPELL_SHA_SPLASH, true);
    }

    void OnUnitExit(Unit* unit)
    {
        if (unit->HasAura(SPELL_SHA_SPLASH))
            unit->RemoveAura(SPELL_SHA_SPLASH);
    }
};

/// Swirl - 143410
struct spell_area_immerseus_swirl : public AreaTriggerAI
{
    spell_area_immerseus_swirl(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }


    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_SWIRL_DMG_2))
            target->CastSpell(target, SPELL_SWIRL_DMG_2, true);
    }
};

/// Swirl - 143309
struct spell_area_immerseus_swirl_target : public AreaTriggerAI
{
    spell_area_immerseus_swirl_target(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_SWIRL_DMG))
            return;

        if (Unit* l_Immerseus = at->GetCaster())
            if (InstanceScript* l_Instance = l_Immerseus->GetInstanceScript())
                if (Creature* l_SwirlTarget = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_SWIRL_TARGET)))
                    if (target->IsInAxe(l_Immerseus, l_SwirlTarget, 10.0f))
                        l_Immerseus->CastSpell(target, SPELL_SWIRL_DMG, true);
    }
};

/// Seeping Sha - 143281
struct spell_area_immerseus_seeping_sha : public AreaTriggerAI
{
    spell_area_immerseus_seeping_sha(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if(Unit* l_Immerseus = at->GetCaster())
            if (!target->HasAura(Spells::SPELL_SEEPING_SHA_DMG))
                l_Immerseus->CastSpell(target, Spells::SPELL_SEEPING_SHA_DMG, true);
    }
};

/// Sha Corruption - 143579
class spell_sha_corruption : public AuraScript
{
    PrepareAuraScript(spell_sha_corruption);

    const float m_Coefficients[6] = { 1.f, 3.5f, 9.1876f, 21.4372f, 46.8944f, 98.4784f };

    void OnPeriodic(AuraEffect const* p_AurEff)
    {
        uint8 l_StackAmount = GetAura()->GetStackAmount();
        uint32 l_Damage = p_AurEff->GetBaseAmount() * m_Coefficients[std::min(uint8(l_StackAmount - 1), uint8(5))];

        for (uint8 l_Itr = 7; l_Itr <= l_StackAmount; ++l_Itr)
            AddPct(l_Damage, 100);

        const_cast<AuraEffect*>(p_AurEff)->SetAmount(l_Damage);
        //const_cast<AuraEffect*>(p_AurEff)->m_fixed_periodic.SetFixedDamage(l_Damage);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_corruption::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_immerseus()
{
    new boss_immerseus();                       // 71543
    new npc_immerseus_contaminated_puddle();    // 71604
    new npc_immerseus_sha_puddle();             // 71603
    RegisterCreatureAI(npc_immerseus_sha_bolt); // 71544
    new npc_immerseus_swirl_target();           // 71550
    new npc_immerseus_swirl();                  // 71548
    RegisterCreatureAI(npc_immerseus_sha_pool); // 71611

    new spell_immerseus_sha_bolt_aoe();         // 143290
    new spell_immerseus_split();                // 143020
    new spell_immerseus_reform();               // 143469
    new spell_immerseus_congealing();           // 143538
    RegisterAuraScript(spell_immerseus_swirl);  // 143309
    new spell_immerseus_swirl_aura();           // 143412 143413
    new spell_immerseus_corrosive_blast();      // 143436
    new spell_immerseus_erupting_sha();         // 143498
    RegisterAuraScript(spell_immerseus_swelling_corruption);  // 143574
    RegisterAuraScript(spell_immerseus_sha_pool);         // 143462
    RegisterSpellScript(spell_immerseus_sha_pool_dmg);    // 143460
    RegisterSpellScript(spell_immerseus_sha_pool_script); // 143461
    RegisterAreaTriggerAI(spell_area_immerseus_sha_splash); // 143298
    RegisterAreaTriggerAI(spell_area_immerseus_swirl);      // 143410
    RegisterAreaTriggerAI(spell_area_immerseus_swirl_target); // 143309
    RegisterAreaTriggerAI(spell_area_immerseus_seeping_sha);  // 143281
    RegisterAuraScript(spell_sha_corruption);   // 143579
}
