-- Kolkar Pack Runner SAI
SET @ENTRY := 3274;
SET @SPELL := 9128;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_summons` WHERE `id`=8;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-769);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL,32,0,0,0,0,1,0,0,0,0,0,0,0, 'Kolkar Pack Runner - On Aggro - Cast Battle Shout'),
(@ENTRY,0,1,2,6,0,3,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kolkar Pack Runner - On Death 3% - Say 0'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,12,3395,4,60000,0,0,0,8,0,0,0,-1209.65,-2738.38,102.646,4.99352, 'Kolkar Pack Runner - On Death 3% - Summon Verog the Dervish');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I am slain! Summon Verog!',14,0,100,0,0,0, 'Kolkar Pack Runner');

-- Kolkar Marauder SAI
SET @ENTRY := 3275;
SET @SPELL := 11976;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,12000,12000,7000,7000,11,@SPELL,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Kolkar Marauder - Combat - Cast Strike'),
(@ENTRY,0,1,2,6,0,3,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kolkar Marauder - On Death 3% - Say 0'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,12,3395,4,60000,0,0,0,8,0,0,0,-1209.65,-2738.38,102.646,4.99352, 'Kolkar Marauder - On Death 3% - Summon Verog the Dervish');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I am slain! Summon Verog!',14,0,100,0,0,0, 'Kolkar Marauder');

-- Kolkar Bloodcharger SAI
SET @ENTRY := 3397;
SET @SPELL1 := 6742;
SET @SPELL2 := 172;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,35000,35000,10000,10000,11,@SPELL1,32,0,0,0,0,1,0,0,0,0,0,0,0, 'Kolkar Bloodcharger - Combat - Cast Bollodlust'),
(@ENTRY,0,1,0,0,0,100,0,20000,20000,5000,5000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Kolkar Bloodcharger - Combat - Cast Corruption'),
(@ENTRY,0,2,3,6,0,3,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kolkar Bloodcharger - On Death 3% - Say 0'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,3395,4,60000,0,0,0,8,0,0,0,-1209.65,-2738.38,102.646,4.99352, 'Kolkar Bloodcharger - On Death 3% - Summon Verog the Dervish');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I am slain! Summon Verog!',14,0,100,0,0,0, 'Kolkar Bloodcharger');

-- Clara Charles SAI
SET @ENTRY := 5917;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_summons` WHERE `id` BETWEEN 7 AND 19;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,1,1,15,0,0,12,583,4,60000,0,0,0,8,0,0,0,-9232.11,342.473,74.4399,4.31658, 'Clara Charles - On LOS - Summon Defias Ambusher');

-- Defias Dockmaster SAI
SET @ENTRY := 6846;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-232);
DELETE FROM `creature_ai_summons` WHERE `id` IN (4,5,6);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Dockmaster - On Aggro - Say 0'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,6866,4,60000,0,0,0,8,0,0,0,-9967.55,-135.956,24.5909,0.170326, 'Defias Dockmaster - On Aggro - Summon Defias Bodyguard'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,12,6866,4,60000,0,0,0,8,0,0,0,-9958.49,-140.526,24.2409,4.0015, 'Defias Dockmaster - On Aggro - Summon Defias Bodyguard'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,6866,4,60000,0,0,0,8,0,0,0,-9964.59,-140.567,24.5105,0.741307, 'Defias Dockmaster - On Aggro - Summon Defias Bodyguard');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The Brotherhood will not be hampered by insects.',12,0,100,0,0,0, 'Defias Dockmaster');

