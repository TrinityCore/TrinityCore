-- Warrior
DELETE FROM `quest_template_addon` WHERE `ID` IN (28766, 28774, 26913, 28789, 28797, 28823, 28813, 3100);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28766, 1, 0, 28774),
(28774, 1, 28766, 3100),
(3100, 1, 28774, 26913),
(26913, 1, 3100, 28789),
(28789, 1, 26913, 28797),
(28797, 1, 28789, 28823),
(28823, 1, 28797, 26389),
(28813, 1, 28789, 0);

-- Paladin
DELETE FROM `quest_template_addon` WHERE `ID` IN (28762, 28770, 3101, 26918, 28785, 28793, 28819, 28809);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28762, 2, 0, 28770),
(28770, 2, 28762, 3101),
(3101, 2, 28770, 26918),
(26918, 2, 3101, 28785),
(28785, 2, 26918, 28793),
(28793, 2, 28785, 28819),
(28819, 2, 28793, 26389),
(28809, 2, 28785, 0);

-- Hunter
DELETE FROM `quest_template_addon` WHERE `ID` IN (28767, 28759, 26910, 26917, 28780, 28791, 28817, 28806);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28767, 4, 0, 28759),
(28759, 4, 28767, 26910),
(26910, 4, 28759, 26917),
(26917, 4, 26910, 28780),
(28780, 4, 26917, 28791),
(28791, 4, 28780, 28817),
(28817, 4, 28791, 26389),
(28806, 4, 28780, 0);

-- Rogue
DELETE FROM `quest_template_addon` WHERE `ID` IN (28764, 28772, 3102, 26915, 28787, 28795, 28821, 28811);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28764, 8, 0, 28772),
(28772, 8, 28764, 3102),
(3102, 8, 28772, 26915),
(26915, 8, 3102, 28787),
(28787, 8, 26915, 28795),
(28795, 8, 28787, 28821),
(28821, 8, 28795, 26389),
(28811, 8, 28787, 0);

-- Priest
DELETE FROM `quest_template_addon` WHERE `ID` IN (28763, 28771, 3103, 26919, 28786, 28794, 28820, 28810);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28763, 16, 0, 28771),
(28771, 16, 28763, 3103),
(3103, 16, 28771, 26919),
(26919, 16, 3103, 28786),
(28786, 16, 26919, 28794),
(28794, 16, 28786, 28820),
(28820, 16, 28794, 26389),
(28810, 16, 28786, 0);

-- Mage
DELETE FROM `quest_template_addon` WHERE `ID` IN (28757, 28769, 3104, 26916, 28784, 28792, 28818, 28808);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28757, 128, 0, 28769),
(28769, 128, 28757, 3104),
(3104, 128, 28769, 26916),
(26916, 128, 3104, 28784),
(28784, 128, 26916, 28792),
(28792, 128, 28784, 28818),
(28818, 128, 28792, 26389),
(28808, 128, 28784, 0);

-- Warlock
DELETE FROM `quest_template_addon` WHERE `ID` IN (28765, 28773, 3105, 26914, 28788, 28796, 28822, 28812);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestID`) VALUES
(28765, 256, 0, 28773),
(28773, 256, 28765, 3105),
(3105, 256, 28773, 26914),
(26914, 256, 3105, 28788),
(28788, 256, 26914, 28796),
(28796, 256, 28788, 28822),
(28822, 256, 28796, 26389),
(28812, 256, 28788, 0);

DELETE FROM `creature_queststarter` WHERE `quest` IN (28789, 28785, 28780, 28787, 28786, 28784, 28788);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(911, 28789),
(925, 28785),
(43278, 28780),
(915, 28787),
(375, 28786),
(198, 28784),
(459, 28788);

