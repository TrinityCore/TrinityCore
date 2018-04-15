DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=40094;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,40094,0,0,31,0,3,22953,0,0,'','Spell summom channel targets Wrathbone Flayer');
UPDATE `creature_template` SET `AIName`= '', `ScriptName` = 'npc_wrathbone_flayer' WHERE `entry`=22953;
DELETE FROM smart_scripts WHERE entryorguid=22953;
