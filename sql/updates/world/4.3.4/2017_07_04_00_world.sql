-- Partial Redridge fixup

-- Spawn missing npc's in redridge
SET @GUID := 251517;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID+0, 43184, 0, 0, 0, 1, 1, 169, 0, 0, -9201.863, -2154.75, 57.18658, 4.593081, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+1, 43248, 0, 0, 0, 1, 1, 169, 0, 0, -9202.206, -2157.61, 57.18667, 1.451431, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+2, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9203.75, -2150.61, 57.26973, 5.096361, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+3, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9200, -2150.34, 57.26853, 4.834562, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+4, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9204.75, -2149.66, 57.26983, 5.131268, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+5, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9201.87, -2150.28, 57.26913, 4.921828, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+6, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9205.21, -2150.85, 57.26993, 5.113815, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+7, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9206.5, -2151.86, 57.26993, 5.846853, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+8, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9202.89, -2149.51, 57.26933, 5.061455, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+9, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9195.01, -2155.74, 57.26893, 2.897247, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+10, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9196.25, -2153.44, 57.26843, 3.263766, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+11, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9195.93, -2155.27, 57.26873, 3.316126, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+12, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9194.31, -2158.86, 57.26953, 2.408554, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+13, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9195.53, -2159.08, 57.26923, 3.228859, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+14, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9193.6, -2154.45, 57.26863, 3.089233, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+15, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9195.24, -2157.47, 57.26923, 3.281219, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+16, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9193.85, -2152.98, 57.26853, 3.944444, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+17, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9195.26, -2153.86, 57.26853, 3.385939, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+18, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9196.57, -2152.05, 57.26813, 3.804818, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+19, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9196.33, -2157.53, 57.26903, 3.141593, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+20, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9197.05, -2160.39, 57.26943, 2.635447, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+21, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9199.6, -2148.51, 57.26803, 4.206244, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+22, 43222, 0, 0, 0, 1, 1, 169, 0, 0, -9194.87, -2151.31, 57.26823, 3.874631, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+23, 382, 0, 0, 0, 1, 1, 169, 0, 0, -9276.96, -2242.86, 64.17783, 1.134464, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+24, 43194, 0, 0, 0, 1, 1, 169, 0, 0, -9277.43, -2240.89, 64.11594, 5.061455, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+25, 43184, 0, 0, 0, 1, 1, 169, 0, 0, -9201.46,-2155.63, 57.26993, 0.4014257, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+26, 43248, 0, 0, 0, 1, 1, 169, 0, 0, -9202, -2155.81, 57.26993, 1.53589, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+27, 43432, 0, 0, 0, 1, 1, 169, 0, 0, -9200.94, -2157.94, 57.26933, 2.146755, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+28, 43433, 0, 0, 0, 1, 1, 169, 0, 0, -9201.71, -2153.14, 57.26943, 4.660029, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+29, 43434, 0, 0, 0, 1, 1, 169, 0, 0, -9200.21, -2153.62, 57.26903, 4.049164, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015),
(@GUID+30, 43435, 0, 0, 0, 1, 1, 169, 0, 0, -9199.89, -2156.77, 57.26913, 2.740167, 120, 0, 0, 1, 0, 0, 0, 0, 0, 24015);
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @GUID+0 AND @GUID+30;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID+0,0,0,65536,257,0, '80816'),(@GUID+1,0,0,65536,257,0, '80816'),(@GUID+2,0,0,65536,257,0, '80816'),
(@GUID+3,0,0,65536,257,0, '80816'),(@GUID+4,0,0,65536,257,0, '80816'),(@GUID+5,0,0,65536,257,0, '80816'),
(@GUID+6,0,0,65536,257,0, '80816'),(@GUID+7,0,0,65536,257,0, '80816'),(@GUID+8,0,0,65536,257,0, '80816'),
(@GUID+9,0,0,65536,257,0, '80816'),(@GUID+10,0,0,65536,257,0, '80816'),(@GUID+11,0,0,65536,257,0, '80816'),
(@GUID+12,0,0,65536,257,0, '80816'),(@GUID+13,0,0,65536,257,0, '80816'),(@GUID+14,0,0,65536,257,0, '80816'),
(@GUID+15,0,0,65536,257,0, '80816'),(@GUID+16,0,0,65536,257,0, '80816'),(@GUID+17,0,0,65536,257,0, '80816'),
(@GUID+18,0,0,65536,257,0, '80816'),(@GUID+19,0,0,65536,257,0, '80816'),(@GUID+20,0,0,65536,257,0, '80816'),
(@GUID+21,0,0,65536,257,0, '80816'),(@GUID+22,0,0,65536,257,0, '80816'),(@GUID+23,0,0,65536,1,0, '80699'),
(@GUID+24,0,0,65536,1,0, '80699'),(@GUID+25,0,0,65536,1,0, '81201'),(@GUID+26,0,0,65543,1,0, '81201'),
(@GUID+27,0,0,65536,1,0, '81201'),(@GUID+28,0,0,65536,1,0, '81201'),(@GUID+29,0,0,65536,1,0, '81201'),
(@GUID+30,0,0,65536,1,0, '81201');

DELETE FROM `creature` WHERE `guid` IN (335060,334938);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(335060, 4064, 0, 0, 0, 1, 169, 0, 0, 0, -9168.14, -2823.74, 94.15073, 5.061455, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23420),
(334938, 437, 0, 0, 0, 1, 169, 0, 0, 0, -9147.99, -2920.22, 93.51772, 1.155607, 120, 0, 0, 1, 0, 2, 0, 0, 0, 23420);
DELETE FROM `creature_addon` WHERE `guid`=335060;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (335060,0,0,0,1,333, '');

-- Remove overspawns and add missing rares "Still Missing http://www.wowhead.com/npc=947/rohh-the-silent will add in future."
DELETE FROM `creature` WHERE `guid` IN (334864,334700,334597,334726);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(334864, 14272, 0, 0, 0, 1, 1, 169, 0, 0, -9553.5, -2388.502, 99.86586, 5.044002, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- Snarlflare
(334700, 616, 0, 0, 0, 1, 1, 169, 0, 0, -9101.009, -2454.14, 120.4729, 5.413383, 3600, 6, 0, 0, 0, 1, 0, 0, 0, 24015), -- Chatter
(334597, 14270, 0, 0, 0, 1, 1, 169, 0, 0, -9236.906, -2448.561, 57.06998, 4.921828, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- Squiddic
(334726, 14271, 0, 0, 0, 1, 1, 169, 0, 0, -9562.991, -2253.339, 85.65274, 5.462881, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 24015); -- Ribchaser
-- Rare fixups
UPDATE `creature` SET`spawntimesecs`=3600 WHERE `id` IN (14269,52146,14273,584);
UPDATE `creature_template` SET `ExperienceModifier`=7.5 WHERE `entry` IN (14269,52146,14273,584,616,14270,14271,947);
UPDATE `creature` SET `spawndist`=15,`MovementType`=1,`position_x`=-9653.848,`position_y`=-3112.19,`position_z`=48.65988 WHERE `guid`=335295;

-- Detect Quest Invis Zone 1
DELETE FROM `spell_area` WHERE `spell` IN (80695);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80695,44,0,26520,0,2098253,2,1,0,11); -- Zone Wide
-- Detect Quest Invis Zone 2
DELETE FROM `spell_area` WHERE `spell` IN (80696);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80696,44,26520,0,0,2098253,2,1,64,0); -- Zone Wide
-- Detect: Quest Invis Zone 3
DELETE FROM `spell_area` WHERE `spell` IN (80817);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80817,69,0,26567,0,2098253,2,1,0,1); -- Lakeshire
-- Detect: Quest Invis Zone 4
DELETE FROM `spell_area` WHERE `spell` IN (80818);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80818,69,26567,26607,0,2098253,2,1,74,1); -- Lakeshire
-- Detect: Quest Invis Zone 9
DELETE FROM `spell_area` WHERE `spell` IN (81202);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(81202,69,26607,26616,0,2098253,2,1,74,1); -- Lakeshire
-- Gnomecorder
DELETE FROM `spell_area` WHERE `spell` IN (80689);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80689,44,26512,26616,0,2098253,2,1,74,1); -- Zone Wide

-- Detect: Quest Invis Zone 19
DELETE FROM `spell_area` WHERE `spell` IN (82100);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(82100,69,0,26616,0,2098253,2,1,0,1); -- Lakeshire "Not sure when or if it stops will update in future."

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (428);

DELETE FROM `creature_template_addon` WHERE `entry` IN (341,43196);
DELETE FROM `creature_template_addon` WHERE `entry` BETWEEN 648 AND 653;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`auras`) VALUES
(341,0,0,65543,1,0,0, '80694'),(648,0,0,65536,1,0,726, '80698'),(649,0,0,65536,1,0,726, '80698'),(650,0,0,65536,1,0,726, '80698'),
(651,0,0,65536,1,0,726, '80698'),(652,0,0,65536,1,0,726, '80698'),(653,0,0,65536,1,0,726, '80698'),(43196,0,0,65536,1,0,0, '80694');

UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `guid`=334727;

-- Vernon Hale Entry: 1678
UPDATE `creature` SET `spawndist`=2,`MovementType`=1,`position_x`=-9267.604,`position_y`=-2167.748,`position_z`=63.06792 WHERE `guid`=334821;

DELETE FROM `creature_template_addon` WHERE `entry`=43533;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (43533,0,25831,0,1,0, '');

-- Pathing for Redridge Fox Entry: 43083
SET @NPC := 335043;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9704.2,`position_y`=-2516.38,`position_z`=61.4835 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-9704.2,`position_y`=-2516.38,`position_z`=61.4835 WHERE `guid`=335044;
UPDATE `creature` SET `position_x`=-9704.2,`position_y`=-2516.38,`position_z`=61.4835 WHERE `guid`=335045;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9704.2,-2516.38,61.4835,0,0,0,0,100,0),
(@PATH,2,-9705.95,-2548.23,60.95052,0,0,0,0,100,0),
(@PATH,3,-9688.77,-2561.36,59.49363,0,0,0,0,100,0),
(@PATH,4,-9670.78,-2543.3,58.54979,0,0,0,0,100,0),
(@PATH,5,-9671.38,-2515.64,59.52671,0,0,0,0,100,0),
(@PATH,6,-9691.92,-2496.74,61.03778,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,335044,3,315,2,0,0),
(@NPC,335045,3,45,2,0,0);

-- Pathing for Redridge Fox Entry: 43083
SET @NPC := 335089;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9721.58,`position_y`=-2583.98,`position_z`=59.99473 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-9721.58,`position_y`=-2583.98,`position_z`=59.99473 WHERE `guid`=335090;
UPDATE `creature` SET `position_x`=-9721.58,`position_y`=-2583.98,`position_z`=59.99473 WHERE `guid`=335091;
UPDATE `creature` SET `position_x`=-9721.58,`position_y`=-2583.98,`position_z`=59.99473 WHERE `guid`=335093;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9721.58,-2583.98,59.99473,0,0,0,0,100,0),
(@PATH,2,-9724.73,-2607.79,60.72164,0,0,0,0,100,0),
(@PATH,3,-9717.56,-2633.61,62.75267,0,0,0,0,100,0),
(@PATH,4,-9696.93,-2628.99,64.19862,0,0,0,0,100,0),
(@PATH,5,-9675.24,-2619.94,63.37025,0,0,0,0,100,0),
(@PATH,6,-9669.93,-2592.58,61.19247,0,0,0,0,100,0),
(@PATH,7,-9687.97,-2576.93,59.81454,0,0,0,0,100,0),
(@PATH,8,-9707.85,-2578.2,59.34263,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,335090,2,360,2,0,0),
(@NPC,335091,4,360,2,0,0),
(@NPC,335093,6,360,2,0,0);

-- Pathing for Redridge Fox Entry: 43083
SET @NPC := 335097;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9643.77,`position_y`=-2736.02,`position_z`=59.07977 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-9643.77,`position_y`=-2736.02,`position_z`=59.07977 WHERE `guid`=335132;
UPDATE `creature` SET `position_x`=-9643.77,`position_y`=-2736.02,`position_z`=59.07977 WHERE `guid`=335134;
UPDATE `creature` SET `position_x`=-9643.77,`position_y`=-2736.02,`position_z`=59.07977 WHERE `guid`=335135;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9643.77,-2736.02,59.07977,0,0,0,0,100,0),
(@PATH,2,-9666.16,-2744.32,57.12957,0,0,0,0,100,0),
(@PATH,3,-9673.69,-2715.49,59.43433,0,0,0,0,100,0),
(@PATH,4,-9665.98,-2686.7,61.71717,0,0,0,0,100,0),
(@PATH,5,-9669.4,-2665.82,62.68268,0,0,0,0,100,0),
(@PATH,6,-9712.4,-2665.232,62.62767,0,0,0,0,100,0),
(@PATH,7,-9697.62,-2650.54,63.20367,0,0,0,0,100,0),
(@PATH,8,-9673.83,-2636.91,63.25323,0,0,0,0,100,0),
(@PATH,9,-9656.5,-2659.89,60.2452,0,0,0,0,100,0),
(@PATH,10,-9649.22,-2700.01,60.38137,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,335132,2,360,2,0,0),
(@NPC,335134,4,360,2,0,0),
(@NPC,335135,6,360,2,0,0);

