--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 32301;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,32301,0,0,31,0,3,18371,0,0,0,0,"","Group 0: Spell 'Ping Shirrak' (Effect 0) targets creature 'Shirrak the Dead Watcher'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_shirrak_ping_shirrak', 'spell_shirrak_inhibit_magic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32301, 'spell_shirrak_ping_shirrak'),
(32264, 'spell_shirrak_inhibit_magic');

UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 128 WHERE `entry` IN (18374,20308);
