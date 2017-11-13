UPDATE `creature_template` SET `modelid1` = '13069' WHERE `entry` = '95049';

DELETE FROM creature_addon WHERE guid = 20541414;

#95048

REPLACE INTO `areatrigger_template_actions` VALUES (9905, 0, 195401, 2);
UPDATE creature_template SET scriptname = "npc_mardum_doom_commander_beliash" WHERE entry = 93221;
UPDATE gameobject_template SET scriptname = "go_mardum_portal_shivarra" WHERE entry = 241757;
