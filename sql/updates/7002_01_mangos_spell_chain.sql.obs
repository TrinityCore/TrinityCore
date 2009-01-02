ALTER TABLE db_version CHANGE COLUMN required_6970_01_mangos_playercreateinfo required_7002_01_mangos_spell_chain bit;

DELETE FROM `spell_chain` WHERE `spell_id` IN (51490,59156,59158,59159);

INSERT INTO `spell_chain` VALUES
(51490,0,51490,1,0),
(59156,51490,51490,2,0),
(59158,59156,51490,3,0),
(59159,59158,51490,4,0);
