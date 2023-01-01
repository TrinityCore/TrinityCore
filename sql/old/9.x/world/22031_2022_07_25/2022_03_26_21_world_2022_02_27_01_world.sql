--
DELETE FROM `creature_text` WHERE `CreatureID` = 27435;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27435,0,0,"%s armed.",16,0,100,0,0,0,24590,0,"Wintergarde Mine Bomb"),
(27435,1,0,"Detonation in 5...",16,0,100,0,0,0,24591,0,"Wintergarde Mine Bomb"),
(27435,2,0,"4...",16,0,100,0,0,0,24592,0,"Wintergarde Mine Bomb"),
(27435,3,0,"3...",16,0,100,0,0,0,24593,0,"Wintergarde Mine Bomb"),
(27435,4,0,"2...",16,0,100,0,0,0,24594,0,"Wintergarde Mine Bomb"),
(27435,5,0,"1...",16,0,100,0,0,0,24595,0,"Wintergarde Mine Bomb");

UPDATE `creature_template` SET `unit_flags` = 256 WHERE `entry` = 27435;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27435 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2743500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27435,0,0,0,11,0,100,0,0,0,0,0,0,80,2743500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Spawn - Run Script"),
(27435,0,1,0,8,0,100,0,48746,0,0,0,0,11,48744,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Spellhit 'Tap Upper Mine' - Cast 'Upper Wintergarde Mine Credit'"),
(27435,0,2,0,8,0,100,0,48747,0,0,0,0,11,48745,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Spellhit 'Tap Lower Mine' - Cast 'Lower Wintergarde Mine Credit'"),
-- The only flags it actually has are ImmunePC and Sessile, let's keep this hack from previous script for now
(27435,0,3,0,63,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Just Created - Set ImmuneNPC On"),

(2743500,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 0"),
(2743500,9,1,0,0,0,100,0,1500,1500,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 1"),
(2743500,9,2,0,0,0,100,0,1500,1500,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 2"),
(2743500,9,3,0,0,0,100,0,1500,1500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 3"),
(2743500,9,4,0,0,0,100,0,1500,1500,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 4"),
(2743500,9,5,0,0,0,100,0,1500,1500,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Say Line 5"),
(2743500,9,6,0,0,0,100,0,1500,1500,0,0,0,11,48742,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Cast 'Wintergarde Mine Explosion'"),
(2743500,9,7,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Script - Despawn");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (27436,27437);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27436,27437) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27436,0,0,0,8,0,100,0,48742,0,0,0,0,11,48746,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Upper Wintergarde Mine Shaft - On Spellhit 'Wintergarde Mine Explosion' - Cast 'Tap Upper Mine'"),
(27437,0,0,0,8,0,100,0,48742,0,0,0,0,11,48747,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lower Wintergarde Mine Shaft - On Spellhit 'Wintergarde Mine Explosion' - Cast 'Tap Lower Mine'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 48742 AND `ScriptName` = 'spell_q12277_wintergarde_mine_explosion';

--
UPDATE `gameobject` SET `VerifiedBuild` = 12340 WHERE `guid` = 66639 AND `id` = 188711;
UPDATE `gameobject` SET `position_x` = 3903.77685546875, `position_y` = -882.82940673828125, `position_z` = 121.3870697021484375, `orientation` = -2.967041015625, `rotation2` = -0.99619388580322265, `rotation3` = 0.087165042757987976, `VerifiedBuild` = 12340 WHERE `guid` = 370 AND `id` = 188711;
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` = 188711);

UPDATE `creature` SET `position_x` = 3904.216064453125, `position_y` = -882.77777099609375, `position_z` = 119.691162109375, `orientation` = 3.473205089569091796, `VerifiedBuild` = 12340 WHERE `guid` = 42576 AND `id` = 27436;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 131174 AND `id` = 27437;
