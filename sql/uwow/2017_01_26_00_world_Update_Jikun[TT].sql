DELETE FROM `spell_script_names` WHERE `spell_id` = '134385';
DELETE FROM `spell_script_names` WHERE `spell_id` = '134256';
DELETE FROM `spell_script_names` WHERE `spell_id` = '134335';
DELETE FROM `spell_script_names` WHERE `spell_id` = '134322';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '134385','spell_regurgitate');  
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '134256','spell_jikun_slimed_aura'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '134335','spell_incubated'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '134322','spell_hatchling_morph');
UPDATE `creature_template` SET `InhabitType`='7',`ScriptName`='npc_juvenile' WHERE `entry`='69836';
UPDATE `creature_template` SET `InhabitType`='7',`ScriptName`='npc_juvenile' WHERE `entry`='70095';
UPDATE `creature_template` SET `ScriptName`='npc_jikun_fledgling_egg' WHERE `entry`='68202'; 
  