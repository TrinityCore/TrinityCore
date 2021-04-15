/*ALTER TABLE db_version CHANGE COLUMN required_7133_02_mangos_spell_loot_template required_7141_01_mangos_instance_template bit;*/

ALTER TABLE instance_template ADD maxPlayersHeroic tinyint(3) unsigned NOT NULL default '0' AFTER maxPlayers;

UPDATE instance_template SET maxPlayersHeroic = maxPlayers;

DELETE FROM instance_template WHERE map IN (533,615,616,624);
INSERT INTO instance_template VALUES
(533,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(615,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(616,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(624,0,80,0,10,25,0,NULL,NULL,NULL,NULL,'');
