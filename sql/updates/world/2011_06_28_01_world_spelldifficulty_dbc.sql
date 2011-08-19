DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN 3251 AND 3261;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`)
VALUES
-- Steelbreaker
(3251,61980,63498,0,0),
(3252,61903,63493,0,0),
(3253,44008,63494,0,0),
(3254,64637,61888,0,0),
-- Runemaster Molgeim
(3255,62274,63489,0,0),
(3256,62277,63967,0,0),
(3257,62052,63492,0,0),
-- Stormcaller Brundir
(3258,61879,63479,0,0),
(3259,61869,63481,0,0),
(3260,61915,63483,0,0),
(3261,61887,63486,0,0);
