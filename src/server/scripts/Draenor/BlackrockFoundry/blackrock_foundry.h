#ifndef BLACKROCK_FOUNDRY_HPP
# define BLACKROCK_FOUNDRY_HPP

# include "InstanceScript.h"
# include "ScriptedCreature.h"
# include "ScriptMgr.h"
# include "Cell.h"
# include "CellImpl.h"
# include "GridNotifiers.h"
# include "GridNotifiersImpl.h"
# include "Vehicle.h"
# include "GameObjectAI.h"
# include "Group.h"
# include "MoveSplineInit.h"
# include "CreatureTextMgr.h"
#include "SpellAuraEffects.h"
#include "DB2Stores.h"
#include "Unit.h"
#include "SmartScript.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"

#define DataHeader "BLACKROCKFOUNDRY"

float const g_NorthOrientation = 0.0f;
float const g_SouthOrientation = float(M_PI);
float const g_WestOrientation = float(M_PI / 2.0f);
float const g_EastOrientation = float(3.0f * M_PI / 2.0f);

static void CastSpellToPlayers(Map* p_Map, Unit* p_Caster, uint32 p_SpellID, bool p_Triggered)
{
    if (p_Map == nullptr)
        return;

    Map::PlayerList const& l_Players = p_Map->GetPlayers();
    for (Map::PlayerList::const_iterator l_Iter = l_Players.begin(); l_Iter != l_Players.end(); ++l_Iter)
    {
        if (Player* l_Player = l_Iter->GetSource())
        {
            if (p_Caster != nullptr)
                p_Caster->CastSpell(l_Player, p_SpellID, p_Triggered);
            else
                l_Player->CastSpell(l_Player, p_SpellID, p_Triggered);
        }
    }
}

static void DespawnCreaturesInArea(uint32 p_Entry, WorldObject* p_WorldObject)
{
    std::list<Creature*> l_Creatures;
    GetCreatureListWithEntryInGrid(l_Creatures, p_WorldObject, p_Entry, p_WorldObject->GetMap()->GetVisibilityRange());

    for (Creature* l_Iter : l_Creatures)
        l_Iter->DespawnOrUnsummon();
}

enum eFoundryCreatures
{
    /// Slagworks - Part 1
    /// Gruul
    BossGruul               = 76877,
    /// Oregorger
    BossOregorger           = 77182,
    /// Blast Furnace
    HeartOfTheMountain      = 76806,
    ForemanFeldspar         = 76809,
    BlackhandCosmetic       = 76831,
    /// The Black Forge - Part 2
    /// Hans'gar & Franzok
    BossHansgar             = 76973,
    BossFranzok             = 76974,
    /// Flamebender Ka'graz
    BossFlamebenderKagraz   = 76814,
    AknorSteelbringer       = 77337,
    LavaStalker             = 77043,
    MoltenTorrentStalker    = 77253,
    CinderWolf              = 76794,
    /// Kromog
    BossKromog              = 77692,
    /// Iron Assembly - Part 3
    /// Beastlord Darmac
    BossBeastlordDarmac     = 76865,
    BossCruelfang           = 76884,
    BossDreadwing           = 76874,
    BossIroncrusher         = 76945,
    ThunderlordPackPens     = 77631,
    GromkarManAtArms        = 78832,
    IronRaider              = 81197,
    IronCrackShot           = 81315,
    GromkarFiremender       = 87841,
    /// Operator Thogar
    BossOperatorThogar      = 76906,
    /// Iron Maidens
    BossAdmiralGaran        = 77557,
    BossEnforcerSorka       = 77231,
    BossMarakTheBlooded     = 77477,
    ZiplineStalker          = 82538,
    IronCannon              = 78152,
    /// Blackhand's Crucible - Part 4
    ForgemistressFlamehand  = 87989,
    /// Blackhand
    BossBlackhand           = 77325,
    BlackrockFoundryTrigger = 77558,
    CeilingStalker          = 77570,
    AchievementStalker      = 80831
};

