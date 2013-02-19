-- remove waypoint script spamming from 2 Dawnblade Blood Knight's
UPDATE `waypoint_data` SET `action`=0 WHERE `id` IN (943090,943250) AND `point`=2;
