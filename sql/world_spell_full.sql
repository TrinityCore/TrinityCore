-- Up to TC2 3515

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
( 33206, 44416, 2, 'Pain Suppression (threat)'),
( 50720, 59665, 0, 'Vigilance (redirect threat)'),
( 52610, 62071, 0, 'Savage Roar'),
( -52610, -62071, 0, 'Savage Roar'),

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
( 28732,-28798, 1, 'Widow\'s Embrace - Frenzy'),
( 54097,-54100, 1, 'Widow\'s Embrace - Frenzy (H)'),
(-28169, 28240, 0, 'Mutating Injection - Poison Cloud'),
-- Archavon
( 58666, 58672, 1, 'Impale (Archavon)'),
( 60882, 58672, 1, 'Impale (Archavon)');


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
(25879, 46262, 128, ''), # Void Zone Periodic
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, '') # Grobbulus Cloud (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

UPDATE creature_template SET speed = 1.0 WHERE entry = 23095; # molten_flame

-- --------
-- CLICK
-- --------

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN ('29501', '29488');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
('29488', '54568', '12670', '1', '3'),
('29501', '54575', '12670', '1', '3');

DELETE FROM npc_spellclick_spells WHERE `npc_entry` IN (28605,28606,28607);
INSERT INTO npc_spellclick_spells (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28605, 52263, 12680, 3, 1),
(28606, 52263, 12680, 3, 1),
(28607, 52263, 12680, 3, 1);

-- Spellclick spell to mount deathcharger
DELETE FROM npc_spellclick_spells WHERE `npc_entry`=28782;
INSERT INTO npc_spellclick_spells (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28782, 52280, 12687, 3, 1);

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

-- naxx
DELETE FROM `spell_script_target` WHERE `entry` IN
(28732,54097,55479,
27892,27893,27928,27929,27935,27936);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(28732, 1, 15953), # Widow's Embrace
(54097, 1, 15953), # Widow's Embrace
(55479, 1, 16803), # Force Obedience - Death Knight Understudy
# (29105, 1, 16803), # Hopeless - Death Knight Understudy
(27892, 1, 16060), # To Anchor 1 - Gothik
(27893, 1, 16060), # To Anchor 2 - Gothik
(27928, 1, 16060), # To Anchor 1 - Gothik
(27929, 1, 16060), # To Anchor 2 - Gothik
(27935, 1, 16060), # To Anchor 1 - Gothik
(27936, 1, 16060); # To Anchor 2 - Gothik

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

-- --------
-- POSITION
-- --------
DELETE FROM spell_target_position WHERE `id` IN (46019, 46020, 53360);
INSERT INTO spell_target_position () VALUES (46019, 580, 1704.34, 928.17, -74.558, 0);
INSERT INTO spell_target_position () VALUES (46020, 580, 1704.34, 928.17, 53.079, 0);
INSERT INTO spell_target_position () VALUES (53360, 571, 5807.829, 587.960, 660.939, 1.663);

-- positions for teleports in acherus
DELETE FROM `spell_target_position` WHERE `id` IN (54744,54746);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(54744, 0, 2418.67, -5621.41, 420.644, 3.89597),
(54746, 0, 2402.15, -5633.74, 377.021, 3.65249);

-- --------
-- MISC
-- --------
UPDATE `creature_template` SET `flags_extra` = 33 WHERE `entry` = 23576; /*no crush*/

DELETE FROM `playercreateinfo_spell` WHERE Spell = 56816;
INSERT INTO `playercreateinfo_spell` (`race`, `class`, `Spell`, `Note`) VALUES
(0, 6, 56816, 'Rune Strike');

