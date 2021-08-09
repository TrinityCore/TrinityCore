UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`flags_extra`='1',`ScriptName`='boss_thok_the_bloodthirsty' WHERE `entry`='71529';
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE `entry`='71658';
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_thok_ice_tomb' WHERE `entry`='69398'; 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '143800','spell_icy_blood'); 
DELETE FROM `areatrigger_actions` WHERE `entry` = '1045';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) values('1045','0','1','0','8','143784','0','-143784','0','0','0','0','OO: Burning Blood');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) values('1045','1','2','1','8','143784','0','0','0','0','0','0','OO: Burning Blood Remove');