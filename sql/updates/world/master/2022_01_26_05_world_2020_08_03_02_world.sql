--
-- Captain Tyralius's Prison SAI
UPDATE `gameobject` SET `spawntimesecs` = 60 WHERE `id` = 184588 AND `guid` = 25412;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 184588;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 184588 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18458800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(184588,  1,0,0,11,0,100,0,0,0,0,0,0,12,   20787,8,0,0,0,0, 1,    0,0,0,0,0,0,0,0,"Captain Tyralius's Prison - On Respawn - Summon Creature 'Captain Tyralius'"),
(184588,  1,1,0,11,0,100,0,0,0,0,0,0,12,   20825,8,0,0,0,0, 1,    0,0,0,0,0,0,0,0,"Captain Tyralius's Prison - On Respawn - Summon Creature 'Ethereum Prisoner (Tyralius)'"),
(184588,  1,2,0,64,0,100,0,1,0,0,0,0,80,18458800,0,0,0,0,0, 1,    0,0,0,0,0,0,0,0,"Captain Tyralius's Prison - On Gossip Hello - Run Script"),
(18458800,9,0,0, 0,0,100,0,0,0,0,0,0,99,       3,0,0,0,0,0, 1,    0,0,0,0,0,0,0,0,"Captain Tyralius's Prison - On Script - Set Lootstate Deactivated"),
(18458800,9,1,0, 0,0,100,0,0,0,0,0,0,33,   20787,0,0,0,0,0, 7,    0,0,0,0,0,0,0,0,"Captain Tyralius's Prison - On Script - Quest Credit 'Captain Tyralius'"),
(18458800,9,2,0, 0,0,100,0,0,0,0,0,0, 1,       0,0,0,0,0,0,19,20787,5,0,0,0,0,0,0,"Captain Tyralius's Prison - On Script - Say Line 0 (Captain Tyralius)"),
(18458800,9,3,0, 0,0,100,0,0,0,0,0,0,41,       0,0,0,0,0,0,19,20825,5,0,0,0,0,0,0,"Captain Tyralius's Prison - On Script - Despawn (0) (Ethereum Prisoner (Tyralius))"),
(18458800,9,4,0, 0,0,100,0,0,0,0,0,0,45,       0,1,0,0,0,0,19,20787,5,0,0,0,0,0,0,"Captain Tyralius's Prison - On Script - Set Data 0 1 (Captain Tyralius)");

-- Captain Tyralius SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 20787;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20787 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2078700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20787,  0,0,0,38,0,100,0,   0,   1,0,0,0,80,2078700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Tyralius - On Data Set 0 1 - Run Script"),
(2078700,9,0,0, 0,0,100,0,5000,5000,0,0,0,11,  51347,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Tyralius - On Script - Cast 'Teleport Visual Only'"),
(2078700,9,1,0, 0,0,100,0,   0,   0,0,0,0,41,   2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Tyralius - On Script - Despawn (2000)");
