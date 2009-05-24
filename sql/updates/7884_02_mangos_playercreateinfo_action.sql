ALTER TABLE db_version CHANGE COLUMN required_7884_01_mangos_playercreateinfo_spell required_7884_02_mangos_playercreateinfo_action bit;

DELETE FROM playercreateinfo_action WHERE action = '28734';
UPDATE playercreateinfo_action SET button = '3' WHERE race = '10' AND class IN ('8', '9', '5', '2', '3') AND button = '4';
UPDATE playercreateinfo_action SET button = '4' WHERE race = '10' AND class = '4' AND button = '5';
