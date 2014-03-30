SET @CGUID              := 120649;
SET @HULKING_HORROR     := 31411;
SET @HULKING_HORROR1    := 31413;
SET @KRENDELL           := 31444;
SET @V_COMMANDO         := 31414;
SET @UPPER_CUT          := 10966;
SET @INF_BITE           := 49861;
SET @COSMETIC_EXP       := 46225;
SET @FLAME_PATCH        := 42344;
SET @FC_PITFALL         := 59398;
SET @AURA_FALL          := 59396;
SET @ASPELL             := 59073;
SET @HSPELL             := 59087;
SET @AREA               := 4522;

-- Setting new spawns to appropriate phase, and older spawns to their own appropriate phase also.
UPDATE `creature_template` SET `minlevel`=79, `maxlevel`=80, `exp`=2, `faction_A`=2043, `faction_H`=2043, `speed_run`=1.28968, `mindmg`=422, `maxdmg`=586, `attackpower`=642, `minrangedmg`=345, `maxrangedmg`=509, `rangedattackpower`=103 WHERE  `entry`=31413;
UPDATE `creature_template` SET AIName = 'SmartAI' WHERE entry IN (@HULKING_HORROR,@HULKING_HORROR1);
UPDATE `creature` SET `phaseMask` = 2 WHERE id IN (@KRENDELL,@V_COMMANDO,@HULKING_HORROR);
UPDATE `creature` SET `phaseMask` = 8 WHERE id = @HULKING_HORROR1;
UPDATE `gameobject` SET `phaseMask` = 10 WHERE id IN (193401,193400);
UPDATE `creature` SET `phaseMask` = 10 WHERE id IN (31641, 31644);

-- Phasing zone to both Alliance and Horde sides so they don't collide with the npc's there.
DELETE FROM `spell_area` WHERE `spell` IN (@HSPELL,@ASPELL) AND `area`=@AREA;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(@HSPELL,@AREA,13258,13282,0, 690,2,1,66,43), -- Horde version
(@ASPELL,@AREA,13386,13392,0,1101,2,1,66,43); -- Alliance version

-- Missing Hulking Horrors
DELETE FROM `creature` WHERE guid BETWEEN @CGUID AND @CGUID+22; 
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID, 31413, 571, 1, 8, 23681, 0, 5814.02, 1985.69, 503.881, 2.51188, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+1, 31413, 571, 1, 8, 23681, 0, 5816.86, 1943.29, 507.56, 3.40633, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+2, 31413, 571, 1, 8, 23681, 0, 5863.57, 1984, 507.648, 5.88321, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+3, 31413, 571, 1, 8, 23681, 0, 5778.56, 1957.5, 503.857, 3.27375, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+4, 31413, 571, 1, 8, 23681, 0, 5732.14, 1937.82, 506.014, 5.41257, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+5, 31413, 571, 1, 8, 23681, 0, 5706.3, 1977.47, 503.911, 4.05224, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+6, 31413, 571, 1, 8, 23681, 0, 5685.71, 1974.25, 503.863, 2.57831, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+7, 31413, 571, 1, 8, 23681, 0, 5673.84, 2094.37, 503.889, 5.52857, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+8, 31413, 571, 1, 8, 23681, 0, 5831.47, 2106.11, 503.89, 6.24962, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+9, 31413, 571, 1, 8, 23681, 0, 5826.33, 2149.32, 505.746, 2.48705, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+10, 31413, 571, 1, 8, 23681, 0, 5754.92, 2151.17, 503.91, 1.93734, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+11, 31413, 571, 1, 8, 23681, 0, 5775.43, 2193.86, 512.998, 0.776427, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+12, 31413, 571, 1, 8, 23681, 0, 5729.88, 2136.62, 503.894, 1.79434, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+13, 31413, 571, 1, 8, 23681, 0, 5782.62, 2140.68, 503.9, 0.783972, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+14, 31413, 571, 1, 8, 23681, 0, 5754.13, 2174.58, 506.181, 1.25723, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+15, 31413, 571, 1, 8, 23681, 0, 5650.03, 2055.57, 503.868, 0.939173, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+16, 31413, 571, 1, 8, 23681, 0, 5660.07, 2125.83, 505.943, 0.534949, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+17, 31413, 571, 1, 8, 23681, 0, 5700.89, 2148.91, 503.999, 5.77704, 300, 0, 0, 12175, 0, 0, 0, 0, 0),
(@CGUID+18, 31413, 571, 1, 8, 23681, 0, 5651.27, 2007.15, 504.97, 1.98891, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+19, 31413, 571, 1, 8, 23681, 0, 5858.93, 2108.63, 505.124, 2.30257, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+20, 31413, 571, 1, 8, 23681, 0, 5688.14, 2001.98, 503.924, 0.151243, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+21, 31413, 571, 1, 8, 23681, 0, 5845.64, 2080.43, 503.97, 2.90496, 300, 5, 0, 12175, 0, 1, 0, 0, 0),
(@CGUID+22, 31413, 571, 1, 8, 23681, 0, 5876.8, 2037.78, 506.147, 0.498635, 300, 0, 0, 12175, 0, 0, 0, 0, 0);

