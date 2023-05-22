-- Inn, Boralus
SET @PHASE := 0;
SET @SWAP := -1;
SET @CGUID := 850606;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,142752,1643,0,0,0,@PHASE,0,@SWAP,0,0,1185.2587,-593.9601,31.730467,4.018624782562255859,300,0,0,1,0,0,0,0,0,0),
(@CGUID+1,142056,1643,0,0,0,@PHASE,0,@SWAP,0,0,1187.2413,-595.4583,32.942432,4.142158031463623046,300,0,0,1,0,0,0,0,0,0),
(@CGUID+2,177193,1643,0,0,0,@PHASE,0,@SWAP,0,0,1171.6771,-597.67706,31.742126,1.357682228088378906,300,0,0,1,0,0,0,0,0,0),
(@CGUID+3,138725,1643,0,0,0,@PHASE,0,@SWAP,0,0,1188.8785,-580.941,31.557228,5.265533924102783203,300,0,0,1,0,0,0,0,0,0),
(@CGUID+4,138726,1643,0,0,0,@PHASE,0,@SWAP,0,0,1189.0226,-582.533,31.557224,0.805170536041259765,300,0,0,1,0,0,0,0,0,0),
(@CGUID+5,138724,1643,0,0,0,@PHASE,0,@SWAP,0,0,1190.2274,-581.73615,31.585388,3.182176828384399414,300,0,0,1,0,0,0,0,0,0),
(@CGUID+6,135153,1643,0,0,0,@PHASE,0,@SWAP,0,0,1181.9045,-596.1632,31.741201,1.415455222129821777,300,0,0,1,0,0,0,0,0,0);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`MountCreatureID`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`visibilityDistanceType`,`auras`) VALUES
(@CGUID+0,0,0,0,0,1,0,16093,0,0,0,''),
(@CGUID+1,0,0,0,0,1,0,0,0,0,0,'145953'),
(@CGUID+2,0,0,0,0,1,0,0,0,0,0,''),
(@CGUID+3,0,0,0,0,1,0,0,0,0,0,''),
(@CGUID+4,0,0,0,0,1,0,0,0,0,0,''),
(@CGUID+5,0,0,0,0,1,0,0,0,0,0,''),
(@CGUID+6,0,0,0,0,1,0,0,0,0,0,'');

-- Archmage Zalia Entry: 138724, Archmage Auri Entry: 138725, Archmage Luci Entry: 138726 SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (138724,138725,138726);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (138724,138725,138726) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(138724,0,0,0,1,0,100,0,3000,4000,3000,4000,0,10,1,6,273,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Zalia - OOC - Do random emote'),
(138724,0,1,0,1,0,100,0,10000,30000,25000,30000,0,11,56745,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Zalia - OOC - Cast ''Drink Alcohol'''),
(138725,0,0,0,1,0,100,0,3000,4000,3000,4000,0,10,1,6,273,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Auri - OOC - Do random emote'),
(138725,0,1,0,1,0,100,0,10000,30000,25000,30000,0,11,56745,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Auri - OOC - Cast ''Drink Alcohol'''),
(138726,0,0,0,1,0,100,0,3000,4000,3000,4000,0,10,1,6,273,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Luci - OOC - Do random emote'),
(138726,0,1,0,1,0,100,0,10000,30000,25000,30000,0,11,56745,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Luci - OOC - Cast ''Drink Alcohol''');

DELETE FROM `npc_vendor` WHERE `entry`=135153;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(135153, 1, 159867, 0, 0, 1, 0, 0, 45745),
(135153, 2, 159868, 0, 0, 1, 0, 0, 45745),
(135153, 3, 162026, 0, 0, 1, 0, 0, 45745),
(135153, 4, 159850, 0, 0, 1, 0, 0, 45745),
(135153, 5, 159846, 0, 0, 1, 0, 0, 45745),
(135153, 6, 163019, 0, 0, 1, 0, 0, 45745),
(135153, 7, 159874, 0, 0, 1, 0, 0, 45745),
(135153, 8, 159878, 0, 0, 1, 0, 0, 45745),
(135153, 9, 163052, 0, 0, 1, 0, 0, 45745),
(135153, 10, 163107, 0, 0, 1, 0, 0, 45745);

UPDATE `creature_template` SET `gossip_menu_id`=23196 WHERE `entry`=142752;
UPDATE `creature_template` SET `gossip_menu_id`=26846 WHERE `entry`=177193;
UPDATE `creature_template` SET `gossip_menu_id`=22552 WHERE `entry`=135153;
UPDATE `npc_text` SET `Probability0`=1 WHERE `ID`=42723;

-- Pettable creatures on Boralus spell clicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (142056,143502,142139,143022,135521,143272,144175,144178,144177,144176,142069,142050,142055,142053,142052,142453,142031,142030,142035,142043,142042,142040,137199,137196,142029,142613,142032,142111,142046,142044,137201,138410,148906,138423,138422,138421,142051,144110,144327,144328,143444,148904,142119);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(142056, 224326, 3, 0),
(143502, 224326, 3, 0),
(142139, 224326, 3, 0),
(143022, 224326, 3, 0),
(135521, 224326, 3, 0),
(143272, 224326, 3, 0),
(144175, 224326, 3, 0),
(144178, 224326, 3, 0),
(144177, 224326, 3, 0),
(144176, 224326, 3, 0),
(142069, 224326, 3, 0),
(142050, 224326, 3, 0),
(142055, 224326, 3, 0),
(142053, 224326, 3, 0),
(142052, 224326, 3, 0),
(142453, 224326, 3, 0),
(142031, 224326, 3, 0),
(142030, 224326, 3, 0),
(142035, 224326, 3, 0),
(142043, 224326, 3, 0),
(142042, 224326, 3, 0),
(142040, 224326, 3, 0),
(137199, 224326, 3, 0),
(137196, 224326, 3, 0),
(142029, 224326, 3, 0),
(142613, 224326, 3, 0),
(142032, 224326, 3, 0),
(142111, 224326, 3, 0),
(142046, 224326, 3, 0),
(142044, 224326, 3, 0),
(137201, 224326, 3, 0),
(138410, 224326, 3, 0),
(148906, 224326, 3, 0),
(138423, 224326, 3, 0),
(138422, 224326, 3, 0),
(138421, 224326, 3, 0),
(142051, 224326, 3, 0),
(144110, 224326, 3, 0),
(144327, 224326, 3, 0),
(144328, 224326, 3, 0),
(143444, 224326, 3, 0),
(148904, 224326, 3, 0),
(142119, 224326, 3, 0);
