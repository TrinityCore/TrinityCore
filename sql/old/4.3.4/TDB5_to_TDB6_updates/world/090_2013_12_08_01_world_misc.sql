-- Fix Quest 11310 Warning: Some Assembly Required

-- Condition for spell Mindless Abomination Control
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42168;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,1,42168,0,0,31,0,3,23575,0,0,0,0, '', 'Mindless Abomination Control targets Mindless Abomination');

UPDATE `creature_template` SET `spell1`=42166, `spell2`=61359, `AIName`= '',ScriptName = 'npc_mindless_abomination' WHERE `entry`=23575;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43392;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(43392,42168,0, 'Mindless Abomination Control cast when Assemble Abomination cast');

DELETE FROM `spell_script_names` WHERE `spell_id`=42268;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42268, 'spell_mindless_abomination_explosion_fx_master');

-- Update SAI for Plagued Dragonflayer Tribesman, Plagued Dragonflayer Rune-Caster, Plagued Dragonflayer Handler from Pitcrawler
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23564,24198,24199) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23564,0,0,1,8,0,100,0,42166,0,0,0,11,43399,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plagued Blood Explosion - Spellcast Plagued Vrykul Force Credit'),
(23564,0,1,0,61,0,100,0,0,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(23564,0,2,0,8,0,100,0,42167,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(23564,0,3,0,4,0,100,0,0,0,0,0,11,43506,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On aggro - Spellcast Plague Blight'),
(23564,0,4,5,8,0,100,0,43381,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plague Spray - Say text'),
(23564,0,5,6,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plague Spray - Set faction'),
(23564,0,6,0,61,0,100,0,0,0,0,0,11,43384,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plague Spray - Spellcast Spray Credit'),
(23564,0,7,0,8,0,100,0,43385,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On spellhit Plagued Vrykul Dummy - Start attack'),
(23564,0,8,0,6,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On death - Set default faction'),
(23564,0,9,0,1,0,35,0,0,30000,25000,45000,11,43327,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On update OOC - Spellcast Vomit'),
(23564,0,10,0,0,0,100,0,2000,4000,5000,8000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On update IC - Spellcast Mortal Strike'),
(23564,0,11,0,0,0,100,0,1000,1000,4000,5000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Dragonflayer Tribesman - On update IC - Spellcast Cleave'),
(24198,0,0,1,8,0,100,0,42166,0,0,0,11,43399,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plagued Blood Explosion - Spellcast Plagued Vrykul Force Credit'),
(24198,0,1,0,61,0,100,0,0,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(24198,0,2,0,8,0,100,0,42167,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(24198,0,3,4,8,0,100,0,43381,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plague Spray - Say text'),
(24198,0,4,5,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plague Spray - Set faction'),
(24198,0,5,0,61,0,100,0,0,0,0,0,11,43384,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plague Spray - Spellcast Spray Credit'),
(24198,0,6,0,8,0,100,0,43385,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On spellhit Plagued Vrykul Dummy - Start attack'),
(24198,0,7,0,6,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On death - Set default faction'),
(24198,0,8,0,1,0,35,0,0,30000,25000,45000,11,43327,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On update OOC - Spellcast Vomit'),
(24198,0,9,0,0,0,100,0,0,0,18000,20000,11,47782,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On update IC - Spellcast Corruption'),
(24198,0,10,0,0,0,100,0,10000,12000,15000,17000,11,15616,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Dragonflayer Rune-Caster - On update IC - Spellcast Flame Shock'),
(24199,0,0,1,8,0,100,0,42166,0,0,0,11,43399,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plagued Blood Explosion - Spellcast Plagued Vrykul Force Credit'),
(24199,0,1,0,61,0,100,0,0,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(24199,0,2,0,8,0,100,0,42167,0,0,0,11,42167,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plagued Blood Explosion - Spellcast Plagued Blood Explosion'),
(24199,0,3,0,4,0,100,0,0,0,0,0,11,43506,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On aggro - Spellcast Plague Blight'),
(24199,0,4,5,8,0,100,0,43381,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plague Spray - Say text'),
(24199,0,5,6,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plague Spray - Set faction'),
(24199,0,6,0,61,0,100,0,0,0,0,0,11,43384,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plague Spray - Spellcast Spray Credit'),
(24199,0,7,0,8,0,100,0,43385,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On spellhit Plagued Vrykul Dummy - Start attack'),
(24199,0,8,0,6,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On death - Set default faction'),
(24199,0,9,0,1,0,35,0,0,30000,25000,45000,11,43327,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Dragonflayer Handler - On update OOC - Spellcast Vomit');
