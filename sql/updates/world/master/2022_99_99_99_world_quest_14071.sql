DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5499, 5498, 5497);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5499, 'SmartTrigger'), -- Izzy
(5498, 'SmartTrigger'), -- Gobber
(5497, 'SmartTrigger'); -- Ace

-- AreaTrigger SAI
DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` IN (5499, 5498, 5497);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5499, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 85, 66600, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On trigger - self: Cast spell 66600 on Invoker'),
(5498, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 85, 66599, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On trigger - self: Cast spell 66599 on Invoker'),
(5497, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 85, 66597, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On trigger - self: Cast spell 66597 on Invoker');

-- Spelltarget Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` IN (66600, 66599, 66597));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 66600, 0, 0, 31, 0, 3, 34890, 0, 0, 0, 0, '', 'Summon Izzy can only hit Entry 34890'),
(13, 1, 66599, 0, 0, 31, 0, 3, 34954, 0, 0, 0, 0, '', 'Summon Gobber can only hit Entry 34954'),
(13, 1, 66597, 0, 0, 31, 0, 3, 34892, 0, 0, 0, 0, '', 'Summon Ace can only hit Entry 34892');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=66301;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 66301, 0, 1, 31, 0, 3, 35063, 0, 0, 0, 0, '', 'Spell: Hot Rod Knockback can only hit Entry 35063'),
(13, 1, 66301, 0, 0, 31, 0, 3, 35075, 0, 0, 0, 0, '', 'Spell: Hot Rod Knockback can only hit Entry 35063');

DELETE FROM `creature_template_spell` WHERE `CreatureID`=34840;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(34840, 0, 66300, 41031),
(34840, 2, 66298, 44325),
(34840, 3, 66299, 41031);

