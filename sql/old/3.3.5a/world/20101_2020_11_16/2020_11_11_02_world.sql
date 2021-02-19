--
UPDATE `item_template` SET `ScriptName` = "" WHERE `entry` = 30175;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 32578 AND `ConditionTypeOrReference` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,32578,0,0,1,1,32578,0,0,1,173,0,"","Group 0: Spell 'Gor'drek's Ointment' can be used if target does not have aura 'Gor'drek's Ointment'");
