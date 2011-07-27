DROP TABLE IF EXISTS `lottery_winners`;
CREATE TABLE `lottery_winners` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(12) NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `bet` longtext NOT NULL,
  `betPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `cash` varchar(12) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `lottery_bets`;
CREATE TABLE `lottery_bets` (
  `id` int(10) unsigned NOT NULL DEFAULT '1',
  `name` varchar(12) NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `bet` longtext NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `lottery`;
CREATE TABLE `lottery` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `number_1` int(10) unsigned NOT NULL DEFAULT '0',
  `number_2` int(10) unsigned NOT NULL DEFAULT '0',
  `number_3` int(10) unsigned NOT NULL DEFAULT '0',
  `number_4` int(10) unsigned NOT NULL DEFAULT '0',
  `number_5` int(10) unsigned NOT NULL DEFAULT '0',
  `jackpot` int(10) unsigned NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

DELETE FROM game_event WHERE eventEntry = 132;
INSERT INTO game_event VALUES 
(132, "2011-01-31 20:00:00", "2020-12-31 06:00:00", 1440, 1, 0, "Lottery", 0);

DELETE FROM `creature_template` WHERE (`entry` = '99013');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (99013, 0, 0, 0, 0, 0, 491, 491, 523, 523, '"Везунчик" Угрюмм', 'worldofwarcraft.by lottery', '', 0, 85, 85, 2, 35, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1.4, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1024, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_lottery', 1);

DELETE FROM `trinity_string` where `entry` IN ('11005', '11006', '11007');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11005', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот, который на данный момент составляет %f золотых монет, разыгран не был.|r');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11006', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот в %f золотых монет выигран игроком %s.|r');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11007', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот в %f золотых монет разделило %u игроков.|r');

DELETE FROM `config` WHERE `name` LIKE 'Lottery%';
INSERT INTO `config` VALUES ('Lottery.Enable', '1', '1', '1', '1', '');
INSERT INTO `config` VALUES ('Lottery.BetCost', '500000', '500000', null, '500000', '');
INSERT INTO `config` VALUES ('Lottery.MaxNumber', '30', '30', null, '30', '');
INSERT INTO `config` VALUES ('Lottery.MinUserLVL', '60', '60', null, '60', '');
INSERT INTO `config` VALUES ('Lottery.BpU', '1', '1', '1', '1', 'Bet per User. One player can make only one bet.');
