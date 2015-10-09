--
UPDATE `creature_template` SET `npcflag`=16777217, `InhabitType`=4 WHERE  `entry`=27923;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27923;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(27923,46598,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9045 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=11509 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9045 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=28 AND `ConditionTarget`=0 AND `ConditionValue1`=11509 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9045, 0, 0, 0, 8, 0, 11509, 0, 0, 0, 0, 0, '', 'Lou the Cabin Boy - Show gossip option only if player has taken quest 11509');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9045, 0, 0, 1, 28, 0, 11509, 0, 0, 0, 0, 0, '', 'Lou the Cabin Boy - Show gossip option only if player has taken quest 11509');

-- Lou the Cabin Boy SAI
SET @ENTRY := 27923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,27923,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,28,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Passenger Removed - Despawn Instant"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Just Summoned - Set Reactstate Passive"),
(@ENTRY,0,3,0,40,0,100,0,13,27923,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Waypoint 13 Reached - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=27923;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27923, 1, 556.8802, -2811.598, -0.076807, 'Lou'),
(27923, 2, 482.0306, -2834.213, -0.049029, 'Lou'),
(27923, 3, 454.4951, -2891.859, -0.049029, 'Lou'),
(27923, 4, 335.4129, -2946.441, -0.049029, 'Lou'),
(27923, 5, 262.8804, -3016.949, -0.021251, 'Lou'),
(27923, 6, 147.2193, -3176.037, -0.049029, 'Lou'),
(27923, 7, 86.28928, -3239.844, -0.021251, 'Lou'),
(27923, 8, -22.49794, -3241.448, -0.076807, 'Lou'),
(27923, 9, -151.2886, -3296.966, 0.006526, 'Lou'),
(27923, 10, -195.9667, -3366.19, -0.132362, 'Lou'),
(27923, 11, -255.5049, -3519.14, -0.021251, 'Lou'),
(27923, 12, -217.6928, -3555.593, -0.076807, 'Lou'),
(27923, 13, -201.783, -3548.484, -0.021251, 'Lou');
