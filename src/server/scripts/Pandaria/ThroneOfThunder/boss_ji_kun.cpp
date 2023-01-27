#include "GameObjectAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h" 
#include "CreatureTextMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "VehicleDefines.h"
#include "SpellInfo.h"

#include "throne_of_thunder.h"

/*
    NOTE:
    Ji-Kun's young are located throughout the roost and progress through different stages of life. After a period of incubation Young Eggs of Ji-Kun will hatch into Hatchlings.
    When fed by Ji-Kun, the Hatchlings then mature into Fledglings. Both Fledgling Eggs and Mature Eggs will hatch into Juveniles.
*/

enum Spells
{
    // Ji-Kun.

    // Infected talons
    SPELL_INFECTED_TALONS_AURA = 140094, // Boss check aura on successful melee ability.
    SPELL_INFECTED_TALONS_DAMAGE = 140092, // Player debuff.

    // Talon Rake
    SPELL_TALON_RAKE = 134366, // Damage + increase.

    // Quills
    SPELL_QUILLS = 134380, // Triggers SPELL_QUILLS_DAMAGE damage and SPELL_QUILLS_PERIODIC (Effect 1).
    SPELL_QUILLS_DAMAGE = 134381, // Quills damage.
    SPELL_QUILLS_PERIODIC = 138649, // Periodic dummy - cast of SPELL_QUILLS_VISUAL.
    SPELL_QUILLS_VISUAL = 138650, // Quills visual.

    // Down Draft
    SPELL_DOWN_DRAFT = 134370, // Areatrigger aura.

    // Caw
    SPELL_CAW = 138923, // Script Effect for SPELL_CAW_MISSILE (Effect 0).
    SPELL_CAW_MISSILE = 138926, // Triggers SPELL_CAW_DAMAGE.
    SPELL_CAW_DAMAGE = 134375, // Damage in 8 yards.

    /*
        Flying mechanic:

        When an egg or hatchling from the lower nests located around Ji-Kun's roost is slain it leaves behind a feather for players to loot.
        This feather grants the player Daedalian Wings. Daedalian Wings grants the player an extra action button that allows players to take flight for 10 sec.
    */

    // Drop feather
    SPELL_DROP_FEATHER = 140016, // 140016 Summons lootable feather.

    // Daedelian Wings
    SPELL_DAEDELIAN_WINGS = 134339, // 140014 LFR version (No CD trigger). Flight spell + SPELL_LESSON_OF_ICARUS trigger. Stacks added / aura removed using this spell.
    SPELL_LESSON_OF_ICARUS = 140571, // Cooldown 1 minute Dummy (Effect 0) - Cannot pickup wings.
    SPELL_FLIGHT_ACTION_BUTTON = 133755, // Action button spell on Daedelian Wings. Removes 1 stack and makes player fly.

    /*
        Feed mechanic:

        Ji-Kun spits up globs of food for her young. If a Hatchling has called out for food, Ji-Kun will aim this ability in their direction;
        otherwise the food will land at random locations around Ji-Kun's platform. When the food lands on the ground, it forms a Feed Pool.
        While a glob of food is traveling through the air, players with Flight can intercept it to prevent a Feed Pool from forming.
        Doing so afflicts the player with Slimed, but also grants Primal Nutriment.
    */

    // Feed young
    SPELL_FEED_YOUNG = 137528, // Triggers SPELL_REGURGITATE each 1 sec on Normal / 2.5 sec on Heroic.
    SPELL_REGURGITATE = 134385, // Script effect (Effect 0) for summoning NPC_FEED_POOL / NPC_FEED_HATCHLINGS.

    // Feed pool
    SPELL_FEED_POOL_DMG = 138319, // Periodic damage.
    SPELL_FEED_POOL_VISUAL = 138854, // Green visual, on platform.
    SPELL_FEED_POOL_VISUAL_HATCHLING = 139284, // Yellow visual, on hatchlings in nest.
    SPELL_SUMMON_POOL = 134259, // Main platform, summons NPC_POOL_OF_FEED.
    SPELL_SUMMON_POOL_HATCHLINGS = 139285, // Hatchling nest, summons NPC_POOL_OF_FEED_HATCHLING.

    SPELL_SLIMED = 134256, // On players intercepting Ji-Kun's food globules. Periodic damage and Script Effect (Effect 1) for SPELL_SLIMED_DMG_INCREASE.
    SPELL_SLIMED_DMG_INCREASE = 138309, // 10% damage increase from next Slimed.

    SPELL_PRIMAL_NUTRIMENT = 140741, // On players intercepting Ji-Kun's food globules. Eff 0 + 1 Dummy A. H / D incr., SPELL_PRIMAL_NUTRIMENT_INCREASE trigger on Eff 2.
    SPELL_PRIMAL_NUTRIMENT_INCREASE = 112879, // 30% Healing and 100% Damage increase.

    // Ji-Kun's Flock.

    // Hatchling

    SPELL_HATCHLING_CHEEP = 139296, // Triggers SPELL_HATCHLING_CHEEP_DAMAGE in 10 yards.
    SPELL_HATCHLING_CHEEP_DAMAGE = 139298,
    SPELL_CHEEP_AOE = 140129,
    SPELL_INCUBATION_LOW_NEST = 134347, // 10 sec incubation
    SPELL_INCUBATION_HIGH_NEST = 134335, // 20 sec incubation

    SPELL_SUMMON_YOUNG_HATCHLING = 134336,
    SPELL_SUMMON_JUVENILE = 138905,

    SPELL_HATCHLING_EVOLUTION = 134322,

    SPELL_HATCHLING_EATING = 134321,

    // Fledgling

    SPELL_FLEDGLING_LAY_EGG = 134367, // Summons NPC_FLEDGLING_EGG_JIKUN.
    SPELL_FLEDGLING_CHEEP = 140570, // Needs target limitation.

    // Juvenile

    SPELL_JUVENILE_CHEEP = 140227, // Script effect (Effect 0) for SPELL_JUVENILE_CHEEP_DAMAGE in 60 yards.
    SPELL_JUVENILE_CHEEP_DAMAGE = 140129, // Damage in 10 yards.

    // Nest Guardian - HEROIC!

    SPELL_GUARDIAN_TALON_STRIKE = 139100, // Weapon damage 180 degree arc.
    SPELL_GUARDIAN_SCREECH = 140640, // Damage, Interrupt, Script Effect (Effect 2) for SPELL_GUARDIAN_SCREECH_SLOW. If not actively engaged in melee combat.
    SPELL_GUARDIAN_SCREECH_SLOW = 134372, // Slow casting on targets (Removed after casting any spell). Mana users.

    SPELL_BEAM_VISUAL = 137526, // visual aur of beam

    SPELL_TALON_STRIKE = 139100,
    SPELL_SCREECH = 140640,
    SPELL_SCREECH_STACKS = 134372,
};

