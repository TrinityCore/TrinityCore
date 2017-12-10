-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (62727, 63438, 63439, 63440, 63441, 63442, 63443, 63444, 63445, 63446) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 62727, 0, 0, 31, 0, 3, 33238, 0, 0, 0, 0, '', 'Spell Stormwind Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Squire.'),
(13, 1, 63438, 0, 0, 31, 0, 3, 33239, 0, 0, 0, 0, '', 'Spell Silvermoon Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Gruntling.'),
(13, 1, 63439, 0, 0, 31, 0, 3, 33238, 0, 0, 0, 0, '', 'Spell Exodar Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Squire.'),
(13, 1, 63440, 0, 0, 31, 0, 3, 33238, 0, 0, 0, 0, '', 'Spell Ironforge Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Squire.'),
(13, 1, 63441, 0, 0, 31, 0, 3, 33239, 0, 0, 0, 0, '', 'Spell Undercity Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Gruntling.'),
(13, 1, 63442, 0, 0, 31, 0, 3, 33238, 0, 0, 0, 0, '', 'Spell Gnomeregan Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Squire.'),
(13, 1, 63443, 0, 0, 31, 0, 3, 33238, 0, 0, 0, 0, '', 'Spell Darnassus Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Squire.'),
(13, 1, 63444, 0, 0, 31, 0, 3, 33239, 0, 0, 0, 0, '', 'Spell Orgrimmar Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Gruntling.'),
(13, 1, 63445, 0, 0, 31, 0, 3, 33239, 0, 0, 0, 0, '', 'Spell Thunder Bluff Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Gruntling.'),
(13, 1, 63446, 0, 0, 31, 0, 3, 33239, 0, 0, 0, 0, '', 'Spell Sen''jin Champion''s Pennant (effect 0) will hit the potential target of the spell if target is unit Argent Gruntling.');
