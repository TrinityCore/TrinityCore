-- Disable Midsummer Fire Festival quests that were removed in patch 2.4.0
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (9367,9368,9319,9386,9322,9323,9388,9389);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,9367,0,0,0,'Quest: The Festival of Fire {A}, removed in patch 2.4.0'),
(1,9368,0,0,0,'Quest: The Festival of Fire {H}, removed in patch 2.4.0'),
(1,9319,0,0,0,'Quest: A Light in Dark Places, removed in patch 2.4.0'),
(1,9386,0,0,0,'Quest: A Light in Dark Places {Daily}, removed in patch 2.4.0'),
(1,9322,0,0,0,'Quest: Wild Fires in Kalimdor, removed in patch 2.4.0'),
(1,9323,0,0,0,'Quest: Wild Fires in the Eastern Kingdoms, removed in patch 2.4.0'),
(1,9388,0,0,0,'Quest: Flickering Flames in Kalimdor, removed in patch 2.4.0'),
(1,9389,0,0,0,'Quest: Flickering Flames in the Eastern Kingdoms, removed in patch 2.4.0');

-- Remove above mentioned quests from QuestStarters and QuestEnders
DELETE FROM `creature_queststarter` WHERE `quest` IN (9367,9368,9319,9386,9322,9323,9388,9389);
DELETE FROM `creature_questender` WHERE `quest` IN (9367,9368,9319,9386,9322,9323,9388,9389);
