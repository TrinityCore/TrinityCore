#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "G3D/Vector3.h"

enum Spells
{
    SPELL_LONGING_CAST = 297934,
    SPELL_LONGING_AURA_PERIODIC = 304260,
    SPELL_PAINFUL_MEMORIES_CAST = 297937,
    SPELL_PAINFUL_MEMORIES_AURA_PERIODIC = 304267,
    SPELL_TORMENT = 297912,
    SPELL_CURSED_HEART_PERIODIC = 297898,
    SPELL_CURSED_HEART_AT = 297900,
    SPELL_CURSED_HEART_AT_DAMAGE = 297907,
    SPELL_CHAIN_LIGHTNING = 297972,
    SPELL_INFURIATED = 300428,
    SPELL_COLD_BLAST = 298014,
    SPELL_FROZEN = 298018,
    SPELL_ICE_SHARD = 298021,
    SPELL_LIGHTNING_ORB_DAMAGE = 298120,
    SPELL_LIGHTNING_ORB_SPELLDEST = 298121,
    SPELL_LIGHTNING_ORB_AT = 298119,
    SPELL_SERRATED_EDGE = 298756,
    SPELL_CHARGED_SPEAR = 298422,
    SPELL_DRAIN_ANCIENT_WARD_VISUAL = 302497,
    SPELL_BECKON_CAST = 299094,
    SPELL_DEVOTION = 300001,
    SPELL_CRUSHING_DEPTHS_SUMMON = 303828,
    SPELL_CRUSHING_DEPTHS_AURA = 303825,
    SPELL_BECKON_AT = 303759, //303224
    SPELL_ARCANE_ORBS_DUMMY = 298787,
    SPELL_ARCANE_ORBS_MISSILE = 298786,
    SPELL_ARCANE_ORBS_DAMAGE = 298782,
    SPELL_ARCANE_ORBS_AURA = 298781,
    SPELL_ARCANE_ORBS_AT = 298783,
    SPELL_GROUND_POUND_CHANNEL = 298531,
    SPELL_QUEENS_DECREE = 299250,
    SPELL_ARCANE_ORB_DECREE_AT = 304974,
    SPELL_SUFFER = 299249,
    SPELL_OBEY = 299251,
    SPELL_STAND_ALONE = 299255,
    SPELL_STAND_TOGETHER = 299254,
    SPELL_SANCTION = 299276,
    SPELL_DRAINED_SOUL = 298569,
    SPELL_TITANIC_MACHINATIONS = 303457,
    SPELL_PRESSURE_SURGE = 300074,
    SPELL_PRESSURE_SURGE_AT = 302208,
    SPELL_CATASTROPHIC_FAILURE = 300076,
    SPELL_ARCANE_JOLT = 304475,
    SPELL_ARCANE_VULNERABILITY = 302999,
    SPELL_ARCANE_MASTERY = 300502,
    SPELL_ARCANE_MISSILE = 300504,
    SPELL_ARCANE_BURST_DUMMY = 303629,
    SPELL_ARCANE_BURST_AURA = 303657,
    SPELL_ARCANE_BURST_DAMAGE = 303672,
    SPELL_ARCANE_DETONATION = 300518,
    SPELL_JEALOUSY = 303816,
    SPELL_REVERSAL_OF_FORTUNE = 297371,
    SPELL_ENERGIZE_WARD_OF_POWER = 300490,
    SPELL_DRAIN_ANCIENT_WARD = 300491,
    SPELL_STATIC_SHOCK = 300492,
    SPELL_CRYSTALLINE_SHIELD = 300620,
    SPELL_PIERCING_SPEAR = 300602,
    SPELL_VOID_TOUCHED = 300743,
    SPELL_NETHER_PORTAL_MISSILE = 303987,
    SPELL_NETHER_PORTAL_AT_DAMAGE = 303981,
    SPELL_NETHER_PORTAL_AT = 303980,
    SPELL_PIERCING_GAZE_AT = 300784,
    SPELL_PIERCING_GAZE_DAMAGE = 300785,
    SPELL_OVERLOAD_ESSENCE_OF_AZEROTH_AT = 301435,
    SPELL_OVERLOAD_ESSENCE_OF_AZEROTH_AT_MISSILE = 301456,
    SPELL_OVERLOAD_SYSTEM_SHOCK_AT = 301457,
    SPELL_OVERLOAD_SYSTEM_SHOCK_AT_MISSILE = 301458,
    SPELL_OVERLOAD_SHORT_CIRCUIT_AT = 301459,
    SPELL_OVERLOAD_SHORT_CIRCUIT_AT_MISSILE = 301460,
    SPELL_OVERLOAD_MISSILE = 301462,
    SPELL_OVERLOAD_AT = 301461,
    SPELL_OVERLOAD_DUMMY = 300807,
    SPELL_MASSIVE_ENERGY_SPIKE = 301518,
    SPELL_CONTROLLED_BURST = 301424,
    SPELL_CONTROLLED_BURST_DAMAGE = 301425,
    SPELL_SYSTEM_SHOCK_MISSILE = 301484,
    SPELL_SYSTEM_SHOCK_DAMAGE = 300877,
    SPELL_SHORT_CIRCUIT_PERIODIC = 301155,
    SPELL_SHORT_CIRCUIT_VISUAL = 301158,
    SPELL_SHORT_CIRCUIT_DUMMY = 300879,
    SPELL_ESSENCE_OF_AEROTH = 300866,
    SPELL_ESSENCE_OF_AZEROTH_MISSILE = 301483,
    SPELL_STAY_AURA = 299253,
    SPELL_STAY_AT = 305499, //no visual
    SPELL_MARCH_AT = 303480, //305399
    SPELL_MARCH_PERIODIC = 299252,
    SPELL_GREATER_REVERSAL_OF_FORTUNE = 297372,
    SPELL_FEEDBACK = 303644,
    SPELL_DIVIDE_AND_CONQUER_CAST = 307331,
    SPELL_DIVIDE_AND_CONQUER_DUMMY_KILL = 305415,
    SPELL_DIVIDE_AND_CONQUER_AT_1 = 300478,
    SPELL_DIVIDE_AND_CONQUER_AT_2 = 307332,
    SPELL_LIGHTNING_ORB_VISUAL = 293832,
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_PAINFUL_MEMORIES,
    EVENT_LONGING,
    EVENT_CHAIN_LIGHTNING,
    EVENT_LIGHTNING_ORB,
    EVENT_COLD_BLAST,
    EVENT_ICE_SHARD,
    EVENT_SERRATED_EDGE,
    EVENT_CHARGED_SPEAR,
    EVENT_DRAIN_ANCIENT_WARD,
    EVENT_BECKON,
    EVENT_ARCANE_ORBS,
    EVENT_SUMMON_HULK,
    EVENT_CHANGE_PHASE2,
    EVENT_SPECIAL_ENERGY,
    EVENT_CHECK_PLAYERS,
    EVENT_SELECT_RANDOM_WARD,
    EVENT_ARCANE_DETONATION,
    EVENT_ARCANE_BURST,
    EVENT_TITANIC_MACHINATIONS,
    EVENT_ARCANE_JOLT,
    EVENT_SUMMON_ADDS,
    EVENT_CHANGE_PHASE3,
    EVENT_CHARGE_WARD,
    EVENT_NETHER_PORTAL,
    EVENT_PIERCING_GAZE,
    EVENT_VOID_TOUCHED,
    EVENT_REVERSAL_OF_FORTUNE,
    EVENT_SUMMON_LOYAL_MYRMIDON,
    EVENT_SUMMON_TIDEMISTRESSES,
    EVENT_DIVINE_AND_CONQUER,
    EVENT_CRYSTALLINE_SHIELD,
    EVENT_STATIC_SHOCK,
    EVENT_OVERLOAD,
    EVENT_MASSIVE_ENERGY_SPIKE,
};