-- Mekgineer Thermaplugg SAI
SET @ENTRY := 7800;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-188,-189,-190,-191);
DELETE FROM `creature_ai_summons` WHERE `id` IN (2,3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - On Aggro - Say 0'),
(@ENTRY,0,1,0,5,0,100,2,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - On Kill - Say 3'),
(@ENTRY,0,2,0,0,0,100,2,40000,40000,40000,60000,11,11130,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - Combat - Cast Knock Away'),
(@ENTRY,0,3,0,0,0,100,2,15000,15000,15000,35000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - Combat - Cast Knock Away'),
(@ENTRY,0,4,5,0,0,100,2,30000,30000,30000,30000,12,7915,4,60000,0,0,0,8,0,0,0,-521.934,693.13,-327.005,2.95, 'Mekgineer Thermaplugg - Combat - Summon Walking Bomb'),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,12,7915,4,60000,0,0,0,8,0,0,0,-535.318,649.987,-326.494,2.72, 'Mekgineer Thermaplugg - Combat - Summon Walking Bomb'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - Combat - Say 2'),
(@ENTRY,0,7,0,0,0,100,2,20000,20000,40000,65000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mekgineer Thermaplugg - Combat - Say 1');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'USURPERS!!! GNOMEREGAN IS MINE!!!',14,0,100,0,0,5807, 'Mekgineer Thermaplugg'),
(@ENTRY,1,0, 'My machines are the future! They''ll destroy you all!',14,0,100,0,0,5808, 'Mekgineer Thermaplugg'),
(@ENTRY,2,0, 'Explosions! MORE explosions! I''ve got to have more explosions!',14,0,100,0,0,5809, 'Mekgineer Thermaplugg'),
(@ENTRY,3,0, '...and stay dead! He got served!',14,0,100,0,0,5810, 'Mekgineer Thermaplugg');

-- Shy-Rotam SAI
SET @ENTRY := 10737;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_summons` WHERE `id` IN (1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,5000,10000,11,14100,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shy-Rotam - Combat - Cast Terrifying Roar'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,22000,27000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shy-Rotam - Combat - Cast Rend'),
(@ENTRY,0,2,0,0,0,100,0,2000,3000,15000,20000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shy-Rotam - Combat - Cast Tendon Rip'),
(@ENTRY,0,3,0,0,0,100,1,0,50,0,0,12,10741,1,180000,0,0,0,8,0,0,0,8074.84,-3840,690.061,4.6, 'Shy-Rotam - @50%HP - Summon Sian-Rotam');

-- Jammal'an the Prophet SAI
SET @ENTRY := 5710;
SET @QUEST_SOULGRINDER := 11000;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-821,-822,-823,-824);
DELETE FROM `creature_ai_summons` WHERE `id` IN (20,21);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,10,0,100,0,0,85,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - On OOC Los - Say Line 0 (P0)"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - On OOC Los - Set Phase 1"),
(@ENTRY,0,2,0,0,1,100,0,0,0,31400,76200,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jammal'an the Prophet - In Combat - Say Line 2"),
(@ENTRY,0,3,0,0,1,100,0,8100,35600,20100,52900,11,12468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jammal'an the Prophet - In Combat - Cast Flamestrike"),
(@ENTRY,0,4,0,0,1,100,0,6200,16500,26100,36600,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - In Combat - Cast Earthgrab Totem"),
(@ENTRY,0,5,6,1,1,100,0,16300,19900,31400,53500,11,12479,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jammal'an the Prophet - In Combat - Cast Hex of Jammal'an"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jammal'an the Prophet - On Hex of Jammal'an Cast - Say Line 1"),
(@ENTRY,0,7,8,2,1,100,1,0,30,0,0,11,12492,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - At 30% HP - Cast Healing Wave"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - At 30% HP - Say Line 3"),
(@ENTRY,0,9,0,5,1,100,0,0,0,0,0,4,5863,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jammal'an the Prophet - Killed Unit - Play Sound 5863"),
(@ENTRY,0,10,11,6,1,100,0,0,0,0,0,12,5721,1,300000,0,0,0,8,0,0,0,-472.02,105.823,-94.6299,0.0301925,"Jammal'an the Prophet - On Death - Summon Dreamscyte"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,12,5720,1,300000,0,0,0,8,0,0,0,-467.099,85.2944,-94.7318,3.95326,"Jammal'an the Prophet - On Death - Summon Weaver");
-- Jammal'an the Prophet text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The shield be down! Rise up Atal'ai! Rise up!",14,0,100,0,0,0,"Jammal'an the Prophet"), -- 821
(@ENTRY,1,0,"Join us!",14,0,100,0,0,0,"Jammal'an the Prophet"), -- 823
(@ENTRY,2,0,"The Soulflayer comes!",14,0,100,0,0,0,"Jammal'an the Prophet"), -- 822
(@ENTRY,3,0,"Hakkar shall live again!",14,0,100,0,0,0,"Jammal'an the Prophet"); -- 824
