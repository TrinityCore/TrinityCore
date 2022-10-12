-- DB update 2021_02_25_03 -> 2021_02_25_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_25_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_25_03 2021_02_25_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614069921307272588'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614069921307272588');

-- Create pooling for Copper Veins in Eversong Woods

DELETE FROM `pool_template` WHERE `entry`=11644;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(11644,30,"Copper Vein - Eversong Woods");

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE `guid` IN (74930,74931,74932,74933,74934,74935,74936,74937,74938,74939,74940,74941,74942,74943,74944,74945,74946,74947,74948,74949,74950,74951,74952,74953,74954,74955,74956,74957,74958,74959,74960,74961,74962,74963,74964,74965,74966,74967,74968,74969,74970,74971,74972,74973,74974,74975,74976,74977,74978,74979,74980,74981,74982,74983,74984,74985,74986,74987,120618);

INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(74930,11644,0,"Eversong Woods, Copper Vein, spawn 1"),
(74931,11644,0,"Eversong Woods, Copper Vein, spawn 2"),
(74932,11644,0,"Eversong Woods, Copper Vein, spawn 3"),
(74933,11644,0,"Eversong Woods, Copper Vein, spawn 4"),
(74934,11644,0,"Eversong Woods, Copper Vein, spawn 5"),
(74935,11644,0,"Eversong Woods, Copper Vein, spawn 6"),
(74936,11644,0,"Eversong Woods, Copper Vein, spawn 7"),
(74937,11644,0,"Eversong Woods, Copper Vein, spawn 8"),
(74938,11644,0,"Eversong Woods, Copper Vein, spawn 9"),
(74939,11644,0,"Eversong Woods, Copper Vein, spawn 10"),
(74940,11644,0,"Eversong Woods, Copper Vein, spawn 11"),
(74941,11644,0,"Eversong Woods, Copper Vein, spawn 12"),
(74942,11644,0,"Eversong Woods, Copper Vein, spawn 13"),
(74943,11644,0,"Eversong Woods, Copper Vein, spawn 14"),
(74944,11644,0,"Eversong Woods, Copper Vein, spawn 15"),
(74945,11644,0,"Eversong Woods, Copper Vein, spawn 16"),
(74946,11644,0,"Eversong Woods, Copper Vein, spawn 17"),
(74947,11644,0,"Eversong Woods, Copper Vein, spawn 18"),
(74948,11644,0,"Eversong Woods, Copper Vein, spawn 19"),
(74949,11644,0,"Eversong Woods, Copper Vein, spawn 20"),
(74950,11644,0,"Eversong Woods, Copper Vein, spawn 21"),
(74951,11644,0,"Eversong Woods, Copper Vein, spawn 22"),
(74952,11644,0,"Eversong Woods, Copper Vein, spawn 23"),
(74953,11644,0,"Eversong Woods, Copper Vein, spawn 24"),
(74954,11644,0,"Eversong Woods, Copper Vein, spawn 25"),
(74955,11644,0,"Eversong Woods, Copper Vein, spawn 26"),
(74956,11644,0,"Eversong Woods, Copper Vein, spawn 27"),
(74957,11644,0,"Eversong Woods, Copper Vein, spawn 28"),
(74958,11644,0,"Eversong Woods, Copper Vein, spawn 29"),
(74959,11644,0,"Eversong Woods, Copper Vein, spawn 30"),
(74960,11644,0,"Eversong Woods, Copper Vein, spawn 31"),
(74961,11644,0,"Eversong Woods, Copper Vein, spawn 32"),
(74962,11644,0,"Eversong Woods, Copper Vein, spawn 33"),
(74963,11644,0,"Eversong Woods, Copper Vein, spawn 34"),
(74964,11644,0,"Eversong Woods, Copper Vein, spawn 35"),
(74965,11644,0,"Eversong Woods, Copper Vein, spawn 36"),
(74966,11644,0,"Eversong Woods, Copper Vein, spawn 37"),
(74967,11644,0,"Eversong Woods, Copper Vein, spawn 38"),
(74968,11644,0,"Eversong Woods, Copper Vein, spawn 39"),
(74969,11644,0,"Eversong Woods, Copper Vein, spawn 40"),
(74970,11644,0,"Eversong Woods, Copper Vein, spawn 41"),
(74971,11644,0,"Eversong Woods, Copper Vein, spawn 42"),
(74972,11644,0,"Eversong Woods, Copper Vein, spawn 43"),
(74973,11644,0,"Eversong Woods, Copper Vein, spawn 44"),
(74974,11644,0,"Eversong Woods, Copper Vein, spawn 45"),
(74975,11644,0,"Eversong Woods, Copper Vein, spawn 46"),
(74976,11644,0,"Eversong Woods, Copper Vein, spawn 47"),
(74977,11644,0,"Eversong Woods, Copper Vein, spawn 48"),
(74978,11644,0,"Eversong Woods, Copper Vein, spawn 49"),
(74979,11644,0,"Eversong Woods, Copper Vein, spawn 50"),
(74980,11644,0,"Eversong Woods, Copper Vein, spawn 51"),
(74981,11644,0,"Eversong Woods, Copper Vein, spawn 52"),
(74982,11644,0,"Eversong Woods, Copper Vein, spawn 53"),
(74983,11644,0,"Eversong Woods, Copper Vein, spawn 54"),
(74984,11644,0,"Eversong Woods, Copper Vein, spawn 55"),
(74985,11644,0,"Eversong Woods, Copper Vein, spawn 56"),
(74986,11644,0,"Eversong Woods, Copper Vein, spawn 57"),
(74987,11644,0,"Eversong Woods, Copper Vein, spawn 58"),
(120618,11644,0,"Eversong Woods, Copper Vein, spawn 59");

-- Lower respawn of veins to 1 minute
UPDATE `gameobject` SET `spawntimesecs`=60 WHERE `guid` IN (74930,74931,74932,74933,74934,74935,74936,74937,74938,74939,74940,74941,74942,74943,74944,74945,74946,74947,74948,74949,74950,74951,74952,74953,74954,74955,74956,74957,74958,74959,74960,74961,74962,74963,74964,74965,74966,74967,74968,74969,74970,74971,74972,74973,74974,74975,74976,74977,74978,74979,74980,74981,74982,74983,74984,74985,74986,74987,120618);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
