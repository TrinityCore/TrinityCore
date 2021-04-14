DELETE FROM `spell_proc_event` WHERE `entry` IN (16086,16544,51523,51524);
INSERT INTO `spell_proc_event` VALUES
( 16086, 0x04,  11, 0x00000020, 0x00000000, 0x00000000, 0x00011000, 0x00000000,   0,   0,   0), -- Improved Fire Nova Totem (Rank 1)
( 16544, 0x04,  11, 0x00000020, 0x00000000, 0x00000000, 0x00011000, 0x00000000,   0, 100,   0), -- Improved Fire Nova Totem (Rank 2)
( 51523, 0x08,  11, 0x00000000, 0x00000001, 0x00000000, 0x00011000, 0x00000000,   0,  50,   0), -- Earthen Power (Rank 1)
( 51524, 0x08,  11, 0x00000000, 0x00000001, 0x00000000, 0x00011000, 0x00000000,   0, 100,   0); -- Earthen Power (Rank 2)
