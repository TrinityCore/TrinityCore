DELETE FROM `conditions` WHERE `SourceEntry` IN (63317,62505,63524,63657,63658,63659);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(13,0,63317,0,18,1,33453,0,0,'','Flame Breath - Dark Rune Watcher'),
(13,0,63317,0,18,1,33846,0,0,'','Flame Breath - Dark Rune Sentinel'),
(13,0,63317,0,18,1,33388,0,0,'','Flame Breath - Dark Rune Guardian'),
(13,0,62505,0,18,1,33186,0,0,'','Harpoon Trigger - Razorscale'),
(13,0,63524,0,18,1,33233,0,0,'','Harpoon Shot - Razorscale'),
(13,0,63657,0,18,1,33233,0,0,'','Harpoon Shot - Razorscale'),
(13,0,63658,0,18,1,33233,0,0,'','Harpoon Shot - Razorscale'),
(13,0,63659,0,18,1,33233,0,0,'','Harpoon Shot - Razorscale');
