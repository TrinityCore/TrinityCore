-- DB/Spell: Spell 58152, Arcane Lightning should also target NPCs 29321, Ichor Globule
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=58152 AND `ElseGroup`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,58152,0,18,31,0,3,29321,0,0,0,0,'','Defense System - Arcane Lightning');
