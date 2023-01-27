-- Abyssion
SET @ENTRY := 44289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,82876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Breath'),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,15000,18000,11,82878,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rift Barrage'),
(@ENTRY,0,2,0,9,0,100,0,0,50,15000,25000,11,82883,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Nova on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,84052,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Shield at 40% HP');

-- Aeosera <Stone Dragon Broodmother>
SET @ENTRY := 43641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,84448,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Searing Breath');

-- Agitated Tunneler
SET @ENTRY := 43031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,10,40,15000,25000,11,80563,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Rupture on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,80453,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gravel Blast');

-- Avalanchion <Elemental Lord>
SET @ENTRY := 44372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,81147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder on Aggro'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,79872,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave on Close'),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,12000,15000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,17000,22000,11,80117,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Earth Spike');

-- Boldrich Stonerender
SET @ENTRY := 42923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,16000,18000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Boomshroom
SET @ENTRY := 43501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,11,81319,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Boomshroom Explosion on Spawn'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn on Cast Boomshroom Explosion');

-- Bouldergut <Stone Trogg Chieftain>
SET @ENTRY := 44151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,8,25,15000,25000,11,83015,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Leap on Close'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam');

-- Bound Air Elemental
SET @ENTRY := 44885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,22000,11,83004,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Storm Cloud');

-- Bound Fire Elemental
SET @ENTRY := 44887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rush of Flame');

-- Bound Water Elemental
SET @ENTRY := 44886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,39207,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Spout');

-- Corestone of Patience
SET @ENTRY := 53894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82841,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rock Bash');

-- Deepstone Elemental
SET @ENTRY := 43026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82841,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rock Bash'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,82839,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hardened at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,30000,30000,45000,45000,11,82840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vulnerable');

-- Defaced Earthrager
SET @ENTRY := 44076;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,86725,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Upheaved Earth on Close');

-- Desecrated Earthrager
SET @ENTRY := 44683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,86725,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Upheaved Earth on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,86867,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Torment of the Sundered Earth at 40% HP');

-- Doomshroom
SET @ENTRY := 43388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,50542,3,0,0,0,0,0,7,0,0,0,0,0,0,'Cast Poison Cloud on Death');

-- Dormant Stonebound Elemental
SET @ENTRY := 43115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82841,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rock Bash'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,82839,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hardened at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,30000,30000,45000,45000,11,82840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vulnerable');

-- Dragul Giantbutcher
SET @ENTRY := 42921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86816,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Giant\'s Bane');

-- Earthcaller Yevaa
SET @ENTRY := 44646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,31765,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,31765,1,15000,30000,11,31765,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat');

-- Earthen Geomancer
SET @ENTRY := 43170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,34828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water  Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,34828,1,15000,30000,11,34828,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water  Shield on Repeat'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,79890,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

-- Earthen Ring Shaman
SET @ENTRY := 44998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,11986,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 40% HP');

-- Earthguard Sentinel <The Earthen Ring>
SET @ENTRY := 42792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,78154,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Earthmender Norsala <The Earthen Ring>
SET @ENTRY := 43514;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79949,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water  Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,79949,1,15000,30000,11,79949,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water  Shield on Repeat');

-- Elemental Overseer
SET @ENTRY := 45084;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2500,3500,11,86798,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystalline Missiles');

-- Emerald Colossus
SET @ENTRY := 44218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,19000,11,86639,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Emerald Rain'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86610,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystalline Kick');

-- Energized Geode
SET @ENTRY := 43254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,15000,25000,11,86800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wild Energy on Close');

-- Enormous Gyreworm
SET @ENTRY := 48533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,90625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike');

-- Exhausted Earthguard Sentinel <The Earthen Ring>
SET @ENTRY := 42779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,78154,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Feldspar the Eternal
SET @ENTRY := 43358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,25000,11,29326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,35235,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Osmosis at 40% HP');

-- Fungal Behemoth
SET @ENTRY := 42475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,32065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,86574,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shroom Stomp on Close');

-- Fungal Monstrosity
SET @ENTRY := 44035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,35244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Choking Vines');

-- Fungal Terror
SET @ENTRY := 43954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,35244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Choking Vines');

-- Fungalmancer Glop
SET @ENTRY := 43372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,81320,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Boomshroom'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,60000,65000,11,81304,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Evolution on Spawn');

-- Golgarok <The Crimson Shatterer>
SET @ENTRY := 50059;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,22000,11,86861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earthquake'),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,10000,12000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Gorged Gyreworm
SET @ENTRY := 44259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,9591,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike');

-- Gorged Gyreworm
SET @ENTRY := 42766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,9591,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike');

-- Gorgonite
SET @ENTRY := 43339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Flash');

-- Gorsik the Tumultuous
SET @ENTRY := 43810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11130,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,51334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash');

