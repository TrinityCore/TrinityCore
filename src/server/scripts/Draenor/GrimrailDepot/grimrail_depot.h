
static void DespawnCreaturesInArea(uint32 p_Entry, WorldObject* p_Object)
{
    std::list<Creature*> l_CreaturesList;
    GetCreatureListWithEntryInGrid(l_CreaturesList, p_Object, p_Entry, 2000.0f);
    if (l_CreaturesList.empty())
        return;

    for (std::list<Creature*>::iterator l_Iter = l_CreaturesList.begin(); l_Iter != l_CreaturesList.end(); ++l_Iter)
        (*l_Iter)->DespawnOrUnsummon();
}

#define InvisibleDisplay 11686
#define FriendlyFaction 35
#define HostileFaction 16
#define AttackableYetNotHostileFaction 7

Position const g_PositionGrimrailTrainTeleport = { 1645.683f, 1537.129f, 106.950f, 1.517012f };

enum eGrimrailDepotSpells
{
    /// Assault Cannon: 79548
    SpellOverHeatedBlast = 167589,
    SpellReloadingUnknownEffect = 160680, /// spell cast reloading, but no effect 
    SpellSlagBlastProjectile = 166565,
    SpellSlagBlastDotStackable = 166570,
    SpellSlagBlastAreatrigger = 166571,
    /// Grimrail Bombadier - 81407
    SpellBlackrockBombDummy = 164183,
    SpellBlackrockBombTriggerMissile = 164187,
    SpellBlackrockBombDamage = 164188,
    SpellBlackrockSummon = 168112,
    SpellDoubleSlash = 164218,
    SpellHermoragingWounds = 164241,
    /// Grimrail Laborer - 81235
    SpellHaymaker = 170099,
    /// Grimrail Overseer - 81212
    SpellDashDummy = 164168,
    SpellDashCharge = 164170,
    SpellDashDamage = 164171,
    SpellHewingSwipe = 164163,
    /// Grimrail Scout - 82590
    SpellArcaneBlitzAura = 166397,
    SpellArcaneBlitzTriggerMissileA = 166398,
    SpellArcaneBlitzTriggerMissileB = 166399,
    SpellArcaneBlitzDamage = 166404,
    SpellScoutingAHead = 166350,
    /// Grimrail Technician - 81236
    Spell50kVolts = 164192,
    SpellActivating = 163966,
    /// Grom'kar Boomer - 79720
    SpellBlackrockMortarTriggerMissile = 161258,
    SpellBlackrockMortarDamage = 160963,
    /// Grom'kar Capitan - 82597
    SpellRecklessSlash = 166380,
    /// Grom'kar Cinderseer - 88163	
    SpellFlametongueDummy = 176031,
    SpellFlametongueTriggerMissile = 176032,
    SpellFlametongueAura = 176033,
    SpellFlametongue = 176039,
    SpellLavaWreath = 176027,
    SpellLavaWreathDummy = 176025,
    /// Grom'kar Far Seer - 82579
    SpellFarSight = 166364,
    SpellHealingRain = 166387,
    SpellHealingRainDummy = 166388,
    SpellStormShieldAura = 166335,
    SpellStormShieldDamage = 166336,
    SpellThunderZoneAura = 166340,
    SpellThunderZoneDummy = 166346,
    /// Grom'kar Grenadier - 79739
    SpellBlackRockGrenade = 161150,
    /// Grom'kar Gunner - 77483
    SpellShrapnelBlast = 160943,
    /// Grom'kar Hulk - 80938
    SpellGettingAngry = 176023
};

enum GrimrailDepotActions
{
    ActionActivate = 1,
    ActionCount,
};

enum GrimrailDepotCreatures
{
    CreatureAssaultCannon = 79548,
    CreatureGrimrailBombadier = 81407,
    CreatureGrimrailLaborer = 81235,
    CreatureGrimrailOverseer = 81212,
    CreatureGrimrailScout = 82590,
    CreatureGrimrailTechnician = 81236,
    CreatureGromkarBoomer = 79720,
    CreatureGromkarCapitan = 82597,
    CreatureGromkarCinderseer = 88163,
    CreatureGromkarFarSeer = 82579,
    CreatureGromkarGrenadier = 79739,
    CreatureGromkarGunner = 77483,
    CreatureGromkarHulk = 80938,
    CreatureIronInfantry = 79888,
    CreatureStarMkIII = 81293,
    CreatureBetterPosition = 80518,
    CreatureJumpToLocation = 80333,
    CreatureBlackrockBombsTriggers = 324256,
    CreatureIronTurret = 82721,
    CreatureIronTurret01 = 78843,
    CreatureIronTurretNitrogg = 79548,
    CreatureNitroggPushBackTrigger = 877895,
    CreatureTurretMovement = 877896,
    CreatureSkylordTovraDragon = 80004
};

