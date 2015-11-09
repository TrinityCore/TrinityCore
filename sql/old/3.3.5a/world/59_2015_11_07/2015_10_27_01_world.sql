    UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE  `entryorguid`=32257 AND `source_type`=0 AND `id` in(0,1,2);


    DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=32257 AND `id`>2;
    DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=3225700;
    DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=3214901;

    DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=32149 AND `id`=1;

    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32257, 0, 3, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - OOC - Set Phase 2'),
    (32257, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - On Agro - Set Phase 1'),
    (32257, 0, 5, 0, 75, 2,33, 0, 0, 32149, 40, 120000, 80, 3225700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - On Fallen Heros Spirit within 30 yards (Phase 2/5% Chance) - Run Script'),
    (32149, 0, 1, 0, 8, 0, 100, 1, 60231, 0, 0, 0, 80, 3214901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero\'s Spirit - On Spellhit "Grip of the Scourge" - Run Script'),
    (3214901, 9, 0, 0, 0, 0, 100, 0, 10, 10, 0, 0, 75, 60231, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Heros Spirit - Script - Add Aura Grip of the Scourge'),
    (3214901, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Heros Spirit - Script - Turn random movement off'),

    (3214901, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7464.0068, 2445.8369, 384.2378, 0, 'Fallen Heros Spirit - Script - Move to Position'),
    (3214901, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Heros Spirit - Script - Despawn'),
    (3225700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 60212, 64, 0, 0, 0, 0, 19, 32149, 0, 0, 0, 0, 0, 0, 'Scourge Converter - Script - Cast Grip of the Scourge');

    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=66719 AND  `ConditionTypeOrReference`=1;

    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
    (17, 0, 66719, 0, 0, 1, 1, 60231, 0, 0, 1, 0, 0, '', 'Blessing of Peace cannot be cast on unit with Grip of the Scourge');