enum Timers
{
    TIMER_CHECK_ENERGY = 1 * IN_MILLISECONDS,
    TIMER_PAINFUL_MEMORIES = 8 * IN_MILLISECONDS,
    TIMER_LONGING = 20 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING = 15 * IN_MILLISECONDS,
    TIMER_LIGHTNING_ORB = 35 * IN_MILLISECONDS,
    TIMER_COLD_BLAST = 10 * IN_MILLISECONDS,
    TIMER_ICE_SHARD = 5 * IN_MILLISECONDS,
    TIMER_SERRATED_EDGE = 3 * IN_MILLISECONDS,
    TIMER_CHARGED_SPEAR = 30 * IN_MILLISECONDS,
    TIMER_DRAIN_ANCIENT_WARD = 45 * IN_MILLISECONDS,
    TIMER_BECKON = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_HULK = 45 * IN_MILLISECONDS,
    TIMER_ARCANE_ORBS = 50 * IN_MILLISECONDS,
    TIMER_CHANGE_PHASE = 20 * IN_MILLISECONDS,
    TIMER_SELECT_WARD = 1 * IN_MILLISECONDS,
    TIMER_ARCANE_JOLT = 15 * IN_MILLISECONDS,
    TIMER_TITANIC_MACHINATIONS = 5 * IN_MILLISECONDS,
    TIMER_ARCANE_BURST = 25 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS = 50 * IN_MILLISECONDS,
    TIMER_CHECK_PLAYERS = 2 * IN_MILLISECONDS,
    TIMER_NETHER_PORTAL = 30 * IN_MILLISECONDS,
    TIMER_VOID_TOUCHED = 25 * IN_MILLISECONDS,
    TIMER_SUMMON_LOYAL_MYRMIDON = 90 * IN_MILLISECONDS,
    TIMER_REVERSAL_OF_FORTUNE = 80 * IN_MILLISECONDS,
    TIMER_PIERCING_GAZE = 50 * IN_MILLISECONDS,
    TIMER_DIVIDE_AND_CONQUER = 55 * IN_MILLISECONDS,
    TIMER_STATIC_SHOCK = 25 * IN_MILLISECONDS,
    TIMER_OVERLOAD = 55 * IN_MILLISECONDS,
    TIMER_MASSIVE_ENERGY_SPIKE = 40 * IN_MILLISECONDS,
};

enum GameObjects
{
    GOB_SENTRY = 327636,
    GOB_WARD_RIGHT = 327631,
    GOB_WARD_SOUTH = 327632,
    GOB_WARD_LEFT = 327634,
    GOB_WARD_MIDDLE = 327635,
    GOB_TITAN_CONSOLE = 327633,
};

enum Points
{
    POINT_WARD_REACHED = 200,
};

Position centerPos = { 216.65f, 2444.94f, 710.65f };
Position middleWard = { centerPos };
Position leftWard = { 182.32f, 2454.58f, 710.79f };
Position rightWard = { 250.27f, 2454.62f, 710.79f };
Position southWard = { 216.27f, 2410.97f, 710.78f };
Position overloadATs = { 216.47f, 2415.98f, 712.34f };
Position azsharaPreEngage = { 266.21f, 2475.89f, 743.32f, 3.65f };
Position azsharaEngage = { 223.30f, 2482.45f, 710.81f };

Position rpAdds[4] =
{
    {206.12f, 2408.97f, 710.80f}, //thalyssra
    {200.15f, 2411.34f, 710.80f}, // jaina
    {227.28f, 2407.95f, 710.80f}, // lorthemar
    {232.28f, 2409.54f, 710.81f}, // shandris
};

Position firstAdds[2][1] =
{
    {
        {210.72f, 2480.79f, 710.80f },
    },

    {
        {229.15f, 2479.40f, 710.80f},
    },
};

enum Actions
{
    ACTION_INIT = 1,
    ACTION_ENGAGE_COMBAT_AZSHARA,
    ACTION_RP,
    ACTION_COUNT_SERVANTS_P1,
    ACTION_COUNT_SURGE,
    ACTION_REMOVE_SURGE,
    ACTION_NORMAL_ENERGY,
    ACTION_SPECIAL_EVENT,
};

struct noTanks : public std::unary_function<Unit*, bool>
{
    noTanks() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
    }
};

struct checkShield : public std::unary_function<Unit*, bool>
{
    checkShield() {}

    bool operator() (const Unit* target)
    {
        return target && !target->HasAura(SPELL_CRYSTALLINE_SHIELD);
    }
};

uint32 QueensDecree[4] =
{
    SPELL_SUFFER,
    SPELL_OBEY,
    SPELL_STAND_ALONE,
    SPELL_STAND_TOGETHER,
};

uint32 QueensDecreeHeroic[6] =
{
    SPELL_STAND_TOGETHER,
    SPELL_OBEY,
    SPELL_SUFFER,
    SPELL_STAND_ALONE,
    SPELL_STAY_AURA,
    SPELL_MARCH_PERIODIC,
};

uint32 QueensDecreeMythic[6] =
{
    SPELL_STAY_AURA,
    SPELL_MARCH_PERIODIC,
    SPELL_OBEY,
    SPELL_SUFFER,
    SPELL_STAND_ALONE,
    SPELL_STAND_TOGETHER,
};

//152910
struct bfa_boss_queen_azshara : public BossAI
{
    bfa_boss_queen_azshara(Creature* creature) : BossAI(creature, DATA_QUEEN_AZSHARA), summons(me) {  }

    public:
        SummonList summons;
        bool _started;
        uint8 servants;
        uint8 _surge;
        bool _beckonphase2;
        uint8 _intermission;
        bool phase4;
        bool phase3;

