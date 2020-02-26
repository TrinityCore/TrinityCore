-- Gnome Pit Boss & Goblin Pit Boss
DELETE FROM `creature_text` WHERE `CreatureID` IN (4495,4496);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4495,0,0,"Look at what $n brought us!  Let's drink up!",12,0,100,22,0,0,8242,0,"Gnome Pit Boss"),
(4496,0,0,"$n brought us booze!  Let's party!",12,0,100,22,0,0,8244,0,"Goblin Pit Boss");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (4495,4496);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4495,4496) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4495,0,0,0,20,0,100,0,1120,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kravel Koalbeard - On Quest 'Get the Gnomes Drunk' Finished - Say Line 0"),
(4496,0,0,0,20,0,100,0,1121,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kravel Koalbeard - On Quest 'Get the Goblins Drunk' Finished - Say Line 0");
