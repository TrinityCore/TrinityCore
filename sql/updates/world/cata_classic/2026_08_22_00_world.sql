DELETE FROM `world_state` WHERE `ID` IN (17224, 17225, 17227, 21975, 26150, 26151);
INSERT INTO `world_state` (`ID`, `MapIDs`, `DefaultValue`, `Comment`) VALUES
(17224, null, 1, 'Enable Alterac Valley Battleground'),
(17225, null, 1, 'Enable Warson Gulch Battleground'),
(17227, null, 1, 'Enable Arathi Basin Battleground'),
(21975, null, 1, 'Enable Isle of Conquest Battleground'),
(26150, null, 1, 'Enable Twin Peaks Battleground'),
(26151, null, 1, 'Enable Battle for Gilneas Battleground');
