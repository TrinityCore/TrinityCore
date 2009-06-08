DROP TABLE IF EXISTS merge_creature;

CREATE TABLE merge_creature
(guid_new INT NOT NULL AUTO_INCREMENT PRIMARY KEY)
SELECT * FROM world2.creature WHERE id NOT IN (SELECT DISTINCT id FROM creature);

ALTER TABLE merge_creature ADD INDEX guid (guid);

UPDATE merge_creature SET guid = guid_new + (SELECT MAX(guid) FROM creature);

ALTER TABLE merge_creature DROP COLUMN guid_new;

INSERT creature SELECT * FROM merge_creature;
