ALTER TABLE db_version CHANGE COLUMN required_7560_01_mangos_gameobject_template required_7565_01_mangos_mangos_string bit;

DELETE FROM mangos_string WHERE entry IN(1010,1011,1012,1013,1014);
INSERT INTO mangos_string VALUES
(1010,'|    Account    |       Character      |       IP        | GM | Expansion |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1011,'|<Error>        | %20s |<Error>          |<Er>| <Error>   |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1012,'===========================================================================',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1013,'|%15s| %20s | %15s |%4d| %9d |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1014,'No online players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