-- --------
-- REQUIRED
-- --------
DROP TABLE IF EXISTS `spell_required`;
CREATE TABLE `spell_required` (
  `spell_id` mediumint(9) NOT NULL default '0',
  `req_spell` mediumint(9) NOT NULL default '0',
  PRIMARY KEY  (`spell_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Spell Additinal Data';

INSERT INTO `spell_required` (`spell_id`, `req_spell`) VALUES
(53312, 53308),
(48938, 48936),
(48937, 48935),
(48934, 48932),
(48933, 48931),
(27143, 27142),
(27141, 27140),
(27009, 26989),
(25916, 25291),
(25918, 25290),
(25894, 19854),
(25782, 19838),
(27681, 14752),
(17329, 9853),
(16813, 9852),
(16812, 5196),
(16811, 5195),
(16810, 1062),
(16689, 339),
(9788, 9785),
(17039, 9787),
(17040, 9787),
(17041, 9787),
(10660, 10662),
(10658, 10662),
(10656, 10662),
(28672, 28596),
(28675, 28596),
(28677, 28596),
(26801, 26790),
(26798, 26790),
(26797, 26790),
(20222, 12656),
(20219, 12656),
(25899, 20911);

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
DROP TABLE IF EXISTS `spell_proc_event`;
CREATE TABLE `spell_proc_event` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(4) NOT NULL default '0',
  `SpellFamilyName` smallint(5) unsigned NOT NULL default '0',
  `SpellFamilyMask0` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask1` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask2` int(10) unsigned NOT NULL default '0',
  `procFlags` int(10) unsigned NOT NULL default '0',
  `procEx` int(10) unsigned NOT NULL default '0',
  `ppmRate` float NOT NULL default '0',
  `CustomChance` float NOT NULL default '0',
  `Cooldown` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(324,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 1)
(325,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 2)
(905,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 3)
(945,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 4)
(974,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield (Rank 1)
(1463,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 1)
(3232,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Gouge Stun Test
(5952,	0x00,	8,	0x00000001,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Throwing Specialization (Rank 1)
(6346,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000100,	0,	0,	0), -- Fear Ward
(7383,	0x01,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000100,	0,	0,	0), -- Water Bubble
(7434,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Fate Rune of Unsurpassed Vigor
(8134,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 5)
(8178,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Grounding Totem Effect (Rank 1)
(8494,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 2)
(8495,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 3)
(9452,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Vindication (Rank 1)
(9782,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Mithril Shield Spike
(9784,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Iron Shield Spike
(9799,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Eye for an Eye (Rank 1)
(10191,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 4)
(10192,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 5)
(10193,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 6)
(10431,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 6)
(10432,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 7)
(11095,	0x00,	3,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Scorch (Rank 1)
(11119,	0x04,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ignite (Rank 1)
(11120,	0x04,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ignite (Rank 2)
(11129,	0x00,	3,	0x00C00017,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Combustion
(11180,	0x10,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Winter's Chill (Rank 1)
(11185,	0x00,	3,	0x00000080,	0x00000000,	0x00000000,	0x00050000,	0x00000000,	0,	0,	0), -- Improved Blizzard (Rank 1)
(11255,	0x00,	3,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Counterspell (Rank 1)
(12169,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Block
(12281,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sword Specialization (Rank 1)
(12289,	0x00,	4,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Hamstring (Rank 1)
(12298,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 1)
(12311,	0x00,	4,	0x00000800,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Gag Order (Rank 1)
(12319,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 1)
(12322,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Unbridled Wrath (Rank 1)
(12487,	0x00,	3,	0x00000080,	0x00000000,	0x00000000,	0x00050000,	0x00000000,	0,	0,	0), -- Improved Blizzard (Rank 2)
(12488,	0x00,	3,	0x00000080,	0x00000000,	0x00000000,	0x00050000,	0x00000000,	0,	0,	0), -- Improved Blizzard (Rank 3)
(12598,	0x00,	3,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Counterspell (Rank 2)
(12668,	0x00,	4,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Hamstring (Rank 2)
(12724,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 2)
(12725,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 3)
(12726,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 4)
(12727,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 5)
(12797,	0x00,	4,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Revenge (Rank 1)
(12799,	0x00,	4,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Revenge (Rank 2)
(12812,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sword Specialization (Rank 2)
(12813,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sword Specialization (Rank 3)
(12814,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sword Specialization (Rank 4)
(12815,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sword Specialization (Rank 5)
(12834,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Deep Wounds (Rank 1)
(12846,	0x04,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ignite (Rank 3)
(12847,	0x04,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ignite (Rank 4)
(12848,	0x04,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ignite (Rank 5)
(12849,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Deep Wounds (Rank 2)
(12867,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Deep Wounds (Rank 3)
(12872,	0x00,	3,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Scorch (Rank 2)
(12873,	0x00,	3,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Scorch (Rank 3)
(12958,	0x00,	4,	0x00000800,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Gag Order (Rank 2)
(12966,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 1)
(12967,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 2)
(12968,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 3)
(12969,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 4)
(12970,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 5)
(12971,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 2)
(12972,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 3)
(12973,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 4)
(12974,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 5)
(12999,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	4,	0,	0), -- Unbridled Wrath (Rank 2)
(13000,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	6,	0,	0), -- Unbridled Wrath (Rank 3)
(13001,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	8,	0,	0), -- Unbridled Wrath (Rank 4)
(13002,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	10,	0,	0), -- Unbridled Wrath (Rank 5)
(13163,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Aspect of the Monkey
(13165,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 1)
(13754,	0x00,	8,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Kick (Rank 1)
(13867,	0x00,	8,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Kick (Rank 2)
(13983,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000018,	0,	0,	0), -- Setup (Rank 1)
(14070,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000018,	0,	0,	0), -- Setup (Rank 2)
(14071,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000018,	0,	0,	0), -- Setup (Rank 3)
(14156,	0x00,	8,	0x003E0000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Ruthlessness (Rank 1)
(14160,	0x00,	8,	0x003E0000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Ruthlessness (Rank 2)
(14161,	0x00,	8,	0x003E0000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Ruthlessness (Rank 3)
(14186,	0x00,	8,	0x40800508,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Seal Fate (Rank 1)
(14190,	0x00,	8,	0x40800508,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Seal Fate (Rank 2)
(14193,	0x00,	8,	0x40800508,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Seal Fate (Rank 3)
(14194,	0x00,	8,	0x40800508,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Seal Fate (Rank 4)
(14195,	0x00,	8,	0x40800508,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Seal Fate (Rank 5)
(14318,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 2)
(14319,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 3)
(14320,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 4)
(14321,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 5)
(14322,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 6)
(14531,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Martyrdom (Rank 1)
(14774,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Martyrdom (Rank 2)
(14892,	0x00,	6,	0x10001E00,	0x00010004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Inspiration (Rank 1)
(15088,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry
(15128,	0x04,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Mark of Flames
(15268,	0x20,	6,	0x06080000,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 1)
(15277,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	6,	0,	0), -- Seal of Reckoning
(15286,	0x20,	6,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Embrace
(15323,	0x20,	6,	0x06080000,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 2)
(15324,	0x20,	6,	0x06080000,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 3)
(15325,	0x20,	6,	0x06080000,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 4)
(15326,	0x20,	6,	0x06080000,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 5)
(15337,	0x00,	6,	0x00002000,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Spirit Tap (Rank 1)
(15338,	0x00,	6,	0x00002000,	0x00000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Spirit Tap (Rank 2)
(15346,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	6,	0,	0), -- Seal of Reckoning
(15362,	0x00,	6,	0x10001E00,	0x00010004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Inspiration (Rank 2)
(15363,	0x00,	6,	0x10001E00,	0x00010004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Inspiration (Rank 3)
(15600,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1,	0,	0), -- Hand of Justice
(16086,	0x00,	11,	0x00000000,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Fire Nova Totem (Rank 1)
(16164,	0x00,	11,	0x901000C3,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Focus
(16176,	0x00,	11,	0x000001C0,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Healing (Rank 1)
(16180,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Water Shield (Rank 1)
(16196,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Water Shield (Rank 2)
(16198,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Water Shield (Rank 3)
(16235,	0x00,	11,	0x000001C0,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Healing (Rank 2)
(16240,	0x00,	11,	0x000001C0,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Healing (Rank 3)
(16256,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 1)
(16257,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 1)
(16277,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 2)
(16278,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 3)
(16279,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 4)
(16280,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Flurry (Rank 5)
(16281,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 2)
(16282,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 3)
(16283,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 4)
(16284,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Flurry (Rank 5)
(16487,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blood Craze (Rank 1)
(16489,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blood Craze (Rank 2)
(16492,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blood Craze (Rank 3)
(16544,	0x00,	11,	0x00000000,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Fire Nova Totem (Rank 2)
(16550,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Bonespike (Rank 1)
(16620,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Proc Self Invulnerability
(16624,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Thorium Shield Spike
(16850,	0x00,	7,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Celestial Focus (Rank 1)
(16864,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Omen of Clarity
(16880,	0x48,	7,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Nature's Grace
(16923,	0x00,	7,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Celestial Focus (Rank 2)
(16924,	0x00,	7,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Celestial Focus (Rank 3)
(16952,	0x00,	7,	0x00039000,	0x00000400,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blood Frenzy (Rank 1)
(16954,	0x00,	7,	0x00039000,	0x00000400,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blood Frenzy (Rank 2)
(16958,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Primal Fury (Rank 1)
(16961,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Primal Fury (Rank 2)
(17106,	0x00,	7,	0x00080000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Intensity (Rank 1)
(17107,	0x00,	7,	0x00080000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Intensity (Rank 2)
(17108,	0x00,	7,	0x00080000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Intensity (Rank 3)
(17364,	0x08,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Stormstrike
(17495,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Crest of Retribution
(17619,	0x00,	13,	0x00000000,	0x00000000,	0x00000000,	0x00008000,	0x00000000,	0,	0,	0), -- Alchemist's Stone
(17793,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Shadow Bolt (Rank 1)
(17794,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000001,	0,	0,	0), -- Shadow Mastery
(17796,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Shadow Bolt (Rank 2)
(17797,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Mastery
(17798,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Mastery
(17799,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Mastery
(17800,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Mastery
(17801,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Shadow Bolt (Rank 3)
(17802,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Shadow Bolt (Rank 4)
(17803,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Improved Shadow Bolt (Rank 5)
(18073,	0x00,	5,	0x00000060,	0x00800080,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pyroclasm (Rank 2)
(18094,	0x00,	5,	0x0000000A,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Nightfall (Rank 1)
(18095,	0x00,	5,	0x0000000A,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Nightfall (Rank 2)
(18096,	0x00,	5,	0x00000060,	0x00800080,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pyroclasm (Rank 1)
(18119,	0x00,	5,	0x000003E5,	0x000010C0,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aftermath (Rank 1)
(18120,	0x00,	5,	0x000003E5,	0x000010C0,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aftermath (Rank 2)
(18820,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Insight
(19184,	0x00,	9,	0x00000014,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Entrapment (Rank 1)
(19228,	0x00,	0,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Wing Clip (Rank 1)
(19232,	0x00,	9,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Wing Clip (Rank 2)
(19233,	0x00,	9,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Wing Clip (Rank 3)
(19387,	0x00,	9,	0x00000014,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Entrapment (Rank 2)
(19388,	0x00,	9,	0x00000014,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Entrapment (Rank 3)
(19572,	0x00,	9,	0x00800000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Mend Pet (Rank 1)
(19573,	0x00,	9,	0x00800000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Mend Pet (Rank 2)
(20049,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Vengeance (Rank 1)
(20056,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Vengeance (Rank 2)
(20057,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Vengeance (Rank 3)
(20128,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Redoubt
(20131,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Redoubt
(20132,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Redoubt
(20164,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	5,	0,	0), -- Seal of Justice
(20165,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	20,	0,	0), -- Seal of Light
(20166,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	12,	0,	0), -- Seal of Wisdom
(20177,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000043,	0,	0,	0), -- Reckoning (Rank 1)
(20179,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000043,	0,	0,	0), -- Reckoning (Rank 2)
(20180,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000043,	0,	0,	0), -- Reckoning (Rank 4)
(20181,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000043,	0,	0,	0), -- Reckoning (Rank 3)
(20182,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000043,	0,	0,	0), -- Reckoning (Rank 5)
(20210,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Illumination (Rank 1)
(20212,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Illumination (Rank 2)
(20213,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Illumination (Rank 3)
(20214,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Illumination (Rank 4)
(20215,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Illumination (Rank 5)
(20234,	0x00,	10,	0x00008000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Lay on Hands (Rank 1)
(20235,	0x00,	10,	0x00008000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Lay on Hands (Rank 2)
(20375,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	7,	0,	0), -- Seal of Command
(20500,	0x00,	4,	0x10000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Berserker Rage (Rank 1)
(20501,	0x00,	4,	0x10000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Berserker Rage (Rank 2)
(20705,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Power Shield 500
(20911,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Blessing of Sanctuary
(20925,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 1)
(20927,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 2)
(20928,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 3)
(21185,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Spinal Reaper
(21882,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Judgement Smite
(21890,	0x00,	4,	0x2A764EEF,	0x0000036C,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Warrior's Wrath
(22007,	0x00,	3,	0x00200021,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Netherwind Focus
(22618,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Force Reactive Disk
(22648,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Call of Eskhandar
(23547,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Parry
(23548,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Parry
(23551,	0x00,	11,	0x000000C0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Shield
(23552,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield
(23572,	0x00,	11,	0x000000C0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Mana Surge
(23578,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Expose Weakness
(23581,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Bloodfang
(23602,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Specialization (Rank 1)
(23686,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Lightning Strike
(23688,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Aura of the Blue Dragon
(23689,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	4,	0,	0), -- Heroism
(23695,	0x00,	4,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Hamstring (Rank 3)
(23721,	0x00,	9,	0x00000800,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Arcane Infused
(23920,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Spell Reflection
(24353,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Primal Instinct
(24389,	0x00,	3,	0x00C00017,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Chaos Fire
(24398,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 7)
(24658,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00014110,	0x00000000,	0,	0,	0), -- Unstable Power
(24905,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	15,	0,	0), -- Moonkin Form (Passive) (Passive)
(24932,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	6), -- Leader of the Pack
(25050,	0x04,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Mark of Flames
(25296,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 7)
(25469,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 8)
(25472,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 9)
(25669,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1,	0,	0), -- Decapitate
(25899,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Greater Blessing of Sanctuary
(25988,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Eye for an Eye (Rank 2)
(26016,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Vindication (Rank 2)
(26107,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000064,	0,	0,	0), -- Symbols of Unending Life Finisher Bonus
(26119,	0x00,	10,	0x90100003,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Stormcaller Spelldamage Bonus
(26128,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000008,	0,	0,	0), -- Enigma Resist Bonus
(26135,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Battlegear of Eternal Justice
(26480,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Badge of the Swarmguard
(26605,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Bloodcrown
(27044,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Aspect of the Hawk (Rank 8)
(27131,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 7)
(27179,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 4)
(27419,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Warrior's Resolve
(27498,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Crusader's Wrath
(27521,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	15), -- Mana Restore
(27656,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Flame Lash
(27774,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- The Furious Storm
(27787,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Rogue Armor Energize
(27811,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Recovery (Rank 1)
(27815,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Recovery (Rank 2)
(27816,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Recovery (Rank 3)
(28592,	0x10,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Winter's Chill (Rank 2)
(28593,	0x10,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Winter's Chill (Rank 3)
(28716,	0x00,	7,	0x00000010,	0x00000000,	0x00000000,	0x00048000,	0x00000000,	0,	0,	0), -- Rejuvenation
(28719,	0x00,	7,	0x00000020,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Healing Touch
(28744,	0x00,	7,	0x00000040,	0x00000000,	0x00000000,	0x00044000,	0x00000000,	0,	0,	0), -- Regrowth
(28752,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Adrenaline Rush
(28789,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Holy Power
(28802,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Epiphany
(28809,	0x00,	6,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Greater Heal
(28812,	0x00,	8,	0x02000006,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Head Rush
(28816,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Invigorate
(28823,	0x00,	11,	0x000000C0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Totemic Power
(28847,	0x00,	7,	0x00000020,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Healing Touch Refund
(28849,	0x00,	11,	0x00000080,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lesser Healing Wave
(29074,	0x14,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Master of Elements (Rank 1)
(29075,	0x14,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Master of Elements (Rank 2)
(29076,	0x14,	3,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Master of Elements (Rank 3)
(29150,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Electric Discharge
(29179,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Devastation (Rank 2)
(29180,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Devastation (Rank 3)
(29385,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	7,	0,	0), -- Seal of Command
(29441,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000008,	0,	0,	1), -- Magic Absorption (Rank 1)
(29444,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000008,	0,	0,	1), -- Magic Absorption (Rank 2)
(29455,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Felsteel Shield Spike
(29501,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Frost Arrow
(29593,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Improved Defensive Stance (Rank 1)
(29594,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Improved Defensive Stance (Rank 2)
(29624,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Searing Arrow
(29625,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Flaming Cannonball
(29626,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Shadow Bolt
(29632,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Shadow Shot
(29633,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Fire Blast
(29634,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Quill Shot
(29635,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Flaming Shell
(29636,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Venom Shot
(29637,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Keeper's Sting
(29801,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Rampage (Rank 1)
(29834,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Second Wind (Rank 1)
(29838,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Second Wind (Rank 2)
(29977,	0x00,	3,	0x00C00017,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Combustion
(30003,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Sheen of Zanza
(30160,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Devastation (Rank 1)
(30293,	0x00,	5,	0x00000381,	0x000200C0,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Soul Leech (Rank 1)
(30295,	0x00,	5,	0x00000381,	0x000200C0,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Soul Leech (Rank 2)
(30296,	0x00,	5,	0x00000381,	0x000200C0,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Soul Leech (Rank 3)
(30299,	0x7E,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Nether Protection (Rank 1)
(30301,	0x7E,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Nether Protection (Rank 2)
(30302,	0x7E,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Nether Protection (Rank 3)
(30675,	0x00,	11,	0x00000003,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Overload (Rank 1)
(30678,	0x00,	11,	0x00000003,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Overload (Rank 2)
(30679,	0x00,	11,	0x00000003,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Overload (Rank 3)
(30680,	0x00,	11,	0x00000003,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Overload (Rank 4)
(30681,	0x00,	11,	0x00000003,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lightning Overload (Rank 5)
(30701,	0x1C,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Elemental Absorption (Rank 1)
(30705,	0x1C,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Elemental Absorption (Rank 5)
(30802,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 1)
(30803,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 1)
(30804,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 2)
(30805,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 3)
(30806,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 4)
(30807,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 5)
(30808,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 2)
(30809,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 3)
(30810,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 4)
(30811,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Unleashed Rage (Rank 5)
(30823,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	10.5,	0,	0), -- Shamanistic Rage (Rank 1)
(30881,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	5), -- Nature's Guardian (Rank 1)
(30883,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	5), -- Nature's Guardian (Rank 2)
(30884,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	5), -- Nature's Guardian (Rank 3)
(30885,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	5), -- Nature's Guardian (Rank 4)
(30886,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	5), -- Nature's Guardian (Rank 5)
(30937,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Mark of Shadow
(31124,	0x00,	8,	0x01000006,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blade Twisting (Rank 1)
(31126,	0x00,	8,	0x01000006,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blade Twisting (Rank 2)
(31221,	0x00,	8,	0x00400000,	0x00000000,	0x00000000,	0x00014000,	0x00006001,	0,	0,	0), -- Master of Subtlety (Rank 1)
(31222,	0x00,	8,	0x00400000,	0x00000000,	0x00000000,	0x00014000,	0x00006001,	0,	0,	0), -- Master of Subtlety (Rank 2)
(31223,	0x00,	8,	0x00400000,	0x00000000,	0x00000000,	0x00014000,	0x00006001,	0,	0,	0), -- Master of Subtlety (Rank 3)
(31244,	0x00,	8,	0x003E0000,	0x00000009,	0x00000000,	0x00000000,	0x00000004,	0,	0,	0), -- Quick Recovery (Rank 1)
(31245,	0x00,	8,	0x003E0000,	0x00000009,	0x00000000,	0x00000000,	0x00000004,	0,	0,	0), -- Quick Recovery (Rank 2)
(31394,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Mark of Shadow
(31569,	0x00,	3,	0x00010000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Blink (Rank 1)
(31570,	0x00,	3,	0x00010000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Blink (Rank 2)
(31571,	0x00,	3,	0x00000000,	0x00000022,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Arcane Potency (Rank 1)
(31572,	0x00,	3,	0x00000000,	0x00000022,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Arcane Potency (Rank 2)
(31794,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Focused Mind
(31801,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	20,	0,	0), -- Seal of Vengeance
(31833,	0x00,	10,	0x80000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Light's Grace (Rank 1)
(31835,	0x00,	10,	0x80000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Light's Grace (Rank 2)
(31836,	0x00,	10,	0x80000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Light's Grace (Rank 3)
(31871,	0x00,	10,	0x00000010,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Divine Purpose (Rank 1)
(31872,	0x00,	10,	0x00000010,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Divine Purpose (Rank 2)
(31876,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Wise (Rank 1)
(31877,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Wise (Rank 2)
(31878,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Wise (Rank 3)
(31904,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield
(32385,	0x00,	5,	0x00000001,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Embrace (Rank 1)
(32387,	0x00,	5,	0x00000001,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Embrace (Rank 2)
(32392,	0x00,	5,	0x00000001,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Embrace (Rank 3)
(32393,	0x00,	5,	0x00000001,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Embrace (Rank 4)
(32394,	0x00,	5,	0x00000001,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Embrace (Rank 5)
(32409,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Word: Death
(32587,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Block
(32593,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield (Rank 2)
(32594,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield (Rank 3)
(32642,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Spore Cloud
(32734,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield
(32748,	0x00,	8,	0x00000000,	0x00000001,	0x00000000,	0x00000140,	0x00000000,	0,	0,	0), -- Deadly Throw Interrupt (Rank 5)
(32776,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Redoubt
(32777,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield
(32837,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	45), -- Spell Focus Trigger
(32844,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	0), -- Lesser Heroism
(32885,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Infuriate
(33076,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 1)
(33089,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Vigilance of the Colossus
(33127,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	7,	0,	0), -- Seal of Command
(33142,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Resilience (Rank 1)
(33145,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Resilience (Rank 2)
(33146,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Blessed Resilience (Rank 3)
(33150,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Surge of Light (Rank 1)
(33151,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Surge of Light (Rank 1)
(33154,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Surge of Light (Rank 2)
(33174,	0x00,	6,	0x00000020,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Divine Spirit (Rank 1)
(33182,	0x00,	6,	0x00000020,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Divine Spirit (Rank 2)
(33191,	0x00,	6,	0x00808000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Misery (Rank 1)
(33192,	0x00,	6,	0x00808000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Misery (Rank 2)
(33193,	0x00,	6,	0x00808000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Misery (Rank 3)
(33299,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Coilfang Slave Pens Lvl 70 Boss3a Caster Trinket
(33510,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	5,	0,	0), -- Health Restore
(33648,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Reflection of Torment
(33719,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Perfect Spell Reflection
(33736,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 8)
(33746,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Essence Infused Mushroom
(33757,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Windfury Weapon (Passive) (Rank 1)
(33759,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Power Infused Mushroom
(33881,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Natural Perfection (Rank 1)
(33882,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Natural Perfection (Rank 2)
(33883,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Natural Perfection (Rank 3)
(33953,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	45), -- Essence of Life
(34074,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000003,	0,	0,	0), -- Aspect of the Viper
(34080,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000008,	0,	0,	0), -- Riposte Stance
(34138,	0x00,	11,	0x00000080,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Totem of the Third Wind
(34139,	0x00,	10,	0x40000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Libram of Justice
(34258,	0x00,	10,	0x00000400,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Justice
(34262,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Mercy
(34320,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Call of the Nexus
(34355,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Poison Shield
(34457,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Ferocious Inspiration (Rank 1)
(34497,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Thrill of the Hunt (Rank 1)
(34498,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Thrill of the Hunt (Rank 2)
(34499,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Thrill of the Hunt (Rank 3)
(34500,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Expose Weakness (Rank 1)
(34502,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Expose Weakness (Rank 2)
(34503,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Expose Weakness (Rank 3)
(34584,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Love Struck
(34586,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1.5,	0,	0), -- Romulo's Poison
(34598,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Karazhan Caster Robe
(34749,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000008,	0,	0,	0), -- Recurring Power
(34753,	0x00,	6,	0x00001800,	0x00000004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Holy Concentration (Rank 1)
(34774,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1.5,	0,	20), -- Magtheridon Melee Trinket
(34783,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Spell Reflection
(34827,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield
(34859,	0x00,	6,	0x00001800,	0x00000004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Holy Concentration (Rank 2)
(34860,	0x00,	6,	0x00001800,	0x00000004,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Holy Concentration (Rank 3)
(34914,	0x00,	6,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Touch (Rank 1)
(34916,	0x00,	6,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Touch (Rank 2)
(34917,	0x00,	6,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Touch (Rank 3)
(34935,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	8), -- Backlash (Rank 1)
(34938,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	8), -- Backlash (Rank 2)
(34939,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	8), -- Backlash (Rank 3)
(34950,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Go for the Throat (Rank 1)
(34954,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Go for the Throat (Rank 2)
(35077,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Band of the Eternal Defender
(35080,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1,	0,	60), -- Band of the Eternal Champion
(35083,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Band of the Eternal Sage
(35086,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Band of the Eternal Restorer
(35100,	0x00,	9,	0x00003001,	0x00000000,	0x00000000,	0x00010140,	0x00000000,	0,	0,	0), -- Concussive Barrage (Rank 1)
(35102,	0x00,	9,	0x00003001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Concussive Barrage (Rank 2)
(35103,	0x00,	9,	0x00003001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Concussive Barrage (Rank 3)
(35121,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Nether Power
(36032,	0x00,	3,	0x00000800,	0x00008000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Arcane Blast
(36096,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Spell Reflection
(36111,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- World Breaker
(36541,	0x04,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Curse of Burning Shadows
(37165,	0x00,	8,	0x00200400,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Haste
(37168,	0x00,	8,	0x003E0000,	0x00000009,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Finisher Combo
(37170,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1,	0,	0), -- Free Finisher Chance
(37173,	0x00,	8,	0x2CBC0598,	0x00000106,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Armor Penetration
(37189,	0x00,	10,	0xC0000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	60), -- Recuced Holy Light Cast Time
(37193,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Infused Shield
(37195,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgement Group Heal
(37197,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	45), -- Spell Damage
(37213,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Mana Cost Reduction
(37214,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Energized
(37227,	0x00,	11,	0x000001C0,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	60), -- Improved Healing Wave
(37237,	0x00,	11,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Lightning Bolt Discount
(37247,	0x08,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	45), -- Regain Mana
(37377,	0x20,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Shadowflame
(37379,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Flameshadow
(37384,	0x00,	5,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Corruption and Immolate
(37443,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Crit Bonus Damage
(37514,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Blade Turning
(37516,	0x00,	4,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Revenge Bonus
(37519,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000030,	0,	0,	0), -- Rage Bonus
(37523,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Reinforced Shield
(37528,	0x00,	4,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Overpower Bonus
(37536,	0x00,	4,	0x00010000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Battle Shout
(37568,	0x00,	6,	0x00000800,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Greater Heal Discount
(37594,	0x00,	6,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Greater Heal Refund
(37600,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Offensive Discount
(37601,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Relentlessness
(37603,	0x00,	6,	0x00008000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shadow Word Pain Damage
(37655,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Bonus Mana Regen
(37657,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	3), -- Lightning Capacitor
(38026,	0x01,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000100,	0,	0,	0), -- Viscous Shield
(38031,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Shield Block
(38290,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	1.6,	0,	0), -- Santos' Blessing
(38326,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Crit Threat Reduction Melee
(38327,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Crit Threat Reduction Spell
(38334,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Proc Mana Regen
(38347,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Crit Proc Spell Damage
(38350,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Crit Proc Heal
(38394,	0x00,	5,	0x00000006,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Dot Heals
(38857,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Spell Ground
(39027,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Poison Shield
(39372,	0x30,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Frozen Shadoweave
(39437,	0x04,	5,	0x00001364,	0x000000C0,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Shadowflame Hellfire and RoF
(39442,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000001,	0,	0,	0), -- Aura of Wrath
(39443,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Aura of Wrath
(39530,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Focus
(39958,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0.7,	0,	40), -- Skyfire Swiftness
(40407,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	6,	0,	0), -- Illidan Tank Shield
(40438,	0x00,	6,	0x00008040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Priest Tier 6 Trinket
(40442,	0x00,	7,	0x00000014,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Druid Tier 6 Trinket
(40444,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Black Temple Tank Trinket
(40458,	0x00,	4,	0x02000000,	0x00000601,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Warrior Tier 6 Trinket
(40463,	0x00,	11,	0x00000081,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Shaman Tier 6 Trinket
(40470,	0x00,	10,	0xC0800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Paladin Tier 6 Trinket
(40475,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	3,	0,	0), -- Black Temple Melee Trinket
(40478,	0x00,	5,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Warlock Tier 6 Trinket
(40482,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Mage Tier 6 Trinket
(40485,	0x00,	9,	0x00000000,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Hunter Tier 6 Trinket
(40899,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Felfire Proc
(41034,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Spell Absorption
(41260,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Aviana's Purpose
(41262,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Aviana's Will
(41381,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000100,	0,	0,	0), -- Shell of Life
(41393,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Riposte
(41434,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2,	0,	45), -- The Twin Blades of Azzinoth
(41469,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	7,	0,	0), -- Seal of Command
(41635,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 1)
(41989,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0.5,	0,	0), -- Fists of Fury
(42083,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	45), -- Fury of the Crashing Waves
(42135,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	90), -- Lesser Rune of Warding
(42136,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	90), -- Greater Rune of Warding
(42368,	0x00,	10,	0x40000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Merciless Libram of Justice
(42370,	0x00,	11,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Merciless Totem of the Third WInd
(42770,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Second Wind (Rank 2)
(43019,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 8)
(43020,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Mana Shield (Rank 9)
(43338,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Shamanistic Focus
(43443,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Spell Reflection
(43726,	0x00,	10,	0x40000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vengeful Libram of Justice
(43728,	0x00,	11,	0x00000080,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vengeful Totem of Third WInd
(43737,	0x00,	7,	0x00000000,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Primal Instinct
(43739,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lunar Grace
(43741,	0x00,	10,	0x80000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Light's Grace
(43745,	0x00,	10,	0x00000000,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Crusader's Command
(43748,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Elemental Strength
(43750,	0x00,	11,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Energized
(43819,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Lucidity
(44394,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Incanter's Absorption (Rank 1)
(44395,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Incanter's Absorption (Rank 2)
(44396,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000400,	0,	0,	0), -- Incanter's Absorption (Rank 3)
(44401,	0x00,	3,	0x00200000,	0x00000000,	0x00000000,	0x00000000,	0x00000FFF,	0,	0,	0), -- Missile Barrage
(44404,	0x00,	3,	0x20000021,	0x00009000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Missile Barrage (Rank 1)
(44442,	0x00,	3,	0x00800000,	0x00000040,	0x00000000,	0x00000000,	0x00010000,	0,	0,	1), -- Firestarter (Rank 1)
(44443,	0x00,	3,	0x00800000,	0x00000040,	0x00000000,	0x00000000,	0x00010000,	0,	0,	1), -- Firestarter (Rank 2)
(44445,	0x00,	3,	0x00000013,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Hot Streak (Rank 1)
(44446,	0x00,	3,	0x00000013,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Hot Streak (Rank 2)
(44448,	0x00,	3,	0x00000013,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Hot Streak (Rank 3)
(44449,	0x00,	3,	0x20E21277,	0x00019048,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Burnout (Rank 1)
(44469,	0x00,	3,	0x20E21277,	0x00019048,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Burnout (Rank 2)
(44470,	0x00,	3,	0x20E21277,	0x00019048,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Burnout (Rank 3)
(44471,	0x00,	3,	0x20E21277,	0x00019048,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Burnout (Rank 4)
(44472,	0x00,	3,	0x20E21277,	0x00019048,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Burnout (Rank 5)
(44543,	0x00,	3,	0x00100220,	0x00001000,	0x00000000,	0x00010000,	0x00000000,	0,	7,	0), -- Fingers of Frost (Rank 1)
(44545,	0x00,	3,	0x00100220,	0x00001000,	0x00000000,	0x00010000,	0x00000000,	0,	15,	0), -- Fingers of Frost (Rank 2)
(44546,	0x00,	3,	0x020002A0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Brain Freeze (Rank 1)
(44548,	0x00,	3,	0x020002A0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Brain Freeze (Rank 2)
(44549,	0x00,	3,	0x020002A0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Brain Freeze (Rank 3)
(44745,	0x00,	3,	0x00000000,	0x00000001,	0x00000000,	0x00008000,	0x00002000,	0,	0,	0), -- Shattered Barrier (Rank 1)
(44835,	0x00,	7,	0x00000000,	0x00000080,	0x00000000,	0x00000010,	0x00000000,	0,	0,	0), -- Maim Interrupt
(45054,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	15), -- Augment Pain
(45057,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Evasive Maneuvers
(45234,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Will (Rank 1)
(45243,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Will (Rank 2)
(45244,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Will (Rank 3)
(45354,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Item - Sunwell Dungeon Melee Trinket
(45469,	0x00,	15,	0x00000010,	0x00000000,	0x00000000,	0x00000010,	0x00000000,	0,	0,	0), -- Death Strike
(45481,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Sunwell Exalted Caster Neck
(45482,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Sunwell Exalted Melee Neck
(45483,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Sunwell Exalted Tank Neck
(45484,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	45), -- Sunwell Exalted Healer Neck
(46025,	0x20,	6,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Blackout (Rank 5)
(46092,	0x00,	10,	0x40000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Brutal Libram of Justice
(46098,	0x00,	11,	0x00000080,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Brutal Totem of Third WInd
(46569,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Sunwell Exalted Caster Neck
(46662,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	20), -- Deathfrost
(46832,	0x00,	7,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Moonkin Starfire Bonus
(46854,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Trauma (Rank 1)
(46855,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Trauma (Rank 2)
(46867,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Wrecking Crew (Rank 1)
(46910,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000001,	5.5,	0,	0), -- Furious Attacks (Rank 1)
(46911,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000001,	7.5,	0,	0), -- Furious Attacks (Rank 2)
(46913,	0x00,	4,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Bloodsurge (Rank 1)
(46914,	0x00,	4,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Bloodsurge (Rank 2)
(46915,	0x00,	4,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Bloodsurge (Rank 3)
(46916,	0x00,	4,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Slam!
(46951,	0x00,	4,	0x00000400,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sword and Board (Rank 1)
(46952,	0x00,	0,	0x00000400,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sword and Board (Rank 2)
(46953,	0x00,	0,	0x00000400,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sword and Board (Rank 3)
(47195,	0x00,	5,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Eradication (Rank 1)
(47196,	0x00,	5,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Eradication (Rank 2)
(47197,	0x00,	5,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Eradication (Rank 3)
(47201,	0x00,	5,	0x00000008,	0x00040000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Everlasting Affliction (1)
(47202,	0x00,	5,	0x00000008,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Everlasting Affliction (2)
(47203,	0x00,	5,	0x00000008,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Everlasting Affliction (3)
(47204,	0x00,	5,	0x00000008,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Everlasting Affliction (4)
(47205,	0x00,	5,	0x00000008,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Everlasting Affliction (5)
(47232,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Demonic Empathy (Rank 1)
(47234,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Demonic Empathy (Rank 2)
(47235,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Demonic Empathy (Rank 3)
(47245,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Molten Core (Rank 1)
(47246,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Molten Core (Rank 2)
(47247,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Molten Core (Rank 3)
(47258,	0x00,	5,	0x00000000,	0x00800000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Backdraft (Rank 1)
(47259,	0x00,	5,	0x00000000,	0x00800000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Backdraft (Rank 2)
(47260,	0x00,	5,	0x00000000,	0x00800000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Backdraft (Rank 3)
(47263,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	20), -- Torture (Rank 1)
(47264,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	20), -- Torture (Rank 2)
(47265,	0x20,	5,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	20), -- Torture (Rank 3)
(47509,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Divine Aegis (Rank 1)
(47511,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Divine Aegis (Rank 2)
(47515,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Divine Aegis (Rank 3)
(47516,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Grace (Rank 1)
(47517,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Grace (Rank 2)
(47535,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00014010,	0x00000000,	0,	0,	0), -- Rapture (Rank 1)
(47536,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00014010,	0x00000000,	0,	0,	0), -- Rapture (Rank 2)
(47537,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00014010,	0x00000000,	0,	0,	0), -- Rapture (Rank 3)
(47538,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00014010,	0x00000000,	0,	0,	0), -- Rapture (Rank 4)
(47539,	0x00,	6,	0x00001800,	0x00010000,	0x00000000,	0x00014010,	0x00000000,	0,	0,	0), -- Rapture (Rank 5)
(47549,	0x00,	6,	0x00000000,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Holy Concentration (Rank 1)
(47551,	0x00,	6,	0x00000000,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Holy Concentration (Rank 2)
(47552,	0x00,	6,	0x00000000,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Holy Concentration (Rank 3)
(47555,	0x00,	6,	0x00001800,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Serendipity (Rank 1)
(47556,	0x00,	6,	0x00001800,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Serendipity (Rank 2)
(47557,	0x00,	6,	0x00001800,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Serendipity (Rank 3)
(47569,	0x00,	6,	0x00004000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	50,	0), -- Improved Shadowform (Rank 1)
(47570,	0x00,	6,	0x00004000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	100,	0), -- Improved Shadowform (Rank 2)
(47571,	0x00,	6,	0x00010000,	0x00000000,	0x00000000,	0x00010000,	0x00006000,	0,	50,	0), -- Psychic Horror (Rank 1)
(47572,	0x00,	6,	0x00010000,	0x00000000,	0x00000000,	0x00010000,	0x00006000,	0,	100,	0), -- Psychic Horror (Rank 2)
(47580,	0x00,	6,	0x00000000,	0x00000000,	0x00000040,	0x00000000,	0x00010000,	0,	0,	0), -- Pain and Suffering (Rank 1)
(47581,	0x00,	6,	0x00000000,	0x00000000,	0x00000040,	0x00000000,	0x00010000,	0,	0,	0), -- Pain and Suffering (Rank 2)
(47582,	0x00,	6,	0x00000000,	0x00000000,	0x00000040,	0x00000000,	0x00010000,	0,	0,	0), -- Pain and Suffering (Rank 3)
(48110,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 2)
(48111,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 3)
(48112,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 2)
(48113,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000A02A8,	0x00000000,	0,	0,	0), -- Prayer of Mending (Rank 3)
(48159,	0x00,	6,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Touch (Rank 4)
(48160,	0x00,	6,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Vampiric Touch (Rank 5)
(48483,	0x00,	7,	0x00008800,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Infected Wounds (Rank 1)
(48484,	0x00,	7,	0x00008800,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Infected Wounds (Rank 2)
(48485,	0x00,	7,	0x00008800,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Infected Wounds (Rank 3)
(48496,	0x00,	7,	0x00000060,	0x02000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Living Seed (Rank 1)
(48499,	0x00,	7,	0x00000060,	0x02000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Living Seed (Rank 2)
(48500,	0x00,	7,	0x00000060,	0x02000002,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Living Seed (Rank 3)
(48506,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Earth and Moon (Rank 1)
(48510,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Earth and Moon (Rank 2)
(48511,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Earth and Moon (Rank 3)
(48516,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	30), -- Eclipse (Rank 1)
(48521,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	30), -- Eclipse (Rank 2)
(48525,	0x00,	7,	0x00000005,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	30), -- Eclipse (Rank 3)
(48833,	0x00,	7,	0x00000000,	0x00000440,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Primal Instinct
(48835,	0x00,	10,	0x00000000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Justice
(48837,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Elemental Tenacity
(48951,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 5)
(48952,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Holy Shield (Rank 6)
(48988,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Bloody Vengeance (Rank 1)
(49018,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sudden Doom (Rank 1)
(49137,	0x00,	15,	0x00000000,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Endless Winter (Rank 1)
(49188,	0x00,	15,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Rime (Rank 1)
(49208,	0x00,	15,	0x00440000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Reaping (Rank 1)
(49222,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Bone Shield
(49280,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 10)
(49281,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Lightning Shield (Rank 11)
(49283,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield (Rank 4)
(49284,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield (Rank 5)
(49503,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Bloody Vengeance (Rank 2)
(49504,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Bloody Vengeance (Rank 3)
(49529,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sudden Doom (Rank 2)
(49530,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sudden Doom (Rank 3)
(49531,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sudden Doom (Rank 4)
(49532,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sudden Doom (Rank 5)
(49622,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Bonus Mana Regen
(49657,	0x00,	15,	0x00000000,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Endless Winter (Rank 2)
(50781,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Fate Rune of Primal Energy
(51123,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Killing Machine (Rank 1)
(51127,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Killing Machine (Rank 2)
(51128,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Killing Machine (Rank 3)
(51129,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Killing Machine (Rank 4)
(51130,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Killing Machine (Rank 5)
(51346,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Venture Company Beatdown!
(51349,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Venture Company Beatdown
(51352,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Venture Company Beatdown!
(51359,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	10), -- Venture Company Beatdown
(51466,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Oath (Rank 1)
(51470,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Elemental Oath (Rank 2)
(51474,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Astral Shift (Rank 1)
(51478,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Astral Shift (Rank 2)
(51479,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Astral Shift (Rank 3)
(51528,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	2.5,	0,	0), -- Maelstrom Weapon (Rank 1)
(51529,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	5,	0,	0), -- Maelstrom Weapon (Rank 2)
(51530,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	7.5,	0,	0), -- Maelstrom Weapon (Rank 3)
(51531,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	10,	0,	0), -- Maelstrom Weapon (Rank 4)
(51532,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	12.5,	0,	0), -- Maelstrom Weapon (Rank 5)
(51556,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Awakening (Rank 1)
(51557,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Awakening (Rank 2)
(51558,	0x00,	11,	0x000000C0,	0x00000000,	0x00000010,	0x00000000,	0x00000002,	0,	0,	0), -- Ancestral Awakening (Rank 3)
(51562,	0x00,	11,	0x00000100,	0x00000000,	0x00000010,	0x00000000,	0x00000000,	0,	0,	0), -- Tidal Waves (Rank 1)
(51563,	0x00,	11,	0x00000100,	0x00000000,	0x00000010,	0x00000000,	0x00000000,	0,	0,	0), -- Tidal Waves (Rank 2)
(51564,	0x00,	11,	0x00000100,	0x00000000,	0x00000010,	0x00000000,	0x00000000,	0,	0,	0), -- Tidal Waves (Rank 3)
(51565,	0x00,	11,	0x00000100,	0x00000000,	0x00000010,	0x00000000,	0x00000000,	0,	0,	0), -- Tidal Waves (Rank 4)
(51566,	0x00,	11,	0x00000100,	0x00000000,	0x00000010,	0x00000000,	0x00000000,	0,	0,	0), -- Tidal Waves (Rank 5)
(51625,	0x00,	8,	0x1000A000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Deadly Brew (Rank 1)
(51626,	0x00,	8,	0x1000A000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Deadly Brew (Rank 2)
(51627,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Turn the Tables (Rank 1)
(51628,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Turn the Tables (Rank 2)
(51629,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000070,	0,	0,	0), -- Turn the Tables (Rank 3)
(51634,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Attacks (Rank 1)
(51635,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Attacks (Rank 2)
(51636,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Focused Attacks (Rank 3)
(51664,	0x00,	8,	0x00020000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Cut to the Chase (Rank 1)
(51665,	0x00,	8,	0x00020000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Cut to the Chase (Rank 2)
(51667,	0x00,	8,	0x00020000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Cut to the Chase (Rank 3)
(51668,	0x00,	8,	0x00020000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Cut to the Chase (Rank 4)
(51669,	0x00,	8,	0x00020000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Cut to the Chase (Rank 5)
(51672,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	1), -- Unfair Advantage (Rank 1)
(51674,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	1), -- Unfair Advantage (Rank 2)
(51679,	0x00,	8,	0x00000001,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Throwing Specialization (Rank 2)
(51692,	0x00,	8,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Waylay (Rank 1)
(51696,	0x00,	8,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Waylay (Rank 2)
(51698,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	1), -- Honor Among Thieves (Rank 1)
(51700,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	1), -- Honor Among Thieves (Rank 2)
(51701,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	1), -- Honor Among Thieves (Rank 3)
(51940,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 1)
(51989,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 2)
(52004,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 3)
(52005,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 4)
(52007,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 5)
(52008,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	20,	0), -- Earthliving Weapon (Passive) (Rank 6)
(52020,	0x00,	7,	0x00008000,	0x00100000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Snap and Snarl
(52127,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 1)
(52129,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 2)
(52131,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 3)
(52134,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 4)
(52136,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 5)
(52138,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 6)
(52420,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	30), -- Deflection
(52423,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Retaliation
(52795,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Borrowed Time (Rank 1)
(52797,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Borrowed Time (Rank 2)
(52798,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Borrowed Time (Rank 3)
(52799,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Borrowed Time (Rank 4)
(52800,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Borrowed Time (Rank 5)
(52898,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Spell Damping
(53137,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Abomination's Might (Rank 1)
(53138,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Abomination's Might (Rank 2)
(53215,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Wild Quiver (Rank 1)
(53216,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Wild Quiver (Rank 2)
(53217,	0x00,	9,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Wild Quiver (Rank 3)
(53221,	0x00,	9,	0x00000000,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Steady Shot (Rank 1)
(53222,	0x00,	9,	0x00000000,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Steady Shot (Rank 2)
(53224,	0x00,	9,	0x00000000,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Improved Steady Shot (Rank 3)
(53228,	0x00,	9,	0x00000020,	0x01000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Rapid Recuperation (Rank 1)
(53232,	0x00,	9,	0x00000020,	0x01000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Rapid Recuperation (Rank 2)
(53256,	0x00,	9,	0x00000800,	0x00800001,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Cobra Strikes (Rank 1)
(53259,	0x00,	9,	0x00000800,	0x00800001,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Cobra Strikes (Rank 2)
(53260,	0x00,	9,	0x00000800,	0x00800001,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Cobra Strikes (Rank 3)
(53290,	0x00,	9,	0x00000800,	0x7FFFFFFF,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Hunting Party (Rank 1)
(53291,	0x00,	9,	0x00000800,	0x7FFFFFFF,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Hunting Party (Rank 2)
(53292,	0x00,	9,	0x00000800,	0x7FFFFFFF,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Hunting Party (Rank 3)
(53293,	0x00,	9,	0x00000800,	0x7FFFFFFF,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Hunting Party (Rank 4)
(53294,	0x00,	9,	0x00000800,	0x7FFFFFFF,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Hunting Party (Rank 5)
(53375,	0x00,	10,	0x00000000,	0x00002000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	6), -- Sanctified Wrath (Rank 1)
(53380,	0x00,	10,	0x00800000,	0x00020000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Righteous Vengeance (Rank 1)
(53381,	0x00,	10,	0x00800000,	0x00020000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Righteous Vengeance (Rank 2)
(53382,	0x00,	10,	0x00800000,	0x00020000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Righteous Vengeance (Rank 3)
(53383,	0x00,	10,	0x00800000,	0x00020000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Righteous Vengeance (Rank 4)
(53384,	0x00,	10,	0x00800000,	0x00020000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Righteous Vengeance (Rank 5)
(53486,	0x00,	10,	0x00800000,	0x00028000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- The Art of War (Rank 1)
(53488,	0x00,	10,	0x00800000,	0x00028000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- The Art of War (Rank 2)
(53501,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Sheath of Light (Rank 1)
(53502,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Sheath of Light (Rank 2)
(53503,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Sheath of Light (Rank 3)
(53551,	0x00,	10,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sacred Cleansing (Rank 1)
(53552,	0x00,	10,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sacred Cleansing (Rank 2)
(53553,	0x00,	10,	0x00001000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sacred Cleansing (Rank 3)
(53569,	0x00,	10,	0x00200000,	0x00010000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Infusion of Light (Rank 1)
(53576,	0x00,	10,	0x00200000,	0x00010000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Infusion of Light (Rank 2)
(53601,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	6), -- Sacred Shield (Rank 1)
(53671,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Pure (Rank 1)
(53672,	0x00,	10,	0x00200000,	0x00010000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Infusion of Light
(53673,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Pure (Rank 2)
(53754,	0x00,	5,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00006000,	0,	0,	0), -- Improved Fear (Rank 1)
(53759,	0x00,	5,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0x00006000,	0,	0,	0), -- Improved Fear (Rank 2)
(54149,	0x00,	10,	0x00200000,	0x00010000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Infusion of Light (Rank 2)
(54151,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Pure (Rank 3)
(54154,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Pure (Rank 4)
(54155,	0x00,	10,	0x00800000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Judgements of the Pure (Rank 5)
(54278,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Empowered Imp
(54486,	0x00,	0,	0x20000021,	0x00009000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Missile Barrage (Rank 2)
(54488,	0x00,	0,	0x20000021,	0x00009000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Missile Barrage (Rank 3)
(54489,	0x00,	0,	0x20000021,	0x00009000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Missile Barrage (Rank 4)
(54490,	0x00,	0,	0x20000021,	0x00009000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Missile Barrage (Rank 5)
(54707,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Sonic Awareness (DND)
(54738,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	45), -- Star of Light
(54747,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Burning Determination (Rank 1)
(54749,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Burning Determination (Rank 2)
(54754,	0x00,	7,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Rejuvenation
(54787,	0x00,	3,	0x00000000,	0x00000001,	0x00000000,	0x00008000,	0x00002000,	0,	0,	0), -- Shattered Barrier (Rank 2)
(54808,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	60), -- Sonic Shield
(54841,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Thunder Capacitor
(54936,	0x00,	10,	0x40000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Flash of Light
(54937,	0x00,	10,	0x80000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Holy Light
(54939,	0x00,	10,	0x00008000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Divinity
(55198,	0x00,	11,	0x000001C0,	0x00000000,	0x00000000,	0x00004000,	0x00000002,	0,	0,	0), -- Tidal Force
(55380,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Skyflare Swiftness
(55381,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	15), -- Mana Restore
(55440,	0x00,	11,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Healing Wave
(55620,	0x00,	15,	0x00000001,	0x08000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Night of the Dead (Rank 1)
(55623,	0x00,	15,	0x00000001,	0x08000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Night of the Dead (Rank 2)
(55640,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Lightweave Embroidery
(55666,	0x00,	15,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Desecration (Rank 1)
(55667,	0x00,	15,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Desecration (Rank 2)
(55668,	0x00,	15,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Desecration (Rank 3)
(55669,	0x00,	15,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Desecration (Rank 4)
(55670,	0x00,	15,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Desecration (Rank 5)
(55672,	0x00,	6,	0x00000001,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Glyph of Power Word: Shield
(55677,	0x00,	6,	0x00000000,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Dispel Magic
(55680,	0x00,	6,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Prayer of Healing
(55689,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Glyph of Shadow
(55768,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Darkglow Embroidery
(55776,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Swordguard Embroidery
(56218,	0x00,	5,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Corruption
(56249,	0x00,	5,	0x00000000,	0x00000000,	0x00000400,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Felhunter
(56333,	0x00,	9,	0x00000004,	0x00000000,	0x00000040,	0x00022200,	0x00000000,	0,	0,	0), -- T.N.T. (Rank 1)
(56336,	0x00,	9,	0x00000004,	0x00000000,	0x00000040,	0x00022200,	0x00000000,	0,	0,	0), -- T.N.T. (Rank 2)
(56337,	0x00,	9,	0x00000004,	0x00000000,	0x00000040,	0x00022200,	0x00000000,	0,	0,	0), -- T.N.T. (Rank 3)
(56342,	0x00,	9,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lock and Load (Rank 1)
(56343,	0x00,	9,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lock and Load (Rank 2)
(56344,	0x00,	9,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Lock and Load (Rank 3)
(56355,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Titanium Shield Spike
(56364,	0x00,	3,	0x00000000,	0x01000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Remove Curse
(56372,	0x00,	3,	0x00000000,	0x00000080,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Glyph of Ice Block
(56374,	0x00,	3,	0x00000000,	0x00004000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Glyph of Icy Veins
(56451,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Earth Shield
(56611,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Wrecking Crew (Rank 2)
(56612,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Wrecking Crew (Rank 3)
(56613,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Wrecking Crew (Rank 4)
(56614,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Wrecking Crew (Rank 5)
(56636,	0x00,	4,	0x00000020,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Taste for Blood (Rank 1)
(56637,	0x00,	4,	0x00000020,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Taste for Blood (Rank 2)
(56638,	0x00,	4,	0x00000020,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Taste for Blood (Rank 3)
(56816,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000030,	0,	0,	0), -- Rune Strike
(56821,	0x00,	8,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Glyph of Sinister Strike
(56822,	0x00,	15,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Rime (Rank 2)
(56834,	0x00,	15,	0x00440000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Reaping (Rank 2)
(56835,	0x00,	15,	0x00440000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Reaping (Rank 3)
(57318,	0x00,	10,	0x00000000,	0x00002000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	6), -- Sanctified Wrath
(57345,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Darkmoon Card: Greatness
(57878,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Natural Reaction (Rank 1)
(57880,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Natural Reaction (Rank 2)
(57881,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Natural Reaction (Rank 3)
(57907,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Increased Spirit
(57960,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	3), -- Water Shield (Rank 9)
(58357,	0x00,	4,	0x00000040,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Glyph of Heroic Strike
(58364,	0x00,	4,	0x00000400,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Revenge
(58372,	0x00,	4,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Hamstring
(58386,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Glyph of Overpower
(58426,	0x00,	8,	0x00400000,	0x00000000,	0x00000000,	0x00014000,	0x00006001,	0,	0,	0), -- Overkill
(58435,	0x00,	5,	0x00000002,	0x00000100,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pandemic (Rank 1)
(58436,	0x00,	5,	0x00000002,	0x00000100,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pandemic (Rank 2)
(58437,	0x00,	5,	0x00000002,	0x00000100,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pandemic (Rank 3)
(58616,	0x00,	15,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Blood Boil
(58620,	0x00,	15,	0x00000000,	0x00004000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Chains of Ice
(58626,	0x00,	15,	0x02000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Death Grip
(58631,	0x00,	15,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Icy Touch
(58642,	0x00,	15,	0x00000000,	0x08000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Scourge Strike
(58644,	0x00,	15,	0x00000000,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Frost Strike
(58647,	0x00,	15,	0x00000000,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Frost Strike
(58676,	0x00,	15,	0x00000000,	0x00000008,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Vampiric Blood
(58677,	0x00,	15,	0x00002000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Death's Embrace
(58872,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Damage Shield (Rank 1)
(58874,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000040,	0,	0,	0), -- Damage Shield (Rank 2)
(58901,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Tears of Anguish
(59057,	0x00,	15,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Rime (Rank 3)
(59088,	0x00,	4,	0x00000000,	0x00000002,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Spell Reflection
(59089,	0x00,	4,	0x00000000,	0x00000002,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0), -- Improved Spell Reflection
(59176,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Spell Damping
(59327,	0x00,	15,	0x08000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Glyph of Rune Tap
(59725,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000800,	0,	0,	0), -- Spell Reflection
(60132,	0x00,	15,	0x00000000,	0x08020000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Oblit/Scourge Strike Runic Power Up
(60170,	0x00,	5,	0x00000006,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Corruption Triggers Crit
(60172,	0x00,	5,	0x00040000,	0x00000000,	0x00000000,	0x00000000,	0x00010000,	0,	0,	0), -- Life Tap Bonus Spirit
(60176,	0x00,	4,	0x00000020,	0x00000010,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Bleed Cost Reduction
(60442,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Bandit's Insignia
(60493,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Dying Curse
(60529,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Forethought Talisman
(60537,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Soul of the Dead
(60564,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Savage Gladiator's Totem of Survival
(60571,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Hateful Gladiator's Totem of Survival
(60572,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Deadly Gladiator's Totem of Survival
(60573,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 4 Gladiator's Totem of Survival
(60574,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 5 Gladiator's Totem of Survival
(60575,	0x00,	11,	0x90100000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 6 Gladiator's Totem of Survival
(60617,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000020,	0,	0,	0), -- Parry
(60710,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Savage Gladiator's Idol of Steadfastness
(60717,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	100,	0), -- Hateful Gladiator's Idol of Steadfastness
(60719,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Deadly Gladiator's Idol of Steadfastness
(60722,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 4 Gladiator's Idol of Steadfastness
(60724,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 5 Gladiator's Idol of Steadfastness
(60726,	0x00,	7,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- LK Arena 6 Gladiator's Idol of Steadfastness
(60770,	0x00,	11,	0x00000001,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Totem of the Elemental Plane
(60818,	0x00,	10,	0x00000000,	0x00000200,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Libram of Reciprocation
(60826,	0x00,	15,	0x01400000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Sigil of Haunted Dreams
(61188,	0x00,	5,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Chaotic Mind
(61257,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x000202A8,	0x00010000,	0,	0,	0), -- Runic Power Back on Snare/Root (Rank 5)
(61324,	0x00,	10,	0x00000000,	0x00020000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Justice
(61345,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Nature's Grace
(61346,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Nature's Grace
(61356,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000002,	0,	0,	0), -- Invigorating Earthsiege Diamond Passive
(61618,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	45), -- Tentacles
(61846,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Aspect of the Dragonhawk (Rank 1)
(61847,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Aspect of the Dragonhawk (Rank 2)
(61848,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000010,	0,	0,	0), -- Aspect of the Dragonhawk
(62147,	0x00,	15,	0x00000002,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Icy Touch Defense Increase
(62459,	0x00,	15,	0x00000004,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0); -- Chains of Ice Frost Rune Refresh (Rank 3)

-- --------
-- ENCHANT PROC
-- --------
DROP TABLE IF EXISTS `spell_enchant_proc_data`;
CREATE TABLE `spell_enchant_proc_data` (
  `entry` INT(10) UNSIGNED NOT NULL,
  `customChance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `PPMChance` FLOAT UNSIGNED NOT NULL DEFAULT '0', 
  `procEx` FLOAT UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Spell enchant proc data';

INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES 
(2, 0, 8.8,0), -- Frostbrand Weapon
(12, 0, 8.8,0), -- Frostbrand Weapon
(524, 0, 8.8,0), -- Frostbrand Weapon
(1667, 0, 8.8,0), -- Frostbrand Weapon
(1668, 0, 8.8,0), -- Frostbrand Weapon
(2635, 0, 8.8,0), -- Frostbrand Weapon
(3782, 0, 8.8,0), -- Frostbrand Weapon
(3783, 0, 8.8,0), -- Frostbrand Weapon
(3784, 0, 8.8,0); -- Frostbrand Weapon

-- --------
-- SPELL AFFECT
-- --------

DROP TABLE IF EXISTS `spell_affect`;
CREATE TABLE `spell_affect` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `effectId` tinyint(3) unsigned NOT NULL default '0',
  `SpellClassMask0` int(5) unsigned NOT NULL default '0',
  `SpellClassMask1` int(5) unsigned NOT NULL default '0',
  `SpellClassMask2` int(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`effectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_affect` (`entry`, `effectId`, `SpellClassMask0`, `SpellClassMask1`, `SpellClassMask2`) VALUES
(44544,0,685904631,1151048,0); -- Fingers of frost

-- --------
-- PET
-- --------
INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4) VALUES
(15352, 36213, 0, 0, 0), # Greater Earth Elemental
(15438, 57984, 12470, 13376, 0), # Greater Fire Elemental
(29264, 58861, 58875, 58867, 58857), # Spirit Wolf
(510, 31707, 33395, 0, 0) # Water Elemental
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4);

-- Three-seat mammoth
UPDATE creature_template SET VehicleId = 312 WHERE entry IN (31857,31858,31861,31862,32212,32213,32633,32640);

-- --------
-- Death Knight
-- --------
update creature_template set spell5=51890 where entry = 28511; -- Eye of Acherus flight

DELETE FROM `spell_script_target` WHERE entry IN
(51859, 48743);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(51859, 1, 28525), -- siphon of archerus
(51859, 1, 28542),
(51859, 1, 28543),
(51859, 1, 28544),
(48743, 1, 26125); -- Death pact

update creature_template set minlevel=50,maxlevel=52,minhealth=2215,maxhealth=2317,faction_A=2084,faction_H=2084,mindmg=50,maxdmg=50 where entry=28528; -- ghoul

-- taxi
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN ('29501', '29488');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
('29488', '54568', '12670', '1', '3'),
('29501', '54575', '12670', '1', '3');

DELETE FROM `spell_script_target` WHERE entry IN (52124);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52124, 1, 28655);
UPDATE `creature_template` SET spell1=52372,spell2=52373,spell3=52374,spell4=52375 WHERE `entry`=28406;

