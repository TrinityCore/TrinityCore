-- 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(26560);
UPDATE `smart_scripts` SET `action_type`=69 , `action_param4`=1, `target_type`=19, `target_param1`=29542, `target_param2`=40, `target_param3`=1, `target_y`=0 WHERE `entryorguid` IN (2956000) AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=66 , `action_param4`=0, `target_type`=19, `target_param1`=29542, `target_param2`=40, `target_param3`=1 WHERE `entryorguid` IN (2956000) AND `source_type`=9 AND `id`=2;
DELETE FROM `smart_scripts`   WHERE `entryorguid` IN (2956000) AND `source_type`=9  AND `id` IN (19,20);
DELETE FROM `smart_scripts`   WHERE `entryorguid` IN (29560) AND `source_type`=0  AND `id` IN (4);
DELETE FROM  `smart_scripts` WHERE `entryorguid` IN (19157900,2957200) AND `source_type`=9 ;
DELETE FROM  `smart_scripts` WHERE `entryorguid` IN (191579) AND `source_type`=1 ;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2956000, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 191579, 0, 0, 0, 0, 0, 0, "Lord-Commander Arete - On Script - Despawn "),
(2956000, 9, 20, 0, 0, 0, 100, 0, 500, 500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lord-Commander Arete - On Script - Despawn "),
(29560, 0, 4, 0, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lord-Commander Arete - On just created - set run off "),
(191579, 1, 0, 0, 60, 0, 100, 1, 4000, 4000, 0, 0, 11, 18280, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arete's Gate - On upadte - activat gob"),
(2957200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 29560, 20, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Set Orientation Closest Creature 'Lord-Commander Arete'"),
(2957200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 36545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Cast 'Floating Drowned'"),
(2957200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - set run off"),
(2957200, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, "Landgren's Soul - On Script - Move offset"),
(2957200, 9, 4, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Say Line 0"),
(2957200, 9, 5, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Say Line 1"),
(2957200, 9, 6, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Say Line 2"),
(2957200, 9, 7, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Say Line 3"),
(2957200, 9, 8, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Say Line 4"),
(2957200, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Cast 'Arcane Explosion Visual'"),
(2957200, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Landgren's Soul - On Script - Despawn Instant");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 17 AND SourceEntry = 26560;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`, `NegativeCondition`) VALUES
(17, 0, 26560, 0, 29, 0, 29542, 5, 1, 0, '', "'Spell Summon Arete's Gate'", 0),
(17, 0, 26560, 0, 30, 0, 191579, 30, 0, 0, '', "'Spell Summon Arete's Gate'", 1);
