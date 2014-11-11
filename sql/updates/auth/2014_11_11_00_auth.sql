/* add entry for the beta client program WoWB */
INSERT INTO `battlenet_components` (`Program`,`Platform`,`Build`) VALUES
('WoWB','Mc64','19116'),
('WoWB','Win','19116'),
('WoWB','Wn64','19116'),
('WoWB','deDE','0'),
('WoWB','enGB','0'),
('WoWB','enUS','0'),
('WoWB','esES','0'),
('WoWB','esMX','0'),
('WoWB','frFR','0'),
('WoWB','koKR','0'),
('WoWB','ruRU','0'),
('WoWB','zhCN','0'),
('WoWB','base','19116'),
('WoWB','zhTW','0');

/* Version bump for WoW base */
UPDATE `battlenet_components` SET Build = 19116 WHERE Build = 19057;

