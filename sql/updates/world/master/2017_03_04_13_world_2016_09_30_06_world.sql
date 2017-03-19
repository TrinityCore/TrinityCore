--
UPDATE `smart_scripts` SET `action_type`=44, `action_param1`=2, `comment`="High Chief Bristlelimb - On Reset - Set Phasemask 2" WHERE `entryorguid`=17702 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=44, `action_param1`=1, `comment`="High Chief Bristlelimb - On Data Set - Set Phasemask 1" WHERE `entryorguid`=17702 AND `id`=2;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=17702;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 17702, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, "", "High Chief Bristlelimb must be alive in order to execute SAI ID 2 AND"),
(22, 3, 17702, 0, 0, 26, 1, 2, 0, 0, 0, 0, 0, "", "High Chief Bristlelimb must be in phasemask 2 in order to execute SAI ID 2");

UPDATE `gameobject` SET `orientation`=1.553341, `rotation2`=0.7009087, `rotation3`=0.7132511, `VerifiedBuild`=15595 WHERE `id`=181928;
