/*ALTER TABLE db_version CHANGE COLUMN required_7156_01_mangos_spell_proc_event required_7168_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('learn','unlearn');
INSERT INTO `command` VALUES
('learn',3,'Syntax: .learn #spell [all]\r\n\r\nSelected character learn a spell of id #spell. If \'all\' provided then all ranks learned.'),
('unlearn',3,'Syntax: .unlearn #spell [all]\r\n\r\nUnlearn for selected player a spell #spell.  If \'all\' provided then all ranks unlearned.');
