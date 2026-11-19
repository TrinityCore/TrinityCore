-- Makes a number of Craftsman's Writ quests repeatable
UPDATE `quest_template_addon` SET `SpecialFlags`=`SpecialFlags`| 1 WHERE `ID` IN (9181, 9190, 9195, 9205, 9206);
