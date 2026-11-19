-- 11140
DELETE FROM `spell_script_names` WHERE `spell_id` = 42287 AND `ScriptName` = "spell_q11140salvage_wreckage";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42287,"spell_q11140salvage_wreckage");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 42287;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42287,0,0,31,0,5,186283,0,0,0,0,"","Group 0: Spell 'Salvage Wreckage' (Effect 0) targets object 'Shipwreck Debris'"),
(13,2,42287,0,1,31,0,5,186283,0,0,0,0,"","Group 1: Spell 'Salvage Wreckage' (Effect 1) targets object 'Shipwreck Debris'"),
(13,4,42287,0,2,31,0,5,186278,0,0,0,0,"","Group 2: Spell 'Salvage Wreckage' (Effect 2) targets object 'Burning Wreckage'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 186283 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18628300,18628301) AND `source_type` = 9;
UPDATE `gameobject_template` SET `AIName` = "" WHERE `entry` = 186283;
UPDATE `gameobject` SET `spawntimesecs` = 180 WHERE `id` IN (186283,186278);

-- 12279
DELETE FROM `spell_script_names` WHERE `spell_id` = 48794 AND `ScriptName` = "spell_q12279_cast_net";

-- 9452
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (29866,29869);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,29866,0,0,31,0,5,181616,0,0,0,0,"","Group 0: Spell 'Cast Fishing Net' (Effect 0) targets object 'School of Red Snapper'"),
(13,2,29866,0,1,31,0,5,181616,0,0,0,0,"","Group 1: Spell 'Cast Fishing Net' (Effect 1) targets object 'School of Red Snapper'"),
(13,1,29869,0,0,31,0,5,181616,0,0,0,0,"","Group 0: Spell 'Fished Up Murloc' (Effect 0) targets object 'School of Red Snapper'");
