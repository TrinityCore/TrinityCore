-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=17101 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17215 AND `source_type`=0 AND `id` IN (2, 3, 4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17214 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17242 AND `source_type`=0 AND `id` IN (1, 2, 3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17117 AND `source_type`=0 AND `id` IN (2, 3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17241 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17101, 0, 2, 0, 20, 0, 100, 0, 9452, 0, 0, 0, 5, 24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Diktynna - On Quest 'Red Snapper - Very Tasty!' Rewarded - Play Emote 24"),
(17215, 0, 2, 0, 38, 0, 100, 512, 1, 1, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Daedal - On Data Set 1 1- Set NPC Flags"),
(17215, 0, 3, 0, 38, 0, 100, 512, 2, 2, 0, 0, 81, 83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Daedal - On Data Set 2 2- Set NPC Flags"),
(17215, 0, 4, 0, 20, 0, 100, 512, 9473, 2, 0, 0, 80, 1721500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Daedal - On Quest 'An Alternative Alternative' Rewarded - Run Script"),
(17214, 0, 1, 0, 20, 0, 100, 512, 9463, 2, 0, 0, 80, 1721400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anchorite Fateema - On Quest 'Medicinal Purposes' Rewarded - Run Script"),
(17242, 0, 1, 0, 38, 0, 100, 512, 1, 1, 0, 0, 53, 0, 1724200, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Adamant Ironheart - On Data Set 1 1- Start WP (Path 1)"),
(17242, 0, 2, 0, 38, 0, 100, 512, 2, 2, 0, 0, 53, 0, 1724201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Adamant Ironheart - On Data Set 2 2- Start WP (Path 2)"),
(17242, 0, 3, 0, 40, 0, 100, 512, 1, 1724201, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.26573, "Archaeologist Adamant Ironheart - On Reached WP1 (Path 2) - Set Orientation"),
(17117, 0, 2, 0, 38, 0, 100, 512, 1, 1, 0, 0, 91, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Injured Night Elf Priestess - On Data Set 1 1 - Set Bytes 1"),
(17117, 0, 3, 0, 38, 0, 100, 512, 2, 2, 0, 0, 90, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Injured Night Elf Priestess - On Data Set 2 2 - Set Bytes 1"),
(17241, 0, 1, 0, 20, 0, 100, 512, 9514, 0, 0, 0, 80, 1724100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Priestess Kyleen Il'dinare - On Quest 'Rune Covered Tablet' Rewarded - Run Script");
