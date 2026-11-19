-- Add new winner field, bound to player
ALTER TABLE `pvpstats_players`
  ADD COLUMN `winner` BIT(1) NOT NULL AFTER `character_guid`;

-- Resolve horde players victories
UPDATE `pvpstats_players` SET `winner` = 1 WHERE `battleground_id` IN (
    SELECT `id` FROM `pvpstats_battlegrounds` WHERE `winner_faction` = 0
) AND `character_guid` IN (
    SELECT `guid` FROM `characters` WHERE `race` IN (2, 5, 6, 8, 9, 10)
);

-- Resolve alliance players victories
UPDATE `pvpstats_players` SET `winner` = 1 WHERE `battleground_id` IN (
    SELECT `id` FROM `pvpstats_battlegrounds` WHERE `winner_faction` = 1
) AND `character_guid` IN (
    SELECT `guid` FROM `characters` WHERE `race` IN (1, 3, 4, 7, 11, 22)
);