enum eFoundryGameObjects
{
    HardenedSlagEntrance        = 238838,
    HardenedSlagBlastFurnace    = 238834,
    /// Slagworks - Part 1
    SlagworksDoor               = 238835,
    GruulSpikeDoor              = 230930,
    BKFoundrySpikeTrapGate      = 230931,
    FurnacePortcullis           = 237224,
    BlastFurnaceEncounterDoor   = 230759,
    CrucibleLeft                = 233759,
    CrucibleRight               = 233839,
    FurnaceGate                 = 227423,
    /// The Black Forge - Part 2
    BlackForgeEntrance          = 238836,
    BlackForgePortcullis        = 236847,
    BlackForgeGate              = 237306,
    VolatileBlackrockOre        = 237308,
    HansgarAndFranzokEntrance   = 229318,
    HansgarAndFranzokExit       = 229319,
    ConveyorBelt002             = 230481,
    ConveyorBelt001             = 230482,
    ConveyorBelt003             = 230483,
    ConveyorBelt004             = 230484,
    ConveyorBelt005             = 230485,
    StampingPress16             = 229574,
    StampingPress20             = 229575,
    StampingPress19             = 229576,
    StampingPress18             = 229577,
    StampingPress17             = 229578,
    StampingPress15             = 229579,
    StampingPress14             = 229580,
    StampingPress13             = 229581,
    StampingPress12             = 229582,
    StampingPress11             = 229583,
    StampingPress06             = 229584,
    StampingPress07             = 229585,
    StampingPress08             = 229586,
    StampingPress09             = 229587,
    StampingPress10             = 229588,
    StampingPress05             = 229589,
    StampingPress04             = 229590,
    StampingPress01             = 229591,
    StampingPress02             = 229592,
    StampingPress03             = 229593,
    ConveyorBelt006             = 233238,
    ConveyorBelt007             = 233239,
    ConveyorBelt008             = 233240,
    ConveyorBelt009             = 236843,
    ConveyorBelt010             = 236844,
    FirewallDoor                = 236845,
    BurningFrontDoor            = 236842,
    KromogsDoorSouth            = 236839,
    KromogsDoorEast             = 236840,
    KromogDoor                  = 234029,
    /// Iron Assembly - Part 3
    IronAssembleyGate           = 238837,
    TheBeastGate                = 231841,
    BeastsEnclosureDoor         = 232021,
    TerminusDoor                = 237307,
    IronGate                    = 231842,
    MassiveDoorTrack4Right      = 231843,
    MassiveDoorTrack3Right      = 231844,
    MassiveDoorTrack2Right      = 231845,
    MassiveDoorTrack1Right      = 231846,
    MassiveDoorTrack4Left       = 231848,
    MassiveDoorTrack3Left       = 231847,
    MassiveDoorTrack2Left       = 231849,
    MassiveDoorTrack1Left       = 231850,
    FreightElevatorDoor         = 236848,
    IronMaidensRampDoor         = 232392,
    IronMaidensExitDoor         = 232393,
    AmmoLoader                  = 234028,
    /// Blackhand's Crucible - Part 4
    SpikeGate                   = 232556,
    CrucibleDoor                = 233006,
    PreBlackhandsGate           = 237109,
    BlackhandsGate              = 233007,
    BlackhandsCrucible01        = 233950,
    BlackhandsCrucible02        = 233951,
    BlackhandsCrucible03        = 233952,
    BlackhandsCrucible04        = 233953,
    BlackhandsCrucible05        = 233954,
    BlackhandAPlatform          = 230193,
    HangingIronStar             = 233841
};

enum eFoundryDatas
{
    /// Bosses
    DataGruul,
    DataOregorger,
    DataBlastFurnace,
    DataHansgarAndFranzok,
    DataFlamebenderKagraz,
    DataKromog,
    DataBeastlordDarmac,
    DataOperatorThogar,
    DataIronMaidens,
    DataBlackhand,
    DataIronMaidensStart,
    MaxBossData,

    /// Other boss datas
    DataForemanFeldspar     = eFoundryDatas::MaxBossData,

    /// Some define datas
    FriendlyFaction         = 35,

