UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=3430;
-- DELETE FROM `creature_ai_texts` WHERE `entry`=-47;

-- Hardened Steel Skycaller SAI
SET @ENTRY := 28580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - On Aggro - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,3,4,9,0,100,2,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-30 Range - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,5,6,0,0,100,2,9000,12000,15000,20000,11,52754,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Cast 52754 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,7,8,0,0,100,2,7000,12000,12000,18000,11,52755,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Cast 52755 (Normal Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,9,0,4,0,100,5,0,0,0,0,11,61515,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - On Aggro - Cast 61515 (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,4,5,30,2300,5000,11,61515,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-30 Range - Cast 61515 (Heroic Dungeon)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,12,13,0,0,100,4,9000,12000,15000,20000,11,59148,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Cast 59148 (Heroic Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,14,15,0,0,100,4,7000,12000,12000,18000,11,59147,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Cast 59147 (Heroic Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - In Combat - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,16,0,9,0,100,6,0,5,6000,9000,11,61507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 0-5 Range - Cast 61507 (Dungeon Only)"),
(@ENTRY,0,17,18,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,19,20,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,22,23,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,24,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - On Evade - Set Sheath Melee (Dungeon Only)");

-- Cabal Ritualist SAI
SET @ENTRY := 18794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,30,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Out Of Combat - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,2,5,4,1,100,3,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Cast 15497 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-40 Range - Cast 15497 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,1,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Cast 12675 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-40 Range - Cast 12675 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,0,1,100,2,7000,7000,7000,12000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 15532 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,0,0,1,100,4,7000,7000,7000,12000,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 15063 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,0,2,100,6,4000,4000,6000,8000,11,12540,0,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 12540 (Dungeon Only) (Phase 2)"),
(@ENTRY,0,15,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,16,19,4,4,100,3,0,0,0,0,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Cast 33833 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,2,0,30,2400,3800,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-30 Range - Cast 33833 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,18,19,4,4,100,3,0,0,0,0,11,38264,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Cast 38264 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,19,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,20,0,9,4,100,4,0,30,2400,3800,11,38264,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-30 Range - Cast 38264 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,21,22,3,4,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,22,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 3)"),
(@ENTRY,0,23,0,9,4,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,24,0,9,4,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,25,0,9,4,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,26,0,0,4,100,6,9000,12000,12000,16000,11,33487,1,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 33487 (Dungeon Only) (Phase 3)"),
(@ENTRY,0,27,0,0,8,100,6,4000,4000,6000,8000,11,12540,0,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 12540 (Dungeon Only) (Phase 4)"),
(@ENTRY,0,28,0,3,8,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,29,0,4,0,100,7,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,30,0,0,0,100,2,6000,10000,4000,6000,11,20795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 20795 (Normal Dungeon)"),
(@ENTRY,0,31,0,0,0,100,4,6000,10000,4000,6000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 14145 (Heroic Dungeon)"),
(@ENTRY,0,32,0,0,0,100,6,2000,2000,10000,12000,11,9574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 9574 (Dungeon Only)"),
(@ENTRY,0,33,0,0,0,100,6,4000,4000,6000,8000,11,12540,0,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 12540 (Dungeon Only)");

-- Ring-Lord Sorceress SAI
SET @ENTRY := 27639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,50715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Cast 50715 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,15000,19000,11,50715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-40 Range - Cast 50715 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,59278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Cast 59278 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,5,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,15000,19000,11,59278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-40 Range - Cast 59278 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,14,0,0,0,100,2,9000,12000,15000,18000,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 16102 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,4,9000,12000,15000,18000,11,61402,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 61402 (Heroic Dungeon)");

-- Murkblood Oracle SAI
SET @ENTRY := 17771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,900000,900000,11,34880,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Out Of Combat - Cast 34880 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,7,0,0,0,0,30,1,3,5,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,3,6,4,1,100,3,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 15497 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3200,4800,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 15497 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,1,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 12675 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,3200,4800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 12675 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,0,1,100,2,8700,8700,19000,19000,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 32192 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,0,1,100,4,8700,8700,19000,19000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 15531 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,15,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,16,19,4,4,100,3,0,0,0,0,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 14034 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,2,0,40,2400,3800,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 14034 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,18,19,4,4,100,3,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 15228 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,19,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,20,0,9,4,100,4,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 15228 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,21,22,3,4,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,22,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 3)"),
(@ENTRY,0,23,0,9,4,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,24,0,9,4,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,25,0,9,4,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,26,0,0,4,100,2,3600,3600,12000,15000,11,15241,1,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 15241 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,27,0,0,4,100,4,3600,3600,9000,12000,11,36807,1,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 36807 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,28,0,3,8,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,29,32,4,16,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 12471 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,30,0,9,16,100,2,0,40,3100,4700,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,31,32,4,16,100,3,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Cast 15232 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,32,0,61,16,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,33,0,9,16,100,4,0,40,3100,4700,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-40 Range - Cast 15232 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,34,35,3,16,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,35,0,61,16,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 5)"),
(@ENTRY,0,36,0,9,16,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,37,0,9,16,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,38,0,9,16,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,39,0,0,16,100,2,7600,7600,3600,10100,11,31405,32,0,0,0,0,5,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 31405 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,40,0,0,16,100,4,7600,7600,6700,6700,11,37113,32,0,0,0,0,5,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 37113 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,41,0,3,32,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 6)"),
(@ENTRY,0,42,0,0,0,100,6,3000,9000,15000,250000,11,34880,33,0,0,0,0,5,0,0,0,0,0,0,0,"Murkblood Oracle - In Combat - Cast 34880 (Dungeon Only)"),
(@ENTRY,0,43,44,2,0,100,7,0,15,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Health - Set Event Phase 0 (Dungeon Only)"),
(@ENTRY,0,44,45,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,45,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkblood Oracle - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Coilfang Leper SAI
SET @ENTRY := 21338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,7,0,0,0,0,30,1,3,5,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,2,5,4,1,100,3,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - On Aggro - Cast 9613 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-40 Range - Cast 9613 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,1,100,3,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - On Aggro - Cast 12739 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-40 Range - Cast 12739 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,0,1,85,2,9000,12000,9000,12000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 11831 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,0,0,1,100,4,9000,12000,9000,12000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 15063 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,15,16,9,4,100,2,5,30,2300,3800,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-30 Range - Cast 15547 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,16,0,61,4,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,17,18,9,4,100,4,5,30,2300,3800,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-30 Range - Cast 16100 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,18,0,61,4,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,19,20,9,4,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,20,0,61,4,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 3)"),
(@ENTRY,0,21,22,9,4,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,22,23,61,4,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 3)"),
(@ENTRY,0,23,0,61,4,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 3)"),
(@ENTRY,0,24,25,9,4,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,25,0,61,4,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 3)"),
(@ENTRY,0,26,0,2,4,100,2,0,40,10000,14000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-40% Health - Cast 11642 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,27,0,2,4,100,4,0,40,10000,11000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-40% Health - Cast 15586 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,28,0,0,8,100,1,1000,1000,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Allow Combat Movement (Phase 4)"),
(@ENTRY,0,29,0,0,16,100,2,5000,7000,7000,9000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 13339 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,30,0,0,16,100,4,5000,7000,7000,8000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 14145 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,31,0,0,16,100,6,8000,12000,8000,14000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 13444 (Dungeon Only) (Phase 5)"),
(@ENTRY,0,32,0,0,16,100,6,6000,8000,9000,12000,11,13446,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Leper - In Combat - Cast 13446 (Dungeon Only) (Phase 5)"),
(@ENTRY,0,33,34,2,0,100,7,0,15,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-15% Health - Set Event Phase 6 (Dungeon Only)"),
(@ENTRY,0,34,35,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,35,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Coilfang Leper - Between 0-15% Health - Flee For Assist (Dungeon Only)"),
(@ENTRY,0,36,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Leper - On Evade - Set Sheath Melee (Dungeon Only)");

-- Mage Hunter Ascendant SAI
SET @ENTRY := 26727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,7,0,0,0,0,30,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,2,5,4,1,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,1,100,3,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Cast 17290 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-40 Range - Cast 17290 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,0,1,100,6,4000,6000,12000,18000,11,47784,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 47784 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,0,1,100,2,7000,9000,15000,28000,11,36808,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 36808 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,0,1,100,4,7000,9000,15000,28000,11,39376,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 39376 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,15,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,16,19,4,4,100,3,0,0,0,0,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Cast 12737 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,2,0,30,2400,3800,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-30 Range - Cast 12737 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,18,19,4,4,100,3,0,0,0,0,11,56837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Cast 56837 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,19,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,20,0,9,4,100,4,0,30,2400,3800,11,56837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-30 Range - Cast 56837 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,21,22,3,4,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,22,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 3)"),
(@ENTRY,0,23,0,9,4,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,24,0,9,4,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,25,0,9,4,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,26,0,0,0,100,6,7000,9000,11000,18000,11,55040,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 55040 (Dungeon Only)"),
(@ENTRY,0,27,0,0,0,100,2,10000,12000,11000,15000,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 15244 (Normal Dungeon)"),
(@ENTRY,0,28,0,0,0,100,4,10000,12000,11000,15000,11,38384,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 38384 (Heroic Dungeon)"),
(@ENTRY,0,29,0,3,8,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,30,0,1,16,100,6,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - Out Of Combat - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,31,0,0,1,100,2,4000,6000,8000,11000,11,34933,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 34933 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,32,0,0,1,100,4,4000,6000,8000,11000,11,56825,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 56825 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,33,0,0,1,100,6,8000,9000,9000,15000,11,47789,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 47789 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,34,0,0,1,100,2,1000,1200,60000,60000,11,50182,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 50182 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,35,0,0,1,100,4,1000,1200,60000,60000,11,56827,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 56827 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,36,0,0,0,100,6,9000,14000,19000,22000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 13323 (Dungeon Only)");

-- Veteran Mage Hunter SAI
SET @ENTRY := 30665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Out Of Combat - Cast 58040 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,7,0,0,0,0,30,1,3,5,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - In Combat - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,3,6,4,1,100,3,0,0,0,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 15043 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 15043 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,1,100,3,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 20822 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,2400,3800,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 20822 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,6,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,14,17,4,4,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 12466 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,15,0,9,4,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,16,17,4,4,100,3,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 20823 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,17,0,61,4,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,18,0,9,4,100,4,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 20823 (Heroic Dungeon) (Phase 3)"),
(@ENTRY,0,19,20,3,4,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,20,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 3)"),
(@ENTRY,0,21,0,9,4,100,6,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,22,0,9,4,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,23,0,9,4,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 3)"),
(@ENTRY,0,24,0,3,8,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,25,28,4,16,100,3,0,0,0,0,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 13748 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,26,0,9,16,100,2,0,40,2400,3800,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 13748 (Normal Dungeon) (Phase 5)"),
(@ENTRY,0,27,28,4,16,100,3,0,0,0,0,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Cast 20829 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,28,0,61,16,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,29,0,9,16,100,4,0,40,2400,3800,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-40 Range - Cast 20829 (Heroic Dungeon) (Phase 5)"),
(@ENTRY,0,30,31,3,16,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,31,0,61,16,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 5)"),
(@ENTRY,0,32,0,9,16,100,6,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,33,0,9,16,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,34,0,9,16,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 5)"),
(@ENTRY,0,35,0,3,32,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 6)"),
(@ENTRY,0,36,37,2,0,100,7,0,15,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Health - Set Event Phase 0 (Dungeon Only)"),
(@ENTRY,0,37,38,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,38,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Health - Flee For Assist (Dungeon Only)");
