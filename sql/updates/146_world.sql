update creature_template set spell1 = 40836, flags_extra = 128, scriptname = '' where entry = 23336;

DROP TABLE IF EXISTS `spell_linked_spell`;
CREATE TABLE `spell_linked_spell` (
  `spell_trigger` int(10) NOT NULL,
  `spell_effect` int(10) NOT NULL default '0',
  `type` smallint(3) unsigned NOT NULL default '0',
  `comment` text NOT NULL default '',
  PRIMARY KEY (`spell_trigger`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (44008, 45265, 1, 'Static Disruption Visual');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (42052, 40118, 0, 'Volcanic Geyser Visual');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (-41914, 41915, 0, 'Summon Parasitic Shadowfiend\r\n');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (46021, 44852, 1, 'Spectral Realm Aura');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (-46021, 44867, 0, 'Spectral Exhaustion');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (-30410, 44032, 0, 'Manticron Cube Mind Exhaustion');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (-45934, 7, 0, 'Dark Fiend Suicide');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45661, 45665, 1, 'Encapsulate\r\n');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (40604, 40616, 1, 'Fel Rage Aura');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (40616, 41625, 1, 'Fel Rage Aura');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (41292, 42017, 1, 'Aura of Suffering');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (-41292, -42017, 0, 'Aura of Suffering');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45347, -45348, 1, 'Remove Flame Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45348, -45347, 1, 'Remove Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45248, 45347, 1, 'Apply Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45329, 45347, 1, 'Apply Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45256, 45347, 1, 'Apply Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45270, 45347, 1, 'Apply Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45342, 45348, 1, 'Apply Flame Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (46771, 45348, 1, 'Apply Flame Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45271, 45347, 1, 'Apply Dark Touched');

INSERT INTO spell_linked_spell
   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES
   (45246, 45348, 1, 'Apply Flame Touched');