enum GrimrailDepotBosses
{
    BossSkylordTovra = 80005,
    BossBorkatheBrute = 77816,//86226,
    BossRocketSpark = 77803,
    BossNitroggThundertower = 79545
};

enum GrimrailDepotGobjects
{
    GameObjectSpikedGate = 237441,
    GameObjectIronWroughtGate = 237442,
    GameObjectIronWroughtGate01OnTrain = 237444,
    GameObjectIronWroughtGate02OnTrain = 237449,
    GameObjectIronWroughtGate03OnTrain = 237448,
    GameObjectIronWroughtGate04OnTrain = 237451,
    GameObjectIronWroughtGate05OnTrain = 237450,
    GameObjectIronWroughtGate06OnTrain = 237446,
    GameObjectAssaultFlaps = 231980,
    GameObjectInvisibleDoor = 232131,
    GameObjectSpikedGateSkylordTovra = 237445
};

enum GrimrailDepotData
{
    DataRocketspark = 1,
    DataBorka,
    DataRocketsparkEncounter,
    DataNitroggThundertower,
    DataNitroggTurret,
    DataSpikedGateBoss1,
    DataIronWroughtGate,
    DataSkyLordTovra,
    DataSkyLordTovraDragon,
    DataIronWroughtGateOnTrainCount,
    DataIronWroughtGateOnTrainDoorNumber,
    DataIronWroughtGate01OnTrain,
    DataIronWroughtGate02OnTrain,
    DataIronWroughtGate03OnTrain,
    DataIronWroughtGate04OnTrain,
    DataIronWroughtGate05OnTrain,
    DataIronWroughtGate06OnTrain,
    DataAssaultFlaps,
    DataInvisibleDoor,
    DataSpikedGateSkylordTovraDoor
};

enum GrimrailDepotScenes
{
    SceneBoardToGrimrail = 1344,
    SceneEscapeTheTrain  = 1345
};

/*
enum eGrimrailDepotScenarios
{
    ScenarioGrimrailDepotChallengeID = ,
    ScenarioBossRocketsparkAndBorka = ,
    ScenarioBossNitroggThundertower,
    ScenariosBossSkylordTovra = 
};
*/

enum GrimrailDepotAchivement
{
    AchievementGrimrailDepotNormal = 9043,  /// Defeat Skylord Tovra in Grimrail Depot.
    AchievementGrimrailDepotHeroic = 9052,  /// Defeat Skylord Tovra in Grimrail Depot On Heroic diffculty.
    AchievementGrimrailDepotMythic = 10082, /// Defeat Skylord Tovra in Grimrail Depot On Mythic diffculty.
    AchievementGrimrailDepotChallenger = 8887,  /// Complete the Grimrail Depot Challenge Mode.
    AchievementGrimrailDepotBronze = 8888,  /// Complete the Grimrail Depot Challenge Mode with rating of Bronze or better.
    AchievementGrimrailDepotSilver = 8889,  /// Complete the Grimrail Depot Challenge Mode with rating of Silver or better.
    AchievementGrimrailDepotGold = 8890,  /// Complete the Grimrail Depot Challenge Mode with rating of Gold.
    AchievementGrimrailDepotGuildRun = 9373,  /// Defeat Skylord Torva in Grimrail Depot on Heroic diffculty while in a guild group.
    AchievementGrimrailDepotNoTicket = 9007,  /// Defeat Nitrogg Thundertower after abruptly removing 20 enemies from the Grimrail in Grimrail Depot on Heroic diffculty.
    AchievementGrimrailDepotThisIsWhyWeCantHaveNiceThings = 9024   /// Defeat Railmaster Rocketspark and Borka the Brute after destroying all of the Priceless Paraphernalia in Grimrail Depot on Heroic diffculty.
};

