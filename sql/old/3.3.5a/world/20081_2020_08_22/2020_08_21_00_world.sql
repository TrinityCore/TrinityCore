-- 
DELETE FROM `warden_checks` WHERE `id` IN (788,789,790);
INSERT INTO `warden_checks` (`id`,`type`,`str`,`address`,`length`,`result`, `comment`) VALUES
(788, 139, 'forceinsecure() return issecure()', NULL, NULL, NULL, 'Detects naive Lua unlockers'),
(789, 139, 'return not not PQR_IsMoving', NULL, NULL, NULL, 'Detects PQR'),
(790, 139, 'local f=DEFAULT_CHAT_FRAME for i=1,f:GetNumMessages() do if (f:GetMessageInfo(i)):find("|cffffd200PQR|r") then return true end end', NULL, NULL, NULL, 'Detects PQR');
