UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24497,24527,24510);
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=24527;
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=24510;


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 0, 0, 19, 0, 100, 0, 11409, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 1, 0, 20, 0, 100, 0, 11409, 0, 0, 0, 11, 44358, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 2, 0, 19, 0, 100, 0, 11412, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 3, 0, 20, 0, 100, 0, 11412, 0, 0, 0, 11, 44358, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram''');


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24527;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24527, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43660, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bok Dropcertain - Within 0-50 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24527;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24527, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', ''),
(22, 1, 24527, 0, 0, 2, 0, 33797, 1, 0, 1, 0, 0, '', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43662;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43662, 0, 0, 31, 0, 3, 24510, 0, 0, 0, 0, '', '');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24510;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24510, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43714, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Driz Tumblequick <Ram Racing Apprentice> - Within 0-50 Range - Cast ''Brewfest - Throw Keg - DND'''),
(24510, 0, 1, 0, 8, 0, 100, 0, 43662, 0, 0, 0, 85, 44601, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Driz Tumblequick <Ram Racing Apprentice> - On SpellHit - Cast ''Brewfest - Relay Race - Intro - Assign Kill Credit''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24510;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24510, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', ''),
(22, 1, 24510, 0, 0, 2, 0, 33797, 1, 0, 0, 0, 0, '', '');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (
43714,
43876 
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(43714, 'spell_brewfest_relay_race_intro_force_player_to_throw'),
(43876, 'spell_brewfest_dismount_ram');
