-- Gossips
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=55054 AND `MenuID`=14988);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(55054, 14988, 57212); -- General Nazgrim

DELETE FROM `gossip_menu` WHERE (`MenuID`=14988 AND `TextID`=21186);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14988, 21186, 57212); -- 55054 (General Nazgrim)

UPDATE `creature_template_gossip` SET `VerifiedBuild`=56819 WHERE (`CreatureID`=3310 AND `MenuID`=4342) OR (`CreatureID`=39605 AND `MenuID`=12594);

UPDATE `gossip_menu` SET `VerifiedBuild`=56819 WHERE (`MenuID`=4342 AND `TextID`=5516) OR (`MenuID`=12594 AND `TextID`=17713);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=4342 AND `OptionID`=7);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4342, 30402, 7, 0, 'I need a flight to Hellscream''s Fist.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56819);

UPDATE `gossip_menu_option` SET `GossipOptionID`=30395, `VerifiedBuild`=56819 WHERE (`MenuID`=4342 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4342 AND `SourceEntry`=7;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,4342,7,0,0,47,0,31853,10,0,'',0,0,0,'','Show gossip option if quest 31853 is taken | complete');

-- Quests
DELETE FROM `quest_template_addon` WHERE `ID`=29690;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29690, 0, 0, 0, 31853, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `quest_poi` SET `VerifiedBuild`=56819 WHERE (`QuestID`=31853 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=31853 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=31853 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=31853 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=56819 WHERE (`QuestID`=31853 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=31853 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31853 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31853 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=56819 WHERE `ID`=31853;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=57388 WHERE `ID`=31853;

DELETE FROM `creature_queststarter` WHERE (`id`=55054 AND `quest`=31853);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(55054, 31853, 57212); -- All Aboard! offered by General Nazgrim

UPDATE `creature_queststarter` SET `VerifiedBuild`=56819 WHERE (`id`=54870 AND `quest`=31853);

UPDATE `creature_questender` SET `VerifiedBuild`=56819 WHERE (`id`=55054 AND `quest`=31853);

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (3310,170866);

SET @ENTRY := 67038;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
SET @ACTIONLIST := 67038 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=67038 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` BETWEEN @ACTIONLIST+0 AND @ACTIONLIST+5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(67038,0,0,0,'',40,0,100,0,7,@PATH+0,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 7 reached - Call timed actionlist 1'),
(67038,0,1,0,'',40,0,100,0,15,@PATH+0,0,0,0,'',80,@ACTIONLIST+1,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 15 reached - Call timed actionlist 2'),
(67038,0,2,0,'',40,0,100,0,8,@PATH+1,0,0,0,'',80,@ACTIONLIST+2,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 8 reached - Call timed actionlist 3'),
(67038,0,3,0,'',40,0,100,0,19,@PATH+1,0,0,0,'',80,@ACTIONLIST+3,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 19 reached - Call timed actionlist 4'),
(67038,0,4,0,'',1,0,100,0,0,30000,60000,90000,0,'',80,@ACTIONLIST+4,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - Out of combat (60-90s) - Call timed actionlist 5'),
(67038,0,5,0,'',1,0,100,0,0,3000,6000,9000,0,'',10,5,14,15,25,274,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - Out of combat (6-9s) - Play random emote'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,2000,2000,0,0,0,'',17,133,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,40000,40000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+1,9,0,0,'',0,0,100,0,0,0,0,0,0,'',17,233,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+1,9,1,0,'',0,0,100,0,35000,35000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+2,9,0,0,'',0,0,100,0,250,250,0,0,0,'',17,69,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+2,9,1,0,'',0,0,100,0,40000,40000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+3,9,0,0,'',0,0,100,0,250,250,0,0,0,'',17,233,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+3,9,1,0,'',0,0,100,0,40850,40850,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+4,9,0,0,'',0,0,100,0,0,0,0,0,0,'',5,381,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Play emote'),
(@ACTIONLIST+4,9,1,0,'',0,0,100,0,0,0,0,0,0,'',11,79367,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Cast ''Holding a Cannonball'''),
(@ACTIONLIST+4,9,2,0,'',0,0,100,0x20,0,0,0,0,0,'',53,0,@PATH+2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Start scripted path 1'),
(@ACTIONLIST+4,9,3,0,'',0,0,100,0,2500,2500,0,0,0,'',5,61,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Play emote'),
(@ACTIONLIST+4,9,4,0,'',0,0,100,0,0,0,0,0,0,'',28,79367,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove aura ''Holding a Cannonball'''),
(@ACTIONLIST+4,9,5,0,'',0,0,100,0,1200,1200,0,0,0,'',53,0,@PATH+3,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Start scripted path 2'),
(@ACTIONLIST+4,9,6,0,'',0,0,100,0,0,0,0,0,0,'',1,0,0,1,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Talk');

DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH+2, @PATH+3);
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH+2, 0, 1867.2361, -5490.635, 445.39252, NULL, 0), -- Spline
(@PATH+2, 1, 1863.7361, -5492.885, 445.14252, NULL, 0), -- Spline
(@PATH+2, 2, 1861.4861, -5493.885, 444.89252, NULL, 0), -- Spline
(@PATH+2, 3, 1861.0139, -5493.3647, 444.78436, NULL, 0),
(@PATH+3, 0, 1863.7361, -5492.885, 445.14252, NULL, 0), -- Spline
(@PATH+3, 1, 1866.9861, -5490.635, 445.39252, NULL, 0), -- Spline
(@PATH+3, 2, 1866.4584, -5487.905, 444.50064, NULL, 150),
(@PATH+3, 3, 1866.4584, -5487.905, 444.50064, 3.777480840682983398, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=67038;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,5,67038,0,0,58,1,0,0,0,'LoadCannon',0,0,0,'','Trigger smart event if object has StringId ''LoadCannon'''),
(22,6,67038,0,0,58,1,0,0,0,'RandomEmote',0,0,0,'','Trigger smart event if object has StringId ''RandomEmote''');

UPDATE `conditions` SET `Comment`='Areatrigger 8190 triggers if player is Horde' WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8463 AND `ConditionTypeOrReference`=6;
UPDATE `conditions` SET `Comment`='Areatrigger 99 triggers if condition reference 40001 is fulfilled' WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=99 AND `SourceEntry`=1 AND `ConditionTypeOrReference`=-40001;
UPDATE `conditions` SET `Comment`='Areatrigger 99 triggers if player is Horde' WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=99 AND `SourceEntry`=1 AND `ConditionTypeOrReference`=6;

DELETE FROM `smart_scripts` WHERE `entryorguid`=55054 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55054,0,2,0,'',64,0,100,0,0,0,0,0,0,'',153,0,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - On gossip hello - Credit quest objective TalkTo');

DELETE FROM `smart_scripts` WHERE `entryorguid`=3310 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3310,0,0,1,'',62,0,100,0,4342,7,0,0,0,'',134,333254,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Doras - On gossip option 7 selected - Invoker casts ''Summon Wind Rider'''),
(3310,0,1,0,'',61,0,100,0,0,0,0,0,0,'',72,0,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Doras - Event linked - Close gossip');

UPDATE `smart_scripts` SET `action_param2`=0x2, `action_param3`=(0x20 | 0x40000) WHERE `entryorguid`=8463 AND `source_type`=2 AND `id`=0;

SET @ENTRY := 170866;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `smart_scripts` WHERE `entryorguid`=170866 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(170866,0,0,0,'',54,0,100,0x200,0,0,0,0,0,'',11,333258,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Orgrimmar Wind Rider - On summon - Cast ''Dust Cloud'''),
(170866,0,1,0,'',27,0,100,0x200,0,0,0,0,0,'',53,0,@PATH,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Orgrimmar Wind Rider - On passenger boarded - Start scripted path'),
(170866,0,2,3,'',58,0,100,0x200,0xFFFFFFFF,@PATH,0,0,0,'',28,46598,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Orgrimmar Wind Rider - On scripted path ended - Remove aura ''Ride Vehicle Hardcoded'''),
(170866,0,3,0,'',61,0,100,0x200,0,0,0,0,0,'',114,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,40,0,0,'Orgrimmar Wind Rider - Event linked - Move forward 40 yards');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, 160, 'Orgrimmar Wind Rider - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1769.4827, -4363.278, 108.83427, NULL, 0),
(@PATH, 1, 1701.9723, -4366.712, 113.84267, NULL, 0),
(@PATH, 2, 1669.1493, -4412.5884, 126.84298, NULL, 0),
(@PATH, 3, 1656.7709, -4467.049, 136.71732, NULL, 0),
(@PATH, 4, 1696.1354, -4536.443, 146.4351, NULL, 0),
(@PATH, 5, 1803.6805, -4625.4116, 195.52322, NULL, 0),
(@PATH, 6, 1847.7274, -4778.778, 282.32523, NULL, 0),
(@PATH, 7, 1888.3091, -4893.5835, 314.58096, NULL, 0),
(@PATH, 8, 2056.6338, -5047.3247, 366.49112, NULL, 0),
(@PATH, 9, 2240.4463, -5647.0054, 559.2592, NULL, 0),
(@PATH, 10, 1847.9, -5595.1, 460.4, NULL, 0),
(@PATH, 11, 1840.5, -5496.8, 452.4, NULL, 0),
(@PATH, 12, 1851.7, -5462.5, 446.2, NULL, 0);

DELETE FROM `vehicle_template` WHERE `creatureId`=170866;
INSERT INTO `vehicle_template` (`creatureId`, `despawnDelayMs`) VALUES
(170866, 800);
