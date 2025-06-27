UPDATE `creature_template` SET `ScriptName`='npc_rocket_propelled_warhead' WHERE `entry`=27593;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_z_check', 'spell_vehicle_warhead_fuse', 'spell_warhead_detonate','spell_warhead_fuse');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61678, 'spell_z_check'),
(49107, 'spell_vehicle_warhead_fuse'),
(49250, 'spell_warhead_detonate'),
(49181, 'spell_warhead_fuse');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49332;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,49332,0,1,31,0,3,27702,0,0,0,0,'',"Spell 'Warhead Seeking Mine' can hit 'Horde Lumberboat'"),
(13,1,49332,0,2,31,0,3,27688,0,0,0,0,'',"Spell 'Warhead Seeking Mine' can hit 'Alliance Lumberboat'");

-- Warhead Explosion Bunny SAI
UPDATE `creature_template` SET `InhabitType`=4, `AIName`='SmartAI' WHERE `entry`=27663;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27663 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27663,0,0,0,54,0,100,0,0,0,0,0,11,49290,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warhead Explosion Bunny - Just Summoned - Cast \'Torpedo Explosion\'');

-- Alliance Lumberboat Explosions SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27689;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27689 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2768900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27689,0,0,0,8,0,100,0,49290,0,0,0,80,2768900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Lumberboat Explosions - On SpellHit \'Warhead Seeking Mine\' - Cast \'Horde Boat to Torpedo\''),
(2768900,9,0,0,0,0,100,0,0,0,0,0,11,42344,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Lumberboat Explosions - ActionList - Cast \'Cosmetic - Flame Patch 0.5\''),
(2768900,9,1,0,0,0,50,0,11000,11000,0,0,11,42345,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Lumberboat Explosions - ActionList - Cast \'Cosmetic - Flame Patch\''),
(2768900,9,2,0,0,0,50,0,11000,11000,0,0,11,42346,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Lumberboat Explosions - ActionList - Cast \'Cosmetic - Flame Patch 2.0\'');

-- Horde Lumberboat SAI
UPDATE `creature_template` SET `InhabitType`=4, `AIName`='SmartAI' WHERE `entry`=27702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27702 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27702,0,0,0,8,0,100,0,49332,0,0,0,11,49372,0,0,0,0,0,9,27593,0,100,0,0,0,0,'Horde Lumberboat - On SpellHit \'Warhead Seeking Mine\' - Cast \'Horde Boat to Torpedo\'');

-- Alliance Lumberboat SAI
UPDATE `creature_template` SET `InhabitType`=4, `AIName`='SmartAI' WHERE `entry`=27688;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27688 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27688,0,0,0,8,0,100,0,49332,0,0,0,11,49257,0,0,0,0,0,9,27593,0,100,0,0,0,0,'Alliance Lumberboat - On SpellHit \'Warhead Seeking Mine\' - Cast \'Alliance Boat to Torpedo\'');
