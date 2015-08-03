SET @MOVIE := 110112;
SET @CHROMIE := 58195;
SET @GOSSIP1 := 13389;
SET @ITHARIUS := 58199;
SET @GOSSIP2 := 13390;

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id` IN (@GOSSIP1, @GOSSIP2);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@CHROMIE, @ITHARIUS);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CHROMIE, @ITHARIUS) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@CHROMIE, 0, 0, 0, 62, 0, 100, 0, @GOSSIP1, 0, 0, 0, 11, @MOVIE, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Chromie - On gossip select - Start movie'),
(@ITHARIUS, 0, 0, 0, 62, 0, 100, 0, @GOSSIP2, 0, 0, 0, 11, @MOVIE, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lord Itharius - On gossip select - Start movie');
