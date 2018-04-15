-- Remove some unused creature_ai_texts
DELETE FROM creature_ai_texts WHERE entry IN (-1,-133,-134,-135,-136,-137,-138,-139,-217,-218,-219,-220,-221,-222,-223,-224,-225,-226,-227,-810,-811,-812,-813,-814,-815);
DELETE FROM creature_ai_texts WHERE entry BETWEEN -876 AND -841;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -643 AND -634;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -763 AND -740;
-- Clean up some EAI errors
UPDATE creature_ai_scripts SET action1_param2 = 0 WHERE action1_type = 1 AND creature_id IN (22992,22993,22994,23163);
-- Remove some EAI already converted to cpp
DELETE FROM creature_ai_scripts WHERE creature_id IN (26529,26530,26532,26533);
UPDATE creature_template SET AIName = '' WHERE entry IN (26529,26530,26532,26533);
