UPDATE quest_template_addon SET PrevQuestID = 34583 WHERE id = 34616;
UPDATE quest_objectives SET Amount = 0 WHERE id = 273766;
REPLACE INTO gossip_menu VALUES (60002, 79243, 0);
REPLACE INTO gossip_menu_option VALUES (60002, 1, 0, "We have everything we need. It's time to build this Garrison.", 0, 1, 1, 0);