-- Trigger Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` IN (5499, 5498, 5497));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Trigger Izzy
(22, 1, 5499, 2, 0, 47, 0, 14071, 8, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Quest 14071 in Progress'),
(22, 1, 5499, 2, 0, 48, 0, 265516, 0, 0, 0, 0, 1, '', 'SAI AreaTrigger needs Objective 265516 not rewarded'),
(22, 1, 5499, 2, 0, 1, 0, 66392, 1, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Player with Aura 66392 Effect 1'),
-- Trigger Gobber
(22, 1, 5498, 2, 0, 47, 0, 14071, 8, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Quest 14071 in Progress'),
(22, 1, 5498, 2, 0, 48, 0, 265518, 0, 0, 0, 0, 1, '', 'SAI AreaTrigger needs Objective 265518 not rewarded'),
(22, 1, 5498, 2, 0, 1, 0, 66392, 1, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Player with Aura 66392 Effect 1'),
-- Trigger Ace
(22, 1, 5497, 2, 0, 47, 0, 14071, 8, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Quest 14071 in Progress'),
(22, 1, 5497, 2, 0, 48, 0, 265517, 0, 0, 0, 0, 1, '', 'SAI AreaTrigger needs Objective 265517 not rewarded'),
(22, 1, 5497, 2, 0, 1, 0, 66392, 1, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Player with Aura 66392 Effect 1');

DELETE FROM `creature_text` WHERE `CreatureID` IN (35063, 35075);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(35063, 0, 0, 'Learn how to drive you maniac!', 14, 0, 25, 5, 0, 12924, 35311, 0, 'Kezan Citizen to Player'),
(35063, 0, 1, 'Ouch!', 14, 0, 25, 11, 0, 1411, 35312, 0, 'Kezan Citizen to Player'), -- BroadcastTextID: 35312 - 38769 - 44855 - 57589 - 62060 - 146032 - 180058
(35063, 0, 2, 'My neck! I\'m gonna sue!', 14, 0, 25, 11, 0, 1411, 35313, 0, 'Kezan Citizen to Player'),
(35063, 0, 3, 'The Trade Prince will hear about this, $n!', 14, 0, 25, 1, 0, 1411, 35316, 0, 'Kezan Citizen to Player'),
(35063, 0, 4, 'I\'ll get you, $n!', 14, 0, 25, 1, 0, 1411, 35314, 0, 'Kezan Citizen to Player'),
(35075, 0, 0, 'Ouch!', 14, 0, 25, 5, 0, 18500, 35312, 0, 'Kezan Citizen to Player'), -- BroadcastTextID: 35312 - 38769 - 44855 - 57589 - 62060 - 146032 - 180058
(35075, 0, 1, 'Learn how to drive you maniac!', 14, 0, 25, 273, 0, 18500, 35311, 0, 'Kezan Citizen to Player'),
(35075, 0, 2, 'You\'re a public nuisance, $n!', 14, 0, 25, 5, 0, 18500, 35315, 0, 'Kezan Citizen to Player'),
(35075, 0, 3, 'You\'re gonna hear from my lawyer!', 14, 0, 25, 274, 0, 18500, 35309, 0, 'Kezan Citizen to Player'),
(35075, 0, 4, 'The Trade Prince will hear about this, $n!', 14, 0, 25, 5, 0, 1411, 35316, 0, 'Kezan Citizen to Player'),
(35075, 0, 5, 'I\'ll get you, $n!', 14, 0, 25, 1, 0, 18500, 35314, 0, 'Kezan Citizen to Player');

 -- Kezan Citizen smart ai
SET @ENTRY := 35063;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 66301, 0, 1000, 1000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell 66301 hit (wait 1000 - 1000 ms before next trigger) - Self: Talk 0 to invoker');

 -- Kezan Citizen smart ai
SET @ENTRY := 35075;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 66301, 0, 1000, 1000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell 66301 hit (wait 1000 - 1000 ms before next trigger) - Self: Talk 0 to invoker');

 -- Megs Dreadshredder smart ai
SET @ENTRY := 34874;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14071, 0, 0, 0, 85, 66394, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Rolling with my Homies (14071) - Player who accepted quest: Cast spell 66394 on self'),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 14071, 0, 0, 0, 85, 66679, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Rolling with my Homies (14071) - Player who accepted quest: Cast spell 66679 on self'),
(@ENTRY, 0, 2, 0, 19, 0, 100, 0, 14071, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Rolling with my Homies (14071) - Self: Talk Use the Keys to the Hot Rod |TInterfaceIconsinv_misc_key_12.... (1) to invoker'),
(@ENTRY, 0, 3, 0, 20, 0, 100, 0, 14071, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest Rolling with my Homies (14071) - Self: Talk Here they are! Okay, you three make sure that you help him o... (2) to invoker');

 -- Hot Rod smart ai
SET @ENTRY := 34840;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 86, 66392, 0, 22, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Summoner\'s vehicle: Cast spell 66392 at Summoner');

 -- Ace smart ai
SET @ENTRY := 34957;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 33, 34957, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Give kill credit Ace (34957)'),
(@ENTRY, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 85, 66589, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Summoner: Cast spell 66589 on self');

 -- Gobber smart ai
SET @ENTRY := 34958;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 33, 34958, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Give kill credit Gobber (34958)'),
(@ENTRY, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 85, 66590, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Summoner: Cast spell 66590 on self');

 -- Izzy smart ai
SET @ENTRY := 34959;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 33, 34959, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Give kill credit Izzy (34959)'),
(@ENTRY, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 85, 66591, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Summoner: Cast spell 66591 on self');

DELETE FROM `spell_area` WHERE `quest_start` =14071;

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (66395, 66396, 66397, 66394, 66589, 66590, 66591, 66612, 66148, 66609, 66617, 66618, 66679);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(66395, 0, 0, 6, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66396, 0, 0, 6, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66397, 0, 0, 6, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66394, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66394, 1, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66394, 2, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66589, 0, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66590, 0, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66591, 0, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66612, 0, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 22, 7),
(66148, 0, 0, 6, 23, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 66609, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66609, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66617, 0, 0, 6, 226, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66618, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(66679, 0, 0, 6, 226, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 66612);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 66612, 0, 0, 31, 0, 3, 34957, 0, 0, 0, 0, '', 'Spell "Rolling with my Homies: Despawn Summoned Friends can hit Ace'),
(13, 1, 66612, 0, 1, 31, 0, 3, 34958, 0, 0, 0, 0, '', 'Spell "Rolling with my Homies: Despawn Summoned Friends can hit Gobber'),
(13, 1, 66612, 0, 2, 31, 0, 3, 34959, 0, 0, 0, 0, '', 'Spell "Rolling with my Homies: Despawn Summoned Friends can hit Izzy');

DELETE FROM `creature_template_addon` WHERE `entry` IN (34840, 34957, 34958, 34959);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(34840, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '66148'),
(34957, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '66617'),
(34958, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '66617'),
(34959, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '66617');

UPDATE `creature_template` SET `unit_flags` = 16392, `unit_flags2` = 2162688, `VehicleID` = 448 WHERE `entry` = 34840;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (66298, 66299, 66617, 66618, 66612);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66298, 'spell_hot_rod_honk_horn'),
(66299, 'spell_hot_rod_radio'),
(66617, 'spell_hot_rod_periodic_check'),
(66618, 'spell_hot_rod_mount'),
(66612, 'spell_despawn_summoned_friends');

UPDATE `quest_template_addon` SET `ScriptName` = 'quest_rolling_with_my_homies' WHERE `ID` = 14071;
