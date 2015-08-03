TRUNCATE TABLE `playercreateinfo_spell`;
TRUNCATE TABLE `playercreateinfo_spell_custom`;

ALTER TABLE `playercreateinfo_spell`
  CHANGE `race` `racemask` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
  CHANGE `class` `classmask` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `playercreateinfo_spell_custom`
  CHANGE `race` `racemask` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
  CHANGE `class` `classmask` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

INSERT INTO `playercreateinfo_spell` (`racemask`, `classmask`, `Spell`, `Note`) VALUES
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Death Knight
(0x0, 0x27, 202, "Two-Handed Swords"),
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Rogue, Death Knight, Shaman
(0x0, 0x6F, 196, "One-Handed Axes"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 2457, "Battle Stance"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 88161, "Strike"),
-- Races:   All
-- Classes: Warrior, Hunter, Rogue
(0x0, 0xD, 5011, "Crossbows"),
-- Races:   All
-- Classes: Warrior, Rogue
(0x0, 0x9, 3018, "Shoot"),
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Death Knight, Shaman
(0x0, 0x67, 197, "Two-Handed Axes"),
-- Races:   All
-- Classes: Warrior, Hunter, Rogue, Priest, Shaman, Mage, Warlock, Druid
(0x0, 0x5DD, 1180, "Daggers"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 45927, "Summon Friend"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6478, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6603, "Auto Attack"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 22027, "Remove Insignia"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 22810, "Opening - No Text"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 21651, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 21652, "Closing"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 2382, "Generic"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 3365, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 3050, "Detect"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 9125, "Generic"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 8386, "Attacking"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 7266, "Duel"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 7267, "Grovel"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 7355, "Stuck"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6233, "Closing"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6246, "Closing"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6247, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 6477, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 61437, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 68398, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 96220, "Opening"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 203, "Unarmed"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 20864, "Mace Specialization"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 20599, "Diplomacy"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 20597, "Sword Specialization"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 20598, "The Human Spirit"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 59752, "Every Man for Himself"),
-- Races:   Human
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BF, 79738, "Languages"),
-- Races:   All
-- Classes: Warrior, Paladin, Death Knight
(0x0, 0x23, 49410, "Forceful Deflection"),
-- Races:   All
-- Classes: Warrior, Paladin, Death Knight, Shaman, Druid
(0x0, 0x463, 199, "Two-Handed Maces"),
-- Races:   All
-- Classes: Warrior, Hunter, Rogue, Shaman, Druid
(0x0, 0x44D, 15590, "Fist Weapons"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 76268, "Armor Skills"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 76290, "Weapon Skills"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 88163, "Attack"),
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Death Knight, Druid
(0x0, 0x427, 200, "Polearms"),
-- Races:   Human, Dwarf, Night elf, Gnome, Dranei, Worgen
-- Classes: All
(0x20044D, 0x0, 668, "Language Common"),
-- Races:   All
-- Classes: Warrior, Hunter, Priest, Shaman, Mage, Warlock, Druid
(0x0, 0x5D5, 227, "Staves"),
-- Races:   All
-- Classes: Warrior, Paladin, Shaman
(0x0, 0x43, 9116, "Shield"),
-- Races:   All
-- Classes: Warrior, Paladin, Death Knight
(0x0, 0x23, 8737, "Mail"),
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Rogue, Death Knight, Shaman, Druid
(0x0, 0x46F, 9077, "Leather"),
-- Races:   All
-- Classes: Warrior, Hunter, Rogue
(0x0, 0xD, 264, "Bows"),
-- Races:   All
-- Classes: Warrior, Hunter, Rogue
(0x0, 0xD, 266, "Guns"),
-- Races:   All
-- Classes: Warrior, Paladin, Shaman
(0x0, 0x43, 107, "Block"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 81, "Dodge"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 32215, "Victorious State"),
-- Races:   All
-- Classes: Warrior
(0x0, 0x1, 5301, "Defensive State (DND)"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 204, "Defense"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 522, "SPELLDEFENSE (DND)"),
-- Races:   All
-- Classes: Warrior, Rogue
(0x0, 0x9, 2764, "Throw"),
-- Races:   All
-- Classes: Warrior, Rogue
(0x0, 0x9, 2567, "Thrown"),
-- Races:   All
-- Classes: All
(0x0, 0x0, 9078, "Cloth"),
-- Races:   All
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Shaman, Druid
(0x0, 0x47B, 198, "One-Handed Maces"),
-- Races:   All
-- Classes: Warrior, Paladin, Hunter, Rogue, Death Knight, Mage, Warlock
(0x0, 0x1AF, 201, "One-Handed Swords"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 27762, "Relic"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 76271, "Armor Skills"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 76294, "Weapon Skills"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 35395, "Crusader Strike"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 60091, "Judgement Anti-Parry/Dodge Passive"),
-- Races:   Human, Dwarf, Tauren, Blood elf, Dranei
-- Classes: Paladin
(0x625, 0x2, 20208, "Paladin pushback resistance"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 3044, "Arcane Shot"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 75, "Auto Shot"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 82928, "Aimed Shot!"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 34082, "Hunter Passive Auras (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 883, "Call Pet 1"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 982, "Revive Pet"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 13358, "Defensive State (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 24949, "Defensive State 2 (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 77442, "Focus"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 76249, "Weapon Skills"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 76250, "Armor Skills"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 87324, "Focused Aim"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Hunter
(0x2007BF, 0x4, 87816, "General Hunter Passives"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Rogue
(0x2003DF, 0x8, 1752, "Sinister Strike"),
-- Races:   All
-- Classes: Rogue, Death Knight
(0x0, 0x28, 674, "Dual Wield"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Rogue
(0x2003DF, 0x8, 76273, "Armor Skills"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Rogue
(0x2003DF, 0x8, 76297, "Weapon Skills"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Rogue
(0x2003DF, 0x8, 16092, "Defensive State (DND)"),
-- Races:   All
-- Classes: Priest, Mage, Warlock
(0x0, 0x190, 5009, "Wands"),
-- Races:   All
-- Classes: Priest, Mage, Warlock
(0x0, 0x190, 5019, "Shoot"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 585, "Smite"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 84733, "Holy Focus"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 88685, "Holy Word: Sanctuary"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 88684, "Holy Word: Serenity"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 101062, "Flash Heal"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 76301, "Weapon Skills"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 76279, "Armor Skills"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 84734, "Dark Thoughts"),
-- Races:   Human, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Priest
(0x2007FD, 0x10, 77486, "Shadow Orb Power"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 71761, "Deep Freeze Immunity State"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 79684, "Offensive State (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 133, "Fireball"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 92315, "Pyroblast!"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage, Warlock
(0x2007DF, 0x180, 85801, "DPS Caster Crit Damage Bonus"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 76298, "Weapon Skills"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Goblin, Blood elf, Dranei, Worgen
-- Classes: Mage
(0x2007DF, 0x80, 76276, "Armor Skills"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 688, "Summon Imp"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 86213, "Soul Swap Exhale"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 89420, "Drain Life"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 76299, "Weapon Skills"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 76277, "Armor Skills"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 87330, "Suppression"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 75445, "Demonic Immolate"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 686, "Shadow Bolt"),
-- Races:   Human, Orc, Dwarf, Undead, Gnome, Troll, Goblin, Blood elf, Worgen
-- Classes: Warlock
(0x2003D7, 0x100, 58284, "Chaos Bolt Passive"),
-- Races:   Orc, Undead, Tauren, Troll, Goblin, Blood elf
-- Classes: All
(0x3B2, 0x0, 669, "Language Orcish"),
-- Races:   Orc
-- Classes: Warrior, Rogue, Mage
(0x2, 0x89, 21563, "Command"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight
(0x2, 0x2D, 20572, "Blood Fury"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight, Shaman, Mage, Warlock
(0x2, 0x1ED, 20573, "Hardiness"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight, Shaman, Mage, Warlock
(0x2, 0x1ED, 20574, "Axe Specialization"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight, Shaman, Mage, Warlock
(0x2, 0x1ED, 79743, "Languages"),
-- Races:   Orc
-- Classes: Hunter
(0x2, 0x4, 20576, "Command"),
-- Races:   Orc, Dwarf, Troll, Goblin, Dranei
-- Classes: Shaman
(0x586, 0x40, 27763, "Relic"),
-- Races:   Orc
-- Classes: Shaman
(0x2, 0x40, 65222, "Command"),
-- Races:   Orc
-- Classes: Shaman
(0x2, 0x40, 33697, "Blood Fury"),
-- Races:   Orc, Dwarf, Troll, Goblin, Dranei
-- Classes: Shaman
(0x586, 0x40, 76272, "Armor Skills"),
-- Races:   Orc, Dwarf, Troll, Goblin, Dranei
-- Classes: Shaman
(0x586, 0x40, 76296, "Weapon Skills"),
-- Races:   Orc, Dwarf, Troll, Goblin, Dranei
-- Classes: Shaman
(0x586, 0x40, 89920, "Ancestral Focus"),
-- Races:   Orc, Dwarf, Tauren, Troll, Goblin, Dranei
-- Classes: Shaman
(0x5A6, 0x40, 403, "Lightning Bolt"),
-- Races:   Orc
-- Classes: Mage, Warlock
(0x2, 0x180, 33702, "Blood Fury"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 20596, "Frost Resistance"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 20595, "Gun Specialization"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 20594, "Stoneform"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 59224, "Mace Specialization"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 92682, "Explorer"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 79739, "Languages"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x4, 0x1FF, 672, "Language Dwarven"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 76252, "Languages"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 20583, "Nature Resistance"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 20582, "Quickness"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 20585, "Wisp Spirit"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 21009, "Elusiveness"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 58984, "Shadowmeld"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Druid
(0x8, 0x4BD, 671, "Language Darnassian"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 84736, "Nature's Focus"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 81170, "Ravage!"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 79577, "Eclipse Mastery Driver Passive"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 76300, "Weapon Skills"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 76275, "Armor Skills"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 5176, "Wrath"),
-- Races:   Night elf, Tauren, Troll, Worgen
-- Classes: Druid
(0x2000A8, 0x400, 84738, "Celestial Focus"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage
(0x10, 0xBD, 17737, "Language Gutterspeak"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1BD, 5227, "Underwater Breathing"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1BD, 7744, "Will of the Forsaken"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1BD, 20577, "Cannibalize"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1BD, 20579, "Shadow Resistance"),
-- Races:   Undead
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1BD, 79747, "Languages"),
-- Races:   Undead
-- Classes: Warlock
(0x10, 0x100, 17747, "Language Gutterspeak"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 670, "Language Taurahe"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 20549, "War Stomp"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 20550, "Endurance"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 20551, "Nature Resistance"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 20552, "Cultivation"),
-- Races:   Tauren
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Druid
(0x20, 0x437, 79746, "Languages"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 20591, "Expansive Mind"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 20593, "Engineering Specialization"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 20592, "Arcane Resistance"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 92680, "Shortblade Specialization"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 79740, "Languages"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x40, 0x1B9, 7340, "Language Gnomish"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 7341, "Language Troll"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 26290, "Bow Specialization"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 26297, "Berserking"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 58943, "Da Voodoo Shuffle"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 20555, "Regeneration"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 20557, "Beast Slaying"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 20558, "Throwing Specialization"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x80, 0x5FD, 79744, "Languages"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69269, "Language Goblin"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69070, "Rocket Jump"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69041, "Rocket Barrage"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69044, "Best Deals Anywhere"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69045, "Better Living Through Chemistry"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 69042, "Time is Money"),
-- Races:   Goblin
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock
(0x100, 0x1FD, 79749, "Languages"),
-- Races:   Blood elf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BF, 813, "Language Thalassian"),
-- Races:   Blood elf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BF, 822, "Arcane Resistance"),
-- Races:   Blood elf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BF, 28877, "Arcane Affinity"),
-- Races:   Blood elf
-- Classes: Warrior
(0x200, 0x1, 69179, "Arcane Torrent"),
-- Races:   Blood elf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BF, 79748, "Languages"),
-- Races:   Blood elf
-- Classes: Paladin, Priest, Mage, Warlock
(0x200, 0x192, 28730, "Arcane Torrent"),
-- Races:   Blood elf
-- Classes: Hunter
(0x200, 0x4, 80483, "Arcane Torrent"),
-- Races:   Blood elf
-- Classes: Rogue
(0x200, 0x8, 25046, "Arcane Torrent"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Shaman, Mage
(0x400, 0xF7, 29932, "Language Draenei"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Shaman, Mage
(0x400, 0xF7, 79741, "Languages"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Death Knight
(0x400, 0x27, 6562, "Heroic Presence"),
-- Races:   Dranei
-- Classes: Warrior
(0x400, 0x1, 28880, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Shaman, Mage
(0x400, 0xF7, 28875, "Gemcutting"),
-- Races:   Dranei
-- Classes: Warrior
(0x400, 0x1, 59221, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Paladin
(0x400, 0x2, 59535, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Paladin
(0x400, 0x2, 59542, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Hunter
(0x400, 0x4, 59543, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Hunter
(0x400, 0x4, 59536, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Priest
(0x400, 0x10, 59538, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Priest, Shaman, Mage
(0x400, 0xD0, 28878, "Heroic Presence"),
-- Races:   Dranei
-- Classes: Priest
(0x400, 0x10, 59544, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Shaman
(0x400, 0x40, 59540, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Shaman
(0x400, 0x40, 59547, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Mage
(0x400, 0x80, 59541, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Mage
(0x400, 0x80, 59548, "Gift of the Naaru"),
-- Races:   Worgen
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Mage, Warlock, Druid
(0x200000, 0x5BD, 79742, "Languages"),
-- Races:   Worgen
-- Classes: Warrior, Hunter, Rogue, Priest, Mage, Warlock, Druid
(0x200000, 0x59D, 69001, ""),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 52665, "Relic"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 63645, "Activating Primary Spec"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 63644, "Activating Secondary Spec"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 45902, "Blood Strike"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 82246, "Parry"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 89832, "Death Strike Enabler"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 45477, "Icy Touch"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 48266, "Frost Presence"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 61455, "Runic Focus"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 59921, "Frost Fever"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 33391, "Journeyman Riding"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 89964, "Clear Glyph"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 76282, "Armor Skills"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 76292, "Weapon Skills"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 750, "Plate Mail"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 45462, "Plague Strike"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 47541, "Death Coil"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 49576, "Death Grip"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 59879, "Blood Plague"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 45903, "Offensive State (DND)"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 10846, "First Aid"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 3275, "Linen Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 18630, "Heavy Runecloth Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 3276, "Heavy Linen Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 3277, "Wool Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 3278, "Heavy Wool Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 7928, "Silk Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 7929, "Heavy Silk Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 10840, "Mageweave Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 10841, "Heavy Mageweave Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 18629, "Runecloth Bandage"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 7934, "Anti-Venom"),
-- Races:   Orc
-- Classes: Death Knight
(0x2, 0x20, 54562, "Command"),
-- Races:   Gnome
-- Classes: Death Knight
(0x40, 0x20, 20589, "Escape Artist"),
-- Races:   Goblin
-- Classes: Death Knight
(0x100, 0x20, 69046, "Pack Hobgoblin"),
-- Races:   Blood elf
-- Classes: Death Knight
(0x200, 0x20, 50613, "Arcane Torrent"),
-- Races:   Dranei
-- Classes: Death Knight
(0x400, 0x20, 59539, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Death Knight
(0x400, 0x20, 59545, "Gift of the Naaru"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 68978, "Flayer"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 68992, "Darkflight"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 68976, "Aberration"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 68996, "Two Forms"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 68975, "Viciousness"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 94293, "Enable Worgen Altered Form"),
-- Races:   Worgen
-- Classes: Death Knight
(0x200000, 0x20, 87840, "Running Wild");
