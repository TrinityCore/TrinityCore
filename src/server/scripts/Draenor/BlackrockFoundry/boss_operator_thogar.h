#include "blackrock_foundry.h"

enum eThogarMiscDatas : uint8
{
    /// Tracks handling
    FirstTrack,
    SecondTrack,
    ThirdTrack,
    FourthTrack,
    MaxTrainTracks,
    /// Trains handling
    /// Trains are large solid objects that block line of sight and that deal lethal damage to any players who are hit by them.
    /// There are 4 types of train and they can come in two forms:
    /// full-length train (train that is as long as a track) and half-length train (train that is half as long as a track).
    NonAddTrain = 0,
    SiegeTrain,
    AddsTrain,
    BigAddsTrain,
    CosmeticIntroTrain,
    CosmeticMovingTrain,
    MaxFightTrains = 40,
    /// Adds datas
    MaxIronRaiders = 8,
    HostileFaction = 16
};

enum eThogarCreatures
{
    TrainEngine         = 77181,
    TrainWheels         = 76907,
    Train1              = 82107,
    Train2              = 81226,
    TroopTransport1     = 78842,
    TroopTransport2     = 81752,
    TroopTransport3     = 77158,
    WeaponsTransport1   = 81768,
    WeaponsTransport2   = 89077,
    SuppliesTransport   = 81778,
    WoodTransport       = 89074,
    SlagTank            = 81177,
    Gunner              = 77260,
    Lieutnant           = 77243,
    SiegeEngine1        = 81316,
    SiegeEngine2        = 78982,
    IronGunnerySergeant = 81318,
    GrimrailLoader1     = 89055,
    GrimrailLoader2     = 89079,
    OgronHauler         = 89062,
    GromkarGrenadier    = 89064,
    ManAtArmsIntro      = 77687,
    GromkarGunner       = 89068,
    ThogarIronRaider    = 77394,
    ThogarIronCrackShot = 77476,
    ThogarFiremender    = 77487,
    ThogarManAtArms     = 80791,
    ThogarSergeant      = 78981
};

enum eThogarGameObjects
{
    TrainAndCarCollisionBox1    = 232213,
    TrainAndCarCollisionBox2    = 227739,
    EngineCollisionBox          = 237588
};

enum eThogarSpells
{
    SlagTankAura            = 178189,
    SuppliesTransportAura   = 178232,
    MovingFrontAura         = 164263,
    BreakingFrontAura       = 164265,
    StoppedFrontAura        = 164266,
    MovingBackAura          = 167632,
    BreakingBackAura        = 167633,
    StoppedBackAura         = 167634,
    TroopTransportOpen      = 164319,
    TroopTransportClosed    = 164320,
    MovingTrain             = 156553,
    WoodTransportAura       = 178261,
    IronStarsTransportAura  = 178264,
    TroopTransportAura      = 178255,
    TroopTransportAura2     = 178231,
    TroopTransportAura3     = 164620
};

enum eThogarTalks
{
    TalkTrack1,
    TalkTrack2,
    TalkTrack3,
    TalkTrack4,
    TalkExpress,
    TalkIntro,
    TalkAggro,
    TalkReinforcements,
    TalkIronGunnerySergeant,
    TalkGromkarManAtArms,
    TalkTripleTrain,    ///< Mythic only
    TalkDeforester,     ///< Mythic only
    TalkSlay,
    TalkBerserk,
    TalkWipe,
    TalkDeath
};

enum eThogarActions
{
    ActionNone,
    /// Intro: Part1 - Iron Raiders
    IntroBegin,
    IntroEnd,
    TrainMoveEnd,
    /// Intro: Part2 - Iron Gunnery Sergeants
    IntroBeginPart2,
    TrainMoveEndPart2,
    /// Intro: Part3 - Wood transport, before intro text
    IntroBeginPart3,
    TrainMoveEndPart3,
    /// Fight actions
    TrainFightMoveEnd,
    SiegeTrainMoveEnd
};

struct TrackDoors
{
    uint32 RightDoor;
    uint32 LeftDoor;
};

