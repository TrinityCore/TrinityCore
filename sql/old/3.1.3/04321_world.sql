DELETE FROM `creature_questrelation` WHERE `quest`=12701;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28377, 12701);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12701;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28377, 12701);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12723;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12723);
DELETE FROM `creature_questrelation` WHERE `quest`=12724;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12724);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12724;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12724);
DELETE FROM `creature_questrelation` WHERE `quest`=12725;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28913, 12725);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12725;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28912, 12725);
DELETE FROM `creature_questrelation` WHERE `quest`=12727;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28912, 12727);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12727;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28913, 12727);

DELETE FROM `spell_script_target` WHERE `entry` IN (48714,57806);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
('48714', '2', '27237'),
('48714', '2', '27235'),
('48714', '2', '27234'),
('48714', '2', '27236'),
('57806', '2', '31043');

UPDATE `creature_template` SET `ScriptName`='npc_aged_dying_ancient_kodo' WHERE `entry` IN (4700,4701,4702,11627);

DELETE FROM `spell_target_position` WHERE `id`=51852;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(51852, 609, 2361.21, -5660.45, 503.828, 4.49);

DELETE FROM `spell_bonus_data` WHERE `entry` IN (20187);
INSERT INTO `spell_bonus_data` (entry, direct_bonus, dot_bonus, ap_bonus, comments) VALUES
(20187, 0.4, 0, 0.25, 'Judgement of Righteousness');
