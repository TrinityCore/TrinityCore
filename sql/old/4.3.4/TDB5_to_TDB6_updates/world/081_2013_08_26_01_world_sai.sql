-- Ribbly Screwspigot 9543
SET @GOSSIP			:= 1970;
SET @RIBBLY			:= 9543;
SET @CRONY			:= 10043;

DELETE FROM `creature_equip_template` WHERE `entry` =@RIBBLY;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(@RIBBLY, 5280, 0, 0); -- Ribbly Screwspigot

DELETE FROM `creature_template_addon` WHERE `entry` =@RIBBLY;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@RIBBLY, 0, 0x0, 0x1, ''); -- Ribbly Screwspigot

DELETE FROM `gossip_menu` WHERE `entry` =@GOSSIP;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(@GOSSIP, 2643);

DELETE FROM `gossip_menu_option` WHERE `menu_id` =@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP,0,0, 'You''re good for nothing, Ribbly. It''s time to pay for your wickedness!.', 1, 1, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`gossip_menu_id`=@GOSSIP ,`npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=@RIBBLY;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@RIBBLY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@RIBBLY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 735, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - On Reset - Set Default Faction'),
(@RIBBLY, 0, 1, 2, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - On Gossip Select - Close Menu'),
(@RIBBLY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 2, 736, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - Linked with Previous Event - Set Hostile'),
(@RIBBLY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 5000, 0, 0, 0, 11, @CRONY, 10, 100, 0, 0, 0, 0, 'Ribbly Screwspigot - Linked with Previous Event - Send Data 1 1 to Ribblys Cronies'),
(@RIBBLY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - Linked with Previous Event - Attack Invoker'),
(@RIBBLY, 0, 5, 0, 4 , 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - On Aggro - Say line 0'),
(@RIBBLY, 0, 6, 0, 0 , 0, 100, 0, 4000, 12000, 4000, 12000, 11, 12540, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - IC - Cast Gouge'),
(@RIBBLY, 0, 7, 0, 0 , 0, 100, 0, 5000, 14000, 5000, 14000, 11, 9080 , 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Ribbly Screwspigot - IC - Cast Hamstring');

DELETE FROM `creature_text` WHERE `entry` =@RIBBLY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@RIBBLY, 0, 0, 'No! Get away from me! Help!', 12, 0, 100, 0, 0, 0, 'Ribbly Screwspigot');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`unit_flags`=576 WHERE `entry`= @CRONY;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@CRONY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@CRONY, 0, 0, 0, 25,  0, 100, 0, 0, 0, 0, 0, 2, 735, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - On Reset - Set Default Faction'),
(@CRONY, 0, 1, 2, 38,  0, 100, 0, 1, 1, 0, 0, 2, 736, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - On Data Set 1 1 - Set Hostile'),
(@CRONY, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - Linked with Previous Event - Attack'),
(@CRONY, 0, 3, 0, 0,  0, 100, 0, 5000, 14000, 5000, 14000, 11, 15692, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - IC - Cast Eviscerate'),
(@CRONY, 0, 4, 0, 0,  0, 100, 0, 2000, 11000, 2000, 11000, 11, 15581, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - IC - Cast Sinister Strike'),
(@CRONY, 0, 5, 0, 0,  0, 100, 0, 8000, 18000, 8000, 18000, 11, 13298, 0, 0, 0, 0, 0, 2, 32, 0, 0, 0, 0, 0, 0, 'Ribblys Crony - IC - Cast Poison');
