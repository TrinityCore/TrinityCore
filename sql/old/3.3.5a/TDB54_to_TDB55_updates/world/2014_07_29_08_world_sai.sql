-- Gordunni Ogre Mage SAI
SET @ENTRY := 5237;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Gordunni Mage-Lord SAI
SET @ENTRY := 5239;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,20000,26000,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Woodpaw Mystic SAI
SET @ENTRY := 5254;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,14,0,100,0,800,30,45000,45000,11,8005,1,0,0,0,0,7,0,0,0,0,0,0,0,"Woodpaw Mystic - Friendly At 800 Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Atal'ai Witch Doctor SAI
SET @ENTRY := 5259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3500,5200,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4900,13100,13100,18400,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10900,26100,17100,35100,11,11641,1,0,0,0,0,5,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Hex' (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,2,1800,40,12700,23100,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Friendly At 1800 Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Enthralled Atal'ai SAI
SET @ENTRY := 5261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12000,18000,25000,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enthralled Atal'ai - In Combat - Cast 'Fixate' (Normal Dungeon)");

-- Mummified Atal'ai SAI
SET @ENTRY := 5263;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,15000,4000,10000,11,16186,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mummified Atal'ai - In Combat - Cast 'Fevered Plague' (Normal Dungeon)");

-- Atal'ai Priest SAI
SET @ENTRY := 5269;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Out of Combat - Cast 'Shadow Shield' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,1000,30,11000,15000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Priest - Friendly At 1000 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Atal'ai Corpse Eater SAI
SET @ENTRY := 5270;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,12000,12000,11,12134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Corpse Eater - Between 0-30% Health - Cast 'Atal'ai Corpse Eat' (No Repeat) (Normal Dungeon)");

-- Atal'ai Deathwalker SAI
SET @ENTRY := 5271;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7300,14500,15900,32200,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Deathwalker - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,13000,18000,11,12096,1,0,0,0,0,6,0,0,0,0,0,0,0,"Atal'ai Deathwalker - In Combat - Cast 'Fear' (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,12095,7,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Deathwalker - On Just Died - Cast 'Summon Atal'ai Deathwalker's Spirit' (No Repeat) (Normal Dungeon)");

-- Atal'ai High Priest SAI
SET @ENTRY := 5273;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3600,3600,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai High Priest - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,40,2,10000,20000,75000,75000,11,12151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - In Combat - Cast 'Summon Atal'ai Skeleton' (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,2500,40,20000,30000,11,12039,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai High Priest - Friendly At 2500 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,12040,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Ironfur Patriarch SAI
SET @ENTRY := 5274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,8000,8000,12000,12000,11,10968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironfur Patriarch - In Combat - Cast 'Demoralizing Roar'");

-- Nightmare Scalebane SAI
SET @ENTRY := 5277;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4500,10900,11900,17100,11,3639,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Scalebane - In Combat - Cast 'Improved Blocking' (Normal Dungeon)");

-- Nightmare Wyrmkin SAI
SET @ENTRY := 5280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,9591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wyrmkin - In Combat CMC - Cast 'Acid Spit' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,23000,27000,11,12098,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nightmare Wyrmkin - In Combat - Cast 'Sleep' (Normal Dungeon)");

-- Nightmare Wanderer SAI
SET @ENTRY := 5283;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13900,16700,12100,19900,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wanderer - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,5,23800,38200,11,12097,33,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wanderer - Within 0-5 Range - Cast 'Pierce Armor' (Normal Dungeon)");

-- Areatrigger SAI
SET @ENTRY := 5284;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,5284,0,0,0,85,60111,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Cast 'Kill Credit South'");

-- Areatrigger SAI
SET @ENTRY := 5285;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,5285,0,0,0,85,60112,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Cast 'Kill Credit Central'");

-- Areatrigger SAI
SET @ENTRY := 5286;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,5286,0,0,0,85,60115,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Cast 'Kill Credit North'");

-- Areatrigger SAI
SET @ENTRY := 5287;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,5287,0,0,0,85,60117,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Cast 'Kill Credit Northwest'");

-- Hakkari Frostwing SAI
SET @ENTRY := 5291;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5900,9700,15900,32200,11,8398,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hakkari Frostwing - In Combat - Cast 'Frostbolt Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,17800,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hakkari Frostwing - Within 0-5 Range - Cast 'Swoop' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6900,16800,16800,29600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hakkari Frostwing - In Combat - Cast 'Frost Nova' (Normal Dungeon)");

-- Ferocious Rage Scar SAI
SET @ENTRY := 5299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,15000,15000,45000,45000,11,3147,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ferocious Rage Scar - In Combat - Cast 'Rend Flesh'");

-- Dunemaul Ogre Mage SAI
SET @ENTRY := 5473;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,18000,26000,11,11436,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - In Combat - Cast 'Slow'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Dunemaul Brute SAI
SET @ENTRY := 5474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,9000,12000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Brute - In Combat - Cast 'Uppercut'");

-- Dunemaul Warlock SAI
SET @ENTRY := 5475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,21000,26000,11,2941,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Immolate'"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,180000,188000,11,6909,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Curse of Thorns'");

-- Thistleshrub Dew Collector SAI
SET @ENTRY := 5481;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,2500,22000,26000,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistleshrub Dew Collector - In Combat - Cast 'Entangling Roots'");

-- Thistleshrub Rootshaper SAI
SET @ENTRY := 5485;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,2500,25000,35000,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistleshrub Rootshaper - In Combat - Cast 'Earthgrab Totem'");

-- Wastewander Rogue SAI
SET @ENTRY := 5615;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Rogue - Out of Combat - Cast 'Stealth'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,6000,10000,11,8721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Rogue - In Combat - Cast 'Backstab'");

-- Wastewander Thief SAI
SET @ENTRY := 5616;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,7000,12000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Thief - In Combat - Cast 'Disarm'");

-- Wastewander Shadow Mage SAI
SET @ENTRY := 5617;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Shadow Mage - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,19000,26000,11,20826,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Shadow Mage - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Wastewander Bandit SAI
SET @ENTRY := 5618;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,7000,12000,11,8629,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Bandit - In Combat - Cast 'Gouge'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,6000,10000,11,8721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Bandit - In Combat - Cast 'Backstab'");

-- Sandfury Hideskinner SAI
SET @ENTRY := 5645;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,6000,10000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Hideskinner - In Combat - Cast 'Backstab'");

-- Sandfury Axe Thrower SAI
SET @ENTRY := 5646;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Axe Thrower - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");


-- Sandfury Firecaller SAI
SET @ENTRY := 5647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,85,0,8000,14000,20000,26000,11,11990,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - In Combat - Cast 'Rain of Fire'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Sandfury Shadowcaster SAI
SET @ENTRY := 5648;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Out of Combat - Cast 'Demon Skin' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowcaster - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,23000,28000,11,14032,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Shadowcaster - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Sandfury Blood Drinker SAI
SET @ENTRY := 5649;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5500,8000,8000,10000,11,11898,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Blood Drinker - In Combat - Cast 'Blood Leech' (Normal Dungeon)");

-- Sandfury Witch Doctor SAI
SET @ENTRY := 5650;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,45000,45000,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - In Combat - Cast 'Healing Ward' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,85,2,3000,3000,35000,35000,11,8264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - In Combat - Cast 'Lava Spout Totem' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,12000,12000,11,17843,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - Between 0-50% Health - Cast 'Flash Heal' (Normal Dungeon)");
