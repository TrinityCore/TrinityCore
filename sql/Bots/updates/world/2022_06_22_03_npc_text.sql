--
SET @LOCALIZED_STRINGS_START = 70010;
SET @LOCALIZED_STRINGS_END   = 70011;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70010','<You see an emaciated naga matron. She looks tired and weak, and avoids looking at you.>$B$BS-s-s-spare the words, mortal...','-1'),
('70011','Did I mess-s-s-s up my hair again? <She brushes her \"hair\">$B...No, I didn\'t. Then what is it?','-1');

SET @LOCALIZED_STRINGS_START = 70108;
SET @LOCALIZED_STRINGS_END   = 70108;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70108','|cff0000ddSea Witch|r$b|cffdd6600-=Warcraft III tribute=-|r$B$B"A vicious scaly denizen of ocean often associated with the coming of prodigious storms".$B$BSpell damage taken reduced by 30%, partially immune to control effects, cloth armor, deals physical/spellfrost/spellstorm damage, attack power bonus: agility x2, spell power bonus: 200% intellect. Main attribute: Intellect.$B$BForked Lightning. Calls forth a cone of lightning to damage enemies. Hits from 2 to all targets (depending on Sea Witch\'s level), stunning them for 2 seconds. This damage generates no threat.$B$BFrost Arrows. Imbues arrow with spellfrost for extra damage, slowing target\'s movement, attack and casting speed by 30% to 70% (depending on Sea Witch\'s level).$B$BMana Shield. Creates a shield that absorbs 100% incoming (non-mitigated) damage by using Sea Witch\'s mana. Absorbs 2 to 10 damage per point of mana (depending on Sea Witch\'s level).$B$BTornado. Summons a fierce tornado that damages and slows nearby enemy units, sometimes incapacitating them completely. Tornado grows over time oudoors, increasing damage dealt and area of effect, but shrinks indoors, dissipating quickly. Unlocked at level 60.$B$BNaga (Passive). Swim speed increased by 200%, damage and dodge chance are greatly increased while in water.','-1');

SET @LOCALIZED_STRINGS_START = 70651;
SET @LOCALIZED_STRINGS_END   = 70655;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70651','NIY','-1'),
('70652','Are you sure this is gonna work? It\'s better be the best water in the world...','-1'),
('70653','Seems like you could really use a drink of fresh water.','-1'),
('70654','Sea Witches','-1'),
('70655','Sea Witch','-1');
