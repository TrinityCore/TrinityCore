-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=43233;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 43233, 0, 0, 29, 0, 24182, 20, 0, 0, 0, 0, "","Spell Burn Structure requires caster to be within 20 yards of creature Winterskorn Dwelling Credit"),
(17, 0, 43233, 0, 1, 29, 0, 24183, 20, 0, 0, 0, 0, "","Spell Burn Structure requires caster to be within 20 yards of creature Winterskorn Watchtower Credit"),
(17, 0, 43233, 0, 2, 29, 0, 24184, 20, 0, 0, 0, 0, "","Spell Burn Structure requires caster to be within 20 yards of creature Winterskorn Barracks Credit"),
(17, 0, 43233, 0, 3, 29, 0, 24185, 20, 0, 0, 0, 0, "","Spell Burn Structure requires caster to be within 20 yards of creature Winterskorn Bridge Credit");