static std::vector<TrackDoors> g_TrackDoors =
{
    { eFoundryGameObjects::MassiveDoorTrack1Right, eFoundryGameObjects::MassiveDoorTrack1Left },
    { eFoundryGameObjects::MassiveDoorTrack2Right, eFoundryGameObjects::MassiveDoorTrack2Left },
    { eFoundryGameObjects::MassiveDoorTrack3Right, eFoundryGameObjects::MassiveDoorTrack3Left },
    { eFoundryGameObjects::MassiveDoorTrack4Right, eFoundryGameObjects::MassiveDoorTrack4Left }
};

struct WaggonDatas
{
    uint32 Entry;
    uint32 VisualAura;

    std::vector<uint32> Passengers;
};

struct TrainDatas
{
    /// Entries
    uint32 EngineEntry;

    uint32 SpawnTimer;

    uint8 TrackID;
    uint8 TrainType;
    bool RightToLeft;

    std::vector<WaggonDatas> WaggonsDatas;
};

enum eThogarTrains
{
    /// Intro trains
    IntroTroopsTrain,
    IntroSiegeTrain,
    IntroWoodTrain,
    /// Fight Trains
    FightTrainBeginning,
    FightTrainEnd = eThogarTrains::FightTrainBeginning + eThogarMiscDatas::MaxFightTrains,
    /// End
    MaxTrains
};

