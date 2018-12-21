DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_mage_mirror_image',
'spell_mage_initialize_images');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55342, 'spell_mage_mirror_image'),
(58836, 'spell_mage_initialize_images');

UPDATE `creature_template` SET `unit_class`= 8, `ScriptName`= 'npc_pet_mage_mirror_image' WHERE `entry` IN (47244, 47243, 31216);

DELETE FROM `conditions` WHERE `SourceEntry`= 58836 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 58836, 0, 0, 31, 0, 3, 47244, 0, 0, 0, '', 'Initialize Images - Target Mirror Image'),
(13, 1, 58836, 0, 1, 31, 0, 3, 47243, 0, 0, 0, '', 'Initialize Images - Target Mirror Image'),
(13, 1, 58836, 0, 2, 31, 0, 3, 31216, 0, 0, 0, '', 'Initialize Images - Target Mirror Image');
