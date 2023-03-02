-- Adolescent Thundertail
SET @ENTRY := 92981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Akrrilo <Shadowhunter of the Blackfang>
SET @ENTRY := 92766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,15,15000,25000,11,128044,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,177932,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Vial'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,6434,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slice and Dice at 40% HP');

-- Al'Nathris
SET @ENTRY := 95181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Altauur <Rangari Assassin>
SET @ENTRY := 91942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Argosh the Destroyer
SET @ENTRY := 91871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,183410,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Tremors');

-- Belgork <Grom'kar Strikeleader>
SET @ENTRY := 92552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidate'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,158388,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Iron Binding'),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,25000,11,158210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shackle on Close');

-- Belinoth
SET @ENTRY := 95187;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm');

-- Bilkor the Thrower <Bleeding Hollow Spearmaster>
SET @ENTRY := 90884;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184453,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Spears'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,2,0,9,0,100,0,0,10,15000,25000,11,158665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Face Kick on Close');

-- Blackfang Hunter
SET @ENTRY := 89747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,35,15000,25000,11,171892,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Net on Close'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,171132,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Spear');

-- Blackfang Prowler
SET @ENTRY := 89746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171799,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Breaker');

-- Blackfang Prowler
SET @ENTRY := 92466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Claws');

-- Blackfang Savage
SET @ENTRY := 89695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,171946,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rend'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,171928,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Cleaver');

-- Blackfang Shaman
SET @ENTRY := 92481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,83017,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Insect Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,176218,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Regrowth at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,30000,40,15000,18000,11,176218,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,4,0,16,0,100,0,174768,40,22000,25000,11,174768,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rock Skin on Friendlies Missing Buff'),
(@ENTRY,0,5,0,4,0,100,1,0,0,0,0,11,174768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rock Skin on Aggro');

-- Bleeding Globule
SET @ENTRY := 91301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,185017,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Blood Splatter on Death');

-- Bleeding Hollow Ambusher
SET @ENTRY := 91380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Bleeding Hollow Brute
SET @ENTRY := 89706;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,22000,25000,11,188784,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bellowing Roar at 55% HP');

-- Bleeding Hollow Cabalist
SET @ENTRY := 89703;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,90387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,24617,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Funnel at 40% HP');

-- Bleeding Hollow Cabalist
SET @ENTRY := 90851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,90387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,24617,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Funnel at 40% HP');

-- Bleeding Hollow Herbalist
SET @ENTRY := 92596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,90387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt');

-- Bleeding Hollow Horror
SET @ENTRY := 92657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,188396,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deranged Rampage'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,188387,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Fumes');

-- Bleeding Hollow Hunter
SET @ENTRY := 89699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Bleeding Hollow Impaler
SET @ENTRY := 89705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,184399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Sanguinary Stab');

-- Bleeding Hollow Looter
SET @ENTRY := 90211;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,184399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Sanguinary Stab');

-- Bleeding Hollow Looter
SET @ENTRY := 90222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,184399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Sanguinary Stab');

-- Bleeding Hollow Scavenger
SET @ENTRY := 90210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Bleeding Hollow Scavenger
SET @ENTRY := 92640;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Blood Droplet
SET @ENTRY := 93585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,185017,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Blood Splatter on Death');

-- Bloodfang Grub
SET @ENTRY := 83519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ichor Spray');

-- Bloodfang Ravager
SET @ENTRY := 89741;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,15000,25000,11,162951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lacerating Spines on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162930,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage Armor'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,163040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Bloodfang Swarmer
SET @ENTRY := 89789;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167119,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sting'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,167130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Buzzing Frenzy at 30% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,176070,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fatal Sting at 40% HP');

-- Bloodhunter Zulk <Bleeding Hollow Assassin>
SET @ENTRY := 90936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slice and Dice'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,4,0,0,0,100,0,10000,10000,10000,10000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep');

-- Bramblefell
SET @ENTRY := 91093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184302,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tortured Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,175480,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Rain');

-- Broodlord Ixkor
SET @ENTRY := 92429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174423,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pinning Spines');

