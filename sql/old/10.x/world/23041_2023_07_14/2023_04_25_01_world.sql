-- Cragmaw the Infested
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_cragmaw_the_infested' WHERE `entry` = 131817;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cragmaw_blood_tick' WHERE `entry` = 132051;
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 132080;

UPDATE `creature_template_addon` SET `Emote` = 0, `auras` = '' WHERE `entry` = 131817;

UPDATE `creature_template` SET `faction`=16, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=132051; -- Blood Tick
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=17301505 WHERE `entry`=132080; -- Blood Tick Larva

DELETE FROM `creature` WHERE `guid` = 850807;
DELETE FROM `creature_addon` WHERE `guid` = 850807;

DELETE FROM `creature_template_addon` WHERE `entry` = (132051 /*132051 (Blood Tick) - Blood Burst*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(132051, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '278641 260768'); -- 132051 (Blood Tick) - Blood Burst

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`IsServerSide`=0 AND `Id` IN (17026,17014));
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(17026, 0, 0, 4, 1.35000002384185791, 1.35000002384185791, 0, 0, 0, 0, 0, 0, 48999),
(17014, 0, 1, 4, 2.5, 2.5, 7.5, 2.5, 2.5, 7.5, 0, 0, 48999);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (12334 /*SpellId : 260411*/, 12319 /*SpellId : 260292*/);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(12334, 17026, 0, 0, 0, 0, -1, 0, 0, 0, 12000, 0, 1.35000002384185791, 1.35000002384185791, 0, 0, 0, 0, 0, 0, 48999), -- SpellId : 260411 (Summon Larva)
(12319, 17014, 0, 0, 0, 0, -1, 0, 0, 0, 10000, 1, 2.5, 2.5, 7.5, 2.5, 2.5, 7.5, 0, 0, 48999); -- SpellId : 260292 (Charge)

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'at_cragmaw_destroy_larva' WHERE `Id` = 12334 AND `AreaTriggerId` = 17026;

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = 17014 AND `IsServerSide` = 0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES 
(17014, 0, 0, 260312, 2);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=23 AND `Entry` IN (132051,132080,140593));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(132051, 23, 0, 0, 502, 48999),
(132080, 23, 0, 0, 502, 48999),
(140593, 23, 2, 2, 502, 48999);

 -- Creature 132080 smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 132080;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = 132080;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(132080, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 260416, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSummon - Self: Cast spell 260416 with flags triggered on Self'),
(132080, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 260411, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSummon - Self: Cast spell 260411 with flags triggered on Self');

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (271775, 260416, 159474, 278641, 260411);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(271775, 'spell_cragmaw_power_energize_tantrum'),
(260416, 'spell_cragmaw_larva_metamorphosis'),
(159474, 'spell_gen_feign_death_all_flags_uninteractible'),
(278641, 'spell_cragmaw_blood_burst'),
(260411, 'spell_cragmaw_summon_larva');
