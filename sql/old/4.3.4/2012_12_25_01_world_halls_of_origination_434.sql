DELETE FROM `creature_text` WHERE `entry`=39428;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39428, 0, 0, 'More carrion for the swarm...', 14, 0, 100, 0, 0, 18906, 'Earthrager Ptah - SAY_AGGRO'),
(39428, 1, 0, 'Ptah... is... no more...', 14, 0, 100, 0, 0, 18905, 'Earthrager Ptah  - SAY_DEATH');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (75540,89881,94974,75519);
INSERT INTO `spell_script_names` VALUES
(75540,'spell_earthrager_ptah_flame_bolt'),
(89881,'spell_earthrager_ptah_flame_bolt'),
(75519 ,'spell_earthrager_ptah_explosion'),
(94974,'spell_earthrager_ptah_earth_spike');

UPDATE `creature_template` SET `ScriptName`='boss_earthrager_ptah' WHERE `Entry`=39428;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=89398;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 6, 89398, 0, 0, 31, 0, 3, 39443, 0, 0, 0, 0, '', 'Earth Spike - Camel');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=39443;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(39443,89397,1,0);

-- Jeweled Scarab SAI
SET @ENTRY := 40458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jeweled Scarab - On just summoned - Remove field byte for submerged'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,65982,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jeweled Scarab - Linked - Cast emerge'),
(@ENTRY,0,2,0,1,0,100,1,2500,2500,2500,2500,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0, 'Jeweled Scarab - OOC (one time) - Attack player in 100 yards'),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,39428,100,0,0,0,0,0, 'Jeweled Scarab - On death - Set data 0 - 1'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jeweled Scarab - Linked - Add again byte for submerged');
 
-- Dustbone Horror SAI
SET @ENTRY := 40450;
SET @SPELL := 75453; -- Smash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dustbone Horror - On just summoned - Remove field byte 1 for submerged'),
(@ENTRY,0,1,0,1,0,100,1,2500,2500,2500,2500,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0, 'Dustbone Horror - OOC (one time) - Attack player in 100 yards'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,10000,12000,11,@SPELL,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Dustbone Horror - Combat - Cast Smash'),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,39428,100,0,0,0,0,0, 'Dustbone Horror - On death - Set data 0 - 1'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dustbone Horror - Linked - Add again byte for submerged');
 
-- Add creature_addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (40458,40450);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(40458,0,0,9,1,0,NULL),
(40450,0,0,9,1,0,NULL);

SET @QUICKSAND := 75548;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@QUICKSAND;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@QUICKSAND,0,0,0,54,0,100,0,0,0,0,0,11,40503,0,0,0,0,0,1,0,0,0,0,0,0,0,'Quicksand - On summoned (spawned) - Cast spell');
