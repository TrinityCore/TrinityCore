DROP TABLE IF EXISTS `spell_linked_spell`;
CREATE TABLE `spell_linked_spell` (
  `spell_trigger` int(10) NOT NULL,
  `spell_effect` int(10) NOT NULL default '0',
  `type` smallint(3) unsigned NOT NULL default '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`spell_trigger`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `spell_linked_spell` DROP PRIMARY KEY;

INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44008, 45265, 1, 'Static Disruption Visual');
INSERT INTO spell_linked_spell   (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES   (-30410, 44032, 0, 'Manticron Cube Mind Exhaustion');

-- class
delete from `spell_linked_spell` where `spell_trigger` in ('15237','15430','15431','27799','27800','27801','25331');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('15237','23455','0','Holy Nova (rank1)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('15430','23458','0','Holy Nova (rank2)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('15431','23459','0','Holy Nova (rank3)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('27799','27803','0','Holy Nova (rank4)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('27800','27804','0','Holy Nova (rank5)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('27801','27805','0','Holy Nova (rank6)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('25331','25329','0','Holy Nova (rank7)');
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (-19386, -24132, -24133, -27068, -49011, -49012);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-19386, 24131, 0, 'Wyvern Sting');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-24132, 24134, 0, 'Wyvern Sting');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-24133, 24135, 0, 'Wyvern Sting');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-27068, 27069, 0, 'Wyvern Sting');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-49011, 49009, 0, 'Wyvern Sting');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-49012, 49010, 0, 'Wyvern Sting');

-- black temple
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (39992, 39835, 42052, -41914, -41917, 41126, -41376, 39908);
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39992, 39835, 1, 'Needle Spine');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39835, 39968, 1, 'Needle Spine');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41376, 41377, 0, 'Spite');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (41126, 41131, 1, 'Flame Crash');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41914, 41915, 0, 'Summon Parasitic Shadowfiend');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41917, 41915, 0, 'Summon Parasitic Shadowfiend');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39908, 40017, 1, 'Eye Blast');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (40604, 40616, 1, 'Fel Rage Aura');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (40616, 41625, 1, 'Fel Rage Aura');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (41292, 42017, 1, 'Aura of Suffering');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (-41292, -42017, 0, 'Aura of Suffering');

-- sunwell
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (44869, 46648, 46019, 46021, -46021, 46020);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 44866, 1, 'Spectral Blast Portal');
-- 46648 will cause severe lag seems should be casted by go
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 46648, 1, 'Spectral Blast Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 46019, 1, 'Spectral Blast Teleport');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46019, 46021, 1, 'Spectral Realm Aura');
-- 44852 makes boss friendly to you, weird
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46021, 44852, 1, 'Spectral Realm Aura');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-46021, 46020, 0, 'Teleport: Normal Realm');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46020, 44867, 1, 'Spectral Exhaustion');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45661, 45665, 1, 'Encapsulate');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45347, -45348, 1, 'Remove Flame Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45348, -45347, 1, 'Remove Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45248, 45347, 1, 'Apply Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45329, 45347, 1, 'Apply Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45256, 45347, 1, 'Apply Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45270, 45347, 1, 'Apply Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45342, 45348, 1, 'Apply Flame Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (46771, 45348, 1, 'Apply Flame Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45271, 45347, 1, 'Apply Dark Touched');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES   (45246, 45348, 1, 'Apply Flame Touched');

-- zulaman
DELETE FROM `spell_proc_event` WHERE `entry` = 43983;
INSERT INTO `spell_proc_event` VALUES ('43983', '0', '0', '0', '0', '0', '16384', '0', '0');
DELETE FROM `spell_script_target` WHERE `entry` = 42577;
INSERT INTO `spell_script_target` VALUES ('42577', '1', '24136');

-- sunwell
DELETE FROM `spell_script_target` WHERE `entry` in (44885,45388,45389,46350,45714);
INSERT INTO `spell_script_target` VALUES ('45388', '1', '25038');
INSERT INTO `spell_script_target` VALUES ('45389', '1', '25265');
INSERT INTO `spell_script_target` VALUES ('44885', '1', '25160');
INSERT INTO `spell_script_target` VALUES ('46350', '1', '25160');
INSERT INTO `spell_script_target` VALUES ('45714', '1', '25038');

-- Magtheridon Earthquake
DELETE FROM spell_script_target WHERE `entry` IN (30657);
INSERT INTO spell_script_target VALUES ('30657', '1', '24136');

