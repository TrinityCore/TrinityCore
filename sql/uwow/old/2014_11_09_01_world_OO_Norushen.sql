/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

DELETE FROM `creature_template` WHERE `entry` = 90008;
UPDATE `creature_template` SET `unit_flags` = '32768' WHERE `entry` = 72276;

DELETE FROM creature where id in (72872, 71967, 72276);
UPDATE `gameobject_template` SET `flags` = `flags` | 0x10 WHERE entry in (223012, 223013, 223014, 223015, 221447, 221446, 221620, 221245);
-- 221620 221245 

DELETE FROM creature_text WHERE entry in (72872, 71967);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- 0xF1311CA800000B02
(72872, 0, 0, 'Невероятно! Еще один зал, похоже, созданный «титанами».', 12, 0, 100, 0, 0, 38138, 0),
(72872, 1,0, 'Да. Должно быть, он был спрятан давным-давно. И на то была причина!', 12, 0, 100, 0, 0, 38139, 0),
(72872, 2,0, 'В этой комнате, в недрах мирного края, спало сердце древнего бога.', 12, 0, 100, 0, 0, 38140, 0),
(72872, 3,0, 'Ох! Что это? Здравствуй! Я Хранитель истории Чо.', 12, 0, 100, 3, 0, 38141, 'Норусхен'),
(72872, 4,0, 'Порча? Мы здесь как раз, чтобы остановить ее и спасти Пандарию!', 12, 0, 100, 274, 0, 38142, 'Норусхен'),
(72872, 5,0, 'Да! Пропусти нас!', 12, 0, 100, 273, 0, 38143, 'Норусхен'),
-- 0xF131191F0000002F
(71967, 0,0, 'Стойте!', 14, 0, 100, 0, 0, 38883, 'Хранитель истории Чо'),
(71967, 1,0, 'Порча больше не проникнет в покои сердца!', 14, 0, 100, 0, 0, 38884, 'Хранитель истории Чо'),
(71967, 2,0, 'Вы хотите победить порчу?', 14, 0, 100, 0, 0, 38885, 'Хранитель истории Чо'),
(71967, 3,0, 'Если вы пройдете через эти двери сейчас, то потерпите неудачу. Вы поддались коварной порче, и имя ей – Гордыня.', 14, 0, 100, 0, 0, 38886, 'Хранитель истории Чо'),
(71967, 4,0, 'Вы гордитесь своими победами, и в этом ваша слабость.', 14, 0, 100, 0, 0, 0, 'Хранитель истории Чо'),
(71967, 5,0, 'Чтобы победить порчу, сначала нужно убить ее в себе.', 14, 0, 100, 0, 0, 0, 'Хранитель истории Чо'),
(71967, 6,0, 'Скажите, когда будете готовы ко встрече со своими демонами.', 14, 0, 100, 0, 0, 38887, 'Хранитель истории Чо'),
--
(71967, 7,0, 'Хорошо, я создам поле для удерживания порчи.', 14, 0, 100, 0, 0, 38888, 0),
(71967, 8,0, 'Докажите, что достойны, и я пропущу вас.', 14, 0, 100, 0, 0, 38889, 0),
(71967, 9,0, 'Свет несет очищение, но принять его непросто. Приготовьтесь! ', 14, 0, 100, 0, 0, 38880, 'Норусхен'),
(71967, 10,0, 'Загляните в себя, изгоните тьму.', 14, 0, 100, 0, 0, 38892, 0);

REPLACE INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('145188', '1136', '797.9045', '877.7274', '371.099', '0'),
('145143', '1136', '777.3924', '974.2292', '356.3398', '1.786108'),
('145149', '1136', '777.3924', '974.2292', '356.3398', '1.786108');

UPDATE `creature_template` SET `ScriptName` = 'npc_norushen_lowerwalker' WHERE `entry` = 72872;
UPDATE `creature_template` SET `ScriptName` = 'boss_norushen', `gossip_menu_id` = '71967' WHERE `entry` = 71967;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=71967;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(71967, 0, 0, 'Мы готовы...', 1, 1, 0, 0, 0, 0, '');

