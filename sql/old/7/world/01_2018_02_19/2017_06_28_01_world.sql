-- 
-- Fix Valley of Trials Quests
-- Quest Starters
DELETE FROM `creature_queststarter` WHERE `id`=3143 AND `quest`IN (25126,25127,25172);
DELETE FROM `creature_queststarter` WHERE `id`=3145 AND `quest`IN (25131,25132,25133);
DELETE FROM `creature_queststarter` WHERE `id`=3287 AND `quest`IN (25129,25130);
DELETE FROM `creature_queststarter` WHERE `id`=5887 AND `quest`IN (25128);
DELETE FROM `creature_queststarter` WHERE `id`=9796 AND `quest`IN (25136);
DELETE FROM `creature_queststarter` WHERE `id`=10176 AND `quest`IN (25152);
DELETE FROM `creature_queststarter` WHERE `id`=11378 AND `quest`IN (37446,25135,25134);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(3143, 25126),
(3143, 25127),
(3143, 25172),
(3145, 25131),
(3145, 25132),
(3145, 25133),
(3287, 25129),
(3287, 25130),
(5887, 25128),
(9796, 25136),
(10176, 25152),
(11378, 37446),
(11378, 25135);
-- Quest Enders
DELETE FROM `creature_questender` WHERE `id`=3143 AND `quest` IN (787,788,789,804,4641,25126,25127,25130,25152,25172);
DELETE FROM `creature_questender` WHERE `id`=3145 AND `quest` IN (792,794,1499,25131,25132);
DELETE FROM `creature_questender` WHERE `id`=3287 AND `quest` IN (790,25128,25129);
DELETE FROM `creature_questender` WHERE `id`=5887 AND `quest` IN (1463,1516,1518);
DELETE FROM `creature_questender` WHERE `id`=9796 AND `quest` IN (4402,25136);
DELETE FROM `creature_questender` WHERE `id`=11378 AND `quest` IN (5441,6394,25134,25135,37446);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(3143, 25126),
(3143, 25127),
(3143, 25130),
(3143, 25152),
(3143, 25172),
(3145, 25131),
(3145, 25132),
(3287, 25128),
(3287, 25129),
(9796, 25136),
(11378, 25135),
(11378, 37446);
-- Quest_Template_Addon Fixs
DELETE FROM `quest_template_addon` WHERE `ID` IN (25126, 25127, 25128, 25129, 25130, 25131, 25133, 25135, 25136, 25172, 37446);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(25126, 0, 0, 0, 25152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25127, 0, 0, 0, 25172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25128, 0, 0, 0, 37446, 25129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25129, 0, 0, 0, 25128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25130, 0, 0, 0, 25129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25131, 0, 0, 0, 25127, 25132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25133, 0, 0, 0, 25132, 25167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25135, 0, 0, 0, 25131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25136, 0, 0, 0, 25126, 37446, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25172, 0, 0, 0, 25126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37446, 0, 0, 0, 25136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
