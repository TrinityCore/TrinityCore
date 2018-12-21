-- Template Updates
-- Rom'Ogg Bonecrusher
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 2048 WHERE `entry` IN (39665, 39666);
-- Quake
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 40401;
-- Angered Earth
UPDATE `creature_template` SET `DamageModifier`= 8 WHERE `entry`= 50376;
-- Chains of Woe
UPDATE `creature_template` SET `ScriptName`= 'npc_romogg_chains_of_woe' WHERE `entry`= 40447;
UPDATE `creature_template` SET `InhabitType`= 12, `mechanic_immune_mask`= 1 | 2 | 16 | 32 | 256 | 512 | 2048 | 8192 | 65536 | 131072 | 8388608 | 33554432, `flags_extra`= 0x40000000 WHERE `entry` IN (40447, 50379);

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (40401);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40401, '75379');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_romogg_quake',
'spell_chains_of_woe_1',
'spell_chains_of_woe_4',
'spell_romogg_chains_of_woe_teleport',
'spell_romogg_chains_of_woe_root',
'spell_romogg_chains_of_woe',
'spell_romogg_chains_of_woe_teleport_dest',
'spell_romogg_call_for_help');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75272, 'spell_romogg_quake'),
(75437, 'spell_romogg_chains_of_woe_teleport'),
(82189, 'spell_romogg_chains_of_woe_root'),
(75539, 'spell_romogg_chains_of_woe'),
(75464, 'spell_romogg_chains_of_woe_teleport_dest'),
(82137, 'spell_romogg_call_for_help');

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15943;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15943, 11, 0, 0, 'achievement_crushing_bones_and_cracking_skulls');

DELETE FROM `conditions` WHERE `SourceEntry`= 93454 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 93454, 0, 0, 31, 0, 3, 50376, 0, 0, 0, '', 'The Skullcracker - Target Enraged Earth'),
(13, 2, 93454, 0, 1, 31, 0, 3, 40447, 0, 0, 0, '', 'The Skullcracker - Target Chains of Woe');
