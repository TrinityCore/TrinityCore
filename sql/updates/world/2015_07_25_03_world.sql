-- 
-- DB/SAI: Update Duskwood
-- Anguished Spirit SAI
SET @ENTRY := 45614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,80132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anguished Spirit - In Combat - Cast 'Unbound Darkness'");
-- Barn Owl SAI
SET @ENTRY := 44020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,13000,17000,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barn Owl - In Combat - Cast 'Eye Peck'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,24000,11,81680,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barn Owl - In Combat - Cast 'Howling Screech'");
-- Black Ravager SAI
SET @ENTRY := 628;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,45,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Ravager - Within 0-45 Range - Cast 'Leaping Rush' (No Repeat)");
-- Black Widow SAI
SET @ENTRY := 45582;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,21000,11,87080,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Widow - Between 0-40% Health - Cast 'Vanish'");
-- Black Widow Hatchling SAI
SET @ENTRY := 930;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow Hatchling - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,8000,9000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow Hatchling - Within 0-30 Range - Cast 'Web'");
-- Blackbelly Forager SAI
SET @ENTRY := 44089;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackbelly Forager - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,84873,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackbelly Forager - Between 0-30% Health - Cast 'Wallow' (No Repeat)");
-- Bone Chewer SAI
SET @ENTRY := 210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2500,11000,11500,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bone Chewer - In Combat - Cast 'Bone Toss'"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bone Chewer - Out of Combat - Cast 'Birth' (No Repeat)");
-- Buried Corpse SAI
SET @ENTRY := 43851;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,84863,0,0,0,0,0,1,0,0,0,0,0,0,0,"Buried Corpse - In Combat - Cast 'Tunnel'"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Buried Corpse - Out of Combat - Cast 'Birth' (No Repeat)");
-- Carved One SAI
SET @ENTRY := 45785;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,85253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Carved One - Out of Combat - Cast 'Rotten Stench'"),
(@ENTRY,0,1,0,0,0,100,0,4500,6500,14500,16800,11,78472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carved One - In Combat - Cast 'Flame Breath'");
-- Clattering Coldwraith SAI
SET @ENTRY := 44029;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,1800000,1800000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clattering Coldwraith - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,24000,26000,11,79860,1,0,0,0,0,5,0,0,0,0,0,0,0,"Clattering Coldwraith - In Combat - Cast 'Blizzard'"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,79859,1,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Coldwraith - In Combat - Cast 'Ice Lance'");
-- Coalpelt Bear SAI
SET @ENTRY := 44016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,11000,13000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coalpelt Bear - In Combat - Cast 'Swipe'"),
(@ENTRY,0,1,0,2,0,100,1,0,45,0,0,11,84868,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coalpelt Bear - Between 0-45% Health - Cast 'Hibernate' (No Repeat)");
-- Corpseweed SAI
SET @ENTRY := 43732;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,85253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corpseweed - Out of Combat - Cast 'Rotten Stench'");
-- Crown Duster SAI
SET @ENTRY := 37984;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Duster - In Combat - Cast 'Spray Chemical'");
-- Dire Wolf SAI
SET @ENTRY := 43704;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dire Wolf - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dire Wolf - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,22000,26000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dire Wolf - In Combat - Cast 'Rabies'");
-- NPC talk text insert
SET @ENTRY := 43704;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Eliza SAI
SET @ENTRY := 45801;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eliza - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,3107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eliza - On Aggro - Cast 'Summon Eliza's Guard' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,3107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eliza - Between 0-50% Health - Cast 'Summon Eliza's Guard' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,2500,4500,20500,22000,11,81767,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eliza - In Combat - Cast 'Lantern Blaze'"),
(@ENTRY,0,4,0,0,0,100,0,8000,12000,15000,18000,11,81764,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eliza - In Combat - Cast 'Throw Lantern'");
-- NPC talk text insert
SET @ENTRY := 45801;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Eliza isss pretty....sssso pretty...',12,0,100,0,0,0, 'on Aggro Text',45846);
-- Fenros SAI
SET @ENTRY := 507;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenros - On Aggro - Cast 'Shadow Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenros - In Combat - Cast 'Exploit Weakness'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,19000,22000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenros - In Combat - Cast 'Furious Howl'");
-- Fetid Corpse SAI
SET @ENTRY := 1270;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fetid Corpse - In Combat - Cast 'Fetid Breath'"),
(@ENTRY,0,1,0,0,0,100,0,2000,8000,22000,26000,11,7102,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fetid Corpse - In Combat - Cast 'Contagion of Rot'"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fetid Corpse - Out of Combat - Cast 'Birth' (No Repeat)");
-- Flesh Eater SAI
SET @ENTRY := 3;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flesh Eater - Out of Combat - Cast 'Birth' (No Repeat)");
-- Forlorn Spirit SAI
SET @ENTRY := 43923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,21000,11,81193,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forlorn Spirit - In Combat - Cast 'Unrelenting Anguish'");
-- Grave Robber SAI
SET @ENTRY := 218;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grave Robber - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grave Robber - In Combat - Cast 'Exploit Weakness'");
-- Insane Ghoul SAI
SET @ENTRY := 511;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,22000,26000,11,83586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Insane Ghoul - In Combat - Cast 'Insane Rambling'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,"Insane Ghoul - On Just Died - Cast 'Corpse Rot' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Insane Ghoul - Out of Combat - Cast 'Birth' (No Repeat)");
-- Lupos SAI
SET @ENTRY := 521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lupos - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,22000,26000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lupos - In Combat - Cast 'Rabies'");
-- Marina DeSirrus SAI
SET @ENTRY := 45811;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marina DeSirrus - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marina DeSirrus - In Combat - Cast 'Exploit Weakness'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,16000,22000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marina DeSirrus - In Combat - Cast 'Torch Toss'");
-- NPC talk text insert
SET @ENTRY := 45811;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Adventurers are such hypocrites! Like YOU just FOUND your weapons on the side of the road!',12,0,100,0,0,0, 'on Aggro Text',45864);
-- Marus SAI
SET @ENTRY := 45771;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marus - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marus - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,40,16000,21000,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marus - Between 0-40% Health - Cast 'Evasion'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marus - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 45771;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Morbent Fel SAI
SET @ENTRY := 43761;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,22000,26000,11,3108,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morbent Fel - Between 0-55% Health - Cast 'Touch of Death'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,20000,11,3109,0,0,0,0,0,5,0,0,0,0,0,0,0,"Morbent Fel - In Combat - Cast 'Presence of Death'"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,8909,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbent Fel - On Respawn - Cast 'Unholy Shield' (No Repeat)");
-- Morbidius SAI
SET @ENTRY := 45619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,14500,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morbidius - Within 0-5 Range - Cast 'Mortal Strike'");
-- Mor'Ladim SAI
SET @ENTRY := 522;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,6000,12000,15000,11,79961,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mor'Ladim - In Combat - Cast 'Holy Shock'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,3547,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mor'Ladim - Between 0-30% Health - Cast 'Enraging Memories' (No Repeat)");
-- Naraxis SAI
SET @ENTRY := 574;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naraxis - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,21000,11,87080,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naraxis - Between 0-40% Health - Cast 'Vanish'"),
(@ENTRY,0,2,0,9,0,100,0,0,30,8000,9000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naraxis - Within 0-30 Range - Cast 'Web'");
-- Nefaru SAI
SET @ENTRY := 534;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,17000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nefaru - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,25000,28000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nefaru - In Combat - Cast 'Infected Wound'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,33000,36000,11,8715,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nefaru - In Combat - Cast 'Terrifying Howl'");
-- Night Watch Guard SAI
SET @ENTRY := 10038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Night Watch Guard - In Combat - Cast 'Shoot'");
-- Nightbane Dark Runner SAI
SET @ENTRY := 205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Dark Runner - On Aggro - Cast 'Shadow Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Dark Runner - In Combat - Cast 'Exploit Weakness'");
-- Nightbane Shadow Weaver SAI
SET @ENTRY := 533;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,10,0,2,1,100,1,0,45,0,0,11,85072,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - Between 0-45% Health - Cast 'Woven Shadows' (Phase 1) (No Repeat)");
-- Nightbane Stalker SAI
SET @ENTRY := 44087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Stalker - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Stalker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Stalker - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Stalker - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)");
-- Nightbane Tainted One SAI
SET @ENTRY := 920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,60000,65000,11,85244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Tainted One - In Combat - Cast 'Worgen Taint'");
-- Nightbane Vile Fang SAI
SET @ENTRY := 206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,11000,25000,28000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Vile Fang - In Combat - Cast 'Infected Wound'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,22000,22500,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Vile Fang - In Combat - Cast 'Furious Howl'");
-- Nightbane Worgen SAI
SET @ENTRY := 898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Worgen - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,22000,22500,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Worgen - In Combat - Cast 'Furious Howl'");
-- Plague Spreader SAI
SET @ENTRY := 604;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,33000,36000,11,3436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Spreader - In Combat - Cast 'Wandering Plague'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Spreader - On Just Died - Cast 'Corpse Rot' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Spreader - Out of Combat - Cast 'Birth' (No Repeat)");
-- Rotted One SAI
SET @ENTRY := 948;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotted One - Out of Combat - Cast 'Birth' (No Repeat)"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,3428,3,0,0,0,0,1,0,0,0,0,0,0,0,"Rotted One - On Just Died - Cast 'Summon Flesh Eating Worms' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotted One - In Combat - Cast 'Fetid Breath'");
-- Rotting Horror SAI
SET @ENTRY := 202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,16000,21000,11,7102,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotting Horror - In Combat - Cast 'Contagion of Rot'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Horror - On Just Died - Cast 'Corpse Rot' (No Repeat)");
-- Silent Shade SAI
SET @ENTRY := 44028;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,14000,11,82717,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silent Shade - In Combat - Cast 'Vanish'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,17000,21000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silent Shade - Between 0-40% Health - Cast 'Evasion'");
-- Sister Elsington SAI
SET @ENTRY := 43731;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,1800000,1800000,11,48168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Elsington - Out of Combat - Cast 'Inner Fire'");
-- Skeletal Mage SAI
SET @ENTRY := 203;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Mage - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Mage - Out of Combat - Cast 'Frost Armor'");
-- Skeletal Warrior SAI
SET @ENTRY := 48;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,16000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Warrior - Within 0-5 Range - Cast 'Sundering Cleave'");
-- Splinter Fist Firemonger SAI
SET @ENTRY := 1251;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Firemonger - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,16000,22000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Firemonger - In Combat - Cast 'Torch Toss'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3500,12000,13000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Firemonger - In Combat - Cast 'Scorch'");
-- NPC talk text insert
SET @ENTRY := 1251;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Splinter Fist Ogre SAI
SET @ENTRY := 889;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Ogre - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,12000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Ogre - In Combat - Cast 'Uppercut'");
-- NPC talk text insert
SET @ENTRY := 889;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Splinter Fist Warrior SAI
SET @ENTRY := 212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,24000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - In Combat - Cast 'Bladestorm'");
-- NPC talk text insert
SET @ENTRY := 212;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Stalvan Mistmantle SAI
SET @ENTRY := 315;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stalvan Mistmantle - In Combat - Cast 'Fetid Breath'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,65000,68000,11,3105,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stalvan Mistmantle - In Combat - Cast 'Curse of Stalvan'");
-- Stitches SAI
SET @ENTRY := 43862;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3106,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stitches - On Respawn - Cast 'Aura of Rot' (No Repeat)");
-- The Unknown Soldier SAI
SET @ENTRY := 45739;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Unknown Soldier - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Unknown Soldier - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Unknown Soldier - On Aggro - Cast 'Commanding Shout' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,5,14000,15000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Unknown Soldier - Within 0-5 Range - Cast 'Sundering Cleave'");
-- NPC talk text insert
SET @ENTRY := 45739;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Zzarc' Vul SAI
SET @ENTRY := 300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zzarc' Vul - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,24000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zzarc' Vul - In Combat - Cast 'Bladestorm'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,12000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zzarc' Vul - In Combat - Cast 'Uppercut'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,22000,22000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zzarc' Vul - Within 0-5 Range - Cast 'Low Swipe'"),
(@ENTRY,0,4,0,0,0,100,0,12000,15000,8000,25000,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zzarc' Vul - In Combat - Cast 'Knockdown'");
-- NPC talk text insert
SET @ENTRY := 300;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
