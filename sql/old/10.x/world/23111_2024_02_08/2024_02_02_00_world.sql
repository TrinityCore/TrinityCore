DELETE FROM `creature_immunities` WHERE `ID` IN (1762,1771,1794,1799,1808,1835,1887,1893,1944,1964,1971);
INSERT INTO `creature_immunities` (`ID`, `SchoolMask`, `DispelTypeMask`, `MechanicsMask`, `Effects`, `Auras`, `ImmuneAoE`, `ImmuneChain`, `Comment`) VALUES
(1762, 0, 4, 0, '', '', 0, 0, 'Immune to Curses'),
(1771, 0, 0, 0, '', '', 1, 0, 'Immune to AoE'),
(1794, 0, 0, 67108864, '68', '', 0, 0, 'Immune to Interrupts'),
(1799, 0, 0, 67109376, '68', '27,60', 0, 0, 'Immune to Interrupts+Silence'),
(1808, 0, 0, 0, '98,124,144,145', '', 0, 0, 'Immune to knockback'),
(1835, 0, 0, 1075183616, '', '', 0, 0, 'Immune to polymorph+banish+shackle+sap'),
(1887, 0, 0, 0, '98,124,144,145', '', 0, 0, 'Immune to knockback'),
(1893, 0, 0, 1091728546, '', '', 0, 0, 'Immune to Charm+Fear+Freeze+Horror+Knockout+Polymorph+Root+Sap+Shackle+Sleep+Stun'),
(1944, 0, 0, 68719476736, '114', '11', 0, 0, 'Immune to Taunt'),
(1964, 0, 0, 67109376, '68', '27,60', 0, 0, 'Immune to Interrupts+Silence'),
(1971, 0, 0, 4096, '', '', 0, 0, 'Immune to Stun');
