-- Disable Shadowglen quests deprecated between 3.3.5/WotLK and Legion
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3116,3117,3118,3119,3120,26945,26946,26947,26948,26949);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3116, 0, '', '', 'Deprecated quest: Simple Sigil'),
(1,  3117, 0, '', '', 'Deprecated quest: Etched Sigil'),
(1,  3118, 0, '', '', 'Deprecated quest: Encrypted Sigil'),
(1,  3119, 0, '', '', 'Deprecated quest: Hallowed Sigil'),
(1,  3120, 0, '', '', 'Deprecated quest: Verdant Sigil'),
(1, 26945, 0, '', '', 'Deprecated quest: Learning New Techniques'),
(1, 26946, 0, '', '', "Deprecated quest: A Rogue's Advantage"),
(1, 26947, 0, '', '', "Deprecated quest: A Woodsman's Training"),
(1, 26948, 0, '', '', 'Deprecated quest: Moonfire'),
(1, 26949, 0, '', '', 'Deprecated quest: Learning the Word');

-- Shadowglen quest starters
DELETE FROM `creature_queststarter` WHERE `id`=2077 AND `quest`IN (3116,3117,3118,3119,3120,26841,28715);
DELETE FROM `creature_queststarter` WHERE `id`=2079 AND `quest`IN (3116,3117,3118,3119,3120,26841,28713,28714,28723,28734);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES
(2077, 28715),
(2079, 28713),
(2079, 28714),
(2079, 28723),
(2079, 28734);

DELETE FROM `creature_queststarter` WHERE `id`= 3593 AND `quest` = 26945;
DELETE FROM `creature_queststarter` WHERE `id`= 3594 AND `quest` = 26946;
DELETE FROM `creature_queststarter` WHERE `id`= 3595 AND `quest` = 26949;
DELETE FROM `creature_queststarter` WHERE `id`= 3596 AND `quest` = 26947;
DELETE FROM `creature_queststarter` WHERE `id`= 3597 AND `quest` = 26948;

DELETE FROM `creature_queststarter` WHERE `quest` = 28723 AND `id` IN (3593,3594,3595,3596,3597,43006);

-- Shadowglen quest enders
DELETE FROM `creature_questender` WHERE `id`=2079 AND `quest` IN (456,457,28713,28714,28723);
DELETE FROM `creature_questender` WHERE `id`=3514 AND `quest` IN (920,921,28730);
DELETE FROM `creature_questender` WHERE `id`=3593 AND `quest` IN (3116, 26945);
DELETE FROM `creature_questender` WHERE `id`=3594 AND `quest` IN (3118, 26946);
DELETE FROM `creature_questender` WHERE `id`=3595 AND `quest` IN (3119, 26949);
DELETE FROM `creature_questender` WHERE `id`=3596 AND `quest` IN (3117, 26947);
DELETE FROM `creature_questender` WHERE `id`=3597 AND `quest` IN (3120, 26948);
INSERT INTO `creature_questender` (`id`,`quest`) VALUES
(2079, 28713),
(2079, 28714),
(3514, 28730);

-- Quest Template Addon
UPDATE `quest_template_addon` SET `NextQuestID`= 28723 WHERE `ID`= 28714;
UPDATE `quest_template_addon` SET `NextQuestID`= 28715 WHERE `ID`= 28734;

DELETE FROM `quest_template_addon` WHERE `ID`= 2519;
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`) VALUES
(2519, 0, 0, 0, 28730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
