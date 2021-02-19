--
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (63356, 63821, 63666, 62478, 62411);
INSERT INTO `spelldifficulty_dbc`(`id`, `spellid0`, `spellid1`) VALUES
(63356, 63356, 64003), -- Kologarn - Overhead Smash
(63821, 63821, 64001), -- Mimiron - Falling Rubble
(63666, 63666, 65026), -- Mimiron - Napalm Shell
(62478, 62478, 63512), -- Hodir - Frozen Blows
(62411, 62411, 62413); -- Ancient Rune Giant (Thorim) - Stomp
