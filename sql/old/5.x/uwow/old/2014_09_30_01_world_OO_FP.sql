/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

INSERT INTO `areatrigger_data` (`entry`, `radius`, `radius2`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `comment`) VALUES 
('4906', '0', '0', '0', '0', '0', '32486', 'OO: Defiled Ground');

INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('4906', '0', '0', '0', '2', '143959', '0', '0', 'OO: Defiled Ground on enter cast'), 
('4906', '1', '1', '1', '0', '143959', '0', '0', 'OO: Defiled Ground on exit remove');

DELETE FROM `spell_script_names` WHERE `spell_id` = 143961;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143961', 'spell_fallen_protectors_defile_ground');