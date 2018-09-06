-- phpMyAdmin SQL Dump
--
-- Host: localhost
-- Generation Time: Sep 06, 2018 at 01:01 PM
-- Server version: 10.1.34-MariaDB
-- PHP Version: 7.2.7

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `achievement`
--

DROP TABLE IF EXISTS `achievement`;
CREATE TABLE `achievement` (
  `Description` text,
  `Title` text,
  `Reward` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `InstanceID` smallint(6) NOT NULL DEFAULT '0',
  `Faction` tinyint(3) NOT NULL DEFAULT '0',
  `Supercedes` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Category` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinimumCriteria` tinyint(3) NOT NULL DEFAULT '0',
  `Points` tinyint(3) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `UiOrder` smallint(6) NOT NULL DEFAULT '0',
  `IconFileID` int(10) NOT NULL DEFAULT '0',
  `CriteriaTree` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SharesCriteria` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `animkit`
--

DROP TABLE IF EXISTS `animkit`;
CREATE TABLE `animkit` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `OneShotDuration` int(10) NOT NULL DEFAULT '0',
  `OneShotStopAnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LowDefAnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `areagroupmember`
--

DROP TABLE IF EXISTS `areagroupmember`;
CREATE TABLE `areagroupmember` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `AreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaGroupID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `areatable`
--

DROP TABLE IF EXISTS `areatable`;
CREATE TABLE `areatable` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ZoneName` text,
  `AreaName` text,
  `ContinentID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParentAreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaBit` smallint(6) NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AmbienceID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwAmbience` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ZoneMusic` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwZoneMusic` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ExplorationLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `IntroSound` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwIntroSound` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FactionGroupMask` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AmbientMultiplier` float NOT NULL DEFAULT '0',
  `MountFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PvpCombatWorldStateID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WildBattlePetLevelMin` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `WildBattlePetLevelMax` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `WindSettingsID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags1` int(10) NOT NULL DEFAULT '0',
  `Flags2` int(10) NOT NULL DEFAULT '0',
  `LiquidTypeID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LiquidTypeID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LiquidTypeID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LiquidTypeID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `areatrigger`
--

DROP TABLE IF EXISTS `areatrigger`;
CREATE TABLE `areatrigger` (
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `ContinentID` smallint(6) NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) NOT NULL DEFAULT '0',
  `PhaseID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `BoxLength` float NOT NULL DEFAULT '0',
  `BoxWidth` float NOT NULL DEFAULT '0',
  `BoxHeight` float NOT NULL DEFAULT '0',
  `BoxYaw` float NOT NULL DEFAULT '0',
  `ShapeType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ShapeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaTriggerActionSetID` smallint(6) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `armorlocation`
--

DROP TABLE IF EXISTS `armorlocation`;
CREATE TABLE `armorlocation` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Clothmodifier` float NOT NULL DEFAULT '0',
  `Leathermodifier` float NOT NULL DEFAULT '0',
  `Chainmodifier` float NOT NULL DEFAULT '0',
  `Platemodifier` float NOT NULL DEFAULT '0',
  `Modifier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifact`
--

DROP TABLE IF EXISTS `artifact`;
CREATE TABLE `artifact` (
  `Name` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `UiTextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UiNameColor` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UiBarOverlayColor` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UiBarBackgroundColor` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ArtifactCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiModelSceneID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellVisualKitID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactappearance`
--

DROP TABLE IF EXISTS `artifactappearance`;
CREATE TABLE `artifactappearance` (
  `Name` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `ArtifactAppearanceSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UnlockPlayerConditionID` int(10) NOT NULL DEFAULT '0',
  `ItemAppearanceModifierID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiSwatchColor` int(10) NOT NULL DEFAULT '0',
  `UiModelSaturation` float NOT NULL DEFAULT '0',
  `UiModelOpacity` float NOT NULL DEFAULT '0',
  `OverrideShapeshiftFormID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OverrideShapeshiftDisplayID` int(10) NOT NULL DEFAULT '0',
  `UiItemAppearanceID` int(10) NOT NULL DEFAULT '0',
  `UiAltItemAppearanceID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiCameraID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactappearanceset`
--

DROP TABLE IF EXISTS `artifactappearanceset`;
CREATE TABLE `artifactappearanceset` (
  `Name` text,
  `Description` text,
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiCameraID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AltHandUICameraID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ForgeAttachmentOverride` tinyint(3) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) NOT NULL DEFAULT '0',
  `ArtifactID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactcategory`
--

DROP TABLE IF EXISTS `artifactcategory`;
CREATE TABLE `artifactcategory` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `XpMultCurrencyID` smallint(6) NOT NULL DEFAULT '0',
  `XpMultCurveID` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactpower`
--

DROP TABLE IF EXISTS `artifactpower`;
CREATE TABLE `artifactpower` (
  `DisplayPosX` float NOT NULL DEFAULT '0',
  `DisplayPosY` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPurchasableRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Label` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Tier` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactpowerlink`
--

DROP TABLE IF EXISTS `artifactpowerlink`;
CREATE TABLE `artifactpowerlink` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PowerA` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PowerB` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactpowerpicker`
--

DROP TABLE IF EXISTS `artifactpowerpicker`;
CREATE TABLE `artifactpowerpicker` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactpowerrank`
--

DROP TABLE IF EXISTS `artifactpowerrank`;
CREATE TABLE `artifactpowerrank` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RankIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `ItemBonusListID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AuraPointsOverride` float NOT NULL DEFAULT '0',
  `ArtifactPowerID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactquestxp`
--

DROP TABLE IF EXISTS `artifactquestxp`;
CREATE TABLE `artifactquestxp` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty1` int(10) NOT NULL DEFAULT '0',
  `Difficulty2` int(10) NOT NULL DEFAULT '0',
  `Difficulty3` int(10) NOT NULL DEFAULT '0',
  `Difficulty4` int(10) NOT NULL DEFAULT '0',
  `Difficulty5` int(10) NOT NULL DEFAULT '0',
  `Difficulty6` int(10) NOT NULL DEFAULT '0',
  `Difficulty7` int(10) NOT NULL DEFAULT '0',
  `Difficulty8` int(10) NOT NULL DEFAULT '0',
  `Difficulty9` int(10) NOT NULL DEFAULT '0',
  `Difficulty10` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifacttier`
--

DROP TABLE IF EXISTS `artifacttier`;
CREATE TABLE `artifacttier` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ArtifactTier` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MaxNumTraits` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MaxArtifactKnowledge` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `KnowledgePlayerCondition` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MinimumEmpowerKnowledge` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `artifactunlock`
--

DROP TABLE IF EXISTS `artifactunlock`;
CREATE TABLE `artifactunlock` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PowerID` int(10) NOT NULL DEFAULT '0',
  `PowerRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemBonusListID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ArtifactID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `auctionhouse`
--

DROP TABLE IF EXISTS `auctionhouse`;
CREATE TABLE `auctionhouse` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `FactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DepositRate` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ConsignmentRate` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `bankbagslotprices`
--

DROP TABLE IF EXISTS `bankbagslotprices`;
CREATE TABLE `bankbagslotprices` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Cost` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `bannedaddons`
--

DROP TABLE IF EXISTS `bannedaddons`;
CREATE TABLE `bannedaddons` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Version` text,
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `barbershopstyle`
--

DROP TABLE IF EXISTS `barbershopstyle`;
CREATE TABLE `barbershopstyle` (
  `DisplayName` text,
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CostModifier` float NOT NULL DEFAULT '0',
  `Race` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Sex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Data` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `battlemasterlist`
--

DROP TABLE IF EXISTS `battlemasterlist`;
CREATE TABLE `battlemasterlist` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `GameType` text,
  `ShortDescription` text,
  `LongDescription` text,
  `InstanceType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) NOT NULL DEFAULT '0',
  `RatedPlayers` tinyint(3) NOT NULL DEFAULT '0',
  `MinPlayers` tinyint(3) NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GroupsAllowed` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxGroupSize` tinyint(3) NOT NULL DEFAULT '0',
  `HolidayWorldState` smallint(6) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `RequiredPlayerConditionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID9` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID10` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID11` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID12` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID13` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID14` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID15` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MapID16` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `battlepetbreedquality`
--

DROP TABLE IF EXISTS `battlepetbreedquality`;
CREATE TABLE `battlepetbreedquality` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `StateMultiplier` float NOT NULL DEFAULT '0',
  `QualityEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `battlepetbreedstate`
--

DROP TABLE IF EXISTS `battlepetbreedstate`;
CREATE TABLE `battlepetbreedstate` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BattlePetStateID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Value` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `BattlePetBreedID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `battlepetspecies`
--

DROP TABLE IF EXISTS `battlepetspecies`;
CREATE TABLE `battlepetspecies` (
  `Description` text,
  `SourceText` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `CreatureID` int(10) NOT NULL DEFAULT '0',
  `SummonSpellID` int(10) NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `PetTypeEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `CardUIModelSceneID` int(10) NOT NULL DEFAULT '0',
  `LoadoutUIModelSceneID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `battlepetspeciesstate`
--

DROP TABLE IF EXISTS `battlepetspeciesstate`;
CREATE TABLE `battlepetspeciesstate` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BattlePetStateID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Value` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BattlePetSpeciesID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `broadcasttext`
--

DROP TABLE IF EXISTS `broadcasttext`;
CREATE TABLE `broadcasttext` (
  `Text` text,
  `Text1` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ConditionID` int(10) NOT NULL DEFAULT '0',
  `EmotesID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Unknown` int(10) NOT NULL DEFAULT '0',
  `SoundEntriesID1` int(10) NOT NULL DEFAULT '0',
  `SoundEntriesID2` int(10) NOT NULL DEFAULT '0',
  `EmoteID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteDelay1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteDelay2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteDelay3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `cfgregions`
--

DROP TABLE IF EXISTS `cfgregions`;
CREATE TABLE `cfgregions` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Tag` text,
  `Raidorigin` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ChallengeOrigin` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RegionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RegionGroupMask` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `characterfacialhairstyles`
--

DROP TABLE IF EXISTS `characterfacialhairstyles`;
CREATE TABLE `characterfacialhairstyles` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Geoset1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Geoset2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Geoset3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Geoset4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Geoset5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VariationID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `charbasesection`
--

DROP TABLE IF EXISTS `charbasesection`;
CREATE TABLE `charbasesection` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `LayoutResType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VariationEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ResolutionVariationEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `charsections`
--

DROP TABLE IF EXISTS `charsections`;
CREATE TABLE `charsections` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BaseSection` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VariationIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ColorIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaterialResourcesID1` int(10) NOT NULL DEFAULT '0',
  `MaterialResourcesID2` int(10) NOT NULL DEFAULT '0',
  `MaterialResourcesID3` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `charstartoutfit`
--

DROP TABLE IF EXISTS `charstartoutfit`;
CREATE TABLE `charstartoutfit` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OutfitID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PetDisplayID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PetFamilyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID1` int(10) NOT NULL DEFAULT '0',
  `ItemID2` int(10) NOT NULL DEFAULT '0',
  `ItemID3` int(10) NOT NULL DEFAULT '0',
  `ItemID4` int(10) NOT NULL DEFAULT '0',
  `ItemID5` int(10) NOT NULL DEFAULT '0',
  `ItemID6` int(10) NOT NULL DEFAULT '0',
  `ItemID7` int(10) NOT NULL DEFAULT '0',
  `ItemID8` int(10) NOT NULL DEFAULT '0',
  `ItemID9` int(10) NOT NULL DEFAULT '0',
  `ItemID10` int(10) NOT NULL DEFAULT '0',
  `ItemID11` int(10) NOT NULL DEFAULT '0',
  `ItemID12` int(10) NOT NULL DEFAULT '0',
  `ItemID13` int(10) NOT NULL DEFAULT '0',
  `ItemID14` int(10) NOT NULL DEFAULT '0',
  `ItemID15` int(10) NOT NULL DEFAULT '0',
  `ItemID16` int(10) NOT NULL DEFAULT '0',
  `ItemID17` int(10) NOT NULL DEFAULT '0',
  `ItemID18` int(10) NOT NULL DEFAULT '0',
  `ItemID19` int(10) NOT NULL DEFAULT '0',
  `ItemID20` int(10) NOT NULL DEFAULT '0',
  `ItemID21` int(10) NOT NULL DEFAULT '0',
  `ItemID22` int(10) NOT NULL DEFAULT '0',
  `ItemID23` int(10) NOT NULL DEFAULT '0',
  `ItemID24` int(10) NOT NULL DEFAULT '0',
  `RaceID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chartitles`
--

DROP TABLE IF EXISTS `chartitles`;
CREATE TABLE `chartitles` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Name1` text,
  `MaskID` smallint(6) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chatchannels`
--

DROP TABLE IF EXISTS `chatchannels`;
CREATE TABLE `chatchannels` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Shortcut` text,
  `Flags` int(10) NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chrclasses`
--

DROP TABLE IF EXISTS `chrclasses`;
CREATE TABLE `chrclasses` (
  `Name` text,
  `Filename` text,
  `NameMale` text,
  `NameFemale` text,
  `PetNameToken` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `CreateScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `StartingLevel` int(10) NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DefaultSpec` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PrimaryStatPriority` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayPower` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RangedAttackPowerPerAgility` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AttackPowerPerAgility` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AttackPowerPerStrength` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chrclassesxpowertypes`
--

DROP TABLE IF EXISTS `chrclassesxpowertypes`;
CREATE TABLE `chrclassesxpowertypes` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) NOT NULL DEFAULT '0',
  `ClassID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chrraces`
--

DROP TABLE IF EXISTS `chrraces`;
CREATE TABLE `chrraces` (
  `ClientPrefix` text,
  `ClientFileString` text,
  `Name` text,
  `NameFemale` text,
  `NameLowercase` text,
  `NameFemaleLowercase` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `MaleDisplayID` int(10) NOT NULL DEFAULT '0',
  `FemaleDisplayID` int(10) NOT NULL DEFAULT '0',
  `HighResMaleDisplayID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `HighResFemaleDisplayID` int(10) NOT NULL DEFAULT '0',
  `CreateScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `MaleCustomizeOffset1` float NOT NULL DEFAULT '0',
  `MaleCustomizeOffset2` float NOT NULL DEFAULT '0',
  `MaleCustomizeOffset3` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset1` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset2` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset3` float NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int(10) NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID1` int(10) NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID2` int(10) NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID3` int(10) NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID1` int(10) NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID2` int(10) NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID3` int(10) NOT NULL DEFAULT '0',
  `HeritageArmorAchievementID` int(10) NOT NULL DEFAULT '0',
  `StartingLevel` int(10) NOT NULL DEFAULT '0',
  `UiDisplayOrder` int(10) NOT NULL DEFAULT '0',
  `FemaleSkeletonFileDataID` int(10) NOT NULL DEFAULT '0',
  `MaleSkeletonFileDataID` int(10) NOT NULL DEFAULT '0',
  `BaseRaceID` int(10) NOT NULL DEFAULT '0',
  `FactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ResSicknessSpellID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SplashSoundID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `BaseLanguage` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CreatureType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Alliance` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RaceRelated` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UnalteredVisualRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CharComponentTextureLayoutID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CharComponentTexLayoutHiResID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DefaultClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `NeutralRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaleModelFallbackRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaleModelFallbackSex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FemaleModelFallbackRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FemaleModelFallbackSex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaleTextureFallbackRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaleTextureFallbackSex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FemaleTextureFallbackRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FemaleTextureFallbackSex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `chrspecialization`
--

DROP TABLE IF EXISTS `chrspecialization`;
CREATE TABLE `chrspecialization` (
  `Name` text,
  `FemaleName` text,
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) NOT NULL DEFAULT '0',
  `PetTalentType` tinyint(3) NOT NULL DEFAULT '0',
  `Role` tinyint(3) NOT NULL DEFAULT '0',
  `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellIconFileID` int(10) NOT NULL DEFAULT '0',
  `PrimaryStatPriority` tinyint(3) NOT NULL DEFAULT '0',
  `AnimReplacements` int(10) NOT NULL DEFAULT '0',
  `MasterySpellID1` int(10) NOT NULL DEFAULT '0',
  `MasterySpellID2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `cinematiccamera`
--

DROP TABLE IF EXISTS `cinematiccamera`;
CREATE TABLE `cinematiccamera` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `OriginX` float NOT NULL DEFAULT '0',
  `OriginY` float NOT NULL DEFAULT '0',
  `OriginZ` float NOT NULL DEFAULT '0',
  `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `OriginFacing` float NOT NULL DEFAULT '0',
  `FileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `cinematicsequences`
--

DROP TABLE IF EXISTS `cinematicsequences`;
CREATE TABLE `cinematicsequences` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Camera1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Camera8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `conversationline`
--

DROP TABLE IF EXISTS `conversationline`;
CREATE TABLE `conversationline` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BroadcastTextID` int(10) NOT NULL DEFAULT '0',
  `SpellVisualKitID` int(10) NOT NULL DEFAULT '0',
  `AdditionalDuration` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `NextConversationLineID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpeechType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StartAnimation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EndAnimation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `creaturedisplayinfo`
--

DROP TABLE IF EXISTS `creaturedisplayinfo`;
CREATE TABLE `creaturedisplayinfo` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `ModelID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SoundID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SizeClass` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CreatureModelScale` float NOT NULL DEFAULT '0',
  `CreatureModelAlpha` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BloodID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ExtendedDisplayInfoID` int(10) NOT NULL DEFAULT '0',
  `NPCSoundID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParticleColorID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PortraitCreatureDisplayInfoID` int(10) NOT NULL DEFAULT '0',
  `PortraitTextureFileDataID` int(10) NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AnimReplacementSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int(10) NOT NULL DEFAULT '0',
  `PlayerOverrideScale` float NOT NULL DEFAULT '0',
  `PetInstanceScale` float NOT NULL DEFAULT '0',
  `UnarmedWeaponType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MountPoofSpellVisualKitID` int(10) NOT NULL DEFAULT '0',
  `DissolveEffectID` int(10) NOT NULL DEFAULT '0',
  `Gender` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DissolveOutEffectID` int(10) NOT NULL DEFAULT '0',
  `CreatureModelMinLod` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TextureVariationFileDataID1` int(10) NOT NULL DEFAULT '0',
  `TextureVariationFileDataID2` int(10) NOT NULL DEFAULT '0',
  `TextureVariationFileDataID3` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `creaturedisplayinfoextra`
--

DROP TABLE IF EXISTS `creaturedisplayinfoextra`;
CREATE TABLE `creaturedisplayinfoextra` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DisplaySexID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SkinID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FaceID` tinyint(3) NOT NULL DEFAULT '0',
  `HairStyleID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HairColorID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FacialHairID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BakeMaterialResourcesID` int(10) NOT NULL DEFAULT '0',
  `HDBakeMaterialResourcesID` int(10) NOT NULL DEFAULT '0',
  `CustomDisplayOption1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CustomDisplayOption2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CustomDisplayOption3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `creaturefamily`
--

DROP TABLE IF EXISTS `creaturefamily`;
CREATE TABLE `creaturefamily` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `MinScale` float NOT NULL DEFAULT '0',
  `MinScaleLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxScale` float NOT NULL DEFAULT '0',
  `MaxScaleLevel` tinyint(3) NOT NULL DEFAULT '0',
  `PetFoodMask` smallint(6) NOT NULL DEFAULT '0',
  `PetTalentType` tinyint(3) NOT NULL DEFAULT '0',
  `IconFileID` int(10) NOT NULL DEFAULT '0',
  `SkillLine1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillLine2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `creaturemodeldata`
--

DROP TABLE IF EXISTS `creaturemodeldata`;
CREATE TABLE `creaturemodeldata` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GeoBox1` float NOT NULL DEFAULT '0',
  `GeoBox2` float NOT NULL DEFAULT '0',
  `GeoBox3` float NOT NULL DEFAULT '0',
  `GeoBox4` float NOT NULL DEFAULT '0',
  `GeoBox5` float NOT NULL DEFAULT '0',
  `GeoBox6` float NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `FileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BloodID` int(10) NOT NULL DEFAULT '0',
  `FootprintTextureID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FootprintTextureLength` float NOT NULL DEFAULT '0',
  `FootprintTextureWidth` float NOT NULL DEFAULT '0',
  `FootprintParticleScale` float NOT NULL DEFAULT '0',
  `FoleyMaterialID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FootstepCameraEffectID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DeathThudCameraEffectID` int(10) NOT NULL DEFAULT '0',
  `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SizeClass` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CollisionWidth` float NOT NULL DEFAULT '0',
  `CollisionHeight` float NOT NULL DEFAULT '0',
  `WorldEffectScale` float NOT NULL DEFAULT '0',
  `CreatureGeosetDataID` int(10) NOT NULL DEFAULT '0',
  `HoverHeight` float NOT NULL DEFAULT '0',
  `AttachedEffectScale` float NOT NULL DEFAULT '0',
  `ModelScale` float NOT NULL DEFAULT '0',
  `MissileCollisionRadius` float NOT NULL DEFAULT '0',
  `MissileCollisionPush` float NOT NULL DEFAULT '0',
  `MissileCollisionRaise` float NOT NULL DEFAULT '0',
  `MountHeight` float NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `OverrideSelectionRadius` float NOT NULL DEFAULT '0',
  `TamedPetBaseScale` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `creaturetype`
--

DROP TABLE IF EXISTS `creaturetype`;
CREATE TABLE `creaturetype` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `criteria`
--

DROP TABLE IF EXISTS `criteria`;
CREATE TABLE `criteria` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Type` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Asset` int(10) NOT NULL DEFAULT '0',
  `ModifierTreeID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `StartEvent` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StartAsset` int(10) NOT NULL DEFAULT '0',
  `StartTimer` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `FailEvent` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FailAsset` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EligibilityWorldStateID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EligibilityWorldStateValue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `criteriatree`
--

DROP TABLE IF EXISTS `criteriatree`;
CREATE TABLE `criteriatree` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Description` text,
  `Parent` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Amount` int(10) NOT NULL DEFAULT '0',
  `Operator` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CriteriaID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` int(10) NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `currencytypes`
--

DROP TABLE IF EXISTS `currencytypes`;
CREATE TABLE `currencytypes` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `CategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `InventoryIconFileID` int(10) NOT NULL DEFAULT '0',
  `SpellWeight` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellCategory` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxQty` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MaxEarnablePerWeek` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Quality` tinyint(3) NOT NULL DEFAULT '0',
  `Unknown10` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `curve`
--

DROP TABLE IF EXISTS `curve`;
CREATE TABLE `curve` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `curvepoint`
--

DROP TABLE IF EXISTS `curvepoint`;
CREATE TABLE `curvepoint` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `CurveID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `destructiblemodeldata`
--

DROP TABLE IF EXISTS `destructiblemodeldata`;
CREATE TABLE `destructiblemodeldata` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `State0ImpactEffectDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State0AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State1Wmo` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `State1DestructionDoodadSet` tinyint(3) NOT NULL DEFAULT '0',
  `State1ImpactEffectDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State1AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State2Wmo` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `State2DestructionDoodadSet` tinyint(3) NOT NULL DEFAULT '0',
  `State2ImpactEffectDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State2AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State3Wmo` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `State3InitDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State3AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EjectDirection` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DoNotHighlight` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State0Wmo` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `HealEffect` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HealEffectSpeed` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `State0NameSet` tinyint(3) NOT NULL DEFAULT '0',
  `State1NameSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State2NameSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `State3NameSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `difficulty`
--

DROP TABLE IF EXISTS `difficulty`;
CREATE TABLE `difficulty` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `InstanceType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OldEnumValue` tinyint(3) NOT NULL DEFAULT '0',
  `FallbackDifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ToggleDifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GroupSizeHealthCurveID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GroupSizeDmgCurveID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GroupSizeSpellPointsCurveID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `dungeonencounter`
--

DROP TABLE IF EXISTS `dungeonencounter`;
CREATE TABLE `dungeonencounter` (
  `Name` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) NOT NULL DEFAULT '0',
  `OrderIndex` int(10) NOT NULL DEFAULT '0',
  `CreatureDisplayID` tinyint(3) NOT NULL DEFAULT '0',
  `Unknown6` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellIconFileID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `durabilitycosts`
--

DROP TABLE IF EXISTS `durabilitycosts`;
CREATE TABLE `durabilitycosts` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost9` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost10` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost11` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost12` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost13` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost14` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost15` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost16` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost17` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost18` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost19` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost20` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubClassCost21` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArmorSubClassCost8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `durabilityquality`
--

DROP TABLE IF EXISTS `durabilityquality`;
CREATE TABLE `durabilityquality` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `emotes`
--

DROP TABLE IF EXISTS `emotes`;
CREATE TABLE `emotes` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RaceMask` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteSlashCommand` text,
  `AnimID` int(10) NOT NULL DEFAULT '0',
  `EmoteFlags` int(10) NOT NULL DEFAULT '0',
  `EmoteSpecProc` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EmoteSpecProcParam` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EventSoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellVisualKitID` int(10) NOT NULL DEFAULT '0',
  `ClassMask` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `emotestext`
--

DROP TABLE IF EXISTS `emotestext`;
CREATE TABLE `emotestext` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `EmoteID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `emotestextsound`
--

DROP TABLE IF EXISTS `emotestextsound`;
CREATE TABLE `emotestextsound` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EmotesTextID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `faction`
--

DROP TABLE IF EXISTS `faction`;
CREATE TABLE `faction` (
  `ReputationRaceMask1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationRaceMask2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationRaceMask3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationRaceMask4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `ReputationIndex` smallint(6) NOT NULL DEFAULT '0',
  `ParentFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Expansion` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FriendshipRepID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ParagonFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationClassMask1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationClassMask2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationClassMask3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationClassMask4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationFlags1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationFlags2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationFlags3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationFlags4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationBase1` int(10) NOT NULL DEFAULT '0',
  `ReputationBase2` int(10) NOT NULL DEFAULT '0',
  `ReputationBase3` int(10) NOT NULL DEFAULT '0',
  `ReputationBase4` int(10) NOT NULL DEFAULT '0',
  `ReputationMax1` int(10) NOT NULL DEFAULT '0',
  `ReputationMax2` int(10) NOT NULL DEFAULT '0',
  `ReputationMax3` int(10) NOT NULL DEFAULT '0',
  `ReputationMax4` int(10) NOT NULL DEFAULT '0',
  `ParentFactionMod1` float NOT NULL DEFAULT '0',
  `ParentFactionMod2` float NOT NULL DEFAULT '0',
  `ParentFactionCap1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ParentFactionCap2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `factiontemplate`
--

DROP TABLE IF EXISTS `factiontemplate`;
CREATE TABLE `factiontemplate` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Faction` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FriendGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EnemyGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Enemies1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enemies2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enemies3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enemies4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Friend1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Friend2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Friend3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Friend4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `gameobjectdisplayinfo`
--

DROP TABLE IF EXISTS `gameobjectdisplayinfo`;
CREATE TABLE `gameobjectdisplayinfo` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GeoBox1` float NOT NULL DEFAULT '0',
  `GeoBox2` float NOT NULL DEFAULT '0',
  `GeoBox3` float NOT NULL DEFAULT '0',
  `GeoBox4` float NOT NULL DEFAULT '0',
  `GeoBox5` float NOT NULL DEFAULT '0',
  `GeoBox6` float NOT NULL DEFAULT '0',
  `FileDataID` int(10) NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `gameobjects`
--

DROP TABLE IF EXISTS `gameobjects`;
CREATE TABLE `gameobjects` (
  `Name` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `Rot4` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `OwnerID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Scale` float NOT NULL DEFAULT '0',
  `TypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue6` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue7` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PropValue8` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrability`
--

DROP TABLE IF EXISTS `garrability`;
CREATE TABLE `garrability` (
  `Name` text,
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `GarrAbilityCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrFollowerTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `FactionChangeGarrAbilityID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrbuilding`
--

DROP TABLE IF EXISTS `garrbuilding`;
CREATE TABLE `garrbuilding` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `HordeName` text,
  `AllianceName` text,
  `Description` text,
  `Tooltip` text,
  `GarrTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BuildingType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeGameObjectID` int(10) NOT NULL DEFAULT '0',
  `AllianceGameObjectID` int(10) NOT NULL DEFAULT '0',
  `GarrSiteID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BuildSeconds` int(10) NOT NULL DEFAULT '0',
  `CurrencyTypeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyQty` int(10) NOT NULL DEFAULT '0',
  `HordeUiTextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceUiTextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `AllianceSceneScriptPackageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `HordeSceneScriptPackageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxAssignments` int(10) NOT NULL DEFAULT '0',
  `ShipmentCapacity` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrAbilityID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `BonusGarrAbilityID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GoldCost` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrbuildingplotinst`
--

DROP TABLE IF EXISTS `garrbuildingplotinst`;
CREATE TABLE `garrbuildingplotinst` (
  `MapOffsetX` float NOT NULL DEFAULT '0',
  `MapOffsetY` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `GarrBuildingID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrSiteLevelPlotInstID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UiTextureAtlasMemberID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrclassspec`
--

DROP TABLE IF EXISTS `garrclassspec`;
CREATE TABLE `garrclassspec` (
  `ClassSpec` text,
  `ClassSpecMale` text,
  `ClassSpecFemale` text,
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UiTextureAtlasMemberID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GarrFollItemSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `FollowerClassLimit` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrfollower`
--

DROP TABLE IF EXISTS `garrfollower`;
CREATE TABLE `garrfollower` (
  `HordeSourceText` text,
  `AllianceSourceText` text,
  `TitleName` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `GarrTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrFollowerTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeCreatureID` int(10) NOT NULL DEFAULT '0',
  `AllianceCreatureID` int(10) NOT NULL DEFAULT '0',
  `HordeGarrFollRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceGarrFollRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeGarrClassSpecID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceGarrClassSpecID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Quality` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FollowerLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevelWeapon` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevelArmor` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `HordeSourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `AllianceSourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `HordeIconFileDataID` int(10) NOT NULL DEFAULT '0',
  `AllianceIconFileDataID` int(10) NOT NULL DEFAULT '0',
  `HordeGarrFollItemSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceGarrFollItemSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `HordeUITextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceUITextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Vitality` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeFlavorGarrStringID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AllianceFlavorGarrStringID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeSlottingBroadcastTextID` int(10) NOT NULL DEFAULT '0',
  `AllySlottingBroadcastTextID` int(10) NOT NULL DEFAULT '0',
  `ChrClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Gender` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrfollowerxability`
--

DROP TABLE IF EXISTS `garrfollowerxability`;
CREATE TABLE `garrfollowerxability` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FactionIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrAbilityID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GarrFollowerID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrplot`
--

DROP TABLE IF EXISTS `garrplot`;
CREATE TABLE `garrplot` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `PlotType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HordeConstructObjID` int(10) NOT NULL DEFAULT '0',
  `AllianceConstructObjID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeRequirement1` int(10) NOT NULL DEFAULT '0',
  `UpgradeRequirement2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrplotbuilding`
--

DROP TABLE IF EXISTS `garrplotbuilding`;
CREATE TABLE `garrplotbuilding` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GarrPlotID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GarrBuildingID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrplotinstance`
--

DROP TABLE IF EXISTS `garrplotinstance`;
CREATE TABLE `garrplotinstance` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `GarrPlotID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrsitelevel`
--

DROP TABLE IF EXISTS `garrsitelevel`;
CREATE TABLE `garrsitelevel` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `TownHallUiPosX` float NOT NULL DEFAULT '0',
  `TownHallUiPosY` float NOT NULL DEFAULT '0',
  `GarrSiteID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GarrLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeMovieID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UiTextureKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxBuildingLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeCost` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeGoldCost` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `garrsitelevelplotinst`
--

DROP TABLE IF EXISTS `garrsitelevelplotinst`;
CREATE TABLE `garrsitelevelplotinst` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UiMarkerPosX` float NOT NULL DEFAULT '0',
  `UiMarkerPosY` float NOT NULL DEFAULT '0',
  `GarrSiteLevelID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GarrPlotInstanceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiMarkerSize` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `gemproperties`
--

DROP TABLE IF EXISTS `gemproperties`;
CREATE TABLE `gemproperties` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EnchantID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Type` int(10) NOT NULL DEFAULT '0',
  `MinItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `glyphbindablespell`
--

DROP TABLE IF EXISTS `glyphbindablespell`;
CREATE TABLE `glyphbindablespell` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `GlyphPropertiesID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `glyphproperties`
--

DROP TABLE IF EXISTS `glyphproperties`;
CREATE TABLE `glyphproperties` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellIconID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GlyphType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `GlyphExclusiveCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `glyphrequiredspec`
--

DROP TABLE IF EXISTS `glyphrequiredspec`;
CREATE TABLE `glyphrequiredspec` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GlyphPropertiesID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `guildcolorbackground`
--

DROP TABLE IF EXISTS `guildcolorbackground`;
CREATE TABLE `guildcolorbackground` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Red` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Blue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Green` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `guildcolorborder`
--

DROP TABLE IF EXISTS `guildcolorborder`;
CREATE TABLE `guildcolorborder` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Red` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Blue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Green` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `guildcoloremblem`
--

DROP TABLE IF EXISTS `guildcoloremblem`;
CREATE TABLE `guildcoloremblem` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Red` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Blue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Green` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `guildperkspells`
--

DROP TABLE IF EXISTS `guildperkspells`;
CREATE TABLE `guildperkspells` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `heirloom`
--

DROP TABLE IF EXISTS `heirloom`;
CREATE TABLE `heirloom` (
  `SourceText` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `LegacyUpgradedItemID` int(10) NOT NULL DEFAULT '0',
  `StaticUpgradedItemID` int(10) NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LegacyItemID` int(10) NOT NULL DEFAULT '0',
  `UpgradeItemID1` int(10) NOT NULL DEFAULT '0',
  `UpgradeItemID2` int(10) NOT NULL DEFAULT '0',
  `UpgradeItemID3` int(10) NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `holidays`
--

DROP TABLE IF EXISTS `holidays`;
CREATE TABLE `holidays` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `Region` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Looping` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `HolidayNameID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `HolidayDescriptionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Priority` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFilterType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Duration1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration9` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Duration10` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Date1` int(10) NOT NULL DEFAULT '0',
  `Date2` int(10) NOT NULL DEFAULT '0',
  `Date3` int(10) NOT NULL DEFAULT '0',
  `Date4` int(10) NOT NULL DEFAULT '0',
  `Date5` int(10) NOT NULL DEFAULT '0',
  `Date6` int(10) NOT NULL DEFAULT '0',
  `Date7` int(10) NOT NULL DEFAULT '0',
  `Date8` int(10) NOT NULL DEFAULT '0',
  `Date9` int(10) NOT NULL DEFAULT '0',
  `Date10` int(10) NOT NULL DEFAULT '0',
  `Date11` int(10) NOT NULL DEFAULT '0',
  `Date12` int(10) NOT NULL DEFAULT '0',
  `Date13` int(10) NOT NULL DEFAULT '0',
  `Date14` int(10) NOT NULL DEFAULT '0',
  `Date15` int(10) NOT NULL DEFAULT '0',
  `Date16` int(10) NOT NULL DEFAULT '0',
  `CalendarFlags1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags9` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CalendarFlags10` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TextureFileDataID1` int(10) NOT NULL DEFAULT '0',
  `TextureFileDataID2` int(10) NOT NULL DEFAULT '0',
  `TextureFileDataID3` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `importpricearmor`
--

DROP TABLE IF EXISTS `importpricearmor`;
CREATE TABLE `importpricearmor` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ClothModifier` float NOT NULL DEFAULT '0',
  `LeatherModifier` float NOT NULL DEFAULT '0',
  `ChainModifier` float NOT NULL DEFAULT '0',
  `PlateModifier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `importpricequality`
--

DROP TABLE IF EXISTS `importpricequality`;
CREATE TABLE `importpricequality` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `importpriceshield`
--

DROP TABLE IF EXISTS `importpriceshield`;
CREATE TABLE `importpriceshield` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `importpriceweapon`
--

DROP TABLE IF EXISTS `importpriceweapon`;
CREATE TABLE `importpriceweapon` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
CREATE TABLE `item` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SubclassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Material` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `InventoryType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SheatheType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundOverrideSubclassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `ItemGroupSoundsID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemappearance`
--

DROP TABLE IF EXISTS `itemappearance`;
CREATE TABLE `itemappearance` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemDisplayInfoID` int(10) NOT NULL DEFAULT '0',
  `DefaultIconFileDataID` int(10) NOT NULL DEFAULT '0',
  `UiOrder` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemarmorquality`
--

DROP TABLE IF EXISTS `itemarmorquality`;
CREATE TABLE `itemarmorquality` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Qualitymod1` float NOT NULL DEFAULT '0',
  `Qualitymod2` float NOT NULL DEFAULT '0',
  `Qualitymod3` float NOT NULL DEFAULT '0',
  `Qualitymod4` float NOT NULL DEFAULT '0',
  `Qualitymod5` float NOT NULL DEFAULT '0',
  `Qualitymod6` float NOT NULL DEFAULT '0',
  `Qualitymod7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemarmorshield`
--

DROP TABLE IF EXISTS `itemarmorshield`;
CREATE TABLE `itemarmorshield` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemarmortotal`
--

DROP TABLE IF EXISTS `itemarmortotal`;
CREATE TABLE `itemarmortotal` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) NOT NULL DEFAULT '0',
  `Cloth` float NOT NULL DEFAULT '0',
  `Leather` float NOT NULL DEFAULT '0',
  `Mail` float NOT NULL DEFAULT '0',
  `Plate` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itembagfamily`
--

DROP TABLE IF EXISTS `itembagfamily`;
CREATE TABLE `itembagfamily` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itembonus`
--

DROP TABLE IF EXISTS `itembonus`;
CREATE TABLE `itembonus` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Value1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Value2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Value3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ParentItemBonusListID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itembonuslistleveldelta`
--

DROP TABLE IF EXISTS `itembonuslistleveldelta`;
CREATE TABLE `itembonuslistleveldelta` (
  `ItemLevelDelta` smallint(6) NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itembonustreenode`
--

DROP TABLE IF EXISTS `itembonustreenode`;
CREATE TABLE `itembonustreenode` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ChildItemBonusTreeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ChildItemBonusListID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ChildItemLevelSelectorID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParentItemBonusTreeID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemchildequipment`
--

DROP TABLE IF EXISTS `itemchildequipment`;
CREATE TABLE `itemchildequipment` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ChildItemID` int(10) NOT NULL DEFAULT '0',
  `ChildItemEquipSlot` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ParentItemID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemclass`
--

DROP TABLE IF EXISTS `itemclass`;
CREATE TABLE `itemclass` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ClassName` text,
  `ClassID` tinyint(3) NOT NULL DEFAULT '0',
  `PriceModifier` float NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemcurrencycost`
--

DROP TABLE IF EXISTS `itemcurrencycost`;
CREATE TABLE `itemcurrencycost` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdamageammo`
--

DROP TABLE IF EXISTS `itemdamageammo`;
CREATE TABLE `itemdamageammo` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdamageonehand`
--

DROP TABLE IF EXISTS `itemdamageonehand`;
CREATE TABLE `itemdamageonehand` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdamageonehandcaster`
--

DROP TABLE IF EXISTS `itemdamageonehandcaster`;
CREATE TABLE `itemdamageonehandcaster` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdamagetwohand`
--

DROP TABLE IF EXISTS `itemdamagetwohand`;
CREATE TABLE `itemdamagetwohand` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdamagetwohandcaster`
--

DROP TABLE IF EXISTS `itemdamagetwohandcaster`;
CREATE TABLE `itemdamagetwohandcaster` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemdisenchantloot`
--

DROP TABLE IF EXISTS `itemdisenchantloot`;
CREATE TABLE `itemdisenchantloot` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Subclass` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Quality` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillRequired` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) NOT NULL DEFAULT '0',
  `Class` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemeffect`
--

DROP TABLE IF EXISTS `itemeffect`;
CREATE TABLE `itemeffect` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `LegacySlotIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TriggerType` tinyint(3) NOT NULL DEFAULT '0',
  `Charges` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CoolDownMSec` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CategoryCoolDownMSec` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellCategoryID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParentItemID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemextendedcost`
--

DROP TABLE IF EXISTS `itemextendedcost`;
CREATE TABLE `itemextendedcost` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredArenaRating` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ArenaBracket` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinFactionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredAchievement` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID1` int(10) NOT NULL DEFAULT '0',
  `ItemID2` int(10) NOT NULL DEFAULT '0',
  `ItemID3` int(10) NOT NULL DEFAULT '0',
  `ItemID4` int(10) NOT NULL DEFAULT '0',
  `ItemID5` int(10) NOT NULL DEFAULT '0',
  `ItemCount1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemCount2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemCount3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemCount4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemCount5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyID5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyCount1` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount2` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount3` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount4` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount5` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemlevelselector`
--

DROP TABLE IF EXISTS `itemlevelselector`;
CREATE TABLE `itemlevelselector` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MinItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevelSelectorQualitySetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemlevelselectorquality`
--

DROP TABLE IF EXISTS `itemlevelselectorquality`;
CREATE TABLE `itemlevelselectorquality` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `QualityItemBonusListID` int(10) NOT NULL DEFAULT '0',
  `Quality` tinyint(3) NOT NULL DEFAULT '0',
  `ParentILSQualitySetID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemlevelselectorqualityset`
--

DROP TABLE IF EXISTS `itemlevelselectorqualityset`;
CREATE TABLE `itemlevelselectorqualityset` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `IlvlRare` smallint(6) NOT NULL DEFAULT '0',
  `IlvlEpic` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemlimitcategory`
--

DROP TABLE IF EXISTS `itemlimitcategory`;
CREATE TABLE `itemlimitcategory` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Quantity` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemlimitcategorycondition`
--

DROP TABLE IF EXISTS `itemlimitcategorycondition`;
CREATE TABLE `itemlimitcategorycondition` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `AddQuantity` tinyint(3) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ParentItemLimitCategoryID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemmodifiedappearance`
--

DROP TABLE IF EXISTS `itemmodifiedappearance`;
CREATE TABLE `itemmodifiedappearance` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `ItemAppearanceModifierID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemAppearanceID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TransmogSourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itempricebase`
--

DROP TABLE IF EXISTS `itempricebase`;
CREATE TABLE `itempricebase` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Armor` float NOT NULL DEFAULT '0',
  `Weapon` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemrandomproperties`
--

DROP TABLE IF EXISTS `itemrandomproperties`;
CREATE TABLE `itemrandomproperties` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemrandomsuffix`
--

DROP TABLE IF EXISTS `itemrandomsuffix`;
CREATE TABLE `itemrandomsuffix` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Enchantment5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllocationPct1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllocationPct2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllocationPct3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllocationPct4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllocationPct5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemsearchname`
--

DROP TABLE IF EXISTS `itemsearchname`;
CREATE TABLE `itemsearchname` (
  `AllowableRace` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Display` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `OverallQualityID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AllowableClass` int(10) NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(3) NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredAbility` int(10) NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemset`
--

DROP TABLE IF EXISTS `itemset`;
CREATE TABLE `itemset` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `SetFlags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkill` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID1` int(10) NOT NULL DEFAULT '0',
  `ItemID2` int(10) NOT NULL DEFAULT '0',
  `ItemID3` int(10) NOT NULL DEFAULT '0',
  `ItemID4` int(10) NOT NULL DEFAULT '0',
  `ItemID5` int(10) NOT NULL DEFAULT '0',
  `ItemID6` int(10) NOT NULL DEFAULT '0',
  `ItemID7` int(10) NOT NULL DEFAULT '0',
  `ItemID8` int(10) NOT NULL DEFAULT '0',
  `ItemID9` int(10) NOT NULL DEFAULT '0',
  `ItemID10` int(10) NOT NULL DEFAULT '0',
  `ItemID11` int(10) NOT NULL DEFAULT '0',
  `ItemID12` int(10) NOT NULL DEFAULT '0',
  `ItemID13` int(10) NOT NULL DEFAULT '0',
  `ItemID14` int(10) NOT NULL DEFAULT '0',
  `ItemID15` int(10) NOT NULL DEFAULT '0',
  `ItemID16` int(10) NOT NULL DEFAULT '0',
  `ItemID17` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemsetspell`
--

DROP TABLE IF EXISTS `itemsetspell`;
CREATE TABLE `itemsetspell` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ChrSpecID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Threshold` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemSetID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemsparse`
--

DROP TABLE IF EXISTS `itemsparse`;
CREATE TABLE `itemsparse` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `AllowableRace` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Description` text,
  `Display3` text,
  `Display2` text,
  `Display1` text,
  `Display` text,
  `DmgVariance` float NOT NULL DEFAULT '0',
  `DurationInInventory` int(10) NOT NULL DEFAULT '0',
  `QualityModifier` float NOT NULL DEFAULT '0',
  `BagFamily` int(10) NOT NULL DEFAULT '0',
  `ItemRange` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket1` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket2` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket3` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket4` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket5` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket6` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket7` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket8` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket9` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket10` float NOT NULL DEFAULT '0',
  `StatPercentEditor1` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor2` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor3` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor4` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor5` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor6` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor7` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor8` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor9` int(10) NOT NULL DEFAULT '0',
  `StatPercentEditor10` int(10) NOT NULL DEFAULT '0',
  `Stackable` int(10) NOT NULL DEFAULT '0',
  `MaxCount` int(10) NOT NULL DEFAULT '0',
  `RequiredAbility` int(10) NOT NULL DEFAULT '0',
  `SellPrice` int(10) NOT NULL DEFAULT '0',
  `BuyPrice` int(10) NOT NULL DEFAULT '0',
  `VendorStackCount` int(10) NOT NULL DEFAULT '0',
  `PriceVariance` float NOT NULL DEFAULT '0',
  `PriceRandomValue` float NOT NULL DEFAULT '0',
  `Flags1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Unknown` int(10) NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredTransmogHoliday` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredHoliday` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LimitCategory` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `GemProperties` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SocketMatchEnchantmentID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TotemCategoryID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `InstanceBound` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ZoneBound` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemSet` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemRandomSuffixGroupID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RandomSelect` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LockID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `StartQuestID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemDelay` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ScalingStatDistributionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AllowableClass` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellWeight` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellWeightCategory` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SocketType1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SocketType2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SocketType3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SheatheType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Material` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PageMaterialID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Bonding` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DamageDamageType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat9` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `StatModifierBonusStat10` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ContainerSlots` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredPVPMedal` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `InventoryType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OverallQualityID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemspec`
--

DROP TABLE IF EXISTS `itemspec`;
CREATE TABLE `itemspec` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PrimaryStat` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SecondaryStat` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpecializationID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemspecoverride`
--

DROP TABLE IF EXISTS `itemspecoverride`;
CREATE TABLE `itemspecoverride` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpecID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemupgrade`
--

DROP TABLE IF EXISTS `itemupgrade`;
CREATE TABLE `itemupgrade` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemUpgradePathID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevelIncrement` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PrerequisiteID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyType` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyAmount` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `itemxbonustree`
--

DROP TABLE IF EXISTS `itemxbonustree`;
CREATE TABLE `itemxbonustree` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemBonusTreeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `keychain`
--

DROP TABLE IF EXISTS `keychain`;
CREATE TABLE `keychain` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Key1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key9` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key10` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key11` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key12` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key13` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key14` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key15` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key16` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key17` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key18` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key19` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key20` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key21` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key22` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key23` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key24` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key25` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key26` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key27` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key28` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key29` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key30` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key31` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key32` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `lfgdungeons`
--

DROP TABLE IF EXISTS `lfgdungeons`;
CREATE TABLE `lfgdungeons` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `MinLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Subtype` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Faction` tinyint(3) NOT NULL DEFAULT '0',
  `IconTextureFileID` int(10) NOT NULL DEFAULT '0',
  `RewardsBgTextureFileID` int(10) NOT NULL DEFAULT '0',
  `PopupBgTextureFileID` int(10) NOT NULL DEFAULT '0',
  `ExpansionLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinGear` float NOT NULL DEFAULT '0',
  `GroupID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `TargetLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TargetLevelMin` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TargetLevelMax` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RandomID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ScenarioID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `FinalEncounterID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CountTank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CountHealer` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CountDamage` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinCountTank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinCountHealer` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinCountDamage` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BonusReputationAmount` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MentorItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MentorCharLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags1` int(10) NOT NULL DEFAULT '0',
  `Flags2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `light`
--

DROP TABLE IF EXISTS `light`;
CREATE TABLE `light` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GameCoordsX` float NOT NULL DEFAULT '0',
  `GameCoordsY` float NOT NULL DEFAULT '0',
  `GameCoordsZ` float NOT NULL DEFAULT '0',
  `GameFalloffStart` float NOT NULL DEFAULT '0',
  `GameFalloffEnd` float NOT NULL DEFAULT '0',
  `ContinentID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LightParamsID8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `liquidtype`
--

DROP TABLE IF EXISTS `liquidtype`;
CREATE TABLE `liquidtype` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Texture1` text,
  `Texture2` text,
  `Texture3` text,
  `Texture4` text,
  `Texture5` text,
  `Texture6` text,
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SoundBank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `MaxDarkenDepth` float NOT NULL DEFAULT '0',
  `FogDarkenIntensity` float NOT NULL DEFAULT '0',
  `AmbDarkenIntensity` float NOT NULL DEFAULT '0',
  `DirDarkenIntensity` float NOT NULL DEFAULT '0',
  `LightID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParticleScale` float NOT NULL DEFAULT '0',
  `ParticleMovement` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ParticleTexSlots` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaterialID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinimapStaticCol` int(10) NOT NULL DEFAULT '0',
  `FrameCountTexture1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FrameCountTexture2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FrameCountTexture3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FrameCountTexture4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FrameCountTexture5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `FrameCountTexture6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Color1` int(10) NOT NULL DEFAULT '0',
  `Color2` int(10) NOT NULL DEFAULT '0',
  `Float1` float NOT NULL DEFAULT '0',
  `Float2` float NOT NULL DEFAULT '0',
  `Float3` float NOT NULL DEFAULT '0',
  `Float4` float NOT NULL DEFAULT '0',
  `Float5` float NOT NULL DEFAULT '0',
  `Float6` float NOT NULL DEFAULT '0',
  `Float7` float NOT NULL DEFAULT '0',
  `Float8` float NOT NULL DEFAULT '0',
  `Float9` float NOT NULL DEFAULT '0',
  `Float10` float NOT NULL DEFAULT '0',
  `Float11` float NOT NULL DEFAULT '0',
  `Float12` float NOT NULL DEFAULT '0',
  `Float13` float NOT NULL DEFAULT '0',
  `Float14` float NOT NULL DEFAULT '0',
  `Float15` float NOT NULL DEFAULT '0',
  `Float16` float NOT NULL DEFAULT '0',
  `Float17` float NOT NULL DEFAULT '0',
  `Float18` float NOT NULL DEFAULT '0',
  `Int1` int(10) NOT NULL DEFAULT '0',
  `Int2` int(10) NOT NULL DEFAULT '0',
  `Int3` int(10) NOT NULL DEFAULT '0',
  `Int4` int(10) NOT NULL DEFAULT '0',
  `Coefficient1` float NOT NULL DEFAULT '0',
  `Coefficient2` float NOT NULL DEFAULT '0',
  `Coefficient3` float NOT NULL DEFAULT '0',
  `Coefficient4` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `lock`
--

DROP TABLE IF EXISTS `lock`;
CREATE TABLE `lock` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Index1` int(10) NOT NULL DEFAULT '0',
  `Index2` int(10) NOT NULL DEFAULT '0',
  `Index3` int(10) NOT NULL DEFAULT '0',
  `Index4` int(10) NOT NULL DEFAULT '0',
  `Index5` int(10) NOT NULL DEFAULT '0',
  `Index6` int(10) NOT NULL DEFAULT '0',
  `Index7` int(10) NOT NULL DEFAULT '0',
  `Index8` int(10) NOT NULL DEFAULT '0',
  `Skill1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Skill8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Type1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Action8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mailtemplate`
--

DROP TABLE IF EXISTS `mailtemplate`;
CREATE TABLE `mailtemplate` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Body` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `map`
--

DROP TABLE IF EXISTS `map`;
CREATE TABLE `map` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Directory` text,
  `MapName` text,
  `MapDescription0` text,
  `MapDescription1` text,
  `PvpShortDescription` text,
  `PvpLongDescription` text,
  `CorpseX` float NOT NULL DEFAULT '0',
  `CorpseY` float NOT NULL DEFAULT '0',
  `MapType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `InstanceType` tinyint(3) NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AreaTableID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LoadingScreenID` smallint(6) NOT NULL DEFAULT '0',
  `TimeOfDayOverride` smallint(6) NOT NULL DEFAULT '0',
  `ParentMapID` smallint(6) NOT NULL DEFAULT '0',
  `CosmeticParentMapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TimeOffset` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinimapIconScale` float NOT NULL DEFAULT '0',
  `CorpseMapID` smallint(6) NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `WindSettingsID` smallint(6) NOT NULL DEFAULT '0',
  `ZmpFileDataID` int(10) NOT NULL DEFAULT '0',
  `Flags1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mapdifficulty`
--

DROP TABLE IF EXISTS `mapdifficulty`;
CREATE TABLE `mapdifficulty` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Message` text,
  `ItemContextPickerID` int(10) NOT NULL DEFAULT '0',
  `Unknown` int(10) NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LockID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ResetInterval` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MapID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `modifiertree`
--

DROP TABLE IF EXISTS `modifiertree`;
CREATE TABLE `modifiertree` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Parent` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Operator` tinyint(3) NOT NULL DEFAULT '0',
  `Amount` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Asset` int(10) NOT NULL DEFAULT '0',
  `SecondaryAsset` int(10) NOT NULL DEFAULT '0',
  `TertiaryAsset` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mount`
--

DROP TABLE IF EXISTS `mount`;
CREATE TABLE `mount` (
  `Name` text,
  `SourceText` text,
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `MountTypeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `SourceSpellID` int(10) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) NOT NULL DEFAULT '0',
  `MountFlyRideHeight` float NOT NULL DEFAULT '0',
  `UiModelSceneID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mountcapability`
--

DROP TABLE IF EXISTS `mountcapability`;
CREATE TABLE `mountcapability` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ReqRidingSkill` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReqAreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ReqSpellAuraID` int(10) NOT NULL DEFAULT '0',
  `ReqSpellKnownID` int(10) NOT NULL DEFAULT '0',
  `ModSpellAuraID` int(10) NOT NULL DEFAULT '0',
  `ReqMapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mounttypexcapability`
--

DROP TABLE IF EXISTS `mounttypexcapability`;
CREATE TABLE `mounttypexcapability` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MountTypeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MountCapabilityID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `mountxdisplay`
--

DROP TABLE IF EXISTS `mountxdisplay`;
CREATE TABLE `mountxdisplay` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CreatureDisplayInfoID` int(10) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) NOT NULL DEFAULT '0',
  `MountID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `movie`
--

DROP TABLE IF EXISTS `movie`;
CREATE TABLE `movie` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Volume` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `KeyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AudioFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SubtitleFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `namegen`
--

DROP TABLE IF EXISTS `namegen`;
CREATE TABLE `namegen` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Sex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `namesprofanity`
--

DROP TABLE IF EXISTS `namesprofanity`;
CREATE TABLE `namesprofanity` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Language` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `namesreserved`
--

DROP TABLE IF EXISTS `namesreserved`;
CREATE TABLE `namesreserved` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `namesreservedlocale`
--

DROP TABLE IF EXISTS `namesreservedlocale`;
CREATE TABLE `namesreservedlocale` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `LocaleMask` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `overridespelldata`
--

DROP TABLE IF EXISTS `overridespelldata`;
CREATE TABLE `overridespelldata` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Spells1` int(10) NOT NULL DEFAULT '0',
  `Spells2` int(10) NOT NULL DEFAULT '0',
  `Spells3` int(10) NOT NULL DEFAULT '0',
  `Spells4` int(10) NOT NULL DEFAULT '0',
  `Spells5` int(10) NOT NULL DEFAULT '0',
  `Spells6` int(10) NOT NULL DEFAULT '0',
  `Spells7` int(10) NOT NULL DEFAULT '0',
  `Spells8` int(10) NOT NULL DEFAULT '0',
  `Spells9` int(10) NOT NULL DEFAULT '0',
  `Spells10` int(10) NOT NULL DEFAULT '0',
  `PlayerActionBarFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `phase`
--

DROP TABLE IF EXISTS `phase`;
CREATE TABLE `phase` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `phasexphasegroup`
--

DROP TABLE IF EXISTS `phasexphasegroup`;
CREATE TABLE `phasexphasegroup` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseGroupID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `playercondition`
--

DROP TABLE IF EXISTS `playercondition`;
CREATE TABLE `playercondition` (
  `RaceMask` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FailureDescription` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `MinLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ClassMask` int(10) NOT NULL DEFAULT '0',
  `SkillLogic` int(10) NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinLanguage` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLanguage` int(10) NOT NULL DEFAULT '0',
  `MaxFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ReputationLogic` int(10) NOT NULL DEFAULT '0',
  `CurrentPvpFaction` tinyint(3) NOT NULL DEFAULT '0',
  `PvpMedal` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PrevQuestLogic` int(10) NOT NULL DEFAULT '0',
  `CurrQuestLogic` int(10) NOT NULL DEFAULT '0',
  `CurrentCompletedQuestLogic` int(10) NOT NULL DEFAULT '0',
  `SpellLogic` int(10) NOT NULL DEFAULT '0',
  `ItemLogic` int(10) NOT NULL DEFAULT '0',
  `ItemFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AuraSpellLogic` int(10) NOT NULL DEFAULT '0',
  `WorldStateExpressionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `WeatherID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PartyStatus` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LifetimeMaxPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AchievementLogic` int(10) NOT NULL DEFAULT '0',
  `Gender` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `NativeGender` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AreaLogic` int(10) NOT NULL DEFAULT '0',
  `LfgLogic` int(10) NOT NULL DEFAULT '0',
  `CurrencyLogic` int(10) NOT NULL DEFAULT '0',
  `QuestKillID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `QuestKillLogic` int(10) NOT NULL DEFAULT '0',
  `MinExpansionLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxExpansionLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinAvgItemLevel` int(10) NOT NULL DEFAULT '0',
  `MaxAvgItemLevel` int(10) NOT NULL DEFAULT '0',
  `MinAvgEquippedItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxAvgEquippedItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PhaseGroupID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ChrSpecializationIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ChrSpecializationRole` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ModifierTreeID` int(10) NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PowerTypeComp` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PowerTypeValue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `WeaponSubclassMask` int(10) NOT NULL DEFAULT '0',
  `MaxGuildLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinGuildLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxExpansionTier` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinExpansionTier` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SkillID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinSkill1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinSkill2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinSkill3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinSkill4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxSkill1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxSkill2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxSkill3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxSkill4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinFactionID1` int(10) NOT NULL DEFAULT '0',
  `MinFactionID2` int(10) NOT NULL DEFAULT '0',
  `MinFactionID3` int(10) NOT NULL DEFAULT '0',
  `MinReputation1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PrevQuestID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PrevQuestID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PrevQuestID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PrevQuestID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrQuestID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrQuestID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrQuestID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrQuestID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID1` int(10) NOT NULL DEFAULT '0',
  `SpellID2` int(10) NOT NULL DEFAULT '0',
  `SpellID3` int(10) NOT NULL DEFAULT '0',
  `SpellID4` int(10) NOT NULL DEFAULT '0',
  `ItemID1` int(10) NOT NULL DEFAULT '0',
  `ItemID2` int(10) NOT NULL DEFAULT '0',
  `ItemID3` int(10) NOT NULL DEFAULT '0',
  `ItemID4` int(10) NOT NULL DEFAULT '0',
  `ItemCount1` int(10) NOT NULL DEFAULT '0',
  `ItemCount2` int(10) NOT NULL DEFAULT '0',
  `ItemCount3` int(10) NOT NULL DEFAULT '0',
  `ItemCount4` int(10) NOT NULL DEFAULT '0',
  `Explored1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Explored2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Time1` int(10) NOT NULL DEFAULT '0',
  `Time2` int(10) NOT NULL DEFAULT '0',
  `AuraSpellID1` int(10) NOT NULL DEFAULT '0',
  `AuraSpellID2` int(10) NOT NULL DEFAULT '0',
  `AuraSpellID3` int(10) NOT NULL DEFAULT '0',
  `AuraSpellID4` int(10) NOT NULL DEFAULT '0',
  `AuraStacks1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AuraStacks2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AuraStacks3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AuraStacks4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Achievement1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Achievement2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Achievement3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Achievement4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LfgStatus1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgStatus2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgStatus3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgStatus4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgCompare1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgCompare2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgCompare3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgCompare4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LfgValue1` int(10) NOT NULL DEFAULT '0',
  `LfgValue2` int(10) NOT NULL DEFAULT '0',
  `LfgValue3` int(10) NOT NULL DEFAULT '0',
  `LfgValue4` int(10) NOT NULL DEFAULT '0',
  `CurrencyID1` int(10) NOT NULL DEFAULT '0',
  `CurrencyID2` int(10) NOT NULL DEFAULT '0',
  `CurrencyID3` int(10) NOT NULL DEFAULT '0',
  `CurrencyID4` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount1` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount2` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount3` int(10) NOT NULL DEFAULT '0',
  `CurrencyCount4` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster1` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster2` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster3` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster4` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster5` int(10) NOT NULL DEFAULT '0',
  `QuestKillMonster6` int(10) NOT NULL DEFAULT '0',
  `MovementFlags1` int(10) NOT NULL DEFAULT '0',
  `MovementFlags2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `powerdisplay`
--

DROP TABLE IF EXISTS `powerdisplay`;
CREATE TABLE `powerdisplay` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `GlobalStringBaseTag` text,
  `ActualType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Red` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Green` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Blue` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `powertype`
--

DROP TABLE IF EXISTS `powertype`;
CREATE TABLE `powertype` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `NameGlobalStringTag` text,
  `CostGlobalStringTag` text,
  `PowerTypeEnum` tinyint(3) NOT NULL DEFAULT '0',
  `MinPower` tinyint(3) NOT NULL DEFAULT '0',
  `MaxBasePower` smallint(6) NOT NULL DEFAULT '0',
  `CenterPower` tinyint(3) NOT NULL DEFAULT '0',
  `DefaultPower` tinyint(3) NOT NULL DEFAULT '0',
  `DisplayModifier` tinyint(3) NOT NULL DEFAULT '0',
  `RegenInterruptTimeMS` smallint(6) NOT NULL DEFAULT '0',
  `RegenPeace` float NOT NULL DEFAULT '0',
  `RegenCombat` float NOT NULL DEFAULT '0',
  `Flags` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `prestigelevelinfo`
--

DROP TABLE IF EXISTS `prestigelevelinfo`;
CREATE TABLE `prestigelevelinfo` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `HonorLevel` int(10) NOT NULL DEFAULT '0',
  `BadgeTextureFileDataID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Unknown` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `pvpdifficulty`
--

DROP TABLE IF EXISTS `pvpdifficulty`;
CREATE TABLE `pvpdifficulty` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RangeIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MapID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `pvpitem`
--

DROP TABLE IF EXISTS `pvpitem`;
CREATE TABLE `pvpitem` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `ItemLevelDelta` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `pvpreward`
--

DROP TABLE IF EXISTS `pvpreward`;
CREATE TABLE `pvpreward` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `HonorLevel` int(10) NOT NULL DEFAULT '0',
  `PrestigeLevel` int(10) NOT NULL DEFAULT '0',
  `RewardPackID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `pvptalent`
--

DROP TABLE IF EXISTS `pvptalent`;
CREATE TABLE `pvptalent` (
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `SpecID` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `ActionBarSpellID` int(10) NOT NULL DEFAULT '0',
  `PvpTalentCategoryID` int(10) NOT NULL DEFAULT '0',
  `LevelRequired` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `pvptalentunlock`
--

DROP TABLE IF EXISTS `pvptalentunlock`;
CREATE TABLE `pvptalentunlock` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `TierID` int(10) NOT NULL DEFAULT '0',
  `ColumnIndex` int(10) NOT NULL DEFAULT '0',
  `HonorLevel` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questfactionreward`
--

DROP TABLE IF EXISTS `questfactionreward`;
CREATE TABLE `questfactionreward` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty1` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty2` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty3` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty4` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty5` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty6` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty7` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty8` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty9` smallint(6) NOT NULL DEFAULT '0',
  `Difficulty10` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questmoneyreward`
--

DROP TABLE IF EXISTS `questmoneyreward`;
CREATE TABLE `questmoneyreward` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty6` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty7` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty8` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty9` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty10` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questpackageitem`
--

DROP TABLE IF EXISTS `questpackageitem`;
CREATE TABLE `questpackageitem` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PackageID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `ItemQuantity` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questsort`
--

DROP TABLE IF EXISTS `questsort`;
CREATE TABLE `questsort` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SortName` text,
  `UiOrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questv2`
--

DROP TABLE IF EXISTS `questv2`;
CREATE TABLE `questv2` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UniqueBitFlag` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `questxp`
--

DROP TABLE IF EXISTS `questxp`;
CREATE TABLE `questxp` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty9` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Difficulty10` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `randproppoints`
--

DROP TABLE IF EXISTS `randproppoints`;
CREATE TABLE `randproppoints` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DamageReplaceStat` int(10) NOT NULL DEFAULT '0',
  `Epic1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Epic2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Epic3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Epic4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Epic5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Superior1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Superior2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Superior3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Superior4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Superior5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Good1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Good2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Good3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Good4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Good5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `rewardpack`
--

DROP TABLE IF EXISTS `rewardpack`;
CREATE TABLE `rewardpack` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CharTitleID` int(10) NOT NULL DEFAULT '0',
  `Money` int(10) NOT NULL DEFAULT '0',
  `ArtifactXPDifficulty` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ArtifactXPMultiplier` float NOT NULL DEFAULT '0',
  `ArtifactXPCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TreasurePickerID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `rewardpackxcurrencytype`
--

DROP TABLE IF EXISTS `rewardpackxcurrencytype`;
CREATE TABLE `rewardpackxcurrencytype` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CurrencyTypeID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Quantity` int(10) NOT NULL DEFAULT '0',
  `RewardPackID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `rewardpackxitem`
--

DROP TABLE IF EXISTS `rewardpackxitem`;
CREATE TABLE `rewardpackxitem` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `ItemQuantity` int(10) NOT NULL DEFAULT '0',
  `RewardPackID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `rulesetitemupgrade`
--

DROP TABLE IF EXISTS `rulesetitemupgrade`;
CREATE TABLE `rulesetitemupgrade` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `ItemUpgradeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `sandboxscaling`
--

DROP TABLE IF EXISTS `sandboxscaling`;
CREATE TABLE `sandboxscaling` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` int(10) NOT NULL DEFAULT '0',
  `MaxLevel` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scalingstatdistribution`
--

DROP TABLE IF EXISTS `scalingstatdistribution`;
CREATE TABLE `scalingstatdistribution` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PlayerLevelToItemLevelCurveID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` int(10) NOT NULL DEFAULT '0',
  `MaxLevel` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenario`
--

DROP TABLE IF EXISTS `scenario`;
CREATE TABLE `scenario` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `AreaTableID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Unknown` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenariostep`
--

DROP TABLE IF EXISTS `scenariostep`;
CREATE TABLE `scenariostep` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Description` text,
  `Title` text,
  `ScenarioID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CriteriatreeID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RewardQuestID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RelatedStep` int(10) NOT NULL DEFAULT '0',
  `Supersedes` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Unknown` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenescript`
--

DROP TABLE IF EXISTS `scenescript`;
CREATE TABLE `scenescript` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FirstSceneScriptID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NextSceneScriptID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenescriptglobaltext`
--

DROP TABLE IF EXISTS `scenescriptglobaltext`;
CREATE TABLE `scenescriptglobaltext` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenescriptpackage`
--

DROP TABLE IF EXISTS `scenescriptpackage`;
CREATE TABLE `scenescriptpackage` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `scenescripttext`
--

DROP TABLE IF EXISTS `scenescripttext`;
CREATE TABLE `scenescripttext` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `skillline`
--

DROP TABLE IF EXISTS `skillline`;
CREATE TABLE `skillline` (
  `DisplayName` text,
  `AlternateVerb` text,
  `Description` text,
  `HordeDisplayName` text,
  `ExpansionDisplayName` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `CategoryID` tinyint(3) NOT NULL DEFAULT '0',
  `SpellIconFileID` int(10) NOT NULL DEFAULT '0',
  `CanLink` tinyint(3) NOT NULL DEFAULT '0',
  `ParentSkillLineID` int(10) NOT NULL DEFAULT '0',
  `ParentTierIndex` int(10) NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `skilllineability`
--

DROP TABLE IF EXISTS `skilllineability`;
CREATE TABLE `skilllineability` (
  `RaceMask` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `SkillLine` smallint(6) NOT NULL DEFAULT '0',
  `Spell` int(10) NOT NULL DEFAULT '0',
  `MinSkillLineRank` smallint(6) NOT NULL DEFAULT '0',
  `ClassMask` int(10) NOT NULL DEFAULT '0',
  `SupercedesSpell` int(10) NOT NULL DEFAULT '0',
  `AcquireMethod` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TrivialSkillLineRankHigh` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TrivialSkillLineRankLow` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `NumSkillUps` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UniqueBit` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TradeSkillCategoryID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SkillupSkillLineID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `skillraceclassinfo`
--

DROP TABLE IF EXISTS `skillraceclassinfo`;
CREATE TABLE `skillraceclassinfo` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RaceMask` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SkillID` smallint(6) NOT NULL DEFAULT '0',
  `ClassMask` int(10) NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Availability` tinyint(3) NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) NOT NULL DEFAULT '0',
  `SkillTierID` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `soundkit`
--

DROP TABLE IF EXISTS `soundkit`;
CREATE TABLE `soundkit` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `SoundType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VolumeFloat` float NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinDistance` float NOT NULL DEFAULT '0',
  `DistanceCutoff` float NOT NULL DEFAULT '0',
  `EAXDef` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundKitAdvancedID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VolumeVariationPlus` float NOT NULL DEFAULT '0',
  `VolumeVariationMinus` float NOT NULL DEFAULT '0',
  `PitchVariationPlus` float NOT NULL DEFAULT '0',
  `PitchVariationMinus` float NOT NULL DEFAULT '0',
  `DialogType` tinyint(3) NOT NULL DEFAULT '0',
  `PitchAdjust` float NOT NULL DEFAULT '0',
  `BusOverwriteID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxInstances` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `specializationspells`
--

DROP TABLE IF EXISTS `specializationspells`;
CREATE TABLE `specializationspells` (
  `Description` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `SpecID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) NOT NULL DEFAULT '0',
  `DisplayOrder` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spell`
--

DROP TABLE IF EXISTS `spell`;
CREATE TABLE `spell` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `NameSubtext` text,
  `Description` text,
  `AuraDescription` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellauraoptions`
--

DROP TABLE IF EXISTS `spellauraoptions`;
CREATE TABLE `spellauraoptions` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CumulativeAura` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ProcCategoryRecovery` int(10) NOT NULL DEFAULT '0',
  `ProcChance` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ProcCharges` int(10) NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ProcTypeMask1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ProcTypeMask2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellaurarestrictions`
--

DROP TABLE IF EXISTS `spellaurarestrictions`;
CREATE TABLE `spellaurarestrictions` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CasterAuraState` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TargetAuraState` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ExcludeCasterAuraState` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ExcludeTargetAuraState` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CasterAuraSpell` int(10) NOT NULL DEFAULT '0',
  `TargetAuraSpell` int(10) NOT NULL DEFAULT '0',
  `ExcludeCasterAuraSpell` int(10) NOT NULL DEFAULT '0',
  `ExcludeTargetAuraSpell` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellcastingrequirements`
--

DROP TABLE IF EXISTS `spellcastingrequirements`;
CREATE TABLE `spellcastingrequirements` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `FacingCasterFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinFactionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MinReputation` tinyint(3) NOT NULL DEFAULT '0',
  `RequiredAreasID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredAuraVision` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiresSpellFocus` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellcasttimes`
--

DROP TABLE IF EXISTS `spellcasttimes`;
CREATE TABLE `spellcasttimes` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Base` int(10) NOT NULL DEFAULT '0',
  `PerLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Minimum` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellcategories`
--

DROP TABLE IF EXISTS `spellcategories`;
CREATE TABLE `spellcategories` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Category` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DefenseType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `DispelType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Mechanic` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `PreventionType` tinyint(3) NOT NULL DEFAULT '0',
  `StartRecoveryCategory` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ChargeCategory` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellcategory`
--

DROP TABLE IF EXISTS `spellcategory`;
CREATE TABLE `spellcategory` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UsesPerWeek` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxCharges` tinyint(3) NOT NULL DEFAULT '0',
  `ChargeRecoveryTime` int(10) NOT NULL DEFAULT '0',
  `TypeMask` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellclassoptions`
--

DROP TABLE IF EXISTS `spellclassoptions`;
CREATE TABLE `spellclassoptions` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `ModalNextSpell` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassMask1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassMask2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassMask3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellClassMask4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellcooldowns`
--

DROP TABLE IF EXISTS `spellcooldowns`;
CREATE TABLE `spellcooldowns` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CategoryRecoveryTime` int(10) NOT NULL DEFAULT '0',
  `RecoveryTime` int(10) NOT NULL DEFAULT '0',
  `StartRecoveryTime` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellduration`
--

DROP TABLE IF EXISTS `spellduration`;
CREATE TABLE `spellduration` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Duration` int(10) NOT NULL DEFAULT '0',
  `DurationPerLevel` int(10) NOT NULL DEFAULT '0',
  `MaxDuration` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spelleffect`
--

DROP TABLE IF EXISTS `spelleffect`;
CREATE TABLE `spelleffect` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` int(10) NOT NULL DEFAULT '0',
  `EffectIndex` int(10) NOT NULL DEFAULT '0',
  `Effect` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectAmplitude` float NOT NULL DEFAULT '0',
  `EffectAttributes` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectAura` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EffectAuraPeriod` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectBonusCoefficient` float NOT NULL DEFAULT '0',
  `EffectChainAmplitude` float NOT NULL DEFAULT '0',
  `EffectChainTargets` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectItemType` int(10) NOT NULL DEFAULT '0',
  `EffectMechanic` int(10) NOT NULL DEFAULT '0',
  `EffectPointsPerResource` float NOT NULL DEFAULT '0',
  `EffectPosFacing` float NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel` float NOT NULL DEFAULT '0',
  `EffectTriggerSpell` int(10) NOT NULL DEFAULT '0',
  `BonusCoefficientFromAP` float NOT NULL DEFAULT '0',
  `PvpMultiplier` float NOT NULL DEFAULT '0',
  `Coefficient` float NOT NULL DEFAULT '0',
  `Variance` float NOT NULL DEFAULT '0',
  `ResourceCoefficient` float NOT NULL DEFAULT '0',
  `GroupSizeBasePointsCoefficient` float NOT NULL DEFAULT '0',
  `EffectBasePoints` float NOT NULL DEFAULT '0',
  `EffectMiscValue1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectMiscValue2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectRadiusIndex1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectRadiusIndex2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectSpellClassMask1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectSpellClassMask2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectSpellClassMask3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectSpellClassMask4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ImplicitTarget1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ImplicitTarget2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellequippeditems`
--

DROP TABLE IF EXISTS `spellequippeditems`;
CREATE TABLE `spellequippeditems` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `EquippedItemClass` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EquippedItemInvTypes` int(10) NOT NULL DEFAULT '0',
  `EquippedItemSubclass` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellfocusobject`
--

DROP TABLE IF EXISTS `spellfocusobject`;
CREATE TABLE `spellfocusobject` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellinterrupts`
--

DROP TABLE IF EXISTS `spellinterrupts`;
CREATE TABLE `spellinterrupts` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `InterruptFlags` smallint(6) NOT NULL DEFAULT '0',
  `AuraInterruptFlags1` int(10) NOT NULL DEFAULT '0',
  `AuraInterruptFlags2` int(10) NOT NULL DEFAULT '0',
  `ChannelInterruptFlags1` int(10) NOT NULL DEFAULT '0',
  `ChannelInterruptFlags2` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellitemenchantment`
--

DROP TABLE IF EXISTS `spellitemenchantment`;
CREATE TABLE `spellitemenchantment` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `HordeName` text,
  `EffectArg1` int(10) NOT NULL DEFAULT '0',
  `EffectArg2` int(10) NOT NULL DEFAULT '0',
  `EffectArg3` int(10) NOT NULL DEFAULT '0',
  `EffectScalingPoints1` float NOT NULL DEFAULT '0',
  `EffectScalingPoints2` float NOT NULL DEFAULT '0',
  `EffectScalingPoints3` float NOT NULL DEFAULT '0',
  `TransmogCost` int(10) NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) NOT NULL DEFAULT '0',
  `TransmogPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `EffectPointsMin1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EffectPointsMin2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `EffectPointsMin3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemVisual` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkillID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Charges` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Effect1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Effect2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Effect3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ScalingClass` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ScalingClassRestricted` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ConditionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellitemenchantmentcondition`
--

DROP TABLE IF EXISTS `spellitemenchantmentcondition`;
CREATE TABLE `spellitemenchantmentcondition` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperandType1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperandType2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperandType3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperandType4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperandType5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LtOperand1` int(10) NOT NULL DEFAULT '0',
  `LtOperand2` int(10) NOT NULL DEFAULT '0',
  `LtOperand3` int(10) NOT NULL DEFAULT '0',
  `LtOperand4` int(10) NOT NULL DEFAULT '0',
  `LtOperand5` int(10) NOT NULL DEFAULT '0',
  `Operator1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Operator2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Operator3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Operator4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Operator5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperandType1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperandType2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperandType3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperandType4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperandType5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperand1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperand2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperand3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperand4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RtOperand5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Logic1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Logic2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Logic3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Logic4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Logic5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spelllearnspell`
--

DROP TABLE IF EXISTS `spelllearnspell`;
CREATE TABLE `spelllearnspell` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `LearnSpellID` int(10) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spelllevels`
--

DROP TABLE IF EXISTS `spelllevels`;
CREATE TABLE `spelllevels` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BaseLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPassiveAuraLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellmisc`
--

DROP TABLE IF EXISTS `spellmisc`;
CREATE TABLE `spellmisc` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CastingTimeIndex` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DurationIndex` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RangeIndex` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SchoolMask` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Speed` float NOT NULL DEFAULT '0',
  `LaunchDelay` float NOT NULL DEFAULT '0',
  `Unknown` float NOT NULL DEFAULT '0',
  `SpellIconFileDataID` int(10) NOT NULL DEFAULT '0',
  `ActiveIconFileDataID` int(10) NOT NULL DEFAULT '0',
  `Attributes1` int(10) NOT NULL DEFAULT '0',
  `Attributes2` int(10) NOT NULL DEFAULT '0',
  `Attributes3` int(10) NOT NULL DEFAULT '0',
  `Attributes4` int(10) NOT NULL DEFAULT '0',
  `Attributes5` int(10) NOT NULL DEFAULT '0',
  `Attributes6` int(10) NOT NULL DEFAULT '0',
  `Attributes7` int(10) NOT NULL DEFAULT '0',
  `Attributes8` int(10) NOT NULL DEFAULT '0',
  `Attributes9` int(10) NOT NULL DEFAULT '0',
  `Attributes10` int(10) NOT NULL DEFAULT '0',
  `Attributes11` int(10) NOT NULL DEFAULT '0',
  `Attributes12` int(10) NOT NULL DEFAULT '0',
  `Attributes13` int(10) NOT NULL DEFAULT '0',
  `Attributes14` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellpower`
--

DROP TABLE IF EXISTS `spellpower`;
CREATE TABLE `spellpower` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ManaCost` int(10) NOT NULL DEFAULT '0',
  `ManaCostPerLevel` int(10) NOT NULL DEFAULT '0',
  `ManaPerSecond` int(10) NOT NULL DEFAULT '0',
  `PowerDisplayID` int(10) NOT NULL DEFAULT '0',
  `AltPowerBarID` int(10) NOT NULL DEFAULT '0',
  `PowerCostPct` float NOT NULL DEFAULT '0',
  `PowerCostMaxPct` float NOT NULL DEFAULT '0',
  `PowerPctPerSecond` float NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredAuraSpellID` int(10) NOT NULL DEFAULT '0',
  `OptionalCost` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellpowerdifficulty`
--

DROP TABLE IF EXISTS `spellpowerdifficulty`;
CREATE TABLE `spellpowerdifficulty` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellprocsperminute`
--

DROP TABLE IF EXISTS `spellprocsperminute`;
CREATE TABLE `spellprocsperminute` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BaseProcRate` float NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellprocsperminutemod`
--

DROP TABLE IF EXISTS `spellprocsperminutemod`;
CREATE TABLE `spellprocsperminutemod` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Param` smallint(6) NOT NULL DEFAULT '0',
  `Coeff` float NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellradius`
--

DROP TABLE IF EXISTS `spellradius`;
CREATE TABLE `spellradius` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `RadiusPerLevel` float NOT NULL DEFAULT '0',
  `RadiusMin` float NOT NULL DEFAULT '0',
  `RadiusMax` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellrange`
--

DROP TABLE IF EXISTS `spellrange`;
CREATE TABLE `spellrange` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayName` text,
  `DisplayNameShort` text,
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RangeMin1` float NOT NULL DEFAULT '0',
  `RangeMin2` float NOT NULL DEFAULT '0',
  `RangeMax1` float NOT NULL DEFAULT '0',
  `RangeMax2` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellreagents`
--

DROP TABLE IF EXISTS `spellreagents`;
CREATE TABLE `spellreagents` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `Reagent1` int(10) NOT NULL DEFAULT '0',
  `Reagent2` int(10) NOT NULL DEFAULT '0',
  `Reagent3` int(10) NOT NULL DEFAULT '0',
  `Reagent4` int(10) NOT NULL DEFAULT '0',
  `Reagent5` int(10) NOT NULL DEFAULT '0',
  `Reagent6` int(10) NOT NULL DEFAULT '0',
  `Reagent7` int(10) NOT NULL DEFAULT '0',
  `Reagent8` int(10) NOT NULL DEFAULT '0',
  `ReagentCount1` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount2` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount3` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount4` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount5` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount6` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount7` smallint(6) NOT NULL DEFAULT '0',
  `ReagentCount8` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellscaling`
--

DROP TABLE IF EXISTS `spellscaling`;
CREATE TABLE `spellscaling` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `Class` int(10) NOT NULL DEFAULT '0',
  `MinScalingLevel` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MaxScalingLevel` int(10) NOT NULL DEFAULT '0',
  `ScalesFromItemLevel` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellshapeshift`
--

DROP TABLE IF EXISTS `spellshapeshift`;
CREATE TABLE `spellshapeshift` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `StanceBarOrder` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ShapeshiftExclude1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ShapeshiftExclude2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ShapeshiftMask1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ShapeshiftMask2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellshapeshiftform`
--

DROP TABLE IF EXISTS `spellshapeshiftform`;
CREATE TABLE `spellshapeshiftform` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `CreatureType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `AttackIconFileID` int(10) NOT NULL DEFAULT '0',
  `BonusActionBar` tinyint(3) NOT NULL DEFAULT '0',
  `CombatRoundTime` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DamageVariance` float NOT NULL DEFAULT '0',
  `MountTypeID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CreatureDisplayID1` int(10) NOT NULL DEFAULT '0',
  `CreatureDisplayID2` int(10) NOT NULL DEFAULT '0',
  `CreatureDisplayID3` int(10) NOT NULL DEFAULT '0',
  `CreatureDisplayID4` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID1` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID2` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID3` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID4` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID5` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID6` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID7` int(10) NOT NULL DEFAULT '0',
  `PresetSpellID8` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spelltargetrestrictions`
--

DROP TABLE IF EXISTS `spelltargetrestrictions`;
CREATE TABLE `spelltargetrestrictions` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ConeDegrees` float NOT NULL DEFAULT '0',
  `MaxTargets` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `MaxTargetLevel` int(10) NOT NULL DEFAULT '0',
  `TargetCreatureType` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Targets` int(10) NOT NULL DEFAULT '0',
  `Width` float NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spelltotems`
--

DROP TABLE IF EXISTS `spelltotems`;
CREATE TABLE `spelltotems` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Totem1` int(10) NOT NULL DEFAULT '0',
  `Totem2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `spellxspellvisual`
--

DROP TABLE IF EXISTS `spellxspellvisual`;
CREATE TABLE `spellxspellvisual` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellVisualID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Probability` float NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Priority` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpellIconFileID` int(10) NOT NULL DEFAULT '0',
  `ActiveIconFileID` int(10) NOT NULL DEFAULT '0',
  `ViewerUnitConditionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ViewerPlayerConditionID` int(10) NOT NULL DEFAULT '0',
  `CasterUnitConditionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CasterPlayerConditionID` int(10) NOT NULL DEFAULT '0',
  `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `summonproperties`
--

DROP TABLE IF EXISTS `summonproperties`;
CREATE TABLE `summonproperties` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Control` int(10) NOT NULL DEFAULT '0',
  `Faction` int(10) NOT NULL DEFAULT '0',
  `Title` int(10) NOT NULL DEFAULT '0',
  `Slot` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `tactkey`
--

DROP TABLE IF EXISTS `tactkey`;
CREATE TABLE `tactkey` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Key1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key5` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key6` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key7` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key8` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key9` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key10` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key11` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key12` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key13` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key14` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key15` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Key16` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `talent`
--

DROP TABLE IF EXISTS `talent`;
CREATE TABLE `talent` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Description` text,
  `TierID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ColumnIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SpecID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) NOT NULL DEFAULT '0',
  `CategoryMask1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `CategoryMask2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `taxinodes`
--

DROP TABLE IF EXISTS `taxinodes`;
CREATE TABLE `taxinodes` (
  `Name` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `MapOffset1` float NOT NULL DEFAULT '0',
  `MapOffset2` float NOT NULL DEFAULT '0',
  `FlightMapOffset1` float NOT NULL DEFAULT '0',
  `FlightMapOffset2` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `ContinentID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ConditionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CharacterBitNumber` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiTextureKitID` int(10) NOT NULL DEFAULT '0',
  `Facing` float NOT NULL DEFAULT '0',
  `SpecialIconConditionID` int(10) NOT NULL DEFAULT '0',
  `Unknown` int(10) NOT NULL DEFAULT '0',
  `MountCreatureID1` int(10) NOT NULL DEFAULT '0',
  `MountCreatureID2` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `taxipath`
--

DROP TABLE IF EXISTS `taxipath`;
CREATE TABLE `taxipath` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `FromTaxiNode` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ToTaxiNode` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Cost` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `taxipathnode`
--

DROP TABLE IF EXISTS `taxipathnode`;
CREATE TABLE `taxipathnode` (
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `ID` int(10) NOT NULL DEFAULT '0',
  `PathID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NodeIndex` int(10) NOT NULL DEFAULT '0',
  `ContinentID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Delay` int(10) NOT NULL DEFAULT '0',
  `ArrivalEventID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DepartureEventID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `totemcategory`
--

DROP TABLE IF EXISTS `totemcategory`;
CREATE TABLE `totemcategory` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `TotemCategoryType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TotemCategoryMask` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `toy`
--

DROP TABLE IF EXISTS `toy`;
CREATE TABLE `toy` (
  `SourceText` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transmogholiday`
--

DROP TABLE IF EXISTS `transmogholiday`;
CREATE TABLE `transmogholiday` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `RequiredTransmogHoliday` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transmogset`
--

DROP TABLE IF EXISTS `transmogset`;
CREATE TABLE `transmogset` (
  `Name` text,
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ClassMask` int(10) NOT NULL DEFAULT '0',
  `TrackingQuestID` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `TransmogSetGroupID` int(10) NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` int(10) NOT NULL DEFAULT '0',
  `ParentTransmogSetID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `UiOrder` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transmogsetgroup`
--

DROP TABLE IF EXISTS `transmogsetgroup`;
CREATE TABLE `transmogsetgroup` (
  `Name` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transmogsetitem`
--

DROP TABLE IF EXISTS `transmogsetitem`;
CREATE TABLE `transmogsetitem` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `TransmogSetID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transportanimation`
--

DROP TABLE IF EXISTS `transportanimation`;
CREATE TABLE `transportanimation` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `SequenceID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TimeIndex` int(10) NOT NULL DEFAULT '0',
  `TransportID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `transportrotation`
--

DROP TABLE IF EXISTS `transportrotation`;
CREATE TABLE `transportrotation` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `Rot4` float NOT NULL DEFAULT '0',
  `TimeIndex` int(10) NOT NULL DEFAULT '0',
  `GameObjectsID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `unitpowerbar`
--

DROP TABLE IF EXISTS `unitpowerbar`;
CREATE TABLE `unitpowerbar` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Name` text,
  `Cost` text,
  `OutOfError` text,
  `ToolTip` text,
  `MinPower` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MaxPower` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `StartPower` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `CenterPower` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `BarType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `StartInset` float NOT NULL DEFAULT '0',
  `EndInset` float NOT NULL DEFAULT '0',
  `FileDataID1` int(10) NOT NULL DEFAULT '0',
  `FileDataID2` int(10) NOT NULL DEFAULT '0',
  `FileDataID3` int(10) NOT NULL DEFAULT '0',
  `FileDataID4` int(10) NOT NULL DEFAULT '0',
  `FileDataID5` int(10) NOT NULL DEFAULT '0',
  `FileDataID6` int(10) NOT NULL DEFAULT '0',
  `Color1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Color2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Color3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Color4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Color5` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Color6` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `vehicle`
--

DROP TABLE IF EXISTS `vehicle`;
CREATE TABLE `vehicle` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `FlagsB` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TurnSpeed` float NOT NULL DEFAULT '0',
  `PitchSpeed` float NOT NULL DEFAULT '0',
  `PitchMin` float NOT NULL DEFAULT '0',
  `PitchMax` float NOT NULL DEFAULT '0',
  `MouseLookOffsetPitch` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMin` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMax` float NOT NULL DEFAULT '0',
  `CameraPitchOffset` float NOT NULL DEFAULT '0',
  `FacingLimitRight` float NOT NULL DEFAULT '0',
  `FacingLimitLeft` float NOT NULL DEFAULT '0',
  `CameraYawOffset` float NOT NULL DEFAULT '0',
  `UiLocomotionType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VehicleUIIndicatorID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `MissileTargetingID` int(10) NOT NULL DEFAULT '0',
  `SeatID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID4` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID5` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID6` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID7` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `SeatID8` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PowerDisplayID1` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PowerDisplayID2` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `PowerDisplayID3` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `vehicleseat`
--

DROP TABLE IF EXISTS `vehicleseat`;
CREATE TABLE `vehicleseat` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `AttachmentOffsetX` float NOT NULL DEFAULT '0',
  `AttachmentOffsetY` float NOT NULL DEFAULT '0',
  `AttachmentOffsetZ` float NOT NULL DEFAULT '0',
  `CameraOffsetX` float NOT NULL DEFAULT '0',
  `CameraOffsetY` float NOT NULL DEFAULT '0',
  `CameraOffsetZ` float NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `FlagsB` int(10) NOT NULL DEFAULT '0',
  `FlagsC` int(10) NOT NULL DEFAULT '0',
  `AttachmentID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `EnterPreDelay` float NOT NULL DEFAULT '0',
  `EnterSpeed` float NOT NULL DEFAULT '0',
  `EnterGravity` float NOT NULL DEFAULT '0',
  `EnterMinDuration` float NOT NULL DEFAULT '0',
  `EnterMaxDuration` float NOT NULL DEFAULT '0',
  `EnterMinArcHeight` float NOT NULL DEFAULT '0',
  `EnterMaxArcHeight` float NOT NULL DEFAULT '0',
  `EnterAnimStart` int(10) NOT NULL DEFAULT '0',
  `EnterAnimLoop` int(10) NOT NULL DEFAULT '0',
  `RideAnimStart` int(10) NOT NULL DEFAULT '0',
  `RideAnimLoop` int(10) NOT NULL DEFAULT '0',
  `RideUpperAnimStart` int(10) NOT NULL DEFAULT '0',
  `RideUpperAnimLoop` int(10) NOT NULL DEFAULT '0',
  `ExitPreDelay` float NOT NULL DEFAULT '0',
  `ExitSpeed` float NOT NULL DEFAULT '0',
  `ExitGravity` float NOT NULL DEFAULT '0',
  `ExitMinDuration` float NOT NULL DEFAULT '0',
  `ExitMaxDuration` float NOT NULL DEFAULT '0',
  `ExitMinArcHeight` float NOT NULL DEFAULT '0',
  `ExitMaxArcHeight` float NOT NULL DEFAULT '0',
  `ExitAnimStart` int(10) NOT NULL DEFAULT '0',
  `ExitAnimLoop` int(10) NOT NULL DEFAULT '0',
  `ExitAnimEnd` int(10) NOT NULL DEFAULT '0',
  `VehicleEnterAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleEnterAnimBone` tinyint(3) NOT NULL DEFAULT '0',
  `VehicleExitAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleExitAnimBone` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VehicleRideAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `VehicleRideAnimLoopBone` tinyint(3) NOT NULL DEFAULT '0',
  `PassengerAttachmentID` tinyint(3) NOT NULL DEFAULT '0',
  `PassengerYaw` float NOT NULL DEFAULT '0',
  `PassengerPitch` float NOT NULL DEFAULT '0',
  `PassengerRoll` float NOT NULL DEFAULT '0',
  `VehicleEnterAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleExitAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleAbilityDisplay` tinyint(3) NOT NULL DEFAULT '0',
  `EnterUISoundID` int(10) NOT NULL DEFAULT '0',
  `ExitUISoundID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `UiSkinFileDataID` int(10) NOT NULL DEFAULT '0',
  `CameraEnteringDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDuration` float NOT NULL DEFAULT '0',
  `CameraExitingDelay` float NOT NULL DEFAULT '0',
  `CameraExitingDuration` float NOT NULL DEFAULT '0',
  `CameraPosChaseRate` float NOT NULL DEFAULT '0',
  `CameraFacingChaseRate` float NOT NULL DEFAULT '0',
  `CameraEnteringZoom` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMin` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMax` float NOT NULL DEFAULT '0',
  `EnterAnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `RideAnimKitID` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VehicleEnterAnimKitID` smallint(6) NOT NULL DEFAULT '0',
  `VehicleRideAnimKitID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VehicleExitAnimKitID` smallint(6) NOT NULL DEFAULT '0',
  `CameraModeID` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `wmoareatable`
--

DROP TABLE IF EXISTS `wmoareatable`;
CREATE TABLE `wmoareatable` (
  `AreaName` text,
  `ID` int(10) NOT NULL DEFAULT '0',
  `WmoID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NameSetID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `WmoGroupID` int(10) NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `AmbienceID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwAmbience` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ZoneMusic` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwZoneMusic` int(10) NOT NULL DEFAULT '0',
  `IntroSound` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `UwIntroSound` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaTableID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `worldeffect`
--

DROP TABLE IF EXISTS `worldeffect`;
CREATE TABLE `worldeffect` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int(10) NOT NULL DEFAULT '0',
  `WhenToDisplay` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TargetType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `TargetAsset` int(10) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `CombatConditionID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `worldmaparea`
--

DROP TABLE IF EXISTS `worldmaparea`;
CREATE TABLE `worldmaparea` (
  `AreaName` text,
  `LocLeft` float NOT NULL DEFAULT '0',
  `LocRight` float NOT NULL DEFAULT '0',
  `LocTop` float NOT NULL DEFAULT '0',
  `LocBottom` float NOT NULL DEFAULT '0',
  `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `AreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `DisplayMapID` smallint(6) NOT NULL DEFAULT '0',
  `DefaultDungeonFloor` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `ParentWorldMapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `LevelRangeMin` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `LevelRangeMax` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BountySetID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BountyDisplayLocation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `worldmapoverlay`
--

DROP TABLE IF EXISTS `worldmapoverlay`;
CREATE TABLE `worldmapoverlay` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `UiMapArtID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `TextureWidth` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `TextureHeight` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `OffsetX` int(10) NOT NULL DEFAULT '0',
  `OffsetY` int(10) NOT NULL DEFAULT '0',
  `HitRectTop` int(10) NOT NULL DEFAULT '0',
  `HitRectBottom` int(10) NOT NULL DEFAULT '0',
  `HitRectLeft` int(10) NOT NULL DEFAULT '0',
  `HitRectRight` int(10) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID1` int(10) NOT NULL DEFAULT '0',
  `AreaID2` int(10) NOT NULL DEFAULT '0',
  `AreaID3` int(10) NOT NULL DEFAULT '0',
  `AreaID4` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `worldmaptransforms`
--

DROP TABLE IF EXISTS `worldmaptransforms`;
CREATE TABLE `worldmaptransforms` (
  `ID` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `RegionMinX` float NOT NULL DEFAULT '0',
  `RegionMinY` float NOT NULL DEFAULT '0',
  `RegionMinZ` float NOT NULL DEFAULT '0',
  `RegionMaxX` float NOT NULL DEFAULT '0',
  `RegionMaxY` float NOT NULL DEFAULT '0',
  `RegionMaxZ` float NOT NULL DEFAULT '0',
  `RegionOffsetX` float NOT NULL DEFAULT '0',
  `RegionOffsetY` float NOT NULL DEFAULT '0',
  `RegionScale` float NOT NULL DEFAULT '0',
  `MapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `AreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NewMapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NewDungeonMapID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `NewAreaID` smallint(6) UNSIGNED NOT NULL DEFAULT '0',
  `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `Priority` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `achievement`
--
ALTER TABLE `achievement`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `animkit`
--
ALTER TABLE `animkit`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `areagroupmember`
--
ALTER TABLE `areagroupmember`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `areatable`
--
ALTER TABLE `areatable`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `areatrigger`
--
ALTER TABLE `areatrigger`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `armorlocation`
--
ALTER TABLE `armorlocation`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifact`
--
ALTER TABLE `artifact`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactappearance`
--
ALTER TABLE `artifactappearance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactappearanceset`
--
ALTER TABLE `artifactappearanceset`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactcategory`
--
ALTER TABLE `artifactcategory`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactpower`
--
ALTER TABLE `artifactpower`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactpowerlink`
--
ALTER TABLE `artifactpowerlink`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactpowerpicker`
--
ALTER TABLE `artifactpowerpicker`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactpowerrank`
--
ALTER TABLE `artifactpowerrank`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactquestxp`
--
ALTER TABLE `artifactquestxp`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifacttier`
--
ALTER TABLE `artifacttier`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `artifactunlock`
--
ALTER TABLE `artifactunlock`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `auctionhouse`
--
ALTER TABLE `auctionhouse`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `bankbagslotprices`
--
ALTER TABLE `bankbagslotprices`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `bannedaddons`
--
ALTER TABLE `bannedaddons`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `barbershopstyle`
--
ALTER TABLE `barbershopstyle`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `battlemasterlist`
--
ALTER TABLE `battlemasterlist`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `battlepetbreedquality`
--
ALTER TABLE `battlepetbreedquality`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `battlepetbreedstate`
--
ALTER TABLE `battlepetbreedstate`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `battlepetspecies`
--
ALTER TABLE `battlepetspecies`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `battlepetspeciesstate`
--
ALTER TABLE `battlepetspeciesstate`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `broadcasttext`
--
ALTER TABLE `broadcasttext`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `cfgregions`
--
ALTER TABLE `cfgregions`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `characterfacialhairstyles`
--
ALTER TABLE `characterfacialhairstyles`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `charbasesection`
--
ALTER TABLE `charbasesection`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `charsections`
--
ALTER TABLE `charsections`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `charstartoutfit`
--
ALTER TABLE `charstartoutfit`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chartitles`
--
ALTER TABLE `chartitles`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chatchannels`
--
ALTER TABLE `chatchannels`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chrclasses`
--
ALTER TABLE `chrclasses`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chrclassesxpowertypes`
--
ALTER TABLE `chrclassesxpowertypes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chrraces`
--
ALTER TABLE `chrraces`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `chrspecialization`
--
ALTER TABLE `chrspecialization`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `cinematiccamera`
--
ALTER TABLE `cinematiccamera`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `cinematicsequences`
--
ALTER TABLE `cinematicsequences`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `conversationline`
--
ALTER TABLE `conversationline`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `creaturedisplayinfo`
--
ALTER TABLE `creaturedisplayinfo`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `creaturedisplayinfoextra`
--
ALTER TABLE `creaturedisplayinfoextra`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `creaturefamily`
--
ALTER TABLE `creaturefamily`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `creaturemodeldata`
--
ALTER TABLE `creaturemodeldata`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `creaturetype`
--
ALTER TABLE `creaturetype`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `criteria`
--
ALTER TABLE `criteria`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `criteriatree`
--
ALTER TABLE `criteriatree`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `currencytypes`
--
ALTER TABLE `currencytypes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `curve`
--
ALTER TABLE `curve`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `curvepoint`
--
ALTER TABLE `curvepoint`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `destructiblemodeldata`
--
ALTER TABLE `destructiblemodeldata`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `difficulty`
--
ALTER TABLE `difficulty`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `dungeonencounter`
--
ALTER TABLE `dungeonencounter`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `durabilitycosts`
--
ALTER TABLE `durabilitycosts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `durabilityquality`
--
ALTER TABLE `durabilityquality`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `emotes`
--
ALTER TABLE `emotes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `emotestext`
--
ALTER TABLE `emotestext`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `emotestextsound`
--
ALTER TABLE `emotestextsound`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `faction`
--
ALTER TABLE `faction`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `factiontemplate`
--
ALTER TABLE `factiontemplate`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `gameobjectdisplayinfo`
--
ALTER TABLE `gameobjectdisplayinfo`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `gameobjects`
--
ALTER TABLE `gameobjects`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrability`
--
ALTER TABLE `garrability`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrbuilding`
--
ALTER TABLE `garrbuilding`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrbuildingplotinst`
--
ALTER TABLE `garrbuildingplotinst`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrclassspec`
--
ALTER TABLE `garrclassspec`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrfollower`
--
ALTER TABLE `garrfollower`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrfollowerxability`
--
ALTER TABLE `garrfollowerxability`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrplot`
--
ALTER TABLE `garrplot`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrplotbuilding`
--
ALTER TABLE `garrplotbuilding`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrplotinstance`
--
ALTER TABLE `garrplotinstance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrsitelevel`
--
ALTER TABLE `garrsitelevel`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `garrsitelevelplotinst`
--
ALTER TABLE `garrsitelevelplotinst`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `gemproperties`
--
ALTER TABLE `gemproperties`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `glyphbindablespell`
--
ALTER TABLE `glyphbindablespell`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `glyphproperties`
--
ALTER TABLE `glyphproperties`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `glyphrequiredspec`
--
ALTER TABLE `glyphrequiredspec`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `guildcolorbackground`
--
ALTER TABLE `guildcolorbackground`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `guildcolorborder`
--
ALTER TABLE `guildcolorborder`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `guildcoloremblem`
--
ALTER TABLE `guildcoloremblem`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `guildperkspells`
--
ALTER TABLE `guildperkspells`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `heirloom`
--
ALTER TABLE `heirloom`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `holidays`
--
ALTER TABLE `holidays`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `importpricearmor`
--
ALTER TABLE `importpricearmor`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `importpricequality`
--
ALTER TABLE `importpricequality`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `importpriceshield`
--
ALTER TABLE `importpriceshield`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `importpriceweapon`
--
ALTER TABLE `importpriceweapon`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `item`
--
ALTER TABLE `item`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemappearance`
--
ALTER TABLE `itemappearance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemarmorquality`
--
ALTER TABLE `itemarmorquality`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemarmorshield`
--
ALTER TABLE `itemarmorshield`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemarmortotal`
--
ALTER TABLE `itemarmortotal`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itembagfamily`
--
ALTER TABLE `itembagfamily`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itembonus`
--
ALTER TABLE `itembonus`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itembonuslistleveldelta`
--
ALTER TABLE `itembonuslistleveldelta`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itembonustreenode`
--
ALTER TABLE `itembonustreenode`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemchildequipment`
--
ALTER TABLE `itemchildequipment`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemclass`
--
ALTER TABLE `itemclass`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemcurrencycost`
--
ALTER TABLE `itemcurrencycost`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdamageammo`
--
ALTER TABLE `itemdamageammo`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdamageonehand`
--
ALTER TABLE `itemdamageonehand`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdamageonehandcaster`
--
ALTER TABLE `itemdamageonehandcaster`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdamagetwohand`
--
ALTER TABLE `itemdamagetwohand`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdamagetwohandcaster`
--
ALTER TABLE `itemdamagetwohandcaster`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemdisenchantloot`
--
ALTER TABLE `itemdisenchantloot`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemeffect`
--
ALTER TABLE `itemeffect`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemextendedcost`
--
ALTER TABLE `itemextendedcost`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemlevelselector`
--
ALTER TABLE `itemlevelselector`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemlevelselectorquality`
--
ALTER TABLE `itemlevelselectorquality`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemlevelselectorqualityset`
--
ALTER TABLE `itemlevelselectorqualityset`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemlimitcategory`
--
ALTER TABLE `itemlimitcategory`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemlimitcategorycondition`
--
ALTER TABLE `itemlimitcategorycondition`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemmodifiedappearance`
--
ALTER TABLE `itemmodifiedappearance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itempricebase`
--
ALTER TABLE `itempricebase`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemrandomproperties`
--
ALTER TABLE `itemrandomproperties`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemrandomsuffix`
--
ALTER TABLE `itemrandomsuffix`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemsearchname`
--
ALTER TABLE `itemsearchname`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemset`
--
ALTER TABLE `itemset`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemsetspell`
--
ALTER TABLE `itemsetspell`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemsparse`
--
ALTER TABLE `itemsparse`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemspec`
--
ALTER TABLE `itemspec`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemspecoverride`
--
ALTER TABLE `itemspecoverride`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemupgrade`
--
ALTER TABLE `itemupgrade`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `itemxbonustree`
--
ALTER TABLE `itemxbonustree`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `keychain`
--
ALTER TABLE `keychain`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `lfgdungeons`
--
ALTER TABLE `lfgdungeons`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `light`
--
ALTER TABLE `light`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `liquidtype`
--
ALTER TABLE `liquidtype`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `lock`
--
ALTER TABLE `lock`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mailtemplate`
--
ALTER TABLE `mailtemplate`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `map`
--
ALTER TABLE `map`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mapdifficulty`
--
ALTER TABLE `mapdifficulty`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `modifiertree`
--
ALTER TABLE `modifiertree`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mount`
--
ALTER TABLE `mount`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mountcapability`
--
ALTER TABLE `mountcapability`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mounttypexcapability`
--
ALTER TABLE `mounttypexcapability`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `mountxdisplay`
--
ALTER TABLE `mountxdisplay`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `movie`
--
ALTER TABLE `movie`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `namegen`
--
ALTER TABLE `namegen`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `namesprofanity`
--
ALTER TABLE `namesprofanity`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `namesreserved`
--
ALTER TABLE `namesreserved`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `namesreservedlocale`
--
ALTER TABLE `namesreservedlocale`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `overridespelldata`
--
ALTER TABLE `overridespelldata`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `phase`
--
ALTER TABLE `phase`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `phasexphasegroup`
--
ALTER TABLE `phasexphasegroup`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `playercondition`
--
ALTER TABLE `playercondition`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `powerdisplay`
--
ALTER TABLE `powerdisplay`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `powertype`
--
ALTER TABLE `powertype`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `prestigelevelinfo`
--
ALTER TABLE `prestigelevelinfo`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `pvpdifficulty`
--
ALTER TABLE `pvpdifficulty`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `pvpitem`
--
ALTER TABLE `pvpitem`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `pvpreward`
--
ALTER TABLE `pvpreward`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `pvptalent`
--
ALTER TABLE `pvptalent`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `pvptalentunlock`
--
ALTER TABLE `pvptalentunlock`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questfactionreward`
--
ALTER TABLE `questfactionreward`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questmoneyreward`
--
ALTER TABLE `questmoneyreward`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questpackageitem`
--
ALTER TABLE `questpackageitem`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questsort`
--
ALTER TABLE `questsort`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questv2`
--
ALTER TABLE `questv2`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `questxp`
--
ALTER TABLE `questxp`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `randproppoints`
--
ALTER TABLE `randproppoints`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `rewardpack`
--
ALTER TABLE `rewardpack`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `rewardpackxcurrencytype`
--
ALTER TABLE `rewardpackxcurrencytype`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `rewardpackxitem`
--
ALTER TABLE `rewardpackxitem`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `rulesetitemupgrade`
--
ALTER TABLE `rulesetitemupgrade`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `sandboxscaling`
--
ALTER TABLE `sandboxscaling`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scalingstatdistribution`
--
ALTER TABLE `scalingstatdistribution`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenario`
--
ALTER TABLE `scenario`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenariostep`
--
ALTER TABLE `scenariostep`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenescript`
--
ALTER TABLE `scenescript`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenescriptglobaltext`
--
ALTER TABLE `scenescriptglobaltext`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenescriptpackage`
--
ALTER TABLE `scenescriptpackage`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `scenescripttext`
--
ALTER TABLE `scenescripttext`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `skillline`
--
ALTER TABLE `skillline`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `skilllineability`
--
ALTER TABLE `skilllineability`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `skillraceclassinfo`
--
ALTER TABLE `skillraceclassinfo`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `soundkit`
--
ALTER TABLE `soundkit`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `specializationspells`
--
ALTER TABLE `specializationspells`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spell`
--
ALTER TABLE `spell`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellauraoptions`
--
ALTER TABLE `spellauraoptions`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellaurarestrictions`
--
ALTER TABLE `spellaurarestrictions`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellcastingrequirements`
--
ALTER TABLE `spellcastingrequirements`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellcasttimes`
--
ALTER TABLE `spellcasttimes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellcategories`
--
ALTER TABLE `spellcategories`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellcategory`
--
ALTER TABLE `spellcategory`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellclassoptions`
--
ALTER TABLE `spellclassoptions`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellcooldowns`
--
ALTER TABLE `spellcooldowns`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellduration`
--
ALTER TABLE `spellduration`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spelleffect`
--
ALTER TABLE `spelleffect`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellequippeditems`
--
ALTER TABLE `spellequippeditems`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellfocusobject`
--
ALTER TABLE `spellfocusobject`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellinterrupts`
--
ALTER TABLE `spellinterrupts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellitemenchantment`
--
ALTER TABLE `spellitemenchantment`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellitemenchantmentcondition`
--
ALTER TABLE `spellitemenchantmentcondition`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spelllearnspell`
--
ALTER TABLE `spelllearnspell`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spelllevels`
--
ALTER TABLE `spelllevels`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellmisc`
--
ALTER TABLE `spellmisc`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellpower`
--
ALTER TABLE `spellpower`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellpowerdifficulty`
--
ALTER TABLE `spellpowerdifficulty`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellprocsperminute`
--
ALTER TABLE `spellprocsperminute`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellprocsperminutemod`
--
ALTER TABLE `spellprocsperminutemod`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellradius`
--
ALTER TABLE `spellradius`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellrange`
--
ALTER TABLE `spellrange`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellreagents`
--
ALTER TABLE `spellreagents`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellscaling`
--
ALTER TABLE `spellscaling`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellshapeshift`
--
ALTER TABLE `spellshapeshift`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellshapeshiftform`
--
ALTER TABLE `spellshapeshiftform`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spelltargetrestrictions`
--
ALTER TABLE `spelltargetrestrictions`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spelltotems`
--
ALTER TABLE `spelltotems`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `spellxspellvisual`
--
ALTER TABLE `spellxspellvisual`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `summonproperties`
--
ALTER TABLE `summonproperties`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `tactkey`
--
ALTER TABLE `tactkey`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `talent`
--
ALTER TABLE `talent`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `taxinodes`
--
ALTER TABLE `taxinodes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `taxipath`
--
ALTER TABLE `taxipath`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `taxipathnode`
--
ALTER TABLE `taxipathnode`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `totemcategory`
--
ALTER TABLE `totemcategory`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `toy`
--
ALTER TABLE `toy`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transmogholiday`
--
ALTER TABLE `transmogholiday`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transmogset`
--
ALTER TABLE `transmogset`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transmogsetgroup`
--
ALTER TABLE `transmogsetgroup`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transmogsetitem`
--
ALTER TABLE `transmogsetitem`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transportanimation`
--
ALTER TABLE `transportanimation`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transportrotation`
--
ALTER TABLE `transportrotation`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `unitpowerbar`
--
ALTER TABLE `unitpowerbar`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `vehicle`
--
ALTER TABLE `vehicle`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `vehicleseat`
--
ALTER TABLE `vehicleseat`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `wmoareatable`
--
ALTER TABLE `wmoareatable`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `worldeffect`
--
ALTER TABLE `worldeffect`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `worldmaparea`
--
ALTER TABLE `worldmaparea`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `worldmapoverlay`
--
ALTER TABLE `worldmapoverlay`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `worldmaptransforms`
--
ALTER TABLE `worldmaptransforms`
  ADD PRIMARY KEY (`ID`);
COMMIT;


/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;