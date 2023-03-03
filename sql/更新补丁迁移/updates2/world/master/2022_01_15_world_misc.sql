/*
**************************
*    BfaCore Reforged    *
**************************
*/

UPDATE `creature_template` SET `ScriptName`='npc_dark_ranger_thyala_36312' WHERE (`entry`='36312');


-- Only Alliance Races can see quest
-- quest The Speaker's Imperative
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=51403;
-- quest Tides of War
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=46727;
-- quest The Nation of Kul Tiras
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=46728;
-- quest Daughter of the Sea
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=51341;
-- quest Out Like Flynn
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=47098;
-- quest Get Your Bearings
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=47099;
-- quest The Old Knight
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=46729;
-- Sanctum of the Sages
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=47186;
-- A Nation Divided
UPDATE `quest_template` SET `AllowableRaces`=2971684173 WHERE id=47189;


-- Only Horde Races can see quest
-- quest The Speaker's Imperative
UPDATE `quest_template` SET `AllowableRaces`=1308636082 WHERE id=53031;
-- quest Battle for Azeroth: Mission Statement
UPDATE `quest_template` SET `AllowableRaces`=1308636082 WHERE id=51443;
-- Fix Quest Complete NPC
UPDATE `creature_template` SET `npcflag` = 3  WHERE (`entry` = 135205);
-- quest The Stormwind Extraction
UPDATE `quest_template` SET `AllowableRaces`=1308636082 WHERE id=50769;


-- Fix Quest Forced to Watch from Afar
-- Fix Creature Mountaineer Valgrum
UPDATE creature_template SET ScriptName="" WHERE entry= 41056;
DELETE FROM smart_scripts WHERE entryOrGuid = 41056;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= 41056;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(41056, 0, 0, 0, 62, 0, 100, 0, 11457, 0, 0, 0, 33, 41056, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11457 selected - Action invoker: Give kill credit Mountaineer Valgrum"),
(41056, 0, 1, 0, 62, 0, 100, 0, 11457, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11457 selected - Self: Talk 0 to invoker");

-- Fix Creature Mountaineer Lewin
DELETE FROM smart_scripts WHERE entryOrGuid = 40994;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= 40994;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(40994, 0, 0, 0, 62, 0, 100, 0, 11456, 0, 0, 0, 33, 40994, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11456 selected - Action invoker: Give kill credit Mountaineer Lewin"),
(40994, 0, 1, 0, 62, 0, 100, 0, 11456, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11456 selected - Self: Talk 0 to invoker");

-- Fix Creature Mountaineer Dunstan
DELETE FROM smart_scripts WHERE entryOrGuid = 40991;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= 40991;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(40991, 0, 0, 0, 62, 0, 100, 0, 11455, 0, 0, 0, 33, 40991, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11455 selected - Action invoker: Give kill credit Mountaineer Dunstan"),
(40991, 0, 1, 0, 62, 0, 100, 0, 11455, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 11455 selected - Self: Talk 0 to invoker");
