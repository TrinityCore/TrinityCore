-- Charlga Razorflank <The Crone>
SET @ENTRY := 4421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','10','0','100','1','0','40','500','2000','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','OOC LOS - Speech (condition if player)'),
(@ENTRY,'0','1','0','4','0','100','0','0','0','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech'),
(@ENTRY,'0','2','0','61','0','100','0','0','0','0','0','11','151534','0','0','0','0','0','2','0','0','0','0','0','0','0','Link - Crystalline Command'),
(@ENTRY,'0','3','0','0','0','100','1','5000','5000','0','0','11','151534','0','0','0','0','0','2','0','0','0','0','0','0','0','OOC Once - Crystalline Command'),
(@ENTRY,'0','4','0','0','0','100','0','10000','10000','6000','6000','11','151583','0','0','0','0','0','2','0','0','0','0','0','0','0','OOC - Elemental Binding'),
(@ENTRY,'0','5','0','6','0','100','0','0','0','0','0','45','1','1','0','0','0','0','19','44415','1000','0','0','0','0','0','Death - Set Data to Spirit of Agamaggan'),
(@ENTRY,'0','6','0','4','0','100','1','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Say Text on Aggro'),
(@ENTRY,'0','7','0','2','0','100','1','0','60','0','0','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','Say Text at 60% HP');

-- Hunter Bonetusk <Pack Leader>
SET @ENTRY := 75001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','38','0','100','1','1','1','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','Data Set from Geomangus Once - Speech'),
(@ENTRY,'0','1','0','9','0','100','0','0','20','1000','2000','11','150879','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Shoot'),
(@ENTRY,'0','2','4','0','0','100','0','2000','2000','17000','22000','11','150881','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Barrage'),
(@ENTRY,'0','3','4','0','0','100','0','6000','8000','7000','20000','11','150904','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Volley'),
(@ENTRY,'0','4','0','61','0','100','0','0','0','0','0','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','Link - Speech - Many shots, 1 kill'),
(@ENTRY,'0','5','6','2','0','100','1','0','50','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','HP50% - Speech - Boars overrun'),
(@ENTRY,'0','6','0','61','0','100','0','0','0','0','0','11','150917','0','0','0','0','0','2','0','0','0','0','0','0','0','Link - Stampede on Target'),
(@ENTRY,'0','7','0','6','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Death - Speech - Never Take Glory'),
(@ENTRY,'0','8','0','4','0','100','0','0','0','0','0','1','4','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech - Run Them Through');

-- Roogug <Geomagus Overseer>
SET @ENTRY := 74948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','10','0','100','1','0','60','500','2000','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','OOC LOS - Speech (condition if player)'),
(@ENTRY,'0','1','0','6','0','100','0','0','0','0','0','1','4','0','0','0','0','0','1','0','0','0','0','0','0','0','Death - Speech'),
(@ENTRY,'0','2','0','4','0','100','0','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech'),
(@ENTRY,'0','3','0','9','0','100','0','0','15','1500','2500','11','150774','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Cast Woven Elements'),
(@ENTRY,'0','4','5','0','0','100','0','6000','16000','18000','25000','11','153525','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Cast Crystalfire Totem'),
(@ENTRY,'0','5','0','61','0','100','0','0','0','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Link - Speech'),
(@ENTRY,'0','6','7','0','0','100','0','10000','20000','19000','35000','11','153528','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Cast Solarshard Totem'),
(@ENTRY,'0','7','0','61','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Link - Speech'),
(@ENTRY,'0','8','0','2','0','100','1','0','75','500','500','1','5','0','0','0','0','0','1','0','0','0','0','0','0','0','HP 75% Once - Speech'),
(@ENTRY,'0','9','0','2','0','100','0','0','75','2500','5000','11','150768','0','0','0','0','0','1','0','0','0','0','0','0','0','HP 75% - Bloodlust');

