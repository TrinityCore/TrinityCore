-- playercreateinfo_skills

DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 129;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 229;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 293;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 762;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 770;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 771;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 32 AND `skill` = 772;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 35 AND `skill` = 55;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 35 AND `skill` = 413;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 37 AND `skill` = 44;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 37 AND `skill` = 172;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 39 AND `skill` = 43;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 40 AND `skill` = 118;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 67 AND `skill` = 433;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 400 AND `skill` = 228;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 1107 AND `skill` = 54;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 1135 AND `skill` = 414;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 0 AND `classMask` = 1488 AND `skill` = 136;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 36 AND `classMask` = 4 AND `skill` = 46;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 650 AND `classMask` = 4 AND `skill` = 45;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 735 AND `classMask` = 1293 AND `skill` = 173;
DELETE FROM `world`.`playercreateinfo_skills` WHERE `raceMask` = 1061 AND `classMask` = 3 AND `skill` = 160;

UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: defense (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 95;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: unarmed (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 162;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: generic (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 183;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'armor: cloth (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 415;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: mounts (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 777;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: pets (all)' WHERE `raceMask` = 0 AND `classMask` = 0 AND `skill` = 778;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: arms (warrior)' WHERE `raceMask` = 0 AND `classMask` = 1 AND `skill` = 26;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: fury (warrior)' WHERE `raceMask` = 0 AND `classMask` = 1 AND `skill` = 256;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: protection (warrior)' WHERE `raceMask` = 0 AND `classMask` = 1 AND `skill` = 257;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: retribution (paladin)' WHERE `raceMask` = 0 AND `classMask` = 2 AND `skill` = 184;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: protection (paladin)' WHERE `raceMask` = 0 AND `classMask` = 2 AND `skill` = 267;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: holy (paladin)' WHERE `raceMask` = 0 AND `classMask` = 2 AND `skill` = 594;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: beast mastery (hunter)' WHERE `raceMask` = 0 AND `classMask` = 4 AND `skill` = 50;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: survival (hunter)' WHERE `raceMask` = 0 AND `classMask` = 4 AND `skill` = 51;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: marksmanship (hunter)' WHERE `raceMask` = 0 AND `classMask` = 4 AND `skill` = 163;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: combat (rogue)' WHERE `raceMask` = 0 AND `classMask` = 8 AND `skill` = 38;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: subtlety (rogue)' WHERE `raceMask` = 0 AND `classMask` = 8 AND `skill` = 39;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: thrown (rogue)' WHERE `raceMask` = 0 AND `classMask` = 8 AND `skill` = 176;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: assassination (rogue)' WHERE `raceMask` = 0 AND `classMask` = 8 AND `skill` = 253;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: holy (priest)' WHERE `raceMask` = 0 AND `classMask` = 16 AND `skill` = 56;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: shadow (priest)' WHERE `raceMask` = 0 AND `classMask` = 16 AND `skill` = 78;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: discipline (priest)' WHERE `raceMask` = 0 AND `classMask` = 16 AND `skill` = 613;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: enhancement (shaman)' WHERE `raceMask` = 0 AND `classMask` = 64 AND `skill` = 373;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: restoration (shaman)' WHERE `raceMask` = 0 AND `classMask` = 64 AND `skill` = 374;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: elemental (shaman)' WHERE `raceMask` = 0 AND `classMask` = 64 AND `skill` = 375;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: frost (mage)' WHERE `raceMask` = 0 AND `classMask` = 128 AND `skill` = 6;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: fire (mage)' WHERE `raceMask` = 0 AND `classMask` = 128 AND `skill` = 8;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: arcane (mage)' WHERE `raceMask` = 0 AND `classMask` = 128 AND `skill` = 237;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: demonology (warlock)' WHERE `raceMask` = 0 AND `classMask` = 256 AND `skill` = 354;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: affliction (warlock)' WHERE `raceMask` = 0 AND `classMask` = 256 AND `skill` = 355;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: destruction (warlock)' WHERE `raceMask` = 0 AND `classMask` = 256 AND `skill` = 593;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: feral (druid)' WHERE `raceMask` = 0 AND `classMask` = 1024 AND `skill` = 134;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: restoration (druid)' WHERE `raceMask` = 0 AND `classMask` = 1024 AND `skill` = 573;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'talent: balance (druid)' WHERE `raceMask` = 0 AND `classMask` = 1024 AND `skill` = 574;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (human)' WHERE `raceMask` = 1 AND `classMask` = 0 AND `skill` = 754;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (orc)' WHERE `raceMask` = 2 AND `classMask` = 0 AND `skill` = 125;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (dwarf)' WHERE `raceMask` = 4 AND `classMask` = 0 AND `skill` = 101;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (dwarf)' WHERE `raceMask` = 4 AND `classMask` = 0 AND `skill` = 111;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (night elf)' WHERE `raceMask` = 8 AND `classMask` = 0 AND `skill` = 113;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (night elf)' WHERE `raceMask` = 8 AND `classMask` = 0 AND `skill` = 126;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (undead)' WHERE `raceMask` = 16 AND `classMask` = 0 AND `skill` = 220;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (undead)' WHERE `raceMask` = 16 AND `classMask` = 0 AND `skill` = 673;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (tauren)' WHERE `raceMask` = 32 AND `classMask` = 0 AND `skill` = 115;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (tauren)' WHERE `raceMask` = 32 AND `classMask` = 0 AND `skill` = 124;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (gnome)' WHERE `raceMask` = 64 AND `classMask` = 0 AND `skill` = 313;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (gnome)' WHERE `raceMask` = 64 AND `classMask` = 0 AND `skill` = 753;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (troll)' WHERE `raceMask` = 128 AND `classMask` = 0 AND `skill` = 315;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (troll)' WHERE `raceMask` = 128 AND `classMask` = 0 AND `skill` = 733;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (blood elf)' WHERE `raceMask` = 512 AND `classMask` = 0 AND `skill` = 137;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (blood elf)' WHERE `raceMask` = 512 AND `classMask` = 0 AND `skill` = 756;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (horde)' WHERE `raceMask` = 690 AND `classMask` = 0 AND `skill` = 109;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (draenei)' WHERE `raceMask` = 1024 AND `classMask` = 0 AND `skill` = 759;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'racial: (draenei)' WHERE `raceMask` = 1024 AND `classMask` = 0 AND `skill` = 760;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'skill: crossbows (draenei hunter)' WHERE `raceMask` = 1024 AND `classMask` = 4 AND `skill` = 226;
UPDATE `world`.`playercreateinfo_skills` SET `comment` = 'language: (alliance)' WHERE `raceMask` = 1101 AND `classMask` = 0 AND `skill` = 98;

INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 43, 0, 'skill: swords (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 44, 0, 'skill: axes (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 54, 0, 'skill: maces (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 55, 0, 'skill: 2h-swords (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 160, 0, 'skill: 2h-maces (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 172, 0, 'skill: 2h-axes (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 173, 0, 'skill: daggers (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 413, 0, 'armor: mail (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 414, 0, 'armor: leather (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1, 433, 0, 'skill: shield (warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 43, 0, 'skill: swords (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 54, 0, 'skill: maces (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 55, 0, 'skill: 2h-swords (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 160, 0, 'skill: 2h-maces (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 413, 0, 'armor: mail (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 414, 0, 'armor: leather (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 2, 433, 0, 'skill: shield (paladin)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 4, 43, 0, 'skill: swords (hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 4, 44, 0, 'skill: axes (hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 4, 172, 0, 'skill: 2h-axes (hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 4, 173, 0, 'skill: daggers (hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 4, 414, 0, 'armor: leather (hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 8, 118, 0, 'skill: dual wield (rogue)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 8, 173, 0, 'skill: daggers (rogue)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 8, 414, 0, 'armor: leather (rogue)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 16, 54, 0, 'skill: maces (priest)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 16, 136, 0, 'skill: staves (priest)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 16, 228, 0, 'skill: wands (priest)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 64, 54, 0, 'skill: maces (shaman)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 64, 136, 0, 'skill: staves (shaman)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 64, 414, 0, 'armor: leather (shaman)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 64, 433, 0, 'skill: shield (shaman)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 128, 136, 0, 'skill: staves (mage)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 128, 228, 0, 'skill: wands (mage)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 256, 136, 0, 'skill: staves (warlock)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 256, 173, 0, 'skill: daggers (warlock)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 256, 228, 0, 'skill: wands (warlock)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1024, 54, 0, 'skill: maces (druid)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1024, 136, 0, 'skill: staves (druid)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1024, 173, 0, 'skill: daggers (druid)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (0, 1024, 414, 0, 'armor: leather (druid)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (1, 4, 45, 0, 'skill: bows (human hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (1, 4, 226, 0, 'skill: crossbows (human hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (2, 4, 45, 0, 'skill: bows (orc hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (4, 4, 46, 0, 'skill: guns (dwarf hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (8, 4, 45, 0, 'skill: bows (night elf hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (32, 4, 46, 0, 'skill: guns (tauren hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (128, 1, 176, 0, 'skill: thrown (troll warrior)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (128, 4, 45, 0, 'skill: bows (troll hunter)');
INSERT INTO `world`.`playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES (512, 4, 45, 0, 'skill: bows (blood elf hunter)');


