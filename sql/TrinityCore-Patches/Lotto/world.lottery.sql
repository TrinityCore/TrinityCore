DELETE FROM `trinity_string` where `entry` IN ('11010', '11011', '11012');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('11010', '|cffff0000[Lottery]: The contest is over! Total bets involved: %u. The winning numbers: %s. The Jackpot contains %u gold and was not paid.|r');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('11011', '|cffff0000[Lottery]: The contest is over! Total bets involved: %u. The winning numbers: %s.  %s hit the Jackpot and wins %u gold! Congratulations!|r');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('11012', '|cffff0000[Lottery]: The contest is over! Total bets involved: %u. The winning numbers: %s.  %u players hit the Jackpot and everyone wins %u gold. Congratulations!|r');

DROP TABLE IF EXISTS `lottery_winners`;
CREATE TABLE `lottery_winners` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(12) NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `bet` longtext NOT NULL,
  `betPoints` int(10) unsigned NOT NULL DEFAULT '0',
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
  `numbers` longtext NOT NULL,
  `jackpot` int(10) unsigned NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


REPLACE INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(132, '2013-08-21 20:00:00', '2020-12-31 06:00:00', 1440, 1, 0, 'Lottery', 0, 2);


DELETE FROM `creature_template` WHERE (`entry`=900010);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
('900010', '0', '0', '0', '0', '0', '7993', '0', '0', '0', 'Lotty', '- by GoN -', NULL, '0', '80', '80', '0', '35', '1', '1', '1.14286', '0.75', '0', '0', '1400', '1900', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1', '1', '1', '1', '1', '1', '0', '0', '1', '0', '0', 'npc_lottery', '12340');
