DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN 3200 AND 3206;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`)
VALUES
(3200,64389,64678,0,0), -- Auriaya - Sentinel Blast
(3201,64422,64688,0,0), -- Auriaya - Sonic Screech
(3202,64496,64674,0,0), -- Auriaya/Feral Defender - Feral Rush
(3203,64478,64669,0,0), -- Auriaya/Feral Defender - Feral Pounce
(3204,64458,64676,0,0), -- Auriaya/Feral Defender - Seeping Essence
(3205,64666,64374,0,0), -- Auriaya/Sanctum Sentry - Savage Pounce
(3206,64375,64667,0,0); -- Auriaya/Sanctum Sentry - Rip Flesh
