INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1275','0','1','0','8','147136','0','-147136','0','0','0','0','0','OO:Napalm');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1275','1','42','1','8','147136','0','147136','0','0','0','0','0','OO:Napalm Remove');
UPDATE `creature_template` SET `minlevel`='93',`maxlevel`='93',`faction`='14',`rank`='3',`InhabitType`='7',`mechanic_immune_mask`='650854399',`ScriptName`='npc_horde_cannon' WHERE `entry`='73665'; 
UPDATE `creature_template` SET `minlevel`='93',`maxlevel`='93',`rank`='3',`InhabitType`='7',`mechanic_immune_mask`='650854399',`ScriptName`='npc_korkron_gunship' WHERE `entry`='73065'; 
UPDATE `creature_template` SET `minlevel`='93',`maxlevel`='93',`faction`='16',`mechanic_immune_mask`='650854399',`ScriptName`='npc_unstable_iron_star' WHERE `entry`='73059'; 
UPDATE `creature_model_info` SET `combat_reach`='10.5' WHERE `modelid`='51051'; 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147319','spell_crushing_fear');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147011','spell_manifest_rage');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147229','spell_malice_dummy');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147665','spell_fixate_iron_star');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147120','spell_call_bombartment');


