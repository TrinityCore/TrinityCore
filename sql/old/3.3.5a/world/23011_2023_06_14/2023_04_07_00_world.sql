-- deletes for rerunability ensure any custom entries are not being replaced first
DELETE FROM `warden_checks` WHERE `id` IN (793, 794, 795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811);

-- insert new warden checks
INSERT INTO `warden_checks` (`id`, `type`, `str`, `address`, `length`, `comment`, `data`, `result`) VALUES 
(793, 139, 'local f=DEFAULT_CHAT_FRAME for i=1,f:GetNumMessages() do if (f:GetMessageInfo(i)):find("New addon name is ") then return true end end', NULL, NULL, 'Custom Detects KickKitty', NULL, NULL),
(794, 139, 'local f=DEFAULT_CHAT_FRAME for i=1,f:GetNumMessages() do if (f:GetMessageInfo(i)):find(". It\'s in new directory not this one") then return true end end', NULL, NULL, 'Custom Detects KickKitty', NULL, NULL),
(795, 217, 'BlackMagic.dll', 0, 0, 'Custom BlackMagic - injected dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(796, 217, 'x0.dll', 0, 0, 'Custom x0 gold hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(797, 217, 'Luim.dll', 0, 0, 'Custom Lua Unlocker dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(798, 217, 'Gold Hack.dll', 0, 0, 'Custom Gold Hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(799, 217, 'fasmdll_managed.dll', 0, 0, 'Custom Rotation Bot', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(800, 217, 'PortBlock.dll', 0, 0, 'Custom Multiclient Lagger', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(801, 217, 'PinvokeCollection.dll', 0, 0, 'Custom Keysender', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(802, 217, 'FuncCollection.dll', 0, 0, 'Custom Multi Hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(803, 139, 'local f=DEFAULT_CHAT_FRAME for i=1,f:GetNumMessages() do if (f:GetMessageInfo(i)):find("Rotation :        %3s") then return true end end', NULL, NULL, 'Custom Cloud Magic Rotation Bot', NULL, NULL),
(804, 217, 'nampower.dll', 0, 0, 'Custom Multi Hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(805, 217, 'EWTDll.dll', 0, 0, 'Custom Multi Hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(806, 217, 'iKillFish.dll', 0, 0, 'Custom Fish Bot', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(807, 217, 'iwanna.dll', 0, 0, 'Custom Fish Bot', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(808, 217, 'oGasai.dll', 0, 0, 'Custom Multi Hack dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(809, 217, 'tMorph.dll', 0, 0, 'Custom tMorph - injected dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(810, 217, 'jMorph.dll', 0, 0, 'Custom jMorph - injected dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', ''),
(811, 217, 'dmorph.dll', 0, 0, 'Custom dmorph - injected dll', '\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', '');
