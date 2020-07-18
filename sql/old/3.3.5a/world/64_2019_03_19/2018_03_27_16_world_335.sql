UPDATE `item_template` SET `maxcount`=1 WHERE `entry`=6926;
UPDATE `quest_template` SET `AllowableRaces`=8 WHERE `ID`=1703;
UPDATE `quest_template` SET `AllowableRaces`=64 WHERE `ID`=1704;
UPDATE `quest_template` SET `AllowableRaces`=1|4 WHERE `ID`=1700;
UPDATE `quest_template_addon` SET `PrevQuestID`=1782 WHERE `ID` IN (1710, 1705, 1708,1703,1704,1700);
