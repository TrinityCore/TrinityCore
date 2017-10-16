-- Fix gossip text for NPC Geirrvif
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=31135;
DELETE FROM `gossip_menu` WHERE `TextID`=13918 AND `MenuID`=10034;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10034;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 10034, 13921, 0, 0, 8, 0, 13142, 0, 0, 1, 0, 0, "", "Show gossip text 13921 if quest 'Banshee's Revenge' is NOT rewarded"),
(14, 10034, 13922, 0, 0, 8, 0, 13142, 0, 0, 0, 0, 0, "", "Show gossip text 13922 if quest 'Banshee's Revenge' is rewarded AND"),
(14, 10034, 13922, 0, 0, 8, 0, 13219, 0, 0, 1, 0, 0, "", "Show gossip text 13922 if quest 'Battle at Valhalas: Final Challenge' is NOT rewarded"),
(14, 10034, 13946, 0, 0, 8, 0, 13219, 0, 0, 0, 0, 0, "", "Show gossip text 13946 if quest 'Battle at Valhalas: Final Challenge' is rewarded");
