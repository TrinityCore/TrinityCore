--  3.x + 4.x + 6.x
-- DB/SAI: Update Gjostland
-- Haris Lightsbreath SAI
SET @ENTRY := 49954;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haris Lightsbreath - Out of Combat - Cast 'Seal of Righteousness'");

-- Matron Narsilla SAI
SET @ENTRY := 49950;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,48168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matron Narsilla - Out of Combat - Cast 'Inner Fire'");

-- Shadowpine Catlord SAI
SET @ENTRY := 16345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,16,0,100,0,28902,30,20000,40000,11,28902,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpine Catlord - On Friendly Unit Missing Buff 'Bloodlust' - Cast 'Bloodlust'"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,28904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Catlord - Out of Combat - Cast 'Summon Ghostclaw Lynx' (No Repeat)");

-- 4.x + 6.x
-- DB/SAI: Update Darkshore
-- Aetherion SAI
SET @ENTRY := 33041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,75079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aetherion - In Combat - Cast 'Blast of Air'");
-- Anaya Dawnrunner SAI
SET @ENTRY := 3667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,14000,17000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anaya Dawnrunner - In Combat - Cast 'Banshee Curse'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya Dawnrunner - On Just Died - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 3667;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Finally, my soul may rest... Oh, dearest Cerellean...',12,0,100,0,0,0, 'on Aggro Text',1224);
-- Awakened Ancient SAI
SET @ENTRY := 34486;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,15000,22000,11,26281,0,0,0,0,0,2,1,0,0,0,0,0,0,"Awakened Ancient - In Combat - Cast 'Taunt'");
-- Blackwood Furbolg SAI
SET @ENTRY := 33084;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,25000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwood Furbolg - Between 0-50% Health - Cast 'Healing Ward'");
-- Blackwood Tracker SAI
SET @ENTRY := 11713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwood Tracker - Within 0-5 Range - Cast 'Thrash'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,30000,35000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwood Tracker - Within 0-30 Range - Cast 'Faerie Fire'");
-- Carnivous the Breaker SAI
SET @ENTRY := 2186;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Carnivous the Breaker - On Respawn - Cast 'Thrash' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carnivous the Breaker - Within 0-5 Range - Cast 'Pierce Armor'");
-- Cloudtamer Wildmane SAI
SET @ENTRY := 32988;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cloudtamer Wildmane - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,17000,22000,11,15039,2,0,0,0,0,2,0,0,0,0,0,0,0,"Cloudtamer Wildmane - Within 0-20 Range - Cast 'Flame Shock'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,12000,26500,11,75068,2,0,0,0,0,2,0,0,0,0,0,0,0,"Cloudtamer Wildmane - In Combat - Cast 'Lava Burst'"),
(@ENTRY,0,3,0,1,0,100,1,1000,1000,1000,1000,11,39550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cloudtamer Wildmane - Out of Combat - Cast 'Arcane Channeling' (No Repeat)");
-- Consumed Thistle Bear SAI
SET @ENTRY := 34302;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,87187,0,0,0,0,0,2,0,0,0,0,0,0,0,"Consumed Thistle Bear - On Aggro - Cast 'Feral Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,18000,22000,11,5422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Consumed Thistle Bear - In Combat - Cast 'Lacerate'");
-- Corrupted Blackwood SAI
SET @ENTRY := 33044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Blackwood - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Blackwood - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,5800,12000,14700,11,15039,2,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Blackwood - In Combat - Cast 'Flame Shock'");
-- Corrupted Thistle Bear SAI
SET @ENTRY := 33009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,18000,22000,11,5422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Thistle Bear - In Combat - Cast 'Lacerate'");
-- Corrupted Thistle Bear Matriarch SAI
SET @ENTRY := 33905;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,18000,22000,11,5422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Thistle Bear Matriarch - In Combat - Cast 'Lacerate'");
-- Corrupted Tide Crawler SAI
SET @ENTRY := 32935;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,17000,23000,11,75004,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Tide Crawler - In Combat - Cast 'Pinch'");
-- Cursed Highborne SAI
SET @ENTRY := 33179;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,16000,21000,11,75015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Highborne - Within 0-30 Range - Cast 'Curse of Shadows'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,24000,28000,11,51897,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Highborne - In Combat - Cast 'Banshee Screech'");
-- Darkscale Myrmidon SAI
SET @ENTRY := 33079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkscale Myrmidon - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkscale Myrmidon - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,12500,14500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkscale Myrmidon - Within 0-5 Range - Cast 'Heroic Strike'");
-- NPC talk text insert
SET @ENTRY := 33079;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Darkscale Priestess SAI
SET @ENTRY := 34415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkscale Priestess - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkscale Priestess - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,11000,16000,11,75062,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darkscale Priestess - Within 0-8 Range - Cast 'Frost Nova'");
-- Darkscale Scout SAI
SET @ENTRY := 33206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,21000,22000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkscale Scout - Within 0-5 Range - Cast 'Hamstring'");
-- Darkscale Siren SAI
SET @ENTRY := 34414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,19500,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkscale Siren - Within 0-5 Range - Cast 'Knockdown'");
-- Darkshore Stag SAI
SET @ENTRY := 33311;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkshore Stag - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,17000,24500,11,31274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkshore Stag - In Combat - Cast 'Knockdown'");
-- Darkshore Wisp SAI
SET @ENTRY := 34306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,65127,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkshore Wisp - On Respawn - Cast 'Darkshore Wisp Sparkle' (No Repeat)");
-- Doomspeaker Trevellion SAI
SET @ENTRY := 34326;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Doomspeaker Trevellion - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,34000,35000,11,14868,2,0,0,0,0,2,0,0,0,0,0,0,0,"Doomspeaker Trevellion - In Combat - Cast 'Curse of Agony'"),
(@ENTRY,0,2,0,0,0,100,0,9000,11000,25000,29500,11,32063,2,0,0,0,0,2,0,0,0,0,0,0,0,"Doomspeaker Trevellion - In Combat - Cast 'Corruption'");
-- Elder Brownpaw SAI
SET @ENTRY := 33117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,25000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Brownpaw - Between 0-50% Health - Cast 'Healing Ward'");
-- Encrusted Tide Crawler SAI
SET @ENTRY := 2233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,12000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,"Encrusted Tide Crawler - Within 0-5 Range - Cast 'Infected Wound'");
-- Enraged Earth Elemental SAI
SET @ENTRY := 33083;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,12000,19000,11,75023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Earth Elemental - Within 0-20 Range - Cast 'Boulder Toss'");
-- Enraged Tidal Spirit SAI
SET @ENTRY := 32890;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,14000,22000,11,39207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Tidal Spirit - In Combat - Cast 'Water Spout'");
-- Faceless One SAI
SET @ENTRY := 34413;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faceless One - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faceless One - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,3500,11000,15600,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faceless One - In Combat - Cast 'Mind Blast'");
-- NPC talk text insert
SET @ENTRY := 34413;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Firecaller Radison SAI
SET @ENTRY := 2192;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firecaller Radison - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,12000,16000,11,11969,2,0,0,0,0,1,0,0,0,0,0,0,0,"Firecaller Radison - Within 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,60000,65000,11,5915,2,0,0,0,0,1,0,0,0,0,0,0,0,"Firecaller Radison - Between 0-30% Health - Cast 'Crazed'");
-- Flagglemurk the Cruel SAI
SET @ENTRY := 7015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flagglemurk the Cruel - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,9000,12000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flagglemurk the Cruel - In Combat - Cast 'Knockdown'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flagglemurk the Cruel - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Forsaken Looter SAI
SET @ENTRY := 34046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,6000,8000,25000,27000,11,74975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Looter - In Combat - Cast 'Purse Snatch'"),
(@ENTRY,0,1,0,61,0,100,0,6000,8000,25000,27000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Looter - In Combat - Say Line 0"),
(@ENTRY,0,2,0,1,0,40,0,12000,15000,44000,47000,11,35205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Looter - Out of Combat - Cast 'Vanish'");
-- NPC talk text insert
SET @ENTRY := 34046;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s cackles in glee.',16,0,100,0,0,0, 'combat Text',40210);
-- Frenzied Cyclone SAI
SET @ENTRY := 32985;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Cyclone - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Cyclone - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,2,0,0,0,100,0,4000,4500,12000,13000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Cyclone - In Combat - Cast 'Lightning Bolt'");
-- Greater Awakened Ancient SAI
SET @ENTRY := 42984;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,15000,22000,11,26281,0,0,0,0,0,2,1,0,0,0,0,0,0,"Greater Awakened Ancient - In Combat - Cast 'Taunt'");
-- Greef SAI
SET @ENTRY := 33981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,36227,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greef - In Combat - Cast 'Firebolt'");
-- Greymist Hunter SAI
SET @ENTRY := 2206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Hunter - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Greymist Oracle SAI
SET @ENTRY := 2207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Oracle - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Greymist Refugee SAI
SET @ENTRY := 34339;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Refugee - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Refugee - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,1,3000,5000,0,0,11,75097,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Refugee - In Combat - Cast 'Summon Tamed Crab' (No Repeat)");
-- Greymist Tidehunter SAI
SET @ENTRY := 33262;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Tidehunter - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Greymist Warrior SAI
SET @ENTRY := 33277;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,25000,29000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,"Greymist Warrior - Within 0-5 Range - Cast 'Infected Wound'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,21000,11,74972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Warrior - In Combat - Cast 'Greymist'");
-- Grizzled Thistle Bear SAI
SET @ENTRY := 2165;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,7000,10000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzled Thistle Bear - In Combat - Cast 'Ravage'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzled Thistle Bear - On Aggro - Cast 'Leaping Rush' (No Repeat)");
-- Happy Greymist Murloc SAI
SET @ENTRY := 34347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Happy Greymist Murloc - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Hermit Tide Crawler SAI
SET @ENTRY := 34369;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,17000,23000,11,75004,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hermit Tide Crawler - In Combat - Cast 'Pinch'");
-- High Cultist Azerynn SAI
SET @ENTRY := 32899;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Azerynn - Out of Combat - Cast 'Shadow Channelling' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,20000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Cultist Azerynn - In Combat - Cast 'Mind Flay'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,22000,24500,11,30615,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Cultist Azerynn - In Combat - Cast 'Fear'");
-- Horde Enforcer SAI
SET @ENTRY := 32859;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35570,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Enforcer - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,13000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Enforcer - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,27000,32000,11,13730,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Enforcer - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Enforcer - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Enforcer - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 32859;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Horoo the Flamekeeper SAI
SET @ENTRY := 34385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,14000,18000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horoo the Flamekeeper - In Combat - Cast 'Moonfire'");
-- Hungry Thistle Bear SAI
SET @ENTRY := 33978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,18000,22000,11,5422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hungry Thistle Bear - In Combat - Cast 'Lacerate'");
-- Jor'kil the Soulripper SAI
SET @ENTRY := 32862;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,11000,15500,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jor'kil the Soulripper - Within 0-30 Range - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,35197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jor'kil the Soulripper - Between 0-30% Health - Cast 'Terror Totem' (No Repeat)");
-- Keynira Owlwing SAI
SET @ENTRY := 34103;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Evade - Cast 'Stealth' (No Repeat)");
-- Lady Janira SAI
SET @ENTRY := 33207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Janira - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Janira - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,40,14000,21000,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Janira - Between 0-40% Health - Cast 'Heal'");
-- Lady Moongazer SAI
SET @ENTRY := 2184;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Moongazer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,8000,11000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Moongazer - Within 0-20 Range - Cast 'Net'");
-- Lady Vespira SAI
SET @ENTRY := 7016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespira - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,14000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespira - Within 0-5 Range - Cast 'Knockdown'"),
(@ENTRY,0,2,0,0,0,100,0,11000,15000,14000,17000,11,12549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespira - In Combat - Cast 'Forked Lightning'");
-- Licillin SAI
SET @ENTRY := 2191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Licillin - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,120000,130000,11,11980,2,0,0,0,0,2,0,0,0,0,0,0,0,"Licillin - Within 0-30 Range - Cast 'Curse of Weakness'");
-- Lord Sinslayer SAI
SET @ENTRY := 7017;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Sinslayer - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,11000,16000,11,13586,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Sinslayer - In Combat - Cast 'Aqua Jet'");
-- Lor'danel Sentinel SAI
SET @ENTRY := 32969;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,13000,11,31290,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,9,0,100,0,11,24,15000,18000,11,81253,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - Within 11-24 Range - Cast 'Glaive'");
-- Lor'danel Sentinel SAI
SET @ENTRY := 33115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,64437,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - In Combat - Cast 'Flame Arrow Aura'");
-- Lor'danel Sentinel SAI
SET @ENTRY := 43440;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,13000,11,31290,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,9,0,100,0,11,24,15000,18000,11,81253,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'danel Sentinel - Within 11-24 Range - Cast 'Glaive'");
-- Lorenth Thundercall SAI
SET @ENTRY := 32868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorenth Thundercall - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,5,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorenth Thundercall - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,62238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lorenth Thundercall - On Aggro - Cast 'Unstable Lightning Blast' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4700,11,62238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lorenth Thundercall - Within 0-40 Range - Cast 'Unstable Lightning Blast' (Phase 1)"),
(@ENTRY,0,4,0,2,1,100,0,0,40,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorenth Thundercall - Between 0-40% Health - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorenth Thundercall - On Aggro - Say Line 0 (Phase 1) (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 32868;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Don''t move, little adventurer. I have the death you seek.',12,0,100,0,0,0, 'on Aggro Text',34476);
-- Luk'gar SAI
SET @ENTRY := 33345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Luk'gar - On Aggro - Cast 'Battle Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,19000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Luk'gar - In Combat - Cast 'Thunderclap'");
-- Maddened Blackwood SAI
SET @ENTRY := 33043;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,30000,35000,11,75014,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maddened Blackwood - In Combat - Cast 'Howl of Madness'");
-- Marosh the Devious SAI
SET @ENTRY := 11714;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marosh the Devious - Within 0-5 Range - Cast 'Thrash'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,30000,35000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marosh the Devious - Within 0-30 Range - Cast 'Faerie Fire'");
-- Moonstalker SAI
SET @ENTRY := 33127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,17000,11,75008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonstalker - In Combat - Cast 'Pounce'");
-- Moonstalker Matriarch SAI
SET @ENTRY := 2071;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,8594,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonstalker Matriarch - Out of Combat - Cast 'Summon Moonstalker Runt' (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonstalker Matriarch - On Aggro - Cast 'Sprint' (No Repeat)");
-- Moonstalker Sire SAI
SET @ENTRY := 2237;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,17000,11,75008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonstalker Sire - In Combat - Cast 'Pounce'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonstalker Sire - On Aggro - Cast 'Sprint' (No Repeat)");
-- Nightsaber Rider SAI
SET @ENTRY := 33359;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightsaber Rider - In Combat - Cast 'Shoot'");
-- Priestess Alinya SAI
SET @ENTRY := 33107;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,14000,21000,11,62294,0,0,0,0,0,1,0,0,0,0,0,0,0,"Priestess Alinya - Between 0-40% Health - Cast 'Heal'");
-- Rit'ko SAI
SET @ENTRY := 32970;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rit'ko - In Combat - Cast 'Throw'");
-- Shadowclaw SAI
SET @ENTRY := 2175;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,120000,125000,11,17227,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowclaw - Within 0-30 Range - Cast 'Curse of Weakness'");
-- Sharax the Defiler SAI
SET @ENTRY := 32996;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,14000,17000,11,75015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharax the Defiler - Within 0-30 Range - Cast 'Curse of Shadows'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,22000,27000,11,75016,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharax the Defiler - In Combat - Cast 'Defiled Ground'");
-- Shatterspear Champion SAI
SET @ENTRY := 32858;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,19000,11,37704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Champion - Within 0-5 Range - Cast 'Whirlwind'");
-- Shatterspear Laborer SAI
SET @ENTRY := 32861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Laborer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Laborer - On Aggro - Cast 'Throw Rock' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,17000,24500,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Laborer - In Combat - Cast 'Head Crack'");
-- Shatterspear Mystic SAI
SET @ENTRY := 34248;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Mystic - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Mystic - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Mystic - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,13585,1,15000,30000,11,13585,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Mystic - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,0,0,100,0,7000,9000,15000,19000,11,12058,2,0,0,0,0,4,0,0,0,0,0,0,0,"Shatterspear Mystic - In Combat - Cast 'Chain Lightning'");
-- Shatterspear Overseer SAI
SET @ENTRY := 32863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Overseer - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,14000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Overseer - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,0,0,100,0,7000,8000,22000,25000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Overseer - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Overseer - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Overseer - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 32863;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Shatterspear Priestess SAI
SET @ENTRY := 32855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,14000,21000,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Priestess - Between 0-40% Health - Cast 'Heal'"),
(@ENTRY,0,1,0,14,0,100,0,1500,40,15000,18000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shatterspear Priestess - Friendly At 1500 Health - Cast 'Heal'");
-- Sheya Stormweaver SAI
SET @ENTRY := 32869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,64954,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sheya Stormweaver - In Combat - Cast 'Water Bolt'");
-- Shatterspear Raider SAI
SET @ENTRY := 34309;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,64041,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Raider - In Combat - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Raider - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,5,9,0,100,0,5,30,12000,17000,11,79444,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Raider - Within 5-30 Range - Cast 'Impale'");
-- Shatterspear Raider SAI
SET @ENTRY := 33071;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,64041,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Raider - In Combat - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Raider - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,17000,11,79444,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shatterspear Raider - Within 5-30 Range - Cast 'Impale'");
-- Shatterspear Shaman SAI
SET @ENTRY := 32860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,40,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Shaman - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,24000,11,8264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Shaman - In Combat - Cast 'Lava Spout Totem'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,14000,21000,11,35199,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shatterspear Shaman - Between 0-50% Health - Cast 'Healing Stream Totem'");
-- NPC talk text insert
SET @ENTRY := 32860;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Relax, mon, I be makin'' dis quick.',12,0,100,0,0,0, 'on Aggro Text',50171);
-- Skylord Braax SAI
SET @ENTRY := 32990;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,39550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skylord Braax - Out of Combat - Cast 'Arcane Channeling' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skylord Braax - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,2,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skylord Braax - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,0,0,100,0,2000,5000,15000,24000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skylord Braax - In Combat - Cast 'Searing Totem'");
-- Spawn of Soggoth SAI
SET @ENTRY := 33082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spawn of Soggoth - In Combat - Cast 'Knockdown'");
-- Strider Clutchmother SAI
SET @ENTRY := 2172;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,11000,15000,18000,11,7272,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strider Clutchmother - In Combat - Cast 'Dust Cloud'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,20000,25000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strider Clutchmother - Within 0-5 Range - Cast 'Lash'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strider Clutchmother - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Teegan Holloway SAI
SET @ENTRY := 34033;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Aggro - Cast 'Shadow Charge' (No Repeat)"),
(@ENTRY,0,1,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,20000,30000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - Out of Combat - Say Line 1"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,14000,11,38926,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teegan Holloway - In Combat - Cast 'Dark Strike'");
-- NPC talk text insert
SET @ENTRY := 34033;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Your flesh is forfeit!',12,0,100,0,0,0, 'on Aggro Text',34163),
(@ENTRY,1,0, 'I said, SEARCH the bodies BEFORE you eat them!',12,0,100,0,0,0, 'OOC Text',34167);
-- Twilight Fanatic SAI
SET @ENTRY := 32888;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,75019,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Fanatic - In Combat - Cast 'Twilight's Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Fanatic - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,3,0,0,100,0,5000,6000,35000,40000,11,75021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Fanatic - In Combat - Cast 'Prismatic Gaze'"),
(@ENTRY,0,3,0,61,0,35,1,5000,6000,35000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Fanatic - In Combat - Say Line 1");
-- NPC talk text insert
SET @ENTRY := 32888;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,1,0, 'Intruders! Good, I was getting bored...',12,0,50,0,0,0, 'combat Text',840),
(@ENTRY,1,1, 'Masters, I pledge this Pin to you!',14,0,50,0,0,0, 'combat Text',835);
-- Twilight Rider SAI
SET @ENTRY := 34282;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,65060,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Rider - In Combat - Cast 'Twilight Bolt'");
-- Twilight Worker SAI
SET @ENTRY := 34405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worker - On Aggro - Cast 'Throw Rock' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,17000,21000,11,75059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worker - In Combat - Cast 'Shatter Armor'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worker - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Twilight Zealot SAI
SET @ENTRY := 33057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,75019,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Zealot - In Combat - Cast 'Twilight's Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Zealot - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,35000,40000,11,75021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Zealot - In Combat - Cast 'Prismatic Gaze'");
-- Unbound Fire Elemental SAI
SET @ENTRY := 32999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Fire Elemental - On Aggro - Cast 'Rush of Flame' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,9000,15000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Fire Elemental - In Combat - Cast 'Flame Shock'");
-- Vile Corruptor SAI
SET @ENTRY := 33022;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,17000,22000,11,75061,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Corruptor - In Combat - Cast 'Taste of Corruption'");
-- Vile Grell SAI
SET @ENTRY := 33021;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,32000,35000,11,75060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Grell - In Combat - Cast 'Critical Focus'");
-- Vile Spray SAI
SET @ENTRY := 32928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,25000,27000,11,39207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Spray - In Combat - Cast 'Water Spout'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,11000,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Spray - In Combat - Cast 'Water Bolt'");
-- Warlord Wrathspine SAI
SET @ENTRY := 34423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,12000,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Wrathspine - In Combat - Cast 'Knockdown'");
-- Whitetail Stag SAI
SET @ENTRY := 34318;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitetail Stag - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,15000,11,31274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitetail Stag - In Combat - Cast 'Knockdown'");
-- Wildkin Spirit SAI
SET @ENTRY := 34304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildkin Spirit - In Combat - Cast 'Moonfire'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,24000,27000,11,75011,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildkin Spirit - Between 0-50% Health - Cast 'Lunar Blessing'");
-- Windmaster Tzu-Tzu SAI
SET @ENTRY := 32989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windmaster Tzu-Tzu - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,9000,11000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Windmaster Tzu-Tzu - In Combat - Cast 'Earth Shock'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,17000,25000,11,34079,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windmaster Tzu-Tzu - In Combat - Cast 'Grounding Totem'");
-- NPC talk text insert
SET @ENTRY := 32989;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Ya be messin\' with Tzu-Tzu? It no matter...Aetherion\'s here,mon.We gonna roll on ya refugee camp an\' then bring the hurt to ya Lor\'demal.But first ya die!',12,0,100,0,0,0, 'on Aggro Text',33219);
-- Withered Ent SAI
SET @ENTRY := 34009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,19000,22000,11,11442,0,0,0,0,0,2,32,0,0,0,0,0,0,"Withered Ent - In Combat - Cast 'Withered Touch'");
-- Writhing Highborne SAI
SET @ENTRY := 33180;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,15000,16000,11,75017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Writhing Highborne - In Combat - Cast 'Curse of Doom'");
-- Yoth'al the Devourer SAI
SET @ENTRY := 34331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yoth'al the Devourer - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,75073,2,0,0,0,0,1,0,0,0,0,0,0,0,"Yoth'al the Devourer - Within 0-8 Range - Cast 'Shadow Nova'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,24000,27000,11,16568,2,0,0,0,0,2,0,0,0,0,0,0,0,"Yoth'al the Devourer - In Combat - Cast 'Mind Flay'");
-- Young Grizzled Thistle Bear SAI
SET @ENTRY := 34417;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Young Grizzled Thistle Bear - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,7000,10000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Young Grizzled Thistle Bear - In Combat - Cast 'Ravage'");
-- Zenn Foulhoof SAI
SET @ENTRY := 33020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,25000,28000,11,21062,0,0,0,0,0,2,32,0,0,0,0,0,0,"Zenn Foulhoof - In Combat - Cast 'Putrid Breath'");
