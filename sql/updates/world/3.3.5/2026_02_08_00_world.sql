DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_destroy_deathforged_infernal', 'spell_fel_reaver_sentinel_tag', 'spell_fel_reaver_controller');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38055, 'spell_destroy_deathforged_infernal'),
(38020, 'spell_fel_reaver_sentinel_tag'),
(38002, 'spell_fel_reaver_controller'),
(38120, 'spell_fel_reaver_controller'),
(38122, 'spell_fel_reaver_controller'),
(38125, 'spell_fel_reaver_controller'),
(38127, 'spell_fel_reaver_controller'),
(38129, 'spell_fel_reaver_controller');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceEntry`IN(38006,38052);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 38006, 0, 0, 31, 0, 3, 21753, 0, 0, 0, 0, '', 'World Breaker targets shadow council felsworm'),
(13, 3, 38006, 0, 1, 31, 0, 3, 21961, 0, 0, 0, 0, '', 'World Breaker targets shadow council Catacyslm Overseer'),
(13, 3, 38006, 0, 2, 31, 0, 3, 21754, 0, 0, 0, 0, '', 'World Breaker targets shadow council zealot'),
(13, 3, 38006, 0, 3, 31, 0, 3, 21779, 0, 0, 0, 0, '', 'World Breaker targets shadow doctor maleficus');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceEntry`IN(38488);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 38488, 0, 0, 31, 0, 3, 21753, 0, 0, 0, 0, '', 'Sonic Boom targets shadow council felsworm'),
(13, 1, 38488, 0, 1, 31, 0, 3, 21961, 0, 0, 0, 0, '', 'Sonic Boom targets shadow council Catacyslm Overseer'),
(13, 1, 38488, 0, 2, 31, 0, 3, 21754, 0, 0, 0, 0, '', 'Sonic Boom targets shadow council zealot'),
(13, 1, 38488, 0, 3, 31, 0, 3, 21779, 0, 0, 0, 0, '', 'Sonic Boom targets shadow doctor maleficus');

UPDATE `creature_template` SET `flags_extra`=64 WHERE  `entry`=21949;

DELETE FROM `creature_template_spell` WHERE `CreatureID` = 21949;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(21949, 0, 38055, 0),
(21949, 1, 38488, 0),
(21949, 2, 38006, 0),
(21949, 3, 37920, 0);

 -- Fel Reaver Sentinel smart ai
SET @ENTRY := 21949;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 512, 1000, 1000, 1000, 1000, 41, 0, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Self: Despawn instantly respawn in 15 seconds'),
(@ENTRY, 0, 1, 0, 0, 0, 100, 512, 1000, 1000, 1000, 1000, 41, 0, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (IC) - Self: Despawn instantly respawn in 15 seconds'),
(@ENTRY, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Despawn in 1 s respawn in 15 seconds'),
(@ENTRY, 0, 3, 0, 29, 0, 100, 0, 1, 0, 0, 0, 41, 0, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On creature got charmed by another unit - Self: Despawn instantly respawn in 5 seconds');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 21949 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 21949, 0, 0, 23, 1, 3943, 0, 0, 1, 'Object is not in area Invasion Point: Cataclysm (3943)'),
(22, 2, 21949, 0, 0, 23, 1, 3943, 0, 0, 1, 'Object is not in area Invasion Point: Cataclysm (3943)');

UPDATE `gameobject_template_addon` SET `flags` = 16 WHERE `entry` = 184979;
