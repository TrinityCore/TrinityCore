-- Up to TC2 5408

-- --------
-- LINKED
-- --------
-- spell1 / spell2 / type
-- + + 0 caster casts 2 when casts 1
-- + - 0 caster removes aura 2 when casts 1
-- + + 1 target casts 2 on self (originalCaster = caster) when 1 casted by caster hits target
-- + - 1 target removes aura 2 when hit by 1
-- + + 2 when aura 1 is applied, aura 2 is also applied; when 1 is removed, 2 is also removed
-- + - 2 when aura 1 is applied, target is immune to spell 2, until 1 is removed
-- - + 0 target casts 2 on self (originalCaster = caster) when aura 1 casted by caster is removed
-- - - 0 aura 2 is removed when aura 1 is removed

TRUNCATE TABLE `spell_linked_spell`;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
-- class
( 31224, -1543, 2, 'Cloak of Shadows - Flare'),
( 15237, 23455, 0, 'Holy Nova (rank1)'),
( 15430, 23458, 0, 'Holy Nova (rank2)'),
( 15431, 23459, 0, 'Holy Nova (rank3)'),
( 27799, 27803, 0, 'Holy Nova (rank4)'),
( 27800, 27804, 0, 'Holy Nova (rank5)'),
( 27801, 27805, 0, 'Holy Nova (rank6)'),
( 25331, 25329, 0, 'Holy Nova (rank7)'),
( 48077, 48075, 0, 'Holy Nova (rank8)'),
( 48078, 48076, 0, 'Holy Nova (rank9)'),
(-19386, 24131, 0, 'Wyvern Sting'),
(-24132, 24134, 0, 'Wyvern Sting'),
(-24133, 24135, 0, 'Wyvern Sting'),
(-27068, 27069, 0, 'Wyvern Sting'),
(-49011, 49009, 0, 'Wyvern Sting'),
(-49012, 49010, 0, 'Wyvern Sting'),
( 47585, 60069, 2, 'Dispersion (transform/regen)'),
( 47585, 63230, 2, 'Dispersion (immunity)'),
( 61847, 61848, 2, 'Aspect of the dragonhawk'),
( 61846, 61848, 2, 'Aspect of the dragonhawk'),
( 47988, 54501, 2, 'Consume Shadows - Rank 9'),
( 47987, 54501, 2, 'Consume Shadows - Rank 8'),
( 27272, 54501, 2, 'Consume Shadows - Rank 7'),
( 17854, 54501, 2, 'Consume Shadows - Rank 6'),
( 17853, 54501, 2, 'Consume Shadows - Rank 5'),
( 17852, 54501, 2, 'Consume Shadows - Rank 4'),
( 17851, 54501, 2, 'Consume Shadows - Rank 3'),
( 17850, 54501, 2, 'Consume Shadows - Rank 2'),
( 17767, 54501, 2, 'Consume Shadows - Rank 1'),
(-5143, -36032, 0, 'Arcane Missiles Rank 1'),
(-5144, -36032, 0, 'Arcane Missiles Rank 2'),
(-5145, -36032, 0, 'Arcane Missiles Rank 3'),
(-8416, -36032, 0, 'Arcane Missiles Rank 4'),
(-8417, -36032, 0, 'Arcane Missiles Rank 5'),
(-10211, -36032, 0, 'Arcane Missiles Rank 6'),
(-10212, -36032, 0, 'Arcane Missiles Rank 7'),
(-25345, -36032, 0, 'Arcane Missiles Rank 8'),
(-27075, -36032, 0, 'Arcane Missiles Rank 9'),
(-38699, -36032, 0, 'Arcane Missiles Rank 10'),
(-38704, -36032, 0, 'Arcane Missiles Rank 11'),
(-42843, -36032, 0, 'Arcane Missiles Rank 12'),
(-42846, -36032, 0, 'Arcane Missiles Rank 13'),
( 53563, 53651, 2, 'Beacon of Light'),
(   781, 56446, 0, 'Disengage'),
( 57635, 57636, 0, 'Disengage'),
( 60932, 60934, 0, 'Disengage'),
( 61507, 61508, 0, 'Disengage'),
( 49576, 49560, 0, 'Death Grip'),
( 47897, 47960, 1, 'Shadowflame Rank 1'),
( 61290, 61291, 1, 'Shadowflame Rank 2'),
( 51723, 52874, 0, 'Fan Of Knives'),
( 32386, 60448, 2, 'Shadow Embrace Rank1'),
( 32388, 60465, 2, 'Shadow Embrace Rank2'),
( 32389, 60466, 2, 'Shadow Embrace Rank3'),
( 32390, 60467, 2, 'Shadow Embrace Rank4'),
( 32391, 60468, 2, 'Shadow Embrace Rank5'),
( 33206, 44416, 2, 'Pain Suppression (threat)'),
( 50720, 59665, 0, 'Vigilance (redirect threat)'),
( 52610, 62071, 0, 'Savage Roar'),
( -52610, -62071, 0, 'Savage Roar'),
(51209, 55095, 1, 'Hungering cold - frost fever'),
(50334, 58923, 2, 'Berserk - modify target number aura'),
( -5229, -51185, 0, 'King of the Jungle - remove with enrage'),
(48384, 50170, 2, 'Improved Moonkin Form'),
(48395, 50171, 2, 'Improved Moonkin Form'),
(48396, 50172, 2, 'Improved Moonkin Form'),
( 20594, 65116, 0, 'Stoneform'),
( 49039, 50397, 2, 'Lichborne - shapeshift'),
( 64382, 64380, 0, 'Shattering Throw'),
( 19574, 24395, 2, 'Bestial Wrath'),
( 19574, 24396, 2, 'Bestial Wrath'),
( 19574, 24397, 2, 'Bestial Wrath'),
( 19574, 26592, 2, 'Bestial Wrath'),
( 34471, 24395, 2, 'The Beast Within'),
( 34471, 24396, 2, 'The Beast Within'),
( 34471, 24397, 2, 'The Beast Within'),
( 34471, 26592, 2, 'The Beast Within'),
(-59907,     7, 0, 'Lightwell Charges - Suicide'),
( 26022, 61417, 2, 'Pursuit of Justice'),
( 26023, 61418, 2, 'Pursuit of Justice'),
-- Quest
( 40214, 40216, 2, 'Dragonmaw Illusion'),
( 40214, 42016, 2, 'Dragonmaw Illusion'),
-- Creature
( 36574, 36650, 0, 'Apply Phase Slip Vulnerability'),
-- instance
(-30410, 44032, 0, 'Manticron Cube Mind Exhaustion'),
(-33711, 33686, 0, 'Murmur''s Shockwave (Normal)'),
(-38794, 33686, 0, 'Murmur''s Shockwave (Heroic)'),
( 33686, 31705, 0, 'Murmur''s Shockwave Jump'),
-- Zul'aman
( 44008, 45265, 1, 'Static Disruption Visual'),
( 43648, 44007, 1, 'Storm Eye Safe Zone'),
( 44007,-43657, 2, 'Storm Eye Safe Zone Immune'),
( 43658, 43653, 0, 'Electrical Arc Visual'),
( 43658, 43654, 0, 'Electrical Arc Visual'),
( 43658, 43655, 0, 'Electrical Arc Visual'),
( 43658, 43656, 0, 'Electrical Arc Visual'),
( 43658, 43659, 0, 'Electrical Arc Visual'),
-- black temple
-- (39992, 39835, 1, 'Needle Spine'),
( 39835, 39968, 1, 'Needle Spine'),
(-41376, 41377, 0, 'Spite'),
( 41126, 41131, 1, 'Flame Crash'),
(-41914, 41915, 0, 'Summon Parasitic Shadowfiend'),
(-41917, 41915, 0, 'Summon Parasitic Shadowfiend'),
( 39908, 40017, 1, 'Eye Blast'),
( 40604, 40616, 1, 'Fel Rage Aura'),
( 40616, 41625, 1, 'Fel Rage Aura'),
( 41292, 42017, 2, 'Aura of Suffering'),
-- sunwell
( 44869, 44866, 1, 'Spectral Blast Portal'),
-- (44869, 46648, 1, 'Spectral Blast Visual'), cause severe lag seems should be casted by go
( 44869, 46019, 1, 'Spectral Blast Teleport'),
( 46019, 46021, 1, 'Spectral Realm Aura'),
-- (46021, 44852, 1, 'Spectral Realm Aura'), 44852 makes boss friendly to you
(-46021, 46020, 0, 'Teleport: Normal Realm'),
( 46020, 44867, 1, 'Spectral Exhaustion'),
( 44867,-46019, 2, 'Spectral Exhaustion - Teleport: Spectral Realm'),
( 45661, 45665, 1, 'Encapsulate'),
( 45347,-45348, 1, 'Remove Flame Touched'),
( 45348,-45347, 1, 'Remove Dark Touched'),
( 45248, 45347, 1, 'Apply Dark Touched'),
( 45329, 45347, 1, 'Apply Dark Touched'),
( 45256, 45347, 1, 'Apply Dark Touched'),
( 45270, 45347, 1, 'Apply Dark Touched'),
( 45342, 45348, 1, 'Apply Flame Touched'),
( 46771, 45348, 1, 'Apply Flame Touched'),
( 45271, 45347, 1, 'Apply Dark Touched'),
( 45246, 45348, 1, 'Apply Flame Touched'),
( 44869,-45018, 1, 'Remove Arcane Buffet'),
( 46019,-45018, 1, 'Remove Arcane Buffet'),
( 46242, 46247, 0, 'Black Hole Visual (Birth)'),
( 46228, 46235, 0, 'Black Hole Visual (Grown)'),
( 46228,-46247, 0, 'Black Hole Visual (Grown)'),
( 46262, 46265, 0, 'Void Zone Visual'),
-- naxx
(-28169, 28206, 0, 'Mutating Injection - Mutagen Explosion'),
( 28732,-28798, 1, 'Widow''s Embrace - Frenzy'),
( 54097,-54100, 1, 'Widow''s Embrace - Frenzy (H)'),
(-28169, 28240, 0, 'Mutating Injection - Poison Cloud'),
-- Archavon
( 58666, 58672, 1, 'Impale (Archavon)'),
( 60882, 58672, 1, 'Impale (Archavon)');


-- --------
-- CLICK
-- --------

-- --------
-- TARGET
-- --------

DELETE FROM `spell_script_target` WHERE `entry` IN (58836, 50524, 50515, 52173, 60243);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(58836, 3, 31216), -- Mirror Image
(50524, 3, 27829), -- Runic Power Feed
(52173, 3, 28267), -- Coyote Spirit Despawn
(60243, 3, 11236), -- Blood Parrot Despawn
(50515, 3, 27829); -- Dismiss Gargoyle

-- zulaman
DELETE FROM `spell_script_target` WHERE `entry` IN
(42577,42471,43734,42631);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(42471, 1, 23817), -- hatch eggs
(43734, 1, 23817), -- hatch eggs
(42631, 1, 23920), -- fire bomb
(42577, 1, 24136); -- zap inform

-- sunwell
DELETE FROM `spell_script_target` WHERE `entry` IN
(44885,45388,45389,46350,45714);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(45388, 1, 25038),
(45389, 1, 25265),
(44885, 1, 25160),
(46350, 1, 25160),
(45714, 1, 25038);

-- Magtheridon
DELETE FROM spell_script_target WHERE `entry` IN
(30531,30657);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(30531, 1, 17256), -- soul transfer
(30657, 1, 24136); -- quake

-- black temple
DELETE FROM `spell_script_target` WHERE `entry` IN
(41455);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(41455, 1, 22949), -- circle of healing
(41455, 1, 22950),
(41455, 1, 22951),
(41455, 1, 22952);

-- Magisters' Terrace
DELETE FROM spell_script_target WHERE `entry` IN
(44320, 44321);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(44320, 1, 24723), -- Mana Rage
(44321, 1, 24723); -- Mana Rage

DELETE FROM `spell_script_target` WHERE `entry` IN
(30659);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(30659, 1, 17281); -- Fel Infusion

DELETE FROM `spell_script_target` WHERE `entry` IN
(34186, 42492, 33831, 5628, 45109, 45149);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(34186, 1, 16938),
(42492, 1, 0),
(33831, 1, 0),
(5628,  1, 2011),
(5628,  1, 2012),
(5628,  1, 2013),
(5628,  1, 2014),
(45109, 1, 25084),
(45149, 0, 300154);

DELETE FROM `spell_script_target` WHERE entry IN
(33655, 44374);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(33655, 0, 183350), -- Dropping The Nether Modulator/Gateway Murketh
(33655, 0, 183351),
(44374, 1, 24722);

REPLACE INTO `spell_script_target` VALUES
(33655,0,183350),
(33655,0,183351),
(44374,1,24722),
(31538,1,17895),
(29967,1,16524),
(39887,1,23002),
(31617,1,17899),
(31624,1,17899),
(31625,1,17899),
(34019,1,19422),
(34946,1,20040),
(34946,1,20041),
(43144,1,23817),
(12613,1,5843),
(9095,1,1200);

DELETE FROM `spell_script_target` WHERE entry IN
(8913,9095,12613,34019,34526,36904,38015,38738,39011,39844,40105,40106,42391);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(8913,  1, 1200),
(9095,  1, 6492),
(12613, 1, 5843),
(34019, 2, 16873), -- raise dead
(34019, 2, 16871),
(34019, 2, 19422),
(34019, 2, 16907),
(34526, 1, 19723),
(34526, 1, 19724),
(36904, 0, 21511),
(38015, 1, 21216),
(38738, 0, 185193), -- Activate Legion Obelisk
(38738, 0, 185195),
(38738, 0, 185196),
(38738, 0, 185197),
(38738, 0, 185198),
(39011, 1, 20885),
(39844, 0, 185549),
(40105, 1, 22883),
(40106, 1, 22883),
(42391, 0, 300152);

-- naxx
DELETE FROM `spell_script_target` WHERE `entry` IN
(28732,54097,55479,
27892,27893,27928,27929,27935,27936);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(28732, 1, 15953), -- Widow's Embrace
(54097, 1, 15953), -- Widow's Embrace
(55479, 1, 16803), -- Force Obedience - Death Knight Understudy
-- (29105, 1, 16803), -- Hopeless - Death Knight Understudy
(27892, 1, 16060), -- To Anchor 1 - Gothik
(27893, 1, 16060), -- To Anchor 2 - Gothik
(27928, 1, 16060), -- To Anchor 1 - Gothik
(27929, 1, 16060), -- To Anchor 2 - Gothik
(27935, 1, 16060), -- To Anchor 1 - Gothik
(27936, 1, 16060); -- To Anchor 2 - Gothik

