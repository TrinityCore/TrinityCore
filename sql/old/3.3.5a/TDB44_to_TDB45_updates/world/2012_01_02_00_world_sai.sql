-- [Q] Plan B (11658)
SET @ENTRY_GUARD := 25342; -- Dead Caravan Guard
SET @ENTRY_WORKER := 25343; -- Dead Caravan Worker
SET @ITEM := 34842; -- Warsong Outfit
SET @GOSSIP_1 := 9155;
SET @GOSSIP_2 := 9156;
SET @QUEST := 11658; -- Plan B

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP_1;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP_2;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(@GOSSIP_1, 12388),
(@GOSSIP_2, 12389);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_1;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_2;
INSERT INTO `gossip_menu_option` VALUES
(@GOSSIP_1, 0, 0, 'Retrieve Warsong Outfit.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP_2, 0, 0, 'Retrieve Warsong Outfit.', 1, 1, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (@ENTRY_GUARD, @ENTRY_WORKER);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=25342 AND `id`=2534201;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=25343 AND `id`=2534301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_GUARD, @ENTRY_WORKER);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY_GUARD AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY_WORKER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
(@ENTRY_GUARD, 0, 0, 1, 62, 0, 100, 0, @GOSSIP_1, 0, 0, 0, 56, @ITEM, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Guard - On Gossip Select - Add Item Warsong Outfit'),
(@ENTRY_GUARD, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Guard - On Gossip Select - Forced Despawn'),
(@ENTRY_WORKER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP_2, 0, 0, 0, 56, @ITEM, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Worker - On Gossip Select - Add Item Warsong Outfit'),
(@ENTRY_WORKER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Worker - On Gossip Select - Forced Despawn');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP_1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP_2;
INSERT INTO `conditions` VALUES
(15, @GOSSIP_1, 0, 0, 9, @QUEST, 0, 0, 0, '', 'Only show gossip if player has quest Plan B'),
(15, @GOSSIP_2, 0, 0, 9, @QUEST, 0, 0, 0, '', 'Only show gossip if player has quest Plan B'),
(15, @GOSSIP_1, 0, 0, 2, @ITEM, 10, 0, 0, '', 'Only show gossip if player has less then 10 outfits'),
(15, @GOSSIP_2, 0, 0, 2, @ITEM, 10, 0, 0, '', 'Only show gossip if player has less then 10 outfits');