        void Reset() override
        {
            BossAI::Reset();
            _beckonphase2 = false;
            phase3 = false;
            _started = false;
            phase4 = false;
            servants = 0;
            _intermission = 0;
            _surge = 0;
            me->SetCanFly(true);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_DEFENSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SummonCreature(NPC_FIRST_ARCANIST_THALYSSRA, 206.12f, 2408.97f, 710.80f, 1.280f);
            me->SummonCreature(NPC_JAINA_PROUDMOORE, 201.291f, 2413.060f, 710.797f, 1.425f);
            me->SummonCreature(NPC_LORTHEMAR_THERON, 227.574f, 2412.920f, 710.791f, 1.818f);
            me->SummonCreature(NPC_SHANDRIS_FEATHERMOON, 230.994f, 2416.348f, 710.785f, 1.952f);
            if (Creature* titanConsole = me->FindNearestCreature(NPC_TITAN_CONSOLE, 100.0f, true))
            {
                titanConsole->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                titanConsole->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            }
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 0);
        }

       /* void EnterCombat(Unit*) override
        {
            _EnterCombat();
        }/**/

        void KilledUnit(Unit* target) override
        {
            if (target->IsPlayer() && roll_chance_f(15))
                Talk(22);
        }

        Creature* GetConsole()
        {
            return me->FindNearestCreature(NPC_TITAN_CONSOLE, 100.0f, true);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_RP:
            {
                if (_started)
                    return;
                _started = true;
                Talk(21);
                //At last! The final preparations are in place, and we have a captive audiance.
                me->GetScheduler().Schedule(7s, [this](TaskContext /*context*/)
                {
                    //Stay vigilant champions. Azshara conceals schemes within schemes. She wants something.
                    if (Creature* jaina = me->FindNearestCreature(NPC_JAINA_PROUDMOORE, 100.0f, true))
                        jaina->AI()->Talk(0);
                }).
                Schedule(17s, [this] (TaskContext /*context*/)
                {
                    //You must indulge the theatrical nature of tonight's entertainment. We have waited so very long for this moment, and we simply cannot resist savoring it.
                    Talk(20);
                }).
                Schedule(30s, [this] (TaskContext /*context*/)
                {
                    //Without further ado... The stage is set, the hour is at hand. Legions arise! Serve your queen's command!
                    Talk(19);
                }).
                Schedule(45s, [this] (TaskContext /*context*/)
                {
                    me->AI()->DoAction(ACTION_ENGAGE_COMBAT_AZSHARA);
                });
                break;
            }
            case ACTION_ENGAGE_COMBAT_AZSHARA:
                //I call the cursed loves to enter the stage!
                Talk(24);
                me->SetInCombatWithZone();
                me->SummonCreature(NPC_AETHANEL, firstAdds[1][0]);
                me->SummonCreature(NPC_CYRANUS, 197.82f, 2464.691f, 710.765f);
                HandleWards();
                events.Reset();
                events.ScheduleEvent(EVENT_DRAIN_ANCIENT_WARD, TIMER_DRAIN_ANCIENT_WARD);
                events.ScheduleEvent(EVENT_ARCANE_ORBS, TIMER_ARCANE_ORBS);
                events.ScheduleEvent(EVENT_SUMMON_HULK, TIMER_SUMMON_HULK);
                if (IsMythic())
                    events.ScheduleEvent(EVENT_DIVINE_AND_CONQUER, TIMER_DIVIDE_AND_CONQUER);
                servants = 0;
                break;
            case ACTION_COUNT_SERVANTS_P1:
            {
                ++servants;

                if (servants >= 2)
                {
                    Intermission();
                }
                break;
            }
            case ACTION_COUNT_SURGE:
            {
                ++_surge;

                if (_surge >= 3)
                    me->CastSpell(me, SPELL_CATASTROPHIC_FAILURE, true);
                break;
            }
            case ACTION_REMOVE_SURGE:
                --_surge;
                break;
            }
        }

        void Intermission()
        {
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));            

            me->CastSpell(me, SPELL_QUEENS_DECREE);
            for (uint8 i = 0; i < 4; ++i)
            {
                Position random = me->GetRandomPoint(centerPos, 15.0f);
                me->CastSpell(random, SPELL_ARCANE_ORB_DECREE_AT, true);
            }

            for (uint32 i = 0; i < 4; i++)
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 100.0f);
                if (playerList.size() >= i)
                    playerList.resize(i);

                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                  //  if (IsNormal())
                      //  me->CastSpell((*itr), QueensDecree[i], true);
                    /*else*/ if (IsHeroic())
                    {
                        me->CastSpell((*itr), QueensDecree[i], true);
                        me->CastSpell((*itr), QueensDecreeHeroic[i], true);
                    }
                    else if (IsMythic())
                    {
                        me->CastSpell((*itr), QueensDecree[i], true);
                        me->CastSpell((*itr), QueensDecreeHeroic[i], true);
                        me->CastSpell((*itr), QueensDecreeMythic[i], true);
                    }
                }
            }

            ++_intermission;

            if (_intermission == 1)
                events.ScheduleEvent(EVENT_CHANGE_PHASE2, TIMER_CHANGE_PHASE);
            else if (_intermission == 2)
                events.ScheduleEvent(EVENT_CHANGE_PHASE3, TIMER_CHANGE_PHASE);
        }

        Creature* GetThalyssra()
        {
            return me->FindNearestCreature(NPC_FIRST_ARCANIST_THALYSSRA, 100.0f, true);
        }

        void SummonAddsP2()
        {
            switch (rand() % 2)
            {
            case 1:
                me->SummonCreature(NPC_AZSHARAS_INDOMITABLE, rpAdds[1]);
                break;
            case 2:
                me->SummonCreature(NPC_AZSHARAS_DEVOTED, rpAdds[2]);
                me->SummonCreature(NPC_AZSHARAS_DEVOTED, rpAdds[3]);
                me->SummonCreature(NPC_AZSHARAS_DEVOTED, rpAdds[0]);
                break;
            }
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (me->HealthBelowPct(70) && !phase3)
            {
                phase3 = true;
                Intermission();
            }
            if (me->HealthBelowPct(45) && !phase4)
            {
                phase4 = true;
                Phase4();
            }
        }

        void Phase4()
        {
            events.Reset();
            Talk(14);

            events.ScheduleEvent(EVENT_TITANIC_MACHINATIONS, TIMER_TITANIC_MACHINATIONS);
            events.ScheduleEvent(EVENT_REVERSAL_OF_FORTUNE, TIMER_REVERSAL_OF_FORTUNE);
            events.ScheduleEvent(EVENT_BECKON, TIMER_BECKON);

            events.ScheduleEvent(EVENT_VOID_TOUCHED, TIMER_VOID_TOUCHED);
            events.ScheduleEvent(EVENT_NETHER_PORTAL, TIMER_NETHER_PORTAL);
            events.ScheduleEvent(EVENT_PIERCING_GAZE, TIMER_PIERCING_GAZE);
            events.ScheduleEvent(EVENT_OVERLOAD, TIMER_OVERLOAD);

            if (IsMythic())
                events.ScheduleEvent(EVENT_DIVINE_AND_CONQUER, TIMER_DIVIDE_AND_CONQUER);
        }

        void JustDied(Unit* target) override
        {
            Talk(8);
            _JustDied();
            //instance->DoStartMovie(920); doesn't work because of Moviedb2
            me->SummonGameObject(GO_AZSHARA_CHEST, Position(216.6f, 2475.3f, 710.779f, 4.70423f), QuaternionData(0.0f, 0.0f, -0.709986f, 0.704216f), false);
            instance->SendBossKillCredit(2299);
        }

        void RemoveFrames()
        {
            std::list<Creature*> clist;
            me->GetCreatureListWithEntryInGrid(clist, NPC_CYRANUS, 100.0f);
            me->GetCreatureListWithEntryInGrid(clist, NPC_AETHANEL, 100.0f);
            if (!clist.empty())
            {
                for (auto creature : clist)
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, creature);
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_AETHANEL:
            case NPC_CYRANUS:
                summon->SetInCombatWithZone();
                break;
            case NPC_OVERZEALOUS_HULK:
                summon->SetInCombatWithZone();
                break;
            case NPC_LOYAL_MYRMIDON:
                summon->SetInCombatWithZone();
                summon->SetObjectScale(2.0f);
                break;
            case NPC_WARD:
                summon->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                break;
            }
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            Talk(13);
            RemoveFrames();
            _JustReachedHome();
            summons.DespawnAll();
            std::list<Creature*> wardList;
            me->GetCreatureListWithEntryInGrid(wardList, NPC_WARD, 100.0f);
            for (auto& wards : wardList)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, wards);
                wards->DespawnOrUnsummon();
            }
            _DespawnAtEvade();
        }

        void HandleWards()
        {
            if (Creature* w1 = me->SummonCreature(NPC_WARD, leftWard, TEMPSUMMON_MANUAL_DESPAWN))
                w1->AI()->DoAction(ACTION_NORMAL_ENERGY);
            if (Creature* w2 = me->SummonCreature(NPC_WARD, rightWard, TEMPSUMMON_MANUAL_DESPAWN))
                w2->AI()->DoAction(ACTION_NORMAL_ENERGY);
            if (Creature* w3 = me->SummonCreature(NPC_WARD, southWard, TEMPSUMMON_MANUAL_DESPAWN))
                w3->AI()->DoAction(ACTION_NORMAL_ENERGY);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DRAIN_ANCIENT_WARD:
                {
                    Talk(54);
                    std::ostringstream str;
                    str << "Queen Azshara |cFFF00000|h[Drains]|h|r one of the Ancient Wards!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    std::list<Creature*> wardList;
                    me->GetCreatureListWithEntryInGrid(wardList, NPC_WARD, 100.0f);
                    if (wardList.size())
                    {
                        for (std::list<Creature*>::const_iterator itr = wardList.begin(); itr != wardList.end(); ++itr)
                        {
                            Creature* selectedWard = *itr;

                            me->CastSpell(selectedWard, SPELL_DRAIN_ANCIENT_WARD_VISUAL);
                            selectedWard->SetPower(POWER_ENERGY, selectedWard->GetPower(POWER_ENERGY) - 30);
                        }
                    }

                    events.ScheduleEvent(EVENT_BECKON, TIMER_BECKON);
                    break;
                }
                case EVENT_BECKON:
                {
                    Talk(17);
                    me->CastSpell(me, SPELL_BECKON_CAST);
                    events.ScheduleEvent(EVENT_DRAIN_ANCIENT_WARD, TIMER_DRAIN_ANCIENT_WARD);
                    break;
                }
                case EVENT_ARCANE_ORBS:
                {
                    std::ostringstream str;
                    str << "Queen Azshara litters the field with |cFFF00000|h[Arcane Orbs]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    for (uint8 i = 0; i < 5; ++i)
                    {
                        Position random = me->GetRandomPoint(centerPos, 15.0f);
                        me->CastSpell(random, SPELL_ARCANE_ORBS_MISSILE, true);
                    }

                    events.ScheduleEvent(EVENT_ARCANE_ORBS, TIMER_ARCANE_ORBS);
                    break;
                }
                case EVENT_SUMMON_HULK:
                {
                    me->SummonCreature(NPC_OVERZEALOUS_HULK, centerPos);
                    events.ScheduleEvent(EVENT_SUMMON_HULK, TIMER_SUMMON_HULK);
                    break;
                }
                case EVENT_CHANGE_PHASE2:
                {
                    _beckonphase2 = true;
                    events.Reset();
                    Talk(23);
                    me->NearTeleportTo(azsharaEngage, false);
                    SetCombatMovement(true);
                    me->AddAura(SPELL_ARCANE_MASTERY, me);

                    events.ScheduleEvent(EVENT_BECKON, TIMER_BECKON);
                    events.ScheduleEvent(EVENT_ARCANE_JOLT, TIMER_ARCANE_JOLT);
                    events.ScheduleEvent(EVENT_TITANIC_MACHINATIONS, TIMER_TITANIC_MACHINATIONS);
                    events.ScheduleEvent(EVENT_ARCANE_BURST, TIMER_ARCANE_BURST);
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    events.ScheduleEvent(EVENT_SUMMON_ADDS, TIMER_SUMMON_ADDS);

                    if (IsMythic())
                        events.ScheduleEvent(EVENT_DIVINE_AND_CONQUER, TIMER_DIVIDE_AND_CONQUER);

                    if (Creature* ward = me->SummonCreature(NPC_WARD, centerPos))
                        ward->AI()->DoAction(ACTION_SPECIAL_EVENT);
                    break;
                }
                case EVENT_CHANGE_PHASE3:
                {
                    events.Reset();
                    Talk(46);                   
                    me->AddAura(SPELL_ARCANE_MASTERY, me);

                    events.ScheduleEvent(EVENT_BECKON, TIMER_BECKON);
                    events.ScheduleEvent(EVENT_ARCANE_JOLT, TIMER_ARCANE_JOLT);
                    events.ScheduleEvent(EVENT_TITANIC_MACHINATIONS, TIMER_TITANIC_MACHINATIONS);
                    events.ScheduleEvent(EVENT_ARCANE_BURST, TIMER_ARCANE_BURST);
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);

                    if (IsMythic())
                        events.ScheduleEvent(EVENT_DIVINE_AND_CONQUER, TIMER_DIVIDE_AND_CONQUER);

                    events.ScheduleEvent(EVENT_REVERSAL_OF_FORTUNE, TIMER_REVERSAL_OF_FORTUNE);
                    events.ScheduleEvent(EVENT_SUMMON_TIDEMISTRESSES, 5 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUMMON_LOYAL_MYRMIDON, 2 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_REVERSAL_OF_FORTUNE:
                {
                    Talk(17);
                    //temp
                    break;
                }
                case EVENT_OVERLOAD:
                {
                    Talk(56);
                    std::ostringstream str;
                    str << "The Titan Console begins to |cFFF00000|h[Overload]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);

                    switch (rand() % 3)
                    {
                    case 1:
                    {
                        std::list<Player*> playerList;
                        me->GetPlayerListInGrid(playerList, 100.0f);
                        if (playerList.size() >= 1)
                            playerList.resize(1);

                        if (!playerList.empty())
                        {
                            for (auto player : playerList)
                            {
                                player->AddAura(SPELL_SYSTEM_SHOCK_DAMAGE, player);
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        float radius = 50.0f;
                        Creature* selectedWard = NULL;
                        std::list<Creature*> wards;
                      //  me->GetCreatureListInGrid(wards, 100.0f);
                        if (wards.size())
                        {
                            for (auto ward : wards)
                            {
                                if (me->GetDistance(ward) <= radius)
                                    selectedWard = ward;
                            }
                        }

                        if (selectedWard)
                        {
                            me->CastSpell(selectedWard, SPELL_DRAIN_ANCIENT_WARD_VISUAL, true);
                            selectedWard->SetPower(POWER_ENERGY, selectedWard->GetPower(POWER_ENERGY) - 30);
                        }
                        break;
                    }
                    case 3:
                    {
                        std::list<Player*> playerList;
                        me->GetPlayerListInGrid(playerList, 100.0f);
                        if (playerList.size() >= 1)
                            playerList.resize(1);

                        if (!playerList.empty())
                        {
                            for (auto player : playerList)
                            {
                                player->AddAura(SPELL_ESSENCE_OF_AEROTH, player);
                            }
                        }
                        break;
                    }
                    }

                    if (Creature* titan = me->FindNearestCreature(NPC_TITAN_CONSOLE, 100.0f, true))
                        me->CastSpell(titan, SPELL_OVERLOAD_DUMMY);
                    events.ScheduleEvent(EVENT_MASSIVE_ENERGY_SPIKE, TIMER_MASSIVE_ENERGY_SPIKE);
                    break;
                }
                case EVENT_MASSIVE_ENERGY_SPIKE:
                {
                    if (Creature* titan = me->FindNearestCreature(NPC_TITAN_CONSOLE, 100.0f, true))
                        titan->CastSpell(titan, SPELL_MASSIVE_ENERGY_SPIKE, true);
                    events.ScheduleEvent(EVENT_OVERLOAD, TIMER_OVERLOAD);
                    break;
                }
                case EVENT_SUMMON_TIDEMISTRESSES:
                {
                  //  if (IsNormal())
                    {
                        if (Creature* ward = me->FindNearestCreature(NPC_WARD, 100.0f, true))
                            me->SummonCreature(NPC_LADY_VENOMTONGE, ward->GetPosition());

                        if (Creature* ward2 = me->FindNearestCreature(NPC_WARD, 100.0f, true))
                            me->SummonCreature(NPC_SERENA_SCARSCALE, ward2->GetPosition());
                    }
                   // else
                    {
                        me->SummonCreature(NPC_LADY_VENOMTONGE, rpAdds[1]);
                        me->SummonCreature(NPC_SERENA_SCARSCALE, rpAdds[2]);
                        me->SummonCreature(NPC_VENNA_SEASTORM, rpAdds[3]);
                    }
                    break;
                }
                case EVENT_SUMMON_LOYAL_MYRMIDON:
                {
                    me->SummonCreature(NPC_LOYAL_MYRMIDON, centerPos);
                    events.ScheduleEvent(EVENT_SUMMON_LOYAL_MYRMIDON, TIMER_SUMMON_LOYAL_MYRMIDON);
                    break;
                }
                case EVENT_ARCANE_JOLT:
                {
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_ARCANE_JOLT);
                    events.ScheduleEvent(EVENT_ARCANE_JOLT, TIMER_ARCANE_JOLT);
                    break;
                }
                case EVENT_SUMMON_ADDS:
                    SummonAddsP2();
                    events.ScheduleEvent(EVENT_SUMMON_ADDS, TIMER_SUMMON_ADDS);
                    break;
                case EVENT_TITANIC_MACHINATIONS:
                {
                    float radius = 50.0f;
                    Creature* selectedWard = NULL;
                    std::list<Creature*> wards;
                   // me->GetCreatureListInGrid(wards, 100.0f);
                    if (wards.size())
                    {
                        for (auto ward : wards)
                        {
                            if (me->GetDistance(ward) <= radius)
                                selectedWard = ward;
                        }
                    }

                    if (selectedWard)
                    {
                        me->CastSpell(selectedWard, SPELL_DRAIN_ANCIENT_WARD_VISUAL, true);
                        selectedWard->SetPower(POWER_ENERGY, selectedWard->GetPower(POWER_ENERGY) - 1);
                    }

                    events.ScheduleEvent(EVENT_TITANIC_MACHINATIONS, TIMER_TITANIC_MACHINATIONS);
                    break;
                }
                case EVENT_ARCANE_BURST:
                {
                    Talk(0);
                    me->CastSpell(me, SPELL_ARCANE_BURST_DUMMY);
                    events.ScheduleEvent(EVENT_ARCANE_BURST, TIMER_ARCANE_BURST);
                    break;
                }
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_MANA) == 100)
                    {
                        me->SetPower(POWER_MANA, 0);
                        events.ScheduleEvent(EVENT_ARCANE_DETONATION, 1 * IN_MILLISECONDS);
                    }
                    me->ModifyPower(POWER_MANA, urand(+2, +3));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
                case EVENT_ARCANE_DETONATION:
                {
                    Talk(1);
                    std::ostringstream str;
                    str << "Queen Azshara unleashes an |cFFF00000|h[Arcane Detonation]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(me, SPELL_ARCANE_DETONATION);
                    break;
                }
                case EVENT_VOID_TOUCHED:
                {
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_VOID_TOUCHED);
                    events.ScheduleEvent(EVENT_VOID_TOUCHED, TIMER_VOID_TOUCHED);
                    break;
                }
                case EVENT_NETHER_PORTAL:
                {
                    Talk(52);
                    std::ostringstream str;
                    str << "Queen Azshara creates a |cFFF00000|h[Nether Portal]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    Position portalPos = me->GetRandomPoint(centerPos, 50.0f);
                    me->CastSpell(portalPos, SPELL_NETHER_PORTAL_AT, true);
                    events.ScheduleEvent(EVENT_NETHER_PORTAL, TIMER_NETHER_PORTAL);
                    break;
                }
                case EVENT_PIERCING_GAZE:
                {
                    Talk(49);
                    std::ostringstream str;
                    str << "Queen Azshara summons N'zoth's |cFFF00000|h[Piercing Gaze]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(centerPos, SPELL_PIERCING_GAZE_AT, true);
                    events.ScheduleEvent(EVENT_PIERCING_GAZE, TIMER_PIERCING_GAZE);
                    break;
                }
                case EVENT_DIVINE_AND_CONQUER:
                {
                    Talk(53);
                    std::ostringstream str;
                    str << "Queen Azshara |cFFF00000|h[Divides]|h|r the field in two!";
                    me->TextEmote(str.str().c_str(), 0, true);
                    me->CastSpell(me, SPELL_DIVIDE_AND_CONQUER_CAST);
                    events.ScheduleEvent(EVENT_DIVINE_AND_CONQUER, TIMER_DIVIDE_AND_CONQUER);
                    break;
                }
                }
            }
        }
};

