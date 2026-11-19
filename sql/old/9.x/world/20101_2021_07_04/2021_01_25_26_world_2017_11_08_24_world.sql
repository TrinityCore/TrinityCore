--
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` BETWEEN 113768 AND 113772;
DELETE FROM `smart_scripts` WHERE (`entryorguid` BETWEEN 113768 AND 113772) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(113768, 1, 0, 0, 70, 0, 20, 0, 2, 0, 0, 0, 11, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brightly Colored Egg - On State Change - Cast 'Noblegarden Bunny'"),
(113769, 1, 0, 0, 70, 0, 20, 0, 2, 0, 0, 0, 11, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brightly Colored Egg - On State Change - Cast 'Noblegarden Bunny"),
(113770, 1, 0, 0, 70, 0, 20, 0, 2, 0, 0, 0, 11, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brightly Colored Egg - On State Change - Cast 'Noblegarden Bunny"),
(113771, 1, 0, 0, 70, 0, 20, 0, 2, 0, 0, 0, 11, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brightly Colored Egg - On State Change - Cast 'Noblegarden Bunny"),
(113772, 1, 0, 0, 70, 0, 20, 0, 2, 0, 0, 0, 11, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brightly Colored Egg - On State Change - Cast 'Noblegarden Bunny");