    /// Misc
    PristineTrueIronOres    = 0,
    VolatileOreGrinded,
    PrimalElementalistTime,
    PlayerStamped,
    IronTaskmasterAggro,
    AknorDied,
    GraspingEarthTime,
    DarmacBeastMountedFirst,
    DataAfterFightAddCount,
    DataThogarIntroStarted,
    IronMaidensKillTimer,
    BlackhandAshCollected,

    /// Counters
    /// Gruul
    MaxPristineTrueIronOres = 3,
    /// Oregorger
    MaxOreCrateSpawns       = 25,
    MaxOregorgerMovePos     = 8,
    MaxOregorgerPatterns    = 7,
    MaxOregorgerCollisions  = 8,
    MaxOregorgerPaths       = 12,
    /// Blast Furnace
    MaxPrimalElementalists  = 4,
    /// Kromog
    MaxReverberationSpawns  = 15,
    MaxGraspingEarthHands   = 10,
    /// Beastlord Darmac
    DataDreadwingFirst      = 1,
    DataIronCrusherFirst    = 2,
    DataCruelfangFirst      = 3,
    /// After Beastlord Darmac fight counters
    DataGromkarManAtArms    = 1,
    DataIronRaider          = 2,
    DataIronCrackShot       = 2,
    DataGromkarFiremender   = 2,
    /// Iron Maidens
    IronMaidensCount        = 3,
    ShipExplosionSceneID    = 777,
    /// Blackhand
    MaxAshesToCollect       = 20
};

enum eFoundrySpells
{
    Berserker                   = 26662,
    FollowerAknorSteelbringer   = 174973
};

enum eFoundryAchievements
{
    TheIronPrince           = 8978,
    HeShootsHeOres          = 8979,
    YaWeveGotTime           = 8930,
    StampStampRevolution    = 8980,
    TheSteelHasBeenBrought  = 8929,
    WouldYouGiveMeAHand     = 8983,
    FainWouldLieDown        = 8981,
    BeQuickOrBeDead         = 8984,
    AshesAshes              = 8952
};

enum eFoundryCriterias
{
    DreadwingMountedFirst   = 24675,
    IroncrusherMountedFirst = 24676,
    CruelfangMountedFirst   = 24677
};

enum eFoundryWorldState
{
    WorldStateDarmacAchievement = 9127
};

enum eFoundryVisuals
{
    CrucibleVisuals = 6922,
    ConveyorsStart  = 7621,
    ConveyorsStop   = 7336,
    ConveyorsStart2 = 6975,
    ConveyorsStart3 = 6974,
    AmmoLoaderAnim  = 4397
};

enum eFoundryDungeons
{
    Slagworks           = 847,
    BlackForge          = 846,
    IronAssembly        = 848,
    BlackhandsCrucible  = 823
};

static std::array<uint32, eFoundryDatas::IronMaidensCount> g_IronMaidensEntries =
{
    eFoundryCreatures::BossAdmiralGaran,
    eFoundryCreatures::BossEnforcerSorka,
    eFoundryCreatures::BossMarakTheBlooded
};

Position const g_GromkarManAtArmsMovePos = { 379.8316f, 3322.484f, 303.9331f, 0.0f };

Position const g_IronRaiderMovePos[eFoundryDatas::DataIronRaider] =
{
    { 385.01f, 3310.060f, 303.6845f, float(M_PI) },
    { 384.85f, 3316.058f, 303.6845f, float(M_PI) }
};

Position const g_IronCrackShotMovePos[eFoundryDatas::DataIronCrackShot] =
{
    { 395.39f, 3313.339f, 303.6845f, float(M_PI) },
    { 395.47f, 3310.340f, 303.6845f, float(M_PI) }
};

Position const g_GromkarFiremenderMovePos[eFoundryDatas::DataGromkarFiremender] =
{
    { 384.93f, 3313.059f, 303.6845f, float(M_PI )},
    { 395.32f, 3316.338f, 303.6845f, float(M_PI) }
};

Position const g_GromkarManAtArmsIntroRightPos  = { 502.17f, 3275.37f, 305.984f, 0.538223f };
Position const g_GromkarManAtArmsIntroLeftPos   = { 501.031f, 3348.45f, 306.277f, 5.37476f };

#endif