//154959
struct bfa_npc_titan_console : public ScriptedAI
{
    bfa_npc_titan_console(Creature* c) : ScriptedAI(c) { }

private:
    Creature* GetAzshara()
    {
        return me->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true);
    }

    bool GossipHello(Player* player) override
    {
        AddGossipItemFor(player, 0, "Attempt to activate the device.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);

        SendGossipMenuFor(player, 1, me);

        return true;
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    { 
        if (gossipListId == 0)
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

        if (Creature* azshara = GetAzshara())
            azshara->AI()->DoAction(ACTION_RP);

        return true;
    }
};

//153059
struct bfa_npc_aethanel : public ScriptedAI
{
    bfa_npc_aethanel(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    Creature* GetAzshara()
    {
        return me->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true);
    }

    void JustDied(Unit* target) override
    {
        Talk(1);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* azshara = GetAzshara())
            azshara->AI()->DoAction(ACTION_COUNT_SERVANTS_P1);
    }

    void EnterCombat(Unit* target) //override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_LONGING, TIMER_PAINFUL_MEMORIES);
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
        events.ScheduleEvent(EVENT_LIGHTNING_ORB, TIMER_LIGHTNING_ORB);
    }

    void ExecuteEvent(uint32 eventId)// override
    {
        switch (eventId)
        {
        case EVENT_LONGING:
            Talk(0);
            me->CastSpell(me, SPELL_LONGING_CAST);
            events.ScheduleEvent(EVENT_PAINFUL_MEMORIES, TIMER_PAINFUL_MEMORIES);
            break;

        case EVENT_PAINFUL_MEMORIES:
            Talk(2);
            me->CastSpell(me, SPELL_PAINFUL_MEMORIES_CAST);
            events.ScheduleEvent(EVENT_LONGING, TIMER_LONGING);
            break;

        case EVENT_CHAIN_LIGHTNING:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(target, SPELL_CHAIN_LIGHTNING);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
            break;

        case EVENT_COLD_BLAST:
            if (Unit* target = me->GetVictim())
            {
                me->CastSpell(target, SPELL_COLD_BLAST, true);
                if (Aura* blast = target->GetAura(SPELL_COLD_BLAST))
                    if (blast->GetStackAmount() >= 3)
                        me->CastSpell(target, SPELL_ICE_SHARD);
            }
            events.ScheduleEvent(EVENT_COLD_BLAST, TIMER_COLD_BLAST);
            break;

        case EVENT_LIGHTNING_ORB:
            for (uint8 i = 0; i < 3; i++)
            {
                me->SummonCreature(NPC_LIGHTNING_ORB, me->GetRandomNearPosition(25.0f));
            }
            events.Repeat(TIMER_LIGHTNING_ORB);
            break;
        }
    }
