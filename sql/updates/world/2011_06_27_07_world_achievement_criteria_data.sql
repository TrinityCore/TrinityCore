DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry` IN (7709,7710,7711,7712,7713,7714,7715,7716,7718,7719);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7709,7710,7711,7712,7713,7714,7715,7716,7718,7719);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7709,6,4575,0, ''), -- killed player in Wintergrasp Fortress
(7710,6,4612,0, ''), -- killed player in Eastspark Workshop
(7711,6,4539,0, ''), -- killed player in The Broken Temple
(7712,6,4538,0, ''), -- killed player in The Sunken Ring
(7713,6,4611,0, ''), -- killed player in Westspark Workshop
(7714,6,4581,0, ''), -- killed player in Flamewatch Tower
(7715,6,4583,0, ''), -- killed player in Shadowsight Tower
(7716,6,4582,0, ''), -- killed player in Winter's Edge Tower
(7718,6,4584,0, ''), -- killed player in The Cauldron of Flames
(7719,6,4589,0, ''); -- killed player in The Chilled Quagmire
