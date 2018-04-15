DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19723,19724) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19723, 0, 0, 1, 8, 0, 100, 1, 34526, 0, 0, 0, 80, 1972300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis BE Ballista - On Spellhit - Run Script'),
(19723, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 19723, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis BE Ballista - On Spellhit (Link) - Quest Credit'),
(19724, 0, 0, 1, 8, 0, 100, 1, 34526, 0, 0, 0, 80, 1972400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis BE Tent - On Spellhit - Run Script'),
(19724, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 19724, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis BE Tent - On Spellhit (Link) - Quest Credit');
