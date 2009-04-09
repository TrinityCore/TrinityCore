ALTER TABLE db_version CHANGE COLUMN required_7643_01_mangos_db_version required_7643_02_mangos_mangos_string bit;

DELETE FROM mangos_string WHERE entry IN(59);
INSERT INTO mangos_string VALUES
(59,'Using creature EventAI: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
