-- 
DROP PROCEDURE IF EXISTS apply_if_exists_2023_04_10_00_world;

DELIMITER ;;
CREATE PROCEDURE apply_if_exists_2023_04_10_00_world() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='script_waypoint') THEN
    DELETE FROM `waypoint_data` WHERE `id` & 2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) SELECT ((s.`entry` << 3) | 2), s.`pointid`, s.`location_x`, s.`location_y`, s.`location_z`, s.`waittime` FROM `script_waypoint` s;
    
    DROP TABLE IF EXISTS `script_waypoint`;
  END IF;
END;;

DELIMITER ;
CALL apply_if_exists_2023_04_10_00_world();

DROP PROCEDURE IF EXISTS apply_if_exists_2023_04_10_00_world;

-- Rage Winterchill
SET @PATH_ID := 142138;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 4896.08, -1576.35, 1333.65),
(@PATH_ID, 1, 4898.68, -1615.02, 1329.48),
(@PATH_ID, 2, 4907.12, -1667.08, 1321.00),
(@PATH_ID, 3, 4963.18, -1699.35, 1340.51),
(@PATH_ID, 4, 4989.16, -1716.67, 1335.74),
(@PATH_ID, 5, 5026.27, -1736.89, 1323.02),
(@PATH_ID, 6, 5037.77, -1770.56, 1324.36),
(@PATH_ID, 7, 5067.23, -1789.95, 1321.17);

-- Kazrogal
SET @PATH_ID := 143106;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 5492.91, -2404.61, 1462.63),
(@PATH_ID, 1, 5531.76, -2460.87, 1469.55),
(@PATH_ID, 2, 5554.58, -2514.66, 1476.12),
(@PATH_ID, 3, 5554.16, -2567.23, 1479.90),
(@PATH_ID, 4, 5540.67, -2625.99, 1480.89),
(@PATH_ID, 5, 5508.16, -2659.20, 1480.15),
(@PATH_ID, 6, 5489.62, -2704.05, 1482.18),
(@PATH_ID, 7, 5457.04, -2726.26, 1485.10);

-- Azgalor
SET @PATH_ID := 142738;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 5492.91, -2404.61, 1462.63),
(@PATH_ID, 1, 5531.76, -2460.87, 1469.55),
(@PATH_ID, 2, 5554.58, -2514.66, 1476.12),
(@PATH_ID, 3, 5554.16, -2567.23, 1479.90),
(@PATH_ID, 4, 5540.67, -2625.99, 1480.89),
(@PATH_ID, 5, 5508.16, -2659.20, 1480.15),
(@PATH_ID, 6, 5489.62, -2704.05, 1482.18),
(@PATH_ID, 7, 5457.04, -2726.26, 1485.10);

-- Anetheron
SET @PATH_ID := 142466;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 4896.08, -1576.35, 1333.65),
(@PATH_ID, 1, 4898.68, -1615.02, 1329.48),
(@PATH_ID, 2, 4907.12, -1667.08, 1321.00),
(@PATH_ID, 3, 4963.18, -1699.35, 1340.51),
(@PATH_ID, 4, 4989.16, -1716.67, 1335.74),
(@PATH_ID, 5, 5026.27, -1736.89, 1323.02),
(@PATH_ID, 6, 5037.77, -1770.56, 1324.36),
(@PATH_ID, 7, 5067.23, -1789.95, 1321.17);

-- ------------------------------------------------------------------------------------------------

SET @MOVE_TYPE_RUN := 1;
SET @MOVE_TYPE_WALK := 0;

-- Thrall, old_hillsbrad.cpp
SET @PATHID := 143010;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` < 8;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` BETWEEN 8 AND 10;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` BETWEEN 11 AND 29;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` = 30;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` BETWEEN 31 AND 58;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point`=59;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` BETWEEN 60 AND 63;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` BETWEEN 64 AND 70;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` BETWEEN 71 AND 80;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` BETWEEN 81 AND 83;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` BETWEEN 84 AND 90;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` BETWEEN 91 AND 96;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` >= 97;

-- Magwin, zone_azuremyst_isle.cpp
SET @PATHID := 138498;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` >= 28;

-- Wizzlecrank Shredder, zone_the_barrens.cpp
SET @PATHID := 27514;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_WALK WHERE `id`=@PATHID AND `point` BETWEEN 9 AND 17;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` >= 18;

-- Brann Bronzebeard, halls_of_stone.cpp
SET @PATHID := 224562;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` >= 1;

-- Maghar Captive, zone_nagrand.cpp
SET @PATHID := 145682;
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=@PATHID AND `point` >= 16;

-- ------------------------------------------------------------------------------------------------

-- Mograine, chapter5.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=233386;

-- Scarlet Trainee, boss_herod.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=52602;

-- Anetheron, boss_anetheron.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=142466;

-- Azgalor, boss_azgalor.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=142738;

-- Kazrogal, boss_kazrogal.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=143106;

-- Rage Winterchill, boss_rage_winterchill.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=142138;

-- Legoso, zone_bloodmyst_isle.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=143858;

-- Skeletal Gryphon, boss_black_knight.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=283930;

-- Crok Scourgebane, boss_sister_svalna.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=297034;

-- Mimirons Inferno, boss_flame_leviathan.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=266962;

-- Icefang, zone_storm_peaks.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=236818;

-- Garments of quests, npcs_special.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id` IN(99386,99418,99426,99434,99442);

-- Taretha, old_hillsbrad.cpp
UPDATE `waypoint_data` SET `move_type`=@MOVE_TYPE_RUN WHERE `id`=151098;
