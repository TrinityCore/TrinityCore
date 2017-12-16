-- [NPC][WotlK] Library Guardian and Databank, missing spell, wrong movement 
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=29746;
UPDATE `creature` SET `spawndist`=18 WHERE  `id`=29724 AND `spawndist` >0;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `id`=29746;

-- Library Guardian SAI
SET @ENTRY := 29724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,45000,60000,60000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - Out of Combat - Run Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Aggro - Set Rooted Off");

-- Actionlist SAI
SET @ENTRY := 2972400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,1,0,0,0,0,0,19,29746,25,0,0,0,0,0,"Library Guardian - On Script - Set Orientation Closest Creature 'Databank'"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Script - Set Rooted On"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,1300,1300,0,0,11,55134,0,0,0,0,0,19,29746,25,0,0,0,0,0,"Library Guardian - On Script - Cast 'Data Stream'"),
(@ENTRY,9,5,0,0,0,100,0,12000,12000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Script - Set Rooted Off"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Library Guardian - On Script - Set Active Off");

-- Conditions for spellcast and sai execution
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=29724;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,29724,0,0,29,1,29746,25,0,0,0,0,"","Library Guardian - Run SAI near Creature 'Databank'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=55134;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 55134, 0, 0, 31, 0, 3, 29746, 0, 0, 0, 0, '', 'Data Strea only targets Creature Databank');

DELETE FROM `creature_text` WHERE `entry`=29724;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(29724, 0, 0, 'Defragmenting swap file ...', 12, 0, 100, 1, 0, 0, 30375, 'Library Guardian'),
(29724, 0, 1, 'Running a level three diagnostic ...', 12, 0, 100, 1, 0, 0, 30374, 'Library Guardian'),
(29724, 0, 2, 'Attempting to restore lost data ...', 12, 0, 100, 1, 0, 0, 30377, 'Library Guardian'),
(29724, 0, 3, 'Implementing new security protocols ...', 12, 0, 100, 1, 0, 0, 30378, 'Library Guardian'),
(29724, 0, 4, 'Verifying encryption key ...', 12, 0, 100, 1, 0, 0, 30376, 'Library Guardian'),
(29724, 0, 5, 'Assessing database integrity ...', 12, 0, 100, 1, 0, 0, 30373, 'Library Guardian');
