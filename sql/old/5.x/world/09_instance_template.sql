DELETE FROM `instance_template` WHERE `map` IN (
999, 1000, 1005, 1014, 1024, 1028, 1029, 1030, 1031, 1035, 1048, 1049, 1050, 1051, 1095,
1099, 1102, 1103, 1104, 1112, 1122, 1123, 1124, 1125, 1126, 1127, 1130, 1131, 1135, 1144,
1148, 1155, 1157, 1161, 1008, 1009, 1098, 1136, 996, 995, 1001, 1004, 1007, 1011, 1032,
959, 960, 961, 962, 977, 994);

INSERT INTO `instance_template` VALUES
-- scenarios
('999', '0', '', '0'),  -- BFTAllianceScenario
('1000', '0', '', '0'), -- BFTHordeScenario
('1005', '0', '', '0'), -- BrewmasterScenario01
('1014', '0', '', '0'), -- MonkAreaScenario
('1024', '0', '', '0'), -- PandaFishingVillageScenario
('1028', '0', '', '0'), -- MoguRuinsScenario
('1029', '0', '', '0'), -- AncientMoguCryptScenario
('1030', '0', '', '0'), -- AncientMoguCyptDestroyedScenario
('1031', '0', '', '0'), -- ProvingGroundsScenario
('1035', '0', '', '0'), -- ValleyOfPowerScenario
('1048', '0', '', '0'), -- BrewmasterScenario03
('1049', '0', '', '0'), -- BlackOxTempleScenario
('1050', '0', '', '0'), -- ScenarioKlaxxiIsland
('1051', '0', '', '0'), -- ScenarioBrewmaster04
('1095', '0', '', '0'), -- HordeAmbushScenario
('1099', '0', '', '0'), -- NavalBattleScenario
('1102', '0', '', '0'), -- HordeBaseBeachScenario
('1103', '0', '', '0'), -- AllianceBaseBeachScenario
('1104', '0', '', '0'), -- ALittlePatienceScenario
('1112', '0', '', '0'), -- BlackTempleScenario
('1122', '0', '', '0'), -- CitySiegeMoguIslandProgressionScenario
('1123', '0', '', '0'), -- LightningForgeMoguIslandProgressionScenario
('1124', '0', '', '0'), -- ShipyardMoguIslandProgressionScenario
('1125', '0', '', '0'), -- AllianceHubMoguIslandProgressionScenario
('1126', '0', '', '0'), -- HordeHubMoguIslandProgressionScenario
('1127', '0', '', '0'), -- FinalGateMoguIslandProgressionScenario
('1130', '0', '', '0'), -- ShimmerRidgeScenario
('1131', '0', '', '0'), -- DarkHordeScenario
('1135', '0', '', '0'), -- MoguIslandLootRoom
('1144', '0', '', '0'), -- HeartOfTheOldGodScenario
('1148', '0', '', '0'), -- ProvingGrounds
('1155', '0', '', '0'), -- Stormgarde Keep
('1157', '0', '', '0'), -- HalfhillScenario
('1161', '0', '', '0'), -- CelestialChallenge
-- raids
('1008', '0', '', '0'), -- MogushanPalace
('1009', '0', '', '0'), -- MantidRaid
('1098', '0', '', '0'), -- ThunderIslandRaid
('1136', '0', '', '0'), -- OrgrimmarRaid
('996', '0', '', '0'), -- MoguExteriorRaid
('995', '0', '', '0'), -- MoguInteriorRaid
-- dungeons
('1001', '0', '', '0'), -- ScarletSanctuaryArmoryAndLibrary
('1004', '0', '', '0'), -- ScarletMonasteryCathedralGY
('1007', '0', '', '0'), -- NewScholomance
('1011', '0', '', '0'), -- MantidDungeon
('1032', '0', '', '0'), -- PetBattleJadeForest
('959', '0', '', '0'), -- ShadowpanHideout
('960', '0', '', '0'), -- EastTemple
('961', '0', '', '0'), -- StormstoutBrewery
('962', '0', '', '0'), -- TheGreatWall
('977', '0', '', '0'), -- MaelstromDeathwingFight
('994', '0', '', '0'); -- MoguDungeon