-- too many...
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(3730,1,15263),
(6955,1,4946),
(7022,1,4945),
(7277,1,5409),
(9457,1,3701),
(11893,1,8156),
(12134,2,5270),
(12134,2,5271),
(12134,2,5273),
(12134,2,5256),
(12134,2,5259),
(13489,1,9178),
(15658,1,8929), -- It's up to script to implement SpellHit() for Moira Bronze beard
(16032,1,6557), -- Dummy effect should be implemented in core i think
(16337,1,10339),
(16337,1,10429), -- per spells description, it buffs two npc's.
(16637,1,10447),
(17748,1,10556),
(18969,1,12126),
(19749,1,12352), -- used by creature script to check if all troopers are presents, NYI
(19773,1,12018), -- used by Ragnaros to kill Majordomo
(21556,1,13378), -- no longer in game, but still could be used for some FUN-so why not fix it ? ;)
(21566,1,13416),
(22710,1,14349),
(23168,1,14020),
(24062,1,15010),
(24217,1,15069),
(24323,1,14834),
(24804,1,14888),
(25896,1,15299),
(28096,1,15929),
(28111,1,15930),
(28353,2,16390),
(28392,1,16420),
(28697,1,3976),
(28861,1,16592),
(29172,0,181605),
(29456,1,17060),
(29457,1,17060),
(29459,1,17060), -- Those are spells Arch Mage Xintor casts at training dummies near him.
(29531,0,181605),
(29831,0,181288),
(30221,1,620),
(30232,1,15691),
(30460,1,17404),
(30951,1,17533),
(31326,1,15608),
(31611,1,17979),
(31727,1,17536),
(32301,1,18371),
(32396,1,18358),
(32890,1,18764),
(33111,1,17400),
(33111,1,18894),
(33644,1,19279),
(33644,1,19328),
(33644,1,19278),
(33644,1,19329),
(33644,1,19326),
(33644,1,19277),
(33644,1,19276), -- All legion antennas.
(33742,1,17400),
(33742,1,18894),
(33742,1,19279),
(33742,1,19328),
(33742,1,19278),
(33742,1,19329),
(33742,1,19326),
(33742,1,19277),
(33742,1,19276), -- All legion antennas, another spell.
(33783,1,18732),
(34254,1,19554),
(34350,1,19554),
(34662,1,17827),
(35596,1,20794),
(36174,1,20885),
(37465,1,17469),
(37465,1,21747),
(37465,1,21750),
(37465,1,21748),
(37469,1,21664),
(37469,1,21682),
(37469,1,21683),
(37469,1,17211),
(37626,1,15689), -- Netherspite's beam
(37853,1,15608),
(37868,1,21909),
(37893,1,21909),
(37895,1,21909),
(38003,1,21949),
(38044,1,21212),
(38121,1,21949),
(38123,1,21949),
(38126,1,21949),
(38128,1,21949),
(38130,1,21949),
(38250,0,185125),
(38508,1,17270),
(38508,1,16873),
(38508,1,17269),
(38508,1,16871),
(38508,1,19422),
(38508,1,16907),
(38508,1,17478),
(38508,1,19424),
(38629,0,185214),
(38722,1,21506),
(38966,1,22293),
(39124,0,184738),
(39126,1,19557),
(39221,1,23116),
(39364,1,19732),
(39601,1,22916),
(39974,0,300127),
(39978,1,21851),
(39993,1,23382),
(40359,1,23382),
(40454,1,22181),
(40547,1,22911),
(40828,1,23327),
(40828,1,23322),
(41128,1,23164),
(41362,1,22956),
(41362,1,22964),
(41975,1,23191),
(42317,1,22844),
(42317,1,23319),
(42317,1,23421),
(42317,1,23216),
(42317,1,23523),
(42317,1,22849),
(42317,1,22845),
(42317,1,22847),
(42317,1,23318),
(42317,1,23215),
(42317,1,23524),
(42317,1,23374),
(42317,1,22846),
(42318,1,22844),
(42318,1,23319),
(42318,1,23421),
(42318,1,23216),
(42318,1,23523),
(42318,1,22849),
(42318,1,22845),
(42318,1,22847),
(42318,1,23318),
(42318,1,23215),
(42318,1,23524),
(42318,1,23374),
(42318,1,22846),
(42405,1,23775),
(42410,1,23775),
(42517,1,23864),
(42734,1,4974),
(44864,1,24955),
(45201,1,24882),
(46809,1,26239), -- Make Ahune's Ghost Burst
(46818,1,25840),
(46852,0,181605), -- Ribbon Pole Music
(46896,0,181605),
(47104,1,26401),
(49058,1,24968); -- Rocket Bot Attack

DELETE FROM `spell_script_target` WHERE entry IN
(42857,44807,32307,32314,42222);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(42857, 1, 23954), -- Scourge Resurrection
(44807, 1, 24850), -- Crazed Rage - Kalecgos
(44807, 1, 24892),
(32307, 2, 17146), -- Plant Warmaul Ogre Banner
(32307, 2, 17147),
(32307, 2, 17148),
(32307, 2, 18658),
(32314, 2, 17138), -- Plant Kil'sorrow Banner
(32314, 2, 18037),
(32314, 2, 18064),
(32314, 2, 18065),
(42222, 1, 23616); -- Lunch for Kyle

DELETE FROM `spell_script_target` WHERE `entry` IN
(46589, 45839, 45976, 46177);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(46589, 1, 30598), -- Shadow Spike - Spike Target
(46589, 1, 30614), -- Shadow Spike - Spike Target 2
(45839, 1, 25653), -- Vengeance of the Blue Flight - Power of the Blue Flight
(45976, 1, 25770), -- Open Portal
(46177, 1, 25770); -- Open All Portals

DELETE FROM `spell_script_target` WHERE entry IN
(58672);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(58672, 1, 31125); -- Impale (Archavon)

-- Teleports in dk starting area
DELETE FROM `spell_script_target` WHERE entry IN
(54699,54725,54744,54746);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(54699,1,0),
(54725,1,0),
(54744,1,0),
(54746,1,0);

-- For quest The Denouncement and The Restless Dead
DELETE FROM `spell_script_target` WHERE `entry` IN (48714,57806);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(48714, 2, 27237),
(48714, 2, 27235),
(48714, 2, 27234),
(48714, 2, 27236),
(57806, 2, 31043);

-- Zul'Drak
DELETE FROM `spell_script_target` WHERE `entry` IN (55083,55223,59951,59952);
INSERT INTO `spell_script_target` VALUES
(55083, 1, 29700),(55223, 1, 29686),
(59951, 1, 29686),(59952, 1, 29686);