-- death charger
DELETE FROM spell_area WHERE spell = 52693;
INSERT INTO spell_area (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
(52693, 4298, 12687, 1, 12687, 0, 0, 0, 1);

-- Horses for quest 12680 / not sure if its offilike
UPDATE creature_template SET `VehicleId`=200 WHERE `entry` IN (28605,28606,28607);

-- Vehicle and summon spell(summon npc 28788) for Acherus Deathcharger
UPDATE creature_template SET `spell1`=52362, `VehicleId`=200 WHERE `entry`=28782;

-- gift of harvester
DELETE FROM `spell_script_target` WHERE entry IN
(52479);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52479,1,28819),
(52479,1,28822);


replace into creature_questrelation (id,quest) VALUES (28377,12701);
replace into creature_involvedrelation (id,quest) VALUES (28377,12701);
replace into creature_involvedrelation (id,quest) VALUES (28914,12723);
replace into creature_questrelation (id,quest) VALUES (28914,12724);
replace into creature_involvedrelation (id,quest) VALUES (28914,12724);
replace into creature_questrelation (id,quest) VALUES (28913,12725);
replace into creature_involvedrelation (id,quest) VALUES (28912,12725);
replace into creature_questrelation (id,quest) VALUES (28912,12727);
replace into creature_involvedrelation (id,quest) VALUES (28913,12727);

