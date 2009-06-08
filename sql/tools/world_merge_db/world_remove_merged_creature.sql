DELETE FROM creature WHERE guid IN (SELECT guid FROM merge_creature);
DROP TABLE IF EXISTS merge_creature;