private:
    InstanceScript* instance;
    EventMap events;
};

//153060
struct bfa_npc_cyranus : public ScriptedAI
{
    bfa_npc_cyranus(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    Creature* GetAzshara()
    {
        return me->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true);
    }

    void JustDied(Unit* target) override
    {
        Talk(1);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
         if (Creature* azshara = GetAzshara())
                azshara->AI()->DoAction(ACTION_COUNT_SERVANTS_P1);
    }

    void EnterCombat(Unit* target) //override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_LONGING, TIMER_LONGING);
        events.ScheduleEvent(EVENT_CHARGED_SPEAR, TIMER_CHARGED_SPEAR);
        events.ScheduleEvent(EVENT_SERRATED_EDGE, TIMER_SERRATED_EDGE);
    }

    void ExecuteEvent(uint32 eventId) //override
    {
        switch (eventId)
        {
        case EVENT_LONGING:
            Talk(0);
            me->CastSpell(me, SPELL_LONGING_CAST);
            events.ScheduleEvent(EVENT_PAINFUL_MEMORIES, TIMER_PAINFUL_MEMORIES);
            break;

        case EVENT_PAINFUL_MEMORIES:
            Talk(2);
            me->CastSpell(me, SPELL_PAINFUL_MEMORIES_CAST);
            events.ScheduleEvent(EVENT_LONGING, TIMER_LONGING);
            break;

        case EVENT_CHARGED_SPEAR:
        {
            Unit* target = me->GetVictim();
            std::ostringstream str;
            str << "Cyranus aims their|cFFF00000|h[Charged Spear]|h|r at " << target->GetName() << "!";
            me->TextEmote(str.str().c_str(), 0, true);

            float orientation = me->GetOrientation();
            Position pos;
            me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 1.0f, 180.0f, orientation);
          //  me->CastSpell(pos.m_positionX, pos.m_positionY, pos.m_positionZ, SPELL_CHARGED_SPEAR);
            events.ScheduleEvent(EVENT_CHARGED_SPEAR, TIMER_CHARGED_SPEAR);
            break;
        }

        case EVENT_SERRATED_EDGE:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                me->CastSpell(target, SPELL_SERRATED_EDGE, true);
            events.Repeat(2s);
            break;
        }
    }
private:
    InstanceScript* instance;
    EventMap events;
};

//297934
class bfa_spell_longing : public SpellScript
{
    PrepareSpellScript(bfa_spell_longing);

    void HandleDummy()
    {
        if (Unit* caster = GetCaster())
            caster->AddAura(SPELL_LONGING_AURA_PERIODIC, caster);
    }

    void Register()
    {
        AfterCast += SpellCastFn(bfa_spell_longing::HandleDummy);
    }
};

//297937
class bfa_spell_painful_memories : public SpellScript
{
    PrepareSpellScript(bfa_spell_painful_memories);

    void HandleDummy()
    {
        if (Unit* caster = GetCaster())
            caster->AddAura(SPELL_PAINFUL_MEMORIES_AURA_PERIODIC, caster);
    }

    void Register()
    {
        AfterCast += SpellCastFn(bfa_spell_painful_memories::HandleDummy);
    }
};

//297898
class bfa_spell_cursed_heart : public AuraScript
{
    PrepareAuraScript(bfa_spell_cursed_heart);

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster->GetPosition(), SPELL_CURSED_HEART_AT, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_cursed_heart::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//16848, 297900
struct bfa_at_cursed_heart : AreaTriggerAI
{
    bfa_at_cursed_heart(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_CURSED_HEART_AT_DAMAGE))
            at->GetCaster()->CastSpell(target, SPELL_CURSED_HEART_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_CURSED_HEART_AT_DAMAGE))
            target->RemoveAura(SPELL_CURSED_HEART_AT_DAMAGE);
    }
};

