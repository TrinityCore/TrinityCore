/*
-- Quarry Slave
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8917;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8917 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8917,0,0,0,4,0,100,0,0,0,0,0,0,39,20,1,0,0,0,0,1,0,0,0,0,0,0,0,"Quarry Slave - On Aggro - Call For Help"),
(8917,0,1,0,0,0,100,0,5000,8000,5000,8000,0,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quarry Slave - In Combat - Cast 'Strike'"),
(8917,0,2,0,0,0,100,0,7000,9000,13000,16000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quarry Slave - In Combat - Cast 'Hamstring'"),
(8917,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Quarry Slave - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `creature_addon` SET `emote`=173 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=8917); -- Add some missing emotes

-- Anvilrage Overseer
DELETE FROM `smart_scripts` WHERE `entryorguid`=8889 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8889,0,1,0,25,0,100,0,0,0,0,0,0,11,13589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Overseer - On Reset - Cast 'Haste Aura'");

-- Anvilrage Warden
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8890;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8890 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8890,0,0,0,9,0,100,0,0,30,12000,18000,0,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Warden - Within 0-30 Range - Cast 'Hooked Net'"),
(8890,0,1,0,0,0,100,0,9000,11000,12000,16000,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Warden - In Combat - Cast 'Shield Bash'");

-- Bloodhound
DELETE FROM `smart_scripts` WHERE `entryorguid`=8921 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8921,0,2,0,25,0,100,0,0,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodhound - On Reset - Cast 'Stealth Detection'");

-- Anvilrage Guardsman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8891;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8891 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8891,0,0,0,0,0,100,0,3000,6000,13000,16000,0,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Shield Block'"),
(8891,0,1,0,0,0,100,0,7000,9000,12000,14000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Disarm'"),
(8891,0,2,0,0,0,100,0,5000,7000,15000,17000,0,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Sunder Armor'");

-- Twilight's Hammer Torturer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8912;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8912 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8912,0,0,0,25,0,100,0,0,0,0,0,0,11,13616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight's Hammer Torturer - On Reset - Cast 'Wracking Pains Proc'"),
(8912,0,1,0,0,0,100,0,3000,6000,14000,17000,0,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Torturer - In Combat - Cast 'Shadow Word: Pain'");

-- Anvilrage Footman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8892;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8892 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8892,0,0,0,0,0,100,0,5000,8000,7000,10000,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Footman - In Combat - Cast 'Strike'"),
(8892,0,1,0,13,0,100,0,13000,15000,0,0,0,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Footman - Target Casting - Cast 'Kick'");

-- Fireguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8909;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8909 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8909,0,0,0,0,0,100,0,0,0,3000,5000,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fireguard - In Combat - Cast 'Fireball'");

-- Lord Roccor
DELETE FROM `smart_scripts` WHERE `entryorguid`=9025 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9025,0,2,0,0,0,100,0,10000,13000,11000,14000,0,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Roccor - In Combat - Cast 'Ground Tremor'");

-- Houndmaster Grebmar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9319;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9319 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9319,0,0,0,0,0,100,0,7000,9000,22000,24000,0,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Houndmaster Grebmar - In Combat - Cast 'Demoralizing Shout'"),
(9319,0,1,0,0,0,100,0,5000,7000,12000,14000,0,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Houndmaster Grebmar - In Combat - Cast 'Pummel'"),
(9319,0,2,0,2,0,100,1,0,30,0,0,0,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Houndmaster Grebmar - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Arena Spectator
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8916;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8916 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8916,0,0,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Arena Spectator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Anvilrage Soldier
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8893;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8893 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8893,0,0,0,0,0,100,0,5000,7000,11000,15000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Soldier - In Combat - Cast 'Cleave'"),
(8893,0,1,0,0,0,100,0,7000,9000,13000,15000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Soldier - In Combat - Cast 'Hamstring'"),
(8893,0,2,0,2,0,100,0,0,30,16000,18000,0,11,13847,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Soldier - Between 0-30% Health - Cast 'Recklessness'");

-- Anvilrage Medic
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8894;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8894 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8894,0,0,0,16,0,100,0,13864,1,1000,2000,0,11,13864,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anvilrage Medic - On Friendly Unit Missing Buff 'Power Word: Fortitude' - Cast 'Power Word: Fortitude'"),
(8894,0,1,0,0,0,100,0,0,0,3000,5000,0,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Medic - In Combat - Cast 'Mind Blast'"),
(8894,0,2,0,0,0,100,0,12000,15000,28000,32000,0,11,15585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Medic - In Combat - Cast 'Prayer of Healing'"),
(8894,0,3,0,14,0,100,0,2500,40,18000,21000,0,11,15586,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anvilrage Medic - Friendly At 2500 Health - Cast 'Heal'");

-- Shadowforge Citizen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8902 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8902,0,0,0,4,0,100,0,0,0,0,0,0,31,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Citizen - On Aggro - Set Phase Random Between 1-5"),
(8902,0,1,0,0,1,100,0,7000,9000,8000,12000,0,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Cleave' (Phase 1)"),
(8902,0,2,0,0,1,100,0,5000,7000,7000,10000,0,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Strike' (Phase 1)"),
(8902,0,3,0,0,2,100,0,6000,8000,15000,18000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Frost Nova' (Phase 2)"),
(8902,0,4,0,0,4,100,0,0,0,3000,4000,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Shadow Bolt' (Phase 3)"),
(8902,0,5,0,0,8,100,0,3000,6000,6000,12000,0,11,13339,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Fire Blast' (Phase 4)"),
(8902,0,6,0,14,16,100,0,1200,40,18000,21000,0,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowforge Citizen - Friendly At 1200 Health - Cast 'Heal' (Phase 5)"),
(8902,0,7,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Citizen - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Shadowforge Peasant
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8896;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8896 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8896,0,0,0,4,0,100,0,0,0,0,0,0,31,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Peasant - On Aggro - Set Phase Random Between 1-5"),
(8896,0,1,0,0,1,100,0,7000,9000,12000,17000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Peasant - In Combat - Cast 'Disarm' (Phase 1)"),
(8896,0,2,0,0,1,100,0,5000,7000,7000,10000,0,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Peasant - In Combat - Cast 'Strike' (Phase 1)"),
(8896,0,3,0,0,2,100,0,0,0,2000,4000,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Peasant - In Combat - Cast 'Shoot' (Phase 2)"),
(8896,0,4,0,9,2,100,0,0,5,18000,21000,0,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Peasant - Within 0-5 Range - Cast 'Tendon Rip' (Phase 2)"),
(8896,0,5,0,0,4,100,0,0,0,2000,4000,0,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Peasant - In Combat - Cast 'Throw Dynamite' (Phase 3)"),
(8896,0,6,0,14,8,100,0,1200,40,18000,21000,0,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowforge Peasant - Friendly At 1200 Health - Cast 'Heal' (Phase 4)"),
(8896,0,7,0,0,16,100,0,0,0,3000,5000,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Citizen - In Combat - Cast 'Fireball' (Phase 5)"),
(8896,0,8,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Peasant - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Anvilrage Officer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8895;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8895 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8895,0,0,0,4,0,100,0,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Officer - On Aggro - Cast 'Battle Shout'"),
(8895,0,1,0,0,0,100,0,5000,7000,9000,13000,0,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Officer - In Combat - Cast 'Backhand'"),
(8895,0,2,0,14,0,100,0,3000,40,12000,16000,0,11,13952,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anvilrage Officer - Friendly At 3000 Health - Cast 'Holy Light'"),
(8895,0,3,0,2,0,100,0,0,20,21000,28000,0,11,13874,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Officer - Between 0-15% Health - Cast 'Divine Shield'");

-- Shadowforge Senator
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8904;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8904 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8904,0,0,0,4,0,100,0,0,0,0,0,0,31,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Senator - On Aggro - Set Phase Random Between 1-5"),
(8904,0,1,0,0,1,100,0,0,0,3000,5000,0,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Fireball' (Phase 1)"),
(8904,0,2,0,16,1,100,0,2601,1,15000,19000,0,11,2601,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowforge Senator - On Friendly Unit Missing Buff 'Fire Shield III' - Cast 'Fire Shield III' (Phase 1)"),
(8904,0,3,0,0,2,100,0,0,0,3000,5000,0,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Shadow Bolt' (Phase 2)"),
(8904,0,4,0,0,2,100,0,3000,6000,13000,19000,0,11,14868,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Curse of Agony' (Phase 2)"),
(8904,0,5,0,0,4,100,0,6000,8000,15000,18000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Frost Nova' (Phase 3)"),
(8904,0,6,0,0,8,100,0,3000,8000,14000,25000,0,11,11436,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Slow' (Phase 4)"),
(8904,0,7,0,0,16,100,0,1000,2000,3000,5000,0,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Senator - In Combat - Cast 'Holy Smite' (Phase 5)"),
(8904,0,8,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Senator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Twilight Emissary
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8913;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8913 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8913,0,0,0,4,0,100,0,0,0,0,0,0,31,1,3,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Emissary - On Aggro - Set Phase Random Between 1-3"),
(8913,0,1,0,16,1,100,0,15288,1,8000,11000,0,11,15288,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Emissary - On Friendly Unit Missing Buff 'Fury of Ragnaros' - Cast 'Fury of Ragnaros' (Phase 1)"),
(8913,0,2,0,0,1,100,0,0,0,3000,5000,0,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Emissary - In Combat - Cast 'Fireball' (Phase 1)"),
(8913,0,3,0,0,2,100,0,0,0,3000,5000,0,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Emissary - In Combat - Cast 'Frostbolt' (Phase 2)"),
(8913,0,4,0,0,2,100,0,15000,25000,20000,25000,0,11,8364,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Emissary - In Combat - Cast 'Blizzard' (Phase 2)"),
(8913,0,5,0,9,2,100,0,0,8,20000,22000,0,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Emissary - Within 0-8 Range - Cast 'Frost Nova' (Phase 2)"),
(8913,0,6,0,16,2,100,0,12544,1,1000,1000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Emissary - On Friendly Unit Missing Buff 'Frost Armor' - Cast 'Frost Armor' (Phase 2)"),
(8913,0,7,0,0,4,100,0,0,0,2000,4000,0,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Emissary - In Combat - Cast 'Arcane Bolt' (Phase 3)"),
(8913,0,8,0,9,5,100,0,0,8,16000,20000,0,11,13745,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Emissary - Within 0-8 Range - Cast 'Arcane Explosion' (Phase 3)");

-- Twilight Bodyguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8914;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8914 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8914,0,0,0,13,0,100,0,15000,17000,0,0,0,11,13902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Bodyguard - Target Casting - Cast 'Pummel'"),
(8914,0,1,0,0,0,100,0,13000,15000,13000,15000,0,11,13902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Bodyguard - In Combat - Cast 'Fist of Ragnaros'"),
(8914,0,2,0,14,0,100,0,3000,40,31000,33000,0,11,13903,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Bodyguard - Friendly At 3000 Health - Cast 'Seal of Sacrifice'");

-- Pyromancer Loregrain
DELETE FROM `smart_scripts` WHERE `entryorguid`=9024 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9024,0,3,0,0,0,100,0,2000,7000,30000,45000,0,11,15041,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyromancer Loregrain - In Combat - Cast 'Fire Ward'");

-- Doomforge Craftsman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8897;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8897 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8897,0,0,0,4,0,100,0,0,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Doomforge Craftsman - On Aggro - Set Phase Random Between 1-2"),
(8897,0,1,0,0,1,100,0,0,0,2000,3000,0,11,15619,64,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Craftsman - In Combat - Cast 'Throw Wrench' (Phase 1)"),
(8897,0,2,0,0,2,100,0,0,0,2000,3000,0,11,9143,64,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Craftsman - In Combat - Cast 'Bomb' (Phase 2)"),
(8897,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Doomforge Craftsman - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `creature_addon` SET `emote`=173 WHERE `guid` IN (47722,47723,47724,47731,47732,47709,47710,47711,47706,47707,47726,47715,47727,47728,47713,47714,47718,47719,47720); -- Add some missing emotes

-- Bloodhound Mastiff
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8922;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8922 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8922,0,0,0,0,0,100,0,5000,7000,11000,13000,0,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodhound Mastiff - In Combat - Cast 'Expose Weakness'"),
(8922,0,1,0,0,0,100,0,9000,11000,20000,22000,0,11,15608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodhound Mastiff - In Combat - Cast 'Ravenous Claw'"),
(8922,0,2,0,25,0,100,0,0,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodhound Mastiff - On Reset - Cast 'Stealth Detection'");

-- Fireguard Destroyer
DELETE FROM `smart_scripts` WHERE `entryorguid`=8911 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8911,0,1,0,25,0,100,0,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fireguard Destroyer - On Reset - Cast 'Thrash'");

-- Blazing Fireguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8910;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8910 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8910,0,0,0,0,0,100,0,3000,5000,6000,12000,0,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazing Fireguard - In Combat - Cast 'Fire Blast'"),
(8910,0,1,0,0,0,100,0,9000,11000,11000,18000,0,11,20787,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blazing Fireguard - In Combat - Cast 'Immolate'"),
(8910,0,2,0,0,0,100,0,5000,7000,3000,6000,0,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazing Fireguard - In Combat - Cast 'Scorch'");

-- Verek
DELETE FROM `smart_scripts` WHERE `entryorguid`=9042 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9042,0,0,0,0,0,100,0,3000,5000,30000,45000,0,11,15042,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verek - In Combat - Cast 'Curse of Blood'");

-- Dark Keeper Bethek
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=9438 AND `source_type`=0 AND `id`=1;

-- Warbringer Construct
DELETE FROM `smart_scripts` WHERE `entryorguid`=8905 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8905,0,6,0,4,0,30,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warbringer Construct - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=8905;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8905,0,0,"Intruders!!",12,0,100,0,0,0,4961,0,"Warbringer Construct");

-- Fineous Darkvire
UPDATE `smart_scripts` SET `target_type`=2 WHERE `entryorguid`=9056 AND `source_type`=0 AND `id`=3;

-- Lord Incendius
DELETE FROM `smart_scripts` WHERE `entryorguid`=9017 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9017,0,4,0,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Incendius - On Just Died - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9017;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9017,0,0,"I cannot be destroyed! By the will of Ragnaros, I shall be reborn!",12,0,100,0,0,0,5061,0,"Lord Incendius");

-- Doomforge Dragoon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8899;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8899 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8899,0,0,0,0,0,100,0,0,0,2000,4000,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Dragoon - In Combat - Cast 'Shoot'"),
(8899,0,1,0,0,0,100,0,4000,6000,8000,12000,0,11,15495,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Dragoon - In Combat - Cast 'Explosive Shot'"),
(8899,0,2,0,0,0,100,0,5000,7000,8000,12000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Dragoon - In Combat - Cast 'Cleave'");

-- Anvilrage Marshal
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8898;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8898 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8898,0,0,0,4,0,100,0,0,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Marshal - On Aggro - Cast 'Pummel'"),
(8898,0,1,0,0,0,100,0,5000,7000,7000,9000,0,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Marshal - In Combat - Cast 'Holy Strike'"),
(8898,0,2,0,14,0,100,0,3000,40,12000,16000,0,11,13952,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anvilrage Marshal - Friendly At 3000 Health - Cast 'Holy Light'");

-- Weapon Technician
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8920;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8920 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8920,0,0,0,4,0,100,0,0,0,0,0,0,31,1,3,0,0,0,0,1,0,0,0,0,0,0,0,"Weapon Technician - On Aggro - Set Phase Random Between 1-3"),
(8920,0,1,0,0,0,100,0,0,0,2000,4000,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Weapon Technician - In Combat - Cast 'Shoot'"),
(8920,0,2,0,0,1,100,0,3000,6000,10000,13000,0,11,7896,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weapon Technician - In Combat - Cast 'Exploding Shot' (Phase 1)"),
(8920,0,3,0,0,2,100,0,3000,6000,10000,13000,0,11,12551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weapon Technician - In Combat - Cast 'Frost Shot' (Phase 2)"),
(8920,0,4,0,0,4,100,0,5000,7000,13000,15000,0,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weapon Technician - In Combat - Cast 'Multi-Shot' (Phase 3)"),
(8920,0,5,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Weapon Technician - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Doomforge Arcanasmith
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8900 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8900,0,0,0,0,0,100,0,0,0,2000,4000,0,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,"Doomforge Arcanasmith - In Combat - Cast 'Arcane Bolt'"),
(8900,0,1,0,9,0,100,0,0,8,8000,12000,0,11,13745,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doomforge Arcanasmith - Within 0-8 Range - Cast 'Arcane Explosion'"),
(8900,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Doomforge Arcanasmith - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ragereaver Golem
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8906;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8906 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8906,0,0,0,25,0,100,0,0,0,0,0,0,11,15088,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragereaver Golem - On Reset - Cast 'Flurry'"),
(8906,0,1,0,2,0,100,1,0,30,0,0,0,11,12795,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragereaver Golem - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(8906,0,2,0,2,0,100,1,0,30,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragereaver Golem - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=8906;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8906,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Ragereaver Golem");

-- Mistress Nagmara
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=950000 AND `source_type`=9 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=9500 AND `GroupID`=0 AND `ID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9500,0,3,"Yes $gsir:madam;.",12,0,100,0,0,0,4983,0,"Mistress Nagmara");

-- Molten War Golem
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8908;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8908 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8908,0,0,0,25,0,100,0,0,0,0,0,0,11,15506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molten War Golem - On Reset - Cast 'Immolate'");

-- Shadowforge Flame Keeper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9956;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9956 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9956,0,0,0,4,0,100,0,0,0,0,0,0,11,9128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Flame Keeper - On Aggro - Cast 'Battle Shout'"),
(9956,0,1,0,0,0,100,0,0,0,2200,3800,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Flame Keeper - In Combat - Cast 'Shoot'"),
(9956,0,2,0,0,0,100,0,4000,6000,12000,15000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Flame Keeper - In Combat - Cast 'Hamstring'"),
(9956,0,3,0,0,0,100,0,8000,11000,6000,9000,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Flame Keeper - In Combat - Cast 'Strike'");

-- Twilight's Hammer Ambassador
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8915;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8915 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8915,0,0,0,4,0,100,0,0,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - On Aggro - Set Phase Random Between 1-4"),
(8915,0,1,0,0,1,100,0,6000,10000,7000,14000,0,11,12248,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - In Combat - Cast 'Amplify Damage' (Phase 1)"),
(8915,0,2,0,0,1,100,0,2000,4000,12000,16000,0,11,11980,32,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - In Combat - Cast 'Curse of Weakness' (Phase 1)"),
(8915,0,3,0,0,2,100,0,3000,5000,7000,9000,0,11,15499,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - In Combat - Cast 'Frost Shock' (Phase 2)"),
(8915,0,4,0,0,4,100,0,3000,5000,7000,9000,0,11,15096,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - In Combat - Cast 'Flame Shock' (Phase 3)"),
(8915,0,5,0,14,8,100,0,1300,40,10000,18000,0,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - Friendly At 1300 Health - Cast 'Bloodlust' (Phase 4)"),
(8915,0,6,0,0,8,100,0,3000,5000,7000,9000,0,11,15500,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight's Hammer Ambassador - In Combat - Cast 'Shock' (Phase 4)");

-- Lava Surger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12101 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(12101,0,0,0,0,0,100,0,1000,1000,12000,15000,0,11,19196,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lava Surger - In Combat - Cast 'Surge'");

-- Fix spawn position for some creatures
UPDATE `creature` SET `position_x`=724.198, `position_y`=-131.585, `position_z`=-71.9149, `orientation`=3.86779 WHERE `guid`=45859;
UPDATE `creature` SET `position_x`=723.114, `position_y`=-134.579, `position_z`=-71.9354, `orientation`=1.92786, `spawndist`=0, `MovementType`=0 WHERE `guid`=45857;

-- Fix gossip text for Anger'rel
UPDATE `npc_text` SET `text0_0`="I am one of the Seven, and it is our doom to stand sentry.  Forever.", `BroadcastTextID0`=4874 WHERE `ID`=2596;

-- Fix Typo
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `event_chance`=0;
*/
