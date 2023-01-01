-- Remove not confirmed by https://youtu.be/kh0Yyy6ov_Y?list=PLRg2QJ-bO2wlxphJqhxb56AENsxSRud1L&t=7598 actions
-- Captured Rabid Thistle Bear does not change the faction back to 14 after player turns in the quest
-- Tharnariun Treetender does not change NPC flags after player turns in the quest
-- Other changes requires better source
-- Revert faction change for Captured Rabid Thistle Bear, better to change it in script
UPDATE `creature_template` SET `faction` = 14 WHERE `entry` = 11836;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2164 AND `source_type` = 0 AND `id` BETWEEN 3 AND 7;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 216400 AND `source_type` = 9 AND `id` = 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 370100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(216400,9,5,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rabid Thistle Bear - On Script - Set Faction 35"),

(370100,9,0,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,19,11836,0,0,0,0,0,0,0,"Tharnariun Treetender - On Script - Set Orientation Closest Creature 'Captured Rabid Thistle Bear'"),
(370100,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tharnariun Treetender - On Script - Say Line 0"),
(370100,9,2,0,0,0,100,0,2000,2000,0,0,0,11,9457,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tharnariun Treetender - On Script - Cast 'Tharnariun's Heal'"),
(370100,9,3,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,19,11836,0,0,0,0,0,0,0,"Tharnariun Treetender - On Script - Despawn (0) (Captured Rabid Thistle Bear)"),
(370100,9,4,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tharnariun Treetender - On Script - Set Orientation Home Position");
