-- DB update 2021_02_03_02 -> 2021_02_03_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_03_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_03_02 2021_02_03_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612115546205486724'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612115546205486724');

-- Add new script for flee event, also flee for assist
-- Grimscale Murloc SAI
SET @ENTRY := 15668;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,0,1,0,0,11,26661,2,0,0,0,0,1,0,0,0,0,0,0,0,"Grimscale Murloc - On Data Set 0 1 - Cast 'Fear' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grimscale Murloc - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Add entry for flee event + fix healing
-- Grimscale Oracle SAI
SET @ENTRY := 15669;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,400,40,12000,16000,11,17137,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grimscale Oracle - Friendly At 70 Health - Cast 'Flash Heal'"),
(@ENTRY,0,1,0,38,0,100,0,0,1,0,0,11,26661,3,0,0,0,0,1,0,0,0,0,0,0,0,"Grimscale Oracle - On Data Set 0 1 - Cast 'Fear' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grimscale Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Redo script
-- Mmmrrrggglll SAI
SET @ENTRY := 15937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,9000,12000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mmmrrrggglll - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,12000,16000,11,21030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mmmrrrggglll - In Combat - Cast 'Frost Shock'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,12000,15000,11,12491,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mmmrrrggglll - Between 0-50% Health - Cast 'Healing Wave'"),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,15668,0,60,0,0,0,0,"Mmmrrrggglll - On Just Died - Set Data 0 1"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,15669,0,60,0,0,0,0,"Mmmrrrggglll - On Just Died - Set Data 0 1");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
