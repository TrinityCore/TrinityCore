--
SET @CGUID := 76305;

UPDATE `creature_template` SET `AIName`= 'SmartAI',`flags_extra`=`flags_extra`|128,`unit_flags`=33554432 WHERE `entry`  IN(23040,23081);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID, 23040, 530, 1, 1, 0, 0, 3261.86, 4625.63, 216.751, 0.680678, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
(@CGUID+1, 23040, 530, 1, 1, 0, 0, 3257.33, 4653.79, 216.73, 5.75959, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
(@CGUID+2, 23040, 530, 1, 1, 0, 0, 3304.42, 4643.83, 217.281, 3.28122, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
(@CGUID+3, 23040, 530, 1, 1, 0, 0, 3279.39, 4664.33, 216.778, 4.76475, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
(@CGUID+4, 23040, 530, 1, 1, 0, 0, 3292.61, 4619.95, 217.272, 2.1293, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
(@CGUID+5, 23081, 530, 1, 1, 0, 0, 3279.73, 4640.09, 216.526, 4.08274, 120, 0, 0, 1, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=130 WHERE  `entry`=23081;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23040, 0, 0, 0, 1,  0, 100, 0, 0, 0, 4000, 4000, 11, 39853, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vim gols Circle Bunny - On Update OOC  - Cast Vim gol: Summon Circle Popluation Tester D'),
(23040, 0, 1, 0, 31,  0, 100, 0, 39853, 0, 0, 0, 45, 1 , 1, 0, 0, 0, 0, 19, 23081, 50, 0, 0, 0, 0, 0, 'Vim gols Circle Bunny: On SpellHitTester A - set data for summon bunny');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23081;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23081, 0, 0, 1, 38,  0, 100, 0, 1, 1, 60000, 60000, 11, 39921, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vim gols Summon Bunny - On data set  - Cast pentagram beam'),
(23081, 0, 1, 2, 61,  0, 100, 0, 0, 0, 0, 0, 67, 23081, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Linked with previous event - Create timed event'),
(23081, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Linked with previous event - Create timed event'),
(23081, 0, 3, 0, 59,  0, 100, 0, 23081, 0, 0, 0, 12, 22911, 2, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed event - Summon Vimgol');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 39921;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 39921, 0, 0, 31, 0, 3, 23081, 0, 0, 0, 0, '', 'pentagram only hits summon bunny'),
(13, 1, 39921, 0, 1, 31, 0, 3, 23040, 0, 0, 0, 0, '', 'pentagram only hits circle bunny');

DELETE FROM `creature_text` WHERE `entry`=22911;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(22911, 0, 0, 'You dare summon me?', 14, 0, 100, 15, 0, 0, 'Vim\'gol the Vile', 20733);
(22911, 1, 0, 'Now me grow bigger and crush you!', 14, 0, 100, 0, 0, 0, 'Vim\'gol the Vile', 21264);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=22911;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22911;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22911, 0, 0, 0, 4,  0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vim'gol the Vile - On Agro Say"),
(22911, 0, 1, 0, 6,  0, 100, 0, 0, 0, 0, 0, 11, 39862, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vim'gol the Vile - On Death - Cast Vim'gol: Summon Vim'gol's Vile Grimoire Chest"),
(22911, 0, 2, 0, 2,  0, 100, 1, 0, 50, 60000, 60000, 11, 40545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vim'gol the Vile - On 50% HP - Cast Unholy Growth (No repeat)"),
(22911, 0, 3, 0, 23,  0, 100, 1, 40545, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vim'gol the Vile - On 50% HP - Cast Unholy Growth (No repeat)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23040;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 2, 23040, 0, 0, 9, 0, 10998, 0, 0, 0, 0, 0, '', 'Execute SAI only if player is on Grim(oire) Business'),
(22, 2, 23040, 0, 0, 29, 1, 22911, 200, 0, 1, 0, 0, '', 'Execute SAI only if Vim Gol is not already spawned');
