DELETE FROM `disables` WHERE `entry` IN (3368,3369,3370,3371,7623,12578,3684,5529,5512,5530,5531,5532,5533,5534,5535,9165,9166,5536,5537,5538,5539,5540,13254,5541,5542,5543,5544,5545,5546,5547,5548,7573,7574,10619,10620,11497,11498,11500,11501,12178,12179,12181,12182,13255) AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3368,3369,3370,3371,7623,12578,3684,5529,5512,5530,5531,5532,5533,5534,5535,9165,9166,5536,5537,5538,5539,5540,13254,5541,5542,5543,5544,5545,5546,5547,5548,7573,7574,10619,10620,11497,11498,11500,11501,12178,12179,12181,12182,13255);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(3368,0,0,0,''), -- Alterac Valley
(3369,0,0,0,''), -- Arathi Basin
(3370,0,0,0,''), -- Eye of the Storm
(3371,0,0,0,''), -- Warsong Gulch
(7623,0,0,0,''), -- Strand of the Ancients
(12578,0,0,0,''), -- Isle of Conquest
(3684,7,23505,0,''), -- Berserking killing blow
(5529,0,0,0,''), -- Total Killing Blows
(5512,20,0,0,''), -- Eastern Kingdoms
(5530,20,1,0,''), -- Kalimdor
(5531,20,530,0,''), -- Burning Crusade Areas
(5532,20,571,0,''), -- Northrend
(5533,20,559,0,''), -- Nagrand Arena
(5534,20,562,0,''), -- Blade's Edge Arena
(5535,20,572,0,''), -- Ruind of Lordaeron
(9165,20,617,0,''), -- Dalaran Sewers
(9166,20,618,0,''), -- Ring of Valor
(5536,20,30,0,''), -- Alterac Valley
(5537,20,529,0,''), -- Arathi Basin
(5538,20,489,0,''), -- Warsong Gulch
(5539,20,566,0,''), -- Eye of the Storm
(5540,20,607,0,''), -- Strand of the Ancients
(13254,20,628,0,''), -- Isle of Conquest
(5541,11,0,0,'achievement_arena_2v2_kills'), -- 2v2 Arena Killing Blows
(5542,11,0,0,'achievement_arena_3v3_kills'), -- 3v3 Arena Killing Blows
(5543,11,0,0,'achievement_arena_5v5_kills'), -- 5v5 Arena Killing Blows
(5544,20,30,0,''), -- Alterac Valley Killing Blows
(5545,20,529,0,''), -- Arathi Basin Killing Blows
(5546,20,489,0,''), -- Warsong Gulch Killing Blows
(5547,20,566,0,''), -- Eye of the Storm Killing Blows
(5548,20,607,0,''), -- Strand of the Ancients Killing Blows
(7573,1,30249,0,''), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7573,11,0,0,'achievement_denyin_the_scion'), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7574,1,30249,0,''), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7574,11,0,0,'achievement_denyin_the_scion'), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(10619,1,33142,0,''), -- Leviathan Turret
(10620,1,33142,0,''), -- Leviathan Turret
(11497,1,35273,0,''), -- Glaive Thrower
(11498,1,34775,0,''), -- Demolisher
(11500,1,34793,0,''), -- Catapult
(11501,1,35069,0,''), -- Siege Engine
(12178,1,34802,0,''), -- Glaive Thrower
(12179,1,34775,0,''), -- Demolisher
(12181,1,34793,0,''), -- Catapult
(12182,1,34776,0,''), -- Siege Engine
(13255,20,628,0,''); -- Isle of Conquest Killing Blows
