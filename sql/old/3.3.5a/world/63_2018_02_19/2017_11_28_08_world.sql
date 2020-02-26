-- Fizzle Brassbolts
DELETE FROM `creature_text` WHERE `CreatureID`=4454;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4454,0,0,"%s listens as $n tells him of $ghis:her; adventures in the Badlands.",16,0,100,0,0,0,1495,0,"Fizzle Brassbolts"),
(4454,1,0,"Astounding!  So then indurium is the key!",12,0,100,4,0,0,1496,0,"Fizzle Brassbolts");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4454;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4454 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=445400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4454,0,0,0,20,0,100,0,1137,0,0,0,80,445400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Brassbolts - On Quest 'News for Fizzle' Finished - Run Script"),
(445400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Brassbolts - On Script - Remove Npc Flag Questgiver"),
(445400,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Brassbolts - On Script - Say Line 0"),
(445400,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Brassbolts - On Script - Say Line 1"),
(445400,9,3,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Brassbolts - On Script - Add Npc Flag Questgiver");
