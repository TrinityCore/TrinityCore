--
UPDATE `quest_template` SET `AllowableRaces`=32 WHERE `ID`=748;

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=364;
UPDATE `quest_template` SET `AllowableRaces`=0 WHERE `ID` IN (364, 3901);

UPDATE `quest_template` SET `AllowableRaces`=0 WHERE `ID` IN (367, 368, 369, 492);
