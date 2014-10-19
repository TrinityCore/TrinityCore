-- Cleaning db, those mobs already have emote asigned on creature_template_addon
DELETE FROM creature_addon WHERE guid IN (SELECT guid FROM creature WHERE `id` = 33236) AND `emote`=27;
