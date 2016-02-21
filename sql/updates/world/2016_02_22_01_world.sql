-- 
DELETE FROM achievement_criteria_data WHERE `type`=6;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hun_glyph_of_arcane_shot';
UPDATE `smart_scripts` SET `action_param1`=170, `comment`='On Script - Set Phase 170' WHERE `entryorguid`=18707300 AND `source_type`=9 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `comment`='On Script - Set Phase 170' WHERE `entryorguid`=19055500 AND `source_type`=9 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`=169, `comment`='On Script - Set Phase 169' WHERE `entryorguid`=18707300 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`=169, `comment`='On Script - Set Phase 169' WHERE `entryorguid`=19055500 AND `source_type`=9 AND `id`=1 AND `link`=0;
