ALTER TABLE `guild` CHANGE `EmblemStyle` `EmblemStyle` INT( 5 ) NOT NULL DEFAULT '0',
CHANGE `EmblemColor` `EmblemColor` INT( 5 ) NOT NULL DEFAULT '0',
CHANGE `BorderStyle` `BorderStyle` INT( 5 ) NOT NULL DEFAULT '0',
CHANGE `BorderColor` `BorderColor` INT( 5 ) NOT NULL DEFAULT '0',
CHANGE `BackgroundColor` `BackgroundColor` INT( 5 ) NOT NULL DEFAULT '0';

ALTER TABLE `item_template` ADD `unk_203` INT(10) NOT NULL default '0' AFTER `sheath`;
ALTER TABLE `item_template` CHANGE `Unknown1` `Map` INT( 10 ) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `BagFamily` `BagFamily` INT( 10 ) NOT NULL DEFAULT '0' AFTER `Map`;
ALTER TABLE `item_template` ADD `TotemCategory` INT( 10 ) NOT NULL DEFAULT '0' AFTER `BagFamily`,
ADD `socketColor_1` INT( 10 ) NOT NULL DEFAULT '0' AFTER `TotemCategory`,
ADD `socketContent_1` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketColor_1`,
ADD `socketColor_2` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketContent_1`,
ADD `socketContent_2` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketColor_2`,
ADD `socketColor_3` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketContent_2`,
ADD `socketContent_3` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketColor_3`,
ADD `socketBonus` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketContent_3`,
ADD `GemProperties` INT( 10 ) NOT NULL DEFAULT '0' AFTER `socketBonus`,
ADD `ExtendedCost` INT( 10 ) NOT NULL DEFAULT '0' AFTER `GemProperties`,
ADD `RequiredDisenchantSkill` INT( 10 ) NOT NULL DEFAULT '-1' AFTER `ExtendedCost`;

UPDATE `item_template` SET `TotemCategory` = '11' WHERE `entry` = '2901';
UPDATE `item_template` SET `TotemCategory` = '1' WHERE `entry` = '7005';
UPDATE `item_template` SET `TotemCategory` = '1' WHERE `entry` = '12709';
UPDATE `item_template` SET `TotemCategory` = '2' WHERE `entry` = '5175';
UPDATE `item_template` SET `TotemCategory` = '4' WHERE `entry` = '5176';
UPDATE `item_template` SET `TotemCategory` = '5' WHERE `entry` = '5177';
UPDATE `item_template` SET `TotemCategory` = '3' WHERE `entry` = '5178';

ALTER TABLE `character_kill` CHANGE `guid` `guid` SMALLINT( 4 ) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier' ;
ALTER TABLE `character_kill` DROP `type` ;
ALTER TABLE `character` DROP `highest_rank` , DROP `standing` , DROP `rating` ;

insert into `playercreateinfo_spell` values
(10,2,7355,'Stuck',1),
(10,3,7355,'Stuck',1),
(10,4,7355,'Stuck',1),
(10,5,7355,'Stuck',1),
(10,8,7355,'Stuck',1),
(10,9,7355,'Stuck',1),
(11,1,7355,'Stuck',1),
(11,2,7355,'Stuck',1),
(11,3,7355,'Stuck',1),
(11,5,7355,'Stuck',1),
(11,7,7355,'Stuck',1),
(11,8,7355,'Stuck',1);

ALTER TABLE `group` CHANGE `leaderGuid` `leaderGuid` INT( 20 ) NOT NULL ,
CHANGE `looterGuid` `looterGuid` INT( 20 ) NOT NULL ;
ALTER TABLE `group_member` CHANGE `leaderGuid` `leaderGuid` INT( 20 ) NOT NULL ,
CHANGE `memberGuid` `memberGuid` INT( 20 ) NOT NULL ;
ALTER TABLE `group` ADD `mainTank` INT(20) NOT NULL AFTER `leaderGuid` ,
ADD `mainAssistant` INT(20) NOT NULL AFTER `mainTank` ;

