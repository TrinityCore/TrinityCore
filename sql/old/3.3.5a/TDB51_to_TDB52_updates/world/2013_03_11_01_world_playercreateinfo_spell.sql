-- playercreateinfo_spell
TRUNCATE TABLE `playercreateinfo_spell`;

ALTER TABLE `playercreateinfo_spell`
  CHANGE `race` `racemask` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
  CHANGE `class` `classmask` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `playercreateinfo_spell_custom`
  CHANGE `race` `racemask` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
  CHANGE `class` `classmask` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

INSERT INTO `playercreateinfo_spell` (`racemask`, `classmask`, `Spell`, `Note`) VALUES
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Dranei
-- Classes: Warrior
(0x4FF, 0x1, 78, "Heroic Strike"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 81, "Dodge"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Shaman
(0x6FF, 0x43, 107, "Block"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Hunter, Death Knight
(0x6FF, 0x25, 196, "One-Handed Axes"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Priest, Shaman, Druid
(0x6FF, 0x453, 198, "One-Handed Maces"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Death Knight
(0x6FF, 0x27, 201, "One-Handed Swords"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 203, "Unarmed"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 204, "Defense"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 522, "SPELLDEFENSE (DND)"),
-- Races:   Human, Dwarf, Night elf, Gnome, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x44D, 0x5FF, 668, "Language Common"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 1843, "Disarm"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 2382, "Generic"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Dranei
-- Classes: Warrior
(0x4FF, 0x1, 2457, "Battle Stance"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 2479, "Honorless Target"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 3050, "Detect"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 3365, "Opening"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Dranei
-- Classes: Warrior
(0x4FF, 0x1, 5301, "Defensive State (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6233, "Closing"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6246, "Closing"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6247, "Opening"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6477, "Opening"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6478, "Opening"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 6603, "Attack"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 7266, "Duel"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 7267, "Grovel"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 7355, "Stuck"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 8386, "Attacking"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Death Knight
(0x6FF, 0x23, 8737, "Mail"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Death Knight, Shaman, Druid
(0x6FF, 0x46F, 9077, "Leather"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 9078, "Cloth"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Shaman
(0x6FF, 0x43, 9116, "Shield"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 9125, "Generic"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 20597, "Sword Specialization"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 20598, "The Human Spirit"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 20599, "Diplomacy"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 20864, "Mace Specialization"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 21651, "Opening"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 21652, "Closing"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 22027, "Remove Insignia"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 22810, "Opening - No Text"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Dranei
-- Classes: Warrior
(0x4FF, 0x1, 32215, "Victorious State"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 45927, "Summon Friend"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 58985, "Perception"),
-- Races:   Human
-- Classes: Warrior, Paladin, Rogue, Priest, Death Knight, Mage, Warlock
(0x1, 0x1BB, 59752, "Every Man for Himself"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5FF, 61437, "Opening"),
-- Races:   Human, Dwarf, Tauren, Dranei
-- Classes: Warrior, Paladin
(0x425, 0x3, 199, "Two-Handed Maces"),
-- Races:   Human, Dwarf, Blood elf, Dranei
-- Classes: Paladin
(0x605, 0x2, 635, "Holy Light"),
-- Races:   Human, Dwarf, Blood elf, Dranei
-- Classes: Paladin
(0x605, 0x2, 21084, "Seal of Righteousness"),
-- Races:   Human, Dwarf, Blood elf, Dranei
-- Classes: Paladin
(0x605, 0x2, 27762, "Libram"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Warrior, Hunter, Rogue, Warlock, Druid
(0x2DF, 0x50D, 1180, "Daggers"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Rogue
(0x2DF, 0x8, 1752, "Sinister Strike"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Rogue
(0x2DF, 0x8, 2098, "Eviscerate"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Warrior, Rogue
(0x2DF, 0x9, 2567, "Thrown"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Warrior, Rogue
(0x2DF, 0x9, 2764, "Throw"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Rogue
(0x2DF, 0x8, 16092, "Defensive State (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf
-- Classes: Rogue
(0x2DF, 0x8, 21184, "Rogue Passive (DND)"),
-- Races:   Human, Dwarf, Night elf, Undead, Troll, Blood elf, Dranei
-- Classes: Priest
(0x69D, 0x10, 585, "Smite"),
-- Races:   Human, Dwarf, Night elf, Undead, Troll, Blood elf, Dranei
-- Classes: Priest
(0x69D, 0x10, 2050, "Lesser Heal"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf, Dranei
-- Classes: Priest, Mage, Warlock
(0x6DF, 0x190, 5009, "Wands"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Gnome, Troll, Blood elf, Dranei
-- Classes: Priest, Mage, Warlock
(0x6DF, 0x190, 5019, "Shoot"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Hunter, Death Knight
(0x6FF, 0x25, 197, "Two-Handed Axes"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 200, "Polearms"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Warrior, Paladin, Death Knight
(0x6FF, 0x23, 202, "Two-Handed Swords"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Rogue, Death Knight
(0x6FF, 0x28, 674, "Dual Wield"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 750, "Plate Mail"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 3127, "Parry"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 3275, "Linen Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 3276, "Heavy Linen Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 3277, "Wool Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 3278, "Heavy Wool Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 7928, "Silk Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 7929, "Heavy Silk Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 7934, "Anti-Venom"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 10840, "Mageweave Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 10841, "Heavy Mageweave Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 10846, "First Aid"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 18629, "Runecloth Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 18630, "Heavy Runecloth Bandage"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 33391, "Journeyman Riding"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 45462, "Plague Strike"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 45477, "Icy Touch"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 45902, "Blood Strike"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 45903, "Offensive State (DND)"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 47541, "Death Coil"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 48266, "Blood Presence"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 49410, "Forceful Deflection"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 49576, "Death Grip"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 52665, "Sigil"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 59879, "Blood Plague"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 59921, "Frost Fever"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Death Knight
(0x6FF, 0x20, 61455, "Runic Focus"),
-- Races:   Human, Undead, Gnome, Troll, Blood elf, Dranei
-- Classes: Mage
(0x6D1, 0x80, 133, "Fireball"),
-- Races:   Human, Undead, Gnome, Troll, Blood elf, Dranei
-- Classes: Mage
(0x6D1, 0x80, 168, "Frost Armor"),
-- Races:   Human, Orc, Dwarf, Night elf, Undead, Tauren, Gnome, Troll, Blood elf, Dranei
-- Classes: Priest, Shaman, Mage, Warlock, Druid
(0x6FF, 0x5D0, 227, "Staves"),
-- Races:   Human, Orc, Undead, Gnome, Blood elf
-- Classes: Warlock
(0x253, 0x100, 686, "Shadow Bolt"),
-- Races:   Human, Orc, Undead, Gnome, Blood elf
-- Classes: Warlock
(0x253, 0x100, 687, "Demon Skin"),
-- Races:   Human, Orc, Undead, Gnome, Blood elf
-- Classes: Warlock
(0x253, 0x100, 58284, "Chaos Bolt Passive"),
-- Races:   Orc, Undead, Tauren, Troll, Blood elf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight, Shaman, Mage, Warlock, Druid
(0x2B2, 0x5FF, 669, "Language Orcish"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight
(0x2, 0x2D, 20572, "Blood Fury"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight, Shaman, Warlock
(0x2, 0x16D, 20573, "Hardiness"),
-- Races:   Orc
-- Classes: Warrior, Hunter, Rogue, Death Knight, Shaman, Warlock
(0x2, 0x16D, 20574, "Axe Specialization"),
-- Races:   Orc
-- Classes: Warrior, Rogue, Shaman
(0x2, 0x49, 21563, "Command"),
-- Races:   Orc, Dwarf, Night elf, Tauren, Troll, Blood elf, Dranei
-- Classes: Hunter
(0x6AE, 0x4, 75, "Auto Shot"),
-- Races:   Orc, Night elf, Troll, Blood elf
-- Classes: Hunter
(0x28A, 0x4, 264, "Bows"),
-- Races:   Orc, Dwarf, Night elf, Tauren, Troll, Blood elf, Dranei
-- Classes: Hunter
(0x6AE, 0x4, 2973, "Raptor Strike"),
-- Races:   Orc, Dwarf, Night elf, Tauren, Troll, Blood elf, Dranei
-- Classes: Hunter
(0x6AE, 0x4, 13358, "Defensive State (DND)"),
-- Races:   Orc
-- Classes: Hunter
(0x2, 0x4, 20576, "Command"),
-- Races:   Orc, Dwarf, Night elf, Tauren, Troll, Blood elf, Dranei
-- Classes: Hunter
(0x6AE, 0x4, 24949, "Defensive State 2 (DND)"),
-- Races:   Orc, Dwarf, Night elf, Tauren, Troll, Blood elf, Dranei
-- Classes: Hunter
(0x6AE, 0x4, 34082, "Advantaged State (DND)"),
-- Races:   Orc
-- Classes: Death Knight
(0x2, 0x20, 54562, "Command"),
-- Races:   Orc, Tauren, Troll, Dranei
-- Classes: Shaman
(0x4A2, 0x40, 331, "Healing Wave"),
-- Races:   Orc, Tauren, Troll, Dranei
-- Classes: Shaman
(0x4A2, 0x40, 403, "Lightning Bolt"),
-- Races:   Orc, Tauren, Troll, Dranei
-- Classes: Shaman
(0x4A2, 0x40, 27763, "Totem"),
-- Races:   Orc
-- Classes: Shaman
(0x2, 0x40, 33697, "Blood Fury"),
-- Races:   Orc
-- Classes: Warlock
(0x2, 0x100, 20575, "Command"),
-- Races:   Orc
-- Classes: Warlock
(0x2, 0x100, 33702, "Blood Fury"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 672, "Language Dwarven"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 2481, "Find Treasure"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 20594, "Stoneform"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 20595, "Gun Specialization"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 20596, "Frost Resistance"),
-- Races:   Dwarf
-- Classes: Warrior, Paladin, Hunter, Rogue, Priest, Death Knight
(0x4, 0x3F, 59224, "Mace Specialization"),
-- Races:   Dwarf, Tauren
-- Classes: Hunter
(0x24, 0x4, 266, "Guns"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Druid
(0x8, 0x43D, 671, "Language Darnassian"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Druid
(0x8, 0x43D, 20582, "Quickness"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Druid
(0x8, 0x43D, 20583, "Nature Resistance"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Druid
(0x8, 0x43D, 20585, "Wisp Spirit"),
-- Races:   Night elf
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Druid
(0x8, 0x43D, 58984, "Shadowmelt"),
-- Races:   Night elf, Tauren
-- Classes: Druid
(0x28, 0x400, 5176, "Wrath"),
-- Races:   Night elf, Tauren
-- Classes: Druid
(0x28, 0x400, 5185, "Healing Touch"),
-- Races:   Night elf, Tauren
-- Classes: Druid
(0x28, 0x400, 27764, "Fetish"),
-- Races:   Undead
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1B9, 5227, "Underwater Breathing"),
-- Races:   Undead
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1B9, 7744, "Will of the Forsaken"),
-- Races:   Undead
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1B9, 17737, "Language Gutterspeak"),
-- Races:   Undead
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1B9, 20577, "Cannibalize"),
-- Races:   Undead
-- Classes: Warrior, Rogue, Priest, Death Knight, Mage, Warlock
(0x10, 0x1B9, 20579, "Shadow Resistance"),
-- Races:   Tauren
-- Classes: Warrior, Hunter, Death Knight, Shaman, Druid
(0x20, 0x465, 670, "Language Taurahe"),
-- Races:   Tauren
-- Classes: Warrior, Hunter, Death Knight, Shaman, Druid
(0x20, 0x465, 20549, "War Stomp"),
-- Races:   Tauren
-- Classes: Warrior, Hunter, Death Knight, Shaman, Druid
(0x20, 0x465, 20550, "Endurance"),
-- Races:   Tauren
-- Classes: Warrior, Hunter, Death Knight, Shaman, Druid
(0x20, 0x465, 20551, "Nature Resistance"),
-- Races:   Tauren
-- Classes: Warrior, Hunter, Death Knight, Shaman, Druid
(0x20, 0x465, 20552, "Cultivation"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Death Knight, Mage, Warlock
(0x40, 0x1A9, 7340, "Language Gnomish"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Death Knight, Mage, Warlock
(0x40, 0x1A9, 20589, "Escape Artist"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Death Knight, Mage, Warlock
(0x40, 0x1A9, 20591, "Expansive Mind"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Death Knight, Mage, Warlock
(0x40, 0x1A9, 20592, "Arcane Resistance"),
-- Races:   Gnome
-- Classes: Warrior, Rogue, Death Knight, Mage, Warlock
(0x40, 0x1A9, 20593, "Engineering Specialization"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 7341, "Language Troll"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 20555, "Regeneration"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 20557, "Beast Slaying"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 20558, "Throwing Specialization"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 26290, "Bow Specialization"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 26297, "Berserking"),
-- Races:   Troll
-- Classes: Warrior, Hunter, Rogue, Priest, Death Knight, Shaman, Mage
(0x80, 0xFD, 58943, "Da Voodoo Shuffle"),
-- Races:   Blood elf
-- Classes: Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BE, 813, "Language Thalassian"),
-- Races:   Blood elf
-- Classes: Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BE, 822, "Magic Resistance"),
-- Races:   Blood elf
-- Classes: Paladin, Hunter, Priest, Mage, Warlock
(0x200, 0x196, 28730, "Arcane Torrent"),
-- Races:   Blood elf
-- Classes: Paladin, Hunter, Rogue, Priest, Death Knight, Mage, Warlock
(0x200, 0x1BE, 28877, "Arcane Affinity"),
-- Races:   Blood elf
-- Classes: Rogue
(0x200, 0x8, 25046, "Arcane Torrent"),
-- Races:   Blood elf
-- Classes: Death Knight
(0x200, 0x20, 50613, "Arcane Torrent"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Death Knight
(0x400, 0x27, 6562, "Heroic Presence"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Shaman, Mage
(0x400, 0xF7, 28875, "Gemcutting"),
-- Races:   Dranei
-- Classes: Warrior
(0x400, 0x1, 28880, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Warrior, Paladin, Hunter, Priest, Death Knight, Shaman, Mage
(0x400, 0xF7, 29932, "Language Draenei"),
-- Races:   Dranei
-- Classes: Mage
(0x400, 0x80, 59541, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Paladin
(0x400, 0x2, 59542, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Hunter
(0x400, 0x4, 5011, "Crossbows"),
-- Races:   Dranei
-- Classes: Shaman
(0x400, 0x40, 59540, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Hunter
(0x400, 0x4, 59543, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Priest, Shaman, Mage
(0x400, 0xD0, 28878, "Inspiring Presence"),
-- Races:   Dranei
-- Classes: Death Knight
(0x400, 0x20, 59539, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Priest
(0x400, 0x10, 59544, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Priest
(0x400, 0x10, 59538, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Hunter
(0x400, 0x4, 59536, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Death Knight
(0x400, 0x20, 59545, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Paladin
(0x400, 0x2, 59535, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Shaman
(0x400, 0x40, 59547, "Gift of the Naaru"),
-- Races:   Dranei
-- Classes: Warrior
(0x400, 0x1, 59221, "Shadow Resistance"),
-- Races:   Dranei
-- Classes: Mage
(0x400, 0x80, 59548, "Gift of the Naaru"),
-- Races:   Human, Dwarf, Blood elf, Dranei
-- Classes: Paladin
(0x605, 0x2, 60091, "Judgement Anti-Parry/Dodge Passive"),
-- Races:   All
-- Classes: Death Knight
(0x0, 0x20, 56816, "Rune Strike"),
-- Races:   All
-- Classes: Shaman
(0x0, 0x40, 75461, "Flame Shock Passive"),
-- Races:   All
-- Classes: Warlock
(0x0, 0x100, 75445, "Demonic Immolate");
