DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=30179) AND `path_id`=0;
DELETE FROM `creature_template_addon` WHERE `entry`=30179;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (30179,0,1,0, '');

-- Spectral Warden SAI
SET @ENTRY := 36666;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,69144,32,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Warden - On Reset - Cast 'Shadowform'"),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,9000,10000,11,69633,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Warden - In Combat - Cast 'Veil of Shadow'"),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,5000,6000,11,69633,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spectral Warden - In Combat - Cast 'Veil of Shadow'"),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,5000,6000,11,69148,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spectral Warden - In Combat - Cast 'Wail of Souls'");

DELETE FROM `creature_template_addon` WHERE `entry`=36666;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (36666,0,1,0, '');
UPDATE `creature_addon`  SET `bytes1`=1, `auras`= '' WHERE `guid` IN (201796,201737,201687);

-- Scarlet Crusader SAI
SET @ENTRY := 28529;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Crusader - In Combat CMC - Cast 'Shoot'");

UPDATE `creature_addon`  SET `auras`= '' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=28529);

-- Mam'toth Disciple SAI
SET @ENTRY := 28861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,33,28876,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mam'toth Disciple - On Just Died - Quest Credit 'Wooly Justice'"),
(@ENTRY,0,1,2,25,0,100,0,0,0,0,0,28,52607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mam'toth Disciple - On Reset - Remove Aura 'Enraged Mammoth: Trample Aura for On Death Kill Credit'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,52574,32,0,0,0,0,1,0,0,0,0,0,0,0,"Mam'toth Disciple - On Reset - Cast 'Blue Radiation'");
UPDATE `creature_addon`  SET `auras`= '' WHERE `guid` IN (113829,83026);
UPDATE `creature_template_addon`  SET `auras`= '' WHERE `entry` IN (28861);
