DROP TABLE IF EXISTS `beastmaster`;

CREATE TABLE `beastmaster` (
  `entry` INT(5) NOT NULL DEFAULT '0' COMMENT 'Pet entry number',
  `cat_number` INT(5) NOT NULL DEFAULT '0' COMMENT '0-normal pet 1-exotic pet 2-pet spell',
  `tokenOrGold` TINYINT(1) DEFAULT '0' COMMENT '0 = gold 1 = token',
  `cost` INT(10) NOT NULL DEFAULT '0' COMMENT 'Amount in copper if tokenOrGold is 0 else number of tokens',
  `token` INT(10) NOT NULL DEFAULT '0' COMMENT 'Token entry number (item_template.entry)',
  `name` VARCHAR(255) DEFAULT NULL COMMENT 'Name of pet or name of pet spell',
  `spell` INT(10) NOT NULL DEFAULT '0' COMMENT 'Spell entry number.',
  PRIMARY KEY (`entry`)
) ENGINE=INNODB DEFAULT CHARSET=utf8 COMMENT='Beastmaster System by LordPsyan';

/*Data for the table `beastmaster` */

INSERT INTO `beastmaster` (`entry`, `cat_number`, `tokenOrGold`, `cost`, `token`, `name`, `spell`) VALUES
('1','0','1','1000','0','Spider','2349'),
('2','0','0','1000','0','Bat','28233'),
('3','0','0','1000','0','Bear','29319'),
('4','0','0','1000','0','Boar','29996'),
('5','0','0','1000','0','Cat','28097'),
('6','0','0','1000','0','Carrion Bird','26838'),
('7','0','0','1000','0','Crab','24478'),
('8','0','0','1000','0','Crocolisk','1417'),
('9','0','0','1000','0','Dragonhawk','27946'),
('10','0','0','1000','0','Gorilla','28213'),
('11','0','0','1000','0','Hyena','13036'),
('12','0','0','1000','0','Moth','27421'),
('13','0','0','1000','0','Owl','23136'),
('14','0','0','1000','0','Raveger','17199'),
('15','0','0','1000','0','Raptor','14821'),
('16','0','0','1000','0','Serpent','28358'),
('17','0','0','1000','0','Bug','28085'),
('18','0','0','1000','0','Strider','22807'),
('19','0','0','1000','0','Scorpid','9698'),
('20','1','0','1000','0','Chimaera','21879'),
('21','1','0','1000','0','Core Hound','21108'),
('22','1','0','1000','0','Devilsaur','20931'),
('23','1','0','1000','0','Rhino','30445'),
('24','1','0','1000','0','Silithid','5460'),
('25','1','0','1000','0','Worm','30148'),
('26','1','0','1000','0','Loque\'nahak','32517'),
('27','1','0','1000','0','Skoll','35189'),
('28','1','0','1000','0','Gondria','33776'),
('29','2','1','1000','0','Feed Pet','6991'),
('30','2','0','1000','0','Call Pet','883'),
('31','2','0','1000','0','Dismiss Pet','2641'),
('32','2','0','1000','0','Mend Pet','136'),
('33','2','0','1000','0','Revive Pet','982');

-- Beastmaster NPC

DELETE FROM `creature_template` WHERE `entry` = 99990;

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('99990','0','0','0','0','0','26789','0','0','0','LordPsyan','Beastmaster Service','','0','80','80','0','35','129','1','1.14286','0.75','1','0','1500','0','1','1','1','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','1','1','0','0','1','0','0','Npc_Beastmaster','0');

-- Sample npc vendor data for beastmaster

DELETE FROM `npc_vendor` WHERE `entry` = 99990;

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
('99990','0','4540','0','0','0'),
('99990','0','4541','0','0','0'),
('99990','0','4542','0','0','0');
