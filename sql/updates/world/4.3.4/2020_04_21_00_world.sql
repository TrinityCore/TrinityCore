SET @TEAM_ALLIANCE := 469;
SET @TEAM_HORDE := 67;
SET @GUILD_FACTION := 1168;
SET @REP_FRIENDLY := 0 | 16 | 32 | 64 | 128;
SET @REP_HONORED := 0 | 32 | 64 | 128;
SET @REP_REVERED := 0 | 64 | 128;
SET @REP_EXALTED := 128;

SET @VENDOR := 46572;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

SET @VENDOR := 46602;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

SET @VENDOR := 51495;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)


SET @VENDOR := 51496;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)


SET @VENDOR := 51501;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)


SET @VENDOR := 51502;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)


SET @VENDOR := 51503;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

SET @VENDOR := 51504;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

SET @VENDOR := 51512;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

SET @VENDOR := 52268;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(23, @VENDOR, 69209, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Illustrious Guild Tabard
(23, @VENDOR, 69210, 5, @GUILD_FACTION, @REP_HONORED), -- Renowned Guild Tabard
-- Faction related items
-- Alliance
(23, @VENDOR, 63352, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63352, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63352, 6, @TEAM_ALLIANCE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63206, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63206, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63206, 6, @TEAM_ALLIANCE, 0), -- Wrap of Unity
(23, @VENDOR, 65360, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65360, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65360, 6, @TEAM_ALLIANCE, 0), -- Cloak of Coordination
(23, @VENDOR, 65361, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65361, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65361, 6, @TEAM_ALLIANCE, 0), -- Guild Page
(23, @VENDOR, 65364, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0), -- Guild Herald
(23, @VENDOR, 63359, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 63359, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 63359, 6, @TEAM_ALLIANCE, 0), -- Banner of Cooperation
(23, @VENDOR, 64398, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64398, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64398, 6, @TEAM_ALLIANCE, 0), -- Standard of Unity
(23, @VENDOR, 64399, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64399, 6, @TEAM_ALLIANCE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 62298, 17, 4912, 0), -- Reins of the Golden King
(23, @VENDOR, 62298, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Golden King
(23, @VENDOR, 62298, 6, @TEAM_ALLIANCE, 0), -- Reins of the Golden King
-- Horde
(23, @VENDOR, 63353, 17, 4989, 0), -- Shroud of Cooperation
(23, @VENDOR, 63353, 5, @GUILD_FACTION, @REP_HONORED), -- Shroud of Cooperation
(23, @VENDOR, 63353, 6, @TEAM_HORDE, 0), -- Shroud of Cooperation
(23, @VENDOR, 63207, 17, 4945, 0), -- Wrap of Unity
(23, @VENDOR, 63207, 5, @GUILD_FACTION, @REP_HONORED), -- Wrap of Unity
(23, @VENDOR, 63207, 6, @TEAM_HORDE, 0), -- Wrap of Unity
(23, @VENDOR, 65274, 17, 5035, 0), -- Cloak of Coordination
(23, @VENDOR, 65274, 5, @GUILD_FACTION, @REP_REVERED), -- Cloak of Coordination
(23, @VENDOR, 65274, 6, @TEAM_HORDE, 0), -- Cloak of Coordination
(23, @VENDOR, 65362, 17, 5031, 0), -- Guild Page
(23, @VENDOR, 65362, 5, @GUILD_FACTION, @REP_HONORED), -- Guild Page
(23, @VENDOR, 65362, 6, @TEAM_HORDE, 0), -- Guild Page
(23, @VENDOR, 65363, 17, 5201, 0), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0), -- Guild Herald
(23, @VENDOR, 64400, 17, 4860, 0), -- Banner of Cooperation
(23, @VENDOR, 64400, 5, @GUILD_FACTION, @REP_HONORED), -- Banner of Cooperation
(23, @VENDOR, 64400, 6, @TEAM_HORDE, 0), -- Banner of Cooperation
(23, @VENDOR, 64401, 17, 5143, 0), -- Standard of Unity
(23, @VENDOR, 64401, 5, @GUILD_FACTION, @REP_HONORED), -- Standard of Unity
(23, @VENDOR, 64401, 6, @TEAM_HORDE, 0), -- Standard of Unity
(23, @VENDOR, 64402, 17, 5422, 0), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 5, @GUILD_FACTION, @REP_HONORED), -- Battle Standard of Coordination
(23, @VENDOR, 64402, 6, @TEAM_HORDE, 0), -- Battle Standard of Coordination
(23, @VENDOR, 67107, 17, 4912, 0), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Kor'kron Annihilator
(23, @VENDOR, 67107, 6, @TEAM_HORDE, 0), -- Reins of the Kor'kron Annihilator
--
(23, @VENDOR, 63138, 17, 5812, 0), -- Dark Phoenix Hatchling
(23, @VENDOR, 63138, 5, @GUILD_FACTION, @REP_EXALTED), -- Dark Phoenix Hatchling
(23, @VENDOR, 63398, 17, 5144, 0), -- Armadillo Pup
(23, @VENDOR, 63398, 5, @GUILD_FACTION, @REP_REVERED), -- Armadillo Pup
(23, @VENDOR, 62800, 17, 5036, 0), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62800, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Seafood Magnifique Feast
(23, @VENDOR, 62799, 17, 5467, 0), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 62799, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Broiled Dragon Feast
(23, @VENDOR, 65435, 17, 5465, 0), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65435, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Cauldron of Battle
(23, @VENDOR, 65498, 17, 5024, 0), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 65498, 5, @GUILD_FACTION, @REP_HONORED), -- Recipe: Big Cauldron of Battle
(23, @VENDOR, 62286, 17, 4943, 0), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62286, 5, @GUILD_FACTION, @REP_FRIENDLY), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 5158, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 62287, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 5152, 0), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 5, @GUILD_FACTION, @REP_REVERED), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 69892, 17, 4944, 0), -- Ripped Sandstorm Cloak
(23, @VENDOR, 69892, 5, @GUILD_FACTION, @REP_HONORED), -- Ripped Sandstorm Cloak
(23, @VENDOR, 62038, 17, 4944, 0), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62038, 5, @GUILD_FACTION, @REP_HONORED), -- Worn Stoneskin Gargoyle Cape
(23, @VENDOR, 62039, 17, 4944, 0), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62039, 5, @GUILD_FACTION, @REP_HONORED), -- Inherited Cape of the Black Baron
(23, @VENDOR, 62040, 17, 4944, 0), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 62040, 5, @GUILD_FACTION, @REP_HONORED), -- Ancient Bloodmoon Cloak
(23, @VENDOR, 69887, 17, 4946, 0), -- Burnished Helm of Might
(23, @VENDOR, 69887, 5, @GUILD_FACTION, @REP_HONORED), -- Burnished Helm of Might
(23, @VENDOR, 61958, 17, 4946, 0), -- Tattered Dreadmist Mask
(23, @VENDOR, 61958, 5, @GUILD_FACTION, @REP_HONORED), -- Tattered Dreadmist Mask
(23, @VENDOR, 61942, 17, 4946, 0), -- Preened Tribal War Feathers
(23, @VENDOR, 61942, 5, @GUILD_FACTION, @REP_HONORED), -- Preened Tribal War Feathers
(23, @VENDOR, 61937, 17, 4946, 0), -- Stained Shadowcraft Cap
(23, @VENDOR, 61937, 5, @GUILD_FACTION, @REP_HONORED), -- Stained Shadowcraft Cap
(23, @VENDOR, 61936, 17, 4946, 0), -- Mystical Coif of Elements
(23, @VENDOR, 61936, 5, @GUILD_FACTION, @REP_HONORED), -- Mystical Coif of Elements
(23, @VENDOR, 61935, 17, 4946, 0), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61935, 5, @GUILD_FACTION, @REP_HONORED), -- Tarnished Raging Berserker's Helm
(23, @VENDOR, 61931, 17, 4946, 0), -- Polished Helm of Valor
(23, @VENDOR, 61931, 5, @GUILD_FACTION, @REP_HONORED), -- Polished Helm of Valor
(23, @VENDOR, 63125, 17, 4988, 0), -- Reins of the Dark Phoenix
(23, @VENDOR, 63125, 5, @GUILD_FACTION, @REP_EXALTED), -- Reins of the Dark Phoenix
(23, @VENDOR, 71033, 17, 5840, 0), -- Lil' Tarecgosa
(23, @VENDOR, 71033, 5, @GUILD_FACTION, @REP_EXALTED); -- Lil' Tarecgosa

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`) VALUES
(23, @VENDOR, 62286, 17, 5196, 1), -- Guild Vault Voucher (7th Slot)
(23, @VENDOR, 62287, 17, 4949, 1), -- Guild Vault Voucher (8th Slot)
(23, @VENDOR, 68136, 17, 4949, 1); -- Guild Vault Voucher (8th Slot)

-- Vendor Data
SET @VENDOR := 46572;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 46602;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51495;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51496;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51501;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51502;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51503;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51504;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 51512;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa

SET @VENDOR := 52268;
DELETE FROM `npc_vendor` WHERE `entry`= @VENDOR;
INSERT INTO `npc_vendor` (`entry`,  `slot`,  `item`,  `maxcount`,  `incrtime`,  `ExtendedCost`,  `type`,  `VerifiedBuild`) VALUES
(@VENDOR, 1, 69209, 0, 0, 0, 1, 0), -- Illustrious Guild Tabard
(@VENDOR, 2, 69210, 0, 0, 0, 1, 0), -- Renowned Guild Tabard
(@VENDOR, 3, 63353, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 4, 63352, 0, 0, 0, 1, 0), -- Shroud of Cooperation
(@VENDOR, 5, 63207, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 6, 63206, 0, 0, 0, 1, 0), -- Wrap of Unity
(@VENDOR, 7, 65274, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 8, 65360, 0, 0, 0, 1, 0), -- Cloak of Coordination
(@VENDOR, 9, 65362, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 10, 65363, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 11, 65361, 0, 0, 0, 1, 0), -- Guild Page
(@VENDOR, 12, 65364, 0, 0, 0, 1, 0), -- Guild Herald
(@VENDOR, 13, 63138, 0, 0, 0, 1, 0), -- Dark Phoenix Hatchling
(@VENDOR, 14, 63398, 0, 0, 0, 1, 0), -- Armadillo Pup
(@VENDOR, 15, 63359, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 16, 64398, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 17, 64399, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 18, 64400, 0, 0, 0, 1, 0), -- Banner of Cooperation
(@VENDOR, 19, 64401, 0, 0, 0, 1, 0), -- Standard of Unity
(@VENDOR, 20, 64402, 0, 0, 0, 1, 0), -- Battle Standard of Coordination
(@VENDOR, 21, 62800, 0, 0, 0, 1, 0), -- Recipe: Seafood Magnifique Feast
(@VENDOR, 22, 62799, 0, 0, 0, 1, 0), -- Recipe: Broiled Dragon Feast
(@VENDOR, 23, 65435, 0, 0, 0, 1, 0), -- Recipe: Cauldron of Battle
(@VENDOR, 25, 62286, 0, 0, 0, 1, 0), -- Guild Vault Voucher (7th Slot)
(@VENDOR, 26, 62287, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 27, 68136, 0, 0, 0, 1, 0), -- Guild Vault Voucher (8th Slot)
(@VENDOR, 28, 69892, 0, 0, 0, 1, 0), -- Ripped Sandstorm Cloak
(@VENDOR, 29, 62038, 0, 0, 0, 1, 0), -- Worn Stoneskin Gargoyle Cape
(@VENDOR, 30, 62039, 0, 0, 0, 1, 0), -- Inherited Cape of the Black Baron
(@VENDOR, 31, 62040, 0, 0, 0, 1, 0), -- Ancient Bloodmoon Cloak
(@VENDOR, 32, 69887, 0, 0, 0, 1, 0), -- Burnished Helm of Might
(@VENDOR, 33, 61958, 0, 0, 0, 1, 0), -- Tattered Dreadmist Mask
(@VENDOR, 34, 61942, 0, 0, 0, 1, 0), -- Preened Tribal War Feathers
(@VENDOR, 35, 61937, 0, 0, 0, 1, 0), -- Stained Shadowcraft Cap
(@VENDOR, 36, 61936, 0, 0, 0, 1, 0), -- Mystical Coif of Elements
(@VENDOR, 37, 61935, 0, 0, 0, 1, 0), -- Tarnished Raging Berserker's Helm
(@VENDOR, 38, 61931, 0, 0, 0, 1, 0), -- Polished Helm of Valor
(@VENDOR, 39, 67107, 0, 0, 0, 1, 0), -- Reins of the Kor'kron Annihilator
(@VENDOR, 40, 62298, 0, 0, 0, 1, 0), -- Reins of the Golden King
(@VENDOR, 41, 63125, 0, 0, 0, 1, 0), -- Reins of the Dark Phoenix
(@VENDOR, 42, 71033, 0, 0, 0, 1, 0); -- Lil' Tarecgosa
