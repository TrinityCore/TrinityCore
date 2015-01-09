DELETE FROM `creature_ai_scripts` WHERE `creature_id`=17398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=17398;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN  (-85712,-85717,-85719,-85724);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-85724, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 29607, 0, 0, 0, 0, 0, 14, 22299, 0, 0, 0, 0, 0, 0, 'Blood Furnace - First Cell'),
(-85719, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 29607, 0, 0, 0, 0, 0, 14, 22297, 0, 0, 0, 0, 0, 0, 'Blood Furnace - Second Cell'),
(-85717, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 29607, 0, 0, 0, 0, 0, 14, 22298, 0, 0, 0, 0, 0, 0, 'Blood Furnace - Third Cell'),
(-85712, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 29607, 0, 0, 0, 0, 0, 14, 22296, 0, 0, 0, 0, 0, 0, 'Blood Furnace - Fourth Cell');

DELETE FROM `gameobject_scripts` WHERE `id`=150441;
INSERT INTO `gameobject_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(150441, 3, 11, 22295, 0, 0, 0, 0, 0, 0);
