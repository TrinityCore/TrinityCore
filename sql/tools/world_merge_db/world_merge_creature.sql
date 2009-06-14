-- --------
-- creature_template
-- --------

DROP TABLE IF EXISTS merge_creature_template;
CREATE TABLE merge_creature_template
SELECT * FROM world2.creature_template WHERE entry NOT IN (SELECT DISTINCT entry FROM creature_template);

ALTER TABLE merge_creature_template ADD INDEX entry (entry);

ALTER TABLE merge_creature_template ADD COLUMN spell5 mediumint(8) unsigned NOT NULL default '0' AFTER spell4;
ALTER TABLE merge_creature_template ADD COLUMN spell6 mediumint(8) unsigned NOT NULL default '0' AFTER spell5;
ALTER TABLE merge_creature_template ADD COLUMN spell7 mediumint(8) unsigned NOT NULL default '0' AFTER spell6;
ALTER TABLE merge_creature_template ADD COLUMN spell8 mediumint(8) unsigned NOT NULL default '0' AFTER spell7;
ALTER TABLE merge_creature_template ADD COLUMN VehicleId mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER PetSpellDataId;

INSERT creature_template SELECT * FROM merge_creature_template;


-- --------
-- creature_model_info
-- --------

DROP TABLE IF EXISTS merge_creature_model_info;
CREATE TABLE merge_creature_model_info
SELECT * FROM world2.creature_model_info WHERE modelid NOT IN (SELECT DISTINCT modelid FROM creature_model_info);

ALTER TABLE merge_creature_model_info ADD INDEX modelid (modelid);

INSERT creature_model_info SELECT * FROM merge_creature_model_info;


-- --------
-- creature
-- --------

DROP TABLE IF EXISTS merge_creature;
CREATE TABLE merge_creature
(guid_new INT NOT NULL AUTO_INCREMENT PRIMARY KEY)
SELECT * FROM world2.creature WHERE id NOT IN (SELECT DISTINCT id FROM creature);

ALTER TABLE merge_creature ADD INDEX guid (guid);
UPDATE merge_creature SET guid = guid_new + (SELECT MAX(guid) FROM creature);
UPDATE `merge_creature`, `creature_template` SET 

`merge_creature`.`curhealth`=`creature_template`.`minhealth`,`merge_creature`.`curmana`=`creature_template`.`minmana` WHERE `merge_creature`.`id`=`creature_template`.`entry` and 

`creature_template`.`RegenHealth` = '1';
ALTER TABLE merge_creature DROP COLUMN guid_new;

INSERT creature SELECT * FROM merge_creature;


