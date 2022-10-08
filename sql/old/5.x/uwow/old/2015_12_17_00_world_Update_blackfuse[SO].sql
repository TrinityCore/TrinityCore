INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '144287','spell_on_conveyor'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '149146','spell_blacksue_cm_explose'); 
UPDATE `creature_template` SET `ScriptName`='npc_blackfuse_trigger' WHERE `entry`='71520';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1059';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1057';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1021';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1046';
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1059','0','1','0','8','144335','0','0','0','0','0','0','0','OO:Death Beam');
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1057','0','1','0','1','144213','0','143387','0','0','0','0','0','OO:Automatic Repair Beam'); 
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1057','1','2','1','1','144213','0','144213','0','0','0','0','0','OO:Automatic Repair Beam Remove'); 
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1021','0','1','0','8','143327','0','0','0','0','0','0','0','OO:Launch Sawblade');    
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) values ( '1021','1','1','0','1','143327','0','143387','0','0','0','0','0','OO:Launch Sawblade for shredder');
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) values ( '1046','0','1','0','8','143856','0','0','0','0','0','0','0','OO:Disentegration Laser');
INSERT INTO `areatrigger_actions` (`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) values ( '1046','1','1','0','1','143856','0','143387','0','0','0','0','0','OO:Disentegration Laser for shredder');

