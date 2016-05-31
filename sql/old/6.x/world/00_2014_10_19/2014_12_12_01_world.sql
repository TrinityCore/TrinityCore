--
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` |33554432, `flags_extra` = `flags_extra` &~256  WHERE entry IN (10184, 36538);