static std::array<TrainDatas, (eThogarTrains::MaxTrains - 1)> const g_TrainDatas =
{
    {
        /// Iron raider train for intro, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::CosmeticIntroTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport1, 0,
                    {
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider
                    }
                },
                { eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura, { } },
                {
                    eThogarCreatures::TroopTransport1, 0,
                    {
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider,
                        eFoundryCreatures::IronRaider
                    }
                }
            }
        },
        /// Siege engine train for intro, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::CosmeticIntroTrain, true,
            {
                { eThogarCreatures::Train2, 0, { eThogarCreatures::SiegeEngine1 } },
                { eThogarCreatures::Train1, 0, { eThogarCreatures::SiegeEngine1, eThogarCreatures::ManAtArmsIntro } },
                { eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,{} }
            }
        },
        /// Wood train for intro, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::CosmeticIntroTrain, true,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } },
                { eThogarCreatures::TroopTransport2, 0, { eThogarCreatures::GromkarGunner, eThogarCreatures::GromkarGunner, eThogarCreatures::GrimrailLoader1, eThogarCreatures::GrimrailLoader1 } }
            }
        },
        /// First fight train: Moving train on track 4, left to right
        {
            eThogarCreatures::TrainEngine, 17 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::WeaponsTransport2, eThogarSpells::IronStarsTransportAura,
                    {
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader2,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader2
                    }
                }
            }
        },
        /// Second fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 27 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Third fight train: Adds train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 32 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::AddsTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                }
            }
        },
        /// Fourth fight train: Moving train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 47 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Fifth fight train: Siege train on track 4, left to right
        {
            eThogarCreatures::TrainEngine, 52 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::SiegeTrain, false,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                { eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 } },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Sixth fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 77 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Seventh fight train: Adds train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 82 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::BigAddsTrain, false,
            {
                {
                    eThogarCreatures::Lieutnant, 0,
                    {
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms,
                        0,
                        0,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms
                    }
                }
            }
        },
        /// Eighth fight train: Moving train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 107 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        },
        /// Ninth fight train: Adds train on track 2, left to right
        {
            eThogarCreatures::TrainEngine, 122 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::AddsTrain, false,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                }
            }
        },
        /// Tenth fight train: Adds train on track 3, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::AddsTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                }
            }
        },
        /// Eleventh fight train: Moving train on track 1, left to right
        {
            eThogarCreatures::TrainEngine, 162 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Twelfth fight train: Moving train on track 4, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::WeaponsTransport1, 0,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Thirteenth fight train: Siege train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 172 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::SiegeTrain, true,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                {
                    eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 }
                },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Fourteenth fight train: Moving train on track 2, left to right
        {
            eThogarCreatures::TrainEngine, 187 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Fifteenth fight train: Adds train on track 4, right to left
        {
            eThogarCreatures::TrainEngine, 197 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::AddsTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                }
            }
        },
        /// Sixteenth fight train: Moving train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 217 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Seventeenth fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 227 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Eighteenth fight train: Moving train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 237 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        },
        /// Nineteenth fight train: Adds train on track 2, left to right
        {
            eThogarCreatures::TrainEngine, 252 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::BigAddsTrain, false,
            {
                {
                    eThogarCreatures::Lieutnant, 0,
                    {
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms,
                        0,
                        0,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms
                    }
                }
            }
        },
        /// Twentieth fight train: Siege train on track 4, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::SiegeTrain, true,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                { eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 } },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Twenty first fight train: Moving train on track 1, left to right
        {
            eThogarCreatures::TrainEngine, 272 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Twenty second fight train: Moving train on track 3, right to left
        {
            eThogarCreatures::TrainEngine, 277 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Twenty third fight train: Siege train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 307 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::SiegeTrain, true,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                {
                    eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 }
                },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Twenty fourth fight train: Siege train on track 4, left to right
        {
            eThogarCreatures::TrainEngine, 0 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::SiegeTrain, false,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                { eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 } },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Twenty fifth fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 317 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Twenty sixth fight train: Moving train on track 2, left to right
        {
            eThogarCreatures::TrainEngine, 342 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        },
        /// Twenty seventh fight train: Adds train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 372 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::AddsTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                }
            }
        },
        /// Twenty eighth fight train: Adds train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::BigAddsTrain, false,
            {
                {
                    eThogarCreatures::Lieutnant, 0,
                    {
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms,
                        0,
                        0,
                        eThogarCreatures::ThogarFiremender,
                        eThogarCreatures::ThogarManAtArms
                    }
                }
            }
        },
        /// Twenty ninth fight train: Moving train on track 4, right to left
        {
            eThogarCreatures::TrainEngine, 387 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::WeaponsTransport1, 0,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Thirtieth fight train: Moving train on track 1, left to right
        {
            eThogarCreatures::TrainEngine, 407 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        },
        /// Thirty first fight train: Siege train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 417 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::SiegeTrain, true,
            {
                {
                    eThogarCreatures::SuppliesTransport, eThogarSpells::SuppliesTransportAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GromkarGrenadier,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGunner
                    }
                },
                {
                    eThogarCreatures::Gunner, 0, { eThogarCreatures::SiegeEngine2 }
                },
                {
                    eThogarCreatures::WeaponsTransport1, eThogarSpells::TroopTransportAura3,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Thirty second fight train: Adds train on track 4, left to right
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::AddsTrain, false,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider
                    }
                }
            }
        },
        /// Thirty third fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 433 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Thirty fourth fight train: Moving train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 442, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::WeaponsTransport1, 0,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Thirty fifth fight train: Adds train on track 3, right to left
        {
            eThogarCreatures::TrainEngine, 462, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::AddsTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                },
                {
                    eThogarCreatures::TroopTransport3, eThogarSpells::TroopTransportAura2,
                    {
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronRaider,
                        eThogarCreatures::ThogarIronCrackShot,
                        eThogarCreatures::ThogarIronCrackShot
                    }
                }
            }
        },
        /// Thirty sixth fight train: Moving train on track 1, left to right
        {
            eThogarCreatures::TrainEngine, 467 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        },
        /// Thirty seventh fight train: Moving train on track 4, right to left
        {
            eThogarCreatures::TrainEngine, 0, eThogarMiscDatas::FourthTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::WeaponsTransport1, 0,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Thirty eighth fight train: Moving train on track 3, left to right
        {
            eThogarCreatures::TrainEngine, 487 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::ThirdTrack, eThogarMiscDatas::NonAddTrain, false,
            {
                { eThogarCreatures::WoodTransport, eThogarSpells::WoodTransportAura, { } }
            }
        },
        /// Thirty ninth fight train: Moving train on track 2, right to left
        {
            eThogarCreatures::TrainEngine, 490 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::SecondTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::TroopTransport2, eThogarSpells::TroopTransportAura,
                    {
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GromkarGunner,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GrimrailLoader1
                    }
                }
            }
        },
        /// Forty fight train: Moving train on track 1, right to left
        {
            eThogarCreatures::TrainEngine, 495 * TimeConstants::IN_MILLISECONDS, eThogarMiscDatas::FirstTrack, eThogarMiscDatas::NonAddTrain, true,
            {
                {
                    eThogarCreatures::SlagTank, eThogarSpells::SlagTankAura,
                    {
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::OgronHauler,
                        eThogarCreatures::GrimrailLoader1,
                        eThogarCreatures::GromkarGrenadier
                    }
                }
            }
        }
    }
};

