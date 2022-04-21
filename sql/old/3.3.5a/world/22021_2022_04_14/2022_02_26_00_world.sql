--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -52010;

--
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI', `ScriptName` = '' WHERE `entry` = 191548;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 191548 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(191548,1,0,1,70,0,100,0,2,0,0,0,0,33,29928,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scourge Enclosure - On Gameobject State Changed - Quest Credit 'Our Only Hope'"),
(191548,1,1,2,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,29647,10,0,0,0,0,0,0,"Scourge Enclosure - On Gameobject State Changed - Set Data 0 1 (Gymer)"),
(191548,1,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,11,29928,20,0,0,0,0,0,0,"Scourge Enclosure - On Gameobject State Changed - Set Data 0 1 (Gymer Lock Dummy)");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29928;
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `id` = 29928;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-117883,-117884,-117885,-117886) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2992800,2992801) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-117883,0,0,0,38,0,100,0,0,1,0,0,0,80,2992800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Data Set 0 1 - Run Script"),
(-117885,0,0,0,38,0,100,0,0,1,0,0,0,80,2992800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Data Set 0 1 - Run Script"),
(-117884,0,0,0,38,0,100,0,0,1,0,0,0,80,2992801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Data Set 0 1 - Run Script"),
(-117886,0,0,0,38,0,100,0,0,1,0,0,0,80,2992801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Data Set 0 1 - Run Script"),

(2992800,9,0,0,0,0,100,0,0,0,0,0,0,11,55529,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Script - Cast 'Gymer Lock Explosion'"),
(2992801,9,0,0,0,0,100,0,0,0,0,0,0,11,55529,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Script - Cast 'Gymer Lock Explosion'"),
(2992801,9,1,0,0,0,100,0,2000,2000,0,0,0,11,55529,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gymer Lock Dummy - On Script - Cast 'Gymer Lock Explosion'");

-- Gymer definitely doesn't yell when player turns in the quest, but after player opens the cage. However, he yells after random timer
-- or (most likely) he yells right after player opens the cage, but if another action set was in progress(he also says out of combat),
-- it makes him yell after delay
UPDATE `smart_scripts` SET `event_type` = 38, `event_param1` = 0, `event_param2` = 1, `comment` = "Gymer - On Data Set 0 1 - Say Line 7" WHERE `entryorguid` = 29647 AND `source_type` = 0 AND `id` = 5;
