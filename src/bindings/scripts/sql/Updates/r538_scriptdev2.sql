-- Structure updates

ALTER TABLE eventai_scripts
ADD event_flags tinyint(3) unsigned NOT NULL default '0' AFTER event_chance;

ALTER TABLE eventai_scripts
ADD event_param4 int(11) signed NOT NULL default '0' AFTER event_param3;

-- Event updates

-- EVENT_T_TIMER_REPEAT
UPDATE eventai_scripts SET event_param4 = event_param3+event_param1, event_param3 = event_param1, event_param1 = event_param2, event_flags = 1 WHERE event_type = 0;

-- EVENT_T_TIMER_SINGLE
UPDATE eventai_scripts SET event_param4 = event_param3+event_param1, event_param3 = event_param1, event_param1 = event_param2, event_type = 0 WHERE event_type = 1;

-- EVENT_T_TIMER_OOC_REPEAT
UPDATE eventai_scripts SET event_param4 = event_param3+event_param1, event_param3 = event_param1, event_param1 = event_param2, event_flags = 1, event_type = 1 WHERE event_type = 2;

-- EVENT_T_TIMER_OOC_SINGLE
UPDATE eventai_scripts SET event_param4 = event_param3+event_param1, event_param3 = event_param1, event_param1 = event_param2, event_type = 1 WHERE event_type = 3;

-- EVENT_T_HP_SINGLE
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 0, event_type = 2 WHERE event_type = 4;

-- EVENT_T_MANA_SINGLE
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 0, event_type = 3 WHERE event_type = 5;

-- EVENT_T_AGGRO
UPDATE eventai_scripts SET event_type = 4 WHERE event_type = 6;

-- EVENT_T_KILL
UPDATE eventai_scripts SET event_param2 = event_param1, event_flags = 1, event_type = 5 WHERE event_type = 7;

-- EVENT_T_DEATH
UPDATE eventai_scripts SET event_type = 6 WHERE event_type = 8;

-- EVENT_T_EVADE
UPDATE eventai_scripts SET event_type = 7 WHERE event_type = 9;

-- EVENT_T_SPELLHIT
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 1, event_type = 8 WHERE event_type = 10;

-- EVENT_T_RANGE
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 1, event_type = 9 WHERE event_type = 11;

-- EVENT_T_OOC_LOS
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 1, event_type = 10 WHERE event_type = 12;

-- EVENT_T_SPAWNED
UPDATE eventai_scripts SET event_type = 11 WHERE event_type = 13;

-- EVENT_T_TARGET_HP
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 1, event_type = 12 WHERE event_type = 14;

-- EVENT_T_TARGET_CASTING
UPDATE eventai_scripts SET event_param2 = event_param1, event_flags = 1, event_type = 13 WHERE event_type = 15;

-- EVENT_T_FRIENDLY_HP
UPDATE eventai_scripts SET event_param4 = event_param3, event_flags = 1, event_type = 14 WHERE event_type = 16;