-- --------
-- POSITION
-- --------
DELETE FROM spell_target_position WHERE `id` IN (46019, 46020, 53360);
INSERT INTO spell_target_position (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(46019, 580, 1704.34, 928.17, -74.558, 0),
(46020, 580, 1704.34, 928.17, 53.079, 0),
(53360, 571, 5807.829, 587.960, 660.939, 1.663);

-- positions for teleports in acherus
DELETE FROM `spell_target_position` WHERE `id` IN (54744,54746);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(54744, 0, 2418.67, -5621.41, 420.644, 3.89597),
(54746, 0, 2402.15, -5633.74, 377.021, 3.65249);

-- positions for Dalaran 'Trespasser!' spell
DELETE FROM `spell_target_position` WHERE `id` IN (54028,54029);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(54028, 571, 5758.79, 678.359, 642.726, 5.572),
(54029, 571, 5849.16, 602.093, 651.13, 2.364);

-- --------
-- MISC
-- --------
DELETE FROM `playercreateinfo_spell` WHERE Spell = 56816;
INSERT INTO `playercreateinfo_spell` (`race`, `class`, `Spell`, `Note`) VALUES
(0, 6, 56816, 'Rune Strike');
DELETE FROM `playercreateinfo_spell` WHERE `spell` = 60091;
INSERT INTO `playercreateinfo_spell` (`race`, `class`, `Spell`, `Note`) VALUES
(1, 2,  60091, 'Judgement Anti-Parry/Dodge Passive'),
(3, 2,  60091, 'Judgement Anti-Parry/Dodge Passive'),
(10, 2,  60091, 'Judgement Anti-Parry/Dodge Passive'),
(11, 2,  60091, 'Judgement Anti-Parry/Dodge Passive');

-- --------
-- PROC
-- --------
/*
This is not a good way, but I do not know if there is better way to do it
select entry,
CONCAT('0x',LPAD(HEX(schoolmask),2,'0')),
spellfamilyname,
CONCAT('0x',LPAD(HEX(spellfamilymask0),8,'0')),
CONCAT('0x',LPAD(HEX(spellfamilymask1),8,'0')),
CONCAT('0x',LPAD(HEX(spellfamilymask2),8,'0')),
CONCAT('0x',LPAD(HEX(procflags),8,'0')),
CONCAT('0x',LPAD(HEX(procex),8,'0')),
ppmrate, customchance, cooldown
from spell_proc_event order by entry;
*/
TRUNCATE TABLE `spell_proc_event`;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(   324, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 1)
(   325, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 2)
(   905, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 3)
(   945, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 4)
(   974, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield (Rank 1)
(  1463, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 1)
(  3232, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Gouge Stun Test
(  5952, 0x00,   8, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Throwing Specialization (Rank 1)
(  6346, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000100,   0,   0,   0), -- Fear Ward
(  7383, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000100,   0,   0,   0), -- Water Bubble
(  7434, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Fate Rune of Unsurpassed Vigor
(  8134, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 5)
(  8178, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Grounding Totem Effect (Rank 1)
(  8494, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 2)
(  8495, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 3)
(  9452, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Vindication (Rank 1)
(  9782, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Mithril Shield Spike
(  9784, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Iron Shield Spike
(  9799, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Eye for an Eye (Rank 1)
( 10191, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 4)
( 10192, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 5)
( 10193, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 6)
( 10431, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 6)
( 10432, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 7)
( 11095, 0x00,   3, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Scorch (Rank 1)
( 11119, 0x04,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ignite (Rank 1)
( 11120, 0x04,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ignite (Rank 2)
( 11129, 0x00,   3, 0x00C00017, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Combustion
( 11180, 0x10,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Winter's Chill (Rank 1)
( 11185, 0x00,   3, 0x00000080, 0x00000000, 0x00000000, 0x00050000, 0x00000000,   0,   0,   0), -- Improved Blizzard (Rank 1)
( 11255, 0x00,   3, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Counterspell (Rank 1)
( 12169, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Block
( 12281, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sword Specialization (Rank 1)
( 12289, 0x00,   4, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Hamstring (Rank 1)
( 12298, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 1)
( 12311, 0x00,   4, 0x00000800, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Gag Order (Rank 1)
( 12319, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 1)
( 12322, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Unbridled Wrath (Rank 1)
( 12487, 0x00,   3, 0x00000080, 0x00000000, 0x00000000, 0x00050000, 0x00000000,   0,   0,   0), -- Improved Blizzard (Rank 2)
( 12488, 0x00,   3, 0x00000080, 0x00000000, 0x00000000, 0x00050000, 0x00000000,   0,   0,   0), -- Improved Blizzard (Rank 3)
( 12598, 0x00,   3, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Counterspell (Rank 2)
( 12668, 0x00,   4, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Hamstring (Rank 2)
( 12724, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 2)
( 12725, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 3)
( 12726, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 4)
( 12727, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 5)
( 12797, 0x00,   4, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Revenge (Rank 1)
( 12799, 0x00,   4, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Revenge (Rank 2)
( 12812, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sword Specialization (Rank 2)
( 12813, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sword Specialization (Rank 3)
( 12814, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sword Specialization (Rank 4)
( 12815, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sword Specialization (Rank 5)
( 12834, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Deep Wounds (Rank 1)
( 12846, 0x04,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ignite (Rank 3)
( 12847, 0x04,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ignite (Rank 4)
( 12848, 0x04,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ignite (Rank 5)
( 12849, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Deep Wounds (Rank 2)
( 12867, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Deep Wounds (Rank 3)
( 12872, 0x00,   3, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Scorch (Rank 2)
( 12873, 0x00,   3, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Scorch (Rank 3)
( 12958, 0x00,   4, 0x00000800, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Gag Order (Rank 2)
( 12966, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 1)
( 12967, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 2)
( 12968, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 3)
( 12969, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 4)
( 12970, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 5)
( 12971, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 2)
( 12972, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 3)
( 12973, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 4)
( 12974, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 5)
( 12999, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   4,   0,   0), -- Unbridled Wrath (Rank 2)
( 13000, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   6,   0,   0), -- Unbridled Wrath (Rank 3)
( 13001, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   8,   0,   0), -- Unbridled Wrath (Rank 4)
( 13002, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  10,   0,   0), -- Unbridled Wrath (Rank 5)
( 13163, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   0), -- Aspect of the Monkey
( 13754, 0x00,   8, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Kick (Rank 1)
( 13867, 0x00,   8, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Kick (Rank 2)
( 13983, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018,   0,   0,   0), -- Setup (Rank 1)
( 14070, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018,   0,   0,   0), -- Setup (Rank 2)
( 14071, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018,   0,   0,   0), -- Setup (Rank 3)
( 14156, 0x00,   8, 0x003E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Ruthlessness (Rank 1)
( 14160, 0x00,   8, 0x003E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Ruthlessness (Rank 2)
( 14161, 0x00,   8, 0x003E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Ruthlessness (Rank 3)
( 14186, 0x00,   8, 0x40800508, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Seal Fate (Rank 1)
( 14190, 0x00,   8, 0x40800508, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Seal Fate (Rank 2)
( 14193, 0x00,   8, 0x40800508, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Seal Fate (Rank 3)
( 14194, 0x00,   8, 0x40800508, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Seal Fate (Rank 4)
( 14195, 0x00,   8, 0x40800508, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Seal Fate (Rank 5)
( 14531, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Martyrdom (Rank 1)
( 14774, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Martyrdom (Rank 2)
( 14892, 0x00,   6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Inspiration (Rank 1)
( 15088, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry
( 15128, 0x04,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Mark of Flames
( 15277, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   6,   0,   0), -- Seal of Reckoning
( 15286, 0x20,   6, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Embrace
( 15337, 0x00,   6, 0x00002000, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Improved Spirit Tap (Rank 1)
( 15338, 0x00,   6, 0x00002000, 0x00000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Improved Spirit Tap (Rank 2)
( 15318, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0), -- Shadow Affinity (Rank 1)
( 15272, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0), -- Shadow Affinity (Rank 2)
( 15320, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0), -- Shadow Affinity (Rank 3)
( 15346, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   6,   0,   0), -- Seal of Reckoning
( 15362, 0x00,   6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Inspiration (Rank 2)
( 15363, 0x00,   6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Inspiration (Rank 3)
( 15600, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   1,   0,   0), -- Hand of Justice
( 16086, 0x04,  11, 0x00000020, 0x00000000, 0x00000000, 0x00011000, 0x00000000,   0,   0,   0), -- Improved Fire Nova Totem (Rank 1)
( 16544, 0x04,  11, 0x00000020, 0x00000000, 0x00000000, 0x00011000, 0x00000000,   0, 100,   0), -- Improved Fire Nova Totem (Rank 2)
( 16176, 0x00,  11, 0x000001C0, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Healing (Rank 1)
( 16180, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Improved Water Shield (Rank 1)
( 16196, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Improved Water Shield (Rank 2)
( 16198, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Improved Water Shield (Rank 3)
( 16235, 0x00,  11, 0x000001C0, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Healing (Rank 2)
( 16240, 0x00,  11, 0x000001C0, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Healing (Rank 3)
( 16256, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 1)
( 16257, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 1)
( 16277, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 2)
( 16278, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 3)
( 16279, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 4)
( 16280, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Flurry (Rank 5)
( 16281, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 2)
( 16282, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 3)
( 16283, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 4)
( 16284, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Flurry (Rank 5)
( 16487, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blood Craze (Rank 1)
( 16489, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blood Craze (Rank 2)
( 16492, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blood Craze (Rank 3)
( 16550, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Bonespike (Rank 1)
( 16620, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Proc Self Invulnerability
( 16624, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Thorium Shield Spike
( 16850, 0x00,   7, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Celestial Focus (Rank 1)
( 16864, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Omen of Clarity
( 16880, 0x48,   7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Nature's Grace
( 16923, 0x00,   7, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Celestial Focus (Rank 2)
( 16924, 0x00,   7, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Celestial Focus (Rank 3)
( 16952, 0x00,   7, 0x00039000, 0x00000400, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blood Frenzy (Rank 1)
( 16954, 0x00,   7, 0x00039000, 0x00000400, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blood Frenzy (Rank 2)
( 16958, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Primal Fury (Rank 1)
( 16961, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Primal Fury (Rank 2)
( 17106, 0x00,   7, 0x00080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Intensity (Rank 1)
( 17107, 0x00,   7, 0x00080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Intensity (Rank 2)
( 17108, 0x00,   7, 0x00080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Intensity (Rank 3)
( 17364, 0x08,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Stormstrike
( 17495, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Crest of Retribution
( 17619, 0x00,  13, 0x00000000, 0x00000000, 0x00000000, 0x00008000, 0x00000000,   0,   0,   0), -- Alchemist's Stone
( 17793, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Shadow Bolt (Rank 1)
( 17796, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Shadow Bolt (Rank 2)
( 17801, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Shadow Bolt (Rank 3)
( 17802, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Shadow Bolt (Rank 4)
( 17803, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Shadow Bolt (Rank 5)
( 18094, 0x00,   5, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Nightfall (Rank 1)
( 18095, 0x00,   5, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Nightfall (Rank 2)
( 18820, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Insight
( 19184, 0x00,   9, 0x00000014, 0x00002000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Entrapment (Rank 1)
( 19387, 0x00,   9, 0x00000014, 0x00002000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Entrapment (Rank 2)
( 19388, 0x00,   9, 0x00000014, 0x00002000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Entrapment (Rank 3)
( 19572, 0x00,   9, 0x00800000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Mend Pet (Rank 1)
( 19573, 0x00,   9, 0x00800000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Mend Pet (Rank 2)
( 20049, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Vengeance (Rank 1)
( 20056, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Vengeance (Rank 2)
( 20057, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Vengeance (Rank 3)
( 20128, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Redoubt
( 20131, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Redoubt
( 20132, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Redoubt
( 20164, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   5,   0,   0), -- Seal of Justice
( 20165, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  20,   0,   0), -- Seal of Light
( 20166, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  12,   0,   0), -- Seal of Wisdom
( 20177, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Reckoning (Rank 1)
( 20179, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Reckoning (Rank 2)
( 20180, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Reckoning (Rank 4)
( 20181, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Reckoning (Rank 3)
( 20182, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Reckoning (Rank 5)
( 20185, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  15,   0,   0), -- Judgement of Light
( 20186, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  15,   0,   0), -- Judgement of Wisdom
( 20210, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 1)
( 20212, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 2)
( 20213, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 3)
( 20214, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 4)
( 20215, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 5)
( 20234, 0x00,  10, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Lay on Hands (Rank 1)
( 20235, 0x00,  10, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Lay on Hands (Rank 2)
( 20375, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   7,   0,   1), -- Seal of Command
( 20500, 0x00,   4, 0x10000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Berserker Rage (Rank 1)
( 20501, 0x00,   4, 0x10000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Berserker Rage (Rank 2)
( 20705, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Power Shield 500
( 20911, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Blessing of Sanctuary
( 20925, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 1)
( 20927, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 2)
( 20928, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 3)
( 21185, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Spinal Reaper
( 21882, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Judgement Smite
( 21890, 0x00,   4, 0x2A764EEF, 0x0000036C, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Warrior's Wrath
( 22007, 0x00,   3, 0x00200021, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Netherwind Focus
( 22618, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Force Reactive Disk
( 22648, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Call of Eskhandar
( 23547, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Parry
( 23548, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Parry
( 23551, 0x00,  11, 0x000000C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lightning Shield
( 23552, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield
( 23572, 0x00,  11, 0x000000C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Mana Surge
( 23578, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Expose Weakness
( 23581, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Bloodfang
( 23602, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Specialization (Rank 1)
( 23686, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Lightning Strike
( 23688, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Aura of the Blue Dragon
( 23689, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   4,   0,   0), -- Heroism
( 23695, 0x00,   4, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Hamstring (Rank 3)
( 23721, 0x00,   9, 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Arcane Infused
( 23920, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Spell Reflection
( 24353, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Primal Instinct
( 24389, 0x00,   3, 0x00C00017, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chaos Fire
( 24398, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 7)
( 24658, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00014110, 0x00000000,   0,   0,   0), -- Unstable Power
( 24905, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,  15,   0,   0), -- Moonkin Form (Passive) (Passive)
( 24932, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   6), -- Leader of the Pack
( 25050, 0x04,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Mark of Flames
( 25469, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 8)
( 25472, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 9)
( 25669, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   1,   0,   0), -- Decapitate
( 25899, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Greater Blessing of Sanctuary
( 25988, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Eye for an Eye (Rank 2)
( 26016, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Vindication (Rank 2)
( 26107, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000064,   0,   0,   0), -- Symbols of Unending Life Finisher Bonus
( 26119, 0x00,  10, 0x90100003, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Stormcaller Spelldamage Bonus
( 26128, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008,   0,   0,   0), -- Enigma Resist Bonus
( 26135, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Battlegear of Eternal Justice
( 26480, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Badge of the Swarmguard
( 26605, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Bloodcrown
( 27131, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 7)
( 27179, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 4)
( 27419, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Warrior's Resolve
( 27498, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Crusader's Wrath
( 27521, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,  15), -- Mana Restore
( 27656, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Flame Lash
( 27774, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- The Furious Storm
( 27787, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Rogue Armor Energize
( 27811, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Recovery (Rank 1)
( 27815, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Recovery (Rank 2)
( 27816, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Recovery (Rank 3)
( 28592, 0x10,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Winter's Chill (Rank 2)
( 28593, 0x10,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Winter's Chill (Rank 3)
( 28716, 0x00,   7, 0x00000010, 0x00000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Rejuvenation
( 28719, 0x00,   7, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Healing Touch
( 28744, 0x00,   7, 0x00000040, 0x00000000, 0x00000000, 0x00044000, 0x00000000,   0,   0,   0), -- Regrowth
( 28752, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Adrenaline Rush
( 28789, 0x00,  10, 0xC0000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Holy Power
( 28802, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Epiphany
( 28809, 0x00,   6, 0x00001000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Greater Heal
( 28812, 0x00,   8, 0x02000006, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Head Rush
( 28816, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Invigorate
( 28823, 0x00,  11, 0x000000C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Totemic Power
( 28847, 0x00,   7, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Healing Touch Refund
( 28849, 0x00,  11, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lesser Healing Wave
( 29074, 0x14,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Master of Elements (Rank 1)
( 29075, 0x14,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Master of Elements (Rank 2)
( 29076, 0x14,   3, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Master of Elements (Rank 3)
( 29150, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Electric Discharge
( 29179, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Devastation (Rank 2)
( 29180, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Devastation (Rank 3)
( 29385, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   7,   0,   0), -- Seal of Command
( 29441, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008,   0,   0,   1), -- Magic Absorption (Rank 1)
( 29444, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008,   0,   0,   1), -- Magic Absorption (Rank 2)
( 29455, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Felsteel Shield Spike
( 29501, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Frost Arrow
( 29593, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Improved Defensive Stance (Rank 1)
( 29594, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Improved Defensive Stance (Rank 2)
( 29624, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Searing Arrow
( 29625, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Flaming Cannonball
( 29626, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Shadow Bolt
( 29632, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Shadow Shot
( 29633, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Fire Blast
( 29634, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Quill Shot
( 29635, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Flaming Shell
( 29636, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Venom Shot
( 29637, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Keeper's Sting
( 29801, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Rampage (Rank 1)
( 29834, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Second Wind (Rank 1)
( 29838, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Second Wind (Rank 2)
( 29977, 0x00,   3, 0x00C00017, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Combustion
( 30003, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Sheen of Zanza
( 30160, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Devastation (Rank 1)
( 30293, 0x00,   5, 0x00000381, 0x000200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Soul Leech (Rank 1)
( 30295, 0x00,   5, 0x00000381, 0x000200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Soul Leech (Rank 2)
( 30296, 0x00,   5, 0x00000381, 0x000200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Soul Leech (Rank 3)
( 30299, 0x7E,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Nether Protection (Rank 1)
( 30301, 0x7E,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Nether Protection (Rank 2)
( 30302, 0x7E,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Nether Protection (Rank 3)
( 30675, 0x00,  11, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lightning Overload (Rank 1)
( 30678, 0x00,  11, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lightning Overload (Rank 2)
( 30679, 0x00,  11, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lightning Overload (Rank 3)
( 30701, 0x1C,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Elemental Absorption (Rank 1)
( 30705, 0x1C,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Elemental Absorption (Rank 5)
( 30802, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 1)
( 30803, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 1)
( 30804, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 2)
( 30805, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 3)
( 30808, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 2)
( 30809, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Unleashed Rage (Rank 3)
( 30823, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 10.,   0,   0), -- Shamanistic Rage
( 30881, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Nature's Guardian (Rank 1)
( 30883, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Nature's Guardian (Rank 2)
( 30884, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Nature's Guardian (Rank 3)
( 30885, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Nature's Guardian (Rank 4)
( 30886, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Nature's Guardian (Rank 5)
( 30937, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Mark of Shadow
( 31124, 0x00,   8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blade Twisting (Rank 1)
( 31126, 0x00,   8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blade Twisting (Rank 2)
( 31221, 0x00,   8, 0x00400000, 0x00000000, 0x00000000, 0x00000400, 0x00006001,   0,   0,   0), -- Master of Subtlety (Rank 1)
( 31222, 0x00,   8, 0x00400000, 0x00000000, 0x00000000, 0x00000400, 0x00006001,   0,   0,   0), -- Master of Subtlety (Rank 2)
( 31223, 0x00,   8, 0x00400000, 0x00000000, 0x00000000, 0x00000400, 0x00006001,   0,   0,   0), -- Master of Subtlety (Rank 3)
( 31244, 0x00,   8, 0x003E0000, 0x00000009, 0x00000000, 0x00000000, 0x00000004,   0,   0,   0), -- Quick Recovery (Rank 1)
( 31245, 0x00,   8, 0x003E0000, 0x00000009, 0x00000000, 0x00000000, 0x00000004,   0,   0,   0), -- Quick Recovery (Rank 2)
( 31394, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Mark of Shadow
( 31569, 0x00,   3, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Blink (Rank 1)
( 31570, 0x00,   3, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Blink (Rank 2)
( 31571, 0x00,   3, 0x00000000, 0x00000022, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Arcane Potency (Rank 1)
( 31572, 0x00,   3, 0x00000000, 0x00000022, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Arcane Potency (Rank 2)
( 31794, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Focused Mind
( 31801, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  20,   0,   0), -- Seal of Vengeance
( 31833, 0x00,  10, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Light's Grace (Rank 1)
( 31835, 0x00,  10, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Light's Grace (Rank 2)
( 31836, 0x00,  10, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Light's Grace (Rank 3)
( 31871, 0x00,  10, 0x00000010, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Divine Purpose (Rank 1)
( 31872, 0x00,  10, 0x00000010, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Divine Purpose (Rank 2)
( 31876, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Wise (Rank 1)
( 31877, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Wise (Rank 2)
( 31878, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Wise (Rank 3)
( 31904, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield
( 32385, 0x00,   5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Embrace (Rank 1)
( 32387, 0x00,   5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Embrace (Rank 2)
( 32392, 0x00,   5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Embrace (Rank 3)
( 32393, 0x00,   5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Embrace (Rank 4)
( 32394, 0x00,   5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Embrace (Rank 5)
( 32409, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Word: Death
( 32587, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Block
( 32593, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield (Rank 2)
( 32594, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield (Rank 3)
( 32642, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Spore Cloud
( 32734, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield
( 32748, 0x00,   8, 0x00000000, 0x00000001, 0x00000000, 0x00000140, 0x00000000,   0,   0,   0), -- Deadly Throw Interrupt (Rank 5)
( 32776, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Redoubt
( 32777, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield
( 32837, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,  45), -- Spell Focus Trigger
( 32844, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,   0), -- Lesser Heroism
( 32885, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Infuriate
( 33076, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 1)
( 33089, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Vigilance of the Colossus
( 33127, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   7,   0,   0), -- Seal of Command
( 33142, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Resilience (Rank 1)
( 33145, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Resilience (Rank 2)
( 33146, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Blessed Resilience (Rank 3)
( 33150, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Surge of Light (Rank 1)
( 33151, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Surge of Light (Rank 1)
( 33154, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Surge of Light (Rank 2)
( 33174, 0x00,   6, 0x00000020, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Divine Spirit (Rank 1)
( 33182, 0x00,   6, 0x00000020, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Divine Spirit (Rank 2)
( 33191, 0x00,   6, 0x00808000, 0x00000400, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Misery (Rank 1)
( 33192, 0x00,   6, 0x00808000, 0x00000400, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Misery (Rank 2)
( 33193, 0x00,   6, 0x00808000, 0x00000400, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Misery (Rank 3)
( 33297, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Spell Haste Trinket
( 33299, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Coilfang Slave Pens Lvl 70 Boss3a Caster Trinket
( 33510, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   5,   0,   0), -- Health Restore
( 33648, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Reflection of Torment
( 33719, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Perfect Spell Reflection
( 33736, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 8)
( 33746, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Essence Infused Mushroom
( 33757, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Windfury Weapon (Passive) (Rank 1)
( 33759, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Power Infused Mushroom
( 33881, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Natural Perfection (Rank 1)
( 33882, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Natural Perfection (Rank 2)
( 33883, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Natural Perfection (Rank 3)
( 33953, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00044000, 0x00000000,   0,   0,  45), -- Essence of Life
( 34074, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003,   0,   0,   0), -- Aspect of the Viper
( 34080, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008,   0,   0,   0), -- Riposte Stance
( 34138, 0x00,  11, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Totem of the Third Wind
( 34139, 0x00,  10, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Libram of Justice
( 34258, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Justice
( 34262, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Mercy
( 34320, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Call of the Nexus
( 34355, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Poison Shield
( 34457, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Ferocious Inspiration (Rank 1)
( 34497, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Thrill of the Hunt (Rank 1)
( 34498, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Thrill of the Hunt (Rank 2)
( 34499, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Thrill of the Hunt (Rank 3)
( 34500, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Expose Weakness (Rank 1)
( 34502, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Expose Weakness (Rank 2)
( 34503, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Expose Weakness (Rank 3)
( 34584, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Love Struck
( 34586, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 1.5,   0,   0), -- Romulo's Poison
( 34598, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Karazhan Caster Robe
( 34749, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008,   0,   0,   0), -- Recurring Power
( 34753, 0x00,   6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Holy Concentration (Rank 1)
( 34774, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 1.5,   0,  20), -- Magtheridon Melee Trinket
( 34783, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Spell Reflection
( 34827, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield
( 34859, 0x00,   6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Holy Concentration (Rank 2)
( 34860, 0x00,   6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Holy Concentration (Rank 3)
( 34914, 0x00,   6, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Touch (Rank 1)
( 34916, 0x00,   6, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Touch (Rank 2)
( 34917, 0x00,   6, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Touch (Rank 3)
( 34935, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   8), -- Backlash (Rank 1)
( 34938, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   8), -- Backlash (Rank 2)
( 34939, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   8), -- Backlash (Rank 3)
( 34950, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Go for the Throat (Rank 1)
( 34954, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Go for the Throat (Rank 2)
( 35077, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Band of the Eternal Defender
( 35080, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   1,   0,  60), -- Band of the Eternal Champion
( 35083, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Band of the Eternal Sage
( 35086, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Band of the Eternal Restorer
( 35121, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Nether Power
( 35541, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00800000, 0x00000000,   0,   0,   0), -- Combat Potency (Rank 1)
( 35550, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00800000, 0x00000000,   0,   0,   0), -- Combat Potency (Rank 2)
( 35551, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00800000, 0x00000000,   0,   0,   0), -- Combat Potency (Rank 3)
( 35552, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00800000, 0x00000000,   0,   0,   0), -- Combat Potency (Rank 4)
( 35553, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00800000, 0x00000000,   0,   0,   0), -- Combat Potency (Rank 5)
( 36032, 0x00,   3, 0x00001000, 0x00008000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Arcane Blast
( 36096, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Spell Reflection
( 36111, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- World Breaker
( 36541, 0x04,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Curse of Burning Shadows
( 37165, 0x00,   8, 0x00200400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Haste
( 37168, 0x00,   8, 0x003E0000, 0x00000009, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Finisher Combo
( 37170, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   1,   0,   0), -- Free Finisher Chance
( 37173, 0x00,   8, 0x2CBC0598, 0x00000106, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Armor Penetration
( 37189, 0x00,  10, 0xC0000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  60), -- Recuced Holy Light Cast Time
( 37193, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Infused Shield
( 37195, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgement Group Heal
( 37197, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,  45), -- Spell Damage
( 37213, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Mana Cost Reduction
( 37214, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Energized
( 37227, 0x00,  11, 0x000001C0, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  60), -- Improved Healing Wave
( 37237, 0x00,  11, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Lightning Bolt Discount
( 37247, 0x08,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,  45), -- Regain Mana
( 37377, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Shadowflame
( 37379, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Flameshadow
( 37384, 0x00,   5, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Corruption and Immolate
( 37443, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Crit Bonus Damage
( 37514, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Blade Turning
( 37516, 0x00,   4, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Revenge Bonus
( 37519, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000030,   0,   0,   0), -- Rage Bonus
( 37523, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Reinforced Shield
( 37528, 0x00,   4, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Overpower Bonus
( 37536, 0x00,   4, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Battle Shout
( 37568, 0x00,   6, 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Greater Heal Discount
( 37594, 0x00,   6, 0x00001000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Greater Heal Refund
( 37600, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Offensive Discount
( 37601, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Relentlessness
( 37603, 0x00,   6, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shadow Word Pain Damage
( 37655, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Bonus Mana Regen
( 37657, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   3), -- Lightning Capacitor
( 38026, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000100,   0,   0,   0), -- Viscous Shield
( 38031, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Shield Block
( 38290, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 1.6,   0,   0), -- Santos' Blessing
( 38299, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  15), -- HoTs on Heals
( 38326, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Crit Threat Reduction Melee
( 38327, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Crit Threat Reduction Spell
( 38334, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Proc Mana Regen
( 38347, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Crit Proc Spell Damage
( 38350, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Crit Proc Heal
( 38394, 0x00,   5, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Dot Heals
( 38857, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Spell Ground
( 39027, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Poison Shield
( 39372, 0x30,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Frozen Shadoweave
( 39437, 0x04,   5, 0x00001364, 0x000000C0, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Shadowflame Hellfire and RoF
( 39442, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001,   0,   0,   0), -- Aura of Wrath
( 39443, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Aura of Wrath
( 39530, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Focus
( 39958, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.7,   0,  40), -- Skyfire Swiftness
( 40407, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   6,   0,   0), -- Illidan Tank Shield
( 40438, 0x00,   6, 0x00008040, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Priest Tier 6 Trinket
( 40442, 0x00,   7, 0x00000014, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Druid Tier 6 Trinket
( 40444, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Black Temple Tank Trinket
( 40458, 0x00,   4, 0x02000000, 0x00000601, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Warrior Tier 6 Trinket
( 40463, 0x00,  11, 0x00000081, 0x00000010, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shaman Tier 6 Trinket
( 40470, 0x00,  10, 0xC0800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Paladin Tier 6 Trinket
( 40475, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   3,   0,   0), -- Black Temple Melee Trinket
( 40478, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Warlock Tier 6 Trinket
( 40482, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Mage Tier 6 Trinket
( 40485, 0x00,   9, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Hunter Tier 6 Trinket
( 40899, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Felfire Proc
( 41034, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Spell Absorption
( 41260, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Aviana's Purpose
( 41262, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Aviana's Will
( 41381, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000100,   0,   0,   0), -- Shell of Life
( 41393, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Riposte
( 41434, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   2,   0,  45), -- The Twin Blades of Azzinoth
( 41469, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   7,   0,   0), -- Seal of Command
( 41635, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 1)
( 41989, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.5,   0,   0), -- Fists of Fury
( 42083, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Fury of the Crashing Waves
( 42135, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  90), -- Lesser Rune of Warding
( 42136, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  90), -- Greater Rune of Warding
( 42368, 0x00,  10, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Merciless Libram of Justice
( 42370, 0x00,  11, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Merciless Totem of the Third WInd
( 42770, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Second Wind (Rank 2)
( 43019, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 8)
( 43020, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Mana Shield (Rank 9)
( 43338, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Shamanistic Focus
( 43443, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Spell Reflection
( 43726, 0x00,  10, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vengeful Libram of Justice
( 43728, 0x00,  11, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vengeful Totem of Third WInd
( 43737, 0x00,   7, 0x00000000, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Primal Instinct
( 43739, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Lunar Grace
( 43741, 0x00,  10, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Light's Grace
( 43745, 0x00,  10, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Crusader's Command
( 43748, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Elemental Strength
( 43750, 0x00,  11, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Energized
( 43819, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Lucidity
( 44394, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Incanter's Absorption (Rank 1)
( 44395, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Incanter's Absorption (Rank 2)
( 44396, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400,   0,   0,   0), -- Incanter's Absorption (Rank 3)
( 44401, 0x00,   3, 0x00200000, 0x00000000, 0x00000000, 0x00000000, 0x00000FFF,   0,   0,   0), -- Missile Barrage
( 44404, 0x00,   3, 0x20000021, 0x00009000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Missile Barrage (Rank 1)
( 44442, 0x00,   3, 0x00800000, 0x00000040, 0x00000000, 0x00000000, 0x00010000,   0,   0,   1), -- Firestarter (Rank 1)
( 44443, 0x00,   3, 0x00800000, 0x00000040, 0x00000000, 0x00000000, 0x00010000,   0,   0,   1), -- Firestarter (Rank 2)
( 44445, 0x00,   3, 0x00000013, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Hot Streak (Rank 1)
( 44446, 0x00,   3, 0x00000013, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Hot Streak (Rank 2)
( 44448, 0x00,   3, 0x00000013, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Hot Streak (Rank 3)
( 44449, 0x00,   3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Burnout (Rank 1)
( 44469, 0x00,   3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Burnout (Rank 2)
( 44470, 0x00,   3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Burnout (Rank 3)
( 44471, 0x00,   3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Burnout (Rank 4)
( 44472, 0x00,   3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Burnout (Rank 5)
( 44543, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00010000, 0x00000000,   0,   7,   0), -- Fingers of Frost (Rank 1)
( 44545, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00010000, 0x00000000,   0,  15,   0), -- Fingers of Frost (Rank 2)
( 44546, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brain Freeze (Rank 1)
( 44548, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brain Freeze (Rank 2)
( 44549, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brain Freeze (Rank 3)
( 44557, 0x00,   3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Enduring Winter (Rank 1)
( 44560, 0x00,   3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Enduring Winter (Rank 2)
( 44561, 0x00,   3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Enduring Winter (Rank 3)
( 44745, 0x00,   3, 0x00000000, 0x00000001, 0x00000000, 0x00004000, 0x00002000,   0,   0,   0), -- Shattered Barrier (Rank 1)
( 44835, 0x00,   7, 0x00000000, 0x00000080, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Maim Interrupt
( 45054, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  15), -- Augment Pain
( 45057, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Evasive Maneuvers
( 45234, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Will (Rank 1)
( 45243, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Will (Rank 2)
( 45244, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Will (Rank 3)
( 45354, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Item - Sunwell Dungeon Melee Trinket
( 45469, 0x00,  15, 0x00000010, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Death Strike
( 45481, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Sunwell Exalted Caster Neck
( 45482, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Sunwell Exalted Melee Neck
( 45483, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Sunwell Exalted Tank Neck
( 45484, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,  45), -- Sunwell Exalted Healer Neck
( 46025, 0x20,   6, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blackout (Rank 5)
( 46092, 0x00,  10, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brutal Libram of Justice
( 46098, 0x00,  11, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brutal Totem of Third WInd
( 46569, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Sunwell Exalted Caster Neck
( 46662, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  20), -- Deathfrost
( 46832, 0x00,   7, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Moonkin Starfire Bonus
( 46854, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Trauma (Rank 1)
( 46855, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Trauma (Rank 2)
( 46867, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Wrecking Crew (Rank 1)
( 46910, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 5.5,   0,   0), -- Furious Attacks (Rank 1)
( 46911, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 7.5,   0,   0), -- Furious Attacks (Rank 2)
( 46913, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bloodsurge (Rank 1)
( 46914, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bloodsurge (Rank 2)
( 46915, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bloodsurge (Rank 3)
( 46916, 0x00,   4, 0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Slam!
( 46951, 0x00,   4, 0x00000400, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sword and Board (Rank 1)
( 46952, 0x00,   0, 0x00000400, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sword and Board (Rank 2)
( 46953, 0x00,   0, 0x00000400, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sword and Board (Rank 3)
( 47195, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Eradication (Rank 1)
( 47196, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Eradication (Rank 2)
( 47197, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Eradication (Rank 3)
( 47201, 0x00,   5, 0x00000008, 0x00040000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Everlasting Affliction (1)
( 47202, 0x00,   5, 0x00000008, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Everlasting Affliction (2)
( 47203, 0x00,   5, 0x00000008, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Everlasting Affliction (3)
( 47204, 0x00,   5, 0x00000008, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Everlasting Affliction (4)
( 47205, 0x00,   5, 0x00000008, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Everlasting Affliction (5)
( 47245, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Molten Core (Rank 1)
( 47246, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Molten Core (Rank 2)
( 47247, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Molten Core (Rank 3)
( 47258, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Backdraft (Rank 1)
( 47259, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Backdraft (Rank 2)
( 47260, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Backdraft (Rank 3)
( 47263, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  20), -- Torture (Rank 1)
( 47264, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  20), -- Torture (Rank 2)
( 47265, 0x20,   5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  20), -- Torture (Rank 3)
( 47509, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Divine Aegis (Rank 1)
( 47511, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Divine Aegis (Rank 2)
( 47515, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Divine Aegis (Rank 3)
( 47516, 0x00,   6, 0x00001800, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Grace (Rank 1)
( 47517, 0x00,   6, 0x00001800, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Grace (Rank 2)
( 47535, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00004000, 0x00002000,   0,   0,  12), -- Rapture (Rank 1)
( 47536, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00004000, 0x00002000,   0,   0,  12), -- Rapture (Rank 2)
( 47537, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00004000, 0x00002000,   0,   0,  12), -- Rapture (Rank 3)
( 47569, 0x00,   6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Shadowform (Rank 1)
( 47570, 0x00,   6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Improved Shadowform (Rank 2)
( 47580, 0x00,   6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000,   0,   0,   0), -- Pain and Suffering (Rank 1)
( 47581, 0x00,   6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000,   0,   0,   0), -- Pain and Suffering (Rank 2)
( 47582, 0x00,   6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000,   0,   0,   0), -- Pain and Suffering (Rank 3)
( 48110, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 2)
( 48111, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 3)
( 48112, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 2)
( 48113, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x000A22A8, 0x00000000,   0,   0,   0), -- Prayer of Mending (Rank 3)
( 48159, 0x00,   6, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Touch (Rank 4)
( 48160, 0x00,   6, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Vampiric Touch (Rank 5)
( 48483, 0x00,   7, 0x00008800, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Infected Wounds (Rank 1)
( 48484, 0x00,   7, 0x00008800, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Infected Wounds (Rank 2)
( 48485, 0x00,   7, 0x00008800, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Infected Wounds (Rank 3)
( 48492, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0), -- King of the Jungle (Rank1)
( 48494, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0), -- King of the Jungle (Rank2)
( 48495, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0), -- King of the Jungle (Rank3)
( 48496, 0x00,   7, 0x00000060, 0x02000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Living Seed (Rank 1)
( 48499, 0x00,   7, 0x00000060, 0x02000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Living Seed (Rank 2)
( 48500, 0x00,   7, 0x00000060, 0x02000002, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Living Seed (Rank 3)
( 48506, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Earth and Moon (Rank 1)
( 48510, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Earth and Moon (Rank 2)
( 48511, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Earth and Moon (Rank 3)
( 48516, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  30), -- Eclipse (Rank 1)
( 48521, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  30), -- Eclipse (Rank 2)
( 48525, 0x00,   7, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  30), -- Eclipse (Rank 3)
( 48833, 0x00,   7, 0x00000000, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Primal Instinct
( 48835, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Justice
( 48837, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Elemental Tenacity
( 48951, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 5)
( 48952, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Holy Shield (Rank 6)
( 48988, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Bloody Vengeance (Rank 1)
( 49018, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sudden Doom (Rank 1)
( 49208, 0x00,  15, 0x00440000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Reaping (Rank 1)
( 49222, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Bone Shield
( 49280, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 10)
( 49281, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Lightning Shield (Rank 11)
( 49283, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield (Rank 4)
( 49284, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield (Rank 5)
( 49503, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Bloody Vengeance (Rank 2)
( 49504, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Bloody Vengeance (Rank 3)
( 49529, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sudden Doom (Rank 2)
( 49530, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sudden Doom (Rank 3)
( 49622, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Bonus Mana Regen
( 50781, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   6), -- Fate Rune of Primal Energy
( 50880, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50884, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50885, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50886, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50887, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 51123, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Killing Machine (Rank 1)
( 51127, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Killing Machine (Rank 2)
( 51128, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Killing Machine (Rank 3)
( 51129, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Killing Machine (Rank 4)
( 51130, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Killing Machine (Rank 5)
( 51346, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Venture Company Beatdown!
( 51349, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Venture Company Beatdown
( 51352, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Venture Company Beatdown!
( 51359, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Venture Company Beatdown
( 51414, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Venomous Breath Aura
( 51466, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Oath (Rank 1)
( 51470, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Oath (Rank 2)
( 51474, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Astral Shift (Rank 1)
( 51478, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Astral Shift (Rank 2)
( 51479, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Astral Shift (Rank 3)
( 51483, 0x01,  11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001,   0,   0,   0), -- Storm, Earth and Fire
( 51485, 0x01,  11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001,   0,   0,   0), -- Storm, Earth and Fire
( 51486, 0x01,  11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001,   0,   0,   0), -- Storm, Earth and Fire
( 51521, 0x00,  11, 0x00000000, 0x01000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Stormstrike
( 51522, 0x00,  11, 0x00000000, 0x01000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Stormstrike
( 51523, 0x08,  11, 0x00000000, 0x00000001, 0x00000000, 0x00011000, 0x00000000,   0,  50,   0), -- Earthen Power (Rank 1)
( 51524, 0x08,  11, 0x00000000, 0x00000001, 0x00000000, 0x00011000, 0x00000000,   0, 100,   0), -- Earthen Power (Rank 2)
( 51528, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 2.5,   0,   0), -- Maelstrom Weapon (Rank 1)
( 51529, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   5,   0,   0), -- Maelstrom Weapon (Rank 2)
( 51530, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 7.5,   0,   0), -- Maelstrom Weapon (Rank 3)
( 51531, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  10,   0,   0), -- Maelstrom Weapon (Rank 4)
( 51532, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 12.,   0,   0), -- Maelstrom Weapon (Rank 5)
( 51556, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Awakening (Rank 1)
( 51557, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Awakening (Rank 2)
( 51558, 0x00,  11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002,   0,   0,   0), -- Ancestral Awakening (Rank 3)
( 51562, 0x00,  11, 0x00000100, 0x00000000, 0x00000010, 0x00000000, 0x00000000,   0,   0,   0), -- Tidal Waves (Rank 1)
( 51563, 0x00,  11, 0x00000100, 0x00000000, 0x00000010, 0x00000000, 0x00000000,   0,   0,   0), -- Tidal Waves (Rank 2)
( 51564, 0x00,  11, 0x00000100, 0x00000000, 0x00000010, 0x00000000, 0x00000000,   0,   0,   0), -- Tidal Waves (Rank 3)
( 51565, 0x00,  11, 0x00000100, 0x00000000, 0x00000010, 0x00000000, 0x00000000,   0,   0,   0), -- Tidal Waves (Rank 4)
( 51566, 0x00,  11, 0x00000100, 0x00000000, 0x00000010, 0x00000000, 0x00000000,   0,   0,   0), -- Tidal Waves (Rank 5)
( 51625, 0x00,   8, 0x1000A000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Deadly Brew (Rank 1)
( 51626, 0x00,   8, 0x1000A000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Deadly Brew (Rank 2)
( 51627, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Turn the Tables (Rank 1)
( 51628, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Turn the Tables (Rank 2)
( 51629, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070,   0,   0,   0), -- Turn the Tables (Rank 3)
( 51634, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Attacks (Rank 1)
( 51635, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Attacks (Rank 2)
( 51636, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Focused Attacks (Rank 3)
( 51664, 0x00,   8, 0x00020000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Cut to the Chase (Rank 1)
( 51665, 0x00,   8, 0x00020000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Cut to the Chase (Rank 2)
( 51667, 0x00,   8, 0x00020000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Cut to the Chase (Rank 3)
( 51668, 0x00,   8, 0x00020000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Cut to the Chase (Rank 4)
( 51669, 0x00,   8, 0x00020000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Cut to the Chase (Rank 5)
( 51672, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   1), -- Unfair Advantage (Rank 1)
( 51674, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   1), -- Unfair Advantage (Rank 2)
( 51679, 0x00,   8, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Throwing Specialization (Rank 2)
( 51692, 0x00,   8, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Waylay (Rank 1)
( 51696, 0x00,   8, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Waylay (Rank 2)
( 51698, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   1), -- Honor Among Thieves (Rank 1)
( 51700, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   1), -- Honor Among Thieves (Rank 2)
( 51701, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   1), -- Honor Among Thieves (Rank 3)
( 51915, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x01000000, 0x00000000,   0, 100, 600), -- Undying Resolve
( 51940, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 1)
( 51989, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 2)
( 52004, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 3)
( 52005, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 4)
( 52007, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 5)
( 52008, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,  20,   0), -- Earthliving Weapon (Passive) (Rank 6)
( 52020, 0x00,   7, 0x00008000, 0x00100000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Snap and Snarl
( 52127, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 1)
( 52129, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 2)
( 52131, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 3)
( 52134, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 4)
( 52136, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 5)
( 52138, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 6)
( 52420, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Deflection
( 52423, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Retaliation
( 52795, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Borrowed Time (Rank 1)
( 52797, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Borrowed Time (Rank 2)
( 52798, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Borrowed Time (Rank 3)
( 52799, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Borrowed Time (Rank 4)
( 52800, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Borrowed Time (Rank 5)
( 52898, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Spell Damping
( 53137, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Abomination's Might (Rank 1)
( 53138, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Abomination's Might (Rank 2)
( 53215, 0x00,   9, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Wild Quiver (Rank 1)
( 53216, 0x00,   9, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Wild Quiver (Rank 2)
( 53217, 0x00,   9, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Wild Quiver (Rank 3)
( 53221, 0x00,   9, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Steady Shot (Rank 1)
( 53222, 0x00,   9, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Steady Shot (Rank 2)
( 53224, 0x00,   9, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Improved Steady Shot (Rank 3)
( 53228, 0x00,   9, 0x00000020, 0x01000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Rapid Recuperation (Rank 1)
( 53232, 0x00,   9, 0x00000020, 0x01000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Rapid Recuperation (Rank 2)
( 53256, 0x00,   9, 0x00000800, 0x00800001, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Cobra Strikes (Rank 1)
( 53259, 0x00,   9, 0x00000800, 0x00800001, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Cobra Strikes (Rank 2)
( 53260, 0x00,   9, 0x00000800, 0x00800001, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Cobra Strikes (Rank 3)
( 53290, 0x00,   9, 0x00000800, 0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Hunting Party (Rank 1)
( 53291, 0x00,   9, 0x00000800, 0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Hunting Party (Rank 2)
( 53292, 0x00,   9, 0x00000800, 0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Hunting Party (Rank 3)
( 53375, 0x00,  10, 0x00000000, 0x00002000, 0x00000000, 0x00000400, 0x00000000,   0,   0,   6), -- Sanctified Wrath (Rank 1)
( 53376, 0x00,  10, 0x00000000, 0x00002000, 0x00000000, 0x00000400, 0x00000000,   0,   0,   6), -- Sanctified Wrath (Rank 2)
( 53380, 0x00,  10, 0x00800000, 0x00020000, 0x00000000, 0x00000000, 0x00040002,   0,   0,   0), -- Righteous Vengeance (Rank 1)
( 53381, 0x00,  10, 0x00800000, 0x00020000, 0x00000000, 0x00000000, 0x00040002,   0,   0,   0), -- Righteous Vengeance (Rank 2)
( 53382, 0x00,  10, 0x00800000, 0x00020000, 0x00000000, 0x00000000, 0x00040002,   0,   0,   0), -- Righteous Vengeance (Rank 3)
( 53397, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Invigoration (Rank 1)
( 53489, 0x00,  10, 0x00800000, 0x00028000, 0x00000000, 0x00000000, 0x00040002,   0,   0,   0), -- The Art of War (Rank 1)
( 59578, 0x00,  10, 0x00800000, 0x00028000, 0x00000000, 0x00000000, 0x00040002,   0,   0,   0), -- The Art of War (Rank 2)
( 53501, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Sheath of Light (Rank 1)
( 53502, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Sheath of Light (Rank 2)
( 53503, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Sheath of Light (Rank 3)
( 53551, 0x00,  10, 0x00001000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sacred Cleansing (Rank 1)
( 53552, 0x00,  10, 0x00001000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sacred Cleansing (Rank 2)
( 53553, 0x00,  10, 0x00001000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sacred Cleansing (Rank 3)
( 53569, 0x00,  10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Infusion of Light (Rank 1)
( 53576, 0x00,  10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Infusion of Light (Rank 2)
( 53601, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Sacred Shield (Rank 1)
( 53646, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Demonic Pact (Rank 1)
( 53671, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Pure (Rank 1)
( 53672, 0x00,  10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Infusion of Light
( 53673, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Pure (Rank 2)
( 53709, 0x02,  10, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shield of the templar
( 53710, 0x02,  10, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shield of the templar
( 53711, 0x02,  10, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Shield of the templar
( 53754, 0x00,   5, 0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x00006000,   0,   0,   0), -- Improved Fear (Rank 1)
( 53759, 0x00,   5, 0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x00006000,   0,   0,   0), -- Improved Fear (Rank 2)
( 54149, 0x00,  10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Infusion of Light (Rank 2)
( 54151, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Pure (Rank 3)
( 54154, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Pure (Rank 4)
( 54155, 0x00,  10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,   0,   0,   0), -- Judgements of the Pure (Rank 5)
( 54278, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Empowered Imp
( 54486, 0x00,   0, 0x20000021, 0x00009000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Missile Barrage (Rank 2)
( 54488, 0x00,   0, 0x20000021, 0x00009000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Missile Barrage (Rank 3)
( 54489, 0x00,   0, 0x20000021, 0x00009000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Missile Barrage (Rank 4)
( 54490, 0x00,   0, 0x20000021, 0x00009000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Missile Barrage (Rank 5)
( 54695, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Item - Death Knight's Anguish Base
( 54707, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Sonic Awareness (DND)
( 54738, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Star of Light
( 54747, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Burning Determination (Rank 1)
( 54749, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Burning Determination (Rank 2)
( 54754, 0x00,   7, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Rejuvenation
( 54787, 0x00,   3, 0x00000000, 0x00000001, 0x00000000, 0x00004000, 0x00002000,   0,   0,   0), -- Shattered Barrier (Rank 2)
( 54808, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  60), -- Sonic Shield
( 54838, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Purified Spirit
( 54841, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   3), -- Thunder Capacitor
( 54936, 0x00,  10, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Flash of Light
( 54937, 0x00,  10, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Holy Light
( 54939, 0x00,  10, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Divinity
( 55198, 0x00,  11, 0x000001C0, 0x00000000, 0x00000000, 0x00004000, 0x00000002,   0,   0,   0), -- Tidal Force
( 55380, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Skyflare Swiftness
( 55381, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,  15), -- Mana Restore
( 55440, 0x00,  11, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Healing Wave
( 55610, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00001000, 0x00000000,   0,   0,   0), -- Improved Icy Talons
( 55640, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Lightweave Embroidery
( 55677, 0x00,   6, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Dispel Magic
( 55680, 0x00,   6, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Prayer of Healing
( 55689, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Glyph of Shadow
( 55747, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Argent Fury
( 55768, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Darkglow Embroidery
( 55776, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Swordguard Embroidery
( 56218, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Corruption
( 56249, 0x00,   5, 0x00000000, 0x00000000, 0x00000400, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Felhunter
( 56355, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040,   0,   0,   0), -- Titanium Shield Spike
( 56364, 0x00,   3, 0x00000000, 0x01000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Remove Curse
( 56372, 0x00,   3, 0x00000000, 0x00000080, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Glyph of Ice Block
( 56374, 0x00,   3, 0x00000000, 0x00004000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0), -- Glyph of Icy Veins
( 56451, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Earth Shield
( 56611, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Wrecking Crew (Rank 2)
( 56612, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Wrecking Crew (Rank 3)
( 56613, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Wrecking Crew (Rank 4)
( 56614, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Wrecking Crew (Rank 5)
( 56816, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000030,   0,   0,   0), -- Rune Strike
( 56821, 0x00,   8, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Glyph of Sinister Strike
( 56834, 0x00,  15, 0x00440000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Reaping (Rank 2)
( 56835, 0x00,  15, 0x00440000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Reaping (Rank 3)
( 57345, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Darkmoon Card: Greatness
( 57352, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00051154, 0x00000000,   0,   0,  45), -- Darkmoon Card: Death
( 57878, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   0), -- Natural Reaction (Rank 1)
( 57880, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   0), -- Natural Reaction (Rank 2)
( 57881, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   0), -- Natural Reaction (Rank 3)
( 57907, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Increased Spirit
( 57960, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Water Shield (Rank 9)
( 58357, 0x00,   4, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Glyph of Heroic Strike
( 58364, 0x00,   4, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Revenge
( 58372, 0x00,   4, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Hamstring
( 58386, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Glyph of Overpower
( 58426, 0x00,   8, 0x00400000, 0x00000000, 0x00000000, 0x00000400, 0x00006001,   0,   0,   0), -- Overkill
( 58442, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  15), -- Airy Pale Ale
( 58444, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   5), -- Worg Tooth Oatmeal Stout
( 58626, 0x00,  15, 0x02000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Death Grip
( 58631, 0x00,  15, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Icy Touch
( 58642, 0x00,  15, 0x00000000, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Scourge Strike
( 58644, 0x00,  15, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Frost Strike
( 58647, 0x00,  15, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Frost Strike
( 58676, 0x00,  15, 0x00000000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Vampiric Blood
( 58677, 0x00,  15, 0x00002000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Death's Embrace
( 58872, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Damage Shield (Rank 1)
( 58874, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Damage Shield (Rank 2)
( 58901, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Tears of Anguish
( 59088, 0x00,   4, 0x00000000, 0x00000002, 0x00000000, 0x00000400, 0x00000000,   0,   0,   0), -- Improved Spell Reflection (Rank 1)
( 59089, 0x00,   4, 0x00000000, 0x00000002, 0x00000000, 0x00000400, 0x00000000,   0,   0,   0), -- Improved Spell Reflection (Rank 2)
( 59176, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Spell Damping
( 59327, 0x00,  15, 0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Rune Tap
( 59345, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Chagrin
( 59630, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Black Magic
( 59725, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Spell Reflection
( 60061, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Flow of Time
( 60063, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Now is the Time!
( 60132, 0x00,  15, 0x00000000, 0x08020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Oblit/Scourge Strike Runic Power Up
( 60170, 0x00,   5, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Corruption Triggers Crit
( 60172, 0x00,   5, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0x00010000,   0,   0,   0), -- Life Tap Bonus Spirit
( 60176, 0x00,   4, 0x00000020, 0x00000010, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bleed Cost Reduction
( 60221, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Essence of Gossamer
( 60301, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Meteorite Whetstone
( 60306, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Vestige of Haldor
( 60317, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Signet of Edward the Odd
( 60436, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Grim Toll
( 60442, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Bandit's Insignia
( 60473, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Forge Ember
( 60482, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Pendulum of Telluric Currents
( 60487, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  15), -- Extract of Necromatic Power
( 60490, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Embrace of the Spider
( 60493, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Dying Curse
( 60519, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Spark of Life
( 60529, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Forethought Talisman
( 60537, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Soul of the Dead
( 60564, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Savage Gladiator's Totem of Survival
( 60571, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Hateful Gladiator's Totem of Survival
( 60572, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Deadly Gladiator's Totem of Survival
( 60573, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 4 Gladiator's Totem of Survival
( 60574, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 5 Gladiator's Totem of Survival
( 60575, 0x00,  11, 0x90100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 6 Gladiator's Totem of Survival
( 60617, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,   0), -- Parry
( 60710, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Savage Gladiator's Idol of Steadfastness
( 60717, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0, 100,   0), -- Hateful Gladiator's Idol of Steadfastness
( 60719, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Deadly Gladiator's Idol of Steadfastness
( 60722, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 4 Gladiator's Idol of Steadfastness
( 60724, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 5 Gladiator's Idol of Steadfastness
( 60726, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- LK Arena 6 Gladiator's Idol of Steadfastness
( 60770, 0x00,  11, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Totem of the Elemental Plane
( 60818, 0x00,  10, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Libram of Reciprocation
( 60826, 0x00,  15, 0x01400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Sigil of Haunted Dreams
( 61188, 0x00,   5, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chaotic Mind
( 61324, 0x00,  10, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Justice
( 61345, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Nature's Grace
( 61346, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Nature's Grace
( 61356, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  90), -- Invigorating Earthsiege Diamond Passive
( 61618, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Tentacles
( 61848, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010,   0,   0,   0), -- Aspect of the Dragonhawk
( 62147, 0x00,  15, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Touch Defense Increase
( 62459, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chains of Ice Frost Rune Refresh (Rank 3)
( 63108, 0x00,   5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Siphon Life
( 63158, 0x00,   5, 0x00000001, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Decimation
( 63156, 0x00,   5, 0x00000001, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Decimation
( 64343, 0x00,   3, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Impact
( 64976, 0x00,   4, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Juggernaut
( 64914, 0x00,   8, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Rogue T8 2P Bonus
( 64938, 0x00,   4, 0x00200040, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Item - Warrior T8 Melee 2P Bonus
( 64952, 0x00,   7, 0x00000000, 0x00000440, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Druid T8 Feral Relic
( 64964, 0x00,  15, 0x00000000, 0x20000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Death Knight T8 Tank Relic
( 65002, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Bonus Mana Regen
( 65005, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Alacrity of the Elements
( 64999, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   5,   0,   0), -- Meteoric Inspiration
( 65007, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   5,   0,   0), -- Eye of the Broodmother
( 65013, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Pyrite Infusion
( 65020, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Mjolnir Runestone
( 65025, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Dark Matter
( 46949, 0x00,   4, 0x00000000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Safeguard
( 46945, 0x00,   4, 0x00000000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Safeguard
( 64415, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Val'anyr Hammer of Ancient Kings - Equip Effect
( 60066, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Rage of the Unraveller
( 62115, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Strength of the Titans
( 62114, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Flow of Knowledge
( 62600, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Savage Defense
( 63245, 0x00,   5, 0x00000100, 0x00800000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Pyroclasm
( 18096, 0x00,   5, 0x00000100, 0x00800000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Pyroclasm
( 18073, 0x00,   5, 0x00000100, 0x00800000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Pyroclasm
( 63280, 0x00,  11, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Totem of Wrath
( 63310, 0x00,   5, 0x00000000, 0x00010000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Glyph of Shadowflame
( 63320, 0x00,   5, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Life Tap
( 63335, 0x00,  15, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Howling Blast
( 63730, 0x00,   6, 0x00000800, 0x00000004, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Serendipity
( 63733, 0x00,   6, 0x00000800, 0x00000004, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Serendipity
( 63737, 0x00,   6, 0x00000800, 0x00000004, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Serendipity
( 64127, 0x00,   6, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Body and Soul
( 64129, 0x00,   6, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Body and Soul
( 64568, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   3), -- Blood Reserve
( 64571, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  30), -- Blood Draining
( 64440, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020,   0,   0,  20), -- Blade Warding
( 64714, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Flame of the Heavens
( 64738, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Show of Faith
( 64742, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  45), -- Pandora's Plea
( 64752, 0x00,   7, 0x00800000, 0x10000100, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Druid T8 Feral 2P Bonus
( 64786, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  15), -- Comet's Trail
( 64792, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,  45), -- Blood of the Old God
( 64824, 0x00,   7, 0x00200000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Druid T8 Balance 4P Bonus
( 64928, 0x00,  11, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Item - Shaman T8 Elemental
( 64860, 0x00,   9, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Hunter T8 4P Bonus
( 64867, 0x00,   3, 0x20000021, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Mage T8 2P Bonus
( 64882, 0x00,  10, 0x00000000, 0x00100000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T8 Protection 4P Bonus
( 64890, 0x00,  10, 0x00000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Item - Paladin T8 Holy 2P Bonus
( 64908, 0x00,   6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Priest T8 Shadow 4P Bonus
( 64912, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Priest T8 Healer 4P Bonus
( 57470, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Renewed Hope
( 57472, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Renewed Hope
( 35100, 0x00,   9, 0x00001000, 0x00000000, 0x00000001, 0x00000000, 0x00000000,   0,   0,   0), -- Concussive Barrage
( 35102, 0x00,   9, 0x00001000, 0x00000000, 0x00000001, 0x00000000, 0x00000000,   0,   0,   0), -- Concussive Barrage
( 18119, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Aftermath
( 18120, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Aftermath
( 13165, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 14318, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 14319, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 14320, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 14321, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 14322, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 25296, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 27044, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Hawk
( 61846, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Dragonhawk
( 61847, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000000,   0,   0,   0), -- Aspect of the Dragonhawk
( 49223, 0x00,  15, 0x00000011, 0x08020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Dirge
( 49599, 0x00,  15, 0x00000011, 0x08020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Dirge
( 49188, 0x00,  15, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Rime
( 56822, 0x00,  15, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Rime
( 59057, 0x00,  15, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Rime
( 55666, 0x00,  15, 0x00000001, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Desecration
( 55667, 0x00,  15, 0x00000001, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Desecration
( 55668, 0x00,  15, 0x00000001, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Desecration
( 55669, 0x00,  15, 0x00000001, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Desecration
( 55670, 0x00,  15, 0x00000001, 0x08000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Desecration
( 58616, 0x00,  15, 0x01000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Heart Strike
( 16164, 0x00,  11, 0x901000C3, 0x00001000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Focus
( 49149, 0x00,  15, 0x00000006, 0x00020002, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chill of the Grave
( 50115, 0x00,  15, 0x00000006, 0x00020002, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chill of the Grave
( 49217, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49654, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49655, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49137, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Endless Winter
( 49657, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Endless Winter
( 58620, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Glyph of Chains of Ice
( 56342, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0), -- Lock and Load
( 56343, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0), -- Lock and Load
( 56344, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0), -- Lock and Load
( 48539, 0x00,   7, 0x00000010, 0x04000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Revitalize
( 48544, 0x00,   7, 0x00000010, 0x04000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Revitalize
( 48545, 0x00,   7, 0x00000010, 0x04000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Revitalize
( 53234, 0x00,   9, 0x00020000, 0x00000001, 0x00000001, 0x00000000, 0x00000002,   0,   0,   0), -- Piercing Shots (Rank 1)
( 53237, 0x00,   9, 0x00020000, 0x00000001, 0x00000001, 0x00000000, 0x00000002,   0,   0,   0), -- Piercing Shots (Rank 2)
( 53238, 0x00,   9, 0x00020000, 0x00000001, 0x00000001, 0x00000000, 0x00000002,   0,   0,   0), -- Piercing Shots (Rank 3)
( 56636, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Taste for Blood (Rank 1)
( 56637, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Taste for Blood (Rank 2)
( 56638, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Taste for Blood (Rank 3)
( 56375, 0x00,   3, 0x01000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Glyphs of Polymorph
( 54639, 0x00,  15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 54638, 0x00,  15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 54637, 0x00,  15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 61433, 0x00,  15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 61434, 0x00,  15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 49467, 0x00,  15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Death Rune Mastery
( 50033, 0x00,  15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Death Rune Mastery
( 50034, 0x00,  15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Death Rune Mastery
( 63373, 0x00,  11, 0x80000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Frozen Power (Rank 1)
( 63374, 0x00,  11, 0x80000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Frozen Power (Rank 2)
( 54821, 0x00,   7, 0x00001000, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Glyph of Rake
( 54815, 0x00,   7, 0x00008000, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Glyph of Shred
( 54845, 0x00,   7, 0x00000004, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Glyph of Starfire
( 56800, 0x00,   8, 0x00800004, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Glyph of Backstab
( 54832, 0x00,   7, 0x00000000, 0x00001000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   0); -- Glyph of Innervate

-- --------
-- ENCHANT PROC
-- --------
TRUNCATE TABLE `spell_enchant_proc_data`;
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES
 -- Frostbrand Weapon
(2, 0, 8.8,0),
(12, 0, 8.8,0),
(524, 0, 8.8,0),
(1667, 0, 8.8,0),
(1668, 0, 8.8,0),
(2635, 0, 8.8,0),
(3782, 0, 8.8,0),
(3783, 0, 8.8,0),
(3784, 0, 8.8,0),
 -- Wound Poison
(703, 0, 21.43,0),
(704, 0, 21.43,0),
(705, 0, 21.43,0),
(706, 0, 21.43,0),
(2644, 0, 21.43,0),
(3772, 0, 21.43,0),
(3773, 0, 21.43,0),
 -- Instant Poison
(323, 0, 8.53,0),
(324, 0, 8.53,0),
(325, 0, 8.53,0),
(623, 0, 8.53,0),
(624, 0, 8.53,0),
(625, 0, 8.53,0),
(2641, 0, 8.53,0),
(3768, 0, 8.53,0),
(3769, 0, 8.53,0),
 -- Fiery Weapon
(803, 0, 6.0,0),
 -- Demonslaying
(912, 0, 6.0,0),
 -- Icy Weapon
(1894, 0, 3.0,0),
 -- Lifestealing
(1898, 0, 6.0,0),
 -- Unholy Weapon
(1899, 0, 1.0,0),
 -- Crusader
(1900, 0, 1.0,0),
 -- Mongoose
(2673, 0, 1.0,0),
 -- Battlemaster
(2675, 0, 1.0,0),
 -- Executioner
(3225, 0, 1.0,0),
 -- Icebreaker Weapon
(3239, 0, 3.0,0),
 -- Lifeward
(3241, 0, 3.0,0),
 -- Giantslaying
(3251, 0, 3.0,0),
 -- Deathfrost
(3273, 0, 3.0,0),
 -- Rune of the Fallen Crusader
(3368, 0, 1.0,0),
 -- Rune of Cinderglacier
(3369, 0, 1.0,0),
 -- Berserking
(3789, 0, 1.0,0),
 -- Blade Ward
(3869, 0, 1.0,0);

-- --------
-- SPELL BONUS DATA
-- --------
TRUNCATE TABLE `spell_bonus_data`;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(49941, -1, -1, 0.04, -1, 'Death Knight - Blood Boil'),
(48721, -1, -1, 0.04, -1, 'Death Knight - Blood Boil'),
(55078, -1, -1, -1, 0.055, 'Death Knight - Blood Plague'),
(50444, -1, -1, 0.105, -1, 'Death Knight - Corpse Explosion Triggered'),
(52212, -1, -1, 0.0475, -1, 'Death Knight - Death and Decay'),
(47632, -1, -1, 0.15, -1, 'Death Knight - Death Coil'),
(47633, -1, -1, 0.15, -1, 'Death Knight - Death Coil Heal'),
(55095, -1, -1, -1, 0.055, 'Death Knight - Frost Fever'),
(58621, -1, -1, 0.08, -1, 'Death Knight - Glyph of Chains of Ice'),
(49184, -1, -1, 0.1, -1, 'Death Knight - Howling Blast'),
(45477, -1, -1, 0.1, -1, 'Death Knight - Icy Touch'),
(56903, 0, 0, 0, 0, 'Death Knight - Lichflame'),
(50842, -1, -1, 0.04, -1, 'Death Knight - Pestilence'),
(50401, 0, 0, 0, 0, 'Death Knight - Razor Frost'),
(47476, -1, -1, 0.06, -1, 'Death Knight - Strangulate'),
(50536, -1, -1, 0.013, -1, 'Death Knight - Unholy Blight (Rank1)'),
(339, -1, 0.1, -1, -1, 'Druid - Entangling Roots'),
(60089, -1, -1, 0.05, -1, 'Druid - Faerie Fire (feral)'),
(5185, 1.611, -1, -1, -1, 'Druid - Healing Touch'),
(42231, 0.12898, -1, -1, -1, 'Druid - Hurricane Triggered'),
(5570, -1, 0.2, -1, -1, 'Druid - Insect Swarm'),
(33745, -1, -1, -1, 0.01, 'Druid - Lacerate($AP*0.05 / number of ticks)'),
(33778, 0.516, 0, 0, 0, 'Druid - Lifebloom final heal'),
(33763, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 1)'),
(48450, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 2)'),
(48451, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 3)'),
(48628, -1, -1, -1, 0.15, 'Druid - Lock Jaw'),
(8921, 0.1515, 0.13, -1, -1, 'Druid - Moonfire'),
(50464, 0.67305, -1, -1, -1, 'Druid - Nourish'),
(1822, -1, -1, 0.01, 0.06, 'Druid - Rake ($AP*0.18 / number of ticks)'),
(8936, 0.539, 0.188, -1, -1, 'Druid - Regrowth'),
(774, -1, 0.37604, -1, -1, 'Druid - Rejuvenation'),
(50294, 0.0119, -1, -1, -1, 'Druid - Starfall AOE rank 1'),
(53188, 0.0119, -1, -1, -1, 'Druid - Starfall AOE rank 2'),
(53189, 0.0119, -1, -1, -1, 'Druid - Starfall AOE rank 3'),
(53190, 0.0119, -1, -1, -1, 'Druid - Starfall AOE rank 4'),
(50288, 0.0458, -1, -1, -1, 'Druid - Starfall rank 1'),
(53191, 0.0458, -1, -1, -1, 'Druid - Starfall rank 2'),
(53194, 0.0458, -1, -1, -1, 'Druid - Starfall rank 3'),
(53195, 0.0458, -1, -1, -1, 'Druid - Starfall rank 4'),
(2912, 1, -1, -1, -1, 'Druid - Starfire'),
(18562, 0, 0, 0, 0, 'Druid - Swiftmend'),
(779, -1, -1, 0.063, -1, 'Druid - Swipe (Bear)'),
(44203, 0.538, -1, -1, -1, 'Druid - Tranquility Triggered'),
(61391, 0.193, -1, -1, -1, 'Druid - Typhoon'),
(48438, -1, 0.11505, -1, -1, 'Druid - Wild Growth'),
(5176, 0.5714, -1, -1, -1, 'Druid - Wrath'),
(3044, -1, -1, 0.15, -1, 'Hunter - Arcane Shot'),
(3674, -1, -1, -1, 0.02, 'Hunter - Black Arrow($RAP*0.1 / number of ticks)'),
(19306, -1, -1, 0.2, -1, 'Hunter - Counterattack'),
(13812, -1, -1, 0.1, -1, 'Hunter - Explosive Trap Effect'),
(13797, -1, -1, -1, 0.02, 'Hunter - Immolation Trap($RAP*0.1 / number of ticks)'),
(1495, -1, -1, 0.2, -1, 'Hunter - Mongoose Bite'),
(1978, -1, -1, -1, 0.04, 'Hunter - Serpent Sting($RAP*0.2 / number of ticks)'),
(56641, -1, -1, 0.1, -1, 'Hunter - Steady Shot'),
(42243, -1, -1, 0.07, -1, 'Hunter - Volley'),
(53352, -1, -1, 0.14, -1, 'Hunter - Explosive Shot (triggered)'),
(55039, 0, 0, 0, 0, 'Item - Gnomish Lightning Generator'),
(40293, 0, 0, 0, 0, 'Item - Siphon Essence'),
(44425, 0.7143, -1, -1, -1, 'Mage - Arcane Barrage'),
(30451, 0.7143, -1, -1, -1, 'Mage - Arcane Blast'),
(1449, 0.2128, -1, -1, -1, 'Mage - Arcane Explosion'),
(7268, 0.2857, -1, -1, -1, 'Mage - Arcane Missiles Triggered Spell Rank 1'),
(7269, 0.2857, -1, -1, -1, 'Mage - Arcane Missiles Triggered Spell Rank 2'),
(11113, 0.1936, -1, -1, -1, 'Mage - Blast Wave'),
(42208, 0.1437, -1, -1, -1, 'Mage - Blizzard Triggered Spell'),
(120, 0.214, -1, -1, -1, 'Mage - Cone of Cold'),
(31661, 0.1936, -1, -1, -1, 'Mage - Dragons Breath'),
(133, 1, -1, -1, -1, 'Mage - Fire Ball'),
(2136, 0.4286, -1, -1, -1, 'Mage - Fire Blast'),
(543, 0.1, -1, -1, -1, 'Mage - Fire Ward'),
(2120, 0.2357, 0.122, -1, -1, 'Mage - Flamestrike'),
(116, 0.8143, -1, -1, -1, 'Mage - Frost Bolt'),
(122, 0.193, -1, -1, -1, 'Mage - Frost Nova'),
(6143, 0.1, -1, -1, -1, 'Mage - Frost Ward'),
(44614, 0.8571, -1, -1, -1, 'Mage - Frostfire Bolt'),
(11426, 0.8053, -1, -1, -1, 'Mage - Ice Barrier'),
(30455, 0.1429, -1, -1, -1, 'Mage - Ice Lance'),
(44457, 0.4, 0.2, -1, -1, 'Mage - Living Bomb'),
(1463, 0.8053, -1, -1, -1, 'Mage - Mana Shield'),
(34913, 0, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 1'),
(11366, 1.15, 0.05, -1, -1, 'Mage - Pyroblast'),
(2948, 0.4286, -1, -1, -1, 'Mage - Scorch'),
(31935, 0.07, -1, 0.07, -1, 'Paladin - Avenger Shield'),
(53742, -1, 0.0176, -1, 0.03, 'Paladin - Blood Corruption'),
(26573, -1, 0.04, -1, 0.04, 'Paladin - Consecration'),
(879, 0.15, -1, 0.15, -1, 'Paladin - Exorcism'),
(19750, 1, -1, -1, -1, 'Paladin - Flash of Light'),
(53595, 0, 0, 0, 0, 'Paladin - Hammer of the Righteous'),
(24275, 0.15, -1, 0.15, -1, 'Paladin - Hammer of Wrath'),
(62124, 0.085, -1, -1, -1, 'Paladin - Hand of Reckoning'),
(635, 1.66, -1, -1, -1, 'Paladin - Holy Light'),
(20925, 0.09, -1, 0.056, -1, 'Paladin - Holy Shield'),
(25914, 0.81, -1, -1, -1, 'Paladin - Holy Shock Triggered Heal Rank 1'),
(25912, 0.4286, -1, -1, -1, 'Paladin - Holy Shock Triggered Hurt Rank 1'),
(31803, -1, 0.0176, -1, 0.03, 'Paladin - Holy Vengeance'),
(2812, 0.07, -1, 0.07, -1, 'Paladin - Holy Wrath'),
(31898, 0.25, -1, 0.16, -1, 'Paladin - Judgement of Blood Enemy'),
(32220, 0.0833, -1, 0.0533, -1, 'Paladin - Judgement of Blood Self'),
(20467, 0.25, -1, 0.16, -1, 'Paladin - Judgement of Command'),
(53733, 0.22, -1, 0.14, -1, 'Paladin - Judgement of Corruption'),
(20267, 0.1, -1, 0.1, -1, 'Paladin - Judgement of Light Proc'),
-- (20187, 0.4, -1, 0.25, -1, 'Paladin - Judgement of Righteousness'),
(20187, 0, 0, 0, 0, 'Paladin - Judgement of Righteousness'),
(53726, 0.25, -1, 0.16, -1, 'Paladin - Judgement of the Martyr Enemy'),
(53725, 0.0833, -1, 0.0533, -1, 'Paladin - Judgement of the Martyr Self'),
(31804, 0.22, -1, 0.14, -1, 'Paladin - Judgement of Vengeance'),
-- (54158, 0.25, -1, 0.16, -1, 'Paladin - Judgement (Seal of Light, Seal of Wisdom, Seal of Justice)'),
(54158, 0, 0, 0, 0, 'Paladin - Judgement (Seal of Light, Seal of Wisdom, Seal of Justice)'),
(58597, 0.75, -1, -1, -1, 'Paladin - Sacred Shield'),
(53601, 0.75, -1, -1, -1, 'Paladin - Sacred Shield'),
(31893, 0, 0, 0, 0, 'Paladin - Seal of Blood Proc Enemy'),
(32221, 0, 0, 0, 0, 'Paladin - Seal of Blood Proc Self'),
(20424, 0, 0, 0, 0, 'Paladin - Seal of Command Proc'),
(20167, 0.15, -1, 0.15, -1, 'Paladin - Seal of Light Proc'),
(25742, 0.07, -1, 0.039, -1, 'Paladin - Seal of Righteousness Dummy Proc'),
(53719, 0, 0, 0, 0, 'Paladin - Seal of the Martyr Proc Enemy'),
(53718, 0, 0, 0, 0, 'Paladin - Seal of the Martyr Proc Self'),
(50256, -1, -1, 0.08, -1, 'Pet Skills - Bear (Swipe)'),
(32546, 0.8068, -1, -1, -1, 'Priest - Binding Heal'),
(27813, 0, 0, 0, 0, 'Priest - Blessed Recovery Rank 1'),
(34861, 0.402, -1, -1, -1, 'Priest - Circle of Healing'),
(19236, 0.8068, -1, -1, -1, 'Priest - Desperate Prayer'),
(2944, -1, 0.1849, -1, -1, 'Priest - Devouring Plague'),
(2061, 0.8068, -1, -1, -1, 'Priest - Flash Heal'),
(2060, 1.6135, -1, -1, -1, 'Priest - Greater Heal'),
(14914, 0.5711, 0.024, -1, -1, 'Priest - Holy Fire'),
(15237, 0.1606, -1, -1, -1, 'Priest - Holy Nova Damage'),
(23455, 0.3035, -1, -1, -1, 'Priest - Holy Nova Heal Rank 1'),
(8129, 0, 0, 0, 0, 'Priest - Mana Burn'),
(8092, 0.428, -1, -1, -1, 'Priest - Mind Blast'),
(15407, 0.257, -1, -1, -1, 'Priest - Mind Flay'),
(49821, 0.2861, -1, -1, -1, 'Priest - Mind Sear Trigger Rank 1'),
(47750, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 1)'),
(52983, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 2)'),
(52954, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 3)'),
(58985, 0.5362, -1, -1, -1, 'Priest - Penance Heal (Rank 4)'),
(47666, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 1)'),
(52998, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 2)'),
(52999, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 3)'),
(53000, 0.229, -1, -1, -1, 'Priest - Penance Hurt (Rank 4)'),
(17, 0.8068, -1, -1, -1, 'Priest - Power Word: Shield'),
(596, 0.8068, -1, -1, -1, 'Priest - Prayer of Healing'),
(33110, 0.8068, -1, -1, -1, 'Priest - Prayer of Mending Heal Proc'),
(33619, 0, 0, 0, 0, 'Priest - Reflective Shield'),
(139, -1, 0.376, -1, -1, 'Priest - Renew'),
(32379, 0.4296, -1, -1, -1, 'Priest - Shadow Word: Death'),
(589, -1, 0.1829, -1, -1, 'Priest - Shadow Word: Pain'),
(34433, 0.65, -1, -1, -1, 'Priest - Shadowfiend'),
(585, 0.714, -1, -1, -1, 'Priest - Smite'),
(34914, -1, 0.4, -1, -1, 'Priest - Vampiric Touch'),
(7001, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 1'),
(2818, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 1($AP*0.12 / number of ticks)'),
(2819, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 2($AP*0.12 / number of ticks)'),
(11353, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 3($AP*0.12 / number of ticks)'),
(11354, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 4($AP*0.12 / number of ticks)'),
(25349, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 5($AP*0.12 / number of ticks)'),
(26968, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 6($AP*0.12 / number of ticks)'),
(27187, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 7($AP*0.12 / number of ticks)'),
(57969, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 8($AP*0.12 / number of ticks)'),
(57970, -1, -1, -1, 0.03, 'Rogue - Deadly Poison Rank 9($AP*0.12 / number of ticks)'),
(703, -1, -1, -1, 0.02, 'Rogue - Garrote'),
(1776, -1, -1, 0.21, -1, 'Rogue - Gouge'),
(8680, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 1'),
(8685, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 2'),
(8689, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 3'),
(11335, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 4'),
(11336, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 5'),
(11337, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 6'),
(26890, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 7'),
(57964, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 8'),
(57965, -1, -1, 0.1, -1, 'Rogue - Instant Poison Rank 9'),
(13218, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 1'),
(13222, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 2'),
(13223, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 3'),
(13224, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 4'),
(27189, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 5'),
(57974, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 6'),
(57975, -1, -1, 0.04, -1, 'Rogue - Wound Poison Rank 7'),
(1064, 1.34, -1, -1, -1, 'Shaman - Chain Heal'),
(421, 0.57, -1, -1, -1, 'Shaman - Chain Lightning'),
(974, 0.4762, -1, -1, -1, 'Shaman - Earth Shield'),
(379, 0, 0, 0, 0, 'Shaman - Earth Shield Triggered'),
(8042, 0.3858, -1, -1, -1, 'Shaman - Earth Shock'),
(8443, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 1'),
(8504, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 2'),
(8505, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 3'),
(11310, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 4'),
(11311, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 5'),
(25538, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 6'),
(25539, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 7'),
(61651, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 8'),
(61660, 0.2142, -1, -1, -1, 'Shaman - Fire Nova Totem Casted by Totem Rank 9'),
(8050, 0.2142, 0.1, -1, -1, 'Shaman - Flame Shock'),
(8026, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 1'),
(58788, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 10'),
(8028, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 2'),
(8029, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 3'),
(10445, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 4'),
(16343, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 5'),
(16344, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 6'),
(25488, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 7'),
(58786, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 8'),
(58787, 0.1, -1, -1, -1, 'Shaman - Flametongue Weapon Proc Rank 9'),
(8056, 0.3858, -1, -1, -1, 'Shaman - Frost Shock'),
(8034, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 1'),
(8037, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 2'),
(10458, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 3'),
(16352, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 4'),
(16353, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 5'),
(25501, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 6'),
(58797, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 7'),
(58798, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 8'),
(58799, 0.1, -1, -1, -1, 'Shaman - Frostbrand Attack Rank 9'),
(2645, 0, 0, 0, 0, 'Shaman - Glyph of Ghost Wolf'),
(52042, 0.045, -1, -1, -1, 'Shaman - Healing Stream Totem Triggered Heal'),
(331, 1.6106, -1, -1, -1, 'Shaman - Healing Wave'),
(51505, 0.5714, -1, -1, -1, 'Shaman - Lava Burst'),
(8004, 0.8082, -1, -1, -1, 'Shaman - Lesser Healing Wave'),
(403, 0.7143, -1, -1, -1, 'Shaman - Lightning Bolt'),
(26364, 0.33, -1, -1, -1, 'Shaman - Lightning Shield Proc Rank 1'),
(8188, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 1'),
(10582, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 2'),
(10583, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 3'),
(10584, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 4'),
(25551, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 5'),
(58733, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 6'),
(58736, 0.1, -1, -1, -1, 'Shaman - Magma Totam Passive Rank 7'),
(61295, 0.4, 0.18, -1, -1, 'Shaman - Riptide'),
(3606, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 1'),
(58702, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 10'),
(6350, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 2'),
(6351, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 3'),
(6352, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 4'),
(10435, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 5'),
(10436, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 6'),
(25530, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 7'),
(58700, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 8'),
(58701, 0.1667, -1, -1, -1, 'Shaman - Searing Totem Attack Rank 9'),
(50796, 0.7139, -1, -1, -1, 'Warlock - Chaos Bolt'),
(17962, 0, 0, 0, 0, 'Warlock - Conflagrate'),
(172, -1, 0.2, -1, -1, 'Warlock - Corruption'),
(980, -1, 0.1, -1, -1, 'Warlock - Curse of Agony'),
(603, -1, 2, -1, -1, 'Warlock - Curse of Doom'),
(18220, 0.96, -1, -1, -1, 'Warlock - Dark Pact Rank 1'),
(6789, 0.214, -1, -1, -1, 'Warlock - Death Coil'),
(689, -1, 0.143, -1, -1, 'Warlock - Drain Life'),
(5138, 0, 0, 0, 0, 'Warlock - Drain Mana'),
(1120, -1, 0.429, -1, -1, 'Warlock - Drain Soul'),
(28176, 0, 0, 0, 0, 'Warlock - Fel Armor'),
(18790, 0, 0, 0, 0, 'Warlock - Fel Stamina'),
(48181, 0.4793, -1, -1, -1, 'Warlock - Haunt'),
(755, -1, 0.4485, -1, -1, 'Warlock - Health Funnel'),
(1949, -1, 0.0949, -1, -1, 'Warlock - Hellfire'),
(5857, 0.145, -1, -1, -1, 'Warlock - Hellfire Effect on Enemy Rank 1'),
(348, 0.2, 0.2, -1, -1, 'Warlock - Immolate'),
(29722, 0.7139, -1, -1, -1, 'Warlock - Incinerate'),
(42223, 0.286, -1, -1, -1, 'Warlock - Rain of Fire Triggered Rank 1'),
(5676, 0.4293, -1, -1, -1, 'Warlock - Searing Pain'),
(27243, 0.2129, 0.25, -1, -1, 'Warlock - Seed of Corruption'),
(686, 0.8569, -1, -1, -1, 'Warlock - Shadow Bolt'),
(6229, 0.3, -1, -1, -1, 'Warlock - Shadow Ward'),
(17877, 0.4293, -1, -1, -1, 'Warlock - Shadowburn'),
(47960, 0.1064, 0.0667, -1, -1, 'Warlock - Shadowflame Rank 1'),
(61291, 0.1064, 0.0667, -1, -1, 'Warlock - Shadowflame Rank 2'),
(30283, 0.1932, -1, -1, -1, 'Warlock - Shadowfury'),
(63106, 0, 0, 0, 0, 'Warlock - Siphon Life Triggered'),
(6353, 1.15, -1, -1, -1, 'Warlock - Soul Fire'),
(30294, 0, 0, 0, 0, 'Warlock - Soul Leech'),
(30108, -1, 0.2, -1, -1, 'Warlock - Unstable Affliction'),
(31117, 1.8, -1, -1, -1, 'Warlock - Unstable Affliction Dispell'),
(57755, -1, -1, 0.5, -1, 'Warrior - Heroic Throw'),
(20253, -1, -1, 0.12, -1, 'Warrior - Intercept'),
(61491, -1, -1, 0.12, -1, 'Warrior - Intercept'),
(6572, -1, -1, 0.207, -1, 'Warrior - Revenge'),
(64382, -1, -1, 0.5, -1, 'Warrior - Shattering Throw'),
(6343, -1, -1, 0.12, -1, 'Warrior - Thunder Clap');

-- --------
-- SPELL DBC
-- --------

TRUNCATE TABLE `spell_dbc`;
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `AttributesEx3`, `DurationIndex`, `RangeIndex`, `Effect1`, `EffectImplicitTargetA1`, `EffectApplyAuraName1`, `EffectMiscValue1`, `SpellFamilyName`, `SchoolMask`, `Comment`) VALUES
(62388, 0,  0, 0x00000000, 21,  1, 6, 1,   4,  0,  0, 0, 'Demonic Circle: Teleport(48020) - casterAuraSpell'),
(65142, 3, 22, 0x00000080, 21, 13, 6, 6, 255, 22, 15, 8, 'Crypt Fever - SPELL_AURA_LINKED');

-- --------
-- SPELL ELIXIR
-- --------

TRUNCATE TABLE `spell_elixir`;
INSERT INTO `spell_elixir` (`entry`, `mask`) VALUES
(673, 0x2),
(2367, 0x1),
(2374, 0x1),
(2378, 0x2),
(2380, 0x2),
(3160, 0x1),
(3164, 0x1),
(3166, 0x2),
(3219, 0x2),
(3220, 0x2),
(3222, 0x2),
(3223, 0x2),
(3593, 0x2),
(7844, 0x1),
(8212, 0x1),
(10667, 0x1),
(10668, 0x2),
(10669, 0x1),
(10692, 0x2),
(10693, 0x2),
(11319, 0x2),
(11328, 0x1),
(11334, 0x1),
(11348, 0x2),
(11349, 0x2),
(11364, 0x2),
(11371, 0x2),
(11390, 0x1),
(11396, 0x2),
(11405, 0x1),
(11406, 0x1),
(11474, 0x1),
(15231, 0x2),
(15233, 0x2),
(16321, 0x2),
(16322, 0x1),
(16323, 0x1),
(16325, 0x2),
(16326, 0x2),
(16327, 0x2),
(16329, 0x1),
(17038, 0x1),
(17535, 0x2),
(17537, 0x1),
(17538, 0x1),
(17539, 0x1),
(17624, 0x3),
(17626, 0x3),
(17627, 0x3),
(17628, 0x3),
(17629, 0x3),
(21920, 0x1),
(24361, 0x2),
(24363, 0x2),
(24382, 0x2),
(24383, 0x2),
(24417, 0x2),
(26276, 0x1),
(27652, 0x2),
(27653, 0x2),
(28486, 0x1),
(28488, 0x1),
(28490, 0x1),
(28491, 0x1),
(28493, 0x1),
(28497, 0x1),
(28501, 0x1),
(28502, 0x2),
(28503, 0x1),
(28509, 0x2),
(28514, 0x2),
(28518, 0x3),
(28519, 0x3),
(28520, 0x3),
(28521, 0x3),
(28540, 0x3),
(29348, 0x2),
(33720, 0x1),
(33721, 0x1),
(33726, 0x1),
(38954, 0x1),
(39625, 0x2),
(39626, 0x2),
(39627, 0x2),
(39628, 0x2),
(40567, 0x7),
(40568, 0x7),
(40572, 0x7),
(40573, 0x7),
(40575, 0x7),
(40576, 0x7),
(41608, 0xB),
(41609, 0xB),
(41610, 0xB),
(41611, 0xB),
(42735, 0x3),
(45373, 0x1),
(46837, 0xB),
(46839, 0xB),
(53746, 0x1),
(53747, 0x2),
(53748, 0x1),
(53749, 0x1),
(53751, 0x2),
(53752, 0x3),
(53755, 0x3),
(53758, 0x3),
(53760, 0x3),
(53763, 0x2),
(53764, 0x2),
(54212, 0x3),
(54452, 0x1),
(54494, 0x1),
(60340, 0x1),
(60341, 0x1),
(60343, 0x2),
(60344, 0x1),
(60345, 0x1),
(60346, 0x1),
(60347, 0x2),
(62380, 0x3),
(18191,0x10),
(18192,0x10),
(18193,0x10),
(18194,0x10),
(18222,0x10),
(22730,0x10),
(25661,0x10);

-- --------
-- Death Knight
-- --------
DELETE FROM `spell_script_target` WHERE entry IN
(51859, 48743, 52124, 52479, 52576, 53110);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(51859, 1, 28525), -- siphon of archerus
(51859, 1, 28542),
(51859, 1, 28543),
(51859, 1, 28544),
(52124, 1, 28655), -- Sky Darkener Assault
(52479, 1, 28819), -- gift of harvester
(52479, 1, 28822),
(52576, 1, 28834), -- Electro-magnetic Pulse
(52576, 1, 28886),
(53110, 1, 29102),
(53110, 1, 29103); -- Devour Humanoid

-- Eye of Acherus
DELETE FROM `spell_target_position` WHERE `id`=51852;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(51852, 609, 2361.21, -5660.45, 503.828, 4.49);

DELETE FROM `spell_script_target` WHERE `entry` in (53658, 53679, 53701, 53705, 53706, 53677, 53685);
insert into spell_script_target values
-- (53658, 1, 29173),
(53679, 1, 29183),
(53701, 1, 29175),
(53705, 1, 29183),
(53706, 1, 29183),
(53677, 1, 29227),
(53685, 1, 29175);

-- --------
-- NAXXARAMAS
-- --------

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN
(28732,54097,-29865,-55053,-28169,28059,39088,-28059,-39088,28062,39090,28084,
39091,-28084,-39091,28085,39093);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 28732,-28798,  1, 'Widow''s Embrace - Frenzy'),
( 54097,-54100,  1, 'Widow''s Embrace - Frenzy (H)'),
(-29865, 55594,  0, 'Deathbloom'),
(-55053, 55601,  0, 'Deathbloom (H)'),
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud'),
( 28059,-28084,  1, 'Positive Charge - Negative Charge'),
(-28059,-29659,  0, 'Positive Charge'),
-- ( 28062,-29659,  0, 'Positive Charge'),
( 28084,-28059,  1, 'Negative Charge - Positive Charge'),
(-28084,-29660,  0, 'Negative Charge'),
-- ( 28085,-29660,  0, 'Negative Charge'),
( 39088,-39091,  1, 'Positive Charge - Negative Charge'),
(-39088,-29659,  0, 'Positive Charge'),
-- ( 39090,-29659,  0, 'Positive Charge'),
( 39091,-39088,  1, 'Negative Charge - Positive Charge'),
(-39091,-39092,  0, 'Negative Charge'),
-- ( 39093,-39092,  0, 'Negative Charge'),
( 33878, -33876, 1, 'Mangle - Remover'),
( 33878, -33982, 1, 'Mangle - Remover'),
( 33878, -33983, 1, 'Mangle - Remover'),
( 33878, -48565, 1, 'Mangle - Remover'),
( 33878, -48566, 1, 'Mangle - Remover'),
( 33986, -33876, 1, 'Mangle - Remover'),
( 33986, -33982, 1, 'Mangle - Remover'),
( 33986, -33983, 1, 'Mangle - Remover'),
( 33986, -48565, 1, 'Mangle - Remover'),
( 33986, -48566, 1, 'Mangle - Remover'),
( 33987, -33876, 1, 'Mangle - Remover'),
( 33987, -33982, 1, 'Mangle - Remover'),
( 33987, -33983, 1, 'Mangle - Remover'),
( 33987, -48565, 1, 'Mangle - Remover'),
( 33987, -48566, 1, 'Mangle - Remover'),
( 48563, -33876, 1, 'Mangle - Remover'),
( 48563, -33982, 1, 'Mangle - Remover'),
( 48563, -33983, 1, 'Mangle - Remover'),
( 48563, -48565, 1, 'Mangle - Remover'),
( 48563, -48566, 1, 'Mangle - Remover'),
( 48564, -33876, 1, 'Mangle - Remover'),
( 48564, -33982, 1, 'Mangle - Remover'),
( 48564, -33983, 1, 'Mangle - Remover'),
( 48564, -48565, 1, 'Mangle - Remover'),
( 48564, -48566, 1, 'Mangle - Remover'),
( 33876, -33878, 1, 'Mangle - Remover'),
( 33982, -33878, 1, 'Mangle - Remover'),
( 33983, -33878, 1, 'Mangle - Remover'),
( 48565, -33878, 1, 'Mangle - Remover'),
( 48566, -33878, 1, 'Mangle - Remover'),
( 33876, -33986, 1, 'Mangle - Remover'),
( 33982, -33986, 1, 'Mangle - Remover'),
( 33983, -33986, 1, 'Mangle - Remover'),
( 48565, -33986, 1, 'Mangle - Remover'),
( 48566, -33986, 1, 'Mangle - Remover'),
( 33876, -33987, 1, 'Mangle - Remover'),
( 33982, -33987, 1, 'Mangle - Remover'),
( 33983, -33987, 1, 'Mangle - Remover'),
( 48565, -33987, 1, 'Mangle - Remover'),
( 48566, -33987, 1, 'Mangle - Remover'),
( 33876, -48563, 1, 'Mangle - Remover'),
( 33982, -48563, 1, 'Mangle - Remover'),
( 33983, -48563, 1, 'Mangle - Remover'),
( 48565, -48563, 1, 'Mangle - Remover'),
( 48566, -48563, 1, 'Mangle - Remover'),
( 33876, -48564, 1, 'Mangle - Remover'),
( 33982, -48564, 1, 'Mangle - Remover'),
( 33983, -48564, 1, 'Mangle - Remover'),
( 48565, -48564, 1, 'Mangle - Remover'),
( 48566, -48564, 1, 'Mangle - Remover');

DELETE FROM `spell_script_target` WHERE `entry` IN
(28732,54097,55479,
27892,27893,27928,27929,27935,27936);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(28732, 1, 15953), -- Widow's Embrace
(54097, 1, 15953), -- Widow's Embrace
(55479, 1, 16803), -- Force Obedience - Death Knight Understudy
-- (29105, 1, 16803), -- Hopeless - Death Knight Understudy
(27892, 1, 16060), -- To Anchor 1 - Gothik
(27893, 1, 16060), -- To Anchor 2 - Gothik
(27928, 1, 16060), -- To Anchor 1 - Gothik
(27929, 1, 16060), -- To Anchor 2 - Gothik
(27935, 1, 16060), -- To Anchor 1 - Gothik
(27936, 1, 16060); -- To Anchor 2 - Gothik



-- --------
-- ULDUAR
-- --------

DELETE FROM `spell_script_target` WHERE `entry` IN (62427,62496,62374,62399,62056,63985);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(62427, 1, 33109), -- Load into Catapult
(62374, 1, 33060), -- Pursued
(62374, 1, 33109),
(62399, 1, 33139), -- Overload Circuit
(62496, 1, 33167), -- Liquid Pyrite - Salvaged Demolisher Mechanic Seat
(63985, 1, 32934), -- Stone Grip
(62056, 1, 32934);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-62475,62427);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-62475,-62399, 0, 'System Shutdown - Overload Circuit'),
(-62475,-62375, 0, 'System Shutdown - Gathering Speed'),
(-62475, 62472, 0, 'System Shutdown'), #inform, not correct spell
( 62427, 62340, 2, 'Load into Catapult - Passenger Loaded');


-- --------
-- WINTERGRASP
-- --------

-- Build Vehicles
DELETE FROM `spell_script_target` WHERE entry IN
(56575,56661,56663,56665,56667,56669,61408);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(56575, 1, 27852),
(56661, 1, 27852),
(56663, 1, 27852),
(56665, 1, 27852),
(56667, 1, 27852),
(56669, 1, 27852),
(61408, 1, 27852);

-- Defender's Portal
DELETE FROM `spell_script_target` WHERE entry IN
(54643);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(54643,1,23472);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (54643);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 54643,-54643, 2, 'Wintergrasp Defender Teleport');

-- No Fly Zone
INSERT INTO `spell_linked_spell` (spell_trigger, spell_effect, type, comment) VALUES
    (-58600, 61243, 0, 'No fly zone - Parachute'),
    (-58730, 61243, 0, 'No fly zone - Parachute');

-- temp
UPDATE `creature_template` SET `ScriptName`='boss_netherspite' WHERE `entry`='15689';
UPDATE `creature_template` SET `ScriptName` = 'mob_eventai'  WHERE `entry` = '16697';
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN ('-30421','-30422','-30423','38637','38638','38639');
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
('-30421','38637','0','Netherspite''s Perseverence'),
('-30422','38638','0','Netherspite''s Serenity'),
('-30423','38639','0','Netherspite''s Dominance');


-- Chicken Net
DELETE FROM `spell_script_target` WHERE `entry` = '51959' and `type` = '1';
INSERT INTO `spell_script_target` ( `entry`, `type`, `targetEntry`) VALUES ('51959', '1', '28161');

-- update creature_template set ScriptName = 'npc_iruk' where entry = 26219;
-- UPDATE creature_template SET ScriptName = 'npc_corastrasza' WHERE entry = 32548;

DELETE FROM `spell_script_target` WHERE entry = 61245;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(61245, 1, 32535);
