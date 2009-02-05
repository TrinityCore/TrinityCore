DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000247 and -1000245;
INSERT INTO `script_texts` (entry, content_default, type, comment) VALUES
(-1000245, 'You, there! Hand over that moonstone and nobody gets hurt!', 1, 'SAY_RIZZLE_START'),
(-1000246, 'Just chill!', 4, 'SAY_RIZZLE_GRENADE'),
(-1000247, 'All right, you win! I surrender! Just don\'t hurt me!', 1, 'SAY_RIZZLE_FINAL');