-- Greater Quicksilver Ooze
SET @ENTRY := 44988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Gyreworm
SET @ENTRY := 44257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike');

-- Hargoth Dimblaze <The Earthen Ring>
SET @ENTRY := 42788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,78154,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Hargoth Dimblaze <The Earthen Ring>
SET @ENTRY := 44675;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,78154,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- High Priestess Lorthuna
SET @ENTRY := 43837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,83596,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,18000,22000,11,83598,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,18000,18000,11,83597,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley');

-- Irestone Rumbler
SET @ENTRY := 42780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,23114,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');

-- Irestone Rumbler
SET @ENTRY := 42527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,30,15000,25000,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Rock on Close');

-- Jade Rager
SET @ENTRY := 44220;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86606,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rumbling Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,18000,11,79872,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave');

-- Jadecrest Basilisk
SET @ENTRY := 43981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16000,19000,11,86581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrifying Gaze');

-- Jaspertip Borer
SET @ENTRY := 42524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flayer Flurry');

-- Jaspertip Crystal-gorger
SET @ENTRY := 43171;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80585,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro');

-- Jaspertip Ravager
SET @ENTRY := 42525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80585,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86571,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shale Flurry');

-- Jaspertip Swarmer
SET @ENTRY := 42521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80585,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro');

-- Living Blood
SET @ENTRY := 43123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,31281,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,86808,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Boiling Effusion on Close');

-- Lodestone Elemental
SET @ENTRY := 43258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86804,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magnetic Attraction on Aggro'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,86806,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Repulsion Field on Close');

-- Ma'haat the Indomitable
SET @ENTRY := 42470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,50084,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hulking Uppercut');

-- Magmatooth <Initiate Goldmine's Fire Elemental>
SET @ENTRY := 45099;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,83018,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magma Wave'),
(@ENTRY,0,2,0,0,0,100,0,7000,7000,20000,25000,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rush of Flame');

-- Millhouse Manastorm <The Forgemaster>
SET @ENTRY := 44875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn');

-- Mor'norokk the Hateful
SET @ENTRY := 42801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,20000,11,22678,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,12000,15000,11,32063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption');

-- Murkstone Trogg
SET @ENTRY := 44936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,16000,17000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,85867,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Troglodyte Smash');

-- Needlerock Mystic
SET @ENTRY := 43995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,13860,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,2,0,3,0,100,0,0,40,22000,25000,11,79811,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dispersion at 40% HP'),
(@ENTRY,0,3,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(@ENTRY,0,4,0,7,0,100,1,0,0,0,0,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Evade');

-- Needlerock Pummeller
SET @ENTRY := 43847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,19000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Needlerock Rider
SET @ENTRY := 43250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,85867,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Troglodyte Smash');

-- Ogre Bodyguard
SET @ENTRY := 44879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3500,4100,11,79883,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Throw'),
(@ENTRY,0,3,0,0,0,100,0,4000,4000,10000,20000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,4,0,2,0,100,0,0,40,22000,25000,11,79878,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Opal Stonethrower
SET @ENTRY := 43586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,15,150,15000,25000,11,81632,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Boulder on Close');

-- Opal Stonethrower
SET @ENTRY := 44124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,15,150,15000,25000,11,82547,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Boulder on Close');

-- Porecite the Silent
SET @ENTRY := 43356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,38621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fist of Stone at 40% HP');

-- Raging Crystal-walker
SET @ENTRY := 43373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,80835,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thundering Stomp on Close');

-- Rockslice Flayer
SET @ENTRY := 42606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flayer Flurry');

-- Rockslice Ripper
SET @ENTRY := 42607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80585,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,33912,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip');

-- Scalesworn Cultist
SET @ENTRY := 44221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Blood');

-- Servant of Therazane
SET @ENTRY := 42479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,15,15000,25000,11,85855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Quake on Close');

-- Shalehide Basilisk
SET @ENTRY := 43181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrifying Gaze');

-- Son of Kor
SET @ENTRY := 43101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,20000,11,80618,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Colossal Sweep'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,80613,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crushing Stomp on Close'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,84769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hurl Boulder on Aggro'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,49676,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Fist at 40% HP');

-- Stone Drake
SET @ENTRY := 42522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,96134,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,25000,11,32914,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Stone Trogg Ambusher
SET @ENTRY := 43134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,22000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Stone Trogg Beast Tamer
SET @ENTRY := 43598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,22910,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Trap'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,10000,20000,11,52080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Crack');

-- Stone Trogg Berserker
SET @ENTRY := 43228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,79878,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Stone Trogg Digger
SET @ENTRY := 43174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dirt Toss');

-- Stone Trogg Earthrager
SET @ENTRY := 43616;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,22000,11,86861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earthquake'),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,25000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Stone Trogg Fungalmancer
SET @ENTRY := 47184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,32065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,86574,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shroom Stomp on Close');

-- Stone Trogg Geomancer
SET @ENTRY := 43234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,32734,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,32734,1,15000,30000,11,32734,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,79886,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst');

-- Stone Trogg Rockmagus
SET @ENTRY := 43652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,32734,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,32734,1,15000,30000,11,32734,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,81305,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rock Barrage');

-- Stonehearth Defender
SET @ENTRY := 43138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,79872,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave');

-- Stonescale Drake
SET @ENTRY := 43971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,83861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Spike');

-- Stonescale Matriarch
SET @ENTRY := 44148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,83861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Spike'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,85802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sand Breath on Close');

-- Temperamental Rumbler
SET @ENTRY := 43480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,30,15000,25000,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Rock on Close');

-- Terborus
SET @ENTRY := 50060;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79927,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth  Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,79927,1,15000,30000,11,79927,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth  Shield on Repeat'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bore');

