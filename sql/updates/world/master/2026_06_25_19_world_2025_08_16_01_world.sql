--
DELETE FROM `spell_target_position` WHERE `ID` IN (518,25831,25832,26630,26631,26632,720,731,1121);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(518,0,531,-8028.5,1050.9,-54,0,0),
(25831,0,531,-8158.03,1139.3,-83.95,0,0),
(25832,0,531,-8029.25,1237.78,-85.2285,0,0),
(720,0,531,-8043.6,1254.1,-84.3,0,0),
(731,0,531,-8003,1222.9,-82.1,0,0),
(1121,0,531,-8022.3,1149,-89.1,0,0),
(26630,0,531,-8043.6,1254.1,-84.2167,0,0),
(26631,0,531,-8003,1222.9,-82.0167,0,0),
(26632,0,531,-8022.3,1149,-89.0167,0,0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 15962;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15630,15962) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15630,0,0,0,37,0,100,0,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spawn of Fankriss - On AI Initialize - Set Corpse Delay"),
(15630,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spawn of Fankriss - On Spawn - Set In Combat With Zone"),
(15630,0,2,0,60,0,100,1,20000,20000,0,0,0,11,26662,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spawn of Fankriss - On Update - Cast 'Berserk'"),

(15962,0,0,0,37,0,100,0,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vekniss Hatchling - On AI Initialize - Set Corpse Delay"),
(15962,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vekniss Hatchling - On Spawn - Set In Combat With Zone");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_fankriss_entangle';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(720, 'spell_fankriss_entangle'),
(731, 'spell_fankriss_entangle'),
(1121, 'spell_fankriss_entangle');

UPDATE `creature_template` SET `speed_run` = 2.14285714286 WHERE `entry` = 15510;
UPDATE `creature_template` SET `speed_run` = 1.71428571429 WHERE `entry` = 15630;
UPDATE `creature_template` SET `speed_run` = 1.42857142857 WHERE `entry` = 15962;
