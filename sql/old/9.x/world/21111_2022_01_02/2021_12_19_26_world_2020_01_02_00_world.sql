-- 
DELETE FROM `gossip_menu_option` WHERE `MenuId`=5181 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(5181, 0, 1, 'Let me browse your seasonal fare.', 8786, 41488);

DELETE FROM `creature_template_addon` WHERE `entry`=13436;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(13436, 0, 0, 0, 257, 0, 0, 0, 0, ''); -- 13436 (Guchie Jinglepocket)

DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry`=13436;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(13436, 0, 0, 0, 417, 41488);
