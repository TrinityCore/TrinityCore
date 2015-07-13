DELETE FROM `battle_pet_species` WHERE `ID` IN (1449, 1636);
INSERT INTO `battle_pet_species` (`ID`, `CreatureID`, `IconFileID`, `SummonSpellID`, `PetType`, `Source`, `Flags`, `SourceText`, `Description`, `VerifiedBuild`) VALUES
(1449, 84521, 1044497, 169220, 7, 2, 18, '|cFFFFD200Vendor:|r Guild Vendor|n|cFFFFD200Zone:|r Stormwind, Orgrimmar|n|cFFFFD200Cost: |r300|TINTERFACE\\MONEYFRAME\\UI-GOLDICON.BLP:0|t', 'This hatchling has an unusual sense that allows it to detect and follow along with alpha predators.', 19831), -- 1449
(1636, 90345, 134509, 179954, 9, 5, 82, '|cFFFFD200Achievement: |rBig Rocketeer: Gold|n|cFFFFD200Category: |rDarkmoon Faire', 'One of the Darkmoon Race''s most obnoxious obstacles, now in the palm of your hand!', 19831); -- 1636
