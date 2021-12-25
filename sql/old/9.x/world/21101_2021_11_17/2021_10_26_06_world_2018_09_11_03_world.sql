-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36325;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36325,0,31,3,21182,0,0,'','Spell 36325 target creature 21182'),
(13,1,36325,1,31,3,22401,0,0,'','Spell 36325 target creature 22401'),
(13,1,36325,2,31,3,22402,0,0,'','Spell 36325 target creature 22402'),
(13,1,36325,3,31,3,22403,0,0,'','Spell 36325 target creature 22403');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN ( 21182, 22401, 22402, 22403) AND `source_type`=0 AND `id`=2 AND action_type=11;
UPDATE `smart_scripts` SET `id`=2 WHERE `entryorguid` IN ( 21182, 22401, 22402, 22403) AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=34386 WHERE `entryorguid` IN (20813,20814,20815,20816) AND `source_type`=0 AND `id`=2;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21170, 22404, 22405, 22406) AND `source_type`=0 AND `id` IN (9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21170,0,9,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Gryphon Brigadier, Foothill - On Respawn - Set active"),
(22404,0,9,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Gryphon Brigadier, Foothill - On Respawn - Set active"),
(22405,0,9,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Gryphon Brigadier, Foothill - On Respawn - Set active"),
(22406,0,9,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Gryphon Brigadier, Foothill - On Respawn - Set active");
