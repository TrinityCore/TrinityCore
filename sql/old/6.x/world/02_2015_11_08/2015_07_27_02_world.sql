-- 
-- DB/SAI: Update Tanaris
-- Ainamiss the Hive Queen SAI
SET @ENTRY := 47386;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ainamiss the Hive Queen - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,16000,21000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ainamiss the Hive Queen - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,23000,25000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ainamiss the Hive Queen - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,0,0,100,0,12000,13000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ainamiss the Hive Queen - In Combat - Cast 'Silithid Toxin'");
-- Andre Firebeard SAI
SET @ENTRY := 44759;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,83622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Andre Firebeard - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,6500,18500,21000,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Andre Firebeard - In Combat - Cast 'Swashbuckling Slice'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,14000,17500,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Andre Firebeard - Between 0-40% Health - Cast 'Bloodbath'");
-- Aquementas the Unchained SAI
SET @ENTRY := 44761;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,12000,14500,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aquementas the Unchained - Within 0-20 Range - Cast 'Frost Shock'"),
(@ENTRY,0,1,0,9,0,100,0,0,10,20000,24000,11,10987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aquementas the Unchained - Within 0-10 Range - Cast 'Geyser'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,17000,25000,11,83669,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aquementas the Unchained - In Combat - Cast 'Water Bolt'");
-- Basking Cobra SAI
SET @ENTRY := 40657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,16000,17000,11,32093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Basking Cobra - In Combat - Cast 'Poison Spit'");
-- Bilgewater Battlebruiser SAI
SET @ENTRY := 38648;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,16500,18200,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bilgewater Battlebruiser - Between 0-55% Health - Cast 'Bloodbath'");
-- Blisterpaw Hyena SAI
SET @ENTRY := 5426;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,9,15000,17800,11,82797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blisterpaw Hyena - Within 0-9 Range - Cast 'Leaping Bite'");
-- Burning Southsea Pirate SAI
SET @ENTRY := 38719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,83622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Southsea Pirate - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Southsea Pirate - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Caliph Scorpidsting SAI
SET @ENTRY := 44750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,16500,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caliph Scorpidsting - In Combat - Cast 'Poison'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,9000,9800,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caliph Scorpidsting - Between 0-40% Health - Cast 'Sand Step'");
-- Captain Dreadbeard SAI
SET @ENTRY := 38749;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6500,18500,21000,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Dreadbeard - In Combat - Cast 'Swashbuckling Slice'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,14000,17500,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Dreadbeard - Between 0-40% Health - Cast 'Bloodbath'");
-- Centipaar Sandreaver SAI
SET @ENTRY := 5460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Centipaar Sandreaver - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Sandreaver - In Combat - Cast 'Silithid Toxin'"),
(@ENTRY,0,2,0,0,0,100,0,2000,3200,9000,9100,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Centipaar Sandreaver - In Combat - Cast 'Thrash'");
-- Centipaar Tunneler SAI
SET @ENTRY := 5459;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,14500,16800,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Tunneler - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Tunneler - In Combat - Cast 'Silithid Toxin'");
-- Centipaar Wasp SAI
SET @ENTRY := 5455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,18500,22000,11,81109,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Wasp - In Combat - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Wasp - In Combat - Cast 'Silithid Toxin'");
-- Centipaar Worker SAI
SET @ENTRY := 5458;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,18500,22000,11,83574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Worker - In Combat - Cast 'Acidic Adhesive'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Centipaar Worker - In Combat - Cast 'Silithid Toxin'");
-- Covert Ops Pounder SAI
SET @ENTRY := 38649;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8500,18500,21600,11,35049,0,0,0,0,0,2,0,0,0,0,0,0,0,"Covert Ops Pounder - In Combat - Cast 'Pound'");
-- Crazed Bilgewater Survivor SAI
SET @ENTRY := 39020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Bilgewater Survivor - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,16000,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Bilgewater Survivor - In Combat - Cast 'Bonk'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,14000,21000,11,83586,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Bilgewater Survivor - Between 0-40% Health - Cast 'Insane Rambling'");
-- NPC talk text insert
SET @ENTRY := 39020;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Monsters! Monsters come to take our gold!',14,0,50,0,0,0, 'on Aggro Text',40525),
(@ENTRY,0,1, 'Kill the pig! Spill it\'s blood!',14,0,50,0,0,0, 'on Aggro Text',40528);
-- Desert Bloom SAI
SET @ENTRY := 44598;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,48195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Aggro - Cast 'Emerald Lasher Emerge' (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Aggro - Remove Flag Standstate Submerged (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,2,1,100,1,0,30,0,0,11,83504,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - Between 0-30% Health - Cast 'Healing Rain' (Phase 1) (No Repeat)"),
(@ENTRY,0,4,0,7,1,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Evade - Set Event Phase 2 (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,7,2,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Evade - Remove Flag Standstate Submerged (Phase 2) (No Repeat)"),
(@ENTRY,0,6,0,21,2,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Bloom - On Reached Home - Set Flag Standstate Submerged (Phase 2) (No Repeat)");
-- Desert Crawler SAI
SET @ENTRY := 40764;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,22000,23000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Crawler - Between 0-50% Health - Cast 'Harden'");
-- Dune Rattler SAI
SET @ENTRY := 44568;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,18000,20000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dune Rattler - In Combat - Cast 'Poison'");
-- Duneclaw Broodlord SAI
SET @ENTRY := 44599;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,17000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duneclaw Broodlord - In Combat - Cast 'Venom Splash'");
-- Duneclaw Burrower SAI
SET @ENTRY := 44546;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,9000,9800,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duneclaw Burrower - Between 0-55% Health - Cast 'Sand Step'");
-- Duneclaw Lasher SAI
SET @ENTRY := 40717;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,18000,22000,11,33126,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duneclaw Lasher - Within 0-5 Range - Cast 'Dropped Weapon'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,25000,33000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duneclaw Lasher - In Combat - Cast 'Lash'");
-- Duneclaw Stalker SAI
SET @ENTRY := 44587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,9000,9800,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duneclaw Stalker - Between 0-55% Health - Cast 'Sand Step'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duneclaw Stalker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duneclaw Stalker - On Evade - Cast 'Stealth' (No Repeat)");
-- Dunemaul Brute SAI
SET @ENTRY := 5474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Brute - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,16000,18000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Brute - Within 0-5 Range - Cast 'Uppercut'");
-- NPC talk text insert
SET @ENTRY := 5474;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dunemaul Enforcer SAI
SET @ENTRY := 5472;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Enforcer - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,10,24000,26000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Enforcer - Within 0-10 Range - Cast 'Demoralizing Shout'");
-- NPC talk text insert
SET @ENTRY := 5472;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dunemaul Ogre SAI
SET @ENTRY := 5471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,12800,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre - Within 0-5 Range - Cast 'Heroic Strike'");
-- NPC talk text insert
SET @ENTRY := 5471;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dunemaul Ogre Mage SAI
SET @ENTRY := 5473;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,19000,11,11436,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - In Combat - Cast 'Slow'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,3,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5473;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dunemaul Warlock SAI
SET @ENTRY := 5475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,15000,17800,11,6909,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Curse of Thorns'");
-- NPC talk text insert
SET @ENTRY := 5475;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Duneshore Crab SAI
SET @ENTRY := 40527;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,22000,23000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duneshore Crab - Between 0-50% Health - Cast 'Harden'");
-- Emberwing SAI
SET @ENTRY := 8207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,13600,14500,11,11970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emberwing - Within 0-8 Range - Cast 'Fire Nova'");
-- Explorer's League Digger SAI
SET @ENTRY := 38998;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Explorer's League Digger - On Aggro - Cast 'Bone Toss' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,17000,22000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Explorer's League Digger - In Combat - Cast 'Dirt Toss'");
-- Fire Roc SAI
SET @ENTRY := 5429;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,19000,22000,11,24423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fire Roc - Within 0-8 Range - Cast 'Demoralizing Screech'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,15000,15500,11,11021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fire Roc - In Combat - Cast 'Flamespit'");
-- Fronkle the Disturbed SAI
SET @ENTRY := 44714;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,14500,15200,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fronkle the Disturbed - Within 0-8 Range - Cast 'Arcane Explosion'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,15000,18000,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fronkle the Disturbed - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,2,0,0,0,100,0,4000,4800,13000,14000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fronkle the Disturbed - In Combat - Cast 'Slow'");
-- Gadgetzan Bruiser SAI
SET @ENTRY := 9460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gadgetzan Bruiser - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,19,5000,6000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gadgetzan Bruiser - Within 0-19 Range - Cast 'Net'");
-- Gadgetzan Sniper SAI
SET @ENTRY := 21448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,19,5000,6000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gadgetzan Sniper - Within 0-19 Range - Cast 'Net'");
-- Gargantapid SAI
SET @ENTRY := 40581;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,22000,23000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gargantapid - Between 0-50% Health - Cast 'Harden'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,15000,17000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gargantapid - In Combat - Cast 'Venom Splash'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,9000,9800,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gargantapid - Between 0-40% Health - Cast 'Sand Step'");
-- Glasshide Basilisk SAI
SET @ENTRY := 5419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,16000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glasshide Basilisk - In Combat - Cast 'Crystal Flash'");
-- Glasshide Gazer SAI
SET @ENTRY := 5420;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,16000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glasshide Gazer - In Combat - Cast 'Crystal Flash'"),
(@ENTRY,0,1,0,2,0,100,0,0,60,12000,13000,11,83497,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glasshide Gazer - Between 0-60% Health - Cast 'Glass Hide'");
-- Great Shark SAI
SET @ENTRY := 12124;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,9800,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Great Shark - In Combat - Cast 'Thrash'");
-- Gusting Vortex SAI
SET @ENTRY := 8667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,12000,14000,11,83492,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gusting Vortex - In Combat - Cast 'Air Blast'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,22000,26000,11,6982,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gusting Vortex - In Combat - Cast 'Gust of Wind'");
-- Haarka the Ravenous SAI
SET @ENTRY := 8205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,9800,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haarka the Ravenous - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haarka the Ravenous - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Haarka the Ravenous - In Combat - Cast 'Silithid Toxin'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haarka the Ravenous - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haarka the Ravenous - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 8205;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Harakiss the Infestor SAI
SET @ENTRY := 47387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,9800,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harakiss the Infestor - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harakiss the Infestor - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harakiss the Infestor - In Combat - Cast 'Silithid Toxin'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harakiss the Infestor - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harakiss the Infestor - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 47387;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Hazzali Cocoon SAI
SET @ENTRY := 39081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,73441,3,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Cocoon - On Just Died - Cast 'Summon Captured Bughunter' (No Repeat)");
-- Hazzali Sandreaver SAI
SET @ENTRY := 5454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,9800,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Sandreaver - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Sandreaver - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Sandreaver - In Combat - Cast 'Silithid Toxin'");
-- Hazzali Stinger SAI
SET @ENTRY := 5450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,9800,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Stinger - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Stinger - In Combat - Cast 'Silithid Toxin'");
-- Hazzali Swarmer SAI
SET @ENTRY := 5451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,10722,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Swarmer - On Aggro - Cast 'Silithid Swarm' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Swarmer - In Combat - Cast 'Silithid Toxin'");
-- Hazzali Worker SAI
SET @ENTRY := 5452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,83574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Worker - In Combat - Cast 'Acidic Adhesive'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,25000,27000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzali Worker - In Combat - Cast 'Silithid Toxin'");
-- Hellgazer SAI
SET @ENTRY := 39186;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,16000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellgazer - In Combat - Cast 'Crystal Flash'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,24000,27000,11,83657,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hellgazer - In Combat - Cast 'Hellgaze'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellgazer - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellgazer - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 39186;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Jin'Zallah the Sandbringer SAI
SET @ENTRY := 8200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jin'Zallah the Sandbringer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,7272,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jin'Zallah the Sandbringer - Within 0-8 Range - Cast 'Dust Cloud'"),
(@ENTRY,0,2,0,2,0,100,1,0,55,0,0,11,10132,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jin'Zallah the Sandbringer - Between 0-55% Health - Cast 'Sand Storms' (No Repeat)");
-- Kregg Keelhaul SAI
SET @ENTRY := 8203;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,83622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kregg Keelhaul - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,24000,28000,11,83643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kregg Keelhaul - In Combat - Cast 'Slippery Suds'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,12000,14000,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kregg Keelhaul - In Combat - Cast 'Swashbuckling Slice'");
-- Land Rager SAI
SET @ENTRY := 5465;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,16000,11,8117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Land Rager - In Combat - Cast 'Agility'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Land Rager - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Land Rager - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5465;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Meatface SAI
SET @ENTRY := 39061;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Meatface - In Combat - Cast 'Uppercut'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meatface - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meatface - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 39061;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Occulus the Corrupted SAI
SET @ENTRY := 44767;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,16000,11,31464,0,0,0,0,0,2,0,0,0,0,0,0,0,"Occulus the Corrupted - In Combat - Cast 'Mortal Wound'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,24000,28000,11,32914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Occulus the Corrupted - In Combat - Cast 'Wing Buffet'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,15000,24000,11,31458,0,0,0,0,0,1,0,0,0,0,0,0,0,"Occulus the Corrupted - Between 0-50% Health - Cast 'Hasten'");
-- Omgorn the Lost SAI
SET @ENTRY := 8201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Omgorn the Lost - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Omgorn the Lost - Within 0-5 Range - Cast 'Mortal Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Omgorn the Lost - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Omgorn the Lost - Between 0-30% Health - Say Line 1 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 8201;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Rabid Blisterpaw SAI
SET @ENTRY := 5427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,9,15000,17800,11,82797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Blisterpaw - Within 0-9 Range - Cast 'Leaping Bite'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,25000,29000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Blisterpaw - In Combat - Cast 'Rabies'");
-- Reliquary Digger SAI
SET @ENTRY := 38997;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,18000,25000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reliquary Digger - In Combat - Cast 'Dirt Toss'"),
(@ENTRY,0,1,0,9,0,100,0,5,20,5000,6000,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reliquary Digger - Within 5-20 Range - Cast 'Bone Toss'");
-- Rental Shredder SAI
SET @ENTRY := 38650;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,9,0,100,0,0,20,8000,14000,11,36228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rental Shredder - Within 0-20 Range - Cast 'Chainsaw Blade'");
-- Sand Lasher SAI
SET @ENTRY := 44569;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,48195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Aggro - Cast 'Emerald Lasher Emerge' (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Aggro - Remove Flag Standstate Submerged (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,0,1,100,0,3000,5000,12000,15000,11,43619,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Lasher - In Combat - Cast 'Wrath' (Phase 1)"),
(@ENTRY,0,4,0,7,1,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Evade - Set Event Phase 2 (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,7,2,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Evade - Remove Flag Standstate Submerged (Phase 2) (No Repeat)"),
(@ENTRY,0,6,0,21,2,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Lasher - On Reached Home - Set Flag Standstate Submerged (Phase 2) (No Repeat)");
-- Sand Slitherer SAI
SET @ENTRY := 44595;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,0,0,20,9000,13000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Slitherer - Target Between 0-20% Health - Cast 'Fatal Bite'");
-- Sandfury Axe Thrower SAI
SET @ENTRY := 5646;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Axe Thrower - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-30% Health - Say Line 1 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5646;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,1,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Sandfury Firecaller SAI
SET @ENTRY := 5647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,82641,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - In Combat - Cast 'Lava Gout'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,33000,35000,11,79886,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - In Combat - Cast 'Lava Burst'");
-- Sandfury Hideskinner SAI
SET @ENTRY := 5645;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Hideskinner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,15000,18000,11,81705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Hideskinner - In Combat - Cast 'Scalp Slash'");
-- Sandfury Zombie SAI
SET @ENTRY := 38909;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,83507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Zombie - Between 0-30% Health - Cast 'Unnatural Power' (No Repeat)");
-- Sandfury Zombie SAI
SET @ENTRY := 44557;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,83507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Zombie - Between 0-30% Health - Cast 'Unnatural Power' (No Repeat)");
-- Sandscraper SAI
SET @ENTRY := 38880;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandscraper - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandscraper - Within 0-5 Range - Cast 'Mortal Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandscraper - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandscraper - Between 0-30% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,6000,9000,24000,28000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandscraper - In Combat - Cast 'Cleave'");
-- NPC talk text insert
SET @ENTRY := 38880;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Sandstone Earthen SAI
SET @ENTRY := 38916;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,9000,18000,24000,11,73864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandstone Earthen - In Combat - Cast 'Sand Trap'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,11000,12000,11,83567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandstone Earthen - Between 0-40% Health - Cast 'Sparkling Sands'");
-- Sandstone Golem SAI
SET @ENTRY := 38914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,24000,26000,11,80380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandstone Golem - In Combat - Cast 'Sand Breath'");
-- Scorpid Duneburrower SAI
SET @ENTRY := 7803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,14000,16000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Duneburrower - In Combat - Cast 'Venom Sting'");
-- Scorpitar SAI
SET @ENTRY := 39183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,22000,23000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpitar - Between 0-50% Health - Cast 'Harden'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,15000,17000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpitar - In Combat - Cast 'Venom Splash'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,9000,9800,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpitar - Between 0-40% Health - Cast 'Sand Step'");
-- Searing Roc SAI
SET @ENTRY := 5430;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,18000,20000,11,16843,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Roc - In Combat - Cast 'Crimson Fury'");
-- Slaverjaw SAI
SET @ENTRY := 39185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,9,15000,17800,11,82797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slaverjaw - Within 0-9 Range - Cast 'Leaping Bite'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,18000,20000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slaverjaw - In Combat - Cast 'Infected Bite'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,25000,28000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slaverjaw - In Combat - Cast 'Furious Howl'");
-- Soriid the Devourer SAI
SET @ENTRY := 8204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soriid the Devourer - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,16000,21000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soriid the Devourer - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,23000,25000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soriid the Devourer - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,0,0,100,0,12000,13000,60000,65000,11,81224,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soriid the Devourer - In Combat - Cast 'Silithid Toxin'");
-- Southsea Musketeer SAI
SET @ENTRY := 40632;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6600,64,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Musketeer - In Combat - Cast 'Salt Flats Racer Speed'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Musketeer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,22000,24000,11,79721,1,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Musketeer - In Combat - Cast 'Explosive Shot'");
-- Southsea Pirate SAI
SET @ENTRY := 7855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,83622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Pirate - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Pirate - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Southsea Scoundrel SAI
SET @ENTRY := 40665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Scoundrel - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 40665;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Ye\'ll not get around our blockade with scavengin\'!',12,0,100,0,0,0, 'on Aggro Text',40574);
-- Southsea Strongarm SAI
SET @ENTRY := 40635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,82742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Strongarm - On Aggro - Cast 'Impaling Pull' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Strongarm - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Southsea Swabbie SAI
SET @ENTRY := 40636;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,18000,24000,11,83643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Swabbie - In Combat - Cast 'Slippery Suds'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Swabbie - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Southsea Swashbuckler SAI
SET @ENTRY := 7858;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Swashbuckler - In Combat - Cast 'Swashbuckling Slice'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Swashbuckler - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,13,0,100,0,2000,4500,20000,30000,11,79732,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Swashbuckler - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");
-- Southsea Taskmaster SAI
SET @ENTRY := 40593;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,12000,16000,11,81754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Taskmaster - In Combat - Cast 'Motivate'"),
(@ENTRY,0,1,0,9,0,100,0,0,15,34000,37000,11,81753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Taskmaster - Within 0-15 Range - Cast 'Threatening Shout'");
-- Steeljaw Snapper SAI
SET @ENTRY := 14123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,8000,12000,11,83488,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steeljaw Snapper - Between 0-40% Health - Cast 'Shell Shield'");
-- Sunburst Adder SAI
SET @ENTRY := 44594;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,18000,22000,11,78808,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunburst Adder - In Combat - Cast 'Sunbeam'");
-- Surf Glider SAI
SET @ENTRY := 5431;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,8000,12000,11,83488,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surf Glider - Between 0-40% Health - Cast 'Shell Shield'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,15000,11,78799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surf Glider - In Combat - Cast 'Wave Crash'");
-- Tidal Strider SAI
SET @ENTRY := 39022;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,13000,17000,11,82376,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidal Strider - In Combat - Cast 'Frost Smash'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,18000,21000,11,10987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidal Strider - Within 0-8 Range - Cast 'Geyser'");
-- Twisted Reflection of Narain SAI
SET @ENTRY := 44722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twisted Reflection of Narain - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,75073,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twisted Reflection of Narain - Within 0-8 Range - Cast 'Shadow Nova'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,77471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twisted Reflection of Narain - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat)"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twisted Reflection of Narain - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 44722;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Could you forse this, fool?',12,0,100,0,0,0, 'on Aggro Text',44745);
-- Unearthed Fossil SAI
SET @ENTRY := 9397;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,20000,11,83562,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unearthed Fossil - In Combat - Cast 'Curse of Life'");
-- Warleader Krazzilak SAI
SET @ENTRY := 8199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,18000,24000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warleader Krazzilak - Within 0-8 Range - Cast 'Bladestorm'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,15000,17000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warleader Krazzilak - In Combat - Cast 'Knock Away'"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warleader Krazzilak - On Aggro - Cast 'Commanding Shout' (No Repeat)");
-- Wastewander Darkcaster SAI
SET @ENTRY := 44613;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Darkcaster - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,75073,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Darkcaster - Within 0-8 Range - Cast 'Shadow Nova'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,77471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Darkcaster - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat)");
-- Wastewander Survivalist SAI
SET @ENTRY := 44611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,25000,33000,11,80596,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Survivalist - Within 0-5 Range - Cast 'Explosive Trap'");
-- Wastewander Tracker SAI
SET @ENTRY := 44612;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Tracker - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,15,18000,21000,11,80009,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Tracker - Within 5-15 Range - Cast 'Serpent Sting'");
-- Zakkaru SAI
SET @ENTRY := 40648;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,83492,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zakkaru - In Combat - Cast 'Air Blast'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,16000,20000,11,6982,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zakkaru - Within 0-5 Range - Cast 'Gust of Wind'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,25000,26000,11,83493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zakkaru - Between 0-40% Health - Cast 'Blessing of Al'Akir'");
