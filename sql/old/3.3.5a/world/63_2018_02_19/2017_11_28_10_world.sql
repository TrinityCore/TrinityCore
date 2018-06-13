-- Kravel Koalbeard
DELETE FROM `creature_text` WHERE `CreatureID`=4452 AND `GroupID` IN (3,4,5);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4452,3,0,"This stout sure smells strong!",12,0,100,0,0,0,1489,0,"Kravel Koalbeard"),
(4452,4,0,"Let's have just a small taste...",12,0,100,7,0,0,1491,0,"Kravel Koalbeard"),
(4452,5,0,"Wait!  What am I thinking!  We have a job to do with this stuff.",12,0,100,5,0,0,1492,0,"Kravel Koalbeard");

DELETE FROM `smart_scripts` WHERE `entryorguid`=4452 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=445201 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4452,0,1,0,20,0,100,0,1119,0,0,0,80,445201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Quest 'Zanzil's Mixture and a Fool's Stout' Finished - Run Script"),
(445201,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Remove Npc Flag Questgiver"),
(445201,9,1,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 3"),
(445201,9,2,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 4"),
(445201,9,3,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 5"),
(445201,9,4,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Add Npc Flag Questgiver");
