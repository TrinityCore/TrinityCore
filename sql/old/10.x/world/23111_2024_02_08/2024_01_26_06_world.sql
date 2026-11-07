-- Novice Darkspear Warrior update spawn location "Atm spawns are in combat positions"
UPDATE `creature` SET `position_x`=-1187.4618,`position_y`=-5520.4707,`position_z`=12.001953,`orientation`=3.14159 WHERE `guid`=309087;
UPDATE `creature` SET `position_x`=-1164.0677,`position_y`=-5431.7085,`position_z`=12.649599,`orientation`=2.7401669 WHERE `guid`=309169;
UPDATE `creature` SET `position_x`=-1205.0642,`position_y`=-5402.847,`position_z`=11.956104,`orientation`=6.26573 WHERE `guid`=309206;
UPDATE `creature` SET `position_x`=-1153.0348,`position_y`=-5586.3613,`position_z`=11.965891, `orientation`= 4.18879 WHERE `guid`=308999;
UPDATE `creature` SET `position_x`=-1152.8177,`position_y`=-5391.0767,`position_z`=11.991767,`orientation`=1.745329 WHERE `guid`=309178;
UPDATE `creature` SET `position_x`=-1173.6754,`position_y`=-5445.4985,`position_z`=12.001932,`orientation`=5.35816 WHERE `guid`=309163;
-- Novice Darkspear Rogue update spawn location "Atm spawns are in combat positions"
UPDATE `creature` SET `position_x`=-1112.4531,`position_y`=-5463.375,`position_z`=12.006897,`orientation`=4.6600289 WHERE `guid`=309121;
UPDATE `creature` SET `position_x`=-1194.0798,`position_y`=-5417.993,`position_z`=11.933159,`orientation`=5.4454274 WHERE `guid`=309195;
UPDATE `creature` SET `position_x`=-1121.4705,`position_y`=-5443.1196,`position_z`=11.963619,`orientation`=6.003932 WHERE `guid`=309139;
UPDATE `creature` SET `position_x`=-1119.9688,`position_y`=-5496.0923,`position_z`=12.001489,`orientation`=2.391101 WHERE `guid`=309100;

-- Add to sparring template
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (38038,38268,38272,38278,38279,38280,38281,38282,42619);
INSERT INTO `creature_template_sparring` (`Entry`,`NoNPCDamageBelowHealthPct`) VALUES
(38038,85), -- Tiki Target
(38268,100), -- Novice Darkspear Warrior
(38272,100), -- Novice Darkspear Rogue
(38278,100), -- Novice Darkspear Priest
(38279,100), -- Novice Darkspear Mage
(38280,100), -- Novice Darkspear Druid
(38281,100), -- Novice Darkspear Shaman
(38282,100), -- Novice Darkspear Hunter
(42619,100); -- Novice Darkspear Warlock

-- Add emotestate and auras
DELETE FROM `creature_template_addon` WHERE `entry` IN (38268,38272,38278,38279,38280,38281,38282,42619,63309);
INSERT INTO `creature_template_addon` (`entry`,`emote`,`auras`) VALUES
(38268,375,''), -- Novice Darkspear Warrior
(38272,375,''), -- Novice Darkspear Rogue
(38278,375,'73299'), -- Novice Darkspear Priest
(38279,375,'73299'), -- Novice Darkspear Mage
(38280,375,'73299'), -- Novice Darkspear Druid
(38281,375,'73299'), -- Novice Darkspear Shaman
(38282,375,''), -- Novice Darkspear Hunter
(42619,375,'73299'), -- Novice Darkspear Warlock
(63309,510,''); -- Tsu the Wanderer

