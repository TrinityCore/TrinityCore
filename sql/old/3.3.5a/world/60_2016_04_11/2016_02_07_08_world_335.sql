-- DB/Quest: Urok Doomhowl - Summonscript
SET @MAGUS    = 10602;
SET @ENFORCER = 10601;
SET @UROK     = 10584;
SET @OGUID    = 21202;

UPDATE `creature_template` SET `faction`=40 WHERE  `entry`IN(10601,10602);


DELETE FROM `gameobject` WHERE `id` IN(175571,175584);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 175571, 229, 3, 1, -47.90947, -369.0891, 51.54253, 1.378809, 0, 0, 0, 1, -1, 255, 1), -- 175571 (Area: 0)
(@OGUID+1, 175571, 229, 3, 1, -27.88039, -385.8911, 48.50668, 3.700105, 0, 0, 0, 1, -1, 255, 1), -- 175571 (Area: 0)
(@OGUID+2, 175571, 229, 3, 1, -13.72754, -384.8161, 48.97457, 3.68265, 0, 0, 0, 1, -1, 255, 1), -- 175571 (Area: 0)
(@OGUID+3, 175571, 229, 3, 1, -12.36894, -376.4748, 49.335, 5.044002, 0, 0, 0, 1, -1, 255, 1), -- 175571 (Area: 0)
(@OGUID+4, 175571, 229, 3, 1, -24.88243, -369.6189, 49.70592, 3.403396, 0, 0, 0, 1, -1, 255, 1), -- 175571 (Area: 0)
(@OGUID+5, 175584, 229, 3, 1, -14.3415, -395.7287, 48.53813, 2.862335, 0, 0, 0, 1, -1, 255, 0), -- 175584 (Area: 0)
(@OGUID+6, 175571, 229, 3, 1, -34.54366, -370.2325, 50.3396, 5.358161, 0, 0, 0, 1, -1, 255, 1); -- 175571 (Area: 0)

UPDATE `gameobject` SET `position_y`=-395.729 WHERE  `guid`=99791;

DELETE FROM `event_scripts` WHERE `id`=4845;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(4845, 0, 9, @OGUID+0, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+1, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+2, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+3, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+4, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+5, 66, 0, 0, 0, 0, 0),
(4845, 0, 9, @OGUID+6, 66, 0, 0, 0, 0, 0),

(4845, 5, 10, @MAGUS, 900000, 0, -33.04, -385.57, 48.60, 5.98),
(4845, 5, 10, @ENFORCER, 900000, 0, -16.12, -376.99, 49.20, 4.89),
(4845, 5, 10, @ENFORCER, 900000, 0, -25.13, -376.60, 48.94, 5.17),
(4845, 13, 10, @MAGUS, 900000, 0, -14.93, -381.99, 49.04, 4.70),
(4845, 28, 10, @MAGUS, 900000, 0, -35.47, -371.36, 50.22, 4.79),
(4845, 28, 10, @ENFORCER, 900000, 0, -47.54, -368.11, 51.67, 5.70),
(4845, 42, 10, @MAGUS, 900000, 0, -33.04, -385.57, 48.60, 5.98),
(4845, 42, 10, @MAGUS, 900000, 0, -14.58, -375.16, 49.31, 4.73),
(4845, 42, 10, @ENFORCER, 900000, 0, -24.91, -376.41, 48.95, 4.67),
(4845, 58, 10, @MAGUS, 900000, 0, -47.54, -368.11, 51.67, 5.70),
(4845, 66, 10, @UROK, 900000, 0, -23.97, -391.89, 48.58, 1.68);

-- Urok Ogre Magus SAI
SET @ENTRY := 10602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15979,64,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Ogre Magus - In Combat - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-15% Health - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,16,0,100,2,6742,30,10000,15000,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,"Urok Ogre Magus - On Friendly Unit Missing Buff 'Bloodlust' - Cast 'Bloodlust' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,3000,4000,5000,8000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Ogre Magus - In Combat - Cast 'Slow' (Normal Dungeon)"),
(@ENTRY,0,5,0,54,0,100,1,0,0,0,0,11,64195,2,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - On Just Summoned - Cast 'Simple Teleport' (No Repeat)"),
(@ENTRY,0,6,0,54,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Urok Ogre Magus - On Just Summoned - Start Attacking (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 10602;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee', 1150);

-- Urok Enforcer SAI
SET @ENTRY := 10601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,3000,6000,11,16856,2,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Enforcer - In Combat - Cast 'Mortal Strike' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,1,0,1000,6000,7000,11,11084,2,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Enforcer - In Combat - Cast 'Shock' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,12000,17000,11,14516,2,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Enforcer - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,3,0,54,0,100,1,0,0,0,0,11,64195,2,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Enforcer - On Just Summoned - Cast 'Simple Teleport' (No Repeat)"),
(@ENTRY,0,4,0,54,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Urok Enforcer - On Just Summoned - Start Attacking (No Repeat)");
