UPDATE `gameobject_template` SET `flags` = `flags` | 32, `AIName` = 'SmartGameObjectAI' WHERE `entry` = 187267;

DELETE FROM `spell_script_names` WHERE `spell_id` = 45102;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45102, 'spell_love_is_in_the_air_romantic_picnic');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (45119, 45103, 45114);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 45119, 0, 0, 18, 0, 187267, 0, 0, '', 'Holiday - Valentine - Romantic Picnic Near Basket Check - Target Romantic Basket'),
(13, 0, 45103, 0, 0, 18, 1, 0, 0, 0, '', 'Holiday - Valentine - Romantic Picnic Meal Periodic - Target Players'),
(13, 0, 45114, 0, 0, 18, 1, 0, 0, 0, '', 'Holiday - Valentine - Romantic Picnic Meal Particle - Target Players');

DELETE FROM `smart_scripts` WHERE `entryorguid`=187267 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(187267, 1, 0, 0, 60, 0, 100, 0, 3*60*1000, 3*60*1000, 0, 0, 99, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Picnic Basket - Despawn after 3 minutes');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (1291,5787,4071);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(5787, 6, 4395, 0, ''), -- Lonely? - Dalaran
(4071, 6, 4395, 0, ''); -- Lonely? - Dalaran
