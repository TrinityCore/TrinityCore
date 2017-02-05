-- 
SET @ENTRY := 5781;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=`InhabitType`|8 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3251 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5781, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 578100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Just summoned - Action list"),
(578100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Action list - Say text emote"),
(578100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Action list - Say text emote"),
(578100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Action list - Say text emote"),
(578100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 6588, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Action list - Cast 'Summon Silithid Grub'"),
(578100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silithid Creeper Egg - Action list - Cast 'Suicide'"),
(3251, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, "Silithid Grub - Just summoned - Start attack");

DELETE FROM `creature_text` WHERE `entry` IN (5781, 3250);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(3250, 0, 0, "%s lays an egg!", 16, 0, 100, 0, 0, 0, 1408, 'Silithid Creeper'),
(5781, 0, 0, "%s begins to crack and open...", 16, 0, 100, 0, 0, 0, 1409, 'Silithid Creeper Egg'),
(5781, 1, 0, "%s splits open!", 16, 0, 100, 0, 0, 0, 1410, 'Silithid Creeper Egg');
