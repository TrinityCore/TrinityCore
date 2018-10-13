/*
-- 
DELETE FROM `creature` WHERE `guid` IN (88735,88736,88737,88738,88739,88740,88741,88742,88743,88744,88745);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(88735, 4392, 1, 1, 1, 0, 0, -4077, -3346, 30.845, 3.84, 600, 4, 1),
(88736, 4392, 1, 1, 1, 0, 0, -4085, -3298, 40.598, 1.345, 600, 9, 1),
(88737, 4392, 1, 1, 1, 0, 0, -4054, -3817, 40.882, 5.002, 600, 7, 1),
(88738, 4392, 1, 1, 1, 0, 0, -3995, -3760, 38.655, 4.329, 600, 7, 1),
(88739, 4392, 1, 1, 1, 0, 0, -3984, -3561, 40.577, 6.002, 600, 7, 1),
(88740, 4392, 1, 1, 1, 0, 0, -3955, -3334, 37.5, 3.875, 600, 9, 1),
(88741, 4392, 1, 1, 1, 0, 0, -3946, -3835, 36.777, 0.584, 600, 7, 1),
(88742, 4392, 1, 1, 1, 0, 0, -3945, -3695, 42.312, 1.238, 600, 7, 1),
(88743, 4392, 1, 1, 1, 0, 0, -3887, -3773, 37.275, 4.881, 600, 7, 1),
(88744, 4392, 1, 1, 1, 0, 0, -3843, -3475, 35.403, 2.416, 600, 7, 1),
(88745, 4392, 1, 1, 1, 0, 0, -3793, -3651, 37.177, 4.527, 600, 7, 1);
 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4392;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4392 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4392,0,0,0,2,0,100,1,0,15,0,0,0,11,9461,2,0,0,0,0,1,0,0,0,0,0,0,0,"Corrosive Swamp Ooze - Between 0-15% Health - Cast Summon Swamp Ooze");

DELETE FROM `creature_template_addon` WHERE `entry` IN (4392,4391);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(4391,"9460"),
(4392,"9460");
*/
