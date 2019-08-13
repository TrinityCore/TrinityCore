UPDATE `creature_template` SET `flags_extra`= 512, `ScriptName`= 'npc_vp_young_storm_dragon', `AIName`= '' WHERE `entry`= 45919;
UPDATE `creature_template` SET `flags_extra`= 512, `HoverHeight`= 7.875 WHERE `entry`= 45920;
UPDATE `creature_template_movement` SET `Flight`= 0 WHERE `CreatureId` IN (45919, 45920);

DELETE FROM `creature_template_addon` WHERE `entry` IN (45919, 45920);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(45919, '88192'),
(45920, '88192');

DELETE FROM `spell_custom_attr` WHERE `entry` IN (88188, 92758);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(88188, 0x00000008),
(92758, 0x00000008);

DELETE FROM `smart_scripts` WHERE `entryorguid`= 45919 AND `source_type`=0;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_vp_healing_well';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88201, 'spell_vp_healing_well');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 88201 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 88201, 0, 0, 31, 0, 3, 45919, 0, 0, 0, '', 'Healing Well - Target Young Storm Dragon');
