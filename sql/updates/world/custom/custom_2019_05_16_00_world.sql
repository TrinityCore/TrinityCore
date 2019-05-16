DELETE FROM `creature_template_addon` WHERE `entry`= 40180;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(40180, 0, 1, '76236');

UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_mh_arch_druid_fandral_staghelm' WHERE `entry`= 40180;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mh_fandral_creator_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76237, 'spell_mh_fandral_creator_aura');

DELETE FROM `areatrigger_scripts` WHERE `entry`= 5876;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5876, 'at_mh_hyjal_barrow_dens');

DELETE FROM `conditions` WHERE `SourceEntry`= 77828 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 77828, 0, 0, 31, 0, 3, 40180, 0, 0, 0, '', 'Cue Fandral to Despawn - Target Arch Druid Fandral Staghelm');
