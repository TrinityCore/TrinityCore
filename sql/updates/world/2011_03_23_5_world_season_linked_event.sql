-- Delete wrongly assigned season linked events
DELETE FROM `season_linked_event` WHERE `event` IN (124,125);
