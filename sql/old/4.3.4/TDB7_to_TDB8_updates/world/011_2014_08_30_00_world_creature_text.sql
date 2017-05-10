DELETE FROM `trinity_string` WHERE (`entry` BETWEEN 1302 AND 1325) OR (`entry` IN (1331,1332));

DELETE FROM `creature_text` WHERE `entry`=14848;
DELETE FROM `creature_text` WHERE `entry`=11946 AND `groupid`=3 AND `id`=5;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(14848, 1, 0, 'The Stormpike Graveyard was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9057, 'Herald'),
(14848, 2, 0, 'The Stormpike Graveyard is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9058, 'Herald'),
(14848, 3, 0, 'The Stormpike Graveyard was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9059, 'Herald'),
(14848, 4, 0, 'The Stormpike Graveyard is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9060, 'Herald'),

(14848, 5, 0, 'The Snowfall Graveyard was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9061, 'Herald'),
(14848, 6, 0, 'The Snowfall Graveyard is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9062, 'Herald'),
(14848, 7, 0, 'The Snowfall Graveyard was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9063, 'Herald'),
(14848, 8, 0, 'The Snowfall Graveyard is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0,8174, 9064, 'Herald'),

(14848, 9, 0, 'The Frostwolf Graveyard was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9065, 'Herald'),
(14848,10, 0, 'The Frostwolf Graveyard is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9066, 'Herald'),
(14848,11, 0, 'The Frostwolf Graveyard was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9067, 'Herald'),
(14848,12, 0, 'The Frostwolf Graveyard is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9068, 'Herald'),

(14848,13, 0, 'The Dun Baldar South Bunker is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9174, 'Herald'),
(14848,14, 0, 'The Dun Baldar South Bunker was destroyed by the Horde!', 14, 0, 100, 0, 0, 8213, 9175, 'Herald'),
(14848,15, 0, 'The Dun Baldar South Bunker is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9176, 'Herald'),
(14848,16, 0, 'The Dun Baldar South Bunker was taken by the Alliance!', 14, 0, 100, 0, 0, 8192, 9177, 'Herald'),

(14848,17, 0, 'The Dun Baldar North Bunker is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9178, 'Herald'),
(14848,18, 0, 'The Dun Baldar North Bunker was destroyed by the Horde!', 14, 0, 100, 0, 0, 8213, 9179, 'Herald'),
(14848,19, 0, 'The Dun Baldar North Bunker is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9180, 'Herald'),
(14848,20, 0, 'The Dun Baldar North Bunker was taken by the Alliance!', 14, 0, 100, 0, 0, 8192, 9181, 'Herald'),

(14848,21, 0, 'The Icewing Bunker is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9182, 'Herald'),
(14848,22, 0, 'The Icewing Bunker was destroyed by the Horde!', 14, 0, 100, 0, 0, 8213, 9183, 'Herald'),
(14848,23, 0, 'The Icewing Bunker is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9184, 'Herald'),
(14848,24, 0, 'The Icewing Bunker was taken by the Alliance!', 14, 0, 100, 0, 0, 8192, 9185, 'Herald'),

(14848,25, 0, 'The Stonehearth Bunker is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9186, 'Herald'),
(14848,26, 0, 'The Stonehearth Bunker was destroyed by the Horde!', 14, 0, 100, 0, 0, 8213, 9187, 'Herald'),
(14848,27, 0, 'The Stonehearth Bunker is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9188, 'Herald'),
(14848,28, 0, 'The Stonehearth Bunker was taken by the Alliance!', 14, 0, 100, 0, 0, 8192, 9189, 'Herald'),

(14848,29, 0, 'The West Frostwolf Tower is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9190, 'Herald'),
(14848,30, 0, 'The West Frostwolf Tower was taken by the Horde!', 14, 0, 100, 0, 0, 8192, 9191, 'Herald'),
(14848,31, 0, 'The West Frostwolf Tower is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9192, 'Herald'),
(14848,32, 0, 'The West Frostwolf Tower was destroyed by the Alliance!', 14, 0, 100, 0, 0, 8173, 9193, 'Herald'),

(14848,33, 0, 'The East Frostwolf Tower is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9194, 'Herald'),
(14848,34, 0, 'The East Frostwolf Tower was taken by the Horde!', 14, 0, 100, 0, 0, 8192, 9195, 'Herald'),
(14848,35, 0, 'The East Frostwolf Tower is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9196, 'Herald'),
(14848,36, 0, 'The East Frostwolf Tower was destroyed by the Alliance!', 14, 0, 100, 0, 0, 8173, 9197, 'Herald'),

(14848,37, 0, 'Tower Point is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9198, 'Herald'),
(14848,38, 0, 'Tower Point was taken by the Horde!', 14, 0, 100, 0, 0, 8192, 9199, 'Herald'),
(14848,39, 0, 'Tower Point is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9200, 'Herald'),
(14848,40, 0, 'Tower Point was destroyed by the Alliance!', 14, 0, 100, 0, 0, 8173, 9201, 'Herald'),

(14848,41, 0, 'Iceblood Bunker is under attack!  If left unchecked, the Horde will destroy it!', 14, 0, 100, 0, 0, 8174, 9202, 'Herald'),
(14848,42, 0, 'Iceblood Tower was taken by the Horde!', 14, 0, 100, 0, 0, 8192, 9203, 'Herald'),
(14848,43, 0, 'Iceblood Tower is under attack!  If left unchecked, the Alliance will destroy it!', 14, 0, 100, 0, 0, 8212, 9204, 'Herald'),
(14848,44, 0, 'Iceblood Tower was destroyed by the Alliance!', 14, 0, 100, 0, 0, 8173, 9205, 'Herald'),

(14848,45, 0, 'The Stormpike Aid Station was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9211, 'Herald'),
(14848,46, 0, 'The Stormpike Aid Station is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9212, 'Herald'),
(14848,47, 0, 'The Stormpike Aid Station was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9213, 'Herald'),
(14848,48, 0, 'The Stormpike Aid Station is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9214, 'Herald'),

(14848,49, 0, 'The Frostwolf Relief Hut was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9215, 'Herald'),
(14848,50, 0, 'The Frostwolf Relief Hut is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9216, 'Herald'),
(14848,51, 0, 'The Frostwolf Relief Hut was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9217, 'Herald'),
(14848,52, 0, 'The Frostwolf Relief Hut is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9218, 'Herald'),

(14848,53, 0, 'The Stonehearth Graveyard was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9221, 'Herald'),
(14848,54, 0, 'The Stonehearth Graveyard is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9222, 'Herald'),
(14848,55, 0, 'The Stonehearth Graveyard was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9223, 'Herald'),
(14848,56, 0, 'The Stonehearth Graveyard is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9224, 'Herald'),

(14848,57, 0, 'The Iceblood Graveyard was taken by the Horde!', 14, 0, 100, 0, 0, 8213, 9225, 'Herald'),
(14848,58, 0, 'The Iceblood Graveyard is under attack!  If left unchecked, the Horde will capture it!', 14, 0, 100, 0, 0, 8174, 9226, 'Herald'),
(14848,59, 0, 'The Iceblood Graveyard was taken by the Alliance!', 14, 0, 100, 0, 0, 8173, 9227, 'Herald'),
(14848,60, 0, 'The Iceblood Graveyard is under attack!  If left unchecked, the Alliance will capture it!', 14, 0, 100, 0, 0, 8212, 9228, 'Herald'),

(14848,61, 0, 'The Alliance has taken Coldtooth Mine!  Its supplies will now be used for reinforcements!', 14, 0, 100, 0, 0, 8173, 8594, 'Herald'),
(14848,62, 0, 'The Alliance has taken the Irondeep Mine!  Its supplies will now be used for reinforcements!', 14, 0, 100, 0, 0, 8173, 8595, 'Herald'),
(14848,63, 0, 'The Horde has taken the Coldtooth Mine!  Its supplies will now be used for reinforcements!', 14, 0, 100, 0, 0, 8213, 8596, 'Herald'),
(14848,64, 0, 'The Horde has taken the Irondeep Mine!  Its supplies will now be used for reinforcements!', 14, 0, 100, 0, 0, 8213, 8597, 'Herald'),

(14848,65, 0, 'The Frostwolf General is dead!', 14, 0, 100, 0, 0, 0, 7296, 'Herald'),
(14848,66, 0, 'The Stormpike General is dead!', 14, 0, 100, 0, 0, 0, 7297, 'Herald'),

(14848,67, 0, 'The Alliance wins!', 14, 0, 100, 0, 0, 0, 7335, 'Herald'),
(14848,68, 0, 'The Horde wins!', 14, 0, 100, 0, 0, 0, 7336, 'Herald'),

(11946, 3, 5, 'Leave no survivors!', 14, 0, 100, 0, 0, 0, 12352, 'Drek''Thar');