-- Pathing for Blackrock Renegade Entry: 437
SET @NPC := 334938;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9147.99,-2920.22,93.51772,0,0,0,0,100,0),
(@PATH,2,-9146.34,-2901.18,93.76942,0,0,0,0,100,0),
(@PATH,3,-9152.68,-2873.77,93.67885,0,0,0,0,100,0),
(@PATH,4,-9162.18,-2849.22,93.59364,0,0,0,0,100,0),
(@PATH,5,-9152.68,-2873.77,93.67885,0,0,0,0,100,0),
(@PATH,6,-9146.34,-2901.18,93.76942,0,0,0,0,100,0);

-- Pathing for Erin Entry: 850
SET @NPC := 334757;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9216.157,-2147.64,64.35393,0,0,0,0,100,0),
(@PATH,2,-9216.157,-2147.64,64.35393,4.677482,60000,0,0,100,0),
(@PATH,3,-9216.725,-2154.311,64.84718,0,0,1,0,100,0),
(@PATH,4,-9221.725,-2155.061,64.34718,0,0,1,0,100,0),
(@PATH,5,-9231.475,-2154.811,64.84718,0,0,1,0,100,0),
(@PATH,6,-9236.975,-2156.061,64.84718,0,0,1,0,100,0),
(@PATH,7,-9237.975,-2149.061,64.84718,0,0,1,0,100,0),
(@PATH,8,-9248.725,-2147.811,64.34718,0,0,1,0,100,0),
(@PATH,9,-9256.475,-2137.311,64.34718,0,0,1,0,100,0),
(@PATH,10,-9251.725,-2119.311,66.09718,0,0,1,0,100,0),
(@PATH,11,-9253.975,-2112.311,66.59718,0,0,1,0,100,0),
(@PATH,12,-9263.293,-2104.982,66.34043,0,30000,1,0,100,0),
(@PATH,13,-9249.603,-2116.334,66.28384,0,0,0,0,100,0),
(@PATH,14,-9253.45,-2147.048,64.0928,0,0,0,0,100,0),
(@PATH,15,-9270.047,-2158.443,61.40715,0,0,0,0,100,0),
(@PATH,16,-9288.75,-2158.962,60.97298,0,0,0,0,100,0),
(@PATH,17,-9310.324,-2149.189,63.4833,0,30000,0,0,100,0),
(@PATH,18,-9278.817,-2159.886,59.22551,0,0,1,0,100,0),
(@PATH,19,-9258.45,-2146.429,64.08644,0,0,1,0,100,0),
(@PATH,20,-9247.437,-2116.01,66.36197,0,0,1,0,100,0),
(@PATH,21,-9239.378,-2088.349,75.52158,0,0,1,0,100,0),
(@PATH,22,-9219.389,-2090.297,81.70964,0,0,1,0,100,0),
(@PATH,23,-9196.93,-2092.504,87.82926,0,0,1,0,100,0),
(@PATH,24,-9174.333,-2109.712,88.95148,0,45000,1,0,100,0),
(@PATH,25,-9188.83,-2099.061,87.90267,0,0,1,0,100,0),
(@PATH,26,-9214.83,-2090.061,83.15267,0,0,1,0,100,0),
(@PATH,27,-9236.58,-2086.311,76.40267,0,0,1,0,100,0),
(@PATH,28,-9245.83,-2110.561,68.40267,0,0,1,0,100,0),
(@PATH,29,-9255.83,-2135.561,64.40267,0,0,1,0,100,0),
(@PATH,30,-9254.08,-2148.061,64.40267,0,0,1,0,100,0),
(@PATH,31,-9237.33,-2148.561,64.65267,0,0,1,0,100,0),
(@PATH,32,-9237.33,-2156.311,64.65267,0,0,1,0,100,0),
(@PATH,33,-9231.33,-2154.811,64.65267,0,0,1,0,100,0),
(@PATH,34,-9218.33,-2155.061,64.65267,0,0,1,0,100,0),
(@PATH,35,-9216.328,-2150.409,64.35387,0,0,0,0,100,0);

-- Pathing for Rachel Entry: 849
SET @NPC := 334715; -- 334713
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9314.393,`position_y`=-2212.16,`position_z`=61.89775 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-9314.393,`position_y`=-2212.16,`position_z`=61.89775 WHERE `guid`=334713;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9314.393,-2212.16,61.89775,0,0,1,0,100,0),
(@PATH,2,-9288.709,-2208.389,62.71504,0,0,1,0,100,0),
(@PATH,3,-9284.022,-2178.648,60.0108,0,0,1,0,100,0),
(@PATH,4,-9273.287,-2164.192,61.05413,0,0,1,0,100,0),
(@PATH,5,-9264.93,-2132.723,64.42447,0,0,1,0,100,0),
(@PATH,6,-9227.58,-2127.894,64.05843,0,0,1,0,100,0),
(@PATH,7,-9205.659,-2136.823,64.05843,0,0,1,0,100,0),
(@PATH,8,-9192.083,-2135.294,64.48763,0,0,1,0,100,0),
(@PATH,9,-9184.473,-2145.096,64.05843,0,0,1,0,100,0),
(@PATH,10,-9182.216,-2161.026,64.05843,0,0,1,0,100,0),
(@PATH,11,-9179.342,-2184.792,64.05842,0,0,1,0,100,0),
(@PATH,12,-9192.17,-2203.578,64.04914,0,0,1,0,100,0),
(@PATH,13,-9194.929,-2182.834,64.05842,0,0,1,0,100,0),
(@PATH,14,-9208.972,-2174.013,64.05842,0,0,1,0,100,0),
(@PATH,15,-9226.036,-2174.073,64.05842,0,0,1,0,100,0),
(@PATH,16,-9243.988,-2174.786,63.93879,0,0,1,0,100,0),
(@PATH,17,-9254.622,-2182.467,64.01193,0,0,1,0,100,0),
(@PATH,18,-9262.729,-2193.827,64.08961,0,0,1,0,100,0),
(@PATH,19,-9261.979,-2204.166,64.05842,0,0,1,0,100,0),
(@PATH,20,-9289.273,-2213.344,62.67256,0,0,1,0,100,0),
(@PATH,21,-9315.625,-2213.448,61.89775,0,0,1,0,100,0),
(@PATH,22,-9342.124,-2208.642,61.89775,0,0,1,0,100,0),
(@PATH,23,-9344.12,-2183.702,61.89775,0,0,1,0,100,0),
(@PATH,24,-9335.428,-2185.067,61.89775,0,0,1,0,100,0),
(@PATH,25,-9342.166,-2208.277,61.89775,0,0,1,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,334713,2,360,2,0,0);

-- Pathing for Amy Davenport Entry: 777
SET @NPC := 334825;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9261.723,`position_y`=-2199.517,`position_z`=63.93879 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9261.723,-2199.517,63.93879,0,30000,0,0,100,0),
(@PATH,2,-9262.126,-2204.121,64.05842,0,0,0,0,100,0),
(@PATH,3,-9260.208,-2203.088,64.05842,0,0,0,0,100,0),
(@PATH,4,-9260.208,-2203.088,64.05842,3.333579,40000,0,0,100,0);

-- Pathing for Redridge Thrasher Entry: 712
SET @NPC := 334586; -- 334585
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=712, `spawndist`=0,`MovementType`=2,`position_x`=-9542.13,`position_y`=-1901.63,`position_z`=72.77375 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-9542.13,`position_y`=-1903.63,`position_z`=72.77375 WHERE `guid`=334585;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9542.13,-1901.63,72.77375,0,0,0,0,100,0),
(@PATH,2,-9527.42,-1891.17,75.9429,0,0,0,0,100,0),
(@PATH,3,-9509.32,-1895.59,78.98709,0,0,0,0,100,0),
(@PATH,4,-9499.37,-1886.69,80.18827,0,0,0,0,100,0),
(@PATH,5,-9478.525,-1896.393,82.33475,0,0,0,0,100,0),
(@PATH,6,-9487.31,-1918.7,80.07667,0,0,0,0,100,0),
(@PATH,7,-9502.33,-1923.41,78.24402,0,0,0,0,100,0),
(@PATH,8,-9510.65,-1941.613,76.33207,0,0,0,0,100,0),
(@PATH,9,-9525.4,-1941.76,74.1702,0,0,0,0,100,0),
(@PATH,10,-9522.404,-1967.607,75.45863,0,0,0,0,100,0),
(@PATH,11,-9532.93,-1978.41,73.93031,0,0,0,0,100,0),
(@PATH,12,-9523.17,-1958.95,74.53251,0,0,0,0,100,0),
(@PATH,13,-9526.56,-1928.85,74.68689,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,334585,5,360,2,0,0);

-- Pathing for Blackrock Warden Entry: 43535
SET @NPC := 335361;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=43535, `spawndist`=0,`MovementType`=2,`position_x`=-9758.42,`position_y`=-3194.74,`position_z`=58.73384 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9758.42,-3194.74,58.73384,0,0,0,0,100,0),
(@PATH,2,-9755.04,-3173.95,58.73384,0,0,0,0,100,0),
(@PATH,3,-9758.03,-3168.74,58.73384,0,0,0,0,100,0),
(@PATH,4,-9774.75,-3181.21,58.73384,0,0,0,0,100,0),
(@PATH,5,-9786.42,-3203.68,58.73384,0,0,0,0,100,0),
(@PATH,6,-9780.49,-3217.66,58.73384,0,0,0,0,100,0),
(@PATH,7,-9765.21,-3222.24,58.95845,0,0,0,0,100,0),
(@PATH,8,-9750.29,-3208.41,59.18062,0,0,0,0,100,0);

-- Pathing for Blackrock Warden Entry: 43535
SET @NPC := 335291;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=43535, `spawndist`=0,`MovementType`=2,`position_x`=-9688.57,`position_y`=-3132.73,`position_z`=55.91774 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9688.57,-3132.73,55.91774,0,0,0,0,100,0),
(@PATH,2,-9701.08,-3139.66,58.70721,0,0,0,0,100,0),
(@PATH,3,-9709.4,-3159.27,59.02289,0,0,0,0,100,0),
(@PATH,4,-9712.55,-3172.29,58.73384,0,0,0,0,100,0),
(@PATH,5,-9706.44,-3180.38,59.10884,0,0,0,0,100,0),
(@PATH,6,-9707.77,-3201.76,58.83516,0,0,0,0,100,0),
(@PATH,7,-9723.51,-3221.91,58.73384,0,0,0,0,100,0),
(@PATH,8,-9710.57,-3233.38,59.43367,0,0,0,0,100,0),
(@PATH,9,-9692.2,-3246.77,57.53703,0,0,0,0,100,0),
(@PATH,10,-9660.94,-3240.9,49.31552,0,0,0,0,100,0),
(@PATH,11,-9654.98,-3220.45,48.54666,0,0,0,0,100,0),
(@PATH,12,-9648.84,-3196.02,48.43808,0,0,0,0,100,0),
(@PATH,13,-9648.58,-3162.21,48.56976,0,0,0,0,100,0),
(@PATH,14,-9661.02,-3134.66,49.82977,0,0,0,0,100,0),
(@PATH,15,-9680.238,-3129.113,53.04567,0,0,0,0,100,0);

-- Pathing for Shadowhide Darkweaver Entry: 429
SET @NPC := 335409;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9274.88,`position_y`=-3313.99,`position_z`=149.7998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9274.88,-3313.99,149.7998,0,0,0,0,100,0),
(@PATH,2,-9265.84,-3308.64,149.8427,0,0,0,0,100,0),
(@PATH,3,-9265.8,-3294.15,149.7784,0,0,0,0,100,0),
(@PATH,4,-9271.41,-3287.06,149.8091,0,0,0,0,100,0),
(@PATH,5,-9278.23,-3283.55,149.8288,0,0,0,0,100,0),
(@PATH,6,-9285.919,-3287.711,149.8091,0,0,0,0,100,0),
(@PATH,7,-9292.77,-3296.86,149.8174,0,0,0,0,100,0),
(@PATH,8,-9286.12,-3287.82,149.8073,0,0,0,0,100,0),
(@PATH,9,-9278.23,-3283.55,149.8288,0,0,0,0,100,0),
(@PATH,10,-9271.41,-3287.06,149.8091,0,0,0,0,100,0),
(@PATH,11,-9265.8,-3294.15,149.7784,0,0,0,0,100,0),
(@PATH,12,-9265.84,-3308.64,149.8427,0,0,0,0,100,0);

