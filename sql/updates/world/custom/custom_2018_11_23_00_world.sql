UPDATE `creature_template_addon` SET `bytes1`= 1 WHERE `entry`= 50260;
UPDATE `creature_addon` SET `bytes1`= 1 WHERE `guid` IN (255672, 255673, 255674, 255675, 255617, 255493, 255492, 255491, 255490, 255489, 255451, 255448, 255498, 255496, 255497, 255499, 255500, 255502, 255503, 255504, 255505, 255507, 255627, 255625, 255444, 255438, 255616, 255618, 255435, 255615, 255633, 255637, 255609, 255638, 255614, 255613, 255612, 255611, 255610, 255671, 376970, 376969, 376968, 376967, 376964, 376965, 376966, 376961, 376960, 376825, 376823, 376822, 376821, 376820, 376819, 376818, 376817, 376816, 376802, 376803, 376804, 376798, 376799, 376800, 376801, 376796, 376797, 376652, 376651, 376649, 376650, 376648, 376637, 376633, 376634, 376635, 376636, 376629, 376630, 376631, 376632, 376607, 376603, 376604, 376605, 376606, 376601, 376576, 376573, 376477, 376476, 376475, 376474, 376473, 376471, 376472, 376470, 376469, 376415, 376332, 376322, 376314, 376309, 376302, 376298, 376294, 376292, 255898, 255900, 255901, 255902, 255906, 255910, 255912, 255916, 255917, 255920, 255926, 255932, 255933, 255934, 255935, 255936, 255938, 255939, 255940, 255941, 255942, 255943, 255944, 255945, 255946, 255965, 255966, 255967, 255968, 255969, 255970, 255971, 255972, 255973, 255974, 255976, 255978, 255980);

DELETE FROM `conditions` WHERE `SourceEntry` IN (93275, 69123) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 93275, 0, 0, 31, 0, 3, 50260, 0, 0, 0, '', 'Ping Gilnean Crow - Target Gilnean Crow'),
(13, 1, 69123, 0, 0, 31, 0, 3, 36198, 0, 0, 0, '', 'Curse of the Worgen - Target Generic Trigger LAB (Multiphase - Ground)');

UPDATE `creature_template` SET `ScriptName`= 'npc_gilnean_crow', `InhabitType`= 4 WHERE `entry`= 50260;
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 35006;
-- Creature Lord Darius Crowley 35566 SAI
SET @ENTRY := 35566;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14222, 0, 0, 0, 85, 98274, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest Last Stand (14222) - Invoker: Cast spell 98274 to Action invoker // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 72788, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell 72788 to Action invoker // ");

DELETE FROM `creature` WHERE `guid` IN (376477, 376476, 376475, 376473, 376474);
DELETE FROM `creature_addon` WHERE `guid` IN (376477, 376476, 376475, 376473, 376474);

DELETE FROM `spell_area` WHERE `spell`= 68630 AND `area`= 4786;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(68630, 4786, 0, 14375, 0, 0, 2, 1, 0, 1 | 2 | 8 | 32);

DELETE FROM `spell_target_position` WHERE `ID`= 69123;
