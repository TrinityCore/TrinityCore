DELETE FROM `creature` WHERE `guid` IN (38043, 38045, 48641);
DELETE FROM `creature_addon` WHERE `guid` IN (38043, 38045, 48641);

SET @CGUID := 253850;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 53488, 389, 2437, 0, 1, 169, 0, 0, 0, -18.6087303161621093, -63.83367919921875, -21.2950592041015625, 4.590215682983398437, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+1, 53488, 389, 2437, 0, 1, 169, 0, 0, 0, -18.6087303161621093, -63.83367919921875, -21.2950592041015625, 4.590215682983398437, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+2, 53488, 389, 2437, 0, 1, 169, 0, 0, 0, 0.903475463390350341, -14.5965547561645507, -17.4777889251708984, 4.590215682983398437, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+3, 53488, 389, 2437, 0, 1, 169, 0, 0, 0, -5.25880289077758789, -39.7717170715332031, -21.7566337585449218, 4.590215682983398437, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+4, 44223, 389, 2437, 0, 1, 169, 0, 0, 0, -20.3927993774414062, -41.9908981323242187, -21.6314659118652343, 2.914699792861938476, 7200, 0, 0, 656, 0, 0, 0, 0, 0, 15595), -- Orgrimmar Defender (Area: 0 - Difficulty: 0)
(@CGUID+5, 44223, 389, 2437, 0, 1, 169, 0, 0, 0, -7.19542980194091796, -39.0069999694824218, -21.6336650848388671, 3.787364482879638671, 7200, 0, 0, 600, 0, 0, 0, 0, 0, 15595), -- Orgrimmar Defender (Area: 0 - Difficulty: 0)
(@CGUID+6, 44223, 389, 2437, 0, 1, 169, 0, 0, 0, -34.8027992248535156, -59.6866989135742187, -21.2881660461425781, 2.321287870407104492, 7200, 0, 0, 600, 0, 0, 0, 0, 0, 15595), -- Orgrimmar Defender (Area: 0 - Difficulty: 0)
(@CGUID+7, 44223, 389, 2437, 0, 1, 169, 0, 0, 0, -2.73776006698608398, -44.3330001831054687, -21.7803668975830078, 3.892084121704101562, 7200, 0, 0, 656, 0, 0, 0, 0, 0, 15595), -- Orgrimmar Defender (Area: 0 - Difficulty: 0)
(@CGUID+8, 44216, 389, 2437, 0, 1, 169, 0, 0, 0, -16.4137992858886718, -67.8301010131835937, -21.315866470336914, 2.443460941314697265, 7200, 0, 0, 765, 0, 0, 0, 0, 0, 15595), -- Bovaal Whitehorn (Area: 0 - Difficulty: 0) (Auras: 28892 - Nature Channeling)
(@CGUID+9, 44217, 389, 2437, 0, 1, 169, 0, 0, 0, -18.9470996856689453, -54.3344001770019531, -21.4601669311523437, 2.58308720588684082, 7200, 0, 0, 1216, 0, 0, 0, 0, 0, 15595); -- Stone Guard Kurjack (Area: 0 - Difficulty: 0)

-- Creature Bovaal Whitehorn 44216 SAI
SET @ENTRY := 44216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Nature Channeling (28892) on Self // ");

UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x2 WHERE `entry` IN (44223, 44216, 44217);

SET @GROUPID := 456;
DELETE FROM `spawn_group_template` WHERE `groupId`= @GROUPID;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@GROUPID, 'Ragefire Chasm - Horde Spawns', 4);

DELETE FROM `spawn_group` WHERE `groupId`= @GROUPID;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@GROUPID, 0, @CGUID+4),
(@GROUPID, 0, @CGUID+5),
(@GROUPID, 0, @CGUID+6),
(@GROUPID, 0, @CGUID+7),
(@GROUPID, 0, @CGUID+8),
(@GROUPID, 0, @CGUID+9);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= @GROUPID;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(389, 0, 31, @GROUPID, 0x1 | 0x8);

UPDATE `creature` SET `position_x`= -276.77593994140625, `position_y`= -64.8439254760742187, `position_z`= -60.4399681091308593, `orientation`= 2.553579330444335937, `MovementType`= 1, `spawndist`= 6 WHERE `guid`= 48644;
