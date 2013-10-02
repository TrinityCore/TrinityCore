-- DB/Quest: Fix: [A/H] The Summoning
-- Note: This warrior quest was deleted in 4.0.1.
SET @ENTRY := 6176; -- Bath'rah the Windwatcher
DELETE FROM `waypoints` WHERE `entry` = @ENTRY AND `pointid` BETWEEN 8 AND 14;
UPDATE `smart_scripts` SET `event_type` = 40 WHERE `entryorguid` = @ENTRY AND `id` = 1;
