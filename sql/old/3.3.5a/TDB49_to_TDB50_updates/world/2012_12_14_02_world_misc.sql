DELETE FROM `spell_script_names` WHERE `spell_id` IN (24750, 24751, 44436);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(24750, 'spell_trick'),
(24751, 'spell_trick_or_treat'),
(44436, 'spell_tricky_treat');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (42965,42966);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(42965,42919,0, 'Hallows End - Tricky Treat'),
(42966,-42965,0, 'Hallows End - Upset Tummy removes Tricky Treat'),
(42966,-42919,0, 'Hallows End - Upset Tummy removes Tricky Treat');

DELETE FROM `conditions` WHERE `SourceEntry`=44436 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17, 0, 44436, 0, 0, 1, 0, 42966, 0, 0, 1, 0, '','Tricky Treat casted only if Upset Tummy aura is missing');
