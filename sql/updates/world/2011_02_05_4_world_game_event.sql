-- Update Quest_conditions for Quest: The Lunar Festival
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`IN(8870,8871,8872,8873,8874,8875);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
-- Alliance
(19,0,8871,0,4,1519,0,0,0,0,'The Lunar Festival: Stormwind'),
(19,0,8872,0,4,1657,0,0,0,0,'The Lunar Festival: Darnassus'),
(19,0,8870,0,4,1537,0,0,0,0,'The Lunar Festival: Ironforge'),
-- Horde
(19,0,8873,0,4,1637,0,0,0,0,'The Lunar Festival: Orgrimmar'),
(19,0,8874,0,4,1497,0,0,0,0,'The Lunar Festival: Undercity'),
(19,0,8875,0,4,1638,0,0,0,0,'The Lunar Festival: Thunder Bluff');
-- Quest: Lunar Fireworks
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (15872,15873,15874,15879,15880,15882);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (15872,15873,15874,15879,15880,15882); -- Cleanup
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15872,15873,15874,15879,15880,15882);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- small fireworks
-- blue firework
(15879,0,0,0,1,0,100,1,0,0,0,0,11,26344,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks'),
-- green firework
(15880,0,0,0,1,0,100,1,0,0,0,0,11,26345,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks'),
-- red firework
(15882,0,0,0,1,0,100,1,0,0,0,0,11,26347,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks'),
-- big fireworks
-- blue firework
(15872,0,0,0,1,0,100,1,0,0,0,0,11,26344,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks'),
-- red firework
(15873,0,0,0,1,0,100,1,0,0,0,0,11,26347,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks'),
-- green firework
(15874,0,0,0,1,0,100,1,0,0,0,0,11,26345,2,0,0,0,0,1,0,0,0,0,0,0,0, 'cast fireworks');
-- remove useless quests: (as of patch 3.0 they where removed)
DELETE FROM `creature_questrelation` WHERE `quest` IN (8876,8877,8878,8879,8880,8881,8882,8862,8863,8864,8865);

-- Elune's Blessing
DELETE FROM `gameobject_template` WHERE `entry` IN (180876,180877);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`data6`,`data7`,`data8`,`data9`,`data10`,`data11`,`data12`,`data13`,`data14`,`data15`,`data16`,`data17`,`data18`,`data19`,`data20`,`data21`,`data22`,`data23`,`AIName`,`ScriptName`,`WDBVerified`) VALUES
(180876,6,327, 'Elune''s Blessing TRAP BUFF', '', '', '',14,0,0.01,0,0,0,0,0,0,0,255,8,26393,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,'','',1),
(180877,6,327, 'Elune''s Blessing TRAP QUESTCREDIT', '', '', '',14,0,0.01,0,0,0,0,0,0,0,255,8,26394,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,'','',1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=26393;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,26393,0,18,1,0,0,0, '', 'Elune''s Blessing')
