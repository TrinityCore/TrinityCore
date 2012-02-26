DELETE FROM creature_ai_scripts WHERE id = 1527403;
INSERT INTO creature_ai_scripts VALUES (1527403, 15274, 0, 0, 100, 1, 5600, 9400, 11100, 24100, 11, 25602, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Mana Wyrm - Cast Faerie Fire");
UPDATE creature_model_info SET combat_reach = 0.5 WHERE modelid = 16217;
