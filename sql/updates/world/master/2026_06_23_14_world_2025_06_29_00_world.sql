DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_bem_q10720_poison_keg';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_bem_coax_marmot';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_bem_charm_rexxars_rodent';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38629, 'spell_bem_q10720_poison_keg'),
(38544, 'spell_bem_coax_marmot'),
(38586, 'spell_bem_charm_rexxars_rodent');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=38629;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 38629, 0, 0, 31, 0, 3, 22356, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Green Spot Grog Keg Credit'),
(13, 1, 38629, 0, 1, 31, 0, 3, 22367, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Ripe Moonshine Keg Credit'),
(13, 1, 38629, 0, 2, 31, 0, 3, 22368, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Fermented Seed Beer Keg Credit');

UPDATE `creature_template` SET `ScriptName`='npc_q10720_keg_credit' WHERE `entry` IN (22356,22367,22368);
UPDATE `creature_template` SET `ScriptName`='npc_q10720_marmot' WHERE `entry`=22189;

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=20330;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=20330;