DELETE FROM `spell_script_target` WHERE `entry` in (30531,41455,42471,43734,42631);
INSERT INTO `spell_script_target` VALUES ('30531', '1', '17256');
INSERT INTO `spell_script_target` VALUES ('41455', '1', '22949');
INSERT INTO `spell_script_target` VALUES ('41455', '1', '22950');
INSERT INTO `spell_script_target` VALUES ('41455', '1', '22951');
INSERT INTO `spell_script_target` VALUES ('41455', '1', '22952');
INSERT INTO `spell_script_target` VALUES ('42471', '1', '23817');
INSERT INTO `spell_script_target` VALUES ('43734', '1', '23817');
INSERT INTO `spell_script_target` VALUES ('42631', '1', '23920');

DELETE FROM spell_script_target WHERE `entry` IN (44320, 44321);
INSERT INTO spell_script_target () VALUES (44320, 1, 24723);
INSERT INTO spell_script_target () VALUES (44321, 1, 24723);

DELETE FROM `spell_script_target` WHERE `entry` in (30659);
INSERT INTO `spell_script_target` VALUES (30659, 1, 17281);

DELETE FROM `spell_script_target` WHERE `entry` IN (34186, 42492, 33831, 5628, 45109, 45149);
INSERT INTO `spell_script_target` VALUES (34186, 1, 16938);
INSERT INTO `spell_script_target` VALUES (42492, 1, 0);
INSERT INTO `spell_script_target` VALUES (33831, 1, 0);
INSERT INTO `spell_script_target` VALUES (5628, 1, 2011);
INSERT INTO `spell_script_target` VALUES (5628, 1, 2012);
INSERT INTO `spell_script_target` VALUES (5628, 1, 2013);
INSERT INTO `spell_script_target` VALUES (5628, 1, 2014);
INSERT INTO `spell_script_target` VALUES (45109, 1, 25084);
INSERT INTO `spell_script_target` VALUES (45149, 0, 300154);




-- target position
DELETE FROM spell_target_position WHERE `id` IN (46019, 46020);
INSERT INTO spell_target_position () VALUES (46019, 580, 1704.34, 928.17, -74.558, 0);
INSERT INTO spell_target_position () VALUES (46020, 580, 1704.34, 928.17, 53.079, 0);


-- creature trigger spell
-- molten_flame
UPDATE creature_template SET spell1 = 40980, flags_extra = 128, speed = 1.0, scriptname = 'molten_flame' WHERE entry = 23095;
-- volcano
UPDATE creature_template SET spell1 = 40117, flags_extra = 128, scriptname = '' WHERE entry = 23085;
-- flame crash
update creature_template set spell1 = 40836, flags_extra = 128, scriptname = '' where entry = 23336;
-- blaze
update creature_template set spell1 = 40610, flags_extra = 128, scriptname = '' where entry = 23259;


-- proc event   
UPDATE `spell_proc_event` SET `procFlags` = '8396800' WHERE `entry` =14774;
UPDATE `spell_proc_event` SET `procFlags` = '8396800' WHERE `entry` =14531;
UPDATE `spell_proc_event` SET `SchoolMask` = '1' WHERE `entry` = '41434';
   
DELETE FROM spell_proc_event where entry = 42083;
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(42083,0,0,0,0,0x0000000000000000,0x00401000,0,45);

DELETE FROM `spell_elixir` WHERE `entry` = 45373;
INSERT INTO `spell_elixir` VALUES (45373,0x1);

DELETE FROM spell_affect WHERE entry IN (30017,30280,44373) AND effectId = 0;
INSERT INTO spell_affect (entry, effectId, SpellFamilyMask) VALUES
(30017,0,0x0000000000000000),
(30280,0,0x0000000000000000),
(44373,0,0x0000000000000000);

DELETE FROM spell_affect WHERE entry IN (34520,37508) AND effectId = 1;
INSERT INTO spell_affect (entry, effectId, SpellFamilyMask) VALUES
(34520,1,0x0000000000000000),
(37508,1,0x0000000000000000);

DELETE FROM spell_proc_event WHERE entry IN (34139,42368,43726,46092);
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(34139,0,0,0,10,0x0000000040000000,0x08000000,0,0),
(42368,0,0,0,10,0x0000000040000000,0x08000000,0,0),
(43726,0,0,0,10,0x0000000040000000,0x08000000,0,0),
(46092,0,0,0,10,0x0000000040000000,0x08000000,0,0);

DELETE FROM spell_proc_event where entry IN (34598, 34584, 36488);
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(34598,0,0,0,0,0x0000000000000000,0x00020000,0,45),
(36488,0,0,0,0,0x0000000000000000,0x08000000,0,0),
(34584,0,0,0,0,0x0000000000000000,0x00004000,0,30);