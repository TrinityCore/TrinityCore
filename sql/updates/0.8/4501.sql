-- Add definitly a very usefull index to this creature table
-- If this sql file fails because the index already exists, comment the following line
ALTER TABLE `creature` ADD INDEX `index_id` (id);

-- Add suport to creature table for equipment and model overwritting
ALTER TABLE `creature` 
    ADD COLUMN `equipment_id` int(11) NOT NULL default '0' AFTER `map`,
    ADD COLUMN `modelid` int(11) unsigned default '0' AFTER `map`;

-- Creation of creature_model_info table
DROP TABLE IF EXISTS `creature_model_info`;
CREATE TABLE `creature_model_info` (
  `modelid` int(11) unsigned NOT NULL default '0',
  `bounding_radius` float NOT NULL default '0',
  `combat_reach` float NOT NULL default '0',
  `gender` tinyint(2) unsigned NOT NULL default '2',
  `modelid_other_gender` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`modelid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Creature System (Model related info)';

-- Correct possible db problems
UPDATE `creature_template` SET `bounding_radius`=0 WHERE `bounding_radius` IS NULL;
UPDATE `creature_template` SET `combat_reach`=0 WHERE `combat_reach` IS NULL;
UPDATE `creature_template` SET `modelid_m`=0 WHERE `modelid_m` IS NULL;
UPDATE `creature_template` SET `modelid_f`=0 WHERE `modelid_f` IS NULL;

-- All models defined in creature_template are used to build the table
INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT DISTINCT `modelid_m` FROM `creature_template`;
INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT DISTINCT `modelid_f` FROM `creature_template`;

-- Copy the data from creature_template to creature_model_info
UPDATE `creature_model_info`,`creature_template` SET
    `creature_model_info`.`bounding_radius`=`creature_template`.`bounding_radius`,
    `creature_model_info`.`combat_reach`=`creature_template`.`combat_reach`,
    `creature_model_info`.`modelid_other_gender`=`creature_template`.`modelid_f`
    WHERE `creature_model_info`.`modelid`=`creature_template`.`modelid_m`;

UPDATE `creature_model_info`,`creature_template` SET
    `creature_model_info`.`bounding_radius`=`creature_template`.`bounding_radius`,
    `creature_model_info`.`combat_reach`=`creature_template`.`combat_reach`,
    `creature_model_info`.`modelid_other_gender`=`creature_template`.`modelid_m`
    WHERE `creature_model_info`.`modelid`=`creature_template`.`modelid_f`;

-- Some changes in fields of creature_template
ALTER TABLE `creature_template`
    CHANGE `modelid_m` `modelid_A` int(11) unsigned NOT NULL default '0',
    CHANGE `modelid_f` `modelid_H` int(11) unsigned NOT NULL default '0',
    ADD COLUMN `faction_H` int(4) unsigned NOT NULL default '0' AFTER `faction`,
    ADD COLUMN `equipment_id` int(11) unsigned NOT NULL default '0' AFTER `RacialLeader`,
    ADD COLUMN `RegenHealth` tinyint(1) unsigned NOT NULL default '1' AFTER `RacialLeader`,
    DROP COLUMN `bounding_radius`,
    DROP COLUMN `combat_reach`,
    -- This index is temporary and enable the population of creature_equip_template to be fast
    ADD INDEX `idx_tmp` (`equipmodel1`,`equipmodel2`,`equipmodel3`,`equipinfo1`,`equipinfo2`,`equipinfo3`,`equipslot1`,`equipslot2`,`equipslot3`);

ALTER TABLE `creature_template`
    CHANGE `faction` `faction_A` int(4) unsigned NOT NULL default '0';

-- Create table creature_equip_template with temporary auto-increment key
DROP TABLE IF EXISTS `creature_equip_template`;
CREATE TABLE `creature_equip_template` (
  `entry` int(11) unsigned NOT NULL auto_increment COMMENT 'Unique entry',
  `equipmodel1` int(11) unsigned NOT NULL default '0',
  `equipmodel2` int(11) unsigned NOT NULL default '0',
  `equipmodel3` int(11) unsigned NOT NULL default '0',
  `equipinfo1` int(11) unsigned NOT NULL default '0',
  `equipinfo2` int(11) unsigned NOT NULL default '0',
  `equipinfo3` int(11) unsigned NOT NULL default '0',
  `equipslot1`  int(11) NOT NULL default '0',
  `equipslot2`  int(11) NOT NULL default '0',
  `equipslot3`  int(11) NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COMMENT='Creature System (Equipment)';

-- Fill the creature_equip_template table with values from creature_template
INSERT INTO `creature_equip_template` (`equipmodel1`,`equipmodel2`,`equipmodel3`,`equipinfo1`,`equipinfo2`,`equipinfo3`,`equipslot1`,`equipslot2`,`equipslot3`) 
    (SELECT DISTINCT `equipmodel1`,`equipmodel2`,`equipmodel3`,`equipinfo1`,`equipinfo2`,`equipinfo3`,`equipslot1`,`equipslot2`,`equipslot3` FROM `creature_template` WHERE `equipmodel1`<>0 OR `equipmodel2`<>0 OR `equipmodel3`<>0);

-- Then add to creature_template the id generated for equipements
UPDATE `creature_template`,`creature_equip_template` SET
    `creature_template`.`equipment_id`=`creature_equip_template`.`entry`
    WHERE `creature_template`.`equipmodel1`=`creature_equip_template`.`equipmodel1` AND
        `creature_template`.`equipmodel2`=`creature_equip_template`.`equipmodel2` AND
        `creature_template`.`equipmodel3`=`creature_equip_template`.`equipmodel3` AND
        `creature_template`.`equipinfo1`=`creature_equip_template`.`equipinfo1` AND
        `creature_template`.`equipinfo2`=`creature_equip_template`.`equipinfo2` AND
        `creature_template`.`equipinfo3`=`creature_equip_template`.`equipinfo3` AND
        `creature_template`.`equipslot1`=`creature_equip_template`.`equipslot1` AND
        `creature_template`.`equipslot2`=`creature_equip_template`.`equipslot2` AND
        `creature_template`.`equipslot3`=`creature_equip_template`.`equipslot3`;

-- Remove all equipment fields from creature_template, this will remove the temporary index
ALTER TABLE `creature_template`
    DROP COLUMN `equipmodel1`,
    DROP COLUMN `equipmodel2`,
    DROP COLUMN `equipmodel3`,
    DROP COLUMN `equipinfo1`,
    DROP COLUMN `equipinfo2`,
    DROP COLUMN `equipinfo3`,
    DROP COLUMN `equipslot1`,
    DROP COLUMN `equipslot2`,
    DROP COLUMN `equipslot3`;

-- Make all modelid and faction fields filled
UPDATE `creature_template` SET `modelid_A`=`modelid_H` WHERE `modelid_A`=0 AND `modelid_H`<>0;
UPDATE `creature_template` SET `modelid_H`=`modelid_A` WHERE `modelid_H`=0 AND `modelid_A`<>0;
UPDATE `creature_template` SET `faction_A`=`faction_H` WHERE `faction_A`=0 AND `faction_H`<>0;
UPDATE `creature_template` SET `faction_H`=`faction_A` WHERE `faction_H`=0 AND `faction_A`<>0;

-- Finaly remove the no more necessary auto-increment from creature_equip_template
ALTER TABLE `creature_equip_template`
    CHANGE `entry` `entry` int(11) unsigned NOT NULL default '0' COMMENT 'Unique entry';