enum FeedMovementPoints
{
    POINT_GREEN_FEED_AIR = 1,
    POINT_GREEN_FEED_GROUND = 2,
    POINT_FEED_CAME_TO_HATCHLING = 3,
    POINT_FOOD_AIR = 4,
};

enum JuvenileMovementPoints
{
    POINT_MOVE_TO_CENTER_FLY = 1,
};

enum HatchlingMovementPoints
{
    POINT_MOVE_TO_EAT_POOL = 1,
};

enum JikunMovementPoints
{
    POINT1 = 1,
    POINT2 = 2,
};

enum EventsJiKun
{
    EVENT_TALON_RAKE = 1,
    EVENT_QUILLS,
    EVENT_DOWN_DRAFT,
    EVENT_DOWN_DRAFT_FALL,
    EVENT_CAW,
    EVENT_CAW_MISSILE,
    EVENT_ACTIVATE_NEST, // old codish
    EVENT_FEED_YOUNG,
    EVENT_CHECK_MELEE,
    EVENT_TALON_STRIKE,
    EVENT_QUILLS_MELEE,
    EVENT_ACTIVATE_NESTS,
};

enum EventsHatchlings
{
    EVENT_FIND_EAT = 1,
    EVENT_CHEEP,
    EVENT_LAY_EGG,
    EVENT_FEED_POOL_DAMAGE,
};

enum EventsJuvenile
{
    EVENT_START_FLY_AWAY = 1,
    EVENT_JUVENILE_CHEEP,
};

enum EggsJikun
{
    EVENT_SUMMON_HATCHLING = 1,
};

enum Npcs
{
    // Ji-Kun.
    NPC_YOUNG_EGG_OF_JIKUN = 68194, // Hatches to Hatchling.
    NPC_FLEDGLING_EGG_JIKUN = 68202, // Hatches to Juvenile.
    NPC_MATURE_EGG_OF_JIKUN = 69628, // Hatches to Juvenile.

    NPC_JIKUN_HATCHLING = 68192,
    NPC_JIKUN_FLEDGLING = 68193,
    NPC_JIKUN_JUVENILE = 70095,

    NPC_JIKUN_NEST_GUARDIAN = 70134, // HEROIC only!

    NPC_FEED_POOL = 68178, // Feed NPC's. also spawn visual 48142
    NPC_FEED_HATCHLINGS = 70130, // spawn visual 48210

    NPC_POOL_OF_FEED = 68188, // Feed Pool NPC's.
    NPC_POOL_OF_FEED_HATCHLING = 70216,

    NPC_BEAM_NEST = 68208, // Visual beam of active nest
};

enum Gameobjects
{
    GOB_FEATHER_OF_JIKUN = 216453,
};

// Center
const Position Center = { 6146.085f, 4319.261f, -30.608f, 2.739f };

// Ji-Kun intro movement.
Position const IntroMoving[2] =
{
    { 6213.971f, 4289.072f, -14.402f, 2.873f },
    { 6146.085f, 4319.261f, -30.608f, 2.739f }
};

// Ji-Kun low nest positions.
Position const NestPositionsGround[5] =
{
    { 6071.182f, 4285.108f, -101.469f, 1.873f },
    { 6096.028f, 4339.460f, -93.655f, 1.873f },
    { 6159.814f, 4370.529f, -70.502f, 1.873f },
    { 6220.071f, 4333.520f, -57.075f, 1.873f },
    { 6192.708f, 4267.664f, -70.764f, 1.873f }
};

// Ji-Kun high nest positions.
Position const NestPositionsHigh[5] =
{
    { 6078.422f, 4270.403f, 42.407f, 1.873f },
    { 6082.500f, 4371.428f, 45.238f, 1.873f },
    { 6151.905f, 4330.750f, 72.997f, 1.873f },
    { 6217.987f, 4352.961f, 68.138f, 1.873f },
    { 6173.894f, 4239.375f, 43.848f, 1.873f }
};

enum Actions
{
    ACTION_FOOD_AIR = 5,
};

uint32 const EggsLowNest = 15; // size of eggs on low nests
uint32 const EggsHighNest = 10;// size of eggs on high nests

Unit* SelectRandomTargetWithGuidOnRange(Unit* FromWho, uint32 entry, float range, bool player)
{
    std::list<Player*> PlayerList;
    std::list<Creature*> CreatureList;

    if (player)
        GetPlayerListInGrid(PlayerList, FromWho, range);
    else
        GetCreatureListWithEntryInGrid(CreatureList, FromWho, entry, range);

    if (player && !PlayerList.empty())
    {
        if (Player* target = Trinity::Containers::SelectRandomContainerElement(PlayerList))
            return target->ToUnit();
    }
    else if (!CreatureList.empty())
    {
        if (Creature* target = Trinity::Containers::SelectRandomContainerElement(CreatureList))
            return target->ToUnit();
    }

    return NULL;
}

// Ji-Kun - 69712.
class boss_jikun : public CreatureScript
{
public:
    boss_jikun() : CreatureScript("boss_jikun") { }

    struct boss_jikunAI : public BossAI
    {
        boss_jikunAI(Creature* creature) : BossAI(creature, DATA_JI_KUN), summons(me)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        uint64 NestLowEggs[5][EggsLowNest], NestHighEggs[5][EggsHighNest];
        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool lastNestHigh, introDone;
        bool lowerNest;
        uint8 nests;

        /*** SPECIAL FUNCTIONS ***/

        void PreIntro()
        {
            // introDone = false;
             //me->SetVisible(false);
            // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            // me->SetReactState(REACT_PASSIVE);
        }

        void ActivateFeather()
        {
            std::list<GameObject*> jikunFeatherList;
            GetGameObjectListWithEntryInGrid(jikunFeatherList, me, GOB_JIKUN_FEATHER, 200.0f);

            for (auto feather : jikunFeatherList)
            {
                feather->SetRespawnTime(0);
                feather->UpdateObjectVisibility();
            }
        }

