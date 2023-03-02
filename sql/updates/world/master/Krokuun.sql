-- Abyssal Annihilator
SET @ENTRY := 125850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,252010,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Emanations'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,252013,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Aura on Spawn');

-- Acherus Death Knight
SET @ENTRY := 111694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222418,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heart Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,222791,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anti-Magic Zone at 40% HP');

-- Aethas Sunreaver
SET @ENTRY := 121359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,242918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Searing Beam');

-- Aggonar <King of the Pits>
SET @ENTRY := 119397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,244623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,40,40000,45000,11,254448,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Ward at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,30000,11,241185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grip of the Pit King');

-- Alleria Windrunner
SET @ENTRY := 120913;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,241006,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,241549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deteriorate');

-- Ancient Duskcloak
SET @ENTRY := 130943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,188353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dusk Shroud at 40% HP');

-- Annihilan Fanatic
SET @ENTRY := 120723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,65,10000,10000,11,251031,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Encroaching Shadows at 65% HP');

-- Annihilan Warden
SET @ENTRY := 120704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,20,15000,25000,11,251042,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Rush on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Clip');

-- Antaen Light-Breaker
SET @ENTRY := 120361;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250863,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reckless Stomp'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,250880,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felshock Bombardment');

-- Archmage Khadgar
SET @ENTRY := 119538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,223329,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt');

-- Argus Darkray
SET @ENTRY := 124279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chomp'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,251719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shriek');

-- Blazing Felshard
SET @ENTRY := 125109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251993,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Burn'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,251995,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Felshard Explosion on Death');

-- Burning Fiend
SET @ENTRY := 120637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251022,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,244975,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Flames on Spawn'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,245115,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Vile Rupture on Death');

-- Burning Fiend
SET @ENTRY := 120914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251022,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP');

-- Captured Krokul
SET @ENTRY := 122837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,244978,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul Absorbed on Spawn');

-- Caustic Overflow
SET @ENTRY := 123513;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Caustic Leakage');

-- Chitinous Cragscaler
SET @ENTRY := 124225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251894,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,251920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251892,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Chitin at 40% HP');

-- Chitinous Cragscaler
SET @ENTRY := 124265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251894,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,251920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251892,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Chitin at 40% HP');

-- Citadel Dreadguard
SET @ENTRY := 121536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251159,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Punishing Crash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251155,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Wave');

-- Commander Endaxis
SET @ENTRY := 124775;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutish Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,250963,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overpowering Flurry'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251245,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Inspiration at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,60,22000,25000,11,250962,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Crush at 60% HP');

-- Commander Sathrenael
SET @ENTRY := 122912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251317,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Imperious Beam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251302,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Colossal Blowback');

-- Commander Vecaya
SET @ENTRY := 122911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251265,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Backdraft'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251276,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sundering Crash');

-- Defias Thief
SET @ENTRY := 111254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221792,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,221512,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,9,0,100,0,0,15,15000,25000,11,221515,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,203343,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smoke Bomb at 40% HP');

-- Dreamgrove Protector
SET @ENTRY := 119077;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221792,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,221512,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,9,0,100,0,0,15,15000,25000,11,221515,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,203343,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smoke Bomb at 40% HP');

-- Druid of the Claw
SET @ENTRY := 109839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,218605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bear Form on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,218803,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fury of the Bearmantle');

-- Duskcloak Alpha
SET @ENTRY := 123076;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,188353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dusk Strike'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dusk Shroud at 40% HP');

-- Duskcloak Panthara
SET @ENTRY := 124303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,188353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dusk Shroud at 40% HP');

-- Earthcaller
SET @ENTRY := 109448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,218170,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Lash');

-- Ebon Death Knight
SET @ENTRY := 121409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222418,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heart Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,222791,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anti-Magic Zone at 40% HP');

-- Eredar Acolyte
SET @ENTRY := 123130;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3500,11,251028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Blast');

-- Eredar Conqueror
SET @ENTRY := 120395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutish Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,250963,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overpowering Flurry'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251245,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Inspiration at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,60,22000,25000,11,250962,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Crush at 60% HP');

-- Eredar Conqueror
SET @ENTRY := 122924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutish Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,250963,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overpowering Flurry'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251245,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Inspiration at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,60,22000,25000,11,250962,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Crush at 60% HP');

-- Eredar Overseer
SET @ENTRY := 124670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,20,15000,25000,11,251042,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Rush on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Clip');

-- Eredar Soulshaper
SET @ENTRY := 122835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3500,11,251028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,247329,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Ur\'zul on Close');

