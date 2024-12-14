DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN(166787, 166792, 166797, 166782, 166784, 166800, 151088, 151089, 154170, 156626, 149917, 156622, 198896, 198883);
INSERT INTO `creature_summoned_data` (`CreatureID`, `DespawnOnQuestsRemoved`) VALUES
-- Exiles Reach Emergency First Aid,Finding the Lost Expedition
(166787, '59930,59931'), -- Bo Standing
(166792, '59930,59931'), -- Mithdran Standing
(166797, '59930,59931'), -- Lana Jordan Standing
(166782, '59930'), -- Warlord Breka Grimaxe Beach
(166784, '59930'), -- Throg Beach
(166800, '59930'), -- Jinhake Beach
(151088, '54951,54952'), -- Kee La Standing
(151089, '54951,54952'), -- Bjorn Stouthands Standing
(154170, '54951,54952'), -- Austin Huxworth Standing
(156626, '54951'), -- Captain Garrick Standing
(149917, '54951'), -- Cole Beach
(156622, '54951'), -- Richter Beach
-- An Unlikely Informant / The New Clessington Estate
(198896, '72405,72426'), -- Mathias Shaw
(198883, '72405,72426'); -- Vanessa VanCleef
