-- DB update 2021_02_25_04 -> 2021_02_25_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_25_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_25_04 2021_02_25_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614071599270991320'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614071599270991320');

-- Create pooling for Copper Veins on Bloodmyst Isle

DELETE FROM `pool_template` WHERE `entry`=11646;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(11646,1,"Copper Veins - Bloodmyst Isle");

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE `guid` IN (120324,120325,120363);

INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(120324,11646,0,"Bloodmyst Isle, Copper Vein, spawn 1"),
(120325,11646,0,"Bloodmyst Isle, Copper Vein, spawn 2"),
(120363,11646,0,"Bloodmyst Isle, Copper Vein, spawn 3");

-- Lower respawn of veins to 1 minute
UPDATE `gameobject` SET `spawntimesecs`=60 WHERE `guid` IN (120324,120325,120363);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