-- Farseer Nobundo <The Earthen Ring>
SET @ENTRY := 109455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,218013,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,217938,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Surge at 40% HP'),
(@ENTRY,0,2,0,16,0,100,0,217924,40,22000,25000,11,217924,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Riptide on Friendlies Missing Buff');

-- Fel Secretion
SET @ENTRY := 123509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,251326,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Fel Expulsion on Death');

-- Fel-Lusted Wyrmtongue
SET @ENTRY := 124959;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251322,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Flurry'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,248479,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel-Lust at 40% HP');

-- Felbound Drudge
SET @ENTRY := 123085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,221332,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Leokk\'s Insight on Spawn');

-- Felbound Scholar
SET @ENTRY := 122942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251044,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Fel Rune');

-- Felflame Scavenger
SET @ENTRY := 120638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Chomp');

-- Felforge Salvager
SET @ENTRY := 123241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251164,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Concoctions');

-- Felforge Salvager
SET @ENTRY := 127942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251164,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Concoctions');

-- Felscarred Destroyer
SET @ENTRY := 121531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutish Slam'),
(@ENTRY,0,1,0,2,0,100,0,0,60,22000,25000,11,250962,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Crush at 60% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251245,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Inspiration at 40% HP');

-- Felscarred Marsuul
SET @ENTRY := 124278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251723,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tackle'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,251737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro');

-- Felsiege Champion
SET @ENTRY := 119597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250925,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Crash'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250929,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Fel on Close');

-- Felsiege Champion
SET @ENTRY := 120322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250925,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Crash'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250929,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Fel on Close');

-- Felsiege Champion
SET @ENTRY := 123418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250925,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Crash'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250929,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Fel on Close');

-- Felsiege Champion
SET @ENTRY := 123422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250925,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Crash'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250929,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Fel on Close');

-- Felsiege Doomcaller
SET @ENTRY := 119533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250934,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grand Immolation on Close');

-- Felsiege Doomcaller
SET @ENTRY := 122922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250934,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grand Immolation on Close');

-- Felsiege Doomcaller
SET @ENTRY := 123420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250934,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grand Immolation on Close');

-- Felsiege Doomcaller
SET @ENTRY := 123421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250934,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grand Immolation on Close');

-- Felsiege Infernal
SET @ENTRY := 119395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,245377,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Assault'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,233004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Aura on Spawn'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP'),
(@ENTRY,0,3,0,9,0,100,0,0,10,15000,25000,11,205259,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Hellfire on Close');

-- Foebreaker Vanguard
SET @ENTRY := 121548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251166,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Downward Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251170,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crackling Fel'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP');

-- Garothi Obliterator
SET @ENTRY := 120354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251921,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obliterating Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251924,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Mortars');

-- Gnoll
SET @ENTRY := 116355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221792,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,221512,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,9,0,100,0,0,15,15000,25000,11,221515,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,203343,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smoke Bomb at 40% HP');

-- Gorrexus
SET @ENTRY := 123514;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,18000,11,251411,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call of Flames'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,251414,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felflame Aura on Spawn');

-- High Inquisitor Raalgar
SET @ENTRY := 121544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,203373,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Expulse Shadows'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,254265,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Entropy'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,248022,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Heart Bond at 40% HP');

-- High Vindicator <Hand of Argus>
SET @ENTRY := 126206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Aggro');

-- Highguard Captain
SET @ENTRY := 123658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254292,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Descent'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,254293,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Frenzy at 40% HP');

-- Highguard Warrior
SET @ENTRY := 121575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254306,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Crush'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,252463,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Sundering');

-- Highguard Watcher
SET @ENTRY := 123659;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Watcher\'s Strike'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,254323,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Hatchet');

-- Hunting Soulseeker
SET @ENTRY := 125146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183263,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251488,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Spew');

-- Igneous Crusher
SET @ENTRY := 125103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251969,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Abyssal Smash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251972,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Emission at 40% HP');

-- Illidari Adept
SET @ENTRY := 111962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223061,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Aura at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,223903,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Metamorphosis at 30% HP');

-- Imp Mother Laglath
SET @ENTRY := 125820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,22000,25000,11,251689,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Matron\'s Rage'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,251683,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elder\'s Wrath on Close'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3000,3500,11,251703,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath Bolt');

-- Iron Dwarf
SET @ENTRY := 111914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222926,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Titanic Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,223130,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Titanic Smash');

