SET @Gossip = 21289;
SET @NElf = 31111;

DELETE FROM `gossip_menu` WHERE `entry`=@Gossip AND `text_id` IN (15037,15038);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(@Gossip, 15037),
(@Gossip, 15038);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@Gossip AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES
(@Gossip, 0, 0, 'I believe in you.', 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@Gossip;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, @Gossip, 15038, 0, 1, 58493, 0, 0, 0, '', 'Mohawk Grenade - aura'),
(14, @Gossip, 15037, 0, 11, 58493, 0, 0, 0, '', 'Mohawk Grenade - no aura'),
(15, @Gossip, 0, 0, 26, 43489, 1, 0, 0, '', 'Mohawk Grenade - no item');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NElf;
UPDATE `creature_template` SET `gossip_menu_id`=@Gossip,`minlevel`=80,`maxlevel`=80,`npcflag`=`npcflag`|1 WHERE `entry`=31111;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NElf AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@NElf, 0, 0, 1, 62, 0, 100, 0, @Gossip, 0, 0, 0, 11, 69243, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Night Elf Mohawk - On gossip select cast Create Mohawk Grenade'),
(@NElf, 0, 1, 0, 61, 0, 100, 0, @Gossip, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Night Elf Mohawk - Link - close gossip');

DELETE FROM `creature_template_addon` WHERE `entry`=36778;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36778, 0, 0, 3, 1, 0, NULL); -- sleep
