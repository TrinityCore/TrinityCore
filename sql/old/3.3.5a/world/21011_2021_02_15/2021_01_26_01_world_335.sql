-- Razelikh the Defiler, requires research
UPDATE `creature_template` SET `spell_school_immune_mask` = 0 WHERE `entry` = 7664;

-- Fire
UPDATE `creature_template` SET `spell_school_immune_mask` = 4 WHERE `entry` IN (575,2745,3417,5893,5896,6073,6520,6521,7135,7136,7266,7738,7846,8281,8608,8616,8680,8909,8910,8911,9178,9376,11583,11981,11983,12265,13020,14460,14461,14601,14668,15203,15209,17003);

-- Nature
UPDATE `creature_template` SET `spell_school_immune_mask` = 8 WHERE `entry` IN (832,4526,5898,5902,6239,8667,9377,9397,11576,11577,11578,11745,14399,14400,14454,14478,14887,14888,14889,14890,5855,16043,4034,4035);

-- Frost
UPDATE `creature_template` SET `spell_school_immune_mask` = 16 WHERE `entry` IN (2776,2794,3851,3861,3950,4978,5894,5895,5897,6047,6220,6748,8519,8520,8521,8522,8837,10955,11256,11862,12759,12876,13278,13279,13282,13322,13456,13696,13736,14269,14350,14457,14458,15211,15305);

-- Arcane
UPDATE `creature_template` SET `spell_school_immune_mask` = 64 WHERE `entry` IN (6109,6492,6550,11484,14397,15527);

UPDATE `creature_template` SET `spell_school_immune_mask` = 116 WHERE `entry` = 7734;
UPDATE `creature_template` SET `spell_school_immune_mask` = 116 WHERE `entry` = 7735;
UPDATE `creature_template` SET `spell_school_immune_mask` = 127 WHERE `entry` = 8317;
UPDATE `creature_template` SET `spell_school_immune_mask` = 1 WHERE `entry` = 11284;
-- Invincibility no longer needed
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8317 AND `source_type` = 0 AND `id` = 0;
