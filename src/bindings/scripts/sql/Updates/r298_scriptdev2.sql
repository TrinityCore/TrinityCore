-- EVENT_T_SPELLHIT
UPDATE eventai_scripts SET event_param3 = event_param2, event_param2 = -1 WHERE event_type = 10;