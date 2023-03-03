-- Abyss Watcher
SET @ENTRY := 113043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Glare'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,224974,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infinite Abyss'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Acidmaw Scorpid
SET @ENTRY := 103225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,205289,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Boon of the Scorpid at 40% HP');

-- Arcane Enchantment
SET @ENTRY := 107287;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,213808,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burst of Magic on Spawn');

-- Ariadne
SET @ENTRY := 115847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,15000,20000,11,230377,64,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wailing Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,230379,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shriek'),
(@ENTRY,0,2,0,2,0,100,0,0,55,10000,10000,11,230247,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Coalesce Souls at 55% HP');

-- Astral Defender
SET @ENTRY := 112638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224205,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcing Shatter'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,211064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,9,0,100,0,0,60,15000,25000,11,224181,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stellar Crush on Close');

-- Astral Farseer
SET @ENTRY := 111170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,221487,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call to the Stars'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,221487,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call to the Stars at 40% HP');

-- Astrologer Jarin
SET @ENTRY := 112803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,224632,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavenly Crash'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,224560,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Celestial Brand'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,211064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Attendant Keeper
SET @ENTRY := 116185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224483,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Azagrim
SET @ENTRY := 105295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,208672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Wave'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,212625,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Focused Assault at 40% HP');

-- Beltheris
SET @ENTRY := 107232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,208672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Wave'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,212625,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Focused Assault at 40% HP');

-- Burning Ember
SET @ENTRY := 104262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,209017,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felblast');

-- Celestial Acolyte
SET @ENTRY := 112655;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,211064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,224246,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arc Well'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,224229,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Decide Fate at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3000,3500,11,224378,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Luminous Bolt');

-- Chaos Mage Beleron
SET @ENTRY := 111225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221464,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chaotic Energies');

-- Chaotoid
SET @ENTRY := 111075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221158,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Release the Void');

-- Chronowraith
SET @ENTRY := 113307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mass Siphon'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP');

-- Crystalline Scorpid
SET @ENTRY := 103217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,204766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Energy Surge'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,205289,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Boon of the Scorpid at 40% HP');

-- Crystalline Scorpid
SET @ENTRY := 108361;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,204766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Energy Surge'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,205289,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Boon of the Scorpid at 40% HP');

-- D'zorykx the Trapper
SET @ENTRY := 104534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,206883,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Vortex');

-- Dalvengyr
SET @ENTRY := 107233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,208672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Wave'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,212625,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Focused Assault at 40% HP');

-- Domesticated Manasaber
SET @ENTRY := 111295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225857,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Wound');

-- Doomlash
SET @ENTRY := 115853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231454,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vine Lash');

-- Dreadguard
SET @ENTRY := 113052;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattered Will'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,224995,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Suppression'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Duskwatch Battle-Magus
SET @ENTRY := 112671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224511,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arc Blade'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,224510,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crackling Slice'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Duskwatch Sentinel
SET @ENTRY := 112675;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224483,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Duskwatch Warden
SET @ENTRY := 112596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225851,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Force Repel');

-- Duskwatch Weaver
SET @ENTRY := 112973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,225845,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chosen Fate at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,225804,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pillars of Night');

-- Ebulliant
SET @ENTRY := 111112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221209,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burst');

-- Exotic Concubine
SET @ENTRY := 116230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231303,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Love Tap'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,231300,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph');

-- Expedient Elemental
SET @ENTRY := 105301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,209568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exothermic Release');

-- Fel Lord Kuraz'mal
SET @ENTRY := 104537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,206675,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shatter Essence');

-- Felblaze Trickster
SET @ENTRY := 111554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,222156,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felblast');

-- Felsworn Chaos-Mage
SET @ENTRY := 113012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,211571,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,224943,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Eradication'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn'),
(@ENTRY,0,4,0,9,0,100,0,0,15,15000,25000,11,224944,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Will of the Legion on Close');

-- Felsworn Shadowblade
SET @ENTRY := 113013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Felsworn Spellguard
SET @ENTRY := 108591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,216024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Volatile Wound'),
(@ENTRY,0,1,0,9,0,100,0,0,25,15000,25000,11,216028,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Pursuit on Close'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Felweaver Pharamere
SET @ENTRY := 111227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infernal Blade'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,22000,11,222101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Seed of Flame');

-- Fiery Enchantment
SET @ENTRY := 107285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,213760,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burst of Flame');

-- Fragmented Time Particle
SET @ENTRY := 114671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,219808,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chronomate'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,228335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warp Nightwell');

-- Fulminant
SET @ENTRY := 111081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scatter');

-- Gilded Guardian <Spellblade's Construct>
SET @ENTRY := 112712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224440,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Stomp'),
(@ENTRY,0,1,0,2,0,100,0,0,65,22000,25000,11,225927,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gravity Well at 65% HP'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,224436,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Arcburst on Death');

-- Ice Shards
SET @ENTRY := 107592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,213621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entombed in Ice');

-- Icy Enchantment
SET @ENTRY := 107237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,213796,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burst of Ice');

-- Infinite Drakeling
SET @ENTRY := 108802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,216134,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infinite Breath');

