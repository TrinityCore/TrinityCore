--
DELETE FROM `conditions` WHERE `SourceEntry`=1127 AND `SourceTypeOrReferenceId` IN (19, 20);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19, 0, 1127, 0, 0, 9, 0, 1119, 0, 0, 0, 0, 0, "", "Quest 'Fool's Stout' - Can accept if player has quest 'Zanzil's Mixture and a Fool's Stout'"),
(20, 0, 1127, 0, 0, 9, 0, 1119, 0, 0, 0, 0, 0, "", "Quest 'Fool's Stout' - Can accept if player has quest 'Zanzil's Mixture and a Fool's Stout'");

DELETE FROM `quest_template_addon` WHERE `ID`=1127;
INSERT INTO `quest_template_addon` (`ID`, `SpecialFlags`) VALUES
(1127, 1);
