-- Awbee
SET @ENTRY := 86533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,177767,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Breath');

-- Black Iron Alchemist <Iron Horde>
SET @ENTRY := 76100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,350000,40,15000,18000,11,155498,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenating Serum on Friendlies'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,155498,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rejuvenating Serum at 40% HP');

-- Black Iron Berserker <Iron Horde>
SET @ENTRY := 76176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,153897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Cleave'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,153909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Black Iron Drake-Keeper
SET @ENTRY := 76935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,155356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Chain');

-- Black Iron Dreadweaver <Iron Horde>
SET @ENTRY := 77035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,155587,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,155588,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,155586,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Veil of Shadow at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,450000,40,15000,18000,11,155586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Veil of Shadow on Friendlies');

-- Black Iron Dreadweaver <Iron Horde>
SET @ENTRY := 84475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,155587,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,155588,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,155586,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Veil of Shadow at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,450000,40,15000,18000,11,155586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Veil of Shadow on Friendlies');

-- Black Iron Elite <Iron Horde>
SET @ENTRY := 77037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,155584,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Berserker Charge on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,139385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bestial Roar at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,20000,25000,11,167259,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidating Shout');

-- Black Iron Engineer <Iron Horde>
SET @ENTRY := 76101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,2500,11,155505,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Ray');

-- Black Iron Flame Reaver <Iron Horde>
SET @ENTRY := 80678;
SET @ENTRYTOTEM := 80703;
SET @TOTEMSPELL := 163065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,163061,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfury Totem'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,163057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

-- Black Iron Groundshaker
SET @ENTRY := 76599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,20000,11,154827,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Intimidating Roar');

-- Black Iron Grunt <Iron Horde>
SET @ENTRY := 76179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,153832,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,153792,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rallying Banner on Aggro');

-- Black Iron Leadbelcher <Iron Horde>
SET @ENTRY := 76157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,2500,11,153974,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,153981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shell on Close');

-- Black Iron Rageguard <Iron Horde>
SET @ENTRY := 82418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,165954,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,14000,19000,11,165944,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Smash');

-- Black Iron Siegebreaker <Iron Horde>
SET @ENTRY := 77033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,155572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Black Iron Summoner <Iron Horde>
SET @ENTRY := 77036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,155590,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,155589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,1,0,50,1,3000,5000,0,0,11,169088,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Black Iron Dreadweaver on Spawn'),
(@ENTRY,0,3,0,1,0,50,1,3000,5000,0,0,11,169151,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Black Iron Veteran on Spawn'),
(@ENTRY,0,4,0,2,0,50,1,0,40,0,0,11,169088,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Black Iron Dreadweaver at 40% HP'),
(@ENTRY,0,5,0,2,0,50,1,0,40,0,0,11,169151,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Black Iron Veteran at 40% HP');

-- Black Iron Veteran <Iron Horde>
SET @ENTRY := 77034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,155575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast');

-- Black Iron Veteran <Iron Horde>
SET @ENTRY := 84462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,155575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast');

-- Black Iron Warcaster <Iron Horde>
SET @ENTRY := 76151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,153642,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bolt of Steel'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,153942,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shrapnel Storm');

-- Black Iron Wyrmcaller <Iron Horde>
SET @ENTRY := 80649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,163007,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Pull'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,163011,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dragon Roar');

-- Drakonid Monstrosity
SET @ENTRY := 76018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155037,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eruption');

-- Drakonid Monstrosity
SET @ENTRY := 82556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155037,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eruption');

-- Emberscale Ironflight
SET @ENTRY := 82428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166040,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Breath');

-- Emberscale Ironflight
SET @ENTRY := 77180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162905,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Spit');

-- Leeroy Jenkins
SET @ENTRY := 77075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,172584,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chicken Timer on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,134822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike');

-- Ragemaw Worg
SET @ENTRY := 76181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,154017,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blackrock Rabies'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,154039,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frantic Mauling at 40% HP');

-- Sentry Cannon
SET @ENTRY := 76314;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,154178,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Canon Shoot');

-- Son of the Beast
SET @ENTRY := 77927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,157467,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Eruption'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,157428,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Roar'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,157347,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Charge on Aggro');

-- The Lanticore
SET @ENTRY := 77081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Vilemaw Hatchling
SET @ENTRY := 77096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161406,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Spit');