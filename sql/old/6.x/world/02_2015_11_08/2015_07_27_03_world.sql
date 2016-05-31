-- 
-- DB/SAI: Update The Hinterlands
-- Anchorite Traska SAI
SET @ENTRY := 46475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anchorite Traska - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,1800000,1800000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Traska - Out of Combat - Cast 'Power Word: Fortitude'");
-- Crown Agent SAI
SET @ENTRY := 38016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,15500,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Agent - In Combat - Cast 'Kick'");
-- Deathstalker Bodychopper SAI
SET @ENTRY := 43016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,14000,15000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstalker Bodychopper - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,18000,20000,11,79852,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstalker Bodychopper - In Combat - Cast 'Eviscerate'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,33000,35000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstalker Bodychopper - In Combat - Cast 'Expose Armor'"),
(@ENTRY,0,3,0,9,0,100,0,0,8,22000,24000,11,79851,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathstalker Bodychopper - Within 0-8 Range - Cast 'Fan of Knives'");
-- Deathstalker Invader SAI
SET @ENTRY := 43541;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstalker Invader - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,16000,19000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstalker Invader - In Combat - Cast 'Deadly Poison'");
-- Fraggar Thundermantle SAI
SET @ENTRY := 43156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,79914,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fraggar Thundermantle - On Aggro - Cast 'Feral Spirit' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,11000,12000,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fraggar Thundermantle - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fraggar Thundermantle - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,19514,1,15000,30000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fraggar Thundermantle - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,0,0,100,0,8000,8000,24000,25000,11,78770,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fraggar Thundermantle - In Combat - Cast 'Magma Totem'");
-- Gammerita SAI
SET @ENTRY := 7977;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,14500,16500,11,80604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gammerita - In Combat - Cast 'Crushing Bite'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,18000,21000,11,83488,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gammerita - Between 0-40% Health - Cast 'Shell Shield'");
-- Gan'dranda SAI
SET @ENTRY := 42609;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,25000,28000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'dranda - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,14000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'dranda - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,12000,8000,19000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'dranda - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,7000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'dranda - Within 0-5 Range - Cast 'Hamstring'"),
(@ENTRY,0,4,0,2,0,100,1,0,25,0,0,11,79871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'dranda - Between 0-25% Health - Cast 'Recklessness' (No Repeat)");
-- Green Sludge SAI
SET @ENTRY := 2655;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,16000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Sludge - In Combat - Cast 'Corrosive Ooze'");
-- Grimungous SAI
SET @ENTRY := 8215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,22000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimungous - In Combat - Cast 'Trample'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,14000,15000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimungous - Within 0-5 Range - Cast 'War Stomp'");
-- Highvale Sentry SAI
SET @ENTRY := 46478;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Sentry - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Sentry - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,19000,20000,11,83014,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Sentry - In Combat - Cast 'Rapid Shot'");
-- Highvale Swiftblade SAI
SET @ENTRY := 43539;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,18000,20000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Swiftblade - In Combat - Cast 'Expose Armor'");
-- Highvale Vindicator SAI
SET @ENTRY := 43540;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,10000,10500,11,14517,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Vindicator - In Combat - Cast 'Crusader Strike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,18000,11,31803,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Vindicator - In Combat - Cast 'Censure'");
-- Hiri'watha Deathguard SAI
SET @ENTRY := 43715;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hiri'watha Deathguard - In Combat - Cast 'Shoot'");
-- Hiri'watha Deathguard SAI
SET @ENTRY := 51824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hiri'watha Deathguard - In Combat - Cast 'Shoot'");
-- Ironback SAI
SET @ENTRY := 8213;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9500,15000,17000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironback - In Combat - Cast 'Harden'");
-- Jade Ooze SAI
SET @ENTRY := 2656;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,16000,18000,11,6907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jade Ooze - In Combat - Cast 'Diseased Slime'");
-- Jalinde Summerdrake SAI
SET @ENTRY := 8214;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jalinde Summerdrake - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,20000,11,15495,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jalinde Summerdrake - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,60000,65000,11,8806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jalinde Summerdrake - In Combat - Cast 'Poisoned Shot'");
-- Mangy Silvermane SAI
SET @ENTRY := 2923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,22000,25000,11,8139,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mangy Silvermane - In Combat - Cast 'Fevered Fatigue'");
-- Marauding Owlbeast SAI
SET @ENTRY := 7808;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marauding Owlbeast - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marauding Owlbeast - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7808;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Mith'rethis the Enchanter SAI
SET @ENTRY := 8217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,74919,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - Out of Combat - Cast 'Shadow Channeling' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,17000,20000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,15000,16000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - In Combat - Cast 'Slow'"),
(@ENTRY,0,3,0,2,0,100,1,0,35,0,0,11,3443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - Between 0-35% Health - Cast 'Enchanted Quickness' (No Repeat)");
-- Morta'gya the Keeper SAI
SET @ENTRY := 42877;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morta'gya the Keeper - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,18000,19000,11,18266,1,0,0,0,0,2,0,0,0,0,0,0,0,"Morta'gya the Keeper - In Combat - Cast 'Curse of Agony'");
-- Old Cliff Jumper SAI
SET @ENTRY := 8211;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Cliff Jumper - In Combat - Cast 'Carnivorous Bite'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,19000,22000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Cliff Jumper - In Combat - Cast 'Blood Howl'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,16000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Cliff Jumper - Within 0-5 Range - Cast 'Tendon Rip'");
-- Primitive Owlbeast SAI
SET @ENTRY := 2928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,17000,17500,11,3252,0,0,0,0,0,2,0,0,0,0,0,0,0,"Primitive Owlbeast - In Combat - Cast 'Shred'");
-- Qiaga the Keeper SAI
SET @ENTRY := 42919;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Qiaga the Keeper - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,17000,20000,11,32063,1,0,0,0,0,2,0,0,0,0,0,0,0,"Qiaga the Keeper - In Combat - Cast 'Corruption'"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,1000,1000,11,74919,2,0,0,0,0,1,0,0,0,0,0,0,0,"Qiaga the Keeper - Out of Combat - Cast 'Shadow Channeling' (No Repeat)");
-- Razorbeak Skylord SAI
SET @ENTRY := 2659;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorbeak Skylord - In Combat - Cast 'Rend Flesh'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,22000,11,11019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorbeak Skylord - In Combat - Cast 'Wing Flap'");
-- Razortalon SAI
SET @ENTRY := 8210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - In Combat - Cast 'Moonfire'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,22000,25000,11,79823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - In Combat - Cast 'Starfall'");
-- Retherokk the Berserker SAI
SET @ENTRY := 8216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Retherokk the Berserker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Retherokk the Berserker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,3000,8000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Retherokk the Berserker - In Combat - Cast 'Thrash'");
-- NPC talk text insert
SET @ENTRY := 8216;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Revantusk Hexxer SAI
SET @ENTRY := 42555;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Hexxer - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revantusk Hexxer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,8000,30000,33000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Hexxer - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,3,0,0,0,100,0,11000,12000,18000,20000,11,16568,1,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Hexxer - In Combat - Cast 'Mind Flay'");
-- Revantusk Stalker SAI
SET @ENTRY := 42536;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revantusk Stalker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revantusk Stalker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,16000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Stalker - In Combat - Cast 'Uppercut'");
-- NPC talk text insert
SET @ENTRY := 42536;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Revantusk Watcher SAI
SET @ENTRY := 51901;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Watcher - In Combat - Cast 'Shoot'");
-- Revantusk Watcher SAI
SET @ENTRY := 14730;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Revantusk Watcher - In Combat - Cast 'Shoot'");
-- Saltwater Snapjaw SAI
SET @ENTRY := 2505;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,14500,16500,11,80604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltwater Snapjaw - In Combat - Cast 'Crushing Bite'");
-- Savage Owlbeast SAI
SET @ENTRY := 2929;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,14000,16000,11,85257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Owlbeast - In Combat - Cast 'Heave'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,18000,21000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Owlbeast - Between 0-40% Health - Cast 'Fatal Bite'");
-- Shadra SAI
SET @ENTRY := 43007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,20000,11,13298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadra - In Combat - Cast 'Poison'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,22000,26000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadra - In Combat - Cast 'Slowing Poison'"),
(@ENTRY,0,2,0,9,0,100,0,0,10,9000,10000,11,28991,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadra - Within 0-10 Range - Cast 'Web'");
-- Shadraspawn Venomspitter SAI
SET @ENTRY := 42913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,6917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadraspawn Venomspitter - In Combat - Cast 'Venom Spit'");
-- Silvermane Howler SAI
SET @ENTRY := 2925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Howler - In Combat - Cast 'Snarl'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Howler - In Combat - Cast 'Furious Howl'");
-- Silvermane Stalker SAI
SET @ENTRY := 2926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,19000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Stalker - In Combat - Cast 'Infected Bite'");
-- Silvermane Wolf SAI
SET @ENTRY := 2924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Wolf - In Combat - Cast 'Snarl'");
-- Spawn of Shadra SAI
SET @ENTRY := 42879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,15000,17000,11,85278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spawn of Shadra - In Combat - Cast 'Shadra's Venom'");
-- The Reak SAI
SET @ENTRY := 8212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,18000,24000,11,7279,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Reak - In Combat - Cast 'Black Sludge'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,28000,32000,11,21062,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Reak - In Combat - Cast 'Putrid Breath'");
-- Thornar Thunderclash SAI
SET @ENTRY := 42610;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornar Thunderclash - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,79878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornar Thunderclash - In Combat - Cast 'Bloodthirst'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,15500,11,81140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thornar Thunderclash - Within 0-8 Range - Cast 'Thunderclap'");
-- Tracker Yoro SAI
SET @ENTRY := 46476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tracker Yoro - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tracker Yoro - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,19000,20000,11,83014,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tracker Yoro - In Combat - Cast 'Rapid Shot'");
-- Trained Razorbeak SAI
SET @ENTRY := 2657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,14000,15000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Trained Razorbeak - In Combat - Cast 'Rend Flesh'");
-- Umboda Three-Heads SAI
SET @ENTRY := 42724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,15000,20000,11,85279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umboda Three-Heads - In Combat - Cast 'Two-Fisted Skull Bash'");
-- NPC talk text insert
SET @ENTRY := 42724;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Vicious Owlbeast SAI
SET @ENTRY := 2927;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,14000,16000,11,85257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicious Owlbeast - In Combat - Cast 'Heave'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,18000,21000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicious Owlbeast - Between 0-40% Health - Cast 'Fatal Bite'");
-- Vilebranch Aman'zasi Guard SAI
SET @ENTRY := 2648;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,13000,17000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Aman'zasi Guard - In Combat - Cast 'Shield Slam'");
-- Vilebranch Axe Thrower SAI
SET @ENTRY := 2639;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Vilebranch Berserker SAI
SET @ENTRY := 2643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Berserker - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Berserker - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 2643;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Vilebranch Blood Drinker SAI
SET @ENTRY := 2646;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,18000,22000,11,11015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Blood Drinker - In Combat - Cast 'Blood Leech'");
-- Vilebranch Broodguard SAI
SET @ENTRY := 42901;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Broodguard - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,120000,125000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Broodguard - In Combat - Cast 'Battle Shout'");
-- Vilebranch Headhunter SAI
SET @ENTRY := 2641;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Headhunter - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,13000,14500,11,7357,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Headhunter - Within 0-5 Range - Cast 'Poisonous Stab'");
-- Vilebranch Hideskinner SAI
SET @ENTRY := 2644;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,9000,12000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Hideskinner - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,18000,19000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Hideskinner - In Combat - Cast 'Poison'");
-- Vilebranch Raiding Wolf SAI
SET @ENTRY := 2681;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,8000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Raiding Wolf - In Combat - Cast 'Thrash'");
-- Vilebranch Scalper SAI
SET @ENTRY := 4466;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,14000,11,58461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Scalper - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,19000,21000,11,81705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Scalper - In Combat - Cast 'Scalp Slash'");
-- Vilebranch Shadow Hunter SAI
SET @ENTRY := 2645;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,8500,16500,18200,11,75439,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - In Combat - Cast 'Black Shot'");
-- Vilebranch Shadowcaster SAI
SET @ENTRY := 2642;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,7000,9500,25000,26000,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat - Cast 'Shrink'");
-- Vilebranch Soothsayer SAI
SET @ENTRY := 4467;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Soothsayer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Soothsayer - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Vilebranch Soul Eater SAI
SET @ENTRY := 2647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15500,17500,11,11016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Soul Eater - In Combat - Cast 'Soul Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,7154,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Soul Eater - Between 0-30% Health - Cast 'Dark Offering' (No Repeat)"),
(@ENTRY,0,2,0,14,0,100,0,400,10,15000,16000,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vilebranch Soul Eater - Friendly At 400 Health - Cast 'Dark Offering'");
-- Vilebranch Warrior SAI
SET @ENTRY := 4465;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13000,14500,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Warrior - Within 0-5 Range - Cast 'Strike'");
-- Vilebranch Witch Doctor SAI
SET @ENTRY := 2640;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,17000,22000,11,18503,1,0,0,0,0,5,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - In Combat - Cast 'Hex'");
-- Vilebranch Zealot SAI
SET @ENTRY := 43891;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,84534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Zealot - In Combat - Cast 'Zeal'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,19000,23000,11,84535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Zealot - In Combat - Cast 'Zealotry'");
-- Wildhammer Sentry SAI
SET @ENTRY := 7865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,18000,22000,11,8078,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-8 Range - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,9000,12000,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-5 Range - Cast 'Sunder Armor'");
-- Wildhammer Sentry SAI
SET @ENTRY := 51923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,18000,22000,11,8078,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-8 Range - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,9000,12000,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-5 Range - Cast 'Sunder Armor'");
-- Wildhammer Sentry SAI
SET @ENTRY := 52084;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,18000,22000,11,8078,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-8 Range - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,9000,12000,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Sentry - Within 0-5 Range - Cast 'Sunder Armor'");
-- Wildhammer Shaman SAI
SET @ENTRY := 42554;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Shaman - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,49309,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Shaman - Between 0-30% Health - Cast 'Lesser Healing Wave' (No Repeat)");
-- Wildhammer Spirithunter SAI
SET @ENTRY := 43213;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,12500,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Spirithunter - In Combat - Cast 'Rend'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,120000,125000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Spirithunter - In Combat - Cast 'Battle Shout'");
-- Wildhammer Warrior SAI
SET @ENTRY := 42518;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,11000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Warrior - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,120000,125000,11,38232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildhammer Warrior - In Combat - Cast 'Battle Shout'");
-- Zul'arek Hatefowler SAI
SET @ENTRY := 8219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5800,11000,16000,11,17228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'arek Hatefowler - In Combat - Cast 'Shadow Bolt Volley'");