-- Update creature movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (38278,38279,38280,38281,38282,42619);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(38278,1,0,0,1,0,0,0), -- Novice Darkspear Priest
(38279,1,0,0,1,0,0,0), -- Novice Darkspear Mage
(38280,1,0,0,1,0,0,0), -- Novice Darkspear Druid
(38281,1,0,0,1,0,0,0), -- Novice Darkspear Shaman
(38282,1,0,0,1,0,0,0), -- Novice Darkspear Hunter
(42619,1,0,0,1,0,0,0); -- Novice Darkspear Warlock

-- Novice Darkspear Warrior SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38268;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38268) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38268,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Warrior - OOC - Set React state Aggressive'),
(38268,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,10,0,0,0,0,0,0,'Novice Darkspear Warrior - OOC - Attack closest Tiki Target'),
(38268,0,2,0,0,0,100,0,8000,12000,8000,12000,0,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Warrior - IC - Cast Heroic Strike'),
(38268,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Warrior - Evade - Set React state Passive');

-- Novice Darkspear Rogue SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38272;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38272) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38272,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Rogue - OOC - Set React state Aggressive'),
(38272,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,10,0,0,0,0,0,0,'Novice Darkspear Rogue - OOC - Attack closest Tiki Target'),
(38272,0,2,0,0,0,100,0,8000,12000,8000,12000,0,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Rogue - IC - Cast Sinister Strike'),
(38272,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Rogue - Evade - Set React state Passive');
-- Novice Darkspear Priest SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38278;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38278) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38278,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Priest - OOC - Set React state Aggressive'),
(38278,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,14,0,0,0,0,0,0,'Novice Darkspear Priest - OOC - Attack Tiki Target'),
(38278,0,2,0,0,0,100,0,0,3000,3000,3000,0,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Priest - IC - Cast Holy Smite'),
(38278,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Priest - Evade - Set React state Passive');


-- Novice Darkspear Mage SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38279;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38279) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38279,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Mage - OOC - Set React state Aggressive'),
(38279,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,20,0,0,0,0,0,0,'Novice Darkspear Mage - OOC - Attack Tiki Target'),
(38279,0,2,0,0,0,100,0,0,3000,3500,3500,0,11,20797,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Mage - IC - Cast Fireball'),
(38279,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Mage - Evade - Set React state Passive');
-- Novice Darkspear Druid SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38280;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38280) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38280,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Druid - OOC - Set React state Aggressive'),
(38280,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,14,0,0,0,0,0,0,'Novice Darkspear Druid - OOC - Attack Tiki Target'),
(38280,0,2,0,0,0,100,0,0,3000,2500,2500,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Druid - IC - Cast Wrath'),
(38280,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Druid - Evade - Set React state Passive');

-- Novice Darkspear Shaman SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38281;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38281) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38281,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Shaman - OOC - Set React state Aggressive'),
(38281,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,10,0,0,0,0,0,0,'Novice Darkspear Shaman - OOC - Attack Tiki Target'),
(38281,0,2,0,0,0,100,0,0,3000,3500,3500,0,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Shaman - IC - Cast Lightning Bolt'),
(38281,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Shaman - Evade - Set React state Passive');

-- Novice Darkspear Hunter SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38282;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38282) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38282,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Hunter - OOC - Set React state Aggressive'),
(38282,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,10,0,0,0,0,0,0,'Novice Darkspear Hunter - OOC - Attack Tiki Target'),
(38282,0,2,0,0,0,100,0,0,3000,1000,1000,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Hunter - IC - Cast Lightning Bolt'),
(38282,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Hunter - Evade - Set React state Passive');

-- Novice Darkspear Warlock SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=42619;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (42619) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(42619,0,0,1,1,0,100,0,13000,13000,13000,13000,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Warlock - OOC - Set React state Aggressive'),
(42619,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,38038,14,0,0,0,0,0,0,'Novice Darkspear Warlock - OOC - Attack Tiki Target'),
(42619,0,2,0,0,0,100,0,0,3000,3500,3500,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Novice Darkspear Warlock - IC - Cast Shadow Bolt'),
(42619,0,3,0,7,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Darkspear Warlock - Evade - Set React state Passive');
