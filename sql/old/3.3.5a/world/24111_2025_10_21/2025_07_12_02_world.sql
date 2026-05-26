--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_deathbolt' WHERE `ScriptName` = 'spell_q12611_deathbolt';

--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28563;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28563) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2856300) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28563,0,0,0,38,0,100,0,1,1,0,0,0,80,2856300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Data Set 1 1 - Run Action List"),
-- We don't have invoker here
-- For some reason it doesn't work no matter how it is used
-- (2856300,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Say Line 0"),
(2856300,9,1,0,0,0,100,0,0,0,0,0,0,11,51318,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Freya Dummy'"),
(2856300,9,2,0,0,0,100,0,5000,5000,0,0,0,11,51395,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Lifeforce'"),
(2856300,9,3,0,0,0,100,0,5000,5000,0,0,0,11,51395,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Lifeforce'"),
(2856300,9,4,0,0,0,100,0,5000,5000,0,0,0,11,51395,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Lifeforce'"),
(2856300,9,5,0,0,0,100,0,5000,5000,0,0,0,11,51395,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Lifeforce'"),
(2856300,9,6,0,0,0,100,0,5000,5000,0,0,0,11,51395,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freya's Presence - On Script - Cast 'Lifeforce'");

UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_call_of_the_lifewarden' WHERE `ScriptName` = 'spell_q12620_the_lifewarden_wrath';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sholazar_freya_dummy';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51318, 'spell_sholazar_freya_dummy');

UPDATE `creature_text` SET `Probability` = 100 WHERE `CreatureID` = 28563;

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_shoot_rjr' WHERE `ScriptName` = 'spell_q12589_shoot_rjr';

--
UPDATE `creature_text` SET `ID` = 0 WHERE `CreatureID` = 28787;

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 28787;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28787) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2878700,2878701,2878702,2878703,2878704) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28787,0,0,0,19,0,100,0,12688,0,0,0,0,80,2878700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Quest 'Engineering a Disaster' Taken - Run Script"),

(2878700,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Store Targetlist"),
(2878700,9,1,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Set Faction 113"),
(2878700,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Remove NPC Flag Questgiver"),
(2878700,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 0"),
(2878700,9,4,0,0,0,100,0,3000,3000,0,0,0,53,0,2878700,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Start Waypoint"),

(28787,0,1,0,58,0,100,0,0,2878700,0,0,0,80,2878701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Waypoint Finished - Run Script"),

(2878701,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 1"),
(2878701,9,1,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 2"),
(2878701,9,2,0,0,0,100,0,1000,1000,0,0,0,11,52369,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Cast 'Detonate Explosives'"),
(2878701,9,3,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 3"),
(2878701,9,4,0,0,0,100,0,3000,3000,0,0,0,53,0,2878701,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Start Waypoint"),

(28787,0,2,0,58,0,100,0,0,2878701,0,0,0,80,2878702,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Waypoint Finished - Run Script"),

(2878702,9,0,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 4"),
(2878702,9,1,0,0,0,100,0,3000,3000,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 5"),
(2878702,9,2,0,0,0,100,0,1000,1000,0,0,0,11,52371,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Cast 'Detonate Explosives'"),
(2878702,9,3,0,0,0,100,0,2000,2000,0,0,0,53,0,2878702,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Start Waypoint"),

(28787,0,3,0,58,0,100,0,0,2878702,0,0,0,80,2878703,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Waypoint Finished - Run Script"),

(2878703,9,0,0,0,0,100,0,0,0,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Say Line 6"),
(2878703,9,1,0,0,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Set ImmuneNPC"),
(2878703,9,2,0,0,0,100,0,0,0,0,0,0,15,12688,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Script - Quest Credit 'Engineering a Disaster'"),
(2878703,9,3,0,0,0,100,0,5000,5000,0,0,0,53,1,2878703,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Start Waypoint"),

(28787,0,4,0,58,0,100,0,0,2878703,0,0,0,80,2878704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Waypoint Finished - Run Script"),

(2878704,9,0,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Engineer Helice - On Script - Despawn Instant"),

(28787,0,5,0,6,0,100,0,0,0,0,0,0,6,12688,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Engineer Helice - On Death - Fail Quest 'Engineering a Disaster'");

DELETE FROM `script_waypoint` WHERE `entry` = 28787;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2878700 AND 2878703;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(2878700,1,5916.655,5377.119,-98.89189,"Engineer Helice"),
(2878700,2,5918.303,5375.1846,-98.880905,"Engineer Helice"),

(2878701,1,5925.6353,5371.7607,-98.87892,"Engineer Helice"),
(2878701,2,5928.4595,5377.634,-99.029175,"Engineer Helice"),
(2878701,3,5923.454,5380.128,-102.07381,"Engineer Helice"),
(2878701,4,5917.1875,5382.8125,-106.24332,"Engineer Helice"),
(2878701,5,5910.8545,5386.836,-106.24332,"Engineer Helice"),
(2878701,6,5905.1245,5393.084,-104.36307,"Engineer Helice"),
(2878701,7,5904.211,5399.0137,-99.61832,"Engineer Helice"),
(2878701,8,5903.869,5404.004,-97.14992,"Engineer Helice"),
(2878701,9,5899.6494,5408.9204,-95.80813,"Engineer Helice"),
(2878701,10,5894.604,5406.4204,-95.773094,"Engineer Helice"),
(2878701,11,5890.022,5398.5986,-95.45413,"Engineer Helice"),
(2878701,12,5888.2026,5389.766,-95.39017,"Engineer Helice"),
(2878701,13,5887.8447,5385.628,-95.3472,"Engineer Helice"),

(2878702,1,5879.204,5379.8057,-94.22403,"Engineer Helice"),
(2878702,2,5874.893,5370.3823,-95.97647,"Engineer Helice"),
(2878702,3,5872.0894,5363.6025,-97.509,"Engineer Helice"),
(2878702,4,5865.1177,5357.971,-98.60394,"Engineer Helice"),
(2878702,5,5857.0767,5352.808,-98.93683,"Engineer Helice"),
(2878702,6,5849.1987,5344.5957,-99.35419,"Engineer Helice"),
(2878702,7,5841.1,5335.7026,-100.4754,"Engineer Helice"),
(2878702,8,5834.303,5326.5703,-99.19456,"Engineer Helice"),
(2878702,9,5826.3457,5317.33,-97.85027,"Engineer Helice"),
(2878702,10,5818.2407,5305.194,-97.43694,"Engineer Helice"),

(2878703,1,5801.7915,5296.6514,-95.75294,"Engineer Helice"),
(2878703,2,5791.565,5298.5063,-96.164955,"Engineer Helice"),
(2878703,3,5775.99,5302.8086,-98.47748,"Engineer Helice"),
(2878703,4,5758.465,5306.957,-97.36847,"Engineer Helice");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28789;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28789 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2878900,2878901) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28789,0,0,0,8,0,100,0,52369,0,0,0,0,80,2878900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Spellhit 'Detonate Explosives' - Run Script"),

(2878900,9,0,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Cast 'Cosmetic - Explosion'"),
(2878900,9,1,0,0,0,100,0,0,0,0,0,0,131,67,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Spawn SpawnGroup 67"),
(2878900,9,2,0,0,0,100,0,20000,20000,0,0,0,132,67,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Despawn SpawnGroup 67"),

(28789,0,1,0,8,0,100,0,52371,0,0,0,0,80,2878901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Spellhit 'Detonate Explosives' - Run Script"),

(2878901,9,0,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Cast 'Cosmetic - Explosion'"),
(2878901,9,1,0,0,0,100,0,0,0,0,0,0,131,68,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Spawn SpawnGroup 68"),
(2878901,9,2,0,0,0,100,0,20000,20000,0,0,0,132,68,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Explosion Guy - On Script - Despawn SpawnGroup 68");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_q12688_detonate_1','spell_q12688_detonate_2');
