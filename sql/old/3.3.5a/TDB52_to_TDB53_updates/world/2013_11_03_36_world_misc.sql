-- [11258] [11247] Burn Skorn ,Burn

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(24098,24100,24102);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24098,24100,24102);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24102, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43065 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Barraks Bunny - On Spellhit  - Cast Burn Skorn, Burn!: Barracks Kill Credit'),
(24098, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43058 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Longhouse NW Bunny - On Spellhit - Cast Burn Skorn, Burn!: NW Kill Credit'),
(24100, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43061 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Longhouse NE Bunny - On Spellhit - Cast Burn Skorn, Burn!: NE Kill Credit');

-- [11259] [11245] Towers of Certain Doom

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(24087,24092,24093,24094);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24087,24092,24093,24094) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2408700 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24087, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43067 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - On Spellhit - Cast Towers of Certain Doom: NW Kill Credit'),
(24092, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43077 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - On Spellhit - Cast Towers of Certain Doom: E Kill Credit'),
(24093, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43086 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - On Spellhit - Cast Towers of Certain Doom: SW Kill Credit'),
(24094, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43087 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - On Spellhit - Cast Towers of Certain Doom: SE Kill Credit'),
(24087, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43067 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - On Spellhit - Cast Towers of Certain Doom: NW Kill Credit'),
(24092, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43077 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - On Spellhit - Cast Towers of Certain Doom: E Kill Credit'),
(24093, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43086 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - On Spellhit - Cast Towers of Certain Doom: SW Kill Credit'),
(24094, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43087 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - On Spellhit - Cast Towers of Certain Doom: SE Kill Credit'),
(24087, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - Linked with Previous Event - Run Timed Script'),
(24092, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - Linked with Previous Event - Run Timed Script'),
(24093, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - Linked with Previous Event - Run Timed Script'),
(24094, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - Linked with Previous Event - Run Timed Script'),
(2408700, 9, 0, 0, 0,  0, 100, 0, 2000, 2000, 0, 0, 11, 56511 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Tower Bunny Smoke Flare Effect'),
(2408700, 9, 1, 0, 0,  0, 100, 0, 15000, 15000, 0, 0, 11, 43069 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Skorn Cannonfire'),
(2408700, 9, 2, 0, 0,  0, 100, 0, 100, 100, 0, 0, 85, 43072 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Tower Caster Instakill');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13  AND `SourceEntry`IN(49625,49634,43072);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,49625,0,0,31,0,3,24087,0,0,0,0,'','Braves Flare targets Skorn Tower NW Bunny'),
(13,1,49625,0,1,31,0,3,24092,0,0,0,0,'','Braves Flare targets Skorn Tower E Bunny'),
(13,1,49625,0,2,31,0,3,24093,0,0,0,0,'','Braves Flare targets Skorn Tower SW Bunny'),
(13,1,49625,0,3,31,0,3,24094,0,0,0,0,'','Braves Flare targets Skorn Tower SE Bunny'),
(13,1,49634,0,0,31,0,3,24087,0,0,0,0,'','Seargents Flare targets Skorn Tower NW Bunny'),
(13,1,49634,0,1,31,0,3,24092,0,0,0,0,'','Seargents Flare targets Skorn Tower E Bunny'),
(13,1,49634,0,2,31,0,3,24093,0,0,0,0,'','Seargents Flare targets Skorn Tower SW Bunny'),
(13,1,49634,0,3,31,0,3,24094,0,0,0,0,'','Seargents Flare targets Skorn Tower SE Bunny'),
(13,1,43072,0,0,31,0,3,23668,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Rune-Caster'),
(13,1,43072,0,1,31,0,3,23667,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Rune-Seer'),
(13,1,43072,0,2,31,0,3,23669,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Oracle');