-- Inquisitor Vethriz
SET @ENTRY := 104536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,207006,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Blast'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,206840,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gaze of Vethriz at 40% HP');

-- Kar'zun
SET @ENTRY := 116008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231174,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Languor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,231005,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Emanations'),
(@ENTRY,0,2,0,9,0,100,0,0,40,15000,25000,11,230994,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Wrap on Close');

-- Kirin Tor Guardian
SET @ENTRY := 113605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Kirin Tor Guardian
SET @ENTRY := 113608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Lalathin <Elisande's Pet>
SET @ENTRY := 121540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Ly'leth Lunastre
SET @ENTRY := 117085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Nether Elemental
SET @ENTRY := 111151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,222216,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Overcharge');

-- Nightborne Sage
SET @ENTRY := 111303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,25000,40,15000,18000,11,225809,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Time Reversal on Friendlies'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,225809,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Time Reversal at 40% HP'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,225825,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Astral Anomaly on Aggro');

-- Nighthold Protector
SET @ENTRY := 112665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224570,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charged Smash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,224568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mass Suppress'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Nightorb
SET @ENTRY := 111054;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,206912,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Capricious Barrage');

-- Nightwell Diviner
SET @ENTRY := 116395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231737,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Nightwell Discharge'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3000,3500,11,224515,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warped Blast');

-- Nobleborn Warpcaster
SET @ENTRY := 112676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231737,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Nightwell Discharge'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,211064,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3000,3500,11,224515,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warped Blast'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,224488,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reverse Wounds at 40% HP'),
(@ENTRY,0,4,0,14,0,100,0,25000,40,15000,18000,11,224488,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Reverse Wounds on Friendlies');

-- Promenade Guard
SET @ENTRY := 112709;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Putrid Sludge
SET @ENTRY := 112251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,223528,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Sludge'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,214181,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slop Burst'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,223601,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Slime Pool on Death');

-- Putrid Sludge
SET @ENTRY := 113512;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,223528,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Sludge'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,214181,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slop Burst'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,223601,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Slime Pool on Death');

-- Recursive Elemental
SET @ENTRY := 105299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,221864,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blast');

-- Resolute Courtesan
SET @ENTRY := 111166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,16,0,100,0,221521,100,60000,65000,11,221521,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Protect on Friendlies Missing Buff');

-- Searing Infernal
SET @ENTRY := 104596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221333,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Annihilating Orb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,20000,10000,22000,11,221270,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Consuming Flame');

-- Shadescale Wyrm
SET @ENTRY := 112955;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,211476,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nether Spike');

-- Shal'dorei Archmage
SET @ENTRY := 112595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225105,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcanic Release'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,225800,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Time Warp at 40% HP');

-- Shal'dorei Naturalist
SET @ENTRY := 112678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,225855,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,1,0,9,0,100,0,0,6,15000,25000,11,225859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torrent of Water on Close'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,225858,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Poison Brambles');

-- Shambling HungererShambling Hungerer
SET @ENTRY := 113321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Shimmering Manaspine
SET @ENTRY := 112956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,225840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shimmering Reflection on Spawn');

-- Sidereal Familiar
SET @ENTRY := 112718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,224387,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Starstrike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,224390,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arc Bomb');

-- Sightless Watcher
SET @ENTRY := 108593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,216040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Soul');

-- Sludgerax
SET @ENTRY := 112255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,223710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bursting Slime'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223655,2,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Oozing Rush at 40% HP');

-- Tainted Blood
SET @ENTRY := 108934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,206893,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Spawn');

-- Terrace Grove-Tender
SET @ENTRY := 112603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225052,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prune'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,225047,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shrink'),
(@ENTRY,0,3,0,16,0,100,0,225043,30,22000,25000,11,225043,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Grow on Friendlies Missing Buff'),
(@ENTRY,0,4,0,2,0,100,0,0,30,22000,25000,11,225043,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grow at 40% HP');

-- Torm the Brute
SET @ENTRY := 115914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231086,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,230438,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastating Strike'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,230482,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rumbling Blow on Close');

-- Tower Concubine
SET @ENTRY := 116158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,231303,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Love Tap'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,231300,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph');

-- Trained Shadescale
SET @ENTRY := 112804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225404,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,2,0,100,0,0,25,22000,25000,11,226005,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blink at 25% HP');

-- Twilight Stardancer
SET @ENTRY := 111164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweeping Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,221591,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swing Weapon'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,221589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Focused on Spawn');

-- Volatile Scorpid
SET @ENTRY := 108359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,204733,3,0,0,0,0,0,2,0,0,0,0,0,0,'Cast Volatile Chitin on Death'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,204697,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scorpid Swarm at 40% HP');

-- Waning Time Particle
SET @ENTRY := 104676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,219808,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chronomate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,207228,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warp Nightwell at 40% HP');

-- Wily Sycophant
SET @ENTRY := 116159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,215241,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Bolt'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone');

-- Withered Skulker
SET @ENTRY := 113128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,225410,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Withering Volley'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,15000,11,211037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Celerity Zone'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,225407,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mournful Howl');