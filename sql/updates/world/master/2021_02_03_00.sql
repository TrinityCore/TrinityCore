-- DB update 2021_02_02_01 -> 2021_02_03_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_02_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_02_01 2021_02_03_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612094222775369000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612094222775369000');

-- Delete duplicate
DELETE FROM `gossip_menu_option` WHERE `menuid` = 6918 AND `optionid` = 1;

-- Conditions for gossip_menu_option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6918;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,6918,0,0,0,8,0,8867,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'Lunar Fireworks' is rewarded"),
(15,6918,0,0,0,2,0,21711,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Lunar Festival Invitation'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 15895;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15895 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15895,0,0,1,62,0,100,0,6918,0,0,0,0,11,26375,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lunar Festival Harbinger - On Gossip Option 0 Selected - Cast 'Create Lunar Festival Invitation'"),
(15895,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lunar Festival Harbinger - On Link - Close Gossip");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
