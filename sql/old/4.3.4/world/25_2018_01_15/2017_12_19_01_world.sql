--
DELETE FROM `spell_learn_spell` WHERE `entry`= 87840;
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`, `Active`) VALUES
(87840, 33388, 1);
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.654 WHERE `entry`= 133;
