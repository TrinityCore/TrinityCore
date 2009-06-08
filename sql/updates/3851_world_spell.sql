UPDATE `spell_bonus_data` SET `direct_bonus` = '0.6453' WHERE `entry`=33763;
DELETE FROM `spell_script_target` WHERE `entry` IN (48714,57806);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES 
('48714', '2', '27237'),
('48714', '2', '27235'),
('48714', '2', '27234'),
('48714', '2', '27236'),
('57806', '2', '31043');