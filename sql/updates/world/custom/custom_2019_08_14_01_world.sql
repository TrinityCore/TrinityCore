
UPDATE `creature_template` SET `unit_flags`= 33554952, `flags_extra`= 128, `VehicleId`= 1307, `ScriptName`= 'npc_vp_catch_fall' WHERE `entry`= 48165;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 48165;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(48165, 1);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 48165;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(48165, 89524, 1, 1);

DELETE FROM `conditions` WHERE `SourceEntry` IN (89522, 89526) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89522, 0, 0, 31, 0, 3, 45455, 0, 0, 0, '', 'Catch Fall - Target Slipstream'),
(13, 1, 89526, 0, 0, 31, 0, 3, 45455, 0, 0, 0, '', 'Catch Fall - Target Slipstream Landing Zone');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_vp_catch_fall';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89526, 'spell_vp_catch_fall');

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'at_vp_catch_fall';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6477, 'at_vp_catch_fall'),
(6651, 'at_vp_catch_fall'),
(6652, 'at_vp_catch_fall'),
(6660, 'at_vp_catch_fall'),
(6667, 'at_vp_catch_fall'),
(6661, 'at_vp_catch_fall'),
(6663, 'at_vp_catch_fall');
