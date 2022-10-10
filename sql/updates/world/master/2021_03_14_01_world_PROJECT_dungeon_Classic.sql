/*
SAME MAPID CAN ONLY BE USED 1 TIME!!!
Creature level scaling is working and based on dungeon difficulty.
Max access requirement allowed level is set to 60 so we wont spoil the fun, it is stupid if player cant enter a dungeon after leveling up.

CHECK CORRECT DIFFICULTY VALUES FROM DB2:
https://wow.tools/dbc/?dbc=mapdifficulty&build=9.0.2.37176#page=1&search=2236


Modified tables and fields:

`access_requirement`            map, difficulty, lvlmin lvlmax
`creature_template`             minlevel, maxlevel
`creature_template_scaling`     difficulty, LevelScalingMin, LevelScalingMax
`creature`                      spawnDifficulties
`gameobject`                    spawnDifficulties
*/

/*
lfg teleport fixes

Dungeon id:
https://wow.tools/dbc/?dbc=lfgdungeons&build=9.0.2.37176
*/
REPLACE INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `requiredItemLevel`, `VerifiedBuild`) VALUES
('12','Stormwind Stockade','56.45','0.63','-18.90','6.25','0','0'),
('164','Scarlet Monastery','1124.64','512.466','1.00','1.59','0','0'),
('163','Scarlet Halls','824.15','607.46','13.60','6.27','0','0');




-- values for all difficulties
SET @MAPID          := 2236;  -- mapid of dungeon
SET @CRELVL_MIN     := 7;     -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 7;    -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "150"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Darkmaul Citadel Dungeon - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 150; -- current difficulty
SET @ACCLVL_MIN := 7;   -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60;  -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 109; -- mapid of dungeon
SET @CRELVL_MIN     := 20;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 20;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Sunken Temple - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 329;  -- mapid of dungeon
SET @CRELVL_MIN     := 20;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 20;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Stratholme - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 229;  -- mapid of dungeon
SET @CRELVL_MIN     := 20;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 20;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Lower Blackrock Spire - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 230;  -- mapid of dungeon
SET @CRELVL_MIN     := 20;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 20;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Blackrock Depths - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 209;  -- mapid of dungeon
SET @CRELVL_MIN     := 15;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 15;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Zul'Farrak - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end





-- values for all difficulties
SET @MAPID          := 70;  -- mapid of dungeon
SET @CRELVL_MIN     := 15;  -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 15;  -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Uldaman - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 1007; -- mapid of dungeon
SET @CRELVL_MIN     := 15;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 15;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Scholomance - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 129;  -- mapid of dungeon
SET @CRELVL_MIN     := 15;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 15;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Razorfen Downs - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 429;  -- mapid of dungeon
SET @CRELVL_MIN     := 15;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 15;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Dire Maul - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 34;   -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Stormwind Stockade - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 1004; -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Scarlet Monastery - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 1001; -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Scarlet Halls - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 47;   -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Razorfen Kraul - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 349;  -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Maraudon - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end
 



-- values for all difficulties
SET @MAPID          := 90;   -- mapid of dungeon
SET @CRELVL_MIN     := 10;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 10;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Gnomeregan - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 48;   -- mapid of dungeon
SET @CRELVL_MIN     := 9;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 9;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Blackfathom Deeps - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 8;  -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 33;   -- mapid of dungeon
SET @CRELVL_MIN     := 8;   -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 8;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Shadowfang Keep - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 8;  -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 389;  -- mapid of dungeon
SET @CRELVL_MIN     := 7;    -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 7;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Ragefire Chasm - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 7;  -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 36;   -- mapid of dungeon
SET @CRELVL_MIN     := 7;    -- min lvl of creatures in dungeon
SET @CRELVL_MAX     := 7;   -- max lvl of creatures in dungeon
SET @DIFFICULTY_ALL := "1";  -- all map difficulties

-- values for current difficulty
SET @MAPNAME    := "Deadmines - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY := 1;  -- current difficulty
SET @ACCLVL_MIN := 7;  -- access requirement min level for current difficulty
SET @ACCLVL_MAX := 60; -- access requirement max level for current difficulty

-- batch start
UPDATE `creature`   SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
UPDATE `gameobject` SET spawnDifficulties=@DIFFICULTY_ALL WHERE map=@MAPID;
DELETE FROM `access_requirement` WHERE `mapId` = @MAPID;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `comment`) VALUES
(@MAPID, @DIFFICULTY, @ACCLVL_MIN, @ACCLVL_MAX, @MAPNAME);
DROP TEMPORARY TABLE IF EXISTS `creature_ids`;
CREATE TEMPORARY TABLE IF NOT EXISTS `creature_ids` (`Entry` CHAR(255));
SET @ENTRIES := 0; -- string containing comma separated creature ids (DONT CHANGE)
UPDATE `creature_template` LEFT JOIN `creature` ON `creature_template`.`entry` = `creature`.`id` SET `creature_template`.`minlevel` = @CRELVL_MIN, `creature_template`.`maxlevel` = @CRELVL_MAX WHERE `creature`.`map` = @MAPID AND (SELECT @ENTRIES := CONCAT_WS(',', `creature_template`.`entry`, @ENTRIES));
SET @SQL = CONCAT("INSERT INTO `creature_ids` (`Entry`) VALUES ('", REPLACE(@ENTRIES, ",", "'),('"),"');");
PREPARE stmt1 FROM @SQL;
EXECUTE stmt1;
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVL_MIN AS `LevelScalingMin`, @CRELVL_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

