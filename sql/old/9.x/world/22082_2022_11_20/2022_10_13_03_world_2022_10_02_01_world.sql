-- *** Quest "Aces High!" ***
-- Condition for source Gossip menu condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10204 AND `SourceEntry` IN (14169,14170) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 10204, 14169, 0, 0, 9, 0, 13413, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 text id 14169 if quest Aces High! has been taken.'),
(14, 10204, 14170, 0, 0, 9, 0, 13414, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 text id 14170 if quest Aces High! "Daily" has been taken.');

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10204 AND `SourceEntry` IN (0,1) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10204, 0, 0, 0, 9, 0, 13413, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 option id 0 if quest Aces High! has been taken.'),
(15, 10204, 1, 0, 0, 9, 0, 13414, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 option id 1 if quest Aces High! "Daily" has been taken.');

-- Corastrasza SAI
SET @ENTRY := 32548;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,62,0,100,0,10204,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select 0 - Close Gossip for player"),
(@ENTRY,0,1,2,62,0,100,0,10204,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select 1 - Close Gossip for player"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,85,61240,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select - Player Cast 'Summon Wyrmrest Skytalon' on self"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,85,61244,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select - Player Cast 'Wyrmrest Skytalon Ride Periodic' on self");
