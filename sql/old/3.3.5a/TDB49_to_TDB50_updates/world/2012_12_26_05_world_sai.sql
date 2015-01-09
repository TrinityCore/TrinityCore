-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -8 AND -7;
DELETE FROM `creature_text` WHERE `entry` IN (6,40,80,257,327,475,476,1236);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(6,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Vermin - Random Say on Aggro'),
(6,0,1, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Vermin - Random Say on Aggro'),
(40,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Miner - Random Say on Aggro'),
(80,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Labourer - Random Say on Aggro'),
(80,0,1, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Labourer - Random Say on Aggro'),
(257,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Worker - Random Say on Aggro'),
(257,0,1, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Worker - Random Say on Aggro'),
(327,0,0, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Goldtooth - Random Say on Aggro'),
(475,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Tunneler - Random Say on Aggro'),
(475,0,1, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Tunneler - Random Say on Aggro'),
(476,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Geomancer - Random Say on Aggro'),
(1236,0,0, 'You no take candle!',12,0,100,0,0,0, 'Kobold Digger - Random Say on Aggro'),
(1236,0,1, 'Yiieeeee! Me run!',12,0,100,0,0,0, 'Kobold Digger - Random Say on Aggro');

-- SAI for Kobold Vermin
SET @ENTRY := 6;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Vermin - On Aggro - Say random text');

-- SAI for Kobold Miner
SET @ENTRY := 40;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Miner - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,4000,14100,38000,42000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Kobold Miner - Combat - Cast Pierce Armor');

-- SAI for Kobold Labourer
SET @ENTRY := 80;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Labourer - On Aggro - Say random text');

-- SAI for Kobold Worker
SET @ENTRY := 257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Worker - On Aggro - Say random text');

-- SAI for Goldtooth
SET @ENTRY := 327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goldtooth - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goldtooth - HP@20% - Flee');

-- SAI for Kobold Tunneler
SET @ENTRY := 475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Tunneler - On Aggro - Say random text');

-- SAI for Kobold Geomancer
SET @ENTRY := 476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,0,1,20793,1500,3000,5,30,0,0,0,0,0,0,0,0, 'Kobold Geomancer - On Spawn - Load Caster template Cast Fireball'),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Geomancer - OOC - Cast Frost Armor'),
(@ENTRY,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Geomancer - On Aggro - Say Random text');

-- SAI for Kobold Digger
SET @ENTRY := 1236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Digger - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,6800,12600,46200,50100,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Kobold Digger - Combat - Cast Pierce Armor'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kobold Digger - HP@30% - Flee');
