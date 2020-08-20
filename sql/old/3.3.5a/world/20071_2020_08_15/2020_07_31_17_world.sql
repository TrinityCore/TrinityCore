--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (40964,40965,40968,40970,41004);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,2,40964,0,0,31,0,5,185919,0,0,0,0,"","Group 0: Spell 'Fel Crystalforge: Create 1 Flask' (Effect 1) targets object 'Fel Crystalforge'"),
(13,2,40964,0,1,31,0,5,185920,0,0,0,0,"","Group 1: Spell 'Fel Crystalforge: Create 1 Flask' (Effect 1) targets object 'Fel Crystalforge'"),
(13,2,40964,0,2,31,0,5,185923,0,0,0,0,"","Group 2: Spell 'Fel Crystalforge: Create 1 Flask' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,40964,0,3,31,0,5,185924,0,0,0,0,"","Group 3: Spell 'Fel Crystalforge: Create 1 Flask' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,40965,0,0,31,0,5,185919,0,0,0,0,"","Group 0: Spell 'Fel Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Fel Crystalforge'"),
(13,2,40965,0,1,31,0,5,185920,0,0,0,0,"","Group 1: Spell 'Fel Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Fel Crystalforge'"),
(13,2,40965,0,2,31,0,5,185923,0,0,0,0,"","Group 2: Spell 'Fel Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,40965,0,3,31,0,5,185924,0,0,0,0,"","Group 3: Spell 'Fel Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,40968,0,0,31,0,5,185921,0,0,0,0,"","Group 0: Spell 'Bash'ir Crystalforge: Create 1 Flask' (Effect 1) targets object 'Bash'ir Crystalforge'"),
(13,2,40968,0,1,31,0,5,185922,0,0,0,0,"","Group 1: Spell 'Bash'ir Crystalforge: Create 1 Flask' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,40970,0,0,31,0,5,185921,0,0,0,0,"","Group 0: Spell 'Bash'ir Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Bash'ir Crystalforge'"),
(13,2,40970,0,1,31,0,5,185922,0,0,0,0,"","Group 1: Spell 'Bash'ir Crystalforge: Create 5 Flasks' (Effect 1) targets object 'Crystalforge controller'"),
(13,2,41004,0,0,31,0,5,185928,0,0,0,0,"","Group 0: Spell 'Summon Terokk' (Effect 1) targets object 'Ancient Skull Pile'");
