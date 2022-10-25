--
-- 
-- Silverpine Forest

SET @CGUID := 395718;

-- 
-- Deep Elem Mine
 
-- Detect: Quest Invis Zone 6
DELETE FROM `spell_area` WHERE `spell`=84450 AND `area`=213 AND `quest_start`=27194 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(84450, 213, 27194, 27195, 0, 0, 2, 3, 74, 11);

-- Veteran Forsaken Trooper
DELETE FROM `creature` WHERE `guid` IN (@CGUID+0, @CGUID+1, @CGUID+2, @CGUID+3, @CGUID+4, @CGUID+5, @CGUID+6);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 364.993, 1093.53, 106.096, 5.32325, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+1, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 372.582, 1096.04, 106.233, 4.97419, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+2, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 376.009, 1096.43, 106.276, 5.00909, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+3, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 373.549, 1098.99, 106.346, 4.97419, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+4, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 369.517, 1098.67, 106.282, 5.07891, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+5, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 365.075, 1097.21, 106.212, 5.27089, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+6, 45225, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 368.543, 1095.05, 106.191, 4.97419, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

-- Master Forteski
UPDATE `creature_template` SET `ScriptName`= 'npc_silverpine_master_forteski' WHERE `entry` = 45228;

DELETE FROM `creature` WHERE `guid` = @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+7, 45228, 0, 130, 213, '0', 0, 169, 0, -1, 0, 1, 368.99, 1102.56, 106.350, 5.16617, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_text` WHERE `CreatureID` = 45228;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(45228, 0, 0, "Ready then? Let\'s get a move on! Try and keep up, $n.", 12, 0, 100, 6, 0, 0, 0, 45386, 0, "Master Forteski"),
(45228, 1, 0, "Onward, brothers and sisters!", 12, 0, 100, 25, 0, 0, 0, 45387, 0, "Master Forteski"),
(45228, 2, 0, "What\'s this then?", 12, 0, 100, 6, 0, 0, 0, 45388, 0, "Master Forteski"),
(45228, 3, 0, "BOMB! IT'S A TRAP! RUN!", 14, 0, 100, 5, 0, 0, 0, 45391, 0, "Master Forteski"),
(45228, 4, 0, "Remember this day as the day that Forteski saved your hide. Now run! Get back to Sylvanas!", 12, 0, 100, 3, 0, 0, 0, 45394, 0, "Master Forteski");

UPDATE `creature_template_addon` SET `auras` = '84449' WHERE `entry` IN (45225, 45228);

DELETE FROM `waypoint_data` WHERE `id` = 452280;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(452280, 1, 379.951, 1067.22, 107.7871, NULL, 0, 1, 0, 0, 0),
(452280, 2, 382.743, 1057.77, 107.2116, NULL, 0, 1, 0, 0, 0),
(452280, 3, 388.151, 1045.16, 106.4566, NULL, 0, 1, 0, 0, 0),
(452280, 4, 395.875, 1039.82, 106.9294, NULL, 0, 1, 0, 0, 0),
(452280, 5, 408.738, 1036.37, 107.0776, NULL, 0, 1, 0, 0, 0),
(452280, 6, 414.747, 1028.35, 107.0137, NULL, 0, 1, 0, 0, 0),
(452280, 7, 412.75, 1017.73, 108.0727, NULL, 0, 1, 0, 0, 0),
(452280, 8, 408.139, 1006.64, 107.5482, NULL, 0, 1, 0, 0, 0);

-- Packleader Ivar Bloodfang
DELETE FROM `creature_text` WHERE `CreatureID` = 45236;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(45236, 0, 0, "Your doom!", 12, 0, 100, 11, 0, 0, 0, 45389, 0, "Packleader Ivar Bloodfang");

DELETE FROM `waypoint_data` WHERE `id` = 452360;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(452360, 0, 414.84198, 1028.08, 107.175674, NULL, 0, 1, 0, 0, 0),
(452360, 1, 410.59198, 1036.08, 107.175674, NULL, 0, 1, 0, 0, 0),
(452360, 2, 410.59198, 1036.08, 107.175674, NULL, 0, 1, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 84470 AND `ScriptName` = 'spell_gen_reverse_cast_target_to_caster_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84470, 'spell_gen_reverse_cast_target_to_caster_triggered');

DELETE FROM `spell_script_names` WHERE `spell_id` = 84467 AND `ScriptName` = 'spell_silverpine_toss_bomb';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84467, 'spell_silverpine_toss_bomb');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84467 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45237 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84467, 0, 0, 31, 0, 3, 45237, 0, 0, 0, 0, '', 'Toss Bomb - Target Bomb');

-- Bomb Wagon
UPDATE `gameobject` SET `spawntimesecs` = 10 WHERE `id` = 205271;