-- Pathing for Shadowhide Darkweaver Entry: 429
SET @NPC := 335412;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9277.16,`position_y`=-3287.4,`position_z`=122.8192 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9277.16,-3287.4,122.8192,0,0,0,0,100,0),
(@PATH,2,-9283.71,-3288.05,122.8192,0,0,0,0,100,0),
(@PATH,3,-9288.71,-3290.34,121.6832,0,0,0,0,100,0),
(@PATH,4,-9292.14,-3296.1,119.4017,0,0,0,0,100,0),
(@PATH,5,-9290.7,-3304.22,116.4684,0,0,0,0,100,0),
(@PATH,6,-9292.14,-3296.1,119.4017,0,0,0,0,100,0),
(@PATH,7,-9288.71,-3290.34,121.6832,0,0,0,0,100,0),
(@PATH,8,-9283.71,-3288.05,122.8192,0,0,0,0,100,0);

-- Pathing for Shadowhide Darkweaver Entry: 429
SET @NPC := 335460;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9354.602,`position_y`=-3439.974,`position_z`=90.80293 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9354.602,-3439.974,90.80293,0,0,0,0,100,0),
(@PATH,2,-9354.187,-3425.522,91.27364,0,0,0,0,100,0),
(@PATH,3,-9327.761,-3403.446,89.54767,0,0,0,0,100,0),
(@PATH,4,-9326.521,-3386.014,89.94435,0,0,0,0,100,0),
(@PATH,5,-9340.256,-3373.242,87.75284,0,0,0,0,100,0),
(@PATH,6,-9339.783,-3356.798,88.88789,0,0,0,0,100,0),
(@PATH,7,-9332.903,-3334.062,90.80723,0,0,0,0,100,0),
(@PATH,8,-9344.098,-3307.898,89.91653,0,0,0,0,100,0),
(@PATH,9,-9333.007,-3287.381,92.21237,0,0,0,0,100,0),
(@PATH,10,-9337.138,-3272.737,94.27378,0,0,0,0,100,0),
(@PATH,11,-9333.007,-3287.381,92.21237,0,0,0,0,100,0),
(@PATH,12,-9344.098,-3307.898,89.91653,0,0,0,0,100,0),
(@PATH,13,-9332.903,-3334.062,90.80723,0,0,0,0,100,0),
(@PATH,14,-9339.783,-3356.798,88.88789,0,0,0,0,100,0),
(@PATH,15,-9340.256,-3373.242,87.75284,0,0,0,0,100,0),
(@PATH,16,-9326.521,-3386.014,89.94435,0,0,0,0,100,0),
(@PATH,17,-9327.761,-3403.446,89.54767,0,0,0,0,100,0),
(@PATH,18,-9354.187,-3425.522,91.27364,0,0,0,0,100,0);

-- Pathing for Shadowhide Warrior Entry: 568
SET @NPC := 335466;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9390.962,`position_y`=-3431.441,`position_z`=92.16482 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9390.962,-3431.441,92.16482,0,0,0,0,100,0),
(@PATH,2,-9369.958,-3438.232,93.04437,0,0,0,0,100,0),
(@PATH,3,-9352.242,-3417.151,91.14864,0,0,0,0,100,0),
(@PATH,4,-9377.317,-3398.001,89.31553,0,0,0,0,100,0),
(@PATH,5,-9392.275,-3410.385,88.68313,0,0,0,0,100,0),
(@PATH,6,-9411.288,-3412.752,86.65514,0,0,0,0,100,0),
(@PATH,7,-9420.024,-3420.84,87.411,0,0,0,0,100,0),
(@PATH,8,-9411.725,-3435.682,90.13588,0,0,0,0,100,0);

-- Pathing for Redridge Mystic Entry: 430
SET @NPC := 334708;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9006.79,`position_y`=-2107.25,`position_z`=133.3664 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9006.79,-2107.25,133.3664,0,0,0,0,100,0),
(@PATH,2,-9000.19,-2125.2,138.2317,0,0,0,0,100,0),
(@PATH,3,-9002.72,-2139.61,143.2245,0,0,0,0,100,0),
(@PATH,4,-9002.703,-2148.609,140.828,0,0,0,0,100,0),
(@PATH,5,-9002.72,-2139.61,143.2245,0,0,0,0,100,0),
(@PATH,6,-9000.19,-2125.2,138.2317,0,0,0,0,100,0);

-- Pathing for Shadowhide Brute Entry: 432
SET @NPC := 335352;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9058.552,`position_y`=-3301.954,`position_z`=102.3878 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9058.552,-3301.954,102.3878,0,0,0,0,100,0),
(@PATH,2,-9067.342,-3273.868,102.0697,0,0,0,0,100,0),
(@PATH,3,-9094.444,-3277.767,102.0516,0,0,0,0,100,0),
(@PATH,4,-9111.417,-3246.706,101.491,0,0,0,0,100,0),
(@PATH,5,-9136.741,-3251.913,101.0707,0,0,0,0,100,0),
(@PATH,6,-9134.184,-3282.838,102.8506,0,0,0,0,100,0),
(@PATH,7,-9151.759,-3291.632,102.2838,0,0,0,0,100,0),
(@PATH,8,-9151.922,-3320.341,104.8913,0,0,0,0,100,0),
(@PATH,9,-9122.731,-3331.047,100.69,0,0,0,0,100,0),
(@PATH,10,-9097.537,-3324.818,100.842,0,0,0,0,100,0),
(@PATH,11,-9078.503,-3322.085,101.7341,0,0,0,0,100,0);

-- Pathing for Shadowhide Gnoll Entry: 433
SET @NPC := 335354;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9230.697,`position_y`=-3233.006,`position_z`=101.5321 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9230.697,-3233.006,101.5321,0,0,0,0,100,0),
(@PATH,2,-9222.774,-3215.743,102.9801,0,0,0,0,100,0),
(@PATH,3,-9242.188,-3200.437,102.4082,0,0,0,0,100,0),
(@PATH,4,-9274.926,-3200.534,104.4153,0,0,0,0,100,0),
(@PATH,5,-9315.983,-3222.632,100.7225,0,0,0,0,100,0),
(@PATH,6,-9302.952,-3236.202,100.6687,0,0,0,0,100,0),
(@PATH,7,-9260.013,-3238.814,101.9067,0,0,0,0,100,0);

-- Pathing for Rabid Shadowhide Gnoll Entry: 434
SET @NPC := 335330;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9310.653,`position_y`=-3233.226,`position_z`=100.8562 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9310.653,-3233.226,100.8562,0,0,0,0,100,0),
(@PATH,2,-9292.012,-3240.249,100.6492,0,0,0,0,100,0),
(@PATH,3,-9265.055,-3209.41,102.3723,0,0,0,0,100,0),
(@PATH,4,-9263.227,-3208.543,102.1528,0,0,0,0,100,0),
(@PATH,5,-9263.227,-3208.543,102.1528,1.518436,25000,0,0,100,0),
(@PATH,6,-9305.278,-3232.39,100.8562,0,0,0,0,100,0),
(@PATH,7,-9343.33,-3233.92,95.30943,0,0,0,0,100,0),
(@PATH,8,-9376.466,-3260.896,88.61803,0,25000,0,0,100,0),
(@PATH,9,-9338.099,-3230.59,96.25731,0,0,0,0,100,0);

-- Pathing for Blackrock Renegade Entry: 437
SET @NPC := 335083;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9121.89,`position_y`=-2520.46,`position_z`=116.3406 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9121.89,-2520.46,116.3406,0,0,0,0,100,0),
(@PATH,2,-9122.75,-2540.17,115.8669,0,0,0,0,100,0),
(@PATH,3,-9121.74,-2550.45,115.3833,0,0,0,0,100,0),
(@PATH,4,-9115.36,-2564.55,115.2187,0,0,0,0,100,0),
(@PATH,5,-9120.06,-2583.72,114.1031,0,0,0,0,100,0),
(@PATH,6,-9135.13,-2602.19,111.067,0,0,0,0,100,0),
(@PATH,7,-9120.06,-2583.72,114.1031,0,0,0,0,100,0),
(@PATH,8,-9115.36,-2564.55,115.2187,0,0,0,0,100,0),
(@PATH,9,-9121.74,-2550.45,115.3833,0,0,0,0,100,0),
(@PATH,10,-9122.75,-2540.17,115.8669,0,0,0,0,100,0);

-- Pathing for Blackrock Renegade Entry: 437
SET @NPC := 335121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9153.02,`position_y`=-2617.59,`position_z`=108.3707 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9153.02,-2617.59,108.3707,0,0,0,0,100,0),
(@PATH,2,-9168.568,-2628.5,105.6241,0,0,0,0,100,0),
(@PATH,3,-9182.64,-2647.13,101.0137,0,0,0,0,100,0),
(@PATH,4,-9181.28,-2660.36,97.65508,0,0,0,0,100,0),
(@PATH,5,-9174.09,-2685.34,92.13058,0,0,0,0,100,0),
(@PATH,6,-9181.28,-2660.36,97.65508,0,0,0,0,100,0),
(@PATH,7,-9182.64,-2647.13,101.0137,0,0,0,0,100,0),
(@PATH,8,-9168.59,-2628.52,105.6111,0,0,0,0,100,0);

-- Pathing for Redridge Alpha Entry: 445
SET @NPC := 334800;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8989.48,`position_y`=-2259.67,`position_z`=138.7549 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8989.48,-2259.67,138.7549,0,0,0,0,100,0),
(@PATH,2,-8999.98,-2242.78,143.3781,0,0,0,0,100,0),
(@PATH,3,-9005.75,-2223.12,133.9867,0,0,0,0,100,0),
(@PATH,4,-9015.22,-2210.16,132.7043,0,0,0,0,100,0),
(@PATH,5,-9005.75,-2223.12,133.9867,0,0,0,0,100,0),
(@PATH,6,-8999.98,-2242.78,143.3781,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334707;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9084.58,`position_y`=-2187.67,`position_z`=132.8308 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9084.58,-2187.67,132.8308,0,0,0,0,100,0),
(@PATH,2,-9077.55,-2164.66,134.8037,0,0,0,0,100,0),
(@PATH,3,-9088.01,-2135.52,136.9709,0,0,0,0,100,0),
(@PATH,4,-9082.56,-2106.16,131.9894,0,0,0,0,100,0),
(@PATH,5,-9088.01,-2135.52,136.9709,0,0,0,0,100,0),
(@PATH,6,-9077.55,-2164.66,134.8037,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334935;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9151.08,`position_y`=-2248.12,`position_z`=117.8383 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9151.08,-2248.12,117.8383,0,0,0,0,100,0),
(@PATH,2,-9147.5,-2233.77,119.2268,0,0,0,0,100,0),
(@PATH,3,-9136.01,-2220.22,121.0444,0,0,0,0,100,0),
(@PATH,4,-9123,-2209.56,123.6323,0,0,0,0,100,0),
(@PATH,5,-9136.01,-2220.22,121.0444,0,0,0,0,100,0),
(@PATH,6,-9147.5,-2233.77,119.2268,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334709;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9127.62,`position_y`=-2175.16,`position_z`=122.4532 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9127.62,-2175.16,122.4532,0,0,0,0,100,0),
(@PATH,2,-9125.39,-2152.28,123.7381,0,0,0,0,100,0),
(@PATH,3,-9124.18,-2127.93,123.6498,0,0,0,0,100,0),
(@PATH,4,-9114.92,-2111.23,124.6359,0,0,0,0,100,0),
(@PATH,5,-9124.18,-2127.93,123.6498,0,0,0,0,100,0),
(@PATH,6,-9125.39,-2152.28,123.7381,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9146.85,`position_y`=-2188.78,`position_z`=119.6417 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9146.85,-2188.78,119.6417,0,0,0,0,100,0),
(@PATH,2,-9146.25,-2167.01,120.3895,0,0,0,0,100,0),
(@PATH,3,-9134.5,-2144.67,122.3297,0,0,0,0,100,0),
(@PATH,4,-9132.8,-2122.52,122.2406,0,0,0,0,100,0),
(@PATH,5,-9134.5,-2144.67,122.3297,0,0,0,0,100,0),
(@PATH,6,-9146.25,-2167.01,120.3895,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334685;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9125.87,`position_y`=-2029.56,`position_z`=128.6905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9125.87,-2029.56,128.6905,0,0,0,0,100,0),
(@PATH,2,-9124.28,-2044.44,128.7022,0,0,0,0,100,0),
(@PATH,3,-9110.08,-2054.3,128.7022,0,0,0,0,100,0),
(@PATH,4,-9098.18,-2057.61,128.7757,0,0,0,0,100,0),
(@PATH,5,-9084.83,-2072.38,128.7146,0,0,0,0,100,0),
(@PATH,6,-9063.13,-2078.49,130.5251,0,0,0,0,100,0),
(@PATH,7,-9084.83,-2072.38,128.7146,0,0,0,0,100,0),
(@PATH,8,-9098.18,-2057.61,128.7757,0,0,0,0,100,0),
(@PATH,9,-9110.08,-2054.3,128.7022,0,0,0,0,100,0),
(@PATH,10,-9124.28,-2044.44,128.7022,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334865;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8940.15,`position_y`=-2092.95,`position_z`=133.1256 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8940.15,-2092.95,133.1256,0,0,0,0,100,0),
(@PATH,2,-8929.22,-2116.31,133.1243,0,0,0,0,100,0),
(@PATH,3,-8909.26,-2135.76,134.2919,0,0,0,0,100,0),
(@PATH,4,-8929.22,-2116.31,133.1243,0,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 334682;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9044.33,`position_y`=-2092.64,`position_z`=130.9971 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9044.33,-2092.64,130.9971,0,0,0,0,100,0),
(@PATH,2,-9029.35,-2095.69,131.6741,0,0,0,0,100,0),
(@PATH,3,-9010.58,-2089.07,132.5085,0,0,0,0,100,0),
(@PATH,4,-8993.95,-2085.38,132.5694,0,0,0,0,100,0),
(@PATH,5,-9010.58,-2089.07,132.5085,0,0,0,0,100,0),
(@PATH,6,-9029.35,-2095.69,131.6741,0,0,0,0,100,0);

