-- [Q] [A/H] Cleansing of the Orb of Orahil
-- [Q] [A/H] Mana Surges
-- Tabetha SAI
SET @ENTRY := 6546;
SET @QUEST_CLEANSING := 4961;
SET @QUEST_MANA_SURGE := 1957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `entry` IN (@QUEST_CLEANSING,@QUEST_MANA_SURGE);
DELETE FROM `quest_start_scripts` WHERE `id` IN (@QUEST_CLEANSING,@QUEST_MANA_SURGE);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST_CLEANSING,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,11,9097,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Cast Summon Demon of the Orb"),

(@ENTRY,0,1,0,20,0,100,0,@QUEST_MANA_SURGE,0,0,0,9,0,0,0,0,0,0,14,28294,103680,0,0,0,0,0,"Tabetha - On Quest Complete - Deactivate Mana Rift (GO)"), -- Make it stop being visual
(@ENTRY,0,2,3,19,0,100,0,@QUEST_MANA_SURGE,0,0,0,9,0,0,0,0,0,0,14,28294,103680,0,0,0,0,0,"Tabetha - On Quest Accept - Activate Mana Rift (GO)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,87,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest Accept - Run Random Script"),
(@ENTRY,0,4,0,38,0,100,0,1,1,0,0,87,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Data Set - Run Random Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4019.22,-3383.91,38.2265,2.7963,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4019.22,-3383.91,38.2265,2.7963,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4019.22,-3383.91,38.2265,2.7963,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4019.99,-3394.54,38.5507,1.8342,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4019.99,-3394.54,38.5507,1.8342,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4013.29,-3385.14,38.4656,2.3801,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4013.29,-3385.14,38.4656,2.3801,"Tabetha - On Random Script - Summon Mana Surge"),
(@ENTRY*100+3,9,2,0,0,0,100,0,0,0,0,0,12,6550,1,600000,0,0,0,8,0,0,0,-4013.29,-3385.14,38.4656,2.3801,"Tabetha - On Random Script - Summon Mana Surge");
-- Text
DELETE FROM `db_script_string` WHERE `entry`=2000000032;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Grid yourself, $N. The demon in this orb is a fel beast.",12,0,100,0,0,0,"Tabetha");
-- Mana Surge SAI
SET @ENTRY := 6550;
SET @SPELL_SHOCK := 11824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Surge - On Just Summoned - Set Random Movement"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,6546,0,0,0,0,0,0,"Mana Surge - On Death - Set Data Tabetha"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,8000,8000,11,@SPELL_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mana Surge - In Combat - Cast Shock');
