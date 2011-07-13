-- Anub'arak Spike immunemask
-- This is a hack to prevent CC'ing the spike, dont set slow immunity or he will not recognize permafrost aura,
-- even slowing the spike it will reach the "death-speed".
UPDATE `creature_template` SET `mechanic_immune_mask` = 82409854 WHERE `entry` = 34660;