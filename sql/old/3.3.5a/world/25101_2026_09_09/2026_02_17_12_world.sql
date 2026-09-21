--
SET @CGUID := 147418; -- 33

-- Lady Vashj position correction
UPDATE `creature` SET `position_x` = 29.99015235900878906, `position_y` = -922.40875244140625, `position_z` = 42.9852142333984375, `orientation` = 1.396263360977172851, `VerifiedBuild` = 15595 WHERE `id` = 21212;

-- Remove wrong spawns around Lady Vashj
DELETE FROM `creature` WHERE `guid` IN (93900,93901,93902,93903,93904,93905,93906,93907,93908,93909) AND `id` = 21221;

-- Add missing triggers
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+32;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
-- These aren't for Vashj
(@CGUID+00, 15384, 548, 0, 0, 1, 1, 0, 0, 386.298858642578125, -433.73028564453125, 29.61212921142578125, 4.084070205688476562, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+01, 15384, 548, 0, 0, 1, 1, 0, 0, 451.8170166015625, -539.2855224609375, -7.46342134475708007, 6.038839340209960937, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
-- These are for Vashj
(@CGUID+02, 15384, 548, 0, 0, 1, 1, 0, 0, 43.32907867431640625, -869.731201171875, 41.1803436279296875, 4.433136463165283203, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerWaveA1', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 38018 Wave A - 1)
(@CGUID+03, 15384, 548, 0, 0, 1, 1, 0, 0, 78.38092803955078125, -950.6593017578125, 41.18033981323242187, 2.617993831634521484, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerWaveA2', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 38036 Wave A - 2)
(@CGUID+04, 15384, 548, 0, 0, 1, 1, 0, 0, 13.78061676025390625, -975.63262939453125, 41.1803436279296875, 1.29154360294342041, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerWaveA3', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 38040 Wave A - 3)
(@CGUID+05, 15384, 548, 0, 0, 1, 1, 0, 0, -22.5974483489990234, -900.3819580078125, 41.18033981323242187, 5.8817596435546875, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerWaveA4', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 38041 Wave A - 4)
(@CGUID+06, 15384, 548, 0, 0, 1, 1, 0, 0, 64.33573150634765625, -841.26007080078125, 22.7373199462890625, 0.01745329238474369, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+07, 15384, 548, 0, 0, 1, 1, 0, 0, -2.90953707695007324, -840.20587158203125, 22.73732376098632812, 5.009094715118408203, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+08, 15384, 548, 0, 0, 1, 1, 0, 0, 40.87694549560546875, -834.8643798828125, 22.7373199462890625, 3.874630928039550781, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+09, 15384, 548, 0, 0, 1, 1, 0, 0, 17.07788658142089843, -835.12384033203125, 22.7373199462890625, 4.433136463165283203, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+10, 15384, 548, 0, 0, 1, 1, 0, 0, 84.74283599853515625, -853.50836181640625, 22.7373199462890625, 1.466076612472534179, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+11, 15384, 548, 0, 0, 1, 1, 0, 0, 105.0671768188476562, -872.94097900390625, 22.73732185363769531, 6.230825424194335937, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+12, 15384, 548, 0, 0, 1, 1, 0, 0, -50.9142837524414062, -880.622314453125, 22.7373199462890625, 5.811946392059326171, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+13, 15384, 548, 0, 0, 1, 1, 0, 0, -57.8599510192871093, -905.55267333984375, 22.7373199462890625, 6.091198921203613281, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+14, 15384, 548, 0, 0, 1, 1, 0, 0, -61.11981201171875, -928.76397705078125, 22.7373199462890625, 0.069813169538974761, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+15, 15384, 548, 0, 0, 1, 1, 0, 0, -41.931060791015625, -977.385986328125, 22.7373199462890625, 6.126105785369873046, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+16, 15384, 548, 0, 0, 1, 1, 0, 0, 118.0983428955078125, -938.05023193359375, 22.7373199462890625, 2.844886541366577148, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+17, 15384, 548, 0, 0, 1, 1, 0, 0, -23.5065479278564453, -995.796875, 22.7373199462890625, 4.415682792663574218, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+18, 15384, 548, 0, 0, 1, 1, 0, 0, -4.1270599365234375, -1006.3209228515625, 22.73732185363769531, 5.515240192413330078, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+19, 15384, 548, 0, 0, 1, 1, 0, 0, 19.43007850646972656, -1012.5313720703125, 22.7373199462890625, 0.767944872379302978, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+20, 15384, 548, 0, 0, 1, 1, 0, 0, 66.27529144287109375, -1005.50518798828125, 22.7373199462890625, 1.832595705986022949, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+21, 15384, 548, 0, 0, 1, 1, 0, 0, 45.04018783569335937, -1011.1707763671875, 22.7373199462890625, 1.308996915817260742, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+22, 15384, 548, 0, 0, 1, 1, 0, 0, 85.019439697265625, -993.2745361328125, 22.7373199462890625, 6.161012172698974609, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+23, 15384, 548, 0, 0, 1, 1, 0, 0, 101.5224990844726562, -977.1925048828125, 22.73732185363769531, 2.268928050994873046, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+24, 15384, 548, 0, 0, 1, 1, 0, 0, 112.8540496826171875, -957.346923828125, 22.7373199462890625, 2.58308720588684082, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', 'LadyVashjTriggerBottom', 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+25, 15384, 548, 0, 0, 1, 1, 0, 0, 30.20100021362304687, -923.11102294921875, 72.98523712158203125, 3.141592741012573242, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+26, 15384, 548, 0, 0, 1, 1, 0, 0, 29.74659156799316406, -923.37371826171875, 42.9852142333984375, 3.089232683181762695, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+27, 15384, 548, 0, 0, 1, 1, 0, 0, 29.63411140441894531, -923.54058837890625, 42.9852142333984375, 2.39110112190246582, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject1
-- This one is spawned in the middle when phase 2 starts
(@CGUID+28, 15384, 548, 0, 0, 1, 1, 0, 0, 29.87589836120605468, -923.3916015625, 42.9852142333984375, 3.996803998947143554, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 15384 (Area: 0 - Difficulty: 0) CreateObject2
-- World Trigger (Tiny) (for generators)
(@CGUID+29, 21987, 548, 0, 0, 1, 1, 0, 0, 8.955979347229003906, -903.07257080078125, 46.11309814453125, 5.567600250244140625, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 21987 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+30, 21987, 548, 0, 0, 1, 1, 0, 0, 49.85210418701171875, -902.9232177734375, 46.11993408203125, 3.909537553787231445, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 21987 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+31, 21987, 548, 0, 0, 1, 1, 0, 0, 50.27483749389648437, -944.10870361328125, 46.11315536499023437, 2.356194496154785156, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595), -- 21987 (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+32, 21987, 548, 0, 0, 1, 1, 0, 0, 8.991875648498535156, -944.3671875, 46.10596466064453125, 0.78539818525314331, 300, 0, 0, 0, 0, 0, 0, 0, 0, '', NULL, 15595); -- 21987 (Area: 0 - Difficulty: 0) CreateObject1

-- Re-add texts
DELETE FROM `creature_text` WHERE `CreatureID` = 21212;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21212,0,0,"Water... is life. It has become a rare commodity here in Outland; a commodity that we alone shall control. We are the Highborne, and the time has come at last for us to retake our rightful place in the world!",14,0,100,0,0,11531,20085,0,"vashj SAY_INTRO"),
(21212,1,0,"I'll split you from stem to stern!",14,0,100,0,0,11532,20088,0,"vashj SAY_AGGRO_1"),
(21212,1,1,"Victory to Lord Illidan! ",14,0,100,0,0,11533,20089,0,"vashj SAY_AGGRO_2"),
(21212,1,2,"I spit on you, surface filth!",14,0,100,0,0,11534,20091,0,"vashj SAY_AGGRO_3"),
(21212,1,3,"Death to the outsiders!",14,0,100,0,0,11535,20090,0,"vashj SAY_AGGRO_4"),
(21212,1,4,"I did not wish to lower myself by engaging your kind, but you leave me little choice...",14,0,100,0,0,11538,19679,0,"vashj SAY_AGGRO_5"),
(21212,2,0,"Straight to the heart!",14,0,100,0,0,11536,20086,0,"vashj SAY_BOWSHOT_1"),
(21212,2,1,"Seek your mark!",14,0,100,0,0,11537,20087,0,"vashj SAY_BOWSHOT_2"),
(21212,3,0,"The time is now! Leave none standing! ",14,0,100,0,0,11539,20092,0,"vashj SAY_PHASE_2"),
(21212,4,0,"You may want to take cover. ",14,0,100,0,0,11540,20210,0,"vashj SAY_PHASE_3"),
(21212,5,0,"Your time ends now!",14,0,100,0,0,11541,20093,0,"vashj SAY_SLAY_1"),
(21212,5,1,"You have failed!",14,0,100,0,0,11542,20094,0,"vashj SAY_SLAY_2"),
(21212,5,2,"Be'lemer an-delei!",14,0,100,0,0,11543,20095,0,"vashj SAY_SLAY_3"),
(21212,6,0,"Lord Illidan, I... I am... sorry.",14,0,100,0,0,11544,20096,0,"vashj SAY_DEATH");

-- World Trigger (Tiny)
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 21987;

-- Invis KV Shield Generator (no longer needed, wrong entry used)
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 19870;

-- Enchanted Elemental
UPDATE `creature_template` SET `speed_run` = 2.14285714286, `unit_flags` = 32768 WHERE `entry` = 21958;

-- Tainted Elemental
UPDATE `creature_template` SET `speed_run` = 1.28968279702, `unit_flags` = 32768 WHERE `entry` = 22009;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 22009;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(22009,1,1,0,1,0,0,NULL);

-- Coilfang Elite
UPDATE `creature_template` SET `speed_run` = 1.42857142857, `BaseAttackTime` = 2500, `unit_flags` = 32768 WHERE `entry` = 22055;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22055 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22055,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Elite - On AI Initialize - Set Corpse Delay"),
(22055,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Elite - On Spawn - Set In Combat With Zone"),
(22055,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,38260,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilfang Elite - In Combat - Cast 'Cleave'"),
(22055,0,3,0,0,0,100,0,15000,25000,15000,25000,0,11,38262,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilfang Elite - In Combat - Cast 'Hamstring'");

-- Coilfang Strider
UPDATE `creature_template` SET `speed_run` = 1, `BaseAttackTime` = 3000, `unit_flags` = 32768 WHERE `entry` = 22056;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22056 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22056,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Strider - On AI Initialize - Set Corpse Delay"),
(22056,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Strider - On Spawn - Set In Combat With Zone"),
(22056,0,2,0,11,0,100,0,0,0,0,0,0,11,38257,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Strider - On Spawn - Cast 'Panic Periodic'"),
(22056,0,3,0,0,0,100,0,10000,20000,10000,20000,0,11,38259,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilfang Strider - In Combat - Cast 'Mind Blast'");

-- Toxic Sporebat
UPDATE `creature_template` SET `speed_run` = 1.42857142857 WHERE `entry` = 22140;

DELETE FROM `spell_target_position` WHERE `ID` IN (38489,38492,38493);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(38489,0,548,136.463,-720.768,128.184,0,0),
(38492,0,548,-15.5374,-710.768,210.184,0,0),
(38493,0,548,-117.537,-740.768,128.184,0,0);

DELETE FROM `waypoint_data` WHERE `id` IN (17712002,17712010,17712018,17712026,17712034,17712042);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(17712002,1,136.4626,-720.7682,128.1843,NULL,0,1,0,100,0),
(17712002,2,83,-745,111.0833,NULL,0,1,0,100,0),
(17712002,3,29.53741,-769.2318,93.98236,NULL,0,1,0,100,0),
(17712002,4,29.66577,-812.2854,83.60573,NULL,0,1,0,100,0),
(17712002,5,29.81689,-859.7213,77.46452,NULL,0,1,0,100,0),
(17712002,6,29.7356,-896.5361,74.51001,NULL,0,1,0,100,0),
(17712002,7,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),
(17712002,8,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),

(17712010,1,-15.53741,-710.7682,210.1843,NULL,0,1,0,100,0),
(17712010,2,7,-740,152.0833,NULL,0,1,0,100,0),
(17712010,3,29.53741,-769.2318,93.98236,NULL,0,1,0,100,0),
(17712010,4,29.66577,-812.2854,83.60573,NULL,0,1,0,100,0),
(17712010,5,29.81689,-859.7213,77.46452,NULL,0,1,0,100,0),
(17712010,6,29.7356,-896.5361,74.51001,NULL,0,1,0,100,0),
(17712010,7,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),
(17712010,8,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),

(17712018,1,-117.5374,-740.7682,128.1843,NULL,0,1,0,100,0),
(17712018,2,-44,-755,111.0833,NULL,0,1,0,100,0),
(17712018,3,29.53741,-769.2318,93.98236,NULL,0,1,0,100,0),
(17712018,4,29.66577,-812.2854,83.60573,NULL,0,1,0,100,0),
(17712018,5,29.81689,-859.7213,77.46452,NULL,0,1,0,100,0),
(17712018,6,29.7356,-896.5361,74.51001,NULL,0,1,0,100,0),
(17712018,7,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),
(17712018,8,29.98181,-923.3133,72.92973,NULL,0,1,0,100,0),

(17712026,1,25.47625,-936.2615,71.9574,NULL,0,1,0,100,0),
(17712026,2,15.45654,-949.6531,71.5687,NULL,0,1,0,100,0),
(17712026,3,8.161252,-965.6783,71.1796,NULL,0,1,0,100,0),
(17712026,4,17.82873,-974.5029,72.51304,NULL,0,1,0,100,0),
(17712026,5,34.81367,-975.9124,72.67962,NULL,0,1,0,100,0),
(17712026,6,45.80273,-968.9988,73.12431,NULL,0,1,0,100,0),
(17712026,7,45.2906,-952.1388,73.90191,NULL,0,1,0,100,0),
(17712026,8,36.59396,-935.5475,73.51308,NULL,0,1,0,100,0),
(17712026,9,16.22989,-899.4479,72.70769,NULL,0,1,0,100,0),
(17712026,10,11.76118,-876.7528,72.73535,NULL,0,1,0,100,0),
(17712026,11,30.87306,-871.5264,73.34637,NULL,0,1,0,100,0),
(17712026,12,47.49812,-881.7419,73.42989,NULL,0,1,0,100,0),
(17712026,13,45.51097,-898.2436,73.7632,NULL,0,1,0,100,0),
(17712026,14,28.62512,-922.871,72.81866,NULL,0,1,0,100,0),
(17712026,15,4.218264,-937.9555,73.51319,NULL,0,1,0,100,0),
(17712026,16,-12.31643,-942.0379,73.51309,NULL,0,1,0,100,0),
(17712026,17,-21.58506,-926.1245,73.54079,NULL,0,1,0,100,0),
(17712026,18,-15.85825,-912.1876,73.48534,NULL,0,1,0,100,0),
(17712026,19,3.496831,-911.0197,73.84637,NULL,0,1,0,100,0),
(17712026,20,46.598,-929.6895,72.73541,NULL,0,1,0,100,0),
(17712026,21,64.3203,-936.5674,73.09652,NULL,0,1,0,100,0),
(17712026,22,70.36785,-915.422,73.37437,NULL,0,1,0,100,0),
(17712026,23,66.17116,-900.9865,73.51308,NULL,0,1,0,100,0),
(17712026,24,48.37246,-911.2575,73.20755,NULL,0,1,0,100,0),
(17712026,25,29.77706,-923.674,72.92975,NULL,0,1,0,100,0),

(17712034,1,29.74228,-936.5851,71.90195,NULL,0,1,0,100,0),
(17712034,2,26.64374,-952.3989,72.34639,NULL,0,1,0,100,0),
(17712034,3,12.96121,-962.2808,72.45748,NULL,0,1,0,100,0),
(17712034,4,-4.278461,-962.5538,72.81861,NULL,0,1,0,100,0),
(17712034,5,-17.11593,-951.7313,72.84619,NULL,0,1,0,100,0),
(17712034,6,-9.633209,-930.9573,71.87432,NULL,0,1,0,100,0),
(17712034,7,9.306218,-924.4479,71.34638,NULL,0,1,0,100,0),
(17712034,8,33.0076,-920.3102,71.09634,NULL,0,1,0,100,0),
(17712034,9,62.98852,-921.3867,70.37418,NULL,0,1,0,100,0),
(17712034,10,77.16732,-937.0809,70.15195,NULL,0,1,0,100,0),
(17712034,11,70.85632,-955.9498,71.15201,NULL,0,1,0,100,0),
(17712034,12,53.4311,-965.3745,71.73532,NULL,0,1,0,100,0),
(17712034,13,40.6101,-955.7776,70.9575,NULL,0,1,0,100,0),
(17712034,14,35.72985,-936.0399,71.0965,NULL,0,1,0,100,0),
(17712034,15,36.97565,-904.8439,70.62417,NULL,0,1,0,100,0),
(17712034,16,44.32596,-881.2806,70.34651,NULL,0,1,0,100,0),
(17712034,17,67.28079,-875.0112,69.7353,NULL,0,1,0,100,0),
(17712034,18,73.3915,-890.5972,70.06871,NULL,0,1,0,100,0),
(17712034,19,66.65175,-911.3412,69.87421,NULL,0,1,0,100,0),
(17712034,20,27.79452,-915.5251,70.81865,NULL,0,1,0,100,0),
(17712034,21,-0.289989,-916.8209,71.7631,NULL,0,1,0,100,0),
(17712034,22,-16.29699,-905.9411,71.59646,NULL,0,1,0,100,0),
(17712034,23,-9.997787,-885.5416,71.40202,NULL,0,1,0,100,0),
(17712034,24,6.849291,-875.9566,71.34644,NULL,0,1,0,100,0),
(17712034,25,23.93834,-890.9107,71.3187,NULL,0,1,0,100,0),
(17712034,26,27.79953,-909.5942,72.09645,NULL,0,1,0,100,0),
(17712034,27,29.95652,-923.1678,72.37416,NULL,0,1,0,100,0),

(17712042,1,29.45853,-936.4966,73.23524,NULL,0,1,0,100,0),
(17712042,2,26.71206,-959.2283,73.6519,NULL,0,1,0,100,0),
(17712042,3,29.39069,-970.7122,74.01311,NULL,0,1,0,100,0),
(17712042,4,38.77345,-973.7094,73.87413,NULL,0,1,0,100,0),
(17712042,5,45.24231,-968.9174,73.2631,NULL,0,1,0,100,0),
(17712042,6,44.26018,-957.8735,72.48531,NULL,0,1,0,100,0),
(17712042,7,44.43358,-931.1404,72.12431,NULL,0,1,0,100,0),
(17712042,8,45.27556,-902.4111,71.98534,NULL,0,1,0,100,0),
(17712042,9,45.50093,-881.9935,71.31866,NULL,0,1,0,100,0),
(17712042,10,39.50764,-871.8448,71.3186,NULL,0,1,0,100,0),
(17712042,11,27.84665,-872.999,70.92975,NULL,0,1,0,100,0),
(17712042,12,18.04644,-883.7643,71.48533,NULL,0,1,0,100,0),
(17712042,13,16.29116,-911.5618,71.7075,NULL,0,1,0,100,0),
(17712042,14,16.31265,-951.5267,73.54084,NULL,0,1,0,100,0),
(17712042,15,18.15802,-968.5851,73.81873,NULL,0,1,0,100,0),
(17712042,16,29.5142,-973.9502,74.06866,NULL,0,1,0,100,0),
(17712042,17,48.45092,-969.284,74.29092,NULL,0,1,0,100,0),
(17712042,18,59.579,-953.452,74.70754,NULL,0,1,0,100,0),
(17712042,19,59.79919,-933.6411,74.81863,NULL,0,1,0,100,0),
(17712042,20,59.27669,-895.5518,74.01316,NULL,0,1,0,100,0),
(17712042,21,54.24306,-878.1003,74.04095,NULL,0,1,0,100,0),
(17712042,22,30.02266,-870.9995,73.45751,NULL,0,1,0,100,0),
(17712042,23,4.311263,-882.5199,73.04079,NULL,0,1,0,100,0),
(17712042,24,0.506299,-910.079,73.59657,NULL,0,1,0,100,0),
(17712042,25,0.856385,-954.4567,73.48524,NULL,0,1,0,100,0),
(17712042,26,16.84269,-972.4671,72.84637,NULL,0,1,0,100,0),
(17712042,27,55.6355,-969.2434,73.76298,NULL,0,1,0,100,0),
(17712042,28,67.59154,-953.4158,74.09639,NULL,0,1,0,100,0),
(17712042,29,62.93051,-929.8393,73.90189,NULL,0,1,0,100,0),
(17712042,30,27.80816,-924.29,73.15201,NULL,0,1,0,100,0),
(17712042,31,-7.699038,-923.7242,72.87411,NULL,0,1,0,100,0),
(17712042,32,-12.34698,-896.8848,73.06863,NULL,0,1,0,100,0),
(17712042,33,8.823698,-881.1996,72.81866,NULL,0,1,0,100,0),
(17712042,34,31.40876,-882.2166,70.92974,NULL,0,1,0,100,0),
(17712042,35,29.60361,-923.2789,73.23524,NULL,0,1,0,100,0);

-- Spore Drop Trigger
UPDATE `creature_template` SET `unit_flags` = 33554944, `AIName` = 'SmartAI' WHERE `entry` = 22207;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22207 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22207,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spore Drop Trigger - On AI Initialize - Set Reactstate Passive"),
(22207,0,1,0,11,0,100,0,0,0,0,0,0,11,38575,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spore Drop Trigger - On Spawn - Cast 'Toxic Spores'");

-- Lady Vashj
UPDATE `creature_template` SET `speed_run` = 2.14285714286 WHERE `entry` = 21212;

-- Shield Generators
UPDATE `gameobject_template` SET `ScriptName` = 'go_shield_generator' WHERE `entry` IN (185051,185052,185053,185054);
UPDATE `gameobject_template_addon` SET `flags` = 48 WHERE `entry` IN (185051,185052,185053,185054);

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_lady_vashj_summon_wave_mob_trigger',
'spell_lady_vashj_summon_wave_e_mob_trigger',
'spell_lady_vashj_spore_drop_effect',
'spell_lady_vashj_remove_tainted_cores',
'spell_lady_vashj_remove_tainted_cores_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38017, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38037, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38038, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38039, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38248, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38241, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38140, 'spell_lady_vashj_summon_wave_mob_trigger'),
(38494, 'spell_lady_vashj_summon_wave_e_mob_trigger'),
(38573, 'spell_lady_vashj_spore_drop_effect'),
(39495, 'spell_lady_vashj_remove_tainted_cores'),
(39496, 'spell_lady_vashj_remove_tainted_cores_effect');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (38017,38037,38038,38039,38248,38241,38140);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,38017,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Wave A - 1' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38037,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Wave A - 2' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38038,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Wave A - 3' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38039,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Wave A - 4' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38248,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Summon Wave B Mob Trigger' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38241,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Summon Wave C Mob Trigger' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'"),
(13,1,38140,0,0,58,0,0,0,0,"LadyVashjTriggerBottom",0,0,0,"","Group 0: Spell 'Summon Wave D Mob Trigger' (Effect 0) targets creature 'OLDWorld Trigger (DO NOT DELETE)'");

-- In sniffs creatures are summoned at caster's position, not at random position
UPDATE `spell_dbc` SET `EffectImplicitTargetA1`=18,`EffectRadiusIndex1`=0 WHERE `Id` IN (38019,38247,38242,38244);
