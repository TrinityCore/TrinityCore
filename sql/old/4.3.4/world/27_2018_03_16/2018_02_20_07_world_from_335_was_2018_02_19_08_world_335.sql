/*
-- Apothecary Faustin
DELETE FROM `creature_text` WHERE `CreatureID`=5414;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5414,0,0,"The serum will only take a few minutes to prepare, $n.",12,0,100,1,0,0,1848,0,"Apothecary Faustin"),
(5414,1,0,"Almost done...",12,0,100,0,0,0,1849,0,"Apothecary Faustin"),
(5414,2,0,"At last, the serum is complete, $n. Now, come closer. We must talk.",12,0,100,1,0,0,1850,0,"Apothecary Faustin");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5414;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5414 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=541400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5414,0,0,0,20,0,100,0,1383,0,0,0,80,541400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Quest 'Nothing But The Truth (Part 2)' Finished - Run Script"),
(541400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Remove Npc Flag Questgiver"),
(541400,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Say Line 0"),
(541400,9,2,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.23291,"Apothecary Faustin - On Script - Set Orientation"),
(541400,9,3,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Set Emote State 69"),
(541400,9,4,0,0,0,100,0,15000,15000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Say Line 1"),
(541400,9,5,0,0,0,100,0,8000,8000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Set Emote State 0"),
(541400,9,6,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.14159,"Apothecary Faustin - On Script - Set Orientation"),
(541400,9,7,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Say Line 2"),
(541400,9,8,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Faustin - On Script - Add Npc Flag Questgiver");
*/