-- Captain Grok'mar
SET @ENTRY := 93264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,2,0,9,0,100,0,0,10,15000,25000,11,171466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Captain Ironbeard <The True Scourge of the Iron Seas>
SET @ENTRY := 93076;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,126042,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rusty Shank'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,177001,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shrapnel Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,170625,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Roar at 40% HP');

-- Cave Spider
SET @ENTRY := 92532;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,165669,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid');

-- Ceraxas
SET @ENTRY := 90434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183314,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Flames'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,183308,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Leap on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183303,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fearsome Howl at 40% HP');

-- Child of Keravnos
SET @ENTRY := 80401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,162908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Blood on Spawn');

-- Cindral the Wildfire
SET @ENTRY := 90519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,163111,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Splash'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,167353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Blossom on Close');

-- Cloaked Shadowraider <Shadow Council>
SET @ENTRY := 91201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,79853,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor');

-- Cloaked Shadowraider <Shadow Council>
SET @ENTRY := 91230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,79853,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor');

-- Commander Krag'goth
SET @ENTRY := 91232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close');

-- Commander Org'mok
SET @ENTRY := 89675;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Corrupted Elemental Flame
SET @ENTRY := 93039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,18000,11,170376,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shatter');

-- Corrupted Sentry
SET @ENTRY := 90265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Energy Arc'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,185149,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Self-Destruct at 20% HP');

-- Corrupting Fiend
SET @ENTRY := 93024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169038,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Flames');

-- Crazed Outcast Servant
SET @ENTRY := 93285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,159245,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shiv'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,159248,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mirror Image at 40% HP');

-- Crimson Stinger
SET @ENTRY := 91314;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,128064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stinging Venom');

-- Cyrukh <Corrupted Firelord>
SET @ENTRY := 92010;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Blossom');

-- Daggerfish Darter
SET @ENTRY := 92623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,126922,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Razor Teeth');

-- Daggerfish Hunter
SET @ENTRY := 92513;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,126922,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Razor Teeth');

-- Deathtalon <Avatar of Iskar>
SET @ENTRY := 95053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158560,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,167367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Screech');

-- Demonfang Crawler
SET @ENTRY := 89791;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,165669,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid');

-- Demonfang Larva
SET @ENTRY := 92745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ichor Spray');

-- Deranged Iron Engineer
SET @ENTRY := 107553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,213500,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hastily-Rigged Bomb');

-- Diretusk Piglet
SET @ENTRY := 92875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161040,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,184038,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call Mommy at 40% HP');

-- Direwing Predator
SET @ENTRY := 89788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166347,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting Bite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,166342,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sonic Burst at 40% HP');

-- Diretusk Sow
SET @ENTRY := 92876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161040,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,152573,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gore'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,184039,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protective Fury at 40% HP');

-- Disturbed Podling
SET @ENTRY := 95132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Thorns');

-- Doomguard Overfiend
SET @ENTRY := 92051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183834,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Legion Flames'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,188284,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave on Close');

-- Doomroller <Mar'tak's Creation>
SET @ENTRY := 95056;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,50,15000,25000,11,188576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Siege Nova on Close');

-- Dorg the Bloody <Bleeding Hollow Aberration>
SET @ENTRY := 90887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,15000,25000,11,161615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Iron Stomp on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161601,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraged at 30% HP');

-- Drakum <Hollow's Spear>
SET @ENTRY := 98283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,158665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Face Kick on Close'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,184453,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Spears');

-- Driss Vile <Iron Horde Master Sniper>
SET @ENTRY := 93028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,159087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,185997,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Adrenaline at 30% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,128910,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP'),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,11,159090,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incendiary Rounds on Spawn');

-- Drivnul <Master of Rituals>
SET @ENTRY := 90888;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175611,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arterial Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,184371,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Blood at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,175721,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tides of Blood on Close');

-- Emberhide Packbeast
SET @ENTRY := 89972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Goring Swipe'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,158337,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,158341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wounds'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,158349,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spiny Horns on Spawn');

