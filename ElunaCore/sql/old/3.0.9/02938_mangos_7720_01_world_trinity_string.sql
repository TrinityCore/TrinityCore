/*ALTER TABLE db_version CHANGE COLUMN required_7714_01_mangos_command required_7720_01_mangos_mangos_string bit;*/

DELETE FROM trinity_string WHERE entry IN(557,558,559);
INSERT INTO trinity_string VALUES
(557,'%s level up you to (%i)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(558,'%s level down you to (%i)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(559,'%s reset your level progress.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
