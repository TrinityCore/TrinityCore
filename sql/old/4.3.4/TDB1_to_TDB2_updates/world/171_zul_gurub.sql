SET @OGUID := 164292;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 184955, 859, 1, 1, -11894.12, -1263.847, 85.13749, 0, 0, 0, 0, 1, 7200, 255, 1), -- Campfire (Area: 0)
(@OGUID+1, 208550, 859, 1, 1, -11906.45, -1279.137, 85.14069, 4.136433, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+2, 208838, 859, 1, 1, -11915.87, -1220.608, 94.21243, 1.570796, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+3, 208837, 859, 1, 1, -11915.87, -1220.608, 94.21243, 1.570796, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+4, 208314, 859, 1, 1, -11612.51, -1283.451, 78.34849, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+5, 208850, 859, 1, 1, -11613.07, -1360.196, 90.12822, 1.562067, 0, 0, 0, 1, 7200, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+6, 208313, 859, 1, 1, -11648.18, -1446.665, 58.95971, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+7, 208314, 859, 1, 1, -11604.27, -1408.137, 65.5885, 4.97419, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+8, 208313, 859, 1, 1, -11570.83, -1313.016, 79.17264, 4.939284, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+9, 208315, 859, 1, 1, -11564.2, -1258.585, 78.62879, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+10, 208844, 859, 1, 1, -11993.26, -1660.023, 41.80116, 4.54199, 0, 0, 0, 1, 7200, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+12, 180497, 859, 1, 1, -11494.47, -1613.754, 47.6743, 1.579522, 0, 0, 0.7101853, 0.7040148, 7200, 255, 0), -- Forcefield (Area: 0)
(@OGUID+13, 208843, 859, 1, 1, -11938.29, -1843.014, 62.09087, 3.141593, 0, 0, 0, 1, 7200, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+14, 143979, 859, 1, 1, -11600.36, -698.984, 30.97299, 0.01745246, 0, 0, 0.008726574, 0.9999619, 7200, 255, 1), -- Cage Door (Area: 0)
(@OGUID+15, 208845, 859, 1, 1, -12334.6, -1862.155, 129.6658, 0.8028509, 0, 0, 0, 1, 7200, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+16, 208847, 859, 1, 1, -12365.35, -1853.549, 129.7878, 1.570796, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+17, 208848, 859, 1, 1, -12319.17, -1891.137, 129.9776, 0.03490625, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+18, 208846, 859, 1, 1, -12392.28, -1863.455, 129.6838, 2.373644, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+19, 208849, 859, 1, 1, -12330.84, -1919.649, 129.8794, 5.489062, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+20, 208315, 859, 1, 1, -11652.74, -1552.717, 40.84423, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+21, 208313, 859, 1, 1, -11631.98, -1622.672, 39.56029, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+22, 208314, 859, 1, 1, -12303.23, -1845.889, 131.3084, 4.97419, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+23, 208314, 859, 1, 1, -12342.13, -1841.431, 130.8306, 4.97419, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Coil)
(@OGUID+24, 180386, 859, 1, 1, -11508.82, -1647.093, 52.63557, 1.666787, 0, 0, 0.7101853, 0.7040148, 7200, 255, 1); -- Gong (Area: Temple of Bethekk)


DELETE FROM `creature_template_addon` WHERE `entry` IN (53022, 53040, 53151, 53025, 53024, 53044, 53022, 53023, 53022, 53043, 53044, 53022, 52417, 53022, 52377, 52380, 52379, 52373, 52820, 52441, 52417, 52332, 45979, 45979, 52529, 52377, 52331, 52417, 52379, 52377, 52331, 52417, 52376, 52442, 52418, 52062, 52062, 52062, 52331, 45979, 52377, 52373, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52062, 52441, 52375, 45979, 52379, 52332, 52332, 52379, 52379, 52331, 52331, 52331, 52331, 52331, 52331, 52332, 52331, 52379, 52418, 52417, 52331, 52331, 52332, 52379, 52331, 52331, 52331, 52379, 52331, 52379, 52331, 52332, 52331, 52417, 52332, 52331, 52089, 52418, 52529, 52331, 52331, 52332, 52331, 52332, 52379, 52379, 52418, 52418, 52332, 52331, 52331, 52331, 52379, 52331, 52331, 52379, 52331, 52331, 52377, 52440, 52379, 52417, 52413, 52417, 52413, 52417, 52413, 52417, 52417, 52413, 52413, 52417, 52417, 52413, 52413, 52413, 52441, 52417, 52376, 45979, 45979, 52340, 52418, 52089, 45979, 52089, 45979, 52375, 52441, 52417, 52441, 52377, 52089, 52089, 52375, 52441, 52376, 45979, 52417, 52417, 52417, 52418, 52414, 52417, 52417, 52151, 52376, 52417, 52089, 52155, 52148, 52402, 52402, 52089, 52089, 52381, 45979, 52529, 45979, 52402, 52417, 52376, 52402, 52402, 52377, 52377, 52402, 52402, 52417, 52441, 52311, 52311, 52402, 45979, 45979, 45979, 45979, 45979, 45979, 52417, 52402, 45979, 45979, 45979, 52402, 45979, 52417, 45979, 45979, 45979, 52402, 45979, 45979, 45979, 45979, 45979, 45979, 45979, 52402, 52441, 45979, 45979, 45979, 45979, 45979, 45979, 45979, 45979, 45979, 52405, 52422, 52419, 52419, 52419, 52376, 52402, 52402, 52375, 52375, 52377, 52373, 52413, 52323, 52323, 52323, 52323, 52323, 52323, 52323, 52323, 52323, 52323, 52089, 52402, 52402, 52376, 52089, 52377, 52377, 52376, 52402, 52419, 52089, 52089, 52089, 52089, 52322, 52323, 52413, 52417, 52419, 52419, 52302, 52302, 52441, 52089, 52441, 52376, 52364, 52364, 52364, 52364, 52364, 52364, 52364, 52413, 52377, 52413, 52417, 52364, 52417, 52364, 52364, 52364, 52364, 52302, 52302, 52364, 52364, 52364, 52364, 52608, 52608, 6491, 52417, 52417, 52417, 52441, 52376, 52375, 52441, 52377, 52441, 52376, 52089, 52089, 52089, 52089, 52373, 52089, 52350, 52441, 52352, 52352, 52352, 52441, 52348, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52606, 52089, 52441, 52350, 52350, 52350, 52350, 52089, 52606, 52076, 52956, 52089, 52441, 52441, 52089, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52350, 52079, 52079, 52606, 52606, 52076, 52156, 52958, 52962, 52156, 52962, 52156, 52606, 52088, 52598, 52956, 52089, 52156, 52156, 52956, 52156, 52156, 46464, 52156, 46464, 52441, 52958, 52441, 52441, 52429, 52377, 52453, 52453, 52449, 52455, 52441, 52441, 45979, 52449, 52449, 52453, 52446, 52455, 52455, 52455, 52454, 52413, 52373, 52441, 52418, 52452, 52449, 52453, 52451, 52451, 52451, 52450, 52451, 52441, 52434, 52376, 52958, 52375, 52437, 52437, 52437, 52437, 52436, 52436, 52435, 52435, 52435, 52271, 52434, 52437, 52441, 52438, 52413, 52413, 52413, 52413, 52413, 52434, 52437, 52435, 52417, 52376, 52373, 52417, 52435, 52441, 52956, 52956, 52437, 52434, 52436, 52435, 52376, 52417, 52373, 52413, 52417, 52434, 52413, 52373, 52434, 52436, 52418, 52434, 52434, 52437, 52436, 52434, 52089, 52435, 52434, 52434, 52436, 52962, 52417, 52435, 52434, 52434, 52434, 52436, 52435, 52376, 52435, 52434, 52417, 52436, 52435, 52436, 52434, 52376, 52436, 52441, 52435, 52377, 52437, 52441, 52435, 52434, 52375, 52376, 52437, 52375, 52377, 52434, 52435, 52434, 52377, 52435, 52435, 52439, 52434, 52376, 52437, 52435, 52439, 52958, 52441, 52441, 52441, 52435, 52435, 52434, 52434, 52435, 52435, 52434, 52434, 52435, 52436, 52437, 52436, 52434, 52435, 52437, 52392, 52437, 52435, 52437, 52956, 52436, 52434, 52376, 52373, 52436, 52437, 52436, 52436, 52441, 52435, 52435, 52435, 52373, 52434, 52435, 52434, 52434, 52441, 52958, 52435, 52434, 52436, 52435, 52417, 52435, 52435, 52441, 52435, 52377, 52437, 52436, 52436, 52436, 52436, 52434, 52377, 52077, 52362, 52441, 52441, 52434, 52377, 52373, 52436, 52306, 52306, 52306, 52373, 52305, 52306, 52306, 52306, 52306, 52306, 52306, 52437, 52306, 52306, 52306, 52306, 52306, 52306, 52306, 52306, 52305, 52306, 52306, 52377, 52306, 52306, 52306, 52306, 52375, 52417, 52306, 52306, 52376, 52306, 52417, 52306, 52305, 52306, 52435, 52306, 52306, 52306, 52306, 52306, 52345, 52306, 52306, 52327, 52417, 52306, 52345, 52325, 52375, 52347, 52059, 52387, 52387, 52387, 52413, 52958, 52306, 52345, 52306, 52387, 52327, 52387, 52339, 52327, 52413, 52345, 52441, 52376, 52306, 52061, 52306, 52305, 52387, 52377, 52373, 52345, 52061, 52061, 52306, 52387, 52061, 52345, 52417, 52306, 52306, 52387, 52327, 52345, 52306, 52061, 52962, 52306, 52061, 52327, 52061, 52306, 52339, 52325, 52306, 52061, 52306, 53088, 52325, 52347, 52082, 52958, 52306, 52306, 52305, 52306, 52085, 52306, 52306, 52306, 52085, 52085, 52418, 52306, 52347, 52085, 52306, 52598, 52306, 52085, 52085, 52306, 52306, 52387, 52085, 52306, 52085, 52061, 52387, 52061, 52306, 52061, 52085, 52306, 52305, 53088, 52306, 52306, 52086, 52087, 52087, 52087, 52347, 52087, 52087, 52375, 52089, 53088, 52061, 52061, 52387, 52061, 52061, 52347, 52327, 52327, 52325, 52327, 52327, 52387, 52061, 52345, 52339, 52327, 52325, 52327, 52327, 52387, 52325, 52325, 52339, 52325, 52325, 52347, 52327, 53088, 52347, 52305, 52305, 53088, 52306, 53088, 52306, 52306, 52306, 52441, 52087, 52087, 52376, 52377, 52089, 52087, 53088, 53088, 52087, 53088, 53088, 53088, 53088, 53088, 52417, 52086, 52087, 52087, 52087, 52087, 52087, 52087, 52087, 52417, 52417, 52081, 52441, 52962, 52606, 52086, 52086, 52087, 52087, 52087, 52087, 52087, 52087, 52087, 52087, 52087, 52087, 52417, 52087, 52087, 52376, 52087, 52087, 52087, 52087, 52417, 52089, 52089, 52077, 52077, 52053, 52054, 52079, 52079, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52054, 52054, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52441, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52055, 52608, 52608, 52608, 52608, 52608, 52167, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52956, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52958, 52417, 52417, 52417, 52608, 52608, 52167, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52650, 52167, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52608, 52732, 52608, 52608, 52608, 52413, 52608, 52732, 52167, 52608, 52732, 52532, 52532, 52532, 52532, 52532, 52430, 52430, 52430, 52532, 52624, 52532, 52532, 52624, 52532, 52532, 52532, 52532, 52624, 52222, 52624, 52150, 52532, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52532, 52624, 52532, 52730, 52730, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52730, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52624, 52730, 52624, 52624, 52624, 52624, 52624, 52730, 52624, 52624, 52732, 52732, 42548, 42548, 42548);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
-- (45979, 0, 0x0, 0x1, ''), -- General Purpose Bunny JMF
-- (45979, 0, 0x0, 0x1, '96533'), -- General Purpose Bunny JMF - Snake Eyes
-- (45979, 0, 0x0, 0x1, '96534'), -- General Purpose Bunny JMF - Venom Totem
-- (45979, 0, 0x0, 0x1, '96729'), -- General Purpose Bunny JMF - Poison Cloud
-- (45979, 0, 0x0, 0x1, '96885'), -- General Purpose Bunny JMF - Tiki Eyes
-- (45979, 0, 0x0, 0x1, '97081'), -- General Purpose Bunny JMF - Cursed Portal
(46464, 0, 0x3000000, 0x1, ''), -- Generic Bunny - PRK - Extra-Small
(52053, 0, 0x0, 0x1, ''), -- Zanzil
(52054, 0, 0x0, 0x1, ''), -- Zanzili Berserker
-- (52054, 0, 0x0, 0x1, '96306'), -- Zanzili Berserker - Pursuit
(52055, 0, 0x0, 0x1, ''), -- Zanzili Zombie
(52059, 0, 0x2000000, 0x1, '97428 97459 8279'), -- High Priestess Kilnara - Kilnara Hover, Kilnara Hover, Stealth Detection
(52061, 0, 0x0, 0x1, '96446'), -- Pride of Bethekk - Dark Slumber
-- (52062, 0, 0x0, 0x1, '96500'), -- Zanzil's Toxic Gas - Toxic Gas
-- (52062, 0, 0x0, 0x1, '96867'), -- Zanzil's Toxic Gas - Blue Cauldron Skybeam
-- (52062, 0, 0x0, 0x1, '96868'), -- Zanzil's Toxic Gas - Green Cauldron Skybeam
-- (52062, 0, 0x0, 0x1, '96869'), -- Zanzil's Toxic Gas - Red Cauldron Skybeam
-- (52062, 0, 0x0, 0x1, '97180'), -- Zanzil's Toxic Gas - Green Gas
(52076, 0, 0x0, 0x1, ''), -- Gurubashi Cauldron-Mixer
(52077, 0, 0x0, 0x1, ''), -- Gurubashi Berserker
(52079, 15289, 0x0, 0x1, ''), -- Gurubashi Bloodrager
(52081, 0, 0x0, 0x1, ''), -- Gurubashi Cauldron-Mixer
(52082, 0, 0x0, 0x1, '96456'), -- Gurubashi Cauldron-Mixer - Toxic Cauldron
(52085, 0, 0x0, 0x1, ''), -- Razzashi Adder
(52086, 0, 0x0, 0x1, '45104'), -- Hakkari Witch Doctor - Shadow Channelling
(52087, 0, 0x0, 0x1, ''), -- Zanzil Mindslave
(52088, 0, 0x0, 0x1, ''), -- Gurubashi Cauldron-Mixer
(52089, 0, 0x0, 0x1, ''), -- Gurubashi Worker
-- (52089, 0, 0x0, 0x1, '84186'), -- Gurubashi Worker - Cosmetic - Sleep Zzz
(52148, 0, 0x0, 0x1, '82978 97321'), -- Jin'do the Godbreaker - Cosmetic - Alpha State 25%, Drain Spirit Essence
(52150, 0, 0x0, 0x1, '97207'), -- Jin'do the Godbreaker - Hovering Animation
(52151, 34408, 0x0, 0x1, ''), -- Bloodlord Mandokir
(52155, 0, 0x0, 0x1, ''), -- High Priest Venoxis
(52156, 0, 0x2000000, 0x1, '96568 96642'), -- Chained Spirit - Spirit Form, Spirit Form
(52167, 0, 0x0, 0x1, '28126 18950'), -- Gurubashi Spirit Warrior - Spirit Particles (purple), Invisibility and Stealth Detection
(52222, 0, 0x0, 0x1, ''), -- Spirit of Hakkar
(52271, 0, 0x0, 0x1, '55989'), -- Hazza'rah - Spirit Particles (Corpse)
(52302, 0, 0x0, 0x1, '96678'), -- Venomous Effusion Stalker - Venomous Effusion
(52305, 0, 0x0, 0x1, '96725 96973'), -- Toxic Husk - Submerged State Aura, Poison Cloud
(52306, 0, 0x0, 0x1, '96973'), -- Tangled Vine - Poison Cloud
(52311, 0, 0x0, 0x1, ''), -- Venomguard Destroyer
(52322, 0, 0x0, 0x1, '96759'), -- Witch Doctor Qu'in - Guise of the Venom Priestess
(52323, 0, 0x8, 0x1, ''), -- Chosen of Hethiss
(52325, 0, 0x0, 0x1, ''), -- Gurubashi Blood Drinker
(52327, 0, 0x0, 0x1, ''), -- Gurubashi Shadow Hunter
-- (52331, 0, 0x0, 0x1, '96729 96825'), -- Mutated Overgrowth - Poison Cloud, Mysterious Growth
(52331, 0, 0x0, 0x1, '96729'), -- Mutated Overgrowth - Poison Cloud
-- (52332, 0, 0x0, 0x1, '96729 96825'), -- Toxic Venomspitter - Poison Cloud, Mysterious Growth
(52332, 0, 0x0, 0x1, '96729'), -- Toxic Venomspitter - Poison Cloud
-- (52339, 0, 0x0, 0x1, '97332 97559'), -- Lesser Priest of Bethekk - Lesser Priest Mask, Beseech Blessing
(52339, 0, 0x0, 0x1, '97332'), -- Lesser Priest of Bethekk - Lesser Priest Mask
(52340, 0, 0x0, 0x1, '96798'), -- Tiki Lord Mu'Loa - Tiki Lord Visual
(52345, 0, 0x0, 0x1, ''), -- Pride of Bethekk
-- (52347, 0, 0x0, 0x1, '84119'), -- Zul'gurub Eagle - Sit Ground / Sit Loop / Ground Up on fade
(52347, 0, 0x3000000, 0x1, ''), -- Zul'gurub Eagle
(52348, 0, 0x0, 0x1, '96837'), -- Berserking Boulder Roller - Rolling Boulders
-- (52350, 0, 0x0, 0x1, '46598 96833'), -- Boulder - Ride Vehicle Hardcoded, Rolling Boulders
(52350, 0, 0x0, 0x1, '46598'), -- Boulder - Ride Vehicle Hardcoded
(52352, 0, 0x0, 0x1, ''), -- Boulder Target
(52362, 0, 0x0, 0x1, '96851 96874'), -- Tiki Lord Zim'wae - Tiki Lord Visual, Bone Volley
(52364, 0, 0x0, 0x1, '96853'), -- Ritual Tiki Mask - Tiki Lord Visual
-- (52364, 0, 0x2000000, 0x1, '96853'), -- Ritual Tiki Mask - Tiki Lord Visual
-- (52364, 0, 0x3000000, 0x1, '96853'), -- Ritual Tiki Mask - Tiki Lord Visual
(52373, 0, 0x3000000, 0x1, ''), -- Florawing Needler
(52375, 0, 0x3000000, 0x1, ''), -- Florawing Needler
(52376, 0, 0x3000000, 0x1, ''), -- Florawing Needler
(52377, 0, 0x3000000, 0x1, ''), -- Florawing Needler
(52379, 0, 0x3000000, 0x1, ''), -- Venomtip Needler
-- (52379, 0, 0x3000000, 0x1, '96912'), -- Venomtip Needler - Venomtip
(52380, 0, 0x0, 0x1, ''), -- Venomancer Mauri
(52381, 0, 0x0, 0x1, ''), -- Venomancer T'Kulu
(52387, 0, 0x0, 0x1, ''), -- Cave In Stalker
(52392, 0, 0x0, 0x1, ''), -- Gurubashi Master Chef
(52402, 0, 0x0, 0x1, ''), -- Venomtooth
(52405, 0, 0x0, 0x1, ''), -- Mor'Lek the Dismantler
(52413, 0, 0x0, 0x1, ''), -- Zulian Gnasher
(52414, 0, 0x0, 0x1, '84186'), -- Tor-Tun - Cosmetic - Sleep Zzz
-- (52417, 0, 0x0, 0x1, '18943 18950'), -- Shredtooth Frenzy - Double Attack, Invisibility and Stealth Detection
(52417, 0, 0x0, 0x1, '18943'), -- Shredtooth Frenzy - Double Attack
(52418, 0, 0x0, 0x1, ''), -- Lost Offspring of Gahz'ranka
-- (52419, 0, 0x3000000, 0x1, '96994 97000'), -- Tiki Torch - Tiki Torch Visual, Yoga Flame
(52419, 0, 0x3000000, 0x1, '96994'), -- Tiki Torch - Tiki Torch Visual
(52422, 0, 0x0, 0x1, ''), -- Kaulema the Mover
(52429, 0, 0x0, 0x1, '47840'), -- Zanza the Restless - Cosmetic - Purple Ghost Aura
(52430, 0, 0x0, 0x1, '97091 97417'), -- Hakkar's Chains - Hakkar's Chains, Brittle Barrier
(52434, 0, 0x0, 0x1, ''), -- Gurubashi Villager
-- (52434, 0, 0x0, 0x1, '84186'), -- Gurubashi Villager - Cosmetic - Sleep Zzz
-- (52434, 0, 0x1, 0x1, ''), -- Gurubashi Villager
(52435, 0, 0x0, 0x1, ''), -- Gurubashi Villager
-- (52435, 0, 0x0, 0x1, '84186'), -- Gurubashi Villager - Cosmetic - Sleep Zzz
-- (52435, 0, 0x1, 0x1, ''), -- Gurubashi Villager
(52436, 0, 0x0, 0x1, ''), -- Gurubashi Refugee
-- (52436, 0, 0x0, 0x1, '84186'), -- Gurubashi Refugee - Cosmetic - Sleep Zzz
-- (52436, 0, 0x1, 0x1, ''), -- Gurubashi Refugee
(52437, 0, 0x0, 0x1, ''), -- Gurubashi Refugee
-- (52437, 0, 0x0, 0x1, '84186'), -- Gurubashi Refugee - Cosmetic - Sleep Zzz
-- (52437, 0, 0x1, 0x1, ''), -- Gurubashi Refugee
(52438, 0, 0x0, 0x1, ''), -- Mortaxx
(52439, 0, 0x0, 0x1, ''), -- Purple Ground Rune
(52440, 0, 0x0, 0x1, '97014'), -- Gub - Gub Fishing
(52441, 0, 0x0, 0x1, ''), -- Curious Jungle Monkey
(52442, 0, 0x3000000, 0x1, ''), -- Florawing Hive Queen
(52446, 0, 0x3000000, 0x1, '97040'), -- Ancient Dwarven Artifact - Cursed Artifact
(52449, 0, 0x0, 0x1, ''), -- Ancient Dwarven Artifact
(52450, 0, 0x3000000, 0x1, '97040'), -- Ancient Elven Artifact - Cursed Artifact
(52451, 0, 0x0, 0x1, ''), -- Ancient Elven Artifact
(52452, 0, 0x3000000, 0x1, '97040'), -- Ancient Troll Artifact - Cursed Artifact
(52453, 0, 0x0, 0x1, ''), -- Ancient Troll Artifact
(52454, 0, 0x3000000, 0x1, '97040'), -- Ancient Fossil - Cursed Artifact
(52455, 0, 0x0, 0x1, ''), -- Ancient Fossil
(52529, 0, 0x0, 0x1, ''), -- Zanzil's Cauldron of Toxic Torment
-- (52529, 0, 0x0, 0x1, '97122'), -- Zanzil's Cauldron of Toxic Torment - Venom Shield
(52532, 0, 0x0, 0x1, ''), -- Spirit Portal
(52598, 0, 0x0, 0x1, ''), -- Gurubashi Soul-Eater
(52606, 0, 0x0, 0x1, ''), -- Gurubashi Warmonger
(52608, 0, 0x0, 0x1, '97291'), -- Twisted Shadow - Otherworldly Presence
(52624, 0, 0x0, 0x1, ''), -- Twisted Spirit
-- (52624, 0, 0x0, 0x1, '97285'), -- Twisted Spirit - Shade Visual
(52650, 0, 0x0, 0x1, ''), -- Shadow of Hakkar
-- (52730, 0, 0x0, 0x1, '28126 18950'), -- Gurubashi Spirit - Spirit Particles (purple), Invisibility and Stealth Detection
(52730, 0, 0x0, 0x1, '28126'), -- Gurubashi Spirit - Spirit Particles (purple)
(52732, 0, 0x0, 0x1, '97291'), -- Gurubashi Shadow - Otherworldly Presence
(52820, 0, 0x0, 0x1, ''), -- Helpful Jungle Monkey
(52956, 0, 0x0, 0x1, '97987'), -- Zandalari Juggernaut - Tectonic Plating
(52958, 0, 0x0, 0x1, ''), -- Zandalari Hierophant
(52962, 0, 0x0, 0x1, ''), -- Zandalari Archon
(53022, 0, 0x0, 0x1, ''), -- Siame-Quashi
-- (53022, 0, 0x8, 0x1, ''), -- Siame-Quashi
(53023, 0, 0x0, 0x1, ''), -- Bloodslayer T'ara
(53024, 0, 0x0, 0x1, ''), -- Bloodslayer Zala
(53025, 0, 0x0, 0x1, ''), -- Bloodslayer Vaena
(53040, 0, 0x0, 0x1, ''), -- Vehini
(53043, 0, 0x0, 0x1, ''), -- Briney Boltcutter
(53044, 0, 0x0, 0x1, ''), -- Blackwater Ruffian
(53088, 0, 0x0, 0x1, ''), -- Temple Rat
(53151, 0, 0x0, 0x1, ''); -- Overseer Blingbang


UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38095; -- 38095
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38094; -- 38094
UPDATE `creature_model_info` SET `bounding_radius`=0.305556, `combat_reach`=1.5 WHERE `modelid`=30182; -- 30182
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=30183; -- 30183
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=30181; -- 30181
UPDATE `creature_model_info` SET `bounding_radius`=0.525, `combat_reach`=1.5 WHERE `modelid`=30044; -- 30044
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=3, `gender`=0 WHERE `modelid`=22353; -- 22353
UPDATE `creature_model_info` SET `bounding_radius`=2, `combat_reach`=4 WHERE `modelid`=37845; -- 37845
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=30180; -- 30180
UPDATE `creature_model_info` SET `bounding_radius`=3.72, `combat_reach`=24 WHERE `modelid`=37877; -- 37877
UPDATE `creature_model_info` SET `bounding_radius`=0.4284, `combat_reach`=2.1, `gender`=0 WHERE `modelid`=37816; -- 37816
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37788; -- 37788
UPDATE `creature_model_info` SET `bounding_radius`=0.8262, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=37789; -- 37789
UPDATE `creature_model_info` SET `bounding_radius`=0.665, `combat_reach`=0.95 WHERE `modelid`=30083; -- 30083
UPDATE `creature_model_info` SET `bounding_radius`=0.5508, `combat_reach`=2.7, `gender`=0 WHERE `modelid`=37865; -- 37865
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=3, `gender`=0 WHERE `modelid`=37803; -- 37803
UPDATE `creature_model_info` SET `bounding_radius`=7.5, `combat_reach`=7.5, `gender`=0 WHERE `modelid`=37871; -- 37871
UPDATE `creature_model_info` SET `bounding_radius`=7.5, `combat_reach`=7.5, `gender`=0 WHERE `modelid`=37880; -- 37880
UPDATE `creature_model_info` SET `bounding_radius`=0.459, `combat_reach`=2.25, `gender`=1 WHERE `modelid`=37839; -- 37839
UPDATE `creature_model_info` SET `bounding_radius`=0.459, `combat_reach`=2.25, `gender`=0 WHERE `modelid`=37841; -- 37841
UPDATE `creature_model_info` SET `bounding_radius`=0.459, `combat_reach`=2.25, `gender`=1 WHERE `modelid`=37838; -- 37838
UPDATE `creature_model_info` SET `bounding_radius`=0.459, `combat_reach`=2.25, `gender`=0 WHERE `modelid`=37840; -- 37840
UPDATE `creature_model_info` SET `bounding_radius`=0.5508, `combat_reach`=2.7, `gender`=1 WHERE `modelid`=37837; -- 37837
UPDATE `creature_model_info` SET `bounding_radius`=0.1836, `combat_reach`=0.9, `gender`=0 WHERE `modelid`=37852; -- 37852
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=1.5 WHERE `modelid`=38023; -- 38023
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=1.5 WHERE `modelid`=37985; -- 37985
UPDATE `creature_model_info` SET `bounding_radius`=0.868055, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=37970; -- 37970
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=1 WHERE `modelid`=37976; -- 37976
UPDATE `creature_model_info` SET `bounding_radius`=0.694444, `combat_reach`=3, `gender`=0 WHERE `modelid`=38102; -- 38102
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37981; -- 37981
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37982; -- 37982
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3 WHERE `modelid`=37794; -- 37794
UPDATE `creature_model_info` SET `bounding_radius`=0.694444, `combat_reach`=3, `gender`=0 WHERE `modelid`=38108; -- 38108
UPDATE `creature_model_info` SET `bounding_radius`=0.694444, `combat_reach`=3, `gender`=0 WHERE `modelid`=38104; -- 38104
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3 WHERE `modelid`=37793; -- 37793
UPDATE `creature_model_info` SET `bounding_radius`=0.868055, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=37969; -- 37969
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37962; -- 37962
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3 WHERE `modelid`=37796; -- 37796
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37886; -- 37886
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=37909; -- 37909
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=37907; -- 37907
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=37910; -- 37910
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=37908; -- 37908
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37891; -- 37891
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37899; -- 37899
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37897; -- 37897
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37898; -- 37898
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37901; -- 37901
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37902; -- 37902
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37894; -- 37894
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37893; -- 37893
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37895; -- 37895
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37832; -- 37832
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37890; -- 37890
UPDATE `creature_model_info` SET `bounding_radius`=4, `combat_reach`=4 WHERE `modelid`=37904; -- 37904
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37896; -- 37896
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37903; -- 37903
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37892; -- 37892
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37889; -- 37889
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37888; -- 37888
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37900; -- 37900
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=0.5 WHERE `modelid`=37905; -- 37905
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37868; -- 37868
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=2 WHERE `modelid`=37827; -- 37827
UPDATE `creature_model_info` SET `bounding_radius`=0.45, `combat_reach`=1.5 WHERE `modelid`=37988; -- 37988
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37966; -- 37966
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37977; -- 37977
UPDATE `creature_model_info` SET `bounding_radius`=0.5508, `combat_reach`=2.7, `gender`=1 WHERE `modelid`=37805; -- 37805
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37967; -- 37967
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37983; -- 37983
UPDATE `creature_model_info` SET `bounding_radius`=1.1925, `combat_reach`=2.25 WHERE `modelid`=37991; -- 37991
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37972; -- 37972
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37965; -- 37965
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=6417; -- 6417
UPDATE `creature_model_info` SET `bounding_radius`=0.465, `combat_reach`=3 WHERE `modelid`=34918; -- 34918
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=37978; -- 37978
UPDATE `creature_model_info` SET `bounding_radius`=0.868055, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=37971; -- 37971
UPDATE `creature_model_info` SET `bounding_radius`=0.5508, `combat_reach`=2.7, `gender`=0 WHERE `modelid`=37813; -- 37813
UPDATE `creature_model_info` SET `bounding_radius`=0.4896, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=37979; -- 37979
UPDATE `creature_model_info` SET `bounding_radius`=3.75, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=37749; -- 37749
UPDATE `creature_model_info` SET `bounding_radius`=2.38, `combat_reach`=10.5 WHERE `modelid`=38003; -- 38003
UPDATE `creature_model_info` SET `bounding_radius`=3.75, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=38025; -- 38025
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=3 WHERE `modelid`=38049; -- 38049
UPDATE `creature_model_info` SET `bounding_radius`=2.38, `combat_reach`=10.5 WHERE `modelid`=37811; -- 37811
UPDATE `creature_model_info` SET `bounding_radius`=5.508, `combat_reach`=27, `gender`=0 WHERE `modelid`=37812; -- 37812
UPDATE `creature_model_info` SET `bounding_radius`=3.75, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=37854; -- 37854


DELETE FROM `creature_equip_template` WHERE `entry` IN (53022, 53044, 52380, 52089, 52151, 52155, 52148, 52381, 52311, 52606, 52076, 52956, 52079, 52958, 52962, 52088, 52598, 52429, 52271, 52435, 52434, 52392, 52327, 52325, 52059, 52082, 52086, 52081, 52053);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(53022, 5597, 5597, 0), -- Siame-Quashi
(53044, 22346, 0, 0), -- Blackwater Ruffian
(52380, 19909, 0, 0), -- Venomancer Mauri
(52089, 768, 0, 0), -- Gurubashi Worker
(52151, 68818, 0, 0), -- Bloodlord Mandokir
(52155, 68821, 0, 0), -- High Priest Venoxis
(52148, 69202, 0, 0), -- Jin'do the Godbreaker
(52381, 19909, 0, 0), -- Venomancer T'Kulu
(52311, 31274, 0, 0), -- Venomguard Destroyer
(52606, 19874, 0, 0), -- Gurubashi Warmonger
(52076, 69208, 0, 0), -- Gurubashi Cauldron-Mixer
(52956, 28426, 28754, 0), -- Zandalari Juggernaut
(52079, 19867, 19915, 0), -- Gurubashi Bloodrager
(52958, 69642, 0, 0), -- Zandalari Hierophant
(52962, 69643, 0, 0), -- Zandalari Archon
(52088, 69208, 0, 0), -- Gurubashi Cauldron-Mixer
(52598, 69202, 0, 0), -- Gurubashi Soul-Eater
(52429, 13722, 0, 0), -- Zanza the Restless
(52271, 11383, 0, 0), -- Hazza'rah
(52435, 1117, 0, 0), -- Gurubashi Villager
(52434, 1117, 0, 0), -- Gurubashi Villager
(52392, 2827, 19485, 0), -- Gurubashi Master Chef
(52327, 0, 0, 69207), -- Gurubashi Shadow Hunter
(52325, 11321, 0, 0), -- Gurubashi Blood Drinker
(52059, 43219, 0, 0), -- High Priestess Kilnara
(52082, 69208, 0, 0), -- Gurubashi Cauldron-Mixer
(52086, 12959, 0, 0), -- Hakkari Witch Doctor
(52081, 69208, 0, 0), -- Gurubashi Cauldron-Mixer
(52053, 68834, 0, 0); -- Zanzil


