-- Add support for quest: http://www.wowhead.com/quest=12152
-- Indexes
-- TO DO: Add spawns with "Place Offering" Effect 1 - send event for the npc that come after ward summon Jin'Jarrack, also put his spawn in that spell, if anyone ever do it
SET @OFFERING_BUNNY := 27200;
SET @OFFERING_TARGET_BUNNY := 27201;
SET @JIN_ARRAK := 27199;
SET @SCRIPT := @JIN_ARRAK * 100;

-- Template updates
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=unit_flags|0x00000100|0x00000200,`faction_A`=14,`faction_H`=14 WHERE `entry`=@JIN_ARRAK;
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x00000100|0x02000000,`flags_extra`=0x00000080,`AIName`='SmartAI' WHERE `entry`=@OFFERING_BUNNY;
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x00000100|0x02000000,`flags_extra`=0x00000080 WHERE `entry`=@OFFERING_TARGET_BUNNY;

-- SAI support
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@OFFERING_BUNNY,@JIN_ARRAK) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OFFERING_BUNNY,0,0,1,54,0,100,0,0,0,0,0,11,48059,0,0,0,0,0,1,0,0,0,0,0,0,0,'Offering Bunny - On just summoned - Cast spell that send event'),
(@OFFERING_BUNNY,0,1,2,61,0,100,0,0,0,0,0,11,48194,0,0,0,0,0,0,0,0,0,0,0,0,0,'Offering Bunny - Linked - Cast kill credit spell'),
(@OFFERING_BUNNY,0,2,0,61,0,100,0,0,0,0,0,12,@JIN_ARRAK,3,30000,0,0,0,8,0,0,0,4678.617,-4859.459,35.56327,3.124139,'Offering Bunny - Linked - Summon Jin''Arrack [need to be put in the spell event, when all rest are added]'),
(@JIN_ARRAK,0,0,1,54,0,100,0,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - On just summoned - Cast Spirit Particles on self'),
(@JIN_ARRAK,0,1,2,61,0,100,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Linked - Play emote roar'),
(@JIN_ARRAK,0,2,0,61,0,100,0,0,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Linked - Start actionlist'),
(@SCRIPT,9,0,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,1000,1000,0,0,11,48060,0,0,0,0,0,19,@OFFERING_BUNNY,0,0,0,0,0,0,'Warlord Jin''Arrak - Action 1 - Cast feed'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,11,31951,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Action 2 - Cast super particle on self'),
(@SCRIPT,9,3,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Action 3 - Say 2'),
(@SCRIPT,9,4,0,0,0,100,0,100,100,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Action 4 - Set field_byte_1 to 7');

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@JIN_ARRAK;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@JIN_ARRAK,0,0,'Finally, a worthy offering!',41,0,100,15,0,0, 'Warlord Jin''Arrak'),
(@JIN_ARRAK,1,0,'Ahhh! What be happenin'' to me, mon?',41,0,100,0,0,0, 'Warlord Jin''Arrak');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`=48194 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,48194,0,0,32,0,144,0,0,0,0,'', 'Jin''Arrak quest kill credit can hit only players'),
(13,1,48194,0,0,9,0,12152,0,0,0,0,'', 'Jin''Arrak quest kill credit hit target must be on quest Jin''Arrak end');
