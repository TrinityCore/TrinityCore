-- 
UPDATE `smart_scripts` SET `action_type`=1, `comment`="Scarlet Onslaught Prisoner - On Spellhit 'Flask of Blight' - Say Line 0" WHERE `entryorguid`=27349 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000 WHERE `entryorguid`=27250 AND `id`=3;
UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE `entryorguid`=27248 AND `id`=0 AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=27248 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27248, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - On reset - Set event phase 1");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2724800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2724800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Set event phase 2"),
(2724800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 106544, 27250, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - respawn target"),
(2724800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Set EmoteState 0"),
(2724800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 27250, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Set Orientation"),
(2724800, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 1"),
(2724800, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27250, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 1 (Junior Apothecary Schlemiel)"),
(2724800, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 2"),
(2724800, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 27250, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 2 (Junior Apothecary Schlemiel)"),
(2724800, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 3"),
(2724800, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 48201, 0, 0, 0, 0, 0, 19, 27250, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Cast Throw Blight"),
(2724800, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 4"),
(2724800, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Say Line 5"),
(2724800, 9, 12, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.635450, "Apothecary Vicky Levine - Script - Reset Orientation"),
(2724800, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Set EmoteState 133"),
(2724800, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Vicky Levine - Script - Set event phase 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48201;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=48188;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 48201, 0, 0, 31, 0, 3, 27250, 0, 0, 0, 0, "", "Spell 'Throw Blight' targets 'Junior Apothecary Schlemiel'"),
(17, 0, 48188, 0, 0, 29, 0, 27349, 3, 0, 0, 0, 0, "", "Spell 'Flask of Blight' can only be used within 3 yards of 'Scarlet Onslaught Prisoner'");
