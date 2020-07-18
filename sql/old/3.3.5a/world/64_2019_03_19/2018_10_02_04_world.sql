-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=25356 AND `source_type`=0 AND `id`=0 AND `action_type`=85;
UPDATE `smart_scripts` SET `id`=0, `event_type`=19 WHERE `entryorguid`=25356 AND `source_type`=0 AND `id`=1 AND `action_type`=80;
UPDATE `quest_template_addon` SET `SourceSpellID`=45883 WHERE `ID`=11681; 
