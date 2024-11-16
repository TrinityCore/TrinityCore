UPDATE `npc_text` SET `ID`= 16570 WHERE `ID`= 530008;
UPDATE `gossip_menu` SET `TextID`= 16570 WHERE `TextID`= 530008;
UPDATE `conditions`  SET `SourceEntry`= 16570 WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 11817 AND `SourceEntry`= 530008;