        void SummonEggs()
        {
            // 5 places of eggs
            for (uint8 i = 0; i < 5; ++i)
            {
                // bottom places 15 eggs in nest
                for (uint8 j = 0; j < EggsLowNest; ++j)
                {
                    Position summonPos;
                    me->GetRandomPoint(NestPositionsGround[i], 7.0f);

                    Creature* egg = me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, summonPos.GetPositionX(), summonPos.GetPositionY(), summonPos.GetPositionZ());
                }

                // top places 10 eggs in nest
                for (uint8 c = 0; c < EggsHighNest; ++c)
                {
                    Position summonPosHigh;
                    me->GetRandomPoint(NestPositionsHigh[i], 6.0f);

                    me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, summonPosHigh.GetPositionX(), summonPosHigh.GetPositionY(), summonPosHigh.GetPositionZ() + 3.0f);
                }
            }
        }

        void RemoveAllAurasAndDespawnSummons()
        {
            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PRIMAL_NUTRIMENT);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TALON_RAKE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DAEDELIAN_WINGS);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SLIMED_DMG_INCREASE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFECTED_TALONS_DAMAGE);
            }

            DespawnCreature(NPC_FEED_POOL);
            DespawnCreature(NPC_POOL_OF_FEED);
            DespawnCreature(NPC_POOL_OF_FEED_HATCHLING);
            DespawnCreature(NPC_JIKUN_JUVENILE);
            DespawnCreature(NPC_JIKUN_HATCHLING);
            DespawnCreature(NPC_YOUNG_EGG_OF_JIKUN);
            DespawnCreature(NPC_MATURE_EGG_OF_JIKUN);
            DespawnCreature(NPC_FLEDGLING_EGG_JIKUN);
            DespawnCreature(NPC_JIKUN_NEST_GUARDIAN);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        uint64 GetEggGUID(uint8 NestNumber, bool HighEggs)
        {
            if (!instance)
                return 0;

            std::list<Creature*> EggList;
            for (uint8 i = 0; i <= (HighEggs ? (EggsHighNest - 1) : (EggsLowNest - 1)); ++i)
                if (Creature* Egg = instance->GetCreature(NestHighEggs[NestNumber][i]))
                    if (Egg->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                        EggList.push_back(Egg);

            if (!EggList.empty())
                Trinity::Containers::SelectRandomContainerElement(EggList);

            return 0;
        }

        /*** NORMAL FUNCTIONS ***/

        void Reset()
        {
            RemoveAllAurasAndDespawnSummons();

            lastNestHigh = true;
            lowerNest = false;
            me->SetDisableGravity(true);
            me->SetCanFly(true);

            events.Reset();

            //SummonEggs();

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (instance)
                instance->SetBossState(DATA_JI_KUN, NOT_STARTED);
            RemoveFeathers();
        }

        void EnterCombat(Unit* who)
        {
            nests = 0; // just to be sure its reseted
            DoCast(me, SPELL_INFECTED_TALONS_AURA);
            events.ScheduleEvent(EVENT_TALON_RAKE, 5000);
            events.ScheduleEvent(EVENT_QUILLS, 40000);
            events.ScheduleEvent(EVENT_DOWN_DRAFT, 90000);
            events.ScheduleEvent(EVENT_CAW, 16000);
            events.ScheduleEvent(EVENT_QUILLS_MELEE, 3000, 0, 0);
            //events.ScheduleEvent(EVENT_ACTIVATE_NEST, 9000);
            events.ScheduleEvent(EVENT_ACTIVATE_NESTS, 9000);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (instance)
                instance->SetBossState(DATA_JI_KUN, IN_PROGRESS);
            RemoveFeathers();
            //SummonEggs();
        }

        void EnterEvadeMode(EvadeReason w)
        {
            me->RemoveAllAuras();
            Reset();
            me->DeleteThreatList();
            me->CombatStop(true);
            me->GetMotionMaster()->MoveTargetedHome();

            me->AddUnitState(UNIT_STATE_EVADE);
            nests = 0;

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove.
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
            //summon->setActive(true);

            if (me->IsInCombat())
                summon->SetInCombatWithZone();

            switch (summon->GetEntry())
            {
            case NPC_JIKUN_JUVENILE:
                summon->SetInCombatWithZone();
                break;
            }
        }

        void RemoveFeathers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->HasSpell(SPELL_FLIGHT_ACTION_BUTTON))
                        player->RemoveSpell(SPELL_FLIGHT_ACTION_BUTTON);
                }
        }

        void RemoveScreech()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(134372); // screech debuff
                }
        }

        void JustDied(Unit* pKiller) override
        {
            RemoveScreech();
            RemoveAllAurasAndDespawnSummons();
            summons.DespawnAll();
            RemoveFeathers();
            if (instance)
            {
                ActivateFeather();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_JI_KUN, DONE);
            }
            me->SummonCreature(999270, 6124.06f, 4354.29f, -31.86f, 2.03f, TEMPSUMMON_TIMED_DESPAWN, 30 * IN_MILLISECONDS * MINUTE);
        }

        void DoAction(int32 uiAction) override
        {
            if (uiAction == ACTION_START_INTRO)
            {
                if (introDone)
                    return;

                me->GetMotionMaster()->MovePoint(POINT1, IntroMoving[0]);

                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetVisible(true);
                me->SetHomePosition(IntroMoving[1]);

                DoPlaySoundToSet(me, 36213); // pre agro

                introDone = true;
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            switch (id)
            {
            case POINT1:
                me->GetMotionMaster()->MoveJump(IntroMoving[1].GetPositionX(), IntroMoving[1].GetPositionY(), IntroMoving[1].GetPositionZ(), 15.0f, 10.0f, POINT2);
                break;
            case POINT2:
                // me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                introDone = true;
                break;
            }
        }

        // values are for 10 man raids
        void UpdateNestState10()
        {
            ++nests;
            if (nests == 1 || nests == 3)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            //NEST GUARDIAN
            if (nests == 2)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            // NEST GUARDIAN
            if (nests == 4)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
                lowerNest = false;
            }
            if (nests == 5 || nests == 6)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
                lowerNest = false;
            }
            if (nests == 7)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            // NEST GUARDIAN
            if (nests == 8)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            if (nests == 9)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 position2 = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[position2], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            // NEST GUARDIAN
            if (nests == 10)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 pos2 = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos2], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            if (nests == 11)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
                lowerNest = false;
            }
            // NEST GUARDIAN
            if (nests == 12)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
                lowerNest = false;
                nests = 0;
            }
        }

        // values are for 25 man raids
        void UpdateNestState25()
        {
            ++nests;
            if (nests == 1 || nests == 3 || nests == 4)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            // NEST GUARDIAN
            if (nests == 2)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            if (nests == 5)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 position2 = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[position2], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            // NEST GUARDIAN
            if (nests == 6)
            {
                uint8 pos = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            if (nests == 7 || nests == 8)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            if (nests == 9 || nests == 10)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 position2 = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[position2], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            if (nests == 11)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 position2 = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[position2], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            // NEST GUARDIAN
            if (nests == 12)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 pos2 = urand(0, 4);
                if (Creature* beam = me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[pos2], TEMPSUMMON_TIMED_DESPAWN, 25000))
                {
                    if (beam->GetMap()->IsHeroic())
                        beam->SummonCreature(NPC_JIKUN_NEST_GUARDIAN, beam->GetPositionX(), beam->GetPositionY(), beam->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);
            }
            if (nests == 13 || nests == 14)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;
            }
            if (nests == 15 || nests == 16)
            {
                uint8 pos = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsGround[pos], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the lower nests begin to hatch!", 0, true);
                lowerNest = true;

                uint8 position2 = urand(0, 4);
                me->SummonCreature(NPC_BEAM_NEST, NestPositionsHigh[position2], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote("The eggs in one of the upper nests begin to hatch!", 0, true);

                nests = 0;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // only in combat, for .. reasons
            if (me->IsInCombat())
            {
                CheckPlayersHover();
                CheckFlyingHacks();
            }
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_ACTIVATE_NESTS:
            {
                switch (me->GetMap()->GetDifficultyID())
                {
                case DIFFICULTY_10_N:
                case DIFFICULTY_10_HC:
                    UpdateNestState10();
                    break;
                case DIFFICULTY_25_HC:
                case DIFFICULTY_25_N:
                    UpdateNestState25();
                    break;
                }
                events.ScheduleEvent(EVENT_ACTIVATE_NESTS, 30000, 0, 0);
                events.ScheduleEvent(EVENT_FEED_YOUNG, 5000);
                break;
            }
            case EVENT_ACTIVATE_NEST:
            {
                bool IsHighActivate = lastNestHigh ? false : true;
                lastNestHigh = IsHighActivate;
                uint8 NestNumber = urand(0, 4);

                if (instance)
                    for (uint8 i = 0; i <= (IsHighActivate ? 1 : 2); ++i)
                        if (Creature* Egg = instance->GetCreature(GetEggGUID(NestNumber, IsHighActivate)))
                        {
                            Egg->AddAura(IsHighActivate ? SPELL_INCUBATION_HIGH_NEST : SPELL_INCUBATION_LOW_NEST, Egg);
                            Egg->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            Egg->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        }

                me->SummonCreature(NPC_BEAM_NEST, IsHighActivate ? NestPositionsHigh[NestNumber].GetPositionX() : NestPositionsGround[NestNumber].GetPositionX(), IsHighActivate ? NestPositionsHigh[NestNumber].GetPositionY() : NestPositionsGround[NestNumber].GetPositionY(), IsHighActivate ? -31.00f : NestPositionsGround[NestNumber].GetPositionZ() + 7.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->TextEmote(IsHighActivate ? "The eggs in one of the upper nests begin to hatch!" : "The eggs in one of the lower nests begin to hatch!", 0, true);

                if (!IsHighActivate)
                    events.ScheduleEvent(EVENT_FEED_YOUNG, 12000);
                events.ScheduleEvent(EVENT_ACTIVATE_NEST, 25000);
                break;
            }

            case EVENT_FEED_YOUNG:
                if (lowerNest)
                    DoCast(me, SPELL_FEED_YOUNG);
                break;

            case EVENT_TALON_RAKE:
                DoCast(me->GetVictim(), SPELL_TALON_RAKE);
                events.ScheduleEvent(EVENT_TALON_RAKE, 20000);
                break;
            case EVENT_QUILLS:
                me->TextEmote("|TInterface\\Icons\\ability_hunter_pet_dragonhawk.blp:20|tJi-Kun sends her |cFFFF0000|Hspell:134380|h[Quills]|h|r flying in all directions!", 0, true);
                DoCast(me, SPELL_QUILLS);
                events.ScheduleEvent(EVENT_QUILLS, 65000);
                break;
            case EVENT_QUILLS_MELEE:
                if (me->HasAura(SPELL_QUILLS))
                {
                    events.CancelEvent(EVENT_QUILLS_MELEE);
                    events.ScheduleEvent(EVENT_QUILLS_MELEE, 5000, 0, 0);
                }
                else if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me, SPELL_QUILLS);
                }
                events.ScheduleEvent(EVENT_QUILLS_MELEE, 5000, 0, 0);
                break;
            case EVENT_DOWN_DRAFT:
                me->TextEmote("|TInterface\\Icons\\ability_druid_galewinds.blp:20|tJi-Kun uses her wings to create a massive |cFFFF0000|Hspell:134370|h[Down Draft]|h|r!", 0, true);
                DoCast(SPELL_DOWN_DRAFT);
                events.ScheduleEvent(EVENT_DOWN_DRAFT, 90000);
                //events.ScheduleEvent(EVENT_DOWN_DRAFT_FALL, 2500);
                break;

            case EVENT_DOWN_DRAFT_FALL:
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* playerTarget = i->GetSource())
                        if (playerTarget->GetDistance2d(me) <= 50.0f)
                            if (!playerTarget->HasAura(SPELL_DAEDELIAN_WINGS))
                                playerTarget->NearTeleportTo(playerTarget->GetPositionX() - 4.0f * cos(playerTarget->GetAngle(me)), playerTarget->GetPositionY() - 1.6f * sin(playerTarget->GetAngle(me)), playerTarget->GetPositionZ(), playerTarget->GetOrientation());

                if (me->HasAura(SPELL_DOWN_DRAFT))
                    events.ScheduleEvent(EVENT_DOWN_DRAFT_FALL, 500);
                break;
            }
            case EVENT_CAW:
                me->TextEmote("|TInterface\\Icons\\ability_hunter_animalhandler.blp:20|tJi-Kun |cFFFF0000|Hspell:138923|h[Caws]|h|r, sending powerful sound waves at her enemies!", 0, true);
                DoCast(SPELL_CAW);
                events.ScheduleEvent(EVENT_CAW_MISSILE, 2600);
                events.DelayEvents(2700);
                events.ScheduleEvent(EVENT_CAW, 16000);
                break;
            case EVENT_CAW_MISSILE:
                DoCastAOE(SPELL_CAW_MISSILE);
                break;
            default: break;
            }

            if (!me->HasUnitState(UNIT_STATE_CASTING))
                DoMeleeAttackIfReady();
        }

        bool CheckPlayersHover()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive())
                    {
                        if (player->GetPositionZ() < -104.0f)
                        {
                            player->NearTeleportTo(6106.84f, 4296.02f, -29.77f, 0.41f, false);
                            //sWorld->SendWorldText(3, "asd");
                        }
                    }
                }
            return true;
        }

        bool CheckFlyingHacks()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive())
                    {
                        if (player->IsFlying() && !player->HasAura(133755) && !player->IsGameMaster()) // If players are flying and they don't have Flying aura from button AND is not GM ON active, kill and kick, fuck 'em
                        {
                            player->Kill(player, true);
                            player->GetSession()->KickPlayer();
                        }
                    }
                }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jikunAI(creature);
    }
};

