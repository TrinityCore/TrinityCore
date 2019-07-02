-- 
DELETE FROM `spell_scripts` WHERE `id` IN (45691,45685);
INSERT INTO `spell_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(45691,0,8,25505,0,0,0,0,0,0),
(45685,0,8,25505,0,0,0,0,0,0);

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`="" WHERE `entry` IN (25434);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25434) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25434,0,0,0,0,0,100,0,1000,1000,8000,9000,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Magmoth Crusher - IC - Cast Magnataur Charge'),
(25434,0,1,0,0,0,100,0,3000,6000,7000,12000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Magmoth Crusher - IC - Cast Tusk Strike'),
(25434,0,2,0,6,0,100,1,0,0,0,0,85,45685,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Magmoth Crusher - On Just Died - Cast Hah... : Magnataur On Death 2');
UPDATE `smart_scripts` SET `target_type`=7, `action_type`=85, `action_param2`=2 WHERE `entryorguid` IN (25432) AND `source_type`=0 AND `id`=2;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (25434,25432);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 25434, 0, 0, 1, 1, 45673, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25434, 0, 1, 1, 1, 45672, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25434, 0, 2, 1, 1, 45677, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25434, 0, 3, 1, 1, 45681, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25434, 0, 4, 1, 1, 45683, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25432, 0, 0, 1, 1, 45673, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25432, 0, 1, 1, 1, 45672, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25432, 0, 2, 1, 1, 45677, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25432, 0, 3, 1, 1, 45681, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"'),
(22, 3, 25432, 0, 4, 1, 1, 45683, 0, 0, 0, 0, 0, '', 'SAI triggers only if it has aura"');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (51912);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,51912,0,0,31,1,3,25434,0,0,'','Spell Crafty''s Ultra-Advanced Proto-Typical Shortening Blaster'),
(17,0,51912,0,1,31,1,3,25432,0,0,'','Spell Crafty''s Ultra-Advanced Proto-Typical Shortening Blaster');

DELETE FROM `spell_custom_attr` WHERE `entry`=51912;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(51912, 4096);
