-- 
DELETE FROM `spell_dbc` WHERE `Id`=39797;
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectItemType1`, `EffectItemType2`, `EffectItemType3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `SpellName`) VALUES 
(39797, 0, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 7, 0, -1, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 185541, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 'Summon Raven Stone');

DELETE FROM `gameobject` WHERE `id`=185541;
DELETE FROM `gameobject_addon` WHERE `guid` IN (39908, 39909, 39910, 39911, 39912, 39913, 39914, 39915, 39916, 39917, 39918, 39919, 39920);
DELETE FROM `spawn_group` WHERE `spawnId` IN (39908, 39909, 39910, 39911, 39912, 39913, 39914, 39915, 39916, 39917, 39918, 39919, 39920) AND `spawnType`=1;

UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=768 WHERE  `entry`=22972;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22972 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2297200,2297201,2297202) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22972, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2297200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - On Just Summoned - Action list'),
(22972, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2297201, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - On Just Summoned - Action list'),
(2297200, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(2297200, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 89, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Random Move'),
(2297200, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(2297200, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(2297200, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 30, 90, 0, 'Cenarion Sparrowhawk - Action list - Move Offset'),
(2297200, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Despawn'),
(2297201, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(2297201, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 22986, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Random Move'),
(2297201, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(22972, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 80, 2297202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - On Movement Inform - Action list'),
(2297202, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Say text'),
(2297202, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 11, 39797, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Cast Summon Raven Stone'),
(2297202, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 22986, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Despawn'),
(2297202, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 30, 90, 0, 'Cenarion Sparrowhawk - Action list - Move Offset'),
(2297202, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Sparrowhawk - Action list - Despawn');

DELETE FROM `creature_text` WHERE `CreatureID`=22972;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22972, 0, 0, "%s looks at you for a moment, then motions for you to follow.", 16, 0, 100, 0, 0, 0, 20689, 0, 'Cenarion Sparrowhawk'),
(22972, 1, 0, '%s surveys the ground for buried raven stones.', 16, 0, 100, 0, 0, 0, 20675, 0, 'Cenarion Sparrowhawk'),
(22972, 2, 0, '%s locates a buried raven stone.', 16, 0, 100, 0, 0, 0, 20676, 0, 'Cenarion Sparrowhawk'),
(22972, 3, 0, "%s doesn't seem to have had any luck finding raven stones nearby.", 16, 0, 100, 0, 0, 0, 21065, 0, 'Cenarion Sparrowhawk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22  AND `SourceEntry`=22972 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 22972, 0, 0, 29, 1, 22986, 40, 0, 1, 0, 0, '', 'Only run SAI if No Invis Rune Stone within 40 yards'),
(22, 2, 22972, 0, 0, 29, 1, 22986, 40, 0, 0, 0, 0, '', 'Only run SAI if Invis Rune Stone within 40 yards');

UPDATE `creature` SET `spawntimesecs`=320 WHERE `id`=22986;
DELETE FROM `creature` WHERE `guid` IN (87298, 87308, 87369, 87376, 91131, 91132, 91133, 128906);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(87298, 22986, 530, 0, 0, 1, 1, 0, 0, -3709.53, 3744.06, 277.073, 1.62054, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(87308, 22986, 530, 0, 0, 1, 1, 0, 0, -3758.84, 3732.39, 276.846, 5.73288, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(87369, 22986, 530, 0, 0, 1, 1, 0, 0, -3687.76, 3677.07, 275.927, 5.73288, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(87376, 22986, 530, 0, 0, 1, 1, 0, 0, -3591.33, 3724.59, 285.996, 5.73288, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(91131, 22986, 530, 0, 0, 1, 1, 0, 0, -3615.09, 3667.87, 277.788, 1.00477, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(91132, 22986, 530, 0, 0, 1, 1, 0, 0, -3642.5, 3189.22, 314.596, 1.50114, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(91133, 22986, 530, 0, 0, 1, 1, 0, 0, -3967.37, 3323.17, 289.012, 1.50114, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(128906, 22986, 530, 0, 0, 1, 1, 0, 0, -3523.61, 3591.08, 279.754, 0.483256, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0);
