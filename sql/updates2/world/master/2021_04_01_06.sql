-- DB update 2021_04_01_05 -> 2021_04_01_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_05 2021_04_01_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616884299081820400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616884299081820400');

-- Updated gossip_menu for Doctor Gregory Victor <Trauma Surgeon> 
UPDATE `creature_template` SET `gossip_menu_id`=5381 WHERE  `entry`=12920;

-- Condition for gossip before and after quest completion
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` = 5381);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 5381, 6573, 0, 0, 8, 0, 6622, 0, 0, 0, 0, 0, '', ''),
(14, 5381, 6413, 0, 0, 47, 0, 6622, 27, 0, 0, 0, 0, '', '');

-- Condition for gossip before and after quest completion
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` = 5382);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 5382, 6414, 0, 0, 8, 0, 6624, 0, 0, 0, 0, 0, '', ''),
(14, 5382, 6415, 0, 0, 47, 0, 6624, 27, 0, 0, 0, 0, '', '');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
