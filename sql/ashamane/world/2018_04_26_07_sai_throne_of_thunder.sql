-- Amani Warbear
SET @ENTRY := 69177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,136463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Swipe');

-- Amani'shi Beast Shaman
SET @ENTRY := 69176;
SET @ENTRYTOTEM := 69215;
SET @TOTEMSPELL := 136489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,136487,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Nova Totem'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,136480,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,136512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hex of Confusion');

-- Amani'shi Flame Caster
SET @ENTRY := 69168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,136465,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Amani'shi Flame Chanter
SET @ENTRY := 69909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,4700,11,138607,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call Flames'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,138652,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Eruption on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,65,22000,25000,11,138610,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Core at 65% HP');

-- Ancient Python
SET @ENTRY := 70448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,139885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,139885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,139888,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ancient Venom');

-- Archritualist Kelada
SET @ENTRY := 70243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Extermination Beam'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,139368,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Overwhelming at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,10000,25000,11,139503,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Interrupt Shield');

-- Bow Fly Swarm
SET @ENTRY := 68222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,134470,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Luciferase');

-- Cavern Burrower
SET @ENTRY := 70589;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,22000,11,140619,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystal Barbs'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,140600,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Call at 55% HP');

-- Corpse Spider
SET @ENTRY := 68248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139498,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web Spray'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,28000,11,112844,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cocoon');

-- Dark Ritualist
SET @ENTRY := 69702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,138099,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,137998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,137995,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Short-Range Ritual Lightning');

-- Drakkari Frost Warden
SET @ENTRY := 69910;
SET @ENTRYTOTEM := 70047;
SET @TOTEMSPELL := 138678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,138690,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Glacial Freeze Totem'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,138668,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Bulwark at 40% HP');

-- Eternal Guardian
SET @ENTRY := 70586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eternal Prison'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,140628,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Nova on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,140630,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Siphon Life at 40% HP');

-- Farraki Sand Conjurer
SET @ENTRY := 69899;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,138739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sand Bolt'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,140636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Elementals on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,138742,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Choking Sands');

-- Flesh'rok the Diseased <Primordial Saurok Horror>
SET @ENTRY := 70429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139314,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,22000,11,139315,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,139311,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzied Consumption at 40% HP');

-- Fungal Growth
SET @ENTRY := 70153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140620,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungi Spores'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,140626,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grow at 40% HP');

-- Gastropod
SET @ENTRY := 68220;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,134415,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devoured');

-- Greater Cave Bat
SET @ENTRY := 69351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,136753,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slashing Talons'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,136751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Screech on Close');

-- Gurubashi Berserker
SET @ENTRY := 69916;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,138427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserker Frenzy at 30% HP');

-- Gurubashi Berserker
SET @ENTRY := 69905;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,138427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserker Frenzy at 30% HP');

-- Hidden Fog
SET @ENTRY := 69375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,137152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harsh Light'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,136837,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impact on Close');

-- Lightning Guardian <The Emperor's Shield>
SET @ENTRY := 69834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,138196,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Burst'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,140296,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conductive  Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,140296,1,15000,30000,11,140296,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conductive  Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,138187,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Storm');

-- Manchu <Disciple of Iron Qon>
SET @ENTRY := 70202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139803,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Triumphant Rush'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,139797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wild Smash on Close');

-- Mist Lurker
SET @ENTRY := 70594;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140682,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Choking Mists'),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,10000,22000,11,140684,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrosive Breath');

-- Monara <The Last Queen>
SET @ENTRY := 70440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Torment'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,139899,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');

-- Muckbat
SET @ENTRY := 70232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139309,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Muck Spit');

-- No'ku Stormsayer <Lord of Tempest>
SET @ENTRY := 70276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139508,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Conductivity'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,139487,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunder-Blessed Weapon on Spawn'),
(@ENTRY,0,2,0,9,0,100,0,0,3,15000,25000,11,139468,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Fissure on Close'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,18000,22000,11,139402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Waves of Fury');