SET @id = 0;
SET @entry = 72872;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 799.071, 872.569, 371.085, NULL),
(@entry, @id := @id+ 1, 797.319, 880.821, 371.112, NULL),
(@entry, @id := @id+ 1, 797.319, 880.821, 371.112, NULL);

--
REPLACE INTO`spell_script_names` (`spell_id`, `ScriptName`) VALUES ('145571', 'spell_norushen_blind_hatred');
DELETE FROM `conditions` WHERE `SourceEntry` = 145226;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
 ('13', '3', '145226', '0', '0', '31', '0', '3', '72565', '0', '0', '0', '', NULL);
 
--
UPDATE `creature_template` SET `ScriptName` = 'npc_norushen_manifestation_of_corruption_challenge' WHERE `creature_template`.`entry` = 71977;

--
UPDATE `creature_template` SET `ScriptName` = 'npc_norushen_manifestation_of_corruption_released' WHERE `creature_template`.`entry` = 72264;

--
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('145074', 'spell_norushen_residual_corruption');
REPLACE INTO `areatrigger_data` (`entry`, `radius`, `radius2`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `comment`) VALUES 
('5022', '1', '0', '0', '0', '0', '32875', 'OO:NN spell_norushen_residual_corruption');
UPDATE `creature_template` SET `ScriptName` = 'npc_norushen_residual_corruption' WHERE `creature_template`.`entry` = 72550;

--
UPDATE `creature_template` SET `ScriptName` = 'npc_norushen_purifying_light' WHERE `entry` = 72065;
UPDATE `creature_template_addon` SET `auras` = '144717' WHERE `creature_template_addon`.`entry` = 72065;

--
DELETE FROM `spell_script_names` WHERE `ScriptName` LIKE 'spell_norushen_challenge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('144849', 'spell_norushen_challenge'),
('144850', 'spell_norushen_challenge'),
('144851', 'spell_norushen_challenge');

--
REPLACE INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('71976', '0', '0', '0', '0', '0', '148452');
UPDATE `creature_template` SET `unit_flags` = '34816', `unit_flags2` = '2048', `rangeattacktime` = '2000', `ScriptName` = 'npc_essence_of_corruption_challenge' WHERE `creature_template`.`entry` = 71976;
REPLACE INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('71976', '0', '0', '0', '1', '0', NULL);
UPDATE `creature_model_info` SET `gender` = '2' WHERE `creature_model_info`.`modelid` = 51859;

-- class 1 92 lvl base hp - 421592
-- used for heroic25 but should be same for all.
DELETE FROM `creature_difficulty_stat` WHERE entry = 71976;

DELETE FROM `creature_difficulty_stat` WHERE entry = 71977;
INSERT INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(71977, 0, 1.15, 2.6),  -- not shure
(71977, 1, 1.15, 3.0),  -- not shure
(71977, 2, 1.15, 2.8),  -- not shure
(71977, 3, 1.15, 3.2),
(71977, 4, 1.15, 3.2);  -- not shure

UPDATE `creature_template` SET `unit_flags` = '34816', `unit_flags2` = '2048', `rangeattacktime` = '2000', `ScriptName` = 'npc_essence_of_corruption_released' WHERE `creature_template`.`entry` = 72263;

--
UPDATE `creature_template` SET `mindmg` = '7686', `maxdmg` = '2000', `attackpower` = '1' WHERE `creature_template`.`entry` = 72051;
REPLACE INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(72051, 0, 1.5, 10),
(72051, 1, 1.5, 10),
(72051, 2, 2.3, 15),
(72051, 3, 2.3, 15),
(72051, 4, 1, 6.5);

-- 145064
REPLACE INTO `areatrigger_data` (`entry`, `radius`, `radius2`, isMoving, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `comment`) VALUES 
('1106', '0', '0', '1', '0', '0', '0', '32660', '5021', 'OO:NN Expel Corruption released 145064');

REPLACE INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1106', '0', '1', '0', '1', '145132', '0', '0', 'OO:NN Expel Corruption released 145064 onHit friend'), 
('1106', '1', '1', '0', '2', '145134', '1', '0', 'OO:NN Expel Corruption released 145064 onHit enemy');

-- 144479
REPLACE INTO `areatrigger_data` (`entry`, `radius`, `radius2`, isMoving, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `comment`) VALUES 
('1080', '100', '0', '1', '0', '0', '0', '32660', '4985', 'OO:NN Expel Corruption 144479');

