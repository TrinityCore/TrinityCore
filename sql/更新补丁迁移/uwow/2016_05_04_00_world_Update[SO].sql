DELETE FROM `spell_script_names` WHERE `spell_id` = '144919';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '144919','spell_explosive_tar');
UPDATE `areatrigger_data` SET `Radius`='3',`RadiusTarget`='3' WHERE `entry`='1083';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1083';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1083','0','1','0','8','144498','0','-144498','0','0','0','0','0','OO: Explosive Tar');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1083','1','2','1','8','144498','0','144498','0','0','0','0','0','OO: Explosive Tar Remove');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1083','3','1','0','1','144919','0','144576','0','0','0','1','0','OO: Explosive Tar for Cutter Laser');