//304260 
class bfa_spell_longing_aura : public AuraScript
{
    PrepareAuraScript(bfa_spell_longing_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->AddAura(SPELL_CURSED_HEART_PERIODIC, caster);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAura(SPELL_CURSED_HEART_PERIODIC);
    }

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        switch (caster->GetEntry())
        {
        case NPC_AETHANEL:
        {
            if (Creature* cyranus = caster->FindNearestCreature(NPC_CYRANUS, 100.0f, true))
                if (!caster->IsWithinLOSInMap(cyranus))
                    caster->AddAura(SPELL_TORMENT, caster);
            break;
        }
        case NPC_CYRANUS:
        {
            if (Creature* aethanel = caster->FindNearestCreature(NPC_AETHANEL, 100.0f, true))
                if (!caster->IsWithinLOSInMap(aethanel))
                    caster->AddAura(SPELL_TORMENT, caster);
            break;
        }    
        }
    }

    void Register()
    {
        OnEffectRemove += AuraEffectRemoveFn(bfa_spell_longing_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(bfa_spell_longing_aura::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_longing_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 304267 
class bfa_spell_painful_memories_aura : public AuraScript
{
    PrepareAuraScript(bfa_spell_painful_memories_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->AddAura(SPELL_CURSED_HEART_PERIODIC, caster);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAura(SPELL_CURSED_HEART_PERIODIC);
    }

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        switch (caster->GetEntry())
        {
        case NPC_AETHANEL:
        {
            if (Creature* cyranus = caster->FindNearestCreature(NPC_CYRANUS, 100.0f, true))
                if (caster->IsWithinLOSInMap(cyranus))
                    caster->AddAura(SPELL_TORMENT, caster);
            break;
        }
        case NPC_CYRANUS:
        {
            if (Creature* aethanel = caster->FindNearestCreature(NPC_AETHANEL, 100.0f, true))
                if (caster->IsWithinLOSInMap(aethanel))
                    caster->AddAura(SPELL_TORMENT, caster);
            break;
        }
        }
    }

    void Register()
    {
        OnEffectRemove += AuraEffectRemoveFn(bfa_spell_painful_memories_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(bfa_spell_painful_memories_aura::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_painful_memories_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//155643
struct bfa_npc_overzealous_hulk : public ScriptedAI
{
    bfa_npc_overzealous_hulk(Creature* creature) : ScriptedAI(creature) { }

private:
    std::vector<Position> _wardPos;
    bool _stun;

        void Reset() override
        {
            events.Reset();
            _stun = false;
        }

        void EnterCombat(Unit* target)// override
        {
            events.ScheduleEvent(EVENT_SELECT_RANDOM_WARD, TIMER_SELECT_WARD);
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            switch (pointId)
            {
            case POINT_WARD_REACHED:
            {
                InitPound();
                break;
            }
            }
        }

        void InitPound()
        {
            if (Creature* ward = me->FindNearestCreature(NPC_WARD, 10.0f, true))
                me->CastSpell(ward, SPELL_GROUND_POUND_CHANNEL);
        }

        Position FindWard()
        {
            if (_wardPos.empty())
            {
                if (Creature* ward = me->FindNearestCreature(NPC_WARD, 100.0f, true))
                    return ward->GetPosition();
            }

            Position wardpos = Trinity::Containers::SelectRandomContainerElement(_wardPos);

            _wardPos.erase(find(_wardPos.begin(), _wardPos.end(), wardpos));

            return wardpos;
        }

        void GetWardsToMove()
        {
            _wardPos.clear();

            std::list<Creature*> wards_available;

            me->GetCreatureListWithEntryInGrid(wards_available, NPC_WARD, 100.0f);

            if (wards_available.empty())
                return;

            for (auto& it : wards_available)
                if (it)
                    _wardPos.push_back(it->GetPosition());

        }

        void SelectWard()
        {
            GetWardsToMove();

            Position pos = FindWard();

            me->GetMotionMaster()->MovePoint(POINT_WARD_REACHED, pos, false);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!_stun && me->HasUnitState(UNIT_STATE_CONFUSED) || me->HasUnitState(UNIT_STATE_CONTROLLED) || me->HasUnitState(UNIT_STATE_DISTRACTED) || me->HasUnitState(UNIT_STATE_FLEEING)
                || me->HasUnitState(UNIT_STATE_POSSESSED) || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasUnitState(UNIT_STATE_ROOT))
            {
                _stun = true;
                me->AddAura(SPELL_INFURIATED, me);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DAZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            }

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SELECT_RANDOM_WARD:
                {
                    SelectWard();
                    break;
                }
                }
            }
        }
        private:
            InstanceScript* instance;
            EventMap events;
};

//298531
class bfa_spell_ground_pound : public AuraScript
{
    PrepareAuraScript(bfa_spell_ground_pound);

   void HandlePeriodic(AuraEffect const* aureff)
   {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Creature* ward = caster->FindNearestCreature(NPC_WARD, 10.0f, true))
            ward->SetPower(POWER_ENERGY, ward->GetPower(POWER_ENERGY) - 2);
   }

   void Register()
   {
    OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_ground_pound::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
   }
};

//299094
class bfa_spell_beckon_cast : public SpellScriptLoader
{
public:
    bfa_spell_beckon_cast() : SpellScriptLoader("bfa_spell_beckon_cast") { }

    class bfa_spell_beckon_cast_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_beckon_cast_AuraScript);

        bool phase_changed;

        bool Load()
        {
            phase_changed = false;
            return true;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            Position azshara_position = caster->GetPosition();

            if (!target || !caster)
                return;

            if (Creature* azshara = caster->ToCreature())
            {
                if (CAST_AI(bfa_boss_queen_azshara, azshara->AI())->_beckonphase2 == true)
                {
                    target->MovePosition(azshara_position, 10.0f, 15.0f);
                    phase_changed = true;
                }
                else
                    target->MovePosition(centerPos, 10.0f, 15.0f);
            }
        }

        void HandlePeriodic(AuraEffect const* aureff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;
            if (!phase_changed)
            {
                if (target->GetDistance(centerPos) <= 2.0f)
                {
                    this->Remove();
                    target->CastSpell(target, SPELL_CRUSHING_DEPTHS_SUMMON, true);
                    target->CastSpell(target, SPELL_CRUSHING_DEPTHS_AURA, true);
                }
            }
            else
            {
                if (Creature* azshara = target->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true))
                {
                    if (target->GetDistance(azshara->GetPosition()) <= 2.0f)
                    {
                        this->Remove();
                        target->CastSpell(target, SPELL_DEVOTION, true);
                        std::ostringstream str;
                        str << target->GetName() << " |cFFF00000|h[Devotes]|h|r themseves to Azshara's cause!";
                        GetCaster()->TextEmote(str.str().c_str(), 0, true);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_beckon_cast_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_beckon_cast_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    class bfa_spell_beckon_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_beckon_cast_SpellScript);

        void HandleBeckon()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            playerList.remove_if(noTanks());            

            if (playerList.size() >= (caster->GetMap()->IsMythic() ? 4 : 2))
                playerList.resize(caster->GetMap()->IsMythic() ? 4 : 2);

            for (auto player : playerList)
            {
                caster->AddAura(SPELL_BECKON_CAST, player);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_beckon_cast_SpellScript::HandleBeckon);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_beckon_cast_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_beckon_cast_SpellScript();
    }
};

//155845
struct bfa_npc_crushing_depths_stalker : public ScriptedAI
{
    bfa_npc_crushing_depths_stalker(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* target, uint32& damage) override
    {
        if (damage >= me->GetHealth())
            if (Unit* owner = me->GetOwner())
            {
                owner->RemoveAura(SPELL_CRUSHING_DEPTHS_AURA);
                owner->RemoveAura(SPELL_BECKON_CAST);
            }
    }
};

//153175
struct bfa_npc_ancient_ward : public ScriptedAI
{
    bfa_npc_ancient_ward(Creature* creature) : ScriptedAI(creature) {  }

private:
    bool _surge;
    bool _normal;
    bool _special;

    void Reset() override
    {
        events.Reset();
        //instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        _normal = false;
        _special = false;
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100);
        me->SetDisplayId(169, 0.5f);
    }

    Creature* GetAzshara()
    {
        return me->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true);
    }

    void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_NORMAL_ENERGY:
                events.ScheduleEvent(EVENT_CHECK_PLAYERS, TIMER_CHECK_PLAYERS);
                me->SetPower(POWER_ENERGY, 100);
                _normal = true;
                break;
            case ACTION_SPECIAL_EVENT:
                _special = true;
                events.ScheduleEvent(EVENT_SPECIAL_ENERGY, TIMER_CHECK_PLAYERS);
                break;
            }
        }

    void CheckPlayers()
        {
            if (_special)
            {
                me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 2));

                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 10.0f);
                if (playerList.size() >= 1)
                    playerList.resize(1);

                if (playerList.size())
                {
                    for (auto player : playerList)
                    {
                        if (player->GetDistance(me->GetPosition()) <= 5.0f)
                        {
                            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 1);
                            player->AddAura(SPELL_DRAINED_SOUL, player);
                        }
                    }
                }
            }

            if (_normal)
            {
                me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - urand(1, 2));

                if (me->GetPower(POWER_ENERGY) <= 1)
                {
                    me->CastSpell(centerPos, SPELL_PRESSURE_SURGE, true);
                    if (Creature* azshara = GetAzshara())
                    {
                        if (!_surge)
                        {
                            _surge = true;
                            azshara->AI()->DoAction(ACTION_COUNT_SURGE);
                        }
                    }
                }
                else
                {
                    if (_surge)
                    {
                        if (Creature* azshara = GetAzshara())
                        {
                            _surge = false;
                            azshara->AI()->DoAction(ACTION_REMOVE_SURGE);
                        }
                    }
                }

                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 10.0f);
                if (playerList.size() >= 1)
                    playerList.resize(1);

                if (playerList.size())
                {
                    for (auto player : playerList)
                    {
                        if (player->GetDistance(me->GetPosition()) <= 5.0f)
                        {
                            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
                            player->AddAura(SPELL_DRAINED_SOUL, player);
                        }
                    }
                }
            }
        }

     void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYERS:
                    CheckPlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, TIMER_CHECK_PLAYERS);
                    break;
                case EVENT_SPECIAL_ENERGY:
                    CheckPlayers();
                    events.ScheduleEvent(EVENT_SPECIAL_ENERGY, TIMER_CHECK_PLAYERS);
                    break;
                }
            }
        }
     private:
         InstanceScript* instance;
         EventMap events;
};

