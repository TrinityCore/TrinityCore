--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (42166, 45072);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 42166, 0, 0, 31, 0, 3, 24198, 0, 0, 0, 0, "", "Spell 'Plagued Blood Explosion' EFFECT_0 can only hit 'Plagued Dragonflayer Runecaster' OR"),
(13, 1, 42166, 0, 1, 31, 0, 3, 24199, 0, 0, 0, 0, "", "Spell 'Plagued Blood Explosion' EFFECT_0 can only hit 'Plagued Dragonflayer Handler' OR"),
(13, 1, 42166, 0, 2, 31, 0, 3, 23564, 0, 0, 0, 0, "", "Spell 'Plagued Blood Explosion' EFFECT_0 can only hit 'Plagued Dragonflayer Tribesman'"),
(13, 1, 45072, 0, 0, 31, 0, 3, 25031, 0, 0, 0, 0, "", "Spell 'Arcane Charges' EFFECT_0 can only hit 'Pit Overlord' OR"),
(13, 1, 45072, 0, 1, 31, 0, 3, 25033, 0, 0, 0, 0, "", "Spell 'Arcane Charges' EFFECT_0 can only hit 'Eredar Sorcerer' OR"),
(13, 1, 45072, 0, 2, 31, 0, 3, 25158, 0, 0, 0, 0, "", "Spell 'Arcane Charges' EFFECT_0 can only hit 'Brutallus' OR"),
(13, 1, 45072, 0, 3, 31, 0, 3, 25030, 0, 0, 0, 0, "", "Spell 'Arcane Charges' EFFECT_0 can only hit 'Wrath Enforcer'");
