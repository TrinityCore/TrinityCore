SET @CGUID := 395096;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -430.007, -111.033, 626.0352, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+1, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -754.8438, -61.96528, 635.946, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+2, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1032.677, -38.38542, 705.9167, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+3, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1088.38, -56.26042, 705.9065, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+4, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1190.595, 73.69444, 754.2231, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+5, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1226.01, 88.93056, 754.2231, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+6, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1046.92, 419.4653, 698.1262, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+7, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -1004.285, 430.224, 657.9739, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)
(@CGUID+8, 51157, 657, 0, 0, 2, 169, 0, 0, 0, -763.6198, 411.309, 682.6913, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Golden Orb (Area: -Unknown- - Difficulty: 0) (Auras: 94316 - Golden Orb Visual)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+242;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+1, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+2, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+3, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+4, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+5, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+6, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+7, 0, 0, 0, 1, 0, '94316'), -- Golden Orb - 94316 - Golden Orb Visual
(@CGUID+8, 0, 0, 0, 1, 0, '94316'); -- Golden Orb - 94316 - Golden Orb Visual

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 51157;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(51157, 1);

UPDATE `npc_spellclick_spells` SET `spell_id`= 68742 WHERE `npc_entry`= 51157;

-- Creature Golden Orb 51157 SAI
SET @ENTRY := 51157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 68742, 0, 0, 0, 34, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Interact Dummy (68742) hit  - Set instance data #14 to 0 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 28, 94316, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove aura due to spell Golden Orb Visual (94316) // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 1400 ms // ");
