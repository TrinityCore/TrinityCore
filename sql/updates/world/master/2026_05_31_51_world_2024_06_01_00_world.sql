DELETE FROM `creature_template_difficulty` WHERE `Entry`=31243 AND `DifficultyID`=0;
-- Add missing movement flags to Warsong Cannon
UPDATE `creature_template_difficulty` SET `DifficultyID`=0, `StaticFlags1`=0x306, `StaticFlags2`=0x400, `StaticFlags3`=0x400 WHERE `Entry`=31243;
