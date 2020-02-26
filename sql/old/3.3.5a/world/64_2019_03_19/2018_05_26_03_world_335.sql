-- Troyas Moonbreeze
DELETE FROM `creature_text` WHERE `CreatureID`=7764;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7764,0,0,"Feralas: A History... Hmmmm... Let me examine this for a moment.",12,0,100,0,0,0,4039,0,"Troyas Moonbreeze"),
(7764,1,0,"%s skims the pages of the book.",16,0,100,0,0,0,4040,0,"Troyas Moonbreeze"),
(7764,2,0,"Amazing! I think I have found it, $n!",12,0,100,5,0,0,4041,0,"Troyas Moonbreeze");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7764;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7764 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=776400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7764,0,0,0,20,0,100,0,2943,0,0,0,80,776400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Quest 'Return to Troyas' Finished - Run Script"),
(776400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Script - Remove Npc Flag Questgiver"),
(776400,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Script - Say Line 0"),
(776400,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Script - Say Line 1"),
(776400,9,3,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Script - Say Line 2"),
(776400,9,4,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troyas Moonbreeze - On Script - Add Npc Flag Questgiver");