-- Terrath the Steady
SET @ENTRY := 42614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Troggzor the Earthinator <Stone Trogg Battle Leader>
SET @ENTRY := 43456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,96127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,81317,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Rumble'),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,25000,11,32133,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupted Earth on Close'),
(@ENTRY,0,3,0,9,0,100,0,0,10,10000,20000,11,81276,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dust Devil on Close');

-- Twilight Armsman
SET @ENTRY := 44847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,79878,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Twilight Binder
SET @ENTRY := 44619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,79880,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow'),
(@ENTRY,0,3,0,0,0,100,0,4000,10000,10000,19000,11,79868,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast');

-- Twilight Bloodshaper
SET @ENTRY := 43218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,38027,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boiling Blood on Close');

-- Twilight Bloodsmith
SET @ENTRY := 45988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Twilight Centurion
SET @ENTRY := 44649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,5000,8000,20000,30000,11,82800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,19000,22000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Twilight Crusher
SET @ENTRY := 44849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam on Close');

-- Twilight Cryptomancer
SET @ENTRY := 44855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79854,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,79857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Twilight Defiler
SET @ENTRY := 44680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,3900,6900,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,1,0,2,0,100,0,0,70,22000,25000,11,80576,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 70% HP');

-- Twilight Dragonspawn
SET @ENTRY := 43966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86584,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phased Armor');

-- Twilight Dragonstalker
SET @ENTRY := 43992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,3,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(@ENTRY,0,4,0,7,0,100,1,0,0,0,0,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Evade');

-- Twilight Duskwarden
SET @ENTRY := 42917;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,32916,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,86817,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Ward at 40% HP');

-- Twilight Duskwarden
SET @ENTRY := 43039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,32916,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,86817,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Ward at 40% HP');

-- Twilight Heretic
SET @ENTRY := 44681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,32063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption');

-- Twilight Laborer
SET @ENTRY := 42924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38557,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,16000,11,58461,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close');

-- Twilight Priestess
SET @ENTRY := 42823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,31516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,16588,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Mending at 40% HP');

-- Twilight Pyremaw
SET @ENTRY := 44189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86819,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Breath');

-- Twilight Pyremaw
SET @ENTRY := 42824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,36513,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intangible Presence'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,16000,19000,11,36631,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Netherbreath');

-- Twilight Saboteur
SET @ENTRY := 42885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,31516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,11639,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

-- Twilight Scalesister
SET @ENTRY := 43967;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,15000,25000,11,86585,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Flames on Close');

-- Twilight Soulreaper
SET @ENTRY := 42916;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,20000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,86728,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Tear at 40% HP');

-- Verlok Basilisk Rider
SET @ENTRY := 42711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,54431,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Spear'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,81314,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spore Cloud on Close');

-- Verlok Grubthumper
SET @ENTRY := 43367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,85867,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Troglodyte Smash');

-- Verlok Pillartumbler
SET @ENTRY := 43513;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close');

-- Verlok Shroomtender
SET @ENTRY := 43368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,83796,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Craze at 40% HP');

-- War Construct
SET @ENTRY := 43871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,15000,25000,11,82120,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Smash on Close');

-- Young Stone Drake
SET @ENTRY := 44038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,11985,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Yuldris Smolderfury <The Earthen Ring>
SET @ENTRY := 44371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,78154,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP');

-- Zoltrik Drakebane
SET @ENTRY := 42918;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86717,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drake\'s Bane'),
(@ENTRY,0,2,0,9,0,100,0,0,60,15000,25000,11,82589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Choking Smoke Bombs on Close');

-- Zoltrik Drakebane
SET @ENTRY := 44135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,86717,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drake\'s Bane'),
(@ENTRY,0,2,0,9,0,100,0,0,60,15000,25000,11,82589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Choking Smoke Bombs on Close');
