DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=52781;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,52781,0,0,31,0,3,28610,0,0,27,0,'','Persuasive Strike - Scarlet Marksman'),
(17,0,52781,0,1,31,0,3,28939,0,0,27,0,'','Persuasive Strike - Scarlet Preacher'),
(17,0,52781,0,2,31,0,3,28940,0,0,27,0,'','Persuasive Strike - Scarlet Crusader');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (32096,32098);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(32096,32172,2,'Thrallmar''s Favor'),
(32098,32172,2,'Honor Hold''s Favor');

DELETE FROM `spell_area` WHERE `spell` IN (32096,32098);
INSERT INTO `spell_area` (`spell`,`area`,`autocast`) VALUES
(32096,3483,0),
(32096,3562,0),
(32096,3713,0),
(32096,3714,0),
(32096,3836,0),
(32098,3483,0),
(32098,3562,0),
(32098,3713,0),
(32098,3714,0),
(32098,3836,0);

-- Dark / Light essence removing
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-67222, -67223, -67224, -65686, -67176, -67177, -67178, -65684);
