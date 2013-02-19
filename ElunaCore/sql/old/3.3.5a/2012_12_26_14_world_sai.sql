-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-5,-6);
DELETE FROM `creature_text` WHERE `entry` IN (97,98,117,123,124,125,423,424,426,429,430,432,433,434,445,446,452,453,478,500,501,506,568,580,711,1007,1008,1009,1010,1011,1012,1013,1014,1065,1426);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(97,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Runt - Random Say on Aggro'),
(97,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Runt - Random Say on Aggro'),
(98,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Taskmaster - Random Say on Aggro'),
(98,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Taskmaster - Random Say on Aggro'),
(117,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Gnoll - Random Say on Aggro'),
(117,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Gnoll - Random Say on Aggro'),
(123,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Mongrel - Random Say on Aggro'),
(123,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Mongrel - Random Say on Aggro'),
(124,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Brute - Random Say on Aggro'),
(124,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Brute - Random Say on Aggro'),
(125,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Overseer - Random Say on Aggro'),
(125,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Overseer - Random Say on Aggro'),
(423,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Mongrel - Random Say on Aggro'),
(423,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Mongrel - Random Say on Aggro'),
(424,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Poacher - Random Say on Aggro'),
(424,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Poacher - Random Say on Aggro'),
(426,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Brute - Random Say on Aggro'),
(426,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Brute - Random Say on Aggro'),
(429,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Shadowhide Darkweaver - Random Say on Aggro'),
(429,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Shadowhide Darkweaver - Random Say on Aggro'),
(430,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Mystic - Random Say on Aggro'),
(430,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Mystic - Random Say on Aggro'),
(432,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Shadowhide Brute - Random Say on Aggro'),
(432,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Shadowhide Brute - Random Say on Aggro'),
(433,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Shadowhide Gnoll - Random Say on Aggro'),
(433,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Shadowhide Gnoll - Random Say on Aggro'),
(434,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Rabid Shadowhide Gnoll - Random Say on Aggro'),
(434,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Rabid Shadowhide Gnoll - Random Say on Aggro'),
(445,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Alpha - Random Say on Aggro'),
(445,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Alpha - Random Say on Aggro'),
(446,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Basher - Random Say on Aggro'),
(446,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Basher - Random Say on Aggro'),
(452,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Bandit - Random Say on Aggro'),
(452,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Bandit - Random Say on Aggro'),
(453,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Mystic - Random Say on Aggro'),
(453,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Mystic - Random Say on Aggro'),
(478,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Outrunner - Random Say on Aggro'),
(478,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Outrunner - Random Say on Aggro'),
(500,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Scout - Random Say on Aggro'),
(500,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Scout - Random Say on Aggro'),
(501,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Herbalist - Random Say on Aggro'),
(501,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Herbalist - Random Say on Aggro'),
(506,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Sergeant Brashclaw - Random Say on Aggro'),
(506,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Sergeant Brashclaw - Random Say on Aggro'),
(568,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Shadowhide Warrior - Random Say on Aggro'),
(568,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Shadowhide Warrior - Random Say on Aggro'),
(580,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Redridge Drudger - Random Say on Aggro'),
(580,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Redridge Drudger - Random Say on Aggro'),
(711,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Ardo Dirtpaw - Random Say on Aggro'),
(711,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Ardo Dirtpaw - Random Say on Aggro'),
(1007,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Gnoll - Random Say on Aggro'),
(1007,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Gnoll - Random Say on Aggro'),
(1008,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Mongrel - Random Say on Aggro'),
(1008,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Mongrel - Random Say on Aggro'),
(1009,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Mistweaver - Random Say on Aggro'),
(1009,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Mistweaver - Random Say on Aggro'),
(1010,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Fenrunner - Random Say on Aggro'),
(1010,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Fenrunner - Random Say on Aggro'),
(1011,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Trapper - Random Say on Aggro'),
(1011,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Trapper - Random Say on Aggro'),
(1012,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Brute - Random Say on Aggro'),
(1012,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Brute - Random Say on Aggro'),
(1013,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Mystic - Random Say on Aggro'),
(1013,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Mystic - Random Say on Aggro'),
(1014,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Mosshide Alpha - Random Say on Aggro'),
(1014,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Mosshide Alpha - Random Say on Aggro'),
(1065,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Shaman - Random Say on Aggro'),
(1065,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Shaman - Random Say on Aggro'),
(1426,0,0, 'More bones to gnaw on...',12,0,100,0,0,0, 'Riverpaw Miner - Random Say on Aggro'),
(1426,0,1, 'Grrrr... fresh meat!',12,0,100,0,0,0, 'Riverpaw Miner - Random Say on Aggro');

-- SAI for Riverpaw Runt
SET @ENTRY := 97;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Runt - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Runt - HP@15% - Flee');

-- SAI for Riverpaw Taskmaster
SET @ENTRY := 98;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Taskmaster - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,5900,7200,15200,16300,11,3229,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Taskmaster - Combat - Cast Quick Bloodlust'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Taskmaster - HP@15% - Flee');

-- SAI for Riverpaw Gnoll
SET @ENTRY := 117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Gnoll - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Gnoll - HP@15% - Flee');

-- SAI for Riverpaw Mongrel
SET @ENTRY := 123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Mongrel - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,1,2300,35400,0,0,11,8016,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Riverpaw Mongrel - Combat - Cast Spirit Decay'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Mongrel - HP@15% - Flee');

-- SAI for Riverpaw Brute
SET @ENTRY := 124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Brute - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,3800,16800,19800,21500,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Riverpaw Brute - Combat - Cast Demoralizing Shout'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Brute - HP@15% - Flee');

-- SAI for Riverpaw Overseer
SET @ENTRY := 125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Overseer - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Overseer - HP@15% - Flee');

-- SAI for Redridge Mongrel
SET @ENTRY := 423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Mongrel - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Mongrel - HP@15% - Flee');

-- Redridge Poacher SAI
SET @ENTRY := 424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Poacher - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,3400,3700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Poacher - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 15% HP - Increment Phase"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Redridge Poacher - At 15% HP - Flee For Assist"),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - On Evade - Display melee weapon");

-- SAI for Redridge Brute
SET @ENTRY := 426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Brute - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Brute - HP@15% - Flee');

-- Shadowhide Darkweaver SAI
SET @ENTRY := 429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Darkweaver - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,1400,1700,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowhide Darkweaver - At 15% HP - Flee For Assist");

-- Redridge Mystic SAI
SET @ENTRY := 430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Mystic - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,600,1800,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Mystic - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,12,14,0,100,0,0,30,35800,35800,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Redridge Mystic - On Friendly Unit At 0 - 30% Health - Cast Healing Wave"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - On Friendly Unit At 0 - 30% Health - Say Line 1"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Redridge Mystic - At 15% HP - Flee For Assist");

-- SAI for Shadowhide Brute
SET @ENTRY := 432;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Brute - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Brute - HP@30% - Cast Enrage');

-- SAI for Shadowhide Gnoll
SET @ENTRY := 433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Gnoll - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Gnoll - HP@15% - Flee');

-- SAI for Rabid Shadowhide Gnoll
SET @ENTRY := 434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rabid Shadowhide Gnoll - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,5300,12800,7800,22100,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rabid Shadowhide Gnoll - Combat - Cast Poison'),
(@ENTRY,0,2,0,0,0,100,0,8300,9900,8300,9900,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rabid Shadowhide Gnoll - Combat - Cast Rabies'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rabid Shadowhide Gnoll - HP@15% - Flee');

-- SAI for Redridge Alpha
SET @ENTRY := 445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Alpha - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,2100,6100,14100,20100,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Redridge Alpha - Combat - Cast Strike'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Alpha - HP@15% - Flee');

-- SAI for Redridge Basher
SET @ENTRY := 446;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Basher - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1900,10800,17200,17200,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Redridge Basher - Combat - Cast Rend'),
(@ENTRY,0,2,0,0,0,100,0,6600,16000,13600,18700,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Redridge Basher - Combat - Cast Knockdown'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Basher - HP@15% - Flee');

-- SAI for Riverpaw Bandit
SET @ENTRY := 452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Bandit - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1200,3400,2800,13800,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Riverpaw Bandit - Combat - Cast Backstab'),
(@ENTRY,0,2,0,0,0,85,0,2200,9600,16800,39400,11,7357,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Riverpaw Bandit - Combat - Cast Poisonous Stab'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Bandit - HP@15% - Flee');

-- Riverpaw Mystic SAI
SET @ENTRY := 453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Mystic - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Mystic - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Riverpaw Mystic - At 15% HP - Flee For Assist");

-- SAI for Riverpaw Outrunner
SET @ENTRY := 478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Outrunner - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,60,0,2000,2000,16000,18000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Outrunner - Combat - Cast Thrash');

-- Riverpaw Scout SAI
SET @ENTRY := 500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Scout - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2200,4700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Scout - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Riverpaw Scout - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - On Evade - Display melee weapon");

-- SAI for Riverpaw Herbalist
SET @ENTRY := 501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Herbalist - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,500,1200,120000,120000,11,3369,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Herbalist - Combat - Cast Potion Strength II'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Herbalist - HP@15% - Flee');

-- SAI for Sergeant Brashclaw
SET @ENTRY := 506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sergeant Brashclaw - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,90,0,500,1100,30500,38300,11,3136,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sergeant Brashclaw - Combat - Cast Frenxied Command'),
(@ENTRY,0,2,0,0,0,100,0,2000,5600,10800,18600,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Sergeant Brashclaw - Combat - Cast Knockdown'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sergeant Brashclaw - HP@15% - Flee');

-- SAI for Shadowhide Warrior
SET @ENTRY := 568;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Warrior - On Aggro - Say random text'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Warrior - Combat - Cast Defensive Stance'),
(@ENTRY,0,2,0,0,0,100,0,6100,19700,4900,17600,11,7405,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shadowhide Warrior - Combat - Cast Sunder Armor'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowhide Warrior - HP@15% - Flee');

-- SAI for Redridge Drudger
SET @ENTRY := 580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Drudger - On Aggro - Say random text'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Redridge Drudger - HP@15% - Flee');

-- SAI for Ardo Dirtpaw
SET @ENTRY := 711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ardo Dirtpaw - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,6800,10900,245000,255000,11,3256,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ardo Dirtpaw - Combat - Cast Plague Cloud'),
(@ENTRY,0,2,0,0,0,100,0,4900,7900,30000,35000,11,3650,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ardo Dirtpaw - Combat - Cast Sling Mud'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ardo Dirtpaw - HP@15% - Flee');

-- SAI for Mosshide Gnoll
SET @ENTRY := 1007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Gnoll - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,80,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Gnoll - HP@30% - Cast Moss Hide'),
(@ENTRY,0,2,3,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Gnoll - HP@15% - Remove Moss Hide Aura'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Gnoll - HP@15% - Flee');

-- SAI for Mosshide Mongrel
SET @ENTRY := 1008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Mongrel - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,80,0,8700,13800,17700,34500,11,8016,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mosshide Mongrel - Combat - Cast Spirit Decay'),
(@ENTRY,0,2,0,0,0,80,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Mongrel - HP@30% - Cast Moss Hide'),
(@ENTRY,0,3,4,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Mongrel - HP@15% - Remove Moss Hide Aura'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Mongrel - HP@15% - Flee');

-- Mosshide Mistweaver SAI
SET @ENTRY := 1009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12554,32,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Out Of Combat - Cast Summon Treasure Horde"),
(@ENTRY,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mistweaver - On Aggro - Cast Frostbolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,1500,3000,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 30% HP - Cast Moss Hide"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% HP - Remove Aura Moss Hide"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% HP - Set Phase 3"),
(@ENTRY,0,15,16,61,0,100,0,0,15,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% HP - Set Phase 1"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Mistweaver - At 15% HP - Flee For Assist");

-- SAI for Mosshide Fenrunner
SET @ENTRY := 1010;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Fenrunner - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,80,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Fenrunner - HP@30% - Cast Moss Hide'),
(@ENTRY,0,2,3,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Fenrunner - HP@15% - Remove Moss Hide Aura'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Fenrunner - HP@15% - Flee');

-- SAI for Mosshide Trapper
SET @ENTRY := 1011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Trapper - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,5800,10200,17400,28500,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mosshide Trapper - Combat - Cast Net'),
(@ENTRY,0,2,0,0,0,80,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Trapper - HP@30% - Cast Moss Hide'),
(@ENTRY,0,3,4,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Trapper - HP@15% - Remove Moss Hide Aura'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Trapper - HP@15% - Flee');

-- SAI for Mosshide Brute
SET @ENTRY := 1012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Brute - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Brute - HP@15% - Flee');

-- Mosshide Mystic SAI
SET @ENTRY := 1013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mystic - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - On Aggro - Set Phase 6"),
(@ENTRY,0,3,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,4,5,3,0,100,0,0,11,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 11% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 11% Mana - Set Phase 5"),
(@ENTRY,0,6,0,0,0,100,0,0,0,3300,5100,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mystic - In Combat - Cast Lightning Bolt"),
(@ENTRY,0,7,0,9,0,100,0,0,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 0 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,3,0,100,0,20,100,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 100% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 100% Mana - Set Phase 6"),
(@ENTRY,0,10,0,9,0,100,0,40,60,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 40 - 60 Range - Set Phase 1"),
(@ENTRY,0,11,0,9,0,100,0,0,5,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 0 - 5 Range - Set Phase 1"),
(@ENTRY,0,12,0,0,0,30,1,14400,14400,0,0,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mystic - In Combat - Cast Slow"),
(@ENTRY,0,13,0,14,0,80,1,0,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Mosshide Mystic - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,14,0,2,0,30,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 30% HP - Cast Moss Hide"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 15% HP - Set Phase 1"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Mystic - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,61,0,100,0,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - At 15% HP - Remove Aura Moss Hide");

-- SAI for Mosshide Alpha
SET @ENTRY := 1014;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Alpha - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1900,6500,13400,21200,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Alpha - Combat - Cast Battle Shout'),
(@ENTRY,0,2,0,0,0,50,1,0,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Alpha - HP@30% - Cast Moss Hide'),
(@ENTRY,0,3,4,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Alpha - HP@15% - Remove Moss Hide Aura'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mosshide Alpha - HP@15% - Flee');

-- Riverpaw Shaman SAI
SET @ENTRY := 1065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3500,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,1,0,40,0,0,11,913,1,0,0,0,0,7,0,0,0,0,0,0,0,"Riverpaw Shaman - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Riverpaw Shaman - At 15% HP - Flee For Assist");

-- SAI for Riverpaw Miner
SET @ENTRY := 1426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Miner - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1200,6000,7800,12400,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mosshide Miner - Combat - Cast Sunder Armor'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Riverpaw Miner - HP@15% - Flee');
