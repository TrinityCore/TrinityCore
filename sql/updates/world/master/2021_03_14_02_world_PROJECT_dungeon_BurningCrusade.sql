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




-- values for all difficulties
SET @MAPID          := 552;    -- mapid of dungeon
SET @CRELVL_MIN     := 25;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Arcatraz - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 25; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 25; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 25; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Arcatraz - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 269;    -- mapid of dungeon
SET @CRELVL_MIN     := 25;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Opening of the Dark Portal - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 25; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 25; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 25; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Opening of the Dark Portal - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 585;    -- mapid of dungeon
SET @CRELVL_MIN     := 25;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Magisters Terrace - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 25; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 25; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 25; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Magisters Terrace - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end





-- values for all difficulties
SET @MAPID          := 545;    -- mapid of dungeon
SET @CRELVL_MIN     := 20;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Steamvault - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 20; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 20; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Steamvault - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 554;    -- mapid of dungeon
SET @CRELVL_MIN     := 20;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Mechanar - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 20; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 20; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Mechanar - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 553;    -- mapid of dungeon
SET @CRELVL_MIN     := 20;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Botanica - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 20; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 20; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Botanica - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 540;    -- mapid of dungeon
SET @CRELVL_MIN     := 20;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Shattered Halls - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 20; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 20; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Shattered Halls - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 555;    -- mapid of dungeon
SET @CRELVL_MIN     := 20;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Shadow Labyrinth - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 20; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 20; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 20; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Shadow Labyrinth - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 560;    -- mapid of dungeon
SET @CRELVL_MIN     := 15;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Escape from Durnholde - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 15; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 15; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Escape from Durnholde - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 556;    -- mapid of dungeon
SET @CRELVL_MIN     := 15;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Sethekk Halls - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 15; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 15; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Sethekk Halls - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 557;    -- mapid of dungeon
SET @CRELVL_MIN     := 15;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Mana-Tombs - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 15; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 15; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Mana-Tombs - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end





-- values for all difficulties
SET @MAPID          := 558;    -- mapid of dungeon
SET @CRELVL_MIN     := 15;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Auchenai Crypts - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 15; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 15; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 15; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Auchenai Crypts - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 546;    -- mapid of dungeon
SET @CRELVL_MIN     := 10;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Underbog - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 10; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 10; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Underbog - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 547;    -- mapid of dungeon
SET @CRELVL_MIN     := 10;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Slave Pens - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 10; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 10; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Slave Pens - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 543;    -- mapid of dungeon
SET @CRELVL_MIN     := 10;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Hellfire Ramparts - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 10; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 10; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Hellfire Ramparts - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end




-- values for all difficulties
SET @MAPID          := 542;    -- mapid of dungeon
SET @CRELVL_MIN     := 10;     -- min lvl of creatures in all map difficulties
SET @CRELVL_MAX     := 30;     -- max lvl of creatures in all map difficulties
SET @DIFFICULTY_ALL := "1, 2"; -- all map difficulties

-- values for current difficulty
SET @MAPNAME       := "Blood Furnace - Normal"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 1;  -- current difficulty
SET @ACCLVL_MIN    := 10; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 10; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 10; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

-- values for current difficulty
SET @MAPNAME       := "Blood Furnace - Heroic"; -- name of dungeon at current difficulty
SET @DIFFICULTY    := 2;  -- current difficulty
SET @ACCLVL_MIN    := 30; -- access requirement min level for current difficulty
SET @ACCLVL_MAX    := 60; -- access requirement max level for current difficulty
SET @CRELVLDIF_MIN := 30; -- min lvl of creatures in current difficulty
SET @CRELVLDIF_MAX := 30; -- max lvl of creatures in current difficulty

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
REPLACE INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`) SELECT DISTINCT `Entry`, @DIFFICULTY AS `DifficultyID`, @CRELVLDIF_MIN AS `LevelScalingMin`, @CRELVLDIF_MAX AS `LevelScalingMax` FROM `creature_ids`;
DELETE FROM `creature_template_scaling` WHERE `Entry`=0; -- delete entry 0 that was used to initialize @ENTRIES
-- batch end

