-- Update Addon
DELETE FROM `creature_addon` WHERE `guid` IN (295429, 295430, 295436);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(295429, 0, 0, 0, 0, 0, 2, 1, 214, 0, 0, 0, 0, ''), -- Fledgling Brave
(295430, 0, 0, 0, 0, 0, 2, 1, 214, 0, 0, 0, 0, ''), -- Fledgling Brave
(295436, 0, 0, 0, 0, 0, 2, 1, 214, 0, 0, 0, 0, ''); -- Fledgling Brave

-- Set StringID
UPDATE `creature` SET `StringId` = "ShootGun" WHERE `guid` IN (295429, 295430, 295436);

-- Update Template
UPDATE `creature_template` SET `unit_flags`=0x0, `VehicleId`=584 WHERE `entry`=36942; -- Fledgling Brave

-- override StaticFlags
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (295429, 295430, 295436);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(295429, 0, 0x02000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(295430, 0, 0x02000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(295436, 0, 0x02000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

 -- Fledgling Brave smart ai
SET @ENTRY := 36942;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 3000, 1000, 3000, 0, 11, 81502, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 1 - 3 seconds (IC) - Self: Cast spell  81502 on Victim', ''),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 8000, 8000, 0, 11, 81500, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 8 seconds (IC) - Self: Cast spell  81500 on Self', ''),
(@ENTRY, 0, 2, 0, 1, 0, 100, 0, 4000, 8000, 4000, 8000, 0, 11, 70092, 0, 0, 0, 0, 0, 0, 19, 37162, 5, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds (OOC) - Self: Cast spell  70092 on Closest alive creature Romo\'s Half-Size Bunny (37162) in 5 yards', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 36942 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 3, 36942, 0, 0, 58, 1, 0, 0, 0, 'ShootGun', 0, 'Action invoker has StringID ShootGun');
