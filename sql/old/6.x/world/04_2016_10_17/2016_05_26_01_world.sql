SET @ENTRY_PRINCE_LIAM_GREYMANE                 := 34850;
SET @GOSSIP_MENU_ENTRY_PRINCE_LIAM_GREYMANE     := 10669;
SET @TEXT_ID_PRINCE_LIAM_GREYMANE               := 14786;
SET @BROADCAST_TEXT_ID_PRINCE_LIAM_GREYMANE     := 35946;

-- Prince Liam Greymane (mount)
UPDATE `creature_template_addon` SET `mount` = 2410 WHERE `entry` = @ENTRY_PRINCE_LIAM_GREYMANE;

-- Prince Liam Greymane (says)
DELETE FROM `creature_text` WHERE `entry` = @ENTRY_PRINCE_LIAM_GREYMANE;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY_PRINCE_LIAM_GREYMANE,0,0,'Stand ready, guards!  We don\'t know how many intruders we\'re dealing with, but the Headlands are overrun and we\'re cut off from the harbor towns.  Expect to be outnumbered.',12,0,100,1,0,19614,0,0,'Prince Liam Greymane - Say 0'),
(@ENTRY_PRINCE_LIAM_GREYMANE,1,0,'I want the perimeter secured and the gates manned by two guards at all times.  No one gets in, no one gets out.',12,0,100,1,0,19615,0,0,'Prince Liam Greymane - Say 1'),
(@ENTRY_PRINCE_LIAM_GREYMANE,2,0,'We protected Gilneas from the Scourge.  We protected Gilneas during the Northgate rebellion.  We will protect Gilneas from whatever this new threat may be.',12,0,100,25,0,19616,0,0,'Prince Liam Greymane - Say 2');

-- Prince Liam Greymane (smartAI)
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ENTRY_PRINCE_LIAM_GREYMANE;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @ENTRY_PRINCE_LIAM_GREYMANE);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY_PRINCE_LIAM_GREYMANE, 0, 0, 0, 60, 0, 100, 0, 5000, 5000, 62000, 62000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Liam Greymane - On Update - Say Line 0'),
(@ENTRY_PRINCE_LIAM_GREYMANE, 0, 1, 0, 60, 0, 100, 0, 26000, 26000, 62000, 62000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Liam Greymane - On Update - Say Line 1'),
(@ENTRY_PRINCE_LIAM_GREYMANE, 0, 2, 0, 60, 0, 100, 0, 47000, 47000, 62000, 62000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Liam Greymane - On Update - Say Line 2');

-- Prince Liam Greymane (gossip)
UPDATE `creature_template` SET `gossip_menu_id` = @GOSSIP_MENU_ENTRY_PRINCE_LIAM_GREYMANE 
WHERE `entry` = @ENTRY_PRINCE_LIAM_GREYMANE;

-- Gossip Menu
DELETE FROM gossip_menu WHERE (`entry`=@GOSSIP_MENU_ENTRY_PRINCE_LIAM_GREYMANE AND `text_id`=@TEXT_ID_PRINCE_LIAM_GREYMANE);
INSERT INTO gossip_menu (`entry`, `text_id`) VALUES (@GOSSIP_MENU_ENTRY_PRINCE_LIAM_GREYMANE, @TEXT_ID_PRINCE_LIAM_GREYMANE);

-- NPC Text 
DELETE FROM npc_text WHERE `ID`= @TEXT_ID_PRINCE_LIAM_GREYMANE;
INSERT INTO npc_text (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@TEXT_ID_PRINCE_LIAM_GREYMANE, 1, 0, 0, 0, 0, 0, 0, 0, @BROADCAST_TEXT_ID_PRINCE_LIAM_GREYMANE, 0, 0, 0, 0, 0, 0, 0, 20886);
