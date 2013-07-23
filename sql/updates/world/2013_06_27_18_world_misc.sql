UPDATE `gameobject_template` SET `flags`=48, `ScriptName`='go_activation_crystal' WHERE `entry`=193611;

UPDATE `creature_template`
SET `flags_extra'=130,'ScriptName'='npc_violet_hold_arcane_sphere'
WHERE 'entry'=30837;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (13, 1, 57930, 0, 0, 32, 0, 16, 0, 0, 1, 0, 0, '', NULL);
