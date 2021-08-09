-- DB update 2021_03_17_05 -> 2021_03_18_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_17_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_17_05 2021_03_18_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615808511621508316'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615808511621508316');

-- NPC entry: 12144 Lunaclaw Spirit. Druid quest: Body and Heart (Alliance: 6001, Horde: 6002)
SET @Spirit := 12144;
SET @menu   := 3862;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = @menu;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(@menu,0,0,'You have fought well, spirit.  I ask you to grant me the strength of your body and the strength of your heart.',7405,1,1,3863,0,0,0,'',0,0),
(@menu,1,0,'You have fought well, spirit.  I ask you to grant me the strength of your body and the strength of your heart.',7405,1,1,3863,0,0,0,'',0,0);

UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry`= @Spirit;

DELETE FROM `smart_scripts` WHERE `entryorguid`= @Spirit AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Spirit,0,0,1, 62,0,100,0,@menu,0,0,0, 72,    0,   0,0,0,0,0,7,0,0,0,0,0,0,0, 'Lunaclaw Spirit - On Gossip Option 0 Selected - Close Gossip'),
(@Spirit,0,1,2, 61,0,100,0,    0,0,0,0, 98, 3863,4715,0,0,0,0,7,0,0,0,0,0,0,0, 'Lunaclaw Spirit - On Gossip Option 0 Selected - Send Gossip'),
(@Spirit,0,2,0, 61,0,100,0,    0,0,0,0, 15, 6001,   0,0,0,0,0,7,0,0,0,0,0,0,0, "Lunaclaw Spirit - On Gossip Option 0 Selected - Credit Quest 'Body and Heart - Alliance'"),
(@Spirit,0,3,4, 62,0,100,0,@menu,1,0,0, 72,    0,   0,0,0,0,0,7,0,0,0,0,0,0,0, 'Lunaclaw Spirit - On Gossip Option 1 Selected - Close Gossip'),
(@Spirit,0,4,5, 61,0,100,0,    0,0,0,0, 98, 3863,4715,0,0,0,0,7,0,0,0,0,0,0,0, 'Lunaclaw Spirit - On Gossip Option 1 Selected - Send Gossip'),
(@Spirit,0,5,0, 61,0,100,0,    0,0,0,0, 15, 6002,   0,0,0,0,0,7,0,0,0,0,0,0,0, "Lunaclaw Spirit - On Gossip Option 1 Selected - Credit Quest 'Body and Heart - Horde'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= @menu;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@menu,0,0,1, 6,0, 469,0,0,0,0,0,'','Show gossip menu 3862 option id 0 if player is on the Alliance team. -AND-'),
(15,@menu,0,0,1,28,0,6001,0,0,1,0,0,'','Show gossip menu 3862 option id 0 if quest Body and Heart has not been completed.'),
(15,@menu,1,0,2, 6,0,  67,0,0,0,0,0,'','Show gossip menu 3862 option id 1 if player is on the Horde team. -AND-'),
(15,@menu,1,0,2,28,0,6002,0,0,1,0,0,'','Show gossip menu 3862 option id 1 if quest Body and Heart has not been completed.');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
