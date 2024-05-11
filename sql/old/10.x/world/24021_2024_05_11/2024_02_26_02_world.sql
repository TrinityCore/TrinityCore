-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (218,24473,24487,24493);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,24493,0,0,47,0,24492,10,0,'',0,0,0,'','Dont Forget About Us available if quest Pack Your Bags is in progress or completed');
-- Give Em What For and Aid the Wounded Exclusive Group
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-24470 WHERE `ID` IN (24470,24471);
UPDATE `quest_template_addon` SET `NextQuestID`=24473 WHERE `ID` IN (24470,24471);
-- All the Other Stuff and Make Hay While the Sun Shines Exclusive Group
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-24475 WHERE `ID` IN (24475,24486);
UPDATE `quest_template_addon` SET `NextQuestID`=24487 WHERE `ID` IN (24475,24486);
-- Ice and Fire
UPDATE `quest_template_addon` SET `PrevQuestID`=24489 WHERE `ID`=218;
