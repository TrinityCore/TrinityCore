-- DB update 2021_03_14_05 -> 2021_03_14_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_14_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_14_05 2021_03_14_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615548043862503366'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615548043862503366');

-- Feegly the Exhiled should use AI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3421;

-- Change spawn position slightly
UPDATE `creature` SET `position_x`=-4217.54, `position_y`=-2341.56, `position_z`=91.75, `orientation`=1.95 WHERE `guid`=14138;

-- Make him move around a little
UPDATE `creature` SET `MovementType`=1, `wander_distance`=3 WHERE `guid`=14138;

-- Transform to a Trogg and then die
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3421,342100);
INSERT INTO `smart_scripts` VALUES
(3421,0,0,0,20,0,100,0,857,0,0,0,0,80,342100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Quest 'The Tear of the Moons' Finished - Run Script"),
(342100,9,0,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 0"),
(342100,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 1"),
(342100,9,2,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 2"),
(342100,9,3,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 3"),
(342100,9,4,0,0,0,100,0,2000,2000,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Play Emote 15"),
(342100,9,5,0,0,0,100,0,2000,2000,0,0,0,11,5142,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Cast Trogg Form"),
(342100,9,6,0,0,0,100,0,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Start Random Movement"),
(342100,9,7,0,0,0,100,0,10000,10000,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Kill Self");



--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
