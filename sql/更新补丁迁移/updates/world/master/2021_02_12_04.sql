-- DB update 2021_02_12_03 -> 2021_02_12_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_12_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_12_03 2021_02_12_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613075633317108993'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613075633317108993');

-- Create pooling for Battered Chests

DELETE FROM `pool_template` WHERE `entry` IN (11639,11640,11641,11642);
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(11639,1,"Battered Chests, Coldridge Valley "),
(11640,1,"Battered Chests, Elwyn Forest"),
(11641,1,"Battered Chests, Tirisfall"),
(11642,1,"Battered Chests, Shadowglen");

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE `guid` IN (85816,85817,1397,1454,26749,26756,34797,34798,85653,45106,45110,85818,85832,49528,49529);
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(85816,11639,0,"Battered Chest, Coldridge Valley, node 1"),
(85817,11639,0,"Battered Chest, Coldridge Valley, node 2"),
(1397,11639,0,"Battered Chest, Coldridge Valley, node 3"),
(1454,11639,0,"Battered Chest, Coldridge Valley, node 4"),
(26749,11640,0,"Battered Chest, Elwyn Forest, node 1"),
(26756,11640,0,"Battered Chest, Elwyn Forest, node 2"),
(34797,11640,0,"Battered Chest, Elwyn Forest, node 3"),
(34798,11640,0,"Battered Chest, Elwyn Forest, node 4"),
(85653,11640,0,"Battered Chest, Elwyn Forest, node 5"),
(45106,11641,0,"Battered Chest, Tirisfall, node 1"),
(45110,11641,0,"Battered Chest, Tirisfall, node 2"),
(85818,11641,0,"Battered Chest, Tirisfall, node 3"),
(85832,11641,0,"Battered Chest, Tirisfall, node 4"),
(49528,11642,0,"Battered Chest, Shadowglen, node 1"),
(49529,11642,0,"Battered Chest, Shadowglen, node 2");

-- Lower respawn of chests to 5 minutes
UPDATE `gameobject` SET `spawntimesecs`=300 WHERE `guid` IN (85816,85817,1397,1454,26749,26756,34797,34798,85653,45106,45110,85818,85832,49528,49529);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
