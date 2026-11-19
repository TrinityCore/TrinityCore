SET @NPCTEXTID := 590080;

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=72408;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(72408, 0, 0, 0, 0, 0, 0, 0, 0, 'We all have our own versions of the past, don\'t we? \n\nI don\'t care if some dragon lady had a magic amulet. It wasn\'t complete mind control. \n\nThe nobles already hated the common people. The Stonemason\'s Guild would never have needed to turn to banditry and become the Defias Brotherhood, if not for them.', 49801); -- A Window to the Past

UPDATE `quest_poi` SET `VerifiedBuild`=49801 WHERE (`QuestID`=72408 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=72408 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=72408 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50605 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=70197 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50599 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42422 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=49801 WHERE (`QuestID`=72408 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=72408 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=72408 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50605 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=70197 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50601 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50599 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42422 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_request_items` WHERE `ID`=72408;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72408, 0, 0, 0, 0, '<Vanessa sizes you up.>', 49801); -- A Window to the Past

DELETE FROM `creature_queststarter` WHERE (`id`=198883 AND `quest`=72409);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(198883, 72409, 49801); -- Rotten Old Memories offered Vanessa VanCleef

DELETE FROM `creature_questender` WHERE (`id`=198883 AND `quest`=72408);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(198883, 72408, 49801); -- A Window to the Past ended by Vanessa VanCleef

DELETE FROM `quest_details` WHERE `ID`=72409;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72409, 1, 1, 0, 0, 0, 0, 0, 0, 49801); -- Rotten Old Memories

DELETE FROM `quest_template_addon` WHERE `ID` = 72409;
INSERT INTO `quest_template_addon` (`ID`, `prevQuestID`) VALUES
(72409, 72408);

-- Gossip & Text
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+11;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 236757, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198883 (Vanessa VanCleef)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 236744, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198883 (Vanessa VanCleef)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 236761, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198883 (Vanessa VanCleef)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 236763, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198883 (Vanessa VanCleef)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 236144, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 236142, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 236140, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 236737, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+8, 1, 0, 0, 0, 0, 0, 0, 0, 236733, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+9, 1, 0, 0, 0, 0, 0, 0, 0, 236731, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+10, 1, 0, 0, 0, 0, 0, 0, 0, 236729, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198896 (Master Mathias Shaw)
(@NPCTEXTID+11, 1, 0, 0, 0, 0, 0, 0, 0, 236727, 0, 0, 0, 0, 0, 0, 0, 49801); -- 198896 (Master Mathias Shaw)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30834 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30835 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=30836 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=30838 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=30826 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=30827 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=30828 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=30829 AND `TextID`=@NPCTEXTID+7) OR (`MenuID`=30830 AND `TextID`=@NPCTEXTID+8) OR (`MenuID`=30831 AND `TextID`=@NPCTEXTID+9) OR (`MenuID`=30832 AND `TextID`=@NPCTEXTID+10) OR (`MenuID`=30833 AND `TextID`=@NPCTEXTID+11);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30834, @NPCTEXTID+0, 49801), -- 198883 (Vanessa VanCleef)
(30835, @NPCTEXTID+1, 49801), -- 198883 (Vanessa VanCleef)
(30836, @NPCTEXTID+2, 49801), -- 198883 (Vanessa VanCleef)
(30838, @NPCTEXTID+3, 49801), -- 198883 (Vanessa VanCleef)
(30826, @NPCTEXTID+4, 49801), -- 198896 (Master Mathias Shaw)
(30827, @NPCTEXTID+5, 49801), -- 198896 (Master Mathias Shaw)
(30828, @NPCTEXTID+6, 49801), -- 198896 (Master Mathias Shaw)
(30829, @NPCTEXTID+7, 49801), -- 198896 (Master Mathias Shaw)
(30830, @NPCTEXTID+8, 49801), -- 198896 (Master Mathias Shaw)
(30831, @NPCTEXTID+9, 49801), -- 198896 (Master Mathias Shaw)
(30832, @NPCTEXTID+10, 49801), -- 198896 (Master Mathias Shaw)
(30833, @NPCTEXTID+11, 49801); -- 198896 (Master Mathias Shaw)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (30834,30835,30837,30836,30838)) OR (`OptionID`=2 AND `MenuID` IN (30837,30224)) OR (`OptionID`=1 AND `MenuID`=30837) OR (`OptionID`=0 AND `MenuID` IN (30832,30826,30833,30831,30830,30827,30829,30828)) OR (`OptionID`=4 AND `MenuID`=30224) OR (`OptionID`=6 AND `MenuID`=30224) OR (`OptionID`=5 AND `MenuID`=30224);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(108532, 30834, 0, 0, '<Ask about something else.>', 0, 0, 30837, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108531, 30837, 2, 0, '<Ask for more information about the Defias Brotherhood.>', 0, 0, 30838, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108527, 30835, 0, 0, '<Ask about her time fighting the Legion.>', 0, 0, 30834, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108528, 30837, 0, 0, '<Ask for more information about her.>', 0, 0, 30835, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107715, 30224, 2, 0, '<Tell Shaw you are ready to hear about the history of the Drakefire Amulet.>', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108534, 30836, 0, 0, '<Ask about something else.>', 0, 0, 30837, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108529, 30837, 1, 0, '<Ask for more information about Shaw.>', 0, 0, 30836, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108533, 30838, 0, 0, '<Ask about something else.>', 0, 0, 30837, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108523, 30832, 0, 0, '<Ask if Shaw knew Edwin VanCleef.>', 0, 0, 30831, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108538, 30826, 0, 0, '<Ask about something else.>', 0, 0, 30224, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108524, 30833, 0, 0, '<Continue.>', 0, 0, 30832, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108537, 30831, 0, 0, '<Ask about something else.>', 0, 0, 30224, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108521, 30830, 0, 0, '<Continue.>', 0, 0, 30829, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108520, 30224, 4, 0, '<Ask for more information about the Defias Brotherhood.>', 0, 0, 30828, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108522, 30224, 6, 0, '<Ask for more information about the Drakefire Amulet.>', 0, 0, 30830, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108518, 30827, 0, 0, '<Ask Shaw how he feels about the Defias Brotherhood.>', 0, 0, 30826, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108525, 30224, 5, 0, '<Ask for more information about Vanessa VanCleef.>', 0, 0, 30833, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108536, 30829, 0, 0, '<Ask about something else.>', 0, 0, 30224, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108519, 30828, 0, 0, '<Continue.>', 0, 0, 30827, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 30224 AND `SourceEntry` IN (2,4,5,6));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 30224, 2, 0, 0, 9, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30224 2 if Quest 72405 is taken'),
(15, 30224, 4, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30224 4 if Quest 72405 is rewarded'),
(15, 30224, 5, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30224 5 if Quest 72405 is rewarded'),
(15, 30224, 6, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30224 6 if Quest 72405 is rewarded');

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3126;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3126, 16, 3860, 0);

-- Master Mathias Shaw smart ai
SET @ENTRY := 198896;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 30224, 2, 0, 0, 85, 402962, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action <Tell Shaw you are ready ... (2) from menu 30224 selected - Gossip player: Cast spell 402962 with flags interrupt previous, triggered on self'),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 30224, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action <Tell Shaw you are ready ... (2) from menu 30224 selected - Gossip player: Close gossip');

-- Scene 3126
SET @ENTRY := 3126;
UPDATE `scene_template` SET `ScriptName` = 'SmartScene' WHERE `SceneId` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 10 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 10, 0, 0, 81, 0, 100, 0, 0, 0, 0, 0, 85, 402961, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Scene Complete - Self: Cast spell 402961 with flags triggered on self'),
(@ENTRY, 10, 1, 0, 80, 0, 100, 0, 0, 0, 0, 0, 85, 402961, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Scene Cancel - Self: Cast spell 402962 with flags triggered on self');
