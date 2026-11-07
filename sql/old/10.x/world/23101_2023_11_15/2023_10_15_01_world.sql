-- Update template
UPDATE `creature_template` SET `ScriptName` = 'npc_cyana_nightglaive_freed_private' WHERE `entry` = 94377;
UPDATE `creature_template` SET `ScriptName` = 'npc_izal_whitemoon_freed_private' WHERE `entry` = 93117;
UPDATE `creature_template` SET `ScriptName` = 'npc_belath_dawnblade_freed_private' WHERE `entry` = 94400;
UPDATE `creature_template` SET `ScriptName` = 'npc_mannethrel_darkstar_freed_private' WHERE `entry` = 93230;

-- Serverside Spell Effect (add Dummy effect to Credit Spell)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (204714, 204715, 204711, 204712) AND `EffectIndex` = 1;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(204714, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204715, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204711, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204712, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` IN (204711, 204714, 204712, 204715);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(204711, 'spell_cyana_nightglaive_killcredit_set_them_free'),
(204714, 'spell_izal_whitemoon_killcredit_set_them_free'),
(204712, 'spell_belath_dawnblade_killcredit_set_them_free'),
(204715, 'spell_mannethrel_darkstar_killcredit_set_them_free');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (94377, 93117, 94400, 93230);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(94377, 0, 0, 'I... will not... give in!', 14, 0, 100, 0, 0, 55090, 1, 96405, 0, 'Cyana Nightglaive to Player'),
(94377, 1, 0, 'I will never be taken prisoner again. Never!', 12, 0, 100, 5, 0, 55089, 1, 95081, 0, 'Cyana Nightglaive to Player'),
(93117, 0, 0, 'The pain!', 12, 0, 100, 0, 0, 55226, 1, 75975, 0, 'Izal Whitemoon to Player'),
(93117, 1, 0, 'A slight setback. I assure you it will not happen again.', 12, 0, 100, 274, 0, 55227, 1, 96644, 0, 'Izal Whitemoon to Player'),
(94400, 0, 0, 'I will destroy all of you.', 12, 0, 100, 0, 0, 55052, 1, 96411, 0, 'Belath Dawnblade to Player'),
(94400, 1, 0, 'I will kill every last demon in my way.', 12, 0, 100, 5, 0, 55053, 1, 96643, 0, 'Belath Dawnblade to Player'),
(93230, 0, 0, 'So weak... hard to contain... my energy.', 12, 0, 100, 0, 0, 56847, 1, 96407, 0, 'Mannethrel Darkstar to Player'),
(93230, 1, 0, 'I almost lost the fight against the fel energy inside me.', 12, 0, 100, 6, 0, 55311, 1, 96202, 0, 'Mannethrel Darkstar to Player');

-- Update Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4925 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4925, 0, 0, 0, 47, 0, 38759, 2|64, 0, 1, 'Apply Phase 4925 if Quest 38759 is not complete | rewarded'),
(26, 4925, 0, 0, 0, 48, 0, 280293, 0, 1, 1, 'Apply Phase 4925 if Questobjective 280293 (Cyana Nightglaive) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4931 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4931, 0, 0, 0, 47, 0, 38759, 2|64, 0, 1, 'Apply Phase 4931 if Quest 38759 is not complete | rewarded'),
(26, 4931, 0, 0, 0, 48, 0, 278928, 0, 1, 1, 'Apply Phase 4931 if Questobjective 278928 (Belath Dawnblade) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4927 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4927, 0, 0, 0, 47, 0, 38759, 2|64, 0, 1, 'Apply Phase 4927 if Quest 38759 is not complete | rewarded'),
(26, 4927, 0, 0, 0, 48, 0, 278413, 0, 1, 1, 'Apply Phase 4927 if Questobjective 278413 (Mannethrel Darkstar) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4932 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4932, 0, 0, 0, 47, 0, 38759, 2|64, 0, 1, 'Apply Phase 4932 if Quest 38759 is not complete | rewarded'),
(26, 4932, 0, 0, 0, 48, 0, 278929, 0, 1, 1, 'Apply Phase 4932 if Questobjective 278929 (Izal Whitemoon) is not rewarded');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=38759;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38759, 0, 0, 0, 0, 0, 0, 0, 0, 51536); -- Set Them Free

UPDATE `quest_details` SET `VerifiedBuild`=51536 WHERE `ID`=39049;

DELETE FROM `creature_queststarter` WHERE (`id`=94410 AND `quest`=38759);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(94410, 38759, 51536); -- Set Them Free offered Allari the Souleater

DELETE FROM `quest_template_addon` WHERE `ID` = 38759;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(38759, 0, 0, 0, 40378, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Path Cyana Nightglaive
SET @ENTRY := 94377;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 761.4028, 2545.91, -70.2478, NULL, 0, 1),
(@PATH, 1, 757.8733, 2534.789, -69.6983, NULL, 0, 1),
(@PATH, 2, 766.3857, 2513.429, -67.93224, NULL, 0, 1),
(@PATH, 3, 777.6111, 2496.193, -65.42938, NULL, 0, 1),
(@PATH, 4, 787.2969, 2493.281, -63.80701, NULL, 0, 1),
(@PATH, 5, 806.2847, 2490.347, -61.61884, NULL, 0, 1),
(@PATH, 6, 818, 2492.882, -60.87885, NULL, 0, 1),
(@PATH, 7, 835.4445, 2502.257, -60.18602, NULL, 0, 1);

-- Path Izal Whitemoon
SET @ENTRY := 93117;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 872.0009, 2574.877, -56.5737, NULL, 0, 1),
(@PATH, 1, 865.0009, 2567.877, -56.3237, NULL, 0, 1),
(@PATH, 2, 858.2509, 2560.877, -55.5737, NULL, 0, 1),
(@PATH, 3, 852.2509, 2554.377, -55.8237, NULL, 0, 1),
(@PATH, 4, 845.7509, 2545.627, -55.8237, NULL, 0, 1),
(@PATH, 5, 844.7509, 2540.877, -55.8237, NULL, 0, 1),
(@PATH, 6, 847.7509, 2532.127, -57.3237, NULL, 0, 1),
(@PATH, 7, 853.5009, 2527.127, -57.8237, NULL, 0, 1),
(@PATH, 8, 857.5009, 2525.877, -57.8237, NULL, 0, 1);

-- Path Belath Dawnblade
SET @ENTRY := 94400;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 759.908, 2465.828, -61.56675, NULL, 0, 1),
(@PATH, 1, 767.6511, 2465.424, -61.31778, NULL, 0, 1),
(@PATH, 2, 773.4965, 2466.222, -59.81237, NULL, 0, 1);

-- Path Mannethrel Darkstar
SET @ENTRY := 93230;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 902.1406, 2470.149, -66.02625, NULL, 0),
(@PATH, 1, 895.1111, 2470.462, -65.26515, NULL, 0),
(@PATH, 2, 887.8021, 2470.868, -64.38623, NULL, 0),
(@PATH, 3, 874.3594, 2473.307, -62.70589, NULL, 0),
(@PATH, 4, 864.5018, 2476.795, -61.33098, NULL, 0);