-- Warlord Ramtusk
SET @ENTRY := 74462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','1','0','100','0','0','0','0','0','86','68561','6','18','40','0','0','1','0','0','0','0','0','0','0','OOC - Players in Range Cast Dummy Trigger on Self'),
(@ENTRY,'0','1','0','8','0','100','1','68561','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','Spell Hit Once - Speech'),
(@ENTRY,'0','2','0','4','0','100','0','0','0','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech'),
(@ENTRY,'0','3','4','0','0','100','0','8000','12000','10000','20000','11','151312','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Cast Spirit Axe'),
(@ENTRY,'0','4','0','61','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Link - Speech'),
(@ENTRY,'0','5','6','6','0','100','0','0','0','0','0','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','Death - Speech'),
(@ENTRY,'0','6','0','61','0','100','0','0','0','0','0','9','0','0','0','0','0','0','14','139920','0','0','0','0','0','0','Link - Activate GO Barrier to make it open');


-- Aggem Thorncurse
SET @ENTRY := 75149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,151274,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,151273,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Shot');

-- Blood-Branded Razorfen
SET @ENTRY := 74553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','0','0','100','0','1000','3000','6000','8000','11','150848','0','0','0','0','0','1','0','0','0','0','0','0','0','Combat - Cast Bleak Strike'),
(@ENTRY,'0','1','0','4','0','100','0','0','0','0','0','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech');

-- Blood-Branded Razorfen
SET @ENTRY := 76090;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','0','0','100','0','1000','3000','6000','8000','11','150848','0','0','0','0','0','1','0','0','0','0','0','0','0','Combat - Cast Bleak Strike'),
(@ENTRY,'0','1','0','4','0','100','0','0','0','0','0','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech');

-- Cave Bat
SET @ENTRY := 75467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sonic Screech');

-- Crystalline Behemoth
SET @ENTRY := 74534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,152289,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crumble on Spawn');

-- Crystalline Shardling
SET @ENTRY := 75648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,152334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crumbling Charge');

-- Death Speaker Jargba
SET @ENTRY := 75152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,151253,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spirit Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,151218,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Broken Link');

-- Enormous Bullfrog
SET @ENTRY := 75590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,152163,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bile Cloud on Spawn');

-- Groyat, the Blind Hunter
SET @ENTRY := 75247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','9','0','100','0','0','5','5000','5000','11','151475','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Drain Life'),
(@ENTRY,'0','1','0','0','0','100','0','500','500','8000','8000','11','151454','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Sonic Charge'),
(@ENTRY,'0','2','0','0','0','100','0','1500','1500','8000','8000','11','151432','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Sonic Field'),
(@ENTRY,'0','3','4','6','0','100','0','0','0','0','0','45','1','1','0','0','0','0','10','379647','0','0','0','0','0','0','Death - Set Data to Portal NPC'),
(@ENTRY,'0','4','5','61','0','100','0','0','0','0','0','45','1','1','0','0','0','0','10','379640','0','0','0','0','0','0','Link - Set Data to Portal NPC'),
(@ENTRY,'0','5','0','61','0','100','0','0','0','0','0','45','1','1','0','0','0','0','10','379653','0','0','0','0','0','0','Link - Set Data to Portal NPC');

-- Kraulshaped Monstrosity
SET @ENTRY := 75384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','1','0','100','0','0','0','0','0','86','68561','6','18','50','0','0','1','0','0','0','0','0','0','0','OOC - Players in Range Cast Dummy Trigger on Self'),
(@ENTRY,'0','1','2','8','0','100','1','68561','0','0','0','51','0','0','0','0','0','0','11','75114','30','0','0','0','0','0','Spell Hit Once - Kill Nearby Kraulshapers'),
(@ENTRY,'0','2','0','61','0','100','1','0','0','0','0','28','151801','0','0','0','0','0','1','0','0','0','0','0','0','0','Link - Remove Aura'),
(@ENTRY,'0','3','0','0','0','100','0','3000','3000','6000','10000','11','152282','0','0','0','0','0','2','0','0','0','0','0','0','0','Combat - Vine Strike');

