-- Windyreed Quest Credit (Hut 01) SAI
SET @ENTRY := 18142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `gameobject` WHERE `id`=182146; -- Remove already spawned hut fires
SET @SPELL_LIVING_FIRE := 31927; -- Living Fire
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_LIVING_FIRE,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windyreed Quest Credit - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1850.186401,6378.753906,49.132702,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1843.883911,6373.384277,46.005417,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1845.056030,6383.819336,56.662624,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1845.103638,6391.827148,53.700901,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1831.184937,6391.026855,45.671902,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,60165,17139,0,0,0,0,0,"Windyreed Quest Credit - Script - Kill Creature Inside Burning Hut");

-- Windyreed Quest Credit (Hut 02) SAI
SET @ENTRY := 18143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
SET @SPELL_LIVING_FIRE := 31927; -- Living Fire
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_LIVING_FIRE,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windyreed Quest Credit - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1915.344116,6350.488770,52.229897,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1907.135986,6353.901367,48.899532,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1911.698730,6354.161133,58.254566,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1926.308350,6360.901855,57.298611,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1921.458862,6367.373047,59.892593,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,60159,17139,0,0,0,0,0,"Windyreed Quest Credit - Script - Kill Creature Inside Burning Hut");

-- Windyreed Quest Credit (Hut 03) SAI
SET @ENTRY := 18144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
SET @SPELL_LIVING_FIRE := 31927; -- Living Fire
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_LIVING_FIRE,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windyreed Quest Credit - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1969.078369,6278.307129,56.866646,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1977.147461,6277.312988,59.912029,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1974.763306,6269.175781,51.401920,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1970.424805,6273.501953,61.741539,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,60157,17139,0,0,0,0,0,"Windyreed Quest Credit - Script - Kill Creature Inside Burning Hut");

-- Windyreed Quest Credit (Big Hut) SAI
SET @ENTRY := 18110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
SET @SPELL_LIVING_FIRE := 31927; -- Living Fire
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_LIVING_FIRE,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windyreed Quest Credit - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1816.939941,6283.669922,61.357101,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1816.94,6283.67,61.3571,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1819.71,6305.89,63.4012,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1819.55,6298.08,73.4331,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1801.45,6308.03,59.2728,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1808.88,6307.05,72.4877,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,50,182146,20000,0,0,0,0,8,0,0,0,-1794.54,6300.6,71.2263,0,"Windyreed Quest Credit - Script - Summon Hut Fire (Large)"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,60166,17139,0,0,0,0,0,"Windyreed Quest Credit - Script - Kill Creatures Inside Burning Hut"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,60167,17139,0,0,0,0,0,"Windyreed Quest Credit - Script - Kill Creatures Inside Burning Hut");
