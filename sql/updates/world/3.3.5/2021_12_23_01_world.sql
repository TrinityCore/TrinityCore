--
UPDATE `quest_template_addon` SET `SpecialFlags` = 0 WHERE `ID` = 6983;
UPDATE `quest_template` SET `AllowableRaces`=690 WHERE `ID` IN (6983,6984);
