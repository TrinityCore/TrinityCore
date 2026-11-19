UPDATE `smart_scripts` SET `source_type`=0,`id`=1 WHERE `entryorguid`=24814 AND `source_type`=1 AND `event_type`=38;
UPDATE `conditions` SET `SourceTypeOrReferenceId`=17 WHERE `SourceEntry` IN (46485,46488);
UPDATE `conditions` SET `ElseGroup`=0 WHERE `SourceEntry` IN (46485,46488) AND `ConditionValue1`=26817;
