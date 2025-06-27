DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q10720_the_smallest_creature';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_coax_marmot';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_charm_rexxars_rodent';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38629, 'spell_q10720_the_smallest_creature'),
(38544, 'spell_coax_marmot'),
(38586, 'spell_charm_rexxars_rodent');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=38629;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=38629;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 38629, 0, 0, 29, 0, 22356, 10, 0, 0, 0, 0, '', '10 yard requirement [DND]Green Spot Grog Keg Credit'),
(17, 0, 38629, 0, 1, 29, 0, 22367, 10, 0, 0, 0, 0, '', '10 yard requirement [DND]Ripe Moonshine Keg Credit'),
(17, 0, 38629, 0, 2, 29, 0, 22368, 10, 0, 0, 0, 0, '', '10 yard requirement [DND]Fermented Seed Beer Keg Credit'),
(13, 1, 38629, 0, 0, 31, 0, 3, 22356, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Green Spot Grog Keg Credit'),
(13, 1, 38629, 0, 1, 31, 0, 3, 22367, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Ripe Moonshine Keg Credit'),
(13, 1, 38629, 0, 2, 31, 0, 3, 22368, 0, 0, 0, 0, '', 'Poison Keg Targets [DND]Fermented Seed Beer Keg Credit');

UPDATE `creature_template` SET `ScriptName` = 'npc_q10720_key_credit' WHERE `entry` IN (22356,22367,22368);
UPDATE `creature_template` SET `ScriptName` = 'npc_bloodmaul_battle_worg' WHERE (`entry` = 20330);

UPDATE `creature_template_addon` SET `auras` = '' WHERE (`entry` = 20330);
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 20330;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 20330);
