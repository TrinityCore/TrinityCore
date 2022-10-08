/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;


-- --------------------------
-- Worgen First Zone - 4755
-- --------------------------

-- After take 14091
DELETE FROM  `quest_end_scripts` WHERE  `id` =14078;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14078;
DELETE FROM `spell_area` WHERE `spell` in (59073) AND area in (4755);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59073', '4755', '14091', '0', '0', '0', '2', '1', '74', '11');

-- After complete quest 14098
DELETE FROM  `quest_end_scripts` WHERE  `id` =14098;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14098;

-- For quest 14222
DELETE FROM  `quest_end_scripts` WHERE  `id` =14221;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14221;
DELETE FROM `spell_area` WHERE `spell` in (67789) AND area in (4755);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67789', '4755', '14222', '0', '0', '0', '2', '1', '10', '11');

-- After start quest 24904
DELETE FROM  `quest_end_scripts` WHERE  `id` =24902;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 24902;
DELETE FROM `spell_area` WHERE `spell` in (69486) AND area in (4755);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69486', '4755', '24904', '0', '0', '0', '2', '1', '74', '0');

-- --------------------------
-- Worgen Second Zone - 4714
-- --------------------------

-- clean not used
DELETE FROM  `quest_end_scripts` WHERE  `id` =14466;

-- Rewarded 14321
DELETE FROM  `quest_end_scripts` WHERE  `id` =14321;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14321;
DELETE FROM `spell_area` WHERE `spell` in (68482) AND area in (4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68482', '4714', '14321', '0', '0', '0', '2', '1', '64', '11');    -- rewarded

-- Rewarded 14386
DELETE FROM  `quest_end_scripts` WHERE  `id` =14386;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14386;
DELETE FROM `spell_area` WHERE `spell` in (68483) AND area in (4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68483', '4714', '14386', '0', '0', '0', '2', '1', '64', '11');    -- rewarded

-- Rewarded 24676
DELETE FROM  `quest_end_scripts` WHERE  `id` =24676;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 24676;
DELETE FROM `spell_area` WHERE `spell` in (69485) AND area in (4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69485', '4714', '24676', '0', '0', '0', '2', '1', '64', '11');    -- rewarded

-- Rewarded 24679
DELETE FROM  `quest_end_scripts` WHERE  `id` =24679;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 24679;
DELETE FROM `spell_area` WHERE `spell` in (70695) AND area in (4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('70695', '4714', '24679', '0', '0', '0', '2', '1', '64', '11');    -- rewarded

-- Rewarded 24681
DELETE FROM  `quest_end_scripts` WHERE  `id` =24681;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 24681;
DELETE FROM `spell_area` WHERE `spell` in (74093) AND area in (4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('74093', '4714', '24681', '0', '0', '0', '2', '1', '64', '11');    -- rewarded