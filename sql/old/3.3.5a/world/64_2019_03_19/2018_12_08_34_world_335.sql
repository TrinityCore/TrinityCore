--
-- Burning Blade Toxicologist
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=12319;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12319 AND `source_type`=0 AND `id` IN (4,5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(12319,0,4,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Burning Blade Toxicologist - Just Summoned - Start Attacking"),
(12319,0,5,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Toxicologist - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=12319;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12319,0,0,"You've interfered with our plans for the last time, foolish $c!",12,0,100,0,0,0,7579,0,"Burning Blade Toxicologist");
