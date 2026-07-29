-- Gilneas City - Worgen Stater Area

UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 & ~0x20000000 WHERE `entry` = 34864; -- remove floating flag for Gilneas City Guard
