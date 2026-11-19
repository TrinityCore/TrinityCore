-- 
-- DB/SAI: Update Thousand Needles
-- Achellios the Banished SAI
SET @ENTRY := 5933;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,81574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Achellios the Banished - On Aggro - Cast 'Charge' (No Repeat)");
-- Aerie Ace SAI
SET @ENTRY := 47528;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Aerie Ace - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,25000,29000,11,83014,1,0,0,0,0,2,0,0,0,0,0,0,0,"Aerie Ace - In Combat - Cast 'Rapid Shot'");
-- Arikara SAI
SET @ENTRY := 45447;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79085,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arikara - In Combat - Cast 'Lightning Bolt'");
-- Arnak Grimtotem SAI
SET @ENTRY := 45438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - On Aggro - Say Line 1 (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,11,85812,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - On Aggro - Cast 'Chieftan's Call' (No Repeat)"),
(@ENTRY,0,3,4,2,0,100,1,0,55,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - Between 0-55% Health - Say Line 2 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,55,0,0,11,85814,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - Between 0-55% Health - Cast 'Chieftan's Call' (No Repeat)"),
(@ENTRY,0,5,6,2,0,100,1,0,25,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - Between 0-25% Health - Say Line 3 (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,1,0,25,0,0,11,85815,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - Between 0-25% Health - Cast 'Chieftan's Call' (No Repeat)"),
(@ENTRY,0,7,8,6,0,100,1,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - On Just Died - Say Line 4 (No Repeat)"),
(@ENTRY,0,8,0,0,0,100,0,5000,6000,120000,125000,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arnak Grimtotem - In Combat - Cast 'Commanding Shout'"),
(@ENTRY,0,9,0,0,0,100,0,9000,15000,25000,26000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arnak Grimtotem - In Combat - Cast 'Rend'"),
(@ENTRY,0,10,0,0,0,100,0,6500,16500,9900,19500,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arnak Grimtotem - In Combat - Cast 'Bloodbath'");
-- NPC talk text insert
SET @ENTRY := 45438;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You\'re the one my aunt sent? A test, no doubt. I\'ll kill you quickly and prove myself to her once again.',14,0,100,0,0,0, 'on Aggro Text',45569),
(@ENTRY,1,0, 'Stompers, defend your Chieftan!',14,0,100,0,0,0, 'on Summon Text',46121),
(@ENTRY,2,0, 'Reavers, at my side!',14,0,100,0,0,0, 'at HP Text',46122),
(@ENTRY,3,0, 'Geomancers, bury them in stone and flame!',14,0,100,0,0,0, 'at HP Text',46123),
(@ENTRY,4,0, 'NO! Magatha, forgive me! Bring me back!',14,0,100,0,0,0, 'on Death Text',45570);
-- Brienna Starglow SAI
SET @ENTRY := 41444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,85563,64,0,0,0,0,2,0,0,0,0,0,0,0,"Brienna Starglow - In Combat - Cast 'Holy Fire'");
-- Brilliant Clayscraper SAI
SET @ENTRY := 48138;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15600,11,81678,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brilliant Clayscraper - In Combat - Cast 'Eye Peck'");
-- Brute Squad SAI
SET @ENTRY := 40512;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brute Squad - On Respawn - Cast 'Acidic Sweat' (No Repeat)");
-- Bulwark Defender SAI
SET @ENTRY := 47583;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,13600,14500,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bulwark Defender - Within 0-10 Range - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,82800,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bulwark Defender - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");
-- Cliffwatcher Longhorn SAI
SET @ENTRY := 41458;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliffwatcher Longhorn - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5500,18000,21500,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cliffwatcher Longhorn - In Combat - Cast 'Gore'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,13000,11,77773,0,0,0,0,0,4,0,0,0,0,0,0,0,"Cliffwatcher Longhorn - In Combat - Cast 'Sleep'");
-- Cloud Serpent SAI
SET @ENTRY := 4117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cloud Serpent - In Combat - Cast 'Lightning Bolt'");
-- Codemaster Deethuk SAI
SET @ENTRY := 47602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,9000,12000,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,"Codemaster Deethuk - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,5000,6000,11,79866,0,0,0,0,0,2,0,0,0,0,0,0,0,"Codemaster Deethuk - Within 5-30 Range - Cast 'Deadly Throw'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,79864,0,0,0,0,0,2,0,0,0,0,0,0,0,"Codemaster Deethuk - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,8000,11000,23000,26500,11,79863,0,0,0,0,0,2,0,0,0,0,0,0,0,"Codemaster Deethuk - In Combat - Cast 'Hemorrhage'");
-- Commander Fastfuse SAI
SET @ENTRY := 47620;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Fastfuse - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,40,20000,21000,11,79878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Fastfuse - Between 0-40% Health - Cast 'Bloodthirst'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,16000,17000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Fastfuse - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,0,0,100,0,8000,9000,22000,28000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Fastfuse - In Combat - Cast 'Slam'");
-- Den Whomper SAI
SET @ENTRY := 40959;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Den Whomper - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,17000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Den Whomper - Within 0-5 Range - Cast 'Uppercut'"),
(@ENTRY,0,2,0,2,0,100,0,0,60,14000,16000,11,4955,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Whomper - Between 0-60% Health - Cast 'Fist of Stone'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,32000,35000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Whomper - Between 0-30% Health - Cast 'Bloodlust'");
-- NPC talk text insert
SET @ENTRY := 40959;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925);
-- Elder Stormhoof SAI
SET @ENTRY := 45410;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,3,0,0,1,100,0,3000,4500,25000,27000,11,85862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - In Combat - Cast 'Mortar Being Fired' (Phase 1)"),
(@ENTRY,0,4,5,2,1,100,1,0,75,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-75% Health - Set Event Phase 2 (Phase 1) (No Repeat)"),
(@ENTRY,0,5,6,61,1,100,1,0,75,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-75% Health - Say Line 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,6,7,61,1,100,1,0,75,0,0,11,85695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-75% Health - Cast 'Commune With Spirits' (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,61,1,100,1,0,75,0,0,11,85709,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-75% Health - Cast 'Blessed by Fire' (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,0,2,100,0,6000,8000,33000,36000,11,85714,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Stormhoof - In Combat - Cast 'Lava Burst' (Phase 2)"),
(@ENTRY,0,9,0,0,2,100,0,12000,16000,19000,21000,11,85718,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Stormhoof - In Combat - Cast 'Firebloom' (Phase 2)"),
(@ENTRY,0,10,11,2,2,100,1,0,50,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-50% Health - Set Event Phase 4 (Phase 2) (No Repeat)"),
(@ENTRY,0,11,12,61,2,100,1,0,50,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-50% Health - Say Line 2 (Phase 2) (No Repeat)"),
(@ENTRY,0,12,13,61,2,100,1,0,50,0,0,11,85707,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-50% Health - Cast 'Commune With Spirits' (Phase 2) (No Repeat)"),
(@ENTRY,0,13,0,61,2,100,1,0,50,0,0,11,85711,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - Between 0-50% Health - Cast 'Blessed by Air' (Phase 2) (No Repeat)"),
(@ENTRY,0,14,0,0,4,100,0,2000,4500,12000,15000,11,85715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Stormhoof - In Combat - Cast 'Chain Lightning' (Phase 4)"),
(@ENTRY,0,15,0,6,4,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormhoof - On Just Died - Say Line 3 (Phase 4) (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 45410;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Chosen of the Elder Crone! You don''t realize yet, do you? I''ll put an end to you first! You and your friend!',14,0,100,0,0,0, 'on Aggro Text',45557),
(@ENTRY,1,0, 'Spirits of the Firelands, fill me with your rage!',14,0,100,0,0,0, 'in Battle Text',46085),
(@ENTRY,2,0, 'Spirits of Skywall, heed my call!',14,0,100,0,0,0, 'in Battle Text',46087),
(@ENTRY,3,0, 'Why would she choose... an outsider?',12,0,100,0,0,0, 'on Death Text',45558);
-- Elementalist Starion SAI
SET @ENTRY := 47619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79564,64,0,0,0,0,2,0,0,0,0,0,0,0,"Elementalist Starion - In Combat - Cast 'Twilight Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,12000,14000,11,80117,1,0,0,0,0,2,0,0,0,0,0,0,0,"Elementalist Starion - In Combat - Cast 'Earth Spike'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,24000,27000,11,79886,1,0,0,0,0,2,0,0,0,0,0,0,0,"Elementalist Starion - In Combat - Cast 'Lava Burst'"),
(@ENTRY,0,3,0,0,0,100,0,4000,17000,25000,36000,11,88771,1,0,0,0,0,2,0,0,0,0,0,0,0,"Elementalist Starion - In Combat - Cast 'Twilight Immolate'");
-- Evil Dolly SAI
SET @ENTRY := 41076;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Evil Dolly - In Combat - Cast 'Shadowstrike'");
-- Freewind Warrior SAI
SET @ENTRY := 41439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,19000,11,81500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freewind Warrior - In Combat - Cast 'War Stomp'");
-- Galak Mauler SAI
SET @ENTRY := 40062;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,22000,25000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Mauler - Within 0-8 Range - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,20000,11,74720,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Mauler - In Combat - Cast 'Pound'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Mauler - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Galak Mauler SAI
SET @ENTRY := 41302;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,22000,25000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Mauler - Within 0-8 Range - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,20000,11,74720,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Mauler - In Combat - Cast 'Pound'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Mauler - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Galak Stormer SAI
SET @ENTRY := 41305;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,25000,30000,11,6535,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - In Combat - Cast 'Lightning Cloud'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");
-- Galak Stormer SAI
SET @ENTRY := 40061;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,25000,30000,11,6535,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - In Combat - Cast 'Lightning Cloud'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");
-- Galak Wrangler SAI
SET @ENTRY := 40063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,4000,6000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - Within 0-20 Range - Cast 'Net'");
-- Galak Wrangler SAI
SET @ENTRY := 41306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,4000,6000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - Within 0-20 Range - Cast 'Net'");
-- Gibblesnik SAI
SET @ENTRY := 14427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gibblesnik - In Combat - Cast 'Sunder Armor'");
-- Grimtotem Geomancer SAI
SET @ENTRY := 45381;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Geomancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,18000,24000,11,79886,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Geomancer - In Combat - Cast 'Lava Burst'");
-- Grimtotem Invader SAI
SET @ENTRY := 41431;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Invader - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,12000,13500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Invader - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,22000,11,81500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Invader - Within 0-8 Range - Cast 'War Stomp'");
-- Grimtotem Pillager SAI
SET @ENTRY := 39947;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Pillager - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,11000,14000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Pillager - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Pillager - On Aggro - Cast 'Battle Stance' (No Repeat)");
-- Grimtotem Reaver SAI
SET @ENTRY := 45385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Reaver - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,8,24000,26000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Reaver - Within 0-8 Range - Cast 'Bladestorm'");
-- Grimtotem Stomper SAI
SET @ENTRY := 45383;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Stomper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,81219,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Stomper - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,22000,11,81500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Stomper - Within 0-8 Range - Cast 'War Stomp'");
-- Grundig Darkcloud SAI
SET @ENTRY := 45418;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,85791,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grundig Darkcloud - Between 0-30% Health - Cast 'Rage of the Darkcloud' (No Repeat)");
-- Harb Foulmountain SAI
SET @ENTRY := 14426;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,10500,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harb Foulmountain - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,16000,18000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harb Foulmountain - In Combat - Cast 'War Stomp'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harb Foulmountain - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harb Foulmountain - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 14426;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Highperch Wind Rider SAI
SET @ENTRY := 47485;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,18000,20000,11,81376,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highperch Wind Rider - In Combat - Cast 'Pridewing Poison'");
-- Hive Controller SAI
SET @ENTRY := 47389;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,19000,20000,11,19469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive Controller - In Combat - Cast 'Poison Mind'");
-- Isha Gloomaxe SAI
SET @ENTRY := 45387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,17000,19000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Isha Gloomaxe - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,24000,26000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,"Isha Gloomaxe - In Combat - Cast 'Sundering Cleave'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,78943,0,0,0,0,0,1,0,0,0,0,0,0,0,"Isha Gloomaxe - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Isha Gloomaxe - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 45387;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Kravel Koalbeard SAI
SET @ENTRY := 41196;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38557,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kravel Koalbeard - In Combat - Cast 'Throw'");
-- Krkk'kx SAI
SET @ENTRY := 4132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,21400,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krkk'kx - In Combat - Cast 'Strong Cleave'");
-- Lilly Landlubber SAI
SET @ENTRY := 41082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,17000,11,3551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lilly Landlubber - In Combat - Cast 'Skull Crack'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lilly Landlubber - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Kick'");
-- Mad Magus Tirth SAI
SET @ENTRY := 41131;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Magus Tirth - In Combat - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,11975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Magus Tirth - Within 0-8 Range - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,33000,35000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Magus Tirth - Between 0-40% Health - Cast 'Bloodlust'"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,18000,20000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Magus Tirth - In Combat - Cast 'Slow'");
-- Needlespine Shimmerback SAI
SET @ENTRY := 48132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,11000,14000,11,36594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Needlespine Shimmerback - In Combat - Cast 'Lightning Breath'");
-- Rau Cliffrunner SAI
SET @ENTRY := 41421;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rau Cliffrunner - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,12000,13000,11,79872,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rau Cliffrunner - In Combat - Cast 'Shockwave'");
-- Razorfen Thornweaver SAI
SET @ENTRY := 7874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,7966,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Thornweaver - Out of Combat - Cast 'Thorns Aura'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,11431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Thornweaver - Between 0-30% Health - Cast 'Healing Touch' (No Repeat)");
-- Scorpid Cliffcrawler SAI
SET @ENTRY := 48130;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,18000,20000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Cliffcrawler - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,33000,36000,11,7399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Cliffcrawler - In Combat - Cast 'Terrify'");
-- Seadog Fajardo SAI
SET @ENTRY := 41081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,17000,11,3551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seadog Fajardo - In Combat - Cast 'Skull Crack'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,24000,25000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seadog Fajardo - In Combat - Cast 'Torch Toss'");
-- Shackled Earth SAI
SET @ENTRY := 47816;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,15600,17800,11,79872,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shackled Earth - In Combat - Cast 'Shockwave'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,24000,27000,11,86725,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shackled Earth - In Combat - Cast 'Upheaved Earth'");
-- Silithid Defender SAI
SET @ENTRY := 47390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,15000,18000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Defender - In Combat - Cast 'Cripple'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,25000,29000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Defender - In Combat - Cast 'Disarm'");
-- Silithid Ravager SAI
SET @ENTRY := 47388;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13500,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Ravager - In Combat - Cast 'Strong Cleave'");
-- Silithid Ravager SAI
SET @ENTRY := 48178;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13500,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Ravager - In Combat - Cast 'Strong Cleave'");
-- Silithid Ravager SAI
SET @ENTRY := 48177;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13500,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Ravager - In Combat - Cast 'Strong Cleave'");
-- Silithid Wasp SAI
SET @ENTRY := 48179;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13500,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Wasp - In Combat - Cast 'Strong Cleave'");
-- Jadefire Shifter SAI
SET @ENTRY := 48154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86073,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Shifter - On Aggro - Cast 'Flamethrower' (No Repeat)");
-- Southsea Engineer SAI
SET @ENTRY := 46151;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86090,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Engineer - On Aggro - Cast 'High-Powered Shot' (No Repeat)");
-- Southsea Grenadier SAI
SET @ENTRY := 46149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,86088,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Grenadier - On Aggro - Cast 'Throw Dynamite' (No Repeat)");
-- Southsea Parrot Handler SAI
SET @ENTRY := 40432;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,7000,8000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Parrot Handler - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,14000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Parrot Handler - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Parrot Handler - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Southsea Sailor SAI
SET @ENTRY := 40092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,12000,13000,11,74759,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Sailor - In Combat - Cast 'Bottle of Grog'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Sailor - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Southsea Treasure Hunter SAI
SET @ENTRY := 40449;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,60,18000,19000,11,79444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Treasure Hunter - Within 0-60 Range - Cast 'Impale'");
-- Summit Defender SAI
SET @ENTRY := 39951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Summit Defender - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summit Defender - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,120000,125000,11,74606,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summit Defender - Within 0-8 Range - Cast 'War Stomp'");
-- Trackmaster Zherin SAI
SET @ENTRY := 41199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Trackmaster Zherin - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13000,14000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Trackmaster Zherin - Within 0-5 Range - Cast 'Heroic Strike'");
-- Twilight Jailer SAI
SET @ENTRY := 47630;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,30,0,500,1000,600000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Jailer - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,13000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Jailer - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,18000,22000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Jailer - In Combat - Cast 'Sunder Armor'");
-- NPC talk text insert
SET @ENTRY := 47630;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Hey, you haven\'t seen grom-grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,1, 'Hey, you haven''t seen Grom-Grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,2, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,3, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,4, 'Do i know you? No? Welcome to the Twilight\'s Hammer.',12,0,50,1,0,0, 'say Text',47997),
(@ENTRY,0,5, 'Something big\'s brewing at the Withering to the east.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,6, 'Whatever it is, i hope that it\'ll be over soon and we get restationed somewhere nicer.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,7, 'The end days are nigh!',12,0,50,1,0,0, 'say Text',47998),
(@ENTRY,0,8, 'Keep your eyes peeled, They say that freak that was attacking people earlier might still be around.',12,0,50,1,0,0, 'say Text',48003),
(@ENTRY,0,9, 'New recruit? Have you reported to the commander yet?',12,0,50,1,0,0, 'say Text',48000);
-- Twilight Magus SAI
SET @ENTRY := 47585;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79564,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Magus - In Combat - Cast 'Twilight Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,38033,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Magus - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,24000,27000,11,88771,1,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Magus - In Combat - Cast 'Twilight Immolate'"),
(@ENTRY,0,3,0,1,0,30,0,500,1000,600000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Magus - Out of Combat - Say Line 0");
-- NPC talk text insert
SET @ENTRY := 47585;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Hey, you haven\'t seen grom-grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,1, 'Hey, you haven''t seen Grom-Grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,2, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,3, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,4, 'Do i know you? No? Welcome to the Twilight\'s Hammer.',12,0,50,1,0,0, 'say Text',47997),
(@ENTRY,0,5, 'Something big\'s brewing at the Withering to the east.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,6, 'Whatever it is, i hope that it\'ll be over soon and we get restationed somewhere nicer.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,7, 'The end days are nigh!',12,0,50,1,0,0, 'say Text',47998),
(@ENTRY,0,8, 'Keep your eyes peeled, They say that freak that was attacking people earlier might still be around.',12,0,50,1,0,0, 'say Text',48003),
(@ENTRY,0,9, 'New recruit? Have you reported to the commander yet?',12,0,50,1,0,0, 'say Text',48000);
-- Twilight Shaper SAI
SET @ENTRY := 47804;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,30,0,500,1000,600000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shaper - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4200,5000,13500,14600,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Shaper - In Combat - Cast 'Earth Spike'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,17000,25000,11,79886,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Shaper - In Combat - Cast 'Lava Burst'");
-- NPC talk text insert
SET @ENTRY := 47804;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Hey, you haven\'t seen grom-grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,1, 'Hey, you haven''t seen Grom-Grom have you? Orc, about this tall. No?',12,0,50,1,0,0, 'say Text',48001),
(@ENTRY,0,2, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,3, 'Isn\'t it weird that we are keeping Magatha Grimtotem captive here? Good thing all of her totems were destroyed.',12,0,50,1,0,0, 'say Text',48004),
(@ENTRY,0,4, 'Do i know you? No? Welcome to the Twilight\'s Hammer.',12,0,50,1,0,0, 'say Text',47997),
(@ENTRY,0,5, 'Something big\'s brewing at the Withering to the east.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,6, 'Whatever it is, i hope that it\'ll be over soon and we get restationed somewhere nicer.',12,0,50,1,0,0, 'say Text',48002),
(@ENTRY,0,7, 'The end days are nigh!',12,0,50,1,0,0, 'say Text',47998),
(@ENTRY,0,8, 'Keep your eyes peeled, They say that freak that was attacking people earlier might still be around.',12,0,50,1,0,0, 'say Text',48003),
(@ENTRY,0,9, 'New recruit? Have you reported to the commander yet?',12,0,50,1,0,0, 'say Text',48000);
-- Twilight Skymaster Richtofen SAI
SET @ENTRY := 47510;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Skymaster Richtofen - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,17000,25000,11,79721,1,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Skymaster Richtofen - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,80003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Skymaster Richtofen - Between 0-30% Health - Cast 'Black Arrow' (No Repeat)");
-- Twilight Subduer SAI
SET @ENTRY := 47487;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Subduer - In Combat - Cast 'Cleave'");
-- Twilight Trapper SAI
SET @ENTRY := 47479;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Trapper - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,7500,22000,23000,11,80009,1,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Trapper - In Combat - Cast 'Serpent Sting'"),
(@ENTRY,0,2,0,9,0,100,0,0,10,18000,19000,11,78578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Trapper - Within 0-10 Range - Cast 'Immolation Trap'");
-- Venomous Cloud Serpent SAI
SET @ENTRY := 4118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3200,16000,18000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venomous Cloud Serpent - In Combat - Cast 'Deadly Poison'");
-- Vile Sting SAI
SET @ENTRY := 5937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,18000,22000,11,8257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Sting - In Combat - Cast 'Venom Sting'");
