-- 
DELETE FROM `spell_target_position` WHERE (`ID`=57541 AND `EffectIndex`=0) OR (`ID`=57515 AND `EffectIndex`=1) OR (`ID`=57654 AND `EffectIndex`=0) OR (`ID`=65138 AND `EffectIndex`=0) OR (`ID`=100244 AND `EffectIndex`=0) OR (`ID`=245992 AND `EffectIndex`=1) OR (`ID`=72191 AND `EffectIndex`=1) OR (`ID`=72182 AND `EffectIndex`=0) OR (`ID`=72241 AND `EffectIndex`=0) OR (`ID`=72175 AND `EffectIndex`=0) OR (`ID`=72140 AND `EffectIndex`=0) OR (`ID`=77638 AND `EffectIndex`=0) OR (`ID`=76966 AND `EffectIndex`=0) OR (`ID`=76645 AND `EffectIndex`=0) OR (`ID`=65235 AND `EffectIndex`=0) OR (`ID`=68554 AND `EffectIndex`=0) OR (`ID`=68382 AND `EffectIndex`=0) OR (`ID`=68693 AND `EffectIndex`=0) OR (`ID`=42711 AND `EffectIndex`=0) OR (`ID`=42710 AND `EffectIndex`=0) OR (`ID`=113626 AND `EffectIndex`=0) OR (`ID`=111219 AND `EffectIndex`=0) OR (`ID`=84503 AND `EffectIndex`=0) OR (`ID`=84484 AND `EffectIndex`=0) OR (`ID`=84483 AND `EffectIndex`=0) OR (`ID`=251062 AND `EffectIndex`=0) OR (`ID`=78318 AND `EffectIndex`=2) OR (`ID`=145430 AND `EffectIndex`=0) OR (`ID`=132621 AND `EffectIndex`=0) OR (`ID`=71612 AND `EffectIndex`=0) OR (`ID`=85657 AND `EffectIndex`=0) OR (`ID`=85659 AND `EffectIndex`=0) OR (`ID`=85658 AND `EffectIndex`=0) OR (`ID`=85833 AND `EffectIndex`=0) OR (`ID`=85609 AND `EffectIndex`=0) OR (`ID`=81926 AND `EffectIndex`=0) OR (`ID`=81925 AND `EffectIndex`=0) OR (`ID`=81924 AND `EffectIndex`=0) OR (`ID`=81923 AND `EffectIndex`=0) OR (`ID`=81922 AND `EffectIndex`=0) OR (`ID`=81921 AND `EffectIndex`=0) OR (`ID`=81920 AND `EffectIndex`=0) OR (`ID`=81918 AND `EffectIndex`=0) OR (`ID`=81916 AND `EffectIndex`=0) OR (`ID`=81909 AND `EffectIndex`=0) OR (`ID`=82051 AND `EffectIndex`=0) OR (`ID`=81883 AND `EffectIndex`=0) OR (`ID`=81784 AND `EffectIndex`=0) OR (`ID`=81537 AND `EffectIndex`=0) OR (`ID`=81991 AND `EffectIndex`=0) OR (`ID`=80936 AND `EffectIndex`=0) OR (`ID`=80934 AND `EffectIndex`=0) OR (`ID`=223199 AND `EffectIndex`=0) OR (`ID`=243836 AND `EffectIndex`=0) OR (`ID`=258988 AND `EffectIndex`=0) OR (`ID`=228326 AND `EffectIndex`=0) OR (`ID`=78924 AND `EffectIndex`=0) OR (`ID`=78923 AND `EffectIndex`=0) OR (`ID`=87712 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(57541, 0, 1, 7842.86, -2213.05, 470.847, 26899), -- Spell: Portal: Return from Moonglade Efffect: 28 (SPELL_EFFECT_SUMMON)
(57515, 1, 1, 7845.03, -2222.38, 469.268, 26899), -- Spell: Waking from a Fitful Dream Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(57654, 0, 1, 7828.84, -2245.65, 463.707, 26899), -- Spell: Portal: Moonglade Effect Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(65138, 0, 571, 4042.93, 7097.24, 171, 26365), -- Spell: Summon Keristrasza Vehicle Efffect: 28 (SPELL_EFFECT_SUMMON)
(100244, 0, 951, 3708.37, 7359.92, 269.679, 26365), -- Spell: Teleport Player to NEXUS LEGENDARY Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(245992, 1, 0, -8998.14, 861.25, 29.62, 26365), -- Spell: Portal: Stormwind Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(72191, 1, 1, -7556.91, -1474.79, -269.411, 26124), -- Spell: Ever Watching From Above - Diemetradon Teleport Effect Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(72182, 0, 1, -6414.27, -1788.28, -265.867, 26124), -- Spell: Ever Watching From Above - Gorilla Teleport Effect Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(72241, 0, 1, -6716.63, -1904.05, -272.116, 26124), -- Spell: Ever Watching From Above - Bloodpetal Teleport Effect Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(72175, 0, 1, -6792.21, -866.032, -259.331, 26124), -- Spell: Ever Watching From Above - Pterrordax Teleport Effect Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(72140, 0, 1, -6275, -1557, -222, 26124), -- Spell: Un'Goro Pylon Beam Effect - North Efffect: 3 (SPELL_EFFECT_DUMMY)
(77638, 0, 1, 2080.74, 1539.92, 348.415, 25996), -- Spell: Summon Thal'darah's Hippogryph Efffect: 28 (SPELL_EFFECT_SUMMON)
(76966, 0, 1, 1234.01, 457.877, 80.9189, 25996), -- Spell: Call Big Papa Efffect: 28 (SPELL_EFFECT_SUMMON)
(76645, 0, 1, 1007.73, -422.611, 24.0561, 25996), -- Spell: Summon Personal Hot Air Balloon Efffect: 28 (SPELL_EFFECT_SUMMON)
(65235, 0, 1, 2495.64, -1311.38, 135.033, 25996), -- Spell: Teleport to Safety Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(68554, 0, 1, -978.331, 1644.75, 70.5771, 25996), -- Spell: Summon Karnum's Mount Efffect: 28 (SPELL_EFFECT_SUMMON)
(68382, 0, 1, -1041.67, 1613.74, 59.8566, 25996), -- Spell: Summon Kolkar Centaur Efffect: 28 (SPELL_EFFECT_SUMMON)
(68693, 0, 1, 171.402, 1793.46, 86.229, 25996), -- Spell: Summon Jankie's Mount Efffect: 28 (SPELL_EFFECT_SUMMON)
(42711, 0, 1, -3746.5, -4452.16, 64.9715, 25996), -- Spell: Stormwind to Dustwallow Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(42710, 0, 0, -8387.78, 263.307, 155.347, 25996), -- Spell: Dustwallow to Stormwind Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(113626, 0, 1001, 1298.08, 549.637, 12.6391, 25996), -- Spell: Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(111219, 0, 1001, 1206.86, 443.972, 0.9878648, 25996), -- Spell: Heroic Leap Efffect: 42 (SPELL_EFFECT_JUMP_DEST)
(84503, 0, 0, 1371.83, -1497.85, 105.349, 25928), -- Spell: The Depravity of the Forsaken: Summon Val'kyr 2 Efffect: 28 (SPELL_EFFECT_SUMMON)
(84484, 0, 0, 1371.83, -1497.85, 105.349, 25928), -- Spell: The Depravity of the Forsaken: Summon Aradne Efffect: 28 (SPELL_EFFECT_SUMMON)
(84483, 0, 0, 1373.79, -1291.94, 58, 25928), -- Spell: The Depravity of the Forsaken: Summon Camera Efffect: 28 (SPELL_EFFECT_SUMMON)
(251062, 0, 1669, 403.8, 1449.06, 772.66, 25881), -- Spell: Hearthstone Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(78318, 2, 0, -4454.97, 3805.41, -82.36, 26365), -- Spell: Phase - Quest Zone-Specific 02 Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(145430, 0, 870, -651.232, -4903.7, 2.05622, 26365), -- Spell: Call of the Mists Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(132621, 0, 870, 917.64, 294.88, 506.1, 26365), -- Spell: Teleport: Vale of Eternal Blossoms Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(71612, 0, 0, -4016.95, -1984.98, 92.6272, 25996), -- Spell: Summon Vision of Charlga Efffect: 28 (SPELL_EFFECT_SUMMON)
(85657, 0, 0, 3007.52, -3426.23, 152.624, 25950), -- Spell: GFR: Summon Lord Raymond George Efffect: 28 (SPELL_EFFECT_SUMMON)
(85659, 0, 0, 3000.76, -3422.93, 149.809, 25950), -- Spell: GFR: Summon Pamela Redpath Efffect: 28 (SPELL_EFFECT_SUMMON)
(85658, 0, 0, 3011.12, -3427.91, 152.381, 25950), -- Spell: GFR: Summon Vex'tul (Dead) Efffect: 28 (SPELL_EFFECT_SUMMON)
(85833, 0, 0, 2993.03, -3453.21, 152.206, 25950), -- Spell: GFR: Summon Beezil Linkspanner Efffect: 28 (SPELL_EFFECT_SUMMON)
(85609, 0, 0, 2294.56, -5334.66, 90.7523, 25937), -- Spell: Gidwin's Hearthstone Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(81926, 0, 0, -14261.6, 690.652, 10.2489, 25928), -- Spell: Bloodsail's End: Summon Explosion 10 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81925, 0, 0, -14252.7, 668.867, 11.2107, 25928), -- Spell: Bloodsail's End: Summon Explosion 09 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81924, 0, 0, -14250.5, 680.813, 7.63285, 25928), -- Spell: Bloodsail's End: Summon Explosion 08 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81923, 0, 0, -14258.5, 683.572, 10.0244, 25928), -- Spell: Bloodsail's End: Summon Explosion 07 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81922, 0, 0, -14262.8, 672.53, 9.8617, 25928), -- Spell: Bloodsail's End: Summon Explosion 06 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81921, 0, 0, -14269.2, 684.162, 9.9302, 25928), -- Spell: Bloodsail's End: Summon Explosion 05 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81920, 0, 0, -14267, 696.027, 9.8595, 25928), -- Spell: Bloodsail's End: Summon Explosion 04 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81918, 0, 0, -14274.7, 707.218, 9.17219, 25928), -- Spell: Bloodsail's End: Summon Explosion 03 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81916, 0, 0, -14263.8, 703.773, 8.19311, 25928), -- Spell: Bloodsail's End: Summon Explosion 02 Efffect: 28 (SPELL_EFFECT_SUMMON)
(81909, 0, 0, -14276, 694.778, 8.18786, 25928), -- Spell: Bloodsail's End: Summon Explosion 01 Efffect: 28 (SPELL_EFFECT_SUMMON)
(82051, 0, 0, -14446.5, 509.209, 26.2368, 25928), -- Spell: Bloodsail's End: Summon Wind Rider Efffect: 28 (SPELL_EFFECT_SUMMON)
(81883, 0, 0, -14446.5, 509.209, 26.2368, 25928), -- Spell: The Final Voyage of the Brashtide: Summon Wind Rider Efffect: 28 (SPELL_EFFECT_SUMMON)
(81784, 0, 0, -14382.5, 489.066, 12.954, 25928), -- Spell: Damsel's Bad Luck: Summon Disembarking Bunny Efffect: 28 (SPELL_EFFECT_SUMMON)
(81537, 0, 0, -14865.4, 296.362, 0, 25928), -- Spell: Bloodsail Attack Boat Efffect: 28 (SPELL_EFFECT_SUMMON)
(81991, 0, 0, -14454, 510.242, 22.4721, 25928), -- Spell: Bloodsail's End: Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(80936, 0, 0, -11994.3, -1717.32, 32.2833, 25928), -- Spell: High Priest Venoxis: Zanzil Teleport 03 Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(80934, 0, 0, -12027.6, -1708.05, 39.3156, 25928), -- Spell: High Priest Venoxis: Zanzil Teleport 01 Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(223199, 0, 1220, -828.72, 4371.78, 738.64, 25881), -- Spell: Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(243836, 0, 1756, 13705.1, 13075.7, 343.56, 26365), -- Spell: The Deaths of Chromie Efffect: 227 (SPELL_EFFECT_TELEPORT_TO_LFG_DUNGEON)
(258988, 0, 0, -11888.5, -3206.54, -15.2, 26124), -- Spell: Dark Portal Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(228326, 0, 0, -11099.8, -2212.36, 757.83, 25961), -- Spell: Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(78924, 0, 0, -11314.1, -3441.44, 7.46822, 25961), -- Spell: Bloodstone Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(78923, 0, 0, -11217.3, -3508.09, 8.06974, 25961), -- Spell: Bloodstone Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(87712, 0, 0, -10450, -3823.38, 17.8718, 25961); -- Spell: Teleport to Itharius Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `PositionZ`=574.636, `VerifiedBuild`=26899 WHERE (`ID`=57773 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=591.186, `VerifiedBuild`=26899 WHERE (`ID`=57786 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=588.223, `VerifiedBuild`=26899 WHERE (`ID`=57782 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=596.347, `VerifiedBuild`=26899 WHERE (`ID`=57746 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=574.636, `VerifiedBuild`=26899 WHERE (`ID`=57747 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=410.168, `VerifiedBuild`=26899 WHERE (`ID`=57535 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=6390.53, `PositionY`=237.012, `PositionZ`=395.813, `VerifiedBuild`=26899 WHERE (`ID`=57897 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=385.51, `VerifiedBuild`=26899 WHERE (`ID`=56679 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=6705.88, `PositionY`=-247.948, `PositionZ`=948.034, `VerifiedBuild`=26822 WHERE (`ID`=56697 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=6674.92, `PositionY`=-300.363, `PositionZ`=989.339, `VerifiedBuild`=26822 WHERE (`ID`=56676 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=6153.65, `PositionY`=-1075.62, `PositionZ`=403.529, `VerifiedBuild`=26822 WHERE (`ID`=54963 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `PositionX`=3841.4, `PositionY`=-3426.65, `VerifiedBuild`=26822 WHERE (`ID`=49098 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `PositionX`=-465.699, `PositionY`=1495.98, `PositionZ`=17.3595, `VerifiedBuild`=26822 WHERE (`ID`=49097 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `PositionX`=3574.22, `PositionY`=6652.13, `VerifiedBuild`=26365 WHERE (`ID`=46824 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=4034.25, `PositionY`=7349.38, `PositionZ`=635.97, `VerifiedBuild`=26365 WHERE (`ID`=46772 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=3594.18, `PositionY`=5997.51, `PositionZ`=136.215, `VerifiedBuild`=26365 WHERE (`ID`=50135 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-1824.32, `PositionY`=5417.23, `VerifiedBuild`=26124 WHERE (`ID`=33690 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-2260.09, `PositionY`=3215.05, `VerifiedBuild`=26124 WHERE (`ID`=32572 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-2307.42, `PositionY`=3123.68, `PositionZ`=13.7278, `VerifiedBuild`=26124 WHERE (`ID`=32569 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-2260.26, `PositionY`=3114.48, `PositionZ`=136.35, `VerifiedBuild`=26124 WHERE (`ID`=32568 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-4031.24, `PositionY`=-11569.6, `VerifiedBuild`=25996 WHERE (`ID`=32271 AND `EffectIndex`=0);
-- UPDATE `spell_target_position` SET `MapID`=1159, `PositionX`=1936.9, `PositionY`=341.35, `PositionZ`=90.28, `VerifiedBuild`=25881 WHERE (`ID`=171253 AND `EffectIndex`=0); -- Spell script required
UPDATE `spell_target_position` SET `PositionX`=7992.89, `PositionY`=-3193.85, `PositionZ`=927.386, `VerifiedBuild`=26822 WHERE (`ID`=56649 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=5846.5, `PositionY`=605.5, `PositionZ`=650.9, `VerifiedBuild`=26822 WHERE (`ID`=54029 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=273.0607, `VerifiedBuild`=26822 WHERE (`ID`=55762 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=6165.63, `PositionY`=-2001.19, `VerifiedBuild`=26822 WHERE (`ID`=52091 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=479.019, `VerifiedBuild`=26755 WHERE (`ID`=49990 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=479.019, `VerifiedBuild`=26755 WHERE (`ID`=49988 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=479.019, `VerifiedBuild`=26755 WHERE (`ID`=49984 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=4.05514, `VerifiedBuild`=26365 WHERE (`ID`=42838 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionZ`=4.33616, `VerifiedBuild`=26365 WHERE (`ID`=42837 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=3306.98, `PositionY`=2506.61, `PositionZ`=197.317, `VerifiedBuild`=26365 WHERE (`ID`=47324 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=3190.83, `PositionY`=5275.33, `PositionZ`=48.2713, `VerifiedBuild`=26365 WHERE (`ID`=46233 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-1824.32, `PositionY`=5417.23, `VerifiedBuild`=26365 WHERE (`ID`=121853 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=702.969, `PositionY`=197.427, `VerifiedBuild`=26365 WHERE (`ID`=41566 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-11996.47, `PositionY`=-1689.711, `PositionZ`=32.37836, `VerifiedBuild`=25928 WHERE (`ID`=81012 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=2637.11, `PositionY`=-5051.53, `PositionZ`=295.591, `VerifiedBuild`=26822 WHERE (`ID`=43209 AND `EffectIndex`=2);
UPDATE `spell_target_position` SET `PositionX`=3646.74, `PositionY`=5893.2, `VerifiedBuild`=26365 WHERE (`ID`=46018 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=12803.7, `PositionY`=-6907.38, `PositionZ`=41.1164, `VerifiedBuild`=26365 WHERE (`ID`=44870 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=795, `PositionY`=-17, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36964 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=785, `PositionY`=-13, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36963 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=781, `PositionY`=-6, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36962 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=776, `PositionY`=-0.7, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36961 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=781, `PositionY`=5, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36960 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=785, `PositionY`=11, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36959 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=795, `PositionY`=15, `PositionZ`=50.06, `VerifiedBuild`=26365 WHERE (`ID`=36958 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=241.073, `PositionY`=-27.0846, `VerifiedBuild`=26365 WHERE (`ID`=34316 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=239.111, `PositionY`=-1.59108, `PositionZ`=27.0491, `VerifiedBuild`=26365 WHERE (`ID`=34315 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=241.768, `PositionY`=24.8276, `PositionZ`=20.3438, `VerifiedBuild`=26365 WHERE (`ID`=34314 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=359.997, `PositionY`=-92.7042, `PositionZ`=20.0127, `VerifiedBuild`=26365 WHERE (`ID`=34289 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=384.251, `PositionY`=-84.3709, `PositionZ`=20.18, `VerifiedBuild`=26365 WHERE (`ID`=34288 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=335.024, `PositionY`=-83.21, `PositionZ`=20.388, `VerifiedBuild`=26365 WHERE (`ID`=34287 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=403.462, `PositionY`=-67.8334, `PositionZ`=20.18, `VerifiedBuild`=26365 WHERE (`ID`=34286 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=309.55, `PositionY`=-89.3632, `VerifiedBuild`=26365 WHERE (`ID`=34285 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=404.622, `PositionY`=-42.1397, `VerifiedBuild`=26365 WHERE (`ID`=34284 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=283.424, `PositionY`=-85.9517, `VerifiedBuild`=26365 WHERE (`ID`=34283 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=423.478, `PositionY`=-23.9648, `VerifiedBuild`=26365 WHERE (`ID`=34282 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=424.829, `PositionY`=1.01505, `PositionZ`=20.18, `VerifiedBuild`=26365 WHERE (`ID`=34281 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=249.358, `PositionY`=-52.7987, `PositionZ`=20.1795, `VerifiedBuild`=26365 WHERE (`ID`=34280 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=261.468, `PositionY`=-73.6918, `PositionZ`=20.1795, `VerifiedBuild`=26365 WHERE (`ID`=34279 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=422.53, `PositionY`=26.9552, `VerifiedBuild`=26365 WHERE (`ID`=34278 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=402.296, `PositionY`=44.3146, `VerifiedBuild`=26365 WHERE (`ID`=34277 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=403.761, `PositionY`=69.5173, `VerifiedBuild`=26365 WHERE (`ID`=34276 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=382.319, `PositionY`=83.0517, `VerifiedBuild`=26365 WHERE (`ID`=34275 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=358.834, `PositionY`=90.569, `PositionZ`=20.032, `VerifiedBuild`=26365 WHERE (`ID`=34274 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=332.415, `PositionY`=86.6608, `PositionZ`=20.3436, `VerifiedBuild`=26365 WHERE (`ID`=34273 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=306.56, `PositionY`=92.0271, `PositionZ`=20.1798, `VerifiedBuild`=26365 WHERE (`ID`=34272 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=279.967, `PositionY`=83.4335, `VerifiedBuild`=26365 WHERE (`ID`=34271 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=260.572, `PositionY`=67.3991, `VerifiedBuild`=26365 WHERE (`ID`=34270 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=244.1, `PositionY`=49.9153, `VerifiedBuild`=26365 WHERE (`ID`=34269 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-208.411, `VerifiedBuild`=26365 WHERE (`ID`=33582 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-291.833, `PositionY`=-268.595, `VerifiedBuild`=26365 WHERE (`ID`=33585 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-282.272, `PositionY`=-240.432, `PositionZ`=12.6825, `VerifiedBuild`=26365 WHERE (`ID`=33584 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-261.676, `PositionY`=-297.69, `VerifiedBuild`=26365 WHERE (`ID`=33583 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-303.966, `PositionY`=-255.759, `VerifiedBuild`=26365 WHERE (`ID`=33586 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-208.411, `VerifiedBuild`=26365 WHERE (`ID`=33566 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=372, `PositionY`=-690, `PositionZ`=-14, `VerifiedBuild`=26365 WHERE (`ID`=37861 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=366, `PositionY`=-709, `VerifiedBuild`=26365 WHERE (`ID`=37860 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=366, `PositionY`=-736, `PositionZ`=-14, `VerifiedBuild`=26365 WHERE (`ID`=37858 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=334, `PositionY`=-728, `PositionZ`=-14, `VerifiedBuild`=26365 WHERE (`ID`=37854 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=334, `PositionY`=-728, `PositionZ`=-14, `VerifiedBuild`=26365 WHERE (`ID`=37850 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=3923, `PositionY`=3873, `PositionZ`=181, `VerifiedBuild`=26365 WHERE (`ID`=34857 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=4200, `PositionY`=1767, `PositionZ`=133, `VerifiedBuild`=26365 WHERE (`ID`=34830 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=94, `PositionY`=376, `PositionZ`=-27, `VerifiedBuild`=26365 WHERE (`ID`=34734 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=94, `PositionY`=416, `PositionZ`=-27, `VerifiedBuild`=26365 WHERE (`ID`=34733 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=56, `PositionY`=428, `PositionZ`=-25, `VerifiedBuild`=26365 WHERE (`ID`=34731 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=26, `PositionY`=419, `PositionZ`=-25, `VerifiedBuild`=26365 WHERE (`ID`=34727 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-185, `PositionY`=407, `PositionZ`=-15.6, `VerifiedBuild`=26365 WHERE (`ID`=34685 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-185, `PositionY`=376, `PositionZ`=-15.6, `VerifiedBuild`=26365 WHERE (`ID`=34681 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-185, `PositionY`=407, `PositionZ`=-15.6, `VerifiedBuild`=26365 WHERE (`ID`=34684 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-185, `PositionY`=376, `PositionZ`=-15.6, `VerifiedBuild`=26365 WHERE (`ID`=34682 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-204, `PositionY`=391, `PositionZ`=-11, `VerifiedBuild`=26365 WHERE (`ID`=34673 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-25.95, `VerifiedBuild`=25996 WHERE (`ID`=22651 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-478.448, `PositionY`=-89.3074, `PositionZ`=-146.602, `VerifiedBuild`=25996 WHERE (`ID`=12158 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-562.7, `PositionY`=-121.674, `PositionZ`=-150.862, `VerifiedBuild`=25996 WHERE (`ID`=12159 AND `EffectIndex`=0);
