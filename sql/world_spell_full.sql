-- up to TC2 2987 TC1 1434

-- --------
-- LINKED
-- --------

# spell1 / spell2 / type
# + + 0 caster casts 2 when casts 1
# + - 0 caster removes aura 2 when casts 1
# + + 1 target casts 2 on self (originalCaster = caster) when 1 casted by caster hits target
# + - 1 target removes aura 2 when hit by 1
# + + 2 when aura 1 is applied, aura 2 is also applied; when 1 is removed, 2 is also removed
# + - 2 when aura 1 is applied, target is immune to spell 2, until 1 is removed
# - + 0 target casts 2 on self (originalCaster = caster) when aura 1 casted by caster is removed
# - - 0 aura 2 is removed when aura 1 is removed

DROP TABLE IF EXISTS `spell_linked_spell`;
CREATE TABLE `spell_linked_spell` (
  `spell_trigger` mediumint(8) NOT NULL,
  `spell_effect` mediumint(8) NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `comment` text NOT NULL,
  UNIQUE KEY `trigger_effect_type` (`spell_trigger`,`spell_effect`,`type`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

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
( 47585, 60069, 0, 'Dispersion (transform/regen)'),
(-47953, 60406, 0, 'Divine hymn buff to enemies'),
( 48265, 49772, 2, 'Unholy Presence'),
( 49772, 55222, 2, 'Unholy Presence'),
( 48263, 61261, 2, 'Frost Presence'),
( 61847, 61848, 2, 'Aspect of te dragonhawk'),
( 61846, 61848, 2, 'Aspect of te dragonhawk'),
( 47988, 54501, 2, 'Consume Shadows - Rank 9'),
( 47987, 54501, 2, 'Consume Shadows - Rank 8'),
( 27272, 54501, 2, 'Consume Shadows - Rank 7'),
( 17854, 54501, 2, 'Consume Shadows - Rank 6'),
( 17853, 54501, 2, 'Consume Shadows - Rank 5'),
( 17852, 54501, 2, 'Consume Shadows - Rank 4'),
( 17851, 54501, 2, 'Consume Shadows - Rank 3'),
( 17850, 54501, 2, 'Consume Shadows - Rank 2'),
( 17767, 54501, 2, 'Consume Shadows - Rank 1'),
( 53563, 53651, 2, 'Beacon of Light'),
( 16857, 60089, 0, 'Faerie Fire (Feral) Rank 1'),
( 17390, 60089, 0, 'Faerie Fire (Feral) Rank 2'),
( 17391, 60089, 0, 'Faerie Fire (Feral) Rank 3'),
( 17392, 60089, 0, 'Faerie Fire (Feral) Rank 4'),
( 27011, 60089, 0, 'Faerie Fire (Feral) Rank 5'),
( 48475, 60089, 0, 'Faerie Fire (Feral) Rank 6'),
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
-- Creature
( 36574, 36650, 0, 'Apply Phase Slip Vulnerability'),
-- instance
(-30410, 44032, 0, 'Manticron Cube Mind Exhaustion'),
(-33711, 33686, 0, 'Murmur\'s Shockwave (Normal)'),
(-38794, 33686, 0, 'Murmur\'s Shockwave (Heroic)'),
( 33686, 31705, 0, 'Murmur\'s Shockwave Jump'),
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
# (39992, 39835, 1, 'Needle Spine'),
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
# (44869, 46648, 1, 'Spectral Blast Visual'), cause severe lag seems should be casted by go
( 44869, 46019, 1, 'Spectral Blast Teleport'),
( 46019, 46021, 1, 'Spectral Realm Aura'),
# (46021, 44852, 1, 'Spectral Realm Aura'), 44852 makes boss friendly to you
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
(-28169, 28240, 0, 'Mutating Injection - Poison Cloud');


-- --------
-- TRIGGER
-- --------

INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(23095, 40980, 128, 'molten_flame'), # molten_flame
# (23085, 40117, 128, ''), # volcano
(23336, 40836, 128, ''), # flame crash
(23259, 40610, 128, ''), # blaze
(23069, 40029, 128, ''), # demon fire
(24187, 43218, 128, ''), # pillar of fire
(17662, 30914, 128, ''), # Broggok Poison Cloud
(25879, 46262, 128, '')  # Void Zone Periodic
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

UPDATE creature_template SET spell1 = 28158, spell2 = 54362, flags_extra = 128 WHERE entry = 16363;
UPDATE creature_template SET speed = 1.0 WHERE entry = 23095; # molten_flame


-- --------
-- TARGET
-- --------

-- zulaman
DELETE FROM `spell_script_target` WHERE `entry` IN
(42577,42471,43734,42631);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(42471, 1, 23817), # hatch eggs
(43734, 1, 23817), # hatch eggs
(42631, 1, 23920), # fire bomb
(42577, 1, 24136); # zap inform

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
(30531, 1, 17256), # soul transfer
(30657, 1, 24136); # quake

-- black temple
DELETE FROM `spell_script_target` WHERE `entry` IN
(41455);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(41455, 1, 22949), # circle of healing
(41455, 1, 22950),
(41455, 1, 22951),
(41455, 1, 22952);

-- Magisters' Terrace
DELETE FROM spell_script_target WHERE `entry` IN
(44320, 44321);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(44320, 1, 24723), # Mana Rage
(44321, 1, 24723); # Mana Rage

DELETE FROM `spell_script_target` WHERE `entry` IN
(30659);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(30659, 1, 17281); # Fel Infusion

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
(33655, 0, 183350), # Dropping The Nether Modulator/Gateway Murketh
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
(21934,1,21934),
(43144,1,23817),
(12613,1,5843),
(9095,1,1200);

DELETE FROM `spell_script_target` WHERE entry IN
(8913,9095,12613,34019,34526,36904,38015,38738,39011,39844,40105,40106,42391);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(8913,  1, 1200),
(9095,  1, 6492),
(12613, 1, 5843),
(34019, 2, 16873), # raise dead
(34019, 2, 16871),
(34019, 2, 19422),
(34019, 2, 16907),
(34526, 1, 19723),
(34526, 1, 19724),
(36904, 0, 21511),
(38015, 1, 21216),
(38738, 0, 185193), # Activate Legion Obelisk
(38738, 0, 185195),
(38738, 0, 185196),
(38738, 0, 185197),
(38738, 0, 185198),
(39011, 1, 20885),
(39844, 0, 185549),
(40105, 1, 22883),
(40106, 1, 22883),
(42391, 0, 300152);

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
(12134,2,8313),
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
(38968,1,38968),
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

-- --------
-- POSITION
-- --------
DELETE FROM spell_target_position WHERE `id` IN (46019, 46020);
INSERT INTO spell_target_position () VALUES (46019, 580, 1704.34, 928.17, -74.558, 0);
INSERT INTO spell_target_position () VALUES (46020, 580, 1704.34, 928.17, 53.079, 0);
INSERT INTO spell_target_position () VALUES (53360, 571, 5807.829, 587.960, 660.939, 1.663);