CREATE TABLE `looking_for_group` (
  `guid` int(12) unsigned NOT NULL default '0',
  `slot` smallint(2) unsigned NOT NULL default '0',
  `entry` int(12) unsigned NOT NULL default '0',
  `type` smallint(2) unsigned NOT NULL default '0',
  `lfg_type` smallint(2) unsigned NOT NULL default '0',
  `comment` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

UPDATE `creature_template` SET `npcflag`='33' WHERE `name`='Spirit Healer';

ALTER TABLE `playercreateinfo` DROP `displayID`;

ALTER TABLE `quest_template`
CHANGE `OfferRewardEmote` `IncompleteEmote` int(11) unsigned NOT NULL default '0',
CHANGE `RequestItemsEmote` `CompleteEmote` int(11) unsigned NOT NULL default '1';
ALTER TABLE `quest_template`
ADD `DetailsEmote1` int(11) NOT NULL default '0' AFTER `PointOpt`,
ADD `DetailsEmote2` int(11) NOT NULL default '0' AFTER `DetailsEmote1`,
ADD `DetailsEmote3` int(11) NOT NULL default '0' AFTER `DetailsEmote2`,
ADD `DetailsEmote4` int(11) NOT NULL default '0' AFTER `DetailsEmote3`,
ADD `OfferRewardEmote1` int(11) NOT NULL default '0' AFTER `CompleteEmote`,
ADD `OfferRewardEmote2` int(11) NOT NULL default '0' AFTER `OfferRewardEmote1`,
ADD `OfferRewardEmote3` int(11) NOT NULL default '0' AFTER `OfferRewardEmote2`,
ADD `OfferRewardEmote4` int(11) NOT NULL default '0' AFTER `OfferRewardEmote3`;

ALTER TABLE `item_template` ADD `unk0` INT( 10 ) NOT NULL DEFAULT '-1' AFTER `subclass`;

ALTER TABLE `group` ADD `lootThreshold` tinyint(4) NOT NULL AFTER `looterGuid`;

ALTER TABLE `creature_template` CHANGE `equipslot1` `equipslot1` INTEGER NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE `equipslot2` `equipslot2` INTEGER NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE `equipslot3` `equipslot3` INTEGER NOT NULL DEFAULT '0';

CREATE TABLE `arena_team` (
  `guid` int(10) unsigned NOT NULL default '0',
  `slot` tinyint(3) unsigned NOT NULL default '0',
  `name` char(255) NOT NULL,
  `type` tinyint(3) unsigned NOT NULL default '0',
  `rank` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `arena_team_member` (
  `guid` int(10) unsigned NOT NULL default '0',
  `teamslot` tinyint(3) unsigned NOT NULL default '0',
  `teamguid` int(10) unsigned NOT NULL default '0',
  `rating` int(10) unsigned NOT NULL default '0',
  `games` int(10) unsigned NOT NULL default '0',
  `wins` int(10) unsigned NOT NULL default '0',
  `played` int(10) unsigned NOT NULL default '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `gameobject` WHERE `map`='489';
UPDATE `gameobject_template` SET `flags` = '0', `type` = '26' WHERE `entry` IN (179785, 179786);
UPDATE `gameobject_template` SET `flags` = '0' WHERE `entry` IN (179830, 179831);

alter table `creature` change `state` `DeathState` tinyint(3) unsigned not null default '0';

alter table `creature_template` drop `mount`;

INSERT INTO `command` ( `name` , `security` , `help` ) VALUES ('modify titles', '1', 'Syntax:\n.modify titles #mask\n.titles #mask\n\nAllows user to use all titles from #mask.\n\n #mask=0 disables the title-choose-field');
INSERT INTO `command` ( `name` , `security` , `help` ) VALUES ('titles', '1', 'Syntax:\n.modify titles #mask\n.titles #mask\n\nAllows user to use all titles from #mask.\n\n #mask=0 disables the title-choose-field');
