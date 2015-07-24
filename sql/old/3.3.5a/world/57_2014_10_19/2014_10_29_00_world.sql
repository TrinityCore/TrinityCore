-- Spell difficulty entry for Slag Pot Damage spell
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 65722;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(65722, 65722, 65723, 0, 0);

-- Clean up unneeded criteria data, enables achievement Hot Pocket
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10430, 10431) AND `type` = 18;
