/*ALTER TABLE db_version CHANGE COLUMN required_7149_01_mangos_spell_proc_event required_7150_01_mangos_playercreateinfo_spell bit;*/

DELETE FROM `playercreateinfo_spell` WHERE Spell = 58284;

INSERT INTO `playercreateinfo_spell` VALUES
(1,9,58284,'Chaos Bolt Passive'),
(2,9,58284,'Chaos Bolt Passive'),
(5,9,58284,'Chaos Bolt Passive'),
(7,9,58284,'Chaos Bolt Passive'),
(10,9,58284,'Chaos Bolt Passive');