-- ship cannon
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (28833,28887);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28833, 52447, 12701, 3, 3),
(28887, 52447, 12701, 3, 3);

UPDATE creature_template SET spell1=52435,spell2=52576,spell5=52588,VehicleId=68,speed=0 WHERE entry IN (28833,28887);
UPDATE creature_template SET spell1=52211 WHERE entry=28864;

DELETE FROM `spell_script_target` WHERE entry IN
(52576);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52576,1,28834),
(52576,1,28886);


-- frostbrood vanquisher
update creature_template set maxhealth = 133525, minhealth = 133525, maxmana = 51360, minmana = 51360, spell1 = 53114, spell2 = 53112, spell3=53110, VehicleId = 156 where entry = 28670;


-- --------
-- NAXXARAMAS
-- --------
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN
(28732,54097,-29865,-55053,-28169,28059,39088,-28059,-39088,28062,39090,28084,
39091,-28084,-39091,28085,39093);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 28732,-28798,  1, 'Widow\'s Embrace - Frenzy'),
( 54097,-54100,  1, 'Widow\'s Embrace - Frenzy (H)'),
(-29865, 55594,  0, 'Deathbloom'),
(-55053, 55601,  0, 'Deathbloom (H)'),
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud'),
( 28059,-28084,  1, 'Positive Charge - Negative Charge'),
(-28059,-29659,  0, 'Positive Charge'),
# ( 28062,-29659,  0, 'Positive Charge'),
( 28084,-28059,  1, 'Negative Charge - Positive Charge'),
(-28084,-29660,  0, 'Negative Charge'),
# ( 28085,-29660,  0, 'Negative Charge'),
( 39088,-39091,  1, 'Positive Charge - Negative Charge'),
(-39088,-29659,  0, 'Positive Charge'),
# ( 39090,-29659,  0, 'Positive Charge'),
( 39091,-39088,  1, 'Negative Charge - Positive Charge'),
(-39091,-39092,  0, 'Negative Charge');
# ( 39093,-39092,  0, 'Negative Charge');

INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, ''), # Grobbulus Cloud (H)
(16697, 28158, 128, ''), # Void Zone
(29379, 54362, 128, '')  # Void Zone (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

INSERT INTO creature_template (entry, baseattacktime, spell1, flags_extra, scriptname) VALUES
(16474, 1000, 28547, 128, 'trigger_periodic'), # Blizzard (Sapphiron)
(30000, 1000, 55699, 128, ''), # Blizzard (Sapphiron) (H)
(16697, 1000, 28865, 128, 'trigger_periodic'), # Void Zone (Lady Blaumeux)
(16129, 10000, 27812, 128, 'trigger_periodic') # Shadow Fissure (Kel'thezad)
ON DUPLICATE KEY UPDATE
baseattacktime = VALUES(baseattacktime),
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29912);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `cast_flags`) VALUES
(29912, 55479, 0, 1); # Obedience Crystal - Force Obedience

DELETE FROM `spell_script_target` WHERE `entry` IN
(28732,54097,55479,
27892,27893,27928,27929,27935,27936);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(28732, 1, 15953), # Widow's Embrace
(54097, 1, 15953), # Widow's Embrace
(55479, 1, 16803), # Force Obedience - Death Knight Understudy
# (29105, 1, 16803), # Hopeless - Death Knight Understudy
(27892, 1, 16060), # To Anchor 1 - Gothik
(27893, 1, 16060), # To Anchor 2 - Gothik
(27928, 1, 16060), # To Anchor 1 - Gothik
(27929, 1, 16060), # To Anchor 2 - Gothik
(27935, 1, 16060), # To Anchor 1 - Gothik
(27936, 1, 16060); # To Anchor 2 - Gothik

INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8) VALUES
(16573, 15284, 28991, 28969, 34970, 0, 0, 0, 28864), # Crypt Guard
(29256, 15284, 28991, 56098, 34970, 0, 0, 0, 28864), # Crypt Guard (H)
(16506, 54095, 0, 0, 0, 0, 0, 0, 28732), # Naxxramas Worshipper
(29274, 54096, 0, 0, 0, 0, 0, 0, 54097), # Naxxramas Worshipper (H)
(17055, 54121, 0, 0, 0, 0, 0, 0, 0), # Maexxna Spiderling
(29279, 28776, 0, 0, 0, 0, 0, 0, 0), # Maexxna Spiderling (H)
(16486, 28622, 0, 0, 0, 0, 0, 0, 0), # Web Wrap
(30183, 28622, 0, 0, 0, 0, 0, 0, 0), # Web Wrap (H)
(16984, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior
(29632, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior (H)
(16983, 32736, 30138, 0, 0, 0, 0, 0, 0), # Plagued Champion
(29632, 32736, 54889, 0, 0, 0, 0, 0, 0), # Plagued Champion (H)
(16981, 15496, 54890, 0, 0, 0, 0, 0, 0), # Plagued Guardian
(29632, 15496, 54891, 0, 0, 0, 0, 0, 0), # Plagued Guardian (H)
(16286, 0, 0, 0, 0, 0, 0, 0, 29232), # Spore
(30068, 0, 0, 0, 0, 0, 0, 0, 29232), # Spore (H)
(16290, 28156, 0, 0, 0, 0, 0, 0, 0), # Fallout Slime
(29388, 54367, 0, 0, 0, 0, 0, 0, 0), # Fallout Slime (H)
(16360, 29307, 0, 0, 0, 0, 0, 0, 0), # Zombie Chow
(30303, 29307, 0, 0, 0, 0, 0, 0, 0), # Zombie Chow (H)
(16803, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy
(29941, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy (H)
(16124, 55604, 0, 0, 0, 0, 0, 0, 27892), # Unrelenting Trainee
(16125, 27825, 0, 0, 0, 0, 0, 0, 27928), # Unrelenting Death Knight
(16126, 27831, 55606, 0, 0, 0, 0, 0, 27935), # Unrelenting Rider
(16127, 27989, 0, 0, 0, 0, 0, 0, 0), # Spectral Trainee
(16148, 56408, 0, 0, 0, 0, 0, 0, 0), # Spectral Death Knight
(16150, 27994, 55648, 55606, 0, 0, 0, 0, 0), # Spectral Rider
(16149, 27993, 0, 0, 0, 0, 0, 0, 0), # Spectral Horse
(29985, 55645, 0, 0, 0, 0, 0, 0, 27892), # Unrelenting Trainee (H)
(29986, 27825, 0, 0, 0, 0, 0, 0, 27928), # Unrelenting Death Knight (H)
(29987, 55638, 55608, 0, 0, 0, 0, 0, 27935), # Unrelenting Rider (H)
(30264, 56407, 0, 0, 0, 0, 0, 0, 0), # Spectral Trainee (H)
(29990, 56408, 0, 0, 0, 0, 0, 0, 0), # Spectral Death Knight (H)
(29988, 55646, 27995, 55608, 0, 0, 0, 0, 0), # Spectral Rider (H)
(29989, 27993, 0, 0, 0, 0, 0, 0, 0) # Spectral Horse (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4),
spell5 = VALUES(spell5),
spell6 = VALUES(spell6),
spell7 = VALUES(spell7),
spell8 = VALUES(spell8);

# Spore
UPDATE `creature_template` SET `minlevel`='80',`maxlevel`='80',`faction_A`='21',`faction_H`='21' WHERE entry IN (16286,30068);


-- --------
-- WINTERGRASP
-- --------

DELETE FROM `game_event` WHERE `entry` IN (50,51);
INSERT INTO `game_event` (`entry`, `description`, `world_event`) VALUES
(50, 'Wintergrasp Alliance Defence', 5),
(51, 'Wintergrasp Horde Defence', 5);

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

update creature_template set maxhealth = 30000, minhealth = 30000, speed = 2, spell1=50025, spell2=50989, VehicleId = 36 where entry = 27881;
update creature_template set maxhealth = 50000, minhealth = 50000, speed = 1.6, spell1=50896, spell2=50652, VehicleId = 106 where entry = 28094;
update creature_template set maxhealth = 75000, minhealth = 75000, speed = 1, spell1=51678, VehicleId = 117 where entry IN (28312,32627);
update creature_template set maxhealth = 50000, minhealth = 50000, spell1=51362, VehicleId = 116 where entry IN (28319,32629);

update creature_template set scriptname = "npc_demolisher_engineerer" where entry in (30400,30499);

UPDATE creature_template SET VehicleId = 174 WHERE entry IN (31125,31722);
