-- 
DELETE FROM `creature` WHERE `guid` IN (85786,128903);
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `unit_flags`, `MovementType`, `equipment_id`) VALUES
(85786 , 10162, 469, -7466.38281, -1041.09814, 411.97052, 2.195157, 604800, 0, 0, 768, 0, 1),
(128903, 12999, 469, -7470.248, -1035.371, 408.57, 2.155884, 300, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=12999;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3626) AND `source_type`=2 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-128903) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12890300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3626,2,6,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,128903,12999,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(-128903,0,0,0,38,0,100,1,1,1,0,0,80,12890300,0,0,0,0,0,1,0,0,0,0,0,0,0,"World Invisible Trigger - On Data set - Action_list"),
(12890300,9,1,0,0,0,100,0,3000,3000,0,0,1,14,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Action_list - Say text"),
(12890300,9,2,0,0,0,100,0,0,0,0,0,85,23642,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Action_list - Cast spell"),
(12890300,9,3,0,0,0,100,0,15000,15000,0,0,1,15,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Action_list - Say textt"),
(12890300,9,4,0,0,0,100,0,2000,2000,0,0,85,19484,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Action_list - Cast spell"),
(12890300,9,5,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Action_list - Despawn"),
(-128903,0,1,0,1,0,100,1,2000,2000,0,0,2,14,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Ooc - Set faction"),
(-128903,0,2,0,1,0,100,1,2000,2000,0,0,85,37752,0,0,0,0,0,19,10162,0,0,0,0,0,0,"World Invisible Trigger - Ooc - Cast stand");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=23642;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,23642,0,31,3,13020,0,0,'','Spell 23642 targets entry 13020');

DELETE FROM `creature_addon` WHERE `guid` IN (85786);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`visibilityDistanceType`,`auras`) VALUES
(85786,0,1,3,"");

DELETE FROM `creature_text` WHERE `CreatureID` IN (10162) AND `groupid`=15;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(10162, 15, 0, 'Get up, little red wyrm...and destroy them!', 14, 0, 100, 0, 0, 0, 9844, 'Lord Victor Nefarius');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6021;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 6021, 0, 0, 0, 29, 1, 10162, 30, 0, 1, 0, 0, '', 'Show gossip option if 10162 not spawn');
