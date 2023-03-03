DELETE FROM `creature` WHERE `id` = '71548';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1024';
INSERT INTO `areatrigger_actions`(`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1024','0','5','0','8','143413','0','0','0','0','0','0','0','OO:Swirl trigger'); 
INSERT INTO `areatrigger_actions`(`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`amount`,`comment`) VALUES ( '1024','1','42','1','8','143413','0','0','0','0','0','0','0','OO:Swirl trigger remove'); 
UPDATE `areatrigger_data` SET `Radius`='3',`RadiusTarget`='3' WHERE `entry`='1024';
UPDATE `creature_template` SET `modelid1`='11686',`modelid2`='0',`unit_flags`='0',`ScriptName`='npc_swirl_trigger' WHERE `entry`='71548';