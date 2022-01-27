-- No event params & can't repeat
-- SMART_EVENT_AGGRO & SMART_EVENT_JUST_CREATED & SMART_EVENT_DEATH & SMART_EVENT_EVADE & SMART_EVENT_REACHED_HOME & SMART_EVENT_RESET & SMART_EVENT_JUST_SUMMONED & SMART_EVENT_ON_SPELLCLICK
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 1, `event_param1` = 0, `event_param2` = 0, `event_param3` = 0, `event_param4` = 0 WHERE `event_type` IN (4,6,7,21,25,54,63,73) AND `entryorguid` NOT IN (22473,22448);
-- SMART_EVENT_RESPAWN
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 1, `event_param1` = 0, `event_param2` = 0, `event_param3` = 0, `event_param4` = 0 WHERE `event_type` = 11 AND `entryorguid` = 2435;
