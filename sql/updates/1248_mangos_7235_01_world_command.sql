ALTER TABLE db_version CHANGE COLUMN required_7230_02_mangos_spell_bonus_data required_7235_01_mangos_command bit;

DELETE FROM `command` WHERE `name` = 'reset achievements';
INSERT INTO `command` VALUES
('reset achievements',3,'Syntax: .reset achievements [$playername]\r\n\r\nReset achievements data for selected or named (online or offline) character. Achievements for persistance progress data like completed quests/etc re-filled at reset. Achievements for events like kills/casts/etc will lost.');
