-- Quest "The Annals of Darrowshire" --> Add Completion Event
DELETE FROM `creature_text` WHERE `CreatureID`=10667;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10667,0,0,"Let's find out the whole story.  That's going to take some magic...",12,0,100,1,0,0,6418,0,"Chromie"),
(10667,1,0,"There, it is done.  The book has been enhanced...",12,0,100,0,0,0,6419,0,"Chromie");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10667;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10667 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1066700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10667,0,0,0,20,0,100,0,5154,0,0,0,80,1066700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromie - On Quest \'The Annals of Darrowshire\' Finished - Run Script"),
(1066700,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromie - On Script - Remove Npc Flag Questgiver+Gossip"),
(1066700,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Chromie - On Script - Say Line 0"),
(1066700,9,2,0,0,0,100,0,5000,5000,0,0,11,17285,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromie - On Script - Cast Enchant Annals of Darrowshire"),
(1066700,9,3,0,0,0,100,0,4500,4500,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Chromie - On Script - Say Line 1"),
(1066700,9,4,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromie - On Script - Add Npc Flag Questgiver+Gossip");
