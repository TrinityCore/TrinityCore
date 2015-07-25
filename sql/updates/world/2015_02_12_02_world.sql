--
UPDATE `creature` SET `position_x`=1695.631592, `position_y`=1680.963135, `position_z`=134.870605, `orientation`=2.953877 WHERE  `guid`=325130;

-- Risen Recruit SAI
SET @ENTRY := 50414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,53,0,50414,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Reset - Start Waypoint (No Repeat)"),
(@ENTRY,0,1,0,40,0,100,0,1,50414,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Waypoint 1 Reached - Run Script");

DELETE FROM `creature_text` WHERE `entry` IN (1568, 50414);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1568, 0, 0, 'Let\'s see, I just saw a corpse with a jaw that would fit you', 12, 0, 100, 0, 0, 0, 0, 0, 'Mordo'),
(1568, 1, 0, 'That should do the job. Come back right away if it falls off again.', 12, 0, 100, 0, 0, 0, 0, 0, 'Mordo'),
(50414, 0, 0, 'T-thank you, Under-t-taker.', 12, 0, 100, 0, 0, 0, 0, 0, 'Risen Recruit');

-- Actionlist SAI
SET @ENTRY := 5041400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Script - Play Emote 16"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,5,69,0,0,0,0,0,19,1568,10,0,0,0,0,0,"Risen Recruit - On Script - Play Emote 69"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,1568,10,0,0,0,0,0,"Risen Recruit - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,5,26,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Play Emote 26"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Play Emote 25"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 26"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 66"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,53,0,504140,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint"),
(@ENTRY,9,10,0,0,0,100,0,6000,6000,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn In 2000 ms");

DELETE FROM `waypoints` WHERE `entry` IN (50414, 504140);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(50414, 1, 1691.527100, 1675.772339, 135.228180, 'Risen Recruit'),
(504140, 1, 1700.930054, 1655.510010, 129.171005, 'Risen Recruit');