-- Emberhide Warbeast
SET @ENTRY := 90124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,176065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,158175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Enraged Blood Spirit
SET @ENTRY := 91313;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spectral Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163677,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phantasm at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,163671,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ethereal at 30% HP');

-- Eredar Chaosborn
SET @ENTRY := 92546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184236,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chaos Blade'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,184228,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Sear'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,184237,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Infusion at 40% HP');

-- Executor Riloth
SET @ENTRY := 91727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,184896,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170794,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Eye of Kilrogg
SET @ENTRY := 91475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184939,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ocular Blast'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,184934,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Perception');

-- Eyepiercer <Crazed Blackfang Warmonger>
SET @ENTRY := 92819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184090,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Arc'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,184076,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fearsome Howl at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,175184,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Stomp on Close');

-- Fathomless Skitterer
SET @ENTRY := 93058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172366,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Slash');

-- Fel Crystal
SET @ENTRY := 93652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185300,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Empowerment');

-- Fel Imp
SET @ENTRY := 90428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,170640,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt');

-- Fel Ooze
SET @ENTRY := 89714;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166463,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupted Spray');

-- Fel Overseer Mudlump <Beater of Peons>
SET @ENTRY := 98408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162673,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,193829,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Booterang');

-- Fel Rangari Anaara
SET @ENTRY := 93229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2200,11,184640,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,184647,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Shot'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,184653,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blossom');

-- Felblood Corruptor <Shadow Council>
SET @ENTRY := 92262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,2500,11,183868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blast'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,183872,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Grasp'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felblood Corruptor <Shadow Council>
SET @ENTRY := 92396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,2500,11,183868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blast'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,183872,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Grasp'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felblood Deadeye
SET @ENTRY := 91764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hail of Bullets'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite');

-- Felblood Evoker <Shadow Council>
SET @ENTRY := 92398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183905,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Apathy'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183886,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupt Vitality at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,25,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 25% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,18000,22000,11,183899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Weakness');

-- Felblood Goliath <Shadow Council>
SET @ENTRY := 92397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,30000,11,183883,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howl of Rage'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felblood Overseer
SET @ENTRY := 91760;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,30000,11,183698,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Motivating Roar');

-- Felblood Overseer
SET @ENTRY := 92706;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,158082,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Hardened at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,90325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam');

-- Felblood Warlock
SET @ENTRY := 89754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,3500,11,36247,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,37628,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felblood Warrior
SET @ENTRY := 90066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,158082,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Hardened on Spawn');

-- Felbore
SET @ENTRY := 93168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185990,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rupturing Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,185985,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cavernous Tremors'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,60000,60000,11,183847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Shield on Spawn');

-- Felborn Enforcer <Shadow Council>
SET @ENTRY := 90620;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183136,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flip'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,183130,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Might at 40% HP');

-- Felbound Stalker
SET @ENTRY := 95248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183275,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Caustic Bite');

-- Felbound Wolf
SET @ENTRY := 90517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183275,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Caustic Bite');

-- Felflame Fiend
SET @ENTRY := 92082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4000,11,169038,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Flames');

-- Felborn Instructor <Shadow Council>
SET @ENTRY := 89748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,3500,11,36247,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,37628,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felguard
SET @ENTRY := 90425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183268,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Slash'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,183264,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mighty Weapon at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,183270,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Withering Roar');

-- Felguard Sentinel
SET @ENTRY := 92026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Crash');

-- Felsmith Damorka
SET @ENTRY := 92647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,188486,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,159087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,188488,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Felblast at 40% HP');

-- Felspark
SET @ENTRY := 91098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,163111,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Splash'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,167353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Blossom on Close');

-- Felsworn Berserker
SET @ENTRY := 90482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Felsworn Berserker
SET @ENTRY := 90483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Felsworn Berserker
SET @ENTRY := 92715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Felsworn Blood-Talon <Shadow Council>
SET @ENTRY := 89686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185119,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felblade Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,185117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Rush');

