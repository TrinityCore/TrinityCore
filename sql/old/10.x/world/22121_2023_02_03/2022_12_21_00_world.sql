-- Chain Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (66577, 66589, 72240, 66596);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(66577, 0, 0, 0, 65436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(66589, 0, 0, 0, 66577, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(72240, 0, 0, 0, 66577, 67700, -72240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(66596, 0, 0, 0, 66589, 67700, -72240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- update Creature Movement
DELETE FROM `creature_movement_override` WHERE `SpawnId` IN (1250013, 1250012);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(1250013, 0, 0, 1, 1, 0, 0, NULL),
(1250012, 0, 0, 1, 0, 0, 0, NULL);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 19329 AND `SourceEntry` = 1519);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 19329, 1519, 0, 0, 47, 0, 72240, 64, 0, 0, 'Apply Phase 19329 If Quest 72240 is rewarded'),
(26, 19329, 1519, 0, 0, 47, 0, 66596, 64, 0, 1, 'Apply Phase 19329 If Quest 66596 is not rewarded');
