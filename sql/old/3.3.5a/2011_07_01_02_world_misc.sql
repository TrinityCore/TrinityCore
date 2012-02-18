DELETE FROM `spell_script_names` WHERE `spell_id` IN (63317,64021);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)
VALUES
(63317,'spell_razorscale_flame_breath'),
(64021,'spell_razorscale_flame_breath');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10066,10067);

DELETE FROM `conditions` WHERE `SourceEntry`=63317;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`comment`)
VALUES
(13,0,63317,0,18,1,33388,0,0,'','Flame Breath - Dark Rune Guardian');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10066,10067) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10066,11,0,0,'achievement_iron_dwarf_medium_rare'),
(10067,11,0,0,'achievement_iron_dwarf_medium_rare');
