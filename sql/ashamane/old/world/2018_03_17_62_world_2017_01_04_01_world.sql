-- Image of Commander Ameer SAI
SET @ENTRY := 20553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Commander Ameer - On Just Created - Cast 'Simple Teleport'");

-- Image of Agent Ya-six SAI
SET @ENTRY := 20564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Agent Ya-six - On Just Created - Cast 'Simple Teleport'");

DELETE FROM `creature` WHERE `guid` IN (72679,72694);
DELETE FROM `creature_addon` WHERE `guid` IN (72679,72694);
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (20553, 20564);
UPDATE `gameobject` SET `spawntimesecs` = 1 WHERE `id` = 184434;

-- Agent Araxes SAI
SET @ENTRY := 20551;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,20551,1,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,2,20551,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,1,20551,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,4,0,17,0,100,0,20553,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Agent Araxes - On Summoned Unit - Store Targetlist"),
(@ENTRY,0,5,0,17,0,100,0,20564,0,0,0,64,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Agent Araxes - On Summoned Unit - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 2055100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.67552,"Agent Araxes - On Script - Set Orientation 1.67552"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,184434,50,0,0,0,0,0,"Agent Araxes - On Script - Activate Gameobject"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,12,20553,3,31000,0,0,0,8,0,0,0,3781.9,2175.33,142.558,4.99164,"Agent Araxes - On Script - Summon Creature 'Image of Commander Ameer'"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,0,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,1,6000,0,0,0,0,12,1,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 1"),
(@ENTRY,9,7,0,0,0,100,0,5000,5000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 2"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,12,1,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 2"),
(@ENTRY,9,9,0,0,0,100,0,6000,6000,0,0,1,3,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 3"),
(@ENTRY,9,10,0,0,0,100,0,2000,2000,0,0,32,0,0,0,0,0,0,20,184434,50,0,0,0,0,0,"Agent Araxes - On Script -  Activate Gameobject"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,12,20564,3,11000,0,0,0,8,0,0,0,3781.898,2175.332,142.5583,4.991642,"Agent Araxes - On Script - Summon Creature 'Image of Agent Ya-six'"),
(@ENTRY,9,12,0,0,0,100,0,2000,2000,0,0,1,0,5000,0,0,0,0,12,2,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 0"),
(@ENTRY,9,13,0,0,0,100,0,5000,5000,0,0,1,1,6000,0,0,0,0,12,2,0,0,0,0,0,0,"Agent Araxes - On Script - Say Line 1");

DELETE FROM `waypoints` WHERE `entry`=20551;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(20551, 1, 3782.49,2170.66,141.422, 'Agent Araxes'),
(20551, 2, 3782.49,2170.66,141.422, 'Agent Araxes');

DELETE FROM `creature_text` WHERE `CreatureID` IN (20551, 20553, 20564);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
-- Agent Araxes
(20551, 0, 0, 'I hope this damned thing works. *Araxes pounds on the portable transponder.*', 12, 0, 100, 1, 0, 0, 18256, 'Agent Araxes'),
(20551, 1, 0, 'I\'m here, commander.', 12, 0, 100, 1, 0, 0, 18267, 'Agent Araxes'),
(20551, 2, 0, 'We\'ve located the mark, commander. Ya-six and I have been separated. Requesting backup.', 12, 0, 100, 1, 0, 0, 18268, 'Agent Araxes'),
-- Image of Commander Ameer
(20553, 0, 0, 'Araxes, come in... Are you there Araxes? Visibility is nil. Warp storms blocking us.', 12, 0, 100, 1, 0, 0, 18249, 'Image of Commander Ameer'),
(20553, 1, 0, 'Copy. Status report, soldier.', 12, 0, 100, 1, 0, 0, 18250, 'Image of Commander Ameer'),
(20553, 2, 0, 'Copy that, Araxes. Backup is on the way. Hold your position. I repeat, hold your position.', 12, 0, 100, 1, 0, 0, 18269, 'Image of Commander Ameer'),
(20553, 3, 0, 'Ameer, over and out.', 12, 0, 100, 1, 0, 0, 18270, 'Image of Commander Ameer'),
-- Image of Agent Ya-six
(20564, 0, 0, 'Araxes! Send help! I\'m pinned down in the mines. I... I\'m not sure where I am exactly but I had the presence of mind to drop tracers on the ground behind me.', 12, 0, 100, 1, 0, 0, 18281, 'Image of Agent Ya-six'),
(20564, 1, 0, 'I can\'t follow the tracers back out, too many flesh beasts in the way. Send someone in... Follow the tracers... Ya-six, out.', 12, 0, 100, 1, 0, 0, 18282, 'Image of Agent Ya-six');
