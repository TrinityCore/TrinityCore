-- Brutal Armor set Quest chaining
UPDATE `quest_template` SET `AllowableRaces`=16 WHERE `ID`=1841;
UPDATE `quest_template` SET `AllowableRaces`=32 WHERE `ID`=1840;
UPDATE `quest_template` SET `AllowableRaces`=2|128 WHERE `ID`=1839;
UPDATE `quest_template_addon` SET `PrevQuestID`=1848 WHERE `ID` IN (1841,1840,1839,1846,1844,1842);

-- BreadCrumb Quest "Velora Nitely and the Brutal Legguards"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (1841,1846);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1841,0,0,14,0,1846,0,0,0,0,0,"","Quest 'Velora Nitely and the Brutal Legguards' can only be taken if quest 'Dragonmaw Shinbones' is not taken"),
(19,0,1846,0,0,28,0,1841,0,0,1,0,0,"","Quest 'Dragonmaw Shinbones' can only be taken if quest 'Velora Nitely and the Brutal Legguards' is not completed");

-- BreadCrumb Quest "Orm Stonehoof and the Brutal Helm"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (1840,1844);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1840,0,0,14,0,1844,0,0,0,0,0,"","Quest 'Orm Stonehoof and the Brutal Helm' can only be taken if quest 'Chimaeric Horn' is not taken"),
(19,0,1844,0,0,28,0,1840,0,0,1,0,0,"","Quest 'Chimaeric Horn' can only be taken if quest 'Orm Stonehoof and the Brutal Helm' is not completed");

-- BreadCrumb Quest "Ula'elek and the Brutal Gauntlets"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (1839,1842);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1839,0,0,14,0,1842,0,0,0,0,0,"","Quest 'Ula'elek and the Brutal Gauntlets' can only be taken if quest 'Satyr Hooves' is not taken"),
(19,0,1842,0,0,28,0,1839,0,0,1,0,0,"","Quest 'Satyr Hooves' can only be taken if quest 'Ula'elek and the Brutal Gauntlets' is not completed");
