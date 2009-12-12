-- mangos rev 8412
-- ALTER TABLE db_version CHANGE COLUMN required_8399_01_mangos_spell_elixir required_8412_01_mangos_mangos_string bit;

DELETE FROM trinity_string WHERE entry IN(512,513);
INSERT INTO trinity_string VALUES
(512,'%d - |cffffffff|Hitem:%d:0:0:0:0:0:0:0:0|h[%s]|h|r ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(513,'%d - |cffffffff|Hquest:%d:%d|h[%s]|h|r %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
