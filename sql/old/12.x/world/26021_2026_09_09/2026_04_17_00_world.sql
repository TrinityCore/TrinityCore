-- Quest
DELETE FROM `quest_details` WHERE `ID`=88719;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(88719, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- A Voice from the Light

DELETE FROM `creature_queststarter` WHERE (`id`=241677 AND `quest`=88719);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(241677, 88719, 66838); -- A Voice from the Light offered by Image of Lady Liadrin

DELETE FROM `quest_template_addon` WHERE `ID` = 88719;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(88719, 0, 0, 0, 91281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
UPDATE `gossip_menu` SET `VerifiedBuild`=66838 WHERE (`MenuID`=39008 AND `TextID`=610006);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39008 AND `OptionID`=3);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39008, 133523, 3, 0, 'Please summon me to the Isle of Quel\'Danas.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (39008));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 39008, 3, 0, 0, 47, 0, 88719, 8, 0, '', 0, 'Player for which gossip text is shown has A Voice from the Light (88719) in state incomplete');
