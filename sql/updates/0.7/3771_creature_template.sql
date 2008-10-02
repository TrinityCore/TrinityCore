UPDATE `creature_template` SET `npcflag` = (`npcflag` | 0x10000) & ~0x40 WHERE `npcflag` & 0x40 = 0x40 AND `name` NOT LIKE '%spirit guide%';