-- Putrid Waste
SET @ENTRY := 70219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Putrify');

-- Quet'zal <The Stormcaller>
SET @ENTRY := 68080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,136192,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Storm');

-- Ritual Guard
SET @ENTRY := 70179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139215,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,137998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');

-- Roaming Fog
SET @ENTRY := 68313;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,25000,11,134668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gnawed Upon'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,20000,22000,11,134656,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scanning on Spawn');

-- Rocky Horror
SET @ENTRY := 70430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Throw Stalactite'),
(@ENTRY,0,1,0,9,0,100,0,0,30,15000,25000,11,140676,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tremor Stomp on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,140673,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Horrifying Roar at 40% HP');

-- Rotting Scavenger
SET @ENTRY := 70224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139314,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,22000,11,139315,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,139311,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzied Consumption at 40% HP');

-- Shale Stalker
SET @ENTRY := 70587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140616,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shale Shards');

-- Shan'ze Celestial Shaper <Hand of Shan Bu>
SET @ENTRY := 70240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139771,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Lash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,139772,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cosmic Strike');

-- Skittering Spiderling
SET @ENTRY := 70227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,139310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Foul Venom');

-- Soul-Fed Construct
SET @ENTRY := 70308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,139895,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spiritfire Beam');

-- Stormbringer Draz'kil
SET @ENTRY := 70445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,139903,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,139900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stormcloud');

-- Thunder Lord <The Emperor's Shield>
SET @ENTRY := 69821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,138196,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Burst'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,140296,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conductive  Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,140296,1,15000,30000,11,140296,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conductive  Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,138187,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Storm');

-- Tormented Spirit
SET @ENTRY := 70341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,50,15000,25000,11,139550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Torment on Close');

-- Untrained Quilen
SET @ENTRY := 70209;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,121190,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,122962,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');

-- Untrained Quilen
SET @ENTRY := 70206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,121190,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,122962,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');

-- Vampiric Cave Bat
SET @ENTRY := 69352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,135103,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drain the Weak on Spawn');

-- Vampiric Cave Bat
SET @ENTRY := 68497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,135103,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drain the Weak on Spawn');

-- Weisheng <Disciple of Iron Qon>
SET @ENTRY := 70205;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,139815,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Triumphant Roar at 40% HP');

-- Zandalari Blade Initiate
SET @ENTRY := 70230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140049,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wounding Strike');

-- Zandalari High Priest
SET @ENTRY := 69906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,150000,40,15000,18000,11,139228,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Light of the Loa on Friendlies');

-- Zandalari Prelate
SET @ENTRY := 69927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,150000,40,15000,18000,11,139228,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Light of the Loa on Friendlies'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,139223,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgment of the Loa'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,139212,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of the Loa on Spawn');

-- Zandalari Prophet
SET @ENTRY := 70557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140400,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mark of the Prophet'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,140115,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Visions of Demise on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,139205,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Visions of Grandeur at 40% HP');

-- Zandalari Spear-Shaper
SET @ENTRY := 69388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,137077,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spear Spin on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,137096,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserking at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,136986,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Throw Spear'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,137072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retrieve Spear on Aggro');

-- Zandalari Storm-Caller
SET @ENTRY := 69390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3000,11,139231,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,65,22000,25000,11,139218,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Storm Weapon at 65% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,139206,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Focused Lightning');

-- Zandalari Storm-Caller
SET @ENTRY := 70236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3000,11,139231,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,65,22000,25000,11,139218,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Storm Weapon at 65% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,139206,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Focused Lightning');

-- Zandalari Warlord
SET @ENTRY := 69911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,140414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,140422,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Strength of the Loa'),
(@ENTRY,0,2,0,9,0,100,0,0,15,15000,25000,11,134856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Zandalari Warcry on Close');

-- Zandalari Water-Binder
SET @ENTRY := 69455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,136952,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt');

-- Zao'cho <The Emperor's Shield>
SET @ENTRY := 69843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138235,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Electro Pulse');