-- Pathing for Murloc Nightcrawler Entry: 544
SET @NPC := 335463;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9485.27,`position_y`=-3358.73,`position_z`=28.40793 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '8601');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9485.27,-3358.73,28.40793,0,0,0,0,100,0),
(@PATH,2,-9485.54,-3379.48,44.86273,0,0,0,0,100,0),
(@PATH,3,-9482.63,-3397.28,58.24603,0,0,0,0,100,0),
(@PATH,4,-9474.74,-3410.66,68.73155,0,0,0,0,100,0),
(@PATH,5,-9449,-3422.68,79.52767,0,0,0,0,100,0),
(@PATH,6,-9431.1,-3420.18,83.84386,0,0,0,0,100,0),
(@PATH,7,-9449,-3422.68,79.52767,0,0,0,0,100,0),
(@PATH,8,-9474.74,-3410.66,68.73155,0,0,0,0,100,0),
(@PATH,9,-9482.63,-3397.28,58.24603,0,0,0,0,100,0),
(@PATH,10,-9485.54,-3379.48,44.86273,0,0,0,0,100,0);

-- Pathing for Murloc Nightcrawler Entry: 544
SET @NPC := 335453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9558.24,`position_y`=-3320.85,`position_z`=41.69654 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '8601');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9558.24,-3320.85,41.69654,0,0,0,0,100,0),
(@PATH,2,-9526.39,-3329.08,28.71896,0,0,0,0,100,0),
(@PATH,3,-9499.389,-3329.818,15.71942,0,0,0,0,100,0),
(@PATH,4,-9526.389,-3329.08,28.74973,0,0,0,0,100,0);

-- Pathing for Blackrock Tracker Entry: 615
SET @NPC := 335022;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8712.47,`position_y`=-2579.03,`position_z`=132.6573 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8712.47,-2579.03,132.6573,0,0,0,0,100,0),
(@PATH,2,-8724.79,-2552.11,132.6774,0,0,0,0,100,0),
(@PATH,3,-8740.44,-2525.98,132.6519,0,0,0,0,100,0),
(@PATH,4,-8754.69,-2499.5,132.7373,0,0,0,0,100,0),
(@PATH,5,-8740.44,-2525.98,132.6519,0,0,0,0,100,0),
(@PATH,6,-8724.79,-2552.11,132.6774,0,0,0,0,100,0);

-- Pathing for Alma Jainrose Entry: 812
SET @NPC := 334687;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9237.784,`position_y`=-2041.65,`position_z`=78.16777 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9237.784,-2041.65,78.16777,0,40000,0,0,100,0),
(@PATH,2,-9235.044,-2035.057,78.16726,0,0,0,0,100,0),
(@PATH,3,-9234.279,-2033.733,78.1694,0,0,0,0,100,0),
(@PATH,4,-9234.279,-2033.733,78.1694,3.961897,45000,0,0,100,0);

-- Pathing for Guard Clarke Entry: 934
SET @NPC := 334827;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9344.355,`position_y`=-2206.349,`position_z`=61.89775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9344.355,-2206.349,61.89775,0,0,0,0,100,0),
(@PATH,2,-9335.028,-2207.953,61.89775,0,0,0,0,100,0),
(@PATH,3,-9322.396,-2210.031,61.89775,0,0,0,0,100,0),
(@PATH,4,-9311.435,-2210.67,61.89775,0,0,0,0,100,0),
(@PATH,5,-9297.224,-2212.776,61.89775,0,0,0,0,100,0),
(@PATH,6,-9285.208,-2216.076,63.25996,0,0,0,0,100,0),
(@PATH,7,-9284.114,-2226.769,63.39107,0,0,0,0,100,0),
(@PATH,8,-9283.647,-2243.695,63.57106,0,0,0,0,100,0),
(@PATH,9,-9281.135,-2260.52,65.97218,0,0,0,0,100,0),
(@PATH,10,-9275.419,-2273.584,67.4109,0,0,0,0,100,0),
(@PATH,11,-9271.06,-2266.026,66.2466,0,0,0,0,100,0),
(@PATH,12,-9270.646,-2245.761,64.04616,0,0,0,0,100,0),
(@PATH,13,-9269.661,-2222.433,64.04756,0,0,0,0,100,0),
(@PATH,14,-9268.26,-2200.005,64.05788,0,0,0,0,100,0),
(@PATH,15,-9266.45,-2182.234,64.08961,0,0,0,0,100,0),
(@PATH,16,-9268.26,-2200.005,64.05788,0,0,0,0,100,0),
(@PATH,17,-9269.661,-2222.433,64.04756,0,0,0,0,100,0),
(@PATH,18,-9270.646,-2245.761,64.04616,0,0,0,0,100,0),
(@PATH,19,-9271.06,-2266.026,66.2466,0,0,0,0,100,0),
(@PATH,20,-9275.419,-2273.584,67.4109,0,0,0,0,100,0),
(@PATH,21,-9281.135,-2260.52,65.97218,0,0,0,0,100,0),
(@PATH,22,-9283.647,-2243.695,63.57106,0,0,0,0,100,0),
(@PATH,23,-9284.114,-2226.769,63.39107,0,0,0,0,100,0),
(@PATH,24,-9285.208,-2216.076,63.25996,0,0,0,0,100,0),
(@PATH,25,-9296.33,-2212.813,61.89775,0,0,0,0,100,0),
(@PATH,26,-9311.435,-2210.67,61.89775,0,0,0,0,100,0),
(@PATH,27,-9322.396,-2210.031,61.89775,0,0,0,0,100,0),
(@PATH,28,-9335.001,-2207.957,61.89775,0,0,0,0,100,0);

-- Pathing for Guard Adams Entry: 936
SET @NPC := 334728;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9212.636,`position_y`=-2174.064,`position_z`=64.05842 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9212.636,-2174.064,64.05842,0,0,0,0,100,0),
(@PATH,2,-9245.297,-2171.292,63.93879,0,0,0,0,100,0),
(@PATH,3,-9245.685,-2167.466,63.93879,0,30000,0,0,100,0),
(@PATH,4,-9253.704,-2167.139,64.05788,0,0,0,0,100,0),
(@PATH,5,-9254.052,-2135.928,63.93991,0,0,0,0,100,0),
(@PATH,6,-9246.497,-2115.215,66.55289,0,0,0,0,100,0),
(@PATH,7,-9243.474,-2098.984,72.62241,0,0,0,0,100,0),
(@PATH,8,-9239.848,-2075.51,75.75473,0,0,0,0,100,0),
(@PATH,9,-9234.389,-2072.974,76.53476,0,0,0,0,100,0),
(@PATH,10,-9234.089,-2083.617,76.79282,0,0,0,0,100,0),
(@PATH,11,-9220.588,-2089.068,81.41252,0,0,0,0,100,0),
(@PATH,12,-9206.651,-2088.978,86.12273,0,0,0,0,100,0),
(@PATH,13,-9189.044,-2094.362,87.86027,0,15000,0,0,100,0),
(@PATH,14,-9235.082,-2087.048,76.55405,0,0,0,0,100,0),
(@PATH,15,-9245.788,-2099.052,72.19589,0,0,0,0,100,0),
(@PATH,16,-9246.594,-2118.702,65.59097,0,0,0,0,100,0),
(@PATH,17,-9232.146,-2130.648,64.05843,0,0,0,0,100,0),
(@PATH,18,-9212.241,-2135.419,64.05843,0,0,0,0,100,0),
(@PATH,19,-9187.412,-2138.506,64.00642,0,0,0,0,100,0),
(@PATH,20,-9187.227,-2160.702,64.05843,0,0,0,0,100,0);

