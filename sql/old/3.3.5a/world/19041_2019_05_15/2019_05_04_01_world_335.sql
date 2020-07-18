-- Malfurion Stormrage
DELETE FROM `smart_scripts` WHERE `entryorguid`=1536200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1536200,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 0"),
(1536200,9,1,0,0,0,100,0,3000,3000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 5"),
(1536200,9,2,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 1"),
(1536200,9,3,0,0,0,100,0,10000,10000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 2"),
(1536200,9,4,0,0,0,100,0,11000,11000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 3"),
(1536200,9,5,0,0,0,100,0,12000,12000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Say Line 4"),
(1536200,9,6,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malfurion Stormrage - On Script - Add Npc Flag Questgiver");

UPDATE `creature_text` SET `Type`=42 WHERE `CreatureID`=15362 AND `GroupID`=0;
DELETE FROM `creature_text` WHERE `CreatureID`=15362 AND `GroupID`=5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15362,5,0,"%s bows.",16,0,100,2,0,0,11192,0,"Malfurion Stormrage");
