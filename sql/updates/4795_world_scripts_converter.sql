INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8) VALUES
(29987, 55645, 0, 0, 0, 0, 0, 0, 27892), # Unrelenting Trainee (H)
(29985, 27825, 0, 0, 0, 0, 0, 0, 27928), # Unrelenting Death Knight (H)
(29986, 55638, 55608, 0, 0, 0, 0, 0, 27935) # Unrelenting Rider (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4),
spell5 = VALUES(spell5),
spell6 = VALUES(spell6),
spell7 = VALUES(spell7),
spell8 = VALUES(spell8);