// Beam target - 68208.
class jikun_beam_target : public CreatureScript
{
public:
    jikun_beam_target() : CreatureScript("jikun_beam_target") { }

    struct jikun_beam_targetAI : public ScriptedAI
    {
        jikun_beam_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetCanFly(true);
            me->SetDisplayId(11686);
            me->SetFaction(14);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddAura(SPELL_BEAM_VISUAL, me);
        }

        void IsSummonedBy(Unit* summoner)
        {
            if (me->GetPositionZ() > -31.86f)
            {
                SpawnUpperEggs();
            }
            else if (me->GetPositionZ() < -31.86f)
            {
                SpawnLowerEggs();
            }
        }

        void SpawnUpperEggs()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_N:
            case DIFFICULTY_10_HC:
                me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() + 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                //me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() - 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() + 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                //me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() - 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                break;
            case DIFFICULTY_25_HC:
            case DIFFICULTY_25_N:
                me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() + 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                //me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() - 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() + 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                //me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX() - 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_MATURE_EGG_OF_JIKUN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
        }

        void SpawnLowerEggs()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_N:
            case DIFFICULTY_10_HC:
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() + 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() - 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() + 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() - 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                break;
            case DIFFICULTY_25_HC:
            case DIFFICULTY_25_N:
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() + 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() - 5.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() + 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX() - 7.0f, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                me->SummonCreature(NPC_YOUNG_EGG_OF_JIKUN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new jikun_beam_targetAI(creature);
    }
};

