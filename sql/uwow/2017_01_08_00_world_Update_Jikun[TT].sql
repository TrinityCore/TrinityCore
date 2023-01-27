DELETE FROM `areatrigger_scripts` WHERE `entry` = '8848';
INSERT INTO `areatrigger_scripts`(`entry`,`ScriptName`) VALUES ( '8848','at_jikun_precipice'); 
DELETE FROM `creature` WHERE `id` = '70216';
DELETE FROM `areatrigger_actions` WHERE `entry` = '929';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('929','0','1','0','8','134339','0','-140571','0','0','0','0','0','TT:JiKun Feather');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '134339','spell_daedalian_wings'); 