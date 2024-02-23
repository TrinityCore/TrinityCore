-- Honor Hold Archer
UPDATE `creature_template_addon` SET `SheathState`=2, `PvpFlags`=1 WHERE `entry`=16896;
UPDATE `creature_addon` SET `SheathState`=2, `PvpFlags`=1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16896);

UPDATE `creature_addon` SET `SheathState`=0 WHERE `guid` =58446;

DELETE FROM `creature_addon` WHERE `guid` IN (58443, 58444, 58445, 58447);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(58443, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, NULL),
(58444, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, NULL),
(58445, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, NULL),
(58447, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, NULL);

-- SAI
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = -58454);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-58454, 0, 0, 0, 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, 11, 33796, 0, 0, 0, 0, 0, 10, 69107, 19376, 0, 0, 0, 0, 0, 0, "Honor Hold Archer - Out of Combat - Cast 'Shoot Bow'");

-- Delete wrong condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `ConditionValue2` = 16898 AND `SourceEntry` = 33796;

-- ConditionTarget
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `ConditionValue2` = 19376 AND `SourceEntry` = 33796;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 33796, 0, 0, 31, 0, 3, 19376, 0, 0, 0, 0, '', 'Spell 33796 targets Honor Hold Target Dummy Tower');
