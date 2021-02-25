UPDATE `creature_template` SET `mechanic_immune_mask`= 0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20 | 0x40 | 0x200 | 0x800 | 0x1000 | 0x2000 | 0x10000 | 0x400000 | 0x800000, `flags_extra`= `flags_extra` | 0x40000000 WHERE `entry`= 45265;
UPDATE `creature_template` SET `mechanic_immune_mask`= 0x1 WHERE `entry` IN (45264, 45261, 45266, 45267);
