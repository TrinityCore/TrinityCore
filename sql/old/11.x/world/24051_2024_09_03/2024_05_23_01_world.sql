SET @CGUID := 7000524;

DELETE FROM `phase_name` WHERE `ID`=12612;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12612, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater, Hurricane and Elementals at Port Fogtide Bridge');

DELETE FROM `phase_area` WHERE `PhaseId`=12612;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9579, 12612, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater, Hurricane and Elementals at Port Fogtide Bridge - Tidecross'),
(9578, 12612, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater, Hurricane and Elementals at Port Fogtide Bridge - Port Fogtide'),
(9622, 12612, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater, Hurricane and Elementals at Port Fogtide Bridge - Krakens Reach');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12612));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12612, 0, 0, 0, 47, 0, 54721, 74, 0, '', 0, 'Player has I\'m Too Old for This Ship (54721) in state complete, incomplete, rewarded'),
(26, 12612, 0, 0, 0, 47, 0, 54726, 74, 0, '', 1, 'Player doesn\'t have Frame Work (54726) in state complete, incomplete, rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 148879, 1643, 9042, 9579, '0', 12612, 0, 0, 0, 3372.8203125, -408.057281494140625, 11.97694587707519531, 5.568043231964111328, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Bound Earth (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+1, 148870, 1643, 9042, 9579, '0', 12612, 0, 0, 0, 3370.701416015625, -410.111114501953125, 11.97694587707519531, 5.603581905364990234, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Dorian Atwater (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+2, 148879, 1643, 9042, 9579, '0', 12612, 0, 0, 0, 3368.6796875, -412.024322509765625, 11.97694587707519531, 5.571819782257080078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Bound Earth (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+3, 150706, 1643, 9042, 9579, '0', 12612, 0, 0, 0, 3366.2978515625, -416.62152099609375, 11.97694587707519531, 5.707256317138671875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Hurricane (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: 291989 - Carrying Toolbox)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '291989'); -- Hurricane - 291989 - Carrying Toolbox

UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `VehicleId`=6542 WHERE `entry`=150706; -- Hurricane
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=148879; -- Bound Earth
UPDATE `creature_template` SET `faction`=2992, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=148870; -- Dorian Atwater

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=0x10000000, `VerifiedBuild`=54762 WHERE (`Entry`=148870 AND `DifficultyID`=0); -- 148870 (Dorian Atwater) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=0x10000000, `VerifiedBuild`=54762 WHERE (`Entry`=148879 AND `DifficultyID`=0); -- 148879 (Bound Earth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=0x10000000, `VerifiedBuild`=54762 WHERE (`Entry`=150706 AND `DifficultyID`=0); -- 150706 (Hurricane) - CanSwim

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=149374;

UPDATE `creature` SET `PhaseId`=12612 WHERE `guid`=7000412;

 -- FX Stalker with guid 7000412 smart ai
SET @ENTRY := -7000412;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 149374;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 291988, 0, 0, 0, 0, 0, 19, 150706, 10, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  291988 on Closest alive creature Hurricane (150706) in 10 yards');
