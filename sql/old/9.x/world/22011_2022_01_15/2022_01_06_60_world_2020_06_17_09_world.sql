-- Sethekk Ravenguard
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (83296,83298,83294);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(83296,83296,0,0,3),
(83296,83299,0,0,3),
(83298,83298,0,0,3),
(83298,83280,0,0,3),
(83294,83294,0,0,3),
(83294,83259,0,0,3);

-- This guy shouldn't path
DELETE FROM `creature_addon` WHERE `guid` = 83283;
DELETE FROM `waypoint_data` WHERE `id` = 832830;

-- Sethekk Spirit, took from CMaNGOS
UPDATE `creature_template` SET `unit_flags` = 33587264, `speed_walk` = 1.111112, `speed_run` = 0.285714 WHERE `entry` IN (18703,20700);

-- Sniffed
DELETE FROM `creature_template_addon` WHERE `entry` IN (18319,20697,18320,20698,18327,20691);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(18319,"37509"), -- Ghostly Facade -- Time-Lost Scryer
(20697,"37509"), -- Ghostly Facade -- Time-Lost Scryer
(18320,"37509"), -- Ghostly Facade -- Time-Lost Shadowmage
(20698,"37509"), -- Ghostly Facade -- Time-Lost Shadowmage
(18327,"37509"), -- Ghostly Facade -- Time-Lost Controller
(20691,"37509"); -- Ghostly Facade -- Time-Lost Controller

