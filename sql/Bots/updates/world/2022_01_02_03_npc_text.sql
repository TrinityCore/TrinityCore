--
SET @LOCALIZED_STRINGS_START = 70107;
SET @LOCALIZED_STRINGS_END   = 70107;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70107','|cff9900ccNecromancer|r$b|cffdd6600-=Warcraft III / Diablo II tribute=-|r$B$BSpell damage taken reduced by 20%, partially immune to control effects, cloth armor, deals spellshadow damage, no physical attack, spell power bonus: 100% intellect. Main attribute: Intellect.$B$BRaise Dead. Raises 2 Skeletons from a corpse (maximum 6 Skeletons, 65 seconds duration, only works on humanoids, beasts and dragonkin).$B$BUnholy Frenzy. Increases target\'s melee attack speed by 75%, but constantly drains health. Lasts 45 seconds. Cannot be cancelled. Unlocked at level 30.$B$BCorpse Explosion. Causes a corpse to explode, dealing damage equal to 35% to 75% of dead unit\'s maximum health (depends on Necromancer\'s level) to all surrounding enemies. This damage generates no threat. Unlocked at level 40.$B$BCripple. Reduces target\'s movement speed, melee attack speed and total strength by 50% for 60 seconds. Unlocked at level 50.','-1');

SET @LOCALIZED_STRINGS_START = 70646;
SET @LOCALIZED_STRINGS_END   = 70647;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70646','Necromancers','-1'),
('70647','Necromancer','-1');
