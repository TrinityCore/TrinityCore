UPDATE `creature_template` SET `VehicleId`= 907, `spell1`= 79425, `spell2`= 79430, `ScriptName`= 'npc_westfall_overloaded_harvest_golem' WHERE `entry`= 42601;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 42601;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42601, 46598, 1, 0);

DELETE FROM `conditions` WHERE `SourceEntry`= 79436 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 79436, 0, 0, 31, 0, 3, 42381, 0, 0, 0, '', 'Wake Harvest Golem - Target Overloaded Harvest Golem');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_westfall_reaping_blows',
'spell_westfall_wake_harvest_golem');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79425, 'spell_westfall_reaping_blows'),
(79436, 'spell_westfall_wake_harvest_golem');

DELETE FROM `creature_text` WHERE `CreatureID`= 42601;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(42601, 0, 0, 'You may only ride the Overloaded Harvest Golem at the Molsen Farm.', 42, 0, 100, 0, 0, 0, 42475, '');
