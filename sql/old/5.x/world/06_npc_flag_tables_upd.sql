ALTER TABLE `creature_template`
MODIFY COLUMN `npcflag`  bigint(15) UNSIGNED NOT NULL DEFAULT 0 AFTER `faction_H`;

ALTER TABLE `creature`
MODIFY COLUMN `npcflag`  bigint(15) UNSIGNED NOT NULL DEFAULT 0 AFTER `MovementType`;

ALTER TABLE `game_event_npcflag`
MODIFY COLUMN `npcflag`  bigint(15) UNSIGNED NOT NULL DEFAULT 0 AFTER `guid`;