-- Kraulshaper Tukaar
SET @ENTRY := 74900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','10','0','100','1','0','60','2000','2000','1','3','0','0','0','0','0','1','0','0','0','0','0','0','0','OOC LOS - Speech (condition if player)'),
(@ENTRY,'0','1','0','4','0','100','0','0','0','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Speech'),
(@ENTRY,'0','2','3','6','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Death - Speech'),
(@ENTRY,'0','3','4','61','0','100','0','0','0','0','0','9','0','0','0','0','0','0','14','139867','0','0','0','0','0','0','Link - Activate Gate Gameobject'),
(@ENTRY,'0','4','5','61','0','100','0','0','0','0','0','9','0','0','0','0','0','0','14','139868','0','0','0','0','0','0','Link - Activate Gate Gameobject'),
(@ENTRY,'0','5','0','61','0','100','0','0','0','0','0','45','1','1','0','0','0','0','11','75061','80','0','0','0','0','0','Link - Set Data to nearby Young Boar to run away'),
(@ENTRY,'0','6','0','9','0','100','0','0','50','5000','8000','11','151838','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Cast Kraul Blast'),
(@ENTRY,'0','7','0','9','0','100','0','0','30','5000','10000','11','150658','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Cast Vine Burst'),
(@ENTRY,'0','8','0','9','0','100','0','0','50','5000','12000','11','150650','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Cast Vine Line');

-- Molten Inferno Crystal
SET @ENTRY := 75308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151774,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Inferno');

-- Razorfen Beast Stalker
SET @ENTRY := 74551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,150981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,150859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip');

-- Razorfen Beast Stalker
SET @ENTRY := 76089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,150981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,150859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip');

-- Razorfen Geomagus
SET @ENTRY := 74545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','1','0','100','1','1000','1000','0','0','11','151090','0','0','0','0','0','1','0','0','0','0','0','0','0','OOC Once - Summon Crystaline Aberration'),
(@ENTRY,'0','1','0','1','0','100','1','4000','10000','0','0','11','151091','0','0','0','0','0','1','0','0','0','0','0','0','0','OOC Once - Summon Crystaline Shard'),
(@ENTRY,'0','2','0','4','0','100','1','0','0','0','0','45','1','1','0','0','0','0','19','75001','0','0','0','0','0','0','Aggro - Set Data to Bonetusk for Speech'),
(@ENTRY,'0','3','0','4','0','100','0','0','0','0','0','11','150214','0','0','0','0','0','1','0','0','0','0','0','0','0','Aggro - Summon Crystalfire Totem'),
(@ENTRY,'0','4','0','9','0','100','0','0','15','2500','3000','11','150286','0','0','0','0','0','2','0','0','0','0','0','0','0','Range - Nature Barrage');


-- Razorfen Hidecrusher
SET @ENTRY := 74555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151012,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Slam');

-- Razorfen Huntmaster
SET @ENTRY := 74552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,150100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,15000,11,150849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisoned Arrow Volley');

-- Razorfen Huntmaster
SET @ENTRY := 76088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,150100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,15000,11,150849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisoned Arrow Volley');

-- Razorfen Kraulshaper
SET @ENTRY := 74550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,150540,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reshape at 40% HP'),
(@ENTRY,0,1,0,14,0,100,0,2500,10,15000,18000,11,150540,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Reshape on Friendlies'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2000,2000,11,150510,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vine Line');

-- Razorfen Scarblade
SET @ENTRY := 74554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,152357,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,150990,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Quilboar Battle Cry at 55% HP');

-- Razorfen Stonechanter
SET @ENTRY := 74549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,150546,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harnessed Stone'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,22000,11,150326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Solarshard Totem');

-- Razorfen Thornbolt
SET @ENTRY := 74652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,150100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,150997,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Bolt');

-- Roogug
SET @ENTRY := 6168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,8270,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Earth Rumbler on Spawn');

-- Tidal Tempest Crystal
SET @ENTRY := 74946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151562,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tidal Tempest');