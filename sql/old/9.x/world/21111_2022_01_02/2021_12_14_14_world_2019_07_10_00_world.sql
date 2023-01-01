--
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=0 WHERE `ID`=12181;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=12181;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 12181, 0, 0, 47, 0, 12189, 1, 0, 0, 0, 0, "", "Quest 'Give it a Name' can only be taken if quest 'Imbeciles Abound!' is not taken/complete/rewarded AND"),
(19, 0, 12181, 0, 0, 47, 0, 12188, 1, 0, 0, 0, 0, "", "Quest 'Give it a Name' can only be taken if quest 'The Forsaken Blight and You: How Not to Die' is not taken/complete/rewarded");

UPDATE `quest_template_addon` SET `ExclusiveGroup`=10068 WHERE `ID` IN (10068, 10069, 10070, 10071, 10072, 10073);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1522 WHERE `ID` IN (1522, 1523, 2983, 2984);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1528 WHERE `ID` IN (1528, 1529, 2985, 2986);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=4736 WHERE `ID` IN (4736, 4737, 4738, 4739);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=4965 WHERE `ID` IN (4965, 4967, 4968, 4969);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=5066 WHERE `ID` IN (5066, 5090, 5091, 10373);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=5093 WHERE `ID` IN (5093, 5094, 5095, 10374);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=3763 WHERE `ID` IN (3763, 3789, 3790, 10520);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=235 WHERE `ID` IN (235, 742, 6382);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=9500 WHERE `ID` IN (9500, 9502, 10490);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=9547 WHERE `ID` IN (9547, 9551, 10491);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=2260 WHERE `ID` IN (2260, 2298, 2300);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=936 WHERE `ID` IN (936, 3762, 3784);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1698 WHERE `ID` IN (1698, 10371);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=5249 WHERE `ID` IN (5249, 5250);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=6611 WHERE `ID` IN (6611, 6612);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=10891 WHERE `ID` IN (10891, 10892);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=11177 WHERE `ID` IN (11177, 11225);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=11302 WHERE `ID` IN (11302, 11312);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=787 WHERE `ID` IN (787, 4641);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=2996 WHERE `ID` IN (2996, 3001);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=3787 WHERE `ID` IN (3787, 3788);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=8275 WHERE `ID` IN (8275, 8276);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=11995 WHERE `ID` IN (11995, 12440);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=12161 WHERE `ID` IN (12161, 12425);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=12182 WHERE `ID` IN (12182, 12189);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=13226 WHERE `ID` IN (13226, 13227);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1478 WHERE `ID` IN (1478, 10789);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=12208 WHERE `ID` IN (12208, 12210);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=11481 WHERE `ID` IN (11481, 11482);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1506 WHERE `ID` IN (1506, 10790);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=1685 WHERE `ID` IN (1685, 1715);
