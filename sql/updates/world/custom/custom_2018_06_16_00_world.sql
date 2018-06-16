-- Steady Shot
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.021 WHERE `entry`= 56641;
-- Black Arrow
UPDATE `spell_bonus_data` SET `ap_dot_bonus`= 0.133 WHERE `entry`= 3674;
-- Explosion Trap
UPDATE `spell_bonus_data` SET `ap_bonus`= 0, `ap_dot_bonus`= 0.0546 WHERE `entry`= 13812;
-- Serpent Sting
UPDATE `spell_bonus_data` SET `ap_dot_bonus`= 0.08 WHERE `entry`= 1978;
-- Blood Boil
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.08 WHERE `entry`= 48721;
-- Death and Decay
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.064 WHERE `entry`= 52212;
-- Death Coil
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.23 WHERE `entry` IN (47632, 47633);
-- Frostfever and Blood Plague
UPDATE `spell_bonus_data` SET `ap_dot_bonus`= 0.055 WHERE `entry` IN (55095, 55078);
-- Howling Blast
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.44 WHERE `entry`= 49184;
-- Lacerate (Bear Form)
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.0552, `ap_dot_bonus`= 0.00369 WHERE `entry`= 33745;
-- Rake (Cat Form)
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.147, `ap_dot_bonus`= 0.147, `comments`= 'Druid Rake (Cat Form)' WHERE `entry`= 1822;
-- Swipe (Bear Form)
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.123 WHERE `entry`= 779;
-- Judgement of Corruption
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.22, `ap_bonus`= 0.14 WHERE `entry`= 53733;
-- Judgement of Truth
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.223, `ap_bonus`= 0.142 WHERE `entry`= 53733;
-- Seal of Justice
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.25, `ap_bonus`= 0.16 WHERE `entry`= 20170;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (77767, 50842, 47476, 45462, 45902, 49143, 19434, 82928, 55050);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(77767, 0, 0, 0.017, 0, 'Hunter - Cobra Shot'),
(19434, 0, 0, 0.724, 0, 'Hunter - Aimed Shot'),
(82928, 0, 0, 0.724, 0, 'Hunter - Aimed Shot!'),
(45462, 0, 0, 0, 0, 'Death Knight - Plague Strike'),
(45902, 0, 0, 0, 0, 'Death Knight - Blood Strike'),
(49143, 0, 0, 0, 0, 'Death Knight - Frost Strike'),
(55050, 0, 0, 0, 0, 'Death Knight - Heart Strike');
