-- Plagueborn Horror SAI
SET @ENTRY := 36879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,69581,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Pustulant Flesh' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,10000,10000,11,70273,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Pustulant Flesh' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,8000,8000,8000,8000,11,70274,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Toxic Waste' (Dungeon)"),
(@ENTRY,0,3,0,2,0,100,6,15,15,0,0,11,69582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - Between 15-15% Health - Cast 'Blight Bomb' (Dungeon)"),
(@ENTRY,0,4,5,1,0,100,0,0,0,120000,120000,11,58051,2,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - Out of Combat - Cast 'Summon Scourge Package'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,120000,120000,11,69702,2,0,0,0,0,9,30887,0,4,0,0,0,0,"Plagueborn Horror - Out of Combat - Cast 'Rope'"),
(@ENTRY,0,6,0,4,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,30887,0,10,0,0,0,0,"Plagueborn Horror - On Aggro - Set Data 1 1"),
(@ENTRY,0,7,8,25,0,100,0,0,0,0,0,11,58051,2,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - On Reset - Cast 'Summon Scourge Package'"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,63413,2,0,0,0,0,9,30887,0,5,0,0,0,0,"Plagueborn Horror - On Reset - Cast 'Rope Beam'");

UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid` IN (201981,  201833, 202236, 201903);

-- Scourge Package SAI
SET @ENTRY := 30887;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,29,3,40,0,0,0,0,7,0,0,0,0,0,0,0,"Scourge Package - On Just Summoned - Start Follow Invoker"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Just Summoned - Run Random Script"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Data Set 1 1 - Despawn In 1000 ms");

-- Actionlist SAI
SET @ENTRY := 3088700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58016,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58022,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58020,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088703;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58023,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");
