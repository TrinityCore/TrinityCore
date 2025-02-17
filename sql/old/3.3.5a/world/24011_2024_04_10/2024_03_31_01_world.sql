-- These quests should not be available until either "The Forsaken" (9327) or "The Forsaken" (9329) is rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 19 AND `SourceEntry` IN (9145,9149,9150,9152,9155,9160,9171,9192);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,9145,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Help Ranger Valanna!' (9145) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9145,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Help Ranger Valanna!' (9145) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9149,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'The Plagued Coast' (9149) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9149,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'The Plagued Coast' (9149) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9150,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Salvaging the Past' (9150) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9150,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Salvaging the Past' (9150) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9152,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Tomber's Supplies' (9152) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9152,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Tomber's Supplies' (9152) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9155,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Down the Dead Scar' (9155) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9155,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Down the Dead Scar' (9155) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9160,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Investigate An'daroth' (9160) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9160,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Investigate An'daroth' (9160) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9171,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Culinary Crunch' (9171) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9171,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Culinary Crunch' (9171) if quest 'The Forsaken (9329)' is not rewarded"),
(19,0,9192,0,0,8,0,9327,0,0,0,0,0,'',"Don't show quest 'Trouble at the Underlight Mines' (9192) if quest 'The Forsaken (9327)' is not rewarded or"),
(19,0,9192,0,1,8,0,9329,0,0,0,0,0,'',"Don't show quest 'Trouble at the Underlight Mines' (9192) if quest 'The Forsaken (9329)' is not rewarded");