-- Felsworn Bulwark
SET @ENTRY := 91251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,158082,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Hardened at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,4,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Felsworn Conjurer
SET @ENTRY := 93258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,20000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan');

-- Felsworn Hulk
SET @ENTRY := 93267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176419,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161601,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraged at 30% HP');

-- Felsworn Reaver
SET @ENTRY := 91106;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Felsworn Soultwister
SET @ENTRY := 92873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,2500,11,183868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blast'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,183872,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Grasp'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP');

-- Felsworn Thunderer <Shadow Council>
SET @ENTRY := 89683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lightning'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,185130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Storm');

-- Felsworn Vanguard
SET @ENTRY := 93269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,184824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Vulnerability');

-- Findrath'Nadrir
SET @ENTRY := 95190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Forge Engineer
SET @ENTRY := 91721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,158240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cluster Bombs on Spawn');

-- Frostwolf
SET @ENTRY := 92906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150648,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Femoral Tear');

-- Galthenos
SET @ENTRY := 95159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Garrison Grunt
SET @ENTRY := 85792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Garrison Rifleman
SET @ENTRY := 85237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Garrison Soldier
SET @ENTRY := 85234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Ghostly Eye Guardian
SET @ENTRY := 91538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spectral Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,60,22000,25000,11,167012,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incorporeal at 60% HP');

-- Gloomtalon <Clawshaper of the Blackfang>
SET @ENTRY := 92508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,165773,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,165773,1,15000,30000,11,165773,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Repeat'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,184027,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Slash'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,184025,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Claws');

-- Glub'glok
SET @ENTRY := 93125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,39215,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wound'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,174793,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cavitation Blast at 40% HP');

-- Gondar <Hollow's Eye>
SET @ENTRY := 98284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tracker\'s Mark'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,170196,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Whirl on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Gorabosh <Keeper of the Cave>
SET @ENTRY := 92941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,90387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,165663,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Ritual at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,60,22000,25000,11,165662,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sacrificial Pact at 60% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,22000,22000,11,179364,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Shield');

-- Goren Protector
SET @ENTRY := 85294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Bite'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,158997,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rolling Charge on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,174898,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Retched Acid');

-- Grand Warlock Nethekurse
SET @ENTRY := 91695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183559,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Spin'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183575,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Offering at 40% HP');

-- Grannok
SET @ENTRY := 93057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,39058,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,25000,11,184870,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twisted Souls on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,60,22000,25000,11,184872,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shrieking Skull at 60% HP');

-- Greater Axebeak
SET @ENTRY := 89718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171186,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck');

-- Greater Warlock <Shadow Council>
SET @ENTRY := 90224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,20000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan');

-- Grom'kar Beastbreaker
SET @ENTRY := 89973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,157390,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warleader\'s Signal at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,8,40,15000,25000,11,145027,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grappling Hook on Close');

-- Grom'kar Bulwark
SET @ENTRY := 90393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,158082,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Hardened at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,90325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam');

-- Grom'kar Bulwark
SET @ENTRY := 90398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl on Close');

-- Grom'kar Cauterizer
SET @ENTRY := 90136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,179734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,188538,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Shield'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,179737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Enveloping Flames'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,179735,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP');

-- Grom'kar Deadeye
SET @ENTRY := 90392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hail of Bullets'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite');

-- Grom'kar Deadeye
SET @ENTRY := 90399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,5500,11,162666,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Dockhand
SET @ENTRY := 89936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Cleave'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,179727,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrying Bombs on Spawn');

