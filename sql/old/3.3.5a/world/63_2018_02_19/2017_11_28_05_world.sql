-- Kin'weelay
DELETE FROM `creature_text` WHERE `CreatureID`=2519 AND `GroupID` IN (2,3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2519,2,0,"I am eager to hear what so angry an orc has to say...",12,0,100,1,0,0,1664,0,"Kin'weelay"),
(2519,3,0,"%s places Marg's head in the cauldron.",16,0,100,0,0,0,1665,0,"Kin'weelay"),
(2519,4,0,"Peer into the cauldron, $n.  Marg wishes to speak...",12,0,100,1,0,0,1666,0,"Kin'weelay");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2519 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=251901 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2519,0,1,0,20,0,100,0,1240,0,0,0,80,251901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Quest 'The Troll Witchdoctor' Finished - Run Script"),
(251901,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,14,6783,2076,0,0,0,0,0,"Kin'weelay - On Script - Add Gameobject Flag"),
(251901,9,1,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Remove Npc Flag Questgiver"),
(251901,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 2"),
(251901,9,3,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 3"),
(251901,9,4,0,0,0,100,0,2000,2000,0,0,11,3644,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Cast Speak with Heads"),
(251901,9,5,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 4"),
(251901,9,6,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Add Npc Flag Questgiver"),
(251901,9,7,0,0,0,100,0,0,0,0,0,106,16,0,0,0,0,0,14,6783,2076,0,0,0,0,0,"Kin'weelay - On Script - Remove Gameobject Flag");
