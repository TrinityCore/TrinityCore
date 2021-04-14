-- 
DELETE FROM `conditions` WHERE `SourceEntry`=23359 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`, `ErrorType`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17, 0, 23359, 0, 0, 31, 1, 3, 5357, 0, 0, 0, 0, "", "Transmogrify! target can be Land Walker"),
(17, 0, 23359, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, "", "Transmogrify! target must be alive"),
(17, 0, 23359, 0, 1, 31, 1, 3, 5358, 0, 0, 0, 0, "", "Transmogrify! target can be Cliff Giant"),
(17, 0, 23359, 0, 1, 36, 1, 0, 0, 0, 0, 0, 0, "", "Transmogrify! target must be alive"),
(17, 0, 23359, 0, 2, 31, 1, 3, 5359, 0, 0, 0, 0, "", "Transmogrify! target can be Shore Strider"),
(17, 0, 23359, 0, 2, 36, 1, 0, 0, 0, 0, 0, 0, "", "Transmogrify! target must be alive"),
(17, 0, 23359, 0, 3, 31, 1, 3, 5360, 0, 0, 0, 0, "", "Transmogrify! target can be Deep Strider"),
(17, 0, 23359, 0, 3, 36, 1, 0, 0, 0, 0, 0, 0, "", "Transmogrify! target must be alive"),
(17, 0, 23359, 0, 4, 31, 1, 3, 5361, 0, 0, 0, 0, "", "Transmogrify! target can be Wave Strider"),
(17, 0, 23359, 0, 4, 36, 1, 0, 0, 0, 0, 0, 0, "", "Transmogrify! target must be alive");
