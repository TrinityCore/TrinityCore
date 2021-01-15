--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19) AND `SourceEntry` IN (13177, 13179, 13178, 13180);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13177, 0, 0, 32, 0, 144, 0, 0, 0, 0, 0, "condition_is_wintergrasp_alliance", "Alliance quest 'No Mercy for the Merciless' is available if Wintergrasp is held by Alliance"),
(19, 0, 13179, 0, 0, 32, 0, 144, 0, 0, 0, 0, 0, "condition_is_wintergrasp_horde", "Alliance quest 'No Mercy for the Merciless' is available if Wintergrasp is held by Horde"),
(19, 0, 13178, 0, 0, 32, 0, 144, 0, 0, 0, 0, 0, "condition_is_wintergrasp_horde", "Horde quest 'Slay Them All!' is available if Wintergrasp is held by Horde"),
(19, 0, 13180, 0, 0, 32, 0, 144, 0, 0, 0, 0, 0, "condition_is_wintergrasp_alliance", "Horde quest 'Slay Them All!' is available if Wintergrasp is held by Alliance");
