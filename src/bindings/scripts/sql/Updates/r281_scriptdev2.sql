ALTER TABLE eventai_scripts
ADD event_chance tinyint(3) unsigned NOT NULL default 100 AFTER event_inverse_phase_mask;

-- EVENT_T_TIMER_REPEAT
UPDATE eventai_scripts SET event_chance = -event_param3  WHERE event_type = 0 AND event_param3 < 0;

-- EVENT_T_TIMER_SINGLE
UPDATE eventai_scripts SET event_chance = event_param2  WHERE event_type = 1;

-- EVENT_T_TIMER_OOC_REPEAT
UPDATE eventai_scripts SET event_chance = -event_param3  WHERE event_type = 2 AND event_param3 < 0;

-- EVENT_T_TIMER_OOC_SINGLE
UPDATE eventai_scripts SET event_chance = event_param2  WHERE event_type = 3;

-- EVENT_T_HP_SINGLE
UPDATE eventai_scripts SET event_chance = -event_param3  WHERE event_type = 4 AND event_param3 < 0;

-- EVENT_T_MANA_SINGLE
UPDATE eventai_scripts SET event_chance = -event_param3  WHERE event_type = 5 AND event_param3 < 0;

-- EVENT_T_AGGRO
UPDATE eventai_scripts SET event_chance = event_param1  WHERE event_type = 6;

-- EVENT_T_KILL
UPDATE eventai_scripts SET event_chance = event_param2  WHERE event_type = 7;

-- EVENT_T_DEATH
UPDATE eventai_scripts SET event_chance = event_param1  WHERE event_type = 8;

-- EVENT_T_EVADE
UPDATE eventai_scripts SET event_chance = event_param1  WHERE event_type = 9;

-- EVENT_T_SPELLHIT
UPDATE eventai_scripts SET event_chance = event_param3  WHERE event_type = 10;