float const g_InFightStopPosY = 3313.50f;

Position const g_TrainTrackSpawnPos[eThogarMiscDatas::MaxTrainTracks] =
{
    { 589.925f, 2913.5f, 299.4833f, 1.570796f },
    { 565.775f, 2913.5f, 299.4833f, 1.570796f },
    { 541.625f, 2913.5f, 299.4833f, 1.570796f },
    { 517.475f, 2913.5f, 299.4833f, 1.570796f }
};

Position const g_TrainTrackEndPos[eThogarMiscDatas::MaxTrainTracks] =
{
    { 589.925f, 3713.5f, 299.4833f, 1.570796f },
    { 565.775f, 3713.5f, 299.4833f, 1.570796f },
    { 541.625f, 3713.5f, 299.4833f, 1.570796f },
    { 517.475f, 3713.5f, 299.4833f, 1.570796f }
};

Position const g_TrainTrackIntroEndPos = { 517.475f, 3330.412f, 299.4833f, 1.570796f };
Position const g_TrainTrackIntroSiegeEndPos = { 517.475f, 3313.283f, 299.4833f, 1.570796f };
Position const g_TrainTrackIntroWoodEndPos = { 589.925f, 3296.323f, 299.4833f, 1.570796f };

Position const g_IronRaiderLeftExitPos[eThogarMiscDatas::MaxIronRaiders] =
{
    { 493.975f, 3355.412f, 305.8985f, 1.570796f },
    { 500.975f, 3355.412f, 305.9013f, 1.570796f },
    { 493.975f, 3350.412f, 305.9027f, 1.570796f },
    { 500.975f, 3350.412f, 305.9000f, 1.570796f },
    { 493.975f, 3344.412f, 305.9012f, 1.570796f },
    { 500.975f, 3344.412f, 305.8985f, 1.570796f },
    { 493.975f, 3339.412f, 305.8999f, 1.570796f },
    { 500.975f, 3339.412f, 305.8972f, 1.570796f }
};

Position const g_IronRaiderRightExitPos[eThogarMiscDatas::MaxIronRaiders] =
{
    { 493.975f, 3287.412f, 305.8896f, 1.570796f },
    { 500.975f, 3287.412f, 305.8854f, 1.570796f },
    { 493.975f, 3282.412f, 305.8895f, 1.570796f },
    { 500.975f, 3282.412f, 305.8854f, 1.570796f },
    { 493.975f, 3276.412f, 305.8917f, 1.570796f },
    { 500.975f, 3276.412f, 305.8898f, 1.570796f },
    { 493.975f, 3271.412f, 305.8883f, 1.570796f },
    { 500.975f, 3271.412f, 305.8863f, 1.570796f }
};

Position const g_ManAtArmsExitPos = { 482.475f, 3312.533f, 302.3777f, 1.570796f };

Position const g_ThogarJumpPos = { 596.063f, 3312.91f, 299.145f, float(M_PI) };

Position const g_CenterPos = { 553.36f, 3312.41f, 299.65f, 0.0f };

eThogarTalks const g_TrackTalks[eThogarMiscDatas::MaxTrainTracks] =
{
    eThogarTalks::TalkTrack1,
    eThogarTalks::TalkTrack2,
    eThogarTalks::TalkTrack3,
    eThogarTalks::TalkTrack4
};

