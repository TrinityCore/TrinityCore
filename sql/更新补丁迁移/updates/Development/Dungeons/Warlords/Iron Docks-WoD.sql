-- Bombsquad
SET @ENTRY := 80875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,163379,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Big Boom');

-- Champion Druna
SET @ENTRY := 81603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,166923,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Barbed Arrow Barrage'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,173091,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Champion\'s Presence at 30% HP');

-- Dreadfang <Fleshrender Nok'gar's Mount>
SET @ENTRY := 81297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,164734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Swipes'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,164837,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Savage Mauling'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164835,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodletting Howl at 40% HP');

-- Grom'kar Battlemaster
SET @ENTRY := 83025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,167232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,172860,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Drag');

-- Grom'kar Chainmaster
SET @ENTRY := 86526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,173042,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Warcry');

-- Grom'kar Deadeye
SET @ENTRY := 83028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,167239,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Iron Shot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,167240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leg Shot');

-- Grom'kar Deadeye
SET @ENTRY := 83764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,167239,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Iron Shot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,167240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leg Shot');

-- Grom'kar Deckhand
SET @ENTRY := 83762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,173112,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hatchet Toss');

-- Grom'kar Deckhand
SET @ENTRY := 83697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,173112,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hatchet Toss');

-- Grom'kar Flameslinger
SET @ENTRY := 81279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,167120,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,173148,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Arrows');

-- Grom'kar Footsoldier
SET @ENTRY := 83765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,172889,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charging Slash on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,20000,22000,11,169341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demoralizing Roar'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,169413,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tactical Kick on Player Spell Cast');

-- Grom'kar Footsoldier
SET @ENTRY := 81283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,172889,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charging Slash on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,20000,22000,11,169341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demoralizing Roar'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,169413,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tactical Kick on Player Spell Cast');

-- Grom'kar Incinerator
SET @ENTRY := 86809;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,172771,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Slug'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,167516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shrapnel Blast');

-- Grom'kar Technician
SET @ENTRY := 81432;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,172649,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grease Vial'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,172703,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fling Hammer');

-- Grom'kar Technician
SET @ENTRY := 83763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,172649,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grease Vial'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,172703,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fling Hammer');

-- Ironwing Flamespitter
SET @ENTRY := 83389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,173514,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Blast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,173480,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Barrage');

-- Koramar <Captain of Blackhand's Might>
SET @ENTRY := 83613;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,168965,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Berserker Leap on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,168402,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm');

-- Ogron Laborer
SET @ENTRY := 83761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,178412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,173135,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thundering Stomp');

-- Ogron Laborer
SET @ENTRY := 83578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,178412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,173135,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thundering Stomp');

-- Pitwarden Gwarnok
SET @ENTRY := 84520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,172889,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charging Slash on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,20000,22000,11,169341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demoralizing Roar'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,169413,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tactical Kick on Player Spell Cast');

-- Rampaging Clefthoof
SET @ENTRY := 83392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,158337,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,15000,11,158341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wounds'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,18000,22000,11,173349,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Trampled');

-- Rylak Skyterror
SET @ENTRY := 89011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,178154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit');

-- Siegemaster Olugar
SET @ENTRY := 83026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,172963,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gatecrasher'),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,18000,22000,11,172982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Strike');

-- Siegemaster Rokra
SET @ENTRY := 84028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,172963,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gatecrasher'),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,18000,22000,11,172982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Strike');

-- Thunderlord Wrangler
SET @ENTRY := 83390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,167095,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,15000,11,173307,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serrated Spear'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,167815,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Cleave on Close');

-- Unruly Ogron
SET @ENTRY := 87252;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,178412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,173135,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thundering Stomp');