-- Kar'aaz
SET @ENTRY := 120602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,244623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,40,40000,45000,11,247925,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felshard Meteors at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,30000,11,251100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Erupting Crack');

-- Khazaduum
SET @ENTRY := 125824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251473,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251470,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infernal Smash');

-- Kirin Tor Invoker
SET @ENTRY := 110715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,220138,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,106740,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Lance');

-- Krokul Ridgestalker
SET @ENTRY := 120476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,150250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,150250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Krokul Ridgestalker
SET @ENTRY := 125058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,150250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,150250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Krokul Seer
SET @ENTRY := 125057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,189869,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Slash');

-- Lady Heretica
SET @ENTRY := 125115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,185493,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,251736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wave of Destruction on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,251731,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Orbs at 40% HP');

-- Lady Liadrin <Blood Knight Matriarch>
SET @ENTRY := 121418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,242702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,235877,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast of Light');

-- Lady Shahrazad
SET @ENTRY := 122834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Quad Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,251408,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Volley');

-- Legion Cannoneer
SET @ENTRY := 122039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cracking Blow');

-- Legion Laborer
SET @ENTRY := 123565;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,251462,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Wreckage');

-- Legionfall Defender
SET @ENTRY := 121413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,242702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,235877,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast of Light');

-- Lightforged Warpriest
SET @ENTRY := 121397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,242194,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire');

-- Lord Nath'raxas
SET @ENTRY := 125034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251759,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Scythe'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,25000,11,251745,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mass Fel Eruption');

-- Magraloth
SET @ENTRY := 120601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,244623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,40,40000,45000,11,254448,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Ward at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,30000,11,241185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grip of the Pit King');

-- Mistress Apostriss
SET @ENTRY := 125114;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,210537,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251743,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Oppressive Darkness'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,251739,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Winds of Torment');

-- Mo'arg Pit Boss
SET @ENTRY := 124687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251452,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pit Slag'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,251450,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crush on Close');

-- Naroua <King of the Forest>
SET @ENTRY := 126419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,252055,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ambush'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,252037,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Majestic Roar at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,252038,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sovereign\'s Tear');

-- Nath'raxxan Doomshot
SET @ENTRY := 125129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,2500,11,251943,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,251944,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Strike on Close');

-- Nath'raxxan Felguard
SET @ENTRY := 125149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,252005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Swipe');

-- Nath'raxxan Fleshcarver
SET @ENTRY := 125121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,204175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,251936,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Whirl on Close');

-- Nath'raxxan Highguard
SET @ENTRY := 125338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,252027,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Strike on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,252023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twin Felbeams');

-- Nath'raxxan Pyroclast
SET @ENTRY := 125294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251999,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Crash'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,252001,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate');

-- Nath'raxxan Soulweaver
SET @ENTRY := 126765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251203,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Tear'),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,251206,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Fel Imp on Spawn');

-- Nath'raxxan Warbringer
SET @ENTRY := 125339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,252007,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infernal Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,252008,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crashing Fissure');

-- Nathrezim Banelord
SET @ENTRY := 125139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251960,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251966,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Plague'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,251955,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Swarm');

-- Nightborne Huntress
SET @ENTRY := 119081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,235916,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arc Slash'),
(@ENTRY,0,1,0,9,0,100,0,5,40,15000,25000,11,235913,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harpoon on Close');

-- Ox Initiate
SET @ENTRY := 106812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Keg Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,173320,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spear Hand Strike');

-- Panthara Apex
SET @ENTRY := 124269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251799,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Flurry'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,251795,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,251797,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wounded Rage at 30% HP');

-- Panthara Stalker
SET @ENTRY := 124271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251799,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Flurry'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,251795,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,251797,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wounded Rage at 30% HP');

-- Quartermaster Aikras
SET @ENTRY := 123247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,251238,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shrapnel Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251225,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Fel Crystal at 40% HP');

-- Quartermistress Kl'azz
SET @ENTRY := 124015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254243,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Burning Claw'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,254342,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Bulwark at 40% HP');

-- Ravenous Soulhunter
SET @ENTRY := 125223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vile Bite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,204885,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devour Magic at 40% HP');

-- Rottgut
SET @ENTRY := 111237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,25,15000,25000,11,221525,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hook on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,223011,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Belch');

-- Scarwing Harrier
SET @ENTRY := 119604;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251058,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Seeping Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251021,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Screech');

-- Scorchwing Felspitter
SET @ENTRY := 119398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251018,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Bile'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251021,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Screech'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP');

