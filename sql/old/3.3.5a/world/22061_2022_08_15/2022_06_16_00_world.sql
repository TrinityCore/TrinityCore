--
DELETE FROM `spell_scripts` WHERE `id` = 44688;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24852 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2485200,2485201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24852,0,0,0,11,0,100,512,0,0,0,0,0,80,2485200,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Spawn - Run Script"),
(24852,0,1,0,58,0,100,512,0,0,0,0,0,80,2485201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Waypoint Finished - Run Script"),

(2485200,9,0,0,0,0,100,512,4000,4000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Say Line 0"),
(2485200,9,1,0,0,0,100,512,0,0,0,0,0,11,44687,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Cast 'Rocket Jump'"),
(2485200,9,2,0,0,0,100,512,2000,2000,0,0,0,53,1,24852,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Start Waypoint"),

(2485201,9,0,0,0,0,100,512,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Say Line 1"),
(2485201,9,1,0,0,0,100,512,0,0,0,0,0,28,44687,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Remove Aura 'Rocket Jump'"),
(2485201,9,2,0,0,0,100,512,2000,2000,0,0,0,11,44688,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Cast 'System Failure'"),
(2485201,9,3,0,0,0,100,512,1500,1500,0,0,0,11,44741,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Script - Cast 'System Failure'");

DELETE FROM `spell_target_position` WHERE `ID` IN (49976);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(49976,0,571,478.996,-5941.52,308.746,0,14545);

--
DELETE FROM `spell_scripts` WHERE `id` = 25952;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 15664 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1566400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15664,0,0,0,62,0,100,1,6763,0,0,0,0,80,1566400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Gossip Option 0 Selected - Run Script (No Repeat)"),

(1566400,9,0,0,0,0,100,0,0,0,0,0,0,11,25952,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Script - Cast 'Reindeer Dust Effect'"),
(1566400,9,1,0,0,0,100,0,0,0,0,0,0,33,15664,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Script - Quest Credit 'Metzen the Reindeer'"),
(1566400,9,2,0,0,0,100,0,8000+3000,8000+3000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Script - Despawn");
