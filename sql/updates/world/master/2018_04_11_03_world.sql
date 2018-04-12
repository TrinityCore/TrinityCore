-- 
DELETE FROM `creature_equip_template` WHERE `ID`= 1 AND `CreatureID` IN ( 90417, 90418, 90431, 90463, 92183, 92457, 92489, 93520, 93536, 94197, 95844, 96444, 96698, 96708, 96770, 96771, 96772, 96778, 96779, 96780, 96785, 96786, 96791, 96792, 96793, 96801, 96802, 96803, 96804, 96809, 96944, 96945, 96946, 96947, 96948, 96949, 96950, 96951, 96952, 96953, 96954, 96955, 96956, 96957, 96958, 96959, 96960, 97012, 97141, 97213, 97359, 97359, 97493, 97500, 97513, 97515, 97533, 97586, 97756, 97756, 97792, 98723, 98724,100671,100671,101846,102266,103626,104091,105231,105339,106262,106263,106655,106930,107772,107968,108628,109387,109390,109554,110019,111243,111246,112079,112720,113779,113780,113781,113782,113783,113784,113785,113813,113873,114208,114232,115464,115465,115466,115468,116175,116323,118506,119226,119272,119486,119487,120687);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
( 92183, 1, 111625,      0,      0), -- Alard Schmied
( 96778, 1,      0,      0,  14105), -- Aemara
( 96779, 1,      0,      0,  44715), -- Dagna Flintlock
( 97141, 1,  36516,      0,      0), -- Koraud
(106655, 1, 116646,      0,      0), -- Arcanomancer Vridiel
( 96780, 1,   6233,      0,      0), -- Aerith Primrose
( 96809, 1,  13861,      0,      0), -- Arille Azuregaze
( 96698, 1,  34298,      0,      0), -- Blood Knight
( 96708, 1,  34298,      0,      0), -- Blood Knight
(107772, 1,  25150,    820,      0), -- Ol' Toomba
(104091, 1,  43617,      0,      0), -- Kirin Tor Guardian
(116175, 1,  65492, 111717,      0), -- Karam Magespear
(110019, 1,      0,      0, 108713), -- Bruiser Toppleblade
( 96786, 1,  36750,      0,      0), -- Archmage Celindra
( 96785, 1,  13612,      0,      0), -- Christi Stockton
( 96960, 1,  41342,      0,      0), -- High Arcanist Savor
(119272, 1,   3267,  49777,      0), -- Sarah the Savage
( 96954, 1,  13160,      0,      0), -- Nelur Lightsown
( 97792, 1,  64632,      0,      0), -- Sun Priest
(119487, 1, 126320, 126334,      0), -- Talia Direhorn
(119486, 1, 126324,      0,      0), -- Apothecary Lee
( 92489, 1,   1908,      0,      0), -- Mei Francis
( 96957, 1,   2813,      0,      0), -- Murgha the Tempered
(113783, 1,  25519,  25519,      0), -- Savash Windcalller
( 96959, 1,  23225,  24322,      0), -- Vinsun
( 96953, 1,      0,      0,  13147), -- Ranger Eoss
( 96952, 1,  13337,      0,      0), -- Hahna Moonscrest
(120687, 1, 115865,      0,      0), -- Violet Shadowmend
( 96956, 1,  17283,  17282,      0), -- Pathstalker Rislar
( 96958, 1,  19987,      0,      0), -- Summoner Calwen
( 96955, 1,  13751,      0,      0), -- Matron Ossela
( 98724, 1,   2715,      0,      0), -- Giada Goldleash
(113780, 1,  56260,      0,      0), -- Innocent Jim
( 98723, 1,   2714,      0,      0), -- Tiffy Trapspring
(109554, 1,  25324,      0,      0), -- Altius Maximus
(109390, 1, 119463,      0,      0), -- Annie
(109387, 1, 119411,      0,      0), -- Beck
(103626, 1,   3267,  49777,      0), -- Forsaken Guard
( 96804, 1,   2705,      0,      0), -- Hamaka
( 96801, 1,      0,      0,   5856), -- Kyunghee
( 93536, 1,   2827,      0,      0), -- Awilo Lon'gomba
(101846, 1,  17041,      0,      0), -- Nomi
( 96803, 1,   2703,  13859,      0), -- Mimbihi
(112079, 1,  44091,      0,      0), -- Crimson Pilgrim
( 96802, 1,   2703,  13859,      0), -- Umbiwa
(113813, 1,  43093,      0,      0), -- Lieutenant Sinclari
(102266, 1,  43091,  43092,      0), -- Violet Hold Guard
( 94197, 1,  43091,  43092,      0), -- Violet Hold Guard
( 96444, 1,  43091,  43092,      0), -- Violet Hold Guard
(111246, 1,  38298,      0,      0), -- Archmage Timear
(113785, 1,  12182,      0,      0), -- Hugh Mann
(111243, 1,  34884,      0,      0), -- Archmage Lan'dalock
( 97012, 1,      0,      0,   6231), -- Abra Cadabra
(113779, 1,   2183,   2183,      0), -- Sister Might
( 95844, 1,   1117,      0,      0), -- Marcia Chase
(113782, 1,  25839,      0,      0), -- Hannis Shoalwalker
(108628, 1, 118129,      0,      0), -- Armond Thaco
( 97500, 1, 119448,      0,      0), -- Hunaka Greenhoof
(106930, 1,  57038,      0,      0), -- Lieutenant Surtees
( 90417, 1,  28067,      0,      0), -- Archmage Khadgar
( 92457, 1,   3699,  12870,      0), -- Patricia Egan
(113873, 1,      0, 113270,      0), -- Archivist Elysiana
( 90418, 1,  35781,      0,      0), -- Archmage Modera
( 90431, 1,  12182,      0,      0), -- Archmage Ansirem Runeweaver
( 96944, 1,  12328,      0,      0), -- Muran Fairden
( 96792, 1,  13861,  13862,      0), -- Inzi Charmlight
(113784, 1,  18822,      0,      0), -- Classic Larry
( 90463, 1,  50725,      0,      0), -- Archmage Karlain
( 96949, 1,  29694,      0,      0), -- Farseer Lopaa
( 96793, 1,   2705,      0,      0), -- Stefen Cotter
( 96947, 1,  13751,      0,      0), -- Matron Nessa
( 96948, 1,  17283,  17282,      0), -- Pathstalker Gilen
(119226, 1,  29156, 117413,      0), -- Danath Trollbane
( 96950, 1,  19987,      0,      0), -- Summoner Mazek
( 96945, 1,      0,      0,  94658), -- Ranger Bodine
( 96791, 1,  13861,  13862,      0), -- Marcella Bloom
( 97213, 1,      0,      0,   4547), -- Windle Sparkshine
( 96946, 1,  13160,      0,      0), -- Varlean
( 96951, 1,  34292,      0,      0), -- Naseev
( 96772, 1,      0,      0,   6231), -- Warmage Kath'leen
(112720, 1, 140669,      0,      0), -- Jemma Wilson
( 97493, 1, 124379,      0,      0), -- Narestel Palestar
(115465, 1,  35781,      0,      0), -- Archmage Modera
(115466, 1,  12182,      0,      0), -- Archmage Ansirem Runeweaver
(115464, 1,  28067,      0,      0), -- Archmage Khadgar
(115468, 1,  50725,      0,      0), -- Archmage Karlain
( 96771, 1,  35781,      0,   6231), -- Warmage Lukems
( 96770, 1,  20718,      0,   6231), -- Warmage Mumplina
(107968, 1,  34884,      0,      0), -- Archmage Lan'dalock
(105339, 1, 125646, 119379,      0), -- Shadowgore Darkcaster
(118506, 1,  45727,  94256,      0), -- Sunreaver Spellblade
(105231, 1,  46090,      0,      0), -- Sir Galveston
( 93520, 1,  31824,      0,      0), -- Didi the Wrench
( 97533, 1, 113639,      0,      0), -- Felcaster Virim
(114208, 1,  44655,      0,      0), -- Great Wizard Kowalkowski
(114232, 1, 101385,      0,      0), -- Grand Lightweaver Doane
(113781, 1,  88550,      0,      0), -- Li-An Skymirror
( 97513, 1, 113857,      0,      0), -- Juwanamana
(100671, 1, 109482,      0,      0), -- Harold Winston
( 97756, 1, 109309, 109309,      0), -- Inkrot
( 97359, 1,  45727,  43092,      0); -- Raethan
