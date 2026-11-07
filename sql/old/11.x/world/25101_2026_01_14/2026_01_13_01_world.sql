-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3017;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3017, 27, 3511, 0);

-- Quest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=65299 WHERE `ID` IN (66577, 65436);
UPDATE `quest_details` SET `VerifiedBuild`=65299 WHERE `ID`=66577;
UPDATE `quest_request_items` SET `VerifiedBuild`=65299 WHERE `ID`=66577;

-- Template
UPDATE `creature_template_gossip` SET `VerifiedBuild`=64978 WHERE (`CreatureID`=189569 AND `MenuID`=28666);

-- Gossip
UPDATE `gossip_menu` SET `VerifiedBuild`=64978 WHERE (`MenuID`=28666 AND `TextID`=590013);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=64978 WHERE (`MenuID`=28666 AND `OptionID`=1);

 -- Wrathion smart ai
SET @ENTRY := 189569;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `id` IN (0, 1, 2, 3) AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 64, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player opened gossip - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player opened gossip - Gossip player: Complete Meet Wrathion in Stormwind objective (189569)', ''),
(@ENTRY, 0, 2, 3, 62, 0, 100, 0, 28666, 1, 0, 0, 0, 85, 373796, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 28666 selected - Gossip player: Cast spell 373796 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 28666 selected - Gossip player: Close gossip', '');
