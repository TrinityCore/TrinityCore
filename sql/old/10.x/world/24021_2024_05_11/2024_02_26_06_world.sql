-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (24814,25037,25064);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,25037,0,0,47,0,24643,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 1 is rewarded'),
(19,0,25037,0,1,47,0,24755,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 128 is rewarded'),
(19,0,25037,0,2,47,0,24763,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 64 is rewarded'),
(19,0,25037,0,3,47,0,24769,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 1024 is rewarded'),
(19,0,25037,0,4,47,0,24775,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 8 is rewarded'),
(19,0,25037,0,5,47,0,24781,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 4 is rewarded'),
(19,0,25037,0,6,47,0,24787,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 16 is rewarded'),
(19,0,25037,0,7,47,0,26277,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 256 is rewarded'),
(19,0,25037,0,8,47,0,31163,64,0,'',0,0,0,'','Crab Fishin available if quest More Than Expected ClassMask 512 is rewarded');
-- More Than Expected
UPDATE `quest_template_addon` SET `NextQuestID`=25064 WHERE `ID` IN (24643,24755,24763,24769,24775,24781,24787,26277,31163);
-- Saving The Young, Mercy For the Lost, Consort of the Sea Witch Exclusive Group
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-24623 WHERE `ID` IN (24623,24624,24625);
UPDATE `quest_template_addon` SET `NextQuestID`=24626 WHERE `ID` IN (24623,24624,24625);
-- Young and Vicious
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=24626;
-- Territorial Fetish and No More Mercy Exclusive Group
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-24812 WHERE `ID` IN (24812,24813);
UPDATE `quest_template_addon` SET `NextQuestID`=24814 WHERE `ID` IN (24812,24813);
-- Sen'jin Village (To Durotar)
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=25167 WHERE `ID`=25073;
