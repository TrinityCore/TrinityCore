DELETE FROM script_waypoint WHERE entry=3849;
INSERT INTO script_waypoint VALUES
(3849, 0, -250.923431, 2116.264160, 81.179, 0, 'SAY_FREE_AD'),
(3849, 1, -255.048538, 2119.392578, 81.179, 0, ''),
(3849, 2, -254.129105, 2123.454346, 81.179, 0, ''),
(3849, 3, -253.897552, 2130.873535, 81.179, 0, ''),
(3849, 4, -249.889435, 2142.307861, 86.972, 0, ''),
(3849, 5, -248.204926, 2144.017090, 87.013, 0, ''),
(3849, 6, -240.552826, 2140.552734, 87.012, 0, ''),
(3849, 7, -237.513916, 2142.066650, 87.012, 0, ''),
(3849, 8, -235.638138, 2149.231689, 90.587, 0, ''),
(3849, 9, -237.188019, 2151.946045, 90.624, 0, ''),
(3849, 10, -241.162064, 2153.649658, 90.624, 0, 'SAY_OPEN_DOOR_AD'),
(3849, 11, -241.129700, 2154.562988, 90.624, 5000, ''),
(3849, 12, -241.129700, 2154.562988, 90.624, 5000, 'SAY_POST1_DOOR_AD'),
(3849, 13, -241.129700, 2154.562988, 90.624, 25000, 'SAY_POST2_DOOR_AD');

DELETE FROM script_waypoint WHERE entry=3850;
INSERT INTO script_waypoint VALUES
(3850, 0, -241.816895, 2122.904053, 81.179, 0, 'SAY_FREE_AS'),
(3850, 1, -247.139297, 2124.886475, 81.179, 0, ''),
(3850, 2, -253.179184, 2127.406738, 81.179, 0, ''),
(3850, 3, -253.897552, 2130.873535, 81.179, 0, ''),
(3850, 4, -249.889435, 2142.307861, 86.972, 0, ''),
(3850, 5, -248.204926, 2144.017090, 87.013, 0, ''),
(3850, 6, -240.552826, 2140.552734, 87.012, 0, ''),
(3850, 7, -237.513916, 2142.066650, 87.012, 0, ''),
(3850, 8, -235.638138, 2149.231689, 90.587, 0, ''),
(3850, 9, -237.188019, 2151.946045, 90.624, 0, ''),
(3850, 10, -241.162064, 2153.649658, 90.624, 0, 'SAY_OPEN_DOOR_AS'),
(3850, 11, -241.129700, 2154.562988, 90.624, 5000, 'cast'),
(3850, 12, -241.129700, 2154.562988, 90.624, 5000, 'SAY_POST_DOOR_AS'),
(3850, 13, -241.129700, 2154.562988, 90.624, 25000, '');

UPDATE script_texts SET content_default='Follow me and I\'ll open the courtyard door for you.', language=7, comment='prisoner ashcrombe SAY_FREE_AS' WHERE entry=-1033000;

DELETE FROM script_texts WHERE entry BETWEEN -1033008 AND -1033001;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1033001,'I have just the spell to get this door open. Too bad the cell doors weren\'t locked so haphazardly.',0,0,7,1,'prisoner ashcrombe SAY_OPEN_DOOR_AS'),
(-1033002,'There it is! Wide open. Good luck to you conquering what lies beyond. I must report back to the Kirin Tor at once!',0,0,7,1,'prisoner ashcrombe SAY_POST_DOOR_AS'),
(-1033003,'Free from this wretched cell at last! Let me show you to the courtyard....',0,0,1,1,'prisoner adamant SAY_FREE_AD'),
(-1033004,'You are indeed courageous for wanting to brave the horrors that lie beyond this door.',0,0,1,1,'prisoner adamant SAY_OPEN_DOOR_AD'),
(-1033005,'There we go!',0,0,1,1,'prisoner adamant SAY_POST1_DOOR_AD'),
(-1033006,'Good luck with Arugal. I must hurry back to Hadrec now.',0,0,1,1,'prisoner adamant SAY_POST2_DOOR_AD'),
(-1033007,'About time someone killed the wretch.',0,0,1,1,'prisoner adamant SAY_BOSS_DIE_AD'),
(-1033008,'For once I agree with you... scum.',0,0,7,1,'prisoner ashcrombe SAY_BOSS_DIE_AS');
