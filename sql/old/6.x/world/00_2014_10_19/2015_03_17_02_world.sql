DELETE FROM `creature_text` WHERE `entry` = 16287 AND `groupid`= 0;
DELETE FROM `creature_text` WHERE `entry` = 10181 AND `groupid` = 2;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16287, 0, 0, 'That could have gone better. $n, come here, please. I have something I need you to take care of for me.', 15, 0, 100, 0, 0, 0, 12157, 0, 'Ambassador Sunsorrow SAY_SUNSORROW_WHISPER'),
(10181, 2, 0, '%s looks down at the discarded necklace. In her sadness, the lady incants a glamour, which beckons forth Highborne spirits. The chamber resonates with their ancient song about the Sin''dorei...', 16, 0, 100, 0, 0, 0, 19197, 0, 'Lady Sylvanas Windrunner EMOTE_LAMENT');
 
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 7178 AND `id`= 0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextId`) VALUES
(7178, 0, 0, 'What is it that you have for me, ambassador?', 19205, 1, 1, 7178, 0, 0, 0, '', 0);
 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16287;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16287 AND `source_type` = 0 AND `id` IN (0, 1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16287,0,0,1,62,0,100,0,7178,0,0,0,11,37084,1,0,0,0,0,7,0,0,0,0,0,0,0,'Ambassador Sunsorrow - On Gossip Option 0 Selected - Create Item \'Lament of the Highborne\''),
(16287,0,1,0,61,0,100,0,0,0,0,0,98,7178,10378,0,0,0,0,7,0,0,0,0,0,0,0,'Ambassador Sunsorrow - On Gossip Option 0 Selected - SEND_GOSSIP_MENU TEXT'),
(16287,0,2,0,64,0,100,0,0,0,0,0,98,7178,8458,0,0,0,0,7,0,0,0,0,0,0,0,'Ambassador Sunsorrow - On Gossip Hello - SEND_GOSSIP_MENU TEXT');
 
DELETE FROM `npc_text` WHERE  `id` IN (10378, 8458);
INSERT INTO `npc_text` (`id`, `text0_0`, `text0_1`, `prob0`, `em0_1`, `BroadcastTextID0`) VALUES
(8458, "Greetings, $r.  I am Ambassador Sunsorrow of the sin'dorei, or blood elves as we are commonly known.  I have high hopes that this new bond between us and the Horde will be mutually beneficial.", "Greetings, $r.  I am Ambassador Sunsorrow of the sin'dorei, or blood elves as we are commonly known.  I have high hopes that this new bond between us and the Horde will be mutually beneficial.", 1, 2, 12161),
(10378, "Just a small songbook that I thought you might like to have.  It contains the lyrics to a song known as the Lament of the Highborne; the one that Lady Sylvanas glamoured from the air.", "", 1, 1, 19206);
 
DELETE FROM `gossip_menu` WHERE `entry`=7178 AND `text_id` IN (10378, 8458, 8740);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7178,10378),
(7178,8740),
(7178,8458);
 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7178 AND `SourceEntry` = 0 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 7178, 0, 0, 0, 8, 0, 9180, 0, 0, 0, 0, 0, '', 'Ambassador Sunsorrow show gossip only if quest Journey to Undercity is rewarded'),
(15, 7178, 0, 0, 0, 16, 0, 512, 0, 0, 0, 0, 0, '', 'Ambassador Sunsorrow show gossip only if player is Blood Elf'),
(15, 7178, 0, 0, 0, 2, 0, 30632, 1, 0, 1, 0, 0, '', 'Ambassador Sunsorrow show gossip only if player doesn\'t have item Lament of Highborn');

UPDATE `creature_text` SET `type` = 12 WHERE `entry` = 10181 AND `groupid` = 1;
