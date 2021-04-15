-- [Q] The Warm-Up
-- Kirgaraak SAI
SET @ENTRY := 29352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;


DELETE FROM smart_scripts WHERE source_type=0 AND entryorguid=@ENTRY;
DELETE FROM smart_scripts WHERE source_type=9 AND entryorguid=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,5,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,'Kirgaraak - At 5% HP - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,33,30221,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kirgaraak - On Script - Quest Credit'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kirgaraak - On Script - Make Friendly'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kirgaraak - On Script - Evade'),
(@ENTRY*100,9,3,0,0,0,100,0,10000,10000,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kirgaraak - On Script - Reset Faction');

UPDATE `creature_template` SET `exp`=0 WHERE `entry`=24921; -- Cosmetic Trigger - LAB

UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=7,`gender`=0 WHERE `modelid`=26202; -- Kirgaraak

DELETE FROM `creature_template_addon` WHERE `entry` IN (@ENTRY,29918,24921);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,1,0, NULL), -- Kirgaraak
(29918,0,0,1,0, NULL), -- Warbear Matriarch
(24921,0,0,1,0, NULL); -- Cosmetic Trigger - LAB

-- Not working correctly. It will work when spells get fixed
-- 1) Can't have more than one 54324 in the same target. 2) That aura gets removed when target enters in combat and it shouldn't
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=24921;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN -104008 AND -103996 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-103996, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-103997, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-103998, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-103999, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104000, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104001, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104002, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104003, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104004, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104005, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104006, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104007, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak'),
(-104008, 0, 0, 0, 1, 0, 0, 1, 500, 500, 0, 0, 11, 54324, 0, 0, 0, 0, 0, 11, @ENTRY, 60, 0, 0, 0, 0, 0, 'Cosmetic Trigger - LAB (Brunnhildar Village) - Cast Cosmetic Chains at Kirgaraak');
