DELETE FROM `creature_template_movement` WHERE `CreatureId`= 38055;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(38055, 0, 1, 0, 1);

SET @OGUID := 239777;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(@OGUID+0, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3172.524, -2213.277, 99.873,  0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+1, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3173.970, -2224.622, 103.012, 0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+2, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3181.503, -2233.236, 102.950, 0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+3, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3191.787, -2220.257, 99.567,  0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+4, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3126.423, -2185.019, 101.845, 0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+5, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3139.430, -2173.053, 104.464, 0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+6, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3124.032, -2175.558, 104.858, 0, 0, 0, 0, 1, 0, 0, 1, '', 0),
(@OGUID+7, 201943, 1, 0, 0, 1, 0, 0, 0, -1, -3110.275, -2187.401, 103.345, 0, 0, 0, 0, 1, 0, 0, 1, '', 0);

UPDATE `creature` SET `modelid`= 17612 WHERE `guid` IN (298819, 298820, 298860, 298861, 298862, 298864, 298865, 298871, 298872, 298873, 298874, 298891, 298892, 298893, 299022, 299024, 299025, 299026, 299051, 299052, 299053, 299054);

 -- Silithid Mound Bunny smart ai
SET @ENTRY := 38055;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 71030, 0, 60000, 60000, 85, 52855, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell Burning Pitch (71030) hit (wait 60000 - 60000 ms before next trigger) - Self: Cast spell Cosmetic - Low Poly Fire (with Sound) (52855) on self'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 71062, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell Burning Pitch (71030) hit (wait 60000 - 60000 ms before next trigger) - Self: Cast spell Force Player to Summon Silithid Swarmer (71062) on Caster'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 60000, 60000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spell Burning Pitch (71030) hit (wait 60000 - 60000 ms before next trigger) - Trigger timed event timedEvent[1] in 60000 - 60000 ms // -meta_wait'),
(@ENTRY, 0, 3, 0, 59, 0, 100, 0, 1, 0, 0, 0, 28, 52855, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Remove aura due to spell Cosmetic - Low Poly Fire (with Sound) (52855)');

DELETE FROM `conditions` WHERE `SourceEntry`= 71030 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 71030, 0, 0, 31, 0, 3, 38055, 0, 0, 0, '', 'Burning Pitch - Target Silithid Mound Bunny');
