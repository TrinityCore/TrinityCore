DELETE FROM `achievement_criteria_data` WHERE `criteria_id` in(6626,6627,6628,6629,6630);

INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(6626, 20, 30, 0, ''), -- Alterac Valley
(6627, 20, 529, 0, ''), -- Arathi Basin
(6628, 20, 489, 0, ''), -- Warsong Glutch
(6629, 20, 607, 0, ''), -- Strand of the Ancients
(6630, 20, 566, 0, ''); -- Eye of the Storm