// Young hatchling - 68192.
class young_hatchling_jikun : public CreatureScript
{
public:
    young_hatchling_jikun() : CreatureScript("young_hatchling_jikun") { }

    struct young_hatchling_jikunAI : public ScriptedAI
    {
        young_hatchling_jikunAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); // no regen
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            me->SetDisableGravity(true);
            me->SetCanFly(true);

            events.ScheduleEvent(EVENT_CHEEP, urand(5000, 15000));
            events.ScheduleEvent(EVENT_FIND_EAT, urand(5000, 7000));

            me->SetMaxHealth(summoner->GetMaxHealth());
            me->SetHealth(summoner->GetHealth());
            me->SetFaction(summoner->getFaction());

            if (summoner->ToCreature())
                summoner->ToCreature()->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetDistance(me->GetHomePosition()) > 8.0f && me->GetReactState() != REACT_PASSIVE)
            {
                me->CombatStop(true);
                me->GetMotionMaster()->MoveTargetedHome();
            }

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_FIND_EAT: // call this event when eat is came to platform and hatchling must start find it
            {
                if (Unit* target = SelectRandomTargetWithGuidOnRange(me->ToUnit(), NPC_POOL_OF_FEED_HATCHLING, 10.0f, false))
                    if (Creature* eat = target->ToCreature())
                        if (me->GetReactState() != REACT_PASSIVE)
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_EAT_POOL, eat->GetPositionX(), eat->GetPositionY(), eat->GetPositionZ() - 3.0f);
                        }

                events.ScheduleEvent(EVENT_FIND_EAT, urand(2000, 4000));
                break;
            }
            case EVENT_CHEEP:
                me->StopMoving();
                if (me->GetVictim() && me->GetReactState() != REACT_PASSIVE)
                    DoCast(me->GetVictim(), me->HasAura(SPELL_HATCHLING_EVOLUTION) ? SPELL_FLEDGLING_CHEEP : SPELL_HATCHLING_CHEEP);
                events.ScheduleEvent(EVENT_CHEEP, urand(5000, 15000));
                break;

            case EVENT_LAY_EGG:
                me->StopMoving();
                DoCast(SPELL_FLEDGLING_LAY_EGG);
                events.ScheduleEvent(EVENT_LAY_EGG, 50000);
                break;

            default: break;
            }

            if (!me->HasUnitState(UNIT_STATE_CASTING))
                DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            switch (id)
            {
            case POINT_MOVE_TO_EAT_POOL: // when came to eat pool must find nearst eat pool and start eat
                bool Eating = false;
                if (Unit* target = SelectRandomTargetWithGuidOnRange(me->ToUnit(), NPC_POOL_OF_FEED_HATCHLING, 3.0f, false))
                    if (Creature* eat = target->ToCreature())
                    {
                        Eating = true;
                        DoCast(SPELL_HATCHLING_EATING);
                        events.CancelEvent(EVENT_FIND_EAT);
                        events.ScheduleEvent(EVENT_LAY_EGG, 25000);
                        eat->DespawnOrUnsummon();
                    }

                if (!Eating)
                    me->SetReactState(REACT_AGGRESSIVE);
                break;
            }
        }

        void JustDied(Unit*)
        {
            DoCast(SPELL_DROP_FEATHER); // additional AI for object
        }

        /*void JustDied(Unit* killer)
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 10.0f);
            for (auto playerTarget : PlayerList)
                if (!playerTarget->HasAura(SPELL_LESSON_OF_ICARUS))
                {
                    playerTarget->CastSpell(playerTarget,SPELL_DAEDELIAN_WINGS, true);
                    if (playerTarget->HasAura(SPELL_DAEDELIAN_WINGS))
                        playerTarget->GetAura(SPELL_DAEDELIAN_WINGS)->SetStackAmount(4);
                    break;
                }
        }*/
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new young_hatchling_jikunAI(creature);
    }
};

// Juvenile - 70095.
class npc_juvenile : public CreatureScript
{
public:
    npc_juvenile() : CreatureScript("npc_juvenile") { }

    struct npc_juvenileAI : public ScriptedAI
    {
        npc_juvenileAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            if (summoner->GetEntry() == NPC_MATURE_EGG_OF_JIKUN)
                me->SetHealth(summoner->GetHealth());
        }

        void EnterCombat(Unit*)
        {
            me->SetDisableGravity(true);
            events.ScheduleEvent(EVENT_START_FLY_AWAY, 4000);
            me->SetReactState(REACT_PASSIVE);
        }


        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_START_FLY_AWAY:
            {
                Position NextPoint;
                me->GetRandomPoint(Center, 25.0f);
                me->GetMotionMaster()->MovePoint(POINT_MOVE_TO_CENTER_FLY, NextPoint.GetPositionX(), NextPoint.GetPositionY(), 28.0f);
                events.ScheduleEvent(EVENT_JUVENILE_CHEEP, 20000, 0, 0);
                break;
            }
            case EVENT_JUVENILE_CHEEP:
            {
                std::list<Player*> PlayerList;
                GetPlayerListInGrid(PlayerList, me, 150.0f);
                PlayerList.remove_if(Trinity::UnitAuraCheck(true, SPELL_DAEDELIAN_WINGS));

                if (!PlayerList.empty())
                    if (Player* target = Trinity::Containers::SelectRandomContainerElement(PlayerList))
                        DoCast(target, SPELL_JUVENILE_CHEEP_DAMAGE);

                events.ScheduleEvent(EVENT_JUVENILE_CHEEP, 10000);
                break;
            }

            default: break;
            }

            if (!me->HasUnitState(UNIT_STATE_CASTING))
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_juvenileAI(creature);
    }
};

// Egg of Ji-Kun - 69628
class egg_of_jikun : public CreatureScript
{
public:
    egg_of_jikun() : CreatureScript("egg_of_jikun") { }

