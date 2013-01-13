-- Quest 12512 "Leave No One Behind"
-- Fix Leave No One Behind Bunny
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `guid`=117936;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=28137;

-- SAI for Leave No One Behind Bunny
SET @ENTRY := 28137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,0,2000,2000,2000,2000,11,50669,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Leave No One Behind Bunny - OOC - Cast Quest Credit');

-- Add condition for Spell 50669 "Quest Credit"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=50669;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,50669,0,31,3,28142,0,0,'','Spell Quest Credit targets Crusader Lamoof'),
(13,1,50669,1,31,3,28136,0,0,'','Spell Quest Credit targets Crusader Jonothan'),
(13,1,50669,2,31,3,28148,0,0,'','Spell Quest Credit targets Crusader Josephine');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (28142,28136,28148);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28142,0,0, '<sigh>... Well, I suppose it could be worse.',12,0,100,0,0,0, 'Crusader Lamoof'),
(28136,0,0, 'Thank you, friend. Were it not for your aid I would be no more.',12,0,100,0,0,0, 'Crusader Jonothan'),
(28148,0,0, 'I am in your debt, friend. Thank you for my life.',12,0,100,0,0,0, 'Crusader Josephine');

-- SAI for Crusader Lamoof
SET @ENTRY := 28142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,50681,4,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On Spawn - cast Bleeding Out'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Lamoof - On Spawn - follow envoker'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On Spawn - Set Phase 1'),
(@ENTRY,0,3,0,23,0,100,0,50681,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - Aura missing - despawn'),
(@ENTRY,0,4,0,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spell hit - Set Phase 2'),
(@ENTRY,0,5,0,1,2,100,1,0,0,0,0,11,50683,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - OOC - Cast Kill Credit Lamoof 01 (Phase 2)'),
(@ENTRY,0,6,0,1,2,100,1,100,100,0,0,11,50723,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - OOC - Cast Strip Aura Lamoof 01 (Phase 2)'),
(@ENTRY,0,7,0,1,2,100,1,200,200,0,0,29,1,0,0,0,0,0,19,28137,20,0,0,0,0,0, 'Crusader Lamoof - OOC - follow bunny (Phase 2)'),
(@ENTRY,0,8,0,1,2,100,1,400,400,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - OOC - Say text (Phase 2)');

-- SAI for Crusader Jonothan
SET @ENTRY := 28136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,50665,4,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - On Spawn - cast Bleeding Out'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Jonothan - On Spawn - follow envoker'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - On Spawn - Set Phase 1'),
(@ENTRY,0,3,0,23,0,100,0,50665,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - Aura missing - despawn'),
(@ENTRY,0,4,0,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - On spell hit - Set Phase 2'),
(@ENTRY,0,5,0,1,2,100,1,0,0,0,0,11,50671,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - OOC - Cast Kill Credit Jonothan 01 (Phase 2)'),
(@ENTRY,0,6,0,1,2,100,1,100,100,0,0,11,50709,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - OOC - Cast Strip Aura Jonothan 01 (Phase 2)'),
(@ENTRY,0,7,0,1,2,100,1,200,200,0,0,29,1,0,0,0,0,0,19,28137,20,0,0,0,0,0, 'Crusader Jonothan - OOC - follow bunny (Phase 2)'),
(@ENTRY,0,8,0,1,2,100,1,400,400,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - OOC - Say text (Phase 2)');

-- SAI for Crusader Josephine
SET @ENTRY := 28148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,50695,4,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On Spawn - cast Bleeding Out'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Josephine - On Spawn - follow envoker'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On Spawn - Set Phase 1'),
(@ENTRY,0,3,0,23,0,100,0,50695,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - Aura missing - despawn'),
(@ENTRY,0,4,0,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spell hit - Set Phase 2'),
(@ENTRY,0,5,0,1,2,100,1,0,0,0,0,11,50698,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - OOC - Cast Kill Credit Josephine 01 (Phase 2)'),
(@ENTRY,0,6,0,1,2,100,1,100,100,0,0,11,50711,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - OOC - Cast Strip Aura Josephine 01 (Phase 2)'),
(@ENTRY,0,7,0,1,2,100,1,200,200,0,0,29,1,0,0,0,0,0,19,28137,20,0,0,0,0,0, 'Crusader Josephine - OOC - follow bunny (Phase 2)'),
(@ENTRY,0,8,0,1,2,100,1,400,400,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - OOC - Say text (Phase 2)');
