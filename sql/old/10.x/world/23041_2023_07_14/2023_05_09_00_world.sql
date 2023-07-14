UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13117; -- 13117 (Horde Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13116; -- 13116 (Alliance Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template` SET `ScriptName`='', `AIName`='' WHERE `entry` IN (13116, 13117, 88238, 88239); -- BGs

-- allow the graveyard teleporters to see dead players
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|0x00000400 WHERE `entry` IN (26350, 26351);

-- Graveyard Teleport
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 46893;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(46893, 0, 0, 120, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 22, 30);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_spirit_heal_aoe', 'spell_gen_spirit_heal_personal', 'spell_gen_spirit_heal_channel', 'spell_gen_waiting_to_resurrect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22012, 'spell_gen_spirit_heal_aoe'),
(156758, 'spell_gen_spirit_heal_personal'),
(22011, 'spell_gen_spirit_heal_channel'),
(2584, 'spell_gen_waiting_to_resurrect');

DELETE FROM `creature_template_addon` WHERE `entry` IN (26350, 26351);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(26350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '8149'), -- 26350 (Alliance Graveyard Teleporter) - Super Invis
(26351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '8149'); -- 26351 (Horde Graveyard Teleporter) - Super Invis

UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry` IN(26350, 26351);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26350, 26351) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26350,0,0,0,11,0,100,0,0,0,0,0,0,'',11,46893,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Alliance Graveyard Teleporter - On spawn - Cast "Graveyard Teleport"'),
(26351,0,0,0,11,0,100,0,0,0,0,0,0,'',11,46893,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Horde Graveyard Teleporter - On spawn - Cast "Graveyard Teleport"');
