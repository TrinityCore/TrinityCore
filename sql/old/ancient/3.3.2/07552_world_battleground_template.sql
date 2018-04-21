-- Add disable column to allow battlegrounds to be disabled.
ALTER TABLE `battleground_template` ADD COLUMN disable TINYINT(1) NOT NULL DEFAULT '0';

-- Disable wtlk arenas by default
UPDATE `battleground_template` SET `disable`=1 WHERE `id` in (10,11);