-- Grom'kar Leadslinger
SET @ENTRY := 89777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,159087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,159090,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incendiary Rounds on Spawn'),
(@ENTRY,0,3,0,9,0,100,0,0,10,15000,25000,11,159329,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disengage on Close');

-- Grom'kar Punisher
SET @ENTRY := 90397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Cleave');

-- Grom'kar Reinforcement
SET @ENTRY := 89810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,25,15000,25000,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Close');

-- Shoulder Charge
SET @ENTRY := 89857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,158414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,158082,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Hardened at 40% HP');

-- Grom'kar Warrior
SET @ENTRY := 91832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,25,15000,25000,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,182230,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Pact at 40% HP');

-- Grom'kar Warsmith
SET @ENTRY := 89935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,158240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cluster Bombs on Spawn');

-- Hal'Nazris
SET @ENTRY := 95172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Halvonoth
SET @ENTRY := 95178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Harbormaster Korak
SET @ENTRY := 90094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183494,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crunch Time'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,183482,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lock Down on Aggro'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183485,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Behind Schedule at 40% HP');

-- Herald of Chaos
SET @ENTRY := 92028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamelash'),
(@ENTRY,0,1,0,9,0,100,0,0,40,15000,25000,11,170068,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Charge on Close');

-- High Priest Ikzan <Shadow Council>
SET @ENTRY := 90777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185405,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felstorm Gale'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,185376,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tides of Shadow');

-- Highlands Axebeak
SET @ENTRY := 90245;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171186,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck');

-- Hulking Diretusk
SET @ENTRY := 89688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161040,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered at 30% HP');

-- Imp-Master Valessa
SET @ENTRY := 90429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183371,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Offering at 40% HP');

-- Infernal Devastator
SET @ENTRY := 92031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185782,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Punch'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,182574,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,183847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Shield on Aggro');

-- Iron Battle Engine
SET @ENTRY := 90074;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,179785,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hardened on Spawn');

-- Iron Grimshot
SET @ENTRY := 93265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hail of Bullets'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite');

-- Iron Scout
SET @ENTRY := 93579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,25,15000,25000,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Close');

-- Iron Siegesmith
SET @ENTRY := 90510;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,158240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cluster Bombs on Spawn');

-- Iron Sniper
SET @ENTRY := 90497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hail of Bullets'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite');

-- Iron Turret
SET @ENTRY := 93596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,185186,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Turret Fire');

-- Iron Wargronn
SET @ENTRY := 90585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,172781,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,172774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Shatter on Close'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,150770,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Slap');

-- Iron Warsmith
SET @ENTRY := 93263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Whirl');

-- Iron Warwolf
SET @ENTRY := 91250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,131944,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ferocious Bite');

-- Ironfang Stalker
SET @ENTRY := 95305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183275,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Caustic Bite');

-- Jalmedar
SET @ENTRY := 95189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Jax'zor
SET @ENTRY := 90437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183268,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Slash'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,183379,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fracturing Crash on Close');

-- Kath'naroc
SET @ENTRY := 95170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Keravnos
SET @ENTRY := 80398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,162908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Blood on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,161970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Bite');

-- Keravnos Broodmother
SET @ENTRY := 80405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,162908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Blood on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,161970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Bite');

-- Keravnos Monitor
SET @ENTRY := 80404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,162908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Blood on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,161970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Bite');

-- Keravnos Wanderer
SET @ENTRY := 80453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,162908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Blood on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,161970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Bite');

-- Kirin Tor Magus
SET @ENTRY := 90967;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Evade');

-- Kormathras
SET @ENTRY := 95188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Krell the Serene <Blademaster of the Blackfang>
SET @ENTRY := 92517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,184046,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Keen Edge');

-- Krikno <Frostwolf Clan>
SET @ENTRY := 90576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Kris'kar the Unredeemed <Crusader of Rukhmar>
SET @ENTRY := 93279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,158143,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chakram'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,158160,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kaleidoscope'),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,25000,11,165373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Whirl on Close');

-- Kuhl Ragefury
SET @ENTRY := 90080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183883,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howl of Rage at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,30,20000,20000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 30% HP');

-- Lady Oran
SET @ENTRY := 90438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Goring Swipe'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,158337,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Lok'goron Sentry
SET @ENTRY := 93370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,25,15000,25000,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Close');

