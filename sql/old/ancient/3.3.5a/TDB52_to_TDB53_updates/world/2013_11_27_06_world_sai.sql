-- Burning Blade Augur SAI
SET @ENTRY := 4663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Augur - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Augur - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,3000,6000,25000,25000,11,6909,32,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Augur - In Combat - Cast 'Curse of Thorns'"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Adept SAI
SET @ENTRY := 4665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Adept - On Aggro - Cast 'Fireball'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Adept - Within 0-40 Range - Cast 'Fireball' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,2,0,100,1,0,20,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-20% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Shadowmage SAI
SET @ENTRY := 4667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Shadowmage - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,5000,12000,18000,26000,11,9657,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - In Combat - Cast 'Shadow Shell'"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Summoner SAI
SET @ENTRY := 4668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,61,1,0,100,0,1000,1000,0,0,11,688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Out of Combat - Cast 'Summon Imp'"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Summoner - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Summoner - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Fallenroot Hellcaller SAI
SET @ENTRY := 4799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Out of Combat - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallenroot Hellcaller - On Aggro - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,12000,15000,30000,45000,11,8129,1,0,0,0,0,5,0,0,0,0,0,0,0,"Fallenroot Hellcaller - In Combat - Cast 'Mana Burn' (Normal Dungeon)");

