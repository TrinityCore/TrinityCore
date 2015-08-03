DELETE FROM `npc_text` WHERE `ID` IN (14121,14122,17713) AND `WDBVerified`=-1;
INSERT INTO `npc_text` (`ID`,`text0_0`,`WDBVerified`) VALUES -- needs dataz
(14121, '<Placeholder>', -1),
(14122, '<Placeholder>', -1),
(17713, '<Placeholder>', -1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=342 AND `SourceEntry`=1;
