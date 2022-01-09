SET @CGUID := 396662;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- first wing
(@CGUID+0, 45323, 329, 2017, 2017, 1, 169, 0, 0, 0, 3388.889892578125, -3384.93994140625, 142.8853302001953125, 0.663225114345550537, 7200, 0, 0, 27432, 0, 0, 0, 0, 0, 15595), -- Packmaster Stonebruiser (Area: Stratholme - Difficulty: 0)
(@CGUID+1, 45325, 329, 2017, 2017, 1, 169, 0, 0, 0, 3390.31005859375, -3387.4599609375, 143.0973358154296875, 0.610865235328674316, 7200, 0, 0, 1604, 0, 0, 0, 0, 0, 15595), -- Pack Mule (Area: Stratholme - Difficulty: 0)
(@CGUID+2, 45200, 329, 2017, 2017, 1, 169, 0, 0, 0, 3401.85009765625, -3379.739990234375, 142.7303314208984375, 3.176499128341674804, 7200, 0, 0, 175300, 4675, 0, 0, 0, 0, 15595), -- Crusade Commander Eligor Dawnbringer (Area: Stratholme - Difficulty: 0)
(@CGUID+3, 45201, 329, 2017, 2017, 1, 169, 0, 0, 0, 3399.610107421875, -3372.3798828125, 142.7653350830078125, 4.049163818359375, 7200, 0, 0, 83900, 0, 0, 0, 0, 0, 15595), -- Master Craftsman Wilhelm (Area: Stratholme - Difficulty: 0)
-- second wing
(@CGUID+4, 45328, 329, 2017, 5917, 1, 169, 0, 0, 0, 3617.89990234375, -3641.97998046875, 138.59332275390625, 4.258603572845458984, 7200, 0, 0, 33528, 0, 0, 0, 0, 0, 15595), -- Packmaster Stonebruiser (Area: Stratholme - Service Entrance - Difficulty: 0)
(@CGUID+5, 45329, 329, 2017, 5917, 1, 169, 0, 0, 0, 3682.179931640625, -3646.280029296875, 140.7213287353515625, 2.129301786422729492, 7200, 0, 0, 192830, 4675, 0, 0, 0, 0, 15595), -- Crusade Commander Eligor Dawnbringer (Area: Stratholme - Service Entrance - Difficulty: 0)
(@CGUID+6, 45330, 329, 2017, 5917, 1, 169, 0, 0, 0, 3682.760009765625, -3636.8798828125, 140.0263214111328125, 3.124139308929443359, 7200, 0, 0, 109070, 26340, 0, 0, 0, 0, 15595), -- Archmage Angela Dosantos (Area: Stratholme - Service Entrance - Difficulty: 0) (Auras: 79344 - Cosmetic - Mage Shattershield)
(@CGUID+7, 45325, 329, 2017, 5917, 1, 169, 0, 0, 0, 3611.81005859375, -3651.330078125, 138.594329833984375, 0.418879032135009765, 7200, 0, 0, 1604, 0, 0, 0, 0, 0, 15595), -- Pack Mule (Area: Stratholme - Service Entrance - Difficulty: 0)
(@CGUID+8, 45331, 329, 2017, 5917, 1, 169, 0, 0, 0, 3679.2900390625, -3652.4599609375, 140.7213287353515625, 3.769911050796508789, 7200, 0, 0, 83900, 0, 0, 0, 0, 0, 15595); -- Master Craftsman Wilhelm (Area: Stratholme - Service Entrance - Difficulty: 0)

-- remove deprecated spawns
DELETE FROM `creature` WHERE `guid` IN (53297);
DELETE FROM `creature_addon` WHERE `guid` IN (53297);

 -- Archmage Angela Dosantos
SET @ENTRY := 45330;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 79344, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Cosmetic - Mage Shattershield (79344) on Self");
