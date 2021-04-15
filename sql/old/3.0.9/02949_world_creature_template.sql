INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4) VALUES
(15352, 36213, 0, 0, 0), # Greater Earth Elemental
(15438, 57984, 12470, 13376, 0), # Greater Fire Elemental
(29264, 58861, 58875, 58867, 58857), # Spirit Wolf
(510, 31707, 33395, 0, 0) # Water Elemental
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4);
