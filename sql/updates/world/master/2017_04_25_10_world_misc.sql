UPDATE `pet_stats` SET `type`='2' WHERE (`entry`='54983');

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `autocast`, `quest_start_status`) VALUES ('59073', '4714', '14091', '1', '74');
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `terrainswapmap`, `comment`) VALUES ('4714', '3', '1', '638', 'Worgen Start loc');

INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_start_status`) VALUES ('68481', '4714', '14375', '1', '74');
INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_start_status`) VALUES ('68481', '4786', '14375', '1', '74');

UPDATE `spell_linked_spell` SET `chance`='32409' WHERE (`spell_trigger`='118') AND (`spell_effect`='-3') AND (`type`='0') AND (`hastalent`='56375') AND (`actiontype`='2');
UPDATE `spell_linked_spell` SET `chance`='32409' WHERE (`spell_trigger`='19503') AND (`spell_effect`='-3') AND (`type`='0') AND (`hastalent`='119407') AND (`actiontype`='2');
UPDATE `spell_linked_spell` SET `chance`='32409' WHERE (`spell_trigger`='3355') AND (`spell_effect`='-3') AND (`type`='2') AND (`hastalent`='119407') AND (`actiontype`='2');
UPDATE `spell_linked_spell` SET `chance`='32409' WHERE (`spell_trigger`='2094') AND (`spell_effect`='-3') AND (`type`='0') AND (`hastalent`='91299') AND (`actiontype`='2');

DELETE FROM `spell_script_names` WHERE (`spell_id`='115078') AND (`ScriptName`='spell_monk_glyph_of_paralysis');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `actiontype`, `comment`) VALUES ('115078', '-3', '125755', '32409', '1', '2', 'Glyph of Paralysis');

DELETE FROM `spell_proc_event` WHERE (`entry`='57934') AND (`effectmask`='7');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `caster`, `hastalent`, `chance`, `hitmask`, `actiontype`, `comment`) VALUES ('115268', '-3', '2', '56249', '32409', '1', '2', 'Mesmerize');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `caster`, `hastalent`, `chance`, `hitmask`, `actiontype`, `comment`) VALUES ('6358', '-3', '2', '56249', '32409', '1', '2', 'Seduction');

UPDATE `spell_trigger` SET `bp0`='0', `bp1`='120000', `aura`='84963' WHERE (`spell_id`='63225') AND (`spell_trigger`='84963') AND (`option`='21') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');

UPDATE `spell_proc_event` SET `SpellFamilyMask0`='1040' WHERE (`entry`='117967') AND (`effectmask`='7');
UPDATE `spell_proc_event` SET `procFlags`='16' WHERE (`entry`='117967') AND (`effectmask`='7');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `bp0`, `effectmask`, `comment`) VALUES ('117967', '115307', '21', '6000', '2', 'Brewmaster : Training');
UPDATE `spell_trigger` SET `target`='1' WHERE (`spell_id`='117967') AND (`spell_trigger`='115307') AND (`option`='21') AND (`effectmask`='2') AND (`aura`='0') AND (`check_spell_id`='0');

INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `effectmask`, `comment`) VALUES ('117967', '-100784', '1', 'Brewmaster : Training');
INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `effectmask`, `comment`) VALUES ('117967', '-100787', '2', 'Brewmaster : Training');

DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2016');
DELETE FROM `spell_group` WHERE (`id`='2016') AND (`spell_id`='31884');

DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2011');
DELETE FROM `spell_group` WHERE (`id`='2011') AND (`spell_id`='49016');

DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2013');
DELETE FROM `spell_group` WHERE (`id`='2013') AND (`spell_id`='12292');

DELETE FROM `spell_group` WHERE (`id`='2014') AND (`spell_id`='12042');
DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2014');

DELETE FROM `spell_group` WHERE (`id`='2015') AND (`spell_id`='34471');
DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2015');

DELETE FROM `spell_group` WHERE (`id`='2017') AND (`spell_id`='-2012');
DELETE FROM `spell_group` WHERE (`id`='2012') AND (`spell_id`='57933');

DELETE FROM `spell_group_stack_rules` WHERE (`group_id`='2017');

DELETE FROM `spell_trigger` WHERE (`spell_id`='124081') AND (`spell_trigger`='124101') AND (`option`='20') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
UPDATE `spell_trigger` SET `spell_trigger`='-124081', `bp0`='4' WHERE (`spell_id`='124081') AND (`spell_trigger`='125033') AND (`option`='20') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');