UPDATE `smart_scripts` SET `event_flags`=`event_flags`|0x200 WHERE  `entryorguid`IN(2464000) AND `source_type`=9;
UPDATE `conditions` SET `ElseGroup`=1, `ConditionValue1`=9720, `NegativeCondition`=0 WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=24330 AND `ConditionValue1`=9731;
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE  `ID` IN(7170,7171,7172);
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=3771 AND `source_type`=0 AND `id` IN(1,3);
UPDATE `smart_scripts` SET `link`=2 WHERE  `entryorguid`=3771 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE  `entryorguid`=3771 AND `source_type`=0 AND `id`=0 AND `link`=0;
