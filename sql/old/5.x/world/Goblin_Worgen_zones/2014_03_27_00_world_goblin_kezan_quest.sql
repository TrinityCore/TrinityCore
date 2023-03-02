-- NPC 34830 - Defiant Troll
SET @ENTRY := 34830;
SET @SOURCETYPE := 0;

UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,8,0,100,1,66306,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - On Spellhit - Run script'),
(@ENTRY,@SOURCETYPE,1,0,7,0,100,0,0,0,0,0,71,0,0,2704,0,0,1,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - On reset - Equip Jar'),
(@ENTRY,@SOURCETYPE,2,0,7,0,100,0,0,0,0,0,10,467,26,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - On reset - Random emote'),
(@ENTRY,@SOURCETYPE,3,0,7,0,100,0,0,0,0,0,75,45111,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - On reset - Add aura 45111'),
(@ENTRY,@SOURCETYPE,4,0,23,0,100,0,45111,1,30000,30000,10,412,10,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - On spawn - Random emote');

-- NPC 34830 - Defiant Troll - Script 0
SET @SOURCETYPE := 9;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY*100,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Talk'),
(@ENTRY*100,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,20,195489,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Go to nearest GO 195489'),
(@ENTRY*100,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,71,0,0,1910,0,0,1,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Equip Pick'),
(@ENTRY*100,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Emote mining 233'),
(@ENTRY*100,@SOURCETYPE,4,0,0,0,100,0,0,0,0,0,28,45111,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Remove aura 45111'),
(@ENTRY*100,@SOURCETYPE,5,0,0,0,100,0,0,0,0,0,33,34830,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Quest credit'),
(@ENTRY*100,@SOURCETYPE,6,0,0,0,100,0,120000,120000,0,0,24,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Defiant Troll - Script - Evade');

-- Creature text for NPC 34830 - Defiant Troll

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Oops, break''s over.', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 1, 'Don''t tase me, mon!', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 2, 'I report you to HR!', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 3, 'Work was bettah in da Undermine!', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 4, 'I''m going. I''m going!', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 5, 'Sorry, mon. It won''t happen again.', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 6, 'What I doin'' wrong? Don''t I get a lunch and two breaks a day, mon?', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find'),
(@ENTRY, 0, 7, 'Ouch! Dat hurt!', 12, 0, 100, 1, 0, 0, 'Quest 14069 - Good help is hard to find');

-- Conditions for spell 66306
DELETE FROM conditions WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 66306 AND `ConditionValue1` = 45111;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('13', '34830', '66306', '0', '0', '1', '0', '45111', '0', '0', '0', '0', '', 'Quest 14069 - Goblin All-In-1-Der Belt Shocker can hit only target under aura 45111');

DELETE FROM conditions WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 66306 AND `ConditionValue1` = 14069;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '34830', '66306', '0', '0', '9', '0', '14069', '0', '0', '0', '0', '', 'Quest 14069 - QUESTTAKEN');


UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 34830;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('34830', '66306', '1', '0');

UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 34865;

UPDATE `creature_template` SET `IconName` = 'vehichleCursor', `unit_flags` = 32768, `type_flags` = 2080, `VehicleId` = 468, `mechanic_immune_mask` = 1073741823 WHERE `entry` = 34840;

-- 34890 Killcredit
DELETE FROM `creature_template_addon` WHERE (`entry`=34890);
UPDATE `creature_template` SET `npcflag` = 1, `AIName` = 'SmartAI' WHERE `entry` = 34890;

DELETE FROM `smart_scripts` WHERE (`entryorguid`='34890') AND (`source_type`='0') AND (`id`='0') AND (`link`='0');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('34890', '0', '0', '0', '64', '0', '100', '1', '0', '0', '0', '0', '33', '34959', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Izzy - On Spellhit - Kill Credit');

-- 34954 killcredit 34958
DELETE FROM `creature_template_addon` WHERE (`entry`=34954);
UPDATE `creature_template` SET `npcflag` = 1, `KillCredit1` = 0, `AIName` = 'SmartAI' WHERE `entry` = 34954;

DELETE FROM `smart_scripts` WHERE (`entryorguid`='34954') AND (`source_type`='0') AND (`id`='0') AND (`link`='0');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('34954', '0', '0', '0', '64', '0', '100', '1', '0', '0', '0', '0', '33', '34958', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Gobber - On Gossip - Kill Credit');

-- 34957 killcredit 34957
DELETE FROM `creature_questrelation` WHERE (`id`='34957') AND (`quest`='14071');
UPDATE `creature` SET `phaseMask` = 1 WHERE `guid` = 1407134;
DELETE FROM `creature_template_addon` WHERE (`entry`=34957);
UPDATE `creature_template` SET `npcflag` = 1, `KillCredit1` = 0, `AIName` = 'SmartAI' WHERE `entry` = 34957;

DELETE FROM `smart_scripts` WHERE (`entryorguid`='34957') AND (`source_type`='0') AND (`id`='0') AND (`link`='0');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('34957', '0', '0', '0', '64', '0', '100', '1', '0', '0', '0', '0', '33', '34957', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Ace - On Gossip - Kill Credit');


UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 2098 WHERE `Id` = 14010;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 56641 WHERE `Id` = 14007;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 122 WHERE `Id` = 14008;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 100 WHERE `Id` = 14013;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 172 WHERE `Id` = 14012;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 73899 WHERE `Id` = 14011;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 48304, `RequiredSpellCast1` = 89 WHERE `Id` = 14009;


UPDATE `creature_template` SET `spell1` = 69992, `spell2` = 70051, `VehicleId` = 116 WHERE `entry` = 48526;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0, `RequiredNpcOrGo2` = 0, `RequiredNpcOrGoCount1` = 0, `RequiredNpcOrGoCount2` = 0 WHERE `Id` = 24502;

UPDATE `gameobject_template` SET `flags` = 2, `data0` = 2047, `data1` = 30684, `AIName` = '' WHERE `entry` = 211597;


UPDATE `quest_template` SET `ExclusiveGroup` = 24503 WHERE `Id` = 28414;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0, `RequiredNpcOrGoCount1` = 0 WHERE `Id` = 28414;

DELETE FROM `creature` WHERE `id`=34835;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES ('1342175', '34835', '648', '4737', '4771', '1', '1', '0', '0', '-8403.81', '1517.44', '50.8174', '1.95477', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0');

DELETE FROM `creature` WHERE `id`=34877;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES ('1342440', '34877', '648', '4737', '4771', '1', '1', '0', '0', '-8431.76', '1655.16', '45.8771', '5.75959', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0');

DELETE FROM `creature` WHERE `id`=34876;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES ('1342416', '34876', '648', '4737', '4771', '1', '1', '0', '0', '-8360.79', '1631.09', '49.6333', '3.22886', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0');


-- npc 35128
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='10622') AND (`id`='0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10622;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES 
('15', '10622', '0', '0', '1', '9', '0', '14109', '0', '0', '0', '0', '', ''),
('15', '10622', '0', '0', '0', '9', '0', '14110', '0', '0', '0', '0', '', ''),
('15', '10622', '0', '0', '0', '2', '0', '47046', '1', '1', '1', '0', '', '');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 35128;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35128;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES 
('35128', '0', '0', '0', '62', '0', '100', '0', '10622', '0', '0', '0', '85', '66781', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Szabo - On Gossip option - Cast spell 66781 on player');


-- Missa Spekkies npc 35130
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='10624') AND (`id`='0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10624;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES 
('15', '10624', '0', '0', '1', '9', '0', '14109', '0', '0', '0', '0', '', ''),
('15', '10624', '0', '0', '0', '9', '0', '14110', '0', '0', '0', '0', '', ''),
('15', '10624', '0', '0', '0', '2', '0', '47047', '1', '1', '1', '0', '', '');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 35130;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35130;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES 
('35130', '0', '0', '0', '62', '0', '100', '0', '10624', '0', '0', '0', '85', '66782', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Missa Spekkies - On Gossip option - Cast spell 66781 on player');

-- npc 35126
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='10620') AND (`id`='0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10620;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES 
('15', '10620', '0', '0', '1', '9', '0', '14109', '0', '0', '0', '0', '', ''),
('15', '10620', '0', '0', '0', '9', '0', '14110', '0', '0', '0', '0', '', ''),
('15', '10620', '0', '0', '0', '2', '0', '47047', '1', '1', '1', '0', '', '');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 35126;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35126;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES 
('35126', '0', '0', '0', '62', '0', '100', '0', '10620', '0', '0', '0', '85', '66780', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Gappy Silvertooth - On Gossip option - Cast spell 66781 on player');

UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0, `RequiredNpcOrGoCount1` = 0 WHERE `Id` = 14113;

DELETE FROM `spell_area` WHERE `area`= 4822 AND `spell` = 8192;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_status`) VALUES ('8192', '4822', '14121', '8');

UPDATE `creature_template` SET `VehicleId` = 457 WHERE `entry` = 35486;
UPDATE `creature_template` SET `faction_A` = 36, `faction_H` = 36, `npcflag` = 4 WHERE `entry` = 35486;

UPDATE `gameobject_template` SET `type` = 10 WHERE `entry` = 195525;
UPDATE `gameobject_template` SET `AIName` = 'SmartAI' WHERE `entry` = 195525;


DELETE FROM `smart_scripts` WHERE (`entryorguid`=195525 AND `source_type`=1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(195525, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 35486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'KillCredit'),
(195525, 1, 1, 0, 64, 0, 100, 0, 0, 0, 0, 0, 56, 46858, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Die');


UPDATE `quest_template` SET `RequiredNpcOrGo4` = 0, `RequiredNpcOrGoCount4` = 0 WHERE `Id` = 14125;
UPDATE `quest_template` SET `ObjectiveText4` = '' WHERE `Id` = 14125;

UPDATE `quest_template` SET `CompleteScript`='14126' WHERE (`Id`='14126');

DELETE FROM `quest_end_scripts` WHERE `id`='14126' AND `command`='6'; 
INSERT INTO `quest_end_scripts` (`id`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES 
('14126', '6', '1', '1468.59', '-5013.07', '11.7373', '3.17261');
