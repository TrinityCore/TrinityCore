-- Improve completion event for quest "Seeking Spiritual Aid"
UPDATE `creature_text` SET `Type`=12 WHERE `CreatureID`=5901 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=2 WHERE `CreatureID`=5901 AND `GroupID`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=11256;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11256,0,0,"We have heard your requests, and we agree... it is noble in intent. We will purify your waters. Go with our blessing, shaman.",12,12,100,0,0,0,6607,0,"Manifestation of Water");

DELETE FROM `smart_scripts` WHERE `entryorguid`=590100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(590100,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Islen Waterseer - On Script - Remove Npc Flag Gossip+Questgiver"),
(590100,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-1345.16,-4065.02,-0.49,4.73,"Islen Waterseer - On Script - Move To Position"),
(590100,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Islen Waterseer - On Script - Say Line 0"),
(590100,9,3,0,0,0,100,0,7000,7000,0,0,12,11256,3,20000,0,0,0,8,0,0,0,-1346.59,-4076.39,-1.23,1.6,"Islen Waterseer - On Script - Summon Creature \'Manifestation of Water\'"),
(590100,9,4,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Islen Waterseer - On Script - Say Line 1"),
(590100,9,5,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-1345,-4048,6.09,4.34,"Islen Waterseer - On Script - Move To Position"),
(590100,9,6,0,0,0,100,0,5000,5000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Islen Waterseer - On Script - Add Npc Flag Gossip+Questgiver"),
(590100,9,7,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Islen Waterseer - On Script - Set Orientation");

DELETE FROM `smart_scripts` WHERE `entryorguid`=11256 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11256,0,0,0,1,0,100,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manifestation of Water - Out of Combat - Say Line 0");
