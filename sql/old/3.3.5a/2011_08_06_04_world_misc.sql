-- honor challenge
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30037;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30037 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(30037,0,0,0,8,0,100,0,21855,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mjordin Combatant - set to phase 1 when aggroed by spell'),
(30037,0,1,0,6,1,100,0,0,0,0,0,33,30038,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mjordin Combatant - give credit only when it has buff');

-- forgotten depths ambusher
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30204 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(30204,0,0,0,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Depths Ambusher - change flags when aggroed'),
(30204,0,1,0,4,0,100,0,0,0,0,0,28,56422,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Depths Ambusher - remove submerge');

-- ocular
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33555200 WHERE `entry`=29790;
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|8, `unit_flags`=`unit_flags`|4, `InhabitType`=7 WHERE `entry` IN (29747,29790);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29747;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29747 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(29747,0,0,0,0,0,100,0,1500,1500,4000,4000,11,55269,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ocular - cast Deathly Stare every 3 secs'),
 -- (29747,0,1,0,6,0,100,0,0,0,0,0,11,55288,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ocular - cast It''s All Fun and Games: The Ocular On Death'),
(29747,0,1,0,6,0,100,0,0,0,0,0,33,29803,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ocular - cast It''s All Fun and Games: The Ocular On Death'), -- temporary hack
(29747,0,2,0,25,0,100,0,0,0,0,0,75,55162,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Ocular - cast Transform on Spawn');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=55288;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(55288,55289,0, 'Ocular on script cast killcredit');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=55288;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, Comment) VALUES 
(17,0,55288,0,18,1,0,0,0, 'It''s All Fun and Games: The Ocular On Death');

-- shadow vault auras
DELETE FROM `spell_area` WHERE `spell`=30181 AND `area`=4477;
INSERT INTO `spell_area` VALUES 
(30181,4477,0,0,12896,0,1101,2,1),
(30181,4477,0,0,12897,0,690,2,1);

-- quests
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (12897,12896);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ScriptName`, `Comment`) VALUES 
(19,0,12897,0,8,12893,0,0,'', 'If he cannot be turned - horde'),
(19,0,12896,0,8,12893,0,0,'', 'If he cannot be turned - alliance');

-- temp fix
SET @VILE := 29769;
SET @LADY := 29770;
SET @LEAPER := 29840;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VILE,@LADY,@LEAPER) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@VILE,0,0,0,6,0,100,0,0,0,0,0,33,29845,0,0,0,0,0,7,0,0,0,0,0,0,0,'The Vile - On spell hit - Give kill credit'),
(@LADY,0,0,0,6,0,100,0,0,0,0,0,33,29846,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lady Nightswood - On spell hit - Give kill credit'),
(@LEAPER,0,0,0,6,0,100,0,0,0,0,0,33,29847,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Leaper - On spell hit - Give kill credit');

-- vereth quests
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (13146,13147,13160,13161,13162,13163,13164);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ScriptName`, `Comment`) VALUES 
(19,0,13146,0,8,13145,0,0,'', 'Generosity Abounds'),
(19,0,13160,0,8,13145,0,0,'', 'Stunning View'),
(19,0,13147,0,8,13145,0,0,'', 'Matchmaker'),
(19,0,13161,0,8,13146,0,0,'', 'The Rider of the Unholy'),
(19,0,13161,0,8,13147,0,0,'', 'The Rider of the Unholy'),
(19,0,13161,0,8,13160,0,0,'', 'The Rider of the Unholy'),
(19,0,13162,0,8,13146,0,0,'', 'The Rider of Frost'),
(19,0,13162,0,8,13147,0,0,'', 'The Rider of Frost'),
(19,0,13162,0,8,13160,0,0,'', 'The Rider of Frost'),
(19,0,13163,0,8,13146,0,0,'', 'The Rider of Blood'),
(19,0,13163,0,8,13147,0,0,'', 'The Rider of Blood'),
(19,0,13163,0,8,13160,0,0,'', 'The Rider of Blood'),
(19,0,13164,0,8,13161,0,0,'', 'The Fate of Bloodbane'),
(19,0,13164,0,8,13162,0,0,'', 'The Fate of Bloodbane'),
(19,0,13164,0,8,13163,0,0,'', 'The Fate of Bloodbane');

UPDATE `gameobject` SET `phasemask`=3 WHERE `guid`=62035;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29769;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29717;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29738;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29722;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29840;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29770;

-- lightbane from sniffs
DELETE FROM `event_scripts` WHERE `id`=19423;
INSERT INTO `event_scripts` VALUES
(19423,3,10,29851,300000,0,8593.944,2618.039,652.3534,3.174454);