-- Pathing for Dorin Songblade Entry: 956
SET @NPC := 334880;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9247.676,`position_y`=-2240.278,`position_z`=64.05842 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9247.676,-2240.278,64.05842,0,0,0,0,100,0),
(@PATH,2,-9247.676,-2240.278,64.05842,2.583087,42000,0,0,100,0),
(@PATH,3,-9250.197,-2244.496,64.05842,0,42000,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335133;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9682.82,`position_y`=-2551.73,`position_z`=59.36961 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80673');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9682.82,-2551.73,59.36961,0,0,0,0,100,0),
(@PATH,2,-9673.1,-2548.61,58.57811,0,0,0,0,100,0),
(@PATH,3,-9661.77,-2563.5,58.39433,0,0,0,0,100,0),
(@PATH,4,-9668.5,-2575.4,59.41342,0,0,0,0,100,0),
(@PATH,5,-9685.07,-2569.39,59.28476,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335095;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9701.77,`position_y`=-2506.63,`position_z`=61.76182 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80673');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9701.77,-2506.63,61.76182,0,0,0,0,100,0),
(@PATH,2,-9680.31,-2516.74,59.88779,0,0,0,0,100,0),
(@PATH,3,-9683.95,-2485.7,60.15448,0,0,0,0,100,0),
(@PATH,4,-9696.23,-2480.13,60.37299,0,0,0,0,100,0),
(@PATH,5,-9705.92,-2494.36,61.32585,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335209;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9674.72,`position_y`=-2719.21,`position_z`=59.41822 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80673');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9674.72,-2719.21,59.41822,0,0,0,0,100,0),
(@PATH,2,-9667.83,-2739.37,57.72724,0,0,0,0,100,0),
(@PATH,3,-9652.54,-2737.74,59.07952,0,0,0,0,100,0),
(@PATH,4,-9643.31,-2726.92,59.50637,0,0,0,0,100,0),
(@PATH,5,-9644.83,-2714.4,60.13137,0,0,0,0,100,0),
(@PATH,6,-9658.05,-2706.7,60.13137,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335137;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9714.63,`position_y`=-2543.55,`position_z`=60.95052 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80673');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9714.63,-2543.55,60.95052,0,0,0,0,100,0),
(@PATH,2,-9730.07,-2561.81,61.70052,0,0,0,0,100,0),
(@PATH,3,-9725.91,-2616.42,61.30391,0,0,0,0,100,0),
(@PATH,4,-9714.05,-2614.28,61.25191,0,0,0,0,100,0),
(@PATH,5,-9711.43,-2595.85,60.098,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335138;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9708.08,`position_y`=-2641.89,`position_z`=63.41331 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80673');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9708.08,-2641.89,63.41331,0,0,0,0,100,0),
(@PATH,2,-9721.14,-2661.23,65.26488,0,0,0,0,100,0),
(@PATH,3,-9730.553,-2678.887,73.73795,0,0,0,0,100,0),
(@PATH,4,-9717.49,-2680.7,67.642,0,0,0,0,100,0),
(@PATH,5,-9708.97,-2661.81,62.14158,0,0,0,0,100,0),
(@PATH,6,-9695.48,-2645.82,63.89508,0,0,0,0,100,0),
(@PATH,7,-9693.27,-2632.61,64.44862,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335139;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9651.7,`position_y`=-2687.05,`position_z`=60.59486 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9651.7,-2687.05,60.59486,0,0,0,0,100,0),
(@PATH,2,-9679.97,-2688.7,61.66298,0,0,0,0,100,0),
(@PATH,3,-9689.15,-2669.03,62.58559,0,0,0,0,100,0),
(@PATH,4,-9679.32,-2644.04,63.68976,0,0,0,0,100,0),
(@PATH,5,-9654.86,-2639.31,60.26888,0,0,0,0,100,0),
(@PATH,6,-9647.86,-2660.39,59.26791,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9635.4,`position_y`=-2796.5,`position_z`=59.42281 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9635.4,-2796.5,59.42281,0,0,0,0,100,0),
(@PATH,2,-9626.34,-2794.38,60.912,0,0,0,0,100,0),
(@PATH,3,-9610.67,-2780.64,62.78725,0,0,0,0,100,0),
(@PATH,4,-9628.94,-2765.13,58.98745,0,0,0,0,100,0),
(@PATH,5,-9639.21,-2783.63,58.59078,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335266;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9689,`position_y`=-2899.6,`position_z`=51.66112 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9689,-2899.6,51.66112,0,0,0,0,100,0),
(@PATH,2,-9708.99,-2908.08,53.27011,0,0,0,0,100,0),
(@PATH,3,-9714.89,-2889.54,52.59799,0,0,0,0,100,0),
(@PATH,4,-9714.01,-2866.09,53.18264,0,0,0,0,100,0),
(@PATH,5,-9687.51,-2875.32,51.78612,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335252;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9702.33,`position_y`=-2822.46,`position_z`=51.81567 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9702.33,-2822.46,51.81567,0,0,0,0,100,0),
(@PATH,2,-9682.3,-2812.32,51.81636,0,0,0,0,100,0),
(@PATH,3,-9690.92,-2795.11,53.08666,0,0,0,0,100,0),
(@PATH,4,-9709.76,-2802.05,51.81567,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335265;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9654.36,`position_y`=-2914.27,`position_z`=50.65636 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9654.36,-2914.27,50.65636,0,0,0,0,100,0),
(@PATH,2,-9634.99,-2912.76,50.74791,0,0,0,0,100,0),
(@PATH,3,-9660.3,-2890.32,50.73721,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335255;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9688.13,`position_y`=-2858.83,`position_z`=51.75923 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9688.13,-2858.83,51.75923,0,0,0,0,100,0),
(@PATH,2,-9673.4,-2856.11,51.75923,0,0,0,0,100,0),
(@PATH,3,-9669.04,-2829.66,52.71895,0,0,0,0,100,0),
(@PATH,4,-9685.91,-2827,51.81636,0,0,0,0,100,0),
(@PATH,5,-9701.18,-2841.28,51.82034,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335241;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9666.35,`position_y`=-2761.69,`position_z`=55.84588 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9666.35,-2761.69,55.84588,0,0,0,0,100,0),
(@PATH,2,-9686.12,-2745.93,55.84443,0,0,0,0,100,0),
(@PATH,3,-9701.71,-2765.69,52.97309,0,0,0,0,100,0),
(@PATH,4,-9687.09,-2775.99,52.07323,0,0,0,0,100,0),
(@PATH,5,-9667.9,-2774.57,55.02929,0,0,0,0,100,0);

-- Pathing for Blackrock Hunter Entry: 4462
SET @NPC := 335211;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9601.18,`position_y`=-2715.59,`position_z`=59.1107 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9601.18,-2715.59,59.1107,0,0,0,0,100,0),
(@PATH,2,-9589.58,-2702.28,60.03841,0,0,0,0,100,0),
(@PATH,3,-9605.2,-2694.94,59.17298,0,0,0,0,100,0),
(@PATH,4,-9611.5,-2704.71,58.66148,0,0,0,0,100,0);

-- Make all other Blackrock Hunters random movement
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id`=4462 AND `MovementType`=0;

-- Pathing for Blackrock Summoner Entry: 4463
SET @NPC := 335075;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8665.57,`position_y`=-2580.66,`position_z`=132.6573 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8665.57,-2580.66,132.6573,0,0,0,0,100,0),
(@PATH,2,-8649.77,-2577.11,132.6573,0,0,0,0,100,0),
(@PATH,3,-8620.51,-2578.08,132.5789,0,0,0,0,100,0),
(@PATH,4,-8591.94,-2569.3,132.5699,0,0,0,0,100,0),
(@PATH,5,-8570.54,-2563.9,133.185,0,0,0,0,100,0),
(@PATH,6,-8591.94,-2569.3,132.5699,0,0,0,0,100,0),
(@PATH,7,-8620.51,-2578.08,132.5789,0,0,0,0,100,0),
(@PATH,8,-8649.77,-2577.11,132.6573,0,0,0,0,100,0);

-- Pathing for Blackrock Summoner Entry: 4463
SET @NPC := 335069;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8797.58,`position_y`=-2581.76,`position_z`=130.6214 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8797.58,-2581.76,130.6214,0,0,0,0,100,0),
(@PATH,2,-8817.72,-2571.77,130.8075,0,0,0,0,100,0),
(@PATH,3,-8841.41,-2557.55,130.6214,0,0,0,0,100,0),
(@PATH,4,-8875.22,-2550.71,130.6214,0,0,0,0,100,0),
(@PATH,5,-8895.72,-2561.14,130.7711,0,0,0,0,100,0),
(@PATH,6,-8914.1,-2578.95,132.3345,0,0,0,0,100,0),
(@PATH,7,-8895.72,-2561.14,130.7711,0,0,0,0,100,0),
(@PATH,8,-8875.22,-2550.71,130.6214,0,0,0,0,100,0),
(@PATH,9,-8841.41,-2557.55,130.6214,0,0,0,0,100,0),
(@PATH,10,-8817.72,-2571.77,130.8075,0,0,0,0,100,0);

-- Pathing for Blackrock Summoner Entry: 4463
SET @NPC := 334992;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8799.08,`position_y`=-2472.6,`position_z`=134.6679 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8799.08,-2472.6,134.6679,0,0,0,0,100,0),
(@PATH,2,-8794.22,-2450.38,144.2244,0,0,0,0,100,0),
(@PATH,3,-8781.71,-2434.85,150.7,0,0,0,0,100,0),
(@PATH,4,-8780.83,-2419.92,156.1764,0,0,0,0,100,0),
(@PATH,5,-8774.61,-2402.02,156.2206,0,0,0,0,100,0),
(@PATH,6,-8764.4,-2387.92,156.3044,0,0,0,0,100,0),
(@PATH,7,-8774.61,-2402.02,156.2206,0,0,0,0,100,0),
(@PATH,8,-8780.83,-2419.92,156.1764,0,0,0,0,100,0),
(@PATH,9,-8781.71,-2434.85,150.7,0,0,0,0,100,0),
(@PATH,10,-8794.22,-2450.38,144.2244,0,0,0,0,100,0);

-- Pathing for Canyon Ettin Entry: 43094
SET @NPC := 334599;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9105.46,`position_y`=-2208.16,`position_z`=126.5163 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9105.46,-2208.16,126.5163,0,0,0,0,100,0),
(@PATH,2,-9134.289,-2211.389,121.312,0,0,0,0,100,0),
(@PATH,3,-9137.49,-2173.55,121.3245,0,0,0,0,100,0),
(@PATH,4,-9127.85,-2137.67,123.4426,0,0,0,0,100,0),
(@PATH,5,-9128.25,-2095.07,122.8061,0,0,0,0,100,0),
(@PATH,6,-9103.65,-2086.67,127.4204,0,0,0,0,100,0),
(@PATH,7,-9117.41,-2069.33,128.6535,0,0,0,0,100,0),
(@PATH,8,-9111.11,-2064.42,128.7022,0,0,0,0,100,0),
(@PATH,9,-9093.48,-2076.93,128.7146,0,0,0,0,100,0),
(@PATH,10,-9070.16,-2087.55,129.0393,0,0,0,0,100,0),
(@PATH,11,-9039.8,-2095.06,130.9568,0,0,0,0,100,0),
(@PATH,12,-9015.53,-2091.76,132.5085,0,0,0,0,100,0),
(@PATH,13,-9002.63,-2119.99,137.521,0,0,0,0,100,0),
(@PATH,14,-9002.05,-2138.25,143.4562,0,0,0,0,100,0),
(@PATH,15,-9001.05,-2160,133.3666,0,0,0,0,100,0),
(@PATH,16,-9009.8,-2185.88,136.2239,0,0,0,0,100,0),
(@PATH,17,-9041.53,-2193.89,131.472,0,0,0,0,100,0),
(@PATH,18,-9068.82,-2174.21,132.5518,0,0,0,0,100,0),
(@PATH,19,-9087,-2190.03,132.4278,0,0,0,0,100,0);

-- Pathing for Canyon Ettin Entry: 43094
SET @NPC := 334657;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8923.51,`position_y`=-2304.27,`position_z`=133.0706 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8923.51,-2304.27,133.0706,0,0,0,0,100,0),
(@PATH,2,-8931.27,-2331.67,132.8773,0,0,0,0,100,0),
(@PATH,3,-8962.34,-2333.7,132.5694,0,0,0,0,100,0),
(@PATH,4,-8982.57,-2351.04,132.5728,0,0,0,0,100,0),
(@PATH,5,-9000.23,-2379.13,132.4703,0,0,0,0,100,0),
(@PATH,6,-9017.43,-2401.64,130.3283,0,0,0,0,100,0),
(@PATH,7,-9021.813,-2423.211,131.7126,0,0,0,0,100,0),
(@PATH,8,-9050.23,-2437.75,128.3464,0,0,0,0,100,0),
(@PATH,9,-9062.48,-2407.44,127.3151,0,0,0,0,100,0),
(@PATH,10,-9094.87,-2388.64,124.0265,0,0,0,0,100,0),
(@PATH,11,-9112.47,-2360.19,121.6273,0,0,0,0,100,0),
(@PATH,12,-9111.24,-2354.57,122.5619,0,0,0,0,100,0),
(@PATH,13,-9095.8,-2382.87,123.9354,0,0,0,0,100,0),
(@PATH,14,-9061.45,-2399.56,128.0016,0,0,0,0,100,0),
(@PATH,15,-9018.48,-2392.57,130.7203,0,0,0,0,100,0),
(@PATH,16,-8992.11,-2368.29,132.5635,0,0,0,0,100,0),
(@PATH,17,-8964.82,-2329.2,132.5481,0,0,0,0,100,0),
(@PATH,18,-8956.58,-2292.35,132.5678,0,0,0,0,100,0),
(@PATH,19,-8926.41,-2279.25,132.7044,0,0,0,0,100,0),
(@PATH,20,-8905.42,-2245.47,133.3376,0,0,0,0,100,0),
(@PATH,21,-8881.15,-2266.83,133.1034,0,0,0,0,100,0),
(@PATH,22,-8895.5,-2281.12,133.7757,0,0,0,0,100,0),
(@PATH,23,-8915.54,-2283.71,132.3846,0,0,0,0,100,0);

-- Pathing for Blackrock Worg Captain Entry: 43341
SET @NPC := 335118;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9175.36,`position_y`=-2757.06,`position_z`=88.78236 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,207,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9175.36,-2757.06,88.78236,0,0,0,0,100,0),
(@PATH,2,-9172.7,-2748.78,88.78236,0,0,0,0,100,0),
(@PATH,3,-9166.21,-2740.42,88.7916,0,0,0,0,100,0),
(@PATH,4,-9166.21,-2740.42,88.7916,1.797689,6000,0,0,100,0),
(@PATH,5,-9150.57,-2723.75,88.77946,0,0,0,0,100,0),
(@PATH,6,-9150.46,-2710.08,88.77946,0,0,0,0,100,0),
(@PATH,7,-9158.66,-2702.11,88.77946,0,6000,0,0,100,0),
(@PATH,8,-9148.28,-2719.36,88.77946,0,0,0,0,100,0),
(@PATH,9,-9153.93,-2728.32,88.77946,0,0,0,0,100,0),
(@PATH,10,-9169.42,-2742.76,88.78236,0,0,0,0,100,0),
(@PATH,11,-9174.83,-2753.66,88.78236,0,0,0,0,100,0),
(@PATH,12,-9177.35,-2762.76,88.78236,0,0,0,0,100,0),
(@PATH,13,-9183.65,-2770.92,88.73804,0,0,0,0,100,0),
(@PATH,14,-9187.97,-2777.38,88.73804,0,0,0,0,100,0);

-- Pathing for Blackrock Drake Rider Entry: 43533
SET @NPC := 335293;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9791.42,`position_y`=-3204.87,`position_z`=58.73384 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,25831,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9791.42,-3204.87,58.73384,0,0,0,0,100,0),
(@PATH,2,-9766.69,-3229.84,58.73384,0,0,0,0,100,0);

-- Pathing for Blackrock Warden Entry: 43535
SET @NPC := 335428;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9601.39,`position_y`=-3227.86,`position_z`=49.18905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9601.39,-3227.86,49.18905,0,0,0,0,100,0),
(@PATH,2,-9587.77,-3220.46,48.89643,0,0,0,0,100,0),
(@PATH,3,-9580.24,-3240.87,49.00302,0,0,0,0,100,0),
(@PATH,4,-9569.61,-3251.48,48.75106,0,0,0,0,100,0),
(@PATH,5,-9568.84,-3268.61,48.57788,0,0,0,0,100,0),
(@PATH,6,-9559.76,-3287.24,48.77554,0,0,0,0,100,0),
(@PATH,7,-9575.87,-3295.81,47.89307,0,0,0,0,100,0),
(@PATH,8,-9591.28,-3291.65,49.61011,0,0,0,0,100,0),
(@PATH,9,-9606.76,-3272.16,48.59819,0,0,0,0,100,0),
(@PATH,10,-9612.09,-3257.14,48.54079,0,0,0,0,100,0),
(@PATH,11,-9624.36,-3246.51,49.17995,0,0,0,0,100,0),
(@PATH,12,-9627.1,-3226.77,49.31991,0,0,0,0,100,0);

-- Pathing for Ol' Gummers Entry: 43041
SET @NPC := 335055;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9426.26,`position_y`=-2522.74,`position_z`=51.0084 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9426.26,-2522.74,51.0084,0,0,0,0,100,0),
(@PATH,2,-9440.48,-2549.11,51.0084,0,0,0,0,100,0),
(@PATH,3,-9456.95,-2566.33,51.0084,0,0,0,0,100,0),
(@PATH,4,-9474.02,-2637.19,51.0084,0,0,0,0,100,0),
(@PATH,5,-9427.48,-2658.38,51.0084,0,0,0,0,100,0),
(@PATH,6,-9369.48,-2622.18,51.0084,0,0,0,0,100,0),
(@PATH,7,-9316.49,-2528.55,51.0084,0,0,0,0,100,0),
(@PATH,8,-9394.9,-2451.22,51.0084,0,0,0,0,100,0);

-- Pathing for Matthew Hooper Entry: 1680
SET @NPC := 334782;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9315.376,`position_y`=-2156.695,`position_z`=63.4833 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9315.376,-2156.695,63.4833,0,45000,0,0,100,0),
(@PATH,2,-9308.336,-2140.875,63.4833,0,45000,0,0,100,0),
(@PATH,3,-9317.214,-2147.051,63.4833,0,0,0,0,100,0),
(@PATH,4,-9317.214,-2147.051,63.4833,2.897247,40000,0,0,100,0);

-- Pathing for Guard Ashlock Entry: 932
SET @NPC := 334922;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9281.391,`position_y`=-2286.225,`position_z`=67.7533 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '5301');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9281.391,-2286.225,67.7533,0,0,0,0,100,0),
(@PATH,2,-9326.391,-2282.725,71.5033,0,0,0,0,100,0),
(@PATH,3,-9365.141,-2279.975,71.5033,0,0,0,0,100,0),
(@PATH,4,-9401.141,-2268.725,68.0033,0,0,0,0,100,0),
(@PATH,5,-9406.141,-2265.225,67.7533,0,0,0,0,100,0),
(@PATH,6,-9411.66,-2264.84,67.44,0,120000,0,0,100,0),
(@PATH,7,-9412.391,-2266.225,67.5033,0,0,0,0,100,0),
(@PATH,8,-9412.891,-2274.725,67.7533,0,0,0,0,100,0),
(@PATH,9,-9364.891,-2279.725,71.5033,0,0,0,0,100,0),
(@PATH,10,-9330.391,-2282.725,71.7533,0,0,0,0,100,0),
(@PATH,11,-9291.391,-2285.975,67.7533,0,0,0,0,100,0),
(@PATH,12,-9282.12,-2287.61,67.5666,0,120000,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335103;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9678.927,`position_y`=-2670.022,`position_z`=71.32499 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9678.927,-2670.022,71.32499,0,0,0,0,100,0),
(@PATH,2,-9673.069,-2655.88,71.32499,0,0,0,0,100,0),
(@PATH,3,-9658.927,-2650.022,71.32499,0,0,0,0,100,0),
(@PATH,4,-9644.784,-2655.88,71.32499,0,0,0,0,100,0),
(@PATH,5,-9638.927,-2670.022,71.32499,0,0,0,0,100,0),
(@PATH,6,-9644.784,-2684.164,71.32499,0,0,0,0,100,0),
(@PATH,7,-9658.927,-2690.022,71.32499,0,0,0,0,100,0),
(@PATH,8,-9673.069,-2684.164,71.32499,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335201;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9638.366,`position_y`=-2770.991,`position_z`=68.06391 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9638.366,-2770.991,68.06391,0,0,0,0,100,0),
(@PATH,2,-9632.509,-2756.849,68.06391,0,0,0,0,100,0),
(@PATH,3,-9638.366,-2742.707,68.06391,0,0,0,0,100,0),
(@PATH,4,-9652.509,-2736.849,68.06391,0,0,0,0,100,0),
(@PATH,5,-9666.651,-2742.707,68.06391,0,0,0,0,100,0),
(@PATH,6,-9672.509,-2756.849,68.06391,0,0,0,0,100,0),
(@PATH,7,-9666.651,-2770.991,68.06391,0,0,0,0,100,0),
(@PATH,8,-9652.509,-2776.849,68.06391,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335242;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9690.073,`position_y`=-2824.014,`position_z`=62.65337 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9690.073,-2824.014,62.65337,0,0,0,0,100,0),
(@PATH,2,-9684.216,-2838.156,62.65337,0,0,0,0,100,0),
(@PATH,3,-9670.073,-2844.014,62.65337,0,0,0,0,100,0),
(@PATH,4,-9655.931,-2838.156,62.65337,0,0,0,0,100,0),
(@PATH,5,-9650.073,-2824.014,62.65337,0,0,0,0,100,0),
(@PATH,6,-9655.931,-2809.872,62.65337,0,0,0,0,100,0),
(@PATH,7,-9670.073,-2804.014,62.65337,0,0,0,0,100,0),
(@PATH,8,-9684.216,-2809.872,62.65337,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335207;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9653.257,`position_y`=-2869.118,`position_z`=61.9299 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9653.257,-2869.118,61.9299,0,0,0,0,100,0),
(@PATH,2,-9647.399,-2854.976,61.9299,0,0,0,0,100,0),
(@PATH,3,-9653.257,-2840.834,61.9299,0,0,0,0,100,0),
(@PATH,4,-9667.399,-2834.976,61.9299,0,0,0,0,100,0),
(@PATH,5,-9681.542,-2840.834,61.9299,0,0,0,0,100,0),
(@PATH,6,-9687.399,-2854.976,61.9299,0,0,0,0,100,0),
(@PATH,7,-9681.542,-2869.118,61.9299,0,0,0,0,100,0),
(@PATH,8,-9667.399,-2874.976,61.9299,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335254;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9664.997,`position_y`=-2893.202,`position_z`=61.63003 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9664.997,-2893.202,61.63003,0,0,0,0,100,0),
(@PATH,2,-9679.14,-2899.06,61.63003,0,0,0,0,100,0),
(@PATH,3,-9693.282,-2893.202,61.63003,0,0,0,0,100,0),
(@PATH,4,-9699.14,-2879.06,61.63003,0,0,0,0,100,0),
(@PATH,5,-9693.282,-2864.918,61.63003,0,0,0,0,100,0),
(@PATH,6,-9679.14,-2859.06,61.63003,0,0,0,0,100,0),
(@PATH,7,-9664.997,-2864.918,61.63003,0,0,0,0,100,0),
(@PATH,8,-9659.14,-2879.06,61.63003,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335041;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9714.853,`position_y`=-2595.888,`position_z`=71.65476 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9714.853,-2595.888,71.65476,0,0,0,0,100,0),
(@PATH,2,-9708.995,-2581.746,71.65476,0,0,0,0,100,0),
(@PATH,3,-9694.853,-2575.888,71.65476,0,0,0,0,100,0),
(@PATH,4,-9680.71,-2581.746,71.65476,0,0,0,0,100,0),
(@PATH,5,-9674.853,-2595.888,71.65476,0,0,0,0,100,0),
(@PATH,6,-9680.71,-2610.031,71.65476,0,0,0,0,100,0),
(@PATH,7,-9694.853,-2615.888,71.65476,0,0,0,0,100,0),
(@PATH,8,-9708.995,-2610.031,71.65476,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334574;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9675.527,`position_y`=-2758.928,`position_z`=68.06391 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9675.527,-2758.928,68.06391,0,0,0,0,100,0),
(@PATH,2,-9669.601,-2766.983,68.06391,0,0,0,0,100,0),
(@PATH,3,-9666.651,-2770.991,68.06391,0,0,0,0,100,0),
(@PATH,4,-9652.509,-2776.849,68.06391,0,0,0,0,100,0),
(@PATH,5,-9638.366,-2770.991,68.06391,0,0,0,0,100,0),
(@PATH,6,-9632.509,-2756.849,68.06391,0,0,0,0,100,0),
(@PATH,7,-9638.366,-2742.707,68.06391,0,0,0,0,100,0),
(@PATH,8,-9652.509,-2736.849,68.06391,0,0,0,0,100,0),
(@PATH,9,-9666.651,-2742.707,68.06391,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334543;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9620.4,`position_y`=-1840.86,`position_z`=90.4727 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9620.4,-1840.86,90.4727,0,0,0,0,100,0),
(@PATH,2,-9611.39,-1844.27,87.7926,0,0,0,0,100,0),
(@PATH,3,-9596.9,-1890.13,89.5982,0,0,0,0,100,0),
(@PATH,4,-9619.67,-1925.26,90.7371,0,0,0,0,100,0),
(@PATH,5,-9679.37,-1888.64,102.639,0,0,0,0,100,0),
(@PATH,6,-9649.33,-1847.65,97.7783,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334554;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9744.78,`position_y`=-1830.7,`position_z`=72.0213 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9744.78,-1830.7,77.4657,0,0,0,0,100,0),
(@PATH,2,-9771.62,-1865.91,66.1324,0,0,0,0,100,0),
(@PATH,3,-9747.58,-1893.72,66.1324,0,0,0,0,100,0),
(@PATH,4,-9707.64,-1898.98,66.1324,0,0,0,0,100,0),
(@PATH,5,-9676.29,-1898.6,66.1324,0,0,0,0,100,0),
(@PATH,6,-9662.53,-1878.11,66.1324,0,0,0,0,100,0),
(@PATH,7,-9662.96,-1843.65,69.7713,0,0,0,0,100,0),
(@PATH,8,-9671,-1830.86,73.438,0,0,0,0,100,0),
(@PATH,9,-9682.88,-1819.66,77.4657,0,0,0,0,100,0),
(@PATH,10,-9710.54,-1827.32,72.0213,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334568;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9621.52,`position_y`=-1791.54,`position_z`=69.9771 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9621.52,-1791.54,69.9771,0,0,0,0,100,0),
(@PATH,2,-9601.88,-1780.03,69.9771,0,0,0,0,100,0),
(@PATH,3,-9661.64,-1765.11,69.9771,0,0,0,0,100,0),
(@PATH,4,-9674.95,-1776.48,69.9771,0,0,0,0,100,0),
(@PATH,5,-9661.68,-1789.29,69.9771,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334575;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9534.13,`position_y`=-1897.5,`position_z`=86.8128 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9534.13,-1897.5,86.8128,0,0,0,0,100,0),
(@PATH,2,-9540.21,-1920.24,84.3405,0,0,0,0,100,0),
(@PATH,3,-9508.93,-1920.25,84.3405,0,0,0,0,100,0),
(@PATH,4,-9499.94,-1896.07,86.8128,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334612;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9627.06,`position_y`=-1969.17,`position_z`=77.9558 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9627.06,-1969.17,77.9558,0,0,0,0,100,0),
(@PATH,2,-9678.99,-2012.63,84.428,0,0,0,0,100,0),
(@PATH,3,-9674.55,-2043.69,88.1502,0,0,0,0,100,0),
(@PATH,4,-9618.6,-2055.44,88.1502,0,0,0,0,100,0),
(@PATH,5,-9587.15,-2026.87,78.7057,0,0,0,0,100,0),
(@PATH,6,-9573.17,-1998.12,78.7057,0,0,0,0,100,0),
(@PATH,7,-9577.36,-1980.24,79.3725,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334589;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9503.79,`position_y`=-1976.59,`position_z`=93.7357 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9503.79,-1976.59,93.7357,0,0,0,0,100,0),
(@PATH,2,-9441.98,-1941.17,115.708,0,0,0,0,100,0),
(@PATH,3,-9445.79,-1921.2,98.0135,0,0,0,0,100,0),
(@PATH,4,-9487.04,-1925.15,98.0135,0,0,0,0,100,0),
(@PATH,5,-9517.51,-1943.82,88.9857,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334698;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9490.73,`position_y`=-2117.28,`position_z`=110.001 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9490.73,-2117.28,110.001,0,0,0,0,100,0),
(@PATH,2,-9487.84,-2085.75,109.723,0,0,0,0,100,0),
(@PATH,3,-9487.8,-2049.91,109.723,0,0,0,0,100,0),
(@PATH,4,-9500.49,-2015.05,100.89,0,0,0,0,100,0),
(@PATH,5,-9518.28,-1999.3,93.2232,0,0,0,0,100,0),
(@PATH,6,-9530.82,-2016.36,90.8372,0,0,0,0,100,0),
(@PATH,7,-9535.68,-2070.02,95.6984,0,0,0,0,100,0),
(@PATH,8,-9519.93,-2111.95,108.612,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 334721;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9574.24,`position_y`=-2107.24,`position_z`=85.5298 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9574.24,-2107.24,85.5298,0,0,0,0,100,0),
(@PATH,2,-9542.99,-2103.38,112.733,0,0,0,0,100,0),
(@PATH,3,-9506.77,-2073.8,112.733,0,0,0,0,100,0),
(@PATH,4,-9500.77,-2058.63,106.919,0,0,0,0,100,0),
(@PATH,5,-9532.06,-2058.7,85.5298,0,0,0,0,100,0),
(@PATH,6,-9589.85,-2051.46,85.5298,0,0,0,0,100,0),
(@PATH,7,-9607.46,-2083.2,85.5298,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335061;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9042.471,`position_y`=-2521.2,`position_z`=138.1165 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9042.471,-2521.2,138.1165,0,0,0,0,100,0),
(@PATH,2,-9048.328,-2507.058,138.1165,0,0,0,0,100,0),
(@PATH,3,-9062.471,-2501.2,138.1165,0,0,0,0,100,0),
(@PATH,4,-9076.613,-2507.058,138.1165,0,0,0,0,100,0),
(@PATH,5,-9082.471,-2521.2,138.1165,0,0,0,0,100,0),
(@PATH,6,-9076.613,-2535.342,138.1165,0,0,0,0,100,0),
(@PATH,7,-9062.471,-2541.2,138.1165,0,0,0,0,100,0),
(@PATH,8,-9048.328,-2535.342,138.1165,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335082;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9112.056,`position_y`=-2553.654,`position_z`=125.0944 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9112.056,-2553.654,125.0944,0,0,0,0,100,0),
(@PATH,2,-9117.913,-2539.523,125.0944,0,0,0,0,100,0),
(@PATH,3,-9132.056,-2533.665,125.0944,0,0,0,0,100,0),
(@PATH,4,-9146.198,-2539.523,125.0944,0,0,0,0,100,0),
(@PATH,5,-9152.056,-2553.665,125.0944,0,0,0,0,100,0),
(@PATH,6,-9146.198,-2567.807,125.0944,0,0,0,0,100,0),
(@PATH,7,-9132.056,-2573.665,125.0944,0,0,0,0,100,0),
(@PATH,8,-9117.913,-2567.807,125.0944,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335127;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9065.914,`position_y`=-2602.353,`position_z`=136.5891 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9065.914,-2602.353,136.5891,0,0,0,0,100,0),
(@PATH,2,-9060.057,-2616.495,136.5891,0,0,0,0,100,0),
(@PATH,3,-9065.914,-2630.637,136.5891,0,0,0,0,100,0),
(@PATH,4,-9080.057,-2636.495,136.5891,0,0,0,0,100,0),
(@PATH,5,-9094.199,-2630.637,136.5891,0,0,0,0,100,0),
(@PATH,6,-9100.057,-2616.495,136.5891,0,0,0,0,100,0),
(@PATH,7,-9094.199,-2602.353,136.5891,0,0,0,0,100,0),
(@PATH,8,-9080.057,-2596.495,136.5891,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335122;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9096.249,`position_y`=-2630.119,`position_z`=129.3912 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9096.249,-2630.119,129.3912,0,0,0,0,100,0),
(@PATH,2,-9102.106,-2615.977,129.3912,0,0,0,0,100,0),
(@PATH,3,-9116.249,-2610.119,129.3912,0,0,0,0,100,0),
(@PATH,4,-9130.392,-2615.977,129.3912,0,0,0,0,100,0),
(@PATH,5,-9136.249,-2630.119,129.3912,0,0,0,0,100,0),
(@PATH,6,-9130.392,-2644.261,129.3912,0,0,0,0,100,0),
(@PATH,7,-9116.249,-2650.119,129.3912,0,0,0,0,100,0),
(@PATH,8,-9102.106,-2644.261,129.3912,0,0,0,0,100,0);

-- Pathing for Dire Condor Entry: 428
SET @NPC := 335124;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9070.152,`position_y`=-2635.953,`position_z`=137.5065 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9070.152,-2635.953,137.5065,0,0,0,0,100,0),
(@PATH,2,-9064.295,-2650.095,137.5065,0,0,0,0,100,0),
(@PATH,3,-9070.152,-2664.237,137.5065,0,0,0,0,100,0),
(@PATH,4,-9084.295,-2670.095,137.5065,0,0,0,0,100,0),
(@PATH,5,-9098.438,-2664.237,137.5065,0,0,0,0,100,0),
(@PATH,6,-9104.295,-2650.095,137.5065,0,0,0,0,100,0),
(@PATH,7,-9098.438,-2635.953,137.5065,0,0,0,0,100,0),
(@PATH,8,-9084.295,-2630.095,137.5065,0,0,0,0,100,0);

-- Pathing for Madison Entry: 848
SET @NPC := 334626;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9248.165,`position_y`=-2025.89,`position_z`=77.20025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9248.165,-2025.89,77.20025,0,0,1,0,100,0),
(@PATH,2,-9247.915,-2036.89,77.20025,0,0,1,0,100,0),
(@PATH,3,-9240.415,-2061.64,76.70025,0,0,1,0,100,0),
(@PATH,4,-9240.165,-2086.89,75.70025,0,0,1,0,100,0),
(@PATH,5,-9246.665,-2108.89,68.95025,0,0,1,0,100,0),
(@PATH,6,-9254.915,-2137.64,64.45025,0,0,1,0,100,0),
(@PATH,7,-9255.165,-2160.64,64.45025,0,0,1,0,100,0),
(@PATH,8,-9255.415,-2183.39,64.45025,0,0,1,0,100,0),
(@PATH,9,-9269.415,-2190.14,64.45025,0,0,1,0,100,0),
(@PATH,10,-9275.165,-2209.64,64.45025,0,0,1,0,100,0),
(@PATH,11,-9285.915,-2211.89,63.45025,0,0,1,0,100,0),
(@PATH,12,-9315.165,-2211.14,62.20025,0,0,1,0,100,0),
(@PATH,13,-9327.5,-2202.18,61.8977,0,120000,1,0,100,0),
(@PATH,14,-9326.415,-2202.39,62.20025,0,0,1,0,100,0),
(@PATH,15,-9314.165,-2207.39,62.20025,0,0,1,0,100,0),
(@PATH,16,-9288.915,-2208.89,62.95025,0,0,1,0,100,0),
(@PATH,17,-9282.415,-2174.89,60.45025,0,0,1,0,100,0),
(@PATH,18,-9274.665,-2157.14,60.70025,0,0,1,0,100,0),
(@PATH,19,-9264.665,-2132.64,64.95025,0,0,1,0,100,0),
(@PATH,20,-9249.165,-2115.14,66.95025,0,0,1,0,100,0),
(@PATH,21,-9241.665,-2087.64,75.45025,0,0,1,0,100,0),
(@PATH,22,-9239.165,-2059.89,76.95025,0,0,1,0,100,0),
(@PATH,23,-9247.415,-2048.14,77.20025,0,0,1,0,100,0),
(@PATH,24,-9248.665,-2030.39,77.20025,0,0,1,0,100,0),
(@PATH,25,-9248.33,-2023.6,77.0028,0,120000,1,0,100,0);
-- 0x203CA8000000D400005CC000002E0203 .go xyz -9327.5 -2202.18 61.8977

-- Fix Redridge Citizens
DELETE FROM `creature` WHERE `guid` IN (334864,334879);
DELETE FROM `creature_addon` WHERE `guid` IN (334751,334752,334754,334755,334756,334758,334759,334760,334761,334762,334763,334764,334765,334766,334767,334769,334770,334771,334774,334775);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(334751,0,0,65536,257,0, '80815'),(334752,0,0,65536,257,0, '80815'),(334754,0,0,65536,257,0, '80815'),
(334755,0,0,65536,257,0, '80815'),(334756,0,0,65536,257,0, '80815'),(334758,0,0,65536,257,0, '80815'),
(334759,0,0,65536,257,0, '80815'),(334760,0,0,65536,257,0, '80815'),(334761,0,0,65536,257,0, '80815'),
(334762,0,0,65536,257,0, '80815'),(334763,0,0,65536,257,0, '80815'),(334764,0,0,65536,257,0, '80815'),
(334765,0,0,65536,257,0, '80815'),(334766,0,0,65536,257,0, '80815'),(334767,0,0,65536,257,0, '80815'),
(334769,0,0,65536,257,0, '80815'),(334770,0,0,65536,257,0, '80815'),(334771,0,0,65536,257,0, '80815'),
(334774,0,0,65536,257,0, '80815'),(334775,0,0,65536,257,0, '80815');
DELETE FROM `creature_addon` WHERE `guid` IN (334805,334806,334807,334808,334809,334810,334811,334812,334813,334815,334816,334818);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(334805,0,0,65536,257,0, '82099'),(334806,0,0,65536,257,0, '82099'),(334807,0,0,65536,257,0, '82099'),
(334808,0,0,65536,257,0, '82099'),(334809,0,0,65536,257,0, '82099'),(334810,0,0,65536,257,0, '82099'),
(334811,0,0,65536,257,0, '82099'),(334812,0,0,65536,257,0, '82099'),(334813,0,0,65536,257,0, '82099'),
(334815,0,0,65536,257,0, '82099'),(334816,0,0,65536,257,0, '82099'),(334818,0,0,65536,257,0, '82099');

UPDATE `creature` SET `spawndist`=1,`MovementType`=1,`position_x`=-9204.548,`position_y`=-2149.058,`position_z`=64.34298 WHERE `guid`=334749;

-- Snarlflare SAI
SET @ENTRY := 14272;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4,`ExperienceModifier`=7.5 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,6000,10000,6000,10000,11,54293,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snarlflare - OOC - Cast 'Flame Breath'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,8000,12000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snarlflare - Combat - Cast 'Flame Breath'");

UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid`=334917;

-- Marshal Marris SAI
SET @ENTRY := 382;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-334923 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-334923,0,0,0,1,0,100,0,8000,8000,8000,8000,11,58952,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal Marris - OOC - Cast 'Drink Alcohol'");

-- Foreman Oslow text
DELETE FROM `creature_text` WHERE `CreatureID`=341;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(341, 0, 0, 'Somebody... please... get... rock... off... me...', 12, 0, 100, 0, 0, 0, 43173, 'Foreman Oslow'),
(341, 0, 1, 'Hurts... Hurts so bad...', 12, 0, 100, 0, 0, 0, 43174, 'Foreman Oslow'),
(341, 0, 2, 'Please... kill... me...', 12, 0, 100, 0, 0, 0, 43175, 'Foreman Oslow'),
(341, 0, 3, 'I... just... wanted... to... build... the... damned... bridge...', 12, 0, 100, 0, 0, 0, 43176, 'Foreman Oslow');

-- Bridge Worker Alex text
DELETE FROM `creature_text` WHERE `CreatureID` IN (653,648,649,650,651,652);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(653, 0, 0, 'PUT YOUR BACKS INTO IT, BOYS!', 12, 0, 100, 0, 0, 0, 43181, 'Bridge Worker Alex'),
(653, 1, 0, 'HEAVE!', 12, 0, 100, 0, 0, 0, 43182, 'Bridge Worker Alex'),
(653, 2, 0, 'DAMN ROCK WON''T BUDGE!', 12, 0, 100, 0, 0, 0, 43184, 'Bridge Worker Alex'),
(653, 4, 0, 'PUSH HARDER!', 12, 0, 100, 0, 0, 0, 43185, 'Bridge Worker Alex'),
(653, 3, 0, 'We''ll get you out of there, Foreman, just HANG ON!', 12, 0, 100, 0, 0, 0, 43187, 'Bridge Worker Alex'),
(648, 0, 0, 'HO!', 12, 0, 100, 0, 0, 0, 43183, 'Bridge Worker Trent'),
(649, 0, 0, 'HO!', 12, 0, 100, 0, 0, 0, 43183, 'Bridge Worker Dimitri'),
(650, 0, 0, 'HO!', 12, 0, 100, 0, 0, 0, 43183, 'Bridge Worker Jess'),
(651, 0, 0, 'HO!', 12, 0, 100, 0, 0, 0, 43183, 'Bridge Worker Daniel'),
(652, 0, 0, 'HO!', 12, 0, 100, 0, 0, 0, 43183, 'Bridge Worker Matthew'),
(652, 1, 0, 'I''M PUSHIN'' AS HARD AS I CAN! THING WEIGHS A TON!', 12, 0, 100, 0, 0, 0, 43186, 'Bridge Worker Matthew');

DELETE FROM `quest_template_addon` WHERE `NextQuestID`=26503;

-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (26365,28563) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26365, 0, 0, 8, 0, 26503, 0, 0, 1, 0, 0, '', 'Show quest Hero''s Call: Redridge Mountains! if quest Still Assessing the Threat has not been rewarded.'),
(19, 0, 28563, 0, 0, 8, 0, 26503, 0, 0, 1, 0, 0, '', 'Show quest Hero''s Call: Redridge Mountains! if quest Still Assessing the Threat has not been rewarded.');

-- Nida SAI
SET @ENTRY := 8962;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,26508,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nida - On Quest Reward - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,8963,5,0,0,0,0,0,"Nida - Script - Target Say 0"), -- Effsee should say with player as target but can't in sai
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,1,0,0,0,0,7,0,0,0,0,0,0,0,"Nida - Script - Say 0"); -- Nida says with player as target
-- Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (8962,8963);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(8962, 0, 0, 'I know how to speak kitty, and Effsee said thank you.', 12, 0, 100, 0, 0, 0, 4628, 'Nida'),
(8963, 0, 0, 'Meow!', 12, 0, 100, 0, 0, 0, 4627, 'Effsee');

-- Areatrigger SAI
SET @ENTRY := 6033;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,1,46,0,100,0,0,10000,10000,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Store Invoker target"),
(@ENTRY,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,334562,43173,0,0,0,0,0,"Areatrigger - On Trigger - Store Invoker target"),
(@ENTRY,2,2,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,334562,43173,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1 for Redridge Garrison Watchman");
-- Redridge Garrison Watchman SAI
SET @ENTRY := 43173;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` IN (2,3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,3,38,0,100,0,1,1,10000,10000,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"S.A.F.E. Officer - On Data Set - Turn to Invoker"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,1,0,1,0,0,0,0,12,1,0,0,0,0,0,0,"S.A.F.E. Officer - On Data Set - Say 0 to target"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - On Data Set - Say 0 to target"),
(@ENTRY*100,9,0,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - Script - Reset Orientation");
-- Redridge Garrison Watchman Text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Hail, citizen. I would recommend that you speak with Watch Captain Parker. He''s currently at the top of this tower.', 12, 0, 100, 25, 0, 0, 43164, 'Redridge Garrison Watchman');

DELETE FROM `creature_text` WHERE `CreatureID` IN (43222,43247);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43222, 0, 0, 'My spouse has gone missing! Please help!', 12, 7, 100, 22, 0, 0, 43745, 'Redridge Citizen'),
(43222, 0, 1, 'Townspeople are disappearing, Solomon. What are you going to do about it?', 12, 7, 100, 22, 0, 0, 43746, 'Redridge Citizen'),
(43222, 0, 2, 'It''s time to wake up, magistrate! These aren''t ordinary gnoll attacks!', 12, 7, 100, 25, 0, 0, 43747, 'Redridge Citizen'),
(43222, 0, 3, 'Where is the help that we requested from Stormwind?', 12, 7, 100, 4, 0, 0, 43748, 'Redridge Citizen'),
(43222, 0, 4, 'What are we paying our taxes for if your guards can''t even keep gnolls out?', 12, 7, 100, 53, 0, 0, 43749, 'Redridge Citizen'),
(43222, 0, 5, 'My children were kidnapped while they slept! I WANT ANSWERS, SOLOMON!', 12, 7, 100, 5, 0, 0, 43750, 'Redridge Citizen'),
(43222, 0, 6, 'You better do something quick or you''ll have a riot on your hands, Solomon!', 12, 7, 100, 53, 0, 0, 43751, 'Redridge Citizen'),
(43222, 0, 7, 'The gnolls have never been this aggressive. What''s going on, Solomon? Tell us!', 12, 7, 100, 25, 0, 0, 43752, 'Redridge Citizen'),
(43222, 0, 8, 'How long must we stand here before our pleas are heard?', 12, 7, 100, 53, 0, 0, 43753, 'Redridge Citizen'),
(43222, 0, 9, 'Get this damned line moving!', 12, 7, 100, 15, 0, 0, 43754, 'Redridge Citizen'),
(43222, 0, 10, 'You''re good for nothing, Solomon!', 12, 7, 100, 14, 0, 0, 43755, 'Redridge Citizen'),
(43222, 0, 11, 'You can forget about re-election, magistrate!', 12, 7, 100, 274, 0, 0, 43756, 'Redridge Citizen'),
(43222, 0, 12, 'No justice, no peace!', 12, 7, 100, 22, 0, 0, 43757, 'Redridge Citizen'),
(43222, 0, 13, 'If you don''t do something about these gnolls, we will!', 12, 7, 100, 25, 0, 0, 43758, 'Redridge Citizen'),
(43222, 0, 14, 'Please help me! I''m the last member of my family left. Everyone else has been kidnapped!', 12, 7, 100, 15, 0, 0, 43759, 'Redridge Citizen'),
(43222, 1, 0, 'Forget you, Solomon. I''ll find my family by myself.', 12, 7, 100, 14, 0, 0, 43760, 'Redridge Citizen'),
(43247, 0, 0, 'My spouse has gone missing! Please help!', 12, 7, 100, 22, 0, 0, 43745, 'Redridge Citizen'),
(43247, 0, 1, 'Townspeople are disappearing, Solomon. What are you going to do about it?', 12, 7, 100, 22, 0, 0, 43746, 'Redridge Citizen'),
(43247, 0, 2, 'It''s time to wake up, magistrate! These aren''t ordinary gnoll attacks!', 12, 7, 100, 25, 0, 0, 43747, 'Redridge Citizen'),
(43247, 0, 3, 'Where is the help that we requested from Stormwind?', 12, 7, 100, 4, 0, 0, 43748, 'Redridge Citizen'),
(43247, 0, 4, 'What are we paying our taxes for if your guards can''t even keep gnolls out?', 12, 7, 100, 53, 0, 0, 43749, 'Redridge Citizen'),
(43247, 0, 5, 'My children were kidnapped while they slept! I WANT ANSWERS, SOLOMON!', 12, 7, 100, 5, 0, 0, 43750, 'Redridge Citizen'),
(43247, 0, 6, 'You better do something quick or you''ll have a riot on your hands, Solomon!', 12, 7, 100, 53, 0, 0, 43751, 'Redridge Citizen'),
(43247, 0, 7, 'The gnolls have never been this aggressive. What''s going on, Solomon? Tell us!', 12, 7, 100, 25, 0, 0, 43752, 'Redridge Citizen'),
(43247, 0, 8, 'How long must we stand here before our pleas are heard?', 12, 7, 100, 53, 0, 0, 43753, 'Redridge Citizen'),
(43247, 0, 9, 'Get this damned line moving!', 12, 7, 100, 15, 0, 0, 43754, 'Redridge Citizen'),
(43247, 0, 10, 'You''re good for nothing, Solomon!', 12, 7, 100, 14, 0, 0, 43755, 'Redridge Citizen'),
(43247, 0, 11, 'You can forget about re-election, magistrate!', 12, 7, 100, 274, 0, 0, 43756, 'Redridge Citizen'),
(43247, 0, 12, 'No justice, no peace!', 12, 7, 100, 22, 0, 0, 43757, 'Redridge Citizen'),
(43247, 0, 13, 'If you don''t do something about these gnolls, we will!', 12, 7, 100, 25, 0, 0, 43758, 'Redridge Citizen'),
(43247, 0, 14, 'Please help me! I''m the last member of my family left. Everyone else has been kidnapped!', 12, 7, 100, 15, 0, 0, 43759, 'Redridge Citizen'),
(43247, 1, 0, 'Forget you, Solomon. I''ll find my family by myself.', 12, 7, 100, 14, 0, 0, 43760, 'Redridge Citizen');

-- fix some loot "POSSIBLE ADJUSTED AND REPUSHED IN FUTURE "
DELETE FROM `creature_loot_template` WHERE `Entry` IN (430,445,446,580,518) AND `Reference`=0;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Redridge Mystic
(430,58897,0,100,1,1,0,1,1,'Redridge Gnoll Collar'), -- 100%
(430,2589,0,20,0,1,1,1,3,'Linen Cloth'), -- 10%
(430,2592,0,20,0,1,1,1,2,'Wool Cloth'),
(430,1179,0,20,0,1,2,1,1,'Ice Cold Milk'), -- 20%
(430,2287,0,20,0,1,2,1,1,'Haunch of Meat'),
(430,858,0,5,0,1,3,1,1,'Lesser Healing Potion'), -- 5%
(430,2455,0,5,0,1,3,1,1,'Minor Mana Potion'),
(430,1210,0,1,0,1,4,1,1,'Shadowgem'), -- 1%
(430,58898,0,50,0,1,5,1,1,'Dirt-Stained Scroll'), -- 50%
-- Redridge Alpha
(445,58897,0,100,1,1,0,1,1,'Redridge Gnoll Collar'), -- 100%
(445,2589,0,20,0,1,1,1,3,'Linen Cloth'), -- 10%
(445,2592,0,20,0,1,1,1,2,'Wool Cloth'),
(445,1179,0,20,0,1,2,1,1,'Ice Cold Milk'), -- 20%
(445,2287,0,20,0,1,2,1,1,'Haunch of Meat'),
(445,858,0,5,0,1,3,1,1,'Lesser Healing Potion'), -- 5%
(445,2455,0,5,0,1,3,1,1,'Minor Mana Potion'),
(445,1210,0,1,0,1,4,1,1,'Shadowgem'), -- 1%
(445,58898,0,50,0,1,5,1,1,'Dirt-Stained Scroll'), -- 50%
-- Redridge Basher
(446,58897,0,100,1,1,0,1,1,'Redridge Gnoll Collar'), -- 100%
(446,2589,0,20,0,1,1,1,3,'Linen Cloth'), -- 10%
(446,2592,0,20,0,1,1,1,2,'Wool Cloth'),
(446,1179,0,20,0,1,2,1,1,'Ice Cold Milk'), -- 20%
(446,2287,0,20,0,1,2,1,1,'Haunch of Meat'),
(446,858,0,5,0,1,3,1,1,'Lesser Healing Potion'), -- 5%
(446,2455,0,5,0,1,3,1,1,'Minor Mana Potion'),
(446,1210,0,1,0,1,4,1,1,'Shadowgem'), -- 1%
(446,58898,0,50,0,1,5,1,1,'Dirt-Stained Scroll'), -- 50%
-- Redridge Drudger
(580,58897,0,100,1,1,0,1,1,'Redridge Gnoll Collar'), -- 100%
(580,2589,0,20,0,1,1,1,3,'Linen Cloth'), -- 10%
(580,2592,0,20,0,1,1,1,2,'Wool Cloth'),
(580,1179,0,20,0,1,2,1,1,'Ice Cold Milk'), -- 20%
(580,2287,0,20,0,1,2,1,1,'Haunch of Meat'),
(580,858,0,5,0,1,3,1,1,'Lesser Healing Potion'), -- 5%
(580,2455,0,5,0,1,3,1,1,'Minor Mana Potion'),
(580,1210,0,1,0,1,4,1,1,'Shadowgem'), -- 1%
(580,58898,0,50,0,1,5,1,1,'Dirt-Stained Scroll'), -- 50%
-- Yowler
(518,58937,0,100,1,1,0,1,1,'Blackrock Invasion Plans'), -- 100%
(518,2589,0,20,0,1,1,1,3,'Linen Cloth'), -- 10%
(518,2592,0,20,0,1,1,1,2,'Wool Cloth'),
(518,1179,0,20,0,1,2,1,1,'Ice Cold Milk'), -- 20%
(518,2287,0,20,0,1,2,1,1,'Haunch of Meat'),
(518,858,0,5,0,1,3,1,1,'Lesser Healing Potion'), -- 5%
(518,2455,0,5,0,1,3,1,1,'Minor Mana Potion'),
(518,1210,0,1,0,1,4,1,1,'Shadowgem'); -- 1%

-- Redridge Scriptnames
UPDATE `creature_template` SET `ScriptName`='npc_big_earl' WHERE `entry`=43248;
UPDATE `creature_template` SET `ScriptName`='npc_dumpy_and_keeshan' WHERE `entry` IN (43249,43184);
UPDATE `creature_template` SET `ScriptName`='npc_redridge_citizen' WHERE `entry` IN (43222,43247);
UPDATE `creature_template` SET `ScriptName`='npc_bridge_worker_alex' WHERE `entry`=653;