-- + Sethekk Initiate SAI (Source: ACID 4.3.4 OD - N/H)
-- Original script was without initial timers for the 'Sunder Armor'
SET @ID := 18318;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Initiate - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,5300,7100,10800,18100,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Initiate - In Combat - Cast 'Sunder Armor'"),
(@ID,0,2,0,0,0,100,0,7400,15700,27300,47100,11,33961,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Initiate - In Combat - Cast 'Spell Reflection'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Initiate"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Initiate"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Initiate"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Initiate"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Initiate");

-- + Time-Lost Scryer SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: While OOC Arcane Destruction should be casted on self and his group members
-- TO-DO: Should he use Arcane Destruction while IC on allies?
-- TO-DO: Heal spells must be used both on allies and self
SET @ID := 18319;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,1000,1000,30000,30000,11,32689,32,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Out of Combat - Cast 'Arcane Destruction'"),
(@ID,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Scryer - On Aggro - Say Line 0"),
(@ID,0,2,0,0,0,100,0,3100,5300,3100,5300,11,32689,32,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - In Combat - Cast 'Arcane Destruction'"),
(@ID,0,3,0,0,0,100,2,7800,13300,10400,17700,11,22272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - In Combat - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,7800,13300,10400,17700,11,33988,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - In Combat - Cast 'Arcane Missiles' (Heroic Dungeon)"),
(@ID,0,5,0,74,0,100,2,0,75,9600,15700,11,17843,0,0,0,0,0,9,0,0,15,0,0,0,0,"Time-Lost Scryer - On Friendly Between 0-75% Health - Cast 'Flash Heal' (Normal Dungeon)"),
(@ID,0,6,0,74,0,100,4,0,75,9600,15700,11,17138,0,0,0,0,0,9,0,0,15,0,0,0,0,"Time-Lost Scryer - On Friendly Between 0-75% Health - Cast 'Flash Heal' (Heroic Dungeon)"),
(@ID,0,7,0,74,0,100,2,0,40,13200,21700,11,12160,1,0,0,0,0,9,0,0,15,0,0,0,0,"Time-Lost Scryer - On Friendly Between 0-40% Health - Cast 'Rejuvenation' (Normal Dungeon)"),
(@ID,0,8,0,74,0,100,4,0,40,13200,21700,11,15981,1,0,0,0,0,9,0,0,15,0,0,0,0,"Time-Lost Scryer - On Friendly Between 0-40% Health - Cast 'Rejuvenation' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Time-Lost Scryer"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Time-Lost Scryer"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Time-Lost Scryer"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Time-Lost Scryer"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Time-Lost Scryer");

-- + Time-Lost Shadowmage SAI (Source: ACID 4.3.4 OD - N/H)
-- Actually spawns only in normal mode. Currently in both. Heroic version added only because he spawns in both modes, let's keep it just because we can
-- TO-DO: Curse of the Dark Talon only if target does not have max stack?
SET @ID := 18320;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Shadowmage - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,6600,18600,9300,21800,11,32675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 'Shadow Missiles' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,6600,18600,9300,21800,11,38148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 'Shadow Missiles' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,2,4800,9600,21700,33800,11,32682,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 'Curse of the Dark Talon' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,4800,9600,21700,33800,11,38149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 'Curse of the Dark Talon' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Time-Lost Shadowmage"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Time-Lost Shadowmage"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Time-Lost Shadowmage"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Time-Lost Shadowmage"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Time-Lost Shadowmage");

-- + Sethekk Talon Lord SAI (Source: ACID 4.3.4 OD - N/H)
-- He should cast 'Avenger's Shield' on aggro, later on timers, added
-- TO-DO: Talon of Justice should be used on victim too if more than 1 target is available?
SET @ID := 18321;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Talon Lord - On Aggro - Say Line 0"),
(@ID,0,1,0,4,0,100,0,0,0,0,0,11,32674,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Talon Lord - On Aggro - Cast 'Avenger's Shield'"),
(@ID,0,2,0,0,0,100,0,2400,7200,16300,24300,11,32674,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Talon Lord - In Combat - Cast 'Avenger's Shield'"),
(@ID,0,3,0,0,0,100,0,9300,16700,14300,25400,11,32654,0,0,0,0,0,6,0,0,0,0,0,0,0,"Sethekk Talon Lord - In Combat - Cast 'Talon of Justice'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Talon Lord"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Talon Lord"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Talon Lord"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Talon Lord"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Talon Lord");

-- + Sethekk Ravenguard SAI (Source: ACID 4.3.4 OD - N/H + videos (https://www.youtube.com/watch?v=jsp6n_ssyjk))
SET @ID := 18322;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Don't reset it or it will not work after evade. Maybe they should respawn if only one was killed and
-- in this case it will not work without no reset flag
(@ID,0,0,0,11,0,100,256,0,0,0,0,64,1,0,0,0,0,0,19,18322,30,0,0,0,0,0,"Sethekk Ravenguard - On Respawn - Store Targetlist (No Reset)"),
(@ID,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Aggro - Say Line 0"),
(@ID,0,2,0,0,0,100,2,7200,20500,10800,21700,11,33964,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 'Bloodthirst' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,7200,20500,10800,21700,11,40423,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 'Bloodthirst' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,6100,17400,16800,21700,11,32651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 'Howling Screech'"),
(@ID,0,5,0,38,0,100,0,0,1,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Data Set 0 1 - Cast 'Frenzy'"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,12,1,0,0,0,0,0,0,"Sethekk Ravenguard - On Death - Set Data 0 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Ravenguard"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Ravenguard"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Ravenguard"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Ravenguard"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Ravenguard");

-- + Sethekk Guard SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18323;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Guard - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,3600,15700,10900,22100,11,33967,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Guard - In Combat - Cast 'Thunderclap'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Guard"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Guard"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Guard"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Guard"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Guard");

-- + Sethekk Prophet SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18325;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Prophet - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,8700,17700,13200,24100,11,27641,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Prophet - In Combat - Cast 'Fear'"),
(@ID,0,2,0,6,0,100,0,0,0,0,0,11,32692,7,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Prophet - On Death - Cast 'Summon Arakkoa Spirit'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Prophet"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Prophet"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Prophet"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Prophet"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Prophet");

-- + Sethekk Shaman SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Earth Shock must be used on random player casting, according to wowhead comments
-- TO-DO: Should resummon Dark Vortex if killed?
SET @ID := 18326;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Shaman - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,4300,9100,7200,14500,11,15501,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Shaman - In Combat - Cast 'Earth Shock' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,4300,9100,7200,14500,11,22885,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Shaman - In Combat - Cast 'Earth Shock' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,7900,14500,90000,90000,11,32663,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Shaman - In Combat - Cast 'Summon Dark Vortex'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Shaman"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Shaman"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Shaman"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Shaman"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Shaman");

-- + Time-Lost Controller SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18327;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Controller - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,9100,24100,27800,48300,11,32764,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Controller - In Combat - Cast 'Summon Charming Totem'"),
(@ID,0,2,0,0,0,100,0,8400,23200,9700,32600,11,35013,0,0,0,0,0,5,0,0,0,0,0,0,0,"Time-Lost Controller - In Combat - Cast 'Shrink'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Time-Lost Controller"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Time-Lost Controller"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Time-Lost Controller"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Time-Lost Controller"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Time-Lost Controller");

-- + Sethekk Oracle SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18328;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Oracle - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,6100,12100,18500,27700,11,32690,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 'Arcane Lightning' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,1200,12100,7200,13300,11,38146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 'Arcane Lightning' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,2400,8700,8400,19300,11,32129,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 'Faerie Fire'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"In Terokk's name!",12,0,100,0,0,0,16716,0,"Sethekk Oracle"),
(@ID,0,1,"Protect the Veil!",12,0,100,0,0,0,16717,0,"Sethekk Oracle"),
(@ID,0,2,"Darkfire -- avenge us!",12,0,100,0,0,0,16718,0,"Sethekk Oracle"),
(@ID,0,3,"Ssssekk-sara Rith-nealaak!",12,0,100,0,0,0,16719,0,"Sethekk Oracle"),
(@ID,0,4,"Arak-ha!",12,0,100,0,0,0,16720,0,"Sethekk Oracle");

-- Dark Vortex SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18701;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,3600,7200,8400,19300,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Vortex - In Combat - Cast 'Shadow Bolt'");

-- + Sethekk Spirit SAI (Source: ACID 4.3.4 OD - N/H + videos)
SET @ID := 18703;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sethekk Spirit - On Just Summoned - Set In Combat With Zone"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,11,17321,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Spirit - On Link - Cast 'Spirit Spawn-in'"),
(@ID,0,2,3,61,0,100,0,0,0,0,0,11,24051,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Spirit - On Link - Cast 'Spirit Burst'"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,116,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Spirit - On Link - Set Corpse Delay"),
(@ID,0,4,0,60,0,100,1,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Spirit - On Update - Kill Self (No Repeat)");

-- Syth Fire Elemental SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Shouldn't cast on max stack?
SET @ID := 19203;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,1600,7600,8400,18100,11,33526,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Fire Elemental - In Combat - Cast 'Flame Buffet' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,1200,3600,6000,7200,11,38141,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Fire Elemental - In Combat - Cast 'Flame Buffet' (Heroic Dungeon)");

-- Syth Frost Elemental SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Shouldn't cast on max stack?
SET @ID := 19204;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,1600,7600,8400,18100,11,33528,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Frost Elemental - In Combat - Cast 'Frost Buffet' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,1200,3600,6000,7200,11,38142,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Frost Elemental - In Combat - Cast 'Frost Buffet' (Heroic Dungeon)");

-- Syth Arcane Elemental SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Shouldn't cast on max stack?
SET @ID := 19205;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,1600,7600,8400,18100,11,33527,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Arcane Elemental - In Combat - Cast 'Arcane Buffet' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,1200,3600,6000,7200,11,38138,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Arcane Elemental - In Combat - Cast 'Arcane Buffet' (Heroic Dungeon)");

-- Syth Shadow Elemental SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Shouldn't cast on max stack?
SET @ID := 19206;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,1600,7600,8400,18100,11,33529,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Shadow Elemental - In Combat - Cast 'Shadow Buffet' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,1200,3600,6000,7200,11,38143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Shadow Elemental - In Combat - Cast 'Shadow Buffet' (Heroic Dungeon)");

-- + Cobalt Serpent SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 19428;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,4800,14500,13300,22900,11,17503,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Frostbolt' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,4800,14500,13300,22900,11,38238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,5600,22100,8400,25400,11,38193,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Lightning Breath' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,3600,22100,7200,14400,11,38133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Lightning Breath' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,6200,21700,12100,22800,11,38110,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Wing Buffet'");

-- + Avian Darkhawk SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Sonic Charge maybe is used on timers
SET @ID := 19429;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,9,0,100,3,8,25,0,0,11,38059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - Within 8-25 Range - Cast 'Sonic Charge' (Normal Dungeon) (No Repeat)"),
(@ID,0,1,0,9,0,100,5,8,25,0,0,11,39197,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - Within 8-25 Range - Cast 'Sonic Charge' (Heroic Dungeon) (No Repeat)"),
(@ID,0,2,0,0,0,100,2,4800,13600,10900,24100,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - In Combat - Cast 'Carnivorous Bite' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,4800,13600,10900,24100,11,39198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - In Combat - Cast 'Carnivorous Bite' (Heroic Dungeon)");

-- + Avian Ripper SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 21891;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,4300,12100,15600,19300,11,38056,32,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Ripper - In Combat - Cast 'Flesh Rip'");

-- + Avian Warhawk SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Sonic Charge maybe is used on timers
SET @ID := 21904;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,9,0,100,3,8,25,0,0,11,38059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - Within 8-25 Range - Cast 'Sonic Charge' (Normal Dungeon) (No Repeat)"),
(@ID,0,1,0,9,0,100,5,8,25,0,0,11,39197,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - Within 8-25 Range - Cast 'Sonic Charge' (Heroic Dungeon) (No Repeat)"),
(@ID,0,2,0,0,0,100,2,3800,11100,10900,21700,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 'Carnivorous Bite' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,3800,11100,10900,21700,11,39198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 'Carnivorous Bite' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,6200,25500,12100,24100,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 'Swoop'");
