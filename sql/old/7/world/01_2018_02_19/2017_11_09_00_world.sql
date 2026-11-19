-- Quest Linking
DELETE FROM `quest_template_addon` WHERE `ID` IN (25035,24812,24813,24623,24624,24625,25073);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`) VALUES 
(25035,0,24626),(24812,0,25035),(24813,0,25035),(24623,0,24622),(24624,0,24622),(24625,0,24622),(25073,0,24814);

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (24814);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 24814, 0, 1, 8, 0, 24812, 0, 0, 0, 0, 0, '', 'Quest An Ancient Enemy available if quest No More Mercy has been rewarded.'),
(19, 0, 24814, 0, 1, 8, 0, 24813, 0, 0, 0, 0, 0, '', 'Quest An Ancient Enemy available if quest Territorial Fetish has been rewarded.');

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=25064;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25064, 0, 1, 8, 0, 24755, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 2, 8, 0, 24763, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 3, 8, 0, 24775, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 4, 8, 0, 24781, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 5, 8, 0, 24787, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 6, 8, 0, 24643, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 7, 8, 0, 24769, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 8, 8, 0, 26277, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'),
(19, 0, 25064, 0, 9, 8, 0, 31163, 0, 0, 0, 0, 0, '', 'Quest Moraya available if quest More Than Expected has been rewarded.'); -- Master

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=25037;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25037, 0, 1, 8, 0, 24755, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 2, 8, 0, 24763, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 3, 8, 0, 24775, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 4, 8, 0, 24781, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 5, 8, 0, 24787, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 6, 8, 0, 24643, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 7, 8, 0, 24769, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 8, 8, 0, 26277, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'),
(19, 0, 25037, 0, 9, 8, 0, 31163, 0, 0, 0, 0, 0, '', 'Quest Crap Fishin available if quest More Than Expected has been rewarded.'); -- Master
