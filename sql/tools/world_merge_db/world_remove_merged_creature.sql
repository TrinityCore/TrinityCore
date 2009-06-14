DELETE FROM creature WHERE guid IN (SELECT guid FROM merge_creature);
DROP TABLE IF EXISTS merge_creature;

DELETE FROM creature_model_info WHERE modelid IN (SELECT modelid FROM merge_creature_model_info);
DROP TABLE IF EXISTS merge_creature_model_info;

DELETE FROM creature_template WHERE entry IN (SELECT entry FROM merge_creature_template);
DROP TABLE IF EXISTS merge_creature_template;
