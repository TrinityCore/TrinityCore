-- update phasing for the Vindicaar
UPDATE `creature` SET `PhaseId` = 0 WHERE `guid` IN (650104, 650079, 650083, 650100, 650095, 650123, 650094, 650089, 650072, 650114, 650113, 650115, 650096, 650127, 650121, 650087, 650085, 650086, 650128, 650099, 650125, 650108, 650126, 650122, 650091, 650084, 650109, 650076, 650090, 650093, 650105, 650080, 650092, 650106, 650078, 650116, 650071, 650098, 650111, 650112, 650117, 650118, 650119, 650107, 650110, 650129, 650081, 650102, 650124, 650120, 650088, 650085, 650103, 650073);
UPDATE `gameobject` SET `PhaseId` = 0 WHERE `guid` IN (400081, 400064, 400083, 400077, 400075, 400082, 400069, 400072, 400066, 400065, 400063, 400074, 400061, 400062, 400070, 400076, 400071);

-- new phase for Grand Artificer Romuul
UPDATE `creature` SET `PhaseId` = 21673 WHERE `guid` = 650075;

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (21673, 10260, 10349, 9949);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(21673, 'Cosmetic - See Grand Artificer Romuul'),
(10260, 'Cosmetic - See Lightforged Innkeeper and Vigilant Quoram'),
(10349, 'Cosmetic - See Captain Fareeya before enter Stormwind'),
(9949, 'Cosmetic - See Captain Fareeya after enter Stormwind');

DELETE FROM `phase_area` WHERE `AreaId` = 9359 AND `PhaseId` = 21673;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9359, 21673, 'Cosmetic - See Grand Artificer Romuul');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 10260 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 10349 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10260, 0, 0, 0, 16, 0, 0x20000000, 0, 0, 0, 'Apply Phase 10260 if Player is Lightforged Draenei'),
(26, 10349, 0, 0, 0, 16, 0, 0x20000000, 0, 0, 0, 'Apply Phase 10349 if Player is Lightforged Draenei'),
(26, 10349, 0, 0, 0, 8, 0, 49772, 0, 0, 1, 'Apply Phase 10349 if Quest 49772 is not in progress');