static void ApplyPassengerFlags(Creature* p_Passenger, bool p_IsTrain = true)
{
    p_Passenger->SetFaction(eThogarMiscDatas::HostileFaction);
    p_Passenger->SetReactState(ReactStates::REACT_PASSIVE);
    p_Passenger->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC));

    p_Passenger->RemoveUnitFlag(UnitFlags(UNIT_FLAG_DISARMED));

    p_Passenger->AddUnitState(UnitState::UNIT_STATE_IGNORE_PATHFINDING);

    if (p_IsTrain)
        p_Passenger->CastSpell(p_Passenger, eThogarSpells::StoppedFrontAura, true);
}

static ObjectGuid SummonTrain(Creature* p_Summoner, uint8 p_TrainID, eThogarActions p_Action = eThogarActions::ActionNone, bool p_Talk = true)
{
    if (p_Summoner == nullptr || p_TrainID >= eThogarTrains::MaxTrains)
        return ObjectGuid::Empty;

    InstanceScript* l_InstanceScript = p_Summoner->GetInstanceScript();
    if (l_InstanceScript == nullptr)
        return ObjectGuid::Empty;

    Creature* l_Thogar = ObjectAccessor::GetCreature(*p_Summoner, l_InstanceScript->GetGuidData(eFoundryCreatures::BossOperatorThogar));
    if (l_Thogar == nullptr)
        return ObjectGuid::Empty;

    TrainDatas l_TrainDatas = g_TrainDatas[p_TrainID];
    if (l_TrainDatas.TrackID >= eThogarMiscDatas::MaxTrainTracks)
        return ObjectGuid::Empty;

    Position const l_Pos = l_TrainDatas.RightToLeft ? g_TrainTrackSpawnPos[l_TrainDatas.TrackID] : g_TrainTrackEndPos[l_TrainDatas.TrackID];

    ObjectGuid l_TrainGuid;// = 0;
    if (Creature* l_Wheels = p_Summoner->SummonCreature(eThogarCreatures::TrainWheels, l_Pos))
    {
        ApplyPassengerFlags(l_Wheels, false);

        l_TrainGuid             = l_Wheels->GetGUID();
        ObjectGuid l_SummonerGuid   = p_Summoner->GetGUID();
        /*l_InstanceScript->AddTimedDelayedOperation(10, [l_InstanceScript, l_TrainDatas, l_Pos, l_SummonerGuid, l_TrainGuid]() -> void
        {
            Creature* l_Summoner = sObjectAccessor->FindCreature(l_SummonerGuid);
            if (l_Summoner == nullptr)
                return;

            Creature* l_Wheels = sObjectAccessor->FindCreature(l_TrainGuid);
            if (l_Wheels == nullptr)
                return;

            InstanceScript* l_InstanceScript = l_Wheels->GetInstanceScript();
            if (l_InstanceScript == nullptr)
                return;

            int8 l_SeatID = 0;
            if (Creature* l_Engine = l_Summoner->SummonCreature(l_TrainDatas.EngineEntry, l_Pos))
            {
                ApplyPassengerFlags(l_Engine);

                uint64 l_EngineGuid = l_Engine->GetGUID();
                l_InstanceScript->AddTimedDelayedOperation(10, [l_SeatID, l_TrainGuid, l_EngineGuid]() -> void
                {
                    Creature* l_Wheels = sObjectAccessor->FindCreature(l_TrainGuid);
                    if (l_Wheels == nullptr)
                        return;

                    Creature* l_Engine = sObjectAccessor->FindCreature(l_EngineGuid);
                    if (l_Engine == nullptr)
                        return;

                    l_Engine->EnterVehicle(l_Wheels, l_SeatID);
                });

                ++l_SeatID;
            }

            for (WaggonDatas l_WaggonData : l_TrainDatas.WaggonsDatas)
            {
                if (Creature* l_Waggon = l_Summoner->SummonCreature(l_WaggonData.Entry, l_Pos))
                {
                    ApplyPassengerFlags(l_Waggon);

                    uint64 l_WagonGuid = l_Waggon->GetGUID();
                    l_InstanceScript->AddTimedDelayedOperation(10, [l_SeatID, l_WaggonData, l_TrainDatas, l_Pos, l_SummonerGuid, l_TrainGuid, l_WagonGuid]() -> void
                    {
                        Creature* l_Summoner = sObjectAccessor->FindCreature(l_SummonerGuid);
                        if (l_Summoner == nullptr)
                            return;

                        Creature* l_Wheels = sObjectAccessor->FindCreature(l_TrainGuid);
                        if (l_Wheels == nullptr)
                            return;

                        InstanceScript* l_InstanceScript = l_Wheels->GetInstanceScript();
                        if (l_InstanceScript == nullptr)
                            return;

                        Creature* l_Waggon = sObjectAccessor->FindCreature(l_WagonGuid);
                        if (l_Waggon == nullptr)
                            return;

                        /// Apply visual aura if needed
                        if (uint32 l_AuraID = l_WaggonData.VisualAura)
                            l_Waggon->CastSpell(l_Waggon, l_AuraID, true);

                        l_Waggon->EnterVehicle(l_Wheels, l_SeatID);

                        int8 l_OtherSeatID = 0;
                        for (uint32 l_Entry : l_WaggonData.Passengers)
                        {
                            if (l_Entry == 0)
                            {
                                ++l_OtherSeatID;
                                continue;
                            }

                            if (Creature* l_Passenger = l_Summoner->SummonCreature(l_Entry, l_Pos))
                            {
                                ApplyPassengerFlags(l_Passenger, false);

                                uint64 l_PassengerGuid = l_Passenger->GetGUID();
                                l_InstanceScript->AddTimedDelayedOperation(10, [l_OtherSeatID, l_PassengerGuid, l_WagonGuid]() -> void
                                {
                                    Creature* l_Waggon = sObjectAccessor->FindCreature(l_WagonGuid);
                                    if (l_Waggon == nullptr)
                                        return;

                                    Creature* l_Passenger = sObjectAccessor->FindCreature(l_PassengerGuid);
                                    if (l_Passenger == nullptr)
                                        return;

                                    l_Passenger->EnterVehicle(l_Waggon, l_OtherSeatID);
                                });

                                ++l_OtherSeatID;
                            }
                        }
                    });

                    ++l_SeatID;
                }
            }
        });

        l_InstanceScript->AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [p_TrainID, p_Action, l_TrainGuid, l_SummonerGuid]() -> void
        {
            Creature* l_Wheels = sObjectAccessor->FindCreature(l_TrainGuid);
            if (l_Wheels == nullptr)
                return;

            Creature* l_Summoner = sObjectAccessor->FindCreature(l_SummonerGuid);
            if (l_Summoner == nullptr)
                return;

            if (l_Wheels->IsAIEnabled)
            {
                l_Wheels->AI()->SetGUID(l_Summoner->GetGUID(), 0);
                l_Wheels->AI()->SetData(0, p_TrainID);
                l_Wheels->AI()->DoAction(p_Action);
            }
        });
    }

    eThogarTalks l_Talk = g_TrackTalks[l_TrainDatas.TrackID];
    if (p_Talk && l_Thogar->IsAIEnabled)
    {
        switch (l_TrainDatas.TrainType)
        {
            case eThogarMiscDatas::AddsTrain:
            {
                l_Talk = eThogarTalks::TalkReinforcements;
                break;
            }
            case eThogarMiscDatas::BigAddsTrain:
            {
                l_Talk = eThogarTalks::TalkGromkarManAtArms;
                break;
            }
            case eThogarMiscDatas::NonAddTrain:
            {
                l_Talk = eThogarTalks::TalkExpress;
                break;
            }
            case eThogarMiscDatas::SiegeTrain:
            {
                l_Talk = eThogarTalks::TalkIronGunnerySergeant;
                break;
            }
            default:
                break;
        }*/

       // l_Thogar->AI()->Talk(l_Talk);
    }
    
    return l_TrainGuid;
}
