-- Calia Hastings
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=23566; -- She didn't have a gossip text in WotLK. Current text was added in Cata when she became a rogue trainer.

DELETE FROM `creature_text` WHERE `CreatureID`=23566;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23566,0,0,"It would be a shame to let these leaflets go to waste, wouldn't it?",12,7,100,0,0,0,22105,0,"Calia Hastings"),
(23566,1,0,"With just a little creative editing, these are much more useful...",12,7,100,0,0,0,22107,0,"Calia Hastings");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23566;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23566 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2356600,2356601,2356602) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23566,0,0,0,20,0,100,0,11128,0,0,0,80,2356600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Quest 'Propaganda War' Finished - Run Script"),
(23566,0,1,0,40,0,100,0,3,23566,0,0,80,2356601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Waypoint 3 Reached - Run Script"),
(23566,0,2,0,40,0,100,0,7,23566,0,0,80,2356602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Waypoint 7 Reached - Run Script"),
(2356600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Remove Npc Flag Questgiver"),
(2356600,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Say Line 0"),
(2356600,9,2,0,0,0,100,0,5000,5000,0,0,53,0,23566,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Start Waypoint"),
(2356601,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Pause Waypoint"),
(2356601,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.27885,"Calia Hastings - On Script - Set Orientation"),
(2356601,9,2,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Set Emote State 69"),
(2356601,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Set Emote State 0"),
(2356602,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.40855,"Calia Hastings - On Script - Set Orientation"),
(2356602,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Say Line 1"),
(2356602,9,2,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Calia Hastings - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=23566;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(23566,1,-3818.89,-4564.21,8.92453,""),
(23566,2,-3817,-4566.21,8.84672,""),
(23566,3,-3816.71,-4564.26,8.97426,""),
(23566,4,-3817,-4566.21,8.84672,""),
(23566,5,-3818.89,-4564.21,8.92453,""),
(23566,6,-3817.87,-4561.44,9.11807,""),
(23566,7,-3819.74,-4562.35,9.14216,"");
