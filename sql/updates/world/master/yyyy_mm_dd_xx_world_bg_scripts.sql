DROP TABLE IF EXISTS `battleground_scripts`;
CREATE TABLE `battleground_scripts` (
  `MapId` int NOT NULL,
  `BattlemasterListId` int NOT NULL DEFAULT '0',
  `ScriptName` varchar(64) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`MapId`,`BattlemasterListId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(30, 0, 'battleground_alterac_valley'),
(566, 0, 'battleground_eye_of_the_storm'),
(607, 0, 'battleground_strand_of_the_ancients'),
(628, 0, 'battleground_isle_of_conquest'),
(2106, 0, 'battleground_warsong_gulch'),
(2107, 0, 'battleground_arathi_basin'),
(1672, 0, 'arena_blades_edge'),
(572, 0, 'arena_ruins_of_lordaeron'),
(617, 0, 'arena_dalaran_sewers'),
(1505, 0, 'arena_nagrand'),
(618, 0, 'arena_ring_of_valor'),
(726, 0, 'battleground_twin_peaks'),
(761, 0, 'battleground_battle_for_gilneas');

DELETE FROM `quest_template_addon` WHERE `ID` IN (7223, 7224);
INSERT INTO `quest_template_addon` (`ID`, `ScriptName`) VALUES
(7223, 'quest_alterac_valley_armor_scraps'),
(7224, 'quest_alterac_valley_armor_scraps');

UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_armor_scraps' WHERE `ID` IN (6781, 6741);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_call_of_air_slidore_guse' WHERE `ID` IN (6942, 6825);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_call_of_air_vipore_jeztor' WHERE `ID` IN (6941, 6826);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_call_of_air_ichman_mulverick' WHERE `ID` IN (6943, 6827);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_boss_5' WHERE `ID` IN (7386, 7385);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_boss_1' WHERE `ID` IN (6881, 6801);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_near_mine' WHERE `ID` IN (5892, 5893);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_other_mine' WHERE `ID` IN (6982, 6985);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_ram_harnesses' WHERE `ID` IN (7026, 7002);
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_alterac_valley_empty_stables' WHERE `ID` IN (7027, 7001);
