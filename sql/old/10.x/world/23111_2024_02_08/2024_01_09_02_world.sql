DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN(154327, 166996, 120590, 93011, 98228, 98227, 98290, 98292, 99918, 94580, 98229, 98354, 99916, 94410, 99917, 94377, 93117, 94400, 93230);
INSERT INTO `creature_summoned_data` (`CreatureID`, `DespawnOnQuestsRemoved`) VALUES
-- Taming the Wilds
(154327, '59342'), -- Austin Huxworth
(166996, '59937'), -- Dawntracker
-- Tides of War / Nation of Kul'Tiras
(120590, '46727,46728'), -- Jaina
-- Invasion Begins
(93011, '40077'), -- Kayn Sunfury
(98228, '40077'), -- Jayce Darkweaver
(98227, '40077'), -- Allari the Souleater
(98290, '40077'), -- Cyana Nightglaive
(98292, '40077'), -- Korvas Bloodthorn
(99918, '40077'), -- Sevis Brightflame
(94580, '40077'), -- Wrath Warrior
-- Enter the Illidari: Ashtongue
(98229, '40378'), -- Kayn Sunfury
(98354, '40378'), -- Korvas Bloodthorn
(99916, '40378'), -- Sevis Brightflame
(94410, '40378'), -- Allari Souleater
-- Enter the Illidari: Coilskar
(99917, '40379'), -- Sevis Brightflame
-- Set them free
(94377, '38759'), -- Cyana Nightglaive
(93117, '38759'), -- Iyal Whitemoon
(94400, '38759'), -- Belath Dawnblade
(93230, '38759'); -- Mannethrel Darkstar