-- Magril the Seer <Shadow Council>
SET @ENTRY := 90226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Funnel'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Shackle'),
(@ENTRY,0,2,0,1,0,50,1,3000,3000,0,0,11,169027,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Familiar on Spawn'),
(@ENTRY,0,3,0,1,0,50,1,3000,3000,0,0,11,169021,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felfire Familiar on Spawn'),
(@ENTRY,0,4,0,1,0,50,1,3000,3000,0,0,11,169026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Shadowflame Familiar on Spawn');

-- Magwia
SET @ENTRY := 93002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,188281,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whip Splash'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Marsh Gulper
SET @ENTRY := 89749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Pool'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,158532,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Trounce at 55% HP');

-- Melrothar
SET @ENTRY := 95157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Mistress Thavra
SET @ENTRY := 90442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183347,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Stab');

-- Murdrimus
SET @ENTRY := 95182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Murktide Hatchling
SET @ENTRY := 92915;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,131133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Claw Slash');

-- Murktide Slashclaw
SET @ENTRY := 92910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,178703,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Claw Fury');

-- Murktide Squallweaver
SET @ENTRY := 92901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,178702,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,34827,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,34827,1,15000,30000,11,34827,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Repeat');

-- Nefarious Fiend
SET @ENTRY := 90811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,182899,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,182895,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Step through the Void at 40% HP');

-- Negrizarr
SET @ENTRY := 95180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Ogron Hauler
SET @ENTRY := 90163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162280,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,162232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Interrupting Shout on Player Spell Cast');

-- Org'mok's Beast
SET @ENTRY := 89676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Bite');

-- Oriathis
SET @ENTRY := 95184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Overlord Ma'gruth <Shadow Council>
SET @ENTRY := 92411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183785,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Flames'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183783,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Empowerment at 40% HP');

-- Painmistress Selora
SET @ENTRY := 92274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crack the Whip'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183748,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elusive at 40% HP');

-- Pale Ambusher
SET @ENTRY := 92563;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,160323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Claws'),
(@ENTRY,0,2,0,9,0,100,0,0,30,15000,25000,11,160344,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Zephyr Leap on Close'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,149838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Concealment on Spawn'),
(@ENTRY,0,4,0,7,0,100,1,0,0,0,0,11,149838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Concealment on Evade');

-- Pale Bestower
SET @ENTRY := 92530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160376,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Venom'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,160372,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leech Vitality at 55% HP');

-- Pale Brute
SET @ENTRY := 92537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160458,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unstable Slam');

-- Pale Oracle
SET @ENTRY := 92536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fading Blast'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,160423,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Crush'),
(@ENTRY,0,2,0,16,0,100,0,160433,40,22000,25000,11,160433,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Burning Reflexes on Friendlies Missing Buff');

-- Pale Spidermaster
SET @ENTRY := 92531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,128252,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,128933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,128933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,3,0,1,0,100,1,3000,5000,0,0,11,183394,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spider on Spawn');

-- Pale Stabber
SET @ENTRY := 92529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160345,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Rush'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,160323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Claws'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,149947,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Weapon at 40% HP');

-- Palmordris
SET @ENTRY := 95179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Podlord Wakkawam
SET @ENTRY := 91374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,15656,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisonous Stab'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,188470,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thornstorm');

-- Putre'thar
SET @ENTRY := 91009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183720,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Breath');

-- Python Hatchling
SET @ENTRY := 92607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,34811,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail Lash');

-- Ralstiroth
SET @ENTRY := 95185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Rangari Scout
SET @ENTRY := 90186;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,182106,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Crossbow'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Rangari Sheera <Ex Provisioner>
SET @ENTRY := 91944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Ranotheric
SET @ENTRY := 95177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Rasthe <Son of Sethe>
SET @ENTRY := 90782;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184209,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felflame Gale'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,184162,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Downdraft');

-- Relgor <Bleeding Hollow Master Scout>
SET @ENTRY := 92197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,184399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sanguinary Stab'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,188504,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Scent at 40% HP');

-- Remnant of Cindral
SET @ENTRY := 90522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation');

-- Remnant of Cindral
SET @ENTRY := 92413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation');

-- Remnant of the Blood Moon
SET @ENTRY := 91227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185167,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Splash');

