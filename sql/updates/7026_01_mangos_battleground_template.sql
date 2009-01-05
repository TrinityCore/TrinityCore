ALTER TABLE db_version CHANGE COLUMN required_7024_01_mangos_spell_chain required_7026_01_mangos_battleground_template bit;

DELETE FROM battleground_template WHERE id IN (9,10,11);
INSERT INTO battleground_template VALUES
(9,0,0,0,0,1367,0,1368,0),
(10,5,5,10,80,1362,0,1363,0),
(11,5,5,10,80,1364,0,1365,0);
