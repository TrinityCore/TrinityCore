DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(143567, 144181);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(143567, 281587, 1, 1), -- Ride Vehicle
(143567, 279750, 3, 1), -- Enter Mole Machine
(144181, 281587, 1, 1), -- Ride Vehicle
(144181, 281586, 3, 1); -- Enter Mole Machine

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (281586,279750));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(281586, 0, 2081, 1703.550048828125, 453.149993896484375, 201.7299957275390625, 40725), -- Spell: 281586 (Enter Mole Machine) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(279750, 0, 0, -8195.650390625, 776.0999755859375, 72.43000030517578125, 40725); -- Spell: 279750 (Enter Mole Machine) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `scene_template` WHERE `SceneId`=2132;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2132, 20, 2341, 0);

-- hack starts here
DELETE FROM `spell_area` WHERE `spell`=279753;
INSERT INTO `spell_area` (`spell`, `area`, `aura_spell`, `flags`) VALUES
(279753, 9171, 279750, 1);
