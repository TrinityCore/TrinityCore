DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (48619,48620,52812);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=48738;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,48619,0,0,31,0,3,27377,0,0,'','Spell Flame Breath effect0 targets Thane Torvald Eriksson'),
(13,2,48619,0,0,31,0,3,27377,0,0,'','Spell Flame Breath effect1 targets Thane Torvald Eriksson'),
(13,1,48620,0,0,31,0,3,27377,0,0,'','Spell Wing Buffet targets Thane Torvald Eriksson'),
(13,1,52812,0,0,31,0,3,27377,0,0,'','Spell Molten Fury effect0 targets Thane Torvald Eriksson'),
(13,2,52812,0,0,31,0,3,27377,0,0,'','Spell Molten Fury effect1 targets Thane Torvald Eriksson');

UPDATE `smart_scripts` SET `event_type`=1, `event_flags`=1 WHERE `entryorguid`=21633 AND `source_type`=0 AND `id`=0;
