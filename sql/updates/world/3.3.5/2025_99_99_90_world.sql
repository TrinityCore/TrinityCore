UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13117; -- 13117 (Horde Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13116; -- 13116 (Alliance Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617 58729' WHERE `entry`=31841; -- 31841 (Horde Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617 58729' WHERE `entry`=31842; -- 31842 (Alliance Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template` SET `ScriptName`='', `AIName`='' WHERE `entry` IN (13116, 13117); -- BGs

-- allow the graveyard teleporters to see dead players
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|0x00000400 WHERE `entry` IN (26350, 26351);

-- Graveyard Teleport
DELETE FROM `spell_dbc` WHERE `Id` = 46893;
INSERT INTO `spell_dbc` (`Id`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectItemType1`,`EffectItemType2`,`EffectItemType3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`SpellName`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`AreaGroupId`,`SchoolMask`) VALUES
(46893,0,0,256,0,1,4096,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,-1,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,0,0,30,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Graveyard Teleport',0,0,0,0,0,0,0,0,0,0,0,0,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_spirit_heal_aoe', 'spell_gen_spirit_heal_personal', 'spell_gen_spirit_heal_channel', 'spell_gen_waiting_to_resurrect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22012, 'spell_gen_spirit_heal_aoe'),
(22011, 'spell_gen_spirit_heal_channel'),
(2584, 'spell_gen_waiting_to_resurrect');

DELETE FROM `creature_template_addon` WHERE `entry` IN (26350, 26351);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(26350, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '8149'), -- 26350 (Alliance Graveyard Teleporter) - Super Invis
(26351, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '8149'); -- 26351 (Horde Graveyard Teleporter) - Super Invis

UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry` IN(26350, 26351);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26350, 26351) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26350,0,0,0,11,0,100,0,0,0,0,0,0,11,46893,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Alliance Graveyard Teleporter - On spawn - Cast "Graveyard Teleport"'),
(26351,0,0,0,11,0,100,0,0,0,0,0,0,11,46893,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Horde Graveyard Teleporter - On spawn - Cast "Graveyard Teleport"');