-- Seething Harbinger
SET @ENTRY := 123109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251160,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Cross'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251161,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Fan'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP');

-- Shademistress
SET @ENTRY := 122041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,254287,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,254286,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Shade'),
(@ENTRY,0,2,0,16,0,100,0,238591,20,22000,25000,11,238591,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Bargain on Friendlies Missing Buff');

-- Shadowbound Defiler
SET @ENTRY := 123110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,65,10000,10000,11,251031,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Encroaching Shadows at 65% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,251550,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consecration at 40% HP');

-- Siegemaster Voraan
SET @ENTRY := 120393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251094,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Swing'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251096,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Blow'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,251091,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Order Bombardment at 55% HP');

-- Silgryn
SET @ENTRY := 121421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251125,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcanetic Rending');

-- Silver Hand Knight
SET @ENTRY := 111292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221647,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of the Righteous'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,221704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro');

-- Silver Hand Templar
SET @ENTRY := 111316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221719,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,221720,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm on Close');

-- Sister Subversia <Coven of Shivarra>
SET @ENTRY := 123464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,207999,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shock of the Twisting Nether'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,251283,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Come to me on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,251279,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupted Blades'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,251284,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obey at 40% HP');

-- Slavering Devourer
SET @ENTRY := 121297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254280,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Maw');

-- Soulripper Warfiend
SET @ENTRY := 121534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250947,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vile Spit'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pounce on Close');

-- Subservient Imp
SET @ENTRY := 126587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,234497,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Bolt');

-- Talestra the Vile
SET @ENTRY := 123689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,222596,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blade Barrage'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,222623,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Slash at 55% HP');

-- Tar Eater
SET @ENTRY := 125468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251330,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Oily Slap'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,251329,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spit Tar on Close');

-- Tar Spitter
SET @ENTRY := 125479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251718,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grime Smash'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,251714,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tar Expulsion on Close');

-- Tereck the Selector
SET @ENTRY := 124804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251705,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251706,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Rampage');

-- Thunder Warrior
SET @ENTRY := 121412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,242686,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Keg Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,242687,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Breath of Fire');

-- Tiger Initiate
SET @ENTRY := 106885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,22000,11,212246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brittle Statue'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,212247,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast The Golden Gaze');

-- Uncrowned Assassin
SET @ENTRY := 121415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,242488,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisoning Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,242485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,32615,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,11,32615,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Unseen Marksman
SET @ENTRY := 110456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,220017,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,219674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shot');

-- Unseen Pathfinder
SET @ENTRY := 110975;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,220877,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raptor Strike');

-- Ur'zul Devourer
SET @ENTRY := 122815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251340,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devour Essence'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251341,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unearthly Howl at 40% HP');

-- Ur'zul Devourer
SET @ENTRY := 122891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251340,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devour Essence'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,251341,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unearthly Howl at 40% HP');

-- Vagath the Betrayed
SET @ENTRY := 125388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,252065,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,252063,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Plague on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,252057,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Burst at 55% HP'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,252064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Swarm');

-- Vanguard Portal-Master
SET @ENTRY := 125151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,251203,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Tear'),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,251206,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Fel Imp on Spawn');

-- Vanguard Scout
SET @ENTRY := 125152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,20,15000,25000,11,251042,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Rush on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,251218,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tear Down');

-- Vereesa Windrunner <Ranger-General of the Silver Covenant>
SET @ENTRY := 121417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,251142,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Arrow'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,205762,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shot');

-- Vilefiend
SET @ENTRY := 119576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250947,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vile Spit'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pounce on Close'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,245115,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Vile Rupture on Death');

-- Vilefiend
SET @ENTRY := 119576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,250947,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vile Spit'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,250941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pounce on Close'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,245115,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Vile Rupture on Death');

-- Vindicator Boros
SET @ENTRY := 121410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,221647,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of the Righteous'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,221707,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Strength of the Vindicator at 40% HP');

-- Warsong Warrior
SET @ENTRY := 119064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,235693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,235692,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,235617,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rampage at 40% HP');

-- Wrathful Ember
SET @ENTRY := 125110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,251974,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flamewreathed on Spawn');

-- Xeth'tal
SET @ENTRY := 120598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,244623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,75,15000,16000,11,241985,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Felfire at 75% HP');

-- Young Duskcloak
SET @ENTRY := 124486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip');

-- Zul'cur the Ravenous
SET @ENTRY := 124452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251358,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vile Swipe'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,251355,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Foul Breath');