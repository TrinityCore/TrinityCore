-- DB update 2021_03_18_03 -> 2021_03_18_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_18_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_18_03 2021_03_18_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615669234362948639'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615669234362948639');

-- Create pooling for Azshara Solid Chests
DELETE FROM `pool_template` WHERE `entry` = 11650;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(11650,2,"Solid Chests, Azshara");

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE `guid` IN
(48362, 48363, 48364, 48365, 48366, 48367, 48368, 48369, 48370, 48371);
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(48362,11650,0,"Solid Chest, Azshara, node 1"),
(48363,11650,0,"Solid Chest, Azshara, node 2"),
(48364,11650,0,"Solid Chest, Azshara, node 3"),
(48365,11650,0,"Solid Chest, Azshara, node 4"),
(48366,11650,0,"Solid Chest, Azshara, node 5"),
(48367,11650,0,"Solid Chest, Azshara, node 6"),
(48368,11650,0,"Solid Chest, Azshara, node 7"),
(48369,11650,0,"Solid Chest, Azshara, node 8"),
(48370,11650,0,"Solid Chest, Azshara, node 9"),
(48371,11650,0,"Solid Chest, Azshara, node 10");

-- Lower respawn of chests to 10 minutes
UPDATE `gameobject` SET `spawntimesecs` = 600 WHERE `guid` IN
(48362, 48363,48364, 48365, 48366, 48367, 48368, 48369, 48370, 48371);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