    struct egg_of_jikunAI : public ScriptedAI
    {
        egg_of_jikunAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); // no regen
            me->SetReactState(REACT_PASSIVE);
            switch (me->GetEntry())
            {
            case NPC_MATURE_EGG_OF_JIKUN:
                events.ScheduleEvent(EVENT_SUMMON_HATCHLING, 20000);
                me->DespawnOrUnsummon(21000);
                break;
            case NPC_FLEDGLING_EGG_JIKUN:
                events.ScheduleEvent(EVENT_SUMMON_HATCHLING, 20000);
                break;
            case NPC_YOUNG_EGG_OF_JIKUN:
                events.ScheduleEvent(EVENT_SUMMON_HATCHLING, 10000);
                break;
            }
        }

        void IsSummonedBy(Unit* summoner)
        {
            switch (me->GetEntry())
            {
            case NPC_YOUNG_EGG_OF_JIKUN:
                me->AddAura(SPELL_INCUBATION_LOW_NEST, me);
                break;
            case NPC_MATURE_EGG_OF_JIKUN:
                me->AddAura(SPELL_INCUBATION_HIGH_NEST, me);
                break;
            }

            me->SetFaction(summoner->getFaction());
        }

        void OnSpellClick(Unit* clicker, bool& result)
        {
            std::list<Creature*> JiKun;
            GetCreatureListWithEntryInGrid(JiKun, me, 69712, 500.0f);
            for (auto Ji : JiKun)
                Ji->GetAI()->DoAction(1);

            me->SetVisible(false);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_SUMMON_HATCHLING:
                DoCast(me->GetEntry() == NPC_YOUNG_EGG_OF_JIKUN ? SPELL_SUMMON_YOUNG_HATCHLING : SPELL_SUMMON_JUVENILE);

                events.ScheduleEvent(EVENT_SUMMON_HATCHLING, 50000);
                break;

            default: break;
            }

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new egg_of_jikunAI(creature);
    }
};

// Caw 138923
class spell_caw : public SpellScriptLoader
{
public:
    spell_caw() : SpellScriptLoader("spell_caw") { }

    class spell_caw_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_caw_SpellScript);

        void HandleAfterCast()
        {
            GetCaster()->CastSpell(GetCaster()->GetVictim(), SPELL_CAW_MISSILE);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_caw_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_caw_SpellScript();
    }
};

// Caw missile 138926
class bfa_spell_caw_missile : public SpellScriptLoader
{
public:
    bfa_spell_caw_missile() : SpellScriptLoader("bfa_spell_caw_missile") { }

    class bfa_spell_caw_missile_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_caw_missile_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 5 : 2);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_caw_missile_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_caw_missile_SpellScript();
    }
};

// Infected talons aura proc 140094.
class spell_infected_talons : public SpellScriptLoader
{
public:
    spell_infected_talons() : SpellScriptLoader("spell_infected_talons") { }

    class spell_infected_talons_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_infected_talons_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (!GetCaster() || !GetCaster()->GetVictim())
                return;

            GetCaster()->CastSpell(GetCaster()->GetVictim(), SPELL_INFECTED_TALONS_DAMAGE, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_infected_talons_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_infected_talons_AuraScript();
    }
};

// Hatchling eated 134321
class spell_hatchling_eated : public SpellScriptLoader
{
public:
    spell_hatchling_eated() : SpellScriptLoader("spell_hatchling_eated") { }

    class spell_hatchling_eated_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hatchling_eated_AuraScript);

        void OnRemove(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget())
            {
                if (Creature* hatchling = GetTarget()->ToCreature())
                    hatchling->SetReactState(REACT_AGGRESSIVE);
                GetTarget()->CastSpell(GetTarget(), SPELL_HATCHLING_EVOLUTION, true);
            }
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_hatchling_eated_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);

        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_hatchling_eated_AuraScript();
    }
};

// 138319 pool of feed dmg aura
class pool_of_feed_dmg_aura : public SpellScriptLoader
{
public:
    pool_of_feed_dmg_aura() : SpellScriptLoader("pool_of_feed_dmg_aura") { }

    class pool_of_feed_dmg_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(pool_of_feed_dmg_aura_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetTarget() || !aurEff || GetId() == 134256)
                return;

            if (!GetCaster() && GetTarget()->HasAura(138319))
            {
                GetTarget()->RemoveAura(138319);
                return;
            }

            if (!GetCaster())
                return;

            // if somebody get 3 ticks, pool must be despawned
            if (aurEff->GetTickNumber() == 3)
                if (TempSummon* pool = GetCaster()->ToTempSummon())
                {
                    if (GetTarget()->HasAura(138319))
                        GetTarget()->RemoveAura(138319);
                    pool->DespawnOrUnsummon();
                    return;
                }

            if (GetTarget()->GetDistance(GetCaster()) > 4.0f)
                if (GetTarget()->HasAura(138319))
                    GetTarget()->RemoveAura(138319);
        }

        void OnRemove(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget())
                GetTarget()->CastSpell(GetTarget(), SPELL_SLIMED_DMG_INCREASE, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(pool_of_feed_dmg_aura_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            AfterEffectRemove += AuraEffectRemoveFn(pool_of_feed_dmg_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);

        }
    };

    AuraScript* GetAuraScript() const
    {
        return new pool_of_feed_dmg_aura_AuraScript();
    }
};

// Stack of wings remove 133755
class remove_stack_wings : public SpellScriptLoader
{
public:
    remove_stack_wings() : SpellScriptLoader("remove_stack_wings") { }

    class remove_stack_wings_SpellScript : public SpellScript
    {
        PrepareSpellScript(remove_stack_wings_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;
            if (Aura* wing = caster->GetAura(SPELL_DAEDELIAN_WINGS))
            {
                if (wing->GetStackAmount() == 4)
                    wing->SetStackAmount(3);
                else if (wing->GetStackAmount() == 3)
                    wing->SetStackAmount(2);
                else if (wing->GetStackAmount() == 2)
                    wing->SetStackAmount(1);
                else if (wing->GetStackAmount() == 1)
                    wing->Remove();
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(remove_stack_wings_SpellScript::HandleAfterCast);

        }
    };

    SpellScript* GetSpellScript() const
    {
        return new remove_stack_wings_SpellScript();
    }
};

// Pool of feed(dmg) 68188, 70216
class pool_of_feed_dmg : public CreatureScript
{
public:
    pool_of_feed_dmg() : CreatureScript("pool_of_feed_dmg") { }

    struct pool_of_feed_dmgAI : public ScriptedAI
    {
        pool_of_feed_dmgAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(11686);
            me->AddAura(me->GetEntry() == NPC_POOL_OF_FEED_HATCHLING ? SPELL_FEED_POOL_VISUAL_HATCHLING : SPELL_FEED_POOL_VISUAL, me);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_FEED_POOL_DAMAGE, 3500, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FEED_POOL_DAMAGE:
                {                if (me->GetEntry() != NPC_POOL_OF_FEED_HATCHLING)
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* playerTarget = i->GetSource())
                            if (playerTarget->GetDistance(me) <= 4.0f)
                                if (!playerTarget->HasAura(SPELL_FEED_POOL_DMG))
                                    me->CastSpell(playerTarget, SPELL_FEED_POOL_DMG, true);
                }
                events.ScheduleEvent(EVENT_FEED_POOL_DAMAGE, 1000, 0, 0);
                break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new pool_of_feed_dmgAI(creature);
    }
};

