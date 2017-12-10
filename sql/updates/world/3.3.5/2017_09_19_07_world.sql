-- Completion event for quest "Raene's Cleansing (Part 5)"
DELETE FROM `creature_text` WHERE `CreatureID`=3916;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3916,0,0,"The rod\'s design is simple. Dartol didn\'t use his arcane knowledge in its creation... it is more druidic in nature.",12,7,100,0,0,0,1380,0,"Shael\'dryn"),
(3916,1,0,"Hehe... I made a pun, didn\'t I? Druidic in nature... I\'m so funny.",12,7,100,0,0,0,1381,0,"Shael\'dryn"),
(3916,2,0,"Now, then... the rod. Let\'s see about putting it back together, shall we?",12,7,100,0,0,0,1382,0,"Shael\'dryn"),
(3916,3,0,"There! That wasn\'t too bad. What did you say you and Raene were going to do with this thing? It\'s powerful!",12,7,100,0,0,0,1383,0,"Shael\'dryn");

UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=2 WHERE `entry`=3916;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3916 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3916,0,0,0,20,0,100,0,1027,0,0,0,80,391600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Quest \'Raene\'s Cleansing (Part 5)\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=391600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(391600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Remove Npc Flag Questgiver"),
(391600,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Say Line 0"),
(391600,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Say Line 1"),
(391600,9,3,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Say Line 2"),
(391600,9,4,0,0,0,100,0,3000,3000,0,0,11,8736,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Cast Conjure Food"),
(391600,9,5,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Say Line 3"),
(391600,9,6,0,0,0,100,0,4000,4000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shael\'dryn - On Script - Add Npc Flag Questgiver");