-- Rendarr <Warshaman of the Blackfang>
SET @ENTRY := 92817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176249,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wooden Fists'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,174768,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rock Skin at 40% HP'),
(@ENTRY,0,2,0,16,0,100,0,174768,40,22000,25000,11,174768,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rock Skin on Friendlies Missing Buff');

-- Rendrak <Direwing Alpha>
SET @ENTRY := 92627;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,184371,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Blood at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,22000,22000,11,32651,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech');

-- Ril'Morgus
SET @ENTRY := 95183;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Rogond the Tracker <Bleeding Hollow Huntmaster>
SET @ENTRY := 90885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tracker\'s Mark'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,170196,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Whirl on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Rulkrik the Pillager <Bleeding Hollow Clan>
SET @ENTRY := 89705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,184399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Sanguinary Stab'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,184382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Slash'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,163586,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting at 40% HP');

-- Sal'Vendris
SET @ENTRY := 95176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Sargerei Adept
SET @ENTRY := 91088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,171807,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,32741,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170187,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');

-- Sargerei Demonmaster
SET @ENTRY := 90421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,183199,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Blast'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,183207,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Empowerment at 40% HP');

-- Sargerei Felbinder
SET @ENTRY := 90286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,183194,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Binding');

-- Sargerei Nullifier
SET @ENTRY := 90295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183209,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harmful Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183214,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Slam');

-- Sargerei Nullifier
SET @ENTRY := 90684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183209,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harmful Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183214,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Slam');

-- Sargerei Summoner
SET @ENTRY := 92575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,171852,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Spike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,84533,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Life at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170187,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');

-- Savage Whale Shark
SET @ENTRY := 94472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221422,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,18000,11,221425,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,221424,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fear at 40% HP');

-- Scaleclaw Devourer
SET @ENTRY := 89742;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,153161,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ripping Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,165308,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wound');

-- Scaleclaw Hatchling
SET @ENTRY := 89745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,153161,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ripping Claws');

-- Scaleclaw Lashtail
SET @ENTRY := 89744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165308,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wound'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro');

-- Sergeant Mor'grak
SET @ENTRY := 90024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168083,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Massive Slam'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,183698,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Motivating Roar at 55% HP');

-- Sethekk Dreadclaw <Shadow Council>
SET @ENTRY := 90649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,185306,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,174844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Slash');

-- Sethekk Dreadclaw <Shadow Council>
SET @ENTRY := 94467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,185306,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,174844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Slash');

-- Sethekk Invoker <Shadow Council>
SET @ENTRY := 90654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,15000,11,183021,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Imp');

-- Sethekk Invoker <Shadow Council>
SET @ENTRY := 94468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,15000,11,183021,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Imp');

-- Sethekk Neophyte <Shadow Council>
SET @ENTRY := 90312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183165,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Crash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183161,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Zone');

-- Sethekk Oracle <Shadow Council>
SET @ENTRY := 90607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,3000,40,15000,18000,11,183323,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal Other on Friendlies');

-- Sethekk Oracle <Shadow Council>
SET @ENTRY := 94469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,3000,40,15000,18000,11,183323,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal Other on Friendlies');

-- Shadow Hunter Zel'duk
SET @ENTRY := 90239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Shadow Vanguard
SET @ENTRY := 90225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,2,0,9,0,100,0,0,10,15000,25000,11,171466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Shadowheart Fiend
SET @ENTRY := 92083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame Nova');

-- Shadowthrash
SET @ENTRY := 93236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Claws'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,32939,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Phase Burst on Aggro');

-- Smashum Grabb <Hollow's Fist>
SET @ENTRY := 98285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Iron Stomp'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161601,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraged at 30% HP');

-- Soul Fragment
SET @ENTRY := 92937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184174,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip Soul');

-- Soulslicer <Corrupted Shaman>
SET @ENTRY := 92495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184017,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Bargain');

-- Steelsnout
SET @ENTRY := 92887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162083,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heave'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered at 30% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,172781,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Summoned Fiend
SET @ENTRY := 91262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame Nova');