// Feed of Ji-Kun 68178 70130
class npc_jikun_feed : public CreatureScript
{
public:
    npc_jikun_feed() : CreatureScript("npc_jikun_feed") { }

    struct npc_jikun_feedAI : public ScriptedAI
    {
        npc_jikun_feedAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void IsSummonedBy(Unit* summoner)
        {
            if (me->GetEntry() == NPC_FEED_HATCHLINGS)
            {
                me->AI()->DoAction(ACTION_FOOD_AIR);
                me->AddAura(140788, me);
            }
        }

        void UpdateAI(uint32 diff)
        {
            // When eat flyed, player may get it when move to it
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->GetDistance2d(me) <= 2.0f)
                        if (player->HasAura(SPELL_DAEDELIAN_WINGS) && !player->HasAura(SPELL_PRIMAL_NUTRIMENT))
                        {
                            player->CastSpell(player, 134256, true);
                            player->CastSpell(player, SPELL_PRIMAL_NUTRIMENT, true);
                            me->DespawnOrUnsummon();
                            me->Kill(me);
                        }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_FOOD_AIR:
            {
                Position jumpPos;
                me->GetRandomPoint(Center, 40.0f);
                me->GetMotionMaster()->MoveJump(jumpPos.GetPositionX(), jumpPos.GetPositionY(), 6.0f, 25.0f, 10.0f, POINT_FOOD_AIR);
                break;
            }
            }
        }
        void MovementInform(uint32 type, uint32 id)
        {
            switch (id)
            {
            case POINT_GREEN_FEED_AIR: // when came to position in air must fall to ground
                me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), -31.0f, 12.0f, 10.0f, POINT_GREEN_FEED_GROUND);
                break;
            case POINT_GREEN_FEED_GROUND: // when falled on ground must summon pool
                DoCast(SPELL_SUMMON_POOL);
                me->DespawnOrUnsummon();
                break;
            case POINT_FEED_CAME_TO_HATCHLING: // when came summon eat for hatchling and select hatchling to eat it
                DoCast(SPELL_SUMMON_POOL_HATCHLINGS);
                me->DespawnOrUnsummon();
                break;
            case POINT_FOOD_AIR:
            {
                if (Creature* beam = me->FindNearestCreature(NPC_BEAM_NEST, 500.0f))
                {
                    Position newPos, src;
                    //beam->GetPosition(src);
                    me->GetRandomPoint(beam->GetPosition(), 7.0f);
                    me->GetMotionMaster()->MoveJump(newPos.GetPositionX(), newPos.GetPositionY(), newPos.GetPositionZ() + 1.0f, 25.0f, 10.0f, POINT_FEED_CAME_TO_HATCHLING);
                }
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jikun_feedAI(creature);
    }
};

// NPC_FEED_HATCHLINGS - visual 140788 to hatchlings
// NPC_FEED_POOL - visual 
// Feed summon 137528.
class spell_feed_summon : public SpellScriptLoader
{
public:
    spell_feed_summon() : SpellScriptLoader("spell_feed_summon") { }

    class spell_feed_summon_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_feed_summon_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            if (aurEff->GetTickNumber() == 1) // first tick send 3 eat for hatchlings
            {
                /*if (Unit *target = SelectRandomTargetWithGuidOnRange(GetCaster()->ToUnit(), NPC_BEAM_NEST, 500.0f, false))
                    if (Creature* beam = target->ToCreature())
                        for (uint8 i = 0;i<=2;++i)
                            if (Creature *Feed = GetCaster()->SummonCreature(NPC_FEED_HATCHLINGS,GetCaster()->GetPositionX(),GetCaster()->GetPositionY(),GetCaster()->GetPositionZ()+6.0f,0.0f,TEMPSUMMON_TIMED_DESPAWN,12000))
                            {
                                Position newPos,src;
                                beam->GetPosition(&src);
                                Feed->GetRandomPoint(src, 7.0f,newPos);
                                Feed->GetMotionMaster()->MoveJump(newPos.GetPositionX(),newPos.GetPositionY(),newPos.GetPositionZ()+1.0f,25.0f,10.0f,POINT_FEED_CAME_TO_HATCHLING);
                            }*/
                GetCaster()->SummonCreature(NPC_FEED_HATCHLINGS, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 6.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000);
                GetCaster()->SummonCreature(NPC_FEED_HATCHLINGS, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 6.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000);
                GetCaster()->SummonCreature(NPC_FEED_HATCHLINGS, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 6.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000);
            }
            else if (aurEff->GetTickNumber() == 2) // tick 2 send "green eat" for pools
            {
                for (uint8 i = 0; i <= 4; ++i)
                    if (Creature* FeedGreen = GetCaster()->SummonCreature(NPC_FEED_POOL, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 6.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000))
                    {
                        Position jumpPos;
                        FeedGreen->GetRandomPoint(Center, 40.0f);
                        FeedGreen->GetMotionMaster()->MoveJump(jumpPos.GetPositionX(), jumpPos.GetPositionY(), 6.0f, 25.0f, 10.0f, POINT_GREEN_FEED_AIR);
                    }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_feed_summon_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_feed_summon_AuraScript();
    }
};

// Ji kun platform teleporter - 70640.
class npc_jikun_teleport : public CreatureScript
{
public:
    npc_jikun_teleport() : CreatureScript("npc_jikun_teleport") { }

    struct npc_jikun_teleportAI : public ScriptedAI
    {
        npc_jikun_teleportAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetCanFly(true);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* playerTarget = i->GetSource())
                {
                    if (playerTarget->IsFlying())
                        continue;

                    float angle = playerTarget->GetAngle(Center.GetPositionX(), Center.GetPositionY());

                    if (playerTarget->GetDistance(me) <= 5.0f && !playerTarget->HasAura(149418)) // Jump to platform of jikun
                    {
                        playerTarget->CastSpell(playerTarget, 149418, true);
                        playerTarget->JumpTo(24.0f, 20.0f);
                    }

                    if (!playerTarget->HasAura(89428) && playerTarget->GetPositionZ() < -108.0f) // fall from platform to bottom
                    {
                        playerTarget->AddAura(89428, playerTarget);

                        float dist = playerTarget->GetDistance(Center) - 87.0f;
                        playerTarget->GetMotionMaster()->MoveCharge(playerTarget->GetPositionX() + dist * cos(angle), playerTarget->GetPositionY() + dist * sin(angle), -20.0f, 15.0f, 11.0f);
                    }

                    if (playerTarget->HasAura(89428) && playerTarget->GetPositionZ() > -21.0f) // come to return jump
                    {
                        playerTarget->RemoveAurasDueToSpell(89428);

                        float dist = playerTarget->GetDistance(Center) - 37.0f;
                        playerTarget->GetMotionMaster()->MoveCharge(playerTarget->GetPositionX() + dist * cos(angle), playerTarget->GetPositionY() + dist * sin(angle), -31.0f, 30.0f, 22.0f);
                    }
                } // WARNINGS HERE IDK
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jikun_teleportAI(creature);
    }
};

