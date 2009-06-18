DROP TABLE IF EXISTS `access_requirement`;
CREATE TABLE `access_requirement` (
  `id` bigint(20) unsigned NOT NULL COMMENT 'Identifier',
  `level_min` tinyint(3) unsigned NOT NULL default '0',
  `level_max` tinyint(3) unsigned NOT NULL default '0',
  `item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `item2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_failed_text` TEXT NULL DEFAULT NULL,
  `heroic_quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_quest_failed_text` TEXT NULL DEFAULT NULL,
  `comment` TEXT NULL DEFAULT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Access Requirements';

ALTER TABLE `instance_template`
 DROP COLUMN `levelMin`,
 DROP COLUMN `levelMax`,
 ADD COLUMN `access_id` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `reset_delay`;

ALTER TABLE `areatrigger_teleport`
 DROP COLUMN `required_level`,
 DROP COLUMN `required_item`,
 DROP COLUMN `required_item2`,
 DROP COLUMN `heroic_key`,
 DROP COLUMN `heroic_key2`,
 DROP COLUMN `heroic_required_quest_done`,
 DROP COLUMN `heroic_required_failed_quest_text`,
 DROP COLUMN `required_quest_done`,
 DROP COLUMN `required_failed_text`,
 ADD COLUMN `access_id` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `name`;

INSERT INTO `access_requirement` VALUES
('1','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Shadowfang Keep (33)'),
('2','15','0','0','0','0','0','0',NULL,'0',NULL,'instance The Stockade (34)'),
('3','10','0','0','0','0','0','0',NULL,'0',NULL,'instance The Deadmines (36)'),
('4','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Wailing Caverns (43)'),
('5','15','0','0','0','0','0','0',NULL,'0',NULL,'instance Razorfen Kraul (47)'),
('6','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackfathom Deeps (48)'),
('7','30','0','0','0','0','0','0',NULL,'0',NULL,'instance Uldaman (70)'),
('8','15','0','0','0','0','0','0',NULL,'0',NULL,'instance Gnomeregan (90)'),
('9','35','0','0','0','0','0','0',NULL,'0',NULL,'instance Sunken Temple (109)'),
('10','25','0','0','0','0','0','0',NULL,'0',NULL,'instance Razorfen Downs (129)'),
('11','20','0','0','0','0','0','0',NULL,'0',NULL,'instance Scarlet Monastery (189)'),
('12','35','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Farrak (209)'),
('13','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackrock Spire (229)'),
('14','40','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackrock Depths (230)'),
('15','55','0','16309','0','0','0','0',NULL,'0',NULL,'instance Onyxia\'s Lair (249)'),
('16','66','0','0','0','30635','0','10285','You can\'t enter Black Morass until you rescue Thrall from Durnholde Keep.','0',NULL,'instance The Black Morass (269)'),
('17','45','0','13704','0','0','0','0',NULL,'0',NULL,'instance Scholomance (289)'),
('18','50','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Gurub (309)'),
('19','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Stratholme (329)'),
('20','30','0','0','0','0','0','0',NULL,'0',NULL,'instance Maraudon (349)'),
('21','8','0','0','0','0','0','0',NULL,'0',NULL,'instance Ragefire Chasm (389)'),
('22','50','0','0','0','0','0','7487',NULL,'0',NULL,'instance Molten Core (409)'),
('23','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Dire Maul (429)'),
('24','60','0','0','0','0','0','7761',NULL,'0',NULL,'instance Blackwing Lair (469)'),
('25','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Ruins of Ahn\'Qiraj (509)'),
('26','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Temple of Ahn\'Qiraj (531)'),
('27','68','0','0'/*'24490'*/,'0','0','0','0',NULL,'0',NULL,'instance Karazhan (532)'),
('28','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Naxxramas (533)'),
('29','70','0','0','0','0','0','10445',NULL,'0',NULL,'instance Hyjal Summit (534)'),
('30','55','0','0'/*'28395'*/,'0','30637','30622','0',NULL,'0',NULL,'instance The Shattered Halls (540)'),
('31','55','0','0','0','30637','30622','0',NULL,'0',NULL,'instance The Blood Furnace (542)'),
('32','55','0','0','0','30637','30622','0',NULL,'0',NULL,'instance Hellfire Ramparts (543)'),
('33','65','0','0','0','0','0','0',NULL,'0',NULL,'instance Magtheridon\'s Lair (544)'),
('34','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Steamvault (545)'),
('35','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Underbog (546)'),
('36','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Slave Pens (547)'),
('37','70','0','0','0','0','0','0'/*'10901'*/,NULL,'0',NULL,'instance Serpentshrine Cavern (548)'),
('38','70','0','0'/*'31704'*/,'0','0','0','0',NULL,'0',NULL,'instance The Eye (550)'),
('39','68','0','0'/*'31084'*/,'0','30634','0','0',NULL,'0',NULL,'instance The Arcatraz (552)'),
('40','68','0','0','0','30634','0','0',NULL,'0',NULL,'instance The Botanica (553)'),
('41','68','0','0','0','30634','0','0',NULL,'0',NULL,'instance The Mechanar (554)'),
('42','65','0','27991','0','30633','0','0',NULL,'0',NULL,'instance Shadow Labyrinth (555)'),
('43','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Sethekk Halls (556)'),
('44','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Mana-Tombs (557)'),
('45','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Auchenai Crypts (558)'),
('46','66','0','0','0','30635','0','0',NULL,'0',NULL,'instance Old Hillsbrad Foothills (560)'),
('47','70','0','32649','0','0','0','0',NULL,'0',NULL,'instance Black Temple (564)'),
('48','65','0','0','0','0','0','0',NULL,'0',NULL,'instance Gruul\'s Lair (565)'),
('49','70','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Aman (568)'),
('50','70','0','0','0','0','0','0',NULL,'0',NULL,'instance Sunwell Plateau (580)'),
('51','70','0','0','0','0','0','0',NULL,'11492','Heroic Difficulty requires completion of the "Hard to Kill" quest.','instance Magisters\' Terrace (585)'),
('52','58','0','0','0','0','0','0',NULL,'0',NULL,'Dark Portal');

UPDATE `instance_template` SET `access_id` = '1' WHERE `map` = '33';
UPDATE `instance_template` SET `access_id` = '2' WHERE `map` = '34';
UPDATE `instance_template` SET `access_id` = '3' WHERE `map` = '36';
UPDATE `instance_template` SET `access_id` = '4' WHERE `map` = '43';
UPDATE `instance_template` SET `access_id` = '5' WHERE `map` = '47';
UPDATE `instance_template` SET `access_id` = '6' WHERE `map` = '48';
UPDATE `instance_template` SET `access_id` = '7' WHERE `map` = '70';
UPDATE `instance_template` SET `access_id` = '8' WHERE `map` = '90';
UPDATE `instance_template` SET `access_id` = '9' WHERE `map` = '109';
UPDATE `instance_template` SET `access_id` = '10' WHERE `map` = '129';
UPDATE `instance_template` SET `access_id` = '11' WHERE `map` = '189';
UPDATE `instance_template` SET `access_id` = '12' WHERE `map` = '209';
UPDATE `instance_template` SET `access_id` = '13' WHERE `map` = '229';
UPDATE `instance_template` SET `access_id` = '14' WHERE `map` = '230';
UPDATE `instance_template` SET `access_id` = '15' WHERE `map` = '249';
UPDATE `instance_template` SET `access_id` = '16' WHERE `map` = '269';
UPDATE `instance_template` SET `access_id` = '17' WHERE `map` = '289';
UPDATE `instance_template` SET `access_id` = '18' WHERE `map` = '309';
UPDATE `instance_template` SET `access_id` = '19' WHERE `map` = '329';
UPDATE `instance_template` SET `access_id` = '20' WHERE `map` = '349';
UPDATE `instance_template` SET `access_id` = '21' WHERE `map` = '389';
UPDATE `instance_template` SET `access_id` = '22' WHERE `map` = '409';
UPDATE `instance_template` SET `access_id` = '23' WHERE `map` = '429';
UPDATE `instance_template` SET `access_id` = '24' WHERE `map` = '469';
UPDATE `instance_template` SET `access_id` = '25' WHERE `map` = '509';
UPDATE `instance_template` SET `access_id` = '26' WHERE `map` = '531';
UPDATE `instance_template` SET `access_id` = '27' WHERE `map` = '532';
UPDATE `instance_template` SET `access_id` = '28' WHERE `map` = '533';
UPDATE `instance_template` SET `access_id` = '29' WHERE `map` = '534';
UPDATE `instance_template` SET `access_id` = '30' WHERE `map` = '540';
UPDATE `instance_template` SET `access_id` = '31' WHERE `map` = '542';
UPDATE `instance_template` SET `access_id` = '32' WHERE `map` = '543';
UPDATE `instance_template` SET `access_id` = '33' WHERE `map` = '544';
UPDATE `instance_template` SET `access_id` = '34' WHERE `map` = '545';
UPDATE `instance_template` SET `access_id` = '35' WHERE `map` = '546';
UPDATE `instance_template` SET `access_id` = '36' WHERE `map` = '547';
UPDATE `instance_template` SET `access_id` = '37' WHERE `map` = '548';
UPDATE `instance_template` SET `access_id` = '38' WHERE `map` = '550';
UPDATE `instance_template` SET `access_id` = '39' WHERE `map` = '552';
UPDATE `instance_template` SET `access_id` = '40' WHERE `map` = '553';
UPDATE `instance_template` SET `access_id` = '41' WHERE `map` = '554';
UPDATE `instance_template` SET `access_id` = '42' WHERE `map` = '555';
UPDATE `instance_template` SET `access_id` = '43' WHERE `map` = '556';
UPDATE `instance_template` SET `access_id` = '44' WHERE `map` = '557';
UPDATE `instance_template` SET `access_id` = '45' WHERE `map` = '558';
UPDATE `instance_template` SET `access_id` = '46' WHERE `map` = '560';
UPDATE `instance_template` SET `access_id` = '47' WHERE `map` = '564';
UPDATE `instance_template` SET `access_id` = '48' WHERE `map` = '565';
UPDATE `instance_template` SET `access_id` = '49' WHERE `map` = '568';
UPDATE `instance_template` SET `access_id` = '50' WHERE `map` = '580';
UPDATE `instance_template` SET `access_id` = '51' WHERE `map` = '585';
UPDATE `areatrigger_teleport` SET `access_id` = '52' WHERE `id` IN ('4352','4354');
