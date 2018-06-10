-- Boss: Earthrager Ptah
UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 39428;
UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 48714;
UPDATE `creature_template` SET `vehicleId`= 741, `unit_flags`= 33554496, `ScriptName`= 'npc_ptah_tumultuous_earthstorm' WHERE `entry`= 40406;
UPDATE `creature_template` SET `unit_flags`= 33554496, `flags_extra`= 128 WHERE `entry`= 40503;

UPDATE `creature_template` SET `ScriptName` = 'npc_ptah_beetle_stalker' WHERE `entry` = 40459;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_earthrager_ptah_sandstorm',
'spell_earthrager_ptah_consume');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75491, 'spell_earthrager_ptah_sandstorm'),
(75378, 'spell_earthrager_ptah_consume');

-- text
DELETE FROM `creature_text` WHERE `CreatureID` = 39428;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39428, 0, 0, 'Ptah... is... no more...',       14, 0, 100, 0, 0, 18905, 44780, 0, 'Earthrager Ptah - SAY_DEATH'),
(39428, 1, 0, 'More carrion for the swarm...',  14, 0, 100, 0, 0, 18906, 44778, 0, 'Earthrager Ptah - SAY_AGGRO'),
(39428, 2, 0, 'Dust to dust.',                  14, 0, 100, 0, 0, 18907, 44779, 0, 'Earthrager Ptah - SAY_PLAYER_KILL'),
(39428, 3, 0, 'The earth TREMBLES!',            14, 0, 100, 0, 0, 18908, 44781, 0, 'Earthrager Ptah - SAY_SPECIAL');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39428, 48714);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(39428, 395, 3500),
(48714, 395, 7000);

-- Spelleffect entries
DELETE FROM `spelleffect_dbc` WHERE `Id` IN (155918, 155919);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(155918, 28, 40406, 64, 12, 12, 18, 0, 75517, 0, 'Tumultuous Earthstorm'),
(155919, 28, 40503, 64, 12, 12, 53, 0, 75550, 0, 'Summon Quicksand');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (89396, 75378);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 89396, 0, 0, 31, 0, 3, 39443, 0, 0, 0, 0, '', 'Quicksand - Target Camel'),
(13, 2, 75378, 0, 0, 31, 0, 3, 40458, 0, 0, 0, 0, '', 'Consume - Target Jeweled Scarab');

-- Ptah's Dustbone Horror SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1`= 49296, `DamageModifier`= 10 WHERE `entry` = 40450;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40450 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40450, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - On Reset - Remove byte for submerged'),
(40450, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Cast \'Emerge\' on self'),
(40450, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Remove not-selectable flag'),
(40450, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Attack Random Player'),
(40450, 0, 4, 0, 0, 0, 100, 0, 1500, 1500, 10000, 10000, 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - In Combat - Cast \'Smash\' on victim');
UPDATE `creature_template` SET `DamageModifier`= 10, `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `unit_flags`= 64 WHERE `entry` = 49296;

-- Ptah's Jeweled Scarab SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1`= 49297, `DamageModifier`= 5 WHERE `entry`= 40458;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40458 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40458, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - On Reset - Remove byte for submerged'),
(40458, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Cast \'Emerge\' on self'),
(40458, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Remove not-selectable flag'),
(40458, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Attack Random Player');
UPDATE `creature_template` SET `DamageModifier`= 5, `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16 WHERE `entry` = 49297;