-- Blackfathom Tide Priestess SAI
SET @ENTRY := 4802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - On Reset - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - On Aggro - Cast 'Frostbolt'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Within 0-40 Range - Cast 'Frostbolt' (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,0,0,7,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-7% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,7,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-7% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 15-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,0,0,30,25000,35000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-30% Health - Cast 'Heal'"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,13,14,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,14,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Twilight Aquamancer SAI
SET @ENTRY := 4811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,0,0,11,8372,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Out of Combat - Cast 'Summon Aqua Guardian' (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Aquamancer - On Aggro - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Aquamancer - Within 0-40 Range - Cast 'Frostbolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,6,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Twilight Shadowmage SAI

SET @ENTRY := 4813;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,2,0,0,0,0,11,12746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - On Reset - Cast 'Summon Voidwalker' (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Shadowmage - On Aggro - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Shadowmage - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,6,3,1,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,1,100,2,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,18000,26000,24000,30000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Twilight Shadowmage - In Combat - Cast 'Dominate Mind' (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Blindlight Oracle SAI
SET @ENTRY := 4820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blindlight Oracle - On Aggro - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blindlight Oracle - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,10,0,14,0,100,2,1000,40,30000,40000,11,6063,1,0,0,0,0,7,0,0,0,0,0,0,0,"Blindlight Oracle - Friendly At 1000 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,11,0,2,0,100,3,0,50,0,0,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-50% Health - Cast 'Renew' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,8,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Earthcaller Halmgar SAI
SET @ENTRY := 4842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,2,1000,1000,0,0,11,8270,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Out of Combat - Cast 'Summon Earth Rumbler' (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthcaller Halmgar - On Aggro - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthcaller Halmgar - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,0,2000,50000,60000,11,2484,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - In Combat - Cast 'Earthbind Totem' (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Shadowforge Darkcaster SAI
SET @ENTRY := 4848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Darkcaster - On Aggro - Cast 'Shadow Bolt Volley' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,30,2400,3800,11,9081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Within 0-30 Range - Cast 'Shadow Bolt Volley' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,25,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Within 25-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,9000,13000,11000,15000,11,15800,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Darkcaster - In Combat - Cast 'Mana Burn' (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Stonevault Geomancer SAI
SET @ENTRY := 4853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Geomancer - On Aggro - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Geomancer - Within 0-40 Range - Cast 'Fireball' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,1,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 30-100% Mana - Decrement Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,4000,8000,30000,38000,11,10452,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Geomancer - In Combat - Cast 'Flame Buffet' (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Gordunni Ogre Mage SAI
SET @ENTRY := 5237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Aggro - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-15% Mana - Increment Phase (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 30-100% Mana - Decrement Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Gordunni Mage-Lord SAI
SET @ENTRY := 5239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - On Aggro - Cast 'Fireball'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Within 0-40 Range - Cast 'Fireball' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,5000,9000,20000,26000,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Woodpaw Mystic SAI

SET @ENTRY := 5254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Mystic - On Aggro - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Mystic - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,14,0,100,0,800,30,45000,45000,11,8005,1,0,0,0,0,7,0,0,0,0,0,0,0,"Woodpaw Mystic - Friendly At 800 Health - Cast 'Healing Wave'"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Atal'ai Witch Doctor SAI
SET @ENTRY := 5259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Aggro - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,2,100,2,0,40,3500,5200,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,2,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Mana - Enable Combat Movement (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,2,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Mana - Increment Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,2,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 35-80 Range - Enable Combat Movement (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,2,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 5-15 Range - Disable Combat Movement (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,2,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 0-5 Range - Enable Combat Movement (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 30-100% Mana - Decrement Phase (Phase 4) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,4900,13100,13100,18400,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,10900,26100,17100,35100,11,11641,1,0,0,0,0,5,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Hex' (Normal Dungeon)"),
(@ENTRY,0,12,0,14,0,100,2,1800,40,12700,23100,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Friendly At 1800 Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Atal'ai Priest SAI
SET @ENTRY := 5269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Out of Combat - Cast 'Shadow Shield' (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,6,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 30-100% Mana - Decrement Phase (Phase 4) (Normal Dungeon)"),
(@ENTRY,0,11,0,14,0,100,2,1000,30,11000,15000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Priest - Friendly At 1000 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,8,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Atal'ai High Priest SAI
SET @ENTRY := 5273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Out of Combat - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai High Priest - On Aggro - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3600,3600,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai High Priest - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,40,2,10000,20000,75000,75000,11,12151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - In Combat - Cast 'Summon Atal'ai Skeleton' (Normal Dungeon)"),
(@ENTRY,0,11,0,14,0,100,2,2500,40,20000,30000,11,12039,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai High Priest - Friendly At 2500 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,3,0,30,0,0,11,12040,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai High Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Dunemaul Ogre Mage SAI
SET @ENTRY := 5473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - On Aggro - Cast 'Fireball'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Within 0-40 Range - Cast 'Fireball' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 0-15% Mana - Increment Phase (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Within 0-5 Range - Enable Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 30-100% Mana - Decrement Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,9000,18000,26000,11,11436,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - In Combat - Cast 'Slow'"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Dunemaul Warlock SAI
SET @ENTRY := 5475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dunemaul Warlock - Between 30-100% Mana - Decrement Phase (Phase 2)"),
(@ENTRY,0,10,0,0,1,100,0,7000,11000,21000,26000,11,2941,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Immolate' (Phase 1)"),
(@ENTRY,0,11,0,0,1,100,0,3000,5000,180000,188000,11,6909,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dunemaul Warlock - In Combat - Cast 'Curse of Thorns' (Phase 1)");

-- Captain Elleane Wavecrest SAI
SET @ENTRY := 35102;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,1,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,15,0,9,0,100,0,0,5,4000,7000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Between 0-5 Range - Cast 29426"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - On Evade - Set Sheath Melee");

-- Wavecrest Mariner SAI
SET @ENTRY := 35098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wavecrest Mariner - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,0,1,100,0,8000,10000,7000,9000,11,17174,1,0,0,0,0,5,0,0,0,0,0,0,0,"Wavecrest Mariner - In Combat - Cast 17174 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - In Combat - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavecrest Mariner - On Evade - Set Sheath Melee");

-- Firehawk Mariner SAI
SET @ENTRY := 35070;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firehawk Mariner - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,0,1,100,0,8000,10000,7000,9000,11,17174,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firehawk Mariner - In Combat - Cast 17174 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - In Combat - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firehawk Mariner - On Evade - Set Sheath Melee");

-- Captain Aerthas Firehawk SAI
SET @ENTRY := 35090;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,1,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,15,0,9,0,100,0,0,5,4000,7000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Between 0-5 Range - Cast 29426"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - On Evade - Set Sheath Melee");

-- Mistcaller Yngvar SAI
SET @ENTRY := 34965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,45658,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Out Of Combat - Cast 45658"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistcaller Yngvar - On Aggro - Cast 9532"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,5,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,6000,9000,12000,17000,11,49816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mistcaller Yngvar - In Combat - Cast 49816"),
(@ENTRY,0,12,0,2,0,100,0,0,30,120000,120000,11,49871,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Between 0-30% Health - Cast 49871");

-- Copperpot Goon SAI
SET @ENTRY := 34505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,39,50,0,0,0,0,0,1,0,0,0,0,0,0,0,"Copperpot Goon - On Aggro - Call for help"),
(@ENTRY,0,1,0,9,0,100,1,0,20,12000,15000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Copperpot Goon - Between 0-20 Range - Cast 12024");

-- Kvaldir Harpooner SAI
SET @ENTRY := 34907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,66489,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Harpooner - On Aggro - Cast 66489"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,10,30,2300,3900,11,66489,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 10-30 Range - Cast 66489"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 10-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Harpooner - On Evade - Set Sheath Melee");

-- Unbound Seer SAI
SET @ENTRY := 33422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Seer - On Aggro - Cast 38204"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Seer - Between 0-40 Range - Cast 38204 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Seer - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,12000,15000,11,58667,33,0,0,0,0,5,0,0,0,0,0,0,0,"Unbound Seer - In Combat - Cast 58667");