//16953
struct bfa_at_arcane_orb : AreaTriggerAI
{
    bfa_at_arcane_orb(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        std::list<Player*> playerList;
        at->GetPlayerListInGrid(playerList, 10.0f);
        if (playerList.size() >= 1)
            playerList.resize(1);

        if (playerList.size())
        {
            for (auto player : playerList)
            {
                if (player->GetDistance(at->GetPosition()) <= 5.0f)
                    player->AddAura(SPELL_ARCANE_ORBS_AURA, player);
                else
                    player->CastSpell(player, SPELL_ARCANE_ORBS_DAMAGE, true);
            }
        }
    }
};

//300502
class bfa_spell_arcane_mastery_periodic : public AuraScript
{
    PrepareAuraScript(bfa_spell_arcane_mastery_periodic);

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster();
            if (!caster)
                return;

        std::list<Player*> playerList;
        caster->GetPlayerListInGrid(playerList, 150.0f);
        if (playerList.size())
        {
            for (auto player : playerList)
            {
                if (caster->IsWithinLOSInMap(player))
                    caster->CastSpell(player, SPELL_ARCANE_MISSILE, true);
            }
        }
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_arcane_mastery_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//304475
class bfa_spell_arcane_jolt : public SpellScript
{
    PrepareSpellScript(bfa_spell_arcane_jolt);

    void HandleHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_ARCANE_VULNERABILITY, true);
    }

    void Register()
    {
        AfterHit += SpellHitFn(bfa_spell_arcane_jolt::HandleHit);
    }
};

//303629
class bfa_spell_arcane_burst_dummy : public SpellScript
{
    PrepareSpellScript(bfa_spell_arcane_burst_dummy);

    void AfterCastDummy()
    {
        std::list<Player*> playerList;
        GetCaster()->GetPlayerListInGrid(playerList, 100.0f);
        playerList.remove_if(noTanks());
        if (playerList.size() >= 2)
            playerList.resize(2);
        if (playerList.size())
        {
            for (auto player : playerList)
            {
                if (player->IsWithinLOSInMap(GetCaster()))
                    player->AddAura(SPELL_ARCANE_BURST_AURA, player);
            }
        }
    }

    void Register()
    {
        AfterCast += SpellCastFn(bfa_spell_arcane_burst_dummy::AfterCastDummy);
    }
};

