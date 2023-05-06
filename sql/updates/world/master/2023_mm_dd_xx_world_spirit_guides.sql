UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13117; -- 13117 (Horde Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13116; -- 13116 (Alliance Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template` SET `ScriptName`='npc_area_spirit_healer', `AIName`='' WHERE `entry` IN (13116, 13117, 88238, 88239);

-- Graveyard Teleport
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 46893;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(46893, 0, 0, 120, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 22, 30);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_spirit_heal_aoe', 'spell_gen_spirit_heal_personal', 'spell_gen_waiting_to_resurrect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22012, 'spell_gen_spirit_heal_aoe'),
(156758, 'spell_gen_spirit_heal_personal'),
(2584, 'spell_gen_waiting_to_resurrect');

DELETE FROM `creature_template_addon` WHERE `entry` IN (26350, 26351);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(26350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '8149'), -- 26350 (Alliance Graveyard Teleporter) - Super Invis
(26351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '8149'); -- 26351 (Horde Graveyard Teleporter) - Super Invis
