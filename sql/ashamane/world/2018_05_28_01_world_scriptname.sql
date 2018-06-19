UPDATE creature_template SET unit_flags = 0 WHERE entry = 107544;
UPDATE creature_template_addon SET auras = "" WHERE entry = 107544;

DELETE FROM pool_template WHERE entry = 107544;
INSERT INTO pool_template VALUES
(107544, 1, "Nithogg Legion World Boss");

DELETE FROM pool_creature WHERE pool_entry = 107544;
INSERT INTO pool_creature VALUES
(20533575, 107544, 0, "Nithogg"),
(20543904, 107544, 0, "Nithogg"),
(20543907, 107544, 0, "Nithogg"),
(20543908, 107544, 0, "Nithogg"),
(20543909, 107544, 0, "Nithogg"),
(20543910, 107544, 0, "Nithogg");
