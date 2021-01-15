-- Northwatch Foothold
-- Lar must kneel
DELETE FROM `creature_template_addon` WHERE `entry`=3140;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(3140,0,0,8,1,0, '');

-- Infataryman
-- attackemote
DELETE FROM `creature_addon` WHERE `guid` IN (309448,309459,309441,309447,309438,309424,309436,309428,309424,309440);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(309448,0,0,0,1,27, ''),
(309459,0,0,0,1,27, ''),
-- handleemote
(309441,0,0,0,1,69, ''),
(309447,0,0,0,1,69, ''),
(309438,0,0,0,1,69, ''),
-- sitting
(309436,0,0,1,1,0, ''),
(309428,0,0,1,1,0, ''),
(309424,0,0,1,1,0, ''),
(309440,0,0,1,1,0, '');

-- Clattering Scorpid SAI
SET @ENTRY := 3125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,32000,38000,11,79687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast 'Sundering Cleave'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,15000,11,73672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - Between 0-30% Health - Cast 'Envenom'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,15000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clattering Scorpid - Between 0-30% Health - Say 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=3125;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,3125,0,0,9,0,25165,0,0,0,"","Clattering Scorpid - Only enable text if quest 'Never Trust a Big Barb and a Smile' is active");

DELETE FROM `creature_text` WHERE `entry`=3125;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(3125, 0, 0, '%s is casting Envenom!  Place your totem down now!', 42, 0, 100, 0, 0, 0, 39298, 'Clattering Scorpid to Player');

UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=1 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=2 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=3 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=4 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=5 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue1`=25165 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3062 AND `SourceEntry`=6 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=826 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
