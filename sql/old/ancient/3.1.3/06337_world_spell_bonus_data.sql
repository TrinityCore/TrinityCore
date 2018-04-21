DELETE FROM spell_bonus_data WHERE entry IN (47757, 52986, 52987, 52988); -- Old Penance in DB
DELETE FROM spell_bonus_data WHERE entry IN (47750, 52983, 52954, 58985, 47666, 52998, 52999, 53000);
INSERT INTO spell_bonus_data (entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus, comments) VALUES
(47750, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 1)'),
(52983, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 2)'),
(52954, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 3)'),
(58985, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 4)'),
(47666, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 1)'),
(52998, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 2)'),
(52999, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 3)'),
(53000, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 4)');
