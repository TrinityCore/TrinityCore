-- custom
-- UNIT_NPC_FLAG_GUARD                 = 0x00010000, old 
-- UNIT_NPC_FLAG_GUARD                 = 0x10000000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x10000000) & ~0x00010000 WHERE `npcflag` & 0x00010000;

-- UNIT_NPC_FLAG_STABLEMASTER          = 0x00002000, old
-- UNIT_NPC_FLAG_STABLEMASTER          = 0x00400000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00400000) & ~0x00002000 WHERE `npcflag` & 0x00002000;

-- UNIT_NPC_FLAG_AUCTIONEER            = 0x00001000, old
-- UNIT_NPC_FLAG_AUCTIONEER            = 0x00200000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00200000) & ~0x00001000 WHERE `npcflag` & 0x00001000;

-- UNIT_NPC_FLAG_BATTLEFIELDPERSON     = 0x00000800, old
-- UNIT_NPC_FLAG_BATTLEMASTER          = 0x00100000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00100000) & ~0x00000800 WHERE `npcflag` & 0x00000800;

-- UNIT_NPC_FLAG_ARMORER               = 0x00004000, old
-- UNIT_NPC_FLAG_REPAIR                = 0x00001000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00001000) & ~0x00004000 WHERE `npcflag` & 0x00004000;

-- UNIT_NPC_FLAG_TABARDDESIGNER        = 0x00000400, old
-- UNIT_NPC_FLAG_TABARDDESIGNER        = 0x00080000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00080000) & ~0x00000400 WHERE `npcflag` & 0x00000400;

-- UNIT_NPC_FLAG_PETITIONER            = 0x00000200, old
-- UNIT_NPC_FLAG_PETITIONER            = 0x00040000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00040000) & ~0x00000200 WHERE `npcflag` & 0x00000200;

-- UNIT_NPC_FLAG_BANKER                = 0x00000100, old
-- UNIT_NPC_FLAG_BANKER                = 0x00020000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00020000) & ~0x00000100 WHERE `npcflag` & 0x00000100;

-- UNIT_NPC_FLAG_INNKEEPER             = 0x00000080, old
-- UNIT_NPC_FLAG_INNKEEPER             = 0x00010000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00010000) & ~0x00000080 WHERE `npcflag` & 0x00000080;

-- UNIT_NPC_FLAG_SPIRITGUIDE           = 0x00000040, old
-- UNIT_NPC_FLAG_SPIRITGUIDE           = 0x00008000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00008000) & ~0x00000040 WHERE `npcflag` & 0x00000040;

-- UNIT_NPC_FLAG_SPIRITHEALER          = 0x00000020, old
-- UNIT_NPC_FLAG_SPIRITHEALER          = 0x00004000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00004000) & ~0x00000020 WHERE `npcflag` & 0x00000020;

-- UNIT_NPC_FLAG_TAXIVENDOR            = 0x00000008, old
-- UNIT_NPC_FLAG_FLIGHTMASTER          = 0x00002000, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00002000) & ~0x00000008 WHERE `npcflag` & 0x00000008;

-- UNIT_NPC_FLAG_VENDOR                = 0x00000004, old
-- UNIT_NPC_FLAG_VENDOR                = 0x00000080, new
UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x00000080) & ~0x00000004 WHERE `npcflag` & 0x00000004;