-- Swamp Python
SET @ENTRY := 89697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167429,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Huge Fang'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,158873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Numbing Poison');

-- Sylissa <Marshwater Queen>
SET @ENTRY := 92606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167429,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Huge Fang'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,158873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Numbing Poison');

-- Szirek the Twisted
SET @ENTRY := 93001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183905,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Apathy'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183886,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupt Vitality at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,25,22000,25000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 25% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,18000,22000,11,183899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Weakness'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3000,3500,11,183868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blast');

-- Tanaan Gloomhunter
SET @ENTRY := 93003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,165687,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep');

-- Tanglewood Ancient
SET @ENTRY := 93217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,22000,11,159089,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Bark');

-- Terrorfist <Son of Kormrok>
SET @ENTRY := 95044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,9,0,100,0,0,6,15000,25000,11,172679,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smash on Close');

-- Thargruk the Defiler <Shadow Council>
SET @ENTRY := 90254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,20000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan');

-- The Blackfang <Warboss of the Blackfang>
SET @ENTRY := 92465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183960,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rumbling Smash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,183946,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Claws at 40% HP');

-- The Goreclaw
SET @ENTRY := 92694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,82608,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech');

-- The Iron Houndmaster
SET @ENTRY := 92977;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,25,15000,25000,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Close'),
(@ENTRY,0,1,0,16,0,100,0,184863,40,22000,25000,11,184863,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bestial Wrath on Friendlies Missing Buff');

-- The Night Haunter
SET @ENTRY := 92636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Interrupting Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,172453,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghostly Howl');

-- The Night Haunter
SET @ENTRY := 92645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,192618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Marked by the Night Haunter');

-- Tho'gar Gorefist
SET @ENTRY := 91243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183390,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Blades'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183785,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Flames'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,183783,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Empowerment at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,30,20000,20000,11,183863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonblood Vial at 30% HP');

-- Thromma the Gutslicer
SET @ENTRY := 92574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160458,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unstable Slam'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,160372,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leech Vitality at 55% HP');

-- Thundertail Riverbeast
SET @ENTRY := 92979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Uncontrolled Distortion
SET @ENTRY := 93175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167616,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Resonant Strike');

-- Undergrowth Bloom
SET @ENTRY := 93621;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,48195,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Emerald Lasher Emerge on Aggro'),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Ground Emote on Aggro'),
(@ENTRY,0,3,0,0,1,100,1,0,0,2000,2000,11,169567,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hurl Seed'),
(@ENTRY,0,4,0,7,1,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 on Evade'),
(@ENTRY,0,5,0,7,2,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Ground Emote on Evade'),
(@ENTRY,0,6,0,21,2,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ground Emote on Reached Home');

-- Undergrowth Lurker
SET @ENTRY := 89756;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,165779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,165776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom-Laced Web');

-- Valnithar
SET @ENTRY := 95162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Varyx the Damned
SET @ENTRY := 92451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Conduit'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,185277,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chaos Storm at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2500,2500,11,185306,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate');

-- Vengeance <Avatar of Velhari>
SET @ENTRY := 95054;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170178,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Enveloping Shadows'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,170180,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Infusion at 40% HP');

-- Vile Packhunter
SET @ENTRY := 92002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183820,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Maw');

-- Vol'mar Magus
SET @ENTRY := 95578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Evade');

-- Vol'mar Shadow Hunter
SET @ENTRY := 90988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Wakkaling
SET @ENTRY := 91047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Thorns');

-- Wind Guardian
SET @ENTRY := 90582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Xalgros
SET @ENTRY := 95173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Xanzith the Everlasting
SET @ENTRY := 92408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183653,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disintegration Beam');

-- Xemirkol
SET @ENTRY := 96235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,190817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Crash');

-- Zekaveron
SET @ENTRY := 95165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Zemorath
SET @ENTRY := 95164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,170216,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Shadow at 55% HP');

-- Zeter'el
SET @ENTRY := 91087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,184228,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Sear'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,186820,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Blast'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,60000,60000,11,183847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Shield on Spawn');