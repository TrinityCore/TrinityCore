ALTER TABLE `spell_proc_event`
  CHANGE COLUMN `procFlags` `procFlags` int(11) unsigned NOT NULL default '0';

/* on attack miss,dodge,parry and block */
UPDATE `spell_proc_event` 
  SET `procFlags` = 3288334336 WHERE `entry` = 26107;

/* on attack dodge,parry */
DELETE FROM `spell_proc_event` WHERE `entry` IN ( 37519 );
INSERT INTO `spell_proc_event` VALUES 
(37519,0,0,0,0,67108864,0);
