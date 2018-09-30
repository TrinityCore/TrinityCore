UPDATE `spell_script_names` SET `ScriptName`='spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576' WHERE `spell_id` = 59576;
UPDATE `spell_script_names` SET `ScriptName`='spell_q12690_burst_at_the_seams_52510' WHERE `spell_id` = 52510;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (31142,31147,31205,31692);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31142,31147,31205,31692) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31142,0,0,1, 8,0,100,0, 59579,0,0,0, 11,59590,2,0,0,0,0, 7,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Assign Ghoul Kill Credit to Master"'),
(31142,0,1,2,61,0,100,0,     0,0,0,0, 11,52565,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Troll Explosion"'),
(31142,0,2,3,61,0,100,0,     0,0,0,0, 11,52520,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Explode Abomination Meat"'),
(31142,0,3,4,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31142,0,4,5,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31142,0,5,6,61,0,100,0,     0,0,0,0, 11,52516,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams: Bone"'),
(31142,0,6,7,61,0,100,0,     0,0,0,0, 11,52580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Explode Bloody Troll Meat"'),
(31142,0,7,0,61,0,100,0,     0,0,0,0, 11,59580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Icy Ghoul - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams"'),

(31147,0,0,1, 8,0,100,0, 59579,0,0,0, 11,60041,2,0,0,0,0, 7,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Assign Geist Kill Credit to Master"'),
(31147,0,1,2,61,0,100,0,     0,0,0,0, 11,52565,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Troll Explosion"'),
(31147,0,2,3,61,0,100,0,     0,0,0,0, 11,52520,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Explode Abomination Meat"'),
(31147,0,3,4,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31147,0,4,5,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31147,0,5,6,61,0,100,0,     0,0,0,0, 11,52516,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams: Bone"'),
(31147,0,6,7,61,0,100,0,     0,0,0,0, 11,52580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Explode Bloody Troll Meat"'),
(31147,0,7,0,61,0,100,0,     0,0,0,0, 11,59580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Vicious Geist - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams"'),

(31205,0,0,1, 8,0,100,0, 59579,0,0,0, 11,60039,2,0,0,0,0, 7,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Assign Skeleton Kill Credit to Master"'),
(31205,0,1,2,61,0,100,0,     0,0,0,0, 11,52565,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Troll Explosion"'),
(31205,0,2,3,61,0,100,0,     0,0,0,0, 11,52520,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Explode Abomination Meat"'),
(31205,0,3,4,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31205,0,4,5,61,0,100,0,     0,0,0,0, 11,52578,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Explode Troll Meat"'),
(31205,0,5,6,61,0,100,0,     0,0,0,0, 11,52516,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams: Bone"'),
(31205,0,6,7,61,0,100,0,     0,0,0,0, 11,52580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Explode Bloody Troll Meat"'),
(31205,0,7,0,61,0,100,0,     0,0,0,0, 11,59580,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Risen Alliance Soldier - On Spellhit "Burst at the Seams" - Cast "Burst at the Seams"'),

(31692,0,0,0,54,0,100,0,     0,0,0,0, 11,76244,  2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Reanimated Abomination - On Summoned - Cast "Reanimated Abomination Script"'),
(31692,0,1,0, 8,0,100,0, 59590,0,0,0, 85,59591,  2,0,0,0,0,23,0,0,0,0,0,0,0, 'Reanimated Abomination - On Spellhit "Assign Ghoul Kill Credit to Master" - Owner casts "Kill Credit" on self'),
(31692,0,2,0, 8,0,100,0, 60041,0,0,0, 85,60042,  2,0,0,0,0,23,0,0,0,0,0,0,0, 'Reanimated Abomination - On Spellhit "Assign Geist Kill Credit to Master" - Owner casts "Kill Credit" on self'),
(31692,0,3,0, 8,0,100,0, 60039,0,0,0, 85,60040,  2,0,0,0,0,23,0,0,0,0,0,0,0, 'Reanimated Abomination - On Spellhit "Assign Skeleton Kill Credit to Master" - Owner casts "Kill Credit" on self');

DELETE FROM `conditions` WHERE `SourceEntry` IN (59576) AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 59576, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Icy Ghoul'),
(13, 2, 59576, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Vicious Geist'),
(13, 2, 59576, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Risen Alliance Soldier'),
(13, 2, 59576, 0, 3, 31, 0, 4,     0, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Players');