class bfa_go_feather_of_jikun : public GameObjectScript
{
public:
    bfa_go_feather_of_jikun() : GameObjectScript("bfa_go_feather_of_jikun")
    {
    }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->HasAura(SPELL_LESSON_OF_ICARUS || player->IsGameMaster()))
            return true;

        // 3 stacks heroic, 4 normal
        if (player->GetMap()->IsHeroic())
        {
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_LESSON_OF_ICARUS, player);
        }
        else
        {
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_DAEDELIAN_WINGS, player);
            player->AddAura(SPELL_LESSON_OF_ICARUS, player);
        }
        return false;
    }
};

class bfa_npc_nest_guardian : public CreatureScript
{
public:
    bfa_npc_nest_guardian() : CreatureScript("bfa_npc_nest_guardian") { }

    struct bfa_npc_nest_guardianAI : public ScriptedAI
    {
        bfa_npc_nest_guardianAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_CHECK_MELEE, 20000, 0, 0);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_TALON_STRIKE, 15000, 0, 0);
        }

        void UpdateAI(uint32 diff)
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
                case EVENT_TALON_STRIKE:
                    me->CastSpell(me->GetVictim(), SPELL_TALON_STRIKE);
                    events.ScheduleEvent(EVENT_TALON_STRIKE, 15000, 0, 0);
                    break;
                case EVENT_CHECK_MELEE:
                {
                    /*if (Unit* target = me->GetVictim())
                    {
                        if (!target)
                            return;
                        if (me->GetExactDist2d(target) > 5.0f) // if distance ( melee range ) is more than 20 yards > cast growing fury
                        {
                            sWorld->SendWorldText(3, "no player, casting");
                            me->CastSpell(me, SPELL_SCREECH);
                        }
                    }*/
                    if (!me->IsWithinMeleeRange(me->GetVictim()) || !me->IsInCombat())
                        DoCastAOE(SPELL_SCREECH);
                    events.ScheduleEvent(EVENT_CHECK_MELEE, 3000, 0, 0);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_nest_guardianAI(creature);
    }
};

// Slimed - 134256
class bfa_spell_jikun_slimed : public SpellScriptLoader
{
public:
    bfa_spell_jikun_slimed() : SpellScriptLoader("bfa_spell_jikun_slimed") { }

    class bfa_spell_jikun_slimed_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_jikun_slimed_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();

            caster->AddAura(SPELL_SLIMED_DMG_INCREASE, caster);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_jikun_slimed_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_jikun_slimed_AuraScript();
    }
};

// Screech casting slowed spell - 134372
class bfa_spell_screech_slow : public SpellScriptLoader
{
public:
    bfa_spell_screech_slow() : SpellScriptLoader("bfa_spell_screech_slow") { }

    class bfa_spell_screech_slow_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_screech_slow_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
            {
                if (!player)
                    return;
                player->RemoveAura(134372);
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_screech_slow_AuraScript::OnProc, EFFECT_0, SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK); // dbc fix
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_screech_slow_AuraScript();
    }
};

// Talon Rake - 134366
class bfa_spell_talon_rake : public SpellScriptLoader
{
public:
    bfa_spell_talon_rake() : SpellScriptLoader("bfa_spell_talon_rake") { }

    class bfa_spell_talon_rake_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_talon_rake_SpellScript);

        void DealDamage()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (!target || !caster)
                        return;

                    uint32 damage = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                        damage = 369999;
                        break;
                    case DIFFICULTY_25_N:
                        damage = 462499;
                        break;
                    case DIFFICULTY_10_HC:
                        damage = 462499;
                        break;
                    case DIFFICULTY_25_HC:
                        damage = 554999;
                        break;
                    }

                    SetHitDamage(damage);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_talon_rake_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_talon_rake_SpellScript();
    }
};

// Screech - 140640
class bfa_spell_screech : public SpellScriptLoader
{
public:
    bfa_spell_screech() : SpellScriptLoader("bfa_spell_screech") {}

    class bfa_spell_screech_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_screech_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_CAT:
                    case TALENT_SPEC_DRUID_BALANCE:
                    case TALENT_SPEC_WARRIOR_FURY:
                    case TALENT_SPEC_WARRIOR_ARMS:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_PALADIN_RETRIBUTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    case TALENT_SPEC_DEATHKNIGHT_FROST:
                    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                    case TALENT_SPEC_ROGUE_ASSASSINATION:
                    case TALENT_SPEC_ROGUE_COMBAT:
                    case TALENT_SPEC_ROGUE_SUBTLETY:
                    case TALENT_SPEC_HUNTER_BEASTMASTER:
                    case TALENT_SPEC_HUNTER_MARKSMAN:
                    case TALENT_SPEC_HUNTER_SURVIVAL:
                    case TALENT_SPEC_MONK_BREWMASTER:
                    case TALENT_SPEC_MONK_MISTWEAVER:
                    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        void HandleHit(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_SCREECH_STACKS, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_screech_SpellScript::HandleHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_screech_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_screech_SpellScript();
    }
};

// Lesson of Icarus - 140571
class bfa_spell_lesson_of_icarus : public SpellScriptLoader
{
public:
    bfa_spell_lesson_of_icarus() : SpellScriptLoader("bfa_spell_lesson_of_icarus") { }

    class bfa_spell_lesson_of_icarus_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_lesson_of_icarus_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetCaster()->ApplySpellImmune(0, IMMUNITY_ID, 134339, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetCaster()->ApplySpellImmune(0, IMMUNITY_ID, 134339, false);
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(bfa_spell_lesson_of_icarus_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_lesson_of_icarus_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_lesson_of_icarus_AuraScript();
    }
};

void AddSC_boss_jikun()
{
    new boss_jikun();
    new spell_infected_talons();
    new spell_caw();
    new egg_of_jikun();
    new young_hatchling_jikun();
    new npc_juvenile();
    new jikun_beam_target();
    new spell_feed_summon();
    new npc_jikun_feed();
    new pool_of_feed_dmg();
    new pool_of_feed_dmg_aura();
    new remove_stack_wings();
    new spell_hatchling_eated();
    new npc_jikun_teleport();

    new bfa_spell_caw_missile;
    new bfa_npc_nest_guardian;
    new bfa_go_feather_of_jikun;
    new bfa_spell_jikun_slimed;
    new bfa_spell_screech_slow;
    new bfa_spell_talon_rake;
    new bfa_spell_screech;
    new bfa_spell_lesson_of_icarus;
}
