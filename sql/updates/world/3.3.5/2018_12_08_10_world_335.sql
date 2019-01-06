-- Curator Thorius
DELETE FROM `creature_text` WHERE `CreatureID`=8256;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8256,0,0,"Poor Dorius. If I ever get my hands on those Dark Irons, so help me...",12,7,100,0,0,0,4287,0,"Curator Thorius"),
(8256,1,0,"I have just the spot for this horn!",12,0,100,0,0,0,4305,0,"Curator Thorius"),
(8256,2,0,"I've been saving this spot for something special. I don't think it gets any more special than this, $n.",12,0,100,25,0,0,4306,0,"Curator Thorius"),
(8256,3,0,"There we go. All done!",12,0,100,0,0,0,4307,0,"Curator Thorius");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8256;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8256 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (825600,825601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8256,0,0,0,20,0,100,0,3368,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Quest 'Suntara Stones (Part 2)' Finished - Say Line 0"),
(8256,0,1,0,20,0,100,0,3182,0,0,0,80,825600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Quest 'Proof of Deed' Finished - Run Script"),
(8256,0,2,0,40,0,100,0,2,8256,0,0,80,825601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Waypoint 2 Reached - Run Script"),
(8256,0,3,0,58,0,100,0,0,8256,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Waypoint Ended - Evade"),
(825600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Remove Npc Flag Questgiver"),
(825600,9,1,0,0,0,100,0,0,0,0,0,53,0,8256,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Start Waypoint"),
(825600,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Say Line 1"),
(825601,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Say Line 2"),
(825601,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.35796,"Curator Thorius - On Script - Set Orientation"),
(825601,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Say Line 2"),
(825601,9,3,0,0,0,100,0,5000,5000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Set Flag Standstate Kneel"),
(825601,9,4,0,0,0,100,0,2000,2000,0,0,50,147136,300,0,0,0,0,8,0,0,0,-4656.99,-1306,503.383,2.1903,"Curator Thorius - On Script - Summon Gameobject 'Horn of Margol the Rager'"),
(825601,9,5,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Curator Thorius - On Script - Say Line 3"),
(825601,9,6,0,0,0,100,0,3000,3000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Remove Flag Standstate Kneel"),
(825601,9,7,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Thorius - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=8256;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(8256,1,-4660.97,-1300.37,503.383,""),
(8256,2,-4657.86,-1304.74,503.381,""),
(8256,3,-4662.04,-1298.12,503.382,""),
(8256,4,-4659.43,-1288.83,503.382,""),
(8256,5,-4654.31,-1281.54,503.382,"");

UPDATE `waypoint_data` SET `action`=0 WHERE `id`=18870 AND `point`=16;
DELETE FROM `waypoint_scripts` WHERE `id`=188702;