//303657
class bfa_spell_arcane_burst_aura : public AuraScript
{
    PrepareAuraScript(bfa_spell_arcane_burst_aura);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster->GetPosition(), SPELL_ARCANE_BURST_DAMAGE, true);
        if (caster->GetMap()->IsHeroic())
        {
            if (Creature* azshara = caster->FindNearestCreature(NPC_QUEEN_AZSHARA, 100.0f, true))
                azshara->AddAura(SPELL_FEEDBACK, azshara);
        }
    }

    void Register()
    {
        OnEffectRemove += AuraEffectRemoveFn(bfa_spell_arcane_burst_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//154240,155354
struct bfa_npc_azshara_indomitable_devoted : public ScriptedAI
{
    bfa_npc_azshara_indomitable_devoted(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* target) //override
    {
        events.ScheduleEvent(EVENT_CHARGE_WARD, 2000);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        switch (pointId)
        {
        case POINT_WARD_REACHED:
        {
            if (Creature* ward = me->FindNearestCreature(NPC_WARD, 100.0f, true))
            {
                ward->SetPower(POWER_ENERGY, ward->GetPower(POWER_ENERGY) + 5);
                me->Kill(me);  
            }
            break;
        }           
        }
    }

    void ExecuteEvent(uint32 eventId)// override
    {
        switch (eventId)
        {
        case EVENT_CHARGE_WARD:
            if (Creature* ward = me->FindNearestCreature(NPC_WARD, 100.0f, true))
                me->GetMotionMaster()->MovePoint(POINT_WARD_REACHED, ward->GetPosition(), false);
            break;
        }
    }
private:
    InstanceScript* instance;
    EventMap events;
};

// 17468
struct bfa_at_nether_portal : AreaTriggerAI
{
    bfa_at_nether_portal(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    uint32 _timer;

    void OnCreate() override
    {
       at->SetDuration(120000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_NETHER_PORTAL_AT_DAMAGE))
            at->GetCaster()->CastSpell(target, SPELL_NETHER_PORTAL_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_NETHER_PORTAL_AT_DAMAGE))
            target->RemoveAura(SPELL_NETHER_PORTAL_AT_DAMAGE);
    }
};

//17112, 300784
struct bfa_at_piercing_gaze : AreaTriggerAI
{
    bfa_at_piercing_gaze(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
    {
        if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
            return false;

        if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
        obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
           return false;

        float angleSourceDest = source.GetAngle(&destination);
        float angleSourcePoint = source.GetAngle(obj);

        float angle = fabs(angleSourceDest - angleSourcePoint);
        return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
    }

    /*void OnRemove()
    {
        std::list<Player*> playerList;
        at->GetPlayerListInGrid(playerList, 25.0f);
        if (playerList.size())
        {
            for (auto player : playerList)
            {
                if (IsOnBeam(at, at->GetPosition(), (at->GetPositionY() > 100.0f && at->GetPositionY() < 100.0f), 2.0f, 5.0f, 20.0f))
                    player->CastSpell(player, SPELL_PIERCING_GAZE_DAMAGE, true);
            }
        }
    }*/
};

// 299252
class bfa_spell_march : public AuraScript
{
    PrepareAuraScript(bfa_spell_march);

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster->GetPosition(), SPELL_MARCH_AT, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_march::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//299253
class bfa_spell_stay : public AuraScript
{
    PrepareAuraScript(bfa_spell_stay);

    void HandlePeriodic(AuraEffect const* aureff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->isMoving())
        caster->CastSpell(caster->GetPosition(), SPELL_STAY_AT, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_stay::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 307331
class bfa_spell_divide_and_conquer_cast : public SpellScript
{
    PrepareSpellScript(bfa_spell_divide_and_conquer_cast);

    void DummyScript()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint8 getSpawnPos = urand(0, 2);        
        switch (getSpawnPos)
        {
        case 0:
        {
            Position centerPos = { 216.65f, 2444.94f, 710.65f };
            break;
        }
        case 1:
        {
            Position centerPos = { 216.65f, 2444.94f, 710.65f };
            break;
        }
        case 2:
        {
            Position centerPos = { 216.65f, 2444.94f, 710.65f };
            break;
        }
        }

        caster->CastSpell(getSpawnPos, SPELL_DIVIDE_AND_CONQUER_AT_2, true);
        //caster->CastSpell(centerPos, SPELL_DIVIDE_AND_CONQUER_AT_1, true);
    }

    void Register()
    {
        AfterCast += SpellCastFn(bfa_spell_divide_and_conquer_cast::DummyScript);
    }
};

// 17064, 17869, 300478, 307332
struct bfa_at_divide_and_conquer : AreaTriggerAI
{
    bfa_at_divide_and_conquer(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

private:
    uint32 timer = 2000;
    float x;
    float y;

    /*void OnInitialize()
    {
        x = at->GetPositionX() + 100.0f;
        y = at->GetPositionY() + 100.0f;

        switch (at->GetEntry())
        {
        case 17064:
            at->SetOrientation(4.65f);
            break;

        case 17869:
            at->SetOrientation(3.23f);
            break;
        }

        std::vector<G3D::Vector3> points;
        points.push_back(G3D::Vector3(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ()));
        points.push_back(G3D::Vector3(x, y, at->GetPositionZ()));
        at->InitSplines(points, 10000);
        _timer = 2000;
    }*/

    bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
    {
        if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
            return false;

        if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
            obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
            return false;

        float angleSourceDest = source.GetAngle(&destination);
        float angleSourcePoint = source.GetAngle(obj);

        float angle = fabs(angleSourceDest - angleSourcePoint);
        return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
    }

    /*void OnUpdate(uint32 diff)
    {
        if (timer <= diff)
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 25.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    if (IsOnBeam(at, at->GetPosition(), (at->GetPositionY() > 100.0f && at->GetPositionY() < 100.0f), 2.0f, 5.0f, 20.0f))
                    {
                        player->Say("DIVIDE BEAM DAMAGE", LANG_UNIVERSAL);
                        //at->GetCaster()->Kill(player);
                    }
                }
            }
            timer = 2000;
        }
        else
            timer -= diff;
    }*/
};

//154565
struct bfa_npc_loyal_myrmidon : public ScriptedAI
{
    bfa_npc_loyal_myrmidon(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* target) //override
    {
        events.ScheduleEvent(EVENT_CHARGED_SPEAR, TIMER_CHARGED_SPEAR);
    }

    void ExecuteEvent(uint32 eventId) //override
    {
        switch (eventId)
        {
        case EVENT_CHARGED_SPEAR:
        {
            std::list<Creature*> mistresses;
            me->GetCreatureListWithEntryInGrid(mistresses, NPC_LADY_VENOMTONGE, 100.0f);
            me->GetCreatureListWithEntryInGrid(mistresses, NPC_SERENA_SCARSCALE, 100.0f);
            me->GetCreatureListWithEntryInGrid(mistresses, NPC_VENNA_SEASTORM, 100.0f);
            mistresses.remove_if(checkShield());
            if (mistresses.size())
            {
                for (auto mist : mistresses)
                {
                    me->CastSpell(mist->GetPosition(), SPELL_CHARGED_SPEAR);
                }
            }
            else
            {
                float orientation = me->GetOrientation();
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 1.0f, 180.0f, orientation);
              //  me->CastSpell(pos.m_positionX, pos.m_positionY, pos.m_positionZ, SPELL_CHARGED_SPEAR);
            }

            events.ScheduleEvent(EVENT_CHARGED_SPEAR, TIMER_CHARGED_SPEAR);
            break;
        }
        }
    }
private:
    InstanceScript* instance;
    EventMap events;
};

//153091,153090,153092
struct bfa_npc_tidemistresses : public ScriptedAI
{
    bfa_npc_tidemistresses(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            SetCombatMovement(false);
        }

        void EnterCombat(Unit* target) //override
        {
            events.ScheduleEvent(EVENT_STATIC_SHOCK, TIMER_STATIC_SHOCK);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
            events.ScheduleEvent(EVENT_DRAIN_ANCIENT_WARD, TIMER_DRAIN_ANCIENT_WARD);
            events.ScheduleEvent(EVENT_CRYSTALLINE_SHIELD, urand(30, 50) * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STATIC_SHOCK:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    if (playerList.size() >= 4)
                        playerList.resize(4);

                    if (playerList.size())
                    {
                        for (auto player : playerList)
                        {
                            player->AddAura(SPELL_STATIC_SHOCK, player);
                        }
                    }

                    events.ScheduleEvent(EVENT_STATIC_SHOCK, TIMER_STATIC_SHOCK);
                    break;
                }
                case EVENT_CHAIN_LIGHTNING:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true, 0))
                        me->CastSpell(target, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
                    break;
                }
                case EVENT_CRYSTALLINE_SHIELD:
                    me->CastSpell(me, SPELL_CRYSTALLINE_SHIELD, true);
                    events.ScheduleEvent(EVENT_CRYSTALLINE_SHIELD, urand(30, 50) * IN_MILLISECONDS);
                    break;
                case EVENT_DRAIN_ANCIENT_WARD:
                {
                    std::list<Creature*> wardList;
                    me->GetCreatureListWithEntryInGrid(wardList, NPC_WARD, 100.0f);
                    if (wardList.size())
                    {
                        for (std::list<Creature*>::const_iterator itr = wardList.begin(); itr != wardList.end(); ++itr)
                        {
                            Creature* selectedWard = *itr;

                            me->CastSpell(selectedWard, SPELL_DRAIN_ANCIENT_WARD_VISUAL);
                            selectedWard->SetPower(POWER_ENERGY, selectedWard->GetPower(POWER_ENERGY) - 30);
                        }
                    }
                    events.ScheduleEvent(EVENT_DRAIN_ANCIENT_WARD, TIMER_DRAIN_ANCIENT_WARD);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
private:
    InstanceScript* instance;
    EventMap events;
};

//300807
class bfa_spell_overload_dummy : public SpellScript
{
    PrepareSpellScript(bfa_spell_overload_dummy);

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_OVERLOAD_SHORT_CIRCUIT_AT_MISSILE, true);
    }

    void Register()
    {
        AfterCast += SpellCastFn(bfa_spell_overload_dummy::HandleAfterCast);
    }
};

//153521
struct npc_lightning_orbs_ep : public ScriptedAI
{
    npc_lightning_orbs_ep(Creature* creature) : ScriptedAI(creature) { }

private:
    uint8 bounceCount;

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        this->bounceCount = 0;
        me->AddAura(SPELL_LIGHTNING_ORB_VISUAL, me);
        me->SetReactState(REACT_PASSIVE);        
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (this->bounceCount <= 3)
            {
                bounceCount++;
                me->CastSpell(me->GetRandomNearPosition(15.0f), SPELL_LIGHTNING_ORB_DAMAGE, true);
                context.Repeat(5s);
            }
            if (this->bounceCount == 3)
                me->DespawnOrUnsummon(7s);
        });
    }
};

void AddSC_boss_queen_azshara_ep()
{
    RegisterCreatureAI(bfa_boss_queen_azshara);
    RegisterAreaTriggerAI(bfa_at_arcane_orb);
    RegisterAreaTriggerAI(bfa_at_cursed_heart);
    RegisterAreaTriggerAI(bfa_at_divide_and_conquer);
    RegisterAreaTriggerAI(bfa_at_nether_portal);
    RegisterAreaTriggerAI(bfa_at_piercing_gaze);
    RegisterCreatureAI(bfa_npc_aethanel);
    RegisterCreatureAI(bfa_npc_ancient_ward);
    RegisterCreatureAI(bfa_npc_azshara_indomitable_devoted);
    RegisterCreatureAI(bfa_npc_crushing_depths_stalker);
    RegisterCreatureAI(bfa_npc_cyranus);
    RegisterCreatureAI(bfa_npc_loyal_myrmidon);
    RegisterCreatureAI(bfa_npc_overzealous_hulk);
    RegisterCreatureAI(bfa_npc_tidemistresses);
    RegisterCreatureAI(bfa_npc_titan_console);
    RegisterSpellScript(bfa_spell_overload_dummy);
    RegisterAuraScript(bfa_spell_arcane_burst_aura);
    RegisterSpellScript(bfa_spell_arcane_burst_dummy);
    RegisterSpellScript(bfa_spell_arcane_jolt);
    RegisterAuraScript(bfa_spell_arcane_mastery_periodic);
    new bfa_spell_beckon_cast(); //RegisterSpellAndAuraScriptPair
    RegisterAuraScript(bfa_spell_cursed_heart);
    RegisterSpellScript(bfa_spell_divide_and_conquer_cast);
    RegisterAuraScript(bfa_spell_ground_pound);
    RegisterSpellScript(bfa_spell_longing);
    RegisterAuraScript(bfa_spell_longing_aura);
    RegisterAuraScript(bfa_spell_march);
    RegisterAuraScript(bfa_spell_stay);
    RegisterSpellScript(bfa_spell_painful_memories);
    RegisterAuraScript(bfa_spell_painful_memories_aura);
    RegisterCreatureAI(npc_lightning_orbs_ep);
}