-- Conditions for Aura fall
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 and `SourceEntry` = @AURA_FALL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, @AURA_FALL, 0, 0, 31, 0, 3, 31641, 0, 0, 0, 0, '', 'Aura fall hits only pitfall npc');

-- Saronite bomb should blow-up the player into the pit
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=193400;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=193400;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(193400, 1, 0, 0, 19, 0, 100, 0, 13389, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 123287, 31644, 0, 0, 0, 0, 0, 'Saronite Bomb Stack - On quest accept - Set Data'),
(193400, 1, 1, 0, 19, 0, 100, 0, 13263, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 123287, 31644, 0, 0, 0, 0, 0, 'Saronite Bomb Stack - On quest accept - Set Data');

-- Cosmetic Explosion bunny
UPDATE `creature_template` SET AIName = 'SmartAI' WHERE entry = 31644;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31644 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31644, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 11, @COSMETIC_EXP, 2, 0, 0, 0, 0, 9, 31644, 20, 40, 0, 0, 0, 0, 'Cosmetic Trigger - On Data set - Cosmetic Explosion'),
(31644, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, @FLAME_PATCH, 2, 0, 0, 0, 0, 9, 31644, 20, 40, 0, 0, 0, 0, 'Cosmetic Trigger - On Link - Cast flame patch on npc''s'),
(31644, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 31641, 1, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Saronite Bomb Stack - On Link - Summon Pitfall bunny');

-- "Fall" vehicle bunny
UPDATE `creature_template` SET AIName = 'SmartAI', `speed_walk`=20.1429, `speed_run`=20.1429 WHERE entry = 31641; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=31641 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31641, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, @FC_PITFALL, 2, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Pitfall bunny - On respawn - Cast FC pitfall'),
(31641, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5756.644, 2050.579, 480.6346, 0, 'Pitfall bunny - On Link - Go to PoS');

-- Hulking Horror phase 2
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HULKING_HORROR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HULKING_HORROR,0,0,0,0,0,100,0,8000,16000,24000,32000,11,@INF_BITE,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hulking Horror - In Combat - Cast Infected Bite'),
(@HULKING_HORROR,0,1,0,0,0,100,0,4000,9000,14000,19000,11,@UPPER_CUT,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hulking Horror - In Combat - Cast Uppercut'),
(@HULKING_HORROR,0,2,0,6,0,100,0,0,0,0,0,33,31413,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hulking Horror - On Death - Killcredit');

-- Hulking Horrors phase 8
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HULKING_HORROR1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HULKING_HORROR1,0,0,0,0,0,100,0,8000,16000,24000,32000,11,@INF_BITE,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hulking Horror - In Combat - Cast Infected Bite'),
(@HULKING_HORROR1,0,1,0,0,0,100,0,4000,9000,14000,19000,11,@UPPER_CUT,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hulking Horror - In Combat - Cast Uppercut');
