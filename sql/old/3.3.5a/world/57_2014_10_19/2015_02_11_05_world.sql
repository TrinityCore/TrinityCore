DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=10016 AND `SourceEntry`=46004;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10, 10016, 46004, 0, 0, 8, 0, 13845, 0, 0, 1, 0, 0, '', 'Sealed vial of poison only drops if player is not rewarded for quest sealed vial of poison');
UPDATE `gossip_menu_option` SET `npc_option_npcflag`=1 WHERE  `menu_id`=9546 AND `id`=1;
