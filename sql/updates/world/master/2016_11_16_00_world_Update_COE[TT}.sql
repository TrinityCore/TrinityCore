INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('711','0','1','0','8','136860','0','0','0','0','0','0','0','TT:SandTrap');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('711','1','42','1','8','136860','0','0','0','0','0','0','0','TT:SandTrap Remove');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_garajal_soul' WHERE `entry`='69182';
UPDATE `creature_template` SET `ScriptName`='npc_living_sand' WHERE `entry`='69153'; 
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69480';
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69491';
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69492';
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69548';
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69553';
UPDATE `creature_template` SET `ScriptName`='npc_loa_spirit' WHERE `entry`='69556';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '136860','spell_coe_sand_trap'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '136442','spell_possessed'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '137203','spell_loa_spirit'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '137350','spell_loa_spirit'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '136894','spell_sandstorm'); 

