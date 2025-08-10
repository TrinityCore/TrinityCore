-- Unnecessary Rows
DELETE FROM `quest_template_addon` WHERE `ID`=29078;
-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26391;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,26391,0,0,47,0,28817,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 4 is rewarded'),
(19,0,26391,0,1,47,0,28818,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 128 is rewarded'),
(19,0,26391,0,2,47,0,28819,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 2 is rewarded'),
(19,0,26391,0,3,47,0,28820,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 16 is rewarded'),
(19,0,26391,0,4,47,0,28821,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 8 is rewarded'),
(19,0,26391,0,5,47,0,28822,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 256 is rewarded'),
(19,0,26391,0,6,47,0,28823,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 1 is rewarded'),
(19,0,26391,0,7,47,0,29083,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 0 is rewarded'),
(19,0,26391,0,8,47,0,31145,64,0,'',0,0,0,'','Extinguishing Hope available if quest The Rear is Clear ClassMask 1632 is rewarded');
-- Unnecessary NextQuestIDs
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (28757,28759,28762,28763,28764,28765,28766,28767,28769,28770,28771,28772,28773,28774,29079,28780,28784,28785,28786,28787,28788,28789,29080,28791,28792,28793,28794,28795,28796,28797,29081,31139,31140,31141,31143);
-- Other Classes Quest Chain
UPDATE `quest_template_addon` SET `AllowableClasses`=1632 WHERE `ID` IN (31139,31140,31143,63447,31144,31145);
-- Other Races Quest Chain
UPDATE `quest_template_addon` SET `AllowableClasses`=0 WHERE `ID` IN (29079,29080,29081,29082,29083);
-- Fear No Evil (Warrior)
UPDATE `quest_template_addon` SET `AllowableClasses`=1 WHERE `ID`=28813;
-- Fear No Evil (Other Classes)
UPDATE `quest_template_addon` SET `PrevQuestID`=31143 WHERE `ID`=63447;
