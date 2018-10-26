/*
-- 
-- Stormscale Toxicologist
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12321;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12321 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(12321,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Stormscale Toxicologist - Just Summoned - Start Attacking"),
(12321,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormscale Toxicologist - On Aggro - Say Line 0"),
(12321,0,2,0,0,0,100,0,2000,2000,3000,5000,0,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormscale Toxicologist - In Combat - Cast 'Holy Smite"),
(12321,0,3,0,14,0,100,0,200,40,18000,21000,0,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormscale Toxicologist - Friendly At 200 Health - Cast 'Heal'");

DELETE FROM `creature_text` WHERE `CreatureID`=12321;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12321,0,0,"You've interfered with our plans for the last time, foolish $c!",12,0,100,0,0,0,7582,0,"Stormscale Toxicologist");

UPDATE `event_scripts` SET `x`=6875.63, `y`=-661.278, `z`=84.2268, `o`=0.870214 WHERE `id`=6138 AND `datalong`=12321;
*/
