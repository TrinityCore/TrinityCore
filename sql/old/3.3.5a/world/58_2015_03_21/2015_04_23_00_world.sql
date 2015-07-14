--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND SourceEntry IN (46598,49078);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,34776,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,35069,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,35431,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,35433,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,28312,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,32627,46598,0,0,31,0,3,0,0,0,0,'','Require unit for spellclick'),
(18,25334,46598,0,0,9,0,11652,0,0,0,0,'','Player must have The Plains of Nasam taken but not completed to use Horde Siege tank'),
(18,27587,46598,0,0,31,0,3,0,0,0,0,'','Only npc for spellclick'),
(18,27587,49078,0,0,9,0,12326,0,0,0,0,'','Required quest active for spellclick');
