-- Fix I've Got a Flying Machine
-- Steel Gate Chief Archaeologist SAI & Text & Condition
SET @ENTRY			 := 24399;
SET @ENTRY1			:= 24418;
SET @ENTRY2			:= 24439;
SET @ENTRY3			:= 24438;
SET @STALKER		 := 105997;
SET @CGUID			 := 142705;
SET @MENUID			:= 8954;
SET @OPTION			:= 0;

UPDATE `creature_template` SET  `unit_flags`=16777216, `InhabitType`=5, `spell1`=44009, `spell2`=43770, `spell3`=43799, `spell4`=43769, `spell5`=47769 WHERE `entry`=@ENTRY1;
DELETE FROM `creature` WHERE `id`=24439;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID+0, 24439, 571, 1, 1, 24780, 0, 2088.714, -3263.196, 82.50323, 0.2792527, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: 0)
(@CGUID+1, 24439, 571, 1, 1, 24780, 0, 2047.712, -3236.201, 62.82506, 3.682645, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+2, 24439, 571, 1, 1, 24780, 0, 2017.764, -3243.003, 74.95174, 3.246312, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+3, 24439, 571, 1, 1, 24780, 0, 2068.706, -3318.71, 98.2312, 5.72468, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+4, 24439, 571, 1, 1, 24780, 0, 1996.727, -3323.912, 99.77941, 5.532694, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+5, 24439, 571, 1, 1, 24780, 0, 2068.706, -3318.71, 98.2312, 5.72468, 120, 0, 0, 42, 0, 0, 0, 0, 0); -- Sack of Relics (Area: 0)

DELETE FROM `creature_template_addon` WHERE `entry`=24418;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(24418, 0, 0, 0, 0x1, 0x1, '43775 43889'); -- Steel Gate Flying Machine - Flight Drop Off Buff

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@MENUID,@OPTION,0,0,11,45973,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On gossip option select - Cast spell'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On Link - Close gossip'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,43767,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On Link - Cast Invoker'),
(@ENTRY,0,3,4,19,0,100,1,11390,0,0,0,11,45973,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On Quest Accept - Cast spell'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,43767,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On Link - Cast Invoker'),
(@ENTRY,0,5,0,19,0,100,0,11390,0,0,0,12,@ENTRY3,3,120000,0,0,0,8,0,0,0,1972.773,-3265.381,134.719,0, 'Steel Gate Chief Archaeologist - On Link - Cast Invoker');

UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0, `AIName`= 'SmartAI', `type_flags`=1048576 WHERE `entry`=@ENTRY3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY3; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY3,0,0,0,54,0,100,0,0,0,0,0,11,43890,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grapple Target - Just Summoned - Cast Invisibility on self');


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= @ENTRY1;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(@ENTRY1, 43768, 1, 0); 

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@MENUID AND `id`=@OPTION;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@MENUID,@OPTION,0,'Sir, I need another flying machine...',1,1,0,0,0,0,'');

-- Gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@MENUID AND `SourceEntry`=@OPTION;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@MENUID,@OPTION,0,9,11390,0,0,0,'','Show gossip option 0 if player has quest I''ve got a Flying Machine');

DELETE FROM `conditions` WHERE `SourceEntry`=@ENTRY1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16, 0, @ENTRY1, 0, 23, 3999, 0, 0, 0, '', 'Dismount player when not in intended zone');
-- Condition for Grappling Hook spell(43770)
DELETE FROM `conditions` WHERE `SourceEntry`=43770;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 43770, 0, 31, 3, 24439, 0, 0, '', 'Spell 43770(Grappling Hook) targets npc 24439(Sack of Relics)');
-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceEntry`IN (43891,43892,43789);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 43892, 0, 31, 3, 24439, 0, 0, '', 'Spell 43892 targets npc 24439'),
(13, 1, 43891, 0, 29, @ENTRY2, 1, 0, 0, '', 'Spell 43892 targets npc 24439'),
(13, 1, 43789, 0, 31, 3, 24439, 0, 0, '', 'Spell 43892 targets npc 24439');

-- Sack of Relics SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY2 AND `source_type`=0;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY2,0,0,0,8,0,100,0,43770,0,0,0,11,46598,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Sack of Relics - On Link - Mount Sack to vehicle'),
(@ENTRY2,0,1,2,8,0,100,1,43892,0,0,0,11,46598,0,0,0,0,0,10,105997,15214,0,0.0,0.0,0.0,0.0,' Sack of Relics - Remove Vehicle - In range'),
(@ENTRY2,0,2,3,61,0,100,1,0,0,0,0,11,36553,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Sack of Relics - On Link - Cast pet stay(36553)'),
(@ENTRY2,0,3,4,61,0,100,1,0,0,0,0,33,24439,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,'Sack of Relics - On Link - Quest Credit'),
(@ENTRY2,0,4,0,61,0,100,1,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Sack of Relics - On Link - Despawn');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43770;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(43770,43789,1,'Trigger grip beam');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-@STALKER AND `source_type`=0;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=15214;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(-@STALKER,0,0,0,1,0,100,0,0,0,0,0,11,43892,0,0,0,0,0,11,@ENTRY2,10,0,0.0,0.0,0.0,0.0,'Invisible Stalker - OOC - Cast Spell');