REPLACE INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1080', '0', '65', '0', '2', '144480', '0', '0', 'OO:NN Expel Corruption 144479 on enemy between source and dest'),
('1080', '1', 0x2|0x8, '1', '2', '144480', '0', '0', 'OO:NN Expel Corruption 144479 onHit enemy');

--
UPDATE `creature_template` SET `mindmg` = '210', `maxdmg` = '300', `attackpower` = '1', `ScriptName` = 'npc_norushen_heal_ch_greater_corruption' WHERE `creature_template`.`entry` = 72001;
UPDATE `creature_template` SET `mindmg` = '11516', `maxdmg` = '27609', `attackpower` = '1', `ScriptName` = 'npc_norushen_heal_ch_melee_combtant' WHERE `creature_template`.`entry` = 71996;
UPDATE `creature_template` SET `mindmg` = '11516', `maxdmg` = '27609', `attackpower` = '1', `minrangedmg` = '11516', `maxrangedmg` = '27609', `rangedattackpower` = '1', `ScriptName` = 'npc_norushen_heal_ch_caster' WHERE `creature_template`.`entry` = 72000;
UPDATE `creature_template` SET `mindmg` = '18926', `maxdmg` = '18926', `attackpower` = '1', `ScriptName` = 'npc_norushen_heal_ch_guardian' WHERE `creature_template`.`entry` = 71995;

--
REPLACE INTO `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
('146705', '146793', '14', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'OO:NN Heal chap. SPELL_BOTTOMLESS_PIT');

REPLACE INTO `areatrigger_data` (`entry`, `radius`, `radius2`, `isMoving`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `comment`) VALUES 
('1257', '2', '2', '0', '0', '0', '0', '33425', '5208', 'OO:NN SPELL_BOTTOMLESS_PIT 146793');
REPLACE INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1257', '0', '1', '0', '2', '146703', '0', '0', 'OO:NN SPELL_BOTTOMLESS_PIT 146793 on enemy enter'),
('1257', '1', 0x2|0x8, '1', '2', '146703', '0', '0', 'OO:NN SPELL_BOTTOMLESS_PIT 146793 leave');

--
UPDATE creature_difficulty_stat SET dmg_multiplier = 1 WHERE difficulty = 4 AND entry in (72001, 71996, 71995, 72051);
UPDATE creature_difficulty_stat SET dmg_multiplier = 1.5 WHERE difficulty = 1 AND entry in (72001, 71996, 71995, 72051);
UPDATE creature_difficulty_stat SET dmg_multiplier = 1.5 WHERE difficulty = 0 AND entry in (72001, 71996, 71995, 72051);
UPDATE creature_difficulty_stat SET dmg_multiplier = 2.3 WHERE difficulty in (2, 3) AND entry in (72001, 71996, 71995, 72051);

-- 421592
REPLACE INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(72001, 0, 1.5, 15),
(72001, 1, 1.5, 15),
(72001, 2, 2.0, 22.5),
(72001, 3, 2.0, 22.5),
(72001, 4, 1, 9.75);

REPLACE INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(71996, 0, 1.5, 1.5),
(71996, 1, 1.5, 1.5),
(71996, 2, 2.6, 2),
(71996, 3, 2.5, 2),
(71996, 4, 1, 1.12);

-- 18000 - 71995 - 709094
REPLACE INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(71995, 0, 1.5, 2),
(71995, 1, 1.5, 2),
(71995, 2, 2.6, 2.2),
(71995, 3, 2.5, 2.2),
(71995, 4, 1, 1.8); -- 709094 hp

--
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('144521', 'spell_norushen_heal_test_dd');


-- Cell should be in phase too.
UPDATE  `gameobject` SET `phaseMask` = `phaseMask` | 0x2 WHERE map = 1136 AND id in (223142, 223143, 223144, 223145, 223146, 223147);

-- Enable Sha
UPDATE `creature` SET `spawnMask` = '16632' WHERE id = 71734;
-- sha loot
UPDATE `gameobject_template` SET `data1` = '221739' WHERE `gameobject_template`.`entry` = 221739;