SET @CGUID := 218736;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1026;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 52055, 859, 1, 1, -11535.47, -1257.361, 79.50521, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1, 52608, 859, 1, 1, -11735.13, -1471.466, 37.28736, 2.148747, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+2, 52608, 859, 1, 1, -11752.63, -1502.863, 38.70103, 1.448102, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+3, 52608, 859, 1, 1, -11748.06, -1470.401, 39.68186, 2.072615, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+4, 52608, 859, 1, 1, -11758.02, -1510.942, 37.47496, 2.36465, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+5, 52608, 859, 1, 1, -11760.28, -1537.881, 16.70981, 3.158483, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+6, 52167, 859, 1, 1, -11735.09, -1586.427, 40.80828, 3.840919, 7200, 0, 0), -- Gurubashi Spirit Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+7, 52608, 859, 1, 1, -11770.69, -1495.719, 32.7301, 1.970668, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+8, 52608, 859, 1, 1, -11761.78, -1554.45, 16.53257, 1.417734, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+9, 52608, 859, 1, 1, -11776.05, -1515.187, 25.71508, 1.001121, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+10, 52608, 859, 1, 1, -11776, -1523.602, 23.58886, 5.388267, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+11, 52608, 859, 1, 1, -11755.17, -1575.179, 21.12686, 6.198633, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+12, 52608, 859, 1, 1, -11720.77, -1607.672, 21.18313, 1.636932, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+13, 52608, 859, 1, 1, -11776.65, -1541.73, 19.40344, 0.5793744, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+14, 52608, 859, 1, 1, -11768.07, -1576.419, 21.17036, 5.880112, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+15, 52956, 859, 1, 1, -11785.88, -1560.694, 19.92469, 1.64061, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0) (possible waypoints or random movement)
(@CGUID+16, 52608, 859, 1, 1, -11792.65, -1501.601, 26.17068, 1.311706, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+17, 52608, 859, 1, 1, -11796.79, -1469.393, 35.19319, 0.3493309, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+18, 52608, 859, 1, 1, -11783.3, -1486.387, 33.7563, 1.190531, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+19, 52608, 859, 1, 1, -11809.28, -1484.692, 24.49204, 3.463718, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+20, 52608, 859, 1, 1, -11782.8, -1470.843, 46.29272, 4.252807, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+21, 52608, 859, 1, 1, -11822.7, -1502.291, 17.34015, 3.012293, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+22, 52608, 859, 1, 1, -11780.27, -1555.29, 19.35792, 0.2563448, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+23, 52608, 859, 1, 1, -11804.51, -1578.999, 21.13893, 0.1394307, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+24, 52608, 859, 1, 1, -11760.83, -1585.807, 21.15973, 3.632615, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+25, 52608, 859, 1, 1, -11776.56, -1586.949, 21.08788, 3.512361, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+26, 52608, 859, 1, 1, -11805.92, -1554.197, 20.35112, 4.501845, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+27, 52608, 859, 1, 1, -11818.82, -1518.761, 21.76202, 2.589756, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+29, 52608, 859, 1, 1, -11806.96, -1527.551, 20.02675, 1.753307, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+30, 52608, 859, 1, 1, -11817.96, -1538.781, 19.11438, 0.2710515, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+31, 52608, 859, 1, 1, -11790.95, -1519.145, 22.60167, 2.549459, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+32, 52608, 859, 1, 1, -11795.49, -1541.634, 19.40917, 1.835677, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+33, 52608, 859, 1, 1, -11826.72, -1537.868, 17.57409, 5.673232, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+34, 52608, 859, 1, 1, -11821.96, -1553.328, 21.72571, 1.923537, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+35, 52958, 859, 1, 1, -11795.54, -1561.05, 20.04483, 1.570796, 7200, 0, 0), -- Zandalari Hierophant (Area: 0) (possible waypoints or random movement)
(@CGUID+36, 52417, 859, 1, 1, -11746.04, -1427.178, -5.521123, 3.768479, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+37, 52417, 859, 1, 1, -11774.33, -1417.046, 3.438722, 6.068614, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+38, 52417, 859, 1, 1, -11732.29, -1442.186, -0.4210719, 0.1506264, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+39, 52608, 859, 1, 1, -11795.84, -1602.432, 37.04222, 0.8869356, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+40, 52608, 859, 1, 1, -11811.01, -1600.977, 37.04528, 1.160317, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+41, 52167, 859, 1, 1, -11840.63, -1596.266, 40.80637, 6.007871, 7200, 0, 0), -- Gurubashi Spirit Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+42, 52608, 859, 1, 1, -11820.37, -1579.831, 21.22956, 3.53091, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+43, 52608, 859, 1, 1, -11809.93, -1588.784, 21.14074, 3.626626, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+44, 52608, 859, 1, 1, -11825.53, -1588.164, 21.18313, 2.491601, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+45, 52608, 859, 1, 1, -11834.43, -1550.623, 24.48404, 0.8627666, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+46, 52608, 859, 1, 1, -11780.04, -1597.553, 37.04992, 0.2915721, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+47, 52608, 859, 1, 1, -11766.3, -1597.807, 37.05029, 1.697939, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+48, 52608, 859, 1, 1, -11795.22, -1630.397, 21.20461, 1.981118, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+49, 52608, 859, 1, 1, -11849.34, -1611.819, 21.18313, 5.43469, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+50, 52608, 859, 1, 1, -11836, -1622.686, 37.05189, 0.3046315, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+51, 52608, 859, 1, 1, -11738.17, -1618.654, 37.05585, 0.5286215, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+52, 52608, 859, 1, 1, -11782.13, -1633.952, 21.20405, 4.630546, 7200, 0, 0), -- Twisted Shadow (Area: 0) (possible waypoints or random movement)
(@CGUID+53, 52650, 859, 1, 1, -11786.5, -1690.92, 53.01943, 1.605703, 7200, 0, 0), -- Shadow of Hakkar (Area: Altar of the Blood God)
(@CGUID+54, 52167, 859, 1, 1, -11737.74, -1695.834, 40.80537, 2.899904, 7200, 0, 0), -- Gurubashi Spirit Warrior (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+55, 52608, 859, 1, 1, -11838.18, -1645.562, 33.78725, 1.8155, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+56, 52608, 859, 1, 1, -11835.21, -1669.712, 37.05335, 0.9248599, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+57, 52608, 859, 1, 1, -11740.41, -1644.338, 33.78836, 3.636508, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+58, 52608, 859, 1, 1, -11739.42, -1670.922, 37.04718, 5.97368, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+59, 52608, 859, 1, 1, -11779.52, -1650.612, 21.20443, 1.008923, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+60, 52608, 859, 1, 1, -11792.71, -1645.758, 21.20463, 5.308516, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+61, 52608, 859, 1, 1, -11789.82, -1661.349, 21.20449, 5.850589, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+62, 52608, 859, 1, 1, -11799.92, -1659.509, 21.20427, 0.8381915, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+63, 52608, 859, 1, 1, -11769.36, -1702.975, 21.18313, 0.5918737, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+64, 52608, 859, 1, 1, -11857.62, -1626.255, 21.18313, 1.843946, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+65, 52608, 859, 1, 1, -11720.5, -1641.883, 21.18313, 2.939372, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+66, 52608, 859, 1, 1, -11721.03, -1678.182, 21.18313, 5.298421, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+67, 52608, 859, 1, 1, -11726.44, -1625.674, 21.18313, 5.52238, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+68, 52608, 859, 1, 1, -11725.95, -1666.293, 21.18313, 5.364458, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+69, 52732, 859, 1, 1, -11737.55, -1592.141, 40.8897, 1.396263, 7200, 0, 0), -- Gurubashi Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+70, 52608, 859, 1, 1, -11781.24, -1711.857, 21.18313, 0.384528, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+71, 52608, 859, 1, 1, -11752.04, -1711.479, 21.18313, 2.93584, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+72, 52608, 859, 1, 1, -11802.32, -1706.628, 21.18313, 1.203769, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+73, 52413, 859, 1, 1, -11719.27, -1728.646, 14.28813, 2.11978, 7200, 0, 0), -- Zulian Gnasher (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+74, 52608, 859, 1, 1, -11820.38, -1713.578, 21.18313, 0.1656531, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+75, 52732, 859, 1, 1, -11735.41, -1695.665, 40.8887, 1.396263, 7200, 0, 0), -- Gurubashi Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+76, 52167, 859, 1, 1, -11826.84, -1696.22, 40.79424, 0.1289887, 7200, 0, 0), -- Gurubashi Spirit Warrior (Area: Altar of the Blood God)
(@CGUID+77, 52608, 859, 1, 1, -11849.03, -1651.741, 21.18313, 5.372521, 7200, 0, 0), -- Twisted Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+78, 52732, 859, 1, 1, -11837.96, -1698.877, 40.88797, 1.396263, 7200, 0, 0), -- Gurubashi Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+79, 52532, 859, 1, 1, -11811.9, -1637.995, 52.99569, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+80, 52532, 859, 1, 1, -11793.88, -1646.389, 54.6289, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+81, 52532, 859, 1, 1, -11782.06, -1646.38, 54.56368, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+82, 52532, 859, 1, 1, -11769.54, -1663.59, 53.06438, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+83, 52532, 859, 1, 1, -11788.62, -1628.262, 54.86021, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+84, 52430, 859, 1, 1, -11814.56, -1652.12, 52.96632, 0, 7200, 0, 0), -- Hakkar's Chains (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+85, 52430, 859, 1, 1, -11778.6, -1659.418, 53.06332, 0, 7200, 0, 0), -- Hakkar's Chains (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+86, 52430, 859, 1, 1, -11801.36, -1678.391, 53.04712, 0, 7200, 0, 0), -- Hakkar's Chains (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+87, 52532, 859, 1, 1, -11823.27, -1665.2, 53.08056, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+88, 52624, 859, 1, 1, -11835.58, -1669.868, 37.13591, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+89, 52532, 859, 1, 1, -11823.57, -1647.462, 52.87725, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+90, 52532, 859, 1, 1, -11816.96, -1682.873, 53.07767, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+91, 52624, 859, 1, 1, -11787.2, -1662.663, 21.28798, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+92, 52532, 859, 1, 1, -11751.88, -1662.833, 53.08055, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+93, 52532, 859, 1, 1, -11764.74, -1636.479, 52.98969, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+94, 52532, 859, 1, 1, -11752.42, -1645.153, 52.87562, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+95, 52532, 859, 1, 1, -11756.94, -1680.793, 53.0772, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+96, 52624, 859, 1, 1, -11770.24, -1704.986, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+97, 52222, 859, 1, 1, -11786.46, -1690.924, 53.01948, 1.605703, 7200, 0, 0), -- Spirit of Hakkar (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+98, 52624, 859, 1, 1, -11801.83, -1707.472, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+99, 52150, 859, 1, 1, -11786.32, -1715.629, 43.72891, 1.466077, 7200, 0, 0), -- Jin'do the Godbreaker (Area: Altar of the Blood God)
(@CGUID+100, 52532, 859, 1, 1, -11805.72, -1664.719, 53.06411, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+101, 52624, 859, 1, 1, -11778.95, -1651.964, 21.28785, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+102, 52624, 859, 1, 1, -11801.25, -1658.837, 21.28796, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+103, 52624, 859, 1, 1, -11795.19, -1642.288, 21.28803, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+104, 52624, 859, 1, 1, -11741.49, -1667.163, 37.13271, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+105, 52624, 859, 1, 1, -11785.48, -1712.26, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+106, 52624, 859, 1, 1, -11779.26, -1634.451, 21.28769, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+107, 52624, 859, 1, 1, -11793.98, -1628.469, 21.28791, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+108, 52532, 859, 1, 1, -11827.62, -1634.12, 52.93477, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+109, 52624, 859, 1, 1, -11836.25, -1647.847, 33.87125, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+110, 52532, 859, 1, 1, -11749.95, -1631.24, 52.89489, 0, 7200, 0, 0), -- Spirit Portal (Area: Altar of the Blood God)
(@CGUID+111, 52730, 859, 1, 1, -11738.46, -1699.685, 40.80568, 4.179193, 7200, 0, 0), -- Gurubashi Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+112, 52730, 859, 1, 1, -11840.79, -1697.064, 40.80489, 1.973359, 7200, 0, 0), -- Gurubashi Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+113, 52624, 859, 1, 1, -11818.23, -1713.25, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+114, 52624, 859, 1, 1, -11755.66, -1710.448, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+115, 52624, 859, 1, 1, -11739.23, -1643.625, 33.87124, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+116, 52624, 859, 1, 1, -11846.08, -1678.663, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+117, 52624, 859, 1, 1, -11727.28, -1663.969, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+118, 52624, 859, 1, 1, -11834.99, -1623.076, 37.13897, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+119, 52624, 859, 1, 1, -11741.92, -1621.774, 37.14146, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+120, 52624, 859, 1, 1, -11849.82, -1648.172, 21.26647, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+121, 52624, 859, 1, 1, -11799.4, -1601.337, 37.12932, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+122, 52624, 859, 1, 1, -11857.14, -1669, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+123, 52624, 859, 1, 1, -11783.46, -1598.425, 37.13646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+124, 52624, 859, 1, 1, -11719.14, -1678.552, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+125, 52624, 859, 1, 1, -11767.83, -1599.66, 37.1286, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+126, 52624, 859, 1, 1, -11723.77, -1642.7, 21.26647, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+127, 52624, 859, 1, 1, -11813.88, -1599.512, 37.13687, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+128, 52624, 859, 1, 1, -11726.46, -1623.274, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+129, 52624, 859, 1, 1, -11857.69, -1626.906, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+130, 52624, 859, 1, 1, -11848.01, -1613.785, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+132, 52730, 859, 1, 1, -11744.52, -1593.347, 40.80564, 3.461331, 7200, 0, 0), -- Gurubashi Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+133, 52624, 859, 1, 1, -11807.71, -1587.615, 21.20656, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+134, 52624, 859, 1, 1, -11775.46, -1586.406, 21.19078, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+135, 52624, 859, 1, 1, -11824.2, -1588.351, 21.26646, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+136, 52624, 859, 1, 1, -11759.88, -1585.58, 21.24965, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+137, 52624, 859, 1, 1, -11803.85, -1578.787, 21.1402, 3.344298, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+138, 52624, 859, 1, 1, -11817.73, -1579.653, 21.23468, 0.2347809, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+139, 52624, 859, 1, 1, -11768.82, -1576.151, 21.16704, 6.273685, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+140, 52624, 859, 1, 1, -11722.69, -1608.458, 21.18313, 5.213817, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+141, 52730, 859, 1, 1, -11735.41, -1695.668, 40.8887, 1.396263, 7200, 0, 0), -- Gurubashi Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+142, 52624, 859, 1, 1, -11835.58, -1669.868, 37.13591, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+143, 52624, 859, 1, 1, -11805.43, -1554.639, 22.92242, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+144, 52624, 859, 1, 1, -11834.26, -1550.083, 24.63889, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+145, 52624, 859, 1, 1, -11821.81, -1554.184, 21.5714, 0, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+146, 52624, 859, 1, 1, -11750.34, -1577.29, 21.14005, 1.459557, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+147, 52730, 859, 1, 1, -11837.96, -1698.88, 40.88797, 1.396263, 7200, 0, 0), -- Gurubashi Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+148, 52624, 859, 1, 1, -11818.42, -1539.88, 19.62292, 3.011675, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+149, 52624, 859, 1, 1, -11775.13, -1554.965, 19.89001, 6.119739, 7200, 0, 0), -- Twisted Spirit (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+150, 52732, 859, 1, 1, -11837.96, -1698.877, 40.88797, 1.396263, 7200, 0, 0), -- Gurubashi Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+151, 52732, 859, 1, 1, -11735.41, -1695.665, 40.8887, 1.396263, 7200, 0, 0), -- Gurubashi Shadow (Area: Altar of the Blood God) (possible waypoints or random movement)
(@CGUID+152, 53488, 859, 1, 1, -11915.67, -1273.872, 91.82314, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+153, 53488, 859, 1, 1, -11916.08, -1238.281, 92.37059, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+154, 53022, 859, 1, 1, -11920.77, -1260.319, 93.58132, 4.799655, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+155, 53040, 859, 1, 1, -11900.85, -1256.726, 85.22083, 4.869469, 7200, 0, 0), -- Vehini (Area: 0)
(@CGUID+156, 53151, 859, 1, 1, -11897.23, -1262.285, 85.22082, 6.056293, 7200, 0, 0), -- Overseer Blingbang (Area: 0) (possible waypoints or random movement)
(@CGUID+157, 53025, 859, 1, 1, -11896.45, -1265.318, 85.22083, 0.5061455, 7200, 0, 0), -- Bloodslayer Vaena (Area: 0)
(@CGUID+158, 53024, 859, 1, 1, -11894.4, -1261.25, 85.22083, 4.869469, 7200, 0, 0), -- Bloodslayer Zala (Area: 0)
(@CGUID+159, 53044, 859, 1, 1, -11941.06, -1257.727, 85.17756, 4.991642, 7200, 0, 0), -- Blackwater Ruffian (Area: 0)
(@CGUID+160, 53022, 859, 1, 1, -11901.58, -1274.755, 85.22063, 4.625123, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+161, 53023, 859, 1, 1, -11891.79, -1264.722, 85.22083, 2.75762, 7200, 0, 0), -- Bloodslayer T'ara (Area: 0)
(@CGUID+162, 53022, 859, 1, 1, -11896.07, -1274.472, 85.22058, 4.555309, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+163, 53043, 859, 1, 1, -11945.77, -1259.566, 85.19873, 5.427974, 7200, 0, 0), -- Briney Boltcutter (Area: 0)
(@CGUID+164, 53044, 859, 1, 1, -11947.63, -1264.618, 85.20743, 6.126106, 7200, 0, 0), -- Blackwater Ruffian (Area: 0)
(@CGUID+165, 53022, 859, 1, 1, -11944.61, -1283.602, 85.22083, 5.044002, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+166, 52417, 859, 1, 1, -11952.7, -1309.115, 71.76698, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+167, 53022, 859, 1, 1, -11876.68, -1282.91, 85.22083, 5.288348, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+168, 52377, 859, 1, 1, -11882.17, -1292.965, 82.21028, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+169, 52380, 859, 1, 1, -11894.79, -1327.844, 76.69714, 0.6981317, 7200, 0, 0), -- Venomancer Mauri (Area: 0) (possible waypoints or random movement)
(@CGUID+170, 52379, 859, 1, 1, -11923.16, -1337.484, 91.81541, 2.356194, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+171, 52373, 859, 1, 1, -11931.47, -1323.502, 83.89037, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+172, 52820, 859, 1, 1, -11881.98, -1276.274, 85.22083, 2.583087, 7200, 0, 0), -- Helpful Jungle Monkey (Area: 0)
(@CGUID+173, 52441, 859, 1, 1, -11891.05, -1287.505, 79.77172, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+174, 52417, 859, 1, 1, -11953.75, -1327.679, 69.08185, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+175, 52332, 859, 1, 1, -11908.6, -1340, 78.15495, 0.6981317, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+176, 45979, 859, 1, 1, -11885.97, -1319.922, 78.62692, 5.550147, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+177, 45979, 859, 1, 1, -11885.67, -1319.797, 78.64474, 0.5235988, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+178, 52529, 859, 1, 1, -11885.89, -1319.806, 77.92516, 0, 7200, 0, 0), -- Zanzil's Cauldron of Toxic Torment (Area: 0)
(@CGUID+179, 52377, 859, 1, 1, -11867.14, -1312.616, 84.41633, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+180, 52331, 859, 1, 1, -11873.05, -1333.924, 77.23435, 2.338741, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+181, 52417, 859, 1, 1, -11947.69, -1339.764, 67.72157, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+182, 52379, 859, 1, 1, -11914.75, -1351.095, 91.65027, 2.356194, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+183, 52377, 859, 1, 1, -11868.95, -1322.021, 80.65288, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+184, 52331, 859, 1, 1, -11913.07, -1351.063, 81.62288, 0.6108652, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+185, 52417, 859, 1, 1, -11941.4, -1348.224, 72.73904, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+186, 52376, 859, 1, 1, -11855.3, -1315.33, 85.12354, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+187, 52442, 859, 1, 1, -11782.1, -1279.986, 64.29343, 4.537856, 7200, 0, 0), -- Florawing Hive Queen (Area: 0)
(@CGUID+188, 52418, 859, 1, 1, -11789.37, -1369.764, 6.167751, 0.1396263, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+189, 52062, 859, 1, 1, -11612.73, -1283.434, 78.47877, 0, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+190, 52062, 859, 1, 1, -11570.48, -1313.092, 79.32548, 0, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+191, 52062, 859, 1, 1, -11564.18, -1258.804, 78.7486, 0, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+192, 52331, 859, 1, 1, -11922.11, -1338.451, 78.43595, 0.3839724, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+193, 45979, 859, 1, 1, -11895.07, -1346.483, 85.172, 1.570796, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+194, 52377, 859, 1, 1, -11896.04, -1285.335, 81.58699, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+195, 52373, 859, 1, 1, -11925.22, -1317.094, 82.6544, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+196, 52062, 859, 1, 1, -11526.5, -1256.372, 87.43623, 3.874631, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+197, 52062, 859, 1, 1, -11531.41, -1292.224, 83.74413, 2.321288, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+198, 52062, 859, 1, 1, -11572.96, -1272.288, 77.63614, 0, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+199, 52062, 859, 1, 1, -11624.91, -1275.042, 87.38938, 6.038839, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+200, 52062, 859, 1, 1, -11529.26, -1254.09, 87.56752, 3.944444, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+201, 52062, 859, 1, 1, -11534.74, -1225.665, 85.62653, 3.787364, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+202, 52062, 859, 1, 1, -11529.36, -1292.839, 87.39558, 2.391101, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+203, 52062, 859, 1, 1, -11623.1, -1276.964, 83.83668, 6.056293, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+204, 52062, 859, 1, 1, -11529.5, -1256.811, 83.36958, 3.769911, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+205, 52062, 859, 1, 1, -11627.19, -1354.398, 86.69896, 0.8726646, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+206, 52062, 859, 1, 1, -11607.36, -1223.03, 84.68561, 5.201081, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+207, 52062, 859, 1, 1, -11532.11, -1294.953, 87.50522, 2.321288, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+208, 52062, 859, 1, 1, -11609.91, -1222.703, 87.91895, 5.201081, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+209, 52062, 859, 1, 1, -11625.24, -1278.439, 87.4016, 6.091199, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+210, 52062, 859, 1, 1, -11537.24, -1223.78, 85.80284, 4.223697, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+211, 52062, 859, 1, 1, -11536.58, -1225.099, 81.77989, 4.18879, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+212, 52062, 859, 1, 1, -11626.54, -1357.786, 86.3576, 0.9075712, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+213, 52062, 859, 1, 1, -11607.36, -1220.115, 87.66179, 5.183628, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+214, 52062, 859, 1, 1, -11623.68, -1355.396, 82.23634, 0.9424778, 7200, 0, 0), -- Zanzil's Toxic Gas (Area: 0)
(@CGUID+215, 52441, 859, 1, 1, -11929.21, -1315.946, 79.64759, 0.9424778, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+216, 52375, 859, 1, 1, -11890.61, -1292.873, 84.60121, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+217, 45979, 859, 1, 1, -11873.73, -1346.764, 86.93372, 1.605703, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+218, 52379, 859, 1, 1, -11884.84, -1369.794, 81.49525, 3.820872, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+219, 52332, 859, 1, 1, -11876.95, -1351.474, 73.7497, 2.181662, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+220, 52332, 859, 1, 1, -11893.37, -1364.859, 71.26846, 1.117011, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+221, 52379, 859, 1, 1, -11905.89, -1365.877, 88.1031, 2.388578, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+222, 52379, 859, 1, 1, -11922.69, -1367.561, 92.29707, 0.3932513, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+223, 52331, 859, 1, 1, -11904.51, -1367.233, 70.22238, 0.08726646, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+224, 52331, 859, 1, 1, -11919.57, -1373.58, 78.72769, 0, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+225, 52331, 859, 1, 1, -11870.79, -1359.635, 71.648, 0.08726646, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+226, 52331, 859, 1, 1, -11920.3, -1362.602, 81.62651, 1.832596, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+227, 52331, 859, 1, 1, -11880.15, -1364.533, 70.21749, 2.076942, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+228, 52331, 859, 1, 1, -11889.09, -1353.648, 72.84684, 1.064651, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+229, 52332, 859, 1, 1, -11865.88, -1339.238, 76.13886, 5.846853, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+230, 52331, 859, 1, 1, -11862.23, -1353.512, 68.50238, 5.410521, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+231, 52379, 859, 1, 1, -11862.85, -1346.579, 93.76714, 3.4967, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+232, 52418, 859, 1, 1, -11812.91, -1425.062, 7.114854, 4.930093, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+233, 52417, 859, 1, 1, -11946.92, -1368.725, 69.14185, 0.02506192, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+234, 52331, 859, 1, 1, -11907.77, -1376.747, 69.05946, 0.7330383, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+235, 52331, 859, 1, 1, -11889.24, -1374.811, 68.40027, 0.541052, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+236, 52332, 859, 1, 1, -11927.12, -1378.569, 83.79979, 1.745329, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+237, 52379, 859, 1, 1, -11865.33, -1365.281, 76.92286, 2.678216, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+238, 52331, 859, 1, 1, -11886.01, -1388.363, 65.34296, 3.735005, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+239, 52331, 859, 1, 1, -11897.94, -1390.129, 66.43561, 5.707227, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+240, 52331, 859, 1, 1, -11867.62, -1388.031, 67.13773, 5.846853, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+241, 52379, 859, 1, 1, -11928.51, -1392.557, 91.91876, 5.704051, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+242, 52331, 859, 1, 1, -11933.51, -1395.151, 80.40403, 1.37881, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+243, 52379, 859, 1, 1, -11892.14, -1390.298, 74.90738, 4.138957, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+244, 52331, 859, 1, 1, -11895.55, -1377.738, 68.84412, 2.321288, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+245, 52332, 859, 1, 1, -11902.71, -1382.641, 67.89508, 5.462881, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+246, 52331, 859, 1, 1, -11874.93, -1379.123, 68.50045, 3.752458, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+247, 52417, 859, 1, 1, -11943.99, -1383.797, 71.39723, 1.656838, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+248, 52332, 859, 1, 1, -11866.25, -1376.552, 71.29253, 3.612832, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+249, 52331, 859, 1, 1, -11861.1, -1370.488, 71.27198, 6.161012, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+250, 52089, 859, 1, 1, -11825.01, -1321.108, 66.36481, 3.804818, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+251, 52418, 859, 1, 1, -11925.16, -1473.438, 4.500498, 1.951702, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+252, 52529, 859, 1, 1, -11880.01, -1404.913, 62.07856, 0, 7200, 0, 0), -- Zanzil's Cauldron of Toxic Torment (Area: 0)
(@CGUID+253, 52331, 859, 1, 1, -11870.22, -1398.175, 64.73029, 3.961897, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+254, 52331, 859, 1, 1, -11889.4, -1398.552, 63.45974, 2.007129, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+255, 52332, 859, 1, 1, -11937.64, -1406.05, 83.56258, 0.3316126, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+256, 52331, 859, 1, 1, -11914.61, -1407.899, 59.44876, 4.712389, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+257, 52332, 859, 1, 1, -11897.27, -1403.729, 61.59669, 5.689773, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+258, 52379, 859, 1, 1, -11906.15, -1409.755, 69.81449, 2.201301, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+259, 52379, 859, 1, 1, -11869.04, -1404.568, 80.64326, 0.1983072, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+260, 52418, 859, 1, 1, -11755.41, -1408.22, 4.857337, 0.2525529, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+261, 52418, 859, 1, 1, -11856.59, -1490.872, 4.923193, 1.826948, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+262, 52332, 859, 1, 1, -11888.47, -1426.142, 58.96961, 2.879793, 7200, 0, 0), -- Toxic Venomspitter (Area: 0)
(@CGUID+263, 52331, 859, 1, 1, -11920.39, -1418.031, 54.95126, 4.468043, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+264, 52331, 859, 1, 1, -11908.13, -1420.483, 52.02427, 4.939282, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+265, 52331, 859, 1, 1, -11869.42, -1409.717, 63.1772, 2.408554, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+266, 52379, 859, 1, 1, -11886.23, -1419.5, 74.03656, 1.672974, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+267, 52331, 859, 1, 1, -11879.3, -1416.125, 61.51482, 3.228859, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+268, 52331, 859, 1, 1, -11923.72, -1431.863, 46.23868, 0.7679449, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+269, 52379, 859, 1, 1, -11946.46, -1408.439, 96.67417, 4.190343, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+270, 52331, 859, 1, 1, -11907.49, -1432.788, 49.09475, 3.612832, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+271, 52331, 859, 1, 1, -11900.89, -1412.929, 56.23951, 6.161012, 7200, 0, 0), -- Mutated Overgrowth (Area: 0)
(@CGUID+272, 52377, 859, 1, 1, -11803.08, -1291.95, 77.78139, 5.322102, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+273, 52440, 859, 1, 1, -11856.83, -1524.406, 20.09202, 1.797689, 7200, 0, 0), -- Gub (Area: 0) (possible waypoints or random movement)
(@CGUID+274, 52379, 859, 1, 1, -11922.65, -1462.714, 35.22865, 4.992262, 7200, 0, 0), -- Venomtip Needler (Area: 0)
(@CGUID+275, 52417, 859, 1, 1, -11920.38, -1463.064, -0.327136, 1.104416, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+276, 52413, 859, 1, 1, -11892.94, -1477.028, 3.084538, 3.941981, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+277, 52417, 859, 1, 1, -11881.81, -1479.866, 3.827913, 1.092355, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+278, 52413, 859, 1, 1, -11913.52, -1480.036, 8.409369, 2.377297, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+279, 52417, 859, 1, 1, -11942.15, -1449.796, -0.339416, 3.980591, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+280, 52413, 859, 1, 1, -11895.06, -1486.359, 10.30817, 6.067801, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+281, 52417, 859, 1, 1, -11822.55, -1434.786, -0.4953196, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+282, 52417, 859, 1, 1, -11838.06, -1462.857, 0.380622, 5.885613, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+283, 52413, 859, 1, 1, -11894.29, -1494.236, 12.90998, 3.707345, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+284, 52413, 859, 1, 1, -11908.7, -1493.12, 12.77556, 0.3683213, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+285, 52417, 859, 1, 1, -11938.42, -1472.35, 3.673245, 5.010537, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+286, 52417, 859, 1, 1, -11857.55, -1474.211, -9.455076, 0.7855358, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+287, 52413, 859, 1, 1, -11896.91, -1502.483, 15.12609, 5.601407, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+288, 52413, 859, 1, 1, -11876.6, -1502.677, 7.174099, 4.870398, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+289, 52413, 859, 1, 1, -11913.33, -1503.829, 14.79646, 0.8049024, 7200, 0, 0), -- Zulian Gnasher (Area: 0) (possible waypoints or random movement)
(@CGUID+290, 52441, 859, 1, 1, -11977.89, -1409.01, 89.51551, 3.976614, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+291, 52417, 859, 1, 1, -11944.1, -1492.941, 0.840617, 4.551582, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+292, 52376, 859, 1, 1, -11890.77, -1508.938, 22.3128, 5.080555, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+293, 45979, 859, 1, 1, -11852.2, -1499.587, 8.802026, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+294, 45979, 859, 1, 1, -11869.54, -1504.783, 8.93495, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+295, 52340, 859, 1, 1, -11945.29, -1545.023, 39.75023, 1.32645, 7200, 0, 0), -- Tiki Lord Mu'Loa (Area: 0) (possible waypoints or random movement)
(@CGUID+296, 52418, 859, 1, 1, -11903.14, -1605.689, 4.04494, 2.318715, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+297, 52089, 859, 1, 1, -11979.18, -1533.842, 46.76085, 2.391101, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+298, 45979, 859, 1, 1, -11953.84, -1540.958, 44.95029, 1.448623, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+299, 52089, 859, 1, 1, -11967.15, -1524.109, 41.84551, 2.600541, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+300, 45979, 859, 1, 1, -11936.06, -1543.465, 44.65055, 1.466077, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+301, 52375, 859, 1, 1, -11898.82, -1550.469, 32.47108, 4.971496, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+302, 52441, 859, 1, 1, -11978.03, -1519.224, 54.2801, 4.059264, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+303, 52417, 859, 1, 1, -11884.91, -1565.441, 5.386901, 5.452555, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+304, 52441, 859, 1, 1, -11990.83, -1534.731, 58.02654, 4.17832, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+305, 52377, 859, 1, 1, -11904.14, -1557.421, 35.37805, 4.257785, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+306, 52089, 859, 1, 1, -11973.88, -1560.233, 40.28425, 5.427974, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+307, 52089, 859, 1, 1, -11887.7, -1527.288, 22.91233, 5.375614, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+308, 52375, 859, 1, 1, -11961.95, -1518.936, 42.02428, 4.122398, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+309, 52441, 859, 1, 1, -11971.62, -1515.706, 52.44604, 0.657342, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+310, 52376, 859, 1, 1, -11959.82, -1550.182, 42.15764, 1.067669, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+311, 45979, 859, 1, 1, -11858.22, -1510.84, 8.103023, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+312, 52417, 859, 1, 1, -11858.98, -1512.341, -5.987651, 2.575927, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+313, 52417, 859, 1, 1, -11854.69, -1503.414, -0.732681, 3.057783, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+314, 52417, 859, 1, 1, -11865.46, -1538.982, 4.49964, 0.8348627, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+315, 52418, 859, 1, 1, -11898.4, -1689.808, 5.154553, 4.743316, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: 0) (possible waypoints or random movement)
(@CGUID+316, 52414, 859, 1, 1, -12020.18, -1589.325, 14.2777, 0.2094395, 7200, 0, 0), -- Tor-Tun (Area: 0)
(@CGUID+317, 52417, 859, 1, 1, -11888.38, -1588.415, 5.532668, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+318, 52417, 859, 1, 1, -11927.65, -1593.542, -2.95887, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+319, 52151, 859, 1, 1, -12362.04, -1911.49, 127.3196, 1.32645, 7200, 0, 0), -- Bloodlord Mandokir (Area: 0) (possible waypoints or random movement)
(@CGUID+320, 52376, 859, 1, 1, -11946.46, -1619.986, 43.74409, 1.901731, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+321, 52417, 859, 1, 1, -11909.25, -1612.413, -7.376473, 4.413626, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+322, 52089, 859, 1, 1, -11995.33, -1612.127, 36.88533, 1.53589, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+323, 52155, 859, 1, 1, -12020.37, -1699.781, 39.62218, 0.6981317, 7200, 0, 0), -- High Priest Venoxis (Area: 0) (possible waypoints or random movement)
(@CGUID+324, 52148, 859, 1, 1, -11788.24, -1650.073, 54.05426, 4.764749, 7200, 0, 0), -- Jin'do the Godbreaker (Area: 0) (possible waypoints or random movement)
(@CGUID+325, 52402, 859, 1, 1, -11947.91, -1631.902, 39.34916, 6.036406, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+326, 52402, 859, 1, 1, -11978.78, -1629.129, 37.99313, 2.617556, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+327, 52089, 859, 1, 1, -11948.96, -1634.16, 39.25303, 5.061455, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+328, 52089, 859, 1, 1, -11942.11, -1640.839, 42.6086, 0.1396263, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+329, 52381, 859, 1, 1, -11975.04, -1647.241, 34.71352, 0.3316126, 7200, 0, 0), -- Venomancer T'Kulu (Area: 0) (possible waypoints or random movement)
(@CGUID+330, 45979, 859, 1, 1, -11962.6, -1643.234, 37.56361, 3.543018, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+331, 52529, 859, 1, 1, -11963.85, -1643.328, 36.7988, 0, 7200, 0, 0), -- Zanzil's Cauldron of Toxic Torment (Area: 0)
(@CGUID+332, 45979, 859, 1, 1, -11962.64, -1643.238, 37.55449, 3.525565, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+333, 52402, 859, 1, 1, -11986.29, -1644.688, 34.5438, 1.804956, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+334, 52417, 859, 1, 1, -11901.33, -1635.206, -2.913975, 0.2212515, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+335, 52376, 859, 1, 1, -11952.81, -1648.531, 42.34005, 5.02645, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+336, 52402, 859, 1, 1, -12003.98, -1646.418, 35.36646, 1.876479, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+337, 52402, 859, 1, 1, -12026.29, -1639.985, 38.75135, 0.7324108, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+338, 52377, 859, 1, 1, -12036.99, -1635.665, 44.2407, 1.561647, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+339, 52377, 859, 1, 1, -12009.55, -1627.928, 39.21195, 5.083626, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+340, 52402, 859, 1, 1, -11964.6, -1654.996, 36.81807, 3.01046, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+341, 52402, 859, 1, 1, -11976.84, -1677.483, 33.12841, 2.1942, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+342, 52417, 859, 1, 1, -11903.2, -1657.302, -2.735437, 1.545714, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+343, 52441, 859, 1, 1, -11971.76, -1667.193, 51.28594, 2.199115, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+344, 52311, 859, 1, 1, -12010.71, -1681.177, 32.36689, 0.6283185, 7200, 0, 0), -- Venomguard Destroyer (Area: 0) (possible waypoints or random movement)
(@CGUID+345, 52311, 859, 1, 1, -12000.22, -1697.701, 32.36689, 0.5235988, 7200, 0, 0), -- Venomguard Destroyer (Area: 0) (possible waypoints or random movement)
(@CGUID+346, 52402, 859, 1, 1, -12018.32, -1664.487, 32.99401, 1.177795, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+347, 45979, 859, 1, 1, -12025.06, -1666.8, 41.47248, 5.044002, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+348, 45979, 859, 1, 1, -11967.27, -1694.63, 34.36831, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+349, 45979, 859, 1, 1, -12034.42, -1671.429, 39.70014, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+350, 45979, 859, 1, 1, -12010.53, -1693.469, 32.36689, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+351, 45979, 859, 1, 1, -12021.83, -1688.281, 43.45235, 0.5585054, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+352, 45979, 859, 1, 1, -12013.68, -1695.356, 34.79553, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+353, 52417, 859, 1, 1, -11929.26, -1697.114, -3.725104, 2.820583, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+354, 52402, 859, 1, 1, -12048.72, -1653.27, 41.52928, 3.21582, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+355, 45979, 859, 1, 1, -12036.87, -1678.578, 39.39857, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+356, 45979, 859, 1, 1, -12016.98, -1697.563, 37.90731, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+357, 45979, 859, 1, 1, -12031.15, -1686.852, 39.48942, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+358, 52402, 859, 1, 1, -11973.64, -1710.101, 32.75881, 4.79577, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+359, 45979, 859, 1, 1, -12027.45, -1693.599, 39.45731, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+360, 52417, 859, 1, 1, -11908.97, -1688.334, -1.350705, 5.495922, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+361, 45979, 859, 1, 1, -12036.99, -1686.635, 39.39523, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+362, 45979, 859, 1, 1, -12011.01, -1705.972, 43.47624, 0.5235988, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+363, 45979, 859, 1, 1, -12022.35, -1700.566, 39.5043, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+364, 52402, 859, 1, 1, -11988.06, -1716.059, 32.50619, 1.188337, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+365, 45979, 859, 1, 1, -12018.95, -1707.238, 39.45595, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+366, 45979, 859, 1, 1, -12037.2, -1694.578, 39.35389, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+367, 45979, 859, 1, 1, -11983.18, -1719.927, 42.89573, 1.884956, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+368, 45979, 859, 1, 1, -12032.09, -1700.49, 39.40034, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+369, 45979, 859, 1, 1, -12027.89, -1705.49, 39.39857, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+370, 45979, 859, 1, 1, -12015.82, -1713.219, 39.3736, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+371, 45979, 859, 1, 1, -12038.08, -1698.085, 47.80778, 0.08726646, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+372, 52402, 859, 1, 1, -12063.02, -1663.964, 43.90903, 4.409544, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+373, 52441, 859, 1, 1, -12066.11, -1649.488, 57.21412, 0.5067089, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+374, 45979, 859, 1, 1, -12026.18, -1712.125, 39.39877, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+375, 45979, 859, 1, 1, -12005.54, -1722.988, 39.43696, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+376, 45979, 859, 1, 1, -12037.23, -1705.58, 40.36355, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+377, 45979, 859, 1, 1, -12021.56, -1718.474, 39.34007, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+378, 45979, 859, 1, 1, -12000.82, -1727.632, 39.41531, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+379, 45979, 859, 1, 1, -12013.56, -1723.382, 39.3954, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+380, 45979, 859, 1, 1, -12024.66, -1720.476, 47.76387, 0.9250245, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+381, 45979, 859, 1, 1, -12031.1, -1717.536, 39.78202, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+382, 45979, 859, 1, 1, -12019.1, -1724.892, 39.62766, 0, 7200, 0, 0), -- General Purpose Bunny JMF (Area: 0)
(@CGUID+383, 52405, 859, 1, 1, -12012.75, -1805.311, 57.70499, 4.625123, 7200, 0, 0), -- Mor'Lek the Dismantler (Area: 0)
(@CGUID+384, 52422, 859, 1, 1, -12116.83, -1749.484, 80.16071, 1.43117, 7200, 0, 0), -- Kaulema the Mover (Area: 0)
(@CGUID+385, 52419, 859, 1, 1, -11933.25, -1824.54, 51.78383, 1.53589, 7200, 0, 0), -- Tiki Torch (Area: 0)
(@CGUID+386, 52419, 859, 1, 1, -11919.82, -1824.582, 51.45897, 1.53589, 7200, 0, 0), -- Tiki Torch (Area: 0)
(@CGUID+387, 52419, 859, 1, 1, -11903.52, -1824.379, 51.55421, 1.518436, 7200, 0, 0), -- Tiki Torch (Area: 0)
(@CGUID+388, 52376, 859, 1, 1, -12075.77, -1685.004, 47.1365, 1.902409, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+389, 52402, 859, 1, 1, -12069.29, -1678.224, 43.76827, 3.214993, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+390, 52402, 859, 1, 1, -12072.5, -1704.078, 46.4384, 3.665191, 7200, 0, 0), -- Venomtooth (Area: 0)
(@CGUID+391, 52375, 859, 1, 1, -12081.47, -1678.102, 51.98904, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+392, 52375, 859, 1, 1, -12083.15, -1690.564, 50.53361, 1.902409, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+393, 52377, 859, 1, 1, -12015.12, -1740.755, 58.20934, 5.132976, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+394, 52373, 859, 1, 1, -12076.67, -1707.71, 47.97116, 1.902409, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+395, 52413, 859, 1, 1, -11880.64, -1670.642, 14.34169, 1.31538, 7200, 0, 0), -- Zulian Gnasher (Area: The Coil) (possible waypoints or random movement)
(@CGUID+396, 52323, 859, 1, 1, -11974.06, -1743.486, 53.27552, 4.974188, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+397, 52323, 859, 1, 1, -11960.54, -1742.845, 52.77715, 4.328416, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+398, 52323, 859, 1, 1, -11968.6, -1745.585, 52.95988, 4.747295, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+399, 52323, 859, 1, 1, -11978.65, -1747.905, 53.087, 5.305801, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+400, 52323, 859, 1, 1, -11963.79, -1749.5, 53.48859, 4.415683, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+401, 52323, 859, 1, 1, -11970.34, -1751.852, 53.11129, 4.747295, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+402, 52323, 859, 1, 1, -11975.4, -1754.052, 52.77481, 5.288348, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+403, 52323, 859, 1, 1, -11957.43, -1750.849, 54.02831, 3.787364, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+404, 52323, 859, 1, 1, -11966.1, -1755.179, 53.53751, 4.34587, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+405, 52323, 859, 1, 1, -11960.93, -1756.031, 53.89244, 3.961897, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+406, 52089, 859, 1, 1, -11938.97, -1732.852, 52.34692, 1.832596, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+407, 52402, 859, 1, 1, -12040.79, -1738.815, 52.64468, 0.7879214, 7200, 0, 0), -- Venomtooth (Area: The Coil)
(@CGUID+408, 52402, 859, 1, 1, -12070.33, -1722.224, 48.44512, 4.763386, 7200, 0, 0), -- Venomtooth (Area: The Coil)
(@CGUID+409, 52376, 859, 1, 1, -12049.99, -1740.804, 57.77876, 2.073869, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+410, 52089, 859, 1, 1, -11943.14, -1749.589, 53.09305, 4.08407, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+411, 52377, 859, 1, 1, -12059.34, -1735.087, 55.64105, 4.039321, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+412, 52377, 859, 1, 1, -12085.14, -1702.768, 52.05388, 2.48879, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+413, 52376, 859, 1, 1, -12079.97, -1714.89, 52.10005, 4.33959, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+414, 52402, 859, 1, 1, -12067.67, -1732.424, 52.41069, 2.421949, 7200, 0, 0), -- Venomtooth (Area: The Coil)
(@CGUID+415, 52419, 859, 1, 1, -11879.63, -1824.806, 50.88393, 1.466077, 7200, 0, 0), -- Tiki Torch (Area: The Coil)
(@CGUID+416, 52089, 859, 1, 1, -12014.15, -1769.214, 56.20074, 4.712389, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+417, 52089, 859, 1, 1, -12004.95, -1769.79, 58.93688, 4.485496, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+418, 52089, 859, 1, 1, -12001.15, -1777.606, 59.40263, 4.45059, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+419, 52089, 859, 1, 1, -12012.07, -1775.422, 57.21777, 4.590216, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+420, 52322, 859, 1, 1, -11968.73, -1763.431, 53.10692, 1.396263, 7200, 0, 0), -- Witch Doctor Qu'in (Area: The Coil) (possible waypoints or random movement)
(@CGUID+421, 52323, 859, 1, 1, -11958.5, -1761.606, 53.71722, 3.368485, 7200, 0, 0), -- Chosen of Hethiss (Area: The Coil) (possible waypoints or random movement)
(@CGUID+422, 52413, 859, 1, 1, -11908.16, -1723.874, 12.56899, 3.566026, 7200, 0, 0), -- Zulian Gnasher (Area: The Coil) (possible waypoints or random movement)
(@CGUID+423, 52417, 859, 1, 1, -11904.62, -1704.241, 1.437358, 3.612258, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Coil) (possible waypoints or random movement)
(@CGUID+424, 52419, 859, 1, 1, -11849.47, -1824.582, 51.48134, 1.553343, 7200, 0, 0), -- Tiki Torch (Area: The Coil)
(@CGUID+425, 52419, 859, 1, 1, -11864.58, -1824.444, 51.1218, 1.500983, 7200, 0, 0), -- Tiki Torch (Area: The Coil)
(@CGUID+426, 52302, 859, 1, 1, -12014.35, -1683.533, 32.37803, 2.490533, 7200, 0, 0), -- Venomous Effusion Stalker (Area: The Coil) (possible waypoints or random movement)
(@CGUID+427, 52302, 859, 1, 1, -12003.05, -1699.201, 32.39469, 5.730771, 7200, 0, 0), -- Venomous Effusion Stalker (Area: The Coil) (possible waypoints or random movement)
(@CGUID+428, 52441, 859, 1, 1, -12087.46, -1683.506, 71.06385, 4.765018, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Coil)
(@CGUID+429, 52089, 859, 1, 1, -12021.13, -1778.075, 58.30375, 4.747295, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+430, 52441, 859, 1, 1, -12088.83, -1707.621, 71.05639, 4.676568, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Coil)
(@CGUID+431, 52376, 859, 1, 1, -11995.38, -1779.725, 64.09776, 3.802506, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+432, 52364, 859, 1, 1, -11886.26, -1868.925, 63.58854, 2.059489, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+433, 52364, 859, 1, 1, -11880.48, -1866.984, 64.158, 0.2766776, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+434, 52364, 859, 1, 1, -11878.6, -1865.491, 63.58854, 2.268928, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+435, 52364, 859, 1, 1, -11882.69, -1865.774, 63.58854, 2.181662, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+436, 52364, 859, 1, 1, -11887.64, -1872.33, 63.58854, 1.972222, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+437, 52364, 859, 1, 1, -11881.83, -1865.572, 71.55318, 1.922454, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+438, 52364, 859, 1, 1, -11873.97, -1865.767, 63.58854, 2.356194, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+439, 52413, 859, 1, 1, -11877.08, -1677.084, 15.36562, 1.554059, 7200, 0, 0), -- Zulian Gnasher (Area: The Coil) (possible waypoints or random movement)
(@CGUID+440, 52377, 859, 1, 1, -11890.76, -1745.83, 12.80266, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+441, 52413, 859, 1, 1, -11883.26, -1751.578, 10.43144, 0.3197761, 7200, 0, 0), -- Zulian Gnasher (Area: The Coil) (possible waypoints or random movement)
(@CGUID+442, 52417, 859, 1, 1, -11880.41, -1723.677, 4.885028, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Coil) (possible waypoints or random movement)
(@CGUID+443, 52364, 859, 1, 1, -11870.1, -1869.215, 63.58854, 2.356194, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+444, 52417, 859, 1, 1, -11865.13, -1745.333, 5.215191, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Coil) (possible waypoints or random movement)
(@CGUID+445, 52364, 859, 1, 1, -11887.7, -1877.316, 63.63368, 1.919862, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+446, 52364, 859, 1, 1, -11868.64, -1873.748, 63.58854, 2.303835, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+447, 52364, 859, 1, 1, -11888.02, -1869.655, 71.7674, 3.134003, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+448, 52364, 859, 1, 1, -11884.51, -1882.616, 63.86458, 1.937315, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+449, 52302, 859, 1, 1, -12014.37, -1683.524, 32.37819, 2.490533, 7200, 0, 0), -- Venomous Effusion Stalker (Area: The Coil) (possible waypoints or random movement)
(@CGUID+450, 52302, 859, 1, 1, -12003.04, -1699.209, 32.39508, 5.730771, 7200, 0, 0), -- Venomous Effusion Stalker (Area: The Coil) (possible waypoints or random movement)
(@CGUID+451, 52364, 859, 1, 1, -11872.36, -1883.231, 63.65233, 2.129302, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+452, 52364, 859, 1, 1, -11878.17, -1884.071, 63.90799, 2.042035, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+453, 52364, 859, 1, 1, -11868.1, -1878.995, 63.58854, 2.234021, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+454, 52364, 859, 1, 1, -11876.42, -1879.873, 71.62801, 1.248572, 7200, 0, 0), -- Ritual Tiki Mask (Area: The Coil) (possible waypoints or random movement)
(@CGUID+455, 52608, 859, 1, 1, -11856.99, -1669.047, 21.26646, 0, 7200, 0, 0), -- Twisted Shadow (Area: The Coil) (possible waypoints or random movement)
(@CGUID+456, 52608, 859, 1, 1, -11845.7, -1678.26, 21.18313, 3.580742, 7200, 0, 0), -- Twisted Shadow (Area: The Coil) (possible waypoints or random movement)
(@CGUID+457, 52055, 859, 1, 1, -11538.56, -1254.118, 79.2066, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+458, 52417, 859, 1, 1, -11821.07, -1420.984, 3.06104, 3.634255, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+459, 52417, 859, 1, 1, -11819.27, -1383.876, -0.54005, 1.362409, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+460, 52417, 859, 1, 1, -11809.37, -1425.281, -1.141196, 2.612564, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+461, 52441, 859, 1, 1, -12100.88, -1726.425, 92.19883, 1.607865, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Coil)
(@CGUID+462, 52376, 859, 1, 1, -12061.23, -1771.374, 71.51829, 4.742678, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+463, 52375, 859, 1, 1, -12067.81, -1780.017, 72.0853, 5.980674, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+464, 52441, 859, 1, 1, -12043.72, -1792.271, 72.01109, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Coil)
(@CGUID+465, 52377, 859, 1, 1, -12061.65, -1793.795, 75.74282, 1.538603, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+466, 52441, 859, 1, 1, -12132.31, -1739.55, 93.63912, 1.784907, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Coil)
(@CGUID+467, 52376, 859, 1, 1, -12075.39, -1801.393, 80.60693, 4.166294, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+468, 52089, 859, 1, 1, -12114.36, -1783.049, 80.42609, 1.675516, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+469, 52089, 859, 1, 1, -12120.75, -1779.318, 80.32635, 1.396263, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+470, 52089, 859, 1, 1, -12125.11, -1783.821, 80.81445, 1.32645, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+471, 52089, 859, 1, 1, -12114.06, -1793.097, 80.43148, 3.368485, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+472, 52373, 859, 1, 1, -11996.54, -1801.09, 63.24389, 1.531319, 7200, 0, 0), -- Florawing Needler (Area: The Coil)
(@CGUID+473, 52089, 859, 1, 1, -12118.58, -1795.01, 80.27268, 1.047198, 7200, 0, 0), -- Gurubashi Worker (Area: The Coil)
(@CGUID+474, 52441, 859, 1, 1, -12100.93, -1811.019, 93.83914, 0.471857, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+475, 52352, 859, 1, 1, -12127.52, -1809.635, 81.46368, 3.281219, 7200, 0, 0), -- Boulder Target (Area: 0)
(@CGUID+476, 52352, 859, 1, 1, -12116.74, -1818.283, 80.24007, 3.281219, 7200, 0, 0), -- Boulder Target (Area: 0)
(@CGUID+477, 52352, 859, 1, 1, -12125.91, -1827.865, 81.23584, 2.96706, 7200, 0, 0), -- Boulder Target (Area: 0)
(@CGUID+478, 52441, 859, 1, 1, -11998.1, -1821.198, 79.62219, 4.828201, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+479, 52348, 859, 1, 1, -12241.98, -1819.156, 130.19, 6.265732, 7200, 0, 0), -- Berserking Boulder Roller (Area: 0) (possible waypoints or random movement)
(@CGUID+480, 52606, 859, 1, 1, -12257.13, -1849.392, 131.8583, 0.9250245, 7200, 0, 0), -- Gurubashi Warmonger (Area: 0)
(@CGUID+481, 52089, 859, 1, 1, -12253.93, -1835.569, 131.9226, 4.712389, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+482, 52441, 859, 1, 1, -12244.52, -1847.352, 152.4462, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+483, 52089, 859, 1, 1, -12287.85, -1871.958, 131.561, 0.3490658, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+484, 52606, 859, 1, 1, -12305.16, -1828.465, 130.3579, 0.05235988, 7200, 0, 0), -- Gurubashi Warmonger (Area: 0) (possible waypoints or random movement)
(@CGUID+485, 52076, 859, 1, 1, -12296.75, -1833.618, 130.395, 2.338741, 7200, 0, 0), -- Gurubashi Cauldron-Mixer (Area: 0) (possible waypoints or random movement)
(@CGUID+486, 52956, 859, 1, 1, -12298.39, -1825.693, 130.3282, 4.34587, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0) (possible waypoints or random movement)
(@CGUID+487, 52089, 859, 1, 1, -12273.16, -1837.101, 131.5688, 5.044002, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+488, 52441, 859, 1, 1, -12299.49, -1793.431, 153.6178, 4.328416, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+489, 52441, 859, 1, 1, -12305.26, -1793.372, 153.6333, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+490, 52089, 859, 1, 1, -12300.02, -1807.467, 131.2171, 3.246312, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+491, 52079, 859, 1, 1, -12318.69, -1833.902, 130.2726, 2.018715, 7200, 0, 0), -- Gurubashi Bloodrager (Area: 0) (possible waypoints or random movement)
(@CGUID+492, 52079, 859, 1, 1, -12326.21, -1835.57, 130.2979, 5.864697, 7200, 0, 0), -- Gurubashi Bloodrager (Area: 0) (possible waypoints or random movement)
(@CGUID+493, 52606, 859, 1, 1, -12333.96, -1856.88, 130.379, 0.7330383, 7200, 0, 0), -- Gurubashi Warmonger (Area: Mandokir's Domain) (possible waypoints or random movement)
(@CGUID+494, 52606, 859, 1, 1, -12329.06, -1861.398, 130.3437, 0.7853982, 7200, 0, 0), -- Gurubashi Warmonger (Area: Mandokir's Domain) (possible waypoints or random movement)
(@CGUID+495, 52076, 859, 1, 1, -12337.25, -1843.21, 130.8813, 2.478368, 7200, 0, 0), -- Gurubashi Cauldron-Mixer (Area: Mandokir's Domain) (possible waypoints or random movement)
(@CGUID+496, 52156, 859, 1, 1, -12330.34, -1878.406, 127.3196, 3.892084, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+497, 52958, 859, 1, 1, -12312.26, -1900.585, 131.16, 3.455752, 7200, 0, 0), -- Zandalari Hierophant (Area: Mandokir's Domain)
(@CGUID+498, 52962, 859, 1, 1, -12314.2, -1908.905, 131.3111, 2.565634, 7200, 0, 0), -- Zandalari Archon (Area: Mandokir's Domain)
(@CGUID+499, 52156, 859, 1, 1, -12351.94, -1861.51, 127.4807, 4.677482, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+500, 52962, 859, 1, 1, -12365.25, -1826.481, 130.3426, 3.159046, 7200, 0, 0), -- Zandalari Archon (Area: Mandokir's Domain)
(@CGUID+501, 52156, 859, 1, 1, -12326.71, -1904.328, 127.4111, 2.75762, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+502, 52606, 859, 1, 1, -12369.65, -1819.314, 130.3426, 5.864306, 7200, 0, 0), -- Gurubashi Warmonger (Area: Mandokir's Domain)
(@CGUID+503, 52088, 859, 1, 1, -12375.33, -1825.931, 130.8675, 6.161012, 7200, 0, 0), -- Gurubashi Cauldron-Mixer (Area: Mandokir's Domain)
(@CGUID+504, 52598, 859, 1, 1, -12369.81, -1833.302, 130.3426, 0.9599311, 7200, 0, 0), -- Gurubashi Soul-Eater (Area: Mandokir's Domain)
(@CGUID+505, 52956, 859, 1, 1, -12367.63, -1850.668, 130.545, 4.834562, 7200, 0, 0), -- Zandalari Juggernaut (Area: Mandokir's Domain)
(@CGUID+506, 52089, 859, 1, 1, -12372.75, -1848.155, 130.6375, 2.617994, 7200, 0, 0), -- Gurubashi Worker (Area: Mandokir's Domain)
(@CGUID+507, 52156, 859, 1, 1, -12347.41, -1917.535, 127.3196, 1.553343, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+508, 52156, 859, 1, 1, -12378.57, -1861.222, 127.5416, 5.340707, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+509, 52956, 859, 1, 1, -12392.6, -1860.342, 130.3387, 5.323254, 7200, 0, 0), -- Zandalari Juggernaut (Area: Mandokir's Domain)
(@CGUID+510, 52156, 859, 1, 1, -12397.79, -1887.731, 127.5453, 0.03490658, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+511, 52156, 859, 1, 1, -12372.36, -1918.844, 127.343, 1.151917, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+512, 46464, 859, 1, 1, -12375.84, -1915.583, 130.9351, 0, 7200, 0, 0), -- Generic Bunny - PRK - Extra-Small (Area: Mandokir's Domain)
(@CGUID+513, 52156, 859, 1, 1, -12391.23, -1905.273, 127.3196, 0.6108652, 7200, 0, 0), -- Chained Spirit (Area: Mandokir's Domain)
(@CGUID+514, 46464, 859, 1, 1, -12383.9, -1912.535, 130.9426, 0, 7200, 0, 0), -- Generic Bunny - PRK - Extra-Small (Area: Mandokir's Domain)
(@CGUID+515, 52441, 859, 1, 1, -12411.59, -1880.753, 152.9371, 4.702869, 7200, 0, 0), -- Curious Jungle Monkey (Area: Mandokir's Domain)
(@CGUID+516, 52958, 859, 1, 1, -12358.46, -1954.573, 149.9164, 1.692969, 7200, 0, 0), -- Zandalari Hierophant (Area: Mandokir's Domain)
(@CGUID+517, 52441, 859, 1, 1, -12411.82, -1863.125, 152.9541, 4.724767, 7200, 0, 0), -- Curious Jungle Monkey (Area: Mandokir's Domain)
(@CGUID+518, 52441, 859, 1, 1, -12400.24, -1796.109, 152.8312, 0.003402164, 7200, 0, 0), -- Curious Jungle Monkey (Area: Mandokir's Domain)
(@CGUID+519, 52429, 859, 1, 1, -11966.19, -1831.33, 56.91885, 0, 7200, 0, 0), -- Zanza the Restless (Area: 0)
(@CGUID+520, 52377, 859, 1, 1, -11963.53, -1851.776, 60.71044, 5.766706, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+521, 52453, 859, 1, 1, -11914.29, -1874.557, 63.82846, 5.759586, 7200, 0, 0), -- Ancient Troll Artifact (Area: 0)
(@CGUID+522, 52453, 859, 1, 1, -11885.03, -1850.556, 63.80865, 5.288348, 7200, 0, 0), -- Ancient Troll Artifact (Area: 0)
(@CGUID+523, 52449, 859, 1, 1, -11898.08, -1866.095, 63.81823, 4.101524, 7200, 0, 0), -- Ancient Dwarven Artifact (Area: 0)
(@CGUID+524, 52455, 859, 1, 1, -11867.97, -1840.681, 63.90985, 4.328416, 7200, 0, 0), -- Ancient Fossil (Area: 0)
(@CGUID+525, 52441, 859, 1, 1, -11888.56, -1825.304, 74.23955, 1.570796, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+526, 52441, 859, 1, 1, -11894.09, -1825.926, 74.47356, 0.2073989, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+527, 45979, 859, 1, 1, -11880.47, -1880.661, 64.04917, 1.553343, 7200, 0, 0), -- General Purpose Bunny JMF (Area: The Cache of Madness)
(@CGUID+528, 52449, 859, 1, 1, -11910.55, -1902.632, 63.73695, 1.308997, 7200, 0, 0), -- Ancient Dwarven Artifact (Area: The Cache of Madness)
(@CGUID+529, 52449, 859, 1, 1, -11915.59, -1893.648, 63.87705, 1.605703, 7200, 0, 0), -- Ancient Dwarven Artifact (Area: The Cache of Madness)
(@CGUID+530, 52453, 859, 1, 1, -11887.33, -1902.979, 63.58939, 0.8028514, 7200, 0, 0), -- Ancient Troll Artifact (Area: The Cache of Madness)
(@CGUID+531, 52446, 859, 1, 1, -11890.05, -1902.464, 63.58706, 2.495821, 7200, 0, 0), -- Ancient Dwarven Artifact (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+532, 52455, 859, 1, 1, -11852.52, -1857.776, 63.9159, 4.433136, 7200, 0, 0), -- Ancient Fossil (Area: The Cache of Madness)
(@CGUID+533, 52455, 859, 1, 1, -11858.09, -1850.684, 63.82613, 0, 7200, 0, 0), -- Ancient Fossil (Area: The Cache of Madness)
(@CGUID+534, 52455, 859, 1, 1, -11857.59, -1843.129, 63.70304, 2.86234, 7200, 0, 0), -- Ancient Fossil (Area: The Cache of Madness)
(@CGUID+535, 52454, 859, 1, 1, -11851.78, -1847.889, 64.16624, 0, 7200, 0, 0), -- Ancient Fossil (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+536, 52413, 859, 1, 1, -11849.05, -1766.73, 14.95374, 2.409356, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+537, 52373, 859, 1, 1, -11827.4, -1806.079, 53.82852, 0.7276245, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+538, 52441, 859, 1, 1, -11842.45, -1826.672, 74.7005, 3.728013, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Cache of Madness)
(@CGUID+539, 52418, 859, 1, 1, -11739.69, -1792.126, 5.181641, 5.321904, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+540, 52452, 859, 1, 1, -11873.85, -1901.866, 63.61808, 1.727876, 7200, 0, 0), -- Ancient Troll Artifact (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+541, 52449, 859, 1, 1, -11908.14, -1913.167, 64.26126, 1.780236, 7200, 0, 0), -- Ancient Dwarven Artifact (Area: The Cache of Madness)
(@CGUID+542, 52453, 859, 1, 1, -11845.61, -1875.979, 63.73526, 3.316126, 7200, 0, 0), -- Ancient Troll Artifact (Area: The Cache of Madness)
(@CGUID+543, 52451, 859, 1, 1, -11857.93, -1906.623, 63.70674, 5.5676, 7200, 0, 0), -- Ancient Elven Artifact (Area: The Cache of Madness)
(@CGUID+544, 52451, 859, 1, 1, -11864.64, -1911.972, 63.9063, 1.727876, 7200, 0, 0), -- Ancient Elven Artifact (Area: The Cache of Madness)
(@CGUID+545, 52451, 859, 1, 1, -11848.14, -1895.255, 63.71764, 2.635447, 7200, 0, 0), -- Ancient Elven Artifact (Area: The Cache of Madness)
(@CGUID+546, 52450, 859, 1, 1, -11851.56, -1899.807, 63.81581, 2.338741, 7200, 0, 0), -- Ancient Elven Artifact (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+547, 52451, 859, 1, 1, -11854.25, -1913.29, 63.70674, 2.024582, 7200, 0, 0), -- Ancient Elven Artifact (Area: The Cache of Madness)
(@CGUID+548, 52441, 859, 1, 1, -11849.51, -1903.767, 76.45016, 1.482336, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Cache of Madness)
(@CGUID+549, 52434, 859, 1, 1, -11820.78, -1861.417, 52.02921, 5.009095, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+550, 52376, 859, 1, 1, -11830.13, -1897.39, 56.80619, 5.042196, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+551, 52958, 859, 1, 1, -11810.07, -1884.345, 46.38454, 0.715585, 7200, 0, 0), -- Zandalari Hierophant (Area: The Cache of Madness)
(@CGUID+552, 52375, 859, 1, 1, -11824.03, -1900.704, 54.74548, 2.496045, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+553, 52437, 859, 1, 1, -11804.96, -1885.349, 46.02859, 2.007129, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+554, 52437, 859, 1, 1, -11809.67, -1878.132, 46.01535, 4.206244, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+555, 52437, 859, 1, 1, -11805.34, -1881.042, 45.55676, 2.949606, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+556, 52437, 859, 1, 1, -11815.77, -1806.28, 51.17046, 2.70526, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+557, 52436, 859, 1, 1, -11813.66, -1832.892, 50.01446, 3.141593, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+558, 52436, 859, 1, 1, -11818.65, -1804.879, 51.71304, 5.427974, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+559, 52435, 859, 1, 1, -11801.64, -1887.202, 46.18118, 1.015303, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+560, 52435, 859, 1, 1, -11794.75, -1868.648, 49.56459, 0.2268928, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+561, 52435, 859, 1, 1, -11791.96, -1868.191, 49.56459, 3.455752, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+562, 52271, 859, 1, 1, -11880.49, -1881.066, 64.05484, 1.64061, 7200, 0, 0), -- Hazza'rah (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+563, 52434, 859, 1, 1, -11794.73, -1897.587, 51.3021, 2.460914, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+564, 52437, 859, 1, 1, -11789.81, -1884.189, 46.57412, 3.001966, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+565, 52441, 859, 1, 1, -11796.15, -1922.181, 70.82465, 5.099727, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Cache of Madness)
(@CGUID+566, 52438, 859, 1, 1, -11701.17, -1939.755, 55.90589, 1.919862, 7200, 0, 0), -- Mortaxx (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+567, 52413, 859, 1, 1, -11839.45, -1772.746, 15.14637, 3.431946, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+568, 52413, 859, 1, 1, -11836.51, -1765.741, 13.70218, 2.865801, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+569, 52413, 859, 1, 1, -11847.21, -1755.241, 11.99051, 4.070041, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+570, 52413, 859, 1, 1, -11832.7, -1753.752, 10.70066, 4.371763, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+571, 52413, 859, 1, 1, -11815.63, -1769.791, 9.715043, 1.79135, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+572, 52434, 859, 1, 1, -11809.38, -1795.304, 51.92652, 4.014257, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+573, 52437, 859, 1, 1, -11796.09, -1826.281, 51.01739, 0.541052, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+574, 52435, 859, 1, 1, -11791.55, -1823.318, 51.01739, 3.769911, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+575, 52417, 859, 1, 1, -11807.76, -1753.207, 4.183965, 3.311046, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+576, 52376, 859, 1, 1, -11789.51, -1833.033, 51.77052, 5.321256, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+577, 52373, 859, 1, 1, -11782.91, -1838.646, 48.97153, 3.639709, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+578, 52417, 859, 1, 1, -11788.29, -1772.492, -3.686818, 1.657071, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+579, 52435, 859, 1, 1, -11778.09, -1839.243, 46.11236, 2.583087, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+580, 52441, 859, 1, 1, -11770.58, -1811.793, 24.30702, 3.019757, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Cache of Madness)
(@CGUID+581, 52956, 859, 1, 1, -11753.44, -1875.773, 55.52433, 5.078908, 7200, 0, 0), -- Zandalari Juggernaut (Area: The Cache of Madness)
(@CGUID+582, 52956, 859, 1, 1, -11764.13, -1890.066, 56.36925, 0.06981317, 7200, 0, 0), -- Zandalari Juggernaut (Area: The Cache of Madness)
(@CGUID+583, 52437, 859, 1, 1, -11760.58, -1898.444, 56.19395, 0.6283185, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+584, 52434, 859, 1, 1, -11757.88, -1884.818, 55.8348, 5.637414, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+585, 52436, 859, 1, 1, -11758, -1894.087, 55.90588, 4.956735, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+586, 52435, 859, 1, 1, -11750.58, -1880.703, 55.01847, 4.677482, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+587, 52376, 859, 1, 1, -11736.19, -1875.062, 58.40156, 3.478931, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+588, 52417, 859, 1, 1, -11739.4, -1794.38, -4.902249, 5.556531, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+589, 52373, 859, 1, 1, -11757.44, -1833.032, 43.24188, 5.335838, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+590, 52413, 859, 1, 1, -11764.74, -1755.89, 13.24158, 3.918689, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+591, 52417, 859, 1, 1, -11759.77, -1792.792, -1.077319, 3.146136, 7200, 0, 0), -- Shredtooth Frenzy (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+592, 52434, 859, 1, 1, -11742.36, -1859.79, 41.83942, 4.39823, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+593, 52413, 859, 1, 1, -11785.2, -1737.589, 10.70988, 1.716604, 7200, 0, 0), -- Zulian Gnasher (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+594, 52373, 859, 1, 1, -11740.27, -1862.171, 44.3042, 0.4936929, 7200, 0, 0), -- Florawing Needler (Area: The Cache of Madness)
(@CGUID+595, 52434, 859, 1, 1, -11765.14, -1838.163, 42.84235, 1.064651, 7200, 0, 0), -- Gurubashi Villager (Area: The Cache of Madness)
(@CGUID+596, 52436, 859, 1, 1, -11731.01, -1859.094, 42.07911, 1.169371, 7200, 0, 0), -- Gurubashi Refugee (Area: The Cache of Madness)
(@CGUID+597, 52418, 859, 1, 1, -11675.43, -1707.756, 5.103312, 0.4013931, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: The Cache of Madness) (possible waypoints or random movement)
(@CGUID+598, 52434, 859, 1, 1, -11740.1, -1882.905, 55.64582, 3.612832, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+599, 52434, 859, 1, 1, -11763.27, -1913.356, 57.65449, 0.1919862, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+600, 52437, 859, 1, 1, -11753.01, -1899.155, 55.9249, 2.583087, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+601, 52436, 859, 1, 1, -11743.91, -1891.958, 55.79095, 2.059489, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+602, 52434, 859, 1, 1, -11717.59, -1859.391, 41.4832, 5.131268, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+603, 52089, 859, 1, 1, -11715.06, -1838.189, 41.17335, 0.2617994, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+604, 52435, 859, 1, 1, -11718.57, -1850.227, 40.54698, 3.276794, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+605, 52434, 859, 1, 1, -11761.23, -1915.521, 57.64587, 1.53589, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+606, 52434, 859, 1, 1, -11714.47, -1859.491, 41.45408, 3.944444, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+607, 52436, 859, 1, 1, -11706.66, -1853.311, 40.61678, 3.944444, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+608, 52962, 859, 1, 1, -11740.04, -1920.903, 55.90589, 5.846853, 7200, 0, 0), -- Zandalari Archon (Area: 0) (possible waypoints or random movement)
(@CGUID+609, 52417, 859, 1, 1, -11720.63, -1803.172, -5.267715, 5.320489, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+610, 52435, 859, 1, 1, -11731.43, -1903.146, 57.45902, 5.427974, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+611, 52434, 859, 1, 1, -11749.75, -1910.531, 56.09026, 4.799655, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+612, 52434, 859, 1, 1, -11728.85, -1904.354, 57.50654, 5.393067, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+613, 52434, 859, 1, 1, -11722.87, -1901.441, 56.0607, 5.201081, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+614, 52436, 859, 1, 1, -11694.25, -1843.309, 40.61935, 4.642576, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+615, 52435, 859, 1, 1, -11749.54, -1914.602, 55.90589, 1.692969, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+616, 52376, 859, 1, 1, -11694.11, -1863.149, 43.34975, 5.158281, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+617, 52435, 859, 1, 1, -11701.75, -1816.543, 41.29557, 0.2443461, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+618, 52434, 859, 1, 1, -11733.54, -1913.111, 56.41248, 5.689773, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+619, 52417, 859, 1, 1, -11724.56, -1780.728, -0.239906, 5.059695, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+620, 52436, 859, 1, 1, -11689.19, -1827.839, 40.57652, 4.572762, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+621, 52435, 859, 1, 1, -11708.3, -1902.84, 56.28455, 4.747295, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+622, 52436, 859, 1, 1, -11686.79, -1830.976, 40.56763, 3.106686, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+623, 52434, 859, 1, 1, -11748.15, -1925.549, 57.61364, 6.073746, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+624, 52376, 859, 1, 1, -11680.66, -1858.929, 43.79738, 2.14975, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+625, 52436, 859, 1, 1, -11697.89, -1899.243, 55.53128, 3.543018, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+626, 52441, 859, 1, 1, -11687.66, -1815.069, 43.59112, 3.0119, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+627, 52435, 859, 1, 1, -11699.74, -1909.014, 56.23449, 4.363323, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+628, 52377, 859, 1, 1, -11692.81, -1901.866, 56.8168, 3.466632, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+629, 52437, 859, 1, 1, -11669.28, -1855.139, 40.55552, 6.143559, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+630, 52441, 859, 1, 1, -11790.07, -1931.514, 69.82172, 2.579789, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+631, 52435, 859, 1, 1, -11697.09, -1788.606, 12.47068, 4.18879, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+632, 52434, 859, 1, 1, -11700.83, -1784.689, 12.33204, 3.612832, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+633, 52375, 859, 1, 1, -11672.75, -1811.502, 41.5541, 0.6963754, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+634, 52376, 859, 1, 1, -11669, -1876.333, 59.89087, 3.967281, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+635, 52437, 859, 1, 1, -11667.11, -1825.686, 40.84256, 4.24115, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+636, 52375, 859, 1, 1, -11662.11, -1855.327, 45.00328, 2.652495, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+637, 52377, 859, 1, 1, -11682.57, -1790.511, 14.40932, 2.876914, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+638, 52434, 859, 1, 1, -11657.46, -1852.035, 41.73466, 5.253441, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+639, 52435, 859, 1, 1, -11723.21, -1946.019, 57.47268, 0.4886922, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+640, 52434, 859, 1, 1, -11685.55, -1921.892, 55.90589, 3.717551, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+641, 52377, 859, 1, 1, -11660.19, -1817.037, 45.47967, 0.7965252, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+642, 52435, 859, 1, 1, -11702.03, -1768.007, 11.73426, 2.478368, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+643, 52435, 859, 1, 1, -11720.54, -1947.929, 57.48969, 0.5934119, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+644, 52439, 859, 1, 1, -11701.27, -1939.712, 55.90589, 2.024582, 7200, 0, 0), -- Purple Ground Rune (Area: 0)
(@CGUID+645, 52434, 859, 1, 1, -11682.12, -1924.038, 55.90589, 3.682645, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+646, 52376, 859, 1, 1, -11657.42, -1811.339, 43.89299, 1.004265, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+647, 52437, 859, 1, 1, -11658.39, -1896.254, 77.27688, 0.486864, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+648, 52435, 859, 1, 1, -11658.39, -1896.254, 77.27688, 0.486864, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+649, 52439, 859, 1, 1, -11658.19, -1896.311, 77.36022, 2.80998, 7200, 0, 0), -- Purple Ground Rune (Area: 0)
(@CGUID+650, 52958, 859, 1, 1, -11652.37, -1892.549, 77.36022, 3.735005, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+651, 52441, 859, 1, 1, -11638.73, -1866.879, 60.86943, 1.429331, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+652, 52441, 859, 1, 1, -11665.27, -1939.763, 70.85793, 0.9266152, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+653, 52441, 859, 1, 1, -11661.36, -1934.969, 70.8899, 0.777916, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+654, 52435, 859, 1, 1, -11643.67, -1813.009, 40.61359, 4.433136, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+655, 52435, 859, 1, 1, -11636.9, -1836.479, 44.1696, 4.782202, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+656, 52434, 859, 1, 1, -11628.67, -1838.384, 43.44221, 4.502949, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+657, 52434, 859, 1, 1, -11638.03, -1816.411, 40.44133, 4.08609, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+658, 52435, 859, 1, 1, -11649.55, -1788.288, 41.94619, 2.408554, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+659, 52435, 859, 1, 1, -11636.81, -1839.681, 44.17774, 1.623156, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+660, 52434, 859, 1, 1, -11624.97, -1814.129, 40.52547, 4.677482, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+661, 52434, 859, 1, 1, -11644.75, -1816.405, 40.53564, 1.169371, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+662, 52435, 859, 1, 1, -11617.3, -1830.936, 59.47699, 2.86234, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+663, 52436, 859, 1, 1, -11636.53, -1825.227, 40.53675, 2.513274, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+664, 52437, 859, 1, 1, -11653.78, -1801.233, 42.69987, 2.303835, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+665, 52436, 859, 1, 1, -11612.54, -1838.122, 59.47699, 1.396527, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+666, 52434, 859, 1, 1, -11625.49, -1836.077, 43.35887, 3.365826, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+667, 52435, 859, 1, 1, -11653.7, -1841.12, 40.56507, 3.274628, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+668, 52437, 859, 1, 1, -11653.53, -1841.097, 40.56507, 3.274628, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+669, 52392, 859, 1, 1, -11612.85, -1840.326, 43.35887, 4.33926, 7200, 0, 0), -- Gurubashi Master Chef (Area: 0) (possible waypoints or random movement)
(@CGUID+670, 52437, 859, 1, 1, -11605.56, -1840.656, 43.44221, 2.251475, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+671, 52435, 859, 1, 1, -11639.35, -1782.347, 40.63043, 5.393067, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+672, 52437, 859, 1, 1, -11605.13, -1803.141, 40.65794, 2.042035, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+673, 52956, 859, 1, 1, -11678.7, -1764.918, 13.59049, 3.193953, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0)
(@CGUID+674, 52436, 859, 1, 1, -11605.82, -1798.995, 40.65551, 2.617994, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+675, 52434, 859, 1, 1, -11616.09, -1781.534, 40.26062, 1.282733, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+676, 52376, 859, 1, 1, -11596, -1799.218, 44.3221, 2.040205, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+677, 52373, 859, 1, 1, -11592.23, -1806.83, 43.01729, 1.061697, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+678, 52436, 859, 1, 1, -11603.81, -1784.005, 40.77776, 2.076942, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+679, 52437, 859, 1, 1, -11605.08, -1781.637, 40.78185, 5.201081, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+680, 52436, 859, 1, 1, -11682.52, -1768.531, 12.98148, 0.7504916, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+681, 52436, 859, 1, 1, -11683.49, -1763.91, 12.88005, 6.003932, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+682, 52441, 859, 1, 1, -11584.89, -1866.146, 66.33203, 0.2453741, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+683, 52435, 859, 1, 1, -11600.15, -1770.295, 43.46503, 6.178465, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+684, 52435, 859, 1, 1, -11597.33, -1771.819, 43.46503, 2.146755, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+685, 52435, 859, 1, 1, -11611.35, -1761.017, 38.81752, 0.7330383, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+686, 52373, 859, 1, 1, -11658.55, -1750.196, 23.37084, 0.2508523, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+687, 52434, 859, 1, 1, -11680.33, -1755.564, 14.65034, 2.234021, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+688, 52435, 859, 1, 1, -11611.53, -1757.358, 38.81752, 5.532694, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+689, 52434, 859, 1, 1, -11698.78, -1764.026, 11.59842, 2.007129, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+690, 52434, 859, 1, 1, -11607.77, -1758.592, 38.83409, 3.438299, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+691, 52441, 859, 1, 1, -11593.81, -1886.704, 77.80591, 5.749831, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+692, 52958, 859, 1, 1, -11586.07, -1754.694, 39.53971, 2.495821, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+693, 52435, 859, 1, 1, -11625.49, -1742.91, 39.04934, 1.012291, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+694, 52434, 859, 1, 1, -11610.52, -1746.031, 38.78375, 1.624691, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+695, 52436, 859, 1, 1, -11596.28, -1754.851, 39.51356, 6.213372, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+696, 52435, 859, 1, 1, -11623.98, -1740.033, 38.91105, 4.310963, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+697, 52417, 859, 1, 1, -11675.75, -1728.917, 5.845788, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+698, 52435, 859, 1, 1, -11590.44, -1745.568, 39.57365, 5.323254, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+699, 52435, 859, 1, 1, -11594.91, -1738.811, 42.41028, 1.884956, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+700, 52441, 859, 1, 1, -11561.38, -1773.724, 57.65443, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+701, 52435, 859, 1, 1, -11596.05, -1736.156, 42.41028, 5.253441, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+702, 52377, 859, 1, 1, -11553.92, -1778.78, 55.87806, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+703, 52437, 859, 1, 1, -11578.93, -1742.55, 38.73495, 4.24115, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+704, 52436, 859, 1, 1, -11600.81, -1723.79, 39.05836, 3.228859, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+705, 52436, 859, 1, 1, -11572.02, -1741.995, 38.45454, 4.031711, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+706, 52436, 859, 1, 1, -11574.32, -1738.733, 38.59128, 4.310963, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+707, 52436, 859, 1, 1, -11631.36, -1710.507, 40.1113, 3.176499, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+708, 52434, 859, 1, 1, -11558.51, -1752.635, 39.88713, 0.296706, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+709, 52377, 859, 1, 1, -11603.46, -1715.635, 41.99921, 0.6457718, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+710, 52077, 859, 1, 1, -11635.41, -1617.142, 40.24976, 5.218534, 7200, 0, 0), -- Gurubashi Berserker (Area: 0)
(@CGUID+711, 52362, 859, 1, 1, -11589.22, -1620.863, 49.37638, 3.106686, 7200, 0, 0), -- Tiki Lord Zim'wae (Area: 0) (possible waypoints or random movement)
(@CGUID+712, 52441, 859, 1, 1, -11562.78, -1872.497, 73.88931, 4.869139, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+713, 52441, 859, 1, 1, -11540.41, -1818.094, 70.07158, 1.304141, 7200, 0, 0), -- Curious Jungle Monkey (Area: 0)
(@CGUID+714, 52434, 859, 1, 1, -11615.7, -1835.214, 59.46442, 0.4105365, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+715, 52377, 859, 1, 1, -11556.99, -1748.579, 42.84309, 6.14737, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+716, 52373, 859, 1, 1, -11554.75, -1756.044, 42.30904, 3.587069, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+717, 52436, 859, 1, 1, -11612.54, -1838.122, 59.47699, 1.308997, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+718, 52306, 859, 1, 1, -11587.39, -1700.911, 53.03299, 4.066617, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+719, 52306, 859, 1, 1, -11577.28, -1702.326, 51.77951, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+720, 52306, 859, 1, 1, -11582.41, -1696.851, 52.0868, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+721, 52373, 859, 1, 1, -11608.17, -1709.546, 43.14144, 3.530959, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+722, 52305, 859, 1, 1, -11587.63, -1691.297, 51.78875, 1.553343, 7200, 0, 0), -- Toxic Husk (Area: 0)
(@CGUID+723, 52306, 859, 1, 1, -11573.23, -1696.538, 51.04721, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+724, 52306, 859, 1, 1, -11564.16, -1703.601, 52.07163, 0.1570796, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+725, 52306, 859, 1, 1, -11576.89, -1690.118, 51.90451, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+726, 52306, 859, 1, 1, -11580.9, -1685.384, 51.59201, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+727, 52306, 859, 1, 1, -11586.64, -1682.064, 50.54157, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+728, 52306, 859, 1, 1, -11563.98, -1696.967, 52.27508, 0.1570796, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+729, 52437, 859, 1, 1, -11566.75, -1727.858, 39.56809, 4.34587, 7200, 0, 0), -- Gurubashi Refugee (Area: 0)
(@CGUID+730, 52306, 859, 1, 1, -11570.35, -1689.51, 52.27563, 2.059489, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+731, 52306, 859, 1, 1, -11556.38, -1700.057, 51.89949, 2.059489, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+732, 52306, 859, 1, 1, -11576.64, -1681.552, 52.66666, 0, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+733, 52306, 859, 1, 1, -11589.98, -1674.297, 52.21354, 4.066617, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+734, 52306, 859, 1, 1, -11579.87, -1675.712, 50.93969, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+735, 52306, 859, 1, 1, -11565.43, -1684.944, 52.55061, 2.827433, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+736, 52306, 859, 1, 1, -11585, -1670.236, 52.52083, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+737, 52306, 859, 1, 1, -11553.17, -1692.844, 51.0898, 0.9250245, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+738, 52305, 859, 1, 1, -11546.97, -1699.512, 52.58864, 1.553343, 7200, 0, 0), -- Toxic Husk (Area: 0)
(@CGUID+739, 52306, 859, 1, 1, -11557.92, -1684.599, 53.00524, 0.9250245, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+740, 52306, 859, 1, 1, -11575.83, -1669.924, 51.17708, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+741, 52377, 859, 1, 1, -11633.48, -1677.216, 43.45194, 1.251542, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+742, 52306, 859, 1, 1, -11589.82, -1663.976, 52.21528, 0, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+743, 52306, 859, 1, 1, -11544.87, -1692.373, 51.5414, 6.126106, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+744, 52306, 859, 1, 1, -11550.84, -1684.682, 52.52417, 2.827433, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+745, 52306, 859, 1, 1, -11579.48, -1663.504, 50.88685, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+746, 52375, 859, 1, 1, -11630.97, -1671.104, 42.60157, 3.835129, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+747, 52417, 859, 1, 1, -11676.4, -1690.344, -1.590059, 4.767124, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+748, 52306, 859, 1, 1, -11537.79, -1699.865, 52.7588, 4.066617, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+749, 52306, 859, 1, 1, -11583.49, -1658.769, 50.57118, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+750, 52376, 859, 1, 1, -11636.01, -1668.404, 42.91718, 0.9068607, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+751, 52306, 859, 1, 1, -11589.23, -1655.45, 51.18125, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+752, 52417, 859, 1, 1, -11673.78, -1677.074, 4.94148, 0.6987321, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+753, 52306, 859, 1, 1, -11537.63, -1689.543, 51.27604, 0, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+754, 52305, 859, 1, 1, -11573.85, -1658.677, 52.03991, 1.553343, 7200, 0, 0), -- Toxic Husk (Area: 0)
(@CGUID+755, 52306, 859, 1, 1, -11532.82, -1695.804, 51.67128, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+756, 52435, 859, 1, 1, -11534.04, -1725.847, 39.00864, 0.1396263, 7200, 0, 0), -- Gurubashi Villager (Area: 0)
(@CGUID+757, 52306, 859, 1, 1, -11579.23, -1654.938, 51.72049, 0, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+758, 52306, 859, 1, 1, -11527.68, -1701.28, 53.00174, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+759, 52306, 859, 1, 1, -11532, -1686.707, 51.49812, 0, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+760, 52306, 859, 1, 1, -11527.29, -1689.071, 52.34201, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+761, 52306, 859, 1, 1, -11523.64, -1695.491, 53.30903, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+762, 52345, 859, 1, 1, -11563.8, -1648.959, 52.64662, 1.550495, 7200, 0, 0), -- Pride of Bethekk (Area: 0) (possible waypoints or random movement)
(@CGUID+763, 52306, 859, 1, 1, -11514.56, -1702.554, 52.30611, 0.1570796, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+764, 52306, 859, 1, 1, -11520.75, -1688.464, 54.44143, 2.059489, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+765, 52327, 859, 1, 1, -11548.79, -1659.052, 63.61814, 3.874631, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: 0)
(@CGUID+766, 52417, 859, 1, 1, -11673.09, -1655.783, 2.84724, 4.30009, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+767, 52306, 859, 1, 1, -11514.38, -1695.92, 52.95139, 0.1570796, 7200, 0, 0), -- Tangled Vine (Area: 0)
(@CGUID+768, 52345, 859, 1, 1, -11556.73, -1649.103, 52.63936, 1.550477, 7200, 0, 0), -- Pride of Bethekk (Area: 0) (possible waypoints or random movement)
(@CGUID+769, 52325, 859, 1, 1, -11560.2, -1645.477, 52.64256, 4.691726, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: 0) (possible waypoints or random movement)
(@CGUID+770, 52375, 859, 1, 1, -11573.29, -1646.276, 55.15971, 4.516632, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+771, 52347, 859, 1, 1, -11599.94, -1628.502, 76.05481, 1.047198, 7200, 0, 0), -- Zul'gurub Eagle (Area: 0)
(@CGUID+772, 52059, 859, 1, 1, -11518.79, -1627.161, 45.26112, 0, 7200, 0, 0), -- High Priestess Kilnara (Area: 0) (possible waypoints or random movement)
(@CGUID+773, 52387, 859, 1, 1, -11560.39, -1627.205, 44.48487, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+774, 52387, 859, 1, 1, -11538.17, -1645.078, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+775, 52387, 859, 1, 1, -11539.63, -1635.533, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+776, 52413, 859, 1, 1, -11688.86, -1651.735, 13.26988, 2.869828, 7200, 0, 0), -- Zulian Gnasher (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+777, 52958, 859, 1, 1, -11540.33, -1651.816, 74.50887, 1.082104, 7200, 0, 0), -- Zandalari Hierophant (Area: Temple of Bethekk)
(@CGUID+778, 52306, 859, 1, 1, -11579.97, -1590.142, 52.19108, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+779, 52345, 859, 1, 1, -11538.66, -1645.514, 74.50887, 5.096361, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk)
(@CGUID+780, 52306, 859, 1, 1, -11588.47, -1586.821, 52.25521, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+781, 52387, 859, 1, 1, -11528.55, -1648.297, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+782, 52327, 859, 1, 1, -11534.65, -1653.95, 74.50887, 2.024582, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+783, 52387, 859, 1, 1, -11539.58, -1617.727, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+784, 52339, 859, 1, 1, -11533.51, -1646.359, 74.50887, 3.368485, 7200, 0, 0), -- Lesser Priest of Bethekk (Area: Temple of Bethekk)
(@CGUID+785, 52327, 859, 1, 1, -11561.21, -1595.629, 52.64644, 4.758685, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+786, 52413, 859, 1, 1, -11696.2, -1638.22, 15.14931, 0.2076976, 7200, 0, 0), -- Zulian Gnasher (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+787, 52345, 859, 1, 1, -11564.92, -1591.863, 52.65094, 4.758166, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+788, 52441, 859, 1, 1, -11598.24, -1595.617, 61.18437, 1.582654, 7200, 0, 0), -- Curious Jungle Monkey (Area: Temple of Bethekk)
(@CGUID+789, 52376, 859, 1, 1, -11604.95, -1591.22, 42.44664, 2.588252, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+790, 52306, 859, 1, 1, -11591.81, -1579.054, 52.4566, 4.066617, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+791, 52061, 859, 1, 1, -11521.75, -1651.576, 44.48486, 0.9773844, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+792, 52306, 859, 1, 1, -11581.7, -1580.469, 51.68576, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+793, 52305, 859, 1, 1, -11574.72, -1583.25, 51.86406, 0, 7200, 0, 0), -- Toxic Husk (Area: Temple of Bethekk)
(@CGUID+794, 52387, 859, 1, 1, -11529.02, -1626.865, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+795, 52377, 859, 1, 1, -11576.94, -1597.852, 54.61324, 4.631298, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+796, 52373, 859, 1, 1, -11638.58, -1590.876, 44.3182, 5.841419, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+797, 52345, 859, 1, 1, -11557.86, -1591.537, 52.64293, 4.75822, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+798, 52061, 859, 1, 1, -11520.56, -1646.002, 44.48486, 4.956735, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+799, 52061, 859, 1, 1, -11518.06, -1651.479, 44.48486, 2.268928, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+800, 52306, 859, 1, 1, -11586.83, -1574.993, 51.03993, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+801, 52387, 859, 1, 1, -11519.88, -1640.142, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+802, 52061, 859, 1, 1, -11517.24, -1646.819, 44.48486, 3.874631, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+803, 52345, 859, 1, 1, -11535.17, -1611.882, 63.55652, 1.610375, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+804, 52417, 859, 1, 1, -11679.96, -1604.687, -1.28858, 1.888907, 7200, 0, 0), -- Shredtooth Frenzy (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+805, 52306, 859, 1, 1, -11577.66, -1574.681, 51.81944, 5.148721, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+806, 52306, 859, 1, 1, -11591.65, -1568.733, 51.8559, 0, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+807, 52387, 859, 1, 1, -11531.53, -1605.477, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+808, 52327, 859, 1, 1, -11531.78, -1608.198, 63.55652, 1.614298, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+809, 52345, 859, 1, 1, -11528.1, -1611.587, 63.55651, 1.610225, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+810, 52306, 859, 1, 1, -11581.31, -1568.26, 52.08333, 0.7679449, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+811, 52061, 859, 1, 1, -11523.16, -1609.307, 44.48486, 0.9773844, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+812, 52962, 859, 1, 1, -11539.88, -1597.266, 74.50887, 0.7853982, 7200, 0, 0), -- Zandalari Archon (Area: Temple of Bethekk)
(@CGUID+813, 52306, 859, 1, 1, -11585.32, -1563.526, 51.66666, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+814, 52061, 859, 1, 1, -11523.22, -1605.965, 44.48486, 5.410521, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+815, 52327, 859, 1, 1, -11547.79, -1582.698, 63.62276, 2.635447, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+816, 52061, 859, 1, 1, -11519.67, -1609.002, 44.48486, 2.268928, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+817, 52306, 859, 1, 1, -11591.06, -1560.207, 53.32813, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+818, 52339, 859, 1, 1, -11534.41, -1597.083, 74.50887, 2.495821, 7200, 0, 0), -- Lesser Priest of Bethekk (Area: Temple of Bethekk)
(@CGUID+819, 52325, 859, 1, 1, -11540.09, -1590.736, 74.50887, 5.427974, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+820, 52306, 859, 1, 1, -11573.03, -1563.137, 52.544, 2.86234, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+821, 52061, 859, 1, 1, -11519.18, -1605.366, 44.48486, 3.560472, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+822, 52306, 859, 1, 1, -11581.06, -1559.694, 50.67882, 0, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+823, 53088, 859, 1, 1, -11516.17, -1640.366, 52.68262, 3.536005, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+824, 52325, 859, 1, 1, -11533.47, -1592.144, 74.50887, 3.979351, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+825, 52347, 859, 1, 1, -11558.05, -1602.827, 104.4118, 6.249686, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+826, 52082, 859, 1, 1, -11645.99, -1553.068, 40.32316, 3.385939, 7200, 0, 0), -- Gurubashi Cauldron-Mixer (Area: Temple of Bethekk)
(@CGUID+827, 52958, 859, 1, 1, -11658.58, -1557.33, 40.7927, 0.7330383, 7200, 0, 0), -- Zandalari Hierophant (Area: Temple of Bethekk)
(@CGUID+828, 52306, 859, 1, 1, -11586.15, -1552.155, 52.44467, 5.532694, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+829, 52306, 859, 1, 1, -11575.24, -1554.523, 51.89013, 3.630285, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+830, 52305, 859, 1, 1, -11589.89, -1545.715, 53.11182, 0, 7200, 0, 0), -- Toxic Husk (Area: Temple of Bethekk)
(@CGUID+831, 52306, 859, 1, 1, -11570.18, -1549.076, 50.93878, 5.532694, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+832, 52085, 859, 1, 1, -11622.65, -1540.538, 41.23418, 3.246513, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+833, 52306, 859, 1, 1, -11576.16, -1545.382, 51.94791, 3.630285, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+834, 52306, 859, 1, 1, -11555.39, -1553.66, 52.53094, 5.532694, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+835, 52306, 859, 1, 1, -11560.51, -1550.129, 51.44149, 4.764749, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+836, 52085, 859, 1, 1, -11612.03, -1536.868, 40.47735, 5.997171, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+837, 52085, 859, 1, 1, -11611.99, -1535.531, 40.31231, 5.2434, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+838, 52418, 859, 1, 1, -11710.65, -1540.515, 6.576325, 0.4987646, 7200, 0, 0), -- Lost Offspring of Gahz'ranka (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+839, 52306, 859, 1, 1, -11580.54, -1540.689, 53.3993, 2.548181, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+840, 52347, 859, 1, 1, -11556.34, -1629.56, 95.10934, 3.169238, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+841, 52085, 859, 1, 1, -11623.58, -1535.138, 40.96801, 1.324398, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+842, 52306, 859, 1, 1, -11570.23, -1540.168, 52.55382, 4.764749, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+843, 52598, 859, 1, 1, -11656.41, -1546.382, 40.1427, 5.201081, 7200, 0, 0), -- Gurubashi Soul-Eater (Area: Temple of Bethekk)
(@CGUID+844, 52306, 859, 1, 1, -11563.81, -1541.063, 52.41948, 2.86234, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+845, 52085, 859, 1, 1, -11615.95, -1530.129, 41.45307, 2.140373, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+846, 52085, 859, 1, 1, -11617.97, -1529.675, 41.4739, 0.9226059, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+847, 52306, 859, 1, 1, -11544.68, -1552.717, 53.72035, 4.380776, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+848, 52306, 859, 1, 1, -11550.15, -1545.785, 51.77787, 2.548181, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+849, 52387, 859, 1, 1, -11509.96, -1619.33, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+850, 52085, 859, 1, 1, -11630.85, -1529.244, 40.91962, 2.220722, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+851, 52306, 859, 1, 1, -11555.08, -1540.438, 51.5098, 1.902409, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+852, 52085, 859, 1, 1, -11621.98, -1525.457, 41.49091, 2.232925, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+853, 52061, 859, 1, 1, -11508.28, -1607.366, 44.48486, 0.9773844, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+854, 52387, 859, 1, 1, -11508.8, -1604.293, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+855, 52061, 859, 1, 1, -11508.66, -1603.384, 44.48486, 5.410521, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+856, 52306, 859, 1, 1, -11539, -1548.75, 52.59549, 5.532694, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+857, 52061, 859, 1, 1, -11505.64, -1607.561, 44.48486, 2.268928, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+858, 52085, 859, 1, 1, -11627.93, -1520.82, 42.581, 0.1942673, 7200, 0, 0), -- Razzashi Adder (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+859, 52306, 859, 1, 1, -11529.2, -1553.514, 52.21886, 0, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+860, 52305, 859, 1, 1, -11544.71, -1538.677, 51.50199, 0, 7200, 0, 0), -- Toxic Husk (Area: Temple of Bethekk)
(@CGUID+861, 53088, 859, 1, 1, -11516.34, -1593.594, 52.68262, 3.517976, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+862, 52306, 859, 1, 1, -11538.13, -1540.059, 51.56494, 3.630285, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+863, 52306, 859, 1, 1, -11528.66, -1546.95, 51.64107, 2.86234, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+864, 52086, 859, 1, 1, -11598.68, -1513.118, 47.56465, 0.2268928, 7200, 0, 0), -- Hakkari Witch Doctor (Area: Temple of Bethekk)
(@CGUID+865, 52087, 859, 1, 1, -11580.76, -1514.709, 51.78681, 4.071675, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+866, 52087, 859, 1, 1, -11586.46, -1513.057, 50.62965, 5.646899, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+867, 52087, 859, 1, 1, -11576.88, -1514.357, 52.49816, 4.618548, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+868, 52347, 859, 1, 1, -11522.88, -1606.462, 98.33322, 2.460914, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk)
(@CGUID+869, 52087, 859, 1, 1, -11578.22, -1511.306, 53.25095, 0.4095048, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+870, 52087, 859, 1, 1, -11584.38, -1509.627, 52.23115, 5.923638, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+871, 52375, 859, 1, 1, -11669.54, -1537.489, 40.60518, 4.950672, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+872, 52089, 859, 1, 1, -11661.36, -1526.061, 39.79465, 1.937315, 7200, 0, 0), -- Gurubashi Worker (Area: Temple of Bethekk)
(@CGUID+873, 53088, 859, 1, 1, -11509.07, -1636.691, 52.68262, 1.911346, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+874, 52061, 859, 1, 1, -11506.58, -1651.042, 44.48486, 1.605703, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+875, 52061, 859, 1, 1, -11507, -1644.554, 44.48486, 4.782202, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+876, 52387, 859, 1, 1, -11501.99, -1632.88, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+877, 52061, 859, 1, 1, -11504.26, -1645.556, 44.48486, 4.660029, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+878, 52061, 859, 1, 1, -11504.61, -1603.332, 44.48486, 3.874631, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+879, 52347, 859, 1, 1, -11524.21, -1635.009, 98.23921, 4.014257, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk)
(@CGUID+880, 52327, 859, 1, 1, -11510.36, -1658.62, 74.42554, 1.665817, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+881, 52327, 859, 1, 1, -11516.16, -1666.809, 74.50887, 3.612832, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+882, 52325, 859, 1, 1, -11492.08, -1645.005, 74.50887, 5.707227, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+883, 52327, 859, 1, 1, -11514.4, -1574.167, 74.50887, 2.6529, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+884, 52327, 859, 1, 1, -11496.63, -1598.929, 52.71923, 0.296706, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+885, 52387, 859, 1, 1, -11495.35, -1621.67, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+886, 52061, 859, 1, 1, -11504.1, -1650.259, 44.48486, 2.268928, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+887, 52345, 859, 1, 1, -11490.82, -1603.602, 52.72498, 1.239184, 7200, 0, 0), -- Pride of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+888, 52339, 859, 1, 1, -11486.41, -1641.087, 74.50887, 3.804818, 7200, 0, 0), -- Lesser Priest of Bethekk (Area: Temple of Bethekk)
(@CGUID+889, 52327, 859, 1, 1, -11503.99, -1666.8, 74.50887, 5.585053, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+890, 52325, 859, 1, 1, -11495.42, -1592.142, 52.70906, 5.5676, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+891, 52327, 859, 1, 1, -11506.07, -1574.153, 74.50887, 0.3490658, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+892, 52327, 859, 1, 1, -11490.9, -1590.476, 74.50887, 4.468043, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+893, 52387, 859, 1, 1, -11491.29, -1634.09, 44.48486, 0, 7200, 0, 0), -- Cave In Stalker (Area: Temple of Bethekk)
(@CGUID+894, 52325, 859, 1, 1, -11488.73, -1650.833, 74.50887, 0.7679449, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+895, 52325, 859, 1, 1, -11485.55, -1599.483, 74.50887, 1.745329, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+896, 52339, 859, 1, 1, -11487.16, -1599.634, 52.71842, 2.495821, 7200, 0, 0), -- Lesser Priest of Bethekk (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+897, 52325, 859, 1, 1, -11486.85, -1592.931, 52.71036, 3.473205, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+898, 52325, 859, 1, 1, -11481.72, -1594.207, 74.50887, 3.089233, 7200, 0, 0), -- Gurubashi Blood Drinker (Area: Temple of Bethekk)
(@CGUID+899, 52347, 859, 1, 1, -11519.03, -1593.633, 98.47397, 4.716218, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk)
(@CGUID+900, 52327, 859, 1, 1, -11480.51, -1648.113, 74.50887, 2.146755, 7200, 0, 0), -- Gurubashi Shadow Hunter (Area: Temple of Bethekk)
(@CGUID+901, 53088, 859, 1, 1, -11497.24, -1612.822, 63.55652, 1.006206, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+902, 52347, 859, 1, 1, -11519.36, -1608.729, 118.369, 3.730846, 7200, 0, 0), -- Zul'gurub Eagle (Area: Temple of Bethekk)
(@CGUID+903, 52305, 859, 1, 1, -11513.65, -1686.274, 53.04927, 3.996804, 7200, 0, 0), -- Toxic Husk (Area: Temple of Bethekk)
(@CGUID+904, 52305, 859, 1, 1, -11519.43, -1555.266, 52.60499, 1.553343, 7200, 0, 0), -- Toxic Husk (Area: Temple of Bethekk)
(@CGUID+905, 53088, 859, 1, 1, -11492.53, -1647.07, 63.55652, 3.4489, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+906, 52306, 859, 1, 1, -11521.81, -1550.391, 51.54459, 4.764749, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+907, 53088, 859, 1, 1, -11494.07, -1600.395, 44.53593, 6.085066, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+908, 52306, 859, 1, 1, -11504.95, -1693.236, 51.95316, 2.827433, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+909, 52306, 859, 1, 1, -11530.92, -1539.12, 51.7119, 4.764749, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+910, 52306, 859, 1, 1, -11521.16, -1540.148, 53.04292, 2.86234, 7200, 0, 0), -- Tangled Vine (Area: Temple of Bethekk)
(@CGUID+911, 52441, 859, 1, 1, -11511.42, -1529.925, 61.2722, 5.951573, 7200, 0, 0), -- Curious Jungle Monkey (Area: Temple of Bethekk)
(@CGUID+912, 52087, 859, 1, 1, -11576.1, -1509.289, 53.84858, 0.693653, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+913, 52087, 859, 1, 1, -11574.5, -1508.36, 53.94379, 3.421892, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+914, 52376, 859, 1, 1, -11542.89, -1509.96, 63.28044, 5.786437, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+915, 52377, 859, 1, 1, -11536.55, -1514.118, 62.57603, 3.607972, 7200, 0, 0), -- Florawing Needler (Area: Temple of Bethekk)
(@CGUID+916, 52089, 859, 1, 1, -11534.22, -1499.931, 77.95042, 5.72468, 7200, 0, 0), -- Gurubashi Worker (Area: Temple of Bethekk)
(@CGUID+917, 52087, 859, 1, 1, -11570.3, -1509.435, 54.19038, 5.582989, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+918, 53088, 859, 1, 1, -11487.75, -1646.556, 63.59377, 5.061455, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+919, 53088, 859, 1, 1, -11499.06, -1612.057, 63.59361, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+920, 52087, 859, 1, 1, -11572.1, -1508.019, 54.37529, 0.9058142, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+921, 53088, 859, 1, 1, -11512.73, -1595.717, 52.70525, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+922, 53088, 859, 1, 1, -11506.81, -1639.451, 52.72576, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+923, 53088, 859, 1, 1, -11518.35, -1639.635, 52.70818, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+924, 53088, 859, 1, 1, -11496.34, -1599.891, 44.48486, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+925, 53088, 859, 1, 1, -11518.35, -1639.635, 52.70818, 0, 7200, 0, 0), -- Temple Rat (Area: Temple of Bethekk)
(@CGUID+926, 52417, 859, 1, 1, -11696.43, -1556.578, -1.075184, 1.723403, 7200, 0, 0), -- Shredtooth Frenzy (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+927, 52086, 859, 1, 1, -11594.62, -1498.684, 50.82291, 5.864306, 7200, 0, 0), -- Hakkari Witch Doctor (Area: Temple of Bethekk)
(@CGUID+928, 52087, 859, 1, 1, -11587.33, -1496.807, 53.63635, 2.559222, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+929, 52087, 859, 1, 1, -11589.99, -1505.977, 50.92182, 2.796506, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+930, 52087, 859, 1, 1, -11591.02, -1505.904, 50.58246, 4.743629, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+931, 52087, 859, 1, 1, -11586.47, -1506.478, 52.49238, 0.4621571, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+932, 52087, 859, 1, 1, -11577.44, -1505.625, 54.48481, 5.447947, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+933, 52087, 859, 1, 1, -11578.57, -1496.934, 55.32782, 2.586099, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+934, 52087, 859, 1, 1, -11587.47, -1494.66, 54.28674, 2.147417, 7200, 0, 0), -- Zanzil Mindslave (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+935, 52417, 859, 1, 1, -11709.11, -1525.442, -5.128485, 0.5174151, 7200, 0, 0), -- Shredtooth Frenzy (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+936, 52417, 859, 1, 1, -11708.01, -1509.931, -1.892376, 6.174314, 7200, 0, 0), -- Shredtooth Frenzy (Area: Temple of Bethekk) (possible waypoints or random movement)
(@CGUID+937, 52081, 859, 1, 1, -11652.67, -1451.464, 59.57009, 1.064651, 7200, 0, 0), -- Gurubashi Cauldron-Mixer (Area: Temple of Bethekk)
(@CGUID+938, 52441, 859, 1, 1, -11581.32, -1465.106, 66.5325, 4.954762, 7200, 0, 0), -- Curious Jungle Monkey (Area: Temple of Bethekk)
(@CGUID+939, 52962, 859, 1, 1, -11642.18, -1443.04, 58.97274, 3.543018, 7200, 0, 0), -- Zandalari Archon (Area: 0)
(@CGUID+940, 52606, 859, 1, 1, -11652.46, -1440.208, 59.1482, 5.201081, 7200, 0, 0), -- Gurubashi Warmonger (Area: 0)
(@CGUID+941, 52086, 859, 1, 1, -11617.63, -1416.863, 61.76305, 1.466077, 7200, 0, 0), -- Hakkari Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+942, 52086, 859, 1, 1, -11609.56, -1417.788, 62.89562, 1.658063, 7200, 0, 0), -- Hakkari Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+943, 52087, 859, 1, 1, -11610.24, -1412.344, 64.05173, 0, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+944, 52087, 859, 1, 1, -11620.04, -1410.151, 63.10928, 3.86483, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+945, 52087, 859, 1, 1, -11613.81, -1410.9, 63.77493, 0.8033769, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+946, 52087, 859, 1, 1, -11611.51, -1408.276, 64.79598, 0.2346179, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+947, 52087, 859, 1, 1, -11608.05, -1408.96, 65.25175, 0.6872403, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+948, 52087, 859, 1, 1, -11617.95, -1405.593, 64.81339, 2.941468, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+949, 52087, 859, 1, 1, -11607.91, -1406.569, 65.84491, 2.921514, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+950, 52087, 859, 1, 1, -11610.08, -1405.354, 65.74004, 5.212203, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+951, 52087, 859, 1, 1, -11622.72, -1403.66, 66.1441, 0, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+952, 52087, 859, 1, 1, -11619.34, -1401.865, 66.06625, 3.501632, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+953, 52417, 859, 1, 1, -11695.17, -1482.576, -5.364932, 1.361028, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+954, 52087, 859, 1, 1, -11608.32, -1402.685, 66.67853, 4.492027, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+955, 52087, 859, 1, 1, -11621.43, -1398.091, 67.20886, 1.888348, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+956, 52376, 859, 1, 1, -11684.22, -1439.639, 43.13543, 5.308082, 7200, 0, 0), -- Florawing Needler (Area: 0)
(@CGUID+957, 52087, 859, 1, 1, -11613.31, -1397.963, 67.31001, 1.531099, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+958, 52087, 859, 1, 1, -11620.41, -1394.713, 68.06324, 3.398852, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+959, 52087, 859, 1, 1, -11618.44, -1394.49, 67.93043, 6.251822, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+960, 52087, 859, 1, 1, -11608.41, -1395.133, 68.29078, 6.100298, 7200, 0, 0), -- Zanzil Mindslave (Area: 0) (possible waypoints or random movement)
(@CGUID+961, 52417, 859, 1, 1, -11707.91, -1470.028, -0.5065457, 3.961897, 7200, 0, 0), -- Shredtooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+962, 52089, 859, 1, 1, -11676.81, -1416.96, 59.68342, 4.607669, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+963, 52089, 859, 1, 1, -11538.35, -1477.26, 72.70912, 2.548181, 7200, 0, 0), -- Gurubashi Worker (Area: 0)
(@CGUID+964, 52077, 859, 1, 1, -11603.51, -1348.462, 78.50488, 4.555309, 7200, 0, 0), -- Gurubashi Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+965, 52077, 859, 1, 1, -11616.92, -1344.288, 77.80741, 4.834562, 7200, 0, 0), -- Gurubashi Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+966, 52053, 859, 1, 1, -11565.64, -1303.637, 78.14742, 5.423434, 7200, 0, 0), -- Zanzil (Area: 0) (possible waypoints or random movement)
(@CGUID+967, 52054, 859, 1, 1, -11541.43, -1298.149, 85.2326, 2.338741, 7200, 0, 0), -- Zanzili Berserker (Area: 0)
(@CGUID+968, 52079, 859, 1, 1, -11687.67, -1386.737, 60.37096, 5.429971, 7200, 0, 0), -- Gurubashi Bloodrager (Area: 0) (possible waypoints or random movement)
(@CGUID+969, 52079, 859, 1, 1, -11691.45, -1390.008, 60.78281, 5.428172, 7200, 0, 0), -- Gurubashi Bloodrager (Area: 0) (possible waypoints or random movement)
(@CGUID+970, 52055, 859, 1, 1, -11592.2, -1336.095, 78.77258, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+971, 52055, 859, 1, 1, -11585.74, -1338.019, 80.3073, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+972, 52055, 859, 1, 1, -11584.32, -1335.333, 80.19098, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+973, 52055, 859, 1, 1, -11582.81, -1335.408, 80.35243, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+974, 52055, 859, 1, 1, -11588.89, -1337.807, 79.7257, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+975, 52055, 859, 1, 1, -11594.36, -1334.592, 78.29688, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+976, 52055, 859, 1, 1, -11588.6, -1333.964, 80.19955, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+977, 52055, 859, 1, 1, -11582.11, -1332.139, 79.94445, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+978, 52055, 859, 1, 1, -11583.41, -1330.972, 79.52431, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+979, 52055, 859, 1, 1, -11590.69, -1329.899, 78.3559, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+980, 52055, 859, 1, 1, -11586.63, -1332.127, 79.19479, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+981, 52055, 859, 1, 1, -11592.21, -1331.849, 78.35938, 0, 7200, 0, 0), -- Zanzili Zombie (Area: 0)
(@CGUID+982, 52054, 859, 1, 1, -11544.98, -1240.557, 81.50435, 3.926991, 7200, 0, 0), -- Zanzili Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+983, 52054, 859, 1, 1, -11603.58, -1233.599, 81.3652, 5.201081, 7200, 0, 0), -- Zanzili Berserker (Area: 0)
(@CGUID+984, 52055, 859, 1, 1, -11588.74, -1327.123, 78.38542, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+985, 52055, 859, 1, 1, -11586.49, -1327.729, 78.65105, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+986, 52055, 859, 1, 1, -11617.44, -1320.568, 79.0296, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+987, 52055, 859, 1, 1, -11621.9, -1320.009, 78.01384, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+988, 52055, 859, 1, 1, -11620.85, -1318.514, 78.08175, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+989, 52055, 859, 1, 1, -11614.41, -1317.852, 78.34747, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+990, 52055, 859, 1, 1, -11617.52, -1317.201, 78.65349, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+991, 52055, 859, 1, 1, -11621.96, -1316.311, 77.95103, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+992, 52055, 859, 1, 1, -11618.62, -1315.944, 78.30229, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+993, 52055, 859, 1, 1, -11615.52, -1315.01, 78.53697, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+994, 52055, 859, 1, 1, -11614.1, -1314.806, 78.545, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+995, 52055, 859, 1, 1, -11611.5, -1314.75, 78.44965, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+996, 52055, 859, 1, 1, -11620.22, -1314.358, 78.27634, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+997, 52055, 859, 1, 1, -11616.91, -1313.22, 78.65159, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+998, 52055, 859, 1, 1, -11614.74, -1312.698, 79.03841, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+999, 52055, 859, 1, 1, -11618.06, -1311.615, 78.65143, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1000, 52441, 859, 1, 1, -11699.27, -1355.961, 82.59517, 1.909774, 7200, 0, 0), -- Curious Jungle Monkey (Area: The Devil's Terrace)
(@CGUID+1001, 52055, 859, 1, 1, -11588.08, -1250.443, 77.85822, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1002, 52055, 859, 1, 1, -11595.96, -1257.306, 78.47816, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1003, 52055, 859, 1, 1, -11590.33, -1249.837, 77.80575, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1004, 52055, 859, 1, 1, -11590.48, -1260.521, 77.59503, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1005, 52055, 859, 1, 1, -11592.29, -1252.613, 77.69531, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1006, 52055, 859, 1, 1, -11593.81, -1254.563, 77.90052, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1007, 52055, 859, 1, 1, -11593.79, -1258.809, 77.83743, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1008, 52055, 859, 1, 1, -11583.71, -1254.852, 78.03294, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1009, 52055, 859, 1, 1, -11585.91, -1258.047, 77.72848, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1010, 52055, 859, 1, 1, -11587.33, -1260.733, 77.59835, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1011, 52055, 859, 1, 1, -11585, -1253.686, 77.91919, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1012, 52055, 859, 1, 1, -11590.19, -1256.677, 77.60883, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1013, 52055, 859, 1, 1, -11588.22, -1254.84, 77.62454, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1014, 52055, 859, 1, 1, -11584.4, -1258.122, 77.86124, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace)
(@CGUID+1015, 52055, 859, 1, 1, -11544.26, -1262.484, 78.41196, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1016, 52055, 859, 1, 1, -11546.43, -1260.981, 78.28993, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1017, 52055, 859, 1, 1, -11540.95, -1264.196, 78.96161, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1018, 52055, 859, 1, 1, -11537.81, -1264.408, 79.34549, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1019, 52055, 859, 1, 1, -11538.69, -1258.516, 79.09099, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1020, 52055, 859, 1, 1, -11534.18, -1258.528, 79.50695, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1021, 52055, 859, 1, 1, -11542.76, -1256.288, 79.03992, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1022, 52055, 859, 1, 1, -11534.87, -1261.797, 79.63195, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1023, 52055, 859, 1, 1, -11544.28, -1258.238, 78.47396, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1024, 52055, 859, 1, 1, -11540.66, -1260.352, 79.08317, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1025, 52055, 859, 1, 1, -11536.38, -1261.722, 79.47266, 0, 7200, 0, 0), -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
(@CGUID+1026, 52055, 859, 1, 1, -11540.8, -1253.512, 78.9323, 0, 7200, 0, 0); -- Zanzili Zombie (Area: The Devil's Terrace) (possible waypoints or random movement)
