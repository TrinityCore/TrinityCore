--
UPDATE `smart_scripts` SET `event_type`=61, `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0, `action_param1`=10000 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51276;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,51276,0,0,31,0,3,28156,0,0,0,0,'','Incinerate Corpse can be used only on Defeated Argent Footman.');
