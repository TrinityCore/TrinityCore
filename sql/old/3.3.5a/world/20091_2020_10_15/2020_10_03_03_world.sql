--
SET @POOL := 1510;

-- Update stats
-- 18766 & 18441 still requires updates
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `speed_walk` = 1, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20298; -- Angered Skeleton (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 1600, `unit_flags` = 32832 WHERE `entry` = 20299; -- Auchenai Monk (1)
UPDATE `creature_template` SET `maxlevel` = 67 WHERE `entry` = 18702; -- Auchenai Necromancer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20300; -- Auchenai Necromancer (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20301; -- Auchenai Soulpriest (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20302; -- Auchenai Vindicator (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 18478; -- Avatar of the Martyred
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20303; -- Avatar of the Martyred (1)
UPDATE `creature_template` SET `minlevel` = 65 WHERE `entry` = 18778; -- Cosmetic Raging Soul
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 33554688 WHERE `entry` = 20304; -- Cosmetic Raging Soul (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20306; -- Avatar of the Martyred (1)
UPDATE `creature_template` SET `maxlevel` = 66 WHERE `entry` = 18726; -- Flying Raging Soul
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 33555200 WHERE `entry` = 20307; -- Flying Raging Soul (1)
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `speed_walk` = 1.2, `speed_run` = 0.42857, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33554434 WHERE `entry` = 18374; -- Focus Fire
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `speed_walk` = 1.2, `speed_run` = 0.42857, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33554434 WHERE `entry` = 20308; -- Focus Fire (1)
UPDATE `creature_template` SET `maxlevel` = 66, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18503; -- Phantasmal Possessor
UPDATE `creature_template` SET `minlevel` = 70, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20309; -- Phantasmal Possessor (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20310; -- Phasing Cleric (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20311; -- Phasing Soldier (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20312; -- Phasing Sorcerer (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20313; -- Phasing Stalker (1)
-- Nothing in 2 sniffs, heroic level looks weird
-- UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70 WHERE `entry` = 18766; -- Pool of Souls
-- UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75 WHERE `entry` = 20314; -- Pool of Souls (1)
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20315; -- Raging Skeleton (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20316; -- Raging Soul (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20317; -- Reanimated Bones (1)
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry` = 18371; -- Shirrak the Dead Watcher
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20318; -- Shirrak the Dead Watcher (1)
UPDATE `creature_template` SET `minlevel` = 70 WHERE `entry` = 20305; -- Stolen Soul (1)
UPDATE `creature_template` SET `maxlevel` = 66, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18500; -- Unliving Cleric
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20320; -- Unliving Cleric (1)
UPDATE `creature_template` SET `maxlevel` = 66, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18498; -- Unliving Soldier
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20321; -- Unliving Soldier (1)
UPDATE `creature_template` SET `maxlevel` = 66, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18499; -- Unliving Sorcerer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20322; -- Unliving Sorcerer (1)
UPDATE `creature_template` SET `maxlevel` = 66, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18501; -- Unliving Stalker
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20323; -- Unliving Stalker (1)

-- Avatar of the Martyred SAI (add spawn spell)
SET @ID := 18478;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Avatar of the Martyred - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Avatar of the Martyred - On Link - Set In Combat With Zone"),
(@ID,0,2,0,0,0,100,0,6500,11500,6200,15700,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of the Martyred - In Combat - Cast 'Sunder Armor'"),
(@ID,0,3,0,0,0,100,0,12100,16800,10900,24100,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of the Martyred - In Combat - Cast 'Mortal Strike'");

-- D'ore SAI
SET @ID := 19412;
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Just Summoned - Run Script"),
(@ID,0,1,0,40,0,100,0,3,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Waypoint 3 Reached - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,11,7765,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Cast 'Projection'"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,0,53,0,19412,0,0,0,2,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Set Fly Off"),
(@ID*100+1,9,1,0,0,0,100,0,1000,1000,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Add NPC Flag Questgiver");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 19412;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(19412,0,0,1,0,0,0);

DELETE FROM `waypoints` WHERE `entry` = 19412;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(19412,1,-1.840991,-387.04874,50.275303,0,0,"D'ore"),
(19412,2,22.737076,-386.50403,34.94198,0,0,"D'ore"),
(19412,3,32.43662,-387.61356,26.386398,0,0,"D'ore");

-- Two Auchenai Soulpriest with channeling spell
-- Targets only 18778
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 32930 AND `ElseGroup` IN (1,2);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-83375,-83377) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-83375,0,0,0,25,0,100,0,0,0,0,0,0,11,32930,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Reset - Cast 'Blue Beam'"),
(-83375,0,1,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Say Line 0"),
(-83375,0,2,0,0,0,100,2,0,0,3600,4800,0,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(-83375,0,3,0,0,0,100,4,0,0,3600,4800,0,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(-83375,0,4,0,0,0,100,2,10800,19300,18300,33700,0,11,32858,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Normal Dungeon)"),
(-83375,0,5,0,0,0,100,4,10800,13300,16900,27700,0,11,38377,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Heroic Dungeon)"),
(-83375,0,6,0,2,0,100,0,0,50,19200,37400,0,11,32859,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-50% Health - Cast 'Falter'"),
(-83375,0,7,0,0,0,100,1,2000,5000,0,0,0,88,1849300,1849304,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Run Random Script (No Repeat)"),

(-83377,0,0,0,25,0,100,0,0,0,0,0,0,11,32930,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Reset - Cast 'Blue Beam'"),
(-83377,0,1,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Say Line 0"),
(-83377,0,2,0,0,0,100,2,0,0,3600,4800,0,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(-83377,0,3,0,0,0,100,4,0,0,3600,4800,0,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(-83377,0,4,0,0,0,100,2,10800,19300,18300,33700,0,11,32858,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Normal Dungeon)"),
(-83377,0,5,0,0,0,100,4,10800,13300,16900,27700,0,11,38377,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Heroic Dungeon)"),
(-83377,0,6,0,2,0,100,0,0,50,19200,37400,0,11,32859,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-50% Health - Cast 'Falter'"),
(-83377,0,7,0,0,0,100,1,2000,5000,0,0,0,88,1849300,1849304,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Run Random Script (No Repeat)");

-- Fix positions
UPDATE `creature` SET `position_x` = 132.256, `position_y` = -19.2385, `position_z` = 6.38628, `orientation` = 0.01745, `VerifiedBuild` = 12340 WHERE `guid` = 83375 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 136.687, `position_y` = -26.0342, `position_z` = 9.38649, `orientation` = 0.64577, `VerifiedBuild` = 12340 WHERE `guid` = 83377 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 77.8439, `position_y` = -8.14454, `position_z` = 0.02005, `orientation` = 4.46804, `VerifiedBuild` = 12340 WHERE `guid` = 83362 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 77.8439, `position_y` = -8.14454, `position_z` = 0.02005, `orientation` = 4.46804, `VerifiedBuild` = 12340 WHERE `guid` = 83361 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 81.6418, `position_y` = -8.10272, `position_z` = 0.01928, `orientation` = 4.52040, `VerifiedBuild` = 12340 WHERE `guid` = 83364 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 81.6418, `position_y` = -8.10272, `position_z` = 0.01928, `orientation` = 4.52040, `VerifiedBuild` = 12340 WHERE `guid` = 83360 AND `id` = 18493;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 104176 AND `id` = 18778;
UPDATE `creature` SET `position_x` = 21.7842, `position_y` = -160.769, `position_z` = 13.6513, `orientation` = 3.07177, `VerifiedBuild` = 12340 WHERE `guid` = 83407 AND `id` = 18497;
UPDATE `creature` SET `position_x` = 25.2436, `position_y` = -166.950, `position_z` = 13.9401, `orientation` = 2.79252, `VerifiedBuild` = 12340 WHERE `guid` = 83395 AND `id` = 18497;
UPDATE `creature` SET `position_x` = -127.443, `position_y` = -159.481, `position_z` = 26.6723, `orientation` = 6.05629, `VerifiedBuild` = 12340 WHERE `guid` = 83394 AND `id` = 18497;
UPDATE `creature` SET `position_x` = -122.563, `position_y` = -166.735, `position_z` = 26.6719, `orientation` = 0.06981, `VerifiedBuild` = 12340 WHERE `guid` = 83409 AND `id` = 18497;
UPDATE `creature` SET `position_x` = 85.3602, `position_y` = 8.43023, `position_z` = 0.01832, `orientation` = 1.41371, `VerifiedBuild` = 12340 WHERE `guid` = 83353 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 85.3602, `position_y` = 8.43023, `position_z` = 0.01832, `orientation` = 1.41371, `VerifiedBuild` = 12340 WHERE `guid` = 83355 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 78.3840, `position_y` = 39.2965, `position_z` = 4.34501, `orientation` = 1.39626, `VerifiedBuild` = 12340 WHERE `guid` = 83363 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 78.3840, `position_y` = 39.2965, `position_z` = 4.34501, `orientation` = 1.39626, `VerifiedBuild` = 12340 WHERE `guid` = 83365 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 92.4968, `position_y` = -39.0355, `position_z` = 4.34450, `orientation` = 4.52040, `VerifiedBuild` = 12340 WHERE `guid` = 83351 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 92.4968, `position_y` = -39.0355, `position_z` = 4.34450, `orientation` = 4.52040, `VerifiedBuild` = 12340 WHERE `guid` = 83356 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 85.7185, `position_y` = 39.3367, `position_z` = 4.34490, `orientation` = 1.48352, `VerifiedBuild` = 12340 WHERE `guid` = 83358 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 85.7185, `position_y` = 39.3367, `position_z` = 4.34490, `orientation` = 1.48352, `VerifiedBuild` = 12340 WHERE `guid` = 83359 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 89.7786, `position_y` = 8.61549, `position_z` = 0.01932, `orientation` = 1.48352, `VerifiedBuild` = 12340 WHERE `guid` = 83352 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 89.7786, `position_y` = 8.61549, `position_z` = 0.01932, `orientation` = 1.48352, `VerifiedBuild` = 12340 WHERE `guid` = 83354 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 187.004, `position_y` = 4.80022, `position_z` = -0.03852, `orientation` = 4.95673, `VerifiedBuild` = 12340 WHERE `guid` = 83389 AND `id` = 18497;
UPDATE `creature` SET `position_x` = 87.4967, `position_y` = -38.8735, `position_z` = 4.34451, `orientation` = 4.53785, `VerifiedBuild` = 12340 WHERE `guid` = 83366 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 87.4967, `position_y` = -38.8735, `position_z` = 4.34451, `orientation` = 4.53785, `VerifiedBuild` = 12340 WHERE `guid` = 83357 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 122.388, `position_y` = 3.71185, `position_z` = -0.04624, `orientation` = 4.10152, `VerifiedBuild` = 12340 WHERE `guid` = 83376 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 117.888, `position_y` = -4.55225, `position_z` = 0.05047, `orientation` = 0.87266, `VerifiedBuild` = 12340 WHERE `guid` = 83369 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 139.131, `position_y` = 39.3849, `position_z` = 4.34415, `orientation` = 1.46607, `VerifiedBuild` = 12340 WHERE `guid` = 83367 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 139.131, `position_y` = 39.3849, `position_z` = 4.34415, `orientation` = 1.46607, `VerifiedBuild` = 12340 WHERE `guid` = 83368 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 247.790, `position_y` = -9.66694, `position_z` = 0.02644, `orientation` = 3.92699, `VerifiedBuild` = 12340 WHERE `guid` = 83373 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 148.659, `position_y` = 39.4251, `position_z` = 4.34409, `orientation` = 1.30899, `VerifiedBuild` = 12340 WHERE `guid` = 83371 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 148.659, `position_y` = 39.4251, `position_z` = 4.34409, `orientation` = 1.30899, `VerifiedBuild` = 12340 WHERE `guid` = 83370 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 189.554, `position_y` = -3.35629, `position_z` = 0.08177, `orientation` = 1.58824, `VerifiedBuild` = 12340 WHERE `guid` = 83382 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 230.386, `position_y` = 19.4329, `position_z` = 0.01958, `orientation` = 1.41371, `VerifiedBuild` = 12340 WHERE `guid` = 83380 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 242.325, `position_y` = -15.5678, `position_z` = 0.02191, `orientation` = 0.82030, `VerifiedBuild` = 12340 WHERE `guid` = 83381 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 227.658, `position_y` = -170.580, `position_z` = 26.6746, `orientation` = 0.52359, `VerifiedBuild` = 12340 WHERE `guid` = 83408 AND `id` = 18497;
UPDATE `creature` SET `position_x` = 227.659, `position_y` = -155.120, `position_z` = 26.6746, `orientation` = 5.35816, `VerifiedBuild` = 12340 WHERE `guid` = 83384 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 225.460, `position_y` = -163.387, `position_z` = 26.6746, `orientation` = 6.05629, `VerifiedBuild` = 12340 WHERE `guid` = 83387 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 66.7657, `position_y` = -388.345, `position_z` = 26.6733, `orientation` = 2.93215, `VerifiedBuild` = 12340 WHERE `guid` = 83453 AND `id` = 18373;

-- Only these are pooled, checked 3 sniffs + one handmade spawn (not current)
UPDATE `creature` SET `position_x` = -134.907, `position_y` = -246.094, `position_z` = 26.4062, `orientation` = 2.54640, `VerifiedBuild` = 12340 WHERE `guid` = 83393 AND `id` = 18524;
UPDATE `creature` SET `position_x` = -124.254, `position_y` = -250.334, `position_z` = 26.4196, `orientation` = 1.14886, `VerifiedBuild` = 12340 WHERE `guid` = 83401 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -141.887, `position_y` = -252.918, `position_z` = 26.7513, `orientation` = 3.20391, `VerifiedBuild` = 12340 WHERE `guid` = 83410 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -161.974, `position_y` = -290.732, `position_z` = 27.1538, `orientation` = 2.15799, `VerifiedBuild` = 12340 WHERE `guid` = 83396 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -126.534, `position_y` = -292.311, `position_z` = 27.3787, `orientation` = 2.44332, `VerifiedBuild` = 12340 WHERE `guid` = 83413 AND `id` = 18524;

UPDATE `creature` SET `position_x` = -133.863, `position_y` = -260.685, `position_z` = 26.7964, `orientation` = 3.32473, `VerifiedBuild` = 12340, `id` = 18524 WHERE `guid` = 83403 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -135.660, `position_y` = -298.889, `position_z` = 26.2331, `orientation` = 6.26825, `VerifiedBuild` = 12340 WHERE `guid` = 83400 AND `id` = 18524;
UPDATE `creature` SET `position_x` = -148.484, `position_y` = -280.848, `position_z` = 26.4150, `orientation` = 1.44956, `VerifiedBuild` = 12340, `id` = 18524 WHERE `guid` = 83397 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -128.355, `position_y` = -303.919, `position_z` = 26.5348, `orientation` = 0.53588, `VerifiedBuild` = 12340 WHERE `guid` = 83414 AND `id` = 18524;
UPDATE `creature` SET `position_x` = -170.976, `position_y` = -276.465, `position_z` = 31.6516, `orientation` = 4.13776, `VerifiedBuild` = 12340 WHERE `guid` = 83399 AND `id` = 18524;
UPDATE `creature` SET `position_x` = -158.783, `position_y` = -264.385, `position_z` = 24.5374, `orientation` = 1.99998, `VerifiedBuild` = 12340 WHERE `guid` = 83402 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -139.450, `position_y` = -312.464, `position_z` = 26.5910, `orientation` = 4.88842, `VerifiedBuild` = 12340 WHERE `guid` = 83411 AND `id` = 18521;
UPDATE `creature` SET `position_x` = -156.385, `position_y` = -276.651, `position_z` = 26.6656, `orientation` = 0.38677, `VerifiedBuild` = 12340, `id` = 18521 WHERE `guid` = 83398 AND `id` = 18524;
UPDATE `creature` SET `position_x` = -131.077, `position_y` = -313.713, `position_z` = 28.4638, `orientation` = 5.65578, `VerifiedBuild` = 12340 WHERE `guid` = 83412 AND `id` = 18521;
UPDATE `creature` SET `wander_distance` = 2 WHERE `id` IN (18521,18524);

-- Reanimated Bones
UPDATE `creature` SET `position_x` = -70.1430, `position_y` = -377.463, `position_z` = 26.5889, `orientation` = 2.41522, `VerifiedBuild` = 12340 WHERE `guid` = 83417 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -70.3044, `position_y` = -369.064, `position_z` = 26.5888, `orientation` = 2.93664, `VerifiedBuild` = 12340 WHERE `guid` = 83418 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -37.0655, `position_y` = -354.198, `position_z` = 26.9085, `orientation` = 3.24631, `VerifiedBuild` = 12340 WHERE `guid` = 83419 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -45.0082, `position_y` = -364.025, `position_z` = 26.5894, `orientation` = 0.67847, `VerifiedBuild` = 12340 WHERE `guid` = 83420 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -59.3047, `position_y` = -373.747, `position_z` = 26.5865, `orientation` = 3.42051, `VerifiedBuild` = 12340 WHERE `guid` = 83421 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -64.6624, `position_y` = -370.641, `position_z` = 26.5876, `orientation` = 5.50918, `VerifiedBuild` = 12340 WHERE `guid` = 83422 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -56.8285, `position_y` = -361.218, `position_z` = 26.6057, `orientation` = 2.61762, `VerifiedBuild` = 12340 WHERE `guid` = 83424 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -57.5746, `position_y` = -380.266, `position_z` = 26.5861, `orientation` = 5.89536, `VerifiedBuild` = 12340 WHERE `guid` = 83425 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -59.0922, `position_y` = -398.448, `position_z` = 28.0772, `orientation` = 4.13243, `VerifiedBuild` = 12340 WHERE `guid` = 83428 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -63.4261, `position_y` = -403.212, `position_z` = 28.2131, `orientation` = 2.40976, `VerifiedBuild` = 12340 WHERE `guid` = 83429 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -68.5817, `position_y` = -407.449, `position_z` = 26.6690, `orientation` = 2.40190, `VerifiedBuild` = 12340 WHERE `guid` = 83430 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -61.7229, `position_y` = -410.100, `position_z` = 26.5842, `orientation` = 5.74202, `VerifiedBuild` = 12340 WHERE `guid` = 83431 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -52.4464, `position_y` = -393.722, `position_z` = 26.8617, `orientation` = 2.01189, `VerifiedBuild` = 12340 WHERE `guid` = 83432 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -46.3949, `position_y` = -374.708, `position_z` = 26.5836, `orientation` = 0.03451, `VerifiedBuild` = 12340 WHERE `guid` = 83433 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -55.2191, `position_y` = -402.074, `position_z` = 30.4996, `orientation` = 3.82747, `VerifiedBuild` = 12340 WHERE `guid` = 83434 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -50.3705, `position_y` = -404.235, `position_z` = 30.0937, `orientation` = 2.76500, `VerifiedBuild` = 12340 WHERE `guid` = 83435 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -47.2448, `position_y` = -396.088, `position_z` = 27.8633, `orientation` = 4.01421, `VerifiedBuild` = 12340 WHERE `guid` = 83436 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -52.4654, `position_y` = -412.464, `position_z` = 27.3812, `orientation` = 3.33429, `VerifiedBuild` = 12340 WHERE `guid` = 83437 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -45.9900, `position_y` = -396.984, `position_z` = 27.6335, `orientation` = 0.99293, `VerifiedBuild` = 12340 WHERE `guid` = 83438 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -31.5695, `position_y` = -365.554, `position_z` = 26.5876, `orientation` = 2.55308, `VerifiedBuild` = 12340 WHERE `guid` = 83439 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -30.1582, `position_y` = -392.926, `position_z` = 21.7792, `orientation` = 3.97676, `VerifiedBuild` = 12340 WHERE `guid` = 83440 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -31.8871, `position_y` = -417.657, `position_z` = 26.6253, `orientation` = 2.14757, `VerifiedBuild` = 12340 WHERE `guid` = 83441 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -30.4129, `position_y` = -374.279, `position_z` = 22.4391, `orientation` = 4.84041, `VerifiedBuild` = 12340 WHERE `guid` = 83442 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -29.4016, `position_y` = -408.562, `position_z` = 26.5948, `orientation` = 5.70351, `VerifiedBuild` = 12340 WHERE `guid` = 83443 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -29.3163, `position_y` = -352.117, `position_z` = 28.9317, `orientation` = 2.74698, `VerifiedBuild` = 12340 WHERE `guid` = 83444 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -33.1605, `position_y` = -399.026, `position_z` = 24.1221, `orientation` = 2.53145, `VerifiedBuild` = 12340 WHERE `guid` = 83445 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -23.2149, `position_y` = -367.904, `position_z` = 26.5808, `orientation` = 5.23207, `VerifiedBuild` = 12340 WHERE `guid` = 83446 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -14.0088, `position_y` = -376.059, `position_z` = 20.4852, `orientation` = 4.41723, `VerifiedBuild` = 12340 WHERE `guid` = 83447 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -18.1280, `position_y` = -417.605, `position_z` = 26.6053, `orientation` = 5.99070, `VerifiedBuild` = 12340 WHERE `guid` = 83448 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -24.0462, `position_y` = -358.839, `position_z` = 26.6028, `orientation` = 2.85429, `VerifiedBuild` = 12340 WHERE `guid` = 83449 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -16.1842, `position_y` = -398.593, `position_z` = 20.0513, `orientation` = 0.35187, `VerifiedBuild` = 12340 WHERE `guid` = 83450 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -20.7825, `position_y` = -405.465, `position_z` = 25.4570, `orientation` = 3.34263, `VerifiedBuild` = 12340 WHERE `guid` = 83451 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -17.6506, `position_y` = -354.634, `position_z` = 26.5920, `orientation` = 0.73305, `VerifiedBuild` = 12340 WHERE `guid` = 83452 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -9.05496, `position_y` = -370.898, `position_z` = 24.5257, `orientation` = 2.36652, `VerifiedBuild` = 12340 WHERE `guid` = 88277 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -11.1522, `position_y` = -406.241, `position_z` = 26.0603, `orientation` = 1.29951, `VerifiedBuild` = 12340 WHERE `guid` = 88278 AND `id` = 18700;
UPDATE `creature` SET `position_x` = -15.6333, `position_y` = -361.085, `position_z` = 26.5919, `orientation` = 5.39090, `VerifiedBuild` = 12340 WHERE `guid` = 88279 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 16.9976, `position_y` = -383.822, `position_z` = 19.8349, `orientation` = 2.56856, `VerifiedBuild` = 12340 WHERE `guid` = 88280 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 8.66712, `position_y` = -372.301, `position_z` = 23.4212, `orientation` = 3.10270, `VerifiedBuild` = 12340 WHERE `guid` = 88281 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 21.4631, `position_y` = -374.647, `position_z` = 23.3184, `orientation` = 1.09663, `VerifiedBuild` = 12340 WHERE `guid` = 88283 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 9.49306, `position_y` = -398.798, `position_z` = 20.2107, `orientation` = 2.74450, `VerifiedBuild` = 12340 WHERE `guid` = 88284 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 3.69388, `position_y` = -402.122, `position_z` = 22.7467, `orientation` = 1.35305, `VerifiedBuild` = 12340 WHERE `guid` = 88285 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 13.3490, `position_y` = -415.713, `position_z` = 26.5905, `orientation` = 0.47158, `VerifiedBuild` = 12340 WHERE `guid` = 88286 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 24.6692, `position_y` = -414.842, `position_z` = 26.5985, `orientation` = 1.08111, `VerifiedBuild` = 12340 WHERE `guid` = 88287 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 17.9803, `position_y` = -400.050, `position_z` = 21.1781, `orientation` = 5.53106, `VerifiedBuild` = 12340 WHERE `guid` = 88288 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 10.5345, `position_y` = -405.983, `position_z` = 25.8243, `orientation` = 3.46459, `VerifiedBuild` = 12340 WHERE `guid` = 88289 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 17.2126, `position_y` = -372.087, `position_z` = 23.6060, `orientation` = 1.26627, `VerifiedBuild` = 12340 WHERE `guid` = 88290 AND `id` = 18700;
UPDATE `creature` SET `position_x` = 21.8998, `position_y` = -360.026, `position_z` = 26.6169, `orientation` = 4.62559, `VerifiedBuild` = 12340 WHERE `guid` = 88291 AND `id` = 18700;

DELETE FROM `creature` WHERE `guid` IN (130978,130979,130980,130981,130982,130992,130993,130994,131000);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(130978, 18700, 558, 3, 1, 0, 30.7721, -371.381, 27.2539, 2.94669, 10800, 5, 1, 12340),
(130979, 18700, 558, 3, 1, 0, 7.60484, -360.053, 26.5984, 0.59437, 10800, 5, 1, 12340),
(130980, 18700, 558, 3, 1, 0, 30.2229, -365.161, 26.9711, 4.27497, 10800, 5, 1, 12340),
(130981, 18700, 558, 3, 1, 0, 22.0397, -380.514, 23.8941, 4.34587, 10800, 5, 1, 12340),
(130982, 18700, 558, 3, 1, 0, 7.35660, -356.587, 26.6072, 3.05876, 10800, 5, 1, 12340),
(130992, 18700, 558, 3, 1, 0, 23.3647, -393.972, 24.8048, 2.30260, 10800, 5, 1, 12340),
(130993, 18700, 558, 3, 1, 0, 9.20711, -417.384, 26.5897, 5.34991, 10800, 5, 1, 12340),
(130994, 18700, 558, 3, 1, 0, 30.3119, -414.808, 26.5963, 1.19961, 10800, 5, 1, 12340),
(131000, 18700, 558, 3, 1, 0, 33.1965, -402.759, 26.5827, 2.46299, 10800, 5, 1, 12340);

-- Ancient Draenei Spirit
DELETE FROM `creature` WHERE `guid` IN (131001,131002,131003,131004);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131001, 19416, 558, 3, 1, 0, 85.0450, 48.4070, 13.0171, 6.21337, 300, 0, 0, 12340),
(131002, 19416, 558, 3, 1, 0, 85.4924, 47.0913, 24.3882, 6.12610, 300, 0, 0, 12340),
(131003, 19416, 558, 3, 1, 0, 72.8591, 46.5644, 24.3767, 6.12610, 300, 0, 0, 12340),
(131004, 19416, 558, 3, 1, 0, 98.0461, 46.8370, 24.4001, 6.12610, 300, 0, 0, 12340);

DELETE FROM `creature_addon` WHERE `guid` IN (131001,131002,131003,131004);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(131001,0,0,65539,1,0,0,""),
(131002,0,0,65539,1,0,0,""),
(131003,0,0,65539,1,0,0,""),
(131004,0,0,65539,1,0,0,"");

-- Critters
DELETE FROM `creature` WHERE `guid` IN (131005,131006,131007,131008,131009,131013,131019,131039,131040,131041,131042,131043,131044,131045,131046,131047,131048,131049,131050,131052);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131005, 14881, 558, 3, 1, 0, 45.9705, 15.7843, -0.13065, 1.54717, 300, 10, 1, 12340),
(131006, 14881, 558, 3, 1, 0, 88.9477, 43.0601, 4.26159, 3.46546, 300, 10, 1, 12340),
(131007, 14881, 558, 3, 1, 0, 97.6781, -48.1762, 13.0288, 3.89208, 300, 0, 0, 12340),
(131008, 14881, 558, 3, 1, 0, 159.082, 48.3017, 13.0051, 2.72271, 300, 0, 0, 12340),
(131009, 14881, 558, 3, 1, 0, 248.781, 26.7057, 0.01202, 2.72271, 300, 10, 1, 12340),
(131013, 14881, 558, 3, 1, 0, 246.982, -88.6826, 26.5912, 0.04045, 300, 10, 1, 12340),
(131019, 14881, 558, 3, 1, 0, 264.098, -166.265, 26.6746, 4.64257, 300, 10, 1, 12340),
(131039, 14881, 558, 3, 1, 0, 278.047, -162.845, 26.6746, 2.91469, 300, 10, 1, 12340),
(131040, 14881, 558, 3, 1, 0, 183.139, -184.690, 26.5628, 0.01123, 300, 10, 1, 12340),
(131041, 14881, 558, 3, 1, 0, 239.784, -199.027, 26.6746, 2.88579, 300, 10, 1, 12340),
(131042, 14881, 558, 3, 1, 0, -111.230, -170.612, 26.5884, 6.24807, 300, 10, 1, 12340),
(131043, 14881, 558, 3, 1, 0, -110.442, -251.887, 26.6921, 4.41992, 300, 10, 1, 12340),
(131044, 14881, 558, 3, 1, 0, -177.470, -315.551, 26.6425, 3.19077, 300, 10, 1, 12340),
(131045, 14881, 558, 3, 1, 0, -128.316, -319.891, 29.0650, 2.07003, 300, 10, 1, 12340),
(131046, 14881, 558, 3, 1, 0, -100.088, -395.204, 26.5901, 6.00871, 300, 10, 1, 12340),
(131047, 14881, 558, 3, 1, 0, -35.9457, -339.215, 39.7284, 2.04203, 300, 0, 0, 12340),
(131048, 14881, 558, 3, 1, 0, -53.6567, -401.499, 30.5934, 2.58308, 300, 10, 1, 12340),
(131049, 14881, 558, 3, 1, 0, 13.3255, -430.955, 30.9725, 0.00879, 300, 10, 1, 12340),
(131050, 14881, 558, 3, 1, 0, 49.7898, -369.159, 26.6682, 6.02138, 300, 10, 1, 12340),
(131052, 14881, 558, 3, 1, 0, 25.7139, -340.025, 45.4137, 2.84488, 300, 0, 0, 12340);

-- Auchenai Necromancer
UPDATE `creature` SET `position_x` = -51.8320, `position_y` = -361.962, `position_z` = 26.6115 WHERE `guid` = 83426 AND `id` = 18702;
UPDATE `creature` SET `position_x` = 4.82641, `position_y` = -409.194, `position_z` = 26.5824 WHERE `guid` = 83427 AND `id` = 18702;
UPDATE `creature` SET `position_x` = -23.3478, `position_y` = -410.184, `position_z` = 26.6765, `orientation` = 2.98451, `MovementType` = 0, `VerifiedBuild` = 12340 WHERE `guid` = 83415 AND `id` = 18702;
UPDATE `creature` SET `position_x` = -20.6588, `position_y` = -365.689, `position_z` = 26.6665, `orientation` = 2.96705, `MovementType` = 0, `VerifiedBuild` = 12340 WHERE `guid` = 83416 AND `id` = 18702;

DELETE FROM `creature_addon` WHERE `guid` IN (83415,83416,83423);
DELETE FROM `creature` WHERE `guid` = 83423 AND `id` = 18702;
DELETE FROM `linked_respawn` WHERE `guid` = 83423;

DELETE FROM `waypoint_data` WHERE `id` IN (834260,834270,834150,834160,834230);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(834260,1,-51.832047,-361.96216,26.611528),
(834260,2,-54.04397,-369.78027,26.585318),
(834260,3,-53.09907,-376.52548,26.585176),
(834260,4,-48.328968,-381.7298,26.584183),
(834260,5,-53.09907,-376.52548,26.585176),
(834260,6,-54.04397,-369.78027,26.585318),
(834270,1,4.82641,-409.19406,26.582476),
(834270,2,27.47761,-409.23453,26.590727),
(834270,3,27.672134,-401.97705,26.582186),
(834270,4,27.47761,-409.23453,26.590727);

-- Cosmetic scripts for the ones without paths
-- Quite possible in HM they use heroic version of 33325
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-83415,-83416) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-83415,0,0,0,1,0,100,0,10000,15000,25000,25000,0,11,33325,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Necromancer - Out of Combat - Cast 'Shadow Mend'"),
(-83415,0,1,0,4,0,40,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Aggro - Say Line 0"),
(-83415,0,2,0,0,0,100,0,1000,15200,4800,15700,0,11,35839,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Drain Soul'"),
(-83415,0,3,0,0,0,100,2,12100,29000,22900,35000,0,11,32863,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Normal Dungeon)"),
(-83415,0,4,0,0,0,100,4,12100,17500,4800,9600,0,11,38252,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Heroic Dungeon)"),
(-83415,0,5,0,74,0,100,2,0,70,15700,26500,15,11,33325,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Normal Dungeon)"),
(-83415,0,6,0,74,0,100,4,0,70,6100,8400,15,11,37367,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Heroic Dungeon)"),

(-83416,0,0,0,1,0,100,0,10000,15000,25000,25000,0,11,33325,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Auchenai Necromancer - Out of Combat - Cast 'Shadow Mend'"),
(-83416,0,1,0,4,0,40,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Aggro - Say Line 0"),
(-83416,0,2,0,0,0,100,0,1000,15200,4800,15700,0,11,35839,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Drain Soul'"),
(-83416,0,3,0,0,0,100,2,12100,29000,22900,35000,0,11,32863,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Normal Dungeon)"),
(-83416,0,4,0,0,0,100,4,12100,17500,4800,9600,0,11,38252,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Heroic Dungeon)"),
(-83416,0,5,0,74,0,100,2,0,70,15700,26500,15,11,33325,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Normal Dungeon)"),
(-83416,0,6,0,74,0,100,4,0,70,6100,8400,15,11,37367,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Heroic Dungeon)");

-- Shirrak the Dead Watcher
UPDATE `creature` SET `position_x` = -24.4075, `position_y` = -163.498, `position_z` = 26.1805, `orientation` = 0, `VerifiedBuild` = 12340 WHERE `guid` = 83388 AND `id` = 18371;

DELETE FROM `waypoint_data` WHERE `id` = 833880;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(833880,1,-24.407522,-163.4984,26.180597,0,35000,0,0,100,0),
(833880,2,-63.118973,-162.7913,26.528515,6.28318,35000,0,0,100,0),
(833880,3,-24.407522,-163.4984,26.180597,0,0,0,0,100,0);

-- Auchenai Monk
UPDATE `creature` SET `position_x` = 125.416, `position_y` = -3.26788, `position_z` = 0.20679, `orientation` = 2.44346, `VerifiedBuild` = 12340 WHERE `guid` = 83390 AND `id` = 18497;

DELETE FROM `waypoint_data` WHERE `id` = 833900;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(833900,1,125.41664,-3.26788,0.20679134,2.44346,30000,0,6,100,0),
(833900,2,129.40025,-2.901883,0.09694922,0,0,0,0,100,0),
(833900,3,132.78331,-0.456463,0.09080685,0,0,0,0,100,0),
(833900,4,139.49518,2.368823,-0.12775199,0,0,0,0,100,0),
(833900,5,148.84927,3.26893,-0.12693678,0,0,0,0,100,0),
(833900,6,158.58562,2.221657,-0.12592205,0,0,0,0,100,0),
(833900,7,161.79138,3.731095,-0.12575626,0,0,0,0,100,0),
(833900,8,164.71635,9.033345,-0.12607376,0,0,0,0,100,0),
(833900,9,164.69518,17.096685,0.042672902,0,0,0,0,100,0),
(833900,10,164.39384,27.017565,-0.03106403,0,0,0,0,100,0),
(833900,11,162.55814,29.54538,-0.11737426,0,0,0,0,100,0),
(833900,12,158.12143,30.15233,-0.110156596,0,0,0,0,100,0),
(833900,13,154.54019,31.208351,-0.1003358,0,0,0,0,100,0),
(833900,14,153.56567,33.075607,-0.086514466,0,0,0,0,100,0),
(833900,15,153.38432,35.838932,2.3343213,0,0,0,0,100,0),
(833900,16,153.50821,38.660362,4.2311373,0,33000,0,496,100,0),
(833900,17,153.40057,32.949512,-0.08729509,0,0,0,0,100,0),
(833900,18,150.59761,30.838694,-0.10033664,0,0,0,0,100,0),
(833900,19,132.99837,30.463366,-0.09167093,0,0,0,0,100,0),
(833900,20,128.37924,26.073841,-0.1093584,0,0,0,0,100,0),
(833900,21,129.23076,20.53834,-0.12918013,0,0,0,0,100,0),
(833900,22,130.77061,10.76564,0.09537188,0,0,0,0,100,0),
(833900,23,130.48642,2.902071,-0.12865439,0,0,0,0,100,0),
(833900,24,129.59958,-2.468409,0.06528245,0,0,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (496,6);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`, `Comment`) VALUES
(496,1,2,74,8,0,0,0,0,0,520,"Auchenai Monk - On Script - Set Flag Standstate Kneel"),
(496,33,2,74,0,0,0,0,0,0,521,"Auchenai Monk - On Script - Remove Flag Standstate Kneel"),
(6,8,2,74,8,0,0,0,0,0,8,"Auchenai Monk - On Script - Set Flag Standstate Kneel"),
(6,30,2,74,0,0,0,0,0,0,9,"Auchenai Monk - On Script - Remove Flag Standstate Kneel");

UPDATE `creature` SET `position_x` = 238.911, `position_y` = 13.9849, `position_z` = -0.06744 WHERE `guid` = 83404 AND `id` = 18497;

DELETE FROM `waypoint_data` WHERE `id` = 834040;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(834040,1,238.91144,13.98499,-0.067445435,0,8000,0,0,100,0),
(834040,2,222.74164,13.925282,-0.070625804,0,0,0,0,100,0),
(834040,3,222.52168,13.538798,-0.07114606,0,8000,0,0,100,0),
(834040,4,238.14801,13.610128,-0.06791844,0,0,0,0,100,0);

-- Pooling & paths
-- This one is not pooled actually, we'll use this pool for another unpooled creature
UPDATE `pool_members` SET `spawnId` = 83376 WHERE `type` = 0 AND `spawnId` = 83368 AND `poolSpawnId` = 1508;
UPDATE `creature` SET `position_x` = 122.388, `position_y` = 3.71185, `position_z` = -0.04624, `orientation` = 4.10152, `VerifiedBuild` = 12340 WHERE `guid` = 83367 AND `id` = 18495;

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL+0 AND @POOL+5;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL+0, 1, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator"),
(@POOL+1, 1, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator"),
(@POOL+2, 1, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator"),
(@POOL+3, 1, "Auchenai Crypts - Auchenai Vindicator / Auchenai Monk"),
(@POOL+4, 1, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator"),
(@POOL+5, 1, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator");

DELETE FROM `pool_members` WHERE `type` = 0 AND `spawnId` IN (83382,131057,83380,131060,83381,131061,83373,131062,83379,131065,83383,131067);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 83382, @POOL+0, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Soulpriest"),
(0, 131057, @POOL+0, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Vindicator"),
(0, 83380, @POOL+1, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Soulpriest"),
(0, 131060, @POOL+1, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Vindicator"),
(0, 83381, @POOL+2, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Soulpriest"),
(0, 131061, @POOL+2, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Vindicator"),
(0, 83373, @POOL+3, 0, "Auchenai Crypts - Auchenai Vindicator / Auchenai Monk - Auchenai Vindicator"),
(0, 131062, @POOL+3, 0, "Auchenai Crypts - Auchenai Vindicator / Auchenai Monk - Auchenai Monk"),
(0, 83379, @POOL+4, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Soulpriest"),
(0, 131065, @POOL+4, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Vindicator"),
(0, 83383, @POOL+5, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Soulpriest"),
(0, 131067, @POOL+5, 0, "Auchenai Crypts - Auchenai Soulpriest / Auchenai Vindicator - Auchenai Vindicator");

DELETE FROM `creature` WHERE `guid` IN (131057,131060,131061,131062,131065,131067);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131057, 18495, 558, 3, 1, 1, 189.554, -3.35629, 0.08177, 1.58824, 10800, 0, 0, 12340),
(131060, 18495, 558, 3, 1, 1, 230.386, 19.4329, 0.01958, 1.41371, 10800, 0, 0, 12340),
(131061, 18495, 558, 3, 1, 1, 242.325, -15.5678, 0.02191, 0.82030, 10800, 0, 0, 12340),
(131062, 18497, 558, 3, 1, 1, 247.790, -9.66694, 0.02644, 3.92699, 10800, 0, 0, 12340),
(131065, 18495, 558, 3, 1, 1, 86.5258, -4.11577, -0.05583, 3.14909, 10800, 0, 2, 12340),
(131067, 18495, 558, 3, 1, 1, 97.3622, 4.19906, -0.09821, 3.35687, 10800, 0, 2, 12340);

DELETE FROM `creature_addon` WHERE `guid` IN (131057,83380,131060,131061,131062,131065,131067);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(131057,0,0,8,1,0,0,""),
(83380,0,0,8,1,0,0,""),
(131060,0,0,8,1,0,0,""),
(131061,0,0,8,1,0,0,""),
(131062,0,0,8,1,0,0,""),
(131065,1310650,0,0,1,0,0,""),
(131067,1310670,0,0,1,0,0,"");

UPDATE `creature` SET `position_x` = 86.5258, `position_y` = -4.11577, `position_z` = -0.05583, `orientation` = 3.14909, `VerifiedBuild` = 12340 WHERE `guid` = 83379 AND `id` = 18493;
UPDATE `creature` SET `position_x` = 97.3622, `position_y` = 4.19906, `position_z` = -0.09821, `orientation` = 3.35687, `VerifiedBuild` = 12340 WHERE `guid` = 83383 AND `id` = 18493;

DELETE FROM `waypoint_data` WHERE `id` IN (833790,1310650,833830,1310670);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(833790,1,69.16014,-5.811132,-0.10611479,0,0,0,0,100,0),
(833790,2,67.879486,-8.978183,-0.09812962,0,0,0,0,100,0),
(833790,3,67.83837,-26.447706,-0.07039746,0,0,0,0,100,0),
(833790,4,69.417725,-29.127998,-0.0746874,0,0,0,0,100,0),
(833790,5,72.57508,-29.682726,-0.073752105,0,0,0,0,100,0),
(833790,6,96.99448,-29.791718,-0.0515026,0,0,0,0,100,0),
(833790,7,99.8378,-28.062754,-0.03233916,0,0,0,0,100,0),
(833790,8,101.55477,-24.484463,-0.041662257,0,0,0,0,100,0),
(833790,9,101.79505,-9.136434,0.12334159,0,0,0,0,100,0),
(833790,10,101.28473,-5.818955,0.06241134,0,0,0,0,100,0),
(833790,11,98.46999,-4.272734,-0.06604118,0,0,0,0,100,0),
(833790,12,71.67794,-4.22718,-0.052884307,0,0,0,0,100,0),
(1310650,1,69.16014,-5.811132,-0.10611479,0,0,0,0,100,0),
(1310650,2,67.879486,-8.978183,-0.09812962,0,0,0,0,100,0),
(1310650,3,67.83837,-26.447706,-0.07039746,0,0,0,0,100,0),
(1310650,4,69.417725,-29.127998,-0.0746874,0,0,0,0,100,0),
(1310650,5,72.57508,-29.682726,-0.073752105,0,0,0,0,100,0),
(1310650,6,96.99448,-29.791718,-0.0515026,0,0,0,0,100,0),
(1310650,7,99.8378,-28.062754,-0.03233916,0,0,0,0,100,0),
(1310650,8,101.55477,-24.484463,-0.041662257,0,0,0,0,100,0),
(1310650,9,101.79505,-9.136434,0.12334159,0,0,0,0,100,0),
(1310650,10,101.28473,-5.818955,0.06241134,0,0,0,0,100,0),
(1310650,11,98.46999,-4.272734,-0.06604118,0,0,0,0,100,0),
(1310650,12,71.67794,-4.22718,-0.052884307,0,0,0,0,100,0),
(833830,1,68.77632,7.070634,-0.103508666,0,0,0,0,100,0),
(833830,2,68.612335,10.553121,-0.08794852,0,0,0,0,100,0),
(833830,3,68.61637,26.954746,-0.09732934,0,0,0,0,100,0),
(833830,4,69.2411,29.143032,-0.09685513,0,0,0,0,100,0),
(833830,5,71.53857,30.130527,-0.10705714,0,0,0,0,100,0),
(833830,6,97.67164,30.537062,-0.11079049,0,0,0,0,100,0),
(833830,7,100.70564,29.635519,-0.11454146,0,0,0,0,100,0),
(833830,8,101.51514,26.798935,-0.12312045,0,0,0,0,100,0),
(833830,9,101.2426,7.289032,0.19369555,0,0,0,0,100,0),
(833830,10,99.97599,4.770607,0.059734024,0,0,0,0,100,0),
(833830,11,97.24955,4.174426,-0.09839714,0,0,0,0,100,0),
(833830,12,71.15918,4.77888,-0.05281873,0,0,0,0,100,0),
(1310670,1,68.77632,7.070634,-0.103508666,0,0,0,0,100,0),
(1310670,2,68.612335,10.553121,-0.08794852,0,0,0,0,100,0),
(1310670,3,68.61637,26.954746,-0.09732934,0,0,0,0,100,0),
(1310670,4,69.2411,29.143032,-0.09685513,0,0,0,0,100,0),
(1310670,5,71.53857,30.130527,-0.10705714,0,0,0,0,100,0),
(1310670,6,97.67164,30.537062,-0.11079049,0,0,0,0,100,0),
(1310670,7,100.70564,29.635519,-0.11454146,0,0,0,0,100,0),
(1310670,8,101.51514,26.798935,-0.12312045,0,0,0,0,100,0),
(1310670,9,101.2426,7.289032,0.19369555,0,0,0,0,100,0),
(1310670,10,99.97599,4.770607,0.059734024,0,0,0,0,100,0),
(1310670,11,97.24955,4.174426,-0.09839714,0,0,0,0,100,0),
(1310670,12,71.15918,4.77888,-0.05281873,0,0,0,0,100,0);

UPDATE `creature` SET `position_x` = 238.860, `position_y` = -85.6609, `position_z` = 26.5912, `orientation` = 1.57850, `VerifiedBuild` = 12340 WHERE `guid` = 83372 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 238.921, `position_y` = -76.4597, `position_z` = 26.5912, `orientation` = 4.70458, `VerifiedBuild` = 12340 WHERE `guid` = 83391 AND `id` = 18497;
UPDATE `creature` SET `position_x` = 125.534, `position_y` = -163.073, `position_z` = 13.1498 WHERE `guid` = 83392 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 129.109, `position_y` = -159.577, `position_z` = 12.9073 WHERE `guid` = 83378 AND `id` = 18495;
UPDATE `creature` SET `position_x` = 129.029, `position_y` = -166.647, `position_z` = 12.9258 WHERE `guid` = 83385 AND `id` = 18493;

UPDATE `creature_formations` SET `dist` = 5, `angle` = 360 WHERE `leaderGUID` = 83372 AND `memberGUID` = 83391;
UPDATE `creature_formations` SET `dist` = 5 WHERE `leaderGUID` = 83392 AND `memberGUID` = 83378;
UPDATE `creature_formations` SET `dist` = 5 WHERE `leaderGUID` = 83392 AND `memberGUID` = 83385;
UPDATE `creature_formations` SET `angle` = 360 WHERE `leaderGUID` = 83386 AND `memberGUID` = 83406;

DELETE FROM `waypoint_data` WHERE `id` IN (833720,833920);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(833720,1,238.85509,-84.930984,26.591291,0,0,0,0,100,0),
(833720,2,239.11603,-118.809,26.59132,0,0,0,0,100,0),
(833920,1,122.65221,-163.04219,13.356737,0,0,0,0,100,0),
(833920,2,143.57632,-163.27176,12.563572,0,0,0,0,100,0),
(833920,3,166.70355,-163.66641,26.316568,0,0,0,0,100,0),
(833920,4,143.57632,-163.27176,12.563572,0,0,0,0,100,0),
(833920,5,122.65221,-163.04219,13.356737,0,0,0,0,100,0),
(833920,6,104.99422,-162.99231,14.774395,0,0,0,0,100,0),
(833920,7,81.24179,-163.2077,15.368842,0,0,0,0,100,0),
(833920,8,64.53549,-162.75394,15.386806,0,0,0,0,100,0),
(833920,9,48.272915,-162.58008,15.135821,0,0,0,0,100,0),
(833920,10,64.53549,-162.75394,15.386806,0,0,0,0,100,0),
(833920,11,81.24179,-163.2077,15.368842,0,0,0,0,100,0),
(833920,12,104.99422,-162.99231,14.774395,0,0,0,0,100,0);

-- Fix sheath, remove incorrect emote
UPDATE `creature_addon` SET `bytes2` = 1, `emote` = 0 WHERE `guid` IN (83387,83384,83381,83382,83376,83373,83369,83370,83371,83368,83367,83366,83357,83356,83351,83352,83354,83353,83355,83364,83360,83362,83361,83358,83359,83363,83365);
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (18371,18373,20318,20306);

-- Fix text type (Auchenai Necromancer)
UPDATE `creature_text` SET `Type` = 14 WHERE